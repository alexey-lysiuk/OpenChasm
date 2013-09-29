
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

#include "cs_demo.h"

//@ ; #line	"CS_DEMO.PAS" 54
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ExecuteEvent	proc far		; CODE XREF: LoadServerPatch+776P
//@ 					; Demo_ReadNextQuant+35DP
//@ 
//@ Cz		= word ptr  6		; int16_t
//@ Cy		= word ptr  8		; int16_t
//@ $Cx		= word ptr  0Ah		; int16_t
//@ P		= word ptr  0Ch		; int16_t
//@ info		= byte ptr  0Eh		; uint8_t
//@ C		= byte ptr  10h		; char
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 55
//@ 		mov	al, [bp+C]	; char
//@ ; #line	"CS_DEMO.PAS" 56
//@ 		cmp	al, 54h	; 'T'   ; Compare Two Operands
//@ 		jnz	short loc_11F1E	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	[bp+P]		; int16_t
//@ 		call	MakeTeleEffect	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 57
//@ 
//@ loc_11F1E:				; CODE XREF: ExecuteEvent+9j
//@ 		cmp	al, 41h	; 'A'   ; Compare Two Operands
//@ 		jnz	short loc_11F35	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		push	0FFFFh
//@ 		call	AddAmmoBag	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 58
//@ 
//@ loc_11F35:				; CODE XREF: ExecuteEvent+1Ej
//@ 		cmp	al, 45h	; 'E'   ; Compare Two Operands
//@ 		jnz	short loc_11F47	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	ExplodeMine	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 59
//@ 
//@ loc_11F47:				; CODE XREF: ExecuteEvent+35j
//@ 		cmp	al, 4Dh	; 'M'   ; Compare Two Operands
//@ 		jnz	short loc_11F5B	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	0
//@ 		call	AddMine		; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 60
//@ 
//@ loc_11F5B:				; CODE XREF: ExecuteEvent+47j
//@ 		cmp	al, 44h	; 'D'   ; Compare Two Operands
//@ 		jnz	short loc_11F6D	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		call	RemoveAmmoBag	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 61
//@ 
//@ loc_11F6D:				; CODE XREF: ExecuteEvent+5Bj
//@ 		cmp	al, 21h	; '!'   ; Compare Two Operands
//@ 		jnz	short loc_11F7F	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		call	Blow3dObjAt	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 62
//@ 
//@ loc_11F7F:				; CODE XREF: ExecuteEvent+6Dj
//@ 		cmp	al, 6Ch	; 'l'   ; Compare Two Operands
//@ 		jnz	short loc_11F9D	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	[bp+P]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 63
//@ 
//@ loc_11F9D:				; CODE XREF: ExecuteEvent+7Fj
//@ 		cmp	al, 61h	; 'a'   ; Compare Two Operands
//@ 		jnz	short loc_11FB2	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	[bp+P]		; int16_t
//@ 		call	StartProcess	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 64
//@ 
//@ loc_11FB2:				; CODE XREF: ExecuteEvent+9Dj
//@ 		cmp	al, 62h	; 'b'   ; Compare Two Operands
//@ 		jnz	short loc_11FCF	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 65
//@ 
//@ loc_11FCF:				; CODE XREF: ExecuteEvent+B2j
//@ 		cmp	al, 73h	; 's'   ; Compare Two Operands
//@ 		jnz	short loc_11FEC	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	1
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 66
//@ 
//@ loc_11FEC:				; CODE XREF: ExecuteEvent+CFj
//@ 		cmp	al, 70h	; 'p'   ; Compare Two Operands
//@ 		jnz	short loc_12026	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		mov	al, byte ptr [bp+Cz] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		push	ax
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		xchg	ax, dx		; Exchange Register/Memory with	Register
//@ 		push	ax
//@ 		push	[bp+P]		; int16_t
//@ 		mov	al, byte ptr [bp+Cz+1] ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	AddSepPart	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 67
//@ 
//@ loc_12026:				; CODE XREF: ExecuteEvent+ECj
//@ 		cmp	al, 67h	; 'g'   ; Compare Two Operands
//@ 		jnz	short loc_1203B	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		call	AddGreatBlow	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 68
//@ 
//@ loc_1203B:				; CODE XREF: ExecuteEvent+126j
//@ 		cmp	al, 47h	; 'G'   ; Compare Two Operands
//@ 		jnz	short loc_12050	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		call	AddSuperGreatBlow ; function far PASCAL	returns	void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 69
//@ 
//@ loc_12050:				; CODE XREF: ExecuteEvent+13Bj
//@ 		cmp	al, 58h	; 'X'   ; Compare Two Operands
//@ 		jnz	short loc_1206E	; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	[bp+P]		; int16_t
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		call	ExplodeMonster	; function far PASCAL returns void
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 70
//@ 
//@ loc_1206E:				; CODE XREF: ExecuteEvent+150j
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jnz	short loc_120C2	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 71
//@ 		cmp	[bp+$Cx], 0FFFFh ; int16_t
//@ 		jz	short loc_1208A	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+P]		; int16_t
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_120BF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 73
//@ 
//@ loc_1208A:				; CODE XREF: ExecuteEvent+174j
//@ 		mov	ax, [bp+Cy]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_120A3	; Jump if Not Zero (ZF=0)
//@ 		push	0FFFFh
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+P]		; int16_t
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_120BF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 74
//@ 
//@ loc_120A3:				; CODE XREF: ExecuteEvent+18Fj
//@ 		imul	di, [bp+Cy], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CS_DEMO.PAS" 75
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	[bp+P]		; int16_t
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 77
//@ 
//@ loc_120BF:				; CODE XREF: ExecuteEvent+186j
//@ 					; ExecuteEvent+19Fj
//@ 		jmp	locret_12175	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 78
//@ 
//@ loc_120C2:				; CODE XREF: ExecuteEvent+16Ej
//@ 		cmp	al, 6Bh	; 'k'   ; Compare Two Operands
//@ 		jnz	short loc_12110	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 79
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jz	short loc_120E6	; Jump if Zero (ZF=1)
//@ 		imul	ax, [bp+Cy], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+$Cx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		assume es:nothing
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	byte ptr es:[di], 0
//@ 		jmp	short loc_120FD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 80
//@ 
//@ loc_120E6:				; CODE XREF: ExecuteEvent+1C9j
//@ 		imul	ax, [bp+Cy], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+$Cx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	byte ptr es:[di], 7Ah ;	'z'
//@ ; #line	"CS_DEMO.PAS" 81
//@ 
//@ loc_120FD:				; CODE XREF: ExecuteEvent+1E2j
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_1210E	; Jump if Not Zero (ZF=0)
//@ 		mov	GShadeDir, 1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 82
//@ 
//@ loc_1210E:				; CODE XREF: ExecuteEvent+204j
//@ 		jmp	short locret_12175 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 83
//@ 
//@ loc_12110:				; CODE XREF: ExecuteEvent+1C2j
//@ 		cmp	al, 4Bh	; 'K'   ; Compare Two Operands
//@ 		jnz	short loc_1212F	; Jump if Not Zero (ZF=0)
//@ 		mov	cl, [bp+info]	; uint8_t
//@ 		imul	ax, [bp+Cy], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+$Cx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	es:[di], cl
//@ 		jmp	short locret_12175 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 84
//@ 
//@ loc_1212F:				; CODE XREF: ExecuteEvent+210j
//@ 		cmp	al, 53h	; 'S'   ; Compare Two Operands
//@ 		jnz	short loc_12163	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+info], 0	; uint8_t
//@ 		jnz	short loc_12149	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		call	BlowSmoke	; function far PASCAL returns void
//@ 		jmp	short loc_12161	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 85
//@ 
//@ loc_12149:				; CODE XREF: ExecuteEvent+235j
//@ 		push	[bp+$Cx]	; int16_t
//@ 		push	[bp+Cy]		; int16_t
//@ 		push	[bp+Cz]		; int16_t
//@ 		cmp	[bp+P],	1	; int16_t
//@ 		mov	al, 0
//@ 		jnz	short loc_1215B	; Jump if Not Zero (ZF=0)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_1215B:				; CODE XREF: ExecuteEvent+256j
//@ 		push	ax
//@ 		call	BlowShootSmoke	; function far PASCAL returns void
//@ 
//@ loc_12161:				; CODE XREF: ExecuteEvent+245j
//@ 		jmp	short locret_12175 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 86
//@ 
//@ loc_12163:				; CODE XREF: ExecuteEvent+22Fj
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jnz	short locret_12175 ; Jump if Not Zero (ZF=0)
//@ 		mov	al, [bp+info]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	[bp+P]		; int16_t
//@ 		call	SetProcMessage	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 88
//@ 
//@ locret_12175:				; CODE XREF: ExecuteEvent+19j
//@ 					; ExecuteEvent+30j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ ExecuteEvent	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 95
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Init_DemoSystem	proc near		; CODE XREF: StartDemo+4p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_DEMO.PAS" 96
//@ 		cmp	MemoActive, 0	; bool
//@ 		jnz	short loc_12199	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 98
//@ 		mov	di, offset DemoPtr ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0F000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ 		les	di, DemoPtr	; void*
//@ 		mov	ax, es
//@ 		mov	DmSeg, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 100
//@ 
//@ loc_12199:				; CODE XREF: Init_DemoSystem+8j
//@ 		mov	MemoActive, 1	; bool
//@ ; #line	"CS_DEMO.PAS" 101
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ Init_DemoSystem	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 104
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DeInit_DemoSystem proc far		; CODE XREF: DoGame+19C3P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_DEMO.PAS" 105
//@ 		cmp	MemoActive, 0	; bool
//@ 		jz	short loc_121B7	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 107
//@ 		mov	di, offset DemoPtr ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0F000h
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 109
//@ 
//@ loc_121B7:				; CODE XREF: DeInit_DemoSystem+8j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DemoOfs, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 110
//@ 		mov	MemoActive, 0	; bool
//@ ; #line	"CS_DEMO.PAS" 111
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short $+2	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 112
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ DeInit_DemoSystem endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 115
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ EndDemo		proc far		; CODE XREF: ExecConsole:loc_8EBAP
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_DEMO.PAS" 116
//@ 		mov	ax, takt	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	DemoTakts, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 117
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short locret_12241 ; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 119
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset DemoOfs ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 120
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, DemoPtr	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	DemoOfs		; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 121
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	0
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset DemoTakts ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 122
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 124
//@ 
//@ locret_12241:				; CODE XREF: EndDemo+Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ EndDemo		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_3		db 2,'@#'               ; DATA XREF: StartDemo+3Ao
//@ 					; StartDemo+A0o
//@ aChasmdatChasm_	db 16,'CHASMDAT\CHASM.R' ; DATA XREF: StartDemo+2Ao
//@ aChasm_r	db 7,'chasm.r'          ; DATA XREF: StartDemo+90o
//@ ; #line	"CS_DEMO.PAS" 129
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StartDemo	proc far		; CODE XREF: DoGame:loc_C456P
//@ 
//@ var_200		= byte ptr -200h
//@ var_100		= byte ptr -100h
//@ 
//@ 		enter	200h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 130
//@ 		call	Init_DemoSystem	; function near	PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 131
//@ 		mov	word ptr RandSeed, 5456h ; int32_t
//@ 		mov	word ptr RandSeed+2, 34h ; '4' ; int32_t
//@ ; #line	"CS_DEMO.PAS" 132
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DTakt, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 134
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jz	short loc_122DA	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 136
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasmdatChasm_ ; "CHASMDAT\\CHASM.R"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_3	; "@#"
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
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"CS_DEMO.PAS" 137
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	1
//@ 		call	@Rewrite$qm4File4Word ;	Rewrite(var f: File; recsize: Word)
//@ ; #line	"CS_DEMO.PAS" 138
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset w	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 141
//@ 
//@ loc_122DA:				; CODE XREF: StartDemo+1Dj
//@ 		cmp	PlayDemo, 0	; bool
//@ 		jnz	short loc_122E4	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_12366	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 143
//@ 
//@ loc_122E4:				; CODE XREF: StartDemo+80j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_r ; "chasm.r"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_3	; "@#"
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
//@ ; #line	"CS_DEMO.PAS" 144
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset DemoTakts ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 145
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset DBlockSize ;	uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 146
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, DemoPtr	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	DBlockSize	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 147
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DemoOfs, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 150
//@ 
//@ locret_12366:				; CODE XREF: StartDemo+82j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ StartDemo	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_4		db 2,'@#'               ; DATA XREF: GetNextDemoNumber+33o
//@ 					; GetNextDemoNumber+73o
//@ aChasm_r_0	db 7,'chasm.r'          ; DATA XREF: GetNextDemoNumber+23o
//@ 					; GetNextDemoNumber+63o
//@ ; #line	"CS_DEMO.PAS" 155
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetNextDemoNumber proc far		; CODE XREF: ExecConsole+B88P
//@ 					; PROGRAM+D18P	...
//@ 
//@ var_202		= byte ptr -202h
//@ var_102		= byte ptr -102h
//@ c		= word ptr -2		; int16_t
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 156
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+c],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 158
//@ 
//@ loc_1237C:				; CODE XREF: GetNextDemoNumber+5Bj
//@ 		inc	LevelN		; int16_t
//@ 		cmp	LevelN,	40h ; '@' ; int16_t
//@ 		jle	short loc_1238D	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	LevelN,	1	; int16_t
//@ 
//@ loc_1238D:				; CODE XREF: GetNextDemoNumber+12j
//@ 		inc	[bp+c]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 159
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_r_0 ;	"chasm.r"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_4	; "@#"
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
//@ 		call	FExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_123D0	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+c],	40h ; '@' ; int16_t
//@ 		jle	short loc_1237C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 160
//@ 
//@ loc_123D0:				; CODE XREF: GetNextDemoNumber+55j
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasm_r_0 ;	"chasm.r"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_4	; "@#"
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
//@ 		call	FExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short locret_12415 ; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 161
//@ 		mov	PlayDemo, 0	; bool
//@ 		mov	LevelN,	1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 162
//@ 
//@ locret_12415:				; CODE XREF: GetNextDemoNumber+95j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ GetNextDemoNumber endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 174
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Demo_RecordNext	proc far		; CODE XREF: DoGame+1921P
//@ 
//@ var_C		= dword	ptr -0Ch
//@ var_8		= dword	ptr -8
//@ var_4		= word ptr -4
//@ OldOfs		= word ptr -2		; uint16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 176
//@ 		mov	dx, word ptr demotime ;	int32_t
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ 		add	DemoOfs, 2	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 178
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	ax, di
//@ 		mov	dx, es
//@ 		mov	word ptr PPS, ax ; TPlayerState*
//@ 		mov	word ptr PPS+2,	dx ; TPlayerState*
//@ ; #line	"CS_DEMO.PAS" 179
//@ 		les	di, PPS		; TPlayerState*
//@ 		mov	word ptr [bp+var_8+2], di
//@ 		mov	[bp+var_4], es
//@ ; #line	"CS_DEMO.PAS" 181
//@ 		mov	ax, Players.PlHx ; struct TPlayerInfo[8]
//@ 		mov	es:[di], ax
//@ 		mov	ax, Players.PlHy ; struct TPlayerInfo[8]
//@ 		mov	es:[di+2], ax
//@ 		mov	ax, Players.PlFi ; struct TPlayerInfo[8]
//@ 		mov	es:[di+8], ax
//@ 		mov	ax, ehz		; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ 		mov	ax, LookVz	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CS_DEMO.PAS" 182
//@ 		mov	ax, Players.PFlags ; struct TPlayerInfo[8]
//@ 		and	ax, 0FFh	; Logical AND
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CS_DEMO.PAS" 183
//@ 		mov	al, byte ptr Players.PlCurGun ;	struct TPlayerInfo[8]
//@ 		mov	es:[di+4], al
//@ ; #line	"CS_DEMO.PAS" 184
//@ 		mov	di, Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		mov	al, [di-0FA9h]
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+5], al
//@ ; #line	"CS_DEMO.PAS" 185
//@ 		mov	al, Players.Armor ; struct TPlayerInfo[8]
//@ 		mov	es:[di+7], al
//@ ; #line	"CS_DEMO.PAS" 186
//@ 		mov	al, byte ptr Players.Life ; struct TPlayerInfo[8]
//@ 		mov	es:[di+6], al
//@ ; #line	"CS_DEMO.PAS" 187
//@ 		add	DemoOfs, 10h	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 191
//@ 		mov	dl, byte ptr RCount ; uint16_t
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 192
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jle	short loc_124C8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_12578	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_124C8:				; CODE XREF: Demo_RecordNext+ACj
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_124D1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_124CD:				; CODE XREF: Demo_RecordNext+15Ej
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 193
//@ 
//@ loc_124D1:				; CODE XREF: Demo_RecordNext+B4j
//@ 		imul	di, n$0, 18h	; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CS_DEMO.PAS" 195
//@ 		mov	dx, es:[di+2]
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		assume es:nothing
//@ 		mov	es:[di], dx
//@ ; #line	"CS_DEMO.PAS" 196
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+6]
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"CS_DEMO.PAS" 197
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+8]
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"CS_DEMO.PAS" 198
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	dx, es:[di+0Ah]
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dx
//@ ; #line	"CS_DEMO.PAS" 199
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	dl, es:[di+0Ch]
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CS_DEMO.PAS" 200
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	dl, es:[di+0Dh]
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 9		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CS_DEMO.PAS" 201
//@ 		add	DemoOfs, 0Ah	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 202
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short loc_12578	; Jump if Zero (ZF=1)
//@ 		jmp	loc_124CD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 205
//@ 
//@ loc_12578:				; CODE XREF: Demo_RecordNext+AEj
//@ 					; Demo_RecordNext+15Cj
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		mov	[bp+OldOfs], ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 206
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+OldOfs]	; uint16_t
//@ 		pop	es
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"CS_DEMO.PAS" 207
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 208
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_12599	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_12595:				; CODE XREF: Demo_RecordNext+1CAj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 209
//@ 
//@ loc_12599:				; CODE XREF: Demo_RecordNext+17Cj
//@ 		imul	di, n$0, 0Ah	; int16_t
//@ 		cmp	byte ptr [di-5B62h], 0 ; Compare Two Operands
//@ 		jz	short loc_125DC	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 211
//@ 		imul	di, n$0, 0Ah	; int16_t
//@ 		add	di, 0A49Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	0Ah
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CS_DEMO.PAS" 212
//@ 		add	DemoOfs, 0Ah	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 213
//@ 		imul	di, n$0, 0Ah	; int16_t
//@ 		mov	byte ptr [di-5B62h], 0
//@ ; #line	"CS_DEMO.PAS" 214
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+OldOfs]	; uint16_t
//@ 		pop	es
//@ 		inc	byte ptr es:[di] ; Increment by	1
//@ ; #line	"CS_DEMO.PAS" 215
//@ 
//@ loc_125DC:				; CODE XREF: Demo_RecordNext+18Cj
//@ 		cmp	n$0, 0Fh	; int16_t
//@ 		jnz	short loc_12595	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 218
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		mov	[bp+OldOfs], ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 219
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+OldOfs]	; uint16_t
//@ 		pop	es
//@ 		mov	byte ptr es:[di], 0
//@ ; #line	"CS_DEMO.PAS" 220
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 221
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jle	short loc_1260A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_126BE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1260A:				; CODE XREF: Demo_RecordNext+1EEj
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_12613	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1260F:				; CODE XREF: Demo_RecordNext+2A4j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 222
//@ 
//@ loc_12613:				; CODE XREF: Demo_RecordNext+1F6j
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"CS_DEMO.PAS" 223
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	byte ptr es:[di+26h], 0	; Compare Two Operands
//@ 		jz	short loc_126B3	; Jump if Zero (ZF=1)
//@ 		cmp	byte ptr es:[di+26h], 5	; Compare Two Operands
//@ 		jnz	short loc_12672	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_12672	; Jump if Less (SF!=OF)
//@ 		jg	short loc_126B3	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_126B3	; Jump if Not Below (CF=0)
//@ ; #line	"CS_DEMO.PAS" 225
//@ 
//@ loc_12672:				; CODE XREF: Demo_RecordNext+232j
//@ 					; Demo_RecordNext+253j
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+OldOfs]	; uint16_t
//@ 		pop	es
//@ 		inc	byte ptr es:[di] ; Increment by	1
//@ ; #line	"CS_DEMO.PAS" 226
//@ 		mov	dl, byte ptr n$0 ; int16_t
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 227
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	0Ch
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CS_DEMO.PAS" 228
//@ 		add	DemoOfs, 0Ch	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 229
//@ 
//@ loc_126B3:				; CODE XREF: Demo_RecordNext+22Bj
//@ 					; Demo_RecordNext+255j	...
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short loc_126BE	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1260F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 232
//@ 
//@ loc_126BE:				; CODE XREF: Demo_RecordNext+1F0j
//@ 					; Demo_RecordNext+2A2j
//@ 		cmp	DemoOfs, 3E80h	; uint16_t
//@ 		jbe	short locret_126F8 ; Jump if Below or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 234
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset DemoOfs ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 235
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, DemoPtr	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	DemoOfs		; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockWrite$qm4Filem3Any4Wordm4Word ; BlockWrite(var f:	File; var buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 236
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DemoOfs, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 238
//@ 
//@ locret_126F8:				; CODE XREF: Demo_RecordNext+2ADj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ Demo_RecordNext	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 249
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Demo_ReadNextQuant proc	near		; CODE XREF: Demo_ReadNext:loc_12EDDp
//@ 
//@ var_8		= dword	ptr -8
//@ var_4		= word ptr -4
//@ DynamCnt	= word ptr -2		; uint16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 250
//@ 		mov	ax, DTakt	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		cmp	ax, DemoTakts	; uint16_t
//@ 		jb	short loc_12718	; Jump if Below	(CF=1)
//@ ; #line	"CS_DEMO.PAS" 251
//@ 		mov	MenuCode, 4	; uint16_t
//@ 		call	GetNextDemoNumber ; function far PASCAL	returns	void
//@ 		jmp	locret_12C07	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 253
//@ 
//@ loc_12718:				; CODE XREF: Demo_ReadNextQuant+Ej
//@ 		cmp	takt, 0		; uint16_t
//@ 		jnz	short loc_12732	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr RealTime, ax ;	int32_t
//@ 		mov	word ptr RealTime+2, dx	; int32_t
//@ ; #line	"CS_DEMO.PAS" 254
//@ 
//@ loc_12732:				; CODE XREF: Demo_ReadNextQuant+23j
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	word ptr demotime, ax ;	int32_t
//@ 		mov	word ptr demotime+2, dx	; int32_t
//@ ; #line	"CS_DEMO.PAS" 255
//@ 
//@ loc_12747:				; CODE XREF: Demo_ReadNextQuant:loc_1275Cj
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		cmp	dx, word ptr demotime+2	; int32_t
//@ 		jl	short loc_1275C	; Jump if Less (SF!=OF)
//@ 		jg	short loc_1275E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, word ptr demotime ;	int32_t
//@ 		jnb	short loc_1275E	; Jump if Not Below (CF=0)
//@ 
//@ loc_1275C:				; CODE XREF: Demo_ReadNextQuant+58j
//@ 		jmp	short loc_12747	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 257
//@ 
//@ loc_1275E:				; CODE XREF: Demo_ReadNextQuant+5Aj
//@ 					; Demo_ReadNextQuant+60j
//@ 		add	DemoOfs, 2	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 258
//@ 		inc	DTakt		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 261
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	ax, di
//@ 		mov	dx, es
//@ 		mov	word ptr PPS, ax ; TPlayerState*
//@ 		mov	word ptr PPS+2,	dx ; TPlayerState*
//@ ; #line	"CS_DEMO.PAS" 262
//@ 		les	di, PPS		; TPlayerState*
//@ 		mov	word ptr [bp+var_8+2], di
//@ 		mov	[bp+var_4], es
//@ ; #line	"CS_DEMO.PAS" 264
//@ 		mov	ax, es:[di]
//@ 		mov	Players.PlHx, ax ; struct TPlayerInfo[8]
//@ 		mov	ax, es:[di+2]
//@ 		mov	Players.PlHy, ax ; struct TPlayerInfo[8]
//@ 		mov	ax, es:[di+8]
//@ 		mov	Players.PlFi, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 266
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	Players.Plhz, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 267
//@ 		mov	ax, Players.Plhz ; struct TPlayerInfo[8]
//@ 		sub	ax, 600h	; Integer Subtraction
//@ 		mov	Players.Plhz0, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 268
//@ 		mov	ax, es:[di+0Eh]
//@ 		mov	LookVz,	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 270
//@ 		mov	ax, Players.PFlags ; struct TPlayerInfo[8]
//@ 		cmp	ax, es:[di+0Ah]	; Compare Two Operands
//@ 		jz	short loc_127C6	; Jump if Zero (ZF=1)
//@ 		mov	GShadeDir, 1	; int16_t
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	Players.PFlags,	ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 271
//@ 
//@ loc_127C6:				; CODE XREF: Demo_ReadNextQuant+BDj
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di+4]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		jz	short loc_127E7	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 273
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponFTime, ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WeaponPhase, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 274
//@ 		mov	GunShift, 1	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 275
//@ 		jmp	short loc_12816	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 276
//@ 
//@ loc_127E7:				; CODE XREF: Demo_ReadNextQuant+D9j
//@ 		mov	di, Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		mov	al, [di-0FA9h]
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		cmp	al, es:[di+5]	; Compare Two Operands
//@ 		jnb	short loc_12800	; Jump if Not Below (CF=0)
//@ 		mov	GShadeDir, 1	; int16_t
//@ 		jmp	short loc_12816	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 277
//@ 
//@ loc_12800:				; CODE XREF: Demo_ReadNextQuant+FCj
//@ 		mov	di, Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		mov	al, [di-0FA9h]
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		cmp	al, es:[di+5]	; Compare Two Operands
//@ 		jbe	short loc_12816	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	WeaponActive, 1	; bool
//@ ; #line	"CS_DEMO.PAS" 279
//@ 
//@ loc_12816:				; CODE XREF: Demo_ReadNextQuant+EBj
//@ 					; Demo_ReadNextQuant+104j ...
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di+6]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, Players.Life ; struct TPlayerInfo[8]
//@ 		jge	short loc_12833	; Jump if Greater or Equal (SF=OF)
//@ 		mov	al, es:[di+6]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		call	SetMePain	; function far PASCAL returns void
//@ 		jmp	short loc_12848	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 280
//@ 
//@ loc_12833:				; CODE XREF: Demo_ReadNextQuant+129j
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di+6]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, Players.Life ; struct TPlayerInfo[8]
//@ 		jle	short loc_12848	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	GShadeDir, 1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 282
//@ 
//@ loc_12848:				; CODE XREF: Demo_ReadNextQuant+137j
//@ 					; Demo_ReadNextQuant+146j
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di+7]
//@ 		cmp	al, Players.Armor ; struct TPlayerInfo[8]
//@ 		jbe	short loc_1285B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 283
//@ 		mov	GShadeDir, 1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 285
//@ 
//@ loc_1285B:				; CODE XREF: Demo_ReadNextQuant+159j
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di+4]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Players.PlCurGun, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 286
//@ 		mov	al, es:[di+5]
//@ 		mov	di, Players.PlCurGun ; struct TPlayerInfo[8]
//@ 		mov	[di-0FA9h], al
//@ ; #line	"CS_DEMO.PAS" 287
//@ 		les	di, [bp+var_8+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di+6]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	Players.Life, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 288
//@ 		mov	al, es:[di+7]
//@ 		mov	Players.Armor, al ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 291
//@ 		add	DemoOfs, 10h	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 293
//@ 		mov	ax, Players.PlFi ; struct TPlayerInfo[8]
//@ 		mov	HFi, ax		; uint16_t
//@ 		mov	ax, Players.PlHx ; struct TPlayerInfo[8]
//@ 		mov	Hx, ax		; int16_t
//@ 		mov	ax, Players.PlHy ; struct TPlayerInfo[8]
//@ 		mov	Hy, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 294
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 295
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 296
//@ 		mov	ax, _LookVz	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, Players.Plhz ; struct TPlayerInfo[8]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	Hz, ax		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 297
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		mov	cx, 0C8h ; 'È'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 88h	; 'ˆ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4800h
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
//@ 		mov	cx, 86h	; '†'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Hz		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Hz, ax		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 302
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	RCount,	ax	; uint16_t
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 303
//@ 		mov	ax, RCount	; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jle	short loc_12949	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_129FC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_12949:				; CODE XREF: Demo_ReadNextQuant+24Aj
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_12952	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1294E:				; CODE XREF: Demo_ReadNextQuant+2FFj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 304
//@ 
//@ loc_12952:				; CODE XREF: Demo_ReadNextQuant+252j
//@ 		imul	di, n$0, 18h	; int16_t
//@ 		add	di, 0B33Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CS_DEMO.PAS" 306
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 0		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ ; #line	"CS_DEMO.PAS" 307
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 308
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ ; #line	"CS_DEMO.PAS" 309
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CS_DEMO.PAS" 310
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 8		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], al
//@ ; #line	"CS_DEMO.PAS" 311
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		add	ax, 9		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Dh], al
//@ ; #line	"CS_DEMO.PAS" 312
//@ 		add	DemoOfs, 0Ah	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 313
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short loc_129FC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1294E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 316
//@ 
//@ loc_129FC:				; CODE XREF: Demo_ReadNextQuant+24Cj
//@ 					; Demo_ReadNextQuant+2FDj
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+DynamCnt], ax ; uint16_t
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 317
//@ 		mov	ax, [bp+DynamCnt] ; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jg	short loc_12A69	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_12A28	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_12A24:				; CODE XREF: Demo_ReadNextQuant+36Dj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 319
//@ 
//@ loc_12A28:				; CODE XREF: Demo_ReadNextQuant+328j
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset DEvent ; struct TEvent
//@ 		push	ds
//@ 		push	di
//@ 		push	0Ah
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CS_DEMO.PAS" 320
//@ 		mov	al, DEvent.C	; struct TEvent
//@ 		push	ax
//@ 		mov	al, DEvent.info	; struct TEvent
//@ 		push	ax
//@ 		push	DEvent.param	; struct TEvent
//@ 		push	DEvent.$CX	; struct TEvent
//@ 		push	DEvent.CY	; struct TEvent
//@ 		push	DEvent.CZ	; struct TEvent
//@ 		call	ExecuteEvent	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 321
//@ 		add	DemoOfs, 0Ah	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 322
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jnz	short loc_12A24	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 325
//@ 
//@ loc_12A69:				; CODE XREF: Demo_ReadNextQuant+323j
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+DynamCnt], ax ; uint16_t
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 326
//@ 		mov	ax, [bp+DynamCnt] ; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jle	short loc_12A8F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_12BCC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_12A8F:				; CODE XREF: Demo_ReadNextQuant+390j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_12A98	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_12A94:				; CODE XREF: Demo_ReadNextQuant+4CFj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 328
//@ 
//@ loc_12A98:				; CODE XREF: Demo_ReadNextQuant+398j
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	j, ax		; uint16_t
//@ 		inc	DemoOfs		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 329
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset M	; struct TMonster
//@ 		push	ds
//@ 		push	di
//@ 		push	0Ch
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CS_DEMO.PAS" 331
//@ 		cmp	M.DamageMode, 0FFh ; struct TMonster
//@ 		jnz	short loc_12ACE	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_12B89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 332
//@ 
//@ loc_12ACE:				; CODE XREF: Demo_ReadNextQuant+3CFj
//@ 		cmp	M.Phase, 0Ah	; struct TMonster
//@ 		jnz	short loc_12AFF	; Jump if Not Zero (ZF=0)
//@ 		imul	di, j, 28h	; uint16_t
//@ 		cmp	word ptr [di-5ADAh], 0Ah ; Compare Two Operands
//@ 		jz	short loc_12AFF	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 333
//@ 		push	0FFFFh
//@ 		push	M.Mx		; struct TMonster
//@ 		push	M.My		; struct TMonster
//@ 		mov	al, M.MType	; struct TMonster
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0BCh ; '¼'  ; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	loc_12B89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 335
//@ 
//@ loc_12AFF:				; CODE XREF: Demo_ReadNextQuant+3D9j
//@ 					; Demo_ReadNextQuant+3E5j
//@ 		cmp	M.Phase, 10h	; struct TMonster
//@ 		jl	short loc_12B2F	; Jump if Less (SF!=OF)
//@ 		imul	di, j, 28h	; uint16_t
//@ 		cmp	word ptr [di-5ADAh], 10h ; Compare Two Operands
//@ 		jge	short loc_12B2F	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 336
//@ 		push	0FFFFh
//@ 		push	M.Mx		; struct TMonster
//@ 		push	M.My		; struct TMonster
//@ 		mov	al, M.MType	; struct TMonster
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0E8h ; 'è'  ; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_12B89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 338
//@ 
//@ loc_12B2F:				; CODE XREF: Demo_ReadNextQuant+40Aj
//@ 					; Demo_ReadNextQuant+416j
//@ 		imul	di, j, 28h	; uint16_t
//@ 		mov	al, [di-5AD7h]
//@ 		and	al, 7		; Logical AND
//@ 		mov	dl, al
//@ 		mov	al, M.DamageMode ; struct TMonster
//@ 		and	al, 7		; Logical AND
//@ 		cmp	al, dl		; Compare Two Operands
//@ 		jz	short loc_12B62	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 339
//@ 		push	0FFFFh
//@ 		push	M.Mx		; struct TMonster
//@ 		push	M.My		; struct TMonster
//@ 		mov	al, M.MType	; struct TMonster
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0D2h ; 'Ò'  ; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_12B89	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 341
//@ 
//@ loc_12B62:				; CODE XREF: Demo_ReadNextQuant+449j
//@ 		imul	di, j, 28h	; uint16_t
//@ 		cmp	byte ptr [di-5ABCh], 0 ; Compare Two Operands
//@ 		jnz	short loc_12B89	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 342
//@ 		push	0FFFFh
//@ 		push	M.Mx		; struct TMonster
//@ 		push	M.My		; struct TMonster
//@ 		mov	al, M.MType	; struct TMonster
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 344
//@ 
//@ loc_12B89:				; CODE XREF: Demo_ReadNextQuant+3D1j
//@ 					; Demo_ReadNextQuant+402j ...
//@ 		mov	di, offset M	; struct TMonster
//@ 		push	ds
//@ 		push	di
//@ 		imul	di, j, 28h	; uint16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	0Ch
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CS_DEMO.PAS" 345
//@ 		cmp	M.Phase, 10h	; struct TMonster
//@ 		jl	short loc_12BB2	; Jump if Less (SF!=OF)
//@ 		imul	di, j, 28h	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di-5AD0h], ax
//@ ; #line	"CS_DEMO.PAS" 346
//@ 
//@ loc_12BB2:				; CODE XREF: Demo_ReadNextQuant+4ABj
//@ 		imul	di, j, 28h	; uint16_t
//@ 		mov	byte ptr [di-5ABCh], 1
//@ ; #line	"CS_DEMO.PAS" 347
//@ 		add	DemoOfs, 0Ch	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 348
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jz	short loc_12BCC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_12A94	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 350
//@ 
//@ loc_12BCC:				; CODE XREF: Demo_ReadNextQuant+392j
//@ 					; Demo_ReadNextQuant+4CDj
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		cmp	ax, DBlockSize	; uint16_t
//@ 		jb	short locret_12C07 ; Jump if Below (CF=1)
//@ ; #line	"CS_DEMO.PAS" 352
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset DBlockSize ;	uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 353
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, DemoPtr	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	DBlockSize	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CS_DEMO.PAS" 354
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	DemoOfs, ax	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 356
//@ 
//@ locret_12C07:				; CODE XREF: Demo_ReadNextQuant+1Bj
//@ 					; Demo_ReadNextQuant+4D9j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ Demo_ReadNextQuant endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 361
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CorrectPlayerPos proc near		; CODE XREF: Demo_ReadNext+30p
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= word ptr -0Ah
//@ T		= word ptr -8		; int16_t
//@ dt		= word ptr -6		; int16_t
//@ var_4		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 362
//@ 		mov	[bp+n],	1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 363
//@ 
//@ loc_12C12:				; CODE XREF: CorrectPlayerPos+40j
//@ 					; CorrectPlayerPos+62j
//@ 		mov	ax, MnCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_12C29	; Jump if Less (SF!=OF)
//@ 		jg	short loc_12C6D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		ja	short loc_12C6D	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_12C29:				; CODE XREF: CorrectPlayerPos+18j
//@ 		imul	di, [bp+n], 0Ah	; int16_t
//@ 		add	di, 0BC0Ch	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E+2], di
//@ 		mov	[bp+var_A], es
//@ ; #line	"CS_DEMO.PAS" 365
//@ 		cmp	word ptr es:[di+4], 418h ; Compare Two Operands
//@ 		jle	short loc_12C4B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		push	[bp+n]		; int16_t
//@ 		call	ExplodeMine	; function far PASCAL returns void
//@ 		jmp	short loc_12C12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 366
//@ 
//@ loc_12C4B:				; CODE XREF: CorrectPlayerPos+36j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		cmp	word ptr es:[di+4], 118h ; Compare Two Operands
//@ 		jl	short loc_12C5E	; Jump if Less (SF!=OF)
//@ 		cmp	word ptr es:[di+4], 400h ; Compare Two Operands
//@ 		jl	short loc_12C68	; Jump if Less (SF!=OF)
//@ 
//@ loc_12C5E:				; CODE XREF: CorrectPlayerPos+4Bj
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		add	es:[di+4], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 367
//@ 
//@ loc_12C68:				; CODE XREF: CorrectPlayerPos+53j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 368
//@ 		jmp	short loc_12C12	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 370
//@ 
//@ loc_12C6D:				; CODE XREF: CorrectPlayerPos+1Aj
//@ 					; CorrectPlayerPos+1Ej
//@ 		cmp	Spline,	0	; bool
//@ 		jnz	short loc_12C77	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_12ED8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 372
//@ 
//@ loc_12C77:				; CODE XREF: CorrectPlayerPos+69j
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jle	short loc_12C88	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_12D4E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_12C88:				; CODE XREF: CorrectPlayerPos+7Aj
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_12C90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_12C8D:				; CODE XREF: CorrectPlayerPos+142j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 373
//@ 
//@ loc_12C90:				; CODE XREF: CorrectPlayerPos+82j
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"CS_DEMO.PAS" 374
//@ 		cmp	word ptr es:[di+8], 10h	; Compare Two Operands
//@ 		jz	short loc_12CB1	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+8], 11h	; Compare Two Operands
//@ 		jz	short loc_12CB1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_12D43	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 375
//@ 
//@ loc_12CB1:				; CODE XREF: CorrectPlayerPos+9Cj
//@ 					; CorrectPlayerPos+A3j
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, dx		; Add
//@ 		mov	ax, [di-7FD8h]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, 8		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_12CE7	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_12D43	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_12D43	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 377
//@ 
//@ loc_12CE7:				; CODE XREF: CorrectPlayerPos+D6j
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 378
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, dx		; Add
//@ 		mov	ax, [di-7FD8h]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_12D21	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_12D43	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_12D43	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 379
//@ 
//@ loc_12D21:				; CODE XREF: CorrectPlayerPos+110j
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, dx		; Add
//@ 		mov	ax, [di-7FD8h]
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 380
//@ 
//@ loc_12D43:				; CODE XREF: CorrectPlayerPos+A5j
//@ 					; CorrectPlayerPos+D8j	...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jz	short loc_12D4E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_12C8D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 388
//@ 
//@ loc_12D4E:				; CODE XREF: CorrectPlayerPos+7Cj
//@ 					; CorrectPlayerPos+140j
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, word ptr demotime ;	int32_t
//@ 		sbb	dx, word ptr demotime+2	; int32_t
//@ 		mov	[bp+T],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 389
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		sub	ax, word ptr demotime ;	int32_t
//@ 		sbb	dx, word ptr demotime+2	; int32_t
//@ 		mov	[bp+dt], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 391
//@ 		cmp	[bp+dt], 0	; int16_t
//@ 		jg	short loc_12D82	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	locret_12ED8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 392
//@ 
//@ loc_12D82:				; CODE XREF: CorrectPlayerPos+174j
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cmp	ax, [bp+T]	; int16_t
//@ 		jle	short loc_12D90	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+T]	; int16_t
//@ 		mov	[bp+dt], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 393
//@ 
//@ loc_12D90:				; CODE XREF: CorrectPlayerPos+17Fj
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, DemoOfs	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	ax, di
//@ 		mov	dx, es
//@ 		mov	word ptr PPS, ax ; TPlayerState*
//@ 		mov	word ptr PPS+2,	dx ; TPlayerState*
//@ ; #line	"CS_DEMO.PAS" 394
//@ 		les	di, PPS		; TPlayerState*
//@ 		mov	word ptr [bp+var_E+2], di
//@ 		mov	[bp+var_A], es
//@ ; #line	"CS_DEMO.PAS" 396
//@ 		mov	ax, es:[di]
//@ 		sub	ax, Players.PlHx ; struct TPlayerInfo[8]
//@ 		mul	[bp+dt]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+T]		; int16_t
//@ 		add	Players.PlHx, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 397
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, Players.PlHy ; struct TPlayerInfo[8]
//@ 		mul	[bp+dt]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+T]		; int16_t
//@ 		add	Players.PlHy, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 398
//@ 		mov	ax, es:[di+8]
//@ 		mov	[bp+var_4], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 399
//@ 		mov	ax, Players.PlFi ; struct TPlayerInfo[8]
//@ 		sub	[bp+var_4], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 401
//@ 		mov	ax, [bp+var_4]	; int16_t
//@ 		mul	[bp+dt]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+T]		; int16_t
//@ 		add	Players.PlFi, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 402
//@ 		mov	ax, [bp+T]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, Players.Plhz ; struct TPlayerInfo[8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+0Ch]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+dt]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		add	Players.Plhz, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 403
//@ 		mov	ax, Players.Plhz ; struct TPlayerInfo[8]
//@ 		sub	ax, 600h	; Integer Subtraction
//@ 		mov	Players.Plhz0, ax ; struct TPlayerInfo[8]
//@ ; #line	"CS_DEMO.PAS" 404
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		sub	ax, LookVz	; int16_t
//@ 		mul	[bp+dt]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+T]		; int16_t
//@ 		add	LookVz,	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 406
//@ 		mov	ax, Players.PlFi ; struct TPlayerInfo[8]
//@ 		mov	HFi, ax		; uint16_t
//@ 		mov	ax, Players.PlHx ; struct TPlayerInfo[8]
//@ 		mov	Hx, ax		; int16_t
//@ 		mov	ax, Players.PlHy ; struct TPlayerInfo[8]
//@ 		mov	Hy, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 407
//@ 		push	0
//@ 		call	CalcDir		; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 408
//@ 		call	ReInitViewConst	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 409
//@ 		mov	ax, _LookVz	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, Players.Plhz ; struct TPlayerInfo[8]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	Hz, ax		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 410
//@ 		mov	ax, word ptr RealTime ;	int32_t
//@ 		mov	dx, word ptr RealTime+2	; int32_t
//@ 		mov	cx, 0C8h ; 'È'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 88h	; 'ˆ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4800h
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
//@ 		mov	cx, 86h	; '†'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, Hz		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	Hz, ax		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 412
//@ 
//@ locret_12ED8:				; CODE XREF: CorrectPlayerPos+6Bj
//@ 					; CorrectPlayerPos+176j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ CorrectPlayerPos endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 415
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Demo_ReadNext	proc far		; CODE XREF: DoGame+3D5P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_DEMO.PAS" 417
//@ 
//@ loc_12EDD:				; CODE XREF: Demo_ReadNext+27j
//@ 		call	Demo_ReadNextQuant ; function near PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 418
//@ 		mov	ax, DmSeg	; uint16_t
//@ 		push	ax
//@ 		mov	di, DemoOfs	; uint16_t
//@ 		pop	es
//@ 		mov	ax, es:[di]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, word ptr RealTime+2	; int32_t
//@ 		jg	short loc_12F03	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_12EFC	; Jump if Less (SF!=OF)
//@ 		cmp	ax, word ptr RealTime ;	int32_t
//@ 		ja	short loc_12F03	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_12EFC:				; CODE XREF: Demo_ReadNext+1Aj
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		jbe	short loc_12EDD	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 419
//@ 
//@ loc_12F03:				; CODE XREF: Demo_ReadNext+18j
//@ 					; Demo_ReadNext+20j
//@ 		cmp	MenuCode, 0	; uint16_t
//@ 		jnz	short locret_12F0D ; Jump if Not Zero (ZF=0)
//@ 		call	CorrectPlayerPos ; function near PASCAL	returns	void
//@ ; #line	"CS_DEMO.PAS" 420
//@ 
//@ locret_12F0D:				; CODE XREF: Demo_ReadNext+2Ej
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ Demo_ReadNext	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 431
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo		proc near		; CODE XREF: Rocket_WallCheck+112p
//@ 					; Rocket_WallCheck+15Cp
//@ 
//@ var_12		= byte ptr -12h
//@ L		= word ptr -0Ch		; struct TLoc
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
//@ ; #line	"CS_DEMO.PAS" 433
//@ 		mov	ax, [bp+var_5]
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ 		mov	LWx, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 434
//@ 		mov	ax, [bp+var_3]
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ 		mov	LWy, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 435
//@ 		mov	ax, LWx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLwx, ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 436
//@ 		mov	ax, LWy		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	aLWy, ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 437
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
//@ 		jl	short loc_12F78	; Jump if Less (SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 438
//@ 		mov	Ry, 400h	; int16_t
//@ 		jmp	short loc_12FA7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 439
//@ 
//@ loc_12F78:				; CODE XREF: TryToGo+5Fj
//@ 		cmp	LWy, 0		; int16_t
//@ 		jnz	short loc_12F8B	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_7]
//@ 		sub	ax, rry		; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ 		jmp	short loc_12FA7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 441
//@ 
//@ loc_12F8B:				; CODE XREF: TryToGo+6Ej
//@ 		mov	ax, rrx		; int16_t
//@ 		sub	ax, [bp+var_9]	; Integer Subtraction
//@ ; #line	"CS_DEMO.PAS" 442
//@ 		mov	bx, LWy		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWx		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_DEMO.PAS" 443
//@ 		add	ax, [bp+var_7]	; Add
//@ 		sub	ax, rry		; int16_t
//@ 		mov	Ry, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 446
//@ 
//@ loc_12FA7:				; CODE XREF: TryToGo+67j TryToGo+7Aj
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
//@ 		jl	short loc_12FD0	; Jump if Less (SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 447
//@ 		mov	Rx, 400h	; int16_t
//@ 		jmp	short loc_12FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 448
//@ 
//@ loc_12FD0:				; CODE XREF: TryToGo+B7j
//@ 		cmp	LWx, 0		; int16_t
//@ 		jnz	short loc_12FE3	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+var_9]
//@ 		sub	ax, rrx		; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ 		jmp	short loc_12FFF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 450
//@ 
//@ loc_12FE3:				; CODE XREF: TryToGo+C6j
//@ 		mov	ax, rry		; int16_t
//@ 		sub	ax, [bp+var_7]	; Integer Subtraction
//@ ; #line	"CS_DEMO.PAS" 451
//@ 		mov	bx, LWx		; int16_t
//@ 		imul	bx		; Signed Multiply
//@ 		mov	bx, LWy		; int16_t
//@ 		idiv	bx		; Signed Divide
//@ ; #line	"CS_DEMO.PAS" 452
//@ 		add	ax, [bp+var_9]	; Add
//@ 		sub	ax, rrx		; int16_t
//@ 		mov	Rx, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 455
//@ 
//@ loc_12FFF:				; CODE XREF: TryToGo+BFj TryToGo+D2j
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
//@ ; #line	"CS_DEMO.PAS" 456
//@ 		mov	ax, R$1		; int16_t
//@ 		cmp	ax, [bp+FR]	; int16_t
//@ 		jge	short locret_13038 ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 457
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_12],	1
//@ 		push	word ptr ss:[di-0Ah]
//@ 		push	ss:[di+L]	; struct TLoc
//@ 		push	0
//@ 		call	CheckSwitchShoot ; function far	PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 459
//@ 
//@ locret_13038:				; CODE XREF: TryToGo+110j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGo		endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 464
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ TryToGo2B	proc near		; CODE XREF: Rocket_WallCheck+128p
//@ 					; Rocket_WallCheck+16Ep ...
//@ 
//@ var_12		= byte ptr -12h
//@ var_C		= word ptr -0Ch
//@ var_A		= word ptr -0Ah
//@ ay		= word ptr -4		; int16_t
//@ $ax		= word ptr -2		; int16_t
//@ arg_0		= word ptr  4
//@ Fr		= word ptr  6		; int16_t
//@ y2		= word ptr  8		; int16_t
//@ x2		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 465
//@ 		cmp	[bp+Fr], 0Ah	; int16_t
//@ 		jg	short loc_13048	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	short locret_1308B ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 466
//@ 
//@ loc_13048:				; CODE XREF: TryToGo2B+8j
//@ 		mov	ax, rrx		; int16_t
//@ 		sub	ax, [bp+x2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+$ax], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 467
//@ 		mov	ax, rry		; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ay], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 468
//@ 		push	[bp+ay]		; int16_t
//@ 		push	[bp+$ax]	; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, [bp+Fr]	; int16_t
//@ 		jge	short locret_1308B ; Jump if Greater or	Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 469
//@ 		mov	di, [bp+arg_0]
//@ 		mov	ss:[di+var_12],	1
//@ 		push	ss:[di+var_A]
//@ 		push	ss:[di+var_C]
//@ 		push	0
//@ 		call	CheckSwitchShoot ; function far	PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 470
//@ 
//@ locret_1308B:				; CODE XREF: TryToGo2B+Aj
//@ 					; TryToGo2B+36j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TryToGo2B	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 473
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ Rocket_WallCheck proc far		; CODE XREF: MoveRocket+EAP
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
//@ oz		= word ptr -4		; int16_t
//@ Rocket_WallCheck= byte ptr -1		; bool
//@ FCheck		= byte ptr  6		; bool
//@ fr		= word ptr  8		; int16_t
//@ h		= word ptr  0Ah		; int16_t
//@ _rrz		= word ptr  0Ch		; int16_t
//@ _rry		= word ptr  0Eh		; int16_t
//@ _rrx		= word ptr  10h		; int16_t
//@ 
//@ 		enter	1Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 474
//@ 		mov	[bp+blow], 0	; bool
//@ 		mov	ax, [bp+_rrx]	; int16_t
//@ 		mov	rrx, ax		; int16_t
//@ 		mov	ax, [bp+_rry]	; int16_t
//@ 		mov	rry, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 475
//@ 		mov	al, byte ptr rrx+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+rmx], ax	; int16_t
//@ 		mov	al, byte ptr rry+1 ; int16_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+rmy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 476
//@ 		mov	ax, [bp+rmx]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_14], ax
//@ 		mov	ax, [bp+rmx]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jle	short loc_130C8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1329F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_130C8:				; CODE XREF: Rocket_WallCheck+34j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_130D0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_130CD:				; CODE XREF: Rocket_WallCheck+20Dj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_130D0:				; CODE XREF: Rocket_WallCheck+3Cj
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jge	short loc_130D9	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_13294	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_130D9:				; CODE XREF: Rocket_WallCheck+45j
//@ 		cmp	[bp+n],	40h ; '@' ; int16_t
//@ 		jl	short loc_130E2	; Jump if Less (SF!=OF)
//@ 		jmp	loc_13294	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 477
//@ 
//@ loc_130E2:				; CODE XREF: Rocket_WallCheck+4Ej
//@ 		mov	ax, [bp+rmy]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+var_16], ax
//@ 		mov	ax, [bp+rmy]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+var_16]	; Compare Two Operands
//@ 		jle	short loc_130F7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_13294	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_130F7:				; CODE XREF: Rocket_WallCheck+63j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_130FF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_130FC:				; CODE XREF: Rocket_WallCheck+202j
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_130FF:				; CODE XREF: Rocket_WallCheck+6Bj
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jge	short loc_13108	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_13289	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13108:				; CODE XREF: Rocket_WallCheck+74j
//@ 		cmp	[bp+i],	40h ; '@' ; int16_t
//@ 		jl	short loc_13111	; Jump if Less (SF!=OF)
//@ 		jmp	loc_13289	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 478
//@ 
//@ loc_13111:				; CODE XREF: Rocket_WallCheck+7Dj
//@ 		imul	ax, [bp+i], 0Bh	; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CS_DEMO.PAS" 480
//@ 		mov	al, es:[di]
//@ ; #line	"CS_DEMO.PAS" 481
//@ 		cmp	al, 56h	; 'V'   ; Compare Two Operands
//@ 		jnb	short loc_13134	; Jump if Not Below (CF=0)
//@ 		jmp	loc_131BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13134:				; CODE XREF: Rocket_WallCheck+A0j
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		jbe	short loc_1313B	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_131BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1313B:				; CODE XREF: Rocket_WallCheck+A7j
//@ 		cmp	[bp+FCheck], 0	; bool
//@ 		jnz	short loc_13152	; Jump if Not Zero (ZF=0)
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_131BA	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 482
//@ 
//@ loc_13152:				; CODE XREF: Rocket_WallCheck+B0j
//@ 		cmp	[bp+_rrz], 1040h ; int16_t
//@ 		jge	short loc_131BA	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 483
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		mov	al, [di+71A1h]
//@ 		and	al, 1		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_131BA	; Jump if Zero (ZF=1)
//@ 		mov	dx, [bp+i]	; int16_t
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, Flags	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 50h ;	'P' ; Compare Two Operands
//@ 		jnb	short loc_131BA	; Jump if Not Below (CF=0)
//@ ; #line	"CS_DEMO.PAS" 485
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
//@ 		call	TryToGo		; function nested near PASCAL returns void
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	ax, [bp+fr]	; int16_t
//@ 		add	ax, 18h		; Add
//@ 		push	ax
//@ 		push	bp
//@ 		call	TryToGo2B	; function nested near PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 486
//@ 
//@ loc_131BA:				; CODE XREF: Rocket_WallCheck+C1j
//@ 					; Rocket_WallCheck+C8j	...
//@ 		jmp	loc_1327D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 487
//@ 
//@ loc_131BD:				; CODE XREF: Rocket_WallCheck+A2j
//@ 					; Rocket_WallCheck+A9j
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_13202	; Jump if Below	(CF=1)
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		ja	short loc_13202	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	[bp+_rrz], 1040h ; int16_t
//@ 		jge	short loc_13200	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 489
//@ 		mov	al, [bp+blow]	; bool
//@ 		mov	[bp+b],	al	; bool
//@ ; #line	"CS_DEMO.PAS" 490
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
//@ 		call	TryToGo		; function nested near PASCAL returns void
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		push	[bp+fr]		; int16_t
//@ 		push	bp
//@ 		call	TryToGo2B	; function nested near PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 491
//@ 
//@ loc_13200:				; CODE XREF: Rocket_WallCheck+13Bj
//@ 		jmp	short loc_1327D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 492
//@ 
//@ loc_13202:				; CODE XREF: Rocket_WallCheck+130j
//@ 					; Rocket_WallCheck+134j
//@ 		cmp	al, 83h	; 'ƒ'   ; Compare Two Operands
//@ 		jb	short loc_1327D	; Jump if Below	(CF=1)
//@ 		cmp	al, 0E2h ; 'â'  ; Compare Two Operands
//@ 		ja	short loc_1327D	; Jump if Above	(CF=0 &	ZF=0)
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
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
//@ ; #line	"CS_DEMO.PAS" 494
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+2]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+oz], ax	; int16_t
//@ 		mov	ax, [bp+oz]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+oz], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 495
//@ 		mov	ax, [bp+_rrz]	; int16_t
//@ 		add	ax, [bp+h]	; int16_t
//@ 		mov	dx, ax
//@ 		les	di, [bp+var_1E]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+12h]
//@ 		add	ax, [bp+oz]	; int16_t
//@ 		cmp	ax, dx		; Compare Two Operands
//@ 		jg	short loc_1327D	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, es:[di+14h]
//@ 		add	ax, [bp+oz]	; int16_t
//@ 		cmp	ax, [bp+_rrz]	; int16_t
//@ 		jl	short loc_1327D	; Jump if Less (SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 496
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+3]
//@ 		push	word ptr es:[di+5]
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 83h	; 'ƒ'   ; Integer Subtraction
//@ 		imul	di, ax,	24h	; Signed Multiply
//@ 		mov	ax, [di+74AEh]
//@ 		add	ax, 0Ah		; Add
//@ 		push	ax
//@ 		push	bp
//@ 		call	TryToGo2B	; function nested near PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 499
//@ 
//@ loc_1327D:				; CODE XREF: Rocket_WallCheck:loc_131BAj
//@ 					; Rocket_WallCheck:loc_13200j ...
//@ 		cmp	[bp+blow], 0	; bool
//@ 		jz	short loc_13289	; Jump if Zero (ZF=1)
//@ 		mov	[bp+Rocket_WallCheck], 1 ; bool
//@ 		jmp	short loc_132A3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 500
//@ 
//@ loc_13289:				; CODE XREF: Rocket_WallCheck+76j
//@ 					; Rocket_WallCheck+7Fj	...
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_16]	; Compare Two Operands
//@ 		jz	short loc_13294	; Jump if Zero (ZF=1)
//@ 		jmp	loc_130FC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13294:				; CODE XREF: Rocket_WallCheck+47j
//@ 					; Rocket_WallCheck+50j	...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jz	short loc_1329F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_130CD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 501
//@ 
//@ loc_1329F:				; CODE XREF: Rocket_WallCheck+36j
//@ 					; Rocket_WallCheck+20Bj
//@ 		mov	[bp+Rocket_WallCheck], 0 ; bool
//@ ; #line	"CS_DEMO.PAS" 502
//@ 
//@ loc_132A3:				; CODE XREF: Rocket_WallCheck+1F8j
//@ 		mov	al, [bp+Rocket_WallCheck] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ Rocket_WallCheck endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 549
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL varargs returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ GetTarget	proc near		; CODE XREF: AnimateMonsters+182p
//@ 					; AnimateMonsters+178Dp
//@ 
//@ var_18		= dword	ptr -18h
//@ var_14		= word ptr -14h
//@ PFire		= byte ptr -11h		; bool
//@ py		= word ptr -10h		; int16_t
//@ px		= word ptr -0Eh		; int16_t
//@ vy		= word ptr -0Ch		; int16_t
//@ vx		= word ptr -0Ah		; int16_t
//@ rmin		= word ptr -8		; int16_t
//@ r		= word ptr -6		; int16_t
//@ i		= word ptr -4		; int16_t
//@ GetTarget	= byte ptr -1		; bool
//@ t		= dword	ptr  4		; int16_t
//@ _MType		= word ptr  8		; int16_t
//@ _fi		= word ptr  0Ah		; uint16_t
//@ _my		= word ptr  0Ch		; int16_t
//@ _mx		= word ptr  0Eh		; int16_t
//@ 
//@ 		enter	18h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 550
//@ 		mov	[bp+GetTarget],	0 ; bool
//@ ; #line	"CS_DEMO.PAS" 551
//@ 		mov	[bp+rmin], 0FFFFh ; int16_t
//@ ; #line	"CS_DEMO.PAS" 552
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_132C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_132BE:				; CODE XREF: GetTarget+18Aj
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 553
//@ 
//@ loc_132C1:				; CODE XREF: GetTarget+12j
//@ 		imul	di, [bp+i], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_18+2],	di
//@ 		mov	[bp+var_14], es
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_132DA	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1342E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_132DA:				; CODE XREF: GetTarget+2Bj
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_132E4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1342E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 555
//@ 
//@ loc_132E4:				; CODE XREF: GetTarget+35j
//@ 		mov	[bp+rmin], 1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 556
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 4000h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		mov	al, 0
//@ 		jz	short loc_132F7	; Jump if Zero (ZF=1)
//@ 		inc	ax		; Increment by 1
//@ 
//@ loc_132F7:				; CODE XREF: GetTarget+4Aj
//@ 		mov	[bp+PFire], al	; bool
//@ ; #line	"CS_DEMO.PAS" 558
//@ 		cmp	[bp+_fi], 0FFFFh ; uint16_t
//@ 		jnz	short loc_13303	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1339A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 559
//@ 
//@ loc_13303:				; CODE XREF: GetTarget+54j
//@ 		cmp	[bp+PFire], 0	; bool
//@ 		jz	short loc_1330C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1339A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 560
//@ 
//@ loc_1330C:				; CODE XREF: GetTarget+5Dj
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+_mx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 1CCh	; Compare Two Operands
//@ 		jg	short loc_1332E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+_my]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 1CCh	; Compare Two Operands
//@ 		jle	short loc_1339A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 562
//@ 
//@ loc_1332E:				; CODE XREF: GetTarget+71j
//@ 		mov	ax, [bp+_fi]	; uint16_t
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+vx], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 563
//@ 		mov	di, [bp+_fi]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+vy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 564
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	[bp+px], ax	; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	[bp+py], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 566
//@ 		mov	ax, [bp+px]	; int16_t
//@ 		sub	ax, [bp+_mx]	; int16_t
//@ 		imul	[bp+vx]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 567
//@ 		mov	cx, dx
//@ 		mov	bx, ax
//@ 		mov	[bp+px], 0	; int16_t
//@ ; #line	"CS_DEMO.PAS" 568
//@ 		mov	ax, [bp+py]	; int16_t
//@ 		sub	ax, [bp+_my]	; int16_t
//@ 		imul	[bp+vy]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 569
//@ 		add	bx, ax		; Add
//@ 		adc	cx, dx		; Add with Carry
//@ 		jns	short loc_13391	; Jump if Not Sign (SF=0)
//@ 		mov	[bp+px], 1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 572
//@ 
//@ loc_13391:				; CODE XREF: GetTarget+E0j
//@ 		cmp	[bp+px], 1	; int16_t
//@ 		jnz	short loc_1339A	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1342E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 576
//@ 
//@ loc_1339A:				; CODE XREF: GetTarget+56j
//@ 					; GetTarget+5Fj ...
//@ 		cmp	[bp+PFire], 0	; bool
//@ 		jz	short loc_133A7	; Jump if Zero (ZF=1)
//@ 		mov	[bp+r],	18h	; int16_t
//@ 		jmp	short loc_133F0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 577
//@ 
//@ loc_133A7:				; CODE XREF: GetTarget+F4j
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_133BC	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	[bp+r],	2	; int16_t
//@ 		jmp	short loc_133F0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 579
//@ 
//@ loc_133BC:				; CODE XREF: GetTarget+109j
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		call	GetBrightAt	; function far PASCAL returns unsigned char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+r],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 580
//@ 		cmp	[bp+r],	10h	; int16_t
//@ 		jge	short loc_133DE	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+r],	ax	; int16_t
//@ 		jmp	short loc_133E7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_133DE:				; CODE XREF: GetTarget+12Bj
//@ 		mov	ax, [bp+r]	; int16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		mov	[bp+r],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 581
//@ 
//@ loc_133E7:				; CODE XREF: GetTarget+132j
//@ 		mov	ax, 16h
//@ 		sub	ax, [bp+r]	; int16_t
//@ 		mov	[bp+r],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 584
//@ 
//@ loc_133F0:				; CODE XREF: GetTarget+FBj
//@ 					; GetTarget+110j
//@ 		push	[bp+_mx]	; int16_t
//@ 		push	[bp+_my]	; int16_t
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	[bp+r]		; int16_t
//@ 		call	LookToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1342E	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 586
//@ 		mov	[bp+GetTarget],	1 ; bool
//@ ; #line	"CS_DEMO.PAS" 587
//@ 		les	di, [bp+var_18+2] ; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	plx, ax		; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	ply, ax		; int16_t
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		les	di, [bp+t]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CS_DEMO.PAS" 588
//@ 		jmp	loc_134F2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 590
//@ 
//@ loc_1342E:				; CODE XREF: GetTarget+2Dj
//@ 					; GetTarget+37j ...
//@ 		cmp	[bp+i],	7	; int16_t
//@ 		jz	short loc_13437	; Jump if Zero (ZF=1)
//@ 		jmp	loc_132BE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 592
//@ 
//@ loc_13437:				; CODE XREF: GetTarget+188j
//@ 		cmp	[bp+rmin], 1	; int16_t
//@ 		jnz	short loc_13440	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_134F2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 594
//@ 
//@ loc_13440:				; CODE XREF: GetTarget+191j
//@ 		mov	[bp+rmin], 2710h ; int16_t
//@ ; #line	"CS_DEMO.PAS" 595
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_14], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jle	short loc_13456	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_134F2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13456:				; CODE XREF: GetTarget+1A7j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_1345E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1345B:				; CODE XREF: GetTarget+245j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 596
//@ 
//@ loc_1345E:				; CODE XREF: GetTarget+1AFj
//@ 		imul	di, [bp+i], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_18], di
//@ 		mov	word ptr [bp+var_18+2],	es
//@ ; #line	"CS_DEMO.PAS" 597
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+_MType]	; int16_t
//@ 		jz	short loc_134E7	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_134E7	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 598
//@ 		push	[bp+_mx]	; int16_t
//@ 		push	[bp+_my]	; int16_t
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	6
//@ 		call	LookToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_134E7	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 600
//@ 		mov	ax, [bp+_my]	; int16_t
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+_mx]	; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	[bp+r],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 601
//@ 		mov	ax, [bp+r]	; int16_t
//@ 		cmp	ax, [bp+rmin]	; int16_t
//@ 		jge	short loc_134E7	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 602
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		les	di, [bp+t]	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+r]	; int16_t
//@ 		mov	[bp+rmin], ax	; int16_t
//@ 		mov	[bp+GetTarget],	1 ; bool
//@ 		les	di, [bp+var_18]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		mov	plx, ax		; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	ply, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 604
//@ 
//@ loc_134E7:				; CODE XREF: GetTarget+1CDj
//@ 					; GetTarget+1D4j ...
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_14]	; Compare Two Operands
//@ 		jz	short loc_134F2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1345B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 605
//@ 
//@ loc_134F2:				; CODE XREF: GetTarget+181j
//@ 					; GetTarget+193j ...
//@ 		mov	al, [bp+GetTarget] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ch		; Return Near from Procedure
//@ GetTarget	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 610
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ MakePunch	proc near		; CODE XREF: AnimateMonsters+151Dp
//@ 
//@ var_E		= dword	ptr -0Eh
//@ var_A		= word ptr -0Ah
//@ z		= word ptr -8		; int16_t
//@ n		= word ptr -6		; int16_t
//@ o		= word ptr -4		; int16_t
//@ MakePunch	= byte ptr -1		; bool
//@ mid		= word ptr  4		; int16_t
//@ p		= word ptr  6		; int16_t
//@ R		= word ptr  8		; int16_t
//@ pz		= word ptr  0Ah		; int16_t
//@ py		= word ptr  0Ch		; int16_t
//@ px		= word ptr  0Eh		; int16_t
//@ my		= word ptr  10h		; int16_t
//@ mx		= word ptr  12h		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 611
//@ 		mov	[bp+MakePunch],	0 ; bool
//@ ; #line	"CS_DEMO.PAS" 613
//@ 		mov	ax, [bp+mid]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		mov	al, [di-5AD8h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+o],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 614
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_A], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jle	short loc_13524	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_135B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13524:				; CODE XREF: MakePunch+26j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_1352C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13529:				; CODE XREF: MakePunch+B8j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 615
//@ 
//@ loc_1352C:				; CODE XREF: MakePunch+2Ej
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"CS_DEMO.PAS" 616
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+o]	; int16_t
//@ 		jz	short loc_135A9	; Jump if Zero (ZF=1)
//@ 		cmp	byte ptr es:[di+26h], 5	; Compare Two Operands
//@ 		jz	short loc_135A9	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 618
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+px]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+py]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, [bp+R]	; int16_t
//@ 		jge	short loc_135A9	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 620
//@ 		push	[bp+px]		; int16_t
//@ 		push	[bp+py]		; int16_t
//@ 		push	[bp+pz]		; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+n]		; int16_t
//@ 		push	[bp+p]		; int16_t
//@ 		push	[bp+p]		; int16_t
//@ 		push	[bp+mid]	; int16_t
//@ 		call	ShootMonster	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 621
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	640h
//@ 		push	0Ch
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 622
//@ 		mov	[bp+MakePunch],	1 ; bool
//@ ; #line	"CS_DEMO.PAS" 629
//@ 
//@ loc_135A9:				; CODE XREF: MakePunch+4Cj
//@ 					; MakePunch+53j ...
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_A]	; Compare Two Operands
//@ 		jz	short loc_135B4	; Jump if Zero (ZF=1)
//@ 		jmp	loc_13529	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 631
//@ 
//@ loc_135B4:				; CODE XREF: MakePunch+28j
//@ 					; MakePunch+B6j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_135BE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_135BB:				; CODE XREF: MakePunch+22Aj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_135BE:				; CODE XREF: MakePunch+C0j
//@ 		imul	di, [bp+n], 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E+2], di
//@ 		mov	[bp+var_A], es
//@ ; #line	"CS_DEMO.PAS" 632
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_135D7	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_1371D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_135D7:				; CODE XREF: MakePunch+D9j
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_135E1	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_1371D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 634
//@ 
//@ loc_135E1:				; CODE XREF: MakePunch+E3j
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+px]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+py]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 635
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		cmp	ax, [bp+R]	; int16_t
//@ 		jl	short loc_1360E	; Jump if Less (SF!=OF)
//@ 		jmp	loc_1371D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 637
//@ 
//@ loc_1360E:				; CODE XREF: MakePunch+110j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+mx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+my]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 638
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+mx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+my]	; int16_t
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CS_DEMO.PAS" 639
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 2
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, 10h		; Add
//@ 		mov	es:[di+1Ah], ax
//@ ; #line	"CS_DEMO.PAS" 640
//@ 		cmp	[bp+n],	0	; int16_t
//@ 		jnz	short loc_1367F	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+1Ah], 20h ; ' ' ; Compare Two Operands
//@ 		jle	short loc_1367F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di+1Ah]
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	ShakeLevel, ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 642
//@ 
//@ loc_1367F:				; CODE XREF: MakePunch+16Dj
//@ 					; MakePunch+174j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		mov	al, es:[di+27h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		cmp	ax, [bp+p]	; int16_t
//@ 		jl	short loc_1369F	; Jump if Less (SF!=OF)
//@ 		mov	al, byte ptr [bp+p] ; int16_t
//@ 		sub	es:[di+27h], al	; Integer Subtraction
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		mov	[bp+p],	ax	; int16_t
//@ 		jmp	short loc_136C4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 643
//@ 
//@ loc_1369F:				; CODE XREF: MakePunch+192j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
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
//@ ; #line	"CS_DEMO.PAS" 645
//@ 
//@ loc_136C4:				; CODE XREF: MakePunch+1A4j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		cmp	word ptr es:[di+50h], 0	; Compare Two Operands
//@ 		jnz	short loc_136D5	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		sub	es:[di+28h], ax	; Integer Subtraction
//@ ; #line	"CS_DEMO.PAS" 646
//@ 
//@ loc_136D5:				; CODE XREF: MakePunch+1D3j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jg	short loc_136ED	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CS_DEMO.PAS" 647
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+28h], ax
//@ 		push	[bp+n]		; int16_t
//@ 		call	AddDeadPlayer	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 648
//@ 
//@ loc_136ED:				; CODE XREF: MakePunch+1E4j
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	500h
//@ 		push	0Ch
//@ 		push	5
//@ 		call	BlowSpark	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 649
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_13719	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_E+2] ; Load	Full Pointer to	ES:xx
//@ 		push	word ptr es:[di+28h]
//@ 		call	SetMePain	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 651
//@ 
//@ loc_13719:				; CODE XREF: MakePunch+212j
//@ 		mov	[bp+MakePunch],	1 ; bool
//@ ; #line	"CS_DEMO.PAS" 653
//@ 
//@ loc_1371D:				; CODE XREF: MakePunch+DBj
//@ 					; MakePunch+E5j ...
//@ 		cmp	[bp+n],	7	; int16_t
//@ 		jz	short loc_13726	; Jump if Zero (ZF=1)
//@ 		jmp	loc_135BB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 654
//@ 
//@ loc_13726:				; CODE XREF: MakePunch+228j
//@ 		mov	al, [bp+MakePunch] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	10h		; Return Near from Procedure
//@ MakePunch	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 658
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ GetPlayerTo	proc near		; CODE XREF: AnimateMonsters+1496p
//@ 
//@ var_4		= dword	ptr -4
//@ my		= word ptr  4		; int16_t
//@ mx		= word ptr  6		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 659
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_1373C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13738:				; CODE XREF: GetPlayerTo+87j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 660
//@ 
//@ loc_1373C:				; CODE XREF: GetPlayerTo+9j
//@ 		imul	di, n$0, 58h	; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CS_DEMO.PAS" 661
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_137AF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 662
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, [bp+mx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, [bp+my]	; int16_t
//@ 		push	ax
//@ 		call	QPifagorA32$0	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 600h	; Compare Two Operands
//@ 		jnb	short loc_137AF	; Jump if Not Below (CF=0)
//@ ; #line	"CS_DEMO.PAS" 664
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	word ptr es:[di+1Ah], 82h ; '‚'
//@ ; #line	"CS_DEMO.PAS" 665
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		sub	ax, es:[di+0Ah]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, [bp+my]	; int16_t
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CS_DEMO.PAS" 666
//@ 		mov	ShakeLevel, 82h	; '‚' ; int16_t
//@ ; #line	"CS_DEMO.PAS" 667
//@ 		mov	word ptr es:[di+18h], 16h
//@ ; #line	"CS_DEMO.PAS" 668
//@ 		add	word ptr es:[di+0Eh], 2	; Add
//@ ; #line	"CS_DEMO.PAS" 669
//@ 		mov	ax, es:[di+2Ah]
//@ 		or	ax, 100h	; Logical Inclusive OR
//@ 		mov	es:[di+2Ah], ax
//@ ; #line	"CS_DEMO.PAS" 670
//@ 
//@ loc_137AF:				; CODE XREF: GetPlayerTo+25j
//@ 					; GetPlayerTo+3Fj
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_13738	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 671
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ GetPlayerTo	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 679
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns unsigned	char 'Byte'
//@ ; Attributes: bp-based frame
//@ 
//@ GetAttack	proc near		; CODE XREF: AnimateMonsters+19D3p
//@ 
//@ a		= byte ptr -2		; uint8_t
//@ GetAttack	= byte ptr -1		; uint8_t
//@ MType		= byte ptr  4		; uint8_t
//@ DMode		= byte ptr  6		; uint8_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 680
//@ 		mov	al, [bp+DMode]	; uint8_t
//@ ; #line	"CS_DEMO.PAS" 681
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jnz	short loc_137D5	; Jump if Not Zero (ZF=0)
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 5		; Add
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+a],	al	; uint8_t
//@ 		jmp	short loc_13846	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 682
//@ 
//@ loc_137D5:				; CODE XREF: GetAttack+9j
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnz	short loc_137F0	; Jump if Not Zero (ZF=0)
//@ 		push	2
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_137EA	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	8	; uint8_t
//@ 		jmp	short loc_137EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 683
//@ 
//@ loc_137EA:				; CODE XREF: GetAttack+28j
//@ 		mov	[bp+a],	7	; uint8_t
//@ 
//@ loc_137EE:				; CODE XREF: GetAttack+2Ej
//@ 		jmp	short loc_13846	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 684
//@ 
//@ loc_137F0:				; CODE XREF: GetAttack+1Dj
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_1380B	; Jump if Not Zero (ZF=0)
//@ 		push	2
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_13805	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	8	; uint8_t
//@ 		jmp	short loc_13809	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 685
//@ 
//@ loc_13805:				; CODE XREF: GetAttack+43j
//@ 		mov	[bp+a],	6	; uint8_t
//@ 
//@ loc_13809:				; CODE XREF: GetAttack+49j
//@ 		jmp	short loc_13846	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 686
//@ 
//@ loc_1380B:				; CODE XREF: GetAttack+38j
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_13815	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	8	; uint8_t
//@ 		jmp	short loc_13846	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 687
//@ 
//@ loc_13815:				; CODE XREF: GetAttack+53j
//@ 		cmp	al, 7		; Compare Two Operands
//@ 		jz	short loc_1381D	; Jump if Zero (ZF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_13834	; Jump if Not Zero (ZF=0)
//@ 
//@ loc_1381D:				; CODE XREF: GetAttack+5Dj
//@ 		push	2
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_1382E	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	7	; uint8_t
//@ 		jmp	short loc_13832	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 688
//@ 
//@ loc_1382E:				; CODE XREF: GetAttack+6Cj
//@ 		mov	[bp+a],	6	; uint8_t
//@ 
//@ loc_13832:				; CODE XREF: GetAttack+72j
//@ 		jmp	short loc_13846	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 689
//@ 
//@ loc_13834:				; CODE XREF: GetAttack+61j
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jnz	short loc_1383E	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	7	; uint8_t
//@ 		jmp	short loc_13846	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 690
//@ 
//@ loc_1383E:				; CODE XREF: GetAttack+7Cj
//@ 		cmp	al, 6		; Compare Two Operands
//@ 		jnz	short loc_13846	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	6	; uint8_t
//@ ; #line	"CS_DEMO.PAS" 692
//@ 
//@ loc_13846:				; CODE XREF: GetAttack+19j
//@ 					; GetAttack:loc_137EEj	...
//@ 		mov	al, [bp+a]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, [bp+MType]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, dx		; Add
//@ 		cmp	word ptr [di-7FD8h], 0 ; Compare Two Operands
//@ 		jnz	short loc_13865	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	8	; uint8_t
//@ ; #line	"CS_DEMO.PAS" 693
//@ 
//@ loc_13865:				; CODE XREF: GetAttack+A5j
//@ 		mov	al, [bp+a]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	al, [bp+MType]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, dx		; Add
//@ 		cmp	word ptr [di-7FD8h], 0 ; Compare Two Operands
//@ 		jnz	short loc_13884	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+a],	5	; uint8_t
//@ ; #line	"CS_DEMO.PAS" 694
//@ 
//@ loc_13884:				; CODE XREF: GetAttack+C4j
//@ 		mov	al, [bp+a]	; uint8_t
//@ 		mov	[bp+GetAttack],	al ; uint8_t
//@ ; #line	"CS_DEMO.PAS" 695
//@ 		mov	al, [bp+GetAttack] ; uint8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retn	4		; Return Near from Procedure
//@ GetAttack	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 700
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateExternal	proc near		; CODE XREF: AnimateMonsters+4p
//@ 
//@ var_1C		= dword	ptr -1Ch
//@ var_18		= word ptr -18h
//@ var_16		= dword	ptr -16h
//@ var_12		= word ptr -12h
//@ dvy		= word ptr -0Ch		; int16_t
//@ dvx		= word ptr -0Ah		; int16_t
//@ l		= word ptr -8		; int16_t
//@ ic		= word ptr -6		; int16_t
//@ i		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	1Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 701
//@ 		mov	[bp+n],	1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 702
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_12], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jle	short loc_138AB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_13A25	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_138AB:				; CODE XREF: AnimateExternal+15j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_138B3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_138B0:				; CODE XREF: AnimateExternal+191j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 703
//@ 
//@ loc_138B3:				; CODE XREF: AnimateExternal+1Dj
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_16], di
//@ 		mov	word ptr [bp+var_16+2],	es
//@ 		cmp	word ptr es:[di+1Ch], 0	; Compare Two Operands
//@ 		jg	short loc_138CD	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_13A1A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 705
//@ 
//@ loc_138CD:				; CODE XREF: AnimateExternal+37j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+1Ah]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mul	word ptr es:[di+1Ch] ; Unsigned	Multiplication of AL or	AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CS_DEMO.PAS" 706
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	di, es:[di+1Ah]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+1Ch] ; Unsigned	Multiplication of AL or	AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CS_DEMO.PAS" 707
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		add	ax, cx		; Add
//@ 		mov	[bp+l],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 708
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+ic], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 709
//@ 		mov	ax, es:[di+0Eh]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+ic]		; int16_t
//@ 		mov	[bp+dvx], ax	; int16_t
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+ic]		; int16_t
//@ 		mov	[bp+dvy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 710
//@ 		mov	ax, [bp+ic]	; int16_t
//@ 		mov	[bp+var_18], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_18]	; Compare Two Operands
//@ 		jg	short loc_13A03	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_13992	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1398F:				; CODE XREF: AnimateExternal+170j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 711
//@ 
//@ loc_13992:				; CODE XREF: AnimateExternal+FCj
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_1C], di
//@ 		mov	word ptr [bp+var_1C+2],	es
//@ ; #line	"CS_DEMO.PAS" 712
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		sub	ax, [bp+dvx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, [bp+dvy]	; int16_t
//@ 		push	ax
//@ 		push	word ptr es:[di+20h]
//@ 		les	di, [bp+var_1C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Ch]
//@ 		mov	ax, es:[di+8]
//@ 		add	ax, 3Ch	; '<'   ; Add
//@ 		push	ax
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	0
//@ 		push	1
//@ 		push	1
//@ 		call	NotFreeForMonster ; function far PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_139FB	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 713
//@ 		mov	ax, [bp+dvx]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		add	es:[di], ax	; Add
//@ 		mov	ax, [bp+dvy]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		add	es:[di+2], ax	; Add
//@ 
//@ loc_139FB:				; CODE XREF: AnimateExternal+154j
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_18]	; Compare Two Operands
//@ 		jnz	short loc_1398F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 715
//@ 
//@ loc_13A03:				; CODE XREF: AnimateExternal+F7j
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_16]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+1Ch], ax	; Integer Subtraction
//@ 		cmp	word ptr es:[di+1Ch], 0	; Compare Two Operands
//@ 		jge	short loc_13A1A	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+1Ch], ax
//@ ; #line	"CS_DEMO.PAS" 716
//@ 
//@ loc_13A1A:				; CODE XREF: AnimateExternal+39j
//@ 					; AnimateExternal+181j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_12]	; Compare Two Operands
//@ 		jz	short locret_13A25 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_138B0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 717
//@ 
//@ locret_13A25:				; CODE XREF: AnimateExternal+17j
//@ 					; AnimateExternal+18Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ AnimateExternal	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 722
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitMZPosition	proc far		; CODE XREF: DoGame+20DP
//@ 
//@ var_A		= dword	ptr -0Ah
//@ var_6		= word ptr -6
//@ zc		= byte ptr -4		; int16_t
//@ z		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 723
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_6], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jg	short locret_13AA4 ; Jump if Greater (ZF=0 & SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_13A42	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13A3E:				; CODE XREF: InitMZPosition+7Bj
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_13A42:				; CODE XREF: InitMZPosition+15j
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CS_DEMO.PAS" 725
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		push	word ptr [di+7FB6h]
//@ 		lea	di, [bp+z]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+zc]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetMFloorZ	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 726
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+1Eh], ax
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	ax, [di+7FBEh]
//@ 		add	ax, [bp+z]	; int16_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+20h], ax
//@ ; #line	"CS_DEMO.PAS" 727
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_6]	; Compare Two Operands
//@ 		jnz	short loc_13A3E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 728
//@ 
//@ locret_13AA4:				; CODE XREF: InitMZPosition+10j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ InitMZPosition	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 733
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateZMovement proc far		; CODE XREF: DoGame:loc_D94CP
//@ 
//@ var_C		= dword	ptr -0Ch
//@ var_8		= word ptr -8
//@ zc		= byte ptr -6		; int16_t
//@ z		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 734
//@ 		mov	[bp+n],	1	; int16_t
//@ ; #line	"CS_DEMO.PAS" 735
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	[bp+var_8], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jle	short loc_13AC0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_13B95	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13AC0:				; CODE XREF: AnimateZMovement+15j
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_13AC8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13AC5:				; CODE XREF: AnimateZMovement+ECj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CS_DEMO.PAS" 736
//@ 
//@ loc_13AC8:				; CODE XREF: AnimateZMovement+1Dj
//@ 		imul	di, [bp+n], 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jnz	short loc_13AE2	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_13B8A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 738
//@ 
//@ loc_13AE2:				; CODE XREF: AnimateZMovement+37j
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		push	word ptr [di+7FB6h]
//@ 		lea	di, [bp+z]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+zc]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	GetMFloorZ	; function far PASCAL returns void
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	[bp+z],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 739
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		cmp	ax, es:[di+1Eh]	; Compare Two Operands
//@ 		jnz	short loc_13B1D	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_13B8A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 740
//@ 
//@ loc_13B1D:				; CODE XREF: AnimateZMovement+73j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+z]	; int16_t
//@ 		jge	short loc_13B43	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		add	es:[di+1Eh], ax	; Add
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+z]	; int16_t
//@ 		jle	short loc_13B43	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"CS_DEMO.PAS" 741
//@ 
//@ loc_13B43:				; CODE XREF: AnimateZMovement+81j
//@ 					; AnimateZMovement+94j
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+z]	; int16_t
//@ 		jle	short loc_13B69	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		sub	es:[di+1Eh], ax	; Integer Subtraction
//@ 		mov	ax, es:[di+1Eh]
//@ 		cmp	ax, [bp+z]	; int16_t
//@ 		jge	short loc_13B69	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+z]	; int16_t
//@ 		mov	es:[di+1Eh], ax
//@ ; #line	"CS_DEMO.PAS" 742
//@ 
//@ loc_13B69:				; CODE XREF: AnimateZMovement+A7j
//@ 					; AnimateZMovement+BAj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	dx, [di+7FBEh]
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		add	ax, dx		; Add
//@ 		mov	es:[di+20h], ax
//@ ; #line	"CS_DEMO.PAS" 743
//@ 
//@ loc_13B8A:				; CODE XREF: AnimateZMovement+39j
//@ 					; AnimateZMovement+75j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jz	short locret_13B95 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_13AC5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 744
//@ 
//@ locret_13B95:				; CODE XREF: AnimateZMovement+17j
//@ 					; AnimateZMovement+EAj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AnimateZMovement endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_5		db 2,'@#'               ; DATA XREF: AnimateMonsters+16DBo
//@ aIncorrectPhase	db 17,'Incorrect phase: ' ; DATA XREF: AnimateMonsters+16CBo
//@ ; #line	"CS_DEMO.PAS" 753
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AnimateMonsters	proc far		; CODE XREF: DoGame+16D1P
//@ 
//@ var_230		= byte ptr -230h
//@ var_130		= byte ptr -130h
//@ var_32		= word ptr -32h
//@ var_30		= dword	ptr -30h
//@ var_2C		= dword	ptr -2Ch
//@ Inv		= byte ptr -28h		; bool
//@ TrAlive		= byte ptr -27h		; bool
//@ rnd		= word ptr -26h		; int16_t
//@ PlR		= word ptr -24h		; int16_t
//@ tgvy		= word ptr -20h		; int16_t
//@ tgvx		= word ptr -1Eh		; int16_t
//@ dvy		= word ptr -1Ch		; int16_t
//@ dvx		= word ptr -1Ah		; int16_t
//@ r		= word ptr -18h		; int16_t
//@ v		= word ptr -16h		; int16_t
//@ dfi		= word ptr -14h		; int16_t
//@ rotcount	= word ptr -0Eh		; int16_t
//@ 
//@ 		enter	230h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CS_DEMO.PAS" 755
//@ 		call	AnimateExternal	; function near	PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 757
//@ 		mov	n$0, 1		; int16_t
//@ 		inc	MsTakt		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 758
//@ 
//@ loc_13BBD:				; CODE XREF: AnimateMonsters+649j
//@ 					; AnimateMonsters:loc_15651j
//@ 		mov	ax, MCount	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_13BDA	; Jump if Less (SF!=OF)
//@ 		jle	short loc_13BD3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_15654	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13BD3:				; CODE XREF: AnimateMonsters+22j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_13BDA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_15654	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 759
//@ 
//@ loc_13BDA:				; CODE XREF: AnimateMonsters+20j
//@ 					; AnimateMonsters+29j
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2C], di
//@ 		mov	word ptr [bp+var_2C+2],	es
//@ 		cmp	byte ptr es:[di+0Bh], 0FFh ; Compare Two Operands
//@ 		jnz	short loc_13BF9	; Jump if Not Zero (ZF=0)
//@ 		inc	n$0		; int16_t
//@ 		jmp	loc_15651	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 760
//@ 
//@ loc_13BF9:				; CODE XREF: AnimateMonsters+44j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_30], di
//@ 		mov	word ptr [bp+var_30+2],	es
//@ ; #line	"CS_DEMO.PAS" 761
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	al, es:[di+26h]
//@ ; #line	"CS_DEMO.PAS" 764
//@ 		cmp	al, 0		; Compare Two Operands
//@ 		jz	short loc_13C20	; Jump if Zero (ZF=1)
//@ 		jmp	loc_13EFD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 766
//@ 
//@ loc_13C20:				; CODE XREF: AnimateMonsters+6Fj
//@ 		mov	[bp+r],	18h	; int16_t
//@ ; #line	"CS_DEMO.PAS" 767
//@ 		mov	ax, t1		; uint16_t
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 768
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_13C59	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_13C52	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_13CEB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13C52:				; CODE XREF: AnimateMonsters+A1j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_13C59	; Jump if Not Below (CF=0)
//@ 		jmp	loc_13CEB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 770
//@ 
//@ loc_13C59:				; CODE XREF: AnimateMonsters+9Fj
//@ 					; AnimateMonsters+A8j ...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_13C83	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_13C9E	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_13C9E	; Jump if Below	(CF=1)
//@ 
//@ loc_13C83:				; CODE XREF: AnimateMonsters+CFj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+6], ax	; Integer Subtraction
//@ 		jmp	short loc_13C59	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 771
//@ 
//@ loc_13C9E:				; CODE XREF: AnimateMonsters+D1j
//@ 					; AnimateMonsters+D5j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 2
//@ ; #line	"CS_DEMO.PAS" 772
//@ 		mov	ax, takt	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_13CEB	; Jump if Not Below (CF=0)
//@ ; #line	"CS_DEMO.PAS" 774
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ ; #line	"CS_DEMO.PAS" 775
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+2Ah]
//@ 		or	ax, es:[di+2Ch]	; Logical Inclusive OR
//@ 		jnz	short loc_13CEB	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 2
//@ ; #line	"CS_DEMO.PAS" 778
//@ 
//@ loc_13CEB:				; CODE XREF: AnimateMonsters+A3j
//@ 					; AnimateMonsters+AAj ...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 0Eh	; Compare Two Operands
//@ 		jnz	short loc_13CF8	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 779
//@ 
//@ loc_13CF8:				; CODE XREF: AnimateMonsters+147j
//@ 		mov	ax, MsTakt	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		and	ax, 3		; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		or	ax, dx		; Logical Inclusive OR
//@ 		jz	short loc_13D17	; Jump if Zero (ZF=1)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 781
//@ 
//@ loc_13D17:				; CODE XREF: AnimateMonsters+166j
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+4]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	di, offset i	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetTarget	; function near	PASCAL varargs returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_13D38	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 783
//@ 
//@ loc_13D38:				; CODE XREF: AnimateMonsters+187j
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 784
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+26h], 2
//@ ; #line	"CS_DEMO.PAS" 785
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ ; #line	"CS_DEMO.PAS" 786
//@ 		mov	byte ptr es:[di+24h], 0
//@ ; #line	"CS_DEMO.PAS" 787
//@ 		mov	byte ptr es:[di+25h], 1
//@ ; #line	"CS_DEMO.PAS" 788
//@ 		mov	ax, i		; int16_t
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CS_DEMO.PAS" 789
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CS_DEMO.PAS" 791
//@ 		cmp	i, 8		; int16_t
//@ 		jl	short loc_13D8B	; Jump if Less (SF!=OF)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 793
//@ 
//@ loc_13D8B:				; CODE XREF: AnimateMonsters+1DAj
//@ 		push	i		; int16_t
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	n$0		; int16_t
//@ 		call	WeakUpMonstersTo ; function far	PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 794
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+v],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 795
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CS_DEMO.PAS" 796
//@ 		mov	di, es:[di+4]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CS_DEMO.PAS" 797
//@ 		cmp	Skill, 0	; int16_t
//@ 		jg	short loc_13DFE	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 798
//@ 
//@ loc_13DFE:				; CODE XREF: AnimateMonsters+24Dj
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	plx		; int16_t
//@ 		push	ply		; int16_t
//@ 		push	10h
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_13E1B	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13E1B:				; CODE XREF: AnimateMonsters+26Aj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		push	plx		; int16_t
//@ 		push	ply		; int16_t
//@ 		push	10h
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_13E53	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 800
//@ 
//@ loc_13E53:				; CODE XREF: AnimateMonsters+2A2j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_13E63	; Jump if Zero (ZF=1)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13E63:				; CODE XREF: AnimateMonsters+2B2j
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFFFh ; Compare Two Operands
//@ 		jnz	short loc_13E70	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_13EF6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 802
//@ 
//@ loc_13E70:				; CODE XREF: AnimateMonsters+2BFj
//@ 		mov	ax, plx		; int16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, ply		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		mov	b0, ax		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 803
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, b0		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_13EAA	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_13EAA:				; CODE XREF: AnimateMonsters+2F5j
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jl	short loc_13EE2	; Jump if Less (SF!=OF)
//@ 		jg	short loc_13EB6	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, 0FCh ; 'ü'  ; Compare Two Operands
//@ 		jb	short loc_13EE2	; Jump if Below	(CF=1)
//@ 
//@ loc_13EB6:				; CODE XREF: AnimateMonsters+303j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, b0		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_13ED6	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_13ED6:				; CODE XREF: AnimateMonsters+321j
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jg	short loc_13EE2	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_13EF6	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 304h	; Compare Two Operands
//@ 		jbe	short loc_13EF6	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 804
//@ 
//@ loc_13EE2:				; CODE XREF: AnimateMonsters+301j
//@ 					; AnimateMonsters+308j	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 5
//@ 		mov	byte ptr es:[di+26h], 3
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 808
//@ 
//@ loc_13EF6:				; CODE XREF: AnimateMonsters+149j
//@ 					; AnimateMonsters+168j	...
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 809
//@ 		jmp	loc_15651	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 812
//@ 
//@ loc_13EFD:				; CODE XREF: AnimateMonsters+71j
//@ 		cmp	al, 5		; Compare Two Operands
//@ 		jz	short loc_13F04	; Jump if Zero (ZF=1)
//@ 		jmp	loc_141C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 814
//@ 
//@ loc_13F04:				; CODE XREF: AnimateMonsters+353j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 7		; Logical AND
//@ 		mov	es:[di+0Bh], al
//@ ; #line	"CS_DEMO.PAS" 815
//@ 		cmp	word ptr es:[di+8], 10h	; Compare Two Operands
//@ 		jl	short loc_13F1B	; Jump if Less (SF!=OF)
//@ 		jmp	loc_13FA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_13F1B:				; CODE XREF: AnimateMonsters+36Aj
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jnz	short loc_13F25	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_13FA8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 817
//@ 
//@ loc_13F25:				; CODE XREF: AnimateMonsters+374j
//@ 		mov	ax, t1		; uint16_t
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 818
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_13F67	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_13F53	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_13F67	; Jump if Not Below (CF=0)
//@ 
//@ loc_13F53:				; CODE XREF: AnimateMonsters+3A1j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 4		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		ja	short loc_13F67	; Jump if Above	(CF=0 &	ZF=0)
//@ 		cmp	word ptr es:[di+8], 0Ah	; Compare Two Operands
//@ 		jz	short loc_13FA5	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 820
//@ 
//@ loc_13F67:				; CODE XREF: AnimateMonsters+39Fj
//@ 					; AnimateMonsters+3A5j	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 10h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 821
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0E8h ; 'è'  ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 822
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jbe	short loc_13FA5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		inc	TotalKills	; uint16_t
//@ ; #line	"CS_DEMO.PAS" 824
//@ 
//@ loc_13FA5:				; CODE XREF: AnimateMonsters+3B9j
//@ 					; AnimateMonsters+3F3j
//@ 		jmp	loc_14182	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 826
//@ 
//@ loc_13FA8:				; CODE XREF: AnimateMonsters+36Cj
//@ 					; AnimateMonsters+376j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_13FD5	; Jump if Less (SF!=OF)
//@ 		jg	short loc_14036	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		ja	short loc_14036	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_13FD5:				; CODE XREF: AnimateMonsters+421j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_1400C	; Jump if Less (SF!=OF)
//@ 		jg	short loc_14036	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_14036	; Jump if Not Below (CF=0)
//@ ; #line	"CS_DEMO.PAS" 827
//@ 
//@ loc_1400C:				; CODE XREF: AnimateMonsters+458j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di+1Eh]
//@ 		call	iswater		; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_14036	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	9
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 829
//@ 
//@ loc_14036:				; CODE XREF: AnimateMonsters+423j
//@ 					; AnimateMonsters+427j	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+3]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	al, es:[di+1]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 6		; Shift	Logical	Left
//@ 		add	di, dx		; Add
//@ 		mov	al, [di+4EC6h]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		cmp	byte ptr [di-23F0h], 0 ; Compare Two Operands
//@ 		jnz	short loc_14060	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_14138	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 830
//@ 
//@ loc_14060:				; CODE XREF: AnimateMonsters+4AFj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, 80h	; '€'   ; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_14093	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_1408C	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_14138	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1408C:				; CODE XREF: AnimateMonsters+4DBj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_14093	; Jump if Not Below (CF=0)
//@ 		jmp	loc_14138	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14093:				; CODE XREF: AnimateMonsters+4D9j
//@ 					; AnimateMonsters+4E2j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		add	ax, 10h		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_140C0	; Jump if Less (SF!=OF)
//@ 		jg	short loc_14138	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_14138	; Jump if Not Below (CF=0)
//@ ; #line	"CS_DEMO.PAS" 831
//@ 
//@ loc_140C0:				; CODE XREF: AnimateMonsters+50Cj
//@ 		mov	ax, t1		; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_32], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_32]	; Compare Two Operands
//@ 		ja	short loc_14138	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_140D7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_140D3:				; CODE XREF: AnimateMonsters+58Aj
//@ 		inc	j		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 832
//@ 
//@ loc_140D7:				; CODE XREF: AnimateMonsters+525j
//@ 		push	104h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 82h	; '‚'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	104h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 82h	; '‚'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	8
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 8		; Add
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		mov	ax, j		; uint16_t
//@ 		cmp	ax, [bp+var_32]	; Compare Two Operands
//@ 		jnz	short loc_140D3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 834
//@ 
//@ loc_14138:				; CODE XREF: AnimateMonsters+4B1j
//@ 					; AnimateMonsters+4DDj	...
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 835
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_14169	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_14182	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_14182	; Jump if Below	(CF=1)
//@ 
//@ loc_14169:				; CODE XREF: AnimateMonsters+5B5j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 838
//@ 
//@ loc_14182:				; CODE XREF: AnimateMonsters:loc_13FA5j
//@ 					; AnimateMonsters+5B7j	...
//@ 		cmp	RespawnTime, 0	; uint16_t
//@ 		jbe	short loc_141BF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	NewSecond, 0	; bool
//@ 		jz	short loc_141BF	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 840
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		inc	word ptr es:[di+22h] ; Increment by 1
//@ ; #line	"CS_DEMO.PAS" 841
//@ 		cmp	byte ptr es:[di+0Ah], 64h ; 'd' ; Compare Two Operands
//@ 		jbe	short loc_141BF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 842
//@ 		mov	ax, RespawnTime	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+22h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_141B6	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_141BF	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_141BF	; Jump if Below	(CF=1)
//@ ; #line	"CS_DEMO.PAS" 843
//@ 
//@ loc_141B6:				; CODE XREF: AnimateMonsters+602j
//@ 		push	n$0		; int16_t
//@ 		call	RespawnMonster	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 845
//@ 
//@ loc_141BF:				; CODE XREF: AnimateMonsters+5DBj
//@ 					; AnimateMonsters+5E2j	...
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 846
//@ 		jmp	loc_15651	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 849
//@ 
//@ loc_141C6:				; CODE XREF: AnimateMonsters+355j
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+22h], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 850
//@ 		cmp	word ptr es:[di+22h], 1068h ; Compare Two Operands
//@ 		jle	short loc_141F8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 851
//@ 		mov	word ptr es:[di+14h], 0FFFFh
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ 		mov	byte ptr es:[di+26h], 0
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 		mov	word ptr es:[di+8], 2
//@ 		jmp	loc_13BBD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 853
//@ 
//@ loc_141F8:				; CODE XREF: AnimateMonsters+62Aj
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+v],	ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 856
//@ 		mov	[bp+TrAlive], 1	; bool
//@ ; #line	"CS_DEMO.PAS" 857
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 64h ; 'd' ; Compare Two Operands
//@ 		jge	short loc_1425D	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CS_DEMO.PAS" 858
//@ 		imul	di, es:[di+14h], 58h ; Signed Multiply
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		cmp	word ptr es:[di+28h], 0	; Compare Two Operands
//@ 		jle	short loc_14257	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jz	short loc_14257	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 860
//@ 		mov	ax, es:[di+0Ah]
//@ 		mov	plx, ax		; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	ply, ax		; int16_t
//@ ; #line	"CS_DEMO.PAS" 861
//@ 		mov	ax, es:[di+2Ah]
//@ 		and	ax, 1		; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jbe	short loc_1424C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		mov	ax, es:[di+20h]
//@ 		and	ax, 4000h	; Logical AND
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_14250	; Jump if Zero (ZF=1)
//@ 
//@ loc_1424C:				; CODE XREF: AnimateMonsters+693j
//@ 		mov	al, 0
//@ 		jmp	short loc_14252	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14250:				; CODE XREF: AnimateMonsters+69Ej
//@ 		mov	al, 1
//@ 
//@ loc_14252:				; CODE XREF: AnimateMonsters+6A2j
//@ 		mov	[bp+Inv], al	; bool
//@ ; #line	"CS_DEMO.PAS" 862
//@ 		jmp	short loc_1425B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14257:				; CODE XREF: AnimateMonsters+674j
//@ 					; AnimateMonsters+67Aj
//@ 		mov	[bp+TrAlive], 0	; bool
//@ 
//@ loc_1425B:				; CODE XREF: AnimateMonsters+6A9j
//@ 		jmp	short loc_1428E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 864
//@ 
//@ loc_1425D:				; CODE XREF: AnimateMonsters+662j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di+14h]
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		imul	di, ax,	28h	; Signed Multiply
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CS_DEMO.PAS" 865
//@ 		cmp	word ptr es:[di+12h], 0	; Compare Two Operands
//@ 		jle	short loc_1428A	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, es:[di]
//@ 		mov	plx, ax		; int16_t
//@ 		mov	ax, es:[di+2]
//@ 		mov	ply, ax		; int16_t
//@ 		mov	[bp+Inv], 0	; bool
//@ 		jmp	short loc_1428E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 866
//@ 
//@ loc_1428A:				; CODE XREF: AnimateMonsters+6C9j
//@ 		mov	[bp+TrAlive], 0	; bool
//@ ; #line	"CS_DEMO.PAS" 879
//@ 
//@ loc_1428E:				; CODE XREF: AnimateMonsters:loc_1425Bj
//@ 					; AnimateMonsters+6DCj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		sub	ax, plx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, ply		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		mov	[bp+PlR], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 880
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	plx		; int16_t
//@ 		push	ply		; int16_t
//@ 		push	12h
//@ 		call	LookToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1433A	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 882
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		cmp	al, 6Ah	; 'j'   ; Compare Two Operands
//@ 		jz	short loc_142EC	; Jump if Zero (ZF=1)
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jb	short loc_1431C	; Jump if Below	(CF=1)
//@ 		cmp	al, 6Fh	; 'o'   ; Compare Two Operands
//@ 		jbe	short loc_142EC	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	al, 72h	; 'r'   ; Compare Two Operands
//@ 		jz	short loc_142EC	; Jump if Zero (ZF=1)
//@ 		cmp	al, 76h	; 'v'   ; Compare Two Operands
//@ 		jnz	short loc_1431C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 883
//@ 
//@ loc_142EC:				; CODE XREF: AnimateMonsters+72Ej
//@ 					; AnimateMonsters+736j	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+25h], 0	; Compare Two Operands
//@ 		jz	short loc_142FE	; Jump if Zero (ZF=1)
//@ 		cmp	word ptr es:[di+22h], 1A4h ; Compare Two Operands
//@ 		jle	short loc_1431C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_142FE:				; CODE XREF: AnimateMonsters+748j
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 884
//@ 
//@ loc_1431C:				; CODE XREF: AnimateMonsters+732j
//@ 					; AnimateMonsters+73Ej	...
//@ 		mov	ax, plx		; int16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+16h], ax
//@ 		mov	ax, ply		; int16_t
//@ 		mov	es:[di+18h], ax
//@ 		mov	byte ptr es:[di+25h], 1
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ ; #line	"CS_DEMO.PAS" 885
//@ 		jmp	short loc_1436A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 887
//@ 
//@ loc_1433A:				; CODE XREF: AnimateMonsters+723j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		sub	ax, es:[di+16h]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, es:[di+18h]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, 12Ch	; Compare Two Operands
//@ 		jge	short loc_1436A	; Jump if Greater or Equal (SF=OF)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+25h], 0
//@ ; #line	"CS_DEMO.PAS" 890
//@ 
//@ loc_1436A:				; CODE XREF: AnimateMonsters+78Cj
//@ 					; AnimateMonsters+7B4j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+25h], 0	; Compare Two Operands
//@ 		jnz	short loc_14382	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, plx		; int16_t
//@ 		mov	es:[di+16h], ax
//@ 		mov	ax, ply		; int16_t
//@ 		mov	es:[di+18h], ax
//@ ; #line	"CS_DEMO.PAS" 893
//@ 
//@ loc_14382:				; CODE XREF: AnimateMonsters+7C6j
//@ 		cmp	[bp+TrAlive], 0	; bool
//@ 		jz	short loc_143B4	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 894
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+26h]
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jb	short loc_143B4	; Jump if Below	(CF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		ja	short loc_143B4	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CS_DEMO.PAS" 895
//@ 		mov	ax, es:[di+16h]
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+18h]
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CS_DEMO.PAS" 897
//@ 
//@ loc_143B4:				; CODE XREF: AnimateMonsters+7DAj
//@ 					; AnimateMonsters+7E5j	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+26h], 2	; Compare Two Operands
//@ 		jz	short loc_143C1	; Jump if Zero (ZF=1)
//@ 		jmp	loc_14547	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 898
//@ 
//@ loc_143C1:				; CODE XREF: AnimateMonsters+810j
//@ 		mov	al, es:[di+0Ah]
//@ ; #line	"CS_DEMO.PAS" 899
//@ 		cmp	al, 65h	; 'e'   ; Compare Two Operands
//@ 		jnz	short loc_14419	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		and	ax, 3Fh		; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		sub	ax, 20h	; ' '   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_143F2	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_143F2:				; CODE XREF: AnimateMonsters+83Dj
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 400h	; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		and	ax, 3FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	es:[di+0Ch], ax
//@ 		jmp	loc_14547	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 900
//@ 
//@ loc_14419:				; CODE XREF: AnimateMonsters+81Bj
//@ 		cmp	al, 66h	; 'f'   ; Compare Two Operands
//@ 		jnz	short loc_14463	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		and	ax, 7Fh		; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		sub	ax, 40h	; '@'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_1443C	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_1443C:				; CODE XREF: AnimateMonsters+887j
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 400h	; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 20h	; ' '   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		and	ax, 3FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	es:[di+0Ch], ax
//@ 		jmp	loc_14547	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 901
//@ 
//@ loc_14463:				; CODE XREF: AnimateMonsters+86Fj
//@ 		cmp	al, 67h	; 'g'   ; Compare Two Operands
//@ 		jnz	short loc_144AD	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		and	ax, 7Fh		; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		sub	ax, 40h	; '@'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_14486	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_14486:				; CODE XREF: AnimateMonsters+8D1j
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 400h	; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 20h	; ' '   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		and	ax, 3FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	es:[di+0Ch], ax
//@ 		jmp	loc_14547	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 902
//@ 
//@ loc_144AD:				; CODE XREF: AnimateMonsters+8B9j
//@ 		cmp	al, 6Ah	; 'j'   ; Compare Two Operands
//@ 		jnz	short loc_144F6	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		and	ax, 0FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		sub	ax, 80h	; '€'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_144D0	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_144D0:				; CODE XREF: AnimateMonsters+91Bj
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 400h	; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 40h	; '@'   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		and	ax, 3FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	es:[di+0Ch], ax
//@ 		jmp	short loc_14547	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 903
//@ 
//@ loc_144F6:				; CODE XREF: AnimateMonsters+903j
//@ 		cmp	al, 6Bh	; 'k'   ; Compare Two Operands
//@ 		jnz	short loc_14547	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, word ptr Time ; int32_t
//@ 		mov	dx, word ptr Time+2 ; int32_t
//@ 		mov	cx, 1
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		and	ax, 3Fh		; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		sub	ax, 20h	; ' '   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_14523	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_14523:				; CODE XREF: AnimateMonsters+96Ej
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 400h	; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		and	ax, 3FFh	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CS_DEMO.PAS" 906
//@ 
//@ loc_14547:				; CODE XREF: AnimateMonsters+812j
//@ 					; AnimateMonsters+86Aj	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+tgvx], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 907
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+0Ch]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+tgvy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 908
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvx], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 909
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+0Ch]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 912
//@ 		mov	[bp+rotcount], 8 ; int16_t
//@ ; #line	"CS_DEMO.PAS" 913
//@ 		cmp	[bp+v],	2	; int16_t
//@ 		jg	short loc_14607	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jmp	loc_14803	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 914
//@ 
//@ loc_14607:				; CODE XREF: AnimateMonsters+A56j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+26h]
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jnb	short loc_14615	; Jump if Not Below (CF=0)
//@ 		jmp	loc_14803	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14615:				; CODE XREF: AnimateMonsters+A64j
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jbe	short loc_1461C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_14803	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 916
//@ 
//@ loc_1461C:				; CODE XREF: AnimateMonsters+A6Bj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+rotcount], ax ; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+dfi], ax	; int16_t
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	j, ax		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 917
//@ 
//@ loc_1462D:				; CODE XREF: AnimateMonsters+C44j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+dvx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, [bp+dvy]	; int16_t
//@ 		push	ax
//@ 		push	word ptr es:[di+20h]
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+8]
//@ 		push	0
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		push	0
//@ 		push	0
//@ 		call	NotFreeForMonster ; function far PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_146B4	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, [bp+tgvx]	; int16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+v]		; int16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, [bp+tgvy]	; int16_t
//@ 		shl	ax, 7		; Shift	Logical	Left
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+v]		; int16_t
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		push	word ptr es:[di+20h]
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+8]
//@ 		push	0
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		push	0
//@ 		push	1
//@ 		call	NotFreeForMonster ; function far PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_146B4	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_147F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_146B4:				; CODE XREF: AnimateMonsters+ABAj
//@ 					; AnimateMonsters+B03j
//@ 		cmp	[bp+rotcount], 20h ; ' ' ; int16_t
//@ 		jl	short loc_146BD	; Jump if Less (SF!=OF)
//@ 		jmp	loc_147F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 921
//@ 
//@ loc_146BD:				; CODE XREF: AnimateMonsters+B0Cj
//@ 		cmp	[bp+dfi], 0	; int16_t
//@ 		jnz	short loc_146DB	; Jump if Not Zero (ZF=0)
//@ 		push	2
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_146D6	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+dfi], 20h ;	' ' ; int16_t
//@ 		jmp	short loc_146DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_146D6:				; CODE XREF: AnimateMonsters+B21j
//@ 		mov	[bp+dfi], 0FFE0h ; int16_t
//@ ; #line	"CS_DEMO.PAS" 922
//@ 
//@ loc_146DB:				; CODE XREF: AnimateMonsters+B15j
//@ 					; AnimateMonsters+B28j
//@ 		inc	[bp+rotcount]	; int16_t
//@ 		mov	ax, [bp+dfi]	; int16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+0Ch], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 923
//@ 		cmp	byte ptr es:[di+26h], 2	; Compare Two Operands
//@ 		jnz	short loc_14705	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+rotcount], 8 ; int16_t
//@ 		jnz	short loc_14705	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 924
//@ 		mov	byte ptr es:[di+26h], 1
//@ 		mov	ax, takt	; uint16_t
//@ 		and	ax, 3		; Logical AND
//@ 		inc	ax		; Increment by 1
//@ 		mov	es:[di+24h], al
//@ ; #line	"CS_DEMO.PAS" 926
//@ 
//@ loc_14705:				; CODE XREF: AnimateMonsters+B41j
//@ 					; AnimateMonsters+B47j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Ch], 0	; Compare Two Operands
//@ 		jge	short loc_14715	; Jump if Greater or Equal (SF=OF)
//@ 		add	word ptr es:[di+0Ch], 400h ; Add
//@ ; #line	"CS_DEMO.PAS" 927
//@ 
//@ loc_14715:				; CODE XREF: AnimateMonsters+B61j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+0Ch], 3FFh ; Compare Two Operands
//@ 		jle	short loc_14726	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	word ptr es:[di+0Ch], 400h ; Integer Subtraction
//@ ; #line	"CS_DEMO.PAS" 929
//@ 
//@ loc_14726:				; CODE XREF: AnimateMonsters+B72j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+tgvx], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 930
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+0Ch]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+tgvy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 931
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvx], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 932
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+0Ch]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 933
//@ 		push	[bp+dfi]	; int16_t
//@ 		call	Sgn		; function far PASCAL returns signed char 'Shortint'
//@ 		cbw			; AL ->	AX (with sign)
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+dfi]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+dfi], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 934
//@ 		jmp	loc_1462D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 935
//@ 
//@ loc_147F3:				; CODE XREF: AnimateMonsters+B05j
//@ 					; AnimateMonsters+B0Ej
//@ 		cmp	[bp+rotcount], 20h ; ' ' ; int16_t
//@ 		jnz	short loc_14803	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, j		; uint16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CS_DEMO.PAS" 938
//@ 
//@ loc_14803:				; CODE XREF: AnimateMonsters+A58j
//@ 					; AnimateMonsters+A66j	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, es:[di+4]	; Compare Two Operands
//@ 		jnz	short loc_14813	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_148E0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 940
//@ 
//@ loc_14813:				; CODE XREF: AnimateMonsters+C62j
//@ 		mov	ax, es:[di+0Ch]
//@ 		cmp	ax, es:[di+4]	; Compare Two Operands
//@ 		jle	short loc_14824	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+dfi], 1	; int16_t
//@ 		jmp	short loc_14829	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14824:				; CODE XREF: AnimateMonsters+C6Fj
//@ 		mov	[bp+dfi], 0FFFFh ; int16_t
//@ ; #line	"CS_DEMO.PAS" 941
//@ 
//@ loc_14829:				; CODE XREF: AnimateMonsters+C76j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, es:[di+4]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 200h	; Compare Two Operands
//@ 		jle	short loc_14846	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+dfi]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dfi], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 942
//@ 
//@ loc_14846:				; CODE XREF: AnimateMonsters+C90j
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		sub	ax, es:[di+0Ch]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_1487B	; Jump if Less (SF!=OF)
//@ 		jg	short loc_14888	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		ja	short loc_14888	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_1487B:				; CODE XREF: AnimateMonsters+CC7j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	es:[di+4], ax
//@ 		jmp	short loc_148BF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 943
//@ 
//@ loc_14888:				; CODE XREF: AnimateMonsters+CC9j
//@ 					; AnimateMonsters+CCDj
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+dfi]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	es:[di+4], ax
//@ ; #line	"CS_DEMO.PAS" 944
//@ 
//@ loc_148BF:				; CODE XREF: AnimateMonsters+CDAj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4], 0 ;	Compare	Two Operands
//@ 		jge	short loc_148CF	; Jump if Greater or Equal (SF=OF)
//@ 		add	word ptr es:[di+4], 400h ; Add
//@ ; #line	"CS_DEMO.PAS" 945
//@ 
//@ loc_148CF:				; CODE XREF: AnimateMonsters+D1Bj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4], 3FFh ; Compare Two Operands
//@ 		jle	short loc_148E0	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		sub	word ptr es:[di+4], 400h ; Integer Subtraction
//@ ; #line	"CS_DEMO.PAS" 948
//@ 
//@ loc_148E0:				; CODE XREF: AnimateMonsters+C64j
//@ 					; AnimateMonsters+D2Cj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CS_DEMO.PAS" 949
//@ 		mov	di, es:[di+4]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 20h	; ' '
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; '€'
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CS_DEMO.PAS" 950
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvx], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 951
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	di, es:[di+4]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 40h	; '@'
//@ 		idiv	cx		; Signed Divide
//@ 		mul	[bp+v]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 100h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dvy], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 956
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 8		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jbe	short loc_149DA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 957
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		add	ax, 10h		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_149CD	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_149DA	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_149DA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_149CD:				; CODE XREF: AnimateMonsters+E19j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 7		; Logical AND
//@ 		mov	es:[di+0Bh], al
//@ ; #line	"CS_DEMO.PAS" 959
//@ 
//@ loc_149DA:				; CODE XREF: AnimateMonsters+DF3j
//@ 					; AnimateMonsters+E1Bj	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 5 ;	Compare	Two Operands
//@ 		jnz	short loc_14A2C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 960
//@ 		mov	al, es:[di+0Ah]
//@ ; #line	"CS_DEMO.PAS" 961
//@ 		cmp	al, 6Eh	; 'n'   ; Compare Two Operands
//@ 		jnz	short loc_14A05	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	ax, 38h	; '8'   ; Integer Subtraction
//@ 		mov	[bp+rotcount], ax ; int16_t
//@ 		jmp	short loc_14A2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 962
//@ 
//@ loc_14A05:				; CODE XREF: AnimateMonsters+E3Ej
//@ 		cmp	al, 71h	; 'q'   ; Compare Two Operands
//@ 		jnz	short loc_14A10	; Jump if Not Zero (ZF=0)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+rotcount], ax ; int16_t
//@ 		jmp	short loc_14A2A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 963
//@ 
//@ loc_14A10:				; CODE XREF: AnimateMonsters+E5Bj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		add	ax, 4		; Add
//@ 		mov	[bp+rotcount], ax ; int16_t
//@ 
//@ loc_14A2A:				; CODE XREF: AnimateMonsters+E57j
//@ 					; AnimateMonsters+E62j
//@ 		jmp	short loc_14A46	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 964
//@ 
//@ loc_14A2C:				; CODE XREF: AnimateMonsters+E36j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		add	ax, 4		; Add
//@ 		mov	[bp+rotcount], ax ; int16_t
//@ ; #line	"CS_DEMO.PAS" 966
//@ 
//@ loc_14A46:				; CODE XREF: AnimateMonsters:loc_14A2Aj
//@ 		cmp	[bp+TrAlive], 0	; bool
//@ 		jnz	short loc_14A4F	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_150EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 967
//@ 
//@ loc_14A4F:				; CODE XREF: AnimateMonsters+E9Ej
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+26h], 3	; Compare Two Operands
//@ 		jz	short loc_14A5C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_150EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 968
//@ 
//@ loc_14A5C:				; CODE XREF: AnimateMonsters+EABj
//@ 		mov	ax, es:[di+6]
//@ 		cmp	ax, [bp+rotcount] ; int16_t
//@ 		jle	short loc_14A68	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_150EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14A68:				; CODE XREF: AnimateMonsters+EB7j
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rotcount] ; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_14A92	; Jump if Less (SF!=OF)
//@ 		jle	short loc_14A8B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_150EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14A8B:				; CODE XREF: AnimateMonsters+EDAj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_14A92	; Jump if Below	(CF=1)
//@ 		jmp	loc_150EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 969
//@ 
//@ loc_14A92:				; CODE XREF: AnimateMonsters+ED8j
//@ 					; AnimateMonsters+EE1j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+8], 5 ;	Compare	Two Operands
//@ 		jz	short loc_14A9F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_15048	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_14A9F:				; CODE XREF: AnimateMonsters+EEEj
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFFFh ; Compare Two Operands
//@ 		jnz	short loc_14AAC	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_15048	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 973
//@ 
//@ loc_14AAC:				; CODE XREF: AnimateMonsters+EFBj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		or	al, 8		; Logical Inclusive OR
//@ 		mov	es:[di+0Bh], al
//@ ; #line	"CS_DEMO.PAS" 974
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 7Ah	; 'z'   ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 975
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ ; #line	"CS_DEMO.PAS" 976
//@ 		cmp	al, 65h	; 'e'   ; Compare Two Operands
//@ 		jnz	short loc_14B2D	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 500h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 978
//@ 
//@ loc_14B2D:				; CODE XREF: AnimateMonsters+F31j
//@ 		cmp	al, 67h	; 'g'   ; Compare Two Operands
//@ 		jz	short loc_14B34	; Jump if Zero (ZF=1)
//@ 		jmp	loc_14BD3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 980
//@ 
//@ loc_14B34:				; CODE XREF: AnimateMonsters+F83j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 0B00h	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 981
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 0B00h	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		neg	ax		; Two's Complement Negation
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 982
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 983
//@ 
//@ loc_14BD3:				; CODE XREF: AnimateMonsters+F85j
//@ 		cmp	al, 68h	; 'h'   ; Compare Two Operands
//@ 		jnz	short loc_14C1E	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 580h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 984
//@ 
//@ loc_14C1E:				; CODE XREF: AnimateMonsters+1029j
//@ 		cmp	al, 69h	; 'i'   ; Compare Two Operands
//@ 		jnz	short loc_14C65	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+10h], 0Ah ; Signed Multiply
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		imul	ax, es:[di+0Eh], 0Ah ; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 880h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 985
//@ 
//@ loc_14C65:				; CODE XREF: AnimateMonsters+1074j
//@ 		cmp	al, 6Ah	; 'j'   ; Compare Two Operands
//@ 		jnz	short loc_14CD3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 986
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 480h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 987
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		push	5
//@ 		push	1Ch
//@ 		push	28h ; '('
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 988
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 989
//@ 
//@ loc_14CD3:				; CODE XREF: AnimateMonsters+10BBj
//@ 		cmp	al, 6Bh	; 'k'   ; Compare Two Operands
//@ 		jnz	short loc_14D28	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 680h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 990
//@ 
//@ loc_14D28:				; CODE XREF: AnimateMonsters+1129j
//@ 		cmp	al, 6Ch	; 'l'   ; Compare Two Operands
//@ 		jnz	short loc_14D5F	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 160h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 991
//@ 
//@ loc_14D5F:				; CODE XREF: AnimateMonsters+117Ej
//@ 		cmp	al, 6Dh	; 'm'   ; Compare Two Operands
//@ 		jnz	short loc_14DA6	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+10h], 9 ; Signed Multiply
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		imul	ax, es:[di+0Eh], 9 ; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 740h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 992
//@ 
//@ loc_14DA6:				; CODE XREF: AnimateMonsters+11B5j
//@ 		cmp	al, 6Eh	; 'n'   ; Compare Two Operands
//@ 		jnz	short loc_14E03	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 993
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 640h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 994
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		push	6
//@ 		push	1Ch
//@ 		push	0A0h ; ' '
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 995
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 996
//@ 
//@ loc_14E03:				; CODE XREF: AnimateMonsters+11FCj
//@ 		cmp	al, 70h	; 'p'   ; Compare Two Operands
//@ 		jnz	short loc_14E4E	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 4C0h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 997
//@ 
//@ loc_14E4E:				; CODE XREF: AnimateMonsters+1259j
//@ 		cmp	al, 71h	; 'q'   ; Compare Two Operands
//@ 		jz	short loc_14E55	; Jump if Zero (ZF=1)
//@ 		jmp	loc_14EFD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 998
//@ 
//@ loc_14E55:				; CODE XREF: AnimateMonsters+12A4j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+10h], 0Ah ; Signed Multiply
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		imul	ax, es:[di+0Eh], 0Ah ; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 480h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 999
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+10h], 0Ah ; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		imul	ax, es:[di+0Eh], 0Ah ; Signed Multiply
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 480h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1000
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Eh]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+10h]
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		push	5
//@ 		push	1Ch
//@ 		push	28h ; '('
//@ 		call	AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1001
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1002
//@ 
//@ loc_14EFD:				; CODE XREF: AnimateMonsters+12A6j
//@ 		cmp	al, 75h	; 'u'   ; Compare Two Operands
//@ 		jnz	short loc_14F4E	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+0Eh]
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 640h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1003
//@ 
//@ loc_14F4E:				; CODE XREF: AnimateMonsters+1353j
//@ 		cmp	al, 76h	; 'v'   ; Compare Two Operands
//@ 		jnz	short loc_14F85	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 420h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ 		jmp	loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1004
//@ 
//@ loc_14F85:				; CODE XREF: AnimateMonsters+13A4j
//@ 		cmp	al, 77h	; 'w'   ; Compare Two Operands
//@ 		jz	short loc_14F8C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_15034	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1005
//@ 
//@ loc_14F8C:				; CODE XREF: AnimateMonsters+13DBj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 0A00h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1006
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 0A00h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1007
//@ 		imul	di, RCount, 18h	; uint16_t
//@ 		add	word ptr [di-4CB8h], 1A00h ; Add
//@ ; #line	"CS_DEMO.PAS" 1008
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di+1Eh]
//@ 		add	ax, 0A00h	; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		call	SendRocketToMe	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1009
//@ 		imul	di, RCount, 18h	; uint16_t
//@ 		sub	word ptr [di-4CB8h], 1A00h ; Integer Subtraction
//@ ; #line	"CS_DEMO.PAS" 1010
//@ 		jmp	short loc_15045	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1011
//@ 
//@ loc_15034:				; CODE XREF: AnimateMonsters+13DDj
//@ 		cmp	al, 78h	; 'x'   ; Compare Two Operands
//@ 		jnz	short loc_15045	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		call	GetPlayerTo	; function near	PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1014
//@ 
//@ loc_15045:				; CODE XREF: AnimateMonsters+F7Ej
//@ 					; AnimateMonsters+1024j ...
//@ 		jmp	loc_150EE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1016
//@ 
//@ loc_15048:				; CODE XREF: AnimateMonsters+EF0j
//@ 					; AnimateMonsters+EFDj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	n$0		; int16_t
//@ 		call	WeakUpMonstersTo ; function far	PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1017
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	ax, es:[di+4]
//@ 		add	ax, 100h	; Add
//@ 		and	ax, 3FFh	; Logical AND
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 18h
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		mov	di, es:[di+4]
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-6390h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 18h
//@ 		idiv	cx		; Signed Divide
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+2]	; Add
//@ 		push	ax
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	ax, es:[di+1Eh]	; Add
//@ 		push	ax
//@ 		push	0C8h ; 'È'
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+12h]
//@ 		mov	ax, n$0		; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		push	ax
//@ 		call	MakePunch	; function near	PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_150EE	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 1022
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 90h	; ''   ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1027
//@ 
//@ loc_150EE:				; CODE XREF: AnimateMonsters+EA0j
//@ 					; AnimateMonsters+EADj	...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+8]
//@ 		mov	di, offset LandZ ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset CeilZ ; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetMFloorZ	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1028
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		cmp	ax, LandZ	; int16_t
//@ 		jl	short loc_1517E	; Jump if Less (SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 1029
//@ 		cmp	[bp+v],	2	; int16_t
//@ 		jle	short loc_1517E	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 1030
//@ 		mov	al, es:[di+26h]
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jb	short loc_1517E	; Jump if Below	(CF=1)
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		ja	short loc_1517E	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1031
//@ 		mov	ax, es:[di]
//@ 		add	ax, [bp+dvx]	; int16_t
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		add	ax, [bp+dvy]	; int16_t
//@ 		push	ax
//@ 		push	word ptr es:[di+20h]
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+10h]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	word ptr es:[di+8]
//@ 		mov	ax, es:[di+0Ah]
//@ 		sub	ax, 28h	; '('   ; Integer Subtraction
//@ 		push	ax
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+14h]
//@ 		push	1
//@ 		push	0
//@ 		call	NotFreeForMonster ; function far PASCAL	returns	PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1517E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1032
//@ 		mov	ax, [bp+dvx]	; int16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di], ax	; Add
//@ 		mov	ax, [bp+dvy]	; int16_t
//@ 		add	es:[di+2], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 1035
//@ 
//@ loc_1517E:				; CODE XREF: AnimateMonsters+1570j
//@ 					; AnimateMonsters+1576j ...
//@ 		mov	ax, t1		; uint16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		add	es:[di+6], ax	; Add
//@ ; #line	"CS_DEMO.PAS" 1037
//@ 		cmp	byte ptr es:[di+0Ah], 6Dh ; 'm' ; Compare Two Operands
//@ 		jnz	short loc_151F6	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+8], 0 ;	Compare	Two Operands
//@ 		jnz	short loc_151F6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1039
//@ 		cmp	word ptr es:[di+6], 10h	; Compare Two Operands
//@ 		jg	short loc_151BB	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jg	short loc_151E3	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_151BB	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 10h		; Compare Two Operands
//@ 		ja	short loc_151E3	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_151BB:				; CODE XREF: AnimateMonsters+15EFj
//@ 					; AnimateMonsters+1608j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+6], 50h	; 'P' ; Compare Two Operands
//@ 		jg	short loc_151F6	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	ax, t1		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jg	short loc_151E3	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_151F6	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 50h	; 'P'   ; Compare Two Operands
//@ 		jbe	short loc_151F6	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CS_DEMO.PAS" 1041
//@ 
//@ loc_151E3:				; CODE XREF: AnimateMonsters+1606j
//@ 					; AnimateMonsters+160Dj ...
//@ 		push	0FFFFh
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	4Ch ; 'L'
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1044
//@ 
//@ loc_151F6:				; CODE XREF: AnimateMonsters+15E1j
//@ 					; AnimateMonsters+15E8j ...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Ah], 78h ; 'x' ; Compare Two Operands
//@ 		jnz	short loc_1522C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1045
//@ 		cmp	word ptr es:[di+8], 0Ah	; Compare Two Operands
//@ 		jnz	short loc_15219	; Jump if Not Zero (ZF=0)
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[di+7FB8h], ax
//@ 		jmp	short loc_1522C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1046
//@ 
//@ loc_15219:				; CODE XREF: AnimateMonsters+1659j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		imul	di, ax,	0A2h	; Signed Multiply
//@ 		mov	word ptr [di+7FB8h], 168h
//@ ; #line	"CS_DEMO.PAS" 1052
//@ 
//@ loc_1522C:				; CODE XREF: AnimateMonsters+1652j
//@ 					; AnimateMonsters+166Bj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_1525C	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_15255	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_1564D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15255:				; CODE XREF: AnimateMonsters+16A4j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_1525C	; Jump if Not Below (CF=0)
//@ 		jmp	loc_1564D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1054
//@ 
//@ loc_1525C:				; CODE XREF: AnimateMonsters+16A2j
//@ 					; AnimateMonsters+16ABj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		cmp	word ptr es:[di+7Ah], 0	; Compare Two Operands
//@ 		jnz	short loc_152AB	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1055
//@ 		lea	di, [bp+var_230] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aIncorrectPhase ; "Incorrect	phase: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_130] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_5	; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1056
//@ 
//@ loc_152AB:				; CODE XREF: AnimateMonsters+16C3j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	ax, cx
//@ 		mov	dx, bx
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 1057
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 7		; Logical AND
//@ 		mov	es:[di+0Bh], al
//@ ; #line	"CS_DEMO.PAS" 1059
//@ 		cmp	[bp+TrAlive], 0	; bool
//@ 		jz	short loc_152EE	; Jump if Zero (ZF=1)
//@ 		jmp	loc_153AE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1060
//@ 
//@ loc_152EE:				; CODE XREF: AnimateMonsters+173Dj
//@ 		cmp	word ptr es:[di+14h], 7	; Compare Two Operands
//@ 		jnz	short loc_15361	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1062
//@ 		mov	byte ptr es:[di+25h], 0
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+16h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+18h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	plx, ax		; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	ply, ax		; int16_t
//@ 		mov	[bp+Inv], 0	; bool
//@ ; #line	"CS_DEMO.PAS" 1063
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ 		mov	byte ptr es:[di+26h], 1
//@ 		mov	byte ptr es:[di+24h], 4
//@ ; #line	"CS_DEMO.PAS" 1064
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	0FFFFh
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		push	ax
//@ 		mov	di, offset i	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	GetTarget	; function near	PASCAL varargs returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1535F	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 1066
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+26h], 2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+22h], ax
//@ ; #line	"CS_DEMO.PAS" 1067
//@ 		mov	byte ptr es:[di+24h], 0
//@ 		mov	byte ptr es:[di+25h], 1
//@ ; #line	"CS_DEMO.PAS" 1068
//@ 		mov	ax, i		; int16_t
//@ 		mov	es:[di+14h], ax
//@ ; #line	"CS_DEMO.PAS" 1070
//@ 
//@ loc_1535F:				; CODE XREF: AnimateMonsters+1792j
//@ 		jmp	short loc_153AB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1072
//@ 
//@ loc_15361:				; CODE XREF: AnimateMonsters+1747j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+14h], 7
//@ ; #line	"CS_DEMO.PAS" 1073
//@ 		mov	byte ptr es:[di+26h], 2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CS_DEMO.PAS" 1074
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+66h]
//@ 		or	ax, es:[di+68h]	; Logical Inclusive OR
//@ 		jz	short loc_153AB	; Jump if Zero (ZF=1)
//@ ; #line	"CS_DEMO.PAS" 1076
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+26h], 4
//@ 		mov	word ptr es:[di+8], 0Fh
//@ ; #line	"CS_DEMO.PAS" 1077
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		mov	al, es:[di+0Ah]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		add	ax, 0A6h ; '¦'  ; Add
//@ 		push	ax
//@ 		call	AddEvVoice	; function far PASCAL returns void
//@ ; #line	"CS_DEMO.PAS" 1079
//@ 
//@ loc_153AB:				; CODE XREF: AnimateMonsters:loc_1535Fj
//@ 					; AnimateMonsters+17D4j
//@ 		jmp	loc_1564D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1081
//@ 
//@ loc_153AE:				; CODE XREF: AnimateMonsters+173Fj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+26h]
//@ ; #line	"CS_DEMO.PAS" 1082
//@ 		cmp	al, 1		; Compare Two Operands
//@ 		jz	short loc_153BC	; Jump if Zero (ZF=1)
//@ 		jmp	loc_154E1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1083
//@ 
//@ loc_153BC:				; CODE XREF: AnimateMonsters+180Bj
//@ 		push	word ptr es:[di]
//@ 		push	word ptr es:[di+2]
//@ 		push	plx		; int16_t
//@ 		push	ply		; int16_t
//@ 		push	14h
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_153D9	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_154C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_153D9:				; CODE XREF: AnimateMonsters+1828j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		imul	ax, es:[di+10h], 9 ; Signed Multiply
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		imul	ax, es:[di+0Eh], 9 ; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		push	plx		; int16_t
//@ 		push	ply		; int16_t
//@ 		push	14h
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_15409	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_154C6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1086
//@ 
//@ loc_15409:				; CODE XREF: AnimateMonsters+1858j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+26h], 2
//@ ; #line	"CS_DEMO.PAS" 1087
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1541E	; Jump if Zero (ZF=1)
//@ 		jmp	loc_154C4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1541E:				; CODE XREF: AnimateMonsters+186Dj
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFFFh ; Compare Two Operands
//@ 		jnz	short loc_1542B	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_154C4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_1542B:				; CODE XREF: AnimateMonsters+187Aj
//@ 		cmp	[bp+Inv], 0	; bool
//@ 		jz	short loc_15434	; Jump if Zero (ZF=1)
//@ 		jmp	loc_154C4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1091
//@ 
//@ loc_15434:				; CODE XREF: AnimateMonsters+1883j
//@ 		mov	ax, plx		; int16_t
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, ply		; int16_t
//@ 		sub	ax, es:[di+2]	; Integer Subtraction
//@ 		push	ax
//@ 		call	FindVectorFi	; function far PASCAL returns signed int 'Integer'
//@ 		mov	b0, ax		; uint16_t
//@ ; #line	"CS_DEMO.PAS" 1092
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, b0		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_1546E	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_1546E:				; CODE XREF: AnimateMonsters+18B9j
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jl	short loc_154B0	; Jump if Less (SF!=OF)
//@ 		jg	short loc_1547A	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, 80h	; '€'   ; Compare Two Operands
//@ 		jb	short loc_154B0	; Jump if Below	(CF=1)
//@ 
//@ loc_1547A:				; CODE XREF: AnimateMonsters+18C7j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, b0		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_1549A	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_1549A:				; CODE XREF: AnimateMonsters+18E5j
//@ 		cmp	dx, 0		; Compare Two Operands
//@ 		jg	short loc_154B0	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_154A6	; Jump if Less (SF!=OF)
//@ 		cmp	ax, 380h	; Compare Two Operands
//@ 		ja	short loc_154B0	; Jump if Above	(CF=0 &	ZF=0)
//@ 
//@ loc_154A6:				; CODE XREF: AnimateMonsters+18F3j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Ah], 78h ; 'x' ; Compare Two Operands
//@ 		jnz	short loc_154C4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1095
//@ 
//@ loc_154B0:				; CODE XREF: AnimateMonsters+18C5j
//@ 					; AnimateMonsters+18CCj ...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 5
//@ ; #line	"CS_DEMO.PAS" 1096
//@ 		mov	byte ptr es:[di+26h], 3
//@ ; #line	"CS_DEMO.PAS" 1097
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 1100
//@ 
//@ loc_154C4:				; CODE XREF: AnimateMonsters+186Fj
//@ 					; AnimateMonsters+187Cj ...
//@ 		jmp	short loc_154DE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1101
//@ 
//@ loc_154C6:				; CODE XREF: AnimateMonsters+182Aj
//@ 					; AnimateMonsters+185Aj
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+24h], 0	; Compare Two Operands
//@ 		ja	short loc_154D7	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	byte ptr es:[di+26h], 2
//@ 		jmp	short loc_154DE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_154D7:				; CODE XREF: AnimateMonsters+1922j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		dec	byte ptr es:[di+24h] ; Decrement by 1
//@ ; #line	"CS_DEMO.PAS" 1102
//@ 
//@ loc_154DE:				; CODE XREF: AnimateMonsters:loc_154C4j
//@ 					; AnimateMonsters+1929j
//@ 		jmp	loc_1564D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1104
//@ 
//@ loc_154E1:				; CODE XREF: AnimateMonsters+180Dj
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jz	short loc_154F0	; Jump if Zero (ZF=1)
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jz	short loc_154F0	; Jump if Zero (ZF=1)
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jz	short loc_154F0	; Jump if Zero (ZF=1)
//@ 		jmp	loc_1564D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1107
//@ 
//@ loc_154F0:				; CODE XREF: AnimateMonsters+1937j
//@ 					; AnimateMonsters+193Bj ...
//@ 		cmp	[bp+Inv], 0	; bool
//@ 		jz	short loc_154FD	; Jump if Zero (ZF=1)
//@ 		mov	[bp+rnd], 8	; int16_t
//@ 		jmp	short loc_15563	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1108
//@ 
//@ loc_154FD:				; CODE XREF: AnimateMonsters+1948j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+26h]
//@ ; #line	"CS_DEMO.PAS" 1109
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		jnz	short loc_1551D	; Jump if Not Zero (ZF=0)
//@ 		cmp	word ptr es:[di+8], 0Ah	; Compare Two Operands
//@ 		jnz	short loc_15516	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+rnd], 1	; int16_t
//@ 		jmp	short loc_1551B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15516:				; CODE XREF: AnimateMonsters+1961j
//@ 		mov	[bp+rnd], 2	; int16_t
//@ 
//@ loc_1551B:				; CODE XREF: AnimateMonsters+1968j
//@ 		jmp	short loc_15563	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1110
//@ 
//@ loc_1551D:				; CODE XREF: AnimateMonsters+195Aj
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jnz	short loc_15555	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		cmp	byte ptr es:[di+0Ah], 71h ; 'q' ; Compare Two Operands
//@ 		jz	short loc_15532	; Jump if Zero (ZF=1)
//@ 		mov	[bp+rnd], 7	; int16_t
//@ 		jmp	short loc_15553	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1111
//@ 
//@ loc_15532:				; CODE XREF: AnimateMonsters+197Dj
//@ 		push	19h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		cmp	ax, 4		; Compare Two Operands
//@ 		jz	short loc_15545	; Jump if Zero (ZF=1)
//@ 		mov	[bp+rnd], 0FFFFh ; int16_t
//@ 		jmp	short loc_1554A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_15545:				; CODE XREF: AnimateMonsters+1990j
//@ 		mov	[bp+rnd], 7	; int16_t
//@ 
//@ loc_1554A:				; CODE XREF: AnimateMonsters+1997j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ 
//@ loc_15553:				; CODE XREF: AnimateMonsters+1984j
//@ 		jmp	short loc_15563	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1112
//@ 
//@ loc_15555:				; CODE XREF: AnimateMonsters+1973j
//@ 		cmp	al, 2		; Compare Two Operands
//@ 		jnz	short loc_15563	; Jump if Not Zero (ZF=0)
//@ 		mov	ax, 4
//@ 		sub	ax, Skill	; int16_t
//@ 		mov	[bp+rnd], ax	; int16_t
//@ ; #line	"CS_DEMO.PAS" 1115
//@ 
//@ loc_15563:				; CODE XREF: AnimateMonsters+194Fj
//@ 					; AnimateMonsters:loc_1551Bj ...
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		add	ax, 3Ch	; '<'   ; Add
//@ 		cmp	ax, [bp+PlR]	; int16_t
//@ 		jle	short loc_15599	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CS_DEMO.PAS" 1117
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		push	ax
//@ 		mov	al, es:[di+0Ah]
//@ 		push	ax
//@ 		call	GetAttack	; function near	PASCAL returns unsigned	char 'Byte'
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ ; #line	"CS_DEMO.PAS" 1118
//@ 		mov	byte ptr es:[di+26h], 3
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 1119
//@ 		jmp	loc_1564D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1120
//@ 
//@ loc_15599:				; CODE XREF: AnimateMonsters+19C4j
//@ 		push	9
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rnd]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_155BA	; Jump if Less (SF!=OF)
//@ 		jle	short loc_155B3	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_1563F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_155B3:				; CODE XREF: AnimateMonsters+1A02j
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_155BA	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_1563F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_155BA:				; CODE XREF: AnimateMonsters+1A00j
//@ 					; AnimateMonsters+1A09j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+0Bh]
//@ 		and	al, 2		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_1563F	; Jump if Not Zero (ZF=0)
//@ 		imul	ax, es:[di+10h], 9 ; Signed Multiply
//@ 		add	ax, es:[di]	; Add
//@ 		push	ax
//@ 		imul	ax, es:[di+0Eh], 9 ; Signed Multiply
//@ 		mov	dx, ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		push	ax
//@ 		push	plx		; int16_t
//@ 		push	ply		; int16_t
//@ 		push	10h
//@ 		call	PathToMe	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_1563F	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_30]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+14h], 0FFFFh ; Compare Two Operands
//@ 		jz	short loc_1563F	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, es:[di+4]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 24h	; '$'   ; Compare Two Operands
//@ 		jl	short loc_15629	; Jump if Less (SF!=OF)
//@ 		mov	ax, es:[di+0Ch]
//@ 		sub	ax, es:[di+4]	; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, 3DCh	; Compare Two Operands
//@ 		jg	short loc_15629	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	byte ptr es:[di+0Ah], 78h ; 'x' ; Compare Two Operands
//@ 		jnz	short loc_1563F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CS_DEMO.PAS" 1126
//@ 
//@ loc_15629:				; CODE XREF: AnimateMonsters+1A62j
//@ 					; AnimateMonsters+1A74j
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+8], 5
//@ ; #line	"CS_DEMO.PAS" 1127
//@ 		mov	byte ptr es:[di+26h], 3
//@ ; #line	"CS_DEMO.PAS" 1128
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+6], ax
//@ ; #line	"CS_DEMO.PAS" 1129
//@ 		jmp	short loc_1564D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1130
//@ 
//@ loc_1563F:				; CODE XREF: AnimateMonsters+1A04j
//@ 					; AnimateMonsters+1A0Bj ...
//@ 		les	di, [bp+var_2C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+26h], 2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CS_DEMO.PAS" 1135
//@ 
//@ loc_1564D:				; CODE XREF: AnimateMonsters+16A6j
//@ 					; AnimateMonsters+16ADj ...
//@ 		inc	n$0		; int16_t
//@ ; #line	"CS_DEMO.PAS" 1136
//@ 
//@ loc_15651:				; CODE XREF: AnimateMonsters+4Aj
//@ 					; AnimateMonsters+34Ej	...
//@ 		jmp	loc_13BBD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CS_DEMO.PAS" 1139
//@ 
//@ locret_15654:				; CODE XREF: AnimateMonsters+24j
//@ 					; AnimateMonsters+2Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AnimateMonsters	endp
//@ 
//@ ; #line	"CS_DEMO.PAS" 1145
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; Attributes: bp-based frame
//@ 
//@ $CsDemoInit	proc far		; CODE XREF: PROGRAM+32P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CS_DEMO.PAS" 1146
//@ 		mov	MemoActive, 0	; bool
//@ ; #line	"CS_DEMO.PAS" 1147
//@ 		mov	RecordDemo, 0	; bool
//@ ; #line	"CS_DEMO.PAS" 1148
//@ 		mov	PlayDemo, 0	; bool
//@ ; #line	"CS_DEMO.PAS" 1149
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ $CsDemoInit	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ 		align 8
