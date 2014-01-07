
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

#ifndef OPENCHASM_CS_DEMO_H_INCLUDED
#define OPENCHASM_CS_DEMO_H_INCLUDED

namespace CSPBIO
{
    struct TEvent;
    struct TMonster;
};

namespace CS_DEMO
{

struct TPlayerState
{
    Sint16 Dhx;
    Sint16 Dhy;
    Uint8 DCurGun;
    Uint8 DAmmo;
    Uint8 DLife;
    Uint8 DArmor;
    Uint16 Dfi;
    Uint16 DPFlags;
    Uint16 DHz;
    Sint16 DLookVz;
};


void ExecuteEvent(/*...*/);
void DeInit_DemoSystem(/*...*/);
void EndDemo(/*...*/);
void StartDemo(/*...*/);
void GetNextDemoNumber();
void Demo_RecordNext(/*...*/);
void Demo_ReadNext(/*...*/);
bool Rocket_WallCheck(/*...*/);
void InitMZPosition(/*...*/);
void AnimateZMovement(/*...*/);
void AnimateMonsters(/*...*/);

extern Sint32 demotime;

void Init_DemoSystem(/*...*/);
void Demo_ReadNextQuant(/*...*/);
void CorrectPlayerPos(/*...*/);
bool GetTarget(/*...*/);
bool MakePunch(/*...*/);
void GetPlayerTo(/*...*/);
Uint8 GetAttack(/*...*/);
void AnimateExternal(/*...*/);

extern Uint16 DemoTakts;
extern Uint16 DemoOfs;
extern Uint16 DBlockSize;
extern void* DemoPtr;
extern Uint16 DmSeg;
extern Uint16 DTakt;
extern bool MemoActive;
extern TPlayerState* PPS;
extern CSPBIO::TEvent DEvent;
extern CSPBIO::TMonster M;
extern Sint16 plx;
extern Sint16 ply;

// /* nested */ void TryToGo(/*...*/);
// /* nested */ void TryToGo2B(/*...*/);

} // namespace CS_DEMO

#endif // OPENCHASM_CS_DEMO_H_INCLUDED
