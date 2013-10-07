
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

#include "cspbio.h"

#include "csvesa.h"


uint16_t CurVideoMode;

bool Internal;
bool UserMaps;

FILE* F;
FILE* Ft;

int32_t Ll;

char LastFName[256]; // TOOD: filesystem

char AddonPath[41]; // TOOD: filesystem


static char BaseFile[81]; // TODO: filesystem

static const size_t FILE_NAME_SIZE = 13;

#pragma pack(push, 1)

struct TFileTableElement
{
	char    FName[FILE_NAME_SIZE];
	int32_t FSize;
	int32_t FBase;
};

#pragma pack(pop)

TFileTableElement FileTable[2048];

static uint16_t intFCnt;


//@ ; #line	"CSPBIO.PAS" 1162
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ QPifagorA32$0	proc far		; CODE XREF: AnimateRockets+106P
//@ 					; AnimateRockets+1A8P ...
//@ 
//@ YY		= word ptr  6		; int16_t
//@ XX		= word ptr  8		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1163
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 1164
//@ 		mov	ax, [bp+XX]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	si, ax
//@ ; #line	"CSPBIO.PAS" 1165
//@ 		mov	ax, [bp+YY]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	di, ax
//@ ; #line	"CSPBIO.PAS" 1166
//@ 		mov	cx, si
//@ 		add	cx, di		; Add
//@ 		push	cx
//@ ; #line	"CSPBIO.PAS" 1168
//@ 		xor	eax, eax	; Logical Exclusive OR
//@ 		mov	ax, si
//@ ; #line	"CSPBIO.PAS" 1169
//@ 		xor	ebx, ebx	; Logical Exclusive OR
//@ 		mov	bx, di
//@ ; #line	"CSPBIO.PAS" 1170
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSPBIO.PAS" 1171
//@ 		cmp	eax, 0		; Compare Two Operands
//@ ; #line	"CSPBIO.PAS" 1172
//@ 		jz	short loc_2B909	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 1173
//@ 		mov	bx, 7
//@ ; #line	"CSPBIO.PAS" 1174
//@ 		imul	ebx		; Signed Multiply
//@ ; #line	"CSPBIO.PAS" 1177
//@ 		mov	bx, cx
//@ ; #line	"CSPBIO.PAS" 1178
//@ 		shl	ebx, 3		; Shift	Logical	Left
//@ ; #line	"CSPBIO.PAS" 1179
//@ 		sub	ebx, ecx	; Integer Subtraction
//@ ; #line	"CSPBIO.PAS" 1180
//@ 		sub	ebx, ecx	; Integer Subtraction
//@ ; #line	"CSPBIO.PAS" 1181
//@ 		xor	edx, edx	; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 1182
//@ 		div	ebx		; Unsigned Divide
//@ ; #line	"CSPBIO.PAS" 1183
//@ 		pop	bx
//@ 		sub	bx, ax		; Integer Subtraction
//@ 		push	bx
//@ ; #line	"CSPBIO.PAS" 1184
//@ 
//@ loc_2B909:				; CODE XREF: QPifagorA32$0+32j
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1185
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ QPifagorA32$0	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1190
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ 
//@ getmousestate	proc far		; CODE XREF: GetMouseStatus:loc_22D0AP
//@ 					; CheckMouse+9P
//@ 		mov	cx, 0FFFFh
//@ ; #line	"CSPBIO.PAS" 1191
//@ 		mov	dx, 0FFFFh
//@ ; #line	"CSPBIO.PAS" 1192
//@ 		mov	ax, 3
//@ ; #line	"CSPBIO.PAS" 1193
//@ 		int	33h		; - MS MOUSE - RETURN POSITION AND BUTTON STATUS
//@ 					; Return: BX = button status, CX = column, DX =	row
//@ ; #line	"CSPBIO.PAS" 1195
//@ 		mov	MsButt,	bx	; int16_t
//@ ; #line	"CSPBIO.PAS" 1196
//@ 		shr	cx, 1		; Shift	Logical	Right
//@ ; #line	"CSPBIO.PAS" 1197
//@ 		mov	MsX, cx		; int16_t
//@ ; #line	"CSPBIO.PAS" 1198
//@ 		mov	MsY, dx		; int16_t
//@ ; #line	"CSPBIO.PAS" 1199
//@ 		retf			; Return Far from Procedure
//@ getmousestate	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1213
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns signed int 'Integer'
//@ 
//@ GetJoyX		proc far		; CODE XREF: GetJoyStatus+4EP
//@ 					; CheckJoyStick+13P ...
//@ 		mov	dx, 201h
//@ ; #line	"CSPBIO.PAS" 1214
//@ 		mov	ah, 1
//@ ; #line	"CSPBIO.PAS" 1215
//@ 		out	dx, al		; Game I/O port
//@ 					; bits 0-3: Coordinates	(resistive, time-dependent inputs)
//@ 					; bits 4-7: Buttons/Triggers (digital inputs)
//@ ; #line	"CSPBIO.PAS" 1216
//@ 		mov	bx, 0
//@ ; #line	"CSPBIO.PAS" 1217
//@ 		mov	cx, 0FA00h
//@ ; #line	"CSPBIO.PAS" 1218
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1219
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"CSPBIO.PAS" 1220
//@ 
//@ loc_2B937:				; CODE XREF: GetJoyX+1Bj
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1221
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1222
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1223
//@ 		in	al, dx		; Game I/O port
//@ 					; bits 0-3: Coordinates	(resistive, time-dependent inputs)
//@ 					; bits 4-7: Buttons/Triggers (digital inputs)
//@ ; #line	"CSPBIO.PAS" 1224
//@ 		test	ah, al		; Logical Compare
//@ ; #line	"CSPBIO.PAS" 1225
//@ 		jz	short loc_2B945	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 1226
//@ 		inc	bx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 1227
//@ 		loop	loc_2B937	; Loop while CX	!= 0
//@ ; #line	"CSPBIO.PAS" 1228
//@ 
//@ loc_2B945:				; CODE XREF: GetJoyX+18j
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"CSPBIO.PAS" 1229
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ ; #line	"CSPBIO.PAS" 1230
//@ 		mov	JoyX, bx	; int16_t
//@ ; #line	"CSPBIO.PAS" 1231
//@ 		retf			; Return Far from Procedure
//@ GetJoyX		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1236
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns signed int 'Integer'
//@ 
//@ GetJoyY		proc far		; CODE XREF: GetJoyStatus+5AP
//@ 					; CheckJoyStick+1FP ...
//@ 		mov	dx, 201h
//@ ; #line	"CSPBIO.PAS" 1237
//@ 		mov	ah, 2
//@ ; #line	"CSPBIO.PAS" 1238
//@ 		out	dx, al		; Game I/O port
//@ 					; bits 0-3: Coordinates	(resistive, time-dependent inputs)
//@ 					; bits 4-7: Buttons/Triggers (digital inputs)
//@ ; #line	"CSPBIO.PAS" 1239
//@ 		mov	bx, 0
//@ ; #line	"CSPBIO.PAS" 1240
//@ 		mov	cx, 0FA00h
//@ ; #line	"CSPBIO.PAS" 1241
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1242
//@ 		cli			; Clear	Interrupt Flag
//@ ; #line	"CSPBIO.PAS" 1243
//@ 
//@ loc_2B95C:				; CODE XREF: GetJoyY+1Bj
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1244
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1245
//@ 		push	ax
//@ 		pop	ax
//@ ; #line	"CSPBIO.PAS" 1246
//@ 		in	al, dx		; Game I/O port
//@ 					; bits 0-3: Coordinates	(resistive, time-dependent inputs)
//@ 					; bits 4-7: Buttons/Triggers (digital inputs)
//@ ; #line	"CSPBIO.PAS" 1247
//@ 		test	ah, al		; Logical Compare
//@ ; #line	"CSPBIO.PAS" 1248
//@ 		jz	short loc_2B96A	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 1249
//@ 		inc	bx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 1250
//@ 		loop	loc_2B95C	; Loop while CX	!= 0
//@ ; #line	"CSPBIO.PAS" 1251
//@ 
//@ loc_2B96A:				; CODE XREF: GetJoyY+18j
//@ 		sti			; Set Interrupt	Flag
//@ ; #line	"CSPBIO.PAS" 1252
//@ 		shr	bx, 1		; Shift	Logical	Right
//@ ; #line	"CSPBIO.PAS" 1253
//@ 		mov	JoyY, bx	; int16_t
//@ ; #line	"CSPBIO.PAS" 1254
//@ 		retf			; Return Far from Procedure
//@ GetJoyY		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1258
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StosW		proc far		; CODE XREF: ExpandFrame+278P
//@ 					; Build3dScene+25P ...
//@ 
//@ v		= word ptr  6		; uint16_t
//@ cnt		= word ptr  8		; uint16_t
//@ oo1		= word ptr  0Ah		; uint16_t
//@ ss1		= word ptr  0Ch		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1259
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSPBIO.PAS" 1260
//@ 		mov	ax, [bp+ss1]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1261
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 1262
//@ 		mov	di, [bp+oo1]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1263
//@ 		mov	cx, [bp+cnt]	; uint16_t
//@ 		mov	ax, [bp+v]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1264
//@ 		rep stosw		; Store	String
//@ ; #line	"CSPBIO.PAS" 1265
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ StosW		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1268
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ StosEW		proc far		; CODE XREF: UpDateInfo+4DCP
//@ 
//@ v		= word ptr  6		; uint16_t
//@ cnt		= dword	ptr  8		; int32_t
//@ oo1		= dword	ptr  0Ch	; int32_t
//@ ss1		= word ptr  10h		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1269
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSPBIO.PAS" 1270
//@ 		mov	ax, [bp+ss1]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1271
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 1272
//@ 		mov	edi, [bp+oo1]	; int32_t
//@ ; #line	"CSPBIO.PAS" 1273
//@ 		mov	ecx, [bp+cnt]	; int32_t
//@ ; #line	"CSPBIO.PAS" 1274
//@ 		mov	ax, [bp+v]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1275
//@ 		rep stos word ptr es:[edi] ; Store String
//@ ; #line	"CSPBIO.PAS" 1276
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ StosEW		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1293
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ movsw		proc far		; CODE XREF: LoadServerPatch+32P
//@ 					; ShowVESATime+96P ...
//@ 
//@ count		= word ptr  6		; uint16_t
//@ o2		= word ptr  8		; uint16_t
//@ s2		= word ptr  0Ah		; uint16_t
//@ o1		= word ptr  0Ch		; uint16_t
//@ s1		= word ptr  0Eh		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1294
//@ 		push	ds
//@ ; #line	"CSPBIO.PAS" 1295
//@ 		mov	ds, [bp+s1]	; uint16_t
//@ 		mov	si, [bp+o1]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1296
//@ 		mov	ax, [bp+s2]	; uint16_t
//@ 		mov	es, ax
//@ 		mov	di, [bp+o2]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1297
//@ 		mov	cx, [bp+count]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1298
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSPBIO.PAS" 1299
//@ 		rep movsw		; Move Byte(s) from String to String
//@ ; #line	"CSPBIO.PAS" 1300
//@ 		pop	ds
//@ ; #line	"CSPBIO.PAS" 1301
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ movsw		endp
//@ 
//! ; #line	"CSPBIO.PAS" 1308
//! 
//! ; =============== S U B	R O U T	I N E =======================================
//! 
//! ; function far PASCAL returns PASCAL boolean 'Boolean'
//! ; Attributes: bp-based frame
//! 
//! ExistFile	proc far		; CODE XREF: ScanSavedNames+65P
//! 					; FOpen+53P ...
//!
bool ExistFile(const char* const filename)
{
//! Regs		= word ptr -116h	; struct Registers
//! var_110		= word ptr -110h
//! var_108		= word ptr -108h
//! var_104		= byte ptr -104h
//! FLen		= byte ptr -102h	; uint8_t
//! var_101		= byte ptr -101h
//! ExistFile	= byte ptr -1		; bool
//! arg_0		= dword	ptr  6
//!
	struct stat dummy;
	return 0 == stat(filename, &dummy);
//! 		enter	116h, 0		; Make Stack Frame for Procedure Parameters
//! 		mov	bx, ss
//! 		mov	es, bx
//! 		mov	bx, ds
//! 		cld			; Clear	Direction Flag
//! 		lea	di, [bp+FLen]	; uint8_t
//! 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//! 		lodsb			; Load String
//! 		stosb			; Store	String
//! 		xchg	ax, cx		; Exchange Register/Memory with	Register
//! 		xor	ch, ch		; Logical Exclusive OR
//! 		rep movsb		; Move Byte(s) from String to String
//! 		mov	ds, bx
//! ; #line	"CSPBIO.PAS" 1309
//! 		cmp	[bp+FLen], 0	; uint8_t
//! 		jnz	short loc_2B9EA	; Jump if Not Zero (ZF=0)
//! 		mov	[bp+ExistFile],	0 ; bool
//! 		jmp	short loc_2BA34	; Jump
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 1311
//! 
//! loc_2B9EA:				; CODE XREF: ExistFile+20j
//! 		inc	[bp+FLen]	; uint8_t
//! ; #line	"CSPBIO.PAS" 1312
//! 		mov	al, [bp+FLen]	; uint8_t
//! 		xor	ah, ah		; Logical Exclusive OR
//! 		mov	di, ax
//! 		mov	[bp+di+FLen], 0	; uint8_t
//! ; #line	"CSPBIO.PAS" 1313
//! 		mov	[bp+Regs], 4300h ; struct Registers
//! ; #line	"CSPBIO.PAS" 1314
//! 		mov	ax, ss
//! 		mov	[bp+var_108], ax
//! ; #line	"CSPBIO.PAS" 1315
//! 		lea	ax, [bp+var_101] ; Load	Effective Address
//! 		mov	[bp+var_110], ax
//! ; #line	"CSPBIO.PAS" 1316
//! 		lea	di, [bp+Regs]	; struct Registers
//! 		push	ss
//! 		push	di
//! 		call	@MsDos$qm9Registers ; function far PASCAL returns void\nfunction far PASCAL returns void
//! ; #line	"CSPBIO.PAS" 1317
//! 		mov	al, [bp+var_104]
//! 		shr	al, 1		; Shift	Logical	Right
//! 		jb	short loc_2BA2B	; Jump if Below	(CF=1)
//! 		call	@IOResult$qv	; IOResult: Word{AX}
//! 		or	ax, ax		; Logical Inclusive OR
//! 		jz	short loc_2BA2F	; Jump if Zero (ZF=1)
//! 
//! loc_2BA2B:				; CODE XREF: ExistFile+5Ej
//! 		mov	al, 0
//! 		jmp	short loc_2BA31	; Jump
//! ; ---------------------------------------------------------------------------
//! 
//! loc_2BA2F:				; CODE XREF: ExistFile+67j
//! 		mov	al, 1
//! 
//! loc_2BA31:				; CODE XREF: ExistFile+6Bj
//! 		mov	[bp+ExistFile],	al ; bool
//! ; #line	"CSPBIO.PAS" 1319
//! 
//! loc_2BA34:				; CODE XREF: ExistFile+26j
//! 		mov	al, [bp+ExistFile] ; bool
//! 		leave			; High Level Procedure Exit
//! 		retf	4		; Return Far from Procedure
}
//! ExistFile	endp
//!
//@ ; #line	"CSPBIO.PAS" 1325
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL varargs returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ TextSeek	proc near		; CODE XREF: TOpen+1A7p
//@ 
//@ var_A		= dword	ptr -0Ah
//@ Pos		= word ptr -6		; int32_t
//@ var_4		= word ptr -4
//@ TextSeek	= byte ptr -1		; bool
//@ Target		= word ptr  4		; int32_t
//@ arg_2		= word ptr  6
//@ F		= dword	ptr  8		; Text
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1326
//@ 		les	di, [bp+F]	; Text
//@ 		mov	word ptr [bp+var_A], di
//@ 		mov	word ptr [bp+var_A+2], es
//@ ; #line	"CSPBIO.PAS" 1327
//@ 		mov	[bp+TextSeek], 0 ; bool
//@ ; #line	"CSPBIO.PAS" 1328
//@ 		cmp	word ptr es:[di+2], 0D7B1h ; Compare Two Operands
//@ 		jz	short loc_2BA57	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2BB21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1331
//@ 
//@ loc_2BA57:				; CODE XREF: TextSeek+17j
//@ 		mov	Regs.$AX, 4201h	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1332
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		mov	Regs.$BX, ax	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1333
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Regs.$CX, ax	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1334
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	Regs.$DX, ax	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1335
//@ 		mov	di, offset Regs	; struct Registers
//@ 		push	ds
//@ 		push	di
//@ 		call	@MsDos$qm9Registers ; function far PASCAL returns void\nfunction far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1338
//@ 		mov	al, byte ptr Regs.Flags	; struct Registers
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_2BA84	; Jump if Not Below (CF=0)
//@ 		jmp	loc_2BB21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1341
//@ 
//@ loc_2BA84:				; CODE XREF: TextSeek+44j
//@ 		mov	ax, Regs.$DX	; struct Registers
//@ 		mov	[bp+var_4], ax
//@ ; #line	"CSPBIO.PAS" 1342
//@ 		mov	ax, Regs.$AX	; struct Registers
//@ 		mov	[bp+Pos], ax	; int32_t
//@ ; #line	"CSPBIO.PAS" 1343
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	[bp+Pos], ax	; int32_t
//@ 		sbb	[bp+var_4], dx	; Integer Subtraction with Borrow
//@ ; #line	"CSPBIO.PAS" 1346
//@ 		mov	ax, [bp+Target]	; int32_t
//@ 		mov	dx, [bp+arg_2]
//@ 		sub	ax, [bp+Pos]	; int32_t
//@ 		sbb	dx, [bp+var_4]	; Integer Subtraction with Borrow
//@ 		mov	[bp+Pos], ax	; int32_t
//@ 		mov	[bp+var_4], dx
//@ ; #line	"CSPBIO.PAS" 1347
//@ 		cmp	[bp+var_4], 0	; Compare Two Operands
//@ 		jg	short loc_2BABF	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2BAE0	; Jump if Less (SF!=OF)
//@ 		cmp	[bp+Pos], 0	; int32_t
//@ 		jb	short loc_2BAE0	; Jump if Below	(CF=1)
//@ 
//@ loc_2BABF:				; CODE XREF: TextSeek+7Aj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+0Ah]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, [bp+var_4]	; Compare Two Operands
//@ 		jg	short loc_2BAD4	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2BAE0	; Jump if Less (SF!=OF)
//@ 		cmp	ax, [bp+Pos]	; int32_t
//@ 		jbe	short loc_2BAE0	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPBIO.PAS" 1349
//@ 
//@ loc_2BAD4:				; CODE XREF: TextSeek+90j
//@ 		mov	ax, [bp+Pos]	; int32_t
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		jmp	short loc_2BB1D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1353
//@ 
//@ loc_2BAE0:				; CODE XREF: TextSeek+7Cj TextSeek+82j ...
//@ 		mov	Regs.$AX, 4200h	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1354
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		mov	Regs.$BX, ax	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1355
//@ 		mov	ax, [bp+arg_2]
//@ 		mov	Regs.$CX, ax	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1356
//@ 		mov	ax, [bp+Target]	; int32_t
//@ 		mov	Regs.$DX, ax	; struct Registers
//@ ; #line	"CSPBIO.PAS" 1357
//@ 		mov	di, offset Regs	; struct Registers
//@ 		push	ds
//@ 		push	di
//@ 		call	@MsDos$qm9Registers ; function far PASCAL returns void\nfunction far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1359
//@ 		mov	al, byte ptr Regs.Flags	; struct Registers
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_2BB0E	; Jump if Not Below (CF=0)
//@ 		jmp	short loc_2BB21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1361
//@ 
//@ loc_2BB0E:				; CODE XREF: TextSeek+CFj
//@ 		les	di, [bp+var_A]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSPBIO.PAS" 1362
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSPBIO.PAS" 1365
//@ 
//@ loc_2BB1D:				; CODE XREF: TextSeek+A3j
//@ 		mov	[bp+TextSeek], 1 ; bool
//@ ; #line	"CSPBIO.PAS" 1366
//@ 
//@ loc_2BB21:				; CODE XREF: TextSeek+19j TextSeek+46j ...
//@ 		mov	al, [bp+TextSeek] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ TextSeek	endp ; sp-analysis failed
//@ 
//@ ; #line	"CSPBIO.PAS" 1370
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ movsD$0		proc far		; CODE XREF: RestoreLights+18DP
//@ 					; RestoreLights+1B3P ...
//@ 
//@ count		= word ptr  6		; uint16_t
//@ o2		= word ptr  8		; uint16_t
//@ s2		= word ptr  0Ah		; uint16_t
//@ o1		= word ptr  0Ch		; uint16_t
//@ s1		= word ptr  0Eh		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1371
//@ 		push	ds
//@ ; #line	"CSPBIO.PAS" 1372
//@ 		mov	ds, [bp+s1]	; uint16_t
//@ 		mov	si, [bp+o1]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1373
//@ 		mov	ax, [bp+s2]	; uint16_t
//@ 		mov	es, ax
//@ 		mov	di, [bp+o2]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1374
//@ 		mov	cx, [bp+count]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1375
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSPBIO.PAS" 1376
//@ 		rep movsd		; Move Byte(s) from String to String
//@ ; #line	"CSPBIO.PAS" 1377
//@ 		pop	ds
//@ ; #line	"CSPBIO.PAS" 1378
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ movsD$0		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1384
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ settimer	proc far		; CODE XREF: PROGRAM+C9CP DoHalt+3AP
//@ 
//@ num		= word ptr  6		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1385
//@ 		mov	al, 36h	; '6'
//@ ; #line	"CSPBIO.PAS" 1386
//@ 		out	43h, al		; Timer	8253-5 (AT: 8254.2).
//@ ; #line	"CSPBIO.PAS" 1387
//@ 		mov	ax, [bp+num]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1388
//@ 		out	40h, al		; Timer	8253-5 (AT: 8254.2).
//@ ; #line	"CSPBIO.PAS" 1389
//@ 		mov	al, ah
//@ ; #line	"CSPBIO.PAS" 1390
//@ 		out	40h, al		; Timer	8253-5 (AT: 8254.2).
//@ ; #line	"CSPBIO.PAS" 1391
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ settimer	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1395
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Beep		proc far		; CODE XREF: LoadServerPatch+144P
//@ 					; LoadServerPatch+184P
//@ 
//@ d		= word ptr  6		; uint16_t
//@ f		= word ptr  8		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1396
//@ 		push	[bp+f]		; uint16_t
//@ 		call	@Sound$q4Word	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1397
//@ 		imul	ax, [bp+d], 0Ah	; uint16_t
//@ 		push	ax
//@ 		call	@Delay$q4Word	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1398
//@ 		call	@NoSound$qv	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1399
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ Beep		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1407
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FSeek		proc far		; CODE XREF: LoadVoice+FFP
//@ 					; PlayBrifing+C0P ...
//@ 
//@ Pos		= word ptr  6		; int32_t
//@ arg_2		= word ptr  8
//@ F		= dword	ptr  0Ah	; struct BFile
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1408
//@ 		cmp	Internal, 0	; bool
//@ 		jz	short loc_2BBA0	; Jump if Zero (ZF=1)
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+80h]
//@ 		mov	dx, es:[di+82h]
//@ 		add	ax, [bp+Pos]	; int32_t
//@ 		adc	dx, [bp+arg_2]	; Add with Carry
//@ 		push	dx
//@ 		push	ax
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ 		jmp	short locret_2BBB0 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1409
//@ 
//@ loc_2BBA0:				; CODE XREF: FSeek+8j
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+arg_2]
//@ 		push	[bp+Pos]	; int32_t
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ ; #line	"CSPBIO.PAS" 1410
//@ 
//@ locret_2BBB0:				; CODE XREF: FSeek+26j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ FSeek		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1413
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FClose		proc far		; CODE XREF: LoadVoice+1EBP
//@ 					; PlayBrifing+E1P ...
//@ 
//@ F		= dword	ptr  6		; struct BFile
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		call	@Close$qm4File	; Close(var f: File)
//@ 		les	di, [bp+F]	; struct BFile
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+80h], ax
//@ 		mov	es:[di+82h], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+84h], ax
//@ 		mov	es:[di+86h], ax
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ FClose		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_21		db 3,'@##'              ; DATA XREF: FOpen+D9o FOpen+31Do
//@ aIOError	db 11,'I/O Error #'     ; DATA XREF: FOpen+C9o FOpen+30Do
//@ aFile		db 7,' (File:'          ; DATA XREF: FOpen+F5o FOpen+339o
//@ asc_2BBF8	db 1,')'                ; DATA XREF: FOpen+109o FOpen+27Eo ...
//@ aFseekErrorInFi	db 20,'FSeek error in file '
//@ aCsm_binOpenErr	db 26,'CSM.BIN Open Error. (File:' ; DATA XREF: FOpen+26Ao
//! aChasmdat	db 9,'CHASMDAT\'        ; DATA XREF: FOpen+2AEo
static const char* const CHASM_DATA_DIRECTORY = "CHASMDAT/";

static void JustFilename(char* const filename, const char* const path)
{

}

//@ ; #line	"CSPBIO.PAS" 1417
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FOpen		proc far		; CODE XREF: LoadVoice+B1P
//@ 					; PlayBrifing+B1P ...
//@ 
//@ var_404		= byte ptr -404h
//@ var_304		= byte ptr -304h
//@ var_204		= byte ptr -204h
//@ var_106		= word ptr -106h
//@ fn		= word ptr -104h	; int16_t
//@ i		= word ptr -102h	; int16_t
//@ Name		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ F		= dword	ptr  0Ah	; struct BFile
//@ 
//@ 		enter	404h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 1419
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1420
//@ 		cmp	UserMaps, 0	; bool
//@ 		jnz	short loc_2BC6C	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2BD4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1421
//@ 
//@ loc_2BC6C:				; CODE XREF: FOpen+33j
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset AddonPath ; char[41]	// Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	ExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_2BC93	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2BD4F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1423
//@ 
//@ loc_2BC93:				; CODE XREF: FOpen+5Aj
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset AddonPath ; char[41]	// Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ ; #line	"CSPBIO.PAS" 1424
//@ 		les	di, [bp+F]	; struct BFile
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+80h], ax
//@ 		mov	es:[di+82h], ax
//@ 		push	es
//@ 		push	di
//@ 		call	@FileSize$qm4File ; FileSize(var f): Longint{DX:AX}
//@ 		les	di, [bp+F]	; struct BFile
//@ 		mov	es:[di+84h], ax
//@ 		mov	es:[di+86h], dx
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		mov	[bp+i],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1425
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jz	short loc_2BD4C	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_404] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aIOError ; "I/O Error #"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_21 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aFile ; " (File:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2BBF8 ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1426
//@ 
//@ loc_2BD4C:				; CODE XREF: FOpen+C1j
//@ 		jmp	locret_2BF90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1430
//@ 
//@ loc_2BD4F:				; CODE XREF: FOpen+35j	FOpen+5Cj
//@ 		cmp	Internal, 0	; bool
//@ 		jnz	short loc_2BD59	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2BEC4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1432
//@ 
//@ loc_2BD59:				; CODE XREF: FOpen+120j
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	JustFilename	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StUpcase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1433
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	[bp+fn], 0FFFFh	; int16_t
//@ ; #line	"CSPBIO.PAS" 1434
//@ 		mov	ax, intFCnt	; uint16_t
//@ 		mov	[bp+var_106], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		jle	short loc_2BDAE	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_2BE91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2BDAE:				; CODE XREF: FOpen+175j
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_2BDB8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2BDB4:				; CODE XREF: FOpen+25Aj
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1435
//@ 
//@ loc_2BDB8:				; CODE XREF: FOpen+17Ej
//@ 		imul	ax, [bp+i], 15h	; int16_t
//@ 		les	di, FileTable	; TFileTable$Element*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_2BDD5	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2BE84	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1437
//@ 
//@ loc_2BDD5:				; CODE XREF: FOpen+19Cj
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset BaseFile ; char[81] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ ; #line	"CSPBIO.PAS" 1438
//@ 		imul	ax, [bp+i], 15h	; int16_t
//@ 		les	di, FileTable	; TFileTable$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+11h]
//@ 		mov	dx, es:[di+13h]
//@ 		les	di, [bp+F]	; struct BFile
//@ 		mov	es:[di+80h], ax
//@ 		mov	es:[di+82h], dx
//@ ; #line	"CSPBIO.PAS" 1439
//@ 		imul	ax, [bp+i], 15h	; int16_t
//@ 		les	di, FileTable	; TFileTable$Element*
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+0Dh]
//@ 		mov	dx, es:[di+0Fh]
//@ 		les	di, [bp+F]	; struct BFile
//@ 		mov	es:[di+84h], ax
//@ 		mov	es:[di+86h], dx
//@ ; #line	"CSPBIO.PAS" 1440
//@ 		push	es
//@ 		push	di
//@ 		push	word ptr es:[di+82h]
//@ 		push	word ptr es:[di+80h]
//@ 		call	@Seek$qm4File7Longint ;	Seek(var f; n: Longint)
//@ 		mov	[bp+fn], 1	; int16_t
//@ 		jmp	short loc_2BE91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1441
//@ 		db 0C4h	; ￄ
//@ 		db  7Eh	; ~
//@ 		db  0Ah
//@ 		db    6
//@ 		db  57h	; W
//@ 		db  9Ah	; ﾚ
//@ 		dd @FilePos$qm4File	; FilePos(var f): Longint{DX:AX}
//@ 		db 0C4h	; ￄ
//@ 		db  7Eh	; ~
//@ 		db  0Ah
//@ 		db  26h	; &
//@ 		db  3Bh	; ;
//@ 		db  95h	; ﾕ
//@ 		db  82h	; ﾂ
//@ 		db    0
//@ 		db  75h	; u
//@ 		db    7
//@ 		db  26h	; &
//@ 		db  3Bh	; ;
//@ 		db  85h	; ﾅ
//@ 		db  80h	; ﾀ
//@ 		db    0
//@ 		db  74h	; t
//@ 		db  20h
//@ ; #line	"CSPBIO.PAS" 1442
//@ 		db  8Dh	; ﾍ
//@ 		db 0BEh	; ﾾ
//@ 		db 0FAh	; ￺
//@ 		db 0FDh	; �
//@ 		db  16h
//@ 		db  57h	; W
//@ 		db 0BFh	; ﾿
//@ 		db  7Ah	; z
//@ 		db  0Fh
//@ 		db  0Eh
//@ 		db  57h	; W
//@ 		db  9Ah	; ﾚ
//@ 		dd @$basg$qm6Stringt1	; Load string
//@ 		db  8Dh	; ﾍ
//@ 		db 0BEh	; ﾾ
//@ 		db    0
//@ 		db 0FFh
//@ 		db  16h
//@ 		db  57h	; W
//@ 		db  9Ah	; ﾚ
//@ 		dd @Concat$qm6Stringt1	; Concat(dst, src: String): String
//@ 		db  9Ah	; ﾚ
//@ 		dd DoHalt		; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1443
//@ 
//@ loc_2BE84:				; CODE XREF: FOpen+19Ej
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		jz	short loc_2BE91	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2BDB4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1444
//@ 
//@ loc_2BE91:				; CODE XREF: FOpen+177j FOpen+213j ...
//@ 		cmp	[bp+fn], 0FFFFh	; int16_t
//@ 		jnz	short loc_2BEC1	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1445
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCsm_binOpenErr ; "CSM.BIN Open Error. (File:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2BBF8 ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1446
//@ 
//@ loc_2BEC1:				; CODE XREF: FOpen+262j
//@ 		jmp	locret_2BF90	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1448
//@ 
//@ loc_2BEC4:				; CODE XREF: FOpen+122j
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1449
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasmdat ; "CHASMDAT\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//@ ; #line	"CSPBIO.PAS" 1450
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		push	1
//@ 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
//@ ; #line	"CSPBIO.PAS" 1451
//@ 		les	di, [bp+F]	; struct BFile
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+80h], ax
//@ 		mov	es:[di+82h], ax
//@ 		push	es
//@ 		push	di
//@ 		call	@FileSize$qm4File ; FileSize(var f): Longint{DX:AX}
//@ 		les	di, [bp+F]	; struct BFile
//@ 		mov	es:[di+84h], ax
//@ 		mov	es:[di+86h], dx
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		mov	[bp+i],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1452
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jz	short locret_2BF90 ; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aIOError ; "I/O Error #"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_21 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aFile ; " (File:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2BBF8 ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1454
//@ 
//@ locret_2BF90:				; CODE XREF: FOpen:loc_2BD4Cj
//@ 					; FOpen:loc_2BEC1j ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ FOpen		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a@_22		db 3,'@##'              ; DATA XREF: TOpen+B4o TOpen+244o
//@ aIOError_0	db 11,'I/O Error #'     ; DATA XREF: TOpen+A4o TOpen+234o
//@ aFile_0		db 7,' (File:'          ; DATA XREF: TOpen+D0o TOpen+260o
//@ asc_2BFAC	db 1,')'                ; DATA XREF: TOpen+E4o TOpen+1DDo ...
//@ aCsm_binOpenE_0	db 26,'CSM.BIN Open Error. (File:' ; DATA XREF: TOpen+1C9o
//@ aChasmdat_0	db 9,'CHASMDAT\'        ; DATA XREF: TOpen+1FAo
//@ ; #line	"CSPBIO.PAS" 1458
//@ 
//! ; =============== S U B	R O U T	I N E =======================================
//! 
//! ; function far PASCAL returns void
//! ; Attributes: bp-based frame
//! 
//! TOpen		proc far		; CODE XREF: PlayBrifing+17EP
//! 					; ReloadResources+5FP ...
void TOpen(const char* const filename, FILE** externalFile)
{
//! 
//! var_404		= byte ptr -404h
//! var_304		= byte ptr -304h
//! var_204		= byte ptr -204h
//! var_106		= word ptr -106h
//! fn		= word ptr -104h	; int16_t
//! i		= word ptr -102h	; int16_t
//! Name		= byte ptr -100h	; char[256] // Pascal string
//! arg_0		= dword	ptr  6
//! F		= dword	ptr  0Ah	; Text
//! 
//! 		enter	404h, 0		; Make Stack Frame for Procedure Parameters
//! 		mov	bx, ss
//! 		mov	es, bx
//! 		mov	bx, ds
//! 		cld			; Clear	Direction Flag
//! 		lea	di, [bp+Name]	; char[256] // Pascal string
//! 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//! 		lodsb			; Load String
//! 		stosb			; Store	String
//! 		xchg	ax, cx		; Exchange Register/Memory with	Register
//! 		xor	ch, ch		; Logical Exclusive OR
//! 		rep movsb		; Move Byte(s) from String to String
//! 		mov	ds, bx
//! ; #line	"CSPBIO.PAS" 1459
//! 		lea	di, [bp+Name]	; char[256] // Pascal string
//! 		push	ss
//! 		push	di
//! 		mov	di, offset LastFName ; char[256] // Pascal string
//! 		push	ds
//! 		push	di
//! 		push	0FFh
//! 		call	@$basg$qm6Stringt14Byte	; Store	string
    strncpy(LastFName, filename, sizeof LastFName);
//! ; #line	"CSPBIO.PAS" 1460
//! 		cmp	UserMaps, 0	; bool
//! 		jnz	short loc_2C00B	; Jump if Not Zero (ZF=0)
//! 		jmp	loc_2C0C9	; Jump
    if (UserMaps)
    {
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 1461
//! 
//! loc_2C00B:				; CODE XREF: TOpen+33j
        char addonFilePath[256];
//! 		lea	di, [bp+var_204] ; Load	Effective Address
//! 		push	ss
//! 		push	di
//! 		mov	di, offset AddonPath ; char[41]	// Pascal string
//! 		push	ds
//! 		push	di
//! 		call	@$basg$qm6Stringt1 ; Load string
        strncpy(addonFilePath, AddonPath, sizeof addonFilePath - 1);
//! 		lea	di, [bp+Name]	; char[256] // Pascal string
//! 		push	ss
//! 		push	di
//! 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
        strncat(addonFilePath, filename, sizeof addonFilePath - strlen(AddonPath) - 1);
//! 		call	ExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
        if (ExistFile(addonFilePath))
        {
//! 		or	al, al		; Logical Inclusive OR
//! 		jnz	short loc_2C032	; Jump if Not Zero (ZF=0)
//! 		jmp	loc_2C0C9	; Jump
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 1463
//! 
//! loc_2C032:				; CODE XREF: TOpen+5Aj
//! 		les	di, [bp+F]	; Text
//! 		push	es
//! 		push	di
//! 		lea	di, [bp+var_304] ; Load	Effective Address
//! 		push	ss
//! 		push	di
//! 		mov	di, offset AddonPath ; char[41]	// Pascal string
//! 		push	ds
//! 		push	di
//! 		call	@$basg$qm6Stringt1 ; Load string
//! 		lea	di, [bp+Name]	; char[256] // Pascal string
//! 		push	ss
//! 		push	di
//! 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//! 		call	@Assign$qm4Textm6String	; Assign(var f:	Text; name: String)
//! ; #line	"CSPBIO.PAS" 1464
            assert(NULL != externalFile);
            *externalFile = fopen(addonFilePath, "r");
//! 		les	di, [bp+F]	; Text
//! 		push	es
//! 		push	di
//! 		call	@Reset$qm4Text	; Reset(var f: Text)
//! ; #line	"CSPBIO.PAS" 1465
//! 		call	@IOResult$qv	; IOResult: Word{AX}
//! 		mov	[bp+i],	ax	; int16_t
//! ; #line	"CSPBIO.PAS" 1466
//! 		cmp	[bp+i],	0	; int16_t
//! 		jz	short loc_2C0C6	; Jump if Zero (ZF=1)
            if (NULL == *externalFile)
            {
//@ 		lea	di, [bp+var_404] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aIOError_0 ;	"I/O Error #"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_22 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aFile_0 ; " (File:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2BFAC ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
                DoHalt("I/O Error");
            }
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 1467
//! 
//! loc_2C0C6:				; CODE XREF: TOpen+9Cj
//! 		jmp	locret_2C256	; Jump
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 1470
//! 
        }
    }
//! loc_2C0C9:				; CODE XREF: TOpen+35j	TOpen+5Cj
//! 		cmp	Internal, 0	; bool
//! 		jnz	short loc_2C0D3	; Jump if Not Zero (ZF=0)
//! 		jmp	loc_2C1C2	; Jump
    else if (Internal)
    {
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1472
//@ 
//@ loc_2C0D3:				; CODE XREF: TOpen+FBj
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	JustFilename	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StUpcase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1473
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	[bp+fn], 0FFFFh	; int16_t
//@ ; #line	"CSPBIO.PAS" 1474
//@ 		mov	ax, intFCnt	; uint16_t
//@ 		mov	[bp+var_106], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		jg	short loc_2C18F	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_2C12F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C12B:				; CODE XREF: TOpen+1BAj
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1475
//@ 
//@ loc_2C12F:				; CODE XREF: TOpen+156j
//@ 		imul	ax, [bp+i], 15h	; int16_t
//@ 		les	di, FileTable	; TFileTable$Element*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2C185	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1477
//@ 		les	di, [bp+F]	; Text
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset BaseFile ; char[81] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Assign$qm4Textm6String	; Assign(var f:	Text; name: String)
//@ 		les	di, [bp+F]	; Text
//@ 		push	es
//@ 		push	di
//@ 		call	@Reset$qm4Text	; Reset(var f: Text)
//@ ; #line	"CSPBIO.PAS" 1478
//@ 		les	di, [bp+F]	; Text
//@ 		push	es
//@ 		push	di
//@ 		imul	ax, [bp+i], 15h	; int16_t
//@ 		les	di, FileTable	; TFileTable$Element*
//@ 		add	di, ax		; Add
//@ 		push	word ptr es:[di+13h]
//@ 		push	word ptr es:[di+11h]
//@ 		call	TextSeek	; function near	PASCAL varargs returns PASCAL boolean 'Boolean'
//@ ; #line	"CSPBIO.PAS" 1479
//@ 		mov	[bp+fn], 1	; int16_t
//@ 		jmp	short loc_2C18F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1480
//@ 
//@ loc_2C185:				; CODE XREF: TOpen+174j
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		jnz	short loc_2C12B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1481
//@ 
//@ loc_2C18F:				; CODE XREF: TOpen+150j TOpen+1B0j
//@ 		cmp	[bp+fn], 0FFFFh	; int16_t
//@ 		jnz	short loc_2C1BF	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCsm_binOpenE_0 ; "CSM.BIN Open Error. (File:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2BFAC ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1482
//@ 
//@ loc_2C1BF:				; CODE XREF: TOpen+1C1j
//@ 		jmp	locret_2C256	; Jump
//@ ; ---------------------------------------------------------------------------
    }
    else
    {
//@ ; #line	"CSPBIO.PAS" 1484
//@ 
//@ loc_2C1C2:				; CODE XREF: TOpen+FDj
//@ 		les	di, [bp+F]	; Text
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasmdat_0 ; "CHASMDAT\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+Name]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	@Assign$qm4Textm6String	; Assign(var f:	Text; name: String)
//@ ; #line	"CSPBIO.PAS" 1485
//@ 		les	di, [bp+F]	; Text
//@ 		push	es
//@ 		push	di
//@ 		call	@Reset$qm4Text	; Reset(var f: Text)
//@ ; #line	"CSPBIO.PAS" 1486
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		mov	[bp+i],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1487
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jz	short locret_2C256 ; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_304] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aIOError_0 ;	"I/O Error #"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_22 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aFile_0 ; " (File:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2BFAC ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
    }
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 1489
//! 
//! locret_2C256:				; CODE XREF: TOpen:loc_2C0C6j
//! 					; TOpen:loc_2C1BFj ...
//! 		leave			; High Level Procedure Exit
//! 		retf	8		; Return Far from Procedure
//! TOpen		endp
}
//! 
//@ ; ---------------------------------------------------------------------------
//@ aChasmdat_1	db 9,'CHASMDAT\'        ; DATA XREF: FExistFile+79o
//@ ; #line	"CSPBIO.PAS" 1494
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns PASCAL boolean 'Boolean'
//@ ; Attributes: bp-based frame
//@ 
//@ FExistFile	proc far		; CODE XREF: PlayBrifing+32P
//@ 					; GetNextDemoNumber+4EP ...
//@ 
//@ var_206		= byte ptr -206h
//@ var_108		= word ptr -108h
//@ fn		= word ptr -106h	; int16_t
//@ i		= word ptr -104h	; int16_t
//@ FName		= byte ptr -102h	; char[256] // Pascal string
//@ FExistFile	= byte ptr -1		; bool
//@ arg_0		= dword	ptr  6
//@ 
//@ 		enter	206h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_0]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 1495
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	StUpcase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1496
//@ 		cmp	UserMaps, 0	; bool
//@ 		jz	short loc_2C2D0	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 1497
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset AddonPath ; char[41]	// Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	ExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_2C2D0	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 1498
//@ 		mov	[bp+FExistFile], 1 ; bool
//@ 		jmp	loc_2C366	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1500
//@ 
//@ loc_2C2D0:				; CODE XREF: FExistFile+3Fj
//@ 					; FExistFile+63j
//@ 		cmp	Internal, 0	; bool
//@ 		jnz	short loc_2C2FC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1501
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aChasmdat_1 ; "CHASMDAT\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	ExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		mov	[bp+FExistFile], al ; bool
//@ 		jmp	short loc_2C366	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1504
//@ 
//@ loc_2C2FC:				; CODE XREF: FExistFile+71j
//@ 		lea	di, [bp+var_206] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	JustFilename	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1505
//@ 		mov	[bp+fn], 0FFFFh	; int16_t
//@ 		mov	[bp+FExistFile], 0 ; bool
//@ ; #line	"CSPBIO.PAS" 1506
//@ 		mov	ax, intFCnt	; uint16_t
//@ 		mov	[bp+var_108], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jg	short loc_2C366	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_2C33E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C33A:				; CODE XREF: FExistFile+100j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1507
//@ 
//@ loc_2C33E:				; CODE XREF: FExistFile+D4j
//@ 		imul	ax, [bp+i], 15h	; int16_t
//@ 		les	di, FileTable	; TFileTable$Element*
//@ 		add	di, ax		; Add
//@ 		push	es
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2C35C	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+FExistFile], 1 ; bool
//@ 
//@ loc_2C35C:				; CODE XREF: FExistFile+F2j
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jnz	short loc_2C33A	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1509
//@ 
//@ loc_2C366:				; CODE XREF: FExistFile+69j
//@ 					; FExistFile+96j ...
//@ 		mov	al, [bp+FExistFile] ; bool
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ FExistFile	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1522
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ WriteS		proc near		; CODE XREF: ShowFinalScreen+31p
//@ 					; ShowFinalScreen+3Ep ...
//@ 
//@ S		= byte ptr -100h	; char[256] // Pascal string
//@ arg_2		= dword	ptr  6
//@ y		= byte ptr  0Ah		; int16_t
//@ x		= byte ptr  0Ch		; int16_t
//@ 
//@ 		enter	100h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ 		mov	al, [bp+x]	; int16_t
//@ 		push	ax
//@ 		mov	al, [bp+y]	; int16_t
//@ 		push	ax
//@ 		call	@GotoXY$q4Bytet1 ; function far	PASCAL returns void
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ WriteS		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aChasmTheRift_0	db 35,'            CHASM - The Rift. V1.04' ; DATA XREF: ShowFinalScreen+2Bo
//@ aCMegamediaCo_0	db 43,'      (C) Megamedia Corp, Action Forms Ltd.'
//@ 					; DATA XREF: ShowFinalScreen+38o
//@ aPublishedByMeg	db 40,'          Published by Megamedia Corp.  '
//@ 					; DATA XREF: ShowFinalScreen+45o
//@ aDevelopedByAct	db 39,'         Developed by Action Forms Ltd.'
//@ 					; DATA XREF: ShowFinalScreen+52o
//@ asc_2C451	db 73,'ￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄ'
//@ 					; DATA XREF: ShowFinalScreen+5Fo
//@ 					; ShowFinalScreen+E1o
//@ 		db 'ￄￄￄￄￄￄￄￄￄￄￄ'
//@ aProgrammingOle	db 32,' Programming      :  Oleg Slusar' ; DATA XREF: ShowFinalScreen+6Co
//@ aArtworkYarosla	db 41,' Artwork          :  Yaroslav Kravchenko,'
//@ 					; DATA XREF: ShowFinalScreen+79o
//@ aAlexeySerhiy	db 35,'                     Alexey Serhiy,' ; DATA XREF: ShowFinalScreen+86o
//@ aAlexeyPivtorak	db 36,'                     Alexey Pivtorak'
//@ 					; DATA XREF: ShowFinalScreen+93o
//@ aSfxAndMusicAle	db 29,' SFX and Music    :  Alex Kot' ; DATA XREF: ShowFinalScreen+A0o
//@ aLevelDesignYar	db 59,' Level Design     :  Yaroslav Kravchenko, Denis Vereschagin'
//@ 					; DATA XREF: ShowFinalScreen+ADo
//@ aAndreySharanev	db 58,'                     Andrey Sharanevitch, Alexey Pechenkin'
//@ 					; DATA XREF: ShowFinalScreen+BAo
//@ aDirectedByIgor	db 50,' Directed by      :  Igor Karev, Denis Vereschagin'
//@ 					; DATA XREF: ShowFinalScreen+C7o
//@ aSpecialThanksT	db 52,' Special thanks to:  Alexander Soroka, Peter M.Kolos'
//@ 					; DATA XREF: ShowFinalScreen+D4o
//@ aEMailChasm@meg	db 33,' E-mail     : chasm@megamedia.com' ; DATA XREF: ShowFinalScreen+EEo
//@ ; #line	"CSPBIO.PAS" 1524
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowFinalScreen	proc near		; CODE XREF: DoHalt+7Dp
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1525
//@ 		push	4
//@ 		push	3
//@ 		push	4Ch ; 'L'
//@ 		push	14h
//@ 		call	@Window$q4Bytet1t1t1 ; function	far PASCAL returns void
//@ 		mov	TextAttr, 70h ;	'p' ; uint8_t
//@ ; #line	"CSPBIO.PAS" 1526
//@ 		call	@ClrScr$qv	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1527
//@ 		push	1
//@ 		push	1
//@ 		push	50h ; 'P'
//@ 		push	19h
//@ 		call	@Window$q4Bytet1t1t1 ; function	far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1528
//@ 		push	0Eh
//@ 		push	4
//@ 		mov	di, offset aChasmTheRift_0 ; "		  CHASM	- The Rift. V1.04"
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1529
//@ 		push	0Eh
//@ 		push	5
//@ 		mov	di, offset aCMegamediaCo_0 ; "	    (C)	Megamedia Corp,	Action Forms "...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1530
//@ 		push	0Eh
//@ 		push	6
//@ 		mov	di, offset aPublishedByMeg ; "		Published by Megamedia Corp. "...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1531
//@ 		push	0Eh
//@ 		push	7
//@ 		mov	di, offset aDevelopedByAct ; "	       Developed by Action Forms Ltd."
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1532
//@ 		push	4
//@ 		push	8
//@ 		mov	di, offset asc_2C451 ; "ￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄ"...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1533
//@ 		push	0Ch
//@ 		push	9
//@ 		mov	di, offset aProgrammingOle ; " Programming	:  Oleg	Slusar"
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1534
//@ 		push	0Ch
//@ 		push	0Ah
//@ 		mov	di, offset aArtworkYarosla ; " Artwork		:  Yaroslav Kravchenk"...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1535
//@ 		push	0Ch
//@ 		push	0Bh
//@ 		mov	di, offset aAlexeySerhiy ; "			 Alexey	Serhiy,"
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1536
//@ 		push	0Ch
//@ 		push	0Ch
//@ 		mov	di, offset aAlexeyPivtorak ; "			   Alexey Pivtorak"
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1537
//@ 		push	0Ch
//@ 		push	0Dh
//@ 		mov	di, offset aSfxAndMusicAle ; " SFX and Music	:  Alex	Kot"
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1538
//@ 		push	0Ch
//@ 		push	0Eh
//@ 		mov	di, offset aLevelDesignYar ; " Level Design	:  Yaroslav Kravchenk"...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1539
//@ 		push	0Ch
//@ 		push	0Fh
//@ 		mov	di, offset aAndreySharanev ; "			   Andrey Sharanevitc"...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1540
//@ 		push	0Ch
//@ 		push	10h
//@ 		mov	di, offset aDirectedByIgor ; " Directed	by	:  Igor	Karev, Denis "...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1541
//@ 		push	0Ch
//@ 		push	11h
//@ 		mov	di, offset aSpecialThanksT ; " Special thanks to:  Alexander Soroka, "...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1542
//@ 		push	4
//@ 		push	12h
//@ 		mov	di, offset asc_2C451 ; "ￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄￄ"...
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1543
//@ 		push	0Ch
//@ 		push	13h
//@ 		mov	di, offset aEMailChasm@meg ; " E-mail	  : chasm@megamedia.com"
//@ 		push	cs
//@ 		push	di
//@ 		push	bp
//@ 		call	WriteS		; function nested near PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1544
//@ 		push	1
//@ 		push	18h
//@ 		call	@GotoXY$q4Bytet1 ; function far	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1545
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ ShowFinalScreen	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1548
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Wait_R		proc near		; CODE XREF: FadeOut+7Ep FadeIn+85p
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1549
//@ 
//@ loc_2C753:				; CODE XREF: Wait_R+14j
//@ 		mov	dx, 3DAh
//@ 		in	al, dx		; Video	status bits:
//@ 					; 0: retrace.  1=display is in vert or horiz retrace.
//@ 					; 1: 1=light pen is triggered; 0=armed
//@ 					; 2: 1=light pen switch	is open; 0=closed
//@ 					; 3: 1=vertical	sync pulse is occurring.
//@ 		and	al, 8		; Logical AND
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short locret_2C766 ; Jump if Not Zero (ZF=0)
//@ 		cmp	CurTime, 4	; uint16_t
//@ 		jnb	short locret_2C766 ; Jump if Not Below (CF=0)
//@ 		jmp	short loc_2C753	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1551
//@ 
//@ locret_2C766:				; CODE XREF: Wait_R+Bj	Wait_R+12j
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ Wait_R		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1564
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FadeOut		proc far		; CODE XREF: PlayBrifing+40P
//@ 					; PlayBrifing+528P
//@ 
//@ j		= word ptr -304h	; int16_t
//@ i		= word ptr -302h	; int16_t
//@ pal2		= byte ptr -300h	; int8_t[768]
//@ NFrames		= word ptr  6		; int16_t
//@ 
//@ 		enter	306h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1565
//@ 		mov	ax, [bp+NFrames] ; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jge	short loc_2C777	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	locret_2C7FB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C777:				; CODE XREF: FadeOut+Aj
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2C780	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C77C:				; CODE XREF: FadeOut+91j
//@ 		dec	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 1567
//@ 
//@ loc_2C780:				; CODE XREF: FadeOut+12j
//@ 		mov	[bp+i],	1	; int16_t
//@ 		jmp	short loc_2C78C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C788:				; CODE XREF: FadeOut+70j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1568
//@ 
//@ loc_2C78C:				; CODE XREF: FadeOut+1Ej
//@ 		mov	[bp+j],	1	; int16_t
//@ 		jmp	short loc_2C798	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C794:				; CODE XREF: FadeOut+68j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1569
//@ 
//@ loc_2C798:				; CODE XREF: FadeOut+2Aj
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		mov	di, [bp+i]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	al, [di-20A4h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mul	n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+NFrames]	; int16_t
//@ 		mov	dl, al
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		mov	di, [bp+i]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr [bp+di+j], dl ; int16_t
//@ 		cmp	[bp+j],	3	; int16_t
//@ 		jnz	short loc_2C794	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+i],	100h	; int16_t
//@ 		jnz	short loc_2C788	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1570
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ 
//@ loc_2C7DF:				; CODE XREF: FadeOut+7Cj
//@ 		cmp	CurTime, 0	; uint16_t
//@ 		jbe	short loc_2C7DF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		call	Wait_R		; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1571
//@ 		lea	di, [bp+pal2]	; int8_t[768]
//@ 		push	ss
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1572
//@ 		cmp	n$0, 0		; int16_t
//@ 		jnz	short loc_2C77C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1573
//@ 
//@ locret_2C7FB:				; CODE XREF: FadeOut+Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ FadeOut		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1578
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FadeIn		proc far		; CODE XREF: PlayBrifing+499P
//@ 
//@ var_308		= word ptr -308h
//@ j		= word ptr -304h	; int16_t
//@ i		= word ptr -302h	; int16_t
//@ pal2		= byte ptr -300h	; int8_t[768]
//@ NFrames		= word ptr  6		; int16_t
//@ 
//@ 		enter	308h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1579
//@ 		mov	ax, [bp+NFrames] ; int16_t
//@ 		mov	[bp+var_308], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_308] ; Compare Two Operands
//@ 		jle	short loc_2C815	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_2C89E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C815:				; CODE XREF: FadeIn+11j
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2C81E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C81A:				; CODE XREF: FadeIn+9Cj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 1581
//@ 
//@ loc_2C81E:				; CODE XREF: FadeIn+19j
//@ 		mov	[bp+i],	1	; int16_t
//@ 		jmp	short loc_2C82A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C826:				; CODE XREF: FadeIn+77j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1582
//@ 
//@ loc_2C82A:				; CODE XREF: FadeIn+25j
//@ 		mov	[bp+j],	1	; int16_t
//@ 		jmp	short loc_2C836	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2C832:				; CODE XREF: FadeIn+6Fj
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1583
//@ 
//@ loc_2C836:				; CODE XREF: FadeIn+31j
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		mov	di, [bp+i]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	al, [di-20A4h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mul	n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		idiv	[bp+NFrames]	; int16_t
//@ 		mov	dl, al
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		mov	di, [bp+i]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	byte ptr [bp+di+j], dl ; int16_t
//@ 		cmp	[bp+j],	3	; int16_t
//@ 		jnz	short loc_2C832	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+i],	100h	; int16_t
//@ 		jnz	short loc_2C826	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1584
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	CurTime, ax	; uint16_t
//@ 
//@ loc_2C87D:				; CODE XREF: FadeIn+83j
//@ 		cmp	CurTime, 0	; uint16_t
//@ 		jbe	short loc_2C87D	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		call	Wait_R		; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1585
//@ 		lea	di, [bp+pal2]	; int8_t[768]
//@ 		push	ss
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1586
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, [bp+var_308] ; Compare Two Operands
//@ 		jz	short locret_2C89E ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2C81A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1587
//@ 
//@ locret_2C89E:				; CODE XREF: FadeIn+13j FadeIn+9Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ FadeIn		endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aNquit_0	db 5,'NQUIT'            ; DATA XREF: DoHalt+71o
//@ ; #line	"CSPBIO.PAS" 1611
//@ 
//! ; =============== S U B	R O U T	I N E =======================================
//!
//! ; function far PASCAL returns void
//! ; Attributes: noreturn bp-based	frame
//!
//! DoHalt		proc near		; CODE XREF: AnimateSwitches+69P
//! 					; CheckQuit+244P ...
//!
void DoHalt(const char* const message)
{
//@ Mess		= byte ptr -100h	; char[256] // Pascal string
//@ arg_2		= dword	ptr  6
//@ 
//@ 		enter	100h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+Mess]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 1612
//@ 		mov	ax, word ptr KbdInt ; void (*)()
//@ 		or	ax, word ptr KbdInt+2 ;	void (*)()
//@ 		jz	short loc_2C8DB	; Jump if Zero (ZF=1)
//@ 		push	9
//@ 		push	word ptr KbdInt+2 ; void (*)()
//@ 		push	word ptr KbdInt	; void (*)()
//@ 		call	@SetIntVec$q4Byte7Pointer ; function far PASCAL	returns	void
//@ ; #line	"CSPBIO.PAS" 1613
//@ 
//@ loc_2C8DB:				; CODE XREF: DoHalt+22j
//@ 		call	DeInitSoundSystem ; function far PASCAL	returns	void
//@ ; #line	"CSPBIO.PAS" 1617
//@ 		push	0
//@ 		call	settimer	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1618
//@ 		mov	ax, word ptr TimerInt ;	void (*)()
//@ 		or	ax, word ptr TimerInt+2	; void (*)()
//@ 		jz	short loc_2C8FF	; Jump if Zero (ZF=1)
//@ 		push	8
//@ 		push	word ptr TimerInt+2 ; void (*)()
//@ 		push	word ptr TimerInt ; void (*)()
//@ 		call	@SetIntVec$q4Byte7Pointer ; function far PASCAL	returns	void
//@ ; #line	"CSPBIO.PAS" 1619
//@ 
//@ loc_2C8FF:				; CODE XREF: DoHalt+46j
//@ 		sti			; Set Interrupt	Flag
//@ 		mov	ax, 3
//@ 		int	10h		; - VIDEO - SET	VIDEO MODE
//@ 					; AL = mode
//@ ; #line	"CSPBIO.PAS" 1620
//@ 		mov	TextAttr, 7	; uint8_t
//@ ; #line	"CSPBIO.PAS" 1622
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short $+2	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 1623
//@ 		lea	di, [bp+Mess]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aNquit_0 ; "NQUIT"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2C92A	; Jump if Not Zero (ZF=0)
//@ 		call	ShowFinalScreen	; function near	PASCAL returns void
//@ 		jmp	short loc_2C941	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1624
//@ 
//@ loc_2C92A:				; CODE XREF: DoHalt+7Bj
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+Mess]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
	puts(message);
//@ ; #line	"CSPBIO.PAS" 1625
//@ 
//@ loc_2C941:				; CODE XREF: DoHalt+80j DoHalt+A7j
//@ 		call	@KeyPressed$qv	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jz	short loc_2C951	; Jump if Zero (ZF=1)
//@ 		call	@ReadKey$qv	; function far PASCAL returns PASCAL character 'Char'
//@ 		jmp	short loc_2C941	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1626
//@ 
//@ loc_2C951:				; CODE XREF: DoHalt+A0j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		call	far ptr	@Halt$q4Word ; Halt(exitcode: Word{AX})
	exit(EXIT_SUCCESS);
}
//! DoHalt		endp
//!
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1627
//@ 		db 0C9h	; ￉
//@ 		db 0CAh	; ￊ
//@ 		db    4
//@ 		db    0
//@ a@_23		db 3,'@##'              ; DATA XREF: ChI+28o
//@ aIOError_1	db 11,'I/O Error #'     ; DATA XREF: ChI+18o
//@ aFile_1		db 7,' (File:'          ; DATA XREF: ChI+43o
//@ asc_2C974	db 1,')'                ; DATA XREF: ChI+57o
//@ ; #line	"CSPBIO.PAS" 1631
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ChI		proc far		; CODE XREF: LoadConfig+50P
//@ 					; LoadConfig+2B0P ...
//@ 
//@ var_202		= byte ptr -202h
//@ var_102		= byte ptr -102h
//@ i		= word ptr -2		; int16_t
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1632
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		mov	[bp+i],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1633
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jz	short locret_2C9DC ; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aIOError_1 ;	"I/O Error #"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_23 ; "@##"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aFile_1 ; " (File:"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2C974 ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1634
//@ 
//@ locret_2C9DC:				; CODE XREF: ChI+10j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ChI		endp
//@ 
//! ; ---------------------------------------------------------------------------
//! a@_24		db 2,'@#'               ; DATA XREF: GetMem16+4Eo GetMem16+7Do ...
//! aMemoryAllocati	db 36,'Memory allocation error.  (Request: ' ; DATA XREF: GetMem16+3Eo
//! aAvailable	db 12,' Available: '    ; DATA XREF: GetMem16+6Do
//! asc_2CA13	db 1,'('                ; DATA XREF: GetMem16+A3o
//! asc_2CA15	db 1,')'                ; DATA XREF: GetMem16+D9o
//! aInternalMemory	db 33,'Internal memory allocation error.' ; DATA XREF: GetMem16+103o
//! ; #line	"CSPBIO.PAS" 1639
//!
//! ; =============== S U B	R O U T	I N E =======================================
//!
//! ; function far PASCAL returns void
//! ; Attributes: bp-based frame
//!
//! GetMem16	proc far		; CODE XREF: ConnectIPXProcessor+91P
//! 					; LoadVoice+178P ...
//!
void* GetMem16(const uint16_t size)
{
//@ var_400		= byte ptr -400h
//@ var_300		= byte ptr -300h
//@ var_200		= byte ptr -200h
//@ var_100		= byte ptr -100h
//@ size		= word ptr  6		; uint16_t
//@ p		= dword	ptr  8
//@ 
//@ 		enter	400h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1640
//@ 		cmp	[bp+size], 400h	; uint16_t
//@ 		jnb	short loc_2CA49	; Jump if Not Below (CF=0)
//@ 		mov	[bp+size], 400h	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1641
//@ 
//@ loc_2CA49:				; CODE XREF: GetMem16+9j
//@ 		add	word ptr mem0, 1 ; int32_t
//@ 		adc	word ptr mem0+2, 0 ; int32_t
//@ ; #line	"CSPBIO.PAS" 1642
//@ 		call	@MaxAvail$qv	; MaxAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+size]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_2CA71	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jge	short loc_2CA6A	; Jump if Greater or Equal (SF=OF)
//@ 		jmp	loc_2CB21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2CA6A:				; CODE XREF: GetMem16+2Cj
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		ja	short loc_2CA71	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_2CB21	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1643
//@ 
//@ loc_2CA71:				; CODE XREF: GetMem16+2Aj GetMem16+33j
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aMemoryAllocati ; "Memory allocation	error.	(Request: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_100] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_24 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, [bp+size]	; uint16_t
//@ 		shr	ax, 0Ah		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aAvailable ;	" Available: "
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_24 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2CA13 ; "("
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+var_400] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_24 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		call	@MaxAvail$qv	; MaxAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset asc_2CA15 ; ")"
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1646
//@ 
//@ loc_2CB21:				; CODE XREF: GetMem16+2Ej GetMem16+35j
//@ 		push	[bp+size]	; uint16_t
//@ 		call	@GetMem$q4Word	; GetMem(var p:	Pointer{DX:AX};	size: Word)
//@ 		les	di, [bp+p]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], dx
//@ ; #line	"CSPBIO.PAS" 1647
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, di
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short locret_2CB46 ; Jump if Zero (ZF=1)
//@ 		mov	di, offset aInternalMemory ; "Internal memory allocation error."
//@ 		push	cs
//@ 		push	di
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1648
//@ 
//@ locret_2CB46:				; CODE XREF: GetMem16+101j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure

	void* const result = malloc(size);

	if (NULL == result)
	{
		DoHalt("Internal memory allocation error.");
	}

	return result;
}
//! GetMem16	endp
//! 
//@ ; #line	"CSPBIO.PAS" 1662
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FreeMem16	proc far		; CODE XREF: DeInitBrifing+CP
//@ 					; DeInitBrifing+43P ...
//@ 
//@ size		= word ptr  6		; uint16_t
//@ p		= dword	ptr  8
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1663
//@ 		cmp	[bp+size], 400h	; uint16_t
//@ 		jnb	short loc_2CB59	; Jump if Not Below (CF=0)
//@ 		mov	[bp+size], 400h	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1664
//@ 
//@ loc_2CB59:				; CODE XREF: FreeMem16+8j
//@ 		les	di, [bp+p]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+2]
//@ 		push	word ptr es:[di]
//@ 		push	[bp+size]	; uint16_t
//@ 		call	@FreeMem$qm7Pointer4Word ; FreeMem(var p: Pointer; size: Word)
//@ ; #line	"CSPBIO.PAS" 1665
//@ 		les	di, [bp+p]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSPBIO.PAS" 1666
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ FreeMem16	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1671
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CalcDir		proc far		; CODE XREF: ReinitPlayer+141P
//@ 					; LoadServerPatch+28BP	...
//@ 
//@ DFi		= word ptr  6		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 1672
//@ 		mov	ax, [bp+DFi]	; int16_t
//@ 		add	ax, [bp+DFi]	; int16_t
//@ 		add	HFi, ax		; uint16_t
//@ ; #line	"CSPBIO.PAS" 1673
//@ 		mov	ax, HFi		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; 'ﾂ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; 'ﾑ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	word ptr sa, ax	; real_t
//@ 		mov	word ptr sa+2, bx ; real_t
//@ 		mov	word ptr sa+4, dx ; real_t
//@ ; #line	"CSPBIO.PAS" 1674
//@ 		mov	ax, HFi		; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; 'ﾂ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 91h	; 'ﾑ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	far ptr	@Sin$q4Real ; Sin(x: Real): Real
//@ 		mov	word ptr ca, ax	; real_t
//@ 		mov	word ptr ca+2, bx ; real_t
//@ 		mov	word ptr ca+4, dx ; real_t
//@ ; #line	"CSPBIO.PAS" 1688
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ CalcDir		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1693
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ Max		proc far		; CODE XREF: ProcessDevices+665P
//@ 					; ProcessDevices+6AAP ...
//@ 
//@ Max		= word ptr -2		; int16_t
//@ i2		= word ptr  6		; int16_t
//@ i1		= word ptr  8		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	ax, [bp+i1]	; int16_t
//@ 		cmp	ax, [bp+i2]	; int16_t
//@ 		jle	short loc_2CC20	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+i1]	; int16_t
//@ 		mov	[bp+Max], ax	; int16_t
//@ 		jmp	short loc_2CC26	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2CC20:				; CODE XREF: Max+Aj
//@ 		mov	ax, [bp+i2]	; int16_t
//@ 		mov	[bp+Max], ax	; int16_t
//@ 
//@ loc_2CC26:				; CODE XREF: Max+12j
//@ 		mov	ax, [bp+Max]	; int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ Max		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1696
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns signed int 'Integer'
//@ ; Attributes: bp-based frame
//@ 
//@ Min		proc far		; CODE XREF: DoGame+478P DoGame+693P ...
//@ 
//@ Min		= word ptr -2		; int16_t
//@ i2		= word ptr  6		; int16_t
//@ i1		= word ptr  8		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	ax, [bp+i1]	; int16_t
//@ 		cmp	ax, [bp+i2]	; int16_t
//@ 		jge	short loc_2CC41	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+i1]	; int16_t
//@ 		mov	[bp+Min], ax	; int16_t
//@ 		jmp	short loc_2CC47	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2CC41:				; CODE XREF: Min+Aj
//@ 		mov	ax, [bp+i2]	; int16_t
//@ 		mov	[bp+Min], ax	; int16_t
//@ 
//@ loc_2CC47:				; CODE XREF: Min+12j
//@ 		mov	ax, [bp+Min]	; int16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ Min		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1699
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns signed char 'Shortint'
//@ ; Attributes: bp-based frame
//@ 
//@ Sgn		proc far		; CODE XREF: EndPaint+22CP
//@ 					; AnimateMonsters+C2FP	...
//@ 
//@ Sgn		= byte ptr -1		; int8_t
//@ i		= word ptr  6		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ 		cmp	[bp+i],	0	; int16_t
//@ 		jge	short loc_2CC5E	; Jump if Greater or Equal (SF=OF)
//@ 		mov	[bp+Sgn], 0FFh	; int8_t
//@ 		jmp	short loc_2CC62	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2CC5E:				; CODE XREF: Sgn+8j
//@ 		mov	[bp+Sgn], 1	; int8_t
//@ 
//@ loc_2CC62:				; CODE XREF: Sgn+Ej
//@ 		mov	al, [bp+Sgn]	; int8_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ Sgn		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1705
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetCurPicTo	proc far		; CODE XREF: ExpandBlow+73P
//@ 
//@ PBase		= word ptr -8		; int32_t
//@ var_6		= word ptr -6
//@ pofs		= word ptr -4		; uint16_t
//@ o		= word ptr -2		; uint16_t
//@ NFr		= word ptr  6		; uint16_t
//@ FRP		= dword	ptr  8		; struct TPicPack
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1706
//@ 		mov	ax, [bp+NFr]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+2]
//@ 		mov	[bp+o],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1707
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		les	di, es:[di+32h]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	CurPic.XSize, ax ; struct TPic
//@ ; #line	"CSPBIO.PAS" 1708
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		les	di, es:[di+32h]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	CurPic.YSize, ax ; struct TPic
//@ ; #line	"CSPBIO.PAS" 1709
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		add	ax, 4		; Add
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		les	di, es:[di+32h]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	CurPic.CenterX,	ax ; struct TPic
//@ ; #line	"CSPBIO.PAS" 1710
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		add	ax, 6		; Add
//@ 		mov	[bp+pofs], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1711
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		les	di, es:[di+32h]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		call	GetSelectorBase	; Call Procedure
//@ 		mov	[bp+PBase], ax	; int32_t
//@ 		mov	[bp+var_6], dx
//@ ; #line	"CSPBIO.PAS" 1712
//@ 		mov	ax, [bp+pofs]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	[bp+PBase], ax	; int32_t
//@ 		adc	[bp+var_6], dx	; Add with Carry
//@ ; #line	"CSPBIO.PAS" 1713
//@ 		push	CurPicSeg	; uint16_t
//@ 		push	[bp+var_6]
//@ 		push	[bp+PBase]	; int32_t
//@ 		call	SetSelectorBase	; Call Procedure
//@ ; #line	"CSPBIO.PAS" 1714
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	dx, CurPicSeg	; uint16_t
//@ 		mov	word ptr CurPic.p, ax ;	struct TPic
//@ 		mov	word ptr CurPic.p+2, dx	; struct TPic
//@ ; #line	"CSPBIO.PAS" 1715
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ SetCurPicTo	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1720
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadPic		proc far		; CODE XREF: LoadBMPObjects+16FP
//@ 
//@ var_4		= dword	ptr -4
//@ Pc		= dword	ptr  6		; struct TPic
//@ F		= dword	ptr  0Ah	; struct BFile
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1721
//@ 		les	di, [bp+Pc]	; struct TPic
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPBIO.PAS" 1723
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1724
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 2		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1725
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1726
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 6		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		mul	word ptr es:[di+2] ; Unsigned Multiplication of	AL or AX
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1727
//@ 		les	di, [bp+F]	; struct BFile
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		mul	word ptr es:[di+2] ; Unsigned Multiplication of	AL or AX
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1729
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ LoadPic		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1737
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadPicsPacket	proc near		; CODE XREF: LoadBlows+15Ap
//@ 
//@ var_194		= word ptr -194h
//@ var_192		= dword	ptr -192h
//@ F		= byte ptr -18Eh	; struct BFile
//@ var_10A		= word ptr -10Ah
//@ var_108		= word ptr -108h
//@ k		= word ptr -106h	; uint16_t
//@ N		= word ptr -104h	; uint16_t
//@ Sz		= word ptr -102h	; uint16_t
//@ S		= byte ptr -100h	; char[256] // Pascal string
//@ FRP		= dword	ptr  4		; struct TPicPack
//@ arg_4		= dword	ptr  8
//@ 
//@ 		enter	194h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_4]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 1738
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+S]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1739
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1740
//@ 		mov	ax, [bp+var_10A]
//@ 		mov	dx, [bp+var_108]
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	[bp+Sz], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1741
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		add	di, 32h	; '2'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+Sz]		; uint16_t
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1742
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		les	di, es:[di+32h]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+Sz]		; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1743
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1744
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		add	di, 2		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	30h ; '0'
//@ 		push	0FFFFh
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSPBIO.PAS" 1745
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+k],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1746
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		mov	word ptr [bp+var_192], di
//@ 		mov	word ptr [bp+var_192+2], es
//@ ; #line	"CSPBIO.PAS" 1747
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		mov	ax, es:[di]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_194], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_194] ; Compare Two Operands
//@ 		ja	short locret_2CEC9 ; Jump if Above (CF=0 & ZF=0)
//@ 		mov	[bp+N],	ax	; uint16_t
//@ 		jmp	short loc_2CE6B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2CE67:				; CODE XREF: LoadPicsPacket+12Ej
//@ 		inc	[bp+N]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 1749
//@ 
//@ loc_2CE6B:				; CODE XREF: LoadPicsPacket+CCj
//@ 		mov	dx, [bp+k]	; uint16_t
//@ 		mov	ax, [bp+N]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_192] ; Load	Full Pointer to	ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+2], dx
//@ ; #line	"CSPBIO.PAS" 1750
//@ 		les	di, [bp+FRP]	; struct TPicPack
//@ 		mov	ax, es:[di]
//@ 		dec	ax		; Decrement by 1
//@ 		cmp	ax, [bp+N]	; uint16_t
//@ 		jbe	short loc_2CEBF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPBIO.PAS" 1751
//@ 		mov	ax, [bp+k]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		les	di, [bp+var_192] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di+32h]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+k]	; uint16_t
//@ 		les	di, [bp+var_192] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di+32h]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	al, es:[di]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mul	dx		; Unsigned Multiplication of AL	or AX
//@ 		add	ax, 6		; Add
//@ 		add	[bp+k],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1752
//@ 
//@ loc_2CEBF:				; CODE XREF: LoadPicsPacket+F1j
//@ 		mov	ax, [bp+N]	; uint16_t
//@ 		cmp	ax, [bp+var_194] ; Compare Two Operands
//@ 		jnz	short loc_2CE67	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1753
//@ 
//@ locret_2CEC9:				; CODE XREF: LoadPicsPacket+C6j
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ LoadPicsPacket	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aAni_1		db 5,'\ani\'            ; DATA XREF: LoadAnimation:loc_2CF6Co
//@ aAni_2		db 4,'ANI\'             ; DATA XREF: LoadAnimation+72o
//@ aAnimationAndMo	db 59,'Animation and Model file contain different vertexes count. '
//@ 					; DATA XREF: LoadAnimation+D9o
//@ ; #line	"CSPBIO.PAS" 1764
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadAnimation	proc far		; CODE XREF: LoadCharacter+175P
//@ 					; LoadCharacter+200P ...
//@ 
//@ var_28A		= byte ptr -28Ah
//@ VC		= word ptr -18Ah	; uint16_t
//@ F		= byte ptr -188h	; struct BFile
//@ var_104		= word ptr -104h
//@ var_102		= word ptr -102h
//@ AName		= byte ptr -100h	; char[256] // Pascal string
//@ ATime		= dword	ptr  6		; uint16_t
//@ PAni		= dword	ptr  0Ah	; TPoint3di*
//@ VCount		= word ptr  0Eh		; int16_t
//@ arg_A		= dword	ptr  10h
//@ 
//@ 		enter	28Ah, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+AName]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_A]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 1765
//@ 		les	di, [bp+ATime]	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		les	di, [bp+PAni]	; TPoint3di*
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSPBIO.PAS" 1766
//@ 		lea	di, [bp+var_28A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+AName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+AName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1767
//@ 		cmp	[bp+AName], 0	; char[256] // Pascal string
//@ 		jnz	short loc_2CF6C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2D0B0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1768
//@ 
//@ loc_2CF6C:				; CODE XREF: LoadAnimation+53j
//@ 		mov	di, offset aAni_1 ; "\\ani\\"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+AName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jnz	short loc_2CFA9	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_28A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aAni_2 ; "ANI\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+AName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+AName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1769
//@ 
//@ loc_2CFA9:				; CODE XREF: LoadAnimation+6Aj
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+AName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1771
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+VC]	; uint16_t
//@ 		push	ss
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1772
//@ 		mov	ax, [bp+VCount]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+VC]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jnz	short loc_2CFE7	; Jump if Not Zero (ZF=0)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jz	short loc_2D006	; Jump if Zero (ZF=1)
//@ 
//@ loc_2CFE7:				; CODE XREF: LoadAnimation+CDj
//@ 		lea	di, [bp+var_28A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aAnimationAndMo ; "Animation	and Model file contain differ"...
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset LastFName ; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	far ptr	DoHalt	; function far PASCAL returns void
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1773
//@ 
//@ loc_2D006:				; CODE XREF: LoadAnimation+D1j
//@ 		mov	ax, [bp+var_104]
//@ 		mov	dx, [bp+var_102]
//@ 		sub	ax, 2		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, 6
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+VC], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1774
//@ 		mov	ax, [bp+VCount]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+VC]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	cx, 3
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brlsh$q7Longint7Integer ; X1{DX:AX}<<=N{CX}
//@ 		les	di, [bp+ATime]	; uint16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1775
//@ 		les	di, [bp+PAni]	; TPoint3di*
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+VC]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1776
//@ 		les	di, [bp+PAni]	; TPoint3di*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		mov	ax, [bp+VC]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, 4		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1777
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+PAni]	; TPoint3di*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+VC]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1778
//@ 		lea	di, [bp+F]	; struct BFile
//@ 		push	ss
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1779
//@ 
//@ locret_2D0B0:				; CODE XREF: LoadAnimation+55j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ LoadAnimation	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aModels		db 7,'MODELS\'          ; DATA XREF: LoadPOH+5Do
//@ ; #line	"CSPBIO.PAS" 1784
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadPOH		proc far		; CODE XREF: LoadCharacter+A8P
//@ 					; UpLoad3dObjects+227P	...
//@ 
//@ var_204		= byte ptr -204h
//@ var_10A		= dword	ptr -10Ah
//@ var_106		= word ptr -106h
//@ b		= byte ptr -103h	; uint8_t
//@ n		= word ptr -102h	; int16_t
//@ MName		= byte ptr -100h	; char[256] // Pascal string
//@ POH		= dword	ptr  6		; TOHeader*
//@ arg_4		= dword	ptr  0Ah
//@ 
//@ 		enter	204h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+MName]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_4]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 1785
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSPBIO.PAS" 1786
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+MName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+MName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1787
//@ 		cmp	[bp+MName], 0	; char[256] // Pascal string
//@ 		jnz	short loc_2D10C	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2D2E4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1788
//@ 
//@ loc_2D10C:				; CODE XREF: LoadPOH+4Bj
//@ 		cmp	[bp+MName], 0Ch	; char[256] // Pascal string
//@ 		ja	short loc_2D13C	; Jump if Above	(CF=0 &	ZF=0)
//@ 		lea	di, [bp+var_204] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aModels ; "MODELS\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+MName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+MName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 1789
//@ 
//@ loc_2D13C:				; CODE XREF: LoadPOH+55j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+MName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1790
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1791
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1792
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	4806h
//@ 		mov	di, offset w	; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1793
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4804h]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4804h], ax
//@ ; #line	"CSPBIO.PAS" 1794
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4804h],	0 ; Compare Two	Operands
//@ 		jbe	short loc_2D201	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPBIO.PAS" 1796
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		add	di, 4806h	; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4804h]
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1797
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+4806h] ; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1798
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+4806h] ; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4804h]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1800
//@ 
//@ loc_2D201:				; CODE XREF: LoadPOH+ECj
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1802
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+4802h],	0 ; Compare Two	Operands
//@ 		ja	short loc_2D221	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	locret_2D2E4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1803
//@ 
//@ loc_2D221:				; CODE XREF: LoadPOH+160j
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4802h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_106], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		jle	short loc_2D23C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_2D2E4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D23C:				; CODE XREF: LoadPOH+17Bj
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2D246	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D242:				; CODE XREF: LoadPOH+225j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1804
//@ 
//@ loc_2D246:				; CODE XREF: LoadPOH+184j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10A], di
//@ 		mov	word ptr [bp+var_10A+2], es
//@ ; #line	"CSPBIO.PAS" 1806
//@ 		mov	al, es:[di+1Dh]
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+b],	al	; uint8_t
//@ ; #line	"CSPBIO.PAS" 1807
//@ 		cmp	[bp+b],	0	; uint8_t
//@ 		jz	short loc_2D287	; Jump if Zero (ZF=1)
//@ 		mov	al, [bp+b]	; uint8_t
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		dec	ax		; Decrement by 1
//@ 		mov	dx, ax
//@ 		mov	ax, 1
//@ 		mov	cx, dx
//@ 		shl	ax, cl		; Shift	Logical	Left
//@ 		mov	es:[di+1Ch], al
//@ 		jmp	short loc_2D290	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D287:				; CODE XREF: LoadPOH+1B3j
//@ 		les	di, [bp+var_10A] ; Load	Full Pointer to	ES:xx
//@ 		mov	byte ptr es:[di+1Ch], 0
//@ ; #line	"CSPBIO.PAS" 1808
//@ 
//@ loc_2D290:				; CODE XREF: LoadPOH+1C9j
//@ 		les	di, [bp+var_10A] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+1Eh]
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	es:[di+1Eh], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	i$0, ax		; int16_t
//@ 		jmp	short loc_2D2AA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D2A6:				; CODE XREF: LoadPOH+219j
//@ 		inc	i$0		; int16_t
//@ 
//@ loc_2D2AA:				; CODE XREF: LoadPOH+1E8j
//@ 		mov	ax, i$0		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_10A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 80h	; 'ﾀ'   ; Add
//@ 		mov	dx, ax
//@ 		mov	ax, i$0		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_10A] ; Load	Full Pointer to	ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+8], dx
//@ 		cmp	i$0, 7		; int16_t
//@ 		jnz	short loc_2D2A6	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1809
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_106] ; Compare Two Operands
//@ 		jz	short locret_2D2E4 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2D242	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1810
//@ 
//@ locret_2D2E4:				; CODE XREF: LoadPOH+4Dj LoadPOH+162j	...
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ LoadPOH		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1819
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScanLoHi	proc far		; CODE XREF: UpLoad3dObjects+2A8P
//@ 					; InitCaracter+146P ...
//@ 
//@ var_8		= word ptr -8
//@ var_6		= dword	ptr -6
//@ n		= word ptr -2		; uint16_t
//@ HiZ		= dword	ptr  6		; int16_t
//@ LoZ		= dword	ptr  0Ah	; int16_t
//@ POH		= dword	ptr  0Eh	; TOHeader*
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1820
//@ 		les	di, [bp+LoZ]	; int16_t
//@ 		mov	word ptr es:[di], 2710h
//@ ; #line	"CSPBIO.PAS" 1821
//@ 		les	di, [bp+HiZ]	; int16_t
//@ 		mov	word ptr es:[di], 0D8F0h
//@ ; #line	"CSPBIO.PAS" 1822
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		mov	word ptr [bp+var_6], di
//@ 		mov	word ptr [bp+var_6+2], es
//@ ; #line	"CSPBIO.PAS" 1823
//@ 		mov	ax, es:[di+4800h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_8], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jbe	short loc_2D318	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2D398	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D318:				; CODE XREF: ScanLoHi+2Bj
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2D320	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D31D:				; CODE XREF: ScanLoHi+AEj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 1825
//@ 
//@ loc_2D320:				; CODE XREF: ScanLoHi+33j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+3204h]
//@ 		les	di, [bp+LoZ]	; int16_t
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jge	short loc_2D358	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+3204h]
//@ 		les	di, [bp+LoZ]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1826
//@ 
//@ loc_2D358:				; CODE XREF: ScanLoHi+53j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+3204h]
//@ 		les	di, [bp+HiZ]	; int16_t
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jle	short loc_2D390	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, [bp+var_6]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+3204h]
//@ 		les	di, [bp+HiZ]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1827
//@ 
//@ loc_2D390:				; CODE XREF: ScanLoHi+8Bj
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jnz	short loc_2D31D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1828
//@ 
//@ loc_2D398:				; CODE XREF: ScanLoHi+2Dj
//@ 		les	di, [bp+LoZ]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		sub	ax, 60h	; '`'   ; Integer Subtraction
//@ 		mov	es:[di], ax
//@ 		cmp	word ptr es:[di], 0 ; Compare Two Operands
//@ 		jge	short loc_2D3AF	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1829
//@ 
//@ loc_2D3AF:				; CODE XREF: ScanLoHi+C0j
//@ 		les	di, [bp+HiZ]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1830
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ ScanLoHi	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1835
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScanWH		proc near		; CODE XREF: InitCaracter+12Ep
//@ 
//@ var_C		= dword	ptr -0Ch
//@ var_8		= word ptr -8
//@ wy		= word ptr -6		; uint16_t
//@ wx		= word ptr -4		; uint16_t
//@ n		= word ptr -2		; uint16_t
//@ H		= dword	ptr  4		; int16_t
//@ W		= dword	ptr  8		; int16_t
//@ POH		= dword	ptr  0Ch	; TOHeader*
//@ 
//@ 		enter	0Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1836
//@ 		les	di, [bp+H]	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+wx], ax	; uint16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+wy], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1837
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		mov	ax, es:[di+4800h]
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_8], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jbe	short loc_2D3E8	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2D48A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D3E8:				; CODE XREF: ScanWH+27j
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2D3F0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D3ED:				; CODE XREF: ScanWH+CBj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 1838
//@ 
//@ loc_2D3F0:				; CODE XREF: ScanWH+2Fj
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, [bp+POH]	; TOHeader*
//@ 		add	di, ax		; Add
//@ 		add	di, 3200h	; Add
//@ 		mov	word ptr [bp+var_C], di
//@ 		mov	word ptr [bp+var_C+2], es
//@ ; #line	"CSPBIO.PAS" 1840
//@ 		mov	ax, es:[di+4]
//@ 		les	di, [bp+H]	; int16_t
//@ 		cmp	ax, es:[di]	; Compare Two Operands
//@ 		jle	short loc_2D423	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		les	di, [bp+H]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1841
//@ 
//@ loc_2D423:				; CODE XREF: ScanWH+58j
//@ 		mov	ax, [bp+wx]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_2D442	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2D450	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_2D450	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2D442:				; CODE XREF: ScanWH+7Ej
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+wx], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1842
//@ 
//@ loc_2D450:				; CODE XREF: ScanWH+80j ScanWH+84j
//@ 		mov	ax, [bp+wy]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jg	short loc_2D470	; Jump if Greater (ZF=0	& SF=OF)
//@ 		jl	short loc_2D47F	; Jump if Less (SF!=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jbe	short loc_2D47F	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 
//@ loc_2D470:				; CODE XREF: ScanWH+ACj
//@ 		les	di, [bp+var_C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+wy], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1843
//@ 
//@ loc_2D47F:				; CODE XREF: ScanWH+AEj ScanWH+B2j
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_8]	; Compare Two Operands
//@ 		jz	short loc_2D48A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2D3ED	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1844
//@ 
//@ loc_2D48A:				; CODE XREF: ScanWH+29j ScanWH+C9j
//@ 		les	di, [bp+H]	; int16_t
//@ 		mov	ax, es:[di]
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1845
//@ 		push	[bp+wx]		; uint16_t
//@ 		push	[bp+wy]		; uint16_t
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		push	ax
//@ 		push	[bp+wx]		; uint16_t
//@ 		push	[bp+wy]		; uint16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		pop	dx
//@ 		add	ax, dx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		add	ax, 14h		; Add
//@ 		les	di, [bp+W]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1846
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ch		; Return Near from Procedure
//@ ScanWH		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1851
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScanLowHigh	proc far		; CODE XREF: CheckMonsterContact+D0P
//@ 					; SendFastRocket+1A2P ...
//@ 
//@ var_E		= dword	ptr -0Eh
//@ as		= word ptr -0Ah		; uint16_t
//@ ps		= word ptr -8		; uint16_t
//@ _h		= word ptr -6		; int16_t
//@ _l		= word ptr -4		; int16_t
//@ vc		= word ptr -2		; int16_t
//@ FT		= word ptr  6		; int16_t
//@ PH		= word ptr  8		; int16_t
//@ MT		= word ptr  0Ah		; int16_t
//@ H		= dword	ptr  0Ch	; int16_t
//@ L		= dword	ptr  10h	; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1852
//@ 		imul	di, [bp+MT], 0A2h ; int16_t
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_E], di
//@ 		mov	word ptr [bp+var_E+2], es
//@ ; #line	"CSPBIO.PAS" 1854
//@ 		mov	ax, [bp+FT]	; int16_t
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		mov	[bp+FT], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1855
//@ 		mov	ax, [bp+PH]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		add	di, ax		; Add
//@ 		les	di, es:[di+2Ah]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es
//@ 		mov	[bp+as], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1856
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+ps], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1857
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4800h]
//@ 		mov	[bp+vc], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1858
//@ 		push	[bp+as]		; uint16_t
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4800h]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+FT]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 6
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		push	ax
//@ 		push	[bp+ps]		; uint16_t
//@ 		push	3200h
//@ 		les	di, [bp+var_E]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4800h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		call	movsD$0		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1860
//@ 		mov	[bp+_l], 2710h	; int16_t
//@ 		mov	[bp+_h], 0D8F0h	; int16_t
//@ ; #line	"CSPBIO.PAS" 1862
//@ 		mov	ax, [bp+ps]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 1863
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 1864
//@ 		mov	cx, [bp+vc]	; int16_t
//@ ; #line	"CSPBIO.PAS" 1865
//@ 		mov	di, 3204h
//@ ; #line	"CSPBIO.PAS" 1866
//@ 
//@ loc_2D56F:				; CODE XREF: ScanLowHigh+C3j
//@ 		mov	ax, es:[di]
//@ ; #line	"CSPBIO.PAS" 1867
//@ 		cmp	[bp+_l], ax	; int16_t
//@ 		jl	short loc_2D57A	; Jump if Less (SF!=OF)
//@ 		mov	[bp+_l], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1868
//@ 
//@ loc_2D57A:				; CODE XREF: ScanLowHigh+B2j
//@ 		cmp	[bp+_h], ax	; int16_t
//@ 		jg	short loc_2D582	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+_h], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 1869
//@ 
//@ loc_2D582:				; CODE XREF: ScanLowHigh+BAj
//@ 		add	di, 6		; Add
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_2D56F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1871
//@ 		mov	ax, [bp+_l]	; int16_t
//@ 		les	di, [bp+L]	; int16_t
//@ 		mov	es:[di], ax
//@ 		mov	ax, [bp+_h]	; int16_t
//@ 		les	di, [bp+H]	; int16_t
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1873
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ ScanLowHigh	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aCaracter	db 9,'CARACTER\'        ; DATA XREF: InitCaracter+25o
//@ ; #line	"CSPBIO.PAS" 1882
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitCaracter	proc far		; CODE XREF: LoadMonsters+122P
//@ 
//@ var_170		= byte ptr -170h
//@ var_70		= dword	ptr -70h
//@ SFXVol		= byte ptr -6Ch		; uint16_t[8]
//@ SFXSize		= byte ptr -5Ch		; uint16_t[8]
//@ GSND		= word ptr -4Ch		; uint16_t[3]
//@ AniMap		= byte ptr -46h		; uint16_t[32]
//@ h		= byte ptr -6		; int16_t
//@ l		= word ptr -4		; int16_t
//@ n		= word ptr -2		; int16_t
//@ MNum		= word ptr  6		; int16_t
//@ 
//@ 		enter	170h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1883
//@ 		imul	di, [bp+MNum], 0A2h ; int16_t
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_70], di
//@ 		mov	word ptr [bp+var_70+2],	es
//@ ; #line	"CSPBIO.PAS" 1885
//@ 		mov	byte ptr es:[di+18h], 0
//@ ; #line	"CSPBIO.PAS" 1886
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_170] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCaracter ; "CARACTER\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 19h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1887
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+AniMap]	; uint16_t[32]
//@ 		push	ss
//@ 		push	di
//@ 		push	40h ; '@'
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1888
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+GSND]	; uint16_t[3]
//@ 		push	ss
//@ 		push	di
//@ 		push	6
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1889
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+SFXSize] ; uint16_t[8]
//@ 		push	ss
//@ 		push	di
//@ 		push	10h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1890
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+SFXVol]	; uint16_t[8]
//@ 		push	ss
//@ 		push	di
//@ 		push	10h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1892
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		add	di, 26h	; '&'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1893
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1894
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	4806h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1895
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1897
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2D698	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D695:				; CODE XREF: InitCaracter+112j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1898
//@ 
//@ loc_2D698:				; CODE XREF: InitCaracter+EBj
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	dx, [bp+di+GSND] ; uint16_t[3]
//@ 		mov	ax, [bp+MNum]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, [bp+n]	; int16_t
//@ 		imul	di, ax,	12h	; Signed Multiply
//@ 		mov	[di-2FB8h], dx
//@ 		cmp	[bp+n],	2	; int16_t
//@ 		jnz	short loc_2D695	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 1900
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+28h]
//@ 		push	word ptr es:[di+26h]
//@ 		add	di, 0Eh		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ScanWH		; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1901
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+28h]
//@ 		push	word ptr es:[di+26h]
//@ 		lea	di, [bp+l]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+h]	; int16_t
//@ 		push	ss
//@ 		push	di
//@ 		call	ScanLoHi	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1902
//@ 		cmp	[bp+l],	140h	; int16_t
//@ 		jle	short loc_2D704	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		sub	es:[di+0Ch], ax	; Integer Subtraction
//@ ; #line	"CSPBIO.PAS" 1903
//@ 
//@ loc_2D704:				; CODE XREF: InitCaracter+150j
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		add	di, 26h	; '&'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1904
//@ 		cmp	[bp+MNum], 78h ; 'x' ; int16_t
//@ 		jnz	short locret_2D724 ; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di+0Eh], 100h
//@ ; #line	"CSPBIO.PAS" 1906
//@ 
//@ locret_2D724:				; CODE XREF: InitCaracter+171j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ InitCaracter	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aCaracter_0	db 9,'CARACTER\'        ; DATA XREF: UpLoadCaracter+32o
//@ ; #line	"CSPBIO.PAS" 1914
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ UpLoadCaracter	proc far		; CODE XREF: ReloadResources+2ABP
//@ 
//@ var_16C		= byte ptr -16Ch
//@ var_70		= dword	ptr -70h
//@ var_6C		= dword	ptr -6Ch
//@ SFXVol		= word ptr -68h		; uint16_t[8]
//@ SFXSize		= word ptr -58h		; uint16_t[8]
//@ GSND		= byte ptr -48h		; uint16_t[3]
//@ AniMap		= word ptr -42h		; uint16_t[32]
//@ n		= word ptr -2		; int16_t
//@ MNum		= word ptr  6		; int16_t
//@ 
//@ 		enter	16Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1915
//@ 		imul	di, [bp+MNum], 0A2h ; int16_t
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_6C], di
//@ 		mov	word ptr [bp+var_6C+2],	es
//@ ; #line	"CSPBIO.PAS" 1917
//@ 		cmp	byte ptr es:[di+18h], 0	; Compare Two Operands
//@ 		jz	short loc_2D751	; Jump if Zero (ZF=1)
//@ 		jmp	locret_2DC0C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1919
//@ 
//@ loc_2D751:				; CODE XREF: UpLoadCaracter+1Aj
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	byte ptr es:[di+18h], 1
//@ ; #line	"CSPBIO.PAS" 1920
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+var_16C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aCaracter_0 ; "CARACTER\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		add	di, 19h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1921
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+AniMap]	; uint16_t[32]
//@ 		push	ss
//@ 		push	di
//@ 		push	40h ; '@'
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1922
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+GSND]	; uint16_t[3]
//@ 		push	ss
//@ 		push	di
//@ 		push	6
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1923
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+SFXSize] ; uint16_t[8]
//@ 		push	ss
//@ 		push	di
//@ 		push	10h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1924
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+SFXVol]	; uint16_t[8]
//@ 		push	ss
//@ 		push	di
//@ 		push	10h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1926
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		add	di, 26h	; '&'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1927
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1928
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	4806h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1930
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		add	di, 4806h	; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4804h]
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1931
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+4806h] ; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1932
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+4806h] ; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4804h]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1934
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2D881	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D87E:				; CODE XREF: UpLoadCaracter+207j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1935
//@ 
//@ loc_2D881:				; CODE XREF: UpLoadCaracter+14Aj
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		cmp	[bp+di+AniMap],	0 ; uint16_t[32]
//@ 		ja	short loc_2D88F	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_2D933	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1937
//@ 
//@ loc_2D88F:				; CODE XREF: UpLoadCaracter+158j
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 2Ah	; '*'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	[bp+di+AniMap]	; uint16_t[32]
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1938
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		les	di, es:[di+2Ah]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	[bp+di+AniMap]	; uint16_t[32]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1939
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4800h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	cx, ax
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+AniMap] ; uint16_t[32]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	cx		; Unsigned Divide
//@ 		dec	ax		; Decrement by 1
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	es:[di+7Ah], dx
//@ ; #line	"CSPBIO.PAS" 1940
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		les	di, es:[di+2Ah]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+AniMap] ; uint16_t[32]
//@ 		add	ax, 4		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1941
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1942
//@ 
//@ loc_2D933:				; CODE XREF: UpLoadCaracter+15Aj
//@ 		cmp	[bp+n],	13h	; int16_t
//@ 		jz	short loc_2D93C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2D87E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1944
//@ 
//@ loc_2D93C:				; CODE XREF: UpLoadCaracter+205j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2D946	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2D943:				; CODE XREF: UpLoadCaracter+3D7j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 1945
//@ 
//@ loc_2D946:				; CODE XREF: UpLoadCaracter+20Fj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 14h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		cmp	[bp+di+AniMap],	0 ; uint16_t[32]
//@ 		jnz	short loc_2D95B	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2DB03	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1946
//@ 
//@ loc_2D95B:				; CODE XREF: UpLoadCaracter+224j
//@ 		mov	ax, [bp+MNum]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, [bp+n]	; int16_t
//@ 		imul	di, ax,	12h	; Signed Multiply
//@ 		add	di, 0D044h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_70], di
//@ 		mov	word ptr [bp+var_70+2],	es
//@ ; #line	"CSPBIO.PAS" 1948
//@ 		add	di, 6		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1949
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1950
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	4806h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1951
//@ 		imul	di, [bp+MNum], 0A2h ; int16_t
//@ 		les	di, [di+7FD4h]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4806h]
//@ 		mov	dx, es:[di+4808h]
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4806h], ax
//@ 		mov	es:[di+4808h], dx
//@ ; #line	"CSPBIO.PAS" 1953
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 14h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	[bp+di+AniMap]	; uint16_t[32]
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1954
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+0Ah]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 14h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	[bp+di+AniMap]	; uint16_t[32]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1955
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4800h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 14h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+AniMap] ; uint16_t[32]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	cx		; Unsigned Divide
//@ 		dec	ax		; Decrement by 1
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 1956
//@ 		les	di, es:[di+0Ah]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 14h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+AniMap] ; uint16_t[32]
//@ 		add	ax, 4		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1958
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Eh		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 15h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	[bp+di+AniMap]	; uint16_t[32]
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1959
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+0Eh]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 15h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	[bp+di+AniMap]	; uint16_t[32]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1960
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4800h]
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 15h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+AniMap] ; uint16_t[32]
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		div	cx		; Unsigned Divide
//@ 		dec	ax		; Decrement by 1
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSPBIO.PAS" 1961
//@ 		les	di, es:[di+0Eh]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, 15h		; Add
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+AniMap] ; uint16_t[32]
//@ 		add	ax, 4		; Add
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 1962
//@ 
//@ loc_2DB03:				; CODE XREF: UpLoadCaracter+226j
//@ 		cmp	[bp+n],	2	; int16_t
//@ 		jz	short loc_2DB0C	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2D943	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1965
//@ 
//@ loc_2DB0C:				; CODE XREF: UpLoadCaracter+3D5j
//@ 		cmp	sCard, 2	; uint8_t
//@ 		jnb	short loc_2DB16	; Jump if Not Below (CF=0)
//@ 		jmp	loc_2DBC2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1966
//@ 
//@ loc_2DB16:				; CODE XREF: UpLoadCaracter+3DFj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_2DB20	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2DB1D:				; CODE XREF: UpLoadCaracter+48Dj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_2DB20:				; CODE XREF: UpLoadCaracter+3E9j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		cmp	[bp+di+SFXSize], 0 ; uint16_t[8]
//@ 		ja	short loc_2DB2E	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_2DBB9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1967
//@ 
//@ loc_2DB2E:				; CODE XREF: UpLoadCaracter+3F7j
//@ 		mov	ax, [bp+MNum]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+n], 16h	; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		add	ax, dx		; Add
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_70], di
//@ 		mov	word ptr [bp+var_70+2],	es
//@ ; #line	"CSPBIO.PAS" 1969
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+SFXVol] ; uint16_t[8]
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPBIO.PAS" 1970
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [bp+di+SFXSize] ; uint16_t[8]
//@ 		add	ax, 3FFh	; Add
//@ 		shr	ax, 0Ah		; Shift	Logical	Right
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSPBIO.PAS" 1971
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1972
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSPBIO.PAS" 1973
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_70]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		mov	di, [bp+n]	; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	[bp+di+SFXSize]	; uint16_t[8]
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 1974
//@ 
//@ loc_2DBB9:				; CODE XREF: UpLoadCaracter+3F9j
//@ 		cmp	[bp+n],	6	; int16_t
//@ 		jz	short loc_2DBC2	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2DB1D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1978
//@ 
//@ loc_2DBC2:				; CODE XREF: UpLoadCaracter+3E1j
//@ 					; UpLoadCaracter+48Bj
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1979
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		add	di, 10h		; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset i$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	[bp+MNum]	; int16_t
//@ 		push	0
//@ 		push	2
//@ 		call	ScanLowHigh	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1980
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		cmp	word ptr es:[di+10h], 140h ; Compare Two Operands
//@ 		jge	short loc_2DBFE	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+10h], ax
//@ 		jmp	short locret_2DC0C ; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2DBFE:				; CODE XREF: UpLoadCaracter+4C2j
//@ 		les	di, [bp+var_6C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+10h]
//@ 		shr	ax, 5		; Shift	Logical	Right
//@ 		mov	es:[di+10h], ax
//@ ; #line	"CSPBIO.PAS" 1982
//@ 
//@ locret_2DC0C:				; CODE XREF: UpLoadCaracter+1Cj
//@ 					; UpLoadCaracter+4CAj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ UpLoadCaracter	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 1987
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReleaseCaracter	proc far		; CODE XREF: ReloadResources+2B5P
//@ 
//@ var_8		= dword	ptr -8
//@ var_4		= dword	ptr -4
//@ C		= word ptr  6		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 1988
//@ 		imul	di, [bp+C], 0A2h ; int16_t
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPBIO.PAS" 1989
//@ 		cmp	byte ptr es:[di+18h], 0	; Compare Two Operands
//@ 		jnz	short loc_2DC2F	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2DDBC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 1991
//@ 
//@ loc_2DC2F:				; CODE XREF: ReleaseCaracter+1Aj
//@ 		mov	byte ptr es:[di+18h], 0
//@ ; #line	"CSPBIO.PAS" 1993
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2DC3F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2DC3B:				; CODE XREF: ReleaseCaracter+C2j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 1994
//@ 
//@ loc_2DC3F:				; CODE XREF: ReleaseCaracter+29j
//@ 		mov	ax, [bp+C]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		add	ax, n$0		; int16_t
//@ 		imul	di, ax,	12h	; Signed Multiply
//@ 		add	di, 0D044h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSPBIO.PAS" 1995
//@ 		mov	ax, es:[di+6]
//@ 		or	ax, es:[di+8]	; Logical Inclusive OR
//@ 		jz	short loc_2DCCB	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 1997
//@ 		add	di, 0Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	ax, es:[di]
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+4800h] ; Unsigned Multiplication of AL or AX
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1998
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Eh		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+2]
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, es:[di+6]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+4800h] ; Unsigned Multiplication of AL or AX
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 1999
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		add	di, 6		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2000
//@ 
//@ loc_2DCCB:				; CODE XREF: ReleaseCaracter+56j
//@ 		cmp	n$0, 2		; int16_t
//@ 		jz	short loc_2DCD5	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2DC3B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2002
//@ 
//@ loc_2DCD5:				; CODE XREF: ReleaseCaracter+C0j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2DCE0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2DCDC:				; CODE XREF: ReleaseCaracter+127j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 2003
//@ 
//@ loc_2DCE0:				; CODE XREF: ReleaseCaracter+CAj
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+2Ah]
//@ 		or	ax, es:[di+2Ch]	; Logical Inclusive OR
//@ 		jz	short loc_2DD32	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2004
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 2Ah	; '*'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		mov	ax, es:[di+7Ah]
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		inc	ax		; Increment by 1
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	si, ax
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		add	ax, si		; Add
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		mul	word ptr es:[di+4800h] ; Unsigned Multiplication of AL or AX
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 
//@ loc_2DD32:				; CODE XREF: ReleaseCaracter+E3j
//@ 		cmp	n$0, 13h	; int16_t
//@ 		jnz	short loc_2DCDC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2006
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2DD44	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2DD40:				; CODE XREF: ReleaseCaracter+17Bj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 2007
//@ 
//@ loc_2DD44:				; CODE XREF: ReleaseCaracter+12Ej
//@ 		mov	ax, [bp+C]	; int16_t
//@ 		sub	ax, 64h	; 'd'   ; Integer Subtraction
//@ 		mov	dx, ax
//@ 		imul	ax, n$0, 16h	; int16_t
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		add	ax, dx		; Add
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_8], di
//@ 		mov	word ptr [bp+var_8+2], es
//@ ; #line	"CSPBIO.PAS" 2008
//@ 		mov	ax, es:[di]
//@ 		or	ax, es:[di+2]	; Logical Inclusive OR
//@ 		jz	short loc_2DD86	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2009
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 		les	di, [bp+var_8]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+4], ax
//@ 
//@ loc_2DD86:				; CODE XREF: ReleaseCaracter+15Cj
//@ 		cmp	n$0, 7		; int16_t
//@ 		jnz	short loc_2DD40	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2011
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		add	di, 4806h	; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+26h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4804h]
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2012
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		add	di, 26h	; '&'   ; Add
//@ 		push	es
//@ 		push	di
//@ 		push	480Ah
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2014
//@ 
//@ locret_2DDBC:				; CODE XREF: ReleaseCaracter+1Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	2		; Return Far from Procedure
//@ ReleaseCaracter	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aV		db 2,'V:'               ; DATA XREF: LoadSound+21o
//@ a_wav_0		db 4,'.WAV'             ; DATA XREF: LoadSound+C7o
//@ ; #line	"CSPBIO.PAS" 2024
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadSound	proc far		; CODE XREF: LoadNewSounds+95P
//@ 					; LoadSounds+85P
//@ 
//@ var_20A		= byte ptr -20Ah
//@ var_10E		= dword	ptr -10Eh
//@ sg		= word ptr -10Ah	; uint16_t
//@ n		= word ptr -108h	; uint16_t
//@ v		= word ptr -106h	; uint16_t
//@ WSize		= word ptr -104h	; int32_t
//@ var_102		= word ptr -102h
//@ FName		= byte ptr -100h	; char[256] // Pascal string
//@ Index		= word ptr  6		; int16_t
//@ arg_2		= dword	ptr  8
//@ 
//@ 		enter	20Ah, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 2025
//@ 		mov	[bp+v],	40h ; '@' ; uint16_t
//@ 		mov	di, offset aV	; "V:"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+n],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2026
//@ 		cmp	[bp+n],	0	; uint16_t
//@ 		jz	short loc_2DE47	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2027
//@ 		lea	di, [bp+var_20A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+FName], al	; char[256] // Pascal string
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset i$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+v],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2029
//@ 
//@ loc_2DE47:				; CODE XREF: LoadSound+3Aj
//@ 		cmp	[bp+FName], 0	; char[256] // Pascal string
//@ 		jnz	short loc_2DE51	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2DF7F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2030
//@ 
//@ loc_2DE51:				; CODE XREF: LoadSound+84j
//@ 		lea	di, [bp+var_20A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2031
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2032
//@ 		mov	ax, word ptr F.Size ; struct BFile
//@ 		mov	dx, word ptr F.Size+2 ;	struct BFile
//@ 		mov	[bp+WSize], ax	; int32_t
//@ 		mov	[bp+var_102], dx
//@ ; #line	"CSPBIO.PAS" 2033
//@ 		mov	di, offset a_wav_0 ; ".WAV"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_2DEC7	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2034
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	28h ; '('
//@ 		call	FSeek		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+WSize]	; int32_t
//@ 		push	ss
//@ 		push	di
//@ 		push	4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2037
//@ 
//@ loc_2DEC7:				; CODE XREF: LoadSound+D9j
//@ 		mov	ax, [bp+Index]	; int16_t
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		les	di, Voices	; TSFXRec*
//@ 		add	di, ax		; Add
//@ 		mov	word ptr [bp+var_10E], di
//@ 		mov	word ptr [bp+var_10E+2], es
//@ ; #line	"CSPBIO.PAS" 2039
//@ 		mov	ax, [bp+WSize]	; int32_t
//@ 		mov	dx, [bp+var_102]
//@ 		add	ax, 3FFh	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSPBIO.PAS" 2040
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2041
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSPBIO.PAS" 2042
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+WSize]	; int32_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2043
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+sg], ax	; uint16_t
//@ 		mov	ax, [bp+WSize]	; int32_t
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		mov	ax, [bp+v]	; uint16_t
//@ 		les	di, [bp+var_10E] ; Load	Full Pointer to	ES:xx
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPBIO.PAS" 2045
//@ 		mov	cx, [bp+n]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2046
//@ 		mov	ax, [bp+sg]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2047
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2048
//@ 		xor	di, di		; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 2049
//@ 
//@ loc_2DF6E:				; CODE XREF: LoadSound+1ABj
//@ 		sub	byte ptr es:[di], 80h ;	'ﾀ' ; Integer Subtraction
//@ ; #line	"CSPBIO.PAS" 2050
//@ 		inc	di		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2051
//@ 		loop	loc_2DF6E	; Loop while CX	!= 0
//@ ; #line	"CSPBIO.PAS" 2055
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2056
//@ 
//@ locret_2DF7F:				; CODE XREF: LoadSound+86j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ LoadSound	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aB		db 2,'B:'               ; DATA XREF: LoadAmb+2Bo
//@ aV_0		db 2,'V:'               ; DATA XREF: LoadAmb+AFo
//@ a_wav_1		db 4,'.WAV'             ; DATA XREF: LoadAmb+14Co
//@ ; #line	"CSPBIO.PAS" 2060
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadAmb		proc far		; CODE XREF: LoadAmbients+95P
//@ 
//@ var_222		= byte ptr -222h
//@ var_126		= dword	ptr -126h
//@ b		= word ptr -122h	; int16_t
//@ s		= byte ptr -120h	; char[21] // Pascal string
//@ v		= word ptr -10Ah	; uint16_t
//@ n		= word ptr -108h	; uint16_t
//@ sg		= word ptr -106h	; uint16_t
//@ WSize		= word ptr -104h	; int32_t
//@ var_102		= word ptr -102h
//@ FName		= byte ptr -100h	; char[256] // Pascal string
//@ Index		= word ptr  6		; int16_t
//@ arg_2		= dword	ptr  8
//@ 
//@ 		enter	222h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		mov	bx, ds
//@ 		cld			; Clear	Direction Flag
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		lds	si, [bp+arg_2]	; Load Full Pointer to DS:xx
//@ 		lodsb			; Load String
//@ 		stosb			; Store	String
//@ 		xchg	ax, cx		; Exchange Register/Memory with	Register
//@ 		xor	ch, ch		; Logical Exclusive OR
//@ 		rep movsb		; Move Byte(s) from String to String
//@ 		mov	ds, bx
//@ ; #line	"CSPBIO.PAS" 2061
//@ 		cmp	[bp+FName], 0	; char[256] // Pascal string
//@ 		jnz	short loc_2DFB3	; Jump if Not Zero (ZF=0)
//@ 		jmp	locret_2E1DA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2063
//@ 
//@ loc_2DFB3:				; CODE XREF: LoadAmb+20j
//@ 		mov	[bp+b],	0FFFFh	; int16_t
//@ 		mov	di, offset aB	; "B:"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+n],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2064
//@ 		cmp	[bp+n],	0	; uint16_t
//@ 		jz	short loc_2E018	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2066
//@ 		lea	di, [bp+var_222] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+FName], al	; char[256] // Pascal string
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset i$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2068
//@ 
//@ loc_2E018:				; CODE XREF: LoadAmb+44j
//@ 		lea	di, [bp+var_222] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2070
//@ 		mov	[bp+v],	40h ; '@' ; uint16_t
//@ 		mov	di, offset aV_0	; "V:"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+n],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2071
//@ 		cmp	[bp+n],	0	; uint16_t
//@ 		jz	short loc_2E09C	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2072
//@ 		lea	di, [bp+var_222] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	14h
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+FName], al	; char[256] // Pascal string
//@ 		lea	di, [bp+s]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset i$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		mov	[bp+v],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2073
//@ 
//@ loc_2E09C:				; CODE XREF: LoadAmb+C8j
//@ 		lea	di, [bp+var_222] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2075
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2076
//@ 		mov	ax, word ptr F.Size ; struct BFile
//@ 		mov	dx, word ptr F.Size+2 ;	struct BFile
//@ 		mov	[bp+WSize], ax	; int32_t
//@ 		mov	[bp+var_102], dx
//@ ; #line	"CSPBIO.PAS" 2077
//@ 		mov	di, offset a_wav_1 ; ".WAV"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+FName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_2E112	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2078
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	28h ; '('
//@ 		call	FSeek		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+WSize]	; int32_t
//@ 		push	ss
//@ 		push	di
//@ 		push	4
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2080
//@ 
//@ loc_2E112:				; CODE XREF: LoadAmb+15Ej
//@ 		imul	di, [bp+Index],	0Eh ; int16_t
//@ 		add	di, 0F5C2h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_126], di
//@ 		mov	word ptr [bp+var_126+2], es
//@ ; #line	"CSPBIO.PAS" 2082
//@ 		mov	ax, [bp+b]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPBIO.PAS" 2083
//@ 		mov	ax, [bp+WSize]	; int32_t
//@ 		mov	dx, [bp+var_102]
//@ 		add	ax, 3FFh	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	cx, 0Ah
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brrsh$q7Longint7Integer ; X1{DX:AX}>>=N{CX}
//@ 		les	di, [bp+var_126] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPBIO.PAS" 2084
//@ 		mov	ax, [bp+WSize]	; int32_t
//@ 		mov	es:[di+4], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ 		mov	ax, [bp+v]	; uint16_t
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSPBIO.PAS" 2085
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, es:[di+6]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2086
//@ 		les	di, [bp+var_126] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_126] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+6]
//@ 		shl	ax, 0Ah		; Shift	Logical	Left
//@ 		push	ax
//@ 		push	0
//@ 		call	@FillChar$qm3Any4Word4Byte ; FillChar(var x; count: Word; value: Byte)
//@ ; #line	"CSPBIO.PAS" 2087
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_126] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		push	es
//@ 		push	di
//@ 		push	[bp+WSize]	; int32_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2088
//@ 		les	di, [bp+var_126] ; Load	Full Pointer to	ES:xx
//@ 		les	di, es:[di]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es
//@ 		mov	[bp+sg], ax	; uint16_t
//@ 		mov	ax, [bp+WSize]	; int32_t
//@ 		mov	[bp+n],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2090
//@ 		mov	cx, [bp+n]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2091
//@ 		mov	ax, [bp+sg]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2092
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2093
//@ 		xor	di, di		; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 2094
//@ 
//@ loc_2E1C9:				; CODE XREF: LoadAmb+240j
//@ 		sub	byte ptr es:[di], 80h ;	'ﾀ' ; Integer Subtraction
//@ ; #line	"CSPBIO.PAS" 2095
//@ 		inc	di		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2096
//@ 		loop	loc_2E1C9	; Loop while CX	!= 0
//@ ; #line	"CSPBIO.PAS" 2099
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2100
//@ 
//@ locret_2E1DA:				; CODE XREF: LoadAmb+22j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ LoadAmb		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2105
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AllocFloors	proc near		; CODE XREF: AllocMemory+182p
//@ 
//@ p		= dword	ptr -8		; void*
//@ n		= word ptr -4		; uint16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2106
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_2E1EC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E1E9:				; CODE XREF: AllocFloors+3Fj
//@ 		inc	[bp+n]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2108
//@ 
//@ loc_2E1EC:				; CODE XREF: AllocFloors+9j
//@ 		lea	di, [bp+p]	; void*
//@ 		push	ss
//@ 		push	di
//@ 		push	1580h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2109
//@ 		les	di, [bp+p]	; void*
//@ 		mov	ax, es
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di+1890h], ax
//@ ; #line	"CSPBIO.PAS" 2110
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		push	word ptr [di+1890h]
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 2111
//@ 		cmp	[bp+n],	3Fh ; '?' ; uint16_t
//@ 		jnz	short loc_2E1E9	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2113
//@ 		mov	[bp+n],	40h ; '@' ; uint16_t
//@ 		jmp	short loc_2E229	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E226:				; CODE XREF: AllocFloors+5Cj
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_2E229:				; CODE XREF: AllocFloors+46j
//@ 		mov	ax, FlSegs	; uint16_t[256]
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di+1890h], ax
//@ 		cmp	[bp+n],	0FFh	; uint16_t
//@ 		jnz	short loc_2E226	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2114
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ AllocFloors	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2118
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AllocVideo	proc far		; CODE XREF: DeinitMonitor+12P
//@ 					; SwitchMonitor+41P ...
//@ 
//@ VMSize		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2119
//@ 		mov	ax, LastVideoMode ; uint16_t
//@ ; #line	"CSPBIO.PAS" 2120
//@ 		cmp	ax, 0		; Compare Two Operands
//@ 		jnz	short loc_2E24C	; Jump if Not Zero (ZF=0)
//@ 		jmp	short loc_2E268	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2121
//@ 
//@ loc_2E24C:				; CODE XREF: AllocVideo+Aj
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_2E25F	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset $VGA	; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	FreeMem16	; function far PASCAL returns void
//@ 		jmp	short loc_2E268	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2122
//@ 
//@ loc_2E25F:				; CODE XREF: AllocVideo+11j
//@ 		push	VgaSeg		; uint16_t
//@ 		call	GlobalFree	; Call Procedure
//@ ; #line	"CSPBIO.PAS" 2125
//@ 
//@ loc_2E268:				; CODE XREF: AllocVideo+Cj
//@ 					; AllocVideo+1Fj
//@ 		mov	ax, CurVideoMode ; uint16_t
//@ 		mov	LastVideoMode, ax ; uint16_t
//@ ; #line	"CSPBIO.PAS" 2127
//@ 		mov	ax, CurVideoMode ; uint16_t
//@ ; #line	"CSPBIO.PAS" 2128
//@ 		cmp	ax, 1		; Compare Two Operands
//@ 		jnz	short loc_2E28D	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset $VGA	; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	GetMem16	; function far PASCAL returns void
//@ 		les	di, $VGA	; void*
//@ 		mov	ax, es
//@ 		mov	VgaSeg,	ax	; uint16_t
//@ 		jmp	short locret_2E2D0 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2130
//@ 
//@ loc_2E28D:				; CODE XREF: AllocVideo+36j
//@ 		imul	di, CurVideoMode, 0Dh ;	uint16_t
//@ 		mov	ax, [di-0BC9h]
//@ 		mov	dx, [di-0BC7h]
//@ 		add	ax, 0A00h	; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		mov	[bp+VMSize], ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSPBIO.PAS" 2131
//@ 		push	[bp+var_2]
//@ 		push	[bp+VMSize]	; int32_t
//@ 		call	GlobalCompact	; Call Procedure
//@ ; #line	"CSPBIO.PAS" 2132
//@ 		push	40h ; '@'
//@ 		push	[bp+var_2]
//@ 		push	[bp+VMSize]	; int32_t
//@ 		call	GlobalAlloc	; Call Procedure
//@ 		mov	VgaSeg,	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2134
//@ 		mov	ax, 8
//@ ; #line	"CSPBIO.PAS" 2135
//@ 		mov	bx, VgaSeg	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2136
//@ 		mov	cx, [bp+var_2]
//@ ; #line	"CSPBIO.PAS" 2137
//@ 		mov	dx, [bp+VMSize]	; int32_t
//@ ; #line	"CSPBIO.PAS" 2138
//@ 		int	31h		; DPMI Services	  ax=func xxxxh
//@ 					; SET SEGMENT LIMIT
//@ 					; BX = selector, CX:DX = segment limit
//@ 					; Return: CF set on error
//@ 					; CF clear if successful
//@ ; #line	"CSPBIO.PAS" 2142
//@ 
//@ locret_2E2D0:				; CODE XREF: AllocVideo+4Dj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AllocVideo	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aStartupAllocat	db 19,'Startup Allocated: ' ; DATA XREF: AllocMemory+239o
//@ aK__0		db 2,'K.'               ; DATA XREF: AllocMemory+25Eo
//@ ; #line	"CSPBIO.PAS" 2148
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AllocMemory	proc far		; CODE XREF: PROGRAM+C12P
//@ 
//@ mema		= word ptr -4		; int32_t
//@ var_2		= word ptr -2
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2149
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	[bp+mema], ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSPBIO.PAS" 2151
//@ 		mov	di, offset RGBTab25 ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	GetMem16	; function far PASCAL returns void
//@ 		les	di, RGBTab25	; void*
//@ 		mov	ax, es
//@ 		mov	RGBSeg25, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2152
//@ 		mov	di, offset RGBTab60 ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	GetMem16	; function far PASCAL returns void
//@ 		les	di, RGBTab60	; void*
//@ 		mov	ax, es
//@ 		mov	RGBSeg60, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2153
//@ 		mov	di, offset Fonts ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	0A000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2154
//@ 		mov	di, offset ConsolePtr ;	void*
//@ 		push	ds
//@ 		push	di
//@ 		push	5F00h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2155
//@ 		mov	di, offset BigFont ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	230Ah
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2156
//@ 		mov	di, offset LitFont ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	492h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2157
//@ 		mov	di, offset WIcons ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	15E0h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2159
//@ 		mov	di, offset Flags ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2160
//@ 		mov	di, offset VMask ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2161
//@ 		mov	di, offset DarkMap ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2162
//@ 		mov	di, offset AmbMap ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2163
//@ 		mov	di, offset TeleMap ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2164
//@ 		mov	di, offset FloorZLo ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2165
//@ 		mov	di, offset FloorZHi ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2168
//@ 		mov	di, offset VesaTiler ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2169
//@ 		mov	di, offset Ground ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	5000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2170
//@ 		mov	di, offset Status ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	5F00h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2171
//@ 		mov	di, offset AltXTab ; uint8_t*
//@ 		push	ds
//@ 		push	di
//@ 		push	800h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2172
//@ 		mov	di, offset GFXindex ; char*
//@ 		push	ds
//@ 		push	di
//@ 		push	700h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2173
//@ 		mov	di, offset FramesList ;	TFrame*
//@ 		push	ds
//@ 		push	di
//@ 		push	15E0h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2174
//@ 		mov	di, offset BlowsList ; TBlow*
//@ 		push	ds
//@ 		push	di
//@ 		push	1000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2175
//@ 		mov	di, offset LevelNames ;	char*
//@ 		push	ds
//@ 		push	di
//@ 		push	800h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2176
//@ 		mov	di, offset ShortNames ;	char*
//@ 		push	ds
//@ 		push	di
//@ 		push	800h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2177
//@ 		mov	di, offset SkyPtr ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0C800h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2178
//@ 		mov	di, offset LinesBUF ; TLinesBuf*
//@ 		push	ds
//@ 		push	di
//@ 		push	2400h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2179
//@ 		mov	di, offset Tports ; TTPort$Element*
//@ 		push	ds
//@ 		push	di
//@ 		push	500h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2180
//@ 		mov	di, offset HolesList ; THoleItem*
//@ 		push	ds
//@ 		push	di
//@ 		push	500h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2182
//@ 		call	AllocVideo	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2184
//@ 		call	AllocFloors	; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2188
//@ 		mov	ax, ds
//@ 		push	ax
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 2189
//@ 		mov	di, offset Map	; TLoc*
//@ 		push	ds
//@ 		push	di
//@ 		push	0B000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2190
//@ 		mov	di, offset Lights ; TLight*
//@ 		push	ds
//@ 		push	di
//@ 		push	0C00h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2192
//@ 		mov	di, offset ShadowMap ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	GetMem16	; function far PASCAL returns void
//@ 		mov	di, offset ShadowMap2 ;	void*
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFFFh
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2193
//@ 		les	di, ShadowMap	; void*
//@ 		mov	ax, es
//@ 		mov	ShadowSeg, ax	; uint16_t
//@ 		les	di, ShadowMap2	; void*
//@ 		mov	ax, es
//@ 		mov	ShadowSeg2, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2195
//@ 		mov	di, offset WShadowMap ;	void*
//@ 		push	ds
//@ 		push	di
//@ 		push	8000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ 		mov	di, offset WShadowMap2 ; void*
//@ 		push	ds
//@ 		push	di
//@ 		push	8000h
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2196
//@ 		les	di, WShadowMap	; void*
//@ 		mov	ax, es
//@ 		mov	WShadowSeg, ax	; uint16_t
//@ 		les	di, WShadowMap2	; void*
//@ 		mov	ax, es
//@ 		mov	WShadowSeg2, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2198
//@ 		push	WShadowSeg	; uint16_t
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 2199
//@ 		push	ShadowSeg	; uint16_t
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 2200
//@ 		call	@MemAvail$qv	; MemAvail: Longint{DX:AX}\nfunction far PASCAL	returns	signed long 'Longint'
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+mema]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+mema], ax	; int32_t
//@ 		mov	[bp+var_2], dx
//@ ; #line	"CSPBIO.PAS" 2201
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aStartupAllocat ; "Startup Allocated: "
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		mov	ax, [bp+mema]	; int32_t
//@ 		mov	dx, [bp+var_2]
//@ 		mov	cx, 3E8h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		push	dx
//@ 		push	ax
//@ 		push	0
//@ 		call	@Write$qm4Text7Longint4Word ; Write(var	f; v: Longint; width: Word)
//@ 		mov	di, offset aK__0 ; "K."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2202
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ AllocMemory	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadingEnviron	db 22,'Loading environment...' ; DATA XREF: LoadCommonParts+6Bo
//@ aCommonConsole_	db 18,'COMMON\CONSOLE.CEL' ; DATA XREF: LoadCommonParts+81o
//@ aCommonChasm_rg	db 16,'COMMON\CHASM.RGB' ; DATA XREF: LoadCommonParts+D2o
//@ aCommonChasm60_	db 18,'COMMON\CHASM60.RGB' ; DATA XREF: LoadCommonParts+102o
//@ aCommonFont256_	db 18,'COMMON\font256.cel' ; DATA XREF: LoadCommonParts+1B0o
//@ aCommonBfont2_c	db 17,'COMMON\bfont2.cel' ; DATA XREF: LoadCommonParts+282o
//@ aCommonLfont2_c	db 17,'COMMON\lfont2.cel' ; DATA XREF: LoadCommonParts+2C6o
//@ aCommonWicons_c	db 17,'COMMON\wicons.cel' ; DATA XREF: LoadCommonParts+30Ao
//@ aCommonFadetab_	db 18,'COMMON\fadetab.cel' ; DATA XREF: LoadCommonParts+34Eo
//@ aCommonChasm2_p	db 17,'COMMON\chasm2.pal' ; DATA XREF: LoadCommonParts+3BBo
//@ aCommonChasm_ke	db 16,'COMMON\chasm.key' ; DATA XREF: LoadCommonParts+3EAo
//@ aOk__0		db 3,'Ok.'              ; DATA XREF: LoadCommonParts+419o
//@ ; #line	"CSPBIO.PAS" 2207
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadCommonParts	proc far		; CODE XREF: PROGRAM+CB7P
//@ 
//@ yy		= word ptr -0Ah		; uint16_t
//@ xx		= word ptr -8		; uint16_t
//@ w		= word ptr -6		; uint16_t
//@ y		= word ptr -4		; uint16_t
//@ x		= word ptr -2		; uint16_t
//@ 
//@ 		enter	0Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2208
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_2E63A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E636:				; CODE XREF: LoadCommonParts+64j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2E63A:				; CODE XREF: LoadCommonParts+9j
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 2182h
//@ 		mov	si, 0DAA2h
//@ 		mov	di, 490Fh
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 82h	; 'ﾂ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		mov	cx, 8Bh	; 'ﾋ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		call	@Cos$q4Real	; Cos(x: Real):	Real
//@ 		mov	cx, 8Dh	; 'ﾍ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di-6390h], ax
//@ 		cmp	n$0, 3FFh	; int16_t
//@ 		jnz	short loc_2E636	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2210
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadingEnviron ; "Loading environment..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2212
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonConsole_ ; "COMMON\\CONSOLE.CEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2213
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2214
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, ConsolePtr	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	5F00h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2215
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2217
//@ 		push	RGBSeg60	; uint16_t
//@ 		push	0
//@ 		push	0FFFFh
//@ 		call	SetSelectorLimit ; Call	Procedure
//@ ; #line	"CSPBIO.PAS" 2218
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonChasm_rg ; "COMMON\\CHASM.RGB"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, RGBTab25	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FF00h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2219
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonChasm60_ ; "COMMON\\CHASM60.RGB"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, RGBTab60	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	0FF00h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2220
//@ 		mov	ax, RGBSeg25	; uint16_t
//@ 		mov	RGBSeg,	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2222
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+w],	ax	; uint16_t
//@ 		jmp	short loc_2E768	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E765:				; CODE XREF: LoadCommonParts+16Bj
//@ 		inc	[bp+w]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2224
//@ 
//@ loc_2E768:				; CODE XREF: LoadCommonParts+138j
//@ 		mov	dl, byte ptr [bp+w] ; uint16_t
//@ 		mov	ax, RGBSeg60	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		add	ax, 0FFh	; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSPBIO.PAS" 2225
//@ 		mov	dl, byte ptr [bp+w] ; uint16_t
//@ 		mov	ax, RGBSeg60	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		add	ax, 0FF00h	; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ ; #line	"CSPBIO.PAS" 2226
//@ 		cmp	[bp+w],	0FFh	; uint16_t
//@ 		jnz	short loc_2E765	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2228
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+w],	ax	; uint16_t
//@ 		jmp	short loc_2E7A2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E79F:				; CODE XREF: LoadCommonParts+18Aj
//@ 		inc	[bp+w]		; uint16_t
//@ 
//@ loc_2E7A2:				; CODE XREF: LoadCommonParts+172j
//@ 		mov	dl, byte ptr [bp+w] ; uint16_t
//@ 		mov	ax, RGBSeg25	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+w]	; uint16_t
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ 		cmp	[bp+w],	0FEh ; '￾' ; uint16_t
//@ 		jnz	short loc_2E79F	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2229
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+w],	ax	; uint16_t
//@ 		jmp	short loc_2E7C1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E7BE:				; CODE XREF: LoadCommonParts+1A9j
//@ 		inc	[bp+w]		; uint16_t
//@ 
//@ loc_2E7C1:				; CODE XREF: LoadCommonParts+191j
//@ 		mov	dl, byte ptr [bp+w] ; uint16_t
//@ 		mov	ax, RGBSeg60	; uint16_t
//@ 		push	ax
//@ 		mov	di, [bp+w]	; uint16_t
//@ 		pop	es
//@ 		mov	es:[di], dl
//@ 		cmp	[bp+w],	0FEh ; '￾' ; uint16_t
//@ 		jnz	short loc_2E7BE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2232
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonFont256_ ; "COMMON\\font256.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2233
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, Fonts	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	0A000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2234
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2236
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_2E825	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E821:				; CODE XREF: LoadCommonParts+27Aj
//@ 		inc	j		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2238
//@ 
//@ loc_2E825:				; CODE XREF: LoadCommonParts+1F4j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+w],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2239
//@ 		mov	ax, j		; uint16_t
//@ 		and	ax, 0Fh		; Logical AND
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		mov	ax, j		; uint16_t
//@ 		shr	ax, 4		; Shift	Logical	Right
//@ 		mov	[bp+y],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2240
//@ 		mov	[bp+xx], 1	; uint16_t
//@ 		jmp	short loc_2E846	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E843:				; CODE XREF: LoadCommonParts+262j
//@ 		inc	[bp+xx]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2241
//@ 
//@ loc_2E846:				; CODE XREF: LoadCommonParts+216j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+yy], ax	; uint16_t
//@ 		jmp	short loc_2E850	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E84D:				; CODE XREF: LoadCommonParts+25Cj
//@ 		inc	[bp+yy]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2242
//@ 
//@ loc_2E850:				; CODE XREF: LoadCommonParts+220j
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+yy]	; uint16_t
//@ 		shl	ax, 8		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+y], 0A00h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		add	ax, cx		; Add
//@ 		add	ax, [bp+xx]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		add	ax, 200h	; Add
//@ 		les	di, Fonts	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di], 0FFh ; Compare Two Operands
//@ 		jz	short loc_2E883	; Jump if Zero (ZF=1)
//@ 		mov	ax, [bp+xx]	; uint16_t
//@ 		mov	[bp+w],	ax	; uint16_t
//@ 
//@ loc_2E883:				; CODE XREF: LoadCommonParts+250j
//@ 		cmp	[bp+yy], 6	; uint16_t
//@ 		jnz	short loc_2E84D	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+xx], 0Ah	; uint16_t
//@ 		jnz	short loc_2E843	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2243
//@ 		mov	ax, [bp+w]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	di, j		; uint16_t
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	[di-1DA0h], ax
//@ ; #line	"CSPBIO.PAS" 2244
//@ 		cmp	j, 0FFh		; uint16_t
//@ 		jz	short loc_2E8A8	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2E821	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2247
//@ 
//@ loc_2E8A8:				; CODE XREF: LoadCommonParts+278j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonBfont2_c ; "COMMON\\bfont2.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, BigFont	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	230Ah
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2248
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2250
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonLfont2_c ; "COMMON\\lfont2.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, LitFont	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	492h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2251
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2254
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonWicons_c ; "COMMON\\wicons.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2255
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2256
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, WIcons	; uint8_t*
//@ 		push	es
//@ 		push	di
//@ 		push	15E0h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2257
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2259
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonFadetab_ ; "COMMON\\fadetab.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2260
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ColorMap ; uint8_t[13312]
//@ 		push	ds
//@ 		push	di
//@ 		push	3400h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2261
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2262
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_2E9C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2E9BF:				; CODE XREF: LoadCommonParts+3A9j
//@ 		inc	n$0		; int16_t
//@ 
//@ loc_2E9C3:				; CODE XREF: LoadCommonParts+392j
//@ 		mov	di, n$0		; int16_t
//@ 		shl	di, 8		; Shift	Logical	Left
//@ 		mov	byte ptr [di+1AC5h], 0FFh
//@ 		cmp	n$0, 34h ; '4'  ; int16_t
//@ 		jnz	short loc_2E9BF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2264
//@ 		mov	ax, 1AC6h
//@ 		mov	cm_ofs,	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2265
//@ 		call	LoadGround	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2267
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonChasm2_p ; "COMMON\\chasm2.pal"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset Palette ; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		push	300h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2268
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonChasm_ke ; "COMMON\\chasm.key"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset ASCII_Tab ; uint8_t[256]
//@ 		push	ds
//@ 		push	di
//@ 		push	100h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2269
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__0 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2270
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ LoadCommonParts	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2276
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CheckMouse	proc far		; CODE XREF: PROGRAM+664P
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2277
//@ 		mov	MouseD,	0	; bool
//@ ; #line	"CSPBIO.PAS" 2279
//@ 		call	getmousestate	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2280
//@ 		cmp	MsX, 0		; int16_t
//@ 		jle	short locret_2EA88 ; Jump if Less or Equal (ZF=1 | SF!=OF)
//@ 		cmp	MsX, 27Fh	; int16_t
//@ 		jge	short locret_2EA88 ; Jump if Greater or	Equal (SF=OF)
//@ 		cmp	MsY, 0		; int16_t
//@ 		jle	short locret_2EA88 ; Jump if Less or Equal (ZF=1 | SF!=OF)
//@ 		cmp	MsY, 190h	; int16_t
//@ 		jge	short locret_2EA88 ; Jump if Greater or	Equal (SF=OF)
//@ 		mov	MouseD,	1	; bool
//@ ; #line	"CSPBIO.PAS" 2281
//@ 
//@ locret_2EA88:				; CODE XREF: CheckMouse+13j
//@ 					; CheckMouse+1Bj ...
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ CheckMouse	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ asc_2EA8A	db 1,'='                ; DATA XREF: RemoveEqual+4o
//@ asc_2EA8C	db 1,';'                ; DATA XREF: RemoveEqual+43o
//@ 					; RemoveEqual+56o
//@ ; #line	"CSPBIO.PAS" 2288
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ RemoveEqual	proc far		; CODE XREF: LoadNewSounds+4CP
//@ 					; LoadAmbients+4CP ...
//@ 
//@ var_202		= byte ptr -202h
//@ var_102		= byte ptr -102h
//@ p		= word ptr -2		; int16_t
//@ s		= dword	ptr  6		; char[256] // Pascal string
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2289
//@ 		mov	di, offset asc_2EA8A ; "="
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+p],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2290
//@ 		cmp	[bp+p],	0	; int16_t
//@ 		jnz	short loc_2EAAC	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_2EB22 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2291
//@ 
//@ loc_2EAAC:				; CODE XREF: RemoveEqual+1Aj
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, [bp+p]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	88h ; 'ﾈ'
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2292
//@ 		mov	di, offset asc_2EA8C ; ";"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jle	short loc_2EAFA	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPBIO.PAS" 2293
//@ 		mov	di, offset asc_2EA8C ; ";"
//@ 		push	cs
//@ 		push	di
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		dec	ax		; Decrement by 1
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		mov	es:[di], al
//@ ; #line	"CSPBIO.PAS" 2294
//@ 
//@ loc_2EAFA:				; CODE XREF: RemoveEqual+54j
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_102] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	StUpcase	; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		les	di, [bp+s]	; char[256] // Pascal string
//@ 		push	es
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2295
//@ 
//@ locret_2EB22:				; CODE XREF: RemoveEqual+1Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ RemoveEqual	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadSoundData_	db 18,'Load Sound Data...' ; DATA XREF: LoadSounds+13o
//@ aSounds_end	db 12,'[SOUNDS_END]'    ; DATA XREF: LoadSounds+48o
//@ aSfx		db 4,'SFX\'             ; DATA XREF: LoadSounds+6Co
//@ aOk__1		db 3,'Ok.'              ; DATA XREF: LoadSounds+ADo
//@ ; #line	"CSPBIO.PAS" 2300
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadSounds	proc near		; CODE XREF: LoadGraphics+F1p
//@ 
//@ var_202		= byte ptr -202h
//@ index		= word ptr -102h	; uint16_t
//@ sn		= byte ptr -100h	; char[256] // Pascal string
//@ 
//@ 		enter	202h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2301
//@ 		cmp	sCard, 1	; uint8_t
//@ 		ja	short loc_2EB5D	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	locret_2EC0D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2303
//@ 
//@ loc_2EB5D:				; CODE XREF: LoadSounds+9j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadSoundData_ ; "Load Sound Data..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2304
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+sn]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2305
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+index], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2306
//@ 
//@ loc_2EB91:				; CODE XREF: LoadSounds+A6j
//@ 		lea	di, [bp+sn]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSounds_end ; "[SOUNDS_END]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_2EBF7	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2308
//@ 		lea	di, [bp+sn]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2309
//@ 		cmp	[bp+sn], 0	; char[256] // Pascal string
//@ 		jz	short loc_2EBD9	; Jump if Zero (ZF=1)
//@ 		lea	di, [bp+var_202] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aSfx	; "SFX\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+sn]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		push	[bp+index]	; uint16_t
//@ 		call	LoadSound	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2310
//@ 
//@ loc_2EBD9:				; CODE XREF: LoadSounds+64j
//@ 		inc	[bp+index]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2311
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+sn]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2312
//@ 		jmp	short loc_2EB91	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2313
//@ 
//@ loc_2EBF7:				; CODE XREF: LoadSounds+52j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__1 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2314
//@ 
//@ locret_2EC0D:				; CODE XREF: LoadSounds+Bj
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadSounds	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadingObjects	db 19,' Loading Objects...' ; DATA XREF: LoadBMPObjects+9o
//@ aBmp		db 4,'BMP\'             ; DATA XREF: LoadBMPObjects+E9o
//@ aOk__2		db 3,'Ok.'              ; DATA XREF: LoadBMPObjects+196o
//@ ; #line	"CSPBIO.PAS" 2321
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadBMPObjects	proc near		; CODE XREF: LoadGraphics+6Cp
//@ 
//@ var_250		= byte ptr -250h
//@ var_150		= byte ptr -150h
//@ var_52		= word ptr -52h
//@ var_50		= dword	ptr -50h
//@ var_4C		= word ptr -4Ch
//@ FO		= byte ptr -4Ah		; char[61] // Pascal string
//@ _hl		= word ptr -0Ch		; uint16_t
//@ _gl		= word ptr -0Ah		; uint16_t
//@ _sh		= word ptr -8		; uint16_t
//@ n		= word ptr -6		; uint16_t
//@ o		= word ptr -2		; uint16_t
//@ 
//@ 		enter	250h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2322
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadingObjects ; " Loading Objects..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2323
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	ObjectsLoaded, ax ; uint16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2324
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2326
//@ 		mov	ax, ObjectsLoaded ; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_4C], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_4C]	; Compare Two Operands
//@ 		jbe	short loc_2EC6E	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2EDBD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2EC6E:				; CODE XREF: LoadBMPObjects+3Dj
//@ 		mov	[bp+o],	ax	; uint16_t
//@ 		jmp	short loc_2EC76	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2EC73:				; CODE XREF: LoadBMPObjects+18Ej
//@ 		inc	[bp+o]		; uint16_t
//@ 
//@ loc_2EC76:				; CODE XREF: LoadBMPObjects+45j
//@ 		imul	di, [bp+o], 0A5h ; uint16_t
//@ 		add	di, 721Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_50], di
//@ 		mov	word ptr [bp+var_50+2],	es
//@ ; #line	"CSPBIO.PAS" 2328
//@ 		mov	byte ptr es:[di+4], 0
//@ ; #line	"CSPBIO.PAS" 2329
//@ 		mov	byte ptr es:[di+2], 0
//@ ; #line	"CSPBIO.PAS" 2330
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_sh], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_gl], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_hl], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2331
//@ 		cmp	[bp+_sh], 1	; uint16_t
//@ 		jnz	short loc_2ECE8	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+2], 2 ;	Add
//@ ; #line	"CSPBIO.PAS" 2332
//@ 
//@ loc_2ECE8:				; CODE XREF: LoadBMPObjects+B2j
//@ 		cmp	[bp+_gl], 1	; uint16_t
//@ 		jnz	short loc_2ECF5	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		inc	byte ptr es:[di+2] ; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2333
//@ 
//@ loc_2ECF5:				; CODE XREF: LoadBMPObjects+C0j
//@ 		cmp	[bp+_hl], 1	; uint16_t
//@ 		jnz	short loc_2ED03	; Jump if Not Zero (ZF=0)
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+2], 4 ;	Add
//@ ; #line	"CSPBIO.PAS" 2334
//@ 
//@ loc_2ED03:				; CODE XREF: LoadBMPObjects+CDj
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 2335
//@ 		lea	di, [bp+var_250] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aBmp	; "BMP\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_150] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2336
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2337
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		add	di, 3		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2338
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		mov	al, es:[di+3]
//@ 		dec	al		; Decrement by 1
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_52], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		ja	short loc_2EDA8	; Jump if Above	(CF=0 &	ZF=0)
//@ 		mov	j, ax		; uint16_t
//@ 		jmp	short loc_2ED86	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2ED82:				; CODE XREF: LoadBMPObjects+17Aj
//@ 		inc	j		; uint16_t
//@ 
//@ loc_2ED86:				; CODE XREF: LoadBMPObjects+154j
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		imul	ax, j, 0Ah	; uint16_t
//@ 		les	di, [bp+var_50]	; Load Full Pointer to ES:xx
//@ 		add	di, ax		; Add
//@ 		add	di, 5		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPic		; function far PASCAL returns void
//@ 		mov	ax, j		; uint16_t
//@ 		cmp	ax, [bp+var_52]	; Compare Two Operands
//@ 		jnz	short loc_2ED82	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2339
//@ 
//@ loc_2EDA8:				; CODE XREF: LoadBMPObjects+14Fj
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2340
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		cmp	ax, [bp+var_4C]	; Compare Two Operands
//@ 		jz	short loc_2EDBD	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2EC73	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2341
//@ 
//@ loc_2EDBD:				; CODE XREF: LoadBMPObjects+3Fj
//@ 					; LoadBMPObjects+18Cj
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__2 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2342
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadBMPObjects	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoading3dObjec	db 22,' Loading 3D Objects...' ; DATA XREF: Load3dObjects+9o
//@ aOk__3		db 3,'Ok.'              ; DATA XREF: Load3dObjects+25Bo
//@ ; #line	"CSPBIO.PAS" 2347
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Load3dObjects	proc near		; CODE XREF: LoadGraphics+83p
//@ 
//@ var_28C		= byte ptr -28Ch
//@ var_18C		= byte ptr -18Ch
//@ var_8C		= dword	ptr -8Ch
//@ var_88		= word ptr -88h
//@ c		= byte ptr -85h		; char
//@ AN		= byte ptr -84h		; char[61] // Pascal string
//@ var_83		= byte ptr -83h
//@ FO		= byte ptr -46h		; char[61] // Pascal string
//@ n		= word ptr -6		; uint16_t
//@ o		= word ptr -4		; uint16_t
//@ ol3d		= word ptr -2		; uint16_t
//@ 
//@ 		enter	28Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2348
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoading3dObjec ; " Loading 3D Objects..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2349
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+ol3d], ax	; uint16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2350
//@ 		mov	ax, [bp+ol3d]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_88], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_88]	; Compare Two Operands
//@ 		jbe	short loc_2EE34	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2F046	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2EE34:				; CODE XREF: Load3dObjects+3Fj
//@ 		mov	[bp+o],	ax	; uint16_t
//@ 		jmp	short loc_2EE3C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2EE39:				; CODE XREF: Load3dObjects+253j
//@ 		inc	[bp+o]		; uint16_t
//@ 
//@ loc_2EE3C:				; CODE XREF: Load3dObjects+47j
//@ 		imul	di, [bp+o], 24h	; uint16_t
//@ 		add	di, 74AEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_8C], di
//@ 		mov	word ptr [bp+var_8C+2],	es
//@ ; #line	"CSPBIO.PAS" 2352
//@ 
//@ loc_2EE4E:				; CODE XREF: Load3dObjects+90j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text4Char ; Read(var f; var c:	Char{AL})
//@ 		mov	[bp+c],	al	; char
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ 		cmp	[bp+c],	3Bh ; ';' ; char
//@ 		jnz	short loc_2EE72	; Jump if Not Zero (ZF=0)
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 
//@ loc_2EE72:				; CODE XREF: Load3dObjects+76j
//@ 		cmp	[bp+c],	3Bh ; ';' ; char
//@ 		jnz	short loc_2EE82	; Jump if Not Zero (ZF=0)
//@ 		call	@IOResult$qv	; IOResult: Word{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jz	short loc_2EE4E	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2353
//@ 
//@ loc_2EE82:				; CODE XREF: Load3dObjects+87j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+10h], ax
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2354
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+17h], 1
//@ ; #line	"CSPBIO.PAS" 2355
//@ 		lea	di, [bp+var_18C] ; Load	Effective Address
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
//@ ; #line	"CSPBIO.PAS" 2356
//@ 		lea	di, [bp+var_28C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_18C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0Eh
//@ 		push	14h
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+AN]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2357
//@ 		cmp	[bp+var_83], 25h ; '%' ; Compare Two Operands
//@ 		jnz	short loc_2EF94	; Jump if Not Zero (ZF=0)
//@ 		lea	di, [bp+var_18C] ; Load	Effective Address
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
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+17h], 0
//@ ; #line	"CSPBIO.PAS" 2358
//@ 
//@ loc_2EF94:				; CODE XREF: Load3dObjects+177j
//@ 		lea	di, [bp+var_28C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_18C] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	1
//@ 		push	0Eh
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2359
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		mov	ax, es:[di+8]
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		mov	es:[di+8], ax
//@ 		cmp	word ptr es:[di+6], 0 ;	Compare	Two Operands
//@ 		jle	short loc_2EFD9	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		dec	word ptr es:[di+6] ; Decrement by 1
//@ ; #line	"CSPBIO.PAS" 2360
//@ 
//@ loc_2EFD9:				; CODE XREF: Load3dObjects+1E3j
//@ 		lea	di, [bp+FO]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		add	di, 1Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPOH		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2361
//@ 		lea	di, [bp+AN]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+1Ch]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4800h]
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		add	di, 20h	; ' '   ; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		add	di, 1Ah		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadAnimation	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2362
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+1Eh]
//@ 		push	word ptr es:[di+1Ch]
//@ 		add	di, 12h		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_8C]	; Load Full Pointer to ES:xx
//@ 		add	di, 14h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	ScanLoHi	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2363
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		cmp	ax, [bp+var_88]	; Compare Two Operands
//@ 		jz	short loc_2F046	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2EE39	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2364
//@ 
//@ loc_2F046:				; CODE XREF: Load3dObjects+41j
//@ 					; Load3dObjects+251j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__3 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2365
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ Load3dObjects	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadingRockets	db 19,' Loading Rockets...' ; DATA XREF: LoadRockets+9o
//@ aOk__4		db 3,'Ok.'              ; DATA XREF: LoadRockets+1FEo
//@ ; #line	"CSPBIO.PAS" 2371
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadRockets	proc near		; CODE XREF: LoadGraphics+99p
//@ 
//@ var_96		= dword	ptr -96h
//@ var_92		= word ptr -92h
//@ AName		= byte ptr -90h		; char[61] // Pascal string
//@ RName		= byte ptr -52h		; char[61] // Pascal string
//@ _ft		= word ptr -14h		; uint16_t
//@ _at2		= word ptr -12h		; uint16_t
//@ _at		= word ptr -10h		; uint16_t
//@ _lt		= word ptr -0Eh		; uint16_t
//@ _fb		= word ptr -0Ch		; uint16_t
//@ _rf		= word ptr -0Ah		; uint16_t
//@ o		= word ptr -4		; uint16_t
//@ rc		= word ptr -2		; uint16_t
//@ 
//@ 		enter	96h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2372
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadingRockets ; " Loading Rockets..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2373
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+rc], ax	; uint16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2375
//@ 		mov	ax, [bp+rc]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_92], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_92]	; Compare Two Operands
//@ 		jbe	short loc_2F0B5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2F26F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F0B5:				; CODE XREF: LoadRockets+3Aj
//@ 		mov	[bp+o],	ax	; uint16_t
//@ 		jmp	short loc_2F0BD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F0BA:				; CODE XREF: LoadRockets+1F6j
//@ 		inc	[bp+o]		; uint16_t
//@ 
//@ loc_2F0BD:				; CODE XREF: LoadRockets+42j
//@ 		imul	di, [bp+o], 16h	; uint16_t
//@ 		add	di, 0CD84h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_96], di
//@ 		mov	word ptr [bp+var_96+2],	es
//@ ; #line	"CSPBIO.PAS" 2377
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2378
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+RName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+RName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2379
//@ 		cmp	[bp+RName], 0	; char[61] // Pascal string
//@ 		jz	short loc_2F163	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2381
//@ 		lea	di, [bp+RName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 0Eh		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPOH		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2382
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+AName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+AName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2383
//@ 		lea	di, [bp+AName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+0Eh]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4800h]
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		add	di, 12h		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		add	di, 0Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadAnimation	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2384
//@ 		jmp	short loc_2F17A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F163:				; CODE XREF: LoadRockets+87j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+AName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2385
//@ 
//@ loc_2F17A:				; CODE XREF: LoadRockets+EBj
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		mov	byte ptr es:[di+0Ah], 0
//@ ; #line	"CSPBIO.PAS" 2386
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_rf], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_fb], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_lt], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_at], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_at2], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_ft], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Bh], al
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2388
//@ 		cmp	[bp+_rf], 0	; uint16_t
//@ 		jbe	short loc_2F219	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Ah], 20h ; ' ' ; Add
//@ ; #line	"CSPBIO.PAS" 2389
//@ 
//@ loc_2F219:				; CODE XREF: LoadRockets+198j
//@ 		cmp	[bp+_fb], 0	; uint16_t
//@ 		jbe	short loc_2F228	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Ah], 2	; Add
//@ ; #line	"CSPBIO.PAS" 2390
//@ 
//@ loc_2F228:				; CODE XREF: LoadRockets+1A7j
//@ 		cmp	[bp+_lt], 0	; uint16_t
//@ 		jbe	short loc_2F237	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Ah], 4	; Add
//@ ; #line	"CSPBIO.PAS" 2391
//@ 
//@ loc_2F237:				; CODE XREF: LoadRockets+1B6j
//@ 		cmp	[bp+_at], 0	; uint16_t
//@ 		jbe	short loc_2F246	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Ah], 8	; Add
//@ ; #line	"CSPBIO.PAS" 2392
//@ 
//@ loc_2F246:				; CODE XREF: LoadRockets+1C5j
//@ 		cmp	[bp+_at2], 0	; uint16_t
//@ 		jbe	short loc_2F255	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		add	byte ptr es:[di+0Ah], 10h ; Add
//@ ; #line	"CSPBIO.PAS" 2393
//@ 
//@ loc_2F255:				; CODE XREF: LoadRockets+1D4j
//@ 		cmp	[bp+_ft], 0	; uint16_t
//@ 		jbe	short loc_2F263	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_96]	; Load Full Pointer to ES:xx
//@ 		inc	byte ptr es:[di+0Ah] ; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2394
//@ 
//@ loc_2F263:				; CODE XREF: LoadRockets+1E3j
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		cmp	ax, [bp+var_92]	; Compare Two Operands
//@ 		jz	short loc_2F26F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2F0BA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2395
//@ 
//@ loc_2F26F:				; CODE XREF: LoadRockets+3Cj
//@ 					; LoadRockets+1F4j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__4 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2396
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadRockets	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadingGibs___	db 16,' Loading Gibs...' ; DATA XREF: LoadGibs+9o
//@ aEnd_6		db 4,'#end'             ; DATA XREF: LoadGibs+56o
//@ aS_1		db 2,'S:'               ; DATA XREF: LoadGibs+6Fo
//@ aOk__5		db 3,'Ok.'              ; DATA XREF: LoadGibs+104o
//@ ; #line	"CSPBIO.PAS" 2402
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadGibs	proc near		; CODE XREF: LoadGraphics+AFp
//@ 
//@ var_288		= byte ptr -288h
//@ var_188		= byte ptr -188h
//@ var_88		= dword	ptr -88h
//@ var_84		= byte ptr -84h		; char[61] // Pascal string
//@ SName		= byte ptr -46h		; char[61] // Pascal string
//@ p		= word ptr -8		; uint16_t
//@ o		= word ptr -4		; uint16_t
//@ 
//@ 		enter	288h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2403
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadingGibs___ ; " Loading Gibs..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2404
//@ 		mov	[bp+o],	47h ; 'G' ; uint16_t
//@ ; #line	"CSPBIO.PAS" 2407
//@ 
//@ loc_2F2C3:				; CODE XREF: LoadGibs+FCj
//@ 		imul	di, [bp+o], 12h	; uint16_t
//@ 		add	di, 0D044h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_88], di
//@ 		mov	word ptr [bp+var_88+2],	es
//@ ; #line	"CSPBIO.PAS" 2409
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2410
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2411
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aEnd_6 ; "#end"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2F309	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2F3A3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2412
//@ 
//@ loc_2F309:				; CODE XREF: LoadGibs+60j
//@ 		les	di, [bp+var_88]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	word ptr es:[di+4], 49h	; 'I'
//@ ; #line	"CSPBIO.PAS" 2414
//@ 		mov	di, offset aS_1	; "S:"
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		mov	[bp+p],	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2415
//@ 		cmp	[bp+p],	0	; uint16_t
//@ 		jz	short loc_2F37A	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 2416
//@ 		lea	di, [bp+var_288] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_188] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, [bp+p]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	4
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+var_84]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		lea	di, [bp+var_84]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset i$0	; int16_t
//@ 		push	ds
//@ 		push	di
//@ 		call	@Val__Longint$qm6Stringm7Integer ; Val(s: String; v: Longint{DX:AX}; var code: Integer)
//@ 		les	di, [bp+var_88]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, [bp+p]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+SName], al	; char[61] // Pascal string
//@ ; #line	"CSPBIO.PAS" 2418
//@ 
//@ loc_2F37A:				; CODE XREF: LoadGibs+85j
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_88]	; Load Full Pointer to ES:xx
//@ 		add	di, 6		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPOH		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2420
//@ 		les	di, [bp+var_88]	; Load Full Pointer to ES:xx
//@ 		mov	word ptr es:[di], 0Ah
//@ ; #line	"CSPBIO.PAS" 2421
//@ 		mov	word ptr es:[di+2], 4
//@ ; #line	"CSPBIO.PAS" 2422
//@ 		inc	[bp+o]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2423
//@ 		jmp	loc_2F2C3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2425
//@ 
//@ loc_2F3A3:				; CODE XREF: LoadGibs+62j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__5 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2426
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadGibs	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadingBlows__	db 17,' Loading Blows...' ; DATA XREF: LoadBlows+9o
//@ aBmp_0		db 4,'BMP\'             ; DATA XREF: LoadBlows+11Co
//@ aOk__6		db 3,'Ok.'              ; DATA XREF: LoadBlows+179o
//@ ; #line	"CSPBIO.PAS" 2431
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadBlows	proc near		; CODE XREF: LoadGraphics+C5p
//@ 
//@ var_316		= byte ptr -316h
//@ var_216		= byte ptr -216h
//@ var_116		= dword	ptr -116h
//@ var_112		= word ptr -112h
//@ BName		= byte ptr -110h	; char[256] // Pascal string
//@ o		= word ptr -10h		; uint16_t
//@ bcnt		= word ptr -0Eh		; uint16_t
//@ _lt		= word ptr -0Ch		; uint16_t
//@ _hf		= word ptr -0Ah		; uint16_t
//@ _jm		= word ptr -8		; uint16_t
//@ _gr		= word ptr -6		; uint16_t
//@ _lp		= word ptr -4		; uint16_t
//@ _sm		= word ptr -2		; uint16_t
//@ 
//@ 		enter	316h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2432
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadingBlows__ ; " Loading Blows..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2433
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+bcnt], ax	; uint16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2435
//@ 		mov	ax, [bp+bcnt]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	[bp+var_112], ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		cmp	ax, [bp+var_112] ; Compare Two Operands
//@ 		jbe	short loc_2F415	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2F54A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F415:				; CODE XREF: LoadBlows+3Aj
//@ 		mov	[bp+o],	ax	; uint16_t
//@ 		jmp	short loc_2F41D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F41A:				; CODE XREF: LoadBlows+171j
//@ 		inc	[bp+o]		; uint16_t
//@ 
//@ loc_2F41D:				; CODE XREF: LoadBlows+42j
//@ 		imul	di, [bp+o], 3Ah	; uint16_t
//@ 		add	di, 0D698h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_116], di
//@ 		mov	word ptr [bp+var_116+2], es
//@ ; #line	"CSPBIO.PAS" 2437
//@ 		mov	byte ptr es:[di+2], 0
//@ ; #line	"CSPBIO.PAS" 2438
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+3], al
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_hf], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_sm], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_lp], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_gr], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_jm], ax	; uint16_t
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+_lt], ax	; uint16_t
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2439
//@ 		cmp	[bp+_sm], 0	; uint16_t
//@ 		jbe	short loc_2F489	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		inc	byte ptr es:[di+2] ; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2440
//@ 
//@ loc_2F489:				; CODE XREF: LoadBlows+A9j
//@ 		cmp	[bp+_lp], 0	; uint16_t
//@ 		jbe	short loc_2F498	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		add	byte ptr es:[di+2], 2 ;	Add
//@ ; #line	"CSPBIO.PAS" 2441
//@ 
//@ loc_2F498:				; CODE XREF: LoadBlows+B7j
//@ 		cmp	[bp+_gr], 0	; uint16_t
//@ 		jbe	short loc_2F4A7	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		add	byte ptr es:[di+2], 4 ;	Add
//@ ; #line	"CSPBIO.PAS" 2442
//@ 
//@ loc_2F4A7:				; CODE XREF: LoadBlows+C6j
//@ 		cmp	[bp+_jm], 0	; uint16_t
//@ 		jbe	short loc_2F4B6	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		add	byte ptr es:[di+2], 8 ;	Add
//@ ; #line	"CSPBIO.PAS" 2443
//@ 
//@ loc_2F4B6:				; CODE XREF: LoadBlows+D5j
//@ 		cmp	[bp+_hf], 0	; uint16_t
//@ 		jbe	short loc_2F4C5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		add	byte ptr es:[di+2], 10h	; Add
//@ ; #line	"CSPBIO.PAS" 2444
//@ 
//@ loc_2F4C5:				; CODE XREF: LoadBlows+E4j
//@ 		cmp	[bp+_lt], 0	; uint16_t
//@ 		jbe	short loc_2F4D4	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		add	byte ptr es:[di+2], 20h	; ' ' ; Add
//@ ; #line	"CSPBIO.PAS" 2446
//@ 
//@ loc_2F4D4:				; CODE XREF: LoadBlows+F3j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+BName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+var_316] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aBmp_0 ; "BMP\\"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+var_216] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+BName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+BName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2447
//@ 		lea	di, [bp+BName]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		add	di, 4		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPicsPacket	; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2448
//@ 		les	di, [bp+var_116] ; Load	Full Pointer to	ES:xx
//@ 		mov	ax, es:[di+4]
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 2449
//@ 		mov	ax, [bp+o]	; uint16_t
//@ 		cmp	ax, [bp+var_112] ; Compare Two Operands
//@ 		jz	short loc_2F54A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2F41A	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2450
//@ 
//@ loc_2F54A:				; CODE XREF: LoadBlows+3Cj
//@ 					; LoadBlows+16Fj
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__6 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2451
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadBlows	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadingMonster	db 20,' Loading Monsters...' ; DATA XREF: LoadMonsters+9o
//@ aOk__7		db 3,'Ok.'              ; DATA XREF: LoadMonsters+13Co
//@ ; #line	"CSPBIO.PAS" 2463
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadMonsters	proc near		; CODE XREF: LoadGraphics+55p
//@ 
//@ var_12A		= byte ptr -12Ah
//@ var_2A		= dword	ptr -2Ah
//@ var_26		= word ptr -26h
//@ MName		= byte ptr -24h		; char[21] // Pascal string
//@ n		= word ptr -0Ah		; uint16_t
//@ j		= word ptr -4		; uint16_t
//@ mc		= word ptr -2		; uint16_t
//@ 
//@ 		enter	12Ah, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2464
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadingMonster ; " Loading Monsters..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2465
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	[bp+mc], ax	; uint16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2466
//@ 		cmp	[bp+mc], 0	; uint16_t
//@ 		ja	short loc_2F5B0	; Jump if Above	(CF=0 &	ZF=0)
//@ 		jmp	loc_2F6AD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2467
//@ 
//@ loc_2F5B0:				; CODE XREF: LoadMonsters+30j
//@ 		mov	ax, [bp+mc]	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		add	ax, 64h	; 'd'   ; Add
//@ 		mov	[bp+var_26], ax
//@ 		mov	ax, 64h	; 'd'
//@ 		cmp	ax, [bp+var_26]	; Compare Two Operands
//@ 		jbe	short loc_2F5C5	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	loc_2F6AD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F5C5:				; CODE XREF: LoadMonsters+45j
//@ 		mov	[bp+j],	ax	; uint16_t
//@ 		jmp	short loc_2F5CD	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F5CA:				; CODE XREF: LoadMonsters+12Fj
//@ 		inc	[bp+j]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2468
//@ 
//@ loc_2F5CD:				; CODE XREF: LoadMonsters+4Dj
//@ 		imul	di, [bp+j], 0A2h ; uint16_t
//@ 		add	di, 7FAEh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_2A], di
//@ 		mov	word ptr [bp+var_2A+2],	es
//@ ; #line	"CSPBIO.PAS" 2470
//@ 		mov	[bp+n],	1	; uint16_t
//@ 		jmp	short loc_2F5E8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F5E5:				; CODE XREF: LoadMonsters+86j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_2F5E8:				; CODE XREF: LoadMonsters+68j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text4Char ; Read(var f; var c:	Char{AL})
//@ 		mov	di, [bp+n]	; uint16_t
//@ 		mov	[bp+di+MName], al ; char[21] //	Pascal string
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ 		cmp	[bp+n],	0Eh	; uint16_t
//@ 		jnz	short loc_2F5E5	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+MName], 0Eh	; char[21] // Pascal string
//@ ; #line	"CSPBIO.PAS" 2471
//@ 		lea	di, [bp+var_12A] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+MName]	; char[21] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 19h		; Add
//@ 		push	es
//@ 		push	di
//@ 		push	0Ch
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2472
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSPBIO.PAS" 2473
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+12h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+14h], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_2A]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+16h], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2481
//@ 		push	[bp+j]		; uint16_t
//@ 		call	InitCaracter	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2482
//@ 		mov	ax, [bp+j]	; uint16_t
//@ 		cmp	ax, [bp+var_26]	; Compare Two Operands
//@ 		jz	short loc_2F6AD	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2F5CA	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2484
//@ 
//@ loc_2F6AD:				; CODE XREF: LoadMonsters+32j
//@ 					; LoadMonsters+47j ...
//@ 		sub	MonstersInfo.MWidth+144h, 0Ch ;	struct TMonsterInfo[23]
//@ ; #line	"CSPBIO.PAS" 2486
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__7 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2487
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadMonsters	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aLoadingWeapons	db 19,' Loading Weapons...' ; DATA XREF: LoadGunsInfo+9o
//@ aOk__8		db 3,'Ok.'              ; DATA XREF: LoadGunsInfo+1AAo
//@ ; #line	"CSPBIO.PAS" 2498
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadGunsInfo	proc near		; CODE XREF: LoadGraphics+DBp
//@ 
//@ var_C4		= dword	ptr -0C4h
//@ var_C0		= word ptr -0C0h
//@ AName		= byte ptr -0BEh	; char[61] // Pascal string
//@ SName		= byte ptr -80h		; char[61] // Pascal string
//@ GName		= byte ptr -42h		; char[61] // Pascal string
//@ g		= word ptr -2		; int16_t
//@ 
//@ 		enter	0C4h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2499
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aLoadingWeapons ; " Loading Weapons..."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@Write$qm4Text	; Write(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2500
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		mov	WeaponsCount, ax ; uint16_t
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2501
//@ 		mov	ax, WeaponsCount ; uint16_t
//@ 		mov	[bp+var_C0], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_C0]	; Compare Two Operands
//@ 		jle	short loc_2F721	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	loc_2F887	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F721:				; CODE XREF: LoadGunsInfo+3Aj
//@ 		mov	[bp+g],	ax	; int16_t
//@ 		jmp	short loc_2F729	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F726:				; CODE XREF: LoadGunsInfo+1A2j
//@ 		inc	[bp+g]		; int16_t
//@ 
//@ loc_2F729:				; CODE XREF: LoadGunsInfo+42j
//@ 		mov	di, [bp+g]	; int16_t
//@ 		shl	di, 5		; Shift	Logical	Left
//@ 		add	di, 0E440h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_C4], di
//@ 		mov	word ptr [bp+var_C4+2],	es
//@ ; #line	"CSPBIO.PAS" 2503
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+GName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+GName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2504
//@ 		lea	di, [bp+GName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		add	di, 14h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadPOH		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2506
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2507
//@ 		lea	di, [bp+SName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+14h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4800h]
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		add	di, 18h		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		add	di, 12h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadAnimation	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2509
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+AName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		lea	di, [bp+AName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	RemoveEqual	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2510
//@ 		lea	di, [bp+AName]	; char[61] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		les	di, es:[di+14h]	; Load Full Pointer to ES:xx
//@ 		push	word ptr es:[di+4800h]
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		add	di, 1Ch		; Add
//@ 		push	es
//@ 		push	di
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		add	di, 10h		; Add
//@ 		push	es
//@ 		push	di
//@ 		call	LoadAnimation	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2512
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Eh], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ch], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+4], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+6], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+8], ax
//@ 		call	@Read$qm4Text7Longint ;	Read(var f; var	v: Longint{DX:AX})
//@ 		les	di, [bp+var_C4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+0Ah], ax
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2515
//@ 		mov	ax, [bp+g]	; int16_t
//@ 		cmp	ax, [bp+var_C0]	; Compare Two Operands
//@ 		jz	short loc_2F887	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2F726	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2516
//@ 
//@ loc_2F887:				; CODE XREF: LoadGunsInfo+3Cj
//@ 					; LoadGunsInfo+1A0j
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aOk__8 ; "Ok."
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2517
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ LoadGunsInfo	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ a__10		db 1,'.'                ; DATA XREF: ScanLevels:loc_2F8D0o
//@ 					; ScanLevels+2Eo
//@ a@_25		db 2,'@#'               ; DATA XREF: ScanLevels+52o
//@ aLevel_10	db 5,'LEVEL'            ; DATA XREF: ScanLevels+7Co
//@ aResource__0	db 10,'\resource.'      ; DATA XREF: ScanLevels+91o
//@ aName		db 6,'#name='           ; DATA XREF: ScanLevels+112o
//@ a____2		db 3,'...'              ; DATA XREF: ScanLevels+1B4o
//@ ; #line	"CSPBIO.PAS" 2523
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ScanLevels	proc far		; CODE XREF: PROGRAM+CBCP
//@ 
//@ var_300		= byte ptr -300h
//@ var_200		= byte ptr -200h
//@ mask		= byte ptr -100h	; char[256] // Pascal string
//@ 
//@ 		enter	300h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2524
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_2F8D0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2F8CC:				; CODE XREF: ScanLevels+1F2j
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 2526
//@ 
//@ loc_2F8D0:				; CODE XREF: ScanLevels+Aj
//@ 		mov	di, offset a__10 ; "."
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, LevelNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	1Fh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2527
//@ 		mov	di, offset a__10 ; "."
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, ShortNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	1Fh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2528
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset a@_25 ; "@#"
//@ 		push	cs
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		call	Form		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2529
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset aLevel_10 ; "LEVEL"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		mov	di, offset aResource__0	; "\\resource."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2530
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	FExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//@ 		or	al, al		; Logical Inclusive OR
//@ 		jnz	short loc_2F986	; Jump if Not Zero (ZF=0)
//@ 		jmp	loc_2FAAB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2532
//@ 
//@ loc_2F986:				; CODE XREF: ScanLevels+C1j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	TOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2534
//@ 
//@ loc_2F996:				; CODE XREF: ScanLevels+124j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ ; #line	"CSPBIO.PAS" 2535
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2536
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2537
//@ 		mov	di, offset aName ; "#name="
//@ 		push	cs
//@ 		push	di
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@Pos$qm6Stringt1 ; Pos(substr: String, s: String): Byte{AX}
//@ 		or	ax, ax		; Logical Inclusive OR
//@ 		jle	short loc_2F996	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPBIO.PAS" 2538
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4Text	; Close(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2539
//@ 		lea	di, [bp+var_300] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	7
//@ 		push	32h ; '2'
//@ 		call	@Copy$qm6Stringt17Integert3 ; Copy(s: String, index: Integer, count: Integer): String
//@ 		call	Trim		; function far PASCAL returns PASCAL string 'STRING' max FF
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2540
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, LevelNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	1Fh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2541
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	CalcStringLen	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 84h	; 'ﾄ'   ; Compare Two Operands
//@ 		jbe	short loc_2FA8C	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPBIO.PAS" 2543
//@ 
//@ loc_2FA4D:				; CODE XREF: ScanLevels+1A1j
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	CalcStringLen	; function far PASCAL returns unsigned int 'Word'
//@ 		cmp	ax, 7Ah	; 'z'   ; Compare Two Operands
//@ 		jbe	short loc_2FA63	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		dec	[bp+mask]	; char[256] // Pascal string
//@ 		jmp	short loc_2FA4D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2544
//@ 
//@ loc_2FA63:				; CODE XREF: ScanLevels+19Bj
//@ 		lea	di, [bp+var_200] ; Load	Effective Address
//@ 		push	ss
//@ 		push	di
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	@$basg$qm6Stringt1 ; Load string
//@ 		mov	di, offset a____2 ; "..."
//@ 		push	cs
//@ 		push	di
//@ 		call	@Concat$qm6Stringt1 ; Concat(dst, src: String):	String
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2546
//@ 
//@ loc_2FA8C:				; CODE XREF: ScanLevels+18Bj
//@ 		lea	di, [bp+mask]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	ax, n$0		; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, ShortNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		push	1Fh
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 2548
//@ 
//@ loc_2FAAB:				; CODE XREF: ScanLevels+C3j
//@ 		cmp	n$0, 40h ; '@'  ; int16_t
//@ 		jz	short locret_2FAB5 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_2F8CC	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2549
//@ 
//@ locret_2FAB5:				; CODE XREF: ScanLevels+1F0j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ScanLevels	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2554
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ FindNextLevel	proc far		; CODE XREF: PROGRAM:loc_EEECP
//@ 		enter	100h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2555
//@ 		mov	n$0, 1		; int16_t
//@ 		jmp	short loc_2FAC7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2FAC3:				; CODE XREF: FindNextLevel+3Cj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 2557
//@ 
//@ loc_2FAC7:				; CODE XREF: FindNextLevel+Aj
//@ 		inc	LevelN		; int16_t
//@ 		cmp	LevelN,	40h ; '@' ; int16_t
//@ 		jle	short loc_2FAD8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	LevelN,	1	; int16_t
//@ ; #line	"CSPBIO.PAS" 2558
//@ 
//@ loc_2FAD8:				; CODE XREF: FindNextLevel+19j
//@ 		mov	ax, LevelN	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, LevelNames	; char*
//@ 		add	di, ax		; Add
//@ 		cmp	byte ptr es:[di-20h], 1	; Compare Two Operands
//@ 		jz	short loc_2FAED	; Jump if Zero (ZF=1)
//@ 		jmp	short locret_2FAF5 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2559
//@ 
//@ loc_2FAED:				; CODE XREF: FindNextLevel+32j
//@ 		cmp	n$0, 80h ; 'ﾀ'  ; int16_t
//@ 		jnz	short loc_2FAC3	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2560
//@ 
//@ locret_2FAF5:				; CODE XREF: FindNextLevel+34j
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ FindNextLevel	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aReadingGraphic	db 29,'Reading graphics information:' ; DATA XREF: LoadGraphics+8o
//@ aChasm_inf	db 9,'chasm.inf'        ; DATA XREF: LoadGraphics+1Eo
//@ aMonsters	db 10,'[MONSTERS]'      ; DATA XREF: LoadGraphics+49o
//@ aBmp_objects	db 13,'[BMP_OBJECTS]'   ; DATA XREF: LoadGraphics+60o
//@ a3d_objects	db 12,'[3D_OBJECTS]'    ; DATA XREF: LoadGraphics+77o
//@ aRockets	db 9,'[ROCKETS]'        ; DATA XREF: LoadGraphics+8Do
//@ aGibs		db 6,'[GIBS]'           ; DATA XREF: LoadGraphics+A3o
//@ aBlows		db 7,'[BLOWS]'          ; DATA XREF: LoadGraphics+B9o
//@ aWeapons	db 9,'[WEAPONS]'        ; DATA XREF: LoadGraphics+CFo
//@ aSounds		db 8,'[SOUNDS]'         ; DATA XREF: LoadGraphics+E5o
//@ aEnd__1		db 4,'END.'             ; DATA XREF: LoadGraphics+F9o
//@ a__11		db 1,'.'                ; DATA XREF: LoadGraphics+124o
//@ ; #line	"CSPBIO.PAS" 2565
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadGraphics	proc far		; CODE XREF: PROGRAM+CF2P
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 2566
//@ 		mov	di, offset Output ; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aReadingGraphic ; "Reading graphics information:"
//@ 		push	cs
//@ 		push	di
//@ 		push	0
//@ 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//@ 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2567
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aChasm_inf ;	"chasm.inf"
//@ 		push	cs
//@ 		push	di
//@ 		call	TOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2569
//@ 
//@ loc_2FBA0:				; CODE XREF: LoadGraphics+105j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	0FFh
//@ 		call	@Read$qm4Textm6String4Word ; Read(var f; var s:	String;	width: Word)
//@ 		call	@ReadLn$qm4Text	; ReadLn(var f:	Text)
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2570
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aMonsters ; "[MONSTERS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FBD3	; Jump if Not Zero (ZF=0)
//@ 		call	LoadMonsters	; function near	PASCAL returns void
//@ 		jmp	loc_2FC6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2571
//@ 
//@ loc_2FBD3:				; CODE XREF: LoadGraphics+53j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aBmp_objects	; "[BMP_OBJECTS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FBEA	; Jump if Not Zero (ZF=0)
//@ 		call	LoadBMPObjects	; function near	PASCAL returns void
//@ 		jmp	loc_2FC6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2572
//@ 
//@ loc_2FBEA:				; CODE XREF: LoadGraphics+6Aj
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset a3d_objects ; "[3D_OBJECTS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FC00	; Jump if Not Zero (ZF=0)
//@ 		call	Load3dObjects	; function near	PASCAL returns void
//@ 		jmp	short loc_2FC6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2573
//@ 
//@ loc_2FC00:				; CODE XREF: LoadGraphics+81j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aRockets ; "[ROCKETS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FC16	; Jump if Not Zero (ZF=0)
//@ 		call	LoadRockets	; function near	PASCAL returns void
//@ 		jmp	short loc_2FC6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2574
//@ 
//@ loc_2FC16:				; CODE XREF: LoadGraphics+97j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aGibs ; "[GIBS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FC2C	; Jump if Not Zero (ZF=0)
//@ 		call	LoadGibs	; function near	PASCAL returns void
//@ 		jmp	short loc_2FC6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2575
//@ 
//@ loc_2FC2C:				; CODE XREF: LoadGraphics+ADj
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aBlows ; "[BLOWS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FC42	; Jump if Not Zero (ZF=0)
//@ 		call	LoadBlows	; function near	PASCAL returns void
//@ 		jmp	short loc_2FC6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2576
//@ 
//@ loc_2FC42:				; CODE XREF: LoadGraphics+C3j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aWeapons ; "[WEAPONS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FC58	; Jump if Not Zero (ZF=0)
//@ 		call	LoadGunsInfo	; function near	PASCAL returns void
//@ 		jmp	short loc_2FC6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2577
//@ 
//@ loc_2FC58:				; CODE XREF: LoadGraphics+D9j
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aSounds ; "[SOUNDS]"
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short loc_2FC6C	; Jump if Not Zero (ZF=0)
//@ 		call	LoadSounds	; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2578
//@ 
//@ loc_2FC6C:				; CODE XREF: LoadGraphics+58j
//@ 					; LoadGraphics+6Fj ...
//@ 		mov	di, offset S	; char[256] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aEnd__1 ; "END."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jz	short loc_2FC80	; Jump if Zero (ZF=1)
//@ 		jmp	loc_2FBA0	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2579
//@ 
//@ loc_2FC80:				; CODE XREF: LoadGraphics+103j
//@ 		mov	di, offset Ft	; Text
//@ 		push	ds
//@ 		push	di
//@ 		call	@Close$qm4Text	; Close(var f: Text)
//@ ; #line	"CSPBIO.PAS" 2580
//@ 		mov	ax, LevelN	; int16_t
//@ 		shl	ax, 5		; Shift	Logical	Left
//@ 		les	di, LevelNames	; char*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFE0h	; Add
//@ 		push	es
//@ 		push	di
//@ 		mov	di, offset a__11 ; "."
//@ 		push	cs
//@ 		push	di
//@ 		call	@$bsub$qm6Stringt1 ; Compare two strings
//@ 					; ZF - src=dst
//@ 					; CF - src<dst
//@ 		jnz	short locret_2FCAE ; Jump if Not Zero (ZF=0)
//@ 		mov	LevelN,	1	; int16_t
//@ ; #line	"CSPBIO.PAS" 2581
//@ 
//@ locret_2FCAE:				; CODE XREF: LoadGraphics+12Ej
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ LoadGraphics	endp
//@ 
//@ ; ---------------------------------------------------------------------------
//@ aCommonVesatile	db 19,'COMMON\vesatile.cel' ; DATA XREF: LoadGround+9o
//@ aCommonStatus2_	db 18,'COMMON\status2.cel' ; DATA XREF: LoadGround+48o
//@ aCommonGround_c	db 17,'COMMON\ground.cel' ; DATA XREF: LoadGround+8Co
//@ aCommonLoading_	db 18,'COMMON\loading.cel' ; DATA XREF: LoadGround+11Fo
//@ ; #line	"CSPBIO.PAS" 2592
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ LoadGround	proc far		; CODE XREF: LoadCommonParts+3B1P
//@ 
//@ y		= word ptr -4		; uint16_t
//@ x		= word ptr -2		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2594
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonVesatile ; "COMMON\\vesatile.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2595
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2596
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, VesaTiler	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2597
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2599
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonStatus2_ ; "COMMON\\status2.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2600
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2601
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, Status	; void*
//@ 		push	es
//@ 		push	di
//@ 		push	5F00h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2602
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ 		call	ChI		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2605
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonGround_c ; "COMMON\\ground.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2606
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2607
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		push	ax
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	1000h
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2608
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2609
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+x],	ax	; uint16_t
//@ 		jmp	short loc_2FDCF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2FDCC:				; CODE XREF: LoadGround+118j
//@ 		inc	[bp+x]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2610
//@ 
//@ loc_2FDCF:				; CODE XREF: LoadGround+CEj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+y],	ax	; uint16_t
//@ 		jmp	short loc_2FDD9	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_2FDD6:				; CODE XREF: LoadGround+112j
//@ 		inc	[bp+y]		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2611
//@ 
//@ loc_2FDD9:				; CODE XREF: LoadGround+D8j
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		push	ax
//@ 		mov	ax, [bp+y]	; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		les	di, Ground	; void*
//@ 		mov	ax, es
//@ 		push	ax
//@ 		mov	ax, [bp+x]	; uint16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+y], 140h ; uint16_t
//@ 		add	ax, dx		; Add
//@ 		mov	di, ax
//@ 		pop	es
//@ 		push	es
//@ 		push	di
//@ 		push	40h ; '@'
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ 		cmp	[bp+y],	3Fh ; '?' ; uint16_t
//@ 		jnz	short loc_2FDD6	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+x],	4	; uint16_t
//@ 		jnz	short loc_2FDCC	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2615
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset aCommonLoading_ ; "COMMON\\loading.cel"
//@ 		push	cs
//@ 		push	di
//@ 		call	FOpen		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2616
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset LoadingW ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2617
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset LoadingW ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2618
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset LoadingH ; uint16_t
//@ 		push	ds
//@ 		push	di
//@ 		push	2
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2619
//@ 		mov	di, offset Loading ; void*
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, LoadingW	; uint16_t
//@ 		mul	LoadingH	; uint16_t
//@ 		push	ax
//@ 		call	GetMem16	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2620
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		push	0
//@ 		push	320h
//@ 		call	FSeek		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2621
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		les	di, Loading	; void*
//@ 		push	es
//@ 		push	di
//@ 		mov	ax, LoadingW	; uint16_t
//@ 		mul	LoadingH	; uint16_t
//@ 		push	ax
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		push	ax
//@ 		push	ax
//@ 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
//@ ; #line	"CSPBIO.PAS" 2622
//@ 		mov	di, offset F	; struct BFile
//@ 		push	ds
//@ 		push	di
//@ 		call	FClose		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2623
//@ 		mov	ax, LoadingH	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	LoadingH, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2624
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ LoadGround	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2637
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ CLine		proc near		; CODE XREF: Line+372p
//@ 
//@ ScOfs		= dword	ptr -0Eh	; struct DWord
//@ DScrY		= dword	ptr -0Ah	; int32_t
//@ d		= word ptr -6		; int16_t
//@ ddy		= word ptr -4		; int16_t
//@ ddx		= word ptr -2		; int16_t
//@ C		= byte ptr  4		; uint8_t
//@ y2		= word ptr  6		; int16_t
//@ x2		= word ptr  8		; int16_t
//@ y1		= word ptr  0Ah		; int16_t
//@ x1		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	0Eh, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2639
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		cmp	ax, [bp+x1]	; int16_t
//@ 		jnb	short loc_2FED9	; Jump if Not Below (CF=0)
//@ ; #line	"CSPBIO.PAS" 2640
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+x2]		; int16_t
//@ 		pop	[bp+x1]		; int16_t
//@ 		pop	[bp+x2]		; int16_t
//@ ; #line	"CSPBIO.PAS" 2641
//@ 		push	[bp+y1]		; int16_t
//@ 		push	[bp+y2]		; int16_t
//@ 		pop	[bp+y1]		; int16_t
//@ 		pop	[bp+y2]		; int16_t
//@ ; #line	"CSPBIO.PAS" 2644
//@ 
//@ loc_2FED9:				; CODE XREF: CLine+Aj
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	bx, [bp+y1]	; int16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+x1]	; int16_t
//@ ; #line	"CSPBIO.PAS" 2645
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPBIO.PAS" 2646
//@ 		mov	[bp+ScOfs], edi	; struct DWord
//@ ; #line	"CSPBIO.PAS" 2647
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 2648
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		cmp	ax, [bp+y1]	; int16_t
//@ 		jnz	short loc_2FF0E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2649
//@ 		mov	cx, [bp+x2]	; int16_t
//@ 		sub	cx, [bp+x1]	; int16_t
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2650
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ 		mov	al, [bp+C]	; uint8_t
//@ ; #line	"CSPBIO.PAS" 2651
//@ 		rep stos byte ptr es:[edi] ; Store String
//@ ; #line	"CSPBIO.PAS" 2652
//@ 		jmp	locret_30025	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2653
//@ 
//@ loc_2FF0E:				; CODE XREF: CLine+42j
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		mov	[bp+ddx], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2654
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		mov	[bp+ddy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2655
//@ 		mov	[bp+d],	0	; int16_t
//@ ; #line	"CSPBIO.PAS" 2658
//@ 		mov	ax, [bp+ddy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+ddx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jle	short loc_2FFB1	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPBIO.PAS" 2660
//@ 		cmp	[bp+ddy], 0	; int16_t
//@ 		jge	short loc_2FF5F	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+ddy]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+ddy], ax	; int16_t
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		mov	word ptr [bp+DScrY], ax	; int32_t
//@ 		mov	word ptr [bp+DScrY+2], dx ; int32_t
//@ 		jmp	short loc_2FF6C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2661
//@ 
//@ loc_2FF5F:				; CODE XREF: CLine+8Aj
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		mov	word ptr [bp+DScrY], ax	; int32_t
//@ 		mov	word ptr [bp+DScrY+2], dx ; int32_t
//@ ; #line	"CSPBIO.PAS" 2662
//@ 
//@ loc_2FF6C:				; CODE XREF: CLine+A8j
//@ 		mov	ax, [bp+ddx]	; int16_t
//@ 		add	ax, [bp+ddy]	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	[bp+d],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2664
//@ 		mov	ebx, [bp+ScOfs]	; struct DWord
//@ ; #line	"CSPBIO.PAS" 2665
//@ 		mov	di, [bp+ddy]	; int16_t
//@ ; #line	"CSPBIO.PAS" 2666
//@ 		mov	si, [bp+ddx]	; int16_t
//@ ; #line	"CSPBIO.PAS" 2667
//@ 		mov	cx, si
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2668
//@ 		mov	dx, [bp+d]	; int16_t
//@ ; #line	"CSPBIO.PAS" 2669
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2670
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2671
//@ 		mov	al, [bp+C]	; uint8_t
//@ ; #line	"CSPBIO.PAS" 2672
//@ 		push	bp
//@ ; #line	"CSPBIO.PAS" 2673
//@ 		push	large [bp+DScrY] ; int32_t
//@ ; #line	"CSPBIO.PAS" 2674
//@ 		xor	ebp, ebp	; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 2675
//@ 		pop	ebp
//@ ; #line	"CSPBIO.PAS" 2677
//@ 
//@ loc_2FF99:				; CODE XREF: CLine+EEj
//@ 		add	dx, di		; Add
//@ ; #line	"CSPBIO.PAS" 2678
//@ 		jg	short loc_2FFA7	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSPBIO.PAS" 2679
//@ 
//@ loc_2FF9D:				; CODE XREF: CLine+F7j
//@ 		mov	es:[ebx], al
//@ ; #line	"CSPBIO.PAS" 2680
//@ 		inc	ebx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2681
//@ 		loop	loc_2FF99	; Loop while CX	!= 0
//@ ; #line	"CSPBIO.PAS" 2682
//@ 		jmp	short loc_2FFAE	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2683
//@ 
//@ loc_2FFA7:				; CODE XREF: CLine+E6j
//@ 		sub	dx, si		; Integer Subtraction
//@ ; #line	"CSPBIO.PAS" 2684
//@ 		add	ebx, ebp	; Add
//@ ; #line	"CSPBIO.PAS" 2685
//@ 		jmp	short loc_2FF9D	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2686
//@ 
//@ loc_2FFAE:				; CODE XREF: CLine+F0j
//@ 		pop	bp
//@ ; #line	"CSPBIO.PAS" 2688
//@ 		jmp	short locret_30025 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2690
//@ 
//@ loc_2FFB1:				; CODE XREF: CLine+84j
//@ 		cmp	[bp+ddy], 0	; int16_t
//@ 		jge	short loc_2FFD5	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+ddy]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+ddy], ax	; int16_t
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 		mov	word ptr [bp+DScrY], ax	; int32_t
//@ 		mov	word ptr [bp+DScrY+2], dx ; int32_t
//@ 		jmp	short loc_2FFE2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2691
//@ 
//@ loc_2FFD5:				; CODE XREF: CLine+100j
//@ 		mov	ax, word ptr VideoBPL ;	int32_t
//@ 		mov	dx, word ptr VideoBPL+2	; int32_t
//@ 		mov	word ptr [bp+DScrY], ax	; int32_t
//@ 		mov	word ptr [bp+DScrY+2], dx ; int32_t
//@ ; #line	"CSPBIO.PAS" 2692
//@ 
//@ loc_2FFE2:				; CODE XREF: CLine+11Ej
//@ 		mov	ax, [bp+ddy]	; int16_t
//@ 		add	ax, [bp+ddx]	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		sub	[bp+d],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2694
//@ 		mov	ebx, [bp+ScOfs]	; struct DWord
//@ ; #line	"CSPBIO.PAS" 2695
//@ 		mov	di, [bp+ddy]	; int16_t
//@ ; #line	"CSPBIO.PAS" 2696
//@ 		mov	si, [bp+ddx]	; int16_t
//@ ; #line	"CSPBIO.PAS" 2697
//@ 		mov	cx, di
//@ 		inc	cx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2698
//@ 		mov	dx, [bp+d]	; int16_t
//@ ; #line	"CSPBIO.PAS" 2699
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2700
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2701
//@ 		mov	al, [bp+C]	; uint8_t
//@ ; #line	"CSPBIO.PAS" 2702
//@ 		push	bp
//@ ; #line	"CSPBIO.PAS" 2703
//@ 		push	large [bp+DScrY] ; int32_t
//@ ; #line	"CSPBIO.PAS" 2704
//@ 		xor	ebp, ebp	; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 2705
//@ 		pop	ebp
//@ ; #line	"CSPBIO.PAS" 2708
//@ 
//@ loc_3000F:				; CODE XREF: CLine+165j
//@ 		add	dx, si		; Add
//@ ; #line	"CSPBIO.PAS" 2709
//@ 		jg	short loc_3001E	; Jump if Greater (ZF=0	& SF=OF)
//@ ; #line	"CSPBIO.PAS" 2710
//@ 
//@ loc_30013:				; CODE XREF: CLine+16Dj
//@ 		mov	es:[ebx], al
//@ ; #line	"CSPBIO.PAS" 2711
//@ 		add	ebx, ebp	; Add
//@ ; #line	"CSPBIO.PAS" 2712
//@ 		loop	loc_3000F	; Loop while CX	!= 0
//@ ; #line	"CSPBIO.PAS" 2713
//@ 		jmp	short loc_30024	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2714
//@ 
//@ loc_3001E:				; CODE XREF: CLine+15Cj
//@ 		sub	dx, di		; Integer Subtraction
//@ ; #line	"CSPBIO.PAS" 2715
//@ 		inc	ebx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2716
//@ 		jmp	short loc_30013	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2717
//@ 
//@ loc_30024:				; CODE XREF: CLine+167j
//@ 		pop	bp
//@ ; #line	"CSPBIO.PAS" 2721
//@ 
//@ locret_30025:				; CODE XREF: CLine+56j	CLine+FAj
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ CLine		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2748
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function nested near PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutPixel	proc near		; CODE XREF: Line+11Bp	Line+201p ...
//@ 
//@ col		= byte ptr  6		; uint8_t
//@ y		= word ptr  8		; uint16_t
//@ x		= word ptr  0Ah		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 2749
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2750
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	bx, [bp+y]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+x]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2751
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPBIO.PAS" 2752
//@ 		mov	al, [bp+col]	; uint8_t
//@ ; #line	"CSPBIO.PAS" 2753
//@ 		mov	es:[edi], al
//@ ; #line	"CSPBIO.PAS" 2754
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ PutPixel	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2758
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Line		proc near		; CODE XREF: ShowMap+123p ShowMap+1A1p ...
//@ 
//@ ys		= word ptr -12h		; int16_t
//@ xs		= word ptr -10h		; int16_t
//@ ye		= word ptr -0Ah		; int16_t
//@ yb		= word ptr -8		; int16_t
//@ xe		= word ptr -6		; int16_t
//@ xb		= word ptr -4		; int16_t
//@ col		= byte ptr  4		; uint8_t
//@ y2		= word ptr  6		; int16_t
//@ x2		= word ptr  8		; int16_t
//@ y1		= word ptr  0Ah		; int16_t
//@ x1		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	12h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2764
//@ 		mov	bx, mpk_x	; int16_t
//@ ; #line	"CSPBIO.PAS" 2765
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSPBIO.PAS" 2766
//@ 		rol	eax, 10h	; Rotate Left
//@ 		mov	ax, dx
//@ 		rol	eax, 10h	; Rotate Left
//@ 		sar	eax, 0Ch	; Shift	Arithmetic Right
//@ 		mov	[bp+x1], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2767
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSPBIO.PAS" 2768
//@ 		rol	eax, 10h	; Rotate Left
//@ 		mov	ax, dx
//@ 		rol	eax, 10h	; Rotate Left
//@ 		sar	eax, 0Ch	; Shift	Arithmetic Right
//@ 		mov	[bp+x2], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2769
//@ 		mov	bx, mpk_y	; int16_t
//@ ; #line	"CSPBIO.PAS" 2770
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSPBIO.PAS" 2771
//@ 		rol	eax, 10h	; Rotate Left
//@ 		mov	ax, dx
//@ 		rol	eax, 10h	; Rotate Left
//@ 		sar	eax, 0Ch	; Shift	Arithmetic Right
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2772
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		imul	bx		; Signed Multiply
//@ ; #line	"CSPBIO.PAS" 2773
//@ 		rol	eax, 10h	; Rotate Left
//@ 		mov	ax, dx
//@ 		rol	eax, 10h	; Rotate Left
//@ 		sar	eax, 0Ch	; Shift	Arithmetic Right
//@ 		mov	[bp+y2], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2776
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		cmp	ax, [bp+x2]	; int16_t
//@ 		jge	short loc_300D3	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		mov	[bp+xb], ax	; int16_t
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+xe], ax	; int16_t
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		mov	[bp+yb], ax	; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+ye], ax	; int16_t
//@ 		jmp	short loc_300EB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2777
//@ 
//@ loc_300D3:				; CODE XREF: Line+6Aj
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		mov	[bp+xb], ax	; int16_t
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		mov	[bp+xe], ax	; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		mov	[bp+yb], ax	; int16_t
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		mov	[bp+ye], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2779
//@ 
//@ loc_300EB:				; CODE XREF: Line+84j
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		mov	[bp+xs], ax	; int16_t
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		sub	ax, [bp+y2]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ys], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2780
//@ 		mov	ax, WMapX	; int16_t
//@ 		add	[bp+xb], ax	; int16_t
//@ 		mov	ax, WMapX	; int16_t
//@ 		add	[bp+xe], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2781
//@ 		mov	ax, WMapY	; int16_t
//@ 		add	[bp+yb], ax	; int16_t
//@ 		mov	ax, WMapY	; int16_t
//@ 		add	[bp+ye], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2783
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		cmp	ax, WMapX1	; int16_t
//@ 		jl	short loc_3014E	; Jump if Less (SF!=OF)
//@ 		push	[bp+ye]		; int16_t
//@ 		push	[bp+yb]		; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, WMapY1	; int16_t
//@ 		jl	short loc_3014E	; Jump if Less (SF!=OF)
//@ 		mov	ax, [bp+xb]	; int16_t
//@ 		cmp	ax, WMapX2	; int16_t
//@ 		jg	short loc_3014E	; Jump if Greater (ZF=0	& SF=OF)
//@ 		push	[bp+yb]		; int16_t
//@ 		push	[bp+ye]		; int16_t
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, WMapY2	; int16_t
//@ 		jle	short loc_30151	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPBIO.PAS" 2786
//@ 
//@ loc_3014E:				; CODE XREF: Line+D4j Line+E5j ...
//@ 		jmp	locret_303C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2788
//@ 
//@ loc_30151:				; CODE XREF: Line+FFj
//@ 		cmp	[bp+xs], 0	; int16_t
//@ 		jnz	short loc_3016E	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+ys], 0	; int16_t
//@ 		jnz	short loc_3016E	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+xb]		; int16_t
//@ 		push	[bp+yb]		; int16_t
//@ 		mov	al, [bp+col]	; uint8_t
//@ 		push	ax
//@ 		push	bp
//@ 		call	PutPixel	; function nested near PASCAL returns void
//@ 		jmp	locret_303C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2790
//@ 
//@ loc_3016E:				; CODE XREF: Line+108j	Line+10Ej
//@ 		mov	ax, [bp+xb]	; int16_t
//@ 		cmp	ax, WMapX1	; int16_t
//@ 		jge	short loc_301B5	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPBIO.PAS" 2792
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, WMapX1	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		sub	ax, [bp+yb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+yb], ax	; int16_t
//@ 		mov	ax, WMapX1	; int16_t
//@ 		mov	[bp+xb], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2794
//@ 
//@ loc_301B5:				; CODE XREF: Line+128j
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		cmp	ax, WMapX2	; int16_t
//@ 		jle	short loc_301FB	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPBIO.PAS" 2796
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, WMapX2	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		sub	ax, [bp+yb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+yb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+ye], ax	; int16_t
//@ 		mov	ax, WMapX2	; int16_t
//@ 		mov	[bp+xe], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2799
//@ 
//@ loc_301FB:				; CODE XREF: Line+16Fj
//@ 		push	[bp+ye]		; int16_t
//@ 		push	[bp+yb]		; int16_t
//@ 		call	Max		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, WMapY1	; int16_t
//@ 		jl	short loc_3021D	; Jump if Less (SF!=OF)
//@ 		push	[bp+yb]		; int16_t
//@ 		push	[bp+ye]		; int16_t
//@ 		call	Min		; function far PASCAL returns signed int 'Integer'
//@ 		cmp	ax, WMapY2	; int16_t
//@ 		jle	short loc_30220	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 
//@ loc_3021D:				; CODE XREF: Line+1BDj
//@ 		jmp	locret_303C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2800
//@ 
//@ loc_30220:				; CODE XREF: Line+1CEj
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		mov	[bp+xs], ax	; int16_t
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		sub	ax, [bp+yb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ys], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2801
//@ 		cmp	[bp+xs], 0	; int16_t
//@ 		jnz	short loc_30254	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+ys], 0	; int16_t
//@ 		jnz	short loc_30254	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+xb]		; int16_t
//@ 		push	[bp+yb]		; int16_t
//@ 		mov	al, [bp+col]	; uint8_t
//@ 		push	ax
//@ 		push	bp
//@ 		call	PutPixel	; function nested near PASCAL returns void
//@ 		jmp	locret_303C2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2803
//@ 
//@ loc_30254:				; CODE XREF: Line+1EEj	Line+1F4j
//@ 		mov	ax, [bp+yb]	; int16_t
//@ 		cmp	ax, [bp+ye]	; int16_t
//@ 		jl	short loc_3025F	; Jump if Less (SF!=OF)
//@ 		jmp	loc_302EF	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2805
//@ 
//@ loc_3025F:				; CODE XREF: Line+20Dj
//@ 		mov	ax, [bp+yb]	; int16_t
//@ 		cmp	ax, WMapY1	; int16_t
//@ 		jge	short loc_302A6	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPBIO.PAS" 2806
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		sub	ax, [bp+yb]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		sub	ax, WMapY1	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+xb], ax	; int16_t
//@ 		mov	ax, WMapY1	; int16_t
//@ 		mov	[bp+yb], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2807
//@ 
//@ loc_302A6:				; CODE XREF: Line+219j
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		cmp	ax, WMapY2	; int16_t
//@ 		jle	short loc_302EC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPBIO.PAS" 2808
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		sub	ax, [bp+yb]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, WMapY2	; int16_t
//@ 		sub	ax, [bp+yb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+xe], ax	; int16_t
//@ 		mov	ax, WMapY2	; int16_t
//@ 		mov	[bp+ye], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2809
//@ 
//@ loc_302EC:				; CODE XREF: Line+260j
//@ 		jmp	loc_3037C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2811
//@ 
//@ loc_302EF:				; CODE XREF: Line+20Fj
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		cmp	ax, WMapY1	; int16_t
//@ 		jge	short loc_30336	; Jump if Greater or Equal (SF=OF)
//@ ; #line	"CSPBIO.PAS" 2812
//@ 		mov	ax, [bp+yb]	; int16_t
//@ 		sub	ax, [bp+ye]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+yb]	; int16_t
//@ 		sub	ax, WMapY1	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+xe], ax	; int16_t
//@ 		mov	ax, WMapY1	; int16_t
//@ 		mov	[bp+ye], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2813
//@ 
//@ loc_30336:				; CODE XREF: Line+2A9j
//@ 		mov	ax, [bp+yb]	; int16_t
//@ 		cmp	ax, WMapY2	; int16_t
//@ 		jle	short loc_3037C	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ ; #line	"CSPBIO.PAS" 2814
//@ 		mov	ax, [bp+yb]	; int16_t
//@ 		sub	ax, [bp+ye]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, WMapY2	; int16_t
//@ 		sub	ax, [bp+ye]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xb]	; int16_t
//@ 		sub	ax, [bp+xe]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		pop	cx
//@ 		pop	bx
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+xb], ax	; int16_t
//@ 		mov	ax, WMapY2	; int16_t
//@ 		mov	[bp+yb], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2817
//@ 
//@ loc_3037C:				; CODE XREF: Line:loc_302ECj Line+2F0j
//@ 		mov	ax, [bp+xe]	; int16_t
//@ 		sub	ax, [bp+xb]	; int16_t
//@ 		mov	[bp+xs], ax	; int16_t
//@ 		mov	ax, [bp+ye]	; int16_t
//@ 		sub	ax, [bp+yb]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		xor	ax, dx		; Logical Exclusive OR
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		mov	[bp+ys], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2818
//@ 		cmp	[bp+xs], 0	; int16_t
//@ 		jnz	short loc_303AF	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+ys], 0	; int16_t
//@ 		jnz	short loc_303AF	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+xb]		; int16_t
//@ 		push	[bp+yb]		; int16_t
//@ 		mov	al, [bp+col]	; uint8_t
//@ 		push	ax
//@ 		push	bp
//@ 		call	PutPixel	; function nested near PASCAL returns void
//@ 		jmp	short locret_303C2 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2821
//@ 
//@ loc_303AF:				; CODE XREF: Line+34Aj	Line+350j
//@ 		push	[bp+xb]		; int16_t
//@ 		push	[bp+yb]		; int16_t
//@ 		push	[bp+xe]		; int16_t
//@ 		push	[bp+ye]		; int16_t
//@ 		mov	al, [bp+col]	; uint8_t
//@ 		push	ax
//@ 		call	CLine		; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2822
//@ 
//@ locret_303C2:				; CODE XREF: Line:loc_3014Ej Line+11Ej ...
//@ 		leave			; High Level Procedure Exit
//@ 		retn	0Ah		; Return Near from Procedure
//@ Line		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2839
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DoSetPalette	proc far		; CODE XREF: UpDateRedShade+70P
//@ 					; UpDateRedShade+E8P ...
//@ 
//@ PalBuf		= dword	ptr  6
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 2840
//@ 		push	ds
//@ ; #line	"CSPBIO.PAS" 2842
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ ; #line	"CSPBIO.PAS" 2843
//@ 		lds	si, [bp+PalBuf]	; Load Full Pointer to DS:xx
//@ ; #line	"CSPBIO.PAS" 2845
//@ 		mov	dx, 3C8h
//@ ; #line	"CSPBIO.PAS" 2846
//@ 		out	dx, al
//@ ; #line	"CSPBIO.PAS" 2848
//@ 		inc	dx		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2849
//@ 		cld			; Clear	Direction Flag
//@ ; #line	"CSPBIO.PAS" 2851
//@ 		mov	cx, 300h
//@ ; #line	"CSPBIO.PAS" 2852
//@ 		rep outsb		; Output Byte(s) to Port
//@ ; #line	"CSPBIO.PAS" 2855
//@ 		pop	ds
//@ ; #line	"CSPBIO.PAS" 2856
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ DoSetPalette	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2862
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ SetPalette	proc far		; CODE XREF: LoadConfig+2BBP
//@ 					; SwitchMonitor:loc_7F72P ...
//@ 
//@ br		= word ptr -10h		; real_t
//@ var_E		= word ptr -0Eh
//@ var_C		= word ptr -0Ch
//@ bk		= word ptr -0Ah		; int16_t
//@ k		= word ptr -8		; int16_t
//@ b		= word ptr -6		; int16_t
//@ n		= word ptr -4		; int16_t
//@ l		= word ptr -2		; int16_t
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2863
//@ 		mov	ax, Contrast	; int16_t
//@ 		add	ax, 0FFF9h	; Add
//@ 		mov	[bp+bk], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2864
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_303F6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_303F3:				; CODE XREF: SetPalette+148j
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 2866
//@ 
//@ loc_303F6:				; CODE XREF: SetPalette+12j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-23A3h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2867
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-23A2h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		cmp	ax, [bp+b]	; int16_t
//@ 		jle	short loc_3042B	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-23A2h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2868
//@ 
//@ loc_3042B:				; CODE XREF: SetPalette+39j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-23A1h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		cmp	ax, [bp+b]	; int16_t
//@ 		jle	short loc_3044F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-23A1h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2869
//@ 
//@ loc_3044F:				; CODE XREF: SetPalette+5Dj
//@ 		mov	ax, [bp+b]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 86h	; 'ﾆ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 7C00h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+br], ax	; real_t
//@ 		mov	[bp+var_E], bx
//@ 		mov	[bp+var_C], dx
//@ 		mov	ax, [bp+br]	; real_t
//@ 		mov	bx, [bp+var_E]
//@ 		mov	dx, [bp+var_C]
//@ 		mov	cx, [bp+br]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, [bp+br]	; real_t
//@ 		mov	bx, [bp+var_E]
//@ 		mov	dx, [bp+var_C]
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		mov	[bp+br], ax	; real_t
//@ 		mov	[bp+var_E], bx
//@ 		mov	[bp+var_C], dx
//@ 		mov	ax, [bp+br]	; real_t
//@ 		mov	bx, [bp+var_E]
//@ 		mov	dx, [bp+var_C]
//@ 		mov	cx, 85h	; 'ﾅ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	[bp+k],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2871
//@ 		mov	i$0, 1		; int16_t
//@ 		jmp	short loc_304CB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_304C7:				; CODE XREF: SetPalette+13Fj
//@ 		inc	i$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 2872
//@ 
//@ loc_304CB:				; CODE XREF: SetPalette+E6j
//@ 		mov	ax, i$0		; int16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	al, [di-23A4h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	ax, [bp+k]	; int16_t
//@ 		mul	[bp+bk]		; int16_t
//@ 		mul	cx		; Unsigned Multiplication of AL	or AX
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 80h	; 'ﾀ'
//@ 		idiv	cx		; Signed Divide
//@ 		mov	dx, ax
//@ 		mov	ax, i$0		; int16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	al, [di-23A4h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		add	ax, dx		; Add
//@ 		mov	dl, al
//@ 		mov	ax, i$0		; int16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	[di-20A4h], dl
//@ 		cmp	i$0, 3		; int16_t
//@ 		jnz	short loc_304C7	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2873
//@ 		cmp	[bp+n],	100h	; int16_t
//@ 		jz	short loc_3052A	; Jump if Zero (ZF=1)
//@ 		jmp	loc_303F3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2876
//@ 
//@ loc_3052A:				; CODE XREF: SetPalette+146j
//@ 		mov	ax, Color	; int16_t
//@ 		add	ax, 0FFF9h	; Add
//@ 		mov	[bp+bk], ax	; int16_t
//@ 		mov	ax, [bp+bk]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 84h	; 'ﾄ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		xor	di, di		; Logical Exclusive OR
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		mov	[bp+br], ax	; real_t
//@ 		mov	[bp+var_E], bx
//@ 		mov	[bp+var_C], dx
//@ ; #line	"CSPBIO.PAS" 2877
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_3055B	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_30558:				; CODE XREF: SetPalette+24Dj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 2879
//@ 
//@ loc_3055B:				; CODE XREF: SetPalette+177j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A1h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A2h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	dx, ax
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A3h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		add	ax, dx		; Add
//@ 		add	ax, cx		; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2880
//@ 		mov	j, 1		; uint16_t
//@ 		jmp	short loc_305A2	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3059E:				; CODE XREF: SetPalette+243j
//@ 		inc	j		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2882
//@ 
//@ loc_305A2:				; CODE XREF: SetPalette+1BDj
//@ 		mov	ax, j		; uint16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	al, [di-20A4h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		sub	ax, [bp+b]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+br]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, j		; uint16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	al, [di-20A4h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	[bp+l],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2883
//@ 		cmp	[bp+l],	0	; int16_t
//@ 		jge	short loc_305FB	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+l],	ax	; int16_t
//@ 
//@ loc_305FB:				; CODE XREF: SetPalette+215j
//@ 		cmp	[bp+l],	3Fh ; '?' ; int16_t
//@ 		jle	short loc_30606	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+l],	3Fh ; '?' ; int16_t
//@ ; #line	"CSPBIO.PAS" 2884
//@ 
//@ loc_30606:				; CODE XREF: SetPalette+220j
//@ 		mov	dl, byte ptr [bp+l] ; int16_t
//@ 		mov	ax, j		; uint16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	[di-20A4h], dl
//@ ; #line	"CSPBIO.PAS" 2885
//@ 		cmp	j, 3		; uint16_t
//@ 		jz	short loc_30625	; Jump if Zero (ZF=1)
//@ 		jmp	loc_3059E	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2886
//@ 
//@ loc_30625:				; CODE XREF: SetPalette+241j
//@ 		cmp	[bp+n],	100h	; int16_t
//@ 		jz	short loc_3062F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_30558	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2888
//@ 
//@ loc_3062F:				; CODE XREF: SetPalette+24Bj
//@ 		mov	ax, Bright	; int16_t
//@ 		sub	ax, 7		; Integer Subtraction
//@ 		mov	[bp+bk], ax	; int16_t
//@ 		mov	ax, [bp+bk]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, 88h	; 'ﾈ'
//@ 		xor	si, si		; Logical Exclusive OR
//@ 		mov	di, 4400h
//@ 		call	@$brdiv$q4Realt1 ; Real(AX:BX:DX)/=Real(CX:SI:DI)
//@ 					; Real(CX:SI:DI)=Real(AX:BX:DX)%Real(CX:SI:DI)
//@ 		push	dx
//@ 		push	bx
//@ 		push	ax
//@ 		mov	ax, 81h	; 'ﾁ'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		pop	cx
//@ 		pop	si
//@ 		pop	di
//@ 		call	@$brmin$q4Realt1 ; Real(AX:BX:DX)-=Real(CX:SI:DI)
//@ 		mov	[bp+br], ax	; real_t
//@ 		mov	[bp+var_E], bx
//@ 		mov	[bp+var_C], dx
//@ ; #line	"CSPBIO.PAS" 2889
//@ 		mov	[bp+n],	1	; int16_t
//@ 		jmp	short loc_30673	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_30670:				; CODE XREF: SetPalette+38Dj
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 2891
//@ 
//@ loc_30673:				; CODE XREF: SetPalette+28Fj
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A3h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2892
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A2h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		cmp	ax, [bp+b]	; int16_t
//@ 		jle	short loc_306A8	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A2h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2893
//@ 
//@ loc_306A8:				; CODE XREF: SetPalette+2B6j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A1h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		cmp	ax, [bp+b]	; int16_t
//@ 		jle	short loc_306CC	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		mov	al, [di-20A1h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	[bp+b],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2895
//@ 
//@ loc_306CC:				; CODE XREF: SetPalette+2DAj
//@ 		mov	j, 1		; uint16_t
//@ 		jmp	short loc_306D8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_306D4:				; CODE XREF: SetPalette+383j
//@ 		inc	j		; uint16_t
//@ ; #line	"CSPBIO.PAS" 2897
//@ 
//@ loc_306D8:				; CODE XREF: SetPalette+2F3j
//@ 		mov	ax, j		; uint16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	al, [di-20A4h]
//@ 		cbw			; AL ->	AX (with sign)
//@ 		mov	dx, ax
//@ 		mov	ax, 40h	; '@'
//@ 		sub	ax, dx		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@Real$q7Longint	; Real(x: Longint{DX:AX}): Real
//@ 		mov	cx, [bp+br]	; real_t
//@ 		mov	si, [bp+var_E]
//@ 		mov	di, [bp+var_C]
//@ 		call	@$brmul$q4Realt1 ; Real(AX:BX:DX)*=Real(CX:SI:DI)
//@ 		call	@Round$q4Real	; Round(x: Real): Longint
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, 40h	; '@'
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+l],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2898
//@ 		cmp	[bp+b],	3	; int16_t
//@ 		jge	short loc_30730	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		mul	[bp+b]		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+l],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 2899
//@ 
//@ loc_30730:				; CODE XREF: SetPalette+340j
//@ 		cmp	[bp+l],	0	; int16_t
//@ 		jge	short loc_3073B	; Jump if Greater or Equal (SF=OF)
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+l],	ax	; int16_t
//@ 
//@ loc_3073B:				; CODE XREF: SetPalette+355j
//@ 		cmp	[bp+l],	3Fh ; '?' ; int16_t
//@ 		jle	short loc_30746	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	[bp+l],	3Fh ; '?' ; int16_t
//@ ; #line	"CSPBIO.PAS" 2900
//@ 
//@ loc_30746:				; CODE XREF: SetPalette+360j
//@ 		mov	dl, byte ptr [bp+l] ; int16_t
//@ 		mov	ax, j		; uint16_t
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	si, di
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		add	di, si		; Add
//@ 		add	di, ax		; Add
//@ 		mov	[di-20A4h], dl
//@ ; #line	"CSPBIO.PAS" 2901
//@ 		cmp	j, 3		; uint16_t
//@ 		jz	short loc_30765	; Jump if Zero (ZF=1)
//@ 		jmp	loc_306D4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2902
//@ 
//@ loc_30765:				; CODE XREF: SetPalette+381j
//@ 		cmp	[bp+n],	100h	; int16_t
//@ 		jz	short loc_3076F	; Jump if Zero (ZF=1)
//@ 		jmp	loc_30670	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2904
//@ 
//@ loc_3076F:				; CODE XREF: SetPalette+38Bj
//@ 		mov	di, offset Pal	; int8_t[768]
//@ 		push	ds
//@ 		push	di
//@ 		call	DoSetPalette	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2905
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ SetPalette	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2911
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddEvent	proc far		; CODE XREF: CheckFloorLinks+2DDP
//@ 					; DoGame+1620P	...
//@ 
//@ n		= word ptr -2		; int16_t
//@ _CZ		= word ptr  6		; int16_t
//@ _CY		= word ptr  8		; int16_t
//@ _CX		= word ptr  0Ah		; int16_t
//@ P		= word ptr  0Ch		; int16_t
//@ _info		= byte ptr  0Eh		; uint8_t
//@ CC		= byte ptr  10h		; char
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2912
//@ 		cmp	SERVER,	0	; bool
//@ 		jnz	short loc_3078F	; Jump if Not Zero (ZF=0)
//@ 		cmp	RecordDemo, 0	; bool
//@ 		jnz	short loc_3078F	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_307DA ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2913
//@ 
//@ loc_3078F:				; CODE XREF: AddEvent+9j AddEvent+10j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_30799	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_30796:				; CODE XREF: AddEvent+5Dj
//@ 		inc	[bp+n]		; int16_t
//@ 
//@ loc_30799:				; CODE XREF: AddEvent+19j
//@ 		imul	di, [bp+n], 0Ah	; int16_t
//@ 		add	di, 0A49Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPBIO.PAS" 2914
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jnz	short loc_307D4	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2916
//@ 		mov	al, [bp+CC]	; char
//@ 		mov	es:[di], al
//@ 		mov	al, [bp+_info]	; uint8_t
//@ 		mov	es:[di+1], al
//@ 		mov	ax, [bp+P]	; int16_t
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSPBIO.PAS" 2917
//@ 		mov	ax, [bp+_CX]	; int16_t
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, [bp+_CY]	; int16_t
//@ 		mov	es:[di+6], ax
//@ 		mov	ax, [bp+_CZ]	; int16_t
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSPBIO.PAS" 2918
//@ 		jmp	short locret_307DA ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2919
//@ 
//@ loc_307D4:				; CODE XREF: AddEvent+2Cj
//@ 		cmp	[bp+n],	0Fh	; int16_t
//@ 		jnz	short loc_30796	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2920
//@ 
//@ locret_307DA:				; CODE XREF: AddEvent+12j AddEvent+57j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ AddEvent	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2926
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddEvVoice	proc far		; CODE XREF: AnimateRockets+80P
//@ 					; AnimateRockets+1F3P ...
//@ 
//@ VoiceID		= word ptr  6		; int16_t
//@ vy		= word ptr  8		; int16_t
//@ vx		= word ptr  0Ah		; int16_t
//@ $Ch		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 2927
//@ 		cmp	[bp+vx], 0FFFFh	; int16_t
//@ 		jz	short loc_307FA	; Jump if Zero (ZF=1)
//@ 		push	0FFFFh
//@ 		push	[bp+vx]		; int16_t
//@ 		push	[bp+vy]		; int16_t
//@ 		push	[bp+VoiceID]	; int16_t
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_30830	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2929
//@ 
//@ loc_307FA:				; CODE XREF: AddEvVoice+8j
//@ 		mov	ax, [bp+vy]	; int16_t
//@ 		cmp	ax, MyNetN	; int16_t
//@ 		jnz	short loc_30814	; Jump if Not Zero (ZF=0)
//@ 		push	[bp+$Ch]	; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+VoiceID]	; int16_t
//@ 		call	AddVoice	; function far PASCAL returns void
//@ 		jmp	short loc_30830	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 2930
//@ 
//@ loc_30814:				; CODE XREF: AddEvVoice+23j
//@ 		imul	di, [bp+vy], 58h ; int16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		push	0FFFFh
//@ 		push	word ptr es:[di+0Ah]
//@ 		push	word ptr es:[di+0Ch]
//@ 		push	[bp+VoiceID]	; int16_t
//@ 		call	AddVoice	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2931
//@ 
//@ loc_30830:				; CODE XREF: AddEvVoice+1Aj
//@ 					; AddEvVoice+34j
//@ 		push	78h ; 'x'
//@ 		push	0
//@ 		push	[bp+VoiceID]	; int16_t
//@ 		push	[bp+vx]		; int16_t
//@ 		push	[bp+vy]		; int16_t
//@ 		push	0
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 2932
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ AddEvVoice	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2949
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Hline		proc far		; CODE XREF: Bar+2BP DrawKey+15P ...
//@ 
//@ c		= byte ptr  6		; uint8_t
//@ L		= word ptr  8		; uint16_t
//@ Y		= word ptr  0Ah		; uint16_t
//@ X		= word ptr  0Ch		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 2950
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ 		assume es:nothing
//@ ; #line	"CSPBIO.PAS" 2951
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	bx, [bp+Y]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+X]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2952
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPBIO.PAS" 2953
//@ 		mov	al, [bp+c]	; uint8_t
//@ ; #line	"CSPBIO.PAS" 2954
//@ 		xor	ecx, ecx	; Logical Exclusive OR
//@ 		mov	cx, [bp+L]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2955
//@ 		rep stos byte ptr es:[edi] ; Store String
//@ ; #line	"CSPBIO.PAS" 2956
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ Hline		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2959
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ Vline		proc far		; CODE XREF: DrawKey+2BP DrawKey+58P
//@ 
//@ c		= byte ptr  6		; uint8_t
//@ L		= word ptr  8		; uint16_t
//@ Y		= word ptr  0Ah		; uint16_t
//@ X		= word ptr  0Ch		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 2961
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	bx, [bp+Y]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ 		mov	di, [bp+X]	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2962
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPBIO.PAS" 2963
//@ 		mov	cx, [bp+L]	; uint16_t
//@ 		mov	ax, VgaSeg	; uint16_t
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2964
//@ 		mov	al, [bp+c]	; uint8_t
//@ ; #line	"CSPBIO.PAS" 2965
//@ 
//@ loc_30890:				; CODE XREF: Vline+28j
//@ 		mov	es:[edi], al
//@ ; #line	"CSPBIO.PAS" 2966
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CSPBIO.PAS" 2967
//@ 		loop	loc_30890	; Loop while CX	!= 0
//@ ; #line	"CSPBIO.PAS" 2969
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ Vline		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2974
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ HBrline		proc far		; CODE XREF: UpDateMenu+9F1P
//@ 					; UpDateMenu+9FFP ...
//@ 
//@ L		= word ptr  6		; uint16_t
//@ W		= word ptr  8		; uint16_t
//@ Y		= word ptr  0Ah		; uint16_t
//@ X		= word ptr  0Ch		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 2975
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, [bp+X]	; uint16_t
//@ 		mov	bx, [bp+Y]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSPBIO.PAS" 2976
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPBIO.PAS" 2977
//@ 		mov	cx, [bp+W]	; uint16_t
//@ 		mov	bx, [bp+L]	; uint16_t
//@ 		shl	bx, 8		; Shift	Logical	Left
//@ 		add	bx, 1AC6h	; Add
//@ ; #line	"CSPBIO.PAS" 2978
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2979
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2980
//@ 
//@ loc_308C5:				; CODE XREF: HBrline+33j
//@ 		mov	al, es:[edi]
//@ ; #line	"CSPBIO.PAS" 2981
//@ 		xlat			; Table	Lookup Translation
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSPBIO.PAS" 2982
//@ 		mov	es:[edi], al
//@ ; #line	"CSPBIO.PAS" 2983
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 2984
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_308C5	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2985
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ HBrline		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 2988
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ VBrline		proc far		; CODE XREF: DrawBrKey+2AP
//@ 					; DrawBrKey+56P
//@ 
//@ L		= word ptr  6		; uint16_t
//@ W		= word ptr  8		; uint16_t
//@ Y		= word ptr  0Ah		; uint16_t
//@ X		= word ptr  0Ch		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 2989
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, [bp+X]	; uint16_t
//@ 		mov	bx, [bp+Y]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSPBIO.PAS" 2990
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPBIO.PAS" 2991
//@ 		mov	cx, [bp+W]	; uint16_t
//@ 		mov	bx, [bp+L]	; uint16_t
//@ 		shl	bx, 8		; Shift	Logical	Left
//@ 		add	bx, 1AC6h	; Add
//@ ; #line	"CSPBIO.PAS" 2992
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CSPBIO.PAS" 2993
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 2994
//@ 
//@ loc_308FE:				; CODE XREF: VBrline+36j
//@ 		mov	al, es:[edi]
//@ ; #line	"CSPBIO.PAS" 2995
//@ 		xlat			; Table	Lookup Translation
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSPBIO.PAS" 2996
//@ 		mov	es:[edi], al
//@ ; #line	"CSPBIO.PAS" 2997
//@ 		add	edi, VideoBPL	; int32_t
//@ ; #line	"CSPBIO.PAS" 2998
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_308FE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 2999
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ VBrline		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3005
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawKey		proc far		; CODE XREF: UpDateRanking+C7P
//@ 					; UpDateConsole+423P ...
//@ 
//@ c2		= byte ptr  6		; uint8_t
//@ c1		= byte ptr  8		; uint8_t
//@ y2		= word ptr  0Ah		; int16_t
//@ x2		= word ptr  0Ch		; int16_t
//@ y1		= word ptr  0Eh		; int16_t
//@ x1		= word ptr  10h		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 3006
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	al, [bp+c1]	; uint8_t
//@ 		push	ax
//@ 		call	Hline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3007
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		push	ax
//@ 		mov	al, [bp+c1]	; uint8_t
//@ 		push	ax
//@ 		call	Vline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3008
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+y2]		; int16_t
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	al, [bp+c2]	; uint8_t
//@ 		push	ax
//@ 		call	Hline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3009
//@ 		push	[bp+x2]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		push	ax
//@ 		mov	al, [bp+c2]	; uint8_t
//@ 		push	ax
//@ 		call	Vline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3010
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ DrawKey		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3014
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ DrawBrKey	proc far		; CODE XREF: UpDateConsole+32BP
//@ 					; UpDateConsole+4F0P ...
//@ 
//@ br2		= word ptr  6		; int16_t
//@ br1		= word ptr  8		; int16_t
//@ y2		= word ptr  0Ah		; int16_t
//@ x2		= word ptr  0Ch		; int16_t
//@ y1		= word ptr  0Eh		; int16_t
//@ x1		= word ptr  10h		; int16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 3015
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		push	ax
//@ 		push	[bp+br1]	; int16_t
//@ 		call	HBrline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3016
//@ 		push	[bp+x1]		; int16_t
//@ 		mov	ax, [bp+y1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		push	ax
//@ 		push	[bp+br1]	; int16_t
//@ 		call	VBrline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3017
//@ 		mov	ax, [bp+x1]	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	[bp+y2]		; int16_t
//@ 		mov	ax, [bp+x2]	; int16_t
//@ 		sub	ax, [bp+x1]	; int16_t
//@ 		push	ax
//@ 		push	[bp+br2]	; int16_t
//@ 		call	HBrline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3018
//@ 		push	[bp+x2]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		mov	ax, [bp+y2]	; int16_t
//@ 		sub	ax, [bp+y1]	; int16_t
//@ 		push	ax
//@ 		push	[bp+br2]	; int16_t
//@ 		call	VBrline		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3019
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ch		; Return Far from Procedure
//@ DrawBrKey	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3023
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ HBrline0	proc near		; CODE XREF: BrightBar+30p
//@ 
//@ L		= word ptr  4		; uint16_t
//@ W		= word ptr  6		; uint16_t
//@ Y		= word ptr  8		; uint16_t
//@ X		= word ptr  0Ah		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 3035
//@ 		xor	edi, edi	; Logical Exclusive OR
//@ 		mov	di, [bp+X]	; uint16_t
//@ 		mov	bx, [bp+Y]	; uint16_t
//@ 		shl	bx, 2		; Shift	Logical	Left
//@ ; #line	"CSPBIO.PAS" 3036
//@ 		add	edi, [bx-6E84h]	; Add
//@ ; #line	"CSPBIO.PAS" 3037
//@ 		mov	cx, [bp+W]	; uint16_t
//@ 		mov	bx, [bp+L]	; uint16_t
//@ 		shl	bx, 8		; Shift	Logical	Left
//@ 		add	bx, 1AC6h	; Add
//@ ; #line	"CSPBIO.PAS" 3038
//@ 		mov	ax, VgaSeg	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3039
//@ 		mov	es, ax
//@ ; #line	"CSPBIO.PAS" 3040
//@ 
//@ loc_309FA:				; CODE XREF: HBrline0+33j
//@ 		mov	al, es:[edi]
//@ ; #line	"CSPBIO.PAS" 3041
//@ 		xlat			; Table	Lookup Translation
//@ 		xlat			; Table	Lookup Translation
//@ ; #line	"CSPBIO.PAS" 3042
//@ 		mov	es:[edi], al
//@ ; #line	"CSPBIO.PAS" 3043
//@ 		inc	edi		; Increment by 1
//@ ; #line	"CSPBIO.PAS" 3044
//@ 		dec	cx		; Decrement by 1
//@ 		jnz	short loc_309FA	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3045
//@ 		leave			; High Level Procedure Exit
//@ 		retn	8		; Return Near from Procedure
//@ HBrline0	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3051
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BrightBar	proc far		; CODE XREF: UpDateConsole+342P
//@ 					; UpDateConsole+505P ...
//@ 
//@ var_4		= word ptr -4
//@ n		= word ptr -2		; uint16_t
//@ L		= word ptr  6		; uint16_t
//@ y2		= word ptr  8		; uint16_t
//@ x2		= word ptr  0Ah		; uint16_t
//@ y1		= word ptr  0Ch		; uint16_t
//@ x1		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3052
//@ 		mov	ax, [bp+x2]	; uint16_t
//@ 		sub	ax, [bp+x1]	; uint16_t
//@ 		inc	ax		; Increment by 1
//@ 		mov	[bp+x2], ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3053
//@ 		mov	ax, [bp+y2]	; uint16_t
//@ 		mov	[bp+var_4], ax
//@ 		mov	ax, [bp+y1]	; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		ja	short locret_30A48 ; Jump if Above (CF=0 & ZF=0)
//@ 		mov	[bp+n],	ax	; uint16_t
//@ 		jmp	short loc_30A31	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_30A2E:				; CODE XREF: BrightBar+39j
//@ 		inc	[bp+n]		; uint16_t
//@ 
//@ loc_30A31:				; CODE XREF: BrightBar+1Fj
//@ 		push	[bp+x1]		; uint16_t
//@ 		push	[bp+n]		; uint16_t
//@ 		push	[bp+x2]		; uint16_t
//@ 		push	[bp+L]		; uint16_t
//@ 		call	HBrline0	; function near	PASCAL returns void
//@ 		mov	ax, [bp+n]	; uint16_t
//@ 		cmp	ax, [bp+var_4]	; Compare Two Operands
//@ 		jnz	short loc_30A2E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3054
//@ 
//@ locret_30A48:				; CODE XREF: BrightBar+1Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ BrightBar	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3059
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ShowMap		proc far		; CODE XREF: DoGame+18D6P
//@ 
//@ var_1A		= dword	ptr -1Ah
//@ y3		= word ptr -14h		; int16_t
//@ y2		= word ptr -12h		; int16_t
//@ y1		= word ptr -10h		; int16_t
//@ x3		= word ptr -0Eh		; int16_t
//@ x2		= word ptr -0Ch		; int16_t
//@ x1		= word ptr -0Ah		; int16_t
//@ my		= word ptr -4		; int16_t
//@ mx		= word ptr -2		; int16_t
//@ 
//@ 		enter	1Ch, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3061
//@ 		mov	ax, WMapX1	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, WMapY1	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, WMapX2	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	ax, WMapY2	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3062
//@ 		mov	ax, WMapX1	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, WMapY1	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		dec	ax		; Decrement by 1
//@ 		push	ax
//@ 		mov	ax, WMapX2	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		mov	ax, WMapY2	; int16_t
//@ 		inc	ax		; Increment by 1
//@ 		inc	ax		; Increment by 1
//@ 		push	ax
//@ 		push	5
//@ 		push	5
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3063
//@ 		mov	ax, WMapX1	; int16_t
//@ 		sub	ax, 3		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, WMapY1	; int16_t
//@ 		sub	ax, 3		; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, WMapX2	; int16_t
//@ 		add	ax, 3		; Add
//@ 		push	ax
//@ 		mov	ax, WMapY2	; int16_t
//@ 		add	ax, 3		; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		call	DrawKey		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3065
//@ 		mov	ax, VideoCX	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, mps		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 50h	; 'P'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	mpk_x, ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3066
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, mps		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 32h	; '2'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	mpk_y, ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3069
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+mx], ax	; int16_t
//@ 		jmp	short loc_30AFB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_30AF8:				; CODE XREF: ShowMap+132j
//@ 		inc	[bp+mx]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3070
//@ 
//@ loc_30AFB:				; CODE XREF: ShowMap+AAj
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+my], ax	; int16_t
//@ 		jmp	short loc_30B05	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_30B02:				; CODE XREF: ShowMap+12Aj
//@ 		inc	[bp+my]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3071
//@ 
//@ loc_30B05:				; CODE XREF: ShowMap+B4j
//@ 		imul	ax, [bp+my], 0Bh ; int16_t
//@ 		mov	dx, ax
//@ 		imul	ax, [bp+mx], 2C0h ; int16_t
//@ 		les	di, Map		; TLoc*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		mov	word ptr [bp+var_1A], di
//@ 		mov	word ptr [bp+var_1A+2],	es
//@ ; #line	"CSPBIO.PAS" 3072
//@ 		cmp	byte ptr es:[di], 0 ; Compare Two Operands
//@ 		jbe	short loc_30B72	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		cmp	byte ptr es:[di], 78h ;	'x' ; Compare Two Operands
//@ 		jnb	short loc_30B72	; Jump if Not Below (CF=0)
//@ 		mov	dx, [bp+my]	; int16_t
//@ 		mov	ax, [bp+mx]	; int16_t
//@ 		shl	ax, 6		; Shift	Logical	Left
//@ 		les	di, VMask	; uint8_t*
//@ 		add	di, ax		; Add
//@ 		add	di, dx		; Add
//@ 		cmp	byte ptr es:[di], 1 ; Compare Two Operands
//@ 		jz	short loc_30B48	; Jump if Zero (ZF=1)
//@ 		cmp	FullMap, 0	; bool
//@ 		jz	short loc_30B72	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 3074
//@ 
//@ loc_30B48:				; CODE XREF: ShowMap+F3j
//@ 		mov	ax, Hx		; int16_t
//@ 		les	di, [bp+var_1A]	; Load Full Pointer to ES:xx
//@ 		sub	ax, es:[di+3]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+5]
//@ 		sub	ax, Hy		; int16_t
//@ 		push	ax
//@ 		mov	ax, Hx		; int16_t
//@ 		sub	ax, es:[di+7]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+9]
//@ 		sub	ax, Hy		; int16_t
//@ 		push	ax
//@ 		push	0FFF7h
//@ 		call	Line		; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3078
//@ 
//@ loc_30B72:				; CODE XREF: ShowMap+D6j ShowMap+DCj ...
//@ 		cmp	[bp+my], 3Fh ; '?' ; int16_t
//@ 		jnz	short loc_30B02	; Jump if Not Zero (ZF=0)
//@ 		cmp	[bp+mx], 3Fh ; '?' ; int16_t
//@ 		jz	short loc_30B81	; Jump if Zero (ZF=1)
//@ 		jmp	loc_30AF8	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3080
//@ 
//@ loc_30B81:				; CODE XREF: ShowMap+130j
//@ 		mov	ax, isa		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+x1], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3081
//@ 		mov	ax, isa2	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		add	ax, ica2	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+x2], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3082
//@ 		mov	ax, isa2	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		sub	ax, ica2	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+x3], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3084
//@ 		mov	ax, ica		; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+y1], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3085
//@ 		mov	ax, ica2	; int16_t
//@ 		add	ax, isa2	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+y2], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3086
//@ 		mov	ax, ica2	; int16_t
//@ 		sub	ax, isa2	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 0Ch
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+y3], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3088
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		push	[bp+x2]		; int16_t
//@ 		push	[bp+y2]		; int16_t
//@ 		push	0FFA8h
//@ 		call	Line		; function near	PASCAL returns void
//@ 		push	[bp+x2]		; int16_t
//@ 		push	[bp+y2]		; int16_t
//@ 		push	[bp+x3]		; int16_t
//@ 		push	[bp+y3]		; int16_t
//@ 		push	0FFA8h
//@ 		call	Line		; function near	PASCAL returns void
//@ 		push	[bp+x3]		; int16_t
//@ 		push	[bp+y3]		; int16_t
//@ 		push	[bp+x1]		; int16_t
//@ 		push	[bp+y1]		; int16_t
//@ 		push	0FFA8h
//@ 		call	Line		; function near	PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3090
//@ 		cmp	FullMap, 0	; bool
//@ 		jnz	short loc_30C1B	; Jump if Not Zero (ZF=0)
//@ 		jmp	short locret_30C6A ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3092
//@ 
//@ loc_30C1B:				; CODE XREF: ShowMap+1CBj
//@ 		mov	ax, MCount	; uint16_t
//@ 		mov	word ptr [bp+var_1A+2],	ax
//@ 		mov	ax, 1
//@ 		cmp	ax, word ptr [bp+var_1A+2] ; Compare Two Operands
//@ 		jg	short locret_30C6A ; Jump if Greater (ZF=0 & SF=OF)
//@ 		mov	n$0, ax		; int16_t
//@ 		jmp	short loc_30C32	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_30C2E:				; CODE XREF: ShowMap+21Cj
//@ 		inc	n$0		; int16_t
//@ ; #line	"CSPBIO.PAS" 3093
//@ 
//@ loc_30C32:				; CODE XREF: ShowMap+1E0j
//@ 		imul	di, n$0, 28h	; int16_t
//@ 		add	di, 0A51Eh	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ ; #line	"CSPBIO.PAS" 3094
//@ 		mov	ax, Hx		; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, Hy		; int16_t
//@ 		push	ax
//@ 		mov	ax, Hx		; int16_t
//@ 		sub	ax, es:[di]	; Integer Subtraction
//@ 		push	ax
//@ 		mov	ax, es:[di+2]
//@ 		sub	ax, Hy		; int16_t
//@ 		push	ax
//@ 		push	0FFA6h
//@ 		call	Line		; function near	PASCAL returns void
//@ 		mov	ax, n$0		; int16_t
//@ 		cmp	ax, word ptr [bp+var_1A+2] ; Compare Two Operands
//@ 		jnz	short loc_30C2E	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3095
//@ 
//@ locret_30C6A:				; CODE XREF: ShowMap+1CDj ShowMap+1DBj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ShowMap		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3103
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitNormalViewHi proc near		; CODE XREF: ReInitViewConst:loc_31080p
//@ 
//@ dy		= word ptr -4		; int16_t
//@ wc		= word ptr -2		; int16_t
//@ 
//@ 		enter	6, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3104
//@ 		cmp	InfoPage, 0	; bool
//@ 		jz	short loc_30C82	; Jump if Zero (ZF=1)
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		sub	ax, 10h		; Integer Subtraction
//@ 		mov	[bp+wc], ax	; int16_t
//@ 		jmp	short loc_30C88	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3105
//@ 
//@ loc_30C82:				; CODE XREF: InitNormalViewHi+9j
//@ 		mov	ax, VideoCY	; uint16_t
//@ 		mov	[bp+wc], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3107
//@ 
//@ loc_30C88:				; CODE XREF: InitNormalViewHi+14j
//@ 		mov	ax, LookVz	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, word ptr VideoH ; int32_t
//@ 		mov	bx, word ptr VideoH+2 ;	int32_t
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 320h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	[bp+dy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3109
//@ 		cmp	InfoPage, 0	; bool
//@ 		jz	short loc_30CD1	; Jump if Zero (ZF=1)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_30CBB	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_30CD1	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 3110
//@ 
//@ loc_30CBB:				; CODE XREF: InitNormalViewHi+46j
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 18h		; Integer Subtraction
//@ 		cmp	ax, [bp+dy]	; int16_t
//@ 		jge	short loc_30CCF	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 18h		; Integer Subtraction
//@ 		mov	[bp+dy], ax	; int16_t
//@ 
//@ loc_30CCF:				; CODE XREF: InitNormalViewHi+58j
//@ 		jmp	short loc_30CE5	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3111
//@ 
//@ loc_30CD1:				; CODE XREF: InitNormalViewHi+3Fj
//@ 					; InitNormalViewHi+4Dj
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		cmp	ax, [bp+dy]	; int16_t
//@ 		jge	short loc_30CE5	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		mov	[bp+dy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3113
//@ 
//@ loc_30CE5:				; CODE XREF: InitNormalViewHi:loc_30CCFj
//@ 					; InitNormalViewHi+6Ej
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, [bp+dy]	; int16_t
//@ 		jle	short loc_30CFD	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3115
//@ 
//@ loc_30CFD:				; CODE XREF: InitNormalViewHi+84j
//@ 		mov	ax, [bp+dy]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 320h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, word ptr VideoH ; int32_t
//@ 		mov	bx, word ptr VideoH+2 ;	int32_t
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	_LookVz, ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3117
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		add	ax, [bp+dy]	; int16_t
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3119
//@ 		mov	ax, FloorDiv	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, 36h	; '6'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	ObjectW, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3120
//@ 		mov	ax, FloorDiv	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	WallW, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3121
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		mov	cx, 410h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 190h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		and	ax, 0FFE0h	; Logical AND
//@ 		and	dx, 0		; Logical AND
//@ 		mov	WallH, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3123
//@ 		mov	ax, WallH	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 280h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	BLevel0, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3125
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	WinW, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3126
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	WinH, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3127
//@ 		mov	ax, WinW	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	WinW2, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3128
//@ 		mov	ax, WinW2	; uint16_t
//@ 		mov	WinW2i,	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3130
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinH	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinCY	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	WinH2u,	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3131
//@ 		mov	ax, WinH	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinH2d,	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3132
//@ 		cmp	InfoPage, 0	; bool
//@ 		jz	short loc_30DE7	; Jump if Zero (ZF=1)
//@ 		cmp	CLIENT,	0	; bool
//@ 		jnz	short loc_30DE2	; Jump if Not Zero (ZF=0)
//@ 		cmp	SERVER,	0	; bool
//@ 		jz	short loc_30DE7	; Jump if Zero (ZF=1)
//@ 
//@ loc_30DE2:				; CODE XREF: InitNormalViewHi+16Dj
//@ 		sub	WinH2d,	0Ah	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3134
//@ 
//@ loc_30DE7:				; CODE XREF: InitNormalViewHi+166j
//@ 					; InitNormalViewHi+174j
//@ 		mov	ax, WinCY	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinB, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3135
//@ 		mov	ax, WinCY	; uint16_t
//@ 		add	ax, WinH2d	; uint16_t
//@ 		mov	WinE, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3136
//@ 		mov	ax, WinB	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	WinB3, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3137
//@ 		mov	ax, WinE	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	WinE3, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3139
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	WinSX, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3140
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		sub	ax, 1		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		mov	WinEX, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3142
//@ 		mov	ax, WinCY	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinSY, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3143
//@ 		mov	ax, WinCY	; uint16_t
//@ 		add	ax, WinH2d	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	WinEY, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3145
//@ 		mov	ax, WinSX	; uint16_t
//@ 		add	ax, 10h		; Add
//@ 		mov	WMapX1,	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3146
//@ 		mov	ax, WinSY	; uint16_t
//@ 		add	ax, 0Eh		; Add
//@ 		mov	WMapY1,	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3147
//@ 		mov	ax, word ptr VideoW ; int32_t
//@ 		mov	dx, word ptr VideoW+2 ;	int32_t
//@ 		mov	cx, 78h	; 'x'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 140h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WMapX1	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	WMapX2,	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3148
//@ 		mov	ax, word ptr VideoH ; int32_t
//@ 		mov	dx, word ptr VideoH+2 ;	int32_t
//@ 		mov	cx, 78h	; 'x'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 0C8h ; '￈'
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WMapY1	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	WMapY2,	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3149
//@ 		mov	ax, WMapX1	; int16_t
//@ 		add	ax, WMapX2	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	WMapX, ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3150
//@ 		mov	ax, WMapY1	; int16_t
//@ 		add	ax, WMapY2	; int16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	WMapY, ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3151
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ InitNormalViewHi endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3156
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function near	PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ InitMonitorView	proc near		; CODE XREF: ReInitViewConst+Ap
//@ 
//@ dy		= word ptr -4		; int16_t
//@ wc		= word ptr -2		; int16_t
//@ 
//@ 		enter	8, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3157
//@ 		mov	FloorW,	0Ah	; uint16_t
//@ 		mov	InfoPage, 0	; bool
//@ ; #line	"CSPBIO.PAS" 3158
//@ 		mov	[bp+wc], 4Bh ; 'K' ; int16_t
//@ ; #line	"CSPBIO.PAS" 3160
//@ 		imul	di, CurOwner, 58h ; uint16_t
//@ 		add	di, 0F02Ah	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		mov	ax, es:[di+10h]
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 4
//@ 		idiv	cx		; Signed Divide
//@ 		mov	[bp+dy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3161
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		cmp	ax, [bp+dy]	; int16_t
//@ 		jge	short loc_30EF7	; Jump if Greater or Equal (SF=OF)
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		mov	[bp+dy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3162
//@ 
//@ loc_30EF7:				; CODE XREF: InitMonitorView+35j
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		neg	ax		; Two's Complement Negation
//@ 		cmp	ax, [bp+dy]	; int16_t
//@ 		jle	short loc_30F0F	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		sub	ax, 4		; Integer Subtraction
//@ 		neg	ax		; Two's Complement Negation
//@ 		mov	[bp+dy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3163
//@ 
//@ loc_30F0F:				; CODE XREF: InitMonitorView+4Bj
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		add	ax, [bp+dy]	; int16_t
//@ 		mov	WinCY, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3164
//@ 		mov	ObjectW, 21Ch	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3165
//@ 		mov	WallW, 98h ; 'ﾘ' ; uint16_t
//@ ; #line	"CSPBIO.PAS" 3166
//@ 		mov	WallH, 1F4h	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3168
//@ 		mov	ax, WallH	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, BLevelDef	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		call	@$brmul$q7Longintt1 ; X1{DX:AX}*=X2{BX:CX}
//@ 		mov	cx, 280h
//@ 		xor	bx, bx		; Logical Exclusive OR
//@ 		call	@$brdiv$q7Longintt1 ; X1{DX:AX}/=X2{BX:CX}
//@ 					; X2=X1%X2
//@ 		mov	BLevel0, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3170
//@ 		mov	WinW, 130h	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3171
//@ 		mov	ax, WinW	; uint16_t
//@ 		add	ax, 7		; Add
//@ 		shr	ax, 3		; Shift	Logical	Right
//@ 		shl	ax, 3		; Shift	Logical	Left
//@ 		mov	WinW, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3172
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		mov	WinH, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3173
//@ 		mov	ax, WinW	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		mov	WinW2, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3174
//@ 		mov	ax, WinW2	; uint16_t
//@ 		mov	WinW2i,	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3176
//@ 		mov	ax, [bp+wc]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinH	; uint16_t
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, WinCY	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		mov	WinH2u,	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3177
//@ 		mov	ax, WinH	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinH2d,	ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3179
//@ 		mov	ax, WinCY	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinB, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3180
//@ 		mov	ax, WinCY	; uint16_t
//@ 		add	ax, WinH2d	; uint16_t
//@ 		mov	WinE, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3181
//@ 		mov	ax, WinB	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	WinB3, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3182
//@ 		mov	ax, WinE	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		mov	WinE3, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3184
//@ 		mov	ax, 0A0h ; 'ﾠ'
//@ 		sub	ax, WinW2	; uint16_t
//@ 		mov	WinSX, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3185
//@ 		mov	ax, WinW2	; uint16_t
//@ 		add	ax, 0A0h ; 'ﾠ'  ; Add
//@ 		dec	ax		; Decrement by 1
//@ 		mov	WinEX, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3186
//@ 		mov	ax, WinCY	; uint16_t
//@ 		sub	ax, WinH2u	; uint16_t
//@ 		mov	WinSY, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3187
//@ 		mov	ax, WinCY	; uint16_t
//@ 		add	ax, WinH2d	; uint16_t
//@ 		dec	ax		; Decrement by 1
//@ 		mov	WinEY, ax	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3188
//@ 		leave			; High Level Procedure Exit
//@ 		retn			; Return Near from Procedure
//@ InitMonitorView	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3193
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns unsigned int 'Word'
//@ ; Attributes: bp-based frame
//@ 
//@ CalcStringLen	proc far		; CODE XREF: ReadMess+9DP
//@ 					; LoadMessage+218P ...
//@ 
//@ var_108		= word ptr -108h
//@ n		= word ptr -106h	; int16_t
//@ l		= word ptr -104h	; int16_t
//@ S		= byte ptr -102h	; char[256] // Pascal string
//@ CalcStringLen	= word ptr -2		; uint16_t
//@ arg_0		= dword	ptr  6
//@ 
//@ 		enter	108h, 0		; Make Stack Frame for Procedure Parameters
//@ 		mov	bx, ss
//@ 		mov	es, bx
//@ 		assume es:nothing
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
//@ ; #line	"CSPBIO.PAS" 3194
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+l],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3195
//@ 		mov	al, [bp+S]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	[bp+var_108], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jg	short loc_31063	; Jump if Greater (ZF=0	& SF=OF)
//@ 		mov	[bp+n],	ax	; int16_t
//@ 		jmp	short loc_31031	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3102D:				; CODE XREF: CalcStringLen+6Ej
//@ 		inc	[bp+n]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3196
//@ 
//@ loc_31031:				; CODE XREF: CalcStringLen+38j
//@ 		mov	di, [bp+n]	; int16_t
//@ 		cmp	[bp+di+S], 20h ; ' ' ; char[256] // Pascal string
//@ 		jz	short loc_31054	; Jump if Zero (ZF=1)
//@ 		mov	di, [bp+n]	; int16_t
//@ 		mov	al, [bp+di+S]	; char[256] // Pascal string
//@ 		xor	ah, ah		; Logical Exclusive OR
//@ 		mov	di, ax
//@ 		shl	di, 1		; Shift	Logical	Left
//@ 		mov	ax, [di-1DA0h]
//@ 		add	[bp+l],	ax	; int16_t
//@ 		jmp	short loc_31059	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3197
//@ 
//@ loc_31054:				; CODE XREF: CalcStringLen+47j
//@ 		add	[bp+l],	4	; int16_t
//@ 
//@ loc_31059:				; CODE XREF: CalcStringLen+5Fj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		cmp	ax, [bp+var_108] ; Compare Two Operands
//@ 		jnz	short loc_3102D	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3198
//@ 
//@ loc_31063:				; CODE XREF: CalcStringLen+32j
//@ 		mov	ax, [bp+l]	; int16_t
//@ 		mov	[bp+CalcStringLen], ax ; uint16_t
//@ ; #line	"CSPBIO.PAS" 3199
//@ 		mov	ax, [bp+CalcStringLen] ; uint16_t
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ CalcStringLen	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3204
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ ReInitViewConst	proc far		; CODE XREF: ReinitPlayer+16AP
//@ 					; LoadServerPatch+2BAP	...
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 3205
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jz	short loc_31080	; Jump if Zero (ZF=1)
//@ 		call	InitMonitorView	; function near	PASCAL returns void
//@ 		jmp	short locret_31083 ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3208
//@ 
//@ loc_31080:				; CODE XREF: ReInitViewConst+8j
//@ 		call	InitNormalViewHi ; function near PASCAL	returns	void
//@ ; #line	"CSPBIO.PAS" 3209
//@ 
//@ locret_31083:				; CODE XREF: ReInitViewConst+Dj
//@ 		leave			; High Level Procedure Exit
//@ 		retf			; Return Far from Procedure
//@ ReInitViewConst	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3213
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddBlowLight	proc far		; CODE XREF: ReinitPlayer+18EP
//@ 					; AnimateRockets+7A4P ...
//@ 
//@ TT		= word ptr  6		; uint16_t
//@ $BL		= word ptr  8		; uint16_t
//@ BR		= word ptr  0Ah		; uint16_t
//@ By		= word ptr  0Ch		; uint16_t
//@ $Bx		= word ptr  0Eh		; uint16_t
//@ 
//@ 		push	bp
//@ 		mov	bp, sp
//@ ; #line	"CSPBIO.PAS" 3214
//@ 		cmp	LCount,	1Fh	; uint16_t
//@ 		jbe	short loc_31091	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	short locret_310BC ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3215
//@ 
//@ loc_31091:				; CODE XREF: AddBlowLight+8j
//@ 		push	6Ch ; 'l'
//@ 		mov	al, byte ptr [bp+BR] ; uint16_t
//@ 		push	ax
//@ 		push	[bp+$BL]	; uint16_t
//@ 		push	[bp+$Bx]	; uint16_t
//@ 		push	[bp+By]		; uint16_t
//@ 		push	[bp+TT]		; uint16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3216
//@ 		push	[bp+$Bx]	; uint16_t
//@ 		push	[bp+By]		; uint16_t
//@ 		push	[bp+BR]		; uint16_t
//@ 		push	[bp+$BL]	; uint16_t
//@ 		push	[bp+TT]		; uint16_t
//@ 		call	_AddBlowLight	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3217
//@ 
//@ locret_310BC:				; CODE XREF: AddBlowLight+Aj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ AddBlowLight	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3221
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ _AddBlowLight	proc far		; CODE XREF: AnimateRockets+658P
//@ 					; CorrectRocketPosition+154P ...
//@ 
//@ var_4		= dword	ptr -4
//@ TT		= word ptr  6		; uint16_t
//@ $BL		= word ptr  8		; uint16_t
//@ BR		= word ptr  0Ah		; uint16_t
//@ By		= word ptr  0Ch		; uint16_t
//@ $Bx		= word ptr  0Eh		; uint16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3222
//@ 		cmp	LCount,	1Fh	; uint16_t
//@ 		jbe	short loc_310CE	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_3119C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3224
//@ 
//@ loc_310CE:				; CODE XREF: _AddBlowLight+9j
//@ 		cmp	NETMonitor, 0	; bool
//@ 		jnz	short loc_31133	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3225
//@ 		mov	ax, [bp+$Bx]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, ehx		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_310F1	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_310F1:				; CODE XREF: _AddBlowLight+28j
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, MapR	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_31131	; Jump if Less (SF!=OF)
//@ 		jg	short loc_31103	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jb	short loc_31131	; Jump if Below	(CF=1)
//@ 
//@ loc_31103:				; CODE XREF: _AddBlowLight+3Dj
//@ 		mov	ax, [bp+By]	; uint16_t
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, ehy		; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		or	dx, dx		; Logical Inclusive OR
//@ 		jns	short loc_3111F	; Jump if Not Sign (SF=0)
//@ 		not	dx		; One's Complement Negation
//@ 		neg	ax		; Two's Complement Negation
//@ 		sbb	dx, 0FFFFh	; Integer Subtraction with Borrow
//@ 
//@ loc_3111F:				; CODE XREF: _AddBlowLight+56j
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, MapR	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		cmp	dx, bx		; Compare Two Operands
//@ 		jl	short loc_31131	; Jump if Less (SF!=OF)
//@ 		jg	short loc_31133	; Jump if Greater (ZF=0	& SF=OF)
//@ 		cmp	ax, cx		; Compare Two Operands
//@ 		jnb	short loc_31133	; Jump if Not Below (CF=0)
//@ ; #line	"CSPBIO.PAS" 3226
//@ 
//@ loc_31131:				; CODE XREF: _AddBlowLight+3Bj
//@ 					; _AddBlowLight+41j ...
//@ 		jmp	short locret_3119C ; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3227
//@ 
//@ loc_31133:				; CODE XREF: _AddBlowLight+13j
//@ 					; _AddBlowLight+6Bj ...
//@ 		inc	LCount		; uint16_t
//@ ; #line	"CSPBIO.PAS" 3228
//@ 		imul	di, LCount, 12h	; uint16_t
//@ 		add	di, 0BCA4h	; Add
//@ 		push	ds
//@ 		pop	es
//@ 		assume es:dseg11
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPBIO.PAS" 3230
//@ 		mov	ax, [bp+$Bx]	; uint16_t
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 3231
//@ 		mov	ax, [bp+By]	; uint16_t
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		shr	ax, 6		; Shift	Logical	Right
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSPBIO.PAS" 3232
//@ 		mov	ax, [bp+BR]	; uint16_t
//@ 		mov	es:[di+4], ax
//@ 		mov	ax, [bp+$BL]	; uint16_t
//@ 		shl	ax, 2		; Shift	Logical	Left
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPBIO.PAS" 3233
//@ 		cmp	[bp+TT], 0FEh ;	'￾' ; uint16_t
//@ 		jnz	short loc_3117E	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+TT], 0FFh	; uint16_t
//@ ; #line	"CSPBIO.PAS" 3234
//@ 
//@ loc_3117E:				; CODE XREF: _AddBlowLight+B7j
//@ 		mov	ax, [bp+TT]	; uint16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		assume es:nothing
//@ 		mov	es:[di+0Ch], ax
//@ 		mov	ax, [bp+TT]	; uint16_t
//@ 		shr	ax, 2		; Shift	Logical	Right
//@ 		add	ax, t1		; uint16_t
//@ 		mov	es:[di+0Eh], ax
//@ 		mov	word ptr es:[di+10h], 1
//@ ; #line	"CSPBIO.PAS" 3236
//@ 
//@ locret_3119C:				; CODE XREF: _AddBlowLight+Bj
//@ 					; _AddBlowLight:loc_31131j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ _AddBlowLight	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3241
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ AddBlow		proc far		; CODE XREF: AnimateRockets+456P
//@ 					; AddClientProcesses+158P ...
//@ 
//@ var_4		= dword	ptr -4
//@ BBType		= word ptr  6		; int16_t
//@ bbvz		= word ptr  8		; int16_t
//@ bbvy		= word ptr  0Ah		; int16_t
//@ bbvx		= word ptr  0Ch		; int16_t
//@ bbz		= word ptr  0Eh		; int16_t
//@ bby		= word ptr  10h		; int16_t
//@ bbx		= word ptr  12h		; int16_t
//@ 
//@ 		enter	4, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3242
//@ 		cmp	BCount,	0C4h ; 'ￄ' ; uint16_t
//@ 		jbe	short loc_311AF	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ 		jmp	locret_31248	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3243
//@ 
//@ loc_311AF:				; CODE XREF: AddBlow+Aj
//@ 		inc	BCount		; uint16_t
//@ ; #line	"CSPBIO.PAS" 3244
//@ 		mov	ax, BCount	; uint16_t
//@ 		shl	ax, 4		; Shift	Logical	Left
//@ 		les	di, BlowsList	; TBlow*
//@ 		add	di, ax		; Add
//@ 		add	di, 0FFF0h	; Add
//@ 		mov	word ptr [bp+var_4], di
//@ 		mov	word ptr [bp+var_4+2], es
//@ ; #line	"CSPBIO.PAS" 3246
//@ 		mov	al, byte ptr [bp+BBType] ; int16_t
//@ 		cmp	al, 3		; Compare Two Operands
//@ 		jb	short loc_311E9	; Jump if Below	(CF=1)
//@ 		cmp	al, 4		; Compare Two Operands
//@ 		ja	short loc_311E9	; Jump if Above	(CF=0 &	ZF=0)
//@ ; #line	"CSPBIO.PAS" 3247
//@ 		imul	di, [bp+BBType], 3Ah ; int16_t
//@ 		push	word ptr [di-2968h]
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		jmp	short loc_31208	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3248
//@ 
//@ loc_311E9:				; CODE XREF: AddBlow+2Ej AddBlow+32j
//@ 		cmp	[bp+BBType], 8	; int16_t
//@ 		jnz	short loc_31200	; Jump if Not Zero (ZF=0)
//@ 		push	3
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		shr	ax, 1		; Shift	Logical	Right
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di], ax
//@ 		jmp	short loc_31208	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3249
//@ 
//@ loc_31200:				; CODE XREF: AddBlow+4Dj
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	es:[di], ax
//@ ; #line	"CSPBIO.PAS" 3250
//@ 
//@ loc_31208:				; CODE XREF: AddBlow+47j AddBlow+5Ej
//@ 		mov	ax, [bp+BBType]	; int16_t
//@ 		les	di, [bp+var_4]	; Load Full Pointer to ES:xx
//@ 		mov	es:[di+2], ax
//@ ; #line	"CSPBIO.PAS" 3251
//@ 		mov	ax, [bp+bbvx]	; int16_t
//@ 		mov	es:[di+0Ah], ax
//@ ; #line	"CSPBIO.PAS" 3252
//@ 		mov	ax, [bp+bbvy]	; int16_t
//@ 		mov	es:[di+0Ch], ax
//@ ; #line	"CSPBIO.PAS" 3253
//@ 		mov	ax, [bp+bbvz]	; int16_t
//@ 		mov	es:[di+0Eh], ax
//@ ; #line	"CSPBIO.PAS" 3254
//@ 		mov	ax, [bp+bbx]	; int16_t
//@ 		add	ax, es:[di+0Ah]	; Add
//@ 		mov	es:[di+4], ax
//@ ; #line	"CSPBIO.PAS" 3255
//@ 		mov	ax, [bp+bby]	; int16_t
//@ 		add	ax, es:[di+0Ch]	; Add
//@ 		mov	es:[di+6], ax
//@ ; #line	"CSPBIO.PAS" 3256
//@ 		mov	ax, [bp+bbz]	; int16_t
//@ 		add	ax, es:[di+0Eh]	; Add
//@ 		mov	es:[di+8], ax
//@ ; #line	"CSPBIO.PAS" 3258
//@ 
//@ locret_31248:				; CODE XREF: AddBlow+Cj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Eh		; Return Far from Procedure
//@ AddBlow		endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3263
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BlowSpark	proc far		; CODE XREF: AnimateRockets+74EP
//@ 					; AnimateRockets+768P ...
//@ 
//@ var_10		= word ptr -10h
//@ gy		= word ptr -0Eh		; int16_t
//@ gx		= word ptr -0Ch		; int16_t
//@ j		= word ptr -0Ah		; int16_t
//@ vz0		= word ptr -8		; int16_t
//@ vx0		= word ptr -6		; int16_t
//@ vz		= word ptr -4		; int16_t
//@ RMask		= word ptr -2		; int16_t
//@ s		= word ptr  6		; int16_t
//@ n		= word ptr  8		; int16_t
//@ rz		= word ptr  0Ah		; int16_t
//@ ry		= word ptr  0Ch		; int16_t
//@ rx		= word ptr  0Eh		; int16_t
//@ 
//@ 		enter	10h, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3264
//@ 		cmp	[bp+s],	1	; int16_t
//@ 		jnz	short loc_3126E	; Jump if Not Zero (ZF=0)
//@ 		push	73h ; 's'
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		push	ax
//@ 		push	0
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ 		jmp	short loc_31284	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3265
//@ 
//@ loc_3126E:				; CODE XREF: BlowSpark+8j
//@ 		push	62h ; 'b'
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		push	ax
//@ 		push	0
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		push	[bp+rz]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3267
//@ 
//@ loc_31284:				; CODE XREF: BlowSpark+20j
//@ 		cmp	[bp+s],	1	; int16_t
//@ 		jnz	short loc_312A0	; Jump if Not Zero (ZF=0)
//@ 		mov	[bp+vz0], 0Ah	; int16_t
//@ 		mov	[bp+vx0], 10h	; int16_t
//@ 		mov	[bp+vz], 12Ch	; int16_t
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+RMask], ax	; int16_t
//@ 		jmp	short loc_312B4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3268
//@ 
//@ loc_312A0:				; CODE XREF: BlowSpark+3Cj
//@ 		mov	[bp+vz0], 8	; int16_t
//@ 		mov	[bp+vx0], 0Ah	; int16_t
//@ 		mov	[bp+vz], 0A0h ;	'ﾠ' ; int16_t
//@ 		mov	[bp+RMask], 1	; int16_t
//@ ; #line	"CSPBIO.PAS" 3270
//@ 
//@ loc_312B4:				; CODE XREF: BlowSpark+52j
//@ 		mov	al, byte ptr [bp+n] ; int16_t
//@ 		shr	al, 1		; Shift	Logical	Right
//@ 		jnb	short loc_312DE	; Jump if Not Below (CF=0)
//@ 		push	[bp+rx]		; int16_t
//@ 		push	[bp+ry]		; int16_t
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		add	ax, 40h	; '@'   ; Add
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	12h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 0Eh		; Add
//@ 		push	ax
//@ 		push	0Ch
//@ 		call	AddBlow		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3272
//@ 
//@ loc_312DE:				; CODE XREF: BlowSpark+6Dj
//@ 		mov	ax, [bp+n]	; int16_t
//@ 		mov	[bp+var_10], ax
//@ 		mov	ax, 1
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jle	short loc_312EF	; Jump if Less or Equal	(ZF=1 |	SF!=OF)
//@ 		jmp	locret_313E6	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_312EF:				; CODE XREF: BlowSpark+9Ej
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_312F7	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_312F4:				; CODE XREF: BlowSpark+197j
//@ 		inc	[bp+j]		; int16_t
//@ 
//@ loc_312F7:				; CODE XREF: BlowSpark+A6j
//@ 		cmp	BCount,	8Ch ; 'ﾌ' ; uint16_t
//@ 		jb	short loc_31302	; Jump if Below	(CF=1)
//@ 		jmp	loc_313DB	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3275
//@ 
//@ loc_31302:				; CODE XREF: BlowSpark+B1j
//@ 		mov	ax, [bp+vx0]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vx0]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+gx], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3276
//@ 		mov	ax, [bp+vx0]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vx0]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+ry]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		pop	cx
//@ 		pop	bx
//@ 		sub	ax, cx		; Integer Subtraction
//@ 		sbb	dx, bx		; Integer Subtraction with Borrow
//@ 		mov	[bp+gy], ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3277
//@ 		push	[bp+gx]		; int16_t
//@ 		push	[bp+gy]		; int16_t
//@ 		push	140h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+rz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0A0h ; 'ﾠ'  ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		mov	ax, [bp+vz0]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+vz0]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		mov	ax, [bp+vz0]	; int16_t
//@ 		shl	ax, 1		; Shift	Logical	Left
//@ 		push	ax
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+vz0]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	[bp+vz]		; int16_t
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		push	dx
//@ 		push	ax
//@ 		mov	ax, [bp+vz]	; int16_t
//@ 		neg	ax		; Two's Complement Negation
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		mov	cx, 3
//@ 		idiv	cx		; Signed Divide
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		pop	cx
//@ 		pop	bx
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		and	ax, [bp+RMask]	; int16_t
//@ 		add	ax, [bp+s]	; int16_t
//@ 		push	ax
//@ 		call	AddBlow		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3280
//@ 
//@ loc_313DB:				; CODE XREF: BlowSpark+B3j
//@ 		mov	ax, [bp+j]	; int16_t
//@ 		cmp	ax, [bp+var_10]	; Compare Two Operands
//@ 		jz	short locret_313E6 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_312F4	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3281
//@ 
//@ locret_313E6:				; CODE XREF: BlowSpark+A0j
//@ 					; BlowSpark+195j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	0Ah		; Return Far from Procedure
//@ BlowSpark	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3286
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BlowSmoke	proc far		; CODE XREF: AnimateRockets+6EAP
//@ 					; ExecuteEvent+240P
//@ 
//@ j		= word ptr -2		; int16_t
//@ bz		= word ptr  6		; int16_t
//@ by		= word ptr  8		; int16_t
//@ $bx		= word ptr  0Ah		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3287
//@ 		push	53h ; 'S'
//@ 		push	0
//@ 		push	0
//@ 		push	[bp+$bx]	; int16_t
//@ 		push	[bp+by]		; int16_t
//@ 		push	[bp+bz]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3288
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_3140C	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_31409:				; CODE XREF: BlowSmoke+90j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3289
//@ 
//@ loc_3140C:				; CODE XREF: BlowSmoke+1Dj
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+$bx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 14h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	28h ; '('
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+by]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 14h		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	40h ; '@'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+bz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 20h	; ' '   ; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	34h ; '4'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 0Ah		; Add
//@ 		push	ax
//@ 		push	9
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	3	; int16_t
//@ 		jnz	short loc_31409	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3291
//@ 		leave			; High Level Procedure Exit
//@ 		retf	6		; Return Far from Procedure
//@ BlowSmoke	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3296
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ BlowShootSmoke	proc far		; CODE XREF: AnimateRockets+6CDP
//@ 					; ExecuteEvent+25AP ...
//@ 
//@ j		= word ptr -2		; int16_t
//@ Water		= byte ptr  6		; bool
//@ bz		= word ptr  8		; int16_t
//@ by		= word ptr  0Ah		; int16_t
//@ $bx		= word ptr  0Ch		; int16_t
//@ 
//@ 		enter	2, 0		; Make Stack Frame for Procedure Parameters
//@ ; #line	"CSPBIO.PAS" 3297
//@ 		cmp	[bp+Water], 0	; bool
//@ 		jz	short loc_31491	; Jump if Zero (ZF=1)
//@ 		mov	[bp+j],	1	; int16_t
//@ 		jmp	short loc_31496	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_31491:				; CODE XREF: BlowShootSmoke+8j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ ; #line	"CSPBIO.PAS" 3298
//@ 
//@ loc_31496:				; CODE XREF: BlowShootSmoke+Fj
//@ 		push	53h ; 'S'
//@ 		push	1
//@ 		push	[bp+j]		; int16_t
//@ 		push	[bp+$bx]	; int16_t
//@ 		push	[bp+by]		; int16_t
//@ 		push	[bp+bz]		; int16_t
//@ 		call	AddEvent	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3300
//@ 		push	[bp+$bx]	; int16_t
//@ 		push	[bp+by]		; int16_t
//@ 		push	[bp+bz]		; int16_t
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		push	0
//@ 		call	AddBlow		; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3302
//@ 		cmp	[bp+Water], 0	; bool
//@ 		jz	short loc_31515	; Jump if Zero (ZF=1)
//@ ; #line	"CSPBIO.PAS" 3304
//@ 		mov	[bp+j],	1	; int16_t
//@ 		jmp	short loc_314D1	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_314CE:				; CODE XREF: BlowShootSmoke+90j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3305
//@ 
//@ loc_314D1:				; CODE XREF: BlowShootSmoke+4Cj
//@ 		push	[bp+$bx]	; int16_t
//@ 		push	[bp+by]		; int16_t
//@ 		push	140h
//@ 		push	7
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFDh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	7
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFDh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	40h ; '@'
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 40h	; '@'   ; Add
//@ 		push	ax
//@ 		push	0Fh
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	8	; int16_t
//@ 		jnz	short loc_314CE	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3309
//@ 		jmp	locret_31624	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3312
//@ 
//@ loc_31515:				; CODE XREF: BlowShootSmoke+45j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_3151F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3151C:				; CODE XREF: BlowShootSmoke+10Dj
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3313
//@ 
//@ loc_3151F:				; CODE XREF: BlowShootSmoke+9Aj
//@ 		push	1Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+$bx]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0Dh		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	1Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+by]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		sub	ax, 0Dh		; Integer Subtraction
//@ 		sbb	dx, 0		; Integer Subtraction with Borrow
//@ 		push	ax
//@ 		push	20h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+bz]	; int16_t
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		add	ax, 20h	; ' '   ; Add
//@ 		adc	dx, 0		; Add with Carry
//@ 		push	ax
//@ 		push	0
//@ 		push	0
//@ 		push	12h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		add	ax, 0Eh		; Add
//@ 		push	ax
//@ 		push	0Ch
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	3	; int16_t
//@ 		jnz	short loc_3151C	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3317
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+j],	ax	; int16_t
//@ 		jmp	short loc_31599	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_31596:				; CODE XREF: BlowShootSmoke+1A1j
//@ 		inc	[bp+j]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3318
//@ 
//@ loc_31599:				; CODE XREF: BlowShootSmoke+114j
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+$bx]	; int16_t
//@ 		add	ax, 0FFFBh	; Add
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+by]	; int16_t
//@ 		sub	ax, 5		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	10h
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		mov	cx, ax
//@ 		mov	bx, dx
//@ 		mov	ax, [bp+bz]	; int16_t
//@ 		sub	ax, 8		; Integer Subtraction
//@ 		cwd			; AX ->	DX:AX (with sign)
//@ 		add	ax, cx		; Add
//@ 		adc	dx, bx		; Add with Carry
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFBh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	0Ah
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFFBh	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	20h ; ' '
//@ 		call	@Random$q4Word	; Random(range:	Word): Word{AX}
//@ 		xor	dx, dx		; Logical Exclusive OR
//@ 		add	ax, 0FFF0h	; Add
//@ 		adc	dx, 0FFFFh	; Add with Carry
//@ 		push	ax
//@ 		push	0Dh
//@ 		call	AddBlow		; function far PASCAL returns void
//@ 		cmp	[bp+j],	1	; int16_t
//@ 		jz	short locret_31624 ; Jump if Zero (ZF=1)
//@ 		jmp	loc_31596	; Jump
//@ ; ---------------------------------------------------------------------------
//@ ; #line	"CSPBIO.PAS" 3320
//@ 
//@ locret_31624:				; CODE XREF: BlowShootSmoke+92j
//@ 					; BlowShootSmoke+19Fj
//@ 		leave			; High Level Procedure Exit
//@ 		retf	8		; Return Far from Procedure
//@ BlowShootSmoke	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3330
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutConsMessage	proc far		; CODE XREF: ExecConsole+229P
//@ 					; ExecConsole+2F8P ...
//@ 
//@ i		= word ptr -102h	; int16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ 
//@ 		enter	102h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSPBIO.PAS" 3331
//@ 		mov	[bp+i],	1	; int16_t
//@ 		jmp	short loc_3164F	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_3164B:				; CODE XREF: PutConsMessage+4Cj
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_3164F:				; CODE XREF: PutConsMessage+21j
//@ 		imul	di, [bp+i], 29h	; int16_t
//@ 		add	di, 0E6EEh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	di, ax,	29h	; Signed Multiply
//@ 		add	di, 0E6EEh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		cmp	[bp+i],	6	; int16_t
//@ 		jnz	short loc_3164B	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3332
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0CDh) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 3333
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ PutConsMessage	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3337
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutConsMessage2	proc far		; CODE XREF: INIT_IPX_SERVER+8DP
//@ 					; LoadServerPatch+153P	...
//@ 
//@ i		= word ptr -102h	; int16_t
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
//@ 
//@ 		enter	102h, 0		; Make Stack Frame for Procedure Parameters
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
//@ ; #line	"CSPBIO.PAS" 3338
//@ 		mov	[bp+i],	1	; int16_t
//@ 		jmp	short loc_316B3	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_316AF:				; CODE XREF: PutConsMessage2+4Cj
//@ 		inc	[bp+i]		; int16_t
//@ 
//@ loc_316B3:				; CODE XREF: PutConsMessage2+21j
//@ 		imul	di, [bp+i], 29h	; int16_t
//@ 		add	di, 0E6EEh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		mov	ax, [bp+i]	; int16_t
//@ 		dec	ax		; Decrement by 1
//@ 		imul	di, ax,	29h	; Signed Multiply
//@ 		add	di, 0E6EEh	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		cmp	[bp+i],	6	; int16_t
//@ 		jnz	short loc_316AF	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3339
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, (offset ConsoleComm+0CDh) ;	char[287] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	28h ; '('
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 3340
//@ 		cmp	MessageRec.LTime+0BDh, 0 ; struct MessageRec$Element[4]
//@ 		jbe	short loc_3170A	; Jump if Below	or Equal (CF=1 | ZF=1)
//@ ; #line	"CSPBIO.PAS" 3342
//@ 		mov	di, (offset MessageRec.Line+3Fh) ; struct MessageRec$Element[4]
//@ 		push	ds
//@ 		push	di
//@ 		mov	di, offset MessageRec ;	struct MessageRec$Element[4]
//@ 		push	ds
//@ 		push	di
//@ 		push	0BDh ; 'ﾽ'
//@ 		call	@Move$qm3Anyt14Word ; Move(var source, dest; count: Word)
//@ ; #line	"CSPBIO.PAS" 3343
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	MessageRec.LTime+0BDh, ax ; struct MessageRec$Element[4]
//@ ; #line	"CSPBIO.PAS" 3345
//@ 
//@ loc_3170A:				; CODE XREF: PutConsMessage2+65j
//@ 		xor	ax, ax		; Logical Exclusive OR
//@ 		mov	[bp+i],	ax	; int16_t
//@ 		jmp	short loc_31716	; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_31712:				; CODE XREF: PutConsMessage2+C0j
//@ 		inc	[bp+i]		; int16_t
//@ ; #line	"CSPBIO.PAS" 3346
//@ 
//@ loc_31716:				; CODE XREF: PutConsMessage2+84j
//@ 		imul	di, [bp+i], 3Fh	; int16_t
//@ 		cmp	word ptr [di-0C9Dh], 0 ; Compare Two Operands
//@ 		jnz	short loc_31747	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3347
//@ 		imul	di, [bp+i], 3Fh	; int16_t
//@ 		mov	word ptr [di-0C9Dh], 1F4h
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		imul	di, [bp+i], 3Fh	; int16_t
//@ 		add	di, 0F326h	; Add
//@ 		push	ds
//@ 		push	di
//@ 		push	3Ch ; '<'
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ 		jmp	short locret_3174E ; Jump
//@ ; ---------------------------------------------------------------------------
//@ 
//@ loc_31747:				; CODE XREF: PutConsMessage2+94j
//@ 		cmp	[bp+i],	3	; int16_t
//@ 		jnz	short loc_31712	; Jump if Not Zero (ZF=0)
//@ ; #line	"CSPBIO.PAS" 3348
//@ 
//@ locret_3174E:				; CODE XREF: PutConsMessage2+B9j
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ PutConsMessage2	endp
//@ 
//@ ; #line	"CSPBIO.PAS" 3351
//@ 
//@ ; =============== S U B	R O U T	I N E =======================================
//@ 
//@ ; function far PASCAL returns void
//@ ; Attributes: bp-based frame
//@ 
//@ PutConsMessage3	proc far		; CODE XREF: LoadClientPatch+F5P
//@ 					; LoadClientPatch+235P	...
//@ 
//@ s		= byte ptr -100h	; char[256] // Pascal string
//@ arg_0		= dword	ptr  6
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
//@ ; #line	"CSPBIO.PAS" 3352
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		mov	di, offset NetMessage ;	char[33] // Pascal string
//@ 		push	ds
//@ 		push	di
//@ 		push	20h ; ' '
//@ 		call	@$basg$qm6Stringt14Byte	; Store	string
//@ ; #line	"CSPBIO.PAS" 3353
//@ 		lea	di, [bp+s]	; char[256] // Pascal string
//@ 		push	ss
//@ 		push	di
//@ 		call	PutConsMessage2	; function far PASCAL returns void
//@ ; #line	"CSPBIO.PAS" 3354
//@ 		leave			; High Level Procedure Exit
//@ 		retf	4		; Return Far from Procedure
//@ PutConsMessage3	endp
//@ 
//! ; ---------------------------------------------------------------------------
//! aChasmdat_2	db 9,'CHASMDAT\'        ; DATA XREF: $CspBioInit+Co
//! aCsm_bin	db 7,'csm.bin'          ; DATA XREF: $CspBioInit+1Do
//! 					; $CspBioInit+33o ...
static const char* const CHASM_DATA_FILENAME = "csm.bin";
//! aBadCsm_binHead	db 19,'Bad csm.bin header.' ; DATA XREF: $CspBioInit:loc_31870o
//@ aLoadingFrom	db 14,'Loading from: '  ; DATA XREF: $CspBioInit+E4o
//! ; #line	"CSPBIO.PAS" 3357
//!
//! ; =============== S U B	R O U T	I N E =======================================
//!
//! ; Attributes: bp-based frame
//!
//@ $CspBioInit	proc far		; CODE XREF: PROGRAM+14P
void CspBioInit()
{
//! 		push	bp
//! 		mov	bp, sp
//! ; #line	"CSPBIO.PAS" 3358
//! 		call	InitVideo	; function near	PASCAL returns void
	InitVideo();
//! ; #line	"CSPBIO.PAS" 3359
//! 		mov	CurVideoMode, 1	; uint16_t
	CurVideoMode = 1;
//! ; #line	"CSPBIO.PAS" 3360
//! 		mov	di, offset aChasmdat_2 ; "CHASMDAT\\"
//! 		push	cs
//! 		push	di
//! 		mov	di, offset BaseFile ; char[81] // Pascal string
//! 		push	ds
//! 		push	di
//! 		push	50h ; 'P'
//! 		call	@$basg$qm6Stringt14Byte	; Store	string
	strncpy(BaseFile, CHASM_DATA_DIRECTORY, sizeof BaseFile - 1);
//! ; #line	"CSPBIO.PAS" 3361
//! 		mov	di, offset aCsm_bin ; "csm.bin"
//! 		push	cs
//! 		push	di
//! 		call	ExistFile	; function far PASCAL returns PASCAL boolean 'Boolean'
//! 		or	al, al		; Logical Inclusive OR
//! 		jnz	short loc_317F1	; Jump if Not Zero (ZF=0)
//! 		jmp	loc_3189B	; Jump
	if (ExistFile(CHASM_DATA_FILENAME))
	{
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 3363
//!
//! loc_317F1:				; CODE XREF: $CspBioInit+29j
//! 		mov	Internal, 1	; bool
		Internal = 1;
//! 		mov	di, offset aCsm_bin ; "csm.bin"
//! 		push	cs
//! 		push	di
//! 		mov	di, offset BaseFile ; char[81] // Pascal string
//! 		push	ds
//! 		push	di
//! 		push	50h ; 'P'
//! 		call	@$basg$qm6Stringt14Byte	; Store	string
		strncpy(BaseFile, CHASM_DATA_FILENAME, sizeof BaseFile - 1);
//! ; #line	"CSPBIO.PAS" 3364
//! 		mov	di, offset FileTable ; TFileTable$Element*
//! 		push	ds
//! 		push	di
//! 		push	0A800h
//! 		call	GetMem16	; function far PASCAL returns void
//! ; #line	"CSPBIO.PAS" 3365
//! 		mov	di, offset F	; struct BFile
//! 		push	ds
//! 		push	di
//! 		mov	di, offset aCsm_bin ; "csm.bin"
//! 		push	cs
//! 		push	di
//! 		call	@Assign$qm4Filem6String	; Assign(var f:	File; name: String)
//! 		mov	di, offset F	; struct BFile
//! 		push	ds
//! 		push	di
//! 		push	1
//! 		call	@Reset$qm4File4Word ; Reset(var	f: File; recsize: Word)
		F = fopen(CHASM_DATA_FILENAME, "rb");
//! ; #line	"CSPBIO.PAS" 3366
//! 		mov	di, offset F	; struct BFile
//! 		push	ds
//! 		push	di
//! 		mov	di, offset Ll	; int32_t
//! 		push	ds
//! 		push	di
//! 		push	4
//! 		xor	ax, ax		; Logical Exclusive OR
//! 		push	ax
//! 		push	ax
//! 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
		fread(&Ll, sizeof Ll, 1, F);
//! ; #line	"CSPBIO.PAS" 3367
//! 		mov	di, offset F	; struct BFile
//! 		push	ds
//! 		push	di
//! 		mov	di, offset intFCnt ; uint16_t
//! 		push	ds
//! 		push	di
//! 		push	2
//! 		xor	ax, ax		; Logical Exclusive OR
//! 		push	ax
//! 		push	ax
//! 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
		fread(&intFCnt, sizeof intFCnt, 1, F);
//? 		dec	intFCnt		; uint16_t
//		--intFCnt;
//! ; #line	"CSPBIO.PAS" 3368
		static const int32_t CSMid = 0x64695343; // "CSid"
//! 		mov	ax, word ptr Ll	; int32_t
//! 		mov	dx, word ptr Ll+2 ; int32_t
//! 		cmp	dx, word ptr CSMid+2 ; int32_t
//! 		jnz	short loc_31870	; Jump if Not Zero (ZF=0)
//! 		cmp	ax, word ptr CSMid ; int32_t
//! 		jz	short loc_3187A	; Jump if Zero (ZF=1)
		if (CSMid != Ll)
		{
//!
//! loc_31870:				; CODE XREF: $CspBioInit+A5j
//! 		mov	di, offset aBadCsm_binHead ; "Bad csm.bin header."
//! 		push	cs
//! 		push	di
//! 		call	far ptr	DoHalt	; function far PASCAL returns void
			DoHalt("Bad csm.bin header.");
		}
//! ; ---------------------------------------------------------------------------
//! ; #line	"CSPBIO.PAS" 3369
//!
//! loc_3187A:				; CODE XREF: $CspBioInit+ABj
//! 		mov	di, offset F	; struct BFile
//! 		push	ds
//! 		push	di
//! 		les	di, FileTable	; TFileTable$Element*
//! 		push	es
//! 		push	di
//! 		push	0A800h
//! 		xor	ax, ax		; Logical Exclusive OR
//! 		push	ax
//! 		push	ax
//! 		call	@BlockRead$qm4Filem3Any4Wordm4Word ; BlockRead(var f: File; var	buf; count: Word;var result: Word)
		fread(FileTable, sizeof FileTable, 1, F);

		for (uint16_t i = 0; i < intFCnt; ++i)
		{
			PascalToCString(FileTable[i].FName);
		}

//! ; #line	"CSPBIO.PAS" 3370
//! 		mov	di, offset F	; struct BFile
//! 		push	ds
//! 		push	di
//! 		call	@Close$qm4File	; Close(var f: File)
//! ; #line	"CSPBIO.PAS" 3373
		fclose(F);
	}
//!
//! loc_3189B:				; CODE XREF: $CspBioInit+2Bj
//! 		cmp	byte ptr BaseFile, 0 ; char[81]	// Pascal string
//! 		jz	short locret_318C4 ; Jump if Zero (ZF=1)
	if ('\0' != BaseFile)
	{
//! ; #line	"CSPBIO.PAS" 3374
//! 		mov	di, offset Output ; Text
//! 		push	ds
//! 		push	di
//! 		mov	di, offset aLoadingFrom	; "Loading from: "
//! 		push	cs
//! 		push	di
//! 		push	0
//! 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//! 		mov	di, offset BaseFile ; char[81] // Pascal string
//! 		push	ds
//! 		push	di
//! 		push	0
//! 		call	@Write$qm4Textm6String4Word ; Write(var	f; s: String; width: Word)
//! 		call	@WriteLn$qm4Text ; WriteLn(var f: Text)
		printf("Loading from: %s\n", BaseFile);
	}
//! ; #line	"CSPBIO.PAS" 3375
//!
//! locret_318C4:				; CODE XREF: $CspBioInit+DDj
//! 		leave			; High Level Procedure Exit
//! 		retf			; Return Far from Procedure
}
//@ $CspBioInit	endp
