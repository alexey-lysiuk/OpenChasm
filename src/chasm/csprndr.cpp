
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

#include "csprndr.h"


static int16_t Wx, Wy;
static uint8_t PifTab[32][32];


//! ; #line	"CSPRNDR.PAS" 25
//! 
//! ; =============== S U B	R O U T	I N E =======================================
//! 
//! ; function near	PASCAL returns unsigned	int 'Word'
//! ; Attributes: bp-based frame
//! 
//! QPifagorP16	proc near		; CODE XREF: $CspRndrInit+27p
int8_t QPifagorP16(const int16_t XX, const int16_t YY)
{
//! 
//! YY		= word ptr  4		; int16_t
//! XX		= word ptr  6		; int16_t
//! 
//! 		push	bp
//! 		mov	bp, sp
//! ; #line	"CSPRNDR.PAS" 26
//! 		mov	si, [bp+XX]	; int16_t
//! 		mov	di, [bp+YY]	; int16_t
//! ; #line	"CSPRNDR.PAS" 27
//! 		mov	cx, si
//! 		add	cx, di		; Add
//! 		push	cx
//! ; #line	"CSPRNDR.PAS" 29
//! 		mov	ax, si
//! 		imul	di		; Signed Multiply
//! 		jz	short loc_1055A	; Jump if Zero (ZF=1)
//! ; #line	"CSPRNDR.PAS" 30
//! 		mov	dx, ax
//! 		shl	ax, 3		; Shift	Logical	Left
//! 		sub	ax, dx		; Integer Subtraction
//! ; #line	"CSPRNDR.PAS" 32
//! 		mov	bx, cx
//! 		shl	bx, 2		; Shift	Logical	Left
//! 		add	bx, cx		; Add
//! 		add	bx, cx		; Add
//! ; #line	"CSPRNDR.PAS" 33
//! 		xor	dx, dx		; Logical Exclusive OR
//! 		div	bx		; Unsigned Divide
//! ; #line	"CSPRNDR.PAS" 34
//! 		pop	bx
//! 		sub	bx, ax		; Integer Subtraction
//! 		push	bx
//! ; #line	"CSPRNDR.PAS" 35
//! 
//! loc_1055A:				; CODE XREF: QPifagorP16+12j
//! 		pop	ax
//! ; #line	"CSPRNDR.PAS" 36
//! 		leave			; High Level Procedure Exit
//! 		retn	4		; Return Near from Procedure
//! QPifagorP16	endp

    int16_t result = XX + YY;

    if (0 != XX && 0 != YY)
    {
        // TODO: integer overflow in original code, bug or feature?
        //result -= static_cast<uint16_t>(7 * XX * YY) / (6 * result);

        result -= 7 * XX * YY / (6 * result);
    }

    return static_cast<uint8_t>(result);
}
//! 
//@ ; #line	"CSPRNDR.PAS" 62
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns unsigned	int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ QPifagorA32	proc near		; CODE XREF: BackRender+C4p
//@ 					; BackRender+288p
//@ 
//@ YY		= word ptr  4		; int16_t
//@ XX		= word ptr  6		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPRNDR.PAS" 63
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ ; #line	"CSPRNDR.PAS" 64
//@ 		mov	ax, [bp+XX]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	si, ax
//@ ; #line	"CSPRNDR.PAS" 65
//@ 		mov	ax, [bp+YY]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	di, ax
//@ ; #line	"CSPRNDR.PAS" 66
//@ 		mov	cx, si
//@ 		add	cx, di		; Add
//@ 		push	cx
//@ ; #line	"CSPRNDR.PAS" 68
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, si
//@ ; #line	"CSPRNDR.PAS" 69
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ 		mov	bx, di
//@ ; #line	"CSPRNDR.PAS" 70
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSPRNDR.PAS" 71
//@ 		cmp	eax, 0		; Compare Two Operands
//@ ; #line	"CSPRNDR.PAS" 72
//@ 		jz	short loc_105AF	; Jump if Zero (ZF=1)
//@ ; #line	"CSPRNDR.PAS" 73
//@ 		mov	bx, 7
//@ ; #line	"CSPRNDR.PAS" 74
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSPRNDR.PAS" 77
//@ 		mov	bx, cx
//@ ; #line	"CSPRNDR.PAS" 78
//@ 		shl	ebx, 3		; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 79
//@ 		sub	ebx, ecx	; Integer Subtraction
//@ ; #line	"CSPRNDR.PAS" 80
//@ 		sub	ebx, ecx	; Integer Subtraction
//@ ; #line	"CSPRNDR.PAS" 81
//@ 		xor	edx, edx	; Logical Exclusive OR
//@ ; #line	"CSPRNDR.PAS" 82
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"CSPRNDR.PAS" 83
//@ 		pop	bx
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		push	bx
//@ ; #line	"CSPRNDR.PAS" 84
//@ 
//@ loc_105AF:				; CODE XREF: QPifagorA32+32j
//@ 		pop	ax
//@ ; #line	"CSPRNDR.PAS" 85
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ QPifagorA32	endp
//@ 
//@ ; #line	"CSPRNDR.PAS" 89
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ MulVectors$2	proc near		; CODE XREF: BackRender+225p
//@ 
//@ MulVectors	= word ptr -2		; int16_t
//@ vy		= word ptr  4		; int16_t
//@ vx		= word ptr  6		; int16_t
//@ uy		= word ptr  8		; int16_t
//@ ux		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPRNDR.PAS" 91
//@ 		mov	cx, 0FFFFh
//@ ; #line	"CSPRNDR.PAS" 92
//@ 		mov	ax, [bp+ux]	; int16_t
//@ ; #line	"CSPRNDR.PAS" 93
//@ 		imul	[bp+vy]		; int16_t
//@ ; #line	"CSPRNDR.PAS" 94
//@ 		mov	bx, dx
//@ ; #line	"CSPRNDR.PAS" 95
//@ 		shl	ebx, 10h	; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 96
//@ 		mov	bx, ax
//@ ; #line	"CSPRNDR.PAS" 98
//@ 		mov	ax, [bp+uy]	; int16_t
//@ ; #line	"CSPRNDR.PAS" 99
//@ 		imul	[bp+vx]		; int16_t
//@ ; #line	"CSPRNDR.PAS" 100
//@ 		shl	edx, 10h	; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 101
//@ 		mov	dx, ax
//@ ; #line	"CSPRNDR.PAS" 102
//@ 		sub	ebx, edx	; Integer Subtraction
//@ ; #line	"CSPRNDR.PAS" 103
//@ 		js	short loc_105DD	; Jump if Sign (SF=1)
//@ ; #line	"CSPRNDR.PAS" 104
//@ 		mov	cx, 1
//@ ; #line	"CSPRNDR.PAS" 105
//@ 
//@ loc_105DD:				; CODE XREF: MulVectors$2+24j
//@ 		mov	[bp+MulVectors], cx ; int16_t
//@ ; #line	"CSPRNDR.PAS" 107
//@ 		mov	ax, [bp+MulVectors] ; int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ MulVectors$2	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_2		db 2,'@#'               ; DATA XREF: RestoreLights+14Co
//@ aClear		db 7,'CLEAR: '          ; DATA XREF: RestoreLights+13Co
//@ ; #line	"CSPRNDR.PAS" 113
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RestoreLights	proc near		; CODE XREF: ProcessLights+4p
//@ 
//@ var_20C		= byte ptr -20Ch
//@ var_10C		= byte ptr -10Ch
//@ var_10		= dword	ptr -10h
//@ W		= word ptr -0Ch		; uint16_t
//@ WY2		= word ptr -0Ah		; int16_t
//@ WY1		= word ptr -8		; int16_t
//@ FY2		= word ptr -6		; int16_t
//@ FY1		= word ptr -4		; int16_t
//@ N		= word ptr -2		; int16_t
//@ 
//@ 		enter	20Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPRNDR.PAS" 114
//@ 		cmp	LCount,	0	; uint16_t
//@ 		jnz	short loc_10600	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_107AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 116
//@ 
//@ loc_10600:				; CODE XREF: RestoreLights+9j
//@ 		mov	[bp+N],	1	; int16_t
//@ 		mov	[bp+FY1], 100h	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+FY2], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 117
//@ 
//@ loc_1060F:				; CODE XREF: RestoreLights+DAj
//@ 		mov	ax, LCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+N]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_1062C	; Jump if Less (SF!=OF)
//@ 		jle	short loc_10625	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_106CF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10625:				; CODE XREF: RestoreLights+2Ej
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_1062C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_106CF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 118
//@ 
//@ loc_1062C:				; CODE XREF: RestoreLights+2Cj
//@ 					; RestoreLights+35j
//@ 		imul	di, [bp+N], 12h	; int16_t
//@ 		add	di, 0BCA4h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_10], di
//@ 		mov	word ptr [bp+var_10+2],	es
//@ ; #line	"CSPRNDR.PAS" 120
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, es:[di+4]	; Integer Subtraction
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+FY1]	; int16_t
//@ 		jge	short loc_10658	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, es:[di+4]	; Integer Subtraction
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+FY1], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 121
//@ 
//@ loc_10658:				; CODE XREF: RestoreLights+57j
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, es:[di+4]	; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, [bp+FY2]	; int16_t
//@ 		jle	short loc_10677	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, es:[di+4]	; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+FY2], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 122
//@ 
//@ loc_10677:				; CODE XREF: RestoreLights+76j
//@ 		les	di, [bp+var_10]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, es:[di+0Ch]	; Compare Two Operands
//@ 		jbe	short loc_106C9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPRNDR.PAS" 124
//@ 		mov	ax, [bp+N]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	12h	; Signed Multiply
//@ 		add	di, 0BCA4h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, [bp+N], 12h	; int16_t
//@ 		add	di, 0BCA4h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+N]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		add	ax, 1		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 12h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPRNDR.PAS" 125
//@ 		dec	[bp+N]		; int16_t
//@ 		dec	LCount		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 127
//@ 
//@ loc_106C9:				; CODE XREF: RestoreLights+90j
//@ 		inc	[bp+N]		; int16_t
//@ ; #line	"CSPRNDR.PAS" 128
//@ 		jmp	loc_1060F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 130
//@ 
//@ loc_106CF:				; CODE XREF: RestoreLights+30j
//@ 					; RestoreLights+37j
//@ 		cmp	[bp+FY1], 0	; int16_t
//@ 		jge	short loc_106DA	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+FY1], ax	; int16_t
//@ 
//@ loc_106DA:				; CODE XREF: RestoreLights+E1j
//@ 		cmp	[bp+FY2], 0FEh ; '˛' ; int16_t
//@ 		jle	short loc_106E6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+FY2], 0FEh ; '˛' ; int16_t
//@ ; #line	"CSPRNDR.PAS" 132
//@ 
//@ loc_106E6:				; CODE XREF: RestoreLights+EDj
//@ 		mov	ax, [bp+FY1]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+WY1], ax	; int16_t
//@ 		mov	ax, [bp+FY2]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		add	ax, 3		; Add
//@ 		mov	[bp+WY2], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 133
//@ 		mov	ax, [bp+FY2]	; int16_t
//@ 		sub	ax, [bp+FY1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+W],	ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 134
//@ 		cmp	[bp+WY1], 0	; int16_t
//@ 		jge	short loc_10712	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+WY1], ax	; int16_t
//@ 
//@ loc_10712:				; CODE XREF: RestoreLights+119j
//@ 		cmp	[bp+WY2], 3Eh ;	'>' ; int16_t
//@ 		jle	short loc_1071D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+WY2], 3Eh ;	'>' ; int16_t
//@ ; #line	"CSPRNDR.PAS" 135
//@ 
//@ loc_1071D:				; CODE XREF: RestoreLights+124j
//@ 		mov	ax, [bp+W]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		cmp	ax, 3Ch	; '<'   ; Compare Two Operands
//@ 		jbe	short loc_10762	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPRNDR.PAS" 136
//@ 		lea	di, [bp+var_20C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aClear ; "CLEAR: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_10C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_2	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+W]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage	; function far PASCAL returns void
//@ ; #line	"CSPRNDR.PAS" 138
//@ 
//@ loc_10762:				; CODE XREF: RestoreLights+134j
//@ 		push	ShadowSeg2	; uint16_t
//@ 		mov	ax, [bp+FY1]	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	ShadowSeg	; uint16_t
//@ 		mov	ax, [bp+FY1]	; int16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		push	ax
//@ 		mov	ax, [bp+W]	; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	movsD$0		; function far PASCAL returns void
//@ ; #line	"CSPRNDR.PAS" 139
//@ 		push	WShadowSeg2	; uint16_t
//@ 		mov	ax, [bp+WY1]	; int16_t
//@ 		shl	ax, 9		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	WShadowSeg	; uint16_t
//@ 		mov	ax, [bp+WY1]	; int16_t
//@ 		shl	ax, 9		; Shift	Logical	Left
//@ 		push	ax
//@ 		mov	ax, [bp+WY2]	; int16_t
//@ 		sub	ax, [bp+WY1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	movsD$0		; function far PASCAL returns void
//@ ; #line	"CSPRNDR.PAS" 140
//@ 
//@ locret_107AA:				; CODE XREF: RestoreLights+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ RestoreLights	endp
//@ 
//@ ; #line	"CSPRNDR.PAS" 145
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RenderLightOnMap proc near		; CODE XREF: ProcessLights+1FEp
//@ 					; AddLightSource+32p
//@ 
//@ var_8		= word ptr -8
//@ var_6		= word ptr -6
//@ WSEG		= word ptr -4		; uint16_t
//@ FSEG		= word ptr -2		; uint16_t
//@ Original	= byte ptr  4		; bool
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPRNDR.PAS" 146
//@ 		cmp	[bp+Original], 0 ; bool
//@ 		jz	short loc_107C4	; Jump if Zero (ZF=1)
//@ ; #line	"CSPRNDR.PAS" 147
//@ 		mov	ax, ShadowSeg2	; uint16_t
//@ 		mov	[bp+FSEG], ax	; uint16_t
//@ 		mov	ax, WShadowSeg2	; uint16_t
//@ 		mov	[bp+WSEG], ax	; uint16_t
//@ 		jmp	short loc_107D0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 148
//@ 
//@ loc_107C4:				; CODE XREF: RenderLightOnMap+8j
//@ 		mov	ax, ShadowSeg	; uint16_t
//@ 		mov	[bp+FSEG], ax	; uint16_t
//@ 		mov	ax, WShadowSeg	; uint16_t
//@ 		mov	[bp+WSEG], ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 150
//@ 
//@ loc_107D0:				; CODE XREF: RenderLightOnMap+16j
//@ 		mov	ax, CurR2	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LLX		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	Wx1, ax		; uint16_t
//@ 		cmp	Wx1, 0		; uint16_t
//@ 		jge	short loc_10800	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Wx1, ax		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 151
//@ 
//@ loc_10800:				; CODE XREF: RenderLightOnMap+4Dj
//@ 		mov	ax, CurR2	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LLY		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	Wy1, ax		; uint16_t
//@ 		cmp	Wy1, 0		; uint16_t
//@ 		jge	short loc_10830	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Wy1, ax		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 152
//@ 
//@ loc_10830:				; CODE XREF: RenderLightOnMap+7Dj
//@ 		mov	ax, CurR2	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LLX		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		add	ax, 3		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		add	ax, 2		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	Wx2, ax		; uint16_t
//@ 		cmp	Wx2, 63		; uint16_t
//@ 		jbe	short loc_10867	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	Wx2, 63		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 153
//@ 
//@ loc_10867:				; CODE XREF: RenderLightOnMap+B3j
//@ 		mov	ax, CurR2	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, LLY		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		add	ax, 3		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		add	ax, 2		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	Wy2, ax		; uint16_t
//@ 		cmp	Wy2, 63		; uint16_t
//@ 		jbe	short loc_1089E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	Wy2, 63		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 155
//@ 
//@ loc_1089E:				; CODE XREF: RenderLightOnMap+EAj
//@ 		mov	ax, Wy2		; uint16_t
//@ 		mov	[bp+var_6], ax
//@ 		mov	ax, Wy1		; uint16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jbe	short loc_108AF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_109F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_108AF:				; CODE XREF: RenderLightOnMap+FEj
//@ 		mov	ccy, ax		; uint16_t
//@ 		jmp	short loc_108B8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_108B4:				; CODE XREF: RenderLightOnMap+244j
//@ 		inc	ccy		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 156
//@ 
//@ loc_108B8:				; CODE XREF: RenderLightOnMap+106j
//@ 		mov	ax, Wx2		; uint16_t
//@ 		mov	[bp+var_8], ax
//@ 		mov	ax, Wx1		; uint16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jbe	short loc_108C9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_109E8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_108C9:				; CODE XREF: RenderLightOnMap+118j
//@ 		mov	ccx, ax		; uint16_t
//@ 		jmp	short loc_108D2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_108CE:				; CODE XREF: RenderLightOnMap+239j
//@ 		inc	ccx		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 158
//@ 
//@ loc_108D2:				; CODE XREF: RenderLightOnMap+120j
//@ 		imul	ax, ccy, 0Bh	; uint16_t
//@ 		mov	dx, ax
//@ 		imul	ax, ccx, 2C0h	; uint16_t
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
//@ ; #line	"CSPRNDR.PAS" 159
//@ 		mov	al, L.Spr	; struct TLoc
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnb	short loc_108FF	; Jump if Not Below (CF=0)
//@ 		jmp	loc_109DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_108FF:				; CODE XREF: RenderLightOnMap+14Ej
//@ 		cmp	al, 120		; Compare Two Operands
//@ 		jbe	short loc_10906	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_109DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 162
//@ 
//@ loc_10906:				; CODE XREF: RenderLightOnMap+155j
//@ 		mov	ax, L.x1	; struct TLoc
//@ 		sub	ax, L.x2	; struct TLoc
//@ 		sar	ax, 3		; Shift	Arithmetic Right
//@ 		mov	DWx, ax		; int16_t
//@ ; #line	"CSPRNDR.PAS" 163
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		add	ax, L.x2	; struct TLoc
//@ 		mov	Wx, ax		; int16_t
//@ ; #line	"CSPRNDR.PAS" 164
//@ 		mov	ax, L.y1	; struct TLoc
//@ 		sub	ax, L.y2	; struct TLoc
//@ 		sar	ax, 3		; Shift	Arithmetic Right
//@ 		mov	Dwy, ax		; int16_t
//@ ; #line	"CSPRNDR.PAS" 165
//@ 		sar	ax, 1		; Shift	Arithmetic Right
//@ 		add	ax, L.y2	; struct TLoc
//@ 		mov	Wy, ax		; int16_t
//@ ; #line	"CSPRNDR.PAS" 166
//@ 		mov	ax, ccy		; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		add	ax, ccx		; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	os, ax		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 169
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	k, ax		; int16_t
//@ 		jmp	short loc_1094D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10949:				; CODE XREF: RenderLightOnMap+22Ej
//@ 		inc	k		; int16_t
//@ ; #line	"CSPRNDR.PAS" 171
//@ 
//@ loc_1094D:				; CODE XREF: RenderLightOnMap+19Bj
//@ 		mov	ax, Wx		; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		sub	ax, LLX		; int16_t
//@ ; #line	"CSPRNDR.PAS" 172
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	bx, ax
//@ 		shl	bx, 5		; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 173
//@ 		mov	ax, Wy		; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		sub	ax, LLY		; int16_t
//@ ; #line	"CSPRNDR.PAS" 174
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	bx, ax		; Add
//@ ; #line	"CSPRNDR.PAS" 175
//@ 		mov	al, PifTab[bx]	; uint8_t[1024]
//@ ; #line	"CSPRNDR.PAS" 176
//@ 		mov	R$0, ax		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 178
//@ 		mov	R$0, ax		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 180
//@ 		mov	ax, CurR	; uint16_t
//@ 		cmp	R$0, ax		; uint16_t
//@ 		jnb	short loc_109C1	; Jump if Not Below (CF=0)
//@ ; #line	"CSPRNDR.PAS" 181
//@ 		sub	ax, R$0		; uint16_t
//@ 		mul	CurL		; uint16_t
//@ 		div	CurR		; uint16_t
//@ 		shr	al, 2		; Shift	Logical	Right
//@ 		mov	B, al		; uint8_t
//@ ; #line	"CSPRNDR.PAS" 183
//@ 		mov	di, os		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 184
//@ 		mov	ax, WShadowSeg2	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSPRNDR.PAS" 185
//@ 		mov	al, es:[di]
//@ 		sub	al, B		; uint8_t
//@ ; #line	"CSPRNDR.PAS" 186
//@ 		jns	short loc_109AB	; Jump if Not Sign (SF=0)
//@ 		xor	al, al		; Logical Exclusive OR
//@ ; #line	"CSPRNDR.PAS" 187
//@ 
//@ loc_109AB:				; CODE XREF: RenderLightOnMap+1FBj
//@ 		mov	B, al		; uint8_t
//@ ; #line	"CSPRNDR.PAS" 189
//@ 		mov	ax, [bp+WSEG]	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSPRNDR.PAS" 190
//@ 		mov	al, es:[di]
//@ 		mov	ah, B		; uint8_t
//@ ; #line	"CSPRNDR.PAS" 191
//@ 		cmp	al, ah		; Compare Two Operands
//@ 		jbe	short loc_109C1	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPRNDR.PAS" 192
//@ 		mov	es:[di], ah
//@ ; #line	"CSPRNDR.PAS" 193
//@ 
//@ loc_109C1:				; CODE XREF: RenderLightOnMap+1D7j
//@ 					; RenderLightOnMap+210j
//@ 		mov	ax, DWx		; int16_t
//@ 		add	Wx, ax		; int16_t
//@ ; #line	"CSPRNDR.PAS" 194
//@ 		mov	ax, Dwy		; int16_t
//@ 		add	Wy, ax		; int16_t
//@ ; #line	"CSPRNDR.PAS" 195
//@ 		inc	os		; uint16_t
//@ 		cmp	k, 7		; int16_t
//@ 		jz	short loc_109DD	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10949	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 198
//@ 
//@ loc_109DD:				; CODE XREF: RenderLightOnMap+150j
//@ 					; RenderLightOnMap+157j ...
//@ 		mov	ax, ccx		; uint16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jz	short loc_109E8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_108CE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_109E8:				; CODE XREF: RenderLightOnMap+11Aj
//@ 					; RenderLightOnMap+237j
//@ 		mov	ax, ccy		; uint16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jz	short loc_109F3	; Jump if Zero (ZF=1)
//@ 		jmp	loc_108B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 202
//@ 
//@ loc_109F3:				; CODE XREF: RenderLightOnMap+100j
//@ 					; RenderLightOnMap+242j
//@ 		mov	ax, ShadowSeg2	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 203
//@ 		mov	fs, ax
//@ ; #line	"CSPRNDR.PAS" 204
//@ 		mov	ax, [bp+FSEG]	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 205
//@ 		mov	es, ax
//@ ; #line	"CSPRNDR.PAS" 208
//@ 		mov	ax, CurR2	; uint16_t
//@ 		mov	[bp+var_6], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jbe	short loc_10A0D	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_10B30	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10A0D:				; CODE XREF: RenderLightOnMap+25Cj
//@ 		mov	ccy, ax		; uint16_t
//@ 		jmp	short loc_10A16	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10A12:				; CODE XREF: RenderLightOnMap+381j
//@ 		inc	ccy		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 209
//@ 
//@ loc_10A16:				; CODE XREF: RenderLightOnMap+264j
//@ 		mov	ax, CurR2	; uint16_t
//@ 		mov	[bp+var_8], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jbe	short loc_10A26	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_10B25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10A26:				; CODE XREF: RenderLightOnMap+275j
//@ 		mov	ccx, ax		; uint16_t
//@ 		jmp	short loc_10A2F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10A2B:				; CODE XREF: RenderLightOnMap+376j
//@ 		inc	ccx		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 215
//@ 
//@ loc_10A2F:				; CODE XREF: RenderLightOnMap+27Dj
//@ 		mov	bx, ccx		; uint16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	bx, 5		; Shift	Logical	Left
//@ 		add	bx, ccy		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 216
//@ 		mov	al, PifTab[bx]	; uint8_t[1024]
//@ ; #line	"CSPRNDR.PAS" 217
//@ 		mov	R$0, ax		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 219
//@ 		mov	ax, CurR	; uint16_t
//@ 		cmp	R$0, ax		; uint16_t
//@ 		jb	short loc_10A4F	; Jump if Below	(CF=1)
//@ 		jmp	loc_10B1A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 220
//@ 
//@ loc_10A4F:				; CODE XREF: RenderLightOnMap+29Ej
//@ 		sub	ax, R$0		; uint16_t
//@ 		mul	CurL		; uint16_t
//@ 		div	CurR		; uint16_t
//@ 		shr	al, 2		; Shift	Logical	Right
//@ 		mov	B, al		; uint8_t
//@ ; #line	"CSPRNDR.PAS" 222
//@ 		mov	di, LLY		; int16_t
//@ 		add	di, ccy		; uint16_t
//@ 		shl	di, 8		; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 223
//@ 		mov	ax, LLX		; int16_t
//@ 		add	ax, ccx		; uint16_t
//@ 		add	di, ax		; Add
//@ ; #line	"CSPRNDR.PAS" 224
//@ 		mov	ah, fs:[di]
//@ ; #line	"CSPRNDR.PAS" 225
//@ 		sub	ah, B		; uint8_t
//@ 		jns	short loc_10A80	; Jump if Not Sign (SF=0)
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CSPRNDR.PAS" 226
//@ 
//@ loc_10A80:				; CODE XREF: RenderLightOnMap+2D0j
//@ 		mov	al, es:[di]
//@ ; #line	"CSPRNDR.PAS" 227
//@ 		cmp	al, ah		; Compare Two Operands
//@ 		jbe	short loc_10A8A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	es:[di], ah
//@ ; #line	"CSPRNDR.PAS" 229
//@ 
//@ loc_10A8A:				; CODE XREF: RenderLightOnMap+2D9j
//@ 		cmp	ccy, 0		; uint16_t
//@ 		jz	short loc_10ABA	; Jump if Zero (ZF=1)
//@ ; #line	"CSPRNDR.PAS" 230
//@ 		mov	di, LLY		; int16_t
//@ 		sub	di, ccy		; uint16_t
//@ 		shl	di, 8		; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 231
//@ 		mov	ax, LLX		; int16_t
//@ 		add	ax, ccx		; uint16_t
//@ 		add	di, ax		; Add
//@ ; #line	"CSPRNDR.PAS" 232
//@ 		mov	ah, fs:[di]
//@ ; #line	"CSPRNDR.PAS" 233
//@ 		sub	ah, B		; uint8_t
//@ 		jns	short loc_10AB0	; Jump if Not Sign (SF=0)
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CSPRNDR.PAS" 234
//@ 
//@ loc_10AB0:				; CODE XREF: RenderLightOnMap+300j
//@ 		mov	al, es:[di]
//@ ; #line	"CSPRNDR.PAS" 235
//@ 		cmp	al, ah		; Compare Two Operands
//@ 		jbe	short loc_10ABA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	es:[di], ah
//@ ; #line	"CSPRNDR.PAS" 238
//@ 
//@ loc_10ABA:				; CODE XREF: RenderLightOnMap+2E3j
//@ 					; RenderLightOnMap+309j
//@ 		cmp	ccx, 0		; uint16_t
//@ 		jz	short loc_10B1A	; Jump if Zero (ZF=1)
//@ ; #line	"CSPRNDR.PAS" 239
//@ 		mov	di, LLY		; int16_t
//@ 		add	di, ccy		; uint16_t
//@ 		shl	di, 8		; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 240
//@ 		mov	ax, LLX		; int16_t
//@ 		sub	ax, ccx		; uint16_t
//@ 		add	di, ax		; Add
//@ ; #line	"CSPRNDR.PAS" 241
//@ 		mov	ah, fs:[di]
//@ ; #line	"CSPRNDR.PAS" 242
//@ 		sub	ah, B		; uint8_t
//@ 		jns	short loc_10AE0	; Jump if Not Sign (SF=0)
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CSPRNDR.PAS" 243
//@ 
//@ loc_10AE0:				; CODE XREF: RenderLightOnMap+330j
//@ 		mov	al, es:[di]
//@ ; #line	"CSPRNDR.PAS" 244
//@ 		cmp	al, ah		; Compare Two Operands
//@ 		jbe	short loc_10AEA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	es:[di], ah
//@ ; #line	"CSPRNDR.PAS" 246
//@ 
//@ loc_10AEA:				; CODE XREF: RenderLightOnMap+339j
//@ 		cmp	ccy, 0		; uint16_t
//@ 		jz	short loc_10B1A	; Jump if Zero (ZF=1)
//@ ; #line	"CSPRNDR.PAS" 247
//@ 		mov	di, LLY		; int16_t
//@ 		sub	di, ccy		; uint16_t
//@ 		shl	di, 8		; Shift	Logical	Left
//@ ; #line	"CSPRNDR.PAS" 248
//@ 		mov	ax, LLX		; int16_t
//@ 		sub	ax, ccx		; uint16_t
//@ 		add	di, ax		; Add
//@ ; #line	"CSPRNDR.PAS" 249
//@ 		mov	ah, fs:[di]
//@ ; #line	"CSPRNDR.PAS" 250
//@ 		sub	ah, B		; uint8_t
//@ 		jns	short loc_10B10	; Jump if Not Sign (SF=0)
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ ; #line	"CSPRNDR.PAS" 251
//@ 
//@ loc_10B10:				; CODE XREF: RenderLightOnMap+360j
//@ 		mov	al, es:[di]
//@ ; #line	"CSPRNDR.PAS" 252
//@ 		cmp	al, ah		; Compare Two Operands
//@ 		jbe	short loc_10B1A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	es:[di], ah
//@ ; #line	"CSPRNDR.PAS" 256
//@ 
//@ loc_10B1A:				; CODE XREF: RenderLightOnMap+2A0j
//@ 					; RenderLightOnMap+313j ...
//@ 		mov	ax, ccx		; uint16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jz	short loc_10B25	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10A2B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10B25:				; CODE XREF: RenderLightOnMap+277j
//@ 					; RenderLightOnMap+374j
//@ 		mov	ax, ccy		; uint16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jz	short locret_10B30 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_10A12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 257
//@ 
//@ locret_10B30:				; CODE XREF: RenderLightOnMap+25Ej
//@ 					; RenderLightOnMap+37Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ RenderLightOnMap endp
//@ 
//@ ; #line	"CSPRNDR.PAS" 262
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessLights	proc far		; CODE XREF: DoGame+9DFP
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPRNDR.PAS" 263
//@ 		call	RestoreLights	; function near	PASCAL returns void
//@ ; #line	"CSPRNDR.PAS" 265
//@ 		mov	N, 1		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 266
//@ 
//@ loc_10B41:				; CODE XREF: ProcessLights+205j
//@ 		mov	ax, N		; uint16_t
//@ 		cmp	ax, LCount	; uint16_t
//@ 		jbe	short loc_10B4D	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_10D3C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 267
//@ 
//@ loc_10B4D:				; CODE XREF: ProcessLights+14j
//@ 		imul	di, N, 12h	; uint16_t
//@ 		add	di, 0BCA4h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPRNDR.PAS" 269
//@ 		cmp	word ptr es:[di+10h], 1	; Compare Two Operands
//@ 		jz	short loc_10B68	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10C3C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 271
//@ 
//@ loc_10B68:				; CODE XREF: ProcessLights+2Fj
//@ 		cmp	word ptr es:[di+0Ch], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_10B96	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPRNDR.PAS" 273
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	CurR, ax	; uint16_t
//@ 		mov	ax, es:[di+6]
//@ 		mov	CurL, ax	; uint16_t
//@ 		mov	word ptr es:[di+0Eh], 0Ah
//@ 		mov	word ptr es:[di+0Ch], 8
//@ 		mov	word ptr es:[di+10h], 2
//@ ; #line	"CSPRNDR.PAS" 274
//@ 		jmp	loc_10C39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 276
//@ 
//@ loc_10B96:				; CODE XREF: ProcessLights+3Aj
//@ 		mov	ax, t1		; uint16_t
//@ 		add	ax, t1		; uint16_t
//@ 		add	ax, t1		; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	es:[di+0Eh], ax	; Add
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, es:[di+0Ch]	; Compare Two Operands
//@ 		jbe	short loc_10BBA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSPRNDR.PAS" 277
//@ 
//@ loc_10BBA:				; CODE XREF: ProcessLights+7Cj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 0Ah		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	ax, 1		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	CurR, ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 278
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 14h		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 14h		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	CurL, ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 279
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		cmp	ax, es:[di+0Ch]	; Compare Two Operands
//@ 		jb	short loc_10C39	; Jump if Below	(CF=1)
//@ 		mov	word ptr es:[di+10h], 2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSPRNDR.PAS" 281
//@ 
//@ loc_10C39:				; CODE XREF: ProcessLights+5Fj
//@ 					; ProcessLights+F7j
//@ 		jmp	loc_10CCA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 283
//@ 
//@ loc_10C3C:				; CODE XREF: ProcessLights+31j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 8		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		add	ax, 1		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	CurR, ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 284
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 14h		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		add	ax, 14h		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	CurL, ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 285
//@ 		mov	ax, t1		; uint16_t
//@ 		add	es:[di+0Eh], ax	; Add
//@ ; #line	"CSPRNDR.PAS" 288
//@ 
//@ loc_10CCA:				; CODE XREF: ProcessLights:loc_10C39j
//@ 		mov	ax, CurR	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		mov	ax, CurL	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSPRNDR.PAS" 290
//@ 		mov	ax, es:[di]
//@ 		mov	LLX, ax		; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	LLY, ax		; int16_t
//@ 		mov	ax, CurR	; uint16_t
//@ 		add	ax, 3		; Add
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	CurR2, ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 292
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_10D30	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPRNDR.PAS" 293
//@ 		mov	ax, LLY		; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, ehy		; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jg	short loc_10D2E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, LLX		; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, ehx		; int16_t
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, MapR	; int16_t
//@ 		jle	short loc_10D30	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_10D2E:				; CODE XREF: ProcessLights+1E0j
//@ 		jmp	short loc_10D35	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 296
//@ 
//@ loc_10D30:				; CODE XREF: ProcessLights+1C8j
//@ 					; ProcessLights+1F8j
//@ 		push	0
//@ 		call	RenderLightOnMap ; function near PASCAL	returns	void
//@ ; #line	"CSPRNDR.PAS" 299
//@ 
//@ loc_10D35:				; CODE XREF: ProcessLights:loc_10D2Ej
//@ 		inc	N		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 300
//@ 		jmp	loc_10B41	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 301
//@ 
//@ locret_10D3C:				; CODE XREF: ProcessLights+16j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ProcessLights	endp
//@ 
//@ ; #line	"CSPRNDR.PAS" 306
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddLightSource	proc far		; CODE XREF: ContinueProcess+31EP
//@ 
//@ P		= word ptr  6		; int16_t
//@ R		= word ptr  8		; int16_t
//@ Ly		= word ptr  0Ah		; int16_t
//@ Lx		= word ptr  0Ch		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPRNDR.PAS" 307
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	CurR, ax	; uint16_t
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	CurL, ax	; uint16_t
//@ 		mov	ax, [bp+Lx]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	LLX, ax		; int16_t
//@ 		mov	ax, [bp+Ly]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	LLY, ax		; int16_t
//@ ; #line	"CSPRNDR.PAS" 308
//@ 		mov	ax, [bp+R]	; int16_t
//@ 		add	ax, 3		; Add
//@ 		mov	CurR2, ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 309
//@ 		push	1
//@ 		call	RenderLightOnMap ; function near PASCAL	returns	void
//@ ; #line	"CSPRNDR.PAS" 310
//@ 		push	[bp+Lx]		; int16_t
//@ 		push	[bp+Ly]		; int16_t
//@ 		push	[bp+R]		; int16_t
//@ 		push	0
//@ 		push	0FFh
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSPRNDR.PAS" 311
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ AddLightSource	endp
//@ 
//@ ; #line	"CSPRNDR.PAS" 318
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BackRender	proc far		; CODE XREF: ContinueProcess+376P
//@ 					; RemoveLight+9CP
//@ 
//@ var_24		= dword	ptr -24h
//@ var_20		= word ptr -20h
//@ var_1E		= word ptr -1Eh
//@ n		= word ptr -1Ch		; uint16_t
//@ H		= word ptr -1Ah		; uint16_t
//@ L		= word ptr -18h		; uint16_t
//@ y		= word ptr -16h		; uint16_t
//@ x		= word ptr -14h		; uint16_t
//@ dd		= word ptr -12h		; uint16_t
//@ py		= word ptr -10h		; int16_t
//@ px		= word ptr -0Eh		; int16_t
//@ dy		= word ptr -0Ch		; int16_t
//@ $dx		= word ptr -0Ah		; int16_t
//@ yy2		= word ptr -8		; int16_t
//@ yy1		= word ptr -6		; int16_t
//@ xx2		= word ptr -4		; int16_t
//@ xx1		= word ptr -2		; int16_t
//@ VisCheck	= byte ptr  6		; bool
//@ LR		= word ptr  8		; int16_t
//@ MY		= word ptr  0Ah		; int16_t
//@ MX		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	24h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPRNDR.PAS" 319
//@ 		mov	ax, [bp+MX]	; int16_t
//@ 		sub	ax, [bp+LR]	; int16_t
//@ 		mov	[bp+xx1], ax	; int16_t
//@ 		cmp	[bp+xx1], 0	; int16_t
//@ 		jge	short loc_10DA2	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+xx1], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 320
//@ 
//@ loc_10DA2:				; CODE XREF: BackRender+11j
//@ 		mov	ax, [bp+MY]	; int16_t
//@ 		sub	ax, [bp+LR]	; int16_t
//@ 		mov	[bp+yy1], ax	; int16_t
//@ 		cmp	[bp+yy1], 0	; int16_t
//@ 		jge	short loc_10DB6	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+yy1], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 321
//@ 
//@ loc_10DB6:				; CODE XREF: BackRender+25j
//@ 		mov	ax, [bp+MX]	; int16_t
//@ 		add	ax, [bp+LR]	; int16_t
//@ 		mov	[bp+xx2], ax	; int16_t
//@ 		cmp	[bp+xx2], 0FFh	; int16_t
//@ 		jle	short loc_10DCB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+xx2], 0FFh	; int16_t
//@ ; #line	"CSPRNDR.PAS" 322
//@ 
//@ loc_10DCB:				; CODE XREF: BackRender+3Aj
//@ 		mov	ax, [bp+MY]	; int16_t
//@ 		add	ax, [bp+LR]	; int16_t
//@ 		mov	[bp+yy2], ax	; int16_t
//@ 		cmp	[bp+yy2], 0FFh	; int16_t
//@ 		jle	short loc_10DE0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+yy2], 0FFh	; int16_t
//@ ; #line	"CSPRNDR.PAS" 323
//@ 
//@ loc_10DE0:				; CODE XREF: BackRender+4Fj
//@ 		mov	ax, [bp+xx2]	; int16_t
//@ 		sub	ax, [bp+xx1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+L],	ax	; uint16_t
//@ 		mov	ax, [bp+yy2]	; int16_t
//@ 		sub	ax, [bp+yy1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+H],	ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 324
//@ 		mov	ax, [bp+yy2]	; int16_t
//@ 		mov	[bp+var_1E], ax
//@ 		mov	ax, [bp+yy1]	; int16_t
//@ 		cmp	ax, [bp+var_1E]	; Compare Two Operands
//@ 		jbe	short loc_10E05	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_10EA7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10E05:				; CODE XREF: BackRender+76j
//@ 		mov	[bp+y],	ax	; uint16_t
//@ 		jmp	short loc_10E0D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10E0A:				; CODE XREF: BackRender+11Aj
//@ 		inc	[bp+y]		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 325
//@ 
//@ loc_10E0D:				; CODE XREF: BackRender+7Ej
//@ 		mov	ax, [bp+xx2]	; int16_t
//@ 		mov	[bp+var_20], ax
//@ 		mov	ax, [bp+xx1]	; int16_t
//@ 		cmp	ax, [bp+var_20]	; Compare Two Operands
//@ 		jbe	short loc_10E1E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_10E9C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10E1E:				; CODE XREF: BackRender+8Fj
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_10E26	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10E23:				; CODE XREF: BackRender+110j
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 326
//@ 
//@ loc_10E26:				; CODE XREF: BackRender+97j
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+MX]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+MY]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		call	QPifagorA32	; function near	PASCAL returns unsigned	int 'Word'
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+LR]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_10E65	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_10E94	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_10E94	; Jump if Below	(CF=1)
//@ ; #line	"CSPRNDR.PAS" 327
//@ 
//@ loc_10E65:				; CODE XREF: BackRender+D3j
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, DarkMap	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	dl, es:[di]
//@ 		mov	ax, ShadowSeg2	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, [bp+x]	; uint16_t
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ 
//@ loc_10E94:				; CODE XREF: BackRender+D5j
//@ 					; BackRender+D9j
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		cmp	ax, [bp+var_20]	; Compare Two Operands
//@ 		jnz	short loc_10E23	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_10E9C:				; CODE XREF: BackRender+91j
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		cmp	ax, [bp+var_1E]	; Compare Two Operands
//@ 		jz	short loc_10EA7	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10E0A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 329
//@ 
//@ loc_10EA7:				; CODE XREF: BackRender+78j
//@ 					; BackRender+118j
//@ 		mov	ax, [bp+xx1]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+xx1], ax	; int16_t
//@ 		cmp	[bp+xx1], 0	; int16_t
//@ 		jge	short loc_10EBD	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+xx1], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 330
//@ 
//@ loc_10EBD:				; CODE XREF: BackRender+12Cj
//@ 		mov	ax, [bp+yy1]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+yy1], ax	; int16_t
//@ 		cmp	[bp+yy1], 0	; int16_t
//@ 		jge	short loc_10ED3	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+yy1], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 331
//@ 
//@ loc_10ED3:				; CODE XREF: BackRender+142j
//@ 		mov	ax, [bp+xx2]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+xx2], ax	; int16_t
//@ 		cmp	[bp+xx2], 63	; int16_t
//@ 		jle	short loc_10EE9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+xx2], 63	; int16_t
//@ ; #line	"CSPRNDR.PAS" 332
//@ 
//@ loc_10EE9:				; CODE XREF: BackRender+158j
//@ 		mov	ax, [bp+yy2]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+yy2], ax	; int16_t
//@ 		cmp	[bp+yy2], 63	; int16_t
//@ 		jle	short loc_10EFF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+yy2], 63	; int16_t
//@ ; #line	"CSPRNDR.PAS" 334
//@ 
//@ loc_10EFF:				; CODE XREF: BackRender+16Ej
//@ 		mov	ax, [bp+LR]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		add	ax, 32		; Add
//@ 		mov	[bp+LR], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 335
//@ 		mov	ax, [bp+MX]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	[bp+MX], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 336
//@ 		mov	ax, [bp+MY]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	[bp+MY], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 338
//@ 		mov	ax, [bp+yy2]	; int16_t
//@ 		mov	[bp+var_1E], ax
//@ 		mov	ax, [bp+yy1]	; int16_t
//@ 		cmp	ax, [bp+var_1E]	; Compare Two Operands
//@ 		jbe	short loc_10F2E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_11074	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10F2E:				; CODE XREF: BackRender+19Fj
//@ 		mov	[bp+y],	ax	; uint16_t
//@ 		jmp	short loc_10F36	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10F33:				; CODE XREF: BackRender+2E7j
//@ 		inc	[bp+y]		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 339
//@ 
//@ loc_10F36:				; CODE XREF: BackRender+1A7j
//@ 		mov	ax, [bp+xx2]	; int16_t
//@ 		mov	[bp+var_20], ax
//@ 		mov	ax, [bp+xx1]	; int16_t
//@ 		cmp	ax, [bp+var_20]	; Compare Two Operands
//@ 		jbe	short loc_10F47	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_11069	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10F47:				; CODE XREF: BackRender+1B8j
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_10F4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10F4C:				; CODE XREF: BackRender+2DCj
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 340
//@ 
//@ loc_10F4F:				; CODE XREF: BackRender+1C0j
//@ 		imul	ax, [bp+y], 0Bh	; uint16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+x], 2C0h ; uint16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_24], di
//@ 		mov	word ptr [bp+var_24+2],	es
//@ 		mov	al, es:[di]
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnb	short loc_10F72	; Jump if Not Below (CF=0)
//@ 		jmp	loc_1105E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10F72:				; CODE XREF: BackRender+1E3j
//@ 		cmp	al, 120		; Compare Two Operands
//@ 		jbe	short loc_10F79	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_1105E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 342
//@ 
//@ loc_10F79:				; CODE XREF: BackRender+1EAj
//@ 		cmp	[bp+VisCheck], 0 ; bool
//@ 		jz	short loc_10FBA	; Jump if Zero (ZF=1)
//@ ; #line	"CSPRNDR.PAS" 343
//@ 		mov	al, es:[di]
//@ 		cmp	al, 86		; Compare Two Operands
//@ 		jb	short loc_10F8A	; Jump if Below	(CF=1)
//@ 		cmp	al, 120		; Compare Two Operands
//@ 		jbe	short loc_10FBA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPRNDR.PAS" 344
//@ 
//@ loc_10F8A:				; CODE XREF: BackRender+1FAj
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		sub	ax, [bp+MX]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, [bp+MY]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+9]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		push	ax
//@ 		call	MulVectors$2	; function near	PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 0FFFFh	; Compare Two Operands
//@ 		jnz	short loc_10FBA	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1105E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 345
//@ 
//@ loc_10FBA:				; CODE XREF: BackRender+1F3j
//@ 					; BackRender+1FEj ...
//@ 		les	di, [bp+var_24]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+7]
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+$dx], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 346
//@ 		mov	ax, es:[di+9]
//@ 		sub	ax, es:[di+5]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 8
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+dy], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 347
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+dd], ax	; uint16_t
//@ ; #line	"CSPRNDR.PAS" 348
//@ 		mov	ax, es:[di+3]
//@ 		mov	[bp+px], ax	; int16_t
//@ 		mov	ax, es:[di+5]
//@ 		mov	[bp+py], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 349
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_11000	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_10FFD:				; CODE XREF: BackRender+2D2j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSPRNDR.PAS" 351
//@ 
//@ loc_11000:				; CODE XREF: BackRender+271j
//@ 		mov	ax, [bp+MX]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		add	ax, [bp+px]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+MY]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		add	ax, [bp+py]	; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32	; function near	PASCAL returns unsigned	int 'Word'
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+LR]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_11029	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_1104C	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_1104C	; Jump if Below	(CF=1)
//@ ; #line	"CSPRNDR.PAS" 353
//@ 
//@ loc_11029:				; CODE XREF: BackRender+297j
//@ 		mov	cl, byte ptr [bp+dd] ; uint16_t
//@ 		mov	ax, WShadowSeg2	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shl	ax, 9		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		add	ax, 7		; Add
//@ 		sub	ax, [bp+n]	; uint16_t
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], cl
//@ ; #line	"CSPRNDR.PAS" 354
//@ 
//@ loc_1104C:				; CODE XREF: BackRender+299j
//@ 					; BackRender+29Dj
//@ 		mov	ax, [bp+$dx]	; int16_t
//@ 		add	[bp+px], ax	; int16_t
//@ 		mov	ax, [bp+dy]	; int16_t
//@ 		add	[bp+py], ax	; int16_t
//@ ; #line	"CSPRNDR.PAS" 355
//@ 		cmp	[bp+n],	7	; uint16_t
//@ 		jnz	short loc_10FFD	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPRNDR.PAS" 356
//@ 
//@ loc_1105E:				; CODE XREF: BackRender+1E5j
//@ 					; BackRender+1ECj ...
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		cmp	ax, [bp+var_20]	; Compare Two Operands
//@ 		jz	short loc_11069	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10F4C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11069:				; CODE XREF: BackRender+1BAj
//@ 					; BackRender+2DAj
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		cmp	ax, [bp+var_1E]	; Compare Two Operands
//@ 		jz	short loc_11074	; Jump if Zero (ZF=1)
//@ 		jmp	loc_10F33	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPRNDR.PAS" 358
//@ 
//@ loc_11074:				; CODE XREF: BackRender+1A1j
//@ 					; BackRender+2E5j
//@ 		push	ShadowSeg2	; uint16_t
//@ 		push	0
//@ 		push	ShadowSeg	; uint16_t
//@ 		push	0
//@ 		push	3FFFh
//@ 		call	movsD$0		; function far PASCAL returns void
//@ ; #line	"CSPRNDR.PAS" 359
//@ 		push	WShadowSeg2	; uint16_t
//@ 		push	0
//@ 		push	WShadowSeg	; uint16_t
//@ 		push	0
//@ 		push	1FFFh
//@ 		call	movsD$0		; function far PASCAL returns void
//@ ; #line	"CSPRNDR.PAS" 360
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ BackRender	endp
//@ 
//@ ; #line	"CSPRNDR.PAS" 365
//@ 
//! ; =============== S U B	R O U T	I N E =======================================
//! 
//! ; Attributes: bp-based frame
//! 
//! $CspRndrInit	proc far		; CODE XREF: PROGRAM+19P
void CspRndrInit()
{
//! 		push	bp
//! 		mov	bp, sp
//! ; #line	"CSPRNDR.PAS" 366
//! 		xor	ax, ax		; Logical Exclusive OR
//! 		mov	Wx, ax		; int16_t
//! 		jmp	short loc_110AE	; Jump
//! ; ---------------------------------------------------------------------------
//! 
//! loc_110AA:				; CODE XREF: $CspRndrInit+48j
//! 		inc	Wx		; int16_t
//! ; #line	"CSPRNDR.PAS" 367
//! 
//! loc_110AE:				; CODE XREF: $CspRndrInit+8j
//! 		xor	ax, ax		; Logical Exclusive OR
//! 		mov	Wy, ax		; int16_t
//! 		jmp	short loc_110B9	; Jump
//! ; ---------------------------------------------------------------------------
//! 
//! loc_110B5:				; CODE XREF: $CspRndrInit+41j
//! 		inc	Wy		; int16_t
//! ; #line	"CSPRNDR.PAS" 368
//! 
//! loc_110B9:				; CODE XREF: $CspRndrInit+13j
//! 		mov	ax, Wx		; int16_t
//! 		shl	ax, 2		; Shift	Logical	Left
//! 		push	ax
//! 		mov	ax, Wy		; int16_t
//! 		shl	ax, 2		; Shift	Logical	Left
//! 		push	ax
//! 		call	QPifagorP16	; function near	PASCAL returns unsigned	int 'Word'
//! 		mov	dl, al
//! 		mov	ax, Wy		; int16_t
//! 		mov	di, Wx		; int16_t
//! 		shl	di, 5		; Shift	Logical	Left
//! 		add	di, ax		; Add
//! 		mov	PifTab[di], dl	; uint8_t[1024]
//! 		cmp	Wy, 1Fh		; int16_t
//! 		jnz	short loc_110B5	; Jump if Not Zero (ZF=0)
//! 		cmp	Wx, 1Fh		; int16_t
//! 		jnz	short loc_110AA	; Jump if Not Zero (ZF=0)

    for (Wy = 0; Wy < 32; ++Wy)
    {
        for (Wx = 0; Wx < 32; ++Wx)
        {
            PifTab[Wy][Wx] = QPifagorP16(Wx * 4, Wy * 4);
        }
    }

//! ; #line	"CSPRNDR.PAS" 369
//! 		leave			; High Level Procedure Exit
//! 		retf			; Return Far from Procedure
//! $CspRndrInit	endp
}
//! 
//@ ; [0000000B BYTES: COLLAPSED FUNCTION unknown_libname_1. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000002 BYTES: COLLAPSED FUNCTION sub_110F7. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000030 BYTES: COLLAPSED FUNCTION __CrtInit(void). PRESS KEYPAD "+"	TO EXPAND]
//@ ; [00000074 BYTES: COLLAPSED FUNCTION unknown_libname_2. PRESS KEYPAD "+" TO EXPAND]
//@ ; [0000004D BYTES: COLLAPSED FUNCTION sub_1119D. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000048 BYTES: COLLAPSED FUNCTION sub_111EA. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000024 BYTES: COLLAPSED FUNCTION sub_11232. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000029 BYTES: COLLAPSED FUNCTION sub_11256. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000015 BYTES: COLLAPSED FUNCTION TextMode(Integer). PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000040 BYTES: COLLAPSED FUNCTION Window(Byte,Byte,Byte,Byte). PRESS KEYPAD	"+" TO EXPAND]
//@ ; [0000001A BYTES: COLLAPSED FUNCTION ClrScr(void). PRESS KEYPAD "+" TO	EXPAND]
//@ ; [00000014 BYTES: COLLAPSED FUNCTION ClrEol(void). PRESS KEYPAD "+" TO	EXPAND]
//@ ; [00000025 BYTES: COLLAPSED FUNCTION InsLine(void). PRESS KEYPAD "+" TO EXPAND]
//@ ; [0000002C BYTES: COLLAPSED FUNCTION GotoXY(Byte,Byte). PRESS KEYPAD "+" TO EXPAND]
//@ ; [0000000C BYTES: COLLAPSED FUNCTION WhereX(void). PRESS KEYPAD "+" TO	EXPAND]
//@ ; [0000000C BYTES: COLLAPSED FUNCTION WhereY(void). PRESS KEYPAD "+" TO	EXPAND]
//@ ; [0000001A BYTES: COLLAPSED FUNCTION TextColor(Byte). PRESS KEYPAD "+"	TO EXPAND]
//@ ; [00000018 BYTES: COLLAPSED FUNCTION TextBackground(Byte). PRESS KEYPAD "+" TO	EXPAND]
//@ ; [00000006 BYTES: COLLAPSED FUNCTION LowVideo(void). PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000006 BYTES: COLLAPSED FUNCTION HighVideo(void). PRESS KEYPAD "+"	TO EXPAND]
//@ ; [00000007 BYTES: COLLAPSED FUNCTION NormVideo(void). PRESS KEYPAD "+"	TO EXPAND]
//@ ; [0000001E BYTES: COLLAPSED FUNCTION Delay(Word). PRESS KEYPAD	"+" TO EXPAND]
//@ ; [0000000E BYTES: COLLAPSED FUNCTION sub_113CE. PRESS KEYPAD "+" TO EXPAND]
//@ ; [0000002D BYTES: COLLAPSED FUNCTION Sound(Word). PRESS KEYPAD	"+" TO EXPAND]
//@ ; [00000007 BYTES: COLLAPSED FUNCTION NoSound(void). PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000012 BYTES: COLLAPSED FUNCTION KeyPressed(void).	PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000022 BYTES: COLLAPSED FUNCTION ReadKey(void). PRESS KEYPAD "+" TO EXPAND]
//@ ; [0000002B BYTES: COLLAPSED FUNCTION AssignCrt(Text &). PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000038 BYTES: COLLAPSED FUNCTION sub_1146F. PRESS KEYPAD "+" TO EXPAND]
//@ ; [000000AD BYTES: COLLAPSED FUNCTION sub_114A7. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000031 BYTES: COLLAPSED FUNCTION sub_11554. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000005 BYTES: COLLAPSED FUNCTION sub_11585. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000007 BYTES: COLLAPSED FUNCTION sub_1158A. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000059 BYTES: COLLAPSED FUNCTION sub_11591. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000021 BYTES: COLLAPSED FUNCTION sub_115EA. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000007 BYTES: COLLAPSED FUNCTION sub_1160B. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000007 BYTES: COLLAPSED FUNCTION sub_11612. PRESS KEYPAD "+" TO EXPAND]
//@ ; [0000009B BYTES: COLLAPSED FUNCTION sub_11619. PRESS KEYPAD "+" TO EXPAND]
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ 
//@ sub_116B4	proc near		; CODE XREF: sub_11619+2Ap
//@ 					; sub_11619:loc_1164Fp	...
//@ 		cmp	si, di		; Compare Two Operands
//@ 		jz	short locret_1171B ; Jump if Zero (ZF=1)
//@ 		push	cx
//@ 		push	dx
//@ 		push	di
//@ 		push	ds
//@ 		push	es
//@ 		mov	cx, di
//@ 		sub	cx, si		; Integer Subtraction
//@ 		push	ds
//@ 		mov	ds, Seg0040	; uint16_t
//@ 		mov	al, bh
//@ 		mul	byte ptr ConsoleCommands+16h ; char[546] // Pascal string
//@ 		xor	bh, bh		; Logical Exclusive OR
//@ 		add	ax, bx		; Add
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	di, ax
//@ 		mov	dx, word ptr ConsoleCommands+2Fh ; char[546] //	Pascal string
//@ 		add	dx, 6		; Add
//@ 		cmp	byte ptr ConsoleCommands+15h, 7	; char[546] // Pascal string
//@ 		pop	ds
//@ 		mov	ax, SegB800	; uint16_t
//@ 		jnz	short loc_116E9	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, SegB000	; uint16_t
//@ 
//@ loc_116E9:				; CODE XREF: sub_116B4+30j
//@ 		mov	bl, CheckSnow	; bool
//@ 		mov	bh, TextAttr	; uint8_t
//@ 		push	es
//@ 		pop	ds
//@ 		mov	es, ax
//@ 		cld			; Clear	Direction Flag
//@ 		or	bl, bl		; Logical Inclusive OR
//@ 		jz	short loc_11710	; Jump if Zero (ZF=1)
//@ 
//@ loc_116FA:				; CODE XREF: sub_116B4+58j
//@ 		lodsb			; Load String
//@ 		mov	bl, al
//@ 
//@ loc_116FD:				; CODE XREF: sub_116B4+4Cj
//@ 		in	al, dx		; DMA controller, 8237A-5.
//@ 					; channel 3 current address
//@ 		test	al, 1		; Logical Compare
//@ 		jnz	short loc_116FD	; Jump if Not Zero (ZF=0)
//@ 		cli			; Clear	Interrupt Flag
//@ 
//@ loc_11703:				; CODE XREF: sub_116B4+52j
//@ 		in	al, dx		; DMA controller, 8237A-5.
//@ 					; channel 3 current address
//@ 		test	al, 1		; Logical Compare
//@ 		jz	short loc_11703	; Jump if Zero (ZF=1)
//@ 		mov	ax, bx
//@ 		stosw			; Store	String
//@ 		sti			; Set Interrupt	Flag
//@ 		loop	loc_116FA	; Loop while CX	!= 0
//@ 		jmp	short loc_11716	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11710:				; CODE XREF: sub_116B4+44j
//@ 		mov	ah, bh
//@ 
//@ loc_11712:				; CODE XREF: sub_116B4+60j
//@ 		lodsb			; Load String
//@ 		stosw			; Store	String
//@ 		loop	loc_11712	; Loop while CX	!= 0
//@ 
//@ loc_11716:				; CODE XREF: sub_116B4+5Aj
//@ 		pop	es
//@ 		pop	ds
//@ 		pop	di
//@ 		pop	dx
//@ 		pop	cx
//@ 
//@ locret_1171B:				; CODE XREF: sub_116B4+2j
//@ 		retn			; Return Near from Procedure
//@ sub_116B4	endp
//@ 
//@ ; [0000000B BYTES: COLLAPSED FUNCTION sub_1171C. PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000018 BYTES: COLLAPSED FUNCTION GetIntVec(Byte,Pointer &). PRESS KEYPAD "+" TO EXPAND]
//@ ; [00000013 BYTES: COLLAPSED FUNCTION SetIntVec(Byte,Pointer). PRESS KEYPAD "+"	TO EXPAND]
//@ ; [0000006E BYTES: COLLAPSED FUNCTION GetEnv(String). PRESS KEYPAD "+" TO EXPAND]
//@ ; [0000007B BYTES: COLLAPSED FUNCTION MsDos(Registers &). PRESS	KEYPAD "+" TO EXPAND]
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL string 'STRING' max FF
//@ ; Attributes: bp-based frame
//@ 
//@ HexW		proc far		; CODE XREF: PROGRAM+A13P HexL+DP ...
//@ 
//@ W		= byte ptr  6		; uint16_t
//@ arg_1		= byte ptr  7
//@ HexW		= dword	ptr  8		; char[256] // Pascal string
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ 		les	di, [bp+HexW]	; char[256] // Pascal string
//@ 		mov	byte ptr es:[di], 4
//@ 		mov	al, [bp+arg_1]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		mov	al, [di+36Ch]
//@ 		les	di, [bp+HexW]	; char[256] // Pascal string
//@ 		mov	es:[di+1], al
//@ 		mov	al, [bp+arg_1]
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+36Ch]
//@ 		les	di, [bp+HexW]	; char[256] // Pascal string
//@ 		mov	es:[di+2], al
//@ 		mov	al, [bp+W]	; uint16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	di, ax
//@ 		mov	al, [di+36Ch]
//@ 		les	di, [bp+HexW]	; char[256] // Pascal string
//@ 		mov	es:[di+3], al
//@ 		mov	al, [bp+W]	; uint16_t
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+36Ch]
//@ 		les	di, [bp+HexW]	; char[256] // Pascal string
//@ 		mov	es:[di+4], al
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ HexW		endp
//@ 
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL string 'STRING' max FF
//@ ; Attributes: bp-based frame
//@ 
//@ HexL		proc far		; CODE XREF: PROGRAM+924P
//@ 
//@ var_200		= byte ptr -200h
//@ var_100		= byte ptr -100h
//@ L		= word ptr  6		; int32_t
//@ arg_2		= word ptr  8
//@ HexL		= dword	ptr  0Ah	; char[256] // Pascal string
//@ 
//@ 		enter	200h, 0		; Make Stack Frame for Procedure Parameters
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	[bp+arg_2]
//@ 		call	HexW		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		push	[bp+L]		; int32_t
//@ 		call	HexW		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+HexL]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ HexL		endp
//@ 
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL string 'STRING' max FF
//@ ; Attributes: bp-based frame
//@ 
//@ Form		proc far		; CODE XREF: SyncroTime+AAP
//@ 					; EndPaint+332P ...
//@ 
//@ var_314		= byte ptr -314h
//@ var_216		= word ptr -216h
//@ I		= word ptr -214h	; uint16_t
//@ DigitPtr	= byte ptr -211h	; uint8_t
//@ Extras		= byte ptr -210h	; uint8_t
//@ FirstDigit	= byte ptr -20Fh	; uint8_t
//@ Blanks		= byte ptr -20Eh	; uint8_t
//@ Places		= byte ptr -20Dh	; uint8_t
//@ Digits		= byte ptr -20Ch	; uint8_t
//@ DotPos		= byte ptr -20Bh	; uint8_t
//@ EndF		= word ptr -20Ah	; uint16_t
//@ StartF		= word ptr -208h	; uint16_t
//@ Negative	= byte ptr -205h	; bool
//@ Dollar		= byte ptr -204h	; bool
//@ AddMinus	= byte ptr -203h	; bool
//@ WontFit		= byte ptr -202h	; bool
//@ Filler		= byte ptr -201h	; FillType
//@ S		= byte ptr -200h	; char[256] // Pascal string
//@ var_1FF		= byte ptr -1FFh
//@ Mask		= byte ptr -100h	; char[256] // Pascal string
//@ Asterisk	= byte ptr  0		; FillType
//@ Zero		= byte ptr  2		; FillType
//@ R		= word ptr  6		; real_t
//@ arg_2		= word ptr  8
//@ arg_4		= word ptr  0Ah
//@ arg_6		= dword	ptr  0Ch
//@ Form		= dword	ptr  10h	; char[256] // Pascal string
//@ 
//@ 		enter	314h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+Mask]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_6]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ 		cmp	[bp+Mask], 0	; char[256] // Pascal string
//@ 		jnz	short loc_118F6	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_11D18	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_118F6:				; CODE XREF: Form+20j
//@ 		mov	[bp+Filler], 0	; FillType
//@ 		mov	[bp+DotPos], 0	; uint8_t
//@ 		mov	[bp+Places], 0	; uint8_t
//@ 		mov	[bp+Digits], 0	; uint8_t
//@ 		mov	[bp+Dollar], 0	; bool
//@ 		mov	[bp+AddMinus], 1 ; bool
//@ 		mov	[bp+StartF], 1	; uint16_t
//@ 		mov	ax, [bp+R]	; real_t
//@ 		mov	bx, [bp+arg_2]
//@ 		mov	dx, [bp+arg_4]
//@ 		xor	cx, cx		; Logical Exclusive OR
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@__Cmp$q4Realt1	; Compare two reals
//@ 		mov	al, 0
//@ 		jnb	short loc_11933	; Jump if Not Below (CF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_11933:				; CODE XREF: Form+5Fj
//@ 		mov	[bp+Negative], al ; bool
//@ 		mov	ax, [bp+R]	; real_t
//@ 		mov	bx, [bp+arg_2]
//@ 		mov	dx, [bp+arg_4]
//@ 		and	dh, 7Fh		; Logical AND
//@ 		mov	[bp+R],	ax	; real_t
//@ 		mov	[bp+arg_2], bx
//@ 		mov	[bp+arg_4], dx
//@ 
//@ loc_1194C:				; CODE XREF: Form+ADj
//@ 		mov	al, [bp+Mask]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+StartF]	; uint16_t
//@ 		jb	short loc_11980	; Jump if Below	(CF=1)
//@ 		lea	di, [bp+var_314] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, [bp+StartF]	; uint16_t
//@ 		mov	al, [bp+di+Mask] ; char[256] //	Pascal string
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		mov	di, offset FormChars ; char[9] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_11980	; Jump if Not Zero (ZF=0)
//@ 		inc	[bp+StartF]	; uint16_t
//@ 		jmp	short loc_1194C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11980:				; CODE XREF: Form+85j Form+A7j
//@ 		mov	al, [bp+Mask]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+StartF]	; uint16_t
//@ 		jnb	short loc_1198F	; Jump if Not Below (CF=0)
//@ 		jmp	loc_11D18	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1198F:				; CODE XREF: Form+B9j
//@ 		mov	al, [bp+Mask]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_216], ax
//@ 		mov	ax, [bp+StartF]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		jbe	short loc_119A6	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_11A39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_119A6:				; CODE XREF: Form+D0j
//@ 		mov	[bp+EndF], ax	; uint16_t
//@ 		jmp	short loc_119B0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_119AC:				; CODE XREF: Form+165j
//@ 		inc	[bp+EndF]	; uint16_t
//@ 
//@ loc_119B0:				; CODE XREF: Form+D9j
//@ 		mov	di, [bp+EndF]	; uint16_t
//@ 		mov	al, [bp+di+Mask] ; char[256] //	Pascal string
//@ 		cmp	al, 2Ah	; '*'   ; Compare Two Operands
//@ 		jnz	short loc_119C3	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+Filler], 1	; FillType
//@ 		jmp	short loc_11A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_119C3:				; CODE XREF: Form+E9j
//@ 		cmp	al, 40h	; '@'   ; Compare Two Operands
//@ 		jnz	short loc_119CE	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+Filler], 2	; FillType
//@ 		jmp	short loc_11A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_119CE:				; CODE XREF: Form+F4j
//@ 		cmp	al, 24h	; '$'   ; Compare Two Operands
//@ 		jnz	short loc_119D9	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+Dollar], 1	; bool
//@ 		jmp	short loc_11A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_119D9:				; CODE XREF: Form+FFj
//@ 		cmp	al, 2Dh	; '-'   ; Compare Two Operands
//@ 		jz	short loc_119E1	; Jump if Zero (ZF=1)
//@ 		cmp	al, 2Bh	; '+'   ; Compare Two Operands
//@ 		jnz	short loc_119E8	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_119E1:				; CODE XREF: Form+10Aj
//@ 		mov	[bp+AddMinus], 0 ; bool
//@ 		jmp	short loc_11A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_119E8:				; CODE XREF: Form+10Ej
//@ 		cmp	al, 23h	; '#'   ; Compare Two Operands
//@ 		jnz	short loc_119EE	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_11A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_119EE:				; CODE XREF: Form+119j
//@ 		cmp	al, 2Ch	; ','   ; Compare Two Operands
//@ 		jnz	short loc_11A0C	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr [bp+EndF] ; uint16_t
//@ 		mov	[bp+DotPos], al	; uint8_t
//@ 		cmp	CommaForPeriod,	0 ; bool
//@ 		jz	short loc_11A0A	; Jump if Zero (ZF=1)
//@ 		mov	di, [bp+EndF]	; uint16_t
//@ 		mov	[bp+di+Mask], 2Eh ; '.' ; char[256] // Pascal string
//@ 
//@ loc_11A0A:				; CODE XREF: Form+12Ej
//@ 		jmp	short loc_11A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11A0C:				; CODE XREF: Form+11Fj
//@ 		cmp	al, 2Eh	; '.'   ; Compare Two Operands
//@ 		jnz	short loc_11A2A	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr [bp+EndF] ; uint16_t
//@ 		mov	[bp+DotPos], al	; uint8_t
//@ 		cmp	CommaForPeriod,	0 ; bool
//@ 		jz	short loc_11A28	; Jump if Zero (ZF=1)
//@ 		mov	di, [bp+EndF]	; uint16_t
//@ 		mov	[bp+di+Mask], 2Ch ; ',' ; char[256] // Pascal string
//@ 
//@ loc_11A28:				; CODE XREF: Form+14Cj
//@ 		jmp	short loc_11A2C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11A2A:				; CODE XREF: Form+13Dj
//@ 		jmp	short loc_11A3D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11A2C:				; CODE XREF: Form+F0j Form+FBj ...
//@ 		mov	ax, [bp+EndF]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		jz	short loc_11A39	; Jump if Zero (ZF=1)
//@ 		jmp	loc_119AC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11A39:				; CODE XREF: Form+D2j Form+163j
//@ 		inc	[bp+EndF]	; uint16_t
//@ 
//@ loc_11A3D:				; CODE XREF: Form:loc_11A2Aj
//@ 		dec	[bp+EndF]	; uint16_t
//@ 		cmp	[bp+Filler], 2	; FillType
//@ 		jnz	short loc_11A4D	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+Dollar], 0	; bool
//@ 
//@ loc_11A4D:				; CODE XREF: Form+175j
//@ 		mov	al, [bp+Dollar]	; bool
//@ 		mov	[bp+Extras], al	; uint8_t
//@ 		mov	ax, [bp+EndF]	; uint16_t
//@ 		mov	[bp+var_216], ax
//@ 		mov	ax, [bp+StartF]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		ja	short loc_11AAE	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+I],	ax	; uint16_t
//@ 		jmp	short loc_11A71	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11A6D:				; CODE XREF: Form+1DBj
//@ 		inc	[bp+I]		; uint16_t
//@ 
//@ loc_11A71:				; CODE XREF: Form+19Aj
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	al, [bp+di+Mask] ; char[256] //	Pascal string
//@ 		cmp	al, 23h	; '#'   ; Compare Two Operands
//@ 		jz	short loc_11A89	; Jump if Zero (ZF=1)
//@ 		cmp	al, 40h	; '@'   ; Compare Two Operands
//@ 		jz	short loc_11A89	; Jump if Zero (ZF=1)
//@ 		cmp	al, 2Ah	; '*'   ; Compare Two Operands
//@ 		jz	short loc_11A89	; Jump if Zero (ZF=1)
//@ 		cmp	al, 24h	; '$'   ; Compare Two Operands
//@ 		jnz	short loc_11AA4	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_11A89:				; CODE XREF: Form+1AAj	Form+1AEj ...
//@ 		inc	[bp+Digits]	; uint8_t
//@ 		mov	al, [bp+DotPos]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+I]	; uint16_t
//@ 		jnb	short loc_11AA4	; Jump if Not Below (CF=0)
//@ 		cmp	[bp+DotPos], 0	; uint8_t
//@ 		jz	short loc_11AA4	; Jump if Zero (ZF=1)
//@ 		inc	[bp+Places]	; uint8_t
//@ 
//@ loc_11AA4:				; CODE XREF: Form+1B6j	Form+1C6j ...
//@ 		mov	ax, [bp+I]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		jnz	short loc_11A6D	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_11AAE:				; CODE XREF: Form+194j
//@ 		cmp	[bp+Places], 0	; uint8_t
//@ 		mov	al, 0
//@ 		jbe	short loc_11AB8	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_11AB8:				; CODE XREF: Form+1E4j
//@ 		add	[bp+Digits], al	; uint8_t
//@ 		cmp	[bp+Negative], 0 ; bool
//@ 		jz	short loc_11AD7	; Jump if Zero (ZF=1)
//@ 		cmp	[bp+AddMinus], 0 ; bool
//@ 		jz	short loc_11AD7	; Jump if Zero (ZF=1)
//@ 		cmp	[bp+Filler], 0	; FillType
//@ 		jnz	short loc_11AD7	; Jump if Not Zero (ZF=0)
//@ 		inc	[bp+Extras]	; uint8_t
//@ 		jmp	short loc_11ADC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11AD7:				; CODE XREF: Form+1F0j	Form+1F7j ...
//@ 		mov	[bp+AddMinus], 0 ; bool
//@ 
//@ loc_11ADC:				; CODE XREF: Form+204j
//@ 		push	[bp+arg_4]
//@ 		push	[bp+arg_2]
//@ 		push	[bp+R]		; real_t
//@ 		mov	al, [bp+Digits]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, [bp+Places]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Str$q4Real4Wordt2m6String4Word	; Str(x:width:decimals;	var s: string {; strlen: Word})
//@ 		mov	[bp+Blanks], 1	; uint8_t
//@ 
//@ loc_11B06:				; CODE XREF: Form+248j
//@ 		mov	al, [bp+Blanks]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	[bp+di+S], 20h ; ' ' ; char[256] // Pascal string
//@ 		jnz	short loc_11B1B	; Jump if Not Zero (ZF=0)
//@ 		inc	[bp+Blanks]	; uint8_t
//@ 		jmp	short loc_11B06	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11B1B:				; CODE XREF: Form+242j
//@ 		mov	al, [bp+Blanks]	; uint8_t
//@ 		mov	[bp+FirstDigit], al ; uint8_t
//@ 		dec	[bp+Blanks]	; uint8_t
//@ 		mov	al, [bp+S]	; char[256] // Pascal string
//@ 		cmp	al, [bp+Digits]	; uint8_t
//@ 		ja	short loc_11B3F	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	al, [bp+Blanks]	; uint8_t
//@ 		cmp	al, [bp+Extras]	; uint8_t
//@ 		jb	short loc_11B3F	; Jump if Below	(CF=1)
//@ 		mov	al, 0
//@ 		jmp	short loc_11B41	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11B3F:				; CODE XREF: Form+25Ej	Form+268j
//@ 		mov	al, 1
//@ 
//@ loc_11B41:				; CODE XREF: Form+26Cj
//@ 		mov	[bp+WontFit], al ; bool
//@ 		cmp	[bp+WontFit], 0	; bool
//@ 		jz	short loc_11BC8	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+EndF]	; uint16_t
//@ 		mov	[bp+var_216], ax
//@ 		mov	ax, [bp+StartF]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		ja	short loc_11BC5	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+I],	ax	; uint16_t
//@ 		jmp	short loc_11B68	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11B64:				; CODE XREF: Form+2F2j
//@ 		inc	[bp+I]		; uint16_t
//@ 
//@ loc_11B68:				; CODE XREF: Form+291j
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	al, [bp+di+Mask] ; char[256] //	Pascal string
//@ 		cmp	al, 23h	; '#'   ; Compare Two Operands
//@ 		jz	short loc_11B80	; Jump if Zero (ZF=1)
//@ 		cmp	al, 40h	; '@'   ; Compare Two Operands
//@ 		jz	short loc_11B80	; Jump if Zero (ZF=1)
//@ 		cmp	al, 2Ah	; '*'   ; Compare Two Operands
//@ 		jz	short loc_11B80	; Jump if Zero (ZF=1)
//@ 		cmp	al, 24h	; '$'   ; Compare Two Operands
//@ 		jnz	short loc_11B8B	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_11B80:				; CODE XREF: Form+2A1j	Form+2A5j ...
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], 2Ah ; '*' ; char[256] // Pascal string
//@ 		jmp	short loc_11BBB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11B8B:				; CODE XREF: Form+2ADj
//@ 		cmp	al, 2Bh	; '+'   ; Compare Two Operands
//@ 		jnz	short loc_11BA4	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+Negative] ; bool
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	di, ax
//@ 		mov	al, [di+3A6h]
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], al ; char[256] //	Pascal string
//@ 		jmp	short loc_11BBB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11BA4:				; CODE XREF: Form+2BCj
//@ 		cmp	al, 2Dh	; '-'   ; Compare Two Operands
//@ 		jnz	short loc_11BBB	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+Negative] ; bool
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	di, ax
//@ 		mov	al, [di+3A8h]
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], al ; char[256] //	Pascal string
//@ 
//@ loc_11BBB:				; CODE XREF: Form+2B8j	Form+2D1j ...
//@ 		mov	ax, [bp+I]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		jnz	short loc_11B64	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_11BC5:				; CODE XREF: Form+28Bj
//@ 		jmp	loc_11D18	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11BC8:				; CODE XREF: Form+279j
//@ 		cmp	[bp+Blanks], 0	; uint8_t
//@ 		jbe	short loc_11C20	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		lea	di, [bp+var_1FF] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, [bp+Blanks]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, [bp+Filler]	; FillType
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	di, ax
//@ 		mov	al, [di+3AAh]
//@ 		push	ax
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ 		cmp	[bp+Dollar], 0	; bool
//@ 		jz	short loc_11C0C	; Jump if Zero (ZF=1)
//@ 		mov	dl, MoneySign	; char
//@ 		mov	al, [bp+Blanks]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	[bp+di+S], dl	; char[256] // Pascal string
//@ 		dec	[bp+Extras]	; uint8_t
//@ 		dec	[bp+Blanks]	; uint8_t
//@ 
//@ loc_11C0C:				; CODE XREF: Form+321j
//@ 		cmp	[bp+AddMinus], 0 ; bool
//@ 		jz	short loc_11C20	; Jump if Zero (ZF=1)
//@ 		mov	al, [bp+Blanks]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	[bp+di+S], 2Dh ; '-' ; char[256] // Pascal string
//@ 
//@ loc_11C20:				; CODE XREF: Form+2FCj	Form+340j
//@ 		mov	al, [bp+S]	; char[256] // Pascal string
//@ 		mov	[bp+DigitPtr], al ; uint8_t
//@ 		mov	ax, [bp+StartF]	; uint16_t
//@ 		mov	[bp+var_216], ax
//@ 		mov	ax, [bp+EndF]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		jnb	short loc_11C3D	; Jump if Not Below (CF=0)
//@ 		jmp	loc_11D18	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11C3D:				; CODE XREF: Form+367j
//@ 		mov	[bp+I],	ax	; uint16_t
//@ 		jmp	short loc_11C47	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11C43:				; CODE XREF: Form+444j
//@ 		dec	[bp+I]		; uint16_t
//@ 
//@ loc_11C47:				; CODE XREF: Form+370j	Form+405j
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	al, [bp+di+Mask] ; char[256] //	Pascal string
//@ 		cmp	al, 23h	; '#'   ; Compare Two Operands
//@ 		jz	short loc_11C5F	; Jump if Zero (ZF=1)
//@ 		cmp	al, 40h	; '@'   ; Compare Two Operands
//@ 		jz	short loc_11C5F	; Jump if Zero (ZF=1)
//@ 		cmp	al, 2Ah	; '*'   ; Compare Two Operands
//@ 		jz	short loc_11C5F	; Jump if Zero (ZF=1)
//@ 		cmp	al, 24h	; '$'   ; Compare Two Operands
//@ 		jnz	short loc_11CAF	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_11C5F:				; CODE XREF: Form+380j	Form+384j ...
//@ 		cmp	[bp+DigitPtr], 0 ; uint8_t
//@ 		jz	short loc_11C9A	; Jump if Zero (ZF=1)
//@ 		mov	al, [bp+DigitPtr] ; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [bp+di+S]	; char[256] // Pascal string
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], al ; char[256] //	Pascal string
//@ 		dec	[bp+DigitPtr]	; uint8_t
//@ 		mov	al, [bp+DigitPtr] ; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	[bp+di+S], 2Eh ; '.' ; char[256] // Pascal string
//@ 		jnz	short loc_11C98	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+DigitPtr], 0 ; uint8_t
//@ 		jz	short loc_11C98	; Jump if Zero (ZF=1)
//@ 		dec	[bp+DigitPtr]	; uint8_t
//@ 
//@ loc_11C98:				; CODE XREF: Form+3BAj	Form+3C1j
//@ 		jmp	short loc_11CAD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11C9A:				; CODE XREF: Form+393j
//@ 		mov	al, [bp+Filler]	; FillType
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	di, ax
//@ 		mov	al, [di+3AAh]
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], al ; char[256] //	Pascal string
//@ 
//@ loc_11CAD:				; CODE XREF: Form:loc_11C98j
//@ 		jmp	short loc_11D0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11CAF:				; CODE XREF: Form+38Cj
//@ 		cmp	al, 2Ch	; ','   ; Compare Two Operands
//@ 		jz	short loc_11CB7	; Jump if Zero (ZF=1)
//@ 		cmp	al, 2Eh	; '.'   ; Compare Two Operands
//@ 		jnz	short loc_11CDB	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_11CB7:				; CODE XREF: Form+3E0j
//@ 		mov	al, [bp+DotPos]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+I]	; uint16_t
//@ 		jbe	short loc_11CD9	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	al, [bp+DigitPtr] ; uint8_t
//@ 		cmp	al, [bp+FirstDigit] ; uint8_t
//@ 		jnb	short loc_11CD9	; Jump if Not Below (CF=0)
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], 23h ; '#' ; char[256] // Pascal string
//@ 		jmp	loc_11C47	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11CD9:				; CODE XREF: Form+3F0j	Form+3FAj
//@ 		jmp	short loc_11D0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11CDB:				; CODE XREF: Form+3E4j
//@ 		cmp	al, 2Bh	; '+'   ; Compare Two Operands
//@ 		jnz	short loc_11CF4	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+Negative] ; bool
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	di, ax
//@ 		mov	al, [di+3A6h]
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], al ; char[256] //	Pascal string
//@ 		jmp	short loc_11D0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11CF4:				; CODE XREF: Form+40Cj
//@ 		cmp	al, 2Dh	; '-'   ; Compare Two Operands
//@ 		jnz	short loc_11D0B	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+Negative] ; bool
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	di, ax
//@ 		mov	al, [di+3A8h]
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	[bp+di+Mask], al ; char[256] //	Pascal string
//@ 
//@ loc_11D0B:				; CODE XREF: Form:loc_11CADj
//@ 					; Form:loc_11CD9j ...
//@ 		mov	ax, [bp+I]	; uint16_t
//@ 		cmp	ax, [bp+var_216] ; Compare Two Operands
//@ 		jz	short loc_11D18	; Jump if Zero (ZF=1)
//@ 		jmp	loc_11C43	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11D18:				; CODE XREF: Form+22j Form+BBj ...
//@ 		lea	di, [bp+Mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+Form]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ Form		endp
//@ 
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL string 'STRING' max FF
//@ ; Attributes: bp-based frame
//@ 
//@ Trim		proc far		; CODE XREF: ExecConsole+43P
//@ 					; ExecConsole+12DP ...
//@ 
//@ I		= word ptr -102h	; uint16_t
//@ S		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ Trim		= dword	ptr  0Ah	; char[256] // Pascal string
//@ 
//@ 		enter	102h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ 
//@ loc_11D4A:				; CODE XREF: Trim+35j
//@ 		cmp	[bp+S],	0	; char[256] // Pascal string
//@ 		jbe	short loc_11D66	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	al, [bp+S]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	[bp+di+S], 20h ; ' ' ; char[256] // Pascal string
//@ 		ja	short loc_11D66	; Jump if Above	(CF=0 &	ZF=0)
//@ 		dec	[bp+S]		; char[256] // Pascal string
//@ 		jmp	short loc_11D4A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11D66:				; CODE XREF: Trim+20j Trim+2Fj
//@ 		mov	[bp+I],	1	; uint16_t
//@ 
//@ loc_11D6C:				; CODE XREF: Trim+58j
//@ 		mov	al, [bp+S]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+I]	; uint16_t
//@ 		jb	short loc_11D89	; Jump if Below	(CF=1)
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		cmp	[bp+di+S], 20h ; ' ' ; char[256] // Pascal string
//@ 		ja	short loc_11D89	; Jump if Above	(CF=0 &	ZF=0)
//@ 		inc	[bp+I]		; uint16_t
//@ 		jmp	short loc_11D6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11D89:				; CODE XREF: Trim+47j Trim+52j
//@ 		dec	[bp+I]		; uint16_t
//@ 		cmp	[bp+I],	0	; uint16_t
//@ 		jbe	short loc_11DA5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		push	[bp+I]		; uint16_t
//@ 		call	@Delete$qm6String7Integert2 ; Delete(var s: String; index: Integer; count: Integer)
//@ 
//@ loc_11DA5:				; CODE XREF: Trim+63j
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+Trim]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ Trim		endp
//@ 
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL string 'STRING' max FF
//@ ; Attributes: bp-based frame
//@ 
//@ JustFilename	proc far		; CODE XREF: FOpen+137P TOpen+112P ...
//@ 
//@ var_202		= byte ptr -202h
//@ I		= word ptr -102h	; uint16_t
//@ PathName	= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ JustFilename	= dword	ptr  0Ah	; char[256] // Pascal string
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+PathName] ; char[256] // Pascal	string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ 		mov	al, [bp+PathName] ; char[256] // Pascal	string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+I],	ax	; uint16_t
//@ 
//@ loc_11DE2:				; CODE XREF: JustFilename+49j
//@ 		dec	[bp+I]		; uint16_t
//@ 		mov	di, [bp+I]	; uint16_t
//@ 		mov	al, [bp+di+PathName] ; char[256] // Pascal string
//@ 		mov	ah, 1
//@ 		mov	dx, 20h	; ' '
//@ 		call	@Set@GetElemOffset$q4Wordt1 ; Compute Set offset and bitmask
//@ 					; AL - Element number
//@ 					; AH - mask
//@ 					; DX - Set params
//@ 		mov	di, dx
//@ 		test	[di+37Ch], al	; Logical Compare
//@ 		jnz	short loc_11E07	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+I],	0	; uint16_t
//@ 		jnz	short loc_11DE2	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_11E07:				; CODE XREF: JustFilename+42j
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+PathName] ; char[256] // Pascal	string
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+I]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	40h ; '@'
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		les	di, [bp+JustFilename] ;	char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ JustFilename	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		db  9Ah	; ö
//@ 		db  90h	; ê
//@ 		db  41h	; A
//@ 		db  8Eh	; é
//@ 		db  41h	; A
//@ 		db  8Fh	; è
//@ 		db  80h	; Ä
//@ 		db  45h	; E
//@ 		db  45h	; E
//@ 		db  45h	; E
//@ 		db  49h	; I
//@ 		db  49h	; I
//@ 		db  49h	; I
//@ 		db  8Eh	; é
//@ 		db  8Fh	; è
//@ 		db  90h	; ê
//@ 		db  92h	; í
//@ 		db  92h	; í
//@ 		db  4Fh	; O
//@ 		db  99h	; ô
//@ 		db  4Fh	; O
//@ 		db  55h	; U
//@ 		db  55h	; U
//@ 		db  59h	; Y
//@ 		db  99h	; ô
//@ 		db  9Ah	; ö
//@ 		db  9Bh	; õ
//@ 		db  9Ch	; ú
//@ 		db  9Dh	; ù
//@ 		db  9Eh	; û
//@ 		db  9Fh	; ü
//@ 		db  41h	; A
//@ 		db  49h	; I
//@ 		db  4Fh	; O
//@ 		db  55h	; U
//@ 		db 0A5h	; •
//@ 		db 0A5h	; •
//@ 		db  41h	; A
//@ 		db  4Fh	; O
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ UpCasePrim	proc far		; CODE XREF: Upcase+6P	StUpcase-9p
//@ 		cmp	al, 61h	; 'a'   ; Compare Two Operands
//@ 		jb	short locret_11E66 ; Jump if Below (CF=1)
//@ 		cmp	al, 0A7h ; 'ß'  ; Compare Two Operands
//@ 		ja	short locret_11E66 ; Jump if Above (CF=0 & ZF=0)
//@ 		cmp	al, 7Ah	; 'z'   ; Compare Two Operands
//@ 		ja	short loc_11E67	; Jump if Above	(CF=0 &	ZF=0)
//@ 		sub	al, 20h	; ' '   ; Integer Subtraction
//@ 
//@ locret_11E66:				; CODE XREF: UpCasePrim+2j
//@ 					; UpCasePrim+6j ...
//@ 		retf			; Return Far from Procedure
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11E67:				; CODE XREF: UpCasePrim+Aj
//@ 		cmp	al, 81h	; 'Å'   ; Compare Two Operands
//@ 		jb	short locret_11E66 ; Jump if Below (CF=1)
//@ 		sub	al, 81h	; 'Å'   ; Integer Subtraction
//@ 		mov	bx, 2E01h
//@ 		xlat	byte ptr cs:[bx] ; Table Lookup	Translation
//@ 		retf			; Return Far from Procedure
//@ UpCasePrim	endp
//@ 
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL character 'Char'
//@ 
//@ Upcase		proc far
//@ 		mov	bx, sp
//@ 		mov	al, ss:[bx+4]
//@ 		call	UpCasePrim	; function far PASCAL returns void
//@ 		retf	2		; Return Far from Procedure
//@ Upcase		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		db  87h	; á
//@ 		db  81h	; Å
//@ 		db  82h	; Ç
//@ 		db  83h	; É
//@ 		db  84h	; Ñ
//@ 		db  85h	; Ö
//@ 		db  86h	; Ü
//@ 		db  87h	; á
//@ 		db  88h	; à
//@ 		db  89h	; â
//@ 		db  8Ah	; ä
//@ 		db  8Bh	; ã
//@ 		db  8Ch	; å
//@ 		db  8Dh	; ç
//@ 		db  84h	; Ñ
//@ 		db  86h	; Ü
//@ 		db  82h	; Ç
//@ 		db  91h	; ë
//@ 		db  91h	; ë
//@ 		db  93h	; ì
//@ 		db  94h	; î
//@ 		db  95h	; ï
//@ 		db  96h	; ñ
//@ 		db  97h	; ó
//@ 		db  98h	; ò
//@ 		db  94h	; î
//@ 		db  81h	; Å
//@ 		db  9Bh	; õ
//@ 		db  9Ch	; ú
//@ 		db  9Dh	; ù
//@ 		db  9Eh	; û
//@ 		db  9Fh	; ü
//@ 		db 0A0h	; †
//@ 		db 0A1h	; °
//@ 		db 0A2h	; ¢
//@ 		db 0A3h	; £
//@ 		db 0A4h	; §
//@ 		db 0A4h	; §
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ LoCasePrim	proc far		; CODE XREF: LoCase+6P
//@ 		cmp	al, 41h	; 'A'   ; Compare Two Operands
//@ 		jb	short locret_11EB5 ; Jump if Below (CF=1)
//@ 		cmp	al, 0A5h ; '•'  ; Compare Two Operands
//@ 		ja	short locret_11EB5 ; Jump if Above (CF=0 & ZF=0)
//@ 		cmp	al, 5Ah	; 'Z'   ; Compare Two Operands
//@ 		ja	short loc_11EB6	; Jump if Above	(CF=0 &	ZF=0)
//@ 		add	al, 20h	; ' '   ; Add
//@ 
//@ locret_11EB5:				; CODE XREF: LoCasePrim+2j
//@ 					; LoCasePrim+6j ...
//@ 		retf			; Return Far from Procedure
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11EB6:				; CODE XREF: LoCasePrim+Aj
//@ 		cmp	al, 80h	; 'Ä'   ; Compare Two Operands
//@ 		jb	short locret_11EB5 ; Jump if Below (CF=1)
//@ 		sub	al, 80h	; 'Ä'   ; Integer Subtraction
//@ 		mov	bx, 2E51h
//@ 		xlat	byte ptr cs:[bx] ; Table Lookup	Translation
//@ 		retf			; Return Far from Procedure
//@ LoCasePrim	endp
//@ 
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL character 'Char'
//@ 
//@ LoCase		proc far		; CODE XREF: ReadCommand+51P
//@ 					; ReadCommand$0+1FP
//@ 		mov	bx, sp
//@ 		mov	al, ss:[bx+4]
//@ 		call	LoCasePrim	; function far PASCAL returns void
//@ 		retf	2		; Return Far from Procedure
//@ LoCase		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ ; START	OF FUNCTION CHUNK FOR StUpcase
//@ 
//@ loc_11ED0:				; CODE XREF: StUpcase+3j StLocase+3j
//@ 		mov	bx, sp
//@ 		push	ds
//@ 		cld			; Clear	Direction Flag
//@ 		lds	si, ss:[bx+4]	; Load Full Pointer to DS:xx
//@ 		les	di, ss:[bx+8]	; Load Full Pointer to ES:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		mov	cl, al
//@ 		jcxz	short loc_11EEB	; Jump if CX is	0
//@ 
//@ loc_11EE4:				; CODE XREF: StUpcase-6j
//@ 		lodsb			; Load String
//@ 		push	cs
//@ 		call	dx ; UpCasePrim	; function far PASCAL returns void
//@ 		stosb			; Store	String
//@ 		loop	loc_11EE4	; Loop while CX	!= 0
//@ 
//@ loc_11EEB:				; CODE XREF: StUpcase-Dj
//@ 		pop	ds
//@ 		retf	4		; Return Far from Procedure
//@ ; END OF FUNCTION CHUNK	FOR StUpcase
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 
//@ StUpcase	proc far		; CODE XREF: ExecConsole+48P
//@ 					; FOpen+13CP ...
//@ 
//@ ; FUNCTION CHUNK AT 2EA0 SIZE 0000001F BYTES
//@ 
//@ 		mov	dx, 2E28h
//@ 		jmp	short loc_11ED0	; Jump
//@ StUpcase	endp ; sp-analysis failed
//@ 
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 
//@ StLocase	proc far		; CODE XREF: PROGRAM+299P PROGRAM+69CP ...
//@ 		mov	dx, 2E77h
//@ 		jmp	short loc_11ED0	; Jump
//@ StLocase	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		align 8
