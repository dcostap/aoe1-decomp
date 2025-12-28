// GLOBAL FUNCTIONS PART 1200
// Function: FUN_00426626
// Address: 00426626
// XREFS: None
void __thiscall FUN_00426626(int param_1,ulong param_2)
{
  RGE_Communications_Synchronize::SetLastWorldRandom
            (*(RGE_Communications_Synchronize **)(param_1 + 0x14d8),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00426643
// Address: 00426643
// XREFS: None
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
uint __thiscall FUN_00426643(TCommunications_Handler *param_1,uint param_2)
{
  byte bVar1;
  COMMSTATES CVar2;
  bool bVar3;
  ulong uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *pTVar9;
  TDebuggingLog *this_04;
  int *piVar10;
  ulong *puVar11;
  uint uVar12;
  int iStack_88;
  TDebuggingLog *pTStack_84;
  uint uStack_80;
  uint uStack_7c;
  TDebuggingLog *pTStack_78;
  undefined1 auStack_74 [4];
  int iStack_70;
  uchar uStack_6c;
  uchar uStack_6b;
  undefined1 auStack_64 [100];
  
  if (param_1->Multiplayer == 0) {
    return -(uint)((param_1->PlayerOptions).ProgramState != COMM_STATE_PAUSE);
  }
  if ((uint)param_1->MaxGamePlayers < param_1->Me) {
    return 0;
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x20d);
  if (4999 < uVar4 - DAT_0062cf10) {
    pcVar5 = TCommunications_Handler::GetCommInfo(param_1,'\x06');
    TDebuggingLog::Log(this,(char *)L,pcVar5);
    pcVar5 = TCommunications_Handler::GetCommInfo(param_1,'\x05');
    TDebuggingLog::Log(this_00,(char *)L,pcVar5);
    pcVar5 = TCommunications_Handler::GetCommInfo(param_1,'\x04');
    TDebuggingLog::Log(L,(char *)L,pcVar5);
    pcVar5 = TCommunications_Handler::GetCommInfo(param_1,'\x03');
    TDebuggingLog::Log(this_01,(char *)L,pcVar5);
    pcVar5 = TCommunications_Handler::GetCommInfo(param_1,'\x02');
    TDebuggingLog::Log(this_02,(char *)L,pcVar5);
    pcVar5 = TCommunications_Handler::GetCommInfo(param_1,'\x01');
    TDebuggingLog::Log(L,(char *)L,pcVar5);
    DAT_0062cf10 = uVar4;
  }
  TCommunications_Handler::ReceiveGameMessages(param_1);
  param_1->LastPlayerCommunication[param_1->Me] = uVar4;
  bVar1 = (param_1->PlayerOptions).CommandTurnIncrement;
  uVar4 = param_1->current_turn;
  if (((param_1->Multiplayer != 0) && ((param_1->PlayerOptions).ProgramState != COMM_STATE_JOINNOW))
     && (param_1->LastTurnAck[param_1->Me] != uVar4)) {
    param_1->LastTurnAck[param_1->Me] = uVar4;
    if (6 < param_1->current_turn) {
      uStack_6c = RGE_Communications_Speed::GetHighLatencyCenti(param_1->Speed);
      uVar6 = RGE_Communications_Speed::GetAvgFrameRate(param_1->Speed);
      uStack_6b = (uchar)uVar6;
      RGE_Communications_Speed::SetPlayerTurnSpeed(param_1->Speed,param_1->Me,uStack_6b,uStack_6c);
    }
    `protected:_long___thiscall_TCommunications_Handler::SendAllDoneMsg(unsigned_long)'::__l4::
    LastSentTime = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbf9);
    auStack_74[0] = 0x44;
    iStack_70 = bVar1 + uVar4;
    TDebuggingLog::Log(this_03,(char *)L,s___>TX_DONE___d_,0xc);
    TCommunications_Handler::CommOut(param_1,0,'D',auStack_74,0xc,'\0');
  }
  if (param_1->StepMode != 0) {
    uVar6 = param_1->Steps;
    if (uVar6 == 0) {
      return uVar6;
    }
    param_1->Steps = uVar6 - 1;
  }
  RGE_Communications_Synchronize::DoChecksum(param_1->Sync,param_1->current_turn);
  if ((param_1->OutOfSyncFlag == 1) && (param_1->dwStopTime <= param_2)) {
    TCommunications_Handler::NotifyWindowParam(param_1,COMM_SYNC_ERROR,param_1->dwStopTime);
    return 0;
  }
  uVar6 = RGE_Communications_Speed::BufferFramesRemaining(param_1->Speed);
  if ((uVar6 != 0) && (6 < param_1->current_turn)) {
    uVar6 = RGE_Communications_Speed::BufferTimeToUse(param_1->Speed,param_1->current_turn);
    return uVar6;
  }
  uStack_80 = 0;
  iVar7 = TCommunications_Handler::AllPlayersAcknowledged(param_1);
  CVar2 = (param_1->PlayerOptions).ProgramState;
  if (iVar7 != 0) {
    if (CVar2 != COMM_STATE_RUNNING) {
      return 0;
    }
    RGE_Communications_Speed::ReloadBufferFrames(param_1->Speed);
    pTStack_78 = (TDebuggingLog *)0x0;
    uStack_7c = 0;
    if (param_1->MeHost != 0) {
      RGE_Communications_Speed::AnalyzeGameSpeed(param_1->Speed,(uint *)&pTStack_78,&uStack_7c,1);
    }
    uVar4 = param_1->current_turn + 1;
    param_1->current_turn = uVar4;
    TDebuggingLog::Log(pTStack_78,(char *)L,s_____Starting_Turn__d__WT__d__Fr_,uVar4,param_2,
                       pTStack_78,uStack_7c);
    TCommunications_Handler::CheckPlayerStopTurn(param_1,param_1->current_turn);
    uVar6 = RGE_Communications_Speed::GetBufferGranularityAdjusted(param_1->Speed);
    return uVar6;
  }
  if ((int)CVar2 < 5) {
    return 0;
  }
  RGE_Communications_Speed::WaitingOnAcknowledgement(param_1->Speed);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x259);
  uVar12 = 1;
  pTStack_84 = (TDebuggingLog *)0x0;
  iStack_88 = 0;
  iVar7 = 0;
  pTVar9 = (TDebuggingLog *)0x0;
  uVar6 = 0;
  if (param_1->MaxGamePlayers != 0) {
    puVar11 = param_1->LastPlayerCommunication;
    do {
      puVar11 = puVar11 + 1;
      iVar7 = TCommunications_Handler::IsPlayerHuman(param_1,uVar12);
      if ((iVar7 != 0) && (uVar12 != param_1->Me)) {
        uVar6 = *puVar11;
        iStack_88 = iStack_88 + 1;
        if (uStack_80 <= uVar6) {
          uStack_80 = uVar6;
        }
        uVar6 = uVar4 - uVar6;
        if (60000 < uVar6) {
          pTStack_84 = (TDebuggingLog *)((int)&pTStack_84->Timestamp + 1);
        }
        if ((25000 < uVar6) && (25000 < uVar4 - puVar11[10])) {
          puVar11[10] = uVar4;
          TCommunications_Handler::NotifyWindowParam(param_1,COMM_PLAYER_NOT_RESPONDING,uVar12);
        }
        pTVar9 = (TDebuggingLog *)param_1->current_turn;
        bVar3 = false;
        if ((pTVar9 < (TDebuggingLog *)0x8) && (98000 < uVar6)) {
          TDebuggingLog::Log(pTVar9,(char *)L,s____Timeout_pregrame__turn__d_Pla,pTVar9,uVar6);
          bVar3 = true;
        }
        pTVar9 = (TDebuggingLog *)param_1->current_turn;
        if ((((TDebuggingLog *)&DAT_00000007 < pTVar9) && (0x1da9c < uVar6)) &&
           (param_1->MeHost != 0)) {
          TDebuggingLog::Log(pTVar9,(char *)L,s____Timeout_host__turn__d_PlayerT,pTVar9,uVar6);
          bVar3 = true;
        }
        pTVar9 = (TDebuggingLog *)param_1->current_turn;
        if (((TDebuggingLog *)&DAT_00000007 < pTVar9) && (0x1d6b4 < uVar6)) {
          TDebuggingLog::Log(L,(char *)L,s____Timeout_player__turn__d_Playe,pTVar9,uVar6);
          bVar3 = true;
          pTVar9 = extraout_ECX;
        }
        if (bVar3) {
          TDebuggingLog::Log(pTVar9,(char *)L,s_Player_timed_out_with__d_msec_el,uVar6);
          TDebuggingLog::Log(this_04,(char *)L,s_Recommend_player___d__drop_,uVar12);
          if (param_1->MeHost != 0) {
            TDebuggingLog::Log((TDebuggingLog *)param_1->current_turn,(char *)L,
                               s_Player__d_Turn__d__timeout____d_,uVar12,
                               (TDebuggingLog *)param_1->current_turn,uVar6);
            (**(code **)(rge_base_game->_padding_ + 0x20))(0x4ba,auStack_64,100);
            pcVar5 = param_1->TBuff;
            uVar6 = uVar12;
            pcVar8 = TCommunications_Handler::GetPlayerName(param_1,uVar12);
            sprintf(pcVar5,auStack_64,pcVar8,uVar6);
            if (6 < param_1->current_turn) {
              TCommunications_Handler::SendChatMsgAll(param_1,pcVar5);
            }
            TDebuggingLog::Log(L,(char *)L,pcVar5);
            puVar11[0x56] = 1;
            TCommunications_Handler::Kick(param_1,uVar12);
          }
          *puVar11 = uVar4;
          puVar11[0x14] = uVar4;
        }
      }
      uVar12 = uVar12 + 1;
      iVar7 = iStack_88;
      pTVar9 = pTStack_84;
      uVar6 = uStack_80;
    } while (uVar12 <= param_1->MaxGamePlayers);
  }
  if (iVar7 + 1 == 3) {
    if ((int)pTVar9 < 2) goto LAB_00426c46;
  }
  else if ((int)pTVar9 < (iVar7 + 1) / 2) {
LAB_00426c46:
    uVar12 = param_1->LastTimeoutMessageTime;
    if (param_1->LastTimeoutMessageTime < uVar6) {
      uVar12 = uVar6;
    }
    if (25000 < uVar4 - uVar12) {
      TCommunications_Handler::CheckPingTime(param_1,1);
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x2df);
      param_1->LastTimeoutMessageTime = uVar4;
    }
    RGE_Communications_Speed::Skip(param_1->Speed);
    return 0;
  }
  TDebuggingLog::Log(pTVar9,(char *)L,s_I_Dropped_myself_);
  TCommunications_Handler::NotifyWindowParam(param_1,COMM_PLAYER_DROPPED,param_1->Me);
  uVar12 = 1;
  uVar6 = 1;
  if (param_1->MaxGamePlayers != 0) {
    piVar10 = param_1->WasKicked;
    do {
      piVar10 = piVar10 + 1;
      *piVar10 = 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 <= param_1->MaxGamePlayers);
  }
  TRIBE_World::send_zone_score_info((TRIBE_World *)rge_base_game->world);
  TDebuggingLog::Log(L,(char *)L,s_Initialize_Player_List);
  if (param_1->MaxGamePlayers != 0) {
    do {
      TCommunications_Handler::InitPlayerInformation(param_1,uVar12,0,&s__,&s__);
      uVar12 = uVar12 + 1;
    } while ((int)uVar12 <= (int)(uint)param_1->MaxGamePlayers);
  }
  (param_1->PlayerOptions).NeedsToBeSent = '\0';
  (param_1->PlayerOptions).LastSentTime = 0;
  TCommunications_Handler::UpdatePlayers(param_1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00426d32
// Address: 00426d32
// XREFS: None
undefined4 __thiscall FUN_00426d32(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x149c + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_00426d4e
// Address: 00426d4e
// XREFS: None
// [HELPER] s_Send_Player_Name: "Send Player Name"
long __fastcall FUN_00426d4e(int param_1)
{
  long lVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  int iStack_4;
  
  uStack_c = 0;
  iStack_4 = param_1 + 0x1179;
  iStack_8 = param_1 + 0x10f8;
  uStack_10 = 0x10;
  lVar1 = (**(code **)(*DAT_0062c5ec + 0x78))(DAT_0062c5ec,DAT_0062cf04,&uStack_10,2);
  RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x14e0),lVar1,s_Send_Player_Name);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_00426db9
// Address: 00426db9
// XREFS: None
// [HELPER] s_GTD__RX_Ser__d_From_P__d_T__ld_T: "GTD: RX Ser#%d From P#%d T#%ld ToExecT#%d Cmd=%d '%c' Seq=%d"
void __thiscall
FUN_00426db9(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            uint param_6)
{
  if (*(char *)(param_1 + 0x1514) != '\0') {
    TDebuggingLog::Log(L,(char *)L,s_GTD__RX_Ser__d_From_P__d_T__ld_T,param_2,param_3,
                       *(undefined4 *)(param_1 + 0x10c8),param_4,param_5 & 0xff,param_5 & 0xff,
                       param_6 & 0xff);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00426e0d
// Address: 00426e0d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_MsgWait: "MsgWait"
// [HELPER] s_TX___ld__RX___ld__elapsed___ld__: "TX: %ld  RX: %ld  elapsed: %ld  totTX: %ld  totRX: %ld"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426e0d(TCommunications_Handler *param_1)
{
  ulong uVar1;
  int iVar2;
  TDebuggingLog *this;
  uint uVar3;
  uint auStack_8 [2];
  
  if (param_1->Multiplayer == 0) {
    return;
  }
  if ((DAT_0062c5d0 & 1) == 0) {
    DAT_0062c5d0 = DAT_0062c5d0 | 1;
    DAT_0062cef0 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x396);
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x397);
  uVar3 = uVar1 - DAT_0062cef0;
  if (1000 < uVar3) {
    this = (TDebuggingLog *)(param_1->TXPacketLength - DAT_0062cf18);
    TDebuggingLog::Log(this,(char *)L,s_TX___ld__RX___ld__elapsed___ld__,this,
                       param_1->RXPacketLength - DAT_0062cf14,uVar3,param_1->TXPacketLength,
                       param_1->RXPacketLength);
    auStack_8[1] = 0;
    param_1->lastTXDataRate =
         ((float)(param_1->TXPacketLength - DAT_0062cf18) * ram0x0056f254) / (float)uVar3;
    auStack_8[0] = param_1->RXPacketLength - DAT_0062cf14;
    param_1->lastRXDataRate = ((float)auStack_8[0] * ram0x0056f254) / (float)uVar3;
    DAT_0062cf18 = param_1->TXPacketLength;
    DAT_0062cf14 = param_1->RXPacketLength;
    DAT_0062cef0 = uVar1;
  }
  if (param_1->RGE_Guaranteed_Delivery != '\0') {
    TCommunications_Handler::ExecuteIncoming(param_1);
  }
  if (DAT_0062cf04 == 0) {
LAB_00426f74:
    TCommunications_Handler::GetDPLAYMessages(param_1);
    if (param_1->RGE_Guaranteed_Delivery == '\0') goto LAB_00426f99;
    TCommunications_Handler::ExecuteIncoming(param_1);
  }
  else {
    auStack_8[0] = 0;
    iVar2 = (**(code **)(*DAT_0062c5ec + 0x44))(DAT_0062c5ec,DAT_0062cf04,auStack_8);
    if (iVar2 == 0) {
      if (auStack_8[0] != 0) goto LAB_00426f74;
    }
    else {
      RGE_Comm_Error::ShowReturn(param_1->Err,iVar2,s_MsgWait);
    }
  }
  if (param_1->RGE_Guaranteed_Delivery != '\0') {
    TCommunications_Handler::SendStoredMessages(param_1);
  }
LAB_00426f99:
  TCommunications_Handler::CheckPingTime(param_1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_00426fa9
// Address: 00426fa9
// XREFS: None
void __fastcall FUN_00426fa9(TCommunications_Handler *param_1)
{
  param_1->ShuttingDown = 1;
  TCommunications_Handler::ReceiveGameMessages(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00426fbf
// Address: 00426fbf
// XREFS: None
// [HELPER] s_COMM__RX_P__d_ID__ld__siz__db___: "COMM: RX P#%d ID(%ld) siz=%db   MSG=%d '%c'  timeGetTime=%d"
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Rcv_MSG: "Rcv MSG"
// [HELPER] s_True_overflow__d_requested___Max: "True overflow %d requested.  Max = %d"
// [HELPER] s___: "]\n"
// [HELPER] s_____Receive_Peek_slow____u_msec: "!!! Receive Peek slow - %u msec"
void __fastcall FUN_00426fbf(TCommunications_Handler *param_1)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  uint uVar7;
  ulong *puVar8;
  ulong unaff_EBX;
  ulong unaff_EBP;
  TDebuggingLog *unaff_ESI;
  undefined4 uVar9;
  int *piStack_34;
  undefined4 *puVar10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  ulong uStack_4;
  
  if (DAT_0062c5ec == (int *)0x0) {
    return;
  }
  uStack_8 = 4000;
  pcVar1 = param_1->InCommBuff;
  piStack_34 = (int *)0x426fff;
  uStack_4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x3d4);
  puVar10 = &uStack_c;
  piStack_34 = DAT_0062c5ec;
  uStack_c = 0;
  iVar3 = (**(code **)(*DAT_0062c5ec + 0x44))();
  if (iVar3 == 0) {
    TDebuggingLog::Log(this,(char *)L);
  }
  do {
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x3e1);
    uVar9 = 0;
    iVar3 = (**(code **)(*DAT_0062c5ec + 100))(DAT_0062c5ec,&stack0xffffffe0,&stack0xffffffe4,8);
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x3ec);
    if (0x32 < uVar5 - uVar4) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Receive_Peek_slow____u_msec,uVar5 - uVar4);
    }
    if ((iVar3 == 0) && ((undefined4 *)0xf9f < puVar10)) {
      TDebuggingLog::Log(L,(char *)L,s_True_overflow__d_requested___Max,uVar9,4000);
      return;
    }
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x403);
    iVar3 = (**(code **)(*DAT_0062c5ec + 100))
                      (DAT_0062c5ec,&stack0xffffffc8,&piStack_34,1,pcVar1,&stack0xffffffc4);
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x40c);
    if (0x32 < uVar5 - uVar4) {
      TDebuggingLog::Log(this_01,(char *)L);
    }
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x417);
    if (500 < uVar4) {
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
      RGE_Comm_Error::ShowReturn(param_1->Err,iVar3,s_Rcv_MSG);
      return;
    }
    if (unaff_EBP != 0) {
      uVar6 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
      uVar7 = (uint)(param_1->PlayerOptions).HighPlayerNumber;
      if (uVar6 <= uVar7) {
        puVar8 = (param_1->PlayerOptions).dcoID + uVar6;
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
      uVar6 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
      uVar7 = (uint)(param_1->PlayerOptions).HighPlayerNumber;
      if (uVar6 <= uVar7) {
        puVar8 = (param_1->PlayerOptions).dcoID + uVar6;
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
    param_1->RXPacketLength = (ulong)(unaff_ESI->TBuff + (param_1->RXPacketLength - 0x28));
    param_1->RXPackets = param_1->RXPackets + 1;
    pcVar1[(int)(unaff_ESI->TBuff + -0x28)] = '\0';
    if (unaff_EBP == 0) {
      TCommunications_Handler::EvaluateSystemMessage(param_1,(ulong)unaff_ESI,pcVar1,0,unaff_EBX);
      return;
    }
    TCommunications_Handler::PreprocessMessages
              (param_1,(ulong)unaff_ESI,pcVar1,unaff_EBP,unaff_EBX,0);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004272f3
// Address: 004272f3
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
void __thiscall FUN_004272f3(TCommunications_Handler *param_1,int param_2)
{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  
  if (param_1->Multiplayer != 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x460);
    uVar4 = 1;
    if (param_1->MaxGamePlayers != 0) {
      puVar3 = param_1->LastTXPing;
      do {
        puVar3 = puVar3 + 1;
        iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,uVar4);
        if (((iVar2 != 0) && (uVar4 != param_1->Me)) && ((8000 < uVar1 - *puVar3 || (param_2 != 0)))
           ) {
          TCommunications_Handler::TXPing(param_1,uVar4);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 <= param_1->MaxGamePlayers);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00427381
// Address: 00427381
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s___: "]\n"
bool __thiscall FUN_00427381(TCommunications_Handler *param_1,int param_2)
{
  ulong uVar1;
  long lVar2;
  TDebuggingLog *pTVar3;
  ulong *puVar4;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x470);
  UNK_0062cef4._4_1_ = 0x31;
  pTVar3 = (TDebuggingLog *)param_1->current_turn;
  UNK_0062cef4._8_4_ = uVar1;
  UNK_0062cef4._12_4_ = pTVar3;
  if (param_2 == 0) {
    pTVar3 = (TDebuggingLog *)0x1;
    if (param_1->MaxGamePlayers != 0) {
      puVar4 = param_1->LastTXPing;
      do {
        puVar4 = puVar4 + 1;
        *puVar4 = uVar1;
        pTVar3 = (TDebuggingLog *)((int)&pTVar3->Timestamp + 1);
      } while (pTVar3 <= (TDebuggingLog *)(uint)param_1->MaxGamePlayers);
    }
    uVar1 = 0;
  }
  else {
    param_1->LastTXPing[param_2] = uVar1;
    uVar1 = (param_1->PlayerOptions).dcoID[param_2];
  }
  TDebuggingLog::Log(pTVar3,(char *)L,s___>TX_PING___d___d_,param_2,0xc);
  lVar2 = TCommunications_Handler::FastSend(param_1,uVar1,&UNK_0062cef4.field_0x4,0xc,0,0);
  return lVar2 == 0;
}

// --------------------------------------------------

// Function: FUN_00427439
// Address: 00427439
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s___: "]\n"
bool __fastcall FUN_00427439(TCommunications_Handler *param_1)
{
  long lVar1;
  
  UNK_0062c5d1._7_1_ = 0x33;
  UNK_0062c5d1._11_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x496);
  UNK_0062c5d1._15_4_ = param_1->current_turn;
  TDebuggingLog::Log(L,(char *)L,s___>TX_DEBUG_PING___d___d_,0,0xc);
  lVar1 = TCommunications_Handler::FastSend(param_1,0,&UNK_0062c5d1.field_0x7,0xc,0,0);
  return lVar1 == 0;
}

// --------------------------------------------------

// Function: FUN_004274a3
// Address: 004274a3
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_FastTX: "FastTX"
// [HELPER] s_FastTX_to_invalidparams_ignored: "FastTX to invalidparams ignored"
// [HELPER] s_No_send_to_self_FastTX: "No send-to-self FastTX"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____FastSend_slow____ld_msec: "!!!FastSend slow - %ld msec"
int __thiscall
FUN_004274a3(TCommunications_Handler *param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  TDebuggingLog *this;
  int iVar5;
  int unaff_ESI;
  uint uVar6;
  
  if (param_2 == DAT_0062cf04) {
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_No_send_to_self_FastTX);
    return -0x7fffbffb;
  }
  if (DAT_0062cf04 != 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x4ca);
    iVar2 = (**(code **)(*DAT_0062c5ec + 0x68))(DAT_0062c5ec,DAT_0062cf04,param_2,0,param_3,param_4)
    ;
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x4d3);
    if (0x32 < uVar3 - uVar1) {
      TDebuggingLog::Log(this,(char *)L,s____FastSend_slow____ld_msec,uVar3 - uVar1);
    }
    if (param_2 == 0) {
      uVar6 = 1;
      iVar5 = 0;
      if (param_1->MaxGamePlayers != 0) {
        do {
          iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,uVar6);
          if ((iVar4 != 0) && (uVar6 != param_1->Me)) {
            iVar5 = iVar5 + 1;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 <= param_1->MaxGamePlayers);
      }
    }
    else {
      iVar5 = 1;
    }
    param_1->TXPacketLength = param_1->TXPacketLength + iVar5 * unaff_ESI;
    if (iVar2 != -0x7ff8ffa9) {
      if (iVar2 != 0) {
        RGE_Comm_Error::ShowReturn(param_1->Err,iVar2,s_FastTX);
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

// Function: FUN_004275fb
// Address: 004275fb
// XREFS: None
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
undefined4 __thiscall
FUN_004275fb(TCommunications_Handler *param_1,ulong param_2,byte *param_3,ulong param_4,
            ulong param_5,int param_6)
{
  uint *puVar1;
  byte bVar2;
  COMMSTATES CVar3;
  undefined4 uVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  char *pcVar9;
  ulong *puVar10;
  ulong uVar11;
  TCommunications_Handler *this;
  TDebuggingLog *extraout_ECX;
  uint *puVar12;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_00;
  TDebuggingLog *extraout_ECX_01;
  TDebuggingLog *pTVar13;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  TDebuggingLog *this_05;
  TDebuggingLog *this_06;
  TDebuggingLog *pTVar14;
  TCommunications_Handler *pTVar15;
  TDebuggingLog *pTStack_180;
  undefined4 uStack_17c;
  TDebuggingLog *pTStack_178;
  undefined1 auStack_174 [4];
  int iStack_170;
  uchar uStack_16c;
  uchar uStack_16b;
  char acStack_164 [244];
  undefined1 auStack_70 [12];
  undefined1 auStack_64 [100];
  
  this = param_1;
  if (param_4 != 0) {
    pTVar15 = (TCommunications_Handler *)(uint)(param_1->PlayerOptions).LowPlayerNumber;
    this = (TCommunications_Handler *)(uint)(param_1->PlayerOptions).HighPlayerNumber;
    if (pTVar15 <= this) {
      puVar10 = (param_1->PlayerOptions).dcoID + (int)pTVar15;
      do {
        if (*puVar10 == param_4) goto LAB_00427642;
        pTVar15 = (TCommunications_Handler *)((int)&pTVar15->OptionsChanged + 1);
        puVar10 = puVar10 + 1;
      } while ((int)pTVar15 <= (int)this);
    }
  }
  pTVar15 = (TCommunications_Handler *)0x0;
LAB_00427642:
  if (*param_3 == 0x49) {
    TCommunications_Handler::UnlinkToLevel(param_1,SERVICE_AVAILABLE);
    TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PLAYERS);
    TCommunications_Handler::NotifyWindow(param_1,COMM_PLAYER_KICKED);
    return 1;
  }
  if (pTVar15 == (TCommunications_Handler *)0x0) {
    TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Bad_player___for_ID__d,param_4);
    uStack_17c = *(undefined4 *)(param_3 + 8);
    pTStack_180 = (TDebuggingLog *)CONCAT31(pTStack_180._1_3_,0x41);
    if (DAT_0062cf04 != 0) {
      (**(code **)(*DAT_0062c5ec + 0x68))(DAT_0062c5ec,DAT_0062cf04,param_4,0,&pTStack_180,8);
      param_1->TXPacketLength = param_1->TXPacketLength + 8;
      return 0;
    }
    TDebuggingLog::Log((TDebuggingLog *)0x0,(char *)L,s____BAD_DCOID_0_NO_TX);
    return 0;
  }
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x543);
  param_1->LastPlayerCommunication[(int)pTVar15] = uVar5;
  if (param_4 != 0) {
    pTStack_180 = (TDebuggingLog *)(uint)(param_1->PlayerOptions).LowPlayerNumber;
    pTVar13 = (TDebuggingLog *)(uint)(param_1->PlayerOptions).HighPlayerNumber;
    if (pTStack_180 <= pTVar13) {
      puVar10 = (param_1->PlayerOptions).dcoID + (int)pTStack_180;
      do {
        if (*puVar10 == param_4) goto LAB_0042775d;
        pTStack_180 = (TDebuggingLog *)((int)&pTStack_180->Timestamp + 1);
        puVar10 = puVar10 + 1;
      } while ((int)pTStack_180 <= (int)pTVar13);
    }
  }
  pTStack_180 = (TDebuggingLog *)0x0;
LAB_0042775d:
  puVar1 = (uint *)(param_3 + 8);
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x54d);
  TDebuggingLog::Log(L,(char *)L,s_PREPRO_Byte0___c__from__d__d___s,(int)(char)*param_3,pTStack_180,
                     param_4,*puVar1,uVar5);
  if ((*param_3 == 0x4b) && ((param_1->PlayerOptions).ProgramState == COMM_STATE_JOINNOW)) {
    TDebuggingLog::Log(L,(char *)L,s_KILL_Message_recieved_from__d_to,param_4,
                       *(undefined4 *)(param_3 + 0x10));
    if (*puVar1 == param_1->PlayerHighSerialNumber[(int)pTVar15] + 1) {
      param_1->PlayerHighSerialNumber[(int)pTVar15] = *puVar1;
    }
    TDebuggingLog::Log(L,(char *)L,s___>TX_KP_ACK___d__d___d_,pTVar15,*puVar1,8);
    TCommunications_Handler::TXAcknowledgeMessage(param_1,*puVar1,(uint)pTVar15);
    param_1->PlayerHighSerialNumber[*(int *)(param_3 + 0xc)] = *(int *)(param_3 + 0xc) * 2000;
    if (*(int *)(param_3 + 0x10) == DAT_0062cf04) {
      TCommunications_Handler::NotifyWindow(param_1,COMM_PLAYER_KICKED);
      return 1;
    }
  }
  else {
    pTVar13 = extraout_ECX;
    if (*param_3 == 0x43) {
      puVar12 = (uint *)(param_3 + 0xc);
      if (param_1->RGE_Guaranteed_Delivery == '\0') {
        puVar12 = puVar1;
      }
      bVar2 = (byte)puVar12[4];
      if ((bVar2 != 0) &&
         (CVar3 = (param_1->PlayerOptions).ProgramState, CVar3 != COMM_STATE_JOINNOW)) {
        TDebuggingLog::Log((TDebuggingLog *)((int)puVar12 + 0x11),(char *)L,
                           s_DISCARD__ChtPregame__d_PgmState_,(uint)bVar2,CVar3,
                           (TDebuggingLog *)((int)puVar12 + 0x11));
        return 0;
      }
      pTVar13 = (TDebuggingLog *)(param_1->PlayerOptions).ProgramState;
      TDebuggingLog::Log(pTVar13,(char *)L,s_CHAT__ChtPregame__d_PgmState__d_,(uint)bVar2,pTVar13,
                         (byte *)((int)puVar12 + 0x11));
      pTVar13 = extraout_ECX_00;
    }
    bVar2 = *param_3;
    if (bVar2 == 0x41) {
      TCommunications_Handler::RXAcknowledgeStoredMessage
                (param_1,*(uint *)(param_3 + 4),(uint)pTVar15);
      TCommunications_Handler::PurgeAcknowledgedStoredMessages(param_1);
      return 1;
    }
    if (bVar2 == 0x52) {
      TDebuggingLog::Log(L,(char *)L,s_PLAYER_READY_MSG);
      if (param_1->MeHost != 0) {
        (param_1->PlayerOptions).PlayerReady[(int)pTVar15] = (uint)param_3[1];
        TDebuggingLog::Log(L,(char *)L,s_Rcvd_Ready__d_from_player__d,(uint)param_3[1],pTVar15);
        (param_1->PlayerOptions).User1[(int)pTVar15] = *(ulong *)(param_3 + 4);
        (param_1->PlayerOptions).User2[(int)pTVar15] = *puVar1;
        (param_1->PlayerOptions).User3[(int)pTVar15] = *(ulong *)(param_3 + 0xc);
        (param_1->PlayerOptions).User4[(int)pTVar15] = *(ulong *)(param_3 + 0x10);
        (param_1->PlayerOptions).User5[(int)pTVar15] = *(ulong *)(param_3 + 0x14);
        (param_1->PlayerOptions).User6[(int)pTVar15] = *(ulong *)(param_3 + 0x18);
        (param_1->PlayerOptions).User7[(int)pTVar15] = *(ulong *)(param_3 + 0x1c);
        iVar6 = TCommunications_Handler::IsPlayerHuman(param_1,(uint)pTVar15);
        if (iVar6 == 0) {
          TCommunications_Handler::SetPlayerHumanity(param_1,(uint)pTVar15,ME_HUMAN);
        }
        if ((TDebuggingLog *)param_1->CommunicationsVersionCode ==
            *(TDebuggingLog **)(param_3 + 0x20)) {
          TDebuggingLog::Log(*(TDebuggingLog **)(param_3 + 0x20),(char *)L,
                             s_Communications_versions_for_HOST,pTVar15,
                             (TDebuggingLog *)param_1->CommunicationsVersionCode);
        }
        else {
          TCommunications_Handler::NotifyWindowParam
                    (param_1,COMM_PLAYER_SERVICE_ERROR,(long)pTVar15);
          sprintf(param_1->TBuff,s_Player__d_has_a_different_Commun,pTVar15);
          TDebuggingLog::Log(L,(char *)L,param_1->TBuff);
        }
        (param_1->PlayerOptions).NeedsToBeSent = '\x01';
        TCommunications_Handler::SendSharedData(param_1,0);
        TCommunications_Handler::UpdatePlayer(param_1,(uint)pTVar15,0);
        sprintf(param_1->TBuff,s__Plr_Rdy__P1__d_P2__d_P3__d_P4__,
                (param_1->PlayerOptions).PlayerReady[1],(param_1->PlayerOptions).PlayerReady[2],
                (param_1->PlayerOptions).PlayerReady[3],(param_1->PlayerOptions).PlayerReady[4],
                (param_1->PlayerOptions).PlayerReady[5],(param_1->PlayerOptions).PlayerReady[6],
                (param_1->PlayerOptions).PlayerReady[7],(param_1->PlayerOptions).PlayerReady[8]);
        TDebuggingLog::Log(L,(char *)L,param_1->TBuff);
        TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PLAYERS);
        return 1;
      }
    }
    else {
      if (bVar2 == 0x31) {
        uVar5 = param_1->current_turn;
        pTVar13 = (TDebuggingLog *)param_1->Multiplayer;
        uVar4 = *(undefined4 *)(param_3 + 4);
        bVar2 = (param_1->PlayerOptions).CommandTurnIncrement;
        if (((pTVar13 != (TDebuggingLog *)0x0) &&
            ((param_1->PlayerOptions).ProgramState != COMM_STATE_JOINNOW)) &&
           (pTVar13 = (TDebuggingLog *)(param_1->LastTurnAck + param_1->Me),
           param_1->LastTurnAck[param_1->Me] != uVar5)) {
          pTVar13->Timestamp = uVar5;
          if (6 < param_1->current_turn) {
            uStack_16c = RGE_Communications_Speed::GetHighLatencyCenti(param_1->Speed);
            uVar7 = RGE_Communications_Speed::GetAvgFrameRate(param_1->Speed);
            uStack_16b = (uchar)uVar7;
            RGE_Communications_Speed::SetPlayerTurnSpeed
                      (param_1->Speed,param_1->Me,uStack_16b,uStack_16c);
          }
          `protected:_long___thiscall_TCommunications_Handler::SendAllDoneMsg(unsigned_long)'::__l4
          ::LastSentTime = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbf9);
          auStack_174[0] = 0x44;
          iStack_170 = bVar2 + uVar5;
          TDebuggingLog::Log(this_00,(char *)L,s___>TX_DONE___d_,0xc);
          TCommunications_Handler::CommOut(param_1,0,'D',auStack_174,0xc,'\0');
          pTVar13 = extraout_ECX_01;
        }
        pTStack_178 = (TDebuggingLog *)param_1->current_turn;
        pTStack_180 = (TDebuggingLog *)CONCAT31(pTStack_180._1_3_,0x32);
        uStack_17c = uVar4;
        TDebuggingLog::Log(pTVar13,(char *)L,s___>TX_PONG___d___d_,pTVar15,0xc);
        lVar8 = TCommunications_Handler::FastSend
                          (param_1,(param_1->PlayerOptions).dcoID[(int)pTVar15],&pTStack_180,0xc,0,0
                          );
        RGE_Comm_Error::ShowReturn(param_1->Err,lVar8,s_TX_Ping);
        return 1;
      }
      if (bVar2 == 0x33) {
        uStack_17c = *(undefined4 *)(param_3 + 4);
        pTStack_178 = (TDebuggingLog *)param_1->current_turn;
        pTStack_180 = (TDebuggingLog *)CONCAT31(pTStack_180._1_3_,0x34);
        TDebuggingLog::Log(pTStack_178,(char *)L,s___>TX_DEBUG_PONG___d___d_,pTVar15,0xc);
        lVar8 = TCommunications_Handler::FastSend
                          (param_1,(param_1->PlayerOptions).dcoID[(int)pTVar15],&pTStack_180,0xc,0,0
                          );
        RGE_Comm_Error::ShowReturn(param_1->Err,lVar8,s_TX_Debug_Ping);
        pcVar9 = TCommunications_Handler::GetPlayerName(param_1,(uint)pTVar15);
        sprintf(acStack_164,s_Received_debug_ping_from__s____d,pcVar9,pTVar15);
        TDebuggingLog::Log(L,(char *)L,acStack_164);
        TChat::AddChatMsg(param_1->Chat,s_DEBUG,acStack_164,'\0');
        return 1;
      }
      if (bVar2 == 0x3f) {
        if (param_1->MeHost != 0) {
          uVar5 = *(ulong *)(param_3 + 4);
          if (uVar5 != 0) {
            pTVar14 = (TDebuggingLog *)(uint)(param_1->PlayerOptions).LowPlayerNumber;
            pTVar13 = (TDebuggingLog *)(uint)(param_1->PlayerOptions).HighPlayerNumber;
            if (pTVar14 <= pTVar13) {
              puVar10 = (param_1->PlayerOptions).dcoID + (int)pTVar14;
              do {
                if (*puVar10 == uVar5) goto LAB_00427cca;
                pTVar14 = (TDebuggingLog *)((int)&pTVar14->Timestamp + 1);
                puVar10 = puVar10 + 1;
              } while ((int)pTVar14 <= (int)pTVar13);
            }
          }
          pTVar14 = (TDebuggingLog *)0x0;
LAB_00427cca:
          if ((param_1->PlayerOptions).ProgramState != COMM_STATE_JOINNOW) {
            TDebuggingLog::Log(pTVar13,(char *)L,s_Rcvd_MAX_TX_report_for_player___,pTVar14,uVar5,
                               pTVar15);
            TCommunications_Handler::Kick(param_1,(uint)pTVar14);
            return 1;
          }
          sprintf(param_1->TBuff,s__P__d_reported_P__d__dco__d__was,pTVar15,pTVar14,uVar5);
          TDebuggingLog::Log(this_01,(char *)L,param_1->TBuff);
          TDebuggingLog::Log(*(TDebuggingLog **)(param_3 + 4),(char *)L,
                             s_Rcvd_Missing_Player_report_for_p,pTVar14,
                             *(TDebuggingLog **)(param_3 + 4),pTVar15);
          (param_1->PlayerOptions).PlayerReady[(int)pTVar14] = 0;
          (pTVar14[2].Filename + 0x6c)[(int)param_1] = '\x01';
          (param_1->PlayerOptions).NeedsToBeSent = '\x01';
          return 1;
        }
      }
      else {
        if (bVar2 == 0x32) {
          uVar11 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x672);
          iVar6 = *(int *)(param_3 + 4);
          bVar2 = (param_1->PlayerOptions).CommandTurnIncrement;
          uVar5 = param_1->current_turn;
          if (((param_1->Multiplayer != 0) &&
              ((param_1->PlayerOptions).ProgramState != COMM_STATE_JOINNOW)) &&
             (param_1->LastTurnAck[param_1->Me] != uVar5)) {
            param_1->LastTurnAck[param_1->Me] = uVar5;
            if (6 < param_1->current_turn) {
              uStack_16c = RGE_Communications_Speed::GetHighLatencyCenti(param_1->Speed);
              uVar7 = RGE_Communications_Speed::GetAvgFrameRate(param_1->Speed);
              uStack_16b = (uchar)uVar7;
              RGE_Communications_Speed::SetPlayerTurnSpeed
                        (param_1->Speed,param_1->Me,uStack_16b,uStack_16c);
            }
            `protected:_long___thiscall_TCommunications_Handler::SendAllDoneMsg(unsigned_long)'::
            __l4::LastSentTime = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbf9);
            auStack_174[0] = 0x44;
            iStack_170 = bVar2 + uVar5;
            TDebuggingLog::Log(this_02,(char *)L,s___>TX_DONE___d_,0xc);
            TCommunications_Handler::CommOut(param_1,0,'D',auStack_174,0xc,'\0');
          }
          RGE_Communications_Speed::SetActualLatency(param_1->Speed,(uint)pTVar15,uVar11 - iVar6);
          return 1;
        }
        if (bVar2 == 0x34) {
          uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x68b);
          iVar6 = uVar5 - *(int *)(param_3 + 4);
          pcVar9 = TCommunications_Handler::GetPlayerName(param_1,(uint)pTVar15);
          sprintf(acStack_164,s__s___d_Debug_ping___elapsed__d,pcVar9,pTVar15,iVar6);
          TDebuggingLog::Log(this_03,(char *)L,acStack_164);
          TChat::AddChatMsg(param_1->Chat,s_DEBUG,acStack_164,'\0');
          return 1;
        }
        if (bVar2 == 0x59) {
          if ((param_1->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
            param_1->PlayerHighSerialNumber[(int)pTVar15] = *(uint *)(param_3 + 4);
            TCommunications_Handler::ClearRXForPlayer(param_1,(uint)pTVar15);
            TDebuggingLog::Log((TDebuggingLog *)param_1->PlayerHighSerialNumber[(int)pTVar15],
                               (char *)L,s_NOSUCHSERIAL___Setting_P__d_SER_,pTVar15,
                               (TDebuggingLog *)param_1->PlayerHighSerialNumber[(int)pTVar15],
                               *(undefined4 *)(param_3 + 4));
            return 1;
          }
        }
        else {
          if (param_1->RGE_Guaranteed_Delivery == '\0') {
            TCommunications_Handler::LogRXMsg
                      (param_1,*puVar1,(uint)pTVar15,*(ulong *)(param_3 + 4),bVar2,param_3[1]);
            DAT_0062cf20 = param_2 - 8;
            DAT_0062cf1c = puVar1;
          }
          else {
            if (((param_1->IntentionallyDropPackets != 0) && (6 < param_1->current_turn)) &&
               (DAT_0062cf24 = DAT_0062cf24 + 1, 8 < DAT_0062cf24)) {
              (**(code **)(rge_base_game->_padding_ + 0x20))(0x4bc,auStack_64,100);
              sprintf(param_1->TBuff,auStack_70,*puVar1,(int)(char)*param_3,(int)(char)*param_3);
              TDebuggingLog::Log(this_04,(char *)L,param_1->TBuff);
              DAT_0062cf24 = 0;
              return 1;
            }
            if (*param_3 == 0x58) {
              TCommunications_Handler::TXResendReply(param_1,*(uint *)(param_3 + 4),(uint)pTVar15);
              return 1;
            }
            if (param_1->PlayerHighSerialNumber[(int)pTVar15] == 0) {
              TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,
                                 s____First_contact_with_P__d_Next_,pTVar15,(TDebuggingLog *)*puVar1
                                );
              param_1->PlayerHighSerialNumber[(int)pTVar15] = *puVar1 - 1;
            }
            pTVar13 = (TDebuggingLog *)*puVar1;
            pTStack_180 = (TDebuggingLog *)(param_1->PlayerHighSerialNumber[(int)pTVar15] + 1);
            if (pTVar13 < pTStack_180) {
              sprintf(param_1->TBuff,s_GTD__RX_Past_Ser__d_rx__Expected,pTVar13,pTStack_180,pTVar15)
              ;
              TDebuggingLog::Log(this_05,(char *)L,param_1->TBuff);
              TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,s___>TX_R_ACK___d__d___d_,
                                 pTVar15,(TDebuggingLog *)*puVar1,8);
              TCommunications_Handler::TXAcknowledgeMessage(param_1,*puVar1,(uint)pTVar15);
              return 1;
            }
            if (pTStack_180 < pTVar13) {
              param_1->DroppedPacketCount = param_1->DroppedPacketCount + 1;
              sprintf(param_1->TBuff,s_GTD__RX_Future_Ser__d_rx_from_P_,*puVar1,pTVar15);
              TDebuggingLog::Log(this_06,(char *)L,param_1->TBuff);
              TCommunications_Handler::StoreIncoming
                        (param_1,*puVar1,(char *)param_3,param_2,param_4,param_5);
              TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,s___>TX_F_ACK___d__d___d_,
                                 pTVar15,(TDebuggingLog *)*puVar1,8);
              TCommunications_Handler::TXAcknowledgeMessage(param_1,*puVar1,(uint)pTVar15);
              TCommunications_Handler::TXResendRequest(param_1,(uint)pTStack_180,(uint)pTVar15);
              return 1;
            }
            if (param_6 == 0) {
              TDebuggingLog::Log(pTVar13,(char *)L,s___>TX_N_ACK___d__d___d_,pTVar15,pTVar13,8);
              TCommunications_Handler::TXAcknowledgeMessage(param_1,*puVar1,(uint)pTVar15);
            }
            DAT_0062cf20 = param_2 - 0xc;
            param_1->PlayerHighSerialNumber[(int)pTVar15] = *puVar1;
            DAT_0062cf1c = (uint *)(param_3 + 0xc);
          }
          TDebuggingLog::Log(L,(char *)L,s__PROCESS__Ser__d__CMD__d___c__Se,*puVar1,(uint)*param_3,
                             (uint)*param_3,(uint)param_3[1],*(undefined4 *)(param_3 + 4),param_2,
                             param_4,param_5);
          if (param_1->ShuttingDown == 0) {
            TCommunications_Handler::EvaluatePlayerMessage
                      (param_1,param_2,(uint)pTVar15,*(ulong *)(param_3 + 4),*param_3,param_3[1],
                       (char *)DAT_0062cf1c,DAT_0062cf20,param_4,param_5);
          }
        }
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042826f
// Address: 0042826f
// XREFS: None
void __thiscall FUN_0042826f(TCommunications_Handler *param_1,COMMMESSAGES param_2)
{
  TCommunications_Handler::NotifyWindowParam(param_1,param_2,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0042827f
// Address: 0042827f
// XREFS: None
// [HELPER] s_COMM__Send_msg_to_window_WM_USER: "COMM: Send msg to window WM_USER  Msg=%d  Param=%d "
void __thiscall FUN_0042827f(int param_1,undefined4 param_2,undefined4 param_3)
{
  PostMessageA(*(undefined4 *)(param_1 + 0x130c),0x400,param_2,param_3);
  TDebuggingLog::Log(L,(char *)L,s_COMM__Send_msg_to_window_WM_USER,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004282b9
// Address: 004282b9
// XREFS: None
// [HELPER] s_CHAT_RX_from_P__d__d__RXID__d_Ch: "CHAT-RX from P#%d(%d) RXID=%d Chat content='%s'  MsgSize=%d TotalSize=%d preg..."
// [HELPER] s_Host_requested_we_delete_and_rec: "Host requested we delete and recreate our player"
// [HELPER] s_KILL_Message_recieved_from__d_to: "KILL Message recieved from %d to kill P#%d "
// [HELPER] s_Non_host_requested_resume: "Non-host requested resume"
// [HELPER] s_P__d_Requested_pause: "P#%d Requested pause"
// [HELPER] s_Resume_msg_rcvd: "Resume msg rcvd"
// [HELPER] s_Unknown_message____d___c_: "Unknown message : %d '%c'"
// [HELPER] s____REGRESSION_WARNING__Current__: "+++REGRESSION WARNING, Current=%d  ExecuteOnTurn=%d"
undefined4 __thiscall
FUN_004282b9(TCommunications_Handler *param_1,ulong param_2,TDebuggingLog *param_3,ulong param_4,
            uint param_5,uchar param_6,ulong *param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10)
{
  TDebuggingLog *pTVar1;
  ulong uVar2;
  uint uVar3;
  ulong *puVar4;
  uint uVar5;
  
  if (param_1->Multiplayer == 0) {
    return 0;
  }
  param_5 = param_5 & 0xff;
  pTVar1 = (TDebuggingLog *)(param_5 - 0x2b);
  switch(param_5) {
  case 0x2b:
    if (param_1->MeHost != 0) {
      TCommunications_Handler::SendPauseGame(param_1,0);
      TDebuggingLog::Log(L,(char *)L,s_Non_host_requested_resume);
      TCommunications_Handler::LocalResumeGame(param_1,(uint)param_3);
      return 1;
    }
    break;
  default:
    TDebuggingLog::Log(pTVar1,(char *)L,s_Unknown_message____d___c_,param_5,param_5);
    break;
  case 0x3e:
    TCommunications_Handler::AddCommand(param_1,param_4,param_7,param_2,(int)param_3,param_6,0);
    return 1;
  case 0x43:
    TDebuggingLog::Log(param_3,(char *)L,s_CHAT_RX_from_P__d__d__RXID__d_Ch,param_3,param_9,param_10
                       ,(byte *)((int)param_7 + 0x11),param_7[3],param_8,(uint)(byte)param_7[4]);
    if ((*(byte *)(param_1->Me + 1 + (int)param_7) == 0x59) ||
       ((param_1->PlayerOptions).ProgramState == COMM_STATE_JOINNOW)) {
      TChat::AddChatMsg(param_1->Chat,param_1->FriendlyName[(byte)*param_7].Text,
                        (char *)((int)param_7 + 0x11),'\0');
      return 1;
    }
    break;
  case 0x44:
    RGE_Communications_Speed::SetPlayerTurnSpeed
              (param_1->Speed,(uint)param_3,*(byte *)((int)param_7 + 9),(byte)param_7[2]);
    if (((int)(param_1->PlayerOptions).ProgramState < 5) || (param_1->current_turn < 6)) {
      pTVar1 = (TDebuggingLog *)param_1->current_turn;
      if ((TDebuggingLog *)param_7[1] < pTVar1) {
        TDebuggingLog::Log(pTVar1,(char *)L,s____REGRESSION_WARNING__Current__,pTVar1,
                           (TDebuggingLog *)param_7[1]);
        return 0;
      }
    }
    uVar3 = param_7[1] - (uint)(param_1->PlayerOptions).CommandTurnIncrement;
    if (uVar3 <= param_1->LastTurnAck[(int)param_3]) {
      uVar3 = param_1->LastTurnAck[(int)param_3];
    }
    param_1->LastTurnAck[(int)param_3] = uVar3;
    return 1;
  case 0x4b:
    TDebuggingLog::Log((TDebuggingLog *)*param_7,(char *)L,s_KILL_Message_recieved_from__d_to,
                       param_3,(TDebuggingLog *)*param_7);
    uVar2 = param_7[1];
    if (uVar2 != 0) {
      uVar3 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
      uVar5 = (uint)(param_1->PlayerOptions).HighPlayerNumber;
      if (uVar3 <= uVar5) {
        puVar4 = (param_1->PlayerOptions).dcoID + uVar3;
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
      if (param_1->PlayerStopTurn[uVar3] == 0) {
        TCommunications_Handler::DropDeadPlayer(param_1,uVar3,uVar2);
      }
      if (uVar3 == param_1->Me) {
        TCommunications_Handler::NotifyWindow(param_1,COMM_PLAYER_KICKED);
        return 1;
      }
      if (param_1->PlayerStopTurn[uVar3] == 0) {
        TCommunications_Handler::NotifyWindowParam(param_1,COMM_OTHER_PLAYER_DROPPED,uVar3);
        return 1;
      }
    }
    break;
  case 0x4d:
    RGE_Communications_Synchronize::Add
              (param_1->Sync,(uint)param_3,*param_7,param_7[1],param_7[2],param_7[3],param_7[4],
               param_7[5],param_7[6],param_7[7]);
    return 1;
  case 0x4e:
    if (param_1->MeHost == 0) {
      TDebuggingLog::Log(L,(char *)L,s_Host_requested_we_delete_and_rec);
      return 1;
    }
    break;
  case 0x50:
    TDebuggingLog::Log(pTVar1,(char *)L,s_P__d_Requested_pause);
    TCommunications_Handler::LocalPauseGame(param_1,(uint)param_3);
    RGE_Communications_Synchronize::LogChecksums(param_1->Sync,0,0,0,0,0,0,0,0,0);
    return 1;
  case 0x51:
    TCommunications_Handler::SetPlayerStopTurn(param_1,(uint)param_3,*param_7);
    return 1;
  case 0x53:
    RGE_Communications_Speed::SetFutureSpeedChange
              (param_1->Speed,(uint)(ushort)*param_7,(uint)*(ushort *)((int)param_7 + 2),param_4);
    return 1;
  case 0x55:
    TDebuggingLog::Log(pTVar1,(char *)L,s_Resume_msg_rcvd);
    TCommunications_Handler::LocalResumeGame(param_1,(uint)param_3);
    return 1;
  case 0x57:
    if (param_1->MeHost != 0) {
      TCommunications_Handler::SendPauseGame(param_1,1);
      TCommunications_Handler::LocalPauseGame(param_1,(uint)param_3);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00428702
// Address: 00428702
// XREFS: None
// [HELPER] s_CheckPlayerStopTurn__Drop_player: "CheckPlayerStopTurn: Drop player %d on turn %d"
// [HELPER] s_Resigned: "Resigned"
// [HELPER] s__: "}"
void __thiscall FUN_00428702(TCommunications_Handler *param_1,ulong param_2)
{
  bool bVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  
  bVar1 = false;
  uVar4 = 1;
  if (param_1->MaxGamePlayers != 0) {
    puVar3 = param_1->PlayerStopTurn;
    do {
      puVar3 = puVar3 + 1;
      if (*puVar3 != 0) {
        bVar1 = true;
      }
      if (*puVar3 == param_2) {
        TDebuggingLog::Log((TDebuggingLog *)0x1,(char *)L,s_CheckPlayerStopTurn__Drop_player,uVar4,
                           param_2);
        TCommunications_Handler::InitPlayerInformation(param_1,uVar4,0,s_Resigned,&s__);
        TCommunications_Handler::SetPlayerHumanity(param_1,uVar4,ME_ELIMINATED);
        TCommunications_Handler::NotifyWindowParam(param_1,COMM_PLAYER_RESIGNED,uVar4);
        *puVar3 = 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= param_1->MaxGamePlayers);
  }
  if ((6 < param_1->current_turn) && (!bVar1)) {
    bVar1 = false;
    uVar4 = 1;
    if (param_1->MaxGamePlayers != 0) {
      do {
        iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,uVar4);
        if (iVar2 == 0) {
          iVar2 = TCommunications_Handler::IsPlayerComputer(param_1,uVar4);
          if (iVar2 != 0) goto LAB_004287d9;
        }
        else {
LAB_004287d9:
          if (uVar4 != param_1->Me) {
            bVar1 = true;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 <= param_1->MaxGamePlayers);
    }
    if (!bVar1) {
      TCommunications_Handler::NotifyWindow(param_1,COMM_NO_OTHER_HUMANS);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042880c
// Address: 0042880c
// XREFS: None
void __fastcall FUN_0042880c(int param_1)
{
  *(undefined1 *)(param_1 + 0x1550) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00428818
// Address: 00428818
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_NO_DCOID_FAIL_SEND_PLRDAT: "NO DCOID-FAIL SEND PLRDAT"
// [HELPER] s_Sending_options_data: "Sending options data"
// [HELPER] s_Set_Player_Data: "Set Player Data"
long __thiscall FUN_00428818(TCommunications_Handler *param_1,int param_2)
{
  ulong uVar1;
  undefined4 *puVar2;
  long lVar3;
  TDebuggingLog *this;
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
  if (param_1->MeHost == 0) {
    return 0;
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x895);
  if (param_2 == 0) {
    if (uVar1 - (param_1->PlayerOptions).LastSentTime < 2000) {
      return 0;
    }
  }
  else {
    (param_1->PlayerOptions).NeedsToBeSent = '\x01';
  }
  if ((param_1->PlayerOptions).NeedsToBeSent == '\0') {
    return 0;
  }
  if (DAT_0062cf04 == 0) {
    TDebuggingLog::Log(L,(char *)L,s_NO_DCOID_FAIL_SEND_PLRDAT);
    return -0x7fffbffb;
  }
  TDebuggingLog::Log(this,(char *)L,s_Sending_options_data);
  uVar7 = (param_1->PlayerOptions).DataSizeToFollow + 0x1d0;
  (param_1->PlayerOptions).LastSentTime = uVar1;
  puVar2 = (undefined4 *)operator_new(uVar7);
  pCVar8 = &param_1->PlayerOptions;
  puVar10 = puVar2;
  for (iVar4 = 0x74; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = *(undefined4 *)pCVar8;
    pCVar8 = (COMMPLAYEROPTIONS *)&pCVar8->LastSentTime;
    puVar10 = puVar10 + 1;
  }
  uVar6 = (param_1->PlayerOptions).DataSizeToFollow;
  pcVar9 = param_1->OptionsData;
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
  RGE_Comm_Error::ShowReturn(param_1->Err,lVar3,s_Set_Player_Data);
  operator_delete(unaff_EDI);
  (param_1->PlayerOptions).NeedsToBeSent = '\0';
  TCommunications_Handler::NotifyWindow(param_1,COMM_SHARED_DATA_SENT);
  uVar7 = 1;
  if (param_1->MaxGamePlayers != 0) {
    do {
      (param_1->PlayerOptions).InvalidPlayer[uVar7] = '\0';
      uVar7 = uVar7 + 1;
    } while (uVar7 <= param_1->MaxGamePlayers);
  }
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_0042899e
// Address: 0042899e
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Playing_Taunt___d: "Playing Taunt #%d"
undefined4 FUN_0042899e(void)
{
  TTaunt *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ccdb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = (TTaunt *)operator_new(0x198);
  uStack_4 = 0;
  if (pTVar1 == (TTaunt *)0x0) {
    pTVar1 = (TTaunt *)0x0;
  }
  else {
    pTVar1 = (TTaunt *)TTaunt::TTaunt(pTVar1,sound_driver);
  }
  uStack_4 = 0xffffffff;
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x8f2);
  TDebuggingLog::Log(L,(char *)L,s_Playing_Taunt___d,(iVar2 * 0xf) / 0x7fff);
  TTaunt::PlayTauntNo(pTVar1,4);
  if (pTVar1 != (TTaunt *)0x0) {
    TTaunt::~TTaunt(pTVar1);
    operator_delete(pTVar1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00428a62
// Address: 00428a62
// XREFS: None
// [HELPER] s_Check_dcoID__d_to_Me__d__: "Check dcoID %d to Me %d ?"
// [HELPER] s_Match____ID_set_: "Match! - ID set."
// [HELPER] s_SET_SELF_failed___We_are_DCOID__: "SET SELF failed.  We are DCOID=%d"
void __fastcall FUN_00428a62(TCommunications_Handler *param_1)
{
  ulong *puVar1;
  uint uVar2;
  
  uVar2 = 1;
  if (param_1->MaxGamePlayers != 0) {
    puVar1 = (param_1->PlayerOptions).dcoID;
    do {
      puVar1 = puVar1 + 1;
      TDebuggingLog::Log(L,(char *)L,s_Check_dcoID__d_to_Me__d__,*puVar1,DAT_0062cf04);
      if ((TDebuggingLog *)*puVar1 == DAT_0062cf04) {
        TDebuggingLog::Log((TDebuggingLog *)*puVar1,(char *)L,s_Match____ID_set_);
        param_1->Me = uVar2;
        TCommunications_Handler::NotifyWindowParam(param_1,COMM_PLAYER_ID_SET,uVar2);
        return;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 <= param_1->MaxGamePlayers);
  }
  TDebuggingLog::Log(L,(char *)L,s_SET_SELF_failed___We_are_DCOID__,DAT_0062cf04);
  return;
}

// --------------------------------------------------

// Function: FUN_00428b0c
// Address: 00428b0c
// XREFS: None
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
void __thiscall FUN_00428b0c(TCommunications_Handler *param_1,uint param_2,undefined4 param_3)
{
  uint uVar1;
  int iVar2;
  TDebuggingLog *this;
  int *piVar3;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  undefined1 auStack_34 [52];
  
  param_1->WasKicked[param_2] = 1;
  TDebuggingLog::Log(L,(char *)L,s_Drop_dead_called_P__d_and_DPID__,param_2,param_3);
  (param_1->PlayerOptions).InvalidPlayer[param_2] = '\0';
  if (param_2 == 0) {
    TDebuggingLog::Log(this,(char *)L,s_Player_number_invalid___Returnin);
    TCommunications_Handler::UpdatePlayers(param_1);
    return;
  }
  if (param_2 != param_1->Me) {
    iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,param_2);
    if (iVar2 == 0) {
      TCommunications_Handler::NotifyWindowParam(param_1,COMM_PLAYER_DEFEATED,param_2);
      TDebuggingLog::Log(this_01,(char *)L,s_Player_was_defeated__was_compute);
      TCommunications_Handler::InitPlayerInformation
                (param_1,param_2,0,s_Defeated,s_No_Other_Information);
      TCommunications_Handler::UpdatePlayers(param_1);
      TCommunications_Handler::CalculatePlayerRange(param_1);
      return;
    }
    if (((int)(param_1->PlayerOptions).ProgramState < 5) || (param_1->current_turn < 6)) {
      TDebuggingLog::Log(this_00,(char *)L,s_Player_dropped_before_game_start);
      TCommunications_Handler::InitPlayerInformation
                (param_1,param_2,0,s_Dropped,s_No_Other_Information);
      TCommunications_Handler::SetPlayerHumanity(param_1,param_2,ME_ABSENT);
      TCommunications_Handler::UpdatePlayers(param_1);
      TCommunications_Handler::CalculatePlayerRange(param_1);
    }
    else {
      TDebuggingLog::Log(L,(char *)L,s_Player_quit_the_game_);
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x4bd,auStack_34,0x32);
      sprintf(param_1->TBuff,auStack_34,param_2,param_1->FriendlyName + param_2);
      TDebuggingLog::Log(L,(char *)L,param_1->TBuff);
      TCommunications_Handler::InitPlayerInformation(param_1,param_2,0,s_Dropped,&s__);
      TCommunications_Handler::SetPlayerHumanity(param_1,param_2,ME_ABSENT);
      TCommunications_Handler::UpdatePlayers(param_1);
      TCommunications_Handler::CalculatePlayerRange(param_1);
      if (param_1->PlayerStopTurn[param_2] != 0) {
        return;
      }
    }
    TCommunications_Handler::NotifyWindowParam(param_1,COMM_OTHER_PLAYER_DROPPED,param_2);
    return;
  }
  TDebuggingLog::Log(this,(char *)L,s_I_Dropped_);
  TCommunications_Handler::NotifyWindowParam(param_1,COMM_PLAYER_DROPPED,param_1->Me);
  uVar1 = 1;
  if (param_1->MaxGamePlayers != 0) {
    piVar3 = param_1->WasKicked;
    do {
      piVar3 = piVar3 + 1;
      *piVar3 = 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 <= param_1->MaxGamePlayers);
  }
  TRIBE_World::send_zone_score_info((TRIBE_World *)rge_base_game->world);
  TDebuggingLog::Log(L,(char *)L,s_Initialize_Player_List);
  uVar1 = 1;
  if (param_1->MaxGamePlayers != 0) {
    do {
      TCommunications_Handler::InitPlayerInformation(param_1,uVar1,0,&s__,&s__);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= (int)(uint)param_1->MaxGamePlayers);
  }
  (param_1->PlayerOptions).NeedsToBeSent = '\0';
  (param_1->PlayerOptions).LastSentTime = 0;
  TCommunications_Handler::UpdatePlayers(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00428d98
// Address: 00428d98
// XREFS: None
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
/* WARNING: Type propagation algorithm not settling */

void __thiscall
FUN_00428d98(TCommunications_Handler *param_1,undefined4 param_2,undefined4 *param_3)
{
  char *pcVar1;
  ulong uVar2;
  COMMSTATES CVar3;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  PLAYERHUMANITY *pPVar7;
  TDebuggingLog *this_02;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  TDebuggingLog *this_05;
  TDebuggingLog *extraout_ECX_01;
  TDebuggingLog *extraout_ECX_02;
  TDebuggingLog *this_06;
  uint uVar8;
  undefined4 *puVar9;
  TDebuggingLog *pTVar10;
  uint *puVar11;
  COMMPLAYEROPTIONS *pCVar12;
  uint uStack_c;
  undefined4 uStack_8;
  TDebuggingLog *pTStack_4;
  
  if (param_1->Multiplayer == 0) {
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s__MP_in_DPANALYSIS);
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)*param_3,(char *)L,s_DP_Sys_Msg__d,(TDebuggingLog *)*param_3);
  pTVar10 = (TDebuggingLog *)*param_3;
  if (pTVar10 < (TDebuggingLog *)0x22) {
    if (pTVar10 == (TDebuggingLog *)0x21) {
      TDebuggingLog::Log(L,(char *)L,s_delete_player_of_group_);
      return;
    }
    if (pTVar10 == (TDebuggingLog *)&DAT_00000003) {
      uVar2 = param_3[2];
      TDebuggingLog::Log((TDebuggingLog *)&DAT_00000003,(char *)L,s_RX_NEW_PLR_ID__d,uVar2);
      TDebuggingLog::Log(L,(char *)L,s_COMM__Create_Player_Request_);
      pcVar1 = param_1->TBuff;
      sprintf(pcVar1,s_Create_Player_Request____MeHost_,param_1->MeHost,
              (param_1->PlayerOptions).ProgramState,uVar2);
      TDebuggingLog::Log(L,(char *)L,pcVar1);
      CVar3 = (param_1->PlayerOptions).ProgramState;
      if ((CVar3 == COMM_STATE_RUNNING) || (6 < param_1->current_turn)) {
        *pcVar1 = 'I';
        TDebuggingLog::Log((TDebuggingLog *)param_3[2],(char *)L,s___>TX_GIP__u__1_,
                           (TDebuggingLog *)param_3[2]);
        TCommunications_Handler::FastSend(param_1,param_3[2],pcVar1,1,0,0);
        return;
      }
      if (param_1->MeHost == 0) {
        return;
      }
      uVar4 = 1;
      if (param_1->MaxGamePlayers != 0) {
        pPVar7 = (param_1->PlayerOptions).Humanity;
        do {
          pPVar7 = pPVar7 + 1;
          if (*pPVar7 == ME_ABSENT) goto LAB_0042902a;
          uVar4 = uVar4 + 1;
        } while (uVar4 <= param_1->MaxGamePlayers);
      }
      uVar4 = 0;
LAB_0042902a:
      if ((uVar4 != 0) && (CVar3 == COMM_STATE_JOINNOW)) {
        TCommunications_Handler::InitPlayerInformation
                  (param_1,uVar4,param_3[2],(char *)param_3[8],(char *)param_3[9]);
        (param_1->PlayerOptions).dcoID[uVar4] = uVar2;
        (param_1->PlayerOptions).Humanity[uVar4] = ME_HUMAN;
        (param_1->PlayerOptions).NeedsToBeSent = '\x01';
        (param_1->PlayerOptions).InvalidPlayer[uVar4] = '\0';
        TCommunications_Handler::CalculatePlayerRange(param_1);
        TCommunications_Handler::UpdatePlayer(param_1,uVar4,1);
        (param_1->PlayerOptions).NeedsToBeSent = '\x01';
        param_1->PlayerHighSerialNumber[uVar4] = uVar4 * 2000;
        TCommunications_Handler::ClearRXTXForPlayer(param_1,uVar4);
        TCommunications_Handler::SendSharedData(param_1,0);
        return;
      }
      *pcVar1 = 'I';
      TDebuggingLog::Log((TDebuggingLog *)param_3[2],(char *)L,s___>TX_GIP2__u__1_,
                         (TDebuggingLog *)param_3[2]);
      TCommunications_Handler::FastSend(param_1,param_3[2],pcVar1,1,0,0);
      TCommunications_Handler::UpdatePlayers(param_1);
      return;
    }
    if (pTVar10 == (TDebuggingLog *)0x5) {
      uVar2 = param_3[2];
      if (uVar2 != 0) {
        uVar4 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
        uVar8 = (uint)(param_1->PlayerOptions).HighPlayerNumber;
        if (uVar4 <= uVar8) {
          puVar6 = (param_1->PlayerOptions).dcoID + uVar4;
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
      TDebuggingLog::Log(this,(char *)L,s_FROM_Player_ID_____d_,param_3[2]);
      TDebuggingLog::Log(L,(char *)L,s_Equates_to_our_player____d_,uVar4);
      TDebuggingLog::Log(this_00,(char *)L,s_Program_state_is_________d_,
                         (param_1->PlayerOptions).ProgramState);
      TDebuggingLog::FlushLog(L);
      iVar5 = TCommunications_Handler::IsPlayerHuman(param_1,uVar4);
      if ((iVar5 != 0) && (param_1->PlayerStopTurn[uVar4] == 0)) {
        if (uVar4 == param_1->Me) {
          TCommunications_Handler::NotifyWindow(param_1,COMM_PLAYER_DROPPED);
        }
        else {
          TCommunications_Handler::NotifyWindowParam(param_1,COMM_OTHER_PLAYER_DROPPED,uVar4);
        }
      }
      if (param_1->MeHost == 0) {
        return;
      }
      uStack_8 = param_3[2];
      pTStack_4 = (TDebuggingLog *)param_1->current_turn;
      uStack_c = uVar4;
      TDebuggingLog::Log(pTStack_4,(char *)L,s_HOST_Send_to_all___drop_player__,uVar4,uStack_8);
      TDebuggingLog::Log(this_01,(char *)L,s___>TX_KP2___d___d_,uVar4,0xc);
      TCommunications_Handler::CommOut(param_1,0,'K',&uStack_c,0xc,'\0');
      if (uVar4 == 0) {
        return;
      }
      if (param_1->PlayerStopTurn[uStack_c] != 0) {
        return;
      }
      TCommunications_Handler::DropDeadPlayer(param_1,uVar4,uVar2);
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
      (param_1->PlayerOptions).NeedsToBeSent = '\x01';
      TCommunications_Handler::UpdatePlayers(param_1);
      TCommunications_Handler::NotifyWindow(param_1,COMM_HOST_EXITED);
      return;
    case (TDebuggingLog *)0x101:
      if (((param_1->PlayerOptions).ProgramState != COMM_STATE_JOINNOW) &&
         (5 < param_1->current_turn)) {
        TDebuggingLog::Log(pTVar10,(char *)L,s_Assumed_host);
        param_1->MeHost = 1;
        (param_1->PlayerOptions).HostPlayerNumber = param_1->Me;
        TCommunications_Handler::CheckPingTime(param_1,1);
        TCommunications_Handler::UpdatePlayers(param_1);
        TCommunications_Handler::EnableNewPlayers(param_1,DAT_0062c5ec,0);
        TCommunications_Handler::CalculatePlayerRange(param_1);
        TCommunications_Handler::NotifyWindowParam(param_1,COMM_HOST_CHANGED,param_1->Me);
        TCommunications_Handler::KillAnyMissingPlayers(param_1);
        return;
      }
      TDebuggingLog::Log(pTVar10,(char *)L,s_Host__other__Exit_before_game_st);
      TCommunications_Handler::NotifyWindow(param_1,COMM_HOST_EXITED);
      TCommunications_Handler::EnableNewPlayers(param_1,DAT_0062c5ec,1);
      return;
    case (TDebuggingLog *)0x102:
      sprintf(param_1->TBuff,s__Player_Data>_P1__d_P2__d_P3__d_,(param_1->PlayerOptions).dcoID[1],
              (param_1->PlayerOptions).dcoID[2],(param_1->PlayerOptions).dcoID[3],
              (param_1->PlayerOptions).dcoID[4],(param_1->PlayerOptions).dcoID[5],
              (param_1->PlayerOptions).dcoID[6],(param_1->PlayerOptions).dcoID[7],
              (param_1->PlayerOptions).dcoID[8]);
      TDebuggingLog::Log(this_02,(char *)L,param_1->TBuff);
      uVar4 = 1;
      pTVar10 = extraout_ECX;
      if (param_1->MaxGamePlayers != 0) {
        uVar8 = 2000;
        puVar11 = param_1->PlayerHighSerialNumber;
        do {
          puVar11 = puVar11 + 1;
          if ((*puVar11 == 0) && (puVar11[0xf] != 0)) {
            TCommunications_Handler::ClearRXTXForPlayer(param_1,uVar4);
            *puVar11 = uVar8;
            TDebuggingLog::Log(L,(char *)L,s_Set_expected_ser__for_player__d_,uVar4,uVar8 + 1);
            pTVar10 = extraout_ECX_00;
          }
          uVar4 = uVar4 + 1;
          uVar8 = uVar8 + 2000;
        } while (uVar4 <= param_1->MaxGamePlayers);
      }
      if (param_1->MeHost == 0) {
        TDebuggingLog::Log(L,(char *)L,s_Checking_state_for_options_rcvd_);
        if ((param_1->PlayerOptions).ProgramState != COMM_STATE_JOINNOW) {
          return;
        }
        TDebuggingLog::Log(this_03,(char *)L,s_Group_options_rcvd_from_host_);
        if (0x1cf < (uint)param_3[4]) {
          puVar9 = (undefined4 *)param_3[3];
          pCVar12 = &param_1->PlayerOptions;
          for (iVar5 = 0x74; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined4 *)pCVar12 = *puVar9;
            puVar9 = puVar9 + 1;
            pCVar12 = (COMMPLAYEROPTIONS *)&pCVar12->LastSentTime;
          }
          uVar2 = (param_1->PlayerOptions).DataSizeToFollow;
          if (uVar2 + 0x1d0 <= (uint)param_3[4]) {
            TCommunications_Handler::SetMyGameOptions(param_1,(char *)(param_3[3] + 0x1d0),uVar2);
          }
          TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PARAMS);
        }
        uVar2 = (param_1->PlayerOptions).CurrentTurn;
        param_1->AcknowledgeAfterMsec = (param_1->PlayerOptions).AcknowledgeAfterMsec;
        param_1->current_turn = uVar2;
        TCommunications_Handler::SetSelfPlayer(param_1);
        if ((param_1->PlayerOptions).GameHasStarted == 0) {
          TDebuggingLog::Log(L,(char *)L,s_Game_not_yet_started_);
          pTVar10 = extraout_ECX_02;
        }
        else {
          TDebuggingLog::Log(this_04,(char *)L,s_Host_Launched_game);
          TCommunications_Handler::CalculatePlayerRange(param_1);
          TDebuggingLog::Log(L,(char *)L,s_OPTIONS_SET___program_state____d,
                             (param_1->PlayerOptions).ProgramState);
          (param_1->PlayerOptions).ProgramState = COMM_STATE_RUNNING;
          TCommunications_Handler::ResetLastCommunicationTimes(param_1);
          TCommunications_Handler::ClearRXandTX(param_1);
          puVar6 = param_1->PlayerStopTurn;
          pTVar10 = (TDebuggingLog *)0x1;
          for (iVar5 = 9; puVar6 = puVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar6 = 0;
          }
          this_05 = (TDebuggingLog *)0x0;
          if (param_1->MaxGamePlayers != 0) {
            uVar4 = 2000;
            puVar11 = param_1->PlayerHighSerialNumber;
            this_05 = (TDebuggingLog *)0x0;
            do {
              puVar11 = puVar11 + 1;
              if (puVar11[0xf] != 0) {
                *puVar11 = uVar4;
                TDebuggingLog::Log(this_05,(char *)L,s_Set_expected_ser__for_player__d_,pTVar10,
                                   uVar4 + 1);
              }
              pTVar10 = (TDebuggingLog *)((int)&pTVar10->Timestamp + 1);
              this_05 = (TDebuggingLog *)(uint)param_1->MaxGamePlayers;
              uVar4 = uVar4 + 2000;
            } while (pTVar10 <= this_05);
          }
          uVar4 = param_1->Me * 2000 + 1;
          param_1->GTDSerialNo = uVar4;
          TDebuggingLog::Log(this_05,(char *)L,s_Set_my_serial_number_to__d,uVar4);
          TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PARAMS);
          TCommunications_Handler::NotifyWindow(param_1,COMM_LAUNCH_GAME);
          pTVar10 = extraout_ECX_01;
        }
        if ((((param_1->PlayerOptions).GameHasStarted == 0) && (param_1->GTDSerialNo == 0)) &&
           (param_1->Me != 0)) {
          uVar4 = param_1->Me * 2000 + 1;
          param_1->GTDSerialNo = uVar4;
          TDebuggingLog::Log(pTVar10,(char *)L,s_Serial___was_0__setting_my_seria,uVar4);
        }
        TCommunications_Handler::UpdatePlayers(param_1);
        TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PARAMS);
        return;
      }
      TDebuggingLog::Log(pTVar10,(char *)L,s_Host___no_rcv_opts_);
      return;
    case (TDebuggingLog *)0x103:
      TCommunications_Handler::UpdatePlayers(param_1);
      TDebuggingLog::Log(L,(char *)L,s_Set_player_or_group_name);
      TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PARAMS);
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
      TDebuggingLog::Log(this_06,(char *)L,s______NOTICE____);
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

// Function: FUN_0042965b
// Address: 0042965b
// XREFS: None
void __fastcall FUN_0042965b(undefined4 param_1,int param_2)
{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  TCommunications_Handler *this;
  char *pcVar5;
  char *unaff_EBX;
  undefined4 unaff_EBP;
  uint *unaff_ESI;
  uint uVar6;
  int unaff_retaddr;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  undefined2 uStack00000014;
  char *in_stack_0000001c;
  
  pcVar5 = (char *)(in_EAX + 1);
  *(char *)(in_EAX + -0x68ffbd6e) = *(char *)(in_EAX + -0x68ffbd6e) + (char)((uint)param_2 >> 8);
  *(char *)(in_EAX + -0x18ffbd6a) = *(char *)(in_EAX + -0x18ffbd6a) + (char)unaff_EBX;
  *(char *)(unaff_retaddr + -0x6f) = *(char *)(unaff_retaddr + -0x6f) + (char)((uint)unaff_EBP >> 8)
  ;
  this = (TCommunications_Handler *)CONCAT31((int3)((uint)param_1 >> 8),(char)param_1 * '\x02');
  cVar3 = (char)pcVar5;
  *(char *)(unaff_ESI + param_2 + 4) = (char)unaff_ESI[param_2 + 4] + cVar3;
  pcVar2 = (char *)((int)this + (param_2 + 5) * 4 + -0x69c9ffbe);
  *pcVar2 = *pcVar2 + cVar3;
  *pcVar5 = *pcVar5 + cVar3;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)pcVar5;
  uVar6 = CONCAT31((int3)((uint)pcVar5 >> 8),cVar3 + *unaff_EBX + '\x05');
  *unaff_ESI = *unaff_ESI | uVar6;
  pbVar1 = (byte *)(uVar6 + 0xec839090);
  *pbVar1 = *pbVar1 | (char)param_2 + 6U;
  uStack0000000c = 0x4e4e4e4e;
  uVar6 = 1;
  uStack00000010 = 0x4e4e4e4e;
  uStack00000014 = 0x4e4e;
  if (this->MaxGamePlayers != 0) {
    do {
      iVar4 = TChat::inChatGroup(this->Chat,uVar6);
      if (iVar4 != 0) {
        *(undefined1 *)((int)&stack0x0000000c + uVar6) = 0x59;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 <= this->MaxGamePlayers);
  }
  TCommunications_Handler::TXChat(this,this->Me,(uchar *)&stack0x0000000c,in_stack_0000001c);
  return;
}

// --------------------------------------------------

// Function: FUN_004297ca
// Address: 004297ca
// XREFS: None
void __thiscall FUN_004297ca(TCommunications_Handler *param_1,char *param_2)
{
  uchar auStack_c [12];
  
  builtin_memcpy(auStack_c,"YYYY",4);
  builtin_memcpy(auStack_c + 4,"YYYYYY",6);
  TCommunications_Handler::TXChat(param_1,param_1->Me,auStack_c,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00429801
// Address: 00429801
// XREFS: None
// [HELPER] s_SendChatMsg_FROM__d__TO__d_Text_: "SendChatMsg FROM=%d  TO=%d Text='%s'"
void __thiscall
FUN_00429801(TCommunications_Handler *param_1,uint param_2,int param_3,char *param_4)
{
  uchar auStack_c [12];
  
  TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_SendChatMsg_FROM__d__TO__d_Text_,param_2,
                     param_3,param_4);
  builtin_memcpy(auStack_c,"NNNNNNNNNN",10);
  auStack_c[param_3] = 'Y';
  TCommunications_Handler::TXChat(param_1,param_2,auStack_c,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0042986a
// Address: 0042986a
// XREFS: None
// [HELPER] s_Local_chat_add___s: "Local chat add: %s"
// [HELPER] s_Local_chat_single_player_add___s: "Local chat single player add: %s"
// [HELPER] s_TXChat__: "TXChat()"
// [HELPER] s___: "]\n"
long __thiscall
FUN_0042986a(TCommunications_Handler *param_1,uint param_2,int param_3,char *param_4)
{
  char cVar1;
  int iVar2;
  long lVar3;
  TDebuggingLog *this;
  undefined4 extraout_ECX;
  uint uVar4;
  char *pcVar5;
  undefined1 uStack_114;
  char acStack_113 [11];
  int iStack_108;
  undefined1 uStack_104;
  undefined1 auStack_103 [255];
  undefined1 uStack_4;
  
  if (param_1->Multiplayer == 0) {
    TChat::AddChatMsg(param_1->Chat,param_1->FriendlyName[param_2].Text,param_4,'\x01');
    TDebuggingLog::Log(this,(char *)L,s_Local_chat_single_player_add___s,param_4);
    return 0;
  }
  if (param_1->MaxGamePlayers < param_2) {
    return -0x7fffbffb;
  }
  uVar4 = 1;
  if (param_1->MaxGamePlayers != 0) {
    do {
      iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,uVar4);
      if ((iVar2 == 0) || (*(char *)(uVar4 + param_3) != 'Y')) {
        acStack_113[uVar4] = 'N';
      }
      else {
        acStack_113[uVar4] = 'Y';
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= param_1->MaxGamePlayers);
  }
  if (acStack_113[param_1->Me] == 'Y') {
    TChat::AddChatMsg(param_1->Chat,param_1->FriendlyName[param_2].Text,param_4,'\x01');
    TDebuggingLog::Log(L,(char *)L,s_Local_chat_add___s,param_4);
  }
  uVar4 = 0xffffffff;
  pcVar5 = param_4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (~uVar4 - 1 < 0x100) {
    uVar4 = 0xffffffff;
    pcVar5 = param_4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iStack_108 = ~uVar4 - 1;
  }
  else {
    iStack_108 = 0xff;
  }
  uStack_114 = (undefined1)param_2;
  strncpy(auStack_103,param_4,iStack_108 + 1);
  uStack_104 = (param_1->PlayerOptions).ProgramState == COMM_STATE_JOINNOW;
  uStack_4 = 0;
  TDebuggingLog::Log((TDebuggingLog *)CONCAT31((int3)((uint)extraout_ECX >> 8),uStack_104),(char *)L
                     ,s___>TX_CHAT___s____d_,param_4,iStack_108 + 0x16);
  lVar3 = TCommunications_Handler::CommOut(param_1,0,'C',&uStack_114,iStack_108 + 0x16,'\0');
  RGE_Comm_Error::ShowReturn(param_1->Err,lVar3,s_TXChat__);
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_00429a2d
// Address: 00429a2d
// XREFS: None
// [HELPER] s___: "]\n"
void __thiscall FUN_00429a2d(TCommunications_Handler *param_1,undefined2 param_2,undefined2 param_3)
{
  undefined2 uStack00000006;
  
  if ((param_1->MeHost != 0) && (param_1->Multiplayer != 0)) {
    uStack00000006 = param_3;
    TDebuggingLog::Log((TDebuggingLog *)CONCAT22((short)((uint)param_1 >> 0x10),param_3),(char *)L,
                       s___>TX_KP_SPD___d_,4);
    TCommunications_Handler::CommOut(param_1,0,'S',&param_2,4,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00429a86
// Address: 00429a86
// XREFS: None
// [HELPER] s___: "]\n"
void __fastcall FUN_00429a86(TCommunications_Handler *param_1)
{
  uint uVar1;
  TDebuggingLog *pTStack_10;
  undefined1 auStack_c [4];
  TDebuggingLog *pTStack_8;
  uchar uStack_4;
  undefined1 uStack_3;
  
  if (param_1->Multiplayer != 0) {
    pTStack_10 = (TDebuggingLog *)
                 (param_1->current_turn + (uint)(param_1->PlayerOptions).CommandTurnIncrement);
    TDebuggingLog::Log(pTStack_10,(char *)L,s___>TX_RSGN___d_,4);
    TCommunications_Handler::CommOut(param_1,0,'Q',&pTStack_10,4,'\0');
    uStack_4 = RGE_Communications_Speed::GetHighLatencyCenti(param_1->Speed);
    uVar1 = RGE_Communications_Speed::GetAvgFrameRate(param_1->Speed);
    uStack_3 = (undefined1)uVar1;
    pTStack_8 = (TDebuggingLog *)
                (param_1->current_turn + 1 + (uint)(param_1->PlayerOptions).CommandTurnIncrement);
    auStack_c[0] = 0x44;
    TDebuggingLog::Log(L,(char *)L,s___>TX_DONE___d_,0xc);
    TCommunications_Handler::CommOut(param_1,0,'D',auStack_c,0xc,'\0');
    pTStack_8 = (TDebuggingLog *)
                (((TDebuggingLog *)param_1->current_turn)->TBuff +
                ((param_1->PlayerOptions).CommandTurnIncrement - 0x26));
    TDebuggingLog::Log((TDebuggingLog *)param_1->current_turn,(char *)L,s___>TX_DONE___d_,0xc);
    TCommunications_Handler::CommOut(param_1,0,'D',auStack_c,0xc,'\0');
    pTStack_8 = (TDebuggingLog *)
                (param_1->current_turn + 3 + (uint)(param_1->PlayerOptions).CommandTurnIncrement);
    TDebuggingLog::Log(pTStack_8,(char *)L,s___>TX_DONE___d_,0xc);
    TCommunications_Handler::CommOut(param_1,0,'D',auStack_c,0xc,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00429bc9
// Address: 00429bc9
// XREFS: None
uint __fastcall FUN_00429bc9(TCommunications_Handler *param_1)
{
  int iVar1;
  ulong *puVar2;
  uint uVar3;
  
  DAT_0062c5e8 = 0;
  uVar3 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
  if (uVar3 <= (param_1->PlayerOptions).HighPlayerNumber) {
    puVar2 = param_1->LastTurnAck + uVar3;
    do {
      iVar1 = TCommunications_Handler::IsPlayerHuman(param_1,uVar3);
      if ((iVar1 != 0) && (DAT_0062c5e8 < *puVar2)) {
        DAT_0062c5e8 = *puVar2;
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while ((int)uVar3 <= (int)(uint)(param_1->PlayerOptions).HighPlayerNumber);
  }
  return DAT_0062c5e8;
}

// --------------------------------------------------

// Function: FUN_00429c33
// Address: 00429c33
// XREFS: None
undefined4 __fastcall FUN_00429c33(TCommunications_Handler *param_1)
{
  int iVar1;
  ulong *puVar2;
  uint uVar3;
  
  if (param_1->Multiplayer == 0) {
    return 0;
  }
  if (param_1->ShuttingDown != 0) {
    return 0;
  }
  if ((param_1->PlayerOptions).ProgramState == COMM_STATE_PAUSE) {
    return 0;
  }
  uVar3 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
  if (uVar3 <= (param_1->PlayerOptions).HighPlayerNumber) {
    puVar2 = param_1->LastTurnAck + uVar3;
    while( true ) {
      iVar1 = TCommunications_Handler::IsPlayerHuman(param_1,uVar3);
      if ((iVar1 != 0) && (*puVar2 < param_1->current_turn)) break;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
      if ((param_1->PlayerOptions).HighPlayerNumber < uVar3) {
        return 1;
      }
    }
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00429cd2
// Address: 00429cd2
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_SendChecksum: "SendChecksum"
// [HELPER] s___: "]\n"
long __thiscall
FUN_00429cd2(TCommunications_Handler *param_1,undefined4 param_2,undefined4 param_3,
            undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,
            undefined4 param_8)
{
  long lVar1;
  TDebuggingLog *this;
  undefined4 uStack_24;
  ulong uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  ulong uStack_4;
  
  uStack_24 = param_2;
  uStack_20 = param_1->current_turn;
  uStack_18 = param_4;
  uStack_14 = param_5;
  uStack_10 = param_6;
  uStack_c = param_7;
  uStack_8 = param_8;
  uStack_1c = param_3;
  uStack_4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xbc0);
  TDebuggingLog::Log(this,(char *)L,s___>TX_CKSUM___d_,0x24);
  lVar1 = TCommunications_Handler::CommOut(param_1,0,'M',&uStack_24,0x24,'\0');
  RGE_Comm_Error::ShowReturn(param_1->Err,lVar1,s_SendChecksum);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_00429d86
// Address: 00429d86
// XREFS: None
// [HELPER] s_Cached_Execute___d__Slot__d_: "Cached Execute #%d  Slot#%d "
// [HELPER] s_Clearing_OnHold_Slot__d__Len__d_: "Clearing OnHold Slot=%d  Len=%d  From=%d  To=%d"
// [HELPER] s____Clearing_PAST_OnHold_Slot__d_: "+++Clearing PAST OnHold Slot=%d  Serial#%d Len=%d  From=%d  To=%d  Expecting#%d"
undefined4 __fastcall FUN_00429d86(TCommunications_Handler *param_1)
{
  HOLDER *pHVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  TDebuggingLog *this;
  uint uVar5;
  uint uVar6;
  ulong *puVar7;
  undefined4 *puVar8;
  TDebuggingLog *pTStack_c;
  uint uStack_8;
  
  uVar5 = 0;
  if (param_1->Multiplayer != 0) {
    pTStack_c = (TDebuggingLog *)0x0;
    do {
      if ((*(int *)((int)&param_1->OnHold->Length + uVar5) != 0) &&
         (uStack_8 = 1, param_1->MaxGamePlayers != 0)) {
        puVar7 = (param_1->PlayerOptions).dcoID;
        do {
          puVar7 = puVar7 + 1;
          iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,uStack_8);
          if ((iVar4 != 0) && (uStack_8 != param_1->Me)) {
            pHVar1 = param_1->OnHold;
            uVar6 = puVar7[-0xf] + 1;
            uVar2 = *(uint *)((int)&pHVar1->Serial + uVar5);
            if ((uVar2 < uVar6) &&
               (uVar3 = *(ulong *)((int)&pHVar1->dcoFromID + uVar5), uVar3 == *puVar7)) {
              TDebuggingLog::Log(L,(char *)L,s____Clearing_PAST_OnHold_Slot__d_,pTStack_c,uVar2,
                                 *(undefined4 *)((int)&pHVar1->Length + uVar5),uVar3,
                                 *(undefined4 *)((int)&pHVar1->dcoReceiveID + uVar5),uVar6);
              puVar8 = (undefined4 *)((int)&param_1->OnHold->HoldMsg + uVar5);
              if ((void *)*puVar8 != (void *)0x0) {
                operator_delete((void *)*puVar8);
              }
              *puVar8 = 0;
              puVar8[1] = 0;
              puVar8[2] = 0;
              puVar8[3] = 0;
              puVar8[4] = 0;
            }
            if ((*(uint *)((int)&param_1->OnHold->Serial + uVar5) == uVar6) &&
               (*(ulong *)((int)&param_1->OnHold->dcoFromID + uVar5) == *puVar7)) {
              sprintf(param_1->TBuff,s_Cached_Execute___d__Slot__d_,uVar6,pTStack_c);
              TDebuggingLog::Log(this,(char *)L,param_1->TBuff);
              puVar8 = (undefined4 *)((int)&param_1->OnHold->HoldMsg + uVar5);
              TCommunications_Handler::PreprocessMessages
                        (param_1,puVar8[2],(char *)*puVar8,puVar8[3],puVar8[4],1);
              pHVar1 = param_1->OnHold;
              TDebuggingLog::Log(pTStack_c,(char *)L,s_Clearing_OnHold_Slot__d__Len__d_,pTStack_c,
                                 *(undefined4 *)((int)&pHVar1->Length + uVar5),
                                 *(undefined4 *)((int)&pHVar1->dcoFromID + uVar5),
                                 *(undefined4 *)((int)&pHVar1->dcoReceiveID + uVar5));
              puVar8 = (undefined4 *)((int)&param_1->OnHold->HoldMsg + uVar5);
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
          uStack_8 = uStack_8 + 1;
        } while (uStack_8 <= param_1->MaxGamePlayers);
      }
      uVar5 = uVar5 + 0x18;
      pTStack_c = (TDebuggingLog *)((int)&pTStack_c->Timestamp + 1);
    } while (uVar5 < 0x2ef9);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00429f75
// Address: 00429f75
// XREFS: None
// [HELPER] s_Cleared_all_serial_numbers_: "Cleared all serial numbers."
void __fastcall FUN_00429f75(TDebuggingLog *param_1)
{
  char *pcVar1;
  uint uVar2;
  
  TDebuggingLog::Log(param_1,(char *)L,s_Cleared_all_serial_numbers_);
  uVar2 = 0;
  pcVar1 = param_1[2].osbuf + 0x13c;
  do {
    pcVar1[0x144] = '\0';
    pcVar1[0x145] = '\0';
    pcVar1[0x146] = '\0';
    pcVar1[0x147] = '\0';
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1[0x28] = '\0';
    pcVar1[0x29] = '\0';
    pcVar1[0x2a] = '\0';
    pcVar1[0x2b] = '\0';
    pcVar1[0x50] = '\0';
    pcVar1[0x51] = '\0';
    pcVar1[0x52] = '\0';
    pcVar1[0x53] = '\0';
    pcVar1[0x78] = '\0';
    pcVar1[0x79] = '\0';
    pcVar1[0x7a] = '\0';
    pcVar1[0x7b] = '\0';
    uVar2 = uVar2 + 1;
    pcVar1 = pcVar1 + 4;
  } while (uVar2 <= *(ushort *)(param_1[2].osbuf + 0x30));
  return;
}

// --------------------------------------------------

// Function: FUN_00429fc6
// Address: 00429fc6
// XREFS: None
void __fastcall FUN_00429fc6(int param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar2 = 0;
  do {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1524) + uVar2);
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete((void *)*puVar3);
    }
    uVar2 = uVar2 + 0x18;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
  } while (uVar2 < 0x2ef8);
  uVar2 = 0;
  do {
    iVar4 = *(int *)(param_1 + 0x1520);
    *(undefined4 *)(iVar4 + uVar2) = 0;
    iVar4 = iVar4 + uVar2;
    if (*(void **)(iVar4 + 8) != (void *)0x0) {
      operator_delete(*(void **)(iVar4 + 8));
    }
    uVar2 = uVar2 + 0x38;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    puVar3 = (undefined4 *)(iVar4 + 0x10);
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  } while (uVar2 < 0x6d98);
  return;
}

// --------------------------------------------------

// Function: FUN_0042a058
// Address: 0042a058
// XREFS: None
void __thiscall FUN_0042a058(int param_1,int param_2)
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1524) + uVar2);
    if (*(int *)(*(int *)(param_1 + 0x1524) + 0xc + uVar2) ==
        *(int *)(param_1 + 0x1564 + param_2 * 4)) {
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

// Function: FUN_0042a0b3
// Address: 0042a0b3
// XREFS: None
// [HELPER] s_GTD__Ser___d_Slot__d_Cmd___c__Le: "GTD: Ser #%d Slot=%d Cmd='%c' Len=%d not ackd yet by %d,%d,%d,%d,%d,%d,%d,%d"
int __fastcall FUN_0042a0b3(int param_1)
{
  TDebuggingLog *this;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  uVar3 = 0;
  do {
    iVar1 = *(int *)(param_1 + 0x1520) + uVar3;
    this = *(TDebuggingLog **)(iVar1 + 4);
    if (this != (TDebuggingLog *)0x0) {
      TDebuggingLog::Log(this,(char *)L,s_GTD__Ser___d_Slot__d_Cmd___c__Le,this,iVar4,
                         (int)**(char **)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                         *(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),
                         *(undefined4 *)(iVar1 + 0x1c),*(undefined4 *)(iVar1 + 0x20),
                         *(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(iVar1 + 0x28),
                         *(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x30));
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 0x38;
    iVar4 = iVar4 + 1;
  } while (uVar3 < 0x6d99);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0042a12f
// Address: 0042a12f
// XREFS: None
void __thiscall FUN_0042a12f(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x1f6;
  iVar1 = param_2 * 4 + 0x10;
  do {
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
    *(undefined4 *)(*(int *)(param_1 + 0x1520) + -0x38 + iVar1) = 0;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0042a159
// Address: 0042a159
// XREFS: None
void __thiscall FUN_0042a159(TCommunications_Handler *param_1,uint param_2)
{
  TCommunications_Handler::ClearTXForPlayer(param_1,param_2);
  TCommunications_Handler::ClearRXForPlayer(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0042a17b
// Address: 0042a17b
// XREFS: None
// [HELPER] s_Future_Ser__d_previously_stored_: "Future Ser#%d previously stored (Slot#%d)"
// [HELPER] s_HOLD_FULL_WARNING___COUNT__d: "HOLD FULL WARNING.  COUNT=%d"
// [HELPER] s_S__d__Ser__d_FromID__d_Len__d__C: "S#%d  Ser#%d FromID=%d Len=%d  CMD='%c' B0=%d B1=%d"
// [HELPER] s____StoreIncoming_called_for_zero: "+++StoreIncoming called for zero-length message"
// [HELPER] s_____DID_NOT_STORE___: "+++ DID NOT STORE:  "
undefined4 __thiscall
FUN_0042a17b(TDebuggingLog *param_1,int param_2,undefined4 *param_3,int param_4,int param_5,
            undefined4 param_6)
{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  TDebuggingLog *this;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (param_4 == 0) {
    TDebuggingLog::Log(param_1,(char *)L,s____StoreIncoming_called_for_zero);
  }
  iVar7 = *(int *)(param_1[2].osbuf + 0x27c);
  uVar3 = 0;
  piVar1 = (int *)(iVar7 + 0xc);
  while ((piVar1[-2] != param_2 || (*piVar1 != param_5))) {
    uVar3 = uVar3 + 1;
    piVar1 = piVar1 + 6;
    if (0x1f5 < uVar3) {
      uVar3 = 0;
      piVar1 = (int *)(iVar7 + 8);
      while ((*piVar1 != 0 || (param_4 == 0))) {
        uVar3 = uVar3 + 1;
        piVar1 = piVar1 + 6;
        if (500 < uVar3) {
          TDebuggingLog::Log(L,(char *)L,s_____DID_NOT_STORE___);
          if (0x1eb < uVar3) {
            TDebuggingLog::Log(this,(char *)L,s_HOLD_FULL_WARNING___COUNT__d,uVar3);
            iVar7 = 0;
            uVar3 = 0;
            do {
              puVar2 = (undefined4 *)(*(int *)(param_1[2].osbuf + 0x27c) + uVar3);
              if (puVar2[2] != 0) {
                iVar5 = (int)*(char *)*puVar2;
                TDebuggingLog::Log(L,(char *)L,s_S__d__Ser__d_FromID__d_Len__d__C,iVar7,puVar2[1],
                                   puVar2[3],puVar2[2],iVar5,iVar5,(int)((char *)*puVar2)[1]);
              }
              uVar3 = uVar3 + 0x18;
              iVar7 = iVar7 + 1;
            } while (uVar3 < 0x2ef8);
          }
          return 1;
        }
      }
      iVar5 = uVar3 * 0x18;
      *(int *)(iVar5 + 8 + iVar7) = param_4;
      puVar6 = (undefined4 *)(iVar5 + *(int *)(param_1[2].osbuf + 0x27c));
      puVar2 = (undefined4 *)operator_new(puVar6[2]);
      *puVar6 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        uVar3 = puVar6[2];
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar2 = *param_3;
          param_3 = param_3 + 1;
          puVar2 = puVar2 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar2 = *(undefined1 *)param_3;
          param_3 = (undefined4 *)((int)param_3 + 1);
          puVar2 = (undefined4 *)((int)puVar2 + 1);
        }
        puVar6[2] = param_4;
      }
      *(int *)(iVar5 + 4 + *(int *)(param_1[2].osbuf + 0x27c)) = param_2;
      *(int *)(iVar5 + 0xc + *(int *)(param_1[2].osbuf + 0x27c)) = param_5;
      *(undefined4 *)(iVar5 + 0x10 + *(int *)(param_1[2].osbuf + 0x27c)) = param_6;
      return 1;
    }
  }
  TDebuggingLog::Log(L,(char *)L,s_Future_Ser__d_previously_stored_,param_2,uVar3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042a321
// Address: 0042a321
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_QUEUE_Has_Ser___d__Slot__d__Cmd_: "QUEUE Has Ser #%d (Slot=%d) Cmd=%d '%c' Len=%d not ackd yet by %d,%d,%d,%d,%d..."
// [HELPER] s_RESEND_buffer_filled_up__slots__: "RESEND buffer filled up, slots (i=%d)."
// [HELPER] s_Stored__db_for_resend__Slot___d_: "Stored %db for resend (Slot= %d ) SERIAL=%d  (MaxPlayers=%d)"
// [HELPER] s_____RGEGTD_Store: "+++!RGEGTD Store"
undefined4 __thiscall
FUN_0042a321(TDebuggingLog *param_1,undefined4 param_2,undefined4 *param_3,int param_4,
            undefined4 *param_5)
{
  undefined4 *puVar1;
  ulong uVar2;
  TDebuggingLog *this;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  if (*(int *)(param_1[2].TBuff + 0x15c) != 0) {
    if (param_1[2].osbuf[0x26c] == '\0') {
      TDebuggingLog::Log(param_1,(char *)L,s_____RGEGTD_Store);
      return 0;
    }
    iVar4 = 0;
    uVar5 = 0;
    do {
      iVar6 = *(int *)(uVar5 + 4 + *(int *)(param_1[2].osbuf + 0x278));
      iVar7 = uVar5 + *(int *)(param_1[2].osbuf + 0x278);
      if (iVar6 == 0) {
        iVar7 = iVar4 * 0x38;
        *(int *)(iVar7 + 0xc + *(int *)(param_1[2].osbuf + 0x278)) = param_4;
        if (param_4 != 0) {
          iVar6 = iVar7 + *(int *)(param_1[2].osbuf + 0x278);
          puVar1 = (undefined4 *)operator_new(*(uint *)(iVar6 + 0xc));
          *(undefined4 **)(iVar6 + 8) = puVar1;
          if (puVar1 != (undefined4 *)0x0) {
            uVar5 = *(uint *)(iVar6 + 0xc);
            for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar1 = *param_3;
              param_3 = param_3 + 1;
              puVar1 = puVar1 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar1 = *(undefined1 *)param_3;
              param_3 = (undefined4 *)((int)param_3 + 1);
              puVar1 = (undefined4 *)((int)puVar1 + 1);
            }
            *(int *)(iVar6 + 0xc) = param_4;
          }
        }
        *(undefined4 *)(iVar7 + 4 + *(int *)(param_1[2].osbuf + 0x278)) = param_2;
        puVar1 = param_5;
        puVar8 = (undefined4 *)(iVar7 + 0x10 + *(int *)(param_1[2].osbuf + 0x278));
        for (uVar5 = (uint)*(ushort *)(param_1[2].osbuf + 0x30) * 4 + 4 >> 2; uVar5 != 0;
            uVar5 = uVar5 - 1) {
          *puVar8 = *puVar1;
          puVar1 = puVar1 + 1;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar1;
          puVar1 = (undefined4 *)((int)puVar1 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        TDebuggingLog::Log((TDebuggingLog *)(uint)*(ushort *)(param_1[2].osbuf + 0x30),(char *)L,
                           s_Stored__db_for_resend__Slot___d_,param_4,iVar4,param_2,
                           (TDebuggingLog *)(uint)*(ushort *)(param_1[2].osbuf + 0x30));
        uVar5 = 1;
        if (*(short *)(param_1[2].osbuf + 0x30) != 0) {
          iVar4 = iVar7 + 0x14;
          do {
            param_5 = param_5 + 1;
            if (*(int *)(iVar4 + *(int *)(param_1[2].osbuf + 0x278)) != 0) {
              TDebuggingLog::Log((TDebuggingLog *)*param_5,(char *)L,s_______to__>_P__d__retries__d,
                                 uVar5,(TDebuggingLog *)*param_5);
            }
            uVar5 = uVar5 + 1;
            iVar4 = iVar4 + 4;
          } while (uVar5 <= *(ushort *)(param_1[2].osbuf + 0x30));
        }
        uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd12);
        *(ulong *)(iVar7 + *(int *)(param_1[2].osbuf + 0x278)) = uVar2;
        return 1;
      }
      TDebuggingLog::Log(L,(char *)L,s_QUEUE_Has_Ser___d__Slot__d__Cmd_,iVar6,iVar4,
                         (int)**(char **)(iVar7 + 8),(int)**(char **)(iVar7 + 8),
                         *(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 0x14),
                         *(undefined4 *)(iVar7 + 0x18),*(undefined4 *)(iVar7 + 0x1c),
                         *(undefined4 *)(iVar7 + 0x20),*(undefined4 *)(iVar7 + 0x24),
                         *(undefined4 *)(iVar7 + 0x28),*(undefined4 *)(iVar7 + 0x2c),
                         *(undefined4 *)(iVar7 + 0x30));
      uVar5 = uVar5 + 0x38;
      iVar4 = iVar4 + 1;
    } while (uVar5 < 0x6d98);
    TDebuggingLog::Log(this,(char *)L,s_RESEND_buffer_filled_up__slots__,iVar4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042a53b
// Address: 0042a53b
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_GTD_ACK: "GTD ACK"
// [HELPER] s__RGEGTD_Ack: "!RGEGTD Ack"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____TXAcknowledgeMessage_slow____: "!!!TXAcknowledgeMessage slow - %ld msec"
undefined4 __thiscall FUN_0042a53b(TDebuggingLog *param_1,TDebuggingLog *param_2,int param_3)
{
  undefined1 *puVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  TDebuggingLog *this;
  
  if (param_1[2].osbuf[0x26c] == '\0') {
    TDebuggingLog::Log(param_1,(char *)L,s__RGEGTD_Ack);
    return 0;
  }
  puVar1 = (undefined1 *)operator_new(8);
  *puVar1 = 0x41;
  *(TDebuggingLog **)(puVar1 + 4) = param_2;
  if (DAT_0062cf04 == 0) {
    TDebuggingLog::Log(param_2,(char *)L,s____BAD_DCOID_0_NO_TX);
    return 0;
  }
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd53);
  iVar3 = (**(code **)(*DAT_0062c5ec + 0x68))
                    (DAT_0062c5ec,DAT_0062cf04,*(undefined4 *)(param_1[2].osbuf + param_3 * 4 + 700)
                     ,0,puVar1,8);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd5e);
  if (0x32 < uVar4 - uVar2) {
    TDebuggingLog::Log(this,(char *)L,s____TXAcknowledgeMessage_slow____,uVar4 - uVar2);
  }
  *(int *)(param_1[2].osbuf + 0x18) = *(int *)(param_1[2].osbuf + 0x18) + 8;
  operator_delete(puVar1);
  if (iVar3 == 0) {
    return 1;
  }
  RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1[2].osbuf + 0x238),iVar3,s_GTD_ACK);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042a6db
// Address: 0042a6db
// XREFS: None
// [HELPER] s_GTD__Ser___d_Slot__d__Ackd_by_al: "GTD: Ser #%d Slot=%d  Ackd by all. (Released)"
undefined4 __fastcall FUN_0042a6db(TCommunications_Handler *param_1)
{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iStack_c;
  int iStack_8;
  uint uStack_4;
  
  iVar3 = 0;
  iStack_8 = 0;
  uStack_4 = 4;
  do {
    iStack_c = 0;
    if (*(int *)((int)param_1->Resend->DestMap + iVar3 + -0xc) != 0) {
      uVar4 = 1;
      if (param_1->MaxGamePlayers != 0) {
        do {
          iVar1 = TCommunications_Handler::IsPlayerHuman(param_1,uVar4);
          if ((iVar1 != 0) && (param_1->Resend->DestMap[uVar4 + uStack_4 + -4] != 0)) {
            iStack_c = iStack_c + 1;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 <= param_1->MaxGamePlayers);
      }
      if (iStack_c == 0) {
        TDebuggingLog::Log(L,(char *)L,s_GTD__Ser___d_Slot__d__Ackd_by_al,
                           *(undefined4 *)((int)param_1->Resend->DestMap + iVar3 + -0xc),iStack_8);
        puVar5 = (undefined4 *)((int)param_1->Resend->DestMap + iVar3 + -0x10);
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
    uStack_4 = uStack_4 + 0xe;
    iStack_8 = iStack_8 + 1;
    iVar3 = iVar3 + 0x38;
  } while (uStack_4 < 0x1b6b);
  iVar3 = 0x1f6;
  puVar2 = &param_1->Resend->Serial;
  do {
    if (*puVar2 != 0) {
      param_1->WaitingForAck = param_1->WaitingForAck + 1;
    }
    puVar2 = puVar2 + 0xe;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042a7fb
// Address: 0042a7fb
// XREFS: None
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
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __fastcall FUN_0042a7fb(TCommunications_Handler *param_1)
{
  TDebuggingLog *this;
  ulong uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  ulong uVar5;
  uint *puVar6;
  uint *puVar7;
  TCommunications_Handler *extraout_ECX;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  uint uVar8;
  int iVar9;
  RESENDER *pRVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 uVar13;
  TDebuggingLog *pTStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined1 auStack_8 [4];
  int iStack_4;
  
  if (param_1->RGE_Guaranteed_Delivery == '\0') {
    pcVar12 = s__RGEGTD_SendStore;
LAB_0042acdf:
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,pcVar12);
    return 0;
  }
  if ((DAT_0062c5e4 & 1) == 0) {
    DAT_0062c5e4 = DAT_0062c5e4 | 1;
    DAT_0062c5a8 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe00);
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe02);
  uVar11 = 0;
  if (_DAT_0056f210 < (float)DAT_0062cf28 / (float)(int)(uVar1 - DAT_0062c5a8)) {
    return 0;
  }
  DAT_0062cf28 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  pTStack_20 = (TDebuggingLog *)0x0;
  DAT_0062c5a8 = uVar1;
  TCommunications_Handler::PurgeAcknowledgedStoredMessages(param_1);
  pRVar10 = param_1->Resend;
  uVar8 = 0;
  puVar6 = pRVar10->DestMap + 1;
  do {
    if (puVar6[-4] != 0) {
      pTStack_20 = (TDebuggingLog *)((int)pTStack_20 + 1);
      uVar2 = uVar1 - pRVar10->TimeSent;
      if (uStack_1c < uVar2) {
        uStack_1c = uVar2;
        uStack_18 = uVar11;
      }
      puVar7 = puVar6;
      for (uVar2 = (uint)param_1->MaxGamePlayers; uVar2 != 0; uVar2 = uVar2 - 1) {
        if (uVar8 < 0xf0 - *puVar7) {
          uVar8 = 0xf0 - *puVar7;
        }
        puVar7 = puVar7 + 1;
      }
    }
    uVar11 = uVar11 + 1;
    pRVar10 = pRVar10 + 1;
    puVar6 = puVar6 + 0xe;
  } while (uVar11 < 0x1f6);
  if (pTStack_20 == (TDebuggingLog *)0x0) {
    return 0;
  }
  if (param_1->current_turn < 7) {
    if (uStack_1c < 2000) {
      return 0;
    }
  }
  else if (param_1->ShuttingDown == 0) {
    uVar11 = resend_adj2 + param_1->Speed->HighestLatencyMsec * 2;
    if (uVar11 < resend_adj1 + 500U) {
      uVar11 = resend_adj1 + 500U;
    }
    if (uStack_1c < uVar11) {
      return 0;
    }
  }
  else if (uStack_1c < 0xfa) {
    return 0;
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe55);
  uVar11 = 1;
  param_1->Resend[uStack_18].TimeSent = uVar1;
  if (param_1->MaxGamePlayers == 0) {
    return param_1->ResentToOther;
  }
  iVar9 = uStack_18 * 0x38 + 0x14;
  pTStack_20 = (TDebuggingLog *)((param_1->PlayerOptions).dcoID + 1);
  do {
    if ((((*(int *)((int)param_1->Resend->DestMap + iVar9 + -0x10) != 0) &&
         (iVar3 = TCommunications_Handler::IsPlayerHuman(param_1,uVar11), iVar3 != 0)) &&
        (pTStack_20->Timestamp != 0)) && (uVar11 != param_1->Me)) {
      piVar4 = (int *)((int)param_1->Resend->DestMap + iVar9 + -0x10);
      iVar3 = *piVar4;
      if (iVar3 != 0) {
        *piVar4 = iVar3 + -1;
      }
      uVar13 = *(undefined4 *)((int)param_1->Resend->DestMap + iVar9 + -0x10);
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe69);
      TDebuggingLog::Log((TDebuggingLog *)pTStack_20->Timestamp,(char *)L,
                         s_Resending___d_to_P__d_dcoid__d_L,uStack_18,uVar11,
                         (TDebuggingLog *)pTStack_20->Timestamp,param_1->Resend[uStack_18].Length,
                         uStack_1c,uVar1,uVar13);
      if (DAT_0062cf04 == 0) {
        pcVar12 = s____BAD_DCOID_0_NO_TX;
        param_1 = extraout_ECX;
        goto LAB_0042acdf;
      }
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe76);
      TDebuggingLog::Log(L,(char *)L,s___>TX_STOR___d__d___d_,uVar11,uStack_18,
                         param_1->Resend[uStack_18].Length);
      iVar3 = (**(code **)(*DAT_0062c5ec + 0x68))
                        (DAT_0062c5ec,DAT_0062cf04,pTStack_20->Timestamp,0,
                         param_1->Resend[uStack_18].ResendMsg,param_1->Resend[uStack_18].Length);
      uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xe86);
      if (0x32 < uVar5 - uVar1) {
        TDebuggingLog::Log(L,(char *)L,s____SendStoredMessages_slow____ld,uVar5 - uVar1);
      }
      if (iVar3 == 0) {
        puVar6 = &param_1->Resend[uStack_18].Length;
        param_1->ResentToOther = param_1->ResentToOther + 1;
        param_1->TXPacketLength = param_1->TXPacketLength + *puVar6;
        DAT_0062cf28 = DAT_0062cf28 + *puVar6;
        this = (TDebuggingLog *)param_1->Resend[uStack_18].Length;
        TDebuggingLog::Log(this,(char *)L,s_COMM__RESENT_TX_Ser__d_To_P__d_L,
                           param_1->Resend[uStack_18].Serial,uVar11,this);
      }
      else {
        RGE_Comm_Error::ShowReturn(param_1->Err,iVar3,s_RESEND_Transmit);
      }
      if (((*(int *)((int)param_1->Resend->DestMap + iVar9 + -0x10) == 0) &&
          (iVar3 = TCommunications_Handler::IsPlayerHuman(param_1,uVar11), iVar3 != 0)) &&
         ((pTStack_20->Timestamp != 0 && (uVar11 != param_1->Me)))) {
        pcVar12 = TCommunications_Handler::GetPlayerName(param_1,uVar11);
        sprintf(param_1->TBuff,s_Max_resends_to_Player___d___s__,uVar11,pcVar12);
        TDebuggingLog::Log(L,(char *)L,param_1->TBuff);
        if (param_1->MeHost == 0) {
          iStack_4 = pTStack_20->Timestamp;
          TDebuggingLog::Log(pTStack_20,(char *)L,s_TX_Missing_Player_report_for_pla,iStack_4);
          auStack_8[0] = 0x3f;
          TDebuggingLog::Log(this_01,(char *)L,s___>TX_MP___d_,8);
          TCommunications_Handler::FastSend(param_1,0,auStack_8,8,0,0);
        }
        else {
          TDebuggingLog::Log(this_00,(char *)L,s_HOST_Rcvd_MAX_TX_for_player___d,uVar11);
          pTStack_20[-0xffffffff00000001].osbuf[0x3a0] = '\x01';
          pTStack_20[-0xffffffff00000001].osbuf[0x3a1] = '\0';
          pTStack_20[-0xffffffff00000001].osbuf[0x3a2] = '\0';
          pTStack_20[-0xffffffff00000001].osbuf[0x3a3] = '\0';
          TCommunications_Handler::Kick(param_1,uVar11);
        }
      }
    }
    pTStack_20 = (TDebuggingLog *)&pTStack_20->DateTimestamp;
    uVar11 = uVar11 + 1;
    iVar9 = iVar9 + 4;
    if (param_1->MaxGamePlayers < uVar11) {
      return param_1->ResentToOther;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0042ad05
// Address: 0042ad05
// XREFS: None
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
undefined4 __thiscall FUN_0042ad05(TCommunications_Handler *param_1,uint param_2,uint param_3)
{
  TDebuggingLog *this;
  RESENDER *pRVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  TCommunications_Handler *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  uint uVar7;
  char *pcVar8;
  int iStack_18;
  int iStack_14;
  TDebuggingLog *pTStack_10;
  void *pvStack_8;
  int iStack_4;
  
  uVar2 = param_3;
  if (param_1->RGE_Guaranteed_Delivery == '\0') {
    return 0;
  }
  uVar7 = 0;
  if ((param_1->PlayerOptions).dcoID[param_3] == 0) {
    pcVar8 = s_Invalid_player_req_;
    this_00 = param_1;
LAB_0042b07b:
    TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,pcVar8);
    return 0;
  }
  if (DAT_0062cf04 == 0) {
    return 0;
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xee7);
  if ((param_2 == param_1->LastSerialRepliedTX[param_3]) &&
     (uVar6 = uVar3 - param_1->LastRequestRepliedTX[param_3], uVar6 < 500)) {
    TDebuggingLog::Log(L,(char *)L,s_Res_reply_too_soon___u__u,param_2,uVar6);
    return 0;
  }
  param_1->LastSerialRepliedTX[param_3] = param_2;
  param_1->LastRequestRepliedTX[param_3] = uVar3;
  pTStack_10 = (TDebuggingLog *)0x0;
  iStack_18 = 0;
  iStack_14 = 0;
  param_3 = param_3 * 4 + 0x10;
  do {
    uVar6 = *(uint *)((int)param_1->Resend->DestMap + (uVar7 - 0xc));
    if (uVar6 == param_2) {
      sprintf(param_1->TBuff,s_Found_Resend_Ser__d_for_P__d,uVar6,uVar2);
      TDebuggingLog::Log(L,(char *)L,param_1->TBuff);
      pvStack_8 = operator_new(*(uint *)((int)param_1->Resend->DestMap + (uVar7 - 4)));
      this_00 = (TCommunications_Handler *)
                (*(int *)((int)param_1->Resend->DestMap + param_3 + -0x10) + -1);
      *(TCommunications_Handler **)((int)param_1->Resend->DestMap + param_3 + -0x10) = this_00;
      if (DAT_0062cf04 == 0) {
        pcVar8 = s____BAD_DCOID_0_NO_TX;
        goto LAB_0042b07b;
      }
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf19);
      this = *(TDebuggingLog **)((int)param_1->Resend->DestMap + (uVar7 - 4));
      TDebuggingLog::Log(this,(char *)L,s___>TX_RES_REP___d__d___d_,uVar2,param_2,this);
      iVar4 = (**(code **)(*DAT_0062c5ec + 0x68))
                        (DAT_0062c5ec,DAT_0062cf04,(param_1->PlayerOptions).dcoID[uVar2],0,
                         *(undefined4 *)((int)param_1->Resend->DestMap + (uVar7 - 8)),
                         *(undefined4 *)((int)param_1->Resend->DestMap + (uVar7 - 4)));
      uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf28);
      if (0x32 < uVar5 - uVar3) {
        TDebuggingLog::Log(this_01,(char *)L,s____TXResendReply_slow____ld_msec,uVar5 - uVar3);
      }
      if (iVar4 == 0) {
        pTStack_10 = (TDebuggingLog *)((int)&pTStack_10->Timestamp + 1);
        param_1->TXPacketLength =
             param_1->TXPacketLength + *(int *)((int)param_1->Resend->DestMap + (uVar7 - 4));
      }
      else {
        RGE_Comm_Error::ShowReturn(param_1->Err,iVar4,s_Resend_TX);
        iStack_18 = iStack_18 + 1;
      }
      pRVar1 = param_1->Resend;
      iVar4 = (int)**(char **)((int)pRVar1->DestMap + (uVar7 - 8));
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf42);
      TDebuggingLog::Log(L,(char *)L,s_COMM__>>>>>_RETRANSMIT_P__d_Ser_,uVar2,
                         *(undefined4 *)((int)pRVar1->DestMap + (uVar7 - 0xc)),iStack_14,iVar4,iVar4
                         ,*(undefined4 *)((int)pRVar1->DestMap + (uVar7 - 4)),
                         *(undefined4 *)((int)pRVar1->DestMap + param_3 + -0x10),uVar3);
      operator_delete(pvStack_8);
    }
    uVar7 = uVar7 + 0x38;
    iStack_14 = iStack_14 + 1;
    param_3 = param_3 + 0x38;
    if (0x6d98 < uVar7) {
      if ((pTStack_10 == (TDebuggingLog *)0x0) && (iStack_18 == 0)) {
        if ((param_1->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
          TDebuggingLog::Log(L,(char *)L,s_____Did_not_have_requested_Ser__,param_2,uVar2);
          iStack_4 = param_1->GTDSerialNo - 1;
          pvStack_8 = (void *)CONCAT31(pvStack_8._1_3_,0x59);
          TDebuggingLog::Log(this_02,(char *)L,s___>TX_RNSM___d__d___d_,uVar2,param_2,8);
          TCommunications_Handler::FastSend
                    (param_1,(param_1->PlayerOptions).dcoID[uVar2],&pvStack_8,8,0,0);
          TDebuggingLog::Log(this_03,(char *)L,s_____TX__No_such_message_as___d__,param_2);
          TCommunications_Handler::ClearTXForPlayer(param_1,uVar2);
        }
      }
      else {
        TDebuggingLog::Log(pTStack_10,(char *)L,s_RESEND_to_P__d_FULFILLED___GoodT,uVar2,pTStack_10,
                           iStack_18,pTStack_10->TBuff + iStack_18 + -0x28);
      }
      TCommunications_Handler::PurgeAcknowledgedStoredMessages(param_1);
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0042b095
// Address: 0042b095
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_GTD__TX_RESEND_REQ_to_P__d__Ser_: "GTD: TX RESEND REQ to P#%d  Ser#%d "
// [HELPER] s___: "]\n"
// [HELPER] s____BAD_DCOID_0_NO_TX: "+++BAD DCOID=0 NO TX"
// [HELPER] s____GetNextSequence_slow____ld_ms: "!!!GetNextSequence slow - %ld msec"
undefined4 __thiscall FUN_0042b095(int param_1,int param_2,int param_3)
{
  ulong uVar1;
  undefined1 *puVar2;
  int iVar3;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  int unaff_EDI;
  
  if (*(char *)(param_1 + 0x1514) != '\0') {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf8c);
    if ((param_2 != *(int *)(param_1 + 0x13e4 + param_3 * 4)) ||
       (499 < uVar1 - *(int *)(param_1 + 0x140c + param_3 * 4))) {
      *(int *)(param_1 + 0x13e4 + param_3 * 4) = param_2;
      *(ulong *)(param_1 + 0x140c + param_3 * 4) = uVar1;
      puVar2 = (undefined1 *)operator_new(8);
      *puVar2 = 0x58;
      *(int *)(puVar2 + 4) = param_2;
      TDebuggingLog::Log(this,(char *)L,s_GTD__TX_RESEND_REQ_to_P__d__Ser_,param_3,param_2);
      if (DAT_0062cf04 == 0) {
        TDebuggingLog::Log(this_00,(char *)L,s____BAD_DCOID_0_NO_TX);
        return 0;
      }
      debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xfa9);
      TDebuggingLog::Log(L,(char *)L,s___>TX_RES_REQ___d__d___d_,param_3,param_2,8);
      iVar3 = (**(code **)(*DAT_0062c5ec + 0x68))
                        (DAT_0062c5ec,DAT_0062cf04,*(undefined4 *)(param_1 + 0x1564 + param_3 * 4),0
                         ,puVar2,8);
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xfb8);
      if (0x32 < uVar1 - unaff_EDI) {
        TDebuggingLog::Log(this_01,(char *)L,s____GetNextSequence_slow____ld_ms,uVar1 - unaff_EDI);
      }
      operator_delete(puVar2);
      if (iVar3 == 0) {
        *(int *)(param_1 + 0x12c0) = *(int *)(param_1 + 0x12c0) + 8;
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042b1fc
// Address: 0042b1fc
// XREFS: None
// [HELPER] s____Too_many_commands_in_one_comm: "+++Too many commands in one comm turn.  Seq#=%d"
byte __thiscall FUN_0042b1fc(int param_1,int param_2)
{
  byte bVar1;
  
  if (param_2 != DAT_0062cf30) {
    DAT_0062cf30 = param_2;
    DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,1);
    return 1;
  }
  bVar1 = (char)DAT_0062cf2c + 1;
  DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,bVar1);
  if (bVar1 == 0xff) {
    TDebuggingLog::Log(L,(char *)L,s____Too_many_commands_in_one_comm,0xff);
    return 0;
  }
  if ((*(int *)(param_1 + 0x1558) == 4) && (100 < bVar1)) {
    DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,100);
    bVar1 = 100;
  }
  return bVar1;
}

// --------------------------------------------------

// Function: FUN_0042b26c
// Address: 0042b26c
// XREFS: None
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
int __thiscall
FUN_0042b26c(TCommunications_Handler *param_1,int param_2,byte param_3,byte *param_4,uint param_5)
{
  TDebuggingLog *this;
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  ulong uVar6;
  byte *pbVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint *puVar16;
  int iVar17;
  char *pcVar18;
  char *pcVar19;
  uint uStack_20;
  char acStack_c [12];
  
  uVar13 = 0;
  if (param_1->Multiplayer == 0) {
    return 0;
  }
  if (DAT_0062c5ec == (int *)0x0) {
    return 0;
  }
  if (param_1->GTDSerialNo == 0) {
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_SER_Not_set___no_transmit_done_);
    return 0;
  }
  pbVar4 = (byte *)operator_new(0xc);
  if ((((param_3 == 0x31) || (param_3 == 0x32)) || (param_3 == 0x3f)) || (param_3 == 0x41)) {
    TDebuggingLog::Log(L,(char *)L,s____BAD_Msg_type____ASSERT);
  }
  if (param_1->RGE_Guaranteed_Delivery == '\0') {
    uStack_20 = 8;
    pbVar4[8] = 0;
    pbVar4[9] = 0;
    pbVar4[10] = 0;
    pbVar4[0xb] = 0;
    iVar5 = 8;
  }
  else {
    *(uint *)(pbVar4 + 8) = param_1->GTDSerialNo;
    param_1->PlayerHighSerialNumber[param_1->Me] = param_1->GTDSerialNo;
    param_1->GTDSerialNo = param_1->GTDSerialNo + 1;
    iVar5 = 0xc;
    uStack_20 = 0xc;
  }
  this = (TDebuggingLog *)(iVar5 + param_5);
  if ((TDebuggingLog *)0xfa0 < this) {
    TDebuggingLog::Log(this,(char *)L,s_ERROR__Full_length_>__d__Header_,4000,iVar5,param_5);
  }
  pbVar4[1] = 0;
  *pbVar4 = 0;
  uVar6 = param_1->current_turn + (uint)(param_1->PlayerOptions).CommandTurnIncrement;
  puVar16 = param_1->DestMap;
  *(ulong *)(pbVar4 + 4) = uVar6;
  do {
    iVar5 = TCommunications_Handler::IsPlayerHuman(param_1,uVar13);
    if ((iVar5 == 0) || (uVar13 == param_1->Me)) {
      *puVar16 = 0;
    }
    else {
      *puVar16 = 0xf0;
    }
    uVar13 = uVar13 + 1;
    puVar16 = puVar16 + 1;
  } while (uVar13 <= param_1->MaxGamePlayers);
  if (((param_3 == 0x31) || (param_3 == 0x32)) || ((param_3 == 0x3f || (param_3 == 0x41)))) {
    TDebuggingLog::Log(L,(char *)L,s_ASSERT___BAD_MSG_TYPE);
  }
  else {
    bVar3 = TCommunications_Handler::GetNextSequence(param_1,uVar6);
    pbVar4[1] = bVar3;
    if (((param_1->PlayerOptions).ProgramState != COMM_STATE_RUNNING) && (bVar3 == 0)) {
      operator_delete(pbVar4);
      return -0x7788fef2;
    }
  }
  *pbVar4 = param_3;
  pbVar7 = (byte *)operator_new((uint)((int)&this->Timestamp + 1));
  pbVar14 = pbVar4;
  pbVar15 = pbVar7;
  for (uVar13 = uStack_20 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pbVar15 = *(undefined4 *)pbVar14;
    pbVar14 = pbVar14 + 4;
    pbVar15 = pbVar15 + 4;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pbVar15 = *pbVar14;
    pbVar14 = pbVar14 + 1;
    pbVar15 = pbVar15 + 1;
  }
  if (param_5 != 0) {
    pbVar14 = param_4;
    pbVar15 = pbVar7 + uStack_20;
    for (uVar13 = param_5 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pbVar15 = *(undefined4 *)pbVar14;
      pbVar14 = pbVar14 + 4;
      pbVar15 = pbVar15 + 4;
    }
    for (uVar13 = param_5 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pbVar15 = *pbVar14;
      pbVar14 = pbVar14 + 1;
      pbVar15 = pbVar15 + 1;
    }
  }
  iVar5 = 0;
  uVar13 = 0;
  puVar16 = param_1->DestMap;
  do {
    iVar8 = TCommunications_Handler::IsPlayerHuman(param_1,uVar13);
    if ((iVar8 == 0) || (uVar13 == param_1->Me)) {
      *puVar16 = 0;
    }
    else {
      *puVar16 = 0xf0;
      iVar5 = iVar5 + 1;
    }
    uVar13 = uVar13 + 1;
    puVar16 = puVar16 + 1;
  } while (uVar13 <= param_1->MaxGamePlayers);
  if (param_1->RGE_Guaranteed_Delivery == '\0') {
    if (iVar5 != 0) {
      if (DAT_0062cf04 == 0) {
        TDebuggingLog::Log(this_00,(char *)L,s____BAD_DCOID_0_NO_TX);
        return -0x7fffbffb;
      }
      uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10ee);
      iVar8 = (**(code **)(*DAT_0062c5ec + 0x68))(DAT_0062c5ec,DAT_0062cf04,param_2,0,pbVar7,this);
      uVar10 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10f9);
      if (0x32 < uVar10 - uVar9) {
        TDebuggingLog::Log(this_02,(char *)L,s____CommOut2_slow____ld_msec,uVar10 - uVar9);
      }
      if (param_2 == 0) {
        uVar13 = 1;
        iVar17 = 0;
        if (param_1->MaxGamePlayers != 0) {
          do {
            iVar11 = TCommunications_Handler::IsPlayerHuman(param_1,uVar13);
            if ((iVar11 != 0) && (uVar13 != param_1->Me)) {
              iVar17 = iVar17 + 1;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 <= param_1->MaxGamePlayers);
        }
      }
      else {
        iVar17 = 1;
      }
      if (iVar8 == 0) {
        param_1->TXPacketLength = param_1->TXPacketLength + iVar17 * (int)this;
      }
      goto LAB_0042b72a;
    }
  }
  else {
    if (this == (TDebuggingLog *)0x0) {
      TDebuggingLog::Log(L,(char *)L,s____Damaged_Msg_0b);
      return -0x7fffbffb;
    }
    if (iVar5 != 0) {
      if (DAT_0062cf04 == 0) {
        TDebuggingLog::Log(this_00,(char *)L,s____BAD_DCOID_0_NO_TX);
        param_1->GTDSerialNo = param_1->GTDSerialNo - 1;
        return -0x7fffbffb;
      }
      uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10aa);
      iVar8 = (**(code **)(*DAT_0062c5ec + 0x68))(DAT_0062c5ec,DAT_0062cf04,param_2,0,pbVar7,this);
      uVar10 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x10b5);
      if (0x32 < uVar10 - uVar9) {
        TDebuggingLog::Log(this_01,(char *)L,s____CommOut_slow____ld_msec,uVar10 - uVar9);
      }
      if (param_2 == 0) {
        uVar13 = 1;
        iVar17 = 0;
        if (param_1->MaxGamePlayers != 0) {
          do {
            iVar11 = TCommunications_Handler::IsPlayerHuman(param_1,uVar13);
            if ((iVar11 != 0) && (uVar13 != param_1->Me)) {
              iVar17 = iVar17 + 1;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 <= param_1->MaxGamePlayers);
        }
      }
      else {
        iVar17 = 1;
      }
      if (iVar8 == 0) {
        param_1->TXPacketLength = param_1->TXPacketLength + iVar17 * (int)this;
        TCommunications_Handler::StoreForResend
                  (param_1,*(uint *)(pbVar4 + 8),(char *)pbVar7,(uint)this,param_1->DestMap);
      }
      else {
        param_1->GTDSerialNo = param_1->GTDSerialNo - 1;
        RGE_Comm_Error::ShowReturn(param_1->Err,iVar8,s_TX_RGTGTD);
      }
      goto LAB_0042b72a;
    }
  }
  iVar8 = 0;
LAB_0042b72a:
  if (iVar5 != 0) {
    pcVar18 = s_GTD;
    if (param_1->RGE_Guaranteed_Delivery == '\0') {
      pcVar18 = &s__GTD;
    }
    uVar13 = 0xffffffff;
    do {
      pcVar19 = pcVar18;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar19 = pcVar18 + 1;
      cVar1 = *pcVar18;
      pcVar18 = pcVar19;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar18 = pcVar19 + -uVar13;
    pcVar19 = acStack_c;
    for (uVar12 = uVar13 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pcVar19 = *(undefined4 *)pcVar18;
      pcVar18 = pcVar18 + 4;
      pcVar19 = pcVar19 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar19 = *pcVar18;
      pcVar18 = pcVar18 + 1;
      pcVar19 = pcVar19 + 1;
    }
    bVar3 = pbVar7[uStack_20];
    bVar2 = *pbVar4;
    uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x112b);
    TDebuggingLog::Log(L,(char *)L,s_COMM__Ser__d__s_TX_To__d_Len__d_,*(undefined4 *)(pbVar4 + 8),
                       acStack_c,param_2,param_5,uStack_20,(uint)pbVar4[1],
                       *(undefined4 *)(pbVar4 + 4),(uint)bVar2,(uint)bVar2,(int)(char)bVar3,
                       (int)(char)bVar3,iVar5,iVar8,uVar9);
  }
  if (iVar8 == 0) {
    param_1->TXPackets = param_1->TXPackets + 1;
    if (param_3 == 0x3e) {
      TCommunications_Handler::AddCommand(param_1,uVar6,param_4,param_5,param_1->Me,pbVar4[1],0);
    }
  }
  else {
    RGE_Comm_Error::ShowReturn(param_1->Err,iVar8,s_TX);
  }
  operator_delete(pbVar4);
  operator_delete(pbVar7);
  return iVar8;
}

// --------------------------------------------------

// Function: FUN_0042b851
// Address: 0042b851
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_com_hand_h: "C:\msdev\work\age1_x1\com_hand.h"
// [HELPER] s_Initialize_Player_List: "Initialize Player List"
// [HELPER] s__: "}"
void __fastcall FUN_0042b851(TCommunications_Handler *param_1)
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
  
  TCommunications_Handler::DestroyMyPlayer(param_1);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_com_hand_h,0x267);
  param_1->RXPacketLength = 0;
  param_1->RXPacketLengthHigh = 0;
  param_1->TXPacketLength = 0;
  param_1->TXPacketLengthHigh = 0;
  param_1->lastRXDataRate = 0.0;
  param_1->lastTXDataRate = 0.0;
  param_1->HoldCount = 0;
  param_1->ServiceTimeout = 0;
  param_1->TXPackets = 0;
  param_1->RXPackets = 0;
  param_1->RGE_Guaranteed_Delivery = '\0';
  param_1->ResendAcknowledgements = 0;
  param_1->ResentToOther = 0;
  param_1->DroppedPacketCount = 0;
  param_1->LobbyLaunched = 0;
  param_1->GTDSerialNo = 0;
  param_1->dwStopTime = 0;
  param_1->OutOfSyncFlag = 0;
  TDebuggingLog::Time(L);
  uVar5 = 0xffffffff;
  param_1->AvgTurnTime = 0;
  param_1->PauseChangePending = 0;
  param_1->StepMode = 0;
  param_1->IntentionallyDropPackets = 0;
  (param_1->PlayerOptions).LastSentTime = uVar3;
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
  pcVar9 = param_1->MyGameTitle;
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
  pcVar9 = param_1->MyFriendlyName;
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
  pcVar9 = param_1->MyFormalName;
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
  uVar2 = param_1->MaxGamePlayers;
  param_1->TickStart = 0;
  param_1->TickCount = 0;
  param_1->LastTimeoutMessageTime = 0;
  (param_1->PlayerOptions).LowPlayerNumber = 1;
  (param_1->PlayerOptions).HighPlayerNumber = uVar2;
  (param_1->PlayerOptions).GameHasStarted = 0;
  (param_1->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
  param_1->MeHost = 0;
  param_1->HaveHostInit = 0;
  (param_1->PlayerOptions).CommandTurnIncrement = '\x02';
  param_1->current_turn = 4;
  (param_1->PlayerOptions).CurrentTurn = 4;
  (param_1->PlayerOptions).NeedsToBeSent = '\0';
  param_1->AcknowledgeAfterMsec = 0x32;
  param_1->Me = 0;
  param_1->Multiplayer = 0;
  param_1->turnstart = 0;
  param_1->mselapsed = 0;
  TDebuggingLog::Log((TDebuggingLog *)(uint)uVar2,(char *)L,s_Initialize_Player_List);
  uVar5 = 1;
  if (param_1->MaxGamePlayers != 0) {
    do {
      TCommunications_Handler::InitPlayerInformation(param_1,uVar5,0,&s__,&s__);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 <= (int)(uint)param_1->MaxGamePlayers);
  }
  (param_1->PlayerOptions).NeedsToBeSent = '\0';
  (param_1->PlayerOptions).LastSentTime = 0;
  TCommunications_Handler::ClearAllSerialNumbers(param_1);
  TCommunications_Handler::ClearRXandTX(param_1);
  puVar10 = param_1->PlayerStopTurn;
  for (iVar7 = 9; puVar10 = puVar10 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = 0;
  }
  param_1->Steps = 1;
  TCommunications_Handler::ResetLastCommunicationTimes(param_1);
  param_1->WaitingForAck = 0;
  if (param_1->InQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(param_1->InQ);
  }
  if (param_1->OutQ != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::FlushAll(param_1->OutQ);
  }
  param_1->ShuttingDown = 0;
  piVar4 = param_1->Kicked;
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

// Function: FUN_0042bacb
// Address: 0042bacb
// XREFS: None
void __fastcall FUN_0042bacb(TCommunications_Handler *param_1)
{
  COMMSTATUS CVar1;
  
  CVar1 = TCommunications_Handler::AnalyzeCommunicationsStatus(param_1);
  param_1->CommunicationsStatus = CVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0042c683
// Address: 0042c683
// XREFS: None
int __fastcall FUN_0042c683(TCommunications_Handler *param_1)
{
  int iVar1;
  _GUID *p_Var2;
  _GUID *p_Var3;
  bool bVar4;
  
  iVar1 = TCommunications_Handler::IsPaused(param_1);
  if ((iVar1 != 0) && (5 < param_1->current_turn)) {
    return 0xf;
  }
  if ((param_1->PlayerOptions).ProgramState == COMM_STATE_RUNNING) {
    if (5 < param_1->current_turn) {
      return 0xe;
    }
    if (param_1->current_turn < 6) {
      return 0xd;
    }
  }
  if ((param_1->PlayerOptions).NeedsToBeSent != '\0') {
    return 0xc;
  }
  if (DAT_0062cf04 != 0) {
    return 9;
  }
  if (param_1->MeHost != 0) {
    return 7;
  }
  iVar1 = 0x10;
  bVar4 = true;
  p_Var2 = &param_1->SessionGUID;
  p_Var3 = &param_1->NullGUID;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = (char)p_Var2->Data1 == (char)p_Var3->Data1;
    p_Var2 = (_GUID *)((int)&p_Var2->Data1 + 1);
    p_Var3 = (_GUID *)((int)&p_Var3->Data1 + 1);
  } while (bVar4);
  if (!bVar4) {
    return 6;
  }
  iVar1 = 0x10;
  bVar4 = true;
  p_Var2 = &param_1->ServiceGUID;
  p_Var3 = &param_1->NullGUID;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = (char)p_Var2->Data1 == (char)p_Var3->Data1;
    p_Var2 = (_GUID *)((int)&p_Var2->Data1 + 1);
    p_Var3 = (_GUID *)((int)&p_Var3->Data1 + 1);
  } while (bVar4);
  if (!bVar4) {
    return 5;
  }
  if (DAT_0062c5ec == 0) {
    if (param_1->Multiplayer == 0) {
      return 2 - (uint)(param_1->Me != 1);
    }
    return 3;
  }
  return 4;
}

// --------------------------------------------------

// Function: FUN_0042c799
// Address: 0042c799
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
void __fastcall FUN_0042c799(int param_1)
{
  ulong uVar1;
  ulong *puVar2;
  int iVar3;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1282);
  iVar3 = 1;
  if (*(short *)(param_1 + 0x12d8) != 0) {
    puVar2 = (ulong *)(param_1 + 0x1398);
    do {
      puVar2[-0x14] = uVar1;
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 <= (int)(uint)*(ushort *)(param_1 + 0x12d8));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042c7e3
// Address: 0042c7e3
// XREFS: None
bool __fastcall FUN_0042c7e3(int param_1)
{
  return *(int *)(param_1 + 0x1558) == 4;
}

// --------------------------------------------------

// Function: FUN_0042c7ff
// Address: 0042c7ff
// XREFS: None
void __fastcall FUN_0042c7ff(TCommunications_Handler *param_1)
{
  uint uVar1;
  
  if (((param_1->MeHost != 0) && (param_1->current_turn < 7)) &&
     (uVar1 = 1, param_1->MaxGamePlayers != 0)) {
    do {
      TCommunications_Handler::Kick(param_1,uVar1);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= (int)(uint)param_1->MaxGamePlayers);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042c83b
// Address: 0042c83b
// XREFS: None
void __thiscall FUN_0042c83b(TCommunications_Handler *param_1,long param_2)
{
  (param_1->PlayerOptions).ProgramState = COMM_STATE_RUNNING;
  TCommunications_Handler::NotifyWindowParam(param_1,COMM_RESUME,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0042c85c
// Address: 0042c85c
// XREFS: None
void __thiscall FUN_0042c85c(TCommunications_Handler *param_1,long param_2)
{
  (param_1->PlayerOptions).ProgramState = COMM_STATE_PAUSE;
  TCommunications_Handler::NotifyWindowParam(param_1,COMM_PAUSE,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0042c87c
// Address: 0042c87c
// XREFS: None
// [HELPER] s___: "]\n"
void __thiscall FUN_0042c87c(TCommunications_Handler *param_1,int param_2)
{
  if ((param_1->Multiplayer != 0) && (param_1->MeHost != 0)) {
    if (param_2 != 0) {
      TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s___>TX_PAUSE);
      TCommunications_Handler::CommOut(param_1,0,'P',(void *)0x0,0,'\0');
      return;
    }
    TDebuggingLog::Log(L,(char *)L,s___>TX_RESUME);
    TCommunications_Handler::CommOut(param_1,0,'U',(void *)0x0,0,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042c8ed
// Address: 0042c8ed
// XREFS: None
undefined4 __fastcall FUN_0042c8ed(TCommunications_Handler *param_1)
{
  int iVar1;
  
  if (param_1->PauseChangePending != 0) {
    return 0;
  }
  iVar1 = TCommunications_Handler::IsPaused(param_1);
  if (iVar1 != 0) {
    TCommunications_Handler::RequestResumeGame(param_1,0);
    return 1;
  }
  TCommunications_Handler::RequestPauseGame(param_1,0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042c928
// Address: 0042c928
// XREFS: None
// [HELPER] s___: "]\n"
void __fastcall FUN_0042c928(TCommunications_Handler *param_1)
{
  if (param_1->Multiplayer == 0) {
    TCommunications_Handler::LocalPauseGame(param_1,param_1->Me);
    return;
  }
  if (param_1->MeHost != 0) {
    TCommunications_Handler::SendPauseGame(param_1,1);
    TCommunications_Handler::LocalPauseGame(param_1,param_1->Me);
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s___>TX_REQ_PAUSE);
  TCommunications_Handler::CommOut(param_1,0,'W',(void *)0x0,0,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_0042c998
// Address: 0042c998
// XREFS: None
// [HELPER] s_Resume_requested: "Resume requested"
// [HELPER] s___: "]\n"
void __fastcall FUN_0042c998(TCommunications_Handler *param_1)
{
  if (param_1->Multiplayer == 0) {
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_Resume_requested);
    TCommunications_Handler::LocalResumeGame(param_1,param_1->Me);
    return;
  }
  if (param_1->MeHost != 0) {
    TCommunications_Handler::SendPauseGame(param_1,0);
    TCommunications_Handler::LocalResumeGame(param_1,param_1->Me);
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s___>TX_REQ_RES);
  TCommunications_Handler::CommOut(param_1,0,'+',(void *)0x0,0,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_0042ca1c
// Address: 0042ca1c
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
void __thiscall FUN_0042ca1c(TCommunications_Handler *param_1,ulong param_2)
{
  ulong uVar1;
  
  if (param_1->MeHost != 0) {
    if (param_2 == 0xffffffff) {
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1320);
      debug_srand(s_C__msdev_work_age1_x1_Com_hand_c,0x1320,uVar1);
      param_2 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x1321);
    }
    (param_1->PlayerOptions).RandomSeed = param_2;
    (param_1->PlayerOptions).NeedsToBeSent = '\x01';
    TCommunications_Handler::SendSharedData(param_1,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042ca84
// Address: 0042ca84
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
undefined4 __fastcall FUN_0042ca84(int param_1)
{
  ulong uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x10e4) == 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1336);
    debug_srand(s_C__msdev_work_age1_x1_Com_hand_c,0x1336,uVar1);
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x1337);
    *(int *)(param_1 + 0x170c) = iVar2;
  }
  return *(undefined4 *)(param_1 + 0x170c);
}

// --------------------------------------------------

// Function: FUN_0042cae2
// Address: 0042cae2
// XREFS: None
undefined4 __fastcall FUN_0042cae2(int param_1)
{
  return *(undefined4 *)(param_1 + 0x10e0);
}

// --------------------------------------------------

// Function: FUN_0042caf7
// Address: 0042caf7
// XREFS: None
undefined4 __fastcall FUN_0042caf7(int param_1)
{
  if (*(int *)(param_1 + 0x10e4) != 0) {
    return *(undefined4 *)(param_1 + 0x1c);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042cb14
// Address: 0042cb14
// XREFS: None
undefined4 FUN_0042cb14(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042cb23
// Address: 0042cb23
// XREFS: None
// [HELPER] s_Ready_________________________: "Ready=                        "
undefined4 * __fastcall FUN_0042cb23(int param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
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
  if (*(short *)(param_1 + 0x12d8) != 0) {
    puVar4 = (undefined4 *)(param_1 + 0x16d8);
    do {
      if ((uint)puVar4[0x13] < *(uint *)(param_1 + 0x10c8)) {
        switch(*puVar4) {
        case 0:
          (&UNK_0062c5b6)[uVar3] = 0x2d;
          break;
        default:
          (&UNK_0062c5b6)[uVar3] = 0x3f;
          break;
        case 2:
          (&UNK_0062c5b6)[uVar3] = 0x57;
          break;
        case 4:
          (&UNK_0062c5b6)[uVar3] = 0x43;
          break;
        case 5:
          (&UNK_0062c5b6)[uVar3] = 0x58;
          break;
        case 6:
          (&UNK_0062c5b6)[uVar3] = 0x56;
        }
      }
      else {
        (&UNK_0062c5b6)[uVar3] = 0x41;
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 <= *(ushort *)(param_1 + 0x12d8));
  }
  return &DAT_0062c5b0;
}

// --------------------------------------------------

// Function: FUN_0042cbe3
// Address: 0042cbe3
// XREFS: None
void FUN_0042cbe3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0042cc25
// Address: 0042cc25
// XREFS: None
void __thiscall FUN_0042cc25(TCommunications_Handler *param_1,uint param_2,PLAYERHUMANITY param_3)
{
  if ((param_2 != 0) && (param_2 <= param_1->MaxGamePlayers)) {
    (param_1->PlayerOptions).Humanity[param_2] = param_3;
    TCommunications_Handler::UpdatePlayer(param_1,param_2,1);
    TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PARAMS);
    if ((param_1->MeHost != 0) && ((param_1->PlayerOptions).ProgramState == COMM_STATE_JOINNOW)) {
      (param_1->PlayerOptions).NeedsToBeSent = '\x01';
      TCommunications_Handler::SendSharedData(param_1,0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042cc8e
// Address: 0042cc8e
// XREFS: None
int __fastcall FUN_0042cc8e(TCommunications_Handler *param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = TCommunications_Handler::IsPlayerHuman(param_1,uVar3);
    if ((iVar1 != 0) ||
       (iVar1 = TCommunications_Handler::IsPlayerComputer(param_1,uVar3), iVar1 != 0)) {
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 <= (int)(uint)param_1->MaxGamePlayers);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0042cccf
// Address: 0042cccf
// XREFS: None
undefined4 __thiscall FUN_0042cccf(int param_1,uint param_2)
{
  int iVar1;
  
  if (((param_2 != 0) && (param_2 <= *(ushort *)(param_1 + 0x12d8))) &&
     ((iVar1 = *(int *)(param_1 + 0x16d4 + param_2 * 4), iVar1 == 2 || (iVar1 == 5)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042cd04
// Address: 0042cd04
// XREFS: None
bool __thiscall FUN_0042cd04(int param_1,uint param_2)
{
  if ((param_2 != 0) && (param_2 <= *(ushort *)(param_1 + 0x12d8))) {
    return *(int *)(param_1 + 0x16d4 + param_2 * 4) == 4;
  }
  return false;
}

// --------------------------------------------------

// Function: FUN_0042cd42
// Address: 0042cd42
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_Client: "Client"
// [HELPER] s_Host: "Host"
// [HELPER] s_LastComm__P1___5d__P2___5d__P3__: "LastComm: P1=%-5d  P2=%-5d  P3=%-5d  P4=%-5d P5=%-5d P6=%-5d P7=%-5d P8=%-5d"
// [HELPER] s_P_d_T__6ld____7s___s__TX___0_1f_: "P%d T#%6ld [%.7s] %s  TX: %0.1f  RX: %0.1f"
// [HELPER] s__: "}"
// [HELPER] s__s__DPMsgs_d_: "%s  DPMsgs%d "
// [HELPER] s__s__Speed_Adjusts__d_: "%s  Speed Adjusts=%d "
undefined4 * __thiscall FUN_0042cd42(TCommunications_Handler *param_1,char param_2)
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
  int iStack_118;
  int iStack_110;
  int iStack_10c;
  int iStack_108;
  int iStack_104;
  char acStack_100 [256];
  
  iVar9 = 0;
  pcVar12 = (char *)&DAT_0062c6f0;
  if (param_1->Multiplayer == 0) {
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
    pcVar12 = s_;
    do {
      pcVar10 = pcVar12;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar10 = pcVar12 + 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar10;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6;
    pcVar12 = pcVar10 + -uVar6;
    pcVar10 = acStack_100;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar10 = pcVar10 + 4;
    }
    iVar4 = param_1->MeHost;
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar10 = pcVar10 + 1;
    }
    pcVar12 = s_Host;
    if (iVar4 == 0) {
      pcVar12 = &s_Client;
    }
    uVar6 = 0xffffffff;
    do {
      pcVar10 = pcVar12;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar10 = pcVar12 + 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar10;
    } while (cVar2 != '\0');
    fVar1 = param_1->lastRXDataRate;
    uVar6 = ~uVar6;
    pcVar12 = pcVar10 + -uVar6;
    pcVar10 = acStack_100;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar10 = pcVar10 + 4;
    }
    dVar14 = (double)fVar1;
    dVar13 = (double)param_1->lastTXDataRate;
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar10 = pcVar10 + 1;
    }
    pcVar12 = TCommunications_Handler::GetReadyPlayerStr(param_1);
    sprintf(&DAT_0062c6f0,s_P_d_T__6ld____7s___s__TX___0_1f_,param_1->Me,param_1->current_turn,
            acStack_100,pcVar12,dVar13,dVar14);
    RGE_Communications_Speed::GetLatencyInfo(param_1->Speed);
    sprintf();
    RGE_Communications_Speed::GetAdjustmentCount(param_1->Speed);
    pcVar12 = RGE_Communications_Speed::GetMachineSpeedInfo(param_1->Speed);
    sprintf(0x62c8f0,s__s__Speed_Adjusts__d_,pcVar12);
    (**(code **)(*DAT_0062c5ec + 0x44))();
    pcVar12 = RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(param_1->Speed);
    sprintf(0x62c9f0,s__s__DPMsgs_d_,pcVar12);
    RGE_Communications_Speed::GetPlayerSpeedStatusStr(param_1->Speed,0);
    sprintf();
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1468);
    iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,8);
    if ((iVar4 == 0) || (param_1->Me == 8)) {
      iStack_104 = 0;
    }
    else {
      iStack_104 = uVar3 - param_1->LastPlayerCommunication[8];
    }
    iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,7);
    if ((iVar4 == 0) || (param_1->Me == 7)) {
      iStack_10c = 0;
    }
    else {
      iStack_10c = uVar3 - param_1->LastPlayerCommunication[7];
    }
    iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,6);
    if ((iVar4 == 0) || (param_1->Me == 6)) {
      iStack_118 = 0;
    }
    else {
      iStack_118 = uVar3 - param_1->LastPlayerCommunication[6];
    }
    iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,5);
    if ((iVar4 == 0) || (param_1->Me == 5)) {
      iStack_110 = 0;
    }
    else {
      iStack_110 = uVar3 - param_1->LastPlayerCommunication[5];
    }
    iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,4);
    if ((iVar4 == 0) || (param_1->Me == 4)) {
      iStack_108 = 0;
    }
    else {
      iStack_108 = uVar3 - param_1->LastPlayerCommunication[4];
    }
    iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,3);
    if ((iVar4 != 0) && (param_1->Me != 3)) {
      iVar9 = uVar3 - param_1->LastPlayerCommunication[3];
    }
    iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,2);
    if ((iVar4 == 0) || (param_1->Me == 2)) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar3 - param_1->LastPlayerCommunication[2];
    }
    iVar5 = TCommunications_Handler::IsPlayerHuman(param_1,1);
    if ((iVar5 == 0) || (param_1->Me == 1)) {
      iVar5 = 0;
    }
    else {
      iVar5 = uVar3 - param_1->LastPlayerCommunication[1];
    }
    sprintf(0x62cbf0,s_LastComm__P1___5d__P2___5d__P3__,iVar5,iVar4,iVar9,iStack_108,iStack_110,
            iStack_118,iStack_10c,iStack_104);
  }
  return &DAT_0062c6f0 + (uint)(byte)(param_2 - 1) * 0x40;
}

// --------------------------------------------------

// Function: FUN_0042d0d6
// Address: 0042d0d6
// XREFS: None
int __thiscall FUN_0042d0d6(int param_1,uint param_2)
{
  if (*(ushort *)(param_1 + 0x12d8) < param_2) {
    return 0;
  }
  if (param_2 == *(uint *)(param_1 + 0x10e0)) {
    return param_1 + 0x10f8;
  }
  return *(int *)(param_1 + 0x12c8) + param_2 * 0x80;
}

// --------------------------------------------------

// Function: FUN_0042d115
// Address: 0042d115
// XREFS: None
void __thiscall
FUN_0042d115(TCommunications_Handler *param_1,ulong param_2,char *param_3,char *param_4)
{
  uint uVar1;
  ulong *puVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    uVar1 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
    uVar3 = (uint)(param_1->PlayerOptions).HighPlayerNumber;
    if (uVar1 <= uVar3) {
      puVar2 = (param_1->PlayerOptions).dcoID + uVar1;
      do {
        if (*puVar2 == param_2) goto LAB_0042d155;
        uVar1 = uVar1 + 1;
        puVar2 = puVar2 + 1;
      } while ((int)uVar1 <= (int)uVar3);
    }
  }
  uVar1 = 0;
LAB_0042d155:
  if (uVar1 == 0) {
    TCommunications_Handler::InitPlayerInformation(param_1,0,param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042d17b
// Address: 0042d17b
// XREFS: None
// [HELPER] s_Release_count____d: "Release count = %d"
IDirectPlay3 * __fastcall FUN_0042d17b(TCommunications_Handler *param_1)
{
  byte bVar1;
  undefined4 uVar3;
  TDebuggingLog *this;
  IDirectPlay3 *pIStack_58;
  char *pcStack_54;
  DPSESSIONDESC2 DStack_50;
  int *piVar2;
  
  pIStack_58 = (IDirectPlay3 *)0x0;
  bVar1 = RGE_Lobby::CheckForLobbyLaunch(param_1->Lobby,&pIStack_58);
  piVar2 = (int *)(uint)bVar1;
  if (piVar2 != (int *)0x0) {
    if (DAT_0062c5ec != (IDirectPlay3 *)0x0) {
      uVar3 = (**(code **)((int)*DAT_0062c5ec + 8))(DAT_0062c5ec);
      TDebuggingLog::Log(this,(char *)L,s_Release_count____d,uVar3);
    }
    DAT_0062c5ec = pIStack_58;
    if (pIStack_58 == (IDirectPlay3 *)0x0) {
      return pIStack_58;
    }
    bVar1 = RGE_Lobby::GetSessionInfo(param_1->Lobby,&DStack_50);
    piVar2 = (int *)(uint)bVar1;
    if (piVar2 != (int *)0x0) {
      TCommunications_Handler::DebugSessionInformation(param_1,&DStack_50);
    }
    TCommunications_Handler::CommGetCaps(param_1);
    param_1->Multiplayer = 1;
    TCommunications_Handler::DPlayGetSessionDesc(param_1);
    RGE_Lobby::GetPlayerInfo(param_1->Lobby,&pcStack_54);
    TCommunications_Handler::SetMyPlayerName(param_1,pcStack_54);
    (param_1->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    TCommunications_Handler::AddSelfPlayer(param_1);
    bVar1 = RGE_Lobby::IsThisHost(param_1->Lobby);
    param_1->MeHost = (uint)bVar1;
    if (bVar1 != 0) {
      param_1->Me = 1;
      (param_1->PlayerOptions).dcoID[1] = DAT_0062cf04;
      (param_1->PlayerOptions).Humanity[param_1->Me] = ME_HUMAN;
      param_1->HaveHostInit = 1;
      (param_1->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
      TCommunications_Handler::SetRandomSeed(param_1,rge_base_game->random_game_seed);
      param_1->GTDSerialNo = 0x7d1;
    }
    TCommunications_Handler::UpdatePlayers(param_1);
  }
  param_1->LobbyLaunched = (int)piVar2;
  return (IDirectPlay3 *)piVar2;
}

// --------------------------------------------------

// Function: FUN_0042d2c9
// Address: 0042d2c9
// XREFS: None
// [HELPER] s_Player__d___ld__is_INITIALIZED_a: "Player %d (%ld) is INITIALIZED as '%s' [%s]."
void __thiscall
FUN_0042d2c9(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,TDebuggingLog *param_5)
{
  if ((param_2 != 0) && (param_2 <= *(ushort *)(param_1 + 0x12d8))) {
    *(undefined4 *)(param_1 + 0x1594 + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x15bc + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x15e4 + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x160c + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x1634 + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x165c + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x1684 + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x16ac + param_2 * 4) = 0;
    *(undefined1 *)(param_1 + 0x16fc + param_2) = 0;
    *(undefined4 *)(param_1 + 0x1720 + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x16d4 + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x1564 + param_2 * 4) = param_3;
    *(undefined4 *)(param_1 + 0x1528 + param_2 * 4) = 0;
    *(undefined4 *)(param_1 + 0x1484) = 0;
    *(undefined4 *)(param_1 + 0x1488) = 0;
    *(undefined4 *)(param_1 + 0x148c) = 0;
    *(undefined4 *)(param_1 + 0x1490) = 0;
    *(undefined4 *)(param_1 + 0x1494) = 0;
    *(undefined4 *)(param_1 + 0x1498) = 0;
    if (*(RGE_Communications_Queue **)(param_1 + 0x14c4) != (RGE_Communications_Queue *)0x0) {
      RGE_Communications_Queue::FlushForPlayer
                (*(RGE_Communications_Queue **)(param_1 + 0x14c4),param_2);
    }
    TDebuggingLog::Log(param_5,(char *)L,s_Player__d___ld__is_INITIALIZED_a,param_2,param_3,param_4,
                       param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042d3a9
// Address: 0042d3a9
// XREFS: None
// [HELPER] s__s___s_: "%s [%s]"
undefined4 __thiscall FUN_0042d3a9(int param_1,undefined4 param_2)
{
  sprintf(param_1 + 0x11fa,s__s___s_,param_2,param_1 + 0x10f8);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042d3d8
// Address: 0042d3d8
// XREFS: None
// [HELPER] s_Optional_Information: "Optional Information"
void __thiscall FUN_0042d3d8(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
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
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x10f8);
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
  pcVar5 = (char *)(param_1 + 0x1179);
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

// Function: FUN_0042d43a
// Address: 0042d43a
// XREFS: None
void __thiscall FUN_0042d43a(TCommunications_Handler *param_1,uint param_2,char *param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == param_1->Me) {
    TCommunications_Handler::SetMyPlayerName(param_1,param_3);
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_3;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  uVar3 = uVar2 >> 2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = param_1->FriendlyName[param_2].Text;
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

// Function: FUN_0042d48e
// Address: 0042d48e
// XREFS: None
void __thiscall FUN_0042d48e(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x130c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0042d49d
// Address: 0042d49d
// XREFS: None
// [HELPER] s_Already_have_conversation_: "Already have conversation."
// [HELPER] s_DPCreate: "DPCreate"
// [HELPER] s_Get_glpIDC_returns____ld: "Get glpIDC returns...%ld"
// [HELPER] s_Release__Links__d: "Release: Links=%d"
int __fastcall FUN_0042d49d(undefined4 *param_1)
{
  int iVar1;
  undefined4 uVar2;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  int *unaff_EDI;
  undefined4 *puStack_4;
  
  puStack_4 = param_1;
  iVar1 = _DirectPlayCreate_12(param_1 + 0x4b7,&puStack_4,0);
  RGE_Comm_Error::ShowReturn((RGE_Comm_Error *)param_1[0x538],iVar1,s_DPCreate);
  if (DAT_0062c5ec != 0) {
    TDebuggingLog::Log(L,(char *)L,s_Already_have_conversation_);
    return -0x7788fffb;
  }
  if (iVar1 != 0) {
    param_1[0x4b7] = param_1[0x4c6];
    param_1[0x4b8] = param_1[0x4c7];
    param_1[0x4b9] = param_1[0x4c8];
    param_1[0x4ba] = param_1[0x4c9];
    return iVar1;
  }
  if (puStack_4 != (undefined4 *)0x0) {
    iVar1 = (**(code **)*puStack_4)(puStack_4,&_IID_IDirectPlay3A,&DAT_0062c5ec);
    if (iVar1 != 0) {
      TDebuggingLog::Log(this,(char *)L,s_Get_glpIDC_returns____ld,iVar1);
      return iVar1;
    }
    uVar2 = (**(code **)(*unaff_EDI + 8))(unaff_EDI);
    TDebuggingLog::Log(this_00,(char *)L,s_Release__Links__d,uVar2);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042d579
// Address: 0042d579
// XREFS: None
undefined4 FUN_0042d579(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0042d584
// Address: 0042d584
// XREFS: None
// [HELPER] s_DPCreateConv: "DPCreateConv"
// [HELPER] s_DP_Open_Create: "DP Open Create"
undefined4 __fastcall FUN_0042d584(TCommunications_Handler *param_1)
{
  TChat *this;
  long lVar1;
  int iVar2;
  DPSESSIONDESC2 *pDVar3;
  DPSESSIONDESC2 DStack_50;
  
  this = param_1->Chat;
  param_1->Multiplayer = 1;
  param_1->HaveHostInit = 0;
  (param_1->PlayerOptions).CommandTurnIncrement = '\x02';
  param_1->current_turn = 4;
  (param_1->PlayerOptions).CurrentTurn = 4;
  TChat::ClearChat(this);
  lVar1 = TCommunications_Handler::CreateDirectPlayConversation(param_1);
  RGE_Comm_Error::ShowReturn(param_1->Err,lVar1,s_DPCreateConv);
  param_1->MeHost = 1;
  pDVar3 = &DStack_50;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    pDVar3->dwSize = 0;
    pDVar3 = (DPSESSIONDESC2 *)&pDVar3->dwFlags;
  }
  DStack_50.dwMaxPlayers = (ulong)param_1->MaxGamePlayers;
  DStack_50.dwSize = 0x50;
  DStack_50.guidApplication.Data1 = (param_1->ApplicationGUID).Data1;
  DStack_50.dwCurrentPlayers = 1;
  DStack_50.dwFlags = 0x44;
  DStack_50.guidApplication.Data2 = (param_1->ApplicationGUID).Data2;
  DStack_50.guidApplication.Data3 = (param_1->ApplicationGUID).Data3;
  DStack_50.guidApplication.Data4._0_4_ = *(undefined4 *)(param_1->ApplicationGUID).Data4;
  DStack_50.guidApplication.Data4._4_4_ = *(undefined4 *)((param_1->ApplicationGUID).Data4 + 4);
  DStack_50.field6_0x30.lpszSessionName = (ushort *)param_1->MyGameTitle;
  TCommunications_Handler::DebugSessionInformation(param_1,&DStack_50);
  iVar2 = (**(code **)(*DAT_0062c5ec + 0x60))(DAT_0062c5ec,&DStack_50,2);
  RGE_Comm_Error::ShowReturn(param_1->Err,iVar2,s_DP_Open_Create);
  if (iVar2 != 0) {
    if (iVar2 == -0x7788ff56) {
      TCommunications_Handler::NotifyWindow(param_1,COMM_NO_LINK);
      return 0;
    }
    (param_1->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    return 0;
  }
  TCommunications_Handler::SetRandomSeed(param_1,rge_base_game->random_game_seed);
  TCommunications_Handler::AddSelfPlayer(param_1);
  TCommunications_Handler::CommGetCaps(param_1);
  TCommunications_Handler::DPlayGetSessionDesc(param_1);
  param_1->Me = 1;
  (param_1->PlayerOptions).HostPlayerNumber = 1;
  (param_1->PlayerOptions).dcoID[1] = DAT_0062cf04;
  (param_1->PlayerOptions).Humanity[param_1->Me] = ME_HUMAN;
  param_1->HaveHostInit = 1;
  (param_1->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
  param_1->GTDSerialNo = 0x7d1;
  TCommunications_Handler::UpdatePlayers(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042d712
// Address: 0042d712
// XREFS: None
// [HELPER] s_Position__d__LOCKED_____Plr__s: "Position %d *LOCKED*.   Plr=%s"
// [HELPER] s__: "}"
void __fastcall FUN_0042d712(TCommunications_Handler *param_1)
{
  char cVar1;
  TDebuggingLog *this;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  TDebuggingLog *this_00;
  uint uVar6;
  char *pcVar7;
  int iStack_10;
  uint uStack_c;
  ulong *puStack_8;
  
  uStack_c = 1;
  if (param_1->MaxGamePlayers == 0) {
LAB_0042d946:
    TCommunications_Handler::SetSelfPlayer(param_1);
    return;
  }
  puStack_8 = (param_1->PlayerOptions).dcoID;
  iStack_10 = 0x80;
LAB_0042d751:
  puStack_8 = puStack_8 + 1;
  iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,uStack_c);
  if ((iVar2 == 0) &&
     (iVar2 = TCommunications_Handler::IsPlayerComputer(param_1,uStack_c), iVar2 == 0)) {
    uVar6 = uStack_c;
    if ((int)uStack_c <= (int)(uint)param_1->MaxGamePlayers) {
      do {
        iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,uVar6);
        if ((iVar2 != 0) ||
           (iVar2 = TCommunications_Handler::IsPlayerComputer(param_1,uVar6), iVar2 != 0)) {
          uVar4 = 0xffffffff;
          pcVar3 = param_1->FriendlyName[uVar6].Text;
          goto code_r0x0042d7c9;
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 <= (int)(uint)param_1->MaxGamePlayers);
    }
  }
  else {
    pcVar3 = TCommunications_Handler::GetPlayerName(param_1,uStack_c);
    TDebuggingLog::Log(this_00,(char *)L,s_Position__d__LOCKED_____Plr__s,uStack_c,pcVar3);
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
  pcVar7 = param_1->FriendlyName->Text + iStack_10;
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
  pcVar3 = param_1->FormalName[uVar6].Text;
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
  pcVar7 = param_1->FormalName->Text + iStack_10;
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
  puStack_8[0xc] = (param_1->PlayerOptions).PlayerReady[uVar6];
  *puStack_8 = (param_1->PlayerOptions).dcoID[uVar6];
  puStack_8[0x16] = (param_1->PlayerOptions).User1[uVar6];
  puStack_8[0x20] = (param_1->PlayerOptions).User2[uVar6];
  puStack_8[0x2a] = (param_1->PlayerOptions).User3[uVar6];
  puStack_8[0x34] = (param_1->PlayerOptions).User4[uVar6];
  puStack_8[0x3e] = (param_1->PlayerOptions).User5[uVar6];
  puStack_8[0x48] = (param_1->PlayerOptions).User6[uVar6];
  puStack_8[0x52] = (param_1->PlayerOptions).User7[uVar6];
  puStack_8[0x5c] = (param_1->PlayerOptions).Humanity[uVar6];
  this = (TDebuggingLog *)param_1->LastTurnAck[uVar6];
  puStack_8[0x6f] = (ulong)this;
  puStack_8[-0x88] = param_1->LastPlayerCommunication[uVar6];
  TDebuggingLog::Log(this,(char *)L,s_Moved__d_>_d,uVar6,uStack_c);
  pcVar3 = TCommunications_Handler::GetPlayerName(param_1,uStack_c);
  TDebuggingLog::Log(L,(char *)L,s_Position__d__LOCKED_____Plr__s,uStack_c,pcVar3);
  TCommunications_Handler::InitPlayerInformation(param_1,uVar6,0,&s__,&s__);
LAB_0042d915:
  uStack_c = uStack_c + 1;
  iStack_10 = iStack_10 + 0x80;
  if ((int)(uint)param_1->MaxGamePlayers < (int)uStack_c) goto LAB_0042d946;
  goto LAB_0042d751;
}

// --------------------------------------------------

// Function: FUN_0042d953
// Address: 0042d953
// XREFS: None
// [HELPER] s_Add_SELF_PLAYER: "Add SELF PLAYER"
// [HELPER] s_Adding_player___s_: "Adding player [%s]"
// [HELPER] s_Create_the_player: "Create the player"
// [HELPER] s_Rcvd_DPID_of__d: "Rcvd DPID of %d"
undefined4 __fastcall FUN_0042d953(TCommunications_Handler *param_1)
{
  int iVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  char *pcStack_8;
  char *pcStack_4;
  
  TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_Create_the_player);
  pcStack_8 = param_1->MyFriendlyName;
  uStack_c = 0;
  pcStack_4 = param_1->MyFormalName;
  uStack_10 = 0x10;
  TDebuggingLog::Log((TDebuggingLog *)0x0,(char *)L,s_Adding_player___s_,pcStack_8);
  if (DAT_0062c5ec == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_0062c5ec + 0x18))(DAT_0062c5ec,&DAT_0062cf04,&uStack_10,0,0,0,0);
  RGE_Comm_Error::ShowReturn(param_1->Err,iVar1,s_Add_SELF_PLAYER);
  if (iVar1 != 0) {
    TCommunications_Handler::CloseSession(param_1);
    TCommunications_Handler::ReleaseComm(param_1);
    (param_1->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    return 0;
  }
  TDebuggingLog::Log(L,(char *)L,s_Rcvd_DPID_of__d,DAT_0062cf04);
  TCommunications_Handler::GetMyMultiPlayerCaps(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042da46
// Address: 0042da46
// XREFS: None
void __fastcall FUN_0042da46(TCommunications_Handler *param_1)
{
  TChat::ClearChat(param_1->Chat);
  param_1->Multiplayer = 1;
  param_1->HaveHostInit = 0;
  param_1->MeHost = 0;
  param_1->GTDSerialNo = 0;
  TCommunications_Handler::CreateDirectPlayConversation(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0042da7c
// Address: 0042da7c
// XREFS: None
// [HELPER] s_JMPG__Create_w_no_valid_glpIDC: "JMPG: Create w/no valid glpIDC"
// [HELPER] s_Join_MP_Game: "Join MP Game"
// [HELPER] s_Open_session_for_JOIN___Session_: "Open session for JOIN  (Session Data1=%ld) "
undefined4 __thiscall FUN_0042da7c(TCommunications_Handler *param_1,ulong *param_2)
{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  ulong auStack_50 [4];
  ulong uStack_40;
  ulong uStack_3c;
  ulong uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  if (DAT_0062c5ec == (int *)0x0) {
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_JMPG__Create_w_no_valid_glpIDC);
    return 0;
  }
  puVar3 = auStack_50;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  auStack_50[0] = 0x50;
  (param_1->SessionGUID).Data1 = *param_2;
  uVar1 = param_2[1];
  (param_1->SessionGUID).Data2 = (short)uVar1;
  (param_1->SessionGUID).Data3 = (short)(uVar1 >> 0x10);
  *(ulong *)(param_1->SessionGUID).Data4 = param_2[2];
  uVar1 = param_2[3];
  param_1->MeHost = 0;
  *(ulong *)((param_1->SessionGUID).Data4 + 4) = uVar1;
  auStack_50[2] = *param_2;
  auStack_50[3] = param_2[1];
  uStack_40 = param_2[2];
  uStack_3c = param_2[3];
  uStack_38 = (param_1->ApplicationGUID).Data1;
  uStack_34._0_2_ = (param_1->ApplicationGUID).Data2;
  uStack_34._2_2_ = (param_1->ApplicationGUID).Data3;
  uStack_30 = *(undefined4 *)(param_1->ApplicationGUID).Data4;
  uStack_2c = *(undefined4 *)((param_1->ApplicationGUID).Data4 + 4);
  TDebuggingLog::Log(L,(char *)L,s_Open_session_for_JOIN___Session_,(param_1->SessionGUID).Data1);
  iVar2 = (**(code **)(*DAT_0062c5ec + 0x60))(DAT_0062c5ec,auStack_50,1);
  if (iVar2 == -0x7788fea2) {
    RGE_Comm_Error::ShowReturn(param_1->Err,-0x7788fea2,s_Join_MP_Game);
    return 0;
  }
  if (iVar2 == -0x7788fffb) {
    RGE_Comm_Error::ShowReturn(param_1->Err,-0x7788fffb,s_Join_MP_Game);
    return 0;
  }
  if (iVar2 == -0x7788feb6) {
    RGE_Comm_Error::ShowReturn(param_1->Err,-0x7788feb6,s_Join_MP_Game);
    TCommunications_Handler::NotifyWindow(param_1,COMM_NO_NEW_PLAYERS);
    return 0;
  }
  if (iVar2 != 0) {
    RGE_Comm_Error::ShowReturn(param_1->Err,iVar2,s_Join_MP_Game);
    (param_1->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    return 0;
  }
  iVar2 = TCommunications_Handler::AddSelfPlayer(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  (param_1->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042dc1f
// Address: 0042dc1f
// XREFS: None
// [HELPER] s_Clear_player_acknowledgements: "Clear player acknowledgements"
// [HELPER] s_HOST_Set_own_serial_to___d: "HOST Set own serial to =%d"
// [HELPER] s_Set_expected_ser__for_player__d_: "Set expected ser# for player %d to %d"
void __fastcall FUN_0042dc1f(TCommunications_Handler *param_1)
{
  undefined1 *puVar1;
  TDebuggingLog *this;
  ulong *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  TCommunications_Handler::EnableNewPlayers(param_1,DAT_0062c5ec,0);
  (param_1->PlayerOptions).ProgramState = COMM_STATE_RUNNING;
  TCommunications_Handler::CalculatePlayerRange(param_1);
  uVar5 = 1;
  (param_1->PlayerOptions).GameHasStarted = 1;
  TCommunications_Handler::ClearRXandTX(param_1);
  TCommunications_Handler::PackPlayersDown(param_1);
  if (param_1->MaxGamePlayers != 0) {
    uVar3 = 2000;
    puVar4 = param_1->PlayerHighSerialNumber;
    do {
      puVar4 = puVar4 + 1;
      if (puVar4[0xf] != 0) {
        *puVar4 = uVar3;
        TDebuggingLog::Log((TDebuggingLog *)(uVar3 + 1),(char *)L,s_Set_expected_ser__for_player__d_
                           ,uVar5,(TDebuggingLog *)(uVar3 + 1));
      }
      uVar5 = uVar5 + 1;
      uVar3 = uVar3 + 2000;
    } while (uVar5 <= param_1->MaxGamePlayers);
  }
  this = (TDebuggingLog *)(param_1->Me * 2000);
  puVar1 = (undefined1 *)((int)&this->Timestamp + 1);
  param_1->GTDSerialNo = (uint)puVar1;
  TDebuggingLog::Log(this,(char *)L,s_HOST_Set_own_serial_to___d,puVar1);
  TCommunications_Handler::SendSharedData(param_1,1);
  param_1->current_turn = (param_1->PlayerOptions).CommandTurnIncrement + 1;
  if (param_1->Multiplayer != 0) {
    TDebuggingLog::Log(L,(char *)L,s_Clear_player_acknowledgements);
    uVar5 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
    if (uVar5 <= (param_1->PlayerOptions).HighPlayerNumber) {
      puVar2 = param_1->LastTurnAck + uVar5;
      do {
        if (uVar5 != param_1->Me) {
          *puVar2 = 0;
        }
        uVar5 = uVar5 + 1;
        puVar2 = puVar2 + 1;
      } while (uVar5 <= (param_1->PlayerOptions).HighPlayerNumber);
    }
  }
  TCommunications_Handler::ResetLastCommunicationTimes(param_1);
  TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PARAMS);
  return;
}

// --------------------------------------------------

// Function: FUN_0042dd65
// Address: 0042dd65
// XREFS: None
// [HELPER] s_Enumerated_player_caps___: "Enumerated player caps..."
// [HELPER] s_Get_Player_Caps: "Get Player Caps"
// [HELPER] s_Latency____d: "Latency = %d"
// [HELPER] s_MaxQueueSize__d: "MaxQueueSize=%d"
// [HELPER] s_RGE_Gtd_Delivery__d: "RGE_Gtd Delivery=%d"
int __fastcall FUN_0042dd65(int param_1)
{
  int iVar1;
  TDebuggingLog *this;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *puVar2;
  undefined4 auStack_28 [10];
  
  if (DAT_0062c5ec == (int *)0x0) {
    return -0x7fffbffb;
  }
  puVar2 = auStack_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  auStack_28[0] = 0x28;
  if (DAT_0062cf04 == 0) {
    return -0x7fffbffb;
  }
  iVar1 = (**(code **)(*DAT_0062c5ec + 0x4c))(DAT_0062c5ec,DAT_0062cf04,auStack_28);
  RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x14e0),iVar1,s_Get_Player_Caps);
  if (iVar1 != 0) {
    return iVar1;
  }
  *(undefined4 *)(param_1 + 0x1484) = 1;
  *(undefined4 *)(param_1 + 0x1488) = unaff_EDI;
  *(undefined4 *)(param_1 + 0x148c) = unaff_ESI;
  *(undefined1 *)(param_1 + 0x1514) = 1;
  *(undefined4 *)(param_1 + 0x1490) = auStack_28[0];
  *(undefined4 *)(param_1 + 0x1494) = auStack_28[1];
  *(undefined4 *)(param_1 + 0x1498) = auStack_28[2];
  TDebuggingLog::Log(L,(char *)L,s_Enumerated_player_caps___);
  TDebuggingLog::Log(this,(char *)L,s_Latency____d,*(undefined4 *)(param_1 + 0x1498));
  TDebuggingLog::Log(*(TDebuggingLog **)(param_1 + 0x148c),(char *)L,s_MaxQueueSize__d,
                     *(TDebuggingLog **)(param_1 + 0x148c));
  TDebuggingLog::Log(L,(char *)L,s_RGE_Gtd_Delivery__d,(uint)*(byte *)(param_1 + 0x1514));
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042de95
// Address: 0042de95
// XREFS: None
void __thiscall
FUN_0042de95(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  *(undefined4 *)(param_1 + 0x12ec) = param_2;
  *(undefined4 *)(param_1 + 0x12f0) = param_3;
  *(undefined4 *)(param_1 + 0x12f4) = param_4;
  *(undefined4 *)(param_1 + 0x12f8) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_0042dec4
// Address: 0042dec4
// XREFS: None
undefined4 FUN_0042dec4(void)
{
  return DAT_0062c5ec;
}

// --------------------------------------------------

// Function: FUN_0042ded6
// Address: 0042ded6
// XREFS: None
void __thiscall
FUN_0042ded6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  *(undefined4 *)(param_1 + 0x12dc) = param_2;
  *(undefined4 *)(param_1 + 0x12e0) = param_3;
  *(undefined4 *)(param_1 + 0x12e4) = param_4;
  *(undefined4 *)(param_1 + 0x12e8) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_0042df04
// Address: 0042df04
// XREFS: None
void __thiscall
FUN_0042df04(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  *(undefined4 *)(param_1 + 0x12fc) = param_2;
  *(undefined4 *)(param_1 + 0x1300) = param_3;
  *(undefined4 *)(param_1 + 0x1304) = param_4;
  *(undefined4 *)(param_1 + 0x1308) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_0042df34
// Address: 0042df34
// XREFS: None
void __fastcall FUN_0042df34(TCommunications_Handler *param_1)
{
  uint uVar1;
  
  uVar1 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
  if (uVar1 <= (param_1->PlayerOptions).HighPlayerNumber) {
    do {
      TCommunications_Handler::UpdatePlayer(param_1,uVar1,0);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 <= (int)(uint)(param_1->PlayerOptions).HighPlayerNumber);
  }
  TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PLAYERS);
  return;
}

// --------------------------------------------------

// Function: FUN_0042df81
// Address: 0042df81
// XREFS: None
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
void __thiscall FUN_0042df81(TCommunications_Handler *param_1,uint param_2,int param_3)
{
  char cVar1;
  TDebuggingLog *pTVar2;
  undefined4 uVar3;
  int iVar4;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  int iStack_c;
  char *pcStack_8;
  TDebuggingLog *pTStack_4;
  TCommunications_Handler *pTVar5;
  
  uVar7 = param_2;
  pTVar2 = (TDebuggingLog *)(param_1->PlayerOptions).dcoID[param_2];
  pTVar5 = param_1;
  switch((param_1->PlayerOptions).Humanity[param_2]) {
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
    TDebuggingLog::Log((TDebuggingLog *)pTVar5,(char *)L,pcVar10,param_2);
    (param_1->PlayerOptions).dcoID[uVar7] = 0;
    (param_1->PlayerOptions).PlayerReady[uVar7] = 0;
    goto LAB_0042e2ea;
  case ME_COMPUTER:
    pcVar10 = s_P__d_COMPUTER;
LAB_0042e2c0:
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,pcVar10,param_2);
    (param_1->PlayerOptions).dcoID[uVar7] = 0;
    (param_1->PlayerOptions).PlayerReady[uVar7] = 1;
    goto LAB_0042e2ea;
  case ME_CYBORG:
    pcVar10 = s_P__d_CYBORG;
    pTVar5 = (TCommunications_Handler *)L;
    break;
  case ME_VIEWONLY:
    (param_1->PlayerOptions).PlayerReady[param_2] = 1;
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
    pcVar9 = param_1->FriendlyName[param_2].Text;
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
    pTVar2 = (TDebuggingLog *)(param_1->PlayerOptions).Humanity[param_2];
    TDebuggingLog::Log(pTVar2,(char *)L,s_COMM_INVALID_P__d_HUMANITY_SETTI,param_2,pTVar2);
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)pTVar5,(char *)L,pcVar10,param_2);
  if (pTVar2 == (TDebuggingLog *)0x0) {
    TDebuggingLog::Log(this,(char *)L,s_P__d_Not_Defined__updateplayers_,uVar7);
    return;
  }
  param_2 = 0;
  (**(code **)(*DAT_0062c5ec + 0x54))(DAT_0062c5ec,pTVar2,0,&param_2);
  uVar3 = calloc(iStack_c,1);
  iVar4 = (**(code **)(*DAT_0062c5ec + 0x54))(DAT_0062c5ec,pTVar2,uVar3,&iStack_c);
  RGE_Comm_Error::ShowReturn(param_1->Err,iVar4,s_Get_PName_Info);
  if (iVar4 < -0x7788ffe1) {
    if ((iVar4 != -0x7788ffe2) && (iVar4 != -0x7ff8ffa9)) {
LAB_0042e0cf:
      TDebuggingLog::Log(this_00,(char *)L,s_Unknown_fail_on_updateplayers);
      (param_1->PlayerOptions).Humanity[uVar7] = ME_ABSENT;
      (param_1->PlayerOptions).dcoID[uVar7] = 0;
      free(iStack_c);
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
    pcVar9 = param_1->FriendlyName[uVar7].Text;
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
    (param_1->PlayerOptions).Humanity[uVar7] = ME_ABSENT;
  }
  else {
    if (iVar4 == -0x7788ff7e) goto LAB_0042e23d;
    if (iVar4 != -0x7788ff6a) {
      if (iVar4 == 0) {
        uVar8 = 0xffffffff;
        pcVar10 = *(char **)(iStack_c + 8);
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
        pcVar9 = param_1->FriendlyName[uVar7].Text;
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
        pcStack_8 = param_1->FormalName[uVar7].Text;
        uVar8 = 0xffffffff;
        pcVar10 = *(char **)(iStack_c + 0xc);
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
        pcVar9 = pcStack_8;
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
        (param_1->PlayerOptions).Humanity[uVar7] = ME_HUMAN;
        free(iStack_c);
        goto LAB_0042e2ea;
      }
      goto LAB_0042e0cf;
    }
    TDebuggingLog::Log(L,(char *)L,s_INVALID_PLAYER__d___Removing_,pTVar2,uVar3);
    if ((param_1->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
      (param_1->PlayerOptions).Humanity[uVar7] = ME_HUMAN;
      iVar4 = TCommunications_Handler::IsPlayerHuman(param_1,uVar7);
      if (iVar4 != 0) {
        TDebuggingLog::Log(this_01,(char *)L,s_INVALID_PLAYER);
        pTStack_4 = pTVar2;
        TDebuggingLog::Log(this_02,(char *)L,s_TX_Missing_Player_report_for_pla,pTVar2);
        pcStack_8 = (char *)CONCAT31(pcStack_8._1_3_,0x3f);
        TDebuggingLog::Log(pTStack_4,(char *)L,s___>TX_MP___d___d_,pTStack_4,8);
        TCommunications_Handler::FastSend(param_1,0,&pcStack_8,8,0,0);
        free(iStack_c);
        goto LAB_0042e2ea;
      }
    }
  }
  free(iStack_c);
LAB_0042e2ea:
  if (param_3 == 0) {
    return;
  }
  TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PLAYERS);
  return;
}

// --------------------------------------------------

// Function: FUN_0042e4fc
// Address: 0042e4fc
// XREFS: None
undefined4 __thiscall
FUN_0042e4fc(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,undefined4 *param_9,
            undefined4 *param_10)
{
  *param_3 = *(undefined4 *)(param_1 + 0x1594 + param_2 * 4);
  *param_4 = *(undefined4 *)(param_1 + 0x15bc + param_2 * 4);
  *param_5 = *(undefined4 *)(param_1 + 0x15e4 + param_2 * 4);
  *param_6 = *(undefined4 *)(param_1 + 0x160c + param_2 * 4);
  *param_7 = *(undefined4 *)(param_1 + 0x1634 + param_2 * 4);
  *param_8 = *(undefined4 *)(param_1 + 0x165c + param_2 * 4);
  *param_9 = *(undefined4 *)(param_1 + 0x1684 + param_2 * 4);
  *param_10 = *(undefined4 *)(param_1 + 0x16ac + param_2 * 4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042e576
// Address: 0042e576
// XREFS: None
undefined4 __thiscall FUN_0042e576(int param_1,uint param_2)
{
  if ((param_2 != 0) && (param_2 <= *(ushort *)(param_1 + 0x12d8))) {
    return *(undefined4 *)(param_1 + 0x1594 + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042e5a5
// Address: 0042e5a5
// XREFS: None
bool __fastcall FUN_0042e5a5(int param_1)
{
  if (*(int *)(param_1 + 0x10e4) == 0) {
    return true;
  }
  return 6 < *(uint *)(param_1 + 0x10c8);
}

// --------------------------------------------------

// Function: FUN_0042e5d2
// Address: 0042e5d2
// XREFS: None
undefined4 __fastcall FUN_0042e5d2(TCommunications_Handler *param_1)
{
  if (param_1->Multiplayer == 0) {
    return 1;
  }
  if (6 < param_1->current_turn) {
    return 1;
  }
  TCommunications_Handler::DoCycle(param_1,0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042e609
// Address: 0042e609
// XREFS: None
undefined4 __fastcall FUN_0042e609(TCommunications_Handler *param_1)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
  if ((param_1->PlayerOptions).HighPlayerNumber < uVar3) {
    return 1;
  }
  piVar2 = (param_1->PlayerOptions).PlayerReady + uVar3;
  while( true ) {
    iVar1 = TCommunications_Handler::IsPlayerHuman(param_1,uVar3);
    if ((iVar1 != 0) && (*piVar2 == 0)) break;
    uVar3 = uVar3 + 1;
    piVar2 = piVar2 + 1;
    if ((int)(uint)(param_1->PlayerOptions).HighPlayerNumber < (int)uVar3) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042e66c
// Address: 0042e66c
// XREFS: None
// [HELPER] s_Get_Session_Desc: "Get Session Desc"
// [HELPER] s_RX_Current_Players__d: "RX Current Players=%d"
int __fastcall FUN_0042e66c(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_EDI;
  int iStack_4;
  
  if (DAT_0062c5ec == (int *)0x0) {
    return -0x7fffbffb;
  }
  iStack_4 = param_1;
  (**(code **)(*DAT_0062c5ec + 0x58))(DAT_0062c5ec,0,&iStack_4);
  iVar2 = calloc(unaff_EDI,1);
  if (iVar2 == 0) {
    return -0x7ff8fff2;
  }
  iVar3 = (**(code **)(*DAT_0062c5ec + 0x58))(DAT_0062c5ec,iVar2,&stack0xfffffff0);
  RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x14e0),iVar3,s_Get_Session_Desc);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x12fc) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(param_1 + 0x1300) = *(undefined4 *)(iVar2 + 0xc);
    *(undefined4 *)(param_1 + 0x1304) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(param_1 + 0x1308) = *(undefined4 *)(iVar2 + 0x14);
    uVar1 = *(undefined4 *)(iVar2 + 0x2c);
    *(undefined4 *)(param_1 + 0x127c) = uVar1;
    TDebuggingLog::Log(L,(char *)L,s_RX_Current_Players__d,uVar1);
  }
  free(iVar2);
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_0042e72a
// Address: 0042e72a
// XREFS: None
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
long __fastcall FUN_0042e72a(int param_1)
{
  int *piVar1;
  long lVar2;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_02;
  TDebuggingLog *extraout_ECX_01;
  TDebuggingLog *pTVar3;
  TDebuggingLog *unaff_ESI;
  undefined4 unaff_EDI;
  char *pcVar4;
  undefined4 uStack_34;
  int iStack_28;
  int iStack_20;
  TDebuggingLog *pTStack_1c;
  
  piVar1 = DAT_0062c5ec;
  if (DAT_0062c5ec == (int *)0x0) {
    return -0x7fffbffb;
  }
  uStack_34 = 0;
  iStack_28 = 0x28;
  lVar2 = (**(code **)(*DAT_0062c5ec + 0x38))();
  RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x14e0),lVar2,s_Get_Caps);
  lVar2 = (**(code **)(*DAT_0062c5ec + 0x38))(DAT_0062c5ec,&uStack_34,1);
  RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x14e0),lVar2,s_Get_guaranteed_Caps);
  TDebuggingLog::Log(this,(char *)L,s____________Direct_Play_III_Capab);
  TDebuggingLog::Log((TDebuggingLog *)&iStack_28,(char *)L,s_Max_Buffer_Size____d,
                     (TDebuggingLog *)&iStack_28);
  TDebuggingLog::Log(L,(char *)L,s_Max_Queue_Size_____d,uStack_34);
  TDebuggingLog::Log(this_00,(char *)L,s_Max_Players________d,unaff_EDI);
  TDebuggingLog::Log(unaff_ESI,(char *)L,s_Baud_Rate__________d00,unaff_ESI);
  TDebuggingLog::Log(L,(char *)L,s_Latency____________d,iStack_28);
  TDebuggingLog::Log(this_01,(char *)L,s_Header_Length______d,iStack_20);
  TDebuggingLog::Log(pTStack_1c,(char *)L,s_Timeout____________d,pTStack_1c);
  *(TDebuggingLog **)(param_1 + 0x1340) = pTStack_1c;
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
  TDebuggingLog::Log(this_02,(char *)L,pcVar4);
  if (((uint)piVar1 & 0x40) == 0) {
    pcVar4 = s_NOT_Guaranteed_Service_;
    pTVar3 = extraout_ECX_01;
  }
  else {
    pcVar4 = s_Guaranteed_delivery_is_Supported;
    pTVar3 = L;
  }
  TDebuggingLog::Log(pTVar3,(char *)L,pcVar4);
  *(undefined1 *)(param_1 + 0x1514) = 1;
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_0042e914
// Address: 0042e914
// XREFS: None
// [HELPER] s_Close_Session: "Close Session"
// [HELPER] s_Close_Session_Call: "Close Session Call"
long __fastcall FUN_0042e914(TDebuggingLog *param_1)
{
  RGE_Comm_Error *this;
  int iVar1;
  int *piVar2;
  long lVar3;
  
  lVar3 = 0;
  TDebuggingLog::Log(param_1,(char *)L,s_Close_Session_Call);
  if (DAT_0062c5ec != (int *)0x0) {
    lVar3 = (**(code **)(*DAT_0062c5ec + 0x10))(DAT_0062c5ec);
  }
  *(undefined4 *)(param_1[2].osbuf + 0x54) = *(undefined4 *)(param_1[2].osbuf + 0x70);
  *(undefined4 *)(param_1[2].osbuf + 0x58) = *(undefined4 *)(param_1[2].osbuf + 0x74);
  *(undefined4 *)(param_1[2].osbuf + 0x5c) = *(undefined4 *)(param_1[2].osbuf + 0x78);
  this = *(RGE_Comm_Error **)(param_1[2].osbuf + 0x238);
  *(undefined4 *)(param_1[2].osbuf + 0x60) = *(undefined4 *)(param_1[2].osbuf + 0x7c);
  RGE_Comm_Error::ShowReturn(this,lVar3,s_Close_Session);
  iVar1 = 1;
  if (*(short *)(param_1[2].osbuf + 0x30) != 0) {
    piVar2 = &param_1[3].Flush;
    do {
      *piVar2 = 0;
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 <= (int)(uint)*(ushort *)(param_1[2].osbuf + 0x30));
  }
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_0042e9ad
// Address: 0042e9ad
// XREFS: None
// [HELPER] s_1_Release_COMM_links__d: "1.Release COMM links=%d"
undefined4 __fastcall FUN_0042e9ad(int param_1)
{
  undefined4 uVar1;
  TDebuggingLog *this;
  
  if (DAT_0062c5ec != (int *)0x0) {
    uVar1 = (**(code **)(*DAT_0062c5ec + 8))(DAT_0062c5ec);
    TDebuggingLog::Log(this,(char *)L,s_1_Release_COMM_links__d,uVar1);
    *(undefined4 *)(param_1 + 0x12dc) = *(undefined4 *)(param_1 + 0x1318);
    *(undefined4 *)(param_1 + 0x12e0) = *(undefined4 *)(param_1 + 0x131c);
    *(undefined4 *)(param_1 + 0x12e4) = *(undefined4 *)(param_1 + 0x1320);
    *(undefined4 *)(param_1 + 0x12e8) = *(undefined4 *)(param_1 + 0x1324);
    DAT_0062c5ec = (int *)0x0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042ea07
// Address: 0042ea07
// XREFS: None
// [HELPER] s_Sent_to_all___drop_player__d_ID_: "Sent to all - drop player %d ID=%d "
// [HELPER] s___: "]\n"
undefined4 __thiscall FUN_0042ea07(TCommunications_Handler *param_1,uint param_2)
{
  ulong uVar1;
  int iVar2;
  TDebuggingLog *this;
  uint uStack_c;
  ulong uStack_8;
  TDebuggingLog *pTStack_4;
  
  if (((param_2 != 0) && (param_2 <= param_1->MaxGamePlayers)) && (DAT_0062c5ec != 0)) {
    iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,param_2);
    if (iVar2 != 0) {
      uVar1 = (param_1->PlayerOptions).dcoID[param_2];
      if (uVar1 != 0) {
        pTStack_4 = (TDebuggingLog *)param_1->current_turn;
        uStack_c = param_2;
        uStack_8 = uVar1;
        TDebuggingLog::Log(pTStack_4,(char *)L,s_Sent_to_all___drop_player__d_ID_,param_2,uVar1);
        TDebuggingLog::Log(this,(char *)L,s___>TX_KP3__d___d_,param_2,0xc);
        TCommunications_Handler::CommOut(param_1,0,'K',&uStack_c,0xc,'\0');
        if (param_1->PlayerStopTurn[param_2] == 0) {
          TCommunications_Handler::DropDeadPlayer
                    (param_1,param_2,(param_1->PlayerOptions).dcoID[param_2]);
        }
      }
      TCommunications_Handler::NotifyWindow(param_1,COMM_UPDATE_PLAYERS);
      if ((param_1->MeHost != 0) && (param_1->current_turn < 7)) {
        TCommunications_Handler::SendSharedData(param_1,1);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042eb04
// Address: 0042eb04
// XREFS: None
// [HELPER] s_Release_Player: "Release Player"
int __fastcall FUN_0042eb04(int param_1)
{
  int iVar1;
  
  if (DAT_0062c5ec == (int *)0x0) {
    return 0;
  }
  if (DAT_0062cf04 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_0062c5ec + 0x24))(DAT_0062c5ec,DAT_0062cf04);
  RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x14e0),iVar1,s_Release_Player);
  if (iVar1 == 0) {
    DAT_0062cf04 = iVar1;
    *(undefined4 *)(param_1 + 0x10e0) = 0;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0042eb5e
// Address: 0042eb5e
// XREFS: None
// [HELPER] s_Host_Set_Options_to_size__d: "Host Set Options to size %d"
undefined4 __thiscall FUN_0042eb5e(TCommunications_Handler *param_1,char *param_2,uint param_3)
{
  char *pcVar1;
  TDebuggingLog *extraout_ECX;
  uint uVar2;
  TDebuggingLog *this;
  
  if (2000 < param_3) {
    return 0;
  }
  TCommunications_Handler::FreeOptions(param_1);
  this = extraout_ECX;
  if ((param_2 != (char *)0x0) && (param_3 != 0)) {
    pcVar1 = (char *)operator_new(param_3 + 1);
    param_1->OptionsData = pcVar1;
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
    for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pcVar1 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar1 = pcVar1 + 4;
    }
    for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar1 = *param_2;
      param_2 = param_2 + 1;
      pcVar1 = pcVar1 + 1;
    }
    (param_1->PlayerOptions).DataSizeToFollow = param_3;
    this = (TDebuggingLog *)0x0;
  }
  if (param_1->MeHost != 0) {
    (param_1->PlayerOptions).NeedsToBeSent = '\x01';
  }
  TDebuggingLog::Log(this,(char *)L,s_Host_Set_Options_to_size__d,param_3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042ebee
// Address: 0042ebee
// XREFS: None
undefined4 __thiscall FUN_0042ebee(int param_1,undefined4 *param_2)
{
  *param_2 = *(undefined4 *)(param_1 + 0x171c);
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_0042ec02
// Address: 0042ec02
// XREFS: None
void __fastcall FUN_0042ec02(int param_1)
{
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    *(undefined4 *)(param_1 + 0x171c) = 0;
    operator_delete(*(void **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042ec36
// Address: 0042ec36
// XREFS: None
undefined4 FUN_0042ec36(int param_1,undefined2 *param_2)
{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  uint uVar3;
  
  *param_2 = 0x7b;
  pwVar1 = param_2 + 1;
  uVar3 = 0;
  do {
    if ((&DAT_0056f218)[uVar3] == 0x2d) {
      *pwVar1 = L'-';
      pwVar2 = pwVar1;
    }
    else {
      pwVar2 = pwVar1 + 1;
      *pwVar1 = L"0123456789ABCDEF"[*(byte *)(param_1 + (uint)(byte)(&DAT_0056f218)[uVar3]) >> 4];
      *pwVar2 = L"0123456789ABCDEF"[*(byte *)(param_1 + (uint)(byte)(&DAT_0056f218)[uVar3]) & 0xf];
    }
    pwVar1 = pwVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x14);
  *pwVar1 = L'}';
  pwVar2[2] = L'\0';
  return 0x26;
}

// --------------------------------------------------

// Function: StringFromGUID
// Address: 0042ec40
// XREFS: DebugSessionInformation
/* int __cdecl StringFromGUID(struct _GUID *,unsigned short *) */

int __cdecl StringFromGUID(_GUID *param_1,ushort *param_2)
{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  uint uVar3;
  
  *param_2 = 0x7b;
  pwVar1 = (wchar_t *)(param_2 + 1);
  uVar3 = 0;
  do {
    if ((&DAT_0056f218)[uVar3] == 0x2d) {
      *pwVar1 = L'-';
      pwVar2 = pwVar1;
    }
    else {
      pwVar2 = pwVar1 + 1;
      *pwVar1 = L"0123456789ABCDEF"[param_1->Data4[(byte)(&DAT_0056f218)[uVar3] - 8] >> 4];
      *pwVar2 = L"0123456789ABCDEF"[param_1->Data4[(byte)(&DAT_0056f218)[uVar3] - 8] & 0xf];
    }
    pwVar1 = pwVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x14);
  *pwVar1 = L'}';
  pwVar2[2] = L'\0';
  return 0x26;
}

// --------------------------------------------------

// Function: FUN_0042ecb8
// Address: 0042ecb8
// XREFS: None
void __thiscall FUN_0042ecb8(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1714) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0042eccd
// Address: 0042eccd
// XREFS: None
undefined4 __fastcall FUN_0042eccd(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1714);
}

// --------------------------------------------------

// Function: FUN_0042ecd7
// Address: 0042ecd7
// XREFS: None
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
void __thiscall FUN_0042ecd7(TDebuggingLog *param_1,undefined4 *param_2)
{
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  TDebuggingLog *this_04;
  TDebuggingLog *this_05;
  ushort auStack_50 [40];
  
  TDebuggingLog::Log(param_1,(char *)L,s___Information_in_DPSESSIONDESC2_);
  TDebuggingLog::Log((TDebuggingLog *)*param_2,(char *)L,s_Size_DPSESSIONDESC2___d,
                     (TDebuggingLog *)*param_2);
  TDebuggingLog::Log(L,(char *)L,s_Flags_________________d,param_2[1]);
  TDebuggingLog::Log(this,(char *)L,s_Instance_guid__DATA1__u,param_2[2]);
  TDebuggingLog::Log((TDebuggingLog *)(uint)*(ushort *)(param_2 + 3),(char *)L,
                     s________________DATA2__d,(TDebuggingLog *)(uint)*(ushort *)(param_2 + 3));
  TDebuggingLog::Log(L,(char *)L,s________________DATA3__d,(uint)*(ushort *)((int)param_2 + 0xe));
  TDebuggingLog::Log(this_00,(char *)L,s________________DATA4__u,param_2 + 4);
  StringFromGUID((_GUID *)(param_2 + 2),auStack_50);
  TDebuggingLog::Log(this_01,(char *)L,s_Instance_GUID__str____s,auStack_50);
  TDebuggingLog::Log((TDebuggingLog *)param_2[6],(char *)L,s_Applicatn_guid_DATA1__u,
                     (TDebuggingLog *)param_2[6]);
  TDebuggingLog::Log(L,(char *)L,s________________DATA2__d,(uint)*(ushort *)(param_2 + 7));
  TDebuggingLog::Log(this_02,(char *)L,s________________DATA3__d,
                     (uint)*(ushort *)((int)param_2 + 0x1e));
  TDebuggingLog::Log((TDebuggingLog *)(param_2 + 8),(char *)L,s________________DATA4__u,
                     (TDebuggingLog *)(param_2 + 8));
  TDebuggingLog::Log(L,(char *)L,s_Max_Players___________d,param_2[10]);
  TDebuggingLog::Log(this_03,(char *)L,s_Current_Players_______d,param_2[0xb]);
  TDebuggingLog::Log((TDebuggingLog *)param_2[0xe],(char *)L,s_Reserved_1____________d,
                     (TDebuggingLog *)param_2[0xe]);
  TDebuggingLog::Log(L,(char *)L,s_Reserved_2____________d,param_2[0xf]);
  TDebuggingLog::Log(this_04,(char *)L,s_User_1________________d,param_2[0x10]);
  TDebuggingLog::Log((TDebuggingLog *)param_2[0x11],(char *)L,s_User_2________________d,
                     (TDebuggingLog *)param_2[0x11]);
  TDebuggingLog::Log(L,(char *)L,s_User_3________________d,param_2[0x12]);
  TDebuggingLog::Log(this_05,(char *)L,s_User_4________________d,param_2[0x13]);
  TDebuggingLog::Log(L,(char *)L,s______end____);
  return;
}

// --------------------------------------------------

// Function: FUN_0042eef6
// Address: 0042eef6
// XREFS: None
// [HELPER] s_Released_to_links__d: "Released to links=%d"
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_0042eef6(int *param_1)
{
  int iVar1;
  undefined4 uVar2;
  TDebuggingLog *this;
  undefined4 unaff_ESI;
  int *piVar3;
  
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  piVar3 = param_1;
  iVar1 = (**(code **)*param_1)(param_1,&_IID_IDirectPlay);
  if (-1 < iVar1) {
    iVar1 = (*(code *)param_1[10])(&param_1,unaff_ESI);
    uVar2 = (**(code **)(*piVar3 + 8))(piVar3);
    TDebuggingLog::Log(this,(char *)L,s_Released_to_links__d,uVar2);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0042ef5b
// Address: 0042ef5b
// XREFS: None
void __thiscall FUN_0042ef5b(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x10e8) = param_2;
  *(undefined4 *)(param_1 + 0x10ec) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0042ef77
// Address: 0042ef77
// XREFS: None
// [HELPER] s_NOT_LOBBY_LAUNCHED___EXITING: "NOT LOBBY LAUNCHED.  EXITING"
// [HELPER] s_SendGameOptions: "SendGameOptions"
// [HELPER] s_Sending_zone_message_: "Sending zone message."
// [HELPER] s___: "]\n"
undefined4 __thiscall FUN_0042ef77(TCommunications_Handler *param_1,char *param_2,ulong param_3)
{
  int iVar1;
  long lVar2;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  
  iVar1 = TCommunications_Handler::IsLobbyLaunched(param_1);
  if (iVar1 == 0) {
    TDebuggingLog::Log(this,(char *)L,s_NOT_LOBBY_LAUNCHED___EXITING);
    return 0;
  }
  TDebuggingLog::Log(L,(char *)L,s_Sending_zone_message_);
  TDebuggingLog::Log(this_00,(char *)L,s___>TX_ZONE_MSG___u_,param_3);
  lVar2 = RGE_Lobby::SendZoneMessage
                    (param_1->Lobby,param_2,param_3,rge_base_game->prog_info->zone_guid);
  if (lVar2 == 0) {
    return 1;
  }
  RGE_Comm_Error::ShowReturn(param_1->Err,lVar2,s_SendGameOptions);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042f034
// Address: 0042f034
// XREFS: None
// [HELPER] s_ENUM_DEBUG___s: "ENUM DEBUG: %s"
// [HELPER] s_ENUM__d_name__s_id__d: "ENUM %d name=%s id=%d"
// [HELPER] s_FILL_PLAYER_INFORMATION_: "FILL PLAYER INFORMATION."
// [HELPER] s_FORCEENUM__d_name__s_id__d: "FORCEENUM %d name=%s id=%d"
undefined4
FUN_0042f034(ulong param_1,undefined4 param_2,int param_3,undefined4 param_4,
            TCommunications_Handler *param_5)
{
  uint uVar1;
  ulong *puVar2;
  TDebuggingLog *this;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar1 = (uint)(param_5->PlayerOptions).LowPlayerNumber;
    uVar3 = (uint)(param_5->PlayerOptions).HighPlayerNumber;
    if (uVar1 <= uVar3) {
      puVar2 = (param_5->PlayerOptions).dcoID + uVar1;
      do {
        if (*puVar2 == param_1) goto LAB_0042f07f;
        uVar1 = uVar1 + 1;
        puVar2 = puVar2 + 1;
      } while ((int)uVar1 <= (int)uVar3);
    }
  }
  uVar1 = 0;
LAB_0042f07f:
  sprintf(&DAT_0062c5f0,s_ENUM__d_name__s_id__d,param_1,*(undefined4 *)(param_3 + 8),uVar1);
  TDebuggingLog::Log(L,(char *)L,s_ENUM_DEBUG___s,&DAT_0062c5f0);
  TDebuggingLog::Log(this,(char *)L,s_FORCEENUM__d_name__s_id__d,param_1,
                     *(undefined4 *)(param_3 + 8),uVar1);
  TDebuggingLog::Log(L,(char *)L,s_FILL_PLAYER_INFORMATION_);
  TCommunications_Handler::UpdatePlayerInformation
            (param_5,param_1,*(char **)(param_3 + 8),*(char **)(param_3 + 0xc));
  return 1;
}

// --------------------------------------------------

// Function: EnumPlayersCallback2
// Address: 0042f040
// XREFS: ForcePlayerEnumeration
// [HELPER] s_ENUM_DEBUG___s: "ENUM DEBUG: %s"
// [HELPER] s_ENUM__d_name__s_id__d: "ENUM %d name=%s id=%d"
// [HELPER] s_FILL_PLAYER_INFORMATION_: "FILL PLAYER INFORMATION."
// [HELPER] s_FORCEENUM__d_name__s_id__d: "FORCEENUM %d name=%s id=%d"
/* int __stdcall EnumPlayersCallback2(unsigned long,unsigned long,struct DPNAME *,unsigned long,void
   *) */

int EnumPlayersCallback2(ulong param_1,ulong param_2,DPNAME *param_3,ulong param_4,void *param_5)
{
  uint uVar1;
  ulong *puVar2;
  TDebuggingLog *this;
  
  if (param_1 != 0) {
    uVar1 = (uint)*(ushort *)((int)param_5 + 0x1712);
    if (uVar1 <= *(ushort *)((int)param_5 + 0x1710)) {
      puVar2 = (ulong *)((int)param_5 + uVar1 * 4 + 0x1564);
      do {
        if (*puVar2 == param_1) goto LAB_0042f07f;
        uVar1 = uVar1 + 1;
        puVar2 = puVar2 + 1;
      } while ((int)uVar1 <= (int)(uint)*(ushort *)((int)param_5 + 0x1710));
    }
  }
  uVar1 = 0;
LAB_0042f07f:
  sprintf(&DAT_0062c5f0,s_ENUM__d_name__s_id__d,param_1,(param_3->field2_0x8).lpszShortName,uVar1);
  TDebuggingLog::Log(L,(char *)L,s_ENUM_DEBUG___s,&DAT_0062c5f0);
  TDebuggingLog::Log(this,(char *)L,s_FORCEENUM__d_name__s_id__d,param_1,
                     (param_3->field2_0x8).lpszShortName,uVar1);
  TDebuggingLog::Log(L,(char *)L,s_FILL_PLAYER_INFORMATION_);
  TCommunications_Handler::UpdatePlayerInformation
            ((TCommunications_Handler *)param_5,param_1,(param_3->field2_0x8).lpszShortNameA,
             (param_3->field3_0xc).lpszLongNameA);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042f104
// Address: 0042f104
// XREFS: None
// [HELPER] s_Force_Calling_enumeration_of_pla: "Force Calling enumeration of players."
void __fastcall FUN_0042f104(TDebuggingLog *param_1)
{
  TDebuggingLog::Log(param_1,(char *)L,s_Force_Calling_enumeration_of_pla);
  (**(code **)(*DAT_0062c5ec + 0x30))(DAT_0062c5ec,0,EnumPlayersCallback2,param_1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0042f13d
// Address: 0042f13d
// XREFS: None
// [HELPER] s_Create_called_: "Create called."
// [HELPER] s_Force_Self_player_destroy_and_cr: "Force Self player destroy and create!"
void __fastcall FUN_0042f13d(TCommunications_Handler *param_1)
{
  TDebuggingLog *this;
  
  TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_Force_Self_player_destroy_and_cr);
  (**(code **)(*DAT_0062c5ec + 0x24))(DAT_0062c5ec,DAT_0062cf04);
  DAT_0062cf04 = 0;
  TCommunications_Handler::AddSelfPlayer(param_1);
  TDebuggingLog::Log(this,(char *)L,s_Create_called_);
  return;
}

// --------------------------------------------------

// Function: FUN_0042f18e
// Address: 0042f18e
// XREFS: None
// [HELPER] s_Force_Name_Change: "Force Name Change"
// [HELPER] s_TEMPORARY_NAME: "TEMPORARY NAME"
void __fastcall FUN_0042f18e(TDebuggingLog *param_1)
{
  undefined4 auStack_30 [2];
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  undefined4 uStack_11;
  undefined4 uStack_d;
  undefined4 uStack_9;
  undefined4 uStack_5;
  undefined1 uStack_1;
  
  TDebuggingLog::Log(param_1,(char *)L,s_Force_Name_Change);
  uStack_18 = DAT_005832c4;
  uStack_1c = DAT_005832c0;
  uStack_11 = 0;
  uStack_d = 0;
  uStack_12 = DAT_005832ca;
  uStack_9 = 0;
  puStack_24 = &uStack_20;
  uStack_20 = s_TEMPORARY_NAME;
  uStack_5 = 0;
  uStack_14 = DAT_005832c8;
  uStack_1 = 0;
  puStack_28 = &uStack_20;
  auStack_30[0] = 0x10;
  (**(code **)(*DAT_0062c5ec + 0x78))(DAT_0062c5ec,DAT_0062cf04,auStack_30,2);
  return;
}

// --------------------------------------------------

// Function: FUN_0042f224
// Address: 0042f224
// XREFS: None
void __thiscall FUN_0042f224(int param_1,ulong param_2)
{
  RGE_Communications_Speed::SetV1(*(RGE_Communications_Speed **)(param_1 + 0x14d4),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0042f243
// Address: 0042f243
// XREFS: None
void __thiscall FUN_0042f243(int param_1,ulong param_2)
{
  RGE_Communications_Speed::SetV2(*(RGE_Communications_Speed **)(param_1 + 0x14d4),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0042f263
// Address: 0042f263
// XREFS: None
void __thiscall FUN_0042f263(int param_1,uint param_2,ulong param_3)
{
  RGE_Communications_Synchronize::IsPlayerOutOfSync
            (*(RGE_Communications_Synchronize **)(param_1 + 0x14d8),param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0042f288
// Address: 0042f288
// XREFS: None
undefined4 * __thiscall FUN_0042f288(undefined4 *param_1,void *param_2)
{
  RGE_Comm_Error *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cd3b;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = param_2;
  this = (RGE_Comm_Error *)operator_new(8);
  uStack_4 = 0;
  if (this == (RGE_Comm_Error *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = RGE_Comm_Error::RGE_Comm_Error(this,param_2);
  }
  param_1[6] = uVar1;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042f2fc
// Address: 0042f2fc
// XREFS: None
void __fastcall FUN_0042f2fc(RGE_Lobby *param_1)
{
  RGE_Comm_Error *this;
  
  this = param_1->Err;
  if (this != (RGE_Comm_Error *)0x0) {
    RGE_Comm_Error::~RGE_Comm_Error(this);
    operator_delete(this);
  }
  RGE_Lobby::ClearLobbyInfo(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0042f325
// Address: 0042f325
// XREFS: None
// [HELPER] s_Release: "Release"
void __fastcall FUN_0042f325(int param_1)
{
  int *piVar1;
  long lVar2;
  
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    lVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x18),lVar2,s_Release);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0042f394
// Address: 0042f394
// XREFS: None
// [HELPER] s_ENUMPLAYER__DPID____ld: "ENUMPLAYER: DPID = %ld"
// [HELPER] s_ENUMPLAYER__NAME____s: "ENUMPLAYER: NAME = %s"
// [HELPER] s_Local_Player: "Local Player"
// [HELPER] s_Remote_Player: "Remote Player"
// [HELPER] s_____Enumeration_not_done: "+++ Enumeration not done"
undefined4 FUN_0042f394(undefined4 param_1,undefined4 param_2,int param_3,byte param_4)
{
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  
  TDebuggingLog::Log(L,(char *)L,s_ENUMPLAYER__DPID____ld,param_1);
  TDebuggingLog::Log(L,(char *)L,s_ENUMPLAYER__NAME____s,*(undefined4 *)(param_3 + 8));
  TDebuggingLog::Log(this,(char *)L,s_____Enumeration_not_done);
  if ((param_4 & 0x10) != 0) {
    TDebuggingLog::Log(this_00,(char *)L,s_Remote_Player);
  }
  if ((param_4 & 8) != 0) {
    TDebuggingLog::Log(L,(char *)L,s_Local_Player);
  }
  return 1;
}

// --------------------------------------------------

// Function: EnumPlayersCallbackLobby
// Address: 0042f3a0
// XREFS: CheckForLobbyLaunch
// [HELPER] s_ENUMPLAYER__DPID____ld: "ENUMPLAYER: DPID = %ld"
// [HELPER] s_ENUMPLAYER__NAME____s: "ENUMPLAYER: NAME = %s"
// [HELPER] s_Local_Player: "Local Player"
// [HELPER] s_Remote_Player: "Remote Player"
// [HELPER] s_____Enumeration_not_done: "+++ Enumeration not done"
/* int __stdcall EnumPlayersCallbackLobby(unsigned long,unsigned long,struct DPNAME *,unsigned
   long,void *) */

int EnumPlayersCallbackLobby
              (ulong param_1,ulong param_2,DPNAME *param_3,ulong param_4,void *param_5)
{
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  
  TDebuggingLog::Log(L,(char *)L,s_ENUMPLAYER__DPID____ld,param_1);
  TDebuggingLog::Log(L,(char *)L,s_ENUMPLAYER__NAME____s,(param_3->field2_0x8).lpszShortName);
  TDebuggingLog::Log(this,(char *)L,s_____Enumeration_not_done);
  if ((param_4 & 0x10) != 0) {
    TDebuggingLog::Log(this_00,(char *)L,s_Remote_Player);
  }
  if ((param_4 & 8) != 0) {
    TDebuggingLog::Log(L,(char *)L,s_Local_Player);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042f428
// Address: 0042f428
// XREFS: None
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
undefined4 __thiscall FUN_0042f428(RGE_Lobby *param_1,undefined4 *param_2)
{
  IDirectPlayLobby2 **ppIVar1;
  IDirectPlayLobby2 *pIVar2;
  IDirectPlay2 *pIVar3;
  int iVar4;
  DPLCONNECTION *pDVar5;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  IDirectPlayLobby *pIStack_20;
  
  *param_2 = 0;
  RGE_Lobby::ClearLobbyInfo(param_1);
  pIStack_20 = (IDirectPlayLobby *)0x0;
  iVar4 = _DirectPlayLobbyCreateA_20(0,&param_1->glpDPL);
  pIStack_20 = (IDirectPlayLobby *)0x42f470;
  RGE_Comm_Error::ShowReturn(param_1->Err,iVar4,s_Lobby_Create);
  if (iVar4 < 0) {
    return 0;
  }
  pIStack_20 = param_1->glpDPL;
  ppIVar1 = &param_1->glpDPL2;
  (**(code **)*pIStack_20)();
  pIVar2 = *ppIVar1;
  if (pIVar2 == (IDirectPlayLobby2 *)0x0) {
    return 0;
  }
  (**(code **)((int)*pIVar2 + 0x20))(pIVar2,0,0,&stack0xfffffff0);
  pDVar5 = (DPLCONNECTION *)operator_new((uint)&pIStack_20->field_0x1);
  param_1->glpdplConnection = pDVar5;
  iVar4 = (**(code **)((int)**ppIVar1 + 0x20))(*ppIVar1,0,pDVar5,&pIStack_20);
  if (iVar4 < 0) {
    param_1->lobby_game = '\0';
    return 0;
  }
  TDebuggingLog::Log(this,(char *)L,s_LOBBY_LAUNCHED_GAME_);
  param_1->glpdplConnection->lpSessionDesc->dwFlags = 0x44;
  param_1->glpdplConnection->lpSessionDesc->dwMaxPlayers = 9;
  (**(code **)((int)**ppIVar1 + 0x30))(*ppIVar1,0,0,param_1->glpdplConnection);
  TDebuggingLog::Log(this_00,(char *)L,s_Pre_connect);
  iVar4 = (**(code **)((int)**ppIVar1 + 0xc))(*ppIVar1,0,&param_1->glpDP,0);
  TDebuggingLog::Log(L,(char *)L,s_Post_Connect);
  if (iVar4 < 0) {
    if (iVar4 == -0x7788ff10) {
      return 0xff;
    }
    TDebuggingLog::Log(this_01,(char *)L,s_Failed_to_connect_);
    RGE_Comm_Error::ShowReturn(param_1->Err,iVar4,s_Connect);
    return 0xff;
  }
  TDebuggingLog::Log(this_01,(char *)L,s_Pre_QI);
  pIVar3 = param_1->glpDP;
  iVar4 = (**(code **)*pIVar3)(pIVar3,&_IID_IDirectPlay3A,param_2);
  RGE_Comm_Error::ShowReturn(param_1->Err,iVar4,s_Lobby_QI);
  if (iVar4 < 0) {
    TDebuggingLog::Log(this_02,(char *)L,s_Queryinterface_failed_);
    return 0xff;
  }
  TDebuggingLog::Log(this_02,(char *)L,s_Calling_enumeration_of_players_);
  (**(code **)(*(int *)*param_2 + 0x30))((int *)*param_2,0,EnumPlayersCallbackLobby,param_1,0);
  TDebuggingLog::Log(this_03,(char *)L,s_Post_ENUMP);
  param_1->lobby_game = '\x01';
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042f632
// Address: 0042f632
// XREFS: None
uint __fastcall FUN_0042f632(int param_1)
{
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0;
  }
  return *(uint *)(*(int *)(param_1 + 0x10) + 4) >> 1 & 1;
}

// --------------------------------------------------

// Function: FUN_0042f655
// Address: 0042f655
// XREFS: None
undefined4 __thiscall FUN_0042f655(int param_1,undefined4 *param_2)
{
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0;
  }
  *param_2 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + 0xc) + 8);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042f6a6
// Address: 0042f6a6
// XREFS: None
bool __fastcall FUN_0042f6a6(int param_1)
{
  return *(char *)(param_1 + 0x14) != '\0';
}

// --------------------------------------------------

// Function: FUN_0042f6bb
// Address: 0042f6bb
// XREFS: None
bool __fastcall FUN_0042f6bb(int param_1)
{
  return *(char *)(param_1 + 0x14) != '\0';
}

// --------------------------------------------------

// Function: FUN_0042f6cb
// Address: 0042f6cb
// XREFS: None
// [HELPER] s_RX_Lobby_Messages: "RX Lobby Messages"
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

undefined4 __fastcall FUN_0042f6cb(int param_1)
{
  long lVar1;
  
  if (*(char *)(param_1 + 0x14) != '\0') {
    lVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x24))(*(int **)(param_1 + 4),0);
    RGE_Comm_Error::ShowReturn(*(RGE_Comm_Error **)(param_1 + 0x18),lVar1,s_RX_Lobby_Messages);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042f81e
// Address: 0042f81e
// XREFS: None
/* WARNING: Removing unreachable block (ram,0x0042f842) */
/* WARNING: Removing unreachable block (ram,0x0042f8d4) */
/* WARNING: Removing unreachable block (ram,0x0042f8d6) */
/* WARNING: Removing unreachable block (ram,0x0042f8db) */
/* WARNING: Removing unreachable block (ram,0x0042f8dd) */
/* WARNING: Removing unreachable block (ram,0x0042f8f9) */
/* WARNING: Removing unreachable block (ram,0x0042f90d) */

undefined4 __fastcall FUN_0042f81e(int param_1,char param_2)
{
  undefined1 in_AL;
  
  uRamc10042f7 = in_AL;
  *(char *)(param_1 + -0x76) = *(char *)(param_1 + -0x76) + param_2;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042f925
// Address: 0042f925
// XREFS: None
RGE_Combat_Object * __thiscall
FUN_0042f925(RGE_Combat_Object *param_1,RGE_Master_Combat_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cd58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_Object::RGE_Action_Object
            ((RGE_Action_Object *)param_1,(RGE_Master_Action_Object *)param_2,param_3,param_4,
             param_5,param_6,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Combat_Object::_vftable_;
  if (param_7 != 0) {
    RGE_Combat_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042f9b3
// Address: 0042f9b3
// XREFS: None
RGE_Combat_Object * __thiscall FUN_0042f9b3(RGE_Combat_Object *param_1,byte param_2)
{
  RGE_Combat_Object::~RGE_Combat_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042f9de
// Address: 0042f9de
// XREFS: None
RGE_Combat_Object * __thiscall
FUN_0042f9de(RGE_Combat_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cd78;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_Object::RGE_Action_Object((RGE_Action_Object *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Combat_Object::_vftable_;
  if (param_4 != 0) {
    RGE_Combat_Object::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042fa45
// Address: 0042fa45
// XREFS: None
void __fastcall FUN_0042fa45(RGE_Action_Object *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  ulong uVar5;
  ulong uVar6;
  RGE_Action_Object *pRVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cd98;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Combat_Object::_vftable_;
  iVar1 = param_1->_padding_;
  uStack_4 = 0;
  if (-1 < iVar1) {
    uVar5 = param_1[1]._padding_;
    pRVar7 = param_1 + 1;
    uVar6 = 0;
    iVar2 = (int)*(short *)(param_1->_padding_ + 0x14);
    iVar3 = __ftol();
    iVar4 = __ftol();
    Visible_Unit_Manager::Update_Unit_Info
              (VisibleUnitManager,iVar1,(int)*(short *)(param_1->_padding_ + 0x4a),iVar4,iVar3,iVar2
               ,uVar5,uVar6,(VISIBLE_UNIT_REC **)pRVar7);
  }
  uStack_4 = 0xffffffff;
  RGE_Action_Object::~RGE_Action_Object(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0042fae1
// Address: 0042fae1
// XREFS: None
void __thiscall
FUN_0042fae1(RGE_Action_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  int iVar1;
  RGE_Action_Object *pRVar2;
  
  pRVar2 = param_1 + 1;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->_padding_ = 0;
    pRVar2 = (RGE_Action_Object *)&pRVar2->_padding_;
  }
  param_1[1]._padding_ = 0;
  RGE_Action_Object::recycle_in_to_game(param_1,param_2,param_3,param_4,param_5,param_6);
  param_1[1]._padding_ = *(int *)(param_1->_padding_ + 0x120);
  return;
}

// --------------------------------------------------

// Function: FUN_0042fb3d
// Address: 0042fb3d
// XREFS: None
undefined4 __thiscall
FUN_0042fb3d(RGE_Action_Object *param_1,RGE_Master_Action_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  int iVar1;
  RGE_Action_Object *pRVar2;
  
  pRVar2 = param_1 + 1;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->_padding_ = 0;
    pRVar2 = (RGE_Action_Object *)&pRVar2->_padding_;
  }
  param_1[1]._padding_ = 0;
  RGE_Action_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  iVar1 = param_1->_padding_;
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x32;
  param_1[1]._padding_ = *(int *)(iVar1 + 0x120);
  *(undefined1 *)&param_1[1]._padding_ = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042fb9d
// Address: 0042fb9d
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0042fb9d(RGE_Action_Object *param_1,int param_2,RGE_Game_World *param_3)
{
  int iVar1;
  RGE_Action_Object *pRVar2;
  
  pRVar2 = param_1 + 1;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->_padding_ = 0;
    pRVar2 = (RGE_Action_Object *)&pRVar2->_padding_;
  }
  param_1[1]._padding_ = 0;
  RGE_Action_Object::setup(param_1,param_2,param_3);
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x32;
  rge_read(param_2,&param_1[1]._padding_,4);
  if (_DAT_0056f498 <= save_game_version) {
    rge_read(param_2,&param_1[1]._padding_,1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042fc0f
// Address: 0042fc0f
// XREFS: None
void __thiscall FUN_0042fc0f(RGE_Action_Object *param_1,int param_2)
{
  RGE_Action_Object::save(param_1,param_2);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0042fc47
// Address: 0042fc47
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_com_obj_cp: "C:\msdev\work\age1_x1\com_obj.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
void __fastcall FUN_0042fc47(RGE_Action_Object *param_1)
{
  RGE_Action_Object::stop(param_1);
  if (param_1->_padding_ != 0) {
    if (actionFile != (_iobuf *)0x0) {
      fprintf(actionFile,s___d_call_stopObject__s__d_,param_1->_padding_,
              s_C__msdev_work_age1_x1_com_obj_cp,0xab);
    }
    (**(code **)(*(int *)param_1->_padding_ + 0x58))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042fc99
// Address: 0042fc99
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_com_obj_cp: "C:\msdev\work\age1_x1\com_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0042fc99(int *param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5,
            int *param_6)
{
  float fVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  short sVar11;
  undefined4 unaff_EBP;
  int iVar12;
  float10 fVar13;
  float fStack_24;
  short sStack_20;
  short sStack_1c;
  int iStack_18;
  int iStack_10;
  int iStack_c;
  
  fVar1 = *(float *)(param_1[2] + 0x118);
  iVar3 = *(int *)(*(int *)(param_1[3] + 0x3c) + 0x28);
  sVar2 = *(short *)(iVar3 + 8);
  sVar11 = *(short *)(iVar3 + 0xc) + -1;
  fVar6 = (float)_DAT_0056f4a0;
  if (fVar1 < fVar6 || (fVar1 == fVar6) != 0) {
    return CONCAT22((short)((uint)iVar3 >> 0x10),
                    (ushort)(fVar1 < fVar6) << 8 | (ushort)(NAN(fVar1) || NAN(fVar6)) << 10 |
                    (ushort)(fVar1 == fVar6) << 0xe);
  }
  sStack_20 = __ftol();
  sStack_20 = sStack_20 + -2;
  sVar8 = __ftol();
  sVar9 = __ftol();
  sVar9 = sVar9 + -2;
  iStack_c = __ftol();
  iStack_c = iStack_c + 2;
  if (sStack_20 < 0) {
    sStack_20 = 0;
  }
  sStack_1c = sVar8 + 2;
  if ((short)(sVar2 + -1) + 1 < (int)(short)(sVar8 + 2)) {
    sStack_1c = sVar2;
  }
  if (sVar9 < 0) {
    sVar9 = 0;
  }
  if (sVar11 + 1 < (int)(short)iStack_c) {
    iStack_c = CONCAT22((short)((uint)unaff_EBP >> 0x10),sVar11) + 1;
  }
  if (sVar9 < (short)iStack_c) {
    iStack_18 = sVar9 * 4;
    iStack_c = (int)(short)iStack_c - (int)sVar9;
    do {
      if (sStack_20 < sStack_1c) {
        iVar12 = sStack_20 * 0x18;
        iStack_10 = (int)sStack_1c - (int)sStack_20;
        do {
          for (piVar4 = *(int **)(*(int *)(iStack_18 + *(int *)(iVar3 + 0x8d8c)) + 0x10 + iVar12);
              piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
            piVar5 = (int *)*piVar4;
            if (((piVar5 != param_1) &&
                (iVar10 = piVar5[2], *(byte *)(param_1[2] + 0x11c) <= *(byte *)(iVar10 + 0x8b))) &&
               (piVar5 != param_6)) {
              fVar6 = (float)piVar5[0xe] - param_2;
              fStack_24 = (float)piVar5[0xf] - param_3;
              if (fVar6 < _DAT_0056f4a8) {
                fVar6 = -fVar6;
              }
              if (fStack_24 < _DAT_0056f4a8) {
                fStack_24 = -fStack_24;
              }
              fVar7 = _DAT_0056f4a8;
              if (*(float *)(iVar10 + 0x30) < fVar6) {
                fVar7 = fVar6 - *(float *)(iVar10 + 0x30);
              }
              fVar6 = _DAT_0056f4a8;
              if (*(float *)(iVar10 + 0x34) < fStack_24) {
                fVar6 = fStack_24 - *(float *)(iVar10 + 0x34);
              }
              if (fVar6 * fVar6 + fVar7 * fVar7 < fVar1 * fVar1) {
                iVar10 = debug_rand(s_C__msdev_work_age1_x1_com_obj_cp,0xfa);
                iVar10 = iVar10 * 100;
                if ((short)(((short)(iVar10 / 0x7fff) + (short)(iVar10 >> 0x1f)) -
                           (short)((longlong)iVar10 * 0x80010003 >> 0x3f)) <=
                    *(short *)(param_1[2] + 0x126)) {
                  fVar13 = (float10)(**(code **)(*param_1 + 0xf0))(piVar5);
                  (**(code **)(*piVar5 + 0x70))
                            ((int)*(short *)(param_1[2] + 0x108),*(undefined4 *)(param_1[2] + 0x10c)
                             ,(float)fVar13,param_1[3],param_4);
                }
              }
            }
          }
          iVar12 = iVar12 + 0x18;
          iStack_10 = iStack_10 + -1;
        } while (iStack_10 != 0);
      }
      iStack_18 = iStack_18 + 4;
      iStack_c = iStack_c + -1;
    } while (iStack_c != 0);
  }
  return CONCAT31((int3)((uint)iStack_c >> 8),1);
}

// --------------------------------------------------

// Function: FUN_0042ff4b
// Address: 0042ff4b
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0042ff4b(int *param_1,RGE_Static_Object *param_2,undefined4 param_3)
{
  int iVar1;
  RGE_Missile_Object *this;
  int iVar2;
  undefined4 uVar3;
  RGE_Combat_Object *unaff_ESI;
  float unaff_EDI;
  float10 fVar4;
  float10 fVar5;
  
  if (param_2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar2 = param_1[2];
  if (*(short *)(iVar2 + 0x124) < 0) {
    (**(code **)(*param_1 + 0x228))(param_2,param_3,param_1[0xe],param_1[0xf],param_1[0x10]);
  }
  else {
    fVar4 = (float10)fcos((float10)(float)param_1[0x27]);
    fVar5 = (float10)fsin((float10)(float)param_1[0x27]);
    this = (RGE_Missile_Object *)
           (**(code **)(**(int **)(*(int *)(param_1[3] + 0x24) + *(short *)(iVar2 + 0x124) * 4) +
                       0x18))(param_1[3],
                              (float)fVar4 * *(float *)(iVar2 + 0x130) +
                              -(float)fVar5 * *(float *)(iVar2 + 300) + (float)param_1[0xe],
                              (float)(fVar4 * (float10)*(float *)(iVar2 + 300) +
                                      fVar5 * (float10)*(float *)(iVar2 + 0x130) +
                                     (float10)(float)param_1[0xf]),
                              (float)param_1[0x10] + *(float *)(iVar2 + 0x134));
    RGE_Missile_Object::init_missile(this,unaff_ESI,param_2,unaff_EDI);
    (**(code **)(*param_1 + 0x148))(param_1[1],param_1[1],0x200,600,param_2->id,0);
    if (_DAT_0056f49c < *(float *)(param_1[2] + 0x114)) {
      iVar2 = RGE_Player::computerPlayer(param_2->owner);
      if (iVar2 == 1) {
        iVar2 = param_1[1];
        iVar1 = param_2->_padding_;
        uVar3 = __ftol((int)param_2->master_obj->hp);
        (**(code **)(iVar1 + 0x148))(iVar2,param_2->id,0x20f,iVar2,uVar3);
        return 1;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004300e7
// Address: 004300e7
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004300e7(int *param_1)
{
  int iVar1;
  float fVar2;
  RGE_Missile_Object *this;
  float unaff_EBX;
  float unaff_ESI;
  float10 fVar3;
  float10 fVar4;
  RGE_Combat_Object *unaff_retaddr;
  
  iVar1 = param_1[2];
  if (-1 < *(short *)(iVar1 + 0x124)) {
    fVar3 = (float10)fcos((float10)(float)param_1[0x27]);
    fVar4 = (float10)fsin((float10)(float)param_1[0x27]);
    fVar2 = (SQRT(*(float *)(iVar1 + 0x34) * *(float *)(iVar1 + 0x34) +
                  *(float *)(iVar1 + 0x30) * *(float *)(iVar1 + 0x30)) + *(float *)(iVar1 + 0x114))
            - _DAT_0056f4ac;
    this = (RGE_Missile_Object *)
           (**(code **)(**(int **)(*(int *)(param_1[3] + 0x24) + *(short *)(iVar1 + 0x124) * 4) +
                       0x18))(param_1[3],
                              (float)fVar3 * *(float *)(iVar1 + 0x130) +
                              -(float)fVar4 * *(float *)(iVar1 + 300) + (float)param_1[0xe],
                              (float)(fVar4 * (float10)*(float *)(iVar1 + 0x130) +
                                      fVar3 * (float10)*(float *)(iVar1 + 300) +
                                     (float10)(float)param_1[0xf]),
                              (float)param_1[0x10] + *(float *)(iVar1 + 0x134));
    RGE_Missile_Object::init_missile(this,unaff_retaddr,unaff_ESI,(float)fVar4,fVar2,unaff_EBX);
    (**(code **)(*param_1 + 0x148))(param_1[1],param_1[1],0x200,600,0xffffffff,0);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00430221
// Address: 00430221
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_com_obj_cp: "C:\msdev\work\age1_x1\com_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00430221(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)
{
  int iVar1;
  int iVar2;
  float10 fVar3;
  int iVar4;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (_DAT_0056f4a8 < *(float *)(param_1[2] + 0x118)) {
    (**(code **)(*param_1 + 0x21c))(param_4,param_5,param_6,param_3,0);
    return 1;
  }
  iVar4 = param_2[1];
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x148))(param_1[1],param_1[1],0x200,600,iVar4,0);
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_com_obj_cp,0x17b);
  if ((iVar2 * 100) / 0x7fff <= (int)*(short *)(param_1[2] + 0x126)) {
    fVar3 = (float10)(**(code **)(iVar1 + 0xf0))(param_2);
    (**(code **)(*param_2 + 0x70))
              ((int)*(short *)(param_1[2] + 0x108),*(undefined4 *)(param_1[2] + 0x10c),(float)fVar3,
               param_1[3],iVar4);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043031a
// Address: 0043031a
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0043031a(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  iVar1 = *param_1;
  fVar4 = (float10)(**(code **)(iVar1 + 0x74))(param_2,param_3,param_4,param_5,param_6);
  param_1[0xc] = (int)(float)((float10)(float)param_1[0xc] - fVar4);
  if (param_6 != 0) {
    uVar2 = *(undefined4 *)(param_6 + 4);
    uVar3 = __ftol((int)*(short *)(param_1[2] + 0x26));
    (**(code **)(iVar1 + 0x148))(uVar2,param_1[1],500,uVar2,uVar3);
  }
  if ((float)param_1[0xc] < (float)_DAT_0056f4b0) {
    param_1[0xc] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00430394
// Address: 00430394
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00430394(int param_1,uint param_2,short *param_3,float param_4)
{
  int iVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  
  psVar4 = param_3;
  iVar1 = *(int *)(param_1 + 8);
  fVar5 = (float10)_DAT_0056f49c;
  if ((-1 < *(short *)(iVar1 + 0x110)) && (*(int *)(param_1 + 0x1c) != 0)) {
    fVar5 = (float10)*(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x54) +
                                        *(short *)(iVar1 + 0x110) * 4) +
                               (*(byte *)(*(int *)(param_1 + 0x1c) + 5) & 0x1f) * 4);
  }
  fVar6 = (float10)_DAT_0056f4a8;
  if (0 < (int)param_2) {
    param_3 = (short *)param_2;
    do {
      param_2 = (uint)*(byte *)(iVar1 + 0x100);
      if (0 < *(short *)(iVar1 + 0x102)) {
        psVar2 = *(short **)(iVar1 + 0x104);
        iVar3 = (int)*(short *)(iVar1 + 0x102);
        do {
          if (*psVar2 == *psVar4) {
            param_2 = (uint)psVar2[1];
          }
          psVar2 = psVar2 + 2;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      fVar7 = ((float10)(int)psVar4[1] - (float10)(int)param_2) * fVar5 * (float10)param_4;
      if ((float10)_DAT_0056f4a0 < fVar7) {
        fVar6 = fVar7 + fVar6;
      }
      psVar4 = psVar4 + 2;
      param_3 = (short *)((int)param_3 + -1);
    } while (param_3 != (short *)0x0);
  }
  return fVar6;
}

// --------------------------------------------------

// Function: FUN_00430475
// Address: 00430475
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort __fastcall FUN_00430475(int param_1)
{
  float fVar1;
  ushort uVar2;
  
  fVar1 = *(float *)(param_1 + 0x1bc);
  uVar2 = (ushort)(fVar1 < _DAT_0056f4a8) << 8 | (ushort)(NAN(fVar1) || NAN(_DAT_0056f4a8)) << 10 |
          (ushort)(fVar1 == _DAT_0056f4a8) << 0xe;
  if (fVar1 >= _DAT_0056f4a8 && (fVar1 == _DAT_0056f4a8) == 0) {
    return uVar2;
  }
  return CONCAT11((char)(uVar2 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_00430499
// Address: 00430499
// XREFS: None
void __fastcall FUN_00430499(int param_1)
{
  *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(*(int *)(param_1 + 8) + 0x120);
  return;
}

// --------------------------------------------------

// Function: FUN_0043050a
// Address: 0043050a
// XREFS: None
void __thiscall FUN_0043050a(int param_1,short *param_2,undefined2 *param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *param_2 = 0;
  iVar2 = *(int *)(param_1 + 8);
  if (0 < *(short *)(iVar2 + 0x108)) {
    do {
      sVar1 = *(short *)(*(int *)(iVar2 + 0x10c) + 2 + iVar3 * 4);
      if (*param_2 < sVar1) {
        *param_2 = sVar1;
      }
      iVar2 = *(int *)(param_1 + 8);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(iVar2 + 0x108));
  }
  *param_3 = *(undefined2 *)(*(int *)(param_1 + 8) + 0x13e);
  return;
}

// --------------------------------------------------

// Function: FUN_00430561
// Address: 00430561
// XREFS: None
void __thiscall FUN_00430561(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x114);
  *param_3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x140);
  return;
}

// --------------------------------------------------

// Function: FUN_00430591
// Address: 00430591
// XREFS: None
void __thiscall FUN_00430591(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x120);
  *param_3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x144);
  return;
}

// --------------------------------------------------

// Function: FUN_004305c1
// Address: 004305c1
// XREFS: None
void __thiscall FUN_004305c1(RGE_Animated_Object *param_1,RGE_Static_Object *param_2)
{
  RGE_Animated_Object::release_being_worked_on(param_1,param_2);
  if (-1 < param_2->id) {
    (**(code **)(param_1->_padding_ + 0x148))
              (param_2->id,param_1->_padding_,699,(int)param_2->master_obj->object_group,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043060a
// Address: 0043060a
// XREFS: None
void __thiscall FUN_0043060a(RGE_Static_Object *param_1,RGE_Static_Object *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  ulong uVar6;
  uchar *puVar7;
  
  RGE_Static_Object::enter_obj(param_1,param_2);
  if ((param_1->inside_obj != (RGE_Static_Object *)0x0) && (iVar1 = param_1->id, -1 < iVar1)) {
    pRVar5 = param_1[3].inside_obj;
    puVar7 = &param_1[2].inObstructionMapValue;
    uVar6 = 0;
    iVar4 = (int)param_1->master_obj->object_group;
    iVar2 = __ftol();
    iVar3 = __ftol();
    Visible_Unit_Manager::Update_Unit_Info
              (VisibleUnitManager,iVar1,(int)param_1->owner->id,iVar3,iVar2,iVar4,(ulong)pRVar5,
               uVar6,(VISIBLE_UNIT_REC **)puVar7);
    param_1[3].inside_obj = (RGE_Static_Object *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00430679
// Address: 00430679
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar __fastcall FUN_00430679(RGE_Action_Object *param_1)
{
  ulong *puVar1;
  ulong *puVar2;
  bool bVar3;
  float fVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  
  if ((_DAT_0056f4a8 < (float)param_1[1]._padding_) &&
     (fVar4 = (float)param_1[1]._padding_ - *(float *)(*(int *)(param_1->_padding_ + 0x3c) + 0x84),
     bVar3 = fVar4 < _DAT_0056f4a8, param_1[1]._padding_ = (int)fVar4, bVar3)) {
    param_1[1]._padding_ = 0;
  }
  uVar5 = RGE_Action_Object::update(param_1);
  iVar8 = param_1->_padding_;
  if ((-1 < iVar8) && (param_1->_padding_ == 0)) {
    iVar6 = __ftol();
    iVar7 = __ftol();
    puVar1 = (ulong *)param_1[1]._padding_;
    puVar2 = (&unified_map_offsets)[iVar7][iVar6];
    param_1[1]._padding_ = (int)puVar2;
    if (puVar2 != puVar1) {
      Visible_Unit_Manager::Update_Unit_Info
                (VisibleUnitManager,iVar8,(int)*(short *)(param_1->_padding_ + 0x4a),iVar6,iVar7,
                 (int)*(short *)(param_1->_padding_ + 0x14),(ulong)puVar1,(ulong)puVar2,
                 (VISIBLE_UNIT_REC **)(param_1 + 1));
      if ((char)param_1[1]._padding_ != '\0') {
        iVar6 = 1;
        iVar8 = *(int *)(param_1->_padding_ + 0x3c);
        iVar7 = (int)*(short *)(iVar8 + 0x3c);
        if (1 < iVar7) {
          do {
            if ((iVar6 != *(short *)(param_1->_padding_ + 0x4a)) &&
               (((uint)puVar2 & 1 << ((byte)iVar6 & 0x1f)) != 0)) goto LAB_00430784;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar7);
        }
        iVar6 = -1;
LAB_00430784:
        if (-1 < iVar6) {
          iVar8 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar8 + 0x40) + iVar6 * 4));
          if (iVar8 == 0) {
            (**(code **)(param_1->_padding_ + 0x44))
                      (*(undefined4 *)
                        (*(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x40) + iVar6 * 4));
            if ((char)param_1[1]._padding_ == '\x01') {
              *(undefined1 *)&param_1[1]._padding_ = 0;
            }
          }
        }
      }
    }
  }
  if (param_1->_padding_ != 0) {
    iVar8 = RGE_Game_World::is_player_turn
                      (*(RGE_Game_World **)(param_1->_padding_ + 0x3c),
                       (int)*(short *)(param_1->_padding_ + 0x4a));
    if (iVar8 != 0) {
      uVar9 = RGE_Game_World::get_accum_time_delta
                        (*(RGE_Game_World **)(param_1->_padding_ + 0x3c),
                         (int)*(short *)(param_1->_padding_ + 0x4a));
      UnitAIModule::update((UnitAIModule *)param_1->_padding_,uVar9);
    }
  }
  return uVar5;
}

// --------------------------------------------------

// Function: FUN_00430802
// Address: 00430802
// XREFS: None
void __thiscall FUN_00430802(RGE_Action_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Sound *pRVar1;
  
  pRVar1 = (RGE_Sound *)0x0;
  if (param_1->_padding_ == *(int *)(param_1->_padding_ + 0xfc)) {
    pRVar1 = param_2[1].death_sound;
  }
  if (pRVar1 != (RGE_Sound *)0x0) {
    (**(code **)(param_1->_padding_ + 0x38))(pRVar1);
  }
  RGE_Action_Object::copy_obj(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00430849
// Address: 00430849
// XREFS: None
void __thiscall
FUN_00430849(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x48) == '\x02') &&
     (((*(int **)(param_1 + 0x74) == (int *)0x0 ||
       (iVar1 = (**(code **)(**(int **)(param_1 + 0x74) + 0x14))
                          (param_2,param_3,param_4,param_5,param_6,param_7), iVar1 == 0)) &&
      (param_4 != 699)))) {
    (**(code **)(**(int **)(param_1 + 0xc) + 0xe8))(param_2,param_3,param_4,param_5,param_6,param_7)
    ;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004308be
// Address: 004308be
// XREFS: None
undefined4 __thiscall FUN_004308be(RGE_Action_Object *param_1,int param_2,int param_3)
{
  uchar uVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  RGE_Action *pRVar4;
  RGE_Static_Object *pRVar5;
  RGE_Action_Attack *this;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cdbb;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar3 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  if (param_3 == 0) {
    uVar1 = RGE_Action_List::have_action(param_1->actions);
    if (uVar1 == '\x01') {
      pRVar4 = RGE_Action_List::get_action(param_1->actions);
      pRVar5 = (RGE_Static_Object *)(**(code **)(pRVar4->_padding_ + 0x4c))();
      if (pRVar5 == pRVar3) {
        pRVar4 = RGE_Action_List::get_action(param_1->actions);
        sVar2 = (**(code **)(pRVar4->_padding_ + 0x18))();
        if (sVar2 == 9) goto LAB_00430a71;
        pRVar4 = RGE_Action_List::get_action(param_1->actions);
        sVar2 = (**(code **)(pRVar4->_padding_ + 0x18))();
        if (sVar2 == 7) goto LAB_00430a71;
      }
    }
  }
  uVar1 = RGE_Action_List::have_action(param_1->actions);
  if (uVar1 == '\x01') {
    pRVar4 = RGE_Action_List::get_action(param_1->actions);
    pRVar5 = (RGE_Static_Object *)(**(code **)(pRVar4->_padding_ + 0x4c))();
    if (pRVar5 == pRVar3) {
      pRVar4 = RGE_Action_List::get_action(param_1->actions);
      sVar2 = (**(code **)(pRVar4->_padding_ + 0x18))();
      if (sVar2 == 9) {
        pRVar4 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar4->_padding_ + 0x34))
                  (pRVar3,pRVar3->world_x,pRVar3->world_y,pRVar3->world_z);
        goto LAB_00430a71;
      }
    }
  }
  if ((*(short *)(param_1->_padding_ + 0x14) == 4) &&
     (iVar6 = *(int *)(*(int *)(param_1->_padding_ + 0x24) + 0x14c), iVar6 != 0)) {
    (**(code **)(param_1->_padding_ + 0x54))(iVar6);
  }
  this = (RGE_Action_Attack *)operator_new(0x5c);
  uStack_4 = 0;
  if (this == (RGE_Action_Attack *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = param_1->_padding_;
    iVar6 = RGE_Action_Attack::RGE_Action_Attack
                      (this,param_1,pRVar3,(RGE_Sprite *)0x0,(RGE_Sprite *)0x0,(RGE_Sprite *)0x0,
                       *(float *)(iVar6 + 0x114),*(float *)(iVar6 + 0x138),*(short *)(iVar6 + 0x124)
                       ,*(short *)(iVar6 + 0x12a));
  }
  uStack_4 = 0xffffffff;
  if (iVar6 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  RGE_Action_List::delete_list(param_1->actions);
  (**(code **)(param_1->_padding_ + 0x208))(iVar6);
LAB_00430a71:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00430a89
// Address: 00430a89
// XREFS: None
undefined4 __thiscall
FUN_00430a89(RGE_Action_Object *param_1,float param_2,float param_3,float param_4,int param_5)
{
  uchar uVar1;
  short sVar2;
  RGE_Action *pRVar3;
  RGE_Action_Attack *this;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  float fVar5;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cddb;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_5 == 0) {
    uVar1 = RGE_Action_List::have_action(param_1->actions);
    if (uVar1 == '\x01') {
      pRVar3 = RGE_Action_List::get_action(param_1->actions);
      fVar5 = RGE_Action::targetX(pRVar3);
      if (fVar5 == param_2) {
        pRVar3 = RGE_Action_List::get_action(param_1->actions);
        fVar5 = RGE_Action::targetX(pRVar3);
        if (fVar5 == param_3) {
          pRVar3 = RGE_Action_List::get_action(param_1->actions);
          fVar5 = RGE_Action::targetX(pRVar3);
          if (fVar5 == param_4) {
            pRVar3 = RGE_Action_List::get_action(param_1->actions);
            sVar2 = (**(code **)(pRVar3->_padding_ + 0x18))();
            if (sVar2 == 9) goto LAB_00430bec;
            pRVar3 = RGE_Action_List::get_action(param_1->actions);
            sVar2 = (**(code **)(pRVar3->_padding_ + 0x18))();
            if (sVar2 == 7) goto LAB_00430bec;
          }
        }
      }
    }
  }
  this = (RGE_Action_Attack *)operator_new(0x5c);
  uStack_4 = 0;
  if (this == (RGE_Action_Attack *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_1->_padding_;
    iVar4 = RGE_Action_Attack::RGE_Action_Attack
                      (this,param_1,param_2,param_3,param_4,(RGE_Sprite *)0x0,(RGE_Sprite *)0x0,
                       (RGE_Sprite *)0x0,*(float *)(iVar4 + 0x114),*(float *)(iVar4 + 0x138),
                       *(short *)(iVar4 + 0x124),*(short *)(iVar4 + 0x12a));
  }
  uStack_4 = 0xffffffff;
  if (iVar4 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  RGE_Action_List::delete_list(param_1->actions);
  (**(code **)(param_1->_padding_ + 0x208))(iVar4);
LAB_00430bec:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00430c04
// Address: 00430c04
// XREFS: None
void __thiscall FUN_00430c04(int *param_1,undefined4 param_2,undefined4 param_3)
{
  (**(code **)(*param_1 + 0x158))(param_2,0x3f800000,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_00430c2a
// Address: 00430c2a
// XREFS: None
undefined4 __thiscall FUN_00430c2a(RGE_Action_Object *param_1,int param_2,float param_3,int param_4)
{
  uchar uVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  RGE_Action *pRVar4;
  RGE_Static_Object *pRVar5;
  RGE_Action_Move_To *this;
  int iVar6;
  RGE_Sprite *pRVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cdfb;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar3 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  if (param_4 == 0) {
    uVar1 = RGE_Action_List::have_action(param_1->actions);
    if (uVar1 == '\x01') {
      pRVar4 = RGE_Action_List::get_action(param_1->actions);
      pRVar5 = (RGE_Static_Object *)(**(code **)(pRVar4->_padding_ + 0x4c))();
      if (pRVar5 == pRVar3) {
        pRVar4 = RGE_Action_List::get_action(param_1->actions);
        sVar2 = (**(code **)(pRVar4->_padding_ + 0x18))();
        if (sVar2 == 1) goto LAB_00430d35;
      }
    }
  }
  pRVar7 = *(RGE_Sprite **)(param_1->_padding_ + 0xc0);
  if (pRVar7 == (RGE_Sprite *)0x0) {
    pRVar7 = *(RGE_Sprite **)(param_1->_padding_ + 0xbc);
  }
  this = (RGE_Action_Move_To *)operator_new(0x44);
  uStack_4 = 0;
  if (this == (RGE_Action_Move_To *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = RGE_Action_Move_To::RGE_Action_Move_To(this,param_1,pRVar3,param_3,pRVar7);
  }
  uStack_4 = 0xffffffff;
  if (iVar6 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  RGE_Action_List::delete_list(param_1->actions);
  (**(code **)(param_1->_padding_ + 0x208))(iVar6);
LAB_00430d35:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00430d4e
// Address: 00430d4e
// XREFS: None
undefined4 __thiscall
FUN_00430d4e(RGE_Action_Object *param_1,float param_2,float param_3,float param_4,float param_5,
            int param_6)
{
  uchar uVar1;
  short sVar2;
  RGE_Action *pRVar3;
  int iVar4;
  RGE_Action_Move_To *this;
  undefined4 uVar5;
  RGE_Sprite *pRVar6;
  undefined4 *unaff_FS_OFFSET;
  float fVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ce1b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_6 == 0) {
    uVar1 = RGE_Action_List::have_action(param_1->actions);
    if (uVar1 != '\x01') goto LAB_00430df9;
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    fVar7 = RGE_Action::targetX(pRVar3);
    if (fVar7 != param_2) goto LAB_00430df9;
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    fVar7 = RGE_Action::targetY(pRVar3);
    if (fVar7 != param_3) goto LAB_00430df9;
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    fVar7 = RGE_Action::targetZ(pRVar3);
    if (fVar7 != param_4) goto LAB_00430df9;
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    sVar2 = (**(code **)(pRVar3->_padding_ + 0x18))();
    if (sVar2 != 1) goto LAB_00430df9;
  }
  else {
LAB_00430df9:
    uVar1 = RGE_Action_List::have_action(param_1->actions);
    if (uVar1 == '\x01') {
      pRVar3 = RGE_Action_List::get_action(param_1->actions);
      iVar4 = (**(code **)(pRVar3->_padding_ + 0x30))(param_1,param_2,param_3,param_4);
      if (iVar4 == 1) goto LAB_00430e9d;
    }
    pRVar6 = *(RGE_Sprite **)(param_1->_padding_ + 0xc0);
    if (pRVar6 == (RGE_Sprite *)0x0) {
      pRVar6 = *(RGE_Sprite **)(param_1->_padding_ + 0xbc);
    }
    this = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (this == (RGE_Action_Move_To *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = RGE_Action_Move_To::RGE_Action_Move_To
                        (this,param_1,param_2,param_3,param_4,param_5,pRVar6);
    }
    uStack_4 = 0xffffffff;
    if (iVar4 == 0) {
      uVar5 = 0;
      goto LAB_00430ea2;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(param_1->_padding_ + 0x208))(iVar4);
  }
LAB_00430e9d:
  uVar5 = 1;
LAB_00430ea2:
  *unaff_FS_OFFSET = uStack_c;
  return uVar5;
}

// --------------------------------------------------

// Function: FUN_00430eb7
// Address: 00430eb7
// XREFS: None
undefined4 FUN_00430eb7(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00430ec5
// Address: 00430ec5
// XREFS: None
RGE_Static_Object * __thiscall FUN_00430ec5(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  RGE_Action_Gather *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ce3b;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_00431006;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_00430f4e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_00430f4e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 5) goto LAB_00430f4e;
  }
  else {
LAB_00430f4e:
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action(param_1->actions);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 5) {
        pRVar5 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_00431001;
      }
    }
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_00431006;
    this = (RGE_Action_Gather *)operator_new(0x44);
    uStack_4 = 0;
    if (this == (RGE_Action_Gather *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = RGE_Action_Gather::RGE_Action_Gather(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_00431006;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_00431001:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_00431006:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_0043101b
// Address: 0043101b
// XREFS: None
undefined4 __thiscall FUN_0043101b(RGE_Action_Object *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  short sVar2;
  RGE_Action *pRVar3;
  RGE_Action_Explore *this;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ce5b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_4 == 0) {
    uVar1 = RGE_Action_List::have_action(param_1->actions);
    if (uVar1 == '\x01') {
      pRVar3 = RGE_Action_List::get_action(param_1->actions);
      sVar2 = (**(code **)(pRVar3->_padding_ + 0x18))();
      if (sVar2 == 4) goto LAB_00431132;
    }
  }
  uVar1 = RGE_Action_List::have_action(param_1->actions);
  if (uVar1 == '\x01') {
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    sVar2 = (**(code **)(pRVar3->_padding_ + 0x18))();
    if (sVar2 == 4) {
      pRVar3 = RGE_Action_List::get_action(param_1->actions);
      (**(code **)(pRVar3->_padding_ + 0x34))(0,(float)param_2,(float)param_3,param_1->_padding_);
      goto LAB_00431132;
    }
  }
  this = (RGE_Action_Explore *)operator_new(0x40);
  uStack_4 = 0;
  if (this == (RGE_Action_Explore *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = RGE_Action_Explore::RGE_Action_Explore
                      (this,param_1,(RGE_Task *)0x0,(float)param_2,(float)param_3,
                       (float)param_1->_padding_);
  }
  uStack_4 = 0xffffffff;
  if (iVar4 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  RGE_Action_List::delete_list(param_1->actions);
  (**(code **)(param_1->_padding_ + 0x208))(iVar4);
LAB_00431132:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043114a
// Address: 0043114a
// XREFS: None
RGE_Static_Object * __thiscall FUN_0043114a(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  RGE_Action_Enter *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ce7b;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_0043123a;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_004311ca;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004311ca;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 3) goto LAB_004311ca;
  }
  else {
LAB_004311ca:
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_0043123a;
    this = (RGE_Action_Enter *)operator_new(0x40);
    uStack_4 = 0;
    if (this == (RGE_Action_Enter *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = RGE_Action_Enter::RGE_Action_Enter(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_0043123a;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_0043123a:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_0043124f
// Address: 0043124f
// XREFS: None
undefined4 __thiscall
FUN_0043124f(RGE_Action_Object *param_1,float param_2,float param_3,float param_4)
{
  uchar uVar1;
  short sVar2;
  RGE_Action *pRVar3;
  RGE_Action_Transport *this;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ce9b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar1 = RGE_Action_List::have_action(param_1->actions);
  if (uVar1 == '\x01') {
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    sVar2 = (**(code **)(pRVar3->_padding_ + 0x18))();
    if (sVar2 != 0xc) goto LAB_004312b5;
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    iVar5 = pRVar3->_padding_;
    param_1 = (RGE_Action_Object *)0x0;
  }
  else {
LAB_004312b5:
    this = (RGE_Action_Transport *)operator_new(0x40);
    piVar6 = (int *)0x0;
    uStack_4 = 0;
    if (this != (RGE_Action_Transport *)0x0) {
      piVar6 = (int *)RGE_Action_Transport::RGE_Action_Transport
                                (this,param_1,(RGE_Task *)0x0,param_2,param_3,param_4);
    }
    uStack_4 = 0xffffffff;
    if (piVar6 == (int *)0x0) {
      uVar4 = 0;
      goto LAB_00431321;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(param_1->_padding_ + 0x208))(piVar6);
    iVar5 = *piVar6;
  }
  (**(code **)(iVar5 + 0x34))(param_1,param_2,param_3,param_4);
  uVar4 = 1;
LAB_00431321:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}

// --------------------------------------------------

// Function: FUN_00431336
// Address: 00431336
// XREFS: None
undefined4 __thiscall
FUN_00431336(RGE_Action_Object *param_1,undefined4 param_2,int param_3,int param_4,int param_5)
{
  uchar uVar1;
  short sVar2;
  RGE_Action *pRVar3;
  RGE_Action_Transport *this;
  int *piVar4;
  int iVar5;
  int *unaff_FS_OFFSET;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cebb;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  uVar1 = RGE_Action_List::have_action(param_1->actions);
  if (uVar1 == '\x01') {
    pRVar3 = RGE_Action_List::get_action(param_1->actions);
    sVar2 = (**(code **)(pRVar3->_padding_ + 0x18))();
    if (sVar2 == 0xc) {
      pRVar3 = RGE_Action_List::get_action(param_1->actions);
      param_5 = param_1->_padding_;
      iVar5 = pRVar3->_padding_;
      param_4 = param_1->_padding_;
      param_3 = param_1->_padding_;
      goto LAB_00431423;
    }
  }
  this = (RGE_Action_Transport *)operator_new(0x40);
  uStack_4 = 0;
  if (this == (RGE_Action_Transport *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)RGE_Action_Transport::RGE_Action_Transport
                              (this,param_1,(RGE_Task *)0x0,(float)param_1->_padding_,
                               (float)param_1->_padding_,(float)param_1->_padding_);
  }
  uStack_4 = 0xffffffff;
  if (piVar4 == (int *)0x0) {
    *unaff_FS_OFFSET = iStack_c;
    return 0;
  }
  RGE_Action_List::delete_list(param_1->actions);
  (**(code **)(param_1->_padding_ + 0x208))(piVar4);
  iVar5 = *piVar4;
LAB_00431423:
  (**(code **)(iVar5 + 0x34))(param_1,param_3,param_4);
  *unaff_FS_OFFSET = param_5;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043143e
// Address: 0043143e
// XREFS: None
undefined4 __fastcall FUN_0043143e(int *param_1)
{
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0x61]);
  (**(code **)(*param_1 + 0x38))(*(undefined4 *)(param_1[2] + 0x18));
  return 1;
}

// --------------------------------------------------

// Function: FUN_00431463
// Address: 00431463
// XREFS: None
undefined4 __fastcall FUN_00431463(int *param_1)
{
  (**(code **)(*param_1 + 0x38))(*(undefined4 *)(param_1[2] + 0x18));
  return 1;
}

// --------------------------------------------------

// Function: FUN_00431482
// Address: 00431482
// XREFS: None
float10 __fastcall FUN_00431482(int param_1)
{
  return (float10)*(float *)(*(int *)(param_1 + 8) + 0x120);
}

// --------------------------------------------------

// Function: FUN_0043149a
// Address: 0043149a
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0043149a(int param_1)
{
  short *psVar1;
  int iVar2;
  float10 fVar3;
  
  fVar3 = (float10)_DAT_0056f4a8;
  iVar2 = (int)*(short *)(*(int *)(param_1 + 8) + 0x108);
  if (0 < iVar2) {
    psVar1 = (short *)(*(int *)(*(int *)(param_1 + 8) + 0x10c) + 2);
    do {
      if ((float10)_DAT_0056f4a8 < (float10)(int)*psVar1) {
        fVar3 = fVar3 + (float10)(int)*psVar1;
      }
      psVar1 = psVar1 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return fVar3;
}

// --------------------------------------------------

// Function: FUN_004314e6
// Address: 004314e6
// XREFS: None
void __thiscall FUN_004314e6(int *param_1,int *param_2)
{
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*param_2 + 0xf0))(param_1);
  (**(code **)(*param_1 + 0x74))
            ((int)*(short *)(param_2[2] + 0x108),*(undefined4 *)(param_2[2] + 0x10c),(float)fVar1,
             param_2[3],param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0043152f
// Address: 0043152f
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0043152f(RGE_Static_Object *param_1,RGE_Static_Object *param_2)
{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  
  fVar2 = param_1->master_obj->radius_x;
  fVar1 = param_1->master_obj->radius_y;
  fVar4 = (float10)(**(code **)(param_1->_padding_ + 0x10c))();
  fVar3 = (float10)_DAT_0056f4b8;
  fVar5 = RGE_Static_Object::distance_to_object(param_1,param_2);
  if (fVar5 <= (float)((fVar4 + (float10)SQRT(fVar1 * fVar1 + fVar2 * fVar2)) - fVar3)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0043159b
// Address: 0043159b
// XREFS: None
float10 __fastcall FUN_0043159b(int param_1)
{
  return (float10)*(float *)(*(int *)(param_1 + 8) + 0x114);
}

// --------------------------------------------------

// Function: FUN_004315aa
// Address: 004315aa
// XREFS: None
float10 __fastcall FUN_004315aa(int param_1)
{
  return (float10)*(float *)(*(int *)(param_1 + 8) + 0x138);
}

// --------------------------------------------------

// Function: FUN_004315ba
// Address: 004315ba
// XREFS: None
undefined4 __fastcall FUN_004315ba(int param_1)
{
  uchar uVar1;
  RGE_Action *pRVar2;
  int iVar3;
  
  uVar1 = RGE_Action_List::have_action(*(RGE_Action_List **)(param_1 + 0x184));
  if (uVar1 == '\x01') {
    pRVar2 = RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
    iVar3 = (**(code **)(pRVar2->_padding_ + 0x4c))();
    if (iVar3 != 0) {
      pRVar2 = RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
      iVar3 = (**(code **)(pRVar2->_padding_ + 0x4c))();
      return *(undefined4 *)(iVar3 + 4);
    }
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00431604
// Address: 00431604
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00431604(int param_1)
{
  uchar uVar1;
  RGE_Action *this;
  float fVar2;
  
  uVar1 = RGE_Action_List::have_action(*(RGE_Action_List **)(param_1 + 0x184));
  if (uVar1 == '\x01') {
    this = RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
    fVar2 = RGE_Action::targetX(this);
    return (float10)fVar2;
  }
  return (float10)_DAT_0056f4bc;
}

// --------------------------------------------------

// Function: FUN_0043163e
// Address: 0043163e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0043163e(int param_1)
{
  uchar uVar1;
  RGE_Action *this;
  float fVar2;
  
  uVar1 = RGE_Action_List::have_action(*(RGE_Action_List **)(param_1 + 0x184));
  if (uVar1 == '\x01') {
    this = RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
    fVar2 = RGE_Action::targetY(this);
    return (float10)fVar2;
  }
  return (float10)_DAT_0056f4bc;
}

// --------------------------------------------------

// Function: FUN_0043166e
// Address: 0043166e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0043166e(int param_1)
{
  uchar uVar1;
  RGE_Action *this;
  float fVar2;
  
  uVar1 = RGE_Action_List::have_action(*(RGE_Action_List **)(param_1 + 0x184));
  if (uVar1 == '\x01') {
    this = RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
    fVar2 = RGE_Action::targetZ(this);
    return (float10)fVar2;
  }
  return (float10)_DAT_0056f4bc;
}

// --------------------------------------------------

// Function: FUN_0043169e
// Address: 0043169e
// XREFS: None
float10 __thiscall
FUN_0043169e(RGE_Moving_Object *param_1,float param_2,float param_3,float param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float fVar7;
  
  iVar1 = __ftol();
  iVar2 = __ftol();
  fVar7 = RGE_Moving_Object::teleport(param_1,param_2,param_3,param_4);
  fVar6 = (float10)fVar7;
  if (-1 < param_1->_padding_) {
    iVar3 = __ftol();
    iVar4 = __ftol();
    fVar6 = extraout_ST0;
    if ((iVar3 != iVar1) || (iVar4 != iVar2)) {
      piVar5 = &param_1[1]._padding_;
      iVar1 = 9;
      do {
        iVar2 = *piVar5;
        if (iVar2 != 0) {
          *(char *)(iVar2 + 6) = (char)iVar3;
          *(char *)(iVar2 + 7) = (char)iVar4;
        }
        piVar5 = piVar5 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return fVar6;
}

// --------------------------------------------------

// Function: FUN_00431715
// Address: 00431715
// XREFS: None
RGE_Communications_Queue * __thiscall FUN_00431715(RGE_Communications_Queue *param_1,uint param_2)
{
  if ((int)param_2 < 0x14) {
    param_2 = 0x14;
  }
  param_1->QueueDepth = 0;
  param_1->HighQueueDepth = 0;
  param_1->LastCurrentTurn = 0;
  param_1->Queue = (MsgQueue *)0x0;
  param_1->MaxQSize = param_2;
  param_1->Sequence = '\x01';
  RGE_Communications_Queue::AllocateQueue(param_1,param_2);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043175c
// Address: 0043175c
// XREFS: None
void __fastcall FUN_0043175c(int param_1)
{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x114);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar1,0x1c,*(int *)((int)pvVar1 + -4),MsgQueue::~MsgQueue);
    operator_delete((void *)((int)pvVar1 + -4));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043178a
// Address: 0043178a
// XREFS: None
undefined4 * __thiscall FUN_0043178a(undefined4 *param_1,byte param_2)
{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_(param_1,0x1c,param_1[-1],MsgQueue::~MsgQueue);
    operator_delete(param_1 + -1);
    return param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if ((void *)param_1[3] != (void *)0x0) {
    operator_delete((void *)param_1[3]);
  }
  param_1[3] = 0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00431801
// Address: 00431801
// XREFS: None
undefined4 __thiscall FUN_00431801(int param_1,uint param_2)
{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *unaff_FS_OFFSET;
  int *piStack_20;
  uint uStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cedb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 < *(uint *)(param_1 + 8)) {
    uVar3 = 0;
  }
  else {
    iVar8 = param_2 + 1;
    piVar4 = (int *)operator_new(iVar8 * 0x1c + 4);
    uStack_4 = 0;
    if (piVar4 == (int *)0x0) {
      piStack_20 = (int *)0x0;
    }
    else {
      piStack_20 = piVar4 + 1;
      *piVar4 = iVar8;
      _eh_vector_constructor_iterator_(piStack_20,0x1c,iVar8,MsgQueue::MsgQueue,MsgQueue::~MsgQueue)
      ;
    }
    uStack_4 = 0xffffffff;
    if (piStack_20 == (int *)0x0) {
      uVar3 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x114) != 0) {
        uStack_1c = 0;
        iVar8 = -(int)piStack_20;
        piVar4 = piStack_20 + 2;
        do {
          if (*(int *)((int)piVar4 + *(int *)(param_1 + 0x114) + iVar8 + 0xc) != 0) {
            piVar4[-2] = 0;
            piVar4[-1] = 0;
            *(undefined1 *)piVar4 = 0;
            piVar4[2] = 0;
            piVar4[3] = 0;
            piVar4[4] = 0;
            piVar4[-2] = *(int *)((int)piVar4 + *(int *)(param_1 + 0x114) + iVar8 + -8);
            piVar4[-1] = *(int *)((int)piVar4 + *(int *)(param_1 + 0x114) + iVar8 + -4);
            *(undefined1 *)piVar4 = *(undefined1 *)((int)piVar4 + *(int *)(param_1 + 0x114) + iVar8)
            ;
            iVar2 = *(int *)(param_1 + 0x114) + iVar8 + -8;
            uVar7 = *(uint *)((int)piVar4 + iVar2 + 0x14);
            puVar9 = *(undefined4 **)((int)piVar4 + iVar2 + 0xc);
            puVar5 = (undefined4 *)operator_new(uVar7 + 1);
            piVar4[1] = (int)puVar5;
            if (puVar5 != (undefined4 *)0x0) {
              for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar5 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar5 = puVar5 + 1;
              }
              for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined1 *)puVar5 = *(undefined1 *)puVar9;
                puVar9 = (undefined4 *)((int)puVar9 + 1);
                puVar5 = (undefined4 *)((int)puVar5 + 1);
              }
            }
            piVar4[2] = *(int *)((int)piVar4 + *(int *)(param_1 + 0x114) + iVar8 + 8);
            piVar4[3] = *(int *)((int)piVar4 + *(int *)(param_1 + 0x114) + iVar8 + 0xc);
            piVar4[4] = *(int *)((int)piVar4 + *(int *)(param_1 + 0x114) + iVar8 + 0x10);
          }
          uStack_1c = uStack_1c + 1;
          piVar4 = piVar4 + 7;
        } while (uStack_1c <= *(uint *)(param_1 + 8));
        pvVar1 = *(void **)(param_1 + 0x114);
        if (pvVar1 != (void *)0x0) {
          _eh_vector_destructor_iterator_
                    (pvVar1,0x1c,*(int *)((int)pvVar1 + -4),MsgQueue::~MsgQueue);
          operator_delete((void *)((int)pvVar1 + -4));
        }
      }
      *(uint *)(param_1 + 8) = param_2;
      *(int **)(param_1 + 0x114) = piStack_20;
      uVar3 = 1;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_00431a3b
// Address: 00431a3b
// XREFS: None
int __thiscall FUN_00431a3b(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  piVar3 = (int *)(*(int *)(param_1 + 0x114) + 4);
  iVar2 = *(int *)(param_1 + 4) + 1;
  do {
    if (*piVar3 == param_2) {
      iVar1 = iVar1 + 1;
    }
    piVar3 = piVar3 + 7;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00431a63
// Address: 00431a63
// XREFS: None
void __fastcall FUN_00431a63(RGE_Communications_Queue *param_1)
{
  RGE_Communications_Queue::FlushTurnRange(param_1,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_00431a7a
// Address: 00431a7a
// XREFS: None
int __thiscall FUN_00431a7a(int param_1,uint param_2,uint param_3)
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iStack_8;
  uint uStack_4;
  
  iStack_8 = 0;
  uStack_4 = 0;
  iVar3 = 0;
  do {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x114) + iVar3);
    uVar2 = *(uint *)(*(int *)(param_1 + 0x114) + 4 + iVar3);
    if ((((param_2 <= uVar2) && (uVar2 <= param_3)) || ((param_2 == 0 && (param_3 == 0)))) &&
       (iStack_8 = iStack_8 + 1, puVar1[5] != 0)) {
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined1 *)(puVar1 + 2) = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      if ((void *)puVar1[3] != (void *)0x0) {
        operator_delete((void *)puVar1[3]);
      }
      puVar1[3] = 0;
    }
    uStack_4 = uStack_4 + 1;
    iVar3 = iVar3 + 0x1c;
  } while (uStack_4 <= *(uint *)(param_1 + 4));
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_00431b0f
// Address: 00431b0f
// XREFS: None
// [HELPER] s_Flushing_queue_for_player__d: "Flushing queue for player %d"
// [HELPER] s_Remove_Q___d_Seq__d_ToExecute__l: "Remove Q #%d Seq=%d ToExecute %ld From P#%d Size=%d Code=%d Ctrl=%d "
void __thiscall FUN_00431b0f(int param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uStack_4;
  
  TDebuggingLog::Log(L,(char *)L,s_Flushing_queue_for_player__d,param_2);
  uStack_4 = 0;
  iVar3 = 0;
  do {
    iVar1 = *(int *)(*(int *)(param_1 + 0x114) + 0x10 + iVar3);
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x114) + iVar3);
    if ((iVar1 == param_2) && (puVar2[5] != 0)) {
      TDebuggingLog::Log(L,(char *)L,s_Remove_Q___d_Seq__d_ToExecute__l,uStack_4,
                         (uint)*(byte *)(puVar2 + 2),puVar2[1],iVar1,puVar2[5],puVar2[6],*puVar2);
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x114) + iVar3);
      *puVar2 = 0;
      puVar2[1] = 0;
      *(undefined1 *)(puVar2 + 2) = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      if ((void *)puVar2[3] != (void *)0x0) {
        operator_delete((void *)puVar2[3]);
      }
      puVar2[3] = 0;
    }
    uStack_4 = uStack_4 + 1;
    iVar3 = iVar3 + 0x1c;
  } while (uStack_4 <= *(uint *)(param_1 + 4));
  return;
}

// --------------------------------------------------

// Function: FUN_00431bc9
// Address: 00431bc9
// XREFS: None
void __thiscall FUN_00431bc9(RGE_Communications_Queue *param_1,ulong param_2)
{
  RGE_Communications_Queue::FlushTurnRange(param_1,param_2,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00431bde
// Address: 00431bde
// XREFS: None
void __thiscall FUN_00431bde(RGE_Communications_Queue *param_1,ulong param_2)
{
  RGE_Communications_Queue::FlushTurnRange(param_1,0,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00431bef
// Address: 00431bef
// XREFS: None
undefined4 __thiscall
FUN_00431bef(RGE_Communications_Queue *param_1,ulong param_2,char *param_3,uint param_4,uint param_5
            ,byte param_6,int param_7)
{
  int *piVar1;
  MsgQueue *pMVar2;
  uint *puVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uStack_4;
  
  uVar6 = 0;
  uStack_4 = 0;
  puVar3 = &param_1->Queue->Size;
  if (*puVar3 != 0) {
    do {
      uStack_4 = uVar6;
      if (param_1->MaxQSize <= uVar6) break;
      piVar1 = (int *)(puVar3 + 7);
      puVar3 = puVar3 + 7;
      uVar6 = uVar6 + 1;
      uStack_4 = uVar6;
    } while (*piVar1 != 0);
  }
  if (param_1->MaxQSize <= uStack_4) {
    iVar4 = RGE_Communications_Queue::AllocateQueue(param_1,param_1->MaxQSize + 0x14);
    if (iVar4 == 0) {
      return 0;
    }
    uStack_4 = uStack_4 + 1;
  }
  uVar6 = param_1->HighQueueDepth;
  if (param_1->HighQueueDepth < uStack_4) {
    uVar6 = uStack_4;
  }
  pMVar2 = param_1->Queue;
  param_1->HighQueueDepth = uVar6;
  pcVar5 = (char *)operator_new(param_4 + 1);
  pMVar2[uStack_4].msgptr = pcVar5;
  if (pcVar5 != (char *)0x0) {
    for (uVar6 = param_4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = param_4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *param_3;
      param_3 = param_3 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  param_1->Queue[uStack_4].Size = param_4;
  param_1->Queue[uStack_4].SeqNo = param_6;
  param_1->Queue[uStack_4].ExecTurn = param_2;
  param_1->Queue[uStack_4].From = param_5;
  param_1->Queue[uStack_4].Code = (uint)param_6 + param_5 * 1000;
  param_1->Queue[uStack_4].ControlCommand = param_7;
  param_1->QueueDepth = uStack_4;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00431d03
// Address: 00431d03
// XREFS: None
undefined4 __fastcall FUN_00431d03(undefined4 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_00431d13
// Address: 00431d13
// XREFS: None
undefined4 __fastcall FUN_00431d13(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_00431d24
// Address: 00431d24
// XREFS: None
undefined4 __thiscall FUN_00431d24(int param_1,int param_2,int param_3,uint param_4,int *param_5)
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  piVar1 = *(int **)(param_1 + 0x114);
  while ((*piVar1 != (param_4 & 0xff) + param_2 * 1000 || (piVar1[1] != param_3))) {
    uVar4 = uVar4 + 1;
    piVar1 = piVar1 + 7;
    if (*(uint *)(param_1 + 4) < uVar4) {
      return 0;
    }
  }
  iVar2 = uVar4 * 0x1c;
  *param_5 = (*(int **)(param_1 + 0x114))[uVar4 * 7 + 5];
  DAT_0062cf3c = *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xc + iVar2);
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xc + iVar2) = 0;
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x114) + iVar2);
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined1 *)(puVar3 + 2) = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  return DAT_0062cf3c;
}

// --------------------------------------------------

