
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

BinaryStream::BinaryStream(std::streambuf* const buffer)
: Base(buffer)
{

}

String BinaryStream::readPascalString(const Uint8 byteCount)
{
    OC::String result;
    readPascalString(result, byteCount);

    return result;
}

BinaryStream& BinaryStream::readPascalString(String& string, const Uint8 byteCount)
{
    const Uint8 length = readBinary<Uint8>();
    string.resize(length);

    if (length > 0)
    {
        read(&string[0], length);
    }

    if (length < byteCount)
    {
        seekg(byteCount - length, cur);
    }

    return *this;
}


// ===========================================================================


File::File(const OC::Path& filePath, const openmode mode)
: Base(new FileBuffer)
{
    fileBuffer()->open(filePath, mode | std::ios::binary);
}

File::~File()
{
    delete rdbuf();
}

bool File::is_open() const
{
    return fileBuffer()->is_open();
}

File::FileBuffer* File::fileBuffer() const
{
    return static_cast<File::FileBuffer*>(rdbuf());
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

} // namespace FileSystem

} // namespace OC
