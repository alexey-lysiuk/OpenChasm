
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
    String readLine();
    TextInputStream& readLine(String& value);

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
        const typename T::size_type collectionSize = collection.size();
        const typename T::size_type readCount = typename T::size_type(-1) == count
            ? collectionSize
            : count;

        SDL_assert(collectionSize >= readCount);

        if (readCount > 0)
        {
            if (boost::is_fundamental<typename T::value_type>::value)
            {
                rdbuf()->sgetn(reinterpret_cast<char*>(&collection[0]),
                    readCount * sizeof(typename T::value_type));
            }
            else
            {
                for (typename T::size_type i = 0; i < readCount; ++i)
                {
                    *this >> collection[i];
                }
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
    explicit BinaryFile(const Path& path, const openmode mode = std::ios::in);
    ~BinaryFile();

    void open(const Path& path, const openmode mode = std::ios::in);
    bool is_open() const;

    void close();

private:
    typedef boost::filesystem::filebuf Buffer;
    Buffer* buffer() const;
};


// ===========================================================================


// Resource base, stored within big file (csm.bin) or externally

class Resource
{
public:
    enum FlagsType
    {
        PATH_MUST_EXIST    = 1, // Exit with error if resource was not found
        PATH_MAY_NOT_EXIST = 2  // Ignore missing resource
    };

    ~Resource();

    const bool is_open() const;

    const std::streamsize  size() const { return m_size;   }

protected:
    Resource();

    StreamBuffer* open(const Path& path, const FlagsType flags);

private:
    StreamBuffer*   m_buffer;
    
    std::streamsize m_size;
};


// ===========================================================================


// Text resource
// Replaces TOpen() function

class TextResource : public TextInputStream, public Resource
{
public:
    explicit TextResource(const Path& path, const FlagsType flags = PATH_MUST_EXIST);
};


// ===========================================================================

    
// Binary resource
// Replaces FOpen() function and BFile type

class BinaryResource : public BinaryInputStream, public Resource
{
public:
    explicit BinaryResource(const Path& path, const FlagsType flags = PATH_MUST_EXIST);
};


// ===========================================================================


class BigFile;


class FileSystem : public Singleton<FileSystem>
{
public:
    FileSystem();
    ~FileSystem();

    // Path to executable directory which can be read-only
    const Path& basePath() const { return m_basePath; }
    Path basePath(const Path& subPath) const { return m_basePath / subPath; }

    // Path to user's directory with read/write access
    const Path& userPath() const { return m_userPath; }
    Path userPath(const Path& subPath) const { return m_userPath / subPath; }

    // Path to big file (csm.bin) or directory with big file's content
    const Path& resourcePath() const { return m_resourcePath; }

    // Path to add-on levels
    const Path& addonPath() const { return m_addonPath; }
    void setAddonPath(const Path& path) { m_addonPath = path; }

    const Path& lastFileName() const { return m_lastFileName; }
    void setLastFileName(const Path& filename) { m_lastFileName = filename; }

    StreamBuffer* openResource(const Path& path, const Resource::FlagsType flags);
    StreamBuffer* openExternalResource(const Path& path, const Resource::FlagsType flags);

    // Check result of mandatory input/output operation
    // Replaces ChI() functions
    void checkIO(const std::ios& stream) const;

    static bool isPathExist(const Path& path);

    static bool createDirectory(const Path& path);
    static bool createDirectories(const Path& path);

private:
    BigFile* m_bigFile;

    Path m_basePath;
    Path m_userPath;

    Path m_resourcePath;  // BaseFile
    Path m_addonPath;     // AddonPath, UserMaps

    Path m_lastFileName;  // LastFName
};

} // namespace OC


inline OC::FileSystem& ocFS()
{
    return OC::FileSystem::instance();
}

#endif // OPENCHASM_OC_FILESYSTEM_H_INCLUDED
