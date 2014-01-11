
/*
 **---------------------------------------------------------------------------
 ** OpenChasm - Free software reconstruction of Chasm: The Rift game
 ** Copyright (C) 2013, 2014 Alexey Lysiuk
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **---------------------------------------------------------------------------
 */

#include "oc/graphics.h"

#include "oc/filesystem.h"
#include "oc/utils.h"

namespace OC
{

Bitmap::Bitmap()
: m_internal(NULL)
{

}


const Uint16 Bitmap::width()  const
{
    SDL_assert(isValid());

    return Uint16(m_internal->w);
}

const Uint16 Bitmap::height() const
{
    SDL_assert(isValid());

    return Uint16(m_internal->h);
}

const Uint16 Bitmap::centeX() const
{
    SDL_assert(isValid());

    return Uint16(reinterpret_cast<size_t>(m_internal->userdata));
}


const Uint8* Bitmap::pixels() const
{
    SDL_assert(isValid());

    return static_cast<const Uint8*>(m_internal->pixels);
}

const Uint8 Bitmap::pixel(const Uint16 x, const Uint16 y) const
{
    SDL_assert(x >= 0);
    SDL_assert(y >= 0);
    SDL_assert(isValid());

    return pixels()[y * m_internal->pitch + x];
}

void Bitmap::setPixel(const Uint16 x, const Uint16 y, const Uint8 value)
{
    SDL_assert(x >= 0);
    SDL_assert(y >= 0);
    SDL_assert(isValid());

    Uint8* const pixels = static_cast<Uint8*>(m_internal->pixels);
    pixels[y * m_internal->pitch + x] = value;
}


void Bitmap::create(const int width, const int height)
{
    SDL_assert(width  > 0);
    SDL_assert(height > 0);

    release();

    m_internal = BitmapManager::instance().createSurface(width, height);
    SDL_assert(NULL != m_internal);
}

void Bitmap::release()
{
    if (NULL != m_internal)
    {
        BitmapManager::instance().releaseSurface(m_internal);

        m_internal = NULL;
    }
}


void Bitmap::load(const Path& path)
{
    BinaryResource celFile(path);
    load(celFile, FORMAT_CEL);
}

void Bitmap::load(BinaryInputStream& stream)
{
    load(stream, FORMAT_PIC);
}

void Bitmap::load(BinaryInputStream& stream, const FormatType format)
{
    SDL_assert(stream.good());

    release();

    if (FORMAT_CEL == format)
    {
        stream.seekg(2); // skip 0x9119 magic
    }

    Uint16 width, height, centerX;

    stream >> width;
    stream >> height;
    stream >> centerX;

    create(width, height);

    // No other data are stored at the moment
    // So treat userdata pointer as centerX value
    m_internal->userdata = reinterpret_cast<void*>(centerX);

    if (FORMAT_CEL == format)
    {
        stream.seekg(0x320); // skip header and pallete
    }

    char* const pixelData = static_cast<char*>(m_internal->pixels);

    if (m_internal->w == m_internal->pitch)
    {
        stream.read(pixelData, width * height);
    }
    else
    {
        for (Uint16 i = 0; i < height; ++i)
        {
            stream.read(pixelData + i * m_internal->pitch, width);
        }
    }
    
    FileSystem::instance().checkIO(stream);
}


void Bitmap::draw(Bitmap& dest, const int x, const int y, const Rect& clip) const
{
    SDL_assert(m_internal);
    SDL_assert(dest.m_internal);

    const int rectX = -1  == clip.x ? 0 : clip.x;
    const int rectY = -1  == clip.y ? 0 : clip.y;

    const int rectWidth  = -1 == clip.w ? m_internal->w : clip.w;
    const int rectHeight = -1 == clip.h ? m_internal->h : clip.h;

    const SDL_Rect srcRect  = { rectX, rectY, rectWidth, rectHeight };
          SDL_Rect destRect = {     x,     y, rectWidth, rectHeight };

    SDL_BlitSurface(m_internal, &srcRect, dest.m_internal, &destRect);
}


SDL_Texture* Bitmap::createTexture(SDL_Renderer* const renderer) const
{
    SDL_assert(NULL != renderer);
    SDL_assert(isValid());

    return SDL_CreateTextureFromSurface(renderer, m_internal);
}

bool Bitmap::saveAsBMP(const char* const path)
{
    SDL_assert(isValid());
    return 0 == SDL_SaveBMP(m_internal, path);
}


// ===========================================================================


BitmapManager::BitmapManager()
: m_contrast(12)
, m_brightness(7)
, m_color(9)
{
    BinaryResource paletteFile("common/chasm2.pal");
    paletteFile.readArray(m_original);

    setPaletteParameters(m_contrast, m_color, m_brightness);
}

BitmapManager::~BitmapManager()
{
    OC_FOREACH(SDL_Surface* surface, m_surfaces)
    {
        SDL_FreeSurface(surface);
    }
}


SDL_Surface* BitmapManager::createSurface(const int width, const int height)
{
    SDL_Surface* const result = SDL_CreateRGBSurface(0, width, height, 8, 0, 0, 0, 0);

    if (NULL == result)
    {
        DoHaltSDLError("Failed to create render surface.");
    }

    m_surfaces.push_back(result);

    applyPalette(result);

    return result;
}

void BitmapManager::releaseSurface(SDL_Surface* const surface)
{
    SDL_assert(NULL != surface);

    const SurfaceList::iterator it = std::find(m_surfaces.begin(), m_surfaces.end(), surface);
    SDL_assert(m_surfaces.end() != it);

    m_surfaces.erase(it);

    SDL_FreeSurface(surface);
}


void BitmapManager::setContrast(const Sint16 contrast)
{
    setPaletteParameters(contrast, m_color, m_brightness);
}

void BitmapManager::setColor(const Sint16 color)
{
    setPaletteParameters(m_contrast, color, m_brightness);
}

void BitmapManager::setBrightness(const Sint16 brightness)
{
    setPaletteParameters(m_contrast, m_color, brightness);
}

void BitmapManager::setPaletteParameters(const Sint16 contrast, const Sint16 color, const Sint16 brightness)
{
    m_contrast   = contrast;
    m_color      = color;
    m_brightness = brightness;

    // Apply parameters on palette
    m_current    = m_original;

    OC_FOREACH(SDL_Color& color, m_current)
    {
        const Uint8 coeff = std::max(std::max(color.r, color.g), color.b);
        color.r = applyContast(color.r, coeff);
        color.g = applyContast(color.g, coeff);
        color.b = applyContast(color.b, coeff);
    }

    OC_FOREACH(SDL_Color& color, m_current)
    {
        const Sint16 coeff = (Sint16(color.r) + Sint16(color.g) + Sint16(color.b)) / 3;
        color.r = applyColor(color.r, coeff);
        color.g = applyColor(color.g, coeff);
        color.b = applyColor(color.b, coeff);
    }

    OC_FOREACH(SDL_Color& color, m_current)
    {
        const Sint16 coeff = std::max(std::max(color.r, color.g), color.b);
        color.r = applyBrightness(color.r, coeff);
        color.g = applyBrightness(color.g, coeff);
        color.b = applyBrightness(color.b, coeff);
    }

    // Convert 64-color palette to 256-color
    OC_FOREACH(SDL_Color& color, m_current)
    {
        color.r = color.r * 4;
        color.g = color.g * 4;
        color.b = color.b * 4;
    }

    // Update palettes of registred surfaces
    OC_FOREACH(SDL_Surface* const surface, m_surfaces)
    {
        applyPalette(surface);
    }
}


Uint8 BitmapManager::applyContast(const Uint8 color, const Sint16 coeff) const
{
    Float br = coeff / 63.0f; // Real(0x0086, 0x0000, 0x7C00).convert<Float>();
    br -= br * br;
    br *= 16.0f;              // Real(0x0085, 0x0000, 0x0000).convert<Float>();

    return Uint8(color * (m_contrast - 7) * Round<Sint16>(br) / 128 + color);
}

Uint8 BitmapManager::applyColor(const Uint8 color, const Sint16 coeff) const
{
    const Float br = (m_color - 7) / 8.0f; // Real(0x0084, 0x0000, 0x0000).convert<Float>();
    const Sint16 l = Round<Sint16>((color - coeff) * br) + color;

    return Uint8(Clamp(Sint16(0), l, Sint16(63)));
}

Uint8 BitmapManager::applyBrightness(const Uint8 color, const Sint16 coeff) const
{
    const Float br = 1.0f              // Real(0x0081, 0x0000, 0x0000).convert<Float>()
        - (m_brightness - 7) / 196.0f; // Real(0x0088, 0x0000, 0x4400).convert<Float>()
    
    Sint16 l = 64 - Round<Sint16>((64 - color) * br);
    
    if (coeff < 3)
    {
        l = l * coeff / 3;
    }
    
    return Uint8(Clamp(Sint16(0), l, Sint16(63)));
}


void BitmapManager::applyPalette(SDL_Surface* const surface) const
{
    SDL_assert(NULL != surface);
    SDL_assert(NULL != surface->format);
    SDL_assert(NULL != surface->format->palette);
    
    SDL_SetPaletteColors(surface->format->palette, &m_current[0], 0, int(Palette::size()));
}


// ===========================================================================


Renderer::Renderer()
: m_window  (NULL)
, m_renderer(NULL)
{

}

Renderer::~Renderer()
{
    release();
}

const Uint16 Renderer::screenWidth() const
{
    return m_screen.width();
}

const Uint16 Renderer::screenHeight() const
{
    return m_screen.height();
}

void Renderer::setVideoMode(const Uint16 width, const Uint16 height)
{
    release();

    m_window = SDL_CreateWindow("OpenChasm", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if (NULL == m_window)
    {
        DoHaltSDLError("Failed to create window.");
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (NULL == m_renderer)
    {
        DoHaltSDLError("Failed to create renderer.");
    }

    m_screen.create(width, height);

    SDL_RenderClear(m_renderer);
}


void Renderer::draw(const Bitmap& image, const int x, const int y, const Rect& clip)
{
    image.draw(m_screen, x, y, clip);
}


void Renderer::present()
{
    SDL_Texture* const blitTexture = m_screen.createTexture(m_renderer);

    SDL_RenderCopy(m_renderer, blitTexture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

    SDL_DestroyTexture(blitTexture);
}

void Renderer::release()
{
    m_screen.release();

    if (NULL != m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
    }

    if (NULL != m_window)
    {
        SDL_DestroyWindow(m_window);
    }
}

} // namespace OC


// ===========================================================================


OC::BinaryInputStream& operator>>(OC::BinaryInputStream& stream, SDL_Color& value)
{
    stream >> value.r;
    stream >> value.g;
    stream >> value.b;

    value.a = 255;

    return stream;
}
