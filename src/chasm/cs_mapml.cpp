
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

#include "cs_mapml.h"

//@ ; #line	"CS_MAPML.PAS" 11
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ movsD		proc far		; CODE XREF: Morph3d+78P
//@ 
//@ count		= word ptr  6		; uint16_t
//@ o2		= word ptr  8		; uint16_t
//@ s2		= word ptr  0Ah		; uint16_t
//@ o1		= word ptr  0Ch		; uint16_t
//@ s1		= word ptr  0Eh		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 12
//@ 		push	ds
//@ ; #line	"CS_MAPML.PAS" 13
//@ 		mov	ds, [bp+s1]	; uint16_t
//@ 		mov	si, [bp+o1]	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 14
//@ 		mov	ax, [bp+s2]	; uint16_t
//@ 		mov	es, ax
//@ 		mov	di, [bp+o2]	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 15
//@ 		mov	cx, [bp+count]	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 16
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CS_MAPML.PAS" 17
//@ 		rep movsd		; Move Byte(s) from String to String
//@ ; #line	"CS_MAPML.PAS" 18
//@ 		pop	ds
//@ ; #line	"CS_MAPML.PAS" 19
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ movsD		endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 26
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VLineT_Recolor	proc far
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 28
//@ 		mov	bx, x1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"CS_MAPML.PAS" 29
//@ 		cmp	ax, CurDH	; uint16_t
//@ 		jb	short loc_156A6	; Jump if Below	(CF=1)
//@ 		jmp	locret_1581C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 30
//@ 
//@ loc_156A6:				; CODE XREF: VLineT_Recolor+11j
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		cmp	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 31
//@ 		jge	short loc_156B2	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_15746	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 35
//@ 
//@ loc_156B2:				; CODE XREF: VLineT_Recolor+1Dj
//@ 		mov	di, word ptr Ya.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 36
//@ 		mov	ax, word ptr Yb.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		inc	ax		; Increment by 1
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 37
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_156CA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_1581C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 38
//@ 
//@ loc_156CA:				; CODE XREF: VLineT_Recolor+35j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Yb.DW+2, cx ; struct DWord
//@ 		jge	short loc_156D7	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_1581C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 40
//@ 
//@ loc_156D7:				; CODE XREF: VLineT_Recolor+42j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15700	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 42
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 43
//@ 		mov	ax, txb		; int16_t
//@ 		sub	ax, txa		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 44
//@ 		mov	ax, tyb		; int16_t
//@ 		sub	ax, tya		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 46
//@ 
//@ loc_15700:				; CODE XREF: VLineT_Recolor+4Ej
//@ 		mov	dx, txa		; int16_t
//@ ; #line	"CS_MAPML.PAS" 47
//@ 		mov	si, tya		; int16_t
//@ ; #line	"CS_MAPML.PAS" 50
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15726	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 51
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 52
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 53
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 54
//@ 		sub	lnH, bx		; uint16_t
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 56
//@ 
//@ loc_15726:				; CODE XREF: VLineT_Recolor+7Aj
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 57
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jg	short loc_15739	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_157D1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 58
//@ 
//@ loc_15739:				; CODE XREF: VLineT_Recolor+A4j
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jnz	short loc_15743	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1581C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 59
//@ 
//@ loc_15743:				; CODE XREF: VLineT_Recolor+AEj
//@ 		jmp	loc_157D1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 64
//@ 
//@ loc_15746:				; CODE XREF: VLineT_Recolor+1Fj
//@ 		mov	di, word ptr Yb.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 65
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		inc	ax		; Increment by 1
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 66
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_1575E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_1581C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 67
//@ 
//@ loc_1575E:				; CODE XREF: VLineT_Recolor+C9j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Ya.DW+2, cx ; struct DWord
//@ 		jge	short loc_1576B	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_1581C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 69
//@ 
//@ loc_1576B:				; CODE XREF: VLineT_Recolor+D6j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15794	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 70
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 71
//@ 		mov	ax, txa		; int16_t
//@ 		sub	ax, txb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 72
//@ 		mov	ax, tya		; int16_t
//@ 		sub	ax, tyb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 75
//@ 
//@ loc_15794:				; CODE XREF: VLineT_Recolor+E2j
//@ 		mov	dx, txb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 76
//@ 		mov	si, tyb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 79
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_157BA	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 80
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 81
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 82
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 83
//@ 		sub	lnH, bx		; uint16_t
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 86
//@ 
//@ loc_157BA:				; CODE XREF: VLineT_Recolor+10Ej
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 87
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_157D1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 88
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jz	short locret_1581C ; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 93
//@ 
//@ loc_157D1:				; CODE XREF: VLineT_Recolor+A6j
//@ 					; VLineT_Recolor:loc_15743j ...
//@ 		mov	bx, di
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 94
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 95
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CS_MAPML.PAS" 98
//@ 		mov	bx, Curdark	; int16_t
//@ ; #line	"CS_MAPML.PAS" 99
//@ 		push	bp
//@ ; #line	"CS_MAPML.PAS" 100
//@ 		mov	bp, si
//@ ; #line	"CS_MAPML.PAS" 101
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 103
//@ 
//@ loc_157EB:				; CODE XREF: VLineT_Recolor+189j
//@ 		mov	si, bp
//@ ; #line	"CS_MAPML.PAS" 104
//@ 		mov	al, dh
//@ ; #line	"CS_MAPML.PAS" 105
//@ 		shr	si, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 106
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 107
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 108
//@ 		add	si, CSprOfs	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 109
//@ 		mov	al, fs:[si]
//@ ; #line	"CS_MAPML.PAS" 110
//@ 		mov	bx, 1358h
//@ ; #line	"CS_MAPML.PAS" 111
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CS_MAPML.PAS" 112
//@ 		mov	bx, Curdark	; int16_t
//@ ; #line	"CS_MAPML.PAS" 113
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CS_MAPML.PAS" 114
//@ 		mov	gs:[edi], al
//@ ; #line	"CS_MAPML.PAS" 115
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CS_MAPML.PAS" 116
//@ 		add	bp, ctdy	; int16_t
//@ ; #line	"CS_MAPML.PAS" 117
//@ 		add	dx, ctdx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 118
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_157EB	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 119
//@ 		pop	bp
//@ ; #line	"CS_MAPML.PAS" 122
//@ 
//@ locret_1581C:				; CODE XREF: VLineT_Recolor+13j
//@ 					; VLineT_Recolor+37j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ VLineT_Recolor	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 127
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VLineTGlass_Recolor proc far
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 129
//@ 		mov	bx, x1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"CS_MAPML.PAS" 130
//@ 		cmp	ax, CurDH	; uint16_t
//@ 		jb	short loc_15834	; Jump if Below	(CF=1)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 131
//@ 
//@ loc_15834:				; CODE XREF: VLineTGlass_Recolor+11j
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		cmp	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 132
//@ 		jge	short loc_15840	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_158DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 136
//@ 
//@ loc_15840:				; CODE XREF: VLineTGlass_Recolor+1Dj
//@ 		mov	di, word ptr Ya.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 137
//@ 		mov	ax, word ptr Yb.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		jnz	short loc_1584E	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1584E:				; CODE XREF: VLineTGlass_Recolor+2Bj
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 138
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_1585C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 139
//@ 
//@ loc_1585C:				; CODE XREF: VLineTGlass_Recolor+39j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Yb.DW+2, cx ; struct DWord
//@ 		jge	short loc_15869	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 141
//@ 
//@ loc_15869:				; CODE XREF: VLineTGlass_Recolor+46j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15892	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 142
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 143
//@ 		mov	ax, txb		; int16_t
//@ 		sub	ax, txa		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 144
//@ 		mov	ax, tyb		; int16_t
//@ 		sub	ax, tya		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 146
//@ 
//@ loc_15892:				; CODE XREF: VLineTGlass_Recolor+52j
//@ 		mov	dx, txa		; int16_t
//@ ; #line	"CS_MAPML.PAS" 147
//@ 		mov	si, tya		; int16_t
//@ ; #line	"CS_MAPML.PAS" 150
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_158BD	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 151
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 152
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 153
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 154
//@ 		sub	lnH, bx		; uint16_t
//@ 		jnz	short loc_158BB	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_158BB:				; CODE XREF: VLineTGlass_Recolor+98j
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 156
//@ 
//@ loc_158BD:				; CODE XREF: VLineTGlass_Recolor+7Ej
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 157
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jg	short loc_158D0	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1596E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 158
//@ 
//@ loc_158D0:				; CODE XREF: VLineTGlass_Recolor+ADj
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jnz	short loc_158DA	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 159
//@ 
//@ loc_158DA:				; CODE XREF: VLineTGlass_Recolor+B7j
//@ 		jmp	loc_1596E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 164
//@ 
//@ loc_158DD:				; CODE XREF: VLineTGlass_Recolor+1Fj
//@ 		mov	di, word ptr Yb.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 165
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		jnz	short loc_158EB	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_158EB:				; CODE XREF: VLineTGlass_Recolor+C8j
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 166
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_158F9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 167
//@ 
//@ loc_158F9:				; CODE XREF: VLineTGlass_Recolor+D6j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Ya.DW+2, cx ; struct DWord
//@ 		jge	short loc_15906	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_159C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 169
//@ 
//@ loc_15906:				; CODE XREF: VLineTGlass_Recolor+E3j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_1592F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 170
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 171
//@ 		mov	ax, txa		; int16_t
//@ 		sub	ax, txb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 172
//@ 		mov	ax, tya		; int16_t
//@ 		sub	ax, tyb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 175
//@ 
//@ loc_1592F:				; CODE XREF: VLineTGlass_Recolor+EFj
//@ 		mov	dx, txb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 176
//@ 		mov	si, tyb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 180
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15957	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 181
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 182
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 183
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 184
//@ 		sub	lnH, bx		; uint16_t
//@ 		jz	short locret_159C1 ; Jump if Zero (ZF=1)
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 187
//@ 
//@ loc_15957:				; CODE XREF: VLineTGlass_Recolor+11Bj
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 188
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_1596E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 189
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jz	short locret_159C1 ; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 194
//@ 
//@ loc_1596E:				; CODE XREF: VLineTGlass_Recolor+AFj
//@ 					; VLineTGlass_Recolor:loc_158DAj ...
//@ 		mov	bx, di
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 195
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 196
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CS_MAPML.PAS" 199
//@ 		push	es
//@ 		push	bp
//@ ; #line	"CS_MAPML.PAS" 200
//@ 		mov	ax, RGBSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 201
//@ 		mov	bp, si
//@ ; #line	"CS_MAPML.PAS" 202
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 204
//@ 
//@ loc_1598A:				; CODE XREF: VLineTGlass_Recolor+19Ej
//@ 		mov	si, bp
//@ ; #line	"CS_MAPML.PAS" 205
//@ 		mov	al, dh
//@ ; #line	"CS_MAPML.PAS" 206
//@ 		shr	si, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 207
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 208
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 209
//@ 		add	si, CSprOfs	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 210
//@ 		mov	bx, 1358h
//@ ; #line	"CS_MAPML.PAS" 211
//@ 		mov	al, fs:[si]
//@ ; #line	"CS_MAPML.PAS" 212
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CS_MAPML.PAS" 213
//@ 		mov	bl, gs:[edi]
//@ ; #line	"CS_MAPML.PAS" 214
//@ 		mov	bh, al
//@ ; #line	"CS_MAPML.PAS" 215
//@ 		mov	al, es:[bx]
//@ ; #line	"CS_MAPML.PAS" 216
//@ 		mov	gs:[edi], al
//@ ; #line	"CS_MAPML.PAS" 217
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CS_MAPML.PAS" 218
//@ 		add	bp, ctdy	; int16_t
//@ ; #line	"CS_MAPML.PAS" 219
//@ 		add	dx, ctdx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 220
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_1598A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 221
//@ 		pop	bp
//@ 		pop	es
//@ 		nop			; No Operation
//@ ; #line	"CS_MAPML.PAS" 224
//@ 
//@ locret_159C1:				; CODE XREF: VLineTGlass_Recolor+13j
//@ 					; VLineTGlass_Recolor+2Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ VLineTGlass_Recolor endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 232
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VLineT		proc far
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 234
//@ 		mov	bx, x1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"CS_MAPML.PAS" 235
//@ 		cmp	ax, CurDH	; uint16_t
//@ 		jb	short loc_159D9	; Jump if Below	(CF=1)
//@ 		jmp	locret_15B4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 236
//@ 
//@ loc_159D9:				; CODE XREF: VLineT+11j
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		cmp	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 237
//@ 		jge	short loc_159E5	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_15A7E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 241
//@ 
//@ loc_159E5:				; CODE XREF: VLineT+1Dj
//@ 		mov	di, word ptr Ya.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 242
//@ 		mov	ax, word ptr Yb.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		inc	ax		; Increment by 1
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 243
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_159FD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_15B4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 244
//@ 
//@ loc_159FD:				; CODE XREF: VLineT+35j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Yb.DW+2, cx ; struct DWord
//@ 		jge	short loc_15A0A	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_15B4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 246
//@ 
//@ loc_15A0A:				; CODE XREF: VLineT+42j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15A33	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 247
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 248
//@ 		mov	ax, txb		; int16_t
//@ 		sub	ax, txa		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 249
//@ 		mov	ax, tyb		; int16_t
//@ 		sub	ax, tya		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 251
//@ 
//@ loc_15A33:				; CODE XREF: VLineT+4Ej
//@ 		mov	dx, txa		; int16_t
//@ ; #line	"CS_MAPML.PAS" 252
//@ 		mov	si, tya		; int16_t
//@ ; #line	"CS_MAPML.PAS" 255
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15A5E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 256
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 257
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 258
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 259
//@ 		sub	lnH, bx		; uint16_t
//@ 		jnz	short loc_15A5C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15B4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15A5C:				; CODE XREF: VLineT+94j
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 261
//@ 
//@ loc_15A5E:				; CODE XREF: VLineT+7Aj
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 262
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jg	short loc_15A71	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_15B0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 263
//@ 
//@ loc_15A71:				; CODE XREF: VLineT+A9j
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jnz	short loc_15A7B	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15B4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 264
//@ 
//@ loc_15A7B:				; CODE XREF: VLineT+B3j
//@ 		jmp	loc_15B0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 269
//@ 
//@ loc_15A7E:				; CODE XREF: VLineT+1Fj
//@ 		mov	di, word ptr Yb.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 270
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		inc	ax		; Increment by 1
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 271
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_15A96	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_15B4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 272
//@ 
//@ loc_15A96:				; CODE XREF: VLineT+CEj
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Ya.DW+2, cx ; struct DWord
//@ 		jge	short loc_15AA3	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_15B4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 274
//@ 
//@ loc_15AA3:				; CODE XREF: VLineT+DBj
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15ACC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 275
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 276
//@ 		mov	ax, txa		; int16_t
//@ 		sub	ax, txb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 277
//@ 		mov	ax, tya		; int16_t
//@ 		sub	ax, tyb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 280
//@ 
//@ loc_15ACC:				; CODE XREF: VLineT+E7j
//@ 		mov	dx, txb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 281
//@ 		mov	si, tyb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 285
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15AF4	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 286
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 287
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 288
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 289
//@ 		sub	lnH, bx		; uint16_t
//@ 		jz	short locret_15B4F ; Jump if Zero (ZF=1)
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 292
//@ 
//@ loc_15AF4:				; CODE XREF: VLineT+113j
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 293
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_15B0B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 294
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jz	short locret_15B4F ; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 300
//@ 
//@ loc_15B0B:				; CODE XREF: VLineT+ABj
//@ 					; VLineT:loc_15A7Bj ...
//@ 		mov	bx, di
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 301
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 302
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CS_MAPML.PAS" 304
//@ 		mov	bx, Curdark	; int16_t
//@ ; #line	"CS_MAPML.PAS" 305
//@ 		push	bp
//@ ; #line	"CS_MAPML.PAS" 306
//@ 		mov	bp, si
//@ ; #line	"CS_MAPML.PAS" 308
//@ 
//@ loc_15B23:				; CODE XREF: VLineT+189j
//@ 		mov	si, bp
//@ ; #line	"CS_MAPML.PAS" 309
//@ 		mov	ax, dx
//@ ; #line	"CS_MAPML.PAS" 310
//@ 		shr	si, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 311
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 312
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 313
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 314
//@ 		add	si, CSprOfs	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 316
//@ 		mov	al, fs:[si]
//@ ; #line	"CS_MAPML.PAS" 317
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CS_MAPML.PAS" 318
//@ 		mov	gs:[edi], al
//@ ; #line	"CS_MAPML.PAS" 320
//@ 		add	bp, ctdy	; int16_t
//@ ; #line	"CS_MAPML.PAS" 321
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CS_MAPML.PAS" 322
//@ 		add	dx, ctdx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 323
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_15B23	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 325
//@ 		pop	bp
//@ ; #line	"CS_MAPML.PAS" 328
//@ 
//@ locret_15B4F:				; CODE XREF: VLineT+13j VLineT+37j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ VLineT		endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 334
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VLineTGlass	proc far
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 336
//@ 		mov	bx, x1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"CS_MAPML.PAS" 337
//@ 		cmp	ax, CurDH	; uint16_t
//@ 		jb	short loc_15B67	; Jump if Below	(CF=1)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 338
//@ 
//@ loc_15B67:				; CODE XREF: VLineTGlass+11j
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		cmp	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 339
//@ 		jge	short loc_15B73	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_15C10	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 343
//@ 
//@ loc_15B73:				; CODE XREF: VLineTGlass+1Dj
//@ 		mov	di, word ptr Ya.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 344
//@ 		mov	ax, word ptr Yb.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		jnz	short loc_15B81	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15B81:				; CODE XREF: VLineTGlass+2Bj
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 345
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_15B8F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 346
//@ 
//@ loc_15B8F:				; CODE XREF: VLineTGlass+39j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Yb.DW+2, cx ; struct DWord
//@ 		jge	short loc_15B9C	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 348
//@ 
//@ loc_15B9C:				; CODE XREF: VLineTGlass+46j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15BC5	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 349
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 350
//@ 		mov	ax, txb		; int16_t
//@ 		sub	ax, txa		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 351
//@ 		mov	ax, tyb		; int16_t
//@ 		sub	ax, tya		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 353
//@ 
//@ loc_15BC5:				; CODE XREF: VLineTGlass+52j
//@ 		mov	dx, txa		; int16_t
//@ ; #line	"CS_MAPML.PAS" 354
//@ 		mov	si, tya		; int16_t
//@ ; #line	"CS_MAPML.PAS" 357
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15BF0	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 358
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 359
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 360
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 361
//@ 		sub	lnH, bx		; uint16_t
//@ 		jnz	short loc_15BEE	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15BEE:				; CODE XREF: VLineTGlass+98j
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 363
//@ 
//@ loc_15BF0:				; CODE XREF: VLineTGlass+7Ej
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 364
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jg	short loc_15C03	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_15CA1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 365
//@ 
//@ loc_15C03:				; CODE XREF: VLineTGlass+ADj
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jnz	short loc_15C0D	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 366
//@ 
//@ loc_15C0D:				; CODE XREF: VLineTGlass+B7j
//@ 		jmp	loc_15CA1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 371
//@ 
//@ loc_15C10:				; CODE XREF: VLineTGlass+1Fj
//@ 		mov	di, word ptr Yb.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 372
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		jnz	short loc_15C1E	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15C1E:				; CODE XREF: VLineTGlass+C8j
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 373
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_15C2C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 374
//@ 
//@ loc_15C2C:				; CODE XREF: VLineTGlass+D6j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Ya.DW+2, cx ; struct DWord
//@ 		jge	short loc_15C39	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_15CF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 376
//@ 
//@ loc_15C39:				; CODE XREF: VLineTGlass+E3j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15C62	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 377
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 378
//@ 		mov	ax, txa		; int16_t
//@ 		sub	ax, txb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 379
//@ 		mov	ax, tya		; int16_t
//@ 		sub	ax, tyb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 382
//@ 
//@ loc_15C62:				; CODE XREF: VLineTGlass+EFj
//@ 		mov	dx, txb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 383
//@ 		mov	si, tyb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 387
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15C8A	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 388
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 389
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 390
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 391
//@ 		sub	lnH, bx		; uint16_t
//@ 		jz	short locret_15CF0 ; Jump if Zero (ZF=1)
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 394
//@ 
//@ loc_15C8A:				; CODE XREF: VLineTGlass+11Bj
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 395
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_15CA1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 396
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jz	short locret_15CF0 ; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 402
//@ 
//@ loc_15CA1:				; CODE XREF: VLineTGlass+AFj
//@ 					; VLineTGlass:loc_15C0Dj ...
//@ 		mov	bx, di
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 403
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 404
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CS_MAPML.PAS" 406
//@ 		push	es
//@ 		push	bp
//@ ; #line	"CS_MAPML.PAS" 407
//@ 		mov	ax, RGBSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 408
//@ 		mov	bp, si
//@ ; #line	"CS_MAPML.PAS" 409
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 411
//@ 
//@ loc_15CBD:				; CODE XREF: VLineTGlass+19Bj
//@ 		mov	si, bp
//@ ; #line	"CS_MAPML.PAS" 412
//@ 		mov	ax, dx
//@ ; #line	"CS_MAPML.PAS" 413
//@ 		shr	si, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 414
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 415
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 416
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 417
//@ 		add	si, CSprOfs	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 418
//@ 		mov	bh, fs:[si]
//@ ; #line	"CS_MAPML.PAS" 419
//@ 		mov	bl, gs:[edi]
//@ ; #line	"CS_MAPML.PAS" 420
//@ 		mov	al, es:[bx]
//@ ; #line	"CS_MAPML.PAS" 421
//@ 		mov	gs:[edi], al
//@ ; #line	"CS_MAPML.PAS" 422
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CS_MAPML.PAS" 423
//@ 		add	bp, ctdy	; int16_t
//@ ; #line	"CS_MAPML.PAS" 424
//@ 		add	dx, ctdx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 425
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_15CBD	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 426
//@ 		pop	bp
//@ 		pop	es
//@ ; #line	"CS_MAPML.PAS" 429
//@ 
//@ locret_15CF0:				; CODE XREF: VLineTGlass+13j
//@ 					; VLineTGlass+2Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ VLineTGlass	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 434
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VLineTGlass60	proc far
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 436
//@ 		mov	bx, x1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"CS_MAPML.PAS" 437
//@ 		cmp	ax, CurDH	; uint16_t
//@ 		jb	short loc_15D08	; Jump if Below	(CF=1)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 438
//@ 
//@ loc_15D08:				; CODE XREF: VLineTGlass60+11j
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		cmp	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 439
//@ 		jge	short loc_15D14	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_15DB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 443
//@ 
//@ loc_15D14:				; CODE XREF: VLineTGlass60+1Dj
//@ 		mov	di, word ptr Ya.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 444
//@ 		mov	ax, word ptr Yb.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		jnz	short loc_15D22	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15D22:				; CODE XREF: VLineTGlass60+2Bj
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 445
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_15D30	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 446
//@ 
//@ loc_15D30:				; CODE XREF: VLineTGlass60+39j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Yb.DW+2, cx ; struct DWord
//@ 		jge	short loc_15D3D	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 448
//@ 
//@ loc_15D3D:				; CODE XREF: VLineTGlass60+46j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15D66	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 449
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 450
//@ 		mov	ax, txb		; int16_t
//@ 		sub	ax, txa		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 451
//@ 		mov	ax, tyb		; int16_t
//@ 		sub	ax, tya		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 453
//@ 
//@ loc_15D66:				; CODE XREF: VLineTGlass60+52j
//@ 		mov	dx, txa		; int16_t
//@ ; #line	"CS_MAPML.PAS" 454
//@ 		mov	si, tya		; int16_t
//@ ; #line	"CS_MAPML.PAS" 457
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15D91	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 458
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 459
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 460
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 461
//@ 		sub	lnH, bx		; uint16_t
//@ 		jnz	short loc_15D8F	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15D8F:				; CODE XREF: VLineTGlass60+98j
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 463
//@ 
//@ loc_15D91:				; CODE XREF: VLineTGlass60+7Ej
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 464
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jg	short loc_15DA4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_15E42	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 465
//@ 
//@ loc_15DA4:				; CODE XREF: VLineTGlass60+ADj
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jnz	short loc_15DAE	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 466
//@ 
//@ loc_15DAE:				; CODE XREF: VLineTGlass60+B7j
//@ 		jmp	loc_15E42	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 471
//@ 
//@ loc_15DB1:				; CODE XREF: VLineTGlass60+1Fj
//@ 		mov	di, word ptr Yb.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 472
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		jnz	short loc_15DBF	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15DBF:				; CODE XREF: VLineTGlass60+C8j
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 473
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_15DCD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 474
//@ 
//@ loc_15DCD:				; CODE XREF: VLineTGlass60+D6j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Ya.DW+2, cx ; struct DWord
//@ 		jge	short loc_15DDA	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_15E91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 476
//@ 
//@ loc_15DDA:				; CODE XREF: VLineTGlass60+E3j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15E03	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 477
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 478
//@ 		mov	ax, txa		; int16_t
//@ 		sub	ax, txb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 479
//@ 		mov	ax, tya		; int16_t
//@ 		sub	ax, tyb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 482
//@ 
//@ loc_15E03:				; CODE XREF: VLineTGlass60+EFj
//@ 		mov	dx, txb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 483
//@ 		mov	si, tyb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 487
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15E2B	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 488
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 489
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 490
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 491
//@ 		sub	lnH, bx		; uint16_t
//@ 		jz	short locret_15E91 ; Jump if Zero (ZF=1)
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 494
//@ 
//@ loc_15E2B:				; CODE XREF: VLineTGlass60+11Bj
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 495
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_15E42	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 496
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jz	short locret_15E91 ; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 502
//@ 
//@ loc_15E42:				; CODE XREF: VLineTGlass60+AFj
//@ 					; VLineTGlass60:loc_15DAEj ...
//@ 		mov	bx, di
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 503
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 504
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CS_MAPML.PAS" 506
//@ 		push	es
//@ 		push	bp
//@ ; #line	"CS_MAPML.PAS" 507
//@ 		mov	ax, RGBSeg60	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 508
//@ 		mov	bp, si
//@ ; #line	"CS_MAPML.PAS" 509
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 511
//@ 
//@ loc_15E5E:				; CODE XREF: VLineTGlass60+19Bj
//@ 		mov	si, bp
//@ ; #line	"CS_MAPML.PAS" 512
//@ 		mov	ax, dx
//@ ; #line	"CS_MAPML.PAS" 513
//@ 		shr	si, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 514
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 515
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 516
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 517
//@ 		add	si, CSprOfs	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 518
//@ 		mov	bh, fs:[si]
//@ ; #line	"CS_MAPML.PAS" 519
//@ 		mov	bl, gs:[edi]
//@ ; #line	"CS_MAPML.PAS" 520
//@ 		mov	al, es:[bx]
//@ ; #line	"CS_MAPML.PAS" 521
//@ 		mov	gs:[edi], al
//@ ; #line	"CS_MAPML.PAS" 522
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CS_MAPML.PAS" 523
//@ 		add	bp, ctdy	; int16_t
//@ ; #line	"CS_MAPML.PAS" 524
//@ 		add	dx, ctdx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 525
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_15E5E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 526
//@ 		pop	bp
//@ 		pop	es
//@ ; #line	"CS_MAPML.PAS" 529
//@ 
//@ locret_15E91:				; CODE XREF: VLineTGlass60+13j
//@ 					; VLineTGlass60+2Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ VLineTGlass60	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 535
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VLineTFF	proc far
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 537
//@ 		mov	bx, x1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"CS_MAPML.PAS" 538
//@ 		cmp	ax, CurDH	; uint16_t
//@ 		jbe	short loc_15EA9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_16025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 539
//@ 
//@ loc_15EA9:				; CODE XREF: VLineTFF+11j
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		cmp	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 540
//@ 		jge	short loc_15EB5	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_15F4E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 544
//@ 
//@ loc_15EB5:				; CODE XREF: VLineTFF+1Dj
//@ 		mov	di, word ptr Ya.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 545
//@ 		mov	ax, word ptr Yb.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		inc	ax		; Increment by 1
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 546
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_15ECD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_16025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 547
//@ 
//@ loc_15ECD:				; CODE XREF: VLineTFF+35j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Yb.DW+2, cx ; struct DWord
//@ 		jge	short loc_15EDA	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_16025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 549
//@ 
//@ loc_15EDA:				; CODE XREF: VLineTFF+42j
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15F03	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 550
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 551
//@ 		mov	ax, txb		; int16_t
//@ 		sub	ax, txa		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 552
//@ 		mov	ax, tyb		; int16_t
//@ 		sub	ax, tya		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 554
//@ 
//@ loc_15F03:				; CODE XREF: VLineTFF+4Ej
//@ 		mov	dx, txa		; int16_t
//@ ; #line	"CS_MAPML.PAS" 555
//@ 		mov	si, tya		; int16_t
//@ ; #line	"CS_MAPML.PAS" 558
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15F2E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 559
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 560
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 561
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 562
//@ 		sub	lnH, bx		; uint16_t
//@ 		jnz	short loc_15F2C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_16025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15F2C:				; CODE XREF: VLineTFF+94j
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 564
//@ 
//@ loc_15F2E:				; CODE XREF: VLineTFF+7Aj
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 565
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jg	short loc_15F41	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_15FDB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 566
//@ 
//@ loc_15F41:				; CODE XREF: VLineTFF+A9j
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jnz	short loc_15F4B	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_16025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 567
//@ 
//@ loc_15F4B:				; CODE XREF: VLineTFF+B3j
//@ 		jmp	loc_15FDB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 572
//@ 
//@ loc_15F4E:				; CODE XREF: VLineTFF+1Fj
//@ 		mov	di, word ptr Yb.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 573
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		sub	ax, di		; Integer Subtraction
//@ 		inc	ax		; Increment by 1
//@ 		mov	lnH, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 574
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jle	short loc_15F66	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_16025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 575
//@ 
//@ loc_15F66:				; CODE XREF: VLineTFF+CEj
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	word ptr Ya.DW+2, cx ; struct DWord
//@ 		jge	short loc_15F73	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_16025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 577
//@ 
//@ loc_15F73:				; CODE XREF: VLineTFF+DBj
//@ 		mov	bx, lnH		; uint16_t
//@ 		cmp	bx, 1		; Compare Two Operands
//@ 		jle	short loc_15F9C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 578
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 579
//@ 		mov	ax, txa		; int16_t
//@ 		sub	ax, txb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdx, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 580
//@ 		mov	ax, tya		; int16_t
//@ 		sub	ax, tyb		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	ctdy, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 583
//@ 
//@ loc_15F9C:				; CODE XREF: VLineTFF+E7j
//@ 		mov	dx, txb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 584
//@ 		mov	si, tyb		; int16_t
//@ ; #line	"CS_MAPML.PAS" 588
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_15FC4	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 589
//@ 		mov	bx, cx
//@ 		sub	bx, di		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 590
//@ 		push	dx
//@ 		mov	ax, ctdy	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 591
//@ 		mov	ax, ctdx	; int16_t
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		pop	dx
//@ 		add	dx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 592
//@ 		sub	lnH, bx		; uint16_t
//@ 		jz	short locret_16025 ; Jump if Zero (ZF=1)
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 595
//@ 
//@ loc_15FC4:				; CODE XREF: VLineTFF+113j
//@ 		mov	cx, lnH		; uint16_t
//@ 		mov	bx, WinEY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 596
//@ 		mov	ax, cx
//@ 		add	ax, di		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_15FDB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 597
//@ 		inc	bx		; Increment by 1
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		sub	cx, ax		; Integer Subtraction
//@ 		jz	short locret_16025 ; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 603
//@ 
//@ loc_15FDB:				; CODE XREF: VLineTFF+ABj
//@ 					; VLineTFF:loc_15F4Bj ...
//@ 		mov	bx, di
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 604
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 605
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CS_MAPML.PAS" 607
//@ 		mov	bx, Curdark	; int16_t
//@ ; #line	"CS_MAPML.PAS" 608
//@ 		push	bp
//@ ; #line	"CS_MAPML.PAS" 609
//@ 		mov	bp, si
//@ ; #line	"CS_MAPML.PAS" 610
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 612
//@ 
//@ loc_15FF5:				; CODE XREF: VLineTFF+18Fj
//@ 		mov	si, bp
//@ ; #line	"CS_MAPML.PAS" 613
//@ 		mov	ax, dx
//@ ; #line	"CS_MAPML.PAS" 614
//@ 		shr	si, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 615
//@ 		shr	ax, 8		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 616
//@ 		shl	si, 6		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 617
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 618
//@ 		add	si, CSprOfs	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 619
//@ 		mov	al, fs:[si]
//@ ; #line	"CS_MAPML.PAS" 620
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_16014	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 621
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CS_MAPML.PAS" 622
//@ 		mov	gs:[edi], al
//@ ; #line	"CS_MAPML.PAS" 623
//@ 
//@ loc_16014:				; CODE XREF: VLineTFF+17Aj
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CS_MAPML.PAS" 624
//@ 		add	bp, ctdy	; int16_t
//@ ; #line	"CS_MAPML.PAS" 625
//@ 		add	dx, ctdx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 626
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_15FF5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 627
//@ 		pop	bp
//@ ; #line	"CS_MAPML.PAS" 630
//@ 
//@ locret_16025:				; CODE XREF: VLineTFF+13j VLineTFF+37j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ VLineTFF	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 638
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VLineD		proc far		; CODE XREF: DrawTriFaceSh+194P
//@ 					; DrawTriFaceSh+1DCP ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 640
//@ 		mov	bx, x1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	ax, [bx-7DD2h]
//@ ; #line	"CS_MAPML.PAS" 641
//@ 		cmp	ax, CurDH	; uint16_t
//@ 		jb	short loc_1603D	; Jump if Below	(CF=1)
//@ 		jmp	locret_160C0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 642
//@ 
//@ loc_1603D:				; CODE XREF: VLineD+11j
//@ 		mov	ax, word ptr Ya.DW+2 ; struct DWord
//@ 		cmp	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 643
//@ 		jl	short loc_1606D	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 647
//@ 		mov	di, word ptr Ya.DW+2 ; struct DWord
//@ 		mov	si, word ptr Yb.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 648
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jg	short locret_160C0 ; Jump if Greater (ZF=0 & SF=OF)
//@ ; #line	"CS_MAPML.PAS" 649
//@ 		inc	cx		; Increment by 1
//@ 		cmp	si, cx		; Compare Two Operands
//@ 		jle	short loc_1605D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	si, cx
//@ ; #line	"CS_MAPML.PAS" 650
//@ 
//@ loc_1605D:				; CODE XREF: VLineD+32j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	si, cx		; Compare Two Operands
//@ 		jl	short locret_160C0 ; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 651
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_1606B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 652
//@ 
//@ loc_1606B:				; CODE XREF: VLineD+40j
//@ 		jmp	short loc_16094	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 657
//@ 
//@ loc_1606D:				; CODE XREF: VLineD+1Dj
//@ 		mov	di, word ptr Yb.DW+2 ; struct DWord
//@ 		mov	si, word ptr Ya.DW+2 ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 658
//@ 		mov	cx, WinEY	; uint16_t
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jg	short locret_160C0 ; Jump if Greater (ZF=0 & SF=OF)
//@ ; #line	"CS_MAPML.PAS" 659
//@ 		inc	cx		; Increment by 1
//@ 		cmp	si, cx		; Compare Two Operands
//@ 		jle	short loc_16084	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	si, cx
//@ ; #line	"CS_MAPML.PAS" 660
//@ 
//@ loc_16084:				; CODE XREF: VLineD+59j
//@ 		mov	cx, WinSY	; uint16_t
//@ 		cmp	si, cx		; Compare Two Operands
//@ 		jl	short locret_160C0 ; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 661
//@ 		cmp	di, cx		; Compare Two Operands
//@ 		jge	short loc_16092	; Jump if Greater or Equal (SF=OF)
//@ 		mov	di, cx
//@ ; #line	"CS_MAPML.PAS" 662
//@ 
//@ loc_16092:				; CODE XREF: VLineD+67j
//@ 		jmp	short $+2	; Jump
//@ ; #line	"CS_MAPML.PAS" 666
//@ 
//@ loc_16094:				; CODE XREF: VLineD:loc_1606Bj
//@ 		mov	cx, si
//@ 		sub	cx, di		; Integer Subtraction
//@ 		jz	short locret_160C0 ; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 668
//@ 		mov	bx, di
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 669
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 670
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CS_MAPML.PAS" 672
//@ 		mov	bx, ShLevel	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 675
//@ 
//@ loc_160AF:				; CODE XREF: VLineD+97j
//@ 		mov	al, gs:[edi]
//@ ; #line	"CS_MAPML.PAS" 676
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CS_MAPML.PAS" 677
//@ 		mov	gs:[edi], al
//@ ; #line	"CS_MAPML.PAS" 678
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CS_MAPML.PAS" 679
//@ 		dec	cx		; Decrement by 1
//@ ; #line	"CS_MAPML.PAS" 680
//@ 		jnz	short loc_160AF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 683
//@ 
//@ locret_160C0:				; CODE XREF: VLineD+13j VLineD+2Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ VLineD		endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 696
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawTriFace	proc far		; CODE XREF: DrawFaces+7AP
//@ 					; DrawFacesNoCheck+48P
//@ 		mov	di, es:[si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	bx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 697
//@ 		mov	di, es:[si+2]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 698
//@ 		mov	di, es:[si+4]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	dx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 700
//@ 		cmp	bx, cx		; Compare Two Operands
//@ 		jge	short loc_1610F	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 702
//@ 		cmp	bx, dx		; Compare Two Operands
//@ 		jge	short loc_160F5	; Jump if Greater or Equal (SF=OF)
//@ 		mov	v1, 0		; uint16_t
//@ 		jmp	short loc_160FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 703
//@ 
//@ loc_160F5:				; CODE XREF: DrawTriFace+29j
//@ 		mov	v1, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 705
//@ 
//@ loc_160FB:				; CODE XREF: DrawTriFace+31j
//@ 		cmp	cx, dx		; Compare Two Operands
//@ 		jl	short loc_16107	; Jump if Less (SF!=OF)
//@ 		mov	v3, 1		; uint16_t
//@ 		jmp	short loc_1610D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 706
//@ 
//@ loc_16107:				; CODE XREF: DrawTriFace+3Bj
//@ 		mov	v3, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 707
//@ 
//@ loc_1610D:				; CODE XREF: DrawTriFace+43j
//@ 		jmp	short loc_16133	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 710
//@ 
//@ loc_1610F:				; CODE XREF: DrawTriFace+25j
//@ 		cmp	cx, dx		; Compare Two Operands
//@ 		jge	short loc_1611B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	v1, 1		; uint16_t
//@ 		jmp	short loc_16121	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 711
//@ 
//@ loc_1611B:				; CODE XREF: DrawTriFace+4Fj
//@ 		mov	v1, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 713
//@ 
//@ loc_16121:				; CODE XREF: DrawTriFace+57j
//@ 		cmp	bx, dx		; Compare Two Operands
//@ 		jl	short loc_1612D	; Jump if Less (SF!=OF)
//@ 		mov	v3, 0		; uint16_t
//@ 		jmp	short loc_16133	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 714
//@ 
//@ loc_1612D:				; CODE XREF: DrawTriFace+61j
//@ 		mov	v3, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 721
//@ 
//@ loc_16133:				; CODE XREF: DrawTriFace:loc_1610Dj
//@ 					; DrawTriFace+69j
//@ 		mov	ax, 0
//@ ; #line	"CS_MAPML.PAS" 722
//@ 		cmp	ax, v1		; uint16_t
//@ 		jz	short loc_16144	; Jump if Zero (ZF=1)
//@ 		cmp	ax, v3		; uint16_t
//@ 		jz	short loc_16144	; Jump if Zero (ZF=1)
//@ 		jmp	short loc_16154	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_16144:				; CODE XREF: DrawTriFace+78j
//@ 					; DrawTriFace+7Ej
//@ 		inc	ax		; Increment by 1
//@ ; #line	"CS_MAPML.PAS" 723
//@ 		cmp	ax, v1		; uint16_t
//@ 		jz	short loc_16153	; Jump if Zero (ZF=1)
//@ 		cmp	ax, v3		; uint16_t
//@ 		jz	short loc_16153	; Jump if Zero (ZF=1)
//@ 		jmp	short loc_16154	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_16153:				; CODE XREF: DrawTriFace+87j
//@ 					; DrawTriFace+8Dj
//@ 		inc	ax		; Increment by 1
//@ ; #line	"CS_MAPML.PAS" 724
//@ 
//@ loc_16154:				; CODE XREF: DrawTriFace+80j
//@ 					; DrawTriFace+8Fj
//@ 		mov	v2, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 727
//@ 		mov	bx, v1		; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 728
//@ 		mov	ax, es:[bx+si+8]
//@ 		mov	tx1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 729
//@ 		mov	ax, es:[bx+si+0Ah]
//@ 		mov	ty1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 730
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 731
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 732
//@ 		mov	ax, es:[di]
//@ 		mov	x1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 733
//@ 		mov	ax, es:[di+2]
//@ 		mov	y1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 736
//@ 		mov	bx, v2		; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 737
//@ 		mov	ax, es:[bx+si+8]
//@ 		mov	tx2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 738
//@ 		mov	ax, es:[bx+si+0Ah]
//@ 		mov	ty2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 739
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 740
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 741
//@ 		mov	ax, es:[di]
//@ 		mov	x2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 742
//@ 		mov	ax, es:[di+2]
//@ 		mov	y2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 744
//@ 		mov	bx, v3		; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 745
//@ 		mov	ax, es:[bx+si+8]
//@ 		mov	tx3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 746
//@ 		mov	ax, es:[bx+si+0Ah]
//@ 		mov	ty3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 747
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 748
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 749
//@ 		mov	ax, es:[di]
//@ 		mov	x3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 750
//@ 		mov	ax, es:[di+2]
//@ 		mov	y3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 753
//@ 		mov	ax, x2		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 754
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x2		; int16_t
//@ 		mov	L2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 755
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 759
//@ 		mov	ax, tx1		; int16_t
//@ 		mov	txa, ax		; int16_t
//@ 		mov	txb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 760
//@ 		mov	ax, ty1		; int16_t
//@ 		mov	tya, ax		; int16_t
//@ 		mov	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 761
//@ 		mov	ax, y1		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 762
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 765
//@ 		mov	bx, L1		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_16260	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 766
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 767
//@ 		mov	ax, tx2		; int16_t
//@ 		sub	ax, tx1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx1, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 768
//@ 		mov	ax, ty2		; int16_t
//@ 		sub	ax, ty1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty1, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 769
//@ 		mov	ax, y2		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 770
//@ 		mov	word ptr dy1.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy1.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 774
//@ 
//@ loc_16260:				; CODE XREF: DrawTriFace+16Bj
//@ 		mov	bx, L2		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_1629A	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 775
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 776
//@ 		mov	ax, tx3		; int16_t
//@ 		sub	ax, tx2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx2, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 777
//@ 		mov	ax, ty3		; int16_t
//@ 		sub	ax, ty2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty2, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 778
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 779
//@ 		mov	word ptr dy2.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy2.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 783
//@ 
//@ loc_1629A:				; CODE XREF: DrawTriFace+1A5j
//@ 		mov	bx, L3		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_162D4	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 784
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 785
//@ 		mov	ax, tx3		; int16_t
//@ 		sub	ax, tx1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx3, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 786
//@ 		mov	ax, ty3		; int16_t
//@ 		sub	ax, ty1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty3, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 787
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 788
//@ 		mov	word ptr dy3.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy3.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 793
//@ 
//@ loc_162D4:				; CODE XREF: DrawTriFace+1DFj
//@ 					; DrawTriFace+26Aj
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x2		; int16_t
//@ 		jge	short loc_1632E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 795
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_162F0	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 796
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jle	short loc_162EC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_1639D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 797
//@ 
//@ loc_162EC:				; CODE XREF: DrawTriFace+225j
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 799
//@ 
//@ loc_162F0:				; CODE XREF: DrawTriFace+21Fj
//@ 		mov	ax, dtx3	; int16_t
//@ 		add	txa, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 800
//@ 		mov	ax, dty3	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 801
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 802
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 804
//@ 		mov	ax, dtx1	; int16_t
//@ 		add	txb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 805
//@ 		mov	ax, dty1	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 806
//@ 		mov	ax, word ptr dy1.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 807
//@ 		mov	ax, word ptr dy1.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 808
//@ 		inc	x1		; int16_t
//@ 		jmp	short loc_162D4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 813
//@ 
//@ loc_1632E:				; CODE XREF: DrawTriFace+219j
//@ 		mov	ax, tx2		; int16_t
//@ 		mov	txb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 814
//@ 		mov	ax, ty2		; int16_t
//@ 		mov	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 815
//@ 		mov	ax, y2		; int16_t
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 817
//@ 
//@ loc_16346:				; CODE XREF: DrawTriFace+2D9j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x3		; int16_t
//@ 		jge	short locret_1639D ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 818
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_1635F	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short locret_1639D ; Jump if Greater (ZF=0 & SF=OF)
//@ ; #line	"CS_MAPML.PAS" 819
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 822
//@ 
//@ loc_1635F:				; CODE XREF: DrawTriFace+291j
//@ 		mov	ax, dtx3	; int16_t
//@ 		add	txa, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 823
//@ 		mov	ax, dty3	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 824
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 825
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 827
//@ 		mov	ax, dtx2	; int16_t
//@ 		add	txb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 828
//@ 		mov	ax, dty2	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 829
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 830
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 832
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 833
//@ 		jmp	short loc_16346	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 835
//@ 
//@ locret_1639D:				; CODE XREF: DrawTriFace+227j
//@ 					; DrawTriFace+28Bj ...
//@ 		retf			; Return Far from Procedure
//@ DrawTriFace	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 842
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawFourFace1234 proc far		; CODE XREF: DrawFourFace:loc_169ECP
//@ 		mov	ax, x2		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 843
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x2		; int16_t
//@ 		mov	L2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 844
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 845
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x3		; int16_t
//@ 		mov	l4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 847
//@ 		mov	ax, tx1		; int16_t
//@ 		mov	txa, ax		; int16_t
//@ 		mov	txb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 848
//@ 		mov	ax, ty1		; int16_t
//@ 		mov	tya, ax		; int16_t
//@ 		mov	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 849
//@ 		mov	ax, y1		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 850
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 854
//@ 		mov	bx, L1		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_16427	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 855
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 856
//@ 		mov	ax, tx2		; int16_t
//@ 		sub	ax, tx1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx1, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 857
//@ 		mov	ax, ty2		; int16_t
//@ 		sub	ax, ty1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty1, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 858
//@ 		mov	ax, y2		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 859
//@ 		mov	word ptr dy1.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy1.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 863
//@ 
//@ loc_16427:				; CODE XREF: DrawFourFace1234+56j
//@ 		mov	bx, L2		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_16461	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 864
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 865
//@ 		mov	ax, tx4		; int16_t
//@ 		sub	ax, tx2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx2, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 866
//@ 		mov	ax, ty4		; int16_t
//@ 		sub	ax, ty2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty2, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 867
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 868
//@ 		mov	word ptr dy2.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy2.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 872
//@ 
//@ loc_16461:				; CODE XREF: DrawFourFace1234+90j
//@ 		mov	bx, L3		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_1649B	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 873
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 874
//@ 		mov	ax, tx3		; int16_t
//@ 		sub	ax, tx1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx3, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 875
//@ 		mov	ax, ty3		; int16_t
//@ 		sub	ax, ty1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty3, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 876
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 877
//@ 		mov	word ptr dy3.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy3.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 881
//@ 
//@ loc_1649B:				; CODE XREF: DrawFourFace1234+CAj
//@ 		mov	bx, l4		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_164D5	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 882
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 883
//@ 		mov	ax, tx4		; int16_t
//@ 		sub	ax, tx3		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx4, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 884
//@ 		mov	ax, ty4		; int16_t
//@ 		sub	ax, ty3		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty4, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 885
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y3		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 886
//@ 		mov	word ptr dy4.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy4.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 891
//@ 
//@ loc_164D5:				; CODE XREF: DrawFourFace1234+104j
//@ 					; DrawFourFace1234+18Fj
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x2		; int16_t
//@ 		jge	short loc_1652F	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 892
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_164F1	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jle	short loc_164ED	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_16610	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 893
//@ 
//@ loc_164ED:				; CODE XREF: DrawFourFace1234+14Aj
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 896
//@ 
//@ loc_164F1:				; CODE XREF: DrawFourFace1234+144j
//@ 		mov	ax, dtx1	; int16_t
//@ 		add	txa, ax		; int16_t
//@ 		mov	ax, dty1	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 897
//@ 		mov	ax, word ptr dy1.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy1.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 898
//@ 		mov	ax, dtx3	; int16_t
//@ 		add	txb, ax		; int16_t
//@ 		mov	ax, dty3	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 899
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 900
//@ 		inc	x1		; int16_t
//@ 		jmp	short loc_164D5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 905
//@ 
//@ loc_1652F:				; CODE XREF: DrawFourFace1234+13Ej
//@ 		mov	ax, tx2		; int16_t
//@ 		mov	txa, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 906
//@ 		mov	ax, ty2		; int16_t
//@ 		mov	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 907
//@ 		mov	ax, y2		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 909
//@ 
//@ loc_16547:				; CODE XREF: DrawFourFace1234+201j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x3		; int16_t
//@ 		jge	short loc_165A1	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 910
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_16563	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jle	short loc_1655F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_16610	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 911
//@ 
//@ loc_1655F:				; CODE XREF: DrawFourFace1234+1BCj
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 914
//@ 
//@ loc_16563:				; CODE XREF: DrawFourFace1234+1B6j
//@ 		mov	ax, dtx2	; int16_t
//@ 		add	txa, ax		; int16_t
//@ 		mov	ax, dty2	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 915
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 917
//@ 		mov	ax, dtx3	; int16_t
//@ 		add	txb, ax		; int16_t
//@ 		mov	ax, dty3	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 918
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 919
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 920
//@ 		jmp	short loc_16547	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 924
//@ 
//@ loc_165A1:				; CODE XREF: DrawFourFace1234+1B0j
//@ 		mov	ax, tx3		; int16_t
//@ 		mov	txb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 925
//@ 		mov	ax, ty3		; int16_t
//@ 		mov	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 926
//@ 		mov	ax, y3		; int16_t
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 928
//@ 
//@ loc_165B9:				; CODE XREF: DrawFourFace1234+270j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x4		; int16_t
//@ 		jge	short locret_16610 ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 929
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_165D2	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short locret_16610 ; Jump if Greater (ZF=0 & SF=OF)
//@ ; #line	"CS_MAPML.PAS" 930
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 933
//@ 
//@ loc_165D2:				; CODE XREF: DrawFourFace1234+228j
//@ 		mov	ax, dtx2	; int16_t
//@ 		add	txa, ax		; int16_t
//@ 		mov	ax, dty2	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 934
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 936
//@ 		mov	ax, dtx4	; int16_t
//@ 		add	txb, ax		; int16_t
//@ 		mov	ax, dty4	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 937
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 938
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 939
//@ 		jmp	short loc_165B9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 941
//@ 
//@ locret_16610:				; CODE XREF: DrawFourFace1234+14Cj
//@ 					; DrawFourFace1234+1BEj ...
//@ 		retf			; Return Far from Procedure
//@ DrawFourFace1234 endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 946
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawFourFace1243 proc far		; CODE XREF: DrawFourFace:loc_169F3P
//@ 		mov	ax, x2		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 947
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x2		; int16_t
//@ 		mov	L2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 948
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x3		; int16_t
//@ 		mov	L3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 949
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	l4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 951
//@ 		mov	ax, tx1		; int16_t
//@ 		mov	txa, ax		; int16_t
//@ 		mov	txb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 952
//@ 		mov	ax, ty1		; int16_t
//@ 		mov	tya, ax		; int16_t
//@ 		mov	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 953
//@ 		mov	ax, y1		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 954
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 958
//@ 		mov	bx, L1		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_1669A	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 960
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 961
//@ 		mov	ax, tx2		; int16_t
//@ 		sub	ax, tx1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx1, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 962
//@ 		mov	ax, ty2		; int16_t
//@ 		sub	ax, ty1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty1, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 963
//@ 		mov	ax, y2		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 964
//@ 		mov	word ptr dy1.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy1.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 968
//@ 
//@ loc_1669A:				; CODE XREF: DrawFourFace1243+56j
//@ 		mov	bx, L2		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_166D4	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 969
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 970
//@ 		mov	ax, tx3		; int16_t
//@ 		sub	ax, tx2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx2, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 971
//@ 		mov	ax, ty3		; int16_t
//@ 		sub	ax, ty2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty2, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 972
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y2		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 973
//@ 		mov	word ptr dy2.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy2.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 977
//@ 
//@ loc_166D4:				; CODE XREF: DrawFourFace1243+90j
//@ 		mov	bx, L3		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_1670E	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 978
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 979
//@ 		mov	ax, tx4		; int16_t
//@ 		sub	ax, tx3		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx3, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 980
//@ 		mov	ax, ty4		; int16_t
//@ 		sub	ax, ty3		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty3, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 981
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y3		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 982
//@ 		mov	word ptr dy3.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy3.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 986
//@ 
//@ loc_1670E:				; CODE XREF: DrawFourFace1243+CAj
//@ 		mov	bx, l4		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_16748	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 987
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ ; #line	"CS_MAPML.PAS" 988
//@ 		mov	ax, tx4		; int16_t
//@ 		sub	ax, tx1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dtx4, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 989
//@ 		mov	ax, ty4		; int16_t
//@ 		sub	ax, ty1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	dty4, dx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 990
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 991
//@ 		mov	word ptr dy4.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy4.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 996
//@ 
//@ loc_16748:				; CODE XREF: DrawFourFace1243+104j
//@ 					; DrawFourFace1243+18Fj
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x2		; int16_t
//@ 		jge	short loc_167A2	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 997
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_16764	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jle	short loc_16760	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_16883	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 998
//@ 
//@ loc_16760:				; CODE XREF: DrawFourFace1243+14Aj
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 1001
//@ 
//@ loc_16764:				; CODE XREF: DrawFourFace1243+144j
//@ 		mov	ax, dtx1	; int16_t
//@ 		add	txa, ax		; int16_t
//@ 		mov	ax, dty1	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1002
//@ 		mov	ax, word ptr dy1.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy1.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1003
//@ 		mov	ax, dtx4	; int16_t
//@ 		add	txb, ax		; int16_t
//@ 		mov	ax, dty4	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1004
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1005
//@ 		inc	x1		; int16_t
//@ 		jmp	short loc_16748	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1010
//@ 
//@ loc_167A2:				; CODE XREF: DrawFourFace1243+13Ej
//@ 		mov	ax, tx2		; int16_t
//@ 		mov	txa, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1011
//@ 		mov	ax, ty2		; int16_t
//@ 		mov	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1012
//@ 		mov	ax, y2		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1014
//@ 
//@ loc_167BA:				; CODE XREF: DrawFourFace1243+201j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x3		; int16_t
//@ 		jge	short loc_16814	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1015
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_167D6	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jle	short loc_167D2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_16883	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1016
//@ 
//@ loc_167D2:				; CODE XREF: DrawFourFace1243+1BCj
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 1019
//@ 
//@ loc_167D6:				; CODE XREF: DrawFourFace1243+1B6j
//@ 		mov	ax, dtx2	; int16_t
//@ 		add	txa, ax		; int16_t
//@ 		mov	ax, dty2	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1020
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1022
//@ 		mov	ax, dtx4	; int16_t
//@ 		add	txb, ax		; int16_t
//@ 		mov	ax, dty4	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1023
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1024
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1025
//@ 		jmp	short loc_167BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1029
//@ 
//@ loc_16814:				; CODE XREF: DrawFourFace1243+1B0j
//@ 		mov	ax, tx3		; int16_t
//@ 		mov	txa, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1030
//@ 		mov	ax, ty3		; int16_t
//@ 		mov	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1031
//@ 		mov	ax, y3		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1033
//@ 
//@ loc_1682C:				; CODE XREF: DrawFourFace1243+270j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x4		; int16_t
//@ 		jge	short locret_16883 ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1034
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_16845	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short locret_16883 ; Jump if Greater (ZF=0 & SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1035
//@ 		call	DrawRout	; void (*)()
//@ ; #line	"CS_MAPML.PAS" 1038
//@ 
//@ loc_16845:				; CODE XREF: DrawFourFace1243+228j
//@ 		mov	ax, dtx3	; int16_t
//@ 		add	txa, ax		; int16_t
//@ 		mov	ax, dty3	; int16_t
//@ 		add	tya, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1039
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1041
//@ 		mov	ax, dtx4	; int16_t
//@ 		add	txb, ax		; int16_t
//@ 		mov	ax, dty4	; int16_t
//@ 		add	tyb, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1042
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1043
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1044
//@ 		jmp	short loc_1682C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1046
//@ 
//@ locret_16883:				; CODE XREF: DrawFourFace1243+14Cj
//@ 					; DrawFourFace1243+1BEj ...
//@ 		retf			; Return Far from Procedure
//@ DrawFourFace1243 endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1052
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawFourFace	proc far		; CODE XREF: DrawFaces:loc_16A7AP
//@ 					; DrawFacesNoCheck:loc_16AD7P
//@ 		mov	Lx1, 3E8h	; int16_t
//@ 		mov	Lx2, 0FC18h	; int16_t
//@ 		mov	cx, 4
//@ 		mov	adx, 0		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1053
//@ 
//@ loc_16899:				; CODE XREF: DrawFourFace+42j
//@ 		mov	di, es:[si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1054
//@ 		cmp	ax, Lx1		; int16_t
//@ 		jg	short loc_168B1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	Lx1, ax		; int16_t
//@ 		mov	bx, adx		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1055
//@ 
//@ loc_168B1:				; CODE XREF: DrawFourFace+24j
//@ 		cmp	ax, Lx2		; int16_t
//@ 		jl	short loc_168BE	; Jump if Less (SF!=OF)
//@ 		mov	Lx2, ax		; int16_t
//@ 		mov	dx, adx		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1056
//@ 
//@ loc_168BE:				; CODE XREF: DrawFourFace+31j
//@ 		add	si, 2		; Add
//@ 		inc	adx		; int16_t
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_16899	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1057
//@ 		sub	si, 8		; Integer Subtraction
//@ 		mov	v1, bx		; uint16_t
//@ 		mov	v4, dx		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1059
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		add	bx, dx		; Add
//@ 		nop			; No Operation
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1060
//@ 		mov	ax, [bx+12B0h]
//@ ; #line	"CS_MAPML.PAS" 1061
//@ 		mov	bx, [bx+12B2h]
//@ ; #line	"CS_MAPML.PAS" 1062
//@ 		mov	v2, ax		; uint16_t
//@ 		mov	v3, bx		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1065
//@ 		mov	bx, v2		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1066
//@ 		mov	bx, v3		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	dx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1067
//@ 		cmp	cx, dx		; Compare Two Operands
//@ 		jle	short loc_16921	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 1068
//@ 		push	v2		; uint16_t
//@ 		push	v3		; uint16_t
//@ 		pop	v2		; uint16_t
//@ 		pop	v3		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1073
//@ 
//@ loc_16921:				; CODE XREF: DrawFourFace+8Bj
//@ 		mov	bx, v1		; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1074
//@ 		mov	ax, es:[bx+si+8]
//@ 		mov	tx1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1075
//@ 		mov	ax, es:[bx+si+0Ah]
//@ 		mov	ty1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1076
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 1077
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1078
//@ 		mov	ax, es:[di]
//@ 		mov	x1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1079
//@ 		mov	ax, es:[di+2]
//@ 		mov	y1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1081
//@ 		mov	bx, v2		; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1082
//@ 		mov	ax, es:[bx+si+8]
//@ 		mov	tx2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1083
//@ 		mov	ax, es:[bx+si+0Ah]
//@ 		mov	ty2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1084
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 1085
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1086
//@ 		mov	ax, es:[di]
//@ 		mov	x2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1087
//@ 		mov	ax, es:[di+2]
//@ 		mov	y2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1089
//@ 		mov	bx, v3		; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1090
//@ 		mov	ax, es:[bx+si+8]
//@ 		mov	tx3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1091
//@ 		mov	ax, es:[bx+si+0Ah]
//@ 		mov	ty3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1092
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 1093
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1094
//@ 		mov	ax, es:[di]
//@ 		mov	x3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1095
//@ 		mov	ax, es:[di+2]
//@ 		mov	y3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1097
//@ 		mov	bx, v4		; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1098
//@ 		mov	ax, es:[bx+si+8]
//@ 		mov	tx4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1099
//@ 		mov	ax, es:[bx+si+0Ah]
//@ 		mov	ty4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1100
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 1101
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1102
//@ 		mov	ax, es:[di]
//@ 		mov	x4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1103
//@ 		mov	ax, es:[di+2]
//@ 		mov	y4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1107
//@ 		mov	ax, v4		; uint16_t
//@ 		sub	ax, v1		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1108
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jz	short loc_169EC	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0FFFEh	; Compare Two Operands
//@ 		jz	short loc_169EC	; Jump if Zero (ZF=1)
//@ 		jmp	short loc_169F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1109
//@ 
//@ loc_169EC:				; CODE XREF: DrawFourFace+15Fj
//@ 					; DrawFourFace+164j
//@ 		call	DrawFourFace1234 ; function far	PASCAL returns void
//@ 		jmp	short locret_169F8 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1110
//@ 
//@ loc_169F3:				; CODE XREF: DrawFourFace+166j
//@ 		call	DrawFourFace1243 ; function far	PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1112
//@ 
//@ locret_169F8:				; CODE XREF: DrawFourFace+16Dj
//@ 		retf			; Return Far from Procedure
//@ DrawFourFace	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1117
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawFaces	proc far		; CODE XREF: Draw3DObject:loc_1842DP
//@ 					; DrawHi3D+254P
//@ 
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_MAPML.PAS" 1119
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1120
//@ 		mov	gs, ax
//@ ; #line	"CS_MAPML.PAS" 1121
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1123
//@ 		mov	ax, Current	; int16_t
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1124
//@ 
//@ loc_16A0D:				; CODE XREF: DrawFaces:loc_16A7Fj
//@ 		cmp	[bp+n],	0FFFFh	; int16_t
//@ 		jz	short loc_16A81	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1126
//@ 		mov	si, [bp+n]	; int16_t
//@ 		shl	si, 1		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1127
//@ 		cmp	XTabUpdated, 1	; bool
//@ 		jnz	short loc_16A27	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1128
//@ 		mov	bx, [si+6AAh]
//@ 		mov	Curdark, bx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1129
//@ 
//@ loc_16A27:				; CODE XREF: DrawFaces+24j
//@ 		shl	si, 4		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1130
//@ 		mov	ax, es:[si+18h]
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1132
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 1133
//@ 		mov	bl, es:[si+1Dh]
//@ 		and	bx, 0Eh		; Logical AND
//@ ; #line	"CS_MAPML.PAS" 1134
//@ 		mov	ax, [bx+0A9Ch]
//@ ; #line	"CS_MAPML.PAS" 1135
//@ 		mov	word ptr DrawRout, ax ;	void (*)()
//@ ; #line	"CS_MAPML.PAS" 1137
//@ 		mov	ax, es:[si+1Eh]
//@ 		mov	CSprOfs, ax	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1138
//@ 		mov	bx, es:[si+1Ah]
//@ 		shr	bx, 2		; Shift	Logical	Right
//@ 		sub	bx, HPrior	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1139
//@ 		cmp	bx, 3Ch	; '<'   ; Compare Two Operands
//@ 		jg	short loc_16A5C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	bx, 3Ch	; '<'
//@ ; #line	"CS_MAPML.PAS" 1140
//@ 
//@ loc_16A5C:				; CODE XREF: DrawFaces+5Ej
//@ 		mov	ax, Hz2		; uint16_t
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		imul	WallH		; uint16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	CurDH, ax	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1142
//@ 		mov	ax, es:[si+6]
//@ 		cmp	ax, 0FFh	; Compare Two Operands
//@ 		jnz	short loc_16A7A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1143
//@ 		call	DrawTriFace	; function far PASCAL returns void
//@ 		jmp	short loc_16A7F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1144
//@ 
//@ loc_16A7A:				; CODE XREF: DrawFaces+78j
//@ 		call	DrawFourFace	; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1145
//@ 
//@ loc_16A7F:				; CODE XREF: DrawFaces+7Fj
//@ 		jmp	short loc_16A0D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1148
//@ 
//@ loc_16A81:				; CODE XREF: DrawFaces+18j
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1149
//@ 		mov	gs, ax
//@ ; #line	"CS_MAPML.PAS" 1151
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DrawFaces	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1157
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawFacesNoCheck proc far		; CODE XREF: Show3DObject+F0P
//@ 
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_MAPML.PAS" 1159
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1160
//@ 		mov	gs, ax
//@ ; #line	"CS_MAPML.PAS" 1161
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1163
//@ 		mov	ax, Current	; int16_t
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1164
//@ 
//@ loc_16A9C:				; CODE XREF: DrawFacesNoCheck:loc_16ADCj
//@ 		cmp	[bp+n],	0FFFFh	; int16_t
//@ 		jz	short loc_16ADE	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1166
//@ 		mov	si, [bp+n]	; int16_t
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1167
//@ 		mov	ax, es:[si+18h]
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1169
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 1170
//@ 		mov	bl, es:[si+1Dh]
//@ 		and	bx, 0Eh		; Logical AND
//@ ; #line	"CS_MAPML.PAS" 1171
//@ 		mov	ax, [bx+0A9Ch]
//@ ; #line	"CS_MAPML.PAS" 1172
//@ 		mov	word ptr DrawRout, ax ;	void (*)()
//@ ; #line	"CS_MAPML.PAS" 1174
//@ 		mov	ax, es:[si+1Eh]
//@ 		mov	CSprOfs, ax	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1175
//@ 		mov	ax, es:[si+6]
//@ 		cmp	ax, 0FFh	; Compare Two Operands
//@ 		jnz	short loc_16AD7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1176
//@ 		call	DrawTriFace	; function far PASCAL returns void
//@ 		jmp	short loc_16ADC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1177
//@ 
//@ loc_16AD7:				; CODE XREF: DrawFacesNoCheck+46j
//@ 		call	DrawFourFace	; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1178
//@ 
//@ loc_16ADC:				; CODE XREF: DrawFacesNoCheck+4Dj
//@ 		jmp	short loc_16A9C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1181
//@ 
//@ loc_16ADE:				; CODE XREF: DrawFacesNoCheck+18j
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1182
//@ 		mov	gs, ax
//@ ; #line	"CS_MAPML.PAS" 1184
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DrawFacesNoCheck endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1191
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ RotateModelCopy	proc far		; CODE XREF: Show3DObject+C8P
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1192
//@ 		mov	di, 3200h
//@ ; #line	"CS_MAPML.PAS" 1193
//@ 		mov	si, 3800h
//@ ; #line	"CS_MAPML.PAS" 1194
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1196
//@ 
//@ loc_16AF4:				; CODE XREF: RotateModelCopy+37j
//@ 		mov	ax, es:[di]
//@ 		add	ax, OBJx	; int16_t
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 1197
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, OBJy	; int16_t
//@ 		mov	es:[si+2], ax
//@ ; #line	"CS_MAPML.PAS" 1198
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	es:[si+4], ax
//@ ; #line	"CS_MAPML.PAS" 1200
//@ 		add	si, 6		; Add
//@ 		add	di, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1201
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_16AF4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1202
//@ 		mov	CurDH, 3E80h	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1203
//@ 		retf			; Return Far from Procedure
//@ RotateModelCopy	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1208
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RotateModelASM	proc far		; CODE XREF: Draw3DObject:loc_17F0CP
//@ 					; DrawHi3D+228P
//@ 
//@ rfi		= word ptr -0Ah		; real_t
//@ var_8		= word ptr -8
//@ var_6		= word ptr -6
//@ sa		= word ptr -4		; int16_t
//@ ca		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_MAPML.PAS" 1209
//@ 		mov	ax, CurFI	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	[bp+rfi], ax	; real_t
//@ 		mov	[bp+var_8], bx
//@ 		mov	[bp+var_6], dx
//@ ; #line	"CS_MAPML.PAS" 1210
//@ 		mov	ax, [bp+rfi]	; real_t
//@ 		mov	bx, [bp+var_8]
//@ 		mov	dx, [bp+var_6]
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+ca], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1211
//@ 		mov	ax, [bp+rfi]	; real_t
//@ 		mov	bx, [bp+var_8]
//@ 		mov	dx, [bp+var_6]
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+sa], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1213
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1214
//@ 		mov	di, 3200h
//@ ; #line	"CS_MAPML.PAS" 1215
//@ 		mov	si, 3800h
//@ ; #line	"CS_MAPML.PAS" 1216
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1218
//@ 
//@ loc_16BB5:				; CODE XREF: RotateModelASM+E4j
//@ 		mov	ax, es:[di]
//@ 		imul	[bp+ca]		; int16_t
//@ 		mov	ax, es:[di+2]
//@ ; #line	"CS_MAPML.PAS" 1219
//@ 		mov	bx, dx
//@ 		imul	[bp+sa]		; int16_t
//@ 		add	bx, OBJx	; int16_t
//@ 		sub	bx, dx		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 1220
//@ 		mov	es:[si], bx
//@ ; #line	"CS_MAPML.PAS" 1222
//@ 		mov	ax, es:[di+2]
//@ 		imul	[bp+ca]		; int16_t
//@ 		mov	ax, es:[di]
//@ ; #line	"CS_MAPML.PAS" 1223
//@ 		mov	bx, dx
//@ 		imul	[bp+sa]		; int16_t
//@ 		add	bx, OBJy	; int16_t
//@ 		add	bx, dx		; Add
//@ ; #line	"CS_MAPML.PAS" 1224
//@ 		cmp	YWrap, 1	; bool
//@ 		jnz	short loc_16BF6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1225
//@ 		cmp	bx, 0FFC0h	; Compare Two Operands
//@ 		jl	short loc_16BF6	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 1226
//@ 		cmp	bx, 50h	; 'P'   ; Compare Two Operands
//@ 		jg	short loc_16BF6	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	bx, 50h	; 'P'
//@ ; #line	"CS_MAPML.PAS" 1228
//@ 
//@ loc_16BF6:				; CODE XREF: RotateModelASM+C2j
//@ 					; RotateModelASM+C7j ...
//@ 		mov	es:[si+2], bx
//@ ; #line	"CS_MAPML.PAS" 1230
//@ 		mov	ax, es:[di+4]
//@ 		add	di, 6		; Add
//@ 		mov	es:[si+4], ax
//@ 		add	si, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1231
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_16BB5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1233
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ RotateModelASM	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1239
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RotateModelASM_HiDet proc far		; CODE XREF: Draw3DObject+EFP
//@ 
//@ fxtabptr	= word ptr -16h		; uint16_t
//@ rfi		= word ptr -14h		; real_t
//@ var_12		= word ptr -12h
//@ var_10		= word ptr -10h
//@ sa		= word ptr -0Eh		; int16_t
//@ ca		= word ptr -0Ch		; int16_t
//@ lsa		= word ptr -0Ah		; int16_t
//@ lca		= word ptr -8		; int16_t
//@ y1		= word ptr -6		; int16_t
//@ x1		= word ptr -4		; int16_t
//@ x		= word ptr -2		; int16_t
//@ 
//@ 		enter	16h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_MAPML.PAS" 1240
//@ 		mov	ax, LocalFi	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	[bp+rfi], ax	; real_t
//@ 		mov	[bp+var_12], bx
//@ 		mov	[bp+var_10], dx
//@ ; #line	"CS_MAPML.PAS" 1241
//@ 		mov	ax, [bp+rfi]	; real_t
//@ 		mov	bx, [bp+var_12]
//@ 		mov	dx, [bp+var_10]
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+lca], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1242
//@ 		mov	ax, [bp+rfi]	; real_t
//@ 		mov	bx, [bp+var_12]
//@ 		mov	dx, [bp+var_10]
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+lsa], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1244
//@ 		mov	ax, EHFi	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	[bp+rfi], ax	; real_t
//@ 		mov	[bp+var_12], bx
//@ 		mov	[bp+var_10], dx
//@ ; #line	"CS_MAPML.PAS" 1245
//@ 		mov	ax, [bp+rfi]	; real_t
//@ 		mov	bx, [bp+var_12]
//@ 		mov	dx, [bp+var_10]
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7FFEh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+ca], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1246
//@ 		mov	ax, [bp+rfi]	; real_t
//@ 		mov	bx, [bp+var_12]
//@ 		mov	dx, [bp+var_10]
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7FFEh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+sa], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1247
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, GlobX	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	[bp+x1], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1248
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, GlobY	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1250
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1251
//@ 		mov	di, 3200h
//@ ; #line	"CS_MAPML.PAS" 1252
//@ 		mov	si, 3800h
//@ ; #line	"CS_MAPML.PAS" 1253
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1256
//@ 
//@ loc_16D36:				; CODE XREF: RotateModelASM_HiDet+16Dj
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		imul	[bp+lca]	; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1257
//@ 		mov	ax, es:[di+2]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		imul	[bp+lsa]	; int16_t
//@ 		sub	bx, dx		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 1258
//@ 		mov	es:[si], bx
//@ ; #line	"CS_MAPML.PAS" 1260
//@ 		mov	ax, es:[di+2]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		imul	[bp+lca]	; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1261
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		imul	[bp+lsa]	; int16_t
//@ 		add	bx, dx		; Add
//@ ; #line	"CS_MAPML.PAS" 1262
//@ 		mov	es:[si+2], bx
//@ ; #line	"CS_MAPML.PAS" 1264
//@ 		mov	ax, es:[di+4]
//@ 		add	di, 6		; Add
//@ 		mov	es:[si+4], ax
//@ 		add	si, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1265
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_16D36	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1268
//@ 		mov	cx, FCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1269
//@ 		xor	si, si		; Logical Exclusive OR
//@ ; #line	"CS_MAPML.PAS" 1270
//@ 		mov	bx, 6AAh
//@ 		mov	[bp+fxtabptr], bx ; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1271
//@ 		mov	XTabUpdated, 1	; bool
//@ ; #line	"CS_MAPML.PAS" 1272
//@ 		mov	ax, DepthD	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 1AC6h	; Add
//@ 		mov	DepthD,	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1274
//@ 
//@ loc_16D99:				; CODE XREF: RotateModelASM_HiDet+20Dj
//@ 		mov	ax, es:[si]
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		add	di, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1275
//@ 		mov	ax, es:[di+3800h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+x],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1276
//@ 		mov	ax, es:[di+3802h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	y, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1278
//@ 		mov	ax, es:[si+4]
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		add	di, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1279
//@ 		mov	ax, es:[di+3800h]
//@ 		sub	[bp+x],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1280
//@ 		mov	ax, es:[di+3802h]
//@ 		sub	y, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1283
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		add	ax, GlobX	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 1284
//@ 		mov	bx, y		; int16_t
//@ 		sar	bx, 4		; Shift	Arithmetic Right
//@ 		add	bx, GlobY	; int16_t
//@ 		shr	bx, 6		; Shift	Logical	Right
//@ 		shl	bx, 8		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1285
//@ 		add	bx, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1286
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1287
//@ 		mov	dx, es:[bx]
//@ 		shl	dx, 8		; Shift	Logical	Left
//@ 		add	dx, DepthD	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1288
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1289
//@ 		mov	bx, [bp+fxtabptr] ; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1290
//@ 		mov	[bx], dx
//@ ; #line	"CS_MAPML.PAS" 1291
//@ 		add	[bp+fxtabptr], 2 ; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1292
//@ 		add	si, 20h	; ' '   ; Add
//@ ; #line	"CS_MAPML.PAS" 1293
//@ 		dec	cx		; Decrement by 1
//@ 		jz	short loc_16E1D	; Jump if Zero (ZF=1)
//@ 		jmp	loc_16D99	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1296
//@ 
//@ loc_16E1D:				; CODE XREF: RotateModelASM_HiDet+20Bj
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1297
//@ 		mov	si, 3800h
//@ ; #line	"CS_MAPML.PAS" 1299
//@ 
//@ loc_16E24:				; CODE XREF: RotateModelASM_HiDet+275j
//@ 		mov	ax, es:[si]
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		add	ax, [bp+x1]	; int16_t
//@ 		imul	[bp+ca]		; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1300
//@ 		mov	ax, es:[si+2]
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		add	ax, [bp+y1]	; int16_t
//@ 		imul	[bp+sa]		; int16_t
//@ 		sub	bx, dx		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 1301
//@ 		mov	[bp+x],	bx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1303
//@ 		mov	ax, es:[si+2]
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		add	ax, [bp+y1]	; int16_t
//@ 		imul	[bp+ca]		; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1304
//@ 		mov	ax, es:[si]
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		add	ax, [bp+x1]	; int16_t
//@ 		imul	[bp+sa]		; int16_t
//@ 		add	bx, dx		; Add
//@ ; #line	"CS_MAPML.PAS" 1305
//@ 		add	bx, 20h	; ' '   ; Add
//@ ; #line	"CS_MAPML.PAS" 1306
//@ 		cmp	YWrap, 1	; bool
//@ 		jnz	short loc_16E74	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1307
//@ 		cmp	bx, 0FFC0h	; Compare Two Operands
//@ 		jl	short loc_16E74	; Jump if Less (SF!=OF)
//@ 		cmp	bx, 50h	; 'P'   ; Compare Two Operands
//@ 		jg	short loc_16E74	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	bx, 50h	; 'P'
//@ ; #line	"CS_MAPML.PAS" 1308
//@ 
//@ loc_16E74:				; CODE XREF: RotateModelASM_HiDet+258j
//@ 					; RotateModelASM_HiDet+25Dj ...
//@ 		mov	es:[si+2], bx
//@ ; #line	"CS_MAPML.PAS" 1309
//@ 		mov	bx, [bp+x]	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1310
//@ 		mov	es:[si], bx
//@ ; #line	"CS_MAPML.PAS" 1312
//@ 		add	si, 6		; Add
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_16E24	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1314
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ RotateModelASM_HiDet endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1320
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RotateModelASM_XZ proc far		; CODE XREF: Draw3DObject+C0P
//@ 
//@ sax		= word ptr -0Eh		; int16_t
//@ cax		= word ptr -0Ch		; int16_t
//@ saz		= word ptr -0Ah		; int16_t
//@ caz		= word ptr -8		; int16_t
//@ z		= word ptr -6		; int16_t
//@ y		= word ptr -4		; int16_t
//@ x		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_MAPML.PAS" 1321
//@ 		mov	ax, XFi		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 8Ch	; 'Œ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+cax], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1322
//@ 		mov	ax, XFi		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 8Ch	; 'Œ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4000h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+sax], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1323
//@ 		mov	ax, CurFI	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+caz], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1324
//@ 		mov	ax, CurFI	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 91h	; '‘'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 8Fh	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+saz], ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1326
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1327
//@ 		mov	di, 3200h
//@ ; #line	"CS_MAPML.PAS" 1328
//@ 		mov	si, 3800h
//@ ; #line	"CS_MAPML.PAS" 1329
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1331
//@ 
//@ loc_16FBD:				; CODE XREF: RotateModelASM_XZ+1BFj
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+x],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1332
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+y],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1333
//@ 		mov	ax, es:[di+4]
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1335
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1336
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		imul	[bp+cax]	; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1337
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		imul	[bp+sax]	; int16_t
//@ 		sub	bx, dx		; Integer Subtraction
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	[bp+y],	bx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1339
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		imul	[bp+cax]	; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1340
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		imul	[bp+sax]	; int16_t
//@ 		add	bx, dx		; Add
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	[bp+z],	bx	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1341
//@ 		mov	ax, Xfiz0	; int16_t
//@ 		add	[bp+z],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1343
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		imul	[bp+caz]	; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1344
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		imul	[bp+saz]	; int16_t
//@ 		sub	bx, dx		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 1345
//@ 		add	bx, OBJx	; int16_t
//@ 		mov	es:[si], bx
//@ ; #line	"CS_MAPML.PAS" 1346
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		imul	[bp+caz]	; int16_t
//@ 		mov	bx, dx
//@ ; #line	"CS_MAPML.PAS" 1347
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		imul	[bp+saz]	; int16_t
//@ 		add	bx, dx		; Add
//@ ; #line	"CS_MAPML.PAS" 1348
//@ 		add	bx, OBJy	; int16_t
//@ 		mov	es:[si+2], bx
//@ ; #line	"CS_MAPML.PAS" 1350
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		add	di, 6		; Add
//@ 		mov	es:[si+4], ax
//@ 		add	si, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1352
//@ 		dec	cx		; Decrement by 1
//@ 		jz	short locret_17048 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_16FBD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1355
//@ 
//@ locret_17048:				; CODE XREF: RotateModelASM_XZ+1BDj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ RotateModelASM_XZ endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1368
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ ProcToScrASM_Far proc far		; CODE XREF: Draw3DObject+59DP
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1369
//@ 		mov	di, 3800h
//@ ; #line	"CS_MAPML.PAS" 1370
//@ 		mov	si, 4400h
//@ ; #line	"CS_MAPML.PAS" 1371
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1372
//@ 
//@ loc_17059:				; CODE XREF: ProcToScrASM_Far+48j
//@ 		mov	bx, es:[di+2]
//@ 		cmp	bx, 28h	; '('   ; Compare Two Operands
//@ 		jg	short loc_17065	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	bx, 28h	; '('
//@ ; #line	"CS_MAPML.PAS" 1373
//@ 
//@ loc_17065:				; CODE XREF: ProcToScrASM_Far+16j
//@ 		mov	ax, es:[di]
//@ 		imul	WallW		; uint16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_MAPML.PAS" 1374
//@ 		add	ax, VideoCX	; uint16_t
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 1375
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, OBJz	; int16_t
//@ 		imul	WallH4		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_MAPML.PAS" 1376
//@ 		add	ax, WinCY	; uint16_t
//@ 		mov	es:[si+2], ax
//@ ; #line	"CS_MAPML.PAS" 1377
//@ 		add	si, 4		; Add
//@ 		add	di, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1378
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_17059	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1379
//@ 		retf			; Return Far from Procedure
//@ ProcToScrASM_Far endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1384
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ ProcToScrMinMax	proc far		; CODE XREF: Draw3DObject:loc_17F11P
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1385
//@ 		mov	Lx1, 7D0h	; int16_t
//@ 		mov	Lx2, 0F830h	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1386
//@ 		mov	di, 3800h
//@ ; #line	"CS_MAPML.PAS" 1387
//@ 		mov	si, 4400h
//@ ; #line	"CS_MAPML.PAS" 1388
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1389
//@ 
//@ loc_170B0:				; CODE XREF: ProcToScrMinMax+55j
//@ 		mov	bx, es:[di+2]
//@ 		cmp	bx, 28h	; '('   ; Compare Two Operands
//@ 		jl	short loc_170E3	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 1390
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 1391
//@ 		cmp	bx, ax		; Compare Two Operands
//@ 		jl	short loc_170E3	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 1393
//@ 		mov	ax, es:[di]
//@ 		imul	WallW		; uint16_t
//@ 		idiv	bx		; Signed Divide
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 1394
//@ 		cmp	Lx1, ax		; int16_t
//@ 		jle	short loc_170DA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	Lx1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1395
//@ 
//@ loc_170DA:				; CODE XREF: ProcToScrMinMax+40j
//@ 		cmp	Lx2, ax		; int16_t
//@ 		jge	short loc_170E3	; Jump if Greater or Equal (SF=OF)
//@ 		mov	Lx2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1398
//@ 
//@ loc_170E3:				; CODE XREF: ProcToScrMinMax+22j
//@ 					; ProcToScrMinMax+2Ej ...
//@ 		add	si, 4		; Add
//@ 		add	di, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1399
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_170B0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1400
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		add	Lx1, ax		; int16_t
//@ 		add	Lx2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1402
//@ 		mov	bx, OBJy	; int16_t
//@ 		sar	bx, 1		; Shift	Arithmetic Right
//@ 		sub	bx, 100h	; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 1403
//@ 		cmp	bx, 40h	; '@'   ; Compare Two Operands
//@ 		jg	short loc_17109	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	bx, 40h	; '@'
//@ ; #line	"CS_MAPML.PAS" 1404
//@ 
//@ loc_17109:				; CODE XREF: ProcToScrMinMax+6Fj
//@ 		mov	ax, Hz2		; uint16_t
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		imul	WallH		; uint16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	CurDH, ax	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1405
//@ 		retf			; Return Far from Procedure
//@ ProcToScrMinMax	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1410
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ ProcToScrASM_Clip proc far		; CODE XREF: Draw3DObject:loc_183DDP
//@ 					; Show3DObject+D3P
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1411
//@ 		mov	di, 3800h
//@ ; #line	"CS_MAPML.PAS" 1412
//@ 		mov	si, 4400h
//@ ; #line	"CS_MAPML.PAS" 1413
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1414
//@ 
//@ loc_17127:				; CODE XREF: ProcToScrASM_Clip+93j
//@ 		mov	bx, es:[di+2]
//@ 		cmp	bx, 28h	; '('   ; Compare Two Operands
//@ 		jl	short loc_1713D	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 1415
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 1416
//@ 		cmp	bx, ax		; Compare Two Operands
//@ 		jg	short loc_1714C	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1417
//@ 
//@ loc_1713D:				; CODE XREF: ProcToScrASM_Clip+16j
//@ 		mov	ax, 7FFFh
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 1418
//@ 		mov	ax, 0F830h
//@ 		mov	es:[di+2], ax
//@ 		jmp	short loc_171A2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1420
//@ 
//@ loc_1714C:				; CODE XREF: ProcToScrASM_Clip+23j
//@ 		mov	ax, es:[di]
//@ 		imul	WallW		; uint16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_MAPML.PAS" 1421
//@ 		cmp	ax, 258h	; Compare Two Operands
//@ 		jle	short loc_17165	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	ax, 258h	; Integer Subtraction
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		add	bx, ax		; Add
//@ 		mov	ax, 258h
//@ ; #line	"CS_MAPML.PAS" 1422
//@ 
//@ loc_17165:				; CODE XREF: ProcToScrASM_Clip+40j
//@ 		cmp	ax, 0FDA8h	; Compare Two Operands
//@ 		jge	short loc_17175	; Jump if Greater or Equal (SF=OF)
//@ 		add	ax, 258h	; Add
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		mov	ax, 0FDA8h
//@ ; #line	"CS_MAPML.PAS" 1424
//@ 
//@ loc_17175:				; CODE XREF: ProcToScrASM_Clip+50j
//@ 		add	ax, VideoCX	; uint16_t
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 1426
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, OBJz	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1427
//@ 		imul	WallH4		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		add	ax, WinCY	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1429
//@ 		cmp	ax, 258h	; Compare Two Operands
//@ 		jle	short loc_17196	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, 258h
//@ ; #line	"CS_MAPML.PAS" 1430
//@ 
//@ loc_17196:				; CODE XREF: ProcToScrASM_Clip+79j
//@ 		cmp	ax, 0FF4Ch	; Compare Two Operands
//@ 		jge	short loc_1719E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, 0FF4Ch
//@ ; #line	"CS_MAPML.PAS" 1432
//@ 
//@ loc_1719E:				; CODE XREF: ProcToScrASM_Clip+81j
//@ 		mov	es:[si+2], ax
//@ ; #line	"CS_MAPML.PAS" 1433
//@ 
//@ loc_171A2:				; CODE XREF: ProcToScrASM_Clip+32j
//@ 		add	si, 4		; Add
//@ 		add	di, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1434
//@ 		dec	cx		; Decrement by 1
//@ 		jz	short locret_171AE ; Jump if Zero (ZF=1)
//@ 		jmp	loc_17127	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1435
//@ 
//@ locret_171AE:				; CODE XREF: ProcToScrASM_Clip+91j
//@ 		retf			; Return Far from Procedure
//@ ProcToScrASM_Clip endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1440
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ ProcToScrASM_Clip_hi proc far		; CODE XREF: DrawHi3D+24AP
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1441
//@ 		mov	di, 3800h
//@ ; #line	"CS_MAPML.PAS" 1442
//@ 		mov	si, 4400h
//@ ; #line	"CS_MAPML.PAS" 1443
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1444
//@ 
//@ loc_171BE:				; CODE XREF: ProcToScrASM_Clip_hi+62j
//@ 		mov	bx, es:[di+2]
//@ 		cmp	bx, 0B4h ; '´'  ; Compare Two Operands
//@ 		jl	short loc_171D5	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 1445
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		shr	ax, 0		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 1446
//@ 		cmp	bx, ax		; Compare Two Operands
//@ 		jg	short loc_171E4	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1447
//@ 
//@ loc_171D5:				; CODE XREF: ProcToScrASM_Clip_hi+17j
//@ 		mov	ax, 7FFFh
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 1448
//@ 		mov	ax, 0F830h
//@ 		mov	es:[di+2], ax
//@ 		jmp	short loc_1720A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1450
//@ 
//@ loc_171E4:				; CODE XREF: ProcToScrASM_Clip_hi+24j
//@ 		mov	ax, es:[di]
//@ 		imul	WallWhi		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		add	ax, VideoCX	; uint16_t
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 1452
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, OBJz	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1453
//@ 		imul	WallHhi		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ 		add	ax, WinCY	; uint16_t
//@ 		mov	es:[si+2], ax
//@ ; #line	"CS_MAPML.PAS" 1454
//@ 
//@ loc_1720A:				; CODE XREF: ProcToScrASM_Clip_hi+33j
//@ 		add	si, 4		; Add
//@ 		add	di, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 1455
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_171BE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1456
//@ 		retf			; Return Far from Procedure
//@ ProcToScrASM_Clip_hi endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1476
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BuildTreeAsm_Far proc far		; CODE XREF: Draw3DObject:loc_183D6P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 1478
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1479
//@ 		mov	Current, 0FFFFh	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1480
//@ 		mov	n, 0		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1481
//@ 		mov	cx, FCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1483
//@ 
//@ loc_1722C:				; CODE XREF: BuildTreeAsm_Far+12Dj
//@ 		mov	di, n		; int16_t
//@ 		push	cx
//@ 		shl	di, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1485
//@ 		mov	ax, es:[di]
//@ 		mov	si, ax
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, ax		; Add
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1486
//@ 		mov	dx, es:[si+3802h]
//@ ; #line	"CS_MAPML.PAS" 1488
//@ 		mov	ax, es:[di+4]
//@ 		mov	si, ax
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, ax		; Add
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1489
//@ 		add	dx, es:[si+3802h] ; Add
//@ ; #line	"CS_MAPML.PAS" 1492
//@ 		mov	al, es:[di+1Ch]
//@ 		and	al, DrawMask	; uint8_t
//@ 		jz	short loc_17264	; Jump if Zero (ZF=1)
//@ 		jmp	loc_17339	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1494
//@ 
//@ loc_17264:				; CODE XREF: BuildTreeAsm_Far+4Bj
//@ 		mov	es:[di+1Ah], dx
//@ ; #line	"CS_MAPML.PAS" 1495
//@ 		mov	al, es:[di+1Dh]
//@ 		test	al, 1		; Logical Compare
//@ 		jnz	short loc_172C1	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1499
//@ 		mov	si, es:[di]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1500
//@ 		mov	cx, es:[si]
//@ 		mov	bx, es:[si+2]
//@ ; #line	"CS_MAPML.PAS" 1502
//@ 		mov	si, es:[di+2]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1503
//@ 		mov	ax, es:[si]
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		mov	ux, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1504
//@ 		mov	ax, es:[si+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		mov	uy, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1506
//@ 		mov	si, es:[di+4]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1507
//@ 		mov	ax, es:[si]
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		imul	uy		; int16_t
//@ 		mov	cx, ax
//@ ; #line	"CS_MAPML.PAS" 1508
//@ 		mov	ax, es:[si+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		imul	ux		; int16_t
//@ 		sub	ax, cx		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 1510
//@ 		js	short loc_17339	; Jump if Sign (SF=1)
//@ ; #line	"CS_MAPML.PAS" 1513
//@ 
//@ loc_172C1:				; CODE XREF: BuildTreeAsm_Far+5Aj
//@ 		mov	word ptr es:[di+18h], 0FFFFh
//@ ; #line	"CS_MAPML.PAS" 1515
//@ 		cmp	Current, 0FFFFh	; int16_t
//@ 		jnz	short loc_172D6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1516
//@ 		mov	ax, n		; int16_t
//@ 		mov	Current, ax	; int16_t
//@ 		jmp	short loc_17339	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1518
//@ 
//@ loc_172D6:				; CODE XREF: BuildTreeAsm_Far+B8j
//@ 		mov	si, Current	; int16_t
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1519
//@ 		mov	ax, es:[si+1Ah]
//@ ; #line	"CS_MAPML.PAS" 1520
//@ 		mov	dx, es:[di+1Ah]
//@ ; #line	"CS_MAPML.PAS" 1521
//@ 		cmp	dx, ax		; Compare Two Operands
//@ 		jb	short loc_172F8	; Jump if Below	(CF=1)
//@ ; #line	"CS_MAPML.PAS" 1522
//@ 		mov	ax, Current	; int16_t
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CS_MAPML.PAS" 1523
//@ 		mov	ax, n		; int16_t
//@ 		mov	Current, ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1524
//@ 		jmp	short loc_17339	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1527
//@ 
//@ loc_172F8:				; CODE XREF: BuildTreeAsm_Far+D3j
//@ 		mov	ax, Current	; int16_t
//@ 		mov	np, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1528
//@ 		mov	si, np		; int16_t
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1529
//@ 
//@ loc_17305:				; CODE XREF: BuildTreeAsm_Far+112j
//@ 		mov	cx, si
//@ ; #line	"CS_MAPML.PAS" 1530
//@ 		mov	ax, es:[si+18h]
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jz	short loc_17328	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1532
//@ 		mov	npp, ax		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	si, ax
//@ ; #line	"CS_MAPML.PAS" 1534
//@ 		mov	ax, es:[si+1Ah]
//@ 		cmp	dx, ax		; Compare Two Operands
//@ 		ja	short loc_17328	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1535
//@ 		mov	ax, npp		; int16_t
//@ 		mov	np, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1536
//@ 		jmp	short loc_17305	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1538
//@ 
//@ loc_17328:				; CODE XREF: BuildTreeAsm_Far+FAj
//@ 					; BuildTreeAsm_Far+10Aj
//@ 		mov	si, cx
//@ ; #line	"CS_MAPML.PAS" 1539
//@ 		mov	ax, es:[si+18h]
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CS_MAPML.PAS" 1540
//@ 		mov	ax, n		; int16_t
//@ 		mov	es:[si+18h], ax
//@ ; #line	"CS_MAPML.PAS" 1543
//@ 
//@ loc_17339:				; CODE XREF: BuildTreeAsm_Far+4Dj
//@ 					; BuildTreeAsm_Far+ABj	...
//@ 		inc	n		; int16_t
//@ 		pop	cx
//@ 		dec	cx		; Decrement by 1
//@ 		jz	short locret_17344 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1722C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1546
//@ 
//@ locret_17344:				; CODE XREF: BuildTreeAsm_Far+12Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ BuildTreeAsm_Far endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1551
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BuildTreeAsm_NoSort proc far		; CODE XREF: Draw3DObject+5B9P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 1553
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1554
//@ 		mov	Current, 0FFFFh	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1555
//@ 		mov	n, 0		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1556
//@ 		mov	cx, FCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1558
//@ 
//@ loc_1735E:				; CODE XREF: BuildTreeAsm_NoSort+D9j
//@ 		mov	di, n		; int16_t
//@ 		push	cx
//@ 		shl	di, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1560
//@ 		mov	ax, es:[di]
//@ 		mov	si, ax
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, ax		; Add
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1561
//@ 		mov	dx, es:[si+3802h]
//@ ; #line	"CS_MAPML.PAS" 1562
//@ 		mov	ax, es:[di+4]
//@ 		mov	si, ax
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, ax		; Add
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1563
//@ 		add	dx, es:[si+3802h] ; Add
//@ ; #line	"CS_MAPML.PAS" 1565
//@ 		mov	al, es:[di+1Ch]
//@ 		and	al, DrawMask	; uint8_t
//@ 		jz	short loc_17396	; Jump if Zero (ZF=1)
//@ 		jmp	loc_17417	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1567
//@ 
//@ loc_17396:				; CODE XREF: BuildTreeAsm_NoSort+4Bj
//@ 		mov	es:[di+1Ah], dx
//@ ; #line	"CS_MAPML.PAS" 1568
//@ 		mov	al, es:[di+1Dh]
//@ 		test	al, 1		; Logical Compare
//@ 		jnz	short loc_173F3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1572
//@ 		mov	si, es:[di]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1573
//@ 		mov	cx, es:[si]
//@ 		mov	bx, es:[si+2]
//@ ; #line	"CS_MAPML.PAS" 1575
//@ 		mov	si, es:[di+2]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1576
//@ 		mov	ax, es:[si]
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		mov	ux, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1577
//@ 		mov	ax, es:[si+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		mov	uy, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1579
//@ 		mov	si, es:[di+4]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1580
//@ 		mov	ax, es:[si]
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		imul	uy		; int16_t
//@ 		mov	cx, ax
//@ ; #line	"CS_MAPML.PAS" 1581
//@ 		mov	ax, es:[si+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		imul	ux		; int16_t
//@ 		sub	ax, cx		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 1583
//@ 		js	short loc_17417	; Jump if Sign (SF=1)
//@ ; #line	"CS_MAPML.PAS" 1586
//@ 
//@ loc_173F3:				; CODE XREF: BuildTreeAsm_NoSort+5Aj
//@ 		mov	word ptr es:[di+18h], 0FFFFh
//@ ; #line	"CS_MAPML.PAS" 1588
//@ 		cmp	Current, 0FFFFh	; int16_t
//@ 		jnz	short loc_17408	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1589
//@ 		mov	ax, n		; int16_t
//@ 		mov	Current, ax	; int16_t
//@ 		jmp	short loc_17417	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1591
//@ 
//@ loc_17408:				; CODE XREF: BuildTreeAsm_NoSort+B8j
//@ 		mov	ax, Current	; int16_t
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CS_MAPML.PAS" 1592
//@ 		mov	ax, n		; int16_t
//@ 		mov	Current, ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1593
//@ 		jmp	short $+2	; Jump
//@ ; #line	"CS_MAPML.PAS" 1596
//@ 
//@ loc_17417:				; CODE XREF: BuildTreeAsm_NoSort+4Dj
//@ 					; BuildTreeAsm_NoSort+ABj ...
//@ 		inc	n		; int16_t
//@ 		pop	cx
//@ 		dec	cx		; Decrement by 1
//@ 		jz	short locret_17422 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1735E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1599
//@ 
//@ locret_17422:				; CODE XREF: BuildTreeAsm_NoSort+D7j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ BuildTreeAsm_NoSort endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1605
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BuildTreeAsm_Clip proc far		; CODE XREF: Draw3DObject+5CCP
//@ 					; Show3DObject:loc_1856CP ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 1607
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 1608
//@ 		mov	Current, 0FFFFh	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1609
//@ 		mov	n, 0		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1610
//@ 		mov	cx, FCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1612
//@ 
//@ loc_1743C:				; CODE XREF: BuildTreeAsm_Clip+1DEj
//@ 		mov	di, n		; int16_t
//@ 		push	cx
//@ 		shl	di, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1614
//@ 		mov	bl, 6
//@ ; #line	"CS_MAPML.PAS" 1615
//@ 		mov	ax, es:[di+2]
//@ 		mul	bl		; Unsigned Multiplication of AL	or AX
//@ 		add	ax, 3802h	; Add
//@ 		mov	si, ax
//@ 		mov	dx, es:[si]
//@ ; #line	"CS_MAPML.PAS" 1616
//@ 		mov	ax, es:[di+6]
//@ 		mul	bl		; Unsigned Multiplication of AL	or AX
//@ 		add	ax, 3802h	; Add
//@ 		mov	si, ax
//@ 		add	dx, es:[si]	; Add
//@ ; #line	"CS_MAPML.PAS" 1617
//@ 		mov	es:[di+1Ah], dx
//@ 		cmp	dx, 50h	; 'P'   ; Compare Two Operands
//@ 		jge	short loc_1746E	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1619
//@ 
//@ loc_1746E:				; CODE XREF: BuildTreeAsm_Clip+45j
//@ 		mov	ax, es:[di]
//@ 		mov	si, ax
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, ax		; Add
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1620
//@ 		mov	dx, es:[si+3802h]
//@ ; #line	"CS_MAPML.PAS" 1622
//@ 		mov	ax, es:[di+4]
//@ 		mov	si, ax
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, ax		; Add
//@ 		add	si, ax		; Add
//@ ; #line	"CS_MAPML.PAS" 1623
//@ 		add	dx, es:[si+3802h] ; Add
//@ ; #line	"CS_MAPML.PAS" 1626
//@ 		mov	al, es:[di+1Ch]
//@ 		and	al, DrawMask	; uint8_t
//@ 		jz	short loc_1749E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1628
//@ 
//@ loc_1749E:				; CODE XREF: BuildTreeAsm_Clip+75j
//@ 		mov	es:[di+1Ah], dx
//@ ; #line	"CS_MAPML.PAS" 1629
//@ 		mov	al, es:[di+1Dh]
//@ 		test	al, 1		; Logical Compare
//@ 		jz	short loc_174FC	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1631
//@ 		mov	si, es:[di]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		mov	ax, es:[si+4400h]
//@ ; #line	"CS_MAPML.PAS" 1632
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jnz	short loc_174BD	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1633
//@ 
//@ loc_174BD:				; CODE XREF: BuildTreeAsm_Clip+94j
//@ 		mov	si, es:[di+2]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		mov	ax, es:[si+4400h]
//@ ; #line	"CS_MAPML.PAS" 1634
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jnz	short loc_174D1	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1635
//@ 
//@ loc_174D1:				; CODE XREF: BuildTreeAsm_Clip+A8j
//@ 		mov	si, es:[di+4]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		mov	ax, es:[si+4400h]
//@ ; #line	"CS_MAPML.PAS" 1636
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jnz	short loc_174E5	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1637
//@ 
//@ loc_174E5:				; CODE XREF: BuildTreeAsm_Clip+BCj
//@ 		mov	si, es:[di+6]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		mov	ax, es:[si+4400h]
//@ ; #line	"CS_MAPML.PAS" 1638
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jnz	short loc_174F9	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1639
//@ 
//@ loc_174F9:				; CODE XREF: BuildTreeAsm_Clip+D0j
//@ 		jmp	loc_17582	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1643
//@ 
//@ loc_174FC:				; CODE XREF: BuildTreeAsm_Clip+84j
//@ 		mov	si, es:[di]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1644
//@ 		mov	cx, es:[si]
//@ 		mov	bx, es:[si+2]
//@ 		cmp	cx, 7FFFh	; Compare Two Operands
//@ 		jnz	short loc_17516	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1646
//@ 
//@ loc_17516:				; CODE XREF: BuildTreeAsm_Clip+EDj
//@ 		mov	si, es:[di+2]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1647
//@ 		mov	ax, es:[si]
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jnz	short loc_1752C	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1648
//@ 
//@ loc_1752C:				; CODE XREF: BuildTreeAsm_Clip+103j
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		mov	ux, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1649
//@ 		mov	ax, es:[si+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		mov	uy, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1651
//@ 		mov	si, es:[di+4]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		add	si, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1652
//@ 		mov	ax, es:[si]
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jnz	short loc_17550	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1653
//@ 
//@ loc_17550:				; CODE XREF: BuildTreeAsm_Clip+127j
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		imul	uy		; int16_t
//@ 		mov	cx, ax
//@ 		mov	_dx, dx		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1654
//@ 		mov	ax, es:[si+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		imul	ux		; int16_t
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, _dx		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1656
//@ 		jns	short loc_17571	; Jump if Not Sign (SF=0)
//@ 		jmp	loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1658
//@ 
//@ loc_17571:				; CODE XREF: BuildTreeAsm_Clip+148j
//@ 		mov	si, es:[di+6]
//@ 		shl	si, 2		; Shift	Logical	Left
//@ 		mov	ax, es:[si+4400h]
//@ ; #line	"CS_MAPML.PAS" 1659
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jz	short loc_175FA	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1662
//@ 
//@ loc_17582:				; CODE XREF: BuildTreeAsm_Clip:loc_174F9j
//@ 		mov	word ptr es:[di+18h], 0FFFFh
//@ ; #line	"CS_MAPML.PAS" 1664
//@ 		cmp	Current, 0FFFFh	; int16_t
//@ 		jnz	short loc_17597	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1665
//@ 		mov	ax, n		; int16_t
//@ 		mov	Current, ax	; int16_t
//@ 		jmp	short loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1667
//@ 
//@ loc_17597:				; CODE XREF: BuildTreeAsm_Clip+169j
//@ 		mov	si, Current	; int16_t
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1668
//@ 		mov	ax, es:[si+1Ah]
//@ ; #line	"CS_MAPML.PAS" 1669
//@ 		mov	dx, es:[di+1Ah]
//@ ; #line	"CS_MAPML.PAS" 1670
//@ 		cmp	dx, ax		; Compare Two Operands
//@ 		jb	short loc_175B9	; Jump if Below	(CF=1)
//@ ; #line	"CS_MAPML.PAS" 1671
//@ 		mov	ax, Current	; int16_t
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CS_MAPML.PAS" 1672
//@ 		mov	ax, n		; int16_t
//@ 		mov	Current, ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 1673
//@ 		jmp	short loc_175FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1676
//@ 
//@ loc_175B9:				; CODE XREF: BuildTreeAsm_Clip+184j
//@ 		mov	ax, Current	; int16_t
//@ 		mov	np, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1677
//@ 		mov	si, np		; int16_t
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1678
//@ 
//@ loc_175C6:				; CODE XREF: BuildTreeAsm_Clip+1C3j
//@ 		mov	cx, si
//@ ; #line	"CS_MAPML.PAS" 1679
//@ 		mov	ax, es:[si+18h]
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jz	short loc_175E9	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1681
//@ 		mov	npp, ax		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	si, ax
//@ ; #line	"CS_MAPML.PAS" 1683
//@ 		mov	ax, es:[si+1Ah]
//@ 		cmp	dx, ax		; Compare Two Operands
//@ 		ja	short loc_175E9	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1684
//@ 		mov	ax, npp		; int16_t
//@ 		mov	np, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1685
//@ 		jmp	short loc_175C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1687
//@ 
//@ loc_175E9:				; CODE XREF: BuildTreeAsm_Clip+1ABj
//@ 					; BuildTreeAsm_Clip+1BBj
//@ 		mov	si, cx
//@ ; #line	"CS_MAPML.PAS" 1688
//@ 		mov	ax, es:[si+18h]
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CS_MAPML.PAS" 1689
//@ 		mov	ax, n		; int16_t
//@ 		mov	es:[si+18h], ax
//@ ; #line	"CS_MAPML.PAS" 1692
//@ 
//@ loc_175FA:				; CODE XREF: BuildTreeAsm_Clip+47j
//@ 					; BuildTreeAsm_Clip+77j ...
//@ 		inc	n		; int16_t
//@ 		pop	cx
//@ 		dec	cx		; Decrement by 1
//@ 		jz	short locret_17605 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1743C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1695
//@ 
//@ locret_17605:				; CODE XREF: BuildTreeAsm_Clip+1DCj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ BuildTreeAsm_Clip endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1720
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawTriFaceSh	proc far		; CODE XREF: DrawShadowFaces+9CP
//@ 		mov	di, es:[si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	bx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1721
//@ 		mov	di, es:[si+2]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1722
//@ 		mov	di, es:[si+4]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	dx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1724
//@ 		cmp	bx, cx		; Compare Two Operands
//@ 		jge	short loc_17654	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1726
//@ 		cmp	bx, dx		; Compare Two Operands
//@ 		jge	short loc_1763A	; Jump if Greater or Equal (SF=OF)
//@ 		mov	v1, 0		; uint16_t
//@ 		jmp	short loc_17640	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1727
//@ 
//@ loc_1763A:				; CODE XREF: DrawTriFaceSh+29j
//@ 		mov	v1, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1729
//@ 
//@ loc_17640:				; CODE XREF: DrawTriFaceSh+31j
//@ 		cmp	cx, dx		; Compare Two Operands
//@ 		jl	short loc_1764C	; Jump if Less (SF!=OF)
//@ 		mov	v3, 1		; uint16_t
//@ 		jmp	short loc_17652	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1730
//@ 
//@ loc_1764C:				; CODE XREF: DrawTriFaceSh+3Bj
//@ 		mov	v3, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1731
//@ 
//@ loc_17652:				; CODE XREF: DrawTriFaceSh+43j
//@ 		jmp	short loc_17678	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1734
//@ 
//@ loc_17654:				; CODE XREF: DrawTriFaceSh+25j
//@ 		cmp	cx, dx		; Compare Two Operands
//@ 		jge	short loc_17660	; Jump if Greater or Equal (SF=OF)
//@ 		mov	v1, 1		; uint16_t
//@ 		jmp	short loc_17666	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1735
//@ 
//@ loc_17660:				; CODE XREF: DrawTriFaceSh+4Fj
//@ 		mov	v1, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1737
//@ 
//@ loc_17666:				; CODE XREF: DrawTriFaceSh+57j
//@ 		cmp	bx, dx		; Compare Two Operands
//@ 		jl	short loc_17672	; Jump if Less (SF!=OF)
//@ 		mov	v3, 0		; uint16_t
//@ 		jmp	short loc_17678	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1738
//@ 
//@ loc_17672:				; CODE XREF: DrawTriFaceSh+61j
//@ 		mov	v3, 2		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1745
//@ 
//@ loc_17678:				; CODE XREF: DrawTriFaceSh:loc_17652j
//@ 					; DrawTriFaceSh+69j
//@ 		mov	ax, 0
//@ ; #line	"CS_MAPML.PAS" 1746
//@ 		cmp	ax, v1		; uint16_t
//@ 		jz	short loc_17689	; Jump if Zero (ZF=1)
//@ 		cmp	ax, v3		; uint16_t
//@ 		jz	short loc_17689	; Jump if Zero (ZF=1)
//@ 		jmp	short loc_17699	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_17689:				; CODE XREF: DrawTriFaceSh+78j
//@ 					; DrawTriFaceSh+7Ej
//@ 		inc	ax		; Increment by 1
//@ ; #line	"CS_MAPML.PAS" 1747
//@ 		cmp	ax, v1		; uint16_t
//@ 		jz	short loc_17698	; Jump if Zero (ZF=1)
//@ 		cmp	ax, v3		; uint16_t
//@ 		jz	short loc_17698	; Jump if Zero (ZF=1)
//@ 		jmp	short loc_17699	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_17698:				; CODE XREF: DrawTriFaceSh+87j
//@ 					; DrawTriFaceSh+8Dj
//@ 		inc	ax		; Increment by 1
//@ ; #line	"CS_MAPML.PAS" 1748
//@ 
//@ loc_17699:				; CODE XREF: DrawTriFaceSh+80j
//@ 					; DrawTriFaceSh+8Fj
//@ 		mov	v2, ax		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1751
//@ 		mov	bx, v1		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 1752
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1753
//@ 		mov	ax, es:[di]
//@ 		mov	x1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1754
//@ 		mov	ax, es:[di+2]
//@ 		mov	y1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1756
//@ 		mov	bx, v2		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 1757
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1758
//@ 		mov	ax, es:[di]
//@ 		mov	x2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1759
//@ 		mov	ax, es:[di+2]
//@ 		mov	y2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1761
//@ 		mov	bx, v3		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	di, es:[bx+si]
//@ ; #line	"CS_MAPML.PAS" 1762
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 1763
//@ 		mov	ax, es:[di]
//@ 		mov	x3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1764
//@ 		mov	ax, es:[di+2]
//@ 		mov	y3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1768
//@ 		mov	ax, x2		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1769
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x2		; int16_t
//@ 		mov	L2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1770
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1775
//@ 		mov	ax, y1		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1776
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1779
//@ 		mov	bx, L1		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17746	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1780
//@ 		mov	ax, y2		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1781
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1782
//@ 		mov	word ptr dy1.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy1.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1785
//@ 
//@ loc_17746:				; CODE XREF: DrawTriFaceSh+126j
//@ 		mov	bx, L2		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17766	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1786
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y2		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1787
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1788
//@ 		mov	word ptr dy2.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy2.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1792
//@ 
//@ loc_17766:				; CODE XREF: DrawTriFaceSh+146j
//@ 		mov	bx, L3		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17786	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1793
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1794
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1795
//@ 		mov	word ptr dy3.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy3.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1799
//@ 
//@ loc_17786:				; CODE XREF: DrawTriFaceSh+166j
//@ 					; DrawTriFaceSh+1B9j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x2		; int16_t
//@ 		jge	short loc_177C2	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1800
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_177A0	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_177A0	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1801
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1802
//@ 
//@ loc_177A0:				; CODE XREF: DrawTriFaceSh+18Cj
//@ 					; DrawTriFaceSh+192j
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1803
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1804
//@ 		mov	ax, word ptr dy1.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1805
//@ 		mov	ax, word ptr dy1.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1806
//@ 		inc	x1		; int16_t
//@ 		jmp	short loc_17786	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1810
//@ 
//@ loc_177C2:				; CODE XREF: DrawTriFaceSh+186j
//@ 		mov	ax, y2		; int16_t
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1812
//@ 
//@ loc_177CE:				; CODE XREF: DrawTriFaceSh+201j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x3		; int16_t
//@ 		jge	short locret_1780A ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1813
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_177E8	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_177E8	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1814
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1816
//@ 
//@ loc_177E8:				; CODE XREF: DrawTriFaceSh+1D4j
//@ 					; DrawTriFaceSh+1DAj
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1817
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1819
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1820
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1822
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1823
//@ 		jmp	short loc_177CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1825
//@ 
//@ locret_1780A:				; CODE XREF: DrawTriFaceSh+1CEj
//@ 		retf			; Return Far from Procedure
//@ DrawTriFaceSh	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1832
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawFourFaceSh1234 proc	far		; CODE XREF: DrawFourFaceSh:loc_17C43P
//@ 		mov	ax, x2		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1833
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x2		; int16_t
//@ 		mov	L2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1834
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1835
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x3		; int16_t
//@ 		mov	l4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1837
//@ 		mov	ax, y1		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1838
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1842
//@ 		mov	bx, L1		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17868	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1843
//@ 		mov	ax, y2		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1844
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1845
//@ 		mov	word ptr dy1.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy1.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1849
//@ 
//@ loc_17868:				; CODE XREF: DrawFourFaceSh1234+44j
//@ 		mov	bx, L2		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17888	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1850
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y2		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1851
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1852
//@ 		mov	word ptr dy2.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy2.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1856
//@ 
//@ loc_17888:				; CODE XREF: DrawFourFaceSh1234+64j
//@ 		mov	bx, L3		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_178A8	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1857
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1858
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1859
//@ 		mov	word ptr dy3.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy3.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1863
//@ 
//@ loc_178A8:				; CODE XREF: DrawFourFaceSh1234+84j
//@ 		mov	bx, l4		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_178C8	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1864
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y3		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1865
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1866
//@ 		mov	word ptr dy4.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy4.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1871
//@ 
//@ loc_178C8:				; CODE XREF: DrawFourFaceSh1234+A4j
//@ 					; DrawFourFaceSh1234+F7j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x2		; int16_t
//@ 		jge	short loc_17904	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1872
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_178E2	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_178E2	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1873
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1874
//@ 
//@ loc_178E2:				; CODE XREF: DrawFourFaceSh1234+CAj
//@ 					; DrawFourFaceSh1234+D0j
//@ 		mov	ax, word ptr dy1.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy1.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1875
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1876
//@ 		inc	x1		; int16_t
//@ 		jmp	short loc_178C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1880
//@ 
//@ loc_17904:				; CODE XREF: DrawFourFaceSh1234+C4j
//@ 		mov	ax, y2		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1882
//@ 
//@ loc_17910:				; CODE XREF: DrawFourFaceSh1234+13Fj
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x3		; int16_t
//@ 		jge	short loc_1794C	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1883
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_1792A	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_1792A	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1884
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1885
//@ 
//@ loc_1792A:				; CODE XREF: DrawFourFaceSh1234+112j
//@ 					; DrawFourFaceSh1234+118j
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1886
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1887
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1888
//@ 		jmp	short loc_17910	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1891
//@ 
//@ loc_1794C:				; CODE XREF: DrawFourFaceSh1234+10Cj
//@ 		mov	ax, y3		; int16_t
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1892
//@ 
//@ loc_17958:				; CODE XREF: DrawFourFaceSh1234+187j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x4		; int16_t
//@ 		jge	short locret_17994 ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1893
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_17972	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_17972	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1894
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1895
//@ 
//@ loc_17972:				; CODE XREF: DrawFourFaceSh1234+15Aj
//@ 					; DrawFourFaceSh1234+160j
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1896
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1897
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1898
//@ 		jmp	short loc_17958	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1900
//@ 
//@ locret_17994:				; CODE XREF: DrawFourFaceSh1234+154j
//@ 		retf			; Return Far from Procedure
//@ DrawFourFaceSh1234 endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1905
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawFourFaceSh1243 proc	far		; CODE XREF: DrawFourFaceSh:loc_17C4AP
//@ 		mov	ax, x2		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	L1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1906
//@ 		mov	ax, x3		; int16_t
//@ 		sub	ax, x2		; int16_t
//@ 		mov	L2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1907
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x3		; int16_t
//@ 		mov	L3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1908
//@ 		mov	ax, x4		; int16_t
//@ 		sub	ax, x1		; int16_t
//@ 		mov	l4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1910
//@ 		mov	ax, y1		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1911
//@ 		mov	word ptr Yb.DW+2, ax ; struct DWord
//@ 		mov	word ptr Yb.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1915
//@ 		mov	bx, L1		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_179F2	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1916
//@ 		mov	ax, y2		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1917
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1918
//@ 		mov	word ptr dy1.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy1.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1922
//@ 
//@ loc_179F2:				; CODE XREF: DrawFourFaceSh1243+44j
//@ 		mov	bx, L2		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17A12	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1923
//@ 		mov	ax, y3		; int16_t
//@ 		sub	ax, y2		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1924
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1925
//@ 		mov	word ptr dy2.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy2.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1929
//@ 
//@ loc_17A12:				; CODE XREF: DrawFourFaceSh1243+64j
//@ 		mov	bx, L3		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17A32	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1930
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y3		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1931
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1932
//@ 		mov	word ptr dy3.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy3.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1936
//@ 
//@ loc_17A32:				; CODE XREF: DrawFourFaceSh1243+84j
//@ 		mov	bx, l4		; int16_t
//@ 		cmp	bx, 0		; Compare Two Operands
//@ 		jz	short loc_17A52	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 1937
//@ 		mov	ax, y4		; int16_t
//@ 		sub	ax, y1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1938
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	bx, [bx+0AB0h]
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 1939
//@ 		mov	word ptr dy4.DW+2, dx ;	struct DWord
//@ 		nop			; No Operation
//@ 		mov	word ptr dy4.DW, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1944
//@ 
//@ loc_17A52:				; CODE XREF: DrawFourFaceSh1243+A4j
//@ 					; DrawFourFaceSh1243+F7j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x2		; int16_t
//@ 		jge	short loc_17A8E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1945
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_17A6C	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_17A6C	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1946
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1947
//@ 
//@ loc_17A6C:				; CODE XREF: DrawFourFaceSh1243+CAj
//@ 					; DrawFourFaceSh1243+D0j
//@ 		mov	ax, word ptr dy1.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy1.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1948
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1949
//@ 		inc	x1		; int16_t
//@ 		jmp	short loc_17A52	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1953
//@ 
//@ loc_17A8E:				; CODE XREF: DrawFourFaceSh1243+C4j
//@ 		mov	ax, y2		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1955
//@ 
//@ loc_17A9A:				; CODE XREF: DrawFourFaceSh1243+13Fj
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x3		; int16_t
//@ 		jge	short loc_17AD6	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1956
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_17AB4	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_17AB4	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1957
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1958
//@ 
//@ loc_17AB4:				; CODE XREF: DrawFourFaceSh1243+112j
//@ 					; DrawFourFaceSh1243+118j
//@ 		mov	ax, word ptr dy2.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy2.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1959
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1960
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1961
//@ 		jmp	short loc_17A9A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1965
//@ 
//@ loc_17AD6:				; CODE XREF: DrawFourFaceSh1243+10Cj
//@ 		mov	ax, y3		; int16_t
//@ 		mov	word ptr Ya.DW+2, ax ; struct DWord
//@ 		mov	word ptr Ya.DW,	8000h ;	struct DWord
//@ ; #line	"CS_MAPML.PAS" 1967
//@ 
//@ loc_17AE2:				; CODE XREF: DrawFourFaceSh1243+187j
//@ 		mov	ax, x1		; int16_t
//@ 		cmp	ax, x4		; int16_t
//@ 		jge	short locret_17B1E ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1968
//@ 		cmp	ax, WinSX	; uint16_t
//@ 		jl	short loc_17AFC	; Jump if Less (SF!=OF)
//@ 		cmp	ax, WinEX	; uint16_t
//@ 		jg	short loc_17AFC	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 1969
//@ 		call	VLineD		; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 1970
//@ 
//@ loc_17AFC:				; CODE XREF: DrawFourFaceSh1243+15Aj
//@ 					; DrawFourFaceSh1243+160j
//@ 		mov	ax, word ptr dy3.DW ; struct DWord
//@ 		add	word ptr Ya.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy3.DW+2 ;	struct DWord
//@ 		adc	word ptr Ya.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1971
//@ 		mov	ax, word ptr dy4.DW ; struct DWord
//@ 		add	word ptr Yb.DW,	ax ; struct DWord
//@ 		mov	ax, word ptr dy4.DW+2 ;	struct DWord
//@ 		adc	word ptr Yb.DW+2, ax ; struct DWord
//@ ; #line	"CS_MAPML.PAS" 1972
//@ 		inc	x1		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1973
//@ 		jmp	short loc_17AE2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 1975
//@ 
//@ locret_17B1E:				; CODE XREF: DrawFourFaceSh1243+154j
//@ 		retf			; Return Far from Procedure
//@ DrawFourFaceSh1243 endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 1981
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ DrawFourFaceSh	proc far		; CODE XREF: DrawShadowFaces+B6P
//@ 		mov	Lx1, 3E8h	; int16_t
//@ 		mov	Lx2, 0FC18h	; int16_t
//@ 		mov	cx, 4
//@ 		mov	adx, 0		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1982
//@ 
//@ loc_17B34:				; CODE XREF: DrawFourFaceSh+42j
//@ 		mov	di, es:[si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1983
//@ 		cmp	ax, Lx1		; int16_t
//@ 		jg	short loc_17B4C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	Lx1, ax		; int16_t
//@ 		mov	bx, adx		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1984
//@ 
//@ loc_17B4C:				; CODE XREF: DrawFourFaceSh+24j
//@ 		cmp	ax, Lx2		; int16_t
//@ 		jl	short loc_17B59	; Jump if Less (SF!=OF)
//@ 		mov	Lx2, ax		; int16_t
//@ 		mov	dx, adx		; int16_t
//@ ; #line	"CS_MAPML.PAS" 1985
//@ 
//@ loc_17B59:				; CODE XREF: DrawFourFaceSh+31j
//@ 		add	si, 2		; Add
//@ 		inc	adx		; int16_t
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_17B34	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 1986
//@ 		sub	si, 8		; Integer Subtraction
//@ 		mov	v1, bx		; uint16_t
//@ 		mov	v4, dx		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1988
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		add	bx, dx		; Add
//@ 		nop			; No Operation
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 1989
//@ 		mov	ax, [bx+12B0h]
//@ ; #line	"CS_MAPML.PAS" 1990
//@ 		mov	bx, [bx+12B2h]
//@ ; #line	"CS_MAPML.PAS" 1991
//@ 		mov	v2, ax		; uint16_t
//@ 		mov	v3, bx		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 1993
//@ 		mov	bx, v2		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1994
//@ 		mov	bx, v3		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	dx, es:[di+4400h]
//@ ; #line	"CS_MAPML.PAS" 1995
//@ 		cmp	cx, dx		; Compare Two Operands
//@ 		jle	short loc_17BBC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 1996
//@ 		push	v2		; uint16_t
//@ 		push	v3		; uint16_t
//@ 		pop	v2		; uint16_t
//@ 		pop	v3		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 2001
//@ 
//@ loc_17BBC:				; CODE XREF: DrawFourFaceSh+8Bj
//@ 		mov	bx, v1		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 2002
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2003
//@ 		mov	ax, es:[di]
//@ 		mov	x1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2004
//@ 		mov	ax, es:[di+2]
//@ 		mov	y1, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2006
//@ 		mov	bx, v2		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 2007
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2008
//@ 		mov	ax, es:[di]
//@ 		mov	x2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2009
//@ 		mov	ax, es:[di+2]
//@ 		mov	y2, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2011
//@ 		mov	bx, v3		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 2012
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2013
//@ 		mov	ax, es:[di]
//@ 		mov	x3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2014
//@ 		mov	ax, es:[di+2]
//@ 		mov	y3, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2016
//@ 		mov	bx, v4		; uint16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 2017
//@ 		mov	di, es:[bx+si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2018
//@ 		mov	ax, es:[di]
//@ 		mov	x4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2019
//@ 		mov	ax, es:[di+2]
//@ 		mov	y4, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2023
//@ 		mov	ax, v4		; uint16_t
//@ 		sub	ax, v1		; uint16_t
//@ ; #line	"CS_MAPML.PAS" 2024
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jz	short loc_17C43	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0FFFEh	; Compare Two Operands
//@ 		jz	short loc_17C43	; Jump if Zero (ZF=1)
//@ 		jmp	short loc_17C4A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 2025
//@ 
//@ loc_17C43:				; CODE XREF: DrawFourFaceSh+11Bj
//@ 					; DrawFourFaceSh+120j
//@ 		call	DrawFourFaceSh1234 ; function far PASCAL returns void
//@ 		jmp	short locret_17C4F ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 2026
//@ 
//@ loc_17C4A:				; CODE XREF: DrawFourFaceSh+122j
//@ 		call	DrawFourFaceSh1243 ; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 2028
//@ 
//@ locret_17C4F:				; CODE XREF: DrawFourFaceSh+129j
//@ 		retf			; Return Far from Procedure
//@ DrawFourFaceSh	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 2039
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CreateShadow	proc far		; CODE XREF: Draw3DObject+242P
//@ 					; Draw3DObject+3CFP ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_MAPML.PAS" 2051
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 2052
//@ 		mov	di, 3800h
//@ ; #line	"CS_MAPML.PAS" 2053
//@ 		mov	si, 3E00h
//@ ; #line	"CS_MAPML.PAS" 2054
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 2056
//@ 
//@ loc_17C62:				; CODE XREF: CreateShadow+57j
//@ 		mov	ax, es:[di]
//@ 		sub	ax, LtX		; int16_t
//@ 		imul	word ptr es:[di+4] ; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 2057
//@ 		mov	bx, 2000h
//@ 		sub	bx, es:[di+4]	; Integer Subtraction
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_MAPML.PAS" 2058
//@ 		add	ax, es:[di]	; Add
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 2060
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, LtY		; int16_t
//@ 		imul	word ptr es:[di+4] ; Signed Multiply
//@ ; #line	"CS_MAPML.PAS" 2061
//@ 		mov	bx, 2000h
//@ 		sub	bx, es:[di+4]	; Integer Subtraction
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_MAPML.PAS" 2062
//@ 		add	ax, es:[di+2]	; Add
//@ 		mov	es:[si+2], ax
//@ ; #line	"CS_MAPML.PAS" 2063
//@ 		mov	ax, ShadowZ0	; int16_t
//@ 		mov	es:[si+4], ax
//@ ; #line	"CS_MAPML.PAS" 2064
//@ 		add	si, 6		; Add
//@ 		add	di, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 2065
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_17C62	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 2067
//@ 		mov	bx, OBJy	; int16_t
//@ 		sar	bx, 1		; Shift	Arithmetic Right
//@ 		sub	bx, 38h	; '8'   ; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 2068
//@ 		cmp	bx, 40h	; '@'   ; Compare Two Operands
//@ 		jg	short loc_17CBA	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	bx, 40h	; '@'
//@ ; #line	"CS_MAPML.PAS" 2069
//@ 
//@ loc_17CBA:				; CODE XREF: CreateShadow+65j
//@ 		mov	ax, Hz2		; uint16_t
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		imul	WallH		; uint16_t
//@ 		div	bx		; Unsigned Divide
//@ 		mov	CurDH, ax	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 2071
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ CreateShadow	endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 2077
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ ProcToScrShadow_Clip proc far		; CODE XREF: Draw3DObject+247P
//@ 					; Draw3DObject+3D4P ...
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 2078
//@ 		mov	di, 3E00h
//@ ; #line	"CS_MAPML.PAS" 2079
//@ 		mov	si, 4400h
//@ ; #line	"CS_MAPML.PAS" 2080
//@ 		mov	cx, VCount	; int16_t
//@ ; #line	"CS_MAPML.PAS" 2081
//@ 
//@ loc_17CD9:				; CODE XREF: ProcToScrShadow_Clip+81j
//@ 		mov	bx, es:[di+2]
//@ 		cmp	bx, 28h	; '('   ; Compare Two Operands
//@ 		jl	short loc_17CEF	; Jump if Less (SF!=OF)
//@ ; #line	"CS_MAPML.PAS" 2082
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ ; #line	"CS_MAPML.PAS" 2083
//@ 		cmp	bx, ax		; Compare Two Operands
//@ 		jg	short loc_17CFE	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_MAPML.PAS" 2084
//@ 
//@ loc_17CEF:				; CODE XREF: ProcToScrShadow_Clip+16j
//@ 		mov	ax, 7FFFh
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 2085
//@ 		mov	ax, 0F830h
//@ 		mov	es:[di+2], ax
//@ 		jmp	short loc_17D44	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 2087
//@ 
//@ loc_17CFE:				; CODE XREF: ProcToScrShadow_Clip+23j
//@ 		mov	ax, es:[di]
//@ 		imul	WallW		; uint16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_MAPML.PAS" 2088
//@ 		cmp	ax, 258h	; Compare Two Operands
//@ 		jle	short loc_17D17	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	ax, 258h	; Integer Subtraction
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		add	bx, ax		; Add
//@ 		mov	ax, 258h
//@ ; #line	"CS_MAPML.PAS" 2089
//@ 
//@ loc_17D17:				; CODE XREF: ProcToScrShadow_Clip+40j
//@ 		cmp	ax, 0FDA8h	; Compare Two Operands
//@ 		jge	short loc_17D27	; Jump if Greater or Equal (SF=OF)
//@ 		add	ax, 258h	; Add
//@ 		sar	ax, 4		; Shift	Arithmetic Right
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		mov	ax, 0FDA8h
//@ ; #line	"CS_MAPML.PAS" 2092
//@ 
//@ loc_17D27:				; CODE XREF: ProcToScrShadow_Clip+50j
//@ 		add	ax, VideoCX	; uint16_t
//@ 		mov	es:[si], ax
//@ ; #line	"CS_MAPML.PAS" 2093
//@ 		mov	ax, es:[di+4]
//@ 		sub	ax, ehz		; int16_t
//@ 		imul	WallH4		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_MAPML.PAS" 2094
//@ 		add	ax, WinCY	; uint16_t
//@ 		mov	es:[si+2], ax
//@ ; #line	"CS_MAPML.PAS" 2095
//@ 
//@ loc_17D44:				; CODE XREF: ProcToScrShadow_Clip+32j
//@ 		add	si, 4		; Add
//@ 		add	di, 6		; Add
//@ ; #line	"CS_MAPML.PAS" 2096
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_17CD9	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 2097
//@ 		retf			; Return Far from Procedure
//@ ProcToScrShadow_Clip endp
//@ 
//@ ; #line	"CS_MAPML.PAS" 2102
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawShadowFaces	proc far		; CODE XREF: Draw3DObject+24CP
//@ 					; Draw3DObject+3D9P ...
//@ 
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_MAPML.PAS" 2104
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 2105
//@ 		mov	gs, ax
//@ ; #line	"CS_MAPML.PAS" 2106
//@ 		mov	ax, OHSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CS_MAPML.PAS" 2108
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"CS_MAPML.PAS" 2109
//@ 
//@ loc_17D61:				; CODE XREF: DrawShadowFaces+BEj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, FCount	; int16_t
//@ 		jl	short loc_17D6D	; Jump if Less (SF!=OF)
//@ 		jmp	loc_17E0F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 2111
//@ 
//@ loc_17D6D:				; CODE XREF: DrawShadowFaces+1Aj
//@ 		mov	si, [bp+n]	; int16_t
//@ 		shl	si, 5		; Shift	Logical	Left
//@ ; #line	"CS_MAPML.PAS" 2112
//@ 		mov	al, es:[si+1Ch]
//@ 		and	al, DrawMask	; uint8_t
//@ 		jz	short loc_17D80	; Jump if Zero (ZF=1)
//@ 		jmp	loc_17E09	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 2115
//@ 
//@ loc_17D80:				; CODE XREF: DrawShadowFaces+2Dj
//@ 		mov	di, es:[si]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2116
//@ 		mov	cx, es:[di]
//@ 		cmp	cx, 7FFFh	; Compare Two Operands
//@ 		jz	short loc_17E09	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 2117
//@ 		mov	bx, es:[di+2]
//@ ; #line	"CS_MAPML.PAS" 2119
//@ 		mov	di, es:[si+2]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2120
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jz	short loc_17E09	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 2121
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		mov	ux, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2122
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		mov	uy, ax		; int16_t
//@ ; #line	"CS_MAPML.PAS" 2124
//@ 		mov	di, es:[si+4]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2125
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jz	short loc_17E09	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 2126
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		imul	uy		; int16_t
//@ 		mov	cx, ax
//@ ; #line	"CS_MAPML.PAS" 2127
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, bx		; Integer Subtraction
//@ 		imul	ux		; int16_t
//@ 		sub	ax, cx		; Integer Subtraction
//@ ; #line	"CS_MAPML.PAS" 2128
//@ 		js	short loc_17E09	; Jump if Sign (SF=1)
//@ ; #line	"CS_MAPML.PAS" 2130
//@ 		mov	ax, es:[si+6]
//@ 		cmp	ax, 0FFh	; Compare Two Operands
//@ 		jnz	short loc_17DF1	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_MAPML.PAS" 2131
//@ 		call	DrawTriFaceSh	; function far PASCAL returns void
//@ 		jmp	short loc_17E09	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 2132
//@ 
//@ loc_17DF1:				; CODE XREF: DrawShadowFaces+9Aj
//@ 		mov	di, es:[si+6]
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 4400h	; Add
//@ ; #line	"CS_MAPML.PAS" 2133
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, 7FFFh	; Compare Two Operands
//@ 		jz	short loc_17E09	; Jump if Zero (ZF=1)
//@ ; #line	"CS_MAPML.PAS" 2134
//@ 		call	DrawFourFaceSh	; function far PASCAL returns void
//@ ; #line	"CS_MAPML.PAS" 2135
//@ 
//@ loc_17E09:				; CODE XREF: DrawShadowFaces+2Fj
//@ 					; DrawShadowFaces+43j ...
//@ 		inc	[bp+n]		; int16_t
//@ 		jmp	loc_17D61	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_MAPML.PAS" 2138
//@ 
//@ loc_17E0F:				; CODE XREF: DrawShadowFaces+1Cj
//@ 		mov	ax, CSCopy$0	; uint16_t
//@ ; #line	"CS_MAPML.PAS" 2139
//@ 		mov	gs, ax
//@ ; #line	"CS_MAPML.PAS" 2141
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DrawShadowFaces	endp
//@ 
