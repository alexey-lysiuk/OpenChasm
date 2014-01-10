
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

#include "csact.h"

#include "cspbio.h"

namespace csact
{

void MoveOn(/*...*/);
void GetMFloorZ(/*...*/);
bool MS_WallCheck(/*...*/);
bool NotFreeForMonster(/*...*/);

void StartLoading()
{
    if (99 == CSPBIO::LevelN)
    {
        return;
    }

    CSPBIO::LoadPos = 2;

    //OC::Renderer::instance().draw(CSPBIO::VesaTiler, 400, 20);
    //OC::Renderer::instance().draw(CSPBIO::Status, 20, 20);

    const int x = (OC::Renderer::instance().screenWidth() - CSPBIO::Loading.width()) / 2;
    const int y = OC::Renderer::instance().screenHeight() / 2 - 40;
    const OC::Rect clipRect(-1, -1, -1, CSPBIO::Loading.height() / 2);

    OC::Renderer::instance().draw(CSPBIO::Loading, x, y, clipRect);
    OC::Renderer::instance().present();
}

void NextLoading()
{
    if (0 == CSPBIO::LoadPos)
    {
        return;
    }

    CSPBIO::LoadPos += 4;
    CSPBIO::LoadPos = std::min(CSPBIO::LoadPos, Uint16(150));
    
    const int x = (OC::Renderer::instance().screenWidth() - CSPBIO::Loading.width()) / 2;
    const int y = OC::Renderer::instance().screenHeight() / 2 - 40;
    const int w = CSPBIO::LoadPos * CSPBIO::Loading.width() / 150;
    const OC::Rect clipRect(-1, CSPBIO::Loading.height() / 2, w, CSPBIO::Loading.height() / 2);

    OC::Renderer::instance().draw(CSPBIO::Loading, x, y, clipRect);
    OC::Renderer::instance().present();
}

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

void LoadLevel()
{
    StartLoading();

    CSPBIO::FullMap = 0;
    CSPBIO::takt = 0;
    CSPBIO::MsTakt = 0;
    CSPBIO::LCDTrack = 0;
    CSPBIO::BLevelDef = 320;
    CSPBIO::FirstTakt = 1;
    CSPBIO::LastBorn = 0;

    NextLoading();

    //for (int i = 0; i < 38; ++i)
    //{
    //    SDL_Delay(100);
    //    NextLoading();
    //}

    InitLevelDefaults();

    NextLoading();

    // TODO...
}

void SaveGame(/*...*/);
void LoadGame(/*...*/);
void ShootMe(/*...*/);
void SetProcMessage(/*...*/);
void StartProcess(/*...*/);
void AnimateProcesses(/*...*/);
void StartUpProcesses(/*...*/);

std::vector<TProcess> PProc;
std::vector<TLinksList__Element> PLinks;
std::vector<TMessage> PMList;
std::vector<TChangesList__Element> PChanges;
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

void InitLevelDefaults()
{
    CSPBIO::t1 = 4;
    CSPBIO::GunShift = 64;
    CSPBIO::ShakeLevel = 0;
    CSPBIO::LookVz = 0;
    CSPBIO::WXSize = 64;
    CSPBIO::MapMode = 0;

    CSPBIO::LastPainTime = 0;
    CSPBIO::Time = 0;

    CSPBIO::RCount = 0;
    CSPBIO::BCount = 0;
    CSPBIO::ExMode = 0;
    CSPBIO::TCount = 0;
    CSPBIO::LCount = 0;
    CSPBIO::SCount = 0;
    CSPBIO::MnCount = 0;
    CSPBIO::DCount = 0;
    CSPBIO::ReCount = 0;
    CSPBIO::AmCount = 0;
    CSPBIO::HolCount = 0;

    CSPBIO::TeleMap.fill(0xFF);
    CSPBIO::Lights.fill(CSPBIO::TLight());
    CSPBIO::Tports.fill(CSPBIO::Teleport());
    CSPBIO::VMask.fill(0);
    CSPBIO::Flags.fill(0);
    CSPBIO::LevelChanges.fill(0); // [0..7] were cleared originally
    CSPBIO::ProcState.fill(0);
    CSPBIO::EventsList.fill(CSPBIO::TEvent());
}

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
