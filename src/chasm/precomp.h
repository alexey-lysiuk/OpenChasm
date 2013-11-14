
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

#ifndef OPENCHASM_PRECOMP_H_INCLUDED
#define OPENCHASM_PRECOMP_H_INCLUDED

#include <cstdlib>
#include <string>

#define BOOST_ALL_NO_LIB // disables auto-linking for Boost
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include <SDL.h>


// TODO: 48-bit Pascal Real type
typedef double OCReal;

typedef std::string OCString;

typedef boost::filesystem::ifstream OCFile;

#endif // OPENCHASM_PRECOMP_H_INCLUDED
