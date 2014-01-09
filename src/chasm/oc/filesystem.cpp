
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

#include "oc/filesystem.h"

#include "oc/utils.h"

namespace OC
{

TextInputStream::TextInputStream()
: std::istream(NULL)
{
}

String TextInputStream::readLine()
{
    String result;
    readLine(result);

    return result;
}

TextInputStream& TextInputStream::readLine(String& value)
{
    std::getline(*this, value);

    const String::size_type length = value.size();

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
{
    init(NULL);
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
    String result;
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
{
    init(NULL);
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

BinaryFile::BinaryFile(const Path& path, const openmode mode)
{
    rdbuf(new Buffer);
    
    open(path, mode | std::ios::binary);
}

BinaryFile::~BinaryFile()
{
    delete rdbuf();
}

void BinaryFile::open(const Path& path, const openmode mode)
{
    buffer()->open(path, mode | std::ios::binary);
}

bool BinaryFile::is_open() const
{
    return buffer()->is_open();
}

void BinaryFile::close()
{
    buffer()->close();
}

BinaryFile::Buffer* BinaryFile::buffer() const
{
    return static_cast<Buffer*>(rdbuf());
}


// ===========================================================================


class BigFile : private BinaryFile
{
public:
    explicit BigFile(const Path& path);

    // Creates buffer and reads file into it
    StringBuffer* read(const Path& path);

    // Extracts all files into directory with given path
    // If no path provided output directory is named dump within user's directory
    void dumpContent(const Path& path = Path());

private:
    struct Entry
    {
        String      filename;
        std::streamsize size;
        std::streamoff  offset;
    };

    typedef std::vector<Entry> EntryTable;
    EntryTable m_entryTable;  // FileTable
};


BigFile::BigFile(const Path& path)
: BinaryFile(path)
{
    if (!is_open())
    {
        DoHalt(Format("Cannot open file %1%, permission denied or file system error.") % path);
    }

    Uint32 magic;
    *this >> magic;

    static const Sint32 CSM_ID = 0x64695343; // 'CSid'

    if (CSM_ID != magic)
    {
        DoHalt(Format("Bad header in file %1%.") % path);
    }

    Uint16 fileCount;
    *this >> fileCount;

    for (Uint16 i = 0; i < fileCount; ++i)
    {
        const String filename = readString(12);

        Sint32 size, offset;
        *this >> size >> offset;

        const Entry entry = { filename, size, offset };

        m_entryTable.push_back(entry);
    }
}


StringBuffer* BigFile::read(const Path& path)
{
    SDL_assert(!path.empty());

    String filename = path.filename().generic_string();
    boost::algorithm::to_upper(filename);

    OC_FOREACH(const Entry& entry, m_entryTable)
    {
        if (entry.filename == filename)
        {
            seekg(entry.offset, beg);

            // TODO: error handling

            StringBuffer* buffer = new StringBuffer();

            for (std::streamsize bytesLeft = entry.size; bytesLeft > 0; /* EMPTY */)
            {
                char bytes[4096];

                const std::streamsize bytesToRead = std::min(bytesLeft, std::streamsize(sizeof bytes));
                const std::streamsize bytesRead = BinaryInputStream::read(bytes, bytesToRead);

                buffer->sputn(bytes, bytesRead);

                bytesLeft -= bytesRead;
            }

            return buffer;
        }
    }

    return NULL;
}

void BigFile::dumpContent(const Path& path)
{
    SDL_assert(!m_entryTable.empty());
    SDL_assert(is_open());

    const Path dumpPath = path.empty()
        ? FileSystem::instance().userPath("dump")
        : path;

    FileSystem::createDirectories(dumpPath);

    OC_FOREACH(const Entry& entry, m_entryTable)
    {
        seekg(entry.offset);

        const Path outPath = dumpPath / entry.filename;
        BinaryFile outFile(outPath, std::ios::out);

        for (std::streamsize bytesLeft = entry.size; bytesLeft > 0; /* EMPTY */)
        {
            char buffer[4096];

            const std::streamsize bytesToRead = std::min(bytesLeft, std::streamsize(sizeof buffer));
            const std::streamsize bytesRead = BinaryInputStream::read(buffer, bytesToRead);

            outFile.write(buffer, bytesRead);

            bytesLeft -= bytesRead;
        }
    }
}


// ===========================================================================


Resource::Resource()
: m_buffer(NULL)
, m_size(0)
{
}

Resource::~Resource()
{
    delete m_buffer;
}

const bool Resource::is_open() const
{
    return NULL != m_buffer;
}

StreamBuffer* Resource::open(const Path& path, const FlagsType flags)
{
    SDL_assert(NULL == m_buffer);
    
    m_buffer = FileSystem::instance().openResource(path, flags);

    if (NULL != m_buffer)
    {
        m_size = m_buffer->pubseekoff(0, std::ios::end);
        m_buffer->pubseekoff(0, std::ios::beg);
    }

    return m_buffer;
}


// ===========================================================================


TextResource::TextResource(const Path& path, const FlagsType flags)
{
    rdbuf(open(path, flags));
}


// ===========================================================================


BinaryResource::BinaryResource(const Path& path, const FlagsType flags)
{
    rdbuf(open(path, flags));
}


// ===========================================================================


FileSystem::FileSystem()
: m_bigFile(NULL)
{
    if (char* const pathUtf8 = SDL_GetBasePath())
    {
        m_basePath = ExpandString(pathUtf8);
        SDL_free(pathUtf8);
    }

    if (char* const pathUtf8 = SDL_GetPrefPath("", "OpenChasm"))
    {
        WideString pathWide = ExpandString(pathUtf8);

        boost::algorithm::replace_all(pathWide, "//", "/");
        boost::algorithm::replace_all(pathWide, "\\\\", "\\");

        m_userPath = pathWide;

        SDL_free(pathUtf8);
    }

    static const String DATA_FILE_NAME      = "csm.bin";
    static const String DATA_DIRECTORY_NAME = "chasmdat/";

    bool isInternal = false;

    m_resourcePath = FileSystem::basePath(DATA_FILE_NAME);

    if (FileSystem::isPathExist(m_resourcePath))
    {
        isInternal = true;
    }
    else
    {
        m_resourcePath = FileSystem::userPath(DATA_FILE_NAME);

        if (FileSystem::isPathExist(m_resourcePath))
        {
            isInternal = true;
        }
        else
        {
            m_resourcePath = FileSystem::basePath(DATA_DIRECTORY_NAME);

            if (!FileSystem::isPathExist(m_resourcePath))
            {
                m_resourcePath = FileSystem::userPath(DATA_DIRECTORY_NAME);

                if (!FileSystem::isPathExist(m_resourcePath))
                {
                    // TODO: more detailed message
                    DoHalt("Cannot find game resource file or directory.");
                }
            }
        }
    }

    if (isInternal)
    {
        m_bigFile = new BigFile(m_resourcePath);
    }

    SDL_Log("Loading from: %s", m_resourcePath.string().c_str());
}

FileSystem::~FileSystem()
{
    delete m_bigFile;
}


StreamBuffer* FileSystem::openResource(const Path& path, const Resource::FlagsType flags)
{
    StreamBuffer* result;

    setLastFileName(path);

    if (!m_addonPath.empty())
    {
        result = openExternalResource(m_addonPath / path, flags);
    }
    else if (NULL == m_bigFile)
    {
        return openExternalResource(m_basePath / path, flags);
    }
    else
    {
        result = m_bigFile->read(path);

        if ((flags & Resource::PATH_MUST_EXIST) && NULL == result)
        {
            DoHalt(Format("Cannot find file %1% within %2%") % path % m_resourcePath);
        }
    }

    return result;
}

StreamBuffer* FileSystem::openExternalResource(const Path& path, const Resource::FlagsType flags)
{
    if (FileSystem::isPathExist(path))
    {
        boost::filesystem::filebuf* buffer = new boost::filesystem::filebuf();
        buffer->open(path, std::ios::in | std::ios::binary);

        if (buffer->is_open())
        {
            return buffer;
        }
        else if (flags & Resource::PATH_MUST_EXIST)
        {
            DoHalt(Format("Cannot open file %1%, permission denied or file system error.") % path);
        }
    }

    return NULL;
}


void FileSystem::checkIO(const std::ios& stream) const
{
    SDL_assert(stream.good());

    if (!stream.good())
    {
        DoHalt(Format("Error while accessing %1%.\n"
            "Permission denied or file system error.") % lastFileName());
    }
}


bool FileSystem::isPathExist(const Path& path)
{
    boost::system::error_code error;
    return boost::filesystem::exists(path, error);
}

bool FileSystem::createDirectory(const Path& path)
{
    boost::system::error_code error;
    return boost::filesystem::create_directory(path, error);
}

bool FileSystem::createDirectories(const Path& path)
{
    boost::system::error_code error;
    return boost::filesystem::create_directories(path, error);
}

} // namespace OC
