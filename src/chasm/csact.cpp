
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

#include "oc/filesystem.h"
#include "oc/utils.h"

#include "cspbio.h"

namespace csact
{

OC::BinaryInputStream& operator>>(OC::BinaryInputStream& stream, TMT& value)
{
    stream >> value.mx;
    stream >> value.my;
    stream >> value.MType;
    stream >> value.FI;
    stream >> value.Mode;

    return stream;
}


// ===========================================================================


void InitModule()
{
    for (size_t i = 0; i < BrTab.size(); ++i)
    {
        BrTab[i] = Uint8(4 + i * 2);
    }

    BrTab.back() = 35;
}

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

    // TODO: remove this
    SDL_Event e; while (1 == SDL_PollEvent(&e)) { }
    // TODO: remove this

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

namespace
{

void LoadNewSounds(OC::TextResource& resource)
{
    for (size_t i = 80; /* EMPTY */; ++i)
    {
        OC::String filename = CSPBIO::ReadFileNameAfterEqual(resource);

        if ("#end" == filename)
        {
            break;
        }
        else
        {
            filename = (OC::Format("level%1$02i/sfx/%2%") % CSPBIO::LevelN % filename).str();
        }

        CSPBIO::LoadSound(filename, i);
    }
}

void LoadAmbients(OC::TextResource& resource)
{
    for (size_t i = 0; /* EMPTY */; ++i)
    {
        OC::String filename = CSPBIO::ReadFileNameAfterEqual(resource);

        if ("#end" == filename)
        {
            break;
        }
        else
        {
            filename = (OC::Format("level%1$02i/amb/%2%") % CSPBIO::LevelN % filename).str();
        }

        CSPBIO::LoadAmb(filename, i);
    }
}

void UpLoad3dObjects(OC::TextResource& resource)
{
    for (size_t i = 32; i < CSPBIO::Obj3DInf.size(); /* EMPTY */)
    {
        while (';' == resource.peek())
        {
            resource.skipLine();
        }

        if ('#' == resource.peek())
        {
            break;
        }

        Load3DObject(resource, CSPBIO::Obj3DInf[i], CSPBIO::LOAD_3D_OBJECT_LEVEL_RESOURCE);

        ++i;
    }

    NextLoading();
}

} // unnamed namespace

void ReloadResources()
{
    const OC::String filename = (OC::Format("level%1$02i/resource.%1$02i") % CSPBIO::LevelN).str();
    OC::TextResource resourceFile(filename);

    for (;;)
    {
        OC::String line = resourceFile.readLine();
        boost::algorithm::trim(line);
        boost::algorithm::to_lower(line);

        ocFS().checkIO(resourceFile);

        if (line.empty() || ';' == line[0])
        {
            continue;
        }
        else if ("#end." == line)
        {
            break;
        }
        else if (line.find("#sky=") != OC::String::npos)
        {
            LoadSky(line);
        }
        else if (line.find("#cdtrack=") != OC::String::npos)
        {
            SetCDTrack(line);
        }
        else if (line.find("#depth=") != OC::String::npos)
        {
            SetDepth(line);
        }
        else if (line.find("#gfx") != OC::String::npos)
        {
            LoadGFXIndex(resourceFile);
        }
        else if (line.find("#newobjects") != OC::String::npos)
        {
            UpLoad3dObjects(resourceFile);
        }
        else if (line.find("#ambients") != OC::String::npos)
        {
            LoadAmbients(resourceFile);
        }
        else if (line.find("#newsounds") != OC::String::npos)
        {
            LoadNewSounds(resourceFile);
        }
    }

    NextLoading();

    for (size_t x = 0; x < 64; ++x)
    {
        for (size_t y = 0; y < 64; ++y)
        {
            const Uint8 sprite = CSPBIO::Map[x * 64 + y].Spr;

            if (sprite > 0 && sprite < 119)
            {
                CSPBIO::SpryteUsed[sprite - 1] = 1;
            }
        }
    }

    NextLoading();

    for (size_t n = 0; n < CSPBIO::SpryteUsed.size() - 1; ++n)
    {
        if (0 == (n % 7))
        {
            NextLoading();
        }

        if (0 == CSPBIO::SpryteUsed[n])
        {
            continue;
        }

        if (n + 1 < 86)
        {
            LoadSpryte(n);
        }
        else
        {
            LoadFrame(n);
        }
    }

    NextLoading();

    // TODO...
}

void ScanMap()
{
    for (size_t x = 0; x < 64; ++x)
    {
        for (size_t y = 0; y < 64; ++y)
        {
            CSPBIO::TLoc& location = CSPBIO::Map[x * 64 + y];

            if (location.Spr >= 1 && location.Spr <= 120)
            {
                location.Dark = BrTab[location.Dark];
            }
            else if (location.Spr >= 131 && location.Spr <= 226)
            {
                if ((0 != CSPBIO::CLIENT && 0 != CSPBIO::SERVER || 0 != location.x2)
                    && !((1 << CSPBIO::Skill) & location.x2))
                {
                    location.Spr = 0;
                }

                location.y2 = location.x2;
                location.x2 = (location.Dark & 7) << 13;
            }
            else if (250 == location.Spr)
            {
                location.Spr = 0;
            }
        }
    }

    NextLoading();

    if (0 == CSPBIO::NetPlace[3].plx)
    {
        OC::DoHalt("No NET Places.");
    }
}

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

    InitLevelDefaults();
    NextLoading();

    const OC::String filename = (OC::Format("level%1$02i/map.%1$02i") % CSPBIO::LevelN).str();
    OC::BinaryResource levelFile(filename);
    NextLoading();

    levelFile.seekg(0x18001);
    levelFile.readArray(CSPBIO::Map);
    NextLoading();

    levelFile.seekg(0x4000, std::ios::cur);
    levelFile >> CSPBIO::LtCount;
    levelFile.readArray(CSPBIO::Lights, CSPBIO::LtCount);
    NextLoading();

    CSPBIO::MCount = 0;
    CSPBIO::SFXSCount = 0;
    CSPBIO::TotalKills = 0;
    CSPBIO::TotalKeys = 0;
    CSPBIO::NetPlace.fill(CSPBIO::NetPlaceElement());
    NextLoading();

    Uint16 m;
    levelFile >> m;
    OC::Clamp(Uint16(0), m, Uint16(87));

    for (Uint16 i = 0; i < m; ++i)
    {
        TMT mt;
        levelFile >> mt;

        if (100 == mt.MType)
        {
            mt.FI = 7 - ((mt.FI + 5) & 7);

            if (mt.Mode < 0 || mt.Mode > 31)
            {
                OC::DoHalt("Wrong monster mode.");
            }

            if (0 == mt.Mode)
            {
                CSPBIO::TPlayerInfo& player = CSPBIO::Players[0];

                player.PlHx = mt.mx;
                player.PlHy = mt.my;
                player.PFlags = 0;
                player.InvTime = 0;
                player.RefTime = 0;
                player.GodTime = 0;
                
                CSPBIO::HFi = Uint16(mt.FI << 13);
            }

            CSPBIO::NetPlaceElement& netPlace = CSPBIO::NetPlace[mt.Mode];

            netPlace.plx = mt.mx;
            netPlace.plx = mt.my;
            netPlace.PFI = Uint16(mt.FI << 13);
        }
        else
        {
            if ((1 << CSPBIO::Skill) & mt.Mode)
            {
                const CSPBIO::TMonsterInfo& monsterInfo = 
                    CSPBIO::MonstersInfo[mt.MType - CSPBIO::FIRST_MONSTER_INDEX];
                CSPBIO::TMonster& monster = CSPBIO::MonstersList[CSPBIO::MCount];

                monster.Mx = mt.mx;
                monster.My = mt.my;
                monster.MType = Uint8(mt.MType);
                monster.Fi = ((mt.FI + 4) & 7) * 128;
                monster.TgFi = monster.Fi;
                monster.DamageMode = 0;

                const Sint16 speed = monsterInfo.Speed;
                monster.Vx = CSPBIO::SinTab[(monster.Fi + 0x100) & 0x3FF] / 32 * speed / 128;
                monster.Vy = CSPBIO::SinTab[monster.Fi] / 32 * speed / 128;

                monster.Target = -1;
                monster.Phase = 2;
                monster.MMode = 0;
                monster.MFlags = 0;
                monster.LifeMeter = monsterInfo.Life;
                monster.WalkCount = 0;
                monster.FTime = 0;
                monster.EVs = 0;
                monster.EvFi = 0;

                ++CSPBIO::MCount;
            }
        }
    }

    OC::FileSystem::instance().checkIO(levelFile);

    if (!CSPBIO::Monsters)
    {
        CSPBIO::MCount = 0;
    }

    NextLoading();

    ScanMap();
    ReloadResources();

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

void LoadSpryte(const size_t index)
{
    const OC::String& gfxName = CSPBIO::GFXindex[index];

    if (gfxName.empty())
    {
        OC::DoHalt(OC::Format("No registered spryte used! %1%") % index);
    }

    const OC::String gfxFileName = (OC::Format("level%1$02i/gfx/%2%") % CSPBIO::LevelN % gfxName).str();
    CSPBIO::PImPtr[index].load(gfxFileName);

    // TODO ...
}

Uint8 sgn(/*...*/);

void LoadFrame(const size_t index)
{
    LoadSpryte(index);

    // TODO ...
}

namespace
{

OC::String ExtractValue(const OC::String& string)
{
    const OC::String::size_type equalPos = string.find('=');
    SDL_assert(OC::String::npos != equalPos);

    OC::String result = string.substr(equalPos + 1);
    boost::algorithm::trim(result);

    return result;
}

} // unnamed namespace

void LoadSky(const OC::String& resourceString)
{
    const OC::String filename = ExtractValue(resourceString);
    CSPBIO::SkyPtr.load(filename);
}

void SetCDTrack(const OC::String& resourceString)
{
    const OC::String track = ExtractValue(resourceString);
    const int trackNum = SDL_atoi(track.c_str());

    CSPBIO::LCDTrack = Sint16(trackNum);
}

void SetDepth(const OC::String& resourceString)
{
    const OC::String depth = ExtractValue(resourceString);
    const int depthNum = SDL_atoi(depth.c_str());

    CSPBIO::BLevelDef = Sint16(depthNum);
}

void ReloadFloors(/*...*/);

void LoadGFXIndex(OC::TextResource& resource)
{
    for (size_t i = 0; i < CSPBIO::WallMask.size(); ++i)
    {
        Uint8& mask = CSPBIO::WallMask[i];
        mask = 7;

        OC::String filename = resource.readLine();
        boost::algorithm::trim(filename);

        if (filename.size() < 5)
        {
            continue;
        }

        // Remove index prefix
        filename = filename.substr(5);

        const OC::String::size_type length = filename.size();
        if (length < 5)
        {
            continue;
        }

        if (SDL_isspace(filename[length - 4]))
        {
            // Parse flags

            const OC::String::value_type oChar = filename[length - 1];
            SDL_assert('o' == oChar || '.' == oChar);

            if ('o' == oChar)
            {
                mask -= 4;
            }

            const OC::String::value_type sChar = filename[length - 2];
            SDL_assert('s' == sChar || '.' == sChar);

            if ('s' == sChar)
            {
                mask -= 2;
            }

            const OC::String::value_type gChar = filename[length - 3];
            SDL_assert('g' == gChar || '.' == gChar);

            if ('g' == gChar)
            {
                mask -= 1;
            }

            filename.erase(length - 3);
            boost::algorithm::trim(filename);
        }

        CSPBIO::GFXindex[i] = filename;
    }

    CSPBIO::WallMask.back() = 3;
}

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

boost::array<Uint8, 16> BrTab;
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

} // namespace csact
