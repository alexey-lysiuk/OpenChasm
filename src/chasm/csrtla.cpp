
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

#include "csrtla.h"

//@ ; #line	"CSRTLA.PAS" 2
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ MulVectors	proc near		; CODE XREF: Test2Vectors+4Ep
//@ 					; Test2Vectors+64p ...
//@ 
//@ MulVectors	= word ptr -2		; int16_t
//@ vy		= word ptr  4		; int16_t
//@ vx		= word ptr  6		; int16_t
//@ uy		= word ptr  8		; int16_t
//@ ux		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 4
//@ 		mov	cx, 0FFFFh
//@ ; #line	"CSRTLA.PAS" 5
//@ 		mov	ax, [bp+ux]	; int16_t
//@ ; #line	"CSRTLA.PAS" 6
//@ 		imul	[bp+vy]		; int16_t
//@ ; #line	"CSRTLA.PAS" 7
//@ 		mov	bx, dx
//@ ; #line	"CSRTLA.PAS" 8
//@ 		shl	ebx, 10h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 9
//@ 		mov	bx, ax
//@ ; #line	"CSRTLA.PAS" 11
//@ 		mov	ax, [bp+uy]	; int16_t
//@ ; #line	"CSRTLA.PAS" 12
//@ 		imul	[bp+vx]		; int16_t
//@ ; #line	"CSRTLA.PAS" 13
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 14
//@ 		mov	dx, ax
//@ ; #line	"CSRTLA.PAS" 15
//@ 		sub	ebx, edx	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 16
//@ 		js	short loc_2053	; Jump if Sign (SF=1)
//@ ; #line	"CSRTLA.PAS" 17
//@ 		mov	cx, 1
//@ ; #line	"CSRTLA.PAS" 18
//@ 
//@ loc_2053:				; CODE XREF: MulVectors+24j
//@ 		mov	[bp+MulVectors], cx ; int16_t
//@ ; #line	"CSRTLA.PAS" 20
//@ 		mov	ax, [bp+MulVectors] ; int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ MulVectors	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 27
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ Test2Vectors	proc near		; CODE XREF: GetNearestWall+101p
//@ 
//@ Test2Vectors	= byte ptr -1		; bool
//@ y4		= word ptr  4		; int16_t
//@ x4		= word ptr  6		; int16_t
//@ y3		= word ptr  8		; int16_t
//@ x3		= word ptr  0Ah		; int16_t
//@ y2		= word ptr  0Ch		; int16_t
//@ x2		= word ptr  0Eh		; int16_t
//@ y1		= word ptr  10h		; int16_t
//@ x1		= word ptr  12h		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 28
//@ 		mov	[bp+Test2Vectors], 0 ; bool
//@ ; #line	"CSRTLA.PAS" 29
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	nx, ax		; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	ny, ax		; int16_t
//@ ; #line	"CSRTLA.PAS" 30
//@ 		mov	ax, [bp+x3]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	v1x, ax		; int16_t
//@ 		mov	ax, [bp+y3]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	v1y, ax		; int16_t
//@ ; #line	"CSRTLA.PAS" 31
//@ 		mov	ax, [bp+x4]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	v2x, ax		; int16_t
//@ 		mov	ax, [bp+y4]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	v2y, ax		; int16_t
//@ ; #line	"CSRTLA.PAS" 32
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v1x		; int16_t
//@ 		push	v1y		; int16_t
//@ 		call	MulVectors	; function near	PASCAL returns signed int 'Integer'
//@ 		mov	i, ax		; int16_t
//@ ; #line	"CSRTLA.PAS" 34
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v2x		; int16_t
//@ 		push	v2y		; int16_t
//@ 		call	MulVectors	; function near	PASCAL returns signed int 'Integer'
//@ 		cmp	ax, i		; int16_t
//@ 		jnz	short loc_20CC	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_2134	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 36
//@ 
//@ loc_20CC:				; CODE XREF: Test2Vectors+6Bj
//@ 		mov	ax, [bp+x4]	; int16_t
//@ 		sub	ax, [bp+x3]	; int16_t
//@ 		mov	nx, ax		; int16_t
//@ 		mov	ax, [bp+y4]	; int16_t
//@ 		sub	ax, [bp+y3]	; int16_t
//@ 		mov	ny, ax		; int16_t
//@ ; #line	"CSRTLA.PAS" 37
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		sub	ax, [bp+x3]	; int16_t
//@ 		mov	v1x, ax		; int16_t
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+y3]	; int16_t
//@ 		mov	v1y, ax		; int16_t
//@ ; #line	"CSRTLA.PAS" 38
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x3]	; int16_t
//@ 		mov	v2x, ax		; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y3]	; int16_t
//@ 		mov	v2y, ax		; int16_t
//@ ; #line	"CSRTLA.PAS" 39
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v2x		; int16_t
//@ 		push	v2y		; int16_t
//@ 		call	MulVectors	; function near	PASCAL returns signed int 'Integer'
//@ 		push	ax
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v1x		; int16_t
//@ 		push	v1y		; int16_t
//@ 		call	MulVectors	; function near	PASCAL returns signed int 'Integer'
//@ 		pop	dx
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jnz	short loc_2130	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 40
//@ 		jmp	short loc_2134	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 41
//@ 
//@ loc_2130:				; CODE XREF: Test2Vectors+CFj
//@ 		mov	[bp+Test2Vectors], 1 ; bool
//@ ; #line	"CSRTLA.PAS" 42
//@ 
//@ loc_2134:				; CODE XREF: Test2Vectors+6Dj
//@ 					; Test2Vectors+D1j
//@ 		mov	al, [bp+Test2Vectors] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ Test2Vectors	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 53
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ VILineL		proc near
//@ 		mov	ax, HlBr	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, cm_ofs	; uint16_t
//@ 		mov	CMPOfs,	ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 56
//@ 		mov	bx, WinH2u	; uint16_t
//@ ; #line	"CSRTLA.PAS" 57
//@ 		mov	ax, HLh1	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 58
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jb	short loc_2158	; Jump if Below	(CF=1)
//@ 		mov	ax, bx
//@ ; #line	"CSRTLA.PAS" 59
//@ 
//@ loc_2158:				; CODE XREF: VILineL+19j
//@ 		mov	Hlhr1, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 61
//@ 		mov	bx, WinH2d	; uint16_t
//@ ; #line	"CSRTLA.PAS" 62
//@ 		mov	ax, Hlh2	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 63
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jb	short loc_216B	; Jump if Below	(CF=1)
//@ 		mov	ax, bx
//@ ; #line	"CSRTLA.PAS" 64
//@ 
//@ loc_216B:				; CODE XREF: VILineL+2Cj
//@ 		mov	Hlhr2, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 67
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 68
//@ 		mov	bx, WinCY	; uint16_t
//@ 		sub	bx, Hlhr1	; uint16_t
//@ ; #line	"CSRTLA.PAS" 72
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 73
//@ 		mov	si, [bx-7016h]
//@ ; #line	"CSRTLA.PAS" 74
//@ 		add	si, HLxx	; uint16_t
//@ ; #line	"CSRTLA.PAS" 78
//@ 		xor	edx, edx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 79
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 80
//@ 		mov	eax, 1000000h
//@ ; #line	"CSRTLA.PAS" 81
//@ 		mov	bx, HLh1	; uint16_t
//@ ; #line	"CSRTLA.PAS" 82
//@ 		add	bx, Hlh2	; uint16_t
//@ ; #line	"CSRTLA.PAS" 83
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 84
//@ 		mov	ebx, eax
//@ ; #line	"CSRTLA.PAS" 87
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 89
//@ 		mov	ebp, EDI0	; int32_t
//@ ; #line	"CSRTLA.PAS" 90
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 91
//@ 		mov	ax, Hlhr1	; uint16_t
//@ ; #line	"CSRTLA.PAS" 92
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 93
//@ 		sub	ebp, eax	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 94
//@ 		mov	ax, ImOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 95
//@ 		shl	eax, 14h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 96
//@ 		add	ebp, eax	; Add
//@ ; #line	"CSRTLA.PAS" 97
//@ 		mov	edx, ebx
//@ ; #line	"CSRTLA.PAS" 98
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 99
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 101
//@ 		mov	cx, Hlhr1	; uint16_t
//@ 		add	cx, Hlhr2	; uint16_t
//@ ; #line	"CSRTLA.PAS" 102
//@ 		mov	bx, CMPOfs	; uint16_t
//@ 		cmp	Double,	1	; uint8_t
//@ 		jz	short loc_21F4	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 104
//@ 
//@ loc_21D6:				; CODE XREF: VILineL+B5j
//@ 		mov	edi, ebp
//@ ; #line	"CSRTLA.PAS" 105
//@ 		shr	edi, 0Dh	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 106
//@ 		and	di, AliasMask	; uint16_t
//@ ; #line	"CSRTLA.PAS" 107
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 108
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 109
//@ 		mov	es:[si], al
//@ ; #line	"CSRTLA.PAS" 110
//@ 		add	si, 140h	; Add
//@ ; #line	"CSRTLA.PAS" 111
//@ 		add	ebp, edx	; Add
//@ ; #line	"CSRTLA.PAS" 112
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_21D6	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_2212	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 114
//@ 
//@ loc_21F4:				; CODE XREF: VILineL+99j VILineL+D5j
//@ 		mov	edi, ebp
//@ ; #line	"CSRTLA.PAS" 115
//@ 		shr	edi, 0Dh	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 116
//@ 		and	di, AliasMask	; uint16_t
//@ ; #line	"CSRTLA.PAS" 117
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 118
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 119
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 120
//@ 		mov	es:[si], ax
//@ ; #line	"CSRTLA.PAS" 121
//@ 		add	si, 140h	; Add
//@ ; #line	"CSRTLA.PAS" 122
//@ 		add	ebp, edx	; Add
//@ ; #line	"CSRTLA.PAS" 123
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_21F4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 126
//@ 
//@ loc_2212:				; CODE XREF: VILineL+B7j
//@ 		pop	bp
//@ 		nop			; No Operation
//@ ; #line	"CSRTLA.PAS" 127
//@ 		retn			; Return Near from Procedure
//@ VILineL		endp
//@ 
//@ ; #line	"CSRTLA.PAS" 132
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ VILineL_hi	proc near
//@ 		mov	ax, HlBr	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, cm_ofs	; uint16_t
//@ 		mov	CMPOfs,	ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 135
//@ 		mov	bx, WinH2u	; uint16_t
//@ ; #line	"CSRTLA.PAS" 136
//@ 		mov	ax, HLh1	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 137
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jb	short loc_2232	; Jump if Below	(CF=1)
//@ 		mov	ax, bx
//@ ; #line	"CSRTLA.PAS" 138
//@ 
//@ loc_2232:				; CODE XREF: VILineL_hi+19j
//@ 		mov	Hlhr1, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 140
//@ 		mov	bx, WinH2d	; uint16_t
//@ ; #line	"CSRTLA.PAS" 141
//@ 		mov	ax, Hlh2	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 142
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jb	short loc_2245	; Jump if Below	(CF=1)
//@ 		mov	ax, bx
//@ ; #line	"CSRTLA.PAS" 143
//@ 
//@ loc_2245:				; CODE XREF: VILineL_hi+2Cj
//@ 		mov	Hlhr2, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 146
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 147
//@ 		mov	bx, WinCY	; uint16_t
//@ 		sub	bx, Hlhr1	; uint16_t
//@ ; #line	"CSRTLA.PAS" 148
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 149
//@ 		xor	esi, esi	; Logical Exclusive OR
//@ 		mov	si, HLxx	; uint16_t
//@ ; #line	"CSRTLA.PAS" 150
//@ 		add	esi, [bx-6E84h]	; Add
//@ ; #line	"CSRTLA.PAS" 154
//@ 		xor	edx, edx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 155
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 156
//@ 		mov	eax, 1000000h
//@ ; #line	"CSRTLA.PAS" 157
//@ 		mov	bx, HLh1	; uint16_t
//@ ; #line	"CSRTLA.PAS" 158
//@ 		add	bx, Hlh2	; uint16_t
//@ ; #line	"CSRTLA.PAS" 159
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 160
//@ 		mov	ebx, eax
//@ ; #line	"CSRTLA.PAS" 163
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 165
//@ 		mov	ebp, EDI0	; int32_t
//@ ; #line	"CSRTLA.PAS" 166
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 167
//@ 		mov	ax, Hlhr1	; uint16_t
//@ ; #line	"CSRTLA.PAS" 168
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 169
//@ 		sub	ebp, eax	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 170
//@ 		mov	ax, ImOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 171
//@ 		shl	eax, 14h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 172
//@ 		add	ebp, eax	; Add
//@ ; #line	"CSRTLA.PAS" 173
//@ 		mov	edx, ebx
//@ ; #line	"CSRTLA.PAS" 174
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 175
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 177
//@ 		mov	cx, Hlhr1	; uint16_t
//@ 		add	cx, Hlhr2	; uint16_t
//@ ; #line	"CSRTLA.PAS" 178
//@ 		mov	bx, CMPOfs	; uint16_t
//@ 		cmp	Double,	1	; uint8_t
//@ 		jz	short loc_22D5	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 180
//@ 
//@ loc_22B5:				; CODE XREF: VILineL_hi+BCj
//@ 		mov	edi, ebp
//@ ; #line	"CSRTLA.PAS" 181
//@ 		shr	edi, 0Dh	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 182
//@ 		and	di, AliasMask	; uint16_t
//@ ; #line	"CSRTLA.PAS" 183
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 184
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 185
//@ 		mov	es:[esi], al
//@ ; #line	"CSRTLA.PAS" 186
//@ 		add	ebp, edx	; Add
//@ ; #line	"CSRTLA.PAS" 187
//@ 		add	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 188
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_22B5	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_22F5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 191
//@ 
//@ loc_22D5:				; CODE XREF: VILineL_hi+9Ej
//@ 					; VILineL_hi+DEj
//@ 		mov	edi, ebp
//@ ; #line	"CSRTLA.PAS" 192
//@ 		shr	edi, 0Dh	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 193
//@ 		and	di, AliasMask	; uint16_t
//@ ; #line	"CSRTLA.PAS" 194
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 195
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 196
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 197
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 198
//@ 		add	ebp, edx	; Add
//@ ; #line	"CSRTLA.PAS" 199
//@ 		add	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 200
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_22D5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 203
//@ 
//@ loc_22F5:				; CODE XREF: VILineL_hi+BEj
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 204
//@ 		retn			; Return Near from Procedure
//@ VILineL_hi	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 213
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ShowLine	proc near		; CODE XREF: ExpandPicture+4B0p
//@ 					; ExpandPicture:loc_58EEp
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 214
//@ 		mov	ax, Dx0		; uint16_t
//@ 		mov	es:2339h, ax
//@ ; #line	"CSRTLA.PAS" 217
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 218
//@ 		mov	esi, HLSt	; int32_t
//@ ; #line	"CSRTLA.PAS" 222
//@ 		mov	dx, Di0		; uint16_t
//@ 		mov	cx, HS		; int16_t
//@ ; #line	"CSRTLA.PAS" 223
//@ 		mov	ax, ImSeg	; uint16_t
//@ 		mov	bx, n$0		; int16_t
//@ ; #line	"CSRTLA.PAS" 224
//@ 		push	bp
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 225
//@ 		mov	ax, ObjSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 226
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 228
//@ 
//@ loc_2324:				; CODE XREF: ShowLine+4Aj
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 229
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 230
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 231
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 232
//@ 		cmp	al, 0FFh	; Compare Two Operands
//@ 		jz	short loc_2337	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 233
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 235
//@ 		mov	es:[esi], al
//@ ; #line	"CSRTLA.PAS" 236
//@ 
//@ loc_2337:				; CODE XREF: ShowLine+39j
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 237
//@ 		sub	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 238
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2324	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 239
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 240
//@ 		retn			; Return Near from Procedure
//@ ShowLine	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 247
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ShowLine2	proc near		; CODE XREF: ExpandPicture+4D0p
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 248
//@ 		mov	ax, Dx0		; uint16_t
//@ 		mov	es:2389h, ax
//@ ; #line	"CSRTLA.PAS" 251
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 252
//@ 		mov	esi, HLSt	; int32_t
//@ ; #line	"CSRTLA.PAS" 256
//@ 		mov	dx, Di0		; uint16_t
//@ 		mov	cx, HS		; int16_t
//@ ; #line	"CSRTLA.PAS" 257
//@ 		mov	ax, ImSeg	; uint16_t
//@ 		mov	bx, n$0		; int16_t
//@ ; #line	"CSRTLA.PAS" 258
//@ 		push	bp
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 259
//@ 		mov	ax, ObjSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 260
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 262
//@ 
//@ loc_2372:				; CODE XREF: ShowLine2+4Cj
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 263
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 264
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 265
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 266
//@ 		cmp	al, 0FFh	; Compare Two Operands
//@ 		jz	short loc_2387	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 267
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 268
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 269
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 270
//@ 
//@ loc_2387:				; CODE XREF: ShowLine2+39j
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 271
//@ 		sub	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 272
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2372	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 273
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 274
//@ 		retn			; Return Near from Procedure
//@ ShowLine2	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 282
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ShowGlassLine	proc near		; CODE XREF: ExpandPicture:loc_58B4p
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 283
//@ 		mov	ax, Dx0		; uint16_t
//@ 		mov	es:23FDh, ax
//@ ; #line	"CSRTLA.PAS" 284
//@ 		mov	ax, Dx0		; uint16_t
//@ 		mov	es:2434h, ax
//@ ; #line	"CSRTLA.PAS" 285
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	es:2402h, ax
//@ ; #line	"CSRTLA.PAS" 286
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	es:2439h, ax
//@ ; #line	"CSRTLA.PAS" 289
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 290
//@ 		mov	esi, HLSt	; int32_t
//@ ; #line	"CSRTLA.PAS" 294
//@ 		mov	dx, Di0		; uint16_t
//@ 		mov	cx, HS		; int16_t
//@ ; #line	"CSRTLA.PAS" 295
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 296
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 297
//@ 		push	ds
//@ ; #line	"CSRTLA.PAS" 298
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 299
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 300
//@ 		mov	ax, ObjSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 301
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 303
//@ 		cmp	InversGlass, 1	; bool
//@ 		jz	short loc_240D	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 305
//@ 		mov	ax, RGBSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 306
//@ 		mov	ds, ax
//@ ; #line	"CSRTLA.PAS" 307
//@ 
//@ loc_23E2:				; CODE XREF: ShowGlassLine+72j
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 308
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 309
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 310
//@ 		mov	bh, fs:[di]
//@ ; #line	"CSRTLA.PAS" 311
//@ 		cmp	bh, 0FFh	; Compare Two Operands
//@ 		jz	short loc_23FB	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 312
//@ 		mov	bl, es:[esi]
//@ ; #line	"CSRTLA.PAS" 313
//@ 		mov	al, [bx]
//@ ; #line	"CSRTLA.PAS" 314
//@ 		mov	es:[esi], al
//@ ; #line	"CSRTLA.PAS" 315
//@ 
//@ loc_23FB:				; CODE XREF: ShowGlassLine+5Aj
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 316
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 317
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_23E2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 318
//@ 		pop	bp
//@ 		pop	ds
//@ 		jmp	short locret_2442 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 321
//@ 
//@ loc_240D:				; CODE XREF: ShowGlassLine+46j
//@ 		mov	ax, RGBSeg	; uint16_t
//@ 		mov	ds, ax
//@ ; #line	"CSRTLA.PAS" 323
//@ 
//@ loc_2412:				; CODE XREF: ShowGlassLine+A9j
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 324
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 325
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 326
//@ 		mov	bl, fs:[di]
//@ ; #line	"CSRTLA.PAS" 327
//@ 		cmp	bl, 0FFh	; Compare Two Operands
//@ 		jz	short loc_2432	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 328
//@ 		mov	bh, es:[esi]
//@ ; #line	"CSRTLA.PAS" 329
//@ 		cmp	bh, 0		; Compare Two Operands
//@ 		jnz	short loc_242C	; Jump if Not Zero (ZF=0)
//@ 		inc	bh		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 330
//@ 
//@ loc_242C:				; CODE XREF: ShowGlassLine+93j
//@ 		mov	al, [bx]
//@ ; #line	"CSRTLA.PAS" 331
//@ 		mov	es:[esi], al
//@ ; #line	"CSRTLA.PAS" 332
//@ 
//@ loc_2432:				; CODE XREF: ShowGlassLine+8Aj
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 333
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 334
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2412	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 335
//@ 		pop	bp
//@ 		pop	ds
//@ ; #line	"CSRTLA.PAS" 338
//@ 
//@ locret_2442:				; CODE XREF: ShowGlassLine+76j
//@ 		retn			; Return Near from Procedure
//@ ShowGlassLine	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 344
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ShowGlassLine2	proc near		; CODE XREF: ExpandPicture+496p
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 345
//@ 		mov	ax, Dx0		; uint16_t
//@ 		mov	es:24ADh, ax
//@ ; #line	"CSRTLA.PAS" 346
//@ 		mov	ax, Dx0		; uint16_t
//@ 		mov	es:24E6h, ax
//@ ; #line	"CSRTLA.PAS" 347
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	es:24B2h, ax
//@ ; #line	"CSRTLA.PAS" 348
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	es:24EBh, ax
//@ ; #line	"CSRTLA.PAS" 351
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 352
//@ 		mov	esi, HLSt	; int32_t
//@ ; #line	"CSRTLA.PAS" 356
//@ 		mov	dx, Di0		; uint16_t
//@ 		mov	cx, HS		; int16_t
//@ ; #line	"CSRTLA.PAS" 357
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 358
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 359
//@ 		push	ds
//@ ; #line	"CSRTLA.PAS" 360
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 361
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 362
//@ 		mov	ax, ObjSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 363
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 365
//@ 		cmp	InversGlass, 1	; bool
//@ 		jz	short loc_24BD	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 367
//@ 		mov	ax, RGBSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 368
//@ 		mov	ds, ax
//@ ; #line	"CSRTLA.PAS" 369
//@ 
//@ loc_2490:				; CODE XREF: ShowGlassLine2+74j
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 370
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 371
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 372
//@ 		mov	bh, fs:[di]
//@ ; #line	"CSRTLA.PAS" 373
//@ 		cmp	bh, 0FFh	; Compare Two Operands
//@ 		jz	short loc_24AB	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 374
//@ 		mov	bl, es:[esi]
//@ ; #line	"CSRTLA.PAS" 375
//@ 		mov	al, [bx]
//@ ; #line	"CSRTLA.PAS" 376
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 377
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 378
//@ 
//@ loc_24AB:				; CODE XREF: ShowGlassLine2+5Aj
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 379
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 380
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2490	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 381
//@ 		pop	bp
//@ 		pop	ds
//@ 		jmp	short locret_24F4 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 384
//@ 
//@ loc_24BD:				; CODE XREF: ShowGlassLine2+46j
//@ 		mov	ax, RGBSeg	; uint16_t
//@ 		mov	ds, ax
//@ ; #line	"CSRTLA.PAS" 386
//@ 
//@ loc_24C2:				; CODE XREF: ShowGlassLine2+ADj
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 387
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 388
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 389
//@ 		mov	bl, fs:[di]
//@ ; #line	"CSRTLA.PAS" 390
//@ 		cmp	bl, 0FFh	; Compare Two Operands
//@ 		jz	short loc_24E4	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 391
//@ 		mov	bh, es:[esi]
//@ ; #line	"CSRTLA.PAS" 392
//@ 		cmp	bh, 0		; Compare Two Operands
//@ 		jnz	short loc_24DC	; Jump if Not Zero (ZF=0)
//@ 		inc	bh		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 393
//@ 
//@ loc_24DC:				; CODE XREF: ShowGlassLine2+95j
//@ 		mov	al, [bx]
//@ ; #line	"CSRTLA.PAS" 394
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 395
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 396
//@ 
//@ loc_24E4:				; CODE XREF: ShowGlassLine2+8Cj
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 397
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 398
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_24C2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 399
//@ 		pop	bp
//@ 		pop	ds
//@ ; #line	"CSRTLA.PAS" 402
//@ 
//@ locret_24F4:				; CODE XREF: ShowGlassLine2+78j
//@ 		retn			; Return Near from Procedure
//@ ShowGlassLine2	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 408
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ShowGlassLine4	proc near		; CODE XREF: ExpandPicture+46Cp
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 409
//@ 		mov	ax, Dx0		; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 410
//@ 		mov	es:2588h, ax
//@ ; #line	"CSRTLA.PAS" 411
//@ 		mov	es:25DBh, ax
//@ ; #line	"CSRTLA.PAS" 412
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ ; #line	"CSRTLA.PAS" 413
//@ 		mov	es:258Dh, ax
//@ ; #line	"CSRTLA.PAS" 414
//@ 		mov	es:25E0h, ax
//@ ; #line	"CSRTLA.PAS" 415
//@ 		mov	es:2574h, ax
//@ ; #line	"CSRTLA.PAS" 416
//@ 		mov	es:25C7h, ax
//@ ; #line	"CSRTLA.PAS" 419
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 420
//@ 		mov	esi, HLSt	; int32_t
//@ ; #line	"CSRTLA.PAS" 425
//@ 		mov	dx, Di0		; uint16_t
//@ 		mov	cx, HS		; int16_t
//@ 		dec	cx		; Decrement by 1
//@ 		shr	cx, 1		; Shift	Logical	Right
//@ 		cmp	cx, 0		; Compare Two Operands
//@ 		jnz	short loc_2537	; Jump if Not Zero (ZF=0)
//@ 		mov	cx, 1
//@ ; #line	"CSRTLA.PAS" 427
//@ 
//@ loc_2537:				; CODE XREF: ShowGlassLine4+3Dj
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 428
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 429
//@ 		push	ds
//@ ; #line	"CSRTLA.PAS" 430
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 431
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 432
//@ 		mov	ax, ObjSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 433
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 435
//@ 		cmp	InversGlass, 1	; bool
//@ 		jz	short loc_2598	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 437
//@ 		mov	ax, RGBSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 438
//@ 		mov	ds, ax
//@ ; #line	"CSRTLA.PAS" 439
//@ 
//@ loc_2551:				; CODE XREF: ShowGlassLine4+9Dj
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 440
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 441
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 442
//@ 		mov	bh, fs:[di]
//@ ; #line	"CSRTLA.PAS" 443
//@ 		cmp	bh, 0FFh	; Compare Two Operands
//@ 		jz	short loc_2571	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 444
//@ 		mov	bl, es:[esi]
//@ ; #line	"CSRTLA.PAS" 445
//@ 		mov	al, [bx]
//@ ; #line	"CSRTLA.PAS" 446
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 448
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 449
//@ 		mov	es:[esi+2], ax
//@ ; #line	"CSRTLA.PAS" 451
//@ 
//@ loc_2571:				; CODE XREF: ShowGlassLine4+69j
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 452
//@ 		cmp	bh, 0FFh	; Compare Two Operands
//@ 		jz	short loc_2586	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 454
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 455
//@ 		mov	es:[esi+2], ax
//@ ; #line	"CSRTLA.PAS" 456
//@ 
//@ loc_2586:				; CODE XREF: ShowGlassLine4+86j
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 457
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 459
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2551	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 460
//@ 		pop	bp
//@ 		pop	ds
//@ 		jmp	short locret_25E9 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 463
//@ 
//@ loc_2598:				; CODE XREF: ShowGlassLine4+55j
//@ 		mov	ax, RGBSeg	; uint16_t
//@ 		mov	ds, ax
//@ ; #line	"CSRTLA.PAS" 465
//@ 
//@ loc_259D:				; CODE XREF: ShowGlassLine4+F0j
//@ 		mov	di, dx
//@ ; #line	"CSRTLA.PAS" 466
//@ 		shr	di, 8		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 467
//@ 		add	di, bp		; Add
//@ ; #line	"CSRTLA.PAS" 468
//@ 		mov	bl, fs:[di]
//@ ; #line	"CSRTLA.PAS" 469
//@ 		cmp	bl, 0FFh	; Compare Two Operands
//@ 		jz	short loc_25C4	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 470
//@ 		mov	bh, es:[esi]
//@ ; #line	"CSRTLA.PAS" 471
//@ 		cmp	bh, 0		; Compare Two Operands
//@ 		jnz	short loc_25B7	; Jump if Not Zero (ZF=0)
//@ 		inc	bh		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 472
//@ 
//@ loc_25B7:				; CODE XREF: ShowGlassLine4+BEj
//@ 		mov	al, [bx]
//@ ; #line	"CSRTLA.PAS" 473
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 475
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 476
//@ 		mov	es:[esi+2], ax
//@ ; #line	"CSRTLA.PAS" 478
//@ 
//@ loc_25C4:				; CODE XREF: ShowGlassLine4+B5j
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 479
//@ 		cmp	bl, 0FFh	; Compare Two Operands
//@ 		jz	short loc_25D9	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 481
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 482
//@ 		mov	es:[esi+2], ax
//@ ; #line	"CSRTLA.PAS" 483
//@ 
//@ loc_25D9:				; CODE XREF: ShowGlassLine4+D9j
//@ 		sub	dx, 0FFFFh	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 484
//@ 		sub	esi, 280h	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 486
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_259D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 487
//@ 		pop	bp
//@ 		pop	ds
//@ ; #line	"CSRTLA.PAS" 490
//@ 
//@ locret_25E9:				; CODE XREF: ShowGlassLine4+A1j
//@ 		retn			; Return Near from Procedure
//@ ShowGlassLine4	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 502
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ShowSegment	proc near		; CODE XREF: VIlinePack:loc_27C4p
//@ 					; VIlineUpPack:loc_28C2p
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 503
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 505
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 506
//@ 		mov	ax, ImOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 507
//@ 		shl	eax, 0Dh	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 508
//@ 		mov	ebp, eax
//@ ; #line	"CSRTLA.PAS" 510
//@ 		mov	cx, yf2		; uint16_t
//@ 		shr	cx, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 511
//@ 		cmp	cx, WinE	; uint16_t
//@ 		jb	short loc_260E	; Jump if Below	(CF=1)
//@ 		mov	cx, WinE	; uint16_t
//@ ; #line	"CSRTLA.PAS" 513
//@ 
//@ loc_260E:				; CODE XREF: ShowSegment+1Ej
//@ 		mov	ax, yf1		; uint16_t
//@ 		cmp	ax, WinB3	; uint16_t
//@ 		jg	short loc_2634	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSRTLA.PAS" 515
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 516
//@ 		mov	bx, WinB3	; uint16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 517
//@ 		mov	eax, mEDX	; int32_t
//@ ; #line	"CSRTLA.PAS" 518
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 519
//@ 		shr	eax, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 520
//@ 		add	ebp, eax	; Add
//@ ; #line	"CSRTLA.PAS" 521
//@ 		mov	ax, WinB3	; uint16_t
//@ 		mov	yf1, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 523
//@ 
//@ loc_2634:				; CODE XREF: ShowSegment+2Bj
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		cmp	cx, 0		; Compare Two Operands
//@ 		jz	short loc_2677	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 528
//@ 		mov	bx, yf1		; uint16_t
//@ 		shr	bx, 4		; Shift	Logical	Right
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 529
//@ 		xor	esi, esi	; Logical Exclusive OR
//@ 		mov	si, HLxx	; uint16_t
//@ ; #line	"CSRTLA.PAS" 530
//@ 		add	esi, [bx-6E84h]	; Add
//@ ; #line	"CSRTLA.PAS" 533
//@ 		mov	edx, mEDX	; int32_t
//@ ; #line	"CSRTLA.PAS" 534
//@ 		mov	bx, CMPOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 537
//@ 
//@ loc_265D:				; CODE XREF: ShowSegment+8Bj
//@ 		mov	edi, ebp
//@ ; #line	"CSRTLA.PAS" 538
//@ 		shr	edi, 0Dh	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 539
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 540
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 541
//@ 		add	ebp, edx	; Add
//@ ; #line	"CSRTLA.PAS" 542
//@ 		mov	es:[esi], al
//@ ; #line	"CSRTLA.PAS" 543
//@ 		add	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 544
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_265D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 546
//@ 
//@ loc_2677:				; CODE XREF: ShowSegment+52j
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 547
//@ 		retn			; Return Near from Procedure
//@ ShowSegment	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 552
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ShowSegment2	proc near		; CODE XREF: VIlinePack+B5p
//@ 					; VIlineUpPack+ECp
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 553
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 555
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 556
//@ 		mov	ax, ImOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 557
//@ 		shl	eax, 0Dh	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 558
//@ 		mov	ebp, eax
//@ ; #line	"CSRTLA.PAS" 560
//@ 		mov	cx, yf2		; uint16_t
//@ 		shr	cx, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 561
//@ 		cmp	cx, WinE	; uint16_t
//@ 		jb	short loc_269D	; Jump if Below	(CF=1)
//@ 		mov	cx, WinE	; uint16_t
//@ ; #line	"CSRTLA.PAS" 563
//@ 
//@ loc_269D:				; CODE XREF: ShowSegment2+1Ej
//@ 		mov	ax, yf1		; uint16_t
//@ 		cmp	ax, WinB3	; uint16_t
//@ 		jg	short loc_26C3	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSRTLA.PAS" 565
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 566
//@ 		mov	bx, WinB3	; uint16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 567
//@ 		mov	eax, mEDX	; int32_t
//@ ; #line	"CSRTLA.PAS" 568
//@ 		mul	ebx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 569
//@ 		shr	eax, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 570
//@ 		add	ebp, eax	; Add
//@ ; #line	"CSRTLA.PAS" 571
//@ 		mov	ax, WinB3	; uint16_t
//@ 		mov	yf1, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 573
//@ 
//@ loc_26C3:				; CODE XREF: ShowSegment2+2Bj
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		cmp	cx, 0		; Compare Two Operands
//@ 		jz	short loc_2708	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 578
//@ 		mov	bx, yf1		; uint16_t
//@ 		shr	bx, 4		; Shift	Logical	Right
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 579
//@ 		xor	esi, esi	; Logical Exclusive OR
//@ 		mov	si, HLxx	; uint16_t
//@ ; #line	"CSRTLA.PAS" 580
//@ 		add	esi, [bx-6E84h]	; Add
//@ ; #line	"CSRTLA.PAS" 583
//@ 		mov	edx, mEDX	; int32_t
//@ ; #line	"CSRTLA.PAS" 584
//@ 		mov	bx, CMPOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 587
//@ 
//@ loc_26EC:				; CODE XREF: ShowSegment2+8Dj
//@ 		mov	edi, ebp
//@ ; #line	"CSRTLA.PAS" 588
//@ 		shr	edi, 0Dh	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 589
//@ 		mov	al, fs:[di]
//@ ; #line	"CSRTLA.PAS" 590
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 591
//@ 		add	ebp, edx	; Add
//@ ; #line	"CSRTLA.PAS" 592
//@ 		mov	ah, al
//@ ; #line	"CSRTLA.PAS" 595
//@ 		mov	es:[esi], ax
//@ ; #line	"CSRTLA.PAS" 596
//@ 		add	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 597
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_26EC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 599
//@ 
//@ loc_2708:				; CODE XREF: ShowSegment2+52j
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 600
//@ 		retn			; Return Near from Procedure
//@ ShowSegment2	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 609
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ VIlinePack	proc near
//@ 		mov	ax, WinCY	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 610
//@ 		sub	ax, HLh1	; uint16_t
//@ 		mov	yf0, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 611
//@ 		mov	bx, HLh1	; uint16_t
//@ 		add	bx, Hlh2	; uint16_t
//@ 		mov	FullH, bx	; uint16_t
//@ 		mov	cx, bx
//@ ; #line	"CSRTLA.PAS" 613
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 614
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 616
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 617
//@ 		shr	bx, 4		; Shift	Logical	Right
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 618
//@ 		cmp	ax, 10h		; Compare Two Operands
//@ 		jb	short loc_273C	; Jump if Below	(CF=1)
//@ 		mov	ax, 10h
//@ ; #line	"CSRTLA.PAS" 619
//@ 
//@ loc_273C:				; CODE XREF: VIlinePack+2Dj
//@ 		add	ax, DDark	; int16_t
//@ ; #line	"CSRTLA.PAS" 620
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, cm_ofs	; uint16_t
//@ 		mov	CMPOfs,	ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 624
//@ 		xor	edx, edx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 625
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 626
//@ 		mov	eax, 1000000h
//@ ; #line	"CSRTLA.PAS" 627
//@ 		mov	bx, cx
//@ ; #line	"CSRTLA.PAS" 628
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 629
//@ 		mov	ebx, eax
//@ ; #line	"CSRTLA.PAS" 630
//@ 		mov	mEDX, eax	; int32_t
//@ ; #line	"CSRTLA.PAS" 635
//@ 
//@ loc_2762:				; CODE XREF: VIlinePack+C4j
//@ 		mov	di, ImOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 636
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 637
//@ 		mov	al, fs:[di]
//@ 		cmp	al, 0FFh	; Compare Two Operands
//@ 		jz	short locret_27D0 ; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 638
//@ 		mov	FromOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 639
//@ 		mov	al, fs:[di+1]
//@ 		mov	Cnt, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 640
//@ 		add	di, 2		; Add
//@ ; #line	"CSRTLA.PAS" 641
//@ 		mov	ImOfs, di	; uint16_t
//@ ; #line	"CSRTLA.PAS" 643
//@ 		mov	cx, yf0		; uint16_t
//@ ; #line	"CSRTLA.PAS" 644
//@ 		mov	bx, FullH	; uint16_t
//@ ; #line	"CSRTLA.PAS" 646
//@ 		mov	ax, FromOfs	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 647
//@ 		mov	al, ah
//@ 		mov	ah, dl
//@ 		add	ax, cx		; Add
//@ 		mov	yf1, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 648
//@ 		cmp	WinE3, ax	; uint16_t
//@ 		jl	short loc_27C7	; Jump if Less (SF!=OF)
//@ ; #line	"CSRTLA.PAS" 650
//@ 		mov	ax, FromOfs	; uint16_t
//@ 		add	ax, Cnt		; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 651
//@ 		mov	al, ah
//@ 		mov	ah, dl
//@ 		add	ax, cx		; Add
//@ 		mov	yf2, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 652
//@ 		cmp	WinB3, ax	; uint16_t
//@ 		jg	short loc_27C7	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSRTLA.PAS" 654
//@ 		cmp	Double,	0	; uint8_t
//@ 		jz	short loc_27C4	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 655
//@ 		call	ShowSegment2	; function near	PASCAL returns void
//@ 		jmp	short loc_27C7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 656
//@ 
//@ loc_27C4:				; CODE XREF: VIlinePack+B3j
//@ 		call	ShowSegment	; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 657
//@ 
//@ loc_27C7:				; CODE XREF: VIlinePack+92j
//@ 					; VIlinePack+ACj ...
//@ 		mov	ax, Cnt		; uint16_t
//@ 		add	ImOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 658
//@ 		jmp	short loc_2762	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 661
//@ 
//@ locret_27D0:				; CODE XREF: VIlinePack+63j
//@ 		retn			; Return Near from Procedure
//@ VIlinePack	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 667
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ VIlineUpPack	proc near
//@ 		mov	ax, WinCY	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 668
//@ 		sub	ax, HLh1	; uint16_t
//@ 		mov	yf0, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 669
//@ 		mov	bx, HLh1	; uint16_t
//@ 		add	bx, Hlh2	; uint16_t
//@ 		mov	FullH, bx	; uint16_t
//@ 		mov	cx, bx
//@ ; #line	"CSRTLA.PAS" 671
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 672
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 674
//@ 		mov	ax, BLevelW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 675
//@ 		shr	bx, 4		; Shift	Logical	Right
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 676
//@ 		cmp	ax, 10h		; Compare Two Operands
//@ 		jb	short loc_2803	; Jump if Below	(CF=1)
//@ 		mov	ax, 10h
//@ ; #line	"CSRTLA.PAS" 677
//@ 
//@ loc_2803:				; CODE XREF: VIlineUpPack+2Dj
//@ 		add	ax, DDark	; int16_t
//@ ; #line	"CSRTLA.PAS" 678
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, cm_ofs	; uint16_t
//@ 		mov	CMPOfs,	ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 683
//@ 		xor	edx, edx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 684
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 685
//@ 		mov	eax, 1000000h
//@ ; #line	"CSRTLA.PAS" 686
//@ 		mov	bx, cx
//@ ; #line	"CSRTLA.PAS" 687
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 688
//@ 		mov	ebx, eax
//@ ; #line	"CSRTLA.PAS" 689
//@ 		mov	mEDX, eax	; int32_t
//@ ; #line	"CSRTLA.PAS" 695
//@ 
//@ loc_2829:				; CODE XREF: VIlineUpPack+FBj
//@ 		mov	ax, ImSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 696
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 698
//@ 		mov	di, ImOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 699
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 700
//@ 		mov	al, fs:[di]
//@ 		cmp	al, 0FFh	; Compare Two Operands
//@ 		jnz	short loc_283E	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_28CF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 701
//@ 
//@ loc_283E:				; CODE XREF: VIlineUpPack+68j
//@ 		mov	FromOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 702
//@ 		mov	al, fs:[di+1]
//@ 		mov	Cnt, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 703
//@ 		add	di, 2		; Add
//@ ; #line	"CSRTLA.PAS" 704
//@ 		mov	ImOfs, di	; uint16_t
//@ ; #line	"CSRTLA.PAS" 709
//@ 		mov	bx, ScrollK	; uint16_t
//@ ; #line	"CSRTLA.PAS" 710
//@ 		mov	ax, FromOfs	; uint16_t
//@ 		add	ax, Cnt		; uint16_t
//@ 		sub	ax, bx		; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 711
//@ 		js	short loc_28C5	; Jump if Sign (SF=1)
//@ ; #line	"CSRTLA.PAS" 712
//@ 		mov	ax, bx
//@ 		cmp	ax, FromOfs	; uint16_t
//@ 		ja	short loc_286C	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSRTLA.PAS" 713
//@ 		sub	FromOfs, bx	; uint16_t
//@ 		jmp	short loc_287E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 714
//@ 
//@ loc_286C:				; CODE XREF: VIlineUpPack+93j
//@ 		sub	bx, FromOfs	; uint16_t
//@ 		sub	Cnt, bx		; uint16_t
//@ 		add	ImOfs, bx	; uint16_t
//@ 		mov	FromOfs, 0	; uint16_t
//@ ; #line	"CSRTLA.PAS" 719
//@ 
//@ loc_287E:				; CODE XREF: VIlineUpPack+99j
//@ 		mov	cx, yf0		; uint16_t
//@ ; #line	"CSRTLA.PAS" 720
//@ 		mov	bx, FullH	; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 722
//@ 		mov	ax, FromOfs	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 723
//@ 		mov	ax, dx
//@ 		add	ax, cx		; Add
//@ 		mov	yf1, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 724
//@ 		cmp	WinE3, ax	; uint16_t
//@ 		jl	short loc_28C5	; Jump if Less (SF!=OF)
//@ ; #line	"CSRTLA.PAS" 726
//@ 		mov	ax, FromOfs	; uint16_t
//@ 		add	ax, Cnt		; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"CSRTLA.PAS" 727
//@ 		mov	ax, dx
//@ 		add	ax, cx		; Add
//@ 		mov	yf2, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 728
//@ 		cmp	WinB3, ax	; uint16_t
//@ 		jg	short loc_28C5	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSRTLA.PAS" 730
//@ 		cmp	Double,	0	; uint8_t
//@ 		jz	short loc_28C2	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 731
//@ 		call	ShowSegment2	; function near	PASCAL returns void
//@ 		jmp	short loc_28C5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 732
//@ 
//@ loc_28C2:				; CODE XREF: VIlineUpPack+EAj
//@ 		call	ShowSegment	; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 733
//@ 
//@ loc_28C5:				; CODE XREF: VIlineUpPack+8Bj
//@ 					; VIlineUpPack+CAj ...
//@ 		mov	ax, Cnt		; uint16_t
//@ 		add	ImOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 734
//@ 		jmp	loc_2829	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 737
//@ 
//@ locret_28CF:				; CODE XREF: VIlineUpPack+6Aj
//@ 		retn			; Return Near from Procedure
//@ VIlineUpPack	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 750
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ Draw_Cell1	proc near		; CODE XREF: CellVHi+20Dp
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 751
//@ 		mov	ax, DNpx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:298Dh, ax
//@ 		mov	es:2A1Ah, ax
//@ 		mov	es:2A07h, ax
//@ ; #line	"CSRTLA.PAS" 752
//@ 		mov	ax, DNpy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:2993h, ax
//@ 		mov	es:2A23h, ax
//@ 		mov	es:2A0Dh, ax
//@ ; #line	"CSRTLA.PAS" 753
//@ 		mov	al, Xi		; uint8_t
//@ 		mov	es:298Ch, al
//@ 		mov	es:2A19h, al
//@ 		mov	es:2A06h, al
//@ ; #line	"CSRTLA.PAS" 754
//@ 		mov	al, Yi		; uint8_t
//@ 		mov	es:2992h, al
//@ 		mov	es:2A22h, al
//@ 		mov	es:2A0Ch, al
//@ ; #line	"CSRTLA.PAS" 755
//@ 		mov	ax, CMP0	; uint16_t
//@ 		mov	es:297Fh, ax
//@ ; #line	"CSRTLA.PAS" 756
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 758
//@ 		mov	cx, FLen	; uint16_t
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 760
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, FLeftEnd	; int16_t
//@ ; #line	"CSRTLA.PAS" 761
//@ 		mov	edi, FCSAddr	; int32_t
//@ ; #line	"CSRTLA.PAS" 762
//@ 		add	edi, eax	; Add
//@ ; #line	"CSRTLA.PAS" 763
//@ 		mov	dx, Cpx		; uint16_t
//@ ; #line	"CSRTLA.PAS" 764
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 765
//@ 		mov	ax, Cpy		; uint16_t
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 767
//@ 		mov	al, 1
//@ ; #line	"CSRTLA.PAS" 768
//@ 		cmp	CFlr, 3Fh ; '?' ; uint8_t
//@ 		jnz	short loc_2950	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2A16	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 769
//@ 
//@ loc_2950:				; CODE XREF: Draw_Cell1+7Bj
//@ 		cmp	CFlr, 3Eh ; '>' ; uint8_t
//@ 		jnz	short loc_295B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 770
//@ 		inc	cx		; Increment by 1
//@ 		jmp	loc_2A11	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 772
//@ 
//@ loc_295B:				; CODE XREF: Draw_Cell1+85j
//@ 					; Draw_Cell1+C8j
//@ 		mov	si, bp
//@ ; #line	"CSRTLA.PAS" 773
//@ 		mov	ax, dx
//@ ; #line	"CSRTLA.PAS" 774
//@ 		shr	si, 0Ah		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 775
//@ 		shr	ax, 0Ah		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 776
//@ 		mov	bx, si
//@ ; #line	"CSRTLA.PAS" 777
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 778
//@ 		shl	bx, 4		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 779
//@ 		add	si, ax		; Add
//@ ; #line	"CSRTLA.PAS" 780
//@ 		shr	al, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 781
//@ 		mov	bl, al
//@ ; #line	"CSRTLA.PAS" 782
//@ 		add	bx, CurShOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 783
//@ 		mov	bh, gs:[bx]
//@ ; #line	"CSRTLA.PAS" 784
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 785
//@ 		add	bx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 787
//@ 		mov	al, fs:[si]
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 788
//@ 		mov	es:[edi], al
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 789
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 790
//@ 		jb	short loc_299D	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 791
//@ 
//@ loc_2991:				; CODE XREF: Draw_Cell1+FEj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 792
//@ 		jb	short loc_29D0	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 793
//@ 
//@ loc_2997:				; CODE XREF: Draw_Cell1+131j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_295B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 794
//@ 		jmp	loc_2A2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 798
//@ 
//@ loc_299D:				; CODE XREF: Draw_Cell1+BFj
//@ 					; Draw_Cell1+139j ...
//@ 		mov	ax, FMapDx	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 799
//@ 		mov	ax, FShwDx	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 800
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 801
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 802
//@ 		cmp	bl, 3Eh	; '>'   ; Compare Two Operands
//@ 		jnz	short loc_29BD	; Jump if Not Zero (ZF=0)
//@ 		mov	SkyVisible, 1	; bool
//@ 		jmp	short loc_2A0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 803
//@ 
//@ loc_29BD:				; CODE XREF: Draw_Cell1+E4j
//@ 		mov	al, 1
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		jz	short loc_2A21	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 804
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 805
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 806
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 807
//@ 		jmp	short loc_2991	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 810
//@ 
//@ loc_29D0:				; CODE XREF: Draw_Cell1+C5j
//@ 					; Draw_Cell1+13Fj ...
//@ 		mov	ax, FMapDy	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 811
//@ 		mov	ax, FShwDy	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 812
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 813
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 814
//@ 		cmp	bl, 3Eh	; '>'   ; Compare Two Operands
//@ 		jnz	short loc_29F0	; Jump if Not Zero (ZF=0)
//@ 		mov	SkyVisible, 1	; bool
//@ 		jmp	short loc_2A11	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 815
//@ 
//@ loc_29F0:				; CODE XREF: Draw_Cell1+117j
//@ 		mov	al, 1
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		jz	short loc_2A27	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 816
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 817
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 818
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 819
//@ 		jmp	short loc_2997	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 822
//@ 
//@ loc_2A03:				; CODE XREF: Draw_Cell1+142j
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 823
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 824
//@ 		jb	short loc_299D	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 825
//@ 
//@ loc_2A0B:				; CODE XREF: Draw_Cell1+EBj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 826
//@ 		jb	short loc_29D0	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 828
//@ 
//@ loc_2A11:				; CODE XREF: Draw_Cell1+88j
//@ 					; Draw_Cell1+11Ej
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2A03	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 830
//@ 		jmp	short loc_2A2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 834
//@ 
//@ loc_2A16:				; CODE XREF: Draw_Cell1+7Dj
//@ 					; Draw_Cell1+158j
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 835
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 836
//@ 		jnb	short loc_2A21	; Jump if Not Below (CF=0)
//@ 		jmp	loc_299D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 837
//@ 
//@ loc_2A21:				; CODE XREF: Draw_Cell1+F2j
//@ 					; Draw_Cell1+14Cj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 838
//@ 		jb	short loc_29D0	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 839
//@ 
//@ loc_2A27:				; CODE XREF: Draw_Cell1+125j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2A16	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 842
//@ 
//@ loc_2A2A:				; CODE XREF: Draw_Cell1+CAj
//@ 					; Draw_Cell1+144j
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 844
//@ 		retn			; Return Near from Procedure
//@ Draw_Cell1	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 852
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ Draw_Cell2	proc near		; CODE XREF: CellVHi+21Ap
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 853
//@ 		mov	ax, DNpx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:2AEBh, ax
//@ 		mov	es:2B78h, ax
//@ 		mov	es:2B65h, ax
//@ ; #line	"CSRTLA.PAS" 854
//@ 		mov	ax, DNpy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:2AF1h, ax
//@ 		mov	es:2B81h, ax
//@ 		mov	es:2B6Bh, ax
//@ ; #line	"CSRTLA.PAS" 855
//@ 		mov	al, Xi		; uint8_t
//@ 		mov	es:2AEAh, al
//@ 		mov	es:2B77h, al
//@ 		mov	es:2B64h, al
//@ ; #line	"CSRTLA.PAS" 856
//@ 		mov	al, Yi		; uint8_t
//@ 		mov	es:2AF0h, al
//@ 		mov	es:2B80h, al
//@ 		mov	es:2B6Ah, al
//@ ; #line	"CSRTLA.PAS" 857
//@ 		mov	ax, CMP0	; uint16_t
//@ 		mov	es:2ADBh, ax
//@ ; #line	"CSRTLA.PAS" 858
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 860
//@ 		mov	cx, FLen	; uint16_t
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 862
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, FLeftEnd	; int16_t
//@ ; #line	"CSRTLA.PAS" 863
//@ 		mov	edi, FCSAddr	; int32_t
//@ ; #line	"CSRTLA.PAS" 864
//@ 		add	edi, eax	; Add
//@ ; #line	"CSRTLA.PAS" 865
//@ 		mov	dx, Cpx		; uint16_t
//@ ; #line	"CSRTLA.PAS" 866
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 867
//@ 		mov	ax, Cpy		; uint16_t
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 869
//@ 		mov	al, 1
//@ ; #line	"CSRTLA.PAS" 870
//@ 		cmp	CFlr, 3Fh ; '?' ; uint8_t
//@ 		jnz	short loc_2AAC	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2B74	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 871
//@ 
//@ loc_2AAC:				; CODE XREF: Draw_Cell2+7Bj
//@ 		cmp	CFlr, 3Eh ; '>' ; uint8_t
//@ 		jnz	short loc_2AB7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 872
//@ 		inc	cx		; Increment by 1
//@ 		jmp	loc_2B6F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 874
//@ 
//@ loc_2AB7:				; CODE XREF: Draw_Cell2+85j
//@ 					; Draw_Cell2+CAj
//@ 		mov	si, bp
//@ ; #line	"CSRTLA.PAS" 875
//@ 		mov	ax, dx
//@ ; #line	"CSRTLA.PAS" 876
//@ 		shr	si, 0Bh		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 877
//@ 		shr	ax, 0Bh		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 878
//@ 		mov	bx, si
//@ ; #line	"CSRTLA.PAS" 879
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 880
//@ 		shl	bx, 5		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 881
//@ 		add	si, ax		; Add
//@ ; #line	"CSRTLA.PAS" 882
//@ 		shr	al, 3		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 883
//@ 		mov	bl, al
//@ ; #line	"CSRTLA.PAS" 884
//@ 		add	bx, CurShOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 885
//@ 		mov	bh, gs:[bx]
//@ ; #line	"CSRTLA.PAS" 886
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 887
//@ 		add	bx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 889
//@ 		mov	al, fs:[si+1000h]
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 890
//@ 		mov	es:[edi], al
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 892
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 893
//@ 		jb	short loc_2AFB	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 894
//@ 
//@ loc_2AEF:				; CODE XREF: Draw_Cell2+100j
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 895
//@ 		jb	short loc_2B2E	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 896
//@ 
//@ loc_2AF5:				; CODE XREF: Draw_Cell2+133j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2AB7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 897
//@ 		jmp	loc_2B88	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 901
//@ 
//@ loc_2AFB:				; CODE XREF: Draw_Cell2+C1j
//@ 					; Draw_Cell2+13Bj ...
//@ 		mov	ax, FMapDx	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 903
//@ 		mov	ax, FShwDx	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 904
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 905
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 906
//@ 		cmp	bl, 3Eh	; '>'   ; Compare Two Operands
//@ 		jnz	short loc_2B1B	; Jump if Not Zero (ZF=0)
//@ 		mov	SkyVisible, 1	; bool
//@ 		jmp	short loc_2B69	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 907
//@ 
//@ loc_2B1B:				; CODE XREF: Draw_Cell2+E6j
//@ 		mov	al, 1
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		jz	short loc_2B7F	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 908
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 909
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 910
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 911
//@ 		jmp	short loc_2AEF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 914
//@ 
//@ loc_2B2E:				; CODE XREF: Draw_Cell2+C7j
//@ 					; Draw_Cell2+141j ...
//@ 		mov	ax, FMapDy	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 916
//@ 		mov	ax, FShwDy	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 917
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 918
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 919
//@ 		cmp	bl, 3Eh	; '>'   ; Compare Two Operands
//@ 		jnz	short loc_2B4E	; Jump if Not Zero (ZF=0)
//@ 		mov	SkyVisible, 1	; bool
//@ 		jmp	short loc_2B6F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 920
//@ 
//@ loc_2B4E:				; CODE XREF: Draw_Cell2+119j
//@ 		mov	al, 1
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		jz	short loc_2B85	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 921
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 922
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 923
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 924
//@ 		jmp	short loc_2AF5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 928
//@ 
//@ loc_2B61:				; CODE XREF: Draw_Cell2+144j
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 929
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 930
//@ 		jb	short loc_2AFB	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 931
//@ 
//@ loc_2B69:				; CODE XREF: Draw_Cell2+EDj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 932
//@ 		jb	short loc_2B2E	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 934
//@ 
//@ loc_2B6F:				; CODE XREF: Draw_Cell2+88j
//@ 					; Draw_Cell2+120j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2B61	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 936
//@ 		jmp	short loc_2B88	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 940
//@ 
//@ loc_2B74:				; CODE XREF: Draw_Cell2+7Dj
//@ 					; Draw_Cell2+15Aj
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 941
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 942
//@ 		jnb	short loc_2B7F	; Jump if Not Below (CF=0)
//@ 		jmp	loc_2AFB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 943
//@ 
//@ loc_2B7F:				; CODE XREF: Draw_Cell2+F4j
//@ 					; Draw_Cell2+14Ej
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 944
//@ 		jb	short loc_2B2E	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 945
//@ 
//@ loc_2B85:				; CODE XREF: Draw_Cell2+127j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2B74	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 948
//@ 
//@ loc_2B88:				; CODE XREF: Draw_Cell2+CCj
//@ 					; Draw_Cell2+146j
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 949
//@ 		retn			; Return Near from Procedure
//@ Draw_Cell2	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 955
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ Draw_Cell3	proc near		; CODE XREF: CellVHi:loc_2F07p
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 956
//@ 		mov	ax, DNpx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:2C49h, ax
//@ 		mov	es:2CD6h, ax
//@ 		mov	es:2CC3h, ax
//@ ; #line	"CSRTLA.PAS" 957
//@ 		mov	ax, DNpy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:2C4Fh, ax
//@ 		mov	es:2CDFh, ax
//@ 		mov	es:2CC9h, ax
//@ ; #line	"CSRTLA.PAS" 958
//@ 		mov	al, Xi		; uint8_t
//@ 		mov	es:2C48h, al
//@ 		mov	es:2CD5h, al
//@ 		mov	es:2CC2h, al
//@ ; #line	"CSRTLA.PAS" 959
//@ 		mov	al, Yi		; uint8_t
//@ 		mov	es:2C4Eh, al
//@ 		mov	es:2CDEh, al
//@ 		mov	es:2CC8h, al
//@ ; #line	"CSRTLA.PAS" 960
//@ 		mov	ax, CMP0	; uint16_t
//@ 		mov	es:2C39h, ax
//@ ; #line	"CSRTLA.PAS" 961
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 963
//@ 		mov	cx, FLen	; uint16_t
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 965
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, FLeftEnd	; int16_t
//@ ; #line	"CSRTLA.PAS" 966
//@ 		mov	edi, FCSAddr	; int32_t
//@ ; #line	"CSRTLA.PAS" 967
//@ 		add	edi, eax	; Add
//@ ; #line	"CSRTLA.PAS" 968
//@ 		mov	dx, Cpx		; uint16_t
//@ ; #line	"CSRTLA.PAS" 969
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 970
//@ 		mov	ax, Cpy		; uint16_t
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 972
//@ 		mov	al, 1
//@ ; #line	"CSRTLA.PAS" 973
//@ 		cmp	CFlr, 3Fh ; '?' ; uint8_t
//@ 		jnz	short loc_2C0A	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2CD2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 974
//@ 
//@ loc_2C0A:				; CODE XREF: Draw_Cell3+7Bj
//@ 		cmp	CFlr, 3Eh ; '>' ; uint8_t
//@ 		jnz	short loc_2C15	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 975
//@ 		inc	cx		; Increment by 1
//@ 		jmp	loc_2CCD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 977
//@ 
//@ loc_2C15:				; CODE XREF: Draw_Cell3+85j
//@ 					; Draw_Cell3+CAj
//@ 		mov	si, bp
//@ ; #line	"CSRTLA.PAS" 978
//@ 		mov	ax, dx
//@ ; #line	"CSRTLA.PAS" 979
//@ 		shr	si, 0Ch		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 980
//@ 		shr	ax, 0Ch		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 981
//@ 		mov	bx, si
//@ ; #line	"CSRTLA.PAS" 982
//@ 		shl	si, 4		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 983
//@ 		shl	bx, 6		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 984
//@ 		add	si, ax		; Add
//@ ; #line	"CSRTLA.PAS" 985
//@ 		shr	al, 2		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 986
//@ 		mov	bl, al
//@ ; #line	"CSRTLA.PAS" 987
//@ 		add	bx, CurShOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 988
//@ 		mov	bh, gs:[bx]
//@ ; #line	"CSRTLA.PAS" 989
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 990
//@ 		add	bx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 992
//@ 		mov	al, fs:[si+1400h]
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 993
//@ 		mov	es:[edi], al
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 994
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 995
//@ 		jb	short loc_2C59	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 996
//@ 
//@ loc_2C4D:				; CODE XREF: Draw_Cell3+100j
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 997
//@ 		jb	short loc_2C8C	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 998
//@ 
//@ loc_2C53:				; CODE XREF: Draw_Cell3+133j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2C15	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 999
//@ 		jmp	loc_2CE6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1003
//@ 
//@ loc_2C59:				; CODE XREF: Draw_Cell3+C1j
//@ 					; Draw_Cell3+13Bj ...
//@ 		mov	ax, FMapDx	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1005
//@ 		mov	ax, FShwDx	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1006
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1007
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1008
//@ 		cmp	bl, 3Eh	; '>'   ; Compare Two Operands
//@ 		jnz	short loc_2C79	; Jump if Not Zero (ZF=0)
//@ 		mov	SkyVisible, 1	; bool
//@ 		jmp	short loc_2CC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1009
//@ 
//@ loc_2C79:				; CODE XREF: Draw_Cell3+E6j
//@ 		mov	al, 1
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		jz	short loc_2CDD	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1010
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1011
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1012
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1013
//@ 		jmp	short loc_2C4D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1015
//@ 
//@ loc_2C8C:				; CODE XREF: Draw_Cell3+C7j
//@ 					; Draw_Cell3+141j ...
//@ 		mov	ax, FMapDy	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1017
//@ 		mov	ax, FShwDy	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1018
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1019
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1020
//@ 		cmp	bl, 3Eh	; '>'   ; Compare Two Operands
//@ 		jnz	short loc_2CAC	; Jump if Not Zero (ZF=0)
//@ 		mov	SkyVisible, 1	; bool
//@ 		jmp	short loc_2CCD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1021
//@ 
//@ loc_2CAC:				; CODE XREF: Draw_Cell3+119j
//@ 		mov	al, 1
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		jz	short loc_2CE3	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1022
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1023
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1024
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1025
//@ 		jmp	short loc_2C53	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1028
//@ 
//@ loc_2CBF:				; CODE XREF: Draw_Cell3+144j
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1029
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1030
//@ 		jb	short loc_2C59	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1031
//@ 
//@ loc_2CC7:				; CODE XREF: Draw_Cell3+EDj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1032
//@ 		jb	short loc_2C8C	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1034
//@ 
//@ loc_2CCD:				; CODE XREF: Draw_Cell3+88j
//@ 					; Draw_Cell3+120j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2CBF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1036
//@ 		jmp	short loc_2CE6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1040
//@ 
//@ loc_2CD2:				; CODE XREF: Draw_Cell3+7Dj
//@ 					; Draw_Cell3+15Aj
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1041
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1042
//@ 		jnb	short loc_2CDD	; Jump if Not Below (CF=0)
//@ 		jmp	loc_2C59	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1043
//@ 
//@ loc_2CDD:				; CODE XREF: Draw_Cell3+F4j
//@ 					; Draw_Cell3+14Ej
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1044
//@ 		jb	short loc_2C8C	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1045
//@ 
//@ loc_2CE3:				; CODE XREF: Draw_Cell3+127j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2CD2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1049
//@ 
//@ loc_2CE6:				; CODE XREF: Draw_Cell3+CCj
//@ 					; Draw_Cell3+146j
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 1050
//@ 		retn			; Return Near from Procedure
//@ Draw_Cell3	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1058
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CellVHi		proc near		; CODE XREF: BuildFloorCell+6Fp
//@ 
//@ var_2		= word ptr -2
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 1059
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr FCSAddr, ax ; int32_t
//@ 		mov	word ptr FCSAddr+2, ax ; int32_t
//@ ; #line	"CSRTLA.PAS" 1060
//@ 		mov	ax, WinSX	; uint16_t
//@ 		mov	FLeftEnd, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1061
//@ 		mov	ax, WinEX	; uint16_t
//@ 		mov	FRightEnd, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1063
//@ 		cmp	ica, 0		; int16_t
//@ 		jge	short loc_2D0E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	Xi, 0C2h ; 'Â'  ; uint8_t
//@ 		jmp	short loc_2D13	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D0E:				; CODE XREF: CellVHi+1Dj
//@ 		mov	Xi, 0EAh ; 'ê'  ; uint8_t
//@ ; #line	"CSRTLA.PAS" 1064
//@ 
//@ loc_2D13:				; CODE XREF: CellVHi+24j
//@ 		cmp	isa, 0		; int16_t
//@ 		jle	short loc_2D21	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	Yi, 0C5h ; 'Å'  ; uint8_t
//@ 		jmp	short loc_2D26	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D21:				; CODE XREF: CellVHi+30j
//@ 		mov	Yi, 0EDh ; 'í'  ; uint8_t
//@ ; #line	"CSRTLA.PAS" 1066
//@ 
//@ loc_2D26:				; CODE XREF: CellVHi+37j
//@ 		mov	ax, YMin1	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, WinH2u	; uint16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jge	short loc_2D38	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_2F1E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D38:				; CODE XREF: CellVHi+4Bj
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2D41	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D3D:				; CODE XREF: CellVHi+233j
//@ 		dec	n$0		; int16_t
//@ ; #line	"CSRTLA.PAS" 1068
//@ 
//@ loc_2D41:				; CODE XREF: CellVHi+53j CellVHi+8Aj
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_2D64	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2D74	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_2D74	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2D64:				; CODE XREF: CellVHi+74j
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, FLeftEnd	; int16_t
//@ 		jle	short loc_2D74	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		inc	FLeftEnd	; int16_t
//@ 		jmp	short loc_2D41	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1069
//@ 
//@ loc_2D74:				; CODE XREF: CellVHi+76j CellVHi+7Aj ...
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_2D97	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2DA7	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_2DA7	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2D97:				; CODE XREF: CellVHi+A7j
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, FRightEnd	; int16_t
//@ 		jge	short loc_2DA7	; Jump if Greater or Equal (SF=OF)
//@ 		dec	FRightEnd	; int16_t
//@ 		jmp	short loc_2D74	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1070
//@ 
//@ loc_2DA7:				; CODE XREF: CellVHi+A9j CellVHi+ADj ...
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		sub	ax, FLeftEnd	; int16_t
//@ 		mov	FLen, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1071
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	FLE160,	ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1073
//@ 		mov	dx, word ptr CellV+2 ; int32_t
//@ 		mov	ax, word ptr CellV ; int32_t
//@ 		mov	bx, n$0		; int16_t
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 1074
//@ 		mov	TMy, ax		; uint16_t
//@ 		sub	TMy, 10h	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1075
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	bx, FloorDiv	; uint16_t
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 1076
//@ 		mov	DNp, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1077
//@ 		mov	ax, DNp		; uint16_t
//@ 		mov	bx, ica2	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ 		mov	ah, dl
//@ 		mov	DNpx, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1078
//@ 		mov	ax, DNp		; uint16_t
//@ 		mov	bx, isa2	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ 		mov	ah, dl
//@ 		mov	DNpy, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1080
//@ 		mov	ax, DNp		; uint16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1081
//@ 		mov	DNp, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1083
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	AliasMask, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1097
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1098
//@ 		mov	cx, ehy		; int16_t
//@ ; #line	"CSRTLA.PAS" 1099
//@ 		shl	ecx, 8		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1100
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1101
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1102
//@ 		mov	ax, DNpy	; int16_t
//@ ; #line	"CSRTLA.PAS" 1103
//@ 		cwde			; AX ->	EAX (with sign)
//@ ; #line	"CSRTLA.PAS" 1104
//@ 		mov	ebx, eax
//@ ; #line	"CSRTLA.PAS" 1105
//@ 		mov	ax, FLE160	; int16_t
//@ ; #line	"CSRTLA.PAS" 1106
//@ 		cwde			; AX ->	EAX (with sign)
//@ ; #line	"CSRTLA.PAS" 1108
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1109
//@ 		sub	ecx, eax	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1111
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1112
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1113
//@ 		mov	ax, ica4	; int16_t
//@ ; #line	"CSRTLA.PAS" 1114
//@ 		cwde			; AX ->	EAX (with sign)
//@ ; #line	"CSRTLA.PAS" 1115
//@ 		mov	bx, TMy		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1116
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1117
//@ 		sub	ecx, eax	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1119
//@ 		mov	eax, ecx
//@ ; #line	"CSRTLA.PAS" 1120
//@ 		mov	Cpy, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1121
//@ 		shr	eax, 10h	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1122
//@ 		mov	FMy, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1129
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1130
//@ 		mov	cx, ehx		; int16_t
//@ ; #line	"CSRTLA.PAS" 1131
//@ 		shl	ecx, 8		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1133
//@ 		mov	ax, DNpx	; int16_t
//@ ; #line	"CSRTLA.PAS" 1134
//@ 		mov	bx, FLE160	; int16_t
//@ ; #line	"CSRTLA.PAS" 1135
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1136
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1137
//@ 		mov	dx, ax
//@ ; #line	"CSRTLA.PAS" 1138
//@ 		add	ecx, edx	; Add
//@ ; #line	"CSRTLA.PAS" 1140
//@ 		mov	ax, isa4	; int16_t
//@ ; #line	"CSRTLA.PAS" 1141
//@ 		mov	bx, TMy		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1142
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1143
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1144
//@ 		mov	dx, ax
//@ ; #line	"CSRTLA.PAS" 1145
//@ 		sub	ecx, edx	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1147
//@ 		mov	eax, ecx
//@ ; #line	"CSRTLA.PAS" 1148
//@ 		mov	Cpx, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1149
//@ 		shr	eax, 10h	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1150
//@ 		mov	FMx, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1152
//@ 		mov	ax, FMx		; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1153
//@ 		add	ax, FMy		; uint16_t
//@ 		add	ax, 5EC6h	; Add
//@ ; #line	"CSRTLA.PAS" 1154
//@ 		mov	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1156
//@ 		mov	ax, FMy		; uint16_t
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1157
//@ 		mov	si, FMx		; uint16_t
//@ 		shl	si, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1158
//@ 		add	ax, si		; Add
//@ 		mov	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1160
//@ 		mov	di, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1161
//@ 		mov	bl, [di]
//@ 		mov	CFlr, bl	; uint8_t
//@ ; #line	"CSRTLA.PAS" 1162
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1163
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1164
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1167
//@ 		mov	dx, 0
//@ 		mov	ax, BlevelC	; uint16_t
//@ 		mov	bx, n$0		; int16_t
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 1168
//@ 		cmp	al, 10h		; Compare Two Operands
//@ 		jb	short loc_2EE4	; Jump if Below	(CF=1)
//@ 		mov	al, 10h
//@ ; #line	"CSRTLA.PAS" 1169
//@ 
//@ loc_2EE4:				; CODE XREF: CellVHi+1F8j
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 1AC6h	; Add
//@ ; #line	"CSRTLA.PAS" 1170
//@ 		mov	CMP0, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1172
//@ 		cmp	DNp, 100h	; uint16_t
//@ 		ja	short loc_2EFA	; Jump if Above	(CF=0 &	ZF=0)
//@ 		call	Draw_Cell1	; function near	PASCAL returns void
//@ 		jmp	short loc_2F0A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1173
//@ 
//@ loc_2EFA:				; CODE XREF: CellVHi+20Bj
//@ 		cmp	DNp, 200h	; uint16_t
//@ 		ja	short loc_2F07	; Jump if Above	(CF=0 &	ZF=0)
//@ 		call	Draw_Cell2	; function near	PASCAL returns void
//@ 		jmp	short loc_2F0A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1174
//@ 
//@ loc_2F07:				; CODE XREF: CellVHi+218j
//@ 		call	Draw_Cell3	; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 1177
//@ 
//@ loc_2F0A:				; CODE XREF: CellVHi+210j CellVHi+21Dj
//@ 		mov	eax, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 1178
//@ 		add	FCSAddr, eax	; int32_t
//@ ; #line	"CSRTLA.PAS" 1180
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jz	short locret_2F1E ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2D3D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1181
//@ 
//@ locret_2F1E:				; CODE XREF: CellVHi+4Dj CellVHi+231j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CellVHi		endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1193
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ Draw_Floor1	proc near		; CODE XREF: FloorVHi+227p
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1194
//@ 		mov	ax, DNpx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:2FC2h, ax
//@ 		mov	es:3023h, ax
//@ ; #line	"CSRTLA.PAS" 1195
//@ 		mov	ax, DNpy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:2FC8h, ax
//@ 		mov	es:3029h, ax
//@ ; #line	"CSRTLA.PAS" 1196
//@ 		mov	al, Xi		; uint8_t
//@ 		mov	es:2FC1h, al
//@ 		mov	es:3022h, al
//@ ; #line	"CSRTLA.PAS" 1197
//@ 		mov	al, Yi		; uint8_t
//@ 		mov	es:2FC7h, al
//@ 		mov	es:3028h, al
//@ ; #line	"CSRTLA.PAS" 1198
//@ 		mov	ax, CMP0	; uint16_t
//@ 		mov	es:2FB4h, ax
//@ ; #line	"CSRTLA.PAS" 1199
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1201
//@ 		mov	cx, FLen	; uint16_t
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1203
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, FLeftEnd	; int16_t
//@ ; #line	"CSRTLA.PAS" 1204
//@ 		mov	edi, FCSAddr	; int32_t
//@ ; #line	"CSRTLA.PAS" 1205
//@ 		add	edi, eax	; Add
//@ ; #line	"CSRTLA.PAS" 1206
//@ 		mov	dx, Cpx		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1207
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 1208
//@ 		mov	ax, Cpy		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1209
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 1211
//@ 		mov	al, 1
//@ 		cmp	CFlr, 3Fh ; '?' ; uint8_t
//@ 		jnz	short loc_2F90	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_301F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1214
//@ 
//@ loc_2F90:				; CODE XREF: Draw_Floor1+6Bj
//@ 					; Draw_Floor1+ADj
//@ 		mov	si, bp
//@ ; #line	"CSRTLA.PAS" 1215
//@ 		mov	ax, dx
//@ ; #line	"CSRTLA.PAS" 1216
//@ 		shr	si, 0Ah		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1217
//@ 		shr	ax, 0Ah		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1218
//@ 		mov	bx, si
//@ ; #line	"CSRTLA.PAS" 1219
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1220
//@ 		shl	bx, 4		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1221
//@ 		add	si, ax		; Add
//@ ; #line	"CSRTLA.PAS" 1222
//@ 		shr	al, 4		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1223
//@ 		mov	bl, al
//@ ; #line	"CSRTLA.PAS" 1224
//@ 		add	bx, CurShOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1226
//@ 		mov	bh, gs:[bx]
//@ ; #line	"CSRTLA.PAS" 1227
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1228
//@ 		add	bx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1230
//@ 		mov	al, fs:[si]
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 1231
//@ 		mov	es:[edi], al
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1233
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1234
//@ 		jb	short loc_2FD1	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1235
//@ 
//@ loc_2FC6:				; CODE XREF: Draw_Floor1+D6j
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1236
//@ 		jb	short loc_2FF8	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1237
//@ 
//@ loc_2FCC:				; CODE XREF: Draw_Floor1+FDj
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2F90	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1238
//@ 		jmp	short loc_3030	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1242
//@ 
//@ loc_2FD1:				; CODE XREF: Draw_Floor1+A4j
//@ 					; Draw_Floor1+105j
//@ 		mov	ax, FMapDx	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1244
//@ 		mov	ax, FShwDx	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1245
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1246
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1247
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		mov	al, 1
//@ 		jz	short loc_3027	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1248
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1249
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1250
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1251
//@ 		jmp	short loc_2FC6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1253
//@ 
//@ loc_2FF8:				; CODE XREF: Draw_Floor1+AAj
//@ 					; Draw_Floor1+10Bj
//@ 		mov	ax, FMapDy	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1255
//@ 		mov	ax, FShwDy	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1256
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1257
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1258
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		mov	al, 1
//@ 		jz	short loc_302D	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1259
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1260
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1261
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1262
//@ 		jmp	short loc_2FCC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1267
//@ 
//@ loc_301F:				; CODE XREF: Draw_Floor1+6Dj
//@ 					; Draw_Floor1+10Ej
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1268
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1269
//@ 		jb	short loc_2FD1	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1270
//@ 
//@ loc_3027:				; CODE XREF: Draw_Floor1+CAj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1271
//@ 		jb	short loc_2FF8	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1272
//@ 
//@ loc_302D:				; CODE XREF: Draw_Floor1+F1j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_301F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1275
//@ 
//@ loc_3030:				; CODE XREF: Draw_Floor1+AFj
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 1276
//@ 		retn			; Return Near from Procedure
//@ Draw_Floor1	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1282
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ Draw_Floor2	proc near		; CODE XREF: FloorVHi+234p
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1283
//@ 		mov	ax, DNpx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:30D6h, ax
//@ 		mov	es:3137h, ax
//@ ; #line	"CSRTLA.PAS" 1284
//@ 		mov	ax, DNpy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:30DCh, ax
//@ 		mov	es:313Dh, ax
//@ ; #line	"CSRTLA.PAS" 1285
//@ 		mov	al, Xi		; uint8_t
//@ 		mov	es:30D5h, al
//@ 		mov	es:3136h, al
//@ ; #line	"CSRTLA.PAS" 1286
//@ 		mov	al, Yi		; uint8_t
//@ 		mov	es:30DBh, al
//@ 		mov	es:313Ch, al
//@ ; #line	"CSRTLA.PAS" 1287
//@ 		mov	ax, CMP0	; uint16_t
//@ 		mov	es:30C6h, ax
//@ ; #line	"CSRTLA.PAS" 1288
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1290
//@ 		mov	cx, FLen	; uint16_t
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1292
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, FLeftEnd	; int16_t
//@ ; #line	"CSRTLA.PAS" 1293
//@ 		mov	edi, FCSAddr	; int32_t
//@ ; #line	"CSRTLA.PAS" 1294
//@ 		add	edi, eax	; Add
//@ ; #line	"CSRTLA.PAS" 1295
//@ 		mov	dx, Cpx		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1296
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 1297
//@ 		mov	ax, Cpy		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1298
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 1300
//@ 		mov	al, 1
//@ 		cmp	CFlr, 3Fh ; '?' ; uint8_t
//@ 		jnz	short loc_30A2	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_3133	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1303
//@ 
//@ loc_30A2:				; CODE XREF: Draw_Floor2+6Bj
//@ 					; Draw_Floor2+AFj
//@ 		mov	si, bp
//@ ; #line	"CSRTLA.PAS" 1304
//@ 		mov	ax, dx
//@ ; #line	"CSRTLA.PAS" 1305
//@ 		shr	si, 0Bh		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1306
//@ 		shr	ax, 0Bh		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1307
//@ 		mov	bx, si
//@ ; #line	"CSRTLA.PAS" 1308
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1309
//@ 		shl	bx, 5		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1310
//@ 		add	si, ax		; Add
//@ ; #line	"CSRTLA.PAS" 1311
//@ 		shr	al, 3		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1312
//@ 		mov	bl, al
//@ ; #line	"CSRTLA.PAS" 1313
//@ 		add	bx, CurShOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1315
//@ 		mov	bh, gs:[bx]
//@ ; #line	"CSRTLA.PAS" 1316
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1317
//@ 		add	bx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1319
//@ 		mov	al, fs:[si+1000h]
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 1320
//@ 		mov	es:[edi], al
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1322
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1323
//@ 		jb	short loc_30E5	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1324
//@ 
//@ loc_30DA:				; CODE XREF: Draw_Floor2+D8j
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1325
//@ 		jb	short loc_310C	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1326
//@ 
//@ loc_30E0:				; CODE XREF: Draw_Floor2+FFj
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_30A2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1327
//@ 		jmp	short loc_3144	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1331
//@ 
//@ loc_30E5:				; CODE XREF: Draw_Floor2+A6j
//@ 					; Draw_Floor2+107j
//@ 		mov	ax, FMapDx	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1333
//@ 		mov	ax, FShwDx	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1334
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1335
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1336
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		mov	al, 1
//@ 		jz	short loc_313B	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1337
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1338
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1339
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1340
//@ 		jmp	short loc_30DA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1342
//@ 
//@ loc_310C:				; CODE XREF: Draw_Floor2+ACj
//@ 					; Draw_Floor2+10Dj
//@ 		mov	ax, FMapDy	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1344
//@ 		mov	ax, FShwDy	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1345
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1346
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1347
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		mov	al, 1
//@ 		jz	short loc_3141	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1348
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1349
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1350
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1351
//@ 		jmp	short loc_30E0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1356
//@ 
//@ loc_3133:				; CODE XREF: Draw_Floor2+6Dj
//@ 					; Draw_Floor2+110j
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1357
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1358
//@ 		jb	short loc_30E5	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1359
//@ 
//@ loc_313B:				; CODE XREF: Draw_Floor2+CCj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1360
//@ 		jb	short loc_310C	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1361
//@ 
//@ loc_3141:				; CODE XREF: Draw_Floor2+F3j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_3133	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1364
//@ 
//@ loc_3144:				; CODE XREF: Draw_Floor2+B1j
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 1365
//@ 		retn			; Return Near from Procedure
//@ Draw_Floor2	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1371
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ Draw_Floor3	proc near		; CODE XREF: FloorVHi:loc_3493p
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1372
//@ 		mov	ax, DNpx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:31EAh, ax
//@ 		mov	es:324Bh, ax
//@ ; #line	"CSRTLA.PAS" 1373
//@ 		mov	ax, DNpy	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	es:31F0h, ax
//@ 		mov	es:3251h, ax
//@ ; #line	"CSRTLA.PAS" 1374
//@ 		mov	al, Xi		; uint8_t
//@ 		mov	es:31E9h, al
//@ 		mov	es:324Ah, al
//@ ; #line	"CSRTLA.PAS" 1375
//@ 		mov	al, Yi		; uint8_t
//@ 		mov	es:31EFh, al
//@ 		mov	es:3250h, al
//@ ; #line	"CSRTLA.PAS" 1376
//@ 		mov	ax, CMP0	; uint16_t
//@ 		mov	es:31DAh, ax
//@ ; #line	"CSRTLA.PAS" 1377
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1379
//@ 		mov	cx, FLen	; uint16_t
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1381
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, FLeftEnd	; int16_t
//@ ; #line	"CSRTLA.PAS" 1382
//@ 		mov	edi, FCSAddr	; int32_t
//@ ; #line	"CSRTLA.PAS" 1383
//@ 		add	edi, eax	; Add
//@ ; #line	"CSRTLA.PAS" 1384
//@ 		mov	dx, Cpx		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1385
//@ 		push	bp
//@ ; #line	"CSRTLA.PAS" 1386
//@ 		mov	ax, Cpy		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1387
//@ 		mov	bp, ax
//@ ; #line	"CSRTLA.PAS" 1389
//@ 		mov	al, 1
//@ 		cmp	CFlr, 3Fh ; '?' ; uint8_t
//@ 		jnz	short loc_31B6	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_3247	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1392
//@ 
//@ loc_31B6:				; CODE XREF: Draw_Floor3+6Bj
//@ 					; Draw_Floor3+AFj
//@ 		mov	si, bp
//@ ; #line	"CSRTLA.PAS" 1393
//@ 		mov	ax, dx
//@ ; #line	"CSRTLA.PAS" 1394
//@ 		shr	si, 0Ch		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1395
//@ 		shr	ax, 0Ch		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1396
//@ 		mov	bx, si
//@ ; #line	"CSRTLA.PAS" 1397
//@ 		shl	si, 4		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1398
//@ 		shl	bx, 6		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1399
//@ 		add	si, ax		; Add
//@ ; #line	"CSRTLA.PAS" 1400
//@ 		shr	al, 2		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1401
//@ 		mov	bl, al
//@ ; #line	"CSRTLA.PAS" 1402
//@ 		add	bx, CurShOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1404
//@ 		mov	bh, gs:[bx]
//@ ; #line	"CSRTLA.PAS" 1405
//@ 		xor	bl, bl		; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1406
//@ 		add	bx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1408
//@ 		mov	al, fs:[si+1400h]
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSRTLA.PAS" 1409
//@ 		mov	es:[edi], al
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1411
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1412
//@ 		jb	short loc_31F9	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1413
//@ 
//@ loc_31EE:				; CODE XREF: Draw_Floor3+D8j
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1414
//@ 		jb	short loc_3220	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1415
//@ 
//@ loc_31F4:				; CODE XREF: Draw_Floor3+FFj
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_31B6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1416
//@ 		jmp	short loc_3258	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1420
//@ 
//@ loc_31F9:				; CODE XREF: Draw_Floor3+A6j
//@ 					; Draw_Floor3+107j
//@ 		mov	ax, FMapDx	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1422
//@ 		mov	ax, FShwDx	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1423
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1424
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1425
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		mov	al, 1
//@ 		jz	short loc_324F	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1426
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1427
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1428
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1429
//@ 		jmp	short loc_31EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1431
//@ 
//@ loc_3220:				; CODE XREF: Draw_Floor3+ACj
//@ 					; Draw_Floor3+10Dj
//@ 		mov	ax, FMapDy	; int16_t
//@ 		add	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1433
//@ 		mov	ax, FShwDy	; int16_t
//@ 		add	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1434
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1435
//@ 		mov	bl, [si]
//@ ; #line	"CSRTLA.PAS" 1436
//@ 		cmp	bl, 3Fh	; '?'   ; Compare Two Operands
//@ 		mov	al, 1
//@ 		jz	short loc_3255	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1437
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bl, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1438
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1439
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1440
//@ 		jmp	short loc_31F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1445
//@ 
//@ loc_3247:				; CODE XREF: Draw_Floor3+6Dj
//@ 					; Draw_Floor3+110j
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1446
//@ 		add	dx, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1447
//@ 		jb	short loc_31F9	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1448
//@ 
//@ loc_324F:				; CODE XREF: Draw_Floor3+CCj
//@ 		add	bp, 0FFFFh	; Add
//@ ; #line	"CSRTLA.PAS" 1449
//@ 		jb	short loc_3220	; Jump if Below	(CF=1)
//@ ; #line	"CSRTLA.PAS" 1450
//@ 
//@ loc_3255:				; CODE XREF: Draw_Floor3+F3j
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_3247	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1453
//@ 
//@ loc_3258:				; CODE XREF: Draw_Floor3+B1j
//@ 		pop	bp
//@ ; #line	"CSRTLA.PAS" 1454
//@ 		retn			; Return Near from Procedure
//@ Draw_Floor3	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1460
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FloorVHi	proc near		; CODE XREF: BuildFloorCell+8Ap
//@ 
//@ var_2		= word ptr -2
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 1461
//@ 		mov	ax, WinCY	; uint16_t
//@ 		add	ax, WinH2d	; uint16_t
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di-6E84h]
//@ 		mov	dx, [di-6E82h]
//@ 		mov	word ptr FCSAddr, ax ; int32_t
//@ 		mov	word ptr FCSAddr+2, dx ; int32_t
//@ ; #line	"CSRTLA.PAS" 1463
//@ 		mov	ax, WinSX	; uint16_t
//@ 		mov	FLeftEnd, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1464
//@ 		mov	ax, WinEX	; uint16_t
//@ 		mov	FRightEnd, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1465
//@ 		cmp	ica, 0		; int16_t
//@ 		jge	short loc_3293	; Jump if Greater or Equal (SF=OF)
//@ 		mov	Xi, 0C2h ; 'Â'  ; uint8_t
//@ 		jmp	short loc_3298	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3293:				; CODE XREF: FloorVHi+30j
//@ 		mov	Xi, 0EAh ; 'ê'  ; uint8_t
//@ ; #line	"CSRTLA.PAS" 1466
//@ 
//@ loc_3298:				; CODE XREF: FloorVHi+37j
//@ 		cmp	isa, 0		; int16_t
//@ 		jle	short loc_32A6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	Yi, 0C5h ; 'Å'  ; uint8_t
//@ 		jmp	short loc_32AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32A6:				; CODE XREF: FloorVHi+43j
//@ 		mov	Yi, 0EDh ; 'í'  ; uint8_t
//@ ; #line	"CSRTLA.PAS" 1468
//@ 
//@ loc_32AB:				; CODE XREF: FloorVHi+4Aj
//@ 		mov	ax, YMin2	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, WinH2d	; uint16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jge	short loc_32BD	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_34A1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32BD:				; CODE XREF: FloorVHi+5Ej
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_32C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32C2:				; CODE XREF: FloorVHi+244j
//@ 		dec	n$0		; int16_t
//@ ; #line	"CSRTLA.PAS" 1470
//@ 
//@ loc_32C6:				; CODE XREF: FloorVHi+66j FloorVHi+9Dj
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7734h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_32E9	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_32F9	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_32F9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_32E9:				; CODE XREF: FloorVHi+87j
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, FLeftEnd	; int16_t
//@ 		jle	short loc_32F9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		inc	FLeftEnd	; int16_t
//@ 		jmp	short loc_32C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1471
//@ 
//@ loc_32F9:				; CODE XREF: FloorVHi+89j FloorVHi+8Dj ...
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7734h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_331C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_332C	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_332C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_331C:				; CODE XREF: FloorVHi+BAj
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, FRightEnd	; int16_t
//@ 		jge	short loc_332C	; Jump if Greater or Equal (SF=OF)
//@ 		dec	FRightEnd	; int16_t
//@ 		jmp	short loc_32F9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1472
//@ 
//@ loc_332C:				; CODE XREF: FloorVHi+BCj FloorVHi+C0j ...
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		sub	ax, FLeftEnd	; int16_t
//@ 		mov	FLen, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1473
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	FLE160,	ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1475
//@ 		mov	dx, word ptr FloorV+2 ;	int32_t
//@ 		mov	ax, word ptr FloorV ; int32_t
//@ 		mov	bx, n$0		; int16_t
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 1476
//@ 		mov	TMy, ax		; uint16_t
//@ 		sub	TMy, 10h	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1477
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	bx, FloorDiv	; uint16_t
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 1478
//@ 		mov	DNp, ax		; uint16_t
//@ 		mov	cx, 100h
//@ ; #line	"CSRTLA.PAS" 1479
//@ 		mov	ax, DNp		; uint16_t
//@ 		mov	bx, ica2	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ 		mov	ah, dl
//@ 		mov	DNpx, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1480
//@ 		mov	ax, DNp		; uint16_t
//@ 		mov	bx, isa2	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ 		mov	ah, dl
//@ 		mov	DNpy, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1482
//@ 		mov	ax, DNp		; uint16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1483
//@ 		mov	DNp, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1489
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1490
//@ 		mov	cx, ehy		; int16_t
//@ ; #line	"CSRTLA.PAS" 1491
//@ 		shl	ecx, 8		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1493
//@ 		mov	ax, DNpy	; int16_t
//@ ; #line	"CSRTLA.PAS" 1494
//@ 		mov	bx, FLE160	; int16_t
//@ ; #line	"CSRTLA.PAS" 1495
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1496
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1497
//@ 		mov	dx, ax
//@ ; #line	"CSRTLA.PAS" 1498
//@ 		sub	ecx, edx	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1500
//@ 		mov	ax, ica4	; int16_t
//@ ; #line	"CSRTLA.PAS" 1501
//@ 		mov	bx, TMy		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1502
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1503
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1504
//@ 		mov	dx, ax
//@ ; #line	"CSRTLA.PAS" 1505
//@ 		sub	ecx, edx	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1507
//@ 		mov	eax, ecx
//@ ; #line	"CSRTLA.PAS" 1508
//@ 		mov	Cpy, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1509
//@ 		shr	eax, 10h	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1510
//@ 		mov	FMy, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1516
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1517
//@ 		mov	cx, ehx		; int16_t
//@ ; #line	"CSRTLA.PAS" 1518
//@ 		shl	ecx, 8		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1519
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1520
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1521
//@ 		mov	ax, DNpx	; int16_t
//@ ; #line	"CSRTLA.PAS" 1522
//@ 		cwde			; AX ->	EAX (with sign)
//@ ; #line	"CSRTLA.PAS" 1523
//@ 		mov	ebx, eax
//@ ; #line	"CSRTLA.PAS" 1524
//@ 		mov	ax, FLE160	; int16_t
//@ ; #line	"CSRTLA.PAS" 1525
//@ 		cwde			; AX ->	EAX (with sign)
//@ ; #line	"CSRTLA.PAS" 1527
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1528
//@ 		add	ecx, eax	; Add
//@ ; #line	"CSRTLA.PAS" 1531
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1532
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ ; #line	"CSRTLA.PAS" 1533
//@ 		mov	ax, isa4	; int16_t
//@ ; #line	"CSRTLA.PAS" 1534
//@ 		cwde			; AX ->	EAX (with sign)
//@ ; #line	"CSRTLA.PAS" 1535
//@ 		mov	bx, TMy		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1536
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSRTLA.PAS" 1537
//@ 		sub	ecx, eax	; Integer Subtraction
//@ ; #line	"CSRTLA.PAS" 1539
//@ 		mov	eax, ecx
//@ ; #line	"CSRTLA.PAS" 1540
//@ 		mov	Cpx, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1541
//@ 		shr	eax, 10h	; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1542
//@ 		mov	FMx, ax		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1544
//@ 		mov	ax, FMx		; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1545
//@ 		add	ax, FMy		; uint16_t
//@ 		add	ax, 4EC6h	; Add
//@ ; #line	"CSRTLA.PAS" 1546
//@ 		mov	FCurMapOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1548
//@ 		mov	ax, FMy		; uint16_t
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1549
//@ 		mov	si, FMx		; uint16_t
//@ 		shl	si, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1550
//@ 		add	ax, si		; Add
//@ 		mov	CurShOfs, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1552
//@ 		mov	si, FCurMapOfs	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1553
//@ 		mov	bl, [si]
//@ 		mov	CFlr, bl	; uint8_t
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1554
//@ 		mov	ax, [bx+1890h]
//@ ; #line	"CSRTLA.PAS" 1555
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1557
//@ 		mov	eax, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 1558
//@ 		sub	FCSAddr, eax	; int32_t
//@ ; #line	"CSRTLA.PAS" 1559
//@ 		mov	dx, 0
//@ 		mov	ax, BLevelF	; uint16_t
//@ 		mov	bx, n$0		; int16_t
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"CSRTLA.PAS" 1560
//@ 		cmp	al, 10h		; Compare Two Operands
//@ 		jb	short loc_3470	; Jump if Below	(CF=1)
//@ 		mov	al, 10h
//@ ; #line	"CSRTLA.PAS" 1561
//@ 
//@ loc_3470:				; CODE XREF: FloorVHi+212j
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 1AC6h	; Add
//@ ; #line	"CSRTLA.PAS" 1562
//@ 		mov	CMP0, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1564
//@ 		cmp	DNp, 100h	; uint16_t
//@ 		ja	short loc_3486	; Jump if Above	(CF=0 &	ZF=0)
//@ 		call	Draw_Floor1	; function near	PASCAL returns void
//@ 		jmp	short loc_3496	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1565
//@ 
//@ loc_3486:				; CODE XREF: FloorVHi+225j
//@ 		cmp	DNp, 200h	; uint16_t
//@ 		ja	short loc_3493	; Jump if Above	(CF=0 &	ZF=0)
//@ 		call	Draw_Floor2	; function near	PASCAL returns void
//@ 		jmp	short loc_3496	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1566
//@ 
//@ loc_3493:				; CODE XREF: FloorVHi+232j
//@ 		call	Draw_Floor3	; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 1569
//@ 
//@ loc_3496:				; CODE XREF: FloorVHi+22Aj
//@ 					; FloorVHi+237j
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jz	short locret_34A1 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_32C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1570
//@ 
//@ locret_34A1:				; CODE XREF: FloorVHi+60j
//@ 					; FloorVHi+242j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ FloorVHi	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1600
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MovEX		proc near		; CODE XREF: BuildSky+16Cp
//@ 
//@ CNT		= dword	ptr  4		; int32_t
//@ ofsb		= dword	ptr  8		; int32_t
//@ segb		= word ptr  0Ch		; uint16_t
//@ ofsa		= dword	ptr  0Eh	; int32_t
//@ sega		= word ptr  12h		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSRTLA.PAS" 1601
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSRTLA.PAS" 1602
//@ 		mov	dx, ds
//@ ; #line	"CSRTLA.PAS" 1603
//@ 		mov	ds, [bp+sega]	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1604
//@ 		mov	esi, [bp+ofsa]	; int32_t
//@ ; #line	"CSRTLA.PAS" 1605
//@ 		mov	ax, [bp+segb]	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1606
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1607
//@ 		mov	edi, [bp+ofsb]	; int32_t
//@ ; #line	"CSRTLA.PAS" 1608
//@ 		mov	ecx, [bp+CNT]	; int32_t
//@ ; #line	"CSRTLA.PAS" 1609
//@ 		shr	ecx, 2		; Shift	Logical	Right
//@ ; #line	"CSRTLA.PAS" 1610
//@ 		jz	short loc_34C7	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1611
//@ 		rep movs dword ptr es:[edi], dword ptr [esi] ; Move Byte(s) from String	to String
//@ ; #line	"CSRTLA.PAS" 1613
//@ 
//@ loc_34C7:				; CODE XREF: MovEX+1Ej
//@ 		mov	ecx, [bp+CNT]	; int32_t
//@ ; #line	"CSRTLA.PAS" 1614
//@ 		and	ecx, 3		; Logical AND
//@ ; #line	"CSRTLA.PAS" 1615
//@ 		jz	short loc_34D7	; Jump if Zero (ZF=1)
//@ ; #line	"CSRTLA.PAS" 1616
//@ 		rep movs byte ptr es:[edi], byte ptr [esi] ; Move Byte(s) from String to String
//@ ; #line	"CSRTLA.PAS" 1617
//@ 
//@ loc_34D7:				; CODE XREF: MovEX+2Fj
//@ 		mov	ds, dx
//@ ; #line	"CSRTLA.PAS" 1618
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ MovEX		endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1625
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BuildSky	proc near		; CODE XREF: BuildFloorCell+63p
//@ 
//@ var_C		= word ptr -0Ch
//@ cnt		= word ptr -0Ah		; uint16_t
//@ _SkyX		= word ptr -6		; uint16_t
//@ ScrOfs		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 1626
//@ 		mov	ax, YMin1	; uint16_t
//@ 		cmp	ax, WinH2u	; uint16_t
//@ 		jnb	short loc_34F1	; Jump if Not Below (CF=0)
//@ 		cmp	SkyVisible, 0	; bool
//@ 		jnz	short loc_34F4	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_34F1:				; CODE XREF: BuildSky+Bj
//@ 		jmp	locret_369D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1627
//@ 
//@ loc_34F4:				; CODE XREF: BuildSky+12j
//@ 		mov	SkyVisible, 0	; bool
//@ ; #line	"CSRTLA.PAS" 1628
//@ 		cmp	word ptr VideoW+2, 0 ; int32_t
//@ 		jl	short loc_350A	; Jump if Less (SF!=OF)
//@ 		jg	short loc_3511	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	word ptr VideoW, 190h ;	int32_t
//@ 		jnb	short loc_3511	; Jump if Not Below (CF=0)
//@ 
//@ loc_350A:				; CODE XREF: BuildSky+21j
//@ 		mov	[bp+cnt], 6	; uint16_t
//@ 		jmp	short loc_3516	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3511:				; CODE XREF: BuildSky+23j BuildSky+2Bj
//@ 		mov	[bp+cnt], 5	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1629
//@ 
//@ loc_3516:				; CODE XREF: BuildSky+32j
//@ 		mov	ax, EHFi	; uint16_t
//@ 		mov	cx, [bp+cnt]	; uint16_t
//@ 		shr	ax, cl		; Shift	Logical	Right
//@ 		and	ax, 0FFh	; Logical AND
//@ 		add	ax, 400h	; Add
//@ 		mov	SkyX, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1630
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr FCSAddr, ax ; int32_t
//@ 		mov	word ptr FCSAddr+2, ax ; int32_t
//@ ; #line	"CSRTLA.PAS" 1631
//@ 		mov	ax, 320h
//@ 		sub	ax, WinCY	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0C8h ; 'È'
//@ 		div	cx		; Unsigned Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		mov	SkyY, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1632
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	FLeftEnd, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1633
//@ 		mov	ax, WinEX	; uint16_t
//@ 		mov	FRightEnd, ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1634
//@ 		mov	ax, YMin1	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_C], ax
//@ 		mov	ax, WinH2u	; uint16_t
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		jge	short loc_355E	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_369D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_355E:				; CODE XREF: BuildSky+7Cj
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_3567	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3563:				; CODE XREF: BuildSky+1BDj
//@ 		dec	n$0		; int16_t
//@ ; #line	"CSRTLA.PAS" 1636
//@ 
//@ loc_3567:				; CODE XREF: BuildSky+84j BuildSky+BBj
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_358A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_359A	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_359A	; Jump if Below	(CF=1)
//@ 
//@ loc_358A:				; CODE XREF: BuildSky+A5j
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, FLeftEnd	; int16_t
//@ 		jle	short loc_359A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		inc	FLeftEnd	; int16_t
//@ 		jmp	short loc_3567	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1637
//@ 
//@ loc_359A:				; CODE XREF: BuildSky+A7j BuildSky+ABj ...
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7DD2h]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_35BD	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_35CD	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_35CD	; Jump if Below	(CF=1)
//@ 
//@ loc_35BD:				; CODE XREF: BuildSky+D8j
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, FRightEnd	; int16_t
//@ 		jge	short loc_35CD	; Jump if Greater or Equal (SF=OF)
//@ 		dec	FRightEnd	; int16_t
//@ 		jmp	short loc_359A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1638
//@ 
//@ loc_35CD:				; CODE XREF: BuildSky+DAj BuildSky+DEj ...
//@ 		mov	ax, FRightEnd	; int16_t
//@ 		sub	ax, FLeftEnd	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	FLen, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1639
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, SkyX	; uint16_t
//@ 		sub	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		and	ax, 0FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	[bp+_SkyX], ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1640
//@ 		mov	ax, FLeftEnd	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, word ptr FCSAddr ; int32_t
//@ 		adc	dx, word ptr FCSAddr+2 ; int32_t
//@ 		mov	[bp+ScrOfs], ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSRTLA.PAS" 1642
//@ 
//@ loc_3609:				; CODE XREF: BuildSky+192j
//@ 		mov	ax, [bp+_SkyX]	; uint16_t
//@ 		add	ax, FLen	; uint16_t
//@ 		cmp	ax, 0FFh	; Compare Two Operands
//@ 		ja	short loc_361D	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, FLen	; uint16_t
//@ 		mov	[bp+cnt], ax	; uint16_t
//@ 		jmp	short loc_3626	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_361D:				; CODE XREF: BuildSky+136j
//@ 		mov	ax, 100h
//@ 		sub	ax, [bp+_SkyX]	; uint16_t
//@ 		mov	[bp+cnt], ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1643
//@ 
//@ loc_3626:				; CODE XREF: BuildSky+13Ej
//@ 		les	di, SkyPtr	; void*
//@ 		push	es
//@ 		mov	ax, SkyY	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, [bp+_SkyX]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		push	[bp+var_2]
//@ 		push	[bp+ScrOfs]	; int32_t
//@ 		mov	ax, [bp+cnt]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovEX		; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 1645
//@ 		mov	ax, [bp+cnt]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	[bp+ScrOfs], ax	; int32_t
//@ 		adc	[bp+var_2], dx	; Add with Carry
//@ ; #line	"CSRTLA.PAS" 1646
//@ 		mov	ax, [bp+_SkyX]	; uint16_t
//@ 		add	ax, [bp+cnt]	; uint16_t
//@ 		and	ax, 0FFh	; Logical AND
//@ 		mov	[bp+_SkyX], ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1647
//@ 		mov	ax, [bp+cnt]	; uint16_t
//@ 		sub	FLen, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1648
//@ 		cmp	FLen, 0		; uint16_t
//@ 		jnz	short loc_3609	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1649
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		add	word ptr FCSAddr, ax ; int32_t
//@ 		adc	word ptr FCSAddr+2, dx ; int32_t
//@ ; #line	"CSRTLA.PAS" 1650
//@ 		inc	SkyY		; uint16_t
//@ 		mov	ax, SkyY	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 0C8h ; 'È'
//@ 		div	cx		; Unsigned Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		mov	SkyY, ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1651
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		jz	short locret_369D ; Jump if Zero (ZF=1)
//@ 		jmp	loc_3563	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1652
//@ 
//@ locret_369D:				; CODE XREF: BuildSky:loc_34F1j
//@ 					; BuildSky+7Ej	...
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ BuildSky	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1658
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BuildFloorCell	proc near		; CODE XREF: Build3dScene+1F5p
//@ 					; DoGame+BC5p
//@ 
//@ sk		= byte ptr -1		; bool
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 1660
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1661
//@ 		mov	gs, ax
//@ ; #line	"CSRTLA.PAS" 1664
//@ 		cmp	ica, 0		; int16_t
//@ 		jle	short loc_36B7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	FMapDx,	0FFC0h	; int16_t
//@ 		jmp	short loc_36BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_36B7:				; CODE XREF: BuildFloorCell+Ej
//@ 		mov	FMapDx,	40h ; '@' ; int16_t
//@ ; #line	"CSRTLA.PAS" 1665
//@ 
//@ loc_36BD:				; CODE XREF: BuildFloorCell+16j
//@ 		cmp	isa, 0		; int16_t
//@ 		jle	short loc_36CC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	FMapDy,	1	; int16_t
//@ 		jmp	short loc_36D2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_36CC:				; CODE XREF: BuildFloorCell+23j
//@ 		mov	FMapDy,	0FFFFh	; int16_t
//@ ; #line	"CSRTLA.PAS" 1666
//@ 
//@ loc_36D2:				; CODE XREF: BuildFloorCell+2Bj
//@ 		cmp	ica, 0		; int16_t
//@ 		jle	short loc_36E1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	FShwDx,	0FFFCh	; int16_t
//@ 		jmp	short loc_36E7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_36E1:				; CODE XREF: BuildFloorCell+38j
//@ 		mov	FShwDx,	4	; int16_t
//@ ; #line	"CSRTLA.PAS" 1667
//@ 
//@ loc_36E7:				; CODE XREF: BuildFloorCell+40j
//@ 		cmp	isa, 0		; int16_t
//@ 		jle	short loc_36F6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	FShwDy,	400h	; int16_t
//@ 		jmp	short loc_36FC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_36F6:				; CODE XREF: BuildFloorCell+4Dj
//@ 		mov	FShwDy,	0FC00h	; int16_t
//@ ; #line	"CSRTLA.PAS" 1670
//@ 
//@ loc_36FC:				; CODE XREF: BuildFloorCell+55j
//@ 					; BuildFloorCell+7Fj
//@ 		mov	al, SkyVisible	; bool
//@ 		mov	[bp+sk], al	; bool
//@ ; #line	"CSRTLA.PAS" 1671
//@ 		call	BuildSky	; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 1672
//@ 		mov	ax, YMin1	; uint16_t
//@ 		cmp	ax, WinH2u	; uint16_t
//@ 		jnb	short loc_3711	; Jump if Not Below (CF=0)
//@ ; #line	"CSRTLA.PAS" 1673
//@ 		call	CellVHi		; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 1674
//@ 
//@ loc_3711:				; CODE XREF: BuildFloorCell+6Dj
//@ 		cmp	SkyVisible, 0	; bool
//@ 		jz	short loc_3720	; Jump if Zero (ZF=1)
//@ 		cmp	[bp+sk], 0	; bool
//@ 		jnz	short loc_3720	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_36FC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1676
//@ 
//@ loc_3720:				; CODE XREF: BuildFloorCell+77j
//@ 					; BuildFloorCell+7Dj
//@ 		mov	ax, YMin2	; uint16_t
//@ 		cmp	ax, WinH2d	; uint16_t
//@ 		jnb	short loc_372C	; Jump if Not Below (CF=0)
//@ ; #line	"CSRTLA.PAS" 1677
//@ 		call	FloorVHi	; function near	PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 1681
//@ 
//@ loc_372C:				; CODE XREF: BuildFloorCell+88j
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1682
//@ 		mov	gs, ax
//@ ; #line	"CSRTLA.PAS" 1684
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ BuildFloorCell	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1904
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawCross	proc near		; CODE XREF: EndPaint+2F7p
//@ 
//@ cb		= byte ptr -5		; uint8_t
//@ wc		= word ptr -4		; uint16_t
//@ dy		= word ptr  4		; uint16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 1905
//@ 		cmp	Cocpit,	0	; bool
//@ 		jz	short loc_3745	; Jump if Zero (ZF=1)
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_3748	; Jump if Zero (ZF=1)
//@ 
//@ loc_3745:				; CODE XREF: DrawCross+9j
//@ 		jmp	locret_383A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1906
//@ 
//@ loc_3748:				; CODE XREF: DrawCross+10j
//@ 		cmp	InfoPage, 0	; bool
//@ 		jz	short loc_375D	; Jump if Zero (ZF=1)
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		sub	ax, 0Ch		; Integer Subtraction
//@ 		add	ax, [bp+dy]	; uint16_t
//@ 		mov	[bp+wc], ax	; uint16_t
//@ 		jmp	short loc_3769	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1907
//@ 
//@ loc_375D:				; CODE XREF: DrawCross+1Aj
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		add	ax, [bp+dy]	; uint16_t
//@ 		mov	[bp+wc], ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1908
//@ 
//@ loc_3769:				; CODE XREF: DrawCross+28j
//@ 		cmp	CurVideoMode, 1	; uint16_t
//@ 		jnz	short loc_3776	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+cb], 0FAh ;	'ú' ; uint8_t
//@ 		jmp	short loc_377A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3776:				; CODE XREF: DrawCross+3Bj
//@ 		mov	[bp+cb], 0FBh ;	'û' ; uint8_t
//@ ; #line	"CSRTLA.PAS" 1911
//@ 
//@ loc_377A:				; CODE XREF: DrawCross+41j
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CSRTLA.PAS" 1912
//@ 		mov	ax, RGBSeg25	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSRTLA.PAS" 1914
//@ 		xor	esi, esi	; Logical Exclusive OR
//@ 		mov	si, VideoCX	; uint16_t
//@ 		sub	si, 4		; Integer Subtraction
//@ 		mov	bx, [bp+wc]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1915
//@ 		add	esi, [bx-6E84h]	; Add
//@ ; #line	"CSRTLA.PAS" 1916
//@ 		mov	cx, 4
//@ 		mov	bh, [bp+cb]	; uint8_t
//@ ; #line	"CSRTLA.PAS" 1918
//@ 
//@ loc_379F:				; CODE XREF: DrawCross+7Bj
//@ 		mov	bl, fs:[esi]
//@ ; #line	"CSRTLA.PAS" 1919
//@ 		mov	al, es:[bx]
//@ ; #line	"CSRTLA.PAS" 1920
//@ 		mov	fs:[esi], al
//@ ; #line	"CSRTLA.PAS" 1921
//@ 		dec	esi		; Decrement by 1
//@ ; #line	"CSRTLA.PAS" 1922
//@ 		dec	bh		; Decrement by 1
//@ 		loop	loc_379F	; Loop while CX	!= 0
//@ ; #line	"CSRTLA.PAS" 1925
//@ 		xor	esi, esi	; Logical Exclusive OR
//@ 		mov	si, VideoCX	; uint16_t
//@ 		add	si, 4		; Add
//@ 		mov	bx, [bp+wc]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1926
//@ 		add	esi, [bx-6E84h]	; Add
//@ ; #line	"CSRTLA.PAS" 1927
//@ 		mov	cx, 4
//@ 		mov	bh, [bp+cb]	; uint8_t
//@ ; #line	"CSRTLA.PAS" 1929
//@ 
//@ loc_37CB:				; CODE XREF: DrawCross+A7j
//@ 		mov	bl, fs:[esi]
//@ ; #line	"CSRTLA.PAS" 1930
//@ 		mov	al, es:[bx]
//@ ; #line	"CSRTLA.PAS" 1931
//@ 		mov	fs:[esi], al
//@ ; #line	"CSRTLA.PAS" 1932
//@ 		inc	esi		; Increment by 1
//@ ; #line	"CSRTLA.PAS" 1933
//@ 		dec	bh		; Decrement by 1
//@ 		loop	loc_37CB	; Loop while CX	!= 0
//@ ; #line	"CSRTLA.PAS" 1936
//@ 		xor	esi, esi	; Logical Exclusive OR
//@ 		mov	si, VideoCX	; uint16_t
//@ 		mov	bx, [bp+wc]	; uint16_t
//@ 		add	bx, 4		; Add
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1937
//@ 		add	esi, [bx-6E84h]	; Add
//@ ; #line	"CSRTLA.PAS" 1938
//@ 		mov	cx, 4
//@ 		mov	bh, [bp+cb]	; uint8_t
//@ ; #line	"CSRTLA.PAS" 1940
//@ 
//@ loc_37F7:				; CODE XREF: DrawCross+D6j
//@ 		mov	bl, fs:[esi]
//@ ; #line	"CSRTLA.PAS" 1941
//@ 		mov	al, es:[bx]
//@ ; #line	"CSRTLA.PAS" 1942
//@ 		mov	fs:[esi], al
//@ ; #line	"CSRTLA.PAS" 1943
//@ 		add	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 1944
//@ 		dec	bh		; Decrement by 1
//@ 		loop	loc_37F7	; Loop while CX	!= 0
//@ ; #line	"CSRTLA.PAS" 1947
//@ 		xor	esi, esi	; Logical Exclusive OR
//@ 		mov	si, VideoCX	; uint16_t
//@ 		mov	bx, [bp+wc]	; uint16_t
//@ 		sub	bx, 4		; Integer Subtraction
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSRTLA.PAS" 1948
//@ 		add	esi, [bx-6E84h]	; Add
//@ ; #line	"CSRTLA.PAS" 1949
//@ 		mov	cx, 4
//@ 		mov	bh, [bp+cb]	; uint8_t
//@ ; #line	"CSRTLA.PAS" 1951
//@ 
//@ loc_3826:				; CODE XREF: DrawCross+105j
//@ 		mov	bl, fs:[esi]
//@ ; #line	"CSRTLA.PAS" 1952
//@ 		mov	al, es:[bx]
//@ ; #line	"CSRTLA.PAS" 1953
//@ 		mov	fs:[esi], al
//@ ; #line	"CSRTLA.PAS" 1954
//@ 		sub	esi, VideoBPL	; int32_t
//@ ; #line	"CSRTLA.PAS" 1955
//@ 		dec	bh		; Decrement by 1
//@ 		loop	loc_3826	; Loop while CX	!= 0
//@ ; #line	"CSRTLA.PAS" 1957
//@ 
//@ locret_383A:				; CODE XREF: DrawCross:loc_3745j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ DrawCross	endp
//@ 
//@ ; #line	"CSRTLA.PAS" 1963
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowValue	proc near		; CODE XREF: EndPaint+38Dp
//@ 					; EndPaint+39Dp ...
//@ 
//@ c		= byte ptr -3		; uint8_t
//@ x		= word ptr -2		; uint16_t
//@ i		= word ptr  4		; int16_t
//@ w		= word ptr  6		; uint16_t
//@ v		= word ptr  8		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSRTLA.PAS" 1964
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_3851	; Jump if Zero (ZF=1)
//@ 		mov	dx, 0
//@ 		call	SwitchBank	; function far PASCAL returns void
//@ ; #line	"CSRTLA.PAS" 1965
//@ 
//@ loc_3851:				; CODE XREF: ShowValue+9j
//@ 		cmp	[bp+v],	0	; int16_t
//@ 		jge	short loc_385C	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+v],	ax	; int16_t
//@ ; #line	"CSRTLA.PAS" 1966
//@ 
//@ loc_385C:				; CODE XREF: ShowValue+17j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_3866	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3863:				; CODE XREF: ShowValue+85j
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSRTLA.PAS" 1968
//@ 
//@ loc_3866:				; CODE XREF: ShowValue+23j
//@ 		mov	ax, [bp+v]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_387D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_3883	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_3883	; Jump if Below	(CF=1)
//@ 
//@ loc_387D:				; CODE XREF: ShowValue+37j
//@ 		mov	[bp+c],	0	; uint8_t
//@ 		jmp	short loc_38AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1969
//@ 
//@ loc_3883:				; CODE XREF: ShowValue+39j
//@ 					; ShowValue+3Dj
//@ 		cmp	[bp+x],	5	; uint16_t
//@ 		jnb	short loc_388F	; Jump if Not Below (CF=0)
//@ 		mov	[bp+c],	6Ch ; 'l' ; uint8_t
//@ 		jmp	short loc_38AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1970
//@ 
//@ loc_388F:				; CODE XREF: ShowValue+49j
//@ 		cmp	[bp+x],	0Ah	; uint16_t
//@ 		jnb	short loc_389B	; Jump if Not Below (CF=0)
//@ 		mov	[bp+c],	32h ; '2' ; uint8_t
//@ 		jmp	short loc_38AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSRTLA.PAS" 1971
//@ 
//@ loc_389B:				; CODE XREF: ShowValue+55j
//@ 		cmp	[bp+x],	0Fh	; uint16_t
//@ 		jnb	short loc_38A7	; Jump if Not Below (CF=0)
//@ 		mov	[bp+c],	0A6h ; '¦' ; uint8_t
//@ 		jmp	short loc_38AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_38A7:				; CODE XREF: ShowValue+61j
//@ 		mov	[bp+c],	0AAh ; 'ª' ; uint8_t
//@ ; #line	"CSRTLA.PAS" 1972
//@ 
//@ loc_38AB:				; CODE XREF: ShowValue+43j
//@ 					; ShowValue+4Fj ...
//@ 		mov	dl, [bp+c]	; uint8_t
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+w]	; uint16_t
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSRTLA.PAS" 1973
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		sub	[bp+w],	ax	; uint16_t
//@ ; #line	"CSRTLA.PAS" 1974
//@ 		cmp	[bp+x],	1Fh	; uint16_t
//@ 		jnz	short loc_3863	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSRTLA.PAS" 1975
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ ShowValue	endp
//@ 
