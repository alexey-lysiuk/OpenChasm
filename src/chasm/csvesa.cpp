
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

#include "csvesa.h"

//@ ; #line	"CSVESA.PAS" 4
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MovsED		proc far		; CODE XREF: PlayBrifing+41AP
//@ 					; UpDateInfo+C7P ...
//@ 
//@ CNT		= dword	ptr  6		; int32_t
//@ ofsb		= dword	ptr  0Ah	; int32_t
//@ segb		= word ptr  0Eh		; uint16_t
//@ ofsa		= dword	ptr  10h	; int32_t
//@ sega		= word ptr  14h		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 5
//@ 		push	ds
//@ ; #line	"CSVESA.PAS" 6
//@ 		mov	ds, [bp+sega]	; uint16_t
//@ ; #line	"CSVESA.PAS" 7
//@ 		mov	esi, [bp+ofsa]	; int32_t
//@ ; #line	"CSVESA.PAS" 8
//@ 		mov	ax, [bp+segb]	; uint16_t
//@ ; #line	"CSVESA.PAS" 9
//@ 		mov	es, ax
//@ ; #line	"CSVESA.PAS" 10
//@ 		mov	edi, [bp+ofsb]	; int32_t
//@ ; #line	"CSVESA.PAS" 11
//@ 		mov	ecx, [bp+CNT]	; int32_t
//@ ; #line	"CSVESA.PAS" 12
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSVESA.PAS" 13
//@ 		rep movs dword ptr es:[edi], dword ptr [esi] ; Move Byte(s) from String	to String
//@ ; #line	"CSVESA.PAS" 14
//@ 		pop	ds
//@ ; #line	"CSVESA.PAS" 15
//@ 		leave			; High Level Procedure Exit
//@ 		retf	10h		; Return Far from Procedure
//@ MovsED		endp
//@ 
//@ ; #line	"CSVESA.PAS" 20
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MovsEW		proc far		; CODE XREF: StartLoading+B1P
//@ 					; NextLoading+9BP ...
//@ 
//@ CNT		= dword	ptr  6		; int32_t
//@ ofsb		= dword	ptr  0Ah	; int32_t
//@ segb		= word ptr  0Eh		; uint16_t
//@ ofsa		= dword	ptr  10h	; int32_t
//@ sega		= word ptr  14h		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 21
//@ 		push	ds
//@ ; #line	"CSVESA.PAS" 22
//@ 		mov	ds, [bp+sega]	; uint16_t
//@ ; #line	"CSVESA.PAS" 23
//@ 		mov	esi, [bp+ofsa]	; int32_t
//@ ; #line	"CSVESA.PAS" 24
//@ 		mov	ax, [bp+segb]	; uint16_t
//@ ; #line	"CSVESA.PAS" 25
//@ 		mov	es, ax
//@ ; #line	"CSVESA.PAS" 26
//@ 		mov	edi, [bp+ofsb]	; int32_t
//@ ; #line	"CSVESA.PAS" 27
//@ 		mov	ecx, [bp+CNT]	; int32_t
//@ ; #line	"CSVESA.PAS" 28
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSVESA.PAS" 29
//@ 		rep movs word ptr es:[edi], word ptr [esi] ; Move Byte(s) from String to String
//@ ; #line	"CSVESA.PAS" 30
//@ 		pop	ds
//@ ; #line	"CSVESA.PAS" 31
//@ 		leave			; High Level Procedure Exit
//@ 		retf	10h		; Return Far from Procedure
//@ MovsEW		endp
//@ 
//@ ; #line	"CSVESA.PAS" 36
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VESAGetDosMem	proc near		; CODE XREF: InitVideo+50p
//@ 
//@ l		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ Size		= word ptr  4		; uint16_t
//@ p		= dword	ptr  6		; struct XRPointer
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 37
//@ 		cmp	[bp+Size], 400h	; uint16_t
//@ 		jnb	short loc_2ACD5	; Jump if Not Below (CF=0)
//@ 		mov	[bp+Size], 400h	; uint16_t
//@ ; #line	"CSVESA.PAS" 38
//@ 
//@ loc_2ACD5:				; CODE XREF: VESAGetDosMem+9j
//@ 		mov	ax, [bp+Size]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	GlobalDosAlloc	; Call Procedure
//@ 		mov	[bp+l],	ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSVESA.PAS" 39
//@ 		mov	ax, [bp+l]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		xor	cx, cx		; Logical Exclusive OR
//@ 		mov	bx, 1
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		mov	dx, ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		les	di, [bp+p]	; struct XRPointer
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ ; #line	"CSVESA.PAS" 40
//@ 		mov	ax, [bp+l]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		les	di, [bp+p]	; struct XRPointer
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSVESA.PAS" 41
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSVESA.PAS" 42
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ VESAGetDosMem	endp
//@ 
//@ ; #line	"CSVESA.PAS" 45
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VESAFreeDosMem	proc near		; CODE XREF: InitVideo+240p
//@ 
//@ p		= dword	ptr  4		; struct XRPointer
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 46
//@ 		les	di, [bp+p]	; struct XRPointer
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		call	GlobalDosFree	; Call Procedure
//@ ; #line	"CSVESA.PAS" 47
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ VESAFreeDosMem	endp
//@ 
//@ ; #line	"CSVESA.PAS" 52
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ ProcedError	proc near		; CODE XREF: GetVESAInfo+31p
//@ 					; GetModeInfo+3Dp ...
//@ 		mov	VESAError, 0	; uint8_t
//@ ; #line	"CSVESA.PAS" 53
//@ 		cmp	al, 4Fh	; 'O'   ; Compare Two Operands
//@ ; #line	"CSVESA.PAS" 54
//@ 		jnz	short loc_2AD52	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 55
//@ 		cmp	ah, 0		; Compare Two Operands
//@ ; #line	"CSVESA.PAS" 56
//@ 		jz	short locret_2AD59 ; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 57
//@ 		mov	VESAError, 2	; uint8_t
//@ ; #line	"CSVESA.PAS" 58
//@ 		jmp	short locret_2AD59 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 60
//@ 
//@ loc_2AD52:				; CODE XREF: ProcedError+7j
//@ 		mov	VESAError, 1	; uint8_t
//@ ; #line	"CSVESA.PAS" 61
//@ 		jmp	short $+2	; Jump
//@ ; #line	"CSVESA.PAS" 63
//@ 
//@ locret_2AD59:				; CODE XREF: ProcedError+Cj
//@ 					; ProcedError+13j
//@ 		retn			; Return Near from Procedure
//@ ProcedError	endp
//@ 
//@ ; #line	"CSVESA.PAS" 67
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RealInt10h	proc near		; CODE XREF: GetVESAInfo+2Bp
//@ 					; GetModeInfo+37p
//@ 
//@ DPMIRegs	= dword	ptr  4		; struct TDPMIRegs
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 68
//@ 		mov	bx, 10h
//@ ; #line	"CSVESA.PAS" 69
//@ 		xor	cx, cx		; Logical Exclusive OR
//@ ; #line	"CSVESA.PAS" 70
//@ 		les	di, [bp+DPMIRegs] ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 71
//@ 		mov	ax, 300h
//@ ; #line	"CSVESA.PAS" 72
//@ 		int	31h		; DPMI Services	  ax=func xxxxh
//@ 					; SIMULATE REAL	MODE INTERRUPT
//@ 					; BL=interrupt number
//@ 					; CX=number of words to	copy from protected mode to real mode stack
//@ 					; ES:DI	/ ES:EDI = selector:offset of real mode	call structure
//@ 					; Return: CF set on error
//@ 					; CF clear if ok
//@ ; #line	"CSVESA.PAS" 73
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ RealInt10h	endp
//@ 
//@ ; #line	"CSVESA.PAS" 76
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetVESAInfo	proc near		; CODE XREF: InitVideo+59p
//@ 
//@ p		= dword	ptr  4		; struct XRPointer
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 77
//@ 		les	di, [bp+p]	; struct XRPointer
//@ 		mov	ax, es:[di+4]
//@ 		mov	DRegs$0.rES, ax	; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 78
//@ 		mov	ax, es:[di+6]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr DRegs$0.rDI, ax ; struct TDPMIRegs
//@ 		mov	word ptr DRegs$0.rDI+2,	dx ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 79
//@ 		mov	word ptr DRegs$0.xAX, 4F00h ; struct TDPMIRegs
//@ 		mov	word ptr DRegs$0.xAX+2,	0 ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 80
//@ 		mov	di, offset DRegs$0 ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt10h	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 82
//@ 		mov	ax, word ptr DRegs$0.xAX ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 83
//@ 		call	ProcedError	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 85
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ GetVESAInfo	endp
//@ 
//@ ; #line	"CSVESA.PAS" 89
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetModeInfo	proc near		; CODE XREF: InitVideo+C8p
//@ 					; InitVideo+1B5p
//@ 
//@ Mode		= word ptr  4		; uint16_t
//@ p		= dword	ptr  6		; struct XRPointer
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 90
//@ 		les	di, [bp+p]	; struct XRPointer
//@ 		mov	ax, es:[di+4]
//@ 		mov	DRegs$0.rES, ax	; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 91
//@ 		mov	ax, es:[di+6]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr DRegs$0.rDI, ax ; struct TDPMIRegs
//@ 		mov	word ptr DRegs$0.rDI+2,	dx ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 92
//@ 		mov	word ptr DRegs$0.xAX, 4F01h ; struct TDPMIRegs
//@ 		mov	word ptr DRegs$0.xAX+2,	0 ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 93
//@ 		mov	ax, [bp+Mode]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr DRegs$0.xCX, ax ; struct TDPMIRegs
//@ 		mov	word ptr DRegs$0.xCX+2,	dx ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 94
//@ 		mov	di, offset DRegs$0 ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt10h	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 96
//@ 		mov	ax, word ptr DRegs$0.xAX ; struct TDPMIRegs
//@ ; #line	"CSVESA.PAS" 97
//@ 		call	ProcedError	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 99
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ GetModeInfo	endp
//@ 
//@ ; #line	"CSVESA.PAS" 103
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetVESAMode	proc far		; CODE XREF: InitVESAMonitor+58P
//@ 					; Init_HiMode+28P ...
//@ 
//@ Mode		= word ptr  6		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 104
//@ 		mov	ax, 4F02h
//@ ; #line	"CSVESA.PAS" 105
//@ 		mov	bx, [bp+Mode]	; uint16_t
//@ ; #line	"CSVESA.PAS" 106
//@ 		int	10h		; - VIDEO - VESA SuperVGA BIOS -  SET SuperVGA VIDEO MODE
//@ 					; BX = mode, bit 15 set	means don't clear video memory
//@ 					; BX = bit 15 set means	don't clear video memory
//@ 					; Return: AL = 4Fh function supported
//@ 					; AH = 00h successful, 01h failed
//@ ; #line	"CSVESA.PAS" 107
//@ 		call	ProcedError	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 108
//@ 		mov	VESABank, 0	; uint16_t
//@ ; #line	"CSVESA.PAS" 109
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ SetVESAMode	endp
//@ 
//@ ; #line	"CSVESA.PAS" 113
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ SwitchBank	proc far		; CODE XREF: ShowValue+EP
//@ 					; VESA_PutImage+1AP ...
//@ 		mov	ax, 4F05h
//@ ; #line	"CSVESA.PAS" 114
//@ 		mov	bx, 0
//@ ; #line	"CSVESA.PAS" 115
//@ 		shl	dx, 0FFh	; Shift	Logical	Left
//@ ; #line	"CSVESA.PAS" 116
//@ 		int	10h		; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA	BIOS - CPU VIDEO MEMORY	CONTROL
//@ 					; BL = 00h window A, 01h window	B
//@ 					; Return: AL = 4Fh function supported
//@ 					; AH = 00h successful, 01h failed
//@ 					; BH = subfunctionselect video memory window
//@ ; #line	"CSVESA.PAS" 117
//@ 		shr	dx, 0FFh	; Shift	Logical	Right
//@ ; #line	"CSVESA.PAS" 118
//@ 		mov	VESABank, dx	; uint16_t
//@ ; #line	"CSVESA.PAS" 119
//@ 		retf			; Return Far from Procedure
//@ SwitchBank	endp
//@ 
//@ ; #line	"CSVESA.PAS" 123
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ 
//@ OnlySwitchBank	proc near		; CODE XREF: VESA_PutImage+5Ap
//@ 					; VESA_PutImage+7Cp
//@ 		mov	ax, 4F05h
//@ ; #line	"CSVESA.PAS" 124
//@ 		mov	bx, 0
//@ ; #line	"CSVESA.PAS" 125
//@ 		shl	dx, 0FFh	; Shift	Logical	Left
//@ ; #line	"CSVESA.PAS" 126
//@ 		int	10h		; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA	BIOS - CPU VIDEO MEMORY	CONTROL
//@ 					; BL = 00h window A, 01h window	B
//@ 					; Return: AL = 4Fh function supported
//@ 					; AH = 00h successful, 01h failed
//@ 					; BH = subfunctionselect video memory window
//@ ; #line	"CSVESA.PAS" 127
//@ 		shr	dx, 0FFh	; Shift	Logical	Right
//@ ; #line	"CSVESA.PAS" 128
//@ 		retn			; Return Near from Procedure
//@ OnlySwitchBank	endp
//@ 
//@ ; #line	"CSVESA.PAS" 143
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddMode		proc near		; CODE XREF: InitVideo+2Cp
//@ 					; InitVideo+221p
//@ 
//@ var_8		= word ptr -8
//@ vs		= word ptr -6		; int32_t
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; uint16_t
//@ _FLAT		= byte ptr  6		; bool
//@ arg_4		= word ptr  8		; uint16_t
//@ yr		= word ptr  0Ah		; uint16_t
//@ xr		= word ptr  0Ch		; uint16_t
//@ mn		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 144
//@ 		cmp	ModesList.MDCount, 0Bh ; struct	ModesList$Type
//@ 		jb	short loc_2AE32	; Jump if Below	(CF=1)
//@ 		jmp	locret_2AF26	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 145
//@ 
//@ loc_2AE32:				; CODE XREF: AddMode+9j
//@ 		cmp	ModesList.MDCount, 0 ; struct ModesList$Type
//@ 		jbe	short loc_2AE74	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSVESA.PAS" 146
//@ 		mov	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		mov	[bp+var_8], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		ja	short loc_2AE74	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2AE4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2AE4C:				; CODE XREF: AddMode+4Ej
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSVESA.PAS" 147
//@ 
//@ loc_2AE4F:				; CODE XREF: AddMode+26j
//@ 		imul	di, [bp+n], 0Dh	; uint16_t
//@ 		mov	ax, [di-0BCFh]
//@ 		cmp	ax, [bp+xr]	; uint16_t
//@ 		jnz	short loc_2AE6C	; Jump if Not Zero (ZF=0)
//@ 		imul	di, [bp+n], 0Dh	; uint16_t
//@ 		mov	ax, [di-0BCDh]
//@ 		cmp	ax, [bp+yr]	; uint16_t
//@ 		jnz	short loc_2AE6C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2AF26	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2AE6C:				; CODE XREF: AddMode+36j AddMode+43j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jnz	short loc_2AE4C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 149
//@ 
//@ loc_2AE74:				; CODE XREF: AddMode+13j AddMode+21j
//@ 		inc	ModesList.MDCount ; struct ModesList$Type
//@ 		mov	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		mov	ax, [bp+yr]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+arg_4]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	[bp+vs], ax	; int32_t
//@ 		mov	[bp+var_4], dx
//@ ; #line	"CSVESA.PAS" 150
//@ 
//@ loc_2AE97:				; CODE XREF: AddMode+97j
//@ 		cmp	[bp+n],	1	; uint16_t
//@ 		jbe	short loc_2AEBD	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	di, ax,	0Dh	; Signed Multiply
//@ 		mov	ax, [di-0BC9h]
//@ 		mov	dx, [di-0BC7h]
//@ 		cmp	dx, [bp+var_4]	; Compare Two Operands
//@ 		jg	short loc_2AEB8	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2AEBD	; Jump if Less (SF!=OF)
//@ 		cmp	ax, [bp+vs]	; int32_t
//@ 		jbe	short loc_2AEBD	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2AEB8:				; CODE XREF: AddMode+8Bj
//@ 		dec	[bp+n]		; uint16_t
//@ 		jmp	short loc_2AE97	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 152
//@ 
//@ loc_2AEBD:				; CODE XREF: AddMode+77j AddMode+8Dj ...
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		jz	short loc_2AEEC	; Jump if Zero (ZF=1)
//@ 		imul	di, [bp+n], 0Dh	; uint16_t
//@ 		add	di, 0F42Fh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, ax,	0Dh	; Signed Multiply
//@ 		add	di, 0F42Fh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, ModesList.MDCount ;	struct ModesList$Type
//@ 		sub	ax, [bp+n]	; uint16_t
//@ 		imul	ax, 0Dh		; Signed Multiply
//@ 		push	ax
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSVESA.PAS" 154
//@ 
//@ loc_2AEEC:				; CODE XREF: AddMode+A0j
//@ 		imul	di, [bp+n], 0Dh	; uint16_t
//@ 		add	di, 0F42Fh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSVESA.PAS" 156
//@ 		mov	ax, [bp+xr]	; uint16_t
//@ 		mov	es:[di+2], ax
//@ 		mov	ax, [bp+yr]	; uint16_t
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, [bp+mn]	; uint16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+arg_4]	; uint16_t
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSVESA.PAS" 157
//@ 		mov	ax, [bp+vs]	; int32_t
//@ 		mov	dx, [bp+var_4]
//@ 		mov	es:[di+8], ax
//@ 		mov	es:[di+0Ah], dx
//@ ; #line	"CSVESA.PAS" 158
//@ 		mov	al, [bp+_FLAT]	; bool
//@ 		mov	es:[di+0Ch], al
//@ ; #line	"CSVESA.PAS" 160
//@ 
//@ locret_2AF26:				; CODE XREF: AddMode+Bj AddMode+45j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ch		; Return Near from Procedure
//@ AddMode		endp
//@ 
//@ ; #line	"CSVESA.PAS" 165
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitVideo	proc near		; CODE XREF: $CspBioInit+3p
//@ 
void InitVideo()
{
//@ DOSBuf		= dword	ptr -312h	; struct XRPointer
//@ VESAMode	= byte ptr -30Ah	; struct ModeInfoBlock
//@ var_306		= word ptr -306h
//@ var_2FA		= word ptr -2FAh
//@ var_2F8		= word ptr -2F8h
//@ var_2F6		= word ptr -2F6h
//@ var_2F2		= byte ptr -2F2h
//@ var_2F1		= byte ptr -2F1h
//@ var_2E2		= word ptr -2E2h
//@ var_2E0		= word ptr -2E0h
//@ VESAInfo	= word ptr -208h	; struct VgaInfoBlock
//@ var_206		= word ptr -206h
//@ var_204		= word ptr -204h
//@ var_1F6		= word ptr -1F6h
//@ CSCopy		= word ptr -8		; uint16_t
//@ Mode		= word ptr -6		; uint16_t
//@ VEnable		= byte ptr -3		; bool
//@ MulBank		= byte ptr -2		; uint8_t
//@ TmpB		= byte ptr -1		; uint8_t
//@ 
//@ 		enter	312h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 166
//@ 		mov	VESAPresent, 0	; bool
//@ ; #line	"CSVESA.PAS" 167
//@ 		mov	VESA20Compliant, 0 ; bool
//@ ; #line	"CSVESA.PAS" 168
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	VESAVersion, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 169
//@ 		mov	TotalMemory, 100h ; uint16_t
//@ ; #line	"CSVESA.PAS" 170
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ModesList.MDCount, ax ;	struct ModesList$Type
//@ ; #line	"CSVESA.PAS" 171
//@ 		push	0
//@ 		push	140h
//@ 		push	0C8h ; '￈'
//@ 		push	140h
//@ 		push	1
//@ 		push	bp
//@ 		call	AddMode		; function nested near PASCAL returns void
//@ ; #line	"CSVESA.PAS" 173
//@ 		mov	ax, cs
//@ 		push	ax
//@ 		call	AllocSelector	; Call Procedure
//@ 		mov	[bp+CSCopy], ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 174
//@ 		push	[bp+CSCopy]	; uint16_t
//@ 		push	0
//@ 		push	0FA00h
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSVESA.PAS" 176
//@ 		lea	di, [bp+DOSBuf]	; struct XRPointer
//@ 		push	ss
//@ 		push	di
//@ 		push	400h
//@ 		call	VESAGetDosMem	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 177
//@ 		lea	di, [bp+DOSBuf]	; struct XRPointer
//@ 		push	ss
//@ 		push	di
//@ 		call	GetVESAInfo	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 178
//@ 		les	di, [bp+DOSBuf]	; struct XRPointer
//@ 		assume es:nothing
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+VESAInfo] ; struct VgaInfoBlock
//@ 		push	ss
//@ 		push	di
//@ 		push	200h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSVESA.PAS" 180
//@ 		cmp	VESAError, 0	; uint8_t
//@ 		jnz	short loc_2AFC1	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+var_206], 4153h ; Compare Two Operands
//@ 		jnz	short loc_2AFB1	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+VESAInfo], 4556h ; struct VgaInfoBlock
//@ 		jz	short loc_2AFC5	; Jump if Zero (ZF=1)
//@ 
//@ loc_2AFB1:				; CODE XREF: InitVideo+7Dj
//@ 		cmp	[bp+var_206], 3245h ; Compare Two Operands
//@ 		jnz	short loc_2AFC1	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+VESAInfo], 4256h ; struct VgaInfoBlock
//@ 		jz	short loc_2AFC5	; Jump if Zero (ZF=1)
//@ 
//@ loc_2AFC1:				; CODE XREF: InitVideo+75j
//@ 					; InitVideo+8Dj
//@ 		mov	al, 0
//@ 		jmp	short loc_2AFC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2AFC5:				; CODE XREF: InitVideo+85j
//@ 					; InitVideo+95j
//@ 		mov	al, 1
//@ 
//@ loc_2AFC7:				; CODE XREF: InitVideo+99j
//@ 		mov	[bp+VEnable], al ; bool
//@ ; #line	"CSVESA.PAS" 183
//@ 		cmp	[bp+VEnable], 0	; bool
//@ 		jnz	short loc_2AFD3	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2B175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 185
//@ 
//@ loc_2AFD3:				; CODE XREF: InitVideo+A4j
//@ 		mov	VESAPresent, 1	; bool
//@ ; #line	"CSVESA.PAS" 186
//@ 		mov	ax, [bp+var_204]
//@ 		mov	VESAVersion, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 187
//@ 		mov	ax, [bp+var_1F6]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	TotalMemory, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 188
//@ 		lea	di, [bp+DOSBuf]	; struct XRPointer
//@ 		push	ss
//@ 		push	di
//@ 		push	100h
//@ 		call	GetModeInfo	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 189
//@ 		les	di, [bp+DOSBuf]	; struct XRPointer
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+VESAMode] ; struct ModeInfoBlock
//@ 		push	ss
//@ 		push	di
//@ 		push	102h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSVESA.PAS" 190
//@ 		mov	ax, [bp+var_2E2]
//@ 		mov	dx, [bp+var_2E0]
//@ 		mov	word ptr VESA20Addr, ax	; int32_t
//@ 		mov	word ptr VESA20Addr+2, dx ; int32_t
//@ ; #line	"CSVESA.PAS" 193
//@ 		cmp	VESAVersion, 200h ; uint16_t
//@ 		jb	short loc_2B054	; Jump if Below	(CF=1)
//@ 		mov	ax, word ptr VESA20Addr	; int32_t
//@ 		or	ax, word ptr VESA20Addr+2 ; int32_t
//@ 		jz	short loc_2B054	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 195
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		call	AllocSelector	; Call Procedure
//@ 		mov	FLATSelector, ax ; uint16_t
//@ ; #line	"CSVESA.PAS" 196
//@ 		push	FLATSelector	; uint16_t
//@ 		push	word ptr VESA20Addr+2 ;	int32_t
//@ 		push	word ptr VESA20Addr ; int32_t
//@ 		call	SetSelectorBase	; Call Procedure
//@ ; #line	"CSVESA.PAS" 198
//@ 		mov	ax, 8
//@ ; #line	"CSVESA.PAS" 199
//@ 		mov	bx, FLATSelector ; uint16_t
//@ ; #line	"CSVESA.PAS" 200
//@ 		mov	cx, 10h
//@ ; #line	"CSVESA.PAS" 201
//@ 		mov	dx, 0
//@ ; #line	"CSVESA.PAS" 202
//@ 		int	31h		; DPMI Services	  ax=func xxxxh
//@ 					; SET SEGMENT LIMIT
//@ 					; BX = selector, CX:DX = segment limit
//@ 					; Return: CF set on error
//@ 					; CF clear if successful
//@ ; #line	"CSVESA.PAS" 208
//@ 
//@ loc_2B054:				; CODE XREF: InitVideo+F4j
//@ 					; InitVideo+FDj
//@ 		cmp	[bp+var_306], 0	; Compare Two Operands
//@ 		jnz	short loc_2B061	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+var_306], 40h ; '@'
//@ ; #line	"CSVESA.PAS" 210
//@ 
//@ loc_2B061:				; CODE XREF: InitVideo+12Fj
//@ 		mov	[bp+MulBank], 0	; uint8_t
//@ ; #line	"CSVESA.PAS" 211
//@ 		mov	ax, 40h	; '@'
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	[bp+var_306]	; Unsigned Divide
//@ 		mov	[bp+TmpB], al	; uint8_t
//@ ; #line	"CSVESA.PAS" 212
//@ 
//@ loc_2B071:				; CODE XREF: InitVideo+160j
//@ 		cmp	[bp+TmpB], 0	; uint8_t
//@ 		jz	short loc_2B08C	; Jump if Zero (ZF=1)
//@ 		cmp	[bp+TmpB], 1	; uint8_t
//@ 		jz	short loc_2B08C	; Jump if Zero (ZF=1)
//@ 		mov	al, [bp+TmpB]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	[bp+TmpB], al	; uint8_t
//@ 		inc	[bp+MulBank]	; uint8_t
//@ 		jmp	short loc_2B071	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 214
//@ 
//@ loc_2B08C:				; CODE XREF: InitVideo+14Bj
//@ 					; InitVideo+151j
//@ 		mov	al, [bp+MulBank] ; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	VESABankShift, ax ; uint16_t
//@ ; #line	"CSVESA.PAS" 215
//@ 		mov	dl, [bp+MulBank] ; uint8_t
//@ 		mov	ax, [bp+CSCopy]	; uint16_t
//@ 		push	ax
//@ 		mov	di, 18Ah
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSVESA.PAS" 216
//@ 		mov	dl, [bp+MulBank] ; uint8_t
//@ 		mov	ax, [bp+CSCopy]	; uint16_t
//@ 		push	ax
//@ 		mov	di, 18Fh
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSVESA.PAS" 217
//@ 		mov	dl, [bp+MulBank] ; uint8_t
//@ 		mov	ax, [bp+CSCopy]	; uint16_t
//@ 		push	ax
//@ 		mov	di, 19Dh
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSVESA.PAS" 218
//@ 		mov	dl, [bp+MulBank] ; uint8_t
//@ 		mov	ax, [bp+CSCopy]	; uint16_t
//@ 		push	ax
//@ 		mov	di, 1A2h
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSVESA.PAS" 222
//@ 		mov	[bp+Mode], 100h	; uint16_t
//@ 		jmp	short loc_2B0D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B0D3:				; CODE XREF: InitVideo+22Bj
//@ 		inc	[bp+Mode]	; uint16_t
//@ ; #line	"CSVESA.PAS" 224
//@ 
//@ loc_2B0D6:				; CODE XREF: InitVideo+1A7j
//@ 		lea	di, [bp+DOSBuf]	; struct XRPointer
//@ 		push	ss
//@ 		push	di
//@ 		push	[bp+Mode]	; uint16_t
//@ 		call	GetModeInfo	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 225
//@ 		les	di, [bp+DOSBuf]	; struct XRPointer
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+VESAMode] ; struct ModeInfoBlock
//@ 		push	ss
//@ 		push	di
//@ 		push	102h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSVESA.PAS" 227
//@ 		cmp	[bp+var_2F1], 8	; Compare Two Operands
//@ 		jnz	short loc_2B14E	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_2FA]
//@ 		cmp	ax, [bp+var_2F8] ; Compare Two Operands
//@ 		jb	short loc_2B14E	; Jump if Below	(CF=1)
//@ 		cmp	[bp+var_2F8], 280h ; Compare Two Operands
//@ 		ja	short loc_2B14E	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	[bp+var_2F6], 1E0h ; Compare Two Operands
//@ 		ja	short loc_2B14E	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	[bp+var_2F2], 1	; Compare Two Operands
//@ 		jnz	short loc_2B14E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 238
//@ 		mov	ax, [bp+var_2E2]
//@ 		or	ax, [bp+var_2E0] ; Logical Inclusive OR
//@ 		jz	short loc_2B12D	; Jump if Zero (ZF=1)
//@ 		mov	VESA20Compliant, 1 ; bool
//@ ; #line	"CSVESA.PAS" 239
//@ 
//@ loc_2B12D:				; CODE XREF: InitVideo+1FCj
//@ 		push	[bp+Mode]	; uint16_t
//@ 		push	[bp+var_2F8]
//@ 		push	[bp+var_2F6]
//@ 		push	[bp+var_2FA]
//@ 		mov	ax, [bp+var_2E2]
//@ 		or	ax, [bp+var_2E0] ; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jz	short loc_2B149	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_2B149:				; CODE XREF: InitVideo+21Cj
//@ 		push	ax
//@ 		push	bp
//@ 		call	AddMode		; function nested near PASCAL returns void
//@ ; #line	"CSVESA.PAS" 241
//@ 
//@ loc_2B14E:				; CODE XREF: InitVideo+1D1j
//@ 					; InitVideo+1DBj ...
//@ 		cmp	[bp+Mode], 200h	; uint16_t
//@ 		jz	short loc_2B158	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2B0D3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 245
//@ 
//@ loc_2B158:				; CODE XREF: InitVideo+229j
//@ 		cmp	ModesList.MDCount, 5 ; struct ModesList$Type
//@ 		jnb	short loc_2B164	; Jump if Not Below (CF=0)
//@ 		mov	VESA20Compliant, 0 ; bool
//@ ; #line	"CSVESA.PAS" 246
//@ 
//@ loc_2B164:				; CODE XREF: InitVideo+233j
//@ 		lea	di, [bp+DOSBuf]	; struct XRPointer
//@ 		push	ss
//@ 		push	di
//@ 		call	VESAFreeDosMem	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 247
//@ 		push	[bp+CSCopy]	; uint16_t
//@ 		call	FreeSelector	; Call Procedure
//@ ; #line	"CSVESA.PAS" 248
//@ 
//@ locret_2B175:				; CODE XREF: InitVideo+A6j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
}
//@ InitVideo	endp
//@ 
//@ ; #line	"CSVESA.PAS" 257
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VESA_PutImage	proc far		; CODE XREF: ShowVesaScreen+BDP
//@ 					; ShowVESATime+13AP ...
//@ 
//@ SiIncr		= word ptr -4		; int16_t
//@ AddNum		= word ptr -2		; int16_t
//@ BitMap		= dword	ptr  6
//@ XRSize		= word ptr  0Ah		; uint16_t
//@ YSize		= word ptr  0Ch		; uint16_t
//@ XSize		= word ptr  0Eh		; uint16_t
//@ Y		= word ptr  10h		; uint16_t
//@ X		= word ptr  12h		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 258
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSVESA.PAS" 259
//@ 		push	ds
//@ ; #line	"CSVESA.PAS" 261
//@ 		mov	ax, 280h
//@ ; #line	"CSVESA.PAS" 262
//@ 		mul	[bp+Y]		; uint16_t
//@ ; #line	"CSVESA.PAS" 263
//@ 		add	ax, [bp+X]	; uint16_t
//@ ; #line	"CSVESA.PAS" 264
//@ 		adc	dx, 0		; Add with Carry
//@ ; #line	"CSVESA.PAS" 265
//@ 		mov	di, ax
//@ ; #line	"CSVESA.PAS" 266
//@ 		cmp	dx, VESABank	; uint16_t
//@ ; #line	"CSVESA.PAS" 267
//@ 		jz	short loc_2B196	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 268
//@ 		call	SwitchBank	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 271
//@ 
//@ loc_2B196:				; CODE XREF: VESA_PutImage+18j
//@ 		mov	ax, SegA000	; uint16_t
//@ ; #line	"CSVESA.PAS" 272
//@ 		mov	es, ax
//@ ; #line	"CSVESA.PAS" 274
//@ 		lds	si, [bp+BitMap]	; Load Full Pointer to DS:xx
//@ ; #line	"CSVESA.PAS" 276
//@ 		mov	ax, [bp+XSize]	; uint16_t
//@ ; #line	"CSVESA.PAS" 277
//@ 		mov	bx, [bp+XRSize]	; uint16_t
//@ ; #line	"CSVESA.PAS" 278
//@ 		sub	bx, ax		; Integer Subtraction
//@ ; #line	"CSVESA.PAS" 279
//@ 		mov	[bp+SiIncr], bx	; int16_t
//@ ; #line	"CSVESA.PAS" 281
//@ 		mov	bx, 280h
//@ ; #line	"CSVESA.PAS" 282
//@ 		sub	bx, ax		; Integer Subtraction
//@ ; #line	"CSVESA.PAS" 283
//@ 		mov	[bp+AddNum], bx	; int16_t
//@ ; #line	"CSVESA.PAS" 284
//@ 		mov	ax, [bp+YSize]	; uint16_t
//@ ; #line	"CSVESA.PAS" 287
//@ 
//@ loc_2B1B4:				; CODE XREF: VESA_PutImage+79j
//@ 					; VESA_PutImage+7Fj
//@ 		mov	cx, [bp+XSize]	; uint16_t
//@ ; #line	"CSVESA.PAS" 288
//@ 		mov	ax, di
//@ ; #line	"CSVESA.PAS" 289
//@ 		add	ax, cx		; Add
//@ ; #line	"CSVESA.PAS" 290
//@ 		jnb	short loc_2B1D5	; Jump if Not Below (CF=0)
//@ ; #line	"CSVESA.PAS" 292
//@ 		push	ax
//@ ; #line	"CSVESA.PAS" 293
//@ 		sub	cx, ax		; Integer Subtraction
//@ ; #line	"CSVESA.PAS" 294
//@ 		push	cx
//@ 		shr	cx, 2		; Shift	Logical	Right
//@ ; #line	"CSVESA.PAS" 295
//@ 		rep movsd		; Move Byte(s) from String to String
//@ ; #line	"CSVESA.PAS" 296
//@ 		pop	cx
//@ 		and	cx, 3		; Logical AND
//@ 		jz	short loc_2B1D0	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 297
//@ 		rep movsb		; Move Byte(s) from String to String
//@ ; #line	"CSVESA.PAS" 298
//@ 
//@ loc_2B1D0:				; CODE XREF: VESA_PutImage+55j
//@ 		inc	dx		; Increment by 1
//@ ; #line	"CSVESA.PAS" 299
//@ 		call	OnlySwitchBank	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 300
//@ 		pop	cx
//@ ; #line	"CSVESA.PAS" 303
//@ 
//@ loc_2B1D5:				; CODE XREF: VESA_PutImage+44j
//@ 		push	cx
//@ 		shr	cx, 2		; Shift	Logical	Right
//@ ; #line	"CSVESA.PAS" 304
//@ 		rep movsd		; Move Byte(s) from String to String
//@ ; #line	"CSVESA.PAS" 305
//@ 		pop	cx
//@ 		and	cx, 3		; Logical AND
//@ 		jz	short loc_2B1E5	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 306
//@ 		rep movsb		; Move Byte(s) from String to String
//@ ; #line	"CSVESA.PAS" 309
//@ 
//@ loc_2B1E5:				; CODE XREF: VESA_PutImage+6Aj
//@ 		dec	[bp+YSize]	; uint16_t
//@ ; #line	"CSVESA.PAS" 310
//@ 		jz	short loc_2B1F8	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 311
//@ 		add	si, [bp+SiIncr]	; int16_t
//@ ; #line	"CSVESA.PAS" 312
//@ 		add	di, [bp+AddNum]	; int16_t
//@ ; #line	"CSVESA.PAS" 313
//@ 		jnb	short loc_2B1B4	; Jump if Not Below (CF=0)
//@ ; #line	"CSVESA.PAS" 314
//@ 		inc	dx		; Increment by 1
//@ ; #line	"CSVESA.PAS" 315
//@ 		call	OnlySwitchBank	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 316
//@ 		jmp	short loc_2B1B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 319
//@ 
//@ loc_2B1F8:				; CODE XREF: VESA_PutImage+71j
//@ 		pop	ds
//@ ; #line	"CSVESA.PAS" 320
//@ 		mov	VESABank, dx	; uint16_t
//@ ; #line	"CSVESA.PAS" 321
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ VESA_PutImage	endp
//@ 
//@ ; #line	"CSVESA.PAS" 392
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VESA_Line	proc far		; CODE XREF: vesa_DrawKey+3FP
//@ 					; vesa_DrawKey+60P ...
//@ 
//@ y2		= word ptr  6		; int16_t
//@ x2		= word ptr  8		; int16_t
//@ y1		= word ptr  0Ah		; int16_t
//@ x1		= word ptr  0Ch		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 393
//@ 		mov	ax, SegA000	; uint16_t
//@ ; #line	"CSVESA.PAS" 394
//@ 		mov	es, ax
//@ ; #line	"CSVESA.PAS" 395
//@ 		mov	ax, 280h
//@ ; #line	"CSVESA.PAS" 396
//@ 		mul	[bp+y1]		; int16_t
//@ ; #line	"CSVESA.PAS" 397
//@ 		add	ax, [bp+x1]	; int16_t
//@ ; #line	"CSVESA.PAS" 398
//@ 		adc	dx, 0		; Add with Carry
//@ ; #line	"CSVESA.PAS" 399
//@ 		mov	di, ax
//@ ; #line	"CSVESA.PAS" 400
//@ 		cmp	dx, VESABank	; uint16_t
//@ ; #line	"CSVESA.PAS" 401
//@ 		jz	short loc_2B222	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 402
//@ 		call	SwitchBank	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 405
//@ 
//@ loc_2B222:				; CODE XREF: VESA_Line+1Aj
//@ 		mov	ax, [bp+x1]	; int16_t
//@ ; #line	"CSVESA.PAS" 406
//@ 		cmp	ax, [bp+x2]	; int16_t
//@ ; #line	"CSVESA.PAS" 407
//@ 		jz	short loc_2B25B	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 409
//@ 		mov	cx, [bp+x2]	; int16_t
//@ ; #line	"CSVESA.PAS" 410
//@ 		sub	cx, [bp+x1]	; int16_t
//@ ; #line	"CSVESA.PAS" 411
//@ 		js	short locret_2B27E ; Jump if Sign (SF=1)
//@ ; #line	"CSVESA.PAS" 413
//@ 		mov	ax, di
//@ ; #line	"CSVESA.PAS" 414
//@ 		add	ax, cx		; Add
//@ ; #line	"CSVESA.PAS" 415
//@ 		jb	short loc_2B241	; Jump if Below	(CF=1)
//@ ; #line	"CSVESA.PAS" 417
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSVESA.PAS" 418
//@ 		mov	al, VESA_CurrColor ; uint8_t
//@ ; #line	"CSVESA.PAS" 419
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSVESA.PAS" 420
//@ 		rep stosb		; Store	String
//@ ; #line	"CSVESA.PAS" 421
//@ 		jmp	short loc_2B259	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 424
//@ 
//@ loc_2B241:				; CODE XREF: VESA_Line+35j
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSVESA.PAS" 425
//@ 		mov	al, VESA_CurrColor ; uint8_t
//@ ; #line	"CSVESA.PAS" 427
//@ 
//@ loc_2B245:				; CODE XREF: VESA_Line+4Bj
//@ 					; VESA_Line+56j
//@ 		mov	es:[di], al
//@ ; #line	"CSVESA.PAS" 428
//@ 		dec	cx		; Decrement by 1
//@ ; #line	"CSVESA.PAS" 429
//@ 		jz	short loc_2B259	; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 430
//@ 		inc	di		; Increment by 1
//@ ; #line	"CSVESA.PAS" 431
//@ 		jnz	short loc_2B245	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 432
//@ 		inc	dx		; Increment by 1
//@ ; #line	"CSVESA.PAS" 433
//@ 		call	SwitchBank	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 434
//@ 		mov	al, VESA_CurrColor ; uint8_t
//@ ; #line	"CSVESA.PAS" 435
//@ 		jmp	short loc_2B245	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 437
//@ 
//@ loc_2B259:				; CODE XREF: VESA_Line+3Ej
//@ 					; VESA_Line+48j
//@ 		jmp	short locret_2B27E ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 439
//@ 
//@ loc_2B25B:				; CODE XREF: VESA_Line+27j
//@ 		mov	cx, [bp+y2]	; int16_t
//@ ; #line	"CSVESA.PAS" 440
//@ 		sub	cx, [bp+y1]	; int16_t
//@ ; #line	"CSVESA.PAS" 441
//@ 		js	short locret_2B27E ; Jump if Sign (SF=1)
//@ ; #line	"CSVESA.PAS" 443
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSVESA.PAS" 444
//@ 		mov	al, VESA_CurrColor ; uint8_t
//@ ; #line	"CSVESA.PAS" 446
//@ 
//@ loc_2B267:				; CODE XREF: VESA_Line+70j
//@ 					; VESA_Line+7Bj
//@ 		mov	es:[di], al
//@ ; #line	"CSVESA.PAS" 447
//@ 		dec	cx		; Decrement by 1
//@ ; #line	"CSVESA.PAS" 448
//@ 		jz	short locret_2B27E ; Jump if Zero (ZF=1)
//@ ; #line	"CSVESA.PAS" 449
//@ 		add	di, 280h	; Add
//@ ; #line	"CSVESA.PAS" 450
//@ 		jnb	short loc_2B267	; Jump if Not Below (CF=0)
//@ ; #line	"CSVESA.PAS" 451
//@ 		inc	dx		; Increment by 1
//@ ; #line	"CSVESA.PAS" 452
//@ 		call	SwitchBank	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 453
//@ 		mov	al, VESA_CurrColor ; uint8_t
//@ ; #line	"CSVESA.PAS" 454
//@ 		jmp	short loc_2B267	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 456
//@ 
//@ locret_2B27E:				; CODE XREF: VESA_Line+2Fj
//@ 					; VESA_Line:loc_2B259j	...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ VESA_Line	endp
//@ 
//@ ; #line	"CSVESA.PAS" 509
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ClearMonitorWindow proc	near		; CODE XREF: ClearUnusedScreens+2Ep
//@ 					; InitVESAMonitor+ADp
//@ 
//@ p		= word ptr -6		; int16_t
//@ H		= word ptr -4		; int16_t
//@ $Ch		= word ptr -2		; int16_t
//@ w		= word ptr  4		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 510
//@ 		mov	di, [bp+w]	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 27Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSVESA.PAS" 512
//@ 		mov	ax, WinH	; uint16_t
//@ 		mov	[bp+H],	ax	; int16_t
//@ 		mov	di, [bp+w]	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di+280h]
//@ 		mov	[bp+p],	ax	; int16_t
//@ ; #line	"CSVESA.PAS" 514
//@ 
//@ loc_2B2A5:				; CODE XREF: ClearMonitorWindow+65j
//@ 		cmp	[bp+H],	40h ; '@' ; int16_t
//@ 		jle	short loc_2B2B2	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+$Ch], 40h ;	'@' ; int16_t
//@ 		jmp	short loc_2B2B8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B2B2:				; CODE XREF: ClearMonitorWindow+27j
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		mov	[bp+$Ch], ax	; int16_t
//@ ; #line	"CSVESA.PAS" 515
//@ 
//@ loc_2B2B8:				; CODE XREF: ClearMonitorWindow+2Ej
//@ 		mov	di, [bp+w]	; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		push	word ptr [di+27Eh]
//@ 		push	[bp+p]		; int16_t
//@ 		push	130h
//@ 		push	[bp+$Ch]	; int16_t
//@ 		push	140h
//@ 		les	di, Ground	; void*
//@ 		assume es:nothing
//@ 		push	es
//@ 		push	di
//@ 		call	VESA_PutImage	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 516
//@ 		add	[bp+p],	40h ; '@' ; int16_t
//@ 		mov	ax, [bp+$Ch]	; int16_t
//@ 		sub	[bp+H],	ax	; int16_t
//@ ; #line	"CSVESA.PAS" 517
//@ 		cmp	[bp+H],	0	; int16_t
//@ 		jnz	short loc_2B2A5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 519
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ ClearMonitorWindow endp
//@ 
//@ ; #line	"CSVESA.PAS" 524
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ClearUnusedScreens proc	far		; CODE XREF: LoadClientPatch+101P
//@ 					; LoadClientPatch+326P	...
//@ 
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 525
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2B2FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B2F8:				; CODE XREF: ClearUnusedScreens+35j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSVESA.PAS" 526
//@ 
//@ loc_2B2FB:				; CODE XREF: ClearUnusedScreens+9j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	al, [di-0AC0h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	58h	; Signed Multiply
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_2B318	; Jump if Zero (ZF=1)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		cmp	byte ptr [di-0AC0h], 0 ; Compare Two Operands
//@ 		jnz	short loc_2B31E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 527
//@ 
//@ loc_2B318:				; CODE XREF: ClearUnusedScreens+1Fj
//@ 		push	[bp+n]		; int16_t
//@ 		call	ClearMonitorWindow ; function near PASCAL returns void
//@ 
//@ loc_2B31E:				; CODE XREF: ClearUnusedScreens+29j
//@ 		cmp	[bp+n],	3	; int16_t
//@ 		jnz	short loc_2B2F8	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 528
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ClearUnusedScreens endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aServerStartNet	db 25,'SERVER START NET MONITOR.' ; DATA XREF: InitVESAMonitor+81o
//@ ; #line	"CSVESA.PAS" 531
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitVESAMonitor	proc far		; CODE XREF: SwitchMonitor+FP
//@ 					; DoGame+203P
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 535
//@ 		mov	ax, CurVideoMode ; uint16_t
//@ 		mov	ServerSaved.VMode, ax ;	struct ServerSaved$Type
//@ ; #line	"CSVESA.PAS" 536
//@ 		mov	ax, Players.PlHx ; struct TPlayerInfo[8]
//@ 		mov	ServerSaved.svhx, ax ; struct ServerSaved$Type
//@ ; #line	"CSVESA.PAS" 537
//@ 		mov	ax, Players.PlHy ; struct TPlayerInfo[8]
//@ 		mov	ServerSaved.svhy, ax ; struct ServerSaved$Type
//@ ; #line	"CSVESA.PAS" 538
//@ 		mov	ax, Players.Plhz0 ; struct TPlayerInfo[8]
//@ 		mov	ServerSaved.svhz, ax ; struct ServerSaved$Type
//@ ; #line	"CSVESA.PAS" 539
//@ 		push	Players.PlHx	; struct TPlayerInfo[8]
//@ 		push	Players.PlHy	; struct TPlayerInfo[8]
//@ 		push	6
//@ 		push	1Ah
//@ 		push	60h ; '`'
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 540
//@ 		mov	Players.PlHx, 280h ; struct TPlayerInfo[8]
//@ 		mov	ax, Players.PlHx ; struct TPlayerInfo[8]
//@ 		mov	Players.PlHy, ax ; struct TPlayerInfo[8]
//@ ; #line	"CSVESA.PAS" 544
//@ 		mov	CurVideoMode, 1	; uint16_t
//@ ; #line	"CSVESA.PAS" 545
//@ 		call	AllocVideo	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 546
//@ 		call	SetVideoMode	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 547
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 549
//@ 		mov	Console, 1	; bool
//@ ; #line	"CSVESA.PAS" 550
//@ 		push	100h
//@ 		call	SetVESAMode	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 551
//@ 		push	word ptr VesaTiler+2 ; void*
//@ 		push	word ptr VesaTiler ; void*
//@ 		call	VESA_TileScreen	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 552
//@ 		push	148h
//@ 		push	147h
//@ 		push	277h
//@ 		push	18Bh
//@ 		push	2
//@ 		push	4
//@ 		push	1
//@ 		call	vesa_DrawKey	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 553
//@ 		mov	di, offset aServerStartNet ; "SERVER START NET MONITOR."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 556
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2B3D6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B3D2:				; CODE XREF: InitVESAMonitor+D9j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2B3D6:				; CODE XREF: InitVESAMonitor+90j
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		add	di, 27Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSVESA.PAS" 558
//@ 		push	n$0		; int16_t
//@ 		call	ClearMonitorWindow ; function near PASCAL returns void
//@ ; #line	"CSVESA.PAS" 559
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di]
//@ 		add	ax, 12Fh	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, 95h	; 'ﾕ'   ; Add
//@ 		push	ax
//@ 		push	3
//@ 		push	1
//@ 		push	4
//@ 		call	vesa_DrawKey	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 560
//@ 		cmp	n$0, 3		; int16_t
//@ 		jnz	short loc_2B3D2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 561
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitVESAMonitor	endp
//@ 
//@ ; #line	"CSVESA.PAS" 565
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VESA_TileScreen	proc far		; CODE XREF: InitVESAMonitor+65P
//@ 
//@ x		= word ptr -8		; uint16_t
//@ H		= word ptr -6		; uint16_t
//@ HH		= word ptr -4		; uint16_t
//@ y0		= word ptr -2		; uint16_t
//@ p		= dword	ptr  6		; void*
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 566
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y0], ax	; uint16_t
//@ 		mov	[bp+H],	190h	; uint16_t
//@ ; #line	"CSVESA.PAS" 568
//@ 
//@ loc_2B42B:				; CODE XREF: VESA_TileScreen+5Aj
//@ 		cmp	[bp+H],	40h ; '@' ; uint16_t
//@ 		jbe	short loc_2B438	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	[bp+HH], 40h ; '@' ; uint16_t
//@ 		jmp	short loc_2B43E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B438:				; CODE XREF: VESA_TileScreen+12j
//@ 		mov	ax, [bp+H]	; uint16_t
//@ 		mov	[bp+HH], ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 569
//@ 
//@ loc_2B43E:				; CODE XREF: VESA_TileScreen+19j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_2B448	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B445:				; CODE XREF: VESA_TileScreen+4Aj
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSVESA.PAS" 570
//@ 
//@ loc_2B448:				; CODE XREF: VESA_TileScreen+26j
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	[bp+y0]		; uint16_t
//@ 		push	40h ; '@'
//@ 		push	[bp+HH]		; uint16_t
//@ 		push	40h ; '@'
//@ 		les	di, [bp+p]	; void*
//@ 		push	es
//@ 		push	di
//@ 		call	VESA_PutImage	; function far PASCAL returns void
//@ 		cmp	[bp+x],	9	; uint16_t
//@ 		jnz	short loc_2B445	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 571
//@ 		add	[bp+y0], 40h ; '@' ; uint16_t
//@ 		mov	ax, [bp+HH]	; uint16_t
//@ 		sub	[bp+H],	ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 572
//@ 		cmp	[bp+H],	0	; uint16_t
//@ 		jnz	short loc_2B42B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 573
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ VESA_TileScreen	endp
//@ 
//@ ; #line	"CSVESA.PAS" 577
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ vesa_DrawKey	proc far		; CODE XREF: RedrawWindowSelection+46P
//@ 					; RedrawWindowSelection+81P ...
//@ 
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; int16_t
//@ c2		= byte ptr  6		; uint8_t
//@ c1		= byte ptr  8		; uint8_t
//@ H		= word ptr  0Ah		; int16_t
//@ y2		= word ptr  0Ch		; int16_t
//@ x2		= word ptr  0Eh		; int16_t
//@ y1		= word ptr  10h		; int16_t
//@ x1		= word ptr  12h		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 578
//@ 		mov	ax, [bp+H]	; int16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jle	short loc_2B492	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_2B535	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B492:				; CODE XREF: vesa_DrawKey+10j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2B49A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B497:				; CODE XREF: vesa_DrawKey+B5j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSVESA.PAS" 580
//@ 
//@ loc_2B49A:				; CODE XREF: vesa_DrawKey+18j
//@ 		mov	al, [bp+c1]	; uint8_t
//@ 		mov	VESA_CurrColor,	al ; uint8_t
//@ ; #line	"CSVESA.PAS" 581
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		call	VESA_Line	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 582
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		call	VESA_Line	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 583
//@ 		mov	al, [bp+c2]	; uint8_t
//@ 		mov	VESA_CurrColor,	al ; uint8_t
//@ ; #line	"CSVESA.PAS" 584
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		call	VESA_Line	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 585
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		call	VESA_Line	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 586
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short locret_2B535 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2B497	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 587
//@ 
//@ locret_2B535:				; CODE XREF: vesa_DrawKey+12j
//@ 					; vesa_DrawKey+B3j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ vesa_DrawKey	endp
//@ 
//@ ; #line	"CSVESA.PAS" 594
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReDrawGround	proc far		; CODE XREF: DoGame+22BP PROGRAM+D01P	...
//@ 
//@ var_92		= word ptr -92h
//@ c		= word ptr -90h		; uint16_t
//@ w		= word ptr -8Eh		; uint16_t
//@ n		= word ptr -8Ch		; uint16_t
//@ var_8A		= word ptr -8Ah		; int32_t
//@ var_88		= word ptr -88h
//@ gp		= word ptr -86h		; int32_t
//@ var_84		= word ptr -84h
//@ 
//@ 		enter	92h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 595
//@ 		mov	ax, VideoEY	; uint16_t
//@ 		mov	[bp+var_92], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_92]	; Compare Two Operands
//@ 		jbe	short loc_2B54F	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_2B5F9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B54F:				; CODE XREF: ReDrawGround+11j
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2B559	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B555:				; CODE XREF: ReDrawGround+BDj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSVESA.PAS" 597
//@ 
//@ loc_2B559:				; CODE XREF: ReDrawGround+1Aj
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	[bp+w],	ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 598
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	ax, [di-6E84h]
//@ 		mov	dx, [di-6E82h]
//@ 		mov	[bp+var_8A], ax	; int32_t
//@ 		mov	[bp+var_88], dx
//@ ; #line	"CSVESA.PAS" 599
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		and	ax, 3Fh		; Logical AND
//@ 		imul	ax, 140h	; Signed Multiply
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	[bp+gp], ax	; int32_t
//@ 		mov	[bp+var_84], dx
//@ ; #line	"CSVESA.PAS" 600
//@ 
//@ loc_2B58C:				; CODE XREF: ReDrawGround+B1j
//@ 		cmp	[bp+w],	0	; uint16_t
//@ 		jbe	short loc_2B5EC	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSVESA.PAS" 602
//@ 		cmp	[bp+w],	140h	; uint16_t
//@ 		jbe	short loc_2B5A3	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	[bp+c],	140h	; uint16_t
//@ 		jmp	short loc_2B5AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B5A3:				; CODE XREF: ReDrawGround+60j
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		mov	[bp+c],	ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 603
//@ 
//@ loc_2B5AB:				; CODE XREF: ReDrawGround+68j
//@ 		les	di, Ground	; void*
//@ 		push	es
//@ 		push	[bp+var_84]
//@ 		push	[bp+gp]		; int32_t
//@ 		push	VgaSeg		; uint16_t
//@ 		push	[bp+var_88]
//@ 		push	[bp+var_8A]	; int32_t
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovsED		; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 605
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		sub	[bp+w],	ax	; uint16_t
//@ 		mov	ax, [bp+c]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	[bp+var_8A], ax	; int32_t
//@ 		adc	[bp+var_88], dx	; Add with Carry
//@ ; #line	"CSVESA.PAS" 606
//@ 		jmp	short loc_2B58C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 607
//@ 
//@ loc_2B5EC:				; CODE XREF: ReDrawGround+58j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_92]	; Compare Two Operands
//@ 		jz	short locret_2B5F9 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2B555	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 608
//@ 
//@ locret_2B5F9:				; CODE XREF: ReDrawGround+13j
//@ 					; ReDrawGround+BBj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ReDrawGround	endp
//@ 
//@ ; #line	"CSVESA.PAS" 616
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowVideoBuffer	proc far		; CODE XREF: PlayBrifing+48BP
//@ 					; PlayBrifing+532P ...
//@ 
//@ W		= word ptr -6		; uint16_t
//@ DWordsLeft	= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 617
//@ 		cmp	CurVideoMode, 1	; uint16_t
//@ 		jnz	short loc_2B61D	; Jump if Not Zero (ZF=0)
//@ 		push	VgaSeg		; uint16_t
//@ 		push	0
//@ 		push	SegA000		; uint16_t
//@ 		push	0
//@ 		push	3E80h
//@ 		call	movsD$0		; function far PASCAL returns void
//@ 		jmp	locret_2B6C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 618
//@ 
//@ loc_2B61D:				; CODE XREF: ShowVideoBuffer+9j
//@ 		cmp	VideoIsFlat, 0	; bool
//@ 		jz	short loc_2B64E	; Jump if Zero (ZF=1)
//@ 		push	VgaSeg		; uint16_t
//@ 		push	0
//@ 		push	0
//@ 		push	FLATSelector	; uint16_t
//@ 		push	0
//@ 		push	0
//@ 		mov	ax, word ptr VPSize ; int32_t
//@ 		mov	dx, word ptr VPSize+2 ;	int32_t
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		push	dx
//@ 		push	ax
//@ 		call	MovsED		; function far PASCAL returns void
//@ 		jmp	short locret_2B6C1 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 621
//@ 
//@ loc_2B64E:				; CODE XREF: ShowVideoBuffer+27j
//@ 		mov	ax, word ptr VPSize ; int32_t
//@ 		mov	dx, word ptr VPSize+2 ;	int32_t
//@ 		mov	cx, 2
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+DWordsLeft], ax ; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSVESA.PAS" 622
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	VESABank, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 624
//@ 
//@ loc_2B66A:				; CODE XREF: ShowVideoBuffer+C4j
//@ 		cmp	[bp+var_2], 0	; Compare Two Operands
//@ 		jg	short loc_2B679	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2B680	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+DWordsLeft], 4000h ; int32_t
//@ 		jbe	short loc_2B680	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2B679:				; CODE XREF: ShowVideoBuffer+73j
//@ 		mov	[bp+W],	4000h	; uint16_t
//@ 		jmp	short loc_2B686	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 625
//@ 
//@ loc_2B680:				; CODE XREF: ShowVideoBuffer+75j
//@ 					; ShowVideoBuffer+7Cj
//@ 		mov	ax, [bp+DWordsLeft] ; int32_t
//@ 		mov	[bp+W],	ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 627
//@ 
//@ loc_2B686:				; CODE XREF: ShowVideoBuffer+83j
//@ 		mov	dx, VESABank	; uint16_t
//@ ; #line	"CSVESA.PAS" 628
//@ 		call	SwitchBank	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 630
//@ 		mov	ax, VESABank	; uint16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		add	ax, VgaSeg	; uint16_t
//@ 		push	ax
//@ 		push	0
//@ 		push	SegA000		; uint16_t
//@ 		push	0
//@ 		push	[bp+W]		; uint16_t
//@ 		call	movsD$0		; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 631
//@ 		mov	ax, [bp+W]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	[bp+DWordsLeft], ax ; int32_t
//@ 		sbb	[bp+var_2], dx	; Integer Subtraction with Borrow
//@ ; #line	"CSVESA.PAS" 632
//@ 		inc	VESABank	; uint16_t
//@ ; #line	"CSVESA.PAS" 633
//@ 		mov	ax, [bp+DWordsLeft] ; int32_t
//@ 		or	ax, [bp+var_2]	; Logical Inclusive OR
//@ 		jnz	short loc_2B66A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 635
//@ 
//@ locret_2B6C1:				; CODE XREF: ShowVideoBuffer+1Fj
//@ 					; ShowVideoBuffer+51j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ShowVideoBuffer	endp
//@ 
//@ ; #line	"CSVESA.PAS" 640
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Init320x200	proc near		; CODE XREF: SetVideoMode+Cp
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSVESA.PAS" 641
//@ 		mov	ax, 13h
//@ 		int	10h		; - VIDEO - SET	VIDEO MODE
//@ 					; AL = mode
//@ ; #line	"CSVESA.PAS" 642
//@ 		mov	word ptr VideoW, 140h ;	int32_t
//@ 		mov	word ptr VideoW+2, 0 ; int32_t
//@ ; #line	"CSVESA.PAS" 643
//@ 		mov	word ptr VideoH, 0C8h ;	'￈' ; int32_t
//@ 		mov	word ptr VideoH+2, 0 ; int32_t
//@ ; #line	"CSVESA.PAS" 644
//@ 		mov	word ptr VideoBPL, 140h	; int32_t
//@ 		mov	word ptr VideoBPL+2, 0 ; int32_t
//@ ; #line	"CSVESA.PAS" 645
//@ 		mov	FloorDiv, 0Ah	; uint16_t
//@ ; #line	"CSVESA.PAS" 646
//@ 		mov	VideoIsFlat, 0	; bool
//@ ; #line	"CSVESA.PAS" 647
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ Init320x200	endp
//@ 
//@ ; #line	"CSVESA.PAS" 650
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Init_HiMode	proc near		; CODE XREF: SetVideoMode:loc_2B78Dp
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ 		imul	di, CurVideoMode, 0Dh ;	uint16_t
//@ 		add	di, 0F42Fh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSVESA.PAS" 652
//@ 		mov	VideoIsFlat, 0	; bool
//@ ; #line	"CSVESA.PAS" 653
//@ 		cmp	VideoIsFlat, 0	; bool
//@ 		jz	short loc_2B72B	; Jump if Zero (ZF=1)
//@ 		mov	ax, es:[di]
//@ 		add	ax, 4000h	; Add
//@ 		push	ax
//@ 		call	SetVESAMode	; function far PASCAL returns void
//@ 		jmp	short loc_2B736	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 654
//@ 
//@ loc_2B72B:				; CODE XREF: Init_HiMode+1Fj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		call	SetVESAMode	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 656
//@ 
//@ loc_2B736:				; CODE XREF: Init_HiMode+2Dj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr VideoW, ax ; int32_t
//@ 		mov	word ptr VideoW+2, dx ;	int32_t
//@ ; #line	"CSVESA.PAS" 657
//@ 		mov	ax, es:[di+4]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr VideoH, ax ; int32_t
//@ 		mov	word ptr VideoH+2, dx ;	int32_t
//@ ; #line	"CSVESA.PAS" 658
//@ 		mov	ax, es:[di+6]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr VideoBPL, ax ;	int32_t
//@ 		mov	word ptr VideoBPL+2, dx	; int32_t
//@ ; #line	"CSVESA.PAS" 659
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, 10h		; Add
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	FloorDiv, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 661
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ Init_HiMode	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_2B76F	db 3,'###'              ; DATA XREF: SetVideoMode+EAo
//@ 					; SetVideoMode+118o
//@ aMode		db 6,'Mode: '           ; DATA XREF: SetVideoMode+DAo
//@ asc_2B77A	db 1,'x'                ; DATA XREF: SetVideoMode+108o
//@ ; #line	"CSVESA.PAS" 667
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetVideoMode	proc far		; CODE XREF: DeinitMonitor+17P
//@ 					; SwitchMonitor+46P ...
//@ 
//@ var_304		= byte ptr -304h
//@ var_204		= byte ptr -204h
//@ var_104		= byte ptr -104h
//@ n		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ 
//@ 		enter	304h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSVESA.PAS" 668
//@ 		mov	ax, CurVideoMode ; uint16_t
//@ ; #line	"CSVESA.PAS" 669
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_2B78D	; Jump if Not Zero (ZF=0)
//@ 		call	Init320x200	; function near	PASCAL returns void
//@ 		jmp	short loc_2B790	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSVESA.PAS" 670
//@ 
//@ loc_2B78D:				; CODE XREF: SetVideoMode+Aj
//@ 		call	Init_HiMode	; function near	PASCAL returns void
//@ ; #line	"CSVESA.PAS" 673
//@ 
//@ loc_2B790:				; CODE XREF: SetVideoMode+Fj
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	VideoEX, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 674
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	VideoEY, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 675
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	VideoCX, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 676
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	VideoCY, ax	; uint16_t
//@ ; #line	"CSVESA.PAS" 677
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		mov	cx, word ptr VideoH ; int32_t
//@ 		mov	bx, word ptr VideoH+2 ;	int32_t
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	word ptr VPSize, ax ; int32_t
//@ 		mov	word ptr VPSize+2, dx ;	int32_t
//@ ; #line	"CSVESA.PAS" 678
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int32_t
//@ 		mov	[bp+var_2], ax
//@ 		jmp	short loc_2B805	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2B7FD:				; CODE XREF: SetVideoMode+AEj
//@ 					; SetVideoMode+B5j
//@ 		add	[bp+n],	1	; int32_t
//@ 		adc	[bp+var_2], 0	; Add with Carry
//@ 
//@ loc_2B805:				; CODE XREF: SetVideoMode+7Fj
//@ 		mov	ax, [bp+n]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, word ptr VideoBPL ;	int32_t
//@ 		mov	bx, word ptr VideoBPL+2	; int32_t
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	di, [bp+n]	; int32_t
//@ 		shl	di, 2		; Shift	Logical	Left
//@ 		mov	[di-6E84h], ax
//@ 		mov	[di-6E82h], dx
//@ 		cmp	[bp+var_2], 0	; Compare Two Operands
//@ 		jnz	short loc_2B7FD	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+n],	2BCh	; int32_t
//@ 		jnz	short loc_2B7FD	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSVESA.PAS" 679
//@ 		les	di, LinesBUF	; TLinesBuf*
//@ 		push	es
//@ 		push	di
//@ 		push	2400h
//@ 		push	0FFFFh
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSVESA.PAS" 680
//@ 		call	SetPalette	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 681
//@ 		push	0C8h ; '￈'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 682
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMode ; "Mode: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_104] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2B76F ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2B77A ; "x"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_2B76F ; "###"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSVESA.PAS" 683
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ SetVideoMode	endp
//@ 
