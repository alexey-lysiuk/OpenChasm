
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

#include "csbrif.h"

#include "oc/types.h"

namespace Chasm
{
    void Build3dScene();
}

namespace CSBrif
{

void PlayBrifing(/*...*/);

void (*BuildSceneRout)() = Chasm::Build3dScene;

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

bool GoSkip;
Uint16 CurState;
Sint16 CurDelay;
Sint16 CurCar;
Sint16 CurVoice;
TCharacter Characters[3];
OC::String::value_type Command[41];
OC::String::value_type* BrText;
Sint16 Room;
Sint16 CurTop;
Sint16 CurLine;
void* BrifBar;
Camera__Type Camera;

} // namespace CSBrif
