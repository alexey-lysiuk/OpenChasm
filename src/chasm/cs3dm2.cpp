
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

#include "cs3dm2.h"

//@ ; #line	"CS3DM2.PAS" 79
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Draw3DObject	proc far		; CODE XREF: DrawHoles+19EP
//@ 					; Expand3dObject+279P ...
//@ 
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; int16_t
//@ Shadow		= byte ptr  6		; bool
//@ fi		= word ptr  8		; uint16_t
//@ tz		= word ptr  0Ah		; int16_t
//@ ty		= word ptr  0Ch		; int16_t
//@ tx		= word ptr  0Eh		; int16_t
//@ P		= dword	ptr  10h	; TOHeader*
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS3DM2.PAS" 81
//@ 		cmp	Invisibility, 0	; bool
//@ 		jz	short loc_17E25	; Jump if Zero (ZF=1)
//@ 		mov	[bp+Shadow], 0	; bool
//@ ; #line	"CS3DM2.PAS" 83
//@ 
//@ loc_17E25:				; CODE XREF: Draw3DObject+9j
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		mov	OBJx, ax	; int16_t
//@ 		mov	ax, [bp+ty]	; int16_t
//@ 		add	ax, 60h	; '`'   ; Add
//@ 		mov	OBJy, ax	; int16_t
//@ 		mov	ax, [bp+tz]	; int16_t
//@ 		sub	ax, ehz		; int16_t
//@ 		mov	OBJz, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 84
//@ 		mov	ax, [bp+fi]	; uint16_t
//@ 		mov	CurFI, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 85
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+ty]	; int16_t
//@ 		add	ax, 320h	; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_17E5D	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1844A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 87
//@ 
//@ loc_17E5D:				; CODE XREF: Draw3DObject+42j
//@ 		mov	ax, word ptr [bp+P] ; TOHeader*
//@ 		or	ax, word ptr [bp+P+2] ;	TOHeader*
//@ 		jz	short loc_17E6B	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr [bp+P], 0FFFFh	; TOHeader*
//@ 		jnz	short loc_17E6E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 93
//@ 
//@ loc_17E6B:				; CODE XREF: Draw3DObject+4Dj
//@ 		jmp	loc_1844A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 96
//@ 
//@ loc_17E6E:				; CODE XREF: Draw3DObject+53j
//@ 		mov	ax, word ptr [bp+P] ; TOHeader*
//@ 		mov	dx, word ptr [bp+P+2] ;	TOHeader*
//@ 		mov	word ptr POH, ax ; TOHeader*
//@ 		mov	word ptr POH+2,	dx ; TOHeader*
//@ ; #line	"CS3DM2.PAS" 97
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es:[di+4802h]
//@ 		mov	FCount,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 98
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es:[di+4800h]
//@ 		mov	VCount,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 99
//@ 		cmp	FCount,	1	; int16_t
//@ 		jl	short loc_17EA0	; Jump if Less (SF!=OF)
//@ 		mov	ax, word ptr [bp+P] ; TOHeader*
//@ 		or	ax, word ptr [bp+P+2] ;	TOHeader*
//@ 		jnz	short loc_17EA3	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_17EA0:				; CODE XREF: Draw3DObject+80j
//@ 		jmp	loc_1844A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 101
//@ 
//@ loc_17EA3:				; CODE XREF: Draw3DObject+88j
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es
//@ 		mov	OHSeg, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 102
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		les	di, es:[di+4806h] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	TSeg, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 103
//@ 		mov	ax, WallH	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		mov	WallH4,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 104
//@ 		mov	ax, TSeg	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CS3DM2.PAS" 105
//@ 		cmp	XFi, 0		; int16_t
//@ 		jz	short loc_17EDD	; Jump if Zero (ZF=1)
//@ 		call	RotateModelASM_XZ ; function far PASCAL	returns	void
//@ 		jmp	short loc_17F11	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 107
//@ 
//@ loc_17EDD:				; CODE XREF: Draw3DObject+BEj
//@ 		cmp	HiRot, 0	; bool
//@ 		jz	short loc_17F0C	; Jump if Zero (ZF=1)
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, GlobY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, GlobX	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, 1388h	; Compare Two Operands
//@ 		jge	short loc_17F0C	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS3DM2.PAS" 108
//@ 		call	RotateModelASM_HiDet ; function	far PASCAL returns void
//@ 		jmp	short loc_17F11	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 109
//@ 
//@ loc_17F0C:				; CODE XREF: Draw3DObject+CCj
//@ 					; Draw3DObject+EDj
//@ 		call	RotateModelASM	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 111
//@ 
//@ loc_17F11:				; CODE XREF: Draw3DObject+C5j
//@ 					; Draw3DObject+F4j
//@ 		call	ProcToScrMinMax	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 113
//@ 		mov	ax, WinSX	; uint16_t
//@ 		cmp	Lx2, ax		; int16_t
//@ 		jge	short loc_17F22	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1844A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 114
//@ 
//@ loc_17F22:				; CODE XREF: Draw3DObject+107j
//@ 		mov	bx, WinEX	; uint16_t
//@ 		cmp	Lx1, bx		; int16_t
//@ 		jle	short loc_17F2F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1844A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 116
//@ 
//@ loc_17F2F:				; CODE XREF: Draw3DObject+114j
//@ 		cmp	Lx1, ax		; int16_t
//@ 		jge	short loc_17F38	; Jump if Greater or Equal (SF=OF)
//@ 		mov	Lx1, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 117
//@ 
//@ loc_17F38:				; CODE XREF: Draw3DObject+11Dj
//@ 		cmp	Lx2, bx		; int16_t
//@ 		jle	short loc_17F42	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	Lx2, bx		; int16_t
//@ ; #line	"CS3DM2.PAS" 119
//@ 
//@ loc_17F42:				; CODE XREF: Draw3DObject+126j
//@ 		mov	bx, Lx1		; int16_t
//@ 		shl	bx, 1		; Shift	Logical	Left
//@ 		add	bx, 822Eh	; Add
//@ ; #line	"CS3DM2.PAS" 120
//@ 		mov	cx, Lx2		; int16_t
//@ 		sub	cx, Lx1		; int16_t
//@ 		inc	cx		; Increment by 1
//@ 		mov	ax, CurDH	; uint16_t
//@ ; #line	"CS3DM2.PAS" 121
//@ 
//@ loc_17F58:				; CODE XREF: Draw3DObject+14Aj
//@ 		cmp	[bx], ax	; Compare Two Operands
//@ 		jl	short loc_17F65	; Jump if Less (SF!=OF)
//@ 		add	bx, 2		; Add
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_17F58	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 122
//@ 		jmp	loc_1844A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 126
//@ 
//@ loc_17F65:				; CODE XREF: Draw3DObject+144j
//@ 		cmp	[bp+Shadow], 0	; bool
//@ 		jnz	short loc_17F6E	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_18388	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_17F6E:				; CODE XREF: Draw3DObject+153j
//@ 		cmp	Curdark, 1Ah	; int16_t
//@ 		jl	short loc_17F78	; Jump if Less (SF!=OF)
//@ 		jmp	loc_18388	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_17F78:				; CODE XREF: Draw3DObject+15Dj
//@ 		cmp	[bp+ty], 1000h	; int16_t
//@ 		jl	short loc_17F82	; Jump if Less (SF!=OF)
//@ 		jmp	loc_18388	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 128
//@ 
//@ loc_17F82:				; CODE XREF: Draw3DObject+167j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LCnt, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 129
//@ 		mov	ax, ShadowCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LCnt	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_17FA4	; Jump if Less (SF!=OF)
//@ 		jle	short loc_17F9D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1806B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_17F9D:				; CODE XREF: Draw3DObject+182j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_17FA4	; Jump if Below	(CF=1)
//@ 		jmp	loc_1806B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 130
//@ 
//@ loc_17FA4:				; CODE XREF: Draw3DObject+180j
//@ 					; Draw3DObject+189j
//@ 		mov	al, byte ptr GlobY+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr GlobX+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, DarkMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 14h ;	Compare	Two Operands
//@ 		jb	short loc_17FC4	; Jump if Below	(CF=1)
//@ 		jmp	loc_1806B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 132
//@ 
//@ loc_17FC4:				; CODE XREF: Draw3DObject+1A9j
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, GlobX	; int16_t
//@ 		add	ax, 9Ch	; 'œ'   ; Add
//@ 		mov	llx, ax		; int16_t
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, GlobY	; int16_t
//@ 		add	ax, 9Ch	; 'œ'   ; Add
//@ 		mov	lly, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 133
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, lly		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, llx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 400h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	LtX, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 134
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, llx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, lly		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, 400h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	LtY, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 135
//@ 		mov	ax, 32C6h
//@ 		mov	ShLevel, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 136
//@ 		call	CreateShadow	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 137
//@ 		call	ProcToScrShadow_Clip ; function	far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 138
//@ 		call	DrawShadowFaces	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 139
//@ 		inc	LCnt		; int16_t
//@ ; #line	"CS3DM2.PAS" 142
//@ 
//@ loc_1806B:				; CODE XREF: Draw3DObject+184j
//@ 					; Draw3DObject+18Bj ...
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 143
//@ 
//@ loc_18070:				; CODE XREF: Draw3DObject+3E1j
//@ 		mov	ax, LtCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_1808D	; Jump if Less (SF!=OF)
//@ 		jle	short loc_18086	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_181FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18086:				; CODE XREF: Draw3DObject+26Bj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_1808D	; Jump if Below	(CF=1)
//@ 		jmp	loc_181FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1808D:				; CODE XREF: Draw3DObject+269j
//@ 					; Draw3DObject+272j
//@ 		mov	ax, ShadowCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LCnt	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_180AA	; Jump if Less (SF!=OF)
//@ 		jle	short loc_180A3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_181FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_180A3:				; CODE XREF: Draw3DObject+288j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_180AA	; Jump if Below	(CF=1)
//@ 		jmp	loc_181FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_180AA:				; CODE XREF: Draw3DObject+286j
//@ 					; Draw3DObject+28Fj
//@ 		imul	ax, [bp+n], 0Ch	; int16_t
//@ 		les	di, Lights	; TLight*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CS3DM2.PAS" 145
//@ 		mov	ax, GlobX	; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, GlobY	; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	R, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 146
//@ 		mov	ax, R		; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jl	short loc_180E0	; Jump if Less (SF!=OF)
//@ 		jmp	loc_181F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 147
//@ 
//@ loc_180E0:				; CODE XREF: Draw3DObject+2C5j
//@ 		mov	ax, es:[di+8]
//@ 		cmp	ax, es:[di+6]	; Compare Two Operands
//@ 		jz	short loc_1810D	; Jump if Zero (ZF=1)
//@ 		push	GlobX		; int16_t
//@ 		push	GlobY		; int16_t
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, R		; int16_t
//@ 		shr	ax, 7		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	LookToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1810D	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_181F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 149
//@ 
//@ loc_1810D:				; CODE XREF: Draw3DObject+2D2j
//@ 					; Draw3DObject+2F2j
//@ 		inc	LCnt		; int16_t
//@ ; #line	"CS3DM2.PAS" 150
//@ 		mov	ax, ehx		; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		mov	llx, ax		; int16_t
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		mov	lly, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 151
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, lly		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, llx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 400h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	LtX, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 152
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, llx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, lly		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, 400h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	LtY, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 153
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+8]
//@ 		sub	ax, R		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 24h	; '$'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 7		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	ShLevel, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 154
//@ 		cmp	ShLevel, 18h	; uint16_t
//@ 		jbe	short loc_181D5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ShLevel, 18h	; uint16_t
//@ ; #line	"CS3DM2.PAS" 155
//@ 
//@ loc_181D5:				; CODE XREF: Draw3DObject+3B7j
//@ 		mov	ax, 1AC6h
//@ 		mov	dx, ax
//@ 		mov	ax, ShLevel	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	ShLevel, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 156
//@ 		call	CreateShadow	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 157
//@ 		call	ProcToScrShadow_Clip ; function	far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 158
//@ 		call	DrawShadowFaces	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 160
//@ 
//@ loc_181F4:				; CODE XREF: Draw3DObject+2C7j
//@ 					; Draw3DObject+2F4j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CS3DM2.PAS" 161
//@ 		jmp	loc_18070	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 163
//@ 
//@ loc_181FA:				; CODE XREF: Draw3DObject+26Dj
//@ 					; Draw3DObject+274j ...
//@ 		mov	[bp+n],	1	; int16_t
//@ ; #line	"CS3DM2.PAS" 164
//@ 
//@ loc_181FF:				; CODE XREF: Draw3DObject+56Fj
//@ 		mov	ax, LCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_1821C	; Jump if Less (SF!=OF)
//@ 		jle	short loc_18215	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_18388	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18215:				; CODE XREF: Draw3DObject+3FAj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_1821C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_18388	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1821C:				; CODE XREF: Draw3DObject+3F8j
//@ 					; Draw3DObject+401j
//@ 		mov	ax, ShadowCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LCnt	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_18239	; Jump if Less (SF!=OF)
//@ 		jle	short loc_18232	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_18388	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18232:				; CODE XREF: Draw3DObject+417j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_18239	; Jump if Below	(CF=1)
//@ 		jmp	loc_18388	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18239:				; CODE XREF: Draw3DObject+415j
//@ 					; Draw3DObject+41Ej
//@ 		imul	di, [bp+n], 12h	; int16_t
//@ 		add	di, 0BCA4h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CS3DM2.PAS" 166
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, GlobX	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, GlobY	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	R, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 167
//@ 		mov	ax, R		; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jl	short loc_18286	; Jump if Less (SF!=OF)
//@ 		jmp	loc_18382	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 169
//@ 
//@ loc_18286:				; CODE XREF: Draw3DObject+46Bj
//@ 		inc	LCnt		; int16_t
//@ ; #line	"CS3DM2.PAS" 170
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		sub	ax, 20h	; ' '   ; Integer Subtraction
//@ 		mov	llx, ax		; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		sub	ax, 20h	; ' '   ; Integer Subtraction
//@ 		mov	lly, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 171
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, lly		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, llx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 400h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	LtX, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 172
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, llx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, ica		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, lly		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, 400h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	LtY, ax		; int16_t
//@ ; #line	"CS3DM2.PAS" 173
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+8]
//@ 		sub	ax, R		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+0Ah]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 7		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	ShLevel, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 174
//@ 		cmp	ShLevel, 12h	; uint16_t
//@ 		jbe	short loc_18363	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ShLevel, 12h	; uint16_t
//@ ; #line	"CS3DM2.PAS" 175
//@ 
//@ loc_18363:				; CODE XREF: Draw3DObject+545j
//@ 		mov	ax, 1AC6h
//@ 		mov	dx, ax
//@ 		mov	ax, ShLevel	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	ShLevel, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 176
//@ 		call	CreateShadow	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 177
//@ 		call	ProcToScrShadow_Clip ; function	far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 178
//@ 		call	DrawShadowFaces	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 180
//@ 
//@ loc_18382:				; CODE XREF: Draw3DObject+46Dj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CS3DM2.PAS" 181
//@ 		jmp	loc_181FF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 185
//@ 
//@ loc_18388:				; CODE XREF: Draw3DObject+155j
//@ 					; Draw3DObject+15Fj ...
//@ 		mov	ax, cm_ofs	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Curdark	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 188
//@ 		cmp	[bp+ty], 7D0h	; int16_t
//@ 		jle	short loc_183DD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+ty]	; int16_t
//@ 		jge	short loc_183DD	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS3DM2.PAS" 189
//@ 		call	ProcToScrASM_Far ; function far	PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 190
//@ 		cmp	FCount,	3Ch ; '<' ; int16_t
//@ 		jle	short loc_183D6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, [bp+ty]	; int16_t
//@ 		cmp	ax, 0C00h	; Compare Two Operands
//@ 		jle	short loc_183D6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS3DM2.PAS" 191
//@ 		call	BuildTreeAsm_NoSort ; function far PASCAL returns void
//@ 		jmp	short loc_183DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 192
//@ 
//@ loc_183D6:				; CODE XREF: Draw3DObject+5A7j
//@ 					; Draw3DObject+5B7j
//@ 		call	BuildTreeAsm_Far ; function far	PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 193
//@ 
//@ loc_183DB:				; CODE XREF: Draw3DObject+5BEj
//@ 		jmp	short loc_183E7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 194
//@ 
//@ loc_183DD:				; CODE XREF: Draw3DObject+58Ej
//@ 					; Draw3DObject+59Bj
//@ 		call	ProcToScrASM_Clip ; function far PASCAL	returns	void
//@ 		call	BuildTreeAsm_Clip ; function far PASCAL	returns	void
//@ ; #line	"CS3DM2.PAS" 199
//@ 
//@ loc_183E7:				; CODE XREF: Draw3DObject:loc_183DBj
//@ 		cmp	ReColor, 0	; uint16_t
//@ 		jbe	short loc_1841A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS3DM2.PAS" 201
//@ 		cmp	Invisibility, 0	; bool
//@ 		jz	short loc_183FD	; Jump if Zero (ZF=1)
//@ ; #line	"CS3DM2.PAS" 202
//@ 		mov	ax, 1AEh
//@ 		mov	DrawRoutOfsTab,	ax ; uint16_t[8]
//@ 		jmp	short loc_18403	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 203
//@ 
//@ loc_183FD:				; CODE XREF: Draw3DObject+5DDj
//@ 		mov	ax, 20h	; ' '
//@ 		mov	DrawRoutOfsTab,	ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 204
//@ 
//@ loc_18403:				; CODE XREF: Draw3DObject+5E5j
//@ 		mov	ax, 1AEh
//@ 		mov	DrawRoutOfsTab+4, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 205
//@ 		mov	ax, 1AEh
//@ 		mov	DrawRoutOfsTab+6, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 206
//@ 		push	ReColor		; uint16_t
//@ 		call	CreateRecolorMap ; function far	PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 207
//@ 		jmp	short loc_1842D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 208
//@ 
//@ loc_1841A:				; CODE XREF: Draw3DObject+5D6j
//@ 		cmp	Invisibility, 0	; bool
//@ 		jz	short loc_1842D	; Jump if Zero (ZF=1)
//@ ; #line	"CS3DM2.PAS" 209
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab,	ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 210
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab+2, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 213
//@ 
//@ loc_1842D:				; CODE XREF: Draw3DObject+602j
//@ 					; Draw3DObject+609j
//@ 		call	DrawFaces	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 217
//@ 		mov	ax, 353h
//@ 		mov	DrawRoutOfsTab,	ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 218
//@ 		mov	ax, 823h
//@ 		mov	DrawRoutOfsTab+2, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 219
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab+4, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 220
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab+6, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 223
//@ 
//@ loc_1844A:				; CODE XREF: Draw3DObject+44j
//@ 					; Draw3DObject:loc_17E6Bj ...
//@ 		mov	al, 0AAh ; 'ª'
//@ 		mov	DrawMask, al	; uint8_t
//@ ; #line	"CS3DM2.PAS" 224
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	XFi, ax		; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Xfiz0, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 225
//@ 		mov	Invisibility, 0	; bool
//@ ; #line	"CS3DM2.PAS" 226
//@ 		mov	HiRot, 0	; bool
//@ ; #line	"CS3DM2.PAS" 227
//@ 		mov	HPrior,	20h ; ' ' ; int16_t
//@ ; #line	"CS3DM2.PAS" 228
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ReColor, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 229
//@ 		mov	YWrap, 0	; bool
//@ ; #line	"CS3DM2.PAS" 230
//@ 		mov	XTabUpdated, 0	; bool
//@ ; #line	"CS3DM2.PAS" 231
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ShadowZ0, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 232
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ Draw3DObject	endp
//@ 
//@ ; #line	"CS3DM2.PAS" 238
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Show3DObject	proc far		; CODE XREF: DrawItems+8CP
//@ 					; DrawItems+F3P ...
//@ 
//@ cy		= word ptr -4		; int16_t
//@ tz		= word ptr  6		; int16_t
//@ ty		= word ptr  8		; int16_t
//@ tx		= word ptr  0Ah		; int16_t
//@ P		= dword	ptr  0Ch	; TOHeader*
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS3DM2.PAS" 239
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		mov	OBJx, ax	; int16_t
//@ 		mov	ax, [bp+ty]	; int16_t
//@ 		add	ax, 60h	; '`'   ; Add
//@ 		mov	OBJy, ax	; int16_t
//@ 		mov	ax, [bp+tz]	; int16_t
//@ 		mov	OBJz, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 243
//@ 		mov	ax, word ptr [bp+P] ; TOHeader*
//@ 		mov	dx, word ptr [bp+P+2] ;	TOHeader*
//@ 		mov	word ptr POH, ax ; TOHeader*
//@ 		mov	word ptr POH+2,	dx ; TOHeader*
//@ ; #line	"CS3DM2.PAS" 244
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es:[di+4802h]
//@ 		mov	FCount,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 245
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es:[di+4800h]
//@ 		mov	VCount,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 246
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es
//@ 		mov	OHSeg, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 247
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		les	di, es:[di+4806h] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	TSeg, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 248
//@ 		mov	ax, WallH	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		mov	WallH4,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 249
//@ 		mov	ax, WinCY	; uint16_t
//@ 		mov	[bp+cy], ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 251
//@ 		cmp	InfoPage, 0	; bool
//@ 		jnz	short loc_184F8	; Jump if Not Zero (ZF=0)
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_18509	; Jump if Zero (ZF=1)
//@ 
//@ loc_184F8:				; CODE XREF: Show3DObject+6Ej
//@ 		cmp	[bp+tz], 0	; int16_t
//@ 		jge	short loc_18509	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS3DM2.PAS" 252
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		sub	ax, 12h		; Integer Subtraction
//@ 		mov	WinCY, ax	; uint16_t
//@ 		jmp	short loc_1850F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 253
//@ 
//@ loc_18509:				; CODE XREF: Show3DObject+75j
//@ 					; Show3DObject+7Bj
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 256
//@ 
//@ loc_1850F:				; CODE XREF: Show3DObject+86j
//@ 		mov	ax, TSeg	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CS3DM2.PAS" 257
//@ 		mov	al, 0AAh ; 'ª'
//@ 		mov	DrawMask, al	; uint8_t
//@ ; #line	"CS3DM2.PAS" 260
//@ 		cmp	Curdark, 0	; int16_t
//@ 		jge	short loc_18525	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 261
//@ 
//@ loc_18525:				; CODE XREF: Show3DObject+9Dj
//@ 		cmp	Curdark, 32h ; '2' ; int16_t
//@ 		jle	short loc_18532	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	Curdark, 32h ; '2' ; int16_t
//@ ; #line	"CS3DM2.PAS" 262
//@ 
//@ loc_18532:				; CODE XREF: Show3DObject+A9j
//@ 		mov	ax, cm_ofs	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Curdark	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 264
//@ 		call	RotateModelCopy	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 265
//@ 		mov	CurDH, 0EA60h	; uint16_t
//@ ; #line	"CS3DM2.PAS" 266
//@ 		call	ProcToScrASM_Clip ; function far PASCAL	returns	void
//@ ; #line	"CS3DM2.PAS" 268
//@ 		cmp	Invisibility, 0	; bool
//@ 		jz	short loc_1856C	; Jump if Zero (ZF=1)
//@ ; #line	"CS3DM2.PAS" 269
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab,	ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 270
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab+2, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 273
//@ 
//@ loc_1856C:				; CODE XREF: Show3DObject+DDj
//@ 		call	BuildTreeAsm_Clip ; function far PASCAL	returns	void
//@ ; #line	"CS3DM2.PAS" 274
//@ 		call	DrawFacesNoCheck ; function far	PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 276
//@ 		cmp	Invisibility, 0	; bool
//@ 		jz	short loc_18589	; Jump if Zero (ZF=1)
//@ ; #line	"CS3DM2.PAS" 277
//@ 		mov	ax, 353h
//@ 		mov	DrawRoutOfsTab,	ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 278
//@ 		mov	ax, 823h
//@ 		mov	DrawRoutOfsTab+2, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 280
//@ 
//@ loc_18589:				; CODE XREF: Show3DObject+FAj
//@ 		mov	ax, [bp+cy]	; int16_t
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 281
//@ 		mov	Invisibility, 0	; bool
//@ ; #line	"CS3DM2.PAS" 282
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ Show3DObject	endp
//@ 
//@ ; #line	"CS3DM2.PAS" 288
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawHi3D	proc far		; CODE XREF: PlayBrifing+3B3P
//@ 
//@ tfi		= word ptr  6		; uint16_t
//@ fi		= word ptr  8		; uint16_t
//@ tz		= word ptr  0Ah		; int16_t
//@ ty		= word ptr  0Ch		; int16_t
//@ tx		= word ptr  0Eh		; int16_t
//@ P		= dword	ptr  10h	; TOHeader*
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS3DM2.PAS" 289
//@ 		mov	ax, [bp+tfi]	; uint16_t
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
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 2000h
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	word ptr ca, ax	; real_t
//@ 		mov	word ptr ca+2, bx ; real_t
//@ 		mov	word ptr ca+4, dx ; real_t
//@ 		mov	ax, [bp+tfi]	; uint16_t
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
//@ 		mov	cx, 84h	; '„'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 2000h
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	word ptr sa, ax	; real_t
//@ 		mov	word ptr sa+2, bx ; real_t
//@ 		mov	word ptr sa+4, dx ; real_t
//@ ; #line	"CS3DM2.PAS" 290
//@ 		mov	ax, [bp+ty]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, word ptr sa	; real_t
//@ 		mov	si, word ptr sa+2 ; real_t
//@ 		mov	di, word ptr sa+4 ; real_t
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, word ptr ca	; real_t
//@ 		mov	si, word ptr ca+2 ; real_t
//@ 		mov	di, word ptr ca+4 ; real_t
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		mov	cx, 81h	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	OBJx, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 291
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, word ptr sa	; real_t
//@ 		mov	si, word ptr sa+2 ; real_t
//@ 		mov	di, word ptr sa+4 ; real_t
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+ty]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, word ptr ca	; real_t
//@ 		mov	si, word ptr ca+2 ; real_t
//@ 		mov	di, word ptr ca+4 ; real_t
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		add	ax, 60h	; '`'   ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	OBJy, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 293
//@ 		mov	ax, [bp+tz]	; int16_t
//@ 		sub	ax, ehz		; int16_t
//@ 		mov	OBJz, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 294
//@ 		mov	ax, [bp+fi]	; uint16_t
//@ 		add	ax, [bp+tfi]	; uint16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 81h	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	CurFI, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 295
//@ 		mov	ax, [bp+tx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+ty]	; int16_t
//@ 		add	ax, 190h	; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_18719	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_187F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 297
//@ 
//@ loc_18719:				; CODE XREF: DrawHi3D+17Cj
//@ 		mov	ax, word ptr [bp+P] ; TOHeader*
//@ 		or	ax, word ptr [bp+P+2] ;	TOHeader*
//@ 		jz	short loc_1872B	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jnz	short loc_1872E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 303
//@ 
//@ loc_1872B:				; CODE XREF: DrawHi3D+187j
//@ 		jmp	locret_187F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 306
//@ 
//@ loc_1872E:				; CODE XREF: DrawHi3D+191j
//@ 		mov	ax, word ptr [bp+P] ; TOHeader*
//@ 		mov	dx, word ptr [bp+P+2] ;	TOHeader*
//@ 		mov	word ptr POH, ax ; TOHeader*
//@ 		mov	word ptr POH+2,	dx ; TOHeader*
//@ ; #line	"CS3DM2.PAS" 307
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es:[di+4802h]
//@ 		mov	FCount,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 308
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es:[di+4800h]
//@ 		mov	VCount,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 309
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		mov	ax, es
//@ 		mov	OHSeg, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 310
//@ 		les	di, [bp+P]	; TOHeader*
//@ 		les	di, es:[di+4806h] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	TSeg, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 311
//@ 		mov	ax, WallH	; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		mov	WallH4,	ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 312
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		mov	cx, 3Ch	; '<'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 0F0h ; 'ð'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		mov	WallHhi, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 313
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		mov	cx, 118h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 168h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	WallWhi, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 315
//@ 		mov	ax, TSeg	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CS3DM2.PAS" 316
//@ 		call	RotateModelASM	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 319
//@ 		mov	ax, cm_ofs	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Curdark	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Curdark, ax	; int16_t
//@ ; #line	"CS3DM2.PAS" 320
//@ 		mov	CurDH, 4E20h	; uint16_t
//@ ; #line	"CS3DM2.PAS" 321
//@ 		call	ProcToScrASM_Clip_hi ; function	far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 322
//@ 		call	BuildTreeAsm_Clip ; function far PASCAL	returns	void
//@ ; #line	"CS3DM2.PAS" 323
//@ 		call	DrawFaces	; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 325
//@ 
//@ locret_187F1:				; CODE XREF: DrawHi3D+17Ej
//@ 					; DrawHi3D:loc_1872Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ DrawHi3D	endp
//@ 
//@ ; #line	"CS3DM2.PAS" 334
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Morph3d		proc far		; CODE XREF: DrawItems+78P
//@ 					; DrawItems+DFP ...
//@ 
//@ VC		= word ptr -8		; uint16_t
//@ var_6		= word ptr -6		; uint16_t
//@ sh		= word ptr -4		; uint16_t
//@ sa		= word ptr -2		; uint16_t
//@ FCnt		= word ptr  6		; uint16_t
//@ PAni		= dword	ptr  8		; TPoint3di*
//@ POH		= dword	ptr  0Ch	; TOHeader*
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS3DM2.PAS" 335
//@ 		mov	ax, word ptr [bp+POH] ;	TOHeader*
//@ 		or	ax, word ptr [bp+POH+2]	; TOHeader*
//@ 		jz	short loc_18815	; Jump if Zero (ZF=1)
//@ 		mov	ax, word ptr [bp+PAni] ; TPoint3di*
//@ 		or	ax, word ptr [bp+PAni+2] ; TPoint3di*
//@ 		jz	short loc_18815	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr [bp+POH], 0FFFFh ; TOHeader*
//@ 		jz	short loc_18815	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr [bp+PAni], 0FFFFh ; TPoint3di*
//@ 		jnz	short loc_18818	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 341
//@ 
//@ loc_18815:				; CODE XREF: Morph3d+Aj Morph3d+12j ...
//@ 		jmp	locret_188C9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 344
//@ 
//@ loc_18818:				; CODE XREF: Morph3d+1Ej
//@ 		les	di, [bp+PAni]	; TPoint3di*
//@ 		mov	ax, es
//@ 		mov	[bp+sa], ax	; uint16_t
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		mov	ax, es
//@ 		mov	[bp+sh], ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 345
//@ 		mov	ax, [bp+FCnt]	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	[bp+var_6], ax	; uint16_t
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		mov	ax, es:[di+4800h]
//@ 		mov	[bp+VC], ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 347
//@ 		push	[bp+sa]		; uint16_t
//@ 		mov	ax, [bp+var_6]	; uint16_t
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		mul	word ptr es:[di+4800h] ; Unsigned Multiplication of AL or AX
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		push	ax
//@ 		push	[bp+sh]		; uint16_t
//@ 		push	3200h
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		mov	ax, es:[di+4800h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	movsD		; function far PASCAL returns void
//@ ; #line	"CS3DM2.PAS" 350
//@ 		mov	al, byte ptr [bp+FCnt] ; uint16_t
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short locret_188C9 ; Jump if Not Below (CF=0)
//@ ; #line	"CS3DM2.PAS" 353
//@ 		mov	cx, [bp+VC]	; uint16_t
//@ ; #line	"CS3DM2.PAS" 354
//@ 		mov	ax, [bp+sh]	; uint16_t
//@ 		mov	es, ax
//@ 		mov	si, 3200h
//@ ; #line	"CS3DM2.PAS" 355
//@ 		mov	ax, [bp+sa]	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CS3DM2.PAS" 356
//@ 		mov	ax, [bp+var_6]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		mov	bx, 6
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ 		mov	di, ax
//@ ; #line	"CS3DM2.PAS" 357
//@ 
//@ loc_18896:				; CODE XREF: Morph3d+D2j
//@ 		mov	ax, fs:[di]
//@ 		add	ax, es:[si]	; Add
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		mov	es:[si], ax
//@ 		add	di, 2		; Add
//@ ; #line	"CS3DM2.PAS" 358
//@ 		mov	ax, fs:[di]
//@ 		add	ax, es:[si+2]	; Add
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		mov	es:[si+2], ax
//@ 		add	di, 2		; Add
//@ ; #line	"CS3DM2.PAS" 359
//@ 		mov	ax, fs:[di]
//@ 		add	ax, es:[si+4]	; Add
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		mov	es:[si+4], ax
//@ 		add	di, 2		; Add
//@ ; #line	"CS3DM2.PAS" 360
//@ 		add	si, 6		; Add
//@ ; #line	"CS3DM2.PAS" 361
//@ 		loop	loc_18896	; Loop while CX	!= 0
//@ ; #line	"CS3DM2.PAS" 364
//@ 
//@ locret_188C9:				; CODE XREF: Morph3d:loc_18815j
//@ 					; Morph3d+82j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ Morph3d		endp
//@ 
//@ ; #line	"CS3DM2.PAS" 369
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetFreeVert	proc far		; CODE XREF: $Cs3dm2Init+E9P
//@ 
//@ d		= word ptr -4		; uint16_t
//@ c		= word ptr -2		; uint16_t
//@ b		= word ptr  6		; uint16_t
//@ a		= word ptr  8		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS3DM2.PAS" 370
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+c],	ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 371
//@ 
//@ loc_188D6:				; CODE XREF: SetFreeVert+1Cj
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		cmp	ax, [bp+a]	; uint16_t
//@ 		jz	short loc_188E6	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		cmp	ax, [bp+b]	; uint16_t
//@ 		jnz	short loc_188EB	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_188E6:				; CODE XREF: SetFreeVert+Fj
//@ 		inc	[bp+c]		; uint16_t
//@ 		jmp	short loc_188D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 372
//@ 
//@ loc_188EB:				; CODE XREF: SetFreeVert+17j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+d],	ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 373
//@ 
//@ loc_188F0:				; CODE XREF: SetFreeVert+3Ej
//@ 		mov	ax, [bp+d]	; uint16_t
//@ 		cmp	ax, [bp+a]	; uint16_t
//@ 		jz	short loc_18908	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+d]	; uint16_t
//@ 		cmp	ax, [bp+b]	; uint16_t
//@ 		jz	short loc_18908	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+d]	; uint16_t
//@ 		cmp	ax, [bp+c]	; uint16_t
//@ 		jnz	short loc_1890D	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_18908:				; CODE XREF: SetFreeVert+29j
//@ 					; SetFreeVert+31j
//@ 		inc	[bp+d]		; uint16_t
//@ 		jmp	short loc_188F0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS3DM2.PAS" 374
//@ 
//@ loc_1890D:				; CODE XREF: SetFreeVert+39j
//@ 		mov	dx, [bp+c]	; uint16_t
//@ 		mov	ax, [bp+b]	; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+a]	; uint16_t
//@ 		shl	di, 4		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		mov	[di+12B0h], dx
//@ ; #line	"CS3DM2.PAS" 375
//@ 		mov	dx, [bp+d]	; uint16_t
//@ 		mov	ax, [bp+b]	; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+a]	; uint16_t
//@ 		shl	di, 4		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		mov	[di+12B2h], dx
//@ ; #line	"CS3DM2.PAS" 376
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ SetFreeVert	endp
//@ 
//@ ; #line	"CS3DM2.PAS" 378
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; Attributes: bp-based frame
//@ 
//@ $Cs3dm2Init	proc far		; CODE XREF: PROGRAM+2DP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS3DM2.PAS" 379
//@ 		mov	ax, 353h
//@ 		mov	dx, seg	cseg04
//@ 		mov	word ptr DrawRout, ax ;	void (*)()
//@ 		mov	word ptr DrawRout+2, dx	; void (*)()
//@ ; #line	"CS3DM2.PAS" 380
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n, ax		; int16_t
//@ 		jmp	short loc_18956	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18952:				; CODE XREF: $Cs3dm2Init+2Dj
//@ 		inc	n		; int16_t
//@ ; #line	"CS3DM2.PAS" 381
//@ 
//@ loc_18956:				; CODE XREF: $Cs3dm2Init+15j
//@ 		mov	ax, 353h
//@ 		mov	di, n		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di+0A9Ch], ax
//@ 		cmp	n, 7		; int16_t
//@ 		jnz	short loc_18952	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 382
//@ 		mov	ax, 823h
//@ 		mov	DrawRoutOfsTab+2, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 383
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab+4, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 384
//@ 		mov	ax, 4E1h
//@ 		mov	DrawRoutOfsTab+6, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 385
//@ 		mov	ax, 682h
//@ 		mov	DrawRoutOfsTab+8, ax ; uint16_t[8]
//@ ; #line	"CS3DM2.PAS" 387
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n, ax		; int16_t
//@ 		jmp	short loc_1898D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18989:				; CODE XREF: $Cs3dm2Init+63j
//@ 		inc	n		; int16_t
//@ 
//@ loc_1898D:				; CODE XREF: $Cs3dm2Init+4Cj
//@ 		mov	al, byte ptr n	; int16_t
//@ 		mov	di, n		; int16_t
//@ 		mov	[di+1358h], al
//@ 		cmp	n, 0FFh		; int16_t
//@ 		jnz	short loc_18989	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 388
//@ 		mov	ax, cs
//@ 		push	ax
//@ 		call	AllocSelector	; Call Procedure
//@ 		mov	CSCopy,	ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 389
//@ 		push	CSCopy		; uint16_t
//@ 		push	0
//@ 		push	0FA00h
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CS3DM2.PAS" 390
//@ 		mov	ShadowCount, 7	; uint16_t
//@ ; #line	"CS3DM2.PAS" 391
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ReColor, ax	; uint16_t
//@ ; #line	"CS3DM2.PAS" 392
//@ 		mov	Div_tab, 7FFFh	; uint16_t[1024]
//@ ; #line	"CS3DM2.PAS" 393
//@ 		mov	Div_tab+2, 7FFFh ; uint16_t[1024]
//@ ; #line	"CS3DM2.PAS" 394
//@ 		mov	Div_tab+4, 7FFFh ; uint16_t[1024]
//@ ; #line	"CS3DM2.PAS" 395
//@ 		mov	n, 3		; int16_t
//@ 		jmp	short loc_189E2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_189DE:				; CODE XREF: $Cs3dm2Init+C9j
//@ 		inc	n		; int16_t
//@ 
//@ loc_189E2:				; CODE XREF: $Cs3dm2Init+A1j
//@ 		mov	ax, n		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	dx, 1
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	di, n		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di+0AB0h], ax
//@ 		cmp	n, 3FFh		; int16_t
//@ 		jnz	short loc_189DE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 396
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n, ax		; int16_t
//@ 		jmp	short loc_18A11	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18A0D:				; CODE XREF: $Cs3dm2Init+FAj
//@ 		inc	n		; int16_t
//@ ; #line	"CS3DM2.PAS" 397
//@ 
//@ loc_18A11:				; CODE XREF: $Cs3dm2Init+D0j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i$0, ax		; int16_t
//@ 		jmp	short loc_18A1C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18A18:				; CODE XREF: $Cs3dm2Init+F3j
//@ 		inc	i$0		; int16_t
//@ 
//@ loc_18A1C:				; CODE XREF: $Cs3dm2Init+DBj
//@ 		push	n		; int16_t
//@ 		push	i$0		; int16_t
//@ 		call	SetFreeVert	; function far PASCAL returns void
//@ 		cmp	i$0, 3		; int16_t
//@ 		jnz	short loc_18A18	; Jump if Not Zero (ZF=0)
//@ 		cmp	n, 3		; int16_t
//@ 		jnz	short loc_18A0D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS3DM2.PAS" 398
//@ 		mov	YWrap, 0	; bool
//@ ; #line	"CS3DM2.PAS" 400
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ $Cs3dm2Init	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		align 4
