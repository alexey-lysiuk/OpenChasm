
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

#include "soundip/common.h"

//@ ; #line	"SOUNDIP\COMMON.PAS" 2
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ movsw$0		proc far		; CODE XREF: AddAmbient+C5P
//@ 					; NextStereoBlock16+2D5P ...
//@ 
//@ count		= word ptr  6		; uint16_t
//@ o2		= word ptr  8		; uint16_t
//@ s2		= word ptr  0Ah		; uint16_t
//@ o1		= word ptr  0Ch		; uint16_t
//@ s1		= word ptr  0Eh		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\COMMON.PAS" 3
//@ 		push	ds
//@ ; #line	"SOUNDIP\COMMON.PAS" 4
//@ 		mov	ds, [bp+s1]	; uint16_t
//@ 		mov	si, [bp+o1]	; uint16_t
//@ ; #line	"SOUNDIP\COMMON.PAS" 5
//@ 		mov	ax, [bp+s2]	; uint16_t
//@ 		mov	es, ax
//@ 		mov	di, [bp+o2]	; uint16_t
//@ ; #line	"SOUNDIP\COMMON.PAS" 6
//@ 		mov	cx, [bp+count]	; uint16_t
//@ ; #line	"SOUNDIP\COMMON.PAS" 7
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"SOUNDIP\COMMON.PAS" 8
//@ 		rep movsw		; Move Byte(s) from String to String
//@ ; #line	"SOUNDIP\COMMON.PAS" 9
//@ 		pop	ds
//@ ; #line	"SOUNDIP\COMMON.PAS" 10
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ movsw$0		endp
//@ 
//@ ; #line	"SOUNDIP\COMMON.PAS" 13
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StosW$0		proc far		; CODE XREF: NextStereoBlock16+20P
//@ 					; NextStereoBlock+2FP ...
//@ 
//@ v		= word ptr  6		; uint16_t
//@ cnt		= word ptr  8		; uint16_t
//@ oo1		= word ptr  0Ah		; uint16_t
//@ ss1		= word ptr  0Ch		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\COMMON.PAS" 14
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"SOUNDIP\COMMON.PAS" 15
//@ 		mov	ax, [bp+ss1]	; uint16_t
//@ 		mov	es, ax
//@ 		mov	di, [bp+oo1]	; uint16_t
//@ 		mov	cx, [bp+cnt]	; uint16_t
//@ 		mov	ax, [bp+v]	; uint16_t
//@ ; #line	"SOUNDIP\COMMON.PAS" 16
//@ 		rep stosw		; Store	String
//@ ; #line	"SOUNDIP\COMMON.PAS" 17
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ StosW$0		endp
//@ 
//@ ; #line	"SOUNDIP\COMMON.PAS" 20
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DisableSFXIRQ	proc far		; CODE XREF: DeInitSB:loc_32A54P
//@ 					; DeInitGUS+3P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\COMMON.PAS" 21
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jb	short locret_3194D ; Jump if Below (CF=1)
//@ ; #line	"SOUNDIP\COMMON.PAS" 22
//@ 		cmp	sIRQ, 8		; uint8_t
//@ 		jnb	short loc_31932	; Jump if Not Below (CF=0)
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		in	al, 21h		; Interrupt controller,	8259A.
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		out	21h, al		; Interrupt controller,	8259A.
//@ 		jmp	short locret_3194D ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\COMMON.PAS" 23
//@ 
//@ loc_31932:				; CODE XREF: DisableSFXIRQ+Fj
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		in	al, 0A1h	; Interrupt Controller #2, 8259A
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		out	0A1h, al	; Interrupt Controller #2, 8259A
//@ ; #line	"SOUNDIP\COMMON.PAS" 24
//@ 
//@ locret_3194D:				; CODE XREF: DisableSFXIRQ+8j
//@ 					; DisableSFXIRQ+29j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DisableSFXIRQ	endp
//@ 
//@ ; #line	"SOUNDIP\COMMON.PAS" 28
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ EnableSFXIRQ	proc far		; CODE XREF: InitSb+56P InitGUS+53P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\COMMON.PAS" 29
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jb	short locret_3199B ; Jump if Below (CF=1)
//@ ; #line	"SOUNDIP\COMMON.PAS" 30
//@ 		cmp	sIRQ, 8		; uint8_t
//@ 		jnb	short loc_3197D	; Jump if Not Below (CF=0)
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		xor	ax, 0FFh	; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		in	al, 21h		; Interrupt controller,	8259A.
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		out	21h, al		; Interrupt controller,	8259A.
//@ 		jmp	short locret_3199B ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\COMMON.PAS" 31
//@ 
//@ loc_3197D:				; CODE XREF: EnableSFXIRQ+Fj
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		xor	ax, 0FFh	; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		in	al, 0A1h	; Interrupt Controller #2, 8259A
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		out	0A1h, al	; Interrupt Controller #2, 8259A
//@ ; #line	"SOUNDIP\COMMON.PAS" 32
//@ 
//@ locret_3199B:				; CODE XREF: EnableSFXIRQ+8j
//@ 					; EnableSFXIRQ+2Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ EnableSFXIRQ	endp
//@ 
//@ ; #line	"SOUNDIP\COMMON.PAS" 35
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetMem16$0	proc far		; CODE XREF: GetDosPage+172P
//@ 					; GUS_InitDMABuffers+10AP ...
//@ 
//@ size		= word ptr  6		; uint16_t
//@ p		= dword	ptr  8
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\COMMON.PAS" 36
//@ 		cmp	[bp+size], 400h	; uint16_t
//@ 		jnb	short loc_319AC	; Jump if Not Below (CF=0)
//@ 		mov	[bp+size], 400h	; uint16_t
//@ ; #line	"SOUNDIP\COMMON.PAS" 37
//@ 
//@ loc_319AC:				; CODE XREF: GetMem16$0+8j
//@ 		push	[bp+size]	; uint16_t
//@ 		call	@GetMem$q4Word	; GetMem(var p:	Pointer{DX:AX};	size: Word)
//@ 		les	di, [bp+p]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ ; #line	"SOUNDIP\COMMON.PAS" 38
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, di
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short locret_319CE ; Jump if Zero (ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		call	far ptr	@Halt$q4Word ; Halt(exitcode: Word{AX})
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\COMMON.PAS" 39
//@ 
//@ locret_319CE:				; CODE XREF: GetMem16$0+28j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ GetMem16$0	endp
//@ 
