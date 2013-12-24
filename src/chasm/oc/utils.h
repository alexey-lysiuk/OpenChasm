
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

#ifndef OPENCHASM_OC_UTILS_H_INCLUDED
#define OPENCHASM_OC_UTILS_H_INCLUDED

#include "oc/types.h"

namespace OC
{

WideString ExpandString(const char* const utf8String);

template <typename Element, typename Traits>
inline std::basic_string<Element, Traits> ReadLine(std::basic_istream<Element, Traits>& stream)
{
    std::basic_string<Element, Traits> result;

    std::getline(stream, result);

    return result;
}

} // namespace OC

#define OC_FOREACH BOOST_FOREACH

#endif // OPENCHASM_OC_UTILS_H_INCLUDED
