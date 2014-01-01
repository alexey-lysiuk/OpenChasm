
/*
 **---------------------------------------------------------------------------
 ** OpenChasm - Free software reconstruction of Chasm: The Rift game
 ** Copyright (C) 2013 Alexey Lysiuk
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

#include "oc/filesystem.h"

namespace OC
{

TextInputStream::TextInputStream()
: std::istream(NULL)
{
}

OC::String TextInputStream::readLine()
{
    OC::String result;
    readLine(result);

    return result;
}

TextInputStream& TextInputStream::readLine(OC::String& value)
{
    std::getline(*this, value);

    const OC::String::size_type length = value.size();

    if (length > 0 && '\r' == value[length - 1])
    {
        value.resize(length - 1);
    }
    
    return *this;
}

TextInputStream& TextInputStream::skipLine()
{
    ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return *this;
}


// ===========================================================================


BinaryInputStream::BinaryInputStream()
: std::ios(NULL)
{

}

BinaryInputStream& BinaryInputStream::operator>>(bool& value)
{
    return operator>>(reinterpret_cast<Uint8&>(value));
}

BinaryInputStream& BinaryInputStream::operator>>(Sint8& value)
{
    return operator>>(reinterpret_cast<Uint8&>(value));
}

BinaryInputStream& BinaryInputStream::operator>>(Uint8& value)
{
    if (good())
    {
        char* const valuePtr = reinterpret_cast<char*>(&value);

        if (sizeof value != rdbuf()->sgetn(valuePtr, sizeof value))
        {
            setstate(failbit);
        }
    }

    return *this;
}

BinaryInputStream& BinaryInputStream::operator>>(Sint16& value)
{
    return operator>>(reinterpret_cast<Uint16&>(value));
}

BinaryInputStream& BinaryInputStream::operator>>(Uint16& value)
{
    if (good())
    {
        char* const valuePtr = reinterpret_cast<char*>(&value);

        if (sizeof value == rdbuf()->sgetn(valuePtr, sizeof value))
        {
            value = SDL_SwapLE16(value);
        }
        else
        {
            setstate(failbit);
        }
    }
    
    return *this;
}

BinaryInputStream& BinaryInputStream::operator>>(Sint32& value)
{
    return operator>>(reinterpret_cast<Uint32&>(value));
}

BinaryInputStream& BinaryInputStream::operator>>(Uint32& value)
{
    if (good())
    {
        char* const valuePtr = reinterpret_cast<char*>(&value);

        if (sizeof value == rdbuf()->sgetn(valuePtr, sizeof value))
        {
            value = SDL_SwapLE32(value);
        }
        else
        {
            setstate(failbit);
        }
    }
    
    return *this;
}

std::streamsize BinaryInputStream::read(char* const buffer, const std::streamsize count)
{
    SDL_assert(NULL != rdbuf());
    SDL_assert(NULL != buffer);

    const std::streamsize bytesRead = rdbuf()->sgetn(buffer, count);
    if (count != bytesRead)
    {
        setstate(failbit);
    }

    return bytesRead;
}

String BinaryInputStream::readString(const Uint8 byteCount)
{
    OC::String result;
    readString(result, byteCount);

    return result;
}

BinaryInputStream& BinaryInputStream::readString(String& string, const Uint8 byteCount)
{
    Uint8 length;
    *this >> length;

    if (good())
    {
        if (length > 0)
        {
            string.resize(length);

            const std::streamsize bytesToRead = std::min(length, byteCount);
            const std::streamsize bytesRead   = read(&string[0], bytesToRead);

            if (bytesRead != bytesToRead)
            {
                setstate(failbit);
            }
        }

        if (length < byteCount)
        {
            seekg(byteCount - length, cur);
        }
    }

    return *this;
}


BinaryInputStream::pos_type BinaryInputStream::seekg(const streampos pos)
{
    SDL_assert(NULL != rdbuf());

    return rdbuf()->pubseekpos(pos, in);
}

BinaryInputStream::pos_type BinaryInputStream::seekg(const streamoff off, const seekdir way)
{
    SDL_assert(NULL != rdbuf());

    return rdbuf()->pubseekoff(off, way, in);
}


// ===========================================================================


BinaryOutputStream::BinaryOutputStream()
: std::ios(NULL)
{

}

std::streamsize BinaryOutputStream::write(const char* const buffer, const std::streamsize count)
{
    SDL_assert(NULL != rdbuf());
    SDL_assert(NULL != buffer);

    const std::streamsize bytesWritten = rdbuf()->sputn(buffer, count);
    if (count != bytesWritten)
    {
        setstate(failbit);
    }

    return bytesWritten;
}


// ===========================================================================


BinaryFile::BinaryFile()
{
    rdbuf(new Buffer);
}

BinaryFile::BinaryFile(const OC::Path& path, const openmode mode)
{
    rdbuf(new Buffer);
    
    open(path, mode | std::ios::binary);
}

BinaryFile::~BinaryFile()
{
    delete rdbuf();
}

void BinaryFile::open(const OC::Path& path, const openmode mode)
{
    buffer()->open(path, mode | std::ios::binary);
}

bool BinaryFile::is_open() const
{
    return buffer()->is_open();
}

BinaryFile::Buffer* BinaryFile::buffer() const
{
    return static_cast<Buffer*>(rdbuf());
}


// ===========================================================================


namespace FileSystem
{

Path GetBasePath()
{
    static Path result;

    if (result.empty())
    {
        char* const pathUtf8 = SDL_GetBasePath();

        if (NULL != pathUtf8)
        {
            result = ExpandString(pathUtf8);

            SDL_free(pathUtf8);
        }
    }

    return result;
}

Path GetUserPath()
{
    static Path result;

    if (result.empty())
    {
        char* const pathUtf8 = SDL_GetPrefPath("", "OpenChasm");

        if (NULL != pathUtf8)
        {
            WideString pathWide = ExpandString(pathUtf8);

            boost::algorithm::replace_all(pathWide, "//", "/");
            boost::algorithm::replace_all(pathWide, "\\\\", "\\");

            result = pathWide;

            SDL_free(pathUtf8);
        }
    }

    return result;
}


bool IsPathExist(const Path& path)
{
    boost::system::error_code error;
    return boost::filesystem::exists(path, error);
}

bool CreateDirectory(const Path& path)
{
    boost::system::error_code error;
    return boost::filesystem::create_directory(path, error);
}

bool CreateDirectories(const Path& path)
{
    boost::system::error_code error;
    return boost::filesystem::create_directories(path, error);
}

} // namespace FileSystem

} // namespace OC
