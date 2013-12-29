
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

#include "csmenu.h"

#include "cspbio.h"

namespace CSMENU
{

void InitModule()
{
    LoadMenuResourses();
}

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

void ScanSavedNames()
{
    for (size_t i = 0; i < 9; ++i)
    {
        const OC::String saveFileName = (OC::Format("chasm%1$02i.sav") % i).str();
        const OC::Path savePath = OC::FileSystem::GetUserPath(saveFileName);

        OC::String saveName = "...";

        if (OC::FileSystem::IsPathExist(savePath))
        {
            OC::File saveFile(savePath);

            if (saveFile.is_open())
            {
                // TODO: handle read error
                saveName = saveFile.readPascalString(39);
            }
        }
        
        PM.GameNames.push_back(saveName);
    }
}

Sint16 KbWait = -1;
TMenuText PM;
CSPBIO::TPic MainMenu;
CSPBIO::TPic SklMenu;
CSPBIO::TPic NetMenu;
CSPBIO::TPic m_pause;
CSPBIO::TPic PTors;
Sint16 MnSY;
Uint8 MenuTiler[4096];
Uint8 ColorShift;
Uint8 ColorZero;
Uint8 RecolorMap[256];

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

namespace
{

CSPBIO::ResourceFile& operator>>(CSPBIO::ResourceFile& file, MenuRect& rect)
{
    file >> rect.x1;
    file >> rect.y1;
    file >> rect.x2;
    file >> rect.y2;

    // Skip comment
    OC::ReadLine(file);
    
    return file;
}

TMenuText::StringList ReadMenuStringVector(CSPBIO::ResourceFile& file, const size_t count)
{
    TMenuText::StringList result;

    for (size_t i = 0; i < count; ++i)
    {
        const OC::String line = ReadLine(file);
        result.push_back(line);
    }

    return result;
}

void ParseMenuDescriptionFile()
{
    CSPBIO::ResourceFile menuFile("menu/menu.txt");

    menuFile >> PM.MainPos;
    PM.Main = ReadLine(menuFile);

    menuFile >> PM.SklPos;
    PM.Skl = ReadLine(menuFile);

    menuFile >> PM.NetPos;
    PM.Net = ReadLine(menuFile);

    menuFile >> PM.SavePos;
    PM.Save = ReadLine(menuFile);
    PM.Load = ReadLine(menuFile);

    menuFile >> PM.OptiPos;
    PM.Opti = ReadMenuStringVector(menuFile, 13);

    menuFile >> PM.DispPos;
    PM.Disp = ReadMenuStringVector(menuFile, 4);

    menuFile >> PM.ReslPos;
    PM.Resl = ReadMenuStringVector(menuFile, 13);

    menuFile >> PM.ContPos;
    PM.Cont = ReadMenuStringVector(menuFile, 17);

    menuFile >> PM.QuitPos;
    PM.Quit = ReadMenuStringVector(menuFile, 4);

    menuFile >> PM.NewgPos;
    PM.Newg = ReadMenuStringVector(menuFile, 3);

    menuFile >> PM.NGStPos;
    PM.NGSt = ReadMenuStringVector(menuFile, 9);
    PM.NGModes = ReadMenuStringVector(menuFile, 3);
    PM.NGSkill = ReadMenuStringVector(menuFile, 3);

    menuFile >> PM.NJStPos;
    PM.NJst = ReadMenuStringVector(menuFile, 6);

    menuFile >> PM.NOptPos;
    PM.NOpt = ReadMenuStringVector(menuFile, 4);

    OC::ReadLine(menuFile);
    PM.KName = ReadMenuStringVector(menuFile, 88);

    CSPBIO::ChI(menuFile);

    // TODO: init resolutions
}

void LoadMenuAssets()
{
    CSPBIO::ResourceFile tileFile("menu/m_tile1.cel");

    tileFile.seekg(CSPBIO::CEL_DATA_OFFSET);
    tileFile.read(reinterpret_cast<char*>(MenuTiler), sizeof MenuTiler);

    CSPBIO::ChI(tileFile);

    MainMenu.load("menu/m_main.cel");
    SklMenu.load("menu/m_new.cel");
    NetMenu.load("menu/m_netwrk.cel");
    m_pause.load("menu/m_pause.cel");
    PTors.load("menu/ptors.cel");
}

} // unnamed namespace

void LoadMenuResourses()
{
    ParseMenuDescriptionFile();
    ScanSavedNames();
    LoadMenuAssets();
}

// /* nested */ void ShiftRect(/*...*/);

} // namespace CSMENU
