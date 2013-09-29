
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

#include "soundip/soundip.h"

//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 139
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddAmbient	proc far		; CODE XREF: ContinueAmbient+51P
//@ 					; ContinueAmbient+70P ...
//@ 
//@ var_A		= dword	ptr -0Ah
//@ w		= word ptr -6		; uint16_t
//@ v		= word ptr -4		; uint16_t
//@ ACh		= word ptr -2		; int16_t
//@ vy		= word ptr  6		; int16_t
//@ vx		= word ptr  8		; int16_t
//@ vc		= word ptr  0Ah		; int16_t
//@ vol		= word ptr  0Ch		; int16_t
//@ amb		= word ptr  0Eh		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 140
//@ 		mov	[bp+ACh], 0FFh	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 141
//@ 		mov	al, MaxVoice	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	word ptr [bp+var_A+2], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, word ptr [bp+var_A+2] ; Compare Two	Operands
//@ 		jg	short loc_31A0E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$1, ax		; int16_t
//@ 		jmp	short loc_319F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_319EF:				; CODE XREF: AddAmbient+3Aj
//@ 		inc	n$1		; int16_t
//@ 
//@ loc_319F3:				; CODE XREF: AddAmbient+1Bj
//@ 		imul	di, n$1, 0Eh	; int16_t
//@ 		cmp	word ptr [di-878h], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_31A06	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, n$1		; int16_t
//@ 		mov	[bp+ACh], ax	; int16_t
//@ 
//@ loc_31A06:				; CODE XREF: AddAmbient+2Cj
//@ 		mov	ax, n$1		; int16_t
//@ 		cmp	ax, word ptr [bp+var_A+2] ; Compare Two	Operands
//@ 		jnz	short loc_319EF	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 142
//@ 
//@ loc_31A0E:				; CODE XREF: AddAmbient+16j
//@ 		cmp	[bp+ACh], 0FFh	; int16_t
//@ 		jnz	short loc_31A18	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_31B5F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 144
//@ 
//@ loc_31A18:				; CODE XREF: AddAmbient+41j
//@ 		imul	di, [bp+amb], 0Eh ; int16_t
//@ 		add	di, 0F5C2h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 146
//@ 		mov	ax, es:[di]
//@ 		or	ax, es:[di+2]	; Logical Inclusive OR
//@ 		jnz	short loc_31A48	; Jump if Not Zero (ZF=0)
//@ 		push	7D0h
//@ 		call	@Sound$q4Word	; function far PASCAL returns void
//@ 		push	32h ; '2'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	@NoSound$qv	; function far PASCAL returns void
//@ 		jmp	locret_31B5F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 147
//@ 
//@ loc_31A48:				; CODE XREF: AddAmbient+5Dj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+0Ah]
//@ 		mul	[bp+vol]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	[bp+v],	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 148
//@ 		cmp	word ptr es:[di+4], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_31A62	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_31B5F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 149
//@ 
//@ loc_31A62:				; CODE XREF: AddAmbient+8Bj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		sub	ax, es:[di+8]	; Integer Subtraction
//@ 		mov	[bp+w],	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 150
//@ 		cmp	[bp+w],	400h	; uint16_t
//@ 		jb	short loc_31A9E	; Jump if Below	(CF=1)
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		mov	ax, [bp+vc]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	0
//@ 		push	200h
//@ 		call	movsw$0		; function far PASCAL returns void
//@ 		jmp	short loc_31AF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 153
//@ 
//@ loc_31A9E:				; CODE XREF: AddAmbient+A3j
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		push	ax
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+8]
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+vc]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+w]		; uint16_t
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 154
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+vc]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		push	ax
//@ 		mov	di, [bp+w]	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, 400h
//@ 		sub	ax, [bp+w]	; uint16_t
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 156
//@ 
//@ loc_31AF6:				; CODE XREF: AddAmbient+CAj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+8], 400h ; Add
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 157
//@ 		mov	ax, es:[di+8]
//@ 		cmp	ax, es:[di+4]	; Compare Two Operands
//@ 		jb	short loc_31B11	; Jump if Below	(CF=1)
//@ 		mov	ax, es:[di+4]
//@ 		sub	es:[di+8], ax	; Integer Subtraction
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 160
//@ 
//@ loc_31B11:				; CODE XREF: AddAmbient+135j
//@ 		imul	di, [bp+ACh], 0Eh ; int16_t
//@ 		add	di, 0F782h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 162
//@ 		mov	ax, [bp+vc]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di]
//@ 		mov	dx, es:[di+2]
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 163
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 164
//@ 		mov	ax, [bp+v]	; uint16_t
//@ 		mov	es:[di+8], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 165
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 166
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		mov	es:[di+0Ah], ax
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 168
//@ 
//@ locret_31B5F:				; CODE XREF: AddAmbient+43j
//@ 					; AddAmbient+73j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ AddAmbient	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 172
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ContinueAmbient	proc far		; CODE XREF: NextStereoBlock16+10P
//@ 					; NextStereoBlock+34P ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 173
//@ 		cmp	DisableALL, 0	; bool
//@ 		jz	short loc_31B70	; Jump if Zero (ZF=1)
//@ 		jmp	locret_31C33	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 175
//@ 
//@ loc_31B70:				; CODE XREF: ContinueAmbient+8j
//@ 		cmp	CurAmbient, 0FFFFh ; int16_t
//@ 		jnz	short loc_31B7A	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_31C07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 177
//@ 
//@ loc_31B7A:				; CODE XREF: ContinueAmbient+12j
//@ 		mov	ax, CurAmbient	; int16_t
//@ 		cmp	ax, PreAmbient	; int16_t
//@ 		jz	short loc_31B97	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 178
//@ 		cmp	PAmbVol, 1	; uint8_t
//@ 		jbe	short loc_31B91	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		sub	PAmbVol, 2	; uint8_t
//@ 		jmp	short loc_31B97	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_31B91:				; CODE XREF: ContinueAmbient+25j
//@ 		mov	ax, CurAmbient	; int16_t
//@ 		mov	PreAmbient, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 180
//@ 
//@ loc_31B97:				; CODE XREF: ContinueAmbient+1Ej
//@ 					; ContinueAmbient+2Cj
//@ 		cmp	CAmbVol, 30h ; '0' ; uint8_t
//@ 		jnb	short loc_31BA3	; Jump if Not Below (CF=0)
//@ 		add	CAmbVol, 2	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 182
//@ 
//@ loc_31BA3:				; CODE XREF: ContinueAmbient+39j
//@ 		push	CurAmbient	; int16_t
//@ 		mov	al, CAmbVol	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	122h
//@ 		push	0
//@ 		push	0
//@ 		call	AddAmbient	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 183
//@ 		mov	ax, PreAmbient	; int16_t
//@ 		cmp	ax, CurAmbient	; int16_t
//@ 		jz	short loc_31BDA	; Jump if Zero (ZF=1)
//@ 		push	PreAmbient	; int16_t
//@ 		mov	al, PAmbVol	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	123h
//@ 		push	0
//@ 		push	0
//@ 		call	AddAmbient	; function far PASCAL returns void
//@ 		jmp	short loc_31C07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 185
//@ 
//@ loc_31BDA:				; CODE XREF: ContinueAmbient+5Dj
//@ 		imul	di, CurAmbient,	0Eh ; int16_t
//@ 		cmp	word ptr [di-0A32h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_31C07	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 186
//@ 		push	258h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		cmp	ax, 252h	; Compare Two Operands
//@ 		jbe	short loc_31C07	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 187
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		imul	di, CurAmbient,	0Eh ; int16_t
//@ 		push	word ptr [di-0A32h]
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 190
//@ 
//@ loc_31C07:				; CODE XREF: ContinueAmbient+14j
//@ 					; ContinueAmbient+75j ...
//@ 		cmp	ObjAmbU.Ambid, 0 ; struct ObjAmb$Type
//@ 		jle	short locret_31C33 ; Jump if Less or Equal (ZF=1 | SF!=OF)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 191
//@ 		push	ObjAmbU.Ambid	; struct ObjAmb$Type
//@ 		mov	ax, ObjAmbU.R	; struct ObjAmb$Type
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 18h
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, 30h	; '0'
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		push	124h
//@ 		push	ObjAmbU.osx	; struct ObjAmb$Type
//@ 		push	ObjAmbU.osy	; struct ObjAmb$Type
//@ 		call	AddAmbient	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 193
//@ 
//@ locret_31C33:				; CODE XREF: ContinueAmbient+Aj
//@ 					; ContinueAmbient+A9j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ContinueAmbient	endp
//@ 

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

#include "soundip/soundip.h"

//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 202
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ RegisterCard	proc far		; CODE XREF: PROGRAM+73AP
//@ 
//@ RegisterCard	= byte ptr -1		; bool
//@ DMAn		= byte ptr  6		; uint8_t
//@ IRQn		= byte ptr  8		; uint8_t
//@ PORTn		= word ptr  0Ah		; uint16_t
//@ CardT		= byte ptr  0Ch		; uint8_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 203
//@ 		mov	al, [bp+CardT]	; uint8_t
//@ 		mov	sCard, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 204
//@ 		mov	ax, [bp+PORTn]	; uint16_t
//@ 		mov	sBase, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 205
//@ 		mov	al, [bp+IRQn]	; uint8_t
//@ 		mov	sIRQ, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 206
//@ 		mov	al, [bp+DMAn]	; uint8_t
//@ 		mov	sDMA, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 207
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 208
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_33889	; Jump if Zero (ZF=1)
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_3388F	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_33889:				; CODE XREF: RegisterCard+21j
//@ 		mov	[bp+RegisterCard], 1 ; bool
//@ 		jmp	short loc_338B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 209
//@ 
//@ loc_3388F:				; CODE XREF: RegisterCard+25j
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jz	short loc_3389B	; Jump if Zero (ZF=1)
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jz	short loc_3389B	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_338A5	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_3389B:				; CODE XREF: RegisterCard+2Fj
//@ 					; RegisterCard+33j
//@ 		call	TestSBlaster	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		mov	[bp+RegisterCard], al ;	bool
//@ 		jmp	short loc_338B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 210
//@ 
//@ loc_338A5:				; CODE XREF: RegisterCard+37j
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short loc_338B3	; Jump if Not Zero (ZF=0)
//@ 		call	TestGUS		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		mov	[bp+RegisterCard], al ;	bool
//@ 		jmp	short loc_338B7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 211
//@ 
//@ loc_338B3:				; CODE XREF: RegisterCard+45j
//@ 		mov	[bp+RegisterCard], 0 ; bool
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 213
//@ 
//@ loc_338B7:				; CODE XREF: RegisterCard+2Bj
//@ 					; RegisterCard+41j ...
//@ 		mov	al, [bp+RegisterCard] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ RegisterCard	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 219
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetVolumes	proc far		; CODE XREF: LoadConfig+2C0P
//@ 					; ProcessMenu+26CP ...
//@ 
//@ w		= word ptr -2		; uint16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 220
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 221
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jz	short loc_338CD	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_338EF	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 223
//@ 
//@ loc_338CD:				; CODE XREF: SetVolumes+9j
//@ 		push	4
//@ 		mov	al, FXVolume	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 11h		; Signed Multiply
//@ 		push	ax
//@ 		call	WriteMixer	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 224
//@ 		push	28h ; '('
//@ 		mov	al, CDVolume	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 11h		; Signed Multiply
//@ 		push	ax
//@ 		call	WriteMixer	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 225
//@ 		jmp	short locret_33916 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 226
//@ 
//@ loc_338EF:				; CODE XREF: SetVolumes+Dj
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short locret_33916 ; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 228
//@ 		mov	al, FXVolume	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	ax, 665h	; Signed Multiply
//@ 		add	ax, 0A000h	; Add
//@ 		mov	[bp+w],	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 229
//@ 		push	0
//@ 		push	[bp+w]		; uint16_t
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 230
//@ 		push	1
//@ 		push	[bp+w]		; uint16_t
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 233
//@ 
//@ locret_33916:				; CODE XREF: SetVolumes+2Fj
//@ 					; SetVolumes+33j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ SetVolumes	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 238
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpDatePlayerPos	proc far		; CODE XREF: DoGame+9DAP
//@ 					; PlayBrifing+224P
//@ 
//@ var_2		= word ptr -2
//@ _psin		= word ptr  6		; int16_t
//@ _pcos		= word ptr  8		; int16_t
//@ _py		= word ptr  0Ah		; int16_t
//@ _px		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 239
//@ 		mov	ax, [bp+_px]	; int16_t
//@ 		mov	Px, ax		; int16_t
//@ 		mov	ax, [bp+_py]	; int16_t
//@ 		mov	Py, ax		; int16_t
//@ 		mov	ax, [bp+_psin]	; int16_t
//@ 		mov	PSin, ax	; int16_t
//@ 		mov	ax, [bp+_pcos]	; int16_t
//@ 		mov	PCos, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 240
//@ 		mov	ActiveVoices, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 241
//@ 		mov	al, MaxVoice	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_2], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jg	short loc_3396A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$1, ax		; int16_t
//@ 		jmp	short loc_33951	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3394D:				; CODE XREF: UpDatePlayerPos+50j
//@ 		inc	n$1		; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 242
//@ 
//@ loc_33951:				; CODE XREF: UpDatePlayerPos+33j
//@ 		imul	di, n$1, 0Eh	; int16_t
//@ 		cmp	word ptr [di-878h], 0FFh ; Compare Two Operands
//@ 		jz	short loc_33962	; Jump if Zero (ZF=1)
//@ 		inc	ActiveVoices	; uint8_t
//@ 
//@ loc_33962:				; CODE XREF: UpDatePlayerPos+44j
//@ 		mov	ax, n$1		; int16_t
//@ 		cmp	ax, [bp+var_2]	; Compare Two Operands
//@ 		jnz	short loc_3394D	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 243
//@ 
//@ loc_3396A:				; CODE XREF: UpDatePlayerPos+2Ej
//@ 		mov	ObjAmb.Ambid, 0FFFFh ; struct ObjAmb$Type
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 244
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ UpDatePlayerPos	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 249
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetAmbient	proc far		; CODE XREF: StopSound+6P DoGame+1971P ...
//@ 
//@ Amb		= word ptr  6		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 250
//@ 		mov	ax, [bp+Amb]	; int16_t
//@ 		cmp	ax, CurAmbient	; int16_t
//@ 		jnz	short loc_33982	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_339C0 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 252
//@ 
//@ loc_33982:				; CODE XREF: SetAmbient+Aj
//@ 		cmp	[bp+Amb], 0FFFFh ; int16_t
//@ 		jnz	short loc_339A0	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 253
//@ 		mov	CurAmbient, 0FFFFh ; int16_t
//@ 		mov	PreAmbient, 0FFFFh ; int16_t
//@ 		mov	CAmbVol, 0	; uint8_t
//@ 		mov	PAmbVol, 0	; uint8_t
//@ 		jmp	short locret_339C0 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 256
//@ 
//@ loc_339A0:				; CODE XREF: SetAmbient+12j
//@ 		mov	al, CAmbVol	; uint8_t
//@ 		cmp	al, PAmbVol	; uint8_t
//@ 		jbe	short loc_339B5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 257
//@ 		mov	ax, CurAmbient	; int16_t
//@ 		mov	PreAmbient, ax	; int16_t
//@ 		mov	al, CAmbVol	; uint8_t
//@ 		mov	PAmbVol, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 258
//@ 
//@ loc_339B5:				; CODE XREF: SetAmbient+33j
//@ 		mov	CAmbVol, 6	; uint8_t
//@ 		mov	ax, [bp+Amb]	; int16_t
//@ 		mov	CurAmbient, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 260
//@ 
//@ locret_339C0:				; CODE XREF: SetAmbient+Cj
//@ 					; SetAmbient+2Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ SetAmbient	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 267
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddVoice	proc far		; CODE XREF: LoadServerPatch+23AP
//@ 					; LeftRight+31P ...
//@ 
//@ var_12		= dword	ptr -12h
//@ n		= word ptr -0Eh		; int16_t
//@ VoiceID		= word ptr  6		; int16_t
//@ vy		= word ptr  8		; int16_t
//@ vx		= word ptr  0Ah		; int16_t
//@ $Ch		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	12h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 268
//@ 		cmp	DisableALL, 0	; bool
//@ 		jz	short loc_339D2	; Jump if Zero (ZF=1)
//@ 		jmp	locret_33AF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 269
//@ 
//@ loc_339D2:				; CODE XREF: AddVoice+9j
//@ 		cmp	[bp+VoiceID], 0	; int16_t
//@ 		jl	short loc_339DF	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+VoiceID], 12Bh ; int16_t
//@ 		jle	short loc_339F6	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 270
//@ 
//@ loc_339DF:				; CODE XREF: AddVoice+12j
//@ 		push	3E8h
//@ 		call	@Sound$q4Word	; function far PASCAL returns void
//@ 		push	64h ; 'd'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		call	@NoSound$qv	; function far PASCAL returns void
//@ 		jmp	locret_33AF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 271
//@ 
//@ loc_339F6:				; CODE XREF: AddVoice+19j
//@ 		cmp	sCard, 1	; uint8_t
//@ 		ja	short loc_33A00	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	locret_33AF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 274
//@ 
//@ loc_33A00:				; CODE XREF: AddVoice+37j
//@ 		mov	ax, [bp+VoiceID] ; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di]
//@ 		or	ax, es:[di+2]	; Logical Inclusive OR
//@ 		jnz	short loc_33A18	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_33AF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 276
//@ 
//@ loc_33A18:				; CODE XREF: AddVoice+4Fj
//@ 		cmp	[bp+vx], 0	; int16_t
//@ 		jz	short loc_33A42	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 277
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		sub	ax, Py		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		sub	ax, Px		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		cmp	ax, 1770h	; Compare Two Operands
//@ 		jle	short loc_33A42	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_33AF0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 279
//@ 
//@ loc_33A42:				; CODE XREF: AddVoice+58j AddVoice+79j
//@ 		mov	al, MaxVoice	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 280
//@ 
//@ loc_33A4C:				; CODE XREF: AddVoice:loc_33A6Fj
//@ 		cmp	[bp+$Ch], 0FFFFh ; int16_t
//@ 		jnz	short loc_33A71	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jl	short loc_33A71	; Jump if Less (SF!=OF)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 281
//@ 		imul	di, [bp+n], 0Eh	; int16_t
//@ 		cmp	word ptr [di-878h], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_33A6C	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+$Ch], ax	; int16_t
//@ 		jmp	short loc_33A6F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_33A6C:				; CODE XREF: AddVoice+9Ej
//@ 		dec	[bp+n]		; int16_t
//@ 
//@ loc_33A6F:				; CODE XREF: AddVoice+A6j
//@ 		jmp	short loc_33A4C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 283
//@ 
//@ loc_33A71:				; CODE XREF: AddVoice+8Cj AddVoice+92j
//@ 		cmp	[bp+$Ch], 0FFFFh ; int16_t
//@ 		jnz	short loc_33A79	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_33AF0 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 285
//@ 
//@ loc_33A79:				; CODE XREF: AddVoice+B1j
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 286
//@ 		imul	di, [bp+$Ch], 0Eh ; int16_t
//@ 		add	di, 0F782h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_12], di
//@ 		mov	word ptr [bp+var_12+2],	es
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 288
//@ 		mov	word ptr es:[di+6], 0FFh
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 289
//@ 		mov	ax, [bp+VoiceID] ; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+4]
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 290
//@ 		mov	ax, [bp+VoiceID] ; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di]
//@ 		mov	dx, es:[di+2]
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 291
//@ 		mov	ax, [bp+VoiceID] ; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+6]
//@ 		les	di, [bp+var_12]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 292
//@ 		mov	ax, [bp+vx]	; int16_t
//@ 		mov	es:[di+0Ah], ax
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 293
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 295
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 296
//@ 
//@ locret_33AF0:				; CODE XREF: AddVoice+Bj AddVoice+2Fj	...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ AddVoice	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 301
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitSoundSystem	proc far		; CODE XREF: PROGRAM+CD7P
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 302
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jb	short loc_33B71	; Jump if Below	(CF=1)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 304
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, 910h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		push	400h
//@ 		call	@GetMem$q4Word	; GetMem(var p:	Pointer{DX:AX};	size: Word)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ 		mov	word ptr es:[di+4], 1
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 305
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, 918h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		push	400h
//@ 		call	@GetMem$q4Word	; GetMem(var p:	Pointer{DX:AX};	size: Word)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ 		mov	word ptr es:[di+4], 1
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 306
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, 920h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		push	400h
//@ 		call	@GetMem$q4Word	; GetMem(var p:	Pointer{DX:AX};	size: Word)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ 		mov	word ptr es:[di+4], 1
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 309
//@ 
//@ loc_33B71:				; CODE XREF: InitSoundSystem+9j
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 310
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jz	short loc_33B80	; Jump if Zero (ZF=1)
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jz	short loc_33B80	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_33B87	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_33B80:				; CODE XREF: InitSoundSystem+82j
//@ 					; InitSoundSystem+86j
//@ 		call	InitSb		; function far PASCAL returns void
//@ 		jmp	short loc_33B90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 311
//@ 
//@ loc_33B87:				; CODE XREF: InitSoundSystem+8Aj
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short loc_33B90	; Jump if Not Zero (ZF=0)
//@ 		call	InitGUS		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 313
//@ 
//@ loc_33B90:				; CODE XREF: InitSoundSystem+91j
//@ 					; InitSoundSystem+95j
//@ 		call	SetVolumes	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 314
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitSoundSystem	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 317
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DeInitSoundSystem proc far		; CODE XREF: DoHalt:loc_2C8DBP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 318
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 319
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jz	short loc_33BA9	; Jump if Zero (ZF=1)
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jz	short loc_33BA9	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_33BB0	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_33BA9:				; CODE XREF: DeInitSoundSystem+8j
//@ 					; DeInitSoundSystem+Cj
//@ 		call	DeInitSB	; function far PASCAL returns void
//@ 		jmp	short locret_33BB9 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 320
//@ 
//@ loc_33BB0:				; CODE XREF: DeInitSoundSystem+10j
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short locret_33BB9 ; Jump if Not Zero (ZF=0)
//@ 		call	DeInitGUS	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 322
//@ 
//@ locret_33BB9:				; CODE XREF: DeInitSoundSystem+17j
//@ 					; DeInitSoundSystem+1Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DeInitSoundSystem endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_33BBB	db 1,' '                ; DATA XREF: GetData+7Eo
//@ asc_33BBD	db 1,'$'                ; DATA XREF: GetData+9Do
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 332
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested far PASCAL returns unsigned int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ GetData		proc far		; CODE XREF: DetectBlaster+38P
//@ 					; DetectBlaster+4BP ...
//@ 
//@ var_406		= byte ptr -406h
//@ var_306		= byte ptr -306h
//@ Code		= word ptr -206h	; int16_t
//@ Num		= word ptr -204h	; uint16_t
//@ Temp		= byte ptr -202h	; char[256] // Pascal string
//@ Str		= byte ptr -102h	; char[256] // Pascal string
//@ GetData		= word ptr -2		; uint16_t
//@ Hex		= byte ptr  8		; bool
//@ ID		= byte ptr  0Ah		; char
//@ arg_6		= dword	ptr  0Ch
//@ 
//@ 		enter	406h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+Str]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_6]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 333
//@ 		lea	di, [bp+Str]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 334
//@ 		lea	di, [bp+var_306] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, [bp+ID]	; char
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_33C0F	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_33C9D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 336
//@ 
//@ loc_33C0F:				; CODE XREF: GetData+4Bj
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		lea	di, [bp+var_406] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	al, [bp+ID]	; char
//@ 		push	ax
//@ 		call	@$basg$qm6String4Char ;	Str:=Char
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		push	ax
//@ 		call	@Delete$qm6String7Integert2 ; Delete(var s: String; index: Integer; count: Integer)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 337
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_33BBB ; " "
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		push	ax
//@ 		push	0FFh
//@ 		call	@Delete$qm6String7Integert2 ; Delete(var s: String; index: Integer; count: Integer)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 338
//@ 		cmp	[bp+Hex], 0	; bool
//@ 		jz	short loc_33C71	; Jump if Zero (ZF=1)
//@ 		mov	di, offset asc_33BBD ; "$"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		push	1
//@ 		call	@Insert$qm6Stringt14Word7Integer ; Insert(source,dst: String;{dstlen: Word} index: Integer)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 339
//@ 
//@ loc_33C71:				; CODE XREF: GetData+9Bj
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+Code]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+Num], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 340
//@ 		cmp	[bp+Code], 0	; int16_t
//@ 		jnz	short loc_33C96	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+Num]	; uint16_t
//@ 		mov	[bp+GetData], ax ; uint16_t
//@ 		jmp	short loc_33C9B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_33C96:				; CODE XREF: GetData+CCj
//@ 		mov	[bp+GetData], 0FFh ; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 341
//@ 
//@ loc_33C9B:				; CODE XREF: GetData+D5j
//@ 		jmp	short loc_33CA2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_33C9D:				; CODE XREF: GetData+4Dj
//@ 		mov	[bp+GetData], 0FFh ; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 342
//@ 
//@ loc_33CA2:				; CODE XREF: GetData:loc_33C9Bj
//@ 		mov	ax, [bp+GetData] ; uint16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ GetData		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aBlaster	db 7,'BLASTER'          ; DATA XREF: DetectBlaster+10o
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 345
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DetectBlaster	proc far		; CODE XREF: DetectSound+CP
//@ 
//@ var_302		= byte ptr -302h
//@ var_202		= byte ptr -202h
//@ DM16		= word ptr -102h	; int16_t
//@ BLASTER		= byte ptr -100h	; char[256] // Pascal string
//@ 
//@ 		enter	302h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 346
//@ 		lea	di, [bp+var_302] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aBlaster ; "BLASTER"
//@ 		push	cs
//@ 		push	di
//@ 		call	@GetEnv$q6String ; function far	PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StUpcase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+BLASTER] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 347
//@ 		lea	di, [bp+BLASTER] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	41h ; 'A'
//@ 		push	1
//@ 		push	bp
//@ 		call	GetData		; function nested far PASCAL returns unsigned int 'Word'
//@ 		mov	sBase, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 348
//@ 		lea	di, [bp+BLASTER] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	49h ; 'I'
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData		; function nested far PASCAL returns unsigned int 'Word'
//@ 		mov	sIRQ, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 349
//@ 		lea	di, [bp+BLASTER] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	44h ; 'D'
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData		; function nested far PASCAL returns unsigned int 'Word'
//@ 		mov	sDMA, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 350
//@ 		lea	di, [bp+BLASTER] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	48h ; 'H'
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData		; function nested far PASCAL returns unsigned int 'Word'
//@ 		mov	[bp+DM16], ax	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 351
//@ 		lea	di, [bp+BLASTER] ; char[256] //	Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	54h ; 'T'
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData		; function nested far PASCAL returns unsigned int 'Word'
//@ 		mov	sCard, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 352
//@ 		mov	al, sCard	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 353
//@ 		cmp	al, 0FFh	; Compare Two Operands
//@ 		jnz	short loc_33D4C	; Jump if Not Zero (ZF=0)
//@ 		mov	sCard, 2	; uint8_t
//@ 		jmp	short loc_33D7E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 354
//@ 
//@ loc_33D4C:				; CODE XREF: DetectBlaster+92j
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jz	short loc_33D54	; Jump if Zero (ZF=1)
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_33D5B	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_33D54:				; CODE XREF: DetectBlaster+9Dj
//@ 		mov	sCard, 2	; uint8_t
//@ 		jmp	short loc_33D7E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 355
//@ 
//@ loc_33D5B:				; CODE XREF: DetectBlaster+A1j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jz	short loc_33D63	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_33D6A	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_33D63:				; CODE XREF: DetectBlaster+ACj
//@ 		mov	sCard, 3	; uint8_t
//@ 		jmp	short loc_33D7E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 356
//@ 
//@ loc_33D6A:				; CODE XREF: DetectBlaster+B0j
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jb	short loc_33D79	; Jump if Below	(CF=1)
//@ 		cmp	al, 9		; Compare Two Operands
//@ 		ja	short loc_33D79	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	sCard, 4	; uint8_t
//@ 		jmp	short loc_33D7E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 357
//@ 
//@ loc_33D79:				; CODE XREF: DetectBlaster+BBj
//@ 					; DetectBlaster+BFj
//@ 		mov	sCard, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 360
//@ 
//@ loc_33D7E:				; CODE XREF: DetectBlaster+99j
//@ 					; DetectBlaster+A8j ...
//@ 		cmp	[bp+BLASTER], 0	; char[256] // Pascal string
//@ 		jnz	short loc_33D8A	; Jump if Not Zero (ZF=0)
//@ 		mov	sCard, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 361
//@ 
//@ loc_33D8A:				; CODE XREF: DetectBlaster+D2j
//@ 		cmp	sBase, 0FFh	; uint16_t
//@ 		jnz	short loc_33D97	; Jump if Not Zero (ZF=0)
//@ 		mov	sCard, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 362
//@ 
//@ loc_33D97:				; CODE XREF: DetectBlaster+DFj
//@ 		cmp	sIRQ, 0FFh	; uint8_t
//@ 		jnz	short loc_33DA3	; Jump if Not Zero (ZF=0)
//@ 		mov	sCard, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 363
//@ 
//@ loc_33DA3:				; CODE XREF: DetectBlaster+EBj
//@ 		cmp	[bp+DM16], 0FFh	; int16_t
//@ 		jz	short loc_33DB9	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 364
//@ 		cmp	sCard, 4	; uint8_t
//@ 		jnz	short loc_33DB9	; Jump if Not Zero (ZF=0)
//@ 		mov	al, byte ptr [bp+DM16] ; int16_t
//@ 		mov	sDMA, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 365
//@ 
//@ loc_33DB9:				; CODE XREF: DetectBlaster+F8j
//@ 					; DetectBlaster+FFj
//@ 		cmp	sDMA, 0FFh	; uint8_t
//@ 		jnz	short locret_33DC5 ; Jump if Not Zero (ZF=0)
//@ 		mov	sCard, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 366
//@ 
//@ locret_33DC5:				; CODE XREF: DetectBlaster+10Dj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DetectBlaster	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_33DC7	db 1,','                ; DATA XREF: GetData$0+17o
//@ asc_33DC9	db 1,'$'                ; DATA XREF: GetData$0+41o
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 376
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested far PASCAL varargs returns unsigned int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ GetData$0	proc far		; CODE XREF: DetectGravis+43P
//@ 					; DetectGravis+54P ...
//@ 
//@ var_208		= byte ptr -208h
//@ Code		= word ptr -108h	; int16_t
//@ Num		= word ptr -106h	; uint16_t
//@ Ps		= word ptr -104h	; uint16_t
//@ Temp		= byte ptr -102h	; char[256] // Pascal string
//@ GetData		= word ptr -2		; uint16_t
//@ Hex		= byte ptr  8		; bool
//@ Str		= dword	ptr  0Ah	; char[256] // Pascal string
//@ 
//@ 		enter	208h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 377
//@ 		les	di, [bp+Str]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	di, offset asc_33DC7 ; ","
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+Ps], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 378
//@ 		cmp	[bp+Ps], 0	; uint16_t
//@ 		jz	short loc_33E06	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+Ps]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+Temp], al	; char[256] // Pascal string
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 379
//@ 
//@ loc_33E06:				; CODE XREF: GetData$0+30j
//@ 		cmp	[bp+Hex], 0	; bool
//@ 		jz	short loc_33E21	; Jump if Zero (ZF=1)
//@ 		mov	di, offset asc_33DC9 ; "$"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		push	1
//@ 		call	@Insert$qm6Stringt14Word7Integer ; Insert(source,dst: String;{dstlen: Word} index: Integer)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 380
//@ 
//@ loc_33E21:				; CODE XREF: GetData$0+3Fj
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+Temp]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+Code]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+Num], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 381
//@ 		cmp	[bp+Code], 0	; int16_t
//@ 		jnz	short loc_33E51	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+Num]	; uint16_t
//@ 		mov	[bp+GetData], ax ; uint16_t
//@ 		jmp	short loc_33E56	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_33E51:				; CODE XREF: GetData$0+7Bj
//@ 		mov	[bp+GetData], 0FFh ; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 382
//@ 
//@ loc_33E56:				; CODE XREF: GetData$0+84j
//@ 		lea	di, [bp+var_208] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+Str]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+Ps]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	20h ; ' '
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		les	di, [bp+Str]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 383
//@ 		mov	ax, [bp+GetData] ; uint16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ GetData$0	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aUltrasnd	db 8,'ULTRASND'         ; DATA XREF: DetectGravis+14o
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 387
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ DetectGravis	proc far		; CODE XREF: DetectSound+3P
//@ 
//@ var_304		= byte ptr -304h
//@ var_204		= byte ptr -204h
//@ n		= word ptr -104h	; int16_t
//@ eGUS		= byte ptr -102h	; char[256] // Pascal string
//@ DetectGravis	= byte ptr -1		; bool
//@ 
//@ 		enter	304h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 388
//@ 		mov	[bp+DetectGravis], 0 ; bool
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 389
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aUltrasnd ; "ULTRASND"
//@ 		push	cs
//@ 		push	di
//@ 		call	@GetEnv$q6String ; function far	PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StUpcase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+eGUS]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 390
//@ 		cmp	[bp+eGUS], 0	; char[256] // Pascal string
//@ 		jnz	short loc_33EC5	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_33F3D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 393
//@ 
//@ loc_33EC5:				; CODE XREF: DetectGravis+36j
//@ 		lea	di, [bp+eGUS]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		push	bp
//@ 		call	GetData$0	; function nested far PASCAL varargs returns unsigned int 'Word'
//@ 		mov	sBase, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 394
//@ 		lea	di, [bp+eGUS]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData$0	; function nested far PASCAL varargs returns unsigned int 'Word'
//@ 		mov	sDMA, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 395
//@ 		lea	di, [bp+eGUS]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData$0	; function nested far PASCAL varargs returns unsigned int 'Word'
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 396
//@ 		lea	di, [bp+eGUS]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData$0	; function nested far PASCAL varargs returns unsigned int 'Word'
//@ 		mov	sIRQ, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 397
//@ 		lea	di, [bp+eGUS]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		push	bp
//@ 		call	GetData$0	; function nested far PASCAL varargs returns unsigned int 'Word'
//@ 		mov	[bp+n],	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 398
//@ 		cmp	sBase, 0FFh	; uint16_t
//@ 		jz	short loc_33F32	; Jump if Zero (ZF=1)
//@ 		cmp	sDMA, 0FFh	; uint8_t
//@ 		jz	short loc_33F32	; Jump if Zero (ZF=1)
//@ 		cmp	sIRQ, 0FFh	; uint8_t
//@ 		jnz	short loc_33F34	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_33F32:				; CODE XREF: DetectGravis+97j
//@ 					; DetectGravis+9Ej
//@ 		jmp	short loc_33F3D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 400
//@ 
//@ loc_33F34:				; CODE XREF: DetectGravis+A5j
//@ 		mov	sCard, 5	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 401
//@ 		mov	[bp+DetectGravis], 1 ; bool
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 402
//@ 
//@ loc_33F3D:				; CODE XREF: DetectGravis+38j
//@ 					; DetectGravis:loc_33F32j
//@ 		mov	al, [bp+DetectGravis] ;	bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DetectGravis	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 406
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DetectSound	proc far		; CODE XREF: PROGRAM:loc_E802P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 407
//@ 		call	DetectGravis	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short locret_33F53 ; Jump if Not Zero (ZF=0)
//@ 		call	DetectBlaster	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 408
//@ 
//@ locret_33F53:				; CODE XREF: DetectSound+Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DetectSound	endp
//@ 
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 411
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; Attributes: bp-based frame
//@ 
//@ $SoundIPInit	proc far		; CODE XREF: PROGRAM+FP
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 412
//@ 		mov	DisableALL, 0	; bool
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 413
//@ 		mov	sCard, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 414
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr Old_IRQ, ax ; void (*)()
//@ 		mov	word ptr Old_IRQ+2, ax ; void (*)()
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 415
//@ 		mov	ax, cs
//@ 		push	ax
//@ 		call	AllocSelector	; Call Procedure
//@ 		mov	CSCopy$1, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 416
//@ 		push	CSCopy$1	; uint16_t
//@ 		push	0
//@ 		push	0FA00h
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 417
//@ 		mov	di, offset Voices ; TSFXRec*
//@ 		push	ds
//@ 		push	di
//@ 		push	960h
//@ 		call	GetMem16$0	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 418
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$1, ax		; int16_t
//@ 		jmp	short loc_33F9C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_33F98:				; CODE XREF: $SoundIPInit+6Ej
//@ 		inc	n$1		; int16_t
//@ 
//@ loc_33F9C:				; CODE XREF: $SoundIPInit+41j
//@ 		mov	ax, n$1		; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ 		mov	word ptr es:[di+6], 40h	; '@'
//@ 		cmp	n$1, 12Bh	; int16_t
//@ 		jnz	short loc_33F98	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 419
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$1, ax		; int16_t
//@ 		jmp	short loc_33FD0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_33FCC:				; CODE XREF: $SoundIPInit+8Bj
//@ 		inc	n$1		; int16_t
//@ 
//@ loc_33FD0:				; CODE XREF: $SoundIPInit+75j
//@ 		imul	di, n$1, 0Eh	; int16_t
//@ 		mov	word ptr [di-878h], 0FFh
//@ 		cmp	n$1, 0Fh	; int16_t
//@ 		jnz	short loc_33FCC	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 421
//@ 		mov	FXVolume, 0Fh	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 422
//@ 		mov	MaxVoice, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 423
//@ 		mov	Reverse, 0	; bool
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 424
//@ 		mov	CurAmbient, 0FFFFh ; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 425
//@ 		mov	PreAmbient, 0FFFFh ; int16_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 426
//@ 		mov	CAmbVol, 0	; uint8_t
//@ ; #line	"SOUNDIP\SOUNDIP.PAS" 427
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ $SoundIPInit	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		align 10h
