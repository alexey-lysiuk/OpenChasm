
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

#ifndef OPENCHASM_CSPUTL_H_INCLUDED
#define OPENCHASM_CSPUTL_H_INCLUDED

namespace CSPUTL
{

struct _DWord
{
    Uint16 LW;
    Uint16 HW;
};

struct PCXHeader
{
    Uint8 PCXId;
    Uint8 VersionNo;
    Uint8 Encoding;
    Uint8 BitsPerPixel;
    Uint16 Xl;
    Uint16 Yl;
    Uint16 Xh;
    Uint16 Yh;
    Uint16 XRes;
    Uint16 YRes;
    Uint8 Palette[48];
    Uint8 Reserved;
    Uint8 NPlanes;
    Uint16 BytesPerLine;
    Uint16 PaletteInfo;
    Uint8 Reserved2[58];
};


bool iswater(/*...*/);
void Bar(/*...*/);
void ShowVesaScreen(/*...*/);
void ShowVESATime(/*...*/);
void ShowVesaConsole(/*...*/);
void ShowScreen(/*...*/);
void UpDateInfo(/*...*/);
void ScrollGun(/*...*/);
void SavePicture(/*...*/);
void SaveMPicture(/*...*/);
void GetJoyStatus(/*...*/);
void CheckJoyStick(/*...*/);
void InitJoyStick(/*...*/);
void GetMouseStatus(/*...*/);
void FillStartInfo(/*...*/);
void InitMessageSystem();
void RemoveLight(/*...*/);
void AddGreatBlow(/*...*/);
void AddSuperGreatBlow(/*...*/);
void ExplodeMine(/*...*/);
void AnimateRespawnObjects(/*...*/);
void AnimateObjects(/*...*/);
void AddRocket(/*...*/);
Sint16 FindVectorFi(/*...*/);
void SendRocketToMe(/*...*/);
void CheckSwitchShoot(/*...*/);
void MakeBlow(/*...*/);
void Blow3dObjAt(/*...*/);
void AnimateBlows(/*...*/);
void ShootMonster(/*...*/);
Uint8 CheckMonsterContact(/*...*/);
void InsertObject(/*...*/);
void InsertMonsters(/*...*/);
void AddHole(/*...*/);
void SendFastRocket(/*...*/);
Uint8 GetBrightAt(/*...*/);
Sint16 GetSmoothBrightAt(/*...*/);
bool PathToMe(/*...*/);
bool LookToMe(/*...*/);
void WeakUpMonstersTo(/*...*/);
void SetWeapon(/*...*/);
void AddAmmoToPlayer(/*...*/);
void CenterView(/*...*/);
void RespawnMonster(/*...*/);
Sint16 MulVectors(/*...*/);
void Movxb(/*...*/);
void MoveDB(/*...*/);
bool Test2Vectors(/*...*/);
void UpDateRanking(/*...*/);
void UpDateIndy(/*...*/);
void PutPlayerInf(/*...*/);
void ShowMessages(/*...*/);
void PutBigChar(/*...*/);
void PutBigString(/*...*/);
void PutLitChar(/*...*/);
void PutLitString(/*...*/);
void PutWLitString(/*...*/);
bool Pr_WallCheck(/*...*/);
Sint16 FindTarget(/*...*/);
void MakeGreatBlow(/*...*/);
void SCalcBPoint(/*...*/);

extern Uint16 CelSaved;

// /* nested */ void InsertByte(/*...*/);
// /* nested */ Uint8 GetB(/*...*/);
// /* nested */ void InsertByte__0(/*...*/);
// /* nested */ Uint8 GetB__0(/*...*/);
// /* nested */ void TryToGo(/*...*/);
// /* nested */ void TryToGo2B(/*...*/);
// /* nested */ Sint16 CalcRZ(/*...*/);

} // namespace CSPUTL

#endif // OPENCHASM_CSPUTL_H_INCLUDED
