
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

#include "cs_demo.h"

#include "oc/filesystem.h"

#include "cspbio.h"

namespace CS_DEMO
{

void ExecuteEvent(/*...*/);
void DeInit_DemoSystem(/*...*/);
void EndDemo(/*...*/);
void StartDemo(/*...*/);

void GetNextDemoNumber()
{
    using namespace CSPBIO;

    for (size_t i = 0; i < 64; ++i)
    {
        if (++LevelN > 64)
        {
            LevelN = 1;
        }

        const OC::String filename = (OC::Format("chasm.r%1$02i") % LevelN).str();
        OC::BinaryResource demoFile(filename, OC::Resource::PATH_MAY_NOT_EXIST);

        if (demoFile.is_open())
        {
            return;
        }
    }

    PlayDemo = false;
    LevelN   = 1;
}

void Demo_RecordNext(/*...*/);
void Demo_ReadNext(/*...*/);
bool Rocket_WallCheck(/*...*/);
void InitMZPosition(/*...*/);
void AnimateZMovement(/*...*/);
void AnimateMonsters(/*...*/);

Sint32 demotime;

void Init_DemoSystem(/*...*/);
void Demo_ReadNextQuant(/*...*/);
void CorrectPlayerPos(/*...*/);
bool GetTarget(/*...*/);
bool MakePunch(/*...*/);
void GetPlayerTo(/*...*/);
Uint8 GetAttack(/*...*/);
void AnimateExternal(/*...*/);

Uint16 DemoTakts;
Uint16 DemoOfs;
Uint16 DBlockSize;
void* DemoPtr;
Uint16 DmSeg;
Uint16 DTakt;
bool MemoActive = false;
TPlayerState* PPS;
CSPBIO::TEvent DEvent;
CSPBIO::TMonster M;
Sint16 plx;
Sint16 ply;

// /* nested */ void TryToGo(/*...*/);
// /* nested */ void TryToGo2B(/*...*/);

}
