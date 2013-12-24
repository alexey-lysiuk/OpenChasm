
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

#include "chasm.h"

#include "soundip/soundip.h"
#include "cs3dm2.h"
#include "cs_demo.h"
#include "csact.h"
#include "csmenu.h"
#include "cspbio.h"
#include "csprndr.h"
#include "csputl.h"


namespace Chasm
{

void WhatKey(/*...*/);
void TimerFM(/*...*/);
void LoadConfig(/*...*/);
void CalcYMin(/*...*/);
void StartPaint(/*...*/);
void UpDateRedShade(/*...*/);
void UpDateGreenShade(/*...*/);
void UpdateBlueShade(/*...*/);
void DrawItems(/*...*/);
void EndPaint(/*...*/);
bool ExpandWall(/*...*/);
void ExpandFrame(/*...*/);
bool ExpandPicture(/*...*/);
void ExpandObject(/*...*/);
void DrawHoles(/*...*/);
void Expand3dObject(/*...*/);
void ExpandRocket(/*...*/);
void ExpandMine(/*...*/);
void ExpandSepPart(/*...*/);
void ExpandAmmoBag(/*...*/);
void ExpandBlow(/*...*/);
void ExpandPlayer(/*...*/);
void ExpandMonster(/*...*/);
void MapXY(/*...*/);
void MoveRocket(/*...*/);
void AnimateRockets(/*...*/);
bool GetNearestWall(/*...*/);
void AddClientProcesses(/*...*/);
void AnimateSwitches(/*...*/);
void MakeTeleBlow(/*...*/);
void CheckTelePorts(/*...*/);
void CheckFloorLinks(/*...*/);
void DeinitMonitor(/*...*/);
void SwitchMonitor(/*...*/);
void ReInitOwners(/*...*/);
void InsertPlayers(/*...*/);
void NewGame(/*...*/);
void MenuStartNet(/*...*/);
void MenuJoinNet(/*...*/);
void ExecConsole(/*...*/);
void ProcessConsole(/*...*/);
void LeftRight(/*...*/);
void LR_Roll(/*...*/);
void LookForLevel(/*...*/);
void RemoveMouse(/*...*/);
void ProcessMenu(/*...*/);
void Build3dScene(/*...*/);
void SwitchToNextWeapon(/*...*/);
bool WeaponAvail(/*...*/);
void ChangeWeapon(/*...*/);
void ProcessDevices(/*...*/);
void ProcessPreKeyboard(/*...*/);
void SetPFlags(/*...*/);
void MoveServerPlayers(/*...*/);
void CorrectPlayerPosition(/*...*/);
void CorrectRocketPosition(/*...*/);
void CorrectMonstersPosition(/*...*/);
void RedrawWindowSelection(/*...*/);
void AnimateKeyboard(/*...*/);
void StopSound(/*...*/);
void DoGame(/*...*/);
void CheckQuit(/*...*/);
void ShowIntro1(/*...*/);

}


int main(int argc, char** argv)
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", SDL_GetError(), NULL);
        return EXIT_FAILURE;
    }

    atexit(SDL_Quit);

    SoundIP::InitModule();
    CSPBIO::InitModule();
    CSPRNDR::InitModule();
    CSMENU::InitModule();
    CS3DM2::InitModule();

    srand(static_cast<unsigned int>(CSPBIO::StartUpRandSeed));

    // TODO...

    return EXIT_SUCCESS;
}
