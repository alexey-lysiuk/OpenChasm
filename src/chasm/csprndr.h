
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

#ifndef OPENCHASM_CSPRNDR_H_INCLUDED
#define OPENCHASM_CSPRNDR_H_INCLUDED

namespace CSPRNDR
{

void InitModule();

void ProcessLights(/*...*/);
void AddLightSource(/*...*/);
void BackRender(/*...*/);
Uint16 QPifagorA32(/*...*/);
Sint16 MulVectors(/*...*/);
void RestoreLights(/*...*/);
void RenderLightOnMap(/*...*/);

extern Uint16 Wx1;
extern Uint16 Wy1;
extern Uint16 Wx2;
extern Uint16 Wy2;
extern Uint16 os;
extern Uint16 R;
extern Uint16 ccx;
extern Uint16 ccy;
extern Uint16 N;
extern Uint16 CurR;
extern Uint16 CurR2;
extern Uint16 CurL;
extern Sint16 LLX;
extern Sint16 LLY;
extern Sint16 k;
extern Sint16 Wx;
extern Sint16 Wy;
extern Sint16 DWx;
extern Sint16 Dwy;
extern bool V;
extern Uint8 B;
extern Uint8 PifTab[32][32];

} // namespace CSPRNDR

#endif // OPENCHASM_CSPRNDR_H_INCLUDED
