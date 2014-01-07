
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

#ifndef OPENCHASM_OC_UTILS_H_INCLUDED
#define OPENCHASM_OC_UTILS_H_INCLUDED

#include "oc/types.h"

namespace OC
{

template <typename T>
T Abs(const T& value)
{
    return value < 0 ? -value : value;
}

template <typename IntType, typename FloatType>
IntType Round(const FloatType& value)
{
    const FloatType addition = FloatType(value > 0 ? 0.5 : -0.5);
    return IntType(value + addition);
}

template <typename T>
T Clamp(const T& minimum, const T& value, const T& maximum)
{
    return std::min(std::max(minimum, value), maximum);
}

WideString ExpandString(const char* const utf8String);


void DoHalt(const char* const message);
void DoHalt(const OC::String& message);
void DoHalt(const OC::Format& message);

void DoHaltSDLError(const char* const message);

} // namespace OC

#define OC_FOREACH BOOST_FOREACH

#endif // OPENCHASM_OC_UTILS_H_INCLUDED
