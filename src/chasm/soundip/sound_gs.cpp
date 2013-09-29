
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

#include "soundip/sound_gs.h"

//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 194
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ Addr_HIGH	proc far		; CODE XREF: UltraPrimeVoice+6FP
//@ 					; UltraPrimeVoice+8EP ...
//@ 
//@ Addr_HIGH	= word ptr -2		; uint16_t
//@ x		= word ptr  6		; int32_t
//@ arg_2		= word ptr  8
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	ax, [bp+x]	; int32_t
//@ 		mov	dx, [bp+arg_2]
//@ 		mov	cx, 7
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		and	ax, 1FFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	[bp+Addr_HIGH],	ax ; uint16_t
//@ 		mov	ax, [bp+Addr_HIGH] ; uint16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ Addr_HIGH	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 196
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ Addr_LOW	proc far		; CODE XREF: UltraPrimeVoice+50P
//@ 					; UltraPrimeVoice+ADP ...
//@ 
//@ Addr_LOW	= word ptr -2		; uint16_t
//@ x		= word ptr  6		; int32_t
//@ arg_2		= word ptr  8
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	ax, [bp+x]	; int32_t
//@ 		mov	dx, [bp+arg_2]
//@ 		and	ax, 7Fh		; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	cx, 9
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	[bp+Addr_LOW], ax ; uint16_t
//@ 		mov	ax, [bp+Addr_LOW] ; uint16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ Addr_LOW	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 199
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GF1_Delay	proc far		; CODE XREF: UltraReset:loc_32BFFP
//@ 					; UltraReset:loc_32C1FP ...
//@ 
//@ m		= byte ptr -3		; uint8_t
//@ i		= word ptr -2		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_32AC9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32AC6:				; CODE XREF: GF1_Delay+1Ej
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_32AC9:				; CODE XREF: GF1_Delay+9j
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 107h	; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		mov	[bp+m],	al	; uint8_t
//@ 		cmp	[bp+i],	6	; int16_t
//@ 		jnz	short loc_32AC6	; Jump if Not Zero (ZF=0)
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ GF1_Delay	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 204
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ GUSPeekData	proc far		; CODE XREF: TestGUS+31P TestGUS+43P
//@ 
//@ GUSPeekData	= byte ptr -1		; uint8_t
//@ Address		= word ptr  6		; int32_t
//@ arg_2		= word ptr  8
//@ PPort		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 205
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 43h	; 'C'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 206
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+Address] ; int32_t
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 207
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 44h	; 'D'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 208
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 105h	; Add
//@ 		push	ax
//@ 		mov	ax, [bp+Address] ; int32_t
//@ 		mov	dx, [bp+arg_2]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		pop	dx
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 209
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 107h	; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		mov	[bp+GUSPeekData], al ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 210
//@ 		mov	al, [bp+GUSPeekData] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ GUSPeekData	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 216
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GUSPokeData	proc far		; CODE XREF: TestGUS+13P TestGUS+23P
//@ 
//@ Data		= byte ptr  6		; uint8_t
//@ Address		= word ptr  8		; int32_t
//@ arg_4		= word ptr  0Ah
//@ PPort		= word ptr  0Ch		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 217
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 43h	; 'C'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 218
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+Address] ; int32_t
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 219
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 44h	; 'D'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 220
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 105h	; Add
//@ 		push	ax
//@ 		mov	ax, [bp+Address] ; int32_t
//@ 		mov	dx, [bp+arg_4]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		pop	dx
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 221
//@ 		mov	ax, [bp+PPort]	; int16_t
//@ 		add	ax, 107h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Data]	; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 222
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ GUSPokeData	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 227
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ClearGUSMemory	proc far		; CODE XREF: DeInitGUS+35P InitGUS+13P
//@ 
//@ n		= word ptr -2		; uint16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 228
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 44h	; 'D'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 229
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 230
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_32BA1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32B9E:				; CODE XREF: ClearGUSMemory+4Aj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 232
//@ 
//@ loc_32BA1:				; CODE XREF: ClearGUSMemory+1Fj
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 43h	; 'C'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 233
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 234
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 107h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 235
//@ 		cmp	[bp+n],	0FFFFh	; uint16_t
//@ 		jnz	short loc_32B9E	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 236
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ClearGUSMemory	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 249
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ UltraReset	proc far		; CODE XREF: InitGUS+EP
//@ 
//@ var_9		= byte ptr -9
//@ Data_Hi		= word ptr -8		; int16_t
//@ Data_Lo		= word ptr -6		; int16_t
//@ Select		= word ptr -4		; int16_t
//@ V		= byte ptr -2		; uint8_t
//@ UltraReset	= byte ptr -1		; bool
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 250
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	[bp+Select], ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 251
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	[bp+Data_Hi], ax ; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 252
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	[bp+Data_Lo], ax ; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 253
//@ 		mov	al, 4Ch	; 'L'
//@ 		mov	dx, [bp+Select]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 254
//@ 		mov	al, 0
//@ 		mov	dx, [bp+Data_Hi] ; int16_t
//@ 		out	dx, al
//@ 		mov	[bp+V],	0	; uint8_t
//@ 		jmp	short loc_32BFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32BFC:				; CODE XREF: UltraReset+3Dj
//@ 		inc	[bp+V]		; uint8_t
//@ 
//@ loc_32BFF:				; CODE XREF: UltraReset+2Fj
//@ 		call	GF1_Delay	; function far PASCAL returns void
//@ 		cmp	[bp+V],	9	; uint8_t
//@ 		jnz	short loc_32BFC	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 255
//@ 		mov	al, 4Ch	; 'L'
//@ 		mov	dx, [bp+Select]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 256
//@ 		mov	al, 1
//@ 		mov	dx, [bp+Data_Hi] ; int16_t
//@ 		out	dx, al
//@ 		mov	[bp+V],	0	; uint8_t
//@ 		jmp	short loc_32C1F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32C1C:				; CODE XREF: UltraReset+5Dj
//@ 		inc	[bp+V]		; uint8_t
//@ 
//@ loc_32C1F:				; CODE XREF: UltraReset+4Fj
//@ 		call	GF1_Delay	; function far PASCAL returns void
//@ 		cmp	[bp+V],	9	; uint8_t
//@ 		jnz	short loc_32C1C	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 257
//@ 		mov	al, 0Eh
//@ 		mov	dx, [bp+Select]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 258
//@ 		mov	ax, GUSVoices	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		or	ax, 0C0h	; Logical Inclusive OR
//@ 		mov	dx, [bp+Data_Hi] ; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 259
//@ 		mov	ax, GUSVoices	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_9], al
//@ 		mov	al, 0
//@ 		cmp	al, [bp+var_9]	; Compare Two Operands
//@ 		ja	short loc_32C82	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	[bp+V],	al	; uint8_t
//@ 		jmp	short loc_32C51	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_32C4E:				; CODE XREF: UltraReset+B5j
//@ 		inc	[bp+V]		; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 261
//@ 
//@ loc_32C51:				; CODE XREF: UltraReset+81j
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+V]	; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 263
//@ 		mov	al, 0
//@ 		mov	dx, [bp+Select]	; int16_t
//@ 		out	dx, al
//@ 		mov	al, 3
//@ 		mov	dx, [bp+Data_Hi] ; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 264
//@ 		mov	al, 0Dh
//@ 		mov	dx, [bp+Select]	; int16_t
//@ 		out	dx, al
//@ 		mov	al, 3
//@ 		mov	dx, [bp+Data_Hi] ; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 265
//@ 		call	GF1_Delay	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 266
//@ 		mov	al, [bp+V]	; uint8_t
//@ 		cmp	al, [bp+var_9]	; Compare Two Operands
//@ 		jnz	short loc_32C4E	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 268
//@ 
//@ loc_32C82:				; CODE XREF: UltraReset+7Cj
//@ 		mov	al, 4Ch	; 'L'
//@ 		mov	dx, [bp+Select]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 269
//@ 		mov	al, 7
//@ 		mov	dx, [bp+Data_Hi] ; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 270
//@ 		mov	al, [bp+UltraReset] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ UltraReset	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 282
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ UltraPrimeVoice	proc far		; CODE XREF: InitGUS+78P InitGUS+A0P ...
//@ 
//@ UltraPrimeVoice	= byte ptr -1		; uint8_t
//@ VMode		= byte ptr  6		; uint8_t
//@ VEnd		= word ptr  8		; int32_t
//@ arg_4		= word ptr  0Ah
//@ VStart		= word ptr  0Ch		; int32_t
//@ arg_8		= word ptr  0Eh
//@ Voice		= byte ptr  10h		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 283
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Voice]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 284
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0Dh
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 285
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+VMode]	; uint8_t
//@ 		out	dx, al
//@ 		call	GF1_Delay	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 286
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+VMode]	; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 289
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0Bh
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 290
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_8]
//@ 		push	[bp+VStart]	; int32_t
//@ 		call	Addr_LOW	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 291
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0Ah
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 292
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_8]
//@ 		push	[bp+VStart]	; int32_t
//@ 		call	Addr_HIGH	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 294
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 2
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 295
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_8]
//@ 		push	[bp+VStart]	; int32_t
//@ 		call	Addr_HIGH	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 296
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 3
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 297
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_8]
//@ 		push	[bp+VStart]	; int32_t
//@ 		call	Addr_LOW	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 299
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 4
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 300
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_4]
//@ 		push	[bp+VEnd]	; int32_t
//@ 		call	Addr_HIGH	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 301
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 5
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 302
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_4]
//@ 		push	[bp+VEnd]	; int32_t
//@ 		call	Addr_LOW	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 303
//@ 		mov	al, [bp+UltraPrimeVoice] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ UltraPrimeVoice	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 308
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UltraSetVoiceEnd proc far		; CODE XREF: GUS_StartNext+7CP
//@ 					; GUS_StartNext+8AP
//@ 
//@ VEnd		= word ptr  6		; int32_t
//@ arg_2		= word ptr  8
//@ Voice		= byte ptr  0Ah		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 309
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Voice]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 311
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 4
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 312
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_2]
//@ 		push	[bp+VEnd]	; int32_t
//@ 		call	Addr_HIGH	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 313
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 5
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 314
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		push	[bp+arg_2]
//@ 		push	[bp+VEnd]	; int32_t
//@ 		call	Addr_LOW	; function far PASCAL returns unsigned int 'Word'
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 315
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ UltraSetVoiceEnd endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 320
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UltraGoVoice	proc far		; CODE XREF: DeInitGUS+1EP
//@ 					; DeInitGUS+27P ...
//@ 
//@ VMode		= byte ptr  6		; uint8_t
//@ Voice		= byte ptr  8		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 321
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Voice]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 322
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 323
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+VMode]	; uint8_t
//@ 		out	dx, al
//@ 		call	GF1_Delay	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 324
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+VMode]	; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 325
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ UltraGoVoice	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 329
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UltraSetFrequency proc far		; CODE XREF: InitGUS+66P InitGUS+8DP ...
//@ 
//@ Speed		= word ptr  6		; int32_t
//@ arg_2		= word ptr  8
//@ Voice		= byte ptr  0Ah		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 330
//@ 		mov	ax, GUSVoices	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 6BB8h
//@ 		mov	dx, 9
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+Speed]	; int32_t
//@ 		mov	dx, [bp+arg_2]
//@ 		mov	cx, 9
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+Speed], ax	; int32_t
//@ 		mov	[bp+arg_2], dx
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 331
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Voice]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 332
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 1
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 333
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		mov	ax, [bp+Speed]	; int32_t
//@ 		mov	dx, [bp+arg_2]
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 334
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ UltraSetFrequency endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 337
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UltraSetBalance	proc far		; CODE XREF: InitGUS+81P InitGUS+A9P ...
//@ 
//@ Data		= byte ptr  6		; uint8_t
//@ Voice		= byte ptr  8		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 338
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Voice]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 339
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0Ch
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 340
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Data]	; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 341
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ UltraSetBalance	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 344
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UltraSetVolume	proc far		; CODE XREF: DeInitGUS+CP
//@ 					; DeInitGUS+15P ...
//@ 
//@ Volume		= word ptr  6		; uint16_t
//@ Voice		= byte ptr  8		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 345
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Voice]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 346
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 9
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 347
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+Volume]	; uint16_t
//@ 		out	dx, ax
//@ 		call	GF1_Delay	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 348
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+Volume]	; uint16_t
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 349
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ UltraSetVolume	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 354
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ UltraReadVoice	proc far		; CODE XREF: GUS_StartNext+1AP
//@ 					; GUS_StartNext+54P ...
//@ 
//@ High		= word ptr -6		; uint16_t
//@ Low		= word ptr -4		; uint16_t
//@ UltraReadVoice	= word ptr -2		; uint16_t
//@ Voice		= byte ptr  6		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 355
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Voice]	; int16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 356
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 8Ah	; 'ä'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 357
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	dx, ax
//@ 		in	ax, dx
//@ 		mov	[bp+High], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 358
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 8Bh	; 'ã'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 359
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		mov	dx, ax
//@ 		in	ax, dx
//@ 		mov	[bp+Low], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 360
//@ 		mov	ax, [bp+Low]	; uint16_t
//@ 		shr	ax, 9		; Shift	Logical	Right
//@ 		and	ax, 7Fh		; Logical AND
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+High]	; uint16_t
//@ 		and	ax, 1FFh	; Logical AND
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		mov	[bp+UltraReadVoice], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 362
//@ 		mov	ax, [bp+UltraReadVoice]	; uint16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ UltraReadVoice	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 373
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PrimeDMA	proc far		; CODE XREF: UltraDMADRAM_64K+10P
//@ 
//@ S_Addr		= word ptr -0Ch		; uint16_t
//@ S_Page		= word ptr -0Ah		; uint16_t
//@ S_20Bit		= word ptr -8		; int32_t
//@ var_6		= word ptr -6
//@ TDMAPtr		= dword	ptr -4		; DMA_Entry*
//@ Channel		= word ptr  6		; uint16_t
//@ Size		= word ptr  8		; uint16_t
//@ DMAOfs		= word ptr  0Ah		; uint16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 374
//@ 		mov	ax, [bp+Channel] ; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	di, ax,	19h	; Signed Multiply
//@ 		lea	ax, [di+2B8h]	; Load Effective Address
//@ 		mov	dx, ds
//@ 		mov	word ptr [bp+TDMAPtr], ax ; DMA_Entry*
//@ 		mov	word ptr [bp+TDMAPtr+2], dx ; DMA_Entry*
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 375
//@ 		mov	ax, [bp+DMAOfs]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, word ptr dma20bit ;	int32_t
//@ 		adc	dx, word ptr dma20bit+2	; int32_t
//@ 		mov	[bp+S_20Bit], ax ; int32_t
//@ 		mov	[bp+var_6], dx
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 376
//@ 		mov	ax, [bp+S_20Bit] ; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		and	ax, 0		; Logical AND
//@ 		and	dx, 0FFFFh	; Logical AND
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+S_Page], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 377
//@ 		cmp	[bp+Channel], 4	; uint16_t
//@ 		jb	short loc_32FAC	; Jump if Below	(CF=1)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 379
//@ 		mov	ax, [bp+S_20Bit] ; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+S_20Bit], ax ; int32_t
//@ 		mov	[bp+var_6], dx
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 380
//@ 		mov	ax, [bp+Size]	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	[bp+Size], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 382
//@ 
//@ loc_32FAC:				; CODE XREF: PrimeDMA+48j
//@ 		mov	ax, [bp+S_20Bit] ; int32_t
//@ 		mov	dx, [bp+var_6]
//@ 		and	ax, 0FFFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	[bp+S_Addr], ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 383
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	al, es:[di+4]
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+0Eh]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 384
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	al, es:[di+14h]
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+10h]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 385
//@ 		mov	al, 0
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+12h]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 386
//@ 		mov	al, byte ptr [bp+S_Addr] ; uint16_t
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+0Ah]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 387
//@ 		mov	al, byte ptr [bp+S_Addr+1] ; uint16_t
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+0Ah]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 388
//@ 		mov	al, byte ptr [bp+S_Page] ; uint16_t
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+8]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 389
//@ 		mov	al, 0
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+12h]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 390
//@ 		mov	ax, [bp+Size]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+0Ch]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 391
//@ 		mov	ax, [bp+Size]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	al, ah
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+0Ch]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 392
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	al, es:[di+6]
//@ 		les	di, [bp+TDMAPtr] ; DMA_Entry*
//@ 		mov	dx, es:[di+0Eh]
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 393
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ PrimeDMA	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 408
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UltraDMADRAM_64K proc far		; CODE XREF: SendBlock+2BP
//@ 
//@ DRAM_Address	= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ Control		= byte ptr  6		; uint8_t
//@ Ultra_PTR	= word ptr  8		; int32_t
//@ arg_4		= word ptr  0Ah
//@ Size		= word ptr  0Ch		; uint16_t
//@ DMAOfs		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 409
//@ 		push	[bp+DMAOfs]	; uint16_t
//@ 		push	[bp+Size]	; uint16_t
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	PrimeDMA	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 411
//@ 		cmp	sDMA, 4		; uint8_t
//@ 		jb	short loc_33070	; Jump if Below	(CF=1)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 412
//@ 		mov	ax, [bp+Ultra_PTR] ; int32_t
//@ 		mov	dx, [bp+arg_4]
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	[bp+DRAM_Address], ax ;	int32_t
//@ 		mov	[bp+var_2], dx
//@ 		jmp	short loc_3307C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 413
//@ 
//@ loc_33070:				; CODE XREF: UltraDMADRAM_64K+1Aj
//@ 		mov	ax, [bp+Ultra_PTR] ; int32_t
//@ 		mov	dx, [bp+arg_4]
//@ 		mov	[bp+DRAM_Address], ax ;	int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 415
//@ 
//@ loc_3307C:				; CODE XREF: UltraDMADRAM_64K+32j
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 42h	; 'B'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 416
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 104h	; Add
//@ 		push	ax
//@ 		mov	ax, [bp+DRAM_Address] ;	int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		pop	dx
//@ 		out	dx, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 418
//@ 		mov	al, [bp+Control] ; uint8_t
//@ 		or	al, 1		; Logical Inclusive OR
//@ 		mov	[bp+Control], al ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 419
//@ 		cmp	sDMA, 4		; uint8_t
//@ 		jb	short loc_330B7	; Jump if Below	(CF=1)
//@ 		mov	al, [bp+Control] ; uint8_t
//@ 		or	al, 4		; Logical Inclusive OR
//@ 		mov	[bp+Control], al ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 421
//@ 
//@ loc_330B7:				; CODE XREF: UltraDMADRAM_64K+71j
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 41h	; 'A'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 422
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Control] ; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 423
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ UltraDMADRAM_64K endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 440
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UltraSetInterface proc far		; CODE XREF: InitGUS+4EP
//@ 
//@ Mix_Image	= byte ptr -4		; uint8_t
//@ DMA_Control	= byte ptr -3		; uint8_t
//@ IRQ_Control	= byte ptr -2		; uint8_t
//@ GF1_IRQ		= byte ptr -1		; uint8_t
//@ GF1		= word ptr  6		; int16_t
//@ DRAM		= word ptr  8		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 441
//@ 		mov	di, [bp+GF1]	; int16_t
//@ 		mov	al, [di+2A8h]
//@ 		mov	[bp+GF1_IRQ], al ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 443
//@ 		cmp	[bp+DRAM], 0	; int16_t
//@ 		jz	short loc_330F4	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+DRAM]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	di, ax,	19h	; Signed Multiply
//@ 		mov	al, [di+2BAh]
//@ 		mov	DRAM_DMA, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 444
//@ 
//@ loc_330F4:				; CODE XREF: UltraSetInterface+12j
//@ 		mov	al, [bp+GF1_IRQ] ; uint8_t
//@ 		mov	[bp+IRQ_Control], al ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 445
//@ 		mov	al, DRAM_DMA	; uint8_t
//@ 		mov	[bp+DMA_Control], al ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 446
//@ 		mov	[bp+Mix_Image],	0 ; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 448
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Fh		; Add
//@ 		mov	dx, ax
//@ 		mov	al, 5
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 449
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Mix_Image] ; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 450
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Bh		; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 451
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Fh		; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 453
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Mix_Image] ; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 454
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Bh		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+DMA_Control] ; uint8_t
//@ 		or	al, 80h		; Logical Inclusive OR
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 456
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Mix_Image] ; uint8_t
//@ 		or	al, 40h		; Logical Inclusive OR
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 457
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Bh		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+IRQ_Control] ; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 459
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Mix_Image] ; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 460
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Bh		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+DMA_Control] ; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 462
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+Mix_Image] ; uint8_t
//@ 		or	al, 40h		; Logical Inclusive OR
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 463
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 0Bh		; Add
//@ 		mov	dx, ax
//@ 		mov	al, [bp+IRQ_Control] ; uint8_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 465
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 102h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 0
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 466
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ UltraSetInterface endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 474
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DeInitGUS	proc far		; CODE XREF: DeInitSoundSystem+1DP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 475
//@ 		call	DisableSFXIRQ	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 476
//@ 		push	0
//@ 		push	0
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 477
//@ 		push	1
//@ 		push	0
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 478
//@ 		push	0
//@ 		push	3
//@ 		call	UltraGoVoice	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 479
//@ 		push	1
//@ 		push	3
//@ 		call	UltraGoVoice	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 480
//@ 		push	7
//@ 		push	3
//@ 		call	UltraGoVoice	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 481
//@ 		call	ClearGUSMemory	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 482
//@ 		push	0
//@ 		push	0FFF0h
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 483
//@ 		push	1
//@ 		push	0FFF0h
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 484
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DeInitGUS	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 495
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GUS_InitDMABuffers proc	far		; CODE XREF: InitGUS+9P
//@ 
//@ L		= word ptr -0Ch		; int32_t
//@ var_A		= word ptr -0Ah
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 496
//@ 		push	0
//@ 		push	1000h
//@ 		call	GlobalDosAlloc	; Call Procedure
//@ 		mov	[bp+L],	ax	; int32_t
//@ 		mov	[bp+var_A], dx
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 497
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_A]
//@ 		and	ax, 0FFFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	SFXDMASeg, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 498
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_A]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	word ptr dma20bit, ax ;	int32_t
//@ 		mov	word ptr dma20bit+2, dx	; int32_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 500
//@ 		mov	ax, word ptr dma20bit ;	int32_t
//@ 		mov	dx, word ptr dma20bit+2	; int32_t
//@ 		add	ax, 1000h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, word ptr dma20bit ;	int32_t
//@ 		mov	dx, word ptr dma20bit+2	; int32_t
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_3326D	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_332AE	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 502
//@ 
//@ loc_3326D:				; CODE XREF: GUS_InitDMABuffers+73j
//@ 		push	0
//@ 		push	2000h
//@ 		call	GlobalDosAlloc	; Call Procedure
//@ 		mov	[bp+L],	ax	; int32_t
//@ 		mov	[bp+var_A], dx
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 503
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_A]
//@ 		and	ax, 0FFFFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	SFXDMASeg, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 504
//@ 		mov	ax, [bp+L]	; int32_t
//@ 		mov	dx, [bp+var_A]
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		mov	cx, 4
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		mov	word ptr dma20bit, ax ;	int32_t
//@ 		mov	word ptr dma20bit+2, dx	; int32_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 507
//@ 
//@ loc_332AE:				; CODE XREF: GUS_InitDMABuffers+77j
//@ 		mov	ax, word ptr dma20bit ;	int32_t
//@ 		mov	dx, word ptr dma20bit+2	; int32_t
//@ 		add	ax, 1000h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, word ptr dma20bit ;	int32_t
//@ 		mov	dx, word ptr dma20bit+2	; int32_t
//@ 		mov	cx, 10h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_332E2	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_332E9	; Jump if Zero (ZF=1)
//@ 
//@ loc_332E2:				; CODE XREF: GUS_InitDMABuffers+E8j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		call	far ptr	@Halt$q4Word ; Halt(exitcode: Word{AX})
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 509
//@ 
//@ loc_332E9:				; CODE XREF: GUS_InitDMABuffers+ECj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	dx, SFXDMASeg	; uint16_t
//@ 		mov	word ptr SFXDMABuf, ax ; void*
//@ 		mov	word ptr SFXDMABuf+2, dx ; void*
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 510
//@ 		mov	di, offset SFXBuf ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16$0	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 511
//@ 		les	di, SFXBuf	; void*
//@ 		mov	ax, es
//@ 		mov	SFXBufSeg, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 512
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ GUS_InitDMABuffers endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 518
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ TestGUS		proc far		; CODE XREF: RegisterCard+47P
//@ 
//@ TestGUS		= byte ptr -1		; bool
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 519
//@ 		mov	[bp+TestGUS], 1	; bool
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 520
//@ 		push	sBase		; uint16_t
//@ 		push	0
//@ 		push	4200h
//@ 		push	11h
//@ 		call	GUSPokeData	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 521
//@ 		push	sBase		; uint16_t
//@ 		push	0
//@ 		push	4201h
//@ 		push	22h ; '"'
//@ 		call	GUSPokeData	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 522
//@ 		push	sBase		; uint16_t
//@ 		push	0
//@ 		push	4200h
//@ 		call	GUSPeekData	; function far PASCAL returns unsigned char 'Byte'
//@ 		cmp	al, 11h		; Compare Two Operands
//@ 		jnz	short loc_3335C	; Jump if Not Zero (ZF=0)
//@ 		push	sBase		; uint16_t
//@ 		push	0
//@ 		push	4201h
//@ 		call	GUSPeekData	; function far PASCAL returns unsigned char 'Byte'
//@ 		cmp	al, 22h	; '"'   ; Compare Two Operands
//@ 		jnz	short loc_3335C	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 523
//@ 		jmp	short loc_33360	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 524
//@ 
//@ loc_3335C:				; CODE XREF: TestGUS+38j TestGUS+4Aj
//@ 		mov	[bp+TestGUS], 0	; bool
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 525
//@ 
//@ loc_33360:				; CODE XREF: TestGUS+4Cj
//@ 		mov	al, [bp+TestGUS] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ TestGUS		endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 530
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GUS_MixNextBlock proc far		; CODE XREF: GUS_StartNext+AAP
//@ 
//@ var_4		= dword	ptr -4
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 531
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	800h
//@ 		push	0
//@ 		call	StosW$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 532
//@ 		call	ContinueAmbient	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 534
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXC, ax	; uint16_t
//@ 		jmp	short loc_33389	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_33385:				; CODE XREF: GUS_MixNextBlock+2BBj
//@ 		inc	SFXC		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 535
//@ 
//@ loc_33389:				; CODE XREF: GUS_MixNextBlock+1Ej
//@ 		imul	di, SFXC, 0Eh	; uint16_t
//@ 		add	di, 0F782h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ 		cmp	word ptr es:[di+6], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_333A5	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_33619	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 537
//@ 
//@ loc_333A5:				; CODE XREF: GUS_MixNextBlock+3Bj
//@ 		cmp	word ptr es:[di+0Ah], 0	; Compare Two Operands
//@ 		jz	short loc_333B3	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+0Ch], 0	; Compare Two Operands
//@ 		jnz	short loc_333DA	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 538
//@ 
//@ loc_333B3:				; CODE XREF: GUS_MixNextBlock+45j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_333CB	; Jump if Not Zero (ZF=0)
//@ 		mov	_SFXRv,	50h ; 'P' ; uint16_t
//@ 		mov	_SFXLv,	50h ; 'P' ; uint16_t
//@ 		jmp	short loc_333D7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 539
//@ 
//@ loc_333CB:				; CODE XREF: GUS_MixNextBlock+56j
//@ 		mov	_SFXRv,	50h ; 'P' ; uint16_t
//@ 		mov	_SFXLv,	50h ; 'P' ; uint16_t
//@ 
//@ loc_333D7:				; CODE XREF: GUS_MixNextBlock+64j
//@ 		jmp	loc_33516	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 542
//@ 
//@ loc_333DA:				; CODE XREF: GUS_MixNextBlock+4Cj
//@ 		mov	ax, Px		; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		mov	SFXSx, ax	; int16_t
//@ 		mov	ax, Py		; int16_t
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		mov	SFXSy, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 544
//@ 		mov	ax, SFXSy	; int16_t
//@ 		mov	bx, PCos	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		mov	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 545
//@ 		mov	ax, SFXSx	; int16_t
//@ 		mov	bx, PSin	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		add	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 546
//@ 		mov	ax, SFXSx	; int16_t
//@ 		mov	bx, PCos	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		mov	SFXSrx,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 547
//@ 		mov	ax, SFXSy	; int16_t
//@ 		mov	bx, PSin	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, 1000h
//@ 		idiv	bx		; Signed Divide
//@ 		sub	SFXSrx,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 549
//@ 		cmp	SFXSry,	0	; int16_t
//@ 		jge	short loc_33446	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, SFXSry	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	SFXSry,	ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 550
//@ 
//@ loc_33446:				; CODE XREF: GUS_MixNextBlock+D7j
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	SFXSry,	ax	; int16_t
//@ 		cmp	SFXSry,	0Eh	; int16_t
//@ 		jge	short loc_3345E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	SFXSry,	0Eh	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 551
//@ 
//@ loc_3345E:				; CODE XREF: GUS_MixNextBlock+F1j
//@ 		mov	ax, SFXSrx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	SFXSrxA, ax	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 552
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cmp	ax, SFXSrxA	; int16_t
//@ 		jle	short loc_33488	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 555
//@ 		mov	ax, SFXSrxA	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 556
//@ 		mov	bx, 0A0h ; '†'
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 557
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 558
//@ 		mov	bx, SFXSry	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 559
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 560
//@ 		add	ax, 240h	; Add
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 561
//@ 		mov	SFXRvW,	ax	; uint16_t
//@ 		jmp	short loc_3349E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 564
//@ 
//@ loc_33488:				; CODE XREF: GUS_MixNextBlock+10Bj
//@ 		mov	ax, SFXSry	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 565
//@ 		mov	bx, 0A0h ; '†'
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 566
//@ 		mul	bx		; Unsigned Multiplication of AL	or AX
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 567
//@ 		mov	bx, SFXSrxA	; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 568
//@ 		div	bx		; Unsigned Divide
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 569
//@ 		neg	ax		; Two's Complement Negation
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 570
//@ 		add	ax, 380h	; Add
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 571
//@ 		mov	SFXRvW,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 575
//@ 
//@ loc_3349E:				; CODE XREF: GUS_MixNextBlock+121j
//@ 		mov	ax, 480h
//@ 		sub	ax, SFXRvW	; uint16_t
//@ 		mov	SFXLvW,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 577
//@ 		mov	ax, SFXSry	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, SFXSrx	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	SFXLn, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 578
//@ 		cmp	SFXLn, 0Ch	; uint16_t
//@ 		jnb	short loc_334D1	; Jump if Not Below (CF=0)
//@ 		mov	SFXLn, 8	; uint16_t
//@ 		jmp	short loc_334DD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_334D1:				; CODE XREF: GUS_MixNextBlock+162j
//@ 		mov	ax, SFXLn	; uint16_t
//@ 		sub	ax, 0Ch		; Integer Subtraction
//@ 		add	ax, 8		; Add
//@ 		mov	SFXLn, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 580
//@ 
//@ loc_334DD:				; CODE XREF: GUS_MixNextBlock+16Aj
//@ 		cmp	SFXSrx,	0	; int16_t
//@ 		jle	short loc_334FE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, SFXRvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		mov	ax, SFXLvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ 		jmp	short loc_33516	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 581
//@ 
//@ loc_334FE:				; CODE XREF: GUS_MixNextBlock+17Dj
//@ 		mov	ax, SFXLvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		mov	ax, SFXRvW	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	SFXLn		; uint16_t
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 584
//@ 
//@ loc_33516:				; CODE XREF: GUS_MixNextBlock:loc_333D7j
//@ 					; GUS_MixNextBlock+197j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	VcSeg, ax	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		mov	_CurBlock, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 585
//@ 		cmp	Reverse, 0	; bool
//@ 		jz	short loc_33542	; Jump if Zero (ZF=1)
//@ 		push	_SFXLv		; uint16_t
//@ 		push	_SFXRv		; uint16_t
//@ 		pop	_SFXLv		; uint16_t
//@ 		pop	_SFXRv		; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 586
//@ 
//@ loc_33542:				; CODE XREF: GUS_MixNextBlock+1CBj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		mul	_SFXRv		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 50h	; 'P'
//@ 		div	cx		; Unsigned Divide
//@ 		mov	_SFXRv,	ax	; uint16_t
//@ 		cmp	_SFXRv,	7Fh ; '' ; uint16_t
//@ 		jbe	short loc_33564	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	_SFXRv,	7Fh ; '' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 587
//@ 
//@ loc_33564:				; CODE XREF: GUS_MixNextBlock+1F7j
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		mul	_SFXLv		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 50h	; 'P'
//@ 		div	cx		; Unsigned Divide
//@ 		mov	_SFXLv,	ax	; uint16_t
//@ 		cmp	_SFXLv,	7Fh ; '' ; uint16_t
//@ 		jbe	short loc_33586	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	_SFXLv,	7Fh ; '' ; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 589
//@ 
//@ loc_33586:				; CODE XREF: GUS_MixNextBlock+219j
//@ 		mov	ax, SFXBufSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 591
//@ 		push	ds
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 593
//@ 		mov	cx, 400h
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		mov	bx, _SFXLv	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 594
//@ 		mov	si, _CurBlock	; uint16_t
//@ 		shl	si, 0Ah		; Shift	Logical	Left
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 595
//@ 		mov	ax, VcSeg	; uint16_t
//@ 		mov	ds, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 597
//@ 
//@ loc_335A1:				; CODE XREF: GUS_MixNextBlock+252j
//@ 		mov	al, [si]
//@ 		imul	bl		; Signed Multiply
//@ 		add	es:[di], ax	; Add
//@ 		jno	short loc_335B3	; Jump if Not Overflow (OF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 598
//@ 		shr	ax, 0Fh		; Shift	Logical	Right
//@ 		add	ax, 7FFFh	; Add
//@ 		mov	es:[di], ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 599
//@ 
//@ loc_335B3:				; CODE XREF: GUS_MixNextBlock+243j
//@ 		add	di, 2		; Add
//@ 		inc	si		; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 600
//@ 		loop	loc_335A1	; Loop while CX	!= 0
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 602
//@ 		pop	ds
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 604
//@ 		push	ds
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 606
//@ 		mov	cx, 400h
//@ 		mov	di, 800h
//@ 		mov	bx, _SFXRv	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 607
//@ 		mov	si, _CurBlock	; uint16_t
//@ 		shl	si, 0Ah		; Shift	Logical	Left
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 608
//@ 		mov	ax, VcSeg	; uint16_t
//@ 		mov	ds, ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 610
//@ 
//@ loc_335D1:				; CODE XREF: GUS_MixNextBlock+282j
//@ 		mov	al, [si]
//@ 		imul	bl		; Signed Multiply
//@ 		add	es:[di], ax	; Add
//@ 		jno	short loc_335E3	; Jump if Not Overflow (OF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 611
//@ 		shr	ax, 0Fh		; Shift	Logical	Right
//@ 		add	ax, 7FFFh	; Add
//@ 		mov	es:[di], ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 612
//@ 
//@ loc_335E3:				; CODE XREF: GUS_MixNextBlock+273j
//@ 		add	di, 2		; Add
//@ 		inc	si		; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 613
//@ 		loop	loc_335D1	; Loop while CX	!= 0
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 614
//@ 		pop	ds
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 617
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+6] ; Increment by 1
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 618
//@ 		mov	ax, es:[di+6]
//@ 		cmp	ax, es:[di+4]	; Compare Two Operands
//@ 		jb	short loc_33619	; Jump if Below	(CF=1)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 619
//@ 		cmp	SFXC, 0		; uint16_t
//@ 		jnz	short loc_3360A	; Jump if Not Zero (ZF=0)
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		jmp	short loc_33619	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 620
//@ 
//@ loc_3360A:				; CODE XREF: GUS_MixNextBlock+29Bj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+6], 0FFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 621
//@ 
//@ loc_33619:				; CODE XREF: GUS_MixNextBlock+3Dj
//@ 					; GUS_MixNextBlock+294j ...
//@ 		cmp	SFXC, 0Fh	; uint16_t
//@ 		jz	short loc_33623	; Jump if Zero (ZF=1)
//@ 		jmp	loc_33385	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 623
//@ 
//@ loc_33623:				; CODE XREF: GUS_MixNextBlock+2B9j
//@ 		push	SFXBufSeg	; uint16_t
//@ 		push	0
//@ 		push	SFXDMASeg	; uint16_t
//@ 		push	0
//@ 		push	800h
//@ 		call	movsw$0		; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 624
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ GUS_MixNextBlock endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 631
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SendBlock	proc far		; CODE XREF: GUS_StartNext+3CP
//@ 					; GUS_StartNext+B8P
//@ 
//@ control		= byte ptr  8		; uint16_t
//@ dmaofs		= word ptr  0Ah		; uint16_t
//@ lpos		= word ptr  0Ch		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 632
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 41h	; 'A'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 633
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		mov	DSPP, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 634
//@ 		push	[bp+dmaofs]	; uint16_t
//@ 		push	800h
//@ 		mov	ax, [bp+lpos]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	al, [bp+control] ; uint16_t
//@ 		push	ax
//@ 		call	UltraDMADRAM_64K ; function far	PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 635
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ SendBlock	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 638
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GUS_StartNext	proc far		; CODE XREF: GUS_IRQ_Handler+FP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 639
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	dx, ax
//@ 		in	al, dx		; DMA controller, 8237A-5.
//@ 					; channel 3 current address
//@ 		mov	DSPP, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 640
//@ 		mov	al, DSPP	; uint8_t
//@ 		and	al, 80h		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_336FE	; Jump if Zero (ZF=1)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 642
//@ 		push	0
//@ 		call	UltraReadVoice	; function far PASCAL returns unsigned int 'Word'
//@ 		mov	GUSVPos, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 643
//@ 		cmp	GUSVPos, 400h	; uint16_t
//@ 		jbe	short loc_3369C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	SFXBOfs, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 645
//@ 
//@ loc_3369C:				; CODE XREF: GUS_StartNext+28j
//@ 		mov	ax, SFXBOfs	; uint16_t
//@ 		add	ax, 1000h	; Add
//@ 		push	ax
//@ 		push	800h
//@ 		push	0
//@ 		push	bp
//@ 		call	SendBlock	; function nested far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 646
//@ 		mov	ax, 800h
//@ 		sub	ax, SFXBOfs	; uint16_t
//@ 		mov	SFXBOfs, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 648
//@ 		cmp	SFXBOfs, 0	; uint16_t
//@ 		jnz	short loc_336FC	; Jump if Not Zero (ZF=0)
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 650
//@ 		push	1
//@ 		call	UltraReadVoice	; function far PASCAL returns unsigned int 'Word'
//@ 		and	ax, 3FFh	; Logical AND
//@ 		push	ax
//@ 		push	0
//@ 		call	UltraReadVoice	; function far PASCAL returns unsigned int 'Word'
//@ 		and	ax, 3FFh	; Logical AND
//@ 		pop	dx
//@ 		add	ax, dx		; Add
//@ 		mov	GUSVPos, ax	; uint16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 652
//@ 		cmp	GUSVPos, 400h	; uint16_t
//@ 		jbe	short loc_336F0	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		push	7
//@ 		push	0
//@ 		push	43FEh
//@ 		call	UltraSetVoiceEnd ; function far	PASCAL returns void
//@ 		jmp	short loc_336FC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 653
//@ 
//@ loc_336F0:				; CODE XREF: GUS_StartNext+73j
//@ 		push	7
//@ 		push	0
//@ 		push	4402h
//@ 		call	UltraSetVoiceEnd ; function far	PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 656
//@ 
//@ loc_336FC:				; CODE XREF: GUS_StartNext+50j
//@ 					; GUS_StartNext+81j
//@ 		jmp	short locret_3372A ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 659
//@ 
//@ loc_336FE:				; CODE XREF: GUS_StartNext+16j
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 103h	; Add
//@ 		mov	dx, ax
//@ 		mov	al, 8Fh	; 'è'
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 660
//@ 		mov	ax, sBase	; uint16_t
//@ 		add	ax, 105h	; Add
//@ 		mov	dx, ax
//@ 		in	al, dx
//@ 		and	al, 1Fh		; Logical AND
//@ 		mov	DSPP, al	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 661
//@ 		call	GUS_MixNextBlock ; function far	PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 662
//@ 		push	SFXBOfs		; uint16_t
//@ 		push	0
//@ 		push	20h ; ' '
//@ 		push	bp
//@ 		call	SendBlock	; function nested far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 665
//@ 
//@ locret_3372A:				; CODE XREF: GUS_StartNext:loc_336FCj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ GUS_StartNext	endp
//@ 
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 670
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ GUS_IRQ_Handler	proc far
//@ 		pusha			; Push all General Registers
//@ 		push	ds
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 671
//@ 		mov	ax, seg	dseg11
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 672
//@ 		mov	ds, ax
//@ 		push	es
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 674
//@ 		mov	al, 20h	; ' '
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 675
//@ 		out	20h, al		; Interrupt controller,	8259A.
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 676
//@ 		out	0A0h, al	; PIC 2	 same as 0020 for PIC 1
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 677
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 679
//@ 		call	GUS_StartNext	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 681
//@ 		pop	es
//@ 		pop	ds
//@ 		popa			; Pop all General Registers
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 683
//@ 		iret			; Interrupt Return
//@ GUS_IRQ_Handler	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 684
//@ 		db 0CBh	; À
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 696
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitGUS		proc far		; CODE XREF: InitSoundSystem+97P
//@ 
//@ Temp_irq	= word ptr -4		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 697
//@ 		mov	MaxVoice, 0Fh	; uint8_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 698
//@ 		call	GUS_InitDMABuffers ; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 699
//@ 		call	UltraReset	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 700
//@ 		call	ClearGUSMemory	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 701
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+Temp_irq], ax ; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 702
//@ 		cmp	sIRQ, 7		; uint8_t
//@ 		jbe	short loc_33772	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		add	[bp+Temp_irq], 68h ; 'h' ; int16_t
//@ 		jmp	short loc_33776	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 703
//@ 
//@ loc_33772:				; CODE XREF: InitGUS+25j
//@ 		add	[bp+Temp_irq], 8 ; int16_t
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 704
//@ 
//@ loc_33776:				; CODE XREF: InitGUS+2Bj
//@ 		mov	al, byte ptr [bp+Temp_irq] ; int16_t
//@ 		push	ax
//@ 		mov	di, 1E5Ch
//@ 		mov	ax, seg	cseg09
//@ 		push	ax
//@ 		push	di
//@ 		call	@SetIntVec$q4Byte7Pointer ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 705
//@ 		mov	al, sDMA	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, sIRQ	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	UltraSetInterface ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 706
//@ 		call	EnableSFXIRQ	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 707
//@ 		mov	al, 8
//@ 		mov	dx, sBase	; uint16_t
//@ 		out	dx, al
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 710
//@ 		push	0
//@ 		push	0
//@ 		push	2B11h
//@ 		call	UltraSetFrequency ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 711
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	7FFh
//@ 		push	0
//@ 		call	UltraPrimeVoice	; function far PASCAL returns unsigned char 'Byte'
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 712
//@ 		push	0
//@ 		push	0
//@ 		call	UltraSetBalance	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 713
//@ 		push	1
//@ 		push	0
//@ 		push	2B11h
//@ 		call	UltraSetFrequency ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 714
//@ 		push	1
//@ 		push	0
//@ 		push	800h
//@ 		push	0
//@ 		push	0FFFh
//@ 		push	0
//@ 		call	UltraPrimeVoice	; function far PASCAL returns unsigned char 'Byte'
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 715
//@ 		push	1
//@ 		push	0Fh
//@ 		call	UltraSetBalance	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 716
//@ 		push	7
//@ 		push	0
//@ 		push	2B11h
//@ 		call	UltraSetFrequency ; function far PASCAL	returns	void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 717
//@ 		push	7
//@ 		push	0
//@ 		push	4000h
//@ 		push	0
//@ 		push	4400h
//@ 		push	0
//@ 		call	UltraPrimeVoice	; function far PASCAL returns unsigned char 'Byte'
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 718
//@ 		push	7
//@ 		push	7
//@ 		call	UltraSetBalance	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 719
//@ 		push	64h ; 'd'
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 720
//@ 		push	0
//@ 		push	0FFF0h
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 721
//@ 		push	1
//@ 		push	0FFF0h
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 722
//@ 		push	7
//@ 		push	0
//@ 		call	UltraSetVolume	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 724
//@ 		push	0
//@ 		push	0Ch
//@ 		call	UltraGoVoice	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 725
//@ 		push	1
//@ 		push	0Ch
//@ 		call	UltraGoVoice	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 726
//@ 		push	1A4h
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 727
//@ 		push	7
//@ 		push	28h ; '('
//@ 		call	UltraGoVoice	; function far PASCAL returns void
//@ ; #line	"SOUNDIP\SOUND_GS.PAS" 728
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitGUS		endp
//@ 
