
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

#ifndef OPENCHASM_CS3DM2_H_INCLUDED
#define OPENCHASM_CS3DM2_H_INCLUDED

namespace CSPBIO
{
    typedef Sint32 DWord;

    struct TOHeader;
};

namespace CS3DM2
{

struct __PPoint
{
    Sint16 Y;
    Sint16 SpX;
    Sint16 SpY;
    Sint16 Reserv;
};

struct PLine
{
    __PPoint A;
    __PPoint B;
};

struct Free_vert__Element
{
    Uint16 A;
    Uint16 B;
};


void InitModule();

void Draw3DObject(/*...*/);
void Show3DObject(/*...*/);
void DrawHi3D(/*...*/);
void Morph3d(/*...*/);

extern Uint16 ShadowCount;
extern Uint16 ShLevel;
extern Sint16 GlobX;
extern Sint16 GlobY;
extern Sint16 Curdark;
extern Sint16 HPrior;
extern Uint8 DrawMask;
extern bool YWrap;
extern bool Invisibility;
extern bool HiRot;
extern bool XTabUpdated;
extern Sint16 XFi;
extern Sint16 Xfiz0;
extern Sint16 DepthD;
extern Sint16 ShadowZ0;
extern Uint16 _dx;
extern Uint16 ReColor;
extern Uint16 LocalFi;
extern Sint16 WallHhi;
extern Sint16 WallWhi;
extern Uint16 FacesXtab[400];

void movsD(/*...*/);
void VLineT_Recolor(/*...*/);
void VLineTGlass_Recolor(/*...*/);
void VLineT();
void VLineTGlass();
void VLineTGlass60();
void VLineTFF();
void VLineD(/*...*/);
void DrawTriFace(/*...*/);
void DrawFourFace1234(/*...*/);
void DrawFourFace1243(/*...*/);
void DrawFourFace(/*...*/);
void DrawFaces(/*...*/);
void DrawFacesNoCheck(/*...*/);
void RotateModelCopy(/*...*/);
void RotateModelASM(/*...*/);
void RotateModelASM_HiDet(/*...*/);
void RotateModelASM_XZ(/*...*/);
void ProcToScrASM_Far(/*...*/);
void ProcToScrMinMax(/*...*/);
void ProcToScrASM_Clip(/*...*/);
void ProcToScrASM_Clip_hi(/*...*/);
void BuildTreeAsm_Far(/*...*/);
void BuildTreeAsm_NoSort(/*...*/);
void BuildTreeAsm_Clip(/*...*/);
void DrawTriFaceSh(/*...*/);
void DrawFourFaceSh1234(/*...*/);
void DrawFourFaceSh1243(/*...*/);
void DrawFourFaceSh(/*...*/);
void CreateShadow(/*...*/);
void ProcToScrShadow_Clip(/*...*/);
void DrawShadowFaces(/*...*/);

extern Sint16 Lx1;
extern Sint16 Lx2;
extern Sint16 Ix;
extern Sint16 Nx;
extern Sint16 DDIX;
extern Sint16 DDX;
extern Sint16 DDY;
extern Sint16 OBJx;
extern Sint16 OBJy;
extern Sint16 OBJz;
extern Sint16 LCnt;
extern Sint16 LtX;
extern Sint16 LtY;
extern Sint16 llx;
extern Sint16 lly;
extern Sint16 R;
extern Sint32 LSY1;
extern Sint32 LDDY;
extern Sint16 adx;
extern Sint16 ady;
extern Sint16 adtx;
extern Sint16 adty;
extern Uint16 OHSeg;
extern Uint16 lnH;
extern Uint16 CSprOfs;
extern Uint16 CurFI;
extern Uint16 CntrVCnt;
extern Sint16 VCount;
extern Sint16 FCount;
extern Uint16 CurDH;
extern Uint16 CurShDh;
extern Uint16 TSeg;
extern Sint16 np;
extern Sint16 npp;
extern Sint16 Current;
extern Sint16 WallH4;
extern CSPBIO::TOHeader* POH;
extern CSPBIO::DWord Ya;
extern CSPBIO::DWord DYa;
extern CSPBIO::DWord Yb;
extern CSPBIO::DWord DYb;
extern CSPBIO::DWord dy1;
extern CSPBIO::DWord dy2;
extern CSPBIO::DWord dy3;
extern CSPBIO::DWord dy4;
extern Sint16 txa;
extern Sint16 tya;
extern Sint16 dtxa;
extern Sint16 dtya;
extern Sint16 txb;
extern Sint16 tyb;
extern Sint16 dtxb;
extern Sint16 dtyb;
extern Sint16 L1;
extern Sint16 L2;
extern Sint16 L3;
extern Sint16 l4;
extern Sint16 x1;
extern Sint16 x2;
extern Sint16 x3;
extern Sint16 x4;
extern Sint16 y1;
extern Sint16 y2;
extern Sint16 y3;
extern Sint16 y4;
extern Sint16 tx1;
extern Sint16 ty1;
extern Sint16 tx2;
extern Sint16 ty2;
extern Sint16 tx3;
extern Sint16 ty3;
extern Sint16 tx4;
extern Sint16 ty4;
extern Sint16 dtx1;
extern Sint16 dty1;
extern Sint16 dtx2;
extern Sint16 dty2;
extern Sint16 dtx3;
extern Sint16 dty3;
extern Sint16 dtx4;
extern Sint16 dty4;
extern Sint16 x;
extern Sint16 ctdx;
extern Sint16 ctdy;
extern Sint16 vx;
extern Sint16 vy;
extern Sint16 ux;
extern Sint16 uy;
extern Uint16 v1;
extern Uint16 v2;
extern Uint16 v3;
extern Uint16 v4;
extern void (*DrawRoutOfsTab[8])();
extern void (*DrawRout)();
extern Uint16 Div_tab[1024];
extern Free_vert__Element Free_vert[16];

} // namespace CS_DEMO

#endif // OPENCHASM_CS3DM2_H_INCLUDED
