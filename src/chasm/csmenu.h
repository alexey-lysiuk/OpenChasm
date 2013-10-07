
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

#ifndef OPENCHASM_CSMENU_H_INCLUDED
#define OPENCHASM_CSMENU_H_INCLUDED

#pragma pack(push, 1)

struct MenuRect
{
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
};

struct TMenuText
{
    char Main[16];
    MenuRect MainPos;
    char Skl[16];
    MenuRect SklPos;
    char Net[16];
    MenuRect NetPos;
    char Save[16];
    char Load[16];
    MenuRect SavePos;
    char Opti[338];
    MenuRect OptiPos;
    char Disp[104];
    MenuRect DispPos;
    char Resl[782];
    MenuRect ReslPos;
    char Cont[442];
    MenuRect ContPos;
    char Quit[128];
    MenuRect QuitPos;
    char Newg[96];
    MenuRect NewgPos;
    char NGSt[144];
    MenuRect NGStPos;
    char NGModes[66];
    char NGSkill[48];
    char NJst[96];
    MenuRect NJStPos;
    char NOpt[84];
    MenuRect NOptPos;
    char KName[1408];
    char GameNames[400];
};

#pragma pack(pop)


extern TMenuText PM;


void CsMenuInit();

#endif // OPENCHASM_CSMENU_H_INCLUDED
