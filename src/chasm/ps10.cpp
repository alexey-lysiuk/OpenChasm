
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

void LoadConfig(const bool original)
{
    CSPBIO::LastFName = original ? "chasm.cfg" : "chasm.def";

    const OC::Path configPath = OC::FileSystem::GetUserPath(CSPBIO::LastFName);
    OC::File configFile(configPath);

    // Change from original behavior: 
    // Do not exit if user config was not found, try to load default one instead

    if (!configFile.is_open())
    {
        if (original)
        {
            LoadConfig(false);
            return;
        }
        else
        {
            CSPBIO::PutConsMessage2("CHASM.DEF not found.");
            return;
        }
    }

    SoundIP::CDVolume = 8;
    
    CSPBIO::MSsens = 10;
    CSPBIO::Ms1ID = 0;
    CSPBIO::Ms2ID = 1;

    configFile.readBinary(CSPBIO::_FrontOn);
    configFile.readBinary(CSPBIO::_BackOn);
    configFile.readBinary(CSPBIO::_LeftOn);
    configFile.readBinary(CSPBIO::_RightOn);
    configFile.readBinary(CSPBIO::_SLeftOn);
    configFile.readBinary(CSPBIO::_SRightOn);
    configFile.readBinary(CSPBIO::_JumpOn);
    configFile.readBinary(CSPBIO::_FireOn);
    configFile.readBinary(CSPBIO::_ChangOn);
    configFile.readBinary(CSPBIO::_StrafeOn);
    configFile.readBinary(CSPBIO::_SpeedUpOn);
    configFile.readBinary(CSPBIO::_MLookOn);
    configFile.readBinary(CSPBIO::_MLookT);
    configFile.readBinary(CSPBIO::_ViewUpOn);
    configFile.readBinary(CSPBIO::_ViewCntrOn);
    configFile.readBinary(CSPBIO::_ViewDnOn);

    configFile.readBinary(CSPBIO::Ms1ID);
    configFile.readBinary(CSPBIO::Ms2ID);
    configFile.readBinary(CSPBIO::ms3id);

    configFile.readBinary(CSPBIO::RespawnTime);

    configFile.readBinary(SoundIP::FXVolume);
    configFile.readBinary(SoundIP::CDVolume);

    configFile.readBinary(CSPBIO::MSsens);
    configFile.readBinary(CSPBIO::Bright);
    configFile.readBinary(CSPBIO::Contrast);
    configFile.readBinary(CSPBIO::Color);
    configFile.readBinary(CSPBIO::FloorW);
    CSPBIO::b0 = configFile.readBinary<Uint8>(); // TODO ??? 2-byte variable but only one byte is read
    configFile.readBinary(CSPBIO::InfoPage);

    configFile.readPascalString(CSPBIO::SelfNick, 8);
    configFile.readBinary(CSPBIO::SelfColor);

    configFile.readBinary(CS3DM2::ShadowCount);
    configFile.readBinary(CSPBIO::EpisodeReset);
    configFile.readBinary(CSPBIO::Cocpit);
    configFile.readBinary(CSPBIO::ReverseMouse);
    configFile.readBinary(CSPBIO::MLookOn);
    configFile.readBinary(CSPBIO::AlwaysRun);

    configFile.readBinary(CSPBIO::NGCard);
    configFile.readBinary(CSPBIO::NGPort);
    configFile.readBinary(CSPBIO::NGBaud);

    configFile.readBinary(CSPBIO::w);
    configFile.readBinary(CSPBIO::Ll);

    // TODO: validate video mode

    CSPBIO::ChI(configFile);

    //CSPBIO::SetPalette();

    //SoundIP::SetVolumes();

    //CSPBIO::ReInitViewConst();
}

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

void Build3dScene()
{
    // TODO ...
}

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

    CSPBIO::PutConsMessage("CHASM - The Rift. v1.04");
    CSPBIO::PutConsMessage("(c) Megamedia Corp,");
    CSPBIO::PutConsMessage("    Action Forms Ltd.");
    CSPBIO::PutConsMessage("");

    // TODO: CheckNP(), IPX?

    for (size_t i = 0; i < SDL_TABLESIZE(CSPBIO::Players); ++i)
    {
        CSPBIO::Players[i].PlColorN = Sint16(i);
    }

    for (size_t i = 0; i < SDL_TABLESIZE(CSPBIO::Mul320); ++i)
    {
        CSPBIO::Mul320[i] = Uint16(i * 320);
    }

    Chasm::LoadConfig(true);

    // TODO...

    return EXIT_SUCCESS;
}
