
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

#ifndef OPENCHASM_CHASM_H_INCLUDED
#define OPENCHASM_CHASM_H_INCLUDED

#include "oc/types.h"

namespace Chasm
{

struct TServer_Patch
{
    Uint16 iPacketSize;
    Uint16 iPacketCount;
    Uint16 iServerVersion;
    Uint16 iExtDataOfs;
    Uint16 iPActive;
    Sint32 iServerTime;
    Sint32 iReceiveTime;
    Sint16 iLevelN;
    Sint16 iMLen;
    Uint8 iCommand;
    Uint8 iSkill;
    Uint16 iRCount;
    Uint16 iMCount;
    Uint16 iECount;
    Uint16 iMNCount;
    Uint8 iLevelChanges[16];
    Uint16 iProcState[4];
    Uint8 DBuf[3000];
};

struct TClient_Patch
{
    Uint8 iUpDated;
    Uint16 iPlayerID;
    Sint16 iPlNumber;
    OC::String::value_type iPName[11];
    Uint16 iksFlags;
    Uint16 iPlFi;
    Uint16 iColor;
    Sint16 iPlLz;
    Sint16 irv;
    Sint16 iCurGun;
    Sint16 imsdvx;
    Sint16 imsdvy;
};

struct TMPlayerInfo
{
    bool iActive;
    OC::String::value_type iPName[9];
    Sint16 iPlHx;
    Sint16 iPlHy;
    Sint16 iPlhz0;
    Sint16 iPlLz;
    Sint16 v;
    Sint16 sv;
    Sint16 rv;
    Sint16 vz;
    Sint16 iev;
    Sint16 evfi;
    Uint16 iPlFi;
    Uint16 iksFlags;
    Uint16 iFTime;
    Uint8 iPhase;
    Uint8 iWFlags;
    Uint8 iFrags;
    Uint8 iArmor;
    Sint16 iLife;
    Uint16 iPFlags;
    Uint16 iPlayerID;
    Uint8 iAmmo[8];
    Uint16 iColor;
};

struct TDPMIRegs
{
    Sint32 rDI;
    Sint32 rSI;
    Sint32 rBP;
    Sint32 Reserv;
    Sint32 xBX;
    Sint32 xDX;
    Sint32 xCX;
    Sint32 xAX;
    Uint16 rFlags;
    Uint16 rES;
    Uint16 rDS;
    Uint16 rFS;
    Uint16 rGS;
    Uint16 rIP;
    Uint16 rCS;
    Uint16 rSP;
    Uint16 rSS;
};

struct PalBuf__Element
{
    Uint8 R;
    Uint8 G;
    Uint8 B;
};


void GetRealModeIntVector(/*...*/);
void RealInt60h(/*...*/);
void DO_CD_Play(/*...*/);
void DO_CD_Stop(/*...*/);
void ProcessCD(/*...*/);
void RefreshMachineMode(/*...*/);
void ReInstallFreeECB(/*...*/);
void ReinitPlayer(/*...*/);
void MakeChanges(/*...*/);
void DoneChanges(/*...*/);
void CorrectProcesses(/*...*/);
void DoneProcesses(/*...*/);
Uint8 GetFreeNetNumber(/*...*/);
void ConnectIPXProcessor(/*...*/);
void CheckNP(/*...*/);
void INIT_IPX_SERVER(/*...*/);
void INIT_IPX_CLIENT(/*...*/);
void CloseIPXChannel(/*...*/);
void CheckSendComplette(/*...*/);
void SendServerPatch(/*...*/);
void LoadClientPatch(/*...*/);
void LoadServerPatch(/*...*/);
void SendClientPatch(/*...*/);
bool CheckIDsConflict(/*...*/);
void LookForServer(/*...*/);
void ScanNet(/*...*/);
void JoinNetworkGame(/*...*/);
void SendServerPost(/*...*/);
void SyncroTime(/*...*/);
void WaitServer(/*...*/);

Sint16 MulVectors(/*...*/);
bool Test2Vectors(/*...*/);
void VILineL(/*...*/);
void VILineL_hi(/*...*/);
void ShowLine(/*...*/);
void ShowLine2(/*...*/);
void ShowGlassLine(/*...*/);
void ShowGlassLine2(/*...*/);
void ShowGlassLine4(/*...*/);
void ShowSegment(/*...*/);
void ShowSegment2(/*...*/);
void VIlinePack(/*...*/);
void VIlineUpPack(/*...*/);
void Draw_Cell1(/*...*/);
void Draw_Cell2(/*...*/);
void Draw_Cell3(/*...*/);
void CellVHi(/*...*/);
void Draw_Floor1(/*...*/);
void Draw_Floor2(/*...*/);
void Draw_Floor3(/*...*/);
void FloorVHi(/*...*/);
void MovEX(/*...*/);
void BuildSky(/*...*/);
void BuildFloorCell(/*...*/);
void DrawCross(/*...*/);
void ShowValue(/*...*/);

void WhatKey(/*...*/);
void TimerFM(/*...*/);
void LoadConfig(const bool original);
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
void Build3dScene();
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

extern bool Obj3d;
extern Sint16 ClockCount;
extern Uint8 CFlr;
extern Uint8 LSMenuY;
extern Uint16 SkyY;
extern Uint16 SkyX;
extern Uint16 AliasMask;
extern bool InversGlass;
extern TDPMIRegs DRegs;
extern TServer_Patch* PServerLocal;
extern TServer_Patch* PServerPatch;
extern TClient_Patch* PClientPatches;
extern TMPlayerInfo* iMyPlayer;
extern TMPlayerInfo* iPlayer;
extern Uint16 IPXNpSeg;
extern Uint16 IPXServOfs;
extern Uint16 IPXClientOfs;
extern bool KALI;
extern bool NPinst;
extern Sint32 NextSendTime;
extern Sint32 NetPeriod;
extern Sint32 LastServerTime;
extern Sint16 DeltaT;
extern Uint16 DLSeg;
extern Uint16 DsSeg;
extern Uint16 DsOfs;
extern Uint16 DpOfs;
extern Uint16 FLen;
extern Uint16 nn;
extern Uint16 Cpx;
extern Uint16 Cpy;
extern Uint8 Xi;
extern Uint8 Yi;
extern Sint32 FCSAddr;
extern Uint16 HalfShr;
extern Sint16 Blow;
extern Sint16 Cr;
extern Sint16 Sd;
extern Sint16 rdfi;
extern Sint16 rn;
extern Sint16 rtgx;
extern Sint16 rtgy;
extern Sint16 rtgz;

// /* nested */ bool JoinServer(/*...*/);
// /* nested */ void SwapI(/*...*/);

} // namespace Chasm

#endif // OPENCHASM_CHASM_H_INCLUDED
