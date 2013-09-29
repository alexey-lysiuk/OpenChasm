
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

#include "csipx.h"

//@ ; #line	"CSIPX.PAS" 80
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetRealModeIntVector proc near		; CODE XREF: CheckNP+Bp
//@ 
//@ vector		= dword	ptr  4		; void*
//@ IntNo		= byte ptr  8		; uint8_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 81
//@ 		mov	ax, 200h
//@ ; #line	"CSIPX.PAS" 82
//@ 		mov	bl, [bp+IntNo]	; uint8_t
//@ ; #line	"CSIPX.PAS" 83
//@ 		int	31h		; DPMI Services	  ax=func xxxxh
//@ 					; GET REAL MODE	INTERRUPT VECTOR
//@ 					; BL = interrupt number
//@ 					; Return: CF clear, CX:DX = segment:offset of real mode	interrupt handler
//@ ; #line	"CSIPX.PAS" 84
//@ 		les	di, [bp+vector]	; void*
//@ ; #line	"CSIPX.PAS" 85
//@ 		mov	es:[di], dx
//@ ; #line	"CSIPX.PAS" 86
//@ 		mov	es:[di+2], cx
//@ ; #line	"CSIPX.PAS" 87
//@ 		leave			; High Level Procedure Exit
//@ 		retn	6		; Return Near from Procedure
//@ GetRealModeIntVector endp
//@ 
//@ ; #line	"CSIPX.PAS" 90
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RealInt60h	proc near		; CODE XREF: DO_CD_Play+47p
//@ 					; DO_CD_Play+83p ...
//@ 
//@ DPMIRegs	= dword	ptr  4		; struct TDPMIRegs
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 91
//@ 		cmp	NPinst,	0	; bool
//@ ; #line	"CSIPX.PAS" 92
//@ 		jz	short locret_32	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 93
//@ 		mov	bx, 60h	; '`'
//@ ; #line	"CSIPX.PAS" 94
//@ 		xor	cx, cx		; Logical Exclusive OR
//@ ; #line	"CSIPX.PAS" 95
//@ 		les	di, [bp+DPMIRegs] ; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 96
//@ 		mov	ax, 300h
//@ ; #line	"CSIPX.PAS" 97
//@ 		int	31h		; DPMI Services	  ax=func xxxxh
//@ 					; SIMULATE REAL	MODE INTERRUPT
//@ 					; BL=interrupt number
//@ 					; CX=number of words to	copy from protected mode to real mode stack
//@ 					; ES:DI	/ ES:EDI = selector:offset of real mode	call structure
//@ 					; Return: CF set on error
//@ 					; CF clear if ok
//@ ; #line	"CSIPX.PAS" 99
//@ 
//@ locret_32:				; CODE XREF: RealInt60h+8j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ RealInt60h	endp
//@ 
//@ ; #line	"CSIPX.PAS" 102
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DO_CD_Play	proc near		; CODE XREF: ProcessCD+41p
//@ 					; ExecConsole+D1Bp ...
//@ 
//@ Track		= word ptr  4		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 103
//@ 		mov	ax, CDTrack	; int16_t
//@ 		cmp	ax, [bp+Track]	; int16_t
//@ 		jnz	short loc_44	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_FD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 104
//@ 
//@ loc_44:					; CODE XREF: DO_CD_Play+9j
//@ 		cmp	[bp+Track], 0	; int16_t
//@ 		jnz	short loc_4D	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_FD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 105
//@ 
//@ loc_4D:					; CODE XREF: DO_CD_Play+12j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LCDTrack, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 106
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CDTrack, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 107
//@ 		cmp	MSCDEX,	0	; bool
//@ 		jnz	short loc_61	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_FD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 109
//@ 
//@ loc_61:					; CODE XREF: DO_CD_Play+26j
//@ 		mov	word ptr DRegs.xBX, 0CDh ; 'Í' ; struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 110
//@ 		mov	ax, [bp+Track]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	word ptr DRegs.xCX, ax ; struct	TDPMIRegs
//@ 		mov	word ptr DRegs.xCX+2, dx ; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 111
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 113
//@ 		cmp	[bp+Track], 0FFh ; int16_t
//@ 		jnz	short loc_89	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_FD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 116
//@ 
//@ loc_89:					; CODE XREF: DO_CD_Play+4Fj
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	byte ptr es:[di+183h], 0 ; Compare Two Operands
//@ 		jnz	short loc_BC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 118
//@ 		push	0C8h ; 'È'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 119
//@ 		mov	word ptr DRegs.xBX, 0CDh ; 'Í' ; struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 120
//@ 		mov	ax, [bp+Track]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	word ptr DRegs.xCX, ax ; struct	TDPMIRegs
//@ 		mov	word ptr DRegs.xCX+2, dx ; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 121
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 124
//@ 
//@ loc_BC:					; CODE XREF: DO_CD_Play+5Dj
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	byte ptr es:[di+183h], 1 ; Compare Two Operands
//@ 		jnz	short locret_FD	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 126
//@ 		mov	ax, [bp+Track]	; int16_t
//@ 		mov	CDTrack, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 127
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	ax, es:[di+184h]
//@ 		mov	dx, es:[di+186h]
//@ 		mov	cx, 8Ch	; 'Œ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 4Bh	; 'K'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		sub	ax, 46h	; 'F'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	word ptr CDTime, ax ; int32_t
//@ 		mov	word ptr CDTime+2, dx ;	int32_t
//@ ; #line	"CSIPX.PAS" 129
//@ 
//@ locret_FD:				; CODE XREF: DO_CD_Play+Bj
//@ 					; DO_CD_Play+14j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ DO_CD_Play	endp
//@ 
//@ ; #line	"CSIPX.PAS" 133
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DO_CD_Stop	proc near		; CODE XREF: ExecConsole+D25p
//@ 					; CheckQuit+3p	...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 134
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CDTrack, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 135
//@ 		cmp	MSCDEX,	0	; bool
//@ 		jnz	short loc_112	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_132 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 136
//@ 
//@ loc_112:				; CODE XREF: DO_CD_Stop+Dj
//@ 		mov	word ptr DRegs.xBX, 0CDh ; 'Í' ; struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 137
//@ 		mov	word ptr DRegs.xCX, 0FFh ; struct TDPMIRegs
//@ 		mov	word ptr DRegs.xCX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 138
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 139
//@ 
//@ locret_132:				; CODE XREF: DO_CD_Stop+Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DO_CD_Stop	endp
//@ 
//@ ; #line	"CSIPX.PAS" 143
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ProcessCD	proc near		; CODE XREF: DoGame+319p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 144
//@ 		cmp	CDTrack, 0	; int16_t
//@ 		jnz	short loc_140	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_178 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 145
//@ 
//@ loc_140:				; CODE XREF: ProcessCD+8j
//@ 		cmp	MSCDEX,	0	; bool
//@ 		jnz	short loc_149	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_178 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 147
//@ 
//@ loc_149:				; CODE XREF: ProcessCD+11j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	word ptr CDTime, ax ; int32_t
//@ 		sbb	word ptr CDTime+2, dx ;	int32_t
//@ ; #line	"CSIPX.PAS" 148
//@ 		cmp	word ptr CDTime+2, 0 ; int32_t
//@ 		jl	short loc_166	; Jump if Less (SF!=OF)
//@ 		jg	short locret_178 ; Jump	if Greater (ZF=0 & SF=OF)
//@ 		cmp	word ptr CDTime, 0 ; int32_t
//@ 		ja	short locret_178 ; Jump	if Above (CF=0 & ZF=0)
//@ ; #line	"CSIPX.PAS" 149
//@ 
//@ loc_166:				; CODE XREF: ProcessCD+27j
//@ 		mov	ax, CDTrack	; int16_t
//@ 		mov	w, ax		; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CDTrack, ax	; int16_t
//@ 		push	w		; uint16_t
//@ 		call	DO_CD_Play	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 150
//@ 
//@ locret_178:				; CODE XREF: ProcessCD+Aj
//@ 					; ProcessCD+13j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ProcessCD	endp
//@ 
//@ ; #line	"CSIPX.PAS" 159
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RefreshMachineMode proc	near		; CODE XREF: DoGame:loc_C58Cp
//@ 					; DoGame:loc_DC33p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 160
//@ 		cmp	NPinst,	0	; bool
//@ 		jnz	short loc_186	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_1B6 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 161
//@ 
//@ loc_186:				; CODE XREF: RefreshMachineMode+8j
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_199	; Jump if Zero (ZF=1)
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	word ptr es:[di+6], 1
//@ 		jmp	short locret_1B6 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 162
//@ 
//@ loc_199:				; CODE XREF: RefreshMachineMode+11j
//@ 		cmp	CLIENT,	0	; bool
//@ 		jz	short loc_1AC	; Jump if Zero (ZF=1)
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	word ptr es:[di+6], 2
//@ 		jmp	short locret_1B6 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 163
//@ 
//@ loc_1AC:				; CODE XREF: RefreshMachineMode+24j
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSIPX.PAS" 164
//@ 
//@ locret_1B6:				; CODE XREF: RefreshMachineMode+Aj
//@ 					; RefreshMachineMode+1Dj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ RefreshMachineMode endp
//@ 
//@ ; #line	"CSIPX.PAS" 167
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReInstallFreeECB proc near		; CODE XREF: LoadServerPatch:loc_1684p
//@ 					; LookForServer+31p ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 169
//@ 		mov	word ptr DRegs.xBX, 2 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 170
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 171
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ReInstallFreeECB endp
//@ 
//@ ; #line	"CSIPX.PAS" 178
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReinitPlayer	proc near		; CODE XREF: LoadClientPatch+2Fp
//@ 					; DoGame+115p ...
//@ 
//@ var_A		= word ptr -0Ah
//@ var_8		= dword	ptr -8
//@ i		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ pn		= word ptr  4		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 179
//@ 		imul	di, [bp+pn], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSIPX.PAS" 181
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+40h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+42h], ax
//@ ; #line	"CSIPX.PAS" 182
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"CSIPX.PAS" 183
//@ 		mov	word ptr es:[di+2Ah], 300h
//@ ; #line	"CSIPX.PAS" 185
//@ 		mov	word ptr es:[di+28h], 64h ; 'd'
//@ ; #line	"CSIPX.PAS" 186
//@ 		mov	byte ptr es:[di+27h], 0
//@ ; #line	"CSIPX.PAS" 187
//@ 		mov	byte ptr es:[di+25h], 41h ; 'A'
//@ ; #line	"CSIPX.PAS" 188
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+52h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+50h], ax
//@ ; #line	"CSIPX.PAS" 189
//@ 		mov	ax, WeaponsCount ; uint16_t
//@ 		mov	[bp+var_A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jg	short loc_262	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_24D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_24A:				; CODE XREF: ReinitPlayer+8Fj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_24D:				; CODE XREF: ReinitPlayer+77j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+2Dh], 0
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jnz	short loc_24A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 190
//@ 
//@ loc_262:				; CODE XREF: ReinitPlayer+72j
//@ 		mov	al, byte ptr GunsInfo.StartCount ; struct TGunInfo[9]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2Eh], al
//@ ; #line	"CSIPX.PAS" 192
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		mov	byte ptr es:[di+24h], 2
//@ ; #line	"CSIPX.PAS" 193
//@ 		mov	al, LastBorn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		cmp	word ptr [di-1A80h], 0 ; Compare Two Operands
//@ 		jnz	short loc_292	; Jump if Not Zero (ZF=0)
//@ 		mov	LastBorn, 0	; uint8_t
//@ ; #line	"CSIPX.PAS" 194
//@ 
//@ loc_292:				; CODE XREF: ReinitPlayer+BAj
//@ 		mov	al, LastBorn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	ax, [di-1A80h]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSIPX.PAS" 195
//@ 		mov	al, LastBorn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	ax, [di-1A7Eh]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSIPX.PAS" 196
//@ 		mov	al, LastBorn	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	ax, [di-1A7Ch]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"CSIPX.PAS" 197
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	4Eh ; 'N'
//@ 		lea	di, [bp+i]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+n]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetLandHeight	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 198
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSIPX.PAS" 200
//@ 		cmp	[bp+pn], 0	; int16_t
//@ 		jnz	short loc_340	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 202
//@ 		mov	ax, es:[di+1Eh]
//@ 		mov	HFi, ax		; uint16_t
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 203
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+48h], 1
//@ 		mov	LastGunNumber, 1 ; uint16_t
//@ ; #line	"CSIPX.PAS" 204
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponPhase, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 205
//@ 		mov	GunShift, 2Eh ;	'.' ; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LookVz,	ax	; int16_t
//@ ; #line	"CSIPX.PAS" 206
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 208
//@ 
//@ loc_340:				; CODE XREF: ReinitPlayer+136j
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	ehx, ax		; int16_t
//@ ; #line	"CSIPX.PAS" 209
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	ehy, ax		; int16_t
//@ ; #line	"CSIPX.PAS" 210
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	6
//@ 		push	1Ah
//@ 		push	60h ; '`'
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 212
//@ 		inc	LastBorn	; uint8_t
//@ ; #line	"CSIPX.PAS" 213
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ ReinitPlayer	endp
//@ 
//@ ; #line	"CSIPX.PAS" 218
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ MakeChanges	proc near		; CODE XREF: LoadServerPatch+4D6p
//@ 
//@ l		= word ptr -6		; int16_t
//@ n		= byte ptr -3		; uint8_t
//@ b2		= byte ptr -2		; uint8_t
//@ b1		= byte ptr -1		; uint8_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 219
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+l],	ax	; int16_t
//@ 		jmp	short loc_37A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_377:				; CODE XREF: MakeChanges+85j
//@ 		inc	[bp+l]		; int16_t
//@ ; #line	"CSIPX.PAS" 221
//@ 
//@ loc_37A:				; CODE XREF: MakeChanges+9j
//@ 		mov	di, [bp+l]	; int16_t
//@ 		mov	al, [di-0D14h]
//@ 		mov	[bp+b1], al	; uint8_t
//@ ; #line	"CSIPX.PAS" 222
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		les	di, PServerLocal ; TServer_Patch*
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+20h]
//@ 		mov	[bp+b2], al	; uint8_t
//@ ; #line	"CSIPX.PAS" 223
//@ 		mov	al, [bp+b1]	; uint8_t
//@ 		cmp	al, [bp+b2]	; uint8_t
//@ 		jz	short loc_3ED	; Jump if Zero (ZF=1)
//@ 		mov	[bp+n],	0	; uint8_t
//@ 		jmp	short loc_3A5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3A2:				; CODE XREF: MakeChanges+7Fj
//@ 		inc	[bp+n]		; uint8_t
//@ ; #line	"CSIPX.PAS" 224
//@ 
//@ loc_3A5:				; CODE XREF: MakeChanges+34j
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, [bp+b2]	; uint8_t
//@ 		xor	al, [bp+b1]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_3E7	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 225
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, PChanges	; TChangesList$Element*
//@ 		add	di, ax		; Add
//@ ; #line	"CSIPX.PAS" 226
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		call	Blow3dObjAt	; function far PASCAL returns void
//@ 
//@ loc_3E7:				; CODE XREF: MakeChanges+55j
//@ 		cmp	[bp+n],	7	; uint8_t
//@ 		jnz	short loc_3A2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 227
//@ 
//@ loc_3ED:				; CODE XREF: MakeChanges+2Ej
//@ 		cmp	[bp+l],	0Fh	; int16_t
//@ 		jnz	short loc_377	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 228
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ MakeChanges	endp
//@ 
//@ ; #line	"CSIPX.PAS" 233
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DoneChanges	proc near		; CODE XREF: JoinNetworkGame+55p
//@ 
//@ var_E		= dword	ptr -0Eh
//@ l		= word ptr -6		; int16_t
//@ n		= byte ptr -3		; uint8_t
//@ b2		= byte ptr -2		; uint8_t
//@ b1		= byte ptr -1		; uint8_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 234
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+l],	ax	; int16_t
//@ 		jmp	short loc_403	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_400:				; CODE XREF: DoneChanges+C4j
//@ 		inc	[bp+l]		; int16_t
//@ ; #line	"CSIPX.PAS" 236
//@ 
//@ loc_403:				; CODE XREF: DoneChanges+9j
//@ 		mov	di, [bp+l]	; int16_t
//@ 		mov	al, [di-0D14h]
//@ 		mov	[bp+b1], al	; uint8_t
//@ ; #line	"CSIPX.PAS" 237
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+20h]
//@ 		mov	[bp+b2], al	; uint8_t
//@ ; #line	"CSIPX.PAS" 238
//@ 		mov	al, [bp+b1]	; uint8_t
//@ 		cmp	al, [bp+b2]	; uint8_t
//@ 		jnz	short loc_428	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_4B3		; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_428:				; CODE XREF: DoneChanges+2Ej
//@ 		mov	[bp+n],	0	; uint8_t
//@ 		jmp	short loc_431	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_42E:				; CODE XREF: DoneChanges+BBj
//@ 		inc	[bp+n]		; uint8_t
//@ ; #line	"CSIPX.PAS" 239
//@ 
//@ loc_431:				; CODE XREF: DoneChanges+37j
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, [bp+b2]	; uint8_t
//@ 		xor	al, [bp+b1]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		and	ax, dx		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_4AA	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 240
//@ 		mov	al, [bp+n]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		add	ax, dx		; Add
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, PChanges	; TChangesList$Element*
//@ 		add	di, ax		; Add
//@ 		imul	ax, es:[di+2], 0Bh ; Signed Multiply
//@ 		mov	dx, ax
//@ 		imul	ax, es:[di], 2C0h ; Signed Multiply
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"CSIPX.PAS" 242
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		cmp	word ptr [di+74B8h], 3E8h ; Compare Two	Operands
//@ 		jl	short loc_4A4	; Jump if Less (SF!=OF)
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		call	RemoveLight	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 243
//@ 
//@ loc_4A4:				; CODE XREF: DoneChanges+9Dj
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		inc	byte ptr es:[di] ; Increment by	1
//@ ; #line	"CSIPX.PAS" 244
//@ 
//@ loc_4AA:				; CODE XREF: DoneChanges+58j
//@ 		cmp	[bp+n],	7	; uint8_t
//@ 		jz	short loc_4B3	; Jump if Zero (ZF=1)
//@ 		jmp	loc_42E		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 245
//@ 
//@ loc_4B3:				; CODE XREF: DoneChanges+30j
//@ 					; DoneChanges+B9j
//@ 		cmp	[bp+l],	0Fh	; int16_t
//@ 		jz	short locret_4BC ; Jump	if Zero	(ZF=1)
//@ 		jmp	loc_400		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 246
//@ 
//@ locret_4BC:				; CODE XREF: DoneChanges+C2j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DoneChanges	endp
//@ 
//@ ; #line	"CSIPX.PAS" 250
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CorrectProcesses proc near		; CODE XREF: DoneProcesses+9p
//@ 					; LoadServerPatch+4D9p
//@ 
//@ var_C		= dword	ptr -0Ch
//@ LXor		= word ptr -8		; uint16_t
//@ Lnew		= word ptr -6		; uint16_t
//@ n		= word ptr -4		; int16_t
//@ p		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+p],	ax	; int16_t
//@ 		jmp	short loc_4CC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4C9:				; CODE XREF: CorrectProcesses+E2j
//@ 		inc	[bp+p]		; int16_t
//@ ; #line	"CSIPX.PAS" 252
//@ 
//@ loc_4CC:				; CODE XREF: CorrectProcesses+9j
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, PServerLocal ; TServer_Patch*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+30h]
//@ 		mov	[bp+Lnew], ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 253
//@ 		mov	ax, [bp+Lnew]	; uint16_t
//@ 		mov	di, [bp+p]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		xor	ax, [di-0D04h]	; Logical Exclusive OR
//@ 		mov	[bp+LXor], ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 254
//@ 		cmp	[bp+LXor], 0	; uint16_t
//@ 		jnz	short loc_4F6	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_59A		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 255
//@ 
//@ loc_4F6:				; CODE XREF: CorrectProcesses+33j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_500	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_4FD:				; CODE XREF: CorrectProcesses+D9j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSIPX.PAS" 256
//@ 
//@ loc_500:				; CODE XREF: CorrectProcesses+3Dj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 1
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+LXor]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		and	ax, cx		; Logical AND
//@ 		and	dx, bx		; Logical AND
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		jz	short loc_591	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 257
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		add	ax, [bp+n]	; int16_t
//@ 		imul	ax, 1E8h	; Signed Multiply
//@ 		les	di, PProc	; TProcess*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"CSIPX.PAS" 258
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 1
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+Lnew]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		and	ax, cx		; Logical AND
//@ 		and	dx, bx		; Logical AND
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		jz	short loc_572	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 259
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		add	ax, [bp+n]	; int16_t
//@ 		push	ax
//@ 		push	0
//@ 		call	StartProcess	; function far PASCAL returns void
//@ 		jmp	short loc_591	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 262
//@ 
//@ loc_572:				; CODE XREF: CorrectProcesses+9Fj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+1], 2 ;	Compare	Two Operands
//@ 		jz	short loc_581	; Jump if Zero (ZF=1)
//@ 		mov	byte ptr es:[di+1], 2
//@ ; #line	"CSIPX.PAS" 264
//@ 
//@ loc_581:				; CODE XREF: CorrectProcesses+BCj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+24h], 0	; Compare Two Operands
//@ 		jle	short loc_591	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+24h], ax
//@ ; #line	"CSIPX.PAS" 265
//@ 
//@ loc_591:				; CODE XREF: CorrectProcesses+63j
//@ 					; CorrectProcesses+B2j	...
//@ 		cmp	[bp+n],	0Fh	; int16_t
//@ 		jz	short loc_59A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_4FD		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 266
//@ 
//@ loc_59A:				; CODE XREF: CorrectProcesses+35j
//@ 					; CorrectProcesses+D7j
//@ 		cmp	[bp+p],	3	; int16_t
//@ 		jz	short locret_5A3 ; Jump	if Zero	(ZF=1)
//@ 		jmp	loc_4C9		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 267
//@ 
//@ locret_5A3:				; CODE XREF: CorrectProcesses+E0j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CorrectProcesses endp
//@ 
//@ ; #line	"CSIPX.PAS" 270
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DoneProcesses	proc near		; CODE XREF: JoinNetworkGame+58p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 271
//@ 		mov	t1, 20h	; ' '   ; uint16_t
//@ ; #line	"CSIPX.PAS" 272
//@ 		call	CorrectProcesses ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 273
//@ 		call	AnimateProcesses ; function far	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 274
//@ 		call	AnimateProcesses ; function far	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 275
//@ 		call	AnimateProcesses ; function far	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 276
//@ 		call	AnimateProcesses ; function far	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 277
//@ 		call	AnimateProcesses ; function far	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 278
//@ 		call	AnimateProcesses ; function far	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 279
//@ 		mov	t1, 4		; uint16_t
//@ ; #line	"CSIPX.PAS" 280
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ DoneProcesses	endp
//@ 
//@ ; #line	"CSIPX.PAS" 286
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns unsigned	char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ GetFreeNetNumber proc near		; CODE XREF: LoadClientPatch+1Fp
//@ 
//@ n		= word ptr -4		; int16_t
//@ GetFreeNetNumber= byte ptr -1		; uint8_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 287
//@ 		mov	[bp+GetFreeNetNumber], 7 ; uint8_t
//@ ; #line	"CSIPX.PAS" 288
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_5E9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5E6:				; CODE XREF: GetFreeNetNumber+29j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSIPX.PAS" 289
//@ 
//@ loc_5E9:				; CODE XREF: GetFreeNetNumber+Dj
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_5FC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 290
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		mov	[bp+GetFreeNetNumber], al ; uint8_t
//@ 		jmp	short loc_602	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_5FC:				; CODE XREF: GetFreeNetNumber+1Bj
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_5E6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 291
//@ 
//@ loc_602:				; CODE XREF: GetFreeNetNumber+23j
//@ 		mov	al, [bp+GetFreeNetNumber] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ GetFreeNetNumber endp
//@ 
//@ ; #line	"CSIPX.PAS" 298
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ConnectIPXProcessor proc near		; CODE XREF: CheckNP+23p
//@ 
//@ S		= word ptr -2		; uint16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 300
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr DRegs.xBX, ax ; struct	TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, ax ; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 301
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 303
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		call	AllocSelector	; Call Procedure
//@ 		mov	[bp+S],	ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 304
//@ 		push	[bp+S]		; uint16_t
//@ 		mov	ax, DRegs.rES	; struct TDPMIRegs
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		push	dx
//@ 		push	ax
//@ 		call	SetSelectorBase	; Call Procedure
//@ ; #line	"CSIPX.PAS" 305
//@ 		push	[bp+S]		; uint16_t
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSIPX.PAS" 306
//@ 		mov	ax, word ptr DRegs.rSI ; struct	TDPMIRegs
//@ 		mov	dx, [bp+S]	; uint16_t
//@ 		mov	word ptr PServerPatch, ax ; TServer_Patch*
//@ 		mov	word ptr PServerPatch+2, dx ; TServer_Patch*
//@ ; #line	"CSIPX.PAS" 307
//@ 		mov	ax, word ptr DRegs.rDI ; struct	TDPMIRegs
//@ 		mov	dx, [bp+S]	; uint16_t
//@ 		mov	word ptr PClientPatches, ax ; TClient_Patch*
//@ 		mov	word ptr PClientPatches+2, dx ;	TClient_Patch*
//@ ; #line	"CSIPX.PAS" 308
//@ 		mov	ax, word ptr DRegs.xBX ; struct	TDPMIRegs
//@ 		mov	dx, [bp+S]	; uint16_t
//@ 		mov	word ptr PInfoStruct, ax ; TInfo_Struct*
//@ 		mov	word ptr PInfoStruct+2,	dx ; TInfo_Struct*
//@ ; #line	"CSIPX.PAS" 310
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es
//@ 		mov	DsSeg, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 311
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, di
//@ 		mov	DsOfs, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 312
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	al, es:[di+14Bh]
//@ 		mov	IPXPresent, al	; bool
//@ ; #line	"CSIPX.PAS" 314
//@ 		mov	di, offset PServerLocal	; TServer_Patch*
//@ 		push	ds
//@ 		push	di
//@ 		push	0BF0h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 315
//@ 		les	di, PServerLocal ; TServer_Patch*
//@ 		mov	ax, es
//@ 		mov	DLSeg, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 322
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ConnectIPXProcessor endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aNpNotFound_	db 13,'NP not found.'   ; DATA XREF: CheckNP+2Do
//@ ; #line	"CSIPX.PAS" 326
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CheckNP		proc near		; CODE XREF: PROGRAM+1B5p
//@ 
//@ L		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 327
//@ 		push	60h ; '`'
//@ 		lea	di, [bp+L]	; int32_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetRealModeIntVector ; function	near PASCAL returns void
//@ ; #line	"CSIPX.PAS" 328
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		or	ax, [bp+var_2]	; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jz	short loc_6CF	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_6CF:				; CODE XREF: CheckNP+16j
//@ 		mov	NPinst,	al	; bool
//@ ; #line	"CSIPX.PAS" 329
//@ 		cmp	NPinst,	0	; bool
//@ 		jz	short loc_6DE	; Jump if Zero (ZF=1)
//@ 		call	ConnectIPXProcessor ; function near PASCAL returns void
//@ 		jmp	short locret_6F4 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 330
//@ 
//@ loc_6DE:				; CODE XREF: CheckNP+21j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aNpNotFound_	; "NP not found."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSIPX.PAS" 331
//@ 
//@ locret_6F4:				; CODE XREF: CheckNP+26j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CheckNP		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aServerStarted_	db 15,'SERVER STARTED.' ; DATA XREF: INIT_IPX_SERVER+88o
//@ ; #line	"CSIPX.PAS" 335
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ INIT_IPX_SERVER	proc near		; CODE XREF: DoGame+144p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 336
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Players.PName ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 337
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	word ptr es:[di+6], 1
//@ ; #line	"CSIPX.PAS" 338
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	es:[di+14Ch], ax
//@ ; #line	"CSIPX.PAS" 339
//@ 		mov	al, NGPort	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	es:[di+150h], ax
//@ ; #line	"CSIPX.PAS" 340
//@ 		mov	al, NGBaud	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	es:[di+14Eh], ax
//@ ; #line	"CSIPX.PAS" 341
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSIPX.PAS" 343
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_763	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_75F:				; CODE XREF: INIT_IPX_SERVER+72j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_763:				; CODE XREF: INIT_IPX_SERVER+57j
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di], 0
//@ 		cmp	n$0, 8		; int16_t
//@ 		jnz	short loc_75F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 345
//@ 		mov	word ptr DRegs.xBX, 7 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 346
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 347
//@ 		mov	di, offset aServerStarted_ ; "SERVER STARTED."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 348
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ INIT_IPX_SERVER	endp
//@ 
//@ ; #line	"CSIPX.PAS" 353
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ INIT_IPX_CLIENT	proc near		; CODE XREF: LookForServer+4p
//@ 					; DoGame+14Ep
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 354
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	word ptr es:[di+6], 2
//@ ; #line	"CSIPX.PAS" 355
//@ 		mov	al, NGCard	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	es:[di+14Ch], ax
//@ ; #line	"CSIPX.PAS" 356
//@ 		mov	al, NGPort	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	es:[di+150h], ax
//@ ; #line	"CSIPX.PAS" 357
//@ 		mov	al, NGBaud	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	es:[di+14Eh], ax
//@ ; #line	"CSIPX.PAS" 358
//@ 		mov	word ptr DRegs.xBX, 7 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 359
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 360
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ INIT_IPX_CLIENT	endp
//@ 
//@ ; #line	"CSIPX.PAS" 364
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CloseIPXChannel	proc near		; CODE XREF: LookForServer+D4p
//@ 					; DoGame+19C0p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 365
//@ 		cmp	NPinst,	0	; bool
//@ 		jnz	short loc_7F4	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_812 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 366
//@ 
//@ loc_7F4:				; CODE XREF: CloseIPXChannel+8j
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSIPX.PAS" 367
//@ 		mov	word ptr DRegs.xBX, 8 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 368
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 369
//@ 
//@ locret_812:				; CODE XREF: CloseIPXChannel+Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CloseIPXChannel	endp
//@ 
//@ ; #line	"CSIPX.PAS" 372
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CheckSendComplette proc	near		; CODE XREF: SendServerPatch+32p
//@ 					; SendClientPatch+32p ...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSIPX.PAS" 373
//@ 		mov	word ptr DRegs.xBX, 5 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 374
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 375
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CheckSendComplette endp
//@ 
//@ ; #line	"CSIPX.PAS" 380
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SendServerPatch	proc near		; CODE XREF: DoGame+39Bp
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= word ptr -0Ah
//@ var_8		= dword	ptr -8
//@ n		= word ptr -2		; uint16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 381
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		cmp	dx, word ptr NextSendTime+2 ; int32_t
//@ 		jl	short loc_846	; Jump if Less (SF!=OF)
//@ 		jg	short loc_849	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, word ptr NextSendTime ; int32_t
//@ 		jnb	short loc_849	; Jump if Not Below (CF=0)
//@ 
//@ loc_846:				; CODE XREF: SendServerPatch+Fj
//@ 		jmp	locret_B86	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 382
//@ 
//@ loc_849:				; CODE XREF: SendServerPatch+11j
//@ 					; SendServerPatch+17j
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		add	ax, word ptr NetPeriod ; int32_t
//@ 		adc	dx, word ptr NetPeriod+2 ; int32_t
//@ 		mov	word ptr NextSendTime, ax ; int32_t
//@ 		mov	word ptr NextSendTime+2, dx ; int32_t
//@ ; #line	"CSIPX.PAS" 384
//@ 		call	CheckSendComplette ; function near PASCAL returns void
//@ ; #line	"CSIPX.PAS" 385
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	byte ptr es:[di+14Ah], 0 ; Compare Two Operands
//@ 		jnz	short loc_871	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_B86	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 387
//@ 
//@ loc_871:				; CODE XREF: SendServerPatch+3Fj
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSIPX.PAS" 389
//@ 		mov	ax, LevelN	; int16_t
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSIPX.PAS" 390
//@ 		mov	byte ptr es:[di+16h], 0
//@ 		mov	al, byte ptr Skill ; int16_t
//@ 		mov	es:[di+17h], al
//@ ; #line	"CSIPX.PAS" 391
//@ 		mov	ax, ServerVersion ; uint16_t
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSIPX.PAS" 392
//@ 		cmp	Paused,	0	; bool
//@ 		jz	short loc_8A1	; Jump if Zero (ZF=1)
//@ 		mov	byte ptr es:[di+16h], 1
//@ ; #line	"CSIPX.PAS" 393
//@ 
//@ loc_8A1:				; CODE XREF: SendServerPatch+6Dj
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ 		mov	es:[di+0Ch], dx
//@ ; #line	"CSIPX.PAS" 394
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	es:[di+18h], ax
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	es:[di+1Ah], ax
//@ 		mov	ax, MnCount	; uint16_t
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"CSIPX.PAS" 395
//@ 		mov	al, byte ptr NetMessage	; char[33] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSIPX.PAS" 396
//@ 		mov	di, offset LevelChanges	; uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, 20h	; ' '   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	10h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 397
//@ 		mov	di, offset ProcState ; uint16_t[4]
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, 30h	; '0'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	8
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 398
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSIPX.PAS" 399
//@ 		mov	word ptr es:[di+6], 38h	; '8'
//@ ; #line	"CSIPX.PAS" 400
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_914	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_911:				; CODE XREF: SendServerPatch+129j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSIPX.PAS" 401
//@ 
//@ loc_914:				; CODE XREF: SendServerPatch+E2j
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_952	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 403
//@ 		mov	ax, 1
//@ 		mov	cx, [bp+n]	; uint16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"CSIPX.PAS" 404
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	38h ; '8'
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 405
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+6], 38h	; '8' ; Add
//@ ; #line	"CSIPX.PAS" 406
//@ 
//@ loc_952:				; CODE XREF: SendServerPatch+F0j
//@ 		cmp	[bp+n],	7	; uint16_t
//@ 		jnz	short loc_911	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 409
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, DsOfs	; uint16_t
//@ 		mov	DpOfs, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 411
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSIPX.PAS" 412
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_976	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_973:				; CODE XREF: SendServerPatch+189j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSIPX.PAS" 413
//@ 
//@ loc_976:				; CODE XREF: SendServerPatch+144j
//@ 		imul	di, [bp+n], 0Ah	; uint16_t
//@ 		cmp	byte ptr [di-5B62h], 0 ; Compare Two Operands
//@ 		jz	short loc_9B2	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 415
//@ 		imul	di, [bp+n], 0Ah	; uint16_t
//@ 		add	di, 0A49Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DpOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	0Ah
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 416
//@ 		add	DpOfs, 0Ah	; uint16_t
//@ ; #line	"CSIPX.PAS" 417
//@ 		imul	di, [bp+n], 0Ah	; uint16_t
//@ 		mov	byte ptr [di-5B62h], 0
//@ ; #line	"CSIPX.PAS" 418
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+1Ch] ; Increment by 1
//@ ; #line	"CSIPX.PAS" 419
//@ 
//@ loc_9B2:				; CODE XREF: SendServerPatch+152j
//@ 		cmp	[bp+n],	0Fh	; uint16_t
//@ 		jnz	short loc_973	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 422
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0	; Compare Two Operands
//@ 		jle	short loc_9EE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSIPX.PAS" 424
//@ 		mov	di, (offset NetMessage+1) ; char[33] //	Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DpOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 425
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		add	DpOfs, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 426
//@ 		mov	byte ptr NetMessage, 0 ; char[33] // Pascal string
//@ ; #line	"CSIPX.PAS" 430
//@ 
//@ loc_9EE:				; CODE XREF: SendServerPatch+193j
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	[bp+var_A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jbe	short loc_9FF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_AC4		; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_9FF:				; CODE XREF: SendServerPatch+1CDj
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_A07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_A04:				; CODE XREF: SendServerPatch+294j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_A07:				; CODE XREF: SendServerPatch+1D5j
//@ 		imul	di, [bp+n], 18h	; uint16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"CSIPX.PAS" 432
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		assume es:nothing
//@ 		mov	es:[di], dx
//@ ; #line	"CSIPX.PAS" 433
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+6]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"CSIPX.PAS" 434
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+8]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"CSIPX.PAS" 435
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+0Ah]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"CSIPX.PAS" 437
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	dl, es:[di+0Ch]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSIPX.PAS" 438
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	dl, es:[di+0Dh]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 9		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSIPX.PAS" 439
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+12h]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 0Ah		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"CSIPX.PAS" 440
//@ 		add	DpOfs, 0Ch	; uint16_t
//@ ; #line	"CSIPX.PAS" 441
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jz	short loc_AC4	; Jump if Zero (ZF=1)
//@ 		jmp	loc_A04		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 445
//@ 
//@ loc_AC4:				; CODE XREF: SendServerPatch+1CFj
//@ 					; SendServerPatch+292j
//@ 		mov	ax, MnCount	; uint16_t
//@ 		mov	[bp+var_A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		ja	short loc_B03	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_ADA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_AD7:				; CODE XREF: SendServerPatch+2D4j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSIPX.PAS" 447
//@ 
//@ loc_ADA:				; CODE XREF: SendServerPatch+2A8j
//@ 		imul	di, [bp+n], 0Ah	; uint16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DpOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	6
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 448
//@ 		add	DpOfs, 6	; uint16_t
//@ ; #line	"CSIPX.PAS" 449
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jnz	short loc_AD7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 454
//@ 
//@ loc_B03:				; CODE XREF: SendServerPatch+2A3j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		ja	short loc_B65	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_B19	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_B16:				; CODE XREF: SendServerPatch+336j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSIPX.PAS" 456
//@ 
//@ loc_B19:				; CODE XREF: SendServerPatch+2E7j
//@ 		imul	di, [bp+n], 28h	; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DpOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	0Ch
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 457
//@ 		imul	di, [bp+n], 28h	; uint16_t
//@ 		cmp	byte ptr [di-5AD8h], 64h ; 'd' ; Compare Two Operands
//@ 		jnz	short loc_B58	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 458
//@ 		imul	di, [bp+n], 28h	; uint16_t
//@ 		mov	dl, [di-5ACEh]
//@ 		mov	ax, DsSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 0Ah		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSIPX.PAS" 459
//@ 
//@ loc_B58:				; CODE XREF: SendServerPatch+311j
//@ 		add	DpOfs, 0Ch	; uint16_t
//@ ; #line	"CSIPX.PAS" 460
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jnz	short loc_B16	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 461
//@ 
//@ loc_B65:				; CODE XREF: SendServerPatch+2E2j
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		sub	ax, DsOfs	; uint16_t
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"CSIPX.PAS" 465
//@ 		mov	word ptr DRegs.xBX, 1 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 466
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 467
//@ 
//@ locret_B86:				; CODE XREF: SendServerPatch:loc_846j
//@ 					; SendServerPatch+41j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ SendServerPatch	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_B88		db 1,'"'                ; DATA XREF: LoadClientPatch+D2o
//@ 					; LoadClientPatch+1F9o	...
//@ aJoinedTheGame	db 17,'" JOINED THE GAME' ; DATA XREF: LoadClientPatch+EBo
//@ aNowIs		db 10,'" NOW IS "'      ; DATA XREF: LoadClientPatch+213o
//@ aDisconnected	db 14,'" DISCONNECTED'  ; DATA XREF: LoadClientPatch+306o
//@ ; #line	"CSIPX.PAS" 472
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadClientPatch	proc near		; CODE XREF: DoGame+387p
//@ 
//@ var_106		= byte ptr -106h
//@ var_6		= dword	ptr -6
//@ 
//@ 		enter	106h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 474
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		add	di, 100h	; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSIPX.PAS" 475
//@ 		cmp	byte ptr es:[di], 1 ; Compare Two Operands
//@ 		jz	short loc_BD1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_CBC		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 477
//@ 
//@ loc_BD1:				; CODE XREF: LoadClientPatch+16j
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"CSIPX.PAS" 478
//@ 		call	GetFreeNetNumber ; function near PASCAL	returns	unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+3], ax
//@ ; #line	"CSIPX.PAS" 479
//@ 		push	word ptr es:[di+3]
//@ 		call	ReinitPlayer	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 480
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+3], 58h ; Signed Multiply
//@ 		mov	byte ptr [di-0FB0h], 0
//@ ; #line	"CSIPX.PAS" 482
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		add	di, 100h	; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	20h ; ' '
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 485
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+3]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di], 1
//@ ; #line	"CSIPX.PAS" 486
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+3], 58h ; Signed Multiply
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 487
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		imul	di, es:[di+3], 58h ; Signed Multiply
//@ 		mov	[di-0FA0h], ax
//@ ; #line	"CSIPX.PAS" 488
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+3], 58h ; Signed Multiply
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di-0FB4h], ax
//@ ; #line	"CSIPX.PAS" 489
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+3], 58h ; Signed Multiply
//@ 		mov	byte ptr [di-0FB2h], 2
//@ ; #line	"CSIPX.PAS" 490
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		imul	di, es:[di+3], 58h ; Signed Multiply
//@ 		mov	byte ptr [di-0FD6h], 1
//@ ; #line	"CSIPX.PAS" 492
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_B88 ; "\""
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		add	di, 105h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aJoinedTheGame ; "\"	JOINED THE GAME"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 493
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_CBC	; Jump if Zero (ZF=1)
//@ 		call	ClearUnusedScreens ; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 499
//@ 
//@ loc_CBC:				; CODE XREF: LoadClientPatch+18j
//@ 					; LoadClientPatch+FFj
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_CC8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CC4:				; CODE XREF: LoadClientPatch+297j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSIPX.PAS" 500
//@ 
//@ loc_CC8:				; CODE XREF: LoadClientPatch+10Cj
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSIPX.PAS" 501
//@ 		cmp	byte ptr es:[di], 1 ; Compare Two Operands
//@ 		jz	short loc_CE3	; Jump if Zero (ZF=1)
//@ 		jmp	loc_E46		; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_CE3:				; CODE XREF: LoadClientPatch+128j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jnz	short loc_CF2	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_E46		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 503
//@ 
//@ loc_CF2:				; CODE XREF: LoadClientPatch+137j
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"CSIPX.PAS" 504
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"CSIPX.PAS" 505
//@ 		mov	ax, es:[di+10h]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	[di-0FB6h], ax
//@ ; #line	"CSIPX.PAS" 506
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		and	ax, 8000h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_D22	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 507
//@ 		mov	ax, es:[di+12h]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	[di-0FB8h], ax
//@ ; #line	"CSIPX.PAS" 508
//@ 
//@ loc_D22:				; CODE XREF: LoadClientPatch+15Dj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+1Ah], 1	; Compare Two Operands
//@ 		jge	short loc_D32	; Jump if Greater or Equal (SF=OF)
//@ 		mov	word ptr es:[di+1Ah], 1
//@ ; #line	"CSIPX.PAS" 509
//@ 
//@ loc_D32:				; CODE XREF: LoadClientPatch+174j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	[di-0F8Eh], ax
//@ ; #line	"CSIPX.PAS" 510
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+16h]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	[di-0FC6h], ax
//@ ; #line	"CSIPX.PAS" 511
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+18h]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	[di-0FC0h], ax
//@ ; #line	"CSIPX.PAS" 512
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ch]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	[di-0F96h], ax	; Add
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSIPX.PAS" 513
//@ 		mov	ax, es:[di+1Eh]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	[di-0F94h], ax	; Add
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"CSIPX.PAS" 516
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_DF0	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 517
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_B88 ; "\""
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aNowIs ; "\"	NOW IS \""
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_B88 ; "\""
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 519
//@ 
//@ loc_DF0:				; CODE XREF: LoadClientPatch+1F1j
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 520
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+14h]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	[di-0FA0h], ax
//@ ; #line	"CSIPX.PAS" 521
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1]
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	[di-0FAAh], ax
//@ ; #line	"CSIPX.PAS" 522
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	es:[di+54h], ax
//@ 		mov	es:[di+56h], dx
//@ ; #line	"CSIPX.PAS" 523
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"CSIPX.PAS" 524
//@ 
//@ loc_E46:				; CODE XREF: LoadClientPatch+12Aj
//@ 					; LoadClientPatch+139j
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short loc_E50	; Jump if Zero (ZF=1)
//@ 		jmp	loc_CC4		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 527
//@ 
//@ loc_E50:				; CODE XREF: LoadClientPatch+295j
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_E5C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_E58:				; CODE XREF: LoadClientPatch+332j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSIPX.PAS" 528
//@ 
//@ loc_E5C:				; CODE XREF: LoadClientPatch+2A0j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_EE1	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 529
//@ 		mov	ax, es:[di+54h]
//@ 		mov	dx, es:[di+56h]
//@ 		add	ax, 118h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		cmp	dx, word ptr Time+2 ; int32_t
//@ 		jl	short loc_E8F	; Jump if Less (SF!=OF)
//@ 		jg	short loc_EE1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, word ptr Time ; int32_t
//@ 		jnb	short loc_EE1	; Jump if Not Below (CF=0)
//@ ; #line	"CSIPX.PAS" 531
//@ 
//@ loc_E8F:				; CODE XREF: LoadClientPatch+2CFj
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	byte ptr es:[di], 0
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+28h], ax
//@ ; #line	"CSIPX.PAS" 532
//@ 		lea	di, [bp+var_106] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_B88 ; "\""
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aDisconnected ; "\" DISCONNECTED"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage3	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 533
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		mov	byte ptr [di-0FB0h], 0
//@ ; #line	"CSIPX.PAS" 534
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_EE1	; Jump if Zero (ZF=1)
//@ 		call	ClearUnusedScreens ; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 535
//@ 
//@ loc_EE1:				; CODE XREF: LoadClientPatch+2BBj
//@ 					; LoadClientPatch+2D1j	...
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short loc_EEB	; Jump if Zero (ZF=1)
//@ 		jmp	loc_E58		; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 537
//@ 
//@ loc_EEB:				; CODE XREF: LoadClientPatch+330j
//@ 		mov	word ptr DRegs.xBX, 4 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 538
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadClientPatch	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aServerBrokeThe	db 22,'SERVER BROKE THE GAME.' ; DATA XREF: LoadServerPatch+14Eo
//@ aServerChangedL	db 21,'SERVER CHANGED LEVEL.' ; DATA XREF: LoadServerPatch+18Eo
//@ aServerDisconne	db 20,'SERVER DISCONNECTED.' ; DATA XREF: LoadServerPatch+7FDo
//@ aServerLost_	db 12,'SERVER LOST.'    ; DATA XREF: LoadServerPatch:loc_1782o
//@ ; #line	"CSIPX.PAS" 552
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadServerPatch	proc near		; CODE XREF: DoGame+1A1p DoGame+3A5p
//@ 
//@ var_118		= dword	ptr -118h
//@ var_114		= dword	ptr -114h
//@ var_110		= word ptr -110h
//@ var_10E		= dword	ptr -10Eh
//@ l		= word ptr -0Ah		; uint16_t
//@ n		= word ptr -8		; uint16_t
//@ CurOfs		= word ptr -6		; uint16_t
//@ dt		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ 
//@ 		enter	118h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 553
//@ 		cmp	KALI, 0		; bool
//@ 		jz	short loc_F70	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 554
//@ 		mov	ax, takt	; uint16_t
//@ 		and	ax, 1Fh		; Logical AND
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_F70	; Jump if Not Zero (ZF=0)
//@ 		sub	word ptr RealTime, 1 ; int32_t
//@ 		sbb	word ptr RealTime+2, 0 ; int32_t
//@ ; #line	"CSIPX.PAS" 555
//@ 
//@ loc_F70:				; CODE XREF: LoadServerPatch+9j
//@ 					; LoadServerPatch+14j
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"CSIPX.PAS" 556
//@ 		push	DsSeg		; uint16_t
//@ 		push	DsOfs		; uint16_t
//@ 		push	DLSeg		; uint16_t
//@ 		push	0
//@ 		push	5F8h
//@ 		call	movsw		; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 559
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	byte ptr es:[di+16h], 0F0h ; 'ð'
//@ ; #line	"CSIPX.PAS" 560
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"CSIPX.PAS" 562
//@ 		les	di, PServerLocal ; TServer_Patch*
//@ 		mov	word ptr [bp+var_10E], di
//@ 		mov	word ptr [bp+var_10E+2], es
//@ 		cmp	byte ptr es:[di+16h], 0F0h ; 'ð' ; Compare Two Operands
//@ 		jnz	short loc_FA7	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1684	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 564
//@ 
//@ loc_FA7:				; CODE XREF: LoadServerPatch+52j
//@ 		cmp	KALI, 0		; bool
//@ 		jz	short loc_FEF	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 566
//@ 		mov	ax, es:[di+0Eh]
//@ 		mov	dx, es:[di+10h]
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		sbb	dx, es:[di+0Ch]	; Integer Subtraction with Borrow
//@ 		add	ax, 2		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	[bp+dt], ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSIPX.PAS" 567
//@ 		cmp	[bp+var_2], 0	; Compare Two Operands
//@ 		jl	short loc_FD8	; Jump if Less (SF!=OF)
//@ 		jg	short loc_FED	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	[bp+dt], 0	; int32_t
//@ 		jnb	short loc_FED	; Jump if Not Below (CF=0)
//@ ; #line	"CSIPX.PAS" 571
//@ 
//@ loc_FD8:				; CODE XREF: LoadServerPatch+7Ej
//@ 		mov	ax, [bp+dt]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		add	word ptr RealTime, ax ;	int32_t
//@ 		adc	word ptr RealTime+2, dx	; int32_t
//@ ; #line	"CSIPX.PAS" 572
//@ 
//@ loc_FED:				; CODE XREF: LoadServerPatch+80j
//@ 					; LoadServerPatch+86j
//@ 		jmp	short loc_103E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 574
//@ 
//@ loc_FEF:				; CODE XREF: LoadServerPatch+5Cj
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		sub	ax, es:[di+0Eh]	; Integer Subtraction
//@ 		sbb	dx, es:[di+10h]	; Integer Subtraction with Borrow
//@ 		mov	[bp+dt], ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSIPX.PAS" 575
//@ 		mov	ax, takt	; uint16_t
//@ 		and	ax, 0Fh		; Logical AND
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_103E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 576
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"CSIPX.PAS" 577
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	dx, es:[di+0Ch]
//@ 		add	ax, [bp+dt]	; int32_t
//@ 		adc	dx, [bp+var_2]	; Add with Carry
//@ 		mov	word ptr RealTime, ax ;	int32_t
//@ 		mov	word ptr RealTime+2, dx	; int32_t
//@ ; #line	"CSIPX.PAS" 578
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	dx, es:[di+0Ch]
//@ 		mov	es:[di+0Eh], ax
//@ 		mov	es:[di+10h], dx
//@ ; #line	"CSIPX.PAS" 579
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"CSIPX.PAS" 582
//@ 
//@ loc_103E:				; CODE XREF: LoadServerPatch:loc_FEDj
//@ 					; LoadServerPatch+C1j
//@ 		cmp	KALI, 0		; bool
//@ 		jz	short loc_105A	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	dx, es:[di+0Ch]
//@ 		mov	word ptr LastServerTime, ax ; int32_t
//@ 		mov	word ptr LastServerTime+2, dx ;	int32_t
//@ 		jmp	short loc_106E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 583
//@ 
//@ loc_105A:				; CODE XREF: LoadServerPatch+F3j
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		sub	ax, [bp+dt]	; int32_t
//@ 		sbb	dx, [bp+var_2]	; Integer Subtraction with Borrow
//@ 		mov	word ptr LastServerTime, ax ; int32_t
//@ 		mov	word ptr LastServerTime+2, dx ;	int32_t
//@ ; #line	"CSIPX.PAS" 587
//@ 
//@ loc_106E:				; CODE XREF: LoadServerPatch+108j
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		cmp	byte ptr es:[di+16h], 1	; Compare Two Operands
//@ 		mov	al, 0
//@ 		jnz	short loc_107C	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_107C:				; CODE XREF: LoadServerPatch+129j
//@ 		mov	Paused,	al	; bool
//@ ; #line	"CSIPX.PAS" 588
//@ 		mov	al, es:[di+17h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 590
//@ 		cmp	byte ptr es:[di+16h], 20h ; ' ' ; Compare Two Operands
//@ 		jnz	short loc_10C4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 592
//@ 		push	3E8h
//@ 		push	0Ah
//@ 		call	Beep		; function far PASCAL returns void
//@ 		call	@NoSound$qv	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 593
//@ 		mov	di, offset aServerBrokeThe ; "SERVER BROKE THE GAME."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 594
//@ 		mov	CLIENT,	0	; bool
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyNetN,	ax	; int16_t
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"CSIPX.PAS" 595
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+16h], 0F0h ; 'ð'
//@ ; #line	"CSIPX.PAS" 596
//@ 		jmp	locret_1797	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 599
//@ 
//@ loc_10C4:				; CODE XREF: LoadServerPatch+13Dj
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		cmp	byte ptr es:[di+16h], 10h ; Compare Two	Operands
//@ 		jnz	short loc_1101	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 601
//@ 		push	3E8h
//@ 		push	0Ah
//@ 		call	Beep		; function far PASCAL returns void
//@ 		call	@NoSound$qv	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 602
//@ 		mov	di, offset aServerChangedL ; "SERVER CHANGED LEVEL."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 603
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"CSIPX.PAS" 604
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"CSIPX.PAS" 605
//@ 		mov	byte ptr es:[di+16h], 0F0h ; 'ð'
//@ ; #line	"CSIPX.PAS" 606
//@ 		jmp	locret_1797	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 611
//@ 
//@ loc_1101:				; CODE XREF: LoadServerPatch+17Dj
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+16h], 0F0h ; 'ð'
//@ ; #line	"CSIPX.PAS" 612
//@ 		mov	[bp+CurOfs], 38h ; '8' ; uint16_t
//@ ; #line	"CSIPX.PAS" 613
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	word ptr iMyPlayer, ax ; TMPlayerInfo*
//@ 		mov	word ptr iMyPlayer+2, ax ; TMPlayerInfo*
//@ ; #line	"CSIPX.PAS" 614
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_1121	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_111E:				; CODE XREF: LoadServerPatch+4AEj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSIPX.PAS" 615
//@ 
//@ loc_1121:				; CODE XREF: LoadServerPatch+1CCj
//@ 		mov	ax, 1
//@ 		mov	cx, [bp+n]	; uint16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		and	ax, es:[di+8]	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_1141	; Jump if Not Zero (ZF=0)
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	byte ptr [di-0FD6h], 0
//@ 		jmp	loc_13F8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 618
//@ 
//@ loc_1141:				; CODE XREF: LoadServerPatch+1E3j
//@ 		mov	ax, [bp+CurOfs]	; uint16_t
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, di
//@ 		mov	dx, es
//@ 		mov	word ptr iPlayer, ax ; TMPlayerInfo*
//@ 		mov	word ptr iPlayer+2, dx ; TMPlayerInfo*
//@ ; #line	"CSIPX.PAS" 619
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_114+2], di
//@ 		mov	[bp+var_110], es
//@ ; #line	"CSIPX.PAS" 621
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_118F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jnz	short loc_118F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 622
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_114+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	0E8h ; 'è'
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 624
//@ 
//@ loc_118F:				; CODE XREF: LoadServerPatch+21Cj
//@ 					; LoadServerPatch+227j
//@ 		mov	ax, MyNetN	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jz	short loc_11A3	; Jump if Zero (ZF=1)
//@ 		jmp	loc_13DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_11A3:				; CODE XREF: LoadServerPatch+24Ej
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_11AA	; Jump if Zero (ZF=1)
//@ 		jmp	loc_13DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 626
//@ 
//@ loc_11AA:				; CODE XREF: LoadServerPatch+255j
//@ 		mov	ax, word ptr iPlayer ; TMPlayerInfo*
//@ 		mov	dx, word ptr iPlayer+2 ; TMPlayerInfo*
//@ 		mov	word ptr iMyPlayer, ax ; TMPlayerInfo*
//@ 		mov	word ptr iMyPlayer+2, dx ; TMPlayerInfo*
//@ ; #line	"CSIPX.PAS" 628
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jnz	short loc_121F	; Jump if Not Zero (ZF=0)
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_121F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSIPX.PAS" 630
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	ax, es:[di+1Eh]
//@ 		mov	HFi, ax		; uint16_t
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 631
//@ 		mov	LastGunNumber, 1 ; uint16_t
//@ ; #line	"CSIPX.PAS" 632
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	LookVz,	ax	; int16_t
//@ ; #line	"CSIPX.PAS" 633
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	word ptr [di-0F8Eh], 1
//@ ; #line	"CSIPX.PAS" 634
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponPhase, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 635
//@ 		mov	GunShift, 2Eh ;	'.' ; uint16_t
//@ ; #line	"CSIPX.PAS" 636
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 637
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 638
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	al, es:[di+2Eh]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	[di-0FA8h], al
//@ ; #line	"CSIPX.PAS" 641
//@ 
//@ loc_121F:				; CODE XREF: LoadServerPatch+271j
//@ 					; LoadServerPatch+27Cj
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	al, es:[di+2Eh]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		cmp	al, [di-0FA8h]	; Compare Two Operands
//@ 		jz	short loc_1244	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 642
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	al, es:[di+2Eh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		inc	ax		; Increment by 1
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	[di-0FA8h], al
//@ ; #line	"CSIPX.PAS" 644
//@ 
//@ loc_1244:				; CODE XREF: LoadServerPatch+2DFj
//@ 		cmp	GunShift, 0	; uint16_t
//@ 		jnz	short loc_1282	; Jump if Not Zero (ZF=0)
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_118+2], di
//@ 		mov	word ptr [bp+var_114], es
//@ ; #line	"CSIPX.PAS" 645
//@ 		mov	ax, es:[di+48h]
//@ 		add	di, ax		; Add
//@ 		mov	dl, es:[di+2Dh]
//@ 		les	di, [bp+var_118+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+48h]
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di+2Dh]
//@ 		cmp	al, dl		; Compare Two Operands
//@ 		jnb	short loc_1282	; Jump if Not Below (CF=0)
//@ ; #line	"CSIPX.PAS" 646
//@ 		mov	WeaponActive, 1	; bool
//@ ; #line	"CSIPX.PAS" 651
//@ 
//@ loc_1282:				; CODE XREF: LoadServerPatch+2F9j
//@ 					; LoadServerPatch+32Bj
//@ 		les	di, [bp+var_114+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Ah]
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		cmp	ax, es:[di+1Ah]	; Compare Two Operands
//@ 		jge	short loc_12AD	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		cmp	word ptr es:[di+1Ah], 20h ; ' ' ; Compare Two Operands
//@ 		jle	short loc_12AD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	ax, es:[di+1Ah]
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 654
//@ 
//@ loc_12AD:				; CODE XREF: LoadServerPatch+345j
//@ 					; LoadServerPatch+350j
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	ax, es:[di+28h]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		cmp	ax, [di-0FAEh]	; Compare Two Operands
//@ 		jge	short loc_12CC	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		push	word ptr es:[di+28h]
//@ 		call	SetMePain	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 657
//@ 
//@ loc_12CC:				; CODE XREF: LoadServerPatch+36Dj
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	al, es:[di+25h]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		cmp	al, [di-0FB1h]	; Compare Two Operands
//@ 		jnb	short loc_12EE	; Jump if Not Below (CF=0)
//@ ; #line	"CSIPX.PAS" 658
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	al, es:[di+25h]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	[di-0FB1h], al
//@ ; #line	"CSIPX.PAS" 660
//@ 
//@ loc_12EE:				; CODE XREF: LoadServerPatch+38Cj
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	al, es:[di+25h]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		xor	al, [di-0FB1h]	; Logical Exclusive OR
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSIPX.PAS" 661
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	al, es:[di+25h]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	[di-0FB1h], al
//@ ; #line	"CSIPX.PAS" 662
//@ 		cmp	w, 0		; uint16_t
//@ 		jbe	short loc_1361	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+l],	ax	; uint16_t
//@ 		jmp	short loc_1324	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1321:				; CODE XREF: LoadServerPatch+40Fj
//@ 		inc	[bp+l]		; uint16_t
//@ ; #line	"CSIPX.PAS" 663
//@ 
//@ loc_1324:				; CODE XREF: LoadServerPatch+3CFj
//@ 		mov	ax, 1
//@ 		mov	cx, [bp+l]	; uint16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		and	ax, w		; uint16_t
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_135B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 664
//@ 		mov	ax, [bp+l]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	ax, [di-0F8Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_1351	; Jump if Less (SF!=OF)
//@ 		jg	short loc_135B	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_135B	; Jump if Not Below (CF=0)
//@ 
//@ loc_1351:				; CODE XREF: LoadServerPatch+3F9j
//@ 		mov	ax, [bp+l]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	SetWeapon	; function far PASCAL returns void
//@ 
//@ loc_135B:				; CODE XREF: LoadServerPatch+3E2j
//@ 					; LoadServerPatch+3FBj	...
//@ 		cmp	[bp+l],	7	; uint16_t
//@ 		jnz	short loc_1321	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 668
//@ 
//@ loc_1361:				; CODE XREF: LoadServerPatch+3C8j
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	ax, es:[di+2Ah]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		cmp	ax, [di-0FACh]	; Compare Two Operands
//@ 		jnb	short loc_1383	; Jump if Not Below (CF=0)
//@ ; #line	"CSIPX.PAS" 669
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	ax, es:[di+2Ah]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	[di-0FACh], ax
//@ ; #line	"CSIPX.PAS" 671
//@ 
//@ loc_1383:				; CODE XREF: LoadServerPatch+421j
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	ax, es:[di+2Ah]
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		xor	ax, [di-0FACh]	; Logical Exclusive OR
//@ 		mov	w, ax		; uint16_t
//@ ; #line	"CSIPX.PAS" 678
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		mov	ax, [di-0F8Eh]
//@ 		inc	ax		; Increment by 1
//@ 		cmp	ax, 6		; Compare Two Operands
//@ 		ja	short loc_13DD	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	w, ax		; uint16_t
//@ 		jmp	short loc_13AD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13A9:				; CODE XREF: LoadServerPatch+48Bj
//@ 		inc	w		; uint16_t
//@ ; #line	"CSIPX.PAS" 679
//@ 
//@ loc_13AD:				; CODE XREF: LoadServerPatch+457j
//@ 		mov	ax, w		; uint16_t
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr [di-0FA9h], 0 ; Compare Two Operands
//@ 		jnz	short loc_13D6	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, w		; uint16_t
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di+2Dh], 0	; Compare Two Operands
//@ 		jbe	short loc_13D6	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 680
//@ 		push	w		; uint16_t
//@ 		call	SetWeapon	; function far PASCAL returns void
//@ 
//@ loc_13D6:				; CODE XREF: LoadServerPatch+46Bj
//@ 					; LoadServerPatch+47Bj
//@ 		cmp	w, 6		; uint16_t
//@ 		jnz	short loc_13A9	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 683
//@ 
//@ loc_13DD:				; CODE XREF: LoadServerPatch+250j
//@ 					; LoadServerPatch+257j	...
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		push	es
//@ 		push	di
//@ 		imul	di, [bp+n], 58h	; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	38h ; '8'
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 684
//@ 		add	[bp+CurOfs], 38h ; '8' ; uint16_t
//@ ; #line	"CSIPX.PAS" 686
//@ 
//@ loc_13F8:				; CODE XREF: LoadServerPatch+1EEj
//@ 		cmp	[bp+n],	7	; uint16_t
//@ 		jz	short loc_1401	; Jump if Zero (ZF=1)
//@ 		jmp	loc_111E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 688
//@ 
//@ loc_1401:				; CODE XREF: LoadServerPatch+4ACj
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	word ptr Players.LastTime, ax ;	struct TPlayerInfo[8]
//@ 		mov	word ptr Players.LastTime+2, dx	; struct TPlayerInfo[8]
//@ ; #line	"CSIPX.PAS" 689
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 691
//@ 		call	MakeChanges	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 692
//@ 		call	CorrectProcesses ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 693
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 20h	; ' '   ; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset LevelChanges	; uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		push	10h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 695
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+18h]
//@ 		mov	RCount,	ax	; uint16_t
//@ 		mov	ax, es:[di+1Ah]
//@ 		mov	MCount,	ax	; uint16_t
//@ 		mov	ax, es:[di+1Eh]
//@ 		mov	MnCount, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 697
//@ 		mov	ax, es:[di+6]
//@ 		mov	DpOfs, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 700
//@ 		mov	ax, es:[di+14h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		imul	ax, es:[di+1Ch], 0Ah ; Signed Multiply
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		add	DpOfs, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 703
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	[bp+var_110], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_110] ; Compare Two Operands
//@ 		jbe	short loc_148D	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_155F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_148D:				; CODE XREF: LoadServerPatch+538j
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_1495	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1492:				; CODE XREF: LoadServerPatch+60Cj
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_1495:				; CODE XREF: LoadServerPatch+540j
//@ 		imul	di, [bp+n], 18h	; uint16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_114], di
//@ 		mov	word ptr [bp+var_114+2], es
//@ ; #line	"CSIPX.PAS" 705
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSIPX.PAS" 706
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSIPX.PAS" 707
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSIPX.PAS" 708
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSIPX.PAS" 710
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+0Ch], al
//@ ; #line	"CSIPX.PAS" 711
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 9		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+0Dh], al
//@ ; #line	"CSIPX.PAS" 712
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DpOfs	; uint16_t
//@ 		add	ax, 0Ah		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSIPX.PAS" 713
//@ 		add	DpOfs, 0Ch	; uint16_t
//@ ; #line	"CSIPX.PAS" 714
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_110] ; Compare Two Operands
//@ 		jz	short loc_155F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1492	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 718
//@ 
//@ loc_155F:				; CODE XREF: LoadServerPatch+53Aj
//@ 					; LoadServerPatch+60Aj
//@ 		mov	ax, MnCount	; uint16_t
//@ 		mov	[bp+var_110], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_110] ; Compare Two Operands
//@ 		jbe	short loc_1572	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_15F2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1572:				; CODE XREF: LoadServerPatch+61Dj
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_157A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1577:				; CODE XREF: LoadServerPatch+6A0j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_157A:				; CODE XREF: LoadServerPatch+625j
//@ 		imul	di, [bp+n], 0Ah	; uint16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSIPX.PAS" 720
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DpOfs	; uint16_t
//@ 		pop	es
//@ 		assume es:nothing
//@ 		push	es
//@ 		push	di
//@ 		imul	di, [bp+n], 0Ah	; uint16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	6
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 721
//@ 		imul	di, [bp+n], 0Ah	; uint16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_118], di
//@ 		mov	word ptr [bp+var_118+2], es
//@ ; #line	"CSIPX.PAS" 722
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
//@ 		les	di, [bp+var_118] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ 		mov	ax, es:[di+6]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSIPX.PAS" 723
//@ 		add	DpOfs, 6	; uint16_t
//@ ; #line	"CSIPX.PAS" 724
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_110] ; Compare Two Operands
//@ 		jnz	short loc_1577	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 728
//@ 
//@ loc_15F2:				; CODE XREF: LoadServerPatch+61Fj
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_110], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_110] ; Compare Two Operands
//@ 		jbe	short loc_1605	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_1684	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1605:				; CODE XREF: LoadServerPatch+6B0j
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_160D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_160A:				; CODE XREF: LoadServerPatch+732j
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSIPX.PAS" 730
//@ 
//@ loc_160D:				; CODE XREF: LoadServerPatch+6B8j
//@ 		mov	ax, DLSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DpOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		imul	di, [bp+n], 28h	; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	0Ch
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 731
//@ 		imul	di, [bp+n], 28h	; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_114], di
//@ 		mov	word ptr [bp+var_114+2], es
//@ ; #line	"CSIPX.PAS" 733
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jnb	short loc_1659	; Jump if Not Below (CF=0)
//@ ; #line	"CSIPX.PAS" 735
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ 		mov	byte ptr es:[di+0Ah], 64h ; 'd'
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSIPX.PAS" 736
//@ 		jmp	short loc_1676	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 737
//@ 
//@ loc_1659:				; CODE XREF: LoadServerPatch+6F0j
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+8], 10h	; Compare Two Operands
//@ 		jl	short loc_166C	; Jump if Less (SF!=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+12h], ax
//@ 		jmp	short loc_1676	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 738
//@ 
//@ loc_166C:				; CODE XREF: LoadServerPatch+712j
//@ 		les	di, [bp+var_114] ; Load	Full Pointer to	ES:xx
//@ 		mov	word ptr es:[di+12h], 1
//@ ; #line	"CSIPX.PAS" 740
//@ 
//@ loc_1676:				; CODE XREF: LoadServerPatch+707j
//@ 					; LoadServerPatch+71Aj
//@ 		add	DpOfs, 0Ch	; uint16_t
//@ ; #line	"CSIPX.PAS" 741
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_110] ; Compare Two Operands
//@ 		jnz	short loc_160A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 745
//@ 
//@ loc_1684:				; CODE XREF: LoadServerPatch+54j
//@ 					; LoadServerPatch+6B2j
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 748
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_1691	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_168E:				; CODE XREF: LoadServerPatch+787j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_1691:				; CODE XREF: LoadServerPatch+73Cj
//@ 		imul	ax, [bp+n], 0Ah	; uint16_t
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		add	di, ax		; Add
//@ 		add	di, 0Ah		; Add
//@ 		mov	word ptr [bp+var_10E], di
//@ 		mov	word ptr [bp+var_10E+2], es
//@ ; #line	"CSIPX.PAS" 749
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_16D3	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 751
//@ 		mov	al, es:[di]
//@ 		push	ax
//@ 		mov	al, es:[di+1]
//@ 		push	ax
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+4]
//@ 		push	word ptr es:[di+6]
//@ 		push	word ptr es:[di+8]
//@ 		call	ExecuteEvent	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 752
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"CSIPX.PAS" 753
//@ 
//@ loc_16D3:				; CODE XREF: LoadServerPatch+75Bj
//@ 		cmp	[bp+n],	1Fh	; uint16_t
//@ 		jnz	short loc_168E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 755
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	word ptr [bp+var_10E], di
//@ 		mov	word ptr [bp+var_10E+2], es
//@ ; #line	"CSIPX.PAS" 756
//@ 		cmp	byte ptr es:[di+156h], 0 ; Compare Two Operands
//@ 		jz	short loc_1702	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 758
//@ 		add	di, 156h	; Add
//@ 		push	es
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 759
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+156h], 0
//@ ; #line	"CSIPX.PAS" 763
//@ 
//@ loc_1702:				; CODE XREF: LoadServerPatch+79Bj
//@ 		mov	c, 0		; uint8_t
//@ ; #line	"CSIPX.PAS" 764
//@ 		mov	ax, word ptr iMyPlayer ; TMPlayerInfo*
//@ 		or	ax, word ptr iMyPlayer+2 ; TMPlayerInfo*
//@ 		jnz	short loc_1717	; Jump if Not Zero (ZF=0)
//@ 		mov	c, 1		; uint8_t
//@ 		jmp	short loc_1746	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 765
//@ 
//@ loc_1717:				; CODE XREF: LoadServerPatch+7BEj
//@ 		les	di, iMyPlayer	; TMPlayerInfo*
//@ 		mov	word ptr [bp+var_10E], di
//@ 		mov	word ptr [bp+var_10E+2], es
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	word ptr [bp+var_114+2], di
//@ 		mov	[bp+var_110], es
//@ ; #line	"CSIPX.PAS" 767
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+2Ch]
//@ 		les	di, [bp+var_114+2] ; Load Full Pointer to ES:xx
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jz	short loc_1746	; Jump if Zero (ZF=1)
//@ 		mov	c, 1		; uint8_t
//@ ; #line	"CSIPX.PAS" 769
//@ 
//@ loc_1746:				; CODE XREF: LoadServerPatch+7C5j
//@ 					; LoadServerPatch+7EFj
//@ 		cmp	c, 1		; uint8_t
//@ 		jnz	short loc_1767	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 770
//@ 		mov	di, offset aServerDisconne ; "SERVER DISCONNECTED."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		mov	CLIENT,	0	; bool
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyNetN,	ax	; int16_t
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"CSIPX.PAS" 774
//@ 
//@ loc_1767:				; CODE XREF: LoadServerPatch+7FBj
//@ 		mov	ax, word ptr Players.LastTime ;	struct TPlayerInfo[8]
//@ 		mov	dx, word ptr Players.LastTime+2	; struct TPlayerInfo[8]
//@ 		add	ax, 17Ch	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		cmp	dx, word ptr Time+2 ; int32_t
//@ 		jl	short loc_1782	; Jump if Less (SF!=OF)
//@ 		jg	short locret_1797 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		cmp	ax, word ptr Time ; int32_t
//@ 		jnb	short locret_1797 ; Jump if Not	Below (CF=0)
//@ ; #line	"CSIPX.PAS" 775
//@ 
//@ loc_1782:				; CODE XREF: LoadServerPatch+828j
//@ 		mov	di, offset aServerLost_	; "SERVER LOST."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		mov	CLIENT,	0	; bool
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"CSIPX.PAS" 776
//@ 
//@ locret_1797:				; CODE XREF: LoadServerPatch+171j
//@ 					; LoadServerPatch+1AEj	...
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadServerPatch	endp
//@ 
//@ ; #line	"CSIPX.PAS" 780
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SendClientPatch	proc near		; CODE XREF: DoGame+391p
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 781
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		cmp	dx, word ptr NextSendTime+2 ; int32_t
//@ 		jl	short loc_17B2	; Jump if Less (SF!=OF)
//@ 		jg	short loc_17B5	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, word ptr NextSendTime ; int32_t
//@ 		jnb	short loc_17B5	; Jump if Not Below (CF=0)
//@ 
//@ loc_17B2:				; CODE XREF: SendClientPatch+Fj
//@ 		jmp	locret_1893	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 782
//@ 
//@ loc_17B5:				; CODE XREF: SendClientPatch+11j
//@ 					; SendClientPatch+17j
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		add	ax, word ptr NetPeriod ; int32_t
//@ 		adc	dx, word ptr NetPeriod+2 ; int32_t
//@ 		mov	word ptr NextSendTime, ax ; int32_t
//@ 		mov	word ptr NextSendTime+2, dx ; int32_t
//@ ; #line	"CSIPX.PAS" 783
//@ 		call	CheckSendComplette ; function near PASCAL returns void
//@ ; #line	"CSIPX.PAS" 784
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	byte ptr es:[di+14Ah], 0 ; Compare Two Operands
//@ 		jnz	short loc_17DD	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1893	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 786
//@ 
//@ loc_17DD:				; CODE XREF: SendClientPatch+3Fj
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSIPX.PAS" 788
//@ 		mov	ax, HksFlags	; uint16_t
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSIPX.PAS" 789
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	ax, es:[di+8]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ ; #line	"CSIPX.PAS" 790
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Ah
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 791
//@ 		mov	al, SelfColor	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSIPX.PAS" 792
//@ 		mov	ax, HFi		; uint16_t
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSIPX.PAS" 793
//@ 		mov	ax, MyNetN	; int16_t
//@ 		mov	es:[di+3], ax
//@ ; #line	"CSIPX.PAS" 794
//@ 		mov	ax, LookVz	; int16_t
//@ 		mov	es:[di+16h], ax
//@ ; #line	"CSIPX.PAS" 795
//@ 		mov	ax, HRv		; int16_t
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CSIPX.PAS" 796
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	ax, [di-0F8Eh]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CSIPX.PAS" 797
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		cmp	word ptr [di-0FAEh], 0 ; Compare Two Operands
//@ 		jnz	short loc_185F	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+10h], 8000h ; Add
//@ ; #line	"CSIPX.PAS" 798
//@ 
//@ loc_185F:				; CODE XREF: SendClientPatch+BBj
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	ax, [di-0F96h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CSIPX.PAS" 799
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	ax, [di-0F94h]
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"CSIPX.PAS" 802
//@ 		mov	word ptr DRegs.xBX, 3 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 803
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 804
//@ 
//@ locret_1893:				; CODE XREF: SendClientPatch:loc_17B2j
//@ 					; SendClientPatch+41j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ SendClientPatch	endp
//@ 
//@ ; #line	"CSIPX.PAS" 813
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ CheckIDsConflict proc near		; CODE XREF: LookForServer+C8p
//@ 
//@ var_A		= dword	ptr -0Ah
//@ CurOfs		= word ptr -6		; int16_t
//@ n		= word ptr -4		; int16_t
//@ CheckIDsConflict= byte ptr -1		; bool
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 814
//@ 		mov	[bp+CheckIDsConflict], 0 ; bool
//@ ; #line	"CSIPX.PAS" 815
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CSIPX.PAS" 817
//@ 		mov	[bp+CurOfs], 38h ; '8' ; int16_t
//@ ; #line	"CSIPX.PAS" 818
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_18B6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_18B3:				; CODE XREF: CheckIDsConflict+78j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSIPX.PAS" 819
//@ 
//@ loc_18B6:				; CODE XREF: CheckIDsConflict+1Cj
//@ 		mov	ax, 1
//@ 		mov	cx, [bp+n]	; int16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		and	ax, cx		; Logical AND
//@ 		and	dx, bx		; Logical AND
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jg	short loc_18DC	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_1909	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jbe	short loc_1909	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 821
//@ 
//@ loc_18DC:				; CODE XREF: CheckIDsConflict+3Ej
//@ 		mov	ax, [bp+CurOfs]	; int16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, di
//@ 		mov	dx, es
//@ 		mov	word ptr iPlayer, ax ; TMPlayerInfo*
//@ 		mov	word ptr iPlayer+2, dx ; TMPlayerInfo*
//@ ; #line	"CSIPX.PAS" 822
//@ 		add	[bp+CurOfs], 38h ; '8' ; int16_t
//@ ; #line	"CSIPX.PAS" 823
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ ; #line	"CSIPX.PAS" 824
//@ 		mov	ax, es:[di+2Ch]
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jnz	short loc_1909	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+CheckIDsConflict], 1 ; bool
//@ ; #line	"CSIPX.PAS" 825
//@ 
//@ loc_1909:				; CODE XREF: CheckIDsConflict+40j
//@ 					; CheckIDsConflict+45j	...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jnz	short loc_18B3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 827
//@ 		mov	al, [bp+CheckIDsConflict] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CheckIDsConflict endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aNoServerFound_	db 16,'NO SERVER FOUND.' ; DATA XREF: LookForServer+4Fo
//@ aIncorrectServe	db 25,'Incorrect SERVER version.' ; DATA XREF: LookForServer+69o
//@ ; #line	"CSIPX.PAS" 832
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LookForServer	proc near		; CODE XREF: MenuJoinNet+32p
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 834
//@ 		call	INIT_IPX_CLIENT	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 835
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ ; #line	"CSIPX.PAS" 837
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 839
//@ 
//@ loc_1955:				; CODE XREF: LookForServer+45j
//@ 		push	64h ; 'd'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 840
//@ 		mov	word ptr DRegs.xBX, 9 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 841
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 842
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jge	short loc_1986	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	CurTime, 8Ch ; 'Œ' ; uint16_t
//@ 		jbe	short loc_1955	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 844
//@ 
//@ loc_1986:				; CODE XREF: LookForServer+3Dj
//@ 		cmp	CurTime, 8Ch ; 'Œ' ; uint16_t
//@ 		jbe	short loc_199A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 845
//@ 		mov	di, offset aNoServerFound_ ; "NO SERVER	FOUND."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	short loc_1A0E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 847
//@ 
//@ loc_199A:				; CODE XREF: LookForServer+4Dj
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es:[di+4]
//@ 		cmp	ax, ServerVersion ; uint16_t
//@ 		jz	short loc_19B4	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 848
//@ 		mov	di, offset aIncorrectServe ; "Incorrect	SERVER version."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	short loc_1A0E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 851
//@ 
//@ loc_19B4:				; CODE XREF: LookForServer+67j
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"CSIPX.PAS" 852
//@ 		mov	CLIENT,	1	; bool
//@ 		mov	SERVER,	0	; bool
//@ ; #line	"CSIPX.PAS" 853
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"CSIPX.PAS" 854
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es:[di+12h]
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"CSIPX.PAS" 855
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	al, es:[di+17h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 856
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Players.PName ; struct TPlayerInfo[8]
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 858
//@ 
//@ loc_19F2:				; CODE XREF: LookForServer+CDj
//@ 		call	@Randomize$qv	; Randomize
//@ ; #line	"CSIPX.PAS" 859
//@ 		push	0FFFEh
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		inc	ax		; Increment by 1
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSIPX.PAS" 860
//@ 		call	CheckIDsConflict ; function near PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_19F2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 862
//@ 
//@ loc_1A0E:				; CODE XREF: LookForServer+59j
//@ 					; LookForServer+73j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 863
//@ 		call	CloseIPXChannel	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 864
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LookForServer	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aNoServerFoun_0	db 16,'NO SERVER FOUND.' ; DATA XREF: ScanNet+52o
//@ ; #line	"CSIPX.PAS" 868
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScanNet		proc near		; CODE XREF: DoGame+15Fp
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 870
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ ; #line	"CSIPX.PAS" 872
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 874
//@ 
//@ loc_1A3C:				; CODE XREF: ScanNet+42j
//@ 		push	64h ; 'd'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 875
//@ 		mov	word ptr DRegs.xBX, 9 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 876
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 877
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jge	short loc_1A6D	; Jump if Greater or Equal (SF=OF)
//@ 		cmp	CurTime, 230h	; uint16_t
//@ 		jbe	short loc_1A3C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 879
//@ 
//@ loc_1A6D:				; CODE XREF: ScanNet+3Aj
//@ 		cmp	CurTime, 230h	; uint16_t
//@ 		jbe	short loc_1A87	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 880
//@ 		mov	MenuCode, 2	; uint16_t
//@ 		mov	di, offset aNoServerFoun_0 ; "NO SERVER	FOUND."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	short locret_1ACC ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 883
//@ 
//@ loc_1A87:				; CODE XREF: ScanNet+4Aj
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	dx, es:[di+0Ch]
//@ 		add	ax, 1		; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	word ptr RealTime, ax ;	int32_t
//@ 		mov	word ptr RealTime+2, dx	; int32_t
//@ ; #line	"CSIPX.PAS" 884
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es:[di+12h]
//@ 		cmp	ax, LevelN	; int16_t
//@ 		jz	short locret_1ACC ; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 886
//@ 		mov	MenuCode, 1	; uint16_t
//@ ; #line	"CSIPX.PAS" 887
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es:[di+12h]
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"CSIPX.PAS" 888
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	al, es:[di+17h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 891
//@ 
//@ locret_1ACC:				; CODE XREF: ScanNet+5Cj ScanNet+83j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ScanNet		endp
//@ 
//@ ; #line	"CSIPX.PAS" 900
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ JoinServer	proc near		; CODE XREF: JoinNetworkGame+5p
//@ 					; JoinNetworkGame+Dp ...
//@ 
//@ var_A		= dword	ptr -0Ah
//@ var_6		= dword	ptr -6
//@ JoinServer	= byte ptr -1		; bool
//@ arg_0		= word ptr  4
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 901
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1ADD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1AD9:				; CODE XREF: JoinServer+24j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_1ADD:				; CODE XREF: JoinServer+9j
//@ 		imul	ax, n$0, 0Ah	; int16_t
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr es:[di+0Ah], 0
//@ 		cmp	n$0, 1Fh	; int16_t
//@ 		jnz	short loc_1AD9	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 902
//@ 		les	di, PClientPatches ; TClient_Patch*
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSIPX.PAS" 904
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+10h], ax
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Ah
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 905
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+3], 0FFFFh
//@ 		mov	word ptr es:[di+1Ah], 1
//@ ; #line	"CSIPX.PAS" 906
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		mov	ax, es:[di+8]
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1], ax
//@ ; #line	"CSIPX.PAS" 908
//@ 		mov	word ptr DRegs.xBX, 3 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 910
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ 		mov	MyNetN,	0FFFFh	; int16_t
//@ ; #line	"CSIPX.PAS" 911
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ ; #line	"CSIPX.PAS" 914
//@ 
//@ loc_1B60:				; CODE XREF: JoinServer+184j
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSIPX.PAS" 915
//@ 		cmp	word ptr es:[di+12h], 0FFFFh ; Compare Two Operands
//@ 		jnz	short loc_1B74	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1C25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 917
//@ 
//@ loc_1B74:				; CODE XREF: JoinServer+A1j
//@ 		mov	al, es:[di+17h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 918
//@ 		mov	di, [bp+arg_0]
//@ 		mov	word ptr ss:[di+var_6+2], 38h ;	'8'
//@ ; #line	"CSIPX.PAS" 919
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1B91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1B8D:				; CODE XREF: JoinServer+14Aj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSIPX.PAS" 920
//@ 
//@ loc_1B91:				; CODE XREF: JoinServer+BDj
//@ 		mov	ax, 1
//@ 		mov	cx, n$0		; int16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		and	ax, cx		; Logical AND
//@ 		and	dx, bx		; Logical AND
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jg	short loc_1BB8	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_1C11	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jbe	short loc_1C11	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 922
//@ 
//@ loc_1BB8:				; CODE XREF: JoinServer+E1j
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ax, word ptr ss:[di+var_6+2]
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, di
//@ 		mov	dx, es
//@ 		mov	word ptr iPlayer, ax ; TMPlayerInfo*
//@ 		mov	word ptr iPlayer+2, dx ; TMPlayerInfo*
//@ ; #line	"CSIPX.PAS" 923
//@ 		mov	di, [bp+arg_0]
//@ 		add	word ptr ss:[di+var_6+2], 38h ;	'8' ; Add
//@ ; #line	"CSIPX.PAS" 924
//@ 		les	di, iPlayer	; TMPlayerInfo*
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CSIPX.PAS" 925
//@ 		mov	ax, es:[di+2Ch]
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	ax, es:[di+8]	; Compare Two Operands
//@ 		jnz	short loc_1C11	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 926
//@ 		mov	ax, n$0		; int16_t
//@ 		mov	MyNetN,	ax	; int16_t
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	dx, es:[di+0Ch]
//@ 		mov	word ptr RealTime, ax ;	int32_t
//@ 		mov	word ptr RealTime+2, dx	; int32_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		mov	HFi, ax		; uint16_t
//@ ; #line	"CSIPX.PAS" 927
//@ 
//@ loc_1C11:				; CODE XREF: JoinServer+E3j
//@ 					; JoinServer+E8j ...
//@ 		cmp	n$0, 7		; int16_t
//@ 		jz	short loc_1C1B	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1B8D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 928
//@ 
//@ loc_1C1B:				; CODE XREF: JoinServer+148j
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ ; #line	"CSIPX.PAS" 931
//@ 
//@ loc_1C25:				; CODE XREF: JoinServer+A3j
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 932
//@ 		push	28h ; '('
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 933
//@ 		mov	word ptr DRegs.xBX, 9 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 934
//@ 		cmp	MyNetN,	0	; int16_t
//@ 		jg	short loc_1C55	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	CurTime, 168h	; uint16_t
//@ 		ja	short loc_1C55	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_1B60	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 935
//@ 
//@ loc_1C55:				; CODE XREF: JoinServer+17Aj
//@ 					; JoinServer+182j
//@ 		cmp	MyNetN,	0	; int16_t
//@ 		mov	al, 0
//@ 		jle	short loc_1C5F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_1C5F:				; CODE XREF: JoinServer+18Ej
//@ 		mov	[bp+JoinServer], al ; bool
//@ ; #line	"CSIPX.PAS" 936
//@ 		mov	al, [bp+JoinServer] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ JoinServer	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aServerNotRespo	db 21,'SERVER NOT RESPONDING' ; DATA XREF: JoinNetworkGame+27o
//@ ; #line	"CSIPX.PAS" 938
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ JoinNetworkGame	proc near		; CODE XREF: DoGame:loc_C3F7p
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 940
//@ 		push	bp
//@ 		call	JoinServer	; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1CB2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 941
//@ 		push	bp
//@ 		call	JoinServer	; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1CB2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 942
//@ 		push	bp
//@ 		call	JoinServer	; function nested near PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1CB2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 944
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MyNetN,	ax	; int16_t
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"CSIPX.PAS" 945
//@ 		mov	di, offset aServerNotRespo ; "SERVER NOT RESPONDING"
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 946
//@ 		jmp	short locret_1CF0 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 949
//@ 
//@ loc_1CB2:				; CODE XREF: JoinNetworkGame+Aj
//@ 					; JoinNetworkGame+12j ...
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		mov	word ptr [di-0F8Eh], 1
//@ ; #line	"CSIPX.PAS" 950
//@ 		mov	di, offset SelfNick ; char[9] // Pascal	string
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, MyNetN, 58h	; int16_t
//@ 		add	di, 0F02Bh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	8
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSIPX.PAS" 952
//@ 		call	DoneChanges	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 953
//@ 		call	DoneProcesses	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 954
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		add	di, 20h	; ' '   ; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset LevelChanges	; uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		push	10h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 955
//@ 
//@ locret_1CF0:				; CODE XREF: JoinNetworkGame+31j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ JoinNetworkGame	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aErrorSendingPo	db 19,'ERROR SENDING POST.' ; DATA XREF: SendServerPost+40o
//@ 					; SendServerPost+179o
//@ ; #line	"CSIPX.PAS" 960
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SendServerPost	proc near		; CODE XREF: NewGame+Bp
//@ 					; MenuStartNet+57p ...
//@ 
//@ var_4		= dword	ptr -4
//@ Command		= byte ptr  4		; uint8_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 961
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_1D14	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1E8B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 962
//@ 
//@ loc_1D14:				; CODE XREF: SendServerPost+9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 963
//@ 
//@ loc_1D19:				; CODE XREF: SendServerPost+31j
//@ 		cmp	CurTime, 118h	; uint16_t
//@ 		jnb	short loc_1D39	; Jump if Not Below (CF=0)
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	byte ptr es:[di+14Ah], 0 ; Compare Two Operands
//@ 		jnz	short loc_1D39	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 964
//@ 		call	CheckSendComplette ; function near PASCAL returns void
//@ 		push	2
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		jmp	short loc_1D19	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 966
//@ 
//@ loc_1D39:				; CODE XREF: SendServerPost+19j
//@ 					; SendServerPost+25j
//@ 		cmp	CurTime, 118h	; uint16_t
//@ 		jb	short loc_1D53	; Jump if Below	(CF=1)
//@ ; #line	"CSIPX.PAS" 967
//@ 		mov	SERVER,	0	; bool
//@ 		mov	di, offset aErrorSendingPo ; "ERROR SENDING POST."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	locret_1E8B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 969
//@ 
//@ loc_1D53:				; CODE XREF: SendServerPost+39j
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSIPX.PAS" 971
//@ 		mov	ax, LevelN	; int16_t
//@ 		mov	es:[di+12h], ax
//@ ; #line	"CSIPX.PAS" 972
//@ 		mov	al, [bp+Command] ; uint8_t
//@ 		mov	es:[di+16h], al
//@ ; #line	"CSIPX.PAS" 973
//@ 		mov	al, byte ptr Skill ; int16_t
//@ 		mov	es:[di+17h], al
//@ ; #line	"CSIPX.PAS" 974
//@ 		mov	ax, ServerVersion ; uint16_t
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSIPX.PAS" 975
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		mov	es:[di+0Ah], ax
//@ 		mov	es:[di+0Ch], dx
//@ ; #line	"CSIPX.PAS" 976
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ah], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CSIPX.PAS" 977
//@ 		mov	di, offset LevelChanges	; uint8_t[16]
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 20h	; ' '   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	10h
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 978
//@ 		mov	di, offset ProcState ; uint16_t[4]
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 30h	; '0'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	8
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 979
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSIPX.PAS" 980
//@ 		mov	word ptr es:[di+6], 38h	; '8'
//@ ; #line	"CSIPX.PAS" 981
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1DEA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1DE6:				; CODE XREF: SendServerPost+12Aj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSIPX.PAS" 982
//@ 
//@ loc_1DEA:				; CODE XREF: SendServerPost+DEj
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		cmp	byte ptr [di-0FD6h], 0 ; Compare Two Operands
//@ 		jz	short loc_1E2B	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 984
//@ 		mov	ax, 1
//@ 		mov	cx, n$0		; int16_t
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+8], ax	; Add
//@ ; #line	"CSIPX.PAS" 985
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	38h ; '8'
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSIPX.PAS" 986
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	word ptr es:[di+6], 38h	; '8' ; Add
//@ ; #line	"CSIPX.PAS" 987
//@ 
//@ loc_1E2B:				; CODE XREF: SendServerPost+EEj
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_1DE6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSIPX.PAS" 988
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		mov	DpOfs, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 989
//@ 		mov	ax, es:[di+6]
//@ 		mov	es:[di], ax
//@ ; #line	"CSIPX.PAS" 992
//@ 		mov	word ptr DRegs.xBX, 1 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 993
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 996
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 997
//@ 
//@ loc_1E5C:				; CODE XREF: SendServerPost+16Aj
//@ 		cmp	CurTime, 118h	; uint16_t
//@ 		jnb	short loc_1E72	; Jump if Not Below (CF=0)
//@ 		les	di, PInfoStruct	; TInfo_Struct*
//@ 		cmp	byte ptr es:[di+14Ah], 0 ; Compare Two Operands
//@ 		jnz	short loc_1E72	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_1E5C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 998
//@ 
//@ loc_1E72:				; CODE XREF: SendServerPost+15Cj
//@ 					; SendServerPost+168j
//@ 		cmp	CurTime, 118h	; uint16_t
//@ 		jb	short locret_1E8B ; Jump if Below (CF=1)
//@ ; #line	"CSIPX.PAS" 999
//@ 		mov	SERVER,	0	; bool
//@ 		mov	di, offset aErrorSendingPo ; "ERROR SENDING POST."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		jmp	short $+2	; Jump
//@ ; #line	"CSIPX.PAS" 1000
//@ 
//@ locret_1E8B:				; CODE XREF: SendServerPost+Bj
//@ 					; SendServerPost+4Aj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	2		; Return Near from Procedure
//@ SendServerPost	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_1E8F	db 8,'########'         ; DATA XREF: SyncroTime+96o
//@ aServerTime	db 12,'SERVER TIME:'    ; DATA XREF: SyncroTime+86o
//@ ; #line	"CSIPX.PAS" 1005
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SyncroTime	proc near		; CODE XREF: ExecConsole+C19p
//@ 
//@ var_202		= byte ptr -202h
//@ var_102		= byte ptr -102h
//@ Ok		= byte ptr -1		; bool
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 1006
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1EB3	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_1F5E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 1008
//@ 
//@ loc_1EB3:				; CODE XREF: SyncroTime+9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ 		mov	[bp+Ok], 0	; bool
//@ ; #line	"CSIPX.PAS" 1009
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ ; #line	"CSIPX.PAS" 1013
//@ 
//@ loc_1EC6:				; CODE XREF: SyncroTime+73j
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ ; #line	"CSIPX.PAS" 1014
//@ 		cmp	word ptr es:[di+12h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1EEE	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 1016
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	dx, es:[di+0Ch]
//@ 		mov	word ptr RealTime, ax ;	int32_t
//@ 		mov	word ptr RealTime+2, dx	; int32_t
//@ 		mov	[bp+Ok], 1	; bool
//@ ; #line	"CSIPX.PAS" 1017
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ ; #line	"CSIPX.PAS" 1020
//@ 
//@ loc_1EEE:				; CODE XREF: SyncroTime+2Aj
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 1021
//@ 		push	1
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 1022
//@ 		mov	word ptr DRegs.xBX, 9 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ ; #line	"CSIPX.PAS" 1023
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 1024
//@ 		cmp	[bp+Ok], 0	; bool
//@ 		jnz	short loc_1F1A	; Jump if Not Zero (ZF=0)
//@ 		cmp	CurTime, 8Ch ; 'Œ' ; uint16_t
//@ 		jbe	short loc_1EC6	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 1025
//@ 
//@ loc_1F1A:				; CODE XREF: SyncroTime+6Bj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 1026
//@ 		cmp	[bp+Ok], 0	; bool
//@ 		jz	short locret_1F5E ; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aServerTime ; "SERVER TIME:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset asc_1E8F ; "########"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSIPX.PAS" 1027
//@ 
//@ locret_1F5E:				; CODE XREF: SyncroTime+Bj
//@ 					; SyncroTime+7Ej
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ SyncroTime	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aServerTimeOut_	db 16,'SERVER TIME OUT.' ; DATA XREF: WaitServer+A2o
//@ ; #line	"CSIPX.PAS" 1032
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ WaitServer	proc near		; CODE XREF: DoGame:loc_C411p
//@ 					; DoGame+19Ep
//@ 
//@ Ok		= byte ptr -1		; bool
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSIPX.PAS" 1033
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_1F7F	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2028	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSIPX.PAS" 1035
//@ 
//@ loc_1F7F:				; CODE XREF: WaitServer+9j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ 		mov	[bp+Ok], 0	; bool
//@ ; #line	"CSIPX.PAS" 1036
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	word ptr es:[di+12h], 0FFFFh
//@ ; #line	"CSIPX.PAS" 1040
//@ 
//@ loc_1F92:				; CODE XREF: WaitServer+95j
//@ 		call	ReInstallFreeECB ; function near PASCAL	returns	void
//@ ; #line	"CSIPX.PAS" 1041
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ ; #line	"CSIPX.PAS" 1042
//@ 		cmp	word ptr es:[di+12h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1FDF	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 1044
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	dx, es:[di+0Ch]
//@ 		mov	word ptr RealTime, ax ;	int32_t
//@ 		mov	word ptr RealTime+2, dx	; int32_t
//@ 		mov	[bp+Ok], 1	; bool
//@ ; #line	"CSIPX.PAS" 1045
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es:[di+12h]
//@ 		cmp	ax, LevelN	; int16_t
//@ 		jz	short loc_1FDF	; Jump if Zero (ZF=1)
//@ ; #line	"CSIPX.PAS" 1047
//@ 		mov	MenuCode, 4	; uint16_t
//@ ; #line	"CSIPX.PAS" 1048
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	ax, es:[di+12h]
//@ 		mov	LevelN,	ax	; int16_t
//@ ; #line	"CSIPX.PAS" 1049
//@ 		les	di, PServerPatch ; TServer_Patch*
//@ 		mov	al, es:[di+17h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Skill, ax	; int16_t
//@ ; #line	"CSIPX.PAS" 1053
//@ 
//@ loc_1FDF:				; CODE XREF: WaitServer+2Dj
//@ 					; WaitServer+4Ej
//@ 		push	1
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ 		mov	word ptr DRegs.xBX, 9 ;	struct TDPMIRegs
//@ 		mov	word ptr DRegs.xBX+2, 0	; struct TDPMIRegs
//@ 		mov	di, offset DRegs ; struct TDPMIRegs
//@ 		push	ds
//@ 		push	di
//@ 		call	RealInt60h	; function near	PASCAL returns void
//@ ; #line	"CSIPX.PAS" 1054
//@ 		cmp	[bp+Ok], 0	; bool
//@ 		jnz	short loc_2008	; Jump if Not Zero (ZF=0)
//@ 		cmp	CurTime, 578h	; uint16_t
//@ 		jbe	short loc_1F92	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSIPX.PAS" 1056
//@ 
//@ loc_2008:				; CODE XREF: WaitServer+8Dj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ ; #line	"CSIPX.PAS" 1057
//@ 		cmp	[bp+Ok], 0	; bool
//@ 		jnz	short locret_2028 ; Jump if Not	Zero (ZF=0)
//@ 		mov	di, offset aServerTimeOut_ ; "SERVER TIME OUT."
//@ 		push	cs
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ 		mov	MenuCode, 4	; uint16_t
//@ 		mov	CLIENT,	0	; bool
//@ ; #line	"CSIPX.PAS" 1058
//@ 
//@ locret_2028:				; CODE XREF: WaitServer+Bj
//@ 					; WaitServer+A0j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ WaitServer	endp
//@ 
