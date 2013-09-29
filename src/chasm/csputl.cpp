
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

#include "csputl.h"

//@ ; #line	"CSPUTL.PAS" 85
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ MulVectors$1	proc near		; CODE XREF: Test2Vectors$0+4Ep
//@ 					; Test2Vectors$0+64p ...
//@ 
//@ vy		= word ptr  4		; int16_t
//@ vx		= word ptr  6		; int16_t
//@ uy		= word ptr  8		; int16_t
//@ ux		= word ptr  0Ah		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 86
//@ 		mov	cx, 0FFFFh
//@ ; #line	"CSPUTL.PAS" 87
//@ 		mov	ax, [bp+ux]	; int16_t
//@ ; #line	"CSPUTL.PAS" 88
//@ 		imul	[bp+vy]		; int16_t
//@ ; #line	"CSPUTL.PAS" 89
//@ 		mov	bx, dx
//@ ; #line	"CSPUTL.PAS" 90
//@ 		shl	ebx, 10h	; Shift	Logical	Left
//@ ; #line	"CSPUTL.PAS" 91
//@ 		mov	bx, ax
//@ ; #line	"CSPUTL.PAS" 93
//@ 		mov	ax, [bp+uy]	; int16_t
//@ ; #line	"CSPUTL.PAS" 94
//@ 		imul	[bp+vx]		; int16_t
//@ ; #line	"CSPUTL.PAS" 95
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSPUTL.PAS" 96
//@ 		mov	dx, ax
//@ ; #line	"CSPUTL.PAS" 97
//@ 		sub	ebx, edx	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 98
//@ 		js	short loc_20FAA	; Jump if Sign (SF=1)
//@ ; #line	"CSPUTL.PAS" 99
//@ 		mov	cx, 1
//@ ; #line	"CSPUTL.PAS" 101
//@ 
//@ loc_20FAA:				; CODE XREF: MulVectors$1+23j
//@ 		mov	ax, cx
//@ ; #line	"CSPUTL.PAS" 102
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ MulVectors$1	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 107
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Movxb		proc near		; CODE XREF: InsertObject+46Ap
//@ 
//@ cnt		= word ptr  4		; uint16_t
//@ b		= dword	ptr  6
//@ a		= dword	ptr  0Ah
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 108
//@ 		mov	cx, [bp+cnt]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 109
//@ 		mov	dx, ds
//@ ; #line	"CSPUTL.PAS" 111
//@ 		lds	si, [bp+a]	; Load Full Pointer to DS:xx
//@ ; #line	"CSPUTL.PAS" 112
//@ 		add	si, cx		; Add
//@ ; #line	"CSPUTL.PAS" 113
//@ 		sub	si, 2		; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 115
//@ 		les	di, [bp+b]	; Load Full Pointer to ES:xx
//@ ; #line	"CSPUTL.PAS" 116
//@ 		add	di, [bp+cnt]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 117
//@ 		sub	di, 2		; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 119
//@ 		std			; Set Direction	Flag
//@ ; #line	"CSPUTL.PAS" 120
//@ 		shr	cx, 1		; Shift	Logical	Right
//@ ; #line	"CSPUTL.PAS" 121
//@ 		rep movsw		; Move Byte(s) from String to String
//@ ; #line	"CSPUTL.PAS" 122
//@ 		mov	ds, dx
//@ ; #line	"CSPUTL.PAS" 123
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSPUTL.PAS" 124
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ Movxb		endp
//@ 
//@ ; #line	"CSPUTL.PAS" 128
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MoveDB		proc near		; CODE XREF: AnimateBlows+2B8p
//@ 
//@ cnt		= word ptr  4		; uint16_t
//@ b		= dword	ptr  6
//@ a		= dword	ptr  0Ah
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 129
//@ 		mov	dx, ds
//@ ; #line	"CSPUTL.PAS" 130
//@ 		lds	si, [bp+a]	; Load Full Pointer to DS:xx
//@ ; #line	"CSPUTL.PAS" 131
//@ 		les	di, [bp+b]	; Load Full Pointer to ES:xx
//@ ; #line	"CSPUTL.PAS" 132
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSPUTL.PAS" 133
//@ 		mov	cx, [bp+cnt]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 134
//@ 		shr	cx, 2		; Shift	Logical	Right
//@ ; #line	"CSPUTL.PAS" 135
//@ 		jz	short loc_20FEC	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 136
//@ 		rep movsd		; Move Byte(s) from String to String
//@ ; #line	"CSPUTL.PAS" 138
//@ 
//@ loc_20FEC:				; CODE XREF: MoveDB+12j
//@ 		mov	cx, [bp+cnt]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 139
//@ 		and	cx, 3		; Logical AND
//@ ; #line	"CSPUTL.PAS" 140
//@ 		jz	short loc_20FF7	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 141
//@ 		rep movsb		; Move Byte(s) from String to String
//@ ; #line	"CSPUTL.PAS" 143
//@ 
//@ loc_20FF7:				; CODE XREF: MoveDB+1Ej
//@ 		mov	ds, dx
//@ ; #line	"CSPUTL.PAS" 144
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ MoveDB		endp
//@ 
//@ ; #line	"CSPUTL.PAS" 151
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ Test2Vectors$0	proc near		; CODE XREF: SendFastRocket+10Bp
//@ 					; SendFastRocket+255p ...
//@ 
//@ i		= word ptr -4		; int16_t
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
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 152
//@ 		mov	[bp+Test2Vectors], 0 ; bool
//@ ; #line	"CSPUTL.PAS" 153
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	nx, ax		; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	ny, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 154
//@ 		mov	ax, [bp+x3]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	v1x, ax		; int16_t
//@ 		mov	ax, [bp+y3]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	v1y, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 155
//@ 		mov	ax, [bp+x4]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	v2x, ax		; int16_t
//@ 		mov	ax, [bp+y4]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	v2y, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 156
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v1x		; int16_t
//@ 		push	v1y		; int16_t
//@ 		call	MulVectors$1	; function near	PASCAL returns signed int 'Integer'
//@ 		mov	[bp+i],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 158
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v2x		; int16_t
//@ 		push	v2y		; int16_t
//@ 		call	MulVectors$1	; function near	PASCAL returns signed int 'Integer'
//@ 		cmp	ax, [bp+i]	; int16_t
//@ 		jnz	short loc_2106B	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_210D3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 160
//@ 
//@ loc_2106B:				; CODE XREF: Test2Vectors$0+6Aj
//@ 		mov	ax, [bp+x4]	; int16_t
//@ 		sub	ax, [bp+x3]	; int16_t
//@ 		mov	nx, ax		; int16_t
//@ 		mov	ax, [bp+y4]	; int16_t
//@ 		sub	ax, [bp+y3]	; int16_t
//@ 		mov	ny, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 161
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		sub	ax, [bp+x3]	; int16_t
//@ 		mov	v1x, ax		; int16_t
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+y3]	; int16_t
//@ 		mov	v1y, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 162
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x3]	; int16_t
//@ 		mov	v2x, ax		; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y3]	; int16_t
//@ 		mov	v2y, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 163
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v2x		; int16_t
//@ 		push	v2y		; int16_t
//@ 		call	MulVectors$1	; function near	PASCAL returns signed int 'Integer'
//@ 		push	ax
//@ 		push	nx		; int16_t
//@ 		push	ny		; int16_t
//@ 		push	v1x		; int16_t
//@ 		push	v1y		; int16_t
//@ 		call	MulVectors$1	; function near	PASCAL returns signed int 'Integer'
//@ 		pop	dx
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jnz	short loc_210CF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 164
//@ 		jmp	short loc_210D3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 165
//@ 
//@ loc_210CF:				; CODE XREF: Test2Vectors$0+CEj
//@ 		mov	[bp+Test2Vectors], 1 ; bool
//@ ; #line	"CSPUTL.PAS" 166
//@ 
//@ loc_210D3:				; CODE XREF: Test2Vectors$0+6Cj
//@ 					; Test2Vectors$0+D0j
//@ 		mov	al, [bp+Test2Vectors] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ Test2Vectors$0	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 170
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ iswater		proc far		; CODE XREF: AnimateRockets+6A6P
//@ 					; ProcessDevices+6E9P ...
//@ 
//@ iswater		= byte ptr -1		; bool
//@ hz		= word ptr  6		; int16_t
//@ arg_3		= byte ptr  9
//@ arg_5		= byte ptr  0Bh
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 171
//@ 		cmp	[bp+hz], 0	; int16_t
//@ 		jnz	short loc_21110	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+arg_3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, [bp+arg_5]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, AmbMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0Eh	; Signed Multiply
//@ 		cmp	word ptr [di-0A32h], 8 ; Compare Two Operands
//@ 		jnz	short loc_21110	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 172
//@ 		mov	[bp+iswater], 1	; bool
//@ 		jmp	short loc_21114	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 173
//@ 
//@ loc_21110:				; CODE XREF: iswater+8j iswater+2Ej
//@ 		mov	[bp+iswater], 0	; bool
//@ ; #line	"CSPUTL.PAS" 174
//@ 
//@ loc_21114:				; CODE XREF: iswater+34j
//@ 		mov	al, [bp+iswater] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ iswater		endp
//@ 
//@ ; #line	"CSPUTL.PAS" 228
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Bar		proc far		; CODE XREF: UpDateRanking+ADP
//@ 
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; uint16_t
//@ C		= byte ptr  6		; uint8_t
//@ h		= word ptr  8		; uint16_t
//@ w		= word ptr  0Ah		; uint16_t
//@ y		= word ptr  0Ch		; uint16_t
//@ x		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	ax, [bp+h]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_4], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		ja	short locret_21153 ; Jump if Above (CF=0 & ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_21135	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21132:				; CODE XREF: Bar+36j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_21135:				; CODE XREF: Bar+15j
//@ 		push	[bp+x]		; uint16_t
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, [bp+n]	; uint16_t
//@ 		push	ax
//@ 		push	[bp+w]		; uint16_t
//@ 		mov	al, [bp+C]	; uint8_t
//@ 		push	ax
//@ 		call	Hline		; function far PASCAL returns void
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jnz	short loc_21132	; Jump if Not Zero (ZF=0)
//@ 
//@ locret_21153:				; CODE XREF: Bar+10j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ Bar		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aFragsList	db 10,'Frags List'      ; DATA XREF: UpDateRanking+63o
//@ asc_21162	db 3,'###'              ; DATA XREF: UpDateRanking+10Ao
//@ ; #line	"CSPUTL.PAS" 284
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDateRanking	proc near		; CODE XREF: ShowScreen+Ep
//@ 
//@ var_114		= byte ptr -114h
//@ var_14		= dword	ptr -14h
//@ p		= word ptr -10h		; struct MenuRect
//@ var_E		= word ptr -0Eh
//@ var_C		= word ptr -0Ch
//@ var_A		= word ptr -0Ah
//@ pc		= word ptr -8		; int16_t
//@ c		= word ptr -6		; int16_t
//@ y		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	114h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 285
//@ 		mov	[bp+y],	30h ; '0' ; int16_t
//@ ; #line	"CSPUTL.PAS" 286
//@ 		mov	[bp+p],	5Ah ; 'Z' ; struct MenuRect
//@ 		mov	[bp+var_C], 0E6h ; 'æ'
//@ 		mov	[bp+var_E], 1Fh
//@ 		mov	[bp+var_A], 35h	; '5'
//@ ; #line	"CSPUTL.PAS" 287
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2118D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2118A:				; CODE XREF: UpDateRanking+3Aj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_2118D:				; CODE XREF: UpDateRanking+22j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_2119C	; Jump if Zero (ZF=1)
//@ 		add	[bp+var_A], 0Ch	; Add
//@ 
//@ loc_2119C:				; CODE XREF: UpDateRanking+30j
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_2118A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 288
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_211B8	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_211B8	; Jump if Not Zero (ZF=0)
//@ 		mov	Ranking, 0	; bool
//@ 		jmp	locret_2129F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 289
//@ 
//@ loc_211B8:				; CODE XREF: UpDateRanking+41j
//@ 					; UpDateRanking+48j
//@ 		lea	di, [bp+p]	; struct MenuRect
//@ 		push	ss
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 290
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		mov	di, offset aFragsList ;	"Frags List"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 291
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_211DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_211DA:				; CODE XREF: UpDateRanking+136j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_211DD:				; CODE XREF: UpDateRanking+72j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_14], di
//@ 		mov	word ptr [bp+var_14+2],	es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_211F6	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_21296	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 293
//@ 
//@ loc_211F6:				; CODE XREF: UpDateRanking+8Bj
//@ 		mov	di, es:[di+36h]
//@ 		mov	al, [di+28Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+pc], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 294
//@ 		push	64h ; 'd'
//@ 		push	[bp+y]		; int16_t
//@ 		push	78h ; 'x'
//@ 		push	9
//@ 		mov	ax, [bp+pc]	; int16_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		call	Bar		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 295
//@ 		push	64h ; 'd'
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		push	0DCh ; 'Ü'
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		add	ax, 9		; Add
//@ 		push	ax
//@ 		push	1
//@ 		push	1
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 296
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_21242	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+c],	21h ; '!' ; int16_t
//@ 		jmp	short loc_21247	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21242:				; CODE XREF: UpDateRanking+D3j
//@ 		mov	[bp+c],	1	; int16_t
//@ ; #line	"CSPUTL.PAS" 297
//@ 
//@ loc_21247:				; CODE XREF: UpDateRanking+DAj
//@ 		push	69h ; 'i'
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	[bp+c]		; int16_t
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 1		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 298
//@ 		push	0C4h ; 'Ä'
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	[bp+c]		; int16_t
//@ 		lea	di, [bp+var_114] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_21162 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+26h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 299
//@ 		add	[bp+y],	0Ch	; int16_t
//@ ; #line	"CSPUTL.PAS" 300
//@ 
//@ loc_21296:				; CODE XREF: UpDateRanking+8Dj
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jz	short locret_2129F ; Jump if Zero (ZF=1)
//@ 		jmp	loc_211DA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 301
//@ 
//@ locret_2129F:				; CODE XREF: UpDateRanking+4Fj
//@ 					; UpDateRanking+134j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ UpDateRanking	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_212A1	db 3,'   '              ; DATA XREF: UpDateIndy+1Co
//@ asc_212A5	db 3,'###'              ; DATA XREF: UpDateIndy+36o
//@ 					; UpDateIndy+7Do ...
//@ asc_212A9	db 1,'/'                ; DATA XREF: UpDateIndy+97o
//@ 					; UpDateIndy+ABo
//@ ; #line	"CSPUTL.PAS" 306
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDateIndy	proc near		; CODE XREF: ShowVesaScreen+76p
//@ 					; ShowScreen+24p
//@ 
//@ var_206		= byte ptr -206h
//@ var_106		= byte ptr -106h
//@ var_6		= dword	ptr -6
//@ 
//@ 		enter	206h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 309
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSPUTL.PAS" 311
//@ 		cmp	word ptr es:[di+48h], 1	; Compare Two Operands
//@ 		jnz	short loc_212DB	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset asc_212A1 ; "   "
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_21311	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 312
//@ 
//@ loc_212DB:				; CODE XREF: UpDateIndy+1Aj
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_212A5 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+2Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
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
//@ ; #line	"CSPUTL.PAS" 313
//@ 
//@ loc_21311:				; CODE XREF: UpDateIndy+2Ej
//@ 		mov	ax, WinSX	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		mov	ax, VideoEY	; uint16_t
//@ 		sub	ax, 0Ch		; Integer Subtraction
//@ 		push	ax
//@ 		push	8Fh ; ''
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_212A5 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+28h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset asc_212A9 ; "/"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_212A9 ; "/"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_212A5 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 317
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ UpDateIndy	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_2138F	db 1,'['                ; DATA XREF: ShowVesaScreen+38o
//@ asc_21391	db 2,'] '               ; DATA XREF: ShowVesaScreen+59o
//@ ; #line	"CSPUTL.PAS" 324
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowVesaScreen	proc far		; CODE XREF: EndPaint+3D2P
//@ 
//@ var_20C		= byte ptr -20Ch
//@ var_10C		= byte ptr -10Ch
//@ var_C		= dword	ptr -0Ch
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	20Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 325
//@ 		cmp	Paused,	0	; bool
//@ 		jz	short loc_213A4	; Jump if Zero (ZF=1)
//@ 		call	UpdatePause	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 326
//@ 
//@ loc_213A4:				; CODE XREF: ShowVesaScreen+9j
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"CSPUTL.PAS" 328
//@ 		push	0Ah
//@ 		push	2
//@ 		mov	ax, CurOwner	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		mov	al, [di+28Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		lea	di, [bp+var_20C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2138F ; "["
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_10C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, CurOwner	; uint16_t
//@ 		add	ax, 30h	; '0'   ; Add
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_21391 ; "] "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 1		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 334
//@ 		call	UpDateIndy	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 336
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_21417	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21414:				; CODE XREF: ShowVesaScreen+C6j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_21417:				; CODE XREF: ShowVesaScreen+7Ej
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	al, [di-0AC0h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, CurOwner	; uint16_t
//@ 		jnz	short loc_21456	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 337
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		push	word ptr [di+27Eh]
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		push	word ptr [di+280h]
//@ 		push	130h
//@ 		push	WinH		; uint16_t
//@ 		push	140h
//@ 		mov	ax, 8
//@ 		mov	dx, VgaSeg	; uint16_t
//@ 		mov	di, ax
//@ 		mov	es, dx
//@ 		push	es
//@ 		push	di
//@ 		call	VESA_PutImage	; function far PASCAL returns void
//@ 
//@ loc_21456:				; CODE XREF: ShowVesaScreen+90j
//@ 		cmp	[bp+n],	3	; int16_t
//@ 		jnz	short loc_21414	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 339
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ShowVesaScreen	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_16		db 2,'@#'               ; DATA XREF: ShowVESATime+AEo
//@ 					; ShowVESATime+D5o ...
//@ asc_21461	db 1,':'                ; DATA XREF: ShowVESATime+C5o
//@ 					; ShowVESATime+F1o
//@ ; #line	"CSPUTL.PAS" 343
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowVESATime	proc far		; CODE XREF: DoGame+1915P
//@ 
//@ var_306		= byte ptr -306h
//@ var_206		= byte ptr -206h
//@ var_106		= byte ptr -106h
//@ S		= word ptr -6		; uint16_t
//@ M		= word ptr -4		; uint16_t
//@ H		= word ptr -2		; uint16_t
//@ 
//@ 		enter	306h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 344
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
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
//@ 		mov	[bp+S],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 345
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		mov	cx, 20D0h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, 3Ch	; '<'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		mov	[bp+M],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 346
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		mov	cx, 0B0C0h
//@ 		mov	bx, 7
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, 18h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		mov	[bp+H],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 347
//@ 		mov	n$0, 3		; int16_t
//@ 		jmp	short loc_214DA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_214D6:				; CODE XREF: ShowVESATime+A0j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPUTL.PAS" 348
//@ 
//@ loc_214DA:				; CODE XREF: ShowVESATime+71j
//@ 		les	di, Ground	; void*
//@ 		push	es
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di-7016h]
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di-7016h]
//@ 		push	24h ; '$'
//@ 		call	movsw		; function far PASCAL returns void
//@ 		cmp	n$0, 0Bh	; int16_t
//@ 		jnz	short loc_214D6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 349
//@ 		push	0Ch
//@ 		push	4
//@ 		push	20h ; ' '
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_16 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+H]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset asc_21461 ; ":"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_16 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+M]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_21461 ; ":"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_306] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_16 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+S]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 350
//@ 		push	8
//@ 		push	0Bh
//@ 		push	40h ; '@'
//@ 		push	8
//@ 		push	140h
//@ 		mov	ax, 508h
//@ 		mov	dx, VgaSeg	; uint16_t
//@ 		mov	di, ax
//@ 		mov	es, dx
//@ 		push	es
//@ 		push	di
//@ 		call	VESA_PutImage	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 351
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ShowVESATime	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a0Dedicated	db 14,'[0]  DEDICATED'  ; DATA XREF: PutPlayerInf+71o
//@ asc_215B3	db 1,'['                ; DATA XREF: PutPlayerInf+8Bo
//@ asc_215B5	db 1,']'                ; DATA XREF: PutPlayerInf+ACo
//@ asc_215B7	db 1,'/'                ; DATA XREF: PutPlayerInf+104o
//@ ; #line	"CSPUTL.PAS" 356
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutPlayerInf	proc near		; CODE XREF: ShowVesaConsole+80p
//@ 
//@ var_20A		= byte ptr -20Ah
//@ var_10E		= byte ptr -10Eh
//@ var_10A		= byte ptr -10Ah
//@ var_E		= dword	ptr -0Eh
//@ S		= byte ptr -0Ah		; char[6] // Pascal string
//@ n		= word ptr -4		; uint16_t
//@ pc		= word ptr -2		; uint16_t
//@ pn		= word ptr  4		; int16_t
//@ 
//@ 		enter	20Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 357
//@ 		imul	di, [bp+pn], 58h ; int16_t
//@ 		mov	di, [di-0FA0h]
//@ 		mov	al, [di+28Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+pc], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 358
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_215D8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_215D5:				; CODE XREF: PutPlayerInf+39j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_215D8:				; CODE XREF: PutPlayerInf+1Aj
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di-7016h]
//@ 		push	45h ; 'E'
//@ 		push	0
//@ 		call	StosW		; function far PASCAL returns void
//@ 		cmp	[bp+n],	0Ch	; uint16_t
//@ 		jnz	short loc_215D5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 359
//@ 		mov	[bp+n],	1	; uint16_t
//@ 		jmp	short loc_215FE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_215FB:				; CODE XREF: PutPlayerInf+62j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_215FE:				; CODE XREF: PutPlayerInf+40j
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-7016h]
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	44h ; 'D'
//@ 		push	303h
//@ 		call	StosW		; function far PASCAL returns void
//@ 		cmp	[bp+n],	0Bh	; uint16_t
//@ 		jnz	short loc_215FB	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 360
//@ 		cmp	[bp+pn], 0	; int16_t
//@ 		jnz	short loc_21637	; Jump if Not Zero (ZF=0)
//@ 		push	4
//@ 		push	3
//@ 		push	[bp+pc]		; uint16_t
//@ 		mov	di, offset a0Dedicated ; "[0]  DEDICATED"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ 		jmp	locret_216D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 363
//@ 
//@ loc_21637:				; CODE XREF: PutPlayerInf+68j
//@ 		push	4
//@ 		push	3
//@ 		push	[bp+pc]		; uint16_t
//@ 		lea	di, [bp+var_20A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_215B3 ; "["
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_10A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+pn]	; int16_t
//@ 		add	ax, 30h	; '0'   ; Add
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_215B5 ; "]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 364
//@ 		imul	di, [bp+pn], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short locret_216D6 ; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 366
//@ 		mov	al, es:[di+26h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	1
//@ 		lea	di, [bp+S]	; char[6] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	5
//@ 		call	@Str$q7Longint4Wordm6String4Byte ; Str(x:width;	var s: string {; strlen: Word})
//@ ; #line	"CSPUTL.PAS" 367
//@ 		push	1Ch
//@ 		push	3
//@ 		push	[bp+pc]		; uint16_t
//@ 		lea	di, [bp+var_10E] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 1		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset asc_215B7 ; "/"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+S]	; char[6] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 370
//@ 
//@ locret_216D6:				; CODE XREF: PutPlayerInf+7Bj
//@ 					; PutPlayerInf+CFj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ PutPlayerInf	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 374
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowVesaConsole	proc far		; CODE XREF: DoGame+192DP
//@ 
//@ i		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 375
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_216E8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_216E5:				; CODE XREF: ShowVesaConsole+1Cj
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_216E8:				; CODE XREF: ShowVesaConsole+9j
//@ 		imul	di, [bp+i], 3Fh	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di-0C9Dh], ax
//@ 		cmp	[bp+i],	3	; int16_t
//@ 		jnz	short loc_216E5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 376
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ProcMessage.LTime, ax ;	struct ProcMessage$Type
//@ ; #line	"CSPUTL.PAS" 377
//@ 		mov	ax, takt	; uint16_t
//@ 		and	ax, 3		; Logical AND
//@ ; #line	"CSPUTL.PAS" 378
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jz	short loc_2170D	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short loc_21710	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_2170D:				; CODE XREF: ShowVesaConsole+2Cj
//@ 		jmp	locret_21795	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 379
//@ 
//@ loc_21710:				; CODE XREF: ShowVesaConsole+31j
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_21746	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 380
//@ 		mov	ConsY, 4Ch ; 'L' ; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsDY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 381
//@ 		call	UpDateConsole	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 382
//@ 		push	0
//@ 		push	144h
//@ 		push	140h
//@ 		push	4Ch ; 'L'
//@ 		push	140h
//@ 		mov	ax, 9B00h
//@ 		mov	dx, VgaSeg	; uint16_t
//@ 		mov	di, ax
//@ 		mov	es, dx
//@ 		push	es
//@ 		push	di
//@ 		call	VESA_PutImage	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 383
//@ 		jmp	short locret_21795 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 384
//@ 
//@ loc_21746:				; CODE XREF: ShowVesaConsole+39j
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short locret_21795 ; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 385
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_21756	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21752:				; CODE XREF: ShowVesaConsole+B9j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPUTL.PAS" 387
//@ 
//@ loc_21756:				; CODE XREF: ShowVesaConsole+76j
//@ 		push	n$0		; int16_t
//@ 		call	PutPlayerInf	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 388
//@ 		mov	ax, n$0		; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		imul	ax, 98h		; Signed Multiply
//@ 		add	ax, 14Ch	; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		and	ax, 3		; Logical AND
//@ 		imul	ax, 0Fh		; Signed Multiply
//@ 		add	ax, 14Dh	; Add
//@ 		push	ax
//@ 		push	8Ah ; 'Š'
//@ 		push	0Dh
//@ 		push	140h
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		call	VESA_PutImage	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 390
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_21752	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 393
//@ 
//@ locret_21795:				; CODE XREF: ShowVesaConsole:loc_2170Dj
//@ 					; ShowVesaConsole+6Aj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ShowVesaConsole	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 397
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowMessages	proc near		; CODE XREF: ShowScreen+4p
//@ 
//@ var_6		= dword	ptr -6
//@ i		= word ptr -2		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 398
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_217A5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_217A2:				; CODE XREF: ShowMessages+98j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPUTL.PAS" 399
//@ 
//@ loc_217A5:				; CODE XREF: ShowMessages+9j
//@ 		imul	di, [bp+i], 3Fh	; int16_t
//@ 		add	di, 0F326h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ 		cmp	word ptr es:[di+3Dh], 0	; Compare Two Operands
//@ 		jbe	short loc_21829	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 401
//@ 		mov	ax, es:[di+3Dh]
//@ 		cmp	ax, t1		; uint16_t
//@ 		jb	short loc_217CF	; Jump if Below	(CF=1)
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	es:[di+3Dh], ax	; Integer Subtraction
//@ 		jmp	short loc_217D8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_217CF:				; CODE XREF: ShowMessages+2Dj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+3Dh], ax
//@ ; #line	"CSPUTL.PAS" 402
//@ 
//@ loc_217D8:				; CODE XREF: ShowMessages+36j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+3Dh], 0	; Compare Two Operands
//@ 		jbe	short loc_217F8	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		push	4
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	0C1h ; 'Á'
//@ 		push	es
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ 		jmp	short loc_21829	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 403
//@ 
//@ loc_217F8:				; CODE XREF: ShowMessages+49j
//@ 		cmp	[bp+i],	3	; int16_t
//@ 		jz	short loc_21829	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 405
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	3Fh	; Signed Multiply
//@ 		add	di, 0F326h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, [bp+i], 3Fh	; int16_t
//@ 		add	di, 0F326h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, 3
//@ 		sub	ax, [bp+i]	; int16_t
//@ 		imul	ax, 3Fh		; Signed Multiply
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPUTL.PAS" 406
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MessageRec.LTime+0BDh, ax ; struct MessageRec$Element[4]
//@ ; #line	"CSPUTL.PAS" 408
//@ 
//@ loc_21829:				; CODE XREF: ShowMessages+23j
//@ 					; ShowMessages+5Fj ...
//@ 		cmp	[bp+i],	3	; int16_t
//@ 		jz	short loc_21832	; Jump if Zero (ZF=1)
//@ 		jmp	loc_217A2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 410
//@ 
//@ loc_21832:				; CODE XREF: ShowMessages+96j
//@ 		cmp	ProcMessage.LTime, 0 ; struct ProcMessage$Type
//@ 		jnz	short loc_2183C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_218C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 413
//@ 
//@ loc_2183C:				; CODE XREF: ShowMessages+A0j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_21847	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21843:				; CODE XREF: ShowMessages+10Fj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPUTL.PAS" 414
//@ 
//@ loc_21847:				; CODE XREF: ShowMessages+AAj
//@ 		imul	ax, n$0, 36h	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, ProcMessage.MessNum, 17Ch ;	struct ProcMessage$Type
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ ; #line	"CSPUTL.PAS" 415
//@ 		cmp	word ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_218A1	; Jump if Zero (ZF=1)
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0A0h ; ' '  ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+2]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	0C1h ; 'Á'
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ 
//@ loc_218A1:				; CODE XREF: ShowMessages+C9j
//@ 		cmp	n$0, 6		; int16_t
//@ 		jnz	short loc_21843	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 416
//@ 		cmp	EndOfTheGame, 0	; bool
//@ 		jnz	short loc_218B6	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	ProcMessage.LTime, ax ;	struct ProcMessage$Type
//@ ; #line	"CSPUTL.PAS" 417
//@ 
//@ loc_218B6:				; CODE XREF: ShowMessages+116j
//@ 		cmp	ProcMessage.LTime, 0 ; struct ProcMessage$Type
//@ 		jge	short locret_218C2 ; Jump if Greater or	Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ProcMessage.LTime, ax ;	struct ProcMessage$Type
//@ ; #line	"CSPUTL.PAS" 419
//@ 
//@ locret_218C2:				; CODE XREF: ShowMessages+A2j
//@ 					; ShowMessages+124j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ShowMessages	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 427
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowScreen	proc far		; CODE XREF: EndPaint+3E2P
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 428
//@ 		call	ShowMessages	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 430
//@ 		cmp	Ranking, 0	; bool
//@ 		jz	short loc_218D5	; Jump if Zero (ZF=1)
//@ 		call	UpDateRanking	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 431
//@ 
//@ loc_218D5:				; CODE XREF: ShowScreen+Cj
//@ 		cmp	Paused,	0	; bool
//@ 		jz	short loc_218E1	; Jump if Zero (ZF=1)
//@ 		call	UpdatePause	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 432
//@ 
//@ loc_218E1:				; CODE XREF: ShowScreen+16j
//@ 		cmp	InfoPage, 0	; bool
//@ 		jnz	short loc_218EB	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 433
//@ 		call	UpDateIndy	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 434
//@ 
//@ loc_218EB:				; CODE XREF: ShowScreen+22j
//@ 		cmp	InfoPage, 0	; bool
//@ 		jnz	short loc_218F9	; Jump if Not Zero (ZF=0)
//@ 		cmp	TabMode, 0	; bool
//@ 		jz	short loc_218FE	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 435
//@ 
//@ loc_218F9:				; CODE XREF: ShowScreen+2Cj
//@ 		call	UpDateInfo	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 437
//@ 
//@ loc_218FE:				; CODE XREF: ShowScreen+33j
//@ 		cmp	Console, 0	; bool
//@ 		jz	short loc_2190A	; Jump if Zero (ZF=1)
//@ 		call	UpDateConsole	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 438
//@ 
//@ loc_2190A:				; CODE XREF: ShowScreen+3Fj
//@ 		cmp	MenuOn,	0	; bool
//@ 		jz	short loc_21916	; Jump if Zero (ZF=1)
//@ 		call	UpDateMenu	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 440
//@ 
//@ loc_21916:				; CODE XREF: ShowScreen+4Bj
//@ 		call	ShowVideoBuffer	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 441
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ShowScreen	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 461
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutBigChar	proc near		; CODE XREF: PutBigString+A2p
//@ 
//@ BFOfs		= word ptr -4		; uint16_t
//@ BFSeg		= word ptr -2		; uint16_t
//@ C		= word ptr  4		; uint16_t
//@ yo		= word ptr  6		; uint16_t
//@ y0		= word ptr  8		; uint16_t
//@ x0		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 462
//@ 		les	di, BigFont	; uint8_t*
//@ 		mov	ax, es
//@ 		mov	[bp+BFSeg], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 463
//@ 		imul	ax, [bp+yo], 0E6h ; uint16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+C], 17h	; uint16_t
//@ 		add	ax, dx		; Add
//@ 		mov	[bp+BFOfs], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 465
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	bx, [bp+y0]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+x0]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 466
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPUTL.PAS" 468
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSPUTL.PAS" 469
//@ 		mov	ax, [bp+BFSeg]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 470
//@ 		mov	fs, ax
//@ ; #line	"CSPUTL.PAS" 471
//@ 		mov	cx, 13h
//@ ; #line	"CSPUTL.PAS" 474
//@ 
//@ loc_21958:				; CODE XREF: PutBigChar+63j
//@ 		push	cx
//@ 		mov	cx, 16h
//@ 		mov	si, [bp+BFOfs]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 475
//@ 		push	edi
//@ ; #line	"CSPUTL.PAS" 477
//@ 
//@ loc_21961:				; CODE XREF: PutBigChar+53j
//@ 		mov	al, fs:[si]
//@ ; #line	"CSPUTL.PAS" 478
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_2196C	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 479
//@ 		mov	es:[edi], al
//@ ; #line	"CSPUTL.PAS" 480
//@ 
//@ loc_2196C:				; CODE XREF: PutBigChar+49j
//@ 		inc	si		; Increment by 1
//@ ; #line	"CSPUTL.PAS" 481
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSPUTL.PAS" 482
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_21961	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 484
//@ 		add	[bp+BFOfs], 0E6h ; 'æ' ; uint16_t
//@ ; #line	"CSPUTL.PAS" 485
//@ 		pop	edi
//@ ; #line	"CSPUTL.PAS" 486
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CSPUTL.PAS" 487
//@ 		pop	cx
//@ 		dec	cx		; Decrement by 1
//@ ; #line	"CSPUTL.PAS" 488
//@ 		jnz	short loc_21958	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 490
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutBigChar	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_21986	db 3,'###'              ; DATA XREF: PutBigString+36o
//@ ; #line	"CSPUTL.PAS" 494
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutBigString	proc near		; CODE XREF: UpDateInfo+1DAp
//@ 					; UpDateInfo+36Dp ...
//@ 
//@ var_204		= byte ptr -204h
//@ var_106		= word ptr -106h
//@ s		= byte ptr -104h	; char[256] // Pascal string
//@ yo		= word ptr -4		; uint16_t
//@ c		= word ptr -2		; uint16_t
//@ v		= word ptr  4		; int16_t
//@ l		= word ptr  6		; uint16_t
//@ y0		= word ptr  8		; uint16_t
//@ X0		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	204h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 495
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, 0A0h ; ' '  ; Integer Subtraction
//@ 		add	[bp+X0], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 496
//@ 		mov	ax, [bp+l]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+v]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_219AE	; Jump if Less (SF!=OF)
//@ 		jg	short loc_219B5	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_219B5	; Jump if Not Below (CF=0)
//@ 
//@ loc_219AE:				; CODE XREF: PutBigString+1Cj
//@ 		mov	[bp+yo], 14h	; uint16_t
//@ 		jmp	short loc_219BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_219B5:				; CODE XREF: PutBigString+1Ej
//@ 					; PutBigString+22j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+yo], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 497
//@ 
//@ loc_219BA:				; CODE XREF: PutBigString+29j
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_21986 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+v]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPUTL.PAS" 498
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_106], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		ja	short locret_21A38 ; Jump if Above (CF=0 & ZF=0)
//@ 		mov	[bp+c],	ax	; uint16_t
//@ 		jmp	short loc_219FF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_219FC:				; CODE XREF: PutBigString+ACj
//@ 		inc	[bp+c]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 499
//@ 
//@ loc_219FF:				; CODE XREF: PutBigString+70j
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		cmp	al, 30h	; '0'   ; Compare Two Operands
//@ 		jb	short loc_21A2F	; Jump if Below	(CF=1)
//@ 		cmp	al, 39h	; '9'   ; Compare Two Operands
//@ 		ja	short loc_21A2F	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 500
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	ax, 17h		; Signed Multiply
//@ 		add	ax, [bp+X0]	; uint16_t
//@ 		push	ax
//@ 		push	[bp+y0]		; uint16_t
//@ 		push	[bp+yo]		; uint16_t
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 30h	; '0'   ; Integer Subtraction
//@ 		push	ax
//@ 		call	PutBigChar	; function near	PASCAL returns void
//@ 
//@ loc_21A2F:				; CODE XREF: PutBigString+7Ej
//@ 					; PutBigString+82j
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		jnz	short loc_219FC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 501
//@ 
//@ locret_21A38:				; CODE XREF: PutBigString+6Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutBigString	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 508
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutLitChar	proc near		; CODE XREF: PutLitString+65p
//@ 					; PutWLitString+68p
//@ 
//@ BFOfs		= word ptr -4		; uint16_t
//@ BFSeg		= word ptr -2		; uint16_t
//@ C		= word ptr  4		; uint16_t
//@ y0		= word ptr  6		; uint16_t
//@ x0		= word ptr  8		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 509
//@ 		les	di, LitFont	; uint8_t*
//@ 		mov	ax, es
//@ 		mov	[bp+BFSeg], ax	; uint16_t
//@ 		imul	ax, [bp+C], 0Ch	; uint16_t
//@ 		mov	[bp+BFOfs], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 511
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	bx, [bp+y0]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+x0]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 512
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPUTL.PAS" 513
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSPUTL.PAS" 514
//@ 		mov	ax, [bp+BFSeg]	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CSPUTL.PAS" 515
//@ 		mov	cx, 5
//@ ; #line	"CSPUTL.PAS" 517
//@ 
//@ loc_21A6E:				; CODE XREF: PutLitChar+5Aj
//@ 		push	edi
//@ ; #line	"CSPUTL.PAS" 518
//@ 		push	cx
//@ 		mov	cx, 6
//@ ; #line	"CSPUTL.PAS" 519
//@ 		mov	si, [bp+BFOfs]	; uint16_t
//@ ; #line	"CSPUTL.PAS" 521
//@ 
//@ loc_21A77:				; CODE XREF: PutLitChar+4Aj
//@ 		mov	al, fs:[si]
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_21A82	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 522
//@ 		mov	es:[edi], al
//@ ; #line	"CSPUTL.PAS" 523
//@ 
//@ loc_21A82:				; CODE XREF: PutLitChar+40j
//@ 		inc	si		; Increment by 1
//@ ; #line	"CSPUTL.PAS" 524
//@ 		inc	edi		; Increment by 1
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_21A77	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 526
//@ 		add	[bp+BFOfs], 0EAh ; 'ê' ; uint16_t
//@ ; #line	"CSPUTL.PAS" 527
//@ 		pop	cx
//@ ; #line	"CSPUTL.PAS" 528
//@ 		pop	edi
//@ ; #line	"CSPUTL.PAS" 529
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CSPUTL.PAS" 530
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_21A6E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 532
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ PutLitChar	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 536
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutLitString	proc near		; CODE XREF: UpDateInfo+583p
//@ 
//@ var_104		= word ptr -104h
//@ c		= word ptr -102h	; uint16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ y0		= word ptr  8		; uint16_t
//@ X0		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	104h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
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
//@ ; #line	"CSPUTL.PAS" 537
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_104], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_104] ; Compare Two Operands
//@ 		ja	short locret_21B0E ; Jump if Above (CF=0 & ZF=0)
//@ 		mov	[bp+c],	ax	; uint16_t
//@ 		jmp	short loc_21AD4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21AD0:				; CODE XREF: PutLitString+70j
//@ 		inc	[bp+c]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 538
//@ 
//@ loc_21AD4:				; CODE XREF: PutLitString+32j
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		cmp	al, 30h	; '0'   ; Compare Two Operands
//@ 		jb	short loc_21B04	; Jump if Below	(CF=1)
//@ 		cmp	al, 39h	; '9'   ; Compare Two Operands
//@ 		ja	short loc_21B04	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	ax, 7		; Signed Multiply
//@ 		add	ax, [bp+X0]	; uint16_t
//@ 		push	ax
//@ 		push	[bp+y0]		; uint16_t
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 30h	; '0'   ; Integer Subtraction
//@ 		push	ax
//@ 		call	PutLitChar	; function near	PASCAL returns void
//@ 
//@ loc_21B04:				; CODE XREF: PutLitString+42j
//@ 					; PutLitString+46j
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		cmp	ax, [bp+var_104] ; Compare Two Operands
//@ 		jnz	short loc_21AD0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 539
//@ 
//@ locret_21B0E:				; CODE XREF: PutLitString+2Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutLitString	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 543
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutWLitString	proc near		; CODE XREF: UpDateInfo+53Dp
//@ 
//@ var_104		= word ptr -104h
//@ c		= word ptr -102h	; uint16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ y0		= word ptr  8		; uint16_t
//@ X0		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	104h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
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
//@ ; #line	"CSPUTL.PAS" 544
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_104], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_104] ; Compare Two Operands
//@ 		ja	short locret_21B87 ; Jump if Above (CF=0 & ZF=0)
//@ 		mov	[bp+c],	ax	; uint16_t
//@ 		jmp	short loc_21B4A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21B46:				; CODE XREF: PutWLitString+73j
//@ 		inc	[bp+c]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 545
//@ 
//@ loc_21B4A:				; CODE XREF: PutWLitString+32j
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		cmp	al, 30h	; '0'   ; Compare Two Operands
//@ 		jb	short loc_21B7D	; Jump if Below	(CF=1)
//@ 		cmp	al, 39h	; '9'   ; Compare Two Operands
//@ 		ja	short loc_21B7D	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	ax, 7		; Signed Multiply
//@ 		add	ax, [bp+X0]	; uint16_t
//@ 		push	ax
//@ 		push	[bp+y0]		; uint16_t
//@ 		mov	di, [bp+c]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 30h	; '0'   ; Integer Subtraction
//@ 		add	ax, 0Ah		; Add
//@ 		push	ax
//@ 		call	PutLitChar	; function near	PASCAL returns void
//@ 
//@ loc_21B7D:				; CODE XREF: PutWLitString+42j
//@ 					; PutWLitString+46j
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		cmp	ax, [bp+var_104] ; Compare Two Operands
//@ 		jnz	short loc_21B46	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 546
//@ 
//@ locret_21B87:				; CODE XREF: PutWLitString+2Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutWLitString	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_17		db 2,'@#'               ; DATA XREF: UpDateInfo+229o
//@ 					; UpDateInfo+25Co ...
//@ aTime_0		db 6,'Time: '           ; DATA XREF: UpDateInfo+219o
//@ a__5		db 1,'.'                ; DATA XREF: UpDateInfo+24Co
//@ 					; UpDateInfo+280o
//@ asc_21B97	db 3,'###'              ; DATA XREF: UpDateInfo+51Fo
//@ 					; UpDateInfo+565o
//@ ; #line	"CSPUTL.PAS" 553
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDateInfo	proc far		; CODE XREF: ShowScreen:loc_218F9P
//@ 
//@ var_412		= byte ptr -412h
//@ var_312		= byte ptr -312h
//@ var_212		= byte ptr -212h
//@ var_112		= byte ptr -112h
//@ var_10E		= byte ptr -10Eh
//@ var_12		= dword	ptr -12h
//@ h		= word ptr -0Eh		; uint16_t
//@ y		= word ptr -0Ch		; uint16_t
//@ n		= word ptr -0Ah		; uint16_t
//@ c		= word ptr -8		; uint16_t
//@ cc		= word ptr -6		; uint16_t
//@ a		= word ptr -4		; uint16_t
//@ b		= word ptr -2		; uint16_t
//@ 
//@ 		enter	412h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 554
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_21BAD	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_21BB4	; Jump if Zero (ZF=1)
//@ 
//@ loc_21BAD:				; CODE XREF: UpDateInfo+9j
//@ 		mov	[bp+h],	2Ch ; ',' ; uint16_t
//@ 		jmp	short loc_21BB9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21BB4:				; CODE XREF: UpDateInfo+10j
//@ 		mov	[bp+h],	20h ; ' ' ; uint16_t
//@ ; #line	"CSPUTL.PAS" 556
//@ 
//@ loc_21BB9:				; CODE XREF: UpDateInfo+17j
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, 0A0h ; ' '  ; Integer Subtraction
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	[bp+cc], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 558
//@ 		cmp	InfoPage, 0	; bool
//@ 		jnz	short loc_21BCF	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_21CE9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 559
//@ 
//@ loc_21BCF:				; CODE XREF: UpDateInfo+2Fj
//@ 		cmp	CurVideoMode, 1	; uint16_t
//@ 		jnz	short loc_21C02	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 560
//@ 		les	di, Status	; void*
//@ 		push	es
//@ 		mov	ax, 2Ch	; ','
//@ 		sub	ax, [bp+h]	; uint16_t
//@ 		imul	ax, 140h	; Signed Multiply
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, 0C8h ; 'È'
//@ 		sub	ax, [bp+h]	; uint16_t
//@ 		imul	ax, 140h	; Signed Multiply
//@ 		push	ax
//@ 		imul	ax, [bp+h], 50h	; uint16_t
//@ 		push	ax
//@ 		call	movsD$0		; function far PASCAL returns void
//@ 		jmp	loc_21CE9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 562
//@ 
//@ loc_21C02:				; CODE XREF: UpDateInfo+39j
//@ 		mov	ax, [bp+h]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	word ptr [bp+var_12+2],	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, word ptr [bp+var_12+2] ; Compare Two Operands
//@ 		jbe	short loc_21C13	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_21CE9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21C13:				; CODE XREF: UpDateInfo+73j
//@ 		mov	[bp+a],	ax	; uint16_t
//@ 		jmp	short loc_21C1B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21C18:				; CODE XREF: UpDateInfo+14Bj
//@ 		inc	[bp+a]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 564
//@ 
//@ loc_21C1B:				; CODE XREF: UpDateInfo+7Bj
//@ 		mov	ax, 2Bh	; '+'
//@ 		sub	ax, [bp+a]	; uint16_t
//@ 		mov	[bp+b],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 565
//@ 		les	di, Status	; void*
//@ 		push	es
//@ 		imul	ax, [bp+b], 140h ; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, VideoEY	; uint16_t
//@ 		sub	ax, [bp+a]	; uint16_t
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di-6E84h]
//@ 		mov	dx, [di-6E82h]
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0A0h ; ' '  ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	dx
//@ 		push	ax
//@ 		push	0
//@ 		push	50h ; 'P'
//@ 		call	MovsED		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 566
//@ 		les	di, Ground	; void*
//@ 		push	es
//@ 		imul	ax, [bp+b], 140h ; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, VideoEY	; uint16_t
//@ 		sub	ax, [bp+a]	; uint16_t
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		push	word ptr [di-6E82h]
//@ 		push	word ptr [di-6E84h]
//@ 		mov	ax, [bp+cc]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovsED		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 567
//@ 		les	di, Ground	; void*
//@ 		push	es
//@ 		imul	ax, [bp+b], 140h ; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, VideoEY	; uint16_t
//@ 		sub	ax, [bp+a]	; uint16_t
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di-6E84h]
//@ 		mov	dx, [di-6E82h]
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		add	ax, 0A0h ; ' '  ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+cc]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovsED		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 568
//@ 		mov	ax, [bp+a]	; uint16_t
//@ 		cmp	ax, word ptr [bp+var_12+2] ; Compare Two Operands
//@ 		jz	short loc_21CE9	; Jump if Zero (ZF=1)
//@ 		jmp	loc_21C18	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 571
//@ 
//@ loc_21CE9:				; CODE XREF: UpDateInfo+31j
//@ 					; UpDateInfo+64j ...
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_12], di
//@ 		mov	word ptr [bp+var_12+2],	es
//@ ; #line	"CSPUTL.PAS" 572
//@ 		cmp	TabMode, 0	; bool
//@ 		jnz	short loc_21D04	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_21EEF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 574
//@ 
//@ loc_21D04:				; CODE XREF: UpDateInfo+164j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+a],	ax	; uint16_t
//@ 		jmp	short loc_21D0E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21D0B:				; CODE XREF: UpDateInfo+1BFj
//@ 		inc	[bp+a]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 575
//@ 
//@ loc_21D0E:				; CODE XREF: UpDateInfo+16Ej
//@ 		les	di, Status	; void*
//@ 		assume es:nothing
//@ 		push	es
//@ 		mov	ax, 4Bh	; 'K'
//@ 		sub	ax, [bp+a]	; uint16_t
//@ 		imul	ax, 140h	; Signed Multiply
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, VideoEY	; uint16_t
//@ 		sub	ax, [bp+a]	; uint16_t
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di-6E84h]
//@ 		mov	dx, [di-6E82h]
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0A0h ; ' '  ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	dx
//@ 		push	ax
//@ 		push	0
//@ 		push	50h ; 'P'
//@ 		call	MovsED		; function far PASCAL returns void
//@ 		cmp	[bp+a],	1Fh	; uint16_t
//@ 		jnz	short loc_21D0B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 576
//@ 		push	23h ; '#'
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 19h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	14h
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4Eh]
//@ 		call	PutBigString	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 577
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 8Ch	; 'Œ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+c],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 578
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 3Ch	; '<'
//@ 		div	cx		; Unsigned Divide
//@ 		mov	[bp+cc], ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 579
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 1Ah		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		lea	di, [bp+var_212] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTime_0 ; "Time: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_112] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_17 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+cc]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 3Ch	; '<'
//@ 		div	cx		; Unsigned Divide
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a__5	; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_312] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_17 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+cc]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 3Ch	; '<'
//@ 		div	cx		; Unsigned Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a__5	; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_412] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_17 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 3Ch	; '<'
//@ 		div	cx		; Unsigned Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 582
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 0Eh		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		mov	ax, LevelN	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, ShortNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 583
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, 2Fh	; '/'   ; Integer Subtraction
//@ 		mov	x$0, ax		; int16_t
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 1Bh		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+y],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 584
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_21EA3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21EA0:				; CODE XREF: UpDateInfo+34Fj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 585
//@ 
//@ loc_21EA3:				; CODE XREF: UpDateInfo+303j
//@ 		mov	ax, 10h
//@ 		mov	cx, [bp+n]	; uint16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		and	ax, es:[di+2Ah]	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_21EE6	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 586
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		and	ax, 1		; Logical AND
//@ 		imul	ax, 14h		; Signed Multiply
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, x$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		imul	ax, 0Eh		; Signed Multiply
//@ 		add	ax, [bp+y]	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		push	ax
//@ 		call	PutChar		; function far PASCAL returns void
//@ 
//@ loc_21EE6:				; CODE XREF: UpDateInfo+319j
//@ 		cmp	[bp+n],	3	; uint16_t
//@ 		jnz	short loc_21EA0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 587
//@ 		jmp	loc_21FCD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 589
//@ 
//@ loc_21EEF:				; CODE XREF: UpDateInfo+166j
//@ 		push	23h ; '#'
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 19h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	19h
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+28h]
//@ 		call	PutBigString	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 590
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+48h], 1	; Compare Two Operands
//@ 		jle	short loc_21F38	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		push	89h ; '‰'
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 19h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	0Ah
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+2Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	PutBigString	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 591
//@ 
//@ loc_21F38:				; CODE XREF: UpDateInfo+378j
//@ 		push	0F6h ; 'ö'
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 19h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	19h
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	PutBigString	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 592
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+48h]
//@ 		dec	ax		; Decrement by 1
//@ 		imul	ax, 1Ch		; Signed Multiply
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+c],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 594
//@ 		mov	[bp+n],	1	; uint16_t
//@ 		jmp	short loc_21F71	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21F6E:				; CODE XREF: UpDateInfo+430j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 595
//@ 
//@ loc_21F71:				; CODE XREF: UpDateInfo+3D1j
//@ 		les	di, WIcons	; uint8_t*
//@ 		push	es
//@ 		imul	ax, [bp+n], 0E0h ; uint16_t
//@ 		add	ax, [bp+c]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 1Dh		; Integer Subtraction
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
//@ 		sub	ax, 36h	; '6'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	dx
//@ 		push	ax
//@ 		push	0
//@ 		push	0Dh
//@ 		call	MovsEW		; function far PASCAL returns void
//@ 		cmp	[bp+n],	17h	; uint16_t
//@ 		jnz	short loc_21F6E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 599
//@ 
//@ loc_21FCD:				; CODE XREF: UpDateInfo+351j
//@ 		cmp	InfoPage, 0	; bool
//@ 		jnz	short loc_21FD7	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2212A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 600
//@ 
//@ loc_21FD7:				; CODE XREF: UpDateInfo+437j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_21FE8	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_21FE8	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2212A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 601
//@ 
//@ loc_21FE8:				; CODE XREF: UpDateInfo+441j
//@ 					; UpDateInfo+448j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_21FF2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_21FEF:				; CODE XREF: UpDateInfo+58Cj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 602
//@ 
//@ loc_21FF2:				; CODE XREF: UpDateInfo+452j
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_22000	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_22121	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 604
//@ 
//@ loc_22000:				; CODE XREF: UpDateInfo+460j
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	di, [di-0FA0h]
//@ 		mov	al, [di+28Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 5		; Add
//@ 		mov	[bp+c],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 605
//@ 		imul	ax, [bp+c], 101h ; uint16_t
//@ 		mov	[bp+c],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 607
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y],	ax	; uint16_t
//@ 		jmp	short loc_22026	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22023:				; CODE XREF: UpDateInfo+4E5j
//@ 		inc	[bp+y]		; uint16_t
//@ ; #line	"CSPUTL.PAS" 608
//@ 
//@ loc_22026:				; CODE XREF: UpDateInfo+486j
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 29h	; ')'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, [di-6E84h]
//@ 		mov	bx, [di-6E82h]
//@ 		imul	ax, [bp+n], 28h	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 9Ch	; 'œ'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	dx
//@ 		push	ax
//@ 		push	0
//@ 		push	10h
//@ 		push	[bp+c]		; uint16_t
//@ 		call	StosEW		; function far PASCAL returns void
//@ 		cmp	[bp+y],	6	; uint16_t
//@ 		jnz	short loc_22023	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 610
//@ 		mov	ax, MyNetN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_220DD	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnz	short loc_220DD	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+n], 28h	; uint16_t
//@ 		mov	dx, ax
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, 96h	; '–'   ; Integer Subtraction
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 28h	; '('   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		lea	di, [bp+var_10E] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_21B97 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	al, [di-0FB0h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	PutWLitString	; function near	PASCAL returns void
//@ 		jmp	short loc_22121	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 611
//@ 
//@ loc_220DD:				; CODE XREF: UpDateInfo+4F6j
//@ 					; UpDateInfo+4FAj
//@ 		imul	ax, [bp+n], 28h	; uint16_t
//@ 		mov	dx, ax
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, 96h	; '–'   ; Integer Subtraction
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 28h	; '('   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		lea	di, [bp+var_10E] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_21B97 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	al, [di-0FB0h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	PutLitString	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 612
//@ 
//@ loc_22121:				; CODE XREF: UpDateInfo+462j
//@ 					; UpDateInfo+540j
//@ 		cmp	[bp+n],	7	; uint16_t
//@ 		jz	short locret_2212A ; Jump if Zero (ZF=1)
//@ 		jmp	loc_21FEF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 613
//@ 
//@ locret_2212A:				; CODE XREF: UpDateInfo+439j
//@ 					; UpDateInfo+44Aj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ UpDateInfo	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 622
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScrollGun	proc far		; CODE XREF: EndPaint+4P
//@ 
//@ var_6		= dword	ptr -6
//@ dt		= word ptr -2		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 623
//@ 		cmp	WeaponPhase, 1	; uint16_t
//@ 		jnz	short loc_2213A	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_221D0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 624
//@ 
//@ loc_2213A:				; CODE XREF: ScrollGun+9j
//@ 		mov	ax, t1		; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		add	ax, t1		; uint16_t
//@ 		mov	[bp+dt], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 625
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		ja	short loc_22150	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	locret_221D0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22150:				; CODE XREF: ScrollGun+1Fj
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSPUTL.PAS" 627
//@ 		mov	ax, es:[di+48h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LastGunNumber ; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_221AB	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnz	short loc_221AB	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		jbe	short loc_221AB	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 629
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, GunShift	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_2219B	; Jump if Less (SF!=OF)
//@ 		jg	short loc_221A2	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		ja	short loc_221A2	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_2219B:				; CODE XREF: ScrollGun+67j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	GunShift, ax	; uint16_t
//@ 		jmp	short loc_221A9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_221A2:				; CODE XREF: ScrollGun+69j
//@ 					; ScrollGun+6Dj
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		sub	GunShift, ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 630
//@ 
//@ loc_221A9:				; CODE XREF: ScrollGun+74j
//@ 		jmp	short locret_221D0 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 632
//@ 
//@ loc_221AB:				; CODE XREF: ScrollGun+45j
//@ 					; ScrollGun+49j ...
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		add	GunShift, ax	; uint16_t
//@ 		cmp	GunShift, 3Eh ;	'>' ; uint16_t
//@ 		jbe	short loc_221BF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	GunShift, 3Eh ;	'>' ; uint16_t
//@ ; #line	"CSPUTL.PAS" 633
//@ 
//@ loc_221BF:				; CODE XREF: ScrollGun+8Bj
//@ 		cmp	GunShift, 3Eh ;	'>' ; uint16_t
//@ 		jnz	short locret_221D0 ; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+48h]
//@ 		mov	LastGunNumber, ax ; uint16_t
//@ ; #line	"CSPUTL.PAS" 636
//@ 
//@ locret_221D0:				; CODE XREF: ScrollGun+Bj
//@ 					; ScrollGun+21j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ScrollGun	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 761
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InsertByte	proc near		; CODE XREF: SavePicture+24Dp
//@ 					; SavePicture+256p ...
//@ 
//@ var_1002	= word ptr -1002h
//@ arg_0		= word ptr  4
//@ b		= byte ptr  6		; uint8_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 762
//@ 		mov	dl, [bp+b]	; uint8_t
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+var_1002]
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr ss:[di+var_1002+1], dl
//@ 		mov	di, [bp+arg_0]
//@ 		inc	ss:[di+var_1002] ; Increment by	1
//@ ; #line	"CSPUTL.PAS" 763
//@ 		cmp	ss:[di+var_1002], 1000h	; Compare Two Operands
//@ 		jbe	short locret_2221D ; Jump if Below or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 765
//@ 		add	di, 0EF76h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0F000h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_1002], 1
//@ ; #line	"CSPUTL.PAS" 767
//@ 
//@ locret_2221D:				; CODE XREF: InsertByte+24j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ InsertByte	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 770
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns unsigned char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ GetB		proc near		; CODE XREF: SavePicture+19Dp
//@ 					; SavePicture+1AAp ...
//@ 
//@ DOf		= word ptr  6		; int32_t
//@ arg_4		= word ptr  8
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 771
//@ 		mov	bx, [bp+DOf]	; int32_t
//@ ; #line	"CSPUTL.PAS" 772
//@ 		mov	ax, [bp+arg_4]
//@ ; #line	"CSPUTL.PAS" 773
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ ; #line	"CSPUTL.PAS" 774
//@ 		add	ax, VgaSeg	; uint16_t
//@ ; #line	"CSPUTL.PAS" 775
//@ 		mov	es, ax
//@ ; #line	"CSPUTL.PAS" 776
//@ 		mov	al, es:[bx]
//@ ; #line	"CSPUTL.PAS" 777
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ GetB		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_18		db 3,'@##'              ; DATA XREF: SavePicture+1Fo
//@ aChasm_1	db 5,'chasm'            ; DATA XREF: SavePicture+Fo
//@ a_pcx		db 4,'.pcx'             ; DATA XREF: SavePicture+3Bo
//@ aSaved_		db 9,' saved. ('        ; DATA XREF: SavePicture+365o
//@ a__6		db 5,'##.##'            ; DATA XREF: SavePicture+375o
//@ aS_		db 3,'s.)'              ; DATA XREF: SavePicture+39Eo
//@ ; #line	"CSPUTL.PAS" 779
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SavePicture	proc far		; CODE XREF: DoGame:loc_C53DP
//@ 
//@ var_1310	= byte ptr -1310h
//@ var_1210	= byte ptr -1210h
//@ var_1114	= word ptr -1114h
//@ var_1112	= word ptr -1112h
//@ HDR		= byte ptr -1110h	; struct PCXHeader
//@ var_110F	= byte ptr -110Fh
//@ var_110E	= byte ptr -110Eh
//@ var_110D	= byte ptr -110Dh
//@ var_110C	= word ptr -110Ch
//@ var_110A	= word ptr -110Ah
//@ var_1108	= word ptr -1108h
//@ var_1106	= word ptr -1106h
//@ var_1104	= word ptr -1104h
//@ var_1101	= byte ptr -1101h
//@ var_10CF	= byte ptr -10CFh
//@ var_10CE	= word ptr -10CEh
//@ var_10CC	= word ptr -10CCh
//@ b		= byte ptr -108Fh	; uint8_t
//@ cnt		= word ptr -108Eh	; int32_t
//@ var_108C	= word ptr -108Ch
//@ f		= byte ptr -108Ah	; FILE
//@ PSize		= word ptr -100Ah	; int32_t
//@ var_1008	= word ptr -1008h
//@ DTOfs		= word ptr -1006h	; int32_t
//@ var_1004	= word ptr -1004h
//@ DBofs		= word ptr -1002h	; uint16_t
//@ DBuf		= byte ptr -1000h	; uint8_t[4096]
//@ 
//@ 		enter	1310h, 0	; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 780
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 781
//@ 		lea	di, [bp+var_1310] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_1 ; "chasm"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_1210] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_18 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, CelSaved	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_pcx ; ".pcx"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPUTL.PAS" 782
//@ 		inc	CelSaved	; uint16_t
//@ ; #line	"CSPUTL.PAS" 783
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		mov	cx, word ptr VideoH ; int32_t
//@ 		mov	bx, word ptr VideoH+2 ;	int32_t
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	[bp+PSize], ax	; int32_t
//@ 		mov	[bp+var_1008], dx
//@ ; #line	"CSPUTL.PAS" 784
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"CSPUTL.PAS" 785
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	@Rewrite$qm4File4Word ;	Rewrite(var f: File; recsize: Word)
//@ ; #line	"CSPUTL.PAS" 786
//@ 		mov	[bp+DBofs], 1	; uint16_t
//@ ; #line	"CSPUTL.PAS" 789
//@ 		mov	[bp+HDR], 0Ah	; struct PCXHeader
//@ ; #line	"CSPUTL.PAS" 790
//@ 		mov	[bp+var_110F], 5
//@ ; #line	"CSPUTL.PAS" 791
//@ 		mov	[bp+var_110E], 1
//@ ; #line	"CSPUTL.PAS" 792
//@ 		mov	[bp+var_110D], 8
//@ ; #line	"CSPUTL.PAS" 793
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+var_110C], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+var_110A], ax
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+var_1108], ax
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+var_1106], ax
//@ ; #line	"CSPUTL.PAS" 794
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2233F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2233B:				; CODE XREF: SavePicture+F0j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2233F:				; CODE XREF: SavePicture+DCj
//@ 		mov	di, n$0		; int16_t
//@ 		mov	[bp+di+var_1101], 0FFh
//@ 		cmp	n$0, 2Fh ; '/'  ; int16_t
//@ 		jnz	short loc_2233B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 795
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+var_1104], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp-1102h], ax
//@ ; #line	"CSPUTL.PAS" 796
//@ 		mov	[bp+var_10CF], 1
//@ ; #line	"CSPUTL.PAS" 797
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	[bp+var_10CE], ax
//@ ; #line	"CSPUTL.PAS" 798
//@ 		mov	[bp+var_10CC], 1
//@ ; #line	"CSPUTL.PAS" 800
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+HDR]	; struct PCXHeader
//@ 		push	ss
//@ 		push	di
//@ 		push	80h ; '€'
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 801
//@ 		mov	ax, [bp+PSize]	; int32_t
//@ 		mov	dx, [bp+var_1008]
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+var_1114], ax
//@ 		mov	[bp+var_1112], dx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, [bp+var_1112] ; Compare Two	Operands
//@ 		jle	short loc_223A8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_2251C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_223A8:				; CODE XREF: SavePicture+146j
//@ 		jl	short loc_223B3	; Jump if Less (SF!=OF)
//@ 		cmp	ax, [bp+var_1114] ; Compare Two	Operands
//@ 		jbe	short loc_223B3	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2251C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_223B3:				; CODE XREF: SavePicture:loc_223A8j
//@ 					; SavePicture+151j
//@ 		mov	[bp+DTOfs], ax	; int32_t
//@ 		mov	[bp+var_1004], dx
//@ 		jmp	short loc_223C7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_223BD:				; CODE XREF: SavePicture+2B3j
//@ 					; SavePicture+2BCj
//@ 		add	[bp+DTOfs], 1	; int32_t
//@ 		adc	[bp+var_1004], 0 ; Add with Carry
//@ ; #line	"CSPUTL.PAS" 802
//@ 
//@ loc_223C7:				; CODE XREF: SavePicture+15Ej
//@ 		mov	ax, [bp+PSize]	; int32_t
//@ 		mov	dx, [bp+var_1008]
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		cmp	dx, [bp+var_1004] ; Compare Two	Operands
//@ 		jg	short loc_223E9	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_223E0	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_224C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_223E0:				; CODE XREF: SavePicture+17Ej
//@ 		cmp	ax, [bp+DTOfs]	; int32_t
//@ 		ja	short loc_223E9	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_224C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_223E9:				; CODE XREF: SavePicture+17Cj
//@ 					; SavePicture+187j
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1004]
//@ 		add	ax, 1		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		push	bp
//@ 		call	GetB		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		push	ax
//@ 		push	[bp+var_1004]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		pop	dx
//@ 		cmp	al, dl		; Compare Two Operands
//@ 		jz	short loc_22412	; Jump if Zero (ZF=1)
//@ 		jmp	loc_224C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 804
//@ 
//@ loc_22412:				; CODE XREF: SavePicture+1B0j
//@ 		mov	[bp+cnt], 1	; int32_t
//@ 		mov	[bp+var_108C], 0
//@ 		push	[bp+var_1004]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		mov	[bp+b],	al	; uint8_t
//@ ; #line	"CSPUTL.PAS" 806
//@ 
//@ loc_2242E:				; CODE XREF: SavePicture+22Dj
//@ 					; SavePicture+231j
//@ 		add	[bp+cnt], 1	; int32_t
//@ 		adc	[bp+var_108C], 0 ; Add with Carry
//@ ; #line	"CSPUTL.PAS" 807
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1004]
//@ 		add	ax, [bp+cnt]	; int32_t
//@ 		adc	dx, [bp+var_108C] ; Add	with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		push	bp
//@ 		call	GetB		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		cmp	al, [bp+b]	; uint8_t
//@ 		jnz	short loc_22490	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+var_108C], 0 ; Compare Two Operands
//@ 		jg	short loc_22490	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_22464	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+cnt], 3Fh ;	'?' ; int32_t
//@ 		jnb	short loc_22490	; Jump if Not Below (CF=0)
//@ 
//@ loc_22464:				; CODE XREF: SavePicture+1FEj
//@ 		mov	ax, [bp+PSize]	; int32_t
//@ 		mov	dx, [bp+var_1008]
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1004]
//@ 		add	ax, [bp+cnt]	; int32_t
//@ 		adc	dx, [bp+var_108C] ; Add	with Carry
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_22490	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2242E	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_2242E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 808
//@ 
//@ loc_22490:				; CODE XREF: SavePicture+1F5j
//@ 					; SavePicture+1FCj ...
//@ 		sub	[bp+cnt], 1	; int32_t
//@ 		sbb	[bp+var_108C], 0 ; Integer Subtraction with Borrow
//@ ; #line	"CSPUTL.PAS" 809
//@ 		mov	ax, [bp+cnt]	; int32_t
//@ 		mov	dx, [bp+var_108C]
//@ 		add	ax, 0C1h ; 'Á'  ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte	; function nested near PASCAL returns void
//@ 		mov	al, [bp+b]	; uint8_t
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte	; function nested near PASCAL returns void
//@ 		mov	ax, [bp+cnt]	; int32_t
//@ 		mov	dx, [bp+var_108C]
//@ 		add	[bp+DTOfs], ax	; int32_t
//@ 		adc	[bp+var_1004], dx ; Add	with Carry
//@ ; #line	"CSPUTL.PAS" 810
//@ 		jmp	short loc_22502	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 811
//@ 
//@ loc_224C8:				; CODE XREF: SavePicture+180j
//@ 					; SavePicture+189j ...
//@ 		push	[bp+var_1004]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		cmp	al, 0C0h ; 'À'  ; Compare Two Operands
//@ 		jb	short loc_224F1	; Jump if Below	(CF=1)
//@ ; #line	"CSPUTL.PAS" 812
//@ 		push	0FFC1h
//@ 		push	bp
//@ 		call	InsertByte	; function nested near PASCAL returns void
//@ 		push	[bp+var_1004]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte	; function nested near PASCAL returns void
//@ 		jmp	short loc_22502	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 814
//@ 
//@ loc_224F1:				; CODE XREF: SavePicture+279j
//@ 		push	[bp+var_1004]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte	; function nested near PASCAL returns void
//@ 
//@ loc_22502:				; CODE XREF: SavePicture+269j
//@ 					; SavePicture+292j
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1004]
//@ 		cmp	dx, [bp+var_1112] ; Compare Two	Operands
//@ 		jz	short loc_22513	; Jump if Zero (ZF=1)
//@ 		jmp	loc_223BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22513:				; CODE XREF: SavePicture+2B1j
//@ 		cmp	ax, [bp+var_1114] ; Compare Two	Operands
//@ 		jz	short loc_2251C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_223BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 816
//@ 
//@ loc_2251C:				; CODE XREF: SavePicture+148j
//@ 					; SavePicture+153j ...
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+DBuf]	; uint8_t[4096]
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+DBofs]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 818
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_22543	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2253F:				; CODE XREF: SavePicture+314j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_22543:				; CODE XREF: SavePicture+2E0j
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0DF60h
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	di, n$0		; int16_t
//@ 		mov	byte ptr [bp+di+DBofs+1], al ; uint16_t
//@ 		cmp	n$0, 300h	; int16_t
//@ 		jnz	short loc_2253F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 819
//@ 		mov	[bp+b],	0Ch	; uint8_t
//@ ; #line	"CSPUTL.PAS" 820
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+b]	; uint8_t
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 821
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+DBuf]	; uint8_t[4096]
//@ 		push	ss
//@ 		push	di
//@ 		push	300h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 822
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ ; #line	"CSPUTL.PAS" 823
//@ 		lea	di, [bp+var_1210] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aSaved_ ; " saved. ("
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_1310] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a__6	; "##.##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, CurTime	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 88h	; 'ˆ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 0C00h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aS_	; "s.)"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 824
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ SavePicture	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 859
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InsertByte$0	proc near		; CODE XREF: SaveMPicture+237p
//@ 					; SaveMPicture+240p ...
//@ 
//@ var_1002	= word ptr -1002h
//@ arg_0		= word ptr  4
//@ b		= byte ptr  6		; uint8_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 860
//@ 		mov	dl, [bp+b]	; uint8_t
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+var_1002]
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr ss:[di+var_1002+1], dl
//@ 		mov	di, [bp+arg_0]
//@ 		inc	ss:[di+var_1002] ; Increment by	1
//@ ; #line	"CSPUTL.PAS" 861
//@ 		cmp	ss:[di+var_1002], 1000h	; Compare Two Operands
//@ 		jbe	short locret_22657 ; Jump if Below or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 863
//@ 		add	di, 0EF74h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0F000h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_1002], 1
//@ ; #line	"CSPUTL.PAS" 865
//@ 
//@ locret_22657:				; CODE XREF: InsertByte$0+24j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ InsertByte$0	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 868
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns unsigned char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ GetB$0		proc near		; CODE XREF: SaveMPicture+187p
//@ 					; SaveMPicture+194p ...
//@ 
//@ var_1004	= word ptr -1004h
//@ DOf		= word ptr  6		; int32_t
//@ arg_4		= word ptr  8
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 869
//@ 		mov	ax, [bp+arg_4]
//@ ; #line	"CSPUTL.PAS" 870
//@ 		cmp	ax, [bp+var_1004] ; Compare Two	Operands
//@ ; #line	"CSPUTL.PAS" 871
//@ 		jz	short loc_2267B	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 872
//@ 		mov	[bp+var_1004], ax
//@ ; #line	"CSPUTL.PAS" 873
//@ 		mov	dx, ax
//@ ; #line	"CSPUTL.PAS" 874
//@ 		mov	cx, VESABankShift ; uint16_t
//@ ; #line	"CSPUTL.PAS" 875
//@ 		shl	dx, cl		; Shift	Logical	Left
//@ ; #line	"CSPUTL.PAS" 876
//@ 		mov	ax, 4F05h
//@ ; #line	"CSPUTL.PAS" 877
//@ 		mov	bx, 0
//@ ; #line	"CSPUTL.PAS" 878
//@ 		int	10h		; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA	BIOS - CPU VIDEO MEMORY	CONTROL
//@ 					; BL = 00h window A, 01h window	B
//@ 					; Return: AL = 4Fh function supported
//@ 					; AH = 00h successful, 01h failed
//@ 					; BH = subfunctionselect video memory window
//@ ; #line	"CSPUTL.PAS" 880
//@ 
//@ loc_2267B:				; CODE XREF: GetB$0+Aj
//@ 		mov	bx, [bp+DOf]	; int32_t
//@ ; #line	"CSPUTL.PAS" 881
//@ 		mov	ax, SegA000	; uint16_t
//@ ; #line	"CSPUTL.PAS" 882
//@ 		mov	es, ax
//@ ; #line	"CSPUTL.PAS" 883
//@ 		mov	al, es:[bx]
//@ ; #line	"CSPUTL.PAS" 884
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ GetB$0		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_19		db 3,'@##'              ; DATA XREF: SaveMPicture+1Fo
//@ aChasm_2	db 5,'chasm'            ; DATA XREF: SaveMPicture+Fo
//@ a_pcx_0		db 4,'.pcx'             ; DATA XREF: SaveMPicture+3Bo
//@ aSaved__0	db 9,' saved. ('        ; DATA XREF: SaveMPicture+34Fo
//@ a__7		db 5,'##.##'            ; DATA XREF: SaveMPicture+35Fo
//@ aS__0		db 3,'s.)'              ; DATA XREF: SaveMPicture+388o
//@ ; #line	"CSPUTL.PAS" 886
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SaveMPicture	proc far		; CODE XREF: DoGame+2C0P
//@ 
//@ var_1312	= byte ptr -1312h
//@ var_1212	= byte ptr -1212h
//@ var_1116	= word ptr -1116h
//@ var_1114	= word ptr -1114h
//@ HDR		= byte ptr -1112h	; struct PCXHeader
//@ var_1111	= byte ptr -1111h
//@ var_1110	= byte ptr -1110h
//@ var_110F	= byte ptr -110Fh
//@ var_110E	= word ptr -110Eh
//@ var_110C	= word ptr -110Ch
//@ var_110A	= word ptr -110Ah
//@ var_1108	= word ptr -1108h
//@ var_1106	= word ptr -1106h
//@ var_1103	= byte ptr -1103h
//@ var_10D1	= byte ptr -10D1h
//@ var_10D0	= word ptr -10D0h
//@ var_10CE	= word ptr -10CEh
//@ b		= byte ptr -1091h	; uint8_t
//@ cnt		= word ptr -1090h	; int32_t
//@ var_108E	= word ptr -108Eh
//@ f		= byte ptr -108Ch	; FILE
//@ PSize		= word ptr -100Ch	; int32_t
//@ var_100A	= word ptr -100Ah
//@ DTOfs		= word ptr -1008h	; int32_t
//@ var_1006	= word ptr -1006h
//@ LastBank	= word ptr -1004h	; uint16_t
//@ DBofs		= word ptr -1002h	; uint16_t
//@ DBuf		= byte ptr -1000h	; uint8_t[4096]
//@ 
//@ 		enter	1312h, 0	; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 887
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 888
//@ 		lea	di, [bp+var_1312] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_2 ; "chasm"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_1212] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_19 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, CelSaved	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_pcx_0 ; ".pcx"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPUTL.PAS" 889
//@ 		inc	CelSaved	; uint16_t
//@ ; #line	"CSPUTL.PAS" 890
//@ 		mov	[bp+PSize], 0E800h ; int32_t
//@ 		mov	[bp+var_100A], 3
//@ ; #line	"CSPUTL.PAS" 891
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"CSPUTL.PAS" 892
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	@Rewrite$qm4File4Word ;	Rewrite(var f: File; recsize: Word)
//@ ; #line	"CSPUTL.PAS" 893
//@ 		mov	[bp+DBofs], 1	; uint16_t
//@ ; #line	"CSPUTL.PAS" 896
//@ 		mov	[bp+HDR], 0Ah	; struct PCXHeader
//@ ; #line	"CSPUTL.PAS" 897
//@ 		mov	[bp+var_1111], 5
//@ ; #line	"CSPUTL.PAS" 898
//@ 		mov	[bp+var_1110], 1
//@ ; #line	"CSPUTL.PAS" 899
//@ 		mov	[bp+var_110F], 8
//@ ; #line	"CSPUTL.PAS" 900
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+var_110E], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+var_110C], ax
//@ 		mov	[bp+var_110A], 27Fh
//@ 		mov	[bp+var_1108], 18Fh
//@ ; #line	"CSPUTL.PAS" 901
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_22769	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22765:				; CODE XREF: SaveMPicture+CAj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_22769:				; CODE XREF: SaveMPicture+B6j
//@ 		mov	di, n$0		; int16_t
//@ 		mov	[bp+di+var_1103], 0FFh
//@ 		cmp	n$0, 2Fh ; '/'  ; int16_t
//@ 		jnz	short loc_22765	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 902
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+var_1106], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp-1104h], ax
//@ ; #line	"CSPUTL.PAS" 903
//@ 		mov	[bp+var_10D1], 1
//@ ; #line	"CSPUTL.PAS" 904
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	[bp+var_10D0], ax
//@ ; #line	"CSPUTL.PAS" 905
//@ 		mov	[bp+var_10CE], 1
//@ ; #line	"CSPUTL.PAS" 909
//@ 		mov	[bp+LastBank], 0 ; uint16_t
//@ ; #line	"CSPUTL.PAS" 910
//@ 		mov	ax, 4F05h
//@ ; #line	"CSPUTL.PAS" 911
//@ 		mov	bx, 0
//@ ; #line	"CSPUTL.PAS" 912
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ ; #line	"CSPUTL.PAS" 913
//@ 		int	10h		; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA	BIOS - CPU VIDEO MEMORY	CONTROL
//@ 					; BL = 00h window A, 01h window	B
//@ 					; Return: AL = 4Fh function supported
//@ 					; AH = 00h successful, 01h failed
//@ 					; BH = subfunctionselect video memory window
//@ ; #line	"CSPUTL.PAS" 916
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+HDR]	; struct PCXHeader
//@ 		push	ss
//@ 		push	di
//@ 		push	80h ; '€'
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 917
//@ 		mov	ax, [bp+PSize]	; int32_t
//@ 		mov	dx, [bp+var_100A]
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+var_1116], ax
//@ 		mov	[bp+var_1114], dx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, [bp+var_1114] ; Compare Two	Operands
//@ 		jle	short loc_227E2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_22956	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_227E2:				; CODE XREF: SaveMPicture+130j
//@ 		jl	short loc_227ED	; Jump if Less (SF!=OF)
//@ 		cmp	ax, [bp+var_1116] ; Compare Two	Operands
//@ 		jbe	short loc_227ED	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_22956	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_227ED:				; CODE XREF: SaveMPicture:loc_227E2j
//@ 					; SaveMPicture+13Bj
//@ 		mov	[bp+DTOfs], ax	; int32_t
//@ 		mov	[bp+var_1006], dx
//@ 		jmp	short loc_22801	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_227F7:				; CODE XREF: SaveMPicture+29Dj
//@ 					; SaveMPicture+2A6j
//@ 		add	[bp+DTOfs], 1	; int32_t
//@ 		adc	[bp+var_1006], 0 ; Add with Carry
//@ ; #line	"CSPUTL.PAS" 918
//@ 
//@ loc_22801:				; CODE XREF: SaveMPicture+148j
//@ 		mov	ax, [bp+PSize]	; int32_t
//@ 		mov	dx, [bp+var_100A]
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		cmp	dx, [bp+var_1006] ; Compare Two	Operands
//@ 		jg	short loc_22823	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_2281A	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_22902	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2281A:				; CODE XREF: SaveMPicture+168j
//@ 		cmp	ax, [bp+DTOfs]	; int32_t
//@ 		ja	short loc_22823	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_22902	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22823:				; CODE XREF: SaveMPicture+166j
//@ 					; SaveMPicture+171j
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1006]
//@ 		add	ax, 1		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		push	bp
//@ 		call	GetB$0		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		push	ax
//@ 		push	[bp+var_1006]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB$0		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		pop	dx
//@ 		cmp	al, dl		; Compare Two Operands
//@ 		jz	short loc_2284C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_22902	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 920
//@ 
//@ loc_2284C:				; CODE XREF: SaveMPicture+19Aj
//@ 		mov	[bp+cnt], 1	; int32_t
//@ 		mov	[bp+var_108E], 0
//@ 		push	[bp+var_1006]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB$0		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		mov	[bp+b],	al	; uint8_t
//@ ; #line	"CSPUTL.PAS" 922
//@ 
//@ loc_22868:				; CODE XREF: SaveMPicture+217j
//@ 					; SaveMPicture+21Bj
//@ 		add	[bp+cnt], 1	; int32_t
//@ 		adc	[bp+var_108E], 0 ; Add with Carry
//@ ; #line	"CSPUTL.PAS" 923
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1006]
//@ 		add	ax, [bp+cnt]	; int32_t
//@ 		adc	dx, [bp+var_108E] ; Add	with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		push	bp
//@ 		call	GetB$0		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		cmp	al, [bp+b]	; uint8_t
//@ 		jnz	short loc_228CA	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+var_108E], 0 ; Compare Two Operands
//@ 		jg	short loc_228CA	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2289E	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+cnt], 3Fh ;	'?' ; int32_t
//@ 		jnb	short loc_228CA	; Jump if Not Below (CF=0)
//@ 
//@ loc_2289E:				; CODE XREF: SaveMPicture+1E8j
//@ 		mov	ax, [bp+PSize]	; int32_t
//@ 		mov	dx, [bp+var_100A]
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1006]
//@ 		add	ax, [bp+cnt]	; int32_t
//@ 		adc	dx, [bp+var_108E] ; Add	with Carry
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_228CA	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_22868	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_22868	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 924
//@ 
//@ loc_228CA:				; CODE XREF: SaveMPicture+1DFj
//@ 					; SaveMPicture+1E6j ...
//@ 		sub	[bp+cnt], 1	; int32_t
//@ 		sbb	[bp+var_108E], 0 ; Integer Subtraction with Borrow
//@ ; #line	"CSPUTL.PAS" 925
//@ 		mov	ax, [bp+cnt]	; int32_t
//@ 		mov	dx, [bp+var_108E]
//@ 		add	ax, 0C1h ; 'Á'  ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte$0	; function nested near PASCAL returns void
//@ 		mov	al, [bp+b]	; uint8_t
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte$0	; function nested near PASCAL returns void
//@ 		mov	ax, [bp+cnt]	; int32_t
//@ 		mov	dx, [bp+var_108E]
//@ 		add	[bp+DTOfs], ax	; int32_t
//@ 		adc	[bp+var_1006], dx ; Add	with Carry
//@ ; #line	"CSPUTL.PAS" 926
//@ 		jmp	short loc_2293C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 927
//@ 
//@ loc_22902:				; CODE XREF: SaveMPicture+16Aj
//@ 					; SaveMPicture+173j ...
//@ 		push	[bp+var_1006]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB$0		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		cmp	al, 0C0h ; 'À'  ; Compare Two Operands
//@ 		jb	short loc_2292B	; Jump if Below	(CF=1)
//@ ; #line	"CSPUTL.PAS" 928
//@ 		push	0FFC1h
//@ 		push	bp
//@ 		call	InsertByte$0	; function nested near PASCAL returns void
//@ 		push	[bp+var_1006]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB$0		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte$0	; function nested near PASCAL returns void
//@ 		jmp	short loc_2293C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 930
//@ 
//@ loc_2292B:				; CODE XREF: SaveMPicture+263j
//@ 		push	[bp+var_1006]
//@ 		push	[bp+DTOfs]	; int32_t
//@ 		push	bp
//@ 		call	GetB$0		; function nested near PASCAL returns unsigned char 'Byte'
//@ 		push	ax
//@ 		push	bp
//@ 		call	InsertByte$0	; function nested near PASCAL returns void
//@ 
//@ loc_2293C:				; CODE XREF: SaveMPicture+253j
//@ 					; SaveMPicture+27Cj
//@ 		mov	ax, [bp+DTOfs]	; int32_t
//@ 		mov	dx, [bp+var_1006]
//@ 		cmp	dx, [bp+var_1114] ; Compare Two	Operands
//@ 		jz	short loc_2294D	; Jump if Zero (ZF=1)
//@ 		jmp	loc_227F7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2294D:				; CODE XREF: SaveMPicture+29Bj
//@ 		cmp	ax, [bp+var_1116] ; Compare Two	Operands
//@ 		jz	short loc_22956	; Jump if Zero (ZF=1)
//@ 		jmp	loc_227F7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 932
//@ 
//@ loc_22956:				; CODE XREF: SaveMPicture+132j
//@ 					; SaveMPicture+13Dj ...
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+DBuf]	; uint8_t[4096]
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+DBofs]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 934
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_2297D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22979:				; CODE XREF: SaveMPicture+2FEj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2297D:				; CODE XREF: SaveMPicture+2CAj
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0DF60h
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	di, n$0		; int16_t
//@ 		mov	byte ptr [bp+di+DBofs+1], al ; uint16_t
//@ 		cmp	n$0, 300h	; int16_t
//@ 		jnz	short loc_22979	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 935
//@ 		mov	[bp+b],	0Ch	; uint8_t
//@ ; #line	"CSPUTL.PAS" 936
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+b]	; uint8_t
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 937
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+DBuf]	; uint8_t[4096]
//@ 		push	ss
//@ 		push	di
//@ 		push	300h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSPUTL.PAS" 938
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ ; #line	"CSPUTL.PAS" 939
//@ 		lea	di, [bp+var_1212] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aSaved__0 ; " saved.	("
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_1312] ; Load Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a__7	; "##.##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, CurTime	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 88h	; 'ˆ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 0C00h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aS__0 ; "s.)"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 940
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ SaveMPicture	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 948
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetJoyStatus	proc far		; CODE XREF: ProcessMenu+10P
//@ 					; ProcessDevices+206P
//@ 
//@ b		= byte ptr -1		; uint8_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 949
//@ 		cmp	JoyStick, 0	; bool
//@ 		jnz	short loc_22A54	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_22BDF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 951
//@ 
//@ loc_22A54:				; CODE XREF: GetJoyStatus+9j
//@ 		mov	dx, 201h
//@ 		in	al, dx		; Game I/O port
//@ 					; bits 0-3: Coordinates	(resistive, time-dependent inputs)
//@ 					; bits 4-7: Buttons/Triggers (digital inputs)
//@ 		mov	[bp+b],	al	; uint8_t
//@ ; #line	"CSPUTL.PAS" 952
//@ 		cmp	MsKeyA,	0	; bool
//@ 		jnz	short loc_22A6F	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+b]	; uint8_t
//@ 		and	al, 10h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_22A6F	; Jump if Zero (ZF=1)
//@ 		mov	al, 0
//@ 		jmp	short loc_22A71	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22A6F:				; CODE XREF: GetJoyStatus+1Aj
//@ 					; GetJoyStatus+23j
//@ 		mov	al, 1
//@ 
//@ loc_22A71:				; CODE XREF: GetJoyStatus+27j
//@ 		mov	MsKeyA,	al	; bool
//@ ; #line	"CSPUTL.PAS" 953
//@ 		cmp	MsKeyB,	0	; bool
//@ 		jnz	short loc_22A88	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+b]	; uint8_t
//@ 		and	al, 20h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_22A88	; Jump if Zero (ZF=1)
//@ 		mov	al, 0
//@ 		jmp	short loc_22A8A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22A88:				; CODE XREF: GetJoyStatus+33j
//@ 					; GetJoyStatus+3Cj
//@ 		mov	al, 1
//@ 
//@ loc_22A8A:				; CODE XREF: GetJoyStatus+40j
//@ 		mov	MsKeyB,	al	; bool
//@ ; #line	"CSPUTL.PAS" 954
//@ 		push	14h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	GetJoyX		; function far PASCAL returns signed int 'Integer'
//@ ; #line	"CSPUTL.PAS" 955
//@ 		push	14h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	GetJoyY		; function far PASCAL returns signed int 'Integer'
//@ ; #line	"CSPUTL.PAS" 957
//@ 		mov	ax, JoyX	; int16_t
//@ 		cmp	ax, JoyMnX	; int16_t
//@ 		jge	short loc_22AB4	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, JoyX	; int16_t
//@ 		mov	JoyMnX,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 958
//@ 
//@ loc_22AB4:				; CODE XREF: GetJoyStatus+66j
//@ 		mov	ax, JoyY	; int16_t
//@ 		cmp	ax, JoyMnY	; int16_t
//@ 		jge	short loc_22AC3	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, JoyY	; int16_t
//@ 		mov	JoyMnY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 959
//@ 
//@ loc_22AC3:				; CODE XREF: GetJoyStatus+75j
//@ 		mov	ax, JoyX	; int16_t
//@ 		cmp	ax, JoyMxX	; int16_t
//@ 		jle	short loc_22AD2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, JoyX	; int16_t
//@ 		mov	JoyMxX,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 960
//@ 
//@ loc_22AD2:				; CODE XREF: GetJoyStatus+84j
//@ 		mov	ax, JoyY	; int16_t
//@ 		cmp	ax, JoyMxY	; int16_t
//@ 		jle	short loc_22AE1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, JoyY	; int16_t
//@ 		mov	JoyMxY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 962
//@ 
//@ loc_22AE1:				; CODE XREF: GetJoyStatus+93j
//@ 		mov	ax, JoyY	; int16_t
//@ 		sub	ax, JoyCrY	; int16_t
//@ 		mov	JoyY, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 963
//@ 		mov	ax, JoyX	; int16_t
//@ 		sub	ax, JoyCrX	; int16_t
//@ 		mov	JoyX, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 965
//@ 		cmp	JoyX, 0		; int16_t
//@ 		jle	short loc_22B23	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, JoyMxX	; int16_t
//@ 		sub	ax, JoyCrX	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, JoyX	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 19Ch
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	JoyX, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 966
//@ 
//@ loc_22B23:				; CODE XREF: GetJoyStatus+B4j
//@ 		cmp	JoyX, 0		; int16_t
//@ 		jge	short loc_22B51	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, JoyMnX	; int16_t
//@ 		sub	ax, JoyCrX	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, JoyX	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 19Ch
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	JoyX, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 967
//@ 
//@ loc_22B51:				; CODE XREF: GetJoyStatus+E2j
//@ 		cmp	JoyY, 0		; int16_t
//@ 		jle	short loc_22B7F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, JoyMxY	; int16_t
//@ 		sub	ax, JoyCrY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, JoyY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 19Ch
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	JoyY, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 968
//@ 
//@ loc_22B7F:				; CODE XREF: GetJoyStatus+110j
//@ 		cmp	JoyY, 0		; int16_t
//@ 		jge	short loc_22BAD	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, JoyMnY	; int16_t
//@ 		sub	ax, JoyCrY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, JoyY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 19Ch
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	JoyY, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 970
//@ 
//@ loc_22BAD:				; CODE XREF: GetJoyStatus+13Ej
//@ 		mov	ax, JoyX	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_22BBF	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	JoyX, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 971
//@ 
//@ loc_22BBF:				; CODE XREF: GetJoyStatus+172j
//@ 		mov	ax, JoyY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_22BD1	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	JoyY, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 972
//@ 
//@ loc_22BD1:				; CODE XREF: GetJoyStatus+184j
//@ 		mov	ax, JoyX	; int16_t
//@ 		add	MsRv, ax	; int16_t
//@ 		mov	ax, JoyY	; int16_t
//@ 		add	MsVV, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 973
//@ 
//@ locret_22BDF:				; CODE XREF: GetJoyStatus+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ GetJoyStatus	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 977
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CheckJoyStick	proc far		; CODE XREF: PROGRAM+669P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 978
//@ 		mov	dx, 201h
//@ 		in	al, dx		; Game I/O port
//@ 					; bits 0-3: Coordinates	(resistive, time-dependent inputs)
//@ 					; bits 4-7: Buttons/Triggers (digital inputs)
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 979
//@ 		push	14h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	GetJoyX		; function far PASCAL returns signed int 'Integer'
//@ ; #line	"CSPUTL.PAS" 980
//@ 		push	14h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	GetJoyY		; function far PASCAL returns signed int 'Integer'
//@ ; #line	"CSPUTL.PAS" 981
//@ 		cmp	JoyX, 7D00h	; int16_t
//@ 		jz	short locret_22C1A ; Jump if Zero (ZF=1)
//@ 		cmp	JoyY, 7D00h	; int16_t
//@ 		jz	short locret_22C1A ; Jump if Zero (ZF=1)
//@ 		mov	JoyStick, 1	; bool
//@ ; #line	"CSPUTL.PAS" 982
//@ 
//@ locret_22C1A:				; CODE XREF: CheckJoyStick+2Aj
//@ 					; CheckJoyStick+32j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ CheckJoyStick	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 985
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitJoyStick	proc far		; CODE XREF: PROGRAM+D24P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 986
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	JoyCrX,	ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	JoyCrY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 987
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_22C34	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22C30:				; CODE XREF: InitJoyStick+73j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPUTL.PAS" 989
//@ 
//@ loc_22C34:				; CODE XREF: InitJoyStick+12j
//@ 		mov	dx, 201h
//@ 		in	al, dx		; Game I/O port
//@ 					; bits 0-3: Coordinates	(resistive, time-dependent inputs)
//@ 					; bits 4-7: Buttons/Triggers (digital inputs)
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 990
//@ 		mov	ax, w		; uint16_t
//@ 		and	ax, 10h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jnz	short loc_22C4A	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_22C4A:				; CODE XREF: InitJoyStick+2Bj
//@ 		mov	MsKeyA,	al	; bool
//@ ; #line	"CSPUTL.PAS" 991
//@ 		mov	ax, w		; uint16_t
//@ 		and	ax, 20h		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jnz	short loc_22C5A	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_22C5A:				; CODE XREF: InitJoyStick+3Bj
//@ 		mov	MsKeyB,	al	; bool
//@ ; #line	"CSPUTL.PAS" 992
//@ 		push	14h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	GetJoyX		; function far PASCAL returns signed int 'Integer'
//@ ; #line	"CSPUTL.PAS" 993
//@ 		push	14h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	GetJoyY		; function far PASCAL returns signed int 'Integer'
//@ ; #line	"CSPUTL.PAS" 994
//@ 		mov	ax, JoyX	; int16_t
//@ 		add	JoyCrX,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 995
//@ 		mov	ax, JoyY	; int16_t
//@ 		add	JoyCrY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 996
//@ 		push	64h ; 'd'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 997
//@ 		cmp	n$0, 0Fh	; int16_t
//@ 		jnz	short loc_22C30	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 998
//@ 		mov	ax, JoyCrX	; int16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	JoyCrX,	ax	; int16_t
//@ 		mov	ax, JoyCrY	; int16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	JoyCrY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1000
//@ 		mov	ax, JoyCrX	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	JoyMnX,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1001
//@ 		mov	ax, JoyCrY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	JoyMnY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1002
//@ 		mov	ax, JoyCrX	; int16_t
//@ 		add	ax, JoyMnX	; int16_t
//@ 		mov	JoyMxX,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1003
//@ 		mov	ax, JoyCrY	; int16_t
//@ 		add	ax, JoyMnY	; int16_t
//@ 		mov	JoyMxY,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1004
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitJoyStick	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1008
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetMouseStatus	proc far		; CODE XREF: ProcessMenu+BP
//@ 					; ProcessDevices:loc_A471P ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 1009
//@ 		cmp	MouseD,	0	; bool
//@ 		jz	short loc_22CE4	; Jump if Zero (ZF=1)
//@ 		mov	ax, word ptr PInfoStruct ; TInfo_Struct*
//@ 		or	ax, word ptr PInfoStruct+2 ; TInfo_Struct*
//@ 		jnz	short loc_22D0A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1011
//@ 
//@ loc_22CE4:				; CODE XREF: GetMouseStatus+8j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MsRv, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MsVV, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1012
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	msrvi, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Msvvi, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1013
//@ 		mov	MsKeyA,	0	; bool
//@ ; #line	"CSPUTL.PAS" 1014
//@ 		mov	MsKeyB,	0	; bool
//@ ; #line	"CSPUTL.PAS" 1015
//@ 		mov	MsKeyC,	0	; bool
//@ ; #line	"CSPUTL.PAS" 1016
//@ 		jmp	locret_22E2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1021
//@ 
//@ loc_22D0A:				; CODE XREF: GetMouseStatus+11j
//@ 		call	getmousestate	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1024
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	ax, es:[di+188h]
//@ 		mov	MsX, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1025
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	ax, es:[di+18Ah]
//@ 		mov	MsY, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1026
//@ 		cmp	LastMouseX, 0	; int16_t
//@ 		jnz	short loc_22D41	; Jump if Not Zero (ZF=0)
//@ 		cmp	LastMouseY, 0	; int16_t
//@ 		jnz	short loc_22D41	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1027
//@ 		mov	ax, MsX		; int16_t
//@ 		mov	LastMouseX, ax	; int16_t
//@ 		mov	ax, MsY		; int16_t
//@ 		mov	LastMouseY, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1029
//@ 
//@ loc_22D41:				; CODE XREF: GetMouseStatus+5Bj
//@ 					; GetMouseStatus+62j
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_22D9C	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1031
//@ 		mov	al, MSsens	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 4		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, MsX		; int16_t
//@ 		sub	ax, LastMouseX	; int16_t
//@ 		mul	dx		; Unsigned Multiplication of AL	or AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	bx, ax
//@ 		mov	ax, MsRv	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, bx		; Add
//@ 		mov	MsRv, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1032
//@ 		mov	al, MSsens	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 4		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, MsY		; int16_t
//@ 		sub	ax, LastMouseY	; int16_t
//@ 		mul	dx		; Unsigned Multiplication of AL	or AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	bx, ax
//@ 		mov	ax, MsVV	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, bx		; Add
//@ 		mov	MsVV, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1033
//@ 		jmp	short loc_22DEE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1035
//@ 
//@ loc_22D9C:				; CODE XREF: GetMouseStatus+75j
//@ 		mov	al, MSsens	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 6		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, MsX		; int16_t
//@ 		sub	ax, LastMouseX	; int16_t
//@ 		mul	dx		; Unsigned Multiplication of AL	or AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	bx, ax
//@ 		mov	ax, MsRv	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, bx		; Add
//@ 		mov	MsRv, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1036
//@ 		mov	al, MSsens	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 4		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, MsY		; int16_t
//@ 		sub	ax, LastMouseY	; int16_t
//@ 		mul	dx		; Unsigned Multiplication of AL	or AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	bx, ax
//@ 		mov	ax, MsVV	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, bx		; Add
//@ 		mov	MsVV, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1039
//@ 
//@ loc_22DEE:				; CODE XREF: GetMouseStatus+C9j
//@ 		mov	ax, MsX		; int16_t
//@ 		mov	LastMouseX, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1040
//@ 		mov	ax, MsY		; int16_t
//@ 		mov	LastMouseY, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1043
//@ 		mov	ax, MsButt	; int16_t
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jz	short loc_22E07	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_22E07:				; CODE XREF: GetMouseStatus+133j
//@ 		mov	MsKeyA,	al	; bool
//@ ; #line	"CSPUTL.PAS" 1044
//@ 		mov	ax, MsButt	; int16_t
//@ 		and	ax, 2		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jz	short loc_22E17	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_22E17:				; CODE XREF: GetMouseStatus+143j
//@ 		mov	MsKeyB,	al	; bool
//@ ; #line	"CSPUTL.PAS" 1045
//@ 		mov	ax, MsButt	; int16_t
//@ 		and	ax, 4		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jz	short loc_22E27	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_22E27:				; CODE XREF: GetMouseStatus+153j
//@ 		mov	MsKeyC,	al	; bool
//@ ; #line	"CSPUTL.PAS" 1048
//@ 
//@ locret_22E2A:				; CODE XREF: GetMouseStatus+36j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ GetMouseStatus	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1054
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FillStartInfo	proc far		; CODE XREF: PROGRAM:loc_EF6BP
//@ 					; PROGRAM+DF2P	...
//@ 
//@ var_8		= word ptr -8
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1055
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSPUTL.PAS" 1057
//@ 		mov	ax, WeaponsCount ; uint16_t
//@ 		mov	[bp+var_8], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jg	short loc_22E6C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_22E57	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22E54:				; CODE XREF: FillStartInfo+3Ej
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_22E57:				; CODE XREF: FillStartInfo+26j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+2Dh], 0
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jnz	short loc_22E54	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1058
//@ 
//@ loc_22E6C:				; CODE XREF: FillStartInfo+21j
//@ 		mov	al, byte ptr GunsInfo.StartCount ; struct TGunInfo[9]
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2Eh], al
//@ ; #line	"CSPUTL.PAS" 1059
//@ 		mov	word ptr es:[di+28h], 64h ; 'd'
//@ ; #line	"CSPUTL.PAS" 1060
//@ 		mov	byte ptr es:[di+25h], 41h ; 'A'
//@ 		mov	byte ptr es:[di+27h], 0
//@ ; #line	"CSPUTL.PAS" 1061
//@ 		mov	word ptr es:[di+48h], 1
//@ ; #line	"CSPUTL.PAS" 1062
//@ 		mov	LastGunNumber, 1 ; uint16_t
//@ ; #line	"CSPUTL.PAS" 1063
//@ 		mov	GunShift, 2Eh ;	'.' ; uint16_t
//@ ; #line	"CSPUTL.PAS" 1064
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSPUTL.PAS" 1066
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ FillStartInfo	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aKill		db 4,'KILL'             ; DATA XREF: InitMessageSystem+1Co
//@ aAmmo		db 4,'AMMO'             ; DATA XREF: InitMessageSystem+2Eo
//@ aWeapon		db 6,'WEAPON'           ; DATA XREF: InitMessageSystem+44o
//@ aChojin_0	db 6,'CHOJIN'           ; DATA XREF: InitMessageSystem+5Ao
//@ ; #line	"CSPUTL.PAS" 1076
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitMessageSystem proc far		; CODE XREF: PROGRAM+24EP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 1077
//@ 		mov	HistCnt, 4	; int16_t
//@ 		mov	CurHist, 5	; int16_t
//@ ; #line	"CSPUTL.PAS" 1078
//@ 		mov	di, offset ConsHistory ; char*
//@ 		push	ds
//@ 		push	di
//@ 		push	0A00h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1079
//@ 		mov	di, offset aKill ; "KILL"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, ConsHistory	; char*
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPUTL.PAS" 1080
//@ 		mov	di, offset aAmmo ; "AMMO"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, 28h	; '('   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPUTL.PAS" 1081
//@ 		mov	di, offset aWeapon ; "WEAPON"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, 50h	; 'P'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPUTL.PAS" 1082
//@ 		mov	di, offset aChojin_0 ; "CHOJIN"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, ConsHistory	; char*
//@ 		add	di, 78h	; 'x'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPUTL.PAS" 1083
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitMessageSystem endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1088
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RemoveLight	proc far		; CODE XREF: DoneChanges+AAP
//@ 					; Blow3dObjAt+398P
//@ 
//@ var_A		= word ptr -0Ah
//@ i		= word ptr -8		; int16_t
//@ Lnm		= word ptr -6		; int16_t
//@ Rm		= word ptr -4		; int16_t
//@ R		= word ptr -2		; int16_t
//@ ly1		= word ptr  6		; int16_t
//@ lx1		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1089
//@ 		mov	[bp+Rm], 0C8h ;	'È' ; int16_t
//@ 		mov	[bp+Lnm], 0FFFFh ; int16_t
//@ ; #line	"CSPUTL.PAS" 1090
//@ 		mov	ax, LtCount	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_A], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jg	short loc_22F92	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_22F4E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_22F4B:				; CODE XREF: RemoveLight+66j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1091
//@ 
//@ loc_22F4E:				; CODE XREF: RemoveLight+1Fj
//@ 		imul	ax, [bp+i], 0Ch	; int16_t
//@ 		les	di, Lights	; TLight*
//@ 		add	di, ax		; Add
//@ ; #line	"CSPUTL.PAS" 1093
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+ly1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+lx1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	[bp+R],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1094
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		cmp	ax, [bp+Rm]	; int16_t
//@ 		jge	short loc_22F8A	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		mov	[bp+Rm], ax	; int16_t
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		mov	[bp+Lnm], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1095
//@ 
//@ loc_22F8A:				; CODE XREF: RemoveLight+52j
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jnz	short loc_22F4B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1096
//@ 
//@ loc_22F92:				; CODE XREF: RemoveLight+1Aj
//@ 		cmp	[bp+Lnm], 0FFFFh ; int16_t
//@ 		jnz	short loc_22F9A	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_22FF9 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1097
//@ 
//@ loc_22F9A:				; CODE XREF: RemoveLight+6Cj
//@ 		imul	ax, [bp+Lnm], 0Ch ; int16_t
//@ 		les	di, Lights	; TLight*
//@ 		add	di, ax		; Add
//@ ; #line	"CSPUTL.PAS" 1098
//@ 		mov	ax, es:[di]
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		push	ax
//@ 		mov	ax, es:[di+8]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		add	ax, 3		; Add
//@ 		push	ax
//@ 		push	1
//@ 		call	BackRender	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1099
//@ 		mov	ax, [bp+Lnm]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 0Ch		; Signed Multiply
//@ 		les	di, Lights	; TLight*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, [bp+Lnm], 0Ch ; int16_t
//@ 		les	di, Lights	; TLight*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 0FEh ; 'þ'
//@ 		sub	ax, [bp+Lnm]	; int16_t
//@ 		imul	ax, 0Ch		; Signed Multiply
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPUTL.PAS" 1100
//@ 		dec	LtCount		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1101
//@ 
//@ locret_22FF9:				; CODE XREF: RemoveLight+6Ej
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ RemoveLight	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1113
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddGreatBlow	proc far		; CODE XREF: AnimateRockets+707P
//@ 					; ExecuteEvent+131P ...
//@ 
//@ j		= word ptr -2		; int16_t
//@ z		= word ptr  6		; int16_t
//@ y		= word ptr  8		; int16_t
//@ x		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1114
//@ 		push	67h ; 'g'
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1116
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	9
//@ 		push	24h ; '$'
//@ 		push	40h ; '@'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1117
//@ 		cmp	word ptr VPSize+2, 1 ; int32_t
//@ 		jl	short loc_23037	; Jump if Less (SF!=OF)
//@ 		jg	short loc_2308B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	word ptr VPSize, 5F90h ; int32_t
//@ 		jnb	short loc_2308B	; Jump if Not Below (CF=0)
//@ ; #line	"CSPUTL.PAS" 1118
//@ 
//@ loc_23037:				; CODE XREF: AddGreatBlow+2Ej
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_23041	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2303E:				; CODE XREF: AddGreatBlow+89j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1119
//@ 
//@ loc_23041:				; CODE XREF: AddGreatBlow+3Fj
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	26h ; '&'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFEDh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	26h ; '&'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFEDh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	0F0h ; 'ð'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFD8h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	8
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	1Fh	; int16_t
//@ 		jnz	short loc_2303E	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2315A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1124
//@ 
//@ loc_2308B:				; CODE XREF: AddGreatBlow+30j
//@ 					; AddGreatBlow+38j
//@ 		cmp	word ptr VPSize+2, 2 ; int32_t
//@ 		jl	short loc_230B6	; Jump if Less (SF!=OF)
//@ 		jg	short loc_2309C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	word ptr VPSize, 7100h ; int32_t
//@ 		jb	short loc_230B6	; Jump if Below	(CF=1)
//@ 
//@ loc_2309C:				; CODE XREF: AddGreatBlow+95j
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		sub	ax, ehx		; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		sub	ax, ehy		; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 200h	; Compare Two Operands
//@ 		jbe	short loc_23109	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 1125
//@ 
//@ loc_230B6:				; CODE XREF: AddGreatBlow+93j
//@ 					; AddGreatBlow+9Dj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_230C0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_230BD:				; CODE XREF: AddGreatBlow+108j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1126
//@ 
//@ loc_230C0:				; CODE XREF: AddGreatBlow+BEj
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	20h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFF0h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	20h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFF0h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	0B4h ; '´'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFE2h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	8
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	0Ch	; int16_t
//@ 		jnz	short loc_230BD	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_2315A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1131
//@ 
//@ loc_23109:				; CODE XREF: AddGreatBlow+B7j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_23113	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23110:				; CODE XREF: AddGreatBlow+15Bj
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1132
//@ 
//@ loc_23113:				; CODE XREF: AddGreatBlow+111j
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	1Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFF3h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	1Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFF3h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	0AAh ; 'ª'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFE2h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	8
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	5	; int16_t
//@ 		jnz	short loc_23110	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1138
//@ 
//@ loc_2315A:				; CODE XREF: AddGreatBlow+8Bj
//@ 					; AddGreatBlow+10Aj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_23164	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23161:				; CODE XREF: AddGreatBlow+1ACj
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1139
//@ 
//@ loc_23164:				; CODE XREF: AddGreatBlow+162j
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFECh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFECh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	140h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFECh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	11h
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	0Ch	; int16_t
//@ 		jnz	short loc_23161	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1143
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ AddGreatBlow	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1149
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddSuperGreatBlow proc far		; CODE XREF: AnimateRockets+726P
//@ 					; ExecuteEvent+146P
//@ 
//@ j		= word ptr -2		; int16_t
//@ z		= word ptr  6		; int16_t
//@ y		= word ptr  8		; int16_t
//@ x		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1150
//@ 		push	47h ; 'G'
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1151
//@ 		mov	BShadeLev, 34h ; '4' ; int16_t
//@ ; #line	"CSPUTL.PAS" 1153
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	9
//@ 		push	24h ; '$'
//@ 		push	40h ; '@'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1155
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_231E8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_231E5:				; CODE XREF: AddSuperGreatBlow+79j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1156
//@ 
//@ loc_231E8:				; CODE XREF: AddSuperGreatBlow+34j
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFECh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFECh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	140h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 1Eh		; Add
//@ 		push	ax
//@ 		push	11h
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	25h ; '%' ; int16_t
//@ 		jnz	short loc_231E5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1160
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ AddSuperGreatBlow endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1168
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExplodeMine	proc far		; CODE XREF: AnimateRockets+41P
//@ 					; ExecuteEvent+3DP ...
//@ 
//@ mo		= word ptr -8		; int16_t
//@ mz		= word ptr -6		; int16_t
//@ my		= word ptr -4		; int16_t
//@ mx		= word ptr -2		; int16_t
//@ mn		= word ptr  6		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1169
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_2324C	; Jump if Zero (ZF=1)
//@ 		push	45h ; 'E'
//@ 		mov	al, byte ptr [bp+mn] ; int16_t
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1170
//@ 
//@ loc_2324C:				; CODE XREF: ExplodeMine+9j
//@ 		imul	di, [bp+mn], 0Ah ; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPUTL.PAS" 1171
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+mx], ax	; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+my], ax	; int16_t
//@ 		mov	ax, es:[di+6]
//@ 		mov	[bp+mz], ax	; int16_t
//@ 		mov	ax, es:[di+8]
//@ 		mov	[bp+mo], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1172
//@ 		mov	ax, [bp+mn]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	0Ah	; Signed Multiply
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, [bp+mn], 0Ah ; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, 10h
//@ 		sub	ax, [bp+mn]	; int16_t
//@ 		imul	ax, 0Ah		; Signed Multiply
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPUTL.PAS" 1173
//@ 		dec	MnCount		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1174
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+mz]		; int16_t
//@ 		call	AddGreatBlow	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1175
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+mz]		; int16_t
//@ 		push	200h
//@ 		push	0C8h ; 'È'
//@ 		push	[bp+mo]		; int16_t
//@ 		call	MakeBlow	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1176
//@ 		push	0FFFFh
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	28h ; '('
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1177
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ ExplodeMine	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1213
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo$2	proc near		; CODE XREF: Pr_WallCheck+E4p
//@ 					; Pr_WallCheck+120p
//@ 
//@ var_10		= byte ptr -10h
//@ L		= byte ptr -0Ch		; struct TLoc
//@ var_9		= word ptr -9
//@ var_7		= word ptr -7
//@ var_5		= word ptr -5
//@ var_3		= word ptr -3
//@ arg_0		= word ptr  4
//@ arg_2		= dword	ptr  6
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		assume es:nothing
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		mov	cx, 0Bh
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPUTL.PAS" 1215
//@ 		mov	ax, [bp+var_5]
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ 		mov	LWx, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1216
//@ 		mov	ax, [bp+var_3]
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ 		mov	LWy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1217
//@ 		mov	ax, LWx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLwx, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1218
//@ 		mov	ax, LWy		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLWy, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1219
//@ 		mov	ax, aLwx	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+var_9]
//@ 		add	ax, [bp+var_5]	; Add
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, rrx		; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		add	ax, dx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jl	short loc_2333C	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1220
//@ 		mov	Ry, 400h	; int16_t
//@ 		jmp	short loc_2336B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1221
//@ 
//@ loc_2333C:				; CODE XREF: TryToGo$2+5Fj
//@ 		cmp	LWy, 0		; int16_t
//@ 		jnz	short loc_2334F	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_7]
//@ 		sub	ax, rry		; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ 		jmp	short loc_2336B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1223
//@ 
//@ loc_2334F:				; CODE XREF: TryToGo$2+6Ej
//@ 		mov	ax, rrx		; int16_t
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1224
//@ 		mov	bx, LWy		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWx		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CSPUTL.PAS" 1225
//@ 		add	ax, [bp+var_7]	; Add
//@ 		sub	ax, rry		; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1228
//@ 
//@ loc_2336B:				; CODE XREF: TryToGo$2+67j
//@ 					; TryToGo$2+7Aj
//@ 		mov	ax, aLWy	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+var_7]
//@ 		add	ax, [bp+var_3]	; Add
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, rry		; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		add	ax, dx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jl	short loc_23394	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1229
//@ 		mov	Rx, 400h	; int16_t
//@ 		jmp	short loc_233C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1230
//@ 
//@ loc_23394:				; CODE XREF: TryToGo$2+B7j
//@ 		cmp	LWx, 0		; int16_t
//@ 		jnz	short loc_233A7	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_9]
//@ 		sub	ax, rrx		; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ 		jmp	short loc_233C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1232
//@ 
//@ loc_233A7:				; CODE XREF: TryToGo$2+C6j
//@ 		mov	ax, rry		; int16_t
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1233
//@ 		mov	bx, LWx		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWy		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CSPUTL.PAS" 1234
//@ 		add	ax, [bp+var_9]	; Add
//@ 		sub	ax, rrx		; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1237
//@ 
//@ loc_233C3:				; CODE XREF: TryToGo$2+BFj
//@ 					; TryToGo$2+D2j
//@ 		mov	ax, Rx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, Ry		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	R$1, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1238
//@ 		mov	ax, R$1		; int16_t
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ax, ss:[di+arg_0] ; Compare Two	Operands
//@ 		jge	short locret_233EE ; Jump if Greater or	Equal (SF=OF)
//@ 		mov	ss:[di+var_10],	1
//@ ; #line	"CSPUTL.PAS" 1240
//@ 
//@ locret_233EE:				; CODE XREF: TryToGo$2+114j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ TryToGo$2	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1245
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo2B$1	proc near		; CODE XREF: Pr_WallCheck+F6p
//@ 					; Pr_WallCheck+132p ...
//@ 
//@ var_10		= byte ptr -10h
//@ ay		= word ptr -4		; int16_t
//@ $ax		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ Fr		= word ptr  6		; int16_t
//@ y2		= word ptr  8		; int16_t
//@ x2		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1246
//@ 		mov	ax, rrx		; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+$ax], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1247
//@ 		mov	ax, rry		; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ay], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1248
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ss:[di+var_10],	0 ; Compare Two	Operands
//@ 		jnz	short loc_23430	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+ay]		; int16_t
//@ 		push	[bp+$ax]	; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, [bp+Fr]	; int16_t
//@ 		jl	short loc_23430	; Jump if Less (SF!=OF)
//@ 		mov	al, 0
//@ 		jmp	short loc_23432	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23430:				; CODE XREF: TryToGo2B$1+28j
//@ 					; TryToGo2B$1+38j
//@ 		mov	al, 1
//@ 
//@ loc_23432:				; CODE XREF: TryToGo2B$1+3Cj
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_10],	al
//@ ; #line	"CSPUTL.PAS" 1249
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGo2B$1	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1253
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ Pr_WallCheck	proc near		; CODE XREF: AnimateObjects+27Bp
//@ 					; AnimateObjects+789p
//@ 
//@ var_18		= dword	ptr -18h
//@ var_14		= word ptr -14h
//@ var_12		= word ptr -12h
//@ blow		= byte ptr -10h		; bool
//@ b		= byte ptr -0Fh		; bool
//@ rmy		= word ptr -0Eh		; int16_t
//@ rmx		= word ptr -0Ch		; int16_t
//@ i		= word ptr -0Ah		; int16_t
//@ n		= word ptr -8		; int16_t
//@ Pr_WallCheck	= byte ptr -1		; bool
//@ fr		= word ptr  4		; int16_t
//@ _rrz		= word ptr  6		; int16_t
//@ _rry		= word ptr  8		; int16_t
//@ _rrx		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	18h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1254
//@ 		mov	[bp+blow], 0	; bool
//@ 		mov	ax, [bp+_rrx]	; int16_t
//@ 		mov	rrx, ax		; int16_t
//@ 		mov	ax, [bp+_rry]	; int16_t
//@ 		mov	rry, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 1255
//@ 		mov	al, byte ptr rrx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+rmx], ax	; int16_t
//@ 		mov	al, byte ptr rry+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+rmy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1256
//@ 		mov	ax, [bp+rmx]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, [bp+rmx]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jle	short loc_23476	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_235EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23476:				; CODE XREF: Pr_WallCheck+34j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2347E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2347B:				; CODE XREF: Pr_WallCheck+1AAj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_2347E:				; CODE XREF: Pr_WallCheck+3Cj
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jge	short loc_23487	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_235DF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23487:				; CODE XREF: Pr_WallCheck+45j
//@ 		cmp	[bp+n],	40h ; '@' ; int16_t
//@ 		jl	short loc_23490	; Jump if Less (SF!=OF)
//@ 		jmp	loc_235DF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1257
//@ 
//@ loc_23490:				; CODE XREF: Pr_WallCheck+4Ej
//@ 		mov	ax, [bp+rmy]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_14], ax
//@ 		mov	ax, [bp+rmy]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jle	short loc_234A5	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_235DF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_234A5:				; CODE XREF: Pr_WallCheck+63j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_234AD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_234AA:				; CODE XREF: Pr_WallCheck+19Fj
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_234AD:				; CODE XREF: Pr_WallCheck+6Bj
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jge	short loc_234B6	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_235D4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_234B6:				; CODE XREF: Pr_WallCheck+74j
//@ 		cmp	[bp+i],	40h ; '@' ; int16_t
//@ 		jl	short loc_234BF	; Jump if Less (SF!=OF)
//@ 		jmp	loc_235D4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1258
//@ 
//@ loc_234BF:				; CODE XREF: Pr_WallCheck+7Dj
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_18], di
//@ 		mov	word ptr [bp+var_18+2],	es
//@ ; #line	"CSPUTL.PAS" 1260
//@ 		mov	al, es:[di]
//@ ; #line	"CSPUTL.PAS" 1261
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_23539	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_23539	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 1262
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_23536	; Jump if Zero (ZF=1)
//@ 		mov	dx, [bp+i]	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 50h ;	'P' ; Compare Two Operands
//@ 		jnb	short loc_23536	; Jump if Not Below (CF=0)
//@ ; #line	"CSPUTL.PAS" 1264
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	bp
//@ 		call	TryToGo$2	; function nested near PASCAL returns void
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	[bp+fr]		; int16_t
//@ 		push	bp
//@ 		call	TryToGo2B$1	; function nested near PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1265
//@ 
//@ loc_23536:				; CODE XREF: Pr_WallCheck+B5j
//@ 					; Pr_WallCheck+CCj
//@ 		jmp	loc_235C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1266
//@ 
//@ loc_23539:				; CODE XREF: Pr_WallCheck+A0j
//@ 					; Pr_WallCheck+A4j
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_23574	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_23574	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 1267
//@ 		mov	al, [bp+blow]	; bool
//@ 		mov	[bp+b],	al	; bool
//@ ; #line	"CSPUTL.PAS" 1268
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	bp
//@ 		call	TryToGo$2	; function nested near PASCAL returns void
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	[bp+fr]		; int16_t
//@ 		push	bp
//@ 		call	TryToGo2B$1	; function nested near PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1269
//@ 		jmp	short loc_235C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1270
//@ 
//@ loc_23574:				; CODE XREF: Pr_WallCheck+FEj
//@ 					; Pr_WallCheck+102j
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_235C8	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_235C8	; Jump if Above	(CF=0 &	ZF=0)
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74C0h]
//@ 		cmp	ax, [bp+_rrz]	; int16_t
//@ 		jge	short loc_235C8	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74C2h]
//@ 		cmp	ax, [bp+_rrz]	; int16_t
//@ 		jle	short loc_235C8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1271
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		push	word ptr [di+74AEh]
//@ 		push	bp
//@ 		call	TryToGo2B$1	; function nested near PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1273
//@ 
//@ loc_235C8:				; CODE XREF: Pr_WallCheck:loc_23536j
//@ 					; Pr_WallCheck+135j ...
//@ 		cmp	[bp+blow], 0	; bool
//@ 		jz	short loc_235D4	; Jump if Zero (ZF=1)
//@ 		mov	[bp+Pr_WallCheck], 1 ; bool
//@ 		jmp	short loc_235EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1274
//@ 
//@ loc_235D4:				; CODE XREF: Pr_WallCheck+76j
//@ 					; Pr_WallCheck+7Fj ...
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jz	short loc_235DF	; Jump if Zero (ZF=1)
//@ 		jmp	loc_234AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_235DF:				; CODE XREF: Pr_WallCheck+47j
//@ 					; Pr_WallCheck+50j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jz	short loc_235EA	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2347B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1275
//@ 
//@ loc_235EA:				; CODE XREF: Pr_WallCheck+36j
//@ 					; Pr_WallCheck+1A8j
//@ 		mov	[bp+Pr_WallCheck], 0 ; bool
//@ ; #line	"CSPUTL.PAS" 1276
//@ 
//@ loc_235EE:				; CODE XREF: Pr_WallCheck+195j
//@ 		mov	al, [bp+Pr_WallCheck] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ Pr_WallCheck	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1281
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateRespawnObjects proc far		; CODE XREF: DoGame+18ECP
//@ 
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1282
//@ 		mov	[bp+n],	1	; int16_t
//@ ; #line	"CSPUTL.PAS" 1283
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_23608	; Jump if Zero (ZF=1)
//@ 		jmp	locret_23706	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1284
//@ 
//@ loc_23608:				; CODE XREF: AnimateRespawnObjects+Ej
//@ 					; AnimateRespawnObjects:loc_23703j
//@ 		mov	ax, ReCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_23625	; Jump if Less (SF!=OF)
//@ 		jle	short loc_2361E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_23706	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2361E:				; CODE XREF: AnimateRespawnObjects+24j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_23625	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_23706	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23625:				; CODE XREF: AnimateRespawnObjects+22j
//@ 					; AnimateRespawnObjects+2Bj
//@ 		imul	ax, [bp+n], 0Ah	; int16_t
//@ 		les	di, ReObjects	; TReObject*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF6h	; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSPUTL.PAS" 1285
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		cmp	dx, es:[di+8]	; Compare Two Operands
//@ 		jg	short loc_23654	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_2364B	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_23700	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2364B:				; CODE XREF: AnimateRespawnObjects+51j
//@ 		cmp	ax, es:[di+6]	; Compare Two Operands
//@ 		ja	short loc_23654	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_23700	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1287
//@ 
//@ loc_23654:				; CODE XREF: AnimateRespawnObjects+4Fj
//@ 					; AnimateRespawnObjects+5Aj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	cl, es:[di+4]
//@ 		imul	ax, es:[di+2], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ ; #line	"CSPUTL.PAS" 1288
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+2], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	5
//@ 		push	16h
//@ 		push	30h ; '0'
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1289
//@ 		push	4Bh ; 'K'
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+4]
//@ 		push	ax
//@ 		push	0
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1290
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 0Ah		; Signed Multiply
//@ 		les	di, ReObjects	; TReObject*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF6h	; Add
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, [bp+n], 0Ah	; int16_t
//@ 		les	di, ReObjects	; TReObject*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF6h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, ReCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPUTL.PAS" 1291
//@ 		dec	ReCount		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1292
//@ 		jmp	short loc_23703	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23700:				; CODE XREF: AnimateRespawnObjects+53j
//@ 					; AnimateRespawnObjects+5Cj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_23703:				; CODE XREF: AnimateRespawnObjects+109j
//@ 		jmp	loc_23608	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1293
//@ 
//@ locret_23706:				; CODE XREF: AnimateRespawnObjects+10j
//@ 					; AnimateRespawnObjects+26j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AnimateRespawnObjects endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1299
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateObjects	proc far		; CODE XREF: Build3dScene:loc_A020P
//@ 					; DoGame:loc_D951P
//@ 
//@ var_18		= word ptr -18h
//@ var_16		= dword	ptr -16h
//@ var_12		= dword	ptr -12h
//@ meet		= byte ptr -0Dh		; bool
//@ CeilZ		= word ptr -0Ch		; int16_t
//@ FloorZ		= word ptr -0Ah		; int16_t
//@ zz		= word ptr -8		; int16_t
//@ sx		= word ptr -4		; int16_t
//@ o		= word ptr -2		; int16_t
//@ 
//@ 		enter	18h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1300
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+o],	ax	; int16_t
//@ 		jmp	short loc_23716	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23713:				; CODE XREF: AnimateObjects+4Dj
//@ 		inc	[bp+o]		; int16_t
//@ 
//@ loc_23716:				; CODE XREF: AnimateObjects+9j
//@ 		imul	di, [bp+o], 24h	; int16_t
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	ax, es:[di+1Ch]
//@ 		or	ax, es:[di+1Eh]	; Logical Inclusive OR
//@ 		jz	short loc_23751	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1301
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jbe	short loc_23751	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	byte ptr es:[di+16h], 0	; Compare Two Operands
//@ 		jz	short loc_23751	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1303
//@ 		mov	ax, t1		; uint16_t
//@ 		add	es:[di+18h], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1304
//@ 		mov	ax, es:[di+18h]
//@ 		cmp	ax, es:[di+1Ah]	; Compare Two Operands
//@ 		jb	short loc_23751	; Jump if Below	(CF=1)
//@ 		mov	ax, es:[di+1Ah]
//@ 		sub	es:[di+18h], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1305
//@ 
//@ loc_23751:				; CODE XREF: AnimateObjects+20j
//@ 					; AnimateObjects+27j ...
//@ 		cmp	[bp+o],	5Fh ; '_' ; int16_t
//@ 		jnz	short loc_23713	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1307
//@ 		mov	[bp+o],	1	; int16_t
//@ ; #line	"CSPUTL.PAS" 1308
//@ 
//@ loc_2375C:				; CODE XREF: AnimateObjects+8A1j
//@ 		mov	ax, SCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_23779	; Jump if Less (SF!=OF)
//@ 		jle	short loc_23772	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_23FAC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23772:				; CODE XREF: AnimateObjects+65j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_23779	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_23FAC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23779:				; CODE XREF: AnimateObjects+63j
//@ 					; AnimateObjects+6Cj
//@ 		imul	di, [bp+o], 16h	; int16_t
//@ 		add	di, 0B940h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_12], di
//@ 		mov	word ptr [bp+var_12+2],	es
//@ 		imul	di, es:[di+4], 12h ; Signed Multiply
//@ 		add	di, 0D044h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSPUTL.PAS" 1310
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	es:[di], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1311
//@ 		cmp	word ptr es:[di+4], 46h	; 'F' ; Compare Two Operands
//@ 		mov	al, 0
//@ 		jl	short loc_237AF	; Jump if Less (SF!=OF)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_237AF:				; CODE XREF: AnimateObjects+A4j
//@ 		mov	[bp+meet], al	; bool
//@ ; #line	"CSPUTL.PAS" 1312
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	[bp+zz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1314
//@ 		cmp	word ptr es:[di+12h], 0C180h ; Compare Two Operands
//@ 		jnz	short loc_237C4	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_23CCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1316
//@ 
//@ loc_237C4:				; CODE XREF: AnimateObjects+B7j
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		sub	es:[di+12h], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1317
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ch], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1318
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1319
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ah], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1321
//@ 		cmp	word ptr es:[di+8], 200h ; Compare Two Operands
//@ 		jge	short loc_2383E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+8], 200h
//@ 
//@ loc_2383E:				; CODE XREF: AnimateObjects+12Ej
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 3E00h ; Compare Two	Operands
//@ 		jle	short loc_2384F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+8], 3E00h
//@ ; #line	"CSPUTL.PAS" 1322
//@ 
//@ loc_2384F:				; CODE XREF: AnimateObjects+13Fj
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Ah], 200h ; Compare Two Operands
//@ 		jge	short loc_23860	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+0Ah], 200h
//@ 
//@ loc_23860:				; CODE XREF: AnimateObjects+150j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Ah], 3E00h ; Compare Two Operands
//@ 		jle	short loc_23871	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+0Ah], 3E00h
//@ ; #line	"CSPUTL.PAS" 1325
//@ 
//@ loc_23871:				; CODE XREF: AnimateObjects+161j
//@ 		cmp	[bp+meet], 0	; bool
//@ 		jz	short loc_2387E	; Jump if Zero (ZF=1)
//@ 		mov	[bp+sx], 0Ah	; int16_t
//@ 		jmp	short loc_23883	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2387E:				; CODE XREF: AnimateObjects+16Dj
//@ 		mov	[bp+sx], 6	; int16_t
//@ ; #line	"CSPUTL.PAS" 1326
//@ 
//@ loc_23883:				; CODE XREF: AnimateObjects+174j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+8]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+FloorZ], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1327
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, FloorZHi	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+CeilZ], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1328
//@ 		mov	ax, [bp+FloorZ]	; int16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		mov	[bp+FloorZ], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1329
//@ 		mov	ax, [bp+CeilZ]	; int16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		mov	[bp+CeilZ], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1331
//@ 		mov	al, byte ptr takt ; uint16_t
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jb	short loc_238E9	; Jump if Below	(CF=1)
//@ 		jmp	loc_2396E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1332
//@ 
//@ loc_238E9:				; CODE XREF: AnimateObjects+1DCj
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	140h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	5
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	5
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		push	ax
//@ 		push	[bp+sx]		; int16_t
//@ 		call	AddBlow		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1339
//@ 
//@ loc_2396E:				; CODE XREF: AnimateObjects+1DEj
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		call	Pr_WallCheck	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_2398D	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_23A1E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1341
//@ 
//@ loc_2398D:				; CODE XREF: AnimateObjects+280j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Eh], ax
//@ 		mov	ax, es:[di+10h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSPUTL.PAS" 1342
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1343
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ah], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1344
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_23A1E	; Jump if Not Zero (ZF=0)
//@ 		add	word ptr es:[di+14h], 8000h ; Add
//@ ; #line	"CSPUTL.PAS" 1347
//@ 
//@ loc_23A1E:				; CODE XREF: AnimateObjects+282j
//@ 					; AnimateObjects+30Ej
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Ch], 700h ; Compare Two Operands
//@ 		jle	short loc_23A2C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_23AAD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23A2C:				; CODE XREF: AnimateObjects+31Fj
//@ 		cmp	[bp+zz], 700h	; int16_t
//@ 		jle	short loc_23AAD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1348
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	0
//@ 		call	iswater		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_23AAD	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1350
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	9
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1351
//@ 		mov	j, 1		; uint16_t
//@ 		jmp	short loc_23A66	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23A62:				; CODE XREF: AnimateObjects+3A3j
//@ 		inc	j		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1352
//@ 
//@ loc_23A66:				; CODE XREF: AnimateObjects+358j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	180h
//@ 		push	7
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFDh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	7
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFDh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	40h ; '@'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 40h	; '@'   ; Add
//@ 		push	ax
//@ 		push	0Fh
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	j, 8		; uint16_t
//@ 		jnz	short loc_23A62	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1359
//@ 
//@ loc_23AAD:				; CODE XREF: AnimateObjects+321j
//@ 					; AnimateObjects+329j ...
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, [bp+FloorZ]	; int16_t
//@ 		jge	short loc_23AE5	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 1360
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	0
//@ 		call	iswater		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_23AE5	; Jump if Not Zero (ZF=0)
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1362
//@ 
//@ loc_23AE5:				; CODE XREF: AnimateObjects+3AFj
//@ 					; AnimateObjects+3C2j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, [bp+CeilZ]	; int16_t
//@ 		jle	short loc_23B2E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_23B2E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 6		; Shift	Logical	Left
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr [di+5EC6h], 3Eh ; '>' ; Compare Two Operands
//@ 		jz	short loc_23B2E	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1363
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+12h], ax
//@ 		mov	ax, [bp+CeilZ]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 1365
//@ 
//@ loc_23B2E:				; CODE XREF: AnimateObjects+3E7j
//@ 					; AnimateObjects+3EEj ...
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, [bp+FloorZ]	; int16_t
//@ 		jl	short loc_23B3D	; Jump if Less (SF!=OF)
//@ 		jmp	loc_23CA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1366
//@ 
//@ loc_23B3D:				; CODE XREF: AnimateObjects+430j
//@ 		mov	ax, es:[di+12h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, 0C8h ; 'È'  ; Compare Two Operands
//@ 		jle	short loc_23B58	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jz	short loc_23B72	; Jump if Zero (ZF=1)
//@ 
//@ loc_23B58:				; CODE XREF: AnimateObjects+43Ej
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, 190h	; Compare Two Operands
//@ 		jg	short loc_23B69	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_23C61	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23B69:				; CODE XREF: AnimateObjects+45Cj
//@ 		cmp	[bp+meet], 0	; bool
//@ 		jnz	short loc_23B72	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_23C61	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1370
//@ 
//@ loc_23B72:				; CODE XREF: AnimateObjects+44Ej
//@ 					; AnimateObjects+465j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 6		; Shift	Logical	Left
//@ 		add	di, dx		; Add
//@ 		mov	al, [di+4EC6h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-23F0h], 0 ; Compare Two Operands
//@ 		jz	short loc_23C08	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1371
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_23BA4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23BA0:				; CODE XREF: AnimateObjects+4FEj
//@ 		inc	j		; uint16_t
//@ 
//@ loc_23BA4:				; CODE XREF: AnimateObjects+496j
//@ 		push	64h ; 'd'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 32h	; '2'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	64h ; 'd'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 32h	; '2'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		mov	ax, [bp+FloorZ]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	8
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	j, 3		; uint16_t
//@ 		jnz	short loc_23BA0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1373
//@ 
//@ loc_23C08:				; CODE XREF: AnimateObjects+48Fj
//@ 		mov	ax, [bp+FloorZ]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 1374
//@ 		mov	ax, es:[di+12h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSPUTL.PAS" 1375
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFFh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Eh], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1376
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFFh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+10h], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1377
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		sub	es:[di], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1378
//@ 		jmp	short loc_23CA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1380
//@ 
//@ loc_23C61:				; CODE XREF: AnimateObjects+45Ej
//@ 					; AnimateObjects+467j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+12h], 0C180h
//@ 		mov	ax, [bp+FloorZ]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 1381
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 3
//@ 		div	cx		; Unsigned Divide
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_23C95	; Jump if Less (SF!=OF)
//@ 		jg	short loc_23CA2	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_23CA2	; Jump if Not Below (CF=0)
//@ 
//@ loc_23C95:				; CODE XREF: AnimateObjects+585j
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		dec	ax		; Decrement by 1
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"CSPUTL.PAS" 1384
//@ 
//@ loc_23CA2:				; CODE XREF: AnimateObjects+432j
//@ 					; AnimateObjects+557j ...
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_23CBF	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_23CCB	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_23CCB	; Jump if Below	(CF=1)
//@ 
//@ loc_23CBF:				; CODE XREF: AnimateObjects+5AFj
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1386
//@ 
//@ loc_23CCB:				; CODE XREF: AnimateObjects+5B1j
//@ 					; AnimateObjects+5B5j
//@ 		jmp	loc_23FA6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1388
//@ 
//@ loc_23CCE:				; CODE XREF: AnimateObjects+B9j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+8]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+FloorZ], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1389
//@ 		mov	ax, [bp+FloorZ]	; int16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		mov	[bp+FloorZ], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1391
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jz	short loc_23D2B	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_23D2B	; Jump if Less (SF!=OF)
//@ 		jle	short loc_23D24	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_23DDE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23D24:				; CODE XREF: AnimateObjects+617j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_23D2B	; Jump if Below	(CF=1)
//@ 		jmp	loc_23DDE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1392
//@ 
//@ loc_23D2B:				; CODE XREF: AnimateObjects+5FDj
//@ 					; AnimateObjects+615j ...
//@ 		cmp	[bp+meet], 0	; bool
//@ 		jz	short loc_23D34	; Jump if Zero (ZF=1)
//@ 		jmp	loc_23DDE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1393
//@ 
//@ loc_23D34:				; CODE XREF: AnimateObjects+627j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 6		; Shift	Logical	Left
//@ 		add	di, dx		; Add
//@ 		mov	al, [di+4EC6h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-23F0h], 0 ; Compare Two Operands
//@ 		jnz	short loc_23D5E	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_23DDE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1394
//@ 
//@ loc_23D5E:				; CODE XREF: AnimateObjects+651j
//@ 		mov	ax, t1		; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	[bp+var_18], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_18]	; Compare Two Operands
//@ 		ja	short loc_23DDE	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_23D77	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23D73:				; CODE XREF: AnimateObjects+6D4j
//@ 		inc	j		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1395
//@ 
//@ loc_23D77:				; CODE XREF: AnimateObjects+669j
//@ 		push	8Ch ; 'Œ'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 46h	; 'F'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	8Ch ; 'Œ'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 46h	; 'F'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		mov	ax, [bp+FloorZ]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	8
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		mov	ax, j		; uint16_t
//@ 		cmp	ax, [bp+var_18]	; Compare Two Operands
//@ 		jnz	short loc_23D73	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1397
//@ 
//@ loc_23DDE:				; CODE XREF: AnimateObjects+619j
//@ 					; AnimateObjects+620j ...
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+2], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1398
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, [bp+FloorZ]	; int16_t
//@ 		jle	short loc_23DFB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		sub	es:[di+0Ch], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1399
//@ 
//@ loc_23DFB:				; CODE XREF: AnimateObjects+6E7j
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, [bp+FloorZ]	; int16_t
//@ 		jge	short loc_23E0E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+FloorZ]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 1401
//@ 
//@ loc_23E0E:				; CODE XREF: AnimateObjects+6FDj
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jz	short loc_23E1B	; Jump if Zero (ZF=1)
//@ 		jmp	loc_23EF7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1402
//@ 
//@ loc_23E1B:				; CODE XREF: AnimateObjects+70Ej
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jz	short loc_23E34	; Jump if Zero (ZF=1)
//@ 		cmp	[bp+meet], 0	; bool
//@ 		jnz	short loc_23E34	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_23EF7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1404
//@ 
//@ loc_23E34:				; CODE XREF: AnimateObjects+721j
//@ 					; AnimateObjects+727j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1405
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ah], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1406
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		call	Pr_WallCheck	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_23EF7	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1408
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	es:[di+0Eh], ax
//@ 		mov	ax, es:[di+10h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSPUTL.PAS" 1409
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1410
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 5
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ah], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1414
//@ 
//@ loc_23EF7:				; CODE XREF: AnimateObjects+710j
//@ 					; AnimateObjects+729j ...
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_23F31	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1415
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_23F1E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_23F2F	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_23F2F	; Jump if Below	(CF=1)
//@ 
//@ loc_23F1E:				; CODE XREF: AnimateObjects+80Ej
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di], ax	; Integer Subtraction
//@ 		mov	byte ptr es:[di+6], 1
//@ 
//@ loc_23F2F:				; CODE XREF: AnimateObjects+810j
//@ 					; AnimateObjects+814j
//@ 		jmp	short loc_23F5C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1417
//@ 
//@ loc_23F31:				; CODE XREF: AnimateObjects+7F7j
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_23F4F	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_23F5C	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_23F5C	; Jump if Below	(CF=1)
//@ 
//@ loc_23F4F:				; CODE XREF: AnimateObjects+83Fj
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"CSPUTL.PAS" 1419
//@ 
//@ loc_23F5C:				; CODE XREF: AnimateObjects:loc_23F2Fj
//@ 					; AnimateObjects+841j ...
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+2], 36B0h ; Compare Two	Operands
//@ 		jle	short loc_23FA6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1421
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		add	di, 0B940h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, [bp+o], 16h	; int16_t
//@ 		add	di, 0B940h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, SCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 16h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPUTL.PAS" 1422
//@ 		dec	SCount		; uint16_t
//@ 		dec	[bp+o]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1425
//@ 
//@ loc_23FA6:				; CODE XREF: AnimateObjects:loc_23CCBj
//@ 					; AnimateObjects+85Dj
//@ 		inc	[bp+o]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1426
//@ 		jmp	loc_2375C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1428
//@ 
//@ loc_23FAC:				; CODE XREF: AnimateObjects+67j
//@ 					; AnimateObjects+6Ej
//@ 		mov	[bp+o],	1	; int16_t
//@ ; #line	"CSPUTL.PAS" 1429
//@ 
//@ loc_23FB1:				; CODE XREF: AnimateObjects+91Fj
//@ 					; AnimateObjects+988j
//@ 		mov	ax, AmCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_23FCE	; Jump if Less (SF!=OF)
//@ 		jle	short loc_23FC7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_24093	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_23FC7:				; CODE XREF: AnimateObjects+8BAj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_23FCE	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_24093	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1430
//@ 
//@ loc_23FCE:				; CODE XREF: AnimateObjects+8B8j
//@ 					; AnimateObjects+8C1j
//@ 		imul	ax, [bp+o], 1Fh	; int16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		mov	word ptr [bp+var_12], di
//@ 		mov	word ptr [bp+var_12+2],	es
//@ ; #line	"CSPUTL.PAS" 1432
//@ 		mov	ax, t1		; uint16_t
//@ 		add	es:[di+0Ah], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1433
//@ 		cmp	word ptr es:[di+0Ah], 41A0h ; Compare Two Operands
//@ 		jbe	short loc_24029	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 1435
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Fh		; Signed Multiply
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, [bp+o], 1Fh	; int16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 3Fh	; '?'
//@ 		sub	ax, [bp+o]	; int16_t
//@ 		imul	ax, 1Fh		; Signed Multiply
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPUTL.PAS" 1436
//@ 		dec	AmCount		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1437
//@ 		jmp	short loc_23FB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1439
//@ 
//@ loc_24029:				; CODE XREF: AnimateObjects+8E7j
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ch], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1440
//@ 		mov	ax, es:[di+4]
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jle	short loc_2408D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1442
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+4], ax	; Add
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	es:[di+6], ax	; Integer Subtraction
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	es:[di+0Ch], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1443
//@ 		mov	ax, es:[di+4]
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jge	short loc_2408D	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 1444
//@ 		mov	ax, es:[di+8]
//@ 		mov	es:[di+4], ax
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	6
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1446
//@ 
//@ loc_2408D:				; CODE XREF: AnimateObjects+936j
//@ 					; AnimateObjects+96Bj
//@ 		inc	[bp+o]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1447
//@ 		jmp	loc_23FB1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1449
//@ 
//@ loc_24093:				; CODE XREF: AnimateObjects+8BCj
//@ 					; AnimateObjects+8C3j
//@ 		cmp	OAnimate, 0	; bool
//@ 		jnz	short loc_2409C	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_240F3 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1451
//@ 
//@ loc_2409C:				; CODE XREF: AnimateObjects+990j
//@ 		mov	ax, ObjectsLoaded ; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	word ptr [bp+var_12+2],	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, word ptr [bp+var_12+2] ; Compare Two Operands
//@ 		jg	short locret_240F3 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		mov	[bp+o],	ax	; int16_t
//@ 		jmp	short loc_240B2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_240AF:				; CODE XREF: AnimateObjects+9E9j
//@ 		inc	[bp+o]		; int16_t
//@ 
//@ loc_240B2:				; CODE XREF: AnimateObjects+9A5j
//@ 		imul	di, [bp+o], 0A5h ; int16_t
//@ 		add	di, 721Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_16+2],	di
//@ 		mov	word ptr [bp+var_12], es
//@ ; #line	"CSPUTL.PAS" 1452
//@ 		cmp	byte ptr es:[di+3], 0 ;	Compare	Two Operands
//@ 		jbe	short loc_240EB	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 1453
//@ 		mov	al, es:[di+3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+4]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_240E3	; Jump if Greater or Equal (SF=OF)
//@ 		inc	byte ptr es:[di+4] ; Increment by 1
//@ 		jmp	short loc_240EB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1454
//@ 
//@ loc_240E3:				; CODE XREF: AnimateObjects+9D3j
//@ 		les	di, [bp+var_16+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	byte ptr es:[di+4], 0
//@ 
//@ loc_240EB:				; CODE XREF: AnimateObjects+9C0j
//@ 					; AnimateObjects+9D9j
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_12+2] ; Compare Two Operands
//@ 		jnz	short loc_240AF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1456
//@ 
//@ locret_240F3:				; CODE XREF: AnimateObjects+992j
//@ 					; AnimateObjects+9A0j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AnimateObjects	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1463
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ FindTarget	proc near		; CODE XREF: AddRocket+F3p
//@ 
//@ var_32		= dword	ptr -32h
//@ vy		= word ptr -2Eh		; int32_t
//@ var_2C		= word ptr -2Ch
//@ vx		= word ptr -2Ah		; int32_t
//@ var_28		= word ptr -28h
//@ yy		= word ptr -26h		; int32_t
//@ var_24		= word ptr -24h
//@ xx		= word ptr -22h		; int32_t
//@ var_20		= word ptr -20h
//@ isa		= word ptr -1Eh		; int32_t
//@ var_1C		= word ptr -1Ch
//@ ica		= word ptr -1Ah		; int32_t
//@ var_18		= word ptr -18h
//@ n		= word ptr -16h		; int32_t
//@ var_14		= word ptr -14h
//@ R		= word ptr -12h		; int32_t
//@ var_10		= word ptr -10h
//@ tgr		= word ptr -0Eh		; int32_t
//@ var_C		= word ptr -0Ch
//@ tgy		= word ptr -0Ah		; int32_t
//@ var_8		= word ptr -8
//@ tgx		= word ptr -6		; int32_t
//@ var_4		= word ptr -4
//@ FindTarget	= word ptr -2		; int16_t
//@ rfi		= word ptr  4		; uint16_t
//@ rry		= word ptr  6		; int16_t
//@ rrx		= word ptr  8		; int16_t
//@ 
//@ 		enter	32h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1464
//@ 		mov	ax, [bp+rfi]	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	[bp+vx], ax	; int32_t
//@ 		mov	[bp+var_28], dx
//@ ; #line	"CSPUTL.PAS" 1465
//@ 		mov	ax, [bp+rfi]	; uint16_t
//@ 		add	ax, 4000h	; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	[bp+vy], ax	; int32_t
//@ 		mov	[bp+var_2C], dx
//@ ; #line	"CSPUTL.PAS" 1467
//@ 		mov	ax, [bp+rfi]	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	[bp+isa], ax	; int32_t
//@ 		mov	[bp+var_1C], dx
//@ ; #line	"CSPUTL.PAS" 1468
//@ 		mov	ax, [bp+rfi]	; uint16_t
//@ 		add	ax, 4000h	; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	[bp+ica], ax	; int32_t
//@ 		mov	[bp+var_18], dx
//@ ; #line	"CSPUTL.PAS" 1470
//@ 		mov	[bp+R],	4800h	; int32_t
//@ 		mov	[bp+var_10], 1E8h
//@ ; #line	"CSPUTL.PAS" 1471
//@ 		mov	[bp+tgr], 0FFFFh ; int32_t
//@ 		mov	[bp+var_C], 0FFFFh
//@ ; #line	"CSPUTL.PAS" 1487
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int32_t
//@ 		mov	[bp+var_14], ax
//@ 		jmp	short loc_24187	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2417F:				; CODE XREF: FindTarget+1A1j
//@ 					; FindTarget+1AAj
//@ 		add	[bp+n],	1	; int32_t
//@ 		adc	[bp+var_14], 0	; Add with Carry
//@ ; #line	"CSPUTL.PAS" 1488
//@ 
//@ loc_24187:				; CODE XREF: FindTarget+88j
//@ 		imul	di, [bp+n], 58h	; int32_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_32], di
//@ 		mov	word ptr [bp+var_32+2],	es
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_241A1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_24290	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1490
//@ 
//@ loc_241A1:				; CODE XREF: FindTarget+A7j
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+rry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, [bp+isa]	; int32_t
//@ 		mov	bx, [bp+var_1C]
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+rrx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, [bp+ica]	; int32_t
//@ 		mov	bx, [bp+var_18]
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 6
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	[bp+xx], ax	; int32_t
//@ 		mov	[bp+var_20], dx
//@ ; #line	"CSPUTL.PAS" 1491
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+rrx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, [bp+isa]	; int32_t
//@ 		mov	bx, [bp+var_1C]
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+rry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, [bp+ica]	; int32_t
//@ 		mov	bx, [bp+var_18]
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+yy], ax	; int32_t
//@ 		mov	[bp+var_24], dx
//@ ; #line	"CSPUTL.PAS" 1492
//@ 		cmp	[bp+var_24], 0	; Compare Two Operands
//@ 		jg	short loc_2422A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_24290	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+yy], 0	; int32_t
//@ 		jbe	short loc_24290	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2422A:				; CODE XREF: FindTarget+12Bj
//@ 		mov	ax, [bp+xx]	; int32_t
//@ 		mov	dx, [bp+var_20]
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_2423B	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_2423B:				; CODE XREF: FindTarget+13Dj
//@ 		cmp	dx, [bp+var_24]	; Compare Two Operands
//@ 		jl	short loc_24247	; Jump if Less (SF!=OF)
//@ 		jg	short loc_24290	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, [bp+yy]	; int32_t
//@ 		jnb	short loc_24290	; Jump if Not Below (CF=0)
//@ ; #line	"CSPUTL.PAS" 1493
//@ 
//@ loc_24247:				; CODE XREF: FindTarget+149j
//@ 		mov	ax, [bp+R]	; int32_t
//@ 		mov	dx, [bp+var_10]
//@ 		cmp	dx, [bp+var_24]	; Compare Two Operands
//@ 		jg	short loc_24259	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_24290	; Jump if Less (SF!=OF)
//@ 		cmp	ax, [bp+yy]	; int32_t
//@ 		jbe	short loc_24290	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 1495
//@ 
//@ loc_24259:				; CODE XREF: FindTarget+15Bj
//@ 		mov	ax, [bp+yy]	; int32_t
//@ 		mov	dx, [bp+var_24]
//@ 		mov	[bp+R],	ax	; int32_t
//@ 		mov	[bp+var_10], dx
//@ 		mov	ax, [bp+n]	; int32_t
//@ 		mov	dx, [bp+var_14]
//@ 		add	ax, 0C8h ; 'È'  ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	[bp+tgr], ax	; int32_t
//@ 		mov	[bp+var_C], dx
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	[bp+tgx], ax	; int32_t
//@ 		mov	[bp+var_4], dx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	[bp+tgy], ax	; int32_t
//@ 		mov	[bp+var_8], dx
//@ ; #line	"CSPUTL.PAS" 1498
//@ 
//@ loc_24290:				; CODE XREF: FindTarget+A9j
//@ 					; FindTarget+12Dj ...
//@ 		cmp	[bp+var_14], 0	; Compare Two Operands
//@ 		jz	short loc_24299	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2417F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24299:				; CODE XREF: FindTarget+19Fj
//@ 		cmp	[bp+n],	7	; int32_t
//@ 		jz	short loc_242A2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2417F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1500
//@ 
//@ loc_242A2:				; CODE XREF: FindTarget+1A8j
//@ 		cmp	[bp+var_C], 0	; Compare Two Operands
//@ 		jg	short loc_242B0	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_242D1	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+tgr], 0	; int32_t
//@ 		jb	short loc_242D1	; Jump if Below	(CF=1)
//@ ; #line	"CSPUTL.PAS" 1501
//@ 
//@ loc_242B0:				; CODE XREF: FindTarget+1B1j
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	[bp+tgx]	; int32_t
//@ 		push	[bp+tgy]	; int32_t
//@ 		push	1Ah
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_242D1	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1502
//@ 		mov	[bp+tgr], 0FFFFh ; int32_t
//@ 		mov	[bp+var_C], 0FFFFh
//@ ; #line	"CSPUTL.PAS" 1504
//@ 
//@ loc_242D1:				; CODE XREF: FindTarget+1B3j
//@ 					; FindTarget+1B9j ...
//@ 		mov	ax, [bp+tgr]	; int32_t
//@ 		mov	[bp+FindTarget], ax ; int16_t
//@ ; #line	"CSPUTL.PAS" 1505
//@ 		mov	ax, [bp+FindTarget] ; int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ FindTarget	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1509
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddRocket	proc far		; CODE XREF: DoGame+DA2P DoGame+E29P ...
//@ 
//@ var_4		= dword	ptr -4
//@ Targ		= word ptr  6		; int16_t
//@ RRFi		= word ptr  8		; uint16_t
//@ OwId		= word ptr  0Ah		; int16_t
//@ RRType		= byte ptr  0Ch		; int16_t
//@ rvz		= word ptr  0Eh		; int16_t
//@ rvy		= word ptr  10h		; int16_t
//@ rvx		= word ptr  12h		; int16_t
//@ rrz		= word ptr  14h		; int16_t
//@ rry		= word ptr  16h		; int16_t
//@ rrx		= word ptr  18h		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1510
//@ 		cmp	RCount,	3Fh ; '?' ; uint16_t
//@ 		jbe	short loc_242EC	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_243DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1511
//@ 
//@ loc_242EC:				; CODE XREF: AddRocket+9j
//@ 		inc	RCount		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1512
//@ 		imul	di, RCount, 18h	; uint16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPUTL.PAS" 1514
//@ 		mov	ax, [bp+rvx]	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ 		mov	ax, [bp+rvy]	; int16_t
//@ 		mov	es:[di+10h], ax
//@ 		mov	ax, [bp+rvz]	; int16_t
//@ 		mov	es:[di+12h], ax
//@ 		mov	al, [bp+RRType]	; int16_t
//@ 		mov	es:[di+0Ch], al
//@ ; #line	"CSPUTL.PAS" 1515
//@ 		mov	ax, [bp+rvx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 17Ch
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+rrx]	; int16_t
//@ 		mov	es:[di+2], ax
//@ 		mov	ax, [bp+rvy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 17Ch
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+rry]	; int16_t
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 1516
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ 		mov	byte ptr es:[di+0Dh], 0
//@ ; #line	"CSPUTL.PAS" 1517
//@ 		mov	ax, [bp+rrz]	; int16_t
//@ 		mov	es:[di+8], ax
//@ 		mov	ax, [bp+RRFi]	; uint16_t
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSPUTL.PAS" 1518
//@ 		mov	ax, [bp+OwId]	; int16_t
//@ 		mov	es:[di+16h], ax
//@ ; #line	"CSPUTL.PAS" 1519
//@ 		mov	word ptr es:[di+14h], 0FFFFh
//@ ; #line	"CSPUTL.PAS" 1520
//@ 		cmp	Skill, 2	; int16_t
//@ 		jnz	short loc_24382	; Jump if Not Zero (ZF=0)
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	al, [di-3272h]
//@ 		and	al, 8		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_24398	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_24382:				; CODE XREF: AddRocket+8Fj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Ch]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	al, [di-3272h]
//@ 		and	al, 10h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short locret_243DB ; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1523
//@ 
//@ loc_24398:				; CODE XREF: AddRocket+A2j
//@ 		cmp	[bp+Targ], 0	; int16_t
//@ 		jl	short loc_243BE	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+Targ], 7	; int16_t
//@ 		jg	short loc_243BE	; Jump if Greater (ZF=0	& SF=OF)
//@ 		imul	di, [bp+Targ], 58h ; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jle	short loc_243BE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+Targ]	; int16_t
//@ 		add	ax, 0C8h ; 'È'  ; Add
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+14h], ax
//@ 		jmp	short locret_243DB ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1524
//@ 
//@ loc_243BE:				; CODE XREF: AddRocket+BEj
//@ 					; AddRocket+C4j ...
//@ 		cmp	[bp+Targ], 0FFh	; int16_t
//@ 		jnz	short locret_243DB ; Jump if Not Zero (ZF=0)
//@ 		push	[bp+OwId]	; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	[bp+RRFi]	; uint16_t
//@ 		call	FindTarget	; function near	PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSPUTL.PAS" 1526
//@ 
//@ locret_243DB:				; CODE XREF: AddRocket+Bj
//@ 					; AddRocket+B8j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	14h		; Return Far from Procedure
//@ AddRocket	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1533
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ FindVectorFi	proc far		; CODE XREF: DrawHoles+68P
//@ 					; MakePunch+14DP ...
//@ 
//@ Ady		= word ptr -0Ch		; int16_t
//@ Adx		= word ptr -0Ah		; int16_t
//@ DFi		= word ptr -8		; int16_t
//@ Fi		= word ptr -6		; int16_t
//@ j		= word ptr -4		; int16_t
//@ FindVectorFi	= word ptr -2		; int16_t
//@ Dy		= word ptr  6		; int16_t
//@ $Dx		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1534
//@ 		mov	ax, [bp+$Dx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+Adx], ax	; int16_t
//@ 		mov	ax, [bp+Dy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+Ady], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1535
//@ 		mov	[bp+Fi], 80h ; '€' ; int16_t
//@ 		mov	[bp+DFi], 40h ;	'@' ; int16_t
//@ ; #line	"CSPUTL.PAS" 1536
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_2440D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2440A:				; CODE XREF: FindVectorFi+6Bj
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1538
//@ 
//@ loc_2440D:				; CODE XREF: FindVectorFi+29j
//@ 		push	[bp+Adx]	; int16_t
//@ 		push	[bp+Ady]	; int16_t
//@ 		mov	ax, [bp+Fi]	; int16_t
//@ 		add	ax, 100h	; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di-6390h]
//@ 		mov	di, [bp+Fi]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di-6390h]
//@ 		call	MulVectors$1	; function near	PASCAL returns signed int 'Integer'
//@ 		mul	[bp+DFi]	; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+Fi]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+Fi], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1539
//@ 		mov	ax, [bp+DFi]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+DFi], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1540
//@ 		cmp	[bp+j],	6	; int16_t
//@ 		jnz	short loc_2440A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1543
//@ 		cmp	[bp+$Dx], 0	; int16_t
//@ 		jge	short loc_2446A	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	[bp+Dy], 0	; int16_t
//@ 		jge	short loc_2445F	; Jump if Greater or Equal (SF=OF)
//@ 		add	[bp+Fi], 200h	; int16_t
//@ 		jmp	short loc_24468	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2445F:				; CODE XREF: FindVectorFi+77j
//@ 		mov	ax, 200h
//@ 		sub	ax, [bp+Fi]	; int16_t
//@ 		mov	[bp+Fi], ax	; int16_t
//@ 
//@ loc_24468:				; CODE XREF: FindVectorFi+7Ej
//@ 		jmp	short loc_24479	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1544
//@ 
//@ loc_2446A:				; CODE XREF: FindVectorFi+71j
//@ 		cmp	[bp+Dy], 0	; int16_t
//@ 		jge	short loc_24479	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, 400h
//@ 		sub	ax, [bp+Fi]	; int16_t
//@ 		mov	[bp+Fi], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1545
//@ 
//@ loc_24479:				; CODE XREF: FindVectorFi:loc_24468j
//@ 					; FindVectorFi+8Fj
//@ 		mov	ax, [bp+Fi]	; int16_t
//@ 		mov	[bp+FindVectorFi], ax ;	int16_t
//@ ; #line	"CSPUTL.PAS" 1546
//@ 		mov	ax, [bp+FindVectorFi] ;	int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ FindVectorFi	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1552
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SendRocketToMe	proc far		; CODE XREF: AnimateMonsters+F79P
//@ 					; AnimateMonsters+FD1P	...
//@ 
//@ var_16		= dword	ptr -16h
//@ tz		= word ptr -12h		; int16_t
//@ ty		= word ptr -10h		; int16_t
//@ tx		= word ptr -0Eh		; int16_t
//@ vvz		= word ptr -0Ch		; int16_t
//@ vvy		= word ptr -0Ah		; int16_t
//@ vvx		= word ptr -8		; int16_t
//@ rnd		= word ptr -6		; int16_t
//@ L		= word ptr -4		; int16_t
//@ Fi		= word ptr -2		; int16_t
//@ Target		= word ptr  6		; int16_t
//@ OwId		= word ptr  8		; int16_t
//@ RType		= word ptr  0Ah		; int16_t
//@ dy		= word ptr  0Ch		; int16_t
//@ $dx		= word ptr  0Eh		; int16_t
//@ mz		= word ptr  10h		; int16_t
//@ my		= word ptr  12h		; int16_t
//@ mx		= word ptr  14h		; int16_t
//@ 
//@ 		enter	1Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1553
//@ 		mov	ax, Skill	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, 20h	; ' '
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+rnd], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1554
//@ 		cmp	[bp+Target], 8	; int16_t
//@ 		jge	short loc_244B0	; Jump if Greater or Equal (SF=OF)
//@ 		push	[bp+Target]	; int16_t
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	0
//@ 		call	WeakUpMonstersTo ; function far	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1555
//@ 
//@ loc_244B0:				; CODE XREF: SendRocketToMe+18j
//@ 		cmp	[bp+Target], 8	; int16_t
//@ 		jge	short loc_244FE	; Jump if Greater or Equal (SF=OF)
//@ 		imul	di, [bp+Target], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPUTL.PAS" 1557
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	[bp+tx], ax	; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	[bp+ty], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1558
//@ 		mov	ax, es:[di+0Eh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		add	ax, 22h	; '"'   ; Add
//@ 		mov	[bp+tz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1559
//@ 		mov	ax, es:[di+12h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		push	ax
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		add	[bp+rnd], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1560
//@ 		jmp	short loc_24541	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1562
//@ 
//@ loc_244FE:				; CODE XREF: SendRocketToMe+2Ej
//@ 		mov	ax, [bp+Target]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSPUTL.PAS" 1564
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+tx], ax	; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+ty], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1565
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ ; #line	"CSPUTL.PAS" 1566
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	ax, es:[di+20h]	; Add
//@ 		mov	[bp+tz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1569
//@ 
//@ loc_24541:				; CODE XREF: SendRocketToMe+76j
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		sub	ax, [bp+mx]	; int16_t
//@ 		mov	[bp+vvx], ax	; int16_t
//@ 		mov	ax, [bp+ty]	; int16_t
//@ 		sub	ax, [bp+my]	; int16_t
//@ 		mov	[bp+vvy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1570
//@ 		push	[bp+vvx]	; int16_t
//@ 		push	[bp+vvy]	; int16_t
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+L],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1571
//@ 		push	[bp+vvx]	; int16_t
//@ 		push	[bp+vvy]	; int16_t
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+Fi], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1573
//@ 		imul	di, [bp+RType],	16h ; int16_t
//@ 		mov	ax, [di-326Eh]
//@ 		or	ax, [di-326Ch]	; Logical Inclusive OR
//@ 		jz	short loc_24580	; Jump if Zero (ZF=1)
//@ 		jmp	loc_24633	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1575
//@ 
//@ loc_24580:				; CODE XREF: SendRocketToMe+F5j
//@ 		push	[bp+rnd]	; int16_t
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rnd]	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+Fi]	; int16_t
//@ 		add	ax, 400h	; Add
//@ 		add	ax, dx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+Fi], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1576
//@ 		mov	ax, [bp+Fi]	; int16_t
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	[bp+Fi], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1577
//@ 		mov	ax, [bp+Fi]	; int16_t
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	[bp+vvx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1578
//@ 		mov	di, [bp+Fi]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	[bp+vvy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1579
//@ 		mov	ax, [bp+L]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+tz]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mz]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0FFC0h
//@ 		mov	bx, 0FFFFh
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+vvz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1580
//@ 		mov	ax, [bp+vvx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 400h
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+mx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+vvy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 400h
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+my]	; int16_t
//@ 		push	ax
//@ 		push	[bp+mz]		; int16_t
//@ 		push	[bp+vvx]	; int16_t
//@ 		push	[bp+vvy]	; int16_t
//@ 		push	[bp+vvz]	; int16_t
//@ 		push	[bp+RType]	; int16_t
//@ 		push	[bp+OwId]	; int16_t
//@ 		push	1
//@ 		call	SendFastRocket	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1582
//@ 		jmp	locret_24716	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1586
//@ 
//@ loc_24633:				; CODE XREF: SendRocketToMe+F7j
//@ 		mov	ax, [bp+L]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vvx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4000h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+vvx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1587
//@ 		mov	ax, [bp+L]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vvy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4000h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+vvy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1588
//@ 		mov	ax, [bp+vvx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		add	[bp+mx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1589
//@ 		mov	ax, [bp+vvy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		add	[bp+my], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1591
//@ 		imul	di, [bp+RType],	16h ; int16_t
//@ 		mov	al, [di-3272h]
//@ 		and	al, 8		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_2469C	; Jump if Zero (ZF=1)
//@ 		cmp	Skill, 2	; int16_t
//@ 		jz	short loc_246AA	; Jump if Zero (ZF=1)
//@ 
//@ loc_2469C:				; CODE XREF: SendRocketToMe+20Dj
//@ 		imul	di, [bp+RType],	16h ; int16_t
//@ 		mov	al, [di-3272h]
//@ 		and	al, 10h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_246B1	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1593
//@ 
//@ loc_246AA:				; CODE XREF: SendRocketToMe+214j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+vvz], ax	; int16_t
//@ 		jmp	short loc_246DA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1594
//@ 
//@ loc_246B1:				; CODE XREF: SendRocketToMe+222j
//@ 		mov	ax, [bp+L]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+tz]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mz]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0FFC0h
//@ 		mov	bx, 0FFFFh
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+vvz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1597
//@ 
//@ loc_246DA:				; CODE XREF: SendRocketToMe+229j
//@ 		mov	b0, 0C000h	; uint16_t
//@ 		mov	ax, [bp+Fi]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		sub	b0, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1598
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		add	ax, [bp+$dx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		add	ax, [bp+dy]	; int16_t
//@ 		push	ax
//@ 		push	[bp+mz]		; int16_t
//@ 		push	[bp+vvx]	; int16_t
//@ 		push	[bp+vvy]	; int16_t
//@ 		push	[bp+vvz]	; int16_t
//@ 		push	[bp+RType]	; int16_t
//@ 		push	[bp+OwId]	; int16_t
//@ 		push	b0		; uint16_t
//@ 		push	[bp+Target]	; int16_t
//@ 		call	AddRocket	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1599
//@ 
//@ locret_24716:				; CODE XREF: SendRocketToMe+1AAj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	10h		; Return Far from Procedure
//@ SendRocketToMe	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1635
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CheckSwitchShoot proc far		; CODE XREF: TryToGo+124P
//@ 					; TryToGo2B+4AP ...
//@ 
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; int16_t
//@ o		= word ptr  6		; int16_t
//@ y		= word ptr  8		; int16_t
//@ x		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1636
//@ 		cmp	[bp+o],	7	; int16_t
//@ 		jle	short loc_24726	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	short locret_24772 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1637
//@ 
//@ loc_24726:				; CODE XREF: CheckSwitchShoot+8j
//@ 		mov	ax, LinksCount	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_4], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jg	short locret_24772 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2473C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24739:				; CODE XREF: CheckSwitchShoot+56j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1638
//@ 
//@ loc_2473C:				; CODE XREF: CheckSwitchShoot+1Dj
//@ 		imul	ax, [bp+n], 7	; int16_t
//@ 		les	di, PLinks	; TLinksList$Element*
//@ 		add	di, ax		; Add
//@ ; #line	"CSPUTL.PAS" 1639
//@ 		cmp	byte ptr es:[di], 73h ;	's' ; Compare Two Operands
//@ 		jnz	short loc_2476A	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+1]
//@ 		cmp	ax, [bp+x]	; int16_t
//@ 		jnz	short loc_2476A	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+3]
//@ 		cmp	ax, [bp+y]	; int16_t
//@ 		jnz	short loc_2476A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1640
//@ 		push	word ptr es:[di+5]
//@ 		push	[bp+o]		; int16_t
//@ 		call	StartProcess	; function far PASCAL returns void
//@ 
//@ loc_2476A:				; CODE XREF: CheckSwitchShoot+30j
//@ 					; CheckSwitchShoot+39j	...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jnz	short loc_24739	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1641
//@ 
//@ locret_24772:				; CODE XREF: CheckSwitchShoot+Aj
//@ 					; CheckSwitchShoot+18j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ CheckSwitchShoot endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1647
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MakeBlow	proc far		; CODE XREF: AnimateRockets+78EP
//@ 					; ExplodeMine+8DP ...
//@ 
//@ var_26		= dword	ptr -26h
//@ var_22		= dword	ptr -22h
//@ var_1E		= word ptr -1Eh
//@ var_1C		= word ptr -1Ch
//@ ow		= word ptr -16h		; int16_t
//@ oo		= word ptr -14h		; int16_t
//@ swr		= word ptr -12h		; int16_t
//@ z		= word ptr -10h		; int16_t
//@ n		= word ptr -0Ch		; int16_t
//@ j		= word ptr -0Ah		; int16_t
//@ y		= word ptr -8		; int16_t
//@ x		= word ptr -6		; int16_t
//@ oz		= word ptr -4		; int16_t
//@ BCnt		= word ptr -2		; int16_t
//@ o		= word ptr  6		; int16_t
//@ p		= word ptr  8		; int16_t
//@ R		= word ptr  0Ah		; int16_t
//@ rz		= word ptr  0Ch		; int16_t
//@ ry		= word ptr  0Eh		; int16_t
//@ rx		= word ptr  10h		; int16_t
//@ 
//@ 		enter	26h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1648
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_24788	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_2478B	; Jump if Zero (ZF=1)
//@ 
//@ loc_24788:				; CODE XREF: MakeBlow+9j
//@ 		jmp	locret_24DA6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1650
//@ 
//@ loc_2478B:				; CODE XREF: MakeBlow+10j
//@ 		cmp	[bp+o],	8	; int16_t
//@ 		jge	short loc_247A1	; Jump if Greater or Equal (SF=OF)
//@ 		push	[bp+o]		; int16_t
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	0
//@ 		call	WeakUpMonstersTo ; function far	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1651
//@ 
//@ loc_247A1:				; CODE XREF: MakeBlow+19j
//@ 		cmp	[bp+rz], 1000h	; int16_t
//@ 		jle	short loc_247AB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_24DA6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1655
//@ 
//@ loc_247AB:				; CODE XREF: MakeBlow+30j
//@ 		cmp	[bp+R],	0C8h ; 'È' ; int16_t
//@ 		jg	short loc_247B5	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_248FF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1656
//@ 
//@ loc_247B5:				; CODE XREF: MakeBlow+3Aj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_247BF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_247BC:				; CODE XREF: MakeBlow+186j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_247BF:				; CODE XREF: MakeBlow+44j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	[bp+var_1E], di
//@ 		mov	[bp+var_1C], es
//@ ; #line	"CSPUTL.PAS" 1657
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_247D9	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_248F6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1659
//@ 
//@ loc_247D9:				; CODE XREF: MakeBlow+5Ej
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+j],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1660
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		cmp	ax, [bp+R]	; int16_t
//@ 		jl	short loc_247FC	; Jump if Less (SF!=OF)
//@ 		jmp	loc_248F6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1661
//@ 
//@ loc_247FC:				; CODE XREF: MakeBlow+81j
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		les	di, dword ptr [bp+var_1E] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	5
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_2481B	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_248F6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1663
//@ 
//@ loc_2481B:				; CODE XREF: MakeBlow+A0j
//@ 		cmp	[bp+j],	64h ; 'd' ; int16_t
//@ 		jge	short loc_24829	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		mov	[bp+swr], ax	; int16_t
//@ 		jmp	short loc_24856	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1664
//@ 
//@ loc_24829:				; CODE XREF: MakeBlow+A9j
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		sub	ax, [bp+j]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+swr], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1666
//@ 
//@ loc_24856:				; CODE XREF: MakeBlow+B1j
//@ 		les	di, dword ptr [bp+var_1E] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		les	di, dword ptr [bp+var_1E] ; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSPUTL.PAS" 1667
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+swr]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, dword ptr [bp+var_1E] ; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CSPUTL.PAS" 1668
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jnz	short loc_248D3	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+1Ah], 20h ; ' ' ; Compare Two Operands
//@ 		jle	short loc_248D3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1670
//@ 		mov	ax, es:[di+1Ah]
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1671
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 100h	; Add
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jle	short loc_248C1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+1Ah]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CSPUTL.PAS" 1672
//@ 
//@ loc_248C1:				; CODE XREF: MakeBlow+13Fj
//@ 		les	di, dword ptr [bp+var_1E] ; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+0Eh] ; Increment by 1
//@ ; #line	"CSPUTL.PAS" 1673
//@ 		mov	ax, es:[di+2Ah]
//@ 		or	ax, 100h	; Logical Inclusive OR
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"CSPUTL.PAS" 1675
//@ 
//@ loc_248D3:				; CODE XREF: MakeBlow+125j
//@ 					; MakeBlow+12Cj
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+swr]	; int16_t
//@ 		push	[bp+n]		; int16_t
//@ 		push	[bp+o]		; int16_t
//@ 		call	ShootMe		; function far PASCAL returns void
//@ 		les	di, dword ptr [bp+var_1E] ; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSPUTL.PAS" 1677
//@ 
//@ loc_248F6:				; CODE XREF: MakeBlow+60j MakeBlow+83j ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jz	short loc_248FF	; Jump if Zero (ZF=1)
//@ 		jmp	loc_247BC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1679
//@ 
//@ loc_248FF:				; CODE XREF: MakeBlow+3Cj
//@ 					; MakeBlow+184j
//@ 		cmp	[bp+o],	64h ; 'd' ; int16_t
//@ 		jle	short loc_2490C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ow], ax	; int16_t
//@ 		jmp	short loc_24912	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2490C:				; CODE XREF: MakeBlow+18Dj
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		mov	[bp+ow], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1680
//@ 
//@ loc_24912:				; CODE XREF: MakeBlow+194j
//@ 		cmp	[bp+o],	64h ; 'd' ; int16_t
//@ 		jle	short loc_24923	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	[bp+oo], ax	; int16_t
//@ 		jmp	short loc_24928	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24923:				; CODE XREF: MakeBlow+1A0j
//@ 		mov	[bp+oo], 0FFh	; int16_t
//@ ; #line	"CSPUTL.PAS" 1682
//@ 
//@ loc_24928:				; CODE XREF: MakeBlow+1ABj
//@ 		cmp	[bp+R],	0C8h ; 'È' ; int16_t
//@ 		jg	short loc_24932	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_249FE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1683
//@ 
//@ loc_24932:				; CODE XREF: MakeBlow+1B7j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_1C], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jle	short loc_24943	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_249FE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24943:				; CODE XREF: MakeBlow+1C8j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2494B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24948:				; CODE XREF: MakeBlow+285j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_2494B:				; CODE XREF: MakeBlow+1D0j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+oo]	; int16_t
//@ 		jnz	short loc_24956	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_249F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1684
//@ 
//@ loc_24956:				; CODE XREF: MakeBlow+1DBj
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_22+2],	di
//@ 		mov	[bp+var_1E], es
//@ ; #line	"CSPUTL.PAS" 1685
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_24970	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_249F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1687
//@ 
//@ loc_24970:				; CODE XREF: MakeBlow+1F5j
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+j],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1688
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		cmp	ax, [bp+R]	; int16_t
//@ 		jge	short loc_249F3	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 1689
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		les	di, [bp+var_22+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	3
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_249F3	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1691
//@ 		cmp	[bp+j],	64h ; 'd' ; int16_t
//@ 		jge	short loc_249B8	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		mov	[bp+swr], ax	; int16_t
//@ 		jmp	short loc_249D5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1692
//@ 
//@ loc_249B8:				; CODE XREF: MakeBlow+238j
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		sub	ax, [bp+j]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mul	[bp+p]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+swr], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1693
//@ 
//@ loc_249D5:				; CODE XREF: MakeBlow+240j
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+n]		; int16_t
//@ 		push	[bp+swr]	; int16_t
//@ 		push	[bp+swr]	; int16_t
//@ 		push	[bp+o]		; int16_t
//@ 		call	ShootMonster	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1695
//@ 
//@ loc_249F3:				; CODE XREF: MakeBlow+1DDj
//@ 					; MakeBlow+1F7j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jz	short loc_249FE	; Jump if Zero (ZF=1)
//@ 		jmp	loc_24948	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1697
//@ 
//@ loc_249FE:				; CODE XREF: MakeBlow+1B9j
//@ 					; MakeBlow+1CAj ...
//@ 		cmp	[bp+R],	0C8h ; 'È' ; int16_t
//@ 		jg	short loc_24A08	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_24AD2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24A08:				; CODE XREF: MakeBlow+28Dj
//@ 		cmp	[bp+p],	64h ; 'd' ; int16_t
//@ 		jge	short loc_24A11	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_24AD2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1698
//@ 
//@ loc_24A11:				; CODE XREF: MakeBlow+296j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_1C], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jle	short loc_24A22	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_24AD2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24A22:				; CODE XREF: MakeBlow+2A7j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_24A2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24A27:				; CODE XREF: MakeBlow+359j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_24A2A:				; CODE XREF: MakeBlow+2AFj
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_22+2],	di
//@ 		mov	[bp+var_1E], es
//@ ; #line	"CSPUTL.PAS" 1699
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jz	short loc_24A44	; Jump if Zero (ZF=1)
//@ 		jmp	loc_24AC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24A44:				; CODE XREF: MakeBlow+2C9j
//@ 		cmp	byte ptr es:[di+0Bh], 0FFh ; Compare Two Operands
//@ 		jz	short loc_24AC7	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1701
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		add	ax, 96h	; '–'   ; Add
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1702
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		cmp	ax, [bp+R]	; int16_t
//@ 		jge	short loc_24AC7	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 1703
//@ 		les	di, [bp+var_22+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 800h	; Add
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jle	short loc_24AC7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1704
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	3
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_24AC7	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1706
//@ 		les	di, [bp+var_22+2] ; Load Full Pointer to ES:xx
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
//@ ; #line	"CSPUTL.PAS" 1707
//@ 		les	di, [bp+var_22+2] ; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+0Bh], 0FFh
//@ ; #line	"CSPUTL.PAS" 1709
//@ 
//@ loc_24AC7:				; CODE XREF: MakeBlow+2CBj
//@ 					; MakeBlow+2D3j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jz	short loc_24AD2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_24A27	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1713
//@ 
//@ loc_24AD2:				; CODE XREF: MakeBlow+28Fj
//@ 					; MakeBlow+298j ...
//@ 		mov	ax, MnCount	; uint16_t
//@ 		mov	[bp+var_1C], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jle	short loc_24AE3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_24B63	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24AE3:				; CODE XREF: MakeBlow+368j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_24AEB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24AE8:				; CODE XREF: MakeBlow+3EBj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1714
//@ 
//@ loc_24AEB:				; CODE XREF: MakeBlow+370j
//@ 		imul	di, [bp+n], 0Ah	; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_22+2],	di
//@ 		mov	[bp+var_1E], es
//@ ; #line	"CSPUTL.PAS" 1715
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		add	ax, 28h	; '('   ; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_24B26	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_24B5B	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_24B5B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 1716
//@ 
//@ loc_24B26:				; CODE XREF: MakeBlow+3A8j
//@ 		les	di, [bp+var_22+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+6]
//@ 		sub	ax, [bp+rz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 800h	; Compare Two Operands
//@ 		jge	short loc_24B5B	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 1717
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	3
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_24B5B	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1718
//@ 		les	di, [bp+var_22+2] ; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+4], 40Ah
//@ 
//@ loc_24B5B:				; CODE XREF: MakeBlow+3AAj
//@ 					; MakeBlow+3AEj ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jnz	short loc_24AE8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1722
//@ 
//@ loc_24B63:				; CODE XREF: MakeBlow+36Aj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+BCnt], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1723
//@ 		cmp	[bp+R],	0	; int16_t
//@ 		jnz	short loc_24B75	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+swr], 3Ch ;	'<' ; int16_t
//@ 		jmp	short loc_24B7A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24B75:				; CODE XREF: MakeBlow+3F6j
//@ 		mov	[bp+swr], 56h ;	'V' ; int16_t
//@ ; #line	"CSPUTL.PAS" 1725
//@ 
//@ loc_24B7A:				; CODE XREF: MakeBlow+3FDj
//@ 		mov	al, byte ptr [bp+rx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 3		; Add
//@ 		mov	[bp+var_1C], ax
//@ 		mov	al, byte ptr [bp+rx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 3		; Integer Subtraction
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jle	short loc_24B95	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_24DA6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24B95:				; CODE XREF: MakeBlow+41Aj
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_24B9D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24B9A:				; CODE XREF: MakeBlow+62Dj
//@ 		inc	[bp+x]		; int16_t
//@ 
//@ loc_24B9D:				; CODE XREF: MakeBlow+422j
//@ 		cmp	[bp+x],	0	; int16_t
//@ 		jge	short loc_24BA6	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_24D9B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24BA6:				; CODE XREF: MakeBlow+42Bj
//@ 		cmp	[bp+x],	3Fh ; '?' ; int16_t
//@ 		jle	short loc_24BAF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_24D9B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1726
//@ 
//@ loc_24BAF:				; CODE XREF: MakeBlow+434j
//@ 		mov	al, byte ptr [bp+ry+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 3		; Add
//@ 		mov	[bp+var_1E], ax
//@ 		mov	al, byte ptr [bp+ry+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 3		; Integer Subtraction
//@ 		cmp	ax, [bp+var_1E]	; Compare Two Operands
//@ 		jle	short loc_24BCA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_24D9B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24BCA:				; CODE XREF: MakeBlow+44Fj
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_24BD2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24BCF:				; CODE XREF: MakeBlow+622j
//@ 		inc	[bp+y]		; int16_t
//@ 
//@ loc_24BD2:				; CODE XREF: MakeBlow+457j
//@ 		cmp	[bp+y],	0	; int16_t
//@ 		jge	short loc_24BDB	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24BDB:				; CODE XREF: MakeBlow+460j
//@ 		cmp	[bp+y],	3Fh ; '?' ; int16_t
//@ 		jle	short loc_24BE4	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24BE4:				; CODE XREF: MakeBlow+469j
//@ 		cmp	[bp+BCnt], 2	; int16_t
//@ 		jl	short loc_24BED	; Jump if Less (SF!=OF)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1727
//@ 
//@ loc_24BED:				; CODE XREF: MakeBlow+472j
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_22], di
//@ 		mov	word ptr [bp+var_22+2],	es
//@ ; #line	"CSPUTL.PAS" 1728
//@ 		mov	al, es:[di]
//@ ; #line	"CSPUTL.PAS" 1729
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jnz	short loc_24C4E	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+3]
//@ 		add	ax, es:[di+7]	; Add
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		add	ax, es:[di+9]	; Add
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 100h	; Compare Two Operands
//@ 		jge	short loc_24C4B	; Jump if Greater or Equal (SF=OF)
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+o]		; int16_t
//@ 		call	CheckSwitchShoot ; function far	PASCAL returns void
//@ 
//@ loc_24C4B:				; CODE XREF: MakeBlow+4C5j
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1730
//@ 
//@ loc_24C4E:				; CODE XREF: MakeBlow+495j
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnb	short loc_24C55	; Jump if Not Below (CF=0)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24C55:				; CODE XREF: MakeBlow+4DAj
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_24C5C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24C5C:				; CODE XREF: MakeBlow+4E1j
//@ 		les	di, [bp+var_22]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_26], di
//@ 		mov	word ptr [bp+var_26+2],	es
//@ ; #line	"CSPUTL.PAS" 1732
//@ 		les	di, [bp+var_22]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+oz], ax	; int16_t
//@ 		mov	ax, [bp+oz]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+oz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1733
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, [bp+rz]	; int16_t
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_26]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		add	ax, [bp+oz]	; int16_t
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jl	short loc_24CA7	; Jump if Less (SF!=OF)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24CA7:				; CODE XREF: MakeBlow+52Cj
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+14h]
//@ 		add	ax, [bp+oz]	; int16_t
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jg	short loc_24CC4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1736
//@ 
//@ loc_24CC4:				; CODE XREF: MakeBlow+549j
//@ 		les	di, [bp+var_22]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+swr]	; int16_t
//@ 		les	di, [bp+var_26]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di]	; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jle	short loc_24D03	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+o]		; int16_t
//@ 		call	CheckSwitchShoot ; function far	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1737
//@ 
//@ loc_24D03:				; CODE XREF: MakeBlow+57Dj
//@ 		les	di, [bp+var_26]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Ah], 0	; Compare Two Operands
//@ 		jg	short loc_24D10	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_24D90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24D10:				; CODE XREF: MakeBlow+595j
//@ 		cmp	[bp+R],	78h ; 'x' ; int16_t
//@ 		jl	short loc_24D90	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1738
//@ 		les	di, [bp+var_22]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		les	di, [bp+var_26]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di]	; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jle	short loc_24D90	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1739
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		les	di, [bp+var_22]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	5
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_24D90	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1741
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		les	di, [bp+var_22]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+9], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1742
//@ 		cmp	word ptr es:[di+9], 0 ;	Compare	Two Operands
//@ 		jg	short loc_24D90	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSPUTL.PAS" 1743
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		call	Blow3dObjAt	; function far PASCAL returns void
//@ 		inc	[bp+BCnt]	; int16_t
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+o]		; int16_t
//@ 		call	CheckSwitchShoot ; function far	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1746
//@ 
//@ loc_24D90:				; CODE XREF: MakeBlow+462j
//@ 					; MakeBlow+46Bj ...
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, [bp+var_1E]	; Compare Two Operands
//@ 		jz	short loc_24D9B	; Jump if Zero (ZF=1)
//@ 		jmp	loc_24BCF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24D9B:				; CODE XREF: MakeBlow+42Dj
//@ 					; MakeBlow+436j ...
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jz	short locret_24DA6 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_24B9A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1748
//@ 
//@ locret_24DA6:				; CODE XREF: MakeBlow:loc_24788j
//@ 					; MakeBlow+32j	...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ MakeBlow	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1753
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MakeGreatBlow	proc near		; CODE XREF: Blow3dObjAt+384p
//@ 
//@ j		= word ptr -2		; int16_t
//@ z		= word ptr  4		; int16_t
//@ y		= word ptr  6		; int16_t
//@ x		= word ptr  8		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1754
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	140h
//@ 		push	3Ch ; '<'
//@ 		push	0
//@ 		call	MakeBlow	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1755
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_24DCD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24DCA:				; CODE XREF: MakeGreatBlow+59j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1756
//@ 
//@ loc_24DCD:				; CODE XREF: MakeGreatBlow+1Ej
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	[bp+z]		; int16_t
//@ 		push	23h ; '#'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		sub	ax, 11h		; Integer Subtraction
//@ 		push	ax
//@ 		push	23h ; '#'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		sub	ax, 11h		; Integer Subtraction
//@ 		push	ax
//@ 		push	118h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		sub	ax, 26h	; '&'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	8
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	1Dh	; int16_t
//@ 		jnz	short loc_24DCA	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1760
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ MakeGreatBlow	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1766
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Blow3dObjAt	proc far		; CODE XREF: MakeChanges+76P
//@ 					; ExecuteEvent+75P ...
//@ 
//@ var_2C		= dword	ptr -2Ch
//@ var_28		= word ptr -28h
//@ m		= word ptr -26h		; int16_t
//@ gy		= word ptr -24h		; int16_t
//@ gx		= word ptr -22h		; int16_t
//@ k		= word ptr -20h		; int16_t
//@ j		= word ptr -1Eh		; int16_t
//@ vy2		= word ptr -1Ah		; int16_t
//@ vx2		= word ptr -18h		; int16_t
//@ vy		= word ptr -16h		; int16_t
//@ vx		= word ptr -14h		; int16_t
//@ sy		= word ptr -12h		; int16_t
//@ sx		= word ptr -10h		; int16_t
//@ gb		= word ptr -0Eh		; int16_t
//@ lb		= word ptr -0Ch		; int16_t
//@ s		= word ptr -0Ah		; int16_t
//@ zH		= word ptr -8		; int16_t
//@ z0		= word ptr -6		; int16_t
//@ vH		= word ptr -4		; int16_t
//@ v0		= word ptr -2		; int16_t
//@ my		= word ptr  6		; int16_t
//@ mx		= word ptr  8		; int16_t
//@ 
//@ 		enter	2Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1767
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74B8h], 0 ; Compare Two Operands
//@ 		jnz	short loc_24E35	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_252B5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1769
//@ 
//@ loc_24E35:				; CODE XREF: Blow3dObjAt+27j
//@ 		mov	ax, LinksCount	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_28], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_28]	; Compare Two Operands
//@ 		jg	short loc_24E9A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_24E4B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24E48:				; CODE XREF: Blow3dObjAt+8Fj
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1770
//@ 
//@ loc_24E4B:				; CODE XREF: Blow3dObjAt+3Dj
//@ 		imul	ax, [bp+j], 7	; int16_t
//@ 		les	di, PLinks	; TLinksList$Element*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_2C], di
//@ 		mov	word ptr [bp+var_2C+2],	es
//@ ; #line	"CSPUTL.PAS" 1771
//@ 		cmp	byte ptr es:[di], 64h ;	'd' ; Compare Two Operands
//@ 		jnz	short loc_24E92	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+1]
//@ 		cmp	ax, [bp+mx]	; int16_t
//@ 		jnz	short loc_24E92	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+3]
//@ 		cmp	ax, [bp+my]	; int16_t
//@ 		jnz	short loc_24E92	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1773
//@ 		imul	ax, es:[di+5], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+2], 0
//@ ; #line	"CSPUTL.PAS" 1774
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+5]
//@ 		push	0FFFFh
//@ 		call	StartProcess	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1775
//@ 
//@ loc_24E92:				; CODE XREF: Blow3dObjAt+56j
//@ 					; Blow3dObjAt+5Fj ...
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		cmp	ax, [bp+var_28]	; Compare Two Operands
//@ 		jnz	short loc_24E48	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1778
//@ 
//@ loc_24E9A:				; CODE XREF: Blow3dObjAt+38j
//@ 		mov	[bp+vx], 0Ah	; int16_t
//@ 		mov	[bp+z0], 3Ch ; '<' ; int16_t
//@ 		mov	[bp+zH], 0Ah	; int16_t
//@ 		mov	[bp+v0], 0FFA6h	; int16_t
//@ 		mov	[bp+vH], 12Ch	; int16_t
//@ ; #line	"CSPUTL.PAS" 1780
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2C+2],	di
//@ 		mov	[bp+var_28], es
//@ ; #line	"CSPUTL.PAS" 1782
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	[bp+s],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1783
//@ 		cmp	[bp+s],	3E8h	; int16_t
//@ 		jge	short loc_24EF2	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+lb], 1	; int16_t
//@ 		jmp	short loc_24EFC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24EF2:				; CODE XREF: Blow3dObjAt+E0j
//@ 		sub	[bp+s],	3E8h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+lb], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1784
//@ 
//@ loc_24EFC:				; CODE XREF: Blow3dObjAt+E7j
//@ 		cmp	[bp+s],	64h ; 'd' ; int16_t
//@ 		jge	short loc_24F09	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+gb], ax	; int16_t
//@ 		jmp	short loc_24F12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24F09:				; CODE XREF: Blow3dObjAt+F7j
//@ 		sub	[bp+s],	64h ; 'd' ; int16_t
//@ 		mov	[bp+gb], 1	; int16_t
//@ ; #line	"CSPUTL.PAS" 1785
//@ 
//@ loc_24F12:				; CODE XREF: Blow3dObjAt+FEj
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+z0], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1786
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jge	short loc_24F4B	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	word ptr es:[di+8], 0 ;	Compare	Two Operands
//@ 		jle	short loc_24F4B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+8]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	[bp+z0], ax	; int16_t
//@ 		jmp	short loc_24F5C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1787
//@ 
//@ loc_24F4B:				; CODE XREF: Blow3dObjAt+12Dj
//@ 					; Blow3dObjAt+134j
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		add	ax, es:[di+14h]	; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		add	[bp+z0], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1788
//@ 
//@ loc_24F5C:				; CODE XREF: Blow3dObjAt+140j
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+10h], 0	; Compare Two Operands
//@ 		jle	short loc_24FA2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1789
//@ 		push	0FFFFh
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	word ptr es:[di+3]
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	word ptr es:[di+5]
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1792
//@ 
//@ loc_24FA2:				; CODE XREF: Blow3dObjAt+15Bj
//@ 		mov	[bp+m],	10h	; int16_t
//@ ; #line	"CSPUTL.PAS" 1793
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_24FB8	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_24FB8	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25040	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1794
//@ 
//@ loc_24FB8:				; CODE XREF: Blow3dObjAt+1A3j
//@ 					; Blow3dObjAt+1AAj
//@ 		mov	ax, ChangesCount ; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_28], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_28]	; Compare Two Operands
//@ 		jg	short loc_25040	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_24FCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24FCB:				; CODE XREF: Blow3dObjAt+235j
//@ 		inc	[bp+j]		; int16_t
//@ 
//@ loc_24FCE:				; CODE XREF: Blow3dObjAt+1C0j
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, PChanges	; TChangesList$Element*
//@ 		add	di, ax		; Add
//@ ; #line	"CSPUTL.PAS" 1795
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, [bp+mx]	; int16_t
//@ 		jnz	short loc_25038	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+2]
//@ 		cmp	ax, [bp+my]	; int16_t
//@ 		jnz	short loc_25038	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1796
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_25023	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		and	ax, 7		; Logical AND
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		mov	al, [di-0D14h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		mov	dl, al
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		mov	[di-0D14h], dl
//@ 		jmp	short loc_25038	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1797
//@ 
//@ loc_25023:				; CODE XREF: Blow3dObjAt+1E7j
//@ 		push	21h ; '!'
//@ 		mov	al, byte ptr [bp+j] ; int16_t
//@ 		push	ax
//@ 		push	0
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ 
//@ loc_25038:				; CODE XREF: Blow3dObjAt+1D7j
//@ 					; Blow3dObjAt+1E0j ...
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		cmp	ax, [bp+var_28]	; Compare Two Operands
//@ 		jnz	short loc_24FCB	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1799
//@ 
//@ loc_25040:				; CODE XREF: Blow3dObjAt+1ACj
//@ 					; Blow3dObjAt+1BBj
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_2C+2],	di
//@ 		mov	[bp+var_28], es
//@ ; #line	"CSPUTL.PAS" 1801
//@ 		inc	byte ptr es:[di] ; Increment by	1
//@ ; #line	"CSPUTL.PAS" 1803
//@ 		cmp	[bp+s],	33h ; '3' ; int16_t
//@ 		jge	short loc_25065	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_25128	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1805
//@ 
//@ loc_25065:				; CODE XREF: Blow3dObjAt+257j
//@ 		mov	[bp+zH], 20h ; ' ' ; int16_t
//@ ; #line	"CSPUTL.PAS" 1806
//@ 		mov	[bp+j],	1	; int16_t
//@ 		jmp	short loc_25074	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25071:				; CODE XREF: Blow3dObjAt+319j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPUTL.PAS" 1808
//@ 
//@ loc_25074:				; CODE XREF: Blow3dObjAt+266j
//@ 		push	14h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+gx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1809
//@ 		push	14h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+gy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1810
//@ 		cmp	[bp+s],	47h ; 'G' ; int16_t
//@ 		jnz	short loc_250F3	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+gx]		; int16_t
//@ 		push	[bp+gy]		; int16_t
//@ 		push	[bp+zH]		; int16_t
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+z0]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 5
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, 47h	; 'G'   ; Add
//@ 		push	ax
//@ 		push	0
//@ 		call	AddSinglePart	; function far PASCAL returns void
//@ 		jmp	short loc_2511C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1811
//@ 
//@ loc_250F3:				; CODE XREF: Blow3dObjAt+2B3j
//@ 		push	[bp+gx]		; int16_t
//@ 		push	[bp+gy]		; int16_t
//@ 		push	[bp+zH]		; int16_t
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+z0]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		push	[bp+s]		; int16_t
//@ 		push	0
//@ 		call	AddSinglePart	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1812
//@ 
//@ loc_2511C:				; CODE XREF: Blow3dObjAt+2E8j
//@ 		cmp	[bp+j],	8	; int16_t
//@ 		jz	short loc_25125	; Jump if Zero (ZF=1)
//@ 		jmp	loc_25071	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1813
//@ 
//@ loc_25125:				; CODE XREF: Blow3dObjAt+317j
//@ 		jmp	locret_252B5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1824
//@ 
//@ loc_25128:				; CODE XREF: Blow3dObjAt+259j
//@ 		mov	[bp+sy], 1	; int16_t
//@ 		mov	[bp+sx], 1	; int16_t
//@ 		mov	[bp+vy], 14h	; int16_t
//@ 		mov	[bp+vy2], 28h ;	'(' ; int16_t
//@ 		mov	[bp+vx], 14h	; int16_t
//@ 		mov	[bp+vx2], 28h ;	'(' ; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+v0], ax	; int16_t
//@ 		mov	[bp+m],	10h	; int16_t
//@ ; #line	"CSPUTL.PAS" 1825
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_2515E	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_25175	; Jump if Zero (ZF=1)
//@ 
//@ loc_2515E:				; CODE XREF: Blow3dObjAt+34Cj
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	0Ch
//@ 		push	20h ; ' '
//@ 		push	84h ; '„'
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1828
//@ 
//@ loc_25175:				; CODE XREF: Blow3dObjAt+353j
//@ 		cmp	[bp+gb], 0	; int16_t
//@ 		jle	short loc_25190	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	ax, [bp+z0]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	MakeGreatBlow	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1829
//@ 
//@ loc_25190:				; CODE XREF: Blow3dObjAt+370j
//@ 		cmp	[bp+lb], 0	; int16_t
//@ 		jle	short loc_251A6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		call	RemoveLight	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1831
//@ 
//@ loc_251A6:				; CODE XREF: Blow3dObjAt+38Bj
//@ 		mov	ax, [bp+m]	; int16_t
//@ 		mov	word ptr [bp+var_2C], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, word ptr [bp+var_2C] ; Compare Two Operands
//@ 		jle	short loc_251B7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_252B5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_251B7:				; CODE XREF: Blow3dObjAt+3A9j
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_251BF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_251BC:				; CODE XREF: Blow3dObjAt+4A9j
//@ 		inc	[bp+j]		; int16_t
//@ 
//@ loc_251BF:				; CODE XREF: Blow3dObjAt+3B1j
//@ 		cmp	BCount,	96h ; '–' ; uint16_t
//@ 		jb	short loc_251CA	; Jump if Below	(CF=1)
//@ 		jmp	loc_252AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1833
//@ 
//@ loc_251CA:				; CODE XREF: Blow3dObjAt+3BCj
//@ 		push	2Ch ; ','
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 0Ah		; Add
//@ 		mov	[bp+k],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1834
//@ 		push	20h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+gx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1835
//@ 		push	20h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+gy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1836
//@ 		push	[bp+gx]		; int16_t
//@ 		push	[bp+gy]		; int16_t
//@ 		mov	ax, [bp+zH]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+z0]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	[bp+vx2]	; int16_t
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+sx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	[bp+vy2]	; int16_t
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+sy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	[bp+vH]		; int16_t
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+v0]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	[bp+s]		; int16_t
//@ 		call	AddBlow		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1839
//@ 
//@ loc_252AA:				; CODE XREF: Blow3dObjAt+3BEj
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_2C] ; Compare Two Operands
//@ 		jz	short locret_252B5 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_251BC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1841
//@ 
//@ locret_252B5:				; CODE XREF: Blow3dObjAt+29j
//@ 					; Blow3dObjAt:loc_25125j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ Blow3dObjAt	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1850
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateBlows	proc far		; CODE XREF: DoGame+16E0P
//@ 
//@ var_8		= dword	ptr -8
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1851
//@ 		mov	n$0, 1		; int16_t
//@ ; #line	"CSPUTL.PAS" 1852
//@ 
//@ loc_252C3:				; CODE XREF: AnimateBlows+2C7j
//@ 		mov	ax, BCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_252E0	; Jump if Less (SF!=OF)
//@ 		jle	short loc_252D9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_25583	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_252D9:				; CODE XREF: AnimateBlows+1Bj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_252E0	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_25583	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1853
//@ 
//@ loc_252E0:				; CODE XREF: AnimateBlows+19j
//@ 					; AnimateBlows+22j
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, BlowsList	; TBlow*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF0h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPUTL.PAS" 1854
//@ 		imul	di, es:[di+2], 3Ah ; Signed Multiply
//@ 		add	di, 0D698h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSPUTL.PAS" 1857
//@ 		cmp	OAnimate, 0	; bool
//@ 		jz	short loc_25386	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1859
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		inc	word ptr es:[di] ; Increment by	1
//@ ; #line	"CSPUTL.PAS" 1860
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_25349	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1861
//@ 		cmp	BCount,	96h ; '–' ; uint16_t
//@ 		jnb	short loc_25349	; Jump if Not Below (CF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		mov	ax, es:[di+8]
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	6
//@ 		push	2
//@ 		call	AddBlow		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1862
//@ 
//@ loc_25349:				; CODE XREF: AnimateBlows+66j
//@ 					; AnimateBlows+6Ej
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+2], 8 ;	Compare	Two Operands
//@ 		jnz	short loc_25386	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1864
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 6
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSPUTL.PAS" 1865
//@ 		mov	ax, es:[di+0Ah]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSPUTL.PAS" 1866
//@ 		mov	ax, es:[di+0Ch]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 1870
//@ 
//@ loc_25386:				; CODE XREF: AnimateBlows+53j
//@ 					; AnimateBlows+98j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+4], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1871
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1872
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"CSPUTL.PAS" 1877
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		and	al, 8		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_25431	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1878
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jl	short loc_25431	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1879
//@ 		mov	al, es:[di+2]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_25424	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		jmp	short loc_25431	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1880
//@ 
//@ loc_25424:				; CODE XREF: AnimateBlows+15Fj
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		dec	ax		; Decrement by 1
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"CSPUTL.PAS" 1884
//@ 
//@ loc_25431:				; CODE XREF: AnimateBlows+147j
//@ 					; AnimateBlows+155j ...
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		and	al, 8		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_254AD	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1885
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 0 ;	Compare	Two Operands
//@ 		jg	short loc_254AD	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSPUTL.PAS" 1887
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 46h	; 'F'   ; Compare Two Operands
//@ 		jge	short loc_25464	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		jmp	short loc_254AD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1889
//@ 
//@ loc_25464:				; CODE XREF: AnimateBlows+19Bj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Eh], ax
//@ 		cmp	word ptr es:[di+0Eh], 0A0h ; ' ' ; Compare Two Operands
//@ 		jle	short loc_2548E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	word ptr es:[di+0Eh], 0A0h ; ' '
//@ ; #line	"CSPUTL.PAS" 1890
//@ 
//@ loc_2548E:				; CODE XREF: AnimateBlows+1CDj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSPUTL.PAS" 1891
//@ 		mov	ax, es:[di+0Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 1896
//@ 
//@ loc_254AD:				; CODE XREF: AnimateBlows+183j
//@ 					; AnimateBlows+18Dj ...
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_25521	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, es:[di+8]	; Add
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_25521	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1898
//@ 		mov	ax, t1		; uint16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		sub	es:[di+0Eh], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1899
//@ 		cmp	OAnimate, 0	; bool
//@ 		jz	short loc_25521	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1900
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jle	short loc_25521	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1901
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+0Ah], 0Fh ; Signed Multiply
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 10h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Ah], ax
//@ 		imul	ax, es:[di+0Ch], 0Fh ; Signed Multiply
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 10h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 1905
//@ 
//@ loc_25521:				; CODE XREF: AnimateBlows+1FFj
//@ 					; AnimateBlows+213j ...
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jl	short loc_2557C	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1908
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, BlowsList	; TBlow*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, BlowsList	; TBlow*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, BCount	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	MoveDB		; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1909
//@ 		dec	n$0		; int16_t
//@ 		dec	BCount		; uint16_t
//@ ; #line	"CSPUTL.PAS" 1911
//@ 
//@ loc_2557C:				; CODE XREF: AnimateBlows+274j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPUTL.PAS" 1912
//@ 		jmp	loc_252C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1913
//@ 
//@ locret_25583:				; CODE XREF: AnimateBlows+1Dj
//@ 					; AnimateBlows+24j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AnimateBlows	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 1920
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShootMonster	proc far		; CODE XREF: MakePunch+91P
//@ 					; MakeBlow+278P ...
//@ 
//@ var_1C		= dword	ptr -1Ch
//@ var_18		= dword	ptr -18h
//@ _ry		= word ptr -14h		; int16_t
//@ _rx		= word ptr -12h		; int16_t
//@ rry		= word ptr -10h		; int16_t
//@ rrx		= word ptr -0Eh		; int16_t
//@ sa		= word ptr -0Ch		; int16_t
//@ ca		= word ptr -0Ah		; int16_t
//@ sfx		= word ptr -8		; int16_t
//@ sl		= word ptr -6		; int16_t
//@ H		= word ptr -4		; int16_t
//@ ow		= word ptr -2		; int16_t
//@ o		= word ptr  6		; int16_t
//@ $bp		= word ptr  8		; int16_t
//@ lp		= word ptr  0Ah		; int16_t
//@ ms		= word ptr  0Ch		; int16_t
//@ _rvy		= word ptr  0Eh		; int16_t
//@ _rvx		= word ptr  10h		; int16_t
//@ rz		= word ptr  12h		; int16_t
//@ ry		= word ptr  14h		; int16_t
//@ rx		= word ptr  16h		; int16_t
//@ 
//@ 		enter	1Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 1921
//@ 		mov	[bp+sfx], 0FFFFh ; int16_t
//@ ; #line	"CSPUTL.PAS" 1922
//@ 		cmp	[bp+o],	64h ; 'd' ; int16_t
//@ 		jle	short loc_255A8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		mov	al, [di-5AD8h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+ow], ax	; int16_t
//@ 		jmp	short loc_255AD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1923
//@ 
//@ loc_255A8:				; CODE XREF: ShootMonster+Dj
//@ 		mov	[bp+ow], 0Ah	; int16_t
//@ ; #line	"CSPUTL.PAS" 1925
//@ 
//@ loc_255AD:				; CODE XREF: ShootMonster+21j
//@ 		imul	di, [bp+ms], 28h ; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_18], di
//@ 		mov	word ptr [bp+var_18+2],	es
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+ow]	; int16_t
//@ 		jnz	short loc_255CB	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_25D06	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_255CB:				; CODE XREF: ShootMonster+41j
//@ 		cmp	word ptr es:[di+8], 0Eh	; Compare Two Operands
//@ 		jnz	short loc_255D5	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_25D06	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1927
//@ 
//@ loc_255D5:				; CODE XREF: ShootMonster+4Bj
//@ 		cmp	byte ptr es:[di+26h], 0	; Compare Two Operands
//@ 		jnz	short loc_25633	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1930
//@ 		push	[bp+o]		; int16_t
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	0FFFFh
//@ 		call	WeakUpMonstersTo ; function far	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1931
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 1932
//@ 		mov	word ptr es:[di+8], 9
//@ ; #line	"CSPUTL.PAS" 1933
//@ 		mov	byte ptr es:[di+26h], 4
//@ ; #line	"CSPUTL.PAS" 1935
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ ; #line	"CSPUTL.PAS" 1936
//@ 		mov	byte ptr es:[di+24h], 0
//@ ; #line	"CSPUTL.PAS" 1937
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSPUTL.PAS" 1938
//@ 		imul	di, es:[di+14h], 58h ; Signed Multiply
//@ 		mov	ax, [di-0FCCh]
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+16h], ax
//@ ; #line	"CSPUTL.PAS" 1939
//@ 		imul	di, es:[di+14h], 58h ; Signed Multiply
//@ 		mov	ax, [di-0FCAh]
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CSPUTL.PAS" 1942
//@ 
//@ loc_25633:				; CODE XREF: ShootMonster+55j
//@ 		cmp	[bp+o],	8	; int16_t
//@ 		jge	short loc_25645	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+14h], ax
//@ 		jmp	short loc_25656	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1943
//@ 
//@ loc_25645:				; CODE XREF: ShootMonster+B2j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 8	; Compare Two Operands
//@ 		jge	short loc_25656	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSPUTL.PAS" 1945
//@ 
//@ loc_25656:				; CODE XREF: ShootMonster+BEj
//@ 					; ShootMonster+C8j
//@ 		mov	ax, 5
//@ 		sub	ax, Skill	; int16_t
//@ 		mul	[bp+lp]		; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	[bp+lp], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1946
//@ 		cmp	[bp+lp], 64h ; 'd' ; int16_t
//@ 		jge	short loc_25692	; Jump if Greater or Equal (SF=OF)
//@ 		push	5
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 6		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+lp]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 3
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+lp], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1948
//@ 
//@ loc_25692:				; CODE XREF: ShootMonster+E5j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jz	short loc_256AF	; Jump if Zero (ZF=1)
//@ 		cmp	al, 76h	; 'v'   ; Compare Two Operands
//@ 		jb	short loc_256A5	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jbe	short loc_256AF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_256A5:				; CODE XREF: ShootMonster+11Aj
//@ 		mov	ax, [bp+lp]	; int16_t
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+12h], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 1950
//@ 
//@ loc_256AF:				; CODE XREF: ShootMonster+116j
//@ 					; ShootMonster+11Ej
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FC4h]
//@ 		mov	[bp+sl], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1951
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FBAh]
//@ 		mov	[bp+H],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 1954
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_25742	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSPUTL.PAS" 1955
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FB4h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+$bp]	; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jl	short loc_25742	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 1957
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, es:[di+0Bh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+rz]		; int16_t
//@ 		call	ExplodeMonster	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1958
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		mov	byte ptr es:[di+26h], 5
//@ ; #line	"CSPUTL.PAS" 1959
//@ 		mov	byte ptr es:[di+0Bh], 0FFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ 		mov	word ptr es:[di+8], 10h
//@ ; #line	"CSPUTL.PAS" 1960
//@ 		jmp	locret_25D06	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1963
//@ 
//@ loc_25742:				; CODE XREF: ShootMonster+15Aj
//@ 					; ShootMonster+179j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Ah], 6Eh ; 'n' ; Compare Two Operands
//@ 		jnz	short loc_25760	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1964
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_25760	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	byte ptr es:[di+0Bh], 0FFh ; Compare Two Operands
//@ 		jz	short loc_25760	; Jump if Zero (ZF=1)
//@ 		mov	word ptr es:[di+12h], 1
//@ ; #line	"CSPUTL.PAS" 1967
//@ 
//@ loc_25760:				; CODE XREF: ShootMonster+1C5j
//@ 					; ShootMonster+1CCj ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 1	; Compare Two Operands
//@ 		jnz	short loc_257D6	; Jump if Not Zero (ZF=0)
//@ 		cmp	byte ptr es:[di+0Ah], 6Eh ; 'n' ; Compare Two Operands
//@ 		jnz	short loc_257D6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1968
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_257D6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1969
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	12h	; Signed Multiply
//@ 		mov	ax, [di-2FB6h]
//@ 		or	ax, [di-2FB4h]	; Logical Inclusive OR
//@ 		jz	short loc_257D6	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1970
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		sub	ax, 180h	; Integer Subtraction
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jge	short loc_257D6	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 1972
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Bh], 4	; Add
//@ ; #line	"CSPUTL.PAS" 1973
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+$bp]	; int16_t
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	2
//@ 		push	word ptr es:[di+4]
//@ 		push	0
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1974
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSPUTL.PAS" 1978
//@ 
//@ loc_257D6:				; CODE XREF: ShootMonster+1E3j
//@ 					; ShootMonster+1EAj ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_25847	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSPUTL.PAS" 1979
//@ 		mov	al, es:[di+0Ah]
//@ ; #line	"CSPUTL.PAS" 1980
//@ 		cmp	al, 6Ah	; 'j'   ; Compare Two Operands
//@ 		jz	short loc_257FC	; Jump if Zero (ZF=1)
//@ 		cmp	al, 6Bh	; 'k'   ; Compare Two Operands
//@ 		jz	short loc_257FC	; Jump if Zero (ZF=1)
//@ 		cmp	al, 67h	; 'g'   ; Compare Two Operands
//@ 		jz	short loc_257FC	; Jump if Zero (ZF=1)
//@ 		cmp	al, 71h	; 'q'   ; Compare Two Operands
//@ 		jz	short loc_257FC	; Jump if Zero (ZF=1)
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jz	short loc_257FC	; Jump if Zero (ZF=1)
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		jnz	short loc_25847	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 1981
//@ 
//@ loc_257FC:				; CODE XREF: ShootMonster+261j
//@ 					; ShootMonster+265j ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_1C], di
//@ 		mov	word ptr [bp+var_1C+2],	es
//@ ; #line	"CSPUTL.PAS" 1982
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		les	di, [bp+var_1C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+1Eh]	; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	AddAmmoBag	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 1987
//@ 
//@ loc_25847:				; CODE XREF: ShootMonster+259j
//@ 					; ShootMonster+275j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+26h], 3	; Compare Two Operands
//@ 		jnz	short loc_25854	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25B75	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25854:				; CODE XREF: ShootMonster+2CAj
//@ 		cmp	byte ptr es:[di+26h], 4	; Compare Two Operands
//@ 		jnz	short loc_2585E	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25B75	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2585E:				; CODE XREF: ShootMonster+2D4j
//@ 		cmp	word ptr es:[di+8], 0Eh	; Compare Two Operands
//@ 		jnz	short loc_25868	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25B75	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25868:				; CODE XREF: ShootMonster+2DEj
//@ 		mov	ax, [bp+$bp]	; int16_t
//@ 		cmp	ax, [bp+sl]	; int16_t
//@ 		jg	short loc_25888	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, [bp+ms]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, takt	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jb	short loc_25888	; Jump if Below	(CF=1)
//@ 		jmp	loc_25B75	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 1993
//@ 
//@ loc_25888:				; CODE XREF: ShootMonster+2E9j
//@ 					; ShootMonster+2FEj
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 9 ;	Compare	Two Operands
//@ 		jz	short loc_258F5	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+8], 0Ah	; Compare Two Operands
//@ 		jz	short loc_258F5	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1995
//@ 		mov	word ptr es:[di+8], 9
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 1996
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_258BA	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+sl]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		cmp	ax, [bp+$bp]	; int16_t
//@ 		jge	short loc_258F5	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 1998
//@ 
//@ loc_258BA:				; CODE XREF: ShootMonster+329j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di-8000h]
//@ 		or	ax, [di-7FFEh]	; Logical Inclusive OR
//@ 		jz	short loc_258F5	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 1999
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 		mov	word ptr es:[di+8], 0Ah
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0BCh ; '¼'  ; Add
//@ 		mov	[bp+sfx], ax	; int16_t
//@ 		mov	word ptr es:[di+1Ch], 0FFFFh
//@ ; #line	"CSPUTL.PAS" 2002
//@ 
//@ loc_258F5:				; CODE XREF: ShootMonster+30Bj
//@ 					; ShootMonster+312j ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPUTL.PAS" 2003
//@ 		mov	ax, [bp+$bp]	; int16_t
//@ 		cmp	ax, [bp+sl]	; int16_t
//@ 		jg	short loc_25913	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_25AB6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25913:				; CODE XREF: ShootMonster+389j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+20h]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, 80h	; '€'   ; Integer Subtraction
//@ 		add	ax, dx		; Add
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jl	short loc_25931	; Jump if Less (SF!=OF)
//@ 		jmp	loc_25AB6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25931:				; CODE XREF: ShootMonster+3A7j
//@ 		mov	ax, es:[di+20h]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		sub	ax, 1C0h	; Integer Subtraction
//@ 		add	ax, dx		; Add
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jg	short loc_2594A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_25AB6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2004
//@ 
//@ loc_2594A:				; CODE XREF: ShootMonster+3C0j
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 3		; Logical AND
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_25957	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25AB6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2006
//@ 
//@ loc_25957:				; CODE XREF: ShootMonster+3CDj
//@ 		cmp	[bp+sl], 14h	; int16_t
//@ 		jle	short loc_25961	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	[bp+$bp], 0Ah	; int16_t
//@ ; #line	"CSPUTL.PAS" 2007
//@ 
//@ loc_25961:				; CODE XREF: ShootMonster+3D6j
//@ 		mov	ax, [bp+rx]	; int16_t
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		mov	[bp+_rx], ax	; int16_t
//@ 		mov	ax, [bp+ry]	; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		mov	[bp+_ry], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2008
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+sa], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2009
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+4]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+ca], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2011
//@ 		mov	ax, [bp+_ry]	; int16_t
//@ 		mul	[bp+sa]		; int16_t
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+_rx]	; int16_t
//@ 		mul	[bp+ca]		; int16_t
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	[bp+rrx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2012
//@ 		mov	ax, [bp+_rx]	; int16_t
//@ 		mul	[bp+sa]		; int16_t
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+_ry]	; int16_t
//@ 		mul	[bp+ca]		; int16_t
//@ 		add	ax, cx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	[bp+rry], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2015
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_25A48	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2016
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di-7FFCh]
//@ 		or	ax, [di-7FFAh]	; Logical Inclusive OR
//@ 		jz	short loc_25A48	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2017
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		cmp	ax, [bp+rry]	; int16_t
//@ 		jle	short loc_25A48	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2019
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Bh], 2	; Add
//@ 		mov	word ptr es:[di+8], 0Bh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 2020
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0D2h ; 'Ò'  ; Add
//@ 		mov	[bp+sfx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2021
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+$bp]	; int16_t
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	0
//@ 		push	word ptr es:[di+4]
//@ 		push	0
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2025
//@ 
//@ loc_25A48:				; CODE XREF: ShootMonster+461j
//@ 					; ShootMonster+475j ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_25AB6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2026
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di-7FF8h]
//@ 		or	ax, [di-7FF6h]	; Logical Inclusive OR
//@ 		jz	short loc_25AB6	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2027
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, [bp+rry]	; int16_t
//@ 		jle	short loc_25AB6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2029
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		inc	byte ptr es:[di+0Bh] ; Increment by 1
//@ 		mov	word ptr es:[di+8], 0Ch
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 2030
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0D2h ; 'Ò'  ; Add
//@ 		mov	[bp+sfx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2031
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+$bp]	; int16_t
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	1
//@ 		push	word ptr es:[di+4]
//@ 		push	0
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2036
//@ 
//@ loc_25AB6:				; CODE XREF: ShootMonster+38Bj
//@ 					; ShootMonster+3A9j ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_25AC6	; Jump if Zero (ZF=1)
//@ 		jmp	loc_25B55	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2037
//@ 
//@ loc_25AC6:				; CODE XREF: ShootMonster+53Cj
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di-7FF4h]
//@ 		or	ax, [di-7FF2h]	; Logical Inclusive OR
//@ 		jz	short loc_25B55	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2038
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	12h	; Signed Multiply
//@ 		mov	ax, [di-2FB6h]
//@ 		or	ax, [di-2FB4h]	; Logical Inclusive OR
//@ 		jz	short loc_25B55	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2039
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		sub	ax, 180h	; Integer Subtraction
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jge	short loc_25B55	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		sub	ax, 0C0h ; 'À'  ; Integer Subtraction
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jle	short loc_25B55	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2041
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Bh], 4	; Add
//@ 		mov	word ptr es:[di+8], 0Dh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 2042
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0D2h ; 'Ò'  ; Add
//@ 		mov	[bp+sfx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2043
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+$bp]	; int16_t
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	2
//@ 		push	word ptr es:[di+4]
//@ 		push	0
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2046
//@ 
//@ loc_25B55:				; CODE XREF: ShootMonster+53Ej
//@ 					; ShootMonster+553j ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+26h], 4
//@ ; #line	"CSPUTL.PAS" 2047
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		mov	byte ptr es:[di+24h], 0
//@ ; #line	"CSPUTL.PAS" 2048
//@ 		cmp	[bp+o],	8	; int16_t
//@ 		jge	short loc_25B75	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSPUTL.PAS" 2052
//@ 
//@ loc_25B75:				; CODE XREF: ShootMonster+2CCj
//@ 					; ShootMonster+2D6j ...
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_25BE9	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSPUTL.PAS" 2053
//@ 		cmp	byte ptr es:[di+0Ah], 66h ; 'f' ; Compare Two Operands
//@ 		jz	short loc_25BE9	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2054
//@ 		cmp	byte ptr es:[di+0Ah], 6Ch ; 'l' ; Compare Two Operands
//@ 		jz	short loc_25BE9	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2055
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_25BE9	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2056
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	12h	; Signed Multiply
//@ 		mov	ax, [di-2FB6h]
//@ 		or	ax, [di-2FB4h]	; Logical Inclusive OR
//@ 		jz	short loc_25BE9	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2057
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		sub	ax, 340h	; Integer Subtraction
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jge	short loc_25BE9	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2059
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Bh], 4	; Add
//@ ; #line	"CSPUTL.PAS" 2060
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+$bp]	; int16_t
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	2
//@ 		push	word ptr es:[di+4]
//@ 		push	0
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2064
//@ 
//@ loc_25BE9:				; CODE XREF: ShootMonster+5F8j
//@ 					; ShootMonster+5FFj ...
//@ 		cmp	[bp+sfx], 0	; int16_t
//@ 		jle	short loc_25C0A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_25C0A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+sfx]	; int16_t
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2066
//@ 
//@ loc_25C0A:				; CODE XREF: ShootMonster+668j
//@ 					; ShootMonster+672j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+1Ch], 0FFFFh ; Compare Two Operands
//@ 		jnz	short loc_25C79	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2067
//@ 		mov	ax, [bp+$bp]	; int16_t
//@ 		cmp	ax, [bp+sl]	; int16_t
//@ 		jle	short loc_25C70	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2069
//@ 		mov	ax, [bp+rx]	; int16_t
//@ 		sub	ax, [bp+_rvx]	; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+ry]	; int16_t
//@ 		sub	ax, [bp+_rvy]	; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CSPUTL.PAS" 2070
//@ 		cmp	word ptr es:[di+1Ah], 0	; Compare Two Operands
//@ 		jge	short loc_25C4C	; Jump if Greater or Equal (SF=OF)
//@ 		add	word ptr es:[di+1Ah], 400h ; Add
//@ 		jmp	short loc_25C5A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25C4C:				; CODE XREF: ShootMonster+6BDj
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CSPUTL.PAS" 2071
//@ 
//@ loc_25C5A:				; CODE XREF: ShootMonster+6C5j
//@ 		mov	ax, [bp+$bp]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+sl]		; int16_t
//@ 		add	ax, 6		; Add
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSPUTL.PAS" 2072
//@ 		jmp	short loc_25C79	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25C70:				; CODE XREF: ShootMonster+695j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSPUTL.PAS" 2075
//@ 
//@ loc_25C79:				; CODE XREF: ShootMonster+68Dj
//@ 					; ShootMonster+6E9j
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_25C86	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_25D06	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25C86:				; CODE XREF: ShootMonster+6FCj
//@ 		cmp	byte ptr es:[di+26h], 5	; Compare Two Operands
//@ 		jz	short locret_25D06 ; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2077
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		mov	byte ptr es:[di+26h], 5
//@ ; #line	"CSPUTL.PAS" 2078
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		cmp	ax, 14h		; Compare Two Operands
//@ 		jbe	short locret_25D06 ; Jump if Below or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 2079
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di-7FE4h]
//@ 		or	ax, [di-7FE2h]	; Logical Inclusive OR
//@ 		jz	short locret_25D06 ; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2081
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0E8h ; 'è'  ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2082
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 11h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 2083
//@ 		mov	ax, es:[di+4]
//@ 		mov	es:[di+1Ah], ax
//@ 		mov	ax, [bp+$bp]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+sl]		; int16_t
//@ 		add	ax, 1Ch		; Add
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSPUTL.PAS" 2087
//@ 
//@ locret_25D06:				; CODE XREF: ShootMonster+43j
//@ 					; ShootMonster+4Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	12h		; Return Far from Procedure
//@ ShootMonster	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2097
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ CheckMonsterContact proc far		; CODE XREF: MoveRocket+120P
//@ 
//@ var_18		= dword	ptr -18h
//@ var_14		= word ptr -14h
//@ $bl		= byte ptr -11h		; uint8_t
//@ Hz		= word ptr -10h		; int16_t
//@ Lz		= word ptr -0Eh		; int16_t
//@ w		= word ptr -0Ch		; int16_t
//@ n		= word ptr -8		; int16_t
//@ ow		= word ptr -6		; int16_t
//@ sd		= word ptr -4		; int16_t
//@ CheckMonsterContact= byte ptr -1	; uint8_t
//@ p		= word ptr  6		; int16_t
//@ r		= word ptr  8		; int16_t
//@ rvy		= word ptr  0Ah		; int16_t
//@ rvx		= word ptr  0Ch		; int16_t
//@ o		= word ptr  0Eh		; int16_t
//@ rz		= word ptr  10h		; int16_t
//@ ry		= word ptr  12h		; int16_t
//@ rx		= word ptr  14h		; int16_t
//@ 
//@ 		enter	18h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2098
//@ 		mov	[bp+$bl], 0	; uint8_t
//@ ; #line	"CSPUTL.PAS" 2099
//@ 		cmp	[bp+o],	8	; int16_t
//@ 		jge	short loc_25D20	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		mov	[bp+ow], ax	; int16_t
//@ 		jmp	short loc_25D32	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25D20:				; CODE XREF: CheckMonsterContact+Cj
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		mov	al, [di-5AD8h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+ow], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2100
//@ 
//@ loc_25D32:				; CODE XREF: CheckMonsterContact+14j
//@ 		cmp	[bp+o],	8	; int16_t
//@ 		jge	short loc_25D3F	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+sd], 0FFh	; int16_t
//@ 		jmp	short loc_25D48	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25D3F:				; CODE XREF: CheckMonsterContact+2Cj
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	[bp+sd], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2101
//@ 
//@ loc_25D48:				; CODE XREF: CheckMonsterContact+33j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_14], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jle	short loc_25D59	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_25E41	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25D59:				; CODE XREF: CheckMonsterContact+4Aj
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_25D61	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25D5E:				; CODE XREF: CheckMonsterContact+134j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_25D61:				; CODE XREF: CheckMonsterContact+52j
//@ 		mov	ax, [bp+sd]	; int16_t
//@ 		cmp	ax, [bp+n]	; int16_t
//@ 		jnz	short loc_25D6C	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25E36	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2102
//@ 
//@ loc_25D6C:				; CODE XREF: CheckMonsterContact+5Dj
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_18], di
//@ 		mov	word ptr [bp+var_18+2],	es
//@ ; #line	"CSPUTL.PAS" 2103
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_25D86	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_25E36	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2105
//@ 
//@ loc_25D86:				; CODE XREF: CheckMonsterContact+77j
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FBCh]
//@ 		mov	[bp+w],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2106
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+w]	; int16_t
//@ 		jl	short loc_25DAD	; Jump if Less (SF!=OF)
//@ 		jmp	loc_25E36	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25DAD:				; CODE XREF: CheckMonsterContact+9Ej
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+w]	; int16_t
//@ 		jge	short loc_25E36	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2108
//@ 		lea	di, [bp+Lz]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+Hz]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+6]
//@ 		call	ScanLowHigh	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2109
//@ 		mov	ax, [bp+Lz]	; int16_t
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+1Eh]	; Add
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jge	short loc_25E36	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+Hz]	; int16_t
//@ 		add	ax, es:[di+1Eh]	; Add
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jle	short loc_25E36	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2111
//@ 		cmp	[bp+r],	0C8h ; 'È' ; int16_t
//@ 		jge	short loc_25E2C	; Jump if Greater or Equal (SF=OF)
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+ow]	; int16_t
//@ 		jz	short loc_25E2C	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2112
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		push	[bp+rvx]	; int16_t
//@ 		push	[bp+rvy]	; int16_t
//@ 		push	[bp+n]		; int16_t
//@ 		push	[bp+p]		; int16_t
//@ 		push	[bp+p]		; int16_t
//@ 		push	[bp+o]		; int16_t
//@ 		call	ShootMonster	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2113
//@ 
//@ loc_25E2C:				; CODE XREF: CheckMonsterContact+F5j
//@ 					; CheckMonsterContact+100j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		mov	[bp+$bl], 2	; uint8_t
//@ ; #line	"CSPUTL.PAS" 2116
//@ 
//@ loc_25E36:				; CODE XREF: CheckMonsterContact+5Fj
//@ 					; CheckMonsterContact+79j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jz	short loc_25E41	; Jump if Zero (ZF=1)
//@ 		jmp	loc_25D5E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2118
//@ 
//@ loc_25E41:				; CODE XREF: CheckMonsterContact+4Cj
//@ 					; CheckMonsterContact+132j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_25E4B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25E48:				; CODE XREF: CheckMonsterContact+203j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_25E4B:				; CODE XREF: CheckMonsterContact+13Cj
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		cmp	ax, [bp+n]	; int16_t
//@ 		jnz	short loc_25E56	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25F07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2119
//@ 
//@ loc_25E56:				; CODE XREF: CheckMonsterContact+147j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_18+2],	di
//@ 		mov	[bp+var_14], es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_25E6F	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_25F07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_25E6F:				; CODE XREF: CheckMonsterContact+160j
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_25E79	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_25F07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2120
//@ 
//@ loc_25E79:				; CODE XREF: CheckMonsterContact+16Aj
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 50h	; 'P'   ; Compare Two Operands
//@ 		jge	short loc_25F07	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2121
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 6C0h	; Add
//@ 		cmp	ax, [bp+rz]	; int16_t
//@ 		jle	short loc_25F07	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		cmp	ax, es:[di+0Eh]	; Compare Two Operands
//@ 		jle	short loc_25F07	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2122
//@ 		cmp	word ptr es:[di+52h], 0	; Compare Two Operands
//@ 		jle	short loc_25EC2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+$bl], 1Eh	; uint8_t
//@ 		jmp	short loc_25F07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2124
//@ 
//@ loc_25EC2:				; CODE XREF: CheckMonsterContact+1B0j
//@ 		mov	[bp+$bl], 3	; uint8_t
//@ ; #line	"CSPUTL.PAS" 2125
//@ 		cmp	[bp+r],	0C8h ; 'È' ; int16_t
//@ 		jge	short loc_25F07	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2127
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+p]		; int16_t
//@ 		push	[bp+n]		; int16_t
//@ 		push	[bp+o]		; int16_t
//@ 		call	ShootMe		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2128
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ch], ax
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CSPUTL.PAS" 2130
//@ 
//@ loc_25F07:				; CODE XREF: CheckMonsterContact+149j
//@ 					; CheckMonsterContact+162j ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jz	short loc_25F10	; Jump if Zero (ZF=1)
//@ 		jmp	loc_25E48	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2132
//@ 
//@ loc_25F10:				; CODE XREF: CheckMonsterContact+201j
//@ 		mov	al, [bp+$bl]	; uint8_t
//@ 		mov	[bp+CheckMonsterContact], al ; uint8_t
//@ ; #line	"CSPUTL.PAS" 2133
//@ 		mov	al, [bp+CheckMonsterContact] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	10h		; Return Far from Procedure
//@ CheckMonsterContact endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2141
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InsertObject	proc far		; CODE XREF: MapXY+F7P	MapXY+134P ...
//@ 
//@ var_1E		= dword	ptr -1Eh
//@ $dl		= word ptr -1Ah		; int16_t
//@ Fc		= word ptr -18h		; int16_t
//@ py2		= word ptr -16h		; int16_t
//@ px2		= word ptr -14h		; int16_t
//@ py1		= word ptr -12h		; int16_t
//@ px1		= word ptr -10h		; int16_t
//@ CurLen		= word ptr -0Eh		; int16_t
//@ L		= byte ptr -0Ch		; struct TLoc
//@ var_B		= byte ptr -0Bh
//@ var_9		= word ptr -9
//@ var_7		= word ptr -7
//@ var_5		= word ptr -5
//@ var_3		= word ptr -3
//@ MYY		= byte ptr  6		; uint8_t
//@ MXX		= byte ptr  8		; uint8_t
//@ Flag		= byte ptr  0Ah		; uint8_t
//@ arg_6		= dword	ptr  0Ch
//@ 
//@ 		enter	1Eh, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		lds	si, [bp+arg_6]	; Load Full Pointer to DS:xx
//@ 		mov	cx, 0Bh
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPUTL.PAS" 2142
//@ 		cmp	FCount$0, 186h	; uint16_t
//@ 		jbe	short loc_25F40	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_26425	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2145
//@ 
//@ loc_25F40:				; CODE XREF: InsertObject+1Ej
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ 		mov	[bp+px1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2146
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ 		mov	[bp+py1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2147
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, [bp+var_5]	; Integer Subtraction
//@ 		mov	[bp+px2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2148
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, [bp+var_3]	; Integer Subtraction
//@ 		mov	[bp+py2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2150
//@ 		cmp	[bp+L],	78h ; 'x' ; struct TLoc
//@ 		jnb	short loc_25FA0	; Jump if Not Below (CF=0)
//@ 		mov	al, [bp+L]	; struct TLoc
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_25FA0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2151
//@ 		mov	ax, [bp+px2]	; int16_t
//@ 		sub	ax, [bp+px1]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+py2]	; int16_t
//@ 		sub	ax, [bp+py1]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+px1]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		mov	ax, [bp+py1]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		push	ax
//@ 		call	MulVectors$1	; function near	PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jnz	short loc_25FA0	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_26425	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2153
//@ 
//@ loc_25FA0:				; CODE XREF: InsertObject+4Bj
//@ 					; InsertObject+5Cj ...
//@ 		cmp	[bp+L],	7Ah ; 'z' ; struct TLoc
//@ 		jnz	short loc_26022	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2154
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPUTL.PAS" 2155
//@ 		cmp	word ptr es:[di+0Eh], 0	; Compare Two Operands
//@ 		jle	short loc_26022	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2156
//@ 		cmp	byte ptr es:[di+16h], 0	; Compare Two Operands
//@ 		jnz	short loc_25FCF	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+20h]
//@ 		or	ax, es:[di+22h]	; Logical Inclusive OR
//@ 		jnz	short loc_26022	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2158
//@ 
//@ loc_25FCF:				; CODE XREF: InsertObject+A6j
//@ 		mov	ax, [bp+px1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+py1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	R$1, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2159
//@ 		cmp	R$1, 400h	; int16_t
//@ 		jge	short loc_26022	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2160
//@ 		cmp	ObjAmb.Ambid, 0FFFFh ; struct ObjAmb$Type
//@ 		jz	short loc_25FFE	; Jump if Zero (ZF=1)
//@ 		mov	ax, R$1		; int16_t
//@ 		cmp	ax, ObjAmb.R	; struct ObjAmb$Type
//@ 		jge	short loc_26022	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2162
//@ 
//@ loc_25FFE:				; CODE XREF: InsertObject+D6j
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74BCh]
//@ 		mov	ObjAmb.Ambid, ax ; struct ObjAmb$Type
//@ ; #line	"CSPUTL.PAS" 2163
//@ 		mov	ax, [bp+var_9]
//@ 		mov	ObjAmb.osx, ax	; struct ObjAmb$Type
//@ ; #line	"CSPUTL.PAS" 2164
//@ 		mov	ax, [bp+var_7]
//@ 		mov	ObjAmb.osy, ax	; struct ObjAmb$Type
//@ ; #line	"CSPUTL.PAS" 2165
//@ 		mov	ax, R$1		; int16_t
//@ 		mov	ObjAmb.R, ax	; struct ObjAmb$Type
//@ ; #line	"CSPUTL.PAS" 2171
//@ 
//@ loc_26022:				; CODE XREF: InsertObject+87j
//@ 					; InsertObject+9Fj ...
//@ 		mov	ax, [bp+py1]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"CSPUTL.PAS" 2172
//@ 		mov	ax, [bp+px1]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		add	bx, ax		; Add
//@ 		adc	cx, dx		; Add with Carry
//@ ; #line	"CSPUTL.PAS" 2173
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		sub	bx, 40h	; '@'   ; Integer Subtraction
//@ 		mov	ty1$0, bx	; int16_t
//@ ; #line	"CSPUTL.PAS" 2175
//@ 		mov	ax, [bp+px1]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"CSPUTL.PAS" 2176
//@ 		mov	ax, [bp+py1]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		sbb	cx, dx		; Integer Subtraction with Borrow
//@ ; #line	"CSPUTL.PAS" 2177
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		mov	tx1$0, bx	; int16_t
//@ ; #line	"CSPUTL.PAS" 2180
//@ 		cmp	[bp+L],	78h ; 'x' ; struct TLoc
//@ 		jbe	short loc_260A7	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 2181
//@ 		cmp	[bp+L],	7Ah ; 'z' ; struct TLoc
//@ 		jnz	short loc_26090	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, tx1$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, ty1$0	; int16_t
//@ 		add	ax, 320h	; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_2608E	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_26425	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2608E:				; CODE XREF: InsertObject+16Cj
//@ 		jmp	short loc_260A7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2182
//@ 
//@ loc_26090:				; CODE XREF: InsertObject+156j
//@ 		mov	ax, tx1$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	dx, ax
//@ 		mov	ax, ty1$0	; int16_t
//@ 		add	ax, 400h	; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_260A7	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_26425	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2185
//@ 
//@ loc_260A7:				; CODE XREF: InsertObject+150j
//@ 					; InsertObject:loc_2608Ej ...
//@ 		cmp	[bp+L],	78h ; 'x' ; struct TLoc
//@ 		jbe	short loc_260B0	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2612D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2188
//@ 
//@ loc_260B0:				; CODE XREF: InsertObject+18Ej
//@ 		mov	ax, [bp+py2]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"CSPUTL.PAS" 2189
//@ 		mov	ax, [bp+px2]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		add	bx, ax		; Add
//@ 		adc	cx, dx		; Add with Carry
//@ ; #line	"CSPUTL.PAS" 2190
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		sub	bx, 40h	; '@'   ; Integer Subtraction
//@ 		mov	ty2$0, bx	; int16_t
//@ ; #line	"CSPUTL.PAS" 2192
//@ 		mov	ax, [bp+px2]	; int16_t
//@ 		imul	ica		; int16_t
//@ 		mov	bx, ax
//@ 		mov	cx, dx
//@ ; #line	"CSPUTL.PAS" 2193
//@ 		mov	ax, [bp+py2]	; int16_t
//@ 		imul	isa		; int16_t
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		sbb	cx, dx		; Integer Subtraction with Borrow
//@ ; #line	"CSPUTL.PAS" 2194
//@ 		shr	bx, 0Ah		; Shift	Logical	Right
//@ 		shl	cx, 6		; Shift	Logical	Left
//@ 		or	bx, cx		; Logical Inclusive OR
//@ 		mov	tx2$0, bx	; int16_t
//@ ; #line	"CSPUTL.PAS" 2196
//@ 		push	ty1$0		; int16_t
//@ 		push	ty2$0		; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jge	short loc_2610B	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_26425	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2197
//@ 
//@ loc_2610B:				; CODE XREF: InsertObject+1E9j
//@ 		mov	ax, tx1$0	; int16_t
//@ 		add	ax, tx2$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	dx, ax
//@ 		mov	ax, ty1$0	; int16_t
//@ 		add	ax, ty2$0	; int16_t
//@ 		add	ax, 800h	; Add
//@ 		add	ax, 400h	; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_2612D	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_26425	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2201
//@ 
//@ loc_2612D:				; CODE XREF: InsertObject+190j
//@ 					; InsertObject+20Bj
//@ 		inc	FCount$0	; uint16_t
//@ ; #line	"CSPUTL.PAS" 2202
//@ 		mov	ax, FCount$0	; uint16_t
//@ 		mov	[bp+Fc], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2203
//@ 		mov	[bp+$dl], 190h	; int16_t
//@ ; #line	"CSPUTL.PAS" 2205
//@ 		cmp	[bp+L],	78h ; 'x' ; struct TLoc
//@ 		ja	short loc_26171	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 2206
//@ 		mov	ax, ty1$0	; int16_t
//@ 		add	ax, ty2$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		mov	ax, tx1$0	; int16_t
//@ 		add	ax, tx2$0	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		add	ax, 28h	; '('   ; Add
//@ 		mov	[bp+CurLen], ax	; int16_t
//@ 		jmp	loc_26312	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2210
//@ 
//@ loc_26171:				; CODE XREF: InsertObject+223j
//@ 		push	ty1$0		; int16_t
//@ 		push	tx1$0		; int16_t
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+CurLen], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2211
//@ 		cmp	[bp+L],	7Fh ; '' ; struct TLoc
//@ 		jnz	short loc_2619D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2212
//@ 		mov	al, [bp+Flag]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	3Ah	; Signed Multiply
//@ 		mov	al, [di-2966h]
//@ 		and	al, 20h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_2619D	; Jump if Zero (ZF=1)
//@ 		sub	[bp+CurLen], 78h ; 'x' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2214
//@ 
//@ loc_2619D:				; CODE XREF: InsertObject+268j
//@ 					; InsertObject+27Aj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 2216
//@ 		cmp	[bp+L],	7Bh ; '{' ; struct TLoc
//@ 		jnz	short loc_261FB	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+var_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_1E], di
//@ 		mov	word ptr [bp+var_1E+2],	es
//@ ; #line	"CSPUTL.PAS" 2217
//@ 		cmp	word ptr es:[di+1Eh], 8C0h ; Compare Two Operands
//@ 		jle	short loc_261D1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	w, 1		; uint16_t
//@ 		mov	[bp+$dl], 320h	; int16_t
//@ 		jmp	short loc_261FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2218
//@ 
//@ loc_261D1:				; CODE XREF: InsertObject+2A5j
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+1Eh], 0	; Compare Two Operands
//@ 		jle	short loc_261EC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+1Eh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	w, ax		; uint16_t
//@ 		mov	[bp+$dl], 190h	; int16_t
//@ 		jmp	short loc_261FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2219
//@ 
//@ loc_261EC:				; CODE XREF: InsertObject+2BCj
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jnz	short loc_261FB	; Jump if Not Zero (ZF=0)
//@ 		add	[bp+CurLen], 80h ; '€' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2221
//@ 
//@ loc_261FB:				; CODE XREF: InsertObject+289j
//@ 					; InsertObject+2B2j ...
//@ 		cmp	[bp+L],	7Ah ; 'z' ; struct TLoc
//@ 		jnz	short loc_26225	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+MYY]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 0Bh		; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	al, [bp+MXX]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 2C0h	; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 2223
//@ 
//@ loc_26225:				; CODE XREF: InsertObject+2E2j
//@ 		cmp	[bp+L],	79h ; 'y' ; struct TLoc
//@ 		jnz	short loc_2624F	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+MYY]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 0Bh		; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	al, [bp+MXX]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 2C0h	; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 2225
//@ 
//@ loc_2624F:				; CODE XREF: InsertObject+30Cj
//@ 		cmp	[bp+L],	80h ; '€' ; struct TLoc
//@ 		jnz	short loc_2626D	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+var_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 1Fh		; Signed Multiply
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di-17h]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 2227
//@ 
//@ loc_2626D:				; CODE XREF: InsertObject+336j
//@ 		cmp	[bp+L],	7Dh ; '}' ; struct TLoc
//@ 		jnz	short loc_26285	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+var_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0Ah	; Signed Multiply
//@ 		mov	ax, [di-43EEh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 2229
//@ 
//@ loc_26285:				; CODE XREF: InsertObject+354j
//@ 		cmp	[bp+L],	81h ; '' ; struct TLoc
//@ 		jnz	short loc_2629D	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+var_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	58h	; Signed Multiply
//@ 		mov	ax, [di-0FC8h]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 2231
//@ 
//@ loc_2629D:				; CODE XREF: InsertObject+36Cj
//@ 		cmp	[bp+L],	7Eh ; '~' ; struct TLoc
//@ 		jnz	short loc_262B5	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+var_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	16h	; Signed Multiply
//@ 		mov	ax, [di-46B4h]
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSPUTL.PAS" 2233
//@ 
//@ loc_262B5:				; CODE XREF: InsertObject+384j
//@ 		cmp	w, 0		; uint16_t
//@ 		jbe	short loc_26312	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 2234
//@ 		cmp	[bp+L],	81h ; '' ; struct TLoc
//@ 		jnz	short loc_262EA	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, ehz		; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, w		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_262DC	; Jump if Less (SF!=OF)
//@ 		jg	short loc_262E3	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_262E3	; Jump if Not Below (CF=0)
//@ 
//@ loc_262DC:				; CODE XREF: InsertObject+3B7j
//@ 		sub	[bp+CurLen], 0C8h ; 'È' ; int16_t
//@ 		jmp	short loc_262E8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_262E3:				; CODE XREF: InsertObject+3B9j
//@ 					; InsertObject+3BDj
//@ 		add	[bp+CurLen], 0C8h ; 'È' ; int16_t
//@ 
//@ loc_262E8:				; CODE XREF: InsertObject+3C4j
//@ 		jmp	short loc_26312	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2235
//@ 
//@ loc_262EA:				; CODE XREF: InsertObject+3A3j
//@ 		mov	ax, ehz		; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, w		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_26304	; Jump if Less (SF!=OF)
//@ 		jg	short loc_2630C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_2630C	; Jump if Not Below (CF=0)
//@ 
//@ loc_26304:				; CODE XREF: InsertObject+3DFj
//@ 		mov	ax, [bp+$dl]	; int16_t
//@ 		sub	[bp+CurLen], ax	; int16_t
//@ 		jmp	short loc_26312	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2630C:				; CODE XREF: InsertObject+3E1j
//@ 					; InsertObject+3E5j
//@ 		mov	ax, [bp+$dl]	; int16_t
//@ 		add	[bp+CurLen], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2238
//@ 
//@ loc_26312:				; CODE XREF: InsertObject+251j
//@ 					; InsertObject+39Dj ...
//@ 		cmp	[bp+Fc], 1	; int16_t
//@ 		jle	short loc_26333	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+Fc]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	ax, 0Eh		; Signed Multiply
//@ 		les	di, FramesList	; TFrame*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di-6]
//@ 		cmp	ax, [bp+CurLen]	; int16_t
//@ 		jle	short loc_26333	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		dec	[bp+Fc]		; int16_t
//@ 		jmp	short loc_26312	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2240
//@ 
//@ loc_26333:				; CODE XREF: InsertObject+3F9j
//@ 					; InsertObject+40Fj
//@ 		mov	ax, FCount$0	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+Fc]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_26348	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_2638A	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2241
//@ 
//@ loc_26348:				; CODE XREF: InsertObject+425j
//@ 		imul	ax, [bp+Fc], 0Eh ; int16_t
//@ 		les	di, FramesList	; TFrame*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF2h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+Fc]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 0Eh		; Signed Multiply
//@ 		les	di, FramesList	; TFrame*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF2h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+Fc]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, FCount$0	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 0Eh
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	Movxb		; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2244
//@ 
//@ loc_2638A:				; CODE XREF: InsertObject+429j
//@ 		imul	ax, [bp+Fc], 0Eh ; int16_t
//@ 		les	di, FramesList	; TFrame*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF2h	; Add
//@ 		mov	word ptr [bp+var_1E], di
//@ 		mov	word ptr [bp+var_1E+2],	es
//@ ; #line	"CSPUTL.PAS" 2245
//@ 		cmp	[bp+L],	78h ; 'x' ; struct TLoc
//@ 		ja	short loc_263E4	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 2246
//@ 		mov	ax, tx1$0	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, ty1$0	; int16_t
//@ 		mov	es:[di+2], ax
//@ 		mov	ax, tx2$0	; int16_t
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, ty2$0	; int16_t
//@ 		mov	es:[di+6], ax
//@ 		mov	al, [bp+L]	; struct TLoc
//@ 		mov	es:[di+0Ah], al
//@ 		mov	al, [bp+Flag]	; uint8_t
//@ 		mov	es:[di+0Dh], al
//@ 		mov	al, [bp+MXX]	; uint8_t
//@ 		mov	es:[di+0Bh], al
//@ 		mov	al, [bp+MYY]	; uint8_t
//@ 		mov	es:[di+0Ch], al
//@ 		mov	ax, [bp+CurLen]	; int16_t
//@ 		mov	es:[di+8], ax
//@ 		jmp	short locret_26425 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2248
//@ 
//@ loc_263E4:				; CODE XREF: InsertObject+485j
//@ 		mov	ax, tx1$0	; int16_t
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	ax, ty1$0	; int16_t
//@ 		mov	es:[di+2], ax
//@ 		mov	ax, [bp+px2]	; int16_t
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, [bp+py2]	; int16_t
//@ 		mov	es:[di+6], ax
//@ 		mov	al, [bp+L]	; struct TLoc
//@ 		mov	es:[di+0Ah], al
//@ 		mov	al, [bp+var_B]
//@ 		mov	es:[di+0Dh], al
//@ 		mov	al, [bp+MXX]	; uint8_t
//@ 		mov	es:[di+0Bh], al
//@ 		mov	al, [bp+MYY]	; uint8_t
//@ 		mov	es:[di+0Ch], al
//@ 		mov	ax, [bp+CurLen]	; int16_t
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSPUTL.PAS" 2250
//@ 
//@ locret_26425:				; CODE XREF: InsertObject+20j
//@ 					; InsertObject+80j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ InsertObject	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2255
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InsertMonsters	proc far		; CODE XREF: DoGame+172CP
//@ 
//@ var_14		= dword	ptr -14h
//@ var_10		= word ptr -10h
//@ n		= word ptr -0Eh		; int16_t
//@ L		= byte ptr -0Ch		; struct TLoc
//@ var_B		= byte ptr -0Bh
//@ var_9		= word ptr -9
//@ var_7		= word ptr -7
//@ var_5		= word ptr -5
//@ var_3		= word ptr -3
//@ 
//@ 		enter	14h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2256
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WXSize,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2266
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jle	short loc_26443	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_264DE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26443:				; CODE XREF: InsertMonsters+15j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2644B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26448:				; CODE XREF: InsertMonsters+B2j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_2644B:				; CODE XREF: InsertMonsters+1Dj
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_14], di
//@ 		mov	word ptr [bp+var_14+2],	es
//@ 		cmp	byte ptr es:[di+0Bh], 0FFh ; Compare Two Operands
//@ 		jz	short loc_264D3	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2267
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_264D3	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_264D3	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2268
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_2649D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, ehx		; int16_t
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jnz	short loc_2649D	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, ehy		; int16_t
//@ 		cmp	ax, es:[di+2]	; Compare Two Operands
//@ 		jz	short loc_264D3	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2270
//@ 
//@ loc_2649D:				; CODE XREF: InsertMonsters+61j
//@ 					; InsertMonsters+69j
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+var_9], ax
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+var_7], ax
//@ 		mov	ax, [bp+var_9]
//@ 		mov	[bp+var_5], ax
//@ 		mov	ax, [bp+var_7]
//@ 		mov	[bp+var_3], ax
//@ 		mov	[bp+L],	7Bh ; '{' ; struct TLoc
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+var_B], al
//@ ; #line	"CSPUTL.PAS" 2271
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	InsertObject	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2272
//@ 
//@ loc_264D3:				; CODE XREF: InsertMonsters+37j
//@ 					; InsertMonsters+49j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jz	short loc_264DE	; Jump if Zero (ZF=1)
//@ 		jmp	loc_26448	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2274
//@ 
//@ loc_264DE:				; CODE XREF: InsertMonsters+17j
//@ 					; InsertMonsters+B0j
//@ 		mov	ax, MnCount	; uint16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jg	short loc_2655C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_264F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_264F1:				; CODE XREF: InsertMonsters+131j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_264F4:				; CODE XREF: InsertMonsters+C6j
//@ 		imul	di, [bp+n], 0Ah	; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPUTL.PAS" 2275
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_26554	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_26554	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2277
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+var_9], ax
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+var_7], ax
//@ 		mov	ax, [bp+var_9]
//@ 		mov	[bp+var_5], ax
//@ 		mov	ax, [bp+var_7]
//@ 		mov	[bp+var_3], ax
//@ 		mov	[bp+L],	7Dh ; '}' ; struct TLoc
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+var_B], al
//@ ; #line	"CSPUTL.PAS" 2278
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	InsertObject	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2279
//@ 
//@ loc_26554:				; CODE XREF: InsertMonsters+E5j
//@ 					; InsertMonsters+F6j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jnz	short loc_264F1	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2282
//@ 
//@ loc_2655C:				; CODE XREF: InsertMonsters+C1j
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jg	short loc_265DC	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_26572	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2656F:				; CODE XREF: InsertMonsters+1B1j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_26572:				; CODE XREF: InsertMonsters+144j
//@ 		imul	di, [bp+n], 18h	; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ ; #line	"CSPUTL.PAS" 2283
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+6]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_265D4	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_265D4	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2285
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+var_9], ax
//@ 		mov	ax, es:[di+6]
//@ 		mov	[bp+var_7], ax
//@ 		mov	ax, [bp+var_9]
//@ 		mov	[bp+var_5], ax
//@ 		mov	ax, [bp+var_7]
//@ 		mov	[bp+var_3], ax
//@ 		mov	[bp+L],	7Ch ; '|' ; struct TLoc
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+var_B], al
//@ ; #line	"CSPUTL.PAS" 2286
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	InsertObject	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2287
//@ 
//@ loc_265D4:				; CODE XREF: InsertMonsters+163j
//@ 					; InsertMonsters+175j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jnz	short loc_2656F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2289
//@ 
//@ loc_265DC:				; CODE XREF: InsertMonsters+13Fj
//@ 		mov	ax, SCount	; uint16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jg	short loc_2665C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_265F2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_265EF:				; CODE XREF: InsertMonsters+231j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_265F2:				; CODE XREF: InsertMonsters+1C4j
//@ 		imul	di, [bp+n], 16h	; int16_t
//@ 		add	di, 0B940h	; Add
//@ 		push	ds
//@ 		pop	es
//@ ; #line	"CSPUTL.PAS" 2290
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_26654	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, es:[di+8]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_26654	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2292
//@ 		mov	ax, es:[di+8]
//@ 		mov	[bp+var_9], ax
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	[bp+var_7], ax
//@ 		mov	ax, [bp+var_9]
//@ 		mov	[bp+var_5], ax
//@ 		mov	ax, [bp+var_7]
//@ 		mov	[bp+var_3], ax
//@ 		mov	[bp+L],	7Eh ; '~' ; struct TLoc
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+var_B], al
//@ ; #line	"CSPUTL.PAS" 2293
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	InsertObject	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2294
//@ 
//@ loc_26654:				; CODE XREF: InsertMonsters+1E3j
//@ 					; InsertMonsters+1F5j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jnz	short loc_265EF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2296
//@ 
//@ loc_2665C:				; CODE XREF: InsertMonsters+1BFj
//@ 		mov	ax, AmCount	; uint16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jg	short loc_266DE	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_26672	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2666F:				; CODE XREF: InsertMonsters+2B3j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_26672:				; CODE XREF: InsertMonsters+244j
//@ 		imul	ax, [bp+n], 1Fh	; int16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ ; #line	"CSPUTL.PAS" 2297
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_266D6	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_266D6	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2299
//@ 		mov	ax, es:[di]
//@ 		mov	[bp+var_9], ax
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+var_7], ax
//@ 		mov	ax, [bp+var_9]
//@ 		mov	[bp+var_5], ax
//@ 		mov	ax, [bp+var_7]
//@ 		mov	[bp+var_3], ax
//@ 		mov	[bp+L],	80h ; '€' ; struct TLoc
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+var_B], al
//@ ; #line	"CSPUTL.PAS" 2300
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	InsertObject	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2301
//@ 
//@ loc_266D6:				; CODE XREF: InsertMonsters+267j
//@ 					; InsertMonsters+278j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jnz	short loc_2666F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2303
//@ 
//@ loc_266DE:				; CODE XREF: InsertMonsters+23Fj
//@ 		mov	ax, BCount	; uint16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jle	short loc_266EF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_26773	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_266EF:				; CODE XREF: InsertMonsters+2C1j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_266F7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_266F4:				; CODE XREF: InsertMonsters+348j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_266F7:				; CODE XREF: InsertMonsters+2C9j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, BlowsList	; TBlow*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF0h	; Add
//@ 		mov	word ptr [bp+var_14], di
//@ 		mov	word ptr [bp+var_14+2],	es
//@ ; #line	"CSPUTL.PAS" 2304
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+6]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_2676B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, es:[di+4]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jge	short loc_2676B	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPUTL.PAS" 2306
//@ 		mov	ax, es:[di+4]
//@ 		mov	[bp+var_9], ax
//@ 		mov	ax, es:[di+6]
//@ 		mov	[bp+var_7], ax
//@ 		mov	ax, [bp+var_9]
//@ 		mov	[bp+var_5], ax
//@ 		mov	ax, [bp+var_7]
//@ 		mov	[bp+var_3], ax
//@ 		mov	[bp+L],	7Fh ; '' ; struct TLoc
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+var_B], al
//@ ; #line	"CSPUTL.PAS" 2307
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_14]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		call	InsertObject	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2308
//@ 
//@ loc_2676B:				; CODE XREF: InsertMonsters+2F4j
//@ 					; InsertMonsters+306j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jnz	short loc_266F4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2309
//@ 
//@ locret_26773:				; CODE XREF: InsertMonsters+2C3j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InsertMonsters	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2318
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SCalcBPoint	proc near		; CODE XREF: SendFastRocket+142p
//@ 					; SendFastRocket+28Cp ...
//@ 
//@ CC		= word ptr -36h		; real_t
//@ var_34		= word ptr -34h
//@ var_32		= word ptr -32h
//@ BB		= word ptr -30h		; real_t
//@ var_2E		= word ptr -2Eh
//@ var_2C		= word ptr -2Ch
//@ AA		= word ptr -2Ah		; real_t
//@ var_28		= word ptr -28h
//@ var_26		= word ptr -26h
//@ d		= word ptr -24h		; real_t
//@ var_22		= word ptr -22h
//@ var_20		= word ptr -20h
//@ c		= word ptr -1Eh		; real_t
//@ var_1C		= word ptr -1Ch
//@ var_1A		= word ptr -1Ah
//@ dy2		= word ptr -18h		; real_t
//@ var_16		= word ptr -16h
//@ var_14		= word ptr -14h
//@ dx2		= word ptr -12h		; real_t
//@ var_10		= word ptr -10h
//@ var_E		= word ptr -0Eh
//@ dy1		= word ptr -0Ch		; real_t
//@ var_A		= word ptr -0Ah
//@ var_8		= word ptr -8
//@ dx1		= word ptr -6		; real_t
//@ var_4		= word ptr -4
//@ var_2		= word ptr -2
//@ y4		= word ptr  4		; int16_t
//@ x4		= word ptr  6		; int16_t
//@ y3		= word ptr  8		; int16_t
//@ x3		= word ptr  0Ah		; int16_t
//@ y2		= word ptr  0Ch		; int16_t
//@ x2		= word ptr  0Eh		; int16_t
//@ y1		= word ptr  10h		; int16_t
//@ x1		= word ptr  12h		; int16_t
//@ 
//@ 		enter	36h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2319
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	[bp+dx1], ax	; real_t
//@ 		mov	[bp+var_4], bx
//@ 		mov	[bp+var_2], dx
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	[bp+dy1], ax	; real_t
//@ 		mov	[bp+var_A], bx
//@ 		mov	[bp+var_8], dx
//@ ; #line	"CSPUTL.PAS" 2320
//@ 		mov	ax, [bp+x4]	; int16_t
//@ 		sub	ax, [bp+x3]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	[bp+dx2], ax	; real_t
//@ 		mov	[bp+var_10], bx
//@ 		mov	[bp+var_E], dx
//@ 		mov	ax, [bp+y4]	; int16_t
//@ 		sub	ax, [bp+y3]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	[bp+dy2], ax	; real_t
//@ 		mov	[bp+var_16], bx
//@ 		mov	[bp+var_14], dx
//@ ; #line	"CSPUTL.PAS" 2322
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+dx1]	; real_t
//@ 		mov	si, [bp+var_4]
//@ 		mov	di, [bp+var_2]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+dy1]	; real_t
//@ 		mov	si, [bp+var_A]
//@ 		mov	di, [bp+var_8]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		mov	[bp+c],	ax	; real_t
//@ 		mov	[bp+var_1C], bx
//@ 		mov	[bp+var_1A], dx
//@ ; #line	"CSPUTL.PAS" 2323
//@ 		mov	ax, [bp+y3]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+dx2]	; real_t
//@ 		mov	si, [bp+var_10]
//@ 		mov	di, [bp+var_E]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+x3]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+dy2]	; real_t
//@ 		mov	si, [bp+var_16]
//@ 		mov	di, [bp+var_14]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		mov	[bp+d],	ax	; real_t
//@ 		mov	[bp+var_22], bx
//@ 		mov	[bp+var_20], dx
//@ ; #line	"CSPUTL.PAS" 2325
//@ 		mov	ax, [bp+dx1]	; real_t
//@ 		mov	bx, [bp+var_4]
//@ 		mov	dx, [bp+var_2]
//@ 		and	dh, 7Fh		; Logical AND
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+dy1]	; real_t
//@ 		mov	bx, [bp+var_A]
//@ 		mov	dx, [bp+var_8]
//@ 		and	dh, 7Fh		; Logical AND
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@__Cmp$q4Realt1	; Compare two reals
//@ 		ja	short loc_26879	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_26954	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2327
//@ 
//@ loc_26879:				; CODE XREF: SCalcBPoint+FFj
//@ 		mov	ax, [bp+dx1]	; real_t
//@ 		mov	bx, [bp+var_4]
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, [bp+dy2]	; real_t
//@ 		mov	si, [bp+var_16]
//@ 		mov	di, [bp+var_14]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, [bp+dy1]	; real_t
//@ 		mov	si, [bp+var_A]
//@ 		mov	di, [bp+var_8]
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+BB], ax	; real_t
//@ 		mov	[bp+var_2E], bx
//@ 		mov	[bp+var_2C], dx
//@ ; #line	"CSPUTL.PAS" 2328
//@ 		mov	ax, [bp+c]	; real_t
//@ 		mov	bx, [bp+var_1C]
//@ 		mov	dx, [bp+var_1A]
//@ 		mov	cx, [bp+dy2]	; real_t
//@ 		mov	si, [bp+var_16]
//@ 		mov	di, [bp+var_14]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, [bp+dy1]	; real_t
//@ 		mov	si, [bp+var_A]
//@ 		mov	di, [bp+var_8]
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+CC], ax	; real_t
//@ 		mov	[bp+var_34], bx
//@ 		mov	[bp+var_32], dx
//@ ; #line	"CSPUTL.PAS" 2329
//@ 		mov	ax, [bp+BB]	; real_t
//@ 		mov	bx, [bp+var_2E]
//@ 		mov	dx, [bp+var_2C]
//@ 		mov	cx, [bp+dx2]	; real_t
//@ 		mov	si, [bp+var_10]
//@ 		mov	di, [bp+var_E]
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+d]	; real_t
//@ 		mov	bx, [bp+var_22]
//@ 		mov	dx, [bp+var_20]
//@ 		mov	cx, [bp+CC]	; real_t
//@ 		mov	si, [bp+var_34]
//@ 		mov	di, [bp+var_32]
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	bpy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2330
//@ 		mov	ax, bpy		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+dx1]	; real_t
//@ 		mov	si, [bp+var_4]
//@ 		mov	di, [bp+var_2]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, [bp+c]	; real_t
//@ 		mov	si, [bp+var_1C]
//@ 		mov	di, [bp+var_1A]
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		mov	cx, [bp+dy1]	; real_t
//@ 		mov	si, [bp+var_A]
//@ 		mov	di, [bp+var_8]
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	bpx, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2331
//@ 		jmp	locret_26A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2333
//@ 
//@ loc_26954:				; CODE XREF: SCalcBPoint+101j
//@ 		mov	ax, [bp+dy1]	; real_t
//@ 		mov	bx, [bp+var_A]
//@ 		mov	dx, [bp+var_8]
//@ 		mov	cx, [bp+dx2]	; real_t
//@ 		mov	si, [bp+var_10]
//@ 		mov	di, [bp+var_E]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, [bp+dx1]	; real_t
//@ 		mov	si, [bp+var_4]
//@ 		mov	di, [bp+var_2]
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+AA], ax	; real_t
//@ 		mov	[bp+var_28], bx
//@ 		mov	[bp+var_26], dx
//@ ; #line	"CSPUTL.PAS" 2334
//@ 		mov	ax, [bp+c]	; real_t
//@ 		mov	bx, [bp+var_1C]
//@ 		mov	dx, [bp+var_1A]
//@ 		mov	cx, [bp+dx2]	; real_t
//@ 		mov	si, [bp+var_10]
//@ 		mov	di, [bp+var_E]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, [bp+dx1]	; real_t
//@ 		mov	si, [bp+var_4]
//@ 		mov	di, [bp+var_2]
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+CC], ax	; real_t
//@ 		mov	[bp+var_34], bx
//@ 		mov	[bp+var_32], dx
//@ ; #line	"CSPUTL.PAS" 2335
//@ 		mov	ax, [bp+AA]	; real_t
//@ 		mov	bx, [bp+var_28]
//@ 		mov	dx, [bp+var_26]
//@ 		mov	cx, [bp+dy2]	; real_t
//@ 		mov	si, [bp+var_16]
//@ 		mov	di, [bp+var_14]
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+CC]	; real_t
//@ 		mov	bx, [bp+var_34]
//@ 		mov	dx, [bp+var_32]
//@ 		mov	cx, [bp+d]	; real_t
//@ 		mov	si, [bp+var_22]
//@ 		mov	di, [bp+var_20]
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	bpx, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2336
//@ 		mov	ax, bpx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+dy1]	; real_t
//@ 		mov	si, [bp+var_A]
//@ 		mov	di, [bp+var_8]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, [bp+c]	; real_t
//@ 		mov	si, [bp+var_1C]
//@ 		mov	di, [bp+var_1A]
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		mov	cx, [bp+dx1]	; real_t
//@ 		mov	si, [bp+var_4]
//@ 		mov	di, [bp+var_2]
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	bpy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2338
//@ 
//@ locret_26A2C:				; CODE XREF: SCalcBPoint+1DCj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ SCalcBPoint	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2353
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddHole		proc far		; CODE XREF: SendFastRocket+AC0P
//@ 					; SendFastRocket+B17P
//@ 
//@ var_8		= dword	ptr -8
//@ var_4		= dword	ptr -4
//@ hz		= word ptr  6		; int16_t
//@ hy		= word ptr  8		; int16_t
//@ hx		= word ptr  0Ah		; int16_t
//@ my		= word ptr  0Ch		; int16_t
//@ mx		= word ptr  0Eh		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2354
//@ 		cmp	[bp+hz], 1000h	; int16_t
//@ 		jle	short loc_26A3E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_26B4E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2355
//@ 
//@ loc_26A3E:				; CODE XREF: AddHole+9j
//@ 		cmp	HolCount, 3Eh ;	'>' ; uint16_t
//@ 		jb	short loc_26A6E	; Jump if Below	(CF=1)
//@ ; #line	"CSPUTL.PAS" 2357
//@ 		les	di, HolesList	; THoleItem*
//@ 		push	es
//@ 		les	di, HolesList	; THoleItem*
//@ 		add	di, 14h		; Add
//@ 		push	di
//@ 		les	di, HolesList	; THoleItem*
//@ 		push	es
//@ 		les	di, HolesList	; THoleItem*
//@ 		push	di
//@ 		imul	ax, HolCount, 14h ; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		push	ax
//@ 		call	movsw		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2360
//@ 		dec	HolCount	; uint16_t
//@ ; #line	"CSPUTL.PAS" 2362
//@ 
//@ loc_26A6E:				; CODE XREF: AddHole+13j
//@ 		inc	HolCount	; uint16_t
//@ ; #line	"CSPUTL.PAS" 2363
//@ 		imul	ax, HolCount, 14h ; uint16_t
//@ 		les	di, HolesList	; THoleItem*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFECh	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPUTL.PAS" 2365
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPUTL.PAS" 2366
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSPUTL.PAS" 2367
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		mov	es:[di+0Ah], ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPUTL.PAS" 2369
//@ 		cmp	[bp+mx], 0FFFFh	; int16_t
//@ 		jz	short loc_26B17	; Jump if Zero (ZF=1)
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSPUTL.PAS" 2370
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+9]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+hx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+hy]	; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ 		mov	es:[di+10h], bx
//@ 		mov	es:[di+12h], dx
//@ ; #line	"CSPUTL.PAS" 2372
//@ 
//@ loc_26B17:				; CODE XREF: AddHole+75j
//@ 		cmp	[bp+mx], 0FFFFh	; int16_t
//@ 		jnz	short loc_26B37	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2373
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+8] ; Increment by 1
//@ 		cmp	[bp+hz], 800h	; int16_t
//@ 		jle	short loc_26B32	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+hz], 1000h	; int16_t
//@ 		jmp	short loc_26B37	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26B32:				; CODE XREF: AddHole+F9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+hz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2374
//@ 
//@ loc_26B37:				; CODE XREF: AddHole+EBj AddHole+100j
//@ 		mov	ax, [bp+hx]	; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+hy]	; int16_t
//@ 		mov	es:[di+2], ax
//@ 		mov	ax, [bp+hz]	; int16_t
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSPUTL.PAS" 2376
//@ 
//@ locret_26B4E:				; CODE XREF: AddHole+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ AddHole		endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2389
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ CalcRZ		proc near		; CODE XREF: SendFastRocket+180p
//@ 					; SendFastRocket+2CAp ...
//@ 
//@ CalcRZ		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ arg_8		= word ptr  0Ch
//@ arg_A		= word ptr  0Eh
//@ arg_C		= word ptr  10h
//@ arg_E		= word ptr  12h
//@ arg_10		= word ptr  14h
//@ arg_12		= word ptr  16h
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2390
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ss:[di+arg_8], 0 ; Compare Two Operands
//@ 		jnz	short loc_26B63	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_26C02	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2391
//@ 
//@ loc_26B63:				; CODE XREF: CalcRZ+Cj
//@ 		mov	ax, ss:[di+arg_A]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, ss:[di+arg_C]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jle	short loc_26BBD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, ss:[di+arg_C]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, ss:[di+arg_12] ; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, ss:[di+arg_8]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+arg_E]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+CalcRZ], ax	; int16_t
//@ 		jmp	short loc_26C00	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2392
//@ 
//@ loc_26BBD:				; CODE XREF: CalcRZ+27j
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+arg_A]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, ss:[di+arg_10] ; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, ss:[di+arg_8]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+arg_E]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+CalcRZ], ax	; int16_t
//@ 
//@ loc_26C00:				; CODE XREF: CalcRZ+69j
//@ 		jmp	short loc_26C0C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2393
//@ 
//@ loc_26C02:				; CODE XREF: CalcRZ+Ej
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+arg_E]
//@ 		mov	[bp+CalcRZ], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2394
//@ 
//@ loc_26C0C:				; CODE XREF: CalcRZ:loc_26C00j
//@ 		mov	ax, [bp+CalcRZ]	; int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ CalcRZ		endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2396
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SendFastRocket	proc far		; CODE XREF: DoGame+E72P DoGame+F72P ...
//@ 
//@ var_36		= dword	ptr -36h
//@ var_32		= dword	ptr -32h
//@ Water		= byte ptr -2Dh		; bool
//@ HighZ		= word ptr -2Ch		; int16_t
//@ LowZ		= word ptr -2Ah		; int16_t
//@ my2		= word ptr -28h		; int16_t
//@ my1		= word ptr -26h		; int16_t
//@ mx2		= word ptr -24h		; int16_t
//@ mx1		= word ptr -22h		; int16_t
//@ rry		= word ptr -20h		; int16_t
//@ rrx		= word ptr -1Eh		; int16_t
//@ my		= word ptr -1Ch		; int16_t
//@ mx		= word ptr -1Ah		; int16_t
//@ bz		= word ptr -18h		; int16_t
//@ oz		= word ptr -16h		; int16_t
//@ mdy		= word ptr -14h		; int16_t
//@ mdx		= word ptr -12h		; int16_t
//@ pdy		= word ptr -10h		; int16_t
//@ pdx		= word ptr -0Eh		; int16_t
//@ RP		= word ptr -0Ch		; int16_t
//@ RB		= word ptr -0Ah		; int16_t
//@ mn		= word ptr -8		; int16_t
//@ ms		= word ptr -6		; int16_t
//@ n		= word ptr -4		; int16_t
//@ pl		= word ptr -2		; int16_t
//@ scale		= word ptr  6		; int16_t
//@ OwId		= word ptr  8		; int16_t
//@ RType		= word ptr  0Ah		; int16_t
//@ vz		= word ptr  0Ch		; int16_t
//@ vy		= word ptr  0Eh		; int16_t
//@ vx		= word ptr  10h		; int16_t
//@ rz		= word ptr  12h		; int16_t
//@ ry		= word ptr  14h		; int16_t
//@ rx		= word ptr  16h		; int16_t
//@ 
//@ 		enter	36h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2397
//@ 		mov	[bp+mx], 0FFFFh	; int16_t
//@ 		mov	[bp+my], 0FFFFh	; int16_t
//@ ; #line	"CSPUTL.PAS" 2398
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ms], ax	; int16_t
//@ 		mov	[bp+pl], 0FFFFh	; int16_t
//@ 		mov	[bp+mn], 0FFFFh	; int16_t
//@ ; #line	"CSPUTL.PAS" 2399
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 200h
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+rx]	; int16_t
//@ 		mov	[bp+rx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2400
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 200h
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+ry]	; int16_t
//@ 		mov	[bp+ry], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2401
//@ 		mov	ax, [bp+rx]	; int16_t
//@ 		add	ax, [bp+vx]	; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2402
//@ 		mov	ax, [bp+ry]	; int16_t
//@ 		add	ax, [bp+vy]	; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2404
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+pdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2405
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+pdy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2406
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	bpx, ax		; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	bpy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2407
//@ 		imul	di, [bp+RType],	16h ; int16_t
//@ 		mov	ax, [di-327Ch]
//@ 		mov	[bp+RB], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2410
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	word ptr [bp+var_32+2],	ax
//@ 		mov	ax, 1
//@ 		cmp	ax, word ptr [bp+var_32+2] ; Compare Two Operands
//@ 		jle	short loc_26CA0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_26DF2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26CA0:				; CODE XREF: SendFastRocket+88j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_26CA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26CA5:				; CODE XREF: SendFastRocket+1DCj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPUTL.PAS" 2411
//@ 
//@ loc_26CA8:				; CODE XREF: SendFastRocket+90j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_36+2],	di
//@ 		mov	word ptr [bp+var_32], es
//@ ; #line	"CSPUTL.PAS" 2412
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_26CC2	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_26DE7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2414
//@ 
//@ loc_26CC2:				; CODE XREF: SendFastRocket+AAj
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FBCh]
//@ 		mov	[bp+mdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2415
//@ 		mov	ax, [bp+pdy]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2416
//@ 		mov	ax, [bp+pdx]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2417
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_36+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		call	Test2Vectors$0	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_26D28	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_26DE7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2419
//@ 
//@ loc_26D28:				; CODE XREF: SendFastRocket+110j
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_36+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		call	SCalcBPoint	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2420
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_26DE7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2422
//@ 		push	bp
//@ 		call	CalcRZ		; function nested near PASCAL returns signed int 'Integer'
//@ 		mov	[bp+bz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2423
//@ 		lea	di, [bp+LowZ]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+HighZ]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_36+2] ; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+6]
//@ 		call	ScanLowHigh	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2424
//@ 		mov	ax, [bp+LowZ]	; int16_t
//@ 		les	di, [bp+var_36+2] ; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+1Eh]	; Add
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jge	short loc_26DE7	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+HighZ]	; int16_t
//@ 		add	ax, es:[di+1Eh]	; Add
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jle	short loc_26DE7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2425
//@ 		mov	ax, bpx		; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, bpy		; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+ms], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2428
//@ 
//@ loc_26DE7:				; CODE XREF: SendFastRocket+ACj
//@ 					; SendFastRocket+112j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_32+2] ; Compare Two Operands
//@ 		jz	short loc_26DF2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_26CA5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2431
//@ 
//@ loc_26DF2:				; CODE XREF: SendFastRocket+8Aj
//@ 					; SendFastRocket+1DAj
//@ 		mov	ax, MnCount	; uint16_t
//@ 		mov	word ptr [bp+var_32+2],	ax
//@ 		mov	ax, 1
//@ 		cmp	ax, word ptr [bp+var_32+2] ; Compare Two Operands
//@ 		jle	short loc_26E03	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_26F20	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26E03:				; CODE XREF: SendFastRocket+1EBj
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_26E0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26E08:				; CODE XREF: SendFastRocket+30Aj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPUTL.PAS" 2432
//@ 
//@ loc_26E0B:				; CODE XREF: SendFastRocket+1F3j
//@ 		imul	di, [bp+n], 0Ah	; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_36+2],	di
//@ 		mov	word ptr [bp+var_32], es
//@ ; #line	"CSPUTL.PAS" 2434
//@ 		mov	[bp+mdx], 20h ;	' ' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2435
//@ 		mov	ax, [bp+pdy]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2436
//@ 		mov	ax, [bp+pdx]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2437
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		call	Test2Vectors$0	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_26E72	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_26F15	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2439
//@ 
//@ loc_26E72:				; CODE XREF: SendFastRocket+25Aj
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_36+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		call	SCalcBPoint	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2440
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_26F15	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2442
//@ 		push	bp
//@ 		call	CalcRZ		; function nested near PASCAL returns signed int 'Integer'
//@ 		mov	[bp+bz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2443
//@ 		les	di, [bp+var_36+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		sub	ax, 80h	; '€'   ; Integer Subtraction
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jge	short loc_26F15	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, 140h	; Add
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jle	short loc_26F15	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2444
//@ 		mov	ax, bpx		; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, bpy		; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+mn], ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ms], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2448
//@ 
//@ loc_26F15:				; CODE XREF: SendFastRocket+25Cj
//@ 					; SendFastRocket+2C7j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_32+2] ; Compare Two Operands
//@ 		jz	short loc_26F20	; Jump if Zero (ZF=1)
//@ 		jmp	loc_26E08	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2451
//@ 
//@ loc_26F20:				; CODE XREF: SendFastRocket+1EDj
//@ 					; SendFastRocket+308j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_26F2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26F27:				; CODE XREF: SendFastRocket+46Ej
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_26F2A:				; CODE XREF: SendFastRocket+312j
//@ 		mov	ax, [bp+OwId]	; int16_t
//@ 		cmp	ax, [bp+n]	; int16_t
//@ 		jnz	short loc_26F35	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2707B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2452
//@ 
//@ loc_26F35:				; CODE XREF: SendFastRocket+31Dj
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_32], di
//@ 		mov	word ptr [bp+var_32+2],	es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_26F4E	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2707B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_26F4E:				; CODE XREF: SendFastRocket+336j
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_26F58	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_2707B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2454
//@ 
//@ loc_26F58:				; CODE XREF: SendFastRocket+340j
//@ 		mov	ax, MonstersInfo.MWidth	; struct TMonsterInfo[23]
//@ 		mov	[bp+mdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2455
//@ 		mov	ax, [bp+pdy]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2456
//@ 		mov	ax, [bp+pdx]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2457
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		call	Test2Vectors$0	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_26FB2	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2707B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2459
//@ 
//@ loc_26FB2:				; CODE XREF: SendFastRocket+39Aj
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, [bp+pdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, [bp+pdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+pdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+pdy]	; int16_t
//@ 		push	ax
//@ 		call	SCalcBPoint	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2460
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_2707B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2462
//@ 		push	bp
//@ 		call	CalcRZ		; function nested near PASCAL returns signed int 'Integer'
//@ 		mov	[bp+bz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2463
//@ 		lea	di, [bp+LowZ]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+HighZ]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		push	64h ; 'd'
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+24h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	word ptr es:[di+22h]
//@ 		call	ScanLowHigh	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2464
//@ 		mov	ax, [bp+LowZ]	; int16_t
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+0Eh]	; Add
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jge	short loc_2707B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+HighZ]	; int16_t
//@ 		add	ax, es:[di+0Eh]	; Add
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jle	short loc_2707B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2465
//@ 		mov	ax, bpx		; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, bpy		; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+pl], ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ms], ax	; int16_t
//@ 		mov	[bp+mn], 0FFFFh	; int16_t
//@ ; #line	"CSPUTL.PAS" 2468
//@ 
//@ loc_2707B:				; CODE XREF: SendFastRocket+31Fj
//@ 					; SendFastRocket+338j ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jz	short loc_27084	; Jump if Zero (ZF=1)
//@ 		jmp	loc_26F27	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2471
//@ 
//@ loc_27084:				; CODE XREF: SendFastRocket+46Cj
//@ 		cmp	[bp+vx], 0	; int16_t
//@ 		jl	short loc_270B7	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2473
//@ 		mov	al, byte ptr [bp+rx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+mx1], ax	; int16_t
//@ 		cmp	[bp+mx1], 0	; int16_t
//@ 		jge	short loc_2709F	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+mx1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2474
//@ 
//@ loc_2709F:				; CODE XREF: SendFastRocket+485j
//@ 		cmp	[bp+mx1], 28h ;	'(' ; int16_t
//@ 		jle	short loc_270AC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+mx2], 3Fh ;	'?' ; int16_t
//@ 		jmp	short loc_270B5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_270AC:				; CODE XREF: SendFastRocket+490j
//@ 		mov	ax, [bp+mx1]	; int16_t
//@ 		add	ax, 17h		; Add
//@ 		mov	[bp+mx2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2475
//@ 
//@ loc_270B5:				; CODE XREF: SendFastRocket+497j
//@ 		jmp	short loc_270E2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2478
//@ 
//@ loc_270B7:				; CODE XREF: SendFastRocket+475j
//@ 		mov	al, byte ptr [bp+rx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+mx2], ax	; int16_t
//@ 		cmp	[bp+mx2], 3Fh ;	'?' ; int16_t
//@ 		jle	short loc_270CC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+mx2], 3Fh ;	'?' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2479
//@ 
//@ loc_270CC:				; CODE XREF: SendFastRocket+4B2j
//@ 		cmp	[bp+mx2], 17h	; int16_t
//@ 		jge	short loc_270D9	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+mx1], ax	; int16_t
//@ 		jmp	short loc_270E2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_270D9:				; CODE XREF: SendFastRocket+4BDj
//@ 		mov	ax, [bp+mx2]	; int16_t
//@ 		sub	ax, 17h		; Integer Subtraction
//@ 		mov	[bp+mx1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2482
//@ 
//@ loc_270E2:				; CODE XREF: SendFastRocket:loc_270B5j
//@ 					; SendFastRocket+4C4j
//@ 		cmp	[bp+vy], 0	; int16_t
//@ 		jl	short loc_27115	; Jump if Less (SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2484
//@ 		mov	al, byte ptr [bp+ry+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+my1], ax	; int16_t
//@ 		cmp	[bp+my1], 0	; int16_t
//@ 		jge	short loc_270FD	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+my1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2485
//@ 
//@ loc_270FD:				; CODE XREF: SendFastRocket+4E3j
//@ 		cmp	[bp+my1], 28h ;	'(' ; int16_t
//@ 		jle	short loc_2710A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+my2], 3Fh ;	'?' ; int16_t
//@ 		jmp	short loc_27113	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2710A:				; CODE XREF: SendFastRocket+4EEj
//@ 		mov	ax, [bp+my1]	; int16_t
//@ 		add	ax, 17h		; Add
//@ 		mov	[bp+my2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2486
//@ 
//@ loc_27113:				; CODE XREF: SendFastRocket+4F5j
//@ 		jmp	short loc_27140	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2489
//@ 
//@ loc_27115:				; CODE XREF: SendFastRocket+4D3j
//@ 		mov	al, byte ptr [bp+ry+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+my2], ax	; int16_t
//@ 		cmp	[bp+my2], 3Fh ;	'?' ; int16_t
//@ 		jle	short loc_2712A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+my2], 3Fh ;	'?' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2490
//@ 
//@ loc_2712A:				; CODE XREF: SendFastRocket+510j
//@ 		cmp	[bp+my2], 17h	; int16_t
//@ 		jge	short loc_27137	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+my1], ax	; int16_t
//@ 		jmp	short loc_27140	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27137:				; CODE XREF: SendFastRocket+51Bj
//@ 		mov	ax, [bp+my2]	; int16_t
//@ 		sub	ax, 17h		; Integer Subtraction
//@ 		mov	[bp+my1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2498
//@ 
//@ loc_27140:				; CODE XREF: SendFastRocket:loc_27113j
//@ 					; SendFastRocket+522j
//@ 		mov	ax, [bp+mx2]	; int16_t
//@ 		mov	word ptr [bp+var_32+2],	ax
//@ 		mov	ax, [bp+mx1]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_32+2] ; Compare Two Operands
//@ 		jle	short loc_27151	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_27446	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27151:				; CODE XREF: SendFastRocket+539j
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_2715A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27156:				; CODE XREF: SendFastRocket+830j
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSPUTL.PAS" 2499
//@ 
//@ loc_2715A:				; CODE XREF: SendFastRocket+541j
//@ 		mov	ax, [bp+my2]	; int16_t
//@ 		mov	word ptr [bp+var_32], ax
//@ 		mov	ax, [bp+my1]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_32] ; Compare Two Operands
//@ 		jle	short loc_2716B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_2743B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2716B:				; CODE XREF: SendFastRocket+553j
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_27174	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27170:				; CODE XREF: SendFastRocket+825j
//@ 		inc	y		; int16_t
//@ ; #line	"CSPUTL.PAS" 2500
//@ 
//@ loc_27174:				; CODE XREF: SendFastRocket+55Bj
//@ 		imul	ax, y, 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, x$0, 2C0h	; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_36], di
//@ 		mov	word ptr [bp+var_36+2],	es
//@ ; #line	"CSPUTL.PAS" 2501
//@ 		mov	al, es:[di]
//@ ; #line	"CSPUTL.PAS" 2502
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnb	short loc_27199	; Jump if Not Below (CF=0)
//@ 		jmp	loc_27279	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27199:				; CODE XREF: SendFastRocket+581j
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jbe	short loc_271A0	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_27279	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2503
//@ 
//@ loc_271A0:				; CODE XREF: SendFastRocket+588j
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_271B4	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_27276	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_271B4:				; CODE XREF: SendFastRocket+59Cj
//@ 		mov	dx, y		; int16_t
//@ 		mov	ax, x$0		; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 3Ch ;	'<' ; Compare Two Operands
//@ 		jb	short loc_271CF	; Jump if Below	(CF=1)
//@ 		jmp	loc_27276	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2504
//@ 
//@ loc_271CF:				; CODE XREF: SendFastRocket+5B7j
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+7]
//@ 		push	word ptr es:[di+9]
//@ 		call	Test2Vectors$0	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_271F8	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_27276	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2506
//@ 
//@ loc_271F8:				; CODE XREF: SendFastRocket+5E0j
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+7]
//@ 		push	word ptr es:[di+9]
//@ 		call	SCalcBPoint	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2507
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_27276	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2509
//@ 		mov	ax, bpx		; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, bpy		; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		mov	ax, x$0		; int16_t
//@ 		mov	[bp+mx], ax	; int16_t
//@ 		mov	ax, y		; int16_t
//@ 		mov	[bp+my], ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ms], ax	; int16_t
//@ 		mov	[bp+pl], 0FFFFh	; int16_t
//@ ; #line	"CSPUTL.PAS" 2510
//@ 
//@ loc_27276:				; CODE XREF: SendFastRocket+59Ej
//@ 					; SendFastRocket+5B9j ...
//@ 		jmp	loc_27430	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2511
//@ 
//@ loc_27279:				; CODE XREF: SendFastRocket+583j
//@ 					; SendFastRocket+58Aj
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnb	short loc_27280	; Jump if Not Below (CF=0)
//@ 		jmp	loc_27430	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27280:				; CODE XREF: SendFastRocket+668j
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_27287	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_27430	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27287:				; CODE XREF: SendFastRocket+66Fj
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74AEh], 0 ; Compare Two Operands
//@ 		jg	short loc_2729F	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_27430	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2513
//@ 
//@ loc_2729F:				; CODE XREF: SendFastRocket+687j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74AEh]
//@ 		mov	[bp+mdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2514
//@ 		mov	ax, [bp+pdy]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdy], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2515
//@ 		mov	ax, [bp+pdx]	; int16_t
//@ 		mul	[bp+mdx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+mdx], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2516
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		add	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		add	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		call	Test2Vectors$0	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_2730B	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_27430	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2518
//@ 
//@ loc_2730B:				; CODE XREF: SendFastRocket+6F3j
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		add	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		add	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+mdx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+mdy]	; int16_t
//@ 		push	ax
//@ 		call	SCalcBPoint	; function near	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2519
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jg	short loc_2737A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_27430	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2521
//@ 
//@ loc_2737A:				; CODE XREF: SendFastRocket+762j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	al, [di+74AEh]
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_273B9	; Jump if Not Below (CF=0)
//@ ; #line	"CSPUTL.PAS" 2522
//@ 		mov	ax, [bp+mdy]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, bpx		; int16_t
//@ 		mov	bpx, ax		; int16_t
//@ 		mov	ax, [bp+mdx]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	bpy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2523
//@ 
//@ loc_273B9:				; CODE XREF: SendFastRocket+77Bj
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+oz], ax	; int16_t
//@ 		mov	ax, [bp+oz]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+oz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2524
//@ 		push	bp
//@ 		call	CalcRZ		; function nested near PASCAL returns signed int 'Integer'
//@ 		mov	[bp+bz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2525
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74C0h]
//@ 		add	ax, [bp+oz]	; int16_t
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jge	short loc_27430	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74C2h]
//@ 		add	ax, [bp+oz]	; int16_t
//@ 		cmp	ax, [bp+bz]	; int16_t
//@ 		jle	short loc_27430	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2527
//@ 		mov	ax, bpx		; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, bpy		; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		mov	[bp+pl], 0FFFFh	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ms], ax	; int16_t
//@ 		mov	[bp+mn], 0FFFFh	; int16_t
//@ 		mov	ax, x$0		; int16_t
//@ 		mov	[bp+mx], ax	; int16_t
//@ 		mov	ax, y		; int16_t
//@ 		mov	[bp+my], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2530
//@ 
//@ loc_27430:				; CODE XREF: SendFastRocket:loc_27276j
//@ 					; SendFastRocket+66Aj ...
//@ 		mov	ax, y		; int16_t
//@ 		cmp	ax, word ptr [bp+var_32] ; Compare Two Operands
//@ 		jz	short loc_2743B	; Jump if Zero (ZF=1)
//@ 		jmp	loc_27170	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2743B:				; CODE XREF: SendFastRocket+555j
//@ 					; SendFastRocket+823j
//@ 		mov	ax, x$0		; int16_t
//@ 		cmp	ax, word ptr [bp+var_32+2] ; Compare Two Operands
//@ 		jz	short loc_27446	; Jump if Zero (ZF=1)
//@ 		jmp	loc_27156	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2533
//@ 
//@ loc_27446:				; CODE XREF: SendFastRocket+53Bj
//@ 					; SendFastRocket+82Ej
//@ 		cmp	bpx, 0		; int16_t
//@ 		jnz	short loc_27457	; Jump if Not Zero (ZF=0)
//@ 		cmp	bpy, 0		; int16_t
//@ 		jnz	short loc_27457	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_27979	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2535
//@ 
//@ loc_27457:				; CODE XREF: SendFastRocket+838j
//@ 					; SendFastRocket+83Fj
//@ 		cmp	[bp+vz], 0FFF0h	; int16_t
//@ 		jl	short loc_27460	; Jump if Less (SF!=OF)
//@ 		jmp	loc_27525	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2537
//@ 
//@ loc_27460:				; CODE XREF: SendFastRocket+848j
//@ 		mov	ax, [bp+vz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	bpx, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2538
//@ 		mov	ax, [bp+vz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	bpy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2539
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_27525	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2541
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ms], ax	; int16_t
//@ 		mov	[bp+pl], 0FFFFh	; int16_t
//@ 		mov	[bp+mn], 0FFFFh	; int16_t
//@ ; #line	"CSPUTL.PAS" 2542
//@ 		mov	ax, bpx		; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, bpy		; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		mov	[bp+mx], 0FFFFh	; int16_t
//@ 		mov	[bp+my], 0FFFFh	; int16_t
//@ ; #line	"CSPUTL.PAS" 2547
//@ 
//@ loc_27525:				; CODE XREF: SendFastRocket+84Aj
//@ 					; SendFastRocket+8EBj
//@ 		cmp	[bp+vz], 10h	; int16_t
//@ 		jg	short loc_2752E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_27643	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2549
//@ 
//@ loc_2752E:				; CODE XREF: SendFastRocket+916j
//@ 		mov	ax, 1000h
//@ 		sub	ax, [bp+rz]	; int16_t
//@ 		mov	[bp+rz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2550
//@ 		mov	ax, [bp+vz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	bpx, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2551
//@ 		mov	ax, [bp+vz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	bpy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2552
//@ 		mov	ax, 1000h
//@ 		sub	ax, [bp+rz]	; int16_t
//@ 		mov	[bp+rz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2553
//@ 		mov	ax, bpy		; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, bpx		; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_27643	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2555
//@ 		mov	al, byte ptr bpy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr bpx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 6		; Shift	Logical	Left
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr [di+5EC6h], 3Eh ; '>' ; Compare Two Operands
//@ 		jz	short loc_27621	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2556
//@ 		mov	ax, bpx		; int16_t
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, bpy		; int16_t
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		mov	[bp+mx], 0FFFFh	; int16_t
//@ 		mov	[bp+my], 0FFFFh	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+ms], ax	; int16_t
//@ 		mov	[bp+pl], 0FFFFh	; int16_t
//@ 		mov	[bp+mn], 0FFFFh	; int16_t
//@ 		jmp	short loc_27643	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2558
//@ 
//@ loc_27621:				; CODE XREF: SendFastRocket+9E5j
//@ 		cmp	[bp+mx], 0FFFFh	; int16_t
//@ 		jz	short loc_27640	; Jump if Zero (ZF=1)
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 83h ;	'ƒ' ; Compare Two Operands
//@ 		jnb	short loc_27643	; Jump if Not Below (CF=0)
//@ 
//@ loc_27640:				; CODE XREF: SendFastRocket+A12j
//@ 		jmp	locret_27979	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2563
//@ 
//@ loc_27643:				; CODE XREF: SendFastRocket+918j
//@ 					; SendFastRocket+9CBj ...
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		mov	bpx, ax		; int16_t
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		mov	bpy, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2564
//@ 		push	bp
//@ 		call	CalcRZ		; function nested near PASCAL returns signed int 'Integer'
//@ 		mov	[bp+rz], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2568
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jz	short loc_27684	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+rry], ax	; int16_t
//@ 		jmp	short loc_276AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2569
//@ 
//@ loc_27684:				; CODE XREF: SendFastRocket+A47j
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 384h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+rrx]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+rrx], ax	; int16_t
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 384h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+rry]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+rry], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2572
//@ 
//@ loc_276AA:				; CODE XREF: SendFastRocket+A6Fj
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jnz	short loc_276D8	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+ms], 0	; int16_t
//@ 		jnz	short loc_276D8	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+mn], 0FFFFh	; int16_t
//@ 		jnz	short loc_276D8	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+mx], 0FFFFh	; int16_t
//@ 		jnz	short loc_276D8	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	bpx		; int16_t
//@ 		push	bpy		; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		call	AddHole		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2574
//@ 
//@ loc_276D8:				; CODE XREF: SendFastRocket+A9Bj
//@ 					; SendFastRocket+AA1j ...
//@ 		cmp	[bp+mx], 0FFFFh	; int16_t
//@ 		jz	short loc_276EC	; Jump if Zero (ZF=1)
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+OwId]	; int16_t
//@ 		call	CheckSwitchShoot ; function far	PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2575
//@ 
//@ loc_276EC:				; CODE XREF: SendFastRocket+AC9j
//@ 		cmp	[bp+mx], 0FFFFh	; int16_t
//@ 		jnz	short loc_276F5	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_27784	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_276F5:				; CODE XREF: SendFastRocket+ADDj
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_32], di
//@ 		mov	word ptr [bp+var_32+2],	es
//@ ; #line	"CSPUTL.PAS" 2576
//@ 		mov	al, es:[di]
//@ ; #line	"CSPUTL.PAS" 2577
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_27731	; Jump if Below	(CF=1)
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		ja	short loc_27731	; Jump if Above	(CF=0 &	ZF=0)
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	bpx		; int16_t
//@ 		push	bpy		; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		call	AddHole		; function far PASCAL returns void
//@ 		jmp	short loc_27784	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2578
//@ 
//@ loc_27731:				; CODE XREF: SendFastRocket+B00j
//@ 					; SendFastRocket+B04j
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_27784	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_27784	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 2579
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74B8h], 0 ; Compare Two Operands
//@ 		jle	short loc_27784	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74BAh], 0 ; Compare Two Operands
//@ 		jle	short loc_27784	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2582
//@ 		imul	di, [bp+RType],	16h ; int16_t
//@ 		mov	ax, [di-3274h]
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+9], ax	; Integer Subtraction
//@ ; #line	"CSPUTL.PAS" 2583
//@ 		cmp	word ptr es:[di+9], 0 ;	Compare	Two Operands
//@ 		jg	short loc_27784	; Jump if Greater (ZF=0	& SF=OF)
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		call	Blow3dObjAt	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2587
//@ 
//@ loc_27784:				; CODE XREF: SendFastRocket+ADFj
//@ 					; SendFastRocket+B1Cj ...
//@ 		imul	di, [bp+RType],	16h ; int16_t
//@ 		add	di, 0CD84h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPUTL.PAS" 2589
//@ 		mov	ax, es:[di+8]
//@ 		mov	[bp+RP], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2590
//@ 		cmp	[bp+RB], 3	; int16_t
//@ 		jnz	short loc_277C7	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+ry]	; int16_t
//@ 		sub	ax, [bp+rry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+rx]	; int16_t
//@ 		sub	ax, [bp+rrx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		mov	cx, ax
//@ 		imul	ax, [bp+RP], 64h ; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+RP], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2591
//@ 
//@ loc_277C7:				; CODE XREF: SendFastRocket+B86j
//@ 		cmp	[bp+ms], 0	; int16_t
//@ 		jle	short loc_277FF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		push	[bp+ms]		; int16_t
//@ 		push	[bp+RP]		; int16_t
//@ 		mov	ax, [bp+RP]	; int16_t
//@ 		mul	[bp+scale]	; int16_t
//@ 		push	ax
//@ 		push	[bp+OwId]	; int16_t
//@ 		call	ShootMonster	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2592
//@ 
//@ loc_277FF:				; CODE XREF: SendFastRocket+BB8j
//@ 		cmp	[bp+mn], 0	; int16_t
//@ 		jle	short loc_2780D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		push	[bp+mn]		; int16_t
//@ 		call	ExplodeMine	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2593
//@ 
//@ loc_2780D:				; CODE XREF: SendFastRocket+BF0j
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jle	short loc_2785A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2595
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+RP]		; int16_t
//@ 		push	[bp+pl]		; int16_t
//@ 		push	[bp+OwId]	; int16_t
//@ 		call	ShootMe		; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2596
//@ 		imul	di, [bp+pl], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_36], di
//@ 		mov	word ptr [bp+var_36+2],	es
//@ ; #line	"CSPUTL.PAS" 2597
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+rx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+ry]	; int16_t
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+1Ch], ax
//@ 		mov	ax, [bp+RP]	; int16_t
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CSPUTL.PAS" 2599
//@ 
//@ loc_2785A:				; CODE XREF: SendFastRocket+BFEj
//@ 		cmp	[bp+RB], 3	; int16_t
//@ 		jnz	short loc_27886	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jle	short loc_27886	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		imul	di, [bp+pl], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPUTL.PAS" 2600
//@ 		mov	word ptr es:[di+18h], 20h ; ' '
//@ 		add	word ptr es:[di+0Eh], 2	; Add
//@ 		mov	ax, es:[di+2Ah]
//@ 		or	ax, 100h	; Logical Inclusive OR
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"CSPUTL.PAS" 2605
//@ 
//@ loc_27886:				; CODE XREF: SendFastRocket+C4Bj
//@ 					; SendFastRocket+C51j
//@ 		cmp	[bp+RB], 1	; int16_t
//@ 		jz	short loc_2788F	; Jump if Zero (ZF=1)
//@ 		jmp	locret_27979	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2606
//@ 
//@ loc_2788F:				; CODE XREF: SendFastRocket+C77j
//@ 		imul	di, [bp+RType],	16h ; int16_t
//@ 		add	di, 0CD84h	; Add
//@ 		push	ds
//@ 		pop	es
//@ ; #line	"CSPUTL.PAS" 2608
//@ 		cmp	[bp+rz], 200h	; int16_t
//@ 		jge	short loc_278BD	; Jump if Greater or Equal (SF=OF)
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	0
//@ 		call	iswater		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_278BD	; Jump if Zero (ZF=1)
//@ 		cmp	[bp+ms], 0	; int16_t
//@ 		jnz	short loc_278BD	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jz	short loc_278C1	; Jump if Zero (ZF=1)
//@ 
//@ loc_278BD:				; CODE XREF: SendFastRocket+C8Bj
//@ 					; SendFastRocket+C9Cj ...
//@ 		mov	al, 0
//@ 		jmp	short loc_278C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_278C1:				; CODE XREF: SendFastRocket+CA8j
//@ 		mov	al, 1
//@ 
//@ loc_278C3:				; CODE XREF: SendFastRocket+CACj
//@ 		mov	[bp+Water], al	; bool
//@ ; #line	"CSPUTL.PAS" 2609
//@ 		cmp	[bp+ms], 0	; int16_t
//@ 		jnz	short loc_278D2	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jz	short loc_278E6	; Jump if Zero (ZF=1)
//@ 
//@ loc_278D2:				; CODE XREF: SendFastRocket+CB7j
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		push	0Bh
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ 		jmp	short loc_2790C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2610
//@ 
//@ loc_278E6:				; CODE XREF: SendFastRocket+CBDj
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7D0h
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+rrx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 7D0h
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+rry]	; int16_t
//@ 		push	ax
//@ 		push	[bp+rz]		; int16_t
//@ 		mov	al, [bp+Water]	; bool
//@ 		push	ax
//@ 		call	BlowShootSmoke	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2612
//@ 
//@ loc_2790C:				; CODE XREF: SendFastRocket+CD1j
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+OwId]	; int16_t
//@ 		call	MakeBlow	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2613
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	8
//@ 		push	20h ; ' '
//@ 		push	20h ; ' '
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2617
//@ 		cmp	[bp+ms], 0	; int16_t
//@ 		jnz	short locret_27979 ; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jnz	short locret_27979 ; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2618
//@ 		cmp	[bp+Water], 0	; bool
//@ 		jz	short loc_27955	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2619
//@ 		push	0FFFFh
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	0Bh
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ 		jmp	short locret_27979 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2620
//@ 
//@ loc_27955:				; CODE XREF: SendFastRocket+D2Fj
//@ 		push	0Bh
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		cmp	ax, 7		; Compare Two Operands
//@ 		jbe	short locret_27979 ; Jump if Below or Equal (CF=1 | ZF=1)
//@ 		push	0FFFFh
//@ 		push	[bp+rrx]	; int16_t
//@ 		push	[bp+rry]	; int16_t
//@ 		push	2
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 4Eh	; 'N'   ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2622
//@ 
//@ locret_27979:				; CODE XREF: SendFastRocket+841j
//@ 					; SendFastRocket:loc_27640j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	12h		; Return Far from Procedure
//@ SendFastRocket	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2629
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ GetBrightAt	proc far		; CODE XREF: ExpandObject+25P
//@ 					; Expand3dObject+3CP ...
//@ 
//@ GetBrightAt	= byte ptr -1		; uint8_t
//@ y		= word ptr  6		; uint16_t
//@ x		= word ptr  8		; uint16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2630
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	[bp+y],	ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 2631
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, [bp+x]	; uint16_t
//@ 		mov	di, ax
//@ 		pop	es
//@ 		assume es:nothing
//@ 		mov	al, es:[di]
//@ 		mov	[bp+GetBrightAt], al ; uint8_t
//@ ; #line	"CSPUTL.PAS" 2632
//@ 		mov	al, [bp+GetBrightAt] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ GetBrightAt	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2641
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ GetSmoothBrightAt proc far		; CODE XREF: EndPaint+1BFP
//@ 					; ExpandPlayer+68P ...
//@ 
//@ GetSmoothBrightAt= word	ptr -2		; int16_t
//@ y		= word ptr  6		; uint16_t
//@ x		= word ptr  8		; uint16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2642
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		push	ax
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		push	ax
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		pop	dx
//@ 		add	ax, dx		; Add
//@ 		pop	dx
//@ 		add	ax, dx		; Add
//@ 		pop	dx
//@ 		add	ax, dx		; Add
//@ 		mov	[bp+GetSmoothBrightAt],	ax ; int16_t
//@ ; #line	"CSPUTL.PAS" 2646
//@ 		mov	ax, [bp+GetSmoothBrightAt] ; int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ GetSmoothBrightAt endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2653
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ PathToMe	proc far		; CODE XREF: AnimateRockets+126P
//@ 					; AnimateRockets+1C9P ...
//@ 
//@ var_20		= dword	ptr -20h
//@ var_1C		= word ptr -1Ch
//@ var_1A		= word ptr -1Ah
//@ y		= word ptr -0Eh		; int16_t
//@ x		= word ptr -0Ch		; int16_t
//@ y2		= word ptr -0Ah		; int16_t
//@ x2		= word ptr -8		; int16_t
//@ y1		= word ptr -6		; int16_t
//@ x1		= word ptr -4		; int16_t
//@ PathToMe	= byte ptr -1		; bool
//@ Rd		= word ptr  6		; int16_t
//@ hy		= word ptr  8		; int16_t
//@ hx		= word ptr  0Ah		; int16_t
//@ my		= word ptr  0Ch		; int16_t
//@ mx		= word ptr  0Eh		; int16_t
//@ 
//@ 		enter	20h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2654
//@ 		mov	ax, [bp+Rd]	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, [bp+hy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, [bp+hx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_27A4F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2655
//@ 		mov	[bp+PathToMe], 0 ; bool
//@ 		jmp	loc_27B86	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2656
//@ 
//@ loc_27A4F:				; CODE XREF: PathToMe+28j
//@ 		mov	al, byte ptr [bp+mx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+x1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2657
//@ 		mov	al, byte ptr [bp+mx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+x2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2658
//@ 		mov	al, byte ptr [bp+my+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hy+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2659
//@ 		mov	al, byte ptr [bp+my+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hy+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+y2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2661
//@ 		cmp	[bp+x1], 0	; int16_t
//@ 		jge	short loc_27ABE	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x1], ax	; int16_t
//@ 
//@ loc_27ABE:				; CODE XREF: PathToMe+99j
//@ 		cmp	[bp+x2], 3Fh ; '?' ; int16_t
//@ 		jle	short loc_27AC9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+x2], 3Fh ; '?' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2662
//@ 
//@ loc_27AC9:				; CODE XREF: PathToMe+A4j
//@ 		cmp	[bp+y1], 0	; int16_t
//@ 		jge	short loc_27AD4	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y1], ax	; int16_t
//@ 
//@ loc_27AD4:				; CODE XREF: PathToMe+AFj
//@ 		cmp	[bp+y2], 3Fh ; '?' ; int16_t
//@ 		jle	short loc_27ADF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+y2], 3Fh ; '?' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2663
//@ 
//@ loc_27ADF:				; CODE XREF: PathToMe+BAj
//@ 		mov	[bp+PathToMe], 1 ; bool
//@ ; #line	"CSPUTL.PAS" 2664
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+var_1A], ax
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		cmp	ax, [bp+var_1A]	; Compare Two Operands
//@ 		jle	short loc_27AF4	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_27B86	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27AF4:				; CODE XREF: PathToMe+D1j
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_27AFC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27AF9:				; CODE XREF: PathToMe+165j
//@ 		inc	[bp+x]		; int16_t
//@ ; #line	"CSPUTL.PAS" 2665
//@ 
//@ loc_27AFC:				; CODE XREF: PathToMe+D9j
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+var_1C], ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jg	short loc_27B7B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_27B12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27B0F:				; CODE XREF: PathToMe+15Bj
//@ 		inc	[bp+y]		; int16_t
//@ 
//@ loc_27B12:				; CODE XREF: PathToMe+EFj
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_20], di
//@ 		mov	word ptr [bp+var_20+2],	es
//@ ; #line	"CSPUTL.PAS" 2666
//@ 		mov	al, es:[di]
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_27B73	; Jump if Below	(CF=1)
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		ja	short loc_27B73	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 2667
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_27B73	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPUTL.PAS" 2668
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+hx]		; int16_t
//@ 		push	[bp+hy]		; int16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+7]
//@ 		push	word ptr es:[di+9]
//@ 		call	Test2Vectors$0	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_27B73	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2669
//@ 		mov	[bp+PathToMe], 0 ; bool
//@ 		jmp	short loc_27B86	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27B73:				; CODE XREF: PathToMe+112j
//@ 					; PathToMe+116j ...
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jnz	short loc_27B0F	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_27B7B:				; CODE XREF: PathToMe+EAj
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, [bp+var_1A]	; Compare Two Operands
//@ 		jz	short loc_27B86	; Jump if Zero (ZF=1)
//@ 		jmp	loc_27AF9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2670
//@ 
//@ loc_27B86:				; CODE XREF: PathToMe+2Ej PathToMe+D3j ...
//@ 		mov	al, [bp+PathToMe] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ PathToMe	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2675
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ LookToMe	proc far		; CODE XREF: GetTarget+15AP
//@ 					; GetTarget+1E5P ...
//@ 
//@ var_1C		= word ptr -1Ch
//@ var_1A		= word ptr -1Ah
//@ y		= word ptr -0Eh		; int16_t
//@ x		= word ptr -0Ch		; int16_t
//@ y2		= word ptr -0Ah		; int16_t
//@ x2		= word ptr -8		; int16_t
//@ y1		= word ptr -6		; int16_t
//@ x1		= word ptr -4		; int16_t
//@ LookToMe	= byte ptr -1		; bool
//@ Rd		= word ptr  6		; int16_t
//@ hy		= word ptr  8		; int16_t
//@ hx		= word ptr  0Ah		; int16_t
//@ my		= word ptr  0Ch		; int16_t
//@ mx		= word ptr  0Eh		; int16_t
//@ 
//@ 		enter	20h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2676
//@ 		mov	ax, [bp+Rd]	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	bx, ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, [bp+hy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, [bp+hx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, bx		; Compare Two Operands
//@ 		jle	short loc_27BBE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2677
//@ 		mov	[bp+LookToMe], 0 ; bool
//@ 		jmp	loc_27CD5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2678
//@ 
//@ loc_27BBE:				; CODE XREF: LookToMe+28j
//@ 		mov	al, byte ptr [bp+mx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+x1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2679
//@ 		mov	al, byte ptr [bp+mx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+x2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2680
//@ 		mov	al, byte ptr [bp+my+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hy+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 0FFFEh	; Add
//@ 		push	ax
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2681
//@ 		mov	al, byte ptr [bp+my+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	al, byte ptr [bp+hy+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+y2], ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2683
//@ 		cmp	[bp+x1], 0	; int16_t
//@ 		jge	short loc_27C2D	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x1], ax	; int16_t
//@ 
//@ loc_27C2D:				; CODE XREF: LookToMe+99j
//@ 		cmp	[bp+x2], 3Fh ; '?' ; int16_t
//@ 		jle	short loc_27C38	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+x2], 3Fh ; '?' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2684
//@ 
//@ loc_27C38:				; CODE XREF: LookToMe+A4j
//@ 		cmp	[bp+y1], 0	; int16_t
//@ 		jge	short loc_27C43	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y1], ax	; int16_t
//@ 
//@ loc_27C43:				; CODE XREF: LookToMe+AFj
//@ 		cmp	[bp+y2], 3Fh ; '?' ; int16_t
//@ 		jle	short loc_27C4E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+y2], 3Fh ; '?' ; int16_t
//@ ; #line	"CSPUTL.PAS" 2685
//@ 
//@ loc_27C4E:				; CODE XREF: LookToMe+BAj
//@ 		mov	[bp+LookToMe], 1 ; bool
//@ ; #line	"CSPUTL.PAS" 2686
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+var_1A], ax
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		cmp	ax, [bp+var_1A]	; Compare Two Operands
//@ 		jg	short loc_27CD5	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_27C68	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27C65:				; CODE XREF: LookToMe+146j
//@ 		inc	[bp+x]		; int16_t
//@ ; #line	"CSPUTL.PAS" 2687
//@ 
//@ loc_27C68:				; CODE XREF: LookToMe+D6j
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+var_1C], ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jg	short loc_27CCD	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_27C7E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27C7B:				; CODE XREF: LookToMe+13Ej
//@ 		inc	[bp+y]		; int16_t
//@ 
//@ loc_27C7E:				; CODE XREF: LookToMe+ECj
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ ; #line	"CSPUTL.PAS" 2688
//@ 		mov	al, es:[di]
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_27CC5	; Jump if Below	(CF=1)
//@ 		cmp	al, 55h	; 'U'   ; Compare Two Operands
//@ 		ja	short loc_27CC5	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPUTL.PAS" 2689
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+hx]		; int16_t
//@ 		push	[bp+hy]		; int16_t
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+7]
//@ 		push	word ptr es:[di+9]
//@ 		call	Test2Vectors$0	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_27CC5	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2690
//@ 		mov	[bp+LookToMe], 0 ; bool
//@ 		jmp	short loc_27CD5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27CC5:				; CODE XREF: LookToMe+109j
//@ 					; LookToMe+10Dj ...
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jnz	short loc_27C7B	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_27CCD:				; CODE XREF: LookToMe+E7j
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, [bp+var_1A]	; Compare Two Operands
//@ 		jnz	short loc_27C65	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPUTL.PAS" 2691
//@ 
//@ loc_27CD5:				; CODE XREF: LookToMe+2Ej LookToMe+D1j ...
//@ 		mov	al, [bp+LookToMe] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ LookToMe	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2696
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ WeakUpMonstersTo proc far		; CODE XREF: AnimateMonsters+1EEP
//@ 					; AnimateMonsters+14AEP ...
//@ 
//@ var_8		= dword	ptr -8
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; int16_t
//@ exc		= word ptr  6		; int16_t
//@ ppy		= word ptr  8		; int16_t
//@ ppx		= word ptr  0Ah		; int16_t
//@ tr		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2697
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jle	short loc_27CF1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_27D9C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27CF1:				; CODE XREF: WeakUpMonstersTo+10j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_27CF9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27CF6:				; CODE XREF: WeakUpMonstersTo+BDj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPUTL.PAS" 2698
//@ 
//@ loc_27CF9:				; CODE XREF: WeakUpMonstersTo+18j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+exc]	; int16_t
//@ 		jnz	short loc_27D04	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_27D91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2699
//@ 
//@ loc_27D04:				; CODE XREF: WeakUpMonstersTo+23j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSPUTL.PAS" 2700
//@ 		cmp	byte ptr es:[di+26h], 0	; Compare Two Operands
//@ 		jnz	short loc_27D91	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+8], 0Eh	; Compare Two Operands
//@ 		jz	short loc_27D91	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2701
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	[bp+ppx]	; int16_t
//@ 		push	[bp+ppy]	; int16_t
//@ 		push	8
//@ 		call	LookToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_27D91	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2703
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2704
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+26h], 2
//@ ; #line	"CSPUTL.PAS" 2705
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		mov	byte ptr es:[di+24h], 0
//@ 		mov	byte ptr es:[di+25h], 0
//@ ; #line	"CSPUTL.PAS" 2706
//@ 		mov	ax, [bp+tr]	; int16_t
//@ 		mov	es:[di+14h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSPUTL.PAS" 2707
//@ 		mov	ax, [bp+ppx]	; int16_t
//@ 		mov	es:[di+16h], ax
//@ 		mov	ax, [bp+ppy]	; int16_t
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CSPUTL.PAS" 2708
//@ 
//@ loc_27D91:				; CODE XREF: WeakUpMonstersTo+25j
//@ 					; WeakUpMonstersTo+3Dj	...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short locret_27D9C ; Jump if Zero (ZF=1)
//@ 		jmp	loc_27CF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2709
//@ 
//@ locret_27D9C:				; CODE XREF: WeakUpMonstersTo+12j
//@ 					; WeakUpMonstersTo+BBj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ WeakUpMonstersTo endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2729
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetWeapon	proc far		; CODE XREF: LoadServerPatch+406P
//@ 					; LoadServerPatch+481P	...
//@ 
//@ w		= word ptr  6		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 2730
//@ 		mov	ax, [bp+w]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	al, [di-0FB1h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_27DC5	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_27DE8 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2731
//@ 
//@ loc_27DC5:				; CODE XREF: SetWeapon+21j
//@ 		mov	ax, [bp+w]	; int16_t
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	[di-0F8Eh], ax
//@ ; #line	"CSPUTL.PAS" 2732
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponPhase, ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 2733
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		jnz	short locret_27DE8 ; Jump if Not Zero (ZF=0)
//@ 		mov	GunShift, 1	; uint16_t
//@ ; #line	"CSPUTL.PAS" 2734
//@ 
//@ locret_27DE8:				; CODE XREF: SetWeapon+23j
//@ 					; SetWeapon+40j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ SetWeapon	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2738
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddAmmoToPlayer	proc far		; CODE XREF: CheckFloorLinks+2A4P
//@ 					; DoGame+13A4P
//@ 
//@ var_6		= dword	ptr -6
//@ w		= word ptr -2		; int16_t
//@ da		= word ptr  6		; int16_t
//@ na		= word ptr  8		; int16_t
//@ np		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ 		imul	di, [bp+np], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSPUTL.PAS" 2740
//@ 		cmp	[bp+da], 0	; int16_t
//@ 		jnz	short loc_27E08	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_27E6D ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2741
//@ 
//@ loc_27E08:				; CODE XREF: AddAmmoToPlayer+18j
//@ 		mov	ax, [bp+na]	; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+2Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+w],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2742
//@ 		mov	ax, [bp+np]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_27E3C	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+w],	0	; int16_t
//@ 		jnz	short loc_27E3C	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+48h]
//@ 		cmp	ax, [bp+na]	; int16_t
//@ 		jge	short loc_27E3C	; Jump if Greater or Equal (SF=OF)
//@ 		push	[bp+na]		; int16_t
//@ 		call	SetWeapon	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2744
//@ 
//@ loc_27E3C:				; CODE XREF: AddAmmoToPlayer+34j
//@ 					; AddAmmoToPlayer+3Aj ...
//@ 		mov	ax, [bp+da]	; int16_t
//@ 		add	[bp+w],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2745
//@ 		mov	ax, [bp+w]	; int16_t
//@ 		mov	di, [bp+na]	; int16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		cmp	ax, [di-1BBAh]	; Compare Two Operands
//@ 		jle	short loc_27E5E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPUTL.PAS" 2746
//@ 		mov	di, [bp+na]	; int16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		mov	ax, [di-1BBAh]
//@ 		mov	[bp+w],	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2747
//@ 
//@ loc_27E5E:				; CODE XREF: AddAmmoToPlayer+63j
//@ 		mov	dl, byte ptr [bp+w] ; int16_t
//@ 		mov	ax, [bp+na]	; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+2Dh], dl
//@ ; #line	"CSPUTL.PAS" 2749
//@ 
//@ locret_27E6D:				; CODE XREF: AddAmmoToPlayer+1Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ AddAmmoToPlayer	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2752
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CenterView	proc far		; CODE XREF: ProcessDevices+59BP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 2753
//@ 		cmp	LookVz,	0	; int16_t
//@ 		jnz	short loc_27E82	; Jump if Not Zero (ZF=0)
//@ 		mov	VCenterMode, 0	; bool
//@ 		jmp	short locret_27EEB ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2754
//@ 
//@ loc_27E82:				; CODE XREF: CenterView+8j
//@ 		cmp	LookVz,	0	; int16_t
//@ 		jle	short loc_27E92	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	lvz, ax		; int16_t
//@ 		jmp	short loc_27E99	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27E92:				; CODE XREF: CenterView+16j
//@ 		mov	ax, t1		; uint16_t
//@ 		add	lvz, ax		; int16_t
//@ ; #line	"CSPUTL.PAS" 2755
//@ 
//@ loc_27E99:				; CODE XREF: CenterView+1Fj
//@ 		mov	ax, LookVz	; int16_t
//@ 		mov	n$0, ax		; int16_t
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, lvz		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	LookVz,	ax	; int16_t
//@ ; #line	"CSPUTL.PAS" 2756
//@ 		push	n$0		; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		push	ax
//@ 		push	LookVz		; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		pop	dx
//@ 		cmp	al, dl		; Compare Two Operands
//@ 		jz	short loc_27EE6	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2757
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LookVz,	ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	lvz, ax		; int16_t
//@ 		mov	VCenterMode, 0	; bool
//@ ; #line	"CSPUTL.PAS" 2758
//@ 
//@ loc_27EE6:				; CODE XREF: CenterView+64j
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"CSPUTL.PAS" 2759
//@ 
//@ locret_27EEB:				; CODE XREF: CenterView+Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ CenterView	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2773
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RespawnMonster	proc far		; CODE XREF: ExecConsole+53DP
//@ 					; AnimateMonsters+60EP
//@ 
//@ var_4		= dword	ptr -4
//@ m		= word ptr  6		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPUTL.PAS" 2774
//@ 		imul	di, [bp+m], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPUTL.PAS" 2776
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jnz	short loc_27F0A	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_27F74 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2777
//@ 
//@ loc_27F0A:				; CODE XREF: RespawnMonster+19j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	byte ptr es:[di+26h], 0
//@ ; #line	"CSPUTL.PAS" 2778
//@ 		mov	byte ptr es:[di+0Bh], 0
//@ ; #line	"CSPUTL.PAS" 2779
//@ 		mov	word ptr es:[di+14h], 0FFFFh
//@ ; #line	"CSPUTL.PAS" 2780
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di-7FF0h]
//@ 		or	ax, [di-7FEEh]	; Logical Inclusive OR
//@ 		jz	short loc_27F3C	; Jump if Zero (ZF=1)
//@ ; #line	"CSPUTL.PAS" 2781
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 0Eh
//@ 		jmp	short loc_27F45	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPUTL.PAS" 2782
//@ 
//@ loc_27F3C:				; CODE XREF: RespawnMonster+42j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 2
//@ ; #line	"CSPUTL.PAS" 2783
//@ 
//@ loc_27F45:				; CODE XREF: RespawnMonster+4Dj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FB4h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSPUTL.PAS" 2784
//@ 		mov	byte ptr es:[di+24h], 0
//@ ; #line	"CSPUTL.PAS" 2785
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSPUTL.PAS" 2787
//@ 
//@ locret_27F74:				; CODE XREF: RespawnMonster+1Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ RespawnMonster	endp
//@ 
//@ ; #line	"CSPUTL.PAS" 2842
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; Attributes: bp-based frame
//@ 
//@ $CspUtlInit	proc far		; CODE XREF: PROGRAM+23P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPUTL.PAS" 2843
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CelSaved, ax	; uint16_t
//@ ; #line	"CSPUTL.PAS" 2844
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ $CspUtlInit	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		align 10h
