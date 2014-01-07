
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

#include "cspbio.h"

#include "oc/graphics.h"
#include "oc/utils.h"

namespace CSPBIO
{

void MovsED(/*...*/);
void MovsEW(/*...*/);
void SetVESAMode(/*...*/);
void SwitchBank(/*...*/);
void VESA_PutImage(/*...*/);
void VESA_Line(/*...*/);
void ClearUnusedScreens(/*...*/);
void InitVESAMonitor(/*...*/);
void VESA_TileScreen(/*...*/);
void vesa_DrawKey(/*...*/);

void ReDrawGround()
{
    const Uint16 screenWidth  = OC::Renderer::instance().screenWidth();
    const Uint16 screenHeight = OC::Renderer::instance().screenHeight();

    const Uint16 groundWidth  = Ground.width();
    const Uint16 groundHeight = Ground.height();

    for (Uint16 y = 0; y < screenHeight; y += groundHeight)
    {
        for (Uint16 x = 0; x < screenWidth; x += groundWidth)
        {
            OC::Renderer::instance().draw(Ground, x, y);
        }
    }
}

//void SetVideoMode()
//{
//    // Replaces Init320x200() and Init_HiMode()
//
//    // TODO: remove hard-coded 640x480
//    VideoW   = 640;
//    VideoH   = 480;
//    VideoBPL = VideoW;
//
//    FloorDiv = VideoW + 16 / 32;
//
//    VideoEX = VideoW - 1;
//    VideoEY = VideoH - 1;
//
//    VideoCX = VideoW / 2;
//    VideoCY = VideoH / 2;
//
//    VPSize  = VideoBPL * VideoH;
//
//    for (size_t i = 0; i < MulSW.size(); ++i)
//    {
//        MulSW[i] = Sint32(VideoBPL * i);
//    }
//
//    LinesBUF.LinesS.fill(-1);
//    LinesBUF.LinesO.fill(-1);
//    LinesBUF.LinesFH1.fill(-1);
//    LinesBUF.LinesFH2.fill(-1);
//    LinesBUF.LinesB.fill(-1);
//
//    PutConsMessage2((OC::Format("Mode: %1%x%2%") % VideoW % VideoH).str());
//}

void VESAGetDosMem(/*...*/);
void VESAFreeDosMem(/*...*/);
void ProcedError(/*...*/);
void RealInt10h(/*...*/);
void GetVESAInfo(/*...*/);
void GetModeInfo(/*...*/);
void OnlySwitchBank(/*...*/);

void InitVideo()
{
    // TODO...
}

void ClearMonitorWindow(/*...*/);

} // namespace CSPBIO
