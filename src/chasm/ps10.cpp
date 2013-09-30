
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

#include "ps10.h"

#include "cspbio.h"
#include "csprndr.h"


//@ ; #line	"PS10.PAS" 43
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ WhatKey		proc far
//@ 		pusha			; Push all General Registers
//@ ; #line	"PS10.PAS" 44
//@ 		push	ds
//@ ; #line	"PS10.PAS" 45
//@ 		mov	ax, seg	dseg11
//@ ; #line	"PS10.PAS" 46
//@ 		mov	ds, ax
//@ ; #line	"PS10.PAS" 48
//@ 		in	al, 60h		; 8042 keyboard	controller data	register
//@ ; #line	"PS10.PAS" 50
//@ 		cmp	kod, 0E0h ; 'à' ; uint8_t
//@ 		jnz	short loc_38E5	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 51
//@ 		cmp	al, 0AAh ; 'ª'  ; Compare Two Operands
//@ 		jz	short loc_38E3	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 52
//@ 		cmp	al, 0BCh ; '¼'  ; Compare Two Operands
//@ 		jz	short loc_38E3	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 53
//@ 		jmp	short loc_38E5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 54
//@ 
//@ loc_38E3:				; CODE XREF: WhatKey+12j WhatKey+16j
//@ 		mov	al, 0
//@ ; #line	"PS10.PAS" 56
//@ 
//@ loc_38E5:				; CODE XREF: WhatKey+Ej WhatKey+18j
//@ 		cmp	kod, 0E1h ; 'á' ; uint8_t
//@ 		jnz	short loc_38F2	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 57
//@ 		cmp	al, 1Dh		; Compare Two Operands
//@ 		jnz	short loc_38F2	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 58
//@ 		mov	al, 6Fh	; 'o'
//@ ; #line	"PS10.PAS" 59
//@ 
//@ loc_38F2:				; CODE XREF: WhatKey+21j WhatKey+25j
//@ 		mov	kod, al		; uint8_t
//@ ; #line	"PS10.PAS" 65
//@ 		in	al, 61h		; PC/XT	PPI port B bits:
//@ 					; 0: Tmr 2 gate	ÍËÍ OR	03H=spkr ON
//@ 					; 1: Tmr 2 data	Í¼  AND	0fcH=spkr OFF
//@ 					; 3: 1=read high switches
//@ 					; 4: 0=enable RAM parity checking
//@ 					; 5: 0=enable I/O channel check
//@ 					; 6: 0=hold keyboard clock low
//@ 					; 7: 0=enable kbrd
//@ ; #line	"PS10.PAS" 66
//@ 		or	al, 80h		; Logical Inclusive OR
//@ 		out	61h, al		; PC/XT	PPI port B bits:
//@ 					; 0: Tmr 2 gate	ÍËÍ OR	03H=spkr ON
//@ 					; 1: Tmr 2 data	Í¼  AND	0fcH=spkr OFF
//@ 					; 3: 1=read high switches
//@ 					; 4: 0=enable RAM parity checking
//@ 					; 5: 0=enable I/O channel check
//@ 					; 6: 0=hold keyboard clock low
//@ 					; 7: 0=enable kbrd
//@ ; #line	"PS10.PAS" 67
//@ 		and	al, 7Fh		; Logical AND
//@ 		out	61h, al		; PC/XT	PPI port B bits:
//@ 					; 0: Tmr 2 gate	ÍËÍ OR	03H=spkr ON
//@ 					; 1: Tmr 2 data	Í¼  AND	0fcH=spkr OFF
//@ 					; 3: 1=read high switches
//@ 					; 4: 0=enable RAM parity checking
//@ 					; 5: 0=enable I/O channel check
//@ 					; 6: 0=hold keyboard clock low
//@ 					; 7: 0=enable kbrd
//@ ; #line	"PS10.PAS" 69
//@ 		mov	al, 20h	; ' '
//@ ; #line	"PS10.PAS" 70
//@ 		out	20h, al		; Interrupt controller,	8259A.
//@ ; #line	"PS10.PAS" 73
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	al, kod		; uint8_t
//@ 		mov	bl, al
//@ ; #line	"PS10.PAS" 75
//@ 		shr	al, 7		; Shift	Logical	Right
//@ 		xor	al, 1		; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 76
//@ 		and	bl, 7Fh		; Logical AND
//@ ; #line	"PS10.PAS" 77
//@ 		add	bx, 0EC0Eh	; Add
//@ ; #line	"PS10.PAS" 78
//@ 		mov	[bx], al
//@ ; #line	"PS10.PAS" 80
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_3930	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 81
//@ 		mov	bx, KBDBufCnt	; uint16_t
//@ 		cmp	bx, 0Fh		; Compare Two Operands
//@ 		jnb	short loc_3930	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 82
//@ 		mov	al, kod		; uint8_t
//@ ; #line	"PS10.PAS" 83
//@ 		mov	[bx-1372h], al
//@ ; #line	"PS10.PAS" 84
//@ 		inc	KBDBufCnt	; uint16_t
//@ ; #line	"PS10.PAS" 86
//@ 
//@ loc_3930:				; CODE XREF: WhatKey+51j WhatKey+5Aj
//@ 		pop	ds
//@ ; #line	"PS10.PAS" 87
//@ 		popa			; Pop all General Registers
//@ ; #line	"PS10.PAS" 88
//@ 		iret			; Interrupt Return
//@ WhatKey		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 89
//@ 		db 0C3h	; Ã
//@ ; #line	"PS10.PAS" 97
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ TimerFM		proc far
//@ 		pusha			; Push all General Registers
//@ 		push	ds
//@ 		push	es
//@ ; #line	"PS10.PAS" 98
//@ 		mov	ax, seg	dseg11
//@ ; #line	"PS10.PAS" 99
//@ 		mov	ds, ax
//@ ; #line	"PS10.PAS" 101
//@ 		inc	CurTime		; uint16_t
//@ ; #line	"PS10.PAS" 102
//@ 		mov	ax, 1
//@ 		add	word ptr RealTime, ax ;	int32_t
//@ ; #line	"PS10.PAS" 103
//@ 		mov	ax, 0
//@ 		adc	word ptr RealTime+2, ax	; int32_t
//@ ; #line	"PS10.PAS" 105
//@ 		mov	ax, 64h	; 'd'
//@ ; #line	"PS10.PAS" 106
//@ 		sub	ClockCount, ax	; int16_t
//@ ; #line	"PS10.PAS" 107
//@ 		jns	short loc_3963	; Jump if Not Sign (SF=0)
//@ ; #line	"PS10.PAS" 108
//@ 		mov	ax, 301h
//@ ; #line	"PS10.PAS" 109
//@ 		add	ClockCount, ax	; int16_t
//@ ; #line	"PS10.PAS" 110
//@ 		pushf			; Push Flags Register onto the Stack
//@ 		call	TimerInt	; void (*)()
//@ ; #line	"PS10.PAS" 111
//@ 
//@ loc_3963:				; CODE XREF: TimerFM+21j
//@ 		cmp	NPinst,	1	; bool
//@ 		jnz	short loc_397F	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 112
//@ 		les	si, PInfoStruct	; TInfo_Struct*
//@ ; #line	"PS10.PAS" 113
//@ 		add	si, 152h	; Add
//@ ; #line	"PS10.PAS" 114
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	es:[si], ax
//@ ; #line	"PS10.PAS" 115
//@ 		mov	ax, word ptr RealTime+2	; int32_t
//@ 		mov	es:[si+2], ax
//@ ; #line	"PS10.PAS" 118
//@ 
//@ loc_397F:				; CODE XREF: TimerFM+34j
//@ 		mov	al, 20h	; ' '
//@ ; #line	"PS10.PAS" 119
//@ 		out	20h, al		; Interrupt controller,	8259A.
//@ ; #line	"PS10.PAS" 120
//@ 		pop	es
//@ 		pop	ds
//@ 		popa			; Pop all General Registers
//@ ; #line	"PS10.PAS" 121
//@ 		iret			; Interrupt Return
//@ TimerFM		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 122
//@ 		db 0C3h	; Ã
//@ aChasm_cfg	db 9,'CHASM.CFG'        ; DATA XREF: LoadConfig+9o
//@ aChasm_def	db 9,'CHASM.DEF'        ; DATA XREF: LoadConfig:loc_39CEo
//@ aChasm_defNotFo	db 20,'CHASM.DEF not found.' ; DATA XREF: LoadConfig+60o
//@ ; #line	"PS10.PAS" 127
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadConfig	proc near		; CODE XREF: ProcessMenu+65Fp
//@ 					; PROGRAM+232p
//@ 
//@ Original	= byte ptr  4		; bool
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 128
//@ 		cmp	[bp+Original], 0 ; bool
//@ 		jz	short loc_39CE	; Jump if Zero (ZF=1)
//@ 		mov	di, offset aChasm_cfg ;	"CHASM.CFG"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_39E0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 129
//@ 
//@ loc_39CE:				; CODE XREF: LoadConfig+7j
//@ 		mov	di, offset aChasm_def ;	"CHASM.DEF"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 130
//@ 
//@ loc_39E0:				; CODE XREF: LoadConfig+1Bj
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"PS10.PAS" 131
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ ; #line	"PS10.PAS" 132
//@ 		cmp	[bp+Original], 0 ; bool
//@ 		jz	short loc_3A08	; Jump if Zero (ZF=1)
//@ 		call	ChI		; function far PASCAL returns void
//@ 		jmp	short loc_3A1E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 133
//@ 
//@ loc_3A08:				; CODE XREF: LoadConfig+4Ej
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_3A1E	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 134
//@ 		mov	di, offset aChasm_defNotFo ; "CHASM.DEF	not found."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	locret_3C7B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 136
//@ 
//@ loc_3A1E:				; CODE XREF: LoadConfig+55j
//@ 					; LoadConfig+5Ej
//@ 		mov	CDVolume, 8	; uint8_t
//@ 		mov	MSsens,	0Ah	; uint8_t
//@ 		mov	Ms1ID, 0	; uint8_t
//@ 		mov	Ms2ID, 1	; uint8_t
//@ ; #line	"PS10.PAS" 137
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset _FrontOn ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	13h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 139
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset RespawnTime ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 140
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset FXVolume ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 141
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset CDVolume ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 142
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset MSsens ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 143
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Bright ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 144
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Contrast ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 145
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Color ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 146
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset FloorW ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 147
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset b0	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 148
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset InfoPage ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 149
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	9
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 150
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset SelfColor ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 151
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ShadowCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 152
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset EpisodeReset	; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 153
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Cocpit ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 154
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ReverseMouse	; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 155
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset MLookOn ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 156
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset AlwaysRun ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 158
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset NGCard ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 159
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset NGPort ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 160
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset NGBaud ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 162
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset w	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 163
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Ll	; int32_t
//@ 		push	ds
//@ 		push	di
//@ 		push	4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 164
//@ 		cmp	[bp+Original], 0 ; bool
//@ 		jz	short loc_3C57	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 165
//@ 		mov	ax, w		; uint16_t
//@ 		cmp	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		ja	short loc_3C57	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, word ptr Ll	; int32_t
//@ 		mov	dx, word ptr Ll+2 ; int32_t
//@ 		imul	di, w, 0Dh	; uint16_t
//@ 		cmp	dx, [di-0BC7h]	; Compare Two Operands
//@ 		jnz	short loc_3C57	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, [di-0BC9h]	; Compare Two Operands
//@ 		jnz	short loc_3C57	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 166
//@ 		mov	ax, w		; uint16_t
//@ 		mov	CurVideoMode, ax ; uint16_t
//@ ; #line	"PS10.PAS" 167
//@ 
//@ loc_3C57:				; CODE XREF: LoadConfig+27Dj
//@ 					; LoadConfig+286j ...
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 169
//@ 		cmp	[bp+Original], 0 ; bool
//@ 		jnz	short locret_3C7B ; Jump if Not	Zero (ZF=0)
//@ ; #line	"PS10.PAS" 171
//@ 		call	SetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 172
//@ 		call	SetVolumes	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 173
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 175
//@ 
//@ locret_3C7B:				; CODE XREF: LoadConfig+6Aj
//@ 					; LoadConfig+2B9j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ LoadConfig	endp
//@ 
//@ ; #line	"PS10.PAS" 181
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CalcYMin	proc near		; CODE XREF: Build3dScene+1F2p
//@ 					; DoGame+BC2p
//@ 
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 182
//@ 		mov	ax, WinH2u	; uint16_t
//@ 		mov	YMin1, ax	; uint16_t
//@ 		mov	ax, WinH2d	; uint16_t
//@ 		mov	YMin2, ax	; uint16_t
//@ ; #line	"PS10.PAS" 183
//@ 		mov	ax, WinEX	; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, WinSX	; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jg	short loc_3CEF	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_3CA5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3CA2:				; CODE XREF: CalcYMin+6Ej
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 185
//@ 
//@ loc_3CA5:				; CODE XREF: CalcYMin+21j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		cmp	ax, YMin1	; uint16_t
//@ 		jnb	short loc_3CC6	; Jump if Not Below (CF=0)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	YMin1, ax	; uint16_t
//@ ; #line	"PS10.PAS" 186
//@ 
//@ loc_3CC6:				; CODE XREF: CalcYMin+36j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7734h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		cmp	ax, YMin2	; uint16_t
//@ 		jnb	short loc_3CE7	; Jump if Not Below (CF=0)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7734h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	YMin2, ax	; uint16_t
//@ ; #line	"PS10.PAS" 187
//@ 
//@ loc_3CE7:				; CODE XREF: CalcYMin+57j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jnz	short loc_3CA2	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 188
//@ 
//@ loc_3CEF:				; CODE XREF: CalcYMin+1Cj
//@ 		cmp	YMin1, 2	; uint16_t
//@ 		jnb	short loc_3CFC	; Jump if Not Below (CF=0)
//@ 		mov	YMin1, 2	; uint16_t
//@ ; #line	"PS10.PAS" 189
//@ 
//@ loc_3CFC:				; CODE XREF: CalcYMin+75j
//@ 		cmp	YMin2, 2	; uint16_t
//@ 		jnb	short locret_3D09 ; Jump if Not	Below (CF=0)
//@ 		mov	YMin2, 2	; uint16_t
//@ ; #line	"PS10.PAS" 190
//@ 
//@ locret_3D09:				; CODE XREF: CalcYMin+82j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CalcYMin	endp
//@ 
//@ ; #line	"PS10.PAS" 204
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StartPaint	proc near		; CODE XREF: Build3dScene+1F8p
//@ 					; DoGame+1731p
//@ 
//@ LineR		= dword	ptr -0Eh	; void*
//@ X		= word ptr -2		; uint16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 206
//@ 		mov	ax, WinSX	; uint16_t
//@ 		mov	[bp+X],	ax	; uint16_t
//@ 		mov	ax, [bp+X]	; uint16_t
//@ 		mov	HLxx, ax	; uint16_t
//@ ; #line	"PS10.PAS" 207
//@ 		cmp	CurVideoMode, 1	; uint16_t
//@ 		jnz	short loc_3D30	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, 213Bh
//@ 		mov	dx, seg	cseg01
//@ 		mov	word ptr [bp+LineR], ax	; void*
//@ 		mov	word ptr [bp+LineR+2], dx ; void*
//@ 		jmp	short loc_3D3C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3D30:				; CODE XREF: StartPaint+15j
//@ 		mov	ax, 2215h
//@ 		mov	dx, seg	cseg01
//@ 		mov	word ptr [bp+LineR], ax	; void*
//@ 		mov	word ptr [bp+LineR+2], dx ; void*
//@ ; #line	"PS10.PAS" 209
//@ 
//@ loc_3D3C:				; CODE XREF: StartPaint+23j
//@ 					; StartPaint+D3j
//@ 		mov	ax, [bp+X]	; uint16_t
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jbe	short loc_3D48	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_3DE1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 217
//@ 
//@ loc_3D48:				; CODE XREF: StartPaint+38j
//@ 		mov	Double,	0	; uint8_t
//@ ; #line	"PS10.PAS" 218
//@ 		mov	bx, [bp+X]	; uint16_t
//@ 		mov	HLxx, bx	; uint16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 219
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 221
//@ 		mov	al, es:[bx+2000h]
//@ 		mov	HlBr, ax	; uint16_t
//@ ; #line	"PS10.PAS" 222
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 223
//@ 		mov	ax, es:[bx]
//@ 		mov	ImSeg, ax	; uint16_t
//@ ; #line	"PS10.PAS" 224
//@ 		mov	ax, es:[bx+800h]
//@ 		mov	ImOfs, ax	; uint16_t
//@ ; #line	"PS10.PAS" 226
//@ 		cmp	es:[bx+802h], ax ; Compare Two Operands
//@ 		jnz	short loc_3D81	; Jump if Not Zero (ZF=0)
//@ 		mov	Double,	1	; uint8_t
//@ 		inc	[bp+X]		; uint16_t
//@ ; #line	"PS10.PAS" 228
//@ 
//@ loc_3D81:				; CODE XREF: StartPaint+6Cj
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"PS10.PAS" 229
//@ 		cmp	ax, 60h	; '`'   ; Compare Two Operands
//@ 		ja	short loc_3D8D	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, 60h	; '`'
//@ ; #line	"PS10.PAS" 230
//@ 
//@ loc_3D8D:				; CODE XREF: StartPaint+7Dj
//@ 		mov	HLh1, ax	; uint16_t
//@ ; #line	"PS10.PAS" 231
//@ 		mov	ax, [bx-7734h]
//@ ; #line	"PS10.PAS" 232
//@ 		cmp	ax, 40h	; '@'   ; Compare Two Operands
//@ 		ja	short loc_3D9C	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, 40h	; '@'
//@ ; #line	"PS10.PAS" 233
//@ 
//@ loc_3D9C:				; CODE XREF: StartPaint+8Cj
//@ 		mov	Hlh2, ax	; uint16_t
//@ ; #line	"PS10.PAS" 236
//@ 		mov	ax, HLh1	; uint16_t
//@ 		add	ax, Hlh2	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 237
//@ 		cmp	ax, 50h	; 'P'   ; Compare Two Operands
//@ 		jle	short loc_3DB3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	bx, 0FFFFh
//@ 		jmp	short loc_3DD4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 238
//@ 
//@ loc_3DB3:				; CODE XREF: StartPaint+A1j
//@ 		cmp	ax, 28h	; '('   ; Compare Two Operands
//@ 		jle	short loc_3DBD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	bx, 0FFFEh
//@ 		jmp	short loc_3DD4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 239
//@ 
//@ loc_3DBD:				; CODE XREF: StartPaint+ABj
//@ 		cmp	ax, 14h		; Compare Two Operands
//@ 		jle	short loc_3DC7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	bx, 0FFFCh
//@ 		jmp	short loc_3DD4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 240
//@ 
//@ loc_3DC7:				; CODE XREF: StartPaint+B5j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jle	short loc_3DD1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	bx, 0FFF8h
//@ 		jmp	short loc_3DD4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 241
//@ 
//@ loc_3DD1:				; CODE XREF: StartPaint+BFj
//@ 		mov	bx, 0FFF0h
//@ ; #line	"PS10.PAS" 242
//@ 
//@ loc_3DD4:				; CODE XREF: StartPaint+A6j
//@ 					; StartPaint+B0j ...
//@ 		mov	AliasMask, bx	; uint16_t
//@ ; #line	"PS10.PAS" 243
//@ 		call	[bp+LineR]	; void*
//@ ; #line	"PS10.PAS" 244
//@ 		inc	[bp+X]		; uint16_t
//@ 		jmp	loc_3D3C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 248
//@ 
//@ locret_3DE1:				; CODE XREF: StartPaint+3Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ StartPaint	endp
//@ 
//@ ; #line	"PS10.PAS" 256
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDateRedShade	proc near		; CODE XREF: EndPaint:loc_45F7p
//@ 
//@ c		= word ptr -302h	; uint16_t
//@ PalBuf		= byte ptr -300h	; struct PalBuf$Element[256]
//@ 
//@ 		enter	302h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 257
//@ 		cmp	RShadeDir, 0	; int16_t
//@ 		jle	short loc_3E0D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 259
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		add	RShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 260
//@ 		cmp	RShadeLev, 50h ; 'P' ; int16_t
//@ 		jle	short loc_3E0B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	RShadeLev, 50h ; 'P' ; int16_t
//@ 		mov	RShadeDir, 0FFFFh ; int16_t
//@ ; #line	"PS10.PAS" 261
//@ 
//@ loc_3E0B:				; CODE XREF: UpDateRedShade+1Aj
//@ 		jmp	short loc_3E2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 262
//@ 
//@ loc_3E0D:				; CODE XREF: UpDateRedShade+9j
//@ 		cmp	RShadeDir, 0	; int16_t
//@ 		jge	short loc_3E2C	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 264
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	RShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 265
//@ 		cmp	RShadeLev, 0	; int16_t
//@ 		jge	short loc_3E2C	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	RShadeLev, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	RShadeDir, ax	; int16_t
//@ ; #line	"PS10.PAS" 268
//@ 
//@ loc_3E2C:				; CODE XREF: UpDateRedShade:loc_3E0Bj
//@ 					; UpDateRedShade+2Fj ...
//@ 		mov	ax, LastRShadeLev ; int16_t
//@ 		cmp	ax, RShadeLev	; int16_t
//@ 		jnz	short loc_3E38	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_3ED6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 270
//@ 
//@ loc_3E38:				; CODE XREF: UpDateRedShade+50j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	GShadeDir, ax	; int16_t
//@ ; #line	"PS10.PAS" 271
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LastGShadeLev, ax ; int16_t
//@ ; #line	"PS10.PAS" 272
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	GShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 274
//@ 		cmp	RShadeLev, 0	; int16_t
//@ 		jnz	short loc_3E5A	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Pal	; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ 		jmp	short loc_3ED0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 277
//@ 
//@ loc_3E5A:				; CODE XREF: UpDateRedShade+69j
//@ 		mov	di, offset Pal	; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+PalBuf]	; struct PalBuf$Element[256]
//@ 		push	ss
//@ 		push	di
//@ 		push	300h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"PS10.PAS" 278
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+c],	ax	; uint16_t
//@ 		jmp	short loc_3E79	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3E75:				; CODE XREF: UpDateRedShade+E0j
//@ 		inc	[bp+c]		; uint16_t
//@ ; #line	"PS10.PAS" 279
//@ 
//@ loc_3E79:				; CODE XREF: UpDateRedShade+90j
//@ 		mov	ax, RShadeLev	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+PalBuf] ; struct PalBuf$Element[256]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, dx		; Add
//@ 		cmp	ax, 3Fh	; '?'   ; Compare Two Operands
//@ 		jle	short loc_3EA9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	[bp+di+PalBuf],	3Fh ; '?' ; struct PalBuf$Element[256]
//@ 		jmp	short loc_3EBD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 280
//@ 
//@ loc_3EA9:				; CODE XREF: UpDateRedShade+B3j
//@ 		mov	ax, RShadeLev	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	[bp+di+PalBuf],	al ; struct PalBuf$Element[256]
//@ 
//@ loc_3EBD:				; CODE XREF: UpDateRedShade+C4j
//@ 		cmp	[bp+c],	0FFh	; uint16_t
//@ 		jnz	short loc_3E75	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 281
//@ 		lea	di, [bp+PalBuf]	; struct PalBuf$Element[256]
//@ 		push	ss
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 283
//@ 
//@ loc_3ED0:				; CODE XREF: UpDateRedShade+75j
//@ 		mov	ax, RShadeLev	; int16_t
//@ 		mov	LastRShadeLev, ax ; int16_t
//@ ; #line	"PS10.PAS" 284
//@ 
//@ locret_3ED6:				; CODE XREF: UpDateRedShade+52j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ UpDateRedShade	endp
//@ 
//@ ; #line	"PS10.PAS" 291
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDateGreenShade proc near		; CODE XREF: EndPaint+3DCp
//@ 
//@ c		= word ptr -302h	; uint16_t
//@ PalBuf		= byte ptr -300h	; struct PalBuf$Element[256]
//@ var_2FF		= byte ptr -2FFh
//@ 
//@ 		enter	302h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 292
//@ 		cmp	GShadeDir, 0	; int16_t
//@ 		jle	short loc_3F02	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 294
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	GShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 295
//@ 		cmp	GShadeLev, 1Ah	; int16_t
//@ 		jle	short loc_3F00	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	GShadeLev, 1Ah	; int16_t
//@ 		mov	GShadeDir, 0FFFFh ; int16_t
//@ ; #line	"PS10.PAS" 296
//@ 
//@ loc_3F00:				; CODE XREF: UpDateGreenShade+1Aj
//@ 		jmp	short loc_3F21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 297
//@ 
//@ loc_3F02:				; CODE XREF: UpDateGreenShade+9j
//@ 		cmp	GShadeDir, 0	; int16_t
//@ 		jge	short loc_3F21	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 299
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	GShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 300
//@ 		cmp	GShadeLev, 0	; int16_t
//@ 		jge	short loc_3F21	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	GShadeLev, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	GShadeDir, ax	; int16_t
//@ ; #line	"PS10.PAS" 303
//@ 
//@ loc_3F21:				; CODE XREF: UpDateGreenShade:loc_3F00j
//@ 					; UpDateGreenShade+2Fj	...
//@ 		mov	ax, LastGShadeLev ; int16_t
//@ 		cmp	ax, GShadeLev	; int16_t
//@ 		jnz	short loc_3F2D	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_3FBA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 304
//@ 
//@ loc_3F2D:				; CODE XREF: UpDateGreenShade+50j
//@ 		cmp	GShadeLev, 0	; int16_t
//@ 		jnz	short loc_3F40	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Pal	; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ 		jmp	short loc_3FB4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 307
//@ 
//@ loc_3F40:				; CODE XREF: UpDateGreenShade+5Aj
//@ 		mov	di, offset Pal	; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+PalBuf]	; struct PalBuf$Element[256]
//@ 		push	ss
//@ 		push	di
//@ 		push	300h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"PS10.PAS" 308
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+c],	ax	; uint16_t
//@ 		jmp	short loc_3F5F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3F5B:				; CODE XREF: UpDateGreenShade+CFj
//@ 		inc	[bp+c]		; uint16_t
//@ ; #line	"PS10.PAS" 309
//@ 
//@ loc_3F5F:				; CODE XREF: UpDateGreenShade+81j
//@ 		mov	ax, GShadeLev	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+var_2FF]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, dx		; Add
//@ 		cmp	ax, 3Fh	; '?'   ; Compare Two Operands
//@ 		jle	short loc_3F8E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	[bp+di+var_2FF], 3Fh ; '?'
//@ 		jmp	short loc_3FA1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 310
//@ 
//@ loc_3F8E:				; CODE XREF: UpDateGreenShade+A3j
//@ 		mov	ax, GShadeLev	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	[bp+di+var_2FF], al ; Add
//@ 
//@ loc_3FA1:				; CODE XREF: UpDateGreenShade+B4j
//@ 		cmp	[bp+c],	0FFh	; uint16_t
//@ 		jnz	short loc_3F5B	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 311
//@ 		lea	di, [bp+PalBuf]	; struct PalBuf$Element[256]
//@ 		push	ss
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 313
//@ 
//@ loc_3FB4:				; CODE XREF: UpDateGreenShade+66j
//@ 		mov	ax, GShadeLev	; int16_t
//@ 		mov	LastGShadeLev, ax ; int16_t
//@ ; #line	"PS10.PAS" 314
//@ 
//@ locret_3FBA:				; CODE XREF: UpDateGreenShade+52j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ UpDateGreenShade endp
//@ 
//@ ; #line	"PS10.PAS" 320
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpdateBlueShade	proc near		; CODE XREF: EndPaint+3DFp
//@ 
//@ c		= word ptr -302h	; uint16_t
//@ PalBuf		= byte ptr -300h	; struct PalBuf$Element[256]
//@ var_2FF		= byte ptr -2FFh
//@ var_2FE		= byte ptr -2FEh
//@ 
//@ 		enter	302h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 321
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	BShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 322
//@ 		cmp	BShadeLev, 0	; int16_t
//@ 		jge	short loc_3FD3	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	BShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 323
//@ 
//@ loc_3FD3:				; CODE XREF: UpdateBlueShade+10j
//@ 		mov	ax, LastBShadeLev ; int16_t
//@ 		cmp	ax, BShadeLev	; int16_t
//@ 		jnz	short loc_3FDF	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_410B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 324
//@ 
//@ loc_3FDF:				; CODE XREF: UpdateBlueShade+1Ej
//@ 		mov	di, offset Pal	; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+PalBuf]	; struct PalBuf$Element[256]
//@ 		push	ss
//@ 		push	di
//@ 		push	300h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"PS10.PAS" 325
//@ 		mov	[bp+c],	1	; uint16_t
//@ 		jmp	short loc_3FFE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3FFA:				; CODE XREF: UpdateBlueShade+13Bj
//@ 		inc	[bp+c]		; uint16_t
//@ ; #line	"PS10.PAS" 326
//@ 
//@ loc_3FFE:				; CODE XREF: UpdateBlueShade+3Cj
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+var_2FE]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+var_2FF]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+PalBuf] ; struct PalBuf$Element[256]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, dx		; Add
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jg	short loc_403E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_40EF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 328
//@ 
//@ loc_403E:				; CODE XREF: UpdateBlueShade+7Dj
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+PalBuf] ; struct PalBuf$Element[256]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, BShadeLev	; int16_t
//@ 		cmp	ax, 3Fh	; '?'   ; Compare Two Operands
//@ 		jle	short loc_4068	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	[bp+di+PalBuf],	3Fh ; '?' ; struct PalBuf$Element[256]
//@ 		jmp	short loc_4079	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 329
//@ 
//@ loc_4068:				; CODE XREF: UpdateBlueShade+99j
//@ 		mov	al, byte ptr BShadeLev ; int16_t
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	[bp+di+PalBuf],	al ; struct PalBuf$Element[256]
//@ ; #line	"PS10.PAS" 330
//@ 
//@ loc_4079:				; CODE XREF: UpdateBlueShade+AAj
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+var_2FF]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, BShadeLev	; int16_t
//@ 		cmp	ax, 3Fh	; '?'   ; Compare Two Operands
//@ 		jle	short loc_40A3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	[bp+di+var_2FF], 3Fh ; '?'
//@ 		jmp	short loc_40B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 331
//@ 
//@ loc_40A3:				; CODE XREF: UpdateBlueShade+D4j
//@ 		mov	al, byte ptr BShadeLev ; int16_t
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	[bp+di+var_2FF], al ; Add
//@ ; #line	"PS10.PAS" 332
//@ 
//@ loc_40B4:				; CODE XREF: UpdateBlueShade+E5j
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [bp+di+var_2FE]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, BShadeLev	; int16_t
//@ 		cmp	ax, 3Fh	; '?'   ; Compare Two Operands
//@ 		jle	short loc_40DE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	[bp+di+var_2FE], 3Fh ; '?'
//@ 		jmp	short loc_40EF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 333
//@ 
//@ loc_40DE:				; CODE XREF: UpdateBlueShade+10Fj
//@ 		mov	al, byte ptr BShadeLev ; int16_t
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	[bp+di+var_2FE], al ; Add
//@ ; #line	"PS10.PAS" 334
//@ 
//@ loc_40EF:				; CODE XREF: UpdateBlueShade+7Fj
//@ 					; UpdateBlueShade+120j
//@ 		cmp	[bp+c],	0FFh	; uint16_t
//@ 		jz	short loc_40FA	; Jump if Zero (ZF=1)
//@ 		jmp	loc_3FFA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 335
//@ 
//@ loc_40FA:				; CODE XREF: UpdateBlueShade+139j
//@ 		lea	di, [bp+PalBuf]	; struct PalBuf$Element[256]
//@ 		push	ss
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 336
//@ 		mov	ax, BShadeLev	; int16_t
//@ 		mov	LastBShadeLev, ax ; int16_t
//@ ; #line	"PS10.PAS" 337
//@ 
//@ locret_410B:				; CODE XREF: UpdateBlueShade+20j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ UpdateBlueShade	endp
//@ 
//@ ; #line	"PS10.PAS" 343
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawItems	proc near		; CODE XREF: EndPaint:loc_4518p
//@ 
//@ CY		= word ptr -4		; uint16_t
//@ $CX		= word ptr -2		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 344
//@ 		mov	Curdark, 11h	; int16_t
//@ ; #line	"PS10.PAS" 345
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		mov	[bp+$CX], ax	; uint16_t
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		mov	[bp+CY], ax	; uint16_t
//@ ; #line	"PS10.PAS" 346
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	VideoCY, ax	; uint16_t
//@ ; #line	"PS10.PAS" 347
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		mov	cx, 7
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	VideoCX, ax	; uint16_t
//@ ; #line	"PS10.PAS" 348
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	ax, [di-0FACh]
//@ 		and	ax, 4		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_419E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 351
//@ 		mov	ax, word ptr Obj3DInf.PAni+2F4h	; struct TObj3DInfo[96]
//@ 		or	ax, word ptr Obj3DInf.PAni+2F6h	; struct TObj3DInfo[96]
//@ 		jz	short loc_418A	; Jump if Zero (ZF=1)
//@ 		push	word ptr Obj3DInf.POH+2F6h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2F4h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2F6h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2F4h ; struct TObj3DInfo[96]
//@ 		mov	ax, Obj3DInf.FTime+2F4h	; struct TObj3DInfo[96]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 352
//@ 
//@ loc_418A:				; CODE XREF: DrawItems+5Fj
//@ 		push	word ptr Obj3DInf.POH+2F6h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2F4h ; struct TObj3DInfo[96]
//@ 		push	0
//@ 		push	1388h
//@ 		push	0
//@ 		call	Show3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 355
//@ 
//@ loc_419E:				; CODE XREF: DrawItems+56j
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		mov	cx, 6
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	VideoCX, ax	; uint16_t
//@ ; #line	"PS10.PAS" 356
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	ax, [di-0FACh]
//@ 		and	ax, 2		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_4205	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 359
//@ 		mov	ax, word ptr Obj3DInf.PAni+2D0h	; struct TObj3DInfo[96]
//@ 		or	ax, word ptr Obj3DInf.PAni+2D2h	; struct TObj3DInfo[96]
//@ 		jz	short loc_41F1	; Jump if Zero (ZF=1)
//@ 		push	word ptr Obj3DInf.POH+2D2h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2D0h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2D2h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2D0h ; struct TObj3DInfo[96]
//@ 		mov	ax, Obj3DInf.FTime+2D0h	; struct TObj3DInfo[96]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 360
//@ 
//@ loc_41F1:				; CODE XREF: DrawItems+C6j
//@ 		push	word ptr Obj3DInf.POH+2D2h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2D0h ; struct TObj3DInfo[96]
//@ 		push	0
//@ 		push	1388h
//@ 		push	0
//@ 		call	Show3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 362
//@ 
//@ loc_4205:				; CODE XREF: DrawItems+BDj
//@ 		mov	ax, [bp+$CX]	; uint16_t
//@ 		mov	VideoCX, ax	; uint16_t
//@ 		mov	ax, [bp+CY]	; uint16_t
//@ 		mov	VideoCY, ax	; uint16_t
//@ ; #line	"PS10.PAS" 363
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DrawItems	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a__1		db 4,'##.#'             ; DATA XREF: EndPaint+313o
//@ asc_4218	db 1,'/'                ; DATA XREF: EndPaint+337o
//@ asc_421A	db 3,'###'              ; DATA XREF: EndPaint+347o
//@ ; #line	"PS10.PAS" 375
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ EndPaint	proc near		; CODE XREF: DoGame:loc_DB51p
//@ 
//@ var_31A		= byte ptr -31Ah
//@ var_21A		= byte ptr -21Ah
//@ var_122		= dword	ptr -122h
//@ var_11E		= dword	ptr -11Eh
//@ $CS		= word ptr -10Ch	; uint16_t
//@ CT		= word ptr -10Ah	; uint16_t
//@ CP		= word ptr -108h	; uint16_t
//@ CW		= word ptr -106h	; uint16_t
//@ GDy		= word ptr -104h	; uint16_t
//@ 
//@ 		enter	31Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 379
//@ 		call	ScrollGun	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 380
//@ 		mov	ax, t1		; uint16_t
//@ 		add	ax, t1		; uint16_t
//@ 		add	WeaponFTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 391
//@ 		mov	di, LastGunNumber ; uint16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		add	di, 0E440h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_11E], di
//@ 		mov	word ptr [bp+var_11E+2], es
//@ ; #line	"PS10.PAS" 392
//@ 		cmp	WeaponPhase, 1	; uint16_t
//@ 		jnz	short loc_428E	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 394
//@ 		mov	ax, WeaponFTime	; uint16_t
//@ 		cmp	ax, es:[di+10h]	; Compare Two Operands
//@ 		jb	short loc_428C	; Jump if Below	(CF=1)
//@ ; #line	"PS10.PAS" 395
//@ 		cmp	WeaponActive, 0	; bool
//@ 		jz	short loc_4282	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 397
//@ 		mov	WeaponPhase, 1	; uint16_t
//@ ; #line	"PS10.PAS" 398
//@ 
//@ loc_4264:				; CODE XREF: EndPaint+5Bj
//@ 		mov	ax, WeaponFTime	; uint16_t
//@ 		les	di, [bp+var_11E] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		cmp	ax, es:[di+10h]	; Compare Two Operands
//@ 		jb	short loc_427B	; Jump if Below	(CF=1)
//@ 		mov	ax, es:[di+10h]
//@ 		sub	WeaponFTime, ax	; uint16_t
//@ 		jmp	short loc_4264	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 399
//@ 
//@ loc_427B:				; CODE XREF: EndPaint+51j
//@ 		mov	WeaponActive, 0	; bool
//@ ; #line	"PS10.PAS" 400
//@ 		jmp	short loc_428C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 401
//@ 
//@ loc_4282:				; CODE XREF: EndPaint+3Ej
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponPhase, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 402
//@ 
//@ loc_428C:				; CODE XREF: EndPaint+37j EndPaint+62j
//@ 		jmp	short loc_42B9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 403
//@ 
//@ loc_428E:				; CODE XREF: EndPaint+2Ej
//@ 		cmp	WeaponActive, 0	; bool
//@ 		jz	short loc_42A7	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 404
//@ 		mov	WeaponPhase, 1	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ 		mov	WeaponActive, 0	; bool
//@ 		jmp	short loc_42B9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 405
//@ 
//@ loc_42A7:				; CODE XREF: EndPaint+75j
//@ 		mov	ax, WeaponFTime	; uint16_t
//@ 		les	di, [bp+var_11E] ; Load	Full Pointer to	ES:xx
//@ 		cmp	ax, es:[di+12h]	; Compare Two Operands
//@ 		jb	short loc_42B9	; Jump if Below	(CF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 408
//@ 
//@ loc_42B9:				; CODE XREF: EndPaint:loc_428Cj
//@ 					; EndPaint+87j	...
//@ 		mov	ax, MyNetN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, CurOwner	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_42EC	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnz	short loc_42EC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 409
//@ 		mov	ax, LastGunNumber ; uint16_t
//@ 		mov	[bp+CW], ax	; uint16_t
//@ 		mov	ax, WeaponPhase	; uint16_t
//@ 		mov	[bp+CP], ax	; uint16_t
//@ 		mov	ax, WeaponFTime	; uint16_t
//@ 		mov	[bp+CT], ax	; uint16_t
//@ 		mov	ax, GunShift	; uint16_t
//@ 		mov	[bp+$CS], ax	; uint16_t
//@ 		jmp	short loc_4334	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 412
//@ 
//@ loc_42EC:				; CODE XREF: EndPaint+AAj EndPaint+AEj
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		mov	ax, [di-0F8Eh]
//@ 		mov	[bp+CW], ax	; uint16_t
//@ ; #line	"PS10.PAS" 413
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+CP], ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+$CS], ax	; uint16_t
//@ ; #line	"PS10.PAS" 414
//@ 		mov	di, [bp+CW]	; uint16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	ax, [di-1BAEh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		mov	[bp+CT], ax	; uint16_t
//@ ; #line	"PS10.PAS" 418
//@ 
//@ loc_4334:				; CODE XREF: EndPaint+CCj
//@ 		cmp	ExMode,	0	; bool
//@ 		jz	short loc_433E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_4518	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_433E:				; CODE XREF: EndPaint+11Bj
//@ 		cmp	EndOfTheGame, 0	; bool
//@ 		jz	short loc_4348	; Jump if Zero (ZF=1)
//@ 		jmp	loc_4518	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4348:				; CODE XREF: EndPaint+125j
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jg	short loc_4357	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_4518	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4357:				; CODE XREF: EndPaint+134j
//@ 		cmp	VideoCX, 190h	; uint16_t
//@ 		jnz	short loc_4362	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_4518	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 419
//@ 
//@ loc_4362:				; CODE XREF: EndPaint+13Fj
//@ 		mov	di, [bp+CW]	; uint16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		add	di, 0E440h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_11E], di
//@ 		mov	word ptr [bp+var_11E+2], es
//@ ; #line	"PS10.PAS" 421
//@ 		cmp	[bp+CP], 0	; uint16_t
//@ 		jnz	short loc_439F	; Jump if Not Zero (ZF=0)
//@ 		push	word ptr es:[di+16h]
//@ 		push	word ptr es:[di+14h]
//@ 		push	word ptr es:[di+1Ah]
//@ 		push	word ptr es:[di+18h]
//@ 		mov	ax, [bp+CT]	; uint16_t
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ 		jmp	short loc_43C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 422
//@ 
//@ loc_439F:				; CODE XREF: EndPaint+15Ej
//@ 		les	di, [bp+var_11E] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+16h]
//@ 		push	word ptr es:[di+14h]
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	word ptr es:[di+1Ch]
//@ 		mov	ax, [bp+CT]	; uint16_t
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 423
//@ 
//@ loc_43C2:				; CODE XREF: EndPaint+17Fj
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_122], di
//@ 		mov	word ptr [bp+var_122+2], es
//@ ; #line	"PS10.PAS" 424
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		call	GetSmoothBrightAt ; function far PASCAL	returns	signed int 'Integer'
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	bx, ax
//@ 		les	di, [bp+var_122] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+3Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 9C2h
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, bx		; Add
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 425
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		mov	ax, [di-0FACh]
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jbe	short loc_4414	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_4414:				; CODE XREF: EndPaint+1F3j
//@ 		mov	Invisibility, al ; bool
//@ ; #line	"PS10.PAS" 426
//@ 		cmp	HRv, 0		; int16_t
//@ 		jnz	short loc_4426	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+GDy], ax	; uint16_t
//@ 		jmp	short loc_446A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 427
//@ 
//@ loc_4426:				; CODE XREF: EndPaint+1FEj
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 0Ch
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		and	ax, 3FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di-6390h]
//@ 		push	HRv		; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		cbw			; AL ->	AX (with sign)
//@ 		shl	ax, 0Ch		; Shift	Logical	Left
//@ 		pop	dx
//@ 		add	ax, dx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0C8h ; 'È'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	HRv		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+GDy], ax	; uint16_t
//@ ; #line	"PS10.PAS" 428
//@ 
//@ loc_446A:				; CODE XREF: EndPaint+206j
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_122], di
//@ 		mov	word ptr [bp+var_122+2], es
//@ ; #line	"PS10.PAS" 429
//@ 		les	di, [bp+var_11E] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+16h]
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, [bp+$CS]	; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		add	ax, 17Ch	; Add
//@ 		push	ax
//@ 		imul	ax, [bp+$CS], 7	; uint16_t
//@ 		mov	dx, ax
//@ 		mov	ax, 640h
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, ehz		; int16_t
//@ 		les	di, [bp+var_122] ; Load	Full Pointer to	ES:xx
//@ 		sub	ax, es:[di+3Ch]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, _LookVz	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, _LookVz	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+GDy]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		imul	ax, [bp+$CS], 46h ; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0F830h
//@ 		mov	dx, 0FFFFh
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		sub	ax, 600h	; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		call	Show3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 431
//@ 		mov	ax, _LookVz	; int16_t
//@ 		sub	ax, LookVz	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		call	DrawCross	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 434
//@ 
//@ loc_4518:				; CODE XREF: EndPaint+11Dj
//@ 					; EndPaint+127j ...
//@ 		call	DrawItems	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 436
//@ 		cmp	TimeInd, 0	; bool
//@ 		jz	short loc_4594	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 437
//@ 		mov	ax, WinEX	; uint16_t
//@ 		sub	ax, 3Ch	; '<'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	4
//@ 		lea	di, [bp+var_21A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a__1	; "##.#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, Times10Sum	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 2000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset asc_4218 ; "/"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_31A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_421A ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, Times10Sum	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 3381h
//@ 		mov	si, 3333h
//@ 		mov	di, 3333h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 440
//@ 
//@ loc_4594:				; CODE XREF: EndPaint+302j
//@ 		cmp	TimeInd, 0	; bool
//@ 		jz	short loc_45E9	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 442
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_45B0	; Jump if Zero (ZF=1)
//@ 		push	t1		; uint16_t
//@ 		push	27Fh
//@ 		push	4
//@ 		call	ShowValue	; function near	PASCAL returns void
//@ 		jmp	short loc_45BE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 443
//@ 
//@ loc_45B0:				; CODE XREF: EndPaint+382j
//@ 		push	t1		; uint16_t
//@ 		mov	ax, WinW	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		push	4
//@ 		call	ShowValue	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 444
//@ 
//@ loc_45BE:				; CODE XREF: EndPaint+390j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_45E9	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 445
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		sub	ax, es:[di+0Eh]	; Integer Subtraction
//@ 		sbb	dx, es:[di+10h]	; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		mov	ax, WinW	; uint16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		push	4
//@ 		call	ShowValue	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 453
//@ 
//@ loc_45E9:				; CODE XREF: EndPaint+37Bj
//@ 					; EndPaint+3A5j
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_45F7	; Jump if Zero (ZF=1)
//@ 		call	ShowVesaScreen	; function far PASCAL returns void
//@ 		jmp	short loc_4605	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 456
//@ 
//@ loc_45F7:				; CODE XREF: EndPaint+3D0j
//@ 		call	UpDateRedShade	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 457
//@ 		call	UpDateGreenShade ; function near PASCAL	returns	void
//@ ; #line	"PS10.PAS" 458
//@ 		call	UpdateBlueShade	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 459
//@ 		call	ShowScreen	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 462
//@ 
//@ loc_4605:				; CODE XREF: EndPaint+3D7j
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_4617	; Jump if Zero (ZF=1)
//@ 
//@ loc_460C:				; CODE XREF: EndPaint+3F5j
//@ 		cmp	CurTime, 4	; uint16_t
//@ 		jnb	short loc_4615	; Jump if Not Below (CF=0)
//@ 		jmp	short loc_460C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4615:				; CODE XREF: EndPaint+3F3j
//@ 		jmp	short loc_4639	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 464
//@ 
//@ loc_4617:				; CODE XREF: EndPaint+3ECj
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_4625	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_4630	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 465
//@ 
//@ loc_4625:				; CODE XREF: EndPaint+3FEj
//@ 					; EndPaint+40Ej
//@ 		cmp	CurTime, 4	; uint16_t
//@ 		jnb	short loc_462E	; Jump if Not Below (CF=0)
//@ 		jmp	short loc_4625	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_462E:				; CODE XREF: EndPaint+40Cj
//@ 		jmp	short loc_4639	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 466
//@ 
//@ loc_4630:				; CODE XREF: EndPaint+405j
//@ 					; EndPaint+419j
//@ 		cmp	CurTime, 2	; uint16_t
//@ 		jnb	short loc_4639	; Jump if Not Below (CF=0)
//@ 		jmp	short loc_4630	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 468
//@ 
//@ loc_4639:				; CODE XREF: EndPaint:loc_4615j
//@ 					; EndPaint:loc_462Ej ...
//@ 		mov	ax, CurTime	; uint16_t
//@ 		mov	t1, ax		; uint16_t
//@ ; #line	"PS10.PAS" 470
//@ 		cmp	Slow, 0		; bool
//@ 		jz	short loc_4682	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 471
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_4662	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_4662	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_4662	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_4673	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 472
//@ 
//@ loc_4662:				; CODE XREF: EndPaint+42Dj
//@ 					; EndPaint+434j ...
//@ 		mov	t1, 10h		; uint16_t
//@ 
//@ loc_4668:				; CODE XREF: EndPaint+451j
//@ 		cmp	CurTime, 10h	; uint16_t
//@ 		jnb	short loc_4671	; Jump if Not Below (CF=0)
//@ 		jmp	short loc_4668	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4671:				; CODE XREF: EndPaint+44Fj
//@ 		jmp	short loc_4682	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 474
//@ 
//@ loc_4673:				; CODE XREF: EndPaint+442j
//@ 		mov	ax, t1		; uint16_t
//@ 		mov	t1, ax		; uint16_t
//@ 
//@ loc_4679:				; CODE XREF: EndPaint+462j
//@ 		cmp	CurTime, 14h	; uint16_t
//@ 		jnb	short loc_4682	; Jump if Not Below (CF=0)
//@ 		jmp	short loc_4679	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 478
//@ 
//@ loc_4682:				; CODE XREF: EndPaint+426j
//@ 					; EndPaint:loc_4671j ...
//@ 		cmp	t1, 16h		; uint16_t
//@ 		jbe	short locret_468F ; Jump if Below or Equal (CF=1 | ZF=1)
//@ 		mov	t1, 16h		; uint16_t
//@ ; #line	"PS10.PAS" 479
//@ 
//@ locret_468F:				; CODE XREF: EndPaint+469j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ EndPaint	endp
//@ 
//@ ; #line	"PS10.PAS" 491
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandWall	proc near		; CODE XREF: MapXY+18Fp
//@ 
//@ var_4		= word ptr -4
//@ ExpandWall	= byte ptr -1		; bool
//@ y2		= word ptr  4		; int16_t
//@ x2		= word ptr  6		; int16_t
//@ y1		= word ptr  8		; int16_t
//@ x1		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 492
//@ 		mov	[bp+ExpandWall], 0 ; bool
//@ ; #line	"PS10.PAS" 493
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	[bp+x1], ax	; int16_t
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"PS10.PAS" 495
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"PS10.PAS" 496
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		add	bx, ax		; Add
//@ 		adc	cx, dx		; Add with Carry
//@ ; #line	"PS10.PAS" 497
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		sub	bx, 2Ch	; ','   ; Integer Subtraction
//@ 		mov	ty1$0, bx	; int16_t
//@ ; #line	"PS10.PAS" 499
//@ 		mov	ax, WXSize	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		cmp	ax, ty1$0	; int16_t
//@ 		jle	short loc_46E1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_4DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 500
//@ 
//@ loc_46E1:				; CODE XREF: ExpandWall+4Bj
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+x2], ax	; int16_t
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+y2], ax	; int16_t
//@ ; #line	"PS10.PAS" 502
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"PS10.PAS" 503
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		sbb	cx, dx		; Integer Subtraction with Borrow
//@ ; #line	"PS10.PAS" 504
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		mov	tx1$0, bx	; int16_t
//@ ; #line	"PS10.PAS" 506
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"PS10.PAS" 507
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		sbb	cx, dx		; Integer Subtraction with Borrow
//@ ; #line	"PS10.PAS" 508
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		mov	tx2$0, bx	; int16_t
//@ ; #line	"PS10.PAS" 510
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"PS10.PAS" 511
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		add	bx, ax		; Add
//@ 		adc	cx, dx		; Add with Carry
//@ ; #line	"PS10.PAS" 512
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		sub	bx, 2Ch	; ','   ; Integer Subtraction
//@ 		mov	ty2$0, bx	; int16_t
//@ ; #line	"PS10.PAS" 515
//@ 		cmp	ty1$0, 0	; int16_t
//@ 		jg	short loc_476D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ty2$0, 0	; int16_t
//@ 		jg	short loc_476D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_4DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 516
//@ 
//@ loc_476D:				; CODE XREF: ExpandWall+D0j
//@ 					; ExpandWall+D7j
//@ 		mov	ax, word ptr Long1 ; int32_t
//@ 		mov	dx, word ptr Long1+2 ; int32_t
//@ 		mov	word ptr Esl, ax ; int32_t
//@ 		mov	word ptr Esl+2,	dx ; int32_t
//@ ; #line	"PS10.PAS" 520
//@ 		cmp	ty2$0, 0	; int16_t
//@ 		jge	short loc_47C3	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 524
//@ 		mov	di, 26h	; '&'
//@ ; #line	"PS10.PAS" 525
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 526
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 527
//@ 		mov	bx, ty1$0	; int16_t
//@ ; #line	"PS10.PAS" 528
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 529
//@ 		mov	bx, ty1$0	; int16_t
//@ ; #line	"PS10.PAS" 530
//@ 		sub	bx, ty2$0	; int16_t
//@ ; #line	"PS10.PAS" 531
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 532
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 533
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 537
//@ 		mov	ax, tx1$0	; int16_t
//@ ; #line	"PS10.PAS" 538
//@ 		mov	cx, ax
//@ ; #line	"PS10.PAS" 539
//@ 		mov	bx, ty1$0	; int16_t
//@ ; #line	"PS10.PAS" 540
//@ 		sub	ax, tx2$0	; int16_t
//@ ; #line	"PS10.PAS" 541
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"PS10.PAS" 542
//@ 		sub	bx, ty2$0	; int16_t
//@ ; #line	"PS10.PAS" 543
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"PS10.PAS" 544
//@ 		sub	cx, ax		; Integer Subtraction
//@ ; #line	"PS10.PAS" 545
//@ 		mov	tx2$0, cx	; int16_t
//@ ; #line	"PS10.PAS" 547
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ty2$0, ax	; int16_t
//@ ; #line	"PS10.PAS" 553
//@ 
//@ loc_47C3:				; CODE XREF: ExpandWall+EFj
//@ 		cmp	ty1$0, 0	; int16_t
//@ 		jge	short loc_480B	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 557
//@ 		mov	di, 26h	; '&'
//@ ; #line	"PS10.PAS" 558
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 559
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 560
//@ 		mov	bx, ty2$0	; int16_t
//@ ; #line	"PS10.PAS" 561
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 562
//@ 		mov	bx, ty2$0	; int16_t
//@ ; #line	"PS10.PAS" 563
//@ 		sub	bx, ty1$0	; int16_t
//@ ; #line	"PS10.PAS" 564
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 565
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 566
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 570
//@ 		mov	ax, tx2$0	; int16_t
//@ ; #line	"PS10.PAS" 571
//@ 		mov	cx, ax
//@ ; #line	"PS10.PAS" 572
//@ 		mov	bx, ty2$0	; int16_t
//@ ; #line	"PS10.PAS" 573
//@ 		sub	ax, tx1$0	; int16_t
//@ ; #line	"PS10.PAS" 574
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"PS10.PAS" 575
//@ 		sub	bx, ty1$0	; int16_t
//@ ; #line	"PS10.PAS" 576
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"PS10.PAS" 577
//@ 		sub	cx, ax		; Integer Subtraction
//@ ; #line	"PS10.PAS" 578
//@ 		mov	tx1$0, cx	; int16_t
//@ ; #line	"PS10.PAS" 580
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ty1$0, ax	; int16_t
//@ ; #line	"PS10.PAS" 584
//@ 
//@ loc_480B:				; CODE XREF: ExpandWall+137j
//@ 		mov	ax, ty1$0	; int16_t
//@ 		add	ax, 4Ch	; 'L'   ; Add
//@ 		mov	ty1$0, ax	; int16_t
//@ 		mov	ax, ty2$0	; int16_t
//@ 		add	ax, 4Ch	; 'L'   ; Add
//@ 		mov	ty2$0, ax	; int16_t
//@ ; #line	"PS10.PAS" 585
//@ 		mov	ax, ty1$0	; int16_t
//@ 		add	ax, 400h	; Add
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	cx, ax
//@ 		mov	ax, tx1$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jle	short loc_4836	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_4DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 587
//@ 
//@ loc_4836:				; CODE XREF: ExpandWall+1A0j
//@ 		mov	ax, tx1$0	; int16_t
//@ 		mov	bx, WallW	; uint16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, ty1$0	; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		mov	Sx1, ax		; int16_t
//@ ; #line	"PS10.PAS" 588
//@ 		mov	ax, tx2$0	; int16_t
//@ 		mov	bx, WallW	; uint16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, ty2$0	; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		mov	Sx2, ax		; int16_t
//@ ; #line	"PS10.PAS" 590
//@ 		mov	ax, Sx1		; int16_t
//@ 		cmp	ax, Sx2		; int16_t
//@ 		jl	short loc_4866	; Jump if Less (SF!=OF)
//@ 		jmp	loc_4DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 591
//@ 
//@ loc_4866:				; CODE XREF: ExpandWall+1D0j
//@ 		mov	ax, Sx2		; int16_t
//@ 		sub	ax, Sx1		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	sl, ax		; uint16_t
//@ ; #line	"PS10.PAS" 593
//@ 		mov	ax, sl		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, sl		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WXSize	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	AliasMask, ax	; uint16_t
//@ ; #line	"PS10.PAS" 594
//@ 		mov	ax, AliasMask	; uint16_t
//@ ; #line	"PS10.PAS" 595
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jz	short loc_48A6	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_48AE	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_48A6:				; CODE XREF: ExpandWall+20Ej
//@ 		mov	AliasMask, 0FFFFh ; uint16_t
//@ 		jmp	short loc_48D8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 596
//@ 
//@ loc_48AE:				; CODE XREF: ExpandWall+213j
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jz	short loc_48B8	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_48C0	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_48B8:				; CODE XREF: ExpandWall+220j
//@ 		mov	AliasMask, 0FFFEh ; uint16_t
//@ 		jmp	short loc_48D8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 597
//@ 
//@ loc_48C0:				; CODE XREF: ExpandWall+225j
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jb	short loc_48D2	; Jump if Below	(CF=1)
//@ 		cmp	ax, 7		; Compare Two Operands
//@ 		ja	short loc_48D2	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	AliasMask, 0FFFCh ; uint16_t
//@ 		jmp	short loc_48D8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 598
//@ 
//@ loc_48D2:				; CODE XREF: ExpandWall+232j
//@ 					; ExpandWall+237j
//@ 		mov	AliasMask, 0FFF8h ; uint16_t
//@ ; #line	"PS10.PAS" 602
//@ 
//@ loc_48D8:				; CODE XREF: ExpandWall+21Bj
//@ 					; ExpandWall+22Dj ...
//@ 		mov	ax, WinW2i	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, Sx2		; int16_t
//@ 		jge	short loc_48EC	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, Sx1		; int16_t
//@ 		cmp	ax, WinW2i	; int16_t
//@ 		jl	short loc_48EF	; Jump if Less (SF!=OF)
//@ 
//@ loc_48EC:				; CODE XREF: ExpandWall+250j
//@ 		jmp	loc_4DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 604
//@ 
//@ loc_48EF:				; CODE XREF: ExpandWall+259j
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		add	Sx1, ax		; int16_t
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		add	Sx2, ax		; int16_t
//@ ; #line	"PS10.PAS" 605
//@ 		mov	ax, WinSX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_4914	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_491B	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_491B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_4914:				; CODE XREF: ExpandWall+27Bj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	_x1, ax		; uint16_t
//@ 		jmp	short loc_492F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_491B:				; CODE XREF: ExpandWall+27Dj
//@ 					; ExpandWall+281j
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinSX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	_x1, ax		; uint16_t
//@ ; #line	"PS10.PAS" 606
//@ 
//@ loc_492F:				; CODE XREF: ExpandWall+288j
//@ 		mov	ax, sl		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinEX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_4953	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_495C	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_495C	; Jump if Below	(CF=1)
//@ 
//@ loc_4953:				; CODE XREF: ExpandWall+2BAj
//@ 		mov	ax, sl		; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	_x2, ax		; uint16_t
//@ 		jmp	short loc_4970	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_495C:				; CODE XREF: ExpandWall+2BCj
//@ 					; ExpandWall+2C0j
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinEX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	_x2, ax		; uint16_t
//@ ; #line	"PS10.PAS" 609
//@ 
//@ loc_4970:				; CODE XREF: ExpandWall+2C9j
//@ 		mov	cx, WallH	; uint16_t
//@ ; #line	"PS10.PAS" 610
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, Hz2		; uint16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, ty1$0	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys11, ax	; uint16_t
//@ ; #line	"PS10.PAS" 611
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, ehz		; int16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, ty1$0	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys12, ax	; uint16_t
//@ ; #line	"PS10.PAS" 612
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, Hz2		; uint16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, ty2$0	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys21, ax	; uint16_t
//@ ; #line	"PS10.PAS" 613
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, ehz		; int16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, ty2$0	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys22, ax	; uint16_t
//@ ; #line	"PS10.PAS" 616
//@ 		mov	ax, ty1$0	; int16_t
//@ 		cmp	ax, ty2$0	; int16_t
//@ 		jg	short loc_49E2	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, ty2$0	; int16_t
//@ 		sub	ax, ty1$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	word ptr SLy, ax ; int32_t
//@ 		mov	word ptr SLy+2,	dx ; int32_t
//@ 		mov	ax, ys11	; uint16_t
//@ 		sub	ax, ys21	; uint16_t
//@ 		mov	sh1, ax		; uint16_t
//@ 		mov	ax, ys12	; uint16_t
//@ 		sub	ax, ys22	; uint16_t
//@ 		mov	sh2, ax		; uint16_t
//@ 		jmp	short loc_4A05	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 617
//@ 
//@ loc_49E2:				; CODE XREF: ExpandWall+32Aj
//@ 		mov	ax, ty1$0	; int16_t
//@ 		sub	ax, ty2$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	word ptr SLy, ax ; int32_t
//@ 		mov	word ptr SLy+2,	dx ; int32_t
//@ 		mov	ax, ys21	; uint16_t
//@ 		sub	ax, ys11	; uint16_t
//@ 		mov	sh1, ax		; uint16_t
//@ 		mov	ax, ys22	; uint16_t
//@ 		sub	ax, ys12	; uint16_t
//@ 		mov	sh2, ax		; uint16_t
//@ ; #line	"PS10.PAS" 619
//@ 
//@ loc_4A05:				; CODE XREF: ExpandWall+34Fj
//@ 		mov	ax, word ptr Esl ; int32_t
//@ 		mov	dx, word ptr Esl+2 ; int32_t
//@ 		cmp	dx, word ptr Long1+2 ; int32_t
//@ 		jnz	short loc_4A18	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, word ptr Long1 ; int32_t
//@ 		jz	short loc_4A36	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 621
//@ 
//@ loc_4A18:				; CODE XREF: ExpandWall+37Fj
//@ 		mov	di, 26h	; '&'
//@ ; #line	"PS10.PAS" 622
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 623
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 624
//@ 		sub	eax, [di]	; Integer Subtraction
//@ ; #line	"PS10.PAS" 625
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 626
//@ 		mov	bx, WXSize	; int16_t
//@ ; #line	"PS10.PAS" 627
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 628
//@ 		mov	di, 0EBC6h
//@ ; #line	"PS10.PAS" 629
//@ 		mov	[di], eax
//@ 		jmp	short loc_4A3E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 630
//@ 
//@ loc_4A36:				; CODE XREF: ExpandWall+385j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr Io0, ax ; int32_t
//@ 		mov	word ptr Io0+2,	ax ; int32_t
//@ ; #line	"PS10.PAS" 632
//@ 
//@ loc_4A3E:				; CODE XREF: ExpandWall+3A3j
//@ 		cmp	_x1, 0		; uint16_t
//@ 		jbe	short loc_4A4B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ax, WinSX	; uint16_t
//@ 		mov	Sx1, ax		; int16_t
//@ ; #line	"PS10.PAS" 636
//@ 
//@ loc_4A4B:				; CODE XREF: ExpandWall+3B2j
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 637
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 638
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 639
//@ 		mov	bx, WXSize	; int16_t
//@ ; #line	"PS10.PAS" 640
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 641
//@ 		mov	bx, ty1$0	; int16_t
//@ ; #line	"PS10.PAS" 642
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 643
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 648
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 649
//@ 		mov	ax, sl		; uint16_t
//@ ; #line	"PS10.PAS" 650
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 651
//@ 		mov	bx, ty2$0	; int16_t
//@ ; #line	"PS10.PAS" 652
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 653
//@ 		mov	di, 0EBCAh
//@ ; #line	"PS10.PAS" 654
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 659
//@ 		mov	ax, ty1$0	; int16_t
//@ 		cmp	ax, ty2$0	; int16_t
//@ 		jl	short loc_4A87	; Jump if Less (SF!=OF)
//@ 		jmp	loc_4C25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 660
//@ 
//@ loc_4A87:				; CODE XREF: ExpandWall+3F1j
//@ 		mov	ax, _x2		; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, _x1		; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jbe	short loc_4A98	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_4C22	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4A98:				; CODE XREF: ExpandWall+402j
//@ 		mov	_X, ax		; uint16_t
//@ 		jmp	short loc_4AA1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4A9D:				; CODE XREF: ExpandWall+58Ej
//@ 		inc	_X		; uint16_t
//@ ; #line	"PS10.PAS" 662
//@ 
//@ loc_4AA1:				; CODE XREF: ExpandWall+40Aj
//@ 		mov	di, Sx1		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		mov	oldy, ax	; uint16_t
//@ ; #line	"PS10.PAS" 663
//@ 		mov	ax, sh1		; uint16_t
//@ 		mul	_X		; uint16_t
//@ 		div	sl		; uint16_t
//@ 		mov	bx, ys11	; uint16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		mov	ys31, bx	; uint16_t
//@ ; #line	"PS10.PAS" 664
//@ 		mov	ax, oldy	; uint16_t
//@ 		cmp	ax, ys31	; uint16_t
//@ 		jb	short loc_4ACF	; Jump if Below	(CF=1)
//@ 		jmp	loc_4C13	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 666
//@ 
//@ loc_4ACF:				; CODE XREF: ExpandWall+439j
//@ 		mov	[bp+ExpandWall], 1 ; bool
//@ ; #line	"PS10.PAS" 667
//@ 		cmp	oldy, 0		; uint16_t
//@ 		jnz	short loc_4ADE	; Jump if Not Zero (ZF=0)
//@ 		inc	Nlines		; uint16_t
//@ ; #line	"PS10.PAS" 669
//@ 
//@ loc_4ADE:				; CODE XREF: ExpandWall+447j
//@ 		mov	ax, sh2		; uint16_t
//@ 		mov	bx, _X		; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, sl		; uint16_t
//@ 		div	sl		; uint16_t
//@ 		mov	bx, ys12	; uint16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		mov	ys32, bx	; uint16_t
//@ ; #line	"PS10.PAS" 670
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 671
//@ 		mov	bx, ys31	; uint16_t
//@ 		shr	bx, 4		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 672
//@ 		mov	cx, ys32	; uint16_t
//@ 		shr	cx, 4		; Shift	Logical	Right
//@ 		add	bx, cx		; Add
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 673
//@ 		cmp	ax, 10h		; Compare Two Operands
//@ 		jb	short loc_4B18	; Jump if Below	(CF=1)
//@ 		mov	ax, 10h
//@ ; #line	"PS10.PAS" 674
//@ 
//@ loc_4B18:				; CODE XREF: ExpandWall+482j
//@ 		mov	HlBr, ax	; uint16_t
//@ ; #line	"PS10.PAS" 678
//@ 		mov	di, 0EBCEh
//@ ; #line	"PS10.PAS" 679
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 680
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 681
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 682
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 683
//@ 		mov	ecx, eax
//@ ; #line	"PS10.PAS" 684
//@ 		mov	di, 0EBCAh
//@ ; #line	"PS10.PAS" 685
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 686
//@ 		sub	eax, ecx	; Integer Subtraction
//@ ; #line	"PS10.PAS" 687
//@ 		mov	ecx, eax
//@ ; #line	"PS10.PAS" 690
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 691
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 692
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 693
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 694
//@ 		mov	ebx, ecx
//@ ; #line	"PS10.PAS" 695
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 697
//@ 		mov	di, 0EBC6h
//@ ; #line	"PS10.PAS" 698
//@ 		add	eax, [di]	; Add
//@ ; #line	"PS10.PAS" 700
//@ 		mov	cl, LB		; uint8_t
//@ ; #line	"PS10.PAS" 701
//@ 		shr	eax, cl		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 702
//@ 		and	ax, AliasMask	; uint16_t
//@ ; #line	"PS10.PAS" 703
//@ 		mov	Ims, ax		; uint16_t
//@ ; #line	"PS10.PAS" 706
//@ 		mov	bx, Sx1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 707
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 708
//@ 		mov	ax, ImSeg	; uint16_t
//@ 		mov	es:[bx], ax
//@ ; #line	"PS10.PAS" 709
//@ 		mov	ax, Ims		; uint16_t
//@ 		and	ax, XOfsMask	; uint16_t
//@ 		mov	es:[bx+800h], ax
//@ ; #line	"PS10.PAS" 710
//@ 		mov	ax, ys31	; uint16_t
//@ 		mov	[bx-7DD2h], ax
//@ ; #line	"PS10.PAS" 711
//@ 		mov	ax, ys32	; uint16_t
//@ 		mov	[bx-7734h], ax
//@ ; #line	"PS10.PAS" 713
//@ 		mov	ax, WShadowSeg	; uint16_t
//@ 		mov	es, ax
//@ 		mov	ax, Ims		; uint16_t
//@ ; #line	"PS10.PAS" 715
//@ 		mov	cl, SHRC	; uint8_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 717
//@ 		cmp	ax, 8		; Compare Two Operands
//@ 		jb	short loc_4BC4	; Jump if Below	(CF=1)
//@ 		cmp	ax, 78h	; 'x'   ; Compare Two Operands
//@ 		jnb	short loc_4BDC	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 720
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		mov	di, ax
//@ 		shr	di, 4		; Shift	Logical	Right
//@ 		and	ax, 0Fh		; Logical AND
//@ ; #line	"PS10.PAS" 721
//@ 		add	di, WShadowOfs	; uint16_t
//@ ; #line	"PS10.PAS" 722
//@ 		mov	dh, es:[di]
//@ ; #line	"PS10.PAS" 723
//@ 		mov	dl, es:[di+1]
//@ 		sub	dl, dh		; Integer Subtraction
//@ ; #line	"PS10.PAS" 724
//@ 		imul	dl		; Signed Multiply
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		add	al, dh		; Add
//@ 		jmp	short loc_4BF8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 726
//@ 
//@ loc_4BC4:				; CODE XREF: ExpandWall+50Bj
//@ 		sub	al, 8		; Integer Subtraction
//@ 		mov	di, WShadowOfs	; uint16_t
//@ ; #line	"PS10.PAS" 727
//@ 		mov	dh, es:[di]
//@ ; #line	"PS10.PAS" 728
//@ 		mov	dl, es:[di+1]
//@ 		sub	dl, dh		; Integer Subtraction
//@ ; #line	"PS10.PAS" 729
//@ 		imul	dl		; Signed Multiply
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		add	al, dh		; Add
//@ 		jmp	short loc_4BF8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 731
//@ 
//@ loc_4BDC:				; CODE XREF: ExpandWall+510j
//@ 		sub	ax, 76h	; 'v'   ; Integer Subtraction
//@ ; #line	"PS10.PAS" 732
//@ 		mov	di, 7
//@ 		add	di, WShadowOfs	; uint16_t
//@ ; #line	"PS10.PAS" 733
//@ 		mov	dh, es:[di]
//@ ; #line	"PS10.PAS" 734
//@ 		mov	dl, dh
//@ 		sub	dl, es:[di-1]	; Integer Subtraction
//@ ; #line	"PS10.PAS" 735
//@ 		imul	dl		; Signed Multiply
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		add	al, dh		; Add
//@ 		jmp	short $+2	; Jump
//@ ; #line	"PS10.PAS" 738
//@ 
//@ loc_4BF8:				; CODE XREF: ExpandWall+531j
//@ 					; ExpandWall+549j
//@ 		add	ax, HlBr	; uint16_t
//@ ; #line	"PS10.PAS" 739
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jge	short loc_4C02	; Jump if Greater or Equal (SF=OF)
//@ 		xor	al, al		; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 740
//@ 
//@ loc_4C02:				; CODE XREF: ExpandWall+56Dj
//@ 		cmp	al, 33h	; '3'   ; Compare Two Operands
//@ 		jle	short loc_4C08	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	al, 33h	; '3'
//@ ; #line	"PS10.PAS" 741
//@ 
//@ loc_4C08:				; CODE XREF: ExpandWall+573j
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 742
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 743
//@ 		mov	es:[bx+2000h], al
//@ ; #line	"PS10.PAS" 749
//@ 
//@ loc_4C13:				; CODE XREF: ExpandWall+43Bj
//@ 		inc	Sx1		; int16_t
//@ ; #line	"PS10.PAS" 750
//@ 		mov	ax, _X		; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short loc_4C22	; Jump if Zero (ZF=1)
//@ 		jmp	loc_4A9D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4C22:				; CODE XREF: ExpandWall+404j
//@ 					; ExpandWall+58Cj
//@ 		jmp	loc_4DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 752
//@ 
//@ loc_4C25:				; CODE XREF: ExpandWall+3F3j
//@ 		mov	ax, _x2		; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, _x1		; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jbe	short loc_4C36	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_4DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4C36:				; CODE XREF: ExpandWall+5A0j
//@ 		mov	_X, ax		; uint16_t
//@ 		jmp	short loc_4C3F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4C3B:				; CODE XREF: ExpandWall+71Dj
//@ 		inc	_X		; uint16_t
//@ ; #line	"PS10.PAS" 754
//@ 
//@ loc_4C3F:				; CODE XREF: ExpandWall+5A8j
//@ 		mov	di, Sx1		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		mov	oldy, ax	; uint16_t
//@ ; #line	"PS10.PAS" 755
//@ 		mov	ax, sh1		; uint16_t
//@ 		mul	_X		; uint16_t
//@ 		div	sl		; uint16_t
//@ 		add	ax, ys11	; uint16_t
//@ 		mov	ys31, ax	; uint16_t
//@ ; #line	"PS10.PAS" 756
//@ 		mov	ax, oldy	; uint16_t
//@ 		cmp	ax, ys31	; uint16_t
//@ 		jb	short loc_4C6A	; Jump if Below	(CF=1)
//@ 		jmp	loc_4DA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 758
//@ 
//@ loc_4C6A:				; CODE XREF: ExpandWall+5D4j
//@ 		mov	[bp+ExpandWall], 1 ; bool
//@ ; #line	"PS10.PAS" 759
//@ 		cmp	oldy, 0		; uint16_t
//@ 		jnz	short loc_4C79	; Jump if Not Zero (ZF=0)
//@ 		inc	Nlines		; uint16_t
//@ ; #line	"PS10.PAS" 761
//@ 
//@ loc_4C79:				; CODE XREF: ExpandWall+5E2j
//@ 		mov	ax, sh2		; uint16_t
//@ 		mov	bx, _X		; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, sl		; uint16_t
//@ 		div	sl		; uint16_t
//@ 		add	ax, ys12	; uint16_t
//@ 		mov	ys32, ax	; uint16_t
//@ ; #line	"PS10.PAS" 762
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 763
//@ 		mov	bx, ys31	; uint16_t
//@ 		shr	bx, 4		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 764
//@ 		mov	cx, ys32	; uint16_t
//@ 		shr	cx, 4		; Shift	Logical	Right
//@ 		add	bx, cx		; Add
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 765
//@ 		cmp	ax, 10h		; Compare Two Operands
//@ 		jb	short loc_4CB0	; Jump if Below	(CF=1)
//@ 		mov	ax, 10h
//@ ; #line	"PS10.PAS" 766
//@ 
//@ loc_4CB0:				; CODE XREF: ExpandWall+61Aj
//@ 		mov	HlBr, ax	; uint16_t
//@ ; #line	"PS10.PAS" 770
//@ 		mov	di, 0EBCEh
//@ ; #line	"PS10.PAS" 771
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 772
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 773
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 774
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 775
//@ 		mov	ecx, eax
//@ ; #line	"PS10.PAS" 776
//@ 		mov	di, 0EBCAh
//@ ; #line	"PS10.PAS" 777
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 778
//@ 		add	ecx, eax	; Add
//@ ; #line	"PS10.PAS" 781
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 782
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 783
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 784
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 785
//@ 		mov	ebx, ecx
//@ ; #line	"PS10.PAS" 786
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 787
//@ 		mov	cl, LB		; uint8_t
//@ ; #line	"PS10.PAS" 788
//@ 		shr	eax, cl		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 789
//@ 		and	ax, AliasMask	; uint16_t
//@ ; #line	"PS10.PAS" 790
//@ 		mov	Ims, ax		; uint16_t
//@ ; #line	"PS10.PAS" 801
//@ 		mov	bx, Sx1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 802
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 803
//@ 		mov	ax, ImSeg	; uint16_t
//@ 		mov	es:[bx], ax
//@ ; #line	"PS10.PAS" 804
//@ 		mov	ax, Ims		; uint16_t
//@ 		and	ax, XOfsMask	; uint16_t
//@ 		mov	es:[bx+800h], ax
//@ ; #line	"PS10.PAS" 805
//@ 		mov	ax, ys31	; uint16_t
//@ 		mov	[bx-7DD2h], ax
//@ ; #line	"PS10.PAS" 806
//@ 		mov	ax, ys32	; uint16_t
//@ 		mov	[bx-7734h], ax
//@ ; #line	"PS10.PAS" 808
//@ 		mov	ax, WShadowSeg	; uint16_t
//@ 		mov	es, ax
//@ 		mov	ax, Ims		; uint16_t
//@ ; #line	"PS10.PAS" 810
//@ 		mov	cl, SHRC	; uint8_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 813
//@ 		cmp	ax, 8		; Compare Two Operands
//@ 		jb	short loc_4D53	; Jump if Below	(CF=1)
//@ 		cmp	ax, 78h	; 'x'   ; Compare Two Operands
//@ 		jnb	short loc_4D6B	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 816
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		mov	di, ax
//@ 		shr	di, 4		; Shift	Logical	Right
//@ 		and	ax, 0Fh		; Logical AND
//@ ; #line	"PS10.PAS" 817
//@ 		add	di, WShadowOfs	; uint16_t
//@ ; #line	"PS10.PAS" 818
//@ 		mov	dh, es:[di]
//@ ; #line	"PS10.PAS" 819
//@ 		mov	dl, es:[di+1]
//@ 		sub	dl, dh		; Integer Subtraction
//@ ; #line	"PS10.PAS" 820
//@ 		imul	dl		; Signed Multiply
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		add	al, dh		; Add
//@ 		jmp	short loc_4D87	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 822
//@ 
//@ loc_4D53:				; CODE XREF: ExpandWall+69Aj
//@ 		sub	al, 8		; Integer Subtraction
//@ 		mov	di, WShadowOfs	; uint16_t
//@ ; #line	"PS10.PAS" 823
//@ 		mov	dh, es:[di]
//@ ; #line	"PS10.PAS" 824
//@ 		mov	dl, es:[di+1]
//@ 		sub	dl, dh		; Integer Subtraction
//@ ; #line	"PS10.PAS" 825
//@ 		imul	dl		; Signed Multiply
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		add	al, dh		; Add
//@ 		jmp	short loc_4D87	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 827
//@ 
//@ loc_4D6B:				; CODE XREF: ExpandWall+69Fj
//@ 		sub	ax, 76h	; 'v'   ; Integer Subtraction
//@ ; #line	"PS10.PAS" 828
//@ 		mov	di, 7
//@ 		add	di, WShadowOfs	; uint16_t
//@ ; #line	"PS10.PAS" 829
//@ 		mov	dh, es:[di]
//@ ; #line	"PS10.PAS" 830
//@ 		mov	dl, dh
//@ 		sub	dl, es:[di-1]	; Integer Subtraction
//@ ; #line	"PS10.PAS" 831
//@ 		imul	dl		; Signed Multiply
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		add	al, dh		; Add
//@ 		jmp	short $+2	; Jump
//@ ; #line	"PS10.PAS" 834
//@ 
//@ loc_4D87:				; CODE XREF: ExpandWall+6C0j
//@ 					; ExpandWall+6D8j
//@ 		add	ax, HlBr	; uint16_t
//@ ; #line	"PS10.PAS" 835
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jge	short loc_4D91	; Jump if Greater or Equal (SF=OF)
//@ 		xor	al, al		; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 836
//@ 
//@ loc_4D91:				; CODE XREF: ExpandWall+6FCj
//@ 		cmp	al, 33h	; '3'   ; Compare Two Operands
//@ 		jle	short loc_4D97	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	al, 33h	; '3'
//@ ; #line	"PS10.PAS" 837
//@ 
//@ loc_4D97:				; CODE XREF: ExpandWall+702j
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 838
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 839
//@ 		mov	es:[bx+2000h], al
//@ ; #line	"PS10.PAS" 845
//@ 
//@ loc_4DA2:				; CODE XREF: ExpandWall+5D6j
//@ 		inc	Sx1		; int16_t
//@ ; #line	"PS10.PAS" 846
//@ 		mov	ax, _X		; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short loc_4DB1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_4C3B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 847
//@ 
//@ loc_4DB1:				; CODE XREF: ExpandWall+4Dj
//@ 					; ExpandWall+D9j ...
//@ 		mov	al, [bp+ExpandWall] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ ExpandWall	endp
//@ 
//@ ; #line	"PS10.PAS" 859
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SwapI		proc near		; CODE XREF: ExpandFrame+16Cp
//@ 					; ExpandFrame+17Ap
//@ 
//@ i		= word ptr -2		; int16_t
//@ i2		= dword	ptr  6		; int16_t
//@ i1		= dword	ptr  0Ah	; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 860
//@ 		les	di, [bp+i1]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		les	di, [bp+i2]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+i1]	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		les	di, [bp+i2]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"PS10.PAS" 861
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ SwapI		endp
//@ 
//@ ; #line	"PS10.PAS" 863
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandFrame	proc near		; CODE XREF: Build3dScene+25Bp
//@ 					; DoGame+17A4p
//@ 
//@ var_8		= dword	ptr -8
//@ VUP		= dword	ptr -4		; void (*)()
//@ oyy		= word ptr  4		; uint16_t
//@ oxx		= word ptr  6		; uint16_t
//@ Flags		= word ptr  8		; uint16_t
//@ ty2		= word ptr  0Ah		; int16_t
//@ tx2		= word ptr  0Ch		; int16_t
//@ ty1		= word ptr  0Eh		; int16_t
//@ tx1		= word ptr  10h		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 864
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jg	short loc_4DF1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	[bp+ty2], 0	; int16_t
//@ 		jg	short loc_4DF1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	locret_540B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4DF1:				; CODE XREF: ExpandFrame+8j
//@ 					; ExpandFrame+Ej
//@ 		mov	ax, word ptr Long1 ; int32_t
//@ 		mov	dx, word ptr Long1+2 ; int32_t
//@ 		mov	word ptr Esl, ax ; int32_t
//@ 		mov	word ptr Esl+2,	dx ; int32_t
//@ ; #line	"PS10.PAS" 865
//@ 		imul	ax, [bp+oyy], 0Bh ; uint16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+oxx], 2C0h ; uint16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"PS10.PAS" 867
//@ 		mov	al, es:[di]
//@ 		mov	c, al		; uint8_t
//@ 		mov	al, es:[di]
//@ 		dec	al		; Decrement by 1
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+70B2h]
//@ 		mov	ImSeg, ax	; uint16_t
//@ ; #line	"PS10.PAS" 868
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+1]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	WXSize,	ax	; int16_t
//@ 		mov	ax, [bp+oxx]	; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+oyy]	; uint16_t
//@ 		shl	ax, 9		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	CurShOfs, ax	; uint16_t
//@ ; #line	"PS10.PAS" 869
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_4E68	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	XOfsMask, 3Fh ;	'?' ; uint16_t
//@ 		jmp	short loc_4E6E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4E68:				; CODE XREF: ExpandFrame+80j
//@ 		mov	XOfsMask, 7Fh ;	'' ; uint16_t
//@ ; #line	"PS10.PAS" 874
//@ 
//@ loc_4E6E:				; CODE XREF: ExpandFrame+88j
//@ 		cmp	[bp+ty2], 0	; int16_t
//@ 		jge	short loc_4EAE	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 878
//@ 		mov	di, 26h	; '&'
//@ ; #line	"PS10.PAS" 879
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 880
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 881
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 882
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 883
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 884
//@ 		sub	bx, [bp+ty2]	; int16_t
//@ ; #line	"PS10.PAS" 885
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 886
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 887
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 891
//@ 		mov	ax, [bp+tx1]	; int16_t
//@ ; #line	"PS10.PAS" 892
//@ 		mov	cx, ax
//@ ; #line	"PS10.PAS" 893
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 894
//@ 		sub	ax, [bp+tx2]	; int16_t
//@ ; #line	"PS10.PAS" 895
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"PS10.PAS" 896
//@ 		sub	bx, [bp+ty2]	; int16_t
//@ ; #line	"PS10.PAS" 897
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"PS10.PAS" 898
//@ 		sub	cx, ax		; Integer Subtraction
//@ ; #line	"PS10.PAS" 899
//@ 		mov	[bp+tx2], cx	; int16_t
//@ ; #line	"PS10.PAS" 901
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ty2], ax	; int16_t
//@ ; #line	"PS10.PAS" 904
//@ 
//@ loc_4EAE:				; CODE XREF: ExpandFrame+94j
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jge	short loc_4EEE	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 908
//@ 		mov	di, 26h	; '&'
//@ ; #line	"PS10.PAS" 909
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 910
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 911
//@ 		mov	bx, [bp+ty2]	; int16_t
//@ ; #line	"PS10.PAS" 912
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 913
//@ 		mov	bx, [bp+ty2]	; int16_t
//@ ; #line	"PS10.PAS" 914
//@ 		sub	bx, [bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 915
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 916
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 917
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 921
//@ 		mov	ax, [bp+tx2]	; int16_t
//@ ; #line	"PS10.PAS" 922
//@ 		mov	cx, ax
//@ ; #line	"PS10.PAS" 923
//@ 		mov	bx, [bp+ty2]	; int16_t
//@ ; #line	"PS10.PAS" 924
//@ 		sub	ax, [bp+tx1]	; int16_t
//@ ; #line	"PS10.PAS" 925
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"PS10.PAS" 926
//@ 		sub	bx, [bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 927
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"PS10.PAS" 928
//@ 		sub	cx, ax		; Integer Subtraction
//@ ; #line	"PS10.PAS" 929
//@ 		mov	[bp+tx1], cx	; int16_t
//@ ; #line	"PS10.PAS" 931
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ty1], ax	; int16_t
//@ ; #line	"PS10.PAS" 934
//@ 
//@ loc_4EEE:				; CODE XREF: ExpandFrame+D4j
//@ 		add	[bp+ty1], 60h ;	'`' ; int16_t
//@ 		add	[bp+ty2], 60h ;	'`' ; int16_t
//@ ; #line	"PS10.PAS" 935
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		add	ax, 400h	; Add
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+tx1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jle	short loc_4F0F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_540B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 937
//@ 
//@ loc_4F0F:				; CODE XREF: ExpandFrame+12Cj
//@ 		mov	ax, [bp+tx1]	; int16_t
//@ 		mov	bx, WallW	; uint16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		mov	Sx1, ax		; int16_t
//@ ; #line	"PS10.PAS" 938
//@ 		mov	ax, [bp+tx2]	; int16_t
//@ 		mov	bx, WallW	; uint16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, [bp+ty2]	; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		mov	Sx2, ax		; int16_t
//@ ; #line	"PS10.PAS" 941
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	XORMask, ax	; uint16_t
//@ ; #line	"PS10.PAS" 942
//@ 		mov	ax, Sx1		; int16_t
//@ 		cmp	ax, Sx2		; int16_t
//@ 		jle	short loc_4F62	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, offset Sx1	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Sx2	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	bp
//@ 		call	SwapI		; function nested near PASCAL returns void
//@ 		lea	di, [bp+ty1]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+ty2]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		push	bp
//@ 		call	SwapI		; function nested near PASCAL returns void
//@ 		mov	ax, WXSize	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	XORMask, ax	; uint16_t
//@ ; #line	"PS10.PAS" 943
//@ 
//@ loc_4F62:				; CODE XREF: ExpandFrame+15Fj
//@ 		mov	ax, Sx2		; int16_t
//@ 		sub	ax, Sx1		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	sl, ax		; uint16_t
//@ ; #line	"PS10.PAS" 944
//@ 		cmp	sl, 2		; uint16_t
//@ 		jnb	short loc_4F7A	; Jump if Not Below (CF=0)
//@ 		mov	sl, 2		; uint16_t
//@ 
//@ loc_4F7A:				; CODE XREF: ExpandFrame+194j
//@ 		mov	ax, sl		; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	slp, ax		; uint16_t
//@ ; #line	"PS10.PAS" 945
//@ 		mov	ax, WinW2i	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, Sx2		; int16_t
//@ 		jge	short loc_4F95	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, Sx1		; int16_t
//@ 		cmp	ax, WinW2i	; int16_t
//@ 		jl	short loc_4F98	; Jump if Less (SF!=OF)
//@ 
//@ loc_4F95:				; CODE XREF: ExpandFrame+1ACj
//@ 		jmp	locret_540B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 947
//@ 
//@ loc_4F98:				; CODE XREF: ExpandFrame+1B5j
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		add	Sx1, ax		; int16_t
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		add	Sx2, ax		; int16_t
//@ ; #line	"PS10.PAS" 948
//@ 		mov	ax, WinSX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_4FBD	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_4FC4	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_4FC4	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_4FBD:				; CODE XREF: ExpandFrame+1D7j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	_x1, ax		; uint16_t
//@ 		jmp	short loc_4FD8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4FC4:				; CODE XREF: ExpandFrame+1D9j
//@ 					; ExpandFrame+1DDj
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinSX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	_x1, ax		; uint16_t
//@ ; #line	"PS10.PAS" 949
//@ 
//@ loc_4FD8:				; CODE XREF: ExpandFrame+1E4j
//@ 		mov	ax, sl		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinEX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_4FFC	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_5005	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_5005	; Jump if Below	(CF=1)
//@ 
//@ loc_4FFC:				; CODE XREF: ExpandFrame+216j
//@ 		mov	ax, sl		; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	_x2, ax		; uint16_t
//@ 		jmp	short loc_5019	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5005:				; CODE XREF: ExpandFrame+218j
//@ 					; ExpandFrame+21Cj
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinEX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	_x2, ax		; uint16_t
//@ ; #line	"PS10.PAS" 950
//@ 
//@ loc_5019:				; CODE XREF: ExpandFrame+225j
//@ 		mov	ax, Sx1		; int16_t
//@ 		add	ax, _x1		; uint16_t
//@ 		mov	Sx11, ax	; int16_t
//@ ; #line	"PS10.PAS" 951
//@ 		mov	ax, Sx1		; int16_t
//@ 		add	ax, _x2		; uint16_t
//@ 		mov	Sx21, ax	; int16_t
//@ ; #line	"PS10.PAS" 956
//@ 		push	word ptr LinesBUF+2 ; TLinesBuf*
//@ 		mov	ax, Sx11	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		db	26h
//@ 		lea	ax, [di+800h]	; Load Effective Address
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		mov	ax, Sx21	; int16_t
//@ 		sub	ax, Sx11	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	0FFFFh
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 961
//@ 		mov	cx, WallH	; uint16_t
//@ 		add	cx, 2		; Add
//@ ; #line	"PS10.PAS" 962
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, Hz2		; uint16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys11, ax	; uint16_t
//@ ; #line	"PS10.PAS" 963
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, ehz		; int16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys12, ax	; uint16_t
//@ ; #line	"PS10.PAS" 964
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, Hz2		; uint16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, [bp+ty2]	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys21, ax	; uint16_t
//@ ; #line	"PS10.PAS" 965
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, ehz		; int16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, [bp+ty2]	; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	ys22, ax	; uint16_t
//@ ; #line	"PS10.PAS" 968
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		cmp	ax, [bp+ty2]	; int16_t
//@ 		jg	short loc_50CA	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, [bp+ty2]	; int16_t
//@ 		sub	ax, [bp+ty1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	word ptr SLy, ax ; int32_t
//@ 		mov	word ptr SLy+2,	dx ; int32_t
//@ 		mov	ax, ys11	; uint16_t
//@ 		sub	ax, ys21	; uint16_t
//@ 		mov	sh1, ax		; uint16_t
//@ 		mov	ax, ys12	; uint16_t
//@ 		sub	ax, ys22	; uint16_t
//@ 		mov	sh2, ax		; uint16_t
//@ 		jmp	short loc_50EC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 969
//@ 
//@ loc_50CA:				; CODE XREF: ExpandFrame+2C6j
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		sub	ax, [bp+ty2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	word ptr SLy, ax ; int32_t
//@ 		mov	word ptr SLy+2,	dx ; int32_t
//@ 		mov	ax, ys21	; uint16_t
//@ 		sub	ax, ys11	; uint16_t
//@ 		mov	sh1, ax		; uint16_t
//@ 		mov	ax, ys22	; uint16_t
//@ 		sub	ax, ys12	; uint16_t
//@ 		mov	sh2, ax		; uint16_t
//@ ; #line	"PS10.PAS" 971
//@ 
//@ loc_50EC:				; CODE XREF: ExpandFrame+2EAj
//@ 		mov	ax, word ptr Esl ; int32_t
//@ 		mov	dx, word ptr Esl+2 ; int32_t
//@ 		cmp	dx, word ptr Long1+2 ; int32_t
//@ 		jnz	short loc_50FF	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, word ptr Long1 ; int32_t
//@ 		jz	short loc_511D	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 973
//@ 
//@ loc_50FF:				; CODE XREF: ExpandFrame+319j
//@ 		mov	di, 26h	; '&'
//@ ; #line	"PS10.PAS" 974
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 975
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 976
//@ 		sub	eax, [di]	; Integer Subtraction
//@ ; #line	"PS10.PAS" 977
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 978
//@ 		mov	bx, WXSize	; int16_t
//@ ; #line	"PS10.PAS" 979
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 980
//@ 		mov	di, 0EBC6h
//@ ; #line	"PS10.PAS" 981
//@ 		mov	[di], eax
//@ 		jmp	short loc_5125	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 982
//@ 
//@ loc_511D:				; CODE XREF: ExpandFrame+31Fj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr Io0, ax ; int32_t
//@ 		mov	word ptr Io0+2,	ax ; int32_t
//@ ; #line	"PS10.PAS" 984
//@ 
//@ loc_5125:				; CODE XREF: ExpandFrame+33Dj
//@ 		cmp	_x1, 0		; uint16_t
//@ 		jbe	short loc_5132	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ax, WinSX	; uint16_t
//@ 		mov	Sx1, ax		; int16_t
//@ ; #line	"PS10.PAS" 989
//@ 
//@ loc_5132:				; CODE XREF: ExpandFrame+34Cj
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 990
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 991
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 992
//@ 		mov	bx, WXSize	; int16_t
//@ ; #line	"PS10.PAS" 993
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 994
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 995
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 996
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 1001
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 1002
//@ 		mov	ax, sl		; uint16_t
//@ ; #line	"PS10.PAS" 1003
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 1004
//@ 		mov	bx, [bp+ty2]	; int16_t
//@ ; #line	"PS10.PAS" 1005
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 1006
//@ 		mov	di, 0EBCAh
//@ ; #line	"PS10.PAS" 1007
//@ 		mov	[di], eax
//@ ; #line	"PS10.PAS" 1016
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		cmp	ax, [bp+ty2]	; int16_t
//@ 		jl	short loc_516B	; Jump if Less (SF!=OF)
//@ 		jmp	loc_525D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1017
//@ 
//@ loc_516B:				; CODE XREF: ExpandFrame+388j
//@ 		mov	ax, _x2		; uint16_t
//@ 		mov	word ptr [bp+var_8+2], ax
//@ 		mov	ax, _x1		; uint16_t
//@ 		cmp	ax, word ptr [bp+var_8+2] ; Compare Two	Operands
//@ 		jbe	short loc_517C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_525A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_517C:				; CODE XREF: ExpandFrame+399j
//@ 		mov	_X, ax		; uint16_t
//@ 		jmp	short loc_5185	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5181:				; CODE XREF: ExpandFrame+479j
//@ 		inc	_X		; uint16_t
//@ ; #line	"PS10.PAS" 1019
//@ 
//@ loc_5185:				; CODE XREF: ExpandFrame+3A1j
//@ 		mov	di, Sx1		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	oldy, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1020
//@ 		mov	ax, sh1		; uint16_t
//@ 		mul	_X		; uint16_t
//@ 		div	slp		; uint16_t
//@ 		mov	bx, ys11	; uint16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		mov	ys31, bx	; uint16_t
//@ ; #line	"PS10.PAS" 1021
//@ 		mov	ax, oldy	; uint16_t
//@ 		cmp	ax, ys31	; uint16_t
//@ 		jbe	short loc_51B4	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_524B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1023
//@ 
//@ loc_51B4:				; CODE XREF: ExpandFrame+3D1j
//@ 		mov	ax, sh2		; uint16_t
//@ 		mul	_X		; uint16_t
//@ 		div	slp		; uint16_t
//@ 		mov	bx, ys12	; uint16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		mov	ys32, bx	; uint16_t
//@ ; #line	"PS10.PAS" 1024
//@ 		mov	dx, ys31	; uint16_t
//@ 		mov	ax, Sx1		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+1000h], dx
//@ 		mov	dx, ys32	; uint16_t
//@ 		mov	ax, Sx1		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+1800h], dx
//@ ; #line	"PS10.PAS" 1026
//@ 		mov	di, 0EBCEh
//@ ; #line	"PS10.PAS" 1027
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 1028
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 1029
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 1030
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 1031
//@ 		mov	ecx, eax
//@ ; #line	"PS10.PAS" 1032
//@ 		mov	di, 0EBCAh
//@ ; #line	"PS10.PAS" 1033
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 1034
//@ 		sub	eax, ecx	; Integer Subtraction
//@ ; #line	"PS10.PAS" 1035
//@ 		mov	ecx, eax
//@ ; #line	"PS10.PAS" 1038
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 1039
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 1040
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 1041
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 1042
//@ 		mov	ebx, ecx
//@ ; #line	"PS10.PAS" 1043
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 1045
//@ 		mov	di, 0EBC6h
//@ ; #line	"PS10.PAS" 1046
//@ 		add	eax, [di]	; Add
//@ ; #line	"PS10.PAS" 1048
//@ 		mov	cl, LB		; uint8_t
//@ ; #line	"PS10.PAS" 1049
//@ 		shr	eax, cl		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 1050
//@ 		xor	ax, XORMask	; uint16_t
//@ ; #line	"PS10.PAS" 1052
//@ 		mov	Ims, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1054
//@ 		mov	dx, Ims		; uint16_t
//@ 		mov	ax, Sx1		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+800h], dx
//@ ; #line	"PS10.PAS" 1056
//@ 
//@ loc_524B:				; CODE XREF: ExpandFrame+3D3j
//@ 		inc	Sx1		; int16_t
//@ ; #line	"PS10.PAS" 1057
//@ 		mov	ax, _X		; uint16_t
//@ 		cmp	ax, word ptr [bp+var_8+2] ; Compare Two	Operands
//@ 		jz	short loc_525A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_5181	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_525A:				; CODE XREF: ExpandFrame+39Bj
//@ 					; ExpandFrame+477j
//@ 		jmp	loc_533D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1059
//@ 
//@ loc_525D:				; CODE XREF: ExpandFrame+38Aj
//@ 		mov	ax, _x2		; uint16_t
//@ 		mov	word ptr [bp+var_8+2], ax
//@ 		mov	ax, _x1		; uint16_t
//@ 		cmp	ax, word ptr [bp+var_8+2] ; Compare Two	Operands
//@ 		jbe	short loc_526E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_533D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_526E:				; CODE XREF: ExpandFrame+48Bj
//@ 		mov	_X, ax		; uint16_t
//@ 		jmp	short loc_5277	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5273:				; CODE XREF: ExpandFrame+55Cj
//@ 		inc	_X		; uint16_t
//@ ; #line	"PS10.PAS" 1061
//@ 
//@ loc_5277:				; CODE XREF: ExpandFrame+493j
//@ 		mov	di, Sx1		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	oldy, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1062
//@ 		mov	ax, sh1		; uint16_t
//@ 		mul	_X		; uint16_t
//@ 		div	slp		; uint16_t
//@ 		add	ax, ys11	; uint16_t
//@ 		mov	ys31, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1063
//@ 		mov	ax, oldy	; uint16_t
//@ 		cmp	ax, ys31	; uint16_t
//@ 		jbe	short loc_52A3	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_532E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1065
//@ 
//@ loc_52A3:				; CODE XREF: ExpandFrame+4C0j
//@ 		mov	ax, sh2		; uint16_t
//@ 		mul	_X		; uint16_t
//@ 		div	slp		; uint16_t
//@ 		add	ax, ys12	; uint16_t
//@ 		mov	ys32, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1066
//@ 		mov	dx, ys31	; uint16_t
//@ 		mov	ax, Sx1		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+1000h], dx
//@ 		mov	dx, ys32	; uint16_t
//@ 		mov	ax, Sx1		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+1800h], dx
//@ ; #line	"PS10.PAS" 1068
//@ 		mov	di, 0EBCEh
//@ ; #line	"PS10.PAS" 1069
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 1070
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"PS10.PAS" 1071
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 1072
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 1073
//@ 		mov	ecx, eax
//@ ; #line	"PS10.PAS" 1074
//@ 		mov	di, 0EBCAh
//@ ; #line	"PS10.PAS" 1075
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 1076
//@ 		add	ecx, eax	; Add
//@ ; #line	"PS10.PAS" 1079
//@ 		mov	di, 0EBC2h
//@ ; #line	"PS10.PAS" 1080
//@ 		mov	eax, [di]
//@ ; #line	"PS10.PAS" 1081
//@ 		mov	bx, _X		; uint16_t
//@ ; #line	"PS10.PAS" 1082
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 1083
//@ 		mov	ebx, ecx
//@ ; #line	"PS10.PAS" 1084
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 1085
//@ 		mov	cl, LB		; uint8_t
//@ ; #line	"PS10.PAS" 1086
//@ 		shr	eax, cl		; Shift	Logical	Right
//@ ; #line	"PS10.PAS" 1087
//@ 		xor	ax, XORMask	; uint16_t
//@ ; #line	"PS10.PAS" 1089
//@ 		mov	Ims, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1091
//@ 		mov	dx, Ims		; uint16_t
//@ 		mov	ax, Sx1		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+800h], dx
//@ ; #line	"PS10.PAS" 1093
//@ 
//@ loc_532E:				; CODE XREF: ExpandFrame+4C2j
//@ 		inc	Sx1		; int16_t
//@ ; #line	"PS10.PAS" 1094
//@ 		mov	ax, _X		; uint16_t
//@ 		cmp	ax, word ptr [bp+var_8+2] ; Compare Two	Operands
//@ 		jz	short loc_533D	; Jump if Zero (ZF=1)
//@ 		jmp	loc_5273	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1097
//@ 
//@ loc_533D:				; CODE XREF: ExpandFrame:loc_525Aj
//@ 					; ExpandFrame+48Dj ...
//@ 		cmp	WXSize,	80h ; '€' ; int16_t
//@ 		jnz	short loc_534C	; Jump if Not Zero (ZF=0)
//@ 		mov	SHRC, 4		; uint8_t
//@ 		jmp	short loc_5351	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_534C:				; CODE XREF: ExpandFrame+565j
//@ 		mov	SHRC, 3		; uint8_t
//@ ; #line	"PS10.PAS" 1098
//@ 
//@ loc_5351:				; CODE XREF: ExpandFrame+56Cj
//@ 		mov	ax, Sx11	; int16_t
//@ 		mov	x$0, ax		; int16_t
//@ ; #line	"PS10.PAS" 1099
//@ 		mov	ax, [bp+Flags]	; uint16_t
//@ 		mov	ScrollK, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1100
//@ 		cmp	ScrollK, 0	; uint16_t
//@ 		jnz	short loc_5372	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, 270Ah
//@ 		mov	dx, seg	cseg01
//@ 		mov	word ptr [bp+VUP], ax ;	void (*)()
//@ 		mov	word ptr [bp+VUP+2], dx	; void (*)()
//@ 		jmp	short loc_537E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1101
//@ 
//@ loc_5372:				; CODE XREF: ExpandFrame+584j
//@ 		mov	ax, 27D1h
//@ 		mov	dx, seg	cseg01
//@ 		mov	word ptr [bp+VUP], ax ;	void (*)()
//@ 		mov	word ptr [bp+VUP+2], dx	; void (*)()
//@ ; #line	"PS10.PAS" 1103
//@ 
//@ loc_537E:				; CODE XREF: ExpandFrame+592j
//@ 					; ExpandFrame+62Aj
//@ 		mov	ax, x$0		; int16_t
//@ 		cmp	ax, Sx21	; int16_t
//@ 		jle	short loc_538A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_540B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1113
//@ 
//@ loc_538A:				; CODE XREF: ExpandFrame+5A7j
//@ 		mov	bx, x$0		; int16_t
//@ 		mov	HLxx, bx	; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 1114
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 1115
//@ 		mov	ax, es:[bx+800h]
//@ 		mov	ImOfs, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1116
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jz	short loc_5404	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1118
//@ 		mov	cl, SHRC	; uint8_t
//@ 		shr	ax, cl		; Shift	Logical	Right
//@ 		mov	cx, ax
//@ 		mov	ax, WShadowSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"PS10.PAS" 1119
//@ 		mov	di, CurShOfs	; uint16_t
//@ 		add	di, cx		; Add
//@ ; #line	"PS10.PAS" 1120
//@ 		mov	cl, es:[di]
//@ 		mov	DDark, cx	; int16_t
//@ ; #line	"PS10.PAS" 1122
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 1123
//@ 		mov	ax, es:[bx+1000h]
//@ 		mov	HLh1, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1124
//@ 		mov	ax, es:[bx+1800h]
//@ 		mov	Hlh2, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1125
//@ 		mov	ax, es:[bx+802h]
//@ ; #line	"PS10.PAS" 1126
//@ 		mov	Double,	0	; uint8_t
//@ ; #line	"PS10.PAS" 1127
//@ 		cmp	ax, ImOfs	; uint16_t
//@ 		jnz	short loc_53EC	; Jump if Not Zero (ZF=0)
//@ 		mov	Double,	1	; uint8_t
//@ 		inc	x$0		; int16_t
//@ ; #line	"PS10.PAS" 1128
//@ 
//@ loc_53EC:				; CODE XREF: ExpandFrame+603j
//@ 		mov	ax, ImSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"PS10.PAS" 1129
//@ 		mov	bx, ImOfs	; uint16_t
//@ 		and	bx, XOfsMask	; uint16_t
//@ ; #line	"PS10.PAS" 1130
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, es:[bx]
//@ 		mov	ImOfs, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1131
//@ 		call	[bp+VUP]	; void (*)()
//@ ; #line	"PS10.PAS" 1132
//@ 
//@ loc_5404:				; CODE XREF: ExpandFrame+5C5j
//@ 		inc	x$0		; int16_t
//@ 		jmp	loc_537E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1135
//@ 
//@ locret_540B:				; CODE XREF: ExpandFrame+10j
//@ 					; ExpandFrame+12Ej ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Eh		; Return Near from Procedure
//@ ExpandFrame	endp
//@ 
//@ ; #line	"PS10.PAS" 1153
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandPicture	proc near		; CODE XREF: ExpandObject+BBp
//@ 					; DrawHoles+1F9p ...
//@ 
//@ Visible		= byte ptr -1Bh		; bool
//@ y1		= word ptr -1Ah		; int16_t
//@ sxs		= word ptr -18h		; int16_t
//@ ZClip		= word ptr -16h		; int16_t
//@ H		= word ptr -14h		; uint16_t
//@ k		= word ptr -12h		; uint16_t
//@ crx		= word ptr -10h		; uint16_t
//@ HalfShr1	= word ptr -0Eh		; uint16_t
//@ O		= word ptr -0Ch		; struct TPic
//@ var_A		= word ptr -0Ah
//@ var_8		= word ptr -8
//@ var_6		= dword	ptr -6
//@ ExpandPicture	= byte ptr -1		; bool
//@ GlassMode	= byte ptr  4		; uint8_t
//@ arg_2		= dword	ptr  6
//@ Dark0		= word ptr  0Ah		; int16_t
//@ tz1		= word ptr  0Ch		; int16_t
//@ ty1		= word ptr  0Eh		; int16_t
//@ tx1		= word ptr  10h		; int16_t
//@ 
//@ 		enter	1Ch, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+O]	; struct TPic
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		mov	cx, 0Ah
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"PS10.PAS" 1154
//@ 		mov	ax, HalfShr	; uint16_t
//@ 		mov	[bp+HalfShr1], ax ; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HalfShr, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1155
//@ 		mov	ax, [bp+tx1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+tx1], ax	; int16_t
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+ty1], ax	; int16_t
//@ ; #line	"PS10.PAS" 1156
//@ 		mov	[bp+ExpandPicture], 0 ;	bool
//@ ; #line	"PS10.PAS" 1157
//@ 		cmp	[bp+ty1], 18h	; int16_t
//@ 		jg	short loc_5457	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_590C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1158
//@ 
//@ loc_5457:				; CODE XREF: ExpandPicture+43j
//@ 		add	[bp+ty1], 30h ;	'0' ; int16_t
//@ ; #line	"PS10.PAS" 1159
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		mov	_ty1, ax	; int16_t
//@ ; #line	"PS10.PAS" 1160
//@ 		cmp	_ty1, 48h ; 'H' ; int16_t
//@ 		jge	short loc_5471	; Jump if Greater or Equal (SF=OF)
//@ 		mov	_ty1, 48h ; 'H' ; int16_t
//@ ; #line	"PS10.PAS" 1162
//@ 
//@ loc_5471:				; CODE XREF: ExpandPicture+5Aj
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		add	ax, 200h	; Add
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+tx1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jle	short loc_548A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_590C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1163
//@ 
//@ loc_548A:				; CODE XREF: ExpandPicture+76j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	ObjSeg,	ax	; uint16_t
//@ ; #line	"PS10.PAS" 1164
//@ 		mov	ax, [bp+var_A]
//@ 		mov	ObjectY, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1165
//@ 		mov	ax, [bp+O]	; struct TPic
//@ 		mov	ObjectX, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1166
//@ 		mov	ax, [bp+var_8]
//@ 		mov	[bp+crx], ax	; uint16_t
//@ ; #line	"PS10.PAS" 1168
//@ 		mov	ax, [bp+tx1]	; int16_t
//@ 		mov	bx, WallW	; uint16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		mov	[bp+sxs], ax	; int16_t
//@ ; #line	"PS10.PAS" 1173
//@ 		mov	cx, [bp+HalfShr1] ; uint16_t
//@ 		shl	[bp+ty1], cl	; int16_t
//@ ; #line	"PS10.PAS" 1174
//@ 		mov	ax, [bp+crx]	; uint16_t
//@ ; #line	"PS10.PAS" 1175
//@ 		mul	ObjectW		; uint16_t
//@ 		div	[bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 1176
//@ 		neg	ax		; Two's Complement Negation
//@ 		add	ax, [bp+sxs]	; int16_t
//@ 		mov	Sx1, ax		; int16_t
//@ ; #line	"PS10.PAS" 1178
//@ 		mov	ax, [bp+O]	; struct TPic
//@ ; #line	"PS10.PAS" 1179
//@ 		sub	ax, [bp+crx]	; uint16_t
//@ ; #line	"PS10.PAS" 1180
//@ 		mul	ObjectW		; uint16_t
//@ 		div	[bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 1181
//@ 		add	ax, [bp+sxs]	; int16_t
//@ 		mov	Sx2, ax		; int16_t
//@ ; #line	"PS10.PAS" 1182
//@ 		shr	[bp+ty1], cl	; int16_t
//@ ; #line	"PS10.PAS" 1184
//@ 		cmp	VideoCX, 0C8h ;	'È' ; uint16_t
//@ 		jbe	short loc_54FB	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ax, Sx2		; int16_t
//@ 		sub	ax, Sx1		; int16_t
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jge	short loc_54FB	; Jump if Greater or Equal (SF=OF)
//@ 		inc	Sx2		; int16_t
//@ ; #line	"PS10.PAS" 1185
//@ 
//@ loc_54FB:				; CODE XREF: ExpandPicture+DAj
//@ 					; ExpandPicture+E6j
//@ 		mov	ax, Sx2		; int16_t
//@ 		sub	ax, Sx1		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	sl, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1188
//@ 		mov	ax, WinW2i	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, Sx2		; int16_t
//@ 		jge	short loc_551A	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, Sx1		; int16_t
//@ 		cmp	ax, WinW2i	; int16_t
//@ 		jl	short loc_551D	; Jump if Less (SF!=OF)
//@ 
//@ loc_551A:				; CODE XREF: ExpandPicture+100j
//@ 		jmp	loc_590C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1190
//@ 
//@ loc_551D:				; CODE XREF: ExpandPicture+109j
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		add	Sx1, ax		; int16_t
//@ ; #line	"PS10.PAS" 1191
//@ 		mov	ax, WinSX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_553B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_5542	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_5542	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_553B:				; CODE XREF: ExpandPicture+124j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	_x1, ax		; uint16_t
//@ 		jmp	short loc_5556	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5542:				; CODE XREF: ExpandPicture+126j
//@ 					; ExpandPicture+12Aj
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinSX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	_x1, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1192
//@ 
//@ loc_5556:				; CODE XREF: ExpandPicture+131j
//@ 		mov	ax, sl		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinEX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_557A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_5582	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_5582	; Jump if Below	(CF=1)
//@ 
//@ loc_557A:				; CODE XREF: ExpandPicture+163j
//@ 		mov	ax, sl		; uint16_t
//@ 		mov	_x2, ax		; uint16_t
//@ 		jmp	short loc_559C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5582:				; CODE XREF: ExpandPicture+165j
//@ 					; ExpandPicture+169j
//@ 		mov	ax, Sx1		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinEX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		add	ax, 1		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	_x2, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1195
//@ 
//@ loc_559C:				; CODE XREF: ExpandPicture+171j
//@ 		mov	bx, [bp+ty1]	; int16_t
//@ ; #line	"PS10.PAS" 1196
//@ 		mov	cx, WallH	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, ehz		; int16_t
//@ 		sub	ax, [bp+tz1]	; int16_t
//@ 		sar	ax, 5		; Shift	Arithmetic Right
//@ 		imul	cx		; Signed Multiply
//@ 		idiv	bx		; Signed Divide
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"PS10.PAS" 1197
//@ 		mov	cx, WallH	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	ax, ObjectY	; uint16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 1198
//@ 		mov	cx, [bp+HalfShr1] ; uint16_t
//@ 		shr	ax, cl		; Shift	Logical	Right
//@ 		mov	HS, ax		; int16_t
//@ ; #line	"PS10.PAS" 1202
//@ 		mov	ax, ehz		; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		imul	WallH		; uint16_t
//@ 		div	_ty1		; int16_t
//@ 		mov	ys12, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1204
//@ 		cmp	HS, 0		; int16_t
//@ 		jnz	short loc_55E7	; Jump if Not Zero (ZF=0)
//@ 		mov	HS, 1		; int16_t
//@ ; #line	"PS10.PAS" 1205
//@ 
//@ loc_55E7:				; CODE XREF: ExpandPicture+1D0j
//@ 		cmp	VideoCY, 96h ; '–' ; uint16_t
//@ 		jbe	short loc_55FC	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	HS, 1		; int16_t
//@ 		jnz	short loc_55FC	; Jump if Not Zero (ZF=0)
//@ 		mov	HS, 2		; int16_t
//@ ; #line	"PS10.PAS" 1206
//@ 
//@ loc_55FC:				; CODE XREF: ExpandPicture+1DEj
//@ 					; ExpandPicture+1E5j
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinCY	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"PS10.PAS" 1210
//@ 		mov	ax, WinEY	; uint16_t
//@ 		mov	[bp+ZClip], ax	; int16_t
//@ ; #line	"PS10.PAS" 1211
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, HS		; int16_t
//@ 		cmp	ax, [bp+ZClip]	; int16_t
//@ 		jge	short loc_5628	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	[bp+y1], 0	; int16_t
//@ 		jge	short loc_562B	; Jump if Greater or Equal (SF=OF)
//@ 
//@ loc_5628:				; CODE XREF: ExpandPicture+211j
//@ 		jmp	loc_590C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1213
//@ 
//@ loc_562B:				; CODE XREF: ExpandPicture+217j
//@ 		mov	ax, Sx1		; int16_t
//@ 		add	_x1, ax		; uint16_t
//@ 		mov	ax, Sx1		; int16_t
//@ 		add	_x2, ax		; uint16_t
//@ 		mov	[bp+Visible], 0	; bool
//@ ; #line	"PS10.PAS" 1225
//@ 		mov	ax, _x1		; uint16_t
//@ 		mov	_X, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1226
//@ 		mov	cx, _x2		; uint16_t
//@ 		sub	cx, ax		; Integer Subtraction
//@ ; #line	"PS10.PAS" 1227
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ ; #line	"PS10.PAS" 1228
//@ 
//@ loc_564D:				; CODE XREF: ExpandPicture+27Fj
//@ 		mov	bx, _X		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 1229
//@ 		mov	ax, [bx-7734h]
//@ ; #line	"PS10.PAS" 1230
//@ 		cmp	ax, ys12	; uint16_t
//@ ; #line	"PS10.PAS" 1231
//@ 		jb	short loc_5662	; Jump if Below	(CF=1)
//@ ; #line	"PS10.PAS" 1232
//@ 		mov	ax, 0FFFFh
//@ 		jmp	short loc_567F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1234
//@ 
//@ loc_5662:				; CODE XREF: ExpandPicture+24Cj
//@ 		mov	[bp+Visible], 1	; bool
//@ ; #line	"PS10.PAS" 1235
//@ 		mov	ax, _X		; uint16_t
//@ 		sub	ax, Sx1		; int16_t
//@ ; #line	"PS10.PAS" 1236
//@ 		mov	bx, ObjectX	; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 1237
//@ 		mov	bx, sl		; uint16_t
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"PS10.PAS" 1238
//@ 		mov	bx, ObjectY	; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"PS10.PAS" 1240
//@ 
//@ loc_567F:				; CODE XREF: ExpandPicture+251j
//@ 		mov	bx, _X		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"PS10.PAS" 1241
//@ 		mov	es:[bx+1000h], ax
//@ ; #line	"PS10.PAS" 1242
//@ 		inc	_X		; uint16_t
//@ ; #line	"PS10.PAS" 1243
//@ 		loop	loc_564D	; Loop while CX	!= 0
//@ ; #line	"PS10.PAS" 1244
//@ 		mov	ax, 0FFFFh
//@ ; #line	"PS10.PAS" 1245
//@ 		add	bx, 1000h	; Add
//@ ; #line	"PS10.PAS" 1246
//@ 		mov	es:[bx+2], ax
//@ ; #line	"PS10.PAS" 1247
//@ 		mov	es:[bx+4], ax
//@ ; #line	"PS10.PAS" 1248
//@ 		mov	es:[bx+6], ax
//@ ; #line	"PS10.PAS" 1249
//@ 		mov	es:[bx+8], ax
//@ ; #line	"PS10.PAS" 1252
//@ 		cmp	[bp+Visible], 0	; bool
//@ 		jnz	short loc_56B0	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_590C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1254
//@ 
//@ loc_56B0:				; CODE XREF: ExpandPicture+29Cj
//@ 		mov	ax, sl		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	[bp+O]		; struct TPic
//@ 		mov	[bp+k],	ax	; uint16_t
//@ ; #line	"PS10.PAS" 1257
//@ 		mov	dx, 0
//@ 		mov	ax, ObjectY	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	Di0, ax		; uint16_t
//@ 		mov	bx, HS		; int16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	Dx0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1260
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		cmp	ax, [bp+ZClip]	; int16_t
//@ 		jle	short loc_5722	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 1262
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+ZClip]	; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, HS		; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+H],	ax	; uint16_t
//@ 		mov	ax, [bp+ZClip]	; int16_t
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"PS10.PAS" 1263
//@ 		mov	ax, HS		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+H]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, ObjectY	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	Di0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1264
//@ 		mov	ax, [bp+H]	; uint16_t
//@ 		mov	HS, ax		; int16_t
//@ ; #line	"PS10.PAS" 1265
//@ 		jmp	short loc_572C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5722:				; CODE XREF: ExpandPicture+2C7j
//@ 		mov	ax, ObjectY	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		dec	ax		; Decrement by 1
//@ 		mov	Di0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1267
//@ 
//@ loc_572C:				; CODE XREF: ExpandPicture+311j
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, HS		; int16_t
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jge	short loc_573E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	HS, ax		; int16_t
//@ ; #line	"PS10.PAS" 1268
//@ 
//@ loc_573E:				; CODE XREF: ExpandPicture+326j
//@ 		mov	di, [bp+y1]	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di-6E84h]
//@ 		mov	dx, [di-6E82h]
//@ 		mov	word ptr HLSt, ax ; int32_t
//@ 		mov	word ptr HLSt+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 1269
//@ 		mov	ax, Dx0		; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	Di0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1272
//@ 		cmp	[bp+Dark0], 0	; int16_t
//@ 		jl	short loc_57C0	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 1274
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	n$0, ax		; int16_t
//@ ; #line	"PS10.PAS" 1275
//@ 		cmp	n$0, 10h	; int16_t
//@ 		jle	short loc_5794	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	n$0, 10h	; int16_t
//@ ; #line	"PS10.PAS" 1276
//@ 
//@ loc_5794:				; CODE XREF: ExpandPicture+37Dj
//@ 		cmp	n$0, 27h ; '''  ; int16_t
//@ 		jl	short loc_57A4	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+GlassMode],	0 ; uint8_t
//@ 		jbe	short loc_57A4	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_590C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1277
//@ 
//@ loc_57A4:				; CODE XREF: ExpandPicture+38Aj
//@ 					; ExpandPicture+390j
//@ 		mov	ax, cm_ofs	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, [bp+Dark0]	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	n$0, ax		; int16_t
//@ ; #line	"PS10.PAS" 1278
//@ 		jmp	short loc_57C9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_57C0:				; CODE XREF: ExpandPicture+351j
//@ 		mov	ax, cm_ofs	; uint16_t
//@ 		add	ax, 700h	; Add
//@ 		mov	n$0, ax		; int16_t
//@ ; #line	"PS10.PAS" 1281
//@ 
//@ loc_57C9:				; CODE XREF: ExpandPicture+3AFj
//@ 		mov	al, [bp+GlassMode] ; uint8_t
//@ ; #line	"PS10.PAS" 1282
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_57DD	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, RGBSeg25	; uint16_t
//@ 		mov	RGBSeg,	ax	; uint16_t
//@ 		mov	InversGlass, 0	; bool
//@ 		jmp	short loc_580E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1283
//@ 
//@ loc_57DD:				; CODE XREF: ExpandPicture+3BFj
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_57EE	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, RGBSeg60	; uint16_t
//@ 		mov	RGBSeg,	ax	; uint16_t
//@ 		mov	InversGlass, 0	; bool
//@ 		jmp	short loc_580E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1284
//@ 
//@ loc_57EE:				; CODE XREF: ExpandPicture+3D0j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_57FF	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, RGBSeg60	; uint16_t
//@ 		mov	RGBSeg,	ax	; uint16_t
//@ 		mov	InversGlass, 1	; bool
//@ 		jmp	short loc_580E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1285
//@ 
//@ loc_57FF:				; CODE XREF: ExpandPicture+3E1j
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_580E	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, RGBSeg25	; uint16_t
//@ 		mov	RGBSeg,	ax	; uint16_t
//@ 		mov	InversGlass, 1	; bool
//@ ; #line	"PS10.PAS" 1289
//@ 
//@ loc_580E:				; CODE XREF: ExpandPicture+3CCj
//@ 					; ExpandPicture+3DDj ...
//@ 		mov	ax, _x1		; uint16_t
//@ 		mov	_X, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1290
//@ 		mov	ax, _X		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	word ptr HLSt, ax ; int32_t
//@ 		adc	word ptr HLSt+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 1291
//@ 
//@ loc_5821:				; CODE XREF: ExpandPicture+4F0j
//@ 		mov	ax, _X		; uint16_t
//@ 		cmp	ax, _x2		; uint16_t
//@ 		jb	short loc_582D	; Jump if Below	(CF=1)
//@ 		jmp	loc_5902	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1293
//@ 
//@ loc_582D:				; CODE XREF: ExpandPicture+419j
//@ 		mov	ax, _X		; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+1000h]
//@ 		mov	ImSeg, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1294
//@ 		cmp	ImSeg, 0FFFFh	; uint16_t
//@ 		jnz	short loc_584A	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_58F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1296
//@ 
//@ loc_584A:				; CODE XREF: ExpandPicture+436j
//@ 		mov	ax, _X		; uint16_t
//@ 		mov	HLxx, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1297
//@ 		cmp	[bp+GlassMode],	0 ; uint8_t
//@ 		jbe	short loc_58B9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 1298
//@ 		cmp	HS, 4		; int16_t
//@ 		jle	short loc_588A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, _X		; uint16_t
//@ 		add	ax, 3		; Add
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+1000h]
//@ 		cmp	ax, ImSeg	; uint16_t
//@ 		jnz	short loc_588A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1299
//@ 		add	_X, 3		; uint16_t
//@ 		call	ShowGlassLine4	; function near	PASCAL returns void
//@ 		add	word ptr HLSt, 3 ; int32_t
//@ 		adc	word ptr HLSt+2, 0 ; int32_t
//@ 		jmp	short loc_58B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1300
//@ 
//@ loc_588A:				; CODE XREF: ExpandPicture+44Cj
//@ 					; ExpandPicture+465j
//@ 		mov	ax, _X		; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+1000h]
//@ 		cmp	ax, ImSeg	; uint16_t
//@ 		jnz	short loc_58B4	; Jump if Not Zero (ZF=0)
//@ 		inc	_X		; uint16_t
//@ 		call	ShowGlassLine2	; function near	PASCAL returns void
//@ 		add	word ptr HLSt, 1 ; int32_t
//@ 		adc	word ptr HLSt+2, 0 ; int32_t
//@ 		jmp	short loc_58B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1301
//@ 
//@ loc_58B4:				; CODE XREF: ExpandPicture+490j
//@ 		call	ShowGlassLine	; function near	PASCAL returns void
//@ 
//@ loc_58B7:				; CODE XREF: ExpandPicture+479j
//@ 					; ExpandPicture+4A3j
//@ 		jmp	short loc_58F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1303
//@ 
//@ loc_58B9:				; CODE XREF: ExpandPicture+445j
//@ 		cmp	[bp+k],	0	; uint16_t
//@ 		jnz	short loc_58C4	; Jump if Not Zero (ZF=0)
//@ 		call	ShowLine	; function near	PASCAL returns void
//@ 		jmp	short loc_58F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1304
//@ 
//@ loc_58C4:				; CODE XREF: ExpandPicture+4AEj
//@ 		mov	ax, _X		; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+1000h]
//@ 		cmp	ax, ImSeg	; uint16_t
//@ 		jnz	short loc_58EE	; Jump if Not Zero (ZF=0)
//@ 		inc	_X		; uint16_t
//@ 		call	ShowLine2	; function near	PASCAL returns void
//@ 		add	word ptr HLSt, 1 ; int32_t
//@ 		adc	word ptr HLSt+2, 0 ; int32_t
//@ 		jmp	short loc_58F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1305
//@ 
//@ loc_58EE:				; CODE XREF: ExpandPicture+4CAj
//@ 		call	ShowLine	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 1307
//@ 
//@ loc_58F1:				; CODE XREF: ExpandPicture+438j
//@ 					; ExpandPicture:loc_58B7j ...
//@ 		inc	_X		; uint16_t
//@ 		add	word ptr HLSt, 1 ; int32_t
//@ 		adc	word ptr HLSt+2, 0 ; int32_t
//@ ; #line	"PS10.PAS" 1308
//@ 		jmp	loc_5821	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1309
//@ 
//@ loc_5902:				; CODE XREF: ExpandPicture+41Bj
//@ 		mov	[bp+ExpandPicture], 1 ;	bool
//@ ; #line	"PS10.PAS" 1310
//@ 		mov	ax, RGBSeg25	; uint16_t
//@ 		mov	RGBSeg,	ax	; uint16_t
//@ ; #line	"PS10.PAS" 1311
//@ 
//@ loc_590C:				; CODE XREF: ExpandPicture+45j
//@ 					; ExpandPicture+78j ...
//@ 		mov	al, [bp+ExpandPicture] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Eh		; Return Near from Procedure
//@ ExpandPicture	endp
//@ 
//@ ; #line	"PS10.PAS" 1318
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandObject	proc near		; CODE XREF: DoGame+17C6p
//@ 
//@ var_16		= dword	ptr -16h
//@ d		= word ptr -8		; int16_t
//@ CObject		= word ptr -4		; int16_t
//@ z		= word ptr -2		; int16_t
//@ oyy		= word ptr  4		; int16_t
//@ oxx		= word ptr  6		; int16_t
//@ ty1		= word ptr  8		; int16_t
//@ tx1		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	16h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1319
//@ 		imul	ax, [bp+oyy], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+oxx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"PS10.PAS" 1321
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+d],	ax	; int16_t
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 79h	; 'y'   ; Integer Subtraction
//@ 		mov	[bp+CObject], ax ; int16_t
//@ ; #line	"PS10.PAS" 1322
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+z],	ax	; int16_t
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1324
//@ 		imul	di, [bp+CObject], 0A5h ; int16_t
//@ 		add	di, 721Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"PS10.PAS" 1326
//@ 		mov	al, es:[di+2]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_5982	; Jump if Zero (ZF=1)
//@ 		mov	[bp+d],	9	; int16_t
//@ ; #line	"PS10.PAS" 1327
//@ 
//@ loc_5982:				; CODE XREF: ExpandObject+68j
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+2]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_5995	; Jump if Zero (ZF=1)
//@ 		mov	HalfShr, 1	; uint16_t
//@ ; #line	"PS10.PAS" 1328
//@ 
//@ loc_5995:				; CODE XREF: ExpandObject+7Aj
//@ 		cmp	[bp+CObject], 1	; int16_t
//@ 		jz	short loc_59A4	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1329
//@ 
//@ loc_59A4:				; CODE XREF: ExpandObject+86j
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	[bp+d]		; int16_t
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+4]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 0Ah		; Signed Multiply
//@ 		add	di, ax		; Add
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		and	al, 1		; Logical AND
//@ 		push	ax
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"PS10.PAS" 1331
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ ExpandObject	endp
//@ 
//@ ; #line	"PS10.PAS" 1336
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawHoles	proc near		; CODE XREF: DoGame+1734p
//@ 
//@ var_14		= dword	ptr -14h
//@ var_10		= dword	ptr -10h
//@ var_C		= word ptr -0Ch
//@ ty1		= word ptr -0Ah		; int16_t
//@ tx1		= word ptr -8		; int16_t
//@ py1		= word ptr -6		; int16_t
//@ px1		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	14h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1337
//@ 		mov	ax, HolCount	; uint16_t
//@ 		mov	[bp+var_C], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		jle	short loc_59EA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_5BDC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_59EA:				; CODE XREF: DrawHoles+10j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_59F2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_59EF:				; CODE XREF: DrawHoles+204j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 1338
//@ 
//@ loc_59F2:				; CODE XREF: DrawHoles+18j
//@ 		imul	ax, [bp+n], 14h	; int16_t
//@ 		les	di, HolesList	; THoleItem*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFECh	; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"PS10.PAS" 1340
//@ 		cmp	word ptr es:[di+0Ah], 0FFFFh ; Compare Two Operands
//@ 		jnz	short loc_5A10	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_5ACD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5A10:				; CODE XREF: DrawHoles+36j
//@ 		imul	ax, es:[di+0Ch], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+0Ah], 2C0h ;	Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_14], di
//@ 		mov	word ptr [bp+var_14+2],	es
//@ ; #line	"PS10.PAS" 1342
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+9]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"PS10.PAS" 1343
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	cx, es:[di+0Eh]
//@ 		mov	si, es:[di+10h]
//@ 		mov	di, es:[di+12h]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"PS10.PAS" 1344
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+9]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	cx, es:[di+0Eh]
//@ 		mov	si, es:[di+10h]
//@ 		mov	di, es:[di+12h]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ ; #line	"PS10.PAS" 1347
//@ 
//@ loc_5ACD:				; CODE XREF: DrawHoles+38j
//@ 		mov	ax, ehx		; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		mov	[bp+px1], ax	; int16_t
//@ ; #line	"PS10.PAS" 1348
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		mov	[bp+py1], ax	; int16_t
//@ ; #line	"PS10.PAS" 1350
//@ 		mov	ax, [bp+py1]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"PS10.PAS" 1351
//@ 		mov	ax, [bp+px1]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		add	bx, ax		; Add
//@ 		adc	cx, dx		; Add with Carry
//@ ; #line	"PS10.PAS" 1352
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		sub	bx, 40h	; '@'   ; Integer Subtraction
//@ 		mov	[bp+ty1], bx	; int16_t
//@ ; #line	"PS10.PAS" 1354
//@ 		mov	ax, [bp+px1]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"PS10.PAS" 1355
//@ 		mov	ax, [bp+py1]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		sbb	cx, dx		; Integer Subtraction with Borrow
//@ ; #line	"PS10.PAS" 1356
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		mov	[bp+tx1], bx	; int16_t
//@ ; #line	"PS10.PAS" 1358
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jg	short loc_5B31	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_5BD1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1360
//@ 
//@ loc_5B31:				; CODE XREF: DrawHoles+157j
//@ 		mov	Curdark, 0Ch	; int16_t
//@ 		mov	HPrior,	2	; int16_t
//@ ; #line	"PS10.PAS" 1361
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_5B53	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	al, DrawMask	; uint8_t
//@ 		xor	al, 3		; Logical Exclusive OR
//@ 		mov	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1362
//@ 
//@ loc_5B53:				; CODE XREF: DrawHoles+174j
//@ 		push	word ptr Obj3DInf.POH+2AEh ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2ACh ; struct TObj3DInfo[96]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, EHFi	; uint16_t
//@ 		push	ax
//@ 		push	0
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1365
//@ 		cmp	Obj3DInf.BMPObj+2ACh, 0	; struct TObj3DInfo[96]
//@ 		jl	short loc_5BD1	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 1367
//@ 		imul	di, Obj3DInf.BMPObj+2ACh, 0A5h ; struct	TObj3DInfo[96]
//@ 		mov	al, [di+721Ch]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_5B95	; Jump if Zero (ZF=1)
//@ 		mov	HalfShr, 1	; uint16_t
//@ ; #line	"PS10.PAS" 1368
//@ 
//@ loc_5B95:				; CODE XREF: DrawHoles+1B8j
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		push	8
//@ 		imul	di, Obj3DInf.BMPObj+2ACh, 0A5h ; struct	TObj3DInfo[96]
//@ 		mov	al, [di+721Eh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 0Ah		; Signed Multiply
//@ 		imul	di, Obj3DInf.BMPObj+2ACh, 0A5h ; struct	TObj3DInfo[96]
//@ 		add	di, ax		; Add
//@ 		add	di, 721Fh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, Obj3DInf.BMPObj+2ACh, 0A5h ; struct	TObj3DInfo[96]
//@ 		mov	al, [di+721Ch]
//@ 		and	al, 1		; Logical AND
//@ 		push	ax
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"PS10.PAS" 1373
//@ 
//@ loc_5BD1:				; CODE XREF: DrawHoles+159j
//@ 					; DrawHoles+1A8j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		jz	short locret_5BDC ; Jump if Zero (ZF=1)
//@ 		jmp	loc_59EF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1374
//@ 
//@ locret_5BDC:				; CODE XREF: DrawHoles+12j
//@ 					; DrawHoles+202j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DrawHoles	endp
//@ 
//@ ; #line	"PS10.PAS" 1380
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Expand3dObject	proc near		; CODE XREF: Build3dScene+27Cp
//@ 					; DoGame+17E8p
//@ 
//@ var_16		= dword	ptr -16h
//@ var_12		= dword	ptr -12h
//@ fl		= word ptr -0Eh		; uint16_t
//@ ft		= word ptr -0Ch		; uint16_t
//@ bz		= word ptr -0Ah		; int16_t
//@ d		= word ptr -8		; int16_t
//@ CObject		= word ptr -2		; int16_t
//@ oyy		= word ptr  4		; int16_t
//@ oxx		= word ptr  6		; int16_t
//@ ty1		= word ptr  8		; int16_t
//@ tx1		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	16h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1381
//@ 		cmp	Obj3d, 0	; bool
//@ 		jnz	short loc_5BEC	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_5EC5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1382
//@ 
//@ loc_5BEC:				; CODE XREF: Expand3dObject+9j
//@ 		imul	ax, [bp+oyy], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+oxx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_12], di
//@ 		mov	word ptr [bp+var_12+2],	es
//@ ; #line	"PS10.PAS" 1384
//@ 		mov	ax, es:[di+7]
//@ 		mov	[bp+fl], ax	; uint16_t
//@ 		mov	ax, [bp+fl]	; uint16_t
//@ 		mov	LocalFi, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1385
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+d],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1386
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		mov	GlobX, ax	; int16_t
//@ 		mov	ax, es:[di+5]
//@ 		mov	GlobY, ax	; int16_t
//@ ; #line	"PS10.PAS" 1387
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		mov	[bp+CObject], ax ; int16_t
//@ ; #line	"PS10.PAS" 1388
//@ 		cmp	[bp+CObject], 0	; int16_t
//@ 		jge	short loc_5C49	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_5EC5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1390
//@ 
//@ loc_5C49:				; CODE XREF: Expand3dObject+66j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	ShadowZ0, ax	; int16_t
//@ 		mov	ax, ShadowZ0	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	ShadowZ0, ax	; int16_t
//@ ; #line	"PS10.PAS" 1392
//@ 		imul	di, [bp+CObject], 24h ;	int16_t
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_12], di
//@ 		mov	word ptr [bp+var_12+2],	es
//@ ; #line	"PS10.PAS" 1394
//@ 		cmp	word ptr es:[di+6], 0FFFDh ; Compare Two Operands
//@ 		mov	al, 0
//@ 		jnz	short loc_5C78	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_5C78:				; CODE XREF: Expand3dObject+97j
//@ 		mov	YWrap, al	; bool
//@ ; #line	"PS10.PAS" 1396
//@ 		cmp	word ptr es:[di+6], 0FFFDh ; Compare Two Operands
//@ 		jz	short loc_5C89	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+2], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_5C8E	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_5C89:				; CODE XREF: Expand3dObject+A2j
//@ 		mov	HiRot, 1	; bool
//@ ; #line	"PS10.PAS" 1397
//@ 
//@ loc_5C8E:				; CODE XREF: Expand3dObject+A9j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+6], 0FFFCh ; Compare Two Operands
//@ 		jnz	short loc_5C9E	; Jump if Not Zero (ZF=0)
//@ 		mov	HPrior,	50h ; 'P' ; int16_t
//@ ; #line	"PS10.PAS" 1402
//@ 
//@ loc_5C9E:				; CODE XREF: Expand3dObject+B8j
//@ 		mov	ax, ShadowZ0	; int16_t
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+8]	; Add
//@ 		mov	[bp+bz], ax	; int16_t
//@ ; #line	"PS10.PAS" 1403
//@ 		cmp	word ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jl	short loc_5D11	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+bz], 800h	; int16_t
//@ 		jl	short loc_5D11	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 1405
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		mov	al, [di+721Ch]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_5CCF	; Jump if Zero (ZF=1)
//@ 		mov	HalfShr, 1	; uint16_t
//@ ; #line	"PS10.PAS" 1406
//@ 
//@ loc_5CCF:				; CODE XREF: Expand3dObject+E9j
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+bz]		; int16_t
//@ 		push	[bp+d]		; int16_t
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		mov	al, [di+721Eh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 0Ah		; Signed Multiply
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		add	di, ax		; Add
//@ 		add	di, 721Fh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		mov	al, [di+721Ch]
//@ 		and	al, 1		; Logical AND
//@ 		push	ax
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"PS10.PAS" 1411
//@ 
//@ loc_5D11:				; CODE XREF: Expand3dObject+D2j
//@ 					; Expand3dObject+D9j
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jle	short loc_5D3E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	DepthD,	ax	; int16_t
//@ 		jmp	short loc_5D43	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5D3E:				; CODE XREF: Expand3dObject+137j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DepthD,	ax	; int16_t
//@ ; #line	"PS10.PAS" 1412
//@ 
//@ loc_5D43:				; CODE XREF: Expand3dObject+15Ej
//@ 		cmp	DepthD,	10h	; int16_t
//@ 		jle	short loc_5D50	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	DepthD,	10h	; int16_t
//@ ; #line	"PS10.PAS" 1413
//@ 
//@ loc_5D50:				; CODE XREF: Expand3dObject+16Aj
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+2], 0 ;	Compare	Two Operands
//@ 		jle	short loc_5D7A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 1415
//@ 		mov	ax, DepthD	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 5
//@ 		idiv	cx		; Signed Divide
//@ 		mov	DepthD,	ax	; int16_t
//@ ; #line	"PS10.PAS" 1416
//@ 		sub	DepthD,	4	; int16_t
//@ 		cmp	DepthD,	0	; int16_t
//@ 		jge	short loc_5D7A	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DepthD,	ax	; int16_t
//@ ; #line	"PS10.PAS" 1418
//@ 
//@ loc_5D7A:				; CODE XREF: Expand3dObject+17Aj
//@ 					; Expand3dObject+195j
//@ 		mov	ax, DepthD	; int16_t
//@ 		add	ax, [bp+d]	; int16_t
//@ 		mov	Curdark, ax	; int16_t
//@ 		mov	ax, EHFi	; uint16_t
//@ 		add	[bp+fl], ax	; uint16_t
//@ ; #line	"PS10.PAS" 1420
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+2], 0FFh ; Compare Two Operands
//@ 		jz	short loc_5D9D	; Jump if Zero (ZF=1)
//@ 		mov	ax, es:[di+18h]
//@ 		mov	[bp+ft], ax	; uint16_t
//@ 		jmp	short loc_5DC4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1423
//@ 
//@ loc_5D9D:				; CODE XREF: Expand3dObject+1B4j
//@ 		mov	dx, [bp+oyy]	; int16_t
//@ 		mov	ax, [bp+oxx]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+ft], ax	; uint16_t
//@ ; #line	"PS10.PAS" 1424
//@ 		cmp	[bp+ft], 1	; uint16_t
//@ 		jbe	short loc_5DC4	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	al, DrawMask	; uint8_t
//@ 		xor	al, 3		; Logical Exclusive OR
//@ 		mov	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1427
//@ 
//@ loc_5DC4:				; CODE XREF: Expand3dObject+1BDj
//@ 					; Expand3dObject+1DCj
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+16h], 0	; Compare Two Operands
//@ 		jnz	short loc_5DD3	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ft], ax	; uint16_t
//@ ; #line	"PS10.PAS" 1429
//@ 
//@ loc_5DD3:				; CODE XREF: Expand3dObject+1EEj
//@ 		imul	di, [bp+CObject], 24h ;	int16_t
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"PS10.PAS" 1431
//@ 		mov	ax, es:[di+20h]
//@ 		or	ax, es:[di+22h]	; Logical Inclusive OR
//@ 		jz	short loc_5E34	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1432
//@ 		cmp	byte ptr es:[di+17h], 0	; Compare Two Operands
//@ 		jz	short loc_5E12	; Jump if Zero (ZF=1)
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	word ptr es:[di+1Ch]
//@ 		push	word ptr es:[di+22h]
//@ 		push	word ptr es:[di+20h]
//@ 		mov	ax, [bp+ft]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ 		jmp	short loc_5E34	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1433
//@ 
//@ loc_5E12:				; CODE XREF: Expand3dObject+214j
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	word ptr es:[di+1Ch]
//@ 		push	word ptr es:[di+22h]
//@ 		push	word ptr es:[di+20h]
//@ 		mov	ax, [bp+ft]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		and	ax, 0FFFEh	; Logical AND
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1434
//@ 
//@ loc_5E34:				; CODE XREF: Expand3dObject+20Dj
//@ 					; Expand3dObject+232j
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	word ptr es:[di+1Ch]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	ShadowZ0	; int16_t
//@ 		push	[bp+fl]		; uint16_t
//@ 		cmp	word ptr es:[di+4], 1 ;	Compare	Two Operands
//@ 		mov	al, 0
//@ 		jnz	short loc_5E56	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_5E56:				; CODE XREF: Expand3dObject+275j
//@ 		push	ax
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1437
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jl	short locret_5EC5 ; Jump if Less (SF!=OF)
//@ 		cmp	[bp+bz], 800h	; int16_t
//@ 		jge	short locret_5EC5 ; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 1439
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		mov	al, [di+721Ch]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_5E83	; Jump if Zero (ZF=1)
//@ 		mov	HalfShr, 1	; uint16_t
//@ ; #line	"PS10.PAS" 1440
//@ 
//@ loc_5E83:				; CODE XREF: Expand3dObject+29Dj
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+bz]		; int16_t
//@ 		push	[bp+d]		; int16_t
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		mov	al, [di+721Eh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 0Ah		; Signed Multiply
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		add	di, ax		; Add
//@ 		add	di, 721Fh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+6], 0A5h ; Signed Multiply
//@ 		mov	al, [di+721Ch]
//@ 		and	al, 1		; Logical AND
//@ 		push	ax
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"PS10.PAS" 1445
//@ 
//@ locret_5EC5:				; CODE XREF: Expand3dObject+Bj
//@ 					; Expand3dObject+68j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ Expand3dObject	endp
//@ 
//@ ; #line	"PS10.PAS" 1451
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandRocket	proc near		; CODE XREF: DoGame+1826p
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= dword	ptr -0Ah
//@ RRZ		= word ptr -6		; int16_t
//@ D		= word ptr -2		; int16_t
//@ RNum		= word ptr  4		; int16_t
//@ ty1		= word ptr  6		; int16_t
//@ tx1		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1452
//@ 		imul	di, [bp+RNum], 18h ; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		add	di, 0CD84h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"PS10.PAS" 1454
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+8]
//@ 		mov	[bp+RRZ], ax	; int16_t
//@ ; #line	"PS10.PAS" 1455
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_5F11	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	Curdark, 5	; int16_t
//@ 		jmp	short loc_5F6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1457
//@ 
//@ loc_5F11:				; CODE XREF: ExpandRocket+3Ej
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1458
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jle	short loc_5F53	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+D],	ax	; int16_t
//@ 		jmp	short loc_5F58	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5F53:				; CODE XREF: ExpandRocket+61j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+D],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1459
//@ 
//@ loc_5F58:				; CODE XREF: ExpandRocket+88j
//@ 		cmp	[bp+D],	10h	; int16_t
//@ 		jle	short loc_5F63	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+D],	10h	; int16_t
//@ ; #line	"PS10.PAS" 1460
//@ 
//@ loc_5F63:				; CODE XREF: ExpandRocket+93j
//@ 		mov	ax, Curdark	; int16_t
//@ 		add	ax, [bp+D]	; int16_t
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1462
//@ 
//@ loc_5F6C:				; CODE XREF: ExpandRocket+46j
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		or	ax, es:[di+14h]	; Logical Inclusive OR
//@ 		jz	short loc_5F9B	; Jump if Zero (ZF=1)
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Eh]
//@ 		push	word ptr es:[di+14h]
//@ 		push	word ptr es:[di+12h]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1463
//@ 
//@ loc_5F9B:				; CODE XREF: ExpandRocket+AEj
//@ 		mov	ax, EHFi	; uint16_t
//@ 		mov	b0, ax		; uint16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	b0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1464
//@ 		mov	ax, es:[di+12h]
//@ 		mov	XFi, ax		; int16_t
//@ ; #line	"PS10.PAS" 1465
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Eh]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	b0		; uint16_t
//@ 		push	0
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1467
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ ExpandRocket	endp
//@ 
//@ ; #line	"PS10.PAS" 1473
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandMine	proc near		; CODE XREF: DoGame+1841p
//@ 
//@ var_8		= dword	ptr -8
//@ D		= word ptr -2		; int16_t
//@ MNum		= word ptr  4		; int16_t
//@ ty1		= word ptr  6		; int16_t
//@ tx1		= word ptr  8		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1474
//@ 		imul	di, [bp+MNum], 0Ah ; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"PS10.PAS" 1476
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1477
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jle	short loc_602C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+D],	ax	; int16_t
//@ 		jmp	short loc_6031	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_602C:				; CODE XREF: ExpandMine+29j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+D],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1478
//@ 
//@ loc_6031:				; CODE XREF: ExpandMine+50j
//@ 		cmp	[bp+D],	10h	; int16_t
//@ 		jle	short loc_603C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+D],	10h	; int16_t
//@ 
//@ loc_603C:				; CODE XREF: ExpandMine+5Bj
//@ 		mov	ax, Curdark	; int16_t
//@ 		add	ax, [bp+D]	; int16_t
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1479
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4], 118h ; Compare Two Operands
//@ 		jl	short loc_6071	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 1480
//@ 		cmp	SecCounter, 46h	; 'F' ; uint8_t
//@ 		jbe	short loc_6071	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 1481
//@ 		mov	al, DrawMask	; uint8_t
//@ 		xor	al, 3		; Logical Exclusive OR
//@ 		mov	DrawMask, al	; uint8_t
//@ 		sub	Curdark, 0Ch	; int16_t
//@ 		cmp	Curdark, 6	; int16_t
//@ 		jge	short loc_6071	; Jump if Greater or Equal (SF=OF)
//@ 		mov	Curdark, 6	; int16_t
//@ ; #line	"PS10.PAS" 1482
//@ 
//@ loc_6071:				; CODE XREF: ExpandMine+74j
//@ 					; ExpandMine+7Bj ...
//@ 		push	word ptr Obj3DInf.POH+43Ah ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+438h ; struct TObj3DInfo[96]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+6]
//@ 		push	EHFi		; uint16_t
//@ 		push	0
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1484
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ ExpandMine	endp
//@ 
//@ ; #line	"PS10.PAS" 1490
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandSepPart	proc near		; CODE XREF: DoGame+1897p
//@ 
//@ var_C		= dword	ptr -0Ch
//@ var_8		= dword	ptr -8
//@ d		= word ptr -2		; int16_t
//@ SNum		= word ptr  4		; int16_t
//@ ty1		= word ptr  6		; int16_t
//@ tx1		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1491
//@ 		imul	di, [bp+SNum], 16h ; int16_t
//@ 		add	di, 0B940h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ 		imul	di, es:[di+4], 12h ; Signed Multiply
//@ 		add	di, 0D044h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"PS10.PAS" 1493
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+8]
//@ 		mov	GlobX, ax	; int16_t
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	GlobY, ax	; int16_t
//@ ; #line	"PS10.PAS" 1494
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1495
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jle	short loc_610A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+d],	ax	; int16_t
//@ 		jmp	short loc_610F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_610A:				; CODE XREF: ExpandSepPart+4Cj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+d],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1496
//@ 
//@ loc_610F:				; CODE XREF: ExpandSepPart+73j
//@ 		cmp	[bp+d],	10h	; int16_t
//@ 		jle	short loc_611A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+d],	10h	; int16_t
//@ ; #line	"PS10.PAS" 1497
//@ 
//@ loc_611A:				; CODE XREF: ExpandSepPart+7Ej
//@ 		mov	ax, Curdark	; int16_t
//@ 		add	ax, [bp+d]	; int16_t
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1498
//@ 		mov	ax, EHFi	; uint16_t
//@ 		mov	b0, ax		; uint16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		add	b0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1499
//@ 		cmp	word ptr es:[di+4], 3 ;	Compare	Two Operands
//@ 		jge	short loc_614B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	al, es:[di+7]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	58h	; Signed Multiply
//@ 		mov	ax, [di-0FA0h]
//@ 		mov	ReColor, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1501
//@ 
//@ loc_614B:				; CODE XREF: ExpandSepPart+A4j
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4], 46h	; 'F' ; Compare Two Operands
//@ 		jl	short loc_6171	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 1502
//@ 		cmp	byte ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_616F	; Jump if Not Zero (ZF=0)
//@ 		mov	al, SecCounter	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 1D4h	; Signed Multiply
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	b0, ax		; uint16_t
//@ 
//@ loc_616F:				; CODE XREF: ExpandSepPart+C5j
//@ 		jmp	short loc_61C5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1504
//@ 
//@ loc_6171:				; CODE XREF: ExpandSepPart+BEj
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_61A1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1505
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+0Ah]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ 		jmp	short loc_61C5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1506
//@ 
//@ loc_61A1:				; CODE XREF: ExpandSepPart+E4j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Eh]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1508
//@ 
//@ loc_61C5:				; CODE XREF: ExpandSepPart:loc_616Fj
//@ 					; ExpandSepPart+10Aj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+6]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	b0		; uint16_t
//@ 		cmp	byte ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_61F8	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cmp	ax, 50h	; 'P'   ; Compare Two Operands
//@ 		jl	short loc_61FC	; Jump if Less (SF!=OF)
//@ 
//@ loc_61F8:				; CODE XREF: ExpandSepPart+155j
//@ 		mov	al, 0
//@ 		jmp	short loc_61FE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_61FC:				; CODE XREF: ExpandSepPart+161j
//@ 		mov	al, 1
//@ 
//@ loc_61FE:				; CODE XREF: ExpandSepPart+165j
//@ 		push	ax
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1510
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ ExpandSepPart	endp
//@ 
//@ ; #line	"PS10.PAS" 1515
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandAmmoBag	proc near		; CODE XREF: DoGame+18B1p
//@ 
//@ var_8		= dword	ptr -8
//@ d		= word ptr -2		; int16_t
//@ ANum		= word ptr  4		; int16_t
//@ ty1		= word ptr  6		; int16_t
//@ tx1		= word ptr  8		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1516
//@ 		imul	ax, [bp+ANum], 1Fh ; int16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"PS10.PAS" 1518
//@ 		mov	ax, es:[di]
//@ 		mov	GlobX, ax	; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	GlobY, ax	; int16_t
//@ ; #line	"PS10.PAS" 1519
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1520
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jle	short loc_626B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+d],	ax	; int16_t
//@ 		jmp	short loc_6270	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_626B:				; CODE XREF: ExpandAmmoBag+3Aj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+d],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1521
//@ 
//@ loc_6270:				; CODE XREF: ExpandAmmoBag+61j
//@ 		cmp	[bp+d],	10h	; int16_t
//@ 		jle	short loc_627B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+d],	10h	; int16_t
//@ ; #line	"PS10.PAS" 1522
//@ 
//@ loc_627B:				; CODE XREF: ExpandAmmoBag+6Cj
//@ 		mov	ax, Curdark	; int16_t
//@ 		add	ax, [bp+d]	; int16_t
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1523
//@ 		mov	ax, EHFi	; uint16_t
//@ 		mov	b0, ax		; uint16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	b0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 1524
//@ 		push	word ptr Obj3DInf.POH+2	; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH ;	struct TObj3DInfo[96]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	word ptr es:[di+4]
//@ 		push	b0		; uint16_t
//@ 		push	1
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1526
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ ExpandAmmoBag	endp
//@ 
//@ ; #line	"PS10.PAS" 1531
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandBlow	proc near		; CODE XREF: DoGame+185Bp
//@ 
//@ var_C		= dword	ptr -0Ch
//@ var_8		= dword	ptr -8
//@ D		= word ptr -4		; int16_t
//@ BBZ		= word ptr -2		; int16_t
//@ BNum		= word ptr  4		; int16_t
//@ ty1		= word ptr  6		; int16_t
//@ tx1		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1532
//@ 		mov	ax, [bp+BNum]	; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, BlowsList	; TBlow*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF0h	; Add
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ 		imul	di, es:[di+2], 3Ah ; Signed Multiply
//@ 		add	di, 0D698h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"PS10.PAS" 1534
//@ 		mov	al, es:[di+2]
//@ 		and	al, 10h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_62F1	; Jump if Zero (ZF=1)
//@ 		mov	HalfShr, 1	; uint16_t
//@ ; #line	"PS10.PAS" 1535
//@ 
//@ loc_62F1:				; CODE XREF: ExpandBlow+33j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+2]
//@ 		and	al, 20h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6305	; Jump if Zero (ZF=1)
//@ 		mov	[bp+D],	7	; int16_t
//@ 		jmp	short loc_631A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6305:				; CODE XREF: ExpandBlow+46j
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+D],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1536
//@ 
//@ loc_631A:				; CODE XREF: ExpandBlow+4Dj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		call	SetCurPicTo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1537
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_6341	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+8]
//@ 		mov	[bp+BBZ], ax	; int16_t
//@ 		jmp	short loc_635C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6341:				; CODE XREF: ExpandBlow+80j
//@ 		mov	ax, CurPic.YSize ; struct TPic
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+BBZ], ax	; int16_t
//@ ; #line	"PS10.PAS" 1538
//@ 
//@ loc_635C:				; CODE XREF: ExpandBlow+89j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+3], 4Dh	; 'M' ; Compare Two Operands
//@ 		jnz	short loc_63BE	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1540
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_6386	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+BBZ]	; int16_t
//@ 		push	0FFFFh
//@ 		mov	di, offset CurPic ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		jmp	short loc_63BB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1542
//@ 
//@ loc_6386:				; CODE XREF: ExpandBlow+B7j
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di], 1 ; Compare Two Operands
//@ 		jnz	short loc_63A6	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+BBZ]	; int16_t
//@ 		push	0FFFFh
//@ 		mov	di, offset CurPic ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		push	3
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		jmp	short loc_63BB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1543
//@ 
//@ loc_63A6:				; CODE XREF: ExpandBlow+D7j
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+BBZ]	; int16_t
//@ 		push	0FFFFh
//@ 		mov	di, offset CurPic ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"PS10.PAS" 1544
//@ 
//@ loc_63BB:				; CODE XREF: ExpandBlow+CEj
//@ 					; ExpandBlow+EEj
//@ 		jmp	locret_6457	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1545
//@ 
//@ loc_63BE:				; CODE XREF: ExpandBlow+AEj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+3], 0Ah	; Compare Two Operands
//@ 		jnb	short loc_63E6	; Jump if Not Below (CF=0)
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+BBZ]	; int16_t
//@ 		push	[bp+D]		; int16_t
//@ 		mov	di, offset CurPic ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+3]
//@ 		push	ax
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		jmp	short locret_6457 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1547
//@ 
//@ loc_63E6:				; CODE XREF: ExpandBlow+110j
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		inc	ax		; Increment by 1
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jnz	short loc_640C	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+BBZ]	; int16_t
//@ 		push	0FFFFh
//@ 		mov	di, offset CurPic ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		jmp	short locret_6457 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1548
//@ 
//@ loc_640C:				; CODE XREF: ExpandBlow+13Dj
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jnz	short loc_6433	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+BBZ]	; int16_t
//@ 		push	0FFFFh
//@ 		mov	di, offset CurPic ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		jmp	short locret_6457 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1549
//@ 
//@ loc_6433:				; CODE XREF: ExpandBlow+164j
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+BBZ]	; int16_t
//@ 		push	0FFFFh
//@ 		mov	di, offset CurPic ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ah
//@ 		idiv	cx		; Signed Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		push	ax
//@ 		call	ExpandPicture	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"PS10.PAS" 1552
//@ 
//@ locret_6457:				; CODE XREF: ExpandBlow:loc_63BBj
//@ 					; ExpandBlow+12Ej ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ ExpandBlow	endp
//@ 
//@ ; #line	"PS10.PAS" 1560
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandPlayer	proc near		; CODE XREF: DoGame+187Dp
//@ 
//@ var_14		= dword	ptr -14h
//@ n		= byte ptr -0Bh		; uint8_t
//@ PNum		= word ptr  4		; int16_t
//@ ty1		= word ptr  0Ah		; int16_t
//@ tx1		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	14h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1561
//@ 		imul	di, [bp+PNum], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_14], di
//@ 		mov	word ptr [bp+var_14+2],	es
//@ ; #line	"PS10.PAS" 1563
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	GlobX, ax	; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	GlobY, ax	; int16_t
//@ ; #line	"PS10.PAS" 1564
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jle	short loc_64AA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+n],	al	; uint8_t
//@ 		jmp	short loc_64AE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_64AA:				; CODE XREF: ExpandPlayer+26j
//@ 		mov	[bp+n],	0	; uint8_t
//@ ; #line	"PS10.PAS" 1565
//@ 
//@ loc_64AE:				; CODE XREF: ExpandPlayer+4Dj
//@ 		cmp	[bp+n],	10h	; uint8_t
//@ 		jbe	short loc_64B8	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	[bp+n],	10h	; uint8_t
//@ ; #line	"PS10.PAS" 1567
//@ 
//@ loc_64B8:				; CODE XREF: ExpandPlayer+57j
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		call	GetSmoothBrightAt ; function far PASCAL	returns	signed int 'Integer'
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, dx		; Add
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1568
//@ 		mov	ax, EHFi	; uint16_t
//@ 		mov	b0, ax		; uint16_t
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		sub	b0, ax		; uint16_t
//@ 		add	b0, 8000h	; uint16_t
//@ ; #line	"PS10.PAS" 1570
//@ 		mov	ax, es:[di+36h]
//@ 		mov	ReColor, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1574
//@ 		mov	al, es:[di+24h]
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jb	short loc_6521	; Jump if Below	(CF=1)
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		ja	short loc_6521	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	al, es:[di+24h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-4090h]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+22h]	; Compare Two Operands
//@ 		jbe	short loc_6521	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 1575
//@ 		mov	al, 0C0h ; 'À'
//@ 		xor	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1576
//@ 
//@ loc_6521:				; CODE XREF: ExpandPlayer+A0j
//@ 					; ExpandPlayer+A4j ...
//@ 		push	word ptr MonstersInfo.POH+2 ; struct TMonsterInfo[23]
//@ 		push	word ptr MonstersInfo.POH ; struct TMonsterInfo[23]
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+24h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		push	word ptr [di-40DEh]
//@ 		push	word ptr [di-40E0h]
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+22h]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1577
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jbe	short loc_6560	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_6560:				; CODE XREF: ExpandPlayer+102j
//@ 		mov	Invisibility, al ; bool
//@ ; #line	"PS10.PAS" 1578
//@ 		mov	ax, es:[di+10h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mov	XFi, ax		; int16_t
//@ ; #line	"PS10.PAS" 1579
//@ 		push	word ptr MonstersInfo.POH+2 ; struct TMonsterInfo[23]
//@ 		push	word ptr MonstersInfo.POH ; struct TMonsterInfo[23]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	word ptr es:[di+0Eh]
//@ 		push	b0		; uint16_t
//@ 		cmp	word ptr es:[di+0Eh], 0	; Compare Two Operands
//@ 		mov	al, 0
//@ 		jnz	short loc_6592	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_6592:				; CODE XREF: ExpandPlayer+134j
//@ 		push	ax
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1582
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		call	GetSmoothBrightAt ; function far PASCAL	returns	signed int 'Integer'
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, dx		; Add
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1583
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 2		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_660E	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1586
//@ 		mov	ax, word ptr Obj3DInf.PAni+2D0h	; struct TObj3DInfo[96]
//@ 		or	ax, word ptr Obj3DInf.PAni+2D2h	; struct TObj3DInfo[96]
//@ 		jz	short loc_65EA	; Jump if Zero (ZF=1)
//@ 		push	word ptr Obj3DInf.POH+2D2h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2D0h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2D2h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2D0h ; struct TObj3DInfo[96]
//@ 		mov	ax, Obj3DInf.FTime+2D0h	; struct TObj3DInfo[96]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1587
//@ 
//@ loc_65EA:				; CODE XREF: ExpandPlayer+171j
//@ 		push	word ptr Obj3DInf.POH+2D2h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2D0h ; struct TObj3DInfo[96]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 260h	; Add
//@ 		push	ax
//@ 		push	b0		; uint16_t
//@ 		push	0
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1590
//@ 
//@ loc_660E:				; CODE XREF: ExpandPlayer+168j
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 4		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short locret_666A ; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1593
//@ 		mov	Invisibility, 1	; bool
//@ ; #line	"PS10.PAS" 1594
//@ 		mov	ax, word ptr Obj3DInf.PAni+2F4h	; struct TObj3DInfo[96]
//@ 		or	ax, word ptr Obj3DInf.PAni+2F6h	; struct TObj3DInfo[96]
//@ 		jz	short loc_6646	; Jump if Zero (ZF=1)
//@ 		push	word ptr Obj3DInf.POH+2F6h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2F4h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2F6h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.PAni+2F4h ; struct TObj3DInfo[96]
//@ 		mov	ax, Obj3DInf.FTime+2F4h	; struct TObj3DInfo[96]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1595
//@ 
//@ loc_6646:				; CODE XREF: ExpandPlayer+1CDj
//@ 		push	word ptr Obj3DInf.POH+2F6h ; struct TObj3DInfo[96]
//@ 		push	word ptr Obj3DInf.POH+2F4h ; struct TObj3DInfo[96]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		sub	ax, 40h	; '@'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	b0		; uint16_t
//@ 		push	0
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1598
//@ 
//@ locret_666A:				; CODE XREF: ExpandPlayer+1BFj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ ExpandPlayer	endp
//@ 
//@ ; #line	"PS10.PAS" 1609
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExpandMonster	proc near		; CODE XREF: DoGame+180Bp
//@ 
//@ var_3A		= dword	ptr -3Ah
//@ n		= word ptr -2Ch		; int16_t
//@ tz		= word ptr -2Ah		; int16_t
//@ CurMs		= word ptr -28h		; struct TMonster
//@ var_26		= word ptr -26h
//@ var_24		= word ptr -24h
//@ var_22		= word ptr -22h
//@ var_20		= word ptr -20h
//@ var_1E		= byte ptr -1Eh
//@ var_1D		= byte ptr -1Dh
//@ var_16		= word ptr -16h
//@ var_14		= word ptr -14h
//@ var_A		= word ptr -0Ah
//@ M		= word ptr  4		; int16_t
//@ ty1		= word ptr  0Ah		; int16_t
//@ tx1		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	3Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1610
//@ 		cmp	Obj3d, 0	; bool
//@ 		jnz	short loc_667C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_6814	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1611
//@ 
//@ loc_667C:				; CODE XREF: ExpandMonster+9j
//@ 		imul	di, [bp+M], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+CurMs]	; struct TMonster
//@ 		push	ss
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm3Anyt14Word ; Bitcopy of any type variable
//@ ; #line	"PS10.PAS" 1612
//@ 		mov	al, [bp+var_1E]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_3A], di
//@ 		mov	word ptr [bp+var_3A+2],	es
//@ ; #line	"PS10.PAS" 1614
//@ 		mov	ax, [bp+CurMs]	; struct TMonster
//@ 		mov	GlobX, ax	; int16_t
//@ 		mov	ax, [bp+var_26]
//@ 		mov	GlobY, ax	; int16_t
//@ ; #line	"PS10.PAS" 1616
//@ 		cmp	[bp+ty1], 0	; int16_t
//@ 		jle	short loc_66E0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ty1]	; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 8
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_66E5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_66E0:				; CODE XREF: ExpandMonster+49j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1617
//@ 
//@ loc_66E5:				; CODE XREF: ExpandMonster+70j
//@ 		cmp	[bp+n],	10h	; int16_t
//@ 		jle	short loc_66F0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+n],	10h	; int16_t
//@ ; #line	"PS10.PAS" 1618
//@ 
//@ loc_66F0:				; CODE XREF: ExpandMonster+7Bj
//@ 		push	[bp+CurMs]	; struct TMonster
//@ 		push	[bp+var_26]
//@ 		call	GetSmoothBrightAt ; function far PASCAL	returns	signed int 'Integer'
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		add	ax, [bp+n]	; int16_t
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"PS10.PAS" 1626
//@ 		mov	al, 0AAh ; 'ª'
//@ 		mov	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1627
//@ 		mov	al, [bp+var_1D]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6718	; Jump if Zero (ZF=1)
//@ 		mov	al, 3
//@ 		xor	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1628
//@ 
//@ loc_6718:				; CODE XREF: ExpandMonster+A2j
//@ 		mov	al, [bp+var_1D]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6727	; Jump if Zero (ZF=1)
//@ 		mov	al, 0Ch
//@ 		xor	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1629
//@ 
//@ loc_6727:				; CODE XREF: ExpandMonster+B1j
//@ 		mov	al, [bp+var_1D]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6736	; Jump if Zero (ZF=1)
//@ 		mov	al, 30h	; '0'
//@ 		xor	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1630
//@ 
//@ loc_6736:				; CODE XREF: ExpandMonster+C0j
//@ 		mov	al, [bp+var_1D]
//@ 		and	al, 8		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6745	; Jump if Zero (ZF=1)
//@ 		mov	al, 0C0h ; 'À'
//@ 		xor	DrawMask, al	; uint8_t
//@ ; #line	"PS10.PAS" 1632
//@ 
//@ loc_6745:				; CODE XREF: ExpandMonster+CFj
//@ 		mov	ax, [bp+var_20]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_3A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+var_22]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_6767	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_676C	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_676C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 1640
//@ 
//@ loc_6767:				; CODE XREF: ExpandMonster+F1j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+var_22], ax
//@ ; #line	"PS10.PAS" 1643
//@ 
//@ loc_676C:				; CODE XREF: ExpandMonster+F3j
//@ 					; ExpandMonster+F7j
//@ 		cmp	[bp+var_1E], 64h ; 'd' ; Compare Two Operands
//@ 		jnz	short loc_67A1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1644
//@ 		imul	di, [bp+var_14], 58h ; Signed Multiply
//@ 		mov	ax, [di-0FA0h]
//@ 		mov	ReColor, ax	; uint16_t
//@ 		push	[bp+CurMs]	; struct TMonster
//@ 		push	[bp+var_26]
//@ 		push	0
//@ 		lea	di, [bp+tz]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+n]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetLandHeight	; function far PASCAL returns void
//@ 		mov	ax, [bp+tz]	; int16_t
//@ 		imul	di, [bp+M], 28h	; int16_t
//@ 		mov	[di-5AC4h], ax
//@ 		jmp	short loc_67A7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1645
//@ 
//@ loc_67A1:				; CODE XREF: ExpandMonster+102j
//@ 		mov	ax, [bp+var_A]
//@ 		mov	[bp+tz], ax	; int16_t
//@ ; #line	"PS10.PAS" 1646
//@ 
//@ loc_67A7:				; CODE XREF: ExpandMonster+131j
//@ 		les	di, [bp+var_3A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+28h]
//@ 		push	word ptr es:[di+26h]
//@ 		mov	ax, [bp+var_20]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		push	word ptr es:[di+2Ch]
//@ 		push	word ptr es:[di+2Ah]
//@ 		mov	ax, [bp+var_22]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	Morph3d		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1647
//@ 		mov	ax, [bp+var_24]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	b0, ax		; uint16_t
//@ 		mov	ax, EHFi	; uint16_t
//@ 		add	b0, ax		; uint16_t
//@ 		add	b0, 0C000h	; uint16_t
//@ ; #line	"PS10.PAS" 1648
//@ 		les	di, [bp+var_3A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+28h]
//@ 		push	word ptr es:[di+26h]
//@ 		push	[bp+tx1]	; int16_t
//@ 		push	[bp+ty1]	; int16_t
//@ 		push	[bp+tz]		; int16_t
//@ 		push	b0		; uint16_t
//@ 		cmp	[bp+var_16], 0	; Compare Two Operands
//@ 		jle	short loc_6808	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	[bp+var_A], 0	; Compare Two Operands
//@ 		jz	short loc_680C	; Jump if Zero (ZF=1)
//@ 
//@ loc_6808:				; CODE XREF: ExpandMonster+192j
//@ 		mov	al, 0
//@ 		jmp	short loc_680E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_680C:				; CODE XREF: ExpandMonster+198j
//@ 		mov	al, 1
//@ 
//@ loc_680E:				; CODE XREF: ExpandMonster+19Cj
//@ 		push	ax
//@ 		call	Draw3DObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1650
//@ 
//@ locret_6814:				; CODE XREF: ExpandMonster+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ ExpandMonster	endp
//@ 
//@ ; #line	"PS10.PAS" 1667
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MapXY		proc near		; CODE XREF: Build3dScene+E9p
//@ 					; Build3dScene+140p ...
//@ 
//@ y		= word ptr  4		; int16_t
//@ x		= word ptr  6		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1668
//@ 		cmp	[bp+x],	0	; int16_t
//@ 		jl	short loc_6834	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+x],	3Fh ; '?' ; int16_t
//@ 		jg	short loc_6834	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	[bp+y],	0	; int16_t
//@ 		jl	short loc_6834	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+y],	3Fh ; '?' ; int16_t
//@ 		jle	short loc_6837	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_6834:				; CODE XREF: MapXY+8j MapXY+Ej ...
//@ 		jmp	locret_69C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1684
//@ 
//@ loc_6837:				; CODE XREF: MapXY+1Aj
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		mov	c, al		; uint8_t
//@ 		cmp	c, 0		; uint8_t
//@ 		jnz	short loc_685A	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_69C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1685
//@ 
//@ loc_685A:				; CODE XREF: MapXY+3Dj
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset L	; struct TLoc
//@ 		push	ds
//@ 		push	di
//@ 		push	0Bh
//@ 		call	@$basg$qm3Anyt14Word ; Bitcopy of any type variable
//@ ; #line	"PS10.PAS" 1686
//@ 		cmp	c, 79h ; 'y'    ; uint8_t
//@ 		jnb	short loc_68B3	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 1688
//@ 		mov	al, c		; uint8_t
//@ 		dec	al		; Decrement by 1
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+70B2h]
//@ 		mov	ImSeg, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1689
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_68AD	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	XOfsMask, 3Fh ;	'?' ; uint16_t
//@ 		jmp	short loc_68B3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_68AD:				; CODE XREF: MapXY+8Bj
//@ 		mov	XOfsMask, 7Fh ;	'' ; uint16_t
//@ ; #line	"PS10.PAS" 1692
//@ 
//@ loc_68B3:				; CODE XREF: MapXY+68j	MapXY+93j
//@ 		mov	al, L.Size	; struct TLoc
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	WXSize,	ax	; int16_t
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		shl	ax, 9		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	WShadowOfs, ax	; uint16_t
//@ ; #line	"PS10.PAS" 1694
//@ 		cmp	WXSize,	80h ; '€' ; int16_t
//@ 		jnz	short loc_68DD	; Jump if Not Zero (ZF=0)
//@ 		mov	SHRC, 0		; uint8_t
//@ 		jmp	short loc_68E2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_68DD:				; CODE XREF: MapXY+BCj
//@ 		mov	SHRC, 1		; uint8_t
//@ ; #line	"PS10.PAS" 1696
//@ 
//@ loc_68E2:				; CODE XREF: MapXY+C3j
//@ 		mov	al, c		; uint8_t
//@ ; #line	"PS10.PAS" 1697
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_6917	; Jump if Below	(CF=1)
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		ja	short loc_6917	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	di, offset L	; struct TLoc
//@ 		push	ds
//@ 		push	di
//@ 		mov	dx, [bp+y]	; int16_t
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+x] ; int16_t
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+y] ; int16_t
//@ 		push	ax
//@ 		call	InsertObject	; function far PASCAL returns void
//@ 		jmp	locret_69C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1698
//@ 
//@ loc_6917:				; CODE XREF: MapXY+CFj	MapXY+D3j
//@ 		cmp	al, 79h	; 'y'   ; Compare Two Operands
//@ 		jb	short loc_6953	; Jump if Below	(CF=1)
//@ 		cmp	al, 82h	; '‚'   ; Compare Two Operands
//@ 		ja	short loc_6953	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	WXSize,	100h	; int16_t
//@ 		mov	L.Spr, 79h ; 'y' ; struct TLoc
//@ 		mov	di, offset L	; struct TLoc
//@ 		push	ds
//@ 		push	di
//@ 		mov	dx, [bp+y]	; int16_t
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+x] ; int16_t
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+y] ; int16_t
//@ 		push	ax
//@ 		call	InsertObject	; function far PASCAL returns void
//@ 		jmp	short locret_69C3 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1699
//@ 
//@ loc_6953:				; CODE XREF: MapXY+101j MapXY+105j
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_698F	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_698F	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	WXSize,	100h	; int16_t
//@ 		mov	L.Spr, 7Ah ; 'z' ; struct TLoc
//@ 		mov	di, offset L	; struct TLoc
//@ 		push	ds
//@ 		push	di
//@ 		mov	dx, [bp+y]	; int16_t
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+x] ; int16_t
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+y] ; int16_t
//@ 		push	ax
//@ 		call	InsertObject	; function far PASCAL returns void
//@ 		jmp	short locret_69C3 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1700
//@ 
//@ loc_698F:				; CODE XREF: MapXY+13Dj MapXY+141j
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short locret_69C3 ; Jump if Below (CF=1)
//@ 		cmp	al, 64h	; 'd'   ; Compare Two Operands
//@ 		ja	short locret_69C3 ; Jump if Above (CF=0	& ZF=0)
//@ 		push	L.x2		; struct TLoc
//@ 		push	L.y2		; struct TLoc
//@ 		push	L.x1		; struct TLoc
//@ 		push	L.y1		; struct TLoc
//@ 		call	ExpandWall	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short locret_69C3 ; Jump if Zero (ZF=1)
//@ 		mov	dx, [bp+y]	; int16_t
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, VMask	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	byte ptr es:[di], 1
//@ ; #line	"PS10.PAS" 1708
//@ 
//@ locret_69C3:				; CODE XREF: MapXY:loc_6834j MapXY+3Fj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ MapXY		endp
//@ 
//@ ; #line	"PS10.PAS" 1785
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MoveRocket	proc near		; CODE XREF: AnimateRockets+4B1p
//@ 
//@ var_1A		= word ptr -1Ah
//@ vy		= word ptr -18h		; struct DWord
//@ var_16		= word ptr -16h
//@ vx		= word ptr -14h		; struct DWord
//@ var_12		= word ptr -12h
//@ dvy		= word ptr -10h		; struct DWord
//@ var_E		= word ptr -0Eh
//@ dvx		= word ptr -0Ch		; struct DWord
//@ var_A		= word ptr -0Ah
//@ s		= word ptr -8		; int16_t
//@ n		= word ptr -6		; int16_t
//@ i		= word ptr -4		; int16_t
//@ P		= word ptr  4		; int16_t
//@ R		= word ptr  6		; int16_t
//@ Owner		= word ptr  8		; int16_t
//@ _vy		= word ptr  0Ah		; int16_t
//@ _vx		= word ptr  0Ch		; int16_t
//@ rz		= word ptr  0Eh		; int16_t
//@ ry		= dword	ptr  10h	; struct DWord
//@ rx		= dword	ptr  14h	; struct DWord
//@ 
//@ 		enter	1Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1786
//@ 		cmp	Sd, 2		; int16_t
//@ 		jnz	short loc_69DC	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, t1,	28h	; uint16_t
//@ 		mov	[bp+s],	ax	; int16_t
//@ 		jmp	short loc_69F7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1787
//@ 
//@ loc_69DC:				; CODE XREF: MoveRocket+9j
//@ 		cmp	Sd, 0		; int16_t
//@ 		jnz	short loc_69EE	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	[bp+s],	ax	; int16_t
//@ 		jmp	short loc_69F7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1788
//@ 
//@ loc_69EE:				; CODE XREF: MoveRocket+1Aj
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		mov	[bp+s],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1790
//@ 
//@ loc_69F7:				; CODE XREF: MoveRocket+13j
//@ 					; MoveRocket+25j
//@ 		mov	ax, [bp+_vx]	; int16_t
//@ 		imul	[bp+s]		; int16_t
//@ ; #line	"PS10.PAS" 1791
//@ 		mov	[bp+var_12], dx
//@ ; #line	"PS10.PAS" 1792
//@ 		mov	[bp+vx], ax	; struct DWord
//@ ; #line	"PS10.PAS" 1794
//@ 		mov	ax, [bp+_vy]	; int16_t
//@ 		imul	[bp+s]		; int16_t
//@ ; #line	"PS10.PAS" 1795
//@ 		mov	[bp+var_16], dx
//@ ; #line	"PS10.PAS" 1796
//@ 		mov	[bp+vy], ax	; struct DWord
//@ ; #line	"PS10.PAS" 1802
//@ 		mov	ax, [bp+var_16]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+var_12]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3Ch	; '<'
//@ 		idiv	cx		; Signed Divide
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"PS10.PAS" 1803
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+vx]	; struct DWord
//@ 		mov	dx, [bp+var_12]
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvx], ax	; struct DWord
//@ 		mov	[bp+var_A], dx
//@ ; #line	"PS10.PAS" 1804
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+vy]	; struct DWord
//@ 		mov	dx, [bp+var_16]
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvy], ax	; struct DWord
//@ 		mov	[bp+var_E], dx
//@ ; #line	"PS10.PAS" 1806
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+var_1A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_1A]	; Compare Two Operands
//@ 		jle	short loc_6A70	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_6B6B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6A70:				; CODE XREF: MoveRocket+A4j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_6A78	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6A75:				; CODE XREF: MoveRocket+1A1j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"PS10.PAS" 1808
//@ 
//@ loc_6A78:				; CODE XREF: MoveRocket+ACj
//@ 		mov	ax, [bp+dvx]	; struct DWord
//@ 		mov	dx, [bp+var_A]
//@ 		les	di, [bp+rx]	; struct DWord
//@ 		add	es:[di], ax	; Add
//@ 		adc	es:[di+2], dx	; Add with Carry
//@ ; #line	"PS10.PAS" 1809
//@ 		mov	ax, [bp+dvy]	; struct DWord
//@ 		mov	dx, [bp+var_E]
//@ 		les	di, [bp+ry]	; struct DWord
//@ 		add	es:[di], ax	; Add
//@ 		adc	es:[di+2], dx	; Add with Carry
//@ ; #line	"PS10.PAS" 1810
//@ 		les	di, [bp+rx]	; struct DWord
//@ 		push	word ptr es:[di+2]
//@ 		les	di, [bp+ry]	; struct DWord
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+rz]		; int16_t
//@ 		push	4
//@ 		push	Cr		; int16_t
//@ 		push	0
//@ 		call	Rocket_WallCheck ; function far	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6AC0	; Jump if Zero (ZF=1)
//@ 		mov	Blow, 1		; int16_t
//@ ; #line	"PS10.PAS" 1811
//@ 
//@ loc_6AC0:				; CODE XREF: MoveRocket+F1j
//@ 		cmp	Blow, 0		; int16_t
//@ 		jnz	short loc_6AF1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1812
//@ 		les	di, [bp+rx]	; struct DWord
//@ 		push	word ptr es:[di+2]
//@ 		les	di, [bp+ry]	; struct DWord
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+rz]		; int16_t
//@ 		push	[bp+Owner]	; int16_t
//@ 		push	[bp+_vx]	; int16_t
//@ 		push	[bp+_vy]	; int16_t
//@ 		push	[bp+R]		; int16_t
//@ 		push	[bp+P]		; int16_t
//@ 		call	CheckMonsterContact ; function far PASCAL returns unsigned char	'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Blow, ax	; int16_t
//@ ; #line	"PS10.PAS" 1813
//@ 
//@ loc_6AF1:				; CODE XREF: MoveRocket+FEj
//@ 		cmp	Blow, 1Eh	; int16_t
//@ 		jge	short loc_6B60	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 1814
//@ 		cmp	Blow, 0		; int16_t
//@ 		jle	short loc_6B60	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 1815
//@ 		cmp	Blow, 1		; int16_t
//@ 		jnz	short loc_6B2A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1816
//@ 		mov	ax, [bp+dvx]	; struct DWord
//@ 		mov	dx, [bp+var_A]
//@ 		les	di, [bp+rx]	; struct DWord
//@ 		sub	es:[di], ax	; Integer Subtraction
//@ 		sbb	es:[di+2], dx	; Integer Subtraction with Borrow
//@ 		mov	ax, [bp+dvy]	; struct DWord
//@ 		mov	dx, [bp+var_E]
//@ 		les	di, [bp+ry]	; struct DWord
//@ 		sub	es:[di], ax	; Integer Subtraction
//@ 		sbb	es:[di+2], dx	; Integer Subtraction with Borrow
//@ 		jmp	short locret_6B6B ; Jump
//@ ; ---------------------------------------------------------------------------
//@ 		db 0EBh	; ë
//@ 		db  36h	; 6
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1817
//@ 
//@ loc_6B2A:				; CODE XREF: MoveRocket+13Dj
//@ 		mov	ax, [bp+dvx]	; struct DWord
//@ 		mov	dx, [bp+var_A]
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+rx]	; struct DWord
//@ 		sub	es:[di], ax	; Integer Subtraction
//@ 		sbb	es:[di+2], dx	; Integer Subtraction with Borrow
//@ 		mov	ax, [bp+dvy]	; struct DWord
//@ 		mov	dx, [bp+var_E]
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+ry]	; struct DWord
//@ 		sub	es:[di], ax	; Integer Subtraction
//@ 		sbb	es:[di+2], dx	; Integer Subtraction with Borrow
//@ 		jmp	short locret_6B6B ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1818
//@ 
//@ loc_6B60:				; CODE XREF: MoveRocket+12Fj
//@ 					; MoveRocket+136j
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_1A]	; Compare Two Operands
//@ 		jz	short locret_6B6B ; Jump if Zero (ZF=1)
//@ 		jmp	loc_6A75	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1819
//@ 
//@ locret_6B6B:				; CODE XREF: MoveRocket+A6j
//@ 					; MoveRocket+15Fj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	14h		; Return Near from Procedure
//@ MoveRocket	endp
//@ 
//@ ; #line	"PS10.PAS" 1830
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateRockets	proc near		; CODE XREF: DoGame+16FAp
//@ 
//@ var_18		= dword	ptr -18h
//@ var_14		= dword	ptr -14h
//@ var_E		= word ptr -0Eh
//@ var_C		= dword	ptr -0Ch
//@ water		= byte ptr -8		; bool
//@ SkyC		= byte ptr -7		; bool
//@ cc		= byte ptr -6		; bool
//@ Comp		= byte ptr -5		; bool
//@ n		= word ptr -4		; int16_t
//@ i		= word ptr -2		; int16_t
//@ 
//@ 		enter	18h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1831
//@ 		mov	[bp+n],	1	; int16_t
//@ ; #line	"PS10.PAS" 1832
//@ 
//@ loc_6B78:				; CODE XREF: AnimateRockets+46j
//@ 					; AnimateRockets+88j ...
//@ 		mov	ax, MnCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_6B95	; Jump if Less (SF!=OF)
//@ 		jle	short loc_6B8E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_6D76	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6B8E:				; CODE XREF: AnimateRockets+1Aj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_6B95	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_6D76	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6B95:				; CODE XREF: AnimateRockets+18j
//@ 					; AnimateRockets+21j
//@ 		imul	di, [bp+n], 0Ah	; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"PS10.PAS" 1834
//@ 		cmp	word ptr es:[di+4], 418h ; Compare Two Operands
//@ 		jle	short loc_6BB7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		push	[bp+n]		; int16_t
//@ 		call	ExplodeMine	; function far PASCAL returns void
//@ 		jmp	short loc_6B78	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1836
//@ 
//@ loc_6BB7:				; CODE XREF: AnimateRockets+3Cj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4], 118h ; Compare Two Operands
//@ 		jl	short loc_6BCA	; Jump if Less (SF!=OF)
//@ 		cmp	word ptr es:[di+4], 400h ; Compare Two Operands
//@ 		jl	short loc_6BFA	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 1838
//@ 
//@ loc_6BCA:				; CODE XREF: AnimateRockets+51j
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+4], ax	; Add
//@ ; #line	"PS10.PAS" 1839
//@ 		cmp	word ptr es:[di+4], 118h ; Compare Two Operands
//@ 		jl	short loc_6BF4	; Jump if Less (SF!=OF)
//@ 		cmp	word ptr es:[di+4], 400h ; Compare Two Operands
//@ 		jge	short loc_6BF4	; Jump if Greater or Equal (SF=OF)
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	48h ; 'H'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1840
//@ 
//@ loc_6BF4:				; CODE XREF: AnimateRockets+6Bj
//@ 					; AnimateRockets+73j
//@ 		inc	[bp+n]		; int16_t
//@ 		jmp	loc_6B78	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1843
//@ 
//@ loc_6BFA:				; CODE XREF: AnimateRockets+59j
//@ 		mov	[bp+Comp], 0	; bool
//@ ; #line	"PS10.PAS" 1844
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_E], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_E]	; Compare Two Operands
//@ 		jle	short loc_6C0F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_6CAD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6C0F:				; CODE XREF: AnimateRockets+9Bj
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_6C17	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6C14:				; CODE XREF: AnimateRockets+13Bj
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_6C17:				; CODE XREF: AnimateRockets+A3j
//@ 		imul	di, [bp+i], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_14+2],	di
//@ 		mov	word ptr [bp-10h], es
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_6CA2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 1845
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 118h	; Compare Two Operands
//@ 		jge	short loc_6CA2	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_14+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 118h	; Compare Two Operands
//@ 		jge	short loc_6CA2	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 1846
//@ 		les	di, [bp+var_14+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		les	di, [bp+var_14+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 118h	; Compare Two Operands
//@ 		jnb	short loc_6CA2	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 1847
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		les	di, [bp+var_14+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	3
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6CA2	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1848
//@ 		mov	[bp+Comp], 1	; bool
//@ 
//@ loc_6CA2:				; CODE XREF: AnimateRockets+BDj
//@ 					; AnimateRockets+D0j ...
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_E]	; Compare Two Operands
//@ 		jz	short loc_6CAD	; Jump if Zero (ZF=1)
//@ 		jmp	loc_6C14	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1850
//@ 
//@ loc_6CAD:				; CODE XREF: AnimateRockets+9Dj
//@ 					; AnimateRockets+139j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_6CB7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6CB4:				; CODE XREF: AnimateRockets+1DCj
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_6CB7:				; CODE XREF: AnimateRockets+143j
//@ 		imul	di, [bp+i], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	[bp-10h], di
//@ 		mov	[bp+var_E], es
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_6D45	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 1851
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 118h	; Compare Two Operands
//@ 		jge	short loc_6D45	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 118h	; Compare Two Operands
//@ 		jge	short loc_6D45	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 1852
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 118h	; Compare Two Operands
//@ 		jnb	short loc_6D45	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 1853
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	3
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_6D45	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1854
//@ 		mov	[bp+Comp], 1	; bool
//@ 
//@ loc_6D45:				; CODE XREF: AnimateRockets+15Dj
//@ 					; AnimateRockets+171j ...
//@ 		cmp	[bp+i],	7	; int16_t
//@ 		jz	short loc_6D4E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_6CB4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1856
//@ 
//@ loc_6D4E:				; CODE XREF: AnimateRockets+1DAj
//@ 		cmp	[bp+Comp], 0	; bool
//@ 		jz	short loc_6D70	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1857
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	48h ; 'H'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+4], 400h
//@ ; #line	"PS10.PAS" 1859
//@ 
//@ loc_6D70:				; CODE XREF: AnimateRockets+1E3j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 1860
//@ 		jmp	loc_6B78	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1863
//@ 
//@ loc_6D76:				; CODE XREF: AnimateRockets+1Cj
//@ 					; AnimateRockets+23j
//@ 		mov	[bp+n],	1	; int16_t
//@ ; #line	"PS10.PAS" 1864
//@ 
//@ loc_6D7B:				; CODE XREF: AnimateRockets+822j
//@ 		mov	ax, RCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_6D98	; Jump if Less (SF!=OF)
//@ 		jle	short loc_6D91	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_7394	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6D91:				; CODE XREF: AnimateRockets+21Dj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_6D98	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_7394	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6D98:				; CODE XREF: AnimateRockets+21Bj
//@ 					; AnimateRockets+224j
//@ 		imul	di, [bp+n], 18h	; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		add	di, 0CD84h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	[bp-10h], di
//@ 		mov	[bp+var_E], es
//@ ; #line	"PS10.PAS" 1866
//@ 		mov	al, byte ptr t1	; uint16_t
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	es:[di+0Dh], al	; Add
//@ ; #line	"PS10.PAS" 1867
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+0Ch]	; Compare Two Operands
//@ 		jb	short loc_6DE1	; Jump if Below	(CF=1)
//@ 		mov	al, es:[di+0Ch]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+0Dh], al	; Integer Subtraction
//@ ; #line	"PS10.PAS" 1868
//@ 
//@ loc_6DE1:				; CODE XREF: AnimateRockets+265j
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		mov	Cr, ax		; int16_t
//@ ; #line	"PS10.PAS" 1869
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Blow, ax	; int16_t
//@ ; #line	"PS10.PAS" 1870
//@ 		mov	al, es:[di+0Ah]
//@ 		and	al, 1		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Sd, ax		; int16_t
//@ ; #line	"PS10.PAS" 1871
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Ch], 11h ; Compare Two	Operands
//@ 		jnz	short loc_6E0B	; Jump if Not Zero (ZF=0)
//@ 		mov	Sd, 2		; int16_t
//@ ; #line	"PS10.PAS" 1873
//@ 
//@ loc_6E0B:				; CODE XREF: AnimateRockets+294j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFFFh ; Compare Two Operands
//@ 		jg	short loc_6E18	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_6F98	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1875
//@ 
//@ loc_6E18:				; CODE XREF: AnimateRockets+2A4j
//@ 		cmp	word ptr es:[di+14h], 64h ; 'd' ; Compare Two Operands
//@ 		jge	short loc_6E94	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 1876
//@ 		imul	di, es:[di+14h], 28h ; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_14], di
//@ 		mov	word ptr [bp+var_14+2],	es
//@ ; #line	"PS10.PAS" 1877
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jnz	short loc_6E4F	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	rtgx, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	rtgy, ax	; int16_t
//@ 		mov	rtgz, 440h	; int16_t
//@ 		mov	word ptr es:[di+14h], 0FFFFh
//@ 		jmp	short loc_6E92	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1878
//@ 
//@ loc_6E4F:				; CODE XREF: AnimateRockets+2C6j
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_18], di
//@ 		mov	word ptr [bp+var_18+2],	es
//@ ; #line	"PS10.PAS" 1879
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		mov	rtgx, ax	; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	rtgy, ax	; int16_t
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	rtgz, ax	; int16_t
//@ 
//@ loc_6E92:				; CODE XREF: AnimateRockets+2DEj
//@ 		jmp	short loc_6EE1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1881
//@ 
//@ loc_6E94:				; CODE XREF: AnimateRockets+2AEj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		sub	ax, 0C8h ; 'È'  ; Integer Subtraction
//@ 		imul	di, ax,	58h	; Signed Multiply
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"PS10.PAS" 1882
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_6EC8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	rtgx, ax	; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	rtgy, ax	; int16_t
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 440h	; Add
//@ 		mov	rtgz, ax	; int16_t
//@ 		jmp	short loc_6EE1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1883
//@ 
//@ loc_6EC8:				; CODE XREF: AnimateRockets+33Dj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	rtgx, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	rtgy, ax	; int16_t
//@ 		mov	rtgz, 440h	; int16_t
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	word ptr es:[di+14h], 0FFFFh
//@ ; #line	"PS10.PAS" 1885
//@ 
//@ loc_6EE1:				; CODE XREF: AnimateRockets:loc_6E92j
//@ 					; AnimateRockets+357j
//@ 		cmp	rtgx, 0		; int16_t
//@ 		jg	short loc_6EEB	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_6F98	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1887
//@ 
//@ loc_6EEB:				; CODE XREF: AnimateRockets+377j
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		mov	rdfi, ax	; int16_t
//@ ; #line	"PS10.PAS" 1888
//@ 		mov	rn, 1		; int16_t
//@ 		jmp	short loc_6F00	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_6EFC:				; CODE XREF: AnimateRockets+3D7j
//@ 		inc	rn		; int16_t
//@ ; #line	"PS10.PAS" 1890
//@ 
//@ loc_6F00:				; CODE XREF: AnimateRockets+38Bj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Eh]
//@ 		push	word ptr es:[di+10h]
//@ 		mov	ax, rtgx	; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, rtgy	; int16_t
//@ 		sub	ax, es:[di+6]	; Integer Subtraction
//@ 		push	ax
//@ 		call	MulVectors	; function near	PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jnz	short loc_6F2F	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1891
//@ 		mov	ax, rdfi	; int16_t
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ah], ax	; Add
//@ 		jmp	short loc_6F39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1892
//@ 
//@ loc_6F2F:				; CODE XREF: AnimateRockets+3B2j
//@ 		mov	ax, rdfi	; int16_t
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+0Ah], ax	; Integer Subtraction
//@ ; #line	"PS10.PAS" 1893
//@ 
//@ loc_6F39:				; CODE XREF: AnimateRockets+3BEj
//@ 		mov	ax, rdfi	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	rdfi, ax	; int16_t
//@ ; #line	"PS10.PAS" 1894
//@ 		cmp	rn, 5		; int16_t
//@ 		jnz	short loc_6EFC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1895
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, 0		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"PS10.PAS" 1896
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, 4000h	; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"PS10.PAS" 1897
//@ 		mov	ax, rtgz	; int16_t
//@ 		sub	ax, es:[di+8]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 6
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+12h], ax
//@ ; #line	"PS10.PAS" 1901
//@ 
//@ loc_6F98:				; CODE XREF: AnimateRockets+2A6j
//@ 					; AnimateRockets+379j
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Bh], 0	; Compare Two Operands
//@ 		jbe	short loc_6FCA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 1902
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		mov	ax, es:[di+8]
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	8
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	AddBlow		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1904
//@ 
//@ loc_6FCA:				; CODE XREF: AnimateRockets+431j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sd		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+12h] ; Unsigned	Multiplication of AL or	AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"PS10.PAS" 1905
//@ 		push	es
//@ 		push	di
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Eh]
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+16h]
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+8]
//@ 		call	MoveRocket	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 1906
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Sd		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+12h] ; Unsigned	Multiplication of AL or	AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"PS10.PAS" 1908
//@ 		cmp	Blow, 1Eh	; int16_t
//@ 		jz	short loc_705D	; Jump if Zero (ZF=1)
//@ 		jmp	loc_70DC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1910
//@ 
//@ loc_705D:				; CODE XREF: AnimateRockets+4E9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Blow, ax	; int16_t
//@ ; #line	"PS10.PAS" 1911
//@ 		mov	ax, es:[di+12h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+16h], ax
//@ ; #line	"PS10.PAS" 1912
//@ 		push	2000h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 7000h	; Add
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ah], ax	; Add
//@ ; #line	"PS10.PAS" 1913
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, 0		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"PS10.PAS" 1914
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, 4000h	; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"PS10.PAS" 1915
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		add	es:[di+2], ax	; Add
//@ ; #line	"PS10.PAS" 1916
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"PS10.PAS" 1919
//@ 
//@ loc_70DC:				; CODE XREF: AnimateRockets+4EBj
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+2], 0 ;	Compare	Two Operands
//@ 		jle	short loc_7100	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+2]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+12h], ax	; Integer Subtraction
//@ ; #line	"PS10.PAS" 1920
//@ 
//@ loc_7100:				; CODE XREF: AnimateRockets+575j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+7]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 6		; Shift	Logical	Left
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr [di+5EC6h], 3Eh ; '>' ; Compare Two Operands
//@ 		mov	al, 0
//@ 		jnz	short loc_7122	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_7122:				; CODE XREF: AnimateRockets+5B0j
//@ 		mov	[bp+SkyC], al	; bool
//@ ; #line	"PS10.PAS" 1921
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 0F40h ; Compare Two	Operands
//@ 		jle	short loc_7136	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	[bp+SkyC], 0	; bool
//@ 		jz	short loc_7144	; Jump if Zero (ZF=1)
//@ 
//@ loc_7136:				; CODE XREF: AnimateRockets+5BFj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 60h	; '`' ; Compare Two Operands
//@ 		jl	short loc_7144	; Jump if Less (SF!=OF)
//@ 		mov	al, 0
//@ 		jmp	short loc_7146	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7144:				; CODE XREF: AnimateRockets+5C5j
//@ 					; AnimateRockets+5CFj
//@ 		mov	al, 1
//@ 
//@ loc_7146:				; CODE XREF: AnimateRockets+5D3j
//@ 		mov	[bp+cc], al	; bool
//@ ; #line	"PS10.PAS" 1926
//@ 		cmp	[bp+cc], 0	; bool
//@ 		jz	short loc_7181	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1927
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		and	al, 20h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_717B	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1928
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+12h], ax
//@ 		mov	ax, es:[di+12h]
//@ 		add	es:[di+8], ax	; Add
//@ 		jmp	short loc_7181	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_717B:				; CODE XREF: AnimateRockets+5EBj
//@ 		mov	Blow, 1		; int16_t
//@ ; #line	"PS10.PAS" 1930
//@ 
//@ loc_7181:				; CODE XREF: AnimateRockets+5DEj
//@ 					; AnimateRockets+60Aj
//@ 		cmp	[bp+SkyC], 0	; bool
//@ 		jnz	short loc_7198	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 0F40h ; Compare Two	Operands
//@ 		jle	short loc_7198	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+8], 0F40h
//@ ; #line	"PS10.PAS" 1931
//@ 
//@ loc_7198:				; CODE XREF: AnimateRockets+616j
//@ 					; AnimateRockets+621j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 60h	; '`' ; Compare Two Operands
//@ 		jge	short loc_71A8	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+8], 60h	; '`'
//@ ; #line	"PS10.PAS" 1933
//@ 
//@ loc_71A8:				; CODE XREF: AnimateRockets+631j
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_71CC	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	5
//@ 		push	14h
//@ 		push	0FFh
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1935
//@ 
//@ loc_71CC:				; CODE XREF: AnimateRockets+644j
//@ 		cmp	Blow, 0		; int16_t
//@ 		jg	short loc_71E8	; Jump if Greater (ZF=0	& SF=OF)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 1500h ; Compare Two	Operands
//@ 		jle	short loc_71E4	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	[bp+SkyC], 0	; bool
//@ 		jnz	short loc_71E8	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_71E4:				; CODE XREF: AnimateRockets+66Dj
//@ 		mov	al, 0
//@ 		jmp	short loc_71EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_71E8:				; CODE XREF: AnimateRockets+662j
//@ 					; AnimateRockets+673j
//@ 		mov	al, 1
//@ 
//@ loc_71EA:				; CODE XREF: AnimateRockets+677j
//@ 		mov	[bp+Comp], al	; bool
//@ ; #line	"PS10.PAS" 1936
//@ 		cmp	[bp+Comp], 0	; bool
//@ 		jnz	short loc_71F6	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_738E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1938
//@ 
//@ loc_71F6:				; CODE XREF: AnimateRockets+682j
//@ 		cmp	Blow, 0		; int16_t
//@ 		jg	short loc_7200	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_734E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1940
//@ 
//@ loc_7200:				; CODE XREF: AnimateRockets+68Cj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 200h ; Compare Two Operands
//@ 		jge	short loc_721E	; Jump if Greater or Equal (SF=OF)
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	0
//@ 		call	iswater		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_7222	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_721E:				; CODE XREF: AnimateRockets+69Aj
//@ 		mov	al, 0
//@ 		jmp	short loc_7224	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7222:				; CODE XREF: AnimateRockets+6ADj
//@ 		mov	al, 1
//@ 
//@ loc_7224:				; CODE XREF: AnimateRockets+6B1j
//@ 		mov	[bp+water], al	; bool
//@ ; #line	"PS10.PAS" 1942
//@ 		cmp	[bp+water], 0	; bool
//@ 		jz	short loc_7243	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	0
//@ 		push	1
//@ 		call	BlowShootSmoke	; function far PASCAL returns void
//@ 		jmp	short loc_725E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1943
//@ 
//@ loc_7243:				; CODE XREF: AnimateRockets+6BCj
//@ 		cmp	Blow, 3		; int16_t
//@ 		jge	short loc_725E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 1944
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		call	BlowSmoke	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1946
//@ 
//@ loc_725E:				; CODE XREF: AnimateRockets+6D2j
//@ 					; AnimateRockets+6D9j
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di], 2 ; Compare Two Operands
//@ 		jnz	short loc_727D	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		call	AddGreatBlow	; function far PASCAL returns void
//@ 		jmp	short loc_72DC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1947
//@ 
//@ loc_727D:				; CODE XREF: AnimateRockets+6F6j
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di], 4 ; Compare Two Operands
//@ 		jnz	short loc_729C	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		call	AddSuperGreatBlow ; function far PASCAL	returns	void
//@ 		jmp	short loc_72DC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1949
//@ 
//@ loc_729C:				; CODE XREF: AnimateRockets+715j
//@ 		cmp	Blow, 1		; int16_t
//@ 		jnz	short loc_72C4	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Ch], 11h ; Compare Two	Operands
//@ 		jz	short loc_72C4	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1950
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		push	20h ; ' '
//@ 		push	1
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ 		jmp	short loc_72DC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1951
//@ 
//@ loc_72C4:				; CODE XREF: AnimateRockets+732j
//@ 					; AnimateRockets+73Cj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		push	20h ; ' '
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1954
//@ 
//@ loc_72DC:				; CODE XREF: AnimateRockets+70Cj
//@ 					; AnimateRockets+72Bj ...
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		les	di, [bp-10h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+8]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+16h]
//@ 		call	MakeBlow	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1955
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	8
//@ 		push	20h ; ' '
//@ 		push	20h ; ' '
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1956
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 1Eh		; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1957
//@ 		cmp	[bp+water], 0	; bool
//@ 		jz	short loc_734E	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	0Bh
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 1960
//@ 
//@ loc_734E:				; CODE XREF: AnimateRockets+68Ej
//@ 					; AnimateRockets+7C9j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	18h	; Signed Multiply
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, [bp+n], 18h	; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, RCount	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 18h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"PS10.PAS" 1961
//@ 		dec	[bp+n]		; int16_t
//@ 		dec	RCount		; uint16_t
//@ ; #line	"PS10.PAS" 1963
//@ 
//@ loc_738E:				; CODE XREF: AnimateRockets+684j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 1964
//@ 		jmp	loc_6D7B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1965
//@ 
//@ locret_7394:				; CODE XREF: AnimateRockets+21Fj
//@ 					; AnimateRockets+226j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ AnimateRockets	endp
//@ 
//@ ; #line	"PS10.PAS" 1978
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL varargs returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ GetNearestWall	proc near		; CODE XREF: AnimateSwitches+42p
//@ 
//@ var_16		= dword	ptr -16h
//@ var_12		= word ptr -12h
//@ var_10		= word ptr -10h
//@ y2		= word ptr -0Eh		; int16_t
//@ x2		= word ptr -0Ch		; int16_t
//@ y1		= word ptr -0Ah		; int16_t
//@ x1		= word ptr -8		; int16_t
//@ y		= word ptr -6		; int16_t
//@ x		= word ptr -4		; int16_t
//@ GetNearestWall	= byte ptr -1		; bool
//@ wy		= dword	ptr  4		; int16_t
//@ wx		= dword	ptr  8		; int16_t
//@ arg_9		= byte ptr  0Dh
//@ arg_B		= byte ptr  0Fh
//@ arg_D		= byte ptr  11h
//@ arg_F		= byte ptr  13h
//@ 
//@ 		enter	16h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 1979
//@ 		mov	[bp+GetNearestWall], 0 ; bool
//@ ; #line	"PS10.PAS" 1980
//@ 		mov	al, [bp+arg_F]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+x1], ax	; int16_t
//@ 		mov	al, [bp+arg_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+x2], ax	; int16_t
//@ ; #line	"PS10.PAS" 1981
//@ 		mov	al, [bp+arg_D]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+y1], ax	; int16_t
//@ 		mov	al, [bp+arg_9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+y2], ax	; int16_t
//@ ; #line	"PS10.PAS" 1982
//@ 		cmp	[bp+x1], 0	; int16_t
//@ 		jge	short loc_73D1	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x1], ax	; int16_t
//@ 
//@ loc_73D1:				; CODE XREF: GetNearestWall+34j
//@ 		cmp	[bp+y1], 0	; int16_t
//@ 		jge	short loc_73DC	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"PS10.PAS" 1983
//@ 
//@ loc_73DC:				; CODE XREF: GetNearestWall+3Fj
//@ 		cmp	[bp+x1], 3Fh ; '?' ; int16_t
//@ 		jle	short loc_73E7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+x1], 3Fh ; '?' ; int16_t
//@ 
//@ loc_73E7:				; CODE XREF: GetNearestWall+4Aj
//@ 		cmp	[bp+y1], 3Fh ; '?' ; int16_t
//@ 		jle	short loc_73F2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+y1], 3Fh ; '?' ; int16_t
//@ ; #line	"PS10.PAS" 1985
//@ 
//@ loc_73F2:				; CODE XREF: GetNearestWall+55j
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jle	short loc_7403	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_74CC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7403:				; CODE XREF: GetNearestWall+68j
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_740B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7408:				; CODE XREF: GetNearestWall+133j
//@ 		inc	[bp+x]		; int16_t
//@ ; #line	"PS10.PAS" 1986
//@ 
//@ loc_740B:				; CODE XREF: GetNearestWall+70j
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jle	short loc_741C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_74C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_741C:				; CODE XREF: GetNearestWall+81j
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_7424	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7421:				; CODE XREF: GetNearestWall+128j
//@ 		inc	[bp+y]		; int16_t
//@ 
//@ loc_7424:				; CODE XREF: GetNearestWall+89j
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"PS10.PAS" 1987
//@ 		mov	al, es:[di]
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_74B6	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_74B6	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 1989
//@ 		cmp	byte ptr es:[di], 56h ;	'V' ; Compare Two Operands
//@ 		jnb	short loc_7478	; Jump if Not Below (CF=0)
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+9]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+12h]
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+10h]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		push	ax
//@ 		call	MulVectors	; function near	PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_74B6	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 1991
//@ 
//@ loc_7478:				; CODE XREF: GetNearestWall+B6j
//@ 		push	word ptr [bp+12h]
//@ 		push	word ptr [bp+10h]
//@ 		push	word ptr [bp+0Eh]
//@ 		push	word ptr [bp+0Ch]
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+7]
//@ 		push	word ptr es:[di+9]
//@ 		call	Test2Vectors	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_74B6	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 1992
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		les	di, [bp+wx]	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		les	di, [bp+wy]	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	[bp+GetNearestWall], 1 ; bool
//@ 		jmp	short loc_74CC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1993
//@ 
//@ loc_74B6:				; CODE XREF: GetNearestWall+ACj
//@ 					; GetNearestWall+B0j ...
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jz	short loc_74C1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7421	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_74C1:				; CODE XREF: GetNearestWall+83j
//@ 					; GetNearestWall+126j
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jz	short loc_74CC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7408	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 1994
//@ 
//@ loc_74CC:				; CODE XREF: GetNearestWall+6Aj
//@ 					; GetNearestWall+11Ej ...
//@ 		mov	al, [bp+GetNearestWall]	; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ GetNearestWall	endp
//@ 
//@ ; #line	"PS10.PAS" 2004
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddClientProcesses proc	near		; CODE XREF: DoGame:loc_D975p
//@ 
//@ var_C		= word ptr -0Ch
//@ var_A		= dword	ptr -0Ah
//@ var_6		= dword	ptr -6
//@ var_2		= word ptr -2
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2005
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jle	short loc_74E8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_7643	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_74E8:				; CODE XREF: AddClientProcesses+10j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_74F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_74ED:				; CODE XREF: AddClientProcesses+16Dj
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 2006
//@ 
//@ loc_74F1:				; CODE XREF: AddClientProcesses+18j
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ 		cmp	byte ptr es:[di+0Bh], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_750C	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_7638	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2007
//@ 
//@ loc_750C:				; CODE XREF: AddClientProcesses+34j
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"PS10.PAS" 2009
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+8], 10h	; Compare Two Operands
//@ 		jge	short loc_7536	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jz	short loc_7536	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7638	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2010
//@ 
//@ loc_7536:				; CODE XREF: AddClientProcesses+57j
//@ 					; AddClientProcesses+5Ej
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+1]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 6		; Shift	Logical	Left
//@ 		add	di, dx		; Add
//@ 		mov	al, [di+4EC6h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-23F0h], 0 ; Compare Two Operands
//@ 		jnz	short loc_7560	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_7638	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2011
//@ 
//@ loc_7560:				; CODE XREF: AddClientProcesses+88j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_7593	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_758C	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_7638	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_758C:				; CODE XREF: AddClientProcesses+B4j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_7593	; Jump if Not Below (CF=0)
//@ 		jmp	loc_7638	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7593:				; CODE XREF: AddClientProcesses+B2j
//@ 					; AddClientProcesses+BBj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, 10h		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_75C0	; Jump if Less (SF!=OF)
//@ 		jg	short loc_7638	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_7638	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 2012
//@ 
//@ loc_75C0:				; CODE XREF: AddClientProcesses+E5j
//@ 		mov	ax, t1		; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_C], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		ja	short loc_7638	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_75D7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_75D3:				; CODE XREF: AddClientProcesses+163j
//@ 		inc	j		; uint16_t
//@ ; #line	"PS10.PAS" 2013
//@ 
//@ loc_75D7:				; CODE XREF: AddClientProcesses+FEj
//@ 		push	104h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 82h	; '‚'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	104h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 82h	; '‚'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	8
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		mov	ax, j		; uint16_t
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		jnz	short loc_75D3	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2015
//@ 
//@ loc_7638:				; CODE XREF: AddClientProcesses+36j
//@ 					; AddClientProcesses+60j ...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jz	short loc_7643	; Jump if Zero (ZF=1)
//@ 		jmp	loc_74ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2017
//@ 
//@ loc_7643:				; CODE XREF: AddClientProcesses+12j
//@ 					; AddClientProcesses+16Bj
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jg	short locret_76B3 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_765A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7656:				; CODE XREF: AddClientProcesses+1DEj
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 2018
//@ 
//@ loc_765A:				; CODE XREF: AddClientProcesses+181j
//@ 		imul	di, n$0, 18h	; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"PS10.PAS" 2019
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		add	di, 0CD84h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ 		cmp	byte ptr es:[di+0Bh], 0	; Compare Two Operands
//@ 		jbe	short loc_76AB	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 2020
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		push	0
//@ 		push	0
//@ 		push	2Ah ; '*'
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 
//@ loc_76AB:				; CODE XREF: AddClientProcesses+1B2j
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jnz	short loc_7656	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2021
//@ 
//@ locret_76B3:				; CODE XREF: AddClientProcesses+17Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ AddClientProcesses endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aWrongWay	db 10,'Wrong Way!'      ; DATA XREF: AnimateSwitches:loc_7724o
//@ ; #line	"PS10.PAS" 2038
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateSwitches	proc near		; CODE XREF: DoGame+15D9p DoGame+160Bp
//@ 
//@ var_10		= dword	ptr -10h
//@ var_C		= dword	ptr -0Ch
//@ var_8		= word ptr -8
//@ wy		= word ptr -6		; int16_t
//@ wx		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ Ownr		= word ptr  4		; int16_t
//@ hy2		= word ptr  6		; int16_t
//@ hx2		= word ptr  8		; int16_t
//@ arg_7		= byte ptr  0Bh
//@ arg_9		= byte ptr  0Dh
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2039
//@ 		cmp	LinksCount, 0	; int16_t
//@ 		jnz	short loc_76CE	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_7835	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2040
//@ 
//@ loc_76CE:				; CODE XREF: AnimateSwitches+9j
//@ 		cmp	[bp+hx2], 0FFFFh ; int16_t
//@ 		jnz	short loc_76EC	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+hy2], 0FFFFh ; int16_t
//@ 		jnz	short loc_76EC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2041
//@ 		mov	al, [bp+arg_9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+wx], ax	; int16_t
//@ 		mov	al, [bp+arg_7]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+wy], ax	; int16_t
//@ 		jmp	short loc_770C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2042
//@ 
//@ loc_76EC:				; CODE XREF: AnimateSwitches+12j
//@ 					; AnimateSwitches+18j
//@ 		push	word ptr [bp+0Ch]
//@ 		push	word ptr [bp+0Ah]
//@ 		push	[bp+hx2]	; int16_t
//@ 		push	[bp+hy2]	; int16_t
//@ 		lea	di, [bp+wx]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+wy]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetNearestWall	; function near	PASCAL varargs returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_770C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_7835	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2044
//@ 
//@ loc_770C:				; CODE XREF: AnimateSwitches+2Aj
//@ 					; AnimateSwitches+47j
//@ 		cmp	[bp+wx], 0	; int16_t
//@ 		jl	short loc_7724	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+wx], 3Fh ; '?' ; int16_t
//@ 		jg	short loc_7724	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	[bp+wy], 0	; int16_t
//@ 		jl	short loc_7724	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+wy], 3Fh ; '?' ; int16_t
//@ 		jle	short loc_772E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_7724:				; CODE XREF: AnimateSwitches+50j
//@ 					; AnimateSwitches+56j ...
//@ 		mov	di, offset aWrongWay ; "Wrong Way!"
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2046
//@ 
//@ loc_772E:				; CODE XREF: AnimateSwitches+62j
//@ 		mov	ax, LinksCount	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_8], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jle	short loc_773F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_7835	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_773F:				; CODE XREF: AnimateSwitches+7Aj
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_7747	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7744:				; CODE XREF: AnimateSwitches+172j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 2047
//@ 
//@ loc_7747:				; CODE XREF: AnimateSwitches+82j
//@ 		imul	ax, [bp+n], 7	; int16_t
//@ 		les	di, PLinks	; TLinksList$Element*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"PS10.PAS" 2048
//@ 		mov	ax, es:[di+1]
//@ 		cmp	ax, [bp+wx]	; int16_t
//@ 		jz	short loc_7763	; Jump if Zero (ZF=1)
//@ 		jmp	loc_782A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7763:				; CODE XREF: AnimateSwitches+9Ej
//@ 		mov	ax, es:[di+3]
//@ 		cmp	ax, [bp+wy]	; int16_t
//@ 		jz	short loc_776F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_782A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2049
//@ 
//@ loc_776F:				; CODE XREF: AnimateSwitches+AAj
//@ 		mov	al, es:[di]
//@ ; #line	"PS10.PAS" 2050
//@ 		cmp	al, 6Ch	; 'l'   ; Compare Two Operands
//@ 		jnz	short loc_7785	; Jump if Not Zero (ZF=0)
//@ 		push	word ptr es:[di+5]
//@ 		push	[bp+Ownr]	; int16_t
//@ 		call	StartProcess	; function far PASCAL returns void
//@ 		jmp	loc_782A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2051
//@ 
//@ loc_7785:				; CODE XREF: AnimateSwitches+B4j
//@ 		cmp	al, 72h	; 'r'   ; Compare Two Operands
//@ 		jnz	short loc_77C3	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+5], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"PS10.PAS" 2052
//@ 		cmp	byte ptr es:[di+1], 3 ;	Compare	Two Operands
//@ 		jz	short loc_77B3	; Jump if Zero (ZF=1)
//@ 		cmp	byte ptr es:[di+1], 2 ;	Compare	Two Operands
//@ 		jnz	short loc_77C1	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jle	short loc_77C1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2053
//@ 
//@ loc_77B3:				; CODE XREF: AnimateSwitches+E3j
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+1], 2
//@ 		mov	word ptr es:[di+24h], 1
//@ 
//@ loc_77C1:				; CODE XREF: AnimateSwitches+EAj
//@ 					; AnimateSwitches+F1j
//@ 		jmp	short loc_782A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2054
//@ 
//@ loc_77C3:				; CODE XREF: AnimateSwitches+C7j
//@ 		cmp	al, 75h	; 'u'   ; Compare Two Operands
//@ 		jnz	short loc_77DD	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+5], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+2], 0
//@ 		jmp	short loc_782A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2055
//@ 
//@ loc_77DD:				; CODE XREF: AnimateSwitches+105j
//@ 		cmp	al, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jnz	short loc_782A	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+5], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"PS10.PAS" 2056
//@ 		cmp	byte ptr es:[di+1], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_780E	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+5]
//@ 		push	[bp+Ownr]	; int16_t
//@ 		call	StartProcess	; function far PASCAL returns void
//@ 		jmp	short loc_782A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2058
//@ 
//@ loc_780E:				; CODE XREF: AnimateSwitches+13Bj
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 2 ;	Compare	Two Operands
//@ 		jnz	short loc_782A	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jle	short loc_782A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2059
//@ 		mov	byte ptr es:[di+1], 2
//@ 		mov	word ptr es:[di+24h], 1
//@ 
//@ loc_782A:				; CODE XREF: AnimateSwitches+A0j
//@ 					; AnimateSwitches+ACj ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jz	short locret_7835 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_7744	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2061
//@ 
//@ locret_7835:				; CODE XREF: AnimateSwitches+Bj
//@ 					; AnimateSwitches+49j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ AnimateSwitches	endp
//@ 
//@ ; #line	"PS10.PAS" 2066
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MakeTeleBlow	proc near		; CODE XREF: CheckTelePorts+8Cp
//@ 					; CheckTelePorts+1A6p
//@ 
//@ var_8		= dword	ptr -8
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; int16_t
//@ y		= word ptr  4		; int16_t
//@ x		= word ptr  6		; int16_t
//@ Owner		= word ptr  8		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2067
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jg	short loc_78BA	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_7853	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7850:				; CODE XREF: MakeTeleBlow+7Fj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 2068
//@ 
//@ loc_7853:				; CODE XREF: MakeTeleBlow+15j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_78B2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2069
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 12Ch	; Compare Two Operands
//@ 		jnb	short loc_78B2	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 2071
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ ; #line	"PS10.PAS" 2072
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+1Eh]
//@ 		call	ExplodeMonster	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2073
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+0Bh], 0FFh
//@ ; #line	"PS10.PAS" 2074
//@ 
//@ loc_78B2:				; CODE XREF: MakeTeleBlow+2Fj
//@ 					; MakeTeleBlow+48j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jnz	short loc_7850	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2076
//@ 
//@ loc_78BA:				; CODE XREF: MakeTeleBlow+10j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_78C4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_78C1:				; CODE XREF: MakeTeleBlow+D0j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_78C4:				; CODE XREF: MakeTeleBlow+86j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_7905	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2077
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+x]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+y]	; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 12Ch	; Compare Two Operands
//@ 		jnb	short loc_7905	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 2079
//@ 		push	[bp+n]		; int16_t
//@ 		call	ExplodePlayer	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2080
//@ 		cmp	[bp+Owner], 0FFFFh ; int16_t
//@ 		jz	short loc_7905	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+Owner],	58h ; int16_t
//@ 		inc	byte ptr [di-0FB0h] ; Increment	by 1
//@ ; #line	"PS10.PAS" 2081
//@ 
//@ loc_7905:				; CODE XREF: MakeTeleBlow+9Aj
//@ 					; MakeTeleBlow+B4j ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_78C1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2082
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ MakeTeleBlow	endp
//@ 
//@ ; #line	"PS10.PAS" 2087
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CheckTelePorts	proc near		; CODE XREF: DoGame:loc_DBC7p
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= word ptr -0Ah
//@ tmp		= byte ptr -8		; int16_t
//@ t		= word ptr -6		; int16_t
//@ zc		= byte ptr -4		; int16_t
//@ z		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2088
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_791E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_791A:				; CODE XREF: CheckTelePorts+113j
//@ 		inc	j		; uint16_t
//@ 
//@ loc_791E:				; CODE XREF: CheckTelePorts+9j
//@ 		imul	di, j, 58h	; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_E+2], di
//@ 		mov	[bp+var_A], es
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_7939	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_7A1B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2090
//@ 
//@ loc_7939:				; CODE XREF: CheckTelePorts+25j
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, TeleMap	; uint8_t*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+t],	ax	; int16_t
//@ ; #line	"PS10.PAS" 2091
//@ 		cmp	[bp+t],	0FFh	; int16_t
//@ 		jnz	short loc_7964	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_7A06	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2092
//@ 
//@ loc_7964:				; CODE XREF: CheckTelePorts+50j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 400h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_7975	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7A06	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2094
//@ 
//@ loc_7975:				; CODE XREF: CheckTelePorts+61j
//@ 		add	word ptr es:[di+2Ah], 400h ; Add
//@ ; #line	"PS10.PAS" 2095
//@ 		push	j		; uint16_t
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		push	word ptr es:[di+4]
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		push	word ptr es:[di+6]
//@ 		call	MakeTeleBlow	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2096
//@ 		push	[bp+t]		; int16_t
//@ 		push	j		; uint16_t
//@ 		call	MakeTeleEffect	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2097
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4]
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"PS10.PAS" 2098
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+6]
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"PS10.PAS" 2099
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+16h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ ; #line	"PS10.PAS" 2100
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	4Eh ; 'N'
//@ 		add	di, 0Eh		; Add
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+tmp]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetLandHeight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2102
//@ 
//@ loc_7A06:				; CODE XREF: CheckTelePorts+52j
//@ 					; CheckTelePorts+63j
//@ 		cmp	[bp+t],	0FFh	; int16_t
//@ 		jnz	short loc_7A1B	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 0FBFFh	; Logical AND
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"PS10.PAS" 2103
//@ 
//@ loc_7A1B:				; CODE XREF: CheckTelePorts+27j
//@ 					; CheckTelePorts+FCj
//@ 		cmp	j, 7		; uint16_t
//@ 		jz	short loc_7A25	; Jump if Zero (ZF=1)
//@ 		jmp	loc_791A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2105
//@ 
//@ loc_7A25:				; CODE XREF: CheckTelePorts+111j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jbe	short loc_7A36	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_7B94	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7A36:				; CODE XREF: CheckTelePorts+122j
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_7A3F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7A3B:				; CODE XREF: CheckTelePorts+282j
//@ 		inc	j		; uint16_t
//@ 
//@ loc_7A3F:				; CODE XREF: CheckTelePorts+12Aj
//@ 		imul	di, j, 28h	; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"PS10.PAS" 2107
//@ 		mov	al, es:[di+3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+1]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, TeleMap	; uint8_t*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+t],	ax	; int16_t
//@ ; #line	"PS10.PAS" 2108
//@ 		cmp	[bp+t],	0FFh	; int16_t
//@ 		jnz	short loc_7A7B	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_7B7A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7A7B:				; CODE XREF: CheckTelePorts+167j
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+27h], 0	; Compare Two Operands
//@ 		jz	short loc_7A88	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7B7A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2110
//@ 
//@ loc_7A88:				; CODE XREF: CheckTelePorts+174j
//@ 		mov	byte ptr es:[di+27h], 1
//@ ; #line	"PS10.PAS" 2111
//@ 		push	[bp+t]		; int16_t
//@ 		push	0FFFFh
//@ 		call	MakeTeleEffect	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2112
//@ 		push	0FFFFh
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		push	word ptr es:[di+4]
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		push	word ptr es:[di+6]
//@ 		call	MakeTeleBlow	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2113
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4]
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"PS10.PAS" 2114
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+6]
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ ; #line	"PS10.PAS" 2115
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		cmp	word ptr es:[di+8], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_7B0A	; Jump if Zero (ZF=1)
//@ 		imul	ax, [bp+t], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ ; #line	"PS10.PAS" 2116
//@ 
//@ loc_7B0A:				; CODE XREF: CheckTelePorts+1E1j
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		push	word ptr [di+7FB6h]
//@ 		lea	di, [bp+z]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+zc]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetMFloorZ	; function far PASCAL returns void
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"PS10.PAS" 2117
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"PS10.PAS" 2118
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	dx, [di+7FBEh]
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		add	ax, dx		; Add
//@ 		mov	es:[di+20h], ax
//@ ; #line	"PS10.PAS" 2119
//@ 		cmp	byte ptr es:[di+0Ah], 78h ; 'x' ; Compare Two Operands
//@ 		jnz	short loc_7B7A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2121
//@ 		mov	word ptr es:[di+8], 0Eh
//@ ; #line	"PS10.PAS" 2122
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"PS10.PAS" 2123
//@ 		mov	byte ptr es:[di+26h], 0
//@ ; #line	"PS10.PAS" 2126
//@ 
//@ loc_7B7A:				; CODE XREF: CheckTelePorts+169j
//@ 					; CheckTelePorts+176j ...
//@ 		cmp	[bp+t],	0FFh	; int16_t
//@ 		jnz	short loc_7B89	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+27h], 0
//@ ; #line	"PS10.PAS" 2127
//@ 
//@ loc_7B89:				; CODE XREF: CheckTelePorts+270j
//@ 		mov	ax, j		; uint16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jz	short locret_7B94 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_7A3B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2128
//@ 
//@ locret_7B94:				; CODE XREF: CheckTelePorts+124j
//@ 					; CheckTelePorts+280j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CheckTelePorts	endp
//@ 
//@ ; #line	"PS10.PAS" 2132
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CheckFloorLinks	proc near		; CODE XREF: DoGame+10A8p
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= dword	ptr -0Ah
//@ var_6		= word ptr -6
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2134
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_7BA5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7BA1:				; CODE XREF: CheckFloorLinks+341j
//@ 		inc	j		; uint16_t
//@ 
//@ loc_7BA5:				; CODE XREF: CheckFloorLinks+9j
//@ 		imul	di, j, 58h	; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_7BC0	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_7ED0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2136
//@ 
//@ loc_7BC0:				; CODE XREF: CheckFloorLinks+25j
//@ 		cmp	LinksCount, 0	; int16_t
//@ 		jg	short loc_7BCA	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_7C93	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2137
//@ 
//@ loc_7BCA:				; CODE XREF: CheckFloorLinks+2Fj
//@ 		mov	ax, LinksCount	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_6], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jle	short loc_7BDB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_7C93	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7BDB:				; CODE XREF: CheckFloorLinks+40j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_7BE4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7BE0:				; CODE XREF: CheckFloorLinks+FAj
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 2138
//@ 
//@ loc_7BE4:				; CODE XREF: CheckFloorLinks+48j
//@ 		imul	ax, n$0, 7	; int16_t
//@ 		les	di, PLinks	; TLinksList$Element*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"PS10.PAS" 2139
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+1]	; Compare Two Operands
//@ 		jz	short loc_7C0A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7C88	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7C0A:				; CODE XREF: CheckFloorLinks+6Fj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+3]	; Compare Two Operands
//@ 		jnz	short loc_7C88	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2140
//@ 		mov	al, es:[di]
//@ ; #line	"PS10.PAS" 2141
//@ 		cmp	al, 66h	; 'f'   ; Compare Two Operands
//@ 		jnz	short loc_7C32	; Jump if Not Zero (ZF=0)
//@ 		push	word ptr es:[di+5]
//@ 		push	j		; uint16_t
//@ 		call	StartProcess	; function far PASCAL returns void
//@ 		jmp	short loc_7C88	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2142
//@ 
//@ loc_7C32:				; CODE XREF: CheckFloorLinks+8Bj
//@ 		cmp	al, 75h	; 'u'   ; Compare Two Operands
//@ 		jnz	short loc_7C4C	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+5], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+2], 0
//@ 		jmp	short loc_7C88	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2143
//@ 
//@ loc_7C4C:				; CODE XREF: CheckFloorLinks+9Ej
//@ 		cmp	al, 52h	; 'R'   ; Compare Two Operands
//@ 		jnz	short loc_7C88	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+5], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"PS10.PAS" 2144
//@ 		cmp	byte ptr es:[di+1], 3 ;	Compare	Two Operands
//@ 		jz	short loc_7C7A	; Jump if Zero (ZF=1)
//@ 		cmp	byte ptr es:[di+1], 2 ;	Compare	Two Operands
//@ 		jnz	short loc_7C88	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jle	short loc_7C88	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2145
//@ 
//@ loc_7C7A:				; CODE XREF: CheckFloorLinks+D4j
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+1], 2
//@ 		mov	word ptr es:[di+24h], 1
//@ 
//@ loc_7C88:				; CODE XREF: CheckFloorLinks+71j
//@ 					; CheckFloorLinks+84j ...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jz	short loc_7C93	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7BE0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2148
//@ 
//@ loc_7C93:				; CODE XREF: CheckFloorLinks+31j
//@ 					; CheckFloorLinks+42j ...
//@ 		mov	ax, AmCount	; uint16_t
//@ 		mov	[bp+var_6], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jle	short loc_7CA4	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_7ED0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7CA4:				; CODE XREF: CheckFloorLinks+109j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_7CAD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7CA9:				; CODE XREF: CheckFloorLinks+337j
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 2149
//@ 
//@ loc_7CAD:				; CODE XREF: CheckFloorLinks+111j
//@ 		imul	ax, n$0, 1Fh	; int16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"PS10.PAS" 2150
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 0A0h ; ' '  ; Compare Two Operands
//@ 		jl	short loc_7CDC	; Jump if Less (SF!=OF)
//@ 		jmp	loc_7EC5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7CDC:				; CODE XREF: CheckFloorLinks+141j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 0A0h ; ' '  ; Compare Two Operands
//@ 		jl	short loc_7CF7	; Jump if Less (SF!=OF)
//@ 		jmp	loc_7EC5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2151
//@ 
//@ loc_7CF7:				; CODE XREF: CheckFloorLinks+15Cj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 18h		; Add
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jg	short loc_7D0D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_7EC5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7D0D:				; CODE XREF: CheckFloorLinks+172j
//@ 		mov	ax, es:[di+8]
//@ 		add	ax, 0Ah		; Add
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+0Eh]	; Compare Two Operands
//@ 		jg	short loc_7D20	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_7EC5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2153
//@ 
//@ loc_7D20:				; CODE XREF: CheckFloorLinks+185j
//@ 		cmp	word ptr es:[di+28h], 64h ; 'd' ; Compare Two Operands
//@ 		jge	short loc_7D42	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Bh]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+28h], ax	; Add
//@ 		cmp	word ptr es:[di+28h], 64h ; 'd' ; Compare Two Operands
//@ 		jle	short loc_7D42	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+28h], 64h ; 'd'
//@ ; #line	"PS10.PAS" 2154
//@ 
//@ loc_7D42:				; CODE XREF: CheckFloorLinks+18Fj
//@ 					; CheckFloorLinks+1A4j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Dh]
//@ 		add	w, ax		; uint16_t
//@ 		cmp	w, 0C8h	; 'È'   ; uint16_t
//@ 		jbe	short loc_7D67	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	w, 0C8h	; 'È'   ; uint16_t
//@ 
//@ loc_7D67:				; CODE XREF: CheckFloorLinks+1C9j
//@ 		mov	al, byte ptr w	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+27h], al
//@ ; #line	"PS10.PAS" 2155
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+19h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+4Eh], ax	; Add
//@ 		cmp	word ptr es:[di+4Eh], 78h ; 'x' ; Compare Two Operands
//@ 		jle	short loc_7D8C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+4Eh], 78h ; 'x'
//@ ; #line	"PS10.PAS" 2159
//@ 
//@ loc_7D8C:				; CODE XREF: CheckFloorLinks+1EEj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+25h]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		or	al, es:[di+10h]	; Logical Inclusive OR
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+25h], al
//@ ; #line	"PS10.PAS" 2160
//@ 		mov	ax, es:[di+2Ah]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		or	ax, es:[di+0Eh]	; Logical Inclusive OR
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"PS10.PAS" 2162
//@ 		mov	ax, MyNetN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, j		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_7E17	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnz	short loc_7E17	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+10h], 0	; Compare Two Operands
//@ 		jbe	short loc_7E17	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 2163
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_7DDD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7DD9:				; CODE XREF: CheckFloorLinks+27Fj
//@ 		inc	i		; int16_t
//@ ; #line	"PS10.PAS" 2164
//@ 
//@ loc_7DDD:				; CODE XREF: CheckFloorLinks+241j
//@ 		mov	ax, 1
//@ 		mov	cx, i		; int16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+10h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jle	short loc_7E10	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2165
//@ 		mov	ax, i		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, j, 58h	; uint16_t
//@ 		cmp	ax, [di-0F8Eh]	; Compare Two Operands
//@ 		jle	short loc_7E10	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, i		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	SetWeapon	; function far PASCAL returns void
//@ 
//@ loc_7E10:				; CODE XREF: CheckFloorLinks+25Fj
//@ 					; CheckFloorLinks+26Ej
//@ 		cmp	i, 7		; int16_t
//@ 		jnz	short loc_7DD9	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2167
//@ 
//@ loc_7E17:				; CODE XREF: CheckFloorLinks+22Cj
//@ 					; CheckFloorLinks+230j	...
//@ 		mov	w, 1		; uint16_t
//@ 		jmp	short loc_7E23	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7E1F:				; CODE XREF: CheckFloorLinks+2AEj
//@ 		inc	w		; uint16_t
//@ 
//@ loc_7E23:				; CODE XREF: CheckFloorLinks+287j
//@ 		push	j		; uint16_t
//@ 		push	w		; uint16_t
//@ 		mov	ax, w		; uint16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+10h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	AddAmmoToPlayer	; function far PASCAL returns void
//@ 		cmp	w, 8		; uint16_t
//@ 		jnz	short loc_7E1F	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2169
//@ 		mov	ax, MyNetN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, j		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_7E61	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnz	short loc_7E61	; Jump if Not Zero (ZF=0)
//@ 		mov	GShadeDir, 1	; int16_t
//@ ; #line	"PS10.PAS" 2170
//@ 
//@ loc_7E61:				; CODE XREF: CheckFloorLinks+2BFj
//@ 					; CheckFloorLinks+2C3j
//@ 		push	44h ; 'D'
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2171
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	3Ch ; '<'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2172
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Fh		; Signed Multiply
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, n$0, 1Fh	; int16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 3Fh	; '?'
//@ 		sub	ax, n$0		; int16_t
//@ 		imul	ax, 1Fh		; Signed Multiply
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"PS10.PAS" 2173
//@ 		dec	AmCount		; uint16_t
//@ ; #line	"PS10.PAS" 2174
//@ 		jmp	short loc_7ED0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2175
//@ 
//@ loc_7EC5:				; CODE XREF: CheckFloorLinks+143j
//@ 					; CheckFloorLinks+15Ej	...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jz	short loc_7ED0	; Jump if Zero (ZF=1)
//@ 		jmp	loc_7CA9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2176
//@ 
//@ loc_7ED0:				; CODE XREF: CheckFloorLinks+27j
//@ 					; CheckFloorLinks+10Bj	...
//@ 		cmp	j, 7		; uint16_t
//@ 		jz	short locret_7EDA ; Jump if Zero (ZF=1)
//@ 		jmp	loc_7BA1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2177
//@ 
//@ locret_7EDA:				; CODE XREF: CheckFloorLinks+33Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CheckFloorLinks	endp
//@ 
//@ ; #line	"PS10.PAS" 2201
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DeinitMonitor	proc near		; CODE XREF: DoGame+19C8p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 2202
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_7EE8	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_7EFD ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2203
//@ 
//@ loc_7EE8:				; CODE XREF: DeinitMonitor+8j
//@ 		mov	ax, ServerSaved.VMode ;	struct ServerSaved$Type
//@ 		mov	CurVideoMode, ax ; uint16_t
//@ ; #line	"PS10.PAS" 2204
//@ 		call	AllocVideo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2205
//@ 		call	SetVideoMode	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2206
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2207
//@ 
//@ locret_7EFD:				; CODE XREF: DeinitMonitor+Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DeinitMonitor	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aServerReturned	db 24,'SERVER returned to game.' ; DATA XREF: SwitchMonitor+50o
//@ ; #line	"PS10.PAS" 2211
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SwitchMonitor	proc near		; CODE XREF: ProcessConsole+267p
//@ 					; ProcessMenu+514p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 2212
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2213
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_7F2E	; Jump if Zero (ZF=1)
//@ 		call	InitVESAMonitor	; function far PASCAL returns void
//@ 		jmp	short loc_7F72	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2218
//@ 
//@ loc_7F2E:				; CODE XREF: SwitchMonitor+Dj
//@ 		mov	ax, ServerSaved.VMode ;	struct ServerSaved$Type
//@ 		mov	CurVideoMode, ax ; uint16_t
//@ ; #line	"PS10.PAS" 2219
//@ 		mov	ax, ServerSaved.svhx ; struct ServerSaved$Type
//@ 		mov	Players.PlHx, ax ; struct TPlayerInfo[8]
//@ ; #line	"PS10.PAS" 2220
//@ 		mov	ax, ServerSaved.svhy ; struct ServerSaved$Type
//@ 		mov	Players.PlHy, ax ; struct TPlayerInfo[8]
//@ ; #line	"PS10.PAS" 2221
//@ 		mov	ax, ServerSaved.svhz ; struct ServerSaved$Type
//@ 		mov	Players.Plhz0, ax ; struct TPlayerInfo[8]
//@ ; #line	"PS10.PAS" 2222
//@ 		push	Players.PlHx	; struct TPlayerInfo[8]
//@ 		push	Players.PlHy	; struct TPlayerInfo[8]
//@ 		push	6
//@ 		push	1Ah
//@ 		push	60h ; '`'
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2224
//@ 		call	AllocVideo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2225
//@ 		call	SetVideoMode	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2226
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2227
//@ 		mov	di, offset aServerReturned ; "SERVER returned to game."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2229
//@ 
//@ loc_7F72:				; CODE XREF: SwitchMonitor+14j
//@ 		call	SetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2230
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurOwner, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2231
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ SwitchMonitor	endp
//@ 
//@ ; #line	"PS10.PAS" 2235
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReInitOwners	proc near		; CODE XREF: PROGRAM+D06p
//@ 
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2236
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurOwner, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2237
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_7F91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7F8E:				; CODE XREF: ReInitOwners+22j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_7F91:				; CODE XREF: ReInitOwners+Ej
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	[di-0AC0h], al
//@ 		cmp	[bp+n],	3	; int16_t
//@ 		jnz	short loc_7F8E	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2238
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ReInitOwners	endp
//@ 
//@ ; #line	"PS10.PAS" 2245
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InsertPlayers	proc near		; CODE XREF: DoGame:loc_D99Fp
//@ 
//@ n		= word ptr -0Eh		; int16_t
//@ l		= byte ptr -0Ch		; struct TLoc
//@ var_B		= byte ptr -0Bh
//@ var_9		= word ptr -9
//@ var_7		= word ptr -7
//@ var_5		= word ptr -5
//@ var_3		= word ptr -3
//@ 
//@ 		enter	12h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2246
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_7FB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_7FAF:				; CODE XREF: InsertPlayers+79j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 2247
//@ 
//@ loc_7FB2:				; CODE XREF: InsertPlayers+9j
//@ 		cmp	ExMode,	0	; bool
//@ 		jnz	short loc_7FCE	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, CurOwner	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_7FCE	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_8019	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2248
//@ 
//@ loc_7FCE:				; CODE XREF: InsertPlayers+13j
//@ 					; InsertPlayers+24j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_8019	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_8019	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2251
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	[bp+var_9], ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	[bp+var_7], ax
//@ 		mov	ax, [bp+var_9]
//@ 		mov	[bp+var_5], ax
//@ 		mov	ax, [bp+var_7]
//@ 		mov	[bp+var_3], ax
//@ ; #line	"PS10.PAS" 2253
//@ 		mov	[bp+l],	81h ; '' ; struct TLoc
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+var_B], al
//@ ; #line	"PS10.PAS" 2254
//@ 		lea	di, [bp+l]	; struct TLoc
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	InsertObject	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2255
//@ 
//@ loc_8019:				; CODE XREF: InsertPlayers+28j
//@ 					; InsertPlayers+38j ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_7FAF	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2256
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ InsertPlayers	endp
//@ 
//@ ; #line	"PS10.PAS" 2260
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ NewGame		proc near		; CODE XREF: ExecConsole+256p
//@ 					; ProcessMenu+430p ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 2261
//@ 		mov	MenuCode, 3	; uint16_t
//@ ; #line	"PS10.PAS" 2262
//@ 		push	20h ; ' '
//@ 		call	SendServerPost	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2263
//@ 		mov	SERVER,	0	; bool
//@ ; #line	"PS10.PAS" 2264
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"PS10.PAS" 2265
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"PS10.PAS" 2266
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 2267
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ NewGame		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aIpxNotInstalle	db 18,'IPX not installed.' ; DATA XREF: MenuStartNet+11o
//@ aClientCannotCh	db 35,'CLIENT CANNOT CHANGE GAME SETTINGS.'
//@ 					; DATA XREF: MenuStartNet:loc_8117o
//@ aNpNotInstalled	db 17,'NP not installed.' ; DATA XREF: MenuStartNet:loc_8123o
//@ ; #line	"PS10.PAS" 2270
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MenuStartNet	proc near		; CODE XREF: ProcessMenu+6DCp
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 2272
//@ 		cmp	NGCard,	0	; uint8_t
//@ 		jnz	short loc_80AC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2273
//@ 		cmp	IPXPresent, 0	; bool
//@ 		jnz	short loc_80AC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2274
//@ 		mov	di, offset aIpxNotInstalle ; "IPX not installed."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	locret_812D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2277
//@ 
//@ loc_80AC:				; CODE XREF: MenuStartNet+8j
//@ 					; MenuStartNet+Fj
//@ 		cmp	NPinst,	0	; bool
//@ 		jz	short loc_8123	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2278
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_8117	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2280
//@ 		mov	al, NGSkill	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"PS10.PAS" 2281
//@ 		mov	al, NGLevel	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"PS10.PAS" 2282
//@ 		mov	al, NGMode	; uint8_t
//@ 		mov	NetMode, al	; uint8_t
//@ ; #line	"PS10.PAS" 2283
//@ 		mov	al, NGTeam	; uint8_t
//@ 		mov	TeamMode, al	; uint8_t
//@ ; #line	"PS10.PAS" 2285
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 2286
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_80EA	; Jump if Zero (ZF=1)
//@ 		push	10h
//@ 		call	SendServerPost	; function near	PASCAL returns void
//@ 		jmp	short loc_8106	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2287
//@ 
//@ loc_80EA:				; CODE XREF: MenuStartNet+53j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_80F5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_80F1:				; CODE XREF: MenuStartNet+76j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_80F5:				; CODE XREF: MenuStartNet+61j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	byte ptr [di-0FB0h], 0
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_80F1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2288
//@ 
//@ loc_8106:				; CODE XREF: MenuStartNet+5Aj
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"PS10.PAS" 2289
//@ 		mov	SERVER,	1	; bool
//@ ; #line	"PS10.PAS" 2290
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 2291
//@ 		jmp	short loc_8121	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2292
//@ 
//@ loc_8117:				; CODE XREF: MenuStartNet+2Aj
//@ 		mov	di, offset aClientCannotCh ; "CLIENT CANNOT CHANGE GAME	SETTINGS."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 
//@ loc_8121:				; CODE XREF: MenuStartNet+87j
//@ 		jmp	short locret_812D ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2293
//@ 
//@ loc_8123:				; CODE XREF: MenuStartNet+23j
//@ 		mov	di, offset aNpNotInstalled ; "NP not installed."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2294
//@ 
//@ locret_812D:				; CODE XREF: MenuStartNet+1Bj
//@ 					; MenuStartNet:loc_8121j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ MenuStartNet	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aIpxNotInstal_0	db 18,'IPX not installed.' ; DATA XREF: MenuJoinNet+11o
//@ aNpNotInstall_0	db 17,'NP not installed.' ; DATA XREF: MenuJoinNet:loc_819Fo
//@ aAlreadyInNetwo	db 19,'Already in Network.' ; DATA XREF: MenuJoinNet:loc_81ABo
//@ ; #line	"PS10.PAS" 2297
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MenuJoinNet	proc near		; CODE XREF: ProcessMenu+6EDp
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 2298
//@ 		cmp	NGCard,	0	; uint8_t
//@ 		jnz	short loc_8185	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2299
//@ 		cmp	IPXPresent, 0	; bool
//@ 		jnz	short loc_8185	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2300
//@ 		mov	di, offset aIpxNotInstal_0 ; "IPX not installed."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	short locret_81B5 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2302
//@ 
//@ loc_8185:				; CODE XREF: MenuJoinNet+8j
//@ 					; MenuJoinNet+Fj
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_81AB	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_81AB	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2303
//@ 		cmp	NPinst,	0	; bool
//@ 		jz	short loc_819F	; Jump if Zero (ZF=1)
//@ 		call	LookForServer	; function near	PASCAL returns void
//@ 		jmp	short loc_81A9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2304
//@ 
//@ loc_819F:				; CODE XREF: MenuJoinNet+30j
//@ 		mov	di, offset aNpNotInstall_0 ; "NP not installed."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 
//@ loc_81A9:				; CODE XREF: MenuJoinNet+35j
//@ 		jmp	short locret_81B5 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2305
//@ 
//@ loc_81AB:				; CODE XREF: MenuJoinNet+22j
//@ 					; MenuJoinNet+29j
//@ 		mov	di, offset aAlreadyInNetwo ; "Already in Network."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2306
//@ 
//@ locret_81B5:				; CODE XREF: MenuJoinNet+1Bj
//@ 					; MenuJoinNet:loc_81A9j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ MenuJoinNet	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_81B7	db 1,' '                ; DATA XREF: ExecConsole:loc_83FBo
//@ 					; ExecConsole+160o
//@ aUnknownCommand	db 15,'Unknown command' ; DATA XREF: ExecConsole+224o
//@ a__2		db 1,'.'                ; DATA XREF: ExecConsole+2CAo
//@ aIncorrectLevel	db 23,'Incorrect level number.' ; DATA XREF: ExecConsole:loc_8604o
//@ asc_81E3	db 1,'#'                ; DATA XREF: ExecConsole+345o
//@ 					; ExecConsole+384o
//@ aShadows_count	db 16,'SHADOWS_COUNT = ' ; DATA XREF: ExecConsole+335o
//@ 					; ExecConsole+374o
//@ aMustBeIn0__7	db 15,'Must be in 0..7' ; DATA XREF: ExecConsole:loc_86B8o
//@ asc_8206	db 3,'###'              ; DATA XREF: ExecConsole+3ECo
//@ 					; ExecConsole+441o
//@ aRespawn_time	db 14,'RESPAWN_TIME ='  ; DATA XREF: ExecConsole+3DCo
//@ 					; ExecConsole+431o
//@ aSec__0		db 5,' SEC.'            ; DATA XREF: ExecConsole+408o
//@ 					; ExecConsole+45Do
//@ aRespawnDisable	db 16,'RESPAWN DISABLED' ; DATA XREF: ExecConsole:loc_872Ao
//@ aMustBeIn0__600	db 17,'Must be in 0..600' ; DATA XREF: ExecConsole:loc_877Fo
//@ aChojinModeIs	db 14,'CHOJIN mode is'  ; DATA XREF: ExecConsole+49Ao
//@ aReverseSoundIs	db 16,'REVERSE SOUND is' ; DATA XREF: ExecConsole+4F3o
//@ asc_8262	db 4,'####'             ; DATA XREF: ExecConsole+585o
//@ aDepth		db 7,'DEPTH ='          ; DATA XREF: ExecConsole+575o
//@ aAmmoAddedTo	db 14,'AMMO added to '  ; DATA XREF: ExecConsole+618o
//@ aArmorAddedTo	db 15,'ARMOR added to ' ; DATA XREF: ExecConsole+679o
//@ aSet		db 4,'Set '             ; DATA XREF: ExecConsole+6DBo
//@ aInvisible	db 10,' invisible'      ; DATA XREF: ExecConsole+6F4o
//@ aGive		db 5,'Give '            ; DATA XREF: ExecConsole+750o
//@ aAllKeys_	db 10,' all keys.'      ; DATA XREF: ExecConsole+769o
//@ aWeaponsAddedTo	db 17,'WEAPONS added to ' ; DATA XREF: ExecConsole+817o
//@ aFullMapIs	db 11,'FULL MAP is'     ; DATA XREF: ExecConsole+8C7o
//@ asc_82CD	db 2,'##'               ; DATA XREF: ExecConsole+911o
//@ 					; ExecConsole+99Ao
//@ aTime		db 5,'Time:'            ; DATA XREF: ExecConsole+901o
//@ asc_82D6	db 1,':'                ; DATA XREF: ExecConsole+939o
//@ 					; ExecConsole+9C2o
//@ a@_1		db 2,'@#'               ; DATA XREF: ExecConsole+949o
//@ 					; ExecConsole+9D2o
//@ aCdtime		db 7,'CDTime:'          ; DATA XREF: ExecConsole+98Ao
//@ asc_82E3	db 5,'#####'            ; DATA XREF: ExecConsole+A23o
//@ 					; ExecConsole+A59o
//@ aMem		db 4,'Mem:'             ; DATA XREF: ExecConsole+A13o
//@ asc_82EE	db 1,'/'                ; DATA XREF: ExecConsole+A49o
//@ asc_82F0	db 1,'"'                ; DATA XREF: ExecConsole+AB3o
//@ 					; ExecConsole+ADBo
//@ aNowIs_0	db 10,'" now is "'      ; DATA XREF: ExecConsole+AC7o
//@ aCurrentNick	db 14,'Current Nick: '  ; DATA XREF: ExecConsole+AF2o
//@ asc_830C	db 1,'['                ; DATA XREF: ExecConsole+CADo
//@ asc_830E	db 2,'] '               ; DATA XREF: ExecConsole+CCEo
//@ ; #line	"PS10.PAS" 2315
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExecConsole	proc near		; CODE XREF: ProcessConsole+399p
//@ 
//@ var_350		= byte ptr -350h
//@ var_254		= byte ptr -254h
//@ var_250		= byte ptr -250h
//@ var_154		= byte ptr -154h
//@ var_150		= byte ptr -150h
//@ var_56		= dword	ptr -56h
//@ var_52		= word ptr -52h
//@ sp2		= byte ptr -50h		; char[21] // Pascal string
//@ var_3A		= byte ptr -3Ah		; char[21] // Pascal string
//@ S		= byte ptr -24h		; char[21] // Pascal string
//@ argint2		= word ptr -0Eh		; int16_t
//@ argint		= word ptr -0Ch		; int16_t
//@ ComID		= word ptr -0Ah		; int16_t
//@ x		= word ptr -6		; uint16_t
//@ n		= word ptr -4		; uint16_t
//@ i		= word ptr -2		; uint16_t
//@ 
//@ 		enter	350h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2316
//@ 		mov	[bp+i],	1	; uint16_t
//@ 		jmp	short loc_831F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_831C:				; CODE XREF: ExecConsole+30j
//@ 		inc	[bp+i]		; uint16_t
//@ 
//@ loc_831F:				; CODE XREF: ExecConsole+9j
//@ 		imul	di, [bp+i], 29h	; uint16_t
//@ 		add	di, 0E6EEh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+i]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	di, ax,	29h	; Signed Multiply
//@ 		add	di, 0E6EEh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		cmp	[bp+i],	6	; uint16_t
//@ 		jnz	short loc_831C	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2317
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StUpcase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2319
//@ 		imul	ax, HistCnt, 28h ; int16_t
//@ 		les	di, ConsHistory	; char*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFD8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_83F4	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2321
//@ 		cmp	HistCnt, 40h ; '@' ; int16_t
//@ 		jge	short loc_8394	; Jump if Greater or Equal (SF=OF)
//@ 		inc	HistCnt		; int16_t
//@ 		jmp	short loc_83CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2322
//@ 
//@ loc_8394:				; CODE XREF: ExecConsole+7Bj
//@ 		mov	[bp+n],	1	; uint16_t
//@ 		jmp	short loc_839E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_839B:				; CODE XREF: ExecConsole+BBj
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_839E:				; CODE XREF: ExecConsole+88j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 28h		; Signed Multiply
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFD8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, [bp+n], 28h	; uint16_t
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFD8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		cmp	[bp+n],	3Fh ; '?' ; uint16_t
//@ 		jnz	short loc_839B	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2323
//@ 
//@ loc_83CE:				; CODE XREF: ExecConsole+81j
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		imul	ax, HistCnt, 28h ; int16_t
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFD8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	ax, HistCnt	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	CurHist, ax	; int16_t
//@ ; #line	"PS10.PAS" 2324
//@ 		jmp	short loc_83FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_83F4:				; CODE XREF: ExecConsole+74j
//@ 		mov	ax, HistCnt	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	CurHist, ax	; int16_t
//@ ; #line	"PS10.PAS" 2326
//@ 
//@ loc_83FB:				; CODE XREF: ExecConsole+E1j
//@ 		mov	di, offset asc_81B7 ; "	"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		mov	[bp+var_3A], 0	; char[21] // Pascal string
//@ 		mov	[bp+sp2], 0	; char[21] // Pascal string
//@ 		mov	[bp+argint], 0FFFFh ; int16_t
//@ ; #line	"PS10.PAS" 2327
//@ 		cmp	[bp+x],	0	; uint16_t
//@ 		jnz	short loc_8423	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_84FE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2329
//@ 
//@ loc_8423:				; CODE XREF: ExecConsole+10Dj
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	[bp+x]		; uint16_t
//@ 		push	64h ; 'd'
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+var_3A]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2330
//@ 		mov	al, byte ptr [bp+x] ; uint16_t
//@ 		mov	[bp+S],	al	; char[21] // Pascal string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2331
//@ 		mov	di, offset asc_81B7 ; "	"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+var_3A]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+x],	ax	; uint16_t
//@ ; #line	"PS10.PAS" 2332
//@ 		cmp	[bp+x],	0	; uint16_t
//@ 		jnz	short loc_849D	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_3A]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+i]	; uint16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+argint], ax	; int16_t
//@ 		jmp	short loc_84FE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2334
//@ 
//@ loc_849D:				; CODE XREF: ExecConsole+176j
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_3A]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	[bp+x]		; uint16_t
//@ 		push	64h ; 'd'
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+sp2]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2335
//@ 		mov	al, byte ptr [bp+x] ; uint16_t
//@ 		mov	[bp+var_3A], al	; char[21] // Pascal string
//@ ; #line	"PS10.PAS" 2336
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_3A]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+i]	; uint16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2337
//@ 		lea	di, [bp+sp2]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+i]	; uint16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+argint2], ax ; int16_t
//@ ; #line	"PS10.PAS" 2343
//@ 
//@ loc_84FE:				; CODE XREF: ExecConsole+10Fj
//@ 					; ExecConsole+18Aj
//@ 		mov	[bp+ComID], 0FFFFh ; int16_t
//@ ; #line	"PS10.PAS" 2344
//@ 		mov	[bp+i],	1	; uint16_t
//@ 		jmp	short loc_850D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_850A:				; CODE XREF: ExecConsole+21Cj
//@ 		inc	[bp+i]		; uint16_t
//@ ; #line	"PS10.PAS" 2345
//@ 
//@ loc_850D:				; CODE XREF: ExecConsole+1F7j
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		imul	di, [bp+i], 0Dh	; uint16_t
//@ 		add	di, 27h	; '''   ; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_8529	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+i]	; uint16_t
//@ 		mov	[bp+ComID], ax	; int16_t
//@ 
//@ loc_8529:				; CODE XREF: ExecConsole+210j
//@ 		cmp	[bp+i],	2Ah ; '*' ; uint16_t
//@ 		jnz	short loc_850A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2346
//@ 		cmp	[bp+ComID], 0FFFFh ; int16_t
//@ 		jnz	short loc_8542	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aUnknownCommand ; "Unknown command"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2347
//@ 
//@ loc_8542:				; CODE XREF: ExecConsole+222j
//@ 		mov	ax, [bp+ComID]	; int16_t
//@ ; #line	"PS10.PAS" 2348
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_8562	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2349
//@ 		mov	MenuCode, 0FFFFh ; uint16_t
//@ ; #line	"PS10.PAS" 2350
//@ 		push	20h ; ' '
//@ 		call	SendServerPost	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2351
//@ 		mov	SERVER,	0	; bool
//@ ; #line	"PS10.PAS" 2352
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"PS10.PAS" 2353
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2355
//@ 
//@ loc_8562:				; CODE XREF: ExecConsole+237j
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_856D	; Jump if Not Zero (ZF=0)
//@ 		call	NewGame		; function near	PASCAL returns void
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2356
//@ 
//@ loc_856D:				; CODE XREF: ExecConsole+254j
//@ 		cmp	ax, 17h		; Compare Two Operands
//@ 		jnz	short loc_857B	; Jump if Not Zero (ZF=0)
//@ 		mov	EndDelay, 1Eh	; int16_t
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2358
//@ 
//@ loc_857B:				; CODE XREF: ExecConsole+25Fj
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_85A3	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_85A0	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_85A0	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_85A0	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2360
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 2361
//@ 		push	10h
//@ 		call	SendServerPost	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2362
//@ 
//@ loc_85A0:				; CODE XREF: ExecConsole+274j
//@ 					; ExecConsole+27Bj ...
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2363
//@ 
//@ loc_85A3:				; CODE XREF: ExecConsole+26Dj
//@ 		cmp	ax, 14h		; Compare Two Operands
//@ 		jnz	short loc_8611	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_860E	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_860E	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_860E	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2364
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jle	short loc_8604	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	[bp+argint], 40h ; '@' ; int16_t
//@ 		jg	short loc_8604	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, [bp+argint]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, LevelNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset a__2	; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_8604	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2366
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"PS10.PAS" 2367
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 2368
//@ 		mov	ax, [bp+argint]	; int16_t
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"PS10.PAS" 2369
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 2370
//@ 		push	10h
//@ 		call	SendServerPost	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2371
//@ 		jmp	short loc_860E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_8604:				; CODE XREF: ExecConsole+2B0j
//@ 					; ExecConsole+2B6j ...
//@ 		mov	di, offset aIncorrectLevel ; "Incorrect	level number."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 
//@ loc_860E:				; CODE XREF: ExecConsole+29Cj
//@ 					; ExecConsole+2A3j ...
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2373
//@ 
//@ loc_8611:				; CODE XREF: ExecConsole+295j
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jnz	short loc_8626	; Jump if Not Zero (ZF=0)
//@ 		cmp	Obj3d, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_8620	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_8620:				; CODE XREF: ExecConsole+30Cj
//@ 		mov	Obj3d, al	; bool
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2374
//@ 
//@ loc_8626:				; CODE XREF: ExecConsole+303j
//@ 		cmp	ax, 15h		; Compare Two Operands
//@ 		jz	short loc_862E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_86C5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2375
//@ 
//@ loc_862E:				; CODE XREF: ExecConsole+318j
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_8679	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 8	; int16_t
//@ 		jge	short loc_8679	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 2376
//@ 		mov	ax, [bp+argint]	; int16_t
//@ 		mov	ShadowCount, ax	; uint16_t
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aShadows_count ; "SHADOWS_COUNT = "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_81E3 ; "#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, ShadowCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 		jmp	short loc_86C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2377
//@ 
//@ loc_8679:				; CODE XREF: ExecConsole+321j
//@ 					; ExecConsole+327j
//@ 		cmp	[bp+argint], 0FFFFh ; int16_t
//@ 		jnz	short loc_86B8	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aShadows_count ; "SHADOWS_COUNT = "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_81E3 ; "#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, ShadowCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 		jmp	short loc_86C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2378
//@ 
//@ loc_86B8:				; CODE XREF: ExecConsole+36Cj
//@ 		mov	di, offset aMustBeIn0__7 ; "Must be in 0..7"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2379
//@ 
//@ loc_86C2:				; CODE XREF: ExecConsole+366j
//@ 					; ExecConsole+3A5j
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2381
//@ 
//@ loc_86C5:				; CODE XREF: ExecConsole+31Aj
//@ 		cmp	ax, 16h		; Compare Two Operands
//@ 		jz	short loc_86CD	; Jump if Zero (ZF=1)
//@ 		jmp	loc_878C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2382
//@ 
//@ loc_86CD:				; CODE XREF: ExecConsole+3B7j
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_8736	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 258h ; int16_t
//@ 		jg	short loc_8736	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"PS10.PAS" 2384
//@ 		mov	ax, [bp+argint]	; int16_t
//@ 		mov	RespawnTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2385
//@ 		cmp	RespawnTime, 0	; uint16_t
//@ 		jz	short loc_872A	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aRespawn_time ; "RESPAWN_TIME ="
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_8206 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, RespawnTime	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aSec__0 ; " SEC."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 		jmp	short loc_8734	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2386
//@ 
//@ loc_872A:				; CODE XREF: ExecConsole+3D4j
//@ 		mov	di, offset aRespawnDisable ; "RESPAWN DISABLED"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2387
//@ 
//@ loc_8734:				; CODE XREF: ExecConsole+417j
//@ 		jmp	short loc_8789	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2389
//@ 
//@ loc_8736:				; CODE XREF: ExecConsole+3C0j
//@ 					; ExecConsole+3C7j
//@ 		cmp	[bp+argint], 0FFFFh ; int16_t
//@ 		jnz	short loc_877F	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2390
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aRespawn_time ; "RESPAWN_TIME ="
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_8206 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, RespawnTime	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aSec__0 ; " SEC."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 		jmp	short loc_8789	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2391
//@ 
//@ loc_877F:				; CODE XREF: ExecConsole+429j
//@ 		mov	di, offset aMustBeIn0__600 ; "Must be in 0..600"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2392
//@ 
//@ loc_8789:				; CODE XREF: ExecConsole:loc_8734j
//@ 					; ExecConsole+46Cj
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2395
//@ 
//@ loc_878C:				; CODE XREF: ExecConsole+3B9j
//@ 		cmp	ax, 7		; Compare Two Operands
//@ 		jnz	short loc_87D7	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2396
//@ 		cmp	Players.Life, 0	; struct TPlayerInfo[8]
//@ 		jle	short loc_87D4	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2397
//@ 		cmp	Chojin,	0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_87A2	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_87A2:				; CODE XREF: ExecConsole+48Ej
//@ 		mov	Chojin,	al	; bool
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChojinModeIs ; "CHOJIN mode	is"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	al, Chojin	; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 
//@ loc_87D4:				; CODE XREF: ExecConsole+485j
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2398
//@ 
//@ loc_87D7:				; CODE XREF: ExecConsole+47Ej
//@ 		cmp	ax, 12h		; Compare Two Operands
//@ 		jnz	short loc_87EC	; Jump if Not Zero (ZF=0)
//@ 		cmp	TimeInd, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_87E6	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_87E6:				; CODE XREF: ExecConsole+4D2j
//@ 		mov	TimeInd, al	; bool
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2404
//@ 
//@ loc_87EC:				; CODE XREF: ExecConsole+4C9j
//@ 		cmp	ax, 0Fh		; Compare Two Operands
//@ 		jnz	short loc_8830	; Jump if Not Zero (ZF=0)
//@ 		cmp	Reverse, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_87FB	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_87FB:				; CODE XREF: ExecConsole+4E7j
//@ 		mov	Reverse, al	; bool
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aReverseSoundIs ; "REVERSE SOUND is"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	al, Reverse	; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2405
//@ 
//@ loc_8830:				; CODE XREF: ExecConsole+4DEj
//@ 		cmp	ax, 0Dh		; Compare Two Operands
//@ 		jnz	short loc_885E	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_52], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		ja	short loc_885B	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_884B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_8848:				; CODE XREF: ExecConsole+548j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_884B:				; CODE XREF: ExecConsole+535j
//@ 		push	[bp+n]		; uint16_t
//@ 		call	RespawnMonster	; function far PASCAL returns void
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		jnz	short loc_8848	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_885B:				; CODE XREF: ExecConsole+530j
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2406
//@ 
//@ loc_885E:				; CODE XREF: ExecConsole+522j
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jnz	short loc_88BA	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2407
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_8880	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 2409
//@ 		cmp	[bp+argint], 4B0h ; int16_t
//@ 		jle	short loc_8875	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+argint], 4B0h ; int16_t
//@ ; #line	"PS10.PAS" 2410
//@ 
//@ loc_8875:				; CODE XREF: ExecConsole+55Dj
//@ 		mov	ax, [bp+argint]	; int16_t
//@ 		mov	BLevelDef, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2411
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2413
//@ 
//@ loc_8880:				; CODE XREF: ExecConsole+556j
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aDepth ; "DEPTH ="
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_8262 ; "####"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2414
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2416
//@ 
//@ loc_88BA:				; CODE XREF: ExecConsole+550j
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jz	short loc_88C2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_894A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2418
//@ 
//@ loc_88C2:				; CODE XREF: ExecConsole+5ACj
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_88CE	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 7	; int16_t
//@ 		jle	short loc_88D3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_88CE:				; CODE XREF: ExecConsole+5B5j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2419
//@ 
//@ loc_88D3:				; CODE XREF: ExecConsole+5BBj
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jz	short loc_88E9	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_88EE	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2420
//@ 
//@ loc_88E9:				; CODE XREF: ExecConsole+5CBj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2421
//@ 
//@ loc_88EE:				; CODE XREF: ExecConsole+5D6j
//@ 		mov	ax, WeaponsCount ; uint16_t
//@ 		mov	[bp+var_52], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		ja	short loc_8923	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_8904	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_8901:				; CODE XREF: ExecConsole+610j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"PS10.PAS" 2422
//@ 
//@ loc_8904:				; CODE XREF: ExecConsole+5EEj
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	dl, [di-1BBAh]
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		add	di, ax		; Add
//@ 		mov	[di-0FA9h], dl
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		jnz	short loc_8901	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2423
//@ 
//@ loc_8923:				; CODE XREF: ExecConsole+5E9j
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aAmmoAddedTo	; "AMMO	added to "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2424
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2426
//@ 
//@ loc_894A:				; CODE XREF: ExecConsole+5AEj
//@ 		cmp	ax, 10h		; Compare Two Operands
//@ 		jnz	short loc_89AB	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2428
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_895B	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 7	; int16_t
//@ 		jle	short loc_8960	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_895B:				; CODE XREF: ExecConsole+642j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2429
//@ 
//@ loc_8960:				; CODE XREF: ExecConsole+648j
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jz	short loc_8976	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_897B	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2430
//@ 
//@ loc_8976:				; CODE XREF: ExecConsole+658j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2431
//@ 
//@ loc_897B:				; CODE XREF: ExecConsole+663j
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		mov	byte ptr [di-0FAFh], 0C8h ; 'È'
//@ ; #line	"PS10.PAS" 2432
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aArmorAddedTo ; "ARMOR added	to "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2433
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2435
//@ 
//@ loc_89AB:				; CODE XREF: ExecConsole+63Cj
//@ 		cmp	ax, 11h		; Compare Two Operands
//@ 		jnz	short loc_8A17	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2437
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_89BC	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 7	; int16_t
//@ 		jle	short loc_89C1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_89BC:				; CODE XREF: ExecConsole+6A3j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2438
//@ 
//@ loc_89C1:				; CODE XREF: ExecConsole+6A9j
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jz	short loc_89D7	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_89DC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2439
//@ 
//@ loc_89D7:				; CODE XREF: ExecConsole+6B9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2440
//@ 
//@ loc_89DC:				; CODE XREF: ExecConsole+6C4j
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		mov	word ptr [di-0F88h], 78h ; 'x'
//@ ; #line	"PS10.PAS" 2441
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSet	; "Set "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aInvisible ;	" invisible"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2442
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2444
//@ 
//@ loc_8A17:				; CODE XREF: ExecConsole+69Dj
//@ 		cmp	ax, 13h		; Compare Two Operands
//@ 		jnz	short loc_8A8C	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2445
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_8A28	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 7	; int16_t
//@ 		jle	short loc_8A2D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_8A28:				; CODE XREF: ExecConsole+70Fj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2446
//@ 
//@ loc_8A2D:				; CODE XREF: ExecConsole+715j
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jz	short loc_8A43	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_8A48	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2447
//@ 
//@ loc_8A43:				; CODE XREF: ExecConsole+725j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2448
//@ 
//@ loc_8A48:				; CODE XREF: ExecConsole+730j
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		mov	ax, [di-0FACh]
//@ 		or	ax, 70h		; Logical Inclusive OR
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		mov	[di-0FACh], ax
//@ ; #line	"PS10.PAS" 2449
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aGive ; "Give "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aAllKeys_ ; " all keys."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2450
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2457
//@ 
//@ loc_8A8C:				; CODE XREF: ExecConsole+709j
//@ 		cmp	ax, 8		; Compare Two Operands
//@ 		jz	short loc_8A94	; Jump if Zero (ZF=1)
//@ 		jmp	loc_8B49	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2459
//@ 
//@ loc_8A94:				; CODE XREF: ExecConsole+77Ej
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_8AA0	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 7	; int16_t
//@ 		jle	short loc_8AA5	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_8AA0:				; CODE XREF: ExecConsole+787j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2460
//@ 
//@ loc_8AA5:				; CODE XREF: ExecConsole+78Dj
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jz	short loc_8ABB	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_8AC0	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2461
//@ 
//@ loc_8ABB:				; CODE XREF: ExecConsole+79Dj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+argint], ax	; int16_t
//@ ; #line	"PS10.PAS" 2462
//@ 
//@ loc_8AC0:				; CODE XREF: ExecConsole+7A8j
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_56+2],	di
//@ 		mov	[bp+var_52], es
//@ ; #line	"PS10.PAS" 2463
//@ 		mov	ax, WeaponsCount ; uint16_t
//@ 		mov	word ptr [bp+var_56], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, word ptr [bp+var_56] ; Compare Two Operands
//@ 		ja	short loc_8B22	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_8AE6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_8AE3:				; CODE XREF: ExecConsole+80Fj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"PS10.PAS" 2465
//@ 
//@ loc_8AE6:				; CODE XREF: ExecConsole+7D0j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	dl, [di-1BBAh]
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		les	di, [bp+var_56+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+2Dh], dl
//@ ; #line	"PS10.PAS" 2466
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_56+2] ; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+25h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		mov	es:[di+25h], al
//@ ; #line	"PS10.PAS" 2467
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, word ptr [bp+var_56] ; Compare Two Operands
//@ 		jnz	short loc_8AE3	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2468
//@ 
//@ loc_8B22:				; CODE XREF: ExecConsole+7CBj
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aWeaponsAddedTo ; "WEAPONS added to "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2469
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2471
//@ 
//@ loc_8B49:				; CODE XREF: ExecConsole+780j
//@ 		cmp	ax, 6		; Compare Two Operands
//@ 		jnz	short loc_8BC0	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_52], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		ja	short loc_8BBD	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_8B64	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_8B61:				; CODE XREF: ExecConsole+8AAj
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_8B64:				; CODE XREF: ExecConsole+84Ej
//@ 		imul	di, [bp+n], 28h	; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_56], di
//@ 		mov	word ptr [bp+var_56+2],	es
//@ ; #line	"PS10.PAS" 2472
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_8BB5	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2473
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		cmp	al, 9		; Compare Two Operands
//@ 		jz	short loc_8BB5	; Jump if Zero (ZF=1)
//@ 		cmp	al, 12h		; Compare Two Operands
//@ 		jb	short loc_8B90	; Jump if Below	(CF=1)
//@ 		cmp	al, 14h		; Compare Two Operands
//@ 		jbe	short loc_8BB5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 2475
//@ 
//@ loc_8B90:				; CODE XREF: ExecConsole+879j
//@ 		les	di, [bp+var_56]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		mov	byte ptr es:[di+26h], 5
//@ ; #line	"PS10.PAS" 2476
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"PS10.PAS" 2477
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		mov	byte ptr es:[di+24h], 0Ah
//@ ; #line	"PS10.PAS" 2478
//@ 
//@ loc_8BB5:				; CODE XREF: ExecConsole+868j
//@ 					; ExecConsole+875j ...
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		jnz	short loc_8B61	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_8BBD:				; CODE XREF: ExecConsole+849j
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2479
//@ 
//@ loc_8BC0:				; CODE XREF: ExecConsole+83Bj
//@ 		cmp	ax, 5		; Compare Two Operands
//@ 		jnz	short loc_8C04	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2480
//@ 		cmp	FullMap, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_8BCF	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_8BCF:				; CODE XREF: ExecConsole+8BBj
//@ 		mov	FullMap, al	; bool
//@ ; #line	"PS10.PAS" 2481
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aFullMapIs ;	"FULL MAP is"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	al, FullMap	; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2482
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2484
//@ 
//@ loc_8C04:				; CODE XREF: ExecConsole+8B2j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jz	short loc_8C0C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_8D98	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2485
//@ 
//@ loc_8C0C:				; CODE XREF: ExecConsole+8F6j
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTime ; "Time:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_82CD ; "##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 20D0h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_82D6 ; ":"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_350] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_1	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 8Ch	; 'Œ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, 3Ch	; '<'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2487
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCdtime ; "CDTime:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_82CD ; "##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, word ptr CDTime ; int32_t
//@ 		mov	dx, word ptr CDTime+2 ;	int32_t
//@ 		mov	cx, 20D0h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_82D6 ; ":"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_350] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_1	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, word ptr CDTime ; int32_t
//@ 		mov	dx, word ptr CDTime+2 ;	int32_t
//@ 		mov	cx, 8Ch	; 'Œ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, 3Ch	; '<'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2489
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMem	; "Mem:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_82E3 ; "#####"
//@ 		push	cs
//@ 		push	di
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_82EE ; "/"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_350] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_82E3 ; "#####"
//@ 		push	cs
//@ 		push	di
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2491
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2492
//@ 
//@ loc_8D98:				; CODE XREF: ExecConsole+8F8j
//@ 		cmp	ax, 1Fh		; Compare Two Operands
//@ 		jz	short loc_8DA0	; Jump if Zero (ZF=1)
//@ 		jmp	loc_8E36	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2493
//@ 
//@ loc_8DA0:				; CODE XREF: ExecConsole+A8Aj
//@ 		cmp	[bp+var_3A], 0	; char[21] // Pascal string
//@ 		jz	short loc_8DB7	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_3A]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2494
//@ 
//@ loc_8DB7:				; CODE XREF: ExecConsole+A93j
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_8DFD	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_82F0 ; "\""
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset Players.PName ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aNowIs_0 ; "\" now is \""
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_82F0 ; "\""
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ 		jmp	short loc_8E1C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2495
//@ 
//@ loc_8DFD:				; CODE XREF: ExecConsole+AABj
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCurrentNick	; "Current Nick: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2496
//@ 
//@ loc_8E1C:				; CODE XREF: ExecConsole+AEAj
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2497
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2500
//@ 
//@ loc_8E36:				; CODE XREF: ExecConsole+A8Cj
//@ 		cmp	ax, 27h	; '''   ; Compare Two Operands
//@ 		jnz	short loc_8E6C	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_8E69	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_8E69	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_8E69	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_8E69	; Jump if Not Zero (ZF=0)
//@ 		cmp	Internal, 0	; bool
//@ 		jnz	short loc_8E69	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2501
//@ 		mov	RecordDemo, 1	; bool
//@ 		mov	MenuCode, 4	; uint16_t
//@ 
//@ loc_8E69:				; CODE XREF: ExecConsole+B2Fj
//@ 					; ExecConsole+B36j ...
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2503
//@ 
//@ loc_8E6C:				; CODE XREF: ExecConsole+B28j
//@ 		cmp	ax, 28h	; '('   ; Compare Two Operands
//@ 		jnz	short loc_8EA7	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_8EA4	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_8EA4	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_8EA4	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_8EA4	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2504
//@ 		mov	PlayDemo, 1	; bool
//@ 		mov	ax, [bp+argint]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	LevelN,	ax	; int16_t
//@ 		call	GetNextDemoNumber ; function far PASCAL	returns	void
//@ 		mov	MenuCode, 4	; uint16_t
//@ 
//@ loc_8EA4:				; CODE XREF: ExecConsole+B65j
//@ 					; ExecConsole+B6Cj ...
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2506
//@ 
//@ loc_8EA7:				; CODE XREF: ExecConsole+B5Ej
//@ 		cmp	ax, 26h	; '&'   ; Compare Two Operands
//@ 		jnz	short loc_8ED2	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_8EBA	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_8ECF	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2508
//@ 
//@ loc_8EBA:				; CODE XREF: ExecConsole+BA0j
//@ 		call	EndDemo		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2510
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 2511
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"PS10.PAS" 2512
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 2513
//@ 
//@ loc_8ECF:				; CODE XREF: ExecConsole+BA7j
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2517
//@ 
//@ loc_8ED2:				; CODE XREF: ExecConsole+B99j
//@ 		cmp	ax, 1Eh		; Compare Two Operands
//@ 		jnz	short loc_8F02	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_8EE5	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_8EFF	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2519
//@ 
//@ loc_8EE5:				; CODE XREF: ExecConsole+BCBj
//@ 		push	20h ; ' '
//@ 		call	SendServerPost	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2520
//@ 		mov	CLIENT,	0	; bool
//@ 		mov	SERVER,	0	; bool
//@ ; #line	"PS10.PAS" 2521
//@ 		mov	MenuCode, 4	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyNetN,	ax	; int16_t
//@ ; #line	"PS10.PAS" 2522
//@ 
//@ loc_8EFF:				; CODE XREF: ExecConsole+BD2j
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2524
//@ 
//@ loc_8F02:				; CODE XREF: ExecConsole+BC4j
//@ 		cmp	ax, 1Ah		; Compare Two Operands
//@ 		jnz	short loc_8F25	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_8F22	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2525
//@ 		mov	al, byte ptr [bp+argint] ; int16_t
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_8F22	; Jump if Below	(CF=1)
//@ 		cmp	al, 7		; Compare Two Operands
//@ 		ja	short loc_8F22	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 2526
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		mov	byte ptr [di-0FD6h], 0
//@ 
//@ loc_8F22:				; CODE XREF: ExecConsole+BFBj
//@ 					; ExecConsole+C02j ...
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2528
//@ 
//@ loc_8F25:				; CODE XREF: ExecConsole+BF4j
//@ 		cmp	ax, 1Bh		; Compare Two Operands
//@ 		jnz	short loc_8F30	; Jump if Not Zero (ZF=0)
//@ 		call	SyncroTime	; function near	PASCAL returns void
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2530
//@ 
//@ loc_8F30:				; CODE XREF: ExecConsole+C17j
//@ 		cmp	ax, 19h		; Compare Two Operands
//@ 		jnz	short loc_8F6C	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2531
//@ 		cmp	[bp+argint], 0	; int16_t
//@ 		jl	short loc_8F69	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+argint], 7	; int16_t
//@ 		jg	short loc_8F69	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"PS10.PAS" 2532
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_8F69	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jle	short loc_8F69	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 2535
//@ 		imul	di, [bp+argint], 58h ; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di-0FAEh], ax
//@ ; #line	"PS10.PAS" 2536
//@ 		push	[bp+argint]	; int16_t
//@ 		call	AddDeadPlayer	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2537
//@ 
//@ loc_8F69:				; CODE XREF: ExecConsole+C28j
//@ 					; ExecConsole+C2Ej ...
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2539
//@ 
//@ loc_8F6C:				; CODE XREF: ExecConsole+C22j
//@ 		cmp	ax, 23h	; '#'   ; Compare Two Operands
//@ 		jnz	short loc_8F93	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_3A]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+sp2]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ 		jmp	loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2541
//@ 
//@ loc_8F93:				; CODE XREF: ExecConsole+C5Ej
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jnz	short loc_9004	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_8FA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_8F9F:				; CODE XREF: ExecConsole+CEFj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"PS10.PAS" 2542
//@ 
//@ loc_8FA2:				; CODE XREF: ExecConsole+C8Cj
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_56+2],	di
//@ 		mov	[bp+var_52], es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_8FFC	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2543
//@ 		lea	di, [bp+var_254] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_830C ; "["
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_154] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		add	ax, 31h	; '1'   ; Add
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_830E ; "] "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_56+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 1		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 
//@ loc_8FFC:				; CODE XREF: ExecConsole+CA5j
//@ 		cmp	[bp+n],	7	; uint16_t
//@ 		jnz	short loc_8F9F	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2544
//@ 
//@ loc_9004:				; CODE XREF: ExecConsole+C85j
//@ 		cmp	ax, 22h	; '"'   ; Compare Two Operands
//@ 		jnz	short loc_9024	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_9013	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9010:				; CODE XREF: ExecConsole+D0Fj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"PS10.PAS" 2545
//@ 
//@ loc_9013:				; CODE XREF: ExecConsole+CFDj
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	byte ptr [di-0FB0h], 0
//@ 		cmp	[bp+n],	7	; uint16_t
//@ 		jnz	short loc_9010	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2547
//@ 
//@ loc_9024:				; CODE XREF: ExecConsole+CF6j
//@ 		cmp	ax, 29h	; ')'   ; Compare Two Operands
//@ 		jnz	short loc_9031	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+argint]	; int16_t
//@ 		call	DO_CD_Play	; function near	PASCAL returns void
//@ 		jmp	short loc_9039	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2548
//@ 
//@ loc_9031:				; CODE XREF: ExecConsole+D16j
//@ 		cmp	ax, 2Ah	; '*'   ; Compare Two Operands
//@ 		jnz	short loc_9039	; Jump if Not Zero (ZF=0)
//@ 		call	DO_CD_Stop	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2550
//@ 
//@ loc_9039:				; CODE XREF: ExecConsole+22Ej
//@ 					; ExecConsole+24Ej ...
//@ 		mov	byte ptr ConsoleComm+0F6h, 0 ; char[287] // Pascal string
//@ ; #line	"PS10.PAS" 2551
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ExecConsole	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aQuit		db 4,'QUIT'             ; DATA XREF: ProcessConsole+28Eo
//@ aNew		db 3,'NEW'              ; DATA XREF: ProcessConsole+2D3o
//@ ; #line	"PS10.PAS" 2557
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessConsole	proc near		; CODE XREF: DoGame+2DDp
//@ 
//@ var_202		= byte ptr -202h
//@ var_102		= byte ptr -102h
//@ n		= byte ptr -1		; uint8_t
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2558
//@ 		cmp	KeysState+2Ah, 0 ; bool[128]
//@ 		jnz	short loc_905B	; Jump if Not Zero (ZF=0)
//@ 		cmp	KeysState+36h, 0 ; bool[128]
//@ 		jz	short loc_906E	; Jump if Zero (ZF=1)
//@ 
//@ loc_905B:				; CODE XREF: ProcessConsole+9j
//@ 		mov	al, key		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	di, ax
//@ 		mov	al, [di-1346h]
//@ 		mov	[bp+n],	al	; uint8_t
//@ 		jmp	short loc_907C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2559
//@ 
//@ loc_906E:				; CODE XREF: ProcessConsole+10j
//@ 		mov	al, key		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di-1346h]
//@ 		mov	[bp+n],	al	; uint8_t
//@ ; #line	"PS10.PAS" 2561
//@ 
//@ loc_907C:				; CODE XREF: ProcessConsole+23j
//@ 		cmp	key, 0Fh	; uint8_t
//@ 		jnz	short loc_908D	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, 1
//@ 		sub	ax, ConsMode	; int16_t
//@ 		mov	ConsMode, ax	; int16_t
//@ ; #line	"PS10.PAS" 2562
//@ 
//@ loc_908D:				; CODE XREF: ProcessConsole+38j
//@ 		cmp	key, 4Bh ; 'K'  ; uint8_t
//@ 		jnz	short loc_90A0	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 1	; int16_t
//@ 		jnz	short loc_90A0	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMode, ax	; int16_t
//@ ; #line	"PS10.PAS" 2563
//@ 
//@ loc_90A0:				; CODE XREF: ProcessConsole+49j
//@ 					; ProcessConsole+50j
//@ 		cmp	key, 4Dh ; 'M'  ; uint8_t
//@ 		jnz	short loc_90BB	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jnz	short loc_90BB	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMenu, 4	; int16_t
//@ 		jz	short loc_90BB	; Jump if Zero (ZF=1)
//@ 		mov	ConsMode, 1	; int16_t
//@ ; #line	"PS10.PAS" 2564
//@ 
//@ loc_90BB:				; CODE XREF: ProcessConsole+5Cj
//@ 					; ProcessConsole+63j ...
//@ 		cmp	key, 53h ; 'S'  ; uint8_t
//@ 		jnz	short loc_90C7	; Jump if Not Zero (ZF=0)
//@ 		mov	byte ptr ConsoleComm+0F6h, 0 ; char[287] // Pascal string
//@ ; #line	"PS10.PAS" 2567
//@ 
//@ loc_90C7:				; CODE XREF: ProcessConsole+77j
//@ 		cmp	ConsMode, 1	; int16_t
//@ 		jz	short loc_90D1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_9163	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2569
//@ 
//@ loc_90D1:				; CODE XREF: ProcessConsole+83j
//@ 		cmp	HistCnt, 0	; int16_t
//@ 		jnz	short loc_90DB	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_9163	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2571
//@ 
//@ loc_90DB:				; CODE XREF: ProcessConsole+8Dj
//@ 		cmp	key, 48h ; 'H'  ; uint8_t
//@ 		jnz	short loc_9110	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2573
//@ 		dec	CurHist		; int16_t
//@ 		cmp	CurHist, 1	; int16_t
//@ 		jge	short loc_90F3	; Jump if Greater or Equal (SF=OF)
//@ 		mov	CurHist, 1	; int16_t
//@ ; #line	"PS10.PAS" 2574
//@ 
//@ loc_90F3:				; CODE XREF: ProcessConsole+A2j
//@ 		imul	ax, CurHist, 28h ; int16_t
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFD8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2577
//@ 
//@ loc_9110:				; CODE XREF: ProcessConsole+97j
//@ 		cmp	key, 50h ; 'P'  ; uint8_t
//@ 		jnz	short loc_9163	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, HistCnt	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, CurHist	; int16_t
//@ 		jl	short loc_9163	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 2579
//@ 		inc	CurHist		; int16_t
//@ ; #line	"PS10.PAS" 2580
//@ 		mov	ax, HistCnt	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, CurHist	; int16_t
//@ 		jge	short loc_9136	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, HistCnt	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	CurHist, ax	; int16_t
//@ ; #line	"PS10.PAS" 2581
//@ 
//@ loc_9136:				; CODE XREF: ProcessConsole+E4j
//@ 		mov	ax, CurHist	; int16_t
//@ 		cmp	ax, HistCnt	; int16_t
//@ 		jg	short loc_915E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		imul	ax, CurHist, 28h ; int16_t
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFD8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_9163	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2582
//@ 
//@ loc_915E:				; CODE XREF: ProcessConsole+F4j
//@ 		mov	byte ptr ConsoleComm+0F6h, 0 ; char[287] // Pascal string
//@ ; #line	"PS10.PAS" 2587
//@ 
//@ loc_9163:				; CODE XREF: ProcessConsole+85j
//@ 					; ProcessConsole+8Fj ...
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_916D	; Jump if Zero (ZF=1)
//@ 		jmp	loc_936E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2589
//@ 
//@ loc_916D:				; CODE XREF: ProcessConsole+11Fj
//@ 		cmp	key, 48h ; 'H'  ; uint8_t
//@ 		jnz	short loc_9178	; Jump if Not Zero (ZF=0)
//@ 		dec	ConsMainY	; int16_t
//@ ; #line	"PS10.PAS" 2590
//@ 
//@ loc_9178:				; CODE XREF: ProcessConsole+129j
//@ 		cmp	key, 50h ; 'P'  ; uint8_t
//@ 		jnz	short loc_9183	; Jump if Not Zero (ZF=0)
//@ 		inc	ConsMainY	; int16_t
//@ ; #line	"PS10.PAS" 2592
//@ 
//@ loc_9183:				; CODE XREF: ProcessConsole+134j
//@ 		cmp	ConsMenu, 4	; int16_t
//@ 		jnz	short loc_91CB	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2594
//@ 		cmp	key, 4Dh ; 'M'  ; uint8_t
//@ 		jnz	short loc_91A8	; Jump if Not Zero (ZF=0)
//@ 		mov	di, ConsMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		cmp	word ptr [di-17DEh], 0Eh ; Compare Two Operands
//@ 		jge	short loc_91A8	; Jump if Greater or Equal (SF=OF)
//@ 		mov	di, ConsMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		inc	word ptr [di-17DEh] ; Increment	by 1
//@ ; #line	"PS10.PAS" 2595
//@ 
//@ loc_91A8:				; CODE XREF: ProcessConsole+146j
//@ 					; ProcessConsole+153j
//@ 		cmp	key, 4Bh ; 'K'  ; uint8_t
//@ 		jnz	short loc_91C6	; Jump if Not Zero (ZF=0)
//@ 		mov	di, ConsMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		cmp	word ptr [di-17DEh], 0 ; Compare Two Operands
//@ 		jle	short loc_91C6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, ConsMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		dec	word ptr [di-17DEh] ; Decrement	by 1
//@ ; #line	"PS10.PAS" 2596
//@ 
//@ loc_91C6:				; CODE XREF: ProcessConsole+164j
//@ 					; ProcessConsole+171j
//@ 		call	SetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2599
//@ 
//@ loc_91CB:				; CODE XREF: ProcessConsole+13Fj
//@ 		mov	ax, ConsMenu	; int16_t
//@ ; #line	"PS10.PAS" 2600
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jz	short loc_91D8	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_91E0	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_91D8:				; CODE XREF: ProcessConsole+188j
//@ 		mov	i, 2		; int16_t
//@ 		jmp	short loc_91F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2601
//@ 
//@ loc_91E0:				; CODE XREF: ProcessConsole+18Dj
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_91ED	; Jump if Not Zero (ZF=0)
//@ 		mov	i, 3		; int16_t
//@ 		jmp	short loc_91F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2602
//@ 
//@ loc_91ED:				; CODE XREF: ProcessConsole+19Aj
//@ 		mov	i, 5		; int16_t
//@ ; #line	"PS10.PAS" 2607
//@ 
//@ loc_91F3:				; CODE XREF: ProcessConsole+195j
//@ 					; ProcessConsole+1A2j
//@ 		cmp	ConsMainY, 0	; int16_t
//@ 		jge	short loc_9200	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, i		; int16_t
//@ 		mov	ConsMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2608
//@ 
//@ loc_9200:				; CODE XREF: ProcessConsole+1AFj
//@ 		mov	ax, ConsMainY	; int16_t
//@ 		cmp	ax, i		; int16_t
//@ 		jle	short loc_920E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2610
//@ 
//@ loc_920E:				; CODE XREF: ProcessConsole+1BEj
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jnz	short loc_9268	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMenu, 0	; int16_t
//@ 		jnz	short loc_9268	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2612
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_922A	; Jump if Zero (ZF=1)
//@ 		cmp	VESAPresent, 0	; bool
//@ 		jnz	short loc_9245	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2613
//@ 
//@ loc_922A:				; CODE XREF: ProcessConsole+1D8j
//@ 		cmp	ConsMainY, 1	; int16_t
//@ 		jnz	short loc_9245	; Jump if Not Zero (ZF=0)
//@ 		cmp	key, 50h ; 'P'  ; uint8_t
//@ 		jnz	short loc_9240	; Jump if Not Zero (ZF=0)
//@ 		mov	ConsMainY, 2	; int16_t
//@ 		jmp	short loc_9245	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9240:				; CODE XREF: ProcessConsole+1EDj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2614
//@ 
//@ loc_9245:				; CODE XREF: ProcessConsole+1DFj
//@ 					; ProcessConsole+1E6j ...
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_9268	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2615
//@ 		cmp	ConsMainY, 0	; int16_t
//@ 		jnz	short loc_9268	; Jump if Not Zero (ZF=0)
//@ 		cmp	key, 50h ; 'P'  ; uint8_t
//@ 		jnz	short loc_9262	; Jump if Not Zero (ZF=0)
//@ 		mov	ConsMainY, 1	; int16_t
//@ 		jmp	short loc_9268	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9262:				; CODE XREF: ProcessConsole+20Fj
//@ 		mov	ConsMainY, 3	; int16_t
//@ ; #line	"PS10.PAS" 2618
//@ 
//@ loc_9268:				; CODE XREF: ProcessConsole+1CAj
//@ 					; ProcessConsole+1D1j ...
//@ 		cmp	key, 1Ch	; uint8_t
//@ 		jz	short loc_9272	; Jump if Zero (ZF=1)
//@ 		jmp	loc_932D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2619
//@ 
//@ loc_9272:				; CODE XREF: ProcessConsole+224j
//@ 		mov	ax, ConsMenu	; int16_t
//@ ; #line	"PS10.PAS" 2620
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_92EF	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, ConsMainY	; int16_t
//@ ; #line	"PS10.PAS" 2621
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_9290	; Jump if Not Zero (ZF=0)
//@ 		mov	ConsMenu, 0Ah	; int16_t
//@ 		mov	ax, Skill	; int16_t
//@ 		mov	ConsMainY, ax	; int16_t
//@ 		jmp	short loc_92ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2622
//@ 
//@ loc_9290:				; CODE XREF: ProcessConsole+237j
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_92BA	; Jump if Not Zero (ZF=0)
//@ 		cmp	VESAPresent, 0	; bool
//@ 		jz	short loc_92B8	; Jump if Zero (ZF=1)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_92B8	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2623
//@ 		cmp	NETMonitor, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_92AD	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_92AD:				; CODE XREF: ProcessConsole+261j
//@ 		mov	NETMonitor, al	; bool
//@ 		call	SwitchMonitor	; function near	PASCAL returns void
//@ 		mov	key, 0Eh	; uint8_t
//@ 
//@ loc_92B8:				; CODE XREF: ProcessConsole+251j
//@ 					; ProcessConsole+258j
//@ 		jmp	short loc_92ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2624
//@ 
//@ loc_92BA:				; CODE XREF: ProcessConsole+24Aj
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_92CC	; Jump if Not Zero (ZF=0)
//@ 		mov	ConsMenu, 4	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMainY, ax	; int16_t
//@ 		jmp	short loc_92ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2625
//@ 
//@ loc_92CC:				; CODE XREF: ProcessConsole+274j
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_92ED	; Jump if Not Zero (ZF=0)
//@ 		mov	ConsMode, 1	; int16_t
//@ 		mov	di, offset aQuit ; "QUIT"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	key, 0		; uint8_t
//@ 
//@ loc_92ED:				; CODE XREF: ProcessConsole+245j
//@ 					; ProcessConsole:loc_92B8j ...
//@ 		jmp	short loc_932D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2627
//@ 
//@ loc_92EF:				; CODE XREF: ProcessConsole+22Fj
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jnz	short loc_9301	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMenu, ax	; int16_t
//@ 		mov	ConsMainY, 3	; int16_t
//@ 		jmp	short loc_932D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2628
//@ 
//@ loc_9301:				; CODE XREF: ProcessConsole+2A9j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_932D	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2629
//@ 		mov	ax, ConsMainY	; int16_t
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"PS10.PAS" 2630
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMainY, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMenu, ax	; int16_t
//@ 		mov	ConsMode, 1	; int16_t
//@ ; #line	"PS10.PAS" 2631
//@ 		mov	di, offset aNew	; "NEW"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2635
//@ 
//@ loc_932D:				; CODE XREF: ProcessConsole+226j
//@ 					; ProcessConsole:loc_92EDj ...
//@ 		cmp	key, 1		; uint8_t
//@ 		jnz	short loc_9362	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2636
//@ 		mov	ax, ConsMenu	; int16_t
//@ ; #line	"PS10.PAS" 2637
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jnz	short loc_934E	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMenu, ax	; int16_t
//@ 		mov	ConsMainY, 2	; int16_t
//@ 		mov	key, 0		; uint8_t
//@ 		jmp	short loc_9362	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2638
//@ 
//@ loc_934E:				; CODE XREF: ProcessConsole+2F1j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_9362	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMainY, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMenu, ax	; int16_t
//@ 		mov	key, 0		; uint8_t
//@ ; #line	"PS10.PAS" 2640
//@ 
//@ loc_9362:				; CODE XREF: ProcessConsole+2E9j
//@ 					; ProcessConsole+303j ...
//@ 		cmp	key, 0Eh	; uint8_t
//@ 		jnz	short loc_936E	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 1		; uint8_t
//@ ; #line	"PS10.PAS" 2643
//@ 
//@ loc_936E:				; CODE XREF: ProcessConsole+121j
//@ 					; ProcessConsole+31Ej
//@ 		cmp	[bp+n],	0	; uint8_t
//@ 		jz	short loc_93BC	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2645
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		cmp	al, 20h	; ' '   ; Compare Two Operands
//@ 		jb	short loc_93BC	; Jump if Below	(CF=1)
//@ 		cmp	al, 80h	; '€'   ; Compare Two Operands
//@ 		ja	short loc_93BC	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 2647
//@ 		cmp	byte ptr ConsoleComm+0F6h, 18h ; char[287] // Pascal string
//@ 		jnb	short loc_93B6	; Jump if Not Below (CF=0)
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2648
//@ 
//@ loc_93B6:				; CODE XREF: ProcessConsole+33Bj
//@ 		mov	ConsMode, 1	; int16_t
//@ ; #line	"PS10.PAS" 2652
//@ 
//@ loc_93BC:				; CODE XREF: ProcessConsole+329j
//@ 					; ProcessConsole+330j ...
//@ 		cmp	ConsMode, 1	; int16_t
//@ 		jnz	short loc_93F7	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2654
//@ 		cmp	key, 1Ch	; uint8_t
//@ 		jnz	short loc_93E5	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		pop	di
//@ 		pop	es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_93E5	; Jump if Zero (ZF=1)
//@ 		call	ExecConsole	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2655
//@ 
//@ loc_93E5:				; CODE XREF: ProcessConsole+37Fj
//@ 					; ProcessConsole+397j
//@ 		cmp	key, 0Eh	; uint8_t
//@ 		jnz	short loc_93F7	; Jump if Not Zero (ZF=0)
//@ 		cmp	byte ptr ConsoleComm+0F6h, 0 ; char[287] // Pascal string
//@ 		jz	short loc_93F7	; Jump if Zero (ZF=1)
//@ 		dec	byte ptr ConsoleComm+0F6h ; char[287] // Pascal	string
//@ ; #line	"PS10.PAS" 2660
//@ 
//@ loc_93F7:				; CODE XREF: ProcessConsole+378j
//@ 					; ProcessConsole+3A1j ...
//@ 		cmp	key, 1		; uint8_t
//@ 		jz	short loc_9405	; Jump if Zero (ZF=1)
//@ 		mov	key, 0		; uint8_t
//@ 		jmp	short locret_9411 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2661
//@ 
//@ loc_9405:				; CODE XREF: ProcessConsole+3B3j
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short locret_9411 ; Jump if Not	Zero (ZF=0)
//@ 		mov	key, 0Eh	; uint8_t
//@ ; #line	"PS10.PAS" 2662
//@ 
//@ locret_9411:				; CODE XREF: ProcessConsole+3BAj
//@ 					; ProcessConsole+3C1j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ProcessConsole	endp
//@ 
//@ ; #line	"PS10.PAS" 2667
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LeftRight	proc near		; CODE XREF: ProcessMenu+269p
//@ 					; ProcessMenu+27Dp ...
//@ 
//@ v		= dword	ptr  4		; uint8_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 2668
//@ 		cmp	key, 4Dh ; 'M'  ; uint8_t
//@ 		jnz	short loc_9429	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+v]	; uint8_t
//@ 		cmp	byte ptr es:[di], 0Fh ;	Compare	Two Operands
//@ 		jnb	short loc_9429	; Jump if Not Below (CF=0)
//@ 		inc	byte ptr es:[di] ; Increment by	1
//@ ; #line	"PS10.PAS" 2669
//@ 
//@ loc_9429:				; CODE XREF: LeftRight+8j
//@ 					; LeftRight+11j
//@ 		cmp	key, 4Bh ; 'K'  ; uint8_t
//@ 		jnz	short loc_943C	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+v]	; uint8_t
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jbe	short loc_943C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		dec	byte ptr es:[di] ; Decrement by	1
//@ ; #line	"PS10.PAS" 2670
//@ 
//@ loc_943C:				; CODE XREF: LeftRight+1Bj
//@ 					; LeftRight+24j
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	2
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2671
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ LeftRight	endp
//@ 
//@ ; #line	"PS10.PAS" 2674
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LR_Roll		proc near		; CODE XREF: ProcessMenu+2B0p
//@ 					; ProcessMenu+2C3p ...
//@ 
//@ m		= word ptr  4		; int16_t
//@ l		= word ptr  6		; int16_t
//@ v		= dword	ptr  8		; uint8_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 2675
//@ 		cmp	key, 4Bh ; 'K'  ; uint8_t
//@ 		jnz	short loc_9474	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+v]	; uint8_t
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+l]	; int16_t
//@ 		jle	short loc_9469	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		dec	byte ptr es:[di] ; Decrement by	1
//@ 		jmp	short loc_9472	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9469:				; CODE XREF: LR_Roll+15j
//@ 		mov	al, byte ptr [bp+m] ; int16_t
//@ 		les	di, [bp+v]	; uint8_t
//@ 		mov	es:[di], al
//@ 
//@ loc_9472:				; CODE XREF: LR_Roll+1Aj
//@ 		jmp	short loc_948F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2676
//@ 
//@ loc_9474:				; CODE XREF: LR_Roll+8j
//@ 		les	di, [bp+v]	; uint8_t
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+m]	; int16_t
//@ 		jge	short loc_9486	; Jump if Greater or Equal (SF=OF)
//@ 		inc	byte ptr es:[di] ; Increment by	1
//@ 		jmp	short loc_948F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9486:				; CODE XREF: LR_Roll+32j
//@ 		mov	al, byte ptr [bp+l] ; int16_t
//@ 		les	di, [bp+v]	; uint8_t
//@ 		mov	es:[di], al
//@ ; #line	"PS10.PAS" 2677
//@ 
//@ loc_948F:				; CODE XREF: LR_Roll:loc_9472j
//@ 					; LR_Roll+37j
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	2
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2678
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ LR_Roll		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a__3		db 1,'.'                ; DATA XREF: LookForLevel+5Co
//@ ; #line	"PS10.PAS" 2682
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LookForLevel	proc near		; CODE XREF: ProcessMenu+2E0p
//@ 
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2683
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	2
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2684
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_94BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_94BA:				; CODE XREF: LookForLevel+6Ej
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 2686
//@ 
//@ loc_94BD:				; CODE XREF: LookForLevel+16j
//@ 		cmp	key, 4Bh ; 'K'  ; uint8_t
//@ 		jnz	short loc_94D8	; Jump if Not Zero (ZF=0)
//@ 		cmp	NGLevel, 1	; uint8_t
//@ 		jbe	short loc_94D1	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		dec	NGLevel		; uint8_t
//@ 		jmp	short loc_94D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_94D1:				; CODE XREF: LookForLevel+27j
//@ 		mov	NGLevel, 40h ; '@' ; uint8_t
//@ 
//@ loc_94D6:				; CODE XREF: LookForLevel+2Dj
//@ 		jmp	short loc_94EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2687
//@ 
//@ loc_94D8:				; CODE XREF: LookForLevel+20j
//@ 		cmp	NGLevel, 40h ; '@' ; uint8_t
//@ 		jnb	short loc_94E5	; Jump if Not Below (CF=0)
//@ 		inc	NGLevel		; uint8_t
//@ 		jmp	short loc_94EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_94E5:				; CODE XREF: LookForLevel+3Bj
//@ 		mov	NGLevel, 1	; uint8_t
//@ ; #line	"PS10.PAS" 2688
//@ 
//@ loc_94EA:				; CODE XREF: LookForLevel:loc_94D6j
//@ 					; LookForLevel+41j
//@ 		mov	al, NGLevel	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, LevelNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset a__3	; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_950C	; Jump if Zero (ZF=1)
//@ 		jmp	short locret_9512 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2689
//@ 
//@ loc_950C:				; CODE XREF: LookForLevel+66j
//@ 		cmp	[bp+n],	40h ; '@' ; int16_t
//@ 		jnz	short loc_94BA	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2690
//@ 
//@ locret_9512:				; CODE XREF: LookForLevel+68j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LookForLevel	endp
//@ 
//@ ; #line	"PS10.PAS" 2695
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RemoveMouse	proc near		; CODE XREF: ProcessMenu+4Dp
//@ 					; ProcessMenu+5Dp ...
//@ 
//@ n		= word ptr -2		; int16_t
//@ k		= word ptr  4		; int16_t
//@ m		= word ptr  6		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2696
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	ax, [bp+m]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0ECB0h
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	byte ptr es:[di], 32h ;	'2'
//@ ; #line	"PS10.PAS" 2697
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_953D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_953A:				; CODE XREF: RemoveMouse+69j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 2698
//@ 
//@ loc_953D:				; CODE XREF: RemoveMouse+24j
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0ECB0h
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+k]	; int16_t
//@ 		jnz	short loc_9579	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0ECB0h
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	byte ptr es:[di], 32h ;	'2'
//@ 
//@ loc_9579:				; CODE XREF: RemoveMouse+48j
//@ 		cmp	[bp+n],	2	; int16_t
//@ 		jnz	short loc_953A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2699
//@ 		mov	al, byte ptr KbWait ; int16_t
//@ 		push	ax
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	ax, [bp+m]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0ECB0h
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		pop	es
//@ 		pop	ax
//@ 		mov	es:[di], al
//@ 		mov	KbWait,	0FFFFh	; int16_t
//@ ; #line	"PS10.PAS" 2700
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ RemoveMouse	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aNpNotInstall_1	db 17,'NP not installed.' ; DATA XREF: ProcessMenu:loc_9A98o
//@ 					; ProcessMenu:loc_9AD1o
//@ aClientCannot_0	db 35,'CLIENT CANNOT CHANGE GAME SETTINGS.'
//@ 					; DATA XREF: ProcessMenu:loc_9AC5o
//@ a___		db 4,' ...'             ; DATA XREF: ProcessMenu+56Do
//@ aCannotChangeDi	db 38,'Cannot change difficulty in this mode.'
//@ 					; DATA XREF: ProcessMenu:loc_9C06o
//@ ; #line	"PS10.PAS" 2704
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessMenu	proc near		; CODE XREF: DoGame+2E7p
//@ 
//@ var_200		= byte ptr -200h
//@ var_100		= byte ptr -100h
//@ 
//@ 		enter	200h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2705
//@ 		cmp	KbWait,	0FFFFh	; int16_t
//@ 		jz	short loc_968C	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2707
//@ 		call	GetMouseStatus	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2708
//@ 		call	GetJoyStatus	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2709
//@ 		cmp	key, 1		; uint8_t
//@ 		jbe	short loc_9643	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	key, 58h ; 'X'  ; uint8_t
//@ 		ja	short loc_9643	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 2710
//@ 		mov	al, key		; uint8_t
//@ 		mov	di, KbWait	; int16_t
//@ 		mov	[di-1360h], al
//@ 		mov	KbWait,	0FFFFh	; int16_t
//@ 		mov	key, 0		; uint8_t
//@ ; #line	"PS10.PAS" 2711
//@ 
//@ loc_9643:				; CODE XREF: ProcessMenu+1Aj
//@ 					; ProcessMenu+21j
//@ 		cmp	KbWait,	0Dh	; int16_t
//@ 		jge	short loc_967A	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 2713
//@ 		cmp	MsKeyA,	0	; bool
//@ 		jz	short loc_965A	; Jump if Zero (ZF=1)
//@ 		push	0
//@ 		push	KbWait		; int16_t
//@ 		call	RemoveMouse	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2714
//@ 
//@ loc_965A:				; CODE XREF: ProcessMenu+45j
//@ 		cmp	MsKeyB,	0	; bool
//@ 		jz	short loc_966A	; Jump if Zero (ZF=1)
//@ 		push	1
//@ 		push	KbWait		; int16_t
//@ 		call	RemoveMouse	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2715
//@ 
//@ loc_966A:				; CODE XREF: ProcessMenu+55j
//@ 		cmp	MsKeyC,	0	; bool
//@ 		jz	short loc_967A	; Jump if Zero (ZF=1)
//@ 		push	2
//@ 		push	KbWait		; int16_t
//@ 		call	RemoveMouse	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2717
//@ 
//@ loc_967A:				; CODE XREF: ProcessMenu+3Ej
//@ 					; ProcessMenu+65j
//@ 		cmp	key, 1		; uint8_t
//@ 		jnz	short loc_968C	; Jump if Not Zero (ZF=0)
//@ 		mov	KbWait,	0FFFFh	; int16_t
//@ 		mov	key, 0		; uint8_t
//@ ; #line	"PS10.PAS" 2720
//@ 
//@ loc_968C:				; CODE XREF: ProcessMenu+9j
//@ 					; ProcessMenu+75j
//@ 		cmp	key, 0		; uint8_t
//@ 		jnz	short loc_9696	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_9E31	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2721
//@ 
//@ loc_9696:				; CODE XREF: ProcessMenu+87j
//@ 		cmp	key, 48h ; 'H'  ; uint8_t
//@ 		jnz	short loc_96A1	; Jump if Not Zero (ZF=0)
//@ 		dec	MenuMainY	; int16_t
//@ ; #line	"PS10.PAS" 2722
//@ 
//@ loc_96A1:				; CODE XREF: ProcessMenu+91j
//@ 		cmp	key, 50h ; 'P'  ; uint8_t
//@ 		jnz	short loc_96AC	; Jump if Not Zero (ZF=0)
//@ 		inc	MenuMainY	; int16_t
//@ ; #line	"PS10.PAS" 2723
//@ 
//@ loc_96AC:				; CODE XREF: ProcessMenu+9Cj
//@ 		mov	al, key		; uint8_t
//@ 		cmp	al, 48h	; 'H'   ; Compare Two Operands
//@ 		jz	short loc_96B7	; Jump if Zero (ZF=1)
//@ 		cmp	al, 50h	; 'P'   ; Compare Two Operands
//@ 		jnz	short loc_96C4	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_96B7:				; CODE XREF: ProcessMenu+A7j
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	4
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2724
//@ 
//@ loc_96C4:				; CODE XREF: ProcessMenu+ABj
//@ 		cmp	key, 1Ch	; uint8_t
//@ 		jnz	short loc_96D8	; Jump if Not Zero (ZF=0)
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	5
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2725
//@ 
//@ loc_96D8:				; CODE XREF: ProcessMenu+BFj
//@ 		cmp	key, 1		; uint8_t
//@ 		jnz	short loc_96EC	; Jump if Not Zero (ZF=0)
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	3
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2727
//@ 
//@ loc_96EC:				; CODE XREF: ProcessMenu+D3j
//@ 		mov	ax, MenuMode	; int16_t
//@ ; #line	"PS10.PAS" 2728
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_972E	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2729
//@ 		mov	i, 5		; int16_t
//@ ; #line	"PS10.PAS" 2730
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_970F	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_970F	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_972B	; Jump if Zero (ZF=1)
//@ 
//@ loc_970F:				; CODE XREF: ProcessMenu+F5j
//@ 					; ProcessMenu+FCj
//@ 		cmp	MenuMainY, 2	; int16_t
//@ 		jnz	short loc_972B	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2731
//@ 		cmp	key, 48h ; 'H'  ; uint8_t
//@ 		jnz	short loc_9725	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuMainY, 1	; int16_t
//@ 		jmp	short loc_972B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9725:				; CODE XREF: ProcessMenu+111j
//@ 		mov	MenuMainY, 3	; int16_t
//@ ; #line	"PS10.PAS" 2732
//@ 
//@ loc_972B:				; CODE XREF: ProcessMenu+103j
//@ 					; ProcessMenu+10Aj ...
//@ 		jmp	loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2733
//@ 
//@ loc_972E:				; CODE XREF: ProcessMenu+E8j
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jnz	short loc_9752	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_9749	; Jump if Zero (ZF=1)
//@ 		cmp	VESAPresent, 0	; bool
//@ 		jz	short loc_9749	; Jump if Zero (ZF=1)
//@ 		mov	i, 3		; int16_t
//@ 		jmp	short loc_974F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9749:				; CODE XREF: ProcessMenu+12Ej
//@ 					; ProcessMenu+135j
//@ 		mov	i, 2		; int16_t
//@ 
//@ loc_974F:				; CODE XREF: ProcessMenu+13Dj
//@ 		jmp	loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2734
//@ 
//@ loc_9752:				; CODE XREF: ProcessMenu+127j
//@ 		cmp	ax, 0Ch		; Compare Two Operands
//@ 		jz	short loc_975C	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Dh		; Compare Two Operands
//@ 		jnz	short loc_9764	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_975C:				; CODE XREF: ProcessMenu+14Bj
//@ 		mov	i, 9		; int16_t
//@ 		jmp	short loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2735
//@ 
//@ loc_9764:				; CODE XREF: ProcessMenu+150j
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jnz	short loc_9771	; Jump if Not Zero (ZF=0)
//@ 		mov	i, 0Bh		; int16_t
//@ 		jmp	short loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2736
//@ 
//@ loc_9771:				; CODE XREF: ProcessMenu+15Dj
//@ 		cmp	ax, 18h		; Compare Two Operands
//@ 		jnz	short loc_977E	; Jump if Not Zero (ZF=0)
//@ 		mov	i, 0Fh		; int16_t
//@ 		jmp	short loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2737
//@ 
//@ loc_977E:				; CODE XREF: ProcessMenu+16Aj
//@ 		cmp	ax, 19h		; Compare Two Operands
//@ 		jz	short loc_9788	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 1Ah		; Compare Two Operands
//@ 		jnz	short loc_9790	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_9788:				; CODE XREF: ProcessMenu+177j
//@ 		mov	i, 2		; int16_t
//@ 		jmp	short loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2738
//@ 
//@ loc_9790:				; CODE XREF: ProcessMenu+17Cj
//@ 		cmp	ax, 1Bh		; Compare Two Operands
//@ 		jnz	short loc_979E	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		dec	ax		; Decrement by 1
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2739
//@ 
//@ loc_979E:				; CODE XREF: ProcessMenu+189j
//@ 		cmp	ax, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jnz	short loc_97B8	; Jump if Not Zero (ZF=0)
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+278h]
//@ 		add	ax, 5		; Add
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2740
//@ 
//@ loc_97B8:				; CODE XREF: ProcessMenu+197j
//@ 		cmp	ax, 70h	; 'p'   ; Compare Two Operands
//@ 		jnz	short loc_97D0	; Jump if Not Zero (ZF=0)
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+278h]
//@ 		inc	ax		; Increment by 1
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_97DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2741
//@ 
//@ loc_97D0:				; CODE XREF: ProcessMenu+1B1j
//@ 		cmp	ax, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_97DB	; Jump if Not Zero (ZF=0)
//@ 		mov	i, 2		; int16_t
//@ ; #line	"PS10.PAS" 2744
//@ 
//@ loc_97DB:				; CODE XREF: ProcessMenu:loc_972Bj
//@ 					; ProcessMenu:loc_974Fj ...
//@ 		cmp	MenuMainY, 0	; int16_t
//@ 		jge	short loc_97E8	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, i		; int16_t
//@ 		mov	MenuMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2745
//@ 
//@ loc_97E8:				; CODE XREF: ProcessMenu+1D6j
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		cmp	ax, i		; int16_t
//@ 		jle	short loc_97F6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2747
//@ 
//@ loc_97F6:				; CODE XREF: ProcessMenu+1E5j
//@ 		mov	al, key		; uint8_t
//@ 		cmp	al, 1Ch		; Compare Two Operands
//@ 		jz	short loc_9808	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4Bh	; 'K'   ; Compare Two Operands
//@ 		jz	short loc_9808	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4Dh	; 'M'   ; Compare Two Operands
//@ 		jz	short loc_9808	; Jump if Zero (ZF=1)
//@ 		jmp	loc_998D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2748
//@ 
//@ loc_9808:				; CODE XREF: ProcessMenu+1F1j
//@ 					; ProcessMenu+1F5j ...
//@ 		mov	ax, MenuMode	; int16_t
//@ ; #line	"PS10.PAS" 2749
//@ 		cmp	ax, 19h		; Compare Two Operands
//@ 		jnz	short loc_9861	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2750
//@ 		cmp	key, 4Dh ; 'M'  ; uint8_t
//@ 		jnz	short loc_982E	; Jump if Not Zero (ZF=0)
//@ 		mov	di, MenuMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		cmp	word ptr [di-17DEh], 0Eh ; Compare Two Operands
//@ 		jge	short loc_982E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	di, MenuMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		inc	word ptr [di-17DEh] ; Increment	by 1
//@ ; #line	"PS10.PAS" 2751
//@ 
//@ loc_982E:				; CODE XREF: ProcessMenu+20Bj
//@ 					; ProcessMenu+218j
//@ 		cmp	key, 4Bh ; 'K'  ; uint8_t
//@ 		jnz	short loc_984C	; Jump if Not Zero (ZF=0)
//@ 		mov	di, MenuMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		cmp	word ptr [di-17DEh], 0 ; Compare Two Operands
//@ 		jle	short loc_984C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, MenuMainY	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		dec	word ptr [di-17DEh] ; Decrement	by 1
//@ ; #line	"PS10.PAS" 2752
//@ 
//@ loc_984C:				; CODE XREF: ProcessMenu+229j
//@ 					; ProcessMenu+236j
//@ 		call	SetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2753
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	2
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2754
//@ 		jmp	loc_998D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2755
//@ 
//@ loc_9861:				; CODE XREF: ProcessMenu+204j
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jnz	short loc_98A1	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, MenuMainY	; int16_t
//@ ; #line	"PS10.PAS" 2756
//@ 		cmp	ax, 8		; Compare Two Operands
//@ 		jnz	short loc_987D	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset FXVolume ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		call	LeftRight	; function near	PASCAL returns void
//@ 		call	SetVolumes	; function far PASCAL returns void
//@ 		jmp	short loc_989E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2757
//@ 
//@ loc_987D:				; CODE XREF: ProcessMenu+262j
//@ 		cmp	ax, 9		; Compare Two Operands
//@ 		jnz	short loc_9891	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset CDVolume ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		call	LeftRight	; function near	PASCAL returns void
//@ 		call	SetVolumes	; function far PASCAL returns void
//@ 		jmp	short loc_989E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2758
//@ 
//@ loc_9891:				; CODE XREF: ProcessMenu+276j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_989E	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset MSsens ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		call	LeftRight	; function near	PASCAL returns void
//@ 
//@ loc_989E:				; CODE XREF: ProcessMenu+271j
//@ 					; ProcessMenu+285j ...
//@ 		jmp	loc_998D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2760
//@ 
//@ loc_98A1:				; CODE XREF: ProcessMenu+25Aj
//@ 		cmp	ax, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jz	short loc_98A9	; Jump if Zero (ZF=1)
//@ 		jmp	loc_9928	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_98A9:				; CODE XREF: ProcessMenu+29Aj
//@ 		mov	ax, MenuMainY	; int16_t
//@ ; #line	"PS10.PAS" 2761
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_98BF	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGMode ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	2
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 		jmp	short loc_9926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2762
//@ 
//@ loc_98BF:				; CODE XREF: ProcessMenu+2A5j
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_98D2	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGTeam ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	1
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 		jmp	short loc_9926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2763
//@ 
//@ loc_98D2:				; CODE XREF: ProcessMenu+2B8j
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_98E5	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGSkill ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	2
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 		jmp	short loc_9926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2764
//@ 
//@ loc_98E5:				; CODE XREF: ProcessMenu+2CBj
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jnz	short loc_98EF	; Jump if Not Zero (ZF=0)
//@ 		call	LookForLevel	; function near	PASCAL returns void
//@ 		jmp	short loc_9926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2765
//@ 
//@ loc_98EF:				; CODE XREF: ProcessMenu+2DEj
//@ 		cmp	ax, 5		; Compare Two Operands
//@ 		jnz	short loc_9902	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGCard ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	1
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 		jmp	short loc_9926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2766
//@ 
//@ loc_9902:				; CODE XREF: ProcessMenu+2E8j
//@ 		cmp	ax, 6		; Compare Two Operands
//@ 		jnz	short loc_9915	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGPort ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	1
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 		jmp	short loc_9926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2767
//@ 
//@ loc_9915:				; CODE XREF: ProcessMenu+2FBj
//@ 		cmp	ax, 7		; Compare Two Operands
//@ 		jnz	short loc_9926	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGBaud ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	4
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 
//@ loc_9926:				; CODE XREF: ProcessMenu+2B3j
//@ 					; ProcessMenu+2C6j ...
//@ 		jmp	short loc_998D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2769
//@ 
//@ loc_9928:				; CODE XREF: ProcessMenu+29Cj
//@ 		cmp	ax, 70h	; 'p'   ; Compare Two Operands
//@ 		jnz	short loc_9969	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, MenuMainY	; int16_t
//@ ; #line	"PS10.PAS" 2770
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_9943	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGCard ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	1
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 		jmp	short loc_9967	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2771
//@ 
//@ loc_9943:				; CODE XREF: ProcessMenu+329j
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_9956	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGPort ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	1
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 		jmp	short loc_9967	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2772
//@ 
//@ loc_9956:				; CODE XREF: ProcessMenu+33Cj
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_9967	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGBaud ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	4
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ 
//@ loc_9967:				; CODE XREF: ProcessMenu+337j
//@ 					; ProcessMenu+34Aj ...
//@ 		jmp	short loc_998D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2774
//@ 
//@ loc_9969:				; CODE XREF: ProcessMenu+321j
//@ 		cmp	ax, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_998D	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2775
//@ 		cmp	key, 1Ch	; uint8_t
//@ 		jnz	short loc_997A	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2776
//@ 
//@ loc_997A:				; CODE XREF: ProcessMenu+369j
//@ 		cmp	MenuMainY, 2	; int16_t
//@ 		jnz	short loc_998D	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset NGColor ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	8
//@ 		call	LR_Roll		; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2780
//@ 
//@ loc_998D:				; CODE XREF: ProcessMenu+1FBj
//@ 					; ProcessMenu+254j ...
//@ 		cmp	MenuMainY, 1	; int16_t
//@ 		jz	short loc_9997	; Jump if Zero (ZF=1)
//@ 		jmp	loc_9A1A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9997:				; CODE XREF: ProcessMenu+388j
//@ 		cmp	MenuMode, 71h ;	'q' ; int16_t
//@ 		jnz	short loc_9A1A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2782
//@ 		cmp	key, 0Eh	; uint8_t
//@ 		jnz	short loc_99B0	; Jump if Not Zero (ZF=0)
//@ 		cmp	byte ptr NGNick, 0 ; char[9] //	Pascal string
//@ 		jbe	short loc_99B0	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		dec	byte ptr NGNick	; char[9] // Pascal string
//@ ; #line	"PS10.PAS" 2783
//@ 
//@ loc_99B0:				; CODE XREF: ProcessMenu+399j
//@ 					; ProcessMenu+3A0j
//@ 		cmp	KeysState+2Ah, 0 ; bool[128]
//@ 		jnz	short loc_99BE	; Jump if Not Zero (ZF=0)
//@ 		cmp	KeysState+36h, 0 ; bool[128]
//@ 		jz	short loc_99D1	; Jump if Zero (ZF=1)
//@ 
//@ loc_99BE:				; CODE XREF: ProcessMenu+3ABj
//@ 		mov	al, key		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	di, ax
//@ 		mov	al, [di-1346h]
//@ 		mov	c, al		; uint8_t
//@ 		jmp	short loc_99DF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2784
//@ 
//@ loc_99D1:				; CODE XREF: ProcessMenu+3B2j
//@ 		mov	al, key		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di-1346h]
//@ 		mov	c, al		; uint8_t
//@ ; #line	"PS10.PAS" 2785
//@ 
//@ loc_99DF:				; CODE XREF: ProcessMenu+3C5j
//@ 		mov	al, c		; uint8_t
//@ 		cmp	al, 20h	; ' '   ; Compare Two Operands
//@ 		jb	short loc_9A1A	; Jump if Below	(CF=1)
//@ 		cmp	al, 80h	; '€'   ; Compare Two Operands
//@ 		ja	short loc_9A1A	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 2786
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset NGNick ; char[9] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, c		; uint8_t
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset NGNick ; char[9] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 2791
//@ 
//@ loc_9A1A:				; CODE XREF: ProcessMenu+38Aj
//@ 					; ProcessMenu+392j ...
//@ 		cmp	key, 1Ch	; uint8_t
//@ 		jz	short loc_9A24	; Jump if Zero (ZF=1)
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2792
//@ 
//@ loc_9A24:				; CODE XREF: ProcessMenu+415j
//@ 		mov	ax, MenuMode	; int16_t
//@ ; #line	"PS10.PAS" 2793
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_9A6E	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_9A3F	; Jump if Zero (ZF=1)
//@ 		cmp	MenuMainY, 0	; int16_t
//@ 		jnz	short loc_9A3F	; Jump if Not Zero (ZF=0)
//@ 		call	NewGame		; function near	PASCAL returns void
//@ 		jmp	short loc_9A6B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2795
//@ 
//@ loc_9A3F:				; CODE XREF: ProcessMenu+427j
//@ 					; ProcessMenu+42Ej
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		add	ax, 0Ah		; Add
//@ 		mov	MenuMode, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2796
//@ 		mov	al, byte ptr MenuMode ;	int16_t
//@ 		cmp	al, 0Ch		; Compare Two Operands
//@ 		jb	short loc_9A5E	; Jump if Below	(CF=1)
//@ 		cmp	al, 0Dh		; Compare Two Operands
//@ 		ja	short loc_9A5E	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, LoadSaveY	; uint16_t
//@ 		mov	MenuMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2797
//@ 
//@ loc_9A5E:				; CODE XREF: ProcessMenu+448j
//@ 					; ProcessMenu+44Cj
//@ 		cmp	MenuMode, 0Ah	; int16_t
//@ 		jnz	short loc_9A6B	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, Skill	; int16_t
//@ 		mov	MenuMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 2798
//@ 
//@ loc_9A6B:				; CODE XREF: ProcessMenu+433j
//@ 					; ProcessMenu+459j
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2799
//@ 
//@ loc_9A6E:				; CODE XREF: ProcessMenu+420j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_9A79	; Jump if Not Zero (ZF=0)
//@ 		call	NewGame		; function near	PASCAL returns void
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2800
//@ 
//@ loc_9A79:				; CODE XREF: ProcessMenu+467j
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jz	short loc_9A81	; Jump if Zero (ZF=1)
//@ 		jmp	loc_9B34	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9A81:				; CODE XREF: ProcessMenu+472j
//@ 		mov	ax, MenuMainY	; int16_t
//@ ; #line	"PS10.PAS" 2801
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_9AA5	; Jump if Not Zero (ZF=0)
//@ 		cmp	NPinst,	0	; bool
//@ 		jz	short loc_9A98	; Jump if Zero (ZF=1)
//@ 		mov	MenuMode, 70h ;	'p' ; int16_t
//@ 		jmp	short loc_9AA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2802
//@ 
//@ loc_9A98:				; CODE XREF: ProcessMenu+484j
//@ 		mov	di, offset aNpNotInstall_1 ; "NP not installed."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 
//@ loc_9AA2:				; CODE XREF: ProcessMenu+48Cj
//@ 		jmp	loc_9B31	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2803
//@ 
//@ loc_9AA5:				; CODE XREF: ProcessMenu+47Dj
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_9ADD	; Jump if Not Zero (ZF=0)
//@ 		cmp	NPinst,	0	; bool
//@ 		jz	short loc_9AD1	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2804
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_9AC5	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2805
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		mov	MenuMode, 6Fh ;	'o' ; int16_t
//@ 		jmp	short loc_9ACF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2806
//@ 
//@ loc_9AC5:				; CODE XREF: ProcessMenu+4ACj
//@ 		mov	di, offset aClientCannot_0 ; "CLIENT CANNOT CHANGE GAME	SETTINGS."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 
//@ loc_9ACF:				; CODE XREF: ProcessMenu+4B9j
//@ 		jmp	short loc_9ADB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2807
//@ 
//@ loc_9AD1:				; CODE XREF: ProcessMenu+4A5j
//@ 		mov	di, offset aNpNotInstall_1 ; "NP not installed."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 
//@ loc_9ADB:				; CODE XREF: ProcessMenu:loc_9ACFj
//@ 		jmp	short loc_9B31	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2808
//@ 
//@ loc_9ADD:				; CODE XREF: ProcessMenu+49Ej
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_9B06	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset NGNick ; char[9] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	al, SelfColor	; uint8_t
//@ 		mov	NGColor, al	; uint8_t
//@ 		mov	MenuMode, 71h ;	'q' ; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	short loc_9B31	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2810
//@ 
//@ loc_9B06:				; CODE XREF: ProcessMenu+4D6j
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_9B31	; Jump if Not Zero (ZF=0)
//@ 		cmp	VESAPresent, 0	; bool
//@ 		jz	short loc_9B31	; Jump if Zero (ZF=1)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_9B31	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2811
//@ 		mov	NETMonitor, 1	; bool
//@ 		call	SwitchMonitor	; function near	PASCAL returns void
//@ 		mov	MenuOn,	0	; bool
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMode, ax	; int16_t
//@ 		mov	MenuMainY, 1	; int16_t
//@ 
//@ loc_9B31:				; CODE XREF: ProcessMenu:loc_9AA2j
//@ 					; ProcessMenu:loc_9ADBj ...
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2813
//@ 
//@ loc_9B34:				; CODE XREF: ProcessMenu+474j
//@ 		cmp	ax, 0Ch		; Compare Two Operands
//@ 		jnz	short loc_9B61	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_9B5E	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2814
//@ 		push	MenuMainY	; int16_t
//@ 		call	SaveGame	; function far PASCAL returns void
//@ 		call	ScanSavedNames	; function far PASCAL returns void
//@ 		mov	MenuMainY, 2	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMode, ax	; int16_t
//@ 		mov	MenuOn,	0	; bool
//@ 
//@ loc_9B5E:				; CODE XREF: ProcessMenu+534j
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2815
//@ 
//@ loc_9B61:				; CODE XREF: ProcessMenu+52Dj
//@ 		cmp	ax, 0Dh		; Compare Two Operands
//@ 		jnz	short loc_9B98	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, MenuMainY, 28h ; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 0F50h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset a___	; " ..."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_9B95	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 2816
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		mov	LoadSaveY, ax	; uint16_t
//@ 		mov	al, byte ptr MenuMainY ; int16_t
//@ 		mov	LSMenuY, al	; uint8_t
//@ 		mov	MenuCode, 100h	; uint16_t
//@ 
//@ loc_9B95:				; CODE XREF: ProcessMenu+577j
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2817
//@ 
//@ loc_9B98:				; CODE XREF: ProcessMenu+55Aj
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jz	short loc_9BA0	; Jump if Zero (ZF=1)
//@ 		jmp	loc_9C6F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9BA0:				; CODE XREF: ProcessMenu+591j
//@ 		mov	ax, MenuMainY	; int16_t
//@ ; #line	"PS10.PAS" 2818
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_9BB6	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuMode, 18h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2819
//@ 
//@ loc_9BB6:				; CODE XREF: ProcessMenu+59Cj
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_9BCB	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuMode, 1Bh	; int16_t
//@ 		mov	ax, CurVideoMode ; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2820
//@ 
//@ loc_9BCB:				; CODE XREF: ProcessMenu+5AFj
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_9BDE	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuMode, 19h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2821
//@ 
//@ loc_9BDE:				; CODE XREF: ProcessMenu+5C4j
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_9C12	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_9C06	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_9C06	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_9C06	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2822
//@ 		mov	MenuMode, 1Ah	; int16_t
//@ 		mov	ax, Skill	; int16_t
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	short loc_9C10	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2823
//@ 
//@ loc_9C06:				; CODE XREF: ProcessMenu+5DEj
//@ 					; ProcessMenu+5E5j ...
//@ 		mov	di, offset aCannotChangeDi ; "Cannot change difficulty in this mode."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 
//@ loc_9C10:				; CODE XREF: ProcessMenu+5FAj
//@ 		jmp	short loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2824
//@ 
//@ loc_9C12:				; CODE XREF: ProcessMenu+5D7j
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jnz	short loc_9C26	; Jump if Not Zero (ZF=0)
//@ 		cmp	AlwaysRun, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_9C21	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_9C21:				; CODE XREF: ProcessMenu+614j
//@ 		mov	AlwaysRun, al	; bool
//@ 		jmp	short loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2825
//@ 
//@ loc_9C26:				; CODE XREF: ProcessMenu+60Bj
//@ 		cmp	ax, 5		; Compare Two Operands
//@ 		jnz	short loc_9C3A	; Jump if Not Zero (ZF=0)
//@ 		cmp	Cocpit,	0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_9C35	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_9C35:				; CODE XREF: ProcessMenu+628j
//@ 		mov	Cocpit,	al	; bool
//@ 		jmp	short loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2826
//@ 
//@ loc_9C3A:				; CODE XREF: ProcessMenu+61Fj
//@ 		cmp	ax, 6		; Compare Two Operands
//@ 		jnz	short loc_9C4E	; Jump if Not Zero (ZF=0)
//@ 		cmp	ReverseMouse, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_9C49	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_9C49:				; CODE XREF: ProcessMenu+63Cj
//@ 		mov	ReverseMouse, al ; bool
//@ 		jmp	short loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2827
//@ 
//@ loc_9C4E:				; CODE XREF: ProcessMenu+633j
//@ 		cmp	ax, 7		; Compare Two Operands
//@ 		jnz	short loc_9C62	; Jump if Not Zero (ZF=0)
//@ 		cmp	EpisodeReset, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_9C5D	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_9C5D:				; CODE XREF: ProcessMenu+650j
//@ 		mov	EpisodeReset, al ; bool
//@ 		jmp	short loc_9C6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2828
//@ 
//@ loc_9C62:				; CODE XREF: ProcessMenu+647j
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jnz	short loc_9C6C	; Jump if Not Zero (ZF=0)
//@ 		push	0
//@ 		call	LoadConfig	; function near	PASCAL returns void
//@ 
//@ loc_9C6C:				; CODE XREF: ProcessMenu+5A9j
//@ 					; ProcessMenu+5BEj ...
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2830
//@ 
//@ loc_9C6F:				; CODE XREF: ProcessMenu+593j
//@ 		cmp	ax, 1Bh		; Compare Two Operands
//@ 		jnz	short loc_9C92	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2831
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	CurVideoMode, ax ; uint16_t
//@ ; #line	"PS10.PAS" 2832
//@ 		call	CorrectMenuPos	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2833
//@ 		call	AllocVideo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2834
//@ 		call	SetVideoMode	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2835
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2836
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2837
//@ 
//@ loc_9C92:				; CODE XREF: ProcessMenu+668j
//@ 		cmp	ax, 0Fh		; Compare Two Operands
//@ 		jnz	short loc_9CAF	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2838
//@ 		mov	MenuCode, 0FFFFh ; uint16_t
//@ ; #line	"PS10.PAS" 2839
//@ 		push	20h ; ' '
//@ 		call	SendServerPost	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2840
//@ 		mov	SERVER,	0	; bool
//@ ; #line	"PS10.PAS" 2841
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"PS10.PAS" 2842
//@ 		jmp	loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2843
//@ 
//@ loc_9CAF:				; CODE XREF: ProcessMenu+68Bj
//@ 		cmp	ax, 18h		; Compare Two Operands
//@ 		jnz	short loc_9CBC	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		mov	KbWait,	ax	; int16_t
//@ 		jmp	short loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2844
//@ 
//@ loc_9CBC:				; CODE XREF: ProcessMenu+6A8j
//@ 		cmp	ax, 1Ah		; Compare Two Operands
//@ 		jnz	short loc_9CDA	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2845
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		mov	Skill, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMode, ax	; int16_t
//@ ; #line	"PS10.PAS" 2846
//@ 		mov	MenuMainY, 4	; int16_t
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 2847
//@ 		jmp	short loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2848
//@ 
//@ loc_9CDA:				; CODE XREF: ProcessMenu+6B5j
//@ 		cmp	ax, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jnz	short loc_9CEB	; Jump if Not Zero (ZF=0)
//@ 		cmp	MenuMainY, 0	; int16_t
//@ 		jnz	short loc_9CE9	; Jump if Not Zero (ZF=0)
//@ 		call	MenuStartNet	; function near	PASCAL returns void
//@ 
//@ loc_9CE9:				; CODE XREF: ProcessMenu+6DAj
//@ 		jmp	short loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2849
//@ 
//@ loc_9CEB:				; CODE XREF: ProcessMenu+6D3j
//@ 		cmp	ax, 70h	; 'p'   ; Compare Two Operands
//@ 		jnz	short loc_9CFC	; Jump if Not Zero (ZF=0)
//@ 		cmp	MenuMainY, 0	; int16_t
//@ 		jnz	short loc_9CFA	; Jump if Not Zero (ZF=0)
//@ 		call	MenuJoinNet	; function near	PASCAL returns void
//@ 
//@ loc_9CFA:				; CODE XREF: ProcessMenu+6EBj
//@ 		jmp	short loc_9D39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2850
//@ 
//@ loc_9CFC:				; CODE XREF: ProcessMenu+6E4j
//@ 		cmp	ax, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_9D39	; Jump if Not Zero (ZF=0)
//@ 		cmp	MenuMainY, 0	; int16_t
//@ 		jnz	short loc_9D39	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2852
//@ 		mov	al, NGColor	; uint8_t
//@ 		mov	SelfColor, al	; uint8_t
//@ 		mov	di, offset NGNick ; char[9] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	al, SelfColor	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	[di-0FA0h], ax
//@ ; #line	"PS10.PAS" 2853
//@ 		mov	MenuMainY, 2	; int16_t
//@ 		mov	MenuMode, 0Bh	; int16_t
//@ ; #line	"PS10.PAS" 2857
//@ 
//@ loc_9D39:				; CODE XREF: ProcessMenu+417j
//@ 					; ProcessMenu:loc_9A6Bj ...
//@ 		cmp	key, 1		; uint8_t
//@ 		jz	short loc_9D43	; Jump if Zero (ZF=1)
//@ 		jmp	loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2858
//@ 
//@ loc_9D43:				; CODE XREF: ProcessMenu+734j
//@ 		mov	ax, MenuMode	; int16_t
//@ ; #line	"PS10.PAS" 2859
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jz	short loc_9D64	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jz	short loc_9D64	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Ch		; Compare Two Operands
//@ 		jz	short loc_9D64	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Dh		; Compare Two Operands
//@ 		jz	short loc_9D64	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jz	short loc_9D64	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Fh		; Compare Two Operands
//@ 		jnz	short loc_9D7A	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_9D64:				; CODE XREF: ProcessMenu+73Fj
//@ 					; ProcessMenu+744j ...
//@ 		mov	key, 0		; uint8_t
//@ 		mov	ax, MenuMode	; int16_t
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMode, ax	; int16_t
//@ 		jmp	loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2860
//@ 
//@ loc_9D7A:				; CODE XREF: ProcessMenu+758j
//@ 		cmp	ax, 18h		; Compare Two Operands
//@ 		jnz	short loc_9D98	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 0		; uint8_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		mov	MenuMode, 0Eh	; int16_t
//@ 		mov	KbWait,	0FFFFh	; int16_t
//@ 		jmp	loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2861
//@ 
//@ loc_9D98:				; CODE XREF: ProcessMenu+773j
//@ 		cmp	ax, 19h		; Compare Two Operands
//@ 		jnz	short loc_9DB0	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 0		; uint8_t
//@ 		mov	MenuMainY, 2	; int16_t
//@ 		mov	MenuMode, 0Eh	; int16_t
//@ 		jmp	short loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2862
//@ 
//@ loc_9DB0:				; CODE XREF: ProcessMenu+791j
//@ 		cmp	ax, 1Ah		; Compare Two Operands
//@ 		jnz	short loc_9DC8	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 0		; uint8_t
//@ 		mov	MenuMainY, 3	; int16_t
//@ 		mov	MenuMode, 0Eh	; int16_t
//@ 		jmp	short loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2863
//@ 
//@ loc_9DC8:				; CODE XREF: ProcessMenu+7A9j
//@ 		cmp	ax, 1Bh		; Compare Two Operands
//@ 		jnz	short loc_9DE0	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 0		; uint8_t
//@ 		mov	MenuMainY, 1	; int16_t
//@ 		mov	MenuMode, 0Eh	; int16_t
//@ 		jmp	short loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2864
//@ 
//@ loc_9DE0:				; CODE XREF: ProcessMenu+7C1j
//@ 		cmp	ax, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jnz	short loc_9DF8	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 0		; uint8_t
//@ 		mov	MenuMainY, 1	; int16_t
//@ 		mov	MenuMode, 0Bh	; int16_t
//@ 		jmp	short loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2865
//@ 
//@ loc_9DF8:				; CODE XREF: ProcessMenu+7D9j
//@ 		cmp	ax, 70h	; 'p'   ; Compare Two Operands
//@ 		jnz	short loc_9E0F	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 0		; uint8_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		mov	MenuMode, 0Bh	; int16_t
//@ 		jmp	short loc_9E25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2866
//@ 
//@ loc_9E0F:				; CODE XREF: ProcessMenu+7F1j
//@ 		cmp	ax, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_9E25	; Jump if Not Zero (ZF=0)
//@ 		mov	key, 0		; uint8_t
//@ 		mov	MenuMainY, 2	; int16_t
//@ 		mov	MenuMode, 0Bh	; int16_t
//@ ; #line	"PS10.PAS" 2869
//@ 
//@ loc_9E25:				; CODE XREF: ProcessMenu+736j
//@ 					; ProcessMenu+76Dj ...
//@ 		cmp	key, 1		; uint8_t
//@ 		jz	short locret_9E31 ; Jump if Zero (ZF=1)
//@ 		mov	key, 0		; uint8_t
//@ ; #line	"PS10.PAS" 2870
//@ 
//@ locret_9E31:				; CODE XREF: ProcessMenu+89j
//@ 					; ProcessMenu+820j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ProcessMenu	endp
//@ 
//@ ; #line	"PS10.PAS" 2876
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Build3dScene	proc far
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2878
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2879
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 822Eh
//@ 		push	di
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		push	0
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2880
//@ 		push	word ptr LinesBUF+2 ; TLinesBuf*
//@ 		push	0
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		push	PImBSeg		; uint16_t
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2882
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	FCount$0, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Nlines,	ax	; uint16_t
//@ ; #line	"PS10.PAS" 2884
//@ 		mov	ax, 1000h
//@ 		sub	ax, ehz		; int16_t
//@ 		mov	Hz2, ax		; uint16_t
//@ ; #line	"PS10.PAS" 2885
//@ 		mov	ax, Hz2		; uint16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	mysy, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2886
//@ 		mov	ax, Hz2		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		xor	cx, cx		; Logical Exclusive OR
//@ 		mov	bx, 8
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 800h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 200h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	word ptr EDI0, ax ; int32_t
//@ 		mov	word ptr EDI0+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 2887
//@ 		mov	ax, BLevel0	; uint16_t
//@ 		mov	BLevelW, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2890
//@ 		mov	ax, WallH	; uint16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	bx, ehz		; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	word ptr FloorV, ax ; int32_t
//@ 		mov	word ptr FloorV+2, dx ;	int32_t
//@ ; #line	"PS10.PAS" 2891
//@ 		mov	ax, WallH	; uint16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	bx, Hz2		; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	word ptr CellV,	ax ; int32_t
//@ 		mov	word ptr CellV+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 2892
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		mov	bx, ehz		; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, 1000h
//@ 		div	bx		; Unsigned Divide
//@ 		mov	BLevelF, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2893
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		mov	bx, Hz2		; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, 1000h
//@ 		div	bx		; Unsigned Divide
//@ 		mov	BlevelC, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2896
//@ 		mov	al, byte ptr ehx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMx, ax		; int16_t
//@ 		mov	al, byte ptr ehy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMy, ax		; int16_t
//@ ; #line	"PS10.PAS" 2897
//@ 		push	HMx		; int16_t
//@ 		push	HMy		; int16_t
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	mi, 1		; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	b0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 2898
//@ 
//@ loc_9F2A:				; CODE XREF: Build3dScene:loc_9FE1j
//@ 		cmp	b0, 2		; uint16_t
//@ 		jb	short loc_9F3B	; Jump if Below	(CF=1)
//@ 		cmp	mi, 4		; int16_t
//@ 		jl	short loc_9F3B	; Jump if Less (SF!=OF)
//@ 		jmp	loc_9FE4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2900
//@ 
//@ loc_9F3B:				; CODE XREF: Build3dScene+FCj
//@ 					; Build3dScene+103j
//@ 		mov	ax, Nlines	; uint16_t
//@ 		cmp	ax, WinW	; uint16_t
//@ 		jnz	short loc_9F48	; Jump if Not Zero (ZF=0)
//@ 		inc	b0		; uint16_t
//@ ; #line	"PS10.PAS" 2901
//@ 
//@ loc_9F48:				; CODE XREF: Build3dScene+10Fj
//@ 		mov	ax, HMx		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		mov	word ptr [bp+var_4+2], ax
//@ 		mov	ax, HMx		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jg	short loc_9F8D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_9F67	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9F63:				; CODE XREF: Build3dScene+158j
//@ 		inc	x$0		; int16_t
//@ 
//@ loc_9F67:				; CODE XREF: Build3dScene+12Ej
//@ 		push	x$0		; int16_t
//@ 		mov	ax, HMy		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		push	ax
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		push	x$0		; int16_t
//@ 		mov	ax, HMy		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		push	ax
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	ax, x$0		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jnz	short loc_9F63	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2902
//@ 
//@ loc_9F8D:				; CODE XREF: Build3dScene+129j
//@ 		mov	ax, HMy		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	word ptr [bp+var_4+2], ax
//@ 		mov	ax, HMy		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jg	short loc_9FD4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_9FAE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9FAA:				; CODE XREF: Build3dScene+19Fj
//@ 		inc	y		; int16_t
//@ 
//@ loc_9FAE:				; CODE XREF: Build3dScene+175j
//@ 		mov	ax, HMx		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		push	ax
//@ 		push	y		; int16_t
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	ax, HMx		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		push	ax
//@ 		push	y		; int16_t
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	ax, y		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jnz	short loc_9FAA	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2903
//@ 
//@ loc_9FD4:				; CODE XREF: Build3dScene+170j
//@ 		inc	mi		; int16_t
//@ ; #line	"PS10.PAS" 2904
//@ 		cmp	mi, 1Eh		; int16_t
//@ 		jle	short loc_9FE1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	short loc_9FE4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2905
//@ 
//@ loc_9FE1:				; CODE XREF: Build3dScene+1AAj
//@ 		jmp	loc_9F2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2907
//@ 
//@ loc_9FE4:				; CODE XREF: Build3dScene+105j
//@ 					; Build3dScene+1ACj
//@ 		mov	al, byte ptr ehx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMx, ax		; int16_t
//@ 		mov	al, byte ptr ehy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMy, ax		; int16_t
//@ 		mov	ax, mi		; int16_t
//@ 		add	ax, 3		; Add
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	MapR, ax	; int16_t
//@ ; #line	"PS10.PAS" 2909
//@ 		mov	ax, t1		; uint16_t
//@ 		add	MTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2910
//@ 		cmp	MTime, 0Ah	; uint16_t
//@ 		mov	al, 0
//@ 		jbe	short loc_A011	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_A011:				; CODE XREF: Build3dScene+1DBj
//@ 		mov	OAnimate, al	; bool
//@ ; #line	"PS10.PAS" 2911
//@ 		cmp	OAnimate, 0	; bool
//@ 		jz	short loc_A020	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2912
//@ 
//@ loc_A020:				; CODE XREF: Build3dScene+1E6j
//@ 		call	AnimateObjects	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2916
//@ 		call	CalcYMin	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2917
//@ 		call	BuildFloorCell	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2918
//@ 		call	StartPaint	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 2920
//@ 		cmp	FCount$0, 0	; uint16_t
//@ 		ja	short loc_A038	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_A0B9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2921
//@ 
//@ loc_A038:				; CODE XREF: Build3dScene+200j
//@ 		mov	ax, FCount$0	; uint16_t
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jl	short loc_A0B9	; Jump if Less (SF!=OF)
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_A049	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A045:				; CODE XREF: Build3dScene+284j
//@ 		dec	i		; int16_t
//@ ; #line	"PS10.PAS" 2922
//@ 
//@ loc_A049:				; CODE XREF: Build3dScene+210j
//@ 		imul	ax, i, 0Eh	; int16_t
//@ 		les	di, FramesList	; TFrame*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF2h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"PS10.PAS" 2923
//@ 		mov	al, es:[di+0Ah]
//@ ; #line	"PS10.PAS" 2924
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_A093	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_A093	; Jump if Above	(CF=0 &	ZF=0)
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandFrame	; function near	PASCAL returns void
//@ 		jmp	short loc_A0B2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2925
//@ 
//@ loc_A093:				; CODE XREF: Build3dScene+231j
//@ 					; Build3dScene+235j
//@ 		cmp	al, 7Ah	; 'z'   ; Compare Two Operands
//@ 		jnz	short loc_A0B2	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Expand3dObject	; function near	PASCAL returns void
//@ 
//@ loc_A0B2:				; CODE XREF: Build3dScene+25Ej
//@ 					; Build3dScene+262j
//@ 		cmp	i, 1		; int16_t
//@ 		jnz	short loc_A045	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2928
//@ 
//@ loc_A0B9:				; CODE XREF: Build3dScene+202j
//@ 					; Build3dScene+20Bj
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0Eh
//@ 		div	cx		; Unsigned Divide
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"PS10.PAS" 2929
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 822Eh
//@ 		push	di
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		push	1
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2930
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 88CCh
//@ 		push	di
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		push	1
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 2931
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ Build3dScene	endp
//@ 
//@ ; #line	"PS10.PAS" 2947
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SwitchToNextWeapon proc	near		; CODE XREF: ProcessDevices+465p
//@ 
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2948
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short locret_A189 ; Jump if Less or Equal (ZF=1	| SF!=OF)
//@ ; #line	"PS10.PAS" 2949
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_A120	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A11D:				; CODE XREF: SwitchToNextWeapon+8Dj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 2951
//@ 
//@ loc_A120:				; CODE XREF: SwitchToNextWeapon+21j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		inc	word ptr es:[di+48h] ; Increment by 1
//@ ; #line	"PS10.PAS" 2952
//@ 		mov	ax, WeaponsCount ; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+48h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_A13F	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_A148	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_A148	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_A13F:				; CODE XREF: SwitchToNextWeapon+3Dj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+48h], 1
//@ ; #line	"PS10.PAS" 2953
//@ 
//@ loc_A148:				; CODE XREF: SwitchToNextWeapon+3Fj
//@ 					; SwitchToNextWeapon+43j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+48h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+25h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jle	short loc_A183	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		jbe	short loc_A183	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 2956
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		jnz	short loc_A181	; Jump if Not Zero (ZF=0)
//@ 		mov	GunShift, 1	; uint16_t
//@ ; #line	"PS10.PAS" 2957
//@ 
//@ loc_A181:				; CODE XREF: SwitchToNextWeapon+7Fj
//@ 		jmp	short locret_A189 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2959
//@ 
//@ loc_A183:				; CODE XREF: SwitchToNextWeapon+6Bj
//@ 					; SwitchToNextWeapon+78j
//@ 		cmp	[bp+n],	8	; int16_t
//@ 		jnz	short loc_A11D	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 2960
//@ 
//@ locret_A189:				; CODE XREF: SwitchToNextWeapon+1Aj
//@ 					; SwitchToNextWeapon:loc_A181j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ SwitchToNextWeapon endp
//@ 
//@ ; #line	"PS10.PAS" 2982
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ WeaponAvail	proc near		; CODE XREF: ChangeWeapon+1Ep
//@ 					; ChangeWeapon+2Fp ...
//@ 
//@ WeaponAvail	= byte ptr -1		; bool
//@ W		= word ptr  4		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2983
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"PS10.PAS" 2984
//@ 		mov	ax, [bp+W]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+25h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jle	short loc_A1C1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+W]	; int16_t
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		ja	short loc_A1C5	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_A1C1:				; CODE XREF: WeaponAvail+28j
//@ 		mov	al, 0
//@ 		jmp	short loc_A1C7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A1C5:				; CODE XREF: WeaponAvail+34j
//@ 		mov	al, 1
//@ 
//@ loc_A1C7:				; CODE XREF: WeaponAvail+38j
//@ 		mov	[bp+WeaponAvail], al ; bool
//@ ; #line	"PS10.PAS" 2987
//@ 		mov	al, [bp+WeaponAvail] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ WeaponAvail	endp
//@ 
//@ ; #line	"PS10.PAS" 2991
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ChangeWeapon	proc near		; CODE XREF: ProcessDevices+60Fp
//@ 
//@ var_6		= dword	ptr -6
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 2992
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short locret_A25F ; Jump if Less or Equal (ZF=1	| SF!=OF)
//@ ; #line	"PS10.PAS" 2994
//@ 		push	2
//@ 		call	WeaponAvail	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_A1FE	; Jump if Zero (ZF=1)
//@ 		mov	i, 2		; int16_t
//@ 		jmp	short loc_A248	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2995
//@ 
//@ loc_A1FE:				; CODE XREF: ChangeWeapon+23j
//@ 		push	3
//@ 		call	WeaponAvail	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_A20F	; Jump if Zero (ZF=1)
//@ 		mov	i, 3		; int16_t
//@ 		jmp	short loc_A248	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2996
//@ 
//@ loc_A20F:				; CODE XREF: ChangeWeapon+34j
//@ 		push	5
//@ 		call	WeaponAvail	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_A220	; Jump if Zero (ZF=1)
//@ 		mov	i, 5		; int16_t
//@ 		jmp	short loc_A248	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2997
//@ 
//@ loc_A220:				; CODE XREF: ChangeWeapon+45j
//@ 		push	6
//@ 		call	WeaponAvail	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_A231	; Jump if Zero (ZF=1)
//@ 		mov	i, 6		; int16_t
//@ 		jmp	short loc_A248	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 2998
//@ 
//@ loc_A231:				; CODE XREF: ChangeWeapon+56j
//@ 		push	4
//@ 		call	WeaponAvail	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_A242	; Jump if Zero (ZF=1)
//@ 		mov	i, 4		; int16_t
//@ 		jmp	short loc_A248	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A242:				; CODE XREF: ChangeWeapon+67j
//@ 		mov	i, 1		; int16_t
//@ ; #line	"PS10.PAS" 3000
//@ 
//@ loc_A248:				; CODE XREF: ChangeWeapon+2Bj
//@ 					; ChangeWeapon+3Cj ...
//@ 		mov	ax, i		; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+48h], ax
//@ ; #line	"PS10.PAS" 3001
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		jnz	short locret_A25F ; Jump if Not	Zero (ZF=0)
//@ 		mov	GunShift, 1	; uint16_t
//@ ; #line	"PS10.PAS" 3003
//@ 
//@ locret_A25F:				; CODE XREF: ChangeWeapon+1Aj
//@ 					; ChangeWeapon+86j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ChangeWeapon	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aMouseLookIs	db 14,'Mouse look is '  ; DATA XREF: ProcessDevices+368o
//@ ; #line	"PS10.PAS" 3009
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessDevices	proc near		; CODE XREF: DoGame+37Dp
//@ 
//@ var_106		= byte ptr -106h
//@ var_A		= dword	ptr -0Ah
//@ _mlt		= byte ptr -5		; bool
//@ _ml		= byte ptr -4		; bool
//@ _chw		= byte ptr -3		; bool
//@ dv		= word ptr -2		; int16_t
//@ 
//@ 		enter	106h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3011
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 800h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jbe	short loc_A281	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_A281:				; CODE XREF: ProcessDevices+Ej
//@ 		mov	[bp+_ml], al	; bool
//@ ; #line	"PS10.PAS" 3012
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 1000h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jbe	short loc_A291	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_A291:				; CODE XREF: ProcessDevices+1Ej
//@ 		mov	[bp+_mlt], al	; bool
//@ ; #line	"PS10.PAS" 3013
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 100h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jbe	short loc_A2A1	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_A2A1:				; CODE XREF: ProcessDevices+2Ej
//@ 		mov	[bp+_chw], al	; bool
//@ ; #line	"PS10.PAS" 3014
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HksFlags, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3018
//@ 		cmp	Console, 0	; bool
//@ 		jnz	short loc_A2F5	; Jump if Not Zero (ZF=0)
//@ 		cmp	MenuOn,	0	; bool
//@ 		jnz	short loc_A2F5	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3020
//@ 		mov	al, _ViewUpOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di-13F2h]
//@ 		neg	al		; Two's Complement Negation
//@ 		sbb	al, al		; Integer Subtraction with Borrow
//@ 		neg	al		; Two's Complement Negation
//@ 		mov	kbViewUp, al	; bool
//@ ; #line	"PS10.PAS" 3021
//@ 		mov	al, _ViewDnOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di-13F2h]
//@ 		neg	al		; Two's Complement Negation
//@ 		sbb	al, al		; Integer Subtraction with Borrow
//@ 		neg	al		; Two's Complement Negation
//@ 		mov	kbViewDn, al	; bool
//@ ; #line	"PS10.PAS" 3022
//@ 		mov	al, _ViewCntrOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di-13F2h]
//@ 		neg	al		; Two's Complement Negation
//@ 		sbb	al, al		; Integer Subtraction with Borrow
//@ 		neg	al		; Two's Complement Negation
//@ 		mov	kbViewCntr, al	; bool
//@ ; #line	"PS10.PAS" 3023
//@ 		jmp	short loc_A2FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A2F5:				; CODE XREF: ProcessDevices+3Ej
//@ 					; ProcessDevices+45j
//@ 		mov	kbViewCntr, 0	; bool
//@ ; #line	"PS10.PAS" 3029
//@ 
//@ loc_A2FA:				; CODE XREF: ProcessDevices+83j
//@ 		cmp	Console, 0	; bool
//@ 		jz	short loc_A304	; Jump if Zero (ZF=1)
//@ 		jmp	loc_A44A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A304:				; CODE XREF: ProcessDevices+8Fj
//@ 		cmp	MenuOn,	0	; bool
//@ 		jz	short loc_A30E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_A44A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3031
//@ 
//@ loc_A30E:				; CODE XREF: ProcessDevices+99j
//@ 		mov	al, _FrontOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A320	; Jump if Zero (ZF=1)
//@ 		inc	HksFlags	; uint16_t
//@ ; #line	"PS10.PAS" 3032
//@ 
//@ loc_A320:				; CODE XREF: ProcessDevices+AAj
//@ 		mov	al, _BackOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A333	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 2	; uint16_t
//@ ; #line	"PS10.PAS" 3033
//@ 
//@ loc_A333:				; CODE XREF: ProcessDevices+BCj
//@ 		mov	al, _ChangOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A347	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 100h	; uint16_t
//@ ; #line	"PS10.PAS" 3034
//@ 
//@ loc_A347:				; CODE XREF: ProcessDevices+CFj
//@ 		mov	al, _JumpOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A35A	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 40h ;	'@' ; uint16_t
//@ ; #line	"PS10.PAS" 3036
//@ 
//@ loc_A35A:				; CODE XREF: ProcessDevices+E3j
//@ 		mov	al, _FireOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A375	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3037
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		jnz	short loc_A375	; Jump if Not Zero (ZF=0)
//@ 		add	HksFlags, 80h ;	'€' ; uint16_t
//@ ; #line	"PS10.PAS" 3039
//@ 
//@ loc_A375:				; CODE XREF: ProcessDevices+F6j
//@ 					; ProcessDevices+FDj
//@ 		mov	al, _SLeftOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A388	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 10h	; uint16_t
//@ ; #line	"PS10.PAS" 3040
//@ 
//@ loc_A388:				; CODE XREF: ProcessDevices+111j
//@ 		mov	al, _SRightOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A39B	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 20h ;	' ' ; uint16_t
//@ ; #line	"PS10.PAS" 3042
//@ 
//@ loc_A39B:				; CODE XREF: ProcessDevices+124j
//@ 		mov	al, _SpeedUpOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jnz	short loc_A3B0	; Jump if Not Zero (ZF=0)
//@ 		cmp	AlwaysRun, 0	; bool
//@ 		jz	short loc_A3B6	; Jump if Zero (ZF=1)
//@ 
//@ loc_A3B0:				; CODE XREF: ProcessDevices+137j
//@ 		add	HksFlags, 400h	; uint16_t
//@ ; #line	"PS10.PAS" 3043
//@ 
//@ loc_A3B6:				; CODE XREF: ProcessDevices+13Ej
//@ 		mov	al, _StrafeOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A3CA	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 200h	; uint16_t
//@ ; #line	"PS10.PAS" 3044
//@ 
//@ loc_A3CA:				; CODE XREF: ProcessDevices+152j
//@ 		mov	al, _MLookOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A3DE	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 800h	; uint16_t
//@ ; #line	"PS10.PAS" 3045
//@ 
//@ loc_A3DE:				; CODE XREF: ProcessDevices+166j
//@ 		mov	al, _MLookT	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A3F2	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 1000h	; uint16_t
//@ ; #line	"PS10.PAS" 3047
//@ 
//@ loc_A3F2:				; CODE XREF: ProcessDevices+17Aj
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 200h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_A424	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3049
//@ 		mov	al, _LeftOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A40F	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 10h	; uint16_t
//@ ; #line	"PS10.PAS" 3050
//@ 
//@ loc_A40F:				; CODE XREF: ProcessDevices+198j
//@ 		mov	al, _RightOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A422	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 20h ;	' ' ; uint16_t
//@ ; #line	"PS10.PAS" 3051
//@ 
//@ loc_A422:				; CODE XREF: ProcessDevices+1ABj
//@ 		jmp	short loc_A44A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3053
//@ 
//@ loc_A424:				; CODE XREF: ProcessDevices+18Aj
//@ 		mov	al, _LeftOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A437	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 4	; uint16_t
//@ ; #line	"PS10.PAS" 3054
//@ 
//@ loc_A437:				; CODE XREF: ProcessDevices+1C0j
//@ 		mov	al, _RightOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A44A	; Jump if Zero (ZF=1)
//@ 		add	HksFlags, 8	; uint16_t
//@ ; #line	"PS10.PAS" 3059
//@ 
//@ loc_A44A:				; CODE XREF: ProcessDevices+91j
//@ 					; ProcessDevices+9Bj ...
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di-0F96h], ax
//@ ; #line	"PS10.PAS" 3060
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di-0F94h], ax
//@ ; #line	"PS10.PAS" 3062
//@ 		cmp	MouseD,	0	; bool
//@ 		jnz	short loc_A471	; Jump if Not Zero (ZF=0)
//@ 		cmp	JoyStick, 0	; bool
//@ 		jnz	short loc_A471	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_A6C5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3064
//@ 
//@ loc_A471:				; CODE XREF: ProcessDevices+1F5j
//@ 					; ProcessDevices+1FCj
//@ 		call	GetMouseStatus	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3065
//@ 		call	GetJoyStatus	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3067
//@ 		mov	ax, Msvvi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, MsVV	; int16_t
//@ 		mov	Msvvi, ax	; int16_t
//@ ; #line	"PS10.PAS" 3068
//@ 		mov	ax, msrvi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, MsRv	; int16_t
//@ 		mov	msrvi, ax	; int16_t
//@ ; #line	"PS10.PAS" 3069
//@ 		imul	ax, t1,	3Ch	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Msvvi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_A4B4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_A4BC	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_A4BC	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_A4B4:				; CODE XREF: ProcessDevices+23Cj
//@ 		imul	ax, t1,	3Ch	; uint16_t
//@ 		mov	Msvvi, ax	; int16_t
//@ ; #line	"PS10.PAS" 3070
//@ 
//@ loc_A4BC:				; CODE XREF: ProcessDevices+23Ej
//@ 					; ProcessDevices+242j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0FFC4h
//@ 		mov	bx, 0FFFFh
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Msvvi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_A4DE	; Jump if Less (SF!=OF)
//@ 		jg	short loc_A4F1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_A4F1	; Jump if Not Below (CF=0)
//@ 
//@ loc_A4DE:				; CODE XREF: ProcessDevices+266j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0FFC4h
//@ 		mov	bx, 0FFFFh
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	Msvvi, ax	; int16_t
//@ ; #line	"PS10.PAS" 3071
//@ 
//@ loc_A4F1:				; CODE XREF: ProcessDevices+268j
//@ 					; ProcessDevices+26Cj
//@ 		imul	ax, t1,	78h	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, msrvi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_A50A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_A512	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_A512	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_A50A:				; CODE XREF: ProcessDevices+292j
//@ 		imul	ax, t1,	78h	; uint16_t
//@ 		mov	msrvi, ax	; int16_t
//@ ; #line	"PS10.PAS" 3072
//@ 
//@ loc_A512:				; CODE XREF: ProcessDevices+294j
//@ 					; ProcessDevices+298j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0FF88h
//@ 		mov	bx, 0FFFFh
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, msrvi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_A534	; Jump if Less (SF!=OF)
//@ 		jg	short loc_A547	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_A547	; Jump if Not Below (CF=0)
//@ 
//@ loc_A534:				; CODE XREF: ProcessDevices+2BCj
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0FF88h
//@ 		mov	bx, 0FFFFh
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	msrvi, ax	; int16_t
//@ ; #line	"PS10.PAS" 3074
//@ 
//@ loc_A547:				; CODE XREF: ProcessDevices+2BEj
//@ 					; ProcessDevices+2C2j
//@ 		cmp	Console, 0	; bool
//@ 		jnz	short loc_A5A9	; Jump if Not Zero (ZF=0)
//@ 		cmp	MenuOn,	0	; bool
//@ 		jnz	short loc_A5A9	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3076
//@ 		cmp	MsKeyA,	0	; bool
//@ 		jz	short loc_A571	; Jump if Zero (ZF=1)
//@ 		mov	al, Ms1ID	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		or	ax, HksFlags	; uint16_t
//@ 		mov	HksFlags, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3077
//@ 
//@ loc_A571:				; CODE XREF: ProcessDevices+2EAj
//@ 		cmp	MsKeyB,	0	; bool
//@ 		jz	short loc_A58D	; Jump if Zero (ZF=1)
//@ 		mov	al, Ms2ID	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		or	ax, HksFlags	; uint16_t
//@ 		mov	HksFlags, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3078
//@ 
//@ loc_A58D:				; CODE XREF: ProcessDevices+306j
//@ 		cmp	MsKeyC,	0	; bool
//@ 		jz	short loc_A5A9	; Jump if Zero (ZF=1)
//@ 		mov	al, ms3id	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		or	ax, HksFlags	; uint16_t
//@ 		mov	HksFlags, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3081
//@ 
//@ loc_A5A9:				; CODE XREF: ProcessDevices+2DCj
//@ 					; ProcessDevices+2E3j ...
//@ 		cmp	[bp+_ml], 0	; bool
//@ 		jnz	short loc_A60E	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 800h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_A60E	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3083
//@ 		cmp	MLookOn, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_A5C3	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_A5C3:				; CODE XREF: ProcessDevices+350j
//@ 		mov	MLookOn, al	; bool
//@ 		cmp	MLookOn, 0	; bool
//@ 		jnz	short loc_A5D2	; Jump if Not Zero (ZF=0)
//@ 		mov	VCenterMode, 1	; bool
//@ ; #line	"PS10.PAS" 3084
//@ 
//@ loc_A5D2:				; CODE XREF: ProcessDevices+35Bj
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMouseLookIs	; "Mouse look is "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	al, MLookOn	; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3085
//@ 		cmp	MessageRec.LTime+3Fh, 0	; struct MessageRec$Element[4]
//@ 		jnz	short loc_A60E	; Jump if Not Zero (ZF=0)
//@ 		mov	MessageRec.LTime, 0B4h ; '´' ; struct MessageRec$Element[4]
//@ ; #line	"PS10.PAS" 3088
//@ 
//@ loc_A60E:				; CODE XREF: ProcessDevices+33Dj
//@ 					; ProcessDevices+347j ...
//@ 		cmp	[bp+_mlt], 0	; bool
//@ 		jz	short loc_A623	; Jump if Zero (ZF=1)
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 1000h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_A623	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3089
//@ 		mov	VCenterMode, 1	; bool
//@ ; #line	"PS10.PAS" 3098
//@ 
//@ loc_A623:				; CODE XREF: ProcessDevices+3A2j
//@ 					; ProcessDevices+3ACj
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 1000h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		ja	short loc_A634	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	MLookOn, 0	; bool
//@ 		jz	short loc_A687	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3099
//@ 
//@ loc_A634:				; CODE XREF: ProcessDevices+3BBj
//@ 		cmp	MsVV, 0		; int16_t
//@ 		jz	short loc_A685	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3101
//@ 		cmp	ReverseMouse, 0	; bool
//@ 		jz	short loc_A654	; Jump if Zero (ZF=1)
//@ 		mov	ax, MsVV	; int16_t
//@ 		add	ax, 8		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		add	LookVz,	ax	; int16_t
//@ 		jmp	short loc_A664	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3102
//@ 
//@ loc_A654:				; CODE XREF: ProcessDevices+3D0j
//@ 		mov	ax, MsVV	; int16_t
//@ 		add	ax, 8		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		sub	LookVz,	ax	; int16_t
//@ ; #line	"PS10.PAS" 3103
//@ 
//@ loc_A664:				; CODE XREF: ProcessDevices+3E2j
//@ 		cmp	LookVz,	17Ch	; int16_t
//@ 		jle	short loc_A672	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	LookVz,	17Ch	; int16_t
//@ ; #line	"PS10.PAS" 3104
//@ 
//@ loc_A672:				; CODE XREF: ProcessDevices+3FAj
//@ 		cmp	LookVz,	0FE84h	; int16_t
//@ 		jge	short loc_A680	; Jump if Greater or Equal (SF=OF)
//@ 		mov	LookVz,	0FE84h	; int16_t
//@ ; #line	"PS10.PAS" 3105
//@ 
//@ loc_A680:				; CODE XREF: ProcessDevices+408j
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3106
//@ 
//@ loc_A685:				; CODE XREF: ProcessDevices+3C9j
//@ 		jmp	short loc_A6A2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3107
//@ 
//@ loc_A687:				; CODE XREF: ProcessDevices+3C2j
//@ 		cmp	MenuOn,	0	; bool
//@ 		jnz	short loc_A6A2	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, Msvvi	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 14h
//@ 		idiv	cx		; Signed Divide
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	[di-0F94h], ax
//@ ; #line	"PS10.PAS" 3109
//@ 
//@ loc_A6A2:				; CODE XREF: ProcessDevices:loc_A685j
//@ 					; ProcessDevices+41Cj
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 200h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_A6C5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 3110
//@ 		cmp	MenuOn,	0	; bool
//@ 		jnz	short loc_A6C5	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, msrvi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 10h
//@ 		idiv	cx		; Signed Divide
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	[di-0F96h], ax
//@ ; #line	"PS10.PAS" 3114
//@ 
//@ loc_A6C5:				; CODE XREF: ProcessDevices+1FEj
//@ 					; ProcessDevices+43Aj ...
//@ 		cmp	[bp+_chw], 0	; bool
//@ 		jnz	short loc_A6D8	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 100h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_A6D8	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 3115
//@ 		call	SwitchToNextWeapon ; function near PASCAL returns void
//@ ; #line	"PS10.PAS" 3120
//@ 
//@ loc_A6D8:				; CODE XREF: ProcessDevices+459j
//@ 					; ProcessDevices+463j
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_A6E6	; Jump if Zero (ZF=1)
//@ 		mov	[bp+dv], 8	; int16_t
//@ 		jmp	short loc_A6EB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A6E6:				; CODE XREF: ProcessDevices+46Dj
//@ 		mov	[bp+dv], 10h	; int16_t
//@ ; #line	"PS10.PAS" 3121
//@ 
//@ loc_A6EB:				; CODE XREF: ProcessDevices+474j
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 0Ch		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_A6FA	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HRv, ax		; int16_t
//@ ; #line	"PS10.PAS" 3123
//@ 
//@ loc_A6FA:				; CODE XREF: ProcessDevices+483j
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 4		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_A71C	; Jump if Zero (ZF=1)
//@ 		cmp	HRv, 0		; int16_t
//@ 		jle	short loc_A712	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HRv, ax		; int16_t
//@ 		jmp	short loc_A71C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A712:				; CODE XREF: ProcessDevices+499j
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		sub	HRv, ax		; int16_t
//@ ; #line	"PS10.PAS" 3124
//@ 
//@ loc_A71C:				; CODE XREF: ProcessDevices+492j
//@ 					; ProcessDevices+4A0j
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 8		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_A73E	; Jump if Zero (ZF=1)
//@ 		cmp	HRv, 0		; int16_t
//@ 		jge	short loc_A734	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HRv, ax		; int16_t
//@ 		jmp	short loc_A73E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A734:				; CODE XREF: ProcessDevices+4BBj
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	HRv, ax		; int16_t
//@ ; #line	"PS10.PAS" 3125
//@ 
//@ loc_A73E:				; CODE XREF: ProcessDevices+4B4j
//@ 					; ProcessDevices+4C2j
//@ 		cmp	HRv, 80h ; '€'  ; int16_t
//@ 		jle	short loc_A74C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	HRv, 80h ; '€'  ; int16_t
//@ 
//@ loc_A74C:				; CODE XREF: ProcessDevices+4D4j
//@ 		cmp	HRv, 0FF80h	; int16_t
//@ 		jge	short loc_A759	; Jump if Greater or Equal (SF=OF)
//@ 		mov	HRv, 0FF80h	; int16_t
//@ ; #line	"PS10.PAS" 3128
//@ 
//@ loc_A759:				; CODE XREF: ProcessDevices+4E1j
//@ 		cmp	HRv, 0		; int16_t
//@ 		jz	short loc_A7B6	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3129
//@ 		mov	al, _SpeedUpOn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-13F2h], 0 ; Compare Two Operands
//@ 		jz	short loc_A79C	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3130
//@ 		mov	ax, HRv		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 3
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		push	ax
//@ 		call	CalcDir		; function far PASCAL returns void
//@ 		jmp	short loc_A7B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A79C:				; CODE XREF: ProcessDevices+4FCj
//@ 		mov	ax, HRv		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	CalcDir		; function far PASCAL returns void
//@ 
//@ loc_A7B4:				; CODE XREF: ProcessDevices+52Aj
//@ 		jmp	short loc_A7BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3131
//@ 
//@ loc_A7B6:				; CODE XREF: ProcessDevices+4EEj
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3133
//@ 
//@ loc_A7BD:				; CODE XREF: ProcessDevices:loc_A7B4j
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 200h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_A7DE	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3134
//@ 		cmp	MouseD,	0	; bool
//@ 		jnz	short loc_A7D5	; Jump if Not Zero (ZF=0)
//@ 		cmp	JoyStick, 0	; bool
//@ 		jz	short loc_A7DE	; Jump if Zero (ZF=1)
//@ 
//@ loc_A7D5:				; CODE XREF: ProcessDevices+55Cj
//@ 		push	MsRv		; int16_t
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3138
//@ 
//@ loc_A7DE:				; CODE XREF: ProcessDevices+555j
//@ 					; ProcessDevices+563j
//@ 		cmp	kbViewCntr, 0	; bool
//@ 		jz	short loc_A7F1	; Jump if Zero (ZF=1)
//@ 		cmp	LookVz,	0	; int16_t
//@ 		jz	short loc_A7F1	; Jump if Zero (ZF=1)
//@ 		mov	VCenterMode, 1	; bool
//@ ; #line	"PS10.PAS" 3139
//@ 
//@ loc_A7F1:				; CODE XREF: ProcessDevices+573j
//@ 					; ProcessDevices+57Aj
//@ 		cmp	kbViewUp, 0	; bool
//@ 		jnz	short loc_A7FF	; Jump if Not Zero (ZF=0)
//@ 		cmp	kbViewDn, 0	; bool
//@ 		jz	short loc_A804	; Jump if Zero (ZF=1)
//@ 
//@ loc_A7FF:				; CODE XREF: ProcessDevices+586j
//@ 		mov	VCenterMode, 0	; bool
//@ ; #line	"PS10.PAS" 3140
//@ 
//@ loc_A804:				; CODE XREF: ProcessDevices+58Dj
//@ 		cmp	VCenterMode, 0	; bool
//@ 		jz	short loc_A810	; Jump if Zero (ZF=1)
//@ 		call	CenterView	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3142
//@ 
//@ loc_A810:				; CODE XREF: ProcessDevices+599j
//@ 		cmp	kbViewUp, 0	; bool
//@ 		jz	short loc_A821	; Jump if Zero (ZF=1)
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		add	LookVz,	ax	; int16_t
//@ ; #line	"PS10.PAS" 3143
//@ 
//@ loc_A821:				; CODE XREF: ProcessDevices+5A5j
//@ 		cmp	kbViewDn, 0	; bool
//@ 		jz	short loc_A832	; Jump if Zero (ZF=1)
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		sub	LookVz,	ax	; int16_t
//@ ; #line	"PS10.PAS" 3145
//@ 
//@ loc_A832:				; CODE XREF: ProcessDevices+5B6j
//@ 		cmp	LookVz,	17Ch	; int16_t
//@ 		jle	short loc_A840	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	LookVz,	17Ch	; int16_t
//@ ; #line	"PS10.PAS" 3146
//@ 
//@ loc_A840:				; CODE XREF: ProcessDevices+5C8j
//@ 		cmp	LookVz,	0FE84h	; int16_t
//@ 		jge	short loc_A84E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	LookVz,	0FE84h	; int16_t
//@ ; #line	"PS10.PAS" 3151
//@ 
//@ loc_A84E:				; CODE XREF: ProcessDevices+5D6j
//@ 		cmp	kbViewUp, 0	; bool
//@ 		jnz	short loc_A85C	; Jump if Not Zero (ZF=0)
//@ 		cmp	kbViewDn, 0	; bool
//@ 		jz	short loc_A861	; Jump if Zero (ZF=1)
//@ 
//@ loc_A85C:				; CODE XREF: ProcessDevices+5E3j
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3153
//@ 
//@ loc_A861:				; CODE XREF: ProcessDevices+5EAj
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"PS10.PAS" 3155
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		jnz	short loc_A882	; Jump if Not Zero (ZF=0)
//@ 		call	ChangeWeapon	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3156
//@ 
//@ loc_A882:				; CODE XREF: ProcessDevices+60Dj
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 80h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_A8B4	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 200h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_A8B4	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3157
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		jnz	short loc_A8B4	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3158
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		jbe	short loc_A8B4	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		add	HksFlags, 4000h	; uint16_t
//@ ; #line	"PS10.PAS" 3160
//@ 
//@ loc_A8B4:				; CODE XREF: ProcessDevices+61Aj
//@ 					; ProcessDevices+628j ...
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 400h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_A903	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 3
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	StepMove, ax	; int16_t
//@ 		jmp	short loc_A93C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3161
//@ 
//@ loc_A903:				; CODE XREF: ProcessDevices+64Cj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		add	StepMove, ax	; int16_t
//@ ; #line	"PS10.PAS" 3162
//@ 
//@ loc_A93C:				; CODE XREF: ProcessDevices+691j
//@ 		cmp	StepMove, 1800h	; int16_t
//@ 		jle	short loc_A997	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 3163
//@ 		sub	StepMove, 1800h	; int16_t
//@ ; #line	"PS10.PAS" 3164
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+0Eh]
//@ 		call	iswater		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_A971	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	0Ah
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_A997	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3165
//@ 
//@ loc_A971:				; CODE XREF: ProcessDevices+6F0j
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		and	ax, 400h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_A98A	; Jump if Not Zero (ZF=0)
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	0Eh
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_A997	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3166
//@ 
//@ loc_A98A:				; CODE XREF: ProcessDevices+709j
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	0Fh
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3169
//@ 
//@ loc_A997:				; CODE XREF: ProcessDevices+6D2j
//@ 					; ProcessDevices+6FFj ...
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_A9AF	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3170
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+20h], ax
//@ 		mov	ax, HFi		; uint16_t
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"PS10.PAS" 3172
//@ 
//@ loc_A9AF:				; CODE XREF: ProcessDevices+72Cj
//@ 		mov	ax, HRv		; int16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+16h], ax
//@ 		mov	ax, LookVz	; int16_t
//@ 		mov	es:[di+10h], ax
//@ ; #line	"PS10.PAS" 3174
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ProcessDevices	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aGamePaused_	db 12,'Game paused.'    ; DATA XREF: ProcessPreKeyboard+2Co
//@ aGameUnpaused_	db 14,'Game unpaused.'  ; DATA XREF: ProcessPreKeyboard:loc_AA1Bo
//@ a____0		db 4,' ...'             ; DATA XREF: ProcessPreKeyboard+16Do
//@ ; #line	"PS10.PAS" 3179
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessPreKeyboard proc	near		; CODE XREF: DoGame:loc_C542p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 3182
//@ 		cmp	key, 6Fh ; 'o'  ; uint8_t
//@ 		jnz	short loc_AA25	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3183
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_AA25	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_AA25	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3185
//@ 		cmp	Paused,	0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_AA05	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_AA05:				; CODE XREF: ProcessPreKeyboard+1Fj
//@ 		mov	Paused,	al	; bool
//@ ; #line	"PS10.PAS" 3186
//@ 		cmp	Paused,	0	; bool
//@ 		jz	short loc_AA1B	; Jump if Zero (ZF=1)
//@ 		mov	di, offset aGamePaused_	; "Game	paused."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ 		jmp	short loc_AA25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3187
//@ 
//@ loc_AA1B:				; CODE XREF: ProcessPreKeyboard+2Aj
//@ 		mov	di, offset aGameUnpaused_ ; "Game unpaused."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3191
//@ 
//@ loc_AA25:				; CODE XREF: ProcessPreKeyboard+8j
//@ 					; ProcessPreKeyboard+Fj ...
//@ 		cmp	MenuOn,	0	; bool
//@ 		jnz	short loc_AA3A	; Jump if Not Zero (ZF=0)
//@ 		cmp	Console, 0	; bool
//@ 		jnz	short loc_AA3A	; Jump if Not Zero (ZF=0)
//@ 		cmp	key, 0		; uint8_t
//@ 		jnz	short loc_AA3D	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_AA3A:				; CODE XREF: ProcessPreKeyboard+47j
//@ 					; ProcessPreKeyboard+4Ej
//@ 		jmp	locret_AB68	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3193
//@ 
//@ loc_AA3D:				; CODE XREF: ProcessPreKeyboard+55j
//@ 		mov	al, key		; uint8_t
//@ ; #line	"PS10.PAS" 3194
//@ 		cmp	al, 3Ch	; '<'   ; Compare Two Operands
//@ 		jnz	short loc_AA5F	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_AA5C	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3195
//@ 		mov	MenuOn,	1	; bool
//@ 		mov	MenuMode, 0Ch	; int16_t
//@ 		mov	ax, LoadSaveY	; uint16_t
//@ 		mov	MenuMainY, ax	; int16_t
//@ 
//@ loc_AA5C:				; CODE XREF: ProcessPreKeyboard+66j
//@ 		jmp	loc_AAFB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3196
//@ 
//@ loc_AA5F:				; CODE XREF: ProcessPreKeyboard+5Fj
//@ 		cmp	al, 3Dh	; '='   ; Compare Two Operands
//@ 		jnz	short loc_AA77	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuOn,	1	; bool
//@ 		mov	MenuMode, 0Dh	; int16_t
//@ 		mov	ax, LoadSaveY	; uint16_t
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	loc_AAFB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3197
//@ 
//@ loc_AA77:				; CODE XREF: ProcessPreKeyboard+7Ej
//@ 		cmp	al, 3Eh	; '>'   ; Compare Two Operands
//@ 		jnz	short loc_AA8D	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuOn,	1	; bool
//@ 		mov	MenuMode, 0Eh	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	short loc_AAFB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3198
//@ 
//@ loc_AA8D:				; CODE XREF: ProcessPreKeyboard+96j
//@ 		cmp	al, 3Fh	; '?'   ; Compare Two Operands
//@ 		jnz	short loc_AAA3	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuOn,	1	; bool
//@ 		mov	MenuMode, 0Bh	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		jmp	short loc_AAFB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3199
//@ 
//@ loc_AAA3:				; CODE XREF: ProcessPreKeyboard+ACj
//@ 		cmp	al, 42h	; 'B'   ; Compare Two Operands
//@ 		jnz	short loc_AAE7	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_AAB5	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_AAE5	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3201
//@ 
//@ loc_AAB5:				; CODE XREF: ProcessPreKeyboard+C9j
//@ 		cmp	Ranking, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_AABF	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_AABF:				; CODE XREF: ProcessPreKeyboard+D9j
//@ 		mov	Ranking, al	; bool
//@ ; #line	"PS10.PAS" 3202
//@ 		cmp	Ranking, 0	; bool
//@ 		jz	short loc_AAD8	; Jump if Zero (ZF=1)
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	5
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_AAE5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3203
//@ 
//@ loc_AAD8:				; CODE XREF: ProcessPreKeyboard+E4j
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	3
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3204
//@ 
//@ loc_AAE5:				; CODE XREF: ProcessPreKeyboard+D0j
//@ 					; ProcessPreKeyboard+F3j
//@ 		jmp	short loc_AAFB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3205
//@ 
//@ loc_AAE7:				; CODE XREF: ProcessPreKeyboard+C2j
//@ 		cmp	al, 44h	; 'D'   ; Compare Two Operands
//@ 		jnz	short loc_AAFB	; Jump if Not Zero (ZF=0)
//@ 		mov	MenuOn,	1	; bool
//@ 		mov	MenuMode, 0Fh	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 3207
//@ 
//@ loc_AAFB:				; CODE XREF: ProcessPreKeyboard:loc_AA5Cj
//@ 					; ProcessPreKeyboard+91j ...
//@ 		cmp	MenuOn,	0	; bool
//@ 		jz	short loc_AB0F	; Jump if Zero (ZF=1)
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	5
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3209
//@ 
//@ loc_AB0F:				; CODE XREF: ProcessPreKeyboard+11Dj
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short locret_AB68 ; Jump if Not	Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short locret_AB68 ; Jump if Not	Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short locret_AB68 ; Jump if Not	Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3210
//@ 		mov	al, key		; uint8_t
//@ ; #line	"PS10.PAS" 3211
//@ 		cmp	al, 40h	; '@'   ; Compare Two Operands
//@ 		jnz	short loc_AB3B	; Jump if Not Zero (ZF=0)
//@ 		push	LoadSaveY	; uint16_t
//@ 		call	SaveGame	; function far PASCAL returns void
//@ 		call	ScanSavedNames	; function far PASCAL returns void
//@ 		jmp	short locret_AB68 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3212
//@ 
//@ loc_AB3B:				; CODE XREF: ProcessPreKeyboard+146j
//@ 		cmp	al, 43h	; 'C'   ; Compare Two Operands
//@ 		jnz	short locret_AB68 ; Jump if Not	Zero (ZF=0)
//@ 		imul	ax, MenuMainY, 28h ; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 0F50h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset a____0 ; " ..."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short locret_AB68 ; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3213
//@ 		mov	al, byte ptr LoadSaveY ; uint16_t
//@ 		mov	LSMenuY, al	; uint8_t
//@ 		mov	MenuCode, 100h	; uint16_t
//@ ; #line	"PS10.PAS" 3215
//@ 
//@ locret_AB68:				; CODE XREF: ProcessPreKeyboard:loc_AA3Aj
//@ 					; ProcessPreKeyboard+131j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ProcessPreKeyboard endp
//@ 
//@ ; #line	"PS10.PAS" 3220
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetPFlags	proc near		; CODE XREF: MoveServerPlayers+629p
//@ 					; MoveServerPlayers+640p ...
//@ 
//@ PMask		= word ptr  4		; uint16_t
//@ PFlags		= dword	ptr  6		; uint16_t
//@ T		= dword	ptr  0Ah	; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 3221
//@ 		les	di, [bp+T]	; int16_t
//@ 		cmp	word ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_AB78	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_ABAE ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3222
//@ 
//@ loc_AB78:				; CODE XREF: SetPFlags+Aj
//@ 		les	di, [bp+T]	; int16_t
//@ 		cmp	word ptr es:[di], 0Ah ;	Compare	Two Operands
//@ 		jg	short loc_AB98	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 64h	; 'd'
//@ 		div	cx		; Unsigned Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		cmp	ax, 32h	; '2'   ; Compare Two Operands
//@ 		ja	short loc_AB98	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_ABA1	; Jump if Zero (ZF=1)
//@ 
//@ loc_AB98:				; CODE XREF: SetPFlags+15j
//@ 					; SetPFlags+25j
//@ 		mov	ax, [bp+PMask]	; uint16_t
//@ 		les	di, [bp+PFlags]	; uint16_t
//@ 		add	es:[di], ax	; Add
//@ ; #line	"PS10.PAS" 3223
//@ 
//@ loc_ABA1:				; CODE XREF: SetPFlags+2Cj
//@ 		cmp	NewSecond, 0	; bool
//@ 		jz	short locret_ABAE ; Jump if Zero (ZF=1)
//@ 		les	di, [bp+T]	; int16_t
//@ 		dec	word ptr es:[di] ; Decrement by	1
//@ ; #line	"PS10.PAS" 3224
//@ 
//@ locret_ABAE:				; CODE XREF: SetPFlags+Cj
//@ 					; SetPFlags+3Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ SetPFlags	endp
//@ 
//@ ; #line	"PS10.PAS" 3228
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MoveServerPlayers proc near		; CODE XREF: DoGame+3BDp
//@ 
//@ var_30		= word ptr -30h
//@ var_2E		= dword	ptr -2Eh
//@ Moved		= byte ptr -29h		; bool
//@ dt		= word ptr -28h		; int16_t
//@ dv		= word ptr -26h		; int16_t
//@ esa		= word ptr -24h		; real_t
//@ var_22		= word ptr -22h
//@ var_20		= word ptr -20h
//@ eca		= word ptr -1Eh		; real_t
//@ var_1C		= word ptr -1Ch
//@ var_1A		= word ptr -1Ah
//@ dy		= word ptr -18h		; real_t
//@ var_16		= word ptr -16h
//@ var_14		= word ptr -14h
//@ $dx		= word ptr -12h		; real_t
//@ var_10		= word ptr -10h
//@ var_E		= word ptr -0Eh
//@ ca		= word ptr -0Ch		; real_t
//@ var_A		= word ptr -0Ah
//@ var_8		= word ptr -8
//@ sa		= word ptr -6		; real_t
//@ var_4		= word ptr -4
//@ var_2		= word ptr -2
//@ 
//@ 		enter	30h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3229
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_ABC1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_ABBD:				; CODE XREF: MoveServerPlayers+92Ej
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_ABC1:				; CODE XREF: MoveServerPlayers+9j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2E], di
//@ 		mov	word ptr [bp+var_2E+2],	es
//@ ; #line	"PS10.PAS" 3230
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_ABDB	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_B4D9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_ABDB:				; CODE XREF: MoveServerPlayers+24j
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_ABE5	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_B4D9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3232
//@ 
//@ loc_ABE5:				; CODE XREF: MoveServerPlayers+2Ej
//@ 		mov	[bp+$dx], 0	; real_t
//@ 		mov	[bp+var_10], 0
//@ 		mov	[bp+var_E], 0
//@ 		mov	[bp+dy], 0	; real_t
//@ 		mov	[bp+var_16], 0
//@ 		mov	[bp+var_14], 0
//@ ; #line	"PS10.PAS" 3235
//@ 		mov	ax, es:[di+1Eh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	[bp+sa], ax	; real_t
//@ 		mov	[bp+var_4], bx
//@ 		mov	[bp+var_2], dx
//@ ; #line	"PS10.PAS" 3236
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+1Eh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	[bp+ca], ax	; real_t
//@ 		mov	[bp+var_A], bx
//@ 		mov	[bp+var_8], dx
//@ ; #line	"PS10.PAS" 3237
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 8Bh	; '‹'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	[bp+esa], ax	; real_t
//@ 		mov	[bp+var_22], bx
//@ 		mov	[bp+var_20], dx
//@ ; #line	"PS10.PAS" 3238
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 8Bh	; '‹'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	[bp+eca], ax	; real_t
//@ 		mov	[bp+var_1C], bx
//@ 		mov	[bp+var_1A], dx
//@ ; #line	"PS10.PAS" 3246
//@ 		mov	ax, t1		; uint16_t
//@ 		mov	[bp+var_30], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jle	short loc_AD17	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_B084	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AD17:				; CODE XREF: MoveServerPlayers+160j
//@ 		mov	[bp+dt], ax	; int16_t
//@ 		jmp	short loc_AD1F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AD1C:				; CODE XREF: MoveServerPlayers+4CFj
//@ 		inc	[bp+dt]		; int16_t
//@ ; #line	"PS10.PAS" 3248
//@ 
//@ loc_AD1F:				; CODE XREF: MoveServerPlayers+168j
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_AD2D	; Jump if Zero (ZF=1)
//@ 		mov	[bp+dv], 1	; int16_t
//@ 		jmp	short loc_AD4A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AD2D:				; CODE XREF: MoveServerPlayers+172j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_AD45	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+dv], 1	; int16_t
//@ 		jmp	short loc_AD4A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AD45:				; CODE XREF: MoveServerPlayers+18Aj
//@ 		mov	[bp+dv], 2	; int16_t
//@ ; #line	"PS10.PAS" 3250
//@ 
//@ loc_AD4A:				; CODE XREF: MoveServerPlayers+179j
//@ 					; MoveServerPlayers+191j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 3		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_AD93	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jz	short loc_AD93	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3251
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_AD7C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		sub	es:[di+12h], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jge	short loc_AD7A	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 
//@ loc_AD7A:				; CODE XREF: MoveServerPlayers+1C0j
//@ 		jmp	short loc_AD93	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3252
//@ 
//@ loc_AD7C:				; CODE XREF: MoveServerPlayers+1B2j
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+12h], ax	; Add
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_AD93	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ ; #line	"PS10.PAS" 3254
//@ 
//@ loc_AD93:				; CODE XREF: MoveServerPlayers+1A4j
//@ 					; MoveServerPlayers+1ABj ...
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_ADAB	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+dv], 1	; int16_t
//@ 		jmp	short loc_ADB0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_ADAB:				; CODE XREF: MoveServerPlayers+1F0j
//@ 		mov	[bp+dv], 2	; int16_t
//@ ; #line	"PS10.PAS" 3255
//@ 
//@ loc_ADB0:				; CODE XREF: MoveServerPlayers+1F7j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jle	short loc_ADD0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		sub	es:[di+1Ah], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jge	short loc_ADCE	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ 
//@ loc_ADCE:				; CODE XREF: MoveServerPlayers+214j
//@ 		jmp	short loc_ADE7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3256
//@ 
//@ loc_ADD0:				; CODE XREF: MoveServerPlayers+206j
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+1Ah], ax	; Add
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jle	short loc_ADE7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"PS10.PAS" 3258
//@ 
//@ loc_ADE7:				; CODE XREF: MoveServerPlayers:loc_ADCEj
//@ 					; MoveServerPlayers+22Dj
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_ADF5	; Jump if Zero (ZF=1)
//@ 		mov	[bp+dv], 1	; int16_t
//@ 		jmp	short loc_AE12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_ADF5:				; CODE XREF: MoveServerPlayers+23Aj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_AE0D	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+dv], 2	; int16_t
//@ 		jmp	short loc_AE12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AE0D:				; CODE XREF: MoveServerPlayers+252j
//@ 		mov	[bp+dv], 4	; int16_t
//@ ; #line	"PS10.PAS" 3260
//@ 
//@ loc_AE12:				; CODE XREF: MoveServerPlayers+241j
//@ 					; MoveServerPlayers+259j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 30h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_AE54	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3261
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jle	short loc_AE3D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		sub	es:[di+14h], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jge	short loc_AE3B	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 
//@ loc_AE3B:				; CODE XREF: MoveServerPlayers+281j
//@ 		jmp	short loc_AE54	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3262
//@ 
//@ loc_AE3D:				; CODE XREF: MoveServerPlayers+273j
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+14h], ax	; Add
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jle	short loc_AE54	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ ; #line	"PS10.PAS" 3264
//@ 
//@ loc_AE54:				; CODE XREF: MoveServerPlayers+26Cj
//@ 					; MoveServerPlayers:loc_AE3Bj ...
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_AE78	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jge	short loc_AE70	; Jump if Greater or Equal (SF=OF)
//@ 		add	word ptr es:[di+12h], 4	; Add
//@ 		jmp	short loc_AE78	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AE70:				; CODE XREF: MoveServerPlayers+2B5j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+12h], 2	; Add
//@ ; #line	"PS10.PAS" 3265
//@ 
//@ loc_AE78:				; CODE XREF: MoveServerPlayers+2AEj
//@ 					; MoveServerPlayers+2BCj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 2		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_AE9C	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_AE94	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	word ptr es:[di+12h], 4	; Integer Subtraction
//@ 		jmp	short loc_AE9C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AE94:				; CODE XREF: MoveServerPlayers+2D9j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		sub	word ptr es:[di+12h], 2	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3266
//@ 
//@ loc_AE9C:				; CODE XREF: MoveServerPlayers+2D2j
//@ 					; MoveServerPlayers+2E0j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 10h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_AEC0	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jle	short loc_AEB8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	word ptr es:[di+14h], 8	; Integer Subtraction
//@ 		jmp	short loc_AEC0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AEB8:				; CODE XREF: MoveServerPlayers+2FDj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		sub	word ptr es:[di+14h], 4	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3267
//@ 
//@ loc_AEC0:				; CODE XREF: MoveServerPlayers+2F6j
//@ 					; MoveServerPlayers+304j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 20h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_AEE4	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jge	short loc_AEDC	; Jump if Greater or Equal (SF=OF)
//@ 		add	word ptr es:[di+14h], 8	; Add
//@ 		jmp	short loc_AEE4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AEDC:				; CODE XREF: MoveServerPlayers+321j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+14h], 4	; Add
//@ ; #line	"PS10.PAS" 3269
//@ 
//@ loc_AEE4:				; CODE XREF: MoveServerPlayers+31Aj
//@ 					; MoveServerPlayers+328j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 400h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_AF31	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3271
//@ 		cmp	word ptr es:[di+12h], 30h ; '0' ; Compare Two Operands
//@ 		jle	short loc_AEFF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+12h], 30h ; '0'
//@ 
//@ loc_AEFF:				; CODE XREF: MoveServerPlayers+345j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0FFD0h ; Compare Two Operands
//@ 		jge	short loc_AF0F	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+12h], 0FFD0h
//@ ; #line	"PS10.PAS" 3272
//@ 
//@ loc_AF0F:				; CODE XREF: MoveServerPlayers+355j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 40h ; '@' ; Compare Two Operands
//@ 		jle	short loc_AF1F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+14h], 40h ; '@'
//@ 
//@ loc_AF1F:				; CODE XREF: MoveServerPlayers+365j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFC0h ; Compare Two Operands
//@ 		jge	short loc_AF2F	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+14h], 0FFC0h
//@ ; #line	"PS10.PAS" 3273
//@ 
//@ loc_AF2F:				; CODE XREF: MoveServerPlayers+375j
//@ 		jmp	short loc_AF71	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3275
//@ 
//@ loc_AF31:				; CODE XREF: MoveServerPlayers+33Ej
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 48h ; 'H' ; Compare Two Operands
//@ 		jle	short loc_AF41	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+12h], 48h ; 'H'
//@ 
//@ loc_AF41:				; CODE XREF: MoveServerPlayers+387j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0FFB8h ; Compare Two Operands
//@ 		jge	short loc_AF51	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+12h], 0FFB8h
//@ ; #line	"PS10.PAS" 3276
//@ 
//@ loc_AF51:				; CODE XREF: MoveServerPlayers+397j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 40h ; '@' ; Compare Two Operands
//@ 		jle	short loc_AF61	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+14h], 40h ; '@'
//@ 
//@ loc_AF61:				; CODE XREF: MoveServerPlayers+3A7j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFC0h ; Compare Two Operands
//@ 		jge	short loc_AF71	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+14h], 0FFC0h
//@ ; #line	"PS10.PAS" 3279
//@ 
//@ loc_AF71:				; CODE XREF: MoveServerPlayers:loc_AF2Fj
//@ 					; MoveServerPlayers+3B7j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+eca]	; real_t
//@ 		mov	si, [bp+var_1C]
//@ 		mov	di, [bp+var_1A]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+ca]	; real_t
//@ 		mov	si, [bp+var_A]
//@ 		mov	di, [bp+var_8]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+sa]	; real_t
//@ 		mov	si, [bp+var_4]
//@ 		mov	di, [bp+var_2]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+$dx]	; real_t
//@ 		mov	bx, [bp+var_10]
//@ 		mov	dx, [bp+var_E]
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		mov	[bp+$dx], ax	; real_t
//@ 		mov	[bp+var_10], bx
//@ 		mov	[bp+var_E], dx
//@ ; #line	"PS10.PAS" 3280
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+esa]	; real_t
//@ 		mov	si, [bp+var_22]
//@ 		mov	di, [bp+var_20]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+sa]	; real_t
//@ 		mov	si, [bp+var_4]
//@ 		mov	di, [bp+var_2]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+ca]	; real_t
//@ 		mov	si, [bp+var_A]
//@ 		mov	di, [bp+var_8]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+dy]	; real_t
//@ 		mov	bx, [bp+var_16]
//@ 		mov	dx, [bp+var_14]
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		mov	[bp+dy], ax	; real_t
//@ 		mov	[bp+var_16], bx
//@ 		mov	[bp+var_14], dx
//@ ; #line	"PS10.PAS" 3281
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jz	short loc_B084	; Jump if Zero (ZF=1)
//@ 		jmp	loc_AD1C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3283
//@ 
//@ loc_B084:				; CODE XREF: MoveServerPlayers+162j
//@ 					; MoveServerPlayers+4CDj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+42h]
//@ 		add	es:[di+12h], ax	; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+42h], ax
//@ ; #line	"PS10.PAS" 3284
//@ 		mov	ax, es:[di+40h]
//@ 		add	es:[di+14h], ax	; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+40h], ax
//@ ; #line	"PS10.PAS" 3288
//@ 		mov	di, offset n$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Eh]
//@ 		mov	ax, [bp+$dx]	; real_t
//@ 		mov	bx, [bp+var_10]
//@ 		mov	dx, [bp+var_E]
//@ 		mov	cx, 83h	; 'ƒ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 6000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Trunc$q4Real	; Trunc(x: Real): Longint{DX:AX}
//@ 		push	ax
//@ 		mov	ax, [bp+dy]	; real_t
//@ 		mov	bx, [bp+var_16]
//@ 		mov	dx, [bp+var_14]
//@ 		mov	cx, 83h	; 'ƒ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 6000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Trunc$q4Real	; Trunc(x: Real): Longint{DX:AX}
//@ 		push	ax
//@ 		push	1
//@ 		call	MoveOn		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3293
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+22h], ax	; Add
//@ ; #line	"PS10.PAS" 3295
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jg	short loc_B137	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, es:[di+16h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 14h		; Compare Two Operands
//@ 		jg	short loc_B137	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	al, 0
//@ 		jmp	short loc_B139	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B137:				; CODE XREF: MoveServerPlayers+571j
//@ 					; MoveServerPlayers+57Fj
//@ 		mov	al, 1
//@ 
//@ loc_B139:				; CODE XREF: MoveServerPlayers+583j
//@ 		mov	[bp+Moved], al	; bool
//@ ; #line	"PS10.PAS" 3296
//@ 		cmp	[bp+Moved], 0	; bool
//@ 		jz	short loc_B15F	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3297
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+24h]
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jz	short loc_B151	; Jump if Zero (ZF=1)
//@ 		cmp	al, 7		; Compare Two Operands
//@ 		jnz	short loc_B15F	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_B151:				; CODE XREF: MoveServerPlayers+599j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		mov	byte ptr es:[di+24h], 6
//@ ; #line	"PS10.PAS" 3302
//@ 
//@ loc_B15F:				; CODE XREF: MoveServerPlayers+58Ej
//@ 					; MoveServerPlayers+59Dj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+24h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-4090h]
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+22h]	; Compare Two Operands
//@ 		ja	short loc_B1BC	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 3304
//@ 		mov	al, es:[di+24h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-4090h]
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+22h], ax	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3305
//@ 		cmp	[bp+Moved], 0	; bool
//@ 		jz	short loc_B19B	; Jump if Zero (ZF=1)
//@ 		mov	byte ptr es:[di+24h], 0
//@ 		jmp	short loc_B1BC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3306
//@ 
//@ loc_B19B:				; CODE XREF: MoveServerPlayers+5E0j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+24h]
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_B1AA	; Jump if Zero (ZF=1)
//@ 		cmp	al, 6		; Compare Two Operands
//@ 		jnz	short loc_B1B4	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_B1AA:				; CODE XREF: MoveServerPlayers+5F2j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+24h], 7
//@ 		jmp	short loc_B1BC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B1B4:				; CODE XREF: MoveServerPlayers+5F6j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+24h], 2
//@ ; #line	"PS10.PAS" 3309
//@ 
//@ loc_B1BC:				; CODE XREF: MoveServerPlayers+5C5j
//@ 					; MoveServerPlayers+5E7j ...
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 0FFF0h	; Logical AND
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"PS10.PAS" 3310
//@ 		add	di, 4Eh	; 'N'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 2Ah	; '*'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	1
//@ 		call	SetPFlags	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3311
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 50h	; 'P'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 2Ah	; '*'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		call	SetPFlags	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3312
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 52h	; 'R'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 2Ah	; '*'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	4
//@ 		call	SetPFlags	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3316
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	4Eh ; 'N'
//@ 		mov	di, offset LandZ ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset CeilZ ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetLandHeight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3318
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 40h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_B248	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3319
//@ 		cmp	word ptr es:[di+18h], 0	; Compare Two Operands
//@ 		jnz	short loc_B248	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 0FEFFh	; Logical AND
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"PS10.PAS" 3320
//@ 
//@ loc_B248:				; CODE XREF: MoveServerPlayers+682j
//@ 					; MoveServerPlayers+689j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 80h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_B261	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 0FDFFh	; Logical AND
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"PS10.PAS" 3322
//@ 
//@ loc_B261:				; CODE XREF: MoveServerPlayers+6A2j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 40h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_B2DD	; Jump if Zero (ZF=1)
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 100h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_B2DD	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, LandZ	; int16_t
//@ 		cmp	ax, es:[di+0Eh]	; Compare Two Operands
//@ 		jnz	short loc_B2DD	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3323
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 300h	; Add
//@ 		cmp	ax, CeilZ	; int16_t
//@ 		jge	short loc_B2B6	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 3325
//@ 		inc	word ptr es:[di+0Eh] ; Increment by 1
//@ 		mov	word ptr es:[di+18h], 2Ah ; '*'
//@ 		mov	ax, es:[di+2Ah]
//@ 		or	ax, 100h	; Logical Inclusive OR
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"PS10.PAS" 3326
//@ 		push	0FFFFh
//@ 		push	0FFFFh
//@ 		push	n$0		; int16_t
//@ 		push	0Ch
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3327
//@ 		jmp	short loc_B2DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3329
//@ 
//@ loc_B2B6:				; CODE XREF: MoveServerPlayers+6DCj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+0Eh] ; Increment by 1
//@ 		mov	word ptr es:[di+18h], 10h
//@ 		mov	ax, es:[di+2Ah]
//@ 		or	ax, 100h	; Logical Inclusive OR
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"PS10.PAS" 3330
//@ 		push	0FFFFh
//@ 		push	0FFFFh
//@ 		push	n$0		; int16_t
//@ 		push	0Dh
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3333
//@ 
//@ loc_B2DD:				; CODE XREF: MoveServerPlayers+6BBj
//@ 					; MoveServerPlayers+6C6j ...
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 400h	; Add
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jge	short loc_B2F4	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+0Eh]
//@ 		mov	LandZ, ax	; int16_t
//@ ; #line	"PS10.PAS" 3335
//@ 
//@ loc_B2F4:				; CODE XREF: MoveServerPlayers+739j
//@ 		mov	ax, t1		; uint16_t
//@ 		mov	[bp+var_30], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jle	short loc_B305	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_B401	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B305:				; CODE XREF: MoveServerPlayers+74Ej
//@ 		mov	[bp+dt], ax	; int16_t
//@ 		jmp	short loc_B30D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B30A:				; CODE XREF: MoveServerPlayers+84Cj
//@ 		inc	[bp+dt]		; int16_t
//@ ; #line	"PS10.PAS" 3336
//@ 
//@ loc_B30D:				; CODE XREF: MoveServerPlayers+756j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jnz	short loc_B31D	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_B3ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3338
//@ 
//@ loc_B31D:				; CODE XREF: MoveServerPlayers+766j
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jge	short loc_B34E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 3340
//@ 		add	word ptr es:[di+18h], 4	; Add
//@ 		mov	ax, es:[di+18h]
//@ 		add	es:[di+0Eh], ax	; Add
//@ ; #line	"PS10.PAS" 3341
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jle	short loc_B34B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, LandZ	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ ; #line	"PS10.PAS" 3342
//@ 
//@ loc_B34B:				; CODE XREF: MoveServerPlayers+78Aj
//@ 		jmp	loc_B3EB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3345
//@ 
//@ loc_B34E:				; CODE XREF: MoveServerPlayers+773j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+18h], 0	; Compare Two Operands
//@ 		jle	short loc_B369	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 100h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_B369	; Jump if Not Zero (ZF=0)
//@ 		mov	word ptr es:[di+18h], 0FFFEh
//@ ; #line	"PS10.PAS" 3346
//@ 
//@ loc_B369:				; CODE XREF: MoveServerPlayers+7A4j
//@ 					; MoveServerPlayers+7AFj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		dec	word ptr es:[di+18h] ; Decrement by 1
//@ 		mov	ax, es:[di+18h]
//@ 		add	es:[di+0Eh], ax	; Add
//@ ; #line	"PS10.PAS" 3347
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, CeilZ	; int16_t
//@ 		jle	short loc_B3A0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, CeilZ	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ 		cmp	word ptr es:[di+18h], 0	; Compare Two Operands
//@ 		jle	short loc_B3A0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+18h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+18h], ax
//@ ; #line	"PS10.PAS" 3348
//@ 
//@ loc_B3A0:				; CODE XREF: MoveServerPlayers+7CEj
//@ 					; MoveServerPlayers+7DCj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jge	short loc_B3EB	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 3350
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	LandZ		; int16_t
//@ 		call	iswater		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_B3CA	; Jump if Zero (ZF=1)
//@ 		mov	w, 9		; uint16_t
//@ 		jmp	short loc_B3D0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B3CA:				; CODE XREF: MoveServerPlayers+80Ej
//@ 		mov	w, 0Eh		; uint16_t
//@ ; #line	"PS10.PAS" 3351
//@ 
//@ loc_B3D0:				; CODE XREF: MoveServerPlayers+816j
//@ 		mov	ax, LandZ	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"PS10.PAS" 3352
//@ 		push	0FFFFh
//@ 		push	0FFFFh
//@ 		push	n$0		; int16_t
//@ 		push	w		; uint16_t
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3355
//@ 
//@ loc_B3EB:				; CODE XREF: MoveServerPlayers:loc_B34Bj
//@ 					; MoveServerPlayers+7F9j
//@ 		jmp	short loc_B3F6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B3ED:				; CODE XREF: MoveServerPlayers+768j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ 
//@ loc_B3F6:				; CODE XREF: MoveServerPlayers:loc_B3EBj
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jz	short loc_B401	; Jump if Zero (ZF=1)
//@ 		jmp	loc_B30A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3357
//@ 
//@ loc_B401:				; CODE XREF: MoveServerPlayers+750j
//@ 					; MoveServerPlayers+84Aj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 600h	; Add
//@ 		mov	es:[di+3Ch], ax
//@ ; #line	"PS10.PAS" 3358
//@ 		mov	ax, es:[di+1Eh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 87h	; '‡'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 89h	; '‰'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3Ah], ax
//@ ; #line	"PS10.PAS" 3359
//@ 		mov	ax, es:[di+1Eh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	cx, 87h	; '‡'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 89h	; '‰'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+38h], ax
//@ ; #line	"PS10.PAS" 3360
//@ 		mov	ax, es:[di+3Ch]
//@ 		mov	di, es:[di+48h]
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		sub	ax, [di-1BBEh]	; Integer Subtraction
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3Eh], ax
//@ ; #line	"PS10.PAS" 3362
//@ 
//@ loc_B4D9:				; CODE XREF: MoveServerPlayers+26j
//@ 					; MoveServerPlayers+30j
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short locret_B4E3 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_ABBD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3363
//@ 
//@ locret_B4E3:				; CODE XREF: MoveServerPlayers+92Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ MoveServerPlayers endp
//@ 
//@ ; #line	"PS10.PAS" 3368
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CorrectPlayerPosition proc near		; CODE XREF: DoGame+416p
//@ 
//@ var_30		= word ptr -30h
//@ var_2E		= dword	ptr -2Eh
//@ Moved		= byte ptr -29h		; bool
//@ dt		= word ptr -28h		; int16_t
//@ dv		= word ptr -26h		; int16_t
//@ ca		= word ptr -24h		; real_t
//@ var_22		= word ptr -22h
//@ var_20		= word ptr -20h
//@ sa		= word ptr -1Eh		; real_t
//@ var_1C		= word ptr -1Ch
//@ var_1A		= word ptr -1Ah
//@ esa		= word ptr -18h		; real_t
//@ var_16		= word ptr -16h
//@ var_14		= word ptr -14h
//@ eca		= word ptr -12h		; real_t
//@ var_10		= word ptr -10h
//@ var_E		= word ptr -0Eh
//@ dy		= word ptr -0Ch		; real_t
//@ var_A		= word ptr -0Ah
//@ var_8		= word ptr -8
//@ $dx		= word ptr -6		; real_t
//@ var_4		= word ptr -4
//@ var_2		= word ptr -2
//@ T1		= word ptr  4		; int16_t
//@ 
//@ 		enter	30h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3369
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_B4F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B4F0:				; CODE XREF: CorrectPlayerPosition+6E9j
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 3370
//@ 
//@ loc_B4F4:				; CODE XREF: CorrectPlayerPosition+9j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2E], di
//@ 		mov	word ptr [bp+var_2E+2],	es
//@ ; #line	"PS10.PAS" 3371
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_B50E	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_BBC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B50E:				; CODE XREF: CorrectPlayerPosition+24j
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_B518	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_BBC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3373
//@ 
//@ loc_B518:				; CODE XREF: CorrectPlayerPosition+2Ej
//@ 		mov	[bp+$dx], 0	; real_t
//@ 		mov	[bp+var_4], 0
//@ 		mov	[bp+var_2], 0
//@ 		mov	[bp+dy], 0	; real_t
//@ 		mov	[bp+var_A], 0
//@ 		mov	[bp+var_8], 0
//@ ; #line	"PS10.PAS" 3374
//@ 		mov	ax, es:[di+1Eh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	[bp+sa], ax	; real_t
//@ 		mov	[bp+var_1C], bx
//@ 		mov	[bp+var_1A], dx
//@ ; #line	"PS10.PAS" 3375
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+1Eh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	[bp+ca], ax	; real_t
//@ 		mov	[bp+var_22], bx
//@ 		mov	[bp+var_20], dx
//@ ; #line	"PS10.PAS" 3376
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 8Bh	; '‹'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	[bp+esa], ax	; real_t
//@ 		mov	[bp+var_16], bx
//@ 		mov	[bp+var_14], dx
//@ ; #line	"PS10.PAS" 3377
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 8Bh	; '‹'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	[bp+eca], ax	; real_t
//@ 		mov	[bp+var_10], bx
//@ 		mov	[bp+var_E], dx
//@ ; #line	"PS10.PAS" 3382
//@ 		mov	ax, [bp+T1]	; int16_t
//@ 		mov	[bp+var_30], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jle	short loc_B64A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_B99B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B64A:				; CODE XREF: CorrectPlayerPosition+160j
//@ 		mov	[bp+dt], ax	; int16_t
//@ 		jmp	short loc_B652	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B64F:				; CODE XREF: CorrectPlayerPosition+4B3j
//@ 		inc	[bp+dt]		; int16_t
//@ ; #line	"PS10.PAS" 3384
//@ 
//@ loc_B652:				; CODE XREF: CorrectPlayerPosition+168j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_B66A	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+dv], 1	; int16_t
//@ 		jmp	short loc_B66F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B66A:				; CODE XREF: CorrectPlayerPosition+17Cj
//@ 		mov	[bp+dv], 2	; int16_t
//@ ; #line	"PS10.PAS" 3385
//@ 
//@ loc_B66F:				; CODE XREF: CorrectPlayerPosition+183j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 3		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_B6B8	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jz	short loc_B6B8	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3386
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_B6A1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		sub	es:[di+12h], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jge	short loc_B69F	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 
//@ loc_B69F:				; CODE XREF: CorrectPlayerPosition+1B2j
//@ 		jmp	short loc_B6B8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3387
//@ 
//@ loc_B6A1:				; CODE XREF: CorrectPlayerPosition+1A4j
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+12h], ax	; Add
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_B6B8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ ; #line	"PS10.PAS" 3389
//@ 
//@ loc_B6B8:				; CODE XREF: CorrectPlayerPosition+196j
//@ 					; CorrectPlayerPosition+19Dj ...
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_B6D0	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+dv], 1	; int16_t
//@ 		jmp	short loc_B6D5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B6D0:				; CODE XREF: CorrectPlayerPosition+1E2j
//@ 		mov	[bp+dv], 2	; int16_t
//@ ; #line	"PS10.PAS" 3390
//@ 
//@ loc_B6D5:				; CODE XREF: CorrectPlayerPosition+1E9j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jle	short loc_B6F5	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		sub	es:[di+1Ah], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jge	short loc_B6F3	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ 
//@ loc_B6F3:				; CODE XREF: CorrectPlayerPosition+206j
//@ 		jmp	short loc_B70C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3391
//@ 
//@ loc_B6F5:				; CODE XREF: CorrectPlayerPosition+1F8j
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+1Ah], ax	; Add
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jle	short loc_B70C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"PS10.PAS" 3393
//@ 
//@ loc_B70C:				; CODE XREF: CorrectPlayerPosition:loc_B6F3j
//@ 					; CorrectPlayerPosition+21Fj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_B724	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+dv], 2	; int16_t
//@ 		jmp	short loc_B729	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B724:				; CODE XREF: CorrectPlayerPosition+236j
//@ 		mov	[bp+dv], 4	; int16_t
//@ ; #line	"PS10.PAS" 3394
//@ 
//@ loc_B729:				; CODE XREF: CorrectPlayerPosition+23Dj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 30h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_B76B	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3395
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jle	short loc_B754	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		sub	es:[di+14h], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jge	short loc_B752	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 
//@ loc_B752:				; CODE XREF: CorrectPlayerPosition+265j
//@ 		jmp	short loc_B76B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3396
//@ 
//@ loc_B754:				; CODE XREF: CorrectPlayerPosition+257j
//@ 		mov	ax, [bp+dv]	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+14h], ax	; Add
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jle	short loc_B76B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ ; #line	"PS10.PAS" 3403
//@ 
//@ loc_B76B:				; CODE XREF: CorrectPlayerPosition+250j
//@ 					; CorrectPlayerPosition:loc_B752j ...
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_B78F	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jge	short loc_B787	; Jump if Greater or Equal (SF=OF)
//@ 		add	word ptr es:[di+12h], 4	; Add
//@ 		jmp	short loc_B78F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B787:				; CODE XREF: CorrectPlayerPosition+299j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+12h], 2	; Add
//@ ; #line	"PS10.PAS" 3404
//@ 
//@ loc_B78F:				; CODE XREF: CorrectPlayerPosition+292j
//@ 					; CorrectPlayerPosition+2A0j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 2		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_B7B3	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_B7AB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	word ptr es:[di+12h], 4	; Integer Subtraction
//@ 		jmp	short loc_B7B3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B7AB:				; CODE XREF: CorrectPlayerPosition+2BDj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		sub	word ptr es:[di+12h], 2	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3405
//@ 
//@ loc_B7B3:				; CODE XREF: CorrectPlayerPosition+2B6j
//@ 					; CorrectPlayerPosition+2C4j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 10h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_B7D7	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jle	short loc_B7CF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	word ptr es:[di+14h], 8	; Integer Subtraction
//@ 		jmp	short loc_B7D7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B7CF:				; CODE XREF: CorrectPlayerPosition+2E1j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		sub	word ptr es:[di+14h], 4	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3406
//@ 
//@ loc_B7D7:				; CODE XREF: CorrectPlayerPosition+2DAj
//@ 					; CorrectPlayerPosition+2E8j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 20h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_B7FB	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jge	short loc_B7F3	; Jump if Greater or Equal (SF=OF)
//@ 		add	word ptr es:[di+14h], 8	; Add
//@ 		jmp	short loc_B7FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B7F3:				; CODE XREF: CorrectPlayerPosition+305j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+14h], 4	; Add
//@ ; #line	"PS10.PAS" 3408
//@ 
//@ loc_B7FB:				; CODE XREF: CorrectPlayerPosition+2FEj
//@ 					; CorrectPlayerPosition+30Cj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 400h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_B848	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3410
//@ 		cmp	word ptr es:[di+12h], 30h ; '0' ; Compare Two Operands
//@ 		jle	short loc_B816	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+12h], 30h ; '0'
//@ 
//@ loc_B816:				; CODE XREF: CorrectPlayerPosition+329j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0FFD0h ; Compare Two Operands
//@ 		jge	short loc_B826	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+12h], 0FFD0h
//@ ; #line	"PS10.PAS" 3411
//@ 
//@ loc_B826:				; CODE XREF: CorrectPlayerPosition+339j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 40h ; '@' ; Compare Two Operands
//@ 		jle	short loc_B836	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+14h], 40h ; '@'
//@ 
//@ loc_B836:				; CODE XREF: CorrectPlayerPosition+349j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFC0h ; Compare Two Operands
//@ 		jge	short loc_B846	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+14h], 0FFC0h
//@ ; #line	"PS10.PAS" 3412
//@ 
//@ loc_B846:				; CODE XREF: CorrectPlayerPosition+359j
//@ 		jmp	short loc_B888	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3414
//@ 
//@ loc_B848:				; CODE XREF: CorrectPlayerPosition+322j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 48h ; 'H' ; Compare Two Operands
//@ 		jle	short loc_B858	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+12h], 48h ; 'H'
//@ 
//@ loc_B858:				; CODE XREF: CorrectPlayerPosition+36Bj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0FFB8h ; Compare Two Operands
//@ 		jge	short loc_B868	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+12h], 0FFB8h
//@ ; #line	"PS10.PAS" 3415
//@ 
//@ loc_B868:				; CODE XREF: CorrectPlayerPosition+37Bj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 40h ; '@' ; Compare Two Operands
//@ 		jle	short loc_B878	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+14h], 40h ; '@'
//@ 
//@ loc_B878:				; CODE XREF: CorrectPlayerPosition+38Bj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFC0h ; Compare Two Operands
//@ 		jge	short loc_B888	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+14h], 0FFC0h
//@ ; #line	"PS10.PAS" 3419
//@ 
//@ loc_B888:				; CODE XREF: CorrectPlayerPosition:loc_B846j
//@ 					; CorrectPlayerPosition+39Bj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+eca]	; real_t
//@ 		mov	si, [bp+var_10]
//@ 		mov	di, [bp+var_E]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+ca]	; real_t
//@ 		mov	si, [bp+var_22]
//@ 		mov	di, [bp+var_20]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+sa]	; real_t
//@ 		mov	si, [bp+var_1C]
//@ 		mov	di, [bp+var_1A]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+$dx]	; real_t
//@ 		mov	bx, [bp+var_4]
//@ 		mov	dx, [bp+var_2]
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		mov	[bp+$dx], ax	; real_t
//@ 		mov	[bp+var_4], bx
//@ 		mov	[bp+var_2], dx
//@ ; #line	"PS10.PAS" 3420
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+esa]	; real_t
//@ 		mov	si, [bp+var_16]
//@ 		mov	di, [bp+var_14]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+sa]	; real_t
//@ 		mov	si, [bp+var_1C]
//@ 		mov	di, [bp+var_1A]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+ca]	; real_t
//@ 		mov	si, [bp+var_22]
//@ 		mov	di, [bp+var_20]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+dy]	; real_t
//@ 		mov	bx, [bp+var_A]
//@ 		mov	dx, [bp+var_8]
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		mov	[bp+dy], ax	; real_t
//@ 		mov	[bp+var_A], bx
//@ 		mov	[bp+var_8], dx
//@ ; #line	"PS10.PAS" 3421
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jz	short loc_B99B	; Jump if Zero (ZF=1)
//@ 		jmp	loc_B64F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3428
//@ 
//@ loc_B99B:				; CODE XREF: CorrectPlayerPosition+162j
//@ 					; CorrectPlayerPosition+4B1j
//@ 		mov	di, offset n$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Eh]
//@ 		mov	ax, [bp+$dx]	; real_t
//@ 		mov	bx, [bp+var_4]
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 83h	; 'ƒ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 6000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Trunc$q4Real	; Trunc(x: Real): Longint{DX:AX}
//@ 		push	ax
//@ 		mov	ax, [bp+dy]	; real_t
//@ 		mov	bx, [bp+var_A]
//@ 		mov	dx, [bp+var_8]
//@ 		mov	cx, 83h	; 'ƒ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 6000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Trunc$q4Real	; Trunc(x: Real): Longint{DX:AX}
//@ 		push	ax
//@ 		push	1
//@ 		call	MoveOn		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3430
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	4Eh ; 'N'
//@ 		mov	di, offset LandZ ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset CeilZ ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetLandHeight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3431
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 400h	; Add
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jge	short loc_BA2B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+0Eh]
//@ 		mov	LandZ, ax	; int16_t
//@ ; #line	"PS10.PAS" 3433
//@ 
//@ loc_BA2B:				; CODE XREF: CorrectPlayerPosition+53Dj
//@ 		mov	ax, [bp+T1]	; int16_t
//@ 		mov	[bp+var_30], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jle	short loc_BA3C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_BB00	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BA3C:				; CODE XREF: CorrectPlayerPosition+552j
//@ 		mov	[bp+dt], ax	; int16_t
//@ 		jmp	short loc_BA44	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BA41:				; CODE XREF: CorrectPlayerPosition+618j
//@ 		inc	[bp+dt]		; int16_t
//@ ; #line	"PS10.PAS" 3434
//@ 
//@ loc_BA44:				; CODE XREF: CorrectPlayerPosition+55Aj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jnz	short loc_BA54	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_BAEC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3436
//@ 
//@ loc_BA54:				; CODE XREF: CorrectPlayerPosition+56Aj
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jge	short loc_BA84	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 3438
//@ 		add	word ptr es:[di+18h], 4	; Add
//@ 		mov	ax, es:[di+18h]
//@ 		add	es:[di+0Eh], ax	; Add
//@ ; #line	"PS10.PAS" 3439
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jle	short loc_BA82	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, LandZ	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ ; #line	"PS10.PAS" 3440
//@ 
//@ loc_BA82:				; CODE XREF: CorrectPlayerPosition+58Ej
//@ 		jmp	short loc_BAEA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3443
//@ 
//@ loc_BA84:				; CODE XREF: CorrectPlayerPosition+577j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+18h], 0	; Compare Two Operands
//@ 		jle	short loc_BA9F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 100h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_BA9F	; Jump if Not Zero (ZF=0)
//@ 		mov	word ptr es:[di+18h], 0FFFEh
//@ ; #line	"PS10.PAS" 3444
//@ 
//@ loc_BA9F:				; CODE XREF: CorrectPlayerPosition+5A7j
//@ 					; CorrectPlayerPosition+5B2j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		dec	word ptr es:[di+18h] ; Decrement by 1
//@ 		mov	ax, es:[di+18h]
//@ 		add	es:[di+0Eh], ax	; Add
//@ ; #line	"PS10.PAS" 3445
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jge	short loc_BABF	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, LandZ	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"PS10.PAS" 3446
//@ 
//@ loc_BABF:				; CODE XREF: CorrectPlayerPosition+5D1j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, CeilZ	; int16_t
//@ 		jle	short loc_BAEA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, CeilZ	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ 		cmp	word ptr es:[di+18h], 0	; Compare Two Operands
//@ 		jle	short loc_BAEA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+18h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+18h], ax
//@ ; #line	"PS10.PAS" 3448
//@ 
//@ loc_BAEA:				; CODE XREF: CorrectPlayerPosition:loc_BA82j
//@ 					; CorrectPlayerPosition+5E5j ...
//@ 		jmp	short loc_BAF5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BAEC:				; CODE XREF: CorrectPlayerPosition+56Cj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ 
//@ loc_BAF5:				; CODE XREF: CorrectPlayerPosition:loc_BAEAj
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cmp	ax, [bp+var_30]	; Compare Two Operands
//@ 		jz	short loc_BB00	; Jump if Zero (ZF=1)
//@ 		jmp	loc_BA41	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3450
//@ 
//@ loc_BB00:				; CODE XREF: CorrectPlayerPosition+554j
//@ 					; CorrectPlayerPosition+616j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 600h	; Add
//@ 		mov	es:[di+3Ch], ax
//@ ; #line	"PS10.PAS" 3453
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jg	short loc_BB3B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, es:[di+16h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 14h		; Compare Two Operands
//@ 		jg	short loc_BB3B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	al, 0
//@ 		jmp	short loc_BB3D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BB3B:				; CODE XREF: CorrectPlayerPosition+642j
//@ 					; CorrectPlayerPosition+650j
//@ 		mov	al, 1
//@ 
//@ loc_BB3D:				; CODE XREF: CorrectPlayerPosition+654j
//@ 		mov	[bp+Moved], al	; bool
//@ ; #line	"PS10.PAS" 3454
//@ 		mov	ax, [bp+T1]	; int16_t
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+22h], ax	; Add
//@ ; #line	"PS10.PAS" 3455
//@ 		cmp	[bp+Moved], 0	; bool
//@ 		jz	short loc_BB6A	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3456
//@ 		mov	al, es:[di+24h]
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jz	short loc_BB5C	; Jump if Zero (ZF=1)
//@ 		cmp	al, 7		; Compare Two Operands
//@ 		jnz	short loc_BB6A	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_BB5C:				; CODE XREF: CorrectPlayerPosition+671j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		mov	byte ptr es:[di+24h], 6
//@ ; #line	"PS10.PAS" 3460
//@ 
//@ loc_BB6A:				; CODE XREF: CorrectPlayerPosition+669j
//@ 					; CorrectPlayerPosition+675j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+24h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-4090h]
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+22h]	; Compare Two Operands
//@ 		ja	short loc_BBC7	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 3462
//@ 		mov	al, es:[di+24h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-4090h]
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+22h], ax	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3463
//@ 		cmp	[bp+Moved], 0	; bool
//@ 		jz	short loc_BBA6	; Jump if Zero (ZF=1)
//@ 		mov	byte ptr es:[di+24h], 0
//@ 		jmp	short loc_BBC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3464
//@ 
//@ loc_BBA6:				; CODE XREF: CorrectPlayerPosition+6B8j
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+24h]
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_BBB5	; Jump if Zero (ZF=1)
//@ 		cmp	al, 6		; Compare Two Operands
//@ 		jnz	short loc_BBBF	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_BBB5:				; CODE XREF: CorrectPlayerPosition+6CAj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+24h], 7
//@ 		jmp	short loc_BBC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BBBF:				; CODE XREF: CorrectPlayerPosition+6CEj
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+24h], 2
//@ ; #line	"PS10.PAS" 3467
//@ 
//@ loc_BBC7:				; CODE XREF: CorrectPlayerPosition+26j
//@ 					; CorrectPlayerPosition+30j ...
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short locret_BBD1 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_B4F0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3468
//@ 
//@ locret_BBD1:				; CODE XREF: CorrectPlayerPosition+6E7j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ CorrectPlayerPosition endp
//@ 
//@ ; #line	"PS10.PAS" 3475
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CorrectRocketPosition proc near		; CODE XREF: DoGame+41Dp
//@ 
//@ var_A		= dword	ptr -0Ah
//@ var_6		= word ptr -6
//@ tt		= word ptr -4		; int16_t
//@ sd		= word ptr -2		; int16_t
//@ t1		= word ptr  4		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3476
//@ 		mov	ax, [bp+t1]	; int16_t
//@ 		mov	[bp+tt], ax	; int16_t
//@ ; #line	"PS10.PAS" 3477
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	[bp+var_6], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jle	short loc_BBF0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_BD39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BBF0:				; CODE XREF: CorrectRocketPosition+16j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_BBF9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BBF5:				; CODE XREF: CorrectRocketPosition+161j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_BBF9:				; CODE XREF: CorrectRocketPosition+1Ej
//@ 		imul	di, n$0, 18h	; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"PS10.PAS" 3479
//@ 		mov	ax, [bp+tt]	; int16_t
//@ 		mov	[bp+t1], ax	; int16_t
//@ ; #line	"PS10.PAS" 3480
//@ 		mov	al, byte ptr [bp+t1] ; int16_t
//@ 		add	es:[di+0Dh], al	; Add
//@ ; #line	"PS10.PAS" 3481
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	dx, [di-3270h]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jb	short loc_BC45	; Jump if Below	(CF=1)
//@ ; #line	"PS10.PAS" 3482
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	al, [di-3270h]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+0Dh], al	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3484
//@ 
//@ loc_BC45:				; CODE XREF: CorrectRocketPosition+5Aj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	al, [di-3272h]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_BC63	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+t1]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	[bp+t1], ax	; int16_t
//@ ; #line	"PS10.PAS" 3485
//@ 
//@ loc_BC63:				; CODE XREF: CorrectRocketPosition+84j
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	b0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 3486
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	b0, ax		; uint16_t
//@ 		add	b0, 4000h	; uint16_t
//@ ; #line	"PS10.PAS" 3487
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, 0		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+t1]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:[di+2], ax
//@ ; #line	"PS10.PAS" 3488
//@ 		mov	ax, b0		; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+t1]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:[di+6], ax
//@ ; #line	"PS10.PAS" 3490
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	al, [di-3272h]
//@ 		and	al, 1		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+sd], ax	; int16_t
//@ ; #line	"PS10.PAS" 3491
//@ 		mov	ax, [bp+sd]	; int16_t
//@ 		mul	[bp+t1]		; int16_t
//@ 		add	ax, [bp+t1]	; int16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+12h] ; Unsigned	Multiplication of AL or	AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"PS10.PAS" 3493
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	al, [di-3272h]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_BD2E	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3494
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+6]
//@ 		push	5
//@ 		push	12h
//@ 		push	0FFh
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3495
//@ 
//@ loc_BD2E:				; CODE XREF: CorrectRocketPosition+140j
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jz	short locret_BD39 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_BBF5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3496
//@ 
//@ locret_BD39:				; CODE XREF: CorrectRocketPosition+18j
//@ 					; CorrectRocketPosition+15Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ CorrectRocketPosition endp
//@ 
//@ ; #line	"PS10.PAS" 3501
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CorrectMonstersPosition	proc near	; CODE XREF: DoGame+424p
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= dword	ptr -0Ah
//@ t1		= word ptr  4		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3502
//@ 		mov	n$0, 1		; int16_t
//@ 		inc	MsTakt		; uint16_t
//@ ; #line	"PS10.PAS" 3503
//@ 
//@ loc_BD4B:				; CODE XREF: CorrectMonstersPosition:loc_BF31j
//@ 		mov	ax, MCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_BD68	; Jump if Less (SF!=OF)
//@ 		jle	short loc_BD61	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_BF34	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BD61:				; CODE XREF: CorrectMonstersPosition+1Fj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_BD68	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_BF34	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3504
//@ 
//@ loc_BD68:				; CODE XREF: CorrectMonstersPosition+1Dj
//@ 					; CorrectMonstersPosition+26j
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ 		cmp	byte ptr es:[di+0Bh], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_BD87	; Jump if Not Zero (ZF=0)
//@ 		inc	n$0		; int16_t
//@ 		jmp	loc_BF31	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3505
//@ 
//@ loc_BD87:				; CODE XREF: CorrectMonstersPosition+41j
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"PS10.PAS" 3507
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		ja	short loc_BDAD	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_BEE3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3509
//@ 
//@ loc_BDAD:				; CODE XREF: CorrectMonstersPosition+6Bj
//@ 		mov	ax, [bp+t1]	; int16_t
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"PS10.PAS" 3510
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_BDDB	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_BE16	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_BE16	; Jump if Below	(CF=1)
//@ ; #line	"PS10.PAS" 3511
//@ 
//@ loc_BDDB:				; CODE XREF: CorrectMonstersPosition+96j
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 10h	; Compare Two Operands
//@ 		jge	short loc_BDFD	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+6], ax	; Integer Subtraction
//@ 		jmp	short loc_BE16	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3512
//@ 
//@ loc_BDFD:				; CODE XREF: CorrectMonstersPosition+A6j
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"PS10.PAS" 3513
//@ 
//@ loc_BE16:				; CODE XREF: CorrectMonstersPosition+98j
//@ 					; CorrectMonstersPosition+9Cj ...
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+2] ; Unsigned Multiplication of	AL or AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"PS10.PAS" 3514
//@ 		mov	di, es:[di+4]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+2] ; Unsigned Multiplication of	AL or AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"PS10.PAS" 3515
//@ 		cmp	word ptr es:[di+8], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_BEE1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3516
//@ 		mov	ax, es:[di+0Eh]
//@ 		mul	[bp+t1]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		mul	[bp+t1]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		push	word ptr es:[di+20h]
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+8]
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, 28h	; '('   ; Integer Subtraction
//@ 		push	ax
//@ 		push	0
//@ 		push	1
//@ 		push	0
//@ 		call	NotFreeForMonster ; function far PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_BEE1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3517
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		mul	[bp+t1]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	es:[di], ax	; Add
//@ 		mov	ax, es:[di+10h]
//@ 		mul	[bp+t1]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	es:[di+2], ax	; Add
//@ ; #line	"PS10.PAS" 3518
//@ 
//@ loc_BEE1:				; CODE XREF: CorrectMonstersPosition+131j
//@ 					; CorrectMonstersPosition+17Ej
//@ 		jmp	short loc_BF2D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3520
//@ 
//@ loc_BEE3:				; CODE XREF: CorrectMonstersPosition+6Dj
//@ 		mov	ax, [bp+t1]	; int16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"PS10.PAS" 3521
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_BF14	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_BF2D	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_BF2D	; Jump if Below	(CF=1)
//@ 
//@ loc_BF14:				; CODE XREF: CorrectMonstersPosition+1CFj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"PS10.PAS" 3523
//@ 
//@ loc_BF2D:				; CODE XREF: CorrectMonstersPosition:loc_BEE1j
//@ 					; CorrectMonstersPosition+1D1j	...
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 3524
//@ 
//@ loc_BF31:				; CODE XREF: CorrectMonstersPosition+47j
//@ 		jmp	loc_BD4B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3525
//@ 
//@ locret_BF34:				; CODE XREF: CorrectMonstersPosition+21j
//@ 					; CorrectMonstersPosition+28j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ CorrectMonstersPosition	endp
//@ 
//@ ; #line	"PS10.PAS" 3530
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RedrawWindowSelection proc near		; CODE XREF: AnimateKeyboard:loc_C1DEp
//@ 
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3531
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_BF46	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BF43:				; CODE XREF: RedrawWindowSelection+4Fj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"PS10.PAS" 3532
//@ 
//@ loc_BF46:				; CODE XREF: RedrawWindowSelection+9j
//@ 		cmp	Console, 0	; bool
//@ 		jnz	short loc_BF56	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, CurWindow	; int16_t
//@ 		jz	short loc_BF83	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3533
//@ 
//@ loc_BF56:				; CODE XREF: RedrawWindowSelection+13j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 27Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		add	ax, 12Fh	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, 95h	; '•'   ; Add
//@ 		push	ax
//@ 		push	3
//@ 		push	1
//@ 		push	4
//@ 		call	vesa_DrawKey	; function far PASCAL returns void
//@ 
//@ loc_BF83:				; CODE XREF: RedrawWindowSelection+1Cj
//@ 		cmp	[bp+n],	3	; int16_t
//@ 		jnz	short loc_BF43	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3534
//@ 		cmp	Console, 0	; bool
//@ 		jnz	short locret_BFBE ; Jump if Not	Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3535
//@ 		mov	di, CurWindow	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 27Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ ; #line	"PS10.PAS" 3536
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		add	ax, 12Fh	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, 95h	; '•'   ; Add
//@ 		push	ax
//@ 		push	1
//@ 		push	26h ; '&'
//@ 		push	25h ; '%'
//@ 		call	vesa_DrawKey	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3537
//@ 
//@ locret_BFBE:				; CODE XREF: RedrawWindowSelection+56j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ RedrawWindowSelection endp
//@ 
//@ ; #line	"PS10.PAS" 3541
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateKeyboard	proc near		; CODE XREF: DoGame:loc_C7AFp
//@ 
//@ var_24		= dword	ptr -24h
//@ var_20		= byte ptr -20h
//@ 
//@ 		enter	24h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3542
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_BFCE	; Jump if Zero (ZF=1)
//@ 		jmp	loc_C07A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_BFCE:				; CODE XREF: AnimateKeyboard+9j
//@ 		cmp	EndOfTheGame, 0	; bool
//@ 		jz	short loc_BFD8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_C07A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3543
//@ 
//@ loc_BFD8:				; CODE XREF: AnimateKeyboard+13j
//@ 		mov	al, key		; uint8_t
//@ 		mov	ah, 1
//@ 		mov	dx, 20h	; ' '
//@ 		call	@Set@GetElemOffset$q4Wordt1 ; Compute Set offset and bitmask
//@ 					; AL - Element number
//@ 					; AH - mask
//@ 					; DX - Set params
//@ 		push	dx
//@ 		push	ax
//@ 		lea	di, [bp+var_20]	; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		call	@$basg$qm3Set4Word ; Load word sized set
//@ 		push	2
//@ 		mov	ax, WeaponsCount ; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	@Set@$brplu$q4Bytet1 ; Add Set range
//@ 		pop	di
//@ 		pop	es
//@ 		assume es:nothing
//@ 		pop	ax
//@ 		pop	dx
//@ 		add	di, dx		; Add
//@ 		test	es:[di], al	; Logical Compare
//@ 		jz	short loc_C07A	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3544
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_24], di
//@ 		mov	word ptr [bp+var_24+2],	es
//@ ; #line	"PS10.PAS" 3545
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_C07A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	al, key		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+25h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jle	short loc_C07A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 3546
//@ 		mov	al, key		; uint8_t
//@ 		dec	al		; Decrement by 1
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, es:[di+48h]	; Compare Two Operands
//@ 		jz	short loc_C07A	; Jump if Zero (ZF=1)
//@ 		mov	al, key		; uint8_t
//@ 		dec	al		; Decrement by 1
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		jbe	short loc_C07A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 3548
//@ 		mov	al, key		; uint8_t
//@ 		dec	al		; Decrement by 1
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+48h], ax
//@ ; #line	"PS10.PAS" 3549
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		jnz	short loc_C07A	; Jump if Not Zero (ZF=0)
//@ 		mov	GunShift, 1	; uint16_t
//@ ; #line	"PS10.PAS" 3552
//@ 
//@ loc_C07A:				; CODE XREF: AnimateKeyboard+Bj
//@ 					; AnimateKeyboard+15j ...
//@ 		cmp	key, 0Fh	; uint8_t
//@ 		jnz	short loc_C08E	; Jump if Not Zero (ZF=0)
//@ 		cmp	MapMode, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_C08B	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_C08B:				; CODE XREF: AnimateKeyboard+C8j
//@ 		mov	MapMode, al	; bool
//@ ; #line	"PS10.PAS" 3553
//@ 
//@ loc_C08E:				; CODE XREF: AnimateKeyboard+BFj
//@ 		mov	al, KeysState+3Ah ; bool[128]
//@ 		neg	al		; Two's Complement Negation
//@ 		sbb	al, al		; Integer Subtraction with Borrow
//@ 		neg	al		; Two's Complement Negation
//@ 		mov	TabMode, al	; bool
//@ ; #line	"PS10.PAS" 3565
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_C0A4	; Jump if Zero (ZF=1)
//@ 		jmp	loc_C153	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3567
//@ 
//@ loc_C0A4:				; CODE XREF: AnimateKeyboard+DFj
//@ 		mov	al, key		; uint8_t
//@ 		cmp	al, 0Ch		; Compare Two Operands
//@ 		jb	short loc_C0AF	; Jump if Below	(CF=1)
//@ 		cmp	al, 0Dh		; Compare Two Operands
//@ 		jbe	short loc_C0BA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_C0AF:				; CODE XREF: AnimateKeyboard+E9j
//@ 		mov	al, key		; uint8_t
//@ 		cmp	al, 4Ah	; 'J'   ; Compare Two Operands
//@ 		jz	short loc_C0BA	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4Eh	; 'N'   ; Compare Two Operands
//@ 		jnz	short loc_C0E5	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3569
//@ 
//@ loc_C0BA:				; CODE XREF: AnimateKeyboard+EDj
//@ 					; AnimateKeyboard+F4j
//@ 		cmp	key, 0Ch	; uint8_t
//@ 		jz	short loc_C0C8	; Jump if Zero (ZF=1)
//@ 		cmp	key, 4Ah ; 'J'  ; uint8_t
//@ 		jnz	short loc_C0CD	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_C0C8:				; CODE XREF: AnimateKeyboard+FFj
//@ 		mov	InfoPage, 1	; bool
//@ ; #line	"PS10.PAS" 3570
//@ 
//@ loc_C0CD:				; CODE XREF: AnimateKeyboard+106j
//@ 		cmp	key, 0Dh	; uint8_t
//@ 		jz	short loc_C0DB	; Jump if Zero (ZF=1)
//@ 		cmp	key, 4Eh ; 'N'  ; uint8_t
//@ 		jnz	short loc_C0E0	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_C0DB:				; CODE XREF: AnimateKeyboard+112j
//@ 		mov	InfoPage, 0	; bool
//@ ; #line	"PS10.PAS" 3571
//@ 
//@ loc_C0E0:				; CODE XREF: AnimateKeyboard+119j
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3574
//@ 
//@ loc_C0E5:				; CODE XREF: AnimateKeyboard+F8j
//@ 		cmp	KeysState+1Ah, 0 ; bool[128]
//@ 		jz	short loc_C0F7	; Jump if Zero (ZF=1)
//@ 		cmp	mps, 10h	; int16_t
//@ 		jle	short loc_C0F7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		dec	mps		; int16_t
//@ ; #line	"PS10.PAS" 3575
//@ 
//@ loc_C0F7:				; CODE XREF: AnimateKeyboard+12Aj
//@ 					; AnimateKeyboard+131j
//@ 		cmp	KeysState+1Bh, 0 ; bool[128]
//@ 		jz	short loc_C109	; Jump if Zero (ZF=1)
//@ 		cmp	mps, 40h ; '@'  ; int16_t
//@ 		jge	short loc_C109	; Jump if Greater or Equal (SF=OF)
//@ 		inc	mps		; int16_t
//@ ; #line	"PS10.PAS" 3577
//@ 
//@ loc_C109:				; CODE XREF: AnimateKeyboard+13Cj
//@ 					; AnimateKeyboard+143j
//@ 		cmp	key, 0Eh	; uint8_t
//@ 		jnz	short loc_C12F	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3579
//@ 		cmp	Console, 0	; bool
//@ 		jz	short loc_C11F	; Jump if Zero (ZF=1)
//@ 		mov	ConsDY,	0FFFFh	; int16_t
//@ 		jmp	short loc_C12A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C11F:				; CODE XREF: AnimateKeyboard+155j
//@ 		mov	ConsDY,	1	; int16_t
//@ 		mov	Console, 1	; bool
//@ ; #line	"PS10.PAS" 3580
//@ 
//@ loc_C12A:				; CODE XREF: AnimateKeyboard+15Dj
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3583
//@ 
//@ loc_C12F:				; CODE XREF: AnimateKeyboard+14Ej
//@ 		cmp	key, 1		; uint8_t
//@ 		jnz	short loc_C150	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3585
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	3
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3586
//@ 		cmp	MenuOn,	0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_C14D	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_C14D:				; CODE XREF: AnimateKeyboard+18Aj
//@ 		mov	MenuOn,	al	; bool
//@ ; #line	"PS10.PAS" 3589
//@ 
//@ loc_C150:				; CODE XREF: AnimateKeyboard+174j
//@ 		jmp	loc_C1E1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3591
//@ 
//@ loc_C153:				; CODE XREF: AnimateKeyboard+E1j
//@ 		mov	al, key		; uint8_t
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jb	short loc_C187	; Jump if Below	(CF=1)
//@ 		cmp	al, 8		; Compare Two Operands
//@ 		jbe	short loc_C162	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	al, 0Bh		; Compare Two Operands
//@ 		jnz	short loc_C187	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3593
//@ 
//@ loc_C162:				; CODE XREF: AnimateKeyboard+19Cj
//@ 		cmp	key, 0Bh	; uint8_t
//@ 		jnz	short loc_C174	; Jump if Not Zero (ZF=0)
//@ 		mov	di, CurWindow	; int16_t
//@ 		mov	byte ptr [di-0AC0h], 0
//@ 		jmp	short loc_C182	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3594
//@ 
//@ loc_C174:				; CODE XREF: AnimateKeyboard+1A7j
//@ 		mov	al, key		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		mov	di, CurWindow	; int16_t
//@ 		mov	[di-0AC0h], al
//@ ; #line	"PS10.PAS" 3595
//@ 
//@ loc_C182:				; CODE XREF: AnimateKeyboard+1B2j
//@ 		call	ClearUnusedScreens ; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3597
//@ 
//@ loc_C187:				; CODE XREF: AnimateKeyboard+198j
//@ 					; AnimateKeyboard+1A0j
//@ 		cmp	key, 1		; uint8_t
//@ 		jnz	short loc_C19B	; Jump if Not Zero (ZF=0)
//@ 		cmp	Console, 0	; bool
//@ 		mov	al, 0
//@ 		jnz	short loc_C198	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_C198:				; CODE XREF: AnimateKeyboard+1D5j
//@ 		mov	Console, al	; bool
//@ ; #line	"PS10.PAS" 3598
//@ 
//@ loc_C19B:				; CODE XREF: AnimateKeyboard+1CCj
//@ 		cmp	key, 4Dh ; 'M'  ; uint8_t
//@ 		jnz	short loc_C1A6	; Jump if Not Zero (ZF=0)
//@ 		inc	CurWindow	; int16_t
//@ ; #line	"PS10.PAS" 3599
//@ 
//@ loc_C1A6:				; CODE XREF: AnimateKeyboard+1E0j
//@ 		cmp	key, 50h ; 'P'  ; uint8_t
//@ 		jnz	short loc_C1B2	; Jump if Not Zero (ZF=0)
//@ 		add	CurWindow, 2	; int16_t
//@ ; #line	"PS10.PAS" 3600
//@ 
//@ loc_C1B2:				; CODE XREF: AnimateKeyboard+1EBj
//@ 		mov	ax, CurWindow	; int16_t
//@ 		and	ax, 3		; Logical AND
//@ 		mov	CurWindow, ax	; int16_t
//@ ; #line	"PS10.PAS" 3601
//@ 		cmp	key, 4Bh ; 'K'  ; uint8_t
//@ 		jnz	short loc_C1C6	; Jump if Not Zero (ZF=0)
//@ 		dec	CurWindow	; int16_t
//@ ; #line	"PS10.PAS" 3602
//@ 
//@ loc_C1C6:				; CODE XREF: AnimateKeyboard+200j
//@ 		cmp	key, 48h ; 'H'  ; uint8_t
//@ 		jnz	short loc_C1D2	; Jump if Not Zero (ZF=0)
//@ 		sub	CurWindow, 2	; int16_t
//@ ; #line	"PS10.PAS" 3603
//@ 
//@ loc_C1D2:				; CODE XREF: AnimateKeyboard+20Bj
//@ 		cmp	CurWindow, 0	; int16_t
//@ 		jge	short loc_C1DE	; Jump if Greater or Equal (SF=OF)
//@ 		add	CurWindow, 4	; int16_t
//@ ; #line	"PS10.PAS" 3604
//@ 
//@ loc_C1DE:				; CODE XREF: AnimateKeyboard+217j
//@ 		call	RedrawWindowSelection ;	function near PASCAL returns void
//@ ; #line	"PS10.PAS" 3606
//@ 
//@ loc_C1E1:				; CODE XREF: AnimateKeyboard:loc_C150j
//@ 					; AnimateKeyboard+22Fj
//@ 		call	@KeyPressed$qv	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short locret_C1F1 ; Jump if Zero (ZF=1)
//@ 		call	@ReadKey$qv	; function far PASCAL returns PASCAL character 'Char'
//@ 		jmp	short loc_C1E1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3607
//@ 
//@ locret_C1F1:				; CODE XREF: AnimateKeyboard+228j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ AnimateKeyboard	endp
//@ 
//@ ; #line	"PS10.PAS" 3611
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StopSound	proc near		; CODE XREF: DoGame+19CBp
//@ 
//@ var_2		= word ptr -2
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3612
//@ 		push	0FFFFh
//@ 		call	SetAmbient	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3613
//@ 		mov	ObjAmbU.Ambid, 0FFFFh ;	struct ObjAmb$Type
//@ ; #line	"PS10.PAS" 3614
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"PS10.PAS" 3615
//@ 		mov	al, MaxVoice	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_2], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jg	short loc_C230	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_C21D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C219:				; CODE XREF: StopSound+3Bj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_C21D:				; CODE XREF: StopSound+24j
//@ 		imul	di, n$0, 0Eh	; int16_t
//@ 		mov	word ptr [di-878h], 0FFh
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jnz	short loc_C219	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3616
//@ 
//@ loc_C230:				; CODE XREF: StopSound+1Fj
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"PS10.PAS" 3617
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ StopSound	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aYouGotInvisibi	db 20,'YOU GOT INVISIBILITY' ; DATA XREF: DoGame+14D1o
//@ aYouGotTheRefle	db 21,'YOU GOT THE REFLECTOR' ; DATA XREF: DoGame+1518o
//@ aYouGotTheChoji	db 23,'YOU GOT THE CHOJIN MASK' ; DATA XREF: DoGame+155Fo
//@ ; #line	"PS10.PAS" 3622
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DoGame		proc near		; CODE XREF: PROGRAM:loc_EEDEp
//@ 
//@ var_10		= dword	ptr -10h
//@ var_C		= dword	ptr -0Ch
//@ var_8		= dword	ptr -8
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 3623
//@ 		mov	ExMode,	0	; bool
//@ ; #line	"PS10.PAS" 3624
//@ 		mov	MenuOn,	0	; bool
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMainY, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuMode, ax	; int16_t
//@ ; #line	"PS10.PAS" 3625
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MenuCode, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3626
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr RealTime, ax ;	int32_t
//@ 		mov	word ptr RealTime+2, ax	; int32_t
//@ ; #line	"PS10.PAS" 3627
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr LastPainTime, ax ; int32_t
//@ 		mov	word ptr LastPainTime+2, ax ; int32_t
//@ ; #line	"PS10.PAS" 3628
//@ 		mov	word ptr NextSendTime, 0FFF2h ;	int32_t
//@ 		mov	word ptr NextSendTime+2, 0FFFFh	; int32_t
//@ ; #line	"PS10.PAS" 3631
//@ 		mov	SecCounter, 0	; uint8_t
//@ ; #line	"PS10.PAS" 3632
//@ 		mov	NewSecond, 0	; bool
//@ ; #line	"PS10.PAS" 3633
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ProcMessage.LTime, ax ;	struct ProcMessage$Type
//@ ; #line	"PS10.PAS" 3635
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	RShadeDir, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	RShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 3636
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	GShadeDir, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	GShadeLev, ax	; int16_t
//@ ; #line	"PS10.PAS" 3637
//@ 		mov	Players.Active,	1 ; struct TPlayerInfo[8]
//@ ; #line	"PS10.PAS" 3638
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	StepMove, ax	; int16_t
//@ ; #line	"PS10.PAS" 3639
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_C2E7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C2E3:				; CODE XREF: DoGame+80j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_C2E7:				; CODE XREF: DoGame+6Bj
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	byte ptr [di-0FB2h], 2
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_C2E3	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3640
//@ 		cmp	Console, 0	; bool
//@ 		jz	short loc_C30A	; Jump if Zero (ZF=1)
//@ 		mov	ConsDY,	1	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsY, ax	; int16_t
//@ ; #line	"PS10.PAS" 3645
//@ 
//@ loc_C30A:				; CODE XREF: DoGame+87j
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_C369	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_C369	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3647
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyNetN,	ax	; int16_t
//@ ; #line	"PS10.PAS" 3649
//@ 		push	Players.PlHx	; struct TPlayerInfo[8]
//@ 		push	Players.PlHy	; struct TPlayerInfo[8]
//@ 		push	4Eh ; 'N'
//@ 		mov	di, offset i	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset n$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetLandHeight	; function far PASCAL returns void
//@ 		mov	ax, i		; int16_t
//@ 		mov	Players.Plhz0, ax ; struct TPlayerInfo[8]
//@ ; #line	"PS10.PAS" 3650
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_C348	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C344:				; CODE XREF: DoGame+F1j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_C348:				; CODE XREF: DoGame+CCj
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"PS10.PAS" 3651
//@ 		mov	byte ptr es:[di+26h], 0
//@ 		mov	byte ptr es:[di], 0
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+28h], ax
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_C344	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3655
//@ 
//@ loc_C369:				; CODE XREF: DoGame+99j DoGame+A0j
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_C3B3	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3656
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_C37B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C377:				; CODE XREF: DoGame+13Bj
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 3657
//@ 
//@ loc_C37B:				; CODE XREF: DoGame+FFj
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_C3A1	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3658
//@ 		push	n$0		; int16_t
//@ 		call	ReinitPlayer	; function near	PASCAL returns void
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	word ptr [di-0F82h], 578h
//@ 		mov	word ptr [di-0F80h], 0
//@ 		jmp	short loc_C3AC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3659
//@ 
//@ loc_C3A1:				; CODE XREF: DoGame+10Fj
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di-0FAEh], ax
//@ 
//@ loc_C3AC:				; CODE XREF: DoGame+129j
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_C377	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3661
//@ 
//@ loc_C3B3:				; CODE XREF: DoGame+F8j
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_C3BD	; Jump if Zero (ZF=1)
//@ 		call	INIT_IPX_SERVER	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3662
//@ 
//@ loc_C3BD:				; CODE XREF: DoGame+142j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_C3C7	; Jump if Zero (ZF=1)
//@ 		call	INIT_IPX_CLIENT	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3665
//@ 
//@ loc_C3C7:				; CODE XREF: DoGame+14Cj
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_C41A	; Jump if Zero (ZF=1)
//@ 		cmp	MyNetN,	0	; int16_t
//@ 		jnz	short loc_C411	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3667
//@ 		call	ScanNet		; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3668
//@ 		cmp	MenuCode, 2	; uint16_t
//@ 		jnz	short loc_C3E4	; Jump if Not Zero (ZF=0)
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"PS10.PAS" 3669
//@ 
//@ loc_C3E4:				; CODE XREF: DoGame+167j
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		jz	short loc_C3F7	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3670
//@ 		mov	MenuCode, 4	; uint16_t
//@ 		jmp	locret_DC4E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 		db 0E9h	; é
//@ 		db  3Ch	; <
//@ 		db  18h
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3672
//@ 
//@ loc_C3F7:				; CODE XREF: DoGame+173j
//@ 		call	JoinNetworkGame	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3673
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		jz	short loc_C40F	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3674
//@ 		mov	MenuCode, 4	; uint16_t
//@ 		mov	CLIENT,	0	; bool
//@ 		jmp	loc_DC33	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3675
//@ 
//@ loc_C40F:				; CODE XREF: DoGame+189j
//@ 		jmp	short loc_C41A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3676
//@ 
//@ loc_C411:				; CODE XREF: DoGame+15Dj
//@ 		call	WaitServer	; function near	PASCAL returns void
//@ 		call	WaitServer	; function near	PASCAL returns void
//@ 		call	LoadServerPatch	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3680
//@ 
//@ loc_C41A:				; CODE XREF: DoGame+156j
//@ 					; DoGame:loc_C40Fj
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		jz	short loc_C424	; Jump if Zero (ZF=1)
//@ 		jmp	loc_DC33	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3682
//@ 
//@ loc_C424:				; CODE XREF: DoGame+1A9j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_C432	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_C448	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3684
//@ 
//@ loc_C432:				; CODE XREF: DoGame+1B3j
//@ 		mov	PlayDemo, 0	; bool
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"PS10.PAS" 3685
//@ 		cmp	NetMode, 0	; uint8_t
//@ 		jnz	short loc_C448	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MCount,	ax	; uint16_t
//@ ; #line	"PS10.PAS" 3688
//@ 
//@ loc_C448:				; CODE XREF: DoGame+1BAj DoGame+1CBj
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_C456	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_C45B	; Jump if Zero (ZF=1)
//@ 
//@ loc_C456:				; CODE XREF: DoGame+1D7j
//@ 		call	StartDemo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3690
//@ 
//@ loc_C45B:				; CODE XREF: DoGame+1DEj
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_C469	; Jump if Zero (ZF=1)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_C46D	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_C469:				; CODE XREF: DoGame+1EAj
//@ 		mov	al, 0
//@ 		jmp	short loc_C46F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C46D:				; CODE XREF: DoGame+1F1j
//@ 		mov	al, 1
//@ 
//@ loc_C46F:				; CODE XREF: DoGame+1F5j
//@ 		mov	NETMonitor, al	; bool
//@ ; #line	"PS10.PAS" 3691
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_C47E	; Jump if Zero (ZF=1)
//@ 		call	InitVESAMonitor	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3692
//@ 
//@ loc_C47E:				; CODE XREF: DoGame+201j
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3693
//@ 		call	InitMZPosition	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3694
//@ 		call	SetPalette	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3696
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_C49A	; Jump if Zero (ZF=1)
//@ 		mov	LCDTrack, 0Ah	; int16_t
//@ ; #line	"PS10.PAS" 3697
//@ 
//@ loc_C49A:				; CODE XREF: DoGame+21Cj
//@ 		push	LCDTrack	; int16_t
//@ 		call	DO_CD_Play	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3699
//@ 		call	ReDrawGround	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3700
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3701
//@ 		mov	t1, 4		; uint16_t
//@ ; #line	"PS10.PAS" 3702
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Times10Sum, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3703
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	_Times10Sum, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3704
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Frames10Count, ax ; uint16_t
//@ ; #line	"PS10.PAS" 3705
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	EndDelay, ax	; int16_t
//@ ; #line	"PS10.PAS" 3707
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	KBDBufCnt, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3708
//@ 		mov	NextL, 0	; bool
//@ ; #line	"PS10.PAS" 3709
//@ 		mov	Paused,	0	; bool
//@ ; #line	"PS10.PAS" 3711
//@ 		cmp	MouseD,	0	; bool
//@ 		jz	short loc_C4F8	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3713
//@ 		mov	word ptr LastMouseTime,	0FFF0h ; int32_t
//@ 		mov	word ptr LastMouseTime+2, 0FFFFh ; int32_t
//@ ; #line	"PS10.PAS" 3715
//@ 		call	GetMouseStatus	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3716
//@ 		mov	word ptr LastMouseTime,	0FFF0h ; int32_t
//@ 		mov	word ptr LastMouseTime+2, 0FFFFh ; int32_t
//@ ; #line	"PS10.PAS" 3722
//@ 
//@ loc_C4F8:				; CODE XREF: DoGame+263j DoGame+19BAj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3723
//@ 		cmp	KBDBufCnt, 0	; uint16_t
//@ 		jbe	short loc_C523	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 3725
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"PS10.PAS" 3726
//@ 		mov	al, KBDBuf	; uint8_t[16]
//@ 		mov	key, al		; uint8_t
//@ ; #line	"PS10.PAS" 3727
//@ 		dec	KBDBufCnt	; uint16_t
//@ ; #line	"PS10.PAS" 3728
//@ 		mov	di, (offset KBDBuf+1) ;	uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset KBDBuf ; uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"PS10.PAS" 3729
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"PS10.PAS" 3730
//@ 		jmp	short loc_C528	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C523:				; CODE XREF: DoGame+28Cj
//@ 		mov	key, 0		; uint8_t
//@ ; #line	"PS10.PAS" 3732
//@ 
//@ loc_C528:				; CODE XREF: DoGame+2ABj
//@ 		cmp	key, 58h ; 'X'  ; uint8_t
//@ 		jnz	short loc_C542	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3733
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_C53D	; Jump if Zero (ZF=1)
//@ 		call	SaveMPicture	; function far PASCAL returns void
//@ 		jmp	short loc_C542	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3734
//@ 
//@ loc_C53D:				; CODE XREF: DoGame+2BEj
//@ 		call	SavePicture	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3735
//@ 
//@ loc_C542:				; CODE XREF: DoGame+2B7j DoGame+2C5j
//@ 		call	ProcessPreKeyboard ; function near PASCAL returns void
//@ ; #line	"PS10.PAS" 3738
//@ 		cmp	Console, 0	; bool
//@ 		jz	short loc_C556	; Jump if Zero (ZF=1)
//@ 		cmp	key, 0		; uint8_t
//@ 		jz	short loc_C556	; Jump if Zero (ZF=1)
//@ 		call	ProcessConsole	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3739
//@ 
//@ loc_C556:				; CODE XREF: DoGame+2D4j DoGame+2DBj
//@ 		cmp	MenuOn,	0	; bool
//@ 		jz	short loc_C560	; Jump if Zero (ZF=1)
//@ 		call	ProcessMenu	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3741
//@ 
//@ loc_C560:				; CODE XREF: DoGame+2E5j
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_C56E	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_C582	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3742
//@ 
//@ loc_C56E:				; CODE XREF: DoGame+2EFj
//@ 		mov	word ptr DRegs.xBX, 9 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3743
//@ 
//@ loc_C582:				; CODE XREF: DoGame+2F6j
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		jz	short loc_C58C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_DC33	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3746
//@ 
//@ loc_C58C:				; CODE XREF: DoGame+311j
//@ 		call	RefreshMachineMode ; function near PASCAL returns void
//@ ; #line	"PS10.PAS" 3747
//@ 		call	ProcessCD	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3748
//@ 		mov	al, NETMonitor	; bool
//@ 		mov	DisableALL, al	; bool
//@ ; #line	"PS10.PAS" 3749
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_C5BB	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_C5BB	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_C5BB	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_C5BB	; Jump if Not Zero (ZF=0)
//@ 		cmp	MenuOn,	0	; bool
//@ 		jnz	short loc_C5C2	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_C5BB:				; CODE XREF: DoGame+327j DoGame+32Ej ...
//@ 		cmp	Paused,	0	; bool
//@ 		jz	short loc_C5C6	; Jump if Zero (ZF=1)
//@ 
//@ loc_C5C2:				; CODE XREF: DoGame+343j
//@ 		mov	al, 0
//@ 		jmp	short loc_C5C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C5C6:				; CODE XREF: DoGame+34Aj
//@ 		mov	al, 1
//@ 
//@ loc_C5C8:				; CODE XREF: DoGame+34Ej
//@ 		mov	GameActive, al	; bool
//@ ; #line	"PS10.PAS" 3751
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_C5D9	; Jump if Not Zero (ZF=0)
//@ 		cmp	EndOfTheGame, 0	; bool
//@ 		jz	short loc_C5E5	; Jump if Zero (ZF=1)
//@ 
//@ loc_C5D9:				; CODE XREF: DoGame+35Aj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.ksFlags, ax ; struct TPlayerInfo[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HksFlags, ax	; uint16_t
//@ 		jmp	short loc_C5F6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3752
//@ 
//@ loc_C5E5:				; CODE XREF: DoGame+361j
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_C5F6	; Jump if Not Zero (ZF=0)
//@ 		cmp	Paused,	0	; bool
//@ 		jnz	short loc_C5F6	; Jump if Not Zero (ZF=0)
//@ 		call	ProcessDevices	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3754
//@ 
//@ loc_C5F6:				; CODE XREF: DoGame+36Dj DoGame+374j ...
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_C600	; Jump if Zero (ZF=1)
//@ 		call	LoadClientPatch	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3755
//@ 
//@ loc_C600:				; CODE XREF: DoGame+385j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_C60A	; Jump if Zero (ZF=1)
//@ 		call	SendClientPatch	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3757
//@ 
//@ loc_C60A:				; CODE XREF: DoGame+38Fj
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_C614	; Jump if Zero (ZF=1)
//@ 		call	SendServerPatch	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3758
//@ 
//@ loc_C614:				; CODE XREF: DoGame+399j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_C61E	; Jump if Zero (ZF=1)
//@ 		call	LoadServerPatch	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3760
//@ 
//@ loc_C61E:				; CODE XREF: DoGame+3A3j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_C636	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_C636	; Jump if Not Zero (ZF=0)
//@ 		cmp	Paused,	0	; bool
//@ 		jnz	short loc_C636	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3761
//@ 		call	MoveServerPlayers ; function near PASCAL returns void
//@ ; #line	"PS10.PAS" 3763
//@ 
//@ loc_C636:				; CODE XREF: DoGame+3ADj DoGame+3B4j ...
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		mov	word ptr demotime, ax ;	int32_t
//@ 		mov	word ptr demotime+2, dx	; int32_t
//@ ; #line	"PS10.PAS" 3764
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_C650	; Jump if Zero (ZF=1)
//@ 		call	Demo_ReadNext	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3766
//@ 
//@ loc_C650:				; CODE XREF: DoGame+3D3j
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		jz	short loc_C65A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_DC33	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3768
//@ 
//@ loc_C65A:				; CODE XREF: DoGame+3DFj
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_C6A9	; Jump if Zero (ZF=1)
//@ 		cmp	Spline,	0	; bool
//@ 		jz	short loc_C6A9	; Jump if Zero (ZF=1)
//@ 		cmp	Paused,	0	; bool
//@ 		jnz	short loc_C6A9	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3770
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		sub	ax, word ptr LastServerTime ; int32_t
//@ 		sbb	dx, word ptr LastServerTime+2 ;	int32_t
//@ 		mov	DeltaT,	ax	; int16_t
//@ ; #line	"PS10.PAS" 3771
//@ 		cmp	DeltaT,	0	; int16_t
//@ 		jle	short loc_C6A9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 3773
//@ 		push	DeltaT		; int16_t
//@ 		call	CorrectPlayerPosition ;	function near PASCAL returns void
//@ ; #line	"PS10.PAS" 3774
//@ 		push	DeltaT		; int16_t
//@ 		call	CorrectRocketPosition ;	function near PASCAL returns void
//@ ; #line	"PS10.PAS" 3775
//@ 		push	DeltaT		; int16_t
//@ 		call	CorrectMonstersPosition	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3776
//@ 		mov	ax, DeltaT	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	word ptr LastServerTime, ax ; int32_t
//@ 		adc	word ptr LastServerTime+2, dx ;	int32_t
//@ ; #line	"PS10.PAS" 3780
//@ 
//@ loc_C6A9:				; CODE XREF: DoGame+3E9j DoGame+3F0j ...
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_C6B3	; Jump if Zero (ZF=1)
//@ 		jmp	loc_C7AF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3781
//@ 
//@ loc_C6B3:				; CODE XREF: DoGame+438j
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"PS10.PAS" 3783
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	Hx, ax		; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	Hy, ax		; int16_t
//@ ; #line	"PS10.PAS" 3784
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		push	ax
//@ 		push	30h ; '0'
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	bx, ax
//@ 		mov	ax, hvz		; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, bx		; Add
//@ 		mov	hvz, ax		; int16_t
//@ ; #line	"PS10.PAS" 3785
//@ 		mov	ax, hvz		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jg	short loc_C71E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr ZTime,	ax ; int32_t
//@ 		mov	word ptr ZTime+2, ax ; int32_t
//@ ; #line	"PS10.PAS" 3787
//@ 
//@ loc_C71E:				; CODE XREF: DoGame+49Ej
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 600h	; Add
//@ 		mov	es:[di+3Ch], ax
//@ ; #line	"PS10.PAS" 3788
//@ 		mov	ax, _LookVz	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+3Ch]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	Hz, ax		; uint16_t
//@ ; #line	"PS10.PAS" 3789
//@ 		cmp	Paused,	0	; bool
//@ 		jnz	short loc_C7AF	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, hvz		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, hvz		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 85h	; '…'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, word ptr ZTime ; int32_t
//@ 		mov	dx, word ptr ZTime+2 ; int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		add	Hz, ax		; uint16_t
//@ ; #line	"PS10.PAS" 3792
//@ 
//@ loc_C7AF:				; CODE XREF: DoGame+43Aj DoGame+4CFj
//@ 		call	AnimateKeyboard	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3797
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr k$0, ax ; int32_t
//@ 		mov	word ptr k$0+2,	ax ; int32_t
//@ ; #line	"PS10.PAS" 3798
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_C7C4	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_C848	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3800
//@ 
//@ loc_C7C4:				; CODE XREF: DoGame+549j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_C7CF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C7CB:				; CODE XREF: DoGame+5C0j
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 3802
//@ 
//@ loc_C7CF:				; CODE XREF: DoGame+553j
//@ 		inc	CurOwner	; uint16_t
//@ ; #line	"PS10.PAS" 3803
//@ 		mov	ax, CurOwner	; uint16_t
//@ 		and	ax, 7		; Logical AND
//@ 		mov	CurOwner, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3804
//@ 		cmp	CurOwner, 0	; uint16_t
//@ 		jnz	short loc_C7E9	; Jump if Not Zero (ZF=0)
//@ 		mov	CurOwner, 1	; uint16_t
//@ ; #line	"PS10.PAS" 3805
//@ 
//@ loc_C7E9:				; CODE XREF: DoGame+56Bj
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_C831	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3806
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_C800	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C7FC:				; CODE XREF: DoGame+5B9j
//@ 		inc	j		; uint16_t
//@ ; #line	"PS10.PAS" 3807
//@ 
//@ loc_C800:				; CODE XREF: DoGame+584j
//@ 		mov	di, j		; uint16_t
//@ 		mov	al, [di-0AC0h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, CurOwner	; uint16_t
//@ 		jnz	short loc_C82A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3808
//@ 		mov	n$0, 7		; int16_t
//@ 		mov	j, 3		; uint16_t
//@ 		mov	word ptr k$0, 1	; int32_t
//@ 		mov	word ptr k$0+2,	0 ; int32_t
//@ 		jmp	short loc_C831	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C82A:				; CODE XREF: DoGame+598j
//@ 		cmp	j, 3		; uint16_t
//@ 		jnz	short loc_C7FC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3809
//@ 
//@ loc_C831:				; CODE XREF: DoGame+57Dj DoGame+5B2j
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_C7CB	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3810
//@ 		mov	ax, word ptr k$0 ; int32_t
//@ 		or	ax, word ptr k$0+2 ; int32_t
//@ 		jnz	short loc_C846	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurOwner, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3811
//@ 
//@ loc_C846:				; CODE XREF: DoGame+5C9j
//@ 		jmp	short loc_C84E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_C848:				; CODE XREF: DoGame+54Bj
//@ 		mov	ax, MyNetN	; int16_t
//@ 		mov	CurOwner, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3813
//@ 
//@ loc_C84E:				; CODE XREF: DoGame:loc_C846j
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_C86B	; Jump if Zero (ZF=1)
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_C868	; Jump if Zero (ZF=1)
//@ 		cmp	CurOwner, 0	; uint16_t
//@ 		jnz	short loc_C86B	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3814
//@ 
//@ loc_C868:				; CODE XREF: DoGame+5E9j
//@ 		jmp	loc_CE3E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3816
//@ 
//@ loc_C86B:				; CODE XREF: DoGame+5DDj DoGame+5F0j
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_C875	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_C9C9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3818
//@ 
//@ loc_C875:				; CODE XREF: DoGame+5FAj
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"PS10.PAS" 3820
//@ 		mov	ax, es:[di+38h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	ica, ax		; int16_t
//@ 		mov	ax, es:[di+3Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	isa, ax		; int16_t
//@ ; #line	"PS10.PAS" 3821
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
//@ ; #line	"PS10.PAS" 3822
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
//@ ; #line	"PS10.PAS" 3824
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3825
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+1Eh]
//@ 		mov	EHFi, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3826
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	ehx, ax		; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	ehy, ax		; int16_t
//@ ; #line	"PS10.PAS" 3827
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		push	ax
//@ 		push	30h ; '0'
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		push	ax
//@ 		push	4
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	n$0, ax		; int16_t
//@ ; #line	"PS10.PAS" 3828
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3Ch]
//@ 		mov	ehz, ax		; int16_t
//@ ; #line	"PS10.PAS" 3829
//@ 		cmp	Paused,	0	; bool
//@ 		jnz	short loc_C986	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		add	ehz, ax		; int16_t
//@ ; #line	"PS10.PAS" 3830
//@ 
//@ loc_C986:				; CODE XREF: DoGame+6B2j
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jnz	short loc_C9C6	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3831
//@ 		mov	ehz, 940h	; int16_t
//@ 		mov	di, offset CurOwner ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ehx	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ehy	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	ehz		; int16_t
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		push	0
//@ 		call	MoveOn		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3833
//@ 
//@ loc_C9C6:				; CODE XREF: DoGame+71Aj
//@ 		jmp	loc_CC40	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3835
//@ 
//@ loc_C9C9:				; CODE XREF: DoGame+5FCj
//@ 		mov	ax, HFi		; uint16_t
//@ 		mov	EHFi, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3836
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"PS10.PAS" 3838
//@ 		mov	ax, word ptr ca	; real_t
//@ 		mov	bx, word ptr ca+2 ; real_t
//@ 		mov	dx, word ptr ca+4 ; real_t
//@ 		mov	cx, 89h	; '‰'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	ica, ax		; int16_t
//@ ; #line	"PS10.PAS" 3839
//@ 		mov	ax, word ptr sa	; real_t
//@ 		mov	bx, word ptr sa+2 ; real_t
//@ 		mov	dx, word ptr sa+4 ; real_t
//@ 		mov	cx, 89h	; '‰'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	isa, ax		; int16_t
//@ ; #line	"PS10.PAS" 3840
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
//@ ; #line	"PS10.PAS" 3841
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
//@ ; #line	"PS10.PAS" 3844
//@ 		cmp	EndOfTheGame, 0	; bool
//@ 		jz	short loc_CAD0	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3848
//@ 		mov	ax, EndCamera.$cx ; struct EndCamera$Type
//@ 		mov	ehx, ax		; int16_t
//@ 		mov	ax, EndCamera.cy ; struct EndCamera$Type
//@ 		mov	ehy, ax		; int16_t
//@ 		mov	ax, EndCamera.cz ; struct EndCamera$Type
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	ehz, ax		; int16_t
//@ 		mov	ax, EndCamera.cfi ; struct EndCamera$Type
//@ 		mov	HFi, ax		; uint16_t
//@ 		mov	ax, EndCamera.$cl ; struct EndCamera$Type
//@ 		mov	LookVz,	ax	; int16_t
//@ ; #line	"PS10.PAS" 3850
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 86h	; '†'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 2000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 85h	; '…'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 2000h
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		add	ehz, ax		; int16_t
//@ ; #line	"PS10.PAS" 3851
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3852
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3853
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"PS10.PAS" 3854
//@ 		jmp	loc_CC40	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3855
//@ 
//@ loc_CAD0:				; CODE XREF: DoGame+7EFj
//@ 		cmp	ExMode,	0	; bool
//@ 		jnz	short loc_CAE6	; Jump if Not Zero (ZF=0)
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jz	short loc_CAE6	; Jump if Zero (ZF=1)
//@ 		jmp	loc_CB7B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3857
//@ 
//@ loc_CAE6:				; CODE XREF: DoGame+85Fj DoGame+86Bj
//@ 		mov	ax, Hx		; int16_t
//@ 		mov	ehx, ax		; int16_t
//@ 		mov	ax, Hy		; int16_t
//@ 		mov	ehy, ax		; int16_t
//@ 		mov	ehz, 800h	; int16_t
//@ ; #line	"PS10.PAS" 3858
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"PS10.PAS" 3859
//@ 		cmp	ExMode,	0	; bool
//@ 		jz	short loc_CB33	; Jump if Zero (ZF=1)
//@ 		mov	di, offset MyNetN ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ehx	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ehy	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	280h
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		push	0
//@ 		call	MoveOn		; function far PASCAL returns void
//@ 		jmp	short loc_CB78	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3862
//@ 
//@ loc_CB33:				; CODE XREF: DoGame+88Cj
//@ 		push	Hx		; int16_t
//@ 		push	Hy		; int16_t
//@ 		push	78h ; 'x'
//@ 		mov	di, offset ehx	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ehy	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetMFloorZ	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3863
//@ 		cmp	ehy, 7Ch ; '|'  ; int16_t
//@ 		jge	short loc_CB61	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	ehz, ax		; int16_t
//@ 		jmp	short loc_CB67	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3864
//@ 
//@ loc_CB61:				; CODE XREF: DoGame+8DBj
//@ 		mov	ehz, 0C00h	; int16_t
//@ ; #line	"PS10.PAS" 3865
//@ 
//@ loc_CB67:				; CODE XREF: DoGame+8E9j
//@ 		mov	ax, Hx		; int16_t
//@ 		mov	ehx, ax		; int16_t
//@ 		mov	ax, Hy		; int16_t
//@ 		mov	ehy, ax		; int16_t
//@ ; #line	"PS10.PAS" 3867
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3869
//@ 
//@ loc_CB78:				; CODE XREF: DoGame+8BBj
//@ 		jmp	loc_CC40	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3871
//@ 
//@ loc_CB7B:				; CODE XREF: DoGame+86Dj
//@ 		mov	ax, Hx		; int16_t
//@ 		mov	ehx, ax		; int16_t
//@ 		mov	ax, Hy		; int16_t
//@ 		mov	ehy, ax		; int16_t
//@ 		mov	ax, Hz		; uint16_t
//@ 		mov	ehz, ax		; int16_t
//@ ; #line	"PS10.PAS" 3872
//@ 		cmp	ShakeLevel, 0	; int16_t
//@ 		jg	short loc_CB97	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_CC40	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3874
//@ 
//@ loc_CB97:				; CODE XREF: DoGame+91Cj
//@ 		cmp	ShakeLevel, 64h	; 'd' ; int16_t
//@ 		jle	short loc_CBA6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	w, 64h ; 'd'    ; uint16_t
//@ 		jmp	short loc_CBAC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CBA6:				; CODE XREF: DoGame+926j
//@ 		mov	ax, ShakeLevel	; int16_t
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"PS10.PAS" 3875
//@ 
//@ loc_CBAC:				; CODE XREF: DoGame+92Ej
//@ 		push	4
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFAh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, w		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 40h	; '@'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ehx, ax		; int16_t
//@ ; #line	"PS10.PAS" 3876
//@ 		push	4
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFAh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, w		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 40h	; '@'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ehy, ax		; int16_t
//@ ; #line	"PS10.PAS" 3877
//@ 		push	4
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFFh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, w		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ehz, ax		; int16_t
//@ ; #line	"PS10.PAS" 3878
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	ShakeLevel, ax	; int16_t
//@ ; #line	"PS10.PAS" 3879
//@ 		cmp	ShakeLevel, 0	; int16_t
//@ 		jge	short loc_CC40	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"PS10.PAS" 3885
//@ 
//@ loc_CC40:				; CODE XREF: DoGame:loc_C9C6j
//@ 					; DoGame+857j ...
//@ 		push	ehx		; int16_t
//@ 		push	ehy		; int16_t
//@ 		push	ica		; int16_t
//@ 		push	isa		; int16_t
//@ 		call	UpDatePlayerPos	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3887
//@ 		call	ProcessLights	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3890
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 822Eh
//@ 		push	di
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		push	0
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3891
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	di, 88CCh
//@ 		push	di
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		push	0
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3892
//@ 		push	word ptr LinesBUF+2 ; TLinesBuf*
//@ 		push	0
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		push	PImBSeg		; uint16_t
//@ 		call	StosW		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3894
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	FCount$0, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Nlines,	ax	; uint16_t
//@ ; #line	"PS10.PAS" 3896
//@ 		mov	ax, 1000h
//@ 		sub	ax, ehz		; int16_t
//@ 		mov	Hz2, ax		; uint16_t
//@ ; #line	"PS10.PAS" 3897
//@ 		mov	ax, Hz2		; uint16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	mysy, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3898
//@ 		mov	ax, Hz2		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		xor	cx, cx		; Logical Exclusive OR
//@ 		mov	bx, 8
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 800h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 200h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	word ptr EDI0, ax ; int32_t
//@ 		mov	word ptr EDI0+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 3899
//@ 		mov	ax, BLevel0	; uint16_t
//@ 		mov	BLevelW, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3902
//@ 		mov	ax, WallH	; uint16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	bx, ehz		; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	word ptr FloorV, ax ; int32_t
//@ 		mov	word ptr FloorV+2, dx ;	int32_t
//@ ; #line	"PS10.PAS" 3903
//@ 		mov	ax, WallH	; uint16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	bx, Hz2		; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	word ptr CellV,	ax ; int32_t
//@ 		mov	word ptr CellV+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 3904
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		mov	bx, ehz		; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, 1000h
//@ 		div	bx		; Unsigned Divide
//@ 		mov	BLevelF, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3905
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		mov	bx, Hz2		; uint16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, 1000h
//@ 		div	bx		; Unsigned Divide
//@ 		mov	BlevelC, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3908
//@ 		mov	al, byte ptr ehx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMx, ax		; int16_t
//@ 		mov	al, byte ptr ehy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMy, ax		; int16_t
//@ ; #line	"PS10.PAS" 3909
//@ 		push	HMx		; int16_t
//@ 		push	HMy		; int16_t
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	mi, 1		; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	b0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 3910
//@ 
//@ loc_CD51:				; CODE XREF: DoGame:loc_CE08j
//@ 		cmp	b0, 2		; uint16_t
//@ 		jb	short loc_CD62	; Jump if Below	(CF=1)
//@ 		cmp	mi, 4		; int16_t
//@ 		jl	short loc_CD62	; Jump if Less (SF!=OF)
//@ 		jmp	loc_CE0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3912
//@ 
//@ loc_CD62:				; CODE XREF: DoGame+AE0j DoGame+AE7j
//@ 		mov	ax, Nlines	; uint16_t
//@ 		cmp	ax, WinW	; uint16_t
//@ 		jnz	short loc_CD6F	; Jump if Not Zero (ZF=0)
//@ 		inc	b0		; uint16_t
//@ ; #line	"PS10.PAS" 3913
//@ 
//@ loc_CD6F:				; CODE XREF: DoGame+AF3j
//@ 		mov	ax, HMx		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		mov	word ptr [bp+var_4+2], ax
//@ 		mov	ax, HMx		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jg	short loc_CDB4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_CD8E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CD8A:				; CODE XREF: DoGame+B3Cj
//@ 		inc	x$0		; int16_t
//@ 
//@ loc_CD8E:				; CODE XREF: DoGame+B12j
//@ 		push	x$0		; int16_t
//@ 		mov	ax, HMy		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		push	ax
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		push	x$0		; int16_t
//@ 		mov	ax, HMy		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		push	ax
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	ax, x$0		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jnz	short loc_CD8A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3914
//@ 
//@ loc_CDB4:				; CODE XREF: DoGame+B0Dj
//@ 		mov	ax, HMy		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	word ptr [bp+var_4+2], ax
//@ 		mov	ax, HMy		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jg	short loc_CDFB	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_CDD5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CDD1:				; CODE XREF: DoGame+B83j
//@ 		inc	y		; int16_t
//@ 
//@ loc_CDD5:				; CODE XREF: DoGame+B59j
//@ 		mov	ax, HMx		; int16_t
//@ 		sub	ax, mi		; int16_t
//@ 		push	ax
//@ 		push	y		; int16_t
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	ax, HMx		; int16_t
//@ 		add	ax, mi		; int16_t
//@ 		push	ax
//@ 		push	y		; int16_t
//@ 		call	MapXY		; function near	PASCAL returns void
//@ 		mov	ax, y		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jnz	short loc_CDD1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3915
//@ 
//@ loc_CDFB:				; CODE XREF: DoGame+B54j
//@ 		inc	mi		; int16_t
//@ ; #line	"PS10.PAS" 3916
//@ 		cmp	mi, 1Eh		; int16_t
//@ 		jle	short loc_CE08	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	short loc_CE0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3917
//@ 
//@ loc_CE08:				; CODE XREF: DoGame+B8Ej
//@ 		jmp	loc_CD51	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3919
//@ 
//@ loc_CE0B:				; CODE XREF: DoGame+AE9j DoGame+B90j
//@ 		mov	al, byte ptr ehx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMx, ax		; int16_t
//@ 		mov	al, byte ptr ehy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	HMy, ax		; int16_t
//@ 		mov	ax, mi		; int16_t
//@ 		add	ax, 3		; Add
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	MapR, ax	; int16_t
//@ ; #line	"PS10.PAS" 3920
//@ 		mov	di, offset ObjAmb ; struct ObjAmb$Type
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ObjAmbU ; struct ObjAmb$Type
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm3Anyt14Word ; Bitcopy of any type variable
//@ ; #line	"PS10.PAS" 3923
//@ 		call	CalcYMin	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3925
//@ 		call	BuildFloorCell	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 3932
//@ 
//@ loc_CE3E:				; CODE XREF: DoGame:loc_C868j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	word ptr Time, ax ; int32_t
//@ 		adc	word ptr Time+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 3933
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	word ptr ZTime,	ax ; int32_t
//@ 		adc	word ptr ZTime+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 3934
//@ 		mov	ax, t1		; uint16_t
//@ 		add	MTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3935
//@ 		mov	al, byte ptr t1	; uint16_t
//@ 		add	SecCounter, al	; uint8_t
//@ ; #line	"PS10.PAS" 3936
//@ 		mov	ax, t1		; uint16_t
//@ 		add	MortalTimer, ax	; int16_t
//@ ; #line	"PS10.PAS" 3937
//@ 		cmp	SecCounter, 8Ch	; 'Œ' ; uint8_t
//@ 		jb	short loc_CE80	; Jump if Below	(CF=1)
//@ 		sub	SecCounter, 8Ch	; 'Œ' ; uint8_t
//@ 		mov	NewSecond, 1	; bool
//@ 		jmp	short loc_CE85	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3938
//@ 
//@ loc_CE80:				; CODE XREF: DoGame+BFCj
//@ 		mov	NewSecond, 0	; bool
//@ ; #line	"PS10.PAS" 3939
//@ 
//@ loc_CE85:				; CODE XREF: DoGame+C08j
//@ 		cmp	MortalTimer, 20h ; ' ' ; int16_t
//@ 		jl	short loc_CE98	; Jump if Less (SF!=OF)
//@ 		sub	MortalTimer, 20h ; ' ' ; int16_t
//@ 		mov	MortalTick, 1	; bool
//@ 		jmp	short loc_CE9D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3940
//@ 
//@ loc_CE98:				; CODE XREF: DoGame+C14j
//@ 		mov	MortalTick, 0	; bool
//@ ; #line	"PS10.PAS" 3942
//@ 
//@ loc_CE9D:				; CODE XREF: DoGame+C20j
//@ 		cmp	MTime, 0Ah	; uint16_t
//@ 		mov	al, 0
//@ 		jbe	short loc_CEA7	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_CEA7:				; CODE XREF: DoGame+C2Ej
//@ 		mov	OAnimate, al	; bool
//@ ; #line	"PS10.PAS" 3943
//@ 		cmp	OAnimate, 0	; bool
//@ 		jz	short loc_CEB6	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MTime, ax	; uint16_t
//@ ; #line	"PS10.PAS" 3946
//@ 
//@ loc_CEB6:				; CODE XREF: DoGame+C39j
//@ 		cmp	GameActive, 0	; bool
//@ 		jnz	short loc_CEC0	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_D298	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3947
//@ 
//@ loc_CEC0:				; CODE XREF: DoGame+C45j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_CECA	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D298	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CECA:				; CODE XREF: DoGame+C4Fj
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_CED4	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D298	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3948
//@ 
//@ loc_CED4:				; CODE XREF: DoGame+C59j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_CEDF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CEDB:				; CODE XREF: DoGame+101Fj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_CEDF:				; CODE XREF: DoGame+C63j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_CEF9	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_D28E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3950
//@ 
//@ loc_CEF9:				; CODE XREF: DoGame+C7Ej
//@ 		cmp	word ptr es:[di+4Ah], 0	; Compare Two Operands
//@ 		jle	short loc_CF07	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	es:[di+4Ah], ax	; Integer Subtraction
//@ ; #line	"PS10.PAS" 3951
//@ 
//@ loc_CF07:				; CODE XREF: DoGame+C88j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4Ah], 0	; Compare Two Operands
//@ 		jge	short loc_CF17	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4Ah], ax
//@ ; #line	"PS10.PAS" 3952
//@ 
//@ loc_CF17:				; CODE XREF: DoGame+C99j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 4000h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		ja	short loc_CF28	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_D28E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3953
//@ 
//@ loc_CF28:				; CODE XREF: DoGame+CADj
//@ 		cmp	word ptr es:[di+4Ah], 0	; Compare Two Operands
//@ 		jz	short loc_CF32	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D28E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CF32:				; CODE XREF: DoGame+CB7j
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_CF3C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_D28E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CF3C:				; CODE XREF: DoGame+CC1j
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		ja	short loc_CF4C	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_D28E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3954
//@ 
//@ loc_CF4C:				; CODE XREF: DoGame+CD1j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+48h]
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		add	di, 0E440h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"PS10.PAS" 3956
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ ; #line	"PS10.PAS" 3957
//@ 		mov	al, es:[di+24h]
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jz	short loc_CF77	; Jump if Zero (ZF=1)
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short loc_CF81	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3958
//@ 
//@ loc_CF77:				; CODE XREF: DoGame+CFBj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+24h], 5
//@ 		jmp	short loc_CF89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3959
//@ 
//@ loc_CF81:				; CODE XREF: DoGame+CFFj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+24h], 4
//@ ; #line	"PS10.PAS" 3960
//@ 
//@ loc_CF89:				; CODE XREF: DoGame+D09j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+38h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 398h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	WpnShx,	ax	; int16_t
//@ 		mov	ax, es:[di+3Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 398h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	WpnShy,	ax	; int16_t
//@ ; #line	"PS10.PAS" 3962
//@ 		cmp	word ptr es:[di+48h], 7	; Compare Two Operands
//@ 		jnz	short loc_CFC3	; Jump if Not Zero (ZF=0)
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	n$0		; int16_t
//@ 		call	AddMine		; function far PASCAL returns void
//@ 		jmp	loc_D1F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3963
//@ 
//@ loc_CFC3:				; CODE XREF: DoGame+D37j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+48h], 8	; Compare Two Operands
//@ 		jnz	short loc_D044	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3965
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, WpnShx	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, WpnShy	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, es:[di+3Eh]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+3Ah]
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		mov	ax, es:[di+38h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		add	ax, 40h	; '@'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	n$0		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	0FFh
//@ 		call	AddRocket	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3966
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+1Ah], 78h ; 'x'
//@ ; #line	"PS10.PAS" 3967
//@ 		mov	ax, 4000h
//@ 		sub	ax, es:[di+1Eh]	; Integer Subtraction
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"PS10.PAS" 3968
//@ 		cmp	n$0, 0		; int16_t
//@ 		jnz	short loc_D041	; Jump if Not Zero (ZF=0)
//@ 		mov	ShakeLevel, 46h	; 'F' ; int16_t
//@ ; #line	"PS10.PAS" 3969
//@ 
//@ loc_D041:				; CODE XREF: DoGame+DC3j
//@ 		jmp	loc_D1F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3970
//@ 
//@ loc_D044:				; CODE XREF: DoGame+D55j
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di], 16h ; Signed Multiply
//@ 		mov	ax, [di-326Eh]
//@ 		or	ax, [di-326Ch]	; Logical Inclusive OR
//@ 		jz	short loc_D0A7	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3971
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, WpnShx	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, WpnShy	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, es:[di+3Eh]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+3Ah]
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		mov	ax, es:[di+38h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		push	word ptr es:[di+10h]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	n$0		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	0FFh
//@ 		call	AddRocket	; function far PASCAL returns void
//@ 		jmp	loc_D1F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3973
//@ 
//@ loc_D0A7:				; CODE XREF: DoGame+DDDj
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Ah], 1	; Compare Two Operands
//@ 		jnz	short loc_D0F0	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3974
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, WpnShx	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, WpnShy	; int16_t
//@ 		push	ax
//@ 		push	word ptr es:[di+3Eh]
//@ 		mov	ax, es:[di+3Ah]
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		mov	ax, es:[di+38h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		push	word ptr es:[di+10h]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	n$0		; int16_t
//@ 		push	1
//@ 		call	SendFastRocket	; function far PASCAL returns void
//@ 		jmp	loc_D1F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3977
//@ 
//@ loc_D0F0:				; CODE XREF: DoGame+E39j
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	word ptr [bp+var_C+2], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, word ptr [bp+var_C+2] ; Compare Two	Operands
//@ 		jbe	short loc_D105	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_D1F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D105:				; CODE XREF: DoGame+E8Aj
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_D10E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D10A:				; CODE XREF: DoGame+F7Fj
//@ 		inc	j		; uint16_t
//@ ; #line	"PS10.PAS" 3978
//@ 
//@ loc_D10E:				; CODE XREF: DoGame+E92j
//@ 		push	21h ; '!'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, WpnShx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	21h ; '!'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, WpnShy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	11h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	640h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3Ah]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 320h	; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	640h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+38h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 320h	; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 14h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	n$0		; int16_t
//@ 		push	2
//@ 		call	SendFastRocket	; function far PASCAL returns void
//@ 		mov	ax, j		; uint16_t
//@ 		cmp	ax, word ptr [bp+var_C+2] ; Compare Two	Operands
//@ 		jz	short loc_D1F8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D10A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3985
//@ 
//@ loc_D1F8:				; CODE XREF: DoGame+D4Aj
//@ 					; DoGame:loc_D041j ...
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+48h]
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	ax, [di-1BB2h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4Ah], ax
//@ ; #line	"PS10.PAS" 3986
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		dec	byte ptr es:[di+2Dh] ; Decrement by 1
//@ ; #line	"PS10.PAS" 3987
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+48h], 1	; Compare Two Operands
//@ 		jnz	short loc_D22D	; Jump if Not Zero (ZF=0)
//@ 		cmp	byte ptr es:[di+2Eh], 1	; Compare Two Operands
//@ 		jnz	short loc_D22D	; Jump if Not Zero (ZF=0)
//@ 		mov	byte ptr es:[di+2Eh], 0C8h ; 'È'
//@ ; #line	"PS10.PAS" 3988
//@ 
//@ loc_D22D:				; CODE XREF: DoGame+FA9j DoGame+FB0j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+48h], 7	; Compare Two Operands
//@ 		jz	short loc_D268	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 3989
//@ 		mov	ax, es:[di+3Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0C6h ; 'Æ'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+38h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0C6h ; 'Æ'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		push	6
//@ 		push	18h
//@ 		push	1Ah
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3990
//@ 
//@ loc_D268:				; CODE XREF: DoGame+FBFj
//@ 		push	0
//@ 		push	0FFFFh
//@ 		push	n$0		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+48h]
//@ 		add	ax, 14h		; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 3991
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_D28E	; Jump if Not Zero (ZF=0)
//@ 		mov	WeaponActive, 1	; bool
//@ ; #line	"PS10.PAS" 3993
//@ 
//@ loc_D28E:				; CODE XREF: DoGame+C80j DoGame+CAFj ...
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short loc_D298	; Jump if Zero (ZF=1)
//@ 		jmp	loc_CEDB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 3995
//@ 
//@ loc_D298:				; CODE XREF: DoGame+C47j DoGame+C51j ...
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_D310	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 3996
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_D2AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D2A6:				; CODE XREF: DoGame+1098j
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 3997
//@ 
//@ loc_D2AA:				; CODE XREF: DoGame+102Ej
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"PS10.PAS" 3998
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_D309	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jnz	short loc_D309	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4000
//@ 		mov	ax, t1		; uint16_t
//@ 		add	es:[di+4Ch], ax	; Add
//@ 		cmp	word ptr es:[di+4Ch], 0F0h ; 'ð' ; Compare Two Operands
//@ 		jle	short loc_D2DD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+4Ch], 0F0h ; 'ð'
//@ ; #line	"PS10.PAS" 4001
//@ 
//@ loc_D2DD:				; CODE XREF: DoGame+105Fj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4Ch], 0F0h ; 'ð' ; Compare Two Operands
//@ 		jl	short loc_D309	; Jump if Less (SF!=OF)
//@ ; #line	"PS10.PAS" 4002
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 0C0h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_D309	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 4003
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_D303	; Jump if Zero (ZF=1)
//@ 		push	n$0		; int16_t
//@ 		call	ReinitPlayer	; function near	PASCAL returns void
//@ 		jmp	short loc_D309	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4004
//@ 
//@ loc_D303:				; CODE XREF: DoGame+1082j
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 4005
//@ 
//@ loc_D309:				; CODE XREF: DoGame+1049j DoGame+1050j ...
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_D2A6	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4010
//@ 
//@ loc_D310:				; CODE XREF: DoGame+1027j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_D321	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_D321	; Jump if Not Zero (ZF=0)
//@ 		call	CheckFloorLinks	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4013
//@ 
//@ loc_D321:				; CODE XREF: DoGame+109Fj DoGame+10A6j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_D32B	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D32B:				; CODE XREF: DoGame+10B0j
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_D335	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D926	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4014
//@ 
//@ loc_D335:				; CODE XREF: DoGame+10BAj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_D340	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D33C:				; CODE XREF: DoGame+16ADj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_D340:				; CODE XREF: DoGame+10C4j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_D35B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_D91C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4015
//@ 
//@ loc_D35B:				; CODE XREF: DoGame+10E0j
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	word ptr [bp+var_8+2], ax
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, word ptr [bp+var_8+2] ; Compare Two	Operands
//@ 		jle	short loc_D376	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_D91C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D376:				; CODE XREF: DoGame+10FBj
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_D37F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D37B:				; CODE XREF: DoGame+16A3j
//@ 		inc	x$0		; int16_t
//@ 
//@ loc_D37F:				; CODE XREF: DoGame+1103j
//@ 		cmp	x$0, 0		; int16_t
//@ 		jge	short loc_D389	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_D911	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D389:				; CODE XREF: DoGame+110Ej
//@ 		cmp	x$0, 3Fh ; '?'  ; int16_t
//@ 		jle	short loc_D393	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_D911	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4016
//@ 
//@ loc_D393:				; CODE XREF: DoGame+1118j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	word ptr [bp+var_8], ax
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, word ptr [bp+var_8]	; Compare Two Operands
//@ 		jle	short loc_D3B1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_D911	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D3B1:				; CODE XREF: DoGame+1136j
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_D3BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D3B6:				; CODE XREF: DoGame+1698j
//@ 		inc	y		; int16_t
//@ 
//@ loc_D3BA:				; CODE XREF: DoGame+113Ej
//@ 		cmp	y, 0		; int16_t
//@ 		jge	short loc_D3C4	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D3C4:				; CODE XREF: DoGame+1149j
//@ 		cmp	y, 3Fh ; '?'    ; int16_t
//@ 		jle	short loc_D3CE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4017
//@ 
//@ loc_D3CE:				; CODE XREF: DoGame+1153j
//@ 		imul	ax, y, 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, x$0, 2C0h	; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"PS10.PAS" 4018
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnb	short loc_D3F3	; Jump if Not Below (CF=0)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D3F3:				; CODE XREF: DoGame+1178j
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_D3FA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4019
//@ 
//@ loc_D3FA:				; CODE XREF: DoGame+117Fj
//@ 		push	8Ch ; 'Œ'
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74AEh]
//@ 		add	ax, 5Ah	; 'Z'   ; Add
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		push	ax
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		pop	cx
//@ 		pop	bx
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_D44F	; Jump if Less (SF!=OF)
//@ 		jle	short loc_D448	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D448:				; CODE XREF: DoGame+11CDj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_D44F	; Jump if Below	(CF=1)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4022
//@ 
//@ loc_D44F:				; CODE XREF: DoGame+11CBj DoGame+11D4j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	b0, ax		; uint16_t
//@ ; #line	"PS10.PAS" 4023
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_D479	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_D479	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 4024
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74B0h]
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4025
//@ 
//@ loc_D479:				; CODE XREF: DoGame+11EBj DoGame+11EFj
//@ 		cmp	i, 0		; int16_t
//@ 		jle	short loc_D4BB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 4026
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		add	ax, 18h		; Add
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jg	short loc_D4B8	; Jump if Greater (ZF=0	& SF=OF)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0Ah		; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_D4BB	; Jump if Greater or Equal (SF=OF)
//@ 
//@ loc_D4B8:				; CODE XREF: DoGame+1224j
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4028
//@ 
//@ loc_D4BB:				; CODE XREF: DoGame+1208j DoGame+1240j
//@ 		mov	b0, 28h	; '('   ; uint16_t
//@ ; #line	"PS10.PAS" 4029
//@ 		cmp	i, 0		; int16_t
//@ 		jg	short loc_D4CB	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4031
//@ 
//@ loc_D4CB:				; CODE XREF: DoGame+1250j
//@ 		mov	ax, i		; int16_t
//@ ; #line	"PS10.PAS" 4032
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jge	short loc_D4D6	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_D599	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D4D6:				; CODE XREF: DoGame+125Bj
//@ 		cmp	ax, 8		; Compare Two Operands
//@ 		jle	short loc_D4DE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_D599	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4033
//@ 
//@ loc_D4DE:				; CODE XREF: DoGame+1263j
//@ 		mov	ax, i		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+25h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		mov	es:[di+25h], al
//@ ; #line	"PS10.PAS" 4034
//@ 		mov	di, i		; int16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	dl, [di-1BB8h]
//@ 		mov	ax, i		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	es:[di+2Dh], dl	; Add
//@ ; #line	"PS10.PAS" 4035
//@ 		mov	ax, i		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+2Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, i		; int16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		cmp	ax, [di-1BBAh]	; Compare Two Operands
//@ 		jle	short loc_D545	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, i		; int16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	dl, [di-1BBAh]
//@ 		mov	ax, i		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+2Dh], dl
//@ ; #line	"PS10.PAS" 4036
//@ 
//@ loc_D545:				; CODE XREF: DoGame+12B6j
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	ax, i		; int16_t
//@ 		add	ax, 32h	; '2'   ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4037
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Eh ; '>'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4038
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_D591	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+48h]
//@ 		cmp	ax, i		; int16_t
//@ 		jge	short loc_D591	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 4039
//@ 		push	i		; int16_t
//@ 		call	SetWeapon	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4040
//@ 
//@ loc_D591:				; CODE XREF: DoGame+1303j DoGame+1310j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4041
//@ 		jmp	loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4043
//@ 
//@ loc_D599:				; CODE XREF: DoGame+125Dj DoGame+1265j
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jge	short loc_D5A1	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_D627	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D5A1:				; CODE XREF: DoGame+1326j
//@ 		cmp	ax, 63h	; 'c'   ; Compare Two Operands
//@ 		jle	short loc_D5A9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_D627	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4044
//@ 
//@ loc_D5A9:				; CODE XREF: DoGame+132Ej
//@ 		mov	ax, i		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ah
//@ 		idiv	cx		; Signed Divide
//@ 		mov	j, ax		; uint16_t
//@ ; #line	"PS10.PAS" 4045
//@ 		mov	ax, j		; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+2Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, j		; uint16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		cmp	ax, [di-1BBAh]	; Compare Two Operands
//@ 		jge	short loc_D624	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 4047
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	ax, j		; uint16_t
//@ 		add	ax, 32h	; '2'   ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4048
//@ 		push	n$0		; int16_t
//@ 		push	j		; uint16_t
//@ 		imul	ax, j, 0Ah	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, i		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	di, j		; uint16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	ax, [di-1BBCh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	AddAmmoToPlayer	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4049
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4051
//@ 
//@ loc_D624:				; CODE XREF: DoGame+1358j
//@ 		jmp	loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4053
//@ 
//@ loc_D627:				; CODE XREF: DoGame+1328j DoGame+1330j
//@ 		cmp	ax, 65h	; 'e'   ; Compare Two Operands
//@ 		jl	short loc_D671	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jg	short loc_D671	; Jump if Greater (ZF=0	& SF=OF)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+28h], 64h ; 'd' ; Compare Two Operands
//@ 		jge	short loc_D66E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 4055
//@ 		mov	ax, i		; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		imul	ax, 0Ah		; Signed Multiply
//@ 		add	es:[di+28h], ax	; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4056
//@ 		cmp	word ptr es:[di+28h], 64h ; 'd' ; Compare Two Operands
//@ 		jle	short loc_D65A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+28h], 64h ; 'd'
//@ ; #line	"PS10.PAS" 4057
//@ 
//@ loc_D65A:				; CODE XREF: DoGame+13DCj
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Eh ; '>'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4058
//@ 
//@ loc_D66E:				; CODE XREF: DoGame+13C3j
//@ 		jmp	loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4059
//@ 
//@ loc_D671:				; CODE XREF: DoGame+13B4j DoGame+13B9j
//@ 		cmp	ax, 78h	; 'x'   ; Compare Two Operands
//@ 		jnz	short loc_D6A9	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+28h], 0C8h ; 'È' ; Compare Two Operands
//@ 		jge	short loc_D6A6	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 4061
//@ 		mov	word ptr es:[di+28h], 0C8h ; 'È'
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ 		mov	b0, 78h	; 'x'   ; uint16_t
//@ ; #line	"PS10.PAS" 4062
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Eh ; '>'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4063
//@ 
//@ loc_D6A6:				; CODE XREF: DoGame+1409j
//@ 		jmp	loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4065
//@ 
//@ loc_D6A9:				; CODE XREF: DoGame+13FEj
//@ 		cmp	ax, 79h	; 'y'   ; Compare Two Operands
//@ 		jl	short loc_D70D	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 82h	; '‚'   ; Compare Two Operands
//@ 		jg	short loc_D70D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+27h], 0C8h ; 'È' ; Compare Two Operands
//@ 		jnb	short loc_D70A	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 4067
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ 		mov	ax, i		; int16_t
//@ 		sub	ax, 78h	; 'x'   ; Integer Subtraction
//@ 		imul	ax, 19h		; Signed Multiply
//@ 		add	w, ax		; uint16_t
//@ ; #line	"PS10.PAS" 4068
//@ 		cmp	w, 0C8h	; 'È'   ; uint16_t
//@ 		jbe	short loc_D6E1	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	w, 0C8h	; 'È'   ; uint16_t
//@ ; #line	"PS10.PAS" 4069
//@ 
//@ loc_D6E1:				; CODE XREF: DoGame+1463j
//@ 		mov	al, byte ptr w	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+27h], al
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ 		mov	b0, 3Ch	; '<'   ; uint16_t
//@ ; #line	"PS10.PAS" 4070
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Ch ; '<'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4071
//@ 
//@ loc_D70A:				; CODE XREF: DoGame+1445j
//@ 		jmp	loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4073
//@ 
//@ loc_D70D:				; CODE XREF: DoGame+1436j DoGame+143Bj
//@ 		cmp	ax, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnz	short loc_D754	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4Eh], 78h ; 'x' ; Compare Two Operands
//@ 		jge	short loc_D751	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 4075
//@ 		add	word ptr es:[di+4Eh], 28h ; '(' ; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ 		mov	b0, 78h	; 'x'   ; uint16_t
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Ch ; '<'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4076
//@ 		cmp	n$0, 0		; int16_t
//@ 		jnz	short loc_D751	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aYouGotInvisibi ; "YOU GOT INVISIBILITY"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4077
//@ 
//@ loc_D751:				; CODE XREF: DoGame+14A4j DoGame+14CFj
//@ 		jmp	loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4078
//@ 
//@ loc_D754:				; CODE XREF: DoGame+149Aj
//@ 		cmp	ax, 84h	; '„'   ; Compare Two Operands
//@ 		jnz	short loc_D79B	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+52h], 5Ah ; 'Z' ; Compare Two Operands
//@ 		jge	short loc_D798	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 4080
//@ 		add	word ptr es:[di+52h], 28h ; '(' ; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ 		mov	b0, 78h	; 'x'   ; uint16_t
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Ch ; '<'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4081
//@ 		cmp	n$0, 0		; int16_t
//@ 		jnz	short loc_D798	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aYouGotTheRefle ; "YOU GOT THE REFLECTOR"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4082
//@ 
//@ loc_D798:				; CODE XREF: DoGame+14EBj DoGame+1516j
//@ 		jmp	loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4083
//@ 
//@ loc_D79B:				; CODE XREF: DoGame+14E1j
//@ 		cmp	ax, 85h	; '…'   ; Compare Two Operands
//@ 		jnz	short loc_D7E1	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+50h], 5Ah ; 'Z' ; Compare Two Operands
//@ 		jge	short loc_D7DF	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"PS10.PAS" 4085
//@ 		add	word ptr es:[di+50h], 1Eh ; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ 		mov	b0, 12Ch	; uint16_t
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Ch ; '<'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4086
//@ 		cmp	n$0, 0		; int16_t
//@ 		jnz	short loc_D7DF	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aYouGotTheChoji ; "YOU GOT THE CHOJIN MASK"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4087
//@ 
//@ loc_D7DF:				; CODE XREF: DoGame+1532j DoGame+155Dj
//@ 		jmp	short loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4089
//@ 
//@ loc_D7E1:				; CODE XREF: DoGame+1528j
//@ 		cmp	ax, 8Dh	; ''   ; Compare Two Operands
//@ 		jl	short loc_D834	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 8Fh	; ''   ; Compare Two Operands
//@ 		jg	short loc_D834	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"PS10.PAS" 4090
//@ 		mov	ax, i		; int16_t
//@ 		add	ax, 4		; Add
//@ 		sub	ax, 8Dh	; ''   ; Integer Subtraction
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		or	ax, cx		; Logical Inclusive OR
//@ 		or	dx, bx		; Logical Inclusive OR
//@ 		mov	es:[di+2Ah], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4091
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3Fh ; '?'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ 		mov	b0, 0Ah		; uint16_t
//@ ; #line	"PS10.PAS" 4092
//@ 		jmp	short loc_D852	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4094
//@ 
//@ loc_D834:				; CODE XREF: DoGame+156Ej DoGame+1573j
//@ 		cmp	ax, 0FFh	; Compare Two Operands
//@ 		jnz	short loc_D852	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, x$0		; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		push	ax
//@ 		mov	ax, y		; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	0FFFFh
//@ 		push	0FFFFh
//@ 		push	n$0		; int16_t
//@ 		call	AnimateSwitches	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4097
//@ 
//@ loc_D852:				; CODE XREF: DoGame+1320j
//@ 					; DoGame:loc_D624j ...
//@ 		cmp	i, 0		; int16_t
//@ 		jz	short loc_D85C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4099
//@ 
//@ loc_D85C:				; CODE XREF: DoGame+15E1j
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_D86B	; Jump if Not Zero (ZF=0)
//@ 		mov	GShadeDir, 1	; int16_t
//@ ; #line	"PS10.PAS" 4100
//@ 
//@ loc_D86B:				; CODE XREF: DoGame+15EDj
//@ 		mov	ax, x$0		; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		push	ax
//@ 		mov	ax, y		; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	0FFFFh
//@ 		push	0FFFFh
//@ 		push	n$0		; int16_t
//@ 		call	AnimateSwitches	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4101
//@ 		push	6Bh ; 'k'
//@ 		mov	al, byte ptr n$0 ; int16_t
//@ 		push	ax
//@ 		push	0
//@ 		push	x$0		; int16_t
//@ 		push	y		; int16_t
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4102
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_D8FF	; Jump if Zero (ZF=1)
//@ 		cmp	ReCount, 7Eh ; '~' ; uint16_t
//@ 		jnb	short loc_D8FD	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 4104
//@ 		inc	ReCount		; uint16_t
//@ ; #line	"PS10.PAS" 4105
//@ 		imul	ax, ReCount, 0Ah ; uint16_t
//@ 		les	di, ReObjects	; TReObject*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF6h	; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"PS10.PAS" 4106
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, x$0		; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, y		; int16_t
//@ 		mov	es:[di+2], ax
//@ 		imul	ax, b0,	8Ch	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, word ptr Time ; int32_t
//@ 		adc	dx, word ptr Time+2 ; int32_t
//@ 		mov	es:[di+6], ax
//@ 		mov	es:[di+8], dx
//@ ; #line	"PS10.PAS" 4107
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di], 7Ah ;	'z'
//@ ; #line	"PS10.PAS" 4108
//@ 
//@ loc_D8FD:				; CODE XREF: DoGame+1631j
//@ 		jmp	short loc_D906	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D8FF:				; CODE XREF: DoGame+162Aj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"PS10.PAS" 4111
//@ 
//@ loc_D906:				; CODE XREF: DoGame+114Bj DoGame+1155j ...
//@ 		mov	ax, y		; int16_t
//@ 		cmp	ax, word ptr [bp+var_8]	; Compare Two Operands
//@ 		jz	short loc_D911	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D3B6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D911:				; CODE XREF: DoGame+1110j DoGame+111Aj ...
//@ 		mov	ax, x$0		; int16_t
//@ 		cmp	ax, word ptr [bp+var_8+2] ; Compare Two	Operands
//@ 		jz	short loc_D91C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D37B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D91C:				; CODE XREF: DoGame+10E2j DoGame+10FDj ...
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short loc_D926	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D33C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4120
//@ 
//@ loc_D926:				; CODE XREF: DoGame+10B2j DoGame+10BCj ...
//@ 		cmp	GameActive, 0	; bool
//@ 		jz	short loc_D951	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4122
//@ 		call	AnimateProcesses ; function far	PASCAL returns void
//@ ; #line	"PS10.PAS" 4123
//@ 		cmp	Animation, 0	; bool
//@ 		jz	short loc_D94C	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4124
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_D94C	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_D94C	; Jump if Not Zero (ZF=0)
//@ 		call	AnimateMonsters	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4125
//@ 
//@ loc_D94C:				; CODE XREF: DoGame+16C1j DoGame+16C8j ...
//@ 		call	AnimateZMovement ; function far	PASCAL returns void
//@ ; #line	"PS10.PAS" 4130
//@ 
//@ loc_D951:				; CODE XREF: DoGame+16B5j
//@ 		call	AnimateObjects	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4131
//@ 		call	AnimateBlows	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4132
//@ 		cmp	GameActive, 0	; bool
//@ 		jz	short loc_D978	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4133
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_D975	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_D975	; Jump if Not Zero (ZF=0)
//@ 		call	AnimateRockets	; function near	PASCAL returns void
//@ 		jmp	short loc_D978	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4134
//@ 
//@ loc_D975:				; CODE XREF: DoGame+16F1j DoGame+16F8j
//@ 		call	AddClientProcesses ; function near PASCAL returns void
//@ ; #line	"PS10.PAS" 4137
//@ 
//@ loc_D978:				; CODE XREF: DoGame+16EAj DoGame+16FDj
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_D995	; Jump if Zero (ZF=1)
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_D992	; Jump if Zero (ZF=1)
//@ 		cmp	CurOwner, 0	; uint16_t
//@ 		jnz	short loc_D995	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_D992:				; CODE XREF: DoGame+1713j
//@ 		jmp	loc_DB69	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4139
//@ 
//@ loc_D995:				; CODE XREF: DoGame+1707j DoGame+171Aj
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_D99F	; Jump if Zero (ZF=1)
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4141
//@ 
//@ loc_D99F:				; CODE XREF: DoGame+1724j
//@ 		call	InsertPlayers	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4142
//@ 		call	InsertMonsters	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4143
//@ 		call	StartPaint	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4145
//@ 		call	DrawHoles	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4147
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_D9B7	; Jump if Zero (ZF=1)
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4150
//@ 
//@ loc_D9B7:				; CODE XREF: DoGame+173Cj
//@ 		cmp	FCount$0, 0	; uint16_t
//@ 		ja	short loc_D9C1	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_DB34	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4151
//@ 
//@ loc_D9C1:				; CODE XREF: DoGame+1746j
//@ 		mov	ax, FCount$0	; uint16_t
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jge	short loc_D9CC	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_DB34	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D9CC:				; CODE XREF: DoGame+1751j
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_D9D5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_D9D1:				; CODE XREF: DoGame+18BBj
//@ 		dec	i		; int16_t
//@ ; #line	"PS10.PAS" 4152
//@ 
//@ loc_D9D5:				; CODE XREF: DoGame+1759j
//@ 		imul	ax, i, 0Eh	; int16_t
//@ 		les	di, FramesList	; TFrame*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF2h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"PS10.PAS" 4153
//@ 		mov	al, es:[di+0Ah]
//@ ; #line	"PS10.PAS" 4154
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_DA20	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_DA20	; Jump if Above	(CF=0 &	ZF=0)
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandFrame	; function near	PASCAL returns void
//@ 		jmp	loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4155
//@ 
//@ loc_DA20:				; CODE XREF: DoGame+177Aj DoGame+177Ej
//@ 		cmp	al, 79h	; 'y'   ; Compare Two Operands
//@ 		jnz	short loc_DA42	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandObject	; function near	PASCAL returns void
//@ 		jmp	loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4156
//@ 
//@ loc_DA42:				; CODE XREF: DoGame+17ACj
//@ 		cmp	al, 7Ah	; 'z'   ; Compare Two Operands
//@ 		jnz	short loc_DA64	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Expand3dObject	; function near	PASCAL returns void
//@ 		jmp	loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4157
//@ 
//@ loc_DA64:				; CODE XREF: DoGame+17CEj
//@ 		cmp	al, 7Bh	; '{'   ; Compare Two Operands
//@ 		jnz	short loc_DA87	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandMonster	; function near	PASCAL returns void
//@ 		jmp	loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4158
//@ 
//@ loc_DA87:				; CODE XREF: DoGame+17F0j
//@ 		cmp	al, 7Ch	; '|'   ; Compare Two Operands
//@ 		jnz	short loc_DAA2	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandRocket	; function near	PASCAL returns void
//@ 		jmp	loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4159
//@ 
//@ loc_DAA2:				; CODE XREF: DoGame+1813j
//@ 		cmp	al, 7Dh	; '}'   ; Compare Two Operands
//@ 		jnz	short loc_DABC	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandMine	; function near	PASCAL returns void
//@ 		jmp	short loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4160
//@ 
//@ loc_DABC:				; CODE XREF: DoGame+182Ej
//@ 		cmp	al, 7Fh	; ''   ; Compare Two Operands
//@ 		jnz	short loc_DAD6	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandBlow	; function near	PASCAL returns void
//@ 		jmp	short loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4161
//@ 
//@ loc_DAD6:				; CODE XREF: DoGame+1848j
//@ 		cmp	al, 81h	; ''   ; Compare Two Operands
//@ 		jnz	short loc_DAF8	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandPlayer	; function near	PASCAL returns void
//@ 		jmp	short loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4162
//@ 
//@ loc_DAF8:				; CODE XREF: DoGame+1862j
//@ 		cmp	al, 7Eh	; '~'   ; Compare Two Operands
//@ 		jnz	short loc_DB12	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandSepPart	; function near	PASCAL returns void
//@ 		jmp	short loc_DB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4163
//@ 
//@ loc_DB12:				; CODE XREF: DoGame+1884j
//@ 		cmp	al, 80h	; '€'   ; Compare Two Operands
//@ 		jnz	short loc_DB2A	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExpandAmmoBag	; function near	PASCAL returns void
//@ 
//@ loc_DB2A:				; CODE XREF: DoGame+17A7j DoGame+17C9j ...
//@ 		cmp	i, 1		; int16_t
//@ 		jz	short loc_DB34	; Jump if Zero (ZF=1)
//@ 		jmp	loc_D9D1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4166
//@ 
//@ loc_DB34:				; CODE XREF: DoGame+1748j DoGame+1753j ...
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_DB3E	; Jump if Zero (ZF=1)
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4168
//@ 
//@ loc_DB3E:				; CODE XREF: DoGame+18C3j
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_DB51	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4169
//@ 		cmp	MapMode, 0	; bool
//@ 		jz	short loc_DB51	; Jump if Zero (ZF=1)
//@ 		call	ShowMap		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4170
//@ 
//@ loc_DB51:				; CODE XREF: DoGame+18CDj DoGame+18D4j
//@ 		call	EndPaint	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4171
//@ 		cmp	GameActive, 0	; bool
//@ 		jz	short loc_DB67	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4172
//@ 		cmp	OAnimate, 0	; bool
//@ 		jz	short loc_DB67	; Jump if Zero (ZF=1)
//@ 		call	AnimateRespawnObjects ;	function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4176
//@ 
//@ loc_DB67:				; CODE XREF: DoGame+18E3j DoGame+18EAj
//@ 		jmp	short loc_DB90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4180
//@ 
//@ loc_DB69:				; CODE XREF: DoGame:loc_D992j
//@ 					; DoGame+18FAj
//@ 		cmp	CurTime, 4	; uint16_t
//@ 		jnb	short loc_DB72	; Jump if Not Below (CF=0)
//@ 		jmp	short loc_DB69	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_DB72:				; CODE XREF: DoGame+18F8j
//@ 		mov	t1, 4		; uint16_t
//@ ; #line	"PS10.PAS" 4181
//@ 		push	t1		; uint16_t
//@ 		push	27Fh
//@ 		push	4
//@ 		call	ShowValue	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4182
//@ 		cmp	NewSecond, 0	; bool
//@ 		jz	short loc_DB90	; Jump if Zero (ZF=1)
//@ 		call	ShowVESATime	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4185
//@ 
//@ loc_DB90:				; CODE XREF: DoGame:loc_DB67j
//@ 					; DoGame+1913j
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_DB9C	; Jump if Zero (ZF=1)
//@ 		call	Demo_RecordNext	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4187
//@ 
//@ loc_DB9C:				; CODE XREF: DoGame+191Fj
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_DBA8	; Jump if Zero (ZF=1)
//@ 		call	ShowVesaConsole	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4188
//@ 
//@ loc_DBA8:				; CODE XREF: DoGame+192Bj
//@ 		inc	takt		; uint16_t
//@ ; #line	"PS10.PAS" 4189
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_DBCA	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_DBCA	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4191
//@ 		cmp	Chojin,	0	; bool
//@ 		jz	short loc_DBC7	; Jump if Zero (ZF=1)
//@ 		mov	Players.Life, 0C8h ; 'È' ; struct TPlayerInfo[8]
//@ ; #line	"PS10.PAS" 4192
//@ 
//@ loc_DBC7:				; CODE XREF: DoGame+1949j
//@ 		call	CheckTelePorts	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4195
//@ 
//@ loc_DBCA:				; CODE XREF: DoGame+193Bj DoGame+1942j
//@ 		mov	al, byte ptr ehy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr ehx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, AmbMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	SetAmbient	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4199
//@ 		mov	ax, CurTime	; uint16_t
//@ 		add	_Times10Sum, ax	; uint16_t
//@ ; #line	"PS10.PAS" 4200
//@ 		inc	Frames10Count	; uint16_t
//@ ; #line	"PS10.PAS" 4201
//@ 		cmp	Frames10Count, 0Ah ; uint16_t
//@ 		jb	short loc_DC0E	; Jump if Below	(CF=1)
//@ ; #line	"PS10.PAS" 4202
//@ 		mov	ax, _Times10Sum	; uint16_t
//@ 		mov	Times10Sum, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	_Times10Sum, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Frames10Count, ax ; uint16_t
//@ ; #line	"PS10.PAS" 4203
//@ 
//@ loc_DC0E:				; CODE XREF: DoGame+1986j
//@ 		cmp	EndDelay, 0	; int16_t
//@ 		jle	short loc_DC29	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"PS10.PAS" 4204
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	EndDelay, ax	; int16_t
//@ 		cmp	EndDelay, 0	; int16_t
//@ 		jg	short loc_DC29	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	MenuCode, 2	; uint16_t
//@ ; #line	"PS10.PAS" 4205
//@ 
//@ loc_DC29:				; CODE XREF: DoGame+199Dj DoGame+19ABj
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		ja	short loc_DC33	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_C4F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4208
//@ 
//@ loc_DC33:				; CODE XREF: DoGame+196j DoGame+1ABj ...
//@ 		call	RefreshMachineMode ; function near PASCAL returns void
//@ ; #line	"PS10.PAS" 4209
//@ 		call	CloseIPXChannel	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4210
//@ 		call	DeInit_DemoSystem ; function far PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4211
//@ 		call	DeinitMonitor	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4212
//@ 		call	StopSound	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4213
//@ 		call	ReleaseLevel	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4214
//@ 		mov	EndOfTheGame, 0	; bool
//@ ; #line	"PS10.PAS" 4215
//@ 
//@ locret_DC4E:				; CODE XREF: DoGame+17Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DoGame		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aChasm_cfg_0	db 9,'CHASM.CFG'        ; DATA XREF: CheckQuit+Bo
//@ 					; CheckQuit+15o
//@ aNquit		db 5,'NQUIT'            ; DATA XREF: CheckQuit+23Fo
//@ ; #line	"PS10.PAS" 4224
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: noreturn bp-based	frame
//@ 
//@ CheckQuit	proc near		; CODE XREF: PROGRAM+E77p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"PS10.PAS" 4225
//@ 		call	DO_CD_Stop	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4226
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aChasm_cfg_0	; "CHASM.CFG"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ 		mov	di, offset aChasm_cfg_0	; "CHASM.CFG"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4227
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4229
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset _FrontOn ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	13h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4230
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset RespawnTime ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4231
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset FXVolume ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4232
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset CDVolume ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4233
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset MSsens ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4235
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Bright ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4236
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Contrast ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4237
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Color ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4238
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset FloorW ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4240
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset b0	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4241
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset InfoPage ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4242
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	9
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4243
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset SelfColor ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4244
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ShadowCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4245
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset EpisodeReset	; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4246
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Cocpit ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4247
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ReverseMouse	; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4248
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset MLookOn ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4249
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset AlwaysRun ; bool
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4251
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset NGCard ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4252
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset NGPort ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4253
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset NGBaud ; uint8_t
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4255
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset CurVideoMode	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4256
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset VPSize ; int32_t
//@ 		push	ds
//@ 		push	di
//@ 		push	4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"PS10.PAS" 4258
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4260
//@ 		mov	di, offset aNquit ; "NQUIT"
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ CheckQuit	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4261
//@ 		db 0C9h	; É
//@ 		db 0C3h	; Ã
//@ ; #line	"PS10.PAS" 4266
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowIntro1	proc near		; CODE XREF: PROGRAM+D09p
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 4300
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ShowIntro1	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@		db 5,'[!@#]'            ; DATA XREF: PROGRAM+48o
//@ aRunChasm_exeTo	db 28,'Run CHASM.EXE to play CHASM.' ; DATA XREF: PROGRAM+54o
//@ asc_DED4	db 4,'####'             ; DATA XREF: PROGRAM+85o PROGRAM+842o
//@ aNoEnoughtMemor	db 35,'No enought memory to start CHASM.',0Dh,0Ah ; DATA XREF: PROGRAM+75o
//@ aKMoreMemoryNee	db 21,'K more memory needed.' ; DATA XREF: PROGRAM+B9o
//@ aUnknown	db 7,'UNKNOWN'          ; DATA XREF: PROGRAM+F1o
//@ aChasmTheRift_V	db 23,'CHASM - The Rift. v1.04' ; DATA XREF: PROGRAM+18Do
//@ aCMegamediaCorp	db 19,'(c) Megamedia Corp,' ; DATA XREF: PROGRAM+197o
//@ aActionFormsLtd	db 21,'    Action Forms Ltd.' ; DATA XREF: PROGRAM+1A1o
//@ asc_DF5D	db 0			; DATA XREF: PROGRAM+1ABo
//@ aSafe		db 5,'-safe'            ; DATA XREF: PROGRAM+2B0o
//@ aNomonsters	db 11,'-nomonsters'     ; DATA XREF: PROGRAM+2C6o
//@ aChojin		db 7,'-chojin'          ; DATA XREF: PROGRAM+2DCo
//@ aNodemo		db 7,'-nodemo'          ; DATA XREF: PROGRAM+2F2o
//@ aMonitor	db 8,'-monitor'         ; DATA XREF: PROGRAM+308o
//@ aAddon		db 7,'-addon:'          ; DATA XREF: PROGRAM+334o
//@ asc_DF91	db 1,'\'                ; DATA XREF: PROGRAM+390o
//@ aVmode		db 6,'-vmode'           ; DATA XREF: PROGRAM+3BFo
//@ aKalirate	db 9,'-kalirate'        ; DATA XREF: PROGRAM+43Do
//@ aSetMinNetworkP	db 27,'Set Min Network period to: ' ; DATA XREF: PROGRAM+4AEo
//@ aSec_		db 5,' sec.'            ; DATA XREF: PROGRAM+4DFo
//@ aWarp		db 5,'-warp'            ; DATA XREF: PROGRAM+504o
//@ aSkill		db 6,'-skill'           ; DATA XREF: PROGRAM+57Do
//@ aColor		db 6,'-color'           ; DATA XREF: PROGRAM+5EBo
//@ aNojoy		db 6,'-nojoy'           ; DATA XREF: PROGRAM+6B3o
//@ aNosound	db 8,'-nosound'         ; DATA XREF: PROGRAM+6C9o
//@ aNomouse	db 8,'-nomouse'         ; DATA XREF: PROGRAM+6DFo
//@ aAddLevelsFrom	db 17,'Add levels from: ' ; DATA XREF: PROGRAM+70Ao
//@ aSpecifiedSound	db 35,'Specified sound hardware not found.' ; DATA XREF: PROGRAM+743o
//@ asc_E029	db 44,'--------------------------------------------'
//@ 					; DATA XREF: PROGRAM+752o PROGRAM+BF5o
//@ aMemory		db 11,'Memory   : '     ; DATA XREF: PROGRAM+768o
//@ aK_		db 2,'K.'               ; DATA XREF: PROGRAM+78Co
//@ aKeyboard	db 9,'Keyboard '        ; DATA XREF: PROGRAM+79Do
//@ aJoystick	db 11,'& JoyStick '     ; DATA XREF: PROGRAM+7C6o
//@ aMouse		db 7,'& Mouse'          ; DATA XREF: PROGRAM+7F4o
//@ aControls	db 11,'Controls : '     ; DATA XREF: PROGRAM+816o
//@ aK		db 2,'K,'               ; DATA XREF: PROGRAM+85Eo
//@ aVesa		db 6,' VESA '           ; DATA XREF: PROGRAM+88Co
//@ asc_E099	db 1,'#'                ; DATA XREF: PROGRAM+89Co PROGRAM+8CAo ...
//@ a_		db 1,'.'                ; DATA XREF: PROGRAM+8BAo PROGRAM+B85o
//@ aLinearFrameBuf	db 26,', LINEAR FRAME BUFFER AT: ' ; DATA XREF: PROGRAM+90Co
//@ aVideo		db 11,'Video    : '     ; DATA XREF: PROGRAM+946o
//@ aNo		db 2,'No'               ; DATA XREF: PROGRAM+96Do
//@ aSb1_02_0	db 11,'SB 1.0/2.0 '     ; DATA XREF: PROGRAM+985o
//@ aSbPro2		db 8,'SB Pro2 '         ; DATA XREF: PROGRAM+99Do
//@ aSb16		db 5,'SB16 '            ; DATA XREF: PROGRAM+9B5o
//@ aGravisUltrasou	db 18,'Gravis UltraSound ' ; DATA XREF: PROGRAM+9CDo
//@ asc_E0F5	db 1,'h'                ; DATA XREF: PROGRAM+A26o
//@ aIrq		db 4,',IRQ'             ; DATA XREF: PROGRAM+A30o
//@ a@_0		db 2,'@#'               ; DATA XREF: PROGRAM+A40o PROGRAM+B95o ...
//@ aDma		db 4,',DMA'             ; DATA XREF: PROGRAM+A5Eo
//@ aDspv		db 5,',DSPv'            ; DATA XREF: PROGRAM+AA5o
//@ a__0		db 4,'#.##'             ; DATA XREF: PROGRAM+AB5o
//@ aSound		db 11,'Sound    : '     ; DATA XREF: PROGRAM+AF6o
//@ aNotPresent_	db 12,'Not present.'    ; DATA XREF: PROGRAM+B16o
//@ aVersion	db 8,'Version '         ; DATA XREF: PROGRAM+B52o
//@ aMscdex		db 11,'MSCDEX   : '     ; DATA XREF: PROGRAM+BD0o
//@ aSetInterruptVe	db 24,'Set interrupt vectors...' ; DATA XREF: PROGRAM+C52o
//@ aOk_		db 3,'Ok.'              ; DATA XREF: PROGRAM+CA6o PROGRAM+CE1o
//@ aInitSoundSyste	db 20,'Init Sound System...' ; DATA XREF: PROGRAM+CC6o
//@ aLevel		db 5,'LEVEL'            ; DATA XREF: PROGRAM+D80o
//@ aScript_	db 8,'\script.'         ; DATA XREF: PROGRAM+D94o
//@ aLevel01Script_	db 17,'LEVEL01\script.01' ; DATA XREF: PROGRAM+DE8o
//@ aIntro		db 5,'Intro'            ; DATA XREF: PROGRAM+E3Ao
//@ aGameLoaded_	db 12,'Game Loaded.'    ; DATA XREF: PROGRAM+E66o
//! 		assume ss:dseg12
//! ; #line	"PS10.PAS" 4306
//!
//! ; =============== S U B	R O U T	I N E =======================================
//!
//! ; Attributes: bp-based frame
//!
//! 		public PROGRAM
//! PROGRAM		proc near
//!
int main(int argc, char** argv)
{
//@ var_500		= byte ptr -500h
//@ var_400		= byte ptr -400h
//@ var_304		= byte ptr -304h
//@ var_302		= byte ptr -302h
//@ var_300		= byte ptr -300h
//@ var_204		= byte ptr -204h
//@ var_202		= byte ptr -202h
//@ var_200		= byte ptr -200h
//@ var_104		= byte ptr -104h
//@ var_102		= byte ptr -102h
//@ var_100		= byte ptr -100h
//@ var_4		= dword	ptr -4
//@ 
//! 		call	KERNEL_91	; Call Procedure
//! 		call	@__SystemInit$qv ; Initialize run-time library
//! 		call	@__CrtInit$qv	; __CrtInit(void)
//@ 		call	$SoundIPInit	; Call Procedure
//! 		call	$CspBioInit	; Call Procedure
	CspBioInit();
//! 		call	$CspRndrInit	; Call Procedure
    CspRndrInit();
//@ 		call	$CsMenuInit	; Call Procedure
//@ 		call	$CspUtlInit	; Call Procedure
//@ 		call	$CsActInit	; Call Procedure
//@ 		call	$Cs3dm2Init	; Call Procedure
//@ 		call	$CsDemoInit	; Call Procedure
//@ 		enter	500h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"PS10.PAS" 4307
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	@ParamStr$qm6String4Word ; ParamStr(index): String
//@ 		mov	di, offset a@	; "[!@#]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_E201	; Jump if Zero (ZF=1)
//@ 		mov	di, offset aRunChasm_exeTo ; "Run CHASM.EXE to play CHASM."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4308
//@ 
//@ loc_E201:				; CODE XREF: PROGRAM+52j
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		cmp	dx, 4Ch	; 'L'   ; Compare Two Operands
//@ 		jl	short loc_E212	; Jump if Less (SF!=OF)
//@ 		jg	short loc_E26B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, 4B40h	; Compare Two Operands
//@ 		jnb	short loc_E26B	; Jump if Not Below (CF=0)
//@ ; #line	"PS10.PAS" 4309
//@ 
//@ loc_E212:				; CODE XREF: PROGRAM+66j
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aNoEnoughtMemor ; "No enought memory	to start CHASM.\r\n"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_DED4 ; "####"
//@ 		push	cs
//@ 		push	di
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 4B40h
//@ 		mov	dx, 4Ch	; 'L'
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aKMoreMemoryNee ; "K	more memory needed."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4311
//@ 
//@ loc_E26B:				; CODE XREF: PROGRAM+68j PROGRAM+6Dj
//@ 		mov	ax, Seg0040	; uint16_t
//@ 		push	ax
//@ 		mov	di, 17h
//@ 		pop	es
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"PS10.PAS" 4312
//@ 		call	@Randomize$qv	; Randomize
//@ ; #line	"PS10.PAS" 4313
//@ 		mov	ax, word ptr RandSeed ;	int32_t
//@ 		mov	dx, word ptr RandSeed+2	; int32_t
//@ 		mov	word ptr StartUpRandSeed, ax ; int32_t
//@ 		mov	word ptr StartUpRandSeed+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 4314
//@ 		mov	DirectVideo, 0	; bool
//@ ; #line	"PS10.PAS" 4315
//@ 		mov	byte ptr ConsoleComm+0F6h, 0 ; char[287] // Pascal string
//@ ; #line	"PS10.PAS" 4316
//@ 		mov	di, offset aUnknown ; "UNKNOWN"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4317
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr mem0, ax ; int32_t
//@ 		mov	word ptr mem0+2, ax ; int32_t
//@ ; #line	"PS10.PAS" 4318
//@ 		mov	mps, 30h ; '0'  ; int16_t
//@ ; #line	"PS10.PAS" 4319
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyNetN,	ax	; int16_t
//@ ; #line	"PS10.PAS" 4320
//@ 		mov	RespawnTime, 20D0h ; uint16_t
//@ ; #line	"PS10.PAS" 4321
//@ 		mov	BLevelDef, 140h	; uint16_t
//@ ; #line	"PS10.PAS" 4323
//@ 		mov	Cocpit,	1	; bool
//@ ; #line	"PS10.PAS" 4324
//@ 		mov	SelfColor, 1	; uint8_t
//@ ; #line	"PS10.PAS" 4325
//@ 		mov	Slow, 0		; bool
//@ ; #line	"PS10.PAS" 4326
//@ 		mov	Spline,	1	; bool
//@ ; #line	"PS10.PAS" 4327
//@ 		mov	Monsters, 1	; bool
//@ ; #line	"PS10.PAS" 4328
//@ 		mov	InfoPage, 1	; bool
//@ ; #line	"PS10.PAS" 4329
//@ 		mov	Console, 0	; bool
//@ ; #line	"PS10.PAS" 4330
//@ 		mov	Animation, 1	; bool
//@ ; #line	"PS10.PAS" 4331
//@ 		mov	ClipMode, 0	; bool
//@ ; #line	"PS10.PAS" 4332
//@ 		mov	JoyStick, 0	; bool
//@ ; #line	"PS10.PAS" 4333
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"PS10.PAS" 4334
//@ 		mov	SERVER,	0	; bool
//@ ; #line	"PS10.PAS" 4335
//@ 		mov	Chojin,	0	; bool
//@ ; #line	"PS10.PAS" 4336
//@ 		mov	LevelN,	1	; int16_t
//@ ; #line	"PS10.PAS" 4337
//@ 		mov	NGLevel, 1	; uint8_t
//@ ; #line	"PS10.PAS" 4338
//@ 		mov	NGSkill, 1	; uint8_t
//@ ; #line	"PS10.PAS" 4339
//@ 		mov	NGMode,	0	; uint8_t
//@ ; #line	"PS10.PAS" 4340
//@ 		mov	Skill, 1	; int16_t
//@ ; #line	"PS10.PAS" 4341
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsY, ax	; int16_t
//@ ; #line	"PS10.PAS" 4342
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsDY,	ax	; int16_t
//@ ; #line	"PS10.PAS" 4343
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 4345
//@ 		mov	di, offset aChasmTheRift_V ; "CHASM - The Rift.	v1.04"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4346
//@ 		mov	di, offset aCMegamediaCorp ; "(c) Megamedia Corp,"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4347
//@ 		mov	di, offset aActionFormsLtd ; "	  Action Forms Ltd."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4348
//@ 		mov	di, offset asc_DF5D ; ""
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4350
//@ 		call	CheckNP		; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4352
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_E366	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_E362:				; CODE XREF: PROGRAM+1EFj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_E366:				; CODE XREF: PROGRAM+1BDj
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"PS10.PAS" 4353
//@ 		mov	byte ptr es:[di], 0
//@ 		mov	byte ptr es:[di+24h], 0
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+44h], ax
//@ 		mov	ax, n$0		; int16_t
//@ 		mov	es:[di+46h], ax
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_E362	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4355
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_E39F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_E39B:				; CODE XREF: PROGRAM+212j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_E39F:				; CODE XREF: PROGRAM+1F6j
//@ 		imul	ax, n$0, 140h	; int16_t
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di-7016h], ax
//@ 		cmp	n$0, 0C8h ; 'È' ; int16_t
//@ 		jnz	short loc_E39B	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4357
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsMainY, ax	; int16_t
//@ ; #line	"PS10.PAS" 4358
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LoadSaveY, ax	; uint16_t
//@ ; #line	"PS10.PAS" 4359
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	OptionsY, ax	; uint16_t
//@ ; #line	"PS10.PAS" 4360
//@ 		mov	ax, 9E33h
//@ 		mov	dx, seg	cseg01
//@ 		mov	word ptr BuildSceneRout, ax ; void (*)()
//@ 		mov	word ptr BuildSceneRout+2, dx ;	void (*)()
//@ ; #line	"PS10.PAS" 4362
//@ 		push	1
//@ 		call	LoadConfig	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4364
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Players.PName ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4365
//@ 		mov	al, SelfColor	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Players.PColor,	ax ; struct TPlayerInfo[8]
//@ ; #line	"PS10.PAS" 4366
//@ 		call	InitMessageSystem ; function far PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4369
//@ 		mov	PlayDemo, 1	; bool
//@ ; #line	"PS10.PAS" 4370
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr KbdInt, ax ; void (*)()
//@ 		mov	word ptr KbdInt+2, ax ;	void (*)()
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr TimerInt, ax ;	void (*)()
//@ 		mov	word ptr TimerInt+2, ax	; void (*)()
//@ ; #line	"PS10.PAS" 4371
//@ 		call	@ParamCount$qv	; ParamCount: Word{AX}
//@ 		mov	word ptr [bp+var_4+2], ax
//@ 		mov	ax, 2
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jle	short loc_E41E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_E7F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_E41E:				; CODE XREF: PROGRAM+276j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_E427	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_E423:				; CODE XREF: PROGRAM+64Dj
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 4373
//@ 
//@ loc_E427:				; CODE XREF: PROGRAM+27Ej
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	n$0		; int16_t
//@ 		call	@ParamStr$qm6String4Word ; ParamStr(index): String
//@ 		call	StLocase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4374
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aSafe ; "-safe"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E464	; Jump if Not Zero (ZF=0)
//@ 		mov	SafeLoad, 1	; bool
//@ ; #line	"PS10.PAS" 4375
//@ 
//@ loc_E464:				; CODE XREF: PROGRAM+2BAj
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aNomonsters ; "-nomonsters"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E47A	; Jump if Not Zero (ZF=0)
//@ 		mov	Monsters, 0	; bool
//@ ; #line	"PS10.PAS" 4376
//@ 
//@ loc_E47A:				; CODE XREF: PROGRAM+2D0j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aChojin ; "-chojin"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E490	; Jump if Not Zero (ZF=0)
//@ 		mov	Chojin,	1	; bool
//@ ; #line	"PS10.PAS" 4383
//@ 
//@ loc_E490:				; CODE XREF: PROGRAM+2E6j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aNodemo ; "-nodemo"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E4A6	; Jump if Not Zero (ZF=0)
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4384
//@ 
//@ loc_E4A6:				; CODE XREF: PROGRAM+2FCj
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aMonitor ; "-monitor"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E4C3	; Jump if Not Zero (ZF=0)
//@ 		cmp	VESAPresent, 0	; bool
//@ 		jz	short loc_E4C3	; Jump if Zero (ZF=1)
//@ 		mov	NETMonitor, 1	; bool
//@ ; #line	"PS10.PAS" 4386
//@ 
//@ loc_E4C3:				; CODE XREF: PROGRAM+312j PROGRAM+319j
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	7
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset aAddon ; "-addon:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E54E	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4388
//@ 		lea	di, [bp+var_302] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		push	28h ; '('
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset AddonPath ; char[41]	// Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4389
//@ 		cmp	byte ptr AddonPath, 0 ;	char[41] // Pascal string
//@ 		jbe	short loc_E54E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 4391
//@ 		mov	al, byte ptr AddonPath ; char[41] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-199Ah], 5Ch ; '\' ; Compare Two Operands
//@ 		jz	short loc_E549	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4392
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset AddonPath ; char[41]	// Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset asc_DF91 ; "\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset AddonPath ; char[41]	// Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4393
//@ 
//@ loc_E549:				; CODE XREF: PROGRAM+37Ej
//@ 		mov	UserMaps, 1	; bool
//@ ; #line	"PS10.PAS" 4397
//@ 
//@ loc_E54E:				; CODE XREF: PROGRAM+33Ej PROGRAM+370j
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	6
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset aVmode ; "-vmode"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E5CC	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4399
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	7
//@ 		push	2
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset j	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4400
//@ 		cmp	j, 0		; uint16_t
//@ 		jnz	short loc_E5CC	; Jump if Not Zero (ZF=0)
//@ 		cmp	i, 1		; int16_t
//@ 		jl	short loc_E5CC	; Jump if Less (SF!=OF)
//@ 		mov	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, i		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_E5C6	; Jump if Less (SF!=OF)
//@ 		jg	short loc_E5CC	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		ja	short loc_E5CC	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"PS10.PAS" 4401
//@ 
//@ loc_E5C6:				; CODE XREF: PROGRAM+41Bj
//@ 		mov	ax, i		; int16_t
//@ 		mov	CurVideoMode, ax ; uint16_t
//@ ; #line	"PS10.PAS" 4404
//@ 
//@ loc_E5CC:				; CODE XREF: PROGRAM+3C9j PROGRAM+403j ...
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	9
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset aKalirate ; "-kalirate"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_E5EF	; Jump if Zero (ZF=1)
//@ 		jmp	loc_E693	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4406
//@ 
//@ loc_E5EF:				; CODE XREF: PROGRAM+447j
//@ 		mov	KALI, 1		; bool
//@ ; #line	"PS10.PAS" 4407
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0Ah
//@ 		push	2
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset j	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4408
//@ 		cmp	j, 0		; uint16_t
//@ 		jnz	short loc_E64C	; Jump if Not Zero (ZF=0)
//@ 		cmp	i, 1		; int16_t
//@ 		jl	short loc_E64C	; Jump if Less (SF!=OF)
//@ 		cmp	i, 20h ; ' '    ; int16_t
//@ 		jg	short loc_E64C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, 8Ch	; 'Œ'
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	i		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	word ptr NetPeriod, ax ; int32_t
//@ 		mov	word ptr NetPeriod+2, dx ; int32_t
//@ ; #line	"PS10.PAS" 4409
//@ 
//@ loc_E64C:				; CODE XREF: PROGRAM+489j PROGRAM+490j ...
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aSetMinNetworkP ; "Set Min Network period to: "
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		mov	ax, word ptr NetPeriod ; int32_t
//@ 		mov	dx, word ptr NetPeriod+2 ; int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 88h	; 'ˆ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 0C00h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		push	1
//@ 		push	2
//@ 		call	@Write$qm4Text4Real4Wordt3 ; Write(var f; v: Real; width, decimals: Word)
//@ 		mov	di, offset aSec_ ; " sec."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4412
//@ 
//@ loc_E693:				; CODE XREF: PROGRAM+449j
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	5
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset aWarp ; "-warp"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E70C	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4414
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	6
//@ 		push	2
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset j	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4415
//@ 		cmp	j, 0		; uint16_t
//@ 		jnz	short loc_E701	; Jump if Not Zero (ZF=0)
//@ 		cmp	i, 1		; int16_t
//@ 		jl	short loc_E701	; Jump if Less (SF!=OF)
//@ 		cmp	i, 40h ; '@'    ; int16_t
//@ 		jg	short loc_E701	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, i		; int16_t
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"PS10.PAS" 4416
//@ 
//@ loc_E701:				; CODE XREF: PROGRAM+548j PROGRAM+54Fj ...
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4417
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"PS10.PAS" 4420
//@ 
//@ loc_E70C:				; CODE XREF: PROGRAM+50Ej
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	6
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset aSkill ; "-skill"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E77A	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4422
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	7
//@ 		push	1
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset j	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4423
//@ 		cmp	j, 0		; uint16_t
//@ 		jnz	short loc_E77A	; Jump if Not Zero (ZF=0)
//@ 		cmp	i, 0		; int16_t
//@ 		jl	short loc_E77A	; Jump if Less (SF!=OF)
//@ 		cmp	i, 2		; int16_t
//@ 		jg	short loc_E77A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, i		; int16_t
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"PS10.PAS" 4427
//@ 
//@ loc_E77A:				; CODE XREF: PROGRAM+587j PROGRAM+5C1j ...
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	6
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset aColor ; "-color"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E7E8	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4429
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	7
//@ 		push	1
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset j	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	i, ax		; int16_t
//@ ; #line	"PS10.PAS" 4430
//@ 		cmp	j, 0		; uint16_t
//@ 		jnz	short loc_E7E8	; Jump if Not Zero (ZF=0)
//@ 		cmp	i, 0		; int16_t
//@ 		jle	short loc_E7E8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	i, 8		; int16_t
//@ 		jg	short loc_E7E8	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	al, byte ptr i	; int16_t
//@ 		mov	SelfColor, al	; uint8_t
//@ ; #line	"PS10.PAS" 4432
//@ 
//@ loc_E7E8:				; CODE XREF: PROGRAM+5F5j PROGRAM+62Fj ...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jz	short loc_E7F3	; Jump if Zero (ZF=1)
//@ 		jmp	loc_E423	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4434
//@ 
//@ loc_E7F3:				; CODE XREF: PROGRAM+278j PROGRAM+64Bj
//@ 		cmp	SafeLoad, 0	; bool
//@ 		jz	short loc_E802	; Jump if Zero (ZF=1)
//@ 		mov	CurVideoMode, 1	; uint16_t
//@ 		jmp	short loc_E811	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4437
//@ 
//@ loc_E802:				; CODE XREF: PROGRAM+655j
//@ 		call	DetectSound	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4438
//@ 		call	CheckMouse	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4439
//@ 		call	CheckJoyStick	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4443
//@ 
//@ loc_E811:				; CODE XREF: PROGRAM+65Dj
//@ 		call	@ParamCount$qv	; ParamCount: Word{AX}
//@ 		mov	word ptr [bp+var_4+2], ax
//@ 		mov	ax, 2
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jg	short loc_E89B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_E82A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_E826:				; CODE XREF: PROGRAM+6F6j
//@ 		inc	n$0		; int16_t
//@ ; #line	"PS10.PAS" 4445
//@ 
//@ loc_E82A:				; CODE XREF: PROGRAM+681j
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	n$0		; int16_t
//@ 		call	@ParamStr$qm6String4Word ; ParamStr(index): String
//@ 		call	StLocase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4446
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aNojoy ; "-nojoy"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E867	; Jump if Not Zero (ZF=0)
//@ 		mov	JoyStick, 0	; bool
//@ ; #line	"PS10.PAS" 4447
//@ 
//@ loc_E867:				; CODE XREF: PROGRAM+6BDj
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aNosound ; "-nosound"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E87D	; Jump if Not Zero (ZF=0)
//@ 		mov	sCard, 0	; uint8_t
//@ ; #line	"PS10.PAS" 4448
//@ 
//@ loc_E87D:				; CODE XREF: PROGRAM+6D3j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aNomouse ; "-nomouse"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_E893	; Jump if Not Zero (ZF=0)
//@ 		mov	MouseD,	0	; bool
//@ ; #line	"PS10.PAS" 4449
//@ 
//@ loc_E893:				; CODE XREF: PROGRAM+6E9j
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, word ptr [bp+var_4+2] ; Compare Two	Operands
//@ 		jnz	short loc_E826	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4451
//@ 
//@ loc_E89B:				; CODE XREF: PROGRAM+67Cj
//@ 		cmp	UserMaps, 0	; bool
//@ 		jz	short loc_E8CD	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4452
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aAddLevelsFrom ; "Add levels	from: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset AddonPath ; char[41]	// Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4454
//@ 
//@ loc_E8CD:				; CODE XREF: PROGRAM+6FDj
//@ 		mov	al, sCard	; uint8_t
//@ 		push	ax
//@ 		push	sBase		; uint16_t
//@ 		mov	al, sIRQ	; uint8_t
//@ 		push	ax
//@ 		mov	al, sDMA	; uint8_t
//@ 		push	ax
//@ 		call	RegisterCard	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_E8F0	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4455
//@ 		mov	di, offset aSpecifiedSound ; "Specified	sound hardware not found."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4457
//@ 
//@ loc_E8F0:				; CODE XREF: PROGRAM+741j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset asc_E029 ; "---------------------------------------"...
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4460
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aMemory ; "Memory   : "
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		push	dx
//@ 		push	ax
//@ 		push	0
//@ 		call	@Write$qm4Text7Longint4Word ; Write(var	f; v: Longint; width: Word)
//@ 		mov	di, offset aK_	; "K."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4461
//@ 		mov	di, offset aKeyboard ; "Keyboard "
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4462
//@ 		cmp	JoyStick, 0	; bool
//@ 		jz	short loc_E980	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aJoystick ; "& JoyStick "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4463
//@ 
//@ loc_E980:				; CODE XREF: PROGRAM+7B4j
//@ 		cmp	MouseD,	0	; bool
//@ 		jz	short loc_E9AE	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aMouse ; "& Mouse"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4464
//@ 
//@ loc_E9AE:				; CODE XREF: PROGRAM+7E2j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aControls ; "Controls : "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4467
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_DED4 ; "####"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, TotalMemory	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset aK	; "K,"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4468
//@ 		cmp	VESAVersion, 0	; uint16_t
//@ 		jbe	short loc_EA98	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"PS10.PAS" 4469
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aVesa ; " VESA "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_E099 ; "#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	al, byte ptr VESAVersion+1 ; uint16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_	; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_E099 ; "#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	al, byte ptr VESAVersion ; uint16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4470
//@ 
//@ loc_EA98:				; CODE XREF: PROGRAM+87Aj
//@ 		cmp	FLATSelector, 0	; uint16_t
//@ 		jbe	short loc_EADE	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aLinearFrameBuf ; ",	LINEAR FRAME BUFFER AT:	"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	word ptr VESA20Addr+2 ;	int32_t
//@ 		push	word ptr VESA20Addr ; int32_t
//@ 		call	HexL		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4471
//@ 
//@ loc_EADE:				; CODE XREF: PROGRAM+8FAj
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aVideo ; "Video    :	"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4473
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"PS10.PAS" 4474
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jnz	short loc_EB24	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aNo	; "No"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_EB82	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4475
//@ 
//@ loc_EB24:				; CODE XREF: PROGRAM+96Bj
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_EB3C	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aSb1_02_0 ; "SB 1.0/2.0 "
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_EB82	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4476
//@ 
//@ loc_EB3C:				; CODE XREF: PROGRAM+983j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_EB54	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aSbPro2 ; "SB Pro2 "
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_EB82	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4477
//@ 
//@ loc_EB54:				; CODE XREF: PROGRAM+99Bj
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_EB6C	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aSb16 ; "SB16 "
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_EB82	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4478
//@ 
//@ loc_EB6C:				; CODE XREF: PROGRAM+9B3j
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short loc_EB82	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aGravisUltrasou ; "Gravis UltraSound	"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4480
//@ 
//@ loc_EB82:				; CODE XREF: PROGRAM+97Fj PROGRAM+997j ...
//@ 		cmp	sCard, 1	; uint8_t
//@ 		ja	short loc_EB8C	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_EC8E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4482
//@ 
//@ loc_EB8C:				; CODE XREF: PROGRAM+9E4j
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset asc_E099 ; "#"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	sBase		; uint16_t
//@ 		call	HexW		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		push	2
//@ 		push	3
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_E0F5 ; "h"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aIrq	; ",IRQ"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_400] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_0	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aDma	; ",DMA"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_500] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 30h	; '0'   ; Add
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4485
//@ 		cmp	sCard, 5	; uint8_t
//@ 		jnb	short loc_EC8E	; Jump if Not Below (CF=0)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aDspv ; ",DSPv"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a__0	; "#.##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, sbDSPver	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 87h	; '‡'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4800h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4488
//@ 
//@ loc_EC8E:				; CODE XREF: PROGRAM+9E6j PROGRAM+A93j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSound ; "Sound    :	"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4492
//@ 		mov	di, offset aNotPresent_	; "Not present."
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4493
//@ 		cmp	NPinst,	0	; bool
//@ 		jnz	short loc_ECD5	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_ED68	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4494
//@ 
//@ loc_ECD5:				; CODE XREF: PROGRAM+B2Dj
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		assume es:nothing
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	word ptr es:[di+181h], 0 ; Compare Two Operands
//@ 		ja	short loc_ECEA	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_ED68	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4496
//@ 
//@ loc_ECEA:				; CODE XREF: PROGRAM+B42j
//@ 		mov	MSCDEX,	1	; bool
//@ ; #line	"PS10.PAS" 4497
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aVersion ; "Version "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_104] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_E099 ; "#"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+182h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_	; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_0	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+181h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4501
//@ 
//@ loc_ED68:				; CODE XREF: PROGRAM+B2Fj PROGRAM+B44j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMscdex ; "MSCDEX   : "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4503
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset asc_E029 ; "---------------------------------------"...
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4507
//@ 		mov	HeapLimit, 200h	; uint16_t
//@ ; #line	"PS10.PAS" 4508
//@ 		mov	HeapBlock, 1000h ; uint16_t
//@ ; #line	"PS10.PAS" 4510
//@ 		call	AllocMemory	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4512
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		call	AllocSelector	; Call Procedure
//@ 		mov	CurPicSeg, ax	; uint16_t
//@ 		push	CurPicSeg	; uint16_t
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"PS10.PAS" 4513
//@ 		mov	ax, cs
//@ 		push	ax
//@ 		call	AllocSelector	; Call Procedure
//@ 		mov	CSCopy$0, ax	; uint16_t
//@ 		push	CSCopy$0	; uint16_t
//@ 		push	0
//@ 		push	0FA00h
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"PS10.PAS" 4514
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	gs, ax
//@ ; #line	"PS10.PAS" 4516
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aSetInterruptVe ; "Set interrupt vectors..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"PS10.PAS" 4517
//@ 		push	9
//@ 		mov	di, offset KbdInt ; void (*)()
//@ 		push	ds
//@ 		push	di
//@ 		call	@GetIntVec$q4Bytem7Pointer ; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4518
//@ 		push	9
//@ 		mov	di, 38C9h
//@ 		mov	ax, seg	cseg01
//@ 		push	ax
//@ 		push	di
//@ 		call	@SetIntVec$q4Byte7Pointer ; function far PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4519
//@ 		push	8
//@ 		mov	di, offset TimerInt ; void (*)()
//@ 		push	ds
//@ 		push	di
//@ 		call	@GetIntVec$q4Bytem7Pointer ; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4520
//@ 		push	8
//@ 		mov	di, 3934h
//@ 		mov	ax, seg	cseg01
//@ 		push	ax
//@ 		push	di
//@ 		call	@SetIntVec$q4Byte7Pointer ; function far PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4521
//@ 		push	214Ah
//@ 		call	settimer	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4522
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk_	; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4525
//@ 		call	LoadCommonParts	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4526
//@ 		call	ScanLevels	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4528
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aInitSoundSyste ; "Init Sound System..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"PS10.PAS" 4529
//@ 		call	InitSoundSystem	; function far PASCAL returns void
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk_	; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"PS10.PAS" 4531
//@ 		call	LoadGraphics	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4533
//@ 		call	ReleaseLevel	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4535
//@ 		call	SetVideoMode	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4536
//@ 		call	ReDrawGround	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4537
//@ 		call	ReInitOwners	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4538
//@ 		call	ShowIntro1	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4540
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_EEC0	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4541
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LevelN,	ax	; int16_t
//@ 		call	GetNextDemoNumber ; function far PASCAL	returns	void
//@ ; #line	"PS10.PAS" 4543
//@ 
//@ loc_EEC0:				; CODE XREF: PROGRAM+D11j
//@ 		cmp	JoyStick, 0	; bool
//@ 		jz	short loc_EECC	; Jump if Zero (ZF=1)
//@ 		call	InitJoyStick	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4546
//@ 
//@ loc_EECC:				; CODE XREF: PROGRAM+D22j
//@ 					; PROGRAM:loc_F01Dj
//@ 		mov	ax, MenuCode	; uint16_t
//@ ; #line	"PS10.PAS" 4547
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jz	short loc_EEDE	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jz	short loc_EEDE	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 16h		; Compare Two Operands
//@ 		jnz	short loc_EEE4	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_EEDE:				; CODE XREF: PROGRAM+D2Fj PROGRAM+D34j
//@ 		call	DoGame		; function near	PASCAL returns void
//@ 		jmp	loc_F01D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4548
//@ 
//@ loc_EEE4:				; CODE XREF: PROGRAM+D39j
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jz	short loc_EEEC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_EF83	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4549
//@ 
//@ loc_EEEC:				; CODE XREF: PROGRAM+D44j
//@ 		call	FindNextLevel	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4550
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_0	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"PS10.PAS" 4551
//@ 		call	DO_CD_Stop	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4552
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aScript_ ; "\\script."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PlayBrifing	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4553
//@ 		call	LoadLevel	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4554
//@ 		cmp	EpisodeReset, 0	; bool
//@ 		jz	short loc_EF70	; Jump if Zero (ZF=1)
//@ ; #line	"PS10.PAS" 4555
//@ 		mov	al, byte ptr LevelN ; int16_t
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jz	short loc_EF6B	; Jump if Zero (ZF=1)
//@ 		cmp	al, 9		; Compare Two Operands
//@ 		jz	short loc_EF6B	; Jump if Zero (ZF=1)
//@ 		cmp	al, 0Dh		; Compare Two Operands
//@ 		jnz	short loc_EF70	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_EF6B:				; CODE XREF: PROGRAM+DBEj PROGRAM+DC2j
//@ 		call	FillStartInfo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4556
//@ 
//@ loc_EF70:				; CODE XREF: PROGRAM+DB7j PROGRAM+DC6j
//@ 		mov	MenuCode, 1	; uint16_t
//@ ; #line	"PS10.PAS" 4557
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4558
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4559
//@ 		jmp	loc_F01D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4560
//@ 
//@ loc_EF83:				; CODE XREF: PROGRAM+D46j
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_EFC1	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4561
//@ 		call	DO_CD_Stop	; function near	PASCAL returns void
//@ ; #line	"PS10.PAS" 4562
//@ 		mov	di, offset aLevel01Script_ ; "LEVEL01\\script.01"
//@ 		push	cs
//@ 		push	di
//@ 		call	PlayBrifing	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4563
//@ 		call	FillStartInfo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4564
//@ 		mov	LevelN,	1	; int16_t
//@ ; #line	"PS10.PAS" 4565
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"PS10.PAS" 4566
//@ 		mov	SERVER,	0	; bool
//@ ; #line	"PS10.PAS" 4567
//@ 		call	LoadLevel	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4568
//@ 		mov	MenuCode, 1	; uint16_t
//@ ; #line	"PS10.PAS" 4569
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4570
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4571
//@ 		jmp	short loc_F01D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4572
//@ 
//@ loc_EFC1:				; CODE XREF: PROGRAM+DE3j
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jnz	short loc_EFD8	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4573
//@ 		call	LoadLevel	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4574
//@ 		call	FillStartInfo	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4575
//@ 		mov	MenuCode, 1	; uint16_t
//@ ; #line	"PS10.PAS" 4576
//@ 		jmp	short loc_F01D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4577
//@ 
//@ loc_EFD8:				; CODE XREF: PROGRAM+E21j
//@ 		cmp	ax, 5		; Compare Two Operands
//@ 		jnz	short loc_EFE9	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aIntro ; "Intro"
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ 		db 0EBh	; ë
//@ 		db  34h	; 4
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4578
//@ 
//@ loc_EFE9:				; CODE XREF: PROGRAM+E38j
//@ 		cmp	ax, 100h	; Compare Two Operands
//@ 		jnz	short loc_F015	; Jump if Not Zero (ZF=0)
//@ ; #line	"PS10.PAS" 4579
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4580
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"PS10.PAS" 4581
//@ 		mov	al, LSMenuY	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	LoadGame	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4582
//@ 		mov	MenuCode, 1	; uint16_t
//@ ; #line	"PS10.PAS" 4583
//@ 		mov	di, offset aGameLoaded_	; "Game	Loaded."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"PS10.PAS" 4584
//@ 		jmp	short loc_F01D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4585
//@ 
//@ loc_F015:				; CODE XREF: PROGRAM+E49j
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jnz	short loc_F01D	; Jump if Not Zero (ZF=0)
//@ 		call	CheckQuit	; function near	PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4587
//@ 
//@ loc_F01D:				; CODE XREF: PROGRAM+D3Ej PROGRAM+DDDj ...
//@ 		jmp	loc_EECC	; Jump
	return 0;
}
//@ PROGRAM		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"PS10.PAS" 4588
//@ 		leave			; High Level Procedure Exit
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		call	far ptr	@Halt$q4Word ; Halt(exitcode: Word{AX})
//@ ; ---------------------------------------------------------------------------
//@ 		align 10h
