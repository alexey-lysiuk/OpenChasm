
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

#include "cs3dm2.h"

#include "csmenu.h"

namespace CS3DM2
{

static void SetFreeVert(const Uint16 a, const Uint16 b)
{
    Uint16 c = 0;

    while (a == c || b == c)
    {
        ++c;
    }

    Uint16 d = 0;

    while (a == d || b == d || c == d)
    {
        ++d;
    }

    Free_vert[a * 4 + b].A = c;
    Free_vert[a * 4 + b].B = d;
}

void InitModule()
{
    for (size_t i = 0; i < 256; ++i)
    {
        CSMENU::RecolorMap[i] = Uint8(i);
    }

    Div_tab[0] = 0x7FFF;
    Div_tab[1] = 0x7FFF;
    Div_tab[2] = 0x7FFF;

    for (size_t i = 3; i < 1024; ++i)
    {
        Div_tab[i] = Uint16(0x10000 / i);
    }

    for (Uint16 i = 0; i < 4; ++i)
    {
        for (Uint16 j = 0; j < 4; ++j)
        {
            SetFreeVert(i, j);
        }
    }
}

void Draw3DObject(/*...*/);
void Show3DObject(/*...*/);
void DrawHi3D(/*...*/);
void Morph3d(/*...*/);

Uint16 ShadowCount = 7;
Uint16 ShLevel;
Sint16 GlobX;
Sint16 GlobY;
Sint16 Curdark;
Sint16 HPrior;
Uint8 DrawMask;
bool YWrap = false;
bool Invisibility;
bool HiRot;
bool XTabUpdated;
Sint16 XFi;
Sint16 Xfiz0;
Sint16 DepthD;
Sint16 ShadowZ0;
Uint16 _dx;
Uint16 ReColor = 0;
Uint16 LocalFi;
Sint16 WallHhi;
Sint16 WallWhi;
Uint16 FacesXtab[400];

void movsD(/*...*/);
void VLineT_Recolor(/*...*/);
void VLineTGlass_Recolor(/*...*/);

void VLineT()
{
    // TODO...
}

void VLineTGlass()
{
    // TODO...
}

void VLineTGlass60()
{
    // TODO...
}

void VLineTFF()
{
    // TODO...
}

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

Sint16 Lx1;
Sint16 Lx2;
Sint16 Ix;
Sint16 Nx;
Sint16 DDIX;
Sint16 DDX;
Sint16 DDY;
Sint16 OBJx;
Sint16 OBJy;
Sint16 OBJz;
Sint16 LCnt;
Sint16 LtX;
Sint16 LtY;
Sint16 llx;
Sint16 lly;
Sint16 R;
Sint32 LSY1;
Sint32 LDDY;
Sint16 adx;
Sint16 ady;
Sint16 adtx;
Sint16 adty;
Uint16 OHSeg;
Uint16 lnH;
Uint16 CSprOfs;
Uint16 CurFI;
Uint16 CntrVCnt;
Sint16 VCount;
Sint16 FCount;
Uint16 CurDH;
Uint16 CurShDh;
Uint16 TSeg;
Sint16 np;
Sint16 npp;
Sint16 Current;
Sint16 WallH4;
CSPBIO::TOHeader* POH;
CSPBIO::DWord Ya;
CSPBIO::DWord DYa;
CSPBIO::DWord Yb;
CSPBIO::DWord DYb;
CSPBIO::DWord dy1;
CSPBIO::DWord dy2;
CSPBIO::DWord dy3;
CSPBIO::DWord dy4;
Sint16 txa;
Sint16 tya;
Sint16 dtxa;
Sint16 dtya;
Sint16 txb;
Sint16 tyb;
Sint16 dtxb;
Sint16 dtyb;
Sint16 L1;
Sint16 L2;
Sint16 L3;
Sint16 l4;
Sint16 x1;
Sint16 x2;
Sint16 x3;
Sint16 x4;
Sint16 y1;
Sint16 y2;
Sint16 y3;
Sint16 y4;
Sint16 tx1;
Sint16 ty1;
Sint16 tx2;
Sint16 ty2;
Sint16 tx3;
Sint16 ty3;
Sint16 tx4;
Sint16 ty4;
Sint16 dtx1;
Sint16 dty1;
Sint16 dtx2;
Sint16 dty2;
Sint16 dtx3;
Sint16 dty3;
Sint16 dtx4;
Sint16 dty4;
Sint16 x;
Sint16 ctdx;
Sint16 ctdy;
Sint16 vx;
Sint16 vy;
Sint16 ux;
Sint16 uy;
Uint16 v1;
Uint16 v2;
Uint16 v3;
Uint16 v4;

void (*DrawRoutOfsTab[8])() = 
{
    VLineT, VLineTFF, VLineTGlass, VLineTGlass, VLineTGlass60, VLineT, VLineT, VLineT
};

void (*DrawRout)() = VLineT;

Uint16 Div_tab[1024];
Free_vert__Element Free_vert[16];

} // namespace CS3DM2
