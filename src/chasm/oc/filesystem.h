
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

// Generic text input stream

class TextInputStream : public std::istream
{
public:
    // Reads until end of the line
    OC::String readLine();
    TextInputStream& readLine(OC::String& value);

    // Skips until end of the line
    TextInputStream& skipLine();

    // Reads sequence of flags usually represented as 0 and 1
    template <typename T>
    TextInputStream& readFlags(T& flags, const size_t flagMasks[], const size_t count)
    {
        flags = T(0);

        for (size_t i = 0; i < count; ++i)
        {
            Uint16 value;
            *this >> value;

            if (value > 0)
            {
                flags |= flagMasks[i];
            }
        }

        return *this;
    }

    template <typename T>
    T readFlags(const size_t flagMasks[], const size_t count)
    {
        T result;
        readFlags(result, flagMasks, count);

        return result;
    }

protected:
    TextInputStream();
};


// ===========================================================================


// Generic binary input stream, little endian

class BinaryInputStream : virtual public std::ios
{
public:
    BinaryInputStream& operator>>(bool& value);
    BinaryInputStream& operator>>(Sint8& value);
    BinaryInputStream& operator>>(Uint8& value);
    BinaryInputStream& operator>>(Sint16& value);
    BinaryInputStream& operator>>(Uint16& value);
    BinaryInputStream& operator>>(Sint32& value);
    BinaryInputStream& operator>>(Uint32& value);

    std::streamsize read(char* const buffer, const std::streamsize count);

    // Reads array up to specified number of elements or up to current collection size (in elements)
    // Collection must have appropriate size in both cases
    // Element must have overloaded BinaryInputStream& operator>>()
    template <typename T>
    BinaryInputStream& readArray(T& collection, const typename T::size_type count = typename T::size_type(-1))
    {
        char* const ptr = reinterpret_cast<char*>(&collection[0]);

        const typename T::size_type collectionSize = collection.size();
        const typename T::size_type readCount = typename T::size_type(-1) == count
            ? collectionSize
            : count;

        SDL_assert(collectionSize >= readCount);

        if (1 == sizeof collection[0])
        {
            // Single read call can be used in case of bytes array only
            rdbuf()->sgetn(ptr, readCount);
        }
        else
        {
            for (typename T::size_type i = 0; i < readCount; ++i)
            {
                *this >> collection[i];
            }
        }

        return *this;
    }

    // Reads Pascal string, length byte and up to 255 characters
    // Length byte is excluded from byteCount parameter
    String readString(const Uint8 byteCount);
    BinaryInputStream& readString(String& string, const Uint8 byteCount);

    pos_type seekg(const streampos pos);
    pos_type seekg(const streamoff off, const seekdir way);

protected:
    BinaryInputStream();
};


// ===========================================================================


// Generic binary output stream, little endian

class BinaryOutputStream : virtual public std::ios
{
public:
    std::streamsize write(const char* const buffer, const std::streamsize count);

    // TODO: overloaded operator<<()

protected:
    BinaryOutputStream();
};


// ===========================================================================


// External binary file, read and write

class BinaryFile: public BinaryInputStream, public BinaryOutputStream
{
public:
    BinaryFile();
    explicit BinaryFile(const OC::Path& path, const openmode mode = std::ios::in);
    ~BinaryFile();

    void open(const OC::Path& path, const openmode mode = std::ios::in);
    bool is_open() const;
    
private:
    typedef boost::filesystem::filebuf Buffer;
    Buffer* buffer() const;
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
bool CreateDirectories(const Path& path);

} // namespace FileSystem

} // namespace OC

#endif // OPENCHASM_OC_FILESYSTEM_H_INCLUDED
