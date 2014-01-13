
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

#include "chasm.h"

#include "oc/filesystem.h"
#include "oc/graphics.h"
#include "oc/utils.h"

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
    const char* const filename = original ? "chasm.cfg" : "chasm.def";
    OC::FileSystem::instance().setLastFileName(filename);

    const OC::Path configPath = OC::FileSystem::instance().userPath(filename);
    OC::BinaryFile configFile(configPath);

    // Change from original behavior: 
    // Do not exit if user config was not found, try to load default one instead

    if (!configFile.is_open())
    {
        if (original)
        {
            CSPBIO::PutConsMessage2("File chasm.cfg was not found, fallback to default settings...");

            LoadConfig(false);
            return;
        }
        else
        {
            CSPBIO::PutConsMessage2("File chasm.def was not found");
            return;
        }
    }

    SoundIP::CDVolume = 8;
    
    CSPBIO::MSsens = 10;
    CSPBIO::Ms1ID = 0;
    CSPBIO::Ms2ID = 1;

    configFile >> CSPBIO::_FrontOn;
    configFile >> CSPBIO::_BackOn;
    configFile >> CSPBIO::_LeftOn;
    configFile >> CSPBIO::_RightOn;
    configFile >> CSPBIO::_SLeftOn;
    configFile >> CSPBIO::_SRightOn;
    configFile >> CSPBIO::_JumpOn;
    configFile >> CSPBIO::_FireOn;
    configFile >> CSPBIO::_ChangOn;
    configFile >> CSPBIO::_StrafeOn;
    configFile >> CSPBIO::_SpeedUpOn;
    configFile >> CSPBIO::_MLookOn;
    configFile >> CSPBIO::_MLookT;
    configFile >> CSPBIO::_ViewUpOn;
    configFile >> CSPBIO::_ViewCntrOn;
    configFile >> CSPBIO::_ViewDnOn;

    configFile >> CSPBIO::Ms1ID;
    configFile >> CSPBIO::Ms2ID;
    configFile >> CSPBIO::ms3id;

    configFile >> CSPBIO::RespawnTime;

    configFile >> SoundIP::FXVolume;
    configFile >> SoundIP::CDVolume;

    Uint16 brightness, contrast, color;
    Uint8 b0;

    configFile >> CSPBIO::MSsens;
    configFile >> brightness;
    configFile >> contrast;
    configFile >> color;
    configFile >> CSPBIO::FloorW;
    configFile >> b0;
    configFile >> CSPBIO::InfoPage;

    OC::BitmapManager::instance().setPaletteParameters(contrast, color, brightness);

    CSPBIO::b0 = b0; // ??? 2-byte variable but only one byte is read

    configFile.readString(CSPBIO::SelfNick, 8);
    configFile >> CSPBIO::SelfColor;

    configFile >> CS3DM2::ShadowCount;
    configFile >> CSPBIO::EpisodeReset;
    configFile >> CSPBIO::Cocpit;
    configFile >> CSPBIO::ReverseMouse;
    configFile >> CSPBIO::MLookOn;
    configFile >> CSPBIO::AlwaysRun;

    configFile >> CSPBIO::NGCard;
    configFile >> CSPBIO::NGPort;
    configFile >> CSPBIO::NGBaud;

    configFile >> CSPBIO::w;
    configFile >> CSPBIO::Ll;

    // TODO: validate video mode

    OC::FileSystem::instance().checkIO(configFile);

    if (!original)
    {
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

void ReInitOwners()
{
    CSPBIO::CurOwner = 0;

    for (size_t i = 0; i < CSPBIO::VideoOwners.size(); ++i)
    {
        CSPBIO::VideoOwners[i] = Uint8(i + 1);
    }
}

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
            const OC::String path = parameter.substr(sizeof "-addon:" - 1);
            OC::FileSystem::instance().setAddonPath(path);
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
        OC::DoHaltSDLError("Failed to initialize SDL.");
        return EXIT_FAILURE;
    }

    atexit(SDL_Quit);

    OC::FileSystem::initialize();
    OC::BitmapManager::initialize();
    OC::Renderer::initialize();

    SoundIP::InitModule();
    CSPBIO::InitModule();
    CSPRNDR::InitModule();
    CSMENU::InitModule();
    csact::InitModule();
    CS3DM2::InitModule();

    srand(static_cast<unsigned int>(CSPBIO::StartUpRandSeed));

    CSPBIO::PutConsMessage("CHASM - The Rift. v1.04");
    CSPBIO::PutConsMessage("(c) Megamedia Corp,");
    CSPBIO::PutConsMessage("    Action Forms Ltd.");
    CSPBIO::PutConsMessage("");

    // TODO: CheckNP(), IPX?

    for (size_t i = 0; i < CSPBIO::Players.size(); ++i)
    {
        CSPBIO::Players[i].PlColorN = Sint16(i);
    }

    for (size_t i = 0; i < CSPBIO::Mul320.size(); ++i)
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

    const OC::Path& addonPath = OC::FileSystem::instance().addonPath();
    if (!addonPath.empty())
    {
        SDL_Log("Add levels from: %s", addonPath.string().c_str());
    }

    // TODO: output hardware and diagnostic information

    CSPBIO::LoadCommonParts();
    CSPBIO::ScanLevels();

    // TODO: init sound

    CSPBIO::LoadGraphics();

    // TODO: csact::ReleaseLevel();

    // TODO: video modes support
    OC::Renderer::instance().setVideoMode(640, 480);

    CSPBIO::ReDrawGround();

    Chasm::ReInitOwners();

    if (0 != CSPBIO::PlayDemo)
    {
        CSPBIO::LevelN = 0;

        CS_DEMO::GetNextDemoNumber();
    }

    // TODO: init joystick

    for (;;)
    {
        switch (CSPBIO::MenuCode)
        {
            case 4:
                csact::LoadLevel();

                CSPBIO::MenuCode = 1;
                break;
                
            default:
                //SDL_assert(false);
                break;
        }

        SDL_Event e;

        if (1 == SDL_PollEvent(&e) && SDL_QUIT == e.type)
        {
            break;
        }
        else
        {
            OC::Renderer::instance().present();
        }
    }

    OC::Renderer::shutdown();
    OC::BitmapManager::shutdown();
    OC::FileSystem::shutdown();

    return EXIT_SUCCESS;
}
