
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

    if (!original)
    {
        CSPBIO::SetPalette();

        //SoundIP::SetVolumes();

        //CSPBIO::ReInitViewConst();
    }
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


namespace
{

void ParseCommandLine(const int argc, const char* const* const argv)
{
    for (int i = 1; i < argc; ++i)
    {
        OC::String parameter = argv[i];
        boost::algorithm::to_lower_copy(parameter);

        if ("-safe" == parameter)
        {
            CSPBIO::SafeLoad = true;
        }
        else if ("-nomonsters" == parameter)
        {
            CSPBIO::Monsters = false;
        }
        else if ("-chojin" == parameter)
        {
            CSPBIO::Chojin = false;
        }
        else if ("-nodemo" == parameter)
        {
            CSPBIO::PlayDemo = false;
        }
        else if ("-monitor" == parameter)
        {
            CSPBIO::NETMonitor = CSPBIO::VESAPresent;
        }
        else if (boost::algorithm::starts_with(parameter, "-addon:"))
        {
            CSPBIO::AddonPath = parameter.substr(sizeof "-addon:" - 1);
            CSPBIO::UserMaps  = true;
        }
        else if ("-vmode" == parameter)
        {
            // TODO: video mode
        }
        else if ("-kalirate" == parameter)
        {
            // TODO: network
        }
        else if (boost::algorithm::starts_with(parameter, "-warp"))
        {
            const int level = SDL_atoi(parameter.c_str() + sizeof "-warp" - 1);

            if (level > 0 && level < 40)
            {
                CSPBIO::LevelN = Sint16(level);
            }

            CSPBIO::PlayDemo = 0;
            CSPBIO::MenuMode = 4;
        }
        else if (boost::algorithm::starts_with(parameter, "-skill"))
        {
            const int skill = SDL_atoi(parameter.c_str() + sizeof "-skill" - 1);

            if (skill >= 0 && skill <= 2)
            {
                CSPBIO::Skill = Sint16(skill);
            }
        }
        else if (boost::algorithm::starts_with(parameter, "-color"))
        {
            const int color = SDL_atoi(parameter.c_str() + sizeof "-color" - 1);

            if (color > 0 && color <= 8)
            {
                CSPBIO::SelfColor = Uint8(color);
            }
        }
        else if ("-nojoy" == parameter)
        {
            CSPBIO::JoyStick = false;
        }
        else if ("-nosound" == parameter)
        {
            SoundIP::sCard = 0;
        }
        else if ("-nomouse" == parameter)
        {
            CSPBIO::MouseD = false;
        }
    }
}

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

    CSPBIO::Players[0].PName  = CSPBIO::SelfNick;
    CSPBIO::Players[0].PColor = CSPBIO::SelfColor;

    CSPUTL::InitMessageSystem();

    ParseCommandLine(argc, argv);

    if (CSPBIO::SafeLoad)
    {
        // TODO: safe mode
    }

    if (CSPBIO::UserMaps)
    {
        SDL_Log("Add levels from: %s", CSPBIO::AddonPath.string().c_str());
    }

    // TODO: output hardware and diagnostic information

    CSPBIO::LoadCommonParts();
    CSPBIO::ScanLevels();

    // TODO: init sound

    CSPBIO::LoadGraphics();

    // TODO...

    return EXIT_SUCCESS;
}
