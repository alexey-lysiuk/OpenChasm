
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

#include "oc/utils.h"

namespace oc
{

wstring ExpandString(const char* const utf8String)
{
    SDL_assert(NULL != utf8String);

#if WCHAR_MAX >= 0x10000
    void* wideString = SDL_iconv_utf8_ucs4(utf8String);
#else // WCHAR_MAX < 0x10000
    void* wideString = SDL_iconv_utf8_ucs2(utf8String);
#endif

    wstring result;

    if (NULL != wideString)
    {
        result = static_cast<const wchar_t*>(wideString);
    }

    return result;
}


path GetBasePath()
{
    static path result;

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

path GetUserPath()
{
    static path result;

    if (result.empty())
    {
        char* const pathUtf8 = SDL_GetPrefPath("", "OpenChasm");

        if (NULL != pathUtf8)
        {
            wstring pathWide = ExpandString(pathUtf8);
            algorithm::replace_all(pathWide, "//", "/");
            algorithm::replace_all(pathWide, "\\\\", "\\");

            result = pathWide;

            SDL_free(pathUtf8);
        }
    }
    
    return result;
}

} // namespace oc
