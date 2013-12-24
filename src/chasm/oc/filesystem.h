
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

#ifndef OPENCHASM_OC_FILESYSTEM_H_INCLUDED
#define OPENCHASM_OC_FILESYSTEM_H_INCLUDED

#include "oc/types.h"

namespace OC
{

// Generic binary stream, little endian

class BinaryStream: public std::iostream
{
private:
    typedef std::iostream Base;

public:
    explicit BinaryStream(std::streambuf* const buffer);

    template <typename T>
    T readBinary()
    {
        T result = T();
        readBinary(result);

        return result;
    }

#define OC_BINARY_FILE_READ_LITTLE(TYPE, SWAP_FUNC)             \
    BinaryStream& readBinary(TYPE& value)                       \
    {                                                           \
        char* const valuePtr = reinterpret_cast<char*>(&value); \
        read(valuePtr, sizeof value);                           \
        value = SWAP_FUNC(value);                               \
        return *this;                                           \
    }

#define OC_NO_SWAP_FUNC(X) (X)

    OC_BINARY_FILE_READ_LITTLE(Sint8, OC_NO_SWAP_FUNC)
    OC_BINARY_FILE_READ_LITTLE(Uint8, OC_NO_SWAP_FUNC)

    OC_BINARY_FILE_READ_LITTLE(Sint16, SDL_SwapLE16)
    OC_BINARY_FILE_READ_LITTLE(Uint16, SDL_SwapLE16)

    OC_BINARY_FILE_READ_LITTLE(Sint32, SDL_SwapLE32)
    OC_BINARY_FILE_READ_LITTLE(Uint32, SDL_SwapLE32)

#undef OC_NO_SWAP_FUNC
#undef OC_BINARY_FILE_READ_LITTLE

    // Reads Pascal string, length byte and up to 255 characters
    String readPascalString(const Uint8 byteCount);
    BinaryStream& readPascalString(String& string, const Uint8 byteCount);
};


// ===========================================================================


// External file, read and write

class File: public BinaryStream
{
private:
    typedef BinaryStream               Base;
    typedef boost::filesystem::filebuf FileBuffer;

public:
    explicit File(const OC::Path& filePath, const openmode mode = std::ios::in);
    ~File();

    bool is_open() const;

private:
    FileBuffer* fileBuffer() const;
};


// ===========================================================================


namespace FileSystem
{

Path GetBasePath();

template <typename T>
inline Path GetBasePath(const T& subPath)
{
    Path result = GetBasePath();

    result += subPath;

    return result;
}

Path GetUserPath();

template <typename T>
inline Path GetUserPath(const T& subPath)
{
    Path result = GetUserPath();

    result += subPath;

    return result;
}

bool IsPathExist(const Path& path);

bool CreateDirectory(const Path& path);

} // namespace FileSystem

} // namespace OC

#endif // OPENCHASM_OC_FILESYSTEM_H_INCLUDED
