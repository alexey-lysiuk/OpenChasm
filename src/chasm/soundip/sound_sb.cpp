
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

#include "soundip/sound_sb.h"

//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 5
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ WriteMixer	proc far		; CODE XREF: InitMixerChip+7P
//@ 					; InitMixerChip+10P ...
//@ 
//@ Value		= byte ptr  6		; uint8_t
//@ Device		= byte ptr  8		; uint8_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 6
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Device]	; uint8_t
//@ 		out	dx, al		; DMA controller, 8237A-5.
//@ 					; channel 2 base address
//@ 					; (also	sets current address)
//@ 		push	0Ah
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 7
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 5		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Value]	; uint8_t
//@ 		out	dx, al		; DMA controller, 8237A-5.
//@ 					; channel 2 base address and word count
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 8
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ WriteMixer	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 20
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProgramDMALo	proc far		; CODE XREF: ProgramDSP8bit+3P
//@ 					; NextMonoBlock+4P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 21
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 4		; Add
//@ 		out	0Ah, al		; DMA controller, 8237A-5.
//@ 					; single mask bit register
//@ 					; 0-1: select channel (00=0; 01=1; 10=2; 11=3)
//@ 					; 2: 1=set mask	for channel; 0=clear mask (enable)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 22
//@ 		mov	al, 0
//@ 		out	0Ch, al		; DMA controller, 8237A-5.
//@ 					; clear	byte pointer flip-flop.
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 23
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jnz	short loc_31C7F	; Jump if Not Zero (ZF=0)
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 48h	; 'H'   ; Add
//@ 		out	0Bh, al		; DMA 8237A-5. mode register bits:
//@ 					; 0-1: channel (00=0; 01=1; 10=2; 11=3)
//@ 					; 2-3: transfer	type (00=verify=Nop; 01=write; 10=read)
//@ 					; 4: 1=enable auto-initialization
//@ 					; 5: 1=address increment; 0=address decrement
//@ 					; 6-7: 00=demand mode; 01=single; 10=block; 11=cascade
//@ 		jmp	short loc_31C89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 24
//@ 
//@ loc_31C7F:				; CODE XREF: ProgramDMALo+16j
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 58h	; 'X'   ; Add
//@ 		out	0Bh, al		; DMA 8237A-5. mode register bits:
//@ 					; 0-1: channel (00=0; 01=1; 10=2; 11=3)
//@ 					; 2-3: transfer	type (00=verify=Nop; 01=write; 10=read)
//@ 					; 4: 1=enable auto-initialization
//@ 					; 5: 1=address increment; 0=address decrement
//@ 					; 6-7: 00=demand mode; 01=single; 10=block; 11=cascade
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 26
//@ 
//@ loc_31C89:				; CODE XREF: ProgramDMALo+22j
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr SFXPageOfs	; uint16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 27
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr SFXPageOfs+1 ; uint16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 29
//@ 		mov	al, sDMA	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 30
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jnz	short loc_31CB1	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr SFXPage ; uint16_t
//@ 		out	87h, al		; DMA page register 74LS612:
//@ 					; Channel 0 (address bits 16-23)
//@ 		jmp	short loc_31CD0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 31
//@ 
//@ loc_31CB1:				; CODE XREF: ProgramDMALo+4Dj
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_31CBC	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr SFXPage ; uint16_t
//@ 		out	83h, al		; DMA page register 74LS612:
//@ 					; Channel 1 (address bits 16-23)
//@ 		jmp	short loc_31CD0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 32
//@ 
//@ loc_31CBC:				; CODE XREF: ProgramDMALo+58j
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_31CC7	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr SFXPage ; uint16_t
//@ 		out	81h, al		; DMA page register 74LS612:
//@ 					; Channel 2 (diskette DMA)  (address bits 16-23)
//@ 		jmp	short loc_31CD0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 33
//@ 
//@ loc_31CC7:				; CODE XREF: ProgramDMALo+63j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_31CD0	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr SFXPage ; uint16_t
//@ 		out	82h, al		; DMA page register 74LS612:
//@ 					; Channel 3 (hard disk DMA) (address bits 16-23)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 36
//@ 
//@ loc_31CD0:				; CODE XREF: ProgramDMALo+54j
//@ 					; ProgramDMALo+5Fj ...
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		inc	ax		; Increment by 1
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr SFXLen ; uint16_t
//@ 		out	dx, al		; DMA controller, 8237A-5.
//@ 					; channel 0 base address and word count
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 37
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		inc	ax		; Increment by 1
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr SFXLen+1 ;	uint16_t
//@ 		out	dx, al		; DMA controller, 8237A-5.
//@ 					; channel 0 base address and word count
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 39
//@ 		mov	al, sDMA	; uint8_t
//@ 		out	0Ah, al		; DMA controller, 8237A-5.
//@ 					; single mask bit register
//@ 					; 0-1: select channel (00=0; 01=1; 10=2; 11=3)
//@ 					; 2: 1=set mask	for channel; 0=clear mask (enable)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 40
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ProgramDMALo	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 44
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProgramDMAHi	proc far		; CODE XREF: programDSP16bit+3P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 45
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		add	ax, 4		; Add
//@ 		out	0D4h, al
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 46
//@ 		mov	al, 0
//@ 		out	0D8h, al
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 47
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		add	ax, 58h	; 'X'   ; Add
//@ 		out	0D6h, al
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 48
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, 0C0h ; 'À'  ; Add
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr SFXPageOfs	; uint16_t
//@ 		out	dx, al		; Interrupt Controller #2, 8259A
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 49
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, 0C0h ; 'À'  ; Add
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr SFXPageOfs+1 ; uint16_t
//@ 		out	dx, al		; Interrupt Controller #2, 8259A
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 51
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, 0C2h ; 'Â'  ; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0FFh
//@ 		out	dx, al		; Interrupt Controller #2, 8259A
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 52
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, 0C2h ; 'Â'  ; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0Fh
//@ 		out	dx, al		; Interrupt Controller #2, 8259A
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 54
//@ 		mov	al, sDMA	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 55
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short loc_31D70	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr SFXPage ; uint16_t
//@ 		out	8Bh, al		; DMA page register 74LS612:
//@ 					; Channel 5 (address bits 17-23)
//@ 		jmp	short loc_31D84	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 56
//@ 
//@ loc_31D70:				; CODE XREF: ProgramDMAHi+74j
//@ 		cmp	al, 6		; Compare Two Operands
//@ 		jnz	short loc_31D7B	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr SFXPage ; uint16_t
//@ 		out	89h, al		; DMA page register 74LS612:
//@ 					; Channel 6 (address bits 17-23)
//@ 		jmp	short loc_31D84	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 57
//@ 
//@ loc_31D7B:				; CODE XREF: ProgramDMAHi+7Fj
//@ 		cmp	al, 7		; Compare Two Operands
//@ 		jnz	short loc_31D84	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr SFXPage ; uint16_t
//@ 		out	8Ah, al		; DMA page register 74LS612:
//@ 					; Channel 7 (address bits 17-23)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 60
//@ 
//@ loc_31D84:				; CODE XREF: ProgramDMAHi+7Bj
//@ 					; ProgramDMAHi+86j ...
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		out	0D4h, al
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 61
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ProgramDMAHi	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 69
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ ReadDSP		proc far		; CODE XREF: ResetDSP:loc_31E1BP
//@ 					; TestSBlaster+62P ...
//@ 
//@ n		= word ptr -4		; int16_t
//@ ReadDSP		= byte ptr -1		; uint8_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 70
//@ 
//@ loc_31D94:				; CODE XREF: ReadDSP+1Dj
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Eh		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx		; DMA controller, 8237A-5.
//@ 					; Clear	mask registers.
//@ 					; Any OUT enables all 4	channels.
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_31DAF	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+n],	4E20h	; int16_t
//@ 		jge	short loc_31DAF	; Jump if Greater or Equal (SF=OF)
//@ 		inc	[bp+n]		; int16_t
//@ 		jmp	short loc_31D94	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 71
//@ 
//@ loc_31DAF:				; CODE XREF: ReadDSP+11j ReadDSP+18j
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Ah		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx		; DMA controller, 8237A-5.
//@ 					; single mask bit register
//@ 					; 0-1: select channel (00=0; 01=1; 10=2; 11=3)
//@ 					; 2: 1=set mask	for channel; 0=clear mask (enable)
//@ 		mov	[bp+ReadDSP], al ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 72
//@ 		mov	al, [bp+ReadDSP] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ReadDSP		endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 76
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ WriteToDSP	proc far		; CODE XREF: ProgramDSP8bit+FP
//@ 					; ProgramDSP8bit+16P ...
//@ 
//@ n		= word ptr -2		; int16_t
//@ V		= byte ptr  6		; uint8_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 77
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 78
//@ 
//@ loc_31DC9:				; CODE XREF: WriteToDSP+22j
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Ch		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx		; DMA controller, 8237A-5.
//@ 					; clear	byte pointer flip-flop.
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_31DE4	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	[bp+n],	4E20h	; int16_t
//@ 		jge	short loc_31DE4	; Jump if Greater or Equal (SF=OF)
//@ 		inc	[bp+n]		; int16_t
//@ 		jmp	short loc_31DC9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 79
//@ 
//@ loc_31DE4:				; CODE XREF: WriteToDSP+16j
//@ 					; WriteToDSP+1Dj
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Ch		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+V]	; uint8_t
//@ 		out	dx, al		; DMA controller, 8237A-5.
//@ 					; clear	byte pointer flip-flop.
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 80
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ WriteToDSP	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 83
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ ResetDSP	proc far		; CODE XREF: DeInitSB+33P
//@ 
//@ ResetDSP	= byte ptr -1		; bool
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 84
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	dx, ax
//@ 		mov	al, 1
//@ 		out	dx, al		; DMA controller, 8237A-5.
//@ 					; channel 3 base address
//@ 					; (also	sets current address)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 85
//@ 		push	28h ; '('
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 86
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al		; DMA controller, 8237A-5.
//@ 					; channel 3 base address
//@ 					; (also	sets current address)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 87
//@ 		mov	j$0, 3E8h	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 88
//@ 
//@ loc_31E1B:				; CODE XREF: ResetDSP+3Bj
//@ 		call	ReadDSP		; function far PASCAL returns unsigned char 'Byte'
//@ 		cmp	al, 0AAh ; 'ª'  ; Compare Two Operands
//@ 		jz	short loc_31E31	; Jump if Zero (ZF=1)
//@ 		cmp	j$0, 0		; int16_t
//@ 		jle	short loc_31E31	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		dec	j$0		; int16_t
//@ 		jmp	short loc_31E1B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 89
//@ 
//@ loc_31E31:				; CODE XREF: ResetDSP+2Ej ResetDSP+35j
//@ 		cmp	j$0, 0		; int16_t
//@ 		jle	short loc_31E3E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+ResetDSP], 1 ; bool
//@ 		jmp	short loc_31E42	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 90
//@ 
//@ loc_31E3E:				; CODE XREF: ResetDSP+42j
//@ 		mov	[bp+ResetDSP], 0 ; bool
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 91
//@ 
//@ loc_31E42:				; CODE XREF: ResetDSP+48j
//@ 		mov	al, [bp+ResetDSP] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ResetDSP	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 95
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProgramDSP8bit	proc far		; CODE XREF: InitSb:loc_32A30P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 96
//@ 		call	ProgramDMALo	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 98
//@ 		mov	MaxVoice, 0Fh	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 99
//@ 		push	0FFD1h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 100
//@ 		push	40h ; '@'
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 101
//@ 		mov	al, byte ptr TimeRate ;	uint16_t
//@ 		push	ax
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 103
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jnz	short loc_31E8D	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 105
//@ 		push	14h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 106
//@ 		mov	al, byte ptr SFXLen ; uint16_t
//@ 		push	ax
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 107
//@ 		mov	al, byte ptr SFXLen+1 ;	uint16_t
//@ 		push	ax
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 108
//@ 		jmp	short locret_31EB4 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 110
//@ 
//@ loc_31E8D:				; CODE XREF: ProgramDSP8bit+29j
//@ 		push	48h ; 'H'
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 111
//@ 		mov	al, byte ptr SFXLen ; uint16_t
//@ 		push	ax
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 112
//@ 		mov	al, byte ptr SFXLen+1 ;	uint16_t
//@ 		push	ax
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 113
//@ 		push	1Ch
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 114
//@ 		push	0FFF2h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 116
//@ 
//@ locret_31EB4:				; CODE XREF: ProgramDSP8bit+44j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ProgramDSP8bit	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 120
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ programDSP16bit	proc far		; CODE XREF: InitSb+63P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 121
//@ 		call	ProgramDMAHi	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 123
//@ 		mov	MaxVoice, 0Fh	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 124
//@ 		push	0FFD1h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 125
//@ 		push	41h ; 'A'
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 126
//@ 		push	2Bh ; '+'
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 127
//@ 		push	2Ah ; '*'
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 128
//@ 		push	0FFB6h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 129
//@ 		push	30h ; '0'
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 130
//@ 		push	0FFFFh
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 131
//@ 		push	7
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 132
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ programDSP16bit	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 143
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ NextStereoBlock16 proc far		; CODE XREF: IRQ_Handler+2CP
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 144
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Fh		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		mov	DSPP, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 145
//@ 		call	ContinueAmbient	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 146
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	800h
//@ 		push	0
//@ 		call	StosW$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 148
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXC, ax	; uint16_t
//@ 		jmp	short loc_31F2D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_31F29:				; CODE XREF: NextStereoBlock16+2C1j
//@ 		inc	SFXC		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 149
//@ 
//@ loc_31F2D:				; CODE XREF: NextStereoBlock16+2Aj
//@ 		imul	di, SFXC, 0Eh	; uint16_t
//@ 		add	di, 0F782h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	word ptr es:[di+6], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_31F49	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_321B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 151
//@ 
//@ loc_31F49:				; CODE XREF: NextStereoBlock16+47j
//@ 		cmp	word ptr es:[di+0Ah], 0	; Compare Two Operands
//@ 		jz	short loc_31F57	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+0Ch], 0	; Compare Two Operands
//@ 		jnz	short loc_31F7E	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 152
//@ 
//@ loc_31F57:				; CODE XREF: NextStereoBlock16+51j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_31F6F	; Jump if Not Zero (ZF=0)
//@ 		mov	_SFXRv,	50h ; 'P' ; uint16_t
//@ 		mov	_SFXLv,	50h ; 'P' ; uint16_t
//@ 		jmp	short loc_31F7B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 153
//@ 
//@ loc_31F6F:				; CODE XREF: NextStereoBlock16+62j
//@ 		mov	_SFXRv,	50h ; 'P' ; uint16_t
//@ 		mov	_SFXLv,	50h ; 'P' ; uint16_t
//@ 
//@ loc_31F7B:				; CODE XREF: NextStereoBlock16+70j
//@ 		jmp	loc_320BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 156
//@ 
//@ loc_31F7E:				; CODE XREF: NextStereoBlock16+58j
//@ 		mov	ax, Px		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		mov	SFXSx, ax	; int16_t
//@ 		mov	ax, Py		; int16_t
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		mov	SFXSy, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 158
//@ 		mov	ax, SFXSy	; int16_t
//@ 		mov	bx, PCos	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		mov	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 159
//@ 		mov	ax, SFXSx	; int16_t
//@ 		mov	bx, PSin	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		add	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 160
//@ 		mov	ax, SFXSx	; int16_t
//@ 		mov	bx, PCos	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		mov	SFXSrx,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 161
//@ 		mov	ax, SFXSy	; int16_t
//@ 		mov	bx, PSin	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		sub	SFXSrx,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 163
//@ 		cmp	SFXSry,	0	; int16_t
//@ 		jge	short loc_31FEA	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, SFXSry	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 164
//@ 
//@ loc_31FEA:				; CODE XREF: NextStereoBlock16+E3j
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	SFXSry,	ax	; int16_t
//@ 		cmp	SFXSry,	0Eh	; int16_t
//@ 		jge	short loc_32002	; Jump if Greater or Equal (SF=OF)
//@ 		mov	SFXSry,	0Eh	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 165
//@ 
//@ loc_32002:				; CODE XREF: NextStereoBlock16+FDj
//@ 		mov	ax, SFXSrx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	SFXSrxA, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 166
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cmp	ax, SFXSrxA	; int16_t
//@ 		jle	short loc_3202C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 168
//@ 		mov	ax, SFXSrxA	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 169
//@ 		mov	bx, 0A0h ; ' '
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 170
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 171
//@ 		mov	bx, SFXSry	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 172
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 173
//@ 		add	ax, 240h	; Add
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 174
//@ 		mov	SFXRvW,	ax	; uint16_t
//@ 		jmp	short loc_32042	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 177
//@ 
//@ loc_3202C:				; CODE XREF: NextStereoBlock16+117j
//@ 		mov	ax, SFXSry	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 178
//@ 		mov	bx, 0A0h ; ' '
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 179
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 180
//@ 		mov	bx, SFXSrxA	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 181
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 182
//@ 		neg	ax		; Two's Complement Negation
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 183
//@ 		add	ax, 380h	; Add
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 184
//@ 		mov	SFXRvW,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 188
//@ 
//@ loc_32042:				; CODE XREF: NextStereoBlock16+12Dj
//@ 		mov	ax, 480h
//@ 		sub	ax, SFXRvW	; uint16_t
//@ 		mov	SFXLvW,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 190
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, SFXSrx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	SFXLn, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 191
//@ 		cmp	SFXLn, 0Ch	; uint16_t
//@ 		jnb	short loc_32075	; Jump if Not Below (CF=0)
//@ 		mov	SFXLn, 8	; uint16_t
//@ 		jmp	short loc_32081	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32075:				; CODE XREF: NextStereoBlock16+16Ej
//@ 		mov	ax, SFXLn	; uint16_t
//@ 		sub	ax, 0Ch		; Integer Subtraction
//@ 		add	ax, 8		; Add
//@ 		mov	SFXLn, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 193
//@ 
//@ loc_32081:				; CODE XREF: NextStereoBlock16+176j
//@ 		cmp	SFXSrx,	0	; int16_t
//@ 		jle	short loc_320A2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, SFXRvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		mov	ax, SFXLvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ 		jmp	short loc_320BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 194
//@ 
//@ loc_320A2:				; CODE XREF: NextStereoBlock16+189j
//@ 		mov	ax, SFXLvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		mov	ax, SFXRvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 197
//@ 
//@ loc_320BA:				; CODE XREF: NextStereoBlock16:loc_31F7Bj
//@ 					; NextStereoBlock16+1A3j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	VcSeg, ax	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		mov	_CurBlock, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 198
//@ 		cmp	Reverse, 0	; bool
//@ 		jz	short loc_320E6	; Jump if Zero (ZF=1)
//@ 		push	_SFXLv		; uint16_t
//@ 		push	_SFXRv		; uint16_t
//@ 		pop	_SFXLv		; uint16_t
//@ 		pop	_SFXRv		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 199
//@ 
//@ loc_320E6:				; CODE XREF: NextStereoBlock16+1D7j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		mul	_SFXRv		; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		cmp	_SFXRv,	7Fh ; '' ; uint16_t
//@ 		jbe	short loc_32104	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	_SFXRv,	7Fh ; '' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 200
//@ 
//@ loc_32104:				; CODE XREF: NextStereoBlock16+1FFj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		mul	_SFXLv		; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ 		cmp	_SFXLv,	7Fh ; '' ; uint16_t
//@ 		jbe	short loc_32122	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	_SFXLv,	7Fh ; '' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 202
//@ 
//@ loc_32122:				; CODE XREF: NextStereoBlock16+21Dj
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 204
//@ 		mov	cx, 400h
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		mov	bx, _SFXLv	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 205
//@ 		mov	si, _CurBlock	; uint16_t
//@ 		shl	si, 0Ah		; Shift	Logical	Left
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 206
//@ 		mov	ax, VcSeg	; uint16_t
//@ 		push	ds
//@ 		mov	ds, ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 208
//@ 
//@ loc_3213D:				; CODE XREF: NextStereoBlock16+257j
//@ 		mov	al, [si]
//@ 		imul	bl		; Signed Multiply
//@ 		add	es:[di], ax	; Add
//@ 		jno	short loc_3214F	; Jump if Not Overflow (OF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 209
//@ 		shr	ax, 0Fh		; Shift	Logical	Right
//@ 		add	ax, 7FFFh	; Add
//@ 		mov	es:[di], ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 210
//@ 
//@ loc_3214F:				; CODE XREF: NextStereoBlock16+247j
//@ 		add	di, 4		; Add
//@ 		inc	si		; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 211
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_3213D	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 213
//@ 		pop	ds
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 216
//@ 		mov	cx, 400h
//@ 		mov	bx, _SFXRv	; uint16_t
//@ 		mov	di, 2
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 217
//@ 		mov	si, _CurBlock	; uint16_t
//@ 		shl	si, 0Ah		; Shift	Logical	Left
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 218
//@ 		mov	ax, VcSeg	; uint16_t
//@ 		push	ds
//@ 		mov	ds, ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 219
//@ 
//@ loc_3216E:				; CODE XREF: NextStereoBlock16+288j
//@ 		mov	al, [si]
//@ 		imul	bl		; Signed Multiply
//@ 		add	es:[di], ax	; Add
//@ 		jno	short loc_32180	; Jump if Not Overflow (OF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 220
//@ 		shr	ax, 0Fh		; Shift	Logical	Right
//@ 		add	ax, 7FFFh	; Add
//@ 		mov	es:[di], ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 221
//@ 
//@ loc_32180:				; CODE XREF: NextStereoBlock16+278j
//@ 		add	di, 4		; Add
//@ 		inc	si		; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 222
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_3216E	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 223
//@ 		pop	ds
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 226
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+6] ; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 227
//@ 		mov	ax, es:[di+6]
//@ 		cmp	ax, es:[di+4]	; Compare Two Operands
//@ 		jb	short loc_321B7	; Jump if Below	(CF=1)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 228
//@ 		cmp	SFXC, 0		; uint16_t
//@ 		jnz	short loc_321A8	; Jump if Not Zero (ZF=0)
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		jmp	short loc_321B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 229
//@ 
//@ loc_321A8:				; CODE XREF: NextStereoBlock16+2A1j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 230
//@ 
//@ loc_321B7:				; CODE XREF: NextStereoBlock16+49j
//@ 					; NextStereoBlock16+29Aj ...
//@ 		cmp	SFXC, 0Fh	; uint16_t
//@ 		jz	short loc_321C1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_31F29	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 232
//@ 
//@ loc_321C1:				; CODE XREF: NextStereoBlock16+2BFj
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	SFXDMASeg	; uint16_t
//@ 		push	SFXBOfs		; uint16_t
//@ 		push	800h
//@ 		call	movsw$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 233
//@ 		mov	ax, 1000h
//@ 		sub	ax, SFXBOfs	; uint16_t
//@ 		mov	SFXBOfs, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 234
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ NextStereoBlock16 endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 240
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ NextStereoBlock	proc far		; CODE XREF: IRQ_Handler+21P
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 241
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Eh		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		mov	DSPP, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 242
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	SFXDMASeg	; uint16_t
//@ 		push	0
//@ 		push	400h
//@ 		call	movsw$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 243
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	400h
//@ 		push	0
//@ 		call	StosW$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 244
//@ 		call	ContinueAmbient	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 247
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXC, ax	; uint16_t
//@ 		jmp	short loc_32227	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32223:				; CODE XREF: NextStereoBlock+2D2j
//@ 		inc	SFXC		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 248
//@ 
//@ loc_32227:				; CODE XREF: NextStereoBlock+3Ej
//@ 		imul	di, SFXC, 0Eh	; uint16_t
//@ 		add	di, 0F782h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	word ptr es:[di+6], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_32243	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_324AE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 250
//@ 
//@ loc_32243:				; CODE XREF: NextStereoBlock+5Bj
//@ 		cmp	word ptr es:[di+0Ah], 0	; Compare Two Operands
//@ 		jz	short loc_32251	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+0Ch], 0	; Compare Two Operands
//@ 		jnz	short loc_32278	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 251
//@ 
//@ loc_32251:				; CODE XREF: NextStereoBlock+65j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_32269	; Jump if Not Zero (ZF=0)
//@ 		mov	_SFXRv,	60h ; '`' ; uint16_t
//@ 		mov	_SFXLv,	60h ; '`' ; uint16_t
//@ 		jmp	short loc_32275	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 252
//@ 
//@ loc_32269:				; CODE XREF: NextStereoBlock+76j
//@ 		mov	_SFXRv,	60h ; '`' ; uint16_t
//@ 		mov	_SFXLv,	60h ; '`' ; uint16_t
//@ 
//@ loc_32275:				; CODE XREF: NextStereoBlock+84j
//@ 		jmp	loc_323B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 255
//@ 
//@ loc_32278:				; CODE XREF: NextStereoBlock+6Cj
//@ 		mov	ax, Px		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		mov	SFXSx, ax	; int16_t
//@ 		mov	ax, Py		; int16_t
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		mov	SFXSy, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 257
//@ 		mov	ax, SFXSy	; int16_t
//@ 		mov	bx, PCos	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		mov	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 258
//@ 		mov	ax, SFXSx	; int16_t
//@ 		mov	bx, PSin	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		add	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 259
//@ 		mov	ax, SFXSx	; int16_t
//@ 		mov	bx, PCos	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		mov	SFXSrx,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 260
//@ 		mov	ax, SFXSy	; int16_t
//@ 		mov	bx, PSin	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		sub	SFXSrx,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 262
//@ 		cmp	SFXSry,	0	; int16_t
//@ 		jge	short loc_322E4	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, SFXSry	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 263
//@ 
//@ loc_322E4:				; CODE XREF: NextStereoBlock+F7j
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	SFXSry,	ax	; int16_t
//@ 		cmp	SFXSry,	0Eh	; int16_t
//@ 		jge	short loc_322FC	; Jump if Greater or Equal (SF=OF)
//@ 		mov	SFXSry,	0Eh	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 264
//@ 
//@ loc_322FC:				; CODE XREF: NextStereoBlock+111j
//@ 		mov	ax, SFXSrx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	SFXSrxA, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 266
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cmp	ax, SFXSrxA	; int16_t
//@ 		jle	short loc_32326	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 269
//@ 		mov	ax, SFXSrxA	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 270
//@ 		mov	bx, 0A0h ; ' '
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 271
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 272
//@ 		mov	bx, SFXSry	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 273
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 274
//@ 		add	ax, 240h	; Add
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 275
//@ 		mov	SFXRvW,	ax	; uint16_t
//@ 		jmp	short loc_3233C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 279
//@ 
//@ loc_32326:				; CODE XREF: NextStereoBlock+12Bj
//@ 		mov	ax, SFXSry	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 280
//@ 		mov	bx, 0A0h ; ' '
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 281
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 282
//@ 		mov	bx, SFXSrxA	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 283
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 284
//@ 		neg	ax		; Two's Complement Negation
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 285
//@ 		add	ax, 380h	; Add
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 286
//@ 		mov	SFXRvW,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 290
//@ 
//@ loc_3233C:				; CODE XREF: NextStereoBlock+141j
//@ 		mov	ax, 480h
//@ 		sub	ax, SFXRvW	; uint16_t
//@ 		mov	SFXLvW,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 291
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, SFXSrx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	SFXLn, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 292
//@ 		cmp	SFXLn, 0Ch	; uint16_t
//@ 		jnb	short loc_3236F	; Jump if Not Below (CF=0)
//@ 		mov	SFXLn, 8	; uint16_t
//@ 		jmp	short loc_3237B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3236F:				; CODE XREF: NextStereoBlock+182j
//@ 		mov	ax, SFXLn	; uint16_t
//@ 		sub	ax, 0Ch		; Integer Subtraction
//@ 		add	ax, 8		; Add
//@ 		mov	SFXLn, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 294
//@ 
//@ loc_3237B:				; CODE XREF: NextStereoBlock+18Aj
//@ 		cmp	SFXSrx,	0	; int16_t
//@ 		jle	short loc_3239C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, SFXRvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		mov	ax, SFXLvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ 		jmp	short loc_323B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 295
//@ 
//@ loc_3239C:				; CODE XREF: NextStereoBlock+19Dj
//@ 		mov	ax, SFXLvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		mov	ax, SFXRvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 299
//@ 
//@ loc_323B4:				; CODE XREF: NextStereoBlock:loc_32275j
//@ 					; NextStereoBlock+1B7j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	VcSeg, ax	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		mov	_CurBlock, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 300
//@ 		cmp	Reverse, 0	; bool
//@ 		jz	short loc_323E0	; Jump if Zero (ZF=1)
//@ 		push	_SFXLv		; uint16_t
//@ 		push	_SFXRv		; uint16_t
//@ 		pop	_SFXLv		; uint16_t
//@ 		pop	_SFXRv		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 301
//@ 
//@ loc_323E0:				; CODE XREF: NextStereoBlock+1EBj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		mul	_SFXRv		; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		cmp	_SFXRv,	7Fh ; '' ; uint16_t
//@ 		jbe	short loc_323FE	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	_SFXRv,	7Fh ; '' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 302
//@ 
//@ loc_323FE:				; CODE XREF: NextStereoBlock+213j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		mul	_SFXLv		; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ 		cmp	_SFXLv,	7Fh ; '' ; uint16_t
//@ 		jbe	short loc_3241C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	_SFXLv,	7Fh ; '' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 304
//@ 
//@ loc_3241C:				; CODE XREF: NextStereoBlock+231j
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 305
//@ 		mov	cx, 400h
//@ 		mov	bx, _SFXLv	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 306
//@ 		xor	di, di		; Logical Exclusive OR
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 307
//@ 		mov	si, _CurBlock	; uint16_t
//@ 		shl	si, 0Ah		; Shift	Logical	Left
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 308
//@ 		mov	ax, VcSeg	; uint16_t
//@ 		push	ds
//@ 		mov	ds, ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 309
//@ 
//@ loc_32437:				; CODE XREF: NextStereoBlock+26Aj
//@ 		mov	al, [si]
//@ 		imul	bl		; Signed Multiply
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 310
//@ 		inc	di		; Increment by 1
//@ 		add	es:[di], ah	; Add
//@ 		jno	short loc_3244A	; Jump if Not Overflow (OF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 311
//@ 		shr	ah, 7		; Shift	Logical	Right
//@ 		add	ah, 7Fh	; ''   ; Add
//@ 		mov	es:[di], ah
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 312
//@ 
//@ loc_3244A:				; CODE XREF: NextStereoBlock+25Cj
//@ 		inc	di		; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 313
//@ 		inc	si		; Increment by 1
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_32437	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 314
//@ 		pop	ds
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 316
//@ 		mov	cx, 400h
//@ 		mov	bx, _SFXRv	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 317
//@ 		xor	di, di		; Logical Exclusive OR
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 318
//@ 		mov	si, _CurBlock	; uint16_t
//@ 		shl	si, 0Ah		; Shift	Logical	Left
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 319
//@ 		mov	ax, VcSeg	; uint16_t
//@ 		push	ds
//@ 		mov	ds, ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 320
//@ 
//@ loc_32466:				; CODE XREF: NextStereoBlock+299j
//@ 		mov	al, [si]
//@ 		imul	bl		; Signed Multiply
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 321
//@ 		add	es:[di], ah	; Add
//@ 		jno	short loc_32478	; Jump if Not Overflow (OF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 322
//@ 		shr	ah, 7		; Shift	Logical	Right
//@ 		add	ah, 7Fh	; ''   ; Add
//@ 		mov	es:[di], ah
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 323
//@ 
//@ loc_32478:				; CODE XREF: NextStereoBlock+28Aj
//@ 		inc	di		; Increment by 1
//@ 		inc	di		; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 324
//@ 		inc	si		; Increment by 1
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_32466	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 325
//@ 		pop	ds
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 327
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+6] ; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 328
//@ 		mov	ax, es:[di+6]
//@ 		cmp	ax, es:[di+4]	; Compare Two Operands
//@ 		jb	short loc_324AE	; Jump if Below	(CF=1)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 329
//@ 		cmp	SFXC, 0		; uint16_t
//@ 		jnz	short loc_3249F	; Jump if Not Zero (ZF=0)
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		jmp	short loc_324AE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 330
//@ 
//@ loc_3249F:				; CODE XREF: NextStereoBlock+2B2j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 331
//@ 
//@ loc_324AE:				; CODE XREF: NextStereoBlock+5Dj
//@ 					; NextStereoBlock+2ABj	...
//@ 		cmp	SFXC, 0Fh	; uint16_t
//@ 		jz	short loc_324B8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_32223	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 334
//@ 
//@ loc_324B8:				; CODE XREF: NextStereoBlock+2D0j
//@ 		mov	cx, 400h
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		mov	es, ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		mov	ax, 8080h
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 335
//@ 
//@ loc_324C5:				; CODE XREF: NextStereoBlock+2E8j
//@ 		add	es:[di], ax	; Add
//@ 		inc	di		; Increment by 1
//@ 		inc	di		; Increment by 1
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_324C5	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 338
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		mov	dx, es:[di]
//@ 		mov	ax, SFXDMASeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 339
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ NextStereoBlock	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 346
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ NextMonoBlock	proc far		; CODE XREF: IRQ_Handler+16P
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 347
//@ 		call	ProgramDMALo	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 349
//@ 		push	14h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 350
//@ 		mov	al, byte ptr SFXLen ; uint16_t
//@ 		push	ax
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 351
//@ 		mov	al, byte ptr SFXLen+1 ;	uint16_t
//@ 		push	ax
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 353
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Eh		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		mov	DSPP, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 354
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	SFXDMASeg	; uint16_t
//@ 		push	0
//@ 		push	200h
//@ 		call	movsw$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 355
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	200h
//@ 		push	0
//@ 		call	StosW$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 356
//@ 		call	ContinueAmbient	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 358
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXC, ax	; uint16_t
//@ 		jmp	short loc_32545	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32541:				; CODE XREF: NextMonoBlock+1ABj
//@ 		inc	SFXC		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 359
//@ 
//@ loc_32545:				; CODE XREF: NextMonoBlock+5Cj
//@ 		imul	di, SFXC, 0Eh	; uint16_t
//@ 		add	di, 0F782h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	word ptr es:[di+6], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_32561	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_32687	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 361
//@ 
//@ loc_32561:				; CODE XREF: NextMonoBlock+79j
//@ 		cmp	word ptr es:[di+0Ah], 0	; Compare Two Operands
//@ 		jz	short loc_3256F	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+0Ch], 0	; Compare Two Operands
//@ 		jnz	short loc_32589	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_3256F:				; CODE XREF: NextMonoBlock+83j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_32581	; Jump if Not Zero (ZF=0)
//@ 		mov	_SFXRv,	60h ; '`' ; uint16_t
//@ 		jmp	short loc_32587	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32581:				; CODE XREF: NextMonoBlock+94j
//@ 		mov	_SFXRv,	60h ; '`' ; uint16_t
//@ 
//@ loc_32587:				; CODE XREF: NextMonoBlock+9Cj
//@ 		jmp	short loc_325F0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 363
//@ 
//@ loc_32589:				; CODE XREF: NextMonoBlock+8Aj
//@ 		mov	ax, Px		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		mov	SFXSx, ax	; int16_t
//@ 		mov	ax, Py		; int16_t
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		mov	SFXSy, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 364
//@ 		mov	ax, SFXSy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, SFXSx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	SFXLn, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 365
//@ 		cmp	SFXLn, 0Ch	; uint16_t
//@ 		jnb	short loc_325C8	; Jump if Not Below (CF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXLn, ax	; uint16_t
//@ 		jmp	short loc_325CD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_325C8:				; CODE XREF: NextMonoBlock+DCj
//@ 		sub	SFXLn, 0Ch	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 366
//@ 
//@ loc_325CD:				; CODE XREF: NextMonoBlock+E3j
//@ 		mov	ax, SFXLn	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		mov	cx, ax
//@ 		mov	ax, 380h
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	cx		; Unsigned Divide
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 367
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		mul	_SFXRv		; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 370
//@ 
//@ loc_325F0:				; CODE XREF: NextMonoBlock:loc_32587j
//@ 		mov	al, FXVolume	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mul	_SFXRv		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0Fh
//@ 		div	cx		; Unsigned Divide
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 371
//@ 		cmp	_SFXRv,	7Fh ; '' ; uint16_t
//@ 		jbe	short loc_32610	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	_SFXRv,	7Fh ; '' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 372
//@ 
//@ loc_32610:				; CODE XREF: NextMonoBlock+125j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	VcSeg, ax	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		mov	_CurBlock, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 374
//@ 		mov	cx, 400h
//@ 		mov	bx, _SFXRv	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 375
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		mov	es, ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 376
//@ 		mov	si, _CurBlock	; uint16_t
//@ 		shl	si, 0Ah		; Shift	Logical	Left
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 377
//@ 		mov	ax, VcSeg	; uint16_t
//@ 		push	ds
//@ 		mov	ds, ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 378
//@ 
//@ loc_32640:				; CODE XREF: NextMonoBlock+172j
//@ 		mov	al, [si]
//@ 		imul	bl		; Signed Multiply
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 379
//@ 		add	es:[di], ah	; Add
//@ 		jno	short loc_32652	; Jump if Not Overflow (OF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 380
//@ 		shr	ah, 7		; Shift	Logical	Right
//@ 		add	ah, 7Fh	; ''   ; Add
//@ 		mov	es:[di], ah
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 381
//@ 
//@ loc_32652:				; CODE XREF: NextMonoBlock+164j
//@ 		inc	di		; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 382
//@ 		inc	si		; Increment by 1
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_32640	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 383
//@ 		pop	ds
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 385
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+6] ; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 386
//@ 		mov	ax, es:[di+6]
//@ 		cmp	ax, es:[di+4]	; Compare Two Operands
//@ 		jb	short loc_32687	; Jump if Below	(CF=1)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 387
//@ 		cmp	SFXC, 0		; uint16_t
//@ 		jnz	short loc_32678	; Jump if Not Zero (ZF=0)
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		jmp	short loc_32687	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 388
//@ 
//@ loc_32678:				; CODE XREF: NextMonoBlock+18Bj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 389
//@ 
//@ loc_32687:				; CODE XREF: NextMonoBlock+7Bj
//@ 					; NextMonoBlock+184j ...
//@ 		cmp	SFXC, 0Fh	; uint16_t
//@ 		jz	short loc_32691	; Jump if Zero (ZF=1)
//@ 		jmp	loc_32541	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 392
//@ 
//@ loc_32691:				; CODE XREF: NextMonoBlock+1A9j
//@ 		mov	cx, 200h
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		mov	es, ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		mov	ax, 8080h
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 393
//@ 
//@ loc_3269E:				; CODE XREF: NextMonoBlock+1C1j
//@ 		add	es:[di], ax	; Add
//@ 		inc	di		; Increment by 1
//@ 		inc	di		; Increment by 1
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_3269E	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 396
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		mov	dl, es:[di]
//@ 		mov	ax, SFXDMASeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 397
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ NextMonoBlock	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 406
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ IRQ_Handler	proc far
//@ 		pusha			; Push all General Registers
//@ 		push	ds
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 407
//@ 		mov	ax, seg	dseg11
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 408
//@ 		mov	ds, ax
//@ 		push	es
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 410
//@ 		mov	al, 20h	; ' '
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 411
//@ 		out	20h, al		; Interrupt controller,	8259A.
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 412
//@ 		out	0A0h, al	; PIC 2	 same as 0020 for PIC 1
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 413
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 415
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 416
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_326D9	; Jump if Not Zero (ZF=0)
//@ 		call	NextMonoBlock	; function far PASCAL returns void
//@ 		jmp	short loc_326ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 417
//@ 
//@ loc_326D9:				; CODE XREF: IRQ_Handler+14j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_326E4	; Jump if Not Zero (ZF=0)
//@ 		call	NextStereoBlock	; function far PASCAL returns void
//@ 		jmp	short loc_326ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 418
//@ 
//@ loc_326E4:				; CODE XREF: IRQ_Handler+1Fj
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_326ED	; Jump if Not Zero (ZF=0)
//@ 		call	NextStereoBlock16 ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 420
//@ 
//@ loc_326ED:				; CODE XREF: IRQ_Handler+1Bj
//@ 					; IRQ_Handler+26j ...
//@ 		pop	es
//@ 		pop	ds
//@ 		popa			; Pop all General Registers
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 422
//@ 		iret			; Interrupt Return
//@ IRQ_Handler	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 423
//@ 		db 0CBh	; Ë
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 433
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ TestSBlaster	proc far		; CODE XREF: RegisterCard:loc_3389BP
//@ 
//@ TestSBlaster	= byte ptr -1		; bool
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 434
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	dx, ax
//@ 		mov	al, 1
//@ 		out	dx, al
//@ 		push	32h ; '2'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 435
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al
//@ 		push	14h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 436
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$1, ax		; int16_t
//@ 		jmp	short loc_32725	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32721:				; CODE XREF: TestSBlaster+59j
//@ 		inc	n$1		; int16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 437
//@ 
//@ loc_32725:				; CODE XREF: TestSBlaster+2Dj
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Eh		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_32745	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 438
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Ah		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		cmp	al, 0AAh ; 'ª'  ; Compare Two Operands
//@ 		jnz	short loc_32745	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+TestSBlaster], 1 ; bool
//@ 
//@ loc_32745:				; CODE XREF: TestSBlaster+40j
//@ 					; TestSBlaster+4Dj
//@ 		cmp	n$1, 0FFh	; int16_t
//@ 		jnz	short loc_32721	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 440
//@ 		push	0FFE1h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 441
//@ 		call	ReadDSP		; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	sbDSPver, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 442
//@ 		call	ReadDSP		; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		imul	ax, sbDSPver, 64h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		mov	sbDSPver, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 444
//@ 		cmp	sCard, 4	; uint8_t
//@ 		jnz	short loc_32784	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 445
//@ 		cmp	sbDSPver, 190h	; uint16_t
//@ 		jnb	short loc_32784	; Jump if Not Below (CF=0)
//@ 		mov	[bp+TestSBlaster], 0 ; bool
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 446
//@ 
//@ loc_32784:				; CODE XREF: TestSBlaster+84j
//@ 					; TestSBlaster+8Cj
//@ 		mov	al, [bp+TestSBlaster] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ TestSBlaster	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 455
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetDosPage	proc far		; CODE XREF: InitDMABuffers+3BP
//@ 
//@ W		= word ptr -0Ah		; uint16_t
//@ La		= word ptr -8		; int32_t
//@ var_6		= word ptr -6
//@ L		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ arg_0		= word ptr  6
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 456
//@ 		push	0
//@ 		push	2000h
//@ 		call	GlobalDosAlloc	; Call Procedure
//@ 		mov	[bp+L],	ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 457
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		and	ax, 0FFFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	SFXDMASeg, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 458
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+W],	ax	; uint16_t
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	[bp+La], ax	; int32_t
//@ 		mov	[bp+var_6], dx
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 459
//@ 		mov	ax, [bp+La]	; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	SFXPage, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 461
//@ 		mov	ax, [bp+La]	; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		add	ax, 2000h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, SFXPage	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_3281A	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_32880	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 463
//@ 
//@ loc_3281A:				; CODE XREF: GetDosPage+8Bj
//@ 		push	0
//@ 		push	2000h
//@ 		call	GlobalDosAlloc	; Call Procedure
//@ 		mov	[bp+L],	ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 464
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		and	ax, 0FFFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	SFXDMASeg, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 465
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+W],	ax	; uint16_t
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	[bp+La], ax	; int32_t
//@ 		mov	[bp+var_6], dx
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 466
//@ 		mov	ax, [bp+La]	; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	SFXPage, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 469
//@ 
//@ loc_32880:				; CODE XREF: GetDosPage+8Fj
//@ 		mov	ax, [bp+La]	; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		add	ax, 2000h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, SFXPage	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_328A7	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_328AE	; Jump if Zero (ZF=1)
//@ 
//@ loc_328A7:				; CODE XREF: GetDosPage+118j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		call	far ptr	@Halt$q4Word ; Halt(exitcode: Word{AX})
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 471
//@ 
//@ loc_328AE:				; CODE XREF: GetDosPage+11Cj
//@ 		cmp	sCard, 4	; uint8_t
//@ 		jnz	short loc_328D1	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+La]	; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		and	ax, 0FFFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	SFXPageOfs, ax	; uint16_t
//@ 		jmp	short loc_328E1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 472
//@ 
//@ loc_328D1:				; CODE XREF: GetDosPage+12Aj
//@ 		mov	ax, [bp+La]	; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		and	ax, 0FFFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	SFXPageOfs, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 473
//@ 
//@ loc_328E1:				; CODE XREF: GetDosPage+146j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	dx, SFXDMASeg	; uint16_t
//@ 		mov	word ptr SFXDMABuf, ax ; void*
//@ 		mov	word ptr SFXDMABuf+2, dx ; void*
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 474
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXBOfs, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 475
//@ 		mov	di, offset SFXBuf ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16$0	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 476
//@ 		les	di, SFXBuf	; void*
//@ 		mov	ax, es
//@ 		mov	SFXBufSeg, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 478
//@ 		cmp	sCard, 4	; uint8_t
//@ 		jnz	short loc_3291A	; Jump if Not Zero (ZF=0)
//@ 		mov	di, [bp+arg_0]
//@ 		mov	byte ptr ss:[di+La+1], 0 ; int32_t
//@ 		jmp	short loc_32922	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 479
//@ 
//@ loc_3291A:				; CODE XREF: GetDosPage+185j
//@ 		mov	di, [bp+arg_0]
//@ 		mov	byte ptr ss:[di+La+1], 80h ; '€' ; int32_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 481
//@ 
//@ loc_32922:				; CODE XREF: GetDosPage+18Fj
//@ 		les	di, SFXDMABuf	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	2000h
//@ 		mov	di, [bp+arg_0]
//@ 		mov	al, byte ptr ss:[di+La+1] ; int32_t
//@ 		push	ax
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 482
//@ 		les	di, SFXBuf	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		mov	di, [bp+arg_0]
//@ 		mov	al, byte ptr ss:[di+La+1] ; int32_t
//@ 		push	ax
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 483
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ GetDosPage	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 486
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitDMABuffers	proc far		; CODE XREF: InitSb+3P
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 487
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 488
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_3296B	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 489
//@ 		mov	SFXLen,	3FFh	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 490
//@ 		mov	TimeRate, 9Ch ;	'œ' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 491
//@ 		jmp	short loc_3298C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 492
//@ 
//@ loc_3296B:				; CODE XREF: InitDMABuffers+9j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_3297D	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 493
//@ 		mov	SFXLen,	7FFh	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 494
//@ 		mov	TimeRate, 0CFh ; 'Ï' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 495
//@ 		jmp	short loc_3298C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 496
//@ 
//@ loc_3297D:				; CODE XREF: InitDMABuffers+1Bj
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_3298C	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 497
//@ 		mov	SFXLen,	7FFh	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 498
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	TimeRate, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 501
//@ 
//@ loc_3298C:				; CODE XREF: InitDMABuffers+17j
//@ 					; InitDMABuffers+29j ...
//@ 		push	bp
//@ 		call	GetDosPage	; function nested far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 502
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitDMABuffers	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 506
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitMixerChip	proc far		; CODE XREF: InitSb+FP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 509
//@ 		push	22h ; '"'
//@ 		push	0FFFFh
//@ 		call	WriteMixer	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 511
//@ 		push	4
//@ 		push	0FFFFh
//@ 		call	WriteMixer	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 513
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jnz	short loc_329BB	; Jump if Not Zero (ZF=0)
//@ 		push	0Eh
//@ 		push	0
//@ 		call	WriteMixer	; function far PASCAL returns void
//@ 		jmp	short locret_329C4 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 514
//@ 
//@ loc_329BB:				; CODE XREF: InitMixerChip+1Aj
//@ 		push	0Eh
//@ 		push	2
//@ 		call	WriteMixer	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 516
//@ 
//@ locret_329C4:				; CODE XREF: InitMixerChip+25j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitMixerChip	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 520
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitSb		proc far		; CODE XREF: InitSoundSystem:loc_33B80P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 521
//@ 		call	InitDMABuffers	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 523
//@ 		cmp	sCard, 3	; uint8_t
//@ 		jb	short loc_329DA	; Jump if Below	(CF=1)
//@ 		call	InitMixerChip	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 524
//@ 
//@ loc_329DA:				; CODE XREF: InitSb+Dj
//@ 		cmp	sIRQ, 8		; uint8_t
//@ 		jnb	short loc_329EE	; Jump if Not Below (CF=0)
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 8		; Add
//@ 		mov	intN, al	; uint8_t
//@ 		jmp	short loc_329FC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 525
//@ 
//@ loc_329EE:				; CODE XREF: InitSb+19j
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 70h	; 'p'   ; Add
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		mov	intN, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 527
//@ 
//@ loc_329FC:				; CODE XREF: InitSb+26j
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 528
//@ 		mov	al, intN	; uint8_t
//@ 		push	ax
//@ 		mov	di, offset Old_IRQ ; void (*)()
//@ 		push	ds
//@ 		push	di
//@ 		call	@GetIntVec$q4Bytem7Pointer ; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 529
//@ 		mov	al, intN	; uint8_t
//@ 		push	ax
//@ 		mov	di, 0DECh
//@ 		mov	ax, seg	cseg09
//@ 		push	ax
//@ 		push	di
//@ 		call	@SetIntVec$q4Byte7Pointer ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 530
//@ 		call	EnableSFXIRQ	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 531
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 533
//@ 		cmp	sCard, 4	; uint8_t
//@ 		jnz	short loc_32A30	; Jump if Not Zero (ZF=0)
//@ 		call	programDSP16bit	; function far PASCAL returns void
//@ 		jmp	short locret_32A35 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 534
//@ 
//@ loc_32A30:				; CODE XREF: InitSb+61j
//@ 		call	ProgramDSP8bit	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 535
//@ 
//@ locret_32A35:				; CODE XREF: InitSb+68j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitSb		endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 540
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DeInitSB	proc far		; CODE XREF: DeInitSoundSystem:loc_33BA9P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 541
//@ 		mov	ax, word ptr Old_IRQ ; void (*)()
//@ 		or	ax, word ptr Old_IRQ+2 ; void (*)()
//@ 		jz	short loc_32A54	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 542
//@ 		mov	al, intN	; uint8_t
//@ 		push	ax
//@ 		push	word ptr Old_IRQ+2 ; void (*)()
//@ 		push	word ptr Old_IRQ ; void	(*)()
//@ 		call	@SetIntVec$q4Byte7Pointer ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 544
//@ 
//@ loc_32A54:				; CODE XREF: DeInitSB+Aj
//@ 		call	DisableSFXIRQ	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 545
//@ 		push	0FFD3h
//@ 		call	WriteToDSP	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 546
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 4		; Add
//@ 		out	0Ah, al		; DMA controller, 8237A-5.
//@ 					; single mask bit register
//@ 					; 0-1: select channel (00=0; 01=1; 10=2; 11=3)
//@ 					; 2: 1=set mask	for channel; 0=clear mask (enable)
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 547
//@ 		call	ResetDSP	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"SOUNDIP\SOUND_SB.PAS" 548
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DeInitSB	endp
//@ 
