
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

#include "csbrif.h"

//@ ; #line	"CSBRIF.PAS" 61
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DeInitBrifing	proc near		; CODE XREF: PlayBrifing+508p
//@ 
//@ var_8		= dword	ptr -8
//@ i		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 62
//@ 		mov	di, offset BrText ; char*
//@ 		push	ds
//@ 		push	di
//@ 		push	1700h
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 63
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_F04D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_F04A:				; CODE XREF: DeInitBrifing+55j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSBRIF.PAS" 64
//@ 
//@ loc_F04D:				; CODE XREF: DeInitBrifing+16j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		add	ax, 118h	; Add
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSBRIF.PAS" 65
//@ 		mov	ax, es:[di]
//@ 		or	ax, es:[di+2]	; Logical Inclusive OR
//@ 		jz	short loc_F083	; Jump if Zero (ZF=1)
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ 
//@ loc_F083:				; CODE XREF: DeInitBrifing+37j
//@ 		cmp	[bp+n],	3	; int16_t
//@ 		jnz	short loc_F04A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 66
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_F093	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_F090:				; CODE XREF: DeInitBrifing+124j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSBRIF.PAS" 67
//@ 
//@ loc_F093:				; CODE XREF: DeInitBrifing+5Cj
//@ 		imul	di, [bp+n], 70h	; int16_t
//@ 		add	di, 42Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSBRIF.PAS" 68
//@ 		mov	ax, es:[di+8]
//@ 		or	ax, es:[di+0Ah]	; Logical Inclusive OR
//@ 		jnz	short loc_F0B0	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_F150	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 70
//@ 
//@ loc_F0B0:				; CODE XREF: DeInitBrifing+79j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_F0BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_F0B7:				; CODE XREF: DeInitBrifing+DEj
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSBRIF.PAS" 71
//@ 
//@ loc_F0BA:				; CODE XREF: DeInitBrifing+83j
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+0Ch]
//@ 		or	ax, es:[di+0Eh]	; Logical Inclusive OR
//@ 		jz	short loc_F10C	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 72
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4Ch]
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+8]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+4800h] ; Unsigned Multiplication of AL or AX
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 
//@ loc_F10C:				; CODE XREF: DeInitBrifing+9Bj
//@ 		cmp	[bp+i],	0Fh	; int16_t
//@ 		jnz	short loc_F0B7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 73
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+8]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4804h],	0 ; Compare Two	Operands
//@ 		jbe	short loc_F13F	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+8]	; Load Full Pointer to ES:xx
//@ 		add	di, 4806h	; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4804h]
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 74
//@ 
//@ loc_F13F:				; CODE XREF: DeInitBrifing+EDj
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, 8		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 75
//@ 
//@ loc_F150:				; CODE XREF: DeInitBrifing+7Bj
//@ 		cmp	[bp+n],	3	; int16_t
//@ 		jz	short loc_F159	; Jump if Zero (ZF=1)
//@ 		jmp	loc_F090	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 76
//@ 
//@ loc_F159:				; CODE XREF: DeInitBrifing+122j
//@ 		mov	di, offset BrifBar ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	4380h
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 77
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DeInitBrifing	endp
//@ 
//@ ; #line	"CSBRIF.PAS" 84
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReinitBrifView	proc near		; CODE XREF: PlayBrifing+122p
//@ 
//@ wc		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 85
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 86
//@ 		mov	ax, WinCY	; uint16_t
//@ 		mov	[bp+wc], ax	; int16_t
//@ ; #line	"CSBRIF.PAS" 87
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	WinH, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 89
//@ 		mov	ax, WinH	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	WinH2u,	ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 90
//@ 		mov	ax, WinH	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinH2d,	ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 92
//@ 		mov	ax, WinCY	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinB, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 93
//@ 		mov	ax, WinCY	; uint16_t
//@ 		add	ax, WinH2d	; uint16_t
//@ 		mov	WinE, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 95
//@ 		mov	ax, WinCY	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinSY, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 96
//@ 		mov	ax, WinCY	; uint16_t
//@ 		add	ax, WinH2d	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	WinEY, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 98
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WinSX, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 99
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	WinEX, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 100
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ReinitBrifView	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aSfxBrif	db 9,'SFX\BRIF\'        ; DATA XREF: LoadVoice+9Co
//@ a_wav		db 4,'.wav'             ; DATA XREF: LoadVoice:loc_F2CEo
//@ ; #line	"CSBRIF.PAS" 109
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadVoice	proc near		; CODE XREF: ExecNextCommand+EDp
//@ 
//@ var_208		= byte ptr -208h
//@ var_10C		= dword	ptr -10Ch
//@ sg		= word ptr -108h	; uint16_t
//@ n		= word ptr -106h	; uint16_t
//@ WSize		= word ptr -104h	; int32_t
//@ var_102		= word ptr -102h
//@ FName		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ Car		= word ptr  8		; int16_t
//@ 
//@ 		enter	208h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSBRIF.PAS" 110
//@ 		cmp	GoSkip,	0	; bool
//@ 		jz	short loc_F211	; Jump if Zero (ZF=1)
//@ 		jmp	locret_F3EF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 112
//@ 
//@ loc_F211:				; CODE XREF: LoadVoice+20j
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		cmp	[bp+FName], 0	; char[256] // Pascal string
//@ 		jnz	short loc_F23A	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_F3EF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 113
//@ 
//@ loc_F23A:				; CODE XREF: LoadVoice+49j
//@ 		imul	di, [bp+Car], 0Eh ; int16_t
//@ 		mov	word ptr [di-878h], 0FFh
//@ ; #line	"CSBRIF.PAS" 114
//@ 		mov	ax, [bp+Car]	; int16_t
//@ 		add	ax, 118h	; Add
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10C], di
//@ 		mov	word ptr [bp+var_10C+2], es
//@ ; #line	"CSBRIF.PAS" 115
//@ 		mov	ax, es:[di]
//@ 		or	ax, es:[di+2]	; Logical Inclusive OR
//@ 		jz	short loc_F27D	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 116
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 		les	di, [bp+var_10C] ; Load	Full Pointer to	ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSBRIF.PAS" 118
//@ 
//@ loc_F27D:				; CODE XREF: LoadVoice+76j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSfxBrif ; "SFX\\BRIF\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 119
//@ 		mov	ax, word ptr F.Size ; struct BFile
//@ 		mov	dx, word ptr F.Size+2 ;	struct BFile
//@ 		mov	[bp+WSize], ax	; int32_t
//@ 		mov	[bp+var_102], dx
//@ ; #line	"CSBRIF.PAS" 121
//@ 		cmp	[bp+var_102], 0	; Compare Two Operands
//@ 		jg	short loc_F2C2	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_F2CE	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+WSize], 0FBF4h ; int32_t
//@ 		jbe	short loc_F2CE	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_F2C2:				; CODE XREF: LoadVoice+CAj
//@ 		mov	[bp+WSize], 0FBF4h ; int32_t
//@ 		mov	[bp+var_102], 0
//@ ; #line	"CSBRIF.PAS" 123
//@ 
//@ loc_F2CE:				; CODE XREF: LoadVoice+CCj
//@ 					; LoadVoice+D4j
//@ 		mov	di, offset a_wav ; ".wav"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_F306	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 124
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	28h ; '('
//@ 		call	FSeek		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+WSize]	; int32_t
//@ 		push	ss
//@ 		push	di
//@ 		push	4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSBRIF.PAS" 126
//@ 
//@ loc_F306:				; CODE XREF: LoadVoice+F4j
//@ 		cmp	[bp+var_102], 0	; Compare Two Operands
//@ 		jg	short loc_F317	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_F323	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+WSize], 0FBF4h ; int32_t
//@ 		jbe	short loc_F323	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_F317:				; CODE XREF: LoadVoice+11Fj
//@ 		mov	[bp+WSize], 0FBF4h ; int32_t
//@ 		mov	[bp+var_102], 0
//@ ; #line	"CSBRIF.PAS" 128
//@ 
//@ loc_F323:				; CODE XREF: LoadVoice+121j
//@ 					; LoadVoice+129j
//@ 		mov	ax, [bp+Car]	; int16_t
//@ 		add	ax, 118h	; Add
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10C], di
//@ 		mov	word ptr [bp+var_10C+2], es
//@ ; #line	"CSBRIF.PAS" 130
//@ 		mov	ax, [bp+WSize]	; int32_t
//@ 		mov	dx, [bp+var_102]
//@ 		add	ax, 3FFh	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		les	di, [bp+var_10C] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSBRIF.PAS" 131
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 132
//@ 		les	di, [bp+var_10C] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_10C] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSBRIF.PAS" 133
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_10C] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+WSize]	; int32_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSBRIF.PAS" 134
//@ 		les	di, [bp+var_10C] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+sg], ax	; uint16_t
//@ 		mov	ax, [bp+WSize]	; int32_t
//@ 		mov	[bp+n],	ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 135
//@ 		les	di, [bp+var_10C] ; Load	Full Pointer to	ES:xx
//@ 		mov	word ptr es:[di+6], 78h	; 'x'
//@ ; #line	"CSBRIF.PAS" 137
//@ 		mov	cx, [bp+n]	; uint16_t
//@ ; #line	"CSBRIF.PAS" 138
//@ 		mov	ax, [bp+sg]	; uint16_t
//@ ; #line	"CSBRIF.PAS" 139
//@ 		mov	es, ax
//@ ; #line	"CSBRIF.PAS" 140
//@ 		xor	di, di		; Logical Exclusive OR
//@ ; #line	"CSBRIF.PAS" 141
//@ 
//@ loc_F3CB:				; CODE XREF: LoadVoice+1E4j
//@ 		sub	byte ptr es:[di], 80h ;	'Ä' ; Integer Subtraction
//@ ; #line	"CSBRIF.PAS" 142
//@ 		inc	di		; Increment by 1
//@ ; #line	"CSBRIF.PAS" 143
//@ 		loop	loc_F3CB	; Loop while CX	!= 0
//@ ; #line	"CSBRIF.PAS" 147
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 148
//@ 		push	[bp+Car]	; int16_t
//@ 		push	0
//@ 		push	0
//@ 		mov	ax, [bp+Car]	; int16_t
//@ 		add	ax, 118h	; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 149
//@ 
//@ locret_F3EF:				; CODE XREF: LoadVoice+22j
//@ 					; LoadVoice+4Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ LoadVoice	endp
//@ 
//@ ; #line	"CSBRIF.PAS" 153
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StopSounds	proc near		; CODE XREF: PlayBrifing+170p
//@ 					; PlayBrifing+4E2p ...
//@ 
//@ var_2		= word ptr -2
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 154
//@ 		mov	al, MaxVoice	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_2], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jg	short locret_F422 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_F40F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_F40B:				; CODE XREF: StopSounds+2Dj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_F40F:				; CODE XREF: StopSounds+16j
//@ 		imul	di, n$0, 0Eh	; int16_t
//@ 		mov	word ptr [di-878h], 0FFh
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jnz	short loc_F40B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 155
//@ 
//@ locret_F422:				; CODE XREF: StopSounds+11j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ StopSounds	endp
//@ 
//@ ; #line	"CSBRIF.PAS" 158
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetAni		proc near		; CODE XREF: ExecNextCommand+121p
//@ 					; ExecNextCommand+161p
//@ 
//@ a		= word ptr  4		; int16_t
//@ c		= word ptr  6		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 159
//@ 		cmp	GoSkip,	0	; bool
//@ 		jz	short loc_F431	; Jump if Zero (ZF=1)
//@ 		jmp	short locret_F44B ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 160
//@ 
//@ loc_F431:				; CODE XREF: SetAni+9j
//@ 		imul	di, [bp+c], 70h	; int16_t
//@ 		add	di, 42Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSBRIF.PAS" 161
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6Eh], ax
//@ 		mov	ax, [bp+a]	; int16_t
//@ 		add	ax, 8		; Add
//@ 		mov	es:[di+6Ch], ax
//@ ; #line	"CSBRIF.PAS" 162
//@ 
//@ locret_F44B:				; CODE XREF: SetAni+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ SetAni		endp
//@ 
//@ ; #line	"CSBRIF.PAS" 165
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddText		proc near		; CODE XREF: ExecNextCommand+191p
//@ 
//@ var_200		= byte ptr -200h
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ 
//@ 		enter	200h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		assume es:nothing
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSBRIF.PAS" 166
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 167
//@ 		dec	[bp+s]		; char[256] // Pascal string
//@ ; #line	"CSBRIF.PAS" 168
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	2
//@ 		push	2Ch ; ','
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 169
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		imul	ax, CurLine, 2Eh ; int16_t
//@ 		les	di, BrText	; char*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2Dh ; '-'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 170
//@ 		inc	CurLine		; int16_t
//@ ; #line	"CSBRIF.PAS" 171
//@ 		mov	ax, CurTop	; int16_t
//@ 		add	ax, 5		; Add
//@ 		cmp	ax, CurLine	; int16_t
//@ 		jge	short locret_F4DE ; Jump if Greater or Equal (SF=OF)
//@ 		inc	CurTop		; int16_t
//@ ; #line	"CSBRIF.PAS" 172
//@ 
//@ locret_F4DE:				; CODE XREF: AddText+89j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ AddText		endp
//@ 
//@ ; #line	"CSBRIF.PAS" 177
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReadRealMul	proc near		; CODE XREF: ExecNextCommand+ACp
//@ 					; ExecNextCommand+219p
//@ 
//@ r		= word ptr -6		; real_t
//@ var_4		= word ptr -4
//@ var_2		= word ptr -2
//@ m		= word ptr  4		; real_t
//@ arg_2		= word ptr  6
//@ arg_4		= word ptr  8
//@ I		= dword	ptr  0Ah	; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 178
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text4Real ; Read(var f; var v:	Real{DX:BX:AX})
//@ 		mov	[bp+r],	ax	; real_t
//@ 		mov	[bp+var_4], bx
//@ 		mov	[bp+var_2], dx
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSBRIF.PAS" 179
//@ 		mov	ax, [bp+r]	; real_t
//@ 		mov	bx, [bp+var_4]
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, [bp+m]	; real_t
//@ 		mov	si, [bp+arg_2]
//@ 		mov	di, [bp+arg_4]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		les	di, [bp+I]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSBRIF.PAS" 180
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ ReadRealMul	endp
//@ 
//@ ; #line	"CSBRIF.PAS" 184
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ ; Attributes: bp-based frame
//@ 
//@ ReadCommand	proc near		; CODE XREF: LoadCharacter+63p
//@ 					; LoadSetup+Ap	...
//@ 
//@ var_302		= byte ptr -302h
//@ var_202		= byte ptr -202h
//@ S		= byte ptr -102h	; char[256] // Pascal string
//@ C		= byte ptr -1		; char
//@ ReadCommand	= dword	ptr  4		; char[256] // Pascal string
//@ 
//@ 		enter	302h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 185
//@ 		mov	[bp+S],	0	; char[256] // Pascal string
//@ ; #line	"CSBRIF.PAS" 187
//@ 
//@ loc_F52D:				; CODE XREF: ReadCommand+B9j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text4Char ; Read(var f; var c:	Char{AL})
//@ 		mov	[bp+C],	al	; char
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSBRIF.PAS" 188
//@ 		cmp	[bp+C],	3Bh ; ';' ; char
//@ 		jnz	short loc_F571	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		pop	di
//@ 		pop	es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_F571	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 189
//@ 		mov	[bp+S],	0	; char[256] // Pascal string
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	[bp+C],	20h ; ' ' ; char
//@ ; #line	"CSBRIF.PAS" 190
//@ 
//@ loc_F571:				; CODE XREF: ReadCommand+1Fj
//@ 					; ReadCommand+38j
//@ 		mov	al, [bp+C]	; char
//@ 		push	ax
//@ 		call	LoCase		; function far PASCAL returns PASCAL character 'Char'
//@ 		mov	[bp+C],	al	; char
//@ 		lea	di, [bp+var_302] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, [bp+C]	; char
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 191
//@ 		cmp	[bp+C],	20h ; ' ' ; char
//@ 		jnz	short loc_F5CF	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		pop	di
//@ 		pop	es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_F5E0	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_F5CF:				; CODE XREF: ReadCommand+90j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Eoln$qm4Text	; Eoln(var f: Text): Boolean{AL}
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_F5E0	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_F52D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 192
//@ 
//@ loc_F5E0:				; CODE XREF: ReadCommand+A9j
//@ 					; ReadCommand+B7j
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 193
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+ReadCommand] ; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 194
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ReadCommand	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aModel		db 5,'model'            ; DATA XREF: LoadCharacter+77o
//@ aPosition	db 8,'position'         ; DATA XREF: LoadCharacter+B2o
//@ aIdle		db 4,'idle'             ; DATA XREF: LoadCharacter+F8o
//@ aBrif		db 5,'brif\'            ; DATA XREF: LoadCharacter+129o
//@ 					; LoadCharacter+1B4o
//@ aAni		db 3,'ani'              ; DATA XREF: LoadCharacter+17Fo
//@ aEnd		db 4,'end;'             ; DATA XREF: LoadCharacter+20Ao
//@ ; #line	"CSBRIF.PAS" 198
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadCharacter	proc near		; CODE XREF: LoadSetup+2Ap
//@ 
//@ var_20A		= byte ptr -20Ah
//@ var_10A		= byte ptr -10Ah
//@ var_A		= dword	ptr -0Ah
//@ ddfi		= word ptr -6		; int16_t
//@ i		= word ptr -4		; int16_t
//@ MD		= word ptr -2		; int16_t
//@ 
//@ 		enter	20Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 199
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+MD], ax	; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		imul	di, [bp+MD], 70h ; int16_t
//@ 		add	di, 42Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CSBRIF.PAS" 201
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6Ch], ax
//@ ; #line	"CSBRIF.PAS" 202
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6Eh], ax
//@ ; #line	"CSBRIF.PAS" 203
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSBRIF.PAS" 204
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_F679	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_F676:				; CODE XREF: LoadCharacter+5Bj
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_F679:				; CODE XREF: LoadCharacter+3Dj
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Ch], ax
//@ 		mov	es:[di+0Eh], ax
//@ 		cmp	[bp+i],	0Fh	; int16_t
//@ 		jnz	short loc_F676	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 206
//@ 
//@ loc_F694:				; CODE XREF: LoadCharacter+216j
//@ 		lea	di, [bp+var_10A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 208
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aModel ; "model"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F6E4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 209
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, 8		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPOH		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 211
//@ 
//@ loc_F6E4:				; CODE XREF: LoadCharacter+81j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aPosition ; "position"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F72A	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+ddfi], ax	; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSBRIF.PAS" 213
//@ 
//@ loc_F72A:				; CODE XREF: LoadCharacter+BCj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aIdle ; "idle"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F7B1	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 215
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSBRIF.PAS" 216
//@ 		lea	di, [bp+var_20A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aBrif ; "brif\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_10A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4800h]
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 4Ch	; 'L'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadAnimation	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 219
//@ 
//@ loc_F7B1:				; CODE XREF: LoadCharacter+102j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aAni	; "ani"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F83C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 221
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		add	[bp+i],	8	; int16_t
//@ ; #line	"CSBRIF.PAS" 222
//@ 		lea	di, [bp+var_20A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aBrif ; "brif\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_10A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4800h]
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 4Ch	; 'L'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadAnimation	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 225
//@ 
//@ loc_F83C:				; CODE XREF: LoadCharacter+189j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aEnd	; "end;"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_F850	; Jump if Zero (ZF=1)
//@ 		jmp	loc_F694	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 226
//@ 
//@ loc_F850:				; CODE XREF: LoadCharacter+214j
//@ 		mov	ax, [bp+ddfi]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 89h	; 'â'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 3400h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 90h	; 'ê'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7FFFh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSBRIF.PAS" 228
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadCharacter	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aCharacter	db 9,'character'        ; DATA XREF: LoadSetup+1Eo
//@ aAmbient	db 8,'ambient:'         ; DATA XREF: LoadSetup+32o
//@ aRoom		db 5,'room:'            ; DATA XREF: LoadSetup+5Eo
//@ aCamera		db 7,'camera:'          ; DATA XREF: LoadSetup+81o
//@ aAction		db 7,'#action'          ; DATA XREF: LoadSetup+FBo
//@ ; #line	"CSBRIF.PAS" 231
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadSetup	proc near		; CODE XREF: PlayBrifing+188p
//@ 
//@ var_100		= byte ptr -100h
//@ 
//@ 		enter	100h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 233
//@ 
//@ loc_F8AE:				; CODE XREF: LoadSetup+107j
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 234
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCharacter ;	"character"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F8D7	; Jump if Not Zero (ZF=0)
//@ 		call	LoadCharacter	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 235
//@ 
//@ loc_F8D7:				; CODE XREF: LoadSetup+28j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aAmbient ; "ambient:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F903	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 237
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	i, ax		; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSBRIF.PAS" 238
//@ 		push	i		; int16_t
//@ 		call	SetAmbient	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 240
//@ 
//@ loc_F903:				; CODE XREF: LoadSetup+3Cj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aRoom ; "room:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F926	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 242
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	Room, ax	; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSBRIF.PAS" 244
//@ 
//@ loc_F926:				; CODE XREF: LoadSetup+68j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCamera ; "camera:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_F9A0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 247
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	Camera.camx, ax	; struct Camera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	Camera.camy, ax	; struct Camera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	Camera.CamZ, ax	; struct Camera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	i, ax		; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSBRIF.PAS" 248
//@ 		mov	ax, i		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 89h	; 'â'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 3400h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 90h	; 'ê'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7FFFh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	Camera.camfi, ax ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 249
//@ 		mov	ax, Camera.CamZ	; struct Camera$Type
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	Camera.CamZ, ax	; struct Camera$Type
//@ 		add	Camera.camfi, 8000h ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 250
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Camera.MvTime, ax ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 252
//@ 
//@ loc_F9A0:				; CODE XREF: LoadSetup+8Bj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aAction ; "#action"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short locret_F9B4 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_F8AE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 253
//@ 
//@ locret_F9B4:				; CODE XREF: LoadSetup+105j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadSetup	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_F9B6	db 1,':'                ; DATA XREF: GotoProc+38o
//@ ; #line	"CSBRIF.PAS" 257
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GotoProc	proc near		; CODE XREF: ExecNextCommand+88p
//@ 
//@ var_400		= byte ptr -400h
//@ var_300		= byte ptr -300h
//@ lname		= byte ptr -200h	; char[256] // Pascal string
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ 
//@ 		enter	400h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 258
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+lname]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+var_400] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+lname]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StLocase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset asc_F9B6 ; ":"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+lname]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSBRIF.PAS" 260
//@ 
//@ loc_FA08:				; CODE XREF: GotoProc+ADj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	StLocase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 261
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Eof$qm4Text	; Eof(var f: Text): Boolean{AL}
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short locret_FA67 ; Jump if Not	Zero (ZF=0)
//@ 		lea	di, [bp+lname]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_FA08	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 262
//@ 
//@ locret_FA67:				; CODE XREF: GotoProc+98j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ GotoProc	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aEnd_		db 5,'#end.'            ; DATA XREF: ExecNextCommand+25o
//@ aWait_key	db 8,'wait_key'         ; DATA XREF: ExecNextCommand+3Co
//@ aWait_voice	db 10,'wait_voice'      ; DATA XREF: ExecNextCommand+53o
//@ aGoto		db 4,'goto'             ; DATA XREF: ExecNextCommand+7Co
//@ aDelay		db 5,'delay'            ; DATA XREF: ExecNextCommand+90o
//@ aVoice		db 5,'voice'            ; DATA XREF: ExecNextCommand+BAo
//@ aSetani		db 6,'setani'           ; DATA XREF: ExecNextCommand+F5o
//@ aTurnani	db 7,'turnani'          ; DATA XREF: ExecNextCommand+135o
//@ aSay		db 3,'say'              ; DATA XREF: ExecNextCommand+169o
//@ aMovecamto	db 9,'movecamto'        ; DATA XREF: ExecNextCommand+199o
//@ ; #line	"CSBRIF.PAS" 267
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExecNextCommand	proc near		; CODE XREF: PlayBrifing+213p
//@ 
//@ var_104		= byte ptr -104h
//@ a		= word ptr -4		; int16_t
//@ c		= word ptr -2		; int16_t
//@ 
//@ 		enter	104h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 268
//@ 
//@ loc_FAB5:				; CODE XREF: ExecNextCommand+1Ej
//@ 		lea	di, [bp+var_104] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		cmp	byte ptr Command, 0 ; char[41] // Pascal string
//@ 		jz	short loc_FAB5	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 269
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aEnd_ ; "#end."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FAE8	; Jump if Not Zero (ZF=0)
//@ 		mov	CurState, 0FFFFh ; uint16_t
//@ ; #line	"CSBRIF.PAS" 270
//@ 
//@ loc_FAE8:				; CODE XREF: ExecNextCommand+2Fj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aWait_key ; "wait_key"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FAFF	; Jump if Not Zero (ZF=0)
//@ 		mov	CurState, 2	; uint16_t
//@ ; #line	"CSBRIF.PAS" 271
//@ 
//@ loc_FAFF:				; CODE XREF: ExecNextCommand+46j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aWait_voice ; "wait_voice"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FB28	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	CurVoice, ax	; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	CurState, 4	; uint16_t
//@ ; #line	"CSBRIF.PAS" 272
//@ 
//@ loc_FB28:				; CODE XREF: ExecNextCommand+5Dj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aGoto ; "goto"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FB3C	; Jump if Not Zero (ZF=0)
//@ 		call	GotoProc	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 273
//@ 
//@ loc_FB3C:				; CODE XREF: ExecNextCommand+86j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aDelay ; "delay"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FB66	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset CurDelay ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, 88h	; 'à'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	dx, 0C00h
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul	; function near	PASCAL returns void
//@ 		mov	CurState, 1	; uint16_t
//@ ; #line	"CSBRIF.PAS" 274
//@ 
//@ loc_FB66:				; CODE XREF: ExecNextCommand+9Aj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aVoice ; "voice"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FBA1	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+c],	ax	; int16_t
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		push	[bp+c]		; int16_t
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	LoadVoice	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 275
//@ 
//@ loc_FBA1:				; CODE XREF: ExecNextCommand+C4j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aSetani ; "setani"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FBE1	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+c],	ax	; int16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+a],	ax	; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		push	[bp+c]		; int16_t
//@ 		push	[bp+a]		; int16_t
//@ 		call	SetAni		; function near	PASCAL returns void
//@ 		mov	ax, [bp+c]	; int16_t
//@ 		mov	CurCar,	ax	; int16_t
//@ 		mov	CurState, 3	; uint16_t
//@ ; #line	"CSBRIF.PAS" 276
//@ 
//@ loc_FBE1:				; CODE XREF: ExecNextCommand+FFj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aTurnani ; "turnani"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FC15	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+c],	ax	; int16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+a],	ax	; int16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		push	[bp+c]		; int16_t
//@ 		push	[bp+a]		; int16_t
//@ 		call	SetAni		; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 277
//@ 
//@ loc_FC15:				; CODE XREF: ExecNextCommand+13Fj
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aSay	; "say"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_FC45	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	AddText		; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 278
//@ 
//@ loc_FC45:				; CODE XREF: ExecNextCommand+173j
//@ 		mov	di, offset Command ; char[41] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aMovecamto ;	"movecamto"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short locret_FCD2 ; Jump if Not	Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 281
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	Camera.mvx, ax	; struct Camera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	Camera.mvy, ax	; struct Camera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	Camera.mvz, ax	; struct Camera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+c],	ax	; int16_t
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ 		mov	ax, Camera.mvz	; struct Camera$Type
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	Camera.mvz, ax	; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 282
//@ 		mov	ax, [bp+c]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 89h	; 'â'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 3400h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 90h	; 'ê'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7FFFh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		add	ax, 8000h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	Camera.mvfi, ax	; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 283
//@ 		mov	di, offset Camera.MvTime ; struct Camera$Type
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, 8Dh	; 'ç'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	dx, 0C00h
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul	; function near	PASCAL returns void
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Camera.mvSpeed,	ax ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 285
//@ 
//@ locret_FCD2:				; CODE XREF: ExecNextCommand+1A3j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ExecNextCommand	endp
//@ 
//@ ; #line	"CSBRIF.PAS" 289
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PreProcessBrif	proc near		; CODE XREF: PlayBrifing+209p
//@ 
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 290
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_FCE2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_FCDF:				; CODE XREF: PreProcessBrif+AFj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_FCE2:				; CODE XREF: PreProcessBrif+9j
//@ 		imul	di, [bp+n], 70h	; int16_t
//@ 		add	di, 42Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ 		mov	ax, es:[di+8]
//@ 		or	ax, es:[di+0Ah]	; Logical Inclusive OR
//@ 		jnz	short loc_FCFF	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_FD7D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 292
//@ 
//@ loc_FCFF:				; CODE XREF: PreProcessBrif+26j
//@ 		mov	ax, t1		; uint16_t
//@ 		add	es:[di+6Eh], ax	; Add
//@ ; #line	"CSBRIF.PAS" 293
//@ 		mov	ax, es:[di+6Ch]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4Ch]
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	ax, es:[di+6Eh]	; Compare Two Operands
//@ 		ja	short loc_FD7D	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSBRIF.PAS" 295
//@ 
//@ loc_FD1B:				; CODE XREF: PreProcessBrif+72j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6Ch]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4Ch]
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+6Eh]	; Compare Two Operands
//@ 		ja	short loc_FD48	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, es:[di+6Ch]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4Ch]
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+6Eh], ax	; Integer Subtraction
//@ 		jmp	short loc_FD1B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 296
//@ 
//@ loc_FD48:				; CODE XREF: PreProcessBrif+5Dj
//@ 		cmp	CurState, 3	; uint16_t
//@ 		jnz	short loc_FD5C	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, CurCar	; int16_t
//@ 		cmp	ax, [bp+n]	; int16_t
//@ 		jnz	short loc_FD5C	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 297
//@ 
//@ loc_FD5C:				; CODE XREF: PreProcessBrif+79j
//@ 					; PreProcessBrif+81j ...
//@ 		push	8
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6Ch], ax
//@ 		mov	ax, es:[di+6Ch]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+0Ch]
//@ 		or	ax, es:[di+0Eh]	; Logical Inclusive OR
//@ 		jz	short loc_FD5C	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 299
//@ 
//@ loc_FD7D:				; CODE XREF: PreProcessBrif+28j
//@ 					; PreProcessBrif+45j
//@ 		cmp	[bp+n],	3	; int16_t
//@ 		jz	short locret_FD86 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_FCDF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 300
//@ 
//@ locret_FD86:				; CODE XREF: PreProcessBrif+ADj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ PreProcessBrif	endp
//@ 
//@ ; #line	"CSBRIF.PAS" 304
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessBrif	proc near		; CODE XREF: PlayBrifing:loc_101F6p
//@ 
//@ dt		= word ptr -4		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSBRIF.PAS" 306
//@ 		cmp	Camera.MvTime, 0 ; struct Camera$Type
//@ 		jg	short loc_FD96	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_FF0E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 308
//@ 
//@ loc_FD96:				; CODE XREF: ProcessBrif+9j
//@ 		cmp	Camera.MvTime, 780h ; struct Camera$Type
//@ 		jle	short loc_FDC3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSBRIF.PAS" 310
//@ 		cmp	Camera.mvSpeed,	0 ; struct Camera$Type
//@ 		jnz	short loc_FDAD	; Jump if Not Zero (ZF=0)
//@ 		mov	Camera.mvSpeed,	1 ; struct Camera$Type
//@ 		jmp	short loc_FDB4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_FDAD:				; CODE XREF: ProcessBrif+1Bj
//@ 		mov	ax, t1		; uint16_t
//@ 		add	Camera.mvSpeed,	ax ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 311
//@ 
//@ loc_FDB4:				; CODE XREF: ProcessBrif+23j
//@ 		cmp	Camera.mvSpeed,	20h ; ' ' ; struct Camera$Type
//@ 		jl	short loc_FDC1	; Jump if Less (SF!=OF)
//@ 		mov	Camera.mvSpeed,	20h ; ' ' ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 312
//@ 
//@ loc_FDC1:				; CODE XREF: ProcessBrif+31j
//@ 		jmp	short loc_FDDF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 313
//@ 
//@ loc_FDC3:				; CODE XREF: ProcessBrif+14j
//@ 		cmp	Camera.MvTime, 1C0h ; struct Camera$Type
//@ 		jge	short loc_FDDF	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSBRIF.PAS" 315
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	Camera.mvSpeed,	ax ; struct Camera$Type
//@ 		cmp	Camera.mvSpeed,	2 ; struct Camera$Type
//@ 		jge	short loc_FDDF	; Jump if Greater or Equal (SF=OF)
//@ 		mov	Camera.mvSpeed,	2 ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 318
//@ 
//@ loc_FDDF:				; CODE XREF: ProcessBrif:loc_FDC1j
//@ 					; ProcessBrif+41j ...
//@ 		mov	ax, Camera.mvSpeed ; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	[bp+dt], ax	; int16_t
//@ ; #line	"CSBRIF.PAS" 320
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cmp	ax, Camera.MvTime ; struct Camera$Type
//@ 		jl	short loc_FE1C	; Jump if Less (SF!=OF)
//@ 		mov	ax, Camera.mvx	; struct Camera$Type
//@ 		mov	Camera.camx, ax	; struct Camera$Type
//@ 		mov	ax, Camera.mvy	; struct Camera$Type
//@ 		mov	Camera.camy, ax	; struct Camera$Type
//@ 		mov	ax, Camera.mvfi	; struct Camera$Type
//@ 		mov	Camera.camfi, ax ; struct Camera$Type
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Camera.MvTime, ax ; struct Camera$Type
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Camera.mvSpeed,	ax ; struct Camera$Type
//@ 		jmp	loc_FF0E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 323
//@ 
//@ loc_FE1C:				; CODE XREF: ProcessBrif+73j
//@ 		mov	ax, Camera.MvTime ; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, Camera.mvx	; struct Camera$Type
//@ 		sub	ax, Camera.camx	; struct Camera$Type
//@ 		mul	[bp+dt]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Camera.camx	; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Camera.camx, ax	; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 324
//@ 		mov	ax, Camera.MvTime ; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, Camera.mvy	; struct Camera$Type
//@ 		sub	ax, Camera.camy	; struct Camera$Type
//@ 		mul	[bp+dt]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Camera.camy	; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Camera.camy, ax	; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 325
//@ 		mov	ax, Camera.MvTime ; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, Camera.mvz	; struct Camera$Type
//@ 		sub	ax, Camera.CamZ	; struct Camera$Type
//@ 		mul	[bp+dt]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Camera.CamZ	; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Camera.CamZ, ax	; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 326
//@ 		mov	ax, Camera.MvTime ; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Camera.mvfi	; struct Camera$Type
//@ 		sub	ax, Camera.camfi ; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Camera.camfi ; struct Camera$Type
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Camera.camfi, ax ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 327
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		sub	Camera.MvTime, ax ; struct Camera$Type
//@ ; #line	"CSBRIF.PAS" 331
//@ 
//@ loc_FF0E:				; CODE XREF: ProcessBrif+Bj
//@ 					; ProcessBrif+91j
//@ 		cmp	CurState, 2	; uint16_t
//@ 		jnz	short loc_FF54	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 332
//@ 		cmp	GoSkip,	0	; bool
//@ 		jz	short loc_FF28	; Jump if Zero (ZF=1)
//@ 		mov	GoSkip,	0	; bool
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ 		jmp	short loc_FF54	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 333
//@ 
//@ loc_FF28:				; CODE XREF: ProcessBrif+192j
//@ 		cmp	key, 0		; uint8_t
//@ 		jbe	short loc_FF54	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSBRIF.PAS" 335
//@ 		mov	al, key		; uint8_t
//@ ; #line	"CSBRIF.PAS" 336
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_FF3E	; Jump if Not Zero (ZF=0)
//@ 		mov	CurState, 0FFFFh ; uint16_t
//@ 		jmp	short loc_FF4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 337
//@ 
//@ loc_FF3E:				; CODE XREF: ProcessBrif+1ACj
//@ 		cmp	al, 0Eh		; Compare Two Operands
//@ 		jnz	short loc_FF4A	; Jump if Not Zero (ZF=0)
//@ 		mov	CurState, 0FFFEh ; uint16_t
//@ 		jmp	short loc_FF4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 338
//@ 
//@ loc_FF4A:				; CODE XREF: ProcessBrif+1B8j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 340
//@ 
//@ loc_FF4F:				; CODE XREF: ProcessBrif+1B4j
//@ 					; ProcessBrif+1C0j
//@ 		mov	key, 0		; uint8_t
//@ ; #line	"CSBRIF.PAS" 343
//@ 
//@ loc_FF54:				; CODE XREF: ProcessBrif+18Bj
//@ 					; ProcessBrif+19Ej ...
//@ 		cmp	CurState, 1	; uint16_t
//@ 		jnz	short loc_FF7C	; Jump if Not Zero (ZF=0)
//@ 		cmp	GoSkip,	0	; bool
//@ 		jz	short loc_FF69	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ 		jmp	short loc_FF7C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 344
//@ 
//@ loc_FF69:				; CODE XREF: ProcessBrif+1D8j
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	CurDelay, ax	; int16_t
//@ 		cmp	CurDelay, 0	; int16_t
//@ 		jg	short loc_FF7C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 346
//@ 
//@ loc_FF7C:				; CODE XREF: ProcessBrif+1D1j
//@ 					; ProcessBrif+1DFj ...
//@ 		cmp	CurState, 3	; uint16_t
//@ 		jnz	short loc_FFA2	; Jump if Not Zero (ZF=0)
//@ 		cmp	GoSkip,	0	; bool
//@ 		jz	short loc_FF91	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ 		jmp	short loc_FFA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 347
//@ 
//@ loc_FF91:				; CODE XREF: ProcessBrif+200j
//@ 		imul	di, CurCar, 70h	; int16_t
//@ 		cmp	word ptr [di+498h], 8 ;	Compare	Two Operands
//@ 		jnb	short loc_FFA2	; Jump if Not Below (CF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 349
//@ 
//@ loc_FFA2:				; CODE XREF: ProcessBrif+1F9j
//@ 					; ProcessBrif+207j ...
//@ 		cmp	CurState, 4	; uint16_t
//@ 		jnz	short locret_FFC9 ; Jump if Not	Zero (ZF=0)
//@ 		cmp	GoSkip,	0	; bool
//@ 		jz	short loc_FFB7	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ 		jmp	short locret_FFC9 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 350
//@ 
//@ loc_FFB7:				; CODE XREF: ProcessBrif+226j
//@ 		imul	di, CurVoice, 0Eh ; int16_t
//@ 		cmp	word ptr [di-878h], 0FFh ; Compare Two Operands
//@ 		jnz	short locret_FFC9 ; Jump if Not	Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 351
//@ 
//@ locret_FFC9:				; CODE XREF: ProcessBrif+21Fj
//@ 					; ProcessBrif+22Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ProcessBrif	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aCommonBrifbar_	db 18,'COMMON\brifbar.cel' ; DATA XREF: PlayBrifing+ACo
//@ ; #line	"CSBRIF.PAS" 357
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PlayBrifing	proc far		; CODE XREF: PROGRAM+DA8P PROGRAM+DEDP
//@ 
//@ var_106		= dword	ptr -106h
//@ _Level		= word ptr -102h	; int16_t
//@ ScriptFile	= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ 
//@ 		enter	106h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+ScriptFile] ; char[256]	// Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSBRIF.PAS" 358
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_10007	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_1000A	; Jump if Zero (ZF=1)
//@ 
//@ loc_10007:				; CODE XREF: PlayBrifing+20j
//@ 		jmp	locret_1052A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 359
//@ 
//@ loc_1000A:				; CODE XREF: PlayBrifing+27j
//@ 		lea	di, [bp+ScriptFile] ; char[256]	// Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1001C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1052A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 360
//@ 
//@ loc_1001C:				; CODE XREF: PlayBrifing+39j
//@ 		push	28h ; '('
//@ 		call	FadeOut		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 361
//@ 		mov	di, offset Palette ; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Pal	; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		push	300h
//@ 		call	@$basg$qm3Anyt14Word ; Bitcopy of any type variable
//@ ; #line	"CSBRIF.PAS" 362
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Room, ax	; int16_t
//@ ; #line	"CSBRIF.PAS" 364
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LoadPos, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 365
//@ 		mov	ax, LevelN	; int16_t
//@ 		mov	[bp+_Level], ax	; int16_t
//@ 		mov	LevelN,	63h ; 'c' ; int16_t
//@ 		call	LoadLevel	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 370
//@ 
//@ loc_10051:				; CODE XREF: PlayBrifing+517j
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 822Eh
//@ 		push	di
//@ 		push	282h
//@ 		push	1
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 371
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 88CCh
//@ 		push	di
//@ 		push	282h
//@ 		push	1
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 372
//@ 		mov	InBrifing, 1	; bool
//@ ; #line	"CSBRIF.PAS" 373
//@ 		mov	di, offset BrifBar ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	4380h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 374
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonBrifbar_ ; "COMMON\\brifbar.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 375
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 376
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, BrifBar	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	4380h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSBRIF.PAS" 377
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 378
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 381
//@ 		mov	di, offset BrText ; char*
//@ 		push	ds
//@ 		push	di
//@ 		push	1700h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 382
//@ 		les	di, BrText	; char*
//@ 		push	es
//@ 		push	di
//@ 		push	1700h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSBRIF.PAS" 383
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurLine, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTop,	ax	; int16_t
//@ ; #line	"CSBRIF.PAS" 384
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	XFi, ax		; int16_t
//@ 		mov	ax, 1AC6h
//@ 		mov	cm_ofs,	ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 385
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurState, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 386
//@ 		call	ReinitBrifView	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 387
//@ 		call	ReDrawGround	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 388
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	t1, ax		; uint16_t
//@ ; #line	"CSBRIF.PAS" 390
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0Eh
//@ 		div	cx		; Unsigned Divide
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 391
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 822Eh
//@ 		push	di
//@ 		push	282h
//@ 		push	1
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 392
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 88CCh
//@ 		push	di
//@ 		push	282h
//@ 		push	1
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 395
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	takt, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 396
//@ 		mov	GoSkip,	0	; bool
//@ ; #line	"CSBRIF.PAS" 397
//@ 		call	StopSounds	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 399
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+ScriptFile] ; char[256]	// Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	TOpen		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 400
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 401
//@ 		call	LoadSetup	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 403
//@ 		mov	di, Room	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 0E580h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSBRIF.PAS" 404
//@ 		mov	ax, es:[di]
//@ 		mov	Hx, ax		; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	Hy, ax		; int16_t
//@ ; #line	"CSBRIF.PAS" 407
//@ 
//@ loc_10188:				; CODE XREF: PlayBrifing+1B8j
//@ 					; PlayBrifing+4F1j
//@ 		call	@KeyPressed$qv	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_10198	; Jump if Zero (ZF=1)
//@ 		call	@ReadKey$qv	; function far PASCAL returns PASCAL character 'Char'
//@ 		jmp	short loc_10188	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 408
//@ 
//@ loc_10198:				; CODE XREF: PlayBrifing+1B1j
//@ 		cmp	KBDBufCnt, 0	; uint16_t
//@ 		jbe	short loc_101BE	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSBRIF.PAS" 410
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"CSBRIF.PAS" 411
//@ 		mov	al, KBDBuf	; uint8_t[16]
//@ 		mov	key, al		; uint8_t
//@ ; #line	"CSBRIF.PAS" 412
//@ 		dec	KBDBufCnt	; uint16_t
//@ ; #line	"CSBRIF.PAS" 413
//@ 		mov	di, (offset KBDBuf+1) ;	uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset KBDBuf ; uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSBRIF.PAS" 414
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"CSBRIF.PAS" 415
//@ 		jmp	short loc_101C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_101BE:				; CODE XREF: PlayBrifing+1BFj
//@ 		mov	key, 0		; uint8_t
//@ ; #line	"CSBRIF.PAS" 417
//@ 
//@ loc_101C3:				; CODE XREF: PlayBrifing+1DEj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		mov	word ptr Time, ax ; int32_t
//@ 		mov	word ptr Time+2, dx ; int32_t
//@ ; #line	"CSBRIF.PAS" 418
//@ 		push	VgaSeg		; uint16_t
//@ 		push	0
//@ 		push	7D00h
//@ 		push	101h
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 420
//@ 		call	PreProcessBrif	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 421
//@ 
//@ loc_101EA:				; CODE XREF: PlayBrifing+216j
//@ 		cmp	CurState, 0	; uint16_t
//@ 		jnz	short loc_101F6	; Jump if Not Zero (ZF=0)
//@ 		call	ExecNextCommand	; function near	PASCAL returns void
//@ 		jmp	short loc_101EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 422
//@ 
//@ loc_101F6:				; CODE XREF: PlayBrifing+211j
//@ 		call	ProcessBrif	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 424
//@ 		push	0
//@ 		push	0
//@ 		push	4000h
//@ 		push	0
//@ 		call	UpDatePlayerPos	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 426
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 86h	; 'Ü'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 2000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 85h	; 'Ö'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Camera.CamZ	; struct Camera$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	ehz, ax		; int16_t
//@ ; #line	"CSBRIF.PAS" 427
//@ 		mov	ax, 1000h
//@ 		sub	ax, ehz		; int16_t
//@ 		mov	Hz2, ax		; uint16_t
//@ ; #line	"CSBRIF.PAS" 428
//@ 		mov	ax, Hx		; int16_t
//@ 		sub	ax, Camera.camx	; struct Camera$Type
//@ 		mov	ehx, ax		; int16_t
//@ ; #line	"CSBRIF.PAS" 429
//@ 		mov	ax, Hy		; int16_t
//@ 		sub	ax, Camera.camy	; struct Camera$Type
//@ 		mov	ehy, ax		; int16_t
//@ ; #line	"CSBRIF.PAS" 431
//@ 		mov	ax, Camera.camfi ; struct Camera$Type
//@ 		sub	ax, 8000h	; Integer Subtraction
//@ 		mov	HFi, ax		; uint16_t
//@ ; #line	"CSBRIF.PAS" 432
//@ 		mov	ax, HFi		; uint16_t
//@ 		mov	EHFi, ax	; uint16_t
//@ ; #line	"CSBRIF.PAS" 433
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 434
//@ 		mov	ax, word ptr ca	; real_t
//@ 		mov	bx, word ptr ca+2 ; real_t
//@ 		mov	dx, word ptr ca+4 ; real_t
//@ 		mov	cx, 89h	; 'â'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 84h	; 'Ñ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	ica, ax		; int16_t
//@ ; #line	"CSBRIF.PAS" 435
//@ 		mov	ax, word ptr sa	; real_t
//@ 		mov	bx, word ptr sa+2 ; real_t
//@ 		mov	dx, word ptr sa+4 ; real_t
//@ 		mov	cx, 89h	; 'â'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 84h	; 'Ñ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	isa, ax		; int16_t
//@ ; #line	"CSBRIF.PAS" 436
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	ica2, ax	; int16_t
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	isa2, ax	; int16_t
//@ ; #line	"CSBRIF.PAS" 437
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	ica4, ax	; int16_t
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	isa4, ax	; int16_t
//@ ; #line	"CSBRIF.PAS" 440
//@ 		mov	ax, word ptr BuildSceneRout ; void (*)()
//@ 		or	ax, word ptr BuildSceneRout+2 ;	void (*)()
//@ 		jz	short loc_1030C	; Jump if Zero (ZF=1)
//@ 		call	BuildSceneRout	; void (*)()
//@ ; #line	"CSBRIF.PAS" 442
//@ 
//@ loc_1030C:				; CODE XREF: PlayBrifing+328j
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_10318	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10314:				; CODE XREF: PlayBrifing+3BFj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_10318:				; CODE XREF: PlayBrifing+334j
//@ 		imul	di, n$0, 70h	; int16_t
//@ 		add	di, 42Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_106], di
//@ 		mov	word ptr [bp+var_106+2], es
//@ ; #line	"CSBRIF.PAS" 443
//@ 		mov	ax, es:[di+8]
//@ 		or	ax, es:[di+0Ah]	; Logical Inclusive OR
//@ 		jz	short loc_10396	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 445
//@ 		mov	Curdark, 7	; int16_t
//@ ; #line	"CSBRIF.PAS" 446
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+8]
//@ 		mov	ax, es:[di+6Ch]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		push	word ptr es:[di+0Eh]
//@ 		push	word ptr es:[di+0Ch]
//@ 		les	di, [bp+var_106] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+6Eh]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 447
//@ 		les	di, [bp+var_106] ; Load	Full Pointer to	ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+8]
//@ 		mov	ax, es:[di]
//@ 		sub	ax, Camera.camx	; struct Camera$Type
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, Camera.camy	; struct Camera$Type
//@ 		push	ax
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		mov	ax, Camera.camfi ; struct Camera$Type
//@ 		sub	ax, 8000h	; Integer Subtraction
//@ 		push	ax
//@ 		call	DrawHi3D	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 450
//@ 
//@ loc_10396:				; CODE XREF: PlayBrifing+355j
//@ 		cmp	n$0, 3		; int16_t
//@ 		jz	short loc_103A0	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10314	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 452
//@ 
//@ loc_103A0:				; CODE XREF: PlayBrifing+3BDj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_103AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_103A7:				; CODE XREF: PlayBrifing+424j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSBRIF.PAS" 453
//@ 
//@ loc_103AB:				; CODE XREF: PlayBrifing+3C7j
//@ 		les	di, BrifBar	; void*
//@ 		push	es
//@ 		imul	ax, n$0, 140h	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 36h	; '6'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, [di-6E84h]
//@ 		mov	bx, [di-6E82h]
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0A0h ; '†'  ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	dx
//@ 		push	ax
//@ 		push	0
//@ 		push	50h ; 'P'
//@ 		call	MovsED		; function far PASCAL returns void
//@ 		cmp	n$0, 35h ; '5'  ; int16_t
//@ 		jnz	short loc_103A7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 456
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1040F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1040B:				; CODE XREF: PlayBrifing+489j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSBRIF.PAS" 457
//@ 
//@ loc_1040F:				; CODE XREF: PlayBrifing+42Bj
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, CurTop	; int16_t
//@ 		imul	ax, 2Eh		; Signed Multiply
//@ 		les	di, BrText	; char*
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_10462	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 458
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		sub	ax, 0A0h ; '†'  ; Integer Subtraction
//@ 		push	ax
//@ 		imul	ax, n$0, 0Ah	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 32h	; '2'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, CurTop	; int16_t
//@ 		imul	ax, 2Eh		; Signed Multiply
//@ 		les	di, BrText	; char*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ 
//@ loc_10462:				; CODE XREF: PlayBrifing+445j
//@ 		cmp	n$0, 4		; int16_t
//@ 		jnz	short loc_1040B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSBRIF.PAS" 461
//@ 		call	ShowVideoBuffer	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 462
//@ 		cmp	takt, 0		; uint16_t
//@ 		jnz	short loc_1047C	; Jump if Not Zero (ZF=0)
//@ 		push	28h ; '('
//@ 		call	FadeIn		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 463
//@ 
//@ loc_1047C:				; CODE XREF: PlayBrifing+495j
//@ 		mov	ax, CurTime	; uint16_t
//@ 		mov	t1, ax		; uint16_t
//@ 		inc	takt		; uint16_t
//@ 		cmp	t1, 10h		; uint16_t
//@ 		jbe	short loc_10493	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	t1, 10h		; uint16_t
//@ ; #line	"CSBRIF.PAS" 465
//@ 
//@ loc_10493:				; CODE XREF: PlayBrifing+4ADj
//@ 		cmp	CurState, 2	; uint16_t
//@ 		jz	short loc_104C8	; Jump if Zero (ZF=1)
//@ ; #line	"CSBRIF.PAS" 466
//@ 		mov	al, key		; uint8_t
//@ ; #line	"CSBRIF.PAS" 467
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_104A9	; Jump if Not Zero (ZF=0)
//@ 		mov	CurState, 0FFFFh ; uint16_t
//@ 		jmp	short loc_104C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 468
//@ 
//@ loc_104A9:				; CODE XREF: PlayBrifing+4C1j
//@ 		cmp	al, 0Eh		; Compare Two Operands
//@ 		jnz	short loc_104B5	; Jump if Not Zero (ZF=0)
//@ 		mov	CurState, 0FFFEh ; uint16_t
//@ 		jmp	short loc_104C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 469
//@ 
//@ loc_104B5:				; CODE XREF: PlayBrifing+4CDj
//@ 		cmp	al, 1Ch		; Compare Two Operands
//@ 		jnz	short loc_104C8	; Jump if Not Zero (ZF=0)
//@ 		cmp	Camera.MvTime, 0 ; struct Camera$Type
//@ 		jnz	short loc_104C8	; Jump if Not Zero (ZF=0)
//@ 		call	StopSounds	; function near	PASCAL returns void
//@ 		mov	GoSkip,	1	; bool
//@ ; #line	"CSBRIF.PAS" 472
//@ 
//@ loc_104C8:				; CODE XREF: PlayBrifing+4BAj
//@ 					; PlayBrifing+4C9j ...
//@ 		cmp	CurState, 0FFF0h ; uint16_t
//@ 		ja	short loc_104D2	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_10188	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 473
//@ 
//@ loc_104D2:				; CODE XREF: PlayBrifing+4EFj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4Text	; Close(var f: Text)
//@ ; #line	"CSBRIF.PAS" 474
//@ 		push	0FFFFh
//@ 		call	SetAmbient	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 475
//@ 		call	StopSounds	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 476
//@ 		call	DeInitBrifing	; function near	PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 477
//@ 		mov	InBrifing, 0	; bool
//@ ; #line	"CSBRIF.PAS" 478
//@ 		cmp	CurState, 0FFFFh ; uint16_t
//@ 		jz	short loc_104F8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10051	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSBRIF.PAS" 480
//@ 
//@ loc_104F8:				; CODE XREF: PlayBrifing+515j
//@ 		call	ReleaseLevel	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 481
//@ 		mov	ax, [bp+_Level]	; int16_t
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"CSBRIF.PAS" 482
//@ 		push	28h ; '('
//@ 		call	FadeOut		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 483
//@ 		call	ReDrawGround	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 484
//@ 		call	ShowVideoBuffer	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 485
//@ 		push	SegA000		; uint16_t
//@ 		push	0
//@ 		push	7D00h
//@ 		push	0
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 486
//@ 		call	SetPalette	; function far PASCAL returns void
//@ ; #line	"CSBRIF.PAS" 487
//@ 
//@ locret_1052A:				; CODE XREF: PlayBrifing:loc_10007j
//@ 					; PlayBrifing+3Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ PlayBrifing	endp
//@ 
