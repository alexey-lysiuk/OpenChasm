
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

#ifndef OPENCHASM_CSPBIO_H_INCLUDED
#define OPENCHASM_CSPBIO_H_INCLUDED

#include "oc/graphics.h"

namespace OC
{
    class BinaryInputStream;
    class TextResource;
}

namespace CSPBIO
{

// IMPORTANT NOTE!
// Comments like
//   [!] Uint8 originally
// indicate that these types were altered because of C++ type system issue:
// types Sint8/Uint8 and signed/unsigned char are the same.
// So istream::operator>>() treats Sint8/Uint8 variable as character
// instead of integer.
// TODO: consider better solution: union or template wrapper?

struct TFace
{
    Uint16 V1;
    Uint16 V2;
    Uint16 V3;
    Uint16 V4;

    Uint16 TAx;
    Uint16 TAy;
    Uint16 TBx;
    Uint16 TBy;
    Uint16 TCx;
    Uint16 TCy;
    Uint16 TDx;
    Uint16 TDy;

    Sint16 Next;
    Sint16 Distant;

    Uint8  TNum;
    Uint8  Flags;

    Uint16 SprOFs;

    TFace();

    void load(OC::BinaryInputStream& stream);
};

struct TPoint3di
{
    Sint16 X;
    Sint16 Y;
    Sint16 Z;

    TPoint3di(const Sint16 x = 0, const Sint16 y = 0, const Sint16 z = 0)
    : X(x), Y(y), Z(z) { }

    void load(OC::BinaryInputStream& stream);
};

typedef std::vector<TPoint3di> Point3DList;

struct TPoint2D
{
    Sint16 sX;
    Sint16 sY;

    explicit TPoint2D(const Sint16 sx = 0, const Sint16 sy = 0)
    : sX(sx), sY(sy) { }

    void load(OC::BinaryInputStream& stream);
};

struct TOHeader
{
    boost::array<TFace,     400> Faces;

    boost::array<TPoint3di, 256> OVert;
    boost::array<TPoint3di, 256> RVert;
    boost::array<TPoint3di, 256> ShVert;
    boost::array<TPoint2D,  256> ScVert;

    Uint16 VCount;
    Uint16 FCount;
    
    Uint16 TH;
    std::vector<Uint8> TPtr;

    TOHeader();

    void load(const OC::Path& filename);
    void load(OC::BinaryInputStream& stream);
};

struct TSepPartInfo
{
    Uint16 ATimeA;
    Uint16 ATimeB;

    Uint16 FallSound;

    TOHeader POH;

    Point3DList PAniA;
    Point3DList PAniB;

    TSepPartInfo();
};

struct TAmmoBag
{
    Sint16 ox;
    Sint16 oy;
    Sint16 oz;
    Sint16 vz;
    Sint16 ambLandZ;
    Uint16 TimesLeft;
    Uint16 AFi;
    Uint16 DPFlags;
    Uint8 DWFlags;
    Uint8 dammo[8];
    Sint16 Invis;
    Sint16 DLife;
    Sint16 DArmor;
};

struct TPlayerInfo
{
    OC::String PName;
    Sint16 PlHx;
    Sint16 PlHy;
    Sint16 Plhz0;
    Sint16 PlLz;
    Sint16 v;
    Sint16 sv;
    Sint16 rv;
    Sint16 vz;
    Sint16 ev;
    Sint16 evfi;
    Uint16 PlFi;
    Uint16 ksFlags;
    Uint16 FTime;
    Uint8 Phase;
    Uint8 WFlags;
    Uint8 Frags;
    Uint8 Armor;
    Sint16 Life;
    Uint16 PFlags;
    Uint16 PlayerID;
    Uint8 Ammo[8];
    bool Active;
    Uint16 PColor;
    Sint16 PliCa;
    Sint16 PliSa;
    Sint16 Plhz;
    Sint16 PlRz;
    Sint16 ms_dvx;
    Sint16 ms_dvy;
    Sint16 PTime;
    Sint16 PlColorN;
    Sint16 PlCurGun;
    Sint16 PlRepairTime;
    Sint16 ReDelay;
    Sint16 InvTime;
    Sint16 GodTime;
    Sint16 RefTime;
    Sint32 LastTime;

    TPlayerInfo();
};

struct XRPointer
{
    void* XPtr;
    Uint16 RSeg;
    Uint16 ROFs;
};

struct TFrame
{
    Sint16 ox1;
    Sint16 oy1;
    Sint16 ox2;
    Sint16 oy2;
    Sint16 Distant;
    Uint8 OSpr;
    Uint8 OXX;
    Uint8 OYY;
    Uint8 Flags;
};

struct TBlow
{
    Sint16 CurFrame;
    Sint16 BType;
    Sint16 __BX;
    Sint16 BY;
    Sint16 BZ;
    Sint16 BVX;
    Sint16 BVY;
    Sint16 BVZ;
};

struct LongRec
{
    Uint16 LowWord;
    Uint16 HighWord;
};

struct NetPlaceElement
{
    Sint16 plx;
    Sint16 ply;
    Uint16 PFI;

    NetPlaceElement();
};

struct TLight
{
    Sint16 lx;
    Sint16 ly;
    Sint16 L;
    Sint16 R0;
    Sint16 R1;
    Sint16 MaxB;

    TLight();
};

OC::BinaryInputStream& operator>>(OC::BinaryInputStream& stream, TLight& value);

struct TEvent
{
    char C;
    Uint8 info;
    Sint16 param;
    Sint16 CX;
    Sint16 CY;
    Sint16 CZ;

    TEvent();
};

struct TObj3DInfo
{
    Sint16 GoRad;
    Sint16 ACode;
    Sint16 ShadowOn;

    Sint16 BMPObj;
    Sint16 BMPz;

    Sint16 BlowUp;
    Sint16 BlowLimit;

    Sint16 SFXid;
    Sint16 BSFXid;
    
    Sint16 LoZ;
    Sint16 HiZ;

    bool Animated;
    bool Morphed;

    Uint16 FTime;
    Uint16 ATime;

    TOHeader POH;

    Point3DList PAni;

    TObj3DInfo();
};

struct TPicPack
{
    Uint16 NFrames;
    boost::array<Uint16, 24> FrameOfs;

    std::vector<Uint8> PData;

    TPicPack();
};

struct TLoc
{
    Uint8 Spr;
    Uint8 Size;
    Uint8 Dark;
    Sint16 x1;
    Sint16 y1;
    Sint16 x2;
    Sint16 y2;

    TLoc();
};

OC::BinaryInputStream& operator>>(OC::BinaryInputStream& stream, TLoc& value);

struct TObjBMPInfo
{
    Sint16 Oz;
    Uint8 bmpFlags;

    Uint8 Frames;
    Uint8 CurFrame;

    boost::array<OC::Bitmap, 16> Pics;

    TObjBMPInfo();
};

struct FIB
{
    Uint16 Handle;
    Uint16 Mode;
    Uint16 BufSize;
    Uint16 Private;
    Uint16 BufPos;
    Uint16 BufEnd;
    Uint8* BufPtr;
    void* OpenProc;
    void* InOutProc;
    void* FlushProc;
    void* CloseProc;
    Uint8 UserData[16];
    char Name[80];
    char Buffer[128];
};

struct TLinesBuf
{
    boost::array<Uint16, 1024> LinesS;
    boost::array<Uint16, 1024> LinesO;
    boost::array<Uint16, 1024> LinesFH1;
    boost::array<Uint16, 1024> LinesFH2;
    boost::array<Uint8,  1024> LinesB;
};

struct MessageRec__Element
{
    OC::String::value_type Line[61];
    Uint16 LTime;
};

typedef Sint32 DWord;

struct TRocket
{
    DWord RX;
    DWord RY;
    Sint16 Rz;
    Uint16 RFi;
    Uint8 RType;
    Uint8 FTime;
    Sint16 vx;
    Sint16 vy;
    Sint16 vz;
    Sint16 Target;
    Sint16 Owner;
};

struct TInfo_Struct
{
    Uint16 CardId[3];
    Uint16 MachineMode;
    Uint16 SelfID;
    TEvent Events[32];
    bool SendComplette;
    bool IPXpresent;
    Uint16 Card;
    Uint16 Baud;
    Uint16 Port;
    Sint32 OwnerTime;
    OC::String::value_type InfoMessage[41];
    Uint16 NetError;
    Uint16 MSCDEXVersion;
    Uint8 CDinfo;
    Sint32 CDTime;
    Uint16 MouseX;
    Uint16 MouseY;
    Uint16 MButtons;
};

struct TMovingRecord
{
    Sint16 WMDx;
    Sint16 WMDy;
    Sint16 WMx;
    Sint16 WMy;
    Uint8 Spd;
    char mode;
};

struct TReObject
{
    Sint16 Ox;
    Sint16 Oy;
    Sint16 Oc;
    Sint32 ReTime;
};

struct _DWord
{
    Sint16 LW;
    Sint16 HW;
};

struct TMonsterInfo
{
    OC::String CarName;

    Sint16 PhaseTime;
    Sint16 Speed;
    Sint16 RSpeed;
    Sint16 Life;
    Sint16 Radius;
    Sint16 CRad;
    Sint16 MHeight;
    Sint16 MWidth;
    Sint16 Z0;
    Sint16 KickPower;
    Sint16 Rocket;
    Sint16 SepLimit;
    Uint16 PTimes[20];
    
    TOHeader* POH;
    TPoint3di* Phases[20];

    bool Present;
};

struct TSepPart
{
    Sint16 FTime;
    Sint16 WTime;
    Sint16 PType;
    Uint8 SMode;
    Uint8 PColor;
    Sint16 prx;
    Sint16 pry;
    Sint16 prz;
    Sint16 prvx;
    Sint16 prvy;
    Sint16 prvz;
    Uint16 SFI;
};

struct TMonster
{
    Sint16 Mx;
    Sint16 My;
    Sint16 Fi;
    Sint16 FTime;
    Sint16 Phase;
    Uint8 MType;
    Uint8 DamageMode;
    Sint16 TgFi;
    Sint16 Vx;
    Sint16 Vy;
    Sint16 LifeMeter;
    Sint16 Target;
    Sint16 LPx;
    Sint16 LPy;
    Sint16 EvFi;
    Sint16 EVs;
    Sint16 mz;
    Sint16 mz0;
    Sint16 SleepCount;
    Uint8 WalkCount;
    bool LFollow;
    Uint8 MMode;
    Uint8 MFlags;
};

struct TModeItem
{
    Uint16 ModeNumber;
    Uint16 XRes;
    Uint16 YRes;
    Uint16 BPLine;
    Sint32 VMSize;
    bool Flat;
};

struct VideoPos__Element
{
    Sint16 X;
    Sint16 Y;
};

struct TGunInfo
{
    Sint16 RockType;
    Sint16 RZ0;

    Sint16 DAmmo;
    Sint16 AmmoLimit;

    Sint16 StartCount;
    Sint16 RcCount;
    Sint16 GunYShift;

    Sint16 RepairTime;
    Uint16 PATime;
    Uint16 PSTime;

    TOHeader POH;

    Point3DList PAStat;
    Point3DList PAAttack;

    TGunInfo();
};

struct THoleItem
{
    Sint16 hlx;
    Sint16 hly;
    Sint16 Hlz;
    Uint16 HoleFi;
    Uint16 RMode;
    Sint16 wmx;
    Sint16 wmy;
    OC::Real wl;
};

struct Teleport
{
    Sint16 TSrx;
    Sint16 TSry;
    Sint16 TDstx;
    Sint16 TDsty;
    Sint16 TFi;

    Teleport();
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

struct VgaInfoBlock
{
    Sint32 VESASignature;
    Uint16 VESAVersion;
    void* OEMStringPtr;
    Sint32 Capabilities;
    void* VideoModePtr;
    Uint16 TotalMemory;
    Uint8 Reserved[492];
};

struct TBlowInfo
{
    enum FlagType
    {
        FLAG_SMOOKING  = 0x01,
        FLAG_LOOPED    = 0x02,
        FLAG_GRAVITY   = 0x04,
        FLAG_JUMP      = 0x08,
        FLAG_HALF_SIZE = 0x10,
        FLAG_LIGHT_ON  = 0x20
    };

    Uint16 NFrames;

    Uint8 Flags;
    Uint16 GlassMode; // [!] Uint8 originally

    TPicPack Frames;

    TBlowInfo();
};

struct ModesList__Type
{
    Uint16 MDCount;
    TModeItem ModeInfo[16];
};

struct ProcMessage__Type
{
    Sint16 MessNum;
    Sint16 LTime;
};

struct TMine
{
    Sint16 mnx;
    Sint16 mny;
    Sint16 mntime;
    Sint16 mnz;
    Sint16 MOwner;
};

struct ModeInfoBlock
{
    Uint16 ModeAtt;
    Uint8 WinAAtr;
    Uint8 WinBAtr;
    Uint16 WinGranularity;
    Uint16 WinSize;
    Uint16 WinASeg;
    Uint16 WinBSeg;
    void* WinFunc;
    Uint16 BytesPerLine;
    Uint16 XRes;
    Uint16 YRes;
    Uint8 XCharSize;
    Uint8 YCharSize;
    Uint8 NOfPlanes;
    Uint8 BitsPerPix;
    Uint8 NOfBunks;
    Uint8 MemoryModel;
    Uint8 BankSize;
    Uint8 NOfIP;
    Uint8 Reserv;
    Uint8 RM;
    Uint8 RP;
    Uint8 GM;
    Uint8 GP;
    Uint8 Bm;
    Uint8 __Bp;
    Uint8 Rsm;
    Uint8 Rsp;
    Uint8 DirColorI;
    Sint32 PhysBasePtr;
    Sint32 OffScreenMemOffset;
    Sint32 OffScreenMemSize;
    Uint8 Reserved[206];
};

struct TScrollRec
{
    Uint16 SOY;
    Uint16 SOX;
    Uint16 SprTakt;
};

struct A__Type
{
    Sint16 Y;
    Sint16 SpX;
    Sint16 SpY;
};

struct PLine
{
    A__Type A;
    A__Type B;
};

struct TRotationRecord
{
    Sint16 WMX;
    Sint16 WMY;
    Sint16 OX1;
    Sint16 OX2;
    Sint16 OY1;
    Sint16 OY2;
    Sint16 BSx;
    Sint16 BSy;
    Sint16 DFi;
    Sint16 FiMax;
    Sint16 Spd;
};

struct TBlowLight
{
    Sint16 LX;
    Sint16 LY;
    Sint16 Rds;
    Sint16 Pwr;
    Sint16 CurRds;
    Sint16 CurLight;
    Uint16 TTime;
    Uint16 CTime;
    Uint16 Direct;
};

struct EndCamera__Type
{
    Uint16 __cx;
    Uint16 cy;
    Uint16 cz;
    Uint16 cfi;
    Sint16 __cl;
};

struct TRocketInfo
{
    enum FlagType
    {
        FLAG_FAST        = 0x01,
        FLAG_FULL_BRIGHT = 0x02,
        FLAG_LIGHT       = 0x04,
        FLAG_AUTO        = 0x08,
        FLAG_AUTO_2      = 0x10,
        FLAG_REFLECTION  = 0x20,
    };

    Sint16 BlowType;
    Sint16 GForce;
    Sint16 ActionR;
    Sint16 CheckR;
    Sint16 Power;
    Uint8 rFlags;
    Uint8 SmokeID;
    Uint16 ATime;

    TOHeader POH;

    Point3DList PAni;

    TRocketInfo();
};

struct ServerSaved__Type
{
    Sint16 VMode;
    Sint16 svhx;
    Sint16 svhy;
    Sint16 svhz;
};


void InitModule();

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
void ReDrawGround();

Uint16 QPifagorA32(/*...*/);
void getmousestate(/*...*/);
Sint16 GetJoyX(/*...*/);
Sint16 GetJoyY(/*...*/);
void StosW(/*...*/);
void StosEW(/*...*/);
void movsw(/*...*/);
bool ExistFile(/*...*/);
void movsD(/*...*/);
void settimer(/*...*/);
void Beep(/*...*/);
bool FExistFile(/*...*/);
void FadeOut(/*...*/);
void FadeIn(/*...*/);

void CalcDir(/*...*/);
Sint16 Max(/*...*/);
Sint16 Min(/*...*/);
Sint8 Sgn(/*...*/);
void SetCurPicTo(/*...*/);
void LoadAnimation(const OC::String& filename, const Uint16 modelVertexCount, Point3DList& vertices, Uint16& time);
void LoadPOH(const OC::String& filename, TOHeader& model);
void ScanLoHi(Sint16& loZ, Sint16& hiZ, const TOHeader& model);
void ScanLowHigh(/*...*/);
void InitCaracter(const size_t monsterNumber);
void UpLoadCaracter(/*...*/);
void ReleaseCaracter(/*...*/);
void LoadSound(const OC::String& filename, const size_t index);
void LoadAmb(const OC::String& filename, const size_t index);
void AllocVideo(/*...*/);
void AllocMemory(/*...*/);
void LoadCommonParts();
void CheckMouse(/*...*/);
void RemoveEqual(OC::String& string);
void ScanLevels(/*...*/);
void FindNextLevel(/*...*/);
void LoadGraphics();
void LoadGround();
void AddEvent(/*...*/);
void AddEvVoice(/*...*/);
void Hline(/*...*/);
void Vline(/*...*/);
void HBrline(/*...*/);
void VBrline(/*...*/);
void DrawKey(/*...*/);
void DrawBrKey(/*...*/);
void BrightBar(/*...*/);
void ShowMap(/*...*/);
Uint16 CalcStringLen(const OC::String& string);
void ReInitViewConst(/*...*/);
void AddBlowLight(/*...*/);
void _AddBlowLight(/*...*/);
void AddBlow(/*...*/);
void BlowSpark(/*...*/);
void BlowSmoke(/*...*/);
void BlowShootSmoke(/*...*/);

void PutConsMessage(const OC::String& message);
void PutConsMessage2(const OC::String& message);
void PutConsMessage3(const OC::String& message);

extern Uint16 ServerVersion;
extern Sint32 Long1;
extern Uint8 LB;
extern OC::String::value_type ConsoleCommands[546];
extern OC::String::value_type ncNames[24];
extern Sint16 ncSDivs[5];
extern Sint16 ncYDelta[3];
extern VideoPos__Element VideoPos[4];
extern Uint8 ReColorShift[8];
extern OC::String::value_type OnOff[10];
extern Sint16 Fr;
extern Sint16 Fr2;
extern Sint16 Frr;
extern void* ShadowMap;
extern void* WShadowMap;
extern void* ShadowMap2;
extern void* WShadowMap2;
extern Uint16 FlSegs[256];
extern OC::Bitmap Pc;
extern OC::Bitmap CurPic;
extern Uint16 CurPicSeg;
extern Uint16 ShadowSeg;
extern Uint16 WShadowSeg;
extern Uint16 ShadowSeg2;
extern Uint16 WShadowSeg2;
extern Uint16 cwc;
extern Uint16 CurShOfs;
extern Uint16 CMP0;
extern Uint16 XORMask;
extern boost::array<OC::String, 128> GFXindex;
extern boost::array<OC::String, 64> ShortNames;
extern boost::array<OC::String, 64> LevelNames;
extern OC::Bitmap ColorMap;
extern Uint8 FloorMap[4096];
extern Uint8 CellMap[4096];
extern Uint8* AltXTab;
extern boost::array<TLight, 256> Lights;
extern boost::array<Teleport, 128> Tports;
extern boost::array<OC::Bitmap, 120> PImPtr;
extern boost::array<Uint8, 120> WallMask;
extern boost::array<TObjBMPInfo, 4> ObjBMPInf;
extern boost::array<TObj3DInfo, 96> Obj3DInf;
extern Uint16 LinesH1[847];
extern Uint16 LinesH2[847];
extern TLinesBuf LinesBUF;
extern THoleItem* HolesList;
extern boost::array<Uint8, 120> SpryteUsed;
extern boost::array<Uint16, 201> Mul320;
extern boost::array<Sint32, 701> MulSW;
extern boost::array<Sint16, 1024> SinTab;
extern boost::array<TLoc, 4096> Map;
extern std::list<OC::String> ConsHistory;
extern boost::array<Uint8, 4096> VMask;
extern boost::array<Uint8, 4096> Flags;
extern Uint8* DarkMap;
extern Uint8* AmbMap;
extern boost::array<Uint8, 4096> TeleMap;
extern Uint8* FloorZHi;
extern Uint8* FloorZLo;
extern EndCamera__Type EndCamera;
extern boost::array<TEvent, 16> EventsList;
extern TFrame* FramesList;
extern TBlow* BlowsList;
extern TMonster MonstersList[90];
extern TRocket RocketList[64];
extern TSepPart SepList[32];
extern TMine MinesList[16];
extern TBlowLight BlowLights[32];

// Monster numbers are 100..122
static const size_t FIRST_MONSTER_INDEX = 100;

extern boost::array<TMonsterInfo, 23> MonstersInfo;

extern boost::array<TRocketInfo, 32> RocketsInfo;
extern boost::array<TSepPartInfo, 90> SepPartInfo;
extern boost::array<TBlowInfo, 24> BlowsInfo;
extern std::vector<TReObject> ReObjects;
extern std::vector<TAmmoBag> AmmoBags;
extern bool FFlags[64];

extern OC::Bitmap Fonts;
extern OC::Bitmap BigFont;
extern OC::Bitmap LitFont;
extern OC::Bitmap WIcons;

extern boost::array<Uint16, 256> CharSize;
extern boost::array<TGunInfo, 9> GunsInfo;
extern boost::array<NetPlaceElement, 32> NetPlace;
extern void* VGA;

extern OC::Bitmap Ground;
extern OC::Bitmap Status;
extern OC::Bitmap Loading;
extern OC::Bitmap VesaTiler;
extern OC::Bitmap SkyPtr;

typedef boost::array<Uint8, 0x10000> RGBTable;
extern RGBTable RGBTab25;
extern RGBTable RGBTab60;

extern Uint16 LoadPos;
extern OC::Real ca;
extern OC::Real sa;
extern Sint16 RShadeDir;
extern Sint16 RShadeLev;
extern Sint16 LastRShadeLev;
extern Sint16 BShadeDir;
extern Sint16 BShadeLev;
extern Sint16 LastBShadeLev;
extern Sint16 GShadeDir;
extern Sint16 GShadeLev;
extern Sint16 LastGShadeLev;
extern Uint16 MenuCode;
extern Uint16 CSCopy;
extern Uint16 LoadSaveY;
extern Uint16 OptionsY;
extern Uint8 NetMode;
extern Uint8 TeamMode;
extern Uint8 SHRC;
extern TMonster Ms;
extern Sint16 Skill;
extern Sint16 MyNetN;
extern Sint16 bpx;
extern Sint16 bpy;
extern OC::Bitmap ConsolePtr;

typedef std::list<OC::String> ConsoleText;
extern ConsoleText ConsoleComm;

extern Sint16 ConsY;
extern Sint16 ConsDY;
extern Sint16 ConsMode;
extern Sint16 ConsMainY;
extern Sint16 ConsMenu;
extern Sint16 HistCnt;
extern Sint16 CurHist;
extern Sint16 MenuMode;
extern Sint16 MenuMainY;
extern Uint8 MSsens;
extern Sint16 DisplaySett[3];
extern Sint16 LandZ;
extern Sint16 CeilZ;
extern Sint16 EndDelay;
extern Uint16 Hz;
extern Uint16 Hz2;
extern Uint16 DMax;
extern Uint16 Dy;
extern Uint16 DDY;
extern Uint16 oldy;
extern Uint16 _x1;
extern Uint16 _x2;
extern Uint16 _X;
extern Uint16 sl;
extern Uint16 slp;
extern Uint16 t1;
extern Uint16 Times10Sum;
extern Uint16 _Times10Sum;
extern Uint16 Frames10Count;
extern Uint16 CurTime;
extern Uint16 LastGunNumber;
extern Uint16 GunShift;
extern Uint16 RespawnTime;
extern Uint16 ys31;
extern Uint16 ys32;
extern Uint16 ys11;
extern Uint16 ys12;
extern Uint16 ys21;
extern Uint16 ys22;
extern Uint16 sh1;
extern Uint16 sh2;
extern Uint16 mysy;
extern Uint16 ObjectsLoaded;
extern Uint16 WeaponsCount;
extern Uint16 MCount;
extern Uint16 TotalKills;
extern Uint16 TotalKeys;
extern Uint16 RCount;
extern Uint16 BCount;
extern Uint16 DCount;
extern Uint16 FCount;
extern Uint16 LCount;
extern Uint16 LtCount;
extern Uint16 SCount;
extern Uint16 TCount;
extern Uint16 MnCount;
extern Uint16 AmCount;
extern Uint16 ReCount;
extern Uint16 HolCount;
extern Uint16 SFXSCount;
extern Uint16 InfoLen;
extern Uint16 Di0;
extern Uint16 Dx0;
extern Uint16 Recsize;
extern Uint16 MTime;
extern Uint16 WeaponFTime;
extern Uint16 WeaponPhase;
extern Uint16 j;
extern Uint16 w;
extern Uint16 BLevelDef;
extern Uint16 BLevel0;
extern Uint16 BLevelW;
extern Uint16 BlevelC;
extern Uint16 BLevelF;
extern Uint16 VgaSeg;
extern Uint16 RGBSeg;
extern Uint16 PSeg;
extern Uint16 POfs;
extern Uint16 PImBSeg;
extern Uint16 ImSeg;
extern Uint16 ImOfs;
extern Uint16 Ims;
extern Uint16 ImSegS;
extern Uint16 MyDeath;
extern Uint16 ObjectX;
extern Uint16 ObjectY;
extern Uint16 ObjSeg;
extern Uint16 HlBr;
extern Uint16 HLxx;
extern Uint16 HLh1;
extern Uint16 Hlh2;
extern Uint16 Hlhr1;
extern Uint16 Hlhr2;
extern Uint16 HLRH;
extern Uint16 HLFh;
extern Uint16 YMin1;
extern Uint16 YMin2;
extern Uint16 Nlines;
extern Uint16 NLines1;
extern Uint16 takt;
extern Uint16 MsTakt;
extern Uint16 b0;
extern Uint16 b1;
extern bool WeaponActive;
extern Sint32 CellV;
extern Sint32 FloorV;
extern Sint32 HLSt;
extern Sint16 WXSize;
extern Sint16 isa;
extern Sint16 ica;
extern Sint16 ica2;
extern Sint16 isa2;
extern Sint16 isa4;
extern Sint16 ica4;
extern Sint16 SxS;
extern Sint16 Sx11;
extern Sint16 Sx21;
extern Sint16 Sx1;
extern Sint16 Sx2;
extern Sint16 DShift;
extern Sint16 Dir;
extern Sint16 WpnShx;
extern Sint16 WpnShy;
extern Sint16 lvz;
extern Sint16 hvz;
extern Sint16 GunDx;
extern Sint16 GunDy;
extern Sint16 ShakeLevel;
extern Sint16 LookVz;
extern Sint16 _LookVz;
extern Sint16 v1x;
extern Sint16 v1y;
extern Sint16 v2x;
extern Sint16 v2y;
extern Sint16 nx;
extern Sint16 ny;
extern Sint16 HS;
extern Sint16 Hx;
extern Sint16 Hy;
extern Sint16 HMx;
extern Sint16 HMy;
extern Sint16 ehx;
extern Sint16 ehy;
extern Sint16 ehz;
extern Sint16 mi;
extern Sint16 MapR;
extern Sint16 LevelN;
extern Sint16 ox;
extern Sint16 HRv;
extern Uint16 HksFlags;
extern Uint16 HFi;
extern Uint16 EHFi;
extern bool FirstTakt;
extern bool InfoPage;
extern bool NextL;
extern bool SERVER;
extern bool CLIENT;
extern bool Paused;
extern bool Monsters;
extern bool Animation;
extern bool TimeInd;
extern bool FullMap;
extern bool EndOfTheGame;
extern bool ClipMode;
extern bool IamDead;
extern bool Slow;
extern bool Spline;
extern bool Ranking;
extern bool NewSecond;
extern bool OAnimate;
extern bool MapMode;
extern bool ExMode;
extern bool Chojin;
extern bool TabMode;
extern bool SafeLoad;
extern bool EpisodeReset;
extern bool AlwaysRun;
extern bool ReverseMouse;
extern bool SkyVisible;
extern bool MenuOn;
extern bool Console;
extern bool Cocpit;
extern bool GameActive;
extern Uint8 SecCounter;
extern void (*TimerInt)();
extern void (*KbdInt)();
extern Sint32 EDI0;
extern Sint32 Edi1;
extern Sint32 mEDX;
extern Sint32 Ll;
extern Sint32 Time0;
extern Sint32 Time;
extern Sint32 ZTime;
extern Sint32 k;
extern Sint32 RealTime;
extern Sint32 LastMouseTime;
extern Sint32 LastPainTime;
extern Sint32 StartUpRandSeed;
extern Sint32 MSRND;
extern TLoc L;
extern bool VideoIsFlat;
extern Uint16 WinW;
extern Uint16 WinW2;
extern Uint16 WinSX;
extern Uint16 WinEX;
extern Uint16 WinSY;
extern Uint16 WinEY;
extern Uint16 WinH;
extern Uint16 WinH2u;
extern Uint16 WinH2d;
extern Uint16 WinCY;
extern Uint16 WallH;
extern Uint16 WallW;
extern Uint16 ObjectW;
extern Uint16 WinB;
extern Uint16 WinB3;
extern Uint16 WinE;
extern Uint16 WinE3;
extern Sint16 WMapX1;
extern Sint16 WMapX2;
extern Sint16 WMapY1;
extern Sint16 WMapY2;
extern Sint16 WMapX;
extern Sint16 WMapY;
extern Sint16 mpk_x;
extern Sint16 mpk_y;
extern Sint16 mps;
extern Sint16 WinW2i;
extern Sint16 StepMove;
extern Sint16 FLeftEnd;
extern Sint16 FRightEnd;
extern Sint16 CLeftEnd;
extern Sint16 CRightEnd;
extern Sint16 FLE160;
extern Sint16 DNpy;
extern Sint16 DNpx;
extern Sint16 FMapDx;
extern Sint16 FMapDy;
extern Sint16 FShwDx;
extern Sint16 FShwDy;
extern Uint16 HXiFF;
extern Uint16 FloorW;
extern Uint16 FloorDiv;
extern Uint16 TMy;
extern Uint16 DNp;
extern Uint16 FCurMapOfs;
extern Uint16 FMx;
extern Uint16 FMy;
extern Sint32 Esl;
extern Sint32 Io0;
extern Sint32 SlY2;
extern Sint32 SLy;
extern Sint16 tx1;
extern Sint16 tx2;
extern Sint16 ty1;
extern Sint16 ty2;
extern Sint16 _ty1;
extern Sint16 DDark;
extern Uint16 WShadowOfs;
extern Uint16 CMPOfs;
extern Uint16 XOfsMask;
extern Uint16 Cnt;
extern Uint16 FromOfs;
extern Uint16 FullH;
extern Uint16 yf0;
extern Uint16 yf1;
extern Uint16 yf2;
extern Uint16 ScrollK;
extern Uint8 Double;
extern Sint16 RSize;
extern Sint16 rrx;
extern Sint16 rry;
extern Sint16 nhxi;
extern Sint16 nhyi;
extern Sint16 aLwx;
extern Sint16 aLWy;
extern Sint16 DSh;
extern Sint16 LWx;
extern Sint16 LWy;
extern Sint16 Rx;
extern Sint16 Ry;
extern Sint16 R;
extern bool KeysState[128];
extern Uint8 KBDBuf[16];
extern Uint16 KBDBufCnt;
extern Uint8 KeysID[16];
extern Uint8 _FrontOn;
extern Uint8 _BackOn;
extern Uint8 _LeftOn;
extern Uint8 _RightOn;
extern Uint8 _SLeftOn;
extern Uint8 _SRightOn;
extern Uint8 _JumpOn;
extern Uint8 _FireOn;
extern Uint8 _ChangOn;
extern Uint8 _StrafeOn;
extern Uint8 _SpeedUpOn;
extern Uint8 _MLookOn;
extern Uint8 _MLookT;
extern Uint8 _ViewUpOn;
extern Uint8 _ViewCntrOn;
extern Uint8 _ViewDnOn;
extern Uint8 Ms1ID;
extern Uint8 Ms2ID;
extern Uint8 ms3id;
extern bool kbViewUp;
extern bool kbViewDn;
extern bool kbViewCntr;
extern bool VCenterMode;
extern Uint8 c;
extern Uint8 kod;
extern Uint8 key;
extern boost::array<Uint8, 256> ASCII_Tab;
extern OC::String::value_type S[256];
//extern Dos::Registers Regs;
extern Sint16 JoyX;
extern Sint16 JoyY;
extern Sint16 JoyCrX;
extern Sint16 JoyCrY;
extern Sint16 JoyMnX;
extern Sint16 JoyMnY;
extern Sint16 JoyMxX;
extern Sint16 JoyMxY;
extern bool JoyStick;
extern bool JoyKeyA;
extern bool JoyKeyB;
extern Sint16 MsX;
extern Sint16 MsY;
extern Sint16 MsButt;
extern Sint16 MsV;
extern Sint16 MLookTime;
extern Sint16 LastMouseX;
extern Sint16 LastMouseY;
extern Sint16 MsRv;
extern Sint16 MsVV;
extern Sint16 Msvvi;
extern Sint16 msrvi;
extern bool MouseD;
extern bool MsKeyA;
extern bool MsKeyB;
extern bool MsKeyC;
extern bool MLookOn;
extern bool RecordDemo;
extern bool PlayDemo;
extern bool IPXPresent;
extern Uint8 NGMode;
extern Uint8 NGTeam;
extern Uint8 NGSkill;
extern Uint8 NGLevel;
extern Uint8 NGCard;
extern Uint8 NGPort;
extern Uint8 NGBaud;
extern Uint8 NGColor;
extern OC::String::value_type NGNick[9];
extern OC::String SelfNick;
extern Uint8 SelfColor;
extern TInfo_Struct* PInfoStruct;
extern bool MSCDEX;
extern Sint16 LCDTrack;
extern Sint16 CDTrack;
extern Sint32 CDTime;
extern boost::array<TPlayerInfo, 8> Players;
extern Uint8 LastBorn;
extern boost::array<Uint8, 16> LevelChanges;
extern boost::array<Uint16, 4> ProcState;
extern OC::String::value_type NetMessage[33];
extern MessageRec__Element MessageRec[4];
extern ProcMessage__Type ProcMessage;
extern Uint8 VESAError;
extern Uint16 VESABank;
extern Uint16 VESABankShift;
extern Uint8 VESA_CurrColor;
extern bool VESAPresent;
extern bool VESA20Compliant;
extern Uint16 VESAVersion;
extern Uint16 TotalMemory;
extern Uint16 FLATSelector;
extern Sint32 VESA20Addr;
extern ModesList__Type ModesList;
extern TDPMIRegs DRegs;
extern bool NETMonitor;
extern bool InBrifing;
extern boost::array<Uint8, 4> VideoOwners;
extern Uint16 CurOwner;
extern Uint16 CurVideoMode;
extern Uint16 LastVideoMode;
extern ServerSaved__Type ServerSaved;
extern Sint16 CurWindow;

void VESAGetDosMem(/*...*/);
void VESAFreeDosMem(/*...*/);
void ProcedError(/*...*/);
void RealInt10h(/*...*/);
void GetVESAInfo(/*...*/);
void GetModeInfo(/*...*/);
void OnlySwitchBank(/*...*/);
void InitVideo(/*...*/);
void ClearMonitorWindow(/*...*/);
bool TextSeek(/*...*/);
void ShowFinalScreen(/*...*/);
void Wait_R(/*...*/);
void LoadPicsPacket(const OC::String& filename, TPicPack& packet);
void ScanWH(Sint16& width, Sint16& height, const TOHeader& model);
void AllocFloors(/*...*/);

void LoadSounds(OC::TextResource& info);
void LoadBMPObjects(OC::TextResource& info);
void Load3dObjects(OC::TextResource& info);
void LoadRockets(OC::TextResource& info);
void LoadGibs(OC::TextResource& info);
void LoadBlows(OC::TextResource& info);
void LoadMonsters(OC::TextResource& info);
void LoadGunsInfo(OC::TextResource& info);

void CLine(/*...*/);
void Line(/*...*/);
void HBrline0(/*...*/);
void InitNormalViewHi(/*...*/);
void InitMonitorView(/*...*/);

// /* nested */ void AddMode(/*...*/);
// /* nested */ void WriteS(/*...*/);
// /* nested */ void PutPixel(/*...*/);

enum Load3DObjectMode
{
    LOAD_3D_OBJECT_CHASM_INFO,
    LOAD_3D_OBJECT_LEVEL_RESOURCE,
};

void Load3DObject(OC::TextResource& resource, TObj3DInfo& object, const Load3DObjectMode mode);

OC::String ReadFileNameAfterEqual(OC::TextResource& resource);

} // namespace CSPBIO

#endif // OPENCHASM_CSPBIO_H_INCLUDED
