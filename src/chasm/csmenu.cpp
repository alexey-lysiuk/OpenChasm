
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

#include "csmenu.h"

#include "cspbio.h"


TMenuText PM;


//@ ; #line	"CSMENU.PAS" 69
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CreateRecolorMap proc far		; CODE XREF: Draw3DObject+5FDP
//@ 					; UpDateMenu+D29P
//@ 
//@ Index		= word ptr  6		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSMENU.PAS" 70
//@ 		mov	di, [bp+Index]	; int16_t
//@ 		mov	al, [di+28Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+Index], ax	; int16_t
//@ ; #line	"CSMENU.PAS" 71
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_27FAC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_27FA8:				; CODE XREF: CreateRecolorMap+33j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSMENU.PAS" 72
//@ 
//@ loc_27FAC:				; CODE XREF: CreateRecolorMap+14j
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, [bp+Index]	; int16_t
//@ 		mov	dl, al
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 0E0h ; 'à'  ; Add
//@ 		mov	di, ax
//@ 		mov	[di+1358h], dl
//@ 		cmp	n$0, 0Fh	; int16_t
//@ 		jnz	short loc_27FA8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 73
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ CreateRecolorMap endp
//@ 
//@ ; #line	"CSMENU.PAS" 80
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutIcon		proc near		; CODE XREF: PutIconD+55p
//@ 					; UpDateMenu+1EFp ...
//@ 
//@ AOFS		= word ptr -4		; uint16_t
//@ ASEG		= word ptr -2		; uint16_t
//@ A		= dword	ptr  4
//@ Shift		= byte ptr  8		; uint8_t
//@ VS		= word ptr  0Ah		; uint16_t
//@ h		= word ptr  0Ch		; uint16_t
//@ w		= word ptr  0Eh		; uint16_t
//@ y0		= word ptr  10h		; uint16_t
//@ x0		= word ptr  12h		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 81
//@ 		les	di, [bp+A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+ASEG], ax	; uint16_t
//@ 		mov	ax, di
//@ 		mov	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 83
//@ 		mov	cx, 0
//@ 		mov	ax, [bp+VS]	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSMENU.PAS" 85
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ 		mov	di, [bp+y0]	; uint16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	bx, [bp+x0]	; uint16_t
//@ ; #line	"CSMENU.PAS" 86
//@ 		add	ebx, [di-6E84h]	; Add
//@ ; #line	"CSMENU.PAS" 89
//@ 
//@ loc_27FF5:				; CODE XREF: PutIcon+60j
//@ 		push	cx
//@ ; #line	"CSMENU.PAS" 90
//@ 		mov	si, [bp+AOFS]	; uint16_t
//@ ; #line	"CSMENU.PAS" 91
//@ 		mov	cx, [bp+w]	; uint16_t
//@ ; #line	"CSMENU.PAS" 92
//@ 		push	ebx
//@ ; #line	"CSMENU.PAS" 93
//@ 		push	ds
//@ 		mov	ax, [bp+ASEG]	; uint16_t
//@ 		mov	ds, ax
//@ ; #line	"CSMENU.PAS" 94
//@ 		mov	ah, [bp+Shift]	; uint8_t
//@ ; #line	"CSMENU.PAS" 96
//@ 
//@ loc_28007:				; CODE XREF: PutIcon+4Bj
//@ 		mov	al, [si]
//@ ; #line	"CSMENU.PAS" 97
//@ 		cmp	al, 0		; Compare Two Operands
//@ ; #line	"CSMENU.PAS" 98
//@ 		jz	short loc_28013	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 99
//@ 		add	al, ah		; Add
//@ ; #line	"CSMENU.PAS" 100
//@ 		mov	es:[ebx], al
//@ ; #line	"CSMENU.PAS" 101
//@ 
//@ loc_28013:				; CODE XREF: PutIcon+40j
//@ 		inc	si		; Increment by 1
//@ ; #line	"CSMENU.PAS" 102
//@ 		inc	ebx		; Increment by 1
//@ ; #line	"CSMENU.PAS" 103
//@ 		loop	loc_28007	; Loop while CX	!= 0
//@ ; #line	"CSMENU.PAS" 105
//@ 		pop	ds
//@ ; #line	"CSMENU.PAS" 106
//@ 		pop	ebx
//@ ; #line	"CSMENU.PAS" 107
//@ 		add	ebx, VideoBPL	; int32_t
//@ ; #line	"CSMENU.PAS" 108
//@ 		pop	cx
//@ ; #line	"CSMENU.PAS" 109
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		add	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 110
//@ 		inc	cx		; Increment by 1
//@ 		cmp	cx, [bp+h]	; uint16_t
//@ 		jb	short loc_27FF5	; Jump if Below	(CF=1)
//@ ; #line	"CSMENU.PAS" 112
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ PutIcon		endp
//@ 
//@ ; #line	"CSMENU.PAS" 118
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutIconDark	proc near		; CODE XREF: PutIconD+1Fp PutIconD+3Cp
//@ 
//@ AOFS		= word ptr -4		; uint16_t
//@ ASEG		= word ptr -2		; uint16_t
//@ A		= dword	ptr  4
//@ Dark		= word ptr  8		; uint16_t
//@ VS		= word ptr  0Ah		; uint16_t
//@ h		= word ptr  0Ch		; uint16_t
//@ w		= word ptr  0Eh		; uint16_t
//@ y0		= word ptr  10h		; uint16_t
//@ x0		= word ptr  12h		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 119
//@ 		les	di, [bp+A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+ASEG], ax	; uint16_t
//@ 		mov	ax, di
//@ 		mov	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 121
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, [bp+x0]	; uint16_t
//@ 		mov	bx, [bp+y0]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSMENU.PAS" 122
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSMENU.PAS" 124
//@ 		mov	cx, 0
//@ 		mov	ax, [bp+VS]	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSMENU.PAS" 125
//@ 		mov	bx, 1AC6h
//@ 		mov	ax, [bp+Dark]	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	bx, ax		; Add
//@ ; #line	"CSMENU.PAS" 126
//@ 		mov	ax, [bp+ASEG]	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CSMENU.PAS" 128
//@ 
//@ loc_2806B:				; CODE XREF: PutIconDark+6Aj
//@ 		push	cx
//@ ; #line	"CSMENU.PAS" 129
//@ 		mov	si, [bp+AOFS]	; uint16_t
//@ ; #line	"CSMENU.PAS" 130
//@ 		mov	cx, [bp+w]	; uint16_t
//@ ; #line	"CSMENU.PAS" 131
//@ 		push	edi
//@ ; #line	"CSMENU.PAS" 134
//@ 
//@ loc_28074:				; CODE XREF: PutIconDark+56j
//@ 		mov	al, fs:[si]
//@ ; #line	"CSMENU.PAS" 135
//@ 		cmp	al, 0		; Compare Two Operands
//@ ; #line	"CSMENU.PAS" 136
//@ 		jz	short loc_28084	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 138
//@ 		mov	al, es:[edi]
//@ ; #line	"CSMENU.PAS" 139
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSMENU.PAS" 141
//@ 		mov	es:[edi], al
//@ ; #line	"CSMENU.PAS" 142
//@ 
//@ loc_28084:				; CODE XREF: PutIconDark+48j
//@ 		inc	si		; Increment by 1
//@ ; #line	"CSMENU.PAS" 143
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSMENU.PAS" 144
//@ 		loop	loc_28074	; Loop while CX	!= 0
//@ ; #line	"CSMENU.PAS" 147
//@ 		pop	edi
//@ ; #line	"CSMENU.PAS" 148
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CSMENU.PAS" 149
//@ 		pop	cx
//@ ; #line	"CSMENU.PAS" 150
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		add	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 151
//@ 		inc	cx		; Increment by 1
//@ 		cmp	cx, [bp+h]	; uint16_t
//@ 		jb	short loc_2806B	; Jump if Below	(CF=1)
//@ ; #line	"CSMENU.PAS" 153
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ PutIconDark	endp
//@ 
//@ ; #line	"CSMENU.PAS" 158
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutIconRecolor	proc near		; CODE XREF: UpDateMenu+D41p
//@ 
//@ AOFS		= word ptr -4		; uint16_t
//@ ASEG		= word ptr -2		; uint16_t
//@ A		= dword	ptr  4
//@ h		= word ptr  8		; uint16_t
//@ w		= word ptr  0Ah		; uint16_t
//@ y0		= word ptr  0Ch		; uint16_t
//@ x0		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 159
//@ 		les	di, [bp+A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+ASEG], ax	; uint16_t
//@ 		mov	ax, di
//@ 		mov	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 161
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, [bp+x0]	; uint16_t
//@ 		mov	bx, [bp+y0]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSMENU.PAS" 162
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSMENU.PAS" 164
//@ 		mov	cx, 0
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSMENU.PAS" 165
//@ 		mov	bx, 1358h
//@ ; #line	"CSMENU.PAS" 166
//@ 		mov	ax, [bp+ASEG]	; uint16_t
//@ 		mov	fs, ax
//@ ; #line	"CSMENU.PAS" 168
//@ 
//@ loc_280D3:				; CODE XREF: PutIconRecolor+5Ej
//@ 		push	cx
//@ ; #line	"CSMENU.PAS" 169
//@ 		mov	si, [bp+AOFS]	; uint16_t
//@ ; #line	"CSMENU.PAS" 170
//@ 		mov	cx, [bp+w]	; uint16_t
//@ ; #line	"CSMENU.PAS" 171
//@ 		push	edi
//@ ; #line	"CSMENU.PAS" 174
//@ 
//@ loc_280DC:				; CODE XREF: PutIconRecolor+4Aj
//@ 		mov	al, fs:[si]
//@ ; #line	"CSMENU.PAS" 175
//@ 		cmp	al, 0		; Compare Two Operands
//@ ; #line	"CSMENU.PAS" 176
//@ 		jz	short loc_280E8	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 179
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSMENU.PAS" 181
//@ 		mov	es:[edi], al
//@ ; #line	"CSMENU.PAS" 182
//@ 
//@ loc_280E8:				; CODE XREF: PutIconRecolor+40j
//@ 		inc	si		; Increment by 1
//@ ; #line	"CSMENU.PAS" 183
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSMENU.PAS" 184
//@ 		loop	loc_280DC	; Loop while CX	!= 0
//@ ; #line	"CSMENU.PAS" 187
//@ 		pop	edi
//@ ; #line	"CSMENU.PAS" 188
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CSMENU.PAS" 189
//@ 		pop	cx
//@ ; #line	"CSMENU.PAS" 190
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		add	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 191
//@ 		inc	cx		; Increment by 1
//@ 		cmp	cx, [bp+h]	; uint16_t
//@ 		jb	short loc_280D3	; Jump if Below	(CF=1)
//@ ; #line	"CSMENU.PAS" 193
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ch		; Return Near from Procedure
//@ PutIconRecolor	endp
//@ 
//@ ; #line	"CSMENU.PAS" 200
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutIconFF2Sub	proc near		; CODE XREF: PutString+E9p
//@ 					; PutStringFloat+BAp ...
//@ 
//@ AOFS		= word ptr -4		; uint16_t
//@ ASEG		= word ptr -2		; uint16_t
//@ A		= dword	ptr  4
//@ VS		= word ptr  8		; uint16_t
//@ W0		= word ptr  0Ah		; uint16_t
//@ h		= word ptr  0Ch		; uint16_t
//@ w		= word ptr  0Eh		; uint16_t
//@ y0		= word ptr  10h		; uint16_t
//@ x0		= word ptr  12h		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 201
//@ 		les	di, [bp+A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+ASEG], ax	; uint16_t
//@ 		mov	ax, di
//@ 		mov	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 203
//@ 		mov	cx, 0
//@ 		mov	ax, [bp+VS]	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSMENU.PAS" 204
//@ 		mov	dl, ColorShift	; uint8_t
//@ ; #line	"CSMENU.PAS" 205
//@ 		mov	dh, ColorZero	; uint8_t
//@ ; #line	"CSMENU.PAS" 207
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ 		mov	di, [bp+y0]	; uint16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	bx, [bp+x0]	; uint16_t
//@ ; #line	"CSMENU.PAS" 208
//@ 		add	ebx, [di-6E84h]	; Add
//@ ; #line	"CSMENU.PAS" 210
//@ 
//@ loc_28137:				; CODE XREF: PutIconFF2Sub+69j
//@ 		push	cx
//@ ; #line	"CSMENU.PAS" 211
//@ 		mov	si, [bp+AOFS]	; uint16_t
//@ ; #line	"CSMENU.PAS" 212
//@ 		mov	cx, [bp+w]	; uint16_t
//@ ; #line	"CSMENU.PAS" 213
//@ 		push	ebx
//@ ; #line	"CSMENU.PAS" 214
//@ 		push	ds
//@ 		mov	ax, [bp+ASEG]	; uint16_t
//@ 		mov	ds, ax
//@ ; #line	"CSMENU.PAS" 216
//@ 
//@ loc_28146:				; CODE XREF: PutIconFF2Sub+54j
//@ 		mov	al, [si]
//@ ; #line	"CSMENU.PAS" 217
//@ 		cmp	al, 0FFh	; Compare Two Operands
//@ 		jz	short loc_28156	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 218
//@ 		cmp	al, dh		; Compare Two Operands
//@ 		jz	short loc_28152	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 219
//@ 		add	ax, dx		; Add
//@ ; #line	"CSMENU.PAS" 220
//@ 
//@ loc_28152:				; CODE XREF: PutIconFF2Sub+49j
//@ 		mov	es:[ebx], al
//@ ; #line	"CSMENU.PAS" 221
//@ 
//@ loc_28156:				; CODE XREF: PutIconFF2Sub+45j
//@ 		inc	si		; Increment by 1
//@ ; #line	"CSMENU.PAS" 222
//@ 		inc	ebx		; Increment by 1
//@ ; #line	"CSMENU.PAS" 223
//@ 		loop	loc_28146	; Loop while CX	!= 0
//@ ; #line	"CSMENU.PAS" 225
//@ 		pop	ds
//@ ; #line	"CSMENU.PAS" 226
//@ 		pop	ebx
//@ 		pop	cx
//@ ; #line	"CSMENU.PAS" 227
//@ 		add	ebx, VideoBPL	; int32_t
//@ ; #line	"CSMENU.PAS" 228
//@ 		mov	ax, [bp+W0]	; uint16_t
//@ 		add	[bp+AOFS], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 229
//@ 		inc	cx		; Increment by 1
//@ 		cmp	cx, [bp+h]	; uint16_t
//@ 		jb	short loc_28137	; Jump if Below	(CF=1)
//@ ; #line	"CSMENU.PAS" 231
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ PutIconFF2Sub	endp
//@ 
//@ ; #line	"CSMENU.PAS" 236
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutIconD	proc near		; CODE XREF: UpDateMenu+1A8p
//@ 					; UpDateMenu+2CFp ...
//@ 
//@ A		= dword	ptr  4
//@ VS		= word ptr  8		; uint16_t
//@ h		= word ptr  0Ah		; uint16_t
//@ w		= word ptr  0Ch		; uint16_t
//@ y0		= word ptr  0Eh		; uint16_t
//@ x0		= word ptr  10h		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSMENU.PAS" 237
//@ 		mov	ax, [bp+x0]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, [bp+y0]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		push	[bp+w]		; uint16_t
//@ 		push	[bp+h]		; uint16_t
//@ 		push	[bp+VS]		; uint16_t
//@ 		push	14h
//@ 		les	di, [bp+A]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconDark	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 238
//@ 		mov	ax, [bp+x0]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, [bp+y0]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		push	[bp+w]		; uint16_t
//@ 		push	[bp+h]		; uint16_t
//@ 		push	[bp+VS]		; uint16_t
//@ 		push	28h ; '('
//@ 		les	di, [bp+A]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconDark	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 239
//@ 		push	[bp+x0]		; uint16_t
//@ 		push	[bp+y0]		; uint16_t
//@ 		push	[bp+w]		; uint16_t
//@ 		push	[bp+h]		; uint16_t
//@ 		push	[bp+VS]		; uint16_t
//@ 		push	0
//@ 		les	di, [bp+A]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		call	PutIcon		; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 240
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Eh		; Return Near from Procedure
//@ PutIconD	endp
//@ 
//@ ; #line	"CSMENU.PAS" 245
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutString	proc far		; CODE XREF: UpDateConsole+112P
//@ 					; UpDateConsole+1B7P ...
//@ 
//@ var_108		= word ptr -108h
//@ yf		= word ptr -106h	; uint16_t
//@ xf		= word ptr -104h	; uint16_t
//@ n		= word ptr -102h	; uint16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ Green		= byte ptr  6		; bool
//@ arg_2		= dword	ptr  8
//@ y		= word ptr  0Ch		; uint16_t
//@ x		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	108h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSMENU.PAS" 246
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, 5		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, word ptr VideoH+2 ;	int32_t
//@ 		jg	short loc_28201	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_28204	; Jump if Less (SF!=OF)
//@ 		cmp	ax, word ptr VideoH ; int32_t
//@ 		jbe	short loc_28204	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_28201:				; CODE XREF: PutString+27j
//@ 		jmp	locret_282F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 247
//@ 
//@ loc_28204:				; CODE XREF: PutString+29j
//@ 					; PutString+2Fj
//@ 		cmp	[bp+Green], 0	; bool
//@ 		jz	short loc_28211	; Jump if Zero (ZF=1)
//@ 		cmp	Console, 0	; bool
//@ 		jnz	short loc_28215	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_28211:				; CODE XREF: PutString+38j
//@ 		mov	al, 0
//@ 		jmp	short loc_28217	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28215:				; CODE XREF: PutString+3Fj
//@ 		mov	al, 1
//@ 
//@ loc_28217:				; CODE XREF: PutString+43j
//@ 		mov	[bp+Green], al	; bool
//@ ; #line	"CSMENU.PAS" 248
//@ 		cmp	[bp+Green], 0	; bool
//@ 		jz	short loc_28227	; Jump if Zero (ZF=1)
//@ 		mov	ColorShift, 22h	; '"' ; uint8_t
//@ 		jmp	short loc_2822C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28227:				; CODE XREF: PutString+4Ej
//@ 		mov	ColorShift, 2	; uint8_t
//@ ; #line	"CSMENU.PAS" 249
//@ 
//@ loc_2822C:				; CODE XREF: PutString+55j
//@ 		cmp	[bp+Green], 0	; bool
//@ 		jz	short loc_28239	; Jump if Zero (ZF=1)
//@ 		mov	ColorZero, 0	; uint8_t
//@ 		jmp	short loc_2823E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28239:				; CODE XREF: PutString+60j
//@ 		mov	ColorZero, 0FFh	; uint8_t
//@ ; #line	"CSMENU.PAS" 250
//@ 
//@ loc_2823E:				; CODE XREF: PutString+67j
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_108], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jbe	short loc_28254	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_282F1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28254:				; CODE XREF: PutString+7Fj
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2825E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2825A:				; CODE XREF: PutString+11Ej
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSMENU.PAS" 251
//@ 
//@ loc_2825E:				; CODE XREF: PutString+88j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		cmp	[bp+di+s], 20h ; ' ' ; char[256] // Pascal string
//@ 		jz	short loc_282E0	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 253
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+xf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 254
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+yf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 255
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		push	9
//@ 		push	7
//@ 		push	100h
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+xf]	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+yf], 0A00h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, 200h	; Add
//@ 		les	di, Fonts	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconFF2Sub	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 256
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-1DA0h]
//@ 		add	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 257
//@ 		mov	ax, WinEX	; uint16_t
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		cmp	ax, [bp+x]	; uint16_t
//@ 		jnb	short loc_282DE	; Jump if Not Below (CF=0)
//@ 		jmp	short locret_282F1 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 258
//@ 
//@ loc_282DE:				; CODE XREF: PutString+10Aj
//@ 		jmp	short loc_282E4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_282E0:				; CODE XREF: PutString+97j
//@ 		add	[bp+x],	4	; uint16_t
//@ 
//@ loc_282E4:				; CODE XREF: PutString:loc_282DEj
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jz	short locret_282F1 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2825A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 259
//@ 
//@ locret_282F1:				; CODE XREF: PutString:loc_28201j
//@ 					; PutString+81j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ PutString	endp
//@ 
//@ ; #line	"CSMENU.PAS" 264
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutStringFloat	proc far		; CODE XREF: UpDateRanking+F4P
//@ 					; UpDateRanking+127P ...
//@ 
//@ var_108		= word ptr -108h
//@ yf		= word ptr -106h	; uint16_t
//@ xf		= word ptr -104h	; uint16_t
//@ n		= word ptr -102h	; uint16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ CSh		= byte ptr  0Ah		; uint16_t
//@ y		= word ptr  0Ch		; uint16_t
//@ x		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	108h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSMENU.PAS" 265
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, 5		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, word ptr VideoH+2 ;	int32_t
//@ 		jg	short loc_28326	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_28329	; Jump if Less (SF!=OF)
//@ 		cmp	ax, word ptr VideoH ; int32_t
//@ 		jbe	short loc_28329	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_28326:				; CODE XREF: PutStringFloat+27j
//@ 		jmp	locret_283DA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 266
//@ 
//@ loc_28329:				; CODE XREF: PutStringFloat+29j
//@ 					; PutStringFloat+2Fj
//@ 		mov	al, [bp+CSh]	; uint16_t
//@ 		mov	ColorShift, al	; uint8_t
//@ 		mov	ColorZero, 0	; uint8_t
//@ ; #line	"CSMENU.PAS" 267
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_108], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jbe	short loc_2834A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_283DA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2834A:				; CODE XREF: PutStringFloat+50j
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_28354	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28350:				; CODE XREF: PutStringFloat+E2j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSMENU.PAS" 268
//@ 
//@ loc_28354:				; CODE XREF: PutStringFloat+59j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		cmp	[bp+di+s], 20h ; ' ' ; char[256] // Pascal string
//@ 		jz	short loc_283C9	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 270
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+xf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 271
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+yf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 272
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		push	9
//@ 		push	7
//@ 		push	100h
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+xf]	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+yf], 0A00h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, 200h	; Add
//@ 		les	di, Fonts	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconFF2Sub	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 273
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-1DA0h]
//@ 		add	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 274
//@ 		jmp	short loc_283CD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_283C9:				; CODE XREF: PutStringFloat+68j
//@ 		add	[bp+x],	4	; uint16_t
//@ 
//@ loc_283CD:				; CODE XREF: PutStringFloat+D2j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jz	short locret_283DA ; Jump if Zero (ZF=1)
//@ 		jmp	loc_28350	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 275
//@ 
//@ locret_283DA:				; CODE XREF: PutStringFloat:loc_28326j
//@ 					; PutStringFloat+52j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ PutStringFloat	endp
//@ 
//@ ; #line	"CSMENU.PAS" 281
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutChar		proc far		; CODE XREF: UpDateInfo+346P
//@ 					; PutScroller+22P ...
//@ 
//@ yf		= word ptr -6		; uint16_t
//@ xf		= word ptr -4		; uint16_t
//@ c		= byte ptr  6		; char
//@ y		= word ptr  8		; uint16_t
//@ x		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 282
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		sub	ax, 5		; Integer Subtraction
//@ 		cmp	ax, [bp+y]	; uint16_t
//@ 		jnb	short loc_283EF	; Jump if Not Below (CF=0)
//@ 		jmp	short locret_2843E ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 283
//@ 
//@ loc_283EF:				; CODE XREF: PutChar+Dj
//@ 		mov	ColorShift, 0	; uint8_t
//@ ; #line	"CSMENU.PAS" 284
//@ 		mov	ColorZero, 0FFh	; uint8_t
//@ ; #line	"CSMENU.PAS" 285
//@ 		mov	al, [bp+c]	; char
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+xf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 286
//@ 		mov	al, [bp+c]	; char
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+yf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 287
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		push	0Ah
//@ 		push	7
//@ 		push	100h
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+xf]	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+yf], 0A00h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, 200h	; Add
//@ 		les	di, Fonts	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconFF2Sub	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 288
//@ 
//@ locret_2843E:				; CODE XREF: PutChar+Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ PutChar		endp
//@ 
//@ ; #line	"CSMENU.PAS" 294
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutStr		proc far		; CODE XREF: EndPaint+371P
//@ 					; PlayBrifing+47FP ...
//@ 
//@ var_108		= word ptr -108h
//@ yf		= word ptr -106h	; uint16_t
//@ xf		= word ptr -104h	; uint16_t
//@ n		= word ptr -102h	; uint16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ y		= word ptr  0Ah		; uint16_t
//@ x		= word ptr  0Ch		; uint16_t
//@ 
//@ 		enter	108h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSMENU.PAS" 295
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, 5		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, word ptr VideoH+2 ;	int32_t
//@ 		jg	short loc_28473	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_28476	; Jump if Less (SF!=OF)
//@ 		cmp	ax, word ptr VideoH ; int32_t
//@ 		jbe	short loc_28476	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_28473:				; CODE XREF: PutStr+27j
//@ 		jmp	locret_28526	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 296
//@ 
//@ loc_28476:				; CODE XREF: PutStr+29j PutStr+2Fj
//@ 		mov	ColorShift, 1	; uint8_t
//@ ; #line	"CSMENU.PAS" 297
//@ 		mov	ColorZero, 0FFh	; uint8_t
//@ ; #line	"CSMENU.PAS" 298
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_108], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jbe	short loc_28496	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_28526	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28496:				; CODE XREF: PutStr+4Fj
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_284A0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2849C:				; CODE XREF: PutStr+E1j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSMENU.PAS" 299
//@ 
//@ loc_284A0:				; CODE XREF: PutStr+58j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		cmp	[bp+di+s], 20h ; ' ' ; char[256] // Pascal string
//@ 		jz	short loc_28515	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 301
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+xf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 302
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+yf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 303
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		push	0Ah
//@ 		push	7
//@ 		push	100h
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+xf]	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+yf], 0A00h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, 200h	; Add
//@ 		les	di, Fonts	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconFF2Sub	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 304
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-1DA0h]
//@ 		add	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 305
//@ 		jmp	short loc_28519	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28515:				; CODE XREF: PutStr+67j
//@ 		add	[bp+x],	4	; uint16_t
//@ 
//@ loc_28519:				; CODE XREF: PutStr+D1j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jz	short locret_28526 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2849C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 306
//@ 
//@ locret_28526:				; CODE XREF: PutStr:loc_28473j
//@ 					; PutStr+51j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ PutStr		endp
//@ 
//@ ; #line	"CSMENU.PAS" 311
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutStrFix	proc near		; CODE XREF: UpDateMenu+97Cp
//@ 					; UpDateMenu+9AFp
//@ 
//@ var_108		= word ptr -108h
//@ yf		= word ptr -106h	; uint16_t
//@ xf		= word ptr -104h	; uint16_t
//@ n		= word ptr -102h	; uint16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ y		= word ptr  8		; uint16_t
//@ x		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	108h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSMENU.PAS" 312
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, 5		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, word ptr VideoH+2 ;	int32_t
//@ 		jg	short loc_2855B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2855E	; Jump if Less (SF!=OF)
//@ 		cmp	ax, word ptr VideoH ; int32_t
//@ 		jbe	short loc_2855E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2855B:				; CODE XREF: PutStrFix+27j
//@ 		jmp	locret_285ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 313
//@ 
//@ loc_2855E:				; CODE XREF: PutStrFix+29j
//@ 					; PutStrFix+2Fj
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_108], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		ja	short locret_285ED ; Jump if Above (CF=0 & ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2857B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28577:				; CODE XREF: PutStrFix+C1j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSMENU.PAS" 314
//@ 
//@ loc_2857B:				; CODE XREF: PutStrFix+4Bj
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		cmp	[bp+di+s], 20h ; ' ' ; char[256] // Pascal string
//@ 		jz	short loc_285DF	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 316
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+xf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 317
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+yf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 318
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		push	9
//@ 		push	7
//@ 		push	100h
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+xf]	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+yf], 0A00h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, 200h	; Add
//@ 		les	di, Fonts	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconFF2Sub	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 319
//@ 		add	[bp+x],	8	; uint16_t
//@ ; #line	"CSMENU.PAS" 320
//@ 		jmp	short loc_285E3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_285DF:				; CODE XREF: PutStrFix+5Aj
//@ 		add	[bp+x],	8	; uint16_t
//@ 
//@ loc_285E3:				; CODE XREF: PutStrFix+B3j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jnz	short loc_28577	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 321
//@ 
//@ locret_285ED:				; CODE XREF: PutStrFix:loc_2855Bj
//@ 					; PutStrFix+45j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutStrFix	endp
//@ 
//@ ; #line	"CSMENU.PAS" 327
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutStrOn	proc near		; CODE XREF: PutStrBackOn+40p
//@ 					; UpDateMenu+400p
//@ 
//@ var_108		= word ptr -108h
//@ yf		= word ptr -106h	; uint16_t
//@ xf		= word ptr -104h	; uint16_t
//@ n		= word ptr -102h	; uint16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ y		= word ptr  8		; uint16_t
//@ x		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	108h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSMENU.PAS" 328
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		add	ax, 5		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, word ptr VideoH+2 ;	int32_t
//@ 		jg	short loc_28622	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_28625	; Jump if Less (SF!=OF)
//@ 		cmp	ax, word ptr VideoH ; int32_t
//@ 		jbe	short loc_28625	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_28622:				; CODE XREF: PutStrOn+27j
//@ 		jmp	locret_286D5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 329
//@ 
//@ loc_28625:				; CODE XREF: PutStrOn+29j PutStrOn+2Fj
//@ 		mov	ColorShift, 21h	; '!' ; uint8_t
//@ ; #line	"CSMENU.PAS" 330
//@ 		mov	ColorZero, 0	; uint8_t
//@ ; #line	"CSMENU.PAS" 331
//@ 		mov	al, [bp+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_108], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jbe	short loc_28645	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_286D5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28645:				; CODE XREF: PutStrOn+4Fj
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2864F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2864B:				; CODE XREF: PutStrOn+E1j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSMENU.PAS" 332
//@ 
//@ loc_2864F:				; CODE XREF: PutStrOn+58j
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		cmp	[bp+di+s], 20h ; ' ' ; char[256] // Pascal string
//@ 		jz	short loc_286C4	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 334
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		and	al, 0Fh		; Logical AND
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+xf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 335
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+yf], ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 336
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		push	9
//@ 		push	7
//@ 		push	100h
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, [bp+xf]	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+yf], 0A00h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, 200h	; Add
//@ 		les	di, Fonts	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconFF2Sub	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 337
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	al, [bp+di+s]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-1DA0h]
//@ 		add	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 338
//@ 		jmp	short loc_286C8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_286C4:				; CODE XREF: PutStrOn+67j
//@ 		add	[bp+x],	4	; uint16_t
//@ 
//@ loc_286C8:				; CODE XREF: PutStrOn+D1j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jz	short locret_286D5 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2864B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 339
//@ 
//@ locret_286D5:				; CODE XREF: PutStrOn:loc_28622j
//@ 					; PutStrOn+51j	...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutStrOn	endp
//@ 
//@ ; #line	"CSMENU.PAS" 347
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutStrBack	proc near		; CODE XREF: UpDateMenu+48Bp
//@ 					; UpDateMenu+4A5p ...
//@ 
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ y		= word ptr  8		; uint16_t
//@ x		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	100h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSMENU.PAS" 348
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	CalcStringLen	; function far PASCAL returns unsigned int 'Word'
//@ 		sub	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 349
//@ 		cmp	[bp+x],	0	; uint16_t
//@ 		jnb	short loc_2870D	; Jump if Not Below (CF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 350
//@ 
//@ loc_2870D:				; CODE XREF: PutStrBack+2Dj
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 351
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutStrBack	endp
//@ 
//@ ; #line	"CSMENU.PAS" 354
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutStrCenter	proc far		; CODE XREF: UpDateRanking+68P
//@ 					; UpDateMenu+182P ...
//@ 
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ y		= word ptr  0Ah		; uint16_t
//@ x		= word ptr  0Ch		; uint16_t
//@ 
//@ 		enter	100h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSMENU.PAS" 355
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	CalcStringLen	; function far PASCAL returns unsigned int 'Word'
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 356
//@ 		cmp	[bp+x],	0	; uint16_t
//@ 		jnb	short loc_28758	; Jump if Not Below (CF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 357
//@ 
//@ loc_28758:				; CODE XREF: PutStrCenter+2Fj
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 358
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ PutStrCenter	endp
//@ 
//@ ; #line	"CSMENU.PAS" 361
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutStrBackOn	proc near		; CODE XREF: UpDateMenu+4CDp
//@ 					; UpDateMenu+5FEp ...
//@ 
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  4
//@ y		= word ptr  8		; uint16_t
//@ x		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	100h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSMENU.PAS" 362
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	CalcStringLen	; function far PASCAL returns unsigned int 'Word'
//@ 		sub	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 363
//@ 		cmp	[bp+x],	0	; uint16_t
//@ 		jnb	short loc_287A1	; Jump if Not Below (CF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x],	ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 364
//@ 
//@ loc_287A1:				; CODE XREF: PutStrBackOn+2Dj
//@ 		push	[bp+x]		; uint16_t
//@ 		push	[bp+y]		; uint16_t
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	PutStrOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 365
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutStrBackOn	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_287B4	db 1,'>'                ; DATA XREF: UpDateConsole+133o
//@ a__8		db 1,'_'                ; DATA XREF: UpDateConsole+18Eo
//@ aNew_0		db 3,'New'              ; DATA XREF: UpDateConsole:loc_289D4o
//@ aGoToGame	db 10,'Go to GAME'      ; DATA XREF: UpDateConsole+222o
//@ aMonitor_0	db 7,'Monitor'          ; DATA XREF: UpDateConsole:loc_28A44o
//@ aDisplay	db 7,'Display'          ; DATA XREF: UpDateConsole+2A3o
//@ aQuit_0		db 4,'Quit'             ; DATA XREF: UpDateConsole+2CBo
//@ aContrast	db 8,'Contrast'         ; DATA XREF: UpDateConsole+35Fo
//@ aColor_0	db 5,'Color'            ; DATA XREF: UpDateConsole+387o
//@ aBright		db 6,'Bright'           ; DATA XREF: UpDateConsole+3AFo
//@ aSkill_0	db 9,'- SKILL -'        ; DATA XREF: UpDateConsole+51Eo
//@ aEazy		db 4,'Eazy'             ; DATA XREF: UpDateConsole+533o
//@ aNormal		db 6,'Normal'           ; DATA XREF: UpDateConsole+55Bo
//@ aHard		db 4,'Hard'             ; DATA XREF: UpDateConsole+583o
//@ ; #line	"CSMENU.PAS" 381
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDateConsole	proc far		; CODE XREF: ShowVesaConsole+46P
//@ 					; ShowScreen+41P
//@ 
//@ var_206		= byte ptr -206h
//@ var_108		= word ptr -108h
//@ S		= byte ptr -106h	; char[256] // Pascal string
//@ P		= word ptr -6		; int16_t
//@ N		= word ptr -4		; int16_t
//@ D		= word ptr -2		; int16_t
//@ 
//@ 		enter	206h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 382
//@ 		cmp	ConsDY,	0	; int16_t
//@ 		jge	short loc_2881D	; Jump if Greater or Equal (SF=OF)
//@ 		mov	byte ptr ConsoleComm+0F6h, 0 ; char[287] // Pascal string
//@ ; #line	"CSMENU.PAS" 383
//@ 
//@ loc_2881D:				; CODE XREF: UpDateConsole+9j
//@ 		cmp	ConsDY,	0	; int16_t
//@ 		jge	short loc_2882B	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, HistCnt	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	CurHist, ax	; int16_t
//@ ; #line	"CSMENU.PAS" 384
//@ 
//@ loc_2882B:				; CODE XREF: UpDateConsole+15j
//@ 		cmp	ConsDY,	0	; int16_t
//@ 		jle	short loc_2884D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSMENU.PAS" 386
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ConsY, ax	; int16_t
//@ ; #line	"CSMENU.PAS" 387
//@ 		cmp	ConsY, 4Ch ; 'L' ; int16_t
//@ 		jle	short loc_2884D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ConsY, 4Ch ; 'L' ; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsDY,	ax	; int16_t
//@ ; #line	"CSMENU.PAS" 389
//@ 
//@ loc_2884D:				; CODE XREF: UpDateConsole+23j
//@ 					; UpDateConsole+33j
//@ 		cmp	ConsDY,	0	; int16_t
//@ 		jge	short loc_28876	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSMENU.PAS" 391
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		sub	ConsY, ax	; int16_t
//@ ; #line	"CSMENU.PAS" 392
//@ 		cmp	ConsY, 0	; int16_t
//@ 		jg	short loc_28876	; Jump if Greater (ZF=0	& SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsY, ax	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ConsDY,	ax	; int16_t
//@ 		mov	Console, 0	; bool
//@ 		jmp	locret_28E64	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 395
//@ 
//@ loc_28876:				; CODE XREF: UpDateConsole+45j
//@ 					; UpDateConsole+55j
//@ 		mov	ax, ConsY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		add	ax, 6		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+D],	ax	; int16_t
//@ ; #line	"CSMENU.PAS" 396
//@ 		mov	ax, ConsY	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_108], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jg	short loc_288F9	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+N],	ax	; int16_t
//@ 		jmp	short loc_288AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_288A7:				; CODE XREF: UpDateConsole+EAj
//@ 		inc	[bp+N]		; int16_t
//@ ; #line	"CSMENU.PAS" 397
//@ 
//@ loc_288AA:				; CODE XREF: UpDateConsole+98j
//@ 		les	di, ConsolePtr	; void*
//@ 		push	es
//@ 		imul	ax, [bp+N], 140h ; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		mov	ax, ConsY	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+N]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	di, ax
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		push	word ptr [di-6E82h]
//@ 		push	word ptr [di-6E84h]
//@ 		push	0
//@ 		push	50h ; 'P'
//@ 		call	MovsED		; function far PASCAL returns void
//@ 		mov	ax, [bp+N]	; int16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jnz	short loc_288A7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 400
//@ 
//@ loc_288F9:				; CODE XREF: UpDateConsole+93j
//@ 		mov	WinEX, 13Ch	; uint16_t
//@ ; #line	"CSMENU.PAS" 401
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+N],	ax	; int16_t
//@ 		jmp	short loc_28909	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28906:				; CODE XREF: UpDateConsole+11Bj
//@ 		inc	[bp+N]		; int16_t
//@ ; #line	"CSMENU.PAS" 402
//@ 
//@ loc_28909:				; CODE XREF: UpDateConsole+F7j
//@ 		push	64h ; 'd'
//@ 		imul	ax, [bp+N], 9	; int16_t
//@ 		add	ax, [bp+D]	; int16_t
//@ 		push	ax
//@ 		imul	di, [bp+N], 29h	; int16_t
//@ 		add	di, 0E6EEh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		call	PutString	; function far PASCAL returns void
//@ 		cmp	[bp+N],	5	; int16_t
//@ 		jnz	short loc_28906	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 403
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	WinEX, ax	; uint16_t
//@ ; #line	"CSMENU.PAS" 405
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_287B4 ; ">"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, (offset ConsoleComm+0F6h) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 406
//@ 		cmp	ConsMode, 1	; int16_t
//@ 		jnz	short loc_289B3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 407
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 50h	; 'P'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jg	short loc_2898A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_289B3	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 28h	; '('   ; Compare Two Operands
//@ 		jbe	short loc_289B3	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2898A:				; CODE XREF: UpDateConsole+174j
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset a__8	; "_"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 408
//@ 
//@ loc_289B3:				; CODE XREF: UpDateConsole+15Aj
//@ 					; UpDateConsole+176j ...
//@ 		push	64h ; 'd'
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 3Ah	; ':'   ; Add
//@ 		push	ax
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 410
//@ 		mov	ax, ConsMenu	; int16_t
//@ ; #line	"CSMENU.PAS" 411
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jz	short loc_289D4	; Jump if Zero (ZF=1)
//@ 		jmp	loc_28B57	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 412
//@ 
//@ loc_289D4:				; CODE XREF: UpDateConsole+1C2j
//@ 		mov	di, offset aNew_0 ; "New"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 413
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_28A15	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 414
//@ 		push	0Ch
//@ 		push	[bp+D]		; int16_t
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		cmp	ConsMainY, 0	; int16_t
//@ 		jnz	short loc_28A07	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28A0B	; Jump if Zero (ZF=1)
//@ 
//@ loc_28A07:				; CODE XREF: UpDateConsole+1F1j
//@ 		mov	al, 0
//@ 		jmp	short loc_28A0D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28A0B:				; CODE XREF: UpDateConsole+1F8j
//@ 		mov	al, 1
//@ 
//@ loc_28A0D:				; CODE XREF: UpDateConsole+1FCj
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ 		jmp	short loc_28A28	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 415
//@ 
//@ loc_28A15:				; CODE XREF: UpDateConsole+1DFj
//@ 		push	0Ch
//@ 		push	[bp+D]		; int16_t
//@ 		push	0FEh ; 'þ'
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 418
//@ 
//@ loc_28A28:				; CODE XREF: UpDateConsole+206j
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_28A44	; Jump if Zero (ZF=1)
//@ 		mov	di, offset aGoToGame ; "Go to GAME"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_28A57	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28A44:				; CODE XREF: UpDateConsole+220j
//@ 		mov	di, offset aMonitor_0 ;	"Monitor"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 419
//@ 
//@ loc_28A57:				; CODE XREF: UpDateConsole+235j
//@ 		cmp	VESAPresent, 0	; bool
//@ 		jz	short loc_28A90	; Jump if Zero (ZF=1)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_28A90	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 420
//@ 		push	0Ch
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0Bh		; Add
//@ 		push	ax
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		cmp	ConsMainY, 1	; int16_t
//@ 		jnz	short loc_28A82	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28A86	; Jump if Zero (ZF=1)
//@ 
//@ loc_28A82:				; CODE XREF: UpDateConsole+26Cj
//@ 		mov	al, 0
//@ 		jmp	short loc_28A88	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28A86:				; CODE XREF: UpDateConsole+273j
//@ 		mov	al, 1
//@ 
//@ loc_28A88:				; CODE XREF: UpDateConsole+277j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ 		jmp	short loc_28AA7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 421
//@ 
//@ loc_28A90:				; CODE XREF: UpDateConsole+24Fj
//@ 					; UpDateConsole+256j
//@ 		push	0Ch
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0Bh		; Add
//@ 		push	ax
//@ 		push	0FEh ; 'þ'
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 423
//@ 
//@ loc_28AA7:				; CODE XREF: UpDateConsole+281j
//@ 		push	0Ch
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 16h		; Add
//@ 		push	ax
//@ 		mov	di, offset aDisplay ; "Display"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 2	; int16_t
//@ 		jnz	short loc_28AC3	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28AC7	; Jump if Zero (ZF=1)
//@ 
//@ loc_28AC3:				; CODE XREF: UpDateConsole+2ADj
//@ 		mov	al, 0
//@ 		jmp	short loc_28AC9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28AC7:				; CODE XREF: UpDateConsole+2B4j
//@ 		mov	al, 1
//@ 
//@ loc_28AC9:				; CODE XREF: UpDateConsole+2B8j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 424
//@ 		push	0Ch
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 21h	; '!'   ; Add
//@ 		push	ax
//@ 		mov	di, offset aQuit_0 ; "Quit"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 3	; int16_t
//@ 		jnz	short loc_28AEB	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28AEF	; Jump if Zero (ZF=1)
//@ 
//@ loc_28AEB:				; CODE XREF: UpDateConsole+2D5j
//@ 		mov	al, 0
//@ 		jmp	short loc_28AF1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28AEF:				; CODE XREF: UpDateConsole+2DCj
//@ 		mov	al, 1
//@ 
//@ loc_28AF1:				; CODE XREF: UpDateConsole+2E0j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 425
//@ 		imul	ax, ConsMainY, 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		add	ax, dx		; Add
//@ 		mov	[bp+P],	ax	; int16_t
//@ ; #line	"CSMENU.PAS" 426
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_28B26	; Jump if Less (SF!=OF)
//@ 		jg	short loc_28B54	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_28B54	; Jump if Not Below (CF=0)
//@ ; #line	"CSMENU.PAS" 427
//@ 
//@ loc_28B26:				; CODE XREF: UpDateConsole+311j
//@ 		push	6
//@ 		push	[bp+P]		; int16_t
//@ 		push	56h ; 'V'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		push	14h
//@ 		push	1
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ 		push	7
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	55h ; 'U'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 7		; Add
//@ 		push	ax
//@ 		push	0Bh
//@ 		call	BrightBar	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 428
//@ 
//@ loc_28B54:				; CODE XREF: UpDateConsole+313j
//@ 					; UpDateConsole+317j
//@ 		jmp	locret_28E64	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 429
//@ 
//@ loc_28B57:				; CODE XREF: UpDateConsole+1C4j
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jz	short loc_28B5F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_28D1A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 430
//@ 
//@ loc_28B5F:				; CODE XREF: UpDateConsole+34Dj
//@ 		add	[bp+D],	2	; int16_t
//@ ; #line	"CSMENU.PAS" 431
//@ 		push	0Ah
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0		; Add
//@ 		push	ax
//@ 		mov	di, offset aContrast ; "Contrast"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 0	; int16_t
//@ 		jnz	short loc_28B7F	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28B83	; Jump if Zero (ZF=1)
//@ 
//@ loc_28B7F:				; CODE XREF: UpDateConsole+369j
//@ 		mov	al, 0
//@ 		jmp	short loc_28B85	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28B83:				; CODE XREF: UpDateConsole+370j
//@ 		mov	al, 1
//@ 
//@ loc_28B85:				; CODE XREF: UpDateConsole+374j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 432
//@ 		push	0Ah
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 14h		; Add
//@ 		push	ax
//@ 		mov	di, offset aColor_0 ; "Color"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 1	; int16_t
//@ 		jnz	short loc_28BA7	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28BAB	; Jump if Zero (ZF=1)
//@ 
//@ loc_28BA7:				; CODE XREF: UpDateConsole+391j
//@ 		mov	al, 0
//@ 		jmp	short loc_28BAD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28BAB:				; CODE XREF: UpDateConsole+398j
//@ 		mov	al, 1
//@ 
//@ loc_28BAD:				; CODE XREF: UpDateConsole+39Cj
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 433
//@ 		push	0Ah
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 28h	; '('   ; Add
//@ 		push	ax
//@ 		mov	di, offset aBright ; "Bright"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 2	; int16_t
//@ 		jnz	short loc_28BCF	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28BD3	; Jump if Zero (ZF=1)
//@ 
//@ loc_28BCF:				; CODE XREF: UpDateConsole+3B9j
//@ 		mov	al, 0
//@ 		jmp	short loc_28BD5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28BD3:				; CODE XREF: UpDateConsole+3C0j
//@ 		mov	al, 1
//@ 
//@ loc_28BD5:				; CODE XREF: UpDateConsole+3C4j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 434
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+N],	ax	; int16_t
//@ 		jmp	short loc_28BE5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28BE2:				; CODE XREF: UpDateConsole+4ACj
//@ 		inc	[bp+N]		; int16_t
//@ 
//@ loc_28BE5:				; CODE XREF: UpDateConsole+3D3j
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		add	ax, [bp+D]	; int16_t
//@ 		cmp	ax, 0BEh ; '¾'  ; Compare Two Operands
//@ 		jl	short loc_28BF4	; Jump if Less (SF!=OF)
//@ 		jmp	loc_28CB3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 436
//@ 
//@ loc_28BF4:				; CODE XREF: UpDateConsole+3E2j
//@ 		mov	di, [bp+N]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		imul	ax, [di-17DEh],	45h ; Signed Multiply
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Eh
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, 9		; Add
//@ 		mov	[bp+P],	ax	; int16_t
//@ ; #line	"CSMENU.PAS" 437
//@ 		push	8
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0Bh		; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	53h ; 'S'
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0Fh		; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	14h
//@ 		push	8
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 438
//@ 		push	9
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0Ch		; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	52h ; 'R'
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0Eh		; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	0Ah
//@ 		push	11h
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 439
//@ 		push	[bp+P]		; int16_t
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		add	ax, 9		; Add
//@ 		add	ax, [bp+D]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 3		; Add
//@ 		push	ax
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		add	ax, 11h		; Add
//@ 		add	ax, [bp+D]	; int16_t
//@ 		push	ax
//@ 		push	1Ah
//@ 		push	5
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 440
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		add	ax, 0Ah		; Add
//@ 		add	ax, [bp+D]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		imul	ax, [bp+N], 14h	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		add	ax, [bp+D]	; int16_t
//@ 		push	ax
//@ 		push	14h
//@ 		push	10h
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 441
//@ 
//@ loc_28CB3:				; CODE XREF: UpDateConsole+3E4j
//@ 		cmp	[bp+N],	2	; int16_t
//@ 		jz	short loc_28CBC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_28BE2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 442
//@ 
//@ loc_28CBC:				; CODE XREF: UpDateConsole+4AAj
//@ 		imul	ax, ConsMainY, 14h ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		add	ax, dx		; Add
//@ 		mov	[bp+P],	ax	; int16_t
//@ ; #line	"CSMENU.PAS" 443
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_28CEB	; Jump if Less (SF!=OF)
//@ 		jg	short loc_28D17	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_28D17	; Jump if Not Below (CF=0)
//@ ; #line	"CSMENU.PAS" 444
//@ 
//@ loc_28CEB:				; CODE XREF: UpDateConsole+4D6j
//@ 		push	6
//@ 		push	[bp+P]		; int16_t
//@ 		push	56h ; 'V'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		push	14h
//@ 		push	1
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ 		push	7
//@ 		push	[bp+P]		; int16_t
//@ 		push	55h ; 'U'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 7		; Add
//@ 		push	ax
//@ 		push	0Bh
//@ 		call	BrightBar	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 445
//@ 
//@ loc_28D17:				; CODE XREF: UpDateConsole+4D8j
//@ 					; UpDateConsole+4DCj
//@ 		jmp	locret_28E64	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 446
//@ 
//@ loc_28D1A:				; CODE XREF: UpDateConsole+34Fj
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jz	short loc_28D22	; Jump if Zero (ZF=1)
//@ 		jmp	locret_28E64	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 447
//@ 
//@ loc_28D22:				; CODE XREF: UpDateConsole+510j
//@ 		push	0Ah
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 0		; Add
//@ 		push	ax
//@ 		mov	di, offset aSkill_0 ; "- SKILL -"
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 448
//@ 		push	0Ah
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		mov	di, offset aEazy ; "Eazy"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 0	; int16_t
//@ 		jnz	short loc_28D53	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28D57	; Jump if Zero (ZF=1)
//@ 
//@ loc_28D53:				; CODE XREF: UpDateConsole+53Dj
//@ 		mov	al, 0
//@ 		jmp	short loc_28D59	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28D57:				; CODE XREF: UpDateConsole+544j
//@ 		mov	al, 1
//@ 
//@ loc_28D59:				; CODE XREF: UpDateConsole+548j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 449
//@ 		push	0Ah
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 1Bh		; Add
//@ 		push	ax
//@ 		mov	di, offset aNormal ; "Normal"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 1	; int16_t
//@ 		jnz	short loc_28D7B	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28D7F	; Jump if Zero (ZF=1)
//@ 
//@ loc_28D7B:				; CODE XREF: UpDateConsole+565j
//@ 		mov	al, 0
//@ 		jmp	short loc_28D81	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28D7F:				; CODE XREF: UpDateConsole+56Cj
//@ 		mov	al, 1
//@ 
//@ loc_28D81:				; CODE XREF: UpDateConsole+570j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 450
//@ 		push	0Ah
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 26h	; '&'   ; Add
//@ 		push	ax
//@ 		mov	di, offset aHard ; "Hard"
//@ 		push	cs
//@ 		push	di
//@ 		cmp	ConsMainY, 2	; int16_t
//@ 		jnz	short loc_28DA3	; Jump if Not Zero (ZF=0)
//@ 		cmp	ConsMode, 0	; int16_t
//@ 		jz	short loc_28DA7	; Jump if Zero (ZF=1)
//@ 
//@ loc_28DA3:				; CODE XREF: UpDateConsole+58Dj
//@ 		mov	al, 0
//@ 		jmp	short loc_28DA9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28DA7:				; CODE XREF: UpDateConsole+594j
//@ 		mov	al, 1
//@ 
//@ loc_28DA9:				; CODE XREF: UpDateConsole+598j
//@ 		push	ax
//@ 		call	PutString	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 451
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		add	ax, 8		; Add
//@ 		mov	[bp+P],	ax	; int16_t
//@ ; #line	"CSMENU.PAS" 452
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_28DD7	; Jump if Less (SF!=OF)
//@ 		jg	short loc_28E04	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_28E04	; Jump if Not Below (CF=0)
//@ 
//@ loc_28DD7:				; CODE XREF: UpDateConsole+5C2j
//@ 		push	6
//@ 		push	[bp+P]		; int16_t
//@ 		push	56h ; 'V'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	0
//@ 		push	0Fh
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ 		push	7
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 0		; Add
//@ 		push	ax
//@ 		push	55h ; 'U'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	6
//@ 		call	BrightBar	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 453
//@ 
//@ loc_28E04:				; CODE XREF: UpDateConsole+5C4j
//@ 					; UpDateConsole+5C8j
//@ 		imul	ax, ConsMainY, 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+D]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		add	ax, dx		; Add
//@ 		add	ax, 10h		; Add
//@ 		mov	[bp+P],	ax	; int16_t
//@ ; #line	"CSMENU.PAS" 454
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 0Ah		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_28E36	; Jump if Less (SF!=OF)
//@ 		jg	short locret_28E64 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short locret_28E64 ; Jump if Not Below (CF=0)
//@ ; #line	"CSMENU.PAS" 455
//@ 
//@ loc_28E36:				; CODE XREF: UpDateConsole+621j
//@ 		push	6
//@ 		push	[bp+P]		; int16_t
//@ 		push	56h ; 'V'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		push	14h
//@ 		push	1
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ 		push	7
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	55h ; 'U'
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		add	ax, 7		; Add
//@ 		push	ax
//@ 		push	0Bh
//@ 		call	BrightBar	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 458
//@ 
//@ locret_28E64:				; CODE XREF: UpDateConsole+66j
//@ 					; UpDateConsole:loc_28B54j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ UpDateConsole	endp
//@ 
//@ ; #line	"CSMENU.PAS" 462
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawMenuBar	proc near		; CODE XREF: UpDateMenu+3AEp
//@ 					; UpDateMenu+434p ...
//@ 
//@ h		= word ptr  4		; int16_t
//@ w		= word ptr  6		; int16_t
//@ y1		= word ptr  8		; int16_t
//@ x1		= word ptr  0Ah		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSMENU.PAS" 463
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		add	ax, [bp+w]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		add	ax, [bp+h]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		push	18h
//@ 		call	BrightBar	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 464
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		add	ax, [bp+w]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		add	ax, [bp+h]	; int16_t
//@ 		push	ax
//@ 		push	1Ch
//@ 		push	10h
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 465
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ DrawMenuBar	endp
//@ 
//@ ; #line	"CSMENU.PAS" 470
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawMenuRect	proc far		; CODE XREF: UpDateRanking+57P
//@ 					; UpDateMenu+1BP ...
//@ 
//@ var_E		= word ptr -0Eh
//@ x0		= word ptr -0Ch		; int32_t
//@ var_A		= word ptr -0Ah
//@ MP		= word ptr -8		; struct MenuRect
//@ var_6		= word ptr -6
//@ var_4		= word ptr -4
//@ var_2		= word ptr -2
//@ arg_0		= dword	ptr  6
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+MP]	; struct MenuRect
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		mov	cx, 8
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSMENU.PAS" 472
//@ 		mov	ax, [bp+var_6]
//@ 		add	ax, 4		; Add
//@ 		mov	MnSY, ax	; int16_t
//@ ; #line	"CSMENU.PAS" 473
//@ 		mov	ax, [bp+var_2]
//@ 		mov	[bp+var_E], ax
//@ 		mov	ax, [bp+var_6]
//@ 		cmp	ax, [bp+var_E]	; Compare Two Operands
//@ 		jle	short loc_28EDF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_28F6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28EDF:				; CODE XREF: DrawMenuRect+2Dj
//@ 		mov	y, ax		; int16_t
//@ 		jmp	short loc_28EE8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28EE4:				; CODE XREF: DrawMenuRect+BCj
//@ 		inc	y		; int16_t
//@ ; #line	"CSMENU.PAS" 475
//@ 
//@ loc_28EE8:				; CODE XREF: DrawMenuRect+35j
//@ 		mov	ax, [bp+var_4]
//@ 		sub	ax, [bp+MP]	; struct MenuRect
//@ 		inc	ax		; Increment by 1
//@ 		mov	w, ax		; uint16_t
//@ 		mov	ax, [bp+MP]	; struct MenuRect
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	di, y		; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	ax, [di-6E84h]	; Add
//@ 		adc	dx, [di-6E82h]	; Add with Carry
//@ 		mov	[bp+x0], ax	; int32_t
//@ 		mov	[bp+var_A], dx
//@ ; #line	"CSMENU.PAS" 476
//@ 
//@ loc_28F0B:				; CODE XREF: DrawMenuRect+B2j
//@ 		cmp	w, 0		; uint16_t
//@ 		jbe	short loc_28F61	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSMENU.PAS" 478
//@ 		cmp	w, 40h ; '@'    ; uint16_t
//@ 		jbe	short loc_28F21	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	j, 40h ; '@'    ; uint16_t
//@ 		jmp	short loc_28F27	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28F21:				; CODE XREF: DrawMenuRect+6Aj
//@ 		mov	ax, w		; uint16_t
//@ 		mov	j, ax		; uint16_t
//@ ; #line	"CSMENU.PAS" 479
//@ 
//@ loc_28F27:				; CODE XREF: DrawMenuRect+72j
//@ 		les	di, MenuTiler	; void*
//@ 		push	es
//@ 		mov	ax, y		; int16_t
//@ 		and	ax, 3Fh		; Logical AND
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		push	VgaSeg		; uint16_t
//@ 		push	[bp+var_A]
//@ 		push	[bp+x0]		; int32_t
//@ 		mov	ax, j		; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovsEW		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 481
//@ 		mov	ax, j		; uint16_t
//@ 		sub	w, ax		; uint16_t
//@ 		add	[bp+x0], 40h ; '@' ; int32_t
//@ 		adc	[bp+var_A], 0	; Add with Carry
//@ ; #line	"CSMENU.PAS" 482
//@ 		jmp	short loc_28F0B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 483
//@ 
//@ loc_28F61:				; CODE XREF: DrawMenuRect+63j
//@ 		mov	ax, y		; int16_t
//@ 		cmp	ax, [bp+var_E]	; Compare Two Operands
//@ 		jz	short loc_28F6C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_28EE4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 487
//@ 
//@ loc_28F6C:				; CODE XREF: DrawMenuRect+2Fj
//@ 					; DrawMenuRect+BAj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_28F77	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28F73:				; CODE XREF: DrawMenuRect+F8j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_28F77:				; CODE XREF: DrawMenuRect+C4j
//@ 		mov	ax, [bp+MP]	; struct MenuRect
//@ 		add	ax, n$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+var_6]
//@ 		add	ax, n$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+var_4]
//@ 		sub	ax, n$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+var_2]
//@ 		sub	ax, n$0		; int16_t
//@ 		push	ax
//@ 		push	1
//@ 		push	10h
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ 		cmp	n$0, 1		; int16_t
//@ 		jnz	short loc_28F73	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 488
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_28FB2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28FAE:				; CODE XREF: DrawMenuRect+13Fj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_28FB2:				; CODE XREF: DrawMenuRect+FFj
//@ 		mov	ax, [bp+MP]	; struct MenuRect
//@ 		add	ax, n$0		; int16_t
//@ 		add	ax, 6		; Add
//@ 		push	ax
//@ 		mov	ax, [bp+var_6]
//@ 		add	ax, n$0		; int16_t
//@ 		add	ax, 0Dh		; Add
//@ 		push	ax
//@ 		mov	ax, [bp+var_4]
//@ 		sub	ax, n$0		; int16_t
//@ 		sub	ax, 6		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+var_2]
//@ 		sub	ax, n$0		; int16_t
//@ 		sub	ax, 5		; Integer Subtraction
//@ 		push	ax
//@ 		push	10h
//@ 		push	1
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ 		cmp	n$0, 1		; int16_t
//@ 		jnz	short loc_28FAE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 490
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_28FFA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_28FF6:				; CODE XREF: DrawMenuRect+19Ej
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_28FFA:				; CODE XREF: DrawMenuRect+147j
//@ 		mov	ax, [bp+MP]	; struct MenuRect
//@ 		sub	ax, n$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+var_6]
//@ 		sub	ax, n$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+var_4]
//@ 		add	ax, n$0		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, [bp+var_2]
//@ 		add	ax, n$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, 1Dh
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, 1Dh
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ 		cmp	n$0, 4		; int16_t
//@ 		jnz	short loc_28FF6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 491
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ DrawMenuRect	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ unk_29051	db    9			; DATA XREF: PutScroller+9o
//@ 		db    1
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    2
//@ ; #line	"CSMENU.PAS" 496
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutScroller	proc near		; CODE XREF: UpDateMenu+60Ap
//@ 					; UpDateMenu+616p ...
//@ 
//@ ScrollerBar	= byte ptr  0		; char[256] // Pascal string
//@ v		= word ptr  4		; int16_t
//@ y		= word ptr  6		; int16_t
//@ x		= word ptr  8		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSMENU.PAS" 497
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		mov	di, offset unk_29051
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 498
//@ 		mov	ax, [bp+v]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, [bp+x]	; int16_t
//@ 		push	ax
//@ 		push	[bp+y]		; int16_t
//@ 		push	3
//@ 		call	PutChar		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 499
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ PutScroller	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ unk_29086	db    9			; DATA XREF: PutScroller15+9o
//@ 		db    1
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    0
//@ 		db    2
//@ ; #line	"CSMENU.PAS" 503
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutScroller15	proc near		; CODE XREF: UpDateMenu+557p
//@ 					; UpDateMenu+566p ...
//@ 
//@ v		= word ptr  4		; int16_t
//@ y		= word ptr  6		; int16_t
//@ x		= word ptr  8		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSMENU.PAS" 504
//@ 		push	[bp+x]		; int16_t
//@ 		push	[bp+y]		; int16_t
//@ 		mov	di, offset unk_29086
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 505
//@ 		mov	ax, [bp+v]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		imul	ax, 38h		; Signed Multiply
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3Ch	; '<'
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, [bp+x]	; int16_t
//@ 		push	ax
//@ 		push	[bp+y]		; int16_t
//@ 		push	3
//@ 		call	PutChar		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 506
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ PutScroller15	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a?		db 1,'?'                ; DATA XREF: UpDateMenu+712o
//@ aOrMouse1	db 10,' or Mouse1'      ; DATA XREF: UpDateMenu+760o
//@ aOrMouse2	db 10,' or Mouse2'      ; DATA XREF: UpDateMenu+792o
//@ aOrMouse3	db 10,' or Mouse3'      ; DATA XREF: UpDateMenu+7C4o
//@ unk_290E7	db    1			; DATA XREF: UpDateMenu+90Bo
//@ 		db  10h
//@ unk_290E9	db    1			; DATA XREF: UpDateMenu+921o
//@ 		db  11h
//@ aVesa2_0NotFoun	db 19,'VESA 2.0 not found.' ; DATA XREF: UpDateMenu+937o
//@ aVesa2_0Complia	db 27,'VESA 2.0 compliant adapter.' ; DATA XREF: UpDateMenu+948o
//@ aCom		db 3,'COM'              ; DATA XREF: UpDateMenu+B81o
//@ 					; UpDateMenu+E62o
//@ asc_2911F	db 6,'######'           ; DATA XREF: UpDateMenu+BBEo
//@ 					; UpDateMenu+E9Eo
//@ a__9		db 1,'_'                ; DATA XREF: UpDateMenu+CFDo
//@ ; #line	"CSMENU.PAS" 511
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDateMenu	proc far		; CODE XREF: ShowScreen+4DP
//@ 
//@ var_200		= byte ptr -200h
//@ var_100		= byte ptr -100h
//@ var_2		= word ptr -2
//@ 
//@ 		enter	200h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 512
//@ 		mov	Ranking, 0	; bool
//@ ; #line	"CSMENU.PAS" 513
//@ 		mov	ax, MenuMode	; int16_t
//@ ; #line	"CSMENU.PAS" 514
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jnz	short loc_2914B	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 1C2h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 515
//@ 
//@ loc_2914B:				; CODE XREF: UpDateMenu+Fj
//@ 		cmp	ax, 18h		; Compare Two Operands
//@ 		jnz	short loc_29162	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 70Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 516
//@ 
//@ loc_29162:				; CODE XREF: UpDateMenu+26j
//@ 		cmp	ax, 19h		; Compare Two Operands
//@ 		jnz	short loc_29179	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 232h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 517
//@ 
//@ loc_29179:				; CODE XREF: UpDateMenu+3Dj
//@ 		cmp	ax, 1Ah		; Compare Two Operands
//@ 		jnz	short loc_29190	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 28h	; '('   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 518
//@ 
//@ loc_29190:				; CODE XREF: UpDateMenu+54j
//@ 		cmp	ax, 1Bh		; Compare Two Operands
//@ 		jnz	short loc_291A7	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 548h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 519
//@ 
//@ loc_291A7:				; CODE XREF: UpDateMenu+6Bj
//@ 		cmp	ax, 0Fh		; Compare Two Operands
//@ 		jnz	short loc_291BE	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 792h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 520
//@ 
//@ loc_291BE:				; CODE XREF: UpDateMenu+82j
//@ 		cmp	ax, 0Ch		; Compare Two Operands
//@ 		jz	short loc_291C8	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Dh		; Compare Two Operands
//@ 		jnz	short loc_291DA	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_291C8:				; CODE XREF: UpDateMenu+99j
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 68h	; 'h'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 521
//@ 
//@ loc_291DA:				; CODE XREF: UpDateMenu+9Ej
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_291F1	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 10h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 522
//@ 
//@ loc_291F1:				; CODE XREF: UpDateMenu+B5j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_29208	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 7FAh	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 523
//@ 
//@ loc_29208:				; CODE XREF: UpDateMenu+CCj
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jnz	short loc_2921E	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 40h	; '@'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ 		jmp	short loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 524
//@ 
//@ loc_2921E:				; CODE XREF: UpDateMenu+E3j
//@ 		cmp	ax, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jnz	short loc_2924E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 525
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		imul	ax, [di+278h], 0Bh ; Signed Multiply
//@ 		add	ax, 89h	; '‰'   ; Add
//@ 		les	di, PM		; TMenuText*
//@ 		mov	es:[di+898h], ax
//@ ; #line	"CSMENU.PAS" 526
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 892h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 527
//@ 		jmp	short loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 528
//@ 
//@ loc_2924E:				; CODE XREF: UpDateMenu+F9j
//@ 		cmp	ax, 70h	; 'p'   ; Compare Two Operands
//@ 		jnz	short loc_2927E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 529
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		imul	ax, [di+278h], 0Bh ; Signed Multiply
//@ 		add	ax, 72h	; 'r'   ; Add
//@ 		les	di, PM		; TMenuText*
//@ 		mov	es:[di+972h], ax
//@ ; #line	"CSMENU.PAS" 530
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 96Ch	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 531
//@ 		jmp	short loc_29292	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 532
//@ 
//@ loc_2927E:				; CODE XREF: UpDateMenu+129j
//@ 		cmp	ax, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_29292	; Jump if Not Zero (ZF=0)
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 9C8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	DrawMenuRect	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 534
//@ 
//@ loc_29292:				; CODE XREF: UpDateMenu+20j
//@ 					; UpDateMenu+37j ...
//@ 		mov	ax, MenuMode	; int16_t
//@ ; #line	"CSMENU.PAS" 535
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jz	short loc_2929D	; Jump if Zero (ZF=1)
//@ 		jmp	loc_29364	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 536
//@ 
//@ loc_2929D:				; CODE XREF: UpDateMenu+170j
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 539
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, MainMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		push	MainMenu.XSize	; struct TPic
//@ 		push	MainMenu.YSize	; struct TPic
//@ 		push	VgaSeg		; uint16_t
//@ 		les	di, MainMenu.p	; struct TPic
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconD	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 540
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, MainMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		imul	ax, MenuMainY, 14h ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	MainMenu.XSize	; struct TPic
//@ 		push	0Ch
//@ 		push	VgaSeg		; uint16_t
//@ 		push	40h ; '@'
//@ 		les	di, MainMenu.p	; struct TPic
//@ 		mov	ax, es
//@ 		push	ax
//@ 		mov	ax, MainMenu.XSize ; struct TPic
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		imul	ax, MenuMainY, 14h ; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		call	PutIcon		; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 542
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_2932F	; Jump if Not Zero (ZF=0)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_2932F	; Jump if Not Zero (ZF=0)
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_29361	; Jump if Zero (ZF=1)
//@ ; #line	"CSMENU.PAS" 543
//@ 
//@ loc_2932F:				; CODE XREF: UpDateMenu+1F7j
//@ 					; UpDateMenu+1FEj
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, MainMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		add	ax, 28h	; '('   ; Add
//@ 		push	ax
//@ 		push	MainMenu.XSize	; struct TPic
//@ 		push	0Ch
//@ 		push	VgaSeg		; uint16_t
//@ 		push	5Fh ; '_'
//@ 		les	di, MainMenu.p	; struct TPic
//@ 		mov	ax, es
//@ 		push	ax
//@ 		imul	ax, MainMenu.XSize, 28h	; struct TPic
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		call	PutIcon		; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 546
//@ 
//@ loc_29361:				; CODE XREF: UpDateMenu+205j
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 548
//@ 
//@ loc_29364:				; CODE XREF: UpDateMenu+172j
//@ 		cmp	ax, 0Ah		; Compare Two Operands
//@ 		jnz	short loc_293B8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 549
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 79Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 550
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2938A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29386:				; CODE XREF: UpDateMenu+28Bj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2938A:				; CODE XREF: UpDateMenu+25Cj
//@ 		push	0A0h ; ' '
//@ 		imul	ax, n$0, 0Ch	; int16_t
//@ 		add	ax, 50h	; 'P'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 79Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ 		cmp	n$0, 1		; int16_t
//@ 		jnz	short loc_29386	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 551
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 552
//@ 
//@ loc_293B8:				; CODE XREF: UpDateMenu+23Fj
//@ 		cmp	ax, 0Bh		; Compare Two Operands
//@ 		jz	short loc_293C0	; Jump if Zero (ZF=1)
//@ 		jmp	loc_29484	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 553
//@ 
//@ loc_293C0:				; CODE XREF: UpDateMenu+293j
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 30h	; '0'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 556
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, NetMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		push	NetMenu.XSize	; struct TPic
//@ 		push	NetMenu.YSize	; struct TPic
//@ 		push	VgaSeg		; uint16_t
//@ 		les	di, NetMenu.p	; struct TPic
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconD	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 557
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, NetMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		imul	ax, MenuMainY, 14h ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	NetMenu.XSize	; struct TPic
//@ 		push	0Ch
//@ 		push	VgaSeg		; uint16_t
//@ 		push	40h ; '@'
//@ 		les	di, NetMenu.p	; struct TPic
//@ 		mov	ax, es
//@ 		push	ax
//@ 		mov	ax, NetMenu.XSize ; struct TPic
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		imul	ax, MenuMainY, 14h ; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		call	PutIcon		; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 559
//@ 		cmp	VESAPresent, 0	; bool
//@ 		jz	short loc_2944F	; Jump if Zero (ZF=1)
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_29481	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 560
//@ 
//@ loc_2944F:				; CODE XREF: UpDateMenu+31Ej
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, NetMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		add	ax, 3Ch	; '<'   ; Add
//@ 		push	ax
//@ 		push	NetMenu.XSize	; struct TPic
//@ 		push	0Ch
//@ 		push	VgaSeg		; uint16_t
//@ 		push	5Fh ; '_'
//@ 		les	di, NetMenu.p	; struct TPic
//@ 		mov	ax, es
//@ 		push	ax
//@ 		imul	ax, NetMenu.XSize, 3Ch ; struct	TPic
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		call	PutIcon		; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 563
//@ 
//@ loc_29481:				; CODE XREF: UpDateMenu+325j
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 564
//@ 
//@ loc_29484:				; CODE XREF: UpDateMenu+295j
//@ 		cmp	ax, 0Ch		; Compare Two Operands
//@ 		jz	short loc_29491	; Jump if Zero (ZF=1)
//@ 		cmp	ax, 0Dh		; Compare Two Operands
//@ 		jz	short loc_29491	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2952E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 565
//@ 
//@ loc_29491:				; CODE XREF: UpDateMenu+35Fj
//@ 					; UpDateMenu+364j
//@ 		cmp	MenuMode, 0Ch	; int16_t
//@ 		jnz	short loc_294B0	; Jump if Not Zero (ZF=0)
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 48h	; 'H'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ 		jmp	short loc_294C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 566
//@ 
//@ loc_294B0:				; CODE XREF: UpDateMenu+36Ej
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 58h	; 'X'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 567
//@ 
//@ loc_294C6:				; CODE XREF: UpDateMenu+386j
//@ 		push	3Ch ; '<'
//@ 		imul	ax, MenuMainY, 0Ah ; int16_t
//@ 		add	ax, 28h	; '('   ; Add
//@ 		push	ax
//@ 		push	0C8h ; 'È'
//@ 		push	9
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 568
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_294E4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_294E0:				; CODE XREF: UpDateMenu+3E2j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_294E4:				; CODE XREF: UpDateMenu+3B6j
//@ 		push	50h ; 'P'
//@ 		imul	ax, n$0, 0Ah	; int16_t
//@ 		add	ax, 2Ah	; '*'   ; Add
//@ 		push	ax
//@ 		imul	ax, n$0, 28h	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 0F50h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ 		cmp	n$0, 9		; int16_t
//@ 		jnz	short loc_294E0	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 569
//@ 		push	50h ; 'P'
//@ 		imul	ax, MenuMainY, 0Ah ; int16_t
//@ 		add	ax, 2Ah	; '*'   ; Add
//@ 		push	ax
//@ 		imul	ax, MenuMainY, 28h ; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 0F50h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 570
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 571
//@ 
//@ loc_2952E:				; CODE XREF: UpDateMenu+366j
//@ 		cmp	ax, 0Eh		; Compare Two Operands
//@ 		jz	short loc_29536	; Jump if Zero (ZF=1)
//@ 		jmp	loc_296A3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 572
//@ 
//@ loc_29536:				; CODE XREF: UpDateMenu+409j
//@ 		cmp	MenuMainY, 0Bh	; int16_t
//@ 		jnz	short loc_29545	; Jump if Not Zero (ZF=0)
//@ 		mov	i$0, 2Ch ; ','  ; int16_t
//@ 		jmp	short loc_2954B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29545:				; CODE XREF: UpDateMenu+413j
//@ 		mov	i$0, 27h ; '''  ; int16_t
//@ ; #line	"CSMENU.PAS" 573
//@ 
//@ loc_2954B:				; CODE XREF: UpDateMenu+41Bj
//@ 		push	38h ; '8'
//@ 		imul	ax, MenuMainY, 0Ah ; int16_t
//@ 		add	ax, i$0		; int16_t
//@ 		push	ax
//@ 		push	88h ; 'ˆ'
//@ 		push	9
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 574
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 70h	; 'p'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 575
//@ 		push	36h ; '6'
//@ 		push	97h ; '—'
//@ 		push	10Eh
//@ 		push	98h ; '˜'
//@ 		push	14h
//@ 		push	2
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 576
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_29594	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29590:				; CODE XREF: UpDateMenu+493j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_29594:				; CODE XREF: UpDateMenu+466j
//@ 		push	0BAh ; 'º'
//@ 		imul	ax, n$0, 0Ah	; int16_t
//@ 		add	ax, 29h	; ')'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Ah		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 70h	; 'p'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ 		cmp	n$0, 0Ah	; int16_t
//@ 		jnz	short loc_29590	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 577
//@ 		push	0BAh ; 'º'
//@ 		push	9Ch ; 'œ'
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 1A8h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 578
//@ 		push	0BAh ; 'º'
//@ 		imul	ax, MenuMainY, 0Ah ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, i$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Ah		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 70h	; 'p'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBackOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 580
//@ 		push	0C0h ; 'À'
//@ 		push	51h ; 'Q'
//@ 		mov	al, AlwaysRun	; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 581
//@ 		push	0C0h ; 'À'
//@ 		push	5Bh ; '['
//@ 		mov	al, Cocpit	; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 582
//@ 		push	0C0h ; 'À'
//@ 		push	65h ; 'e'
//@ 		mov	al, ReverseMouse ; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 583
//@ 		push	0C0h ; 'À'
//@ 		push	6Fh ; 'o'
//@ 		mov	al, EpisodeReset ; bool
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 584
//@ 		push	0C4h ; 'Ä'
//@ 		push	79h ; 'y'
//@ 		mov	al, FXVolume	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	PutScroller15	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 585
//@ 		push	0C4h ; 'Ä'
//@ 		push	83h ; 'ƒ'
//@ 		mov	al, CDVolume	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	PutScroller15	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 586
//@ 		push	0C4h ; 'Ä'
//@ 		push	8Dh ; ''
//@ 		mov	al, MSsens	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	PutScroller15	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 587
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 588
//@ 
//@ loc_296A3:				; CODE XREF: UpDateMenu+40Bj
//@ 		cmp	ax, 19h		; Compare Two Operands
//@ 		jz	short loc_296AB	; Jump if Zero (ZF=1)
//@ 		jmp	loc_29750	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 589
//@ 
//@ loc_296AB:				; CODE XREF: UpDateMenu+57Ej
//@ 		push	48h ; 'H'
//@ 		imul	ax, MenuMainY, 0Bh ; int16_t
//@ 		add	ax, 40h	; '@'   ; Add
//@ 		push	ax
//@ 		push	5Ch ; '\'
//@ 		push	9
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 590
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 1CAh	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 591
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_296DE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_296DA:				; CODE XREF: UpDateMenu+5DDj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_296DE:				; CODE XREF: UpDateMenu+5B0j
//@ 		push	0A0h ; ' '
//@ 		imul	ax, n$0, 0Bh	; int16_t
//@ 		add	ax, 42h	; 'B'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Ah		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 1CAh	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ 		cmp	n$0, 2		; int16_t
//@ 		jnz	short loc_296DA	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 592
//@ 		push	0A0h ; ' '
//@ 		imul	ax, MenuMainY, 0Bh ; int16_t
//@ 		add	ax, 42h	; 'B'   ; Add
//@ 		push	ax
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Ah		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 1CAh	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBackOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 594
//@ 		push	0AAh ; 'ª'
//@ 		push	42h ; 'B'
//@ 		push	Contrast	; int16_t
//@ 		call	PutScroller	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 595
//@ 		push	0AAh ; 'ª'
//@ 		push	4Dh ; 'M'
//@ 		push	Color		; int16_t
//@ 		call	PutScroller	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 596
//@ 		push	0AAh ; 'ª'
//@ 		push	58h ; 'X'
//@ 		push	Bright		; int16_t
//@ 		call	PutScroller	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 597
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 598
//@ 
//@ loc_29750:				; CODE XREF: UpDateMenu+580j
//@ 		cmp	ax, 0Fh		; Compare Two Operands
//@ 		jnz	short loc_297A4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 599
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 712h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 600
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_29776	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29772:				; CODE XREF: UpDateMenu+677j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_29776:				; CODE XREF: UpDateMenu+648j
//@ 		push	0A0h ; ' '
//@ 		imul	ax, n$0, 0Ch	; int16_t
//@ 		add	ax, 46h	; 'F'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 712h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ 		cmp	n$0, 2		; int16_t
//@ 		jnz	short loc_29772	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 601
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 602
//@ 
//@ loc_297A4:				; CODE XREF: UpDateMenu+62Bj
//@ 		cmp	ax, 18h		; Compare Two Operands
//@ 		jz	short loc_297AC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_29928	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 603
//@ 
//@ loc_297AC:				; CODE XREF: UpDateMenu+67Fj
//@ 		push	22h ; '"'
//@ 		imul	ax, MenuMainY, 9 ; int16_t
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		push	ax
//@ 		push	7Ch ; '|'
//@ 		push	7
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 604
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 550h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 605
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_297DF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_297DB:				; CODE XREF: UpDateMenu+7FAj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSMENU.PAS" 607
//@ 
//@ loc_297DF:				; CODE XREF: UpDateMenu+6B1j
//@ 		push	9Bh ; '›'
//@ 		imul	ax, n$0, 9	; int16_t
//@ 		add	ax, 21h	; '!'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Ah		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 550h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 608
//@ 		push	9Bh ; '›'
//@ 		imul	ax, MenuMainY, 9 ; int16_t
//@ 		add	ax, 21h	; '!'   ; Add
//@ 		push	ax
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 1Ah		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 550h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBackOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 609
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, KbWait	; int16_t
//@ 		jnz	short loc_29847	; Jump if Not Zero (ZF=0)
//@ 		push	0A6h ; '¦'
//@ 		imul	ax, n$0, 9	; int16_t
//@ 		add	ax, 23h	; '#'   ; Add
//@ 		push	ax
//@ 		push	20h ; ' '
//@ 		mov	di, offset a?	; "?"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ 		jmp	loc_2991B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 611
//@ 
//@ loc_29847:				; CODE XREF: UpDateMenu+702j
//@ 		mov	di, n$0		; int16_t
//@ 		mov	al, [di-1360h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 9C0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 612
//@ 		mov	al, Ms1ID	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, n$0		; int16_t
//@ 		jnz	short loc_2989F	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aOrMouse1 ; " or Mouse1"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 613
//@ 
//@ loc_2989F:				; CODE XREF: UpDateMenu+74Ej
//@ 		mov	al, Ms2ID	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, n$0		; int16_t
//@ 		jnz	short loc_298D1	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aOrMouse2 ; " or Mouse2"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 614
//@ 
//@ loc_298D1:				; CODE XREF: UpDateMenu+780j
//@ 		mov	al, ms3id	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, n$0		; int16_t
//@ 		jnz	short loc_29903	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aOrMouse3 ; " or Mouse3"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 615
//@ 
//@ loc_29903:				; CODE XREF: UpDateMenu+7B2j
//@ 		push	0A6h ; '¦'
//@ 		imul	ax, n$0, 9	; int16_t
//@ 		add	ax, 21h	; '!'   ; Add
//@ 		push	ax
//@ 		push	50h ; 'P'
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 617
//@ 
//@ loc_2991B:				; CODE XREF: UpDateMenu+71Cj
//@ 		cmp	n$0, 0Fh	; int16_t
//@ 		jz	short loc_29925	; Jump if Zero (ZF=1)
//@ 		jmp	loc_297DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 618
//@ 
//@ loc_29925:				; CODE XREF: UpDateMenu+7F8j
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 620
//@ 
//@ loc_29928:				; CODE XREF: UpDateMenu+681j
//@ 		cmp	ax, 1Ah		; Compare Two Operands
//@ 		jz	short loc_29930	; Jump if Zero (ZF=1)
//@ 		jmp	loc_299B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 621
//@ 
//@ loc_29930:				; CODE XREF: UpDateMenu+803j
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 18h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 624
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, SklMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		push	ax
//@ 		push	SklMenu.XSize	; struct TPic
//@ 		push	SklMenu.YSize	; struct TPic
//@ 		push	VgaSeg		; uint16_t
//@ 		les	di, SklMenu.p	; struct TPic
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconD	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 625
//@ 		mov	ax, 0A0h ; ' '
//@ 		sub	ax, SklMenu.CenterX ; struct TPic
//@ 		push	ax
//@ 		imul	ax, MenuMainY, 14h ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, MnSY	; int16_t
//@ 		add	ax, 10h		; Add
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	SklMenu.XSize	; struct TPic
//@ 		push	0Ch
//@ 		push	VgaSeg		; uint16_t
//@ 		push	40h ; '@'
//@ 		les	di, SklMenu.p	; struct TPic
//@ 		mov	ax, es
//@ 		push	ax
//@ 		mov	ax, SklMenu.XSize ; struct TPic
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		imul	ax, MenuMainY, 14h ; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		call	PutIcon		; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 628
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 630
//@ 
//@ loc_299B4:				; CODE XREF: UpDateMenu+805j
//@ 		cmp	ax, 1Bh		; Compare Two Operands
//@ 		jz	short loc_299BC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_29ADD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 631
//@ 
//@ loc_299BC:				; CODE XREF: UpDateMenu+88Fj
//@ 		push	3Ah ; ':'
//@ 		imul	ax, MenuMainY, 0Ah ; int16_t
//@ 		add	ax, 31h	; '1'   ; Add
//@ 		push	ax
//@ 		push	0CCh ; 'Ì'
//@ 		push	8
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 632
//@ 		push	3Ah ; ':'
//@ 		push	2Dh ; '-'
//@ 		push	106h
//@ 		push	2Eh ; '.'
//@ 		push	14h
//@ 		push	2
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 633
//@ 		push	3Ah ; ':'
//@ 		push	0A0h ; ' '
//@ 		push	106h
//@ 		push	0A1h ; '¡'
//@ 		push	14h
//@ 		push	2
//@ 		call	DrawBrKey	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 635
//@ 		mov	ColorShift, 1	; uint8_t
//@ 		mov	ColorZero, 0FFh	; uint8_t
//@ ; #line	"CSMENU.PAS" 636
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 23Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 637
//@ 		push	42h ; 'B'
//@ 		push	24h ; '$'
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 268h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 638
//@ 		push	3Eh ; '>'
//@ 		imul	ax, CurVideoMode, 0Ah ;	uint16_t
//@ 		add	ax, 28h	; '('   ; Add
//@ 		push	ax
//@ 		mov	di, offset unk_290E7
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 639
//@ 		push	0F8h ; 'ø'
//@ 		imul	ax, CurVideoMode, 0Ah ;	uint16_t
//@ 		add	ax, 28h	; '('   ; Add
//@ 		push	ax
//@ 		mov	di, offset unk_290E9
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 640
//@ 		cmp	VESA20Compliant, 0 ; bool
//@ 		jnz	short loc_29A6B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 641
//@ 		push	3Eh ; '>'
//@ 		push	0A5h ; '¥'
//@ 		mov	di, offset aVesa2_0NotFoun ; "VESA 2.0 not found."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ 		jmp	short loc_29A7A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 642
//@ 
//@ loc_29A6B:				; CODE XREF: UpDateMenu+930j
//@ 		push	3Eh ; '>'
//@ 		push	0A5h ; '¥'
//@ 		mov	di, offset aVesa2_0Complia ; "VESA 2.0 compliant adapter."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 644
//@ 
//@ loc_29A7A:				; CODE XREF: UpDateMenu+941j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_29A85	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29A81:				; CODE XREF: UpDateMenu+984j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSMENU.PAS" 645
//@ 
//@ loc_29A85:				; CODE XREF: UpDateMenu+957j
//@ 		push	4Ch ; 'L'
//@ 		imul	ax, n$0, 0Ah	; int16_t
//@ 		add	ax, 32h	; '2'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 2Eh		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 23Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrFix	; function near	PASCAL returns void
//@ 		cmp	n$0, 0Ah	; int16_t
//@ 		jnz	short loc_29A81	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 646
//@ 		mov	ColorShift, 21h	; '!' ; uint8_t
//@ 		mov	ColorZero, 0	; uint8_t
//@ ; #line	"CSMENU.PAS" 647
//@ 		push	4Ch ; 'L'
//@ 		imul	ax, MenuMainY, 0Ah ; int16_t
//@ 		add	ax, 32h	; '2'   ; Add
//@ 		push	ax
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 2Eh		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 23Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrFix	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 648
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 650
//@ 
//@ loc_29ADD:				; CODE XREF: UpDateMenu+891j
//@ 		cmp	ax, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jz	short loc_29AE5	; Jump if Zero (ZF=1)
//@ 		jmp	loc_29D22	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 651
//@ 
//@ loc_29AE5:				; CODE XREF: UpDateMenu+9B8j
//@ 		mov	i$0, 3Ch ; '<'  ; int16_t
//@ 		cmp	MenuMainY, 5	; int16_t
//@ 		jl	short loc_29AF8	; Jump if Less (SF!=OF)
//@ 		mov	i$0, 42h ; 'B'  ; int16_t
//@ ; #line	"CSMENU.PAS" 652
//@ 
//@ loc_29AF8:				; CODE XREF: UpDateMenu+9C8j
//@ 		push	3Ch ; '<'
//@ 		imul	ax, MenuMainY, 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, i$0		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	56h ; 'V'
//@ 		push	9
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 653
//@ 		push	3Ah ; ':'
//@ 		push	72h ; 'r'
//@ 		push	0E0h ; 'à'
//@ 		push	1
//@ 		call	HBrline		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 654
//@ 		push	3Ah ; ':'
//@ 		push	74h ; 't'
//@ 		push	0E0h ; 'à'
//@ 		push	14h
//@ 		call	HBrline		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 656
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 802h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 657
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_29B4D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29B49:				; CODE XREF: UpDateMenu+A4Cj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_29B4D:				; CODE XREF: UpDateMenu+A1Fj
//@ 		push	90h ; ''
//@ 		imul	ax, n$0, 0Bh	; int16_t
//@ 		add	ax, 3Ch	; '<'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 802h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ 		cmp	n$0, 4		; int16_t
//@ 		jnz	short loc_29B49	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 658
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+278h]
//@ 		add	ax, 5		; Add
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, 5
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jg	short loc_29BC4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_29B9A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29B96:				; CODE XREF: UpDateMenu+A9Aj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSMENU.PAS" 659
//@ 
//@ loc_29B9A:				; CODE XREF: UpDateMenu+A6Cj
//@ 		push	90h ; ''
//@ 		imul	ax, n$0, 0Bh	; int16_t
//@ 		add	ax, 42h	; 'B'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 802h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jnz	short loc_29B96	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 661
//@ 
//@ loc_29BC4:				; CODE XREF: UpDateMenu+A67j
//@ 		push	90h ; ''
//@ 		imul	ax, MenuMainY, 0Bh ; int16_t
//@ 		add	ax, i$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 802h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBackOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 663
//@ 		push	96h ; '–'
//@ 		push	47h ; 'G'
//@ 		push	50h ; 'P'
//@ 		mov	al, NGMode	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 16h		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 89Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 664
//@ 		push	96h ; '–'
//@ 		push	52h ; 'R'
//@ 		push	50h ; 'P'
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, NGTeam	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, 296h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 665
//@ 		push	96h ; '–'
//@ 		push	5Dh ; ']'
//@ 		push	50h ; 'P'
//@ 		mov	al, NGSkill	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 8DCh	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 666
//@ 		push	96h ; '–'
//@ 		push	68h ; 'h'
//@ 		push	50h ; 'P'
//@ 		mov	al, NGLevel	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, ShortNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 667
//@ 		push	96h ; '–'
//@ 		push	79h ; 'y'
//@ 		push	8Fh ; ''
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 3		; Shift	Logical	Left
//@ 		add	di, 256h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 668
//@ 		cmp	NGCard,	0	; uint8_t
//@ 		ja	short loc_29C9A	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_29D1F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 670
//@ 
//@ loc_29C9A:				; CODE XREF: UpDateMenu+B6Dj
//@ 		push	96h ; '–'
//@ 		push	84h ; '„'
//@ 		push	8Fh ; ''
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCom	; "COM"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, NGPort	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 31h	; '1'   ; Add
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 671
//@ 		push	96h ; '–'
//@ 		push	8Fh ; ''
//@ 		push	8Fh ; ''
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2911F ; "######"
//@ 		push	cs
//@ 		push	di
//@ 		mov	al, NGBaud	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+26Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0C200h
//@ 		mov	dx, 1
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 673
//@ 
//@ loc_29D1F:				; CODE XREF: UpDateMenu+B6Fj
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 675
//@ 
//@ loc_29D22:				; CODE XREF: UpDateMenu+9BAj
//@ 		cmp	ax, 71h	; 'q'   ; Compare Two Operands
//@ 		jz	short loc_29D2A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_29E6F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 676
//@ 
//@ loc_29D2A:				; CODE XREF: UpDateMenu+BFDj
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 974h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 677
//@ 		push	4Ch ; 'L'
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		add	ax, 36h	; '6'   ; Add
//@ 		push	ax
//@ 		push	4Eh ; 'N'
//@ 		push	9
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 678
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_29D5E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29D5A:				; CODE XREF: UpDateMenu+C5Ej
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_29D5E:				; CODE XREF: UpDateMenu+C30j
//@ 		push	96h ; '–'
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		add	ax, 38h	; '8'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 15h		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 974h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ 		cmp	n$0, 2		; int16_t
//@ 		jnz	short loc_29D5A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 679
//@ 		push	96h ; '–'
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		add	ax, 38h	; '8'   ; Add
//@ 		push	ax
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 15h		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 974h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBackOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 680
//@ 		push	0A0h ; ' '
//@ 		push	47h ; 'G'
//@ 		push	0F2h ; 'ò'
//@ 		push	4Fh ; 'O'
//@ 		push	14h
//@ 		call	BrightBar	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 681
//@ 		push	9Fh ; 'Ÿ'
//@ 		push	46h ; 'F'
//@ 		push	0F3h ; 'ó'
//@ 		push	50h ; 'P'
//@ 		push	0
//@ 		push	2
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 683
//@ 		push	0A0h ; ' '
//@ 		push	57h ; 'W'
//@ 		push	0D8h ; 'Ø'
//@ 		push	7Eh ; '~'
//@ 		push	14h
//@ 		call	BrightBar	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 684
//@ 		push	9Fh ; 'Ÿ'
//@ 		push	56h ; 'V'
//@ 		push	0D9h ; 'Ù'
//@ 		push	7Fh ; ''
//@ 		push	0
//@ 		push	2
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 685
//@ 		mov	di, offset NGNick ; char[9] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 686
//@ 		cmp	MenuMainY, 1	; int16_t
//@ 		jnz	short loc_29E3C	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr Time ; int32_t
//@ 		and	al, 7Fh		; Logical AND
//@ 		cmp	al, 40h	; '@'   ; Compare Two Operands
//@ 		jbe	short loc_29E3C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset a__9	; "_"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 687
//@ 
//@ loc_29E3C:				; CODE XREF: UpDateMenu+CE2j
//@ 					; UpDateMenu+CEBj
//@ 		push	0A2h ; '¢'
//@ 		push	48h ; 'H'
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStr		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 688
//@ 		mov	al, NGColor	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	CreateRecolorMap ; function far	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 691
//@ 		push	0A0h ; ' '
//@ 		push	59h ; 'Y'
//@ 		push	PTors.XSize	; struct TPic
//@ 		push	PTors.YSize	; struct TPic
//@ 		les	di, PTors.p	; struct TPic
//@ 		push	es
//@ 		push	di
//@ 		call	PutIconRecolor	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 692
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 694
//@ 
//@ loc_29E6F:				; CODE XREF: UpDateMenu+BFFj
//@ 		cmp	ax, 70h	; 'p'   ; Compare Two Operands
//@ 		jz	short loc_29E77	; Jump if Zero (ZF=1)
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 695
//@ 
//@ loc_29E77:				; CODE XREF: UpDateMenu+D4Aj
//@ 		mov	i$0, 50h ; 'P'  ; int16_t
//@ 		cmp	MenuMainY, 1	; int16_t
//@ 		jl	short loc_29E8A	; Jump if Less (SF!=OF)
//@ 		mov	i$0, 56h ; 'V'  ; int16_t
//@ ; #line	"CSMENU.PAS" 696
//@ 
//@ loc_29E8A:				; CODE XREF: UpDateMenu+D5Aj
//@ 		push	3Ch ; '<'
//@ 		imul	ax, MenuMainY, 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		mov	ax, i$0		; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		add	ax, dx		; Add
//@ 		push	ax
//@ 		push	56h ; 'V'
//@ 		push	9
//@ 		call	DrawMenuBar	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 697
//@ 		push	3Ah ; ':'
//@ 		push	5Ah ; 'Z'
//@ 		push	0E0h ; 'à'
//@ 		push	1
//@ 		call	HBrline		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 698
//@ 		push	3Ah ; ':'
//@ 		push	5Ch ; '\'
//@ 		push	0E0h ; 'à'
//@ 		push	14h
//@ 		call	HBrline		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 700
//@ 		push	0A0h ; ' '
//@ 		push	MnSY		; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 90Ch	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrCenter	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 701
//@ 		push	90h ; ''
//@ 		push	50h ; 'P'
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 91Ch	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 702
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+278h]
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jg	short loc_29F32	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_29F08	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_29F04:				; CODE XREF: UpDateMenu+E08j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSMENU.PAS" 703
//@ 
//@ loc_29F08:				; CODE XREF: UpDateMenu+DDAj
//@ 		push	90h ; ''
//@ 		imul	ax, n$0, 0Bh	; int16_t
//@ 		add	ax, 56h	; 'V'   ; Add
//@ 		push	ax
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 90Ch	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBack	; function near	PASCAL returns void
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jnz	short loc_29F04	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 705
//@ 
//@ loc_29F32:				; CODE XREF: UpDateMenu+DD5j
//@ 		push	90h ; ''
//@ 		imul	ax, MenuMainY, 0Bh ; int16_t
//@ 		add	ax, i$0		; int16_t
//@ 		push	ax
//@ 		mov	ax, MenuMainY	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 90Ch	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutStrBackOn	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 707
//@ 		push	96h ; '–'
//@ 		push	61h ; 'a'
//@ 		push	8Fh ; ''
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 3		; Shift	Logical	Left
//@ 		add	di, 256h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 708
//@ 		cmp	NGCard,	0	; uint8_t
//@ 		ja	short loc_29F7C	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	locret_29FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 710
//@ 
//@ loc_29F7C:				; CODE XREF: UpDateMenu+E4Fj
//@ 		push	96h ; '–'
//@ 		push	6Ch ; 'l'
//@ 		push	8Fh ; ''
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCom	; "COM"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, NGPort	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		add	ax, 31h	; '1'   ; Add
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 711
//@ 		push	96h ; '–'
//@ 		push	77h ; 'w'
//@ 		push	8Fh ; ''
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2911F ; "######"
//@ 		push	cs
//@ 		push	di
//@ 		mov	al, NGBaud	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di+26Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 0C200h
//@ 		mov	dx, 1
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	PutStringFloat	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 715
//@ 
//@ locret_29FFF:				; CODE XREF: UpDateMenu:loc_29361j
//@ 					; UpDateMenu+28Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ UpDateMenu	endp
//@ 
//@ ; #line	"CSMENU.PAS" 720
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpdatePause	proc far		; CODE XREF: ShowVesaScreen+BP
//@ 					; ShowScreen+18P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSMENU.PAS" 722
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		sub	ax, m_pause.CenterX ; struct TPic
//@ 		push	ax
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		sub	ax, 1Eh		; Integer Subtraction
//@ 		push	ax
//@ 		push	m_pause.XSize	; struct TPic
//@ 		push	m_pause.YSize	; struct TPic
//@ 		push	VgaSeg		; uint16_t
//@ 		push	0
//@ 		les	di, m_pause.p	; struct TPic
//@ 		push	es
//@ 		push	di
//@ 		call	PutIcon		; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 723
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ UpdatePause	endp
//@ 
//@ ; #line	"CSMENU.PAS" 730
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShiftRect	proc near
//@ 
//@ var_4		= word ptr -4
//@ var_2		= word ptr -2
//@ arg_0		= word ptr  4
//@ M		= dword	ptr  6		; struct MenuRect
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+var_2]
//@ 		les	di, [bp+M]	; struct MenuRect
//@ 		add	es:[di], ax	; Add
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+var_4]
//@ 		les	di, [bp+M]	; struct MenuRect
//@ 		add	es:[di+2], ax	; Add
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+var_2]
//@ 		les	di, [bp+M]	; struct MenuRect
//@ 		add	es:[di+4], ax	; Add
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, ss:[di+var_4]
//@ 		les	di, [bp+M]	; struct MenuRect
//@ 		add	es:[di+6], ax	; Add
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ ShiftRect	endp
//@ 
//@ ; #line	"CSMENU.PAS" 732
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CorrectMenuPos	proc far		; CODE XREF: ProcessMenu+671P
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 733
//@ 		jmp	locret_2A126	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 734
//@ 		db 0A1h	; ¡
//@ 		db  46h	; F
//@ 		db 0F5h	; õ
//@ 		db  3Bh	; ;
//@ 		db    6
//@ 		db  48h	; H
//@ 		db 0F5h	; õ
//@ 		db  75h	; u
//@ 		db    3
//@ 		db 0E9h	; é
//@ 		db 0A9h	; ©
//@ 		db    0
//@ ; #line	"CSMENU.PAS" 735
//@ 		db  83h	; ƒ
//@ 		db  3Eh	; >
//@ 		db  46h	; F
//@ 		db 0F5h	; õ
//@ 		db    2
//@ 		db  75h	; u
//@ 		db  0Ch
//@ 		db 0C7h	; Ç
//@ 		db  46h	; F
//@ 		db 0FEh	; þ
//@ 		db 0A0h	;  
//@ 		db    0
//@ 		db 0C7h	; Ç
//@ 		db  46h	; F
//@ 		db 0FCh	; ü
//@ 		db  3Ch	; <
//@ 		db    0
//@ 		db 0EBh	; ë
//@ 		db  0Ah
//@ ; #line	"CSMENU.PAS" 736
//@ 		db 0C7h	; Ç
//@ 		db  46h	; F
//@ 		db 0FEh	; þ
//@ 		db  60h	; `
//@ 		db 0FFh
//@ 		db 0C7h	; Ç
//@ 		db  46h	; F
//@ 		db 0FCh	; ü
//@ 		db 0C4h	; Ä
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 738
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  10h
//@ 		db    0
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  84h	; „
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 739
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  28h	; (
//@ 		db    0
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  76h	; v
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 740
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  40h	; @
//@ 		db    0
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  68h	; h
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 741
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  68h	; h
//@ 		db    0
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  5Ah	; Z
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 742
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db 0C2h	; Â
//@ 		db    1
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  4Ch	; L
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 743
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  32h	; 2
//@ 		db    2
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  3Eh	; >
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 744
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  0Ah
//@ 		db    7
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  30h	; 0
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 745
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  92h	; ’
//@ 		db    7
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  22h	; "
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 746
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db 0FAh	; ú
//@ 		db    7
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db  14h
//@ 		db 0FFh
//@ ; #line	"CSMENU.PAS" 747
//@ 		db 0C4h	; Ä
//@ 		db  3Eh	; >
//@ 		db  1Ah
//@ 		db  13h
//@ 		db  81h	; 
//@ 		db 0C7h	; Ç
//@ 		db  92h	; ’
//@ 		db    8
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  55h	; U
//@ 		db 0E8h	; è
//@ 		db    6
//@ 		db 0FFh
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 748
//@ 
//@ locret_2A126:				; CODE XREF: CorrectMenuPos+4j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ CorrectMenuPos	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a____1		db 4,' ...'             ; DATA XREF: ScanSavedNames:loc_2A149o
//@ 					; ScanSavedNames+F9o
//@ a@_20		db 2,'@#'               ; DATA XREF: ScanSavedNames+40o
//@ 					; ScanSavedNames+8Do
//@ aChasm_3	db 5,'CHASM'            ; DATA XREF: ScanSavedNames+30o
//@ 					; ScanSavedNames+7Do
//@ a_sav_1		db 4,'.SAV'             ; DATA XREF: ScanSavedNames+5Bo
//@ 					; ScanSavedNames+A8o
//@ ; #line	"CSMENU.PAS" 754
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScanSavedNames	proc far		; CODE XREF: ProcessMenu+53FP
//@ 					; ProcessPreKeyboard+151P ...
//@ 
//@ var_482		= byte ptr -482h
//@ var_382		= byte ptr -382h
//@ var_282		= byte ptr -282h
//@ var_182		= byte ptr -182h
//@ f		= byte ptr -82h		; FILE
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	482h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSMENU.PAS" 755
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2A149	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A146:				; CODE XREF: ScanSavedNames+11Bj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSMENU.PAS" 757
//@ 
//@ loc_2A149:				; CODE XREF: ScanSavedNames+9j
//@ 		mov	di, offset a____1 ; " ..."
//@ 		push	cs
//@ 		push	di
//@ 		imul	ax, [bp+n], 28h	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 0F50h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 758
//@ 		lea	di, [bp+var_282] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_3 ; "CHASM"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_182] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_20 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_sav_1 ; ".SAV"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	ExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_2A1AC	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2A250	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 760
//@ 
//@ loc_2A1AC:				; CODE XREF: ScanSavedNames+6Cj
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_482] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_3 ; "CHASM"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_382] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_20 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset a_sav_1 ; ".SAV"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"CSMENU.PAS" 761
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ ; #line	"CSMENU.PAS" 762
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		imul	ax, [bp+n], 28h	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 0F50h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	28h ; '('
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSMENU.PAS" 763
//@ 		lea	di, [bp+f]	; FILE
//@ 		push	ss
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ ; #line	"CSMENU.PAS" 764
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_2A250	; Jump if Zero (ZF=1)
//@ 		mov	di, offset a____1 ; " ..."
//@ 		push	cs
//@ 		push	di
//@ 		imul	ax, [bp+n], 28h	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 0F50h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	27h ; '''
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 766
//@ 
//@ loc_2A250:				; CODE XREF: ScanSavedNames+6Ej
//@ 					; ScanSavedNames+F7j
//@ 		cmp	[bp+n],	9	; int16_t
//@ 		jz	short locret_2A259 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2A146	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 767
//@ 
//@ locret_2A259:				; CODE XREF: ScanSavedNames+119j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ScanSavedNames	endp
//@ 
//@ ; #line	"CSMENU.PAS" 771
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadPicFromCel	proc near		; CODE XREF: LoadMenuResourses+862p
//@ 					; LoadMenuResourses+86Fp ...
//@ 
//@ var_104		= dword	ptr -104h
//@ FName		= byte ptr -100h	; char[256] // Pascal string
//@ M		= dword	ptr  4		; struct TPic
//@ arg_4		= dword	ptr  8
//@ 
//@ 		enter	104h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_4]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ 		les	di, [bp+M]	; struct TPic
//@ 		mov	word ptr [bp+var_104], di
//@ 		mov	word ptr [bp+var_104+2], es
//@ ; #line	"CSMENU.PAS" 773
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 774
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_104] ; Load	Full Pointer to	ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSMENU.PAS" 775
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_104] ; Load	Full Pointer to	ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSMENU.PAS" 776
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_104] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 2		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSMENU.PAS" 777
//@ 		les	di, [bp+var_104] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSMENU.PAS" 778
//@ 		add	di, 6		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_104] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di]
//@ 		mul	word ptr es:[di+2] ; Unsigned Multiplication of	AL or AX
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 779
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 780
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_104] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_104] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di]
//@ 		mul	word ptr es:[di+2] ; Unsigned Multiplication of	AL or AX
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSMENU.PAS" 781
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 783
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ LoadPicFromCel	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aMenuMenu_txt	db 13,'MENU\menu.txt'   ; DATA XREF: LoadMenuResourses+16o
//@ aMenuM_tile1_ce	db 16,'menu\m_tile1.cel' ; DATA XREF: LoadMenuResourses+6EBo
//@ asc_2A360	db 6,'##:   '           ; DATA XREF: LoadMenuResourses+75Bo
//@ asc_2A367	db 3,'###'              ; DATA XREF: LoadMenuResourses+777o
//@ unk_2A36B	db    1			; DATA XREF: LoadMenuResourses+797o
//@ 		db  12h
//@ asc_2A36D	db 5,'###  '            ; DATA XREF: LoadMenuResourses+7A7o
//@ aFlat		db 6,' FLAT '           ; DATA XREF: LoadMenuResourses+7EEo
//@ aBanked		db 6,'BANKED'           ; DATA XREF: LoadMenuResourses+817o
//@ aMenuM_main_cel	db 15,'menu\m_main.cel' ; DATA XREF: LoadMenuResourses:loc_2AC2Ao
//@ aMenuM_new_cel	db 14,'menu\m_new.cel'  ; DATA XREF: LoadMenuResourses+865o
//@ aMenuM_netwrk_c	db 17,'menu\m_netwrk.cel' ; DATA XREF: LoadMenuResourses+872o
//@ aMenuM_pause_ce	db 16,'menu\m_pause.cel' ; DATA XREF: LoadMenuResourses+87Fo
//@ aMenuPtors_cel	db 14,'menu\ptors.cel'  ; DATA XREF: LoadMenuResourses+88Co
//! ; #line	"CSMENU.PAS" 788
//! 
//! ; =============== S U B	R O U T	I N E =======================================
//! 
//! ; function near	PASCAL returns void
//! ; Attributes: bp-based frame
//! 
//! LoadMenuResourses proc near		; CODE XREF: $CsMenuInit+3p
static void LoadMenuResourses()
{
//! 
//! var_306		= byte ptr -306h
//! var_206		= byte ptr -206h
//! var_106		= byte ptr -106h
//! var_6		= dword	ptr -6
//! var_2		= word ptr -2
//! 
//! 		enter	306h, 0		; Make Stack Frame for Procedure Parameters
//! ; #line	"CSMENU.PAS" 789
//! 		mov	di, offset PM	; TMenuText*
//! 		push	ds
//! 		push	di
//! 		push	10E0h
//! 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 790
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aMenuMenu_txt ; "MENU\\menu.txt"
//@ 		push	cs
//@ 		push	di
//@ 		call	TOpen		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 791
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 10h		; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 792
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		les	di, PM		; TMenuText*
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 793
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 28h	; '('   ; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 794
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 18h		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 795
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 40h	; '@'   ; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 796
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 30h	; '0'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 797
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 68h	; 'h'   ; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 798
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 48h	; 'H'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 799
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 58h	; 'X'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 801
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 1C2h	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 802
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A5E3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A5DF:				; CODE XREF: LoadMenuResourses+238j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A5E3:				; CODE XREF: LoadMenuResourses+20Bj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, n$0, 1Ah	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 70h	; 'p'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	19h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 0Ch	; int16_t
//@ 		jnz	short loc_2A5DF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 804
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 232h	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 805
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A65E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A65A:				; CODE XREF: LoadMenuResourses+2B3j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A65E:				; CODE XREF: LoadMenuResourses+286j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, n$0, 1Ah	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 1CAh	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	19h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 3		; int16_t
//@ 		jnz	short loc_2A65A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 807
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 548h	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 808
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A6D9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A6D5:				; CODE XREF: LoadMenuResourses+32Ej
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A6D9:				; CODE XREF: LoadMenuResourses+301j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, n$0, 2Eh	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 23Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2Dh ; '-'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 0Ch	; int16_t
//@ 		jnz	short loc_2A6D5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 810
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 70Ah	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 811
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A754	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A750:				; CODE XREF: LoadMenuResourses+3A9j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A754:				; CODE XREF: LoadMenuResourses+37Cj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, n$0, 1Ah	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 550h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	19h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 10h	; int16_t
//@ 		jnz	short loc_2A750	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 813
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 792h	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 814
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A7CF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A7CB:				; CODE XREF: LoadMenuResourses+425j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A7CF:				; CODE XREF: LoadMenuResourses+3F7j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 712h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	1Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 3		; int16_t
//@ 		jnz	short loc_2A7CB	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 816
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 7FAh	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 817
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A84B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A847:				; CODE XREF: LoadMenuResourses+4A1j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A84B:				; CODE XREF: LoadMenuResourses+473j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 79Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	1Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 2		; int16_t
//@ 		jnz	short loc_2A847	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 819
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 892h	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 821
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A8C7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A8C3:				; CODE XREF: LoadMenuResourses+51Dj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A8C7:				; CODE XREF: LoadMenuResourses+4EFj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 802h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 8		; int16_t
//@ 		jnz	short loc_2A8C3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 822
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A8FC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A8F8:				; CODE XREF: LoadMenuResourses+551j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A8FC:				; CODE XREF: LoadMenuResourses+524j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, n$0, 16h	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 89Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	15h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 2		; int16_t
//@ 		jnz	short loc_2A8F8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 823
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A930	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A92C:				; CODE XREF: LoadMenuResourses+586j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A930:				; CODE XREF: LoadMenuResourses+558j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 8DCh	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 2		; int16_t
//@ 		jnz	short loc_2A92C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 824
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 96Ch	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 825
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2A9AC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2A9A8:				; CODE XREF: LoadMenuResourses+602j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2A9AC:				; CODE XREF: LoadMenuResourses+5D4j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 90Ch	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 5		; int16_t
//@ 		jnz	short loc_2A9A8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 827
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, 9C8h	; Add
//@ 		mov	word ptr [bp+var_6+2], di
//@ 		mov	[bp+var_2], es
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_6+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 828
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2AA28	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2AA24:				; CODE XREF: LoadMenuResourses+67Dj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2AA28:				; CODE XREF: LoadMenuResourses+650j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, n$0, 15h	; int16_t
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 974h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	14h
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 3		; int16_t
//@ 		jnz	short loc_2AA24	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 830
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSMENU.PAS" 831
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_2AA67	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2AA63:				; CODE XREF: LoadMenuResourses+6BDj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2AA67:				; CODE XREF: LoadMenuResourses+68Fj
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 9C0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Fh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		cmp	n$0, 58h ; 'X'  ; int16_t
//@ 		jnz	short loc_2AA63	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSMENU.PAS" 832
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4Text	; Close(var f: Text)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 833
//@ 		call	ScanSavedNames	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 834
//@ 		mov	KbWait,	0FFFFh	; int16_t
//@ ; #line	"CSMENU.PAS" 836
//@ 		mov	di, offset MenuTiler ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 837
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aMenuM_tile1_ce ; "menu\\m_tile1.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 838
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 839
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, MenuTiler	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSMENU.PAS" 840
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSMENU.PAS" 842
//@ 		mov	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		mov	[bp+var_2], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jle	short loc_2AB0D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_2AC2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2AB0D:				; CODE XREF: LoadMenuResourses+736j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2AB16	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2AB12:				; CODE XREF: LoadMenuResourses+855j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSMENU.PAS" 843
//@ 
//@ loc_2AB16:				; CODE XREF: LoadMenuResourses+73Ej
//@ 		imul	di, n$0, 0Dh	; int16_t
//@ 		add	di, 0F42Fh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSMENU.PAS" 845
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2A360 ; "##:   "
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2A367 ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+2]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset unk_2A36B
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_306] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2A36D ; "###  "
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
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
//@ ; #line	"CSMENU.PAS" 847
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Ch], 0	; Compare Two Operands
//@ 		jz	short loc_2ABD9	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aFlat ; " FLAT "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short loc_2AC00	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2ABD9:				; CODE XREF: LoadMenuResourses+7DCj
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset aBanked ; "BANKED"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 848
//@ 
//@ loc_2AC00:				; CODE XREF: LoadMenuResourses+805j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	ax, 2Eh		; Signed Multiply
//@ 		les	di, PM		; TMenuText*
//@ 		add	di, ax		; Add
//@ 		add	di, 23Ah	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2Dh ; '-'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSMENU.PAS" 849
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jz	short loc_2AC2A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2AB12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSMENU.PAS" 851
//@ 
//@ loc_2AC2A:				; CODE XREF: LoadMenuResourses+738j
//@ 					; LoadMenuResourses+853j
//@ 		mov	di, offset aMenuM_main_cel ; "menu\\m_main.cel"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset MainMenu ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		call	LoadPicFromCel	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 852
//@ 		mov	di, offset aMenuM_new_cel ; "menu\\m_new.cel"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset SklMenu ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		call	LoadPicFromCel	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 853
//@ 		mov	di, offset aMenuM_netwrk_c ; "menu\\m_netwrk.cel"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset NetMenu ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		call	LoadPicFromCel	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 854
//@ 		mov	di, offset aMenuM_pause_ce ; "menu\\m_pause.cel"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset m_pause ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		call	LoadPicFromCel	; function near	PASCAL returns void
//@ ; #line	"CSMENU.PAS" 855
//@ 		mov	di, offset aMenuPtors_cel ; "menu\\ptors.cel"
//@ 		push	cs
//@ 		push	di
//@ 		mov	di, offset PTors ; struct TPic
//@ 		push	ds
//@ 		push	di
//@ 		call	LoadPicFromCel	; function near	PASCAL returns void
//! ; #line	"CSMENU.PAS" 856
//! 		leave			; High Level Procedure Exit
//! 		retn			; Return Near from Procedure
//! LoadMenuResourses endp
}
//! 
//! ; #line	"CSMENU.PAS" 861
//! 
//! ; =============== S U B	R O U T	I N E =======================================
//! 
//! ; Attributes: bp-based frame
//! 
//! $CsMenuInit	proc far		; CODE XREF: PROGRAM+1EP
void CsMenuInit()
{
//! 		push	bp
//! 		mov	bp, sp
//! ; #line	"CSMENU.PAS" 862
//! 		call	LoadMenuResourses ; function near PASCAL returns void
    LoadMenuResourses();
//! ; #line	"CSMENU.PAS" 863
//! 		leave			; High Level Procedure Exit
//! 		retf			; Return Far from Procedure
//! $CsMenuInit	endp
}
