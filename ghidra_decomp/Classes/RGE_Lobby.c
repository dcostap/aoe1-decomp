// Class: RGE_Lobby
// Size:  0x1C
//
// Member Layout:
// [0x000] void * HostHWND
// [0x004] IDirectPlayLobby * glpDPL
// [0x008] IDirectPlayLobby2 * glpDPL2
// [0x00C] IDirectPlay2 * glpDP
// [0x010] DPLCONNECTION * glpdplConnection
// [0x014] uchar lobby_game
// [0x018] RGE_Comm_Error * Err
// ----------------------------------------------------------------

// Function: RGE_Lobby
// Address: 0042f290
/* public: __thiscall RGE_Lobby::RGE_Lobby(void *) */

RGE_Lobby * __thiscall RGE_Lobby::RGE_Lobby(RGE_Lobby *this,void *param_1)
{
  RGE_Comm_Error *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cd3b;
  *unaff_FS_OFFSET = &local_c;
  this->HostHWND = param_1;
  pRVar1 = (RGE_Comm_Error *)operator_new(8);
  local_4 = 0;
  if (pRVar1 == (RGE_Comm_Error *)0x0) {
    pRVar1 = (RGE_Comm_Error *)0x0;
  }
  else {
    pRVar1 = (RGE_Comm_Error *)RGE_Comm_Error::RGE_Comm_Error(pRVar1,param_1);
  }
  this->Err = pRVar1;
  this->glpDP = (IDirectPlay2 *)0x0;
  this->glpdplConnection = (DPLCONNECTION *)0x0;
  this->glpDPL = (IDirectPlayLobby *)0x0;
  this->glpDPL2 = (IDirectPlayLobby2 *)0x0;
  this->lobby_game = '\0';
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Lobby
// Address: 0042f300
/* public: __thiscall RGE_Lobby::~RGE_Lobby(void) */

void __thiscall RGE_Lobby::~RGE_Lobby(RGE_Lobby *this)
{
  RGE_Comm_Error *this_00;
  
  this_00 = this->Err;
  if (this_00 != (RGE_Comm_Error *)0x0) {
    RGE_Comm_Error::~RGE_Comm_Error(this_00);
    operator_delete(this_00);
  }
  ClearLobbyInfo(this);
  return;
}

// --------------------------------------------------

// Function: ClearLobbyInfo
// Address: 0042f330
// [HELPER] s_Release: "Release"
/* public: void __thiscall RGE_Lobby::ClearLobbyInfo(void) */

void __thiscall RGE_Lobby::ClearLobbyInfo(RGE_Lobby *this)
{
  IDirectPlayLobby2 *pIVar1;
  long lVar2;
  
  if (this->glpdplConnection != (DPLCONNECTION *)0x0) {
    operator_delete(this->glpdplConnection);
    this->glpdplConnection = (DPLCONNECTION *)0x0;
  }
  pIVar1 = this->glpDPL2;
  if (pIVar1 != (IDirectPlayLobby2 *)0x0) {
    lVar2 = (**(code **)((int)*pIVar1 + 8))(pIVar1);
    RGE_Comm_Error::ShowReturn(this->Err,lVar2,s_Release);
    this->glpDPL2 = (IDirectPlayLobby2 *)0x0;
  }
  this->lobby_game = '\0';
  this->glpDP = (IDirectPlay2 *)0x0;
  return;
}

// --------------------------------------------------

// Function: IsLobbyLaunched
// Address: 0042f370
// [HELPER] s_LOBBY_GAME_LAUNCH_STATUS____d: "LOBBY GAME LAUNCH STATUS = %d"
/* public: int __thiscall RGE_Lobby::IsLobbyLaunched(void) */

int __thiscall RGE_Lobby::IsLobbyLaunched(RGE_Lobby *this)
{
  TDebuggingLog::Log(L,(char *)L,s_LOBBY_GAME_LAUNCH_STATUS____d,(uint)this->lobby_game);
  return (uint)this->lobby_game;
}

// --------------------------------------------------

// Function: CheckForLobbyLaunch
// Address: 0042f430
// [HELPER] s_Calling_enumeration_of_players_: "Calling enumeration of players."
// [HELPER] s_Connect: "Connect"
// [HELPER] s_Failed_to_connect_: "Failed to connect!"
// [HELPER] s_LOBBY_LAUNCHED_GAME_: "LOBBY LAUNCHED GAME."
// [HELPER] s_Lobby_Create: "Lobby Create"
// [HELPER] s_Lobby_QI: "Lobby QI"
// [HELPER] s_Post_Connect: "Post Connect"
// [HELPER] s_Post_ENUMP: "Post ENUMP"
// [HELPER] s_Pre_QI: "Pre QI"
// [HELPER] s_Pre_connect: "Pre-connect"
// [HELPER] s_Queryinterface_failed_: "Queryinterface failed."
/* WARNING: Variable defined which should be unmapped: dwSize */
/* public: unsigned char __thiscall RGE_Lobby::CheckForLobbyLaunch(struct IDirectPlay3 * &) */

uchar __thiscall RGE_Lobby::CheckForLobbyLaunch(RGE_Lobby *this,IDirectPlay3 **param_1)
{
  IDirectPlayLobby2 **ppIVar1;
  IDirectPlayLobby2 *pIVar2;
  IDirectPlay2 *pIVar3;
  int iVar4;
  DPLCONNECTION *pDVar5;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  IDirectPlayLobby *pIStack_20;
  ulong dwSize;
  
  *param_1 = (IDirectPlay3 *)0x0;
  ClearLobbyInfo(this);
  pIStack_20 = (IDirectPlayLobby *)0x0;
  iVar4 = _DirectPlayLobbyCreateA_20(0,&this->glpDPL);
  pIStack_20 = (IDirectPlayLobby *)0x42f470;
  RGE_Comm_Error::ShowReturn(this->Err,iVar4,s_Lobby_Create);
  if (iVar4 < 0) {
    return '\0';
  }
  pIStack_20 = this->glpDPL;
  ppIVar1 = &this->glpDPL2;
  (**(code **)*pIStack_20)();
  pIVar2 = *ppIVar1;
  if (pIVar2 == (IDirectPlayLobby2 *)0x0) {
    return '\0';
  }
  (**(code **)((int)*pIVar2 + 0x20))(pIVar2,0,0,&stack0xfffffff0);
  pDVar5 = (DPLCONNECTION *)operator_new((uint)&pIStack_20->field_0x1);
  this->glpdplConnection = pDVar5;
  iVar4 = (**(code **)((int)**ppIVar1 + 0x20))(*ppIVar1,0,pDVar5,&pIStack_20);
  if (iVar4 < 0) {
    this->lobby_game = '\0';
    return '\0';
  }
  TDebuggingLog::Log(this_00,(char *)L,s_LOBBY_LAUNCHED_GAME_);
  this->glpdplConnection->lpSessionDesc->dwFlags = 0x44;
  this->glpdplConnection->lpSessionDesc->dwMaxPlayers = 9;
  (**(code **)((int)**ppIVar1 + 0x30))(*ppIVar1,0,0,this->glpdplConnection);
  TDebuggingLog::Log(this_01,(char *)L,s_Pre_connect);
  iVar4 = (**(code **)((int)**ppIVar1 + 0xc))(*ppIVar1,0,&this->glpDP,0);
  TDebuggingLog::Log(L,(char *)L,s_Post_Connect);
  if (iVar4 < 0) {
    if (iVar4 == -0x7788ff10) {
      return 0xff;
    }
    TDebuggingLog::Log(this_02,(char *)L,s_Failed_to_connect_);
    RGE_Comm_Error::ShowReturn(this->Err,iVar4,s_Connect);
    return 0xff;
  }
  TDebuggingLog::Log(this_02,(char *)L,s_Pre_QI);
  pIVar3 = this->glpDP;
  iVar4 = (**(code **)*pIVar3)(pIVar3,&_IID_IDirectPlay3A,param_1);
  RGE_Comm_Error::ShowReturn(this->Err,iVar4,s_Lobby_QI);
  if (iVar4 < 0) {
    TDebuggingLog::Log(this_03,(char *)L,s_Queryinterface_failed_);
    return 0xff;
  }
  TDebuggingLog::Log(this_03,(char *)L,s_Calling_enumeration_of_players_);
  (**(code **)((int)**param_1 + 0x30))(*param_1,0,EnumPlayersCallbackLobby,this,0);
  TDebuggingLog::Log(this_04,(char *)L,s_Post_ENUMP);
  this->lobby_game = '\x01';
  return '\x01';
}

// --------------------------------------------------

// Function: IsThisHost
// Address: 0042f640
/* public: unsigned char __thiscall RGE_Lobby::IsThisHost(void) */

uchar __thiscall RGE_Lobby::IsThisHost(RGE_Lobby *this)
{
  if (this->lobby_game == '\0') {
    return '\0';
  }
  return (byte)(this->glpdplConnection->dwFlags >> 1) & 1;
}

// --------------------------------------------------

// Function: GetPlayerInfo
// Address: 0042f660
/* public: unsigned char __thiscall RGE_Lobby::GetPlayerInfo(char * *) */

uchar __thiscall RGE_Lobby::GetPlayerInfo(RGE_Lobby *this,char **param_1)
{
  if (this->lobby_game == '\0') {
    return '\0';
  }
  *param_1 = (char *)this->glpdplConnection->lpPlayerName->field2_0x8;
  return '\x01';
}

// --------------------------------------------------

// Function: GetSessionInfo
// Address: 0042f680
/* public: unsigned char __thiscall RGE_Lobby::GetSessionInfo(struct DPSESSIONDESC2 &) */

uchar __thiscall RGE_Lobby::GetSessionInfo(RGE_Lobby *this,DPSESSIONDESC2 *param_1)
{
  int iVar1;
  DPSESSIONDESC2 *pDVar2;
  
  if (this->lobby_game == '\0') {
    return '\0';
  }
  pDVar2 = this->glpdplConnection->lpSessionDesc;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    param_1->dwSize = pDVar2->dwSize;
    pDVar2 = (DPSESSIONDESC2 *)&pDVar2->dwFlags;
    param_1 = (DPSESSIONDESC2 *)&param_1->dwFlags;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: SendZoneHandshakeResponse
// Address: 0042f6b0
/* public: long __thiscall RGE_Lobby::SendZoneHandshakeResponse(void) */

long __thiscall RGE_Lobby::SendZoneHandshakeResponse(RGE_Lobby *this)
{
  return (uint)(this->lobby_game != '\0');
}

// --------------------------------------------------

// Function: GameIsOver
// Address: 0042f6c0
/* public: int __thiscall RGE_Lobby::GameIsOver(void) */

int __thiscall RGE_Lobby::GameIsOver(RGE_Lobby *this)
{
  return (uint)(this->lobby_game != '\0');
}

// --------------------------------------------------

// Function: ReceiveZoneMessages
// Address: 0042f6d0
// [HELPER] s_RX_Lobby_Messages: "RX Lobby Messages"
/* WARNING: Variable defined which should be unmapped: dwDataSize */
/* WARNING: Removing unreachable block (ram,0x0042f731) */
/* WARNING: Removing unreachable block (ram,0x0042f735) */
/* WARNING: Removing unreachable block (ram,0x0042f74e) */
/* WARNING: Removing unreachable block (ram,0x0042f759) */
/* WARNING: Removing unreachable block (ram,0x0042f77c) */
/* WARNING: Removing unreachable block (ram,0x0042f783) */
/* WARNING: Removing unreachable block (ram,0x0042f7df) */
/* WARNING: Removing unreachable block (ram,0x0042f7c1) */
/* WARNING: Removing unreachable block (ram,0x0042f7a2) */
/* WARNING: Removing unreachable block (ram,0x0042f7fe) */
/* WARNING: Recovered jumptable eliminated as dead code */
/* public: long __thiscall RGE_Lobby::ReceiveZoneMessages(void) */

long __thiscall RGE_Lobby::ReceiveZoneMessages(RGE_Lobby *this)
{
  long lVar1;
  ulong dwDataSize;
  ulong dwRXFlags;
  char Data [2048];
  
  if (this->lobby_game != '\0') {
    lVar1 = (**(code **)((int)*this->glpDPL + 0x24))(this->glpDPL,0);
    RGE_Comm_Error::ShowReturn(this->Err,lVar1,s_RX_Lobby_Messages);
  }
  return 0;
}

// --------------------------------------------------

// Function: SendZoneMessage
// Address: 0042f830
// [HELPER] s_SendLobbyMessage_returns_OK: "SendLobbyMessage returns OK"
// [HELPER] s_Send_Lobby_Msg: "Send Lobby Msg"
// [HELPER] s_Sending__d_bytes_to_the_Zone__To: "Sending %d bytes to the Zone (Total message size %d)."
/* public: long __thiscall RGE_Lobby::SendZoneMessage(char *,unsigned long,struct _GUID) */

long __thiscall
RGE_Lobby::SendZoneMessage(RGE_Lobby *this,char *param_1,ulong param_2,_GUID param_3)
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  TDebuggingLog *this_00;
  char *pcVar6;
  
  if (this->lobby_game == '\0') {
    return 0;
  }
  uVar1 = param_2 + 0x30;
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Sending__d_bytes_to_the_Zone__To,param_2,
                     uVar1);
  puVar3 = (undefined4 *)operator_new(uVar1);
  *puVar3 = 5;
  puVar3[1] = 0;
  puVar3[2] = _GUID_NULL;
  puVar3[3] = DAT_00577a2c;
  puVar3[4] = DAT_00577a30;
  uVar2 = DAT_00577a34;
  puVar3[10] = uVar1;
  puVar3[5] = uVar2;
  puVar3[6] = param_3.Data1;
  puVar3[7] = param_3._4_4_;
  puVar3[8] = param_3.Data4._0_4_;
  puVar3[9] = param_3.Data4._4_4_;
  pcVar6 = (char *)(puVar3 + 0xb);
  for (uVar5 = param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *param_1;
    param_1 = param_1 + 1;
    pcVar6 = pcVar6 + 1;
  }
  iVar4 = (**(code **)((int)*this->glpDPL2 + 0x2c))(this->glpDPL2,0,0,puVar3,uVar1);
  operator_delete(puVar3);
  if (iVar4 == 0) {
    TDebuggingLog::Log(this_00,(char *)L,s_SendLobbyMessage_returns_OK);
  }
  RGE_Comm_Error::ShowReturn(this->Err,iVar4,s_Send_Lobby_Msg);
  return iVar4;
}

// --------------------------------------------------

