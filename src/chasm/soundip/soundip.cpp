
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

#include "soundip/soundip.h"

namespace SoundIP
{

void InitModule()
{
    // TODO...
}

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

Uint8 sCard;
Uint8 sDMA;
Uint8 sIRQ;
Uint16 sBase;
Uint16 sbDSPver;
Uint8 FXVolume;
Uint8 CDVolume;
Uint8 ActiveVoices;
Uint8 MaxVoice;
void (*Old_IRQ)();
bool DisableALL;
bool Reverse;
Sint16 PreAmbient;
Sint16 CurAmbient;
Uint8 PAmbVol;
Uint8 CAmbVol;
TSFXRec* Voices;
TSFXAmbient Ambients[32];
TSFXChannel Channels[16];
ObjAmb__Type ObjAmb;
ObjAmb__Type ObjAmbU;
Uint16 GUSVPos;

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

Sint16 GUSVoices;
Uint8 _GF1_IRQ[16];
DMA_Entry _GF1_DMA[7];
Uint8 intN;
Sint16 Px;
Sint16 Py;
Sint16 PSin;
Sint16 PCos;
Uint16 CSCopy;
Sint16 n;
Sint16 j;
FILE F;
Uint16 LastBChannel;
void* SFXBuf;
void* SFXDMABuf;
Uint16 TimeRate;
Uint16 SFXPage;
Uint16 SFXRxA;
Uint16 SFXRv;
Uint16 SFXLv;
Uint16 SFXC;
Uint16 SFXLen;
Uint16 SFXPageOfs;
Uint16 SFXDMASeg;
Uint16 SFXBufSeg;
Uint16 SFXBOfs;
Uint16 VcSeg;
Uint16 _SFXLv;
Uint16 _SFXRv;
Uint16 _CurBlock;
Uint16 SFXLn;
Uint16 SFXRvW;
Uint16 SFXLvW;
Sint16 SFXSx;
Sint16 SFXSy;
Sint16 SFXSrxA;
Sint16 SFXSrx;
Sint16 SFXSry;
Uint8 SFXCount;
Uint8 DSPP;
Sint32 dma20bit;

// /* nested */ void GetDosPage(/*...*/);

Uint8 DRAM_DMA;

// /* nested */ void SendBlock(/*...*/);
// /* nested */ Uint16 GetData(/*...*/);
// /* nested */ Uint16 GetData__0(/*...*/);

}
