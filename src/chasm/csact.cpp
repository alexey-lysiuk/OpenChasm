
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

#include "csact.h"

namespace csact
{

void MoveOn(/*...*/);
void GetMFloorZ(/*...*/);
bool MS_WallCheck(/*...*/);
bool NotFreeForMonster(/*...*/);
void StartLoading(/*...*/);
void NextLoading(/*...*/);
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
void ReloadResources(/*...*/);
void ScanMap(/*...*/);
void LoadProFile(/*...*/);
void LoadFloorMap(/*...*/);
void LoadLevel(/*...*/);
void SaveGame(/*...*/);
void LoadGame(/*...*/);
void ShootMe(/*...*/);
void SetProcMessage(/*...*/);
void StartProcess(/*...*/);
void AnimateProcesses(/*...*/);
void StartUpProcesses(/*...*/);

TProcess* PProc;
TLinksList__Element* PLinks;
TMessage* PMList;
TChangesList__Element* PChanges;
Sint16 LinksCount;
Sint16 NetOnCount;
Sint16 NetOffCount;
Sint16 ChangesCount;
Sint16 pnum;
Sint16 i;
Sint16 MortalTimer;
bool MortalTick;

Sint16 MulVectors(/*...*/);
Uint8 LocUsed(/*...*/);
Uint8 LocUsedTar(/*...*/);
void GetFloorLoHi(/*...*/);
Uint8 GetFloorZ(/*...*/);
void LoadSpryte(/*...*/);
Uint8 sgn(/*...*/);
void LoadFrame(/*...*/);
void LoadSky(/*...*/);
void SetCDTrack(/*...*/);
void SetDepth(/*...*/);
void ReloadFloors(/*...*/);
void LoadGFXIndex(/*...*/);
void InitZPositions(/*...*/);
void InitChanges(/*...*/);
OCString ReadCommand(/*...*/);
void ReadRealMul(/*...*/);
void LoadLinks(/*...*/);
void LoadTeleports(/*...*/);
void ReadMess(/*...*/);
void LoadMessage(/*...*/);
void LoadAction(/*...*/);
void LoadProcess(/*...*/);
void Stop3d(/*...*/);
void LoadEndCamera(/*...*/);
void InitLevelDefaults(/*...*/);
void ProcessDeathZone(/*...*/);
bool CheckConflict(/*...*/);
bool CheckLifePoint(/*...*/);
bool LifeConflict(/*...*/);
void RemapWall(/*...*/);
void ContinueProcess(/*...*/);

Uint8 BrTab[16];
bool Corrected;
Sint16 cfx;
Sint16 cfy;

// /* nested */ void TryToGo(/*...*/);
// /* nested */ void TryToGo2P(/*...*/);
// /* nested */ bool TryToGo2R(/*...*/);
// /* nested */ void TryToGoM(/*...*/);
// /* nested */ void DoCheck(/*...*/);
// /* nested */ void TryToGo__0(/*...*/);
// /* nested */ void TryToGo2B(/*...*/);
// /* nested */ void TryToGo2P__0(/*...*/);
// /* nested */ void LoadNewSounds(/*...*/);
// /* nested */ void LoadAmbients(/*...*/);
// /* nested */ void UpLoad3dObjects(/*...*/);

} // namespace csact
