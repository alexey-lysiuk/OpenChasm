
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

#include "cspbio.h"

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
void ReDrawGround(/*...*/);
void ShowVideoBuffer(/*...*/);

void SetVideoMode()
{
    // Replaces Init320x200() and Init_HiMode()

    // TODO: remove hard-coded 640x480
    VideoW   = 640;
    VideoH   = 480;
    VideoBPL = 640;

    FloorDiv = Uint16(VideoW + 16 / 32);

    if (NULL != g_window)
    {
        SDL_DestroyWindow(g_window);
    }

    if (NULL != g_renderer)
    {
        SDL_DestroyRenderer(g_renderer);
    }

    g_window = SDL_CreateWindow("OpenChasm", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    if (NULL == g_window)
    {
        DoHalt(OC::Format("Cannot create window: %1%") % SDL_GetError());
    }

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (NULL == g_renderer)
    {
        DoHalt(OC::Format("Cannot create renderer: %1%") % SDL_GetError());
    }
/*
    SDL_RenderClear(g_renderer);
    SDL_RenderPresent(g_renderer);

    SDL_Event e;

    for (;;)
    {
        if (1 == SDL_PollEvent(&e)
            && (e.type == SDL_QUIT || e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN))
        {
            break;
        }
        else
        {
            SDL_Delay(100);
        }
    }
*/
    VideoEX = Uint16(VideoW - 1);
    VideoEY = Uint16(VideoH - 1);

    VideoCX = Uint16(VideoW / 2);
    VideoCY = Uint16(VideoH / 2);

    VPSize  = VideoBPL * VideoH;

    for (size_t i = 0; i < MulSW.size(); ++i)
    {
        MulSW[i] = Sint32(VideoBPL * i);
    }

    LinesBUF.LinesS.fill(-1);
    LinesBUF.LinesO.fill(-1);
    LinesBUF.LinesFH1.fill(-1);
    LinesBUF.LinesFH2.fill(-1);
    LinesBUF.LinesB.fill(-1);

    SetPalette();

    PutConsMessage2((OC::Format("Mode: %1%x%2%") % VideoW % VideoH).str());
}

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

SDL_Window*   g_window   = NULL;
SDL_Renderer* g_renderer = NULL;


} // namespace CSPBIO
