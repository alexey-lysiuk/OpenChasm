
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

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#ifdef _MSC_VER
#define stat _stat
#endif // _MSC_VER

// Converts Pascal string (first byte is length, up to 255 characters)
// to C zero-terminated one

inline void PascalToCString(char* const string)
{
	assert(NULL != string);

	const uint8_t length = string[0];

	memmove(string, string + 1, length);
	string[length] = '\0';
}

#endif // OPENCHASM_PRECOMP_H_INCLUDED
