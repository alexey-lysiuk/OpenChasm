
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

namespace CSPBIO
{
    struct TPic;
}

namespace CSMENU
{

#pragma pack(push, 1)

struct MenuRect
{
    Sint16 x1;
    Sint16 y1;
    Sint16 x2;
    Sint16 y2;
};

struct TMenuText
{
    OC::String Main;
    MenuRect MainPos;

    OC::String Skl;
    MenuRect SklPos;

    OC::String Net;
    MenuRect NetPos;
    
    OC::String Save;
    OC::String Load;
    MenuRect SavePos;

    OC::StringArray Opti;
    MenuRect OptiPos;

    OC::StringArray Disp;
    MenuRect DispPos;

    OC::StringArray Resl;
    MenuRect ReslPos;

    OC::StringArray Cont;
    MenuRect ContPos;

    OC::StringArray Quit;
    MenuRect QuitPos;

    OC::StringArray Newg;
    MenuRect NewgPos;

    OC::StringArray NGSt;
    MenuRect NGStPos;

    OC::StringArray NGModes;
    OC::StringArray NGSkill;
    OC::StringArray NJst;
    MenuRect NJStPos;

    OC::StringArray NOpt;
    MenuRect NOptPos;

    OC::StringArray KName;

    OC::StringArray GameNames;
};

#pragma pack(pop)


void InitModule();

void CreateRecolorMap(/*...*/);
void PutString(/*...*/);
void PutStringFloat(/*...*/);
void PutChar(/*...*/);
void PutStr(/*...*/);
void PutStrCenter(/*...*/);
void UpDateConsole(/*...*/);
void DrawMenuRect(/*...*/);
void UpDateMenu(/*...*/);
void UpdatePause(/*...*/);
void CorrectMenuPos(/*...*/);
void ScanSavedNames();

extern Sint16 KbWait;
extern TMenuText PM;
extern CSPBIO::TPic MainMenu;
extern CSPBIO::TPic SklMenu;
extern CSPBIO::TPic NetMenu;
extern CSPBIO::TPic m_pause;
extern CSPBIO::TPic PTors;
extern Sint16 MnSY;
extern void* MenuTiler;
extern Uint8 ColorShift;
extern Uint8 ColorZero;
extern Uint8 RecolorMap[256];

void PutIcon(/*...*/);
void PutIconDark(/*...*/);
void PutIconRecolor(/*...*/);
void PutIconFF2Sub(/*...*/);
void PutIconD(/*...*/);
void PutStrFix(/*...*/);
void PutStrOn(/*...*/);
void PutStrBack(/*...*/);
void PutStrBackOn(/*...*/);
void DrawMenuBar(/*...*/);
void PutScroller(/*...*/);
void PutScroller15(/*...*/);
void LoadPicFromCel(/*...*/);
void LoadMenuResourses(/*...*/);
// /* nested */ void ShiftRect(/*...*/);

} // namespace CSMENU

#endif // OPENCHASM_CSMENU_H_INCLUDED
