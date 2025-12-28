// Class: RGE_Communications_Synchronize
// Size:  0x7EC
//
// Member Layout:
// [0x000] TCommunications_Handler * Comm
// [0x004] ulong CheckTime
// [0x008] ulong CheckTurn
// [0x00C] int StopOnSyncFail
// [0x010] int DialogOnSyncFail
// [0x014] int SendChatMsgs
// [0x018] int NewData
// [0x01C] int LastResult
// [0x020] uint Offset
// [0x024] int DoChecksums
// [0x028] ulong LastWorldRandom
// [0x02C] ulong GameWorldChecksum
// [0x030] CHECKSUMARRAY[55] Check (sz: 0x7BC)
// ----------------------------------------------------------------

// Function: RGE_Communications_Synchronize
// Address: 00432ff0
// [HELPER] s_Check_turn____d: "Check turn = %d"
RGE_Communications_Synchronize * __thiscall
RGE_Communications_Synchronize::RGE_Communications_Synchronize
          (RGE_Communications_Synchronize *this,TCommunications_Handler *param_1)
{
  ulong *puVar1;
  int iVar2;
  
  this->Comm = param_1;
  this->CheckTime = 1000;
  this->CheckTurn = 10;
  TDebuggingLog::Log(L,(char *)L,s_Check_turn____d,10);
  this->StopOnSyncFail = 1;
  this->DoChecksums = 1;
  this->LastResult = 1;
  this->NewData = 0;
  this->Offset = 0;
  this->LastWorldRandom = 0;
  this->GameWorldChecksum = 0;
  this->SendChatMsgs = 0;
  this->DialogOnSyncFail = 0;
  puVar1 = &this->Check[0].WTurn;
  iVar2 = 0x37;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    ((CHECKSUMARRAY *)(puVar1 + -2))->PlayerNo = 0;
    puVar1 = puVar1 + 9;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Communications_Synchronize
// Address: 00433070
void __thiscall
RGE_Communications_Synchronize::~RGE_Communications_Synchronize
          (RGE_Communications_Synchronize *this)
{
  ulong *puVar1;
  int iVar2;
  
  puVar1 = &this->Check[0].WTurn;
  iVar2 = 0x37;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    ((CHECKSUMARRAY *)(puVar1 + -2))->PlayerNo = 0;
    puVar1 = puVar1 + 9;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: Add
// Address: 004330a0
int __thiscall
RGE_Communications_Synchronize::Add
          (RGE_Communications_Synchronize *this,uint param_1,ulong param_2,ulong param_3,
          ulong param_4,long param_5,long param_6,long param_7,long param_8,long param_9)
{
  int iVar1;
  uint uVar2;
  
  if (this->DoChecksums == 0) {
    return 0;
  }
  uVar2 = this->Offset + 1;
  this->Offset = uVar2;
  if (0x35 < uVar2) {
    this->Offset = 0;
  }
  this->Check[this->Offset].WTime = param_2;
  this->Check[this->Offset].WTurn = param_3;
  this->Check[this->Offset].cs1 = param_5;
  this->Check[this->Offset].cs2 = param_6;
  this->Check[this->Offset].cs3 = param_7;
  this->Check[this->Offset].cs4 = param_8;
  this->Check[this->Offset].cs5 = param_9;
  this->Check[this->Offset].Random = param_4;
  this->Check[this->Offset].PlayerNo = param_1;
  this->NewData = 1;
  iVar1 = ValidateChecksums(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                            param_9);
  return iVar1;
}

// --------------------------------------------------

// Function: ValidateChecksums
// Address: 00433180
// [HELPER] s_P__d_In_Sync___Wtime__d_WTurn__d: "P#%d In Sync @ Wtime=%d WTurn=%d Wrand=%d Wchksum=%d"
int __thiscall
RGE_Communications_Synchronize::ValidateChecksums
          (RGE_Communications_Synchronize *this,uint param_1,ulong param_2,ulong param_3,
          ulong param_4,long param_5,long param_6,long param_7,long param_8,long param_9)
{
  bool bVar1;
  ulong *puVar2;
  uint uVar3;
  
  bVar1 = false;
  if (this->NewData == 0) {
    return this->LastResult;
  }
  this->NewData = 0;
  this->LastResult = 0;
  uVar3 = 1;
  puVar2 = &this->Check[1].WTime;
  do {
    if (puVar2[1] == param_3) {
      if (*puVar2 != param_2) {
        bVar1 = true;
        goto LAB_004331bb;
      }
LAB_004331bf:
      if ((((puVar2[2] != param_5) || (puVar2[3] != param_6)) || (puVar2[4] != param_7)) ||
         (((puVar2[5] != param_8 || (puVar2[6] != param_9)) || (puVar2[7] != param_4)))) {
        bVar1 = true;
      }
    }
    else {
LAB_004331bb:
      if (*puVar2 == param_2) goto LAB_004331bf;
    }
    if (bVar1) {
      LogChecksums(this,param_1,param_2,param_3,param_5,param_6,param_7,param_8,param_9,param_4);
      TCommunications_Handler::NotifyWindowParam(this->Comm,COMM_SYNC_ERROR,param_3);
      this->LastResult = 0;
      return 0;
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 9;
    if (0x36 < uVar3) {
      TDebuggingLog::Log((TDebuggingLog *)param_4,(char *)L,s_P__d_In_Sync___Wtime__d_WTurn__d,
                         param_1,param_2,param_3,param_4,param_5);
      this->LastResult = 1;
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: DoChecksum
// Address: 00433290
// [HELPER] s_Checksum__T__d_wt__d___rand__d__: "Checksum: T#%d wt=%d   rand=%d  csum=%d"
// [HELPER] s_Sync_check_at_turn___d: "Sync check at turn #%d"
// [HELPER] s_Worldtime__ld_Random__d_Checksum: "Worldtime=%ld Random=%d Checksum=%d"
ulong __thiscall
RGE_Communications_Synchronize::DoChecksum(RGE_Communications_Synchronize *this,ulong param_1)
{
  RGE_Base_Game *pRVar1;
  ulong uVar2;
  RGE_Game_World *pRVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long cs3;
  long cs2;
  long cs4;
  char tmp [255];
  
  uVar7 = 0;
  if (this->DoChecksums == 0) {
    return 0;
  }
  if (rge_base_game->world != (RGE_Game_World *)0x0) {
    uVar7 = rge_base_game->world->world_time;
  }
  if (param_1 < this->CheckTurn) {
    return 0;
  }
  TDebuggingLog::Log(L,(char *)L,s_Sync_check_at_turn___d,this->CheckTurn);
  this->CheckTurn = this->CheckTurn + 4;
  cs4 = 0;
  cs2 = 0;
  tmp[0] = '\0';
  tmp[1] = '\0';
  tmp[2] = '\0';
  tmp[3] = '\0';
  RGE_Base_Game::GetWorldChecksums(rge_base_game,&cs4,&cs2,(long *)tmp);
  if (this->SendChatMsgs != 0) {
    sprintf(tmp + 4,s_Worldtime__ld_Random__d_Checksum,uVar7,this->LastWorldRandom,
            this->GameWorldChecksum);
    TCommunications_Handler::SendChatMsgAll(this->Comm,tmp + 4);
  }
  DAT_0062d230 = RGE_Visible_Map::checksumUnifiedVisible((*rge_base_game->world->players)->visible);
  iVar8 = 1;
  pRVar3 = rge_base_game->world;
  if (1 < pRVar3->player_num) {
    do {
      lVar4 = RGE_Visible_Map::checksumVisible(pRVar3->players[iVar8]->visible);
      pRVar1 = rge_base_game;
      (&DAT_0062d208)[iVar8] = lVar4;
      iVar8 = iVar8 + 1;
      pRVar3 = pRVar1->world;
    } while (iVar8 < pRVar3->player_num);
  }
  uVar2 = DAT_0062d230;
  lVar5 = PathingSystem::checksum(&pathSystem);
  uVar11 = this->LastWorldRandom;
  uVar9 = uVar7;
  uVar10 = param_1;
  uVar12 = uVar2;
  lVar4 = cs4;
  lVar13 = cs2;
  lVar14 = tmp._0_4_;
  lVar15 = lVar5;
  uVar6 = TCommunications_Handler::WhoAmI(this->Comm);
  Add(this,uVar6,uVar9,uVar10,uVar11,uVar12,lVar4,lVar13,lVar14,lVar15);
  TCommunications_Handler::SendChecksumMessage
            (this->Comm,uVar7,this->LastWorldRandom,uVar2,cs4,cs2,tmp._0_4_,lVar5);
  TDebuggingLog::Log((TDebuggingLog *)this->LastWorldRandom,(char *)L,
                     s_Checksum__T__d_wt__d___rand__d__,param_1,uVar7,
                     (TDebuggingLog *)this->LastWorldRandom,this->GameWorldChecksum);
  TDebuggingLog::FlushLog(L);
  return 1;
}

// --------------------------------------------------

// Function: SetLastWorldRandom
// Address: 00433450
void __thiscall
RGE_Communications_Synchronize::SetLastWorldRandom
          (RGE_Communications_Synchronize *this,ulong param_1)
{
  this->LastWorldRandom = param_1;
  return;
}

// --------------------------------------------------

// Function: LogChecksums
// Address: 00433460
// [HELPER] s_Adding___P__d__WTime__d__Turn__d: "Adding:  P#%d  WTime=%d  Turn=%d Cs1=%d  Cs2=%d  Cs3=%d  Cs4=%d  Cs5=%d  Rand=%d"
// [HELPER] s_C__aoesync_txt: "C:\aoesync.txt"
// [HELPER] s_PLAYER___s: "PLAYER: %s"
// [HELPER] s_P__d_CSum__d_: "P#%d CSum=%d "
// [HELPER] s_Player_Checksum_information_: "Player Checksum information:"
// [HELPER] s_Plr__Wrldtime_CommTurn_Random_WC: "Plr: Wrldtime CommTurn Random WChecksum CksumNew Position Actions  Unif. Visible"
// [HELPER] s_VISIBLE_Checksum____d: "VISIBLE Checksum = %d"
// [HELPER] s__: "}"
// [HELPER] s___: "]\n"
// [HELPER] s____2d____8d___8d___6d___8d___8d_: " %.2d: %.8d %.8d %.6d %.8d %.8d %.8d %.8d %.8d "
// [HELPER] s______: "---- "
// [HELPER] s____end_of_log: "...end of log"
// [HELPER] s_wt: "wt"
void __thiscall
RGE_Communications_Synchronize::LogChecksums
          (RGE_Communications_Synchronize *this,uint param_1,ulong param_2,ulong param_3,
          long param_4,long param_5,long param_6,long param_7,long param_8,ulong param_9)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  long lVar6;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 *local_20c;
  char TBuff [513];
  
  TBuff._0_4_ = this;
  iVar3 = fopen(s_C__aoesync_txt,s_wt);
  sprintf(TBuff + 4,s_Adding___P__d__WTime__d__Turn__d,param_1,param_2,param_3,param_4,param_5,
          param_6,param_7,param_8,param_9);
  TDebuggingLog::Log(this_00,(char *)L,TBuff + 4);
  if (iVar3 != 0) {
    fputs(TBuff + 4,iVar3);
    fputs(&s__,iVar3);
  }
  sprintf(TBuff + 4,s_Plr__Wrldtime_CommTurn_Random_WC);
  TDebuggingLog::Log(L,(char *)L,TBuff + 4);
  if (iVar3 != 0) {
    fputs(TBuff + 4,iVar3);
    fputs(&s__,iVar3);
  }
  puVar10 = &this->Check[1].WTime;
  local_20c = (undefined4 *)0x35;
  do {
    sprintf(TBuff + 4,s____2d____8d___8d___6d___8d___8d_,((CHECKSUMARRAY *)(puVar10 + -1))->PlayerNo
            ,*puVar10,puVar10[1],puVar10[7],puVar10[2],puVar10[3],puVar10[4],puVar10[5],puVar10[6]);
    TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
    if (iVar3 != 0) {
      fputs(TBuff + 4,iVar3);
      fputs(&s__,iVar3);
    }
    if ((puVar10[1] == param_3) && (*puVar10 != param_2)) {
      sprintf(TBuff + 4,s______>__WORLD_TIME_IS_OUT_OF_SYN,param_2,*puVar10,param_3);
      TDebuggingLog::Log(this_01,(char *)L,TBuff + 4);
      if (iVar3 != 0) {
        fputs(TBuff + 4,iVar3);
        fputs(&s__,iVar3);
      }
    }
    if (*puVar10 == param_2) {
      if (puVar10[7] != param_9) {
        sprintf(TBuff + 4,s______>__MISMATCHED_RANDOM____d_s,param_9,puVar10[7]);
        TDebuggingLog::Log(L,(char *)L,TBuff + 4);
        if (iVar3 != 0) {
          fputs(TBuff + 4,iVar3);
          fputs(&s__,iVar3);
        }
      }
      if (puVar10[2] != param_4) {
        sprintf(TBuff + 4,s______>__MISMATCHED_Unified_Visib);
        TDebuggingLog::Log(this_02,(char *)L,TBuff + 4);
        if (iVar3 != 0) {
          fputs(TBuff + 4,iVar3);
          fputs(&s__,iVar3);
        }
      }
      if (puVar10[3] != param_5) {
        sprintf(TBuff + 4,s______>__MISMATCHED_CHECKSUM___Ne);
        TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
        if (iVar3 != 0) {
          fputs(TBuff + 4,iVar3);
          fputs(&s__,iVar3);
        }
      }
      if (puVar10[4] != param_6) {
        sprintf(TBuff + 4,s______>__MISMATCHED__Position);
        TDebuggingLog::Log(L,(char *)L,TBuff + 4);
        if (iVar3 != 0) {
          fputs(TBuff + 4,iVar3);
          fputs(&s__,iVar3);
        }
      }
      if (puVar10[5] != param_7) {
        sprintf(TBuff + 4,s______>__MISMATCHED___Action);
        TDebuggingLog::Log(this_03,(char *)L,TBuff + 4);
        if (iVar3 != 0) {
          fputs(TBuff + 4,iVar3);
          fputs(&s__,iVar3);
        }
      }
      if (puVar10[6] != param_8) {
        sprintf(TBuff + 4,s______>__MISMATCHED___Obstruction);
        TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
        if (iVar3 != 0) {
          fputs(TBuff + 4,iVar3);
          fputs(&s__,iVar3);
        }
      }
    }
    puVar10 = puVar10 + 9;
    local_20c = (undefined4 *)((int)local_20c + -1);
  } while (local_20c != (undefined4 *)0x0);
  uVar7 = 0xffffffff;
  pcVar5 = TBuff;
  pcVar11 = &s_Player_Checksum_information_;
  do {
    pcVar12 = pcVar11;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  pcVar11 = pcVar12 + -uVar7;
  for (uVar8 = uVar7 >> 2; pcVar5 = pcVar5 + 4, uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar5 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar5 = pcVar5 + 1;
  }
  TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
  if (iVar3 != 0) {
    fputs(TBuff + 4,iVar3);
    fputs(&s__,iVar3);
  }
  uVar7 = 0;
  local_20c = &DAT_0062d208;
  do {
    uVar2 = TBuff._0_4_;
    iVar4 = TCommunications_Handler::IsPlayerHuman(*(TCommunications_Handler **)TBuff._0_4_,uVar7);
    if (iVar4 == 0) {
      iVar4 = TCommunications_Handler::IsPlayerComputer(*(TCommunications_Handler **)uVar2,uVar7);
      if (iVar4 != 0) goto LAB_004338b6;
    }
    else {
LAB_004338b6:
      uVar8 = 0xffffffff;
      pcVar5 = TBuff;
      pcVar11 = (char *)&s___;
      do {
        pcVar12 = pcVar11;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar12 = pcVar11 + 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar12;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar11 = pcVar12 + -uVar8;
      for (uVar9 = uVar8 >> 2; pcVar5 = pcVar5 + 4, uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar5 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar5 = pcVar5 + 1;
      }
      TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
      if (iVar3 != 0) {
        fputs(TBuff + 4,iVar3);
        fputs(&s__,iVar3);
      }
      pcVar5 = TCommunications_Handler::GetPlayerName
                         (*(TCommunications_Handler **)TBuff._0_4_,uVar7);
      sprintf(TBuff + 4,s_PLAYER___s,pcVar5);
      TDebuggingLog::Log(L,(char *)L,TBuff + 4);
      if (iVar3 != 0) {
        fputs(TBuff + 4,iVar3);
        fputs(&s__,iVar3);
      }
      lVar6 = RGE_Base_Game::GetChecksum(rge_base_game,uVar7);
      sprintf(TBuff + 4,s_P__d_CSum__d_,uVar7,lVar6);
      TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
      if (iVar3 != 0) {
        fputs(TBuff + 4,iVar3);
        fputs(&s__,iVar3);
      }
      sprintf(TBuff + 4,s_VISIBLE_Checksum____d,*local_20c);
      TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
      if (iVar3 != 0) {
        fputs(TBuff + 4,iVar3);
        fputs(&s__,iVar3);
      }
    }
    uVar7 = uVar7 + 1;
    local_20c = local_20c + 1;
  } while (local_20c < &UNK_0062d210.field_0x1c);
  uVar7 = 0xffffffff;
  pcVar5 = TBuff;
  pcVar11 = &s____end_of_log;
  do {
    pcVar12 = pcVar11;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  pcVar11 = pcVar12 + -uVar7;
  for (uVar8 = uVar7 >> 2; pcVar5 = pcVar5 + 4, uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar5 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar5 = pcVar5 + 1;
  }
  TDebuggingLog::Log((TDebuggingLog *)(TBuff + 4),(char *)L,(TDebuggingLog *)(TBuff + 4));
  if (iVar3 != 0) {
    fputs(TBuff + 4,iVar3);
    fputs(&s__,iVar3);
  }
  fclose(iVar3);
  return;
}

// --------------------------------------------------

// Function: EnableSyncChecking
// Address: 00433a90
void __thiscall
RGE_Communications_Synchronize::EnableSyncChecking(RGE_Communications_Synchronize *this,int param_1)
{
  this->DoChecksums = param_1;
  return;
}

// --------------------------------------------------

// Function: SetStopOnFail
// Address: 00433aa0
void __thiscall
RGE_Communications_Synchronize::SetStopOnFail(RGE_Communications_Synchronize *this,int param_1)
{
  this->StopOnSyncFail = param_1;
  return;
}

// --------------------------------------------------

// Function: SetDialogOnFail
// Address: 00433ab0
void __thiscall
RGE_Communications_Synchronize::SetDialogOnFail(RGE_Communications_Synchronize *this,int param_1)
{
  this->DialogOnSyncFail = param_1;
  return;
}

// --------------------------------------------------

// Function: SendChatMsgsAtChecksum
// Address: 00433ac0
void __thiscall
RGE_Communications_Synchronize::SendChatMsgsAtChecksum
          (RGE_Communications_Synchronize *this,int param_1)
{
  this->SendChatMsgs = param_1;
  return;
}

// --------------------------------------------------

// Function: IsPlayerOutOfSync
// Address: 00433ad0
// [HELPER] s_OUTOFSYNC__DIDN_T_FIND_MY_VALUES: "OUTOFSYNC: DIDN'T FIND MY VALUES"
// [HELPER] s_OUTOFSYNC___d_diff___d__d__d__d_: "OUTOFSYNC: %d diff: %d %d %d %d %d %d"
// [HELPER] s_OUTOFSYNC___d_same___d__d__d__d_: "OUTOFSYNC: %d same: %d %d %d %d %d %d"
// [HELPER] s_OUTOFSYNC__my_values___d__d__d__: "OUTOFSYNC: my values: %d %d %d %d %d %d"
// [HELPER] s_OUTOFSYNC__numplayers__d__diff__: "OUTOFSYNC: numplayers=%d, diff=%d, same=%d"
// [HELPER] s_OUTOFSYNC__return_not_out: "OUTOFSYNC: return not out"
// [HELPER] s_OUTOFSYNC__return_not_out_2: "OUTOFSYNC: return not out 2"
// [HELPER] s_OUTOFSYNC__return_out: "OUTOFSYNC: return out"
int __thiscall
RGE_Communications_Synchronize::IsPlayerOutOfSync
          (RGE_Communications_Synchronize *this,uint param_1,ulong param_2)
{
  bool bVar1;
  ulong *puVar2;
  int iVar3;
  TDebuggingLog *this_00;
  TDebuggingLog *pTVar4;
  TDebuggingLog *this_01;
  ulong uVar5;
  long lVar6;
  uint uVar7;
  ulong *puVar8;
  char *pcVar9;
  long mycs4;
  long mycs3;
  long mycs2;
  long mycs5;
  int NumSame;
  int NumDiff;
  int NumPlayers;
  int foundMine;
  uint myRandom;
  uint local_8;
  
  uVar5 = 0;
  puVar8 = &this->Check[1].WTurn;
  NumPlayers = 0;
  NumDiff = 0;
  bVar1 = false;
  lVar6 = 0;
  mycs5 = 0;
  mycs2 = 0;
  mycs3 = 0;
  NumSame = 0;
  local_8 = 0;
  foundMine = 0;
  puVar2 = puVar8;
  pTVar4 = (TDebuggingLog *)0x1;
  while ((((CHECKSUMARRAY *)(puVar2 + -2))->PlayerNo != param_1 || (*puVar2 != param_2))) {
    this_00 = (TDebuggingLog *)((int)&pTVar4->Timestamp + 1);
    puVar2 = puVar2 + 9;
    pTVar4 = this_00;
    if ((TDebuggingLog *)0x36 < this_00) {
LAB_00433b69:
      if (!bVar1) {
        TDebuggingLog::Log(this_00,(char *)L,s_OUTOFSYNC__DIDN_T_FIND_MY_VALUES);
        return 0;
      }
      TDebuggingLog::Log((TDebuggingLog *)mycs5,(char *)L,s_OUTOFSYNC__my_values___d__d__d__,uVar5,
                         lVar6,mycs5,mycs2,mycs3,NumSame);
      uVar7 = 1;
      do {
        if ((((CHECKSUMARRAY *)(puVar8 + -2))->PlayerNo != param_1) && (*puVar8 == param_2)) {
          if (((uVar5 == puVar8[-1]) &&
              (((lVar6 == puVar8[1] && (mycs5 == puVar8[2])) && (mycs2 == puVar8[3])))) &&
             (((mycs3 == puVar8[4] && (NumSame == puVar8[5])) && (local_8 == puVar8[6])))) {
            NumDiff = NumDiff + 1;
            pcVar9 = s_OUTOFSYNC___d_same___d__d__d__d_;
            pTVar4 = (TDebuggingLog *)mycs3;
          }
          else {
            NumPlayers = NumPlayers + 1;
            pcVar9 = s_OUTOFSYNC___d_diff___d__d__d__d_;
            pTVar4 = (TDebuggingLog *)mycs2;
          }
          TDebuggingLog::Log(pTVar4,(char *)L,pcVar9,uVar7,uVar5,lVar6,mycs5,mycs2,mycs3,NumSame);
        }
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 9;
      } while (uVar7 < 0x37);
      uVar7 = 1;
      do {
        iVar3 = TCommunications_Handler::GetPlayerHumanity(this->Comm,uVar7);
        if (iVar3 == 2) {
          foundMine = foundMine + 1;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 10);
      TDebuggingLog::Log(L,(char *)L,s_OUTOFSYNC__numplayers__d__diff__,foundMine,NumPlayers,NumDiff
                        );
      if (foundMine + -1 <= NumDiff + NumPlayers) {
        if (NumPlayers <= NumDiff) {
          TDebuggingLog::Log(this_01,(char *)L,s_OUTOFSYNC__return_not_out_2);
          return 0;
        }
        TDebuggingLog::Log(L,(char *)L,s_OUTOFSYNC__return_out);
        return 1;
      }
      TDebuggingLog::Log(this_01,(char *)L,s_OUTOFSYNC__return_not_out);
      return 0;
    }
  }
  bVar1 = true;
  mycs5 = this->Check[(int)pTVar4].cs2;
  mycs2 = this->Check[(int)pTVar4].cs3;
  uVar5 = this->Check[(int)pTVar4].WTime;
  mycs3 = this->Check[(int)&pTVar4->Timestamp].cs4;
  this_00 = (TDebuggingLog *)this->Check[(int)pTVar4].cs5;
  lVar6 = this->Check[(int)pTVar4].cs1;
  local_8 = this->Check[(int)pTVar4].Random;
  NumSame = (int)this_00;
  goto LAB_00433b69;
}

// --------------------------------------------------

