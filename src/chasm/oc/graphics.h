
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

#ifndef OPENCHASM_OC_GRAPHICS_H_INCLUDED
#define OPENCHASM_OC_GRAPHICS_H_INCLUDED

#include "oc/types.h"

namespace OC
{

class BinaryInputStream;


// ===========================================================================


struct Rect : SDL_Rect
{
    Rect(const int x = -1, const int y = -1, const int width = -1, const int height = -1)
    {
        this->x = x;
        this->y = y;
        this->w = width;
        this->h = height;
    }
};


// ===========================================================================


// Bitmap image, replaces TPic type
// Valid objects, load()'ed or create()'ed, must be released explicitly
// via release() call
// Otherwise they internal representation will occupy memory
// until shut down of BitmapManager even if no Bitmap object exsists

class Bitmap
{
public:
    Bitmap();

    const bool isValid() const { return NULL != m_internal; }

    const Uint16 width()  const; // XSize
    const Uint16 height() const; // YSize
    const Uint16 centeX() const; // CenterX

    const Uint8* pixels() const;                                      // p
    const Uint8 pixel(const Uint16 x, const Uint16 y) const;          // p
    void setPixel(const Uint16 x, const Uint16 y, const Uint8 value); // p

    void create(const int width, const int height);
    void release();

    // Loads image from .cel file by its name
    // Replaces LoadPicFromCel()
    void load(const Path& path);

    // Loads image from given binary stream as raw data
    // Replaces LoadPic()
    void load(BinaryInputStream& stream);

    // Draws itself to given destination bitmap at position (x, y)
    // Optional clip rectangle (in source coordinates)
    // allows to blit only part of the image
    void draw(Bitmap& dest, const int x, const int y, const Rect& clip = Rect()) const;

    SDL_Texture* createTexture(SDL_Renderer* const renderer) const;

    // Saves to BMP file at given UTF-8 path
    bool saveAsBMP(const char* const path);

private:
    SDL_Surface* m_internal;

    enum FormatType
    {
        FORMAT_CEL,
        FORMAT_PIC
    };
    
    void load(BinaryInputStream& stream, const FormatType format);
};


// ===========================================================================


class BitmapManager : public Singleton<BitmapManager>
{
public:
    BitmapManager();
    ~BitmapManager();

    SDL_Surface* createSurface(const int width, const int height);
    void releaseSurface(SDL_Surface* const surface);

    // Replaces Contrast variable
    const Sint16 contrast() const { return m_contrast; }
    void setContrast(const Sint16 contrast);

    // Replaces Color variable
    const Sint16 color() const { return m_color; }
    void setColor(const Sint16 color);

    // Replaces Bright variable
    const Sint16 brightness() const { return m_brightness; }
    void setBrightness(const Sint16 brightness);

    // Replaces DoSetPalette(), SetPalette() functions
    void setPaletteParameters(const Sint16 contrast, const Sint16 color, const Sint16 brightness);

private:
    typedef std::vector<SDL_Surface*> SurfaceList;
    SurfaceList m_surfaces;

    typedef boost::array<SDL_Color, 256> Palette;

    // Palette with limited color range [0..63] loaded from resource
    // Replaces Palette variable
    Palette m_original;

    // Palette with full color range [0..255] with parameters applied
    // Ready to be used with SDL surfaces
    // Replaces Pal variable (with extended color range)
    Palette m_current;

    Sint16 m_contrast;
    Sint16 m_color;
    Sint16 m_brightness;

    Uint8 applyContast(const Uint8 color, const Sint16 coeff) const;
    Uint8 applyColor(const Uint8 color, const Sint16 coeff) const;
    Uint8 applyBrightness(const Uint8 color, const Sint16 coeff) const;

    void applyPalette(SDL_Surface* const surface) const;
};


// ===========================================================================


class Renderer : public Singleton<Renderer>
{
    friend class SDLWrapper;

public:
    Renderer();
    ~Renderer();

    const Uint16 screenWidth() const;
    const Uint16 screenHeight() const;

    // Replaces part of SetVideoMode()
    void setVideoMode(const Uint16 width, const Uint16 height);

    // Draws bitmap into screen buffer
    void draw(const Bitmap& image, const int x, const int y,
        const Rect& clip = Rect());

    // Draws on screen, swap buffers
    // Replaces ShowVideoBuffer() functions
    void present();

private:
    SDL_Window*   m_window;
    SDL_Renderer* m_renderer;

    Bitmap        m_screen;

    void release();
};

} // namespace OC


// ===========================================================================


OC::BinaryInputStream& operator>>(OC::BinaryInputStream& stream, SDL_Color& value);

#endif // OPENCHASM_OC_GRAPHICS_H_INCLUDED
