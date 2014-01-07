
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

#ifndef OPENCHASM_CSBRIF_H_INCLUDED
#define OPENCHASM_CSBRIF_H_INCLUDED

#include "oc/types.h"

namespace CSPBIO
{
    struct TOHeader;
    struct TPoint3di;
};

namespace CSBrif
{

struct TCharacter
{
    Sint16 XPos;
    Sint16 YPos;
    Sint16 ZPos;
    Uint16 DFi;
    CSPBIO::TOHeader* Model;
    CSPBIO::TPoint3di* PAni[16];
    Uint16 AniTime[16];
    Uint16 Phase;
    Uint16 FTime;
};

struct Camera__Type
{
    Sint16 camx;
    Sint16 camy;
    Sint16 CamZ;
    Uint16 camfi;
    Sint16 MvTime;
    Sint16 mvSpeed;
    Sint16 mvx;
    Sint16 mvy;
    Sint16 mvz;
    Uint16 mvfi;
};


void PlayBrifing(/*...*/);

extern void (*BuildSceneRout)();

void DeInitBrifing(/*...*/);
void ReinitBrifView(/*...*/);
void LoadVoice(/*...*/);
void StopSounds(/*...*/);
void SetAni(/*...*/);
void AddText(/*...*/);
void ReadRealMul(/*...*/);

OC::String ReadCommand(/*...*/);

void LoadCharacter(/*...*/);
void LoadSetup(/*...*/);
void GotoProc(/*...*/);
void ExecNextCommand(/*...*/);
void PreProcessBrif(/*...*/);
void ProcessBrif(/*...*/);

extern bool GoSkip;
extern Uint16 CurState;
extern Sint16 CurDelay;
extern Sint16 CurCar;
extern Sint16 CurVoice;
extern TCharacter Characters[3];
extern OC::String::value_type Command[41];
extern OC::String::value_type* BrText;
extern Sint16 Room;
extern Sint16 CurTop;
extern Sint16 CurLine;
extern void* BrifBar;
extern Camera__Type Camera;

} // namespace CSBrif

#endif // OPENCHASM_CSBRIF_H_INCLUDED
