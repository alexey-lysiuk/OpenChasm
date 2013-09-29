
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

#include "csact.h"

//@ ; #line	"CSACT.PAS" 111
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ MulVectors$0	proc near		; CODE XREF: TryToGo$0+15Fp
//@ 
//@ vy		= word ptr  4		; int16_t
//@ vx		= word ptr  6		; int16_t
//@ uy		= word ptr  8		; int16_t
//@ ux		= word ptr  0Ah		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSACT.PAS" 112
//@ 		mov	cx, 0FFFFh
//@ ; #line	"CSACT.PAS" 113
//@ 		mov	ax, [bp+ux]	; int16_t
//@ ; #line	"CSACT.PAS" 114
//@ 		imul	[bp+vy]		; int16_t
//@ ; #line	"CSACT.PAS" 115
//@ 		mov	bx, dx
//@ ; #line	"CSACT.PAS" 116
//@ 		shl	ebx, 10h	; Shift	Logical	Left
//@ ; #line	"CSACT.PAS" 117
//@ 		mov	bx, ax
//@ ; #line	"CSACT.PAS" 119
//@ 		mov	ax, [bp+uy]	; int16_t
//@ ; #line	"CSACT.PAS" 120
//@ 		imul	[bp+vx]		; int16_t
//@ ; #line	"CSACT.PAS" 121
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSACT.PAS" 122
//@ 		mov	dx, ax
//@ ; #line	"CSACT.PAS" 123
//@ 		sub	ebx, edx	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 124
//@ 		js	short loc_18A6A	; Jump if Sign (SF=1)
//@ ; #line	"CSACT.PAS" 125
//@ 		mov	cx, 1
//@ ; #line	"CSACT.PAS" 127
//@ 
//@ loc_18A6A:				; CODE XREF: MulVectors$0+23j
//@ 		mov	ax, cx
//@ ; #line	"CSACT.PAS" 128
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ MulVectors$0	endp
//@ 
//@ ; #line	"CSACT.PAS" 139
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo$0	proc near		; CODE XREF: DoCheck+194p DoCheck+1BAp
//@ 
//@ XORMask		= word ptr -0Eh		; uint16_t
//@ L		= byte ptr -0Ch		; struct TLoc
//@ var_9		= word ptr -9
//@ var_7		= word ptr -7
//@ var_5		= word ptr -5
//@ var_3		= word ptr -3
//@ arg_2		= dword	ptr  6
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		mov	cx, 0Bh
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSACT.PAS" 141
//@ 		mov	ax, [bp+var_5]
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ 		mov	LWx, ax		; int16_t
//@ 		mov	ax, [bp+var_3]
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ 		mov	LWy, ax		; int16_t
//@ ; #line	"CSACT.PAS" 142
//@ 		mov	ax, LWx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLwx, ax	; int16_t
//@ 		mov	ax, LWy		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLWy, ax	; int16_t
//@ ; #line	"CSACT.PAS" 143
//@ 		mov	ax, aLwx	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+var_9]
//@ 		add	ax, [bp+var_5]	; Add
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, nhxi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jl	short loc_18AD4	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 144
//@ 		mov	Ry, 400h	; int16_t
//@ 		jmp	short loc_18B03	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 145
//@ 
//@ loc_18AD4:				; CODE XREF: TryToGo$0+5Aj
//@ 		cmp	LWy, 0		; int16_t
//@ 		jnz	short loc_18AE7	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_7]
//@ 		sub	ax, nhyi	; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ 		jmp	short loc_18B03	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 147
//@ 
//@ loc_18AE7:				; CODE XREF: TryToGo$0+69j
//@ 		mov	ax, nhxi	; int16_t
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 148
//@ 		mov	bx, LWy		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWx		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CSACT.PAS" 149
//@ 		add	ax, [bp+var_7]	; Add
//@ 		sub	ax, nhyi	; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ ; #line	"CSACT.PAS" 152
//@ 
//@ loc_18B03:				; CODE XREF: TryToGo$0+62j
//@ 					; TryToGo$0+75j
//@ 		mov	ax, aLWy	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+var_7]
//@ 		add	ax, [bp+var_3]	; Add
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, nhyi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jl	short loc_18B27	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 153
//@ 		mov	Rx, 400h	; int16_t
//@ 		jmp	short loc_18B56	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 154
//@ 
//@ loc_18B27:				; CODE XREF: TryToGo$0+ADj
//@ 		cmp	LWx, 0		; int16_t
//@ 		jnz	short loc_18B3A	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_9]
//@ 		sub	ax, nhxi	; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ 		jmp	short loc_18B56	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 156
//@ 
//@ loc_18B3A:				; CODE XREF: TryToGo$0+BCj
//@ 		mov	ax, nhyi	; int16_t
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 157
//@ 		mov	bx, LWx		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWy		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CSACT.PAS" 158
//@ 		add	ax, [bp+var_9]	; Add
//@ 		sub	ax, nhxi	; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ ; #line	"CSACT.PAS" 162
//@ 
//@ loc_18B56:				; CODE XREF: TryToGo$0+B5j
//@ 					; TryToGo$0+C8j
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
//@ ; #line	"CSACT.PAS" 163
//@ 		cmp	aLwx, 0		; int16_t
//@ 		jle	short loc_18B92	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	aLWy, 0		; int16_t
//@ 		jle	short loc_18B92	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, R$1		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	R$1, ax		; int16_t
//@ ; #line	"CSACT.PAS" 164
//@ 
//@ loc_18B92:				; CODE XREF: TryToGo$0+105j
//@ 					; TryToGo$0+10Cj
//@ 		mov	ax, R$1		; int16_t
//@ 		cmp	ax, Fr		; int16_t
//@ 		jl	short loc_18B9E	; Jump if Less (SF!=OF)
//@ 		jmp	locret_18C4D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 166
//@ 
//@ loc_18B9E:				; CODE XREF: TryToGo$0+129j
//@ 		mov	Corrected, 1	; bool
//@ ; #line	"CSACT.PAS" 167
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+XORMask], ax ; uint16_t
//@ ; #line	"CSACT.PAS" 168
//@ 		mov	al, [bp+L]	; struct TLoc
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_18BDC	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_18BDC	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 169
//@ 		mov	ax, [bp+var_5]
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+var_3]
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, nhxi	; int16_t
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, nhyi	; int16_t
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ 		push	ax
//@ 		call	MulVectors$0	; function near	PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jnz	short loc_18BDC	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+XORMask], 1	; uint16_t
//@ ; #line	"CSACT.PAS" 170
//@ 
//@ loc_18BDC:				; CODE XREF: TryToGo$0+13Dj
//@ 					; TryToGo$0+141j ...
//@ 		mov	ax, Fr		; int16_t
//@ 		sub	ax, R$1		; int16_t
//@ 		mov	R$1, ax		; int16_t
//@ ; #line	"CSACT.PAS" 171
//@ 		mov	ax, aLWy	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		imul	ax		; Signed Multiply
//@ 		mov	cx, ax
//@ 		mov	ax, aLwx	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		imul	ax		; Signed Multiply
//@ 		add	ax, cx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		call	@Sqrt$q4Real	; Sqrt(x: Real): Real
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	RSize, ax	; int16_t
//@ ; #line	"CSACT.PAS" 175
//@ 		mov	cx, RSize	; int16_t
//@ ; #line	"CSACT.PAS" 176
//@ 		mov	ax, R$1		; int16_t
//@ ; #line	"CSACT.PAS" 177
//@ 		mov	bx, LWy		; int16_t
//@ ; #line	"CSACT.PAS" 178
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSACT.PAS" 179
//@ 		idiv	RSize		; int16_t
//@ ; #line	"CSACT.PAS" 181
//@ 		cmp	[bp+XORMask], 0	; uint16_t
//@ ; #line	"CSACT.PAS" 182
//@ 		jz	short loc_18C30	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 183
//@ 		neg	ax		; Two's Complement Negation
//@ ; #line	"CSACT.PAS" 184
//@ 
//@ loc_18C30:				; CODE XREF: TryToGo$0+1BCj
//@ 		sub	nhxi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 186
//@ 		mov	ax, R$1		; int16_t
//@ ; #line	"CSACT.PAS" 187
//@ 		mov	bx, LWx		; int16_t
//@ ; #line	"CSACT.PAS" 188
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSACT.PAS" 189
//@ 		idiv	RSize		; int16_t
//@ ; #line	"CSACT.PAS" 191
//@ 		cmp	[bp+XORMask], 0	; uint16_t
//@ ; #line	"CSACT.PAS" 192
//@ 		jz	short loc_18C49	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 193
//@ 		neg	ax		; Two's Complement Negation
//@ ; #line	"CSACT.PAS" 194
//@ 
//@ loc_18C49:				; CODE XREF: TryToGo$0+1D5j
//@ 		add	nhyi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 198
//@ 
//@ locret_18C4D:				; CODE XREF: TryToGo$0+12Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ TryToGo$0	endp
//@ 
//@ ; #line	"CSACT.PAS" 221
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo2P	proc near		; CODE XREF: DoCheck+35Ep
//@ 
//@ a1		= word ptr -10h		; real_t
//@ var_E		= word ptr -0Eh
//@ var_C		= word ptr -0Ch
//@ ay		= word ptr -0Ah		; int16_t
//@ $ax		= word ptr -8		; int16_t
//@ r2		= word ptr -6		; int16_t
//@ ly		= word ptr -4		; int16_t
//@ lx		= word ptr -2		; int16_t
//@ Fr		= word ptr  6		; int16_t
//@ y2		= word ptr  8		; int16_t
//@ x2		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 222
//@ 		cmp	[bp+Fr], 50h ; 'P' ; int16_t
//@ 		jg	short loc_18C5E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	locret_18D89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 223
//@ 
//@ loc_18C5E:				; CODE XREF: TryToGo2P+8j
//@ 		mov	ax, nhxi	; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+lx], ax	; int16_t
//@ 		mov	ax, nhyi	; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+ly], ax	; int16_t
//@ ; #line	"CSACT.PAS" 225
//@ 		mov	al, byte ptr [bp+Fr] ; int16_t
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_18CEF	; Jump if Not Below (CF=0)
//@ ; #line	"CSACT.PAS" 227
//@ 		mov	ax, [bp+lx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+$ax], ax	; int16_t
//@ 		mov	ax, [bp+ly]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ay], ax	; int16_t
//@ 		push	[bp+ay]		; int16_t
//@ 		push	[bp+$ax]	; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+r2], ax	; int16_t
//@ ; #line	"CSACT.PAS" 228
//@ 		mov	ax, [bp+r2]	; int16_t
//@ 		cmp	ax, [bp+Fr]	; int16_t
//@ 		jge	short loc_18CEC	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 230
//@ 		mov	Corrected, 1	; bool
//@ ; #line	"CSACT.PAS" 231
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, nhyi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, nhxi	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jle	short loc_18CDA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 232
//@ 		push	[bp+lx]		; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mul	[bp+Fr]		; int16_t
//@ 		add	ax, [bp+x2]	; int16_t
//@ 		mov	nhxi, ax	; int16_t
//@ 		jmp	short loc_18CEC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 233
//@ 
//@ loc_18CDA:				; CODE XREF: TryToGo2P+73j
//@ 		push	[bp+ly]		; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mul	[bp+Fr]		; int16_t
//@ 		add	ax, [bp+y2]	; int16_t
//@ 		mov	nhyi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 235
//@ 
//@ loc_18CEC:				; CODE XREF: TryToGo2P+50j
//@ 					; TryToGo2P+87j
//@ 		jmp	locret_18D89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 237
//@ 
//@ loc_18CEF:				; CODE XREF: TryToGo2P+24j
//@ 		push	[bp+lx]		; int16_t
//@ 		push	[bp+ly]		; int16_t
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+r2], ax	; int16_t
//@ ; #line	"CSACT.PAS" 238
//@ 		mov	ax, [bp+r2]	; int16_t
//@ 		cmp	ax, [bp+Fr]	; int16_t
//@ 		jl	short loc_18D08	; Jump if Less (SF!=OF)
//@ 		jmp	locret_18D89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 240
//@ 
//@ loc_18D08:				; CODE XREF: TryToGo2P+B2j
//@ 		mov	Corrected, 1	; bool
//@ ; #line	"CSACT.PAS" 241
//@ 		mov	ax, [bp+r2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+Fr]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+a1], ax	; real_t
//@ 		mov	[bp+var_E], bx
//@ 		mov	[bp+var_C], dx
//@ ; #line	"CSACT.PAS" 242
//@ 		mov	ax, [bp+lx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+a1]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	nhxi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 243
//@ 		mov	ax, [bp+ly]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+a1]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	nhyi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 246
//@ 
//@ locret_18D89:				; CODE XREF: TryToGo2P+Aj
//@ 					; TryToGo2P:loc_18CECj	...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGo2P	endp
//@ 
//@ ; #line	"CSACT.PAS" 272
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo2R	proc near		; CODE XREF: DoCheck+296p DoCheck+2B3p ...
//@ 
//@ ly2		= word ptr -0Eh		; int16_t
//@ lx2		= word ptr -0Ch		; int16_t
//@ R		= word ptr -0Ah		; int16_t
//@ a1		= word ptr -8		; real_t
//@ var_6		= word ptr -6
//@ var_4		= word ptr -4
//@ TryToGo2R	= byte ptr -1		; bool
//@ y2		= word ptr  6		; int16_t
//@ x2		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 273
//@ 		mov	ax, nhxi	; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+lx2], ax	; int16_t
//@ ; #line	"CSACT.PAS" 274
//@ 		mov	ax, nhyi	; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+ly2], ax	; int16_t
//@ ; #line	"CSACT.PAS" 275
//@ 		push	[bp+lx2]	; int16_t
//@ 		push	[bp+ly2]	; int16_t
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+R],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 276
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		cmp	ax, Fr		; int16_t
//@ 		jge	short loc_18E36	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 278
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, Fr		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+a1], ax	; real_t
//@ 		mov	[bp+var_6], bx
//@ 		mov	[bp+var_4], dx
//@ ; #line	"CSACT.PAS" 279
//@ 		mov	ax, [bp+lx2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+a1]	; real_t
//@ 		mov	si, [bp+var_6]
//@ 		mov	di, [bp+var_4]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	nhxi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 280
//@ 		mov	ax, [bp+ly2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+a1]	; real_t
//@ 		mov	si, [bp+var_6]
//@ 		mov	di, [bp+var_4]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	nhyi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 282
//@ 
//@ loc_18E36:				; CODE XREF: TryToGo2R+2Bj
//@ 		mov	al, [bp+TryToGo2R] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ TryToGo2R	endp
//@ 
//@ ; #line	"CSACT.PAS" 289
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGoM	proc near		; CODE XREF: DoCheck+7Ap DoCheck+C4p
//@ 
//@ ay		= word ptr -0Ah		; int16_t
//@ $ax		= word ptr -8		; int16_t
//@ r2		= word ptr -6		; int16_t
//@ ly		= word ptr -4		; int16_t
//@ lx		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ FR		= word ptr  6		; int16_t
//@ y2		= word ptr  8		; int16_t
//@ x2		= word ptr  0Ah		; int16_t
//@ arg_A		= dword	ptr  0Eh
//@ arg_E		= dword	ptr  12h
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 290
//@ 		cmp	[bp+FR], 94h ; '”' ; int16_t
//@ 		jge	short loc_18E4B	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_18EDE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 291
//@ 
//@ loc_18E4B:				; CODE XREF: TryToGoM+9j
//@ 		mov	ax, nhxi	; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+lx], ax	; int16_t
//@ 		mov	ax, [bp+lx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+$ax], ax	; int16_t
//@ ; #line	"CSACT.PAS" 292
//@ 		mov	ax, nhyi	; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+ly], ax	; int16_t
//@ 		mov	ax, [bp+ly]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ay], ax	; int16_t
//@ ; #line	"CSACT.PAS" 293
//@ 		push	[bp+ay]		; int16_t
//@ 		push	[bp+$ax]	; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+r2], ax	; int16_t
//@ ; #line	"CSACT.PAS" 294
//@ 		mov	ax, [bp+r2]	; int16_t
//@ 		cmp	ax, [bp+FR]	; int16_t
//@ 		jge	short locret_18EDE ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 296
//@ 		mov	Corrected, 1	; bool
//@ ; #line	"CSACT.PAS" 297
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		mov	di, [bp+arg_0]
//@ 		les	di, ss:[di+arg_A] ; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		mov	di, [bp+arg_0]
//@ 		les	di, ss:[di+arg_E] ; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jle	short loc_18ECC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 298
//@ 		push	[bp+lx]		; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mul	[bp+FR]		; int16_t
//@ 		add	ax, [bp+x2]	; int16_t
//@ 		mov	nhxi, ax	; int16_t
//@ 		jmp	short locret_18EDE ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 299
//@ 
//@ loc_18ECC:				; CODE XREF: TryToGoM+79j
//@ 		push	[bp+ly]		; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mul	[bp+FR]		; int16_t
//@ 		add	ax, [bp+y2]	; int16_t
//@ 		mov	nhyi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 301
//@ 
//@ locret_18EDE:				; CODE XREF: TryToGoM+Bj TryToGoM+4Aj	...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGoM	endp
//@ 
//@ ; #line	"CSACT.PAS" 307
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DoCheck		proc near		; CODE XREF: MoveOn+C5p MoveOn+EDp ...
//@ 
//@ var_42		= dword	ptr -42h
//@ var_3E		= dword	ptr -3Eh
//@ var_3A		= word ptr -3Ah
//@ var_38		= word ptr -38h
//@ z		= word ptr -6		; int16_t
//@ i		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ arg_2		= byte ptr  6
//@ arg_8		= word ptr  0Ch
//@ arg_12		= dword	ptr  16h
//@ 
//@ 		enter	42h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 308
//@ 		mov	Corrected, 0	; bool
//@ ; #line	"CSACT.PAS" 309
//@ 		cmp	ClipMode, 0	; bool
//@ 		jz	short loc_18EF5	; Jump if Zero (ZF=1)
//@ 		jmp	locret_19259	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 311
//@ 
//@ loc_18EF5:				; CODE XREF: DoCheck+Ej
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ss:[di+arg_2], 0 ; Compare Two Operands
//@ 		jnz	short loc_18F02	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_18FAF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 313
//@ 
//@ loc_18F02:				; CODE XREF: DoCheck+1Bj
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_38], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_38]	; Compare Two Operands
//@ 		jg	short loc_18F67	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_18F18	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18F15:				; CODE XREF: DoCheck+83j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 314
//@ 
//@ loc_18F18:				; CODE XREF: DoCheck+31j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_3E+2],	di
//@ 		mov	[bp+var_3A], es
//@ ; #line	"CSACT.PAS" 315
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_18F5F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		cmp	word ptr [di+7FBEh], 30h ; '0' ; Compare Two Operands
//@ 		jge	short loc_18F5F	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 316
//@ 		les	di, [bp+var_3E+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		push	word ptr [di+7FB8h]
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGoM	; function nested near PASCAL returns void
//@ 
//@ loc_18F5F:				; CODE XREF: DoCheck+4Bj DoCheck+5Cj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_38]	; Compare Two Operands
//@ 		jnz	short loc_18F15	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 320
//@ 
//@ loc_18F67:				; CODE XREF: DoCheck+2Cj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_18F71	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18F6E:				; CODE XREF: DoCheck+CBj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_18F71:				; CODE XREF: DoCheck+8Aj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	di, [bp+arg_0]
//@ 		les	di, ss:[di+arg_12] ; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jz	short loc_18FA9	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 321
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 322
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_18FA9	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_18FA9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 323
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	0B4h ; '´'
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGoM	; function nested near PASCAL returns void
//@ 
//@ loc_18FA9:				; CODE XREF: DoCheck+9Cj DoCheck+ACj ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_18F6E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 326
//@ 
//@ loc_18FAF:				; CODE XREF: DoCheck+1Dj
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_38], ax
//@ 		mov	ax, ss:[di+n]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_38]	; Compare Two Operands
//@ 		jle	short loc_18FC9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_190B5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18FC9:				; CODE XREF: DoCheck+E2j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_18FD1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18FCE:				; CODE XREF: DoCheck+1D0j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_18FD1:				; CODE XREF: DoCheck+EAj
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jge	short loc_18FDA	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_190AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18FDA:				; CODE XREF: DoCheck+F3j
//@ 		cmp	[bp+n],	40h ; '@' ; int16_t
//@ 		jl	short loc_18FE3	; Jump if Less (SF!=OF)
//@ 		jmp	loc_190AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 327
//@ 
//@ loc_18FE3:				; CODE XREF: DoCheck+FCj
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+i]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_3A], ax
//@ 		mov	ax, ss:[di+i]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_3A]	; Compare Two Operands
//@ 		jle	short loc_18FFD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_190AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18FFD:				; CODE XREF: DoCheck+116j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_19005	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19002:				; CODE XREF: DoCheck+1C5j
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_19005:				; CODE XREF: DoCheck+11Ej
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jge	short loc_1900E	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1909F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1900E:				; CODE XREF: DoCheck+127j
//@ 		cmp	[bp+i],	40h ; '@' ; int16_t
//@ 		jl	short loc_19017	; Jump if Less (SF!=OF)
//@ 		jmp	loc_1909F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 328
//@ 
//@ loc_19017:				; CODE XREF: DoCheck+130j
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ ; #line	"CSACT.PAS" 329
//@ 		mov	al, es:[di]
//@ ; #line	"CSACT.PAS" 330
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_1907B	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_1907B	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_19079	; Jump if Zero (ZF=1)
//@ 		mov	dx, [bp+i]	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 46h ;	'F' ; Compare Two Operands
//@ 		jnb	short loc_19079	; Jump if Not Below (CF=0)
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGo$0	; function nested near PASCAL returns void
//@ 
//@ loc_19079:				; CODE XREF: DoCheck+162j DoCheck+179j
//@ 		jmp	short loc_1909F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 331
//@ 
//@ loc_1907B:				; CODE XREF: DoCheck+14Dj DoCheck+151j
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_1909F	; Jump if Below	(CF=1)
//@ 		cmp	al, 6Eh	; 'n'   ; Compare Two Operands
//@ 		ja	short loc_1909F	; Jump if Above	(CF=0 &	ZF=0)
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGo$0	; function nested near PASCAL returns void
//@ 
//@ loc_1909F:				; CODE XREF: DoCheck+129j DoCheck+132j ...
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_3A]	; Compare Two Operands
//@ 		jz	short loc_190AA	; Jump if Zero (ZF=1)
//@ 		jmp	loc_19002	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_190AA:				; CODE XREF: DoCheck+F5j DoCheck+FEj ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_38]	; Compare Two Operands
//@ 		jz	short loc_190B5	; Jump if Zero (ZF=1)
//@ 		jmp	loc_18FCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 334
//@ 
//@ loc_190B5:				; CODE XREF: DoCheck+E4j DoCheck+1CEj
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_38], ax
//@ 		mov	ax, ss:[di+n]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_38]	; Compare Two Operands
//@ 		jle	short loc_190CF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_19259	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_190CF:				; CODE XREF: DoCheck+1E8j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_190D7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_190D4:				; CODE XREF: DoCheck+374j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_190D7:				; CODE XREF: DoCheck+1F0j
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jge	short loc_190E0	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1924E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_190E0:				; CODE XREF: DoCheck+1F9j
//@ 		cmp	[bp+n],	40h ; '@' ; int16_t
//@ 		jl	short loc_190E9	; Jump if Less (SF!=OF)
//@ 		jmp	loc_1924E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 335
//@ 
//@ loc_190E9:				; CODE XREF: DoCheck+202j
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+i]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_3A], ax
//@ 		mov	ax, ss:[di+i]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_3A]	; Compare Two Operands
//@ 		jle	short loc_19103	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1924E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19103:				; CODE XREF: DoCheck+21Cj
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_1910B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19108:				; CODE XREF: DoCheck+369j
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_1910B:				; CODE XREF: DoCheck+224j
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jge	short loc_19114	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_19243	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19114:				; CODE XREF: DoCheck+22Dj
//@ 		cmp	[bp+i],	40h ; '@' ; int16_t
//@ 		jl	short loc_1911D	; Jump if Less (SF!=OF)
//@ 		jmp	loc_19243	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 336
//@ 
//@ loc_1911D:				; CODE XREF: DoCheck+236j
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_3E], di
//@ 		mov	word ptr [bp+var_3E+2],	es
//@ ; #line	"CSACT.PAS" 337
//@ 		mov	al, es:[di]
//@ ; #line	"CSACT.PAS" 338
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_1917E	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_1917E	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1917B	; Jump if Zero (ZF=1)
//@ 		mov	dx, [bp+i]	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 46h ;	'F' ; Compare Two Operands
//@ 		jnb	short loc_1917B	; Jump if Not Below (CF=0)
//@ 		les	di, [bp+var_3E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+7]
//@ 		push	word ptr es:[di+9]
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGo2R	; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ 
//@ loc_1917B:				; CODE XREF: DoCheck+26Ej DoCheck+285j
//@ 		jmp	loc_19243	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 339
//@ 
//@ loc_1917E:				; CODE XREF: DoCheck+259j DoCheck+25Dj
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_191AD	; Jump if Below	(CF=1)
//@ 		cmp	al, 6Eh	; 'n'   ; Compare Two Operands
//@ 		ja	short loc_191AD	; Jump if Above	(CF=0 &	ZF=0)
//@ 		les	di, [bp+var_3E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+7]
//@ 		push	word ptr es:[di+9]
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGo2R	; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ 		les	di, [bp+var_3E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGo2R	; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ 		jmp	loc_19243	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 340
//@ 
//@ loc_191AD:				; CODE XREF: DoCheck+29Ej DoCheck+2A2j
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnb	short loc_191B4	; Jump if Not Below (CF=0)
//@ 		jmp	loc_19243	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_191B4:				; CODE XREF: DoCheck+2CDj
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_191BB	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_19243	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_191BB:				; CODE XREF: DoCheck+2D4j
//@ 		les	di, [bp+var_3E]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_42], di
//@ 		mov	word ptr [bp+var_42+2],	es
//@ ; #line	"CSACT.PAS" 342
//@ 		les	di, [bp+var_3E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+z],	ax	; int16_t
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 343
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+arg_8]
//@ 		add	ax, 320h	; Add
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_42]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		add	ax, [bp+z]	; int16_t
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jle	short loc_19243	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+arg_8]
//@ 		add	ax, 680h	; Add
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_42]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		add	ax, [bp+z]	; int16_t
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jge	short loc_19243	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 344
//@ 		les	di, [bp+var_3E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74AEh]
//@ 		add	ax, 50h	; 'P'   ; Add
//@ 		push	ax
//@ 		mov	di, [bp+arg_0]
//@ 		push	di
//@ 		call	TryToGo2P	; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 345
//@ 
//@ loc_19243:				; CODE XREF: DoCheck+22Fj DoCheck+238j ...
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_3A]	; Compare Two Operands
//@ 		jz	short loc_1924E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_19108	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1924E:				; CODE XREF: DoCheck+1FBj DoCheck+204j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_38]	; Compare Two Operands
//@ 		jz	short locret_19259 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_190D4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 348
//@ 
//@ locret_19259:				; CODE XREF: DoCheck+10j DoCheck+1EAj	...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ DoCheck		endp
//@ 
//@ ; #line	"CSACT.PAS" 351
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MoveOn		proc far		; CODE XREF: MoveServerPlayers+549P
//@ 					; CorrectPlayerPosition+50EP ...
//@ 
//@ var_10		= word ptr -10h
//@ ddy		= word ptr -0Eh		; int16_t
//@ ddx		= word ptr -0Ch		; int16_t
//@ s		= word ptr -0Ah		; int16_t
//@ i		= word ptr -8		; int16_t
//@ n		= word ptr -6		; int16_t
//@ hmy		= word ptr -4		; int16_t
//@ hmx		= word ptr -2		; int16_t
//@ dy		= word ptr  8		; int16_t
//@ $dx		= word ptr  0Ah		; int16_t
//@ hy		= dword	ptr  0Eh	; int16_t
//@ hx		= dword	ptr  12h	; int16_t
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 352
//@ 		mov	ax, [bp+dy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+$dx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2Ch	; ','
//@ 		idiv	cx		; Signed Divide
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 353
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+s],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 354
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jle	short loc_19296	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_19342	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19296:				; CODE XREF: MoveOn+34j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_1929E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1929B:				; CODE XREF: MoveOn+E2j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSACT.PAS" 356
//@ 
//@ loc_1929E:				; CODE XREF: MoveOn+3Cj
//@ 		mov	ax, [bp+$dx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+s]		; int16_t
//@ 		mov	[bp+ddx], ax	; int16_t
//@ 		mov	ax, [bp+dy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+s]		; int16_t
//@ 		mov	[bp+ddy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 357
//@ 		les	di, [bp+hx]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+ddx]	; int16_t
//@ 		mov	nhxi, ax	; int16_t
//@ 		les	di, [bp+hy]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+ddy]	; int16_t
//@ 		mov	nhyi, ax	; int16_t
//@ ; #line	"CSACT.PAS" 358
//@ 		mov	ax, [bp+ddx]	; int16_t
//@ 		sub	[bp+$dx], ax	; int16_t
//@ 		mov	ax, [bp+ddy]	; int16_t
//@ 		sub	[bp+dy], ax	; int16_t
//@ 		dec	[bp+s]		; int16_t
//@ ; #line	"CSACT.PAS" 360
//@ 		cmp	nhxi, 214h	; int16_t
//@ 		jge	short loc_192E7	; Jump if Greater or Equal (SF=OF)
//@ 		mov	nhxi, 214h	; int16_t
//@ ; #line	"CSACT.PAS" 361
//@ 
//@ loc_192E7:				; CODE XREF: MoveOn+82j
//@ 		cmp	nhxi, 3DECh	; int16_t
//@ 		jle	short loc_192F5	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	nhxi, 3DECh	; int16_t
//@ ; #line	"CSACT.PAS" 362
//@ 
//@ loc_192F5:				; CODE XREF: MoveOn+90j
//@ 		cmp	nhyi, 214h	; int16_t
//@ 		jge	short loc_19303	; Jump if Greater or Equal (SF=OF)
//@ 		mov	nhyi, 214h	; int16_t
//@ ; #line	"CSACT.PAS" 363
//@ 
//@ loc_19303:				; CODE XREF: MoveOn+9Ej
//@ 		cmp	nhyi, 3DECh	; int16_t
//@ 		jle	short loc_19311	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	nhyi, 3DECh	; int16_t
//@ ; #line	"CSACT.PAS" 365
//@ 
//@ loc_19311:				; CODE XREF: MoveOn+ACj
//@ 		mov	al, byte ptr nhxi+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+hmx], ax	; int16_t
//@ 		mov	al, byte ptr nhyi+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+hmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 366
//@ 		push	bp
//@ 		call	DoCheck		; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 367
//@ 		mov	ax, nhxi	; int16_t
//@ 		les	di, [bp+hx]	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, nhyi	; int16_t
//@ 		les	di, [bp+hy]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 368
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jz	short loc_19342	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1929B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 369
//@ 
//@ loc_19342:				; CODE XREF: MoveOn+36j MoveOn+E0j
//@ 		cmp	Corrected, 0	; bool
//@ 		jz	short loc_1934D	; Jump if Zero (ZF=1)
//@ 		push	bp
//@ 		call	DoCheck		; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 370
//@ 
//@ loc_1934D:				; CODE XREF: MoveOn+EAj
//@ 		cmp	Corrected, 0	; bool
//@ 		jz	short loc_19358	; Jump if Zero (ZF=1)
//@ 		push	bp
//@ 		call	DoCheck		; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 371
//@ 
//@ loc_19358:				; CODE XREF: MoveOn+F5j
//@ 		cmp	Corrected, 0	; bool
//@ 		jz	short loc_19363	; Jump if Zero (ZF=1)
//@ 		push	bp
//@ 		call	DoCheck		; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 372
//@ 
//@ loc_19363:				; CODE XREF: MoveOn+100j
//@ 		cmp	Corrected, 0	; bool
//@ 		jz	short locret_1936E ; Jump if Zero (ZF=1)
//@ 		push	bp
//@ 		call	DoCheck		; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 373
//@ 
//@ locret_1936E:				; CODE XREF: MoveOn+10Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	14h		; Return Far from Procedure
//@ MoveOn		endp
//@ 
//@ ; #line	"CSACT.PAS" 377
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetMFloorZ	proc far		; CODE XREF: CheckTelePorts+21DP
//@ 					; DoGame+8D1P ...
//@ 
//@ zc		= dword	ptr  6		; int16_t
//@ z		= dword	ptr  0Ah	; int16_t
//@ R		= word ptr  0Eh		; int16_t
//@ my		= word ptr  10h		; int16_t
//@ mx		= word ptr  12h		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSACT.PAS" 378
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	[bp+R],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 379
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 380
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		add	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		add	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 381
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		add	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 382
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		add	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 383
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 384
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		add	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 385
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 386
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		add	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 387
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, [bp+R]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 390
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, 80h	; '€'   ; Integer Subtraction
//@ 		mov	al, ah
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, byte ptr [bp+mx+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, FloorZHi	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+zc]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 391
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		add	ax, 56h	; 'V'   ; Add
//@ 		mov	al, ah
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	al, ah
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, FloorZHi	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+zc]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 392
//@ 		push	word ptr es:[di]
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		add	ax, 56h	; 'V'   ; Add
//@ 		mov	al, ah
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		mov	al, ah
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, FloorZHi	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+zc]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 393
//@ 		les	di, [bp+z]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		mov	es:[di], ax
//@ 		les	di, [bp+zc]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 394
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ GetMFloorZ	endp
//@ 
//@ ; #line	"CSACT.PAS" 404
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo$1	proc near		; CODE XREF: MS_WallCheck+108p
//@ 					; MS_WallCheck+14Bp
//@ 
//@ var_12		= byte ptr -12h
//@ L		= byte ptr -0Ch		; struct TLoc
//@ var_9		= word ptr -9
//@ var_7		= word ptr -7
//@ var_5		= word ptr -5
//@ var_3		= word ptr -3
//@ arg_0		= word ptr  4
//@ FR		= word ptr  6		; int16_t
//@ arg_4		= dword	ptr  8
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+L]	; struct TLoc
//@ 		lds	si, [bp+arg_4]	; Load Full Pointer to DS:xx
//@ 		mov	cx, 0Bh
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSACT.PAS" 406
//@ 		mov	ax, [bp+var_5]
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ 		mov	LWx, ax		; int16_t
//@ ; #line	"CSACT.PAS" 407
//@ 		mov	ax, [bp+var_3]
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ 		mov	LWy, ax		; int16_t
//@ ; #line	"CSACT.PAS" 408
//@ 		mov	ax, LWx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLwx, ax	; int16_t
//@ ; #line	"CSACT.PAS" 409
//@ 		mov	ax, LWy		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLWy, ax	; int16_t
//@ ; #line	"CSACT.PAS" 410
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
//@ 		jl	short loc_19646	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 411
//@ 		mov	Ry, 400h	; int16_t
//@ 		jmp	short loc_19675	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 412
//@ 
//@ loc_19646:				; CODE XREF: TryToGo$1+5Fj
//@ 		cmp	LWy, 0		; int16_t
//@ 		jnz	short loc_19659	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_7]
//@ 		sub	ax, rry		; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ 		jmp	short loc_19675	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 414
//@ 
//@ loc_19659:				; CODE XREF: TryToGo$1+6Ej
//@ 		mov	ax, rrx		; int16_t
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 415
//@ 		mov	bx, LWy		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWx		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CSACT.PAS" 416
//@ 		add	ax, [bp+var_7]	; Add
//@ 		sub	ax, rry		; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ ; #line	"CSACT.PAS" 419
//@ 
//@ loc_19675:				; CODE XREF: TryToGo$1+67j
//@ 					; TryToGo$1+7Aj
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
//@ 		jl	short loc_1969E	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 420
//@ 		mov	Rx, 400h	; int16_t
//@ 		jmp	short loc_196CD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 421
//@ 
//@ loc_1969E:				; CODE XREF: TryToGo$1+B7j
//@ 		cmp	LWx, 0		; int16_t
//@ 		jnz	short loc_196B1	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_9]
//@ 		sub	ax, rrx		; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ 		jmp	short loc_196CD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 423
//@ 
//@ loc_196B1:				; CODE XREF: TryToGo$1+C6j
//@ 		mov	ax, rry		; int16_t
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 424
//@ 		mov	bx, LWx		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWy		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CSACT.PAS" 425
//@ 		add	ax, [bp+var_9]	; Add
//@ 		sub	ax, rrx		; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ ; #line	"CSACT.PAS" 428
//@ 
//@ loc_196CD:				; CODE XREF: TryToGo$1+BFj
//@ 					; TryToGo$1+D2j
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
//@ ; #line	"CSACT.PAS" 429
//@ 		mov	ax, R$1		; int16_t
//@ 		cmp	ax, [bp+FR]	; int16_t
//@ 		jge	short locret_196F7 ; Jump if Greater or	Equal (SF=OF)
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_12],	1
//@ ; #line	"CSACT.PAS" 431
//@ 
//@ locret_196F7:				; CODE XREF: TryToGo$1+110j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGo$1	endp
//@ 
//@ ; #line	"CSACT.PAS" 436
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo2B$0	proc near		; CODE XREF: MS_WallCheck+11Ep
//@ 					; MS_WallCheck+15Dp
//@ 
//@ var_12		= byte ptr -12h
//@ ay		= word ptr -4		; int16_t
//@ $ax		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ Fr		= word ptr  6		; int16_t
//@ y2		= word ptr  8		; int16_t
//@ x2		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 437
//@ 		mov	ax, rrx		; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+$ax], ax	; int16_t
//@ ; #line	"CSACT.PAS" 438
//@ 		mov	ax, rry		; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ay], ax	; int16_t
//@ ; #line	"CSACT.PAS" 439
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ss:[di+var_12],	0 ; Compare Two	Operands
//@ 		jnz	short loc_19739	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+ay]		; int16_t
//@ 		push	[bp+$ax]	; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, [bp+Fr]	; int16_t
//@ 		jl	short loc_19739	; Jump if Less (SF!=OF)
//@ 		mov	al, 0
//@ 		jmp	short loc_1973B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19739:				; CODE XREF: TryToGo2B$0+28j
//@ 					; TryToGo2B$0+38j
//@ 		mov	al, 1
//@ 
//@ loc_1973B:				; CODE XREF: TryToGo2B$0+3Cj
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_12],	al
//@ ; #line	"CSACT.PAS" 440
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGo2B$0	endp
//@ 
//@ ; #line	"CSACT.PAS" 444
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo2P$0	proc near		; CODE XREF: MS_WallCheck+200p
//@ 
//@ var_12		= byte ptr -12h
//@ ay		= word ptr -4		; int16_t
//@ $ax		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ Fr		= word ptr  6		; int16_t
//@ y2		= word ptr  8		; int16_t
//@ x2		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 445
//@ 		mov	al, byte ptr [bp+Fr] ; int16_t
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_19756	; Jump if Not Below (CF=0)
//@ 		add	[bp+Fr], 80h ; '€' ; int16_t
//@ ; #line	"CSACT.PAS" 446
//@ 
//@ loc_19756:				; CODE XREF: TryToGo2P$0+9j
//@ 		mov	ax, rrx		; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+$ax], ax	; int16_t
//@ ; #line	"CSACT.PAS" 447
//@ 		mov	ax, rry		; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ay], ax	; int16_t
//@ ; #line	"CSACT.PAS" 448
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ss:[di+var_12],	0 ; Compare Two	Operands
//@ 		jnz	short loc_19790	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+ay]		; int16_t
//@ 		push	[bp+$ax]	; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, [bp+Fr]	; int16_t
//@ 		jl	short loc_19790	; Jump if Less (SF!=OF)
//@ 		mov	al, 0
//@ 		jmp	short loc_19792	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19790:				; CODE XREF: TryToGo2P$0+34j
//@ 					; TryToGo2P$0+44j
//@ 		mov	al, 1
//@ 
//@ loc_19792:				; CODE XREF: TryToGo2P$0+48j
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_12],	al
//@ ; #line	"CSACT.PAS" 449
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGo2P$0	endp
//@ 
//@ ; #line	"CSACT.PAS" 453
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ MS_WallCheck	proc far		; CODE XREF: NotFreeForMonster+B9P
//@ 
//@ var_1E		= dword	ptr -1Eh
//@ var_1A		= dword	ptr -1Ah
//@ var_16		= word ptr -16h
//@ var_14		= word ptr -14h
//@ blow		= byte ptr -12h		; bool
//@ b		= byte ptr -11h		; bool
//@ rmy		= word ptr -10h		; int16_t
//@ rmx		= word ptr -0Eh		; int16_t
//@ i		= word ptr -0Ch		; int16_t
//@ n		= word ptr -0Ah		; int16_t
//@ z		= word ptr -4		; int16_t
//@ MS_WallCheck	= byte ptr -1		; bool
//@ FCheck		= byte ptr  6		; bool
//@ fr		= word ptr  8		; int16_t
//@ h		= word ptr  0Ah		; int16_t
//@ _rrz		= word ptr  0Ch		; int16_t
//@ _rry		= word ptr  0Eh		; int16_t
//@ _rrx		= word ptr  10h		; int16_t
//@ 
//@ 		enter	1Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 454
//@ 		mov	[bp+blow], 0	; bool
//@ 		mov	ax, [bp+_rrx]	; int16_t
//@ 		mov	rrx, ax		; int16_t
//@ 		mov	ax, [bp+_rry]	; int16_t
//@ 		mov	rry, ax		; int16_t
//@ ; #line	"CSACT.PAS" 455
//@ 		mov	al, byte ptr rrx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+rmx], ax	; int16_t
//@ 		mov	al, byte ptr rry+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+rmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 456
//@ 		mov	ax, [bp+rmx]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_14], ax
//@ 		mov	ax, [bp+rmx]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jle	short loc_197D6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_199C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_197D6:				; CODE XREF: MS_WallCheck+34j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_197DE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_197DB:				; CODE XREF: MS_WallCheck+222j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_197DE:				; CODE XREF: MS_WallCheck+3Cj
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jge	short loc_197E7	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_199B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_197E7:				; CODE XREF: MS_WallCheck+45j
//@ 		cmp	[bp+n],	40h ; '@' ; int16_t
//@ 		jl	short loc_197F0	; Jump if Less (SF!=OF)
//@ 		jmp	loc_199B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 457
//@ 
//@ loc_197F0:				; CODE XREF: MS_WallCheck+4Ej
//@ 		mov	ax, [bp+rmy]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_16], ax
//@ 		mov	ax, [bp+rmy]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_16]	; Compare Two Operands
//@ 		jle	short loc_19805	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_199B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19805:				; CODE XREF: MS_WallCheck+63j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_1980D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1980A:				; CODE XREF: MS_WallCheck+217j
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_1980D:				; CODE XREF: MS_WallCheck+6Bj
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jge	short loc_19816	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_199AC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19816:				; CODE XREF: MS_WallCheck+74j
//@ 		cmp	[bp+i],	40h ; '@' ; int16_t
//@ 		jl	short loc_1981F	; Jump if Less (SF!=OF)
//@ 		jmp	loc_199AC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 458
//@ 
//@ loc_1981F:				; CODE XREF: MS_WallCheck+7Dj
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 460
//@ 		mov	al, es:[di]
//@ ; #line	"CSACT.PAS" 461
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jnb	short loc_19842	; Jump if Not Below (CF=0)
//@ 		jmp	loc_198C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19842:				; CODE XREF: MS_WallCheck+A0j
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		ja	short loc_198C1	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	[bp+FCheck], 0	; bool
//@ 		jnz	short loc_1985D	; Jump if Not Zero (ZF=0)
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_198BE	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 462
//@ 
//@ loc_1985D:				; CODE XREF: MS_WallCheck+ADj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_198BE	; Jump if Zero (ZF=1)
//@ 		mov	dx, [bp+i]	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 50h ;	'P' ; Compare Two Operands
//@ 		jnb	short loc_198BE	; Jump if Not Below (CF=0)
//@ ; #line	"CSACT.PAS" 464
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+fr]	; int16_t
//@ 		add	ax, 18h		; Add
//@ 		push	ax
//@ 		push	bp
//@ 		call	TryToGo$1	; function nested near PASCAL returns void
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	ax, [bp+fr]	; int16_t
//@ 		add	ax, 18h		; Add
//@ 		push	ax
//@ 		push	bp
//@ 		call	TryToGo2B$0	; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 465
//@ 
//@ loc_198BE:				; CODE XREF: MS_WallCheck+BEj
//@ 					; MS_WallCheck+D2j ...
//@ 		jmp	loc_199A0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 466
//@ 
//@ loc_198C1:				; CODE XREF: MS_WallCheck+A2j
//@ 					; MS_WallCheck+A7j
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_19900	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_19900	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 467
//@ 		mov	al, [bp+blow]	; bool
//@ 		mov	[bp+b],	al	; bool
//@ ; #line	"CSACT.PAS" 468
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+fr]		; int16_t
//@ 		push	bp
//@ 		call	TryToGo$1	; function nested near PASCAL returns void
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	[bp+fr]		; int16_t
//@ 		push	bp
//@ 		call	TryToGo2B$0	; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 469
//@ 		jmp	loc_199A0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 470
//@ 
//@ loc_19900:				; CODE XREF: MS_WallCheck+126j
//@ 					; MS_WallCheck+12Aj
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnb	short loc_19907	; Jump if Not Below (CF=0)
//@ 		jmp	loc_199A0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19907:				; CODE XREF: MS_WallCheck+165j
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_1990E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_199A0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 472
//@ 
//@ loc_1990E:				; CODE XREF: MS_WallCheck+16Cj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+z],	ax	; int16_t
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 473
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_1E], di
//@ 		mov	word ptr [bp+var_1E+2],	es
//@ ; #line	"CSACT.PAS" 474
//@ 		cmp	word ptr es:[di+2], 0 ;	Compare	Two Operands
//@ 		jz	short loc_19949	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+2], 0FEh ; 'þ' ; Compare Two Operands
//@ 		jnz	short loc_199A0	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_19949:				; CODE XREF: MS_WallCheck+1A2j
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+6], 0FFFFh ; Compare Two Operands
//@ 		jl	short loc_199A0	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 475
//@ 		mov	ax, [bp+_rrz]	; int16_t
//@ 		add	ax, [bp+h]	; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+12h]
//@ 		add	ax, [bp+z]	; int16_t
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jg	short loc_199A0	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, es:[di+14h]
//@ 		add	ax, [bp+z]	; int16_t
//@ 		cmp	ax, [bp+_rrz]	; int16_t
//@ 		jl	short loc_199A0	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+12h]
//@ 		add	ax, [bp+z]	; int16_t
//@ 		cmp	ax, 0F00h	; Compare Two Operands
//@ 		jge	short loc_199A0	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 476
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74AEh]
//@ 		add	ax, 28h	; '('   ; Add
//@ 		push	ax
//@ 		push	bp
//@ 		call	TryToGo2P$0	; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 479
//@ 
//@ loc_199A0:				; CODE XREF: MS_WallCheck:loc_198BEj
//@ 					; MS_WallCheck+160j ...
//@ 		cmp	[bp+blow], 0	; bool
//@ 		jz	short loc_199AC	; Jump if Zero (ZF=1)
//@ 		mov	[bp+MS_WallCheck], 1 ; bool
//@ 		jmp	short loc_199C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 480
//@ 
//@ loc_199AC:				; CODE XREF: MS_WallCheck+76j
//@ 					; MS_WallCheck+7Fj ...
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_16]	; Compare Two Operands
//@ 		jz	short loc_199B7	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1980A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_199B7:				; CODE XREF: MS_WallCheck+47j
//@ 					; MS_WallCheck+50j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jz	short loc_199C2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_197DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 481
//@ 
//@ loc_199C2:				; CODE XREF: MS_WallCheck+36j
//@ 					; MS_WallCheck+220j
//@ 		mov	[bp+MS_WallCheck], 0 ; bool
//@ ; #line	"CSACT.PAS" 482
//@ 
//@ loc_199C6:				; CODE XREF: MS_WallCheck+20Dj
//@ 		mov	al, [bp+MS_WallCheck] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ MS_WallCheck	endp
//@ 
//@ ; #line	"CSACT.PAS" 488
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns unsigned	char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ LocUsed		proc near		; CODE XREF: NotFreeForMonster+21p
//@ 
//@ var_8		= dword	ptr -8
//@ var_3		= byte ptr -3
//@ l		= byte ptr -2		; uint8_t
//@ LocUsed		= byte ptr -1		; uint8_t
//@ tg		= word ptr  4		; int16_t
//@ h		= word ptr  6		; int16_t
//@ z		= word ptr  8		; int16_t
//@ cmy		= word ptr  0Ah		; int16_t
//@ cmx		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 489
//@ 		mov	[bp+LocUsed], 0	; uint8_t
//@ ; #line	"CSACT.PAS" 490
//@ 		mov	al, byte ptr MCount ; uint16_t
//@ 		mov	[bp+var_3], al
//@ 		mov	al, 1
//@ 		cmp	al, [bp+var_3]	; Compare Two Operands
//@ 		jbe	short loc_199E5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_19A8C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_199E5:				; CODE XREF: LocUsed+13j
//@ 		mov	[bp+l],	al	; uint8_t
//@ 		jmp	short loc_199ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_199EA:				; CODE XREF: LocUsed+BCj
//@ 		inc	[bp+l]		; uint8_t
//@ ; #line	"CSACT.PAS" 491
//@ 
//@ loc_199ED:				; CODE XREF: LocUsed+1Bj
//@ 		mov	al, [bp+l]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, n$0		; int16_t
//@ 		jnz	short loc_199FB	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_19A81	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_199FB:				; CODE XREF: LocUsed+29j
//@ 		mov	al, [bp+l]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		cmp	ax, [bp+tg]	; int16_t
//@ 		jz	short loc_19A81	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 492
//@ 		mov	al, [bp+l]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSACT.PAS" 493
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_19A81	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+cmx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+cmy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 0DCh ; 'Ü'  ; Compare Two Operands
//@ 		jge	short loc_19A81	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 494
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 495
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	ax, es:[di+20h]	; Add
//@ 		cmp	ax, [bp+z]	; int16_t
//@ 		jl	short loc_19A81	; Jump if Less (SF!=OF)
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		add	ax, [bp+h]	; int16_t
//@ 		cmp	ax, es:[di+20h]	; Compare Two Operands
//@ 		jl	short loc_19A81	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 496
//@ 		mov	al, es:[di+0Ah]
//@ 		mov	[bp+LocUsed], al ; uint8_t
//@ 		jmp	short loc_19A8C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19A81:				; CODE XREF: LocUsed+2Bj LocUsed+39j ...
//@ 		mov	al, [bp+l]	; uint8_t
//@ 		cmp	al, [bp+var_3]	; Compare Two Operands
//@ 		jz	short loc_19A8C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_199EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 497
//@ 
//@ loc_19A8C:				; CODE XREF: LocUsed+15j LocUsed+B2j ...
//@ 		mov	al, [bp+LocUsed] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ LocUsed		endp
//@ 
//@ ; #line	"CSACT.PAS" 501
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns unsigned	char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ LocUsedTar	proc near		; CODE XREF: NotFreeForMonster+43p
//@ 
//@ var_6		= dword	ptr -6
//@ LocUsedTar	= byte ptr -1		; uint8_t
//@ tg		= word ptr  4		; int16_t
//@ h		= word ptr  6		; int16_t
//@ z		= word ptr  8		; int16_t
//@ cmy		= word ptr  0Ah		; int16_t
//@ cmx		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 502
//@ 		mov	[bp+LocUsedTar], 0 ; uint8_t
//@ ; #line	"CSACT.PAS" 503
//@ 		cmp	[bp+tg], 64h ; 'd' ; int16_t
//@ 		jl	short loc_19B19	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 504
//@ 		mov	ax, [bp+tg]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSACT.PAS" 505
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_19B19	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+cmx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+cmy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 0B4h ; '´'  ; Compare Two Operands
//@ 		jge	short loc_19B19	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 506
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 507
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	ax, es:[di+20h]	; Add
//@ 		cmp	ax, [bp+z]	; int16_t
//@ 		jl	short loc_19B19	; Jump if Less (SF!=OF)
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		add	ax, [bp+h]	; int16_t
//@ 		cmp	ax, es:[di+20h]	; Compare Two Operands
//@ 		jg	short loc_19B19	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSACT.PAS" 508
//@ 		mov	al, es:[di+0Ah]
//@ 		mov	[bp+LocUsedTar], al ; uint8_t
//@ ; #line	"CSACT.PAS" 509
//@ 
//@ loc_19B19:				; CODE XREF: LocUsedTar+Cj
//@ 					; LocUsedTar+28j ...
//@ 		mov	al, [bp+LocUsedTar] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ LocUsedTar	endp
//@ 
//@ ; #line	"CSACT.PAS" 516
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ NotFreeForMonster proc far		; CODE XREF: CorrectMonstersPosition+177P
//@ 					; AnimateExternal+14DP	...
//@ 
//@ zc		= word ptr -8		; int16_t
//@ z		= word ptr -6		; int16_t
//@ n		= word ptr -4		; int16_t
//@ b		= byte ptr -2		; bool
//@ NotFreeForMonster= byte	ptr -1		; bool
//@ MC		= byte ptr  6		; bool
//@ Pc		= byte ptr  8		; bool
//@ Target		= word ptr  0Ah		; int16_t
//@ CRad		= word ptr  0Ch		; int16_t
//@ Radius		= word ptr  0Eh		; int16_t
//@ h		= word ptr  10h		; int16_t
//@ z0		= word ptr  12h		; int16_t
//@ mz		= word ptr  14h		; int16_t
//@ my		= word ptr  16h		; int16_t
//@ mx		= word ptr  18h		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 517
//@ 		mov	[bp+b],	0	; bool
//@ ; #line	"CSACT.PAS" 519
//@ 		cmp	[bp+MC], 0	; bool
//@ 		jz	short loc_19B50	; Jump if Zero (ZF=1)
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+z0]		; int16_t
//@ 		mov	ax, [bp+h]	; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	[bp+Target]	; int16_t
//@ 		call	LocUsed		; function near	PASCAL returns unsigned	char 'Byte'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jbe	short loc_19B4B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_19B4B:				; CODE XREF: NotFreeForMonster+28j
//@ 		mov	[bp+b],	al	; bool
//@ 		jmp	short loc_19B70	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 520
//@ 
//@ loc_19B50:				; CODE XREF: NotFreeForMonster+Cj
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+z0]		; int16_t
//@ 		mov	ax, [bp+h]	; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	[bp+Target]	; int16_t
//@ 		call	LocUsedTar	; function near	PASCAL returns unsigned	char 'Byte'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jbe	short loc_19B6D	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_19B6D:				; CODE XREF: NotFreeForMonster+4Aj
//@ 		mov	[bp+b],	al	; bool
//@ ; #line	"CSACT.PAS" 521
//@ 
//@ loc_19B70:				; CODE XREF: NotFreeForMonster+2Ej
//@ 		cmp	[bp+b],	0	; bool
//@ 		jnz	short loc_19BBE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 523
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+Radius]	; int16_t
//@ 		lea	di, [bp+z]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+zc]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetMFloorZ	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 524
//@ 		mov	ax, [bp+mz]	; int16_t
//@ 		add	ax, 18h		; Add
//@ 		cmp	ax, [bp+z]	; int16_t
//@ 		jge	short loc_19B9F	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+b],	1	; bool
//@ 		jmp	short loc_19BBE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 525
//@ 
//@ loc_19B9F:				; CODE XREF: NotFreeForMonster+77j
//@ 		cmp	[bp+mz], 50h ; 'P' ; int16_t
//@ 		jge	short loc_19BBE	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+h]	; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		add	ax, [bp+z0]	; int16_t
//@ 		add	ax, dx		; Add
//@ 		cmp	ax, [bp+zc]	; int16_t
//@ 		jle	short loc_19BBE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+b],	1	; bool
//@ ; #line	"CSACT.PAS" 528
//@ 
//@ loc_19BBE:				; CODE XREF: NotFreeForMonster+54j
//@ 					; NotFreeForMonster+7Dj ...
//@ 		cmp	[bp+b],	0	; bool
//@ 		jnz	short loc_19BE1	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		mov	ax, [bp+mz]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	[bp+h]		; int16_t
//@ 		push	[bp+Radius]	; int16_t
//@ 		push	1
//@ 		call	MS_WallCheck	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		mov	[bp+b],	al	; bool
//@ ; #line	"CSACT.PAS" 529
//@ 
//@ loc_19BE1:				; CODE XREF: NotFreeForMonster+A2j
//@ 		cmp	[bp+b],	0	; bool
//@ 		jnz	short loc_19C3C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 530
//@ 		cmp	[bp+Pc], 0	; bool
//@ 		jz	short loc_19C3C	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 531
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_19BF7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19BF4:				; CODE XREF: NotFreeForMonster+11Aj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_19BF7:				; CODE XREF: NotFreeForMonster+D2j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 532
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_19C36	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_19C36	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 533
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, [bp+CRad]	; int16_t
//@ 		jge	short loc_19C36	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+b],	1	; bool
//@ 
//@ loc_19C36:				; CODE XREF: NotFreeForMonster+E5j
//@ 					; NotFreeForMonster+ECj ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_19BF4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 534
//@ 
//@ loc_19C3C:				; CODE XREF: NotFreeForMonster+C5j
//@ 					; NotFreeForMonster+CBj
//@ 		mov	al, [bp+b]	; bool
//@ 		mov	[bp+NotFreeForMonster],	al ; bool
//@ ; #line	"CSACT.PAS" 535
//@ 		mov	al, [bp+NotFreeForMonster] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	14h		; Return Far from Procedure
//@ NotFreeForMonster endp
//@ 
//@ ; #line	"CSACT.PAS" 556
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StartLoading	proc far		; CODE XREF: LoadLevel+4P LoadGame+7P
//@ 
//@ var_4		= word ptr -4
//@ y0		= word ptr -2		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 557
//@ 		cmp	LevelN,	63h ; 'c' ; int16_t
//@ 		jnz	short loc_19C57	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_19D0C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 559
//@ 
//@ loc_19C57:				; CODE XREF: StartLoading+9j
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ 		assume es:nothing
//@ ; #line	"CSACT.PAS" 560
//@ 		mov	bx, word ptr VideoH ; int32_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSACT.PAS" 561
//@ 		mov	edi, [bx-6E84h]
//@ ; #line	"CSACT.PAS" 562
//@ 		mov	bx, 28C6h
//@ ; #line	"CSACT.PAS" 563
//@ 		dec	edi		; Decrement by 1
//@ ; #line	"CSACT.PAS" 565
//@ 
//@ loc_19C6D:				; CODE XREF: StartLoading+2Fj
//@ 		mov	al, es:[edi]
//@ ; #line	"CSACT.PAS" 566
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSACT.PAS" 567
//@ 		mov	es:[edi], al
//@ ; #line	"CSACT.PAS" 568
//@ 		dec	edi		; Decrement by 1
//@ ; #line	"CSACT.PAS" 569
//@ 		jnz	short loc_19C6D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 572
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, 28h	; '('   ; Integer Subtraction
//@ 		mov	[bp+y0], ax	; uint16_t
//@ ; #line	"CSACT.PAS" 573
//@ 		mov	LoadPos, 2	; uint16_t
//@ ; #line	"CSACT.PAS" 574
//@ 		mov	ax, LoadingH	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_4], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jg	short loc_19D07	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_19CA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19C9E:				; CODE XREF: StartLoading+BCj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSACT.PAS" 575
//@ 
//@ loc_19CA2:				; CODE XREF: StartLoading+53j
//@ 		les	di, Loading	; void*
//@ 		push	es
//@ 		mov	ax, LoadingW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+y0]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, [di-6E84h]
//@ 		mov	bx, [di-6E82h]
//@ 		mov	ax, LoadingW	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, LoadingW	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovsEW		; function far PASCAL returns void
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jnz	short loc_19C9E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 578
//@ 
//@ loc_19D07:				; CODE XREF: StartLoading+4Ej
//@ 		call	ShowVideoBuffer	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 579
//@ 
//@ locret_19D0C:				; CODE XREF: StartLoading+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ StartLoading	endp
//@ 
//@ ; #line	"CSACT.PAS" 583
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ NextLoading	proc far		; CODE XREF: UpLoad3dObjects:loc_1BEE2P
//@ 					; ReloadResources+199P	...
//@ 
//@ var_8		= word ptr -8
//@ w		= word ptr -6		; uint16_t
//@ n		= word ptr -4		; uint16_t
//@ y0		= word ptr -2		; uint16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 584
//@ 		cmp	LoadPos, 0	; uint16_t
//@ 		jnz	short loc_19D1C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_19DBB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 585
//@ 
//@ loc_19D1C:				; CODE XREF: NextLoading+9j
//@ 		add	LoadPos, 4	; uint16_t
//@ ; #line	"CSACT.PAS" 589
//@ 		cmp	LoadPos, 96h ; '–' ; uint16_t
//@ 		jbe	short loc_19D2F	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	LoadPos, 96h ; '–' ; uint16_t
//@ ; #line	"CSACT.PAS" 591
//@ 
//@ loc_19D2F:				; CODE XREF: NextLoading+19j
//@ 		mov	ax, LoadPos	; uint16_t
//@ 		mul	LoadingW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 96h	; '–'
//@ 		div	cx		; Unsigned Divide
//@ 		mov	[bp+w],	ax	; uint16_t
//@ ; #line	"CSACT.PAS" 592
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, 28h	; '('   ; Integer Subtraction
//@ 		mov	[bp+y0], ax	; uint16_t
//@ ; #line	"CSACT.PAS" 593
//@ 		mov	ax, LoadingH	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_8], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		ja	short loc_19DB6	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_19D61	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19D5E:				; CODE XREF: NextLoading+A6j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSACT.PAS" 594
//@ 
//@ loc_19D61:				; CODE XREF: NextLoading+4Ej
//@ 		les	di, Loading	; void*
//@ 		push	es
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		add	ax, LoadingH	; uint16_t
//@ 		mul	LoadingW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+y0]	; uint16_t
//@ 		add	ax, [bp+n]	; uint16_t
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	cx, [di-6E84h]
//@ 		mov	bx, [di-6E82h]
//@ 		mov	ax, LoadingW	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovsEW		; function far PASCAL returns void
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jnz	short loc_19D5E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 597
//@ 
//@ loc_19DB6:				; CODE XREF: NextLoading+49j
//@ 		call	ShowVideoBuffer	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 598
//@ 
//@ locret_19DBB:				; CODE XREF: NextLoading+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ NextLoading	endp
//@ 
//@ ; #line	"CSACT.PAS" 644
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetLandHeight	proc far		; CODE XREF: ReinitPlayer+123P
//@ 					; ExpandMonster+121P ...
//@ 
//@ var_1E		= dword	ptr -1Eh
//@ var_1A		= dword	ptr -1Ah
//@ var_16		= word ptr -16h
//@ var_14		= word ptr -14h
//@ my		= word ptr -12h		; int16_t
//@ mx		= word ptr -10h		; int16_t
//@ y		= word ptr -0Eh		; int16_t
//@ x		= word ptr -0Ch		; int16_t
//@ _loz		= word ptr -0Ah		; int16_t
//@ _hiz		= word ptr -8		; int16_t
//@ lz		= word ptr -6		; int16_t
//@ hz		= word ptr -4		; int16_t
//@ r		= word ptr -2		; int16_t
//@ ceilz		= dword	ptr  6		; int16_t
//@ landz		= dword	ptr  0Ah	; int16_t
//@ FR		= word ptr  0Eh		; int16_t
//@ arg_B		= byte ptr  11h
//@ arg_D		= byte ptr  13h
//@ 
//@ 		enter	1Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 645
//@ 		mov	[bp+hz], 1000h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+lz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 649
//@ 		mov	al, [bp+arg_D]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+mx], ax	; int16_t
//@ 		mov	al, [bp+arg_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+my], ax	; int16_t
//@ ; #line	"CSACT.PAS" 650
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_14], ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jle	short loc_19DF0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_19F3E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19DF0:				; CODE XREF: GetLandHeight+2Ej
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_19DF8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19DF5:				; CODE XREF: GetLandHeight+17Ej
//@ 		inc	[bp+y]		; int16_t
//@ ; #line	"CSACT.PAS" 651
//@ 
//@ loc_19DF8:				; CODE XREF: GetLandHeight+36j
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_16], ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_16]	; Compare Two Operands
//@ 		jle	short loc_19E0D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_19F33	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19E0D:				; CODE XREF: GetLandHeight+4Bj
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_19E15	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19E12:				; CODE XREF: GetLandHeight+173j
//@ 		inc	[bp+x]		; int16_t
//@ ; #line	"CSACT.PAS" 652
//@ 
//@ loc_19E15:				; CODE XREF: GetLandHeight+53j
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 653
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnb	short loc_19E38	; Jump if Not Below (CF=0)
//@ 		jmp	loc_19F28	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19E38:				; CODE XREF: GetLandHeight+76j
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_19E3F	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_19F28	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 654
//@ 
//@ loc_19E3F:				; CODE XREF: GetLandHeight+7Dj
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_1E], di
//@ 		mov	word ptr [bp+var_1E+2],	es
//@ ; #line	"CSACT.PAS" 655
//@ 		cmp	word ptr es:[di+2], 0 ;	Compare	Two Operands
//@ 		jz	short loc_19E6F	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+2], 0FEh ; 'þ' ; Compare Two Operands
//@ 		jz	short loc_19E6F	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+6], 0FFFEh ; Compare Two Operands
//@ 		jz	short loc_19E6F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_19F28	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19E6F:				; CODE XREF: GetLandHeight+9Ej
//@ 					; GetLandHeight+A6j ...
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di], 0 ; Compare Two Operands
//@ 		jg	short loc_19E7B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_19F28	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 657
//@ 
//@ loc_19E7B:				; CODE XREF: GetLandHeight+B9j
//@ 		mov	al, es:[di]
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_19EA9	; Jump if Not Below (CF=0)
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+12h]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+10h]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+r],	ax	; int16_t
//@ 		jmp	short loc_19EC4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 658
//@ 
//@ loc_19EA9:				; CODE XREF: GetLandHeight+C3j
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+12h]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+10h]	; Integer Subtraction
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+r],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 659
//@ 
//@ loc_19EC4:				; CODE XREF: GetLandHeight+EAj
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+FR]	; int16_t
//@ 		cmp	ax, [bp+r]	; int16_t
//@ 		jle	short loc_19F28	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 661
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+r],	ax	; int16_t
//@ 		mov	ax, [bp+r]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+r],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 662
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		add	ax, [bp+r]	; int16_t
//@ 		mov	[bp+_loz], ax	; int16_t
//@ 		mov	ax, es:[di+14h]
//@ 		add	ax, [bp+r]	; int16_t
//@ 		mov	[bp+_hiz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 663
//@ 		cmp	[bp+_hiz], 800h	; int16_t
//@ 		jge	short loc_19F13	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+_hiz]	; int16_t
//@ 		cmp	ax, [bp+lz]	; int16_t
//@ 		jle	short loc_19F13	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+_hiz]	; int16_t
//@ 		mov	[bp+lz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 664
//@ 
//@ loc_19F13:				; CODE XREF: GetLandHeight+146j
//@ 					; GetLandHeight+14Ej
//@ 		cmp	[bp+_loz], 800h	; int16_t
//@ 		jle	short loc_19F28	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+_loz]	; int16_t
//@ 		cmp	ax, [bp+hz]	; int16_t
//@ 		jge	short loc_19F28	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+_loz]	; int16_t
//@ 		mov	[bp+hz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 666
//@ 
//@ loc_19F28:				; CODE XREF: GetLandHeight+78j
//@ 					; GetLandHeight+7Fj ...
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, [bp+var_16]	; Compare Two Operands
//@ 		jz	short loc_19F33	; Jump if Zero (ZF=1)
//@ 		jmp	loc_19E12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19F33:				; CODE XREF: GetLandHeight+4Dj
//@ 					; GetLandHeight+171j
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jz	short loc_19F3E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_19DF5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 667
//@ 
//@ loc_19F3E:				; CODE XREF: GetLandHeight+30j
//@ 					; GetLandHeight+17Cj
//@ 		mov	ax, [bp+lz]	; int16_t
//@ 		les	di, [bp+landz]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 668
//@ 		mov	ax, [bp+hz]	; int16_t
//@ 		sub	ax, 780h	; Integer Subtraction
//@ 		les	di, [bp+ceilz]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 669
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ GetLandHeight	endp
//@ 
//@ ; #line	"CSACT.PAS" 674
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetFloorLoHi	proc near		; CODE XREF: InitZPositions+59p
//@ 
//@ var_1A		= dword	ptr -1Ah
//@ var_16		= dword	ptr -16h
//@ var_12		= word ptr -12h
//@ var_10		= word ptr -10h
//@ my		= word ptr -0Eh		; int16_t
//@ mx		= word ptr -0Ch		; int16_t
//@ y		= word ptr -0Ah		; int16_t
//@ x		= word ptr -8		; int16_t
//@ lz		= word ptr -6		; int16_t
//@ hz		= word ptr -4		; int16_t
//@ r		= word ptr -2		; int16_t
//@ ceilz		= dword	ptr  4		; int16_t
//@ landz		= dword	ptr  8		; int16_t
//@ arg_9		= byte ptr  0Dh
//@ arg_B		= byte ptr  0Fh
//@ 
//@ 		enter	1Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 675
//@ 		mov	[bp+hz], 1000h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+lz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 677
//@ 		mov	al, [bp+arg_B]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+mx], ax	; int16_t
//@ 		mov	al, [bp+arg_9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+my], ax	; int16_t
//@ ; #line	"CSACT.PAS" 678
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jle	short loc_19F8A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1A084	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19F8A:				; CODE XREF: GetFloorLoHi+2Ej
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_19F92	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19F8F:				; CODE XREF: GetFloorLoHi+12Aj
//@ 		inc	[bp+y]		; int16_t
//@ ; #line	"CSACT.PAS" 679
//@ 
//@ loc_19F92:				; CODE XREF: GetFloorLoHi+36j
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jle	short loc_19FA7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1A079	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19FA7:				; CODE XREF: GetFloorLoHi+4Bj
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_19FAF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19FAC:				; CODE XREF: GetFloorLoHi+11Fj
//@ 		inc	[bp+x]		; int16_t
//@ ; #line	"CSACT.PAS" 680
//@ 
//@ loc_19FAF:				; CODE XREF: GetFloorLoHi+53j
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSACT.PAS" 681
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jnb	short loc_19FD2	; Jump if Not Below (CF=0)
//@ 		jmp	loc_1A06E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_19FD2:				; CODE XREF: GetFloorLoHi+76j
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_19FD9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_1A06E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 682
//@ 
//@ loc_19FD9:				; CODE XREF: GetFloorLoHi+7Dj
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 683
//@ 		cmp	word ptr es:[di+6], 0FFFFh ; Compare Two Operands
//@ 		jge	short loc_1A06E	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	word ptr es:[di], 0 ; Compare Two Operands
//@ 		jle	short loc_1A06E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 685
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+0Eh]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+0Ch]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+r],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 686
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		add	ax, 8		; Add
//@ 		cmp	ax, [bp+r]	; int16_t
//@ 		jle	short loc_1A048	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	word ptr es:[di+14h], 780h ; Compare Two Operands
//@ 		jge	short loc_1A048	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+14h]
//@ 		cmp	ax, [bp+lz]	; int16_t
//@ 		jle	short loc_1A048	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+14h]
//@ 		mov	[bp+lz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 687
//@ 
//@ loc_1A048:				; CODE XREF: GetFloorLoHi+D7j
//@ 					; GetFloorLoHi+DFj ...
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		add	ax, 40h	; '@'   ; Add
//@ 		cmp	ax, [bp+r]	; int16_t
//@ 		jle	short loc_1A06E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	word ptr es:[di+12h], 780h ; Compare Two Operands
//@ 		jle	short loc_1A06E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+12h]
//@ 		cmp	ax, [bp+hz]	; int16_t
//@ 		jge	short loc_1A06E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+12h]
//@ 		mov	[bp+hz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 688
//@ 
//@ loc_1A06E:				; CODE XREF: GetFloorLoHi+78j
//@ 					; GetFloorLoHi+7Fj ...
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jz	short loc_1A079	; Jump if Zero (ZF=1)
//@ 		jmp	loc_19FAC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A079:				; CODE XREF: GetFloorLoHi+4Dj
//@ 					; GetFloorLoHi+11Dj
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jz	short loc_1A084	; Jump if Zero (ZF=1)
//@ 		jmp	loc_19F8F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 689
//@ 
//@ loc_1A084:				; CODE XREF: GetFloorLoHi+30j
//@ 					; GetFloorLoHi+128j
//@ 		mov	ax, [bp+lz]	; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		les	di, [bp+landz]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 690
//@ 		mov	ax, [bp+hz]	; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		les	di, [bp+ceilz]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 691
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ch		; Return Near from Procedure
//@ GetFloorLoHi	endp
//@ 
//@ ; #line	"CSACT.PAS" 696
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns unsigned	char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ GetFloorZ	proc near		; CODE XREF: InitZPositions+AFp
//@ 
//@ var_1A		= dword	ptr -1Ah
//@ var_16		= dword	ptr -16h
//@ var_12		= word ptr -12h
//@ var_10		= word ptr -10h
//@ my		= word ptr -0Eh		; int16_t
//@ mx		= word ptr -0Ch		; int16_t
//@ y		= word ptr -0Ah		; int16_t
//@ x		= word ptr -8		; int16_t
//@ lz		= word ptr -6		; int16_t
//@ GetFloorZ	= byte ptr -1		; uint8_t
//@ arg_1		= byte ptr  5
//@ arg_3		= byte ptr  7
//@ 
//@ 		enter	1Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 697
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+lz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 699
//@ 		mov	al, [bp+arg_3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+mx], ax	; int16_t
//@ 		mov	al, [bp+arg_1]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+my], ax	; int16_t
//@ ; #line	"CSACT.PAS" 700
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jle	short loc_1A0CE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1A1A1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A0CE:				; CODE XREF: GetFloorZ+29j
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_1A0D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A0D3:				; CODE XREF: GetFloorZ+FEj
//@ 		inc	[bp+y]		; int16_t
//@ ; #line	"CSACT.PAS" 701
//@ 
//@ loc_1A0D6:				; CODE XREF: GetFloorZ+31j
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jle	short loc_1A0EB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1A196	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A0EB:				; CODE XREF: GetFloorZ+46j
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_1A0F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A0F0:				; CODE XREF: GetFloorZ+F3j
//@ 		inc	[bp+x]		; int16_t
//@ ; #line	"CSACT.PAS" 702
//@ 
//@ loc_1A0F3:				; CODE XREF: GetFloorZ+4Ej
//@ 		imul	ax, [bp+y], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSACT.PAS" 703
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_1A18B	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_1A18B	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 704
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 705
//@ 		cmp	word ptr es:[di+6], 0FFFFh ; Compare Two Operands
//@ 		jge	short loc_1A18B	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	word ptr es:[di], 0 ; Compare Two Operands
//@ 		jle	short loc_1A18B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	word ptr es:[di+2], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_1A18B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 706
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+6]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+4]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		add	ax, 10h		; Add
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jle	short loc_1A18B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 707
//@ 		cmp	word ptr es:[di+14h], 780h ; Compare Two Operands
//@ 		jge	short loc_1A18B	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 708
//@ 		mov	ax, es:[di+14h]
//@ 		cmp	ax, [bp+lz]	; int16_t
//@ 		jle	short loc_1A18B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+14h]
//@ 		mov	[bp+lz], ax	; int16_t
//@ 
//@ loc_1A18B:				; CODE XREF: GetFloorZ+71j
//@ 					; GetFloorZ+75j ...
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jz	short loc_1A196	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1A0F0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A196:				; CODE XREF: GetFloorZ+48j
//@ 					; GetFloorZ+F1j
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jz	short loc_1A1A1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1A0D3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 710
//@ 
//@ loc_1A1A1:				; CODE XREF: GetFloorZ+2Bj
//@ 					; GetFloorZ+FCj
//@ 		mov	ax, [bp+lz]	; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	[bp+GetFloorZ],	al ; uint8_t
//@ ; #line	"CSACT.PAS" 711
//@ 		mov	al, [bp+GetFloorZ] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ GetFloorZ	endp
//@ 
//@ ; #line	"CSACT.PAS" 743
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MakeTeleEffect	proc far		; CODE XREF: CheckTelePorts+96P
//@ 					; CheckTelePorts+183P ...
//@ 
//@ var_A		= dword	ptr -0Ah
//@ var_6		= dword	ptr -6
//@ tmp		= byte ptr -2		; int16_t
//@ pl		= word ptr  6		; int16_t
//@ T		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 745
//@ 		imul	ax, [bp+T], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSACT.PAS" 747
//@ 		push	54h ; 'T'
//@ 		mov	al, byte ptr [bp+T] ; int16_t
//@ 		push	ax
//@ 		push	[bp+pl]		; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 748
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		push	ax
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 11h		; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 749
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		push	ax
//@ 		push	6
//@ 		push	26h ; '&'
//@ 		push	2Eh ; '.'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 750
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		push	6
//@ 		push	26h ; '&'
//@ 		push	2Eh ; '.'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 751
//@ 		cmp	[bp+pl], 0FFFFh	; int16_t
//@ 		jnz	short loc_1A262	; Jump if Not Zero (ZF=0)
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 11h		; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	locret_1A333	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 754
//@ 
//@ loc_1A262:				; CODE XREF: MakeTeleEffect+8Fj
//@ 		mov	ax, [bp+pl]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jz	short loc_1A26E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1A30F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A26E:				; CODE XREF: MakeTeleEffect+B8j
//@ 		imul	di, [bp+pl], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CSACT.PAS" 756
//@ 		mov	BShadeLev, 20h ; ' ' ; int16_t
//@ ; #line	"CSACT.PAS" 757
//@ 		imul	ax, [bp+T], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSACT.PAS" 758
//@ 		imul	ax, [bp+T], 0Ah	; int16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+6]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSACT.PAS" 759
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+16h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CSACT.PAS" 760
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1A2DA	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 761
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 0Eh		; Shift	Logical	Left
//@ 		mov	HFi, ax		; uint16_t
//@ ; #line	"CSACT.PAS" 762
//@ 
//@ loc_1A2DA:				; CODE XREF: MakeTeleEffect+11Dj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
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
//@ ; #line	"CSACT.PAS" 763
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 11h		; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 764
//@ 		jmp	short locret_1A333 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 765
//@ 
//@ loc_1A30F:				; CODE XREF: MakeTeleEffect+BAj
//@ 		imul	di, [bp+pl], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 11h		; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 768
//@ 
//@ locret_1A333:				; CODE XREF: MakeTeleEffect+AEj
//@ 					; MakeTeleEffect+15Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ MakeTeleEffect	endp
//@ 
//@ ; #line	"CSACT.PAS" 772
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddMine		proc far		; CODE XREF: DoGame+D45P
//@ 					; ExecuteEvent+51P
//@ 
//@ var_4		= dword	ptr -4
//@ owner		= word ptr  6		; int16_t
//@ my		= word ptr  8		; int16_t
//@ mx		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 773
//@ 		cmp	MnCount, 0Fh	; uint16_t
//@ 		jbe	short loc_1A35A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 775
//@ 		mov	MnCount, 0Fh	; uint16_t
//@ ; #line	"CSACT.PAS" 776
//@ 		mov	di, (offset MinesList.mnx+0Ah) ; struct	TMine[16]
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset MinesList ; struct TMine[16]
//@ 		push	ds
//@ 		push	di
//@ 		push	960h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 779
//@ 
//@ loc_1A35A:				; CODE XREF: AddMine+9j
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_1A374	; Jump if Zero (ZF=1)
//@ 		push	4Dh ; 'M'
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 781
//@ 
//@ loc_1A374:				; CODE XREF: AddMine+28j
//@ 		inc	MnCount		; uint16_t
//@ ; #line	"CSACT.PAS" 782
//@ 		imul	di, MnCount, 0Ah ; uint16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSACT.PAS" 784
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSACT.PAS" 785
//@ 		mov	ax, es:[di+2]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ 		mov	ax, es:[di+6]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSACT.PAS" 786
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, [bp+owner]	; int16_t
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSACT.PAS" 788
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ AddMine		endp
//@ 
//@ ; #line	"CSACT.PAS" 793
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddSepPart	proc far		; CODE XREF: ExecuteEvent+11CP
//@ 					; AddDeadPlayer+1D0P ...
//@ 
//@ var_A		= dword	ptr -0Ah
//@ vy		= word ptr -6		; int16_t
//@ vx		= word ptr -4		; int16_t
//@ vv		= word ptr -2		; int16_t
//@ Color		= word ptr  6		; int16_t
//@ pfi		= word ptr  8		; int16_t
//@ PartN		= word ptr  0Ah		; int16_t
//@ MType		= word ptr  0Ch		; int16_t
//@ Power		= word ptr  0Eh		; int16_t
//@ py		= word ptr  10h		; int16_t
//@ px		= word ptr  12h		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 794
//@ 		cmp	SCount,	1Fh	; uint16_t
//@ 		jbe	short loc_1A3FB	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 796
//@ 		mov	SCount,	1Fh	; uint16_t
//@ ; #line	"CSACT.PAS" 797
//@ 		mov	di, (offset SepList.FTime+16h) ; struct	TSepPart[32]
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset SepList ; struct TSepPart[32]
//@ 		push	ds
//@ 		push	di
//@ 		push	2AAh
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 799
//@ 
//@ loc_1A3FB:				; CODE XREF: AddSepPart+9j
//@ 		inc	SCount		; uint16_t
//@ ; #line	"CSACT.PAS" 801
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 64h	; 'd'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+vy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 802
//@ 		mov	di, [bp+pfi]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 64h	; 'd'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+vx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 804
//@ 		cmp	[bp+PartN], 0	; int16_t
//@ 		jnz	short loc_1A43B	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+vy], ax	; int16_t
//@ 		jmp	short loc_1A443	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A43B:				; CODE XREF: AddSepPart+57j
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+vx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 806
//@ 
//@ loc_1A443:				; CODE XREF: AddSepPart+61j
//@ 		push	70h ; 'p'
//@ 		mov	ax, [bp+MType]	; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, [bp+PartN]	; int16_t
//@ 		push	ax
//@ 		push	[bp+pfi]	; int16_t
//@ 		push	[bp+px]		; int16_t
//@ 		push	[bp+py]		; int16_t
//@ 		mov	ax, [bp+Color]	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, [bp+Power]	; int16_t
//@ 		push	ax
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 808
//@ 		imul	di, SCount, 16h	; uint16_t
//@ 		add	di, 0B940h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CSACT.PAS" 810
//@ 		mov	ax, [bp+px]	; int16_t
//@ 		add	ax, [bp+vx]	; int16_t
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSACT.PAS" 811
//@ 		mov	ax, [bp+py]	; int16_t
//@ 		add	ax, [bp+vy]	; int16_t
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSACT.PAS" 812
//@ 		cmp	[bp+PartN], 2	; int16_t
//@ 		jnz	short loc_1A4B2	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+MType]	; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FBAh]
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+0Ch], ax
//@ 		jmp	short loc_1A4D3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 813
//@ 
//@ loc_1A4B2:				; CODE XREF: AddSepPart+BBj
//@ 		mov	ax, [bp+MType]	; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FBAh]
//@ 		sub	ax, 3		; Integer Subtraction
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSACT.PAS" 814
//@ 
//@ loc_1A4D3:				; CODE XREF: AddSepPart+D8j
//@ 		cmp	[bp+PartN], 2	; int16_t
//@ 		jl	short loc_1A4DC	; Jump if Less (SF!=OF)
//@ 		jmp	loc_1A591	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 816
//@ 
//@ loc_1A4DC:				; CODE XREF: AddSepPart+FFj
//@ 		push	80h ; '€'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		sub	ax, 40h	; '@'   ; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+pfi], ax	; int16_t
//@ ; #line	"CSACT.PAS" 817
//@ 		cmp	[bp+pfi], 0	; int16_t
//@ 		jge	short loc_1A505	; Jump if Greater or Equal (SF=OF)
//@ 		add	[bp+pfi], 400h	; int16_t
//@ 		jmp	short loc_1A511	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 818
//@ 
//@ loc_1A505:				; CODE XREF: AddSepPart+124j
//@ 		cmp	[bp+pfi], 400h	; int16_t
//@ 		jl	short loc_1A511	; Jump if Less (SF!=OF)
//@ 		sub	[bp+pfi], 400h	; int16_t
//@ ; #line	"CSACT.PAS" 819
//@ 
//@ loc_1A511:				; CODE XREF: AddSepPart+12Bj
//@ 					; AddSepPart+132j
//@ 		push	1Eh
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+Power]	; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSACT.PAS" 820
//@ 		push	7
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		mul	[bp+Power]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 70h	; 'p'
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 3		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSACT.PAS" 821
//@ 		push	7
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		mul	[bp+Power]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 70h	; 'p'
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 3		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSACT.PAS" 822
//@ 		jmp	loc_1A637	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 824
//@ 
//@ loc_1A591:				; CODE XREF: AddSepPart+101j
//@ 		push	1Eh
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+Power]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, 5Ah	; 'Z'   ; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSACT.PAS" 825
//@ 		push	200h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		sub	ax, 100h	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+pfi], ax	; int16_t
//@ ; #line	"CSACT.PAS" 826
//@ 		cmp	[bp+pfi], 0	; int16_t
//@ 		jge	short loc_1A5DC	; Jump if Greater or Equal (SF=OF)
//@ 		add	[bp+pfi], 400h	; int16_t
//@ 		jmp	short loc_1A5E8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 827
//@ 
//@ loc_1A5DC:				; CODE XREF: AddSepPart+1FBj
//@ 		cmp	[bp+pfi], 400h	; int16_t
//@ 		jl	short loc_1A5E8	; Jump if Less (SF!=OF)
//@ 		sub	[bp+pfi], 400h	; int16_t
//@ ; #line	"CSACT.PAS" 829
//@ 
//@ loc_1A5E8:				; CODE XREF: AddSepPart+202j
//@ 					; AddSepPart+209j
//@ 		mov	ax, [bp+Power]	; int16_t
//@ 		add	ax, 14h		; Add
//@ 		mov	[bp+vv], ax	; int16_t
//@ ; #line	"CSACT.PAS" 830
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+vv]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSACT.PAS" 831
//@ 		mov	di, [bp+pfi]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+vv]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSACT.PAS" 834
//@ 
//@ loc_1A637:				; CODE XREF: AddSepPart+1B6j
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+14h], ax
//@ 		add	word ptr es:[di+14h], 0C000h ; Add
//@ ; #line	"CSACT.PAS" 835
//@ 		mov	ax, [bp+MType]	; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, [bp+PartN]	; int16_t
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSACT.PAS" 836
//@ 		mov	al, byte ptr [bp+Color]	; int16_t
//@ 		mov	es:[di+7], al
//@ ; #line	"CSACT.PAS" 837
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+2], ax
//@ 		mov	byte ptr es:[di+6], 0
//@ ; #line	"CSACT.PAS" 839
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ AddSepPart	endp
//@ 
//@ ; #line	"CSACT.PAS" 843
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddAmmoBag	proc far		; CODE XREF: ExecuteEvent+2BP
//@ 					; AddDeadPlayer+C1P ...
//@ 
//@ var_4		= dword	ptr -4
//@ owner		= word ptr  6		; int16_t
//@ bz		= word ptr  8		; int16_t
//@ by		= word ptr  0Ah		; int16_t
//@ $bx		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 844
//@ 		cmp	AmCount, 3Eh ; '>' ; uint16_t
//@ 		jbe	short loc_1A683	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_1A80D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 845
//@ 
//@ loc_1A683:				; CODE XREF: AddAmmoBag+9j
//@ 		push	41h ; 'A'
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+$bx]	; int16_t
//@ 		push	[bp+by]		; int16_t
//@ 		push	[bp+bz]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 846
//@ 		add	[bp+$bx], 30h ;	'0' ; int16_t
//@ 		add	[bp+by], 30h ; '0' ; int16_t
//@ ; #line	"CSACT.PAS" 848
//@ 		inc	AmCount		; uint16_t
//@ ; #line	"CSACT.PAS" 849
//@ 		imul	ax, AmCount, 1Fh ; uint16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSACT.PAS" 851
//@ 		push	[bp+$bx]	; int16_t
//@ 		push	[bp+by]		; int16_t
//@ 		push	0
//@ 		add	di, 8		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		call	GetLandHeight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 853
//@ 		cmp	[bp+bz], 0C80h	; int16_t
//@ 		jle	short loc_1A6DC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+bz], 0C80h	; int16_t
//@ ; #line	"CSACT.PAS" 854
//@ 
//@ loc_1A6DC:				; CODE XREF: AddAmmoBag+60j
//@ 		mov	ax, [bp+$bx]	; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+by]	; int16_t
//@ 		mov	es:[di+2], ax
//@ 		mov	ax, [bp+bz]	; int16_t
//@ 		mov	es:[di+4], ax
//@ 		mov	word ptr es:[di+6], 28h	; '('
//@ ; #line	"CSACT.PAS" 855
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Ah], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSACT.PAS" 857
//@ 		cmp	[bp+owner], 0FFFFh ; int16_t
//@ 		jnz	short loc_1A70E	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1A80D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 858
//@ 
//@ loc_1A70E:				; CODE XREF: AddAmmoBag+94j
//@ 		cmp	[bp+owner], 7	; int16_t
//@ 		jg	short loc_1A717	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1A7AC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 860
//@ 
//@ loc_1A717:				; CODE XREF: AddAmmoBag+9Dj
//@ 		add	di, 11h		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	8
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 861
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+19h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Bh], ax
//@ ; #line	"CSACT.PAS" 862
//@ 		mov	byte ptr es:[di+10h], 0
//@ 		mov	word ptr es:[di+1Dh], 2
//@ ; #line	"CSACT.PAS" 863
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSACT.PAS" 864
//@ 		mov	ax, [bp+owner]	; int16_t
//@ ; #line	"CSACT.PAS" 865
//@ 		cmp	ax, 67h	; 'g'   ; Compare Two Operands
//@ 		jnz	short loc_1A755	; Jump if Not Zero (ZF=0)
//@ 		mov	byte ptr es:[di+12h], 5
//@ 		jmp	short loc_1A7AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 866
//@ 
//@ loc_1A755:				; CODE XREF: AddAmmoBag+D7j
//@ 		cmp	ax, 6Ah	; 'j'   ; Compare Two Operands
//@ 		jnz	short loc_1A764	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+12h], 5
//@ 		jmp	short loc_1A7AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 867
//@ 
//@ loc_1A764:				; CODE XREF: AddAmmoBag+E3j
//@ 		cmp	ax, 6Bh	; 'k'   ; Compare Two Operands
//@ 		jnz	short loc_1A773	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+16h], 3
//@ 		jmp	short loc_1A7AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 868
//@ 
//@ loc_1A773:				; CODE XREF: AddAmmoBag+F2j
//@ 		cmp	ax, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jnz	short loc_1A788	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+16h], 32h ; '2'
//@ 		mov	word ptr es:[di+0Eh], 70h ; 'p'
//@ 		jmp	short loc_1A7AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 869
//@ 
//@ loc_1A788:				; CODE XREF: AddAmmoBag+101j
//@ 		cmp	ax, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_1A797	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+15h], 2
//@ 		jmp	short loc_1A7AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 870
//@ 
//@ loc_1A797:				; CODE XREF: AddAmmoBag+116j
//@ 		cmp	ax, 77h	; 'w'   ; Compare Two Operands
//@ 		jnz	short loc_1A7AA	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+16h], 32h ; '2'
//@ 		mov	word ptr es:[di+0Eh], 70h ; 'p'
//@ ; #line	"CSACT.PAS" 872
//@ 
//@ loc_1A7AA:				; CODE XREF: AddAmmoBag+DEj
//@ 					; AddAmmoBag+EDj ...
//@ 		jmp	short locret_1A80D ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 874
//@ 
//@ loc_1A7AC:				; CODE XREF: AddAmmoBag+9Fj
//@ 		imul	di, [bp+owner],	58h ; int16_t
//@ 		add	di, 0F058h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 11h		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	8
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 875
//@ 		imul	di, [bp+owner],	58h ; int16_t
//@ 		mov	ax, [di-0F88h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+19h], ax
//@ ; #line	"CSACT.PAS" 876
//@ 		imul	di, [bp+owner],	58h ; int16_t
//@ 		mov	al, [di-0FB1h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], al
//@ ; #line	"CSACT.PAS" 877
//@ 		imul	di, [bp+owner],	58h ; int16_t
//@ 		mov	al, [di-0FAFh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Dh], ax
//@ ; #line	"CSACT.PAS" 878
//@ 		imul	di, [bp+owner],	58h ; int16_t
//@ 		mov	ax, [di-0FACh]
//@ 		and	ax, 0F0h	; Logical AND
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSACT.PAS" 879
//@ 		mov	word ptr es:[di+1Bh], 14h
//@ ; #line	"CSACT.PAS" 882
//@ 
//@ locret_1A80D:				; CODE XREF: AddAmmoBag+Bj
//@ 					; AddAmmoBag+96j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ AddAmmoBag	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aNoBagsToRemove	db 18,'No bags to remove!' ; DATA XREF: RemoveAmmoBag+52o
//@ ; #line	"CSACT.PAS" 886
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RemoveAmmoBag	proc far		; CODE XREF: ExecuteEvent+63P
//@ 
//@ var_6		= word ptr -6
//@ n		= word ptr -4		; int16_t
//@ o		= word ptr -2		; int16_t
//@ by		= word ptr  6		; int16_t
//@ $bx		= word ptr  8		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 887
//@ 		mov	[bp+o],	0FFFFh	; int16_t
//@ ; #line	"CSACT.PAS" 888
//@ 		mov	ax, AmCount	; uint16_t
//@ 		mov	[bp+var_6], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jg	short loc_1A870	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1A843	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1A840:				; CODE XREF: RemoveAmmoBag+4Aj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 889
//@ 
//@ loc_1A843:				; CODE XREF: RemoveAmmoBag+1Aj
//@ 		imul	ax, [bp+n], 1Fh	; int16_t
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE1h	; Add
//@ ; #line	"CSACT.PAS" 890
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, [bp+$bx]	; int16_t
//@ 		jnz	short loc_1A868	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+2]
//@ 		cmp	ax, [bp+by]	; int16_t
//@ 		jnz	short loc_1A868	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+o],	ax	; int16_t
//@ 
//@ loc_1A868:				; CODE XREF: RemoveAmmoBag+33j
//@ 					; RemoveAmmoBag+3Cj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jnz	short loc_1A840	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 891
//@ 
//@ loc_1A870:				; CODE XREF: RemoveAmmoBag+15j
//@ 		cmp	[bp+o],	0FFFFh	; int16_t
//@ 		jnz	short loc_1A882	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aNoBagsToRemove ; "No bags to remove!"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ 		jmp	short locret_1A8B8 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 892
//@ 
//@ loc_1A882:				; CODE XREF: RemoveAmmoBag+50j
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
//@ ; #line	"CSACT.PAS" 893
//@ 		dec	AmCount		; uint16_t
//@ ; #line	"CSACT.PAS" 894
//@ 
//@ locret_1A8B8:				; CODE XREF: RemoveAmmoBag+5Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ RemoveAmmoBag	endp
//@ 
//@ ; #line	"CSACT.PAS" 900
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddSinglePart	proc far		; CODE XREF: ExplodeMonster+160P
//@ 					; ExplodeMonster+19AP ...
//@ 
//@ var_C		= dword	ptr -0Ch
//@ vy		= word ptr -8		; int16_t
//@ vx		= word ptr -6		; int16_t
//@ vv		= word ptr -4		; int16_t
//@ pfi		= word ptr -2		; int16_t
//@ Color		= byte ptr  6		; int16_t
//@ PartN		= word ptr  8		; int16_t
//@ Power		= word ptr  0Ah		; int16_t
//@ pz		= word ptr  0Ch		; int16_t
//@ py		= word ptr  0Eh		; int16_t
//@ px		= word ptr  10h		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 901
//@ 		imul	di, [bp+PartN],	12h ; int16_t
//@ 		mov	ax, [di-2FB6h]
//@ 		or	ax, [di-2FB4h]	; Logical Inclusive OR
//@ 		jnz	short loc_1A8D1	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1AA8B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 903
//@ 
//@ loc_1A8D1:				; CODE XREF: AddSinglePart+10j
//@ 		cmp	SCount,	1Fh	; uint16_t
//@ 		jbe	short loc_1A8F0	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 905
//@ 		mov	SCount,	1Fh	; uint16_t
//@ ; #line	"CSACT.PAS" 906
//@ 		mov	di, (offset SepList.FTime+16h) ; struct	TSepPart[32]
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset SepList ; struct TSepPart[32]
//@ 		push	ds
//@ 		push	di
//@ 		push	2AAh
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 908
//@ 
//@ loc_1A8F0:				; CODE XREF: AddSinglePart+1Aj
//@ 		inc	SCount		; uint16_t
//@ ; #line	"CSACT.PAS" 910
//@ 		push	400h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		mov	[bp+pfi], ax	; int16_t
//@ ; #line	"CSACT.PAS" 911
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 64h	; 'd'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+vy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 912
//@ 		mov	di, [bp+pfi]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 64h	; 'd'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+vx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 914
//@ 		imul	di, SCount, 16h	; uint16_t
//@ 		add	di, 0B940h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"CSACT.PAS" 916
//@ 		push	0A0h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+px]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 50h	; 'P'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSACT.PAS" 917
//@ 		push	0A0h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+py]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 50h	; 'P'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSACT.PAS" 918
//@ 		push	1Eh
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+pz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, 7
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSACT.PAS" 920
//@ 		push	1Eh
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+Power]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, 5Ah	; 'Z'   ; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSACT.PAS" 921
//@ 		push	200h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		sub	ax, 100h	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+pfi], ax	; int16_t
//@ ; #line	"CSACT.PAS" 922
//@ 		cmp	[bp+pfi], 0	; int16_t
//@ 		jge	short loc_1A9F3	; Jump if Greater or Equal (SF=OF)
//@ 		add	[bp+pfi], 400h	; int16_t
//@ 		jmp	short loc_1A9FF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 923
//@ 
//@ loc_1A9F3:				; CODE XREF: AddSinglePart+12Ej
//@ 		cmp	[bp+pfi], 400h	; int16_t
//@ 		jl	short loc_1A9FF	; Jump if Less (SF!=OF)
//@ 		sub	[bp+pfi], 400h	; int16_t
//@ ; #line	"CSACT.PAS" 925
//@ 
//@ loc_1A9FF:				; CODE XREF: AddSinglePart+135j
//@ 					; AddSinglePart+13Cj
//@ 		push	14h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+Power]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+vv], ax	; int16_t
//@ ; #line	"CSACT.PAS" 926
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+vv]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSACT.PAS" 927
//@ 		mov	di, [bp+pfi]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+vv]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 100h
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSACT.PAS" 929
//@ 		mov	ax, [bp+pfi]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	es:[di+14h], ax
//@ 		add	word ptr es:[di+14h], 0C000h ; Add
//@ ; #line	"CSACT.PAS" 930
//@ 		mov	ax, [bp+PartN]	; int16_t
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSACT.PAS" 931
//@ 		mov	al, [bp+Color]	; int16_t
//@ 		mov	es:[di+7], al
//@ ; #line	"CSACT.PAS" 932
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+2], ax
//@ 		mov	byte ptr es:[di+6], 0
//@ ; #line	"CSACT.PAS" 934
//@ 
//@ locret_1AA8B:				; CODE XREF: AddSinglePart+12j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ AddSinglePart	endp
//@ 
//@ ; #line	"CSACT.PAS" 941
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExplodeMonster	proc far		; CODE XREF: MakeTeleBlow+6CP
//@ 					; ExecuteEvent+164P ...
//@ 
//@ var_12		= word ptr -12h
//@ mh		= word ptr -10h		; int16_t
//@ mz		= word ptr -0Eh		; int16_t
//@ n		= word ptr -0Ch		; int16_t
//@ var_9		= byte ptr -9
//@ p		= byte ptr -8		; uint8_t[8]
//@ var_7		= byte ptr -7
//@ var_6		= byte ptr -6
//@ var_5		= byte ptr -5
//@ var_4		= byte ptr -4
//@ var_3		= byte ptr -3
//@ var_2		= byte ptr -2
//@ rz		= word ptr  6		; int16_t
//@ my		= word ptr  8		; int16_t
//@ mx		= word ptr  0Ah		; int16_t
//@ DM		= word ptr  0Ch		; int16_t
//@ MT		= word ptr  0Eh		; int16_t
//@ 
//@ 		enter	12h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 942
//@ 		push	58h ; 'X'
//@ 		mov	al, byte ptr [bp+MT] ; int16_t
//@ 		push	ax
//@ 		push	[bp+DM]		; int16_t
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	[bp+mz]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 943
//@ 		push	0FFFFh
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		push	7
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 944
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		sub	ax, 14h		; Integer Subtraction
//@ 		mov	[bp+mz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 945
//@ 		cmp	[bp+mz], 0	; int16_t
//@ 		jge	short loc_1AAD0	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+mz], ax	; int16_t
//@ ; #line	"CSACT.PAS" 947
//@ 
//@ loc_1AAD0:				; CODE XREF: ExplodeMonster+3Aj
//@ 		imul	di, [bp+MT], 0A2h ; int16_t
//@ 		mov	ax, [di+7FBAh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	[bp+mh], ax	; int16_t
//@ ; #line	"CSACT.PAS" 948
//@ 		sub	[bp+MT], 64h ; 'd' ; int16_t
//@ ; #line	"CSACT.PAS" 949
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_1AAED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1AAEA:				; CODE XREF: ExplodeMonster+69j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_1AAED:				; CODE XREF: ExplodeMonster+59j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	[bp+di+var_9], 0
//@ 		cmp	[bp+n],	8	; int16_t
//@ 		jnz	short loc_1AAEA	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 950
//@ 		mov	ax, [bp+MT]	; int16_t
//@ ; #line	"CSACT.PAS" 951
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_1AB0D	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+var_2], 6
//@ 		mov	[bp+var_6], 2
//@ 		jmp	loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 952
//@ 
//@ loc_1AB0D:				; CODE XREF: ExplodeMonster+71j
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jnz	short loc_1AB1D	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+var_5], 4
//@ 		mov	[bp+var_4], 4
//@ 		jmp	loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 953
//@ 
//@ loc_1AB1D:				; CODE XREF: ExplodeMonster+81j
//@ 		cmp	ax, 6		; Compare Two Operands
//@ 		jnz	short loc_1AB31	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+p],	3	; uint8_t[8]
//@ 		mov	[bp+var_7], 3
//@ 		mov	[bp+var_6], 3
//@ 		jmp	loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 954
//@ 
//@ loc_1AB31:				; CODE XREF: ExplodeMonster+91j
//@ 		cmp	ax, 8		; Compare Two Operands
//@ 		jnz	short loc_1AB3C	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+var_3], 5
//@ 		jmp	short loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 955
//@ 
//@ loc_1AB3C:				; CODE XREF: ExplodeMonster+A5j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_1AB4F	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+p],	1	; uint8_t[8]
//@ 		mov	[bp+var_7], 5
//@ 		mov	[bp+var_6], 3
//@ 		jmp	short loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 956
//@ 
//@ loc_1AB4F:				; CODE XREF: ExplodeMonster+B0j
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jnz	short loc_1AB62	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+p],	3	; uint8_t[8]
//@ 		mov	[bp+var_7], 3
//@ 		mov	[bp+var_6], 2
//@ 		jmp	short loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 957
//@ 
//@ loc_1AB62:				; CODE XREF: ExplodeMonster+C3j
//@ 		cmp	ax, 5		; Compare Two Operands
//@ 		jz	short loc_1AB76	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Ch		; Compare Two Operands
//@ 		jz	short loc_1AB76	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Dh		; Compare Two Operands
//@ 		jz	short loc_1AB76	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jnz	short loc_1AB84	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1AB76:				; CODE XREF: ExplodeMonster+D6j
//@ 					; ExplodeMonster+DBj ...
//@ 		mov	[bp+p],	5	; uint8_t[8]
//@ 		mov	[bp+var_7], 4
//@ 		mov	[bp+var_6], 3
//@ 		jmp	short loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 958
//@ 
//@ loc_1AB84:				; CODE XREF: ExplodeMonster+E5j
//@ 		cmp	ax, 9		; Compare Two Operands
//@ 		jz	short loc_1AB98	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 12h		; Compare Two Operands
//@ 		jz	short loc_1AB98	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 13h		; Compare Two Operands
//@ 		jz	short loc_1AB98	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 14h		; Compare Two Operands
//@ 		jnz	short loc_1ABA6	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1AB98:				; CODE XREF: ExplodeMonster+F8j
//@ 					; ExplodeMonster+FDj ...
//@ 		mov	[bp+p],	0Ah	; uint8_t[8]
//@ 		mov	[bp+var_7], 8
//@ 		mov	[bp+var_6], 8
//@ 		jmp	short loc_1ABB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 960
//@ 
//@ loc_1ABA6:				; CODE XREF: ExplodeMonster+107j
//@ 		mov	[bp+p],	2	; uint8_t[8]
//@ 		mov	[bp+var_7], 3
//@ 		mov	[bp+var_6], 3
//@ ; #line	"CSACT.PAS" 963
//@ 
//@ loc_1ABB2:				; CODE XREF: ExplodeMonster+7Bj
//@ 					; ExplodeMonster+8Bj ...
//@ 		mov	word ptr [bp-0Ah], 1
//@ 		jmp	short loc_1ABBC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1ABB9:				; CODE XREF: ExplodeMonster+171j
//@ 		inc	word ptr [bp-0Ah] ; Increment by 1
//@ ; #line	"CSACT.PAS" 964
//@ 
//@ loc_1ABBC:				; CODE XREF: ExplodeMonster+128j
//@ 		mov	di, [bp-0Ah]
//@ 		mov	al, [bp+di+var_9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jg	short loc_1ABFC	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1ABD7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1ABD4:				; CODE XREF: ExplodeMonster+16Bj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_1ABD7:				; CODE XREF: ExplodeMonster+143j
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		mov	ax, [bp+mz]	; int16_t
//@ 		add	ax, 28h	; '('   ; Add
//@ 		push	ax
//@ 		push	30h ; '0'
//@ 		mov	ax, [bp-0Ah]
//@ 		add	ax, 46h	; 'F'   ; Add
//@ 		push	ax
//@ 		push	0
//@ 		call	AddSinglePart	; function far PASCAL returns void
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jnz	short loc_1ABD4	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1ABFC:				; CODE XREF: ExplodeMonster+13Ej
//@ 		cmp	word ptr [bp-0Ah], 8 ; Compare Two Operands
//@ 		jnz	short loc_1ABB9	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 966
//@ 		mov	ax, [bp+DM]	; int16_t
//@ 		and	ax, 4		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_1AC2E	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+mx]		; int16_t
//@ 		push	[bp+my]		; int16_t
//@ 		mov	ax, [bp+mz]	; int16_t
//@ 		add	ax, [bp+mh]	; int16_t
//@ 		push	ax
//@ 		push	2Ch ; ','
//@ 		mov	ax, [bp+MT]	; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	0
//@ 		call	AddSinglePart	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 968
//@ 
//@ loc_1AC2E:				; CODE XREF: ExplodeMonster+17Bj
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short locret_1AC85 ; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 969
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jg	short locret_1AC85 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1AC4B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1AC48:				; CODE XREF: ExplodeMonster+1F4j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 970
//@ 
//@ loc_1AC4B:				; CODE XREF: ExplodeMonster+1B7j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		mov	ax, [di-5AE0h]
//@ 		sub	ax, [bp+my]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		mov	ax, [di-5AE2h]
//@ 		sub	ax, [bp+mx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, 20h	; ' '   ; Compare Two Operands
//@ 		jge	short loc_1AC7D	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 971
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		mov	byte ptr [di-5AD7h], 0FFh
//@ 
//@ loc_1AC7D:				; CODE XREF: ExplodeMonster+1E3j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jnz	short loc_1AC48	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 973
//@ 
//@ locret_1AC85:				; CODE XREF: ExplodeMonster+1A4j
//@ 					; ExplodeMonster+1B2j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ ExplodeMonster	endp
//@ 
//@ ; #line	"CSACT.PAS" 977
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetMePain	proc far		; CODE XREF: LoadServerPatch+377P
//@ 					; Demo_ReadNextQuant+132P ...
//@ 
//@ l		= word ptr  6		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSACT.PAS" 978
//@ 		cmp	[bp+l],	0	; int16_t
//@ 		jg	short loc_1AC94	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	short locret_1ACDE ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 979
//@ 
//@ loc_1AC94:				; CODE XREF: SetMePain+7j
//@ 		mov	ax, word ptr LastPainTime ; int32_t
//@ 		mov	dx, word ptr LastPainTime+2 ; int32_t
//@ 		add	ax, 1Eh		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		cmp	dx, word ptr Time+2 ; int32_t
//@ 		jg	short loc_1ACAF	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_1ACB1	; Jump if Less (SF!=OF)
//@ 		cmp	ax, word ptr Time ; int32_t
//@ 		jbe	short loc_1ACB1	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_1ACAF:				; CODE XREF: SetMePain+1Cj
//@ 		jmp	short locret_1ACDE ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 980
//@ 
//@ loc_1ACB1:				; CODE XREF: SetMePain+1Ej
//@ 					; SetMePain+24j
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	word ptr LastPainTime, ax ; int32_t
//@ 		mov	word ptr LastPainTime+2, dx ; int32_t
//@ ; #line	"CSACT.PAS" 981
//@ 		mov	RShadeDir, 1	; int16_t
//@ ; #line	"CSACT.PAS" 982
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		imul	ax, 16h		; Signed Multiply
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 983
//@ 
//@ locret_1ACDE:				; CODE XREF: SetMePain+9j
//@ 					; SetMePain:loc_1ACAFj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ SetMePain	endp
//@ 
//@ ; #line	"CSACT.PAS" 987
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddDeadPlayer	proc far		; CODE XREF: ExecConsole+C53P
//@ 					; MakePunch+1EFP ...
//@ 
//@ var_C		= dword	ptr -0Ch
//@ var_8		= dword	ptr -8
//@ MN		= word ptr -4		; uint16_t
//@ n		= word ptr -2		; uint16_t
//@ Pn		= word ptr  6		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 988
//@ 		mov	[bp+n],	1	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+MN], ax	; uint16_t
//@ ; #line	"CSACT.PAS" 989
//@ 
//@ loc_1ACF0:				; CODE XREF: AddDeadPlayer:loc_1AD2Bj
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, MCount	; uint16_t
//@ 		ja	short loc_1AD2D	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	[bp+MN], 0	; uint16_t
//@ 		jnz	short loc_1AD2D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 990
//@ 		imul	di, [bp+n], 28h	; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 991
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jnz	short loc_1AD28	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+14h]
//@ 		cmp	ax, [bp+Pn]	; int16_t
//@ 		jnz	short loc_1AD28	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jnz	short loc_1AD28	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		mov	[bp+MN], ax	; uint16_t
//@ 		jmp	short loc_1AD2B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1AD28:				; CODE XREF: AddDeadPlayer+2Cj
//@ 					; AddDeadPlayer+35j ...
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_1AD2B:				; CODE XREF: AddDeadPlayer+44j
//@ 		jmp	short loc_1ACF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 993
//@ 
//@ loc_1AD2D:				; CODE XREF: AddDeadPlayer+15j
//@ 					; AddDeadPlayer+1Bj
//@ 		cmp	[bp+MN], 0	; uint16_t
//@ 		jbe	short loc_1AD5E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 995
//@ 		mov	ax, [bp+MN]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, [bp+MN], 28h ; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, MCount	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		sub	ax, [bp+MN]	; uint16_t
//@ 		imul	ax, 28h		; Signed Multiply
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 997
//@ 		dec	MCount		; uint16_t
//@ ; #line	"CSACT.PAS" 1000
//@ 
//@ loc_1AD5E:				; CODE XREF: AddDeadPlayer+4Fj
//@ 		inc	MCount		; uint16_t
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+MN], ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1002
//@ 		imul	di, [bp+MN], 28h ; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSACT.PAS" 1004
//@ 		imul	di, [bp+Pn], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"CSACT.PAS" 1006
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 500h	; Add
//@ 		push	ax
//@ 		push	[bp+Pn]		; int16_t
//@ 		call	AddAmmoBag	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1007
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	0E8h ; 'è'
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1008
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+0Ah], 64h ; 'd'
//@ ; #line	"CSACT.PAS" 1009
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSACT.PAS" 1010
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		sub	ax, 4000h	; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSACT.PAS" 1011
//@ 		mov	ax, es:[di+4]
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSACT.PAS" 1012
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSACT.PAS" 1013
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSACT.PAS" 1014
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+52h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+50h], ax
//@ ; #line	"CSACT.PAS" 1015
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4Ch], ax
//@ ; #line	"CSACT.PAS" 1016
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSACT.PAS" 1017
//@ 		mov	ax, [bp+Pn]	; int16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSACT.PAS" 1019
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSACT.PAS" 1020
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ ; #line	"CSACT.PAS" 1021
//@ 		mov	byte ptr es:[di+24h], 0
//@ ; #line	"CSACT.PAS" 1022
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSACT.PAS" 1023
//@ 		mov	byte ptr es:[di+26h], 5
//@ ; #line	"CSACT.PAS" 1024
//@ 		mov	byte ptr es:[di+0Bh], 0
//@ ; #line	"CSACT.PAS" 1025
//@ 		push	4
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ ; #line	"CSACT.PAS" 1026
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_1AE90	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 0Ch
//@ 		jmp	locret_1AF21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1027
//@ 
//@ loc_1AE90:				; CODE XREF: AddDeadPlayer+1A0j
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_1AEC1	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 0Dh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	12h
//@ 		push	0
//@ 		push	0
//@ 		push	word ptr es:[di+4]
//@ 		push	[bp+Pn]		; int16_t
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+0Bh], 2
//@ 		jmp	short locret_1AF21 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1028
//@ 
//@ loc_1AEC1:				; CODE XREF: AddDeadPlayer+1B1j
//@ 		cmp	ax, 2		; Compare Two Operands
//@ 		jnz	short loc_1AEF2	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 0Eh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	12h
//@ 		push	0
//@ 		push	1
//@ 		push	word ptr es:[di+4]
//@ 		push	[bp+Pn]		; int16_t
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+0Bh], 1
//@ 		jmp	short locret_1AF21 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1029
//@ 
//@ loc_1AEF2:				; CODE XREF: AddDeadPlayer+1E2j
//@ 		cmp	ax, 3		; Compare Two Operands
//@ 		jnz	short locret_1AF21 ; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 0Fh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	1Ch
//@ 		push	0
//@ 		push	2
//@ 		push	word ptr es:[di+4]
//@ 		push	[bp+Pn]		; int16_t
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+0Bh], 4
//@ ; #line	"CSACT.PAS" 1032
//@ 
//@ locret_1AF21:				; CODE XREF: AddDeadPlayer+1ABj
//@ 					; AddDeadPlayer+1DDj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ AddDeadPlayer	endp
//@ 
//@ ; #line	"CSACT.PAS" 1038
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExplodePlayer	proc far		; CODE XREF: MakeTeleBlow+B9P
//@ 					; ShootMe+13BP
//@ 
//@ var_8		= dword	ptr -8
//@ PN		= word ptr  6		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1039
//@ 		imul	di, [bp+PN], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSACT.PAS" 1041
//@ 		push	64h ; 'd'
//@ 		push	0
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+0Eh]
//@ 		call	ExplodeMonster	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1042
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 500h	; Add
//@ 		push	ax
//@ 		push	[bp+PN]		; int16_t
//@ 		call	AddAmmoBag	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1043
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+52h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+50h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4Ch], ax
//@ ; #line	"CSACT.PAS" 1045
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ ExplodePlayer	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_6		db 3,'@##'              ; DATA XREF: LoadSpryte+2Ao
//@ aNoRegisteredSp	db 27,'No registered spryte used! ' ; DATA XREF: LoadSpryte+1Ao
//@ a@_7		db 2,'@#'               ; DATA XREF: LoadSpryte+66o
//@ aLevel_0	db 5,'LEVEL'            ; DATA XREF: LoadSpryte+56o
//@ aGfx		db 5,'\GFX\'            ; DATA XREF: LoadSpryte+81o
//@ ; #line	"CSACT.PAS" 1051
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadSpryte	proc near		; CODE XREF: LoadFrame+7p
//@ 					; ReloadResources+238p
//@ 
//@ var_208		= byte ptr -208h
//@ var_108		= byte ptr -108h
//@ var_A		= word ptr -0Ah
//@ y		= word ptr -8		; uint16_t
//@ x		= word ptr -6		; uint16_t
//@ wd		= word ptr -2		; uint16_t
//@ n		= word ptr  4		; uint16_t
//@ 
//@ 		enter	208h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1052
//@ 		imul	ax, [bp+n], 0Eh	; uint16_t
//@ 		les	di, GFXindex	; char*
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_1B00E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1053
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aNoRegisteredSp ; "No registered spryte used! "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_108] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_6	; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1055
//@ 
//@ loc_1B00E:				; CODE XREF: LoadSpryte+12j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_0 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_108] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_7	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aGfx	; "\\GFX\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		imul	ax, [bp+n], 0Eh	; uint16_t
//@ 		les	di, GFXindex	; char*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1056
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1057
//@ 		cmp	word ptr F.Size+2, 0 ; struct BFile
//@ 		jg	short loc_1B084	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_1B08B	; Jump if Less (SF!=OF)
//@ 		cmp	word ptr F.Size, 2710h ; struct	BFile
//@ 		jbe	short loc_1B08B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_1B084:				; CODE XREF: LoadSpryte+B5j
//@ 		mov	[bp+wd], 80h ; '€' ; uint16_t
//@ 		jmp	short loc_1B090	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B08B:				; CODE XREF: LoadSpryte+B7j
//@ 					; LoadSpryte+BFj
//@ 		mov	[bp+wd], 40h ; '@' ; uint16_t
//@ ; #line	"CSACT.PAS" 1059
//@ 
//@ loc_1B090:				; CODE XREF: LoadSpryte+C6j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_1B0B6	; Jump if Below	(CF=1)
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 6ED2h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+wd]	; uint16_t
//@ 		add	ax, 10h		; Add
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ 		jmp	short loc_1B0CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1060
//@ 
//@ loc_1B0B6:				; CODE XREF: LoadSpryte+D4j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 6ED2h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+wd]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1062
//@ 
//@ loc_1B0CE:				; CODE XREF: LoadSpryte+F1j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		les	di, [di+6ED2h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di+70B2h], ax
//@ ; #line	"CSACT.PAS" 1063
//@ 		cmp	PImBSeg, 0	; uint16_t
//@ 		jnz	short loc_1B0F6	; Jump if Not Zero (ZF=0)
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+70B2h]
//@ 		mov	PImBSeg, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1064
//@ 
//@ loc_1B0F6:				; CODE XREF: LoadSpryte+125j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di+70B2h]
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSACT.PAS" 1065
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		les	di, [di+6ED2h]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+wd]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	16h
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1066
//@ 		mov	ax, [bp+wd]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_A], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jg	short loc_1B162	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_1B139	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B135:				; CODE XREF: LoadSpryte+19Dj
//@ 		inc	i		; int16_t
//@ ; #line	"CSACT.PAS" 1067
//@ 
//@ loc_1B139:				; CODE XREF: LoadSpryte+170j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+70B2h]
//@ 		push	ax
//@ 		mov	ax, i		; int16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		add	ax, 50h	; 'P'   ; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	30h ; '0'
//@ 		push	0FFFFh
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ 		mov	ax, i		; int16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jnz	short loc_1B135	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1069
//@ 
//@ loc_1B162:				; CODE XREF: LoadSpryte+16Bj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y],	ax	; uint16_t
//@ 		jmp	short loc_1B16C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B169:				; CODE XREF: LoadSpryte+1CDj
//@ 		inc	[bp+y]		; uint16_t
//@ ; #line	"CSACT.PAS" 1070
//@ 
//@ loc_1B16C:				; CODE XREF: LoadSpryte+1A4j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+wd]		; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		cmp	[bp+y],	7Fh ; '' ; uint16_t
//@ 		jnz	short loc_1B169	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1071
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1073
//@ 		mov	ax, [bp+wd]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_A], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		ja	short loc_1B1F6	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_1B1B2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B1AF:				; CODE XREF: LoadSpryte+231j
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSACT.PAS" 1074
//@ 
//@ loc_1B1B2:				; CODE XREF: LoadSpryte+1EAj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y],	ax	; uint16_t
//@ 		jmp	short loc_1B1BC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B1B9:				; CODE XREF: LoadSpryte+229j
//@ 		inc	[bp+y]		; uint16_t
//@ ; #line	"CSACT.PAS" 1075
//@ 
//@ loc_1B1BC:				; CODE XREF: LoadSpryte+1F4j
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		add	ax, [bp+x]	; uint16_t
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	dl, es:[di]
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+70B2h]
//@ 		push	ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		add	ax, [bp+y]	; uint16_t
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ 		cmp	[bp+y],	7Fh ; '' ; uint16_t
//@ 		jnz	short loc_1B1B9	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jnz	short loc_1B1AF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1077
//@ 
//@ loc_1B1F6:				; CODE XREF: LoadSpryte+1E5j
//@ 		cmp	[bp+wd], 40h ; '@' ; uint16_t
//@ 		jnz	short locret_1B214 ; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		or	al, 80h		; Logical Inclusive OR
//@ 		mov	dl, al
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		mov	[di+71A1h], dl
//@ ; #line	"CSACT.PAS" 1078
//@ 
//@ locret_1B214:				; CODE XREF: LoadSpryte+237j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ LoadSpryte	endp
//@ 
//@ ; #line	"CSACT.PAS" 1081
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns unsigned	char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ sgn		proc near		; CODE XREF: LoadFrame+B5p
//@ 					; LoadFrame+105p
//@ 
//@ sgn		= byte ptr -1		; uint8_t
//@ b		= byte ptr  4		; uint8_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ 		cmp	[bp+b],	0FEh ; 'þ' ; uint8_t
//@ 		jb	short loc_1B228	; Jump if Below	(CF=1)
//@ 		mov	[bp+sgn], 0	; uint8_t
//@ 		jmp	short loc_1B22C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B228:				; CODE XREF: sgn+8j
//@ 		mov	[bp+sgn], 1	; uint8_t
//@ 
//@ loc_1B22C:				; CODE XREF: sgn+Ej
//@ 		mov	al, [bp+sgn]	; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ sgn		endp
//@ 
//@ ; #line	"CSACT.PAS" 1085
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadFrame	proc near		; CODE XREF: ReloadResources+230p
//@ 
//@ var_C		= word ptr -0Ch
//@ y		= byte ptr -9		; uint8_t
//@ pseg		= word ptr -8		; uint16_t
//@ k		= word ptr -6		; uint16_t
//@ x		= word ptr -4		; uint16_t
//@ wd		= word ptr -2		; uint16_t
//@ n		= word ptr  4		; uint16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1086
//@ 		push	[bp+n]		; uint16_t
//@ 		call	LoadSpryte	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1087
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+70B2h]
//@ 		mov	[bp+pseg], ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1089
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_1B260	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	[bp+wd], 40h ; '@' ; uint16_t
//@ 		jmp	short loc_1B265	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B260:				; CODE XREF: LoadFrame+24j
//@ 		mov	[bp+wd], 80h ; '€' ; uint16_t
//@ ; #line	"CSACT.PAS" 1090
//@ 
//@ loc_1B265:				; CODE XREF: LoadFrame+2Bj
//@ 		mov	ax, [bp+pseg]	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+wd]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 1093
//@ 		mov	[bp+k],	100h	; uint16_t
//@ ; #line	"CSACT.PAS" 1094
//@ 		mov	ax, [bp+wd]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_C], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		jbe	short loc_1B299	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_1B3C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B299:				; CODE XREF: LoadFrame+61j
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_1B2A1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B29E:				; CODE XREF: LoadFrame+18Bj
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSACT.PAS" 1096
//@ 
//@ loc_1B2A1:				; CODE XREF: LoadFrame+69j
//@ 		lea	di, [bp+k]	; uint16_t
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+pseg]	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 1097
//@ 		mov	[bp+y],	0	; uint8_t
//@ ; #line	"CSACT.PAS" 1098
//@ 
//@ loc_1B2BF:				; CODE XREF: LoadFrame:loc_1B3A4j
//@ 		cmp	[bp+y],	7Fh ; '' ; uint8_t
//@ 		jb	short loc_1B2C8	; Jump if Below	(CF=1)
//@ 		jmp	loc_1B3A7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1100
//@ 
//@ loc_1B2C8:				; CODE XREF: LoadFrame+90j
//@ 					; LoadFrame+BFj
//@ 		cmp	[bp+y],	80h ; '€' ; uint8_t
//@ 		jnb	short loc_1B2F4	; Jump if Not Below (CF=0)
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		push	ax
//@ 		mov	al, [bp+y]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		push	ax
//@ 		call	sgn		; function near	PASCAL returns unsigned	char 'Byte'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1B2F4	; Jump if Not Zero (ZF=0)
//@ 		inc	[bp+y]		; uint8_t
//@ 		jmp	short loc_1B2C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1101
//@ 
//@ loc_1B2F4:				; CODE XREF: LoadFrame+99j
//@ 					; LoadFrame+BAj
//@ 		cmp	[bp+y],	80h ; '€' ; uint8_t
//@ 		jb	short loc_1B2FD	; Jump if Below	(CF=1)
//@ 		jmp	loc_1B3A4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1103
//@ 
//@ loc_1B2FD:				; CODE XREF: LoadFrame+C5j
//@ 		mov	c, 1		; uint8_t
//@ ; #line	"CSACT.PAS" 1104
//@ 
//@ loc_1B302:				; CODE XREF: LoadFrame+110j
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, [bp+y]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, dx		; Add
//@ 		cmp	ax, 80h	; '€'   ; Compare Two Operands
//@ 		jge	short loc_1B345	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		push	ax
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	al, [bp+y]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		add	ax, cx		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		push	ax
//@ 		call	sgn		; function near	PASCAL returns unsigned	char 'Byte'
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_1B345	; Jump if Not Zero (ZF=0)
//@ 		inc	c		; uint8_t
//@ 		jmp	short loc_1B302	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1105
//@ 
//@ loc_1B345:				; CODE XREF: LoadFrame+E0j
//@ 					; LoadFrame+10Aj
//@ 		mov	dl, [bp+y]	; uint8_t
//@ 		mov	ax, [bp+pseg]	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+k]	; uint16_t
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSACT.PAS" 1106
//@ 		mov	dl, c		; uint8_t
//@ 		mov	ax, [bp+pseg]	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+k]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ 		add	[bp+k],	2	; uint16_t
//@ ; #line	"CSACT.PAS" 1107
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		push	ax
//@ 		mov	al, [bp+y]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+pseg]	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+k]	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 1108
//@ 		mov	al, c		; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	[bp+k],	ax	; uint16_t
//@ 		mov	al, c		; uint8_t
//@ 		add	[bp+y],	al	; uint8_t
//@ ; #line	"CSACT.PAS" 1110
//@ 
//@ loc_1B3A4:				; CODE XREF: LoadFrame+C7j
//@ 		jmp	loc_1B2BF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1111
//@ 
//@ loc_1B3A7:				; CODE XREF: LoadFrame+92j
//@ 		mov	ax, [bp+pseg]	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+k]	; uint16_t
//@ 		pop	es
//@ 		mov	byte ptr es:[di], 0FFh
//@ 		inc	[bp+k]		; uint16_t
//@ ; #line	"CSACT.PAS" 1112
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		cmp	ax, [bp+var_C]	; Compare Two Operands
//@ 		jz	short locret_1B3C1 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1B29E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1113
//@ 
//@ locret_1B3C1:				; CODE XREF: LoadFrame+63j
//@ 					; LoadFrame+189j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ LoadFrame	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_1B3C5	db 1,'='                ; DATA XREF: LoadSky+2Do
//@ aCommon		db 7,'COMMON\'          ; DATA XREF: LoadSky+64o
//@ ; #line	"CSACT.PAS" 1117
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadSky		proc near		; CODE XREF: ReloadResources+D9p
//@ 
//@ var_300		= byte ptr -300h
//@ var_200		= byte ptr -200h
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ 
//@ 		enter	300h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSACT.PAS" 1118
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1B3C5 ; "="
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1119
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCommon ; "COMMON\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1120
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1121
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, SkyPtr	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0C800h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1122
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1123
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ LoadSky		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_1B481	db 1,'='                ; DATA XREF: SetCDTrack+2Do
//@ ; #line	"CSACT.PAS" 1126
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetCDTrack	proc near		; CODE XREF: ReloadResources+F9p
//@ 
//@ var_300		= byte ptr -300h
//@ var_200		= byte ptr -200h
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ 
//@ 		enter	300h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSACT.PAS" 1127
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1B481 ; "="
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1128
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset i	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSACT.PAS" 1129
//@ 		cmp	i, 0		; int16_t
//@ 		jnz	short locret_1B4FC ; Jump if Not Zero (ZF=0)
//@ 		mov	ax, w		; uint16_t
//@ 		mov	LCDTrack, ax	; int16_t
//@ ; #line	"CSACT.PAS" 1130
//@ 
//@ locret_1B4FC:				; CODE XREF: SetCDTrack+71j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ SetCDTrack	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_1B500	db 1,'='                ; DATA XREF: SetDepth+2Do
//@ ; #line	"CSACT.PAS" 1134
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetDepth	proc near		; CODE XREF: ReloadResources+118p
//@ 
//@ var_300		= byte ptr -300h
//@ var_200		= byte ptr -200h
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ 
//@ 		enter	300h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSACT.PAS" 1135
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1B500 ; "="
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1136
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset i	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSACT.PAS" 1137
//@ 		cmp	i, 0		; int16_t
//@ 		jnz	short locret_1B57B ; Jump if Not Zero (ZF=0)
//@ 		mov	ax, w		; uint16_t
//@ 		mov	BLevelDef, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1138
//@ 
//@ locret_1B57B:				; CODE XREF: SetDepth+71j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ SetDepth	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_8		db 2,'@#'               ; DATA XREF: ReloadFloors+1Fo
//@ 					; ReloadFloors+4Ao
//@ aLevel_1	db 5,'LEVEL'            ; DATA XREF: ReloadFloors+Fo
//@ aFloors_	db 8,'\FLOORS.'         ; DATA XREF: ReloadFloors+3Ao
//@ ; #line	"CSACT.PAS" 1143
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReloadFloors	proc near		; CODE XREF: ReloadResources+2C5p
//@ 
//@ var_300		= byte ptr -300h
//@ var_200		= byte ptr -200h
//@ var_100		= byte ptr -100h
//@ 
//@ 		enter	300h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1144
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_1 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_8	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aFloors_ ; "\\FLOORS."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_8	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1145
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset FFlags ; bool[64]
//@ 		push	ds
//@ 		push	di
//@ 		push	40h ; '@'
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1146
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1B61B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B617:				; CODE XREF: ReloadFloors+B0j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_1B61B:				; CODE XREF: ReloadFloors+84j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+1890h]
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	1580h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		cmp	n$0, 3Fh ; '?'  ; int16_t
//@ 		jnz	short loc_1B617	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1147
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1148
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ReloadFloors	endp
//@ 
//@ ; #line	"CSACT.PAS" 1151
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReleaseLevel	proc far		; CODE XREF: DoGame+19CEP PROGRAM+CF7P ...
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1152
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1B65E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B65A:				; CODE XREF: ReleaseLevel+1Ej
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_1B65E:				; CODE XREF: ReleaseLevel+9j
//@ 		imul	di, n$0, 24h	; int16_t
//@ 		mov	byte ptr [di+74C4h], 1
//@ 		cmp	n$0, 5Fh ; '_'  ; int16_t
//@ 		jnz	short loc_1B65A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1153
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1B67A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B676:				; CODE XREF: ReleaseLevel+86j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSACT.PAS" 1154
//@ 
//@ loc_1B67A:				; CODE XREF: ReleaseLevel+25j
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di+6ED2h]
//@ 		or	ax, [di+6ED4h]	; Logical Inclusive OR
//@ 		jz	short loc_1B6D0	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1156
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_1B6A3	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	w, 40h ; '@'    ; uint16_t
//@ 		jmp	short loc_1B6A9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B6A3:				; CODE XREF: ReleaseLevel+4Aj
//@ 		mov	w, 80h ; '€'    ; uint16_t
//@ ; #line	"CSACT.PAS" 1157
//@ 
//@ loc_1B6A9:				; CODE XREF: ReleaseLevel+52j
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, 56h	; 'V'   ; Compare Two Operands
//@ 		jl	short loc_1B6B7	; Jump if Less (SF!=OF)
//@ 		add	w, 10h		; uint16_t
//@ ; #line	"CSACT.PAS" 1158
//@ 
//@ loc_1B6B7:				; CODE XREF: ReleaseLevel+61j
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 6ED2h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, w		; uint16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1159
//@ 
//@ loc_1B6D0:				; CODE XREF: ReleaseLevel+3Aj
//@ 		cmp	n$0, 76h ; 'v'  ; int16_t
//@ 		jnz	short loc_1B676	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1161
//@ 		mov	di, offset SpryteUsed ;	uint8_t[120]
//@ 		push	ds
//@ 		push	di
//@ 		push	78h ; 'x'
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1163
//@ 		mov	n$0, 20h ; ' '  ; int16_t
//@ 		jmp	short loc_1B6F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B6ED:				; CODE XREF: ReleaseLevel+134j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSACT.PAS" 1164
//@ 
//@ loc_1B6F1:				; CODE XREF: ReleaseLevel+9Cj
//@ 		imul	di, n$0, 24h	; int16_t
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		mov	ax, es:[di+1Ch]
//@ 		or	ax, es:[di+1Eh]	; Logical Inclusive OR
//@ 		jz	short loc_1B77C	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1166
//@ 		mov	ax, es:[di+20h]
//@ 		or	ax, es:[di+22h]	; Logical Inclusive OR
//@ 		jz	short loc_1B73E	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1167
//@ 		add	di, 20h	; ' '   ; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+1Ah]
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, es:[di+1Ch]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+4800h] ; Unsigned Multiplication of AL or AX
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1168
//@ 
//@ loc_1B73E:				; CODE XREF: ReleaseLevel+C5j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+1Ch]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4804h],	0 ; Compare Two	Operands
//@ 		jbe	short loc_1B76B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+1Ch]	; Load Full Pointer to ES:xx
//@ 		add	di, 4806h	; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+1Ch]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4804h]
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1169
//@ 
//@ loc_1B76B:				; CODE XREF: ReleaseLevel+FCj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 1Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1170
//@ 
//@ loc_1B77C:				; CODE XREF: ReleaseLevel+BBj
//@ 		cmp	n$0, 5Fh ; '_'  ; int16_t
//@ 		jz	short loc_1B786	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1B6ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1172
//@ 
//@ loc_1B786:				; CODE XREF: ReleaseLevel+132j
//@ 		mov	n$0, 50h ; 'P'  ; int16_t
//@ 		jmp	short loc_1B792	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B78E:				; CODE XREF: ReleaseLevel+16Cj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSACT.PAS" 1173
//@ 
//@ loc_1B792:				; CODE XREF: ReleaseLevel+13Dj
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ ; #line	"CSACT.PAS" 1174
//@ 		mov	ax, es:[di]
//@ 		or	ax, es:[di+2]	; Logical Inclusive OR
//@ 		jz	short loc_1B7B6	; Jump if Zero (ZF=1)
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 
//@ loc_1B7B6:				; CODE XREF: ReleaseLevel+156j
//@ 		cmp	n$0, 63h ; 'c'  ; int16_t
//@ 		jnz	short loc_1B78E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1176
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1B7C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B7C4:				; CODE XREF: ReleaseLevel+1A1j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSACT.PAS" 1177
//@ 
//@ loc_1B7C8:				; CODE XREF: ReleaseLevel+173j
//@ 		imul	di, n$0, 0Eh	; int16_t
//@ 		add	di, 0F5C2h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 1178
//@ 		mov	ax, es:[di]
//@ 		or	ax, es:[di+2]	; Logical Inclusive OR
//@ 		jz	short loc_1B7EB	; Jump if Zero (ZF=1)
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+6]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 
//@ loc_1B7EB:				; CODE XREF: ReleaseLevel+18Bj
//@ 		cmp	n$0, 1Fh	; int16_t
//@ 		jnz	short loc_1B7C4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1179
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ReleaseLevel	endp
//@ 
//@ ; #line	"CSACT.PAS" 1183
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadGFXIndex	proc near		; CODE XREF: ReloadResources+12Fp
//@ 
//@ var_202		= byte ptr -202h
//@ var_102		= byte ptr -102h
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1184
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1B802	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B7FF:				; CODE XREF: LoadGFXIndex+FFj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 1186
//@ 
//@ loc_1B802:				; CODE XREF: LoadGFXIndex+9j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		mov	byte ptr [di+71A1h], 7
//@ ; #line	"CSACT.PAS" 1187
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1188
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	6
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1189
//@ 		mov	al, byte ptr S	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di-1246h]
//@ 		cmp	al, 2Eh	; '.'   ; Compare Two Operands
//@ 		jz	short loc_1B863	; Jump if Zero (ZF=1)
//@ 		cmp	al, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jnz	short loc_1B8D5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1191
//@ 
//@ loc_1B863:				; CODE XREF: LoadGFXIndex+69j
//@ 		mov	al, byte ptr S	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 0		; Integer Subtraction
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-1246h], 6Fh ; 'o' ; Compare Two Operands
//@ 		jnz	short loc_1B87F	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		sub	byte ptr [di+71A1h], 4 ; Integer Subtraction
//@ ; #line	"CSACT.PAS" 1192
//@ 
//@ loc_1B87F:				; CODE XREF: LoadGFXIndex+7Ej
//@ 		mov	al, byte ptr S	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-1246h], 73h ; 's' ; Compare Two Operands
//@ 		jnz	short loc_1B899	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		sub	byte ptr [di+71A1h], 2 ; Integer Subtraction
//@ ; #line	"CSACT.PAS" 1193
//@ 
//@ loc_1B899:				; CODE XREF: LoadGFXIndex+98j
//@ 		mov	al, byte ptr S	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-1246h], 67h ; 'g' ; Compare Two Operands
//@ 		jnz	short loc_1B8B3	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		dec	byte ptr [di+71A1h] ; Decrement	by 1
//@ ; #line	"CSACT.PAS" 1194
//@ 
//@ loc_1B8B3:				; CODE XREF: LoadGFXIndex+B3j
//@ 		sub	byte ptr S, 3	; char[256] // Pascal string
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1196
//@ 
//@ loc_1B8D5:				; CODE XREF: LoadGFXIndex+6Dj
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, [bp+n], 0Eh	; int16_t
//@ 		les	di, GFXindex	; char*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Dh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1197
//@ 		cmp	[bp+n],	77h ; 'w' ; int16_t
//@ 		jz	short loc_1B8F6	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1B7FF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1198
//@ 
//@ loc_1B8F6:				; CODE XREF: LoadGFXIndex+FDj
//@ 		mov	WallMask+77h, 3	; uint8_t[120]
//@ ; #line	"CSACT.PAS" 1199
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadGFXIndex	endp
//@ 
//@ ; #line	"CSACT.PAS" 1203
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitZPositions	proc near		; CODE XREF: LoadLevel+381p
//@ 					; LoadGame+4BEp
//@ 
//@ var_4		= dword	ptr -4
//@ ZPos		= byte ptr  4		; bool
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1204
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	0FFFFh
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1205
//@ 		les	di, FloorZHi	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		push	0FF80h
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1207
//@ 		mov	x$0, 2		; int16_t
//@ 		jmp	short loc_1B92C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B928:				; CODE XREF: InitZPositions+81j
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSACT.PAS" 1208
//@ 
//@ loc_1B92C:				; CODE XREF: InitZPositions+29j
//@ 		mov	y, 2		; int16_t
//@ 		jmp	short loc_1B938	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B934:				; CODE XREF: InitZPositions+7Aj
//@ 		inc	y		; int16_t
//@ ; #line	"CSACT.PAS" 1210
//@ 
//@ loc_1B938:				; CODE XREF: InitZPositions+35j
//@ 		mov	ax, x$0		; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		push	ax
//@ 		mov	ax, y		; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		push	ax
//@ 		mov	di, offset i	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset n$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetFloorLoHi	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1211
//@ 		mov	cl, byte ptr n$0 ; int16_t
//@ 		mov	dx, y		; int16_t
//@ 		mov	ax, x$0		; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, FloorZHi	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ ; #line	"CSACT.PAS" 1212
//@ 		cmp	y, 3Dh ; '='    ; int16_t
//@ 		jnz	short loc_1B934	; Jump if Not Zero (ZF=0)
//@ 		cmp	x$0, 3Dh ; '='  ; int16_t
//@ 		jnz	short loc_1B928	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1214
//@ 		mov	x$0, 8		; int16_t
//@ 		jmp	short loc_1B98C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B988:				; CODE XREF: InitZPositions+D7j
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSACT.PAS" 1215
//@ 
//@ loc_1B98C:				; CODE XREF: InitZPositions+89j
//@ 		mov	y, 8		; int16_t
//@ 		jmp	short loc_1B998	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B994:				; CODE XREF: InitZPositions+CFj
//@ 		inc	y		; int16_t
//@ ; #line	"CSACT.PAS" 1216
//@ 
//@ loc_1B998:				; CODE XREF: InitZPositions+95j
//@ 		mov	ax, x$0		; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		mov	ax, y		; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		call	GetFloorZ	; function near	PASCAL returns unsigned	char 'Byte'
//@ 		mov	cl, al
//@ 		mov	dx, y		; int16_t
//@ 		mov	ax, x$0		; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ 		cmp	y, 0F4h	; 'ô'   ; int16_t
//@ 		jnz	short loc_1B994	; Jump if Not Zero (ZF=0)
//@ 		cmp	x$0, 0F4h ; 'ô' ; int16_t
//@ 		jnz	short loc_1B988	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1218
//@ 		cmp	[bp+ZPos], 0	; bool
//@ 		jnz	short loc_1B9DF	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1BA70	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1219
//@ 
//@ loc_1B9DF:				; CODE XREF: InitZPositions+DDj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_1B9EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B9E6:				; CODE XREF: InitZPositions+170j
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSACT.PAS" 1220
//@ 
//@ loc_1B9EA:				; CODE XREF: InitZPositions+E7j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_1B9F5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B9F1:				; CODE XREF: InitZPositions+167j
//@ 		inc	y		; int16_t
//@ ; #line	"CSACT.PAS" 1221
//@ 
//@ loc_1B9F5:				; CODE XREF: InitZPositions+F2j
//@ 		imul	ax, y, 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, x$0, 2C0h	; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_1BA5F	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_1BA5F	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 1222
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74B0h], 0 ; Compare Two Operands
//@ 		jle	short loc_1BA57	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 1223
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+3]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, FloorZLo	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], al
//@ 		jmp	short loc_1BA5F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1224
//@ 
//@ loc_1BA57:				; CODE XREF: InitZPositions+12Ej
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+2], 0
//@ 
//@ loc_1BA5F:				; CODE XREF: InitZPositions+118j
//@ 					; InitZPositions+11Cj ...
//@ 		cmp	y, 3Fh ; '?'    ; int16_t
//@ 		jnz	short loc_1B9F1	; Jump if Not Zero (ZF=0)
//@ 		cmp	x$0, 3Fh ; '?'  ; int16_t
//@ 		jz	short locret_1BA70 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1B9E6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1225
//@ 
//@ locret_1BA70:				; CODE XREF: InitZPositions+DFj
//@ 					; InitZPositions+16Ej
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ InitZPositions	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aEnd_0		db 4,'#end'             ; DATA XREF: LoadNewSounds+37o
//@ aLevel_2	db 5,'LEVEL'            ; DATA XREF: LoadNewSounds+62o
//@ aSound_0	db 7,'\SOUND\'          ; DATA XREF: LoadNewSounds+7Ao
//@ ; #line	"CSACT.PAS" 1235
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadNewSounds	proc near		; CODE XREF: ReloadResources+177p
//@ 
//@ var_128		= byte ptr -128h
//@ var_102		= byte ptr -102h
//@ o		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ 
//@ 		enter	102h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1236
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jnb	short loc_1BA95	; Jump if Not Below (CF=0)
//@ 		jmp	locret_1BB42	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1237
//@ 
//@ loc_1BA95:				; CODE XREF: LoadNewSounds+9j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	[bp+o],	50h ; 'P' ; int16_t
//@ ; #line	"CSACT.PAS" 1238
//@ 
//@ loc_1BAB5:				; CODE XREF: LoadNewSounds+B8j
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd_0 ; "#end"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short locret_1BB42 ; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1240
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1241
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ss:[di+var_128], 0 ; Compare Two Operands
//@ 		jz	short loc_1BB21	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_2 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FFD8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aSound_0 ; "\\SOUND\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	[bp+o]		; int16_t
//@ 		call	LoadSound	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1242
//@ 
//@ loc_1BB21:				; CODE XREF: LoadNewSounds+5Aj
//@ 		inc	[bp+o]		; int16_t
//@ ; #line	"CSACT.PAS" 1243
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1244
//@ 		jmp	loc_1BAB5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1245
//@ 
//@ locret_1BB42:				; CODE XREF: LoadNewSounds+Bj
//@ 					; LoadNewSounds+41j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ LoadNewSounds	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aEnd_1		db 4,'#end'             ; DATA XREF: LoadAmbients+37o
//@ aLevel_3	db 5,'LEVEL'            ; DATA XREF: LoadAmbients+62o
//@ aAmb		db 5,'\amb\'            ; DATA XREF: LoadAmbients+7Ao
//@ ; #line	"CSACT.PAS" 1249
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadAmbients	proc near		; CODE XREF: ReloadResources+15Fp
//@ 
//@ var_128		= byte ptr -128h
//@ var_102		= byte ptr -102h
//@ o		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ 
//@ 		enter	102h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1250
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jnb	short loc_1BB65	; Jump if Not Below (CF=0)
//@ 		jmp	locret_1BC12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1251
//@ 
//@ loc_1BB65:				; CODE XREF: LoadAmbients+9j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+o],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 1252
//@ 
//@ loc_1BB85:				; CODE XREF: LoadAmbients+B8j
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd_1 ; "#end"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short locret_1BC12 ; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1254
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1255
//@ 		mov	di, [bp+arg_0]
//@ 		cmp	ss:[di+var_128], 0 ; Compare Two Operands
//@ 		jz	short loc_1BBF1	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_3 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FFD8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aAmb	; "\\amb\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	[bp+o]		; int16_t
//@ 		call	LoadAmb		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1256
//@ 
//@ loc_1BBF1:				; CODE XREF: LoadAmbients+5Aj
//@ 		inc	[bp+o]		; int16_t
//@ ; #line	"CSACT.PAS" 1257
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FED8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1258
//@ 		jmp	loc_1BB85	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1259
//@ 
//@ locret_1BC12:				; CODE XREF: LoadAmbients+Bj
//@ 					; LoadAmbients+41j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ LoadAmbients	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_1BC16	db 1,' '                ; DATA XREF: UpLoad3dObjects+119o
//@ 					; UpLoad3dObjects+13Do	...
//@ aLevel_4	db 5,'LEVEL'            ; DATA XREF: UpLoad3dObjects+1F1o
//@ 					; UpLoad3dObjects+239o
//@ a3d		db 4,'\3d\'             ; DATA XREF: UpLoad3dObjects+209o
//@ aAni_0		db 5,'\ani\'            ; DATA XREF: UpLoad3dObjects+251o
//@ ; #line	"CSACT.PAS" 1265
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpLoad3dObjects	proc near		; CODE XREF: ReloadResources+147p
//@ 
//@ var_286		= byte ptr -286h
//@ var_186		= byte ptr -186h
//@ var_86		= dword	ptr -86h
//@ AN		= byte ptr -82h		; char[61] // Pascal string
//@ var_81		= byte ptr -81h
//@ FO		= byte ptr -44h		; char[61] // Pascal string
//@ c		= byte ptr -7		; char
//@ o		= word ptr -2		; uint16_t
//@ arg_0		= word ptr  4
//@ 
//@ 		enter	286h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1266
//@ 		mov	[bp+o],	20h ; ' ' ; uint16_t
//@ ; #line	"CSACT.PAS" 1268
//@ 
//@ loc_1BC32:				; CODE XREF: UpLoad3dObjects+3Dj
//@ 					; UpLoad3dObjects+2B6j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text4Char ; Read(var f; var c:	Char{AL})
//@ 		mov	[bp+c],	al	; char
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ 		cmp	[bp+c],	3Bh ; ';' ; char
//@ 		jnz	short loc_1BC54	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 
//@ loc_1BC54:				; CODE XREF: UpLoad3dObjects+1Fj
//@ 		call	ChI		; function far PASCAL returns void
//@ 		cmp	[bp+c],	3Bh ; ';' ; char
//@ 		jnz	short loc_1BC68	; Jump if Not Zero (ZF=0)
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1BC32	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1269
//@ 
//@ loc_1BC68:				; CODE XREF: UpLoad3dObjects+34j
//@ 		cmp	[bp+c],	23h ; '#' ; char
//@ 		jnz	short loc_1BC71	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1BED9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1270
//@ 
//@ loc_1BC71:				; CODE XREF: UpLoad3dObjects+43j
//@ 		imul	di, [bp+o], 24h	; uint16_t
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_86], di
//@ 		mov	word ptr [bp+var_86+2],	es
//@ ; #line	"CSACT.PAS" 1272
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1273
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+17h], 1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CSACT.PAS" 1274
//@ 		lea	di, [bp+var_186] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1275
//@ 		mov	[bp+AN], 0	; char[61] // Pascal string
//@ ; #line	"CSACT.PAS" 1276
//@ 		mov	di, offset asc_1BC16 ; " "
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1BDC8	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1278
//@ 		lea	di, [bp+var_286] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_186] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1BC16 ; " "
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		push	ax
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+AN]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1279
//@ 		lea	di, [bp+var_286] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_186] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		mov	di, offset asc_1BC16 ; " "
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		push	ax
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1281
//@ 
//@ loc_1BDC8:				; CODE XREF: UpLoad3dObjects+12Aj
//@ 		cmp	[bp+var_81], 25h ; '%' ; Compare Two Operands
//@ 		jnz	short loc_1BDFA	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_186] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+AN]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	2
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		lea	di, [bp+AN]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+17h], 0
//@ ; #line	"CSACT.PAS" 1282
//@ 
//@ loc_1BDFA:				; CODE XREF: UpLoad3dObjects+1A4j
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	es:[di+8], ax
//@ 		cmp	word ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jle	short loc_1BE14	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		dec	word ptr es:[di+6] ; Decrement by 1
//@ ; #line	"CSACT.PAS" 1283
//@ 
//@ loc_1BE14:				; CODE XREF: UpLoad3dObjects+1E5j
//@ 		lea	di, [bp+var_186] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_4 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FFD8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a3d	; "\\3d\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		add	di, 1Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPOH		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1284
//@ 		cmp	[bp+AN], 0	; char[61] // Pascal string
//@ 		jz	short loc_1BEB5	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1285
//@ 		lea	di, [bp+var_186] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_4 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, [bp+arg_0]
//@ 		add	di, 0FFD8h	; Add
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aAni_0 ; "\\ani\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+AN]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+1Ch]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4800h]
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		add	di, 20h	; ' '   ; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		add	di, 1Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadAnimation	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1286
//@ 
//@ loc_1BEB5:				; CODE XREF: UpLoad3dObjects+231j
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	word ptr es:[di+1Ch]
//@ 		add	di, 12h		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_86]	; Load Full Pointer to ES:xx
//@ 		add	di, 14h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ScanLoHi	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1287
//@ 		inc	[bp+o]		; uint16_t
//@ ; #line	"CSACT.PAS" 1289
//@ 
//@ loc_1BED9:				; CODE XREF: UpLoad3dObjects+45j
//@ 		cmp	[bp+c],	23h ; '#' ; char
//@ 		jz	short loc_1BEE2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1BC32	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1290
//@ 
//@ loc_1BEE2:				; CODE XREF: UpLoad3dObjects+2B4j
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1291
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ UpLoad3dObjects	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_9		db 2,'@#'               ; DATA XREF: ReloadResources+Ao
//@ aLevel_5	db 5,'LEVEL'            ; DATA XREF: ReloadResources+37o
//@ aResource_	db 10,'\resource.'      ; DATA XREF: ReloadResources+4Bo
//@ aSky		db 5,'#sky='            ; DATA XREF: ReloadResources:loc_1C002o
//@ aCdtrack	db 9,'#cdtrack='        ; DATA XREF: ReloadResources:loc_1C022o
//@ aDepth_0	db 7,'#depth='          ; DATA XREF: ReloadResources:loc_1C041o
//@ aGfx_0		db 4,'#gfx'             ; DATA XREF: ReloadResources+123o
//@ aNewobjects	db 11,'#newobjects'     ; DATA XREF: ReloadResources+13Ao
//@ aAmbients	db 9,'#ambients'        ; DATA XREF: ReloadResources+152o
//@ aNewsounds	db 10,'#newsounds'      ; DATA XREF: ReloadResources+16Ao
//@ aEnd__0		db 5,'#end.'            ; DATA XREF: ReloadResources+180o
//@ ; #line	"CSACT.PAS" 1294
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReloadResources	proc far		; CODE XREF: LoadLevel+37AP
//@ 					; LoadGame+4B7P
//@ 
//@ var_328		= byte ptr -328h
//@ var_228		= byte ptr -228h
//@ var_12A		= word ptr -12Ah
//@ s		= byte ptr -128h	; char[256] // Pascal string
//@ var_127		= byte ptr -127h
//@ var_84		= byte ptr -84h
//@ lm		= byte ptr -28h		; char[5] // Pascal string
//@ n		= word ptr -22h		; int16_t
//@ mpres		= byte ptr -20h		; bool[31]
//@ 
//@ 		enter	328h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1295
//@ 		lea	di, [bp+var_228] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_9	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+lm]	; char[5] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	4
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1296
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_228] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_5 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+lm]	; char[5] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aResource_ ;	"\\resource."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+lm]	; char[5] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	TOpen		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1298
//@ 
//@ loc_1BFA7:				; CODE XREF: ReloadResources+18Cj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+var_328] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_228] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StLocase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1299
//@ 		cmp	[bp+s],	0	; char[256] // Pascal string
//@ 		jnz	short loc_1BFF8	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1300
//@ 
//@ loc_1BFF8:				; CODE XREF: ReloadResources+B0j
//@ 		cmp	[bp+var_127], 3Bh ; ';' ; Compare Two Operands
//@ 		jnz	short loc_1C002	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1301
//@ 
//@ loc_1C002:				; CODE XREF: ReloadResources+BAj
//@ 		mov	di, offset aSky	; "#sky="
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1C022	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	LoadSky		; function near	PASCAL returns void
//@ 		jmp	loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1302
//@ 
//@ loc_1C022:				; CODE XREF: ReloadResources+D1j
//@ 		mov	di, offset aCdtrack ; "#cdtrack="
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1C041	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	SetCDTrack	; function near	PASCAL returns void
//@ 		jmp	short loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1303
//@ 
//@ loc_1C041:				; CODE XREF: ReloadResources+F1j
//@ 		mov	di, offset aDepth_0 ; "#depth="
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1C060	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	SetDepth	; function near	PASCAL returns void
//@ 		jmp	short loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1304
//@ 
//@ loc_1C060:				; CODE XREF: ReloadResources+110j
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aGfx_0 ; "#gfx"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1C077	; Jump if Not Zero (ZF=0)
//@ 		call	LoadGFXIndex	; function near	PASCAL returns void
//@ 		jmp	short loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1305
//@ 
//@ loc_1C077:				; CODE XREF: ReloadResources+12Dj
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aNewobjects ; "#newobjects"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1C08F	; Jump if Not Zero (ZF=0)
//@ 		push	bp
//@ 		call	UpLoad3dObjects	; function nested near PASCAL returns void
//@ 		jmp	short loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1306
//@ 
//@ loc_1C08F:				; CODE XREF: ReloadResources+144j
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aAmbients ; "#ambients"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1C0A7	; Jump if Not Zero (ZF=0)
//@ 		push	bp
//@ 		call	LoadAmbients	; function nested near PASCAL returns void
//@ 		jmp	short loc_1C0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1307
//@ 
//@ loc_1C0A7:				; CODE XREF: ReloadResources+15Cj
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aNewsounds ;	"#newsounds"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1C0BD	; Jump if Not Zero (ZF=0)
//@ 		push	bp
//@ 		call	LoadNewSounds	; function nested near PASCAL returns void
//@ ; #line	"CSACT.PAS" 1308
//@ 
//@ loc_1C0BD:				; CODE XREF: ReloadResources+B2j
//@ 					; ReloadResources+BCj ...
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd__0 ; "#end."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C0D2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1BFA7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1309
//@ 
//@ loc_1C0D2:				; CODE XREF: ReloadResources+18Aj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4Text	; Close(var f: Text)
//@ ; #line	"CSACT.PAS" 1311
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1313
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_1C0EC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C0E8:				; CODE XREF: ReloadResources+1EDj
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSACT.PAS" 1314
//@ 
//@ loc_1C0EC:				; CODE XREF: ReloadResources+1A3j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_1C0F7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C0F3:				; CODE XREF: ReloadResources+1E6j
//@ 		inc	y		; int16_t
//@ 
//@ loc_1C0F7:				; CODE XREF: ReloadResources+1AEj
//@ 		imul	ax, y, 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, x$0, 2C0h	; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ ; #line	"CSACT.PAS" 1315
//@ 		mov	al, es:[di]
//@ ; #line	"CSACT.PAS" 1316
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_1C124	; Jump if Below	(CF=1)
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		ja	short loc_1C124	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		mov	di, ax
//@ 		mov	byte ptr [di-708Eh], 1
//@ 
//@ loc_1C124:				; CODE XREF: ReloadResources+1CEj
//@ 					; ReloadResources+1D2j
//@ 		cmp	y, 3Fh ; '?'    ; int16_t
//@ 		jnz	short loc_1C0F3	; Jump if Not Zero (ZF=0)
//@ 		cmp	x$0, 3Fh ; '?'  ; int16_t
//@ 		jnz	short loc_1C0E8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1318
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1320
//@ 		mov	c, 0		; uint8_t
//@ ; #line	"CSACT.PAS" 1321
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	PImBSeg, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1322
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1C14B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C148:				; CODE XREF: ReloadResources+23Fj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 1324
//@ 
//@ loc_1C14B:				; CODE XREF: ReloadResources+203j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		and	ax, 7		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_1C15A	; Jump if Not Zero (ZF=0)
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1325
//@ 
//@ loc_1C15A:				; CODE XREF: ReloadResources+210j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		cmp	byte ptr [di-708Eh], 0 ; Compare Two Operands
//@ 		jbe	short loc_1C17E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 1327
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_1C178	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_1C178	; Jump if Above	(CF=0 &	ZF=0)
//@ 		push	[bp+n]		; int16_t
//@ 		call	LoadFrame	; function near	PASCAL returns void
//@ 		jmp	short loc_1C17E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1328
//@ 
//@ loc_1C178:				; CODE XREF: ReloadResources+227j
//@ 					; ReloadResources+22Bj
//@ 		push	[bp+n]		; int16_t
//@ 		call	LoadSpryte	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1330
//@ 
//@ loc_1C17E:				; CODE XREF: ReloadResources+21Fj
//@ 					; ReloadResources+233j
//@ 		cmp	[bp+n],	76h ; 'v' ; int16_t
//@ 		jnz	short loc_1C148	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1331
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1333
//@ 		mov	[bp+mpres], 1	; bool[31]
//@ ; #line	"CSACT.PAS" 1334
//@ 		mov	[bp+n],	65h ; 'e' ; int16_t
//@ 		jmp	short loc_1C197	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C194:				; CODE XREF: ReloadResources+260j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_1C197:				; CODE XREF: ReloadResources+24Fj
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	[bp+di+var_84],	0
//@ 		cmp	[bp+n],	7Ah ; 'z' ; int16_t
//@ 		jnz	short loc_1C194	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1335
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_12A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_12A] ; Compare Two Operands
//@ 		jg	short loc_1C1D7	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1C1BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C1BA:				; CODE XREF: ReloadResources+292j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_1C1BD:				; CODE XREF: ReloadResources+275j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		mov	al, [di-5AD8h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	[bp+di+var_84],	1
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12A] ; Compare Two Operands
//@ 		jnz	short loc_1C1BA	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1336
//@ 
//@ loc_1C1D7:				; CODE XREF: ReloadResources+270j
//@ 		mov	[bp+n],	64h ; 'd' ; int16_t
//@ 		jmp	short loc_1C1E1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C1DE:				; CODE XREF: ReloadResources+2BEj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 1337
//@ 
//@ loc_1C1E1:				; CODE XREF: ReloadResources+299j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		cmp	[bp+di+var_84],	0 ; Compare Two	Operands
//@ 		jz	short loc_1C1F5	; Jump if Zero (ZF=1)
//@ 		push	[bp+n]		; int16_t
//@ 		call	UpLoadCaracter	; function far PASCAL returns void
//@ 		jmp	short loc_1C1FD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1338
//@ 
//@ loc_1C1F5:				; CODE XREF: ReloadResources+2A6j
//@ 		push	[bp+n]		; int16_t
//@ 		call	ReleaseCaracter	; function far PASCAL returns void
//@ 
//@ loc_1C1FD:				; CODE XREF: ReloadResources+2B0j
//@ 		cmp	[bp+n],	7Ah ; 'z' ; int16_t
//@ 		jnz	short loc_1C1DE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1340
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1342
//@ 		call	ReloadFloors	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1343
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1344
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ReloadResources	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aNoNetPlaces_	db 14,'No NET Places.'  ; DATA XREF: ScanMap+F3o
//@ ; #line	"CSACT.PAS" 1350
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScanMap		proc far		; CODE XREF: LoadLevel+375P
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1351
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_1C230	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C22C:				; CODE XREF: ScanMap+E4j
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSACT.PAS" 1352
//@ 
//@ loc_1C230:				; CODE XREF: ScanMap+9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_1C23B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C237:				; CODE XREF: ScanMap+DAj
//@ 		inc	y		; int16_t
//@ 
//@ loc_1C23B:				; CODE XREF: ScanMap+14j
//@ 		imul	ax, y, 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, x$0, 2C0h	; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSACT.PAS" 1353
//@ 		mov	al, es:[di]
//@ ; #line	"CSACT.PAS" 1354
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_1C276	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_1C276	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+14h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], al
//@ 		jmp	short loc_1C2F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1355
//@ 
//@ loc_1C276:				; CODE XREF: ScanMap+3Aj ScanMap+3Ej
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_1C2E9	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_1C2E9	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 1357
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1C2A6	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_1C2A6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1358
//@ 		mov	ax, 1
//@ 		mov	cx, Skill	; int16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		and	ax, es:[di+7]	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_1C2A4	; Jump if Not Zero (ZF=0)
//@ 		mov	byte ptr es:[di], 0
//@ 
//@ loc_1C2A4:				; CODE XREF: ScanMap+7Dj
//@ 		jmp	short loc_1C2C5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1360
//@ 
//@ loc_1C2A6:				; CODE XREF: ScanMap+62j ScanMap+69j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+7], 0 ;	Compare	Two Operands
//@ 		jz	short loc_1C2C5	; Jump if Zero (ZF=1)
//@ 		mov	ax, 1
//@ 		mov	cx, Skill	; int16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		and	ax, es:[di+7]	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_1C2C5	; Jump if Not Zero (ZF=0)
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"CSACT.PAS" 1361
//@ 
//@ loc_1C2C5:				; CODE XREF: ScanMap:loc_1C2A4j
//@ 					; ScanMap+8Dj ...
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		mov	es:[di+9], ax
//@ 		mov	al, es:[di+2]
//@ 		and	al, 7		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	es:[di+7], ax
//@ 		mov	ax, es:[di+7]
//@ 		shl	ax, 0Dh		; Shift	Logical	Left
//@ 		mov	es:[di+7], ax
//@ ; #line	"CSACT.PAS" 1362
//@ 		jmp	short loc_1C2F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1363
//@ 
//@ loc_1C2E9:				; CODE XREF: ScanMap+57j ScanMap+5Bj
//@ 		cmp	al, 0FAh ; 'ú'  ; Compare Two Operands
//@ 		jnz	short loc_1C2F4	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di], 0
//@ 
//@ loc_1C2F4:				; CODE XREF: ScanMap+53j ScanMap+C6j ...
//@ 		cmp	y, 3Fh ; '?'    ; int16_t
//@ 		jz	short loc_1C2FE	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1C237	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C2FE:				; CODE XREF: ScanMap+D8j
//@ 		cmp	x$0, 3Fh ; '?'  ; int16_t
//@ 		jz	short loc_1C308	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1C22C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1365
//@ 
//@ loc_1C308:				; CODE XREF: ScanMap+E2j
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1368
//@ 		cmp	NetPlace.plx+12h, 0 ; struct NetPlace$Element[32]
//@ 		jnz	short locret_1C31E ; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aNoNetPlaces_ ; "No NET Places."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1369
//@ 
//@ locret_1C31E:				; CODE XREF: ScanMap+F1j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ScanMap		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aTooManyChanges	db 17,'Too many changes.' ; DATA XREF: InitChanges+76o
//@ ; #line	"CSACT.PAS" 1374
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitChanges	proc near		; CODE XREF: LoadLevel+3FBp
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1375
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ChangesCount, ax ; int16_t
//@ ; #line	"CSACT.PAS" 1376
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_1C346	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C342:				; CODE XREF: InitChanges+8Cj
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSACT.PAS" 1377
//@ 
//@ loc_1C346:				; CODE XREF: InitChanges+Ej
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_1C351	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C34D:				; CODE XREF: InitChanges+85j
//@ 		inc	y		; int16_t
//@ ; #line	"CSACT.PAS" 1378
//@ 
//@ loc_1C351:				; CODE XREF: InitChanges+19j
//@ 		imul	ax, y, 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, x$0, 2C0h	; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ ; #line	"CSACT.PAS" 1379
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_1C3B2	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_1C3B2	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 1380
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74B8h], 0 ; Compare Two Operands
//@ 		jz	short loc_1C3B2	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1381
//@ 		mov	ax, ChangesCount ; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, PChanges	; TChangesList$Element*
//@ 		add	di, ax		; Add
//@ ; #line	"CSACT.PAS" 1383
//@ 		mov	ax, x$0		; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, y		; int16_t
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSACT.PAS" 1384
//@ 		inc	ChangesCount	; int16_t
//@ ; #line	"CSACT.PAS" 1385
//@ 		cmp	ChangesCount, 80h ; '€' ; int16_t
//@ 		jl	short loc_1C3B2	; Jump if Less (SF!=OF)
//@ 		mov	di, offset aTooManyChanges ; "Too many changes."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1386
//@ 
//@ loc_1C3B2:				; CODE XREF: InitChanges+39j
//@ 					; InitChanges+3Dj ...
//@ 		cmp	y, 3Fh ; '?'    ; int16_t
//@ 		jnz	short loc_1C34D	; Jump if Not Zero (ZF=0)
//@ 		cmp	x$0, 3Fh ; '?'  ; int16_t
//@ 		jnz	short loc_1C342	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1387
//@ 		cmp	ChangesCount, 0	; int16_t
//@ 		jnz	short loc_1C3E0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1388
//@ 		mov	ChangesCount, 1	; int16_t
//@ 		les	di, PChanges	; TChangesList$Element*
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		les	di, PChanges	; TChangesList$Element*
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSACT.PAS" 1389
//@ 
//@ loc_1C3E0:				; CODE XREF: InitChanges+93j
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1390
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ InitChanges	endp
//@ 
//@ ; #line	"CSACT.PAS" 1397
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ ; Attributes: bp-based frame
//@ 
//@ ReadCommand$0	proc near		; CODE XREF: LoadLinks+Fp
//@ 					; LoadTeleports+Fp ...
//@ 
//@ var_302		= byte ptr -302h
//@ var_202		= byte ptr -202h
//@ S		= byte ptr -102h	; char[256] // Pascal string
//@ C		= byte ptr -1		; char
//@ ReadCommand	= dword	ptr  4		; char[256] // Pascal string
//@ 
//@ 		enter	302h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1398
//@ 		mov	[bp+S],	0	; char[256] // Pascal string
//@ ; #line	"CSACT.PAS" 1400
//@ 
//@ loc_1C3F0:				; CODE XREF: ReadCommand$0+85j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text4Char ; Read(var f; var c:	Char{AL})
//@ 		mov	[bp+C],	al	; char
//@ 		call	@Write$qm4Text	; Write(var f: Text)
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
//@ ; #line	"CSACT.PAS" 1401
//@ 		cmp	[bp+C],	20h ; ' ' ; char
//@ 		jnz	short loc_1C460	; Jump if Not Zero (ZF=0)
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
//@ 		jnz	short loc_1C46E	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1C460:				; CODE XREF: ReadCommand$0+5Ej
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Eoln$qm4Text	; Eoln(var f: Text): Boolean{AL}
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1C3F0	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 1402
//@ 
//@ loc_1C46E:				; CODE XREF: ReadCommand$0+77j
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
//@ ; #line	"CSACT.PAS" 1403
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+ReadCommand] ; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1404
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1405
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ReadCommand$0	endp
//@ 
//@ ; #line	"CSACT.PAS" 1409
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReadRealMul$0	proc near		; CODE XREF: LoadMessage+C7p
//@ 					; LoadProcess+F7p ...
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
//@ ; #line	"CSACT.PAS" 1410
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text4Real ; Read(var f; var v:	Real{DX:BX:AX})
//@ 		mov	[bp+r],	ax	; real_t
//@ 		mov	[bp+var_4], bx
//@ 		mov	[bp+var_2], dx
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1411
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
//@ ; #line	"CSACT.PAS" 1412
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ ReadRealMul$0	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aEnd_2		db 4,'#end'             ; DATA XREF: LoadLinks+23o
//@ aLink		db 4,'link'             ; DATA XREF: LoadLinks+4Ao
//@ aFloor		db 5,'floor'            ; DATA XREF: LoadLinks+5Bo
//@ aShoot		db 5,'shoot'            ; DATA XREF: LoadLinks+6Co
//@ aReturn		db 6,'return'           ; DATA XREF: LoadLinks+7Do
//@ aReturnf	db 7,'returnf'          ; DATA XREF: LoadLinks+8Eo
//@ 					; LoadLinks+11Do
//@ aUnlock		db 6,'unlock'           ; DATA XREF: LoadLinks+9Fo
//@ aOnofflink	db 9,'onofflink'        ; DATA XREF: LoadLinks+B0o
//@ aDestroy	db 7,'destroy'          ; DATA XREF: LoadLinks+C1o
//@ asc_1C527	db 2,'##'               ; DATA XREF: LoadLinks+191o
//@ 					; LoadLinks+1C0o ...
//@ aUseKeyNeededLi	db 21,'Use key needed: link ' ; DATA XREF: LoadLinks+181o
//@ asc_1C540	db 1,' '                ; DATA XREF: LoadLinks+1B0o
//@ 					; LoadLinks+1DFo
//@ ; #line	"CSACT.PAS" 1416
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadLinks	proc near		; CODE XREF: LoadProFile+178p
//@ 
//@ var_41A		= byte ptr -41Ah
//@ var_31A		= byte ptr -31Ah
//@ var_21A		= byte ptr -21Ah
//@ var_11A		= byte ptr -11Ah
//@ var_116		= byte ptr -116h
//@ var_1A		= dword	ptr -1Ah
//@ s		= byte ptr -16h		; char[21] // Pascal string
//@ var_15		= byte ptr -15h
//@ 
//@ 		enter	41Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1417
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LinksCount, ax	; int16_t
//@ ; #line	"CSACT.PAS" 1419
//@ 
//@ loc_1C54B:				; CODE XREF: LoadLinks+22Bj
//@ 		lea	di, [bp+var_116] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand$0	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1420
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd_2 ; "#end"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1C574	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1C770	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1421
//@ 
//@ loc_1C574:				; CODE XREF: LoadLinks+2Dj
//@ 		cmp	[bp+var_15], 3Bh ; ';' ; Compare Two Operands
//@ 		jnz	short loc_1C587	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		jmp	loc_1C761	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1422
//@ 
//@ loc_1C587:				; CODE XREF: LoadLinks+36j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLink ; "link"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aFloor ; "floor"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aShoot ; "shoot"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aReturn ; "return"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aReturnf ; "returnf"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aUnlock ; "unlock"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aOnofflink ;	"onofflink"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aDestroy ; "destroy"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C612	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1C757	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1430
//@ 
//@ loc_1C612:				; CODE XREF: LoadLinks+54j
//@ 					; LoadLinks+65j ...
//@ 		imul	ax, LinksCount,	7 ; int16_t
//@ 		les	di, PLinks	; TLinksList$Element*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 1432
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	al, [bp+var_15]
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], al
//@ ; #line	"CSACT.PAS" 1433
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aReturnf ; "returnf"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1C672	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di], 52h ;	'R'
//@ ; #line	"CSACT.PAS" 1434
//@ 
//@ loc_1C672:				; CODE XREF: LoadLinks+127j
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 6Ch ;	'l' ; Compare Two Operands
//@ 		jz	short loc_1C67E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1C755	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1435
//@ 
//@ loc_1C67E:				; CODE XREF: LoadLinks+137j
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 78h ;	'x' ; Compare Two Operands
//@ 		jb	short loc_1C69C	; Jump if Below	(CF=1)
//@ 		jmp	loc_1C755	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1C69C:				; CODE XREF: LoadLinks+155j
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		ja	short loc_1C6BD	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_1C755	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1437
//@ 
//@ loc_1C6BD:				; CODE XREF: LoadLinks+176j
//@ 		lea	di, [bp+var_21A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aUseKeyNeededLi ; "Use key needed: link "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_11A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1C527 ; "##"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_1C540 ; " "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_31A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1C527 ; "##"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_1C540 ; " "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_41A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1C527 ; "##"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1441
//@ 
//@ loc_1C755:				; CODE XREF: LoadLinks+139j
//@ 					; LoadLinks+157j ...
//@ 		jmp	short loc_1C761	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1442
//@ 
//@ loc_1C757:				; CODE XREF: LoadLinks+CDj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1443
//@ 
//@ loc_1C761:				; CODE XREF: LoadLinks+42j
//@ 					; LoadLinks:loc_1C755j
//@ 		inc	LinksCount	; int16_t
//@ ; #line	"CSACT.PAS" 1444
//@ 		cmp	LinksCount, 80h	; '€' ; int16_t
//@ 		jge	short locret_1C770 ; Jump if Greater or	Equal (SF=OF)
//@ 		jmp	loc_1C54B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1445
//@ 
//@ locret_1C770:				; CODE XREF: LoadLinks+2Fj
//@ 					; LoadLinks+229j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadLinks	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aEnd_3		db 4,'#end'             ; DATA XREF: LoadTeleports+23o
//@ aTcenter	db 7,'tcenter'          ; DATA XREF: LoadTeleports+4Ao
//@ ; #line	"CSACT.PAS" 1450
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadTeleports	proc near		; CODE XREF: LoadProFile+162p
//@ 
//@ var_116		= byte ptr -116h
//@ var_1A		= dword	ptr -1Ah
//@ s		= byte ptr -16h		; char[21] // Pascal string
//@ var_15		= byte ptr -15h
//@ 
//@ 		enter	116h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1451
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	TCount,	ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1453
//@ 
//@ loc_1C788:				; CODE XREF: LoadTeleports+104j
//@ 		lea	di, [bp+var_116] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand$0	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1454
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd_3 ; "#end"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1C7B1	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1C886	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1455
//@ 
//@ loc_1C7B1:				; CODE XREF: LoadTeleports+2Dj
//@ 		cmp	[bp+var_15], 3Bh ; ';' ; Compare Two Operands
//@ 		jnz	short loc_1C7C4	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		jmp	loc_1C87B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1456
//@ 
//@ loc_1C7C4:				; CODE XREF: LoadTeleports+36j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTcenter ; "tcenter"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1C7D8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1C87B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1457
//@ 
//@ loc_1C7D8:				; CODE XREF: LoadTeleports+54j
//@ 		imul	ax, TCount, 0Ah	; uint16_t
//@ 		les	di, Tports	; TTPort$Element*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 1459
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1460
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4], 40h	; '@' ; Compare Two Operands
//@ 		jge	short loc_1C85B	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	word ptr es:[di+6], 40h	; '@' ; Compare Two Operands
//@ 		jge	short loc_1C85B	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 1461
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, es:[di+6]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSACT.PAS" 1462
//@ 
//@ loc_1C85B:				; CODE XREF: LoadTeleports+B7j
//@ 					; LoadTeleports+BEj
//@ 		mov	cl, byte ptr TCount ; uint16_t
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, TeleMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ ; #line	"CSACT.PAS" 1463
//@ 		inc	TCount		; uint16_t
//@ ; #line	"CSACT.PAS" 1465
//@ 
//@ loc_1C87B:				; CODE XREF: LoadTeleports+42j
//@ 					; LoadTeleports+56j
//@ 		cmp	TCount,	80h ; '€' ; uint16_t
//@ 		jnb	short locret_1C886 ; Jump if Not Below (CF=0)
//@ 		jmp	loc_1C788	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1466
//@ 
//@ locret_1C886:				; CODE XREF: LoadTeleports+2Fj
//@ 					; LoadTeleports+102j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadTeleports	endp
//@ 
//@ ; #line	"CSACT.PAS" 1470
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReadMess	proc near		; CODE XREF: LoadMessage+EAp
//@ 					; LoadMessage+111p ...
//@ 
//@ var_104		= byte ptr -104h
//@ var_4		= dword	ptr -4
//@ M		= dword	ptr  4		; struct TProLine
//@ 
//@ 		enter	104h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1471
//@ 		les	di, [bp+M]	; struct TProLine
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSACT.PAS" 1473
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	31h ; '1'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1474
//@ 		lea	di, [bp+var_104] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	31h ; '1'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1475
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		dec	byte ptr es:[di+4] ; Decrement by 1
//@ ; #line	"CSACT.PAS" 1476
//@ 		lea	di, [bp+var_104] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		push	32h ; '2'
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	31h ; '1'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1477
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di], 0FFFFh ; Compare Two Operands
//@ 		jnz	short locret_1C939 ; Jump if Not Zero (ZF=0)
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	CalcStringLen	; function far PASCAL returns unsigned int 'Word'
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"CSACT.PAS" 1479
//@ 
//@ locret_1C939:				; CODE XREF: ReadMess+95j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ ReadMess	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aBadMessNumber_	db 16,'Bad mess number.' ; DATA XREF: LoadMessage:loc_1C9F6o
//@ aDelay_0	db 5,'delay'            ; DATA XREF: LoadMessage+9Eo
//@ aTexta		db 6,'texta:'           ; DATA XREF: LoadMessage+D0o
//@ aTextb		db 6,'textb:'           ; DATA XREF: LoadMessage+F3o
//@ aTextc		db 6,'textc:'           ; DATA XREF: LoadMessage+11Ao
//@ aTextd		db 6,'textd:'           ; DATA XREF: LoadMessage+141o
//@ aTexte		db 6,'texte:'           ; DATA XREF: LoadMessage+168o
//@ aTextf		db 6,'textf:'           ; DATA XREF: LoadMessage+18Fo
//@ aTextg		db 6,'textg:'           ; DATA XREF: LoadMessage+1B6o
//@ aEnd_4		db 4,'#end'             ; DATA XREF: LoadMessage+1E2o
//@ aMessageLineToo	db 23,'Message line too long: ' ; DATA XREF: LoadMessage+228o
//@ ; #line	"CSACT.PAS" 1484
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadMessage	proc near		; CODE XREF: LoadProFile+12Dp
//@ 
//@ var_21A		= byte ptr -21Ah
//@ mnum		= word ptr -11Ah	; int16_t
//@ i		= word ptr -118h	; int16_t
//@ s		= byte ptr -116h	; char[21] // Pascal string
//@ var_115		= byte ptr -115h
//@ var_100		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ 
//@ 		enter	21Ah, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+var_100] ; char[256] //	Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSACT.PAS" 1485
//@ 		lea	di, [bp+var_100] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		push	5
//@ 		call	@Delete$qm6String7Integert2 ; Delete(var s: String; index: Integer; count: Integer)
//@ ; #line	"CSACT.PAS" 1486
//@ 		lea	di, [bp+var_100] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+i]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+mnum], ax	; int16_t
//@ ; #line	"CSACT.PAS" 1487
//@ 		cmp	[bp+mnum], 0	; int16_t
//@ 		jl	short loc_1C9F6	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+mnum], 0Fh	; int16_t
//@ 		jg	short loc_1C9F6	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jle	short loc_1CA00	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_1C9F6:				; CODE XREF: LoadMessage+44j
//@ 					; LoadMessage+4Bj
//@ 		mov	di, offset aBadMessNumber_ ; "Bad mess number."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1488
//@ 
//@ loc_1CA00:				; CODE XREF: LoadMessage+52j
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr es:[di+17Ah], 230h
//@ ; #line	"CSACT.PAS" 1490
//@ 
//@ loc_1CA13:				; CODE XREF: LoadMessage+1EEj
//@ 		lea	di, [bp+var_21A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand$0	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1491
//@ 		cmp	[bp+var_115], 3Bh ; ';' ; Compare Two Operands
//@ 		jnz	short loc_1CA3A	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1492
//@ 
//@ loc_1CA3A:				; CODE XREF: LoadMessage+8Cj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aDelay_0 ; "delay"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CA6C	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, 17Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 88h	; 'ˆ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	dx, 0C00h
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul$0	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1493
//@ 
//@ loc_1CA6C:				; CODE XREF: LoadMessage+A8j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTexta ; "texta:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CA8F	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ReadMess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1494
//@ 
//@ loc_1CA8F:				; CODE XREF: LoadMessage+DAj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTextb ; "textb:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CAB6	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, 36h	; '6'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ReadMess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1495
//@ 
//@ loc_1CAB6:				; CODE XREF: LoadMessage+FDj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTextc ; "textc:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CADD	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, 6Ch	; 'l'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ReadMess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1496
//@ 
//@ loc_1CADD:				; CODE XREF: LoadMessage+124j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTextd ; "textd:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CB04	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, 0A2h ; '¢'  ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ReadMess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1497
//@ 
//@ loc_1CB04:				; CODE XREF: LoadMessage+14Bj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTexte ; "texte:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CB2B	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, 0D8h ; 'Ø'  ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ReadMess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1498
//@ 
//@ loc_1CB2B:				; CODE XREF: LoadMessage+172j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTextf ; "textf:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CB52	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, 10Eh	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ReadMess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1499
//@ 
//@ loc_1CB52:				; CODE XREF: LoadMessage+199j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aTextg ; "textg:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CB79	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, 144h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ReadMess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1500
//@ 
//@ loc_1CB79:				; CODE XREF: LoadMessage+1C0j
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1501
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd_4 ; "#end"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1CB93	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1CA13	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1502
//@ 
//@ loc_1CB93:				; CODE XREF: LoadMessage+1ECj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_1CB9F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1CB9B:				; CODE XREF: LoadMessage+25Cj
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSACT.PAS" 1503
//@ 
//@ loc_1CB9F:				; CODE XREF: LoadMessage+1F7j
//@ 		imul	ax, [bp+i], 36h	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	CalcStringLen	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 138h	; Compare Two Operands
//@ 		jbe	short loc_1CBF9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 1504
//@ 		lea	di, [bp+var_21A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMessageLineToo ; "Message line too long: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	ax, [bp+i], 36h	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mnum], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1CBF9:				; CODE XREF: LoadMessage+220j
//@ 		cmp	[bp+i],	6	; int16_t
//@ 		jnz	short loc_1CB9B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1505
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1506
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ LoadMessage	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aPlayani	db 7,'playani'          ; DATA XREF: LoadAction+54o
//@ aP		db 1,'P'                ; DATA XREF: LoadAction+76o
//@ aStopani	db 7,'stopani'          ; DATA XREF: LoadAction+8Co
//@ aS		db 1,'S'                ; DATA XREF: LoadAction+AEo
//@ aExplode	db 7,'explode'          ; DATA XREF: LoadAction+C4o
//@ aE		db 1,'E'                ; DATA XREF: LoadAction+F2o
//@ aChange		db 6,'change'           ; DATA XREF: LoadAction+108o
//@ aMove		db 4,'move'             ; DATA XREF: LoadAction+147o
//@ aXmove		db 5,'xmove'            ; DATA XREF: LoadAction+19Eo
//@ aYmove		db 5,'ymove'            ; DATA XREF: LoadAction+1F5o
//@ aRotate		db 6,'rotate'           ; DATA XREF: LoadAction+24Co
//@ aUp		db 2,'up'               ; DATA XREF: LoadAction+2AFo
//@ aWaitout	db 7,'waitout'          ; DATA XREF: LoadAction+2FAo
//@ aDeath		db 5,'death'            ; DATA XREF: LoadAction+339o
//@ aQuake		db 5,'quake'            ; DATA XREF: LoadAction+3A8o
//@ aAmbient_0	db 7,'ambient'          ; DATA XREF: LoadAction+3FFo
//@ aLight		db 5,'light'            ; DATA XREF: LoadAction+456o
//@ aSource		db 6,'source'           ; DATA XREF: LoadAction+4B9o
//@ aUnlock_0	db 6,'unlock'           ; DATA XREF: LoadAction+552o
//@ aU		db 1,'U'                ; DATA XREF: LoadAction+55Eo
//@ aLock		db 4,'lock'             ; DATA XREF: LoadAction+58Ao
//@ asc_1CC80	db 1,'L'                ; DATA XREF: LoadAction+596o
//@ aWind		db 4,'wind'             ; DATA XREF: LoadAction+5C2o
//@ aW		db 1,'W'                ; DATA XREF: LoadAction+5CEo
//@ 		db 0
//@ 		db 0
//@ 		db 0
//@ 		db 0
//@ 		db 0
//@ 		db 0
//@ 		db 0
//@ 		db    0
//@ 		db  20h
//@ 		db  10h
//@ 		db 0A9h	; ©
//@ 		db    0
//@ 		db  1Ah
//@ 		db  70h	; p
//@ 		db 0AEh	; ®
//@ 		db    3
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ aS_0		db 2,'s:'               ; DATA XREF: LoadAction:loc_1D3FEo
//@ aTooManySubs_	db 14,'Too many subs.'  ; DATA XREF: LoadAction+787o
//@ aEnd_5		db 4,'#end'             ; DATA XREF: LoadAction+79Bo
//@ ; #line	"CSACT.PAS" 1512
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadAction	proc near		; CODE XREF: LoadProcess:loc_1DA1Ep
//@ 
//@ var_236		= byte ptr -236h
//@ var_136		= byte ptr -136h
//@ var_132		= byte ptr -132h
//@ var_36		= dword	ptr -36h
//@ var_32		= dword	ptr -32h
//@ i		= byte ptr -2Eh		; int16_t
//@ var_2C		= byte ptr -2Ch		; char[21] // Pascal string
//@ s		= byte ptr -16h		; char[21] // Pascal string
//@ var_15		= byte ptr -15h
//@ 
//@ 		enter	236h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1513
//@ 		imul	ax, pnum, 1E8h	; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_32], di
//@ 		mov	word ptr [bp+var_32+2],	es
//@ ; #line	"CSACT.PAS" 1515
//@ 
//@ loc_1CCD6:				; CODE XREF: LoadAction+7A7j
//@ 		lea	di, [bp+var_132] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand$0	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1516
//@ 		cmp	[bp+var_15], 3Bh ; ';' ; Compare Two Operands
//@ 		jnz	short loc_1CCFB	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1517
//@ 
//@ loc_1CCFB:				; CODE XREF: LoadAction+2Fj
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+20h], 1Bh ; Signed Multiply
//@ 		add	di, ax		; Add
//@ 		add	di, 38h	; '8'   ; Add
//@ 		mov	word ptr [bp+var_36], di
//@ 		mov	word ptr [bp+var_36+2],	es
//@ ; #line	"CSACT.PAS" 1519
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aPlayani ; "playani"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CD47	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	di, offset aP	; "P"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1520
//@ 
//@ loc_1CD47:				; CODE XREF: LoadAction+5Ej
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aStopani ; "stopani"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CD7F	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	di, offset aS	; "S"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1521
//@ 
//@ loc_1CD7F:				; CODE XREF: LoadAction+96j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aExplode ; "explode"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CDC3	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		mov	di, offset aE	; "E"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1522
//@ 
//@ loc_1CDC3:				; CODE XREF: LoadAction+CEj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChange ; "change"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CE02	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1523
//@ 
//@ loc_1CE02:				; CODE XREF: LoadAction+112j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMove ; "move"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CE59	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1524
//@ 
//@ loc_1CE59:				; CODE XREF: LoadAction+151j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aXmove ; "xmove"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CEB0	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1525
//@ 
//@ loc_1CEB0:				; CODE XREF: LoadAction+1A8j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aYmove ; "ymove"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CF07	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1526
//@ 
//@ loc_1CF07:				; CODE XREF: LoadAction+1FFj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aRotate ; "rotate"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CF6A	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+9], ax
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1527
//@ 
//@ loc_1CF6A:				; CODE XREF: LoadAction+256j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aUp	; "up"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CFB5	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+9], ax
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1528
//@ 
//@ loc_1CFB5:				; CODE XREF: LoadAction+2B9j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aWaitout ; "waitout"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1CFF4	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1529
//@ 
//@ loc_1CFF4:				; CODE XREF: LoadAction+304j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aDeath ; "death"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D063	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+13h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+15h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+17h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+19h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1530
//@ 
//@ loc_1D063:				; CODE XREF: LoadAction+343j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aQuake ; "quake"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D0BA	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+13h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+15h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+17h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+19h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1531
//@ 
//@ loc_1D0BA:				; CODE XREF: LoadAction+3B2j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aAmbient_0 ;	"ambient"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D111	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+13h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+15h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+17h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+19h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1532
//@ 
//@ loc_1D111:				; CODE XREF: LoadAction+409j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLight ; "light"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D174	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+13h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+15h], ax
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1533
//@ 
//@ loc_1D174:				; CODE XREF: LoadAction+460j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSource ; "source"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1D188	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1D20D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1534
//@ 
//@ loc_1D188:				; CODE XREF: LoadAction+4C3j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+13h], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1535
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+13h], 0Eh ; Signed Multiply
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ah
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+13h], ax
//@ ; #line	"CSACT.PAS" 1536
//@ 		cmp	word ptr es:[di+1], 40h	; '@' ; Compare Two Operands
//@ 		jge	short loc_1D1F5	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+1]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	es:[di+1], ax
//@ ; #line	"CSACT.PAS" 1537
//@ 
//@ loc_1D1F5:				; CODE XREF: LoadAction+525j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+3], 40h	; '@' ; Compare Two Operands
//@ 		jge	short loc_1D20D	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+3]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	es:[di+3], ax
//@ ; #line	"CSACT.PAS" 1539
//@ 
//@ loc_1D20D:				; CODE XREF: LoadAction+4C5j
//@ 					; LoadAction+53Dj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aUnlock_0 ; "unlock"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D245	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aU	; "U"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1540
//@ 
//@ loc_1D245:				; CODE XREF: LoadAction+55Cj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLock ; "lock"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D27D	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset asc_1CC80 ; "L"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1541
//@ 
//@ loc_1D27D:				; CODE XREF: LoadAction+594j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aWind ; "wind"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D2F1	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset aW	; "W"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+13h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+15h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+17h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+19h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1542
//@ 
//@ loc_1D2F1:				; CODE XREF: LoadAction+5CCj
//@ 		mov	al, [bp+var_15]
//@ 		mov	ah, 1
//@ 		mov	dx, 20h	; ' '
//@ 		call	@Set@GetElemOffset$q4Wordt1 ; Compute Set offset and bitmask
//@ 					; AL - Element number
//@ 					; AH - mask
//@ 					; DX - Set params
//@ 		mov	di, dx
//@ 		test	cs:[di+4249h], al ; Logical Compare
//@ 		jnz	short loc_1D30A	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1D43D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1544
//@ 
//@ loc_1D30A:				; CODE XREF: LoadAction+645j
//@ 		mov	al, [bp+var_15]
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], al
//@ ; #line	"CSACT.PAS" 1545
//@ 		mov	al, es:[di]
//@ 		cmp	al, 50h	; 'P'   ; Compare Two Operands
//@ 		jz	short loc_1D31E	; Jump if Zero (ZF=1)
//@ 		cmp	al, 53h	; 'S'   ; Compare Two Operands
//@ 		jnz	short loc_1D325	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1D31E:				; CODE XREF: LoadAction+658j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		dec	word ptr es:[di+1] ; Decrement by 1
//@ ; #line	"CSACT.PAS" 1546
//@ 
//@ loc_1D325:				; CODE XREF: LoadAction+65Cj
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		cmp	al, 57h	; 'W'   ; Compare Two Operands
//@ 		jz	short loc_1D337	; Jump if Zero (ZF=1)
//@ 		cmp	al, 64h	; 'd'   ; Compare Two Operands
//@ 		jz	short loc_1D337	; Jump if Zero (ZF=1)
//@ 		cmp	al, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_1D391	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1548
//@ 
//@ loc_1D337:				; CODE XREF: LoadAction+66Dj
//@ 					; LoadAction+671j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+13h], 40h ; '@' ; Compare Two Operands
//@ 		jge	short loc_1D34C	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+13h]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	es:[di+13h], ax
//@ ; #line	"CSACT.PAS" 1549
//@ 
//@ loc_1D34C:				; CODE XREF: LoadAction+67Fj
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+15h], 40h ; '@' ; Compare Two Operands
//@ 		jge	short loc_1D361	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+15h]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	es:[di+15h], ax
//@ ; #line	"CSACT.PAS" 1550
//@ 
//@ loc_1D361:				; CODE XREF: LoadAction+694j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+17h], 40h ; '@' ; Compare Two Operands
//@ 		jge	short loc_1D379	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+17h]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 100h	; Add
//@ 		mov	es:[di+17h], ax
//@ ; #line	"CSACT.PAS" 1551
//@ 
//@ loc_1D379:				; CODE XREF: LoadAction+6A9j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+19h], 40h ; '@' ; Compare Two Operands
//@ 		jge	short loc_1D391	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+19h]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 100h	; Add
//@ 		mov	es:[di+19h], ax
//@ ; #line	"CSACT.PAS" 1553
//@ 
//@ loc_1D391:				; CODE XREF: LoadAction+675j
//@ 					; LoadAction+6C1j
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+9]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	es:[di+9], ax
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+11h], ax
//@ ; #line	"CSACT.PAS" 1554
//@ 		lea	di, [bp+var_236] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_136] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StLocase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1555
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 6Ch ;	'l' ; Compare Two Operands
//@ 		jnz	short loc_1D3FE	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+9], ax
//@ ; #line	"CSACT.PAS" 1556
//@ 
//@ loc_1D3FE:				; CODE XREF: LoadAction+71Bj
//@ 		mov	di, offset aS_0	; "s:"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_1D436	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1557
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		push	2
//@ 		call	@Delete$qm6String7Integert2 ; Delete(var s: String; index: Integer; count: Integer)
//@ 		lea	di, [bp+var_2C]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+i]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		les	di, [bp+var_36]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+11h], ax
//@ ; #line	"CSACT.PAS" 1558
//@ 
//@ loc_1D436:				; CODE XREF: LoadAction+750j
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+20h] ; Increment by 1
//@ ; #line	"CSACT.PAS" 1561
//@ 
//@ loc_1D43D:				; CODE XREF: LoadAction+647j
//@ 		les	di, [bp+var_32]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+20h], 10h ; Compare Two	Operands
//@ 		jle	short loc_1D451	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, offset aTooManySubs_ ; "Too	many subs."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1562
//@ 
//@ loc_1D451:				; CODE XREF: LoadAction+785j
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1563
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd_5 ; "#end"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short locret_1D46A ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1CCD6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1564
//@ 
//@ locret_1D46A:				; CODE XREF: LoadAction+7A5j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadAction	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aBadProNumber_	db 15,'Bad pro number.' ; DATA XREF: LoadProcess:loc_1D5B9o
//@ aStartdelay	db 10,'startdelay'      ; DATA XREF: LoadProcess+D6o
//@ aBackwait	db 8,'backwait'         ; DATA XREF: LoadProcess+100o
//@ aSpeed		db 5,'speed'            ; DATA XREF: LoadProcess+12Ao
//@ aEnddelay	db 8,'enddelay'         ; DATA XREF: LoadProcess+153o
//@ aCheckgo	db 7,'checkgo'          ; DATA XREF: LoadProcess+17Do
//@ aCheckback	db 9,'checkback'        ; DATA XREF: LoadProcess+198o
//@ aMortal		db 6,'mortal'           ; DATA XREF: LoadProcess+1B3o
//@ aLightremap	db 10,'lightremap'      ; DATA XREF: LoadProcess+1CEo
//@ aLock_0		db 4,'lock'             ; DATA XREF: LoadProcess+1E9o
//@ aRedkey		db 6,'redkey'           ; DATA XREF: LoadProcess+204o
//@ aGreenkey	db 8,'greenkey'         ; DATA XREF: LoadProcess+21Fo
//@ aBluekey	db 7,'bluekey'          ; DATA XREF: LoadProcess+23Ao
//@ aWhitekey	db 8,'whitekey'         ; DATA XREF: LoadProcess+255o
//@ aLoops		db 5,'loops'            ; DATA XREF: LoadProcess+270o
//@ aLoopdelay	db 9,'loopdelay'        ; DATA XREF: LoadProcess+299o
//@ aOnmessage	db 9,'onmessage'        ; DATA XREF: LoadProcess+2C3o
//@ aFirstmessage	db 12,'firstmessage'    ; DATA XREF: LoadProcess+2ECo
//@ aLockmessage	db 11,'lockmessage'     ; DATA XREF: LoadProcess+315o
//@ aSfxon		db 5,'sfxon'            ; DATA XREF: LoadProcess+33Eo
//@ aSfxid		db 5,'sfxid'            ; DATA XREF: LoadProcess+367o
//@ aSfxposxy	db 8,'sfxposxy'         ; DATA XREF: LoadProcess+390o
//@ aLinkswitchat	db 12,'linkswitchat'    ; DATA XREF: LoadProcess+3E6o
//@ aBadSw_link	db 11,'Bad SW.Link'     ; DATA XREF: LoadProcess:loc_1D9C3o
//@ 					; LoadProcess+47Fo
//@ aTooManySw_Link	db 20,'Too many sw. linked.' ; DATA XREF: LoadProcess+498o
//@ aAction_0	db 7,'#action'          ; DATA XREF: LoadProcess+4A8o
//@ ; #line	"CSACT.PAS" 1569
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadProcess	proc near		; CODE XREF: LoadProFile+110p
//@ 
//@ var_21A		= byte ptr -21Ah
//@ var_122		= dword	ptr -122h
//@ var_11E		= dword	ptr -11Eh
//@ var_11A		= dword	ptr -11Ah
//@ s		= byte ptr -116h	; char[21] // Pascal string
//@ var_115		= byte ptr -115h
//@ var_100		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ 
//@ 		enter	21Ah, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+var_100] ; char[256] //	Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSACT.PAS" 1570
//@ 		lea	di, [bp+var_100] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		push	5
//@ 		call	@Delete$qm6String7Integert2 ; Delete(var s: String; index: Integer; count: Integer)
//@ ; #line	"CSACT.PAS" 1571
//@ 		lea	di, [bp+var_100] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset i	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	pnum, ax	; int16_t
//@ ; #line	"CSACT.PAS" 1572
//@ 		cmp	pnum, 0		; int16_t
//@ 		jl	short loc_1D5B9	; Jump if Less (SF!=OF)
//@ 		cmp	pnum, 3Fh ; '?' ; int16_t
//@ 		jg	short loc_1D5B9	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	i, 0		; int16_t
//@ 		jle	short loc_1D5C3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_1D5B9:				; CODE XREF: LoadProcess+42j
//@ 					; LoadProcess+49j
//@ 		mov	di, offset aBadProNumber_ ; "Bad pro number."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1573
//@ 
//@ loc_1D5C3:				; CODE XREF: LoadProcess+50j
//@ 		imul	ax, pnum, 1E8h	; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ ; #line	"CSACT.PAS" 1575
//@ 		mov	byte ptr es:[di], 1
//@ 		mov	word ptr es:[di+6], 8
//@ 		mov	word ptr es:[di+16h], 0FFFFh
//@ 		mov	word ptr es:[di+18h], 0FFFFh
//@ 		mov	byte ptr es:[di+3], 0FFh
//@ ; #line	"CSACT.PAS" 1576
//@ 		mov	word ptr es:[di+10h], 0FFFFh
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ 		mov	word ptr es:[di+14h], 0FFFFh
//@ ; #line	"CSACT.PAS" 1579
//@ 		imul	ax, pnum, 1E8h	; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_11A], di
//@ 		mov	word ptr [bp+var_11A+2], es
//@ ; #line	"CSACT.PAS" 1581
//@ 
//@ loc_1D610:				; CODE XREF: LoadProcess+4B4j
//@ 		lea	di, [bp+var_21A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		call	ReadCommand$0	; function near	PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1582
//@ 		cmp	[bp+var_115], 3Bh ; ';' ; Compare Two Operands
//@ 		jnz	short loc_1D637	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1583
//@ 
//@ loc_1D637:				; CODE XREF: LoadProcess+C4j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aStartdelay ; "startdelay"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D661	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 8		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 88h	; 'ˆ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	dx, 0C00h
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul$0	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1584
//@ 
//@ loc_1D661:				; CODE XREF: LoadProcess+E0j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aBackwait ; "backwait"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D68B	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 0Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 88h	; 'ˆ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	dx, 0C00h
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul$0	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1585
//@ 
//@ loc_1D68B:				; CODE XREF: LoadProcess+10Aj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSpeed ; "speed"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D6B4	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 6		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 81h	; ''
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul$0	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1586
//@ 
//@ loc_1D6B4:				; CODE XREF: LoadProcess+134j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnddelay ; "enddelay"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D6DE	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 1Eh		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 88h	; 'ˆ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	dx, 0C00h
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul$0	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1587
//@ 
//@ loc_1D6DE:				; CODE XREF: LoadProcess+15Dj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCheckgo ; "checkgo"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D6F9	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+3], 1
//@ ; #line	"CSACT.PAS" 1588
//@ 
//@ loc_1D6F9:				; CODE XREF: LoadProcess+187j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCheckback ;	"checkback"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D714	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+3], 2
//@ ; #line	"CSACT.PAS" 1589
//@ 
//@ loc_1D714:				; CODE XREF: LoadProcess+1A2j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMortal ; "mortal"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D72F	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+4], 1
//@ ; #line	"CSACT.PAS" 1590
//@ 
//@ loc_1D72F:				; CODE XREF: LoadProcess+1BDj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLightremap ; "lightremap"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D74A	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+5], 1
//@ ; #line	"CSACT.PAS" 1592
//@ 
//@ loc_1D74A:				; CODE XREF: LoadProcess+1D8j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLock_0 ; "lock"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D765	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+2], 0FFh
//@ ; #line	"CSACT.PAS" 1593
//@ 
//@ loc_1D765:				; CODE XREF: LoadProcess+1F3j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aRedkey ; "redkey"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D780	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+2], 1
//@ ; #line	"CSACT.PAS" 1594
//@ 
//@ loc_1D780:				; CODE XREF: LoadProcess+20Ej
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aGreenkey ; "greenkey"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D79B	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+2], 2
//@ ; #line	"CSACT.PAS" 1595
//@ 
//@ loc_1D79B:				; CODE XREF: LoadProcess+229j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aBluekey ; "bluekey"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D7B6	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+2], 3
//@ ; #line	"CSACT.PAS" 1596
//@ 
//@ loc_1D7B6:				; CODE XREF: LoadProcess+244j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aWhitekey ; "whitekey"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D7D1	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+2], 4
//@ ; #line	"CSACT.PAS" 1598
//@ 
//@ loc_1D7D1:				; CODE XREF: LoadProcess+25Fj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLoops ; "loops"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D7FA	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 0Eh		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 81h	; ''
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul$0	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1599
//@ 
//@ loc_1D7FA:				; CODE XREF: LoadProcess+27Aj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLoopdelay ;	"loopdelay"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D824	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 88h	; 'ˆ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		mov	dx, 0C00h
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	ReadRealMul$0	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1600
//@ 
//@ loc_1D824:				; CODE XREF: LoadProcess+2A3j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aOnmessage ;	"onmessage"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D84D	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+12h], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1601
//@ 
//@ loc_1D84D:				; CODE XREF: LoadProcess+2CDj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aFirstmessage ; "firstmessage"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D876	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+10h], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1602
//@ 
//@ loc_1D876:				; CODE XREF: LoadProcess+2F6j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLockmessage	; "lockmessage"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D89F	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+14h], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1603
//@ 
//@ loc_1D89F:				; CODE XREF: LoadProcess+31Fj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSfxon ; "sfxon"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D8C8	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+18h], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1604
//@ 
//@ loc_1D8C8:				; CODE XREF: LoadProcess+348j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSfxid ; "sfxid"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D8F1	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+16h], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1605
//@ 
//@ loc_1D8F1:				; CODE XREF: LoadProcess+371j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSfxposxy ; "sfxposxy"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1D947	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1606
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+1Ah], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+1Ch], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1607
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	es:[di+1Ah], ax
//@ 		mov	ax, es:[di+1Ch]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSACT.PAS" 1609
//@ 
//@ loc_1D947:				; CODE XREF: LoadProcess+39Aj
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLinkswitchat ; "linkswitchat"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1D95C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1DA09	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1D95C:				; CODE XREF: LoadProcess+3F0j
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+22h]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		add	di, 28h	; '('   ; Add
//@ 		mov	word ptr [bp+var_11E], di
//@ 		mov	word ptr [bp+var_11E+2], es
//@ ; #line	"CSACT.PAS" 1611
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11E] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_11E] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1612
//@ 		les	di, [bp+var_11E] ; Load	Full Pointer to	ES:xx
//@ 		imul	ax, es:[di+2], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_122], di
//@ 		mov	word ptr [bp+var_122+2], es
//@ ; #line	"CSACT.PAS" 1613
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_1D9C3	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		jbe	short loc_1D9CF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_1D9C3:				; CODE XREF: LoadProcess+456j
//@ 		mov	di, offset aBadSw_link ; "Bad SW.Link"
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ 		db 0EBh	; ë
//@ 		db  21h	; !
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1614
//@ 
//@ loc_1D9CF:				; CODE XREF: LoadProcess+45Aj
//@ 		les	di, [bp+var_122] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74B0h], 0FEh ; 'þ' ; Compare Two Operands
//@ 		jge	short loc_1D9F0	; Jump if Greater or Equal (SF=OF)
//@ 		mov	di, offset aBadSw_link ; "Bad SW.Link"
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1615
//@ 
//@ loc_1D9F0:				; CODE XREF: LoadProcess+47Dj
//@ 		les	di, [bp+var_11A] ; Load	Full Pointer to	ES:xx
//@ 		inc	word ptr es:[di+22h] ; Increment by 1
//@ 		cmp	word ptr es:[di+22h], 3	; Compare Two Operands
//@ 		jle	short loc_1DA09	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, offset aTooManySw_Link ; "Too many sw. linked."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1617
//@ 
//@ loc_1DA09:				; CODE XREF: LoadProcess+3F2j
//@ 					; LoadProcess+496j
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aAction_0 ; "#action"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1DA1E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1D610	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1618
//@ 
//@ loc_1DA1E:				; CODE XREF: LoadProcess+4B2j
//@ 		call	LoadAction	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1619
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1620
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ LoadProcess	endp
//@ 
//@ ; #line	"CSACT.PAS" 1624
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Stop3d		proc near		; CODE XREF: LoadProFile+14Ap
//@ 
//@ var_304		= byte ptr -304h
//@ var_204		= byte ptr -204h
//@ n		= byte ptr -104h	; int16_t
//@ i		= word ptr -102h	; int16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ 
//@ 		enter	304h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSACT.PAS" 1625
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	9
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1626
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+n]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+i],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 1627
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	byte ptr [di+74C4h], 0
//@ ; #line	"CSACT.PAS" 1628
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ Stop3d		endp
//@ 
//@ ; #line	"CSACT.PAS" 1631
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadEndCamera	proc near		; CODE XREF: LoadProFile+18Ep
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSACT.PAS" 1633
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	EndCamera.$cx, ax ; struct EndCamera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	EndCamera.cy, ax ; struct EndCamera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	EndCamera.cz, ax ; struct EndCamera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	EndCamera.$cl, ax ; struct EndCamera$Type
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	EndCamera.cfi, ax ; struct EndCamera$Type
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSACT.PAS" 1634
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadEndCamera	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_10		db 2,'@#'               ; DATA XREF: LoadProFile+54o
//@ 					; LoadProFile+7Fo
//@ aLevel_6	db 5,'LEVEL'            ; DATA XREF: LoadProFile+44o
//@ aProcess_	db 9,'\process.'        ; DATA XREF: LoadProFile+6Fo
//@ aProc		db 5,'#proc'            ; DATA XREF: LoadProFile:loc_1DC0Fo
//@ aMess		db 5,'#mess'            ; DATA XREF: LoadProFile:loc_1DC2Co
//@ aStopani_0	db 8,'#stopani'         ; DATA XREF: LoadProFile:loc_1DC49o
//@ aTeleports	db 10,'#teleports'      ; DATA XREF: LoadProFile:loc_1DC66o
//@ aLinks		db 6,'#links'           ; DATA XREF: LoadProFile+16Co
//@ aEndcamera	db 10,'#endcamera'      ; DATA XREF: LoadProFile+182o
//@ a__4		db 1,'.'                ; DATA XREF: LoadProFile+196o
//@ ; #line	"CSACT.PAS" 1638
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadProFile	proc far		; CODE XREF: LoadLevel+3F6P
//@ 					; LoadGame+4C6P
//@ 
//@ var_316		= byte ptr -316h
//@ var_216		= byte ptr -216h
//@ var_116		= byte ptr -116h
//@ var_1A		= dword	ptr -1Ah
//@ S		= byte ptr -16h		; char[21] // Pascal string
//@ var_15		= byte ptr -15h
//@ 
//@ 		enter	316h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1639
//@ 		les	di, PProc	; TProcess*
//@ 		push	es
//@ 		push	di
//@ 		push	7A00h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1640
//@ 		les	di, PLinks	; TLinksList$Element*
//@ 		push	es
//@ 		push	di
//@ 		push	380h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1641
//@ 		les	di, PMList	; TMessage*
//@ 		push	es
//@ 		push	di
//@ 		push	17C0h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1642
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	TCount,	ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1644
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_216] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_6 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_116] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_10 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aProcess_ ; "\\process."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_316] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_10 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	TOpen		; function far PASCAL returns void
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1646
//@ 
//@ loc_1DBBB:				; CODE XREF: LoadProFile+1A2j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+var_216] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_116] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StLocase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1647
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1648
//@ 		cmp	[bp+S],	0	; char[21] // Pascal string
//@ 		jnz	short loc_1DC06	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1DCA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1649
//@ 
//@ loc_1DC06:				; CODE XREF: LoadProFile+EAj
//@ 		cmp	[bp+var_15], 3Bh ; ';' ; Compare Two Operands
//@ 		jnz	short loc_1DC0F	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1DCA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1650
//@ 
//@ loc_1DC0F:				; CODE XREF: LoadProFile+F3j
//@ 		mov	di, offset aProc ; "#proc"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1DC2C	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	LoadProcess	; function near	PASCAL returns void
//@ 		jmp	short loc_1DCA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1651
//@ 
//@ loc_1DC2C:				; CODE XREF: LoadProFile+109j
//@ 		mov	di, offset aMess ; "#mess"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1DC49	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	LoadMessage	; function near	PASCAL returns void
//@ 		jmp	short loc_1DCA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1652
//@ 
//@ loc_1DC49:				; CODE XREF: LoadProFile+126j
//@ 		mov	di, offset aStopani_0 ;	"#stopani"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1DC66	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Stop3d		; function near	PASCAL returns void
//@ 		jmp	short loc_1DCA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1653
//@ 
//@ loc_1DC66:				; CODE XREF: LoadProFile+143j
//@ 		mov	di, offset aTeleports ;	"#teleports"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_1DC7E	; Jump if Zero (ZF=1)
//@ 		call	LoadTeleports	; function near	PASCAL returns void
//@ 		jmp	short loc_1DCA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1654
//@ 
//@ loc_1DC7E:				; CODE XREF: LoadProFile+160j
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLinks ; "#links"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1DC94	; Jump if Not Zero (ZF=0)
//@ 		call	LoadLinks	; function near	PASCAL returns void
//@ 		jmp	short loc_1DCA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1655
//@ 
//@ loc_1DC94:				; CODE XREF: LoadProFile+176j
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEndcamera ;	"#endcamera"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_1DCA8	; Jump if Not Zero (ZF=0)
//@ 		call	LoadEndCamera	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1656
//@ 
//@ loc_1DCA8:				; CODE XREF: LoadProFile+ECj
//@ 					; LoadProFile+F5j ...
//@ 		lea	di, [bp+S]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a__4	; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_1DCBC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1DBBB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1657
//@ 
//@ loc_1DCBC:				; CODE XREF: LoadProFile+1A0j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4Text	; Close(var f: Text)
//@ ; #line	"CSACT.PAS" 1658
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1659
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	x$0, ax		; int16_t
//@ 		jmp	short loc_1DCD6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1DCD2:				; CODE XREF: LoadProFile+212j
//@ 		inc	x$0		; int16_t
//@ ; #line	"CSACT.PAS" 1660
//@ 
//@ loc_1DCD6:				; CODE XREF: LoadProFile+1B9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_1DCE1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1DCDD:				; CODE XREF: LoadProFile+20Bj
//@ 		inc	y		; int16_t
//@ 
//@ loc_1DCE1:				; CODE XREF: LoadProFile+1C4j
//@ 		imul	ax, y, 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, x$0, 2C0h	; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 1661
//@ 		mov	al, es:[di]
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_1DD1D	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_1DD1D	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 1664
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74BAh]
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+9], ax
//@ ; #line	"CSACT.PAS" 1665
//@ 
//@ loc_1DD1D:				; CODE XREF: LoadProFile+1EAj
//@ 					; LoadProFile+1EEj
//@ 		cmp	y, 3Fh ; '?'    ; int16_t
//@ 		jnz	short loc_1DCDD	; Jump if Not Zero (ZF=0)
//@ 		cmp	x$0, 3Fh ; '?'  ; int16_t
//@ 		jnz	short loc_1DCD2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1667
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1668
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ LoadProFile	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_11		db 2,'@#'               ; DATA XREF: LoadFloorMap+1Fo
//@ 					; LoadFloorMap+4Ao ...
//@ aLevel_7	db 5,'LEVEL'            ; DATA XREF: LoadFloorMap+Fo
//@ 					; LoadFloorMap+161o
//@ aMap_		db 5,'\MAP.'            ; DATA XREF: LoadFloorMap+3Ao
//@ 					; LoadFloorMap+18Co
//@ ; #line	"CSACT.PAS" 1675
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadFloorMap	proc far		; CODE XREF: LoadLevel:loc_1E46BP
//@ 					; LoadGame+4C1P
//@ 
//@ var_308		= byte ptr -308h
//@ var_208		= byte ptr -208h
//@ var_108		= byte ptr -108h
//@ y		= word ptr -6		; uint16_t
//@ x		= word ptr -4		; uint16_t
//@ 
//@ 		enter	308h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1676
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_7 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_108] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_11 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aMap_ ; "\\MAP."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_308] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_11 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1677
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		push	3001h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1678
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset CellMap ; uint8_t[4096]
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1679
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset FloorMap ; uint8_t[4096]
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1680
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, DarkMap	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1681
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, AmbMap	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1682
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1683
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_1DE23	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1DE20:				; CODE XREF: LoadFloorMap+126j
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSACT.PAS" 1684
//@ 
//@ loc_1DE23:				; CODE XREF: LoadFloorMap+DDj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y],	ax	; uint16_t
//@ 		jmp	short loc_1DE2D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1DE2A:				; CODE XREF: LoadFloorMap+120j
//@ 		inc	[bp+y]		; uint16_t
//@ 
//@ loc_1DE2D:				; CODE XREF: LoadFloorMap+E7j
//@ 		mov	dx, [bp+y]	; uint16_t
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, DarkMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	cl, [di+14h]
//@ 		mov	dx, [bp+y]	; uint16_t
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, DarkMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ 		cmp	[bp+y],	3Fh ; '?' ; uint16_t
//@ 		jnz	short loc_1DE2A	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+x],	3Fh ; '?' ; uint16_t
//@ 		jnz	short loc_1DE20	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1685
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1688
//@ 		les	di, ShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FFFFh
//@ 		push	18h
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1689
//@ 		les	di, WShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	8000h
//@ 		push	18h
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1691
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_7 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_108] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_11 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aMap_ ; "\\MAP."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_308] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_11 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1692
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, ShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FFFFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1693
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, WShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	8000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1694
//@ 		les	di, ShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		les	di, ShadowMap2	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 1695
//@ 		les	di, WShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		les	di, WShadowMap2	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	8000h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1696
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1697
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ LoadFloorMap	endp
//@ 
//@ ; #line	"CSACT.PAS" 1700
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitLevelDefaults proc near		; CODE XREF: LoadLevel+32p LoadGame+4p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSACT.PAS" 1701
//@ 		mov	t1, 4		; uint16_t
//@ 		mov	GunShift, 40h ;	'@' ; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"CSACT.PAS" 1702
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LookVz,	ax	; int16_t
//@ ; #line	"CSACT.PAS" 1703
//@ 		mov	WXSize,	40h ; '@' ; int16_t
//@ 		mov	MapMode, 0	; bool
//@ ; #line	"CSACT.PAS" 1705
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr LastPainTime, ax ; int32_t
//@ 		mov	word ptr LastPainTime+2, ax ; int32_t
//@ ; #line	"CSACT.PAS" 1706
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr Time, ax ; int32_t
//@ 		mov	word ptr Time+2, ax ; int32_t
//@ ; #line	"CSACT.PAS" 1707
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	RCount,	ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	BCount,	ax	; uint16_t
//@ 		mov	ExMode,	0	; bool
//@ ; #line	"CSACT.PAS" 1708
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	TCount,	ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LCount,	ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SCount,	ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MnCount, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1709
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DCount,	ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ReCount, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	AmCount, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HolCount, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1710
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"CSACT.PAS" 1712
//@ 		les	di, TeleMap	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		push	0FFFFh
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1713
//@ 		les	di, Lights	; TLight*
//@ 		push	es
//@ 		push	di
//@ 		push	0C00h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1714
//@ 		les	di, Tports	; TTPort$Element*
//@ 		push	es
//@ 		push	di
//@ 		push	500h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1715
//@ 		les	di, VMask	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1716
//@ 		les	di, Flags	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1717
//@ 		mov	di, offset LevelChanges	; uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1718
//@ 		mov	di, offset ProcState ; uint16_t[4]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1719
//@ 		mov	di, offset EventsList ;	struct TEvent[16]
//@ 		push	ds
//@ 		push	di
//@ 		push	0A0h ; ' '
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1720
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ InitLevelDefaults endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_12		db 2,'@#'               ; DATA XREF: LoadLevel+55o
//@ 					; LoadLevel+80o
//@ aLevel_8	db 5,'LEVEL'            ; DATA XREF: LoadLevel+45o
//@ aMap__0		db 5,'\MAP.'            ; DATA XREF: LoadLevel+70o
//@ aNetnum		db 7,'+NetNum'          ; DATA XREF: LoadLevel+1C6o
//@ ; #line	"CSACT.PAS" 1730
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadLevel	proc far		; CODE XREF: PROGRAM+DADP PROGRAM+E07P ...
//@ 
//@ var_310		= byte ptr -310h
//@ var_210		= byte ptr -210h
//@ var_112		= byte ptr -112h
//@ var_110		= byte ptr -110h
//@ var_16		= dword	ptr -16h
//@ var_12		= word ptr -12h
//@ mt		= word ptr -10h		; struct TMT
//@ var_E		= word ptr -0Eh
//@ var_C		= word ptr -0Ch
//@ var_A		= byte ptr -0Ah
//@ var_9		= byte ptr -9
//@ m		= word ptr -8		; int16_t
//@ n		= word ptr -4		; int16_t
//@ 
//@ 		enter	310h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1731
//@ 		call	StartLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1732
//@ 		mov	FullMap, 0	; bool
//@ ; #line	"CSACT.PAS" 1733
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	takt, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1734
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MsTakt,	ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1735
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LCDTrack, ax	; int16_t
//@ ; #line	"CSACT.PAS" 1736
//@ 		mov	BLevelDef, 140h	; uint16_t
//@ ; #line	"CSACT.PAS" 1737
//@ 		mov	FirstTakt, 1	; bool
//@ ; #line	"CSACT.PAS" 1738
//@ 		mov	LastBorn, 0	; uint8_t
//@ ; #line	"CSACT.PAS" 1740
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1741
//@ 		call	InitLevelDefaults ; function near PASCAL returns void
//@ ; #line	"CSACT.PAS" 1742
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1744
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_210] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_8 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_110] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_12 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aMap__0 ; "\\MAP."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_310] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_12 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1745
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		push	8001h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1746
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, Map		; TLoc*
//@ 		push	es
//@ 		push	di
//@ 		push	0B000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1747
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	@FilePos$qm4File ; FilePos(var f): Longint{DX:AX}
//@ 		add	ax, 4000h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ ; #line	"CSACT.PAS" 1748
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset LtCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1749
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, Lights	; TLight*
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, LtCount, 0Ch ; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1750
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+m]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1752
//@ 		cmp	[bp+m],	57h ; 'W' ; int16_t
//@ 		jl	short loc_1E1BA	; Jump if Less (SF!=OF)
//@ 		mov	[bp+m],	57h ; 'W' ; int16_t
//@ ; #line	"CSACT.PAS" 1753
//@ 
//@ loc_1E1BA:				; CODE XREF: LoadLevel+139j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MCount,	ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1754
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXSCount, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	TotalKills, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	TotalKeys, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1755
//@ 		mov	di, offset NetPlace ; struct NetPlace$Element[32]
//@ 		push	ds
//@ 		push	di
//@ 		push	0C0h ; 'À'
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 1756
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1759
//@ 		mov	ax, [bp+m]	; int16_t
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jle	short loc_1E1F3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1E3CF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1E1F3:				; CODE XREF: LoadLevel+174j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1E1FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1E1F8:				; CODE XREF: LoadLevel+352j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 1761
//@ 
//@ loc_1E1FB:				; CODE XREF: LoadLevel+17Cj
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+mt]	; struct TMT
//@ 		push	ss
//@ 		push	di
//@ 		push	8
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1762
//@ 		cmp	[bp+var_C], 64h	; 'd' ; Compare Two Operands
//@ 		jz	short loc_1E219	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1E2C0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1765
//@ 
//@ loc_1E219:				; CODE XREF: LoadLevel+19Aj
//@ 		mov	al, [bp+var_A]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 5		; Add
//@ 		and	ax, 7		; Logical AND
//@ 		mov	dx, ax
//@ 		mov	ax, 7
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+var_A], al
//@ ; #line	"CSACT.PAS" 1766
//@ 		cmp	[bp+var_9], 0	; Compare Two Operands
//@ 		jb	short loc_1E23A	; Jump if Below	(CF=1)
//@ 		cmp	[bp+var_9], 1Fh	; Compare Two Operands
//@ 		jbe	short loc_1E25E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_1E23A:				; CODE XREF: LoadLevel+1B8j
//@ 		lea	di, [bp+var_112] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aNetnum ; "+NetNum"
//@ 		push	cs
//@ 		push	di
//@ 		mov	al, [bp+var_9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1767
//@ 
//@ loc_1E25E:				; CODE XREF: LoadLevel+1BEj
//@ 		cmp	[bp+var_9], 0	; Compare Two Operands
//@ 		jnz	short loc_1E28F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1769
//@ 		mov	ax, [bp+mt]	; struct TMT
//@ 		mov	Players.PlHx, ax ; struct TPlayerInfo[8]
//@ 		mov	ax, [bp+var_E]
//@ 		mov	Players.PlHy, ax ; struct TPlayerInfo[8]
//@ 		mov	al, [bp+var_A]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 0Dh		; Shift	Logical	Left
//@ 		mov	HFi, ax		; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.PFlags,	ax ; struct TPlayerInfo[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.InvTime, ax ; struct TPlayerInfo[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.RefTime, ax ; struct TPlayerInfo[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.GodTime, ax ; struct TPlayerInfo[8]
//@ ; #line	"CSACT.PAS" 1770
//@ 
//@ loc_1E28F:				; CODE XREF: LoadLevel+1E8j
//@ 		mov	al, [bp+var_9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 0E580h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 1771
//@ 		mov	ax, [bp+mt]	; struct TMT
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+var_E]
//@ 		mov	es:[di+2], ax
//@ 		mov	al, [bp+var_A]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 0Dh		; Shift	Logical	Left
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSACT.PAS" 1772
//@ 		jmp	loc_1E3C4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1774
//@ 
//@ loc_1E2C0:				; CODE XREF: LoadLevel+19Cj
//@ 		mov	ax, 1
//@ 		mov	cx, Skill	; int16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, [bp+var_9]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jg	short loc_1E2D9	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1E3C4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1775
//@ 
//@ loc_1E2D9:				; CODE XREF: LoadLevel+25Aj
//@ 		mov	ax, MCount	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSACT.PAS" 1777
//@ 		mov	ax, [bp+mt]	; struct TMT
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+var_E]
//@ 		mov	es:[di+2], ax
//@ 		mov	al, byte ptr [bp+var_C]
//@ 		mov	es:[di+0Ah], al
//@ ; #line	"CSACT.PAS" 1778
//@ 		mov	al, [bp+var_A]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 4		; Add
//@ 		and	ax, 7		; Logical AND
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSACT.PAS" 1779
//@ 		mov	ax, es:[di+4]
//@ 		mov	es:[di+0Ch], ax
//@ 		mov	byte ptr es:[di+0Bh], 0
//@ ; #line	"CSACT.PAS" 1781
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FB0h]
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSACT.PAS" 1782
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+10h] ; Unsigned	Multiplication of AL or	AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSACT.PAS" 1783
//@ 		mov	di, es:[di+4]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+10h] ; Unsigned	Multiplication of AL or	AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSACT.PAS" 1784
//@ 		mov	word ptr es:[di+14h], 0FFFFh
//@ ; #line	"CSACT.PAS" 1785
//@ 		mov	word ptr es:[di+8], 2
//@ ; #line	"CSACT.PAS" 1786
//@ 		mov	byte ptr es:[di+26h], 0
//@ ; #line	"CSACT.PAS" 1787
//@ 		mov	byte ptr es:[di+27h], 0
//@ ; #line	"CSACT.PAS" 1788
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FB4h]
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSACT.PAS" 1789
//@ 		mov	byte ptr es:[di+24h], 0
//@ ; #line	"CSACT.PAS" 1790
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CSACT.PAS" 1791
//@ 		inc	MCount		; uint16_t
//@ ; #line	"CSACT.PAS" 1793
//@ 
//@ loc_1E3C4:				; CODE XREF: LoadLevel+243j
//@ 					; LoadLevel+25Cj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jz	short loc_1E3CF	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1E1F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1794
//@ 
//@ loc_1E3CF:				; CODE XREF: LoadLevel+176j
//@ 					; LoadLevel+350j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1795
//@ 		cmp	Monsters, 0	; bool
//@ 		jnz	short loc_1E3EA	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MCount,	ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1796
//@ 
//@ loc_1E3EA:				; CODE XREF: LoadLevel+369j
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1798
//@ 		call	ScanMap		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1799
//@ 		call	ReloadResources	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1800
//@ 		push	1
//@ 		call	InitZPositions	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1803
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jg	short loc_1E46B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1E414	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1E411:				; CODE XREF: LoadLevel+3EFj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 1804
//@ 
//@ loc_1E414:				; CODE XREF: LoadLevel+395j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSACT.PAS" 1806
//@ 		mov	byte ptr es:[di+0Bh], 0
//@ ; #line	"CSACT.PAS" 1807
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FF0h]
//@ 		or	ax, [di+7FF2h]	; Logical Inclusive OR
//@ 		jnz	short loc_1E444	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		inc	byte ptr es:[di+0Bh] ; Increment by 1
//@ ; #line	"CSACT.PAS" 1808
//@ 
//@ loc_1E444:				; CODE XREF: LoadLevel+3C1j
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FF4h]
//@ 		or	ax, [di+7FF6h]	; Logical Inclusive OR
//@ 		jnz	short loc_1E463	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Bh], 2	; Add
//@ ; #line	"CSACT.PAS" 1809
//@ 
//@ loc_1E463:				; CODE XREF: LoadLevel+3DFj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jnz	short loc_1E411	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1812
//@ 
//@ loc_1E46B:				; CODE XREF: LoadLevel+390j
//@ 		call	LoadFloorMap	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1813
//@ 		call	LoadProFile	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1814
//@ 		call	InitChanges	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1815
//@ 		call	StartUpProcesses ; function far	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1817
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HRv, ax		; int16_t
//@ ; #line	"CSACT.PAS" 1818
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1E493	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1E490:				; CODE XREF: LoadLevel+43Fj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_1E493:				; CODE XREF: LoadLevel+414j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSACT.PAS" 1819
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+16h], ax
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_1E490	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1820
//@ 		mov	NextL, 0	; bool
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyDeath, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1821
//@ 		mov	word ptr RandSeed, 4567h ; int32_t
//@ 		mov	word ptr RandSeed+2, 123h ; int32_t
//@ ; #line	"CSACT.PAS" 1822
//@ 		mov	kod, 0		; uint8_t
//@ ; #line	"CSACT.PAS" 1823
//@ 		mov	Hz, 600h	; uint16_t
//@ ; #line	"CSACT.PAS" 1824
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MTime, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponPhase, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1825
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr Time, ax ; int32_t
//@ 		mov	word ptr Time+2, ax ; int32_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr ZTime,	ax ; int32_t
//@ 		mov	word ptr ZTime+2, ax ; int32_t
//@ ; #line	"CSACT.PAS" 1826
//@ 		mov	OAnimate, 0	; bool
//@ ; #line	"CSACT.PAS" 1827
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LoadPos, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1828
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ LoadLevel	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aTooLateToSaveT	db 27,'Too late to save this game!' ; DATA XREF: SaveGame+Bo
//@ a@_13		db 2,'@#'               ; DATA XREF: SaveGame+3Ao
//@ aChasm		db 5,'CHASM'            ; DATA XREF: SaveGame+2Ao
//@ a_sav		db 4,'.SAV'             ; DATA XREF: SaveGame+55o
//@ asc_1E531	db 2,'##'               ; DATA XREF: SaveGame+87o
//@ aLevel_9	db 5,'Level'            ; DATA XREF: SaveGame+77o
//@ aHealth		db 10,'   health '      ; DATA XREF: SaveGame+A2o
//@ a@_14		db 3,'@##'              ; DATA XREF: SaveGame+B2o
//@ aGameSaved_	db 11,'Game saved.'     ; DATA XREF: SaveGame+514o
//@ ; #line	"CSACT.PAS" 1836
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SaveGame	proc far		; CODE XREF: ProcessMenu+53AP
//@ 					; ProcessPreKeyboard+14CP
//@ 
//@ var_3B8		= byte ptr -3B8h
//@ var_2B8		= byte ptr -2B8h
//@ var_1B8		= byte ptr -1B8h
//@ Title		= byte ptr -0B8h	; char[40] // Pascal string
//@ F		= byte ptr -90h		; FILE
//@ LoadN		= word ptr  6		; int16_t
//@ 
//@ 		enter	3B8h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1837
//@ 		cmp	Players.Life, 0	; struct TPlayerInfo[8]
//@ 		jnz	short loc_1E56D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 1838
//@ 		mov	di, offset aTooLateToSaveT ; "Too late to save this game!"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	locret_1EA73	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1839
//@ 
//@ loc_1E56D:				; CODE XREF: SaveGame+9j
//@ 		mov	ax, [bp+LoadN]	; int16_t
//@ 		mov	LoadSaveY, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1840
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_2B8] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm ; "CHASM"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_1B8] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_13 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+LoadN]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_sav ; ".SAV"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"CSACT.PAS" 1841
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	@Rewrite$qm4File4Word ;	Rewrite(var f: File; recsize: Word)
//@ ; #line	"CSACT.PAS" 1842
//@ 		lea	di, [bp+var_2B8] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_9 ; "Level"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_1B8] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1E531 ; "##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, LevelN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aHealth ; "	 health	"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_3B8] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_14 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, Players.Life ; struct TPlayerInfo[8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+Title]	; char[40] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSACT.PAS" 1845
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+Title]	; char[40] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	28h ; '('
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1846
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset ServerVersion ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1847
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, PProc	; TProcess*
//@ 		assume es:nothing
//@ 		push	es
//@ 		push	di
//@ 		push	7A00h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1848
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, ShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FFFFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1849
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, WShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	8000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1851
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Hx	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1852
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Hy	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1853
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Hz	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1854
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset HFi	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1855
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LookVz ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1857
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LevelN ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1858
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Skill ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1859
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1860
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.WFlags ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1861
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.PFlags ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1862
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Armor ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1863
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Ammo	; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1864
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Life	; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1865
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.InvTime ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1866
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.RefTime ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1867
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.GodTime ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1868
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Plhz0 ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1869
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset takt	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1870
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Time	; int32_t
//@ 		push	ds
//@ 		push	di
//@ 		push	4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1871
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset BLevelDef ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1873
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset TotalKills ;	uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1875
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1876
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset DCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1877
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset RCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1878
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MnCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1879
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset BCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1880
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset SCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1881
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1882
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LtCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1883
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset AmCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1885
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MonstersList	; struct TMonster[90]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, MCount, 28h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1886
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset RocketList ;	struct TRocket[64]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, RCount, 18h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1887
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MinesList ; struct TMine[16]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, MnCount, 0Ah ; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1888
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, BlowsList	; TBlow*
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, BCount	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1889
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset SepList ; struct TSepPart[32]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, SCount, 16h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1890
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset BlowLights ;	struct TBlowLight[32]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, LCount, 12h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1891
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, Lights	; TLight*
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, LtCount, 0Ch ; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1892
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, AmCount, 1Fh ; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1894
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, Map		; TLoc*
//@ 		push	es
//@ 		push	di
//@ 		push	0B000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1895
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, Flags	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1896
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, VMask	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1898
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1899
//@ 		mov	CurTime, 1	; uint16_t
//@ ; #line	"CSACT.PAS" 1900
//@ 		mov	di, offset aGameSaved_ ; "Game saved."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1901
//@ 
//@ locret_1EA73:				; CODE XREF: SaveGame+15j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ SaveGame	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_15		db 2,'@#'               ; DATA XREF: LoadGame+2Co
//@ aChasm_0	db 5,'CHASM'            ; DATA XREF: LoadGame+1Co
//@ a_sav_0		db 4,'.SAV'             ; DATA XREF: LoadGame+47o
//@ aOldSaveFileFor	db 21,'Old save file format.' ; DATA XREF: LoadGame+8Eo
//@ ; #line	"CSACT.PAS" 1906
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadGame	proc far		; CODE XREF: PROGRAM+E5BP
//@ 
//@ var_280		= byte ptr -280h
//@ var_180		= byte ptr -180h
//@ F		= byte ptr -80h		; FILE
//@ LoadN		= word ptr  6		; int16_t
//@ 
//@ 		enter	280h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 1907
//@ 		call	InitLevelDefaults ; function near PASCAL returns void
//@ ; #line	"CSACT.PAS" 1908
//@ 		call	StartLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1909
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1911
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_280] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_0 ; "CHASM"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_180] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_15 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+LoadN]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_sav_0 ; ".SAV"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"CSACT.PAS" 1912
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ ; #line	"CSACT.PAS" 1913
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	28h ; '('
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ ; #line	"CSACT.PAS" 1915
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset w	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1916
//@ 		mov	ax, w		; uint16_t
//@ 		cmp	ax, ServerVersion ; uint16_t
//@ 		jz	short loc_1EB33	; Jump if Zero (ZF=1)
//@ 		mov	di, offset aOldSaveFileFor ; "Old save file format."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 1919
//@ 
//@ loc_1EB33:				; CODE XREF: LoadGame+8Cj
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1920
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, PProc	; TProcess*
//@ 		push	es
//@ 		push	di
//@ 		push	7A00h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1921
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		call	@FilePos$qm4File ; FilePos(var f): Longint{DX:AX}
//@ 		add	ax, 0FFFFh	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		add	ax, 8000h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ ; #line	"CSACT.PAS" 1922
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Hx	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1923
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Hy	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1924
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Hz	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1925
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset HFi	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1926
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LookVz ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1928
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LevelN ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1929
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Skill ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1930
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1931
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.WFlags ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1932
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.PFlags ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1933
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Armor ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1934
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Ammo	; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1935
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Life	; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1936
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.InvTime ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1937
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.RefTime ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1938
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.GodTime ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1939
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Players.Plhz0 ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1940
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset takt	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1941
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset Time	; int32_t
//@ 		push	ds
//@ 		push	di
//@ 		push	4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1942
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset BLevelDef ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1943
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset TotalKills ;	uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1945
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1947
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1948
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset DCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1949
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset RCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1950
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MnCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1951
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset BCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1952
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset SCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1953
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1954
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LtCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1955
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset AmCount ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1957
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1959
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MonstersList	; struct TMonster[90]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, MCount, 28h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1960
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset RocketList ;	struct TRocket[64]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, RCount, 18h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1961
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset MinesList ; struct TMine[16]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, MnCount, 0Ah ; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1962
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, BlowsList	; TBlow*
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, BCount	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1963
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset SepList ; struct TSepPart[32]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, SCount, 16h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1964
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset BlowLights ;	struct TBlowLight[32]
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, LCount, 12h	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1965
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, Lights	; TLight*
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, LtCount, 0Ch ; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1966
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, AmmoBags	; TAmmoBag*
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, AmCount, 1Fh ; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1968
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1970
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, Map		; TLoc*
//@ 		push	es
//@ 		push	di
//@ 		push	0B000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1971
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, Flags	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1972
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, VMask	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1973
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1975
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1977
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1978
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LCount,	ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1979
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyDeath, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 1980
//@ 		mov	ax, Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		mov	LastGunNumber, ax ; uint16_t
//@ ; #line	"CSACT.PAS" 1981
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.ev, ax	; struct TPlayerInfo[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.v, ax	; struct TPlayerInfo[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Players.sv, ax	; struct TPlayerInfo[8]
//@ 		mov	ax, Hx		; int16_t
//@ 		mov	Players.PlHx, ax ; struct TPlayerInfo[8]
//@ 		mov	ax, Hy		; int16_t
//@ 		mov	Players.PlHy, ax ; struct TPlayerInfo[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	HRv, ax		; int16_t
//@ ; #line	"CSACT.PAS" 1984
//@ 		call	ReloadResources	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1985
//@ 		push	0
//@ 		call	InitZPositions	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 1986
//@ 		call	LoadFloorMap	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1987
//@ 		call	LoadProFile	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1989
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1991
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ ; #line	"CSACT.PAS" 1992
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	2Ah ; '*'
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ ; #line	"CSACT.PAS" 1993
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, PProc	; TProcess*
//@ 		push	es
//@ 		push	di
//@ 		push	7A00h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1994
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, ShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FFFFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSACT.PAS" 1995
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		les	di, WShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	8000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		call	NextLoading	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 1997
//@ 		les	di, ShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		les	di, ShadowMap2	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 1998
//@ 		les	di, WShadowMap	; void*
//@ 		push	es
//@ 		push	di
//@ 		les	di, WShadowMap2	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	8000h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSACT.PAS" 1999
//@ 		lea	di, [bp+F]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ ; #line	"CSACT.PAS" 2000
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2002
//@ 		mov	CurTime, 1	; uint16_t
//@ ; #line	"CSACT.PAS" 2003
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LoadPos, ax	; uint16_t
//@ ; #line	"CSACT.PAS" 2004
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ LoadGame	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aKillsPlayer	db 14,' KILLS PLAYER '  ; DATA XREF: ShootMe+115o
//@ ; #line	"CSACT.PAS" 2012
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShootMe		proc far		; CODE XREF: ProcessDeathZone+314P
//@ 					; MakeBlow+16CP ...
//@ 
//@ var_10A		= byte ptr -10Ah
//@ var_A		= dword	ptr -0Ah
//@ p		= word ptr -6		; int16_t
//@ ow		= word ptr  6		; int16_t
//@ n		= word ptr  8		; int16_t
//@ lp		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	10Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2013
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CSACT.PAS" 2015
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_1F05F	; Jump if Zero (ZF=1)
//@ 		cmp	TeamMode, 1	; uint8_t
//@ 		jnz	short loc_1F05F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2016
//@ 		cmp	[bp+ow], 8	; int16_t
//@ 		jge	short loc_1F05F	; Jump if Greater or Equal (SF=OF)
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		mov	ax, [di-0FA0h]
//@ 		imul	di, [bp+ow], 58h ; int16_t
//@ 		cmp	ax, [di-0FA0h]	; Compare Two Operands
//@ 		jnz	short loc_1F05F	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1F16C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2018
//@ 
//@ loc_1F05F:				; CODE XREF: ShootMe+19j ShootMe+20j ...
//@ 		mov	ax, Skill	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mul	[bp+lp]		; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	[bp+p],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 2019
//@ 		push	5
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 6		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 3
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+p],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 2021
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+p]	; int16_t
//@ 		jl	short loc_1F0B1	; Jump if Less (SF!=OF)
//@ 		mov	al, byte ptr [bp+p] ; int16_t
//@ 		sub	es:[di+27h], al	; Integer Subtraction
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	[bp+p],	ax	; int16_t
//@ 		jmp	short loc_1F0D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2022
//@ 
//@ loc_1F0B1:				; CODE XREF: ShootMe+7Bj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	cx, ax
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	[bp+p],	ax	; int16_t
//@ 		mov	byte ptr es:[di+27h], 0
//@ ; #line	"CSACT.PAS" 2024
//@ 
//@ loc_1F0D6:				; CODE XREF: ShootMe+8Dj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+50h], 0	; Compare Two Operands
//@ 		jnz	short loc_1F0E7	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		sub	es:[di+28h], ax	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 2025
//@ 
//@ loc_1F0E7:				; CODE XREF: ShootMe+BCj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_1F0FC	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+28h]
//@ 		call	SetMePain	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2027
//@ 
//@ loc_1F0FC:				; CODE XREF: ShootMe+CCj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short locret_1F16C ; Jump if Greater (ZF=0 & SF=OF)
//@ ; #line	"CSACT.PAS" 2029
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+28h], ax
//@ ; #line	"CSACT.PAS" 2030
//@ 		cmp	[bp+ow], 8	; int16_t
//@ 		jge	short loc_1F154	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2032
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+ow]	; int16_t
//@ 		jz	short loc_1F122	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+ow], 58h ; int16_t
//@ 		inc	byte ptr [di-0FB0h] ; Increment	by 1
//@ ; #line	"CSACT.PAS" 2033
//@ 
//@ loc_1F122:				; CODE XREF: ShootMe+F6j
//@ 		lea	di, [bp+var_10A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		imul	di, [bp+ow], 58h ; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aKillsPlayer	; " KILLS PLAYER "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, 1		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2035
//@ 
//@ loc_1F154:				; CODE XREF: ShootMe+EEj
//@ 		cmp	[bp+lp], 64h ; 'd' ; int16_t
//@ 		jl	short loc_1F164	; Jump if Less (SF!=OF)
//@ 		push	[bp+n]		; int16_t
//@ 		call	ExplodePlayer	; function far PASCAL returns void
//@ 		jmp	short locret_1F16C ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2036
//@ 
//@ loc_1F164:				; CODE XREF: ShootMe+136j
//@ 		push	[bp+n]		; int16_t
//@ 		call	AddDeadPlayer	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2039
//@ 
//@ locret_1F16C:				; CODE XREF: ShootMe+3Aj ShootMe+E2j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ ShootMe		endp
//@ 
//@ ; #line	"CSACT.PAS" 2043
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessDeathZone proc near		; CODE XREF: ContinueProcess+2DAp
//@ 
//@ var_6		= dword	ptr -6
//@ var_2		= word ptr -2
//@ P		= word ptr  4		; int16_t
//@ zh		= word ptr  6		; int16_t
//@ zl		= word ptr  8		; int16_t
//@ y2		= word ptr  0Ah		; int16_t
//@ x2		= word ptr  0Ch		; int16_t
//@ y1		= word ptr  0Eh		; int16_t
//@ x1		= word ptr  10h		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2044
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1F182	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_1F185	; Jump if Zero (ZF=1)
//@ 
//@ loc_1F182:				; CODE XREF: ProcessDeathZone+9j
//@ 		jmp	locret_1F4AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2046
//@ 
//@ loc_1F185:				; CODE XREF: ProcessDeathZone+10j
//@ 		cmp	[bp+zl], 0	; int16_t
//@ 		jle	short loc_1F194	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+zl]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+zl], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2047
//@ 
//@ loc_1F194:				; CODE XREF: ProcessDeathZone+19j
//@ 		mov	ax, [bp+zh]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+zh], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2048
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jle	short loc_1F1AE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1F36B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F1AE:				; CODE XREF: ProcessDeathZone+39j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1F1B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F1B3:				; CODE XREF: ProcessDeathZone+1F8j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSACT.PAS" 2049
//@ 
//@ loc_1F1B7:				; CODE XREF: ProcessDeathZone+41j
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSACT.PAS" 2050
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_1F1D2	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F1D2:				; CODE XREF: ProcessDeathZone+5Dj
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, [bp+x1]	; int16_t
//@ 		jge	short loc_1F1DD	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F1DD:				; CODE XREF: ProcessDeathZone+68j
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, [bp+x2]	; int16_t
//@ 		jl	short loc_1F1E8	; Jump if Less (SF!=OF)
//@ 		jmp	loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F1E8:				; CODE XREF: ProcessDeathZone+73j
//@ 		mov	ax, es:[di+2]
//@ 		cmp	ax, [bp+y1]	; int16_t
//@ 		jge	short loc_1F1F4	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F1F4:				; CODE XREF: ProcessDeathZone+7Fj
//@ 		mov	ax, es:[di+2]
//@ 		cmp	ax, [bp+y2]	; int16_t
//@ 		jl	short loc_1F200	; Jump if Less (SF!=OF)
//@ 		jmp	loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2051
//@ 
//@ loc_1F200:				; CODE XREF: ProcessDeathZone+8Bj
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+zl]	; int16_t
//@ 		jge	short loc_1F20C	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F20C:				; CODE XREF: ProcessDeathZone+97j
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+zh]	; int16_t
//@ 		jle	short loc_1F218	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2053
//@ 
//@ loc_1F218:				; CODE XREF: ProcessDeathZone+A3j
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		sub	es:[di+12h], ax	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 2055
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	14h
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2056
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		push	32h ; '2'
//@ 		push	49h ; 'I'
//@ 		push	0
//@ 		call	AddSinglePart	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2057
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_1F25B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1F2FA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2058
//@ 
//@ loc_1F25B:				; CODE XREF: ProcessDeathZone+E6j
//@ 		cmp	word ptr es:[di+8], 9 ;	Compare	Two Operands
//@ 		jnz	short loc_1F265	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1F2F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F265:				; CODE XREF: ProcessDeathZone+F0j
//@ 		cmp	word ptr es:[di+8], 0Ah	; Compare Two Operands
//@ 		jnz	short loc_1F26F	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1F2F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2060
//@ 
//@ loc_1F26F:				; CODE XREF: ProcessDeathZone+FAj
//@ 		push	5
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_1F29A	; Jump if Not Below (CF=0)
//@ ; #line	"CSACT.PAS" 2061
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0BCh ; '¼'  ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ 		jmp	short loc_1F2B8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2062
//@ 
//@ loc_1F29A:				; CODE XREF: ProcessDeathZone+108j
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0D2h ; 'Ò'  ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2063
//@ 
//@ loc_1F2B8:				; CODE XREF: ProcessDeathZone+128j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 9
//@ 		mov	byte ptr es:[di+26h], 4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSACT.PAS" 2064
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jbe	short loc_1F2F8	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 2065
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di-8000h]
//@ 		or	ax, [di-7FFEh]	; Logical Inclusive OR
//@ 		jz	short loc_1F2F8	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 0Ah
//@ ; #line	"CSACT.PAS" 2066
//@ 
//@ loc_1F2F8:				; CODE XREF: ProcessDeathZone+F2j
//@ 					; ProcessDeathZone+FCj	...
//@ 		jmp	short loc_1F360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2069
//@ 
//@ loc_1F2FA:				; CODE XREF: ProcessDeathZone+E8j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		mov	byte ptr es:[di+26h], 5
//@ 		mov	word ptr es:[di+8], 10h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSACT.PAS" 2070
//@ 		mov	al, es:[di+0Ah]
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jz	short loc_1F320	; Jump if Zero (ZF=1)
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		jnz	short loc_1F342	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1F320:				; CODE XREF: ProcessDeathZone+1AAj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, 0C8h ; 'È'  ; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 8C0h	; Add
//@ 		push	ax
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	AddAmmoBag	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2071
//@ 
//@ loc_1F342:				; CODE XREF: ProcessDeathZone+1AEj
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0E8h ; 'è'  ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2073
//@ 
//@ loc_1F360:				; CODE XREF: ProcessDeathZone+5Fj
//@ 					; ProcessDeathZone+6Aj	...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jz	short loc_1F36B	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1F1B3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2078
//@ 
//@ loc_1F36B:				; CODE XREF: ProcessDeathZone+3Bj
//@ 					; ProcessDeathZone+1F6j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jle	short loc_1F37C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1F410	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F37C:				; CODE XREF: ProcessDeathZone+207j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1F385	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F381:				; CODE XREF: ProcessDeathZone+29Dj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_1F385:				; CODE XREF: ProcessDeathZone+20Fj
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSACT.PAS" 2079
//@ 		cmp	byte ptr es:[di+0Ah], 78h ; 'x' ; Compare Two Operands
//@ 		jnb	short loc_1F405	; Jump if Not Below (CF=0)
//@ ; #line	"CSACT.PAS" 2080
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jnz	short loc_1F405	; Jump if Not Zero (ZF=0)
//@ 		cmp	byte ptr es:[di+0Bh], 0FFh ; Compare Two Operands
//@ 		jz	short loc_1F405	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2081
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, [bp+x1]	; int16_t
//@ 		jl	short loc_1F405	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di]
//@ 		cmp	ax, [bp+x2]	; int16_t
//@ 		jge	short loc_1F405	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+2]
//@ 		cmp	ax, [bp+y1]	; int16_t
//@ 		jl	short loc_1F405	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+2]
//@ 		cmp	ax, [bp+y2]	; int16_t
//@ 		jge	short loc_1F405	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2082
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+zl]	; int16_t
//@ 		jl	short loc_1F405	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+zh]	; int16_t
//@ 		jg	short loc_1F405	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSACT.PAS" 2084
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
//@ ; #line	"CSACT.PAS" 2085
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	byte ptr es:[di+0Bh], 0FFh
//@ ; #line	"CSACT.PAS" 2086
//@ 
//@ loc_1F405:				; CODE XREF: ProcessDeathZone+22Bj
//@ 					; ProcessDeathZone+232j ...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jz	short loc_1F410	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1F381	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2090
//@ 
//@ loc_1F410:				; CODE XREF: ProcessDeathZone+209j
//@ 					; ProcessDeathZone+29Bj
//@ 		cmp	[bp+zl], 0	; int16_t
//@ 		jge	short loc_1F419	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_1F4AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2091
//@ 
//@ loc_1F419:				; CODE XREF: ProcessDeathZone+2A4j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1F424	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F420:				; CODE XREF: ProcessDeathZone+337j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_1F424:				; CODE XREF: ProcessDeathZone+2AEj
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ ; #line	"CSACT.PAS" 2092
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_1F4A0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+0Ah]
//@ 		cmp	ax, [bp+x1]	; int16_t
//@ 		jl	short loc_1F4A0	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+0Ah]
//@ 		cmp	ax, [bp+x2]	; int16_t
//@ 		jge	short loc_1F4A0	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, [bp+y1]	; int16_t
//@ 		jl	short loc_1F4A0	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, [bp+y2]	; int16_t
//@ 		jge	short loc_1F4A0	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2093
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, [bp+zl]	; int16_t
//@ 		jl	short loc_1F4A0	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, [bp+zh]	; int16_t
//@ 		jg	short loc_1F4A0	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSACT.PAS" 2095
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	[bp+P]		; int16_t
//@ 		push	n$0		; int16_t
//@ 		push	0C8h ; 'È'
//@ 		call	ShootMe		; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2096
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	640h
//@ 		push	14h
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2097
//@ 
//@ loc_1F4A0:				; CODE XREF: ProcessDeathZone+2CAj
//@ 					; ProcessDeathZone+2D3j ...
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short locret_1F4AA ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1F420	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2098
//@ 
//@ locret_1F4AA:				; CODE XREF: ProcessDeathZone:loc_1F182j
//@ 					; ProcessDeathZone+2A6j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Eh		; Return Near from Procedure
//@ ProcessDeathZone endp
//@ 
//@ ; #line	"CSACT.PAS" 2102
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetProcMessage	proc far		; CODE XREF: ExecuteEvent+26EP
//@ 					; StartProcess+8FP ...
//@ 
//@ o		= word ptr  6		; int16_t
//@ m		= word ptr  8		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSACT.PAS" 2103
//@ 		cmp	[bp+m],	0FFFFh	; int16_t
//@ 		jnz	short loc_1F4B9	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_1F523 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2104
//@ 
//@ loc_1F4B9:				; CODE XREF: SetProcMessage+7j
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_1F4C7	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_1F4DB	; Jump if Zero (ZF=1)
//@ 
//@ loc_1F4C7:				; CODE XREF: SetProcMessage+10j
//@ 		push	6Dh ; 'm'
//@ 		mov	al, byte ptr [bp+m] ; int16_t
//@ 		push	ax
//@ 		push	[bp+o]		; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2105
//@ 
//@ loc_1F4DB:				; CODE XREF: SetProcMessage+17j
//@ 		cmp	[bp+o],	0FFFFh	; int16_t
//@ 		jz	short loc_1F4EC	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2106
//@ 		mov	ax, [bp+o]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jz	short loc_1F4EC	; Jump if Zero (ZF=1)
//@ 		jmp	short locret_1F523 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2107
//@ 
//@ loc_1F4EC:				; CODE XREF: SetProcMessage+31j
//@ 					; SetProcMessage+3Aj
//@ 		cmp	ProcMessage.LTime, 0 ; struct ProcMessage$Type
//@ 		jle	short loc_1F4FD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2108
//@ 		mov	ax, ProcMessage.MessNum	; struct ProcMessage$Type
//@ 		cmp	ax, [bp+m]	; int16_t
//@ 		jnz	short loc_1F4FD	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_1F523 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2109
//@ 
//@ loc_1F4FD:				; CODE XREF: SetProcMessage+43j
//@ 					; SetProcMessage+4Bj
//@ 		imul	ax, [bp+m], 17Ch ; int16_t
//@ 		les	di, PMList	; TMessage*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+17Ah]
//@ 		mov	ProcMessage.LTime, ax ;	struct ProcMessage$Type
//@ ; #line	"CSACT.PAS" 2110
//@ 		mov	ax, [bp+m]	; int16_t
//@ 		mov	ProcMessage.MessNum, ax	; struct ProcMessage$Type
//@ ; #line	"CSACT.PAS" 2111
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	3Dh ; '='
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2112
//@ 
//@ locret_1F523:				; CODE XREF: SetProcMessage+9j
//@ 					; SetProcMessage+3Cj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ SetProcMessage	endp
//@ 
//@ ; #line	"CSACT.PAS" 2118
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StartProcess	proc far		; CODE XREF: CorrectProcesses+ADP
//@ 					; AnimateSwitches+BDP ...
//@ 
//@ var_10		= dword	ptr -10h
//@ var_C		= dword	ptr -0Ch
//@ var_8		= word ptr -8
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; int16_t
//@ owner		= word ptr  6		; int16_t
//@ pn		= word ptr  8		; int16_t
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2119
//@ 		imul	ax, [bp+pn], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSACT.PAS" 2121
//@ 		cmp	byte ptr es:[di+1], 0 ;	Compare	Two Operands
//@ 		jz	short loc_1F546	; Jump if Zero (ZF=1)
//@ 		jmp	locret_1F8CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2122
//@ 
//@ loc_1F546:				; CODE XREF: StartProcess+1Aj
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1F55B	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_1F55B	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_1F563	; Jump if Zero (ZF=1)
//@ 
//@ loc_1F55B:				; CODE XREF: StartProcess+24j
//@ 					; StartProcess+2Bj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+2], 0
//@ ; #line	"CSACT.PAS" 2124
//@ 
//@ loc_1F563:				; CODE XREF: StartProcess+32j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+2], 0Ah	; Compare Two Operands
//@ 		jnb	short loc_1F59E	; Jump if Not Below (CF=0)
//@ 		cmp	[bp+owner], 0	; int16_t
//@ 		jl	short loc_1F59E	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+owner], 8	; int16_t
//@ 		jge	short loc_1F59E	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2125
//@ 		mov	al, es:[di+2]
//@ 		dec	al		; Decrement by 1
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 10h
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		imul	di, [bp+owner],	58h ; int16_t
//@ 		and	ax, [di-0FACh]	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_1F59E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 2126
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+2], 0
//@ ; #line	"CSACT.PAS" 2128
//@ 
//@ loc_1F59E:				; CODE XREF: StartProcess+44j
//@ 					; StartProcess+4Aj ...
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+2], 0 ;	Compare	Two Operands
//@ 		jbe	short loc_1F5BE	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 2130
//@ 		cmp	word ptr es:[di+14h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1F5BB	; Jump if Zero (ZF=1)
//@ 		push	word ptr es:[di+14h]
//@ 		push	[bp+owner]	; int16_t
//@ 		call	SetProcMessage	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2131
//@ 
//@ loc_1F5BB:				; CODE XREF: StartProcess+86j
//@ 		jmp	locret_1F8CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2135
//@ 
//@ loc_1F5BE:				; CODE XREF: StartProcess+7Fj
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_1F5D9	; Jump if Zero (ZF=1)
//@ 		push	61h ; 'a'
//@ 		mov	al, byte ptr [bp+pn] ; int16_t
//@ 		push	ax
//@ 		push	[bp+owner]	; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2137
//@ 
//@ loc_1F5D9:				; CODE XREF: StartProcess+9Cj
//@ 		imul	ax, [bp+pn], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSACT.PAS" 2139
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1F60D	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+10h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1F60D	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2140
//@ 		push	word ptr es:[di+10h]
//@ 		push	[bp+owner]	; int16_t
//@ 		call	SetProcMessage	; function far PASCAL returns void
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+10h], 0FFFFh
//@ ; #line	"CSACT.PAS" 2141
//@ 
//@ loc_1F60D:				; CODE XREF: StartProcess+C8j
//@ 					; StartProcess+CFj
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1F62A	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+12h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1F62A	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2142
//@ 		push	word ptr es:[di+12h]
//@ 		push	[bp+owner]	; int16_t
//@ 		call	SetProcMessage	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2144
//@ 
//@ loc_1F62A:				; CODE XREF: StartProcess+EBj
//@ 					; StartProcess+F5j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+26h], 1
//@ ; #line	"CSACT.PAS" 2145
//@ 		mov	byte ptr es:[di+1], 1
//@ ; #line	"CSACT.PAS" 2146
//@ 		mov	ax, es:[di+8]
//@ 		mov	es:[di+24h], ax
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jnz	short loc_1F64D	; Jump if Not Zero (ZF=0)
//@ 		mov	word ptr es:[di+24h], 1
//@ ; #line	"CSACT.PAS" 2147
//@ 
//@ loc_1F64D:				; CODE XREF: StartProcess+11Ej
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1F696	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_1F696	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2148
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+1Eh], 0	; Compare Two Operands
//@ 		jle	short loc_1F696	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	EndDelay, 0	; int16_t
//@ 		jnz	short loc_1F696	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2150
//@ 		cmp	word ptr es:[di+1Eh], 71Ch ; Compare Two Operands
//@ 		jz	short loc_1F67D	; Jump if Zero (ZF=1)
//@ 		mov	ax, es:[di+1Eh]
//@ 		mov	EndDelay, ax	; int16_t
//@ 		jmp	short loc_1F688	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2151
//@ 
//@ loc_1F67D:				; CODE XREF: StartProcess+14Bj
//@ 		mov	BShadeLev, 34h ; '4' ; int16_t
//@ 		mov	EndOfTheGame, 1	; bool
//@ ; #line	"CSACT.PAS" 2152
//@ 
//@ loc_1F688:				; CODE XREF: StartProcess+154j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+12h]
//@ 		push	0FFFFh
//@ 		call	SetProcMessage	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2155
//@ 
//@ loc_1F696:				; CODE XREF: StartProcess+12Bj
//@ 					; StartProcess+132j ...
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+20h], 0	; Compare Two Operands
//@ 		jg	short loc_1F6A3	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	locret_1F8CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2156
//@ 
//@ loc_1F6A3:				; CODE XREF: StartProcess+177j
//@ 		mov	ax, es:[di+20h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_8], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jle	short loc_1F6B5	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_1F8CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F6B5:				; CODE XREF: StartProcess+189j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1F6BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F6BA:				; CODE XREF: StartProcess+3A4j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 2157
//@ 
//@ loc_1F6BD:				; CODE XREF: StartProcess+191j
//@ 		imul	ax, [bp+n], 1Bh	; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 38h	; '8'   ; Add
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"CSACT.PAS" 2158
//@ 		mov	al, es:[di]
//@ ; #line	"CSACT.PAS" 2159
//@ 		cmp	al, 73h	; 's'   ; Compare Two Operands
//@ 		jnz	short loc_1F6EC	; Jump if Not Zero (ZF=0)
//@ 		push	word ptr es:[di+13h]
//@ 		push	1
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+15h], ax
//@ 		jmp	loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2160
//@ 
//@ loc_1F6EC:				; CODE XREF: StartProcess+1AEj
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jz	short loc_1F6F8	; Jump if Zero (ZF=1)
//@ 		cmp	al, 79h	; 'y'   ; Compare Two Operands
//@ 		jz	short loc_1F6F8	; Jump if Zero (ZF=1)
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jnz	short loc_1F75A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2162
//@ 
//@ loc_1F6F8:				; CODE XREF: StartProcess+1C7j
//@ 					; StartProcess+1CBj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Bh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Dh], ax
//@ ; #line	"CSACT.PAS" 2163
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"CSACT.PAS" 2164
//@ 		mov	ax, es:[di+3]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+13h], ax
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+15h], ax
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+17h], ax
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+9]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+19h], ax
//@ ; #line	"CSACT.PAS" 2165
//@ 		jmp	loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2166
//@ 
//@ loc_1F75A:				; CODE XREF: StartProcess+1CFj
//@ 		cmp	al, 61h	; 'a'   ; Compare Two Operands
//@ 		jnz	short loc_1F7B3	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+17h]
//@ 		mov	word ptr [bp+var_10+2],	ax
//@ 		mov	ax, es:[di+13h]
//@ 		cmp	ax, word ptr [bp+var_10+2] ; Compare Two Operands
//@ 		jg	short loc_1F7B0	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	i, ax		; int16_t
//@ 		jmp	short loc_1F77A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F776:				; CODE XREF: StartProcess+287j
//@ 		inc	i		; int16_t
//@ ; #line	"CSACT.PAS" 2167
//@ 
//@ loc_1F77A:				; CODE XREF: StartProcess+24Dj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+15h]
//@ 		mov	ax, i		; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, AmbMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+19h]
//@ 		sub	ax, es:[di+15h]	; Integer Subtraction
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	al, es:[di+5]
//@ 		push	ax
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ 		mov	ax, i		; int16_t
//@ 		cmp	ax, word ptr [bp+var_10+2] ; Compare Two Operands
//@ 		jnz	short loc_1F776	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1F7B0:				; CODE XREF: StartProcess+248j
//@ 		jmp	loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2168
//@ 
//@ loc_1F7B3:				; CODE XREF: StartProcess+235j
//@ 		cmp	al, 55h	; 'U'   ; Compare Two Operands
//@ 		jnz	short loc_1F7CE	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+1], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+2], 0
//@ 		jmp	loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2169
//@ 
//@ loc_1F7CE:				; CODE XREF: StartProcess+28Ej
//@ 		cmp	al, 4Ch	; 'L'   ; Compare Two Operands
//@ 		jnz	short loc_1F7E9	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+1], 1E8h ; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+2], 0FFh
//@ 		jmp	loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2170
//@ 
//@ loc_1F7E9:				; CODE XREF: StartProcess+2A9j
//@ 		cmp	al, 75h	; 'u'   ; Compare Two Operands
//@ 		jnz	short loc_1F81A	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Bh], ax
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Fh], ax
//@ 		jmp	loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2171
//@ 
//@ loc_1F81A:				; CODE XREF: StartProcess+2C4j
//@ 		cmp	al, 6Ch	; 'l'   ; Compare Two Operands
//@ 		jnz	short loc_1F82C	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		mov	es:[di+7], ax
//@ 		jmp	loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2172
//@ 
//@ loc_1F82C:				; CODE XREF: StartProcess+2F5j
//@ 		cmp	al, 63h	; 'c'   ; Compare Two Operands
//@ 		jnz	short loc_1F856	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ 		jmp	short loc_1F8C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2173
//@ 
//@ loc_1F856:				; CODE XREF: StartProcess+307j
//@ 		cmp	al, 72h	; 'r'   ; Compare Two Operands
//@ 		jnz	short loc_1F8C3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2174
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Fh], ax
//@ ; #line	"CSACT.PAS" 2175
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"CSACT.PAS" 2177
//@ 		mov	ax, es:[di+3]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		mov	es:[di+13h], ax
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+7]	; Integer Subtraction
//@ 		mov	es:[di+15h], ax
//@ ; #line	"CSACT.PAS" 2178
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		mov	es:[di+17h], ax
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+9]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+7]	; Integer Subtraction
//@ 		mov	es:[di+19h], ax
//@ ; #line	"CSACT.PAS" 2180
//@ 
//@ loc_1F8C3:				; CODE XREF: StartProcess+1C2j
//@ 					; StartProcess+230j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jz	short locret_1F8CE ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1F6BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2183
//@ 
//@ locret_1F8CE:				; CODE XREF: StartProcess+1Cj
//@ 					; StartProcess:loc_1F5BBj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ StartProcess	endp
//@ 
//@ ; #line	"CSACT.PAS" 2192
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ CheckConflict	proc near		; CODE XREF: CheckLifePoint+86p
//@ 					; CheckLifePoint+ECp ...
//@ 
//@ var_10		= dword	ptr -10h
//@ yy2		= word ptr -0Ch		; int16_t
//@ xx2		= word ptr -0Ah		; int16_t
//@ yy1		= word ptr -8		; int16_t
//@ xx1		= word ptr -6		; int16_t
//@ CheckConflict	= byte ptr -1		; bool
//@ R2		= word ptr  4		; int16_t
//@ R1		= word ptr  6		; int16_t
//@ wy		= word ptr  8		; int16_t
//@ wx		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2193
//@ 		mov	[bp+CheckConflict], 0 ;	bool
//@ ; #line	"CSACT.PAS" 2194
//@ 		imul	ax, [bp+wy], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+wx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"CSACT.PAS" 2196
//@ 		mov	al, es:[di]
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jb	short loc_1F929	; Jump if Below	(CF=1)
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		ja	short loc_1F929	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 2197
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1F926	; Jump if Not Zero (ZF=0)
//@ 		mov	dx, [bp+wy]	; int16_t
//@ 		mov	ax, [bp+wx]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 54h ;	'T' ; Compare Two Operands
//@ 		jbe	short loc_1F929	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_1F926:				; CODE XREF: CheckConflict+3Bj
//@ 		jmp	loc_1F9EC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2198
//@ 
//@ loc_1F929:				; CODE XREF: CheckConflict+26j
//@ 					; CheckConflict+2Aj ...
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_1F982	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_1F982	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 2199
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+7]
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+xx1], ax	; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+7]
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+xx2], ax	; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+9]
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+yy1], ax	; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+9]
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+yy2], ax	; int16_t
//@ 		jmp	short loc_1F984	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1F982:				; CODE XREF: CheckConflict+5Fj
//@ 					; CheckConflict+63j
//@ 		jmp	short loc_1F9EC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2202
//@ 
//@ loc_1F984:				; CODE XREF: CheckConflict+AEj
//@ 		mov	ax, [bp+xx1]	; int16_t
//@ 		cmp	ax, [bp+xx2]	; int16_t
//@ 		jnz	short loc_1F9B8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2203
//@ 		mov	ax, [bp+yy1]	; int16_t
//@ 		sub	ax, [bp+R2]	; int16_t
//@ 		cmp	ax, cfy		; int16_t
//@ 		jge	short loc_1F9B8	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+yy2]	; int16_t
//@ 		add	ax, [bp+R2]	; int16_t
//@ 		cmp	ax, cfy		; int16_t
//@ 		jle	short loc_1F9B8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, cfx		; int16_t
//@ 		sub	ax, [bp+xx1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+R1]	; int16_t
//@ 		jge	short loc_1F9B8	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+CheckConflict], 1 ;	bool
//@ ; #line	"CSACT.PAS" 2204
//@ 
//@ loc_1F9B8:				; CODE XREF: CheckConflict+B8j
//@ 					; CheckConflict+C4j ...
//@ 		mov	ax, [bp+yy1]	; int16_t
//@ 		cmp	ax, [bp+yy2]	; int16_t
//@ 		jnz	short loc_1F9EC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2205
//@ 		mov	ax, [bp+xx1]	; int16_t
//@ 		sub	ax, [bp+R2]	; int16_t
//@ 		cmp	ax, cfx		; int16_t
//@ 		jge	short loc_1F9EC	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+xx2]	; int16_t
//@ 		add	ax, [bp+R2]	; int16_t
//@ 		cmp	ax, cfx		; int16_t
//@ 		jle	short loc_1F9EC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, cfy		; int16_t
//@ 		sub	ax, [bp+yy1]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+R1]	; int16_t
//@ 		jge	short loc_1F9EC	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+CheckConflict], 1 ;	bool
//@ ; #line	"CSACT.PAS" 2206
//@ 
//@ loc_1F9EC:				; CODE XREF: CheckConflict:loc_1F926j
//@ 					; CheckConflict:loc_1F982j ...
//@ 		mov	al, [bp+CheckConflict] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ CheckConflict	endp
//@ 
//@ ; #line	"CSACT.PAS" 2232
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ CheckLifePoint	proc near		; CODE XREF: LifeConflict+4Bp
//@ 
//@ var_16		= dword	ptr -16h
//@ var_12		= word ptr -12h
//@ var_10		= dword	ptr -10h
//@ pc		= byte ptr -0Bh		; bool
//@ n		= word ptr -0Ah		; int16_t
//@ y		= word ptr -6		; int16_t
//@ x		= word ptr -4		; int16_t
//@ CheckLifePoint	= byte ptr -1		; bool
//@ _cfy		= word ptr  4		; int16_t
//@ _cfx		= word ptr  6		; int16_t
//@ pn		= word ptr  8		; int16_t
//@ 
//@ 		enter	16h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2233
//@ 		mov	ax, [bp+_cfx]	; int16_t
//@ 		mov	cfx, ax		; int16_t
//@ 		mov	ax, [bp+_cfy]	; int16_t
//@ 		mov	cfy, ax		; int16_t
//@ ; #line	"CSACT.PAS" 2234
//@ 		mov	[bp+CheckLifePoint], 0 ; bool
//@ ; #line	"CSACT.PAS" 2235
//@ 		mov	[bp+pc], 0	; bool
//@ ; #line	"CSACT.PAS" 2236
//@ 		imul	ax, [bp+pn], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ 		cmp	word ptr es:[di+20h], 0	; Compare Two Operands
//@ 		jle	short loc_1FA91	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2237
//@ 		mov	ax, es:[di+20h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_12], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jg	short loc_1FA91	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1FA3A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FA37:				; CODE XREF: CheckLifePoint+9Cj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 2238
//@ 
//@ loc_1FA3A:				; CODE XREF: CheckLifePoint+42j
//@ 		imul	ax, [bp+n], 1Bh	; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 38h	; '8'   ; Add
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSACT.PAS" 2239
//@ 		mov	al, es:[di]
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jz	short loc_1FA64	; Jump if Zero (ZF=1)
//@ 		cmp	al, 72h	; 'r'   ; Compare Two Operands
//@ 		jz	short loc_1FA64	; Jump if Zero (ZF=1)
//@ 		cmp	al, 75h	; 'u'   ; Compare Two Operands
//@ 		jz	short loc_1FA64	; Jump if Zero (ZF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jb	short loc_1FA89	; Jump if Below	(CF=1)
//@ 		cmp	al, 79h	; 'y'   ; Compare Two Operands
//@ 		ja	short loc_1FA89	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 2240
//@ 
//@ loc_1FA64:				; CODE XREF: CheckLifePoint+5Fj
//@ 					; CheckLifePoint+63j ...
//@ 		cmp	[bp+pc], 0	; bool
//@ 		jnz	short loc_1FA84	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		push	70h ; 'p'
//@ 		push	14h
//@ 		call	CheckConflict	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1FA84	; Jump if Not Zero (ZF=0)
//@ 		mov	al, 0
//@ 		jmp	short loc_1FA86	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FA84:				; CODE XREF: CheckLifePoint+75j
//@ 					; CheckLifePoint+8Bj
//@ 		mov	al, 1
//@ 
//@ loc_1FA86:				; CODE XREF: CheckLifePoint+8Fj
//@ 		mov	[bp+pc], al	; bool
//@ 
//@ loc_1FA89:				; CODE XREF: CheckLifePoint+6Bj
//@ 					; CheckLifePoint+6Fj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jnz	short loc_1FA37	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2242
//@ 
//@ loc_1FA91:				; CODE XREF: CheckLifePoint+2Ej
//@ 					; CheckLifePoint+3Dj
//@ 		cmp	[bp+pc], 0	; bool
//@ 		jnz	short loc_1FA99	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_1FAFC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2244
//@ 
//@ loc_1FA99:				; CODE XREF: CheckLifePoint+A2j
//@ 		mov	al, byte ptr cfx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	word ptr [bp+var_10+2],	ax
//@ 		mov	al, byte ptr cfx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, word ptr [bp+var_10+2] ; Compare Two Operands
//@ 		jg	short loc_1FAFC	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+x],	ax	; int16_t
//@ 		jmp	short loc_1FAB7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FAB4:				; CODE XREF: CheckLifePoint+107j
//@ 		inc	[bp+x]		; int16_t
//@ ; #line	"CSACT.PAS" 2245
//@ 
//@ loc_1FAB7:				; CODE XREF: CheckLifePoint+BFj
//@ 		mov	al, byte ptr cfy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	word ptr [bp+var_10], ax
//@ 		mov	al, byte ptr cfy+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, word ptr [bp+var_10] ; Compare Two Operands
//@ 		jg	short loc_1FAF4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+y],	ax	; int16_t
//@ 		jmp	short loc_1FAD5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FAD2:				; CODE XREF: CheckLifePoint+FFj
//@ 		inc	[bp+y]		; int16_t
//@ ; #line	"CSACT.PAS" 2246
//@ 
//@ loc_1FAD5:				; CODE XREF: CheckLifePoint+DDj
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		push	4Ah ; 'J'
//@ 		push	14h
//@ 		call	CheckConflict	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1FAEC	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2247
//@ 		mov	[bp+CheckLifePoint], 1 ; bool
//@ 		jmp	short loc_1FAFC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FAEC:				; CODE XREF: CheckLifePoint+F1j
//@ 		mov	ax, [bp+y]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_10] ; Compare Two Operands
//@ 		jnz	short loc_1FAD2	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1FAF4:				; CODE XREF: CheckLifePoint+D8j
//@ 		mov	ax, [bp+x]	; int16_t
//@ 		cmp	ax, word ptr [bp+var_10+2] ; Compare Two Operands
//@ 		jnz	short loc_1FAB4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2248
//@ 
//@ loc_1FAFC:				; CODE XREF: CheckLifePoint+A4j
//@ 					; CheckLifePoint+BAj ...
//@ 		mov	al, [bp+CheckLifePoint]	; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ CheckLifePoint	endp
//@ 
//@ ; #line	"CSACT.PAS" 2256
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ LifeConflict	proc near		; CODE XREF: ContinueProcess+22p
//@ 
//@ var_16		= dword	ptr -16h
//@ var_12		= word ptr -12h
//@ var_10		= dword	ptr -10h
//@ var_C		= dword	ptr -0Ch
//@ var_8		= word ptr -8
//@ p		= word ptr -6		; int16_t
//@ n		= word ptr -4		; int16_t
//@ LifeConflict	= byte ptr -1		; bool
//@ pn		= word ptr  4		; int16_t
//@ 
//@ 		enter	16h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2257
//@ 		imul	ax, [bp+pn], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		cmp	word ptr es:[di+20h], 0	; Compare Two Operands
//@ 		jnz	short loc_1FB1C	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1FD25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2258
//@ 
//@ loc_1FB1C:				; CODE XREF: LifeConflict+14j
//@ 		mov	[bp+LifeConflict], 0 ; bool
//@ ; #line	"CSACT.PAS" 2259
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+p],	ax	; int16_t
//@ 		jmp	short loc_1FB2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FB27:				; CODE XREF: LifeConflict+D2j
//@ 		inc	[bp+p]		; int16_t
//@ 
//@ loc_1FB2A:				; CODE XREF: LifeConflict+22j
//@ 		imul	di, [bp+p], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C+2], di
//@ 		mov	[bp+var_8], es
//@ ; #line	"CSACT.PAS" 2260
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_1FB43	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1FBCF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2261
//@ 
//@ loc_1FB43:				; CODE XREF: LifeConflict+3Bj
//@ 		push	[bp+pn]		; int16_t
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		call	CheckLifePoint	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1FBCF	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2263
//@ 		cmp	MortalTick, 0	; bool
//@ 		jz	short loc_1FBC8	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_C+2] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_1FBC8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2264
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1FBC8	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_1FBC8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2265
//@ 		imul	ax, [bp+pn], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+4], 0 ;	Compare	Two Operands
//@ 		jz	short loc_1FBC8	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2267
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		and	ax, 7		; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		add	ax, 28h	; '('   ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		les	di, [bp+var_C+2] ; Load	Full Pointer to	ES:xx
//@ 		sub	es:[di+28h], ax	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 2268
//@ 		cmp	[bp+p],	0	; int16_t
//@ 		jnz	short loc_1FBB0	; Jump if Not Zero (ZF=0)
//@ 		push	word ptr es:[di+28h]
//@ 		call	SetMePain	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2269
//@ 
//@ loc_1FBB0:				; CODE XREF: LifeConflict+A2j
//@ 		les	di, [bp+var_C+2] ; Load	Full Pointer to	ES:xx
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_1FBC8	; Jump if Greater (ZF=0	& SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+28h], ax
//@ 		push	[bp+p]		; int16_t
//@ 		call	AddDeadPlayer	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2271
//@ 
//@ loc_1FBC8:				; CODE XREF: LifeConflict+57j
//@ 					; LifeConflict+61j ...
//@ 		mov	[bp+LifeConflict], 1 ; bool
//@ 		jmp	loc_1FD25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2272
//@ 
//@ loc_1FBCF:				; CODE XREF: LifeConflict+3Dj
//@ 					; LifeConflict+50j
//@ 		cmp	[bp+p],	7	; int16_t
//@ 		jz	short loc_1FBD8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1FB27	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2275
//@ 
//@ loc_1FBD8:				; CODE XREF: LifeConflict+D0j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_8], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jle	short loc_1FBE9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1FD25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FBE9:				; CODE XREF: LifeConflict+E1j
//@ 		mov	[bp+p],	ax	; int16_t
//@ 		jmp	short loc_1FBF1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FBEE:				; CODE XREF: LifeConflict+21Fj
//@ 		inc	[bp+p]		; int16_t
//@ 
//@ loc_1FBF1:				; CODE XREF: LifeConflict+E9j
//@ 		imul	di, [bp+p], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_1FC0B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1FD1A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2277
//@ 
//@ loc_1FC0B:				; CODE XREF: LifeConflict+103j
//@ 		mov	ax, es:[di]
//@ 		mov	cfx, ax		; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	cfy, ax		; int16_t
//@ ; #line	"CSACT.PAS" 2278
//@ 		imul	ax, [bp+pn], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ 		cmp	word ptr es:[di+20h], 0	; Compare Two Operands
//@ 		jg	short loc_1FC33	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1FD1A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2279
//@ 
//@ loc_1FC33:				; CODE XREF: LifeConflict+12Bj
//@ 		mov	ax, es:[di+20h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_12], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jle	short loc_1FC45	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1FD1A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FC45:				; CODE XREF: LifeConflict+13Dj
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1FC4D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FC4A:				; CODE XREF: LifeConflict+214j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 2280
//@ 
//@ loc_1FC4D:				; CODE XREF: LifeConflict+145j
//@ 		imul	ax, [bp+n], 1Bh	; int16_t
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 38h	; '8'   ; Add
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ ; #line	"CSACT.PAS" 2281
//@ 		mov	al, es:[di]
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jz	short loc_1FC7D	; Jump if Zero (ZF=1)
//@ 		cmp	al, 72h	; 'r'   ; Compare Two Operands
//@ 		jz	short loc_1FC7D	; Jump if Zero (ZF=1)
//@ 		cmp	al, 75h	; 'u'   ; Compare Two Operands
//@ 		jz	short loc_1FC7D	; Jump if Zero (ZF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jnb	short loc_1FC76	; Jump if Not Below (CF=0)
//@ 		jmp	loc_1FD0F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FC76:				; CODE XREF: LifeConflict+16Ej
//@ 		cmp	al, 79h	; 'y'   ; Compare Two Operands
//@ 		jbe	short loc_1FC7D	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_1FD0F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2282
//@ 
//@ loc_1FC7D:				; CODE XREF: LifeConflict+162j
//@ 					; LifeConflict+166j ...
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		push	28h ; '('
//@ 		push	28h ; '('
//@ 		call	CheckConflict	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1FD0F	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2284
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+1], 1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+24h], ax
//@ ; #line	"CSACT.PAS" 2285
//@ 		mov	[bp+LifeConflict], 1 ; bool
//@ ; #line	"CSACT.PAS" 2286
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1FD0F	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_1FD0F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2287
//@ 		cmp	byte ptr es:[di+4], 0 ;	Compare	Two Operands
//@ 		jz	short loc_1FD0F	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2289
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+26h], 1	; Compare Two Operands
//@ 		jnz	short loc_1FCE9	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2291
//@ 		mov	byte ptr es:[di+26h], 4
//@ 		mov	word ptr es:[di+8], 9
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSACT.PAS" 2292
//@ 		push	cfx		; int16_t
//@ 		push	cfy		; int16_t
//@ 		push	400h
//@ 		push	10h
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2294
//@ 
//@ loc_1FCE9:				; CODE XREF: LifeConflict+1BFj
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+12h], ax	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 2295
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jg	short loc_1FD0F	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	byte ptr es:[di+26h], 5	; Compare Two Operands
//@ 		jz	short loc_1FD0F	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2296
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		mov	byte ptr es:[di+26h], 5
//@ ; #line	"CSACT.PAS" 2298
//@ 
//@ loc_1FD0F:				; CODE XREF: LifeConflict+170j
//@ 					; LifeConflict+177j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jz	short loc_1FD1A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1FC4A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2299
//@ 
//@ loc_1FD1A:				; CODE XREF: LifeConflict+105j
//@ 					; LifeConflict+12Dj ...
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jz	short loc_1FD25	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1FBEE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2300
//@ 
//@ loc_1FD25:				; CODE XREF: LifeConflict+16j
//@ 					; LifeConflict+C9j ...
//@ 		mov	al, [bp+LifeConflict] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ LifeConflict	endp
//@ 
//@ ; #line	"CSACT.PAS" 2308
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RemapWall	proc near		; CODE XREF: ContinueProcess+629p
//@ 					; ContinueProcess+D59p	...
//@ 
//@ var_10		= dword	ptr -10h
//@ Wshofs		= word ptr -0Ch		; uint16_t
//@ ddy		= word ptr -0Ah		; int16_t
//@ ddx		= word ptr -8		; int16_t
//@ y0		= word ptr -6		; int16_t
//@ x0		= word ptr -4		; int16_t
//@ wy		= word ptr  4		; uint16_t
//@ wx		= word ptr  6		; uint16_t
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2309
//@ 		imul	ax, [bp+wy], 0Bh ; uint16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+wx], 2C0h ; uint16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ 		cmp	byte ptr es:[di], 78h ;	'x' ; Compare Two Operands
//@ 		jbe	short loc_1FD54	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_1FE6E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 		db 0EBh	; ë
//@ 		db  33h	; 3
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2310
//@ 
//@ loc_1FD54:				; CODE XREF: RemapWall+21j
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		mov	[bp+x0], ax	; int16_t
//@ 		mov	ax, es:[di+9]
//@ 		mov	[bp+y0], ax	; int16_t
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, es:[di+7]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+ddx], ax	; int16_t
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, es:[di+9]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+ddy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2311
//@ 		mov	ax, [bp+ddx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	[bp+x0], ax	; int16_t
//@ 		mov	ax, [bp+ddy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	[bp+y0], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2312
//@ 		mov	ax, [bp+wx]	; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+wy]	; uint16_t
//@ 		shl	ax, 9		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		mov	[bp+Wshofs], ax	; uint16_t
//@ ; #line	"CSACT.PAS" 2323
//@ 		mov	cx, 8
//@ 		mov	si, [bp+Wshofs]	; uint16_t
//@ ; #line	"CSACT.PAS" 2325
//@ 
//@ loc_1FDB8:				; CODE XREF: RemapWall+13Fj
//@ 		mov	ax, ShadowSeg2	; uint16_t
//@ 		mov	es, ax
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ ; #line	"CSACT.PAS" 2327
//@ 		mov	ax, [bp+y0]	; int16_t
//@ 		add	ax, 0Ch		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	di, [bp+x0]	; int16_t
//@ 		add	di, 0Ch		; Add
//@ 		shr	di, 6		; Shift	Logical	Right
//@ 		add	di, ax		; Add
//@ 		mov	bl, es:[di]
//@ ; #line	"CSACT.PAS" 2328
//@ 		mov	ax, [bp+y0]	; int16_t
//@ 		add	ax, 34h	; '4'   ; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	di, [bp+x0]	; int16_t
//@ 		add	di, 0Ch		; Add
//@ 		shr	di, 6		; Shift	Logical	Right
//@ 		add	di, ax		; Add
//@ 		add	bl, es:[di]	; Add
//@ ; #line	"CSACT.PAS" 2329
//@ 		mov	ax, [bp+y0]	; int16_t
//@ 		add	ax, 0Ch		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	di, [bp+x0]	; int16_t
//@ 		add	di, 34h	; '4'   ; Add
//@ 		shr	di, 6		; Shift	Logical	Right
//@ 		add	di, ax		; Add
//@ 		add	bl, es:[di]	; Add
//@ ; #line	"CSACT.PAS" 2330
//@ 		mov	ax, [bp+y0]	; int16_t
//@ 		add	ax, 34h	; '4'   ; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	di, [bp+x0]	; int16_t
//@ 		add	di, 34h	; '4'   ; Add
//@ 		shr	di, 6		; Shift	Logical	Right
//@ 		add	di, ax		; Add
//@ 		add	bl, es:[di]	; Add
//@ ; #line	"CSACT.PAS" 2331
//@ 		mov	ax, [bp+y0]	; int16_t
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	di, [bp+x0]	; int16_t
//@ 		add	di, 20h	; ' '   ; Add
//@ 		shr	di, 6		; Shift	Logical	Right
//@ 		add	di, ax		; Add
//@ ; #line	"CSACT.PAS" 2332
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	al, es:[di]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	bx, ax		; Add
//@ ; #line	"CSACT.PAS" 2333
//@ 		shr	bx, 3		; Shift	Logical	Right
//@ ; #line	"CSACT.PAS" 2334
//@ 		mov	ax, WShadowSeg	; uint16_t
//@ 		mov	es, ax
//@ 		mov	es:[si], bl
//@ ; #line	"CSACT.PAS" 2335
//@ 		mov	ax, WShadowSeg2	; uint16_t
//@ 		mov	es, ax
//@ 		mov	es:[si], bl
//@ ; #line	"CSACT.PAS" 2337
//@ 		mov	ax, [bp+ddx]	; int16_t
//@ 		add	[bp+x0], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2338
//@ 		mov	ax, [bp+ddy]	; int16_t
//@ 		add	[bp+y0], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2339
//@ 		inc	si		; Increment by 1
//@ ; #line	"CSACT.PAS" 2340
//@ 		dec	cx		; Decrement by 1
//@ 		jz	short locret_1FE6E ; Jump if Zero (ZF=1)
//@ 		jmp	loc_1FDB8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2342
//@ 
//@ locret_1FE6E:				; CODE XREF: RemapWall+23j
//@ 					; RemapWall+13Dj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ RemapWall	endp
//@ 
//@ ; #line	"CSACT.PAS" 2349
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ContinueProcess	proc near		; CODE XREF: AnimateProcesses+A9p
//@ 					; AnimateProcesses+B5p
//@ 
//@ var_2E		= dword	ptr -2Eh
//@ var_2A		= dword	ptr -2Ah
//@ var_26		= word ptr -26h
//@ var_24		= dword	ptr -24h
//@ var_20		= dword	ptr -20h
//@ var_1C		= word ptr -1Ch
//@ var_1A		= dword	ptr -1Ah
//@ rca		= word ptr -16h		; real_t
//@ var_14		= word ptr -14h
//@ var_12		= word ptr -12h
//@ rsa		= word ptr -10h		; real_t
//@ var_E		= word ptr -0Eh
//@ var_C		= word ptr -0Ch
//@ StillActive	= byte ptr -9		; bool
//@ dmy		= word ptr -8		; int16_t
//@ dmx		= word ptr -6		; int16_t
//@ i		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ pn		= word ptr  4		; int16_t
//@ 
//@ 		enter	2Eh, 0		; Make Stack Frame for Procedure Parameters
//@ 		imul	ax, [bp+pn], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSACT.PAS" 2352
//@ 		mov	al, es:[di+1]
//@ 		cmp	al, es:[di+3]	; Compare Two Operands
//@ 		jnz	short loc_1FE9E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2353
//@ 		push	[bp+pn]		; int16_t
//@ 		call	LifeConflict	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1FE9E	; Jump if Zero (ZF=1)
//@ 		jmp	locret_20DCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2355
//@ 
//@ loc_1FE9E:				; CODE XREF: ContinueProcess+1Dj
//@ 					; ContinueProcess+27j
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jg	short loc_1FEAB	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1FF8E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2357
//@ 
//@ loc_1FEAB:				; CODE XREF: ContinueProcess+34j
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	es:[di+24h], ax	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 2358
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jle	short loc_1FEBC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1FF8B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2360
//@ 
//@ loc_1FEBC:				; CODE XREF: ContinueProcess+45j
//@ 		cmp	word ptr es:[di+16h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1FED6	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+1Ah]
//@ 		push	word ptr es:[di+1Ch]
//@ 		push	word ptr es:[di+16h]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2361
//@ 
//@ loc_1FED6:				; CODE XREF: ContinueProcess+4Fj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+16h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1FEF3	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+1Ah]
//@ 		push	word ptr es:[di+1Ch]
//@ 		push	word ptr es:[di+16h]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2362
//@ 
//@ loc_1FEF3:				; CODE XREF: ContinueProcess+6Cj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+24h], ax
//@ ; #line	"CSACT.PAS" 2363
//@ 		cmp	byte ptr es:[di+1], 2 ;	Compare	Two Operands
//@ 		jnz	short loc_1FF6C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2365
//@ 		cmp	word ptr es:[di+22h], 0	; Compare Two Operands
//@ 		jle	short loc_1FF6A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2366
//@ 		mov	ax, es:[di+22h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_1C], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jg	short loc_1FF6A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1FF21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FF1E:				; CODE XREF: ContinueProcess+F6j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_1FF21:				; CODE XREF: ContinueProcess+AAj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 28h	; '('   ; Add
//@ ; #line	"CSACT.PAS" 2367
//@ 		imul	ax, es:[di+2], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		push	word ptr [di+74BEh]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jnz	short loc_1FF1E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2368
//@ 
//@ loc_1FF6A:				; CODE XREF: ContinueProcess+96j
//@ 					; ContinueProcess+A5j
//@ 		jmp	short loc_1FF89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FF6C:				; CODE XREF: ContinueProcess+8Fj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+18h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1FF89	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+1Ah]
//@ 		push	word ptr es:[di+1Ch]
//@ 		push	word ptr es:[di+18h]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2369
//@ 
//@ loc_1FF89:				; CODE XREF: ContinueProcess:loc_1FF6Aj
//@ 					; ContinueProcess+102j
//@ 		jmp	short loc_1FF8E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2370
//@ 
//@ loc_1FF8B:				; CODE XREF: ContinueProcess+47j
//@ 		jmp	locret_20DCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2379
//@ 
//@ loc_1FF8E:				; CODE XREF: ContinueProcess+36j
//@ 					; ContinueProcess:loc_1FF89j
//@ 		mov	[bp+StillActive], 0 ; bool
//@ ; #line	"CSACT.PAS" 2380
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+20h], 0	; Compare Two Operands
//@ 		jg	short loc_1FF9F	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_20BD9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2381
//@ 
//@ loc_1FF9F:				; CODE XREF: ContinueProcess+128j
//@ 		mov	ax, es:[di+20h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_1C], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jle	short loc_1FFB1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_20BD9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FFB1:				; CODE XREF: ContinueProcess+13Aj
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1FFB9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1FFB6:				; CODE XREF: ContinueProcess+D64j
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_1FFB9:				; CODE XREF: ContinueProcess+142j
//@ 		imul	ax, [bp+n], 1Bh	; int16_t
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 38h	; '8'   ; Add
//@ 		mov	word ptr [bp+var_20], di
//@ 		mov	word ptr [bp+var_20+2],	es
//@ ; #line	"CSACT.PAS" 2383
//@ 		mov	ax, es:[di+11h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+dmx], ax	; int16_t
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		mov	[bp+dmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2384
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_24], di
//@ 		mov	word ptr [bp+var_24+2],	es
//@ ; #line	"CSACT.PAS" 2385
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_2001C	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2386
//@ 
//@ loc_2001C:				; CODE XREF: ContinueProcess+1A5j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 63h ;	'c' ; Compare Two Operands
//@ 		jnz	short loc_2004E	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_2003E	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+5]
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], al
//@ 		jmp	short loc_2004B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2003E:				; CODE XREF: ContinueProcess+1BBj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+7]
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], al
//@ 
//@ loc_2004B:				; CODE XREF: ContinueProcess+1CAj
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2387
//@ 
//@ loc_2004E:				; CODE XREF: ContinueProcess+1B1j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 50h ;	'P' ; Compare Two Operands
//@ 		jnz	short loc_20064	; Jump if Not Zero (ZF=0)
//@ 		imul	di, es:[di+1], 24h ; Signed Multiply
//@ 		mov	byte ptr [di+74C4h], 1
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2388
//@ 
//@ loc_20064:				; CODE XREF: ContinueProcess+1E3j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 53h ;	'S' ; Compare Two Operands
//@ 		jnz	short loc_2007A	; Jump if Not Zero (ZF=0)
//@ 		imul	di, es:[di+1], 24h ; Signed Multiply
//@ 		mov	byte ptr [di+74C4h], 0
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2389
//@ 
//@ loc_2007A:				; CODE XREF: ContinueProcess+1F9j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 6Eh ;	'n' ; Compare Two Operands
//@ 		jnz	short loc_2008A	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+StillActive], 1 ; bool
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2390
//@ 
//@ loc_2008A:				; CODE XREF: ContinueProcess+20Fj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 45h ;	'E' ; Compare Two Operands
//@ 		jnz	short loc_200B1	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2392
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_200A7	; Jump if Not Zero (ZF=0)
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		call	Blow3dObjAt	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2393
//@ 
//@ loc_200A7:				; CODE XREF: ContinueProcess+226j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"CSACT.PAS" 2394
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2395
//@ 
//@ loc_200B1:				; CODE XREF: ContinueProcess+21Fj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 71h ;	'q' ; Compare Two Operands
//@ 		jnz	short loc_20120	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2397
//@ 		cmp	MortalTick, 0	; bool
//@ 		jz	short loc_2011D	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2398
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2A+2],	di
//@ 		mov	[bp+var_26], es
//@ ; #line	"CSACT.PAS" 2399
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_2011D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	ax, es:[di+13h]	; Compare Two Operands
//@ 		jl	short loc_2011D	; Jump if Less (SF!=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+17h]	; Compare Two Operands
//@ 		jge	short loc_2011D	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+15h]	; Compare Two Operands
//@ 		jl	short loc_2011D	; Jump if Less (SF!=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+19h]	; Compare Two Operands
//@ 		jge	short loc_2011D	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2400
//@ 		mov	ax, es:[di+5]
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"CSACT.PAS" 2401
//@ 
//@ loc_2011D:				; CODE XREF: ContinueProcess+24Dj
//@ 					; ContinueProcess+265j	...
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2402
//@ 
//@ loc_20120:				; CODE XREF: ContinueProcess+246j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 64h ;	'd' ; Compare Two Operands
//@ 		jnz	short loc_20152	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2404
//@ 		cmp	MortalTick, 0	; bool
//@ 		jz	short loc_2014F	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2405
//@ 		push	word ptr es:[di+13h]
//@ 		push	word ptr es:[di+15h]
//@ 		push	word ptr es:[di+17h]
//@ 		push	word ptr es:[di+19h]
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		call	ProcessDeathZone ; function near PASCAL	returns	void
//@ ; #line	"CSACT.PAS" 2406
//@ 
//@ loc_2014F:				; CODE XREF: ContinueProcess+2BCj
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2407
//@ 
//@ loc_20152:				; CODE XREF: ContinueProcess+2B5j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 73h ;	's' ; Compare Two Operands
//@ 		jz	short loc_2015E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_201F9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2408
//@ 
//@ loc_2015E:				; CODE XREF: ContinueProcess+2E7j
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_201C8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2410
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+15h], 0	; Compare Two Operands
//@ 		jle	short loc_201C6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2412
//@ 		mov	ax, t1		; uint16_t
//@ 		sub	es:[di+15h], ax	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 2413
//@ 		cmp	word ptr es:[di+15h], 0	; Compare Two Operands
//@ 		jg	short loc_20197	; Jump if Greater (ZF=0	& SF=OF)
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+7]
//@ 		call	AddLightSource	; function far PASCAL returns void
//@ 		jmp	short loc_201C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2415
//@ 
//@ loc_20197:				; CODE XREF: ContinueProcess+30Cj
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		cmp	ax, 7		; Compare Two Operands
//@ 		jbe	short loc_201C2	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSACT.PAS" 2416
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	word ptr es:[di+7]
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2417
//@ 
//@ loc_201C2:				; CODE XREF: ContinueProcess+323j
//@ 					; ContinueProcess+32Fj
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2419
//@ 
//@ loc_201C6:				; CODE XREF: ContinueProcess+2FEj
//@ 		jmp	short loc_201F6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2420
//@ 
//@ loc_201C8:				; CODE XREF: ContinueProcess+2F4j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+15h], 0	; Compare Two Operands
//@ 		jg	short loc_201F6	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSACT.PAS" 2422
//@ 		mov	ax, es:[di+1]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		push	ax
//@ 		mov	ax, es:[di+3]
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	word ptr es:[di+5]
//@ 		push	0
//@ 		call	BackRender	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2423
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+15h], 1
//@ ; #line	"CSACT.PAS" 2424
//@ 
//@ loc_201F6:				; CODE XREF: ContinueProcess:loc_201C6j
//@ 					; ContinueProcess+35Ej
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2427
//@ 
//@ loc_201F9:				; CODE XREF: ContinueProcess+2E9j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 72h ;	'r' ; Compare Two Operands
//@ 		jz	short loc_20205	; Jump if Zero (ZF=1)
//@ 		jmp	loc_204A1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2429
//@ 
//@ loc_20205:				; CODE XREF: ContinueProcess+38Ej
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_20262	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2431
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Fh]
//@ 		cmp	ax, es:[di+9]	; Compare Two Operands
//@ 		mov	al, 0
//@ 		jz	short loc_2021F	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_2021F:				; CODE XREF: ContinueProcess+3AAj
//@ 		mov	[bp+StillActive], al ; bool
//@ ; #line	"CSACT.PAS" 2432
//@ 		cmp	word ptr es:[di+9], 0 ;	Compare	Two Operands
//@ 		jle	short loc_20244	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2433
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		add	es:[di+0Fh], ax	; Add
//@ 		mov	ax, es:[di+0Fh]
//@ 		cmp	ax, es:[di+9]	; Compare Two Operands
//@ 		jle	short loc_20242	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+9]
//@ 		mov	es:[di+0Fh], ax
//@ 
//@ loc_20242:				; CODE XREF: ContinueProcess+3C6j
//@ 		jmp	short loc_20260	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2434
//@ 
//@ loc_20244:				; CODE XREF: ContinueProcess+3B5j
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+0Fh], ax	; Integer Subtraction
//@ 		mov	ax, es:[di+0Fh]
//@ 		cmp	ax, es:[di+9]	; Compare Two Operands
//@ 		jge	short loc_20260	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+9]
//@ 		mov	es:[di+0Fh], ax
//@ ; #line	"CSACT.PAS" 2435
//@ 
//@ loc_20260:				; CODE XREF: ContinueProcess:loc_20242j
//@ 					; ContinueProcess+3E4j
//@ 		jmp	short loc_202A6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2437
//@ 
//@ loc_20262:				; CODE XREF: ContinueProcess+39Bj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Fh], 0	; Compare Two Operands
//@ 		mov	al, 0
//@ 		jz	short loc_2026F	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_2026F:				; CODE XREF: ContinueProcess+3FAj
//@ 		mov	[bp+StillActive], al ; bool
//@ ; #line	"CSACT.PAS" 2438
//@ 		cmp	word ptr es:[di+9], 0 ;	Compare	Two Operands
//@ 		jle	short loc_2028F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2439
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		sub	es:[di+0Fh], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+0Fh], 0	; Compare Two Operands
//@ 		jge	short loc_2028D	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Fh], ax
//@ 
//@ loc_2028D:				; CODE XREF: ContinueProcess+413j
//@ 		jmp	short loc_202A6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2440
//@ 
//@ loc_2028F:				; CODE XREF: ContinueProcess+405j
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Fh], ax	; Add
//@ 		cmp	word ptr es:[di+0Fh], 0	; Compare Two Operands
//@ 		jle	short loc_202A6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Fh], ax
//@ ; #line	"CSACT.PAS" 2442
//@ 
//@ loc_202A6:				; CODE XREF: ContinueProcess:loc_20260j
//@ 					; ContinueProcess:loc_2028Dj ...
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Fh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 8Ah	; 'Š'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 3400h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	[bp+rca], ax	; real_t
//@ 		mov	[bp+var_14], bx
//@ 		mov	[bp+var_12], dx
//@ ; #line	"CSACT.PAS" 2443
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Fh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 8Ah	; 'Š'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 3400h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	[bp+rsa], ax	; real_t
//@ 		mov	[bp+var_E], bx
//@ 		mov	[bp+var_C], dx
//@ ; #line	"CSACT.PAS" 2444
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+15h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rsa]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+13h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rca]	; real_t
//@ 		mov	si, [bp+var_14]
//@ 		mov	di, [bp+var_12]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ ; #line	"CSACT.PAS" 2445
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+13h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rsa]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+15h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rca]	; real_t
//@ 		mov	si, [bp+var_14]
//@ 		mov	di, [bp+var_12]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ ; #line	"CSACT.PAS" 2446
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+19h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rsa]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+17h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rca]	; real_t
//@ 		mov	si, [bp+var_14]
//@ 		mov	di, [bp+var_12]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+5]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ ; #line	"CSACT.PAS" 2447
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+17h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rsa]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+19h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+rca]	; real_t
//@ 		mov	si, [bp+var_14]
//@ 		mov	di, [bp+var_12]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brplu$q4Realt1 ; Real(AX:BX:DX)+=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+9], ax
//@ ; #line	"CSACT.PAS" 2448
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+5], 0 ;	Compare	Two Operands
//@ 		jz	short loc_2049E	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		call	RemapWall	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 2449
//@ 
//@ loc_2049E:				; CODE XREF: ContinueProcess+61Cj
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2451
//@ 
//@ loc_204A1:				; CODE XREF: ContinueProcess+390j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 75h ;	'u' ; Compare Two Operands
//@ 		jnz	short loc_2051A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2453
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_204D8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2455
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Bh], ax	; Add
//@ ; #line	"CSACT.PAS" 2456
//@ 		mov	ax, es:[di+0Bh]
//@ 		cmp	ax, es:[di+9]	; Compare Two Operands
//@ 		jl	short loc_204D2	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+9]
//@ 		mov	es:[di+0Bh], ax
//@ 		jmp	short loc_204D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_204D2:				; CODE XREF: ContinueProcess+654j
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2457
//@ 
//@ loc_204D6:				; CODE XREF: ContinueProcess+65Ej
//@ 		jmp	short loc_204F5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2459
//@ 
//@ loc_204D8:				; CODE XREF: ContinueProcess+640j
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+0Bh], ax	; Integer Subtraction
//@ ; #line	"CSACT.PAS" 2460
//@ 		cmp	word ptr es:[di+0Bh], 0	; Compare Two Operands
//@ 		jg	short loc_204F1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Bh], ax
//@ 		jmp	short loc_204F5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_204F1:				; CODE XREF: ContinueProcess+675j
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2462
//@ 
//@ loc_204F5:				; CODE XREF: ContinueProcess:loc_204D6j
//@ 					; ContinueProcess+67Dj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Bh]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	cl, al
//@ 		mov	dx, es:[di+3]
//@ 		mov	ax, es:[di+1]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ ; #line	"CSACT.PAS" 2463
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2465
//@ 
//@ loc_2051A:				; CODE XREF: ContinueProcess+636j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 6Ch ;	'l' ; Compare Two Operands
//@ 		jz	short loc_20526	; Jump if Zero (ZF=1)
//@ 		jmp	loc_206FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2467
//@ 
//@ loc_20526:				; CODE XREF: ContinueProcess+6AFj
//@ 		cmp	word ptr es:[di+7], 0 ;	Compare	Two Operands
//@ 		jle	short loc_20538	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	NewSecond, 0	; bool
//@ 		jz	short loc_20538	; Jump if Zero (ZF=1)
//@ 		dec	word ptr es:[di+7] ; Decrement by 1
//@ ; #line	"CSACT.PAS" 2468
//@ 
//@ loc_20538:				; CODE XREF: ContinueProcess+6B9j
//@ 					; ContinueProcess+6C0j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+7], 0 ;	Compare	Two Operands
//@ 		jg	short loc_20545	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_206F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2469
//@ 
//@ loc_20545:				; CODE XREF: ContinueProcess+6CEj
//@ 		imul	ax, es:[di+3], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di+1], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_2A+2],	di
//@ 		mov	[bp+var_26], es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+9]	; Compare Two Operands
//@ 		jz	short loc_20571	; Jump if Zero (ZF=1)
//@ 		jmp	loc_206F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2471
//@ 
//@ loc_20571:				; CODE XREF: ContinueProcess+6FAj
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		add	es:[di+7], ax	; Add
//@ ; #line	"CSACT.PAS" 2473
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+13h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, 4000h	; Integer Subtraction
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 90h	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7FFFh
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+dmx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2474
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+13h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, 4000h	; Integer Subtraction
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 90h	; ''
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7FFFh
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	cx, 82h	; '‚'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+dmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2476
//@ 		mov	al, SecCounter	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 8Ch	; 'Œ'
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+i],	ax	; int16_t
//@ ; #line	"CSACT.PAS" 2477
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+7], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_206AE	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+15h]
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		cmp	ax, [bp+i]	; int16_t
//@ 		jle	short loc_206AE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2479
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+dmx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+dmy]	; int16_t
//@ 		push	ax
//@ 		push	4
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	0FEh ; 'þ'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2480
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+13h], 12Ch ; Compare Two Operands
//@ 		jge	short loc_206AC	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		push	ax
//@ 		push	0FEh ; 'þ'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2481
//@ 
//@ loc_206AC:				; CODE XREF: ContinueProcess+818j
//@ 		jmp	short loc_206F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2483
//@ 
//@ loc_206AE:				; CODE XREF: ContinueProcess+7DDj
//@ 					; ContinueProcess+7E9j
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+dmx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+dmy]	; int16_t
//@ 		push	ax
//@ 		push	4
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+15h]
//@ 		push	0FEh ; 'þ'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2484
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+13h], 12Ch ; Compare Two Operands
//@ 		jge	short loc_206F4	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	3
//@ 		push	0Eh
//@ 		push	0FEh ; 'þ'
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2486
//@ 
//@ loc_206F4:				; CODE XREF: ContinueProcess:loc_206ACj
//@ 					; ContinueProcess+869j
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2489
//@ 
//@ loc_206F8:				; CODE XREF: ContinueProcess+6D0j
//@ 					; ContinueProcess+6FCj
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2490
//@ 
//@ loc_206FB:				; CODE XREF: ContinueProcess+6B1j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 77h ;	'w' ; Compare Two Operands
//@ 		jz	short loc_20707	; Jump if Zero (ZF=1)
//@ 		jmp	loc_207E3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2494
//@ 
//@ loc_20707:				; CODE XREF: ContinueProcess+890j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_20711	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2070E:				; CODE XREF: ContinueProcess+8F9j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSACT.PAS" 2495
//@ 
//@ loc_20711:				; CODE XREF: ContinueProcess+89Aj
//@ 		imul	di, [bp+i], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2A+2],	di
//@ 		mov	[bp+var_26], es
//@ ; #line	"CSACT.PAS" 2496
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_20767	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		sub	ax, es:[di+1]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+5]	; Compare Two Operands
//@ 		jge	short loc_20767	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2497
//@ 		mov	[bp+StillActive], 1 ; bool
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+1], 1
//@ 
//@ loc_20767:				; CODE XREF: ContinueProcess+8B4j
//@ 					; ContinueProcess+8E7j
//@ 		cmp	[bp+i],	7	; int16_t
//@ 		jnz	short loc_2070E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2499
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_26], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_26]	; Compare Two Operands
//@ 		jg	short loc_207E0	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_20783	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20780:				; CODE XREF: ContinueProcess+96Cj
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSACT.PAS" 2500
//@ 
//@ loc_20783:				; CODE XREF: ContinueProcess+90Cj
//@ 		imul	di, [bp+i], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2A], di
//@ 		mov	word ptr [bp+var_2A+2],	es
//@ ; #line	"CSACT.PAS" 2501
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_207D8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		sub	ax, es:[di+1]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+5]	; Compare Two Operands
//@ 		jge	short loc_207D8	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2502
//@ 		mov	[bp+StillActive], 1 ; bool
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+1], 1
//@ 
//@ loc_207D8:				; CODE XREF: ContinueProcess+926j
//@ 					; ContinueProcess+958j
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_26]	; Compare Two Operands
//@ 		jnz	short loc_20780	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2504
//@ 
//@ loc_207E0:				; CODE XREF: ContinueProcess+907j
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2505
//@ 
//@ loc_207E3:				; CODE XREF: ContinueProcess+892j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 57h ;	'W' ; Compare Two Operands
//@ 		jz	short loc_207EF	; Jump if Zero (ZF=1)
//@ 		jmp	loc_209F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2507
//@ 
//@ loc_207EF:				; CODE XREF: ContinueProcess+978j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+5]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Bh], ax
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+7]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Dh], ax
//@ ; #line	"CSACT.PAS" 2508
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_2082D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2082A:				; CODE XREF: ContinueProcess+A45j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSACT.PAS" 2509
//@ 
//@ loc_2082D:				; CODE XREF: ContinueProcess+9B6j
//@ 		imul	di, [bp+i], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2A+2],	di
//@ 		mov	[bp+var_26], es
//@ ; #line	"CSACT.PAS" 2510
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_208B1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	ax, es:[di+13h]	; Compare Two Operands
//@ 		jl	short loc_208B1	; Jump if Less (SF!=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+17h]	; Compare Two Operands
//@ 		jge	short loc_208B1	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+15h]	; Compare Two Operands
//@ 		jl	short loc_208B1	; Jump if Less (SF!=OF)
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+19h]	; Compare Two Operands
//@ 		jge	short loc_208B1	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSACT.PAS" 2511
//@ 		lea	di, [bp+i]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		add	di, 0Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_2A+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Eh]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Bh]
//@ 		push	word ptr es:[di+0Dh]
//@ 		push	1
//@ 		call	MoveOn		; function far PASCAL returns void
//@ 
//@ loc_208B1:				; CODE XREF: ContinueProcess+9D0j
//@ 					; ContinueProcess+9DDj	...
//@ 		cmp	[bp+i],	7	; int16_t
//@ 		jz	short loc_208BA	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2082A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2513
//@ 
//@ loc_208BA:				; CODE XREF: ContinueProcess+A43j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_26], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_26]	; Compare Two Operands
//@ 		jle	short loc_208CB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_209F5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_208CB:				; CODE XREF: ContinueProcess+A54j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_208D4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_208D0:				; CODE XREF: ContinueProcess+B80j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSACT.PAS" 2514
//@ 
//@ loc_208D4:				; CODE XREF: ContinueProcess+A5Cj
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2A], di
//@ 		mov	word ptr [bp+var_2A+2],	es
//@ ; #line	"CSACT.PAS" 2515
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	ax, es:[di+13h]	; Compare Two Operands
//@ 		jge	short loc_208F4	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_209EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_208F4:				; CODE XREF: ContinueProcess+A7Dj
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+17h]	; Compare Two Operands
//@ 		jl	short loc_20906	; Jump if Less (SF!=OF)
//@ 		jmp	loc_209EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20906:				; CODE XREF: ContinueProcess+A8Fj
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+15h]	; Compare Two Operands
//@ 		jge	short loc_20919	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_209EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20919:				; CODE XREF: ContinueProcess+AA2j
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+19h]	; Compare Two Operands
//@ 		jl	short loc_2092C	; Jump if Less (SF!=OF)
//@ 		jmp	loc_209EA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2516
//@ 
//@ loc_2092C:				; CODE XREF: ContinueProcess+AB5j
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2E], di
//@ 		mov	word ptr [bp+var_2E+2],	es
//@ ; #line	"CSACT.PAS" 2518
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+0Bh], 0	; Compare Two Operands
//@ 		jz	short loc_20997	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2519
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+0Bh]	; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+20h]
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	0
//@ 		push	1
//@ 		push	1
//@ 		call	NotFreeForMonster ; function far PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_20997	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Bh]
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		add	es:[di], ax	; Add
//@ ; #line	"CSACT.PAS" 2520
//@ 
//@ loc_20997:				; CODE XREF: ContinueProcess+ADBj
//@ 					; ContinueProcess+B16j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Dh], 0	; Compare Two Operands
//@ 		jz	short loc_209EA	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2521
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		mov	ax, es:[di+2]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+0Dh]	; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+20h]
//@ 		les	di, [bp+var_2E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+8]
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	0
//@ 		push	1
//@ 		push	1
//@ 		call	NotFreeForMonster ; function far PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_209EA	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Dh]
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+2], ax	; Add
//@ ; #line	"CSACT.PAS" 2522
//@ 
//@ loc_209EA:				; CODE XREF: ContinueProcess+A7Fj
//@ 					; ContinueProcess+A91j	...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_26]	; Compare Two Operands
//@ 		jz	short loc_209F5	; Jump if Zero (ZF=1)
//@ 		jmp	loc_208D0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2523
//@ 
//@ loc_209F5:				; CODE XREF: ContinueProcess+A56j
//@ 					; ContinueProcess+B7Ej
//@ 		jmp	loc_20BCE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2526
//@ 
//@ loc_209F8:				; CODE XREF: ContinueProcess+97Aj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jz	short loc_20A05	; Jump if Zero (ZF=1)
//@ 		jmp	loc_20A98	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2528
//@ 
//@ loc_20A05:				; CODE XREF: ContinueProcess+B8Ej
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Bh]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+dmx]	; int16_t
//@ 		jge	short loc_20A27	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, es:[di+0Bh]	; Integer Subtraction
//@ 		mov	[bp+dmx], ax	; int16_t
//@ 		jmp	short loc_20A39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20A27:				; CODE XREF: ContinueProcess+BA6j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+5], 0 ;	Compare	Two Operands
//@ 		jge	short loc_20A39	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dmx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2529
//@ 
//@ loc_20A39:				; CODE XREF: ContinueProcess+BB3j
//@ 					; ContinueProcess+BBDj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Dh]
//@ 		sub	ax, es:[di+7]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+dmy]	; int16_t
//@ 		jge	short loc_20A5B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, es:[di+0Dh]	; Integer Subtraction
//@ 		mov	[bp+dmy], ax	; int16_t
//@ 		jmp	short loc_20A6D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20A5B:				; CODE XREF: ContinueProcess+BDAj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+7], 0 ;	Compare	Two Operands
//@ 		jge	short loc_20A6D	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+dmy]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2530
//@ 
//@ loc_20A6D:				; CODE XREF: ContinueProcess+BE7j
//@ 					; ContinueProcess+BF1j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 78h ;	'x' ; Compare Two Operands
//@ 		jnz	short loc_20A81	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+dmx], 0	; int16_t
//@ 		jz	short loc_20A81	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+dmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2531
//@ 
//@ loc_20A81:				; CODE XREF: ContinueProcess+C02j
//@ 					; ContinueProcess+C08j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 79h ;	'y' ; Compare Two Operands
//@ 		jnz	short loc_20A95	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+dmy], 0	; int16_t
//@ 		jz	short loc_20A95	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+dmx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2532
//@ 
//@ loc_20A95:				; CODE XREF: ContinueProcess+C16j
//@ 					; ContinueProcess+C1Cj
//@ 		jmp	loc_20B1C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2534
//@ 
//@ loc_20A98:				; CODE XREF: ContinueProcess+B90j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Bh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+dmx]	; int16_t
//@ 		jge	short loc_20AB4	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+0Bh]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dmx], ax	; int16_t
//@ 		jmp	short loc_20AC6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20AB4:				; CODE XREF: ContinueProcess+C35j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Bh], 0	; Compare Two Operands
//@ 		jle	short loc_20AC6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dmx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2535
//@ 
//@ loc_20AC6:				; CODE XREF: ContinueProcess+C40j
//@ 					; ContinueProcess+C4Aj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Dh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, [bp+dmy]	; int16_t
//@ 		jge	short loc_20AE2	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+0Dh]
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dmy], ax	; int16_t
//@ 		jmp	short loc_20AF4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20AE2:				; CODE XREF: ContinueProcess+C63j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Dh], 0	; Compare Two Operands
//@ 		jle	short loc_20AF4	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dmy]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2536
//@ 
//@ loc_20AF4:				; CODE XREF: ContinueProcess+C6Ej
//@ 					; ContinueProcess+C78j
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 79h ;	'y' ; Compare Two Operands
//@ 		jnz	short loc_20B08	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+dmx], 0	; int16_t
//@ 		jz	short loc_20B08	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+dmy], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2537
//@ 
//@ loc_20B08:				; CODE XREF: ContinueProcess+C89j
//@ 					; ContinueProcess+C8Fj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di], 78h ;	'x' ; Compare Two Operands
//@ 		jnz	short loc_20B1C	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+dmy], 0	; int16_t
//@ 		jz	short loc_20B1C	; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+dmx], ax	; int16_t
//@ ; #line	"CSACT.PAS" 2540
//@ 
//@ loc_20B1C:				; CODE XREF: ContinueProcess:loc_20A95j
//@ 					; ContinueProcess+C9Dj	...
//@ 		mov	ax, [bp+dmx]	; int16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Bh], ax	; Add
//@ 		mov	ax, [bp+dmy]	; int16_t
//@ 		add	es:[di+0Dh], ax	; Add
//@ ; #line	"CSACT.PAS" 2541
//@ 		mov	ax, es:[di+13h]
//@ 		add	ax, es:[di+0Bh]	; Add
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+17h]
//@ 		add	ax, es:[di+0Bh]	; Add
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+7], ax
//@ ; #line	"CSACT.PAS" 2542
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+15h]
//@ 		add	ax, es:[di+0Dh]	; Add
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+5], ax
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+19h]
//@ 		add	ax, es:[di+0Dh]	; Add
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+9], ax
//@ ; #line	"CSACT.PAS" 2544
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_20B97	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Bh]
//@ 		cmp	ax, es:[di+5]	; Compare Two Operands
//@ 		jnz	short loc_20B93	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+0Dh]
//@ 		cmp	ax, es:[di+7]	; Compare Two Operands
//@ 		jz	short loc_20B97	; Jump if Zero (ZF=1)
//@ 
//@ loc_20B93:				; CODE XREF: ContinueProcess+D15j
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2545
//@ 
//@ loc_20B97:				; CODE XREF: ContinueProcess+D08j
//@ 					; ContinueProcess+D1Fj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 2 ;	Compare	Two Operands
//@ 		jnz	short loc_20BB6	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Bh], 0	; Compare Two Operands
//@ 		jnz	short loc_20BB2	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+0Dh], 0	; Compare Two Operands
//@ 		jz	short loc_20BB6	; Jump if Zero (ZF=1)
//@ 
//@ loc_20BB2:				; CODE XREF: ContinueProcess+D37j
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2546
//@ 
//@ loc_20BB6:				; CODE XREF: ContinueProcess+D2Dj
//@ 					; ContinueProcess+D3Ej
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+5], 0 ;	Compare	Two Operands
//@ 		jz	short loc_20BCE	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		call	RemapWall	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 2548
//@ 
//@ loc_20BCE:				; CODE XREF: ContinueProcess+1A7j
//@ 					; ContinueProcess:loc_2004Bj ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jz	short loc_20BD9	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1FFB6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2553
//@ 
//@ loc_20BD9:				; CODE XREF: ContinueProcess+12Aj
//@ 					; ContinueProcess+13Cj	...
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+22h], 0	; Compare Two Operands
//@ 		jg	short loc_20BE6	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_20D76	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2554
//@ 
//@ loc_20BE6:				; CODE XREF: ContinueProcess+D6Fj
//@ 		mov	ax, es:[di+22h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_1C], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jle	short loc_20BF8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_20D76	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20BF8:				; CODE XREF: ContinueProcess+D81j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_20C00	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20BFD:				; CODE XREF: ContinueProcess+F01j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 2555
//@ 
//@ loc_20C00:				; CODE XREF: ContinueProcess+D89j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 28h	; '('   ; Add
//@ 		mov	word ptr [bp+var_20], di
//@ 		mov	word ptr [bp+var_20+2],	es
//@ ; #line	"CSACT.PAS" 2557
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jz	short loc_20C22	; Jump if Zero (ZF=1)
//@ 		jmp	loc_20D03	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2559
//@ 
//@ loc_20C22:				; CODE XREF: ContinueProcess+DABj
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_20C72	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2560
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+2], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		push	word ptr [di+74BEh]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2561
//@ 
//@ loc_20C72:				; CODE XREF: ContinueProcess+DC9j
//@ 		mov	cl, byte ptr t1	; uint16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		add	es:[di], cl	; Add
//@ ; #line	"CSACT.PAS" 2562
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+2], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di], 2C0h ; Signed Multiply
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
//@ 		mov	word ptr [bp+var_24], di
//@ 		mov	word ptr [bp+var_24+2],	es
//@ ; #line	"CSACT.PAS" 2563
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+1Ah]	; Compare Two Operands
//@ 		jb	short loc_20CFD	; Jump if Below	(CF=1)
//@ 		mov	cl, es:[di+1Ah]
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ 		jmp	short loc_20D01	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2564
//@ 
//@ loc_20CFD:				; CODE XREF: ContinueProcess+E6Bj
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2565
//@ 
//@ loc_20D01:				; CODE XREF: ContinueProcess+E89j
//@ 		jmp	short loc_20D6B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20D03:				; CODE XREF: ContinueProcess+DADj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+26h]
//@ 		cmp	ax, es:[di+0Eh]	; Compare Two Operands
//@ 		jl	short loc_20D6B	; Jump if Less (SF!=OF)
//@ ; #line	"CSACT.PAS" 2567
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, t1		; uint16_t
//@ 		ja	short loc_20D4B	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 2568
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	byte ptr es:[di], 0
//@ 		jmp	short loc_20D6B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2569
//@ 
//@ loc_20D4B:				; CODE XREF: ContinueProcess+EBCj
//@ 		mov	cl, byte ptr t1	; uint16_t
//@ 		les	di, [bp+var_20]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		sub	es:[di], cl	; Integer Subtraction
//@ 		mov	[bp+StillActive], 1 ; bool
//@ ; #line	"CSACT.PAS" 2571
//@ 
//@ loc_20D6B:				; CODE XREF: ContinueProcess:loc_20D01j
//@ 					; ContinueProcess+E9Cj	...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_1C]	; Compare Two Operands
//@ 		jz	short loc_20D76	; Jump if Zero (ZF=1)
//@ 		jmp	loc_20BFD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2575
//@ 
//@ loc_20D76:				; CODE XREF: ContinueProcess+D71j
//@ 					; ContinueProcess+D83j	...
//@ 		cmp	[bp+StillActive], 0 ; bool
//@ 		jnz	short locret_20DCE ; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2576
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jnz	short loc_20DA6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSACT.PAS" 2578
//@ 		cmp	word ptr es:[di+0Ah], 0	; Compare Two Operands
//@ 		jnz	short loc_20D94	; Jump if Not Zero (ZF=0)
//@ 		mov	byte ptr es:[di+1], 3
//@ 		jmp	short loc_20DA4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2579
//@ 
//@ loc_20D94:				; CODE XREF: ContinueProcess+F19j
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+1], 2
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	es:[di+24h], ax
//@ ; #line	"CSACT.PAS" 2580
//@ 
//@ loc_20DA4:				; CODE XREF: ContinueProcess+F20j
//@ 		jmp	short locret_20DCE ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2582
//@ 
//@ loc_20DA6:				; CODE XREF: ContinueProcess+F12j
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+26h]
//@ 		cmp	ax, es:[di+0Eh]	; Compare Two Operands
//@ 		jge	short loc_20DC6	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	es:[di+24h], ax
//@ 		inc	word ptr es:[di+26h] ; Increment by 1
//@ 		mov	byte ptr es:[di+1], 1
//@ 		jmp	short locret_20DCE ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2583
//@ 
//@ loc_20DC6:				; CODE XREF: ContinueProcess+F3Fj
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+1], 0
//@ ; #line	"CSACT.PAS" 2586
//@ 
//@ locret_20DCE:				; CODE XREF: ContinueProcess+29j
//@ 					; ContinueProcess:loc_1FF8Bj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ ContinueProcess	endp
//@ 
//@ ; #line	"CSACT.PAS" 2595
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateProcesses proc far		; CODE XREF: DoneProcesses+CP
//@ 					; DoneProcesses+11P ...
//@ 
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2596
//@ 		mov	di, offset ProcState ; uint16_t[4]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSACT.PAS" 2597
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_20DEE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20DEB:				; CODE XREF: AnimateProcesses+BEj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 2598
//@ 
//@ loc_20DEE:				; CODE XREF: AnimateProcesses+17j
//@ 		imul	ax, [bp+n], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSACT.PAS" 2599
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_20E08	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_20E8A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2601
//@ 
//@ loc_20E08:				; CODE XREF: AnimateProcesses+31j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_20E16	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_20E5A	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2602
//@ 
//@ loc_20E16:				; CODE XREF: AnimateProcesses+3Bj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 3 ;	Compare	Two Operands
//@ 		jz	short loc_20E35	; Jump if Zero (ZF=1)
//@ 		cmp	byte ptr es:[di+1], 1 ;	Compare	Two Operands
//@ 		jz	short loc_20E35	; Jump if Zero (ZF=1)
//@ 		cmp	byte ptr es:[di+1], 2 ;	Compare	Two Operands
//@ 		jnz	short loc_20E5A	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jle	short loc_20E5A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2605
//@ 
//@ loc_20E35:				; CODE XREF: AnimateProcesses+4Cj
//@ 					; AnimateProcesses+53j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		and	ax, 0Fh		; Logical AND
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 1
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	[di-0D04h], dx	; Add
//@ ; #line	"CSACT.PAS" 2607
//@ 
//@ loc_20E5A:				; CODE XREF: AnimateProcesses+42j
//@ 					; AnimateProcesses+5Aj	...
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+2], 0FFh ; Compare Two Operands
//@ 		jnb	short loc_20E8A	; Jump if Not Below (CF=0)
//@ ; #line	"CSACT.PAS" 2608
//@ 		mov	al, es:[di+1]
//@ ; #line	"CSACT.PAS" 2609
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jnz	short loc_20E6E	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_20E8A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2610
//@ 
//@ loc_20E6E:				; CODE XREF: AnimateProcesses+98j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_20E74	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_20E8A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2611
//@ 
//@ loc_20E74:				; CODE XREF: AnimateProcesses+9Ej
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_20E80	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+n]		; int16_t
//@ 		call	ContinueProcess	; function near	PASCAL returns void
//@ 		jmp	short loc_20E8A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2612
//@ 
//@ loc_20E80:				; CODE XREF: AnimateProcesses+A4j
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_20E8A	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+n]		; int16_t
//@ 		call	ContinueProcess	; function near	PASCAL returns void
//@ ; #line	"CSACT.PAS" 2614
//@ 
//@ loc_20E8A:				; CODE XREF: AnimateProcesses+33j
//@ 					; AnimateProcesses+90j	...
//@ 		cmp	[bp+n],	3Fh ; '?' ; int16_t
//@ 		jz	short locret_20E93 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_20DEB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2615
//@ 
//@ locret_20E93:				; CODE XREF: AnimateProcesses+BCj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AnimateProcesses endp
//@ 
//@ ; #line	"CSACT.PAS" 2619
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StartUpProcesses proc far		; CODE XREF: LoadLevel+3FEP
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= word ptr -0Ah
//@ var_8		= dword	ptr -8
//@ i		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSACT.PAS" 2620
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_20EA3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20EA0:				; CODE XREF: StartUpProcesses+90j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSACT.PAS" 2621
//@ 
//@ loc_20EA3:				; CODE XREF: StartUpProcesses+9j
//@ 		imul	ax, [bp+i], 1E8h ; int16_t
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSACT.PAS" 2622
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_20F1F	; Jump if Zero (ZF=1)
//@ 		cmp	byte ptr es:[di+5], 0 ;	Compare	Two Operands
//@ 		jz	short loc_20F1F	; Jump if Zero (ZF=1)
//@ ; #line	"CSACT.PAS" 2623
//@ 		cmp	word ptr es:[di+20h], 0	; Compare Two Operands
//@ 		jle	short loc_20F1F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSACT.PAS" 2624
//@ 		mov	ax, es:[di+20h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_A], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jg	short loc_20F1F	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_20EDF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_20EDC:				; CODE XREF: StartUpProcesses+88j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSACT.PAS" 2625
//@ 
//@ loc_20EDF:				; CODE XREF: StartUpProcesses+45j
//@ 		imul	ax, [bp+n], 1Bh	; int16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 38h	; '8'   ; Add
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"CSACT.PAS" 2626
//@ 		mov	al, es:[di]
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jz	short loc_20F09	; Jump if Zero (ZF=1)
//@ 		cmp	al, 72h	; 'r'   ; Compare Two Operands
//@ 		jz	short loc_20F09	; Jump if Zero (ZF=1)
//@ 		cmp	al, 75h	; 'u'   ; Compare Two Operands
//@ 		jz	short loc_20F09	; Jump if Zero (ZF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jb	short loc_20F17	; Jump if Below	(CF=1)
//@ 		cmp	al, 79h	; 'y'   ; Compare Two Operands
//@ 		ja	short loc_20F17	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSACT.PAS" 2627
//@ 
//@ loc_20F09:				; CODE XREF: StartUpProcesses+62j
//@ 					; StartUpProcesses+66j	...
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1]
//@ 		push	word ptr es:[di+3]
//@ 		call	RemapWall	; function near	PASCAL returns void
//@ 
//@ loc_20F17:				; CODE XREF: StartUpProcesses+6Ej
//@ 					; StartUpProcesses+72j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jnz	short loc_20EDC	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_20F1F:				; CODE XREF: StartUpProcesses+23j
//@ 					; StartUpProcesses+2Aj	...
//@ 		cmp	[bp+i],	3Fh ; '?' ; int16_t
//@ 		jz	short locret_20F28 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_20EA0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSACT.PAS" 2628
//@ 
//@ locret_20F28:				; CODE XREF: StartUpProcesses+8Ej
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ StartUpProcesses endp
//@ 
//@ ; #line	"CSACT.PAS" 2631
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; Attributes: bp-based frame
//@ 
//@ $CsActInit	proc far		; CODE XREF: PROGRAM+28P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSACT.PAS" 2632
//@ 		mov	di, offset PProc ; TProcess*
//@ 		push	ds
//@ 		push	di
//@ 		push	7A00h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2633
//@ 		mov	di, offset PLinks ; TLinksList$Element*
//@ 		push	ds
//@ 		push	di
//@ 		push	380h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2634
//@ 		mov	di, offset PChanges ; TChangesList$Element*
//@ 		push	ds
//@ 		push	di
//@ 		push	200h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2635
//@ 		mov	di, offset PMList ; TMessage*
//@ 		push	ds
//@ 		push	di
//@ 		push	17C0h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2636
//@ 		mov	di, offset ReObjects ; TReObject*
//@ 		push	ds
//@ 		push	di
//@ 		push	500h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2637
//@ 		mov	di, offset AmmoBags ; TAmmoBag*
//@ 		push	ds
//@ 		push	di
//@ 		push	7C0h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSACT.PAS" 2638
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ $CsActInit	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		align 4
