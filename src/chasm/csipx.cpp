
/*
**---------------------------------------------------------------------------
** OpenChasm - Free software reconstruction of Chasm: The Rift game
** Copyright (C) 2013, 2014 Alexey Lysiuk
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

#include "chasm.h"

namespace Chasm
{

void GetRealModeIntVector(/*...*/);
void RealInt60h(/*...*/);
void DO_CD_Play(/*...*/);
void DO_CD_Stop(/*...*/);
void ProcessCD(/*...*/);
void RefreshMachineMode(/*...*/);
void ReInstallFreeECB(/*...*/);
void ReinitPlayer(/*...*/);
void MakeChanges(/*...*/);
void DoneChanges(/*...*/);
void CorrectProcesses(/*...*/);
void DoneProcesses(/*...*/);
Uint8 GetFreeNetNumber(/*...*/);
void ConnectIPXProcessor(/*...*/);
void CheckNP(/*...*/);
void INIT_IPX_SERVER(/*...*/);
void INIT_IPX_CLIENT(/*...*/);
void CloseIPXChannel(/*...*/);
void CheckSendComplette(/*...*/);
void SendServerPatch(/*...*/);
void LoadClientPatch(/*...*/);
void LoadServerPatch(/*...*/);
void SendClientPatch(/*...*/);
bool CheckIDsConflict(/*...*/);
void LookForServer(/*...*/);
void ScanNet(/*...*/);
void JoinNetworkGame(/*...*/);
void SendServerPost(/*...*/);
void SyncroTime(/*...*/);
void WaitServer(/*...*/);

} // namespace Chasm
