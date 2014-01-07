
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

#ifndef OPENCHASM_SOUNDIP_SOUNDIP_H_INCLUDED
#define OPENCHASM_SOUNDIP_SOUNDIP_H_INCLUDED

namespace SoundIP
{

struct TSFXRec
{
    void* P;
    Uint16 Blocks;
    Uint16 Volume;
};

struct TSFXChannel
{
    void* Data;
    Uint16 Blocks;
    Uint16 CurBlock;
    Uint16 CVolume;
    Sint16 X;
    Sint16 Y;
};

struct TSFXAmbient
{
    void* p;
    Uint16 ASize;
    Uint16 Blocks;
    Uint16 CurPos;
    Sint16 Volume;
    Sint16 BackSFX;
};

struct ObjAmb__Type
{
    Sint16 Ambid;
    Sint16 R;
    Sint16 osx;
    Sint16 osy;
};

struct DMA_Entry
{
    Uint16 Flags;
    Uint16 Latch;
    Uint16 DMA_Disable;
    Uint16 DMA_Enable;
    Uint16 Page;
    Uint16 Addr;
    Uint16 Count;
    Uint16 SINGLE;
    Uint16 Mode;
    Uint16 Clear_FF;
    Uint16 WriteTrans;
    Uint16 ReadTrans;
    Uint8 Cur_Mode;
};


void InitModule();

void DisableSFXIRQ(/*...*/);
void EnableSFXIRQ(/*...*/);
void AddAmbient(/*...*/);
bool RegisterCard(/*...*/);
void SetVolumes(/*...*/);
void UpDatePlayerPos(/*...*/);
void SetAmbient(/*...*/);
void AddVoice(/*...*/);
void InitSoundSystem(/*...*/);
void DeInitSoundSystem(/*...*/);
void DetectSound(/*...*/);

extern Uint8 sCard;
extern Uint8 sDMA;
extern Uint8 sIRQ;
extern Uint16 sBase;
extern Uint16 sbDSPver;
extern Uint8 FXVolume;
extern Uint8 CDVolume;
extern Uint8 ActiveVoices;
extern Uint8 MaxVoice;
extern void (*Old_IRQ)();
extern bool DisableALL;
extern bool Reverse;
extern Sint16 PreAmbient;
extern Sint16 CurAmbient;
extern Uint8 PAmbVol;
extern Uint8 CAmbVol;
extern TSFXRec* Voices;
extern TSFXAmbient Ambients[32];
extern TSFXChannel Channels[16];
extern ObjAmb__Type ObjAmb;
extern ObjAmb__Type ObjAmbU;
extern Uint16 GUSVPos;

void movsw(/*...*/);
void StosW(/*...*/);
void GetMem16(/*...*/);
void ContinueAmbient(/*...*/);
void WriteMixer(/*...*/);
void ProgramDMALo(/*...*/);
void ProgramDMAHi(/*...*/);
Uint8 ReadDSP(/*...*/);
void WriteToDSP(/*...*/);
bool ResetDSP(/*...*/);
void ProgramDSP8bit(/*...*/);
void programDSP16bit(/*...*/);
void NextStereoBlock16(/*...*/);
void NextStereoBlock(/*...*/);
void NextMonoBlock(/*...*/);
void IRQ_Handler(/*...*/);
bool TestSBlaster(/*...*/);
void InitDMABuffers(/*...*/);
void InitMixerChip(/*...*/);
void InitSb(/*...*/);
void DeInitSB(/*...*/);
Uint16 Addr_HIGH(/*...*/);
Uint16 Addr_LOW(/*...*/);
void GF1_Delay(/*...*/);
Uint8 GUSPeekData(/*...*/);
void GUSPokeData(/*...*/);
void ClearGUSMemory(/*...*/);
bool UltraReset(/*...*/);
Uint8 UltraPrimeVoice(/*...*/);
void UltraSetVoiceEnd(/*...*/);
void UltraGoVoice(/*...*/);
void UltraSetFrequency(/*...*/);
void UltraSetBalance(/*...*/);
void UltraSetVolume(/*...*/);
Uint16 UltraReadVoice(/*...*/);
void PrimeDMA(/*...*/);
void UltraDMADRAM_64K(/*...*/);
void UltraSetInterface(/*...*/);
void DeInitGUS(/*...*/);
void GUS_InitDMABuffers(/*...*/);
bool TestGUS(/*...*/);
void GUS_MixNextBlock(/*...*/);
void GUS_StartNext(/*...*/);
void GUS_IRQ_Handler(/*...*/);
void InitGUS(/*...*/);
void DetectBlaster(/*...*/);
bool DetectGravis(/*...*/);

extern Sint16 GUSVoices;
extern Uint8 _GF1_IRQ[16];
extern DMA_Entry _GF1_DMA[7];
extern Uint8 intN;
extern Sint16 Px;
extern Sint16 Py;
extern Sint16 PSin;
extern Sint16 PCos;
extern Uint16 CSCopy;
extern Sint16 n;
extern Sint16 j;
extern FILE F;
extern Uint16 LastBChannel;
extern void* SFXBuf;
extern void* SFXDMABuf;
extern Uint16 TimeRate;
extern Uint16 SFXPage;
extern Uint16 SFXRxA;
extern Uint16 SFXRv;
extern Uint16 SFXLv;
extern Uint16 SFXC;
extern Uint16 SFXLen;
extern Uint16 SFXPageOfs;
extern Uint16 SFXDMASeg;
extern Uint16 SFXBufSeg;
extern Uint16 SFXBOfs;
extern Uint16 VcSeg;
extern Uint16 _SFXLv;
extern Uint16 _SFXRv;
extern Uint16 _CurBlock;
extern Uint16 SFXLn;
extern Uint16 SFXRvW;
extern Uint16 SFXLvW;
extern Sint16 SFXSx;
extern Sint16 SFXSy;
extern Sint16 SFXSrxA;
extern Sint16 SFXSrx;
extern Sint16 SFXSry;
extern Uint8 SFXCount;
extern Uint8 DSPP;
extern Sint32 dma20bit;

// /* nested */ void GetDosPage(/*...*/);

extern Uint8 DRAM_DMA;

// /* nested */ void SendBlock(/*...*/);
// /* nested */ Uint16 GetData(/*...*/);
// /* nested */ Uint16 GetData__0(/*...*/);

} // namespace SoundIP

#endif // OPENCHASM_SOUNDIP_SOUNDIP_H_INCLUDED
