
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

#include "csprndr.h"

namespace CSPRNDR
{

void InitModule()
{
    // TODO...
}

void ProcessLights(/*...*/);
void AddLightSource(/*...*/);
void BackRender(/*...*/);
Uint16 QPifagorP16(/*...*/);
Uint16 QPifagorA32(/*...*/);
Sint16 MulVectors(/*...*/);
void RestoreLights(/*...*/);
void RenderLightOnMap(/*...*/);

Uint16 Wx1;
Uint16 Wy1;
Uint16 Wx2;
Uint16 Wy2;
Uint16 os;
Uint16 R;
Uint16 ccx;
Uint16 ccy;
Uint16 N;
Uint16 CurR;
Uint16 CurR2;
Uint16 CurL;
Sint16 LLX;
Sint16 LLY;
Sint16 k;
Sint16 Wx;
Sint16 Wy;
Sint16 DWx;
Sint16 Dwy;
bool V;
Uint8 B;
Uint8 PifTab[1024];

} // namespace CSPRNDR
