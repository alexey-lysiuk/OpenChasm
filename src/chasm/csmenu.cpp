
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

#include "csmenu.h"

#include "oc/filesystem.h"
#include "oc/graphics.h"

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
        const OC::Path savePath = OC::FileSystem::instance().userPath(saveFileName);

        OC::String saveName = "...";

        if (OC::FileSystem::isPathExist(savePath))
        {
            OC::BinaryFile saveFile(savePath);

            if (saveFile.is_open())
            {
                // TODO: handle read error
                saveName = saveFile.readString(39);
            }
        }
        
        PM.GameNames.push_back(saveName);
    }
}

Sint16 KbWait = -1;
TMenuText PM;
OC::Bitmap MainMenu;
OC::Bitmap SklMenu;
OC::Bitmap NetMenu;
OC::Bitmap m_pause;
OC::Bitmap PTors;
Sint16 MnSY;
OC::Bitmap MenuTiler;
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

OC::TextResource& operator>>(OC::TextResource& file, MenuRect& rect)
{
    file >> rect.x1;
    file >> rect.y1;
    file >> rect.x2;
    file >> rect.y2;

    file.skipLine();
    
    return file;
}

TMenuText::StringList ReadMenuStringVector(OC::TextResource& file, const size_t count)
{
    TMenuText::StringList result;

    for (size_t i = 0; i < count; ++i)
    {
        const OC::String line = file.readLine();
        result.push_back(line);
    }

    return result;
}

void ParseMenuDescriptionFile()
{
    OC::TextResource menuFile("menu/menu.txt");

    menuFile >> PM.MainPos;
    PM.Main = menuFile.readLine();

    menuFile >> PM.SklPos;
    PM.Skl = menuFile.readLine();

    menuFile >> PM.NetPos;
    PM.Net = menuFile.readLine();

    menuFile >> PM.SavePos;
    PM.Save = menuFile.readLine();
    PM.Load = menuFile.readLine();

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

    menuFile.skipLine();
    PM.KName = ReadMenuStringVector(menuFile, 88);

    OC::FileSystem::instance().checkIO(menuFile);

    // TODO: init resolutions
}

void LoadMenuAssets()
{
    MenuTiler.load("menu/m_tile1.cel");
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
