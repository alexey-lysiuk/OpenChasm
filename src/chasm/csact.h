
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

#ifndef OPENCHASM_CSACT_H_INCLUDED
#define OPENCHASM_CSACT_H_INCLUDED

#include "oc/types.h"

namespace OC
{
    class BinaryInputStream;
    class TextResource;
}

namespace csact
{

struct TChangesList__Element
{
    Sint16 wx;
    Sint16 wy;
};

struct TLinksList__Element
{
    char c;
    Sint16 swx;
    Sint16 swy;
    Sint16 pron;
};

struct TProLine
{
    Sint16 LX;
    Sint16 LY;
    OC::String::value_type LText[50];
};

struct TMessage
{
    TProLine txt[7];
    Sint16 delay;
};

struct SwList__Element
{
    Sint16 swx;
    Sint16 swy;
};

struct SubProc__Element
{
    char Command;
    Sint16 wx;
    Sint16 wy;
    Sint16 __dx;
    Sint16 dy;
    Sint16 dfi;
    Sint16 CurDx;
    Sint16 CurDy;
    Sint16 CurFi;
    Sint16 Speed;
    Sint16 ox1;
    Sint16 oy1;
    Sint16 ox2;
    Sint16 oy2;
};

struct TProcess
{
    bool Active;
    Uint8 CurMode;
    Uint8 Locked;
    Uint8 CheckMode;
    bool Mortal;
    bool Lightremap;
    Sint16 DefSpeed;
    Sint16 DelayT;
    Sint16 WaitT;
    Sint16 LoopT;
    Sint16 LoopCnt;
    Sint16 FirstOnMID;
    Sint16 OnMessID;
    Sint16 LockMessId;
    Sint16 SFXid;
    Sint16 SFXOn;
    Sint16 SFXx;
    Sint16 SFXy;
    Sint16 ProEndDelay;
    Sint16 SubsCount;
    Sint16 SwCount;
    Sint16 CurTime;
    Sint16 CurLoop;
    SwList__Element SwList[4];
    SubProc__Element SubProc[16];
};

struct TNetCList__Element
{
    Sint16 wx;
    Sint16 wy;
};

struct TMT
{
    Sint16 mx;
    Sint16 my;
    Sint16 MType;
    Uint8 FI;
    Uint8 Mode;
};

OC::BinaryInputStream& operator>>(OC::BinaryInputStream& stream, TMT& value);


void InitModule();

void MoveOn(/*...*/);
void GetMFloorZ(/*...*/);
bool MS_WallCheck(/*...*/);
bool NotFreeForMonster(/*...*/);
void StartLoading();
void NextLoading();
void GetLandHeight(/*...*/);
void MakeTeleEffect(/*...*/);
void AddMine(/*...*/);
void AddSepPart(/*...*/);
void AddAmmoBag(/*...*/);
void RemoveAmmoBag(/*...*/);
void AddSinglePart(/*...*/);
void ExplodeMonster(/*...*/);
void SetMePain(/*...*/);
void AddDeadPlayer(/*...*/);
void ExplodePlayer(/*...*/);
void ReleaseLevel(/*...*/);
void ReloadResources();
void ScanMap();
void LoadProFile(/*...*/);
void LoadFloorMap(/*...*/);
void LoadLevel();
void SaveGame(/*...*/);
void LoadGame(/*...*/);
void ShootMe(/*...*/);
void SetProcMessage(/*...*/);
void StartProcess(/*...*/);
void AnimateProcesses(/*...*/);
void StartUpProcesses(/*...*/);

extern std::vector<TProcess> PProc;
extern std::vector<TLinksList__Element> PLinks;
extern std::vector<TMessage> PMList;
extern std::vector<TChangesList__Element> PChanges;
extern Sint16 MortalTimer;
extern bool MortalTick;

Sint16 MulVectors(/*...*/);
Uint8 LocUsed(/*...*/);
Uint8 LocUsedTar(/*...*/);
void GetFloorLoHi(/*...*/);
Uint8 GetFloorZ(/*...*/);
void LoadSpryte(const size_t index);
Uint8 sgn(/*...*/);
void LoadFrame(const size_t index);
void LoadSky(const OC::String& resourceString);
void SetCDTrack(const OC::String& resourceString);
void SetDepth(const OC::String& resourceString);
void ReloadFloors(/*...*/);
void LoadGFXIndex(OC::TextResource& resource);
void InitZPositions(/*...*/);
void InitChanges(/*...*/);
OC::String ReadCommand(/*...*/);
void ReadRealMul(/*...*/);
void LoadLinks(/*...*/);
void LoadTeleports(/*...*/);
void ReadMess(/*...*/);
void LoadMessage(/*...*/);
void LoadAction(/*...*/);
void LoadProcess(/*...*/);
void Stop3d(/*...*/);
void LoadEndCamera(/*...*/);
void InitLevelDefaults();
void ProcessDeathZone(/*...*/);
bool CheckConflict(/*...*/);
bool CheckLifePoint(/*...*/);
bool LifeConflict(/*...*/);
void RemapWall(/*...*/);
void ContinueProcess(/*...*/);

extern boost::array<Uint8, 16> BrTab;
extern bool Corrected;
extern Sint16 cfx;
extern Sint16 cfy;

// /* nested */ void TryToGo(/*...*/);
// /* nested */ void TryToGo2P(/*...*/);
// /* nested */ bool TryToGo2R(/*...*/);
// /* nested */ void TryToGoM(/*...*/);
// /* nested */ void DoCheck(/*...*/);
// /* nested */ void TryToGo__0(/*...*/);
// /* nested */ void TryToGo2B(/*...*/);
// /* nested */ void TryToGo2P__0(/*...*/);

} // namespace csact

#endif // OPENCHASM_CSACT_H_INCLUDED
