// Class: TCommunications_Handler
// Size:  0x1774
//
// Member Layout:
// [0x000] int OptionsChanged
// [0x004] char * OptionsData
// [0x008] int Steps
// [0x00C] ulong TickStart
// [0x010] ulong TickCount
// [0x014] ulong TimeSinceLastCall
// [0x018] TChat * Chat
// [0x01C] int MeHost
// [0x020] int HaveHostInit
// [0x024] char[4001] InCommBuff (sz: 0xFA1)
// [0xFC5] char[257] TBuff (sz: 0x101)
// [0x10C8] ulong current_turn
// [0x10CC] ulong next_command_turn
// [0x10D0] uint sequence
// [0x10D4] long WaitOnPlayer
// [0x10D8] ulong TurnSpeedMsec
// [0x10DC] ulong AcknowledgeAfterMsec
// [0x10E0] uint Me
// [0x10E4] int Multiplayer
// [0x10E8] int OutOfSyncFlag
// [0x10EC] ulong dwStopTime
// [0x10F0] float lastRXDataRate
// [0x10F4] float lastTXDataRate
// [0x10F8] char[129] MyFriendlyName (sz: 0x81)
// [0x1179] char[129] MyFormalName (sz: 0x81)
// [0x11FA] char[129] MyGameTitle (sz: 0x81)
// [0x127C] ulong CurrentPlayers
// [0x1280] int previous_last_world_random
// [0x1284] int last_world_random
// [0x1288] int StepMode
// [0x128C] ulong turnstart
// [0x1290] ulong lastcalltick
// [0x1294] ulong mselapsed
// [0x1298] int AvgTurnTime
// [0x129C] int SkipFrames
// [0x12A0] int PauseChangePending
// [0x12A4] ulong CommunicationsVersionCode
// [0x12A8] int ShuttingDown
// [0x12AC] ulong ReturnElapsed
// [0x12B0] ulong ReturnRXPacketSize
// [0x12B4] ulong ReturnTXPacketSize
// [0x12B8] ulong RXPacketLength
// [0x12BC] ulong RXPacketLengthHigh
// [0x12C0] ulong TXPacketLength
// [0x12C4] ulong TXPacketLengthHigh
// [0x12C8] NAME * FriendlyName
// [0x12CC] NAME * FormalName
// [0x12D0] ulong LastTimeoutMessageTime
// [0x12D4] COMMSTATUS CommunicationsStatus
// [0x12D8] ushort MaxGamePlayers
// [0x12DC] _GUID ServiceGUID (sz: 0x10)
// [0x12EC] _GUID ApplicationGUID (sz: 0x10)
// [0x12FC] _GUID SessionGUID (sz: 0x10)
// [0x130C] void * HostHWND
// [0x1310] int LobbyLaunched
// [0x1314] ulong MaxReceiveLatency
// [0x1318] _GUID NullGUID (sz: 0x10)
// [0x1328] ulong ResendAcknowledgements
// [0x132C] ulong ResentToOther
// [0x1330] ulong DroppedPacketCount
// [0x1334] ulong RXPackets
// [0x1338] ulong TXPackets
// [0x133C] int IAmLagging
// [0x1340] ulong ServiceTimeout
// [0x1344] ulong[10] LastPlayerCommunication (sz: 0x28)
// [0x136C] ulong[10] LastPlayerWarning (sz: 0x28)
// [0x1394] ulong[10] LastTXPing (sz: 0x28)
// [0x13BC] ulong[10] PlayerStopTurn (sz: 0x28)
// [0x13E4] uint[10] LastSerialRequestedTX (sz: 0x28)
// [0x140C] ulong[10] LastRequestHonoredTX (sz: 0x28)
// [0x1434] uint[10] LastSerialRepliedTX (sz: 0x28)
// [0x145C] ulong[10] LastRequestRepliedTX (sz: 0x28)
// [0x1484] ulong dwFlags
// [0x1488] ulong dwMaxBufferSize
// [0x148C] ulong dwMaxQueueSize
// [0x1490] ulong dwMaxPlayers
// [0x1494] ulong dwHundredBaud
// [0x1498] ulong dwLatency
// [0x149C] int[10] Kicked (sz: 0x28)
// [0x14C4] RGE_Communications_Queue * InQ
// [0x14C8] RGE_Communications_Queue * OutQ
// [0x14CC] RGE_Lobby * Lobby
// [0x14D0] RGE_TimeSinceLastCall * tslc
// [0x14D4] RGE_Communications_Speed * Speed
// [0x14D8] RGE_Communications_Synchronize * Sync
// [0x14DC] RGE_Communications_Addresses * Addresses
// [0x14E0] RGE_Comm_Error * Err
// [0x14E4] uint GTDSerialNo
// [0x14E8] uint HighResendStore
// [0x14EC] uint[10] DestMap (sz: 0x28)
// [0x1514] uchar RGE_Guaranteed_Delivery
// [0x1518] int IntentionallyDropPackets
// [0x151C] uint WaitingForAck
// [0x1520] RESENDER * Resend
// [0x1524] HOLDER * OnHold
// [0x1528] uint[10] PlayerHighSerialNumber (sz: 0x28)
// [0x1550] COMMPLAYEROPTIONS PlayerOptions (sz: 0x1D0)
// [0x1720] ulong[10] LastTurnAck (sz: 0x28)
// [0x1748] uint HoldCount
// [0x174C] int[10] WasKicked (sz: 0x28)
// ----------------------------------------------------------------

// Function: GameOver
// Address: 00425750
/* public: void __thiscall TCommunications_Handler::GameOver(void) */

void __thiscall TCommunications_Handler::GameOver(TCommunications_Handler *this)
{
  this->current_turn = 0;
  if (this->InQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(this->InQ);
  }
  if (this->OutQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(this->OutQ);
  }
  return;
}

// --------------------------------------------------

// Function: WaitingOnNamedInfo
// Address: 00425780
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s___d___s____s: "[%d] %s - %s"
// [HELPER] s___d___s____s__QUIET__d_msec__T__: "[%d] %s - %s (QUIET=%d msec  T#=%d )"
/* public: char * __thiscall TCommunications_Handler::WaitingOnNamedInfo(unsigned int) */

char * __thiscall
TCommunications_Handler::WaitingOnNamedInfo(TCommunications_Handler *this,uint param_1)
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  int iVar5;
  
  pcVar1 = this->TBuff;
  pcVar2 = WaitingOnInfo(this,param_1);
  pcVar3 = GetPlayerName(this,param_1);
  sprintf(pcVar1,s___d___s____s,param_1,pcVar3,pcVar2);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x8e);
  iVar5 = uVar4 - this->LastPlayerCommunication[param_1];
  uVar4 = this->LastTurnAck[param_1];
  pcVar2 = WaitingOnInfo(this,param_1);
  pcVar3 = GetPlayerName(this,param_1);
  sprintf(pcVar1,s___d___s____s__QUIET__d_msec__T__,param_1,pcVar3,pcVar2,iVar5,uVar4);
  return pcVar1;
}

// --------------------------------------------------

// Function: WaitingOnInfo
// Address: 00425800
/* public: char * __thiscall TCommunications_Handler::WaitingOnInfo(unsigned int) */

char * __thiscall TCommunications_Handler::WaitingOnInfo(TCommunications_Handler *this,uint param_1)
{
  int iVar1;
  
  iVar1 = IsPlayerComputer(this,param_1);
  if (iVar1 != 0) {
                    /* language.dll match for 0x4b1: "Computer" */
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b1,0x62c588,0x20);
    return &UNK_0062c585.field_0x3;
  }
  iVar1 = IsPlayerHuman(this,param_1);
  if (iVar1 == 0) {
                    /* language.dll match for 0x4b2: "Empty" */
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b2,0x62c588,0x20);
    return &UNK_0062c585.field_0x3;
  }
  if (this->LastTurnAck[param_1] < 4) {
                    /* language.dll match for 0x4b3: "Loading" */
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b3,0x62c588,0x20);
    return &UNK_0062c585.field_0x3;
  }
  if (this->LastTurnAck[param_1] < this->current_turn) {
                    /* language.dll match for 0x4b4: "Waiting" */
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b4,0x62c588,0x20);
    return &UNK_0062c585.field_0x3;
  }
                    /* language.dll match for 0x4b0: "Ready" */
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b0,0x62c588,0x20);
  return &UNK_0062c585.field_0x3;
}

// --------------------------------------------------

// Function: StopIfSyncFail
// Address: 004258e0
/* public: void __thiscall TCommunications_Handler::StopIfSyncFail(int) */

void __thiscall TCommunications_Handler::StopIfSyncFail(TCommunications_Handler *this,int param_1)
{
  RGE_Communications_Synchronize::SetDialogOnFail(this->Sync,param_1);
  RGE_Communications_Synchronize::SetStopOnFail(this->Sync,param_1);
  return;
}

// --------------------------------------------------

// Function: ShowSyncChatMsgs
// Address: 00425910
/* public: void __thiscall TCommunications_Handler::ShowSyncChatMsgs(int) */

void __thiscall TCommunications_Handler::ShowSyncChatMsgs(TCommunications_Handler *this,int param_1)
{
  RGE_Communications_Synchronize::SendChatMsgsAtChecksum(this->Sync,param_1);
  return;
}

// --------------------------------------------------

// Function: DropPacketsIntentionally
// Address: 00425930
// [HELPER] s_DROPPING_PACKETS_INTENTIONALLY__: "DROPPING PACKETS INTENTIONALLY!!!"
/* public: void __thiscall TCommunications_Handler::DropPacketsIntentionally(int) */

void __thiscall
TCommunications_Handler::DropPacketsIntentionally(TCommunications_Handler *this,int param_1)
{
  this->IntentionallyDropPackets = param_1;
  if (param_1 != 0) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_DROPPING_PACKETS_INTENTIONALLY__);
  }
  return;
}

// --------------------------------------------------

// Function: SetStepMode
// Address: 00425960
/* public: void __thiscall TCommunications_Handler::SetStepMode(int) */

void __thiscall TCommunications_Handler::SetStepMode(TCommunications_Handler *this,int param_1)
{
  this->StepMode = param_1;
  return;
}

// --------------------------------------------------

// Function: SetSpeedControl
// Address: 00425970
/* public: void __thiscall TCommunications_Handler::SetSpeedControl(int) */

void __thiscall TCommunications_Handler::SetSpeedControl(TCommunications_Handler *this,int param_1)
{
  RGE_Communications_Speed::EnableSpeedControl(this->Speed,param_1);
  return;
}

// --------------------------------------------------

// Function: CalculatePlayerRange
// Address: 00425990
/* protected: int __thiscall TCommunications_Handler::CalculatePlayerRange(void) */

int __thiscall TCommunications_Handler::CalculatePlayerRange(TCommunications_Handler *this)
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 1;
  uVar1 = this->MaxGamePlayers;
  (this->PlayerOptions).HighPlayerNumber = 0;
  (this->PlayerOptions).LowPlayerNumber = uVar1 + 1;
  if (uVar1 != 0) {
    do {
      iVar2 = IsPlayerHuman(this,uVar4);
      if (iVar2 == 0) {
        iVar2 = IsPlayerComputer(this,uVar4);
        if (iVar2 != 0) goto LAB_004259d0;
      }
      else {
LAB_004259d0:
        uVar3 = (uint)(this->PlayerOptions).HighPlayerNumber;
        if ((int)uVar3 <= (int)uVar4) {
          uVar3 = uVar4;
        }
        (this->PlayerOptions).HighPlayerNumber = (ushort)uVar3;
        uVar3 = (uint)(this->PlayerOptions).LowPlayerNumber;
        if ((int)uVar4 <= (int)uVar3) {
          uVar3 = uVar4;
        }
        (this->PlayerOptions).LowPlayerNumber = (ushort)uVar3;
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 <= (int)(uint)this->MaxGamePlayers);
  }
  return 1;
}

// --------------------------------------------------

// Function: Step
// Address: 00425a20
/* public: void __thiscall TCommunications_Handler::Step(int) */

void __thiscall TCommunications_Handler::Step(TCommunications_Handler *this,int param_1)
{
  TEST(this);
  this->Steps = this->Steps + param_1;
  return;
}

// --------------------------------------------------

// Function: TCommunications_Handler
// Address: 00425a40
// [HELPER] s_13_17_08: "13:17:08"
// [HELPER] s_COMM___RGE_COMMUNICTIONS_STARTED: "COMM:  RGE COMMUNICTIONS STARTED ---------------%s"
// [HELPER] s_COMM____s__Version_____s: "COMM:  %s  Version... %s"
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_C__msdev_work_age1_x1_com_hand_h: "C:\msdev\work\age1_x1\com_hand.h"
// [HELPER] s_Fri_Jul_17_09_39_38_1998: "Fri Jul 17 09:39:38 1998"
// [HELPER] s_Initialize_Player_List: "Initialize Player List"
// [HELPER] s__: "}"
/* WARNING: Variable defined which should be unmapped: Codestr */
/* public: __thiscall TCommunications_Handler::TCommunications_Handler(void *,unsigned char,class
   TChat *,struct _GUID) */

TCommunications_Handler * __thiscall
TCommunications_Handler::TCommunications_Handler
          (TCommunications_Handler *this,void *param_1,uchar param_2,TChat *param_3,_GUID param_4)
{
  _GUID *p_Var1;
  char cVar2;
  ushort uVar3;
  char *pcVar4;
  RGE_Communications_Queue *pRVar5;
  undefined4 *puVar6;
  RESENDER *pRVar7;
  HOLDER *pHVar8;
  RGE_Comm_Error *pRVar9;
  RGE_Lobby *pRVar10;
  RGE_Communications_Speed *pRVar11;
  RGE_Communications_Synchronize *pRVar12;
  ulong uVar13;
  int *piVar14;
  TDebuggingLog *this_00;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  ulong *puVar22;
  undefined4 *unaff_FS_OFFSET;
  char Codestr [32];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ccbd;
  *unaff_FS_OFFSET = &local_c;
  TDebuggingLog::FlushToDisk(L,1);
  this->ReturnRXPacketSize = this->RXPacketLength;
  uVar15 = this->RXPacketLength;
  if (this->RXPacketLength <= this->RXPacketLengthHigh) {
    uVar15 = this->RXPacketLengthHigh;
  }
  this->RXPacketLengthHigh = uVar15;
  this->RXPacketLength = 0;
  this->ReturnTXPacketSize = this->TXPacketLength;
  uVar15 = this->TXPacketLength;
  if (this->TXPacketLength <= this->TXPacketLengthHigh) {
    uVar15 = this->TXPacketLengthHigh;
  }
  this->TXPacketLengthHigh = uVar15;
  p_Var1 = &this->NullGUID;
  this->TXPacketLength = 0;
  this->OutQ = (RGE_Communications_Queue *)0x0;
  this->InQ = (RGE_Communications_Queue *)0x0;
  this->GTDSerialNo = 0;
  p_Var1->Data1 = 0;
  (this->NullGUID).Data2 = 0;
  (this->NullGUID).Data3 = 0;
  (this->NullGUID).Data4[0] = '\0';
  (this->NullGUID).Data4[1] = '\0';
  (this->NullGUID).Data4[2] = '\0';
  (this->NullGUID).Data4[3] = '\0';
  (this->NullGUID).Data4[4] = '\0';
  (this->NullGUID).Data4[5] = '\0';
  (this->NullGUID).Data4[6] = '\0';
  (this->NullGUID).Data4[7] = '\0';
  this->CommunicationsStatus = INITIALIZED;
  (this->ApplicationGUID).Data1 = param_4.Data1;
  (this->ApplicationGUID).Data2 = param_4.Data2;
  (this->ApplicationGUID).Data3 = param_4.Data3;
  *(undefined4 *)(this->ApplicationGUID).Data4 = param_4.Data4._0_4_;
  *(undefined4 *)((this->ApplicationGUID).Data4 + 4) = param_4.Data4._4_4_;
  (this->SessionGUID).Data1 = p_Var1->Data1;
  uVar3 = (this->NullGUID).Data3;
  (this->SessionGUID).Data2 = (this->NullGUID).Data2;
  (this->SessionGUID).Data3 = uVar3;
  *(undefined4 *)(this->SessionGUID).Data4 = *(undefined4 *)(this->NullGUID).Data4;
  *(undefined4 *)((this->SessionGUID).Data4 + 4) = *(undefined4 *)((this->NullGUID).Data4 + 4);
  (this->ServiceGUID).Data1 = p_Var1->Data1;
  uVar3 = (this->NullGUID).Data3;
  (this->ServiceGUID).Data2 = (this->NullGUID).Data2;
  (this->ServiceGUID).Data3 = uVar3;
  *(undefined4 *)(this->ServiceGUID).Data4 = *(undefined4 *)(this->NullGUID).Data4;
  *(undefined4 *)((this->ServiceGUID).Data4 + 4) = *(undefined4 *)((this->NullGUID).Data4 + 4);
  this->HostHWND = param_1;
  this->Chat = param_3;
  this->MaxGamePlayers = (ushort)param_2;
  TDebuggingLog::Log(L,(char *)L,s_COMM___RGE_COMMUNICTIONS_STARTED,
                     s_C__msdev_work_age1_x1_Com_hand_c);
  TDebuggingLog::Log(this_00,(char *)L,s_COMM____s__Version_____s,s_C__msdev_work_age1_x1_Com_hand_c
                     ,s_Fri_Jul_17_09_39_38_1998);
  uVar15 = 0xffffffff;
  pcVar4 = &s_13_17_08;
  do {
    pcVar19 = pcVar4;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar19 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar19;
  } while (cVar2 != '\0');
  uVar15 = ~uVar15;
  pcVar4 = Codestr;
  pcVar19 = pcVar19 + -uVar15;
  for (uVar16 = uVar15 >> 2; pcVar4 = pcVar4 + 4, uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar4 = *(undefined4 *)pcVar19;
    pcVar19 = pcVar19 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar4 = *pcVar19;
    pcVar19 = pcVar19 + 1;
    pcVar4 = pcVar4 + 1;
  }
  if (Codestr[4] != '\0') {
    pcVar4 = Codestr + 4;
    do {
      if (*pcVar4 == ':') {
        *pcVar4 = '0';
      }
      pcVar19 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar19 != '\0');
  }
  this->CommunicationsVersionCode = 0x2e2887;
  uVar15 = (uint)param_2;
  iVar18 = uVar15 + 1;
  pcVar4 = (char *)operator_new(iVar18 * 0x80);
  if ((NAME *)pcVar4 == (NAME *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    _param_2 = uVar15 + 1;
    pcVar19 = pcVar4;
    do {
      uVar16 = 0xffffffff;
      pcVar20 = &s__;
      do {
        pcVar21 = pcVar20;
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        pcVar21 = pcVar20 + 1;
        cVar2 = *pcVar20;
        pcVar20 = pcVar21;
      } while (cVar2 != '\0');
      uVar16 = ~uVar16;
      pcVar20 = pcVar21 + -uVar16;
      pcVar21 = pcVar19;
      for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar20;
        pcVar20 = pcVar20 + 4;
        pcVar21 = pcVar21 + 4;
      }
      _param_2 = _param_2 + -1;
      for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        *pcVar21 = *pcVar20;
        pcVar20 = pcVar20 + 1;
        pcVar21 = pcVar21 + 1;
      }
      pcVar19 = pcVar19 + 0x80;
    } while (_param_2 != 0);
  }
  this->FriendlyName = (NAME *)pcVar4;
  pcVar4 = (char *)operator_new(iVar18 * 0x80);
  if ((NAME *)pcVar4 == (NAME *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar19 = pcVar4;
    _param_2 = iVar18;
    if (-1 < (int)uVar15) {
      do {
        uVar15 = 0xffffffff;
        pcVar20 = &s__;
        do {
          pcVar21 = pcVar20;
          if (uVar15 == 0) break;
          uVar15 = uVar15 - 1;
          pcVar21 = pcVar20 + 1;
          cVar2 = *pcVar20;
          pcVar20 = pcVar21;
        } while (cVar2 != '\0');
        uVar15 = ~uVar15;
        pcVar20 = pcVar21 + -uVar15;
        pcVar21 = pcVar19;
        for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
          *(undefined4 *)pcVar21 = *(undefined4 *)pcVar20;
          pcVar20 = pcVar20 + 4;
          pcVar21 = pcVar21 + 4;
        }
        _param_2 = _param_2 + -1;
        for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
          *pcVar21 = *pcVar20;
          pcVar20 = pcVar20 + 1;
          pcVar21 = pcVar21 + 1;
        }
        pcVar19 = pcVar19 + 0x80;
      } while (_param_2 != 0);
    }
  }
  this->FormalName = (NAME *)pcVar4;
  pRVar5 = (RGE_Communications_Queue *)operator_new(0x118);
  local_4 = 0;
  if (pRVar5 == (RGE_Communications_Queue *)0x0) {
    pRVar5 = (RGE_Communications_Queue *)0x0;
  }
  else {
    pRVar5 = (RGE_Communications_Queue *)
             RGE_Communications_Queue::RGE_Communications_Queue(pRVar5,0x1f5);
  }
  local_4 = 0xffffffff;
  this->InQ = pRVar5;
  puVar6 = (undefined4 *)operator_new(0x6dd4);
  local_4 = 1;
  if (puVar6 == (undefined4 *)0x0) {
    pRVar7 = (RESENDER *)0x0;
  }
  else {
    pRVar7 = (RESENDER *)(puVar6 + 1);
    *puVar6 = 0x1f6;
    _eh_vector_constructor_iterator_(pRVar7,0x38,0x1f6,RESENDER::RESENDER,RESENDER::~RESENDER);
  }
  local_4 = 0xffffffff;
  this->Resend = pRVar7;
  puVar6 = (undefined4 *)operator_new(0x2f14);
  local_4 = 2;
  if (puVar6 == (undefined4 *)0x0) {
    pHVar8 = (HOLDER *)0x0;
  }
  else {
    pHVar8 = (HOLDER *)(puVar6 + 1);
    *puVar6 = 0x1f6;
    _eh_vector_constructor_iterator_(pHVar8,0x18,0x1f6,HOLDER::HOLDER,HOLDER::~HOLDER);
  }
  local_4 = 0xffffffff;
  this->OnHold = pHVar8;
  pRVar9 = (RGE_Comm_Error *)operator_new(8);
  local_4 = 3;
  if (pRVar9 == (RGE_Comm_Error *)0x0) {
    pRVar9 = (RGE_Comm_Error *)0x0;
  }
  else {
    pRVar9 = (RGE_Comm_Error *)RGE_Comm_Error::RGE_Comm_Error(pRVar9,param_1);
  }
  local_4 = 0xffffffff;
  this->Err = pRVar9;
  pRVar10 = (RGE_Lobby *)operator_new(0x1c);
  local_4 = 4;
  if (pRVar10 == (RGE_Lobby *)0x0) {
    pRVar10 = (RGE_Lobby *)0x0;
  }
  else {
    pRVar10 = (RGE_Lobby *)RGE_Lobby::RGE_Lobby(pRVar10,param_1);
  }
  local_4 = 0xffffffff;
  this->Lobby = pRVar10;
  pRVar11 = (RGE_Communications_Speed *)operator_new(0x240);
  local_4 = 5;
  if (pRVar11 == (RGE_Communications_Speed *)0x0) {
    pRVar11 = (RGE_Communications_Speed *)0x0;
  }
  else {
    pRVar11 = (RGE_Communications_Speed *)
              RGE_Communications_Speed::RGE_Communications_Speed(pRVar11,this);
  }
  local_4 = 0xffffffff;
  this->Speed = pRVar11;
  pRVar12 = (RGE_Communications_Synchronize *)operator_new(0x7ec);
  local_4 = 6;
  if (pRVar12 == (RGE_Communications_Synchronize *)0x0) {
    pRVar12 = (RGE_Communications_Synchronize *)0x0;
  }
  else {
    pRVar12 = (RGE_Communications_Synchronize *)
              RGE_Communications_Synchronize::RGE_Communications_Synchronize(pRVar12,this);
  }
  local_4 = 0xffffffff;
  this->Sync = pRVar12;
  uVar13 = debug_timeGetTime(s_C__msdev_work_age1_x1_com_hand_h,0x267);
  this->RXPacketLength = 0;
  this->RXPacketLengthHigh = 0;
  this->TXPacketLength = 0;
  this->TXPacketLengthHigh = 0;
  this->lastRXDataRate = 0.0;
  this->lastTXDataRate = 0.0;
  this->HoldCount = 0;
  this->ServiceTimeout = 0;
  this->TXPackets = 0;
  this->RXPackets = 0;
  this->RGE_Guaranteed_Delivery = '\0';
  this->ResendAcknowledgements = 0;
  this->ResentToOther = 0;
  this->DroppedPacketCount = 0;
  this->LobbyLaunched = 0;
  this->GTDSerialNo = 0;
  this->dwStopTime = 0;
  this->OutOfSyncFlag = 0;
  TDebuggingLog::Time(L);
  (this->PlayerOptions).LastSentTime = uVar13;
  uVar15 = 0xffffffff;
  this->AvgTurnTime = 0;
  this->PauseChangePending = 0;
  this->StepMode = 0;
  this->IntentionallyDropPackets = 0;
  pcVar4 = &s__;
  do {
    pcVar19 = pcVar4;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar19 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar19;
  } while (cVar2 != '\0');
  uVar15 = ~uVar15;
  pcVar4 = pcVar19 + -uVar15;
  pcVar19 = this->MyGameTitle;
  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar19 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar19 = pcVar19 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar19 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar19 = pcVar19 + 1;
  }
  uVar15 = 0xffffffff;
  pcVar4 = &s__;
  do {
    pcVar19 = pcVar4;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar19 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar19;
  } while (cVar2 != '\0');
  uVar15 = ~uVar15;
  pcVar4 = pcVar19 + -uVar15;
  pcVar19 = this->MyFriendlyName;
  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar19 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar19 = pcVar19 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar19 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar19 = pcVar19 + 1;
  }
  uVar15 = 0xffffffff;
  pcVar4 = &s__;
  do {
    pcVar19 = pcVar4;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar19 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar19;
  } while (cVar2 != '\0');
  uVar15 = ~uVar15;
  pcVar4 = pcVar19 + -uVar15;
  pcVar19 = this->MyFormalName;
  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar19 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar19 = pcVar19 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar19 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar19 = pcVar19 + 1;
  }
  this->TickStart = 0;
  this->TickCount = 0;
  this->LastTimeoutMessageTime = 0;
  uVar3 = this->MaxGamePlayers;
  (this->PlayerOptions).LowPlayerNumber = 1;
  (this->PlayerOptions).HighPlayerNumber = uVar3;
  (this->PlayerOptions).GameHasStarted = 0;
  (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
  this->MeHost = 0;
  this->HaveHostInit = 0;
  (this->PlayerOptions).CommandTurnIncrement = '\x02';
  this->current_turn = 4;
  (this->PlayerOptions).CurrentTurn = 4;
  (this->PlayerOptions).NeedsToBeSent = '\0';
  this->AcknowledgeAfterMsec = 0x32;
  this->Me = 0;
  this->Multiplayer = 0;
  this->turnstart = 0;
  this->mselapsed = 0;
  TDebuggingLog::Log((TDebuggingLog *)(uint)uVar3,(char *)L,s_Initialize_Player_List);
  uVar15 = 1;
  if (this->MaxGamePlayers != 0) {
    do {
      InitPlayerInformation(this,uVar15,0,&s__,&s__);
      uVar15 = uVar15 + 1;
    } while ((int)uVar15 <= (int)(uint)this->MaxGamePlayers);
  }
  (this->PlayerOptions).NeedsToBeSent = '\0';
  (this->PlayerOptions).LastSentTime = 0;
  ClearAllSerialNumbers(this);
  ClearRXandTX(this);
  puVar22 = this->PlayerStopTurn;
  for (iVar18 = 9; puVar22 = puVar22 + 1, iVar18 != 0; iVar18 = iVar18 + -1) {
    *puVar22 = 0;
  }
  this->Steps = 1;
  ResetLastCommunicationTimes(this);
  this->WaitingForAck = 0;
  if (this->InQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(this->InQ);
  }
  if (this->OutQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(this->OutQ);
  }
  this->ShuttingDown = 0;
  piVar14 = this->Kicked;
  iVar18 = 10;
  do {
    piVar14[-0x4c] = 0;
    *piVar14 = 0;
    piVar14[0xac] = 0;
    piVar14 = piVar14 + 1;
    iVar18 = iVar18 + -1;
  } while (iVar18 != 0);
  (this->PlayerOptions).DataSizeToFollow = 0;
  this->OptionsData = (char *)0x0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TCommunications_Handler
// Address: 004261e0
// [HELPER] s_NO_MSG_Slot__d__Ser__d__Len__d__: "NO MSG Slot#%d  Ser#%d  Len=%d  DEST=%d,%d,%d,%d,%d,%d,%d,%d "
/* public: __thiscall TCommunications_Handler::~TCommunications_Handler(void) */

void __thiscall TCommunications_Handler::~TCommunications_Handler(TCommunications_Handler *this)
{
  RESENDER *pRVar1;
  int iVar2;
  HOLDER *pHVar3;
  RGE_Communications_Queue *this_00;
  RGE_Lobby *this_01;
  RGE_Communications_Speed *this_02;
  RGE_Communications_Synchronize *this_03;
  RGE_Comm_Error *this_04;
  int iVar4;
  uint uVar5;
  
  DestroyMultiplayerGame(this);
  CloseSession(this);
  ReleaseComm(this);
  FreeOptions(this);
  operator_delete(this->FriendlyName);
  operator_delete(this->FormalName);
  iVar4 = 0;
  uVar5 = 0;
  do {
    pRVar1 = this->Resend;
    iVar2 = *(int *)((int)pRVar1->DestMap + (uVar5 - 0xc));
    if (iVar2 != 0) {
      TDebuggingLog::Log(L,(char *)L,s_NO_MSG_Slot__d__Ser__d__Len__d__,iVar4,iVar2,
                         *(undefined4 *)((int)pRVar1->DestMap + (uVar5 - 4)),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 4),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 8),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 0xc),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 0x10),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 0x14),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 0x18),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 0x1c),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar5 + 0x20));
    }
    uVar5 = uVar5 + 0x38;
    iVar4 = iVar4 + 1;
  } while (uVar5 < 0x6d99);
  pRVar1 = this->Resend;
  if (pRVar1 != (RESENDER *)0x0) {
    _eh_vector_destructor_iterator_(pRVar1,0x38,pRVar1[-1].DestMap[9],RESENDER::~RESENDER);
    operator_delete(pRVar1[-1].DestMap + 9);
  }
  pHVar3 = this->OnHold;
  if (pHVar3 != (HOLDER *)0x0) {
    _eh_vector_destructor_iterator_(pHVar3,0x18,pHVar3[-1].fromPlayer,HOLDER::~HOLDER);
    operator_delete(&pHVar3[-1].fromPlayer);
  }
  this_00 = this->InQ;
  if (this_00 != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::~RGE_Communications_Queue(this_00);
    operator_delete(this_00);
  }
  this_01 = this->Lobby;
  if (this_01 != (RGE_Lobby *)0x0) {
    RGE_Lobby::~RGE_Lobby(this_01);
    operator_delete(this_01);
  }
  this_02 = this->Speed;
  if (this_02 != (RGE_Communications_Speed *)0x0) {
    RGE_Communications_Speed::~RGE_Communications_Speed(this_02);
    operator_delete(this_02);
  }
  this_03 = this->Sync;
  if (this_03 != (RGE_Communications_Synchronize *)0x0) {
    RGE_Communications_Synchronize::~RGE_Communications_Synchronize(this_03);
    operator_delete(this_03);
  }
  this_04 = this->Err;
  if (this_04 != (RGE_Comm_Error *)0x0) {
    RGE_Comm_Error::~RGE_Comm_Error(this_04);
    operator_delete(this_04);
  }
  return;
}

// --------------------------------------------------

// Function: KillAnyMissingPlayers
// Address: 00426350
// [HELPER] s___: "]\n"
/* WARNING: Variable defined which should be unmapped: dwSize */
/* protected: void __thiscall TCommunications_Handler::KillAnyMissingPlayers(void) */

void __thiscall TCommunications_Handler::KillAnyMissingPlayers(TCommunications_Handler *this)
{
  int iVar1;
  void *pvVar2;
  uint unaff_EBP;
  ulong *puVar3;
  uint uVar4;
  ulong dwSize;
  long hr;
  MSGFORMAT_KILL_PLAYER kp;
  
  uVar4 = 1;
  if (this->MaxGamePlayers != 0) {
    puVar3 = (this->PlayerOptions).dcoID;
    do {
      puVar3 = puVar3 + 1;
      iVar1 = IsPlayerHuman(this,uVar4);
      if (iVar1 != 0) {
        hr = 0;
        (**(code **)(*DAT_0062c5ec + 0x54))(DAT_0062c5ec,*puVar3,0,&hr);
        pvVar2 = operator_new(unaff_EBP);
        kp.PlayerNo = (**(code **)(*DAT_0062c5ec + 0x54))
                                (DAT_0062c5ec,*puVar3,pvVar2,&stack0xffffffdc);
        operator_delete(pvVar2);
        if (kp.PlayerNo != 0) {
          kp.CurrentTurn = *puVar3;
          kp.dcoID = uVar4;
          TDebuggingLog::Log((TDebuggingLog *)this->current_turn,(char *)L,s___>TX_KP___d___d_,uVar4
                             ,0xc);
          CommOut(this,0,'K',&kp.dcoID,0xc,'\0');
          if (puVar3[-0x6a] == 0) {
            DropDeadPlayer(this,uVar4,*puVar3);
          }
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= this->MaxGamePlayers);
  }
  return;
}

// --------------------------------------------------

// Function: AddCommand
// Address: 00426470
/* protected: int __thiscall TCommunications_Handler::AddCommand(unsigned long,void *,unsigned
   long,int,unsigned char,int) */

int __thiscall
TCommunications_Handler::AddCommand
          (TCommunications_Handler *this,ulong param_1,void *param_2,ulong param_3,int param_4,
          uchar param_5,int param_6)
{
  int iVar1;
  
  iVar1 = RGE_Communications_Queue::AddItem
                    (this->InQ,param_1,param_2,param_3,param_4,param_5,param_6);
  return iVar1;
}

// --------------------------------------------------

// Function: get_command
// Address: 004264d0
/* public: void * __thiscall TCommunications_Handler::get_command(void) */

void * __thiscall TCommunications_Handler::get_command(TCommunications_Handler *this)
{
  void *pvVar1;
  
  if (this->Multiplayer == 0) {
    pvVar1 = RGE_Communications_Queue::GetNextItemSingle(this->InQ);
    return pvVar1;
  }
  if ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
    pvVar1 = RGE_Communications_Queue::GetNextItemSingle(this->InQ);
    return pvVar1;
  }
  pvVar1 = RGE_Communications_Queue::GetNextItemOrdered(this->InQ,this->current_turn);
  return pvVar1;
}

// --------------------------------------------------

// Function: new_command
// Address: 00426510
/* public: unsigned char __thiscall TCommunications_Handler::new_command(void *,int) */

uchar __thiscall
TCommunications_Handler::new_command(TCommunications_Handler *this,void *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = NewCommand(this,param_1,param_2,0);
  return (uchar)iVar1;
}

// --------------------------------------------------

// Function: NewCommand
// Address: 00426530
// [HELPER] s_NewCmnd: "NewCmnd"
// [HELPER] s___: "]\n"
/* public: int __thiscall TCommunications_Handler::NewCommand(void *,int,int) */

int __thiscall
TCommunications_Handler::NewCommand
          (TCommunications_Handler *this,void *param_1,int param_2,int param_3)
{
  byte bVar1;
  ulong uVar2;
  uchar uVar3;
  long lVar4;
  
  if (this->Multiplayer != 0) {
                    /* WARNING: Load size is inaccurate */
    TDebuggingLog::Log(L,(char *)L,s___>TX_CMD___d__Cmd__d_,param_2,(uint)*param_1);
    lVar4 = CommOut(this,0,'>',param_1,param_2,'\0');
    RGE_Comm_Error::ShowReturn(this->Err,lVar4,s_NewCmnd);
    return 1;
  }
  uVar2 = this->current_turn;
  bVar1 = (this->PlayerOptions).CommandTurnIncrement;
  uVar3 = RGE_Communications_Queue::GetNextSequence(this->InQ,uVar2);
  AddCommand(this,bVar1 + uVar2,param_1,param_2,this->Me,uVar3,param_3);
  return 1;
}

// --------------------------------------------------

// Function: LastWorldRandom
// Address: 00426630
/* public: void __thiscall TCommunications_Handler::LastWorldRandom(int) */

void __thiscall TCommunications_Handler::LastWorldRandom(TCommunications_Handler *this,int param_1)
{
  RGE_Communications_Synchronize::SetLastWorldRandom(this->Sync,param_1);
  return;
}

// --------------------------------------------------

// Function: DoCycle
// Address: 00426650
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_I_Dropped_myself_: "I Dropped myself."
// [HELPER] s_Initialize_Player_List: "Initialize Player List"
// [HELPER] s_Player__d_Turn__d__timeout____d_: "Player %d Turn#%d  timeout = %d "
// [HELPER] s_Player_timed_out_with__d_msec_el: "Player timed out with %d msec elapsed"
// [HELPER] s_Recommend_player___d__drop_: "Recommend player '%d' drop."
// [HELPER] s__: "}"
// [HELPER] s___: "]\n"
// [HELPER] s____Timeout_host__turn__d_PlayerT: "+++Timeout host, turn=%d PlayerTimeout=%d"
// [HELPER] s____Timeout_player__turn__d_Playe: "+++Timeout player, turn=%d PlayerTimeout=%d"
// [HELPER] s____Timeout_pregrame__turn__d_Pla: "+++Timeout pregrame, turn=%d PlayerTimeout=%d"
// [HELPER] s_____Starting_Turn__d__WT__d__Fr_: "....Starting Turn#%d, WT=%d, Fr=%d, Gr=%d"
/* WARNING: Variable defined which should be unmapped: Now */
/* public: int __thiscall TCommunications_Handler::DoCycle(unsigned long) */

int __thiscall TCommunications_Handler::DoCycle(TCommunications_Handler *this,ulong param_1)
{
  byte bVar1;
  COMMSTATES CVar2;
  bool bVar3;
  ulong uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *pTVar9;
  TDebuggingLog *this_05;
  int *piVar10;
  ulong *puVar11;
  uint uVar12;
  ulong Now;
  int numPlayers;
  int selfTimedOutCount;
  ulong LastAnyPlayerMessage;
  uint G;
  uint F;
  TDebuggingLog *local_78;
  undefined1 local_74 [4];
  int local_70;
  uchar local_6c;
  uchar uStack_6b;
  char msg_str [100];
  
  if (this->Multiplayer == 0) {
    return -(uint)((this->PlayerOptions).ProgramState != COMM_STATE_PAUSE);
  }
  if ((uint)this->MaxGamePlayers < this->Me) {
    return 0;
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x20d);
  if (4999 < uVar4 - DAT_0062cf10) {
    pcVar5 = GetCommInfo(this,'\x06');
    TDebuggingLog::Log(this_00,(char *)L,pcVar5);
    pcVar5 = GetCommInfo(this,'\x05');
    TDebuggingLog::Log(this_01,(char *)L,pcVar5);
    pcVar5 = GetCommInfo(this,'\x04');
    TDebuggingLog::Log(L,(char *)L,pcVar5);
    pcVar5 = GetCommInfo(this,'\x03');
    TDebuggingLog::Log(this_02,(char *)L,pcVar5);
    pcVar5 = GetCommInfo(this,'\x02');
    TDebuggingLog::Log(this_03,(char *)L,pcVar5);
    pcVar5 = GetCommInfo(this,'\x01');
    TDebuggingLog::Log(L,(char *)L,pcVar5);
    DAT_0062cf10 = uVar4;
  }
  ReceiveGameMessages(this);
  this->LastPlayerCommunication[this->Me] = uVar4;
  bVar1 = (this->PlayerOptions).CommandTurnIncrement;
  uVar4 = this->current_turn;
  if (((this->Multiplayer != 0) && ((this->PlayerOptions).ProgramState != COMM_STATE_JOINNOW)) &&
     (this->LastTurnAck[this->Me] != uVar4)) {
    this->LastTurnAck[this->Me] = uVar4;
    if (6 < this->current_turn) {
      local_6c = RGE_Communications_Speed::GetHighLatencyCenti(this->Speed);
      uVar6 = RGE_Communications_Speed::GetAvgFrameRate(this->Speed);
      uStack_6b = (uchar)uVar6;
      RGE_Communications_Speed::SetPlayerTurnSpeed(this->Speed,this->Me,uStack_6b,local_6c);
    }
    `protected:_long___thiscall_TCommunications_Handler::SendAllDoneMsg(unsigned_long)'::__l4::
    LastSentTime = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbf9);
    local_74[0] = 0x44;
    local_70 = bVar1 + uVar4;
    TDebuggingLog::Log(this_04,(char *)L,s___>TX_DONE___d_,0xc);
    CommOut(this,0,'D',local_74,0xc,'\0');
  }
  if (this->StepMode != 0) {
    iVar7 = this->Steps;
    if (iVar7 == 0) {
      return iVar7;
    }
    this->Steps = iVar7 + -1;
  }
  RGE_Communications_Synchronize::DoChecksum(this->Sync,this->current_turn);
  if ((this->OutOfSyncFlag == 1) && (this->dwStopTime <= param_1)) {
    NotifyWindowParam(this,COMM_SYNC_ERROR,this->dwStopTime);
    return 0;
  }
  uVar6 = RGE_Communications_Speed::BufferFramesRemaining(this->Speed);
  if ((uVar6 != 0) && (6 < this->current_turn)) {
    uVar6 = RGE_Communications_Speed::BufferTimeToUse(this->Speed,this->current_turn);
    return uVar6;
  }
  G = 0;
  iVar7 = AllPlayersAcknowledged(this);
  CVar2 = (this->PlayerOptions).ProgramState;
  if (iVar7 != 0) {
    if (CVar2 != COMM_STATE_RUNNING) {
      return 0;
    }
    RGE_Communications_Speed::ReloadBufferFrames(this->Speed);
    local_78 = (TDebuggingLog *)0x0;
    F = 0;
    if (this->MeHost != 0) {
      RGE_Communications_Speed::AnalyzeGameSpeed(this->Speed,(uint *)&local_78,&F,1);
    }
    uVar4 = this->current_turn + 1;
    this->current_turn = uVar4;
    TDebuggingLog::Log(local_78,(char *)L,s_____Starting_Turn__d__WT__d__Fr_,uVar4,param_1,local_78,
                       F);
    CheckPlayerStopTurn(this,this->current_turn);
    uVar6 = RGE_Communications_Speed::GetBufferGranularityAdjusted(this->Speed);
    return uVar6;
  }
  if ((int)CVar2 < 5) {
    return 0;
  }
  RGE_Communications_Speed::WaitingOnAcknowledgement(this->Speed);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x259);
  uVar12 = 1;
  LastAnyPlayerMessage = 0;
  selfTimedOutCount = 0;
  iVar7 = 0;
  pTVar9 = (TDebuggingLog *)0x0;
  uVar6 = 0;
  if (this->MaxGamePlayers != 0) {
    puVar11 = this->LastPlayerCommunication;
    do {
      puVar11 = puVar11 + 1;
      iVar7 = IsPlayerHuman(this,uVar12);
      if ((iVar7 != 0) && (uVar12 != this->Me)) {
        uVar6 = *puVar11;
        selfTimedOutCount = selfTimedOutCount + 1;
        if (G <= uVar6) {
          G = uVar6;
        }
        uVar6 = uVar4 - uVar6;
        if (60000 < uVar6) {
          LastAnyPlayerMessage = LastAnyPlayerMessage + 1;
        }
        if ((25000 < uVar6) && (25000 < uVar4 - puVar11[10])) {
          puVar11[10] = uVar4;
          NotifyWindowParam(this,COMM_PLAYER_NOT_RESPONDING,uVar12);
        }
        pTVar9 = (TDebuggingLog *)this->current_turn;
        bVar3 = false;
        if ((pTVar9 < (TDebuggingLog *)0x8) && (98000 < uVar6)) {
          TDebuggingLog::Log(pTVar9,(char *)L,s____Timeout_pregrame__turn__d_Pla,pTVar9,uVar6);
          bVar3 = true;
        }
        pTVar9 = (TDebuggingLog *)this->current_turn;
        if ((((TDebuggingLog *)&DAT_00000007 < pTVar9) && (0x1da9c < uVar6)) && (this->MeHost != 0))
{
          TDebuggingLog::Log(pTVar9,(char *)L,s____Timeout_host__turn__d_PlayerT,pTVar9,uVar6);
          bVar3 = true;
        }
        pTVar9 = (TDebuggingLog *)this->current_turn;
        if (((TDebuggingLog *)&DAT_00000007 < pTVar9) && (0x1d6b4 < uVar6)) {
          TDebuggingLog::Log(L,(char *)L,s____Timeout_player__turn__d_Playe,pTVar9,uVar6);
          bVar3 = true;
          pTVar9 = extraout_ECX;
        }
        if (bVar3) {
          TDebuggingLog::Log(pTVar9,(char *)L,s_Player_timed_out_with__d_msec_el,uVar6);
          TDebuggingLog::Log(this_05,(char *)L,s_Recommend_player___d__drop_,uVar12);
          if (this->MeHost != 0) {
            TDebuggingLog::Log((TDebuggingLog *)this->current_turn,(char *)L,
                               s_Player__d_Turn__d__timeout____d_,uVar12,
                               (TDebuggingLog *)this->current_turn,uVar6);
                    /* language.dll match for 0x4ba: "Player '%s' (%d) is not responding..." */
            (**(code **)(rge_base_game->_padding_ + 0x20))(0x4ba,msg_str + 4,100);
            pcVar5 = this->TBuff;
            uVar6 = uVar12;
            pcVar8 = GetPlayerName(this,uVar12);
            sprintf(pcVar5,msg_str + 4,pcVar8,uVar6);
            if (6 < this->current_turn) {
              SendChatMsgAll(this,pcVar5);
            }
            TDebuggingLog::Log(L,(char *)L,pcVar5);
            puVar11[0x56] = 1;
            Kick(this,uVar12);
          }
          *puVar11 = uVar4;
          puVar11[0x14] = uVar4;
        }
      }
      uVar12 = uVar12 + 1;
      iVar7 = selfTimedOutCount;
      pTVar9 = (TDebuggingLog *)LastAnyPlayerMessage;
      uVar6 = G;
    } while (uVar12 <= this->MaxGamePlayers);
  }
  if (iVar7 + 1 == 3) {
    if ((int)pTVar9 < 2) goto LAB_00426c46;
  }
  else if ((int)pTVar9 < (iVar7 + 1) / 2) {
LAB_00426c46:
    uVar12 = this->LastTimeoutMessageTime;
    if (this->LastTimeoutMessageTime < uVar6) {
      uVar12 = uVar6;
    }
    if (25000 < uVar4 - uVar12) {
      CheckPingTime(this,1);
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x2df);
      this->LastTimeoutMessageTime = uVar4;
    }
    RGE_Communications_Speed::Skip(this->Speed);
    return 0;
  }
  TDebuggingLog::Log(pTVar9,(char *)L,s_I_Dropped_myself_);
  NotifyWindowParam(this,COMM_PLAYER_DROPPED,this->Me);
  uVar12 = 1;
  uVar6 = 1;
  if (this->MaxGamePlayers != 0) {
    piVar10 = this->WasKicked;
    do {
      piVar10 = piVar10 + 1;
      *piVar10 = 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 <= this->MaxGamePlayers);
  }
  TRIBE_World::send_zone_score_info((TRIBE_World *)rge_base_game->world);
  TDebuggingLog::Log(L,(char *)L,s_Initialize_Player_List);
  if (this->MaxGamePlayers != 0) {
    do {
      InitPlayerInformation(this,uVar12,0,&s__,&s__);
      uVar12 = uVar12 + 1;
    } while ((int)uVar12 <= (int)(uint)this->MaxGamePlayers);
  }
  (this->PlayerOptions).NeedsToBeSent = '\0';
  (this->PlayerOptions).LastSentTime = 0;
  UpdatePlayers(this);
  return 0;
}

// --------------------------------------------------

// Function: HasKicked
// Address: 00426d40
/* public: int __thiscall TCommunications_Handler::HasKicked(unsigned int) */

int __thiscall TCommunications_Handler::HasKicked(TCommunications_Handler *this,uint param_1)
{
  return this->Kicked[param_1];
}

// --------------------------------------------------

// Function: SendPlayerName
// Address: 00426d50
// [HELPER] s_Send_Player_Name: "Send Player Name"
/* WARNING: Variable defined which should be unmapped: dpnSetName */
/* protected: long __thiscall TCommunications_Handler::SendPlayerName(void) */

long __thiscall TCommunications_Handler::SendPlayerName(TCommunications_Handler *this)
{
  long lVar1;
  DPNAME dpnSetName;
  
  dpnSetName.field2_0x8.lpszShortName = (ushort *)0x0;
  dpnSetName.field3_0xc.lpszLongName = (ushort *)this->MyFriendlyName;
  dpnSetName.dwFlags = 0x10;
  lVar1 = (**(code **)(*DAT_0062c5ec + 0x78))(DAT_0062c5ec,DAT_0062cf04,&dpnSetName.dwFlags,2);
  RGE_Comm_Error::ShowReturn(this->Err,lVar1,s_Send_Player_Name);
  return lVar1;
}

// --------------------------------------------------

// Function: LogRXMsg
// Address: 00426dc0
// [HELPER] s_GTD__RX_Ser__d_From_P__d_T__ld_T: "GTD: RX Ser#%d From P#%d T#%ld ToExecT#%d Cmd=%d '%c' Seq=%d"
/* protected: void __thiscall TCommunications_Handler::LogRXMsg(unsigned int,unsigned int,unsigned
   long,unsigned char,unsigned char) */

void __thiscall
TCommunications_Handler::LogRXMsg
          (TCommunications_Handler *this,uint param_1,uint param_2,ulong param_3,uchar param_4,
          uchar param_5)
{
  if (this->RGE_Guaranteed_Delivery != '\0') {
    TDebuggingLog::Log(L,(char *)L,s_GTD__RX_Ser__d_From_P__d_T__ld_T,param_1,param_2,
                       this->current_turn,param_3,param_4,param_4,param_5);
  }
  return;
}

// --------------------------------------------------

// Function: ReceiveGameMessages
// Address: 00426e10
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_MsgWait: "MsgWait"
// [HELPER] s_TX___ld__RX___ld__elapsed___ld__: "TX: %ld  RX: %ld  elapsed: %ld  totTX: %ld  totRX: %ld"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TCommunications_Handler::ReceiveGameMessages(void) */

void __thiscall TCommunications_Handler::ReceiveGameMessages(TCommunications_Handler *this)
{
  ulong uVar1;
  int iVar2;
  TDebuggingLog *this_00;
  uint uVar3;
  uint local_8 [2];
  
  if (this->Multiplayer == 0) {
    return;
  }
  if ((DAT_0062c5d0 & 1) == 0) {
    DAT_0062c5d0 = DAT_0062c5d0 | 1;
    DAT_0062cef0 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x396);
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x397);
  uVar3 = uVar1 - DAT_0062cef0;
  if (1000 < uVar3) {
    this_00 = (TDebuggingLog *)(this->TXPacketLength - DAT_0062cf18);
    TDebuggingLog::Log(this_00,(char *)L,s_TX___ld__RX___ld__elapsed___ld__,this_00,
                       this->RXPacketLength - DAT_0062cf14,uVar3,this->TXPacketLength,
                       this->RXPacketLength);
    local_8[1] = 0;
    this->lastTXDataRate =
         ((float)(this->TXPacketLength - DAT_0062cf18) * ram0x0056f254) / (float)uVar3;
    local_8[0] = this->RXPacketLength - DAT_0062cf14;
    this->lastRXDataRate = ((float)local_8[0] * ram0x0056f254) / (float)uVar3;
    DAT_0062cf18 = this->TXPacketLength;
    DAT_0062cf14 = this->RXPacketLength;
    DAT_0062cef0 = uVar1;
  }
  if (this->RGE_Guaranteed_Delivery != '\0') {
    ExecuteIncoming(this);
  }
  if (DAT_0062cf04 == 0) {
LAB_00426f74:
    GetDPLAYMessages(this);
    if (this->RGE_Guaranteed_Delivery == '\0') goto LAB_00426f99;
    ExecuteIncoming(this);
  }
  else {
    local_8[0] = 0;
    iVar2 = (**(code **)(*DAT_0062c5ec + 0x44))(DAT_0062c5ec,DAT_0062cf04,local_8);
    if (iVar2 == 0) {
      if (local_8[0] != 0) goto LAB_00426f74;
    }
    else {
      RGE_Comm_Error::ShowReturn(this->Err,iVar2,s_MsgWait);
    }
  }
  if (this->RGE_Guaranteed_Delivery != '\0') {
    SendStoredMessages(this);
  }
LAB_00426f99:
  CheckPingTime(this,0);
  return;
}

// --------------------------------------------------

// Function: ShutdownGameMessages
// Address: 00426fb0
/* public: void __thiscall TCommunications_Handler::ShutdownGameMessages(void) */

void __thiscall TCommunications_Handler::ShutdownGameMessages(TCommunications_Handler *this)
{
  this->ShuttingDown = 1;
  ReceiveGameMessages(this);
  return;
}

// --------------------------------------------------

// Function: GetDPLAYMessages
// Address: 00426fc0
// [HELPER] s_COMM__RX_P__d_ID__ld__siz__db___: "COMM: RX P#%d ID(%ld) siz=%db   MSG=%d '%c'  timeGetTime=%d"
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Rcv_MSG: "Rcv MSG"
// [HELPER] s_True_overflow__d_requested___Max: "True overflow %d requested.  Max = %d"
// [HELPER] s___: "]\n"
// [HELPER] s_____Receive_Peek_slow____u_msec: "!!! Receive Peek slow - %u msec"
/* WARNING: Variable defined which should be unmapped: dwSize */
/* public: void __thiscall TCommunications_Handler::GetDPLAYMessages(void) */

void __thiscall TCommunications_Handler::GetDPLAYMessages(TCommunications_Handler *this)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  uint uVar7;
  ulong *puVar8;
  ulong unaff_EBX;
  ulong unaff_EBP;
  TDebuggingLog *unaff_ESI;
  undefined4 uVar9;
  int *piStack_34;
  ulong *puVar10;
  ulong dwSize;
  ulong dcoFromID;
  ulong dcoReceiveID;
  ulong dwCount;
  ulong dwPreSize;
  ulong loopStartTime;
  ulong local_4;
  
  dcoReceiveID = 0;
  dwCount = 0;
  if (DAT_0062c5ec == (int *)0x0) {
    return;
  }
  loopStartTime = 4000;
  dcoFromID = 4000;
  pcVar1 = this->InCommBuff;
  piStack_34 = (int *)0x426fff;
  dwSize = unaff_EBX;
  local_4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x3d4);
  puVar10 = &dwPreSize;
  piStack_34 = DAT_0062c5ec;
  dwPreSize = 0;
  iVar3 = (**(code **)(*DAT_0062c5ec + 0x44))();
  if ((iVar3 == 0) && (10 < dcoFromID)) {
    TDebuggingLog::Log(this_00,(char *)L);
  }
  do {
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x3e1);
    uVar9 = 0;
    iVar3 = (**(code **)(*DAT_0062c5ec + 100))(DAT_0062c5ec,&stack0xffffffe0,&dwSize,8);
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x3ec);
    if (0x32 < uVar5 - uVar4) {
      TDebuggingLog::Log(this_01,(char *)L,s_____Receive_Peek_slow____u_msec,uVar5 - uVar4);
    }
    if ((iVar3 == 0) && ((ulong *)0xf9f < puVar10)) {
      TDebuggingLog::Log(L,(char *)L,s_True_overflow__d_requested___Max,uVar9,4000);
      return;
    }
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x403);
    iVar3 = (**(code **)(*DAT_0062c5ec + 100))
                      (DAT_0062c5ec,&stack0xffffffc8,&piStack_34,1,pcVar1,&stack0xffffffc4);
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x40c);
    if (0x32 < uVar5 - uVar4) {
      TDebuggingLog::Log(this_02,(char *)L);
    }
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x417);
    if (500 < uVar4 - dwCount) {
      debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x419);
      TDebuggingLog::Log(L,(char *)L);
    }
    if (iVar3 == -0x7788ff42) {
      return;
    }
    if (unaff_ESI == (TDebuggingLog *)0x0) {
      return;
    }
    if (iVar3 != 0) {
      RGE_Comm_Error::ShowReturn(this->Err,iVar3,s_Rcv_MSG);
      return;
    }
    if (unaff_EBP != 0) {
      uVar6 = (uint)(this->PlayerOptions).LowPlayerNumber;
      uVar7 = (uint)(this->PlayerOptions).HighPlayerNumber;
      if (uVar6 <= uVar7) {
        puVar8 = (this->PlayerOptions).dcoID + uVar6;
        do {
          if (*puVar8 == unaff_EBP) goto LAB_004271c1;
          uVar6 = uVar6 + 1;
          puVar8 = puVar8 + 1;
        } while ((int)uVar6 <= (int)uVar7);
      }
    }
    uVar6 = 0;
LAB_004271c1:
    TDebuggingLog::Log((TDebuggingLog *)(int)*pcVar1,(char *)L,s___>RX___d__c__d___u_,uVar6,
                       (TDebuggingLog *)(int)*pcVar1);
    if (unaff_EBP != 0) {
      uVar6 = (uint)(this->PlayerOptions).LowPlayerNumber;
      uVar7 = (uint)(this->PlayerOptions).HighPlayerNumber;
      if (uVar6 <= uVar7) {
        puVar8 = (this->PlayerOptions).dcoID + uVar6;
        do {
          if (*puVar8 == unaff_EBP) goto LAB_00427216;
          uVar6 = uVar6 + 1;
          puVar8 = puVar8 + 1;
        } while ((int)uVar6 <= (int)uVar7);
      }
    }
    uVar6 = 0;
LAB_00427216:
    cVar2 = *pcVar1;
    debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x435);
    TDebuggingLog::Log(unaff_ESI,(char *)L,s_COMM__RX_P__d_ID__ld__siz__db___,uVar6,unaff_EBP,
                       unaff_ESI,(int)cVar2);
    this->RXPacketLength = (ulong)(unaff_ESI->TBuff + (this->RXPacketLength - 0x28));
    this->RXPackets = this->RXPackets + 1;
    pcVar1[(int)(unaff_ESI->TBuff + -0x28)] = '\0';
    if (unaff_EBP == 0) {
      EvaluateSystemMessage(this,(ulong)unaff_ESI,pcVar1,0,dwSize);
      return;
    }
    PreprocessMessages(this,(ulong)unaff_ESI,pcVar1,unaff_EBP,dwSize,0);
  } while( true );
}

// --------------------------------------------------

// Function: CheckPingTime
// Address: 00427300
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
/* public: void __thiscall TCommunications_Handler::CheckPingTime(int) */

void __thiscall TCommunications_Handler::CheckPingTime(TCommunications_Handler *this,int param_1)
{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  
  if (this->Multiplayer != 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x460);
    uVar4 = 1;
    if (this->MaxGamePlayers != 0) {
      puVar3 = this->LastTXPing;
      do {
        puVar3 = puVar3 + 1;
        iVar2 = IsPlayerHuman(this,uVar4);
        if (((iVar2 != 0) && (uVar4 != this->Me)) && ((8000 < uVar1 - *puVar3 || (param_1 != 0)))) {
          TXPing(this,uVar4);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 <= this->MaxGamePlayers);
    }
  }
  return;
}

// --------------------------------------------------

// Function: TXPing
// Address: 00427390
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s___: "]\n"
/* protected: int __thiscall TCommunications_Handler::TXPing(unsigned int) */

int __thiscall TCommunications_Handler::TXPing(TCommunications_Handler *this,uint param_1)
{
  ulong uVar1;
  long lVar2;
  TDebuggingLog *pTVar3;
  ulong *puVar4;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x470);
  UNK_0062cef4._4_1_ = 0x31;
  pTVar3 = (TDebuggingLog *)this->current_turn;
  UNK_0062cef4._8_4_ = uVar1;
  UNK_0062cef4._12_4_ = pTVar3;
  if (param_1 == 0) {
    pTVar3 = (TDebuggingLog *)0x1;
    if (this->MaxGamePlayers != 0) {
      puVar4 = this->LastTXPing;
      do {
        puVar4 = puVar4 + 1;
        *puVar4 = uVar1;
        pTVar3 = (TDebuggingLog *)((int)&pTVar3->Timestamp + 1);
      } while (pTVar3 <= (TDebuggingLog *)(uint)this->MaxGamePlayers);
    }
    uVar1 = 0;
  }
  else {
    this->LastTXPing[param_1] = uVar1;
    uVar1 = (this->PlayerOptions).dcoID[param_1];
  }
  TDebuggingLog::Log(pTVar3,(char *)L,s___>TX_PING___d___d_,param_1,0xc);
  lVar2 = FastSend(this,uVar1,&UNK_0062cef4.field_0x4,0xc,0,0);
  return (uint)(lVar2 == 0);
}

// --------------------------------------------------

// Function: TXDebugPing
// Address: 00427440
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s___: "]\n"
/* public: int __thiscall TCommunications_Handler::TXDebugPing(void) */

int __thiscall TCommunications_Handler::TXDebugPing(TCommunications_Handler *this)
{
  long lVar1;
  
  UNK_0062c5d1._7_1_ = 0x33;
  UNK_0062c5d1._11_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x496);
  UNK_0062c5d1._15_4_ = this->current_turn;
  TDebuggingLog::Log(L,(char *)L,s___>TX_DEBUG_PING___d___d_,0,0xc);
  lVar1 = FastSend(this,0,&UNK_0062c5d1.field_0x7,0xc,0,0);
  return (uint)(lVar1 == 0);
}

// --------------------------------------------------

// Function: FastSend
// Address: 004274b0
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_FastTX: "FastTX"
// [HELPER] s_FastTX_to_invalidparams_ignored: "FastTX to invalidparams ignored"
// [HELPER] s_No_send_to_self_FastTX: "No send-to-self FastTX"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____FastSend_slow____ld_msec: "!!!FastSend slow - %ld msec"
/* public: long __thiscall TCommunications_Handler::FastSend(unsigned long,void *,unsigned
   long,int,int) */

long __thiscall
TCommunications_Handler::FastSend
          (TCommunications_Handler *this,ulong param_1,void *param_2,ulong param_3,int param_4,
          int param_5)
{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  TDebuggingLog *this_00;
  int iVar5;
  int unaff_ESI;
  uint uVar6;
  
  if (param_1 == DAT_0062cf04) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_No_send_to_self_FastTX);
    return -0x7fffbffb;
  }
  if (DAT_0062cf04 != 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x4ca);
    iVar2 = (**(code **)(*DAT_0062c5ec + 0x68))(DAT_0062c5ec,DAT_0062cf04,param_1,0,param_2,param_3)
    ;
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x4d3);
    if (0x32 < uVar3 - uVar1) {
      TDebuggingLog::Log(this_00,(char *)L,s____FastSend_slow____ld_msec,uVar3 - uVar1);
    }
    if (param_1 == 0) {
      uVar6 = 1;
      iVar5 = 0;
      if (this->MaxGamePlayers != 0) {
        do {
          iVar4 = IsPlayerHuman(this,uVar6);
          if ((iVar4 != 0) && (uVar6 != this->Me)) {
            iVar5 = iVar5 + 1;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 <= this->MaxGamePlayers);
      }
    }
    else {
      iVar5 = 1;
    }
    this->TXPacketLength = this->TXPacketLength + iVar5 * unaff_ESI;
    if (iVar2 != -0x7ff8ffa9) {
      if (iVar2 != 0) {
        RGE_Comm_Error::ShowReturn(this->Err,iVar2,s_FastTX);
      }
      return iVar2;
    }
    TDebuggingLog::Log(L,(char *)L,s_FastTX_to_invalidparams_ignored);
    return -0x7ff8ffa9;
  }
  TDebuggingLog::Log(L,(char *)L,s____BAD_DCOID_0_NO_TX);
  return -0x7fffbffb;
}

// --------------------------------------------------

// Function: PreprocessMessages
// Address: 00427600
// [HELPER] s_Bad_player___for_ID__d: "Bad player # for ID=%d"
// [HELPER] s_CHAT__ChtPregame__d_PgmState__d_: "CHAT: ChtPregame=%d PgmState=%d  Msg=%s"
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Communications_versions_for_HOST: "Communications versions for HOST and player %d match (%d)"
// [HELPER] s_DEBUG: "DEBUG"
// [HELPER] s_DISCARD__ChtPregame__d_PgmState_: "DISCARD: ChtPregame=%d PgmState=%d  Msg=%s"
// [HELPER] s_GTD__RX_Future_Ser__d_rx_from_P_: "GTD: RX Future Ser#%d rx from P#%d"
// [HELPER] s_GTD__RX_Past_Ser__d_rx__Expected: "GTD: RX Past Ser#%d rx. Expected %d from P#%d (acknowledged and discarded)"
// [HELPER] s_KILL_Message_recieved_from__d_to: "KILL Message recieved from %d to kill P#%d "
// [HELPER] s_NOSUCHSERIAL___Setting_P__d_SER_: "NOSUCHSERIAL - Setting P#%d SER from %d to %d"
// [HELPER] s_PLAYER_READY_MSG: "PLAYER READY MSG"
// [HELPER] s_PREPRO_Byte0___c__from__d__d___s: "PREPRO-Byte0='%c' from=%d(%d)  ser#%d  timeGetTime=%d"
// [HELPER] s_Player__d_has_a_different_Commun: "Player %d has a different Communications Version than you.\n This game will fa..."
// [HELPER] s_Rcvd_MAX_TX_report_for_player___: "Rcvd MAX TX report for player #%d, ID=%d from player %d"
// [HELPER] s_Rcvd_Missing_Player_report_for_p: "Rcvd Missing Player report for player #%d, ID=%d from player %d"
// [HELPER] s_Rcvd_Ready__d_from_player__d: "Rcvd Ready=%d from player %d"
// [HELPER] s_Received_debug_ping_from__s____d: "Received debug ping from %s (#%d)"
// [HELPER] s_TX_Debug_Ping: "TX Debug Ping"
// [HELPER] s_TX_Ping: "TX Ping"
// [HELPER] s__PROCESS__Ser__d__CMD__d___c__Se: " PROCESS: Ser#%d  CMD=%d '%c' Seq=%d Turn=%d [ Size=%d dFrom=%d dRxID=%d ] "
// [HELPER] s__P__d_reported_P__d__dco__d__was: " P#%d reported P#%d (dco=%d) was invalid "
// [HELPER] s__Plr_Rdy__P1__d_P2__d_P3__d_P4__: " Plr Rdy: P1=%d P2=%d P3=%d P4=%d P5=%d P6=%d P7=%d P8=%d"
// [HELPER] s___: "]\n"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____First_contact_with_P__d_Next_: "+++First contact with P#%d Next Serial Init to %d"
// [HELPER] s__s___d_Debug_ping___elapsed__d: "%s #%d Debug ping - elapsed=%d"
/* WARNING: Variable defined which should be unmapped: NextSerialNumber */
/* protected: int __thiscall TCommunications_Handler::PreprocessMessages(unsigned long,char
   *,unsigned long,unsigned long,int) */

int __thiscall
TCommunications_Handler::PreprocessMessages
          (TCommunications_Handler *this,ulong param_1,char *param_2,ulong param_3,ulong param_4,
          int param_5)
{
  uint *puVar1;
  uchar uVar2;
  byte bVar3;
  COMMSTATES CVar4;
  undefined4 uVar5;
  ulong uVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  char *pcVar10;
  ulong *puVar11;
  ulong uVar12;
  TCommunications_Handler *this_00;
  TDebuggingLog *extraout_ECX;
  uint *puVar13;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_01;
  TDebuggingLog *extraout_ECX_01;
  TDebuggingLog *pTVar14;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  TDebuggingLog *this_05;
  TDebuggingLog *this_06;
  TDebuggingLog *this_07;
  TDebuggingLog *pTVar15;
  TCommunications_Handler *pTVar16;
  uint NextSerialNumber;
  TDebuggingLog *local_180;
  undefined4 local_17c;
  TDebuggingLog *local_178;
  undefined1 local_174 [4];
  int local_170;
  uchar local_16c;
  uchar uStack_16b;
  char msg [256];
  char msg_str [100];
  
  this_00 = this;
  if (param_3 != 0) {
    pTVar16 = (TCommunications_Handler *)(uint)(this->PlayerOptions).LowPlayerNumber;
    this_00 = (TCommunications_Handler *)(uint)(this->PlayerOptions).HighPlayerNumber;
    if (pTVar16 <= this_00) {
      puVar11 = (this->PlayerOptions).dcoID + (int)pTVar16;
      do {
        if (*puVar11 == param_3) goto LAB_00427642;
        pTVar16 = (TCommunications_Handler *)((int)&pTVar16->OptionsChanged + 1);
        puVar11 = puVar11 + 1;
      } while ((int)pTVar16 <= (int)this_00);
    }
  }
  pTVar16 = (TCommunications_Handler *)0x0;
LAB_00427642:
  if (*param_2 == 'I') {
    UnlinkToLevel(this,SERVICE_AVAILABLE);
    NotifyWindow(this,COMM_UPDATE_PLAYERS);
    NotifyWindow(this,COMM_PLAYER_KICKED);
    return 1;
  }
  if (pTVar16 == (TCommunications_Handler *)0x0) {
    TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s_Bad_player___for_ID__d,param_3);
    local_17c = *(undefined4 *)(param_2 + 8);
    local_180 = (TDebuggingLog *)CONCAT31(local_180._1_3_,0x41);
    if (DAT_0062cf04 != 0) {
      (**(code **)(*DAT_0062c5ec + 0x68))(DAT_0062c5ec,DAT_0062cf04,param_3,0,&local_180,8);
      this->TXPacketLength = this->TXPacketLength + 8;
      return 0;
    }
    TDebuggingLog::Log((TDebuggingLog *)0x0,(char *)L,s____BAD_DCOID_0_NO_TX);
    return 0;
  }
  uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x543);
  this->LastPlayerCommunication[(int)pTVar16] = uVar6;
  if (param_3 != 0) {
    local_180 = (TDebuggingLog *)(uint)(this->PlayerOptions).LowPlayerNumber;
    pTVar14 = (TDebuggingLog *)(uint)(this->PlayerOptions).HighPlayerNumber;
    if (local_180 <= pTVar14) {
      puVar11 = (this->PlayerOptions).dcoID + (int)local_180;
      do {
        if (*puVar11 == param_3) goto LAB_0042775d;
        local_180 = (TDebuggingLog *)((int)&local_180->Timestamp + 1);
        puVar11 = puVar11 + 1;
      } while ((int)local_180 <= (int)pTVar14);
    }
  }
  local_180 = (TDebuggingLog *)0x0;
LAB_0042775d:
  puVar1 = (uint *)(param_2 + 8);
  uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x54d);
  TDebuggingLog::Log(L,(char *)L,s_PREPRO_Byte0___c__from__d__d___s,(int)*param_2,local_180,param_3,
                     *puVar1,uVar6);
  if ((*param_2 == 'K') && ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW)) {
    TDebuggingLog::Log(L,(char *)L,s_KILL_Message_recieved_from__d_to,param_3,
                       *(undefined4 *)(param_2 + 0x10));
    if (*puVar1 == this->PlayerHighSerialNumber[(int)pTVar16] + 1) {
      this->PlayerHighSerialNumber[(int)pTVar16] = *puVar1;
    }
    TDebuggingLog::Log(L,(char *)L,s___>TX_KP_ACK___d__d___d_,pTVar16,*puVar1,8);
    TXAcknowledgeMessage(this,*puVar1,(uint)pTVar16);
    this->PlayerHighSerialNumber[*(int *)(param_2 + 0xc)] = *(int *)(param_2 + 0xc) * 2000;
    if (*(int *)(param_2 + 0x10) == DAT_0062cf04) {
      NotifyWindow(this,COMM_PLAYER_KICKED);
      return 1;
    }
  }
  else {
    pTVar14 = extraout_ECX;
    if (*param_2 == 'C') {
      puVar13 = (uint *)(param_2 + 0xc);
      if (this->RGE_Guaranteed_Delivery == '\0') {
        puVar13 = puVar1;
      }
      bVar3 = (byte)puVar13[4];
      if ((bVar3 != 0) && (CVar4 = (this->PlayerOptions).ProgramState, CVar4 != COMM_STATE_JOINNOW))
{
        TDebuggingLog::Log((TDebuggingLog *)((int)puVar13 + 0x11),(char *)L,
                           s_DISCARD__ChtPregame__d_PgmState_,(uint)bVar3,CVar4,
                           (TDebuggingLog *)((int)puVar13 + 0x11));
        return 0;
      }
      pTVar14 = (TDebuggingLog *)(this->PlayerOptions).ProgramState;
      TDebuggingLog::Log(pTVar14,(char *)L,s_CHAT__ChtPregame__d_PgmState__d_,(uint)bVar3,pTVar14,
                         (int)puVar13 + 0x11);
      pTVar14 = extraout_ECX_00;
    }
    uVar2 = *param_2;
    if (uVar2 == 'A') {
      RXAcknowledgeStoredMessage(this,*(uint *)(param_2 + 4),(uint)pTVar16);
      PurgeAcknowledgedStoredMessages(this);
      return 1;
    }
    if (uVar2 == 'R') {
      TDebuggingLog::Log(L,(char *)L,s_PLAYER_READY_MSG);
      if (this->MeHost != 0) {
        (this->PlayerOptions).PlayerReady[(int)pTVar16] = (uint)(byte)param_2[1];
        TDebuggingLog::Log(L,(char *)L,s_Rcvd_Ready__d_from_player__d,(uint)(byte)param_2[1],pTVar16
                          );
        (this->PlayerOptions).User1[(int)pTVar16] = *(ulong *)(param_2 + 4);
        (this->PlayerOptions).User2[(int)pTVar16] = *puVar1;
        (this->PlayerOptions).User3[(int)pTVar16] = *(ulong *)(param_2 + 0xc);
        (this->PlayerOptions).User4[(int)pTVar16] = *(ulong *)(param_2 + 0x10);
        (this->PlayerOptions).User5[(int)pTVar16] = *(ulong *)(param_2 + 0x14);
        (this->PlayerOptions).User6[(int)pTVar16] = *(ulong *)(param_2 + 0x18);
        (this->PlayerOptions).User7[(int)pTVar16] = *(ulong *)(param_2 + 0x1c);
        iVar7 = IsPlayerHuman(this,(uint)pTVar16);
        if (iVar7 == 0) {
          SetPlayerHumanity(this,(uint)pTVar16,ME_HUMAN);
        }
        if ((TDebuggingLog *)this->CommunicationsVersionCode == *(TDebuggingLog **)(param_2 + 0x20))
{
          TDebuggingLog::Log(*(TDebuggingLog **)(param_2 + 0x20),(char *)L,
                             s_Communications_versions_for_HOST,pTVar16,
                             (TDebuggingLog *)this->CommunicationsVersionCode);
        }
        else {
          NotifyWindowParam(this,COMM_PLAYER_SERVICE_ERROR,(long)pTVar16);
          sprintf(this->TBuff,s_Player__d_has_a_different_Commun,pTVar16);
          TDebuggingLog::Log(L,(char *)L,this->TBuff);
        }
        (this->PlayerOptions).NeedsToBeSent = '\x01';
        SendSharedData(this,0);
        UpdatePlayer(this,(uint)pTVar16,0);
        sprintf(this->TBuff,s__Plr_Rdy__P1__d_P2__d_P3__d_P4__,(this->PlayerOptions).PlayerReady[1],
                (this->PlayerOptions).PlayerReady[2],(this->PlayerOptions).PlayerReady[3],
                (this->PlayerOptions).PlayerReady[4],(this->PlayerOptions).PlayerReady[5],
                (this->PlayerOptions).PlayerReady[6],(this->PlayerOptions).PlayerReady[7],
                (this->PlayerOptions).PlayerReady[8]);
        TDebuggingLog::Log(L,(char *)L,this->TBuff);
        NotifyWindow(this,COMM_UPDATE_PLAYERS);
        return 1;
      }
    }
    else {
      if (uVar2 == '1') {
        uVar6 = this->current_turn;
        pTVar14 = (TDebuggingLog *)this->Multiplayer;
        uVar5 = *(undefined4 *)(param_2 + 4);
        bVar3 = (this->PlayerOptions).CommandTurnIncrement;
        if (((pTVar14 != (TDebuggingLog *)0x0) &&
            ((this->PlayerOptions).ProgramState != COMM_STATE_JOINNOW)) &&
           (pTVar14 = (TDebuggingLog *)(this->LastTurnAck + this->Me),
           this->LastTurnAck[this->Me] != uVar6)) {
          pTVar14->Timestamp = uVar6;
          if (6 < this->current_turn) {
            local_16c = RGE_Communications_Speed::GetHighLatencyCenti(this->Speed);
            uVar8 = RGE_Communications_Speed::GetAvgFrameRate(this->Speed);
            uStack_16b = (uchar)uVar8;
            RGE_Communications_Speed::SetPlayerTurnSpeed(this->Speed,this->Me,uStack_16b,local_16c);
          }
          `protected:_long___thiscall_TCommunications_Handler::SendAllDoneMsg(unsigned_long)'::__l4
          ::LastSentTime = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbf9);
          local_174[0] = 0x44;
          local_170 = bVar3 + uVar6;
          TDebuggingLog::Log(this_01,(char *)L,s___>TX_DONE___d_,0xc);
          CommOut(this,0,'D',local_174,0xc,'\0');
          pTVar14 = extraout_ECX_01;
        }
        local_178 = (TDebuggingLog *)this->current_turn;
        local_180 = (TDebuggingLog *)CONCAT31(local_180._1_3_,0x32);
        local_17c = uVar5;
        TDebuggingLog::Log(pTVar14,(char *)L,s___>TX_PONG___d___d_,pTVar16,0xc);
        lVar9 = FastSend(this,(this->PlayerOptions).dcoID[(int)pTVar16],&local_180,0xc,0,0);
        RGE_Comm_Error::ShowReturn(this->Err,lVar9,s_TX_Ping);
        return 1;
      }
      if (uVar2 == '3') {
        local_17c = *(undefined4 *)(param_2 + 4);
        local_178 = (TDebuggingLog *)this->current_turn;
        local_180 = (TDebuggingLog *)CONCAT31(local_180._1_3_,0x34);
        TDebuggingLog::Log(local_178,(char *)L,s___>TX_DEBUG_PONG___d___d_,pTVar16,0xc);
        lVar9 = FastSend(this,(this->PlayerOptions).dcoID[(int)pTVar16],&local_180,0xc,0,0);
        RGE_Comm_Error::ShowReturn(this->Err,lVar9,s_TX_Debug_Ping);
        pcVar10 = GetPlayerName(this,(uint)pTVar16);
        sprintf(msg + 4,s_Received_debug_ping_from__s____d,pcVar10,pTVar16);
        TDebuggingLog::Log(L,(char *)L,msg + 4);
        TChat::AddChatMsg(this->Chat,s_DEBUG,msg + 4,'\0');
        return 1;
      }
      if (uVar2 == '?') {
        if (this->MeHost != 0) {
          uVar6 = *(ulong *)(param_2 + 4);
          if (uVar6 != 0) {
            pTVar15 = (TDebuggingLog *)(uint)(this->PlayerOptions).LowPlayerNumber;
            pTVar14 = (TDebuggingLog *)(uint)(this->PlayerOptions).HighPlayerNumber;
            if (pTVar15 <= pTVar14) {
              puVar11 = (this->PlayerOptions).dcoID + (int)pTVar15;
              do {
                if (*puVar11 == uVar6) goto LAB_00427cca;
                pTVar15 = (TDebuggingLog *)((int)&pTVar15->Timestamp + 1);
                puVar11 = puVar11 + 1;
              } while ((int)pTVar15 <= (int)pTVar14);
            }
          }
          pTVar15 = (TDebuggingLog *)0x0;
LAB_00427cca:
          if ((this->PlayerOptions).ProgramState != COMM_STATE_JOINNOW) {
            TDebuggingLog::Log(pTVar14,(char *)L,s_Rcvd_MAX_TX_report_for_player___,pTVar15,uVar6,
                               pTVar16);
            Kick(this,(uint)pTVar15);
            return 1;
          }
          sprintf(this->TBuff,s__P__d_reported_P__d__dco__d__was,pTVar16,pTVar15,uVar6);
          TDebuggingLog::Log(this_02,(char *)L,this->TBuff);
          TDebuggingLog::Log(*(TDebuggingLog **)(param_2 + 4),(char *)L,
                             s_Rcvd_Missing_Player_report_for_p,pTVar15,
                             *(TDebuggingLog **)(param_2 + 4),pTVar16);
          (this->PlayerOptions).PlayerReady[(int)pTVar15] = 0;
          (pTVar15[2].Filename + 0x6c)[(int)this] = '\x01';
          (this->PlayerOptions).NeedsToBeSent = '\x01';
          return 1;
        }
      }
      else {
        if (uVar2 == '2') {
          uVar12 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x672);
          iVar7 = *(int *)(param_2 + 4);
          bVar3 = (this->PlayerOptions).CommandTurnIncrement;
          uVar6 = this->current_turn;
          if (((this->Multiplayer != 0) &&
              ((this->PlayerOptions).ProgramState != COMM_STATE_JOINNOW)) &&
             (this->LastTurnAck[this->Me] != uVar6)) {
            this->LastTurnAck[this->Me] = uVar6;
            if (6 < this->current_turn) {
              local_16c = RGE_Communications_Speed::GetHighLatencyCenti(this->Speed);
              uVar8 = RGE_Communications_Speed::GetAvgFrameRate(this->Speed);
              uStack_16b = (uchar)uVar8;
              RGE_Communications_Speed::SetPlayerTurnSpeed
                        (this->Speed,this->Me,uStack_16b,local_16c);
            }
            `protected:_long___thiscall_TCommunications_Handler::SendAllDoneMsg(unsigned_long)'::
            __l4::LastSentTime = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbf9);
            local_174[0] = 0x44;
            local_170 = bVar3 + uVar6;
            TDebuggingLog::Log(this_03,(char *)L,s___>TX_DONE___d_,0xc);
            CommOut(this,0,'D',local_174,0xc,'\0');
          }
          RGE_Communications_Speed::SetActualLatency(this->Speed,(uint)pTVar16,uVar12 - iVar7);
          return 1;
        }
        if (uVar2 == '4') {
          uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x68b);
          iVar7 = uVar6 - *(int *)(param_2 + 4);
          pcVar10 = GetPlayerName(this,(uint)pTVar16);
          sprintf(msg + 4,s__s___d_Debug_ping___elapsed__d,pcVar10,pTVar16,iVar7);
          TDebuggingLog::Log(this_04,(char *)L,msg + 4);
          TChat::AddChatMsg(this->Chat,s_DEBUG,msg + 4,'\0');
          return 1;
        }
        if (uVar2 == 'Y') {
          if ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
            this->PlayerHighSerialNumber[(int)pTVar16] = *(uint *)(param_2 + 4);
            ClearRXForPlayer(this,(uint)pTVar16);
            TDebuggingLog::Log((TDebuggingLog *)this->PlayerHighSerialNumber[(int)pTVar16],(char *)L
                               ,s_NOSUCHSERIAL___Setting_P__d_SER_,pTVar16,
                               (TDebuggingLog *)this->PlayerHighSerialNumber[(int)pTVar16],
                               *(undefined4 *)(param_2 + 4));
            return 1;
          }
        }
        else {
          if (this->RGE_Guaranteed_Delivery == '\0') {
            LogRXMsg(this,*puVar1,(uint)pTVar16,*(ulong *)(param_2 + 4),uVar2,param_2[1]);
            DAT_0062cf20 = param_1 - 8;
            DAT_0062cf1c = puVar1;
          }
          else {
            if (((this->IntentionallyDropPackets != 0) && (6 < this->current_turn)) &&
               (DAT_0062cf24 = DAT_0062cf24 + 1, 8 < DAT_0062cf24)) {
                    /* language.dll match for 0x4bc: "Intentional drop of Ser#%d  Cmd=%d '%c' " */
              (**(code **)(rge_base_game->_padding_ + 0x20))(0x4bc,msg_str + 4,100);
              sprintf(this->TBuff,msg + 0xf8,*puVar1,(int)*param_2,(int)*param_2);
              TDebuggingLog::Log(this_05,(char *)L,this->TBuff);
              DAT_0062cf24 = 0;
              return 1;
            }
            if (*param_2 == 'X') {
              TXResendReply(this,*(uint *)(param_2 + 4),(uint)pTVar16);
              return 1;
            }
            if (this->PlayerHighSerialNumber[(int)pTVar16] == 0) {
              TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,
                                 s____First_contact_with_P__d_Next_,pTVar16,(TDebuggingLog *)*puVar1
                                );
              this->PlayerHighSerialNumber[(int)pTVar16] = *puVar1 - 1;
            }
            pTVar14 = (TDebuggingLog *)*puVar1;
            local_180 = (TDebuggingLog *)(this->PlayerHighSerialNumber[(int)pTVar16] + 1);
            if (pTVar14 < local_180) {
              sprintf(this->TBuff,s_GTD__RX_Past_Ser__d_rx__Expected,pTVar14,local_180,pTVar16);
              TDebuggingLog::Log(this_06,(char *)L,this->TBuff);
              TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,s___>TX_R_ACK___d__d___d_,
                                 pTVar16,(TDebuggingLog *)*puVar1,8);
              TXAcknowledgeMessage(this,*puVar1,(uint)pTVar16);
              return 1;
            }
            if (local_180 < pTVar14) {
              this->DroppedPacketCount = this->DroppedPacketCount + 1;
              sprintf(this->TBuff,s_GTD__RX_Future_Ser__d_rx_from_P_,*puVar1,pTVar16);
              TDebuggingLog::Log(this_07,(char *)L,this->TBuff);
              StoreIncoming(this,*puVar1,param_2,param_1,param_3,param_4);
              TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,s___>TX_F_ACK___d__d___d_,
                                 pTVar16,(TDebuggingLog *)*puVar1,8);
              TXAcknowledgeMessage(this,*puVar1,(uint)pTVar16);
              TXResendRequest(this,(uint)local_180,(uint)pTVar16);
              return 1;
            }
            if (param_5 == 0) {
              TDebuggingLog::Log(pTVar14,(char *)L,s___>TX_N_ACK___d__d___d_,pTVar16,pTVar14,8);
              TXAcknowledgeMessage(this,*puVar1,(uint)pTVar16);
            }
            DAT_0062cf20 = param_1 - 0xc;
            this->PlayerHighSerialNumber[(int)pTVar16] = *puVar1;
            DAT_0062cf1c = (uint *)(param_2 + 0xc);
          }
          TDebuggingLog::Log(L,(char *)L,s__PROCESS__Ser__d__CMD__d___c__Se,*puVar1,
                             (uint)(byte)*param_2,(uint)(byte)*param_2,(uint)(byte)param_2[1],
                             *(undefined4 *)(param_2 + 4),param_1,param_3,param_4);
          if (this->ShuttingDown == 0) {
            EvaluatePlayerMessage
                      (this,param_1,(uint)pTVar16,*(ulong *)(param_2 + 4),*param_2,param_2[1],
                       (char *)DAT_0062cf1c,DAT_0062cf20,param_3,param_4);
          }
        }
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: NotifyWindow
// Address: 00428270
/* public: void __thiscall TCommunications_Handler::NotifyWindow(enum COMMMESSAGES) */

void __thiscall
TCommunications_Handler::NotifyWindow(TCommunications_Handler *this,COMMMESSAGES param_1)
{
  NotifyWindowParam(this,param_1,0);
  return;
}

// --------------------------------------------------

// Function: NotifyWindowParam
// Address: 00428280
// [HELPER] s_COMM__Send_msg_to_window_WM_USER: "COMM: Send msg to window WM_USER  Msg=%d  Param=%d "
/* public: void __thiscall TCommunications_Handler::NotifyWindowParam(enum COMMMESSAGES,long) */

void __thiscall
TCommunications_Handler::NotifyWindowParam
          (TCommunications_Handler *this,COMMMESSAGES param_1,long param_2)
{
  PostMessageA(this->HostHWND,0x400,param_1,param_2);
  TDebuggingLog::Log(L,(char *)L,s_COMM__Send_msg_to_window_WM_USER,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: EvaluatePlayerMessage
// Address: 004282c0
// [HELPER] s_CHAT_RX_from_P__d__d__RXID__d_Ch: "CHAT-RX from P#%d(%d) RXID=%d Chat content='%s'  MsgSize=%d TotalSize=%d preg..."
// [HELPER] s_Host_requested_we_delete_and_rec: "Host requested we delete and recreate our player"
// [HELPER] s_KILL_Message_recieved_from__d_to: "KILL Message recieved from %d to kill P#%d "
// [HELPER] s_Non_host_requested_resume: "Non-host requested resume"
// [HELPER] s_P__d_Requested_pause: "P#%d Requested pause"
// [HELPER] s_Resume_msg_rcvd: "Resume msg rcvd"
// [HELPER] s_Unknown_message____d___c_: "Unknown message : %d '%c'"
// [HELPER] s____REGRESSION_WARNING__Current__: "+++REGRESSION WARNING, Current=%d  ExecuteOnTurn=%d"
/* protected: int __thiscall TCommunications_Handler::EvaluatePlayerMessage(unsigned long,unsigned
   int,unsigned long,unsigned char,unsigned char,char *,unsigned int,unsigned long,unsigned long) */

int __thiscall
TCommunications_Handler::EvaluatePlayerMessage
          (TCommunications_Handler *this,ulong param_1,uint param_2,ulong param_3,uchar param_4,
          uchar param_5,char *param_6,uint param_7,ulong param_8,ulong param_9)
{
  TDebuggingLog *pTVar1;
  ulong uVar2;
  uint uVar3;
  ulong *puVar4;
  uint uVar5;
  
  if (this->Multiplayer == 0) {
    return 0;
  }
  uVar3 = (uint)param_4;
  pTVar1 = (TDebuggingLog *)(uVar3 - 0x2b);
  switch(uVar3) {
  case 0x2b:
    if (this->MeHost != 0) {
      SendPauseGame(this,0);
      TDebuggingLog::Log(L,(char *)L,s_Non_host_requested_resume);
      LocalResumeGame(this,param_2);
      return 1;
    }
    break;
  default:
    TDebuggingLog::Log(pTVar1,(char *)L,s_Unknown_message____d___c_,uVar3,uVar3);
    break;
  case 0x3e:
    AddCommand(this,param_3,param_6,param_1,param_2,param_5,0);
    return 1;
  case 0x43:
    TDebuggingLog::Log((TDebuggingLog *)param_2,(char *)L,s_CHAT_RX_from_P__d__d__RXID__d_Ch,param_2
                       ,param_8,param_9,param_6 + 0x11,*(undefined4 *)(param_6 + 0xc),param_7,
                       (uint)(byte)param_6[0x10]);
    if ((param_6[this->Me + 1] == 'Y') || ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW)
       ) {
      TChat::AddChatMsg(this->Chat,this->FriendlyName[(byte)*param_6].Text,param_6 + 0x11,'\0');
      return 1;
    }
    break;
  case 0x44:
    RGE_Communications_Speed::SetPlayerTurnSpeed(this->Speed,param_2,param_6[9],param_6[8]);
    if (((int)(this->PlayerOptions).ProgramState < 5) || (this->current_turn < 6)) {
      pTVar1 = (TDebuggingLog *)this->current_turn;
      if (*(TDebuggingLog **)(param_6 + 4) < pTVar1) {
        TDebuggingLog::Log(pTVar1,(char *)L,s____REGRESSION_WARNING__Current__,pTVar1,
                           *(TDebuggingLog **)(param_6 + 4));
        return 0;
      }
    }
    uVar3 = *(int *)(param_6 + 4) - (uint)(this->PlayerOptions).CommandTurnIncrement;
    if (uVar3 <= this->LastTurnAck[param_2]) {
      uVar3 = this->LastTurnAck[param_2];
    }
    this->LastTurnAck[param_2] = uVar3;
    return 1;
  case 0x4b:
    TDebuggingLog::Log(*(TDebuggingLog **)param_6,(char *)L,s_KILL_Message_recieved_from__d_to,
                       param_2,*(TDebuggingLog **)param_6);
    uVar2 = *(ulong *)(param_6 + 4);
    if (uVar2 != 0) {
      uVar3 = (uint)(this->PlayerOptions).LowPlayerNumber;
      uVar5 = (uint)(this->PlayerOptions).HighPlayerNumber;
      if (uVar3 <= uVar5) {
        puVar4 = (this->PlayerOptions).dcoID + uVar3;
        do {
          if (*puVar4 == uVar2) goto LAB_004285e0;
          uVar3 = uVar3 + 1;
          puVar4 = puVar4 + 1;
        } while ((int)uVar3 <= (int)uVar5);
      }
    }
    uVar3 = 0;
LAB_004285e0:
    if (uVar3 != 0) {
      if (this->PlayerStopTurn[uVar3] == 0) {
        DropDeadPlayer(this,uVar3,uVar2);
      }
      if (uVar3 == this->Me) {
        NotifyWindow(this,COMM_PLAYER_KICKED);
        return 1;
      }
      if (this->PlayerStopTurn[uVar3] == 0) {
        NotifyWindowParam(this,COMM_OTHER_PLAYER_DROPPED,uVar3);
        return 1;
      }
    }
    break;
  case 0x4d:
    RGE_Communications_Synchronize::Add
              (this->Sync,param_2,*(ulong *)param_6,*(ulong *)(param_6 + 4),*(ulong *)(param_6 + 8),
               *(long *)(param_6 + 0xc),*(long *)(param_6 + 0x10),*(long *)(param_6 + 0x14),
               *(long *)(param_6 + 0x18),*(long *)(param_6 + 0x1c));
    return 1;
  case 0x4e:
    if (this->MeHost == 0) {
      TDebuggingLog::Log(L,(char *)L,s_Host_requested_we_delete_and_rec);
      return 1;
    }
    break;
  case 0x50:
    TDebuggingLog::Log(pTVar1,(char *)L,s_P__d_Requested_pause);
    LocalPauseGame(this,param_2);
    RGE_Communications_Synchronize::LogChecksums(this->Sync,0,0,0,0,0,0,0,0,0);
    return 1;
  case 0x51:
    SetPlayerStopTurn(this,param_2,*(ulong *)param_6);
    return 1;
  case 0x53:
    RGE_Communications_Speed::SetFutureSpeedChange
              (this->Speed,(uint)*(ushort *)param_6,(uint)*(ushort *)(param_6 + 2),param_3);
    return 1;
  case 0x55:
    TDebuggingLog::Log(pTVar1,(char *)L,s_Resume_msg_rcvd);
    LocalResumeGame(this,param_2);
    return 1;
  case 0x57:
    if (this->MeHost != 0) {
      SendPauseGame(this,1);
      LocalPauseGame(this,param_2);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: SetPlayerStopTurn
// Address: 004286f0
/* protected: void __thiscall TCommunications_Handler::SetPlayerStopTurn(unsigned int,unsigned long)
    */

void __thiscall
TCommunications_Handler::SetPlayerStopTurn(TCommunications_Handler *this,uint param_1,ulong param_2)
{
  this->PlayerStopTurn[param_1] = param_2;
  return;
}

// --------------------------------------------------

// Function: CheckPlayerStopTurn
// Address: 00428710
// [HELPER] s_CheckPlayerStopTurn__Drop_player: "CheckPlayerStopTurn: Drop player %d on turn %d"
// [HELPER] s_Resigned: "Resigned"
// [HELPER] s__: "}"
/* WARNING: Variable defined which should be unmapped: StopPending */
/* protected: void __thiscall TCommunications_Handler::CheckPlayerStopTurn(unsigned long) */

void __thiscall
TCommunications_Handler::CheckPlayerStopTurn(TCommunications_Handler *this,ulong param_1)
{
  bool bVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  int StopPending;
  
  bVar1 = false;
  uVar4 = 1;
  if (this->MaxGamePlayers != 0) {
    puVar3 = this->PlayerStopTurn;
    do {
      puVar3 = puVar3 + 1;
      if (*puVar3 != 0) {
        bVar1 = true;
      }
      if (*puVar3 == param_1) {
        TDebuggingLog::Log((TDebuggingLog *)0x1,(char *)L,s_CheckPlayerStopTurn__Drop_player,uVar4,
                           param_1);
        InitPlayerInformation(this,uVar4,0,s_Resigned,&s__);
        SetPlayerHumanity(this,uVar4,ME_ELIMINATED);
        NotifyWindowParam(this,COMM_PLAYER_RESIGNED,uVar4);
        *puVar3 = 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= this->MaxGamePlayers);
  }
  if ((6 < this->current_turn) && (!bVar1)) {
    bVar1 = false;
    uVar4 = 1;
    if (this->MaxGamePlayers != 0) {
      do {
        iVar2 = IsPlayerHuman(this,uVar4);
        if (iVar2 == 0) {
          iVar2 = IsPlayerComputer(this,uVar4);
          if (iVar2 != 0) goto LAB_004287d9;
        }
        else {
LAB_004287d9:
          if (uVar4 != this->Me) {
            bVar1 = true;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 <= this->MaxGamePlayers);
    }
    if (!bVar1) {
      NotifyWindow(this,COMM_NO_OTHER_HUMANS);
    }
  }
  return;
}

// --------------------------------------------------

// Function: ReleaseSettings
// Address: 00428810
/* public: void __thiscall TCommunications_Handler::ReleaseSettings(void) */

void __thiscall TCommunications_Handler::ReleaseSettings(TCommunications_Handler *this)
{
  (this->PlayerOptions).NeedsToBeSent = '\0';
  return;
}

// --------------------------------------------------

// Function: SendSharedData
// Address: 00428820
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_NO_DCOID_FAIL_SEND_PLRDAT: "NO DCOID-FAIL SEND PLRDAT"
// [HELPER] s_Sending_options_data: "Sending options data"
// [HELPER] s_Set_Player_Data: "Set Player Data"
/* public: long __thiscall TCommunications_Handler::SendSharedData(int) */

long __thiscall TCommunications_Handler::SendSharedData(TCommunications_Handler *this,int param_1)
{
  ulong uVar1;
  undefined4 *puVar2;
  long lVar3;
  TDebuggingLog *this_00;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  COMMPLAYEROPTIONS *pCVar8;
  char *pcVar9;
  void *unaff_EDI;
  undefined4 *puVar10;
  char *pcVar11;
  
  if (DAT_0062c5ec == (int *)0x0) {
    return 0;
  }
  if (this->MeHost == 0) {
    return 0;
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x895);
  if (param_1 == 0) {
    if (uVar1 - (this->PlayerOptions).LastSentTime < 2000) {
      return 0;
    }
  }
  else {
    (this->PlayerOptions).NeedsToBeSent = '\x01';
  }
  if ((this->PlayerOptions).NeedsToBeSent == '\0') {
    return 0;
  }
  if (DAT_0062cf04 == 0) {
    TDebuggingLog::Log(L,(char *)L,s_NO_DCOID_FAIL_SEND_PLRDAT);
    return -0x7fffbffb;
  }
  TDebuggingLog::Log(this_00,(char *)L,s_Sending_options_data);
  uVar7 = (this->PlayerOptions).DataSizeToFollow + 0x1d0;
  (this->PlayerOptions).LastSentTime = uVar1;
  puVar2 = (undefined4 *)operator_new(uVar7);
  pCVar8 = &this->PlayerOptions;
  puVar10 = puVar2;
  for (iVar4 = 0x74; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = *(undefined4 *)pCVar8;
    pCVar8 = (COMMPLAYEROPTIONS *)&pCVar8->LastSentTime;
    puVar10 = puVar10 + 1;
  }
  uVar6 = (this->PlayerOptions).DataSizeToFollow;
  pcVar9 = this->OptionsData;
  pcVar11 = (char *)(puVar2 + 0x74);
  for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar11 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar11 = pcVar11 + 1;
  }
  lVar3 = (**(code **)(*DAT_0062c5ec + 0x74))(DAT_0062c5ec,DAT_0062cf04,puVar2,uVar7,2);
  RGE_Comm_Error::ShowReturn(this->Err,lVar3,s_Set_Player_Data);
  operator_delete(unaff_EDI);
  (this->PlayerOptions).NeedsToBeSent = '\0';
  NotifyWindow(this,COMM_SHARED_DATA_SENT);
  uVar7 = 1;
  if (this->MaxGamePlayers != 0) {
    do {
      (this->PlayerOptions).InvalidPlayer[uVar7] = '\0';
      uVar7 = uVar7 + 1;
    } while (uVar7 <= this->MaxGamePlayers);
  }
  return lVar3;
}

// --------------------------------------------------

// Function: TEST
// Address: 004289a0
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Playing_Taunt___d: "Playing Taunt #%d"
/* protected: int __thiscall TCommunications_Handler::TEST(void) */

int __thiscall TCommunications_Handler::TEST(TCommunications_Handler *this)
{
  TTaunt *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ccdb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = (TTaunt *)operator_new(0x198);
  local_4 = 0;
  if (pTVar1 == (TTaunt *)0x0) {
    pTVar1 = (TTaunt *)0x0;
  }
  else {
    pTVar1 = (TTaunt *)TTaunt::TTaunt(pTVar1,sound_driver);
  }
  local_4 = 0xffffffff;
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x8f2);
  TDebuggingLog::Log(L,(char *)L,s_Playing_Taunt___d,(iVar2 * 0xf) / 0x7fff);
  TTaunt::PlayTauntNo(pTVar1,4);
  if (pTVar1 != (TTaunt *)0x0) {
    TTaunt::~TTaunt(pTVar1);
    operator_delete(pTVar1);
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: SetSelfPlayer
// Address: 00428a70
// [HELPER] s_Check_dcoID__d_to_Me__d__: "Check dcoID %d to Me %d ?"
// [HELPER] s_Match____ID_set_: "Match! - ID set."
// [HELPER] s_SET_SELF_failed___We_are_DCOID__: "SET SELF failed.  We are DCOID=%d"
/* protected: void __thiscall TCommunications_Handler::SetSelfPlayer(void) */

void __thiscall TCommunications_Handler::SetSelfPlayer(TCommunications_Handler *this)
{
  ulong *puVar1;
  uint uVar2;
  
  uVar2 = 1;
  if (this->MaxGamePlayers != 0) {
    puVar1 = (this->PlayerOptions).dcoID;
    do {
      puVar1 = puVar1 + 1;
      TDebuggingLog::Log(L,(char *)L,s_Check_dcoID__d_to_Me__d__,*puVar1,DAT_0062cf04);
      if ((TDebuggingLog *)*puVar1 == DAT_0062cf04) {
        TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,s_Match____ID_set_);
        this->Me = uVar2;
        NotifyWindowParam(this,COMM_PLAYER_ID_SET,uVar2);
        return;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 <= this->MaxGamePlayers);
  }
  TDebuggingLog::Log(L,(char *)L,s_SET_SELF_failed___We_are_DCOID__,DAT_0062cf04);
  return;
}

// --------------------------------------------------

// Function: DropDeadPlayer
// Address: 00428b10
// [HELPER] s_Defeated: "Defeated"
// [HELPER] s_Drop_dead_called_P__d_and_DPID__: "Drop dead called P#%d and DPID=%d"
// [HELPER] s_Dropped: "Dropped"
// [HELPER] s_I_Dropped_: "I Dropped."
// [HELPER] s_Initialize_Player_List: "Initialize Player List"
// [HELPER] s_No_Other_Information: "No Other Information"
// [HELPER] s_Player_dropped_before_game_start: "Player dropped before game start"
// [HELPER] s_Player_number_invalid___Returnin: "Player number invalid.  Returning."
// [HELPER] s_Player_quit_the_game_: "Player quit the game."
// [HELPER] s_Player_was_defeated__was_compute: "Player was defeated, was computer, or is invalid."
// [HELPER] s__: "}"
/* WARNING: Variable defined which should be unmapped: msg_str */
/* public: void __thiscall TCommunications_Handler::DropDeadPlayer(unsigned int,unsigned long) */

void __thiscall
TCommunications_Handler::DropDeadPlayer(TCommunications_Handler *this,uint param_1,ulong param_2)
{
  uint uVar1;
  int iVar2;
  TDebuggingLog *this_00;
  int *piVar3;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  char msg_str [50];
  
  this->WasKicked[param_1] = 1;
  TDebuggingLog::Log(L,(char *)L,s_Drop_dead_called_P__d_and_DPID__,param_1,param_2);
  (this->PlayerOptions).InvalidPlayer[param_1] = '\0';
  if (param_1 == 0) {
    TDebuggingLog::Log(this_00,(char *)L,s_Player_number_invalid___Returnin);
    UpdatePlayers(this);
    return;
  }
  if (param_1 != this->Me) {
    iVar2 = IsPlayerHuman(this,param_1);
    if (iVar2 == 0) {
      NotifyWindowParam(this,COMM_PLAYER_DEFEATED,param_1);
      TDebuggingLog::Log(this_02,(char *)L,s_Player_was_defeated__was_compute);
      InitPlayerInformation(this,param_1,0,s_Defeated,s_No_Other_Information);
      UpdatePlayers(this);
      CalculatePlayerRange(this);
      return;
    }
    if (((int)(this->PlayerOptions).ProgramState < 5) || (this->current_turn < 6)) {
      TDebuggingLog::Log(this_01,(char *)L,s_Player_dropped_before_game_start);
      InitPlayerInformation(this,param_1,0,s_Dropped,s_No_Other_Information);
      SetPlayerHumanity(this,param_1,ME_ABSENT);
      UpdatePlayers(this);
      CalculatePlayerRange(this);
    }
    else {
      TDebuggingLog::Log(L,(char *)L,s_Player_quit_the_game_);
                    /* language.dll match for 0x4bd: "Player %d - '%s' dropped/disconnected." */
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x4bd,msg_str + 4,0x32);
      sprintf(this->TBuff,msg_str + 4,param_1,this->FriendlyName + param_1);
      TDebuggingLog::Log(L,(char *)L,this->TBuff);
      InitPlayerInformation(this,param_1,0,s_Dropped,&s__);
      SetPlayerHumanity(this,param_1,ME_ABSENT);
      UpdatePlayers(this);
      CalculatePlayerRange(this);
      if (this->PlayerStopTurn[param_1] != 0) {
        return;
      }
    }
    NotifyWindowParam(this,COMM_OTHER_PLAYER_DROPPED,param_1);
    return;
  }
  TDebuggingLog::Log(this_00,(char *)L,s_I_Dropped_);
  NotifyWindowParam(this,COMM_PLAYER_DROPPED,this->Me);
  uVar1 = 1;
  if (this->MaxGamePlayers != 0) {
    piVar3 = this->WasKicked;
    do {
      piVar3 = piVar3 + 1;
      *piVar3 = 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 <= this->MaxGamePlayers);
  }
  TRIBE_World::send_zone_score_info((TRIBE_World *)rge_base_game->world);
  TDebuggingLog::Log(L,(char *)L,s_Initialize_Player_List);
  uVar1 = 1;
  if (this->MaxGamePlayers != 0) {
    do {
      InitPlayerInformation(this,uVar1,0,&s__,&s__);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= (int)(uint)this->MaxGamePlayers);
  }
  (this->PlayerOptions).NeedsToBeSent = '\0';
  (this->PlayerOptions).LastSentTime = 0;
  UpdatePlayers(this);
  return;
}

// --------------------------------------------------

// Function: EvaluateSystemMessage
// Address: 00428da0
// [HELPER] s_Add_delete_player_of_group_: "Add/delete player of group."
// [HELPER] s_Assumed_host: "Assumed host"
// [HELPER] s_COMM_Host_session_lost_: "COMM:Host session lost."
// [HELPER] s_COMM_Unknown_system_message___d: "COMM:Unknown system message. %d"
// [HELPER] s_COMM__Create_Player_Request_: "COMM: Create Player Request."
// [HELPER] s_Checking_state_for_options_rcvd_: "Checking state for options rcvd from host."
// [HELPER] s_Create_Player_Request____MeHost_: "Create Player Request.  (MeHost=%d), Programstate=%d DPID=%d "
// [HELPER] s_DPMSG_DESTRPYPLAYERORGROUP___to_: "DPMSG_DESTRPYPLAYERORGROUP  (to debug dropping players)"
// [HELPER] s_DP_Chat_Msg: "DP Chat Msg"
// [HELPER] s_DP_Sys_Msg__d: "DP Sys Msg %d"
// [HELPER] s_Equates_to_our_player____d_: "Equates to our player # %d "
// [HELPER] s_FROM_Player_ID_____d_: "FROM Player ID =		%d "
// [HELPER] s_Game_not_yet_started_: "Game not yet started."
// [HELPER] s_Group_options_rcvd_from_host_: "Group options rcvd from host."
// [HELPER] s_HOST_Send_to_all___drop_player__: "HOST Send to all - drop player %d ID=%d "
// [HELPER] s_Host_Launched_game: "Host Launched game"
// [HELPER] s_Host___no_rcv_opts_: "Host - no rcv opts."
// [HELPER] s_Host__other__Exit_before_game_st: "Host (other) Exit before game start"
// [HELPER] s_OPTIONS_SET___program_state____d: "OPTIONS SET - program state = %d"
// [HELPER] s_Program_state_is_________d_: "Program state is        %d "
// [HELPER] s_RX_NEW_PLR_ID__d: "RX NEW PLR ID=%d"
// [HELPER] s_START_SESSION_MESSAGE_RCVD__: "START SESSION MESSAGE RCVD. "
// [HELPER] s_Secure_message_dp: "Secure message dp"
// [HELPER] s_Serial___was_0__setting_my_seria: "Serial # was 0, setting my serial number to %d"
// [HELPER] s_Set_Sessino_Description: "Set Sessino Description"
// [HELPER] s_Set_expected_ser__for_player__d_: "Set expected ser# for player %d to %d"
// [HELPER] s_Set_my_serial_number_to__d: "Set my serial number to %d"
// [HELPER] s_Set_player_or_group_name: "Set player or group name"
// [HELPER] s__MP_in_DPANALYSIS: "!MP in DPANALYSIS"
// [HELPER] s___: "]\n"
// [HELPER] s______NOTICE____: " *** NOTICE ***"
// [HELPER] s_delete_player_of_group_: "delete player of group."
/* WARNING: Variable defined which should be unmapped: kp */
/* WARNING: Type propagation algorithm not settling */
/* protected: void __thiscall TCommunications_Handler::EvaluateSystemMessage(unsigned long,char
   *,unsigned long,unsigned long) */

void __thiscall
TCommunications_Handler::EvaluateSystemMessage
          (TCommunications_Handler *this,ulong param_1,char *param_2,ulong param_3,ulong param_4)
{
  char *pcVar1;
  ulong uVar2;
  COMMSTATES CVar3;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  PLAYERHUMANITY *pPVar7;
  TDebuggingLog *this_03;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_04;
  TDebuggingLog *this_05;
  TDebuggingLog *this_06;
  TDebuggingLog *extraout_ECX_01;
  TDebuggingLog *extraout_ECX_02;
  TDebuggingLog *this_07;
  uint uVar8;
  undefined4 *puVar9;
  TDebuggingLog *pTVar10;
  uint *puVar11;
  COMMPLAYEROPTIONS *pCVar12;
  MSGFORMAT_KILL_PLAYER kp;
  
  if (this->Multiplayer == 0) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s__MP_in_DPANALYSIS);
    return;
  }
  TDebuggingLog::Log(*(TDebuggingLog **)param_2,(char *)L,s_DP_Sys_Msg__d,*(TDebuggingLog **)param_2
                    );
  pTVar10 = *(TDebuggingLog **)param_2;
  if (pTVar10 < (TDebuggingLog *)0x22) {
    if (pTVar10 == (TDebuggingLog *)0x21) {
      TDebuggingLog::Log(L,(char *)L,s_delete_player_of_group_);
      return;
    }
    if (pTVar10 == (TDebuggingLog *)&DAT_00000003) {
      uVar2 = *(ulong *)(param_2 + 8);
      TDebuggingLog::Log((TDebuggingLog *)&DAT_00000003,(char *)L,s_RX_NEW_PLR_ID__d,uVar2);
      TDebuggingLog::Log(L,(char *)L,s_COMM__Create_Player_Request_);
      pcVar1 = this->TBuff;
      sprintf(pcVar1,s_Create_Player_Request____MeHost_,this->MeHost,
              (this->PlayerOptions).ProgramState,uVar2);
      TDebuggingLog::Log(L,(char *)L,pcVar1);
      CVar3 = (this->PlayerOptions).ProgramState;
      if ((CVar3 == COMM_STATE_RUNNING) || (6 < this->current_turn)) {
        *pcVar1 = 'I';
        TDebuggingLog::Log(*(TDebuggingLog **)(param_2 + 8),(char *)L,s___>TX_GIP__u__1_,
                           *(TDebuggingLog **)(param_2 + 8));
        FastSend(this,*(ulong *)(param_2 + 8),pcVar1,1,0,0);
        return;
      }
      if (this->MeHost == 0) {
        return;
      }
      uVar4 = 1;
      if (this->MaxGamePlayers != 0) {
        pPVar7 = (this->PlayerOptions).Humanity;
        do {
          pPVar7 = pPVar7 + 1;
          if (*pPVar7 == ME_ABSENT) goto LAB_0042902a;
          uVar4 = uVar4 + 1;
        } while (uVar4 <= this->MaxGamePlayers);
      }
      uVar4 = 0;
LAB_0042902a:
      if ((uVar4 != 0) && (CVar3 == COMM_STATE_JOINNOW)) {
        InitPlayerInformation
                  (this,uVar4,*(ulong *)(param_2 + 8),*(char **)(param_2 + 0x20),
                   *(char **)(param_2 + 0x24));
        (this->PlayerOptions).dcoID[uVar4] = uVar2;
        (this->PlayerOptions).Humanity[uVar4] = ME_HUMAN;
        (this->PlayerOptions).NeedsToBeSent = '\x01';
        (this->PlayerOptions).InvalidPlayer[uVar4] = '\0';
        CalculatePlayerRange(this);
        UpdatePlayer(this,uVar4,1);
        (this->PlayerOptions).NeedsToBeSent = '\x01';
        this->PlayerHighSerialNumber[uVar4] = uVar4 * 2000;
        ClearRXTXForPlayer(this,uVar4);
        SendSharedData(this,0);
        return;
      }
      *pcVar1 = 'I';
      TDebuggingLog::Log(*(TDebuggingLog **)(param_2 + 8),(char *)L,s___>TX_GIP2__u__1_,
                         *(TDebuggingLog **)(param_2 + 8));
      FastSend(this,*(ulong *)(param_2 + 8),pcVar1,1,0,0);
      UpdatePlayers(this);
      return;
    }
    if (pTVar10 == (TDebuggingLog *)0x5) {
      uVar2 = *(ulong *)(param_2 + 8);
      if (uVar2 != 0) {
        uVar4 = (uint)(this->PlayerOptions).LowPlayerNumber;
        uVar8 = (uint)(this->PlayerOptions).HighPlayerNumber;
        if (uVar4 <= uVar8) {
          puVar6 = (this->PlayerOptions).dcoID + uVar4;
          do {
            if (*puVar6 == uVar2) goto LAB_00428e50;
            uVar4 = uVar4 + 1;
            puVar6 = puVar6 + 1;
          } while ((int)uVar4 <= (int)uVar8);
        }
      }
      uVar4 = 0;
LAB_00428e50:
      TDebuggingLog::Log(L,(char *)L,s_DPMSG_DESTRPYPLAYERORGROUP___to_);
      TDebuggingLog::Log(this_00,(char *)L,s_FROM_Player_ID_____d_,*(undefined4 *)(param_2 + 8));
      TDebuggingLog::Log(L,(char *)L,s_Equates_to_our_player____d_,uVar4);
      TDebuggingLog::Log(this_01,(char *)L,s_Program_state_is_________d_,
                         (this->PlayerOptions).ProgramState);
      TDebuggingLog::FlushLog(L);
      iVar5 = IsPlayerHuman(this,uVar4);
      if ((iVar5 != 0) && (this->PlayerStopTurn[uVar4] == 0)) {
        if (uVar4 == this->Me) {
          NotifyWindow(this,COMM_PLAYER_DROPPED);
        }
        else {
          NotifyWindowParam(this,COMM_OTHER_PLAYER_DROPPED,uVar4);
        }
      }
      if (this->MeHost == 0) {
        return;
      }
      kp.CurrentTurn = *(ulong *)(param_2 + 8);
      kp.dcoID = uVar4;
      TDebuggingLog::Log((TDebuggingLog *)this->current_turn,(char *)L,
                         s_HOST_Send_to_all___drop_player__,uVar4,kp.CurrentTurn);
      TDebuggingLog::Log(this_02,(char *)L,s___>TX_KP2___d___d_,uVar4,0xc);
      CommOut(this,0,'K',&kp.dcoID,0xc,'\0');
      if (uVar4 == 0) {
        return;
      }
      if (this->PlayerStopTurn[kp.dcoID] != 0) {
        return;
      }
      DropDeadPlayer(this,uVar4,uVar2);
      return;
    }
    if (pTVar10 == (TDebuggingLog *)&DAT_00000007) {
switchD_00429160_caseD_105:
      TDebuggingLog::Log(pTVar10,(char *)L,s_Add_delete_player_of_group_);
      return;
    }
  }
  else {
    switch(pTVar10) {
    case (TDebuggingLog *)0x31:
      TDebuggingLog::Log(pTVar10,(char *)L,s_COMM_Host_session_lost_);
      (this->PlayerOptions).NeedsToBeSent = '\x01';
      UpdatePlayers(this);
      NotifyWindow(this,COMM_HOST_EXITED);
      return;
    case (TDebuggingLog *)0x101:
      if (((this->PlayerOptions).ProgramState != COMM_STATE_JOINNOW) && (5 < this->current_turn)) {
        TDebuggingLog::Log(pTVar10,(char *)L,s_Assumed_host);
        this->MeHost = 1;
        (this->PlayerOptions).HostPlayerNumber = this->Me;
        CheckPingTime(this,1);
        UpdatePlayers(this);
        EnableNewPlayers(this,DAT_0062c5ec,0);
        CalculatePlayerRange(this);
        NotifyWindowParam(this,COMM_HOST_CHANGED,this->Me);
        KillAnyMissingPlayers(this);
        return;
      }
      TDebuggingLog::Log(pTVar10,(char *)L,s_Host__other__Exit_before_game_st);
      NotifyWindow(this,COMM_HOST_EXITED);
      EnableNewPlayers(this,DAT_0062c5ec,1);
      return;
    case (TDebuggingLog *)0x102:
      sprintf(this->TBuff,s__Player_Data>_P1__d_P2__d_P3__d_,(this->PlayerOptions).dcoID[1],
              (this->PlayerOptions).dcoID[2],(this->PlayerOptions).dcoID[3],
              (this->PlayerOptions).dcoID[4],(this->PlayerOptions).dcoID[5],
              (this->PlayerOptions).dcoID[6],(this->PlayerOptions).dcoID[7],
              (this->PlayerOptions).dcoID[8]);
      TDebuggingLog::Log(this_03,(char *)L,this->TBuff);
      uVar4 = 1;
      pTVar10 = extraout_ECX;
      if (this->MaxGamePlayers != 0) {
                    /* language.dll match for 0x7d0: "place holder" */
        uVar8 = 2000;
        puVar11 = this->PlayerHighSerialNumber;
        do {
          puVar11 = puVar11 + 1;
          if ((*puVar11 == 0) && (puVar11[0xf] != 0)) {
            ClearRXTXForPlayer(this,uVar4);
            *puVar11 = uVar8;
            TDebuggingLog::Log(L,(char *)L,s_Set_expected_ser__for_player__d_,uVar4,uVar8 + 1);
            pTVar10 = extraout_ECX_00;
          }
          uVar4 = uVar4 + 1;
          uVar8 = uVar8 + 2000;
        } while (uVar4 <= this->MaxGamePlayers);
      }
      if (this->MeHost == 0) {
        TDebuggingLog::Log(L,(char *)L,s_Checking_state_for_options_rcvd_);
        if ((this->PlayerOptions).ProgramState != COMM_STATE_JOINNOW) {
          return;
        }
        TDebuggingLog::Log(this_04,(char *)L,s_Group_options_rcvd_from_host_);
        if (0x1cf < *(uint *)(param_2 + 0x10)) {
          puVar9 = *(undefined4 **)(param_2 + 0xc);
          pCVar12 = &this->PlayerOptions;
                    /* language.dll match for 0x74: "Copperplate Gothic Light" */
          for (iVar5 = 0x74; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined4 *)pCVar12 = *puVar9;
            puVar9 = puVar9 + 1;
            pCVar12 = (COMMPLAYEROPTIONS *)&pCVar12->LastSentTime;
          }
          uVar2 = (this->PlayerOptions).DataSizeToFollow;
          if (uVar2 + 0x1d0 <= *(uint *)(param_2 + 0x10)) {
            SetMyGameOptions(this,(char *)(*(int *)(param_2 + 0xc) + 0x1d0),uVar2);
          }
          NotifyWindow(this,COMM_UPDATE_PARAMS);
        }
        uVar2 = (this->PlayerOptions).CurrentTurn;
        this->AcknowledgeAfterMsec = (this->PlayerOptions).AcknowledgeAfterMsec;
        this->current_turn = uVar2;
        SetSelfPlayer(this);
        if ((this->PlayerOptions).GameHasStarted == 0) {
          TDebuggingLog::Log(L,(char *)L,s_Game_not_yet_started_);
          pTVar10 = extraout_ECX_02;
        }
        else {
          TDebuggingLog::Log(this_05,(char *)L,s_Host_Launched_game);
          CalculatePlayerRange(this);
          TDebuggingLog::Log(L,(char *)L,s_OPTIONS_SET___program_state____d,
                             (this->PlayerOptions).ProgramState);
          (this->PlayerOptions).ProgramState = COMM_STATE_RUNNING;
          ResetLastCommunicationTimes(this);
          ClearRXandTX(this);
          puVar6 = this->PlayerStopTurn;
          pTVar10 = (TDebuggingLog *)0x1;
          for (iVar5 = 9; puVar6 = puVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar6 = 0;
          }
          this_06 = (TDebuggingLog *)0x0;
          if (this->MaxGamePlayers != 0) {
                    /* language.dll match for 0x7d0: "place holder" */
            uVar4 = 2000;
            puVar11 = this->PlayerHighSerialNumber;
            this_06 = (TDebuggingLog *)0x0;
            do {
              puVar11 = puVar11 + 1;
              if (puVar11[0xf] != 0) {
                *puVar11 = uVar4;
                TDebuggingLog::Log(this_06,(char *)L,s_Set_expected_ser__for_player__d_,pTVar10,
                                   uVar4 + 1);
              }
              pTVar10 = (TDebuggingLog *)((int)&pTVar10->Timestamp + 1);
              this_06 = (TDebuggingLog *)(uint)this->MaxGamePlayers;
              uVar4 = uVar4 + 2000;
            } while (pTVar10 <= this_06);
          }
          uVar4 = this->Me * 2000 + 1;
          this->GTDSerialNo = uVar4;
          TDebuggingLog::Log(this_06,(char *)L,s_Set_my_serial_number_to__d,uVar4);
          NotifyWindow(this,COMM_UPDATE_PARAMS);
          NotifyWindow(this,COMM_LAUNCH_GAME);
          pTVar10 = extraout_ECX_01;
        }
        if ((((this->PlayerOptions).GameHasStarted == 0) && (this->GTDSerialNo == 0)) &&
           (this->Me != 0)) {
          uVar4 = this->Me * 2000 + 1;
          this->GTDSerialNo = uVar4;
          TDebuggingLog::Log(pTVar10,(char *)L,s_Serial___was_0__setting_my_seria,uVar4);
        }
        UpdatePlayers(this);
        NotifyWindow(this,COMM_UPDATE_PARAMS);
        return;
      }
      TDebuggingLog::Log(pTVar10,(char *)L,s_Host___no_rcv_opts_);
      return;
    case (TDebuggingLog *)0x103:
      UpdatePlayers(this);
      TDebuggingLog::Log(L,(char *)L,s_Set_player_or_group_name);
      NotifyWindow(this,COMM_UPDATE_PARAMS);
      return;
    case (TDebuggingLog *)0x104:
      TDebuggingLog::Log(pTVar10,(char *)L,s_Set_Sessino_Description);
      return;
    case (TDebuggingLog *)0x105:
      goto switchD_00429160_caseD_105;
    case (TDebuggingLog *)0x107:
      TDebuggingLog::Log(pTVar10,(char *)L,s_Secure_message_dp);
      return;
    case (TDebuggingLog *)0x108:
      TDebuggingLog::Log(L,(char *)L,s_START_SESSION_MESSAGE_RCVD__);
      TDebuggingLog::Log(this_07,(char *)L,s______NOTICE____);
      return;
    case (TDebuggingLog *)0x109:
      TDebuggingLog::Log(L,(char *)L,s_DP_Chat_Msg);
      return;
    }
  }
  TDebuggingLog::Log(pTVar10,(char *)L,s_COMM_Unknown_system_message___d,pTVar10);
  return;
}

// --------------------------------------------------

// Function: SendGroupChatMsg
// Address: 00429760
/* WARNING: Variable defined which should be unmapped: DestMap */
/* public: void __thiscall TCommunications_Handler::SendGroupChatMsg(char *) */

void __thiscall
TCommunications_Handler::SendGroupChatMsg(TCommunications_Handler *this,char *param_1)
{
  int iVar1;
  uint uVar2;
  uchar DestMap [10];
  
  DestMap[4] = 'N';
  DestMap[5] = 'N';
  DestMap[6] = 'N';
  DestMap[7] = 'N';
  uVar2 = 1;
  stack0xfffffff8 = 0x4e4e4e4e;
  if (this->MaxGamePlayers != 0) {
    do {
      iVar1 = TChat::inChatGroup(this->Chat,uVar2);
      if (iVar1 != 0) {
        DestMap[uVar2 + 4] = 'Y';
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 <= this->MaxGamePlayers);
  }
  TXChat(this,this->Me,DestMap + 4,param_1);
  return;
}

// --------------------------------------------------

// Function: SendChatMsgAll
// Address: 004297d0
/* WARNING: Variable defined which should be unmapped: DestMap */
/* public: void __thiscall TCommunications_Handler::SendChatMsgAll(char *) */

void __thiscall TCommunications_Handler::SendChatMsgAll(TCommunications_Handler *this,char *param_1)
{
  uchar DestMap [10];
  
  DestMap[4] = 'Y';
  DestMap[5] = 'Y';
  DestMap[6] = 'Y';
  DestMap[7] = 'Y';
  DestMap._0_4_ = param_1;
  stack0xfffffff8 = 0x59595959;
  TXChat(this,this->Me,DestMap + 4,param_1);
  return;
}

// --------------------------------------------------

// Function: SendChatMsg
// Address: 00429810
// [HELPER] s_SendChatMsg_FROM__d__TO__d_Text_: "SendChatMsg FROM=%d  TO=%d Text='%s'"
/* WARNING: Variable defined which should be unmapped: DestMap */
/* public: void __thiscall TCommunications_Handler::SendChatMsg(unsigned int,unsigned int,char *) */

void __thiscall
TCommunications_Handler::SendChatMsg
          (TCommunications_Handler *this,uint param_1,uint param_2,char *param_3)
{
  uchar DestMap [10];
  
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_SendChatMsg_FROM__d__TO__d_Text_,param_1,
                     param_2,param_3);
  DestMap[4] = 'N';
  DestMap[5] = 'N';
  DestMap[6] = 'N';
  DestMap[7] = 'N';
  stack0xfffffff8 = 0x4e4e4e4e;
  DestMap[param_2 + 4] = 'Y';
  TXChat(this,param_1,DestMap + 4,param_3);
  return;
}

// --------------------------------------------------

// Function: TXChat
// Address: 00429870
// [HELPER] s_Local_chat_add___s: "Local chat add: %s"
// [HELPER] s_Local_chat_single_player_add___s: "Local chat single player add: %s"
// [HELPER] s_TXChat__: "TXChat()"
// [HELPER] s___: "]\n"
/* WARNING: Variable defined which should be unmapped: cht */
/* public: long __thiscall TCommunications_Handler::TXChat(unsigned int,unsigned char *,char *) */

long __thiscall
TCommunications_Handler::TXChat
          (TCommunications_Handler *this,uint param_1,uchar *param_2,char *param_3)
{
  char cVar1;
  int iVar2;
  long lVar3;
  TDebuggingLog *this_00;
  undefined4 extraout_ECX;
  uint uVar4;
  char *pcVar5;
  MSGFORMAT_CHAT cht;
  
  if (this->Multiplayer == 0) {
    TChat::AddChatMsg(this->Chat,this->FriendlyName[param_1].Text,param_3,'\x01');
    TDebuggingLog::Log(this_00,(char *)L,s_Local_chat_single_player_add___s,param_3);
    return 0;
  }
  if (this->MaxGamePlayers < param_1) {
    return -0x7fffbffb;
  }
  uVar4 = 1;
  if (this->MaxGamePlayers != 0) {
    do {
      iVar2 = IsPlayerHuman(this,uVar4);
      if ((iVar2 == 0) || (param_2[uVar4] != 'Y')) {
        cht.DestPlayers[uVar4 + 4] = 'N';
      }
      else {
        cht.DestPlayers[uVar4 + 4] = 'Y';
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= this->MaxGamePlayers);
  }
  if (cht.DestPlayers[this->Me + 4] == 'Y') {
    TChat::AddChatMsg(this->Chat,this->FriendlyName[param_1].Text,param_3,'\x01');
    TDebuggingLog::Log(L,(char *)L,s_Local_chat_add___s,param_3);
  }
  uVar4 = 0xffffffff;
  pcVar5 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (~uVar4 - 1 < 0x100) {
    uVar4 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    cht._16_4_ = ~uVar4 - 1;
  }
  else {
    cht._16_4_ = 0xff;
  }
  cht.DestPlayers[3] = (uchar)param_1;
  strncpy(cht.ChatMsg + 4,param_3,cht._16_4_ + 1);
  cht.ChatMsg[3] = (this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW;
  TDebuggingLog::Log((TDebuggingLog *)CONCAT31((int3)((uint)extraout_ECX >> 8),cht.ChatMsg[3]),
                     (char *)L,s___>TX_CHAT___s____d_,param_3,cht._16_4_ + 0x16);
  lVar3 = CommOut(this,0,'C',cht.DestPlayers + 3,cht._16_4_ + 0x16,'\0');
  RGE_Comm_Error::ShowReturn(this->Err,lVar3,s_TXChat__);
  return lVar3;
}

// --------------------------------------------------

// Function: SendSpeedChange
// Address: 00429a30
// [HELPER] s___: "]\n"
/* public: void __thiscall TCommunications_Handler::SendSpeedChange(unsigned int,unsigned int) */

void __thiscall
TCommunications_Handler::SendSpeedChange(TCommunications_Handler *this,uint param_1,uint param_2)
{
  if ((this->MeHost != 0) && (this->Multiplayer != 0)) {
    param_1 = CONCAT22((undefined2)param_2,(short)param_1);
    TDebuggingLog::Log((TDebuggingLog *)CONCAT22((short)((uint)this >> 0x10),(undefined2)param_2),
                       (char *)L,s___>TX_KP_SPD___d_,4);
    CommOut(this,0,'S',&param_1,4,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: SendIResignMsg
// Address: 00429a90
// [HELPER] s___: "]\n"
/* WARNING: Variable defined which should be unmapped: resign */
/* public: void __thiscall TCommunications_Handler::SendIResignMsg(void) */

void __thiscall TCommunications_Handler::SendIResignMsg(TCommunications_Handler *this)
{
  MSGFORMAT_ONTURN resign;
  MSGFORMAT_ALL_DONE alldone;
  
  if (this->Multiplayer != 0) {
    alldone._0_4_ = this->current_turn + (uint)(this->PlayerOptions).CommandTurnIncrement;
    TDebuggingLog::Log((TDebuggingLog *)alldone._0_4_,(char *)L,s___>TX_RSGN___d_,4);
    CommOut(this,0,'Q',&alldone,4,'\0');
    RGE_Communications_Speed::GetHighLatencyCenti(this->Speed);
    RGE_Communications_Speed::GetAvgFrameRate(this->Speed);
    alldone._8_4_ = this->current_turn + 1 + (uint)(this->PlayerOptions).CommandTurnIncrement;
    alldone.ExecuteOnTurn._0_1_ = 0x44;
    TDebuggingLog::Log(L,(char *)L,s___>TX_DONE___d_,0xc);
    CommOut(this,0,'D',&alldone.ExecuteOnTurn,0xc,'\0');
    alldone._8_4_ =
         ((TDebuggingLog *)this->current_turn)->TBuff +
         ((this->PlayerOptions).CommandTurnIncrement - 0x26);
    TDebuggingLog::Log((TDebuggingLog *)this->current_turn,(char *)L,s___>TX_DONE___d_,0xc);
    CommOut(this,0,'D',&alldone.ExecuteOnTurn,0xc,'\0');
    alldone._8_4_ = this->current_turn + 3 + (uint)(this->PlayerOptions).CommandTurnIncrement;
    TDebuggingLog::Log((TDebuggingLog *)alldone._8_4_,(char *)L,s___>TX_DONE___d_,0xc);
    CommOut(this,0,'D',&alldone.ExecuteOnTurn,0xc,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: HiTurnAcknowledged
// Address: 00429bd0
/* public: unsigned long __thiscall TCommunications_Handler::HiTurnAcknowledged(void) */

ulong __thiscall TCommunications_Handler::HiTurnAcknowledged(TCommunications_Handler *this)
{
  int iVar1;
  ulong *puVar2;
  uint uVar3;
  
  DAT_0062c5e8 = 0;
  uVar3 = (uint)(this->PlayerOptions).LowPlayerNumber;
  if (uVar3 <= (this->PlayerOptions).HighPlayerNumber) {
    puVar2 = this->LastTurnAck + uVar3;
    do {
      iVar1 = IsPlayerHuman(this,uVar3);
      if ((iVar1 != 0) && (DAT_0062c5e8 < *puVar2)) {
        DAT_0062c5e8 = *puVar2;
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while ((int)uVar3 <= (int)(uint)(this->PlayerOptions).HighPlayerNumber);
  }
  return DAT_0062c5e8;
}

// --------------------------------------------------

// Function: AllPlayersAcknowledged
// Address: 00429c40
/* public: int __thiscall TCommunications_Handler::AllPlayersAcknowledged(void) */

int __thiscall TCommunications_Handler::AllPlayersAcknowledged(TCommunications_Handler *this)
{
  int iVar1;
  ulong *puVar2;
  uint uVar3;
  
  if (this->Multiplayer == 0) {
    return 0;
  }
  if (this->ShuttingDown != 0) {
    return 0;
  }
  if ((this->PlayerOptions).ProgramState == COMM_STATE_PAUSE) {
    return 0;
  }
  uVar3 = (uint)(this->PlayerOptions).LowPlayerNumber;
  if (uVar3 <= (this->PlayerOptions).HighPlayerNumber) {
    puVar2 = this->LastTurnAck + uVar3;
    while( true ) {
      iVar1 = IsPlayerHuman(this,uVar3);
      if ((iVar1 != 0) && (*puVar2 < this->current_turn)) break;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
      if ((this->PlayerOptions).HighPlayerNumber < uVar3) {
        return 1;
      }
    }
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: SendChecksumMessage
// Address: 00429ce0
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_SendChecksum: "SendChecksum"
// [HELPER] s___: "]\n"
/* WARNING: Variable defined which should be unmapped: cs */
/* public: long __thiscall TCommunications_Handler::SendChecksumMessage(unsigned long,unsigned
   int,long,long,long,long,long) */

long __thiscall
TCommunications_Handler::SendChecksumMessage
          (TCommunications_Handler *this,ulong param_1,uint param_2,long param_3,long param_4,
          long param_5,long param_6,long param_7)
{
  long lVar1;
  TDebuggingLog *this_00;
  MSGFORMAT_CHECKSUM cs;
  
  cs.WorldTurn = param_1;
  cs.Random = this->current_turn;
  cs.cs2 = param_3;
  cs.cs3 = param_4;
  cs.cs4 = param_5;
                    /* language.dll match for 0xbc0: "Not enough room to unload all." */
  cs.cs5 = param_6;
  cs.PingInitiated = param_7;
  cs.cs1 = param_2;
  debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbc0);
  TDebuggingLog::Log(this_00,(char *)L,s___>TX_CKSUM___d_,0x24);
  lVar1 = CommOut(this,0,'M',&cs.WorldTurn,0x24,'\0');
  RGE_Comm_Error::ShowReturn(this->Err,lVar1,s_SendChecksum);
  return lVar1;
}

// --------------------------------------------------

// Function: ExecuteIncoming
// Address: 00429d90
// [HELPER] s_Cached_Execute___d__Slot__d_: "Cached Execute #%d  Slot#%d "
// [HELPER] s_Clearing_OnHold_Slot__d__Len__d_: "Clearing OnHold Slot=%d  Len=%d  From=%d  To=%d"
// [HELPER] s____Clearing_PAST_OnHold_Slot__d_: "+++Clearing PAST OnHold Slot=%d  Serial#%d Len=%d  From=%d  To=%d  Expecting#%d"
/* WARNING: Variable defined which should be unmapped: i */
/* public: unsigned int __thiscall TCommunications_Handler::ExecuteIncoming(void) */

uint __thiscall TCommunications_Handler::ExecuteIncoming(TCommunications_Handler *this)
{
  HOLDER *pHVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  TDebuggingLog *this_00;
  uint uVar5;
  uint uVar6;
  ulong *puVar7;
  undefined4 *puVar8;
  uint i;
  uint pno;
  uint local_8;
  
  uVar5 = 0;
  if (this->Multiplayer != 0) {
    pno = 0;
    do {
      if ((*(int *)((int)&this->OnHold->Length + uVar5) != 0) &&
         (local_8 = 1, this->MaxGamePlayers != 0)) {
        puVar7 = (this->PlayerOptions).dcoID;
        do {
          puVar7 = puVar7 + 1;
          iVar4 = IsPlayerHuman(this,local_8);
          if ((iVar4 != 0) && (local_8 != this->Me)) {
            pHVar1 = this->OnHold;
            uVar6 = puVar7[-0xf] + 1;
            uVar2 = *(uint *)((int)&pHVar1->Serial + uVar5);
            if ((uVar2 < uVar6) &&
               (uVar3 = *(ulong *)((int)&pHVar1->dcoFromID + uVar5), uVar3 == *puVar7)) {
              TDebuggingLog::Log(L,(char *)L,s____Clearing_PAST_OnHold_Slot__d_,pno,uVar2,
                                 *(undefined4 *)((int)&pHVar1->Length + uVar5),uVar3,
                                 *(undefined4 *)((int)&pHVar1->dcoReceiveID + uVar5),uVar6);
              puVar8 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar5);
              if ((void *)*puVar8 != (void *)0x0) {
                operator_delete((void *)*puVar8);
              }
              *puVar8 = 0;
              puVar8[1] = 0;
              puVar8[2] = 0;
              puVar8[3] = 0;
              puVar8[4] = 0;
            }
            if ((*(uint *)((int)&this->OnHold->Serial + uVar5) == uVar6) &&
               (*(ulong *)((int)&this->OnHold->dcoFromID + uVar5) == *puVar7)) {
              sprintf(this->TBuff,s_Cached_Execute___d__Slot__d_,uVar6,pno);
              TDebuggingLog::Log(this_00,(char *)L,this->TBuff);
              puVar8 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar5);
              PreprocessMessages(this,puVar8[2],(char *)*puVar8,puVar8[3],puVar8[4],1);
              pHVar1 = this->OnHold;
              TDebuggingLog::Log((TDebuggingLog *)pno,(char *)L,s_Clearing_OnHold_Slot__d__Len__d_,
                                 pno,*(undefined4 *)((int)&pHVar1->Length + uVar5),
                                 *(undefined4 *)((int)&pHVar1->dcoFromID + uVar5),
                                 *(undefined4 *)((int)&pHVar1->dcoReceiveID + uVar5));
              puVar8 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar5);
              if ((void *)*puVar8 != (void *)0x0) {
                operator_delete((void *)*puVar8);
              }
              *puVar8 = 0;
              puVar8[1] = 0;
              puVar8[2] = 0;
              puVar8[3] = 0;
              puVar8[4] = 0;
            }
          }
          local_8 = local_8 + 1;
        } while (local_8 <= this->MaxGamePlayers);
      }
      uVar5 = uVar5 + 0x18;
      pno = pno + 1;
    } while (uVar5 < 0x2ef9);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: ClearAllSerialNumbers
// Address: 00429f80
// [HELPER] s_Cleared_all_serial_numbers_: "Cleared all serial numbers."
/* public: void __thiscall TCommunications_Handler::ClearAllSerialNumbers(void) */

void __thiscall TCommunications_Handler::ClearAllSerialNumbers(TCommunications_Handler *this)
{
  uint *puVar1;
  uint uVar2;
  
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Cleared_all_serial_numbers_);
  uVar2 = 0;
  puVar1 = this->LastSerialRequestedTX;
  do {
    puVar1[0x51] = 0;
    *puVar1 = 0;
    puVar1[10] = 0;
    puVar1[0x14] = 0;
    puVar1[0x1e] = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 <= this->MaxGamePlayers);
  return;
}

// --------------------------------------------------

// Function: ClearRXandTX
// Address: 00429fd0
/* public: void __thiscall TCommunications_Handler::ClearRXandTX(void) */

void __thiscall TCommunications_Handler::ClearRXandTX(TCommunications_Handler *this)
{
  RESENDER *pRVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar4 = 0;
  do {
    puVar6 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar4);
    if ((void *)*puVar6 != (void *)0x0) {
      operator_delete((void *)*puVar6);
    }
    uVar4 = uVar4 + 0x18;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
  } while (uVar4 < 0x2ef8);
  uVar4 = 0;
  do {
    pRVar1 = this->Resend;
    *(undefined4 *)((int)pRVar1->DestMap + (uVar4 - 0x10)) = 0;
    pvVar2 = *(void **)((int)pRVar1->DestMap + (uVar4 - 8));
    if (pvVar2 != (void *)0x0) {
      operator_delete(pvVar2);
    }
    uVar5 = uVar4 + 0x38;
    *(undefined4 *)((int)pRVar1->DestMap + (uVar4 - 8)) = 0;
    *(undefined4 *)((int)pRVar1->DestMap + (uVar4 - 0xc)) = 0;
    *(undefined4 *)((int)pRVar1->DestMap + (uVar4 - 4)) = 0;
    puVar6 = (undefined4 *)((int)pRVar1->DestMap + uVar4);
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    uVar4 = uVar5;
  } while (uVar5 < 0x6d98);
  return;
}

// --------------------------------------------------

// Function: ClearRXForPlayer
// Address: 0042a060
/* protected: void __thiscall TCommunications_Handler::ClearRXForPlayer(unsigned int) */

void __thiscall
TCommunications_Handler::ClearRXForPlayer(TCommunications_Handler *this,uint param_1)
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    puVar1 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar2);
    if (*(ulong *)((int)&this->OnHold->dcoFromID + uVar2) == (this->PlayerOptions).dcoID[param_1]) {
      if ((void *)*puVar1 != (void *)0x0) {
        operator_delete((void *)*puVar1);
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
    }
    uVar2 = uVar2 + 0x18;
  } while (uVar2 < 0x2ef9);
  return;
}

// --------------------------------------------------

// Function: CountWaitingMessages
// Address: 0042a0c0
// [HELPER] s_GTD__Ser___d_Slot__d_Cmd___c__Le: "GTD: Ser #%d Slot=%d Cmd='%c' Len=%d not ackd yet by %d,%d,%d,%d,%d,%d,%d,%d"
/* public: int __thiscall TCommunications_Handler::CountWaitingMessages(void) */

int __thiscall TCommunications_Handler::CountWaitingMessages(TCommunications_Handler *this)
{
  RESENDER *pRVar1;
  TDebuggingLog *this_00;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  uVar3 = 0;
  do {
    pRVar1 = this->Resend;
    this_00 = *(TDebuggingLog **)((int)pRVar1->DestMap + (uVar3 - 0xc));
    if (this_00 != (TDebuggingLog *)0x0) {
      TDebuggingLog::Log(this_00,(char *)L,s_GTD__Ser___d_Slot__d_Cmd___c__Le,this_00,iVar4,
                         (int)**(char **)((int)pRVar1->DestMap + (uVar3 - 8)),
                         *(undefined4 *)((int)pRVar1->DestMap + (uVar3 - 4)),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 4),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 8),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 0xc),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 0x10),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 0x14),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 0x18),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 0x1c),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar3 + 0x20));
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 0x38;
    iVar4 = iVar4 + 1;
  } while (uVar3 < 0x6d99);
  return iVar2;
}

// --------------------------------------------------

// Function: ClearTXForPlayer
// Address: 0042a130
/* protected: void __thiscall TCommunications_Handler::ClearTXForPlayer(unsigned int) */

void __thiscall
TCommunications_Handler::ClearTXForPlayer(TCommunications_Handler *this,uint param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x1f6;
  iVar1 = param_1 * 4 + 0x10;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)((int)this->Resend->DestMap + iVar1 + -0x10) = 0;
    iVar1 = iVar1 + 0x38;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: ClearRXTXForPlayer
// Address: 0042a160
/* protected: void __thiscall TCommunications_Handler::ClearRXTXForPlayer(unsigned int) */

void __thiscall
TCommunications_Handler::ClearRXTXForPlayer(TCommunications_Handler *this,uint param_1)
{
  ClearTXForPlayer(this,param_1);
  ClearRXForPlayer(this,param_1);
  return;
}

// --------------------------------------------------

// Function: StoreIncoming
// Address: 0042a180
// [HELPER] s_Future_Ser__d_previously_stored_: "Future Ser#%d previously stored (Slot#%d)"
// [HELPER] s_HOLD_FULL_WARNING___COUNT__d: "HOLD FULL WARNING.  COUNT=%d"
// [HELPER] s_S__d__Ser__d_FromID__d_Len__d__C: "S#%d  Ser#%d FromID=%d Len=%d  CMD='%c' B0=%d B1=%d"
// [HELPER] s____StoreIncoming_called_for_zero: "+++StoreIncoming called for zero-length message"
// [HELPER] s_____DID_NOT_STORE___: "+++ DID NOT STORE:  "
/* public: int __thiscall TCommunications_Handler::StoreIncoming(unsigned int,char *,unsigned
   int,unsigned long,unsigned long) */

int __thiscall
TCommunications_Handler::StoreIncoming
          (TCommunications_Handler *this,uint param_1,char *param_2,uint param_3,ulong param_4,
          ulong param_5)
{
  ulong *puVar1;
  uint *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  TDebuggingLog *this_00;
  int iVar8;
  HOLDER *pHVar9;
  int iVar10;
  
  if (param_3 == 0) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s____StoreIncoming_called_for_zero);
  }
  pHVar9 = this->OnHold;
  uVar5 = 0;
  puVar1 = &pHVar9->dcoFromID;
  while ((puVar1[-2] != param_1 || (*puVar1 != param_4))) {
    uVar5 = uVar5 + 1;
    puVar1 = puVar1 + 6;
    if (0x1f5 < uVar5) {
      uVar5 = 0;
      puVar2 = &pHVar9->Length;
      while ((*puVar2 != 0 || (param_3 == 0))) {
        uVar5 = uVar5 + 1;
        puVar2 = puVar2 + 6;
        if (500 < uVar5) {
          TDebuggingLog::Log(L,(char *)L,s_____DID_NOT_STORE___);
          if (0x1eb < uVar5) {
            TDebuggingLog::Log(this_00,(char *)L,s_HOLD_FULL_WARNING___COUNT__d,uVar5);
            iVar10 = 0;
            uVar5 = 0;
            do {
              puVar4 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar5);
              if (puVar4[2] != 0) {
                iVar8 = (int)*(char *)*puVar4;
                TDebuggingLog::Log(L,(char *)L,s_S__d__Ser__d_FromID__d_Len__d__C,iVar10,puVar4[1],
                                   puVar4[3],puVar4[2],iVar8,iVar8,(int)((char *)*puVar4)[1]);
              }
              uVar5 = uVar5 + 0x18;
              iVar10 = iVar10 + 1;
            } while (uVar5 < 0x2ef8);
          }
          return 1;
        }
      }
      pHVar9[uVar5].Length = param_3;
      pHVar9 = this->OnHold + uVar5;
      pcVar3 = (char *)operator_new(pHVar9->Length);
      pHVar9->HoldMsg = pcVar3;
      if (pcVar3 != (char *)0x0) {
        uVar7 = pHVar9->Length;
        for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar3 = *(undefined4 *)param_2;
          param_2 = param_2 + 4;
          pcVar3 = pcVar3 + 4;
        }
        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *pcVar3 = *param_2;
          param_2 = param_2 + 1;
          pcVar3 = pcVar3 + 1;
        }
        pHVar9->Length = param_3;
      }
      this->OnHold[uVar5].Serial = param_1;
      this->OnHold[uVar5].dcoFromID = param_4;
      this->OnHold[uVar5].dcoReceiveID = param_5;
      return 1;
    }
  }
  TDebuggingLog::Log(L,(char *)L,s_Future_Ser__d_previously_stored_,param_1,uVar5);
  return 1;
}

// --------------------------------------------------

// Function: StoreForResend
// Address: 0042a330
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_QUEUE_Has_Ser___d__Slot__d__Cmd_: "QUEUE Has Ser #%d (Slot=%d) Cmd=%d '%c' Len=%d not ackd yet by %d,%d,%d,%d,%d..."
// [HELPER] s_RESEND_buffer_filled_up__slots__: "RESEND buffer filled up, slots (i=%d)."
// [HELPER] s_Stored__db_for_resend__Slot___d_: "Stored %db for resend (Slot= %d ) SERIAL=%d  (MaxPlayers=%d)"
// [HELPER] s_____RGEGTD_Store: "+++!RGEGTD Store"
/* public: int __thiscall TCommunications_Handler::StoreForResend(unsigned int,char *,unsigned
   int,unsigned int *) */

int __thiscall
TCommunications_Handler::StoreForResend
          (TCommunications_Handler *this,uint param_1,char *param_2,uint param_3,uint *param_4)
{
  RESENDER *pRVar1;
  char *pcVar2;
  ulong uVar3;
  int iVar4;
  TDebuggingLog *this_00;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  
  if (this->Multiplayer != 0) {
    if (this->RGE_Guaranteed_Delivery == '\0') {
      TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_____RGEGTD_Store);
      return 0;
    }
    iVar7 = 0;
    uVar8 = 0;
    do {
      pRVar1 = this->Resend;
      iVar6 = *(int *)((int)pRVar1->DestMap + (uVar8 - 0xc));
      if (iVar6 == 0) {
        this->Resend[iVar7].Length = param_3;
        if (param_3 != 0) {
          pRVar1 = this->Resend;
          pcVar2 = (char *)operator_new(pRVar1[iVar7].Length);
          pRVar1[iVar7].ResendMsg = pcVar2;
          if (pcVar2 != (char *)0x0) {
            uVar8 = pRVar1[iVar7].Length;
            for (uVar5 = uVar8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined4 *)pcVar2 = *(undefined4 *)param_2;
              param_2 = param_2 + 4;
              pcVar2 = pcVar2 + 4;
            }
            for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pcVar2 = *param_2;
              param_2 = param_2 + 1;
              pcVar2 = pcVar2 + 1;
            }
            pRVar1[iVar7].Length = param_3;
          }
        }
        this->Resend[iVar7].Serial = param_1;
        puVar9 = param_4;
        puVar10 = this->Resend[iVar7].DestMap;
        for (uVar8 = (uint)this->MaxGamePlayers * 4 + 4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(char *)puVar10 = (char)*puVar9;
          puVar9 = (uint *)((int)puVar9 + 1);
          puVar10 = (uint *)((int)puVar10 + 1);
        }
        TDebuggingLog::Log((TDebuggingLog *)(uint)this->MaxGamePlayers,(char *)L,
                           s_Stored__db_for_resend__Slot___d_,param_3,iVar7,param_1,
                           (TDebuggingLog *)(uint)this->MaxGamePlayers);
        uVar8 = 1;
        if (this->MaxGamePlayers != 0) {
          iVar6 = iVar7 * 0x38 + 0x14;
          do {
            param_4 = param_4 + 1;
            if (*(int *)((int)this->Resend->DestMap + iVar6 + -0x10) != 0) {
              TDebuggingLog::Log((TDebuggingLog *)*param_4,(char *)L,s_______to__>_P__d__retries__d,
                                 uVar8,(TDebuggingLog *)*param_4);
            }
            uVar8 = uVar8 + 1;
            iVar6 = iVar6 + 4;
          } while (uVar8 <= this->MaxGamePlayers);
        }
        uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd12);
        this->Resend[iVar7].TimeSent = uVar3;
        return 1;
      }
      iVar4 = (int)**(char **)((int)pRVar1->DestMap + (uVar8 - 8));
      TDebuggingLog::Log(L,(char *)L,s_QUEUE_Has_Ser___d__Slot__d__Cmd_,iVar6,iVar7,iVar4,iVar4,
                         *(undefined4 *)((int)pRVar1->DestMap + (uVar8 - 4)),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 4),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 8),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0xc),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x10),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x14),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x18),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x1c),
                         *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x20));
      uVar8 = uVar8 + 0x38;
      iVar7 = iVar7 + 1;
    } while (uVar8 < 0x6d98);
    TDebuggingLog::Log(this_00,(char *)L,s_RESEND_buffer_filled_up__slots__,iVar7);
  }
  return 0;
}

// --------------------------------------------------

// Function: TXAcknowledgeMessage
// Address: 0042a540
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_GTD_ACK: "GTD ACK"
// [HELPER] s__RGEGTD_Ack: "!RGEGTD Ack"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____TXAcknowledgeMessage_slow____: "!!!TXAcknowledgeMessage slow - %ld msec"
/* public: int __thiscall TCommunications_Handler::TXAcknowledgeMessage(unsigned int,unsigned int)
    */

int __thiscall
TCommunications_Handler::TXAcknowledgeMessage
          (TCommunications_Handler *this,uint param_1,uint param_2)
{
  undefined1 *puVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  TDebuggingLog *this_00;
  
  if (this->RGE_Guaranteed_Delivery == '\0') {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s__RGEGTD_Ack);
    return 0;
  }
  puVar1 = (undefined1 *)operator_new(8);
  *puVar1 = 0x41;
  *(uint *)(puVar1 + 4) = param_1;
  if (DAT_0062cf04 == 0) {
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s____BAD_DCOID_0_NO_TX);
    return 0;
  }
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd53);
  iVar3 = (**(code **)(*DAT_0062c5ec + 0x68))
                    (DAT_0062c5ec,DAT_0062cf04,(this->PlayerOptions).dcoID[param_2],0,puVar1,8);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd5e);
  if (0x32 < uVar4 - uVar2) {
    TDebuggingLog::Log(this_00,(char *)L,s____TXAcknowledgeMessage_slow____,uVar4 - uVar2);
  }
  this->TXPacketLength = this->TXPacketLength + 8;
  operator_delete(puVar1);
  if (iVar3 == 0) {
    return 1;
  }
  RGE_Comm_Error::ShowReturn(this->Err,iVar3,s_GTD_ACK);
  return 0;
}

// --------------------------------------------------

// Function: RXAcknowledgeStoredMessage
// Address: 0042a650
// [HELPER] s_COMM__RX_ACK_from_P__d_for_Ser__: "COMM: RX ACK from P#%d for Ser#%d"
// [HELPER] s__RGEGTD_RxAck: "!RGEGTD RxAck"
/* public: int __thiscall TCommunications_Handler::RXAcknowledgeStoredMessage(unsigned int,unsigned
   int) */

int __thiscall
TCommunications_Handler::RXAcknowledgeStoredMessage
          (TCommunications_Handler *this,uint param_1,uint param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (this->RGE_Guaranteed_Delivery == '\0') {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s__RGEGTD_RxAck);
    return 0;
  }
  TDebuggingLog::Log(L,(char *)L,s_COMM__RX_ACK_from_P__d_for_Ser__,param_2,param_1);
  this->WaitingForAck = 0;
  uVar2 = 0;
  iVar3 = param_2 * 4 + 0x10;
  do {
    uVar1 = *(uint *)((int)this->Resend->DestMap + (uVar2 - 0xc));
    if ((uVar1 == param_1) && (uVar1 != 0)) {
      *(undefined4 *)((int)this->Resend->DestMap + iVar3 + -0x10) = 0;
    }
    uVar2 = uVar2 + 0x38;
    iVar3 = iVar3 + 0x38;
  } while (uVar2 < 0x6d99);
  return 1;
}

// --------------------------------------------------

// Function: PurgeAcknowledgedStoredMessages
// Address: 0042a6e0
// [HELPER] s_GTD__Ser___d_Slot__d__Ackd_by_al: "GTD: Ser #%d Slot=%d  Ackd by all. (Released)"
/* WARNING: Variable defined which should be unmapped: NonAckCount */
/* public: int __thiscall TCommunications_Handler::PurgeAcknowledgedStoredMessages(void) */

int __thiscall
TCommunications_Handler::PurgeAcknowledgedStoredMessages(TCommunications_Handler *this)
{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint NonAckCount;
  uint i;
  int local_8;
  uint local_4;
  
  iVar3 = 0;
  local_8 = 0;
  local_4 = 4;
  do {
    i = 0;
    if (*(int *)((int)this->Resend->DestMap + iVar3 + -0xc) != 0) {
      uVar4 = 1;
      if (this->MaxGamePlayers != 0) {
        do {
          iVar1 = IsPlayerHuman(this,uVar4);
          if ((iVar1 != 0) && (this->Resend->DestMap[uVar4 + local_4 + -4] != 0)) {
            i = i + 1;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 <= this->MaxGamePlayers);
      }
      if (i == 0) {
        TDebuggingLog::Log(L,(char *)L,s_GTD__Ser___d_Slot__d__Ackd_by_al,
                           *(undefined4 *)((int)this->Resend->DestMap + iVar3 + -0xc),local_8);
        puVar5 = (undefined4 *)((int)this->Resend->DestMap + iVar3 + -0x10);
        *puVar5 = 0;
        if ((void *)puVar5[2] != (void *)0x0) {
          operator_delete((void *)puVar5[2]);
        }
        puVar5[2] = 0;
        puVar5[1] = 0;
        puVar5[3] = 0;
        puVar5 = puVar5 + 4;
        for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
      }
    }
    local_4 = local_4 + 0xe;
    local_8 = local_8 + 1;
    iVar3 = iVar3 + 0x38;
  } while (local_4 < 0x1b6b);
  iVar3 = 0x1f6;
  puVar2 = &this->Resend->Serial;
  do {
    if (*puVar2 != 0) {
      this->WaitingForAck = this->WaitingForAck + 1;
    }
    puVar2 = puVar2 + 0xe;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 1;
}

// --------------------------------------------------

// Function: SendStoredMessages
// Address: 0042a800
// [HELPER] s_COMM__RESENT_TX_Ser__d_To_P__d_L: "COMM: RESENT TX Ser#%d To=P#%d Len=%d"
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_HOST_Rcvd_MAX_TX_for_player___d: "HOST Rcvd MAX TX for player #%d"
// [HELPER] s_Max_resends_to_Player___d___s__: "Max resends to Player #%d '%s' "
// [HELPER] s_RESEND_Transmit: "RESEND Transmit"
// [HELPER] s_Resending___d_to_P__d_dcoid__d_L: "Resending #%d to P#%d dcoid=%d Length=%d  (elapsed=%d timeGetTime=%d) remaini..."
// [HELPER] s_TX_Missing_Player_report_for_pla: "TX Missing Player report for player=%d "
// [HELPER] s__RGEGTD_SendStore: "!RGEGTD SendStore"
// [HELPER] s___: "]\n"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____SendStoredMessages_slow____ld: "!!!SendStoredMessages slow - %ld msec"
/* WARNING: Variable defined which should be unmapped: items */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall TCommunications_Handler::SendStoredMessages(void) */

int __thiscall TCommunications_Handler::SendStoredMessages(TCommunications_Handler *this)
{
  TDebuggingLog *this_00;
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  int *piVar5;
  ulong uVar6;
  uint *puVar7;
  uint *puVar8;
  TCommunications_Handler *extraout_ECX;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  uint uVar9;
  int iVar10;
  RESENDER *pRVar11;
  uint uVar12;
  char *pcVar13;
  undefined4 uVar14;
  uint items;
  ulong OldestMessageElapsed;
  uint OldestMessageSlot;
  uint local_18;
  long hr;
  MSGFORMAT_MISSING_PLAYER m;
  
  if (this->RGE_Guaranteed_Delivery == '\0') {
    pcVar13 = s__RGEGTD_SendStore;
LAB_0042acdf:
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,pcVar13);
    return 0;
  }
  if ((DAT_0062c5e4 & 1) == 0) {
    DAT_0062c5e4 = DAT_0062c5e4 | 1;
    DAT_0062c5a8 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe00);
  }
  m._0_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe02);
  uVar12 = 0;
  if (_DAT_0056f210 < (float)DAT_0062cf28 / (float)(int)(m._0_4_ - DAT_0062c5a8)) {
    return 0;
  }
  DAT_0062cf28 = 0;
  OldestMessageSlot = 0;
  local_18 = 0;
  OldestMessageElapsed = 0;
  DAT_0062c5a8 = m._0_4_;
  PurgeAcknowledgedStoredMessages(this);
  pRVar11 = this->Resend;
  uVar9 = 0;
  puVar7 = pRVar11->DestMap + 1;
  do {
    if (puVar7[-4] != 0) {
      OldestMessageElapsed = OldestMessageElapsed + 1;
      uVar2 = m._0_4_ - pRVar11->TimeSent;
      if (OldestMessageSlot < uVar2) {
        OldestMessageSlot = uVar2;
        local_18 = uVar12;
      }
      puVar8 = puVar7;
      for (uVar2 = (uint)this->MaxGamePlayers; uVar2 != 0; uVar2 = uVar2 - 1) {
        if (uVar9 < 0xf0 - *puVar8) {
          uVar9 = 0xf0 - *puVar8;
        }
        puVar8 = puVar8 + 1;
      }
    }
    uVar12 = uVar12 + 1;
    pRVar11 = pRVar11 + 1;
    puVar7 = puVar7 + 0xe;
  } while (uVar12 < 0x1f6);
  if (OldestMessageElapsed == 0) {
    return 0;
  }
  if (this->current_turn < 7) {
    if (OldestMessageSlot < 2000) {
      return 0;
    }
  }
  else if (this->ShuttingDown == 0) {
    uVar12 = resend_adj2 + this->Speed->HighestLatencyMsec * 2;
    if (uVar12 < resend_adj1 + 500U) {
      uVar12 = resend_adj1 + 500U;
    }
    if (OldestMessageSlot < uVar12) {
      return 0;
    }
  }
  else if (OldestMessageSlot < 0xfa) {
    return 0;
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe55);
  uVar12 = 1;
  this->Resend[local_18].TimeSent = uVar3;
  if (this->MaxGamePlayers == 0) {
    return this->ResentToOther;
  }
  iVar10 = local_18 * 0x38 + 0x14;
  puVar1 = (this->PlayerOptions).dcoID;
  do {
    OldestMessageElapsed = (ulong)(puVar1 + 1);
    if ((((*(int *)((int)this->Resend->DestMap + iVar10 + -0x10) != 0) &&
         (iVar4 = IsPlayerHuman(this,uVar12), iVar4 != 0)) && (*(int *)OldestMessageElapsed != 0))
       && (uVar12 != this->Me)) {
      piVar5 = (int *)((int)this->Resend->DestMap + iVar10 + -0x10);
      iVar4 = *piVar5;
      if (iVar4 != 0) {
        *piVar5 = iVar4 + -1;
      }
      uVar14 = *(undefined4 *)((int)this->Resend->DestMap + iVar10 + -0x10);
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe69);
      TDebuggingLog::Log(*(TDebuggingLog **)OldestMessageElapsed,(char *)L,
                         s_Resending___d_to_P__d_dcoid__d_L,local_18,uVar12,
                         *(TDebuggingLog **)OldestMessageElapsed,this->Resend[local_18].Length,
                         OldestMessageSlot,uVar3,uVar14);
      if (DAT_0062cf04 == 0) {
        pcVar13 = s____BAD_DCOID_0_NO_TX;
        this = extraout_ECX;
        goto LAB_0042acdf;
      }
                    /* language.dll match for 0xe76: "Click to attack this building." */
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe76);
      TDebuggingLog::Log(L,(char *)L,s___>TX_STOR___d__d___d_,uVar12,local_18,
                         this->Resend[local_18].Length);
      m._0_4_ = (**(code **)(*DAT_0062c5ec + 0x68))
                          (DAT_0062c5ec,DAT_0062cf04,*(undefined4 *)OldestMessageElapsed,0,
                           this->Resend[local_18].ResendMsg,this->Resend[local_18].Length);
      uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe86);
      if (0x32 < uVar6 - uVar3) {
        TDebuggingLog::Log(L,(char *)L,s____SendStoredMessages_slow____ld,uVar6 - uVar3);
      }
      if (m._0_4_ == 0) {
        puVar7 = &this->Resend[local_18].Length;
        this->ResentToOther = this->ResentToOther + 1;
        this->TXPacketLength = this->TXPacketLength + *puVar7;
        DAT_0062cf28 = DAT_0062cf28 + *puVar7;
        this_00 = (TDebuggingLog *)this->Resend[local_18].Length;
        TDebuggingLog::Log(this_00,(char *)L,s_COMM__RESENT_TX_Ser__d_To_P__d_L,
                           this->Resend[local_18].Serial,uVar12,this_00);
      }
      else {
        RGE_Comm_Error::ShowReturn(this->Err,m._0_4_,s_RESEND_Transmit);
      }
      if (((*(int *)((int)this->Resend->DestMap + iVar10 + -0x10) == 0) &&
          (iVar4 = IsPlayerHuman(this,uVar12), iVar4 != 0)) &&
         ((*(int *)OldestMessageElapsed != 0 && (uVar12 != this->Me)))) {
        pcVar13 = GetPlayerName(this,uVar12);
        sprintf(this->TBuff,s_Max_resends_to_Player___d___s__,uVar12,pcVar13);
        TDebuggingLog::Log(L,(char *)L,this->TBuff);
        if (this->MeHost == 0) {
          TDebuggingLog::Log((TDebuggingLog *)OldestMessageElapsed,(char *)L,
                             s_TX_Missing_Player_report_for_pla,*(undefined4 *)OldestMessageElapsed)
          ;
          m.PlayerID._0_1_ = 0x3f;
          TDebuggingLog::Log(this_02,(char *)L,s___>TX_MP___d_,8);
          FastSend(this,0,&m.PlayerID,8,0,0);
        }
        else {
          TDebuggingLog::Log(this_01,(char *)L,s_HOST_Rcvd_MAX_TX_for_player___d,uVar12);
          puVar1[-0x31] = 1;
          Kick(this,uVar12);
        }
      }
    }
    uVar12 = uVar12 + 1;
    iVar10 = iVar10 + 4;
    puVar1 = (ulong *)OldestMessageElapsed;
    if (this->MaxGamePlayers < uVar12) {
      return this->ResentToOther;
    }
  } while( true );
}

// --------------------------------------------------

// Function: TXResendReply
// Address: 0042ad10
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Found_Resend_Ser__d_for_P__d: "Found Resend Ser#%d for P#%d"
// [HELPER] s_Invalid_player_req_: "Invalid player req."
// [HELPER] s_RESEND_to_P__d_FULFILLED___GoodT: "RESEND to P#%d FULFILLED:  GoodTX=%d BadTX=%d Total=%d"
// [HELPER] s_Res_reply_too_soon___u__u: "Res reply too soon #%u %u"
// [HELPER] s_Resend_TX: "Resend TX"
// [HELPER] s___: "]\n"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____TXResendReply_slow____ld_msec: "!!!TXResendReply slow - %ld msec"
// [HELPER] s_____Did_not_have_requested_Ser__: "+++ Did not have requested Ser#%d for P#%d "
// [HELPER] s_____TX__No_such_message_as___d__: "+++ TX: No such message as #%d..resynchronizing ser#s"
/* WARNING: Variable defined which should be unmapped: BadTransmitCount */
/* public: int __thiscall TCommunications_Handler::TXResendReply(unsigned int,unsigned int) */

int __thiscall
TCommunications_Handler::TXResendReply(TCommunications_Handler *this,uint param_1,uint param_2)
{
  TDebuggingLog *this_00;
  RESENDER *pRVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  TCommunications_Handler *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  uint uVar6;
  char *pcVar7;
  uint BadTransmitCount;
  uint i;
  uint GoodTransmitCount;
  long hr;
  MSGFORMAT_RESEND nosuch;
  
  uVar2 = param_2;
  if (this->RGE_Guaranteed_Delivery == '\0') {
    return 0;
  }
  uVar6 = 0;
  if ((this->PlayerOptions).dcoID[param_2] == 0) {
    pcVar7 = s_Invalid_player_req_;
    this_01 = this;
LAB_0042b07b:
    TDebuggingLog::Log((TDebuggingLog *)this_01,(char *)L,pcVar7);
    return 0;
  }
  if (DAT_0062cf04 == 0) {
    return 0;
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xee7);
  if ((param_1 == this->LastSerialRepliedTX[param_2]) &&
     (uVar5 = uVar3 - this->LastRequestRepliedTX[param_2], uVar5 < 500)) {
    TDebuggingLog::Log(L,(char *)L,s_Res_reply_too_soon___u__u,param_1,uVar5);
    return 0;
  }
  this->LastSerialRepliedTX[param_2] = param_1;
  this->LastRequestRepliedTX[param_2] = uVar3;
  hr = 0;
  i = 0;
  GoodTransmitCount = 0;
  param_2 = param_2 * 4 + 0x10;
  do {
    uVar5 = *(uint *)((int)this->Resend->DestMap + (uVar6 - 0xc));
    if (uVar5 == param_1) {
      sprintf(this->TBuff,s_Found_Resend_Ser__d_for_P__d,uVar5,uVar2);
      TDebuggingLog::Log(L,(char *)L,this->TBuff);
      nosuch.Serialno = (uint)operator_new(*(uint *)((int)this->Resend->DestMap + (uVar6 - 4)));
      this_01 = (TCommunications_Handler *)
                (*(int *)((int)this->Resend->DestMap + (param_2 - 0x10)) + -1);
      *(TCommunications_Handler **)((int)this->Resend->DestMap + (param_2 - 0x10)) = this_01;
      if (DAT_0062cf04 == 0) {
        pcVar7 = s____BAD_DCOID_0_NO_TX;
        goto LAB_0042b07b;
      }
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf19);
      this_00 = *(TDebuggingLog **)((int)this->Resend->DestMap + (uVar6 - 4));
      TDebuggingLog::Log(this_00,(char *)L,s___>TX_RES_REP___d__d___d_,uVar2,param_1,this_00);
      nosuch._0_4_ = (**(code **)(*DAT_0062c5ec + 0x68))
                               (DAT_0062c5ec,DAT_0062cf04,(this->PlayerOptions).dcoID[uVar2],0,
                                *(undefined4 *)((int)this->Resend->DestMap + (uVar6 - 8)),
                                *(undefined4 *)((int)this->Resend->DestMap + (uVar6 - 4)));
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf28);
      if (0x32 < uVar4 - uVar3) {
        TDebuggingLog::Log(this_02,(char *)L,s____TXResendReply_slow____ld_msec,uVar4 - uVar3);
      }
      if (nosuch._0_4_ == 0) {
        hr = hr + 1;
        this->TXPacketLength =
             this->TXPacketLength + *(int *)((int)this->Resend->DestMap + (uVar6 - 4));
      }
      else {
        RGE_Comm_Error::ShowReturn(this->Err,nosuch._0_4_,s_Resend_TX);
        i = i + 1;
      }
      pRVar1 = this->Resend;
                    /* language.dll match for 0xf42: "Right-click to board this transport." */
      nosuch._0_4_ = SEXT14(**(char **)((int)pRVar1->DestMap + (uVar6 - 8)));
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf42);
      TDebuggingLog::Log(L,(char *)L,s_COMM__>>>>>_RETRANSMIT_P__d_Ser_,uVar2,
                         *(undefined4 *)((int)pRVar1->DestMap + (uVar6 - 0xc)),GoodTransmitCount,
                         nosuch._0_4_,nosuch._0_4_,
                         *(undefined4 *)((int)pRVar1->DestMap + (uVar6 - 4)),
                         *(undefined4 *)((int)pRVar1->DestMap + (param_2 - 0x10)),uVar3);
      operator_delete((void *)nosuch.Serialno);
    }
    uVar6 = uVar6 + 0x38;
    GoodTransmitCount = GoodTransmitCount + 1;
    param_2 = param_2 + 0x38;
    if (0x6d98 < uVar6) {
      if ((hr == 0) && (i == 0)) {
        if ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
          TDebuggingLog::Log(L,(char *)L,s_____Did_not_have_requested_Ser__,param_1,uVar2);
          nosuch.Serialno = CONCAT31(nosuch.Serialno._1_3_,0x59);
          TDebuggingLog::Log(this_03,(char *)L,s___>TX_RNSM___d__d___d_,uVar2,param_1,8);
          FastSend(this,(this->PlayerOptions).dcoID[uVar2],&nosuch.Serialno,8,0,0);
          TDebuggingLog::Log(this_04,(char *)L,s_____TX__No_such_message_as___d__,param_1);
          ClearTXForPlayer(this,uVar2);
        }
      }
      else {
        TDebuggingLog::Log((TDebuggingLog *)hr,(char *)L,s_RESEND_to_P__d_FULFILLED___GoodT,uVar2,hr
                           ,i,i + hr);
      }
      PurgeAcknowledgedStoredMessages(this);
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: TXResendRequest
// Address: 0042b0a0
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_GTD__TX_RESEND_REQ_to_P__d__Ser_: "GTD: TX RESEND REQ to P#%d  Ser#%d "
// [HELPER] s___: "]\n"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____GetNextSequence_slow____ld_ms: "!!!GetNextSequence slow - %ld msec"
/* public: int __thiscall TCommunications_Handler::TXResendRequest(unsigned int,unsigned int) */

int __thiscall
TCommunications_Handler::TXResendRequest(TCommunications_Handler *this,uint param_1,uint param_2)
{
  ulong uVar1;
  undefined1 *puVar2;
  int iVar3;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  int unaff_EDI;
  
  if (this->RGE_Guaranteed_Delivery != '\0') {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf8c);
    if ((param_1 != this->LastSerialRequestedTX[param_2]) ||
       (499 < uVar1 - this->LastRequestHonoredTX[param_2])) {
      this->LastSerialRequestedTX[param_2] = param_1;
      this->LastRequestHonoredTX[param_2] = uVar1;
      puVar2 = (undefined1 *)operator_new(8);
      *puVar2 = 0x58;
      *(uint *)(puVar2 + 4) = param_1;
      TDebuggingLog::Log(this_00,(char *)L,s_GTD__TX_RESEND_REQ_to_P__d__Ser_,param_2,param_1);
      if (DAT_0062cf04 == 0) {
        TDebuggingLog::Log(this_01,(char *)L,s____BAD_DCOID_0_NO_TX);
        return 0;
      }
                    /* language.dll match for 0xfa9: "?" */
      debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xfa9);
      TDebuggingLog::Log(L,(char *)L,s___>TX_RES_REQ___d__d___d_,param_2,param_1,8);
      iVar3 = (**(code **)(*DAT_0062c5ec + 0x68))
                        (DAT_0062c5ec,DAT_0062cf04,(this->PlayerOptions).dcoID[param_2],0,puVar2,8);
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xfb8);
      if (0x32 < uVar1 - unaff_EDI) {
        TDebuggingLog::Log(this_02,(char *)L,s____GetNextSequence_slow____ld_ms,uVar1 - unaff_EDI);
      }
      operator_delete(puVar2);
      if (iVar3 == 0) {
        this->TXPacketLength = this->TXPacketLength + 8;
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: GetNextSequence
// Address: 0042b200
// [HELPER] s____Too_many_commands_in_one_comm: "+++Too many commands in one comm turn.  Seq#=%d"
/* public: unsigned char __thiscall TCommunications_Handler::GetNextSequence(unsigned long) */

uchar __thiscall
TCommunications_Handler::GetNextSequence(TCommunications_Handler *this,ulong param_1)
{
  byte bVar1;
  
  if (param_1 != DAT_0062cf30) {
    DAT_0062cf30 = param_1;
    DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,1);
    return '\x01';
  }
  bVar1 = (char)DAT_0062cf2c + 1;
  DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,bVar1);
  if (bVar1 == 0xff) {
    TDebuggingLog::Log(L,(char *)L,s____Too_many_commands_in_one_comm,0xff);
    return '\0';
  }
  if (((this->PlayerOptions).ProgramState == COMM_STATE_PAUSE) && (100 < bVar1)) {
    DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,100);
    bVar1 = 100;
  }
  return bVar1;
}

// --------------------------------------------------

// Function: CommOut
// Address: 0042b270
// [HELPER] s_ASSERT___BAD_MSG_TYPE: "ASSERT - BAD MSG TYPE"
// [HELPER] s_COMM__Ser__d__s_TX_To__d_Len__d_: "COMM: Ser#%d %s TX To=%d Len=%d+%d HDR> Seq=%d ExecOn=%d Cmd=%d '%c' Content[..."
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_GTD: "GTD"
// [HELPER] s_SER_Not_set___no_transmit_done_: "SER Not set - no transmit done."
// [HELPER] s_TX: "TX"
// [HELPER] s_TX_RGTGTD: "TX RGTGTD"
// [HELPER] s__GTD: "!GTD"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____BAD_Msg_type____ASSERT: "+++BAD Msg type -- ASSERT"
// [HELPER] s____CommOut2_slow____ld_msec: "!!!CommOut2 slow - %ld msec"
// [HELPER] s____CommOut_slow____ld_msec: "!!!CommOut slow - %ld msec"
// [HELPER] s____Damaged_Msg_0b: "+++Damaged Msg 0b"
/* WARNING: Variable defined which should be unmapped: FullLength */
/* protected: long __thiscall TCommunications_Handler::CommOut(unsigned long,unsigned char,void
   *,int,unsigned char) */

long __thiscall
TCommunications_Handler::CommOut
          (TCommunications_Handler *this,ulong param_1,uchar param_2,void *param_3,int param_4,
          uchar param_5)
{
  TDebuggingLog *this_00;
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  int iVar10;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint *puVar15;
  int iVar16;
  char *pcVar17;
  char *pcVar18;
  char *pcVar19;
  uint FullLength;
  uint HeaderLength;
  MSGFORMAT_HEADER_GUARANTEED *txMsg;
  char *OutCommBuff;
  uint OutgoingCount;
  ulong SyncTurn;
  char GTDString [10];
  
  uVar12 = 0;
  if (this->Multiplayer == 0) {
    return 0;
  }
  if (DAT_0062c5ec == (int *)0x0) {
    return 0;
  }
  if (this->GTDSerialNo == 0) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_SER_Not_set___no_transmit_done_);
    return 0;
  }
  pbVar4 = (byte *)operator_new(0xc);
  if ((((param_2 == '1') || (param_2 == '2')) || (param_2 == '?')) || (param_2 == 'A')) {
    TDebuggingLog::Log(L,(char *)L,s____BAD_Msg_type____ASSERT);
  }
  if (this->RGE_Guaranteed_Delivery == '\0') {
    txMsg = (MSGFORMAT_HEADER_GUARANTEED *)0x8;
    pbVar4[8] = 0;
    pbVar4[9] = 0;
    pbVar4[10] = 0;
    pbVar4[0xb] = 0;
    iVar5 = 8;
  }
  else {
    *(uint *)(pbVar4 + 8) = this->GTDSerialNo;
    this->PlayerHighSerialNumber[this->Me] = this->GTDSerialNo;
    this->GTDSerialNo = this->GTDSerialNo + 1;
    iVar5 = 0xc;
    txMsg = (MSGFORMAT_HEADER_GUARANTEED *)0xc;
  }
  this_00 = (TDebuggingLog *)(iVar5 + param_4);
  if ((TDebuggingLog *)0xfa0 < this_00) {
    TDebuggingLog::Log(this_00,(char *)L,s_ERROR__Full_length_>__d__Header_,4000,iVar5,param_4);
  }
  pbVar4[1] = 0;
  *pbVar4 = 0;
  GTDString._0_4_ = this->current_turn + (uint)(this->PlayerOptions).CommandTurnIncrement;
  puVar15 = this->DestMap;
  *(undefined4 *)(pbVar4 + 4) = GTDString._0_4_;
  do {
    iVar5 = IsPlayerHuman(this,uVar12);
    if ((iVar5 == 0) || (uVar12 == this->Me)) {
      *puVar15 = 0;
    }
    else {
      *puVar15 = 0xf0;
    }
    uVar12 = uVar12 + 1;
    puVar15 = puVar15 + 1;
  } while (uVar12 <= this->MaxGamePlayers);
  if (((param_2 == '1') || (param_2 == '2')) || ((param_2 == '?' || (param_2 == 'A')))) {
    TDebuggingLog::Log(L,(char *)L,s_ASSERT___BAD_MSG_TYPE);
  }
  else {
    bVar3 = GetNextSequence(this,GTDString._0_4_);
    pbVar4[1] = bVar3;
    if (((this->PlayerOptions).ProgramState != COMM_STATE_RUNNING) && (bVar3 == 0)) {
      operator_delete(pbVar4);
      return -0x7788fef2;
    }
  }
  *pbVar4 = param_2;
  pbVar6 = (byte *)operator_new((uint)((int)&this_00->Timestamp + 1));
  pbVar13 = pbVar4;
  pbVar14 = pbVar6;
  for (uVar12 = (uint)txMsg >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pbVar14 = *(undefined4 *)pbVar13;
    pbVar13 = pbVar13 + 4;
    pbVar14 = pbVar14 + 4;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pbVar14 = *pbVar13;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
  }
  if (param_4 != 0) {
    pbVar13 = (byte *)param_3;
    pbVar14 = pbVar6 + (int)txMsg;
    for (uVar12 = (uint)param_4 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pbVar14 = *(undefined4 *)pbVar13;
      pbVar13 = pbVar13 + 4;
      pbVar14 = pbVar14 + 4;
    }
    for (uVar12 = param_4 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pbVar14 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      pbVar14 = pbVar14 + 1;
    }
  }
  iVar5 = 0;
  uVar12 = 0;
  puVar15 = this->DestMap;
  do {
    iVar7 = IsPlayerHuman(this,uVar12);
    if ((iVar7 == 0) || (uVar12 == this->Me)) {
      *puVar15 = 0;
    }
    else {
      *puVar15 = 0xf0;
      iVar5 = iVar5 + 1;
    }
    uVar12 = uVar12 + 1;
    puVar15 = puVar15 + 1;
  } while (uVar12 <= this->MaxGamePlayers);
  if (this->RGE_Guaranteed_Delivery == '\0') {
    if (iVar5 != 0) {
      if (DAT_0062cf04 == 0) {
        TDebuggingLog::Log(this_01,(char *)L,s____BAD_DCOID_0_NO_TX);
        return -0x7fffbffb;
      }
      uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10ee);
      iVar7 = (**(code **)(*DAT_0062c5ec + 0x68))
                        (DAT_0062c5ec,DAT_0062cf04,param_1,0,pbVar6,this_00);
      uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10f9);
      if (0x32 < uVar9 - uVar8) {
        TDebuggingLog::Log(this_03,(char *)L,s____CommOut2_slow____ld_msec,uVar9 - uVar8);
      }
      if (param_1 == 0) {
        uVar12 = 1;
        iVar16 = 0;
        if (this->MaxGamePlayers != 0) {
          do {
            iVar10 = IsPlayerHuman(this,uVar12);
            if ((iVar10 != 0) && (uVar12 != this->Me)) {
              iVar16 = iVar16 + 1;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 <= this->MaxGamePlayers);
        }
      }
      else {
        iVar16 = 1;
      }
      if (iVar7 == 0) {
        this->TXPacketLength = this->TXPacketLength + iVar16 * (int)this_00;
      }
      goto LAB_0042b72a;
    }
  }
  else {
    if (this_00 == (TDebuggingLog *)0x0) {
      TDebuggingLog::Log(L,(char *)L,s____Damaged_Msg_0b);
      return -0x7fffbffb;
    }
    if (iVar5 != 0) {
      if (DAT_0062cf04 == 0) {
        TDebuggingLog::Log(this_01,(char *)L,s____BAD_DCOID_0_NO_TX);
        this->GTDSerialNo = this->GTDSerialNo - 1;
        return -0x7fffbffb;
      }
      uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10aa);
      iVar7 = (**(code **)(*DAT_0062c5ec + 0x68))
                        (DAT_0062c5ec,DAT_0062cf04,param_1,0,pbVar6,this_00);
      uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10b5);
      if (0x32 < uVar9 - uVar8) {
        TDebuggingLog::Log(this_02,(char *)L,s____CommOut_slow____ld_msec,uVar9 - uVar8);
      }
      if (param_1 == 0) {
        uVar12 = 1;
        iVar16 = 0;
        if (this->MaxGamePlayers != 0) {
          do {
            iVar10 = IsPlayerHuman(this,uVar12);
            if ((iVar10 != 0) && (uVar12 != this->Me)) {
              iVar16 = iVar16 + 1;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 <= this->MaxGamePlayers);
        }
      }
      else {
        iVar16 = 1;
      }
      if (iVar7 == 0) {
        this->TXPacketLength = this->TXPacketLength + iVar16 * (int)this_00;
        StoreForResend(this,*(uint *)(pbVar4 + 8),(char *)pbVar6,(uint)this_00,this->DestMap);
      }
      else {
        this->GTDSerialNo = this->GTDSerialNo - 1;
        RGE_Comm_Error::ShowReturn(this->Err,iVar7,s_TX_RGTGTD);
      }
      goto LAB_0042b72a;
    }
  }
  iVar7 = 0;
LAB_0042b72a:
  if (iVar5 != 0) {
    pcVar19 = GTDString;
    pcVar17 = s_GTD;
    if (this->RGE_Guaranteed_Delivery == '\0') {
      pcVar17 = &s__GTD;
    }
    uVar12 = 0xffffffff;
    do {
      pcVar18 = pcVar17;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar18 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar18;
    } while (cVar1 != '\0');
    uVar12 = ~uVar12;
    pcVar17 = pcVar18 + -uVar12;
    for (uVar11 = uVar12 >> 2; pcVar19 = pcVar19 + 4, uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar19 = *(undefined4 *)pcVar17;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar19 = *pcVar17;
      pcVar17 = pcVar17 + 1;
      pcVar19 = pcVar19 + 1;
    }
    bVar3 = pbVar6[(int)txMsg];
    bVar2 = *pbVar4;
    uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x112b);
    TDebuggingLog::Log(L,(char *)L,s_COMM__Ser__d__s_TX_To__d_Len__d_,*(undefined4 *)(pbVar4 + 8),
                       GTDString + 4,param_1,param_4,txMsg,(uint)pbVar4[1],
                       *(undefined4 *)(pbVar4 + 4),(uint)bVar2,(uint)bVar2,(int)(char)bVar3,
                       (int)(char)bVar3,iVar5,iVar7,uVar8);
  }
  if (iVar7 == 0) {
    this->TXPackets = this->TXPackets + 1;
    if (param_2 == '>') {
      AddCommand(this,GTDString._0_4_,param_3,param_4,this->Me,pbVar4[1],0);
    }
  }
  else {
    RGE_Comm_Error::ShowReturn(this->Err,iVar7,s_TX);
  }
  operator_delete(pbVar4);
  operator_delete(pbVar6);
  return iVar7;
}

// --------------------------------------------------

// Function: DestroyMultiplayerGame
// Address: 0042b860
// [HELPER] s_C__msdev_work_age1_x1_com_hand_h: "C:\msdev\work\age1_x1\com_hand.h"
// [HELPER] s_Initialize_Player_List: "Initialize Player List"
// [HELPER] s__: "}"
/* public: void __thiscall TCommunications_Handler::DestroyMultiplayerGame(void) */

void __thiscall TCommunications_Handler::DestroyMultiplayerGame(TCommunications_Handler *this)
{
  char cVar1;
  ushort uVar2;
  ulong uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  ulong *puVar10;
  
  DestroyMyPlayer(this);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_com_hand_h,0x267);
  this->RXPacketLength = 0;
  this->RXPacketLengthHigh = 0;
  this->TXPacketLength = 0;
  this->TXPacketLengthHigh = 0;
  this->lastRXDataRate = 0.0;
  this->lastTXDataRate = 0.0;
  this->HoldCount = 0;
  this->ServiceTimeout = 0;
  this->TXPackets = 0;
  this->RXPackets = 0;
  this->RGE_Guaranteed_Delivery = '\0';
  this->ResendAcknowledgements = 0;
  this->ResentToOther = 0;
  this->DroppedPacketCount = 0;
  this->LobbyLaunched = 0;
  this->GTDSerialNo = 0;
  this->dwStopTime = 0;
  this->OutOfSyncFlag = 0;
  TDebuggingLog::Time(L);
  uVar5 = 0xffffffff;
  this->AvgTurnTime = 0;
  this->PauseChangePending = 0;
  this->StepMode = 0;
  this->IntentionallyDropPackets = 0;
  (this->PlayerOptions).LastSentTime = uVar3;
  pcVar8 = &s__;
  do {
    pcVar9 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar8 = pcVar9 + -uVar5;
  pcVar9 = this->MyGameTitle;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar8 = &s__;
  do {
    pcVar9 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar8 = pcVar9 + -uVar5;
  pcVar9 = this->MyFriendlyName;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar8 = &s__;
  do {
    pcVar9 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar8 = pcVar9 + -uVar5;
  pcVar9 = this->MyFormalName;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar2 = this->MaxGamePlayers;
  this->TickStart = 0;
  this->TickCount = 0;
  this->LastTimeoutMessageTime = 0;
  (this->PlayerOptions).LowPlayerNumber = 1;
  (this->PlayerOptions).HighPlayerNumber = uVar2;
  (this->PlayerOptions).GameHasStarted = 0;
  (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
  this->MeHost = 0;
  this->HaveHostInit = 0;
  (this->PlayerOptions).CommandTurnIncrement = '\x02';
  this->current_turn = 4;
  (this->PlayerOptions).CurrentTurn = 4;
  (this->PlayerOptions).NeedsToBeSent = '\0';
  this->AcknowledgeAfterMsec = 0x32;
  this->Me = 0;
  this->Multiplayer = 0;
  this->turnstart = 0;
  this->mselapsed = 0;
  TDebuggingLog::Log((TDebuggingLog *)(uint)uVar2,(char *)L,s_Initialize_Player_List);
  uVar5 = 1;
  if (this->MaxGamePlayers != 0) {
    do {
      InitPlayerInformation(this,uVar5,0,&s__,&s__);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 <= (int)(uint)this->MaxGamePlayers);
  }
  (this->PlayerOptions).NeedsToBeSent = '\0';
  (this->PlayerOptions).LastSentTime = 0;
  ClearAllSerialNumbers(this);
  ClearRXandTX(this);
  puVar10 = this->PlayerStopTurn;
  for (iVar7 = 9; puVar10 = puVar10 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = 0;
  }
  this->Steps = 1;
  ResetLastCommunicationTimes(this);
  this->WaitingForAck = 0;
  if (this->InQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(this->InQ);
  }
  if (this->OutQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(this->OutQ);
  }
  this->ShuttingDown = 0;
  piVar4 = this->Kicked;
  iVar7 = 10;
  do {
    piVar4[-0x4c] = 0;
    *piVar4 = 0;
    piVar4[0xac] = 0;
    piVar4 = piVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return;
}

// --------------------------------------------------

// Function: GetCommunicationsStatus
// Address: 0042bad0
/* public: enum COMMSTATUS __thiscall TCommunications_Handler::GetCommunicationsStatus(void) */

COMMSTATUS __thiscall
TCommunications_Handler::GetCommunicationsStatus(TCommunications_Handler *this)
{
  COMMSTATUS CVar1;
  
  CVar1 = AnalyzeCommunicationsStatus(this);
  this->CommunicationsStatus = CVar1;
  return CVar1;
}

// --------------------------------------------------

// Function: UnlinkCurrentLevel
// Address: 0042bae0
// [HELPER] s_C__msdev_work_age1_x1_com_hand_h: "C:\msdev\work\age1_x1\com_hand.h"
// [HELPER] s_Initialize_Player_List: "Initialize Player List"
// [HELPER] s_Level_is_now_____d_: "Level is now...(%d)"
// [HELPER] s_UNLINK_CommSettingsExcahanged: "UNLINK CommSettingsExcahanged"
// [HELPER] s_UNLINK_GameIsLoading: "UNLINK GameIsLoading"
// [HELPER] s_UNLINK_GameIsPaused: "UNLINK GameIsPaused"
// [HELPER] s_UNLINK_GameIsRunning: "UNLINK GameIsRunning"
// [HELPER] s_UNLINK_GameOptionsExchanged: "UNLINK GameOptionsExchanged"
// [HELPER] s_UNLINK_PlayerCreated: "UNLINK PlayerCreated"
// [HELPER] s_UNLINK_PlayerSet: "UNLINK PlayerSet"
// [HELPER] s_UNLINK_ReleaseComm: "UNLINK ReleaseComm"
// [HELPER] s_UNLINK_SerssionHosted: "UNLINK SerssionHosted"
// [HELPER] s_UNLINK_ServiceAvailable: "UNLINK ServiceAvailable"
// [HELPER] s_UNLINK_SessionAvailable: "UNLINK SessionAvailable"
// [HELPER] s_UNLINK_Unknown: "UNLINK Unknown"
// [HELPER] s_Unlinking_current_level___d_: "Unlinking current level (%d)"
// [HELPER] s__: "}"
/* public: enum COMMSTATUS __thiscall TCommunications_Handler::UnlinkCurrentLevel(void) */

COMMSTATUS __thiscall TCommunications_Handler::UnlinkCurrentLevel(TCommunications_Handler *this)
{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  TChat *pTVar4;
  ulong uVar5;
  int *piVar6;
  RGE_Communications_Speed *pRVar7;
  RGE_Communications_Synchronize *pRVar8;
  COMMSTATUS CVar9;
  TDebuggingLog *this_00;
  uint uVar10;
  int iVar11;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this_01;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  TDebuggingLog *extraout_ECX_01;
  TDebuggingLog *extraout_ECX_02;
  TDebuggingLog *extraout_ECX_03;
  TDebuggingLog *extraout_ECX_04;
  TDebuggingLog *extraout_ECX_05;
  TDebuggingLog *extraout_ECX_06;
  TDebuggingLog *extraout_ECX_07;
  TDebuggingLog *this_05;
  TDebuggingLog *extraout_ECX_08;
  TDebuggingLog *extraout_ECX_09;
  TDebuggingLog *pTVar12;
  uint uVar13;
  ulong *puVar14;
  char *pcVar15;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar16;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cd1c;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TDebuggingLog::Log(L,(char *)L,s_Unlinking_current_level___d_,this->CommunicationsStatus);
  pTVar12 = this_00;
  switch(this->CommunicationsStatus) {
  case UNINITIALIZED:
  case INITIALIZED:
    break;
  case SINGLE_PLAYER:
    this->Multiplayer = 0;
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_com_hand_h,0x267);
    this->RXPacketLength = 0;
    this->RXPacketLengthHigh = 0;
    this->TXPacketLength = 0;
    this->TXPacketLengthHigh = 0;
    this->lastRXDataRate = 0.0;
    this->lastTXDataRate = 0.0;
    this->HoldCount = 0;
    this->ServiceTimeout = 0;
    this->TXPackets = 0;
    this->RXPackets = 0;
    this->RGE_Guaranteed_Delivery = '\0';
    this->ResendAcknowledgements = 0;
    this->ResentToOther = 0;
    this->DroppedPacketCount = 0;
    this->LobbyLaunched = 0;
    this->GTDSerialNo = 0;
    this->dwStopTime = 0;
    this->OutOfSyncFlag = 0;
    TDebuggingLog::Time(L);
    this->AvgTurnTime = 0;
    this->PauseChangePending = 0;
    this->StepMode = 0;
    this->IntentionallyDropPackets = 0;
    uVar13 = 0xffffffff;
    (this->PlayerOptions).LastSentTime = uVar5;
    pcVar16 = &s__;
    do {
      pcVar15 = pcVar16;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar15 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar15;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar16 = pcVar15 + -uVar13;
    pcVar15 = this->MyGameTitle;
    for (uVar10 = uVar13 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar15 = pcVar15 + 1;
    }
    uVar13 = 0xffffffff;
    pcVar16 = &s__;
    do {
      pcVar15 = pcVar16;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar15 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar15;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar16 = pcVar15 + -uVar13;
    pcVar15 = this->MyFriendlyName;
    for (uVar10 = uVar13 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar15 = pcVar15 + 1;
    }
    uVar13 = 0xffffffff;
    pcVar16 = &s__;
    do {
      pcVar15 = pcVar16;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar15 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar15;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar16 = pcVar15 + -uVar13;
    pcVar15 = this->MyFormalName;
    for (uVar10 = uVar13 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar15 = pcVar15 + 1;
    }
    this->TickStart = 0;
    this->TickCount = 0;
    this->LastTimeoutMessageTime = 0;
    uVar13 = 1;
    uVar3 = this->MaxGamePlayers;
    (this->PlayerOptions).LowPlayerNumber = 1;
    (this->PlayerOptions).HighPlayerNumber = uVar3;
    (this->PlayerOptions).GameHasStarted = 0;
    (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    this->MeHost = 0;
    this->HaveHostInit = 0;
    (this->PlayerOptions).CommandTurnIncrement = '\x02';
    this->current_turn = 4;
    (this->PlayerOptions).CurrentTurn = 4;
    (this->PlayerOptions).NeedsToBeSent = '\0';
    this->AcknowledgeAfterMsec = 0x32;
    this->Me = 0;
    this->Multiplayer = 0;
    this->turnstart = 0;
    this->mselapsed = 0;
    TDebuggingLog::Log((TDebuggingLog *)(uint)uVar3,(char *)L,s_Initialize_Player_List);
    if (this->MaxGamePlayers != 0) {
      do {
        InitPlayerInformation(this,uVar13,0,&s__,&s__);
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 <= (int)(uint)this->MaxGamePlayers);
    }
    (this->PlayerOptions).NeedsToBeSent = '\0';
    (this->PlayerOptions).LastSentTime = 0;
    ClearAllSerialNumbers(this);
    ClearRXandTX(this);
    puVar14 = this->PlayerStopTurn;
    for (iVar11 = 9; puVar14 = puVar14 + 1, iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar14 = 0;
    }
    this->Steps = 1;
    ResetLastCommunicationTimes(this);
    this->WaitingForAck = 0;
    if (this->InQ != (RGE_Communications_Queue *)0x0) {
      RGE_Communications_Queue::FlushAll(this->InQ);
    }
    if (this->OutQ != (RGE_Communications_Queue *)0x0) {
      RGE_Communications_Queue::FlushAll(this->OutQ);
    }
    this->ShuttingDown = 0;
    piVar6 = this->Kicked;
    iVar11 = 10;
    do {
      piVar6[-0x4c] = 0;
      *piVar6 = 0;
      piVar6[0xac] = 0;
      piVar6 = piVar6 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    this->Me = 1;
    this->MyFriendlyName[0] = '\0';
    this->MyFormalName[0] = '\0';
    pTVar12 = (TDebuggingLog *)0x0;
    break;
  case MULTIPLAYER_RESET:
    this->Multiplayer = 0;
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_com_hand_h,0x267);
    this->RXPacketLength = 0;
    this->RXPacketLengthHigh = 0;
    this->TXPacketLength = 0;
    this->TXPacketLengthHigh = 0;
    this->lastRXDataRate = 0.0;
    this->lastTXDataRate = 0.0;
    this->HoldCount = 0;
    this->ServiceTimeout = 0;
    this->TXPackets = 0;
    this->RXPackets = 0;
    this->RGE_Guaranteed_Delivery = '\0';
    this->ResendAcknowledgements = 0;
    this->ResentToOther = 0;
    this->DroppedPacketCount = 0;
    this->LobbyLaunched = 0;
    this->GTDSerialNo = 0;
    this->dwStopTime = 0;
    this->OutOfSyncFlag = 0;
    TDebuggingLog::Time(L);
    this->AvgTurnTime = 0;
    this->PauseChangePending = 0;
    this->StepMode = 0;
    this->IntentionallyDropPackets = 0;
    uVar13 = 0xffffffff;
    (this->PlayerOptions).LastSentTime = uVar5;
    pcVar16 = &s__;
    do {
      pcVar15 = pcVar16;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar15 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar15;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar16 = pcVar15 + -uVar13;
    pcVar15 = this->MyGameTitle;
    for (uVar10 = uVar13 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar15 = pcVar15 + 1;
    }
    uVar13 = 0xffffffff;
    pcVar16 = &s__;
    do {
      pcVar15 = pcVar16;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar15 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar15;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar16 = pcVar15 + -uVar13;
    pcVar15 = this->MyFriendlyName;
    for (uVar10 = uVar13 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar15 = pcVar15 + 1;
    }
    uVar13 = 0xffffffff;
    pcVar16 = &s__;
    do {
      pcVar15 = pcVar16;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar15 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar15;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar16 = pcVar15 + -uVar13;
    pcVar15 = this->MyFormalName;
    for (uVar10 = uVar13 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar15 = pcVar15 + 1;
    }
    this->TickStart = 0;
    this->TickCount = 0;
    this->LastTimeoutMessageTime = 0;
    uVar13 = 1;
    uVar3 = this->MaxGamePlayers;
    (this->PlayerOptions).LowPlayerNumber = 1;
    (this->PlayerOptions).HighPlayerNumber = uVar3;
    (this->PlayerOptions).GameHasStarted = 0;
    (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    this->MeHost = 0;
    this->HaveHostInit = 0;
    (this->PlayerOptions).CommandTurnIncrement = '\x02';
    this->current_turn = 4;
    (this->PlayerOptions).CurrentTurn = 4;
    (this->PlayerOptions).NeedsToBeSent = '\0';
    this->AcknowledgeAfterMsec = 0x32;
    this->Me = 0;
    this->Multiplayer = 0;
    this->turnstart = 0;
    this->mselapsed = 0;
    TDebuggingLog::Log((TDebuggingLog *)(uint)uVar3,(char *)L,s_Initialize_Player_List);
    if (this->MaxGamePlayers != 0) {
      do {
        InitPlayerInformation(this,uVar13,0,&s__,&s__);
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 <= (int)(uint)this->MaxGamePlayers);
    }
    (this->PlayerOptions).NeedsToBeSent = '\0';
    (this->PlayerOptions).LastSentTime = 0;
    ClearAllSerialNumbers(this);
    ClearRXandTX(this);
    puVar14 = this->PlayerStopTurn;
    for (iVar11 = 9; puVar14 = puVar14 + 1, iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar14 = 0;
    }
    this->Steps = 1;
    ResetLastCommunicationTimes(this);
    this->WaitingForAck = 0;
    if (this->InQ != (RGE_Communications_Queue *)0x0) {
      RGE_Communications_Queue::FlushAll(this->InQ);
    }
    if (this->OutQ != (RGE_Communications_Queue *)0x0) {
      RGE_Communications_Queue::FlushAll(this->OutQ);
    }
    this->ShuttingDown = 0;
    piVar6 = this->Kicked;
    iVar11 = 10;
    do {
      piVar6[-0x4c] = 0;
      *piVar6 = 0;
      piVar6[0xac] = 0;
      piVar6 = piVar6 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    this->Me = 1;
    (this->PlayerOptions).Humanity[1] = ME_HUMAN;
    pTVar12 = (TDebuggingLog *)0x0;
    break;
  case CONVERSATION_OPEN:
    this->TXPackets = 0;
    this->RXPackets = 0;
    this->RGE_Guaranteed_Delivery = '\x01';
    this->ResendAcknowledgements = 0;
    this->ResentToOther = 0;
    this->DroppedPacketCount = 0;
    this->LobbyLaunched = 0;
    this->ShuttingDown = 0;
    TDebuggingLog::Log(L,(char *)L,s_UNLINK_ReleaseComm);
    ReleaseComm(this);
    pTVar12 = extraout_ECX;
    break;
  case SERVICE_AVAILABLE:
    TDebuggingLog::Log(this_00,(char *)L,s_UNLINK_ServiceAvailable);
    ReleaseComm(this);
    TDebuggingLog::Log(this_01,(char *)L,s_Initialize_Player_List);
    uVar13 = 1;
    if (this->MaxGamePlayers != 0) {
      do {
        InitPlayerInformation(this,uVar13,0,&s__,&s__);
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 <= (int)(uint)this->MaxGamePlayers);
    }
    pTVar4 = this->Chat;
    (this->PlayerOptions).NeedsToBeSent = '\0';
    (this->PlayerOptions).LastSentTime = 0;
    TChat::ClearChat(pTVar4);
    this->MyGameTitle[0] = '\0';
    pTVar12 = extraout_ECX_00;
    goto LAB_0042c45e;
  case SESSION_AVAILABLE:
    ClearRXandTX(this);
    DropAllHostedPlayers(this);
    TDebuggingLog::Log(this_02,(char *)L,s_UNLINK_SessionAvailable);
    TChat::ClearChat(this->Chat);
    CloseSession(this);
    this->GTDSerialNo = 0;
    TDebuggingLog::Log(this_03,(char *)L,s_Initialize_Player_List);
    uVar13 = 1;
    if (this->MaxGamePlayers != 0) {
      do {
        InitPlayerInformation(this,uVar13,0,&s__,&s__);
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 <= (int)(uint)this->MaxGamePlayers);
    }
    uVar3 = this->MaxGamePlayers;
    (this->PlayerOptions).NeedsToBeSent = '\0';
    (this->PlayerOptions).LastSentTime = 0;
    (this->PlayerOptions).HighPlayerNumber = uVar3;
    (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    (this->PlayerOptions).CommandTurnIncrement = '\x02';
    this->current_turn = 4;
    (this->PlayerOptions).CurrentTurn = 4;
    this->Me = 0;
    DAT_0062cf04 = 0;
    ClearAllSerialNumbers(this);
    pRVar7 = this->Speed;
    (this->PlayerOptions).GameHasStarted = 0;
    this->ShuttingDown = 0;
    if (pRVar7 != (RGE_Communications_Speed *)0x0) {
      RGE_Communications_Speed::~RGE_Communications_Speed(pRVar7);
      operator_delete(pRVar7);
    }
    pRVar8 = this->Sync;
    if (pRVar8 != (RGE_Communications_Synchronize *)0x0) {
      RGE_Communications_Synchronize::~RGE_Communications_Synchronize(pRVar8);
      operator_delete(pRVar8);
    }
    pRVar7 = (RGE_Communications_Speed *)operator_new(0x240);
    local_4 = 0;
    if (pRVar7 == (RGE_Communications_Speed *)0x0) {
      pRVar7 = (RGE_Communications_Speed *)0x0;
    }
    else {
      pRVar7 = (RGE_Communications_Speed *)
               RGE_Communications_Speed::RGE_Communications_Speed(pRVar7,this);
    }
    local_4 = 0xffffffff;
    this->Speed = pRVar7;
    pRVar8 = (RGE_Communications_Synchronize *)operator_new(0x7ec);
    local_4 = 1;
    if (pRVar8 == (RGE_Communications_Synchronize *)0x0) {
      pRVar8 = (RGE_Communications_Synchronize *)0x0;
    }
    else {
      pRVar8 = (RGE_Communications_Synchronize *)
               RGE_Communications_Synchronize::RGE_Communications_Synchronize(pRVar8,this);
    }
    this->Sync = pRVar8;
    pTVar12 = (TDebuggingLog *)&this->SessionGUID;
    local_4 = 0xffffffff;
    ((_GUID *)pTVar12)->Data1 = (this->NullGUID).Data1;
    uVar3 = (this->NullGUID).Data3;
    (this->SessionGUID).Data2 = (this->NullGUID).Data2;
    (this->SessionGUID).Data3 = uVar3;
    *(undefined4 *)(this->SessionGUID).Data4 = *(undefined4 *)(this->NullGUID).Data4;
    *(undefined4 *)((this->SessionGUID).Data4 + 4) = *(undefined4 *)((this->NullGUID).Data4 + 4);
    break;
  case SESSION_HOSTED:
    TDebuggingLog::Log(L,(char *)L,s_UNLINK_SerssionHosted);
    uVar3 = this->MaxGamePlayers;
    this->MeHost = 0;
    (this->PlayerOptions).HostPlayerNumber = 0;
    (this->PlayerOptions).HighPlayerNumber = uVar3;
    (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    (this->PlayerOptions).CommandTurnIncrement = '\x02';
    this->current_turn = 4;
    (this->PlayerOptions).CurrentTurn = 4;
    this->HaveHostInit = 0;
    CloseSession(this);
    TDebuggingLog::Log(this_04,(char *)L,s_Initialize_Player_List);
    uVar13 = 1;
    if (this->MaxGamePlayers != 0) {
      do {
        InitPlayerInformation(this,uVar13,0,&s__,&s__);
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 <= (int)(uint)this->MaxGamePlayers);
    }
    pTVar4 = this->Chat;
    (this->PlayerOptions).NeedsToBeSent = '\0';
    (this->PlayerOptions).LastSentTime = 0;
    TChat::ClearChat(pTVar4);
    DAT_0062cf04 = 0;
    bVar2 = (this->PlayerOptions).CommandTurnIncrement;
    pRVar7 = this->Speed;
    this->Me = 0;
    this->current_turn = bVar2 + 2;
    (this->PlayerOptions).GameHasStarted = 0;
    this->ShuttingDown = 0;
    if (pRVar7 != (RGE_Communications_Speed *)0x0) {
      RGE_Communications_Speed::~RGE_Communications_Speed(pRVar7);
      operator_delete(pRVar7);
    }
    pRVar8 = this->Sync;
    if (pRVar8 != (RGE_Communications_Synchronize *)0x0) {
      RGE_Communications_Synchronize::~RGE_Communications_Synchronize(pRVar8);
      operator_delete(pRVar8);
    }
    pRVar7 = (RGE_Communications_Speed *)operator_new(0x240);
    local_4 = 2;
    if (pRVar7 == (RGE_Communications_Speed *)0x0) {
      pRVar7 = (RGE_Communications_Speed *)0x0;
    }
    else {
      pRVar7 = (RGE_Communications_Speed *)
               RGE_Communications_Speed::RGE_Communications_Speed(pRVar7,this);
    }
    local_4 = 0xffffffff;
    this->Speed = pRVar7;
    pRVar8 = (RGE_Communications_Synchronize *)operator_new(0x7ec);
    local_4 = 3;
    if (pRVar8 == (RGE_Communications_Synchronize *)0x0) {
      local_4 = 0xffffffff;
      this->Sync = (RGE_Communications_Synchronize *)0x0;
      pTVar12 = extraout_ECX_01;
    }
    else {
      pRVar8 = (RGE_Communications_Synchronize *)
               RGE_Communications_Synchronize::RGE_Communications_Synchronize(pRVar8,this);
      local_4 = 0xffffffff;
      this->Sync = pRVar8;
      pTVar12 = extraout_ECX_02;
    }
    break;
  default:
    pcVar16 = s_UNLINK_Unknown;
    pTVar12 = L;
    goto LAB_0042c553;
  case PLAYER_CREATED:
    TDebuggingLog::Log(this_00,(char *)L,s_UNLINK_PlayerCreated);
    DestroyMyPlayer(this);
    this->Me = 0;
    DAT_0062cf04 = 0;
    RGE_Communications_Queue::FlushAll(this->InQ);
    this->ShuttingDown = 0;
    pTVar12 = extraout_ECX_03;
    break;
  case COMM_SETTINGS_EXCHANGED:
    TDebuggingLog::Log(this_00,(char *)L,s_UNLINK_CommSettingsExcahanged);
    ReleaseSettings(this);
    ResetLastCommunicationTimes(this);
    this->ShuttingDown = 0;
    pTVar12 = extraout_ECX_06;
    break;
  case GAME_PLAYER_SET:
    TDebuggingLog::Log(L,(char *)L,s_UNLINK_PlayerSet);
    pTVar12 = extraout_ECX_04;
LAB_0042c45e:
    this->Me = 0;
    DAT_0062cf04 = 0;
    this->ShuttingDown = 0;
    break;
  case GAME_OPTIONS_EXCHANGED:
    TDebuggingLog::Log(this_00,(char *)L,s_UNLINK_GameOptionsExchanged);
    FreeOptions(this);
    (this->PlayerOptions).NeedsToBeSent = '\0';
    this->ShuttingDown = 0;
    pTVar12 = extraout_ECX_05;
    break;
  case GAME_IS_LOADING:
    (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    TDebuggingLog::Log(L,(char *)L,s_UNLINK_GameIsLoading);
    this->ShuttingDown = 0;
    pTVar12 = extraout_ECX_07;
    break;
  case GAME_IS_RUNNING:
    TChat::ClearChat(this->Chat);
    TDebuggingLog::Log(this_05,(char *)L,s_UNLINK_GameIsRunning);
    this->LastTimeoutMessageTime = 0;
    RGE_Communications_Queue::FlushAll(this->InQ);
    (this->PlayerOptions).GameHasStarted = 0;
    this->ShuttingDown = 0;
    pTVar12 = extraout_ECX_08;
    break;
  case GAME_IS_PAUSED:
    pcVar16 = s_UNLINK_GameIsPaused;
LAB_0042c553:
    TDebuggingLog::Log(pTVar12,(char *)L,pcVar16);
    pTVar12 = extraout_ECX_09;
  }
  TDebuggingLog::Log(pTVar12,(char *)L,s_Level_is_now_____d_,
                     this->CommunicationsStatus - INITIALIZED);
  CVar9 = AnalyzeCommunicationsStatus(this);
  *unaff_FS_OFFSET = local_c;
  return CVar9;
}

// --------------------------------------------------

// Function: UnlinkToLevel
// Address: 0042c5d0
// [HELPER] s_AFTER_UNLINKING___Status__d___Re: "AFTER UNLINKING...Status=%d   Reported=%d"
// [HELPER] s_Unlink_from_level____d___Failed_: "Unlink from level [ %d ] Failed.\n Stopping "
// [HELPER] s_Unlink_to_level__d_desired__curr: "Unlink to level %d desired, currently at level=%d"
/* public: enum COMMSTATUS __thiscall TCommunications_Handler::UnlinkToLevel(enum COMMSTATUS) */

COMMSTATUS __thiscall
TCommunications_Handler::UnlinkToLevel(TCommunications_Handler *this,COMMSTATUS param_1)
{
  COMMSTATUS CVar1;
  COMMSTATUS CVar2;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  
  CVar1 = AnalyzeCommunicationsStatus(this);
  this->CommunicationsStatus = CVar1;
  TDebuggingLog::Log(this_00,(char *)L,s_Unlink_to_level__d_desired__curr,param_1,CVar1);
  if ((int)param_1 < 1) {
    param_1 = INITIALIZED;
  }
  CVar1 = this->CommunicationsStatus;
  CVar2 = CVar1;
  do {
    if ((int)CVar2 <= (int)param_1) {
      CVar1 = this->CommunicationsStatus;
      CVar2 = GetCommunicationsStatus(this);
      TDebuggingLog::Log(this_01,(char *)L,s_AFTER_UNLINKING___Status__d___Re,CVar2,CVar1);
      CVar1 = AnalyzeCommunicationsStatus(this);
      return CVar1;
    }
    CVar2 = UnlinkCurrentLevel(this);
    this->CommunicationsStatus = CVar2;
  } while (CVar2 != CVar1);
  sprintf(this->TBuff,s_Unlink_from_level____d___Failed_,CVar1);
  TDebuggingLog::Log(L,(char *)L,this->TBuff);
  CVar1 = AnalyzeCommunicationsStatus(this);
  return CVar1;
}

// --------------------------------------------------

// Function: AnalyzeCommunicationsStatus
// Address: 0042c690
/* public: enum COMMSTATUS __thiscall TCommunications_Handler::AnalyzeCommunicationsStatus(void) */

COMMSTATUS __thiscall
TCommunications_Handler::AnalyzeCommunicationsStatus(TCommunications_Handler *this)
{
  int iVar1;
  _GUID *p_Var2;
  _GUID *p_Var3;
  bool bVar4;
  
  iVar1 = IsPaused(this);
  if ((iVar1 != 0) && (5 < this->current_turn)) {
    return GAME_IS_PAUSED;
  }
  if ((this->PlayerOptions).ProgramState == COMM_STATE_RUNNING) {
    if (5 < this->current_turn) {
      return GAME_IS_RUNNING;
    }
    if (this->current_turn < 6) {
      return GAME_IS_LOADING;
    }
  }
  if ((this->PlayerOptions).NeedsToBeSent != '\0') {
    return GAME_OPTIONS_EXCHANGED;
  }
  if (DAT_0062cf04 != 0) {
    return PLAYER_CREATED;
  }
  if (this->MeHost != 0) {
    return SESSION_HOSTED;
  }
  iVar1 = 0x10;
  bVar4 = true;
  p_Var2 = &this->SessionGUID;
  p_Var3 = &this->NullGUID;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = (char)p_Var2->Data1 == (char)p_Var3->Data1;
    p_Var2 = (_GUID *)((int)&p_Var2->Data1 + 1);
    p_Var3 = (_GUID *)((int)&p_Var3->Data1 + 1);
  } while (bVar4);
  if (!bVar4) {
    return SESSION_AVAILABLE;
  }
  iVar1 = 0x10;
  bVar4 = true;
  p_Var2 = &this->ServiceGUID;
  p_Var3 = &this->NullGUID;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = (char)p_Var2->Data1 == (char)p_Var3->Data1;
    p_Var2 = (_GUID *)((int)&p_Var2->Data1 + 1);
    p_Var3 = (_GUID *)((int)&p_Var3->Data1 + 1);
  } while (bVar4);
  if (!bVar4) {
    return SERVICE_AVAILABLE;
  }
  if (DAT_0062c5ec == 0) {
    if (this->Multiplayer == 0) {
      return SINGLE_PLAYER - (this->Me != 1);
    }
    return MULTIPLAYER_RESET;
  }
  return CONVERSATION_OPEN;
}

// --------------------------------------------------

// Function: ResetLastCommunicationTimes
// Address: 0042c7a0
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
/* public: void __thiscall TCommunications_Handler::ResetLastCommunicationTimes(void) */

void __thiscall TCommunications_Handler::ResetLastCommunicationTimes(TCommunications_Handler *this)
{
  ulong uVar1;
  ulong *puVar2;
  int iVar3;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1282);
  iVar3 = 1;
  if (this->MaxGamePlayers != 0) {
    puVar2 = this->LastTXPing;
    do {
      puVar2 = puVar2 + 1;
      puVar2[-0x14] = uVar1;
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)(uint)this->MaxGamePlayers);
  }
  return;
}

// --------------------------------------------------

// Function: IsPaused
// Address: 0042c7f0
/* public: int __thiscall TCommunications_Handler::IsPaused(void) */

int __thiscall TCommunications_Handler::IsPaused(TCommunications_Handler *this)
{
  return (uint)((this->PlayerOptions).ProgramState == COMM_STATE_PAUSE);
}

// --------------------------------------------------

// Function: DropAllHostedPlayers
// Address: 0042c800
/* public: void __thiscall TCommunications_Handler::DropAllHostedPlayers(void) */

void __thiscall TCommunications_Handler::DropAllHostedPlayers(TCommunications_Handler *this)
{
  uint uVar1;
  
  if (((this->MeHost != 0) && (this->current_turn < 7)) && (uVar1 = 1, this->MaxGamePlayers != 0)) {
    do {
      Kick(this,uVar1);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= (int)(uint)this->MaxGamePlayers);
  }
  return;
}

// --------------------------------------------------

// Function: LocalResumeGame
// Address: 0042c840
/* protected: void __thiscall TCommunications_Handler::LocalResumeGame(unsigned int) */

void __thiscall TCommunications_Handler::LocalResumeGame(TCommunications_Handler *this,uint param_1)
{
  (this->PlayerOptions).ProgramState = COMM_STATE_RUNNING;
  NotifyWindowParam(this,COMM_RESUME,param_1);
  return;
}

// --------------------------------------------------

// Function: LocalPauseGame
// Address: 0042c860
/* protected: void __thiscall TCommunications_Handler::LocalPauseGame(unsigned int) */

void __thiscall TCommunications_Handler::LocalPauseGame(TCommunications_Handler *this,uint param_1)
{
  (this->PlayerOptions).ProgramState = COMM_STATE_PAUSE;
  NotifyWindowParam(this,COMM_PAUSE,param_1);
  return;
}

// --------------------------------------------------

// Function: SendPauseGame
// Address: 0042c880
// [HELPER] s___: "]\n"
/* protected: void __thiscall TCommunications_Handler::SendPauseGame(int) */

void __thiscall TCommunications_Handler::SendPauseGame(TCommunications_Handler *this,int param_1)
{
  if ((this->Multiplayer != 0) && (this->MeHost != 0)) {
    if (param_1 != 0) {
      TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s___>TX_PAUSE);
      CommOut(this,0,'P',(void *)0x0,0,'\0');
      return;
    }
    TDebuggingLog::Log(L,(char *)L,s___>TX_RESUME);
    CommOut(this,0,'U',(void *)0x0,0,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: TogglePauseGame
// Address: 0042c8f0
/* public: int __thiscall TCommunications_Handler::TogglePauseGame(void) */

int __thiscall TCommunications_Handler::TogglePauseGame(TCommunications_Handler *this)
{
  int iVar1;
  
  if (this->PauseChangePending != 0) {
    return 0;
  }
  iVar1 = IsPaused(this);
  if (iVar1 != 0) {
    RequestResumeGame(this,0);
    return 1;
  }
  RequestPauseGame(this,0);
  return 1;
}

// --------------------------------------------------

// Function: RequestPauseGame
// Address: 0042c930
// [HELPER] s___: "]\n"
/* public: void __thiscall TCommunications_Handler::RequestPauseGame(int) */

void __thiscall TCommunications_Handler::RequestPauseGame(TCommunications_Handler *this,int param_1)
{
  if (this->Multiplayer == 0) {
    LocalPauseGame(this,this->Me);
    return;
  }
  if (this->MeHost != 0) {
    SendPauseGame(this,1);
    LocalPauseGame(this,this->Me);
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s___>TX_REQ_PAUSE);
  CommOut(this,0,'W',(void *)0x0,0,'\0');
  return;
}

// --------------------------------------------------

// Function: RequestResumeGame
// Address: 0042c9a0
// [HELPER] s_Resume_requested: "Resume requested"
// [HELPER] s___: "]\n"
/* public: void __thiscall TCommunications_Handler::RequestResumeGame(int) */

void __thiscall
TCommunications_Handler::RequestResumeGame(TCommunications_Handler *this,int param_1)
{
  if (this->Multiplayer == 0) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Resume_requested);
    LocalResumeGame(this,this->Me);
    return;
  }
  if (this->MeHost != 0) {
    SendPauseGame(this,0);
    LocalResumeGame(this,this->Me);
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s___>TX_REQ_RES);
  CommOut(this,0,'+',(void *)0x0,0,'\0');
  return;
}

// --------------------------------------------------

// Function: SetRandomSeed
// Address: 0042ca20
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
/* public: void __thiscall TCommunications_Handler::SetRandomSeed(int) */

void __thiscall TCommunications_Handler::SetRandomSeed(TCommunications_Handler *this,int param_1)
{
  ulong uVar1;
  
  if (this->MeHost != 0) {
    if (param_1 == -1) {
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1320);
      debug_srand(s_C__msdev_work_age1_x1_Com_hand_c,0x1320,uVar1);
      param_1 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x1321);
    }
    (this->PlayerOptions).RandomSeed = param_1;
    (this->PlayerOptions).NeedsToBeSent = '\x01';
    SendSharedData(this,0);
  }
  return;
}

// --------------------------------------------------

// Function: GetRandomSeed
// Address: 0042ca90
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
/* public: unsigned int __thiscall TCommunications_Handler::GetRandomSeed(void) */

uint __thiscall TCommunications_Handler::GetRandomSeed(TCommunications_Handler *this)
{
  ulong uVar1;
  
  if (this->Multiplayer == 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1336);
    debug_srand(s_C__msdev_work_age1_x1_Com_hand_c,0x1336,uVar1);
    uVar1 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x1337);
    (this->PlayerOptions).RandomSeed = uVar1;
  }
  return (this->PlayerOptions).RandomSeed;
}

// --------------------------------------------------

// Function: WhoAmI
// Address: 0042caf0
/* public: int __thiscall TCommunications_Handler::WhoAmI(void) */

int __thiscall TCommunications_Handler::WhoAmI(TCommunications_Handler *this)
{
  return this->Me;
}

// --------------------------------------------------

// Function: IsHost
// Address: 0042cb00
/* public: int __thiscall TCommunications_Handler::IsHost(void) */

int __thiscall TCommunications_Handler::IsHost(TCommunications_Handler *this)
{
  if (this->Multiplayer != 0) {
    return this->MeHost;
  }
  return 1;
}

// --------------------------------------------------

// Function: GetCommStateStr
// Address: 0042cb20
/* public: char * __thiscall TCommunications_Handler::GetCommStateStr(void) */

char * __thiscall TCommunications_Handler::GetCommStateStr(TCommunications_Handler *this)
{
  return (char *)0x0;
}

// --------------------------------------------------

// Function: GetReadyPlayerStr
// Address: 0042cb30
// [HELPER] s_Ready_________________________: "Ready=                        "
/* public: char * __thiscall TCommunications_Handler::GetReadyPlayerStr(void) */

char * __thiscall TCommunications_Handler::GetReadyPlayerStr(TCommunications_Handler *this)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  PLAYERHUMANITY *pPVar4;
  char *pcVar5;
  char *pcVar6;
  
  uVar2 = 0xffffffff;
  pcVar5 = &s_Ready_________________________;
  do {
    pcVar6 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar6 + -uVar2;
  pcVar6 = (char *)&DAT_0062c5b0;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  uVar3 = 1;
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  if (this->MaxGamePlayers != 0) {
    pPVar4 = (this->PlayerOptions).Humanity;
    do {
      pPVar4 = pPVar4 + 1;
      if (pPVar4[0x13] < this->current_turn) {
        switch(*pPVar4) {
        case ME_ABSENT:
          (&UNK_0062c5b6)[uVar3] = 0x2d;
          break;
        default:
          (&UNK_0062c5b6)[uVar3] = 0x3f;
          break;
        case ME_HUMAN:
          (&UNK_0062c5b6)[uVar3] = 0x57;
          break;
        case ME_COMPUTER:
          (&UNK_0062c5b6)[uVar3] = 0x43;
          break;
        case ME_CYBORG:
          (&UNK_0062c5b6)[uVar3] = 0x58;
          break;
        case ME_VIEWONLY:
          (&UNK_0062c5b6)[uVar3] = 0x56;
        }
      }
      else {
        (&UNK_0062c5b6)[uVar3] = 0x41;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 <= this->MaxGamePlayers);
  }
  return (char *)&DAT_0062c5b0;
}

// --------------------------------------------------

// Function: GetPlayerHumanity
// Address: 0042cc00
/* public: int __thiscall TCommunications_Handler::GetPlayerHumanity(unsigned int) */

int __thiscall
TCommunications_Handler::GetPlayerHumanity(TCommunications_Handler *this,uint param_1)
{
  if ((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) {
    return (this->PlayerOptions).Humanity[param_1];
  }
  return 0;
}

// --------------------------------------------------

// Function: SetPlayerHumanity
// Address: 0042cc30
/* public: void __thiscall TCommunications_Handler::SetPlayerHumanity(unsigned int,enum
   PLAYERHUMANITY) */

void __thiscall
TCommunications_Handler::SetPlayerHumanity
          (TCommunications_Handler *this,uint param_1,PLAYERHUMANITY param_2)
{
  if ((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) {
    (this->PlayerOptions).Humanity[param_1] = param_2;
    UpdatePlayer(this,param_1,1);
    NotifyWindow(this,COMM_UPDATE_PARAMS);
    if ((this->MeHost != 0) && ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW)) {
      (this->PlayerOptions).NeedsToBeSent = '\x01';
      SendSharedData(this,0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: GetActivePlayerCount
// Address: 0042cc90
/* public: int __thiscall TCommunications_Handler::GetActivePlayerCount(void) */

int __thiscall TCommunications_Handler::GetActivePlayerCount(TCommunications_Handler *this)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = IsPlayerHuman(this,uVar3);
    if ((iVar1 != 0) || (iVar1 = IsPlayerComputer(this,uVar3), iVar1 != 0)) {
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 <= (int)(uint)this->MaxGamePlayers);
  return iVar2;
}

// --------------------------------------------------

// Function: IsPlayerHuman
// Address: 0042ccd0
/* public: int __thiscall TCommunications_Handler::IsPlayerHuman(unsigned int) */

int __thiscall TCommunications_Handler::IsPlayerHuman(TCommunications_Handler *this,uint param_1)
{
  PLAYERHUMANITY PVar1;
  
  if (((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) &&
     ((PVar1 = (this->PlayerOptions).Humanity[param_1], PVar1 == ME_HUMAN || (PVar1 == ME_CYBORG))))
{
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: IsPlayerComputer
// Address: 0042cd10
/* public: int __thiscall TCommunications_Handler::IsPlayerComputer(unsigned int) */

int __thiscall TCommunications_Handler::IsPlayerComputer(TCommunications_Handler *this,uint param_1)
{
  if ((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) {
    return (uint)((this->PlayerOptions).Humanity[param_1] == ME_COMPUTER);
  }
  return 0;
}

// --------------------------------------------------

// Function: GetCommInfo
// Address: 0042cd50
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Client: "Client"
// [HELPER] s_Host: "Host"
// [HELPER] s_LastComm__P1___5d__P2___5d__P3__: "LastComm: P1=%-5d  P2=%-5d  P3=%-5d  P4=%-5d P5=%-5d P6=%-5d P7=%-5d P8=%-5d"
// [HELPER] s_P_d_T__6ld____7s___s__TX___0_1f_: "P%d T#%6ld [%.7s] %s  TX: %0.1f  RX: %0.1f"
// [HELPER] s__: "}"
// [HELPER] s__s__DPMsgs_d_: "%s  DPMsgs%d "
// [HELPER] s__s__Speed_Adjusts__d_: "%s  Speed Adjusts=%d "
/* public: char * __thiscall TCommunications_Handler::GetCommInfo(unsigned char) */

char * __thiscall TCommunications_Handler::GetCommInfo(TCommunications_Handler *this,uchar param_1)
{
  float fVar1;
  char cVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  double dVar13;
  double dVar14;
  ulong dwCount;
  int iStack_110;
  int iStack_10c;
  int iStack_108;
  char tmp [255];
  
  iVar9 = 0;
  pcVar12 = (char *)&DAT_0062c6f0;
  if (this->Multiplayer == 0) {
    do {
      uVar6 = 0xffffffff;
      pcVar10 = &s_>;
      do {
        pcVar11 = pcVar10;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar10 + 1;
        cVar2 = *pcVar10;
        pcVar10 = pcVar11;
      } while (cVar2 != '\0');
      uVar6 = ~uVar6;
      pcVar8 = pcVar12 + 0x100;
      pcVar10 = pcVar11 + -uVar6;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar12 = pcVar12 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar12 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
      }
      pcVar12 = pcVar8;
    } while ((int)pcVar8 < 0x62cdf0);
    sprintf();
  }
  else {
    do {
      uVar6 = 0xffffffff;
      pcVar10 = &s__;
      do {
        pcVar11 = pcVar10;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar10 + 1;
        cVar2 = *pcVar10;
        pcVar10 = pcVar11;
      } while (cVar2 != '\0');
      uVar6 = ~uVar6;
      pcVar8 = pcVar12 + 0x100;
      pcVar10 = pcVar11 + -uVar6;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar12 = pcVar12 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar12 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar12 = pcVar12 + 1;
      }
      pcVar12 = pcVar8;
    } while ((int)pcVar8 < 0x62cdf0);
    uVar6 = 0xffffffff;
    pcVar12 = tmp;
    pcVar10 = s_;
    do {
      pcVar11 = pcVar10;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar10 + 1;
      cVar2 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6;
    pcVar10 = tmp;
    pcVar11 = pcVar11 + -uVar6;
    for (uVar7 = uVar6 >> 2; pcVar12 = pcVar12 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
    }
    iVar4 = this->MeHost;
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar12 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar12 = pcVar12 + 1;
    }
    pcVar12 = s_Host;
    if (iVar4 == 0) {
      pcVar12 = &s_Client;
    }
    uVar6 = 0xffffffff;
    do {
      pcVar11 = pcVar12;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar12 + 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar11;
    } while (cVar2 != '\0');
    fVar1 = this->lastRXDataRate;
    uVar6 = ~uVar6;
    pcVar12 = pcVar11 + -uVar6;
    for (uVar7 = uVar6 >> 2; pcVar10 = pcVar10 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
    }
    dVar14 = (double)fVar1;
    dVar13 = (double)this->lastTXDataRate;
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar10 = pcVar10 + 1;
    }
    pcVar12 = GetReadyPlayerStr(this);
    sprintf(&DAT_0062c6f0,s_P_d_T__6ld____7s___s__TX___0_1f_,this->Me,this->current_turn,tmp + 4,
            pcVar12,dVar13,dVar14);
    RGE_Communications_Speed::GetLatencyInfo(this->Speed);
    sprintf();
    RGE_Communications_Speed::GetAdjustmentCount(this->Speed);
    pcVar12 = RGE_Communications_Speed::GetMachineSpeedInfo(this->Speed);
    sprintf(0x62c8f0,s__s__Speed_Adjusts__d_,pcVar12);
    (**(code **)(*DAT_0062c5ec + 0x44))();
    pcVar12 = RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(this->Speed);
    sprintf(0x62c9f0,s__s__DPMsgs_d_,pcVar12);
    RGE_Communications_Speed::GetPlayerSpeedStatusStr(this->Speed,0);
    sprintf();
                    /* language.dll match for 0x1468: "Stone path 5" */
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1468);
    iVar4 = IsPlayerHuman(this,8);
    if ((iVar4 == 0) || (this->Me == 8)) {
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
    }
    else {
      tmp._0_4_ = uVar3 - this->LastPlayerCommunication[8];
    }
    iVar4 = IsPlayerHuman(this,7);
    if ((iVar4 == 0) || (this->Me == 7)) {
      iStack_10c = 0;
    }
    else {
      iStack_10c = uVar3 - this->LastPlayerCommunication[7];
    }
    iVar4 = IsPlayerHuman(this,6);
    if ((iVar4 == 0) || (this->Me == 6)) {
      dwCount = 0;
    }
    else {
      dwCount = uVar3 - this->LastPlayerCommunication[6];
    }
    iVar4 = IsPlayerHuman(this,5);
    if ((iVar4 == 0) || (this->Me == 5)) {
      iStack_110 = 0;
    }
    else {
      iStack_110 = uVar3 - this->LastPlayerCommunication[5];
    }
    iVar4 = IsPlayerHuman(this,4);
    if ((iVar4 == 0) || (this->Me == 4)) {
      iStack_108 = 0;
    }
    else {
      iStack_108 = uVar3 - this->LastPlayerCommunication[4];
    }
    iVar4 = IsPlayerHuman(this,3);
    if ((iVar4 != 0) && (this->Me != 3)) {
      iVar9 = uVar3 - this->LastPlayerCommunication[3];
    }
    iVar4 = IsPlayerHuman(this,2);
    if ((iVar4 == 0) || (this->Me == 2)) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar3 - this->LastPlayerCommunication[2];
    }
    iVar5 = IsPlayerHuman(this,1);
    if ((iVar5 == 0) || (this->Me == 1)) {
      iVar5 = 0;
    }
    else {
      iVar5 = uVar3 - this->LastPlayerCommunication[1];
    }
    sprintf(0x62cbf0,s_LastComm__P1___5d__P2___5d__P3__,iVar5,iVar4,iVar9,iStack_108,iStack_110,
            dwCount,iStack_10c,tmp._0_4_);
  }
  return (char *)(&DAT_0062c6f0 + (uint)(byte)(param_1 - 1) * 0x40);
}

// --------------------------------------------------

// Function: GetPlayerName
// Address: 0042d0e0
/* public: char * __thiscall TCommunications_Handler::GetPlayerName(unsigned int) */

char * __thiscall TCommunications_Handler::GetPlayerName(TCommunications_Handler *this,uint param_1)
{
  if (this->MaxGamePlayers < param_1) {
    return (char *)0x0;
  }
  if (param_1 == this->Me) {
    return this->MyFriendlyName;
  }
  return this->FriendlyName[param_1].Text;
}

// --------------------------------------------------

// Function: UpdatePlayerInformation
// Address: 0042d120
/* public: void __thiscall TCommunications_Handler::UpdatePlayerInformation(unsigned long,char
   *,char *) */

void __thiscall
TCommunications_Handler::UpdatePlayerInformation
          (TCommunications_Handler *this,ulong param_1,char *param_2,char *param_3)
{
  uint uVar1;
  ulong *puVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar1 = (uint)(this->PlayerOptions).LowPlayerNumber;
    uVar3 = (uint)(this->PlayerOptions).HighPlayerNumber;
    if (uVar1 <= uVar3) {
      puVar2 = (this->PlayerOptions).dcoID + uVar1;
      do {
        if (*puVar2 == param_1) goto LAB_0042d155;
        uVar1 = uVar1 + 1;
        puVar2 = puVar2 + 1;
      } while ((int)uVar1 <= (int)uVar3);
    }
  }
  uVar1 = 0;
LAB_0042d155:
  if (uVar1 == 0) {
    InitPlayerInformation(this,0,param_1,param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: IsLobbyLaunched
// Address: 0042d170
/* public: int __thiscall TCommunications_Handler::IsLobbyLaunched(void) */

int __thiscall TCommunications_Handler::IsLobbyLaunched(TCommunications_Handler *this)
{
  int iVar1;
  
  iVar1 = RGE_Lobby::IsLobbyLaunched(this->Lobby);
  return iVar1;
}

// --------------------------------------------------

// Function: LaunchLobbyGame
// Address: 0042d180
// [HELPER] s_Release_count____d: "Release count = %d"
/* WARNING: Variable defined which should be unmapped: NewDPConv */
/* public: int __thiscall TCommunications_Handler::LaunchLobbyGame(void) */

int __thiscall TCommunications_Handler::LaunchLobbyGame(TCommunications_Handler *this)
{
  byte bVar1;
  undefined4 uVar3;
  TDebuggingLog *this_00;
  IDirectPlay3 *NewDPConv;
  char *name;
  DPSESSIONDESC2 test;
  uint uVar2;
  
  name = (char *)0x0;
  bVar1 = RGE_Lobby::CheckForLobbyLaunch(this->Lobby,(IDirectPlay3 **)&name);
  uVar2 = (uint)bVar1;
  if (uVar2 != 0) {
    if (DAT_0062c5ec != (int *)0x0) {
      uVar3 = (**(code **)(*DAT_0062c5ec + 8))(DAT_0062c5ec);
      TDebuggingLog::Log(this_00,(char *)L,s_Release_count____d,uVar3);
    }
    DAT_0062c5ec = (int *)name;
    if (name == (char *)0x0) {
      return (int)name;
    }
    bVar1 = RGE_Lobby::GetSessionInfo(this->Lobby,(DPSESSIONDESC2 *)&test.dwFlags);
    uVar2 = (uint)bVar1;
    if (uVar2 != 0) {
      DebugSessionInformation(this,(DPSESSIONDESC2 *)&test.dwFlags);
    }
    CommGetCaps(this);
    this->Multiplayer = 1;
    DPlayGetSessionDesc(this);
    RGE_Lobby::GetPlayerInfo(this->Lobby,(char **)&test);
    SetMyPlayerName(this,(char *)test.dwSize);
    (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    AddSelfPlayer(this);
    bVar1 = RGE_Lobby::IsThisHost(this->Lobby);
    this->MeHost = (uint)bVar1;
    if (bVar1 != 0) {
      this->Me = 1;
      (this->PlayerOptions).dcoID[1] = DAT_0062cf04;
      (this->PlayerOptions).Humanity[this->Me] = ME_HUMAN;
      this->HaveHostInit = 1;
      (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
      SetRandomSeed(this,rge_base_game->random_game_seed);
                    /* language.dll match for 0x7d1: "Error" */
      this->GTDSerialNo = 0x7d1;
    }
    UpdatePlayers(this);
  }
  this->LobbyLaunched = uVar2;
  return uVar2;
}

// --------------------------------------------------

// Function: InitPlayerInformation
// Address: 0042d2d0
// [HELPER] s_Player__d___ld__is_INITIALIZED_a: "Player %d (%ld) is INITIALIZED as '%s' [%s]."
/* protected: void __thiscall TCommunications_Handler::InitPlayerInformation(unsigned int,unsigned
   long,char *,char *) */

void __thiscall
TCommunications_Handler::InitPlayerInformation
          (TCommunications_Handler *this,uint param_1,ulong param_2,char *param_3,char *param_4)
{
  if ((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) {
    (this->PlayerOptions).PlayerReady[param_1] = 0;
    (this->PlayerOptions).User1[param_1] = 0;
    (this->PlayerOptions).User2[param_1] = 0;
    (this->PlayerOptions).User3[param_1] = 0;
    (this->PlayerOptions).User4[param_1] = 0;
    (this->PlayerOptions).User5[param_1] = 0;
    (this->PlayerOptions).User6[param_1] = 0;
    (this->PlayerOptions).User7[param_1] = 0;
    (this->PlayerOptions).InvalidPlayer[param_1] = '\0';
    this->LastTurnAck[param_1] = 0;
    (this->PlayerOptions).Humanity[param_1] = ME_ABSENT;
    (this->PlayerOptions).dcoID[param_1] = param_2;
    this->PlayerHighSerialNumber[param_1] = 0;
    this->dwFlags = 0;
    this->dwMaxBufferSize = 0;
    this->dwMaxQueueSize = 0;
    this->dwMaxPlayers = 0;
    this->dwHundredBaud = 0;
    this->dwLatency = 0;
    if (this->InQ != (RGE_Communications_Queue *)0x0) {
      RGE_Communications_Queue::FlushForPlayer(this->InQ,param_1);
    }
    TDebuggingLog::Log((TDebuggingLog *)param_4,(char *)L,s_Player__d___ld__is_INITIALIZED_a,param_1
                       ,param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: SetGameTitle
// Address: 0042d3b0
// [HELPER] s__s___s_: "%s [%s]"
/* public: int __thiscall TCommunications_Handler::SetGameTitle(char *) */

int __thiscall TCommunications_Handler::SetGameTitle(TCommunications_Handler *this,char *param_1)
{
  sprintf(this->MyGameTitle,s__s___s_,param_1,this->MyFriendlyName);
  return 1;
}

// --------------------------------------------------

// Function: SetMyPlayerName
// Address: 0042d3e0
// [HELPER] s_Optional_Information: "Optional Information"
/* public: void __thiscall TCommunications_Handler::SetMyPlayerName(char *) */

void __thiscall
TCommunications_Handler::SetMyPlayerName(TCommunications_Handler *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = this->MyFriendlyName;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar4 = &s_Optional_Information;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->MyFormalName;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: SetPlayerName
// Address: 0042d440
/* public: void __thiscall TCommunications_Handler::SetPlayerName(unsigned int,char *) */

void __thiscall
TCommunications_Handler::SetPlayerName(TCommunications_Handler *this,uint param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == this->Me) {
    SetMyPlayerName(this,param_2);
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  uVar3 = uVar2 >> 2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = this->FriendlyName[param_1].Text;
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: SetWindowHandle
// Address: 0042d490
/* public: void * __thiscall TCommunications_Handler::SetWindowHandle(void *) */

void * __thiscall
TCommunications_Handler::SetWindowHandle(TCommunications_Handler *this,void *param_1)
{
  this->HostHWND = param_1;
  return param_1;
}

// --------------------------------------------------

// Function: CreateDirectPlayConversation
// Address: 0042d4a0
// [HELPER] s_Already_have_conversation_: "Already have conversation."
// [HELPER] s_DPCreate: "DPCreate"
// [HELPER] s_Get_glpIDC_returns____ld: "Get glpIDC returns...%ld"
// [HELPER] s_Release__Links__d: "Release: Links=%d"
/* WARNING: Variable defined which should be unmapped: lpIDC */
/* protected: long __thiscall TCommunications_Handler::CreateDirectPlayConversation(void) */

long __thiscall TCommunications_Handler::CreateDirectPlayConversation(TCommunications_Handler *this)
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  int *unaff_EDI;
  IDirectPlay *lpIDC;
  TCommunications_Handler *local_4;
  
  local_4 = this;
  iVar2 = _DirectPlayCreate_12(&this->ServiceGUID,&local_4,0);
  RGE_Comm_Error::ShowReturn(this->Err,iVar2,s_DPCreate);
  if (DAT_0062c5ec != 0) {
    TDebuggingLog::Log(L,(char *)L,s_Already_have_conversation_);
    return -0x7788fffb;
  }
  if (iVar2 != 0) {
    (this->ServiceGUID).Data1 = (this->NullGUID).Data1;
    uVar1 = (this->NullGUID).Data3;
    (this->ServiceGUID).Data2 = (this->NullGUID).Data2;
    (this->ServiceGUID).Data3 = uVar1;
    *(undefined4 *)(this->ServiceGUID).Data4 = *(undefined4 *)(this->NullGUID).Data4;
    *(undefined4 *)((this->ServiceGUID).Data4 + 4) = *(undefined4 *)((this->NullGUID).Data4 + 4);
    return iVar2;
  }
  if (local_4 != (TCommunications_Handler *)0x0) {
    iVar2 = (**(code **)local_4->OptionsChanged)(local_4,&_IID_IDirectPlay3A,&DAT_0062c5ec);
    if (iVar2 != 0) {
      TDebuggingLog::Log(this_00,(char *)L,s_Get_glpIDC_returns____ld,iVar2);
      return iVar2;
    }
    uVar3 = (**(code **)(*unaff_EDI + 8))(unaff_EDI);
    TDebuggingLog::Log(this_01,(char *)L,s_Release__Links__d,uVar3);
  }
  return 0;
}

// --------------------------------------------------

// Function: OpenMultiplayerConnection
// Address: 0042d580
/* public: int __thiscall TCommunications_Handler::OpenMultiplayerConnection(void) */

int __thiscall TCommunications_Handler::OpenMultiplayerConnection(TCommunications_Handler *this)
{
  return -1;
}

// --------------------------------------------------

// Function: CreateMultiplayerGame
// Address: 0042d590
// [HELPER] s_DPCreateConv: "DPCreateConv"
// [HELPER] s_DP_Open_Create: "DP Open Create"
/* WARNING: Variable defined which should be unmapped: dSess2 */
/* public: int __thiscall TCommunications_Handler::CreateMultiplayerGame(void) */

int __thiscall TCommunications_Handler::CreateMultiplayerGame(TCommunications_Handler *this)
{
  TChat *this_00;
  long lVar1;
  int iVar2;
  DPSESSIONDESC2 *pDVar3;
  DPSESSIONDESC2 dSess2;
  
  this_00 = this->Chat;
  this->Multiplayer = 1;
  this->HaveHostInit = 0;
  (this->PlayerOptions).CommandTurnIncrement = '\x02';
  this->current_turn = 4;
  (this->PlayerOptions).CurrentTurn = 4;
  TChat::ClearChat(this_00);
  lVar1 = CreateDirectPlayConversation(this);
  RGE_Comm_Error::ShowReturn(this->Err,lVar1,s_DPCreateConv);
  pDVar3 = &dSess2;
  this->MeHost = 1;
  for (iVar2 = 0x14; pDVar3 = (DPSESSIONDESC2 *)&pDVar3->dwFlags, iVar2 != 0; iVar2 = iVar2 + -1) {
    *(ulong *)pDVar3 = 0;
  }
  dSess2.dwCurrentPlayers = (ulong)this->MaxGamePlayers;
  dSess2.dwFlags = 0x50;
  dSess2.guidApplication._4_4_ = (this->ApplicationGUID).Data1;
  dSess2.field6_0x30 = (DPSESSIONDESC2_u_48)0x1;
  dSess2.guidInstance.Data1 = 0x44;
  dSess2.guidApplication.Data4._0_4_ = *(undefined4 *)&(this->ApplicationGUID).Data2;
  dSess2.guidApplication.Data4._4_4_ = *(undefined4 *)(this->ApplicationGUID).Data4;
  dSess2.dwMaxPlayers = *(ulong *)((this->ApplicationGUID).Data4 + 4);
  dSess2.field7_0x34.lpszPassword = (ushort *)this->MyGameTitle;
  DebugSessionInformation(this,(DPSESSIONDESC2 *)&dSess2.dwFlags);
  iVar2 = (**(code **)(*DAT_0062c5ec + 0x60))(DAT_0062c5ec,&dSess2.dwFlags,2);
  RGE_Comm_Error::ShowReturn(this->Err,iVar2,s_DP_Open_Create);
  if (iVar2 != 0) {
    if (iVar2 == -0x7788ff56) {
      NotifyWindow(this,COMM_NO_LINK);
      return 0;
    }
    (this->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    return 0;
  }
  SetRandomSeed(this,rge_base_game->random_game_seed);
  AddSelfPlayer(this);
  CommGetCaps(this);
  DPlayGetSessionDesc(this);
  this->Me = 1;
  (this->PlayerOptions).HostPlayerNumber = 1;
  (this->PlayerOptions).dcoID[1] = DAT_0062cf04;
  (this->PlayerOptions).Humanity[this->Me] = ME_HUMAN;
  this->HaveHostInit = 1;
  (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
                    /* language.dll match for 0x7d1: "Error" */
  this->GTDSerialNo = 0x7d1;
  UpdatePlayers(this);
  return 1;
}

// --------------------------------------------------

// Function: PackPlayersDown
// Address: 0042d720
// [HELPER] s_Position__d__LOCKED_____Plr__s: "Position %d *LOCKED*.   Plr=%s"
// [HELPER] s__: "}"
/* protected: void __thiscall TCommunications_Handler::PackPlayersDown(void) */

void __thiscall TCommunications_Handler::PackPlayersDown(TCommunications_Handler *this)
{
  char cVar1;
  TDebuggingLog *this_00;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  TDebuggingLog *this_01;
  uint uVar6;
  char *pcVar7;
  int i;
  uint local_c;
  ulong *local_8;
  
  local_c = 1;
  if (this->MaxGamePlayers == 0) {
LAB_0042d946:
    SetSelfPlayer(this);
    return;
  }
  local_8 = (this->PlayerOptions).dcoID;
                    /* language.dll match for 0x80: "Arial" */
  i = 0x80;
LAB_0042d751:
  local_8 = local_8 + 1;
  iVar2 = IsPlayerHuman(this,local_c);
  if ((iVar2 == 0) && (iVar2 = IsPlayerComputer(this,local_c), iVar2 == 0)) {
    uVar6 = local_c;
    if ((int)local_c <= (int)(uint)this->MaxGamePlayers) {
      do {
        iVar2 = IsPlayerHuman(this,uVar6);
        if ((iVar2 != 0) || (iVar2 = IsPlayerComputer(this,uVar6), iVar2 != 0)) {
          uVar4 = 0xffffffff;
          pcVar3 = this->FriendlyName[uVar6].Text;
          goto code_r0x0042d7c9;
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 <= (int)(uint)this->MaxGamePlayers);
    }
  }
  else {
    pcVar3 = GetPlayerName(this,local_c);
    TDebuggingLog::Log(this_01,(char *)L,s_Position__d__LOCKED_____Plr__s,local_c,pcVar3);
  }
  goto LAB_0042d915;
  while( true ) {
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar7;
    if (cVar1 == '\0') break;
code_r0x0042d7c9:
    pcVar7 = pcVar3;
    if (uVar4 == 0) break;
  }
  uVar4 = ~uVar4;
  pcVar3 = pcVar7 + -uVar4;
  pcVar7 = this->FriendlyName->Text + i;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar3 = this->FormalName[uVar6].Text;
  do {
    pcVar7 = pcVar3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar3 = pcVar7 + -uVar4;
  pcVar7 = this->FormalName->Text + i;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  }
  local_8[0xc] = (this->PlayerOptions).PlayerReady[uVar6];
  *local_8 = (this->PlayerOptions).dcoID[uVar6];
  local_8[0x16] = (this->PlayerOptions).User1[uVar6];
  local_8[0x20] = (this->PlayerOptions).User2[uVar6];
  local_8[0x2a] = (this->PlayerOptions).User3[uVar6];
  local_8[0x34] = (this->PlayerOptions).User4[uVar6];
  local_8[0x3e] = (this->PlayerOptions).User5[uVar6];
  local_8[0x48] = (this->PlayerOptions).User6[uVar6];
  local_8[0x52] = (this->PlayerOptions).User7[uVar6];
  local_8[0x5c] = (this->PlayerOptions).Humanity[uVar6];
  this_00 = (TDebuggingLog *)this->LastTurnAck[uVar6];
  local_8[0x6f] = (ulong)this_00;
  local_8[-0x88] = this->LastPlayerCommunication[uVar6];
  TDebuggingLog::Log(this_00,(char *)L,s_Moved__d_>_d,uVar6,local_c);
  pcVar3 = GetPlayerName(this,local_c);
  TDebuggingLog::Log(L,(char *)L,s_Position__d__LOCKED_____Plr__s,local_c,pcVar3);
  InitPlayerInformation(this,uVar6,0,&s__,&s__);
LAB_0042d915:
  local_c = local_c + 1;
  i = i + 0x80;
  if ((int)(uint)this->MaxGamePlayers < (int)local_c) goto LAB_0042d946;
  goto LAB_0042d751;
}

// --------------------------------------------------

// Function: AddSelfPlayer
// Address: 0042d960
// [HELPER] s_Add_SELF_PLAYER: "Add SELF PLAYER"
// [HELPER] s_Adding_player___s_: "Adding player [%s]"
// [HELPER] s_Create_the_player: "Create the player"
// [HELPER] s_Rcvd_DPID_of__d: "Rcvd DPID of %d"
/* WARNING: Variable defined which should be unmapped: names */
/* protected: int __thiscall TCommunications_Handler::AddSelfPlayer(void) */

int __thiscall TCommunications_Handler::AddSelfPlayer(TCommunications_Handler *this)
{
  int iVar1;
  DPNAME names;
  
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Create_the_player);
  names.field3_0xc.lpszLongName = (ushort *)this->MyFriendlyName;
  names.field2_0x8.lpszShortName = (ushort *)0x0;
  names.dwFlags = 0x10;
  TDebuggingLog::Log((TDebuggingLog *)0x0,(char *)L,s_Adding_player___s_,
                     names.field3_0xc.lpszLongName);
  if (DAT_0062c5ec == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_0062c5ec + 0x18))(DAT_0062c5ec,&DAT_0062cf04,&names.dwFlags,0,0,0,0);
  RGE_Comm_Error::ShowReturn(this->Err,iVar1,s_Add_SELF_PLAYER);
  if (iVar1 != 0) {
    CloseSession(this);
    ReleaseComm(this);
    (this->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    return 0;
  }
  TDebuggingLog::Log(L,(char *)L,s_Rcvd_DPID_of__d,DAT_0062cf04);
  GetMyMultiPlayerCaps(this);
  return 1;
}

// --------------------------------------------------

// Function: InitJoinGame
// Address: 0042da50
/* public: long __thiscall TCommunications_Handler::InitJoinGame(void) */

long __thiscall TCommunications_Handler::InitJoinGame(TCommunications_Handler *this)
{
  long lVar1;
  
  TChat::ClearChat(this->Chat);
  this->Multiplayer = 1;
  this->HaveHostInit = 0;
  this->MeHost = 0;
  this->GTDSerialNo = 0;
  lVar1 = CreateDirectPlayConversation(this);
  return lVar1;
}

// --------------------------------------------------

// Function: JoinMultiplayerGame
// Address: 0042da80
// [HELPER] s_JMPG__Create_w_no_valid_glpIDC: "JMPG: Create w/no valid glpIDC"
// [HELPER] s_Join_MP_Game: "Join MP Game"
// [HELPER] s_Open_session_for_JOIN___Session_: "Open session for JOIN  (Session Data1=%ld) "
/* WARNING: Variable defined which should be unmapped: dSess2 */
/* public: int __thiscall TCommunications_Handler::JoinMultiplayerGame(struct _GUID *) */

int __thiscall
TCommunications_Handler::JoinMultiplayerGame(TCommunications_Handler *this,_GUID *param_1)
{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  DPSESSIONDESC2 *pDVar4;
  DPSESSIONDESC2 dSess2;
  
  if (DAT_0062c5ec == (int *)0x0) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_JMPG__Create_w_no_valid_glpIDC);
    return 0;
  }
  pDVar4 = &dSess2;
  for (iVar3 = 0x14; pDVar4 = (DPSESSIONDESC2 *)&pDVar4->dwFlags, iVar3 != 0; iVar3 = iVar3 + -1) {
    *(ulong *)pDVar4 = 0;
  }
  dSess2.dwFlags = 0x50;
  (this->SessionGUID).Data1 = param_1->Data1;
  uVar2 = param_1->Data3;
  (this->SessionGUID).Data2 = param_1->Data2;
  (this->SessionGUID).Data3 = uVar2;
  *(undefined4 *)(this->SessionGUID).Data4 = *(undefined4 *)param_1->Data4;
  uVar1 = *(undefined4 *)(param_1->Data4 + 4);
  this->MeHost = 0;
  *(undefined4 *)((this->SessionGUID).Data4 + 4) = uVar1;
  dSess2.guidInstance._4_4_ = param_1->Data1;
  dSess2.guidInstance.Data4._0_4_ = *(undefined4 *)&param_1->Data2;
  dSess2.guidInstance.Data4._4_4_ = *(undefined4 *)param_1->Data4;
  dSess2.guidApplication.Data1 = *(ulong *)(param_1->Data4 + 4);
  dSess2.guidApplication._4_4_ = (this->ApplicationGUID).Data1;
  dSess2.guidApplication.Data4._0_4_ = *(undefined4 *)&(this->ApplicationGUID).Data2;
  dSess2.guidApplication.Data4._4_4_ = *(undefined4 *)(this->ApplicationGUID).Data4;
  dSess2.dwMaxPlayers = *(ulong *)((this->ApplicationGUID).Data4 + 4);
  TDebuggingLog::Log(L,(char *)L,s_Open_session_for_JOIN___Session_,(this->SessionGUID).Data1);
  iVar3 = (**(code **)(*DAT_0062c5ec + 0x60))(DAT_0062c5ec,&dSess2.dwFlags,1);
  if (iVar3 == -0x7788fea2) {
    RGE_Comm_Error::ShowReturn(this->Err,-0x7788fea2,s_Join_MP_Game);
    return 0;
  }
  if (iVar3 == -0x7788fffb) {
    RGE_Comm_Error::ShowReturn(this->Err,-0x7788fffb,s_Join_MP_Game);
    return 0;
  }
  if (iVar3 == -0x7788feb6) {
    RGE_Comm_Error::ShowReturn(this->Err,-0x7788feb6,s_Join_MP_Game);
    NotifyWindow(this,COMM_NO_NEW_PLAYERS);
    return 0;
  }
  if (iVar3 != 0) {
    RGE_Comm_Error::ShowReturn(this->Err,iVar3,s_Join_MP_Game);
    (this->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    return 0;
  }
  iVar3 = AddSelfPlayer(this);
  if (iVar3 == 0) {
    return 0;
  }
  (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
  return 1;
}

// --------------------------------------------------

// Function: LaunchMultiplayerGame
// Address: 0042dc20
// [HELPER] s_Clear_player_acknowledgements: "Clear player acknowledgements"
// [HELPER] s_HOST_Set_own_serial_to___d: "HOST Set own serial to =%d"
// [HELPER] s_Set_expected_ser__for_player__d_: "Set expected ser# for player %d to %d"
/* public: void __thiscall TCommunications_Handler::LaunchMultiplayerGame(void) */

void __thiscall TCommunications_Handler::LaunchMultiplayerGame(TCommunications_Handler *this)
{
  undefined1 *puVar1;
  TDebuggingLog *this_00;
  ulong *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  EnableNewPlayers(this,DAT_0062c5ec,0);
  (this->PlayerOptions).ProgramState = COMM_STATE_RUNNING;
  CalculatePlayerRange(this);
  uVar5 = 1;
  (this->PlayerOptions).GameHasStarted = 1;
  ClearRXandTX(this);
  PackPlayersDown(this);
  if (this->MaxGamePlayers != 0) {
                    /* language.dll match for 0x7d0: "place holder" */
    uVar3 = 2000;
    puVar4 = this->PlayerHighSerialNumber;
    do {
      puVar4 = puVar4 + 1;
      if (puVar4[0xf] != 0) {
        *puVar4 = uVar3;
        TDebuggingLog::Log((TDebuggingLog *)(uVar3 + 1),(char *)L,s_Set_expected_ser__for_player__d_
                           ,uVar5,(TDebuggingLog *)(uVar3 + 1));
      }
      uVar5 = uVar5 + 1;
      uVar3 = uVar3 + 2000;
    } while (uVar5 <= this->MaxGamePlayers);
  }
  this_00 = (TDebuggingLog *)(this->Me * 2000);
  puVar1 = (undefined1 *)((int)&this_00->Timestamp + 1);
  this->GTDSerialNo = (uint)puVar1;
  TDebuggingLog::Log(this_00,(char *)L,s_HOST_Set_own_serial_to___d,puVar1);
  SendSharedData(this,1);
  this->current_turn = (this->PlayerOptions).CommandTurnIncrement + 1;
  if (this->Multiplayer != 0) {
    TDebuggingLog::Log(L,(char *)L,s_Clear_player_acknowledgements);
    uVar5 = (uint)(this->PlayerOptions).LowPlayerNumber;
    if (uVar5 <= (this->PlayerOptions).HighPlayerNumber) {
      puVar2 = this->LastTurnAck + uVar5;
      do {
        if (uVar5 != this->Me) {
          *puVar2 = 0;
        }
        uVar5 = uVar5 + 1;
        puVar2 = puVar2 + 1;
      } while (uVar5 <= (this->PlayerOptions).HighPlayerNumber);
    }
  }
  ResetLastCommunicationTimes(this);
  NotifyWindow(this,COMM_UPDATE_PARAMS);
  return;
}

// --------------------------------------------------

// Function: GetMyMultiPlayerCaps
// Address: 0042dd70
// [HELPER] s_Enumerated_player_caps___: "Enumerated player caps..."
// [HELPER] s_Get_Player_Caps: "Get Player Caps"
// [HELPER] s_Latency____d: "Latency = %d"
// [HELPER] s_MaxQueueSize__d: "MaxQueueSize=%d"
// [HELPER] s_RGE_Gtd_Delivery__d: "RGE_Gtd Delivery=%d"
/* WARNING: Variable defined which should be unmapped: dpCaps */
/* protected: long __thiscall TCommunications_Handler::GetMyMultiPlayerCaps(void) */

long __thiscall TCommunications_Handler::GetMyMultiPlayerCaps(TCommunications_Handler *this)
{
  int iVar1;
  TDebuggingLog *this_00;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong *puVar2;
  DPCAPS dpCaps;
  
  if (DAT_0062c5ec == (int *)0x0) {
    return -0x7fffbffb;
  }
  puVar2 = &dpCaps.dwFlags;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  dpCaps.dwFlags = 0x28;
  if (DAT_0062cf04 == 0) {
    return -0x7fffbffb;
  }
  dpCaps.dwSize = unaff_ESI;
  iVar1 = (**(code **)(*DAT_0062c5ec + 0x4c))(DAT_0062c5ec,DAT_0062cf04,&dpCaps.dwFlags);
  RGE_Comm_Error::ShowReturn(this->Err,iVar1,s_Get_Player_Caps);
  if (iVar1 != 0) {
    return iVar1;
  }
  this->dwFlags = 1;
  this->dwMaxBufferSize = unaff_EDI;
  this->dwMaxQueueSize = dpCaps.dwSize;
  this->RGE_Guaranteed_Delivery = '\x01';
  this->dwMaxPlayers = dpCaps.dwFlags;
  this->dwHundredBaud = dpCaps.dwMaxBufferSize;
  this->dwLatency = dpCaps.dwMaxQueueSize;
  TDebuggingLog::Log(L,(char *)L,s_Enumerated_player_caps___);
  TDebuggingLog::Log(this_00,(char *)L,s_Latency____d,this->dwLatency);
  TDebuggingLog::Log((TDebuggingLog *)this->dwMaxQueueSize,(char *)L,s_MaxQueueSize__d,
                     (TDebuggingLog *)this->dwMaxQueueSize);
  TDebuggingLog::Log(L,(char *)L,s_RGE_Gtd_Delivery__d,(uint)this->RGE_Guaranteed_Delivery);
  return 0;
}

// --------------------------------------------------

// Function: SetApplicationGUID
// Address: 0042dea0
/* public: void __thiscall TCommunications_Handler::SetApplicationGUID(struct _GUID) */

void __thiscall
TCommunications_Handler::SetApplicationGUID(TCommunications_Handler *this,_GUID param_1)
{
  (this->ApplicationGUID).Data1 = param_1.Data1;
  (this->ApplicationGUID).Data2 = param_1.Data2;
  (this->ApplicationGUID).Data3 = param_1.Data3;
  *(undefined4 *)(this->ApplicationGUID).Data4 = param_1.Data4._0_4_;
  *(undefined4 *)((this->ApplicationGUID).Data4 + 4) = param_1.Data4._4_4_;
  return;
}

// --------------------------------------------------

// Function: GetDPInterface
// Address: 0042ded0
/* public: struct IDirectPlay3 * __thiscall TCommunications_Handler::GetDPInterface(void) */

IDirectPlay3 * __thiscall TCommunications_Handler::GetDPInterface(TCommunications_Handler *this)
{
  return DAT_0062c5ec;
}

// --------------------------------------------------

// Function: SetServiceGUID
// Address: 0042dee0
/* public: void __thiscall TCommunications_Handler::SetServiceGUID(struct _GUID) */

void __thiscall TCommunications_Handler::SetServiceGUID(TCommunications_Handler *this,_GUID param_1)
{
  (this->ServiceGUID).Data1 = param_1.Data1;
  (this->ServiceGUID).Data2 = param_1.Data2;
  (this->ServiceGUID).Data3 = param_1.Data3;
  *(undefined4 *)(this->ServiceGUID).Data4 = param_1.Data4._0_4_;
  *(undefined4 *)((this->ServiceGUID).Data4 + 4) = param_1.Data4._4_4_;
  return;
}

// --------------------------------------------------

// Function: SetSessionGUID
// Address: 0042df10
/* public: void __thiscall TCommunications_Handler::SetSessionGUID(struct _GUID) */

void __thiscall TCommunications_Handler::SetSessionGUID(TCommunications_Handler *this,_GUID param_1)
{
  (this->SessionGUID).Data1 = param_1.Data1;
  (this->SessionGUID).Data2 = param_1.Data2;
  (this->SessionGUID).Data3 = param_1.Data3;
  *(undefined4 *)(this->SessionGUID).Data4 = param_1.Data4._0_4_;
  *(undefined4 *)((this->SessionGUID).Data4 + 4) = param_1.Data4._4_4_;
  return;
}

// --------------------------------------------------

// Function: UpdatePlayers
// Address: 0042df40
/* public: void __thiscall TCommunications_Handler::UpdatePlayers(void) */

void __thiscall TCommunications_Handler::UpdatePlayers(TCommunications_Handler *this)
{
  uint uVar1;
  
  uVar1 = (uint)(this->PlayerOptions).LowPlayerNumber;
  if (uVar1 <= (this->PlayerOptions).HighPlayerNumber) {
    do {
      UpdatePlayer(this,uVar1,0);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= (int)(uint)(this->PlayerOptions).HighPlayerNumber);
  }
  NotifyWindow(this,COMM_UPDATE_PLAYERS);
  return;
}

// --------------------------------------------------

// Function: UpdatePlayer
// Address: 0042df90
// [HELPER] s_COMM_INVALID_P__d_HUMANITY_SETTI: "COMM:INVALID P#%d HUMANITY SETTING %d"
// [HELPER] s_Error: "Error"
// [HELPER] s_Error_: "Error!"
// [HELPER] s_Fatal_error_player_info__ld: "Fatal error player info %ld"
// [HELPER] s_Get_PName_Info: "Get PName Info"
// [HELPER] s_INVALID_PLAYER: "INVALID PLAYER"
// [HELPER] s_INVALID_PLAYER__d___Removing_: "INVALID PLAYER %d.  Removing."
// [HELPER] s_P__d_ABSENT: "P#%d ABSENT"
// [HELPER] s_P__d_CLOSED: "P#%d CLOSED"
// [HELPER] s_P__d_COMPUTER: "P#%d COMPUTER"
// [HELPER] s_P__d_CYBORG: "P#%d CYBORG"
// [HELPER] s_P__d_ELIMINATED: "P#%d ELIMINATED"
// [HELPER] s_P__d_HUMAN: "P#%d HUMAN"
// [HELPER] s_P__d_Not_Defined__updateplayers_: "P#%d Not Defined (updateplayers)."
// [HELPER] s_P__d_VIEWONLY: "P#%d VIEWONLY"
// [HELPER] s_TX_Missing_Player_report_for_pla: "TX Missing Player report for player=%d "
// [HELPER] s_Unknown_fail_on_updateplayers: "Unknown fail on updateplayers"
// [HELPER] s___: "]\n"
/* WARNING: Variable defined which should be unmapped: lpData */
/* public: void __thiscall TCommunications_Handler::UpdatePlayer(unsigned int,int) */

void __thiscall
TCommunications_Handler::UpdatePlayer(TCommunications_Handler *this,uint param_1,int param_2)
{
  char cVar1;
  TDebuggingLog *pTVar2;
  undefined4 uVar3;
  int iVar4;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  void *lpData;
  MSGFORMAT_MISSING_PLAYER m;
  TCommunications_Handler *pTVar5;
  
  uVar7 = param_1;
  pTVar2 = (TDebuggingLog *)(this->PlayerOptions).dcoID[param_1];
  pTVar5 = this;
  switch((this->PlayerOptions).Humanity[param_1]) {
  case ME_ABSENT:
    pcVar10 = s_P__d_ABSENT;
    goto LAB_0042dfd6;
  case ME_CLOSED:
    pcVar10 = s_P__d_CLOSED;
    goto LAB_0042e2c0;
  case ME_HUMAN:
    pcVar10 = s_P__d_HUMAN;
    break;
  case ME_ELIMINATED:
    pcVar10 = s_P__d_ELIMINATED;
    pTVar5 = (TCommunications_Handler *)L;
LAB_0042dfd6:
    TDebuggingLog::Log((TDebuggingLog *)pTVar5,(char *)L,pcVar10,param_1);
    (this->PlayerOptions).dcoID[uVar7] = 0;
    (this->PlayerOptions).PlayerReady[uVar7] = 0;
    goto LAB_0042e2ea;
  case ME_COMPUTER:
    pcVar10 = s_P__d_COMPUTER;
LAB_0042e2c0:
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,pcVar10,param_1);
    (this->PlayerOptions).dcoID[uVar7] = 0;
    (this->PlayerOptions).PlayerReady[uVar7] = 1;
    goto LAB_0042e2ea;
  case ME_CYBORG:
    pcVar10 = s_P__d_CYBORG;
    pTVar5 = (TCommunications_Handler *)L;
    break;
  case ME_VIEWONLY:
    (this->PlayerOptions).PlayerReady[param_1] = 1;
    pcVar10 = s_P__d_VIEWONLY;
    break;
  default:
    uVar7 = 0xffffffff;
    pcVar10 = &s_Error;
    do {
      pcVar9 = pcVar10;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    uVar8 = uVar7 >> 2;
    pcVar10 = pcVar9 + -uVar7;
    pcVar9 = this->FriendlyName[param_1].Text;
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar9 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar9 = pcVar9 + 1;
    }
    pTVar2 = (TDebuggingLog *)(this->PlayerOptions).Humanity[param_1];
    TDebuggingLog::Log(pTVar2,(char *)L,s_COMM_INVALID_P__d_HUMANITY_SETTI,param_1,pTVar2);
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)pTVar5,(char *)L,pcVar10,param_1);
  if (pTVar2 == (TDebuggingLog *)0x0) {
    TDebuggingLog::Log(this_00,(char *)L,s_P__d_Not_Defined__updateplayers_,uVar7);
    return;
  }
  param_1 = 0;
  (**(code **)(*DAT_0062c5ec + 0x54))(DAT_0062c5ec,pTVar2,0,&param_1);
  uVar3 = calloc(m._0_4_,1);
  iVar4 = (**(code **)(*DAT_0062c5ec + 0x54))(DAT_0062c5ec,pTVar2,uVar3,&m);
  RGE_Comm_Error::ShowReturn(this->Err,iVar4,s_Get_PName_Info);
  if (iVar4 < -0x7788ffe1) {
    if ((iVar4 != -0x7788ffe2) && (iVar4 != -0x7ff8ffa9)) {
LAB_0042e0cf:
      TDebuggingLog::Log(this_01,(char *)L,s_Unknown_fail_on_updateplayers);
      (this->PlayerOptions).Humanity[uVar7] = ME_ABSENT;
      (this->PlayerOptions).dcoID[uVar7] = 0;
      free(m._0_4_);
      goto LAB_0042e2ea;
    }
LAB_0042e23d:
    TDebuggingLog::Log(L,(char *)L,s_Fatal_error_player_info__ld,iVar4,uVar3);
    uVar8 = 0xffffffff;
    pcVar10 = &s_Error_;
    do {
      pcVar9 = pcVar10;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar8 = ~uVar8;
    uVar6 = uVar8 >> 2;
    pcVar10 = pcVar9 + -uVar8;
    pcVar9 = this->FriendlyName[uVar7].Text;
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pcVar9 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar9 = pcVar9 + 1;
    }
    (this->PlayerOptions).Humanity[uVar7] = ME_ABSENT;
  }
  else {
    if (iVar4 == -0x7788ff7e) goto LAB_0042e23d;
    if (iVar4 != -0x7788ff6a) {
      if (iVar4 == 0) {
        uVar8 = 0xffffffff;
        pcVar10 = *(char **)(m._0_4_ + 8);
        do {
          pcVar9 = pcVar10;
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar8 = ~uVar8;
        uVar6 = uVar8 >> 2;
        pcVar10 = pcVar9 + -uVar8;
        pcVar9 = this->FriendlyName[uVar7].Text;
        for (; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar9 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar9 = pcVar9 + 1;
        }
        m.PlayerID = (ulong)(this->FormalName + uVar7);
        uVar8 = 0xffffffff;
        pcVar10 = *(char **)(m._0_4_ + 0xc);
        do {
          pcVar9 = pcVar10;
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar8 = ~uVar8;
        pcVar10 = pcVar9 + -uVar8;
        pcVar9 = (char *)m.PlayerID;
        for (uVar6 = uVar8 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar9 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar9 = pcVar9 + 1;
        }
        (this->PlayerOptions).Humanity[uVar7] = ME_HUMAN;
        free(m._0_4_);
        goto LAB_0042e2ea;
      }
      goto LAB_0042e0cf;
    }
    TDebuggingLog::Log(L,(char *)L,s_INVALID_PLAYER__d___Removing_,pTVar2,uVar3);
    if ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
      (this->PlayerOptions).Humanity[uVar7] = ME_HUMAN;
      iVar4 = IsPlayerHuman(this,uVar7);
      if (iVar4 != 0) {
        TDebuggingLog::Log(this_02,(char *)L,s_INVALID_PLAYER);
        TDebuggingLog::Log(this_03,(char *)L,s_TX_Missing_Player_report_for_pla,pTVar2);
        m.PlayerID = CONCAT31(m.PlayerID._1_3_,0x3f);
        TDebuggingLog::Log(pTVar2,(char *)L,s___>TX_MP___d___d_,pTVar2,8);
        FastSend(this,0,&m.PlayerID,8,0,0);
        free(m._0_4_);
        goto LAB_0042e2ea;
      }
    }
  }
  free(m._0_4_);
LAB_0042e2ea:
  if (param_2 == 0) {
    return;
  }
  NotifyWindow(this,COMM_UPDATE_PLAYERS);
  return;
}

// --------------------------------------------------

// Function: SetMyReadiness
// Address: 0042e380
// [HELPER] s_SET_MY_READINESS__P__d_RDY__d_O1: "SET-MY-READINESS: P#%d RDY=%d O1=%d O2=%d O3=%d O4=%d O5=%d O6=%d O7=%d "
// [HELPER] s___: "]\n"
/* WARNING: Variable defined which should be unmapped: rdy */
/* public: int __thiscall TCommunications_Handler::SetMyReadiness(int,unsigned long,unsigned
   long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long) */

int __thiscall
TCommunications_Handler::SetMyReadiness
          (TCommunications_Handler *this,int param_1,ulong param_2,ulong param_3,ulong param_4,
          ulong param_5,ulong param_6,ulong param_7,ulong param_8)
{
  uint uVar1;
  TDebuggingLog *this_00;
  MSGFORMAT_SETREADYOPTIONS rdy;
  
  uVar1 = this->Me;
  this_00 = (TDebuggingLog *)(this->PlayerOptions).User1[uVar1];
  TDebuggingLog::Log(this_00,(char *)L,s_SET_MY_READINESS__P__d_RDY__d_O1,uVar1,
                     (this->PlayerOptions).PlayerReady[uVar1],this_00,
                     (this->PlayerOptions).User2[uVar1],(this->PlayerOptions).User3[uVar1],
                     (this->PlayerOptions).User4[uVar1],(this->PlayerOptions).User5[uVar1],
                     (this->PlayerOptions).User6[uVar1],(this->PlayerOptions).User7[uVar1]);
  (this->PlayerOptions).PlayerReady[this->Me] = param_1;
  (this->PlayerOptions).User1[this->Me] = param_2;
  (this->PlayerOptions).User2[this->Me] = param_3;
  (this->PlayerOptions).User3[this->Me] = param_4;
  (this->PlayerOptions).User4[this->Me] = param_5;
  (this->PlayerOptions).User5[this->Me] = param_6;
  (this->PlayerOptions).User6[this->Me] = param_7;
  (this->PlayerOptions).User7[this->Me] = param_8;
  rdy.User1._1_1_ = (undefined1)param_1;
  rdy.User2 = param_2;
  rdy.User5 = param_5;
  rdy._36_4_ = this->CommunicationsVersionCode;
  rdy.User3 = param_3;
  rdy.User6 = param_6;
  rdy.User4 = param_4;
  rdy.User7 = param_7;
  rdy.CommunicationsVersionCode = param_8;
  rdy.User1._0_1_ = 0x52;
  if (this->MeHost == 0) {
    TDebuggingLog::Log((TDebuggingLog *)CONCAT31((int3)(param_6 >> 8),this->RGE_Guaranteed_Delivery)
                       ,(char *)L,s___>TX_RDY___d_,0x28);
    FastSend(this,0,&rdy.User1,0x28,0,0);
  }
  NotifyWindow(this,COMM_UPDATE_PARAMS);
  return 1;
}

// --------------------------------------------------

// Function: GetClientReadiness
// Address: 0042e500
/* public: int __thiscall TCommunications_Handler::GetClientReadiness(unsigned int,int *,unsigned
   long *,unsigned long *,unsigned long *,unsigned long *,unsigned long *,unsigned long *,unsigned
   long *) */

int __thiscall
TCommunications_Handler::GetClientReadiness
          (TCommunications_Handler *this,uint param_1,int *param_2,ulong *param_3,ulong *param_4,
          ulong *param_5,ulong *param_6,ulong *param_7,ulong *param_8,ulong *param_9)
{
  *param_2 = (this->PlayerOptions).PlayerReady[param_1];
  *param_3 = (this->PlayerOptions).User1[param_1];
  *param_4 = (this->PlayerOptions).User2[param_1];
  *param_5 = (this->PlayerOptions).User3[param_1];
  *param_6 = (this->PlayerOptions).User4[param_1];
  *param_7 = (this->PlayerOptions).User5[param_1];
  *param_8 = (this->PlayerOptions).User6[param_1];
  *param_9 = (this->PlayerOptions).User7[param_1];
  return 1;
}

// --------------------------------------------------

// Function: IsPlayerReady
// Address: 0042e580
/* public: int __thiscall TCommunications_Handler::IsPlayerReady(unsigned int) */

int __thiscall TCommunications_Handler::IsPlayerReady(TCommunications_Handler *this,uint param_1)
{
  if ((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) {
    return (this->PlayerOptions).PlayerReady[param_1];
  }
  return 0;
}

// --------------------------------------------------

// Function: ComputerPlayerGameStart
// Address: 0042e5b0
/* public: int __thiscall TCommunications_Handler::ComputerPlayerGameStart(void) */

int __thiscall TCommunications_Handler::ComputerPlayerGameStart(TCommunications_Handler *this)
{
  if (this->Multiplayer == 0) {
    return 1;
  }
  return (uint)(6 < this->current_turn);
}

// --------------------------------------------------

// Function: MultiplayerGameStart
// Address: 0042e5e0
/* public: int __thiscall TCommunications_Handler::MultiplayerGameStart(void) */

int __thiscall TCommunications_Handler::MultiplayerGameStart(TCommunications_Handler *this)
{
  if (this->Multiplayer == 0) {
    return 1;
  }
  if (6 < this->current_turn) {
    return 1;
  }
  DoCycle(this,0);
  return 0;
}

// --------------------------------------------------

// Function: AllPlayersReady
// Address: 0042e610
/* public: int __thiscall TCommunications_Handler::AllPlayersReady(void) */

int __thiscall TCommunications_Handler::AllPlayersReady(TCommunications_Handler *this)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = (uint)(this->PlayerOptions).LowPlayerNumber;
  if ((this->PlayerOptions).HighPlayerNumber < uVar3) {
    return 1;
  }
  piVar2 = (this->PlayerOptions).PlayerReady + uVar3;
  while( true ) {
    iVar1 = IsPlayerHuman(this,uVar3);
    if ((iVar1 != 0) && (*piVar2 == 0)) break;
    uVar3 = uVar3 + 1;
    piVar2 = piVar2 + 1;
    if ((int)(uint)(this->PlayerOptions).HighPlayerNumber < (int)uVar3) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: DPlayGetSessionDesc
// Address: 0042e670
// [HELPER] s_Get_Session_Desc: "Get Session Desc"
// [HELPER] s_RX_Current_Players__d: "RX Current Players=%d"
/* WARNING: Variable defined which should be unmapped: dwSize */
/* protected: long __thiscall TCommunications_Handler::DPlayGetSessionDesc(void) */

long __thiscall TCommunications_Handler::DPlayGetSessionDesc(TCommunications_Handler *this)
{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_EDI;
  ulong dwSize;
  TCommunications_Handler *local_4;
  
  if (DAT_0062c5ec == (int *)0x0) {
    return -0x7fffbffb;
  }
  local_4 = this;
  (**(code **)(*DAT_0062c5ec + 0x58))(DAT_0062c5ec,0,&local_4);
  iVar3 = calloc(unaff_EDI,1);
  if (iVar3 == 0) {
    return -0x7ff8fff2;
  }
  iVar4 = (**(code **)(*DAT_0062c5ec + 0x58))(DAT_0062c5ec,iVar3,&stack0xfffffff0);
  RGE_Comm_Error::ShowReturn(this->Err,iVar4,s_Get_Session_Desc);
  if (iVar4 == 0) {
    (this->SessionGUID).Data1 = *(ulong *)(iVar3 + 8);
    uVar1 = *(undefined4 *)(iVar3 + 0xc);
    (this->SessionGUID).Data2 = (short)uVar1;
    (this->SessionGUID).Data3 = (short)((uint)uVar1 >> 0x10);
    *(undefined4 *)(this->SessionGUID).Data4 = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)((this->SessionGUID).Data4 + 4) = *(undefined4 *)(iVar3 + 0x14);
    uVar2 = *(ulong *)(iVar3 + 0x2c);
    this->CurrentPlayers = uVar2;
    TDebuggingLog::Log(L,(char *)L,s_RX_Current_Players__d,uVar2);
  }
  free(iVar3);
  return iVar4;
}

// --------------------------------------------------

// Function: CommGetCaps
// Address: 0042e730
// [HELPER] s_Baud_Rate__________d00: "Baud Rate       = %d00"
// [HELPER] s_Get_Caps: "Get Caps"
// [HELPER] s_Get_guaranteed_Caps: "Get guaranteed Caps"
// [HELPER] s_Guaranteed_Optimized_: "Guaranteed Optimized."
// [HELPER] s_Guaranteed_delivery_is_Supported: "Guaranteed delivery is Supported."
// [HELPER] s_Header_Length______d: "Header Length   = %d"
// [HELPER] s_Latency____________d: "Latency         = %d"
// [HELPER] s_Max_Buffer_Size____d: "Max Buffer Size = %d"
// [HELPER] s_Max_Players________d: "Max Players     = %d"
// [HELPER] s_Max_Queue_Size_____d: "Max Queue Size  = %d"
// [HELPER] s_NOT_Guaranteed_Optimized_: "NOT Guaranteed Optimized."
// [HELPER] s_NOT_Guaranteed_Service_: "NOT Guaranteed Service!"
// [HELPER] s_Not_optimized_for_keepalive_: "Not optimized for keepalive."
// [HELPER] s_Not_the_host_: "Not the host."
// [HELPER] s_Optimized_keepalive_detection_: "Optimized keepalive detection."
// [HELPER] s_This_player_is_the_Session_Host_: "This player is the Session Host."
// [HELPER] s_Timeout____________d: "Timeout         = %d"
// [HELPER] s____________Direct_Play_III_Capab: "-----------Direct Play III Capabilities ---------"
/* WARNING: Variable defined which should be unmapped: DPCaps */
/* protected: long __thiscall TCommunications_Handler::CommGetCaps(void) */

long __thiscall TCommunications_Handler::CommGetCaps(TCommunications_Handler *this)
{
  int *piVar1;
  long lVar2;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_03;
  TDebuggingLog *extraout_ECX_01;
  TDebuggingLog *pTVar3;
  ulong unaff_ESI;
  undefined4 unaff_EDI;
  char *pcVar4;
  undefined4 uStack_34;
  DPCAPS DPCaps;
  
  piVar1 = DAT_0062c5ec;
  if (DAT_0062c5ec == (int *)0x0) {
    return -0x7fffbffb;
  }
  uStack_34 = 0;
  DPCaps.dwFlags = 0x28;
  DPCaps.dwSize = unaff_ESI;
  lVar2 = (**(code **)(*DAT_0062c5ec + 0x38))();
  RGE_Comm_Error::ShowReturn(this->Err,lVar2,s_Get_Caps);
  lVar2 = (**(code **)(*DAT_0062c5ec + 0x38))(DAT_0062c5ec,&uStack_34,1);
  RGE_Comm_Error::ShowReturn(this->Err,lVar2,s_Get_guaranteed_Caps);
  TDebuggingLog::Log(this_00,(char *)L,s____________Direct_Play_III_Capab);
  TDebuggingLog::Log((TDebuggingLog *)&DPCaps.dwFlags,(char *)L,s_Max_Buffer_Size____d,
                     &DPCaps.dwFlags);
  TDebuggingLog::Log(L,(char *)L,s_Max_Queue_Size_____d,uStack_34);
  TDebuggingLog::Log(this_01,(char *)L,s_Max_Players________d,unaff_EDI);
  TDebuggingLog::Log((TDebuggingLog *)DPCaps.dwSize,(char *)L,s_Baud_Rate__________d00,DPCaps.dwSize
                    );
  TDebuggingLog::Log(L,(char *)L,s_Latency____________d,DPCaps.dwFlags);
  TDebuggingLog::Log(this_02,(char *)L,s_Header_Length______d,DPCaps.dwMaxQueueSize);
  TDebuggingLog::Log((TDebuggingLog *)DPCaps.dwMaxPlayers,(char *)L,s_Timeout____________d,
                     DPCaps.dwMaxPlayers);
  this->ServiceTimeout = DPCaps.dwMaxPlayers;
  if (((uint)piVar1 & 0x20) == 0) {
    pcVar4 = s_NOT_Guaranteed_Optimized_;
    pTVar3 = extraout_ECX;
  }
  else {
    pcVar4 = s_Guaranteed_Optimized_;
    pTVar3 = L;
  }
  TDebuggingLog::Log(pTVar3,(char *)L,pcVar4);
  if (((uint)piVar1 & 2) == 0) {
    pcVar4 = s_Not_the_host_;
    pTVar3 = L;
  }
  else {
    pcVar4 = s_This_player_is_the_Session_Host_;
    pTVar3 = extraout_ECX_00;
  }
  TDebuggingLog::Log(pTVar3,(char *)L,pcVar4);
  if (((uint)piVar1 & 0x10) == 0) {
    pcVar4 = s_Not_optimized_for_keepalive_;
  }
  else {
    pcVar4 = s_Optimized_keepalive_detection_;
  }
  TDebuggingLog::Log(this_03,(char *)L,pcVar4);
  if (((uint)piVar1 & 0x40) == 0) {
    pcVar4 = s_NOT_Guaranteed_Service_;
    pTVar3 = extraout_ECX_01;
  }
  else {
    pcVar4 = s_Guaranteed_delivery_is_Supported;
    pTVar3 = L;
  }
  TDebuggingLog::Log(pTVar3,(char *)L,pcVar4);
  this->RGE_Guaranteed_Delivery = '\x01';
  return lVar2;
}

// --------------------------------------------------

// Function: CloseSession
// Address: 0042e920
// [HELPER] s_Close_Session: "Close Session"
// [HELPER] s_Close_Session_Call: "Close Session Call"
/* protected: long __thiscall TCommunications_Handler::CloseSession(void) */

long __thiscall TCommunications_Handler::CloseSession(TCommunications_Handler *this)
{
  RGE_Comm_Error *this_00;
  ushort uVar1;
  int iVar2;
  ulong *puVar3;
  long lVar4;
  
  lVar4 = 0;
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Close_Session_Call);
  if (DAT_0062c5ec != (int *)0x0) {
    lVar4 = (**(code **)(*DAT_0062c5ec + 0x10))(DAT_0062c5ec);
  }
  (this->SessionGUID).Data1 = (this->NullGUID).Data1;
  uVar1 = (this->NullGUID).Data3;
  (this->SessionGUID).Data2 = (this->NullGUID).Data2;
  (this->SessionGUID).Data3 = uVar1;
  *(undefined4 *)(this->SessionGUID).Data4 = *(undefined4 *)(this->NullGUID).Data4;
  this_00 = this->Err;
  *(undefined4 *)((this->SessionGUID).Data4 + 4) = *(undefined4 *)((this->NullGUID).Data4 + 4);
  RGE_Comm_Error::ShowReturn(this_00,lVar4,s_Close_Session);
  iVar2 = 1;
  if (this->MaxGamePlayers != 0) {
    puVar3 = this->LastTurnAck;
    do {
      puVar3 = puVar3 + 1;
      *puVar3 = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 <= (int)(uint)this->MaxGamePlayers);
  }
  return lVar4;
}

// --------------------------------------------------

// Function: ReleaseComm
// Address: 0042e9b0
// [HELPER] s_1_Release_COMM_links__d: "1.Release COMM links=%d"
/* protected: long __thiscall TCommunications_Handler::ReleaseComm(void) */

long __thiscall TCommunications_Handler::ReleaseComm(TCommunications_Handler *this)
{
  ushort uVar1;
  undefined4 uVar2;
  TDebuggingLog *this_00;
  
  if (DAT_0062c5ec != (int *)0x0) {
    uVar2 = (**(code **)(*DAT_0062c5ec + 8))(DAT_0062c5ec);
    TDebuggingLog::Log(this_00,(char *)L,s_1_Release_COMM_links__d,uVar2);
    (this->ServiceGUID).Data1 = (this->NullGUID).Data1;
    uVar1 = (this->NullGUID).Data3;
    (this->ServiceGUID).Data2 = (this->NullGUID).Data2;
    (this->ServiceGUID).Data3 = uVar1;
    *(undefined4 *)(this->ServiceGUID).Data4 = *(undefined4 *)(this->NullGUID).Data4;
    *(undefined4 *)((this->ServiceGUID).Data4 + 4) = *(undefined4 *)((this->NullGUID).Data4 + 4);
    DAT_0062c5ec = (int *)0x0;
  }
  return 0;
}

// --------------------------------------------------

// Function: Kick
// Address: 0042ea10
// [HELPER] s_Sent_to_all___drop_player__d_ID_: "Sent to all - drop player %d ID=%d "
// [HELPER] s___: "]\n"
/* WARNING: Variable defined which should be unmapped: kp */
/* public: int __thiscall TCommunications_Handler::Kick(unsigned int) */

int __thiscall TCommunications_Handler::Kick(TCommunications_Handler *this,uint param_1)
{
  ulong uVar1;
  int iVar2;
  TDebuggingLog *this_00;
  MSGFORMAT_KILL_PLAYER kp;
  
  if (((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) && (DAT_0062c5ec != 0)) {
    iVar2 = IsPlayerHuman(this,param_1);
    if (iVar2 != 0) {
      uVar1 = (this->PlayerOptions).dcoID[param_1];
      if (uVar1 != 0) {
        kp.dcoID = param_1;
        kp.CurrentTurn = uVar1;
        TDebuggingLog::Log((TDebuggingLog *)this->current_turn,(char *)L,
                           s_Sent_to_all___drop_player__d_ID_,param_1,uVar1);
        TDebuggingLog::Log(this_00,(char *)L,s___>TX_KP3__d___d_,param_1,0xc);
        CommOut(this,0,'K',&kp.dcoID,0xc,'\0');
        if (this->PlayerStopTurn[param_1] == 0) {
          DropDeadPlayer(this,param_1,(this->PlayerOptions).dcoID[param_1]);
        }
      }
      NotifyWindow(this,COMM_UPDATE_PLAYERS);
      if ((this->MeHost != 0) && (this->current_turn < 7)) {
        SendSharedData(this,1);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: DestroyMyPlayer
// Address: 0042eb10
// [HELPER] s_Release_Player: "Release Player"
/* protected: long __thiscall TCommunications_Handler::DestroyMyPlayer(void) */

long __thiscall TCommunications_Handler::DestroyMyPlayer(TCommunications_Handler *this)
{
  int iVar1;
  
  if (DAT_0062c5ec == (int *)0x0) {
    return 0;
  }
  if (DAT_0062cf04 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_0062c5ec + 0x24))(DAT_0062c5ec,DAT_0062cf04);
  RGE_Comm_Error::ShowReturn(this->Err,iVar1,s_Release_Player);
  if (iVar1 == 0) {
    DAT_0062cf04 = iVar1;
    this->Me = 0;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: SetMyGameOptions
// Address: 0042eb60
// [HELPER] s_Host_Set_Options_to_size__d: "Host Set Options to size %d"
/* public: int __thiscall TCommunications_Handler::SetMyGameOptions(char *,unsigned long) */

int __thiscall
TCommunications_Handler::SetMyGameOptions(TCommunications_Handler *this,char *param_1,ulong param_2)
{
  char *pcVar1;
  TDebuggingLog *extraout_ECX;
  uint uVar2;
  TDebuggingLog *this_00;
  
  if (2000 < param_2) {
    return 0;
  }
  FreeOptions(this);
  this_00 = extraout_ECX;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    pcVar1 = (char *)operator_new(param_2 + 1);
    this->OptionsData = pcVar1;
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
    for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pcVar1 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pcVar1 = pcVar1 + 4;
    }
    for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar1 = *param_1;
      param_1 = param_1 + 1;
      pcVar1 = pcVar1 + 1;
    }
    (this->PlayerOptions).DataSizeToFollow = param_2;
    this_00 = (TDebuggingLog *)0x0;
  }
  if (this->MeHost != 0) {
    (this->PlayerOptions).NeedsToBeSent = '\x01';
  }
  TDebuggingLog::Log(this_00,(char *)L,s_Host_Set_Options_to_size__d,param_2);
  return 1;
}

// --------------------------------------------------

// Function: GetMyGameOptions
// Address: 0042ebf0
/* public: void * __thiscall TCommunications_Handler::GetMyGameOptions(unsigned long *) */

void * __thiscall
TCommunications_Handler::GetMyGameOptions(TCommunications_Handler *this,ulong *param_1)
{
  *param_1 = (this->PlayerOptions).DataSizeToFollow;
  return this->OptionsData;
}

// --------------------------------------------------

// Function: FreeOptions
// Address: 0042ec10
/* protected: void __thiscall TCommunications_Handler::FreeOptions(void) */

void __thiscall TCommunications_Handler::FreeOptions(TCommunications_Handler *this)
{
  char *pcVar1;
  
  pcVar1 = this->OptionsData;
  if (pcVar1 != (char *)0x0) {
    (this->PlayerOptions).DataSizeToFollow = 0;
    operator_delete(pcVar1);
    this->OptionsData = (char *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: SetHostPlayerNumber
// Address: 0042ecc0
/* protected: void __thiscall TCommunications_Handler::SetHostPlayerNumber(unsigned int) */

void __thiscall
TCommunications_Handler::SetHostPlayerNumber(TCommunications_Handler *this,uint param_1)
{
  (this->PlayerOptions).HostPlayerNumber = param_1;
  return;
}

// --------------------------------------------------

// Function: GetHostPlayerNumber
// Address: 0042ecd0
/* public: unsigned int __thiscall TCommunications_Handler::GetHostPlayerNumber(void) */

uint __thiscall TCommunications_Handler::GetHostPlayerNumber(TCommunications_Handler *this)
{
  return (this->PlayerOptions).HostPlayerNumber;
}

// --------------------------------------------------

// Function: DebugSessionInformation
// Address: 0042ece0
// [HELPER] s_Applicatn_guid_DATA1__u: "Applicatn guid DATA1=%u"
// [HELPER] s_Current_Players_______d: "Current Players     =%d"
// [HELPER] s_Flags_________________d: "Flags               =%d"
// [HELPER] s_Instance_GUID__str____s: "Instance GUID  str  =%s"
// [HELPER] s_Instance_guid__DATA1__u: "Instance guid  DATA1=%u"
// [HELPER] s_Max_Players___________d: "Max Players         =%d"
// [HELPER] s_Reserved_1____________d: "Reserved 1          =%d"
// [HELPER] s_Reserved_2____________d: "Reserved 2          =%d"
// [HELPER] s_Size_DPSESSIONDESC2___d: "Size DPSESSIONDESC2 =%d"
// [HELPER] s_User_1________________d: "User 1              =%d"
// [HELPER] s_User_2________________d: "User 2              =%d"
// [HELPER] s_User_3________________d: "User 3              =%d"
// [HELPER] s_User_4________________d: "User 4              =%d"
// [HELPER] s___Information_in_DPSESSIONDESC2_: "--Information in DPSESSIONDESC2 --"
// [HELPER] s________________DATA2__d: "               DATA2=%d"
// [HELPER] s________________DATA3__d: "               DATA3=%d"
// [HELPER] s________________DATA4__u: "               DATA4=%u"
// [HELPER] s______end____: "--   end  --"
/* WARNING: Variable defined which should be unmapped: wszSPGuid */
/* public: void __thiscall TCommunications_Handler::DebugSessionInformation(struct DPSESSIONDESC2 *)
    */

void __thiscall
TCommunications_Handler::DebugSessionInformation
          (TCommunications_Handler *this,DPSESSIONDESC2 *param_1)
{
  uchar *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *pTVar1;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  TDebuggingLog *this_05;
  TDebuggingLog *this_06;
  TDebuggingLog *this_07;
  ushort wszSPGuid [39];
  
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s___Information_in_DPSESSIONDESC2_);
  TDebuggingLog::Log((TDebuggingLog *)param_1->dwSize,(char *)L,s_Size_DPSESSIONDESC2___d,
                     (TDebuggingLog *)param_1->dwSize);
  TDebuggingLog::Log(L,(char *)L,s_Flags_________________d,param_1->dwFlags);
  TDebuggingLog::Log(this_01,(char *)L,s_Instance_guid__DATA1__u,(param_1->guidInstance).Data1);
  pTVar1 = (TDebuggingLog *)(uint)(param_1->guidInstance).Data2;
  TDebuggingLog::Log(pTVar1,(char *)L,s________________DATA2__d,pTVar1);
  TDebuggingLog::Log(L,(char *)L,s________________DATA3__d,(uint)(param_1->guidInstance).Data3);
  TDebuggingLog::Log(this_02,(char *)L,s________________DATA4__u,(param_1->guidInstance).Data4);
  StringFromGUID(&param_1->guidInstance,wszSPGuid + 2);
  TDebuggingLog::Log(this_03,(char *)L,s_Instance_GUID__str____s,wszSPGuid + 2);
  pTVar1 = (TDebuggingLog *)(param_1->guidApplication).Data1;
  TDebuggingLog::Log(pTVar1,(char *)L,s_Applicatn_guid_DATA1__u,pTVar1);
  TDebuggingLog::Log(L,(char *)L,s________________DATA2__d,(uint)(param_1->guidApplication).Data2);
  TDebuggingLog::Log(this_04,(char *)L,s________________DATA3__d,
                     (uint)(param_1->guidApplication).Data3);
  this_00 = (param_1->guidApplication).Data4;
  TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s________________DATA4__u,this_00);
  TDebuggingLog::Log(L,(char *)L,s_Max_Players___________d,param_1->dwMaxPlayers);
  TDebuggingLog::Log(this_05,(char *)L,s_Current_Players_______d,param_1->dwCurrentPlayers);
  TDebuggingLog::Log((TDebuggingLog *)param_1->dwReserved1,(char *)L,s_Reserved_1____________d,
                     (TDebuggingLog *)param_1->dwReserved1);
  TDebuggingLog::Log(L,(char *)L,s_Reserved_2____________d,param_1->dwReserved2);
  TDebuggingLog::Log(this_06,(char *)L,s_User_1________________d,param_1->dwUser1);
  TDebuggingLog::Log((TDebuggingLog *)param_1->dwUser2,(char *)L,s_User_2________________d,
                     (TDebuggingLog *)param_1->dwUser2);
  TDebuggingLog::Log(L,(char *)L,s_User_3________________d,param_1->dwUser3);
  TDebuggingLog::Log(this_07,(char *)L,s_User_4________________d,param_1->dwUser4);
  TDebuggingLog::Log(L,(char *)L,s______end____);
  return;
}

// --------------------------------------------------

// Function: EnableNewPlayers
// Address: 0042ef00
// [HELPER] s_Released_to_links__d: "Released to links=%d"
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* protected: long __thiscall TCommunications_Handler::EnableNewPlayers(struct IDirectPlay2 *,int)
    */

long __thiscall
TCommunications_Handler::EnableNewPlayers
          (TCommunications_Handler *this,IDirectPlay2 *param_1,int param_2)
{
  long lVar1;
  undefined4 uVar2;
  TDebuggingLog *this_00;
  undefined4 unaff_ESI;
  IDirectPlay2 *pIVar3;
  
  if (param_1 == (IDirectPlay2 *)0x0) {
    return -0x7ff8ffa9;
  }
  pIVar3 = param_1;
  lVar1 = (**(code **)*param_1)(param_1,&_IID_IDirectPlay);
  if (-1 < lVar1) {
    lVar1 = (*(code *)param_1[10])(&param_1,unaff_ESI);
    uVar2 = (**(code **)((int)*pIVar3 + 8))(pIVar3);
    TDebuggingLog::Log(this_00,(char *)L,s_Released_to_links__d,uVar2);
  }
  return lVar1;
}

// --------------------------------------------------

// Function: OutOfSync
// Address: 0042ef60
/* public: void __thiscall TCommunications_Handler::OutOfSync(int,unsigned long) */

void __thiscall
TCommunications_Handler::OutOfSync(TCommunications_Handler *this,int param_1,ulong param_2)
{
  this->OutOfSyncFlag = param_1;
  this->dwStopTime = param_2;
  return;
}

// --------------------------------------------------

// Function: SendZoneMessage
// Address: 0042ef80
// [HELPER] s_NOT_LOBBY_LAUNCHED___EXITING: "NOT LOBBY LAUNCHED.  EXITING"
// [HELPER] s_SendGameOptions: "SendGameOptions"
// [HELPER] s_Sending_zone_message_: "Sending zone message."
// [HELPER] s___: "]\n"
/* public: int __thiscall TCommunications_Handler::SendZoneMessage(char *,unsigned long) */

int __thiscall
TCommunications_Handler::SendZoneMessage(TCommunications_Handler *this,char *param_1,ulong param_2)
{
  int iVar1;
  long lVar2;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  
  iVar1 = IsLobbyLaunched(this);
  if (iVar1 == 0) {
    TDebuggingLog::Log(this_00,(char *)L,s_NOT_LOBBY_LAUNCHED___EXITING);
    return 0;
  }
  TDebuggingLog::Log(L,(char *)L,s_Sending_zone_message_);
  TDebuggingLog::Log(this_01,(char *)L,s___>TX_ZONE_MSG___u_,param_2);
  lVar2 = RGE_Lobby::SendZoneMessage
                    (this->Lobby,param_1,param_2,rge_base_game->prog_info->zone_guid);
  if (lVar2 == 0) {
    return 1;
  }
  RGE_Comm_Error::ShowReturn(this->Err,lVar2,s_SendGameOptions);
  return 0;
}

// --------------------------------------------------

// Function: ForcePlayerEnumeration
// Address: 0042f110
// [HELPER] s_Force_Calling_enumeration_of_pla: "Force Calling enumeration of players."
/* public: void __thiscall TCommunications_Handler::ForcePlayerEnumeration(void) */

void __thiscall TCommunications_Handler::ForcePlayerEnumeration(TCommunications_Handler *this)
{
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Force_Calling_enumeration_of_pla);
  (**(code **)(*DAT_0062c5ec + 0x30))(DAT_0062c5ec,0,EnumPlayersCallback2,this,0);
  return;
}

// --------------------------------------------------

// Function: ForcePlayerDestroyAndCreate
// Address: 0042f140
// [HELPER] s_Create_called_: "Create called."
// [HELPER] s_Force_Self_player_destroy_and_cr: "Force Self player destroy and create!"
/* public: void __thiscall TCommunications_Handler::ForcePlayerDestroyAndCreate(void) */

void __thiscall TCommunications_Handler::ForcePlayerDestroyAndCreate(TCommunications_Handler *this)
{
  TDebuggingLog *this_00;
  
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Force_Self_player_destroy_and_cr);
  (**(code **)(*DAT_0062c5ec + 0x24))(DAT_0062c5ec,DAT_0062cf04);
  DAT_0062cf04 = 0;
  AddSelfPlayer(this);
  TDebuggingLog::Log(this_00,(char *)L,s_Create_called_);
  return;
}

// --------------------------------------------------

// Function: ForceNameChange
// Address: 0042f190
// [HELPER] s_Force_Name_Change: "Force Name Change"
// [HELPER] s_TEMPORARY_NAME: "TEMPORARY NAME"
/* WARNING: Variable defined which should be unmapped: dpn */
/* public: void __thiscall TCommunications_Handler::ForceNameChange(void) */

void __thiscall TCommunications_Handler::ForceNameChange(TCommunications_Handler *this)
{
  DPNAME dpn;
  char test [32];
  
  dpn.dwSize = (ulong)s_Force_Name_Change;
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Force_Name_Change);
  test[0xc] = (char)DAT_005832c4;
  test[0xd] = DAT_005832c4._1_1_;
  test[0xe] = DAT_005832c4._2_1_;
  test[0xf] = DAT_005832c4._3_1_;
  test[8] = (char)DAT_005832c0;
  test[9] = DAT_005832c0._1_1_;
  test[10] = DAT_005832c0._2_1_;
  test[0xb] = DAT_005832c0._3_1_;
  test[0x13] = '\0';
  test[0x14] = '\0';
  test[0x15] = '\0';
  test[0x16] = '\0';
  test[0x17] = '\0';
  test[0x18] = '\0';
  test[0x19] = '\0';
  test[0x1a] = '\0';
  test[0x12] = DAT_005832ca;
  test[0x1b] = '\0';
  test[0x1c] = '\0';
  test[0x1d] = '\0';
  test[0x1e] = '\0';
  test._0_4_ = test + 4;
  test[4] = (char)s_TEMPORARY_NAME;
  test[5] = s_TEMPORARY_NAME._1_1_;
  test[6] = s_TEMPORARY_NAME._2_1_;
  test[7] = s_TEMPORARY_NAME._3_1_;
  stack0xfffffffb = 0;
  test[0x10] = (char)DAT_005832c8;
  test[0x11] = DAT_005832c8._1_1_;
  dpn.dwSize = 2;
  dpn.field3_0xc.lpszLongName = (ushort *)(test + 4);
  dpn.dwFlags = 0x10;
  (**(code **)(*DAT_0062c5ec + 0x78))(DAT_0062c5ec,DAT_0062cf04,&dpn.dwFlags,2);
  return;
}

// --------------------------------------------------

// Function: SetSpeedV1
// Address: 0042f230
/* public: void __thiscall TCommunications_Handler::SetSpeedV1(unsigned long) */

void __thiscall TCommunications_Handler::SetSpeedV1(TCommunications_Handler *this,ulong param_1)
{
  RGE_Communications_Speed::SetV1(this->Speed,param_1);
  return;
}

// --------------------------------------------------

// Function: SetSpeedV2
// Address: 0042f250
/* public: void __thiscall TCommunications_Handler::SetSpeedV2(unsigned long) */

void __thiscall TCommunications_Handler::SetSpeedV2(TCommunications_Handler *this,ulong param_1)
{
  RGE_Communications_Speed::SetV2(this->Speed,param_1);
  return;
}

// --------------------------------------------------

// Function: IsPlayerOutOfSync
// Address: 0042f270
/* public: int __thiscall TCommunications_Handler::IsPlayerOutOfSync(unsigned int,unsigned long) */

int __thiscall
TCommunications_Handler::IsPlayerOutOfSync(TCommunications_Handler *this,uint param_1,ulong param_2)
{
  int iVar1;
  
  iVar1 = RGE_Communications_Synchronize::IsPlayerOutOfSync(this->Sync,param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

