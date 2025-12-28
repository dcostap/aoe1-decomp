// GLOBAL FUNCTIONS PART 5000
// Function: FUN_005292c7
// Address: 005292c7
// XREFS: None
void __thiscall FUN_005292c7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa84) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_005292dd
// Address: 005292dd
// XREFS: None
undefined4 __fastcall FUN_005292dd(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa88);
}

// --------------------------------------------------

// Function: FUN_005292e7
// Address: 005292e7
// XREFS: None
void __thiscall FUN_005292e7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa88) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_005292fd
// Address: 005292fd
// XREFS: None
undefined4 __fastcall FUN_005292fd(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa8c);
}

// --------------------------------------------------

// Function: FUN_00529307
// Address: 00529307
// XREFS: None
undefined4 __fastcall FUN_00529307(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa90);
}

// --------------------------------------------------

// Function: FUN_00529317
// Address: 00529317
// XREFS: None
void __thiscall FUN_00529317(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xa8c) = param_2;
  *(undefined4 *)(param_1 + 0xa90) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00529337
// Address: 00529337
// XREFS: None
undefined1 __thiscall FUN_00529337(int param_1,int param_2)
{
  return *(undefined1 *)(param_1 + 0xa94 + param_2);
}

// --------------------------------------------------

// Function: FUN_00529362
// Address: 00529362
// XREFS: None
undefined4 __thiscall FUN_00529362(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0xaa0 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_0052937e
// Address: 0052937e
// XREFS: None
void __thiscall FUN_0052937e(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xaa0 + param_2 * 4) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00529392
// Address: 00529392
// XREFS: None
undefined1 __thiscall FUN_00529392(int param_1,int param_2)
{
  return *(undefined1 *)(param_1 + 0xac4 + param_2);
}

// --------------------------------------------------

// Function: FUN_005293c2
// Address: 005293c2
// XREFS: None
undefined1 __thiscall FUN_005293c2(int param_1,int param_2)
{
  return *(undefined1 *)(param_1 + 0xacd + param_2);
}

// --------------------------------------------------

// Function: FUN_005293f2
// Address: 005293f2
// XREFS: None
undefined1 __fastcall FUN_005293f2(int param_1)
{
  return *(undefined1 *)(param_1 + 0xad6);
}

// --------------------------------------------------

// Function: FUN_00529409
// Address: 00529409
// XREFS: None
undefined1 __fastcall FUN_00529409(int param_1)
{
  return *(undefined1 *)(param_1 + 0xad7);
}

// --------------------------------------------------

// Function: FUN_00529419
// Address: 00529419
// XREFS: None
undefined1 __fastcall FUN_00529419(int param_1)
{
  return *(undefined1 *)(param_1 + 0xad8);
}

// --------------------------------------------------

// Function: FUN_00529429
// Address: 00529429
// XREFS: None
undefined1 __fastcall FUN_00529429(int param_1)
{
  return *(undefined1 *)(param_1 + 0xad9);
}

// --------------------------------------------------

// Function: FUN_00529439
// Address: 00529439
// XREFS: None
undefined4 __fastcall FUN_00529439(int param_1)
{
  return *(undefined4 *)(param_1 + 0xadc);
}

// --------------------------------------------------

// Function: FUN_00529447
// Address: 00529447
// XREFS: None
undefined4 __fastcall FUN_00529447(int param_1)
{
  return *(undefined4 *)(param_1 + 0xae0);
}

// --------------------------------------------------

// Function: FUN_00529457
// Address: 00529457
// XREFS: None
undefined1 __fastcall FUN_00529457(int param_1)
{
  return *(undefined1 *)(param_1 + 0xae4);
}

// --------------------------------------------------

// Function: FUN_00529469
// Address: 00529469
// XREFS: None
undefined1 __fastcall FUN_00529469(int param_1)
{
  return *(undefined1 *)(param_1 + 0xae5);
}

// --------------------------------------------------

// Function: FUN_00529477
// Address: 00529477
// XREFS: None
char __fastcall FUN_00529477(RGE_Base_Game *param_1)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::multiplayerGame(param_1);
  if (iVar1 != 0) {
    return param_1[1].save_music_file[0x42];
  }
  return '2';
}

// --------------------------------------------------

// Function: FUN_00529498
// Address: 00529498
// XREFS: None
undefined1 __fastcall FUN_00529498(int param_1)
{
  return *(undefined1 *)(param_1 + 0x1190);
}

// --------------------------------------------------

// Function: FUN_005294a7
// Address: 005294a7
// XREFS: None
undefined4 __fastcall FUN_005294a7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1194);
}

// --------------------------------------------------

// Function: FUN_005294b7
// Address: 005294b7
// XREFS: None
void __thiscall FUN_005294b7(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xad6) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_005294cd
// Address: 005294cd
// XREFS: None
void __thiscall FUN_005294cd(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xad7) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_005294dd
// Address: 005294dd
// XREFS: None
void __thiscall FUN_005294dd(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xad8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_005294ed
// Address: 005294ed
// XREFS: None
void __thiscall FUN_005294ed(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xad9) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_005294fd
// Address: 005294fd
// XREFS: None
void __thiscall FUN_005294fd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xadc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052950d
// Address: 0052950d
// XREFS: None
void __thiscall FUN_0052950d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xae0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052951d
// Address: 0052951d
// XREFS: None
void __thiscall FUN_0052951d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xae4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052952d
// Address: 0052952d
// XREFS: None
void __thiscall FUN_0052952d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xae5) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052953d
// Address: 0052953d
// XREFS: None
void __thiscall FUN_0052953d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xae6) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052954d
// Address: 0052954d
// XREFS: None
void __thiscall FUN_0052954d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x1190) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052955d
// Address: 0052955d
// XREFS: None
void __thiscall FUN_0052955d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1194) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052956d
// Address: 0052956d
// XREFS: None
Alignment * FUN_0052956d(void)
{
  DAT_0086bca0._0_1_ = 0;
  return &DAT_0086bca0;
}

// --------------------------------------------------

// Function: FUN_0052957d
// Address: 0052957d
// XREFS: None
long FUN_0052957d(TRIBE_Game *param_1,uint param_2,uint param_3,long param_4)
{
  long lVar1;
  
  if (param_3 < 0x201) {
    if (param_3 == 0x200) {
      if (param_1->_padding_ == 1) {
        SetCursor(0);
      }
    }
    else if (param_3 == 7) {
      if (param_1->_padding_ == 0) {
        RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
      }
      else {
        RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
      }
    }
  }
  else if (((param_3 == 0x201) || (param_3 == 0x204)) && (param_1->_padding_ == 1)) {
    TRIBE_Game::stop_video(param_1,'\x01');
    return 0;
  }
  lVar1 = RGE_Base_Game::wnd_proc(param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_0052960c
// Address: 0052960c
// XREFS: None
// [HELPER] s_Already_in_handle_idle__wT__ld_: "Already in handle_idle, wT=%ld."
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s__: "}"
// [HELPER] s_paused: "paused"
// [HELPER] s_stopped: "stopped"
int __fastcall FUN_0052960c(TRIBE_Game *param_1)
{
  char cVar1;
  byte bVar2;
  TDebuggingLog *this;
  int iVar3;
  ulong uVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  TRIBE_Screen_Wait *this_00;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  char *pcVar12;
  char *pcVar13;
  bool bVar14;
  byte abStack_964 [100];
  char acStack_900 [2304];
  
  iVar3 = RGE_Base_Game::handle_idle((RGE_Base_Game *)param_1);
  if (iVar3 == 0) {
    return 0;
  }
  if (param_1->inHandleIdle != 0) {
    this = *(TDebuggingLog **)(param_1->_padding_ + 4);
    TDebuggingLog::Log(this,(char *)L,s_Already_in_handle_idle__wT__ld_,this);
    return 0;
  }
  uVar10 = 1;
  param_1->inHandleIdle = 1;
  color_log('L','L',5);
  color_log('L','\x16',5);
  iVar6 = param_1->_padding_;
  if ((iVar6 != 1) || (param_1->video_window == (void *)0x0)) {
    if (iVar6 == 3) {
      iVar6 = TCommunications_Handler::MultiplayerGameStart
                        ((TCommunications_Handler *)param_1->_padding_);
      if (iVar6 == 0) {
        color_log('L','T',5);
        uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x139c);
        if (499 < uVar4 - DAT_0086be04) {
          (**(code **)(param_1->_padding_ + 0x20))(0x454,acStack_900,0x900);
          uVar8 = 0xffffffff;
          pcVar7 = &s__;
          do {
            pcVar13 = pcVar7;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            pcVar13 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar13;
          } while (cVar1 != '\0');
          uVar8 = ~uVar8;
          iVar6 = -1;
          pcVar7 = acStack_900;
          do {
            pcVar12 = pcVar7;
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            pcVar12 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar12;
          } while (cVar1 != '\0');
          pcVar7 = pcVar13 + -uVar8;
          pcVar13 = pcVar12 + -1;
          for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar13 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar13 = pcVar13 + 1;
          }
          do {
            uVar8 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)param_1->_padding_);
            if (uVar10 != uVar8) {
              iVar6 = TCommunications_Handler::IsPlayerHuman
                                ((TCommunications_Handler *)param_1->_padding_,uVar10);
              if (iVar6 != 0) {
                uVar8 = 0xffffffff;
                pcVar7 = &s__;
                do {
                  pcVar13 = pcVar7;
                  if (uVar8 == 0) break;
                  uVar8 = uVar8 - 1;
                  pcVar13 = pcVar7 + 1;
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar13;
                } while (cVar1 != '\0');
                uVar8 = ~uVar8;
                iVar6 = -1;
                pcVar7 = acStack_900;
                do {
                  pcVar12 = pcVar7;
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  pcVar12 = pcVar7 + 1;
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar12;
                } while (cVar1 != '\0');
                pcVar7 = pcVar13 + -uVar8;
                pcVar13 = pcVar12 + -1;
                for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                  *(undefined4 *)pcVar13 = *(undefined4 *)pcVar7;
                  pcVar7 = pcVar7 + 4;
                  pcVar13 = pcVar13 + 4;
                }
                for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *pcVar13 = *pcVar7;
                  pcVar7 = pcVar7 + 1;
                  pcVar13 = pcVar13 + 1;
                }
                pcVar7 = TCommunications_Handler::WaitingOnNamedInfo
                                   ((TCommunications_Handler *)param_1->_padding_,uVar10);
                uVar8 = 0xffffffff;
                do {
                  pcVar13 = pcVar7;
                  if (uVar8 == 0) break;
                  uVar8 = uVar8 - 1;
                  pcVar13 = pcVar7 + 1;
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar13;
                } while (cVar1 != '\0');
                uVar8 = ~uVar8;
                iVar6 = -1;
                pcVar7 = acStack_900;
                do {
                  pcVar12 = pcVar7;
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  pcVar12 = pcVar7 + 1;
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar12;
                } while (cVar1 != '\0');
                pcVar7 = pcVar13 + -uVar8;
                pcVar13 = pcVar12 + -1;
                for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                  *(undefined4 *)pcVar13 = *(undefined4 *)pcVar7;
                  pcVar7 = pcVar7 + 4;
                  pcVar13 = pcVar13 + 4;
                }
                for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *pcVar13 = *pcVar7;
                  pcVar7 = pcVar7 + 1;
                  pcVar13 = pcVar13 + 1;
                }
              }
            }
            uVar10 = uVar10 + 1;
          } while ((int)uVar10 < 9);
          this_00 = (TRIBE_Screen_Wait *)
                    TPanelSystem::panel(&panel_system,s_Multiplayer_Wait_Screen);
          if (this_00 != (TRIBE_Screen_Wait *)0x0) {
            TRIBE_Screen_Wait::set_text(this_00,acStack_900);
          }
          DAT_0086be04 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x13ac);
        }
      }
      else {
        color_log('L','$',5);
        TRIBE_Game::let_game_begin(param_1);
      }
    }
    else if (((iVar6 == 4) || (iVar6 == 6)) || (iVar6 == 5)) {
      color_log('L','2',5);
      if ((out_of_sync2 == 0) && (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
        TRIBE_Screen_Game::handle_game_update(param_1->game_screen);
      }
    }
    goto LAB_0052994c;
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x1381);
  if (uVar4 - param_1->last_video_time < 1000) goto LAB_0052994c;
  SendMessageA(param_1->video_window,0x46a,100,abStack_964);
  if (abStack_964[0] == 0) {
LAB_00529784:
    TRIBE_Game::stop_video(param_1,'\x01');
  }
  else {
    pbVar11 = &s_stopped;
    pbVar5 = abStack_964;
    do {
      bVar2 = *pbVar5;
      bVar14 = bVar2 < *pbVar11;
      if (bVar2 != *pbVar11) {
LAB_00529725:
        iVar6 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        goto LAB_0052972a;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar14 = bVar2 < pbVar11[1];
      if (bVar2 != pbVar11[1]) goto LAB_00529725;
      pbVar5 = pbVar5 + 2;
      pbVar11 = pbVar11 + 2;
    } while (bVar2 != 0);
    iVar6 = 0;
LAB_0052972a:
    if (iVar6 == 0) goto LAB_00529784;
    if (param_1->video_paused == 0) {
      pbVar11 = &s_paused;
      pbVar5 = abStack_964;
      do {
        bVar2 = *pbVar5;
        bVar14 = bVar2 < *pbVar11;
        if (bVar2 != *pbVar11) {
LAB_00529769:
          iVar6 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_0052976e;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar14 = bVar2 < pbVar11[1];
        if (bVar2 != pbVar11[1]) goto LAB_00529769;
        pbVar5 = pbVar5 + 2;
        pbVar11 = pbVar11 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_0052976e:
      if (iVar6 == 0) {
        SendMessageA(param_1->video_window,0x855,0,0);
      }
    }
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x138d);
  param_1->last_video_time = uVar4;
LAB_0052994c:
  color_log('L','_',5);
  param_1->inHandleIdle = 0;
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00529973
// Address: 00529973
// XREFS: None
int __thiscall
FUN_00529973(RGE_Base_Game *param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  int iVar1;
  
  iVar1 = 1;
  if (param_1->prog_mode == 1) {
    if ((param_1[1].mouse_blit_sync != 0) && (*(int *)param_1[1].work_dir == 0)) {
      SendMessageA(param_1[1].mouse_blit_sync,0x476,0,0);
      return 1;
    }
  }
  else {
    iVar1 = RGE_Base_Game::handle_query_new_palette(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_005299db
// Address: 005299db
// XREFS: None
undefined4 __thiscall
FUN_005299db(RGE_Base_Game *param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  int iVar1;
  
  RGE_Base_Game::handle_activate(param_1,param_2,param_3,param_4,param_5);
  if ((param_1->prog_mode == 1) && (iVar1 = param_1[1].mouse_blit_sync, iVar1 != 0)) {
    if (param_4 == 1) {
      if (param_1[1].mouse_cursor != (void *)0x0) {
        SendMessageA(iVar1,0x855,0,0);
        param_1[1].mouse_cursor = (void *)0x0;
        return 1;
      }
    }
    else if (param_1[1].mouse_cursor == (void *)0x0) {
      SendMessageA(iVar1,0x809,0,0);
      param_1[1].mouse_cursor = (void *)0x1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00529a6d
// Address: 00529a6d
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_Out_of_sync_detected_by_comm___: "Out of sync detected by comm..."
// [HELPER] s_SKIPSYNCSAVE: "SKIPSYNCSAVE"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Temp_Screen: "Temp Screen"
// [HELPER] s_____PROBLEM_COMMUNICATING_WITH__: "$$$ PROBLEM COMMUNICATING WITH %s"
// [HELPER] s_syncerr_d_gam: "syncerr%d.gam"
undefined4 __thiscall FUN_00529a6d(TRIBE_Game *param_1,undefined4 param_2,ulong param_3)
{
  uchar uVar1;
  TEasy_Panel *pTVar2;
  uint uVar3;
  TRIBE_Screen_Status_Message *this;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  char acStack_210 [260];
  undefined1 auStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056182e;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = param_1->_padding_;
  if (iVar4 == 3) {
    switch(param_2) {
    case 0x17a8:
    case 0x17a9:
    case 0x17aa:
    case 0x17ab:
    case 0x17b2:
    case 0x17b6:
      TRIBE_Game::quit_game(param_1);
      TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Wait_Screen);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
      pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
joined_r0x00529bcc:
      if (pTVar2 != (TEasy_Panel *)0x0) {
        TEasy_Panel::popupOKDialog(pTVar2,0x25c9,(char *)0x0,0x1c2,100);
      }
      break;
    case 0x17ac:
    case 0x17b7:
      (**(code **)(param_1->_padding_ + 0x44))();
      RGE_Base_Game::setSinglePlayerGame((RGE_Base_Game *)param_1,1);
      TRIBE_Game::quit_game(param_1);
      TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Wait_Screen);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
      pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
      if (pTVar2 != (TEasy_Panel *)0x0) {
        TEasy_Panel::popupOKDialog(pTVar2,0x25c9,(char *)0x0,0x1c2,100);
      }
    }
  }
  else {
    if (((iVar4 != 4) && (iVar4 != 6)) && (iVar4 != 5)) goto switchD_00529abb_caseD_17ad;
    switch(param_2) {
    case 0x17a2:
      if (param_1->game_screen != (TRIBE_Screen_Game *)0x0) {
        TRIBE_Screen_Game::handle_pause(param_1->game_screen);
      }
      break;
    case 0x17a3:
      if (param_1->game_screen != (TRIBE_Screen_Game *)0x0) {
        TRIBE_Screen_Game::handle_resume(param_1->game_screen);
      }
      break;
    case 0x17b0:
      if (param_1->game_screen != (TRIBE_Screen_Game *)0x0) {
        RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,2);
        TRIBE_Screen_Game::display_system_message
                  (param_1->game_screen,s_Out_of_sync_detected_by_comm___);
      }
      uVar1 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)param_1,s_SKIPSYNCSAVE);
      if (uVar1 == '\0') {
        if (out_of_sync == 0) {
          out_of_sync = 1;
          iVar4 = TCommunications_Handler::IsHost((TCommunications_Handler *)param_1->_padding_);
          if (iVar4 != 0) {
            TRIBE_Command::command_save_game(*(TRIBE_Command **)(param_1->_padding_ + 0x58));
          }
        }
      }
      else if (out_of_sync == 0) {
        uVar3 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)param_1->_padding_);
        iVar4 = TCommunications_Handler::IsPlayerOutOfSync
                          ((TCommunications_Handler *)param_1->_padding_,uVar3,param_3);
        if (iVar4 != 0) {
          out_of_sync = 1;
          out_of_sync2 = 1;
          this = (TRIBE_Screen_Status_Message *)operator_new(0x47c);
          uStack_4 = 0;
          if (this != (TRIBE_Screen_Status_Message *)0x0) {
            TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
                      (this,s_Temp_Screen,s_,(char *)0x0,-1);
          }
          uStack_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Temp_Screen,0);
          TRIBE_Game::close_game_screens(param_1,1);
          if (do_debug_random != 0) {
            debug_random_write();
            dump_vismap_log();
          }
          iVar4 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)param_1->_padding_);
          sprintf(acStack_210,s_syncerr_d_gam,iVar4);
          TRIBE_Game::save_game(param_1,acStack_210);
          RGE_Player::loss_if_game_on
                    (*(RGE_Player **)
                      (*(int *)(param_1->_padding_ + 0x40) +
                      *(short *)(param_1->_padding_ + 0x7c) * 4));
          TRIBE_Game::do_game_over(param_1);
          pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
          if (pTVar2 != (TEasy_Panel *)0x0) {
            TEasy_Panel::popupOKDialog(pTVar2,0x966,(char *)0x0,0x1c2,100);
          }
          TPanelSystem::destroyPanel(&panel_system,s_Temp_Screen);
        }
      }
      break;
    case 0x17b2:
      if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) break;
      RGE_Player::loss_if_game_on
                (*(RGE_Player **)
                  (*(int *)(param_1->_padding_ + 0x40) + *(short *)(param_1->_padding_ + 0x7c) * 4))
      ;
      TRIBE_Game::do_game_over(param_1);
      pTVar2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
      goto joined_r0x00529bcc;
    case 0x17bd:
      iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,param_3);
      if (((iVar4 != *(short *)(param_1->_padding_ + 0x7c)) &&
          (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) &&
         ((iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,param_3), 0 < iVar4 &&
          ((&player_dropped)[param_3] == (int *)0x0)))) {
        RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,2);
        (**(code **)(param_1->_padding_ + 0x20))(0x4c1,auStack_10c,0x100);
        iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,param_3);
        sprintf(acStack_210,auStack_10c,
                *(undefined4 *)(*(int *)(*(int *)(param_1->_padding_ + 0x40) + iVar4 * 4) + 0x44));
        TRIBE_Screen_Game::display_system_message(param_1->game_screen,acStack_210);
        iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,param_3);
        TDebuggingLog::Log(L,(char *)L,s_____PROBLEM_COMMUNICATING_WITH__,
                           *(undefined4 *)
                            (*(int *)(*(int *)(param_1->_padding_ + 0x40) + iVar4 * 4) + 0x44));
      }
      break;
    case 0x17d5:
      if (param_1->game_screen != (TRIBE_Screen_Game *)0x0) {
        RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,2);
        TRIBE_Screen_Game::handleChatReceived(param_1->game_screen,param_3);
      }
    }
  }
switchD_00529abb_caseD_17ad:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00529edf
// Address: 00529edf
// XREFS: None
void FUN_00529edf(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00529ff4
// Address: 00529ff4
// XREFS: None
undefined4 __fastcall FUN_00529ff4(TRIBE_Game *param_1)
{
  if (param_1->_padding_ != 0) {
    TRIBE_Game::disconnect_multiplayer_game(param_1);
    param_1->_padding_ = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0052a023
// Address: 0052a023
// XREFS: None
undefined4 __fastcall FUN_0052a023(int *param_1)
{
  if (*(char *)(*(int *)(*(int *)(param_1[0xfd] + 0x40) + *(short *)(param_1[0xfd] + 0x7c) * 4) +
               0x80) == '\x01') {
    (**(code **)(*param_1 + 0x20))(0x47e,0x86bce0,0x100);
    return 0x86bce0;
  }
  (**(code **)(*param_1 + 0x20))(0x47f,0x86bce0,0x100);
  return 0x86bce0;
}

// --------------------------------------------------

// Function: FUN_0052a07d
// Address: 0052a07d
// XREFS: None
long __thiscall FUN_0052a07d(int param_1,uchar param_2,char **param_3)
{
  long lVar1;
  
  if (*(TRIBE_World **)(param_1 + 0x3f4) == (TRIBE_World *)0x0) {
    return 0;
  }
  lVar1 = TRIBE_World::get_achievement(*(TRIBE_World **)(param_1 + 0x3f4),param_2,param_3);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_0052a0a1
// Address: 0052a0a1
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
int __thiscall FUN_0052a0a1(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_c [4];
  int iStack_8;
  
  (**(code **)(*param_1 + 0x20))((param_2 + 0x1b7) * 10,auStack_c,10);
  iVar1 = atoi(&stack0xffffffe8);
  iStack_8 = 0;
  param_2 = param_2 * 10;
  do {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0x1521);
    iVar3 = iVar2 % iVar1;
    if (iVar1 + -1 < iVar2 % iVar1) {
      iVar3 = iVar1 + -1;
    }
  } while ((*(char *)((int)param_1 + iVar3 + param_2 + 0x1198) != '\0') &&
          (iStack_8 = iStack_8 + 1, iStack_8 < 0x14));
  iVar1 = iVar3;
  if (*(char *)((int)param_1 + param_2 + iVar3 + 0x1198) == '\x01') {
    iVar2 = 0;
    do {
      iVar1 = iVar2;
      if (*(char *)((int)param_1 + iVar2 + param_2 + 0x1198) == '\0') break;
      iVar2 = iVar2 + 1;
      iVar1 = iVar3;
    } while (iVar2 < 10);
  }
  *(undefined1 *)((int)param_1 + iVar1 + param_2 + 0x1198) = 1;
  return iVar1 + param_2 + -9;
}

// --------------------------------------------------

// Function: FUN_0052a16b
// Address: 0052a16b
// XREFS: None
void __fastcall FUN_0052a16b(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x1198);
  for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052a182
// Address: 0052a182
// XREFS: None
undefined4 __thiscall
FUN_0052a182(TRIBE_Game *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5)
{
  undefined4 uVar1;
  
  if (param_3 == 0x200) {
    SetCursor(0);
    return 0;
  }
  if ((param_3 != 0x201) && (param_3 != 0x204)) {
    uVar1 = CallWindowProcA(param_1->old_video_wnd_proc,param_2,param_3,param_4,param_5);
    return uVar1;
  }
  TRIBE_Game::stop_video(param_1,'\x01');
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052a1de
// Address: 0052a1de
// XREFS: None
void __thiscall
FUN_0052a1de(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  *(undefined4 *)(param_1 + 0xa24) = param_2;
  *(undefined4 *)(param_1 + 0xa28) = param_3;
  *(undefined4 *)(param_1 + 0xa2c) = param_4;
  *(undefined4 *)(param_1 + 0xa30) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_0052a20b
// Address: 0052a20b
// XREFS: None
void __fastcall FUN_0052a20b(TRIBE_Game *param_1)
{
  if (*(short *)(param_1->_padding_ + 0x8dc) == 1) {
    TRIBE_Game::SetClickTables
              (param_1,(MouseClickInfo *)&Tribe1btnMouseRightClickTable,
               Tribe1btnMouseRightClickTableSize,(MouseClickInfo *)&Tribe1btnMouseLeftClickTable,
               Tribe1btnMouseLeftClickTableSize);
    return;
  }
  TRIBE_Game::SetClickTables
            (param_1,(MouseClickInfo *)&Tribe2btnMouseRightClickTable,
             Tribe2btnMouseRightClickTableSize,(MouseClickInfo *)&Tribe2btnMouseLeftClickTable,
             Tribe2btnMouseLeftClickTableSize);
  return;
}

// --------------------------------------------------

// Function: FUN_0052a257
// Address: 0052a257
// XREFS: None
// [HELPER] s_640x480_16bit: "640x480 16bit"
// [HELPER] s_640x480_16bit_success: "640x480 16bit success"
// [HELPER] s_640x480_8bit: "640x480 8bit"
// [HELPER] s_640x480_8bit_success: "640x480 8bit success"
// [HELPER] s_8BITVIDEO: "8BITVIDEO"
// [HELPER] s_Blank_Screen: "Blank Screen"
// [HELPER] s_video_changed_res__d__double_siz: "video_changed_res=%d, double_size=%d"
undefined4 __fastcall FUN_0052a257(RGE_Base_Game *param_1)
{
  TDrawSystem *pTVar1;
  uchar uVar2;
  int iVar3;
  RGE_Font *pRVar4;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  
  if (param_1[1].input_disabled_window != (void *)0x0) {
    return 1;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Blank_Screen,0);
  RGE_Base_Game::mouse_off(param_1);
  pTVar1 = param_1->draw_system;
  *(undefined4 *)&param_1[1].font_num = 1;
  param_1[1].fonts = (RGE_Font *)0x0;
  param_1[1].work_dir[0] = '\0';
  param_1[1].work_dir[1] = '\0';
  param_1[1].work_dir[2] = '\0';
  param_1[1].work_dir[3] = '\0';
  *(void **)(param_1[1].work_dir + 0xc) = pTVar1->Pal;
  if (pTVar1->ScreenMode == '\x02') {
    SetCursor(0);
    SetClassLongA(param_1->prog_window,0xfffffff4,0);
    TMousePointer::Shutdown_Mouse(param_1->mouse_pointer);
    pTVar1 = param_1->draw_system;
    *(int *)(param_1[1].work_dir + 4) = pTVar1->ScreenWidth;
    *(int *)(param_1[1].work_dir + 8) = pTVar1->ScreenHeight;
    uVar2 = RGE_Base_Game::check_prog_argument(param_1,s_8BITVIDEO);
    if (uVar2 == '\0') {
      iVar3 = TDrawSystem::IsModeAvail(param_1->draw_system,0x280,0x1e0,0x10);
      if (iVar3 != 0) {
        TDebuggingLog::Log(this,(char *)L,s_640x480_16bit);
        pRVar4 = (RGE_Font *)TDrawSystem::SetDisplaySize(param_1->draw_system,0x280,0x1e0,0x10);
        param_1[1].fonts = pRVar4;
        if (pRVar4 != (RGE_Font *)0x0) {
          *(undefined4 *)&param_1[1].font_num = 1;
          param_1[1].work_dir[0] = '\x01';
          param_1[1].work_dir[1] = '\0';
          param_1[1].work_dir[2] = '\0';
          param_1[1].work_dir[3] = '\0';
          TDebuggingLog::Log(L,(char *)L,s_640x480_16bit_success);
        }
      }
      if ((param_1[1].fonts == (RGE_Font *)0x0) && (param_1->draw_system->ScreenWidth != 0x280)) {
        iVar3 = TDrawSystem::IsModeAvail(param_1->draw_system,0x280,0x1e0,8);
        if (iVar3 != 0) {
          TDebuggingLog::Log(this_00,(char *)L,s_640x480_8bit);
          pRVar4 = (RGE_Font *)TDrawSystem::SetDisplaySize(param_1->draw_system,0x280,0x1e0,8);
          param_1[1].fonts = pRVar4;
          if (pRVar4 != (RGE_Font *)0x0) {
            *(undefined4 *)&param_1[1].font_num = 1;
            TDebuggingLog::Log(this_01,(char *)L,s_640x480_8bit_success);
          }
        }
      }
    }
  }
  TDebuggingLog::Log(*(TDebuggingLog **)&param_1[1].font_num,(char *)L,
                     s_video_changed_res__d__double_siz,param_1[1].fonts,
                     *(TDebuggingLog **)&param_1[1].font_num);
  iVar3 = param_1->_padding_;
  (**(code **)(iVar3 + 0xc))(1);
  (**(code **)(iVar3 + 0xa4))();
  param_1[1].input_disabled_window = (void *)0x1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0052a422
// Address: 0052a422
// XREFS: None
void __fastcall FUN_0052a422(RGE_Base_Game *param_1)
{
  TDrawSystem *this;
  int iVar1;
  void *pvVar2;
  
  if (param_1[1].input_disabled_window != (void *)0x0) {
    if (param_1[1].fonts != (RGE_Font *)0x0) {
      TDrawSystem::SetDisplaySize
                (param_1->draw_system,*(long *)(param_1[1].work_dir + 4),
                 *(long *)(param_1[1].work_dir + 8),8);
      TDrawSystem::ClearPrimarySurface(param_1->draw_system);
      TDrawSystem::SetPalette(param_1->draw_system,*(void **)(param_1[1].work_dir + 0xc));
      this = param_1->draw_system;
      param_1[1].fonts = (RGE_Font *)0x0;
      TDrawSystem::CheckSurfaces(this);
      TDrawSystem::ClearRestored(param_1->draw_system);
      RGE_Base_Game::check_paint(param_1);
      restore_mouse_after_paint = 1;
    }
    TDrawSystem::ClearPrimarySurface(param_1->draw_system);
    TDrawSystem::SetPalette(param_1->draw_system,*(void **)(param_1[1].work_dir + 0xc));
    RGE_Base_Game::set_render_all(param_1);
    InvalidateRect(param_1->prog_window,0,1);
    iVar1 = param_1->_padding_;
    (**(code **)(iVar1 + 0xc))(2);
    (**(code **)(iVar1 + 0xa8))();
    pvVar2 = (void *)LoadCursorA(0,0x7f00);
    RGE_Base_Game::set_mouse_cursor(param_1,pvVar2);
    RGE_Base_Game::mouse_on(param_1);
    param_1[1].input_disabled_window = (void *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052a50c
// Address: 0052a50c
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
void __fastcall FUN_0052a50c(TRIBE_Game *param_1)
{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  iVar1 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)param_1);
  if (iVar1 == 0) {
    TCommunications_Handler::GameOver((TCommunications_Handler *)param_1->_padding_);
  }
  else {
    iVar1 = param_1->_padding_;
    if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
      TCommunications_Handler::SendIResignMsg((TCommunications_Handler *)param_1->_padding_);
      TCommunications_Handler::ShutdownGameMessages((TCommunications_Handler *)param_1->_padding_);
      iVar1 = TCommunications_Handler::CountWaitingMessages
                        ((TCommunications_Handler *)param_1->_padding_);
      if (0 < iVar1) {
        RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
        TRIBE_Game::show_status_message(param_1,0x4c0,(char *)0x0,-1);
        uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x15f8);
        uVar4 = uVar2;
        do {
          do {
            if ((param_1->_padding_ == 0) || (*(char *)(param_1->_padding_ + 0x1d) == '\x01'))
            goto LAB_0052a5fa;
            TCommunications_Handler::ShutdownGameMessages
                      ((TCommunications_Handler *)param_1->_padding_);
            uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x1601);
          } while (uVar3 - uVar4 < 500);
          iVar1 = TCommunications_Handler::CountWaitingMessages
                            ((TCommunications_Handler *)param_1->_padding_);
          if (iVar1 == 0) break;
          uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x1605);
        } while (uVar4 - uVar2 < 15000);
      }
LAB_0052a5fa:
      TCommunications_Handler::GameOver((TCommunications_Handler *)param_1->_padding_);
      TCommunications_Handler::UnlinkToLevel
                ((TCommunications_Handler *)param_1->_padding_,SERVICE_AVAILABLE);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052a627
// Address: 0052a627
// XREFS: None
void __thiscall FUN_0052a627(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc50);
  if (((iVar1 < 0) || (*(int *)(param_1 + 0xc28 + iVar1 * 4) != param_2)) ||
     (*(int *)(param_1 + 0xc3c + iVar1 * 4) != param_3)) {
    *(int *)(param_1 + 0xc50) = iVar1 + 1;
    if (4 < iVar1 + 1) {
      *(undefined4 *)(param_1 + 0xc50) = 0;
    }
    *(int *)(param_1 + 0xc28 + *(int *)(param_1 + 0xc50) * 4) = param_2;
    *(int *)(param_1 + 0xc3c + *(int *)(param_1 + 0xc50) * 4) = param_3;
  }
  *(undefined4 *)(param_1 + 0xc54) = *(undefined4 *)(param_1 + 0xc50);
  return;
}

// --------------------------------------------------

// Function: FUN_0052a695
// Address: 0052a695
// XREFS: None
void __fastcall FUN_0052a695(RGE_Base_Game *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  RGE_Player *this;
  float fVar4;
  float fVar5;
  
  iVar1 = *(int *)(param_1[1].work_dir + 0x48);
  if (iVar1 != -1) {
    iVar2 = *(int *)(param_1[1].work_dir + iVar1 * 4 + 0x1c);
    iVar3 = *(int *)(param_1[1].work_dir + iVar1 * 4 + 0x30);
    *(int *)(param_1[1].work_dir + 0x48) = iVar1 + -1;
    if (iVar1 + -1 < 0) {
      param_1[1].work_dir[0x48] = '\x04';
      param_1[1].work_dir[0x49] = '\0';
      param_1[1].work_dir[0x4a] = '\0';
      param_1[1].work_dir[0x4b] = '\0';
    }
    if ((*(int *)(param_1[1].work_dir + *(int *)(param_1[1].work_dir + 0x48) * 4 + 0x1c) == -1) ||
       (*(int *)(param_1[1].work_dir + *(int *)(param_1[1].work_dir + 0x48) * 4 + 0x30) == -1)) {
      *(undefined4 *)(param_1[1].work_dir + 0x48) = *(undefined4 *)(param_1[1].work_dir + 0x44);
    }
    fVar5 = (float)iVar3;
    fVar4 = (float)iVar2;
    this = RGE_Base_Game::get_player(param_1);
    RGE_Player::set_view_loc(this,fVar4,fVar5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052a721
// Address: 0052a721
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052a721(int param_1)
{
  float *pfVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  int iStack_4;
  
  iStack_4 = 0;
  pfVar1 = (float *)(param_1 + 0x8000);
  do {
    fVar2 = (float10)iStack_4 * (float10)_DAT_005772f0;
    fVar3 = (float10)fsin(fVar2);
    fVar4 = (float10)fcos(fVar2);
    pfVar1[-0x2000] = (float)fVar3;
    pfVar1[-0x1000] = (float)fVar4;
    if ((iStack_4 == 0x400) || (iStack_4 == 0xc00)) {
      *pfVar1 = 0.0;
    }
    else {
      fVar3 = (float10)fptan(fVar2);
      *pfVar1 = (float)fVar3;
    }
    if ((iStack_4 == 0) || (iStack_4 == 0x800)) {
      pfVar1[0x1000] = 0.0;
    }
    else {
      fVar2 = (float10)fpatan(fVar2,(float10)1);
      pfVar1[0x1000] = (float)fVar2;
    }
    iStack_4 = iStack_4 + 1;
    pfVar1 = pfVar1 + 1;
  } while (iStack_4 < 0x1000);
  pfVar1 = (float *)(param_1 + 0x10b40);
  iStack_4 = 0;
  do {
    fVar2 = (float10)iStack_4 * (float10)_DAT_005772f8;
    fVar3 = (float10)fsin(fVar2);
    fVar4 = (float10)fcos(fVar2);
    pfVar1[-0x2d0] = (float)fVar3;
    pfVar1[-0x168] = (float)fVar4;
    if ((iStack_4 == 0x5a) || (iStack_4 == 0x10e)) {
      *pfVar1 = 0.0;
    }
    else {
      fVar3 = (float10)fptan(fVar2);
      *pfVar1 = (float)fVar3;
    }
    if ((iStack_4 == 0) || (iStack_4 == 0xb4)) {
      pfVar1[0x168] = 0.0;
    }
    else {
      fVar2 = (float10)fpatan(fVar2,(float10)1);
      pfVar1[0x168] = (float)fVar2;
    }
    iStack_4 = iStack_4 + 1;
    pfVar1 = pfVar1 + 1;
  } while (iStack_4 < 0x168);
  return;
}

// --------------------------------------------------

// Function: FUN_0052a849
// Address: 0052a849
// XREFS: None
int FUN_0052a849(int param_1)
{
  param_1 = param_1 % 0x168;
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052a867
// Address: 0052a867
// XREFS: None
float10 __thiscall FUN_0052a867(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle(param_1,param_2);
  return (float10)param_1->sines[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a884
// Address: 0052a884
// XREFS: None
float10 __thiscall FUN_0052a884(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle(param_1,param_2);
  return (float10)param_1->cose[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a8a8
// Address: 0052a8a8
// XREFS: None
float10 __thiscall FUN_0052a8a8(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle(param_1,param_2);
  return (float10)param_1->tane[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a8c8
// Address: 0052a8c8
// XREFS: None
float10 __thiscall FUN_0052a8c8(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle(param_1,param_2);
  return (float10)param_1->atane[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a8e8
// Address: 0052a8e8
// XREFS: None
float10 __thiscall FUN_0052a8e8(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle360(param_1,param_2);
  return (float10)param_1->sine360[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a908
// Address: 0052a908
// XREFS: None
float10 __thiscall FUN_0052a908(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle360(param_1,param_2);
  return (float10)param_1->cose360[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a928
// Address: 0052a928
// XREFS: None
float10 __thiscall FUN_0052a928(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle360(param_1,param_2);
  return (float10)param_1->tane360[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a948
// Address: 0052a948
// XREFS: None
float10 __thiscall FUN_0052a948(TRIGONOMETRY *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TRIGONOMETRY::RestrictAngle360(param_1,param_2);
  return (float10)param_1->atane360[iVar1];
}

// --------------------------------------------------

// Function: FUN_0052a968
// Address: 0052a968
// XREFS: None
void FUN_0052a968(void)
{
  TRIGONOMETRY::TRIGONOMETRY(&trig);
  return;
}

// --------------------------------------------------

// Function: $E2
// Address: 0052a970
// XREFS: None
void _E2(void)
{
  TRIGONOMETRY::TRIGONOMETRY(&trig);
  return;
}

// --------------------------------------------------

// Function: FUN_0052a975
// Address: 0052a975
// XREFS: None
void FUN_0052a975(void)
{
  TRIGONOMETRY::TRIGONOMETRY(&trig);
  return;
}

// --------------------------------------------------

// Function: $E1
// Address: 0052a980
// XREFS: $E2
void _E1(void)
{
  TRIGONOMETRY::TRIGONOMETRY(&trig);
  return;
}

// --------------------------------------------------

// Function: FUN_0052a98a
// Address: 0052a98a
// XREFS: None
RGE_Scenario_Header * __thiscall FUN_0052a98a(RGE_Scenario_Header *param_1,T_Scenario *param_2)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561848;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Scenario_Header::RGE_Scenario_Header(param_1,(RGE_Scenario *)param_2);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Scenario_Header::_vftable_;
  iVar1 = T_Scenario::any_sp_victory(param_2);
  param_1[1]._padding_ = iVar1;
  iVar1 = RGE_Scenario::active_player_count((RGE_Scenario *)param_2);
  param_1[1].error_code = iVar1;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052a9ef
// Address: 0052a9ef
// XREFS: None
RGE_Scenario_Header * __thiscall FUN_0052a9ef(RGE_Scenario_Header *param_1,int param_2)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561868;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Scenario_Header::RGE_Scenario_Header(param_1,param_2);
  iVar1 = param_1->error_code;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Scenario_Header::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1].error_code = 0;
  if (iVar1 == 0) {
    rge_read_uncompressed(param_2,param_1 + 1,4);
    rge_read_uncompressed(param_2,&param_1[1].error_code,4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052aa6e
// Address: 0052aa6e
// XREFS: None
int __fastcall FUN_0052aa6e(RGE_Scenario_Header *param_1)
{
  long lVar1;
  
  lVar1 = RGE_Scenario_Header::get_size(param_1);
  return lVar1 + 8;
}

// --------------------------------------------------

// Function: FUN_0052aa79
// Address: 0052aa79
// XREFS: None
void __thiscall FUN_0052aa79(RGE_Scenario_Header *param_1,int param_2)
{
  RGE_Scenario_Header::save(param_1,param_2);
  rge_write_uncompressed(param_2,param_1 + 1,4);
  rge_write_uncompressed(param_2,&param_1[1].error_code,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0052aab1
// Address: 0052aab1
// XREFS: None
T_Scenario * __thiscall FUN_0052aab1(T_Scenario *param_1,RGE_Game_World *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561888;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Scenario::RGE_Scenario((RGE_Scenario *)param_1,param_2);
  uStack_4 = 0;
  param_1->_padding_ = (int)&T_Scenario::_vftable_;
  T_Scenario::InitializePlayerValues(param_1);
  T_Scenario::InitializeVictoryValues(param_1);
  T_Scenario::InitializeFriendlinessValues(param_1);
  param_1->mp_victory_type = 0;
  param_1->victory_score = 900;
  param_1->victory_time = 9000;
  param_1->victory_all_flag = 0;
  param_1->which_player = 0;
  param_1->ScenarioOptions[0] = 0;
  param_1->ScenarioOptions[1] = 0;
  param_1->ScenarioOptions[2] = 0;
  T_Scenario::ClearDisabledTechnologies(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052ab5f
// Address: 0052ab5f
// XREFS: None
T_Scenario * __thiscall FUN_0052ab5f(T_Scenario *param_1,byte param_2)
{
  T_Scenario::~T_Scenario(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052ab85
// Address: 0052ab85
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

T_Scenario * __thiscall FUN_0052ab85(T_Scenario *param_1,int param_2,RGE_Game_World *param_3)
{
  float fVar1;
  int iVar2;
  void *pvVar3;
  Player_Start_Info *pPVar4;
  int *piVar5;
  SP_Victory_Info (*paSVar6) [12];
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005618a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Scenario::RGE_Scenario((RGE_Scenario *)param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&T_Scenario::_vftable_;
  param_3 = (RGE_Game_World *)0x0;
  T_Scenario::InitializeVictoryValues(param_1);
  T_Scenario::InitializeFriendlinessValues(param_1);
  T_Scenario::ClearDisabledTechnologies(param_1);
  fVar1 = _DAT_00577318;
  param_1->mp_victory_type = 0;
  param_1->victory_score = 900;
  param_1->victory_time = 9000;
  param_1->victory_all_flag = 0;
  param_1->which_player = 0;
  if ((float)param_1->_padding_ <= fVar1) {
    pvVar3 = (void *)((int)&param_1->_padding_ + 1);
    iVar7 = 0x10;
    do {
      rge_read(param_2,pvVar3,0x100);
      pvVar3 = (void *)((int)pvVar3 + 0x100);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if ((float)param_1->_padding_ <= _DAT_00577318) {
    piVar5 = &param_1->_padding_;
    pPVar4 = param_1->player_info;
    param_2 = 0x10;
    do {
      rge_read(iVar2,piVar5 + 0x20,4);
      rge_read(iVar2,pPVar4,0x10);
      rge_read(iVar2,piVar5,4);
      rge_read(iVar2,piVar5 + 0x10,4);
      rge_read(iVar2,piVar5 + -0x10,4);
      pPVar4 = pPVar4 + 1;
      piVar5 = piVar5 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  else {
    pPVar4 = param_1->player_info;
    iVar7 = 0x10;
    do {
      rge_read(param_2,pPVar4,0x10);
      pPVar4 = pPVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (_DAT_0057731c < (float)param_1->_padding_) {
    rge_read(iVar2,&param_3,4);
  }
  rge_read(iVar2,&param_1->victory,0x18);
  rge_read(iVar2,&param_1->victory_all_flag,4);
  if ((float)param_1->_padding_ < _DAT_00577318) {
    param_1->mp_victory_type = 4;
    param_1->victory_score = 900;
    param_1->victory_time = 9000;
  }
  else {
    rge_read(iVar2,&param_1->mp_victory_type,4);
    rge_read(iVar2,&param_1->victory_score,4);
    rge_read(iVar2,&param_1->victory_time,4);
  }
  rge_read(iVar2,param_1->Opponent,0x400);
  paSVar6 = param_1->sp_victory;
  iVar7 = 0x10;
  do {
    rge_read(iVar2,paSVar6,0x2d0);
    paSVar6 = paSVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (_DAT_0057731c < (float)param_1->_padding_) {
    rge_read(iVar2,&param_3,4);
  }
  if (param_1->_padding_ == 0x3f8147ae) {
    iVar7 = 0x10;
    do {
      rge_read(iVar2,param_1->AlliedVictory,0x40);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (_DAT_0057731c <= (float)param_1->_padding_) {
    rge_read(iVar2,param_1->AlliedVictory,0x40);
  }
  if (_DAT_00577320 < (float)param_1->_padding_) {
    rge_read(iVar2,param_1->DisabledTechnology,0x500);
  }
  if (_DAT_00577324 < (float)param_1->_padding_) {
    if (_DAT_00577328 <= (float)param_1->_padding_) {
      rge_read(iVar2,param_1->ScenarioOptions,0xc);
    }
    else {
      rge_read(iVar2,param_1->ScenarioOptions,4);
      param_1->ScenarioOptions[1] = 0;
      param_1->ScenarioOptions[2] = 0;
    }
  }
  if (_DAT_0057732c < (float)param_1->_padding_) {
    rge_read(iVar2,param_1->PlayerAge,0x40);
  }
  if (_DAT_0057731c < (float)param_1->_padding_) {
    rge_read(iVar2,&param_3,4);
  }
  (param_1->victory).MP_Conquest = (uint)(byte)param_1->_padding_;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052af1e
// Address: 0052af1e
// XREFS: None
void __thiscall FUN_0052af1e(T_Scenario *param_1,int param_2)
{
  Player_Start_Info *pPVar1;
  SP_Victory_Info (*paSVar2) [12];
  int iVar3;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffff9d;
  T_Scenario::WriteDisabledTechnologiesToMainSystem(param_1);
  RGE_Scenario::save((RGE_Scenario *)param_1,param_2);
  pPVar1 = param_1->player_info;
  iVar3 = 0x10;
  do {
    rge_write(param_2,pPVar1,0x10);
    pPVar1 = pPVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  rge_write(param_2,&uStack_4,4);
  rge_write(param_2,&param_1->victory,0x18);
  rge_write(param_2,&param_1->victory_all_flag,4);
  rge_write(param_2,&param_1->mp_victory_type,4);
  rge_write(param_2,&param_1->victory_score,4);
  rge_write(param_2,&param_1->victory_time,4);
  rge_write(param_2,param_1->Opponent,0x400);
  paSVar2 = param_1->sp_victory;
  iVar3 = 0x10;
  do {
    rge_write(param_2,paSVar2,0x2d0);
    paSVar2 = paSVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  rge_write(param_2,&uStack_4,4);
  rge_write(param_2,param_1->AlliedVictory,0x40);
  rge_write(param_2,param_1->DisabledTechnology,0x500);
  rge_write(param_2,param_1->ScenarioOptions,0xc);
  rge_write(param_2,param_1->PlayerAge,0x40);
  rge_write(param_2,&uStack_4,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0052b072
// Address: 0052b072
// XREFS: None
void __fastcall FUN_0052b072(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar1 = (undefined4 *)(param_1 + 0x18cc);
  puVar2 = (undefined4 *)(param_1 + 0x1998);
  do {
    iVar3 = iVar3 + 1;
    puVar2[-2] = 0;
    puVar2[-1] = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar1[0x20] = 0;
    puVar2[-2] = 0;
    puVar2[-1] = 200;
    *puVar2 = 200;
    puVar2[1] = 0x96;
    *puVar1 = 0;
    puVar1[0x10] = iVar3;
    puVar1[-0x10] = 4;
    puVar1[0xcb7] = 0;
    puVar1[0xe0d] = 0;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 0x10);
  *(undefined4 *)(param_1 + 0x18cc) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b0fb
// Address: 0052b0fb
// XREFS: None
void __fastcall FUN_0052b0fb(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x4bf4);
  for (iVar1 = 0x140; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 1;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b115
// Address: 0052b115
// XREFS: None
void __fastcall FUN_0052b115(RGE_Scenario *param_1)
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar5 = 0;
  do {
    uVar7 = 0xffffffff;
    uVar6 = 4;
    iVar1 = param_1->world->players[iVar5]->_padding_;
    pcVar2 = RGE_Scenario::Get_player_AI(param_1,iVar5,1);
    pcVar3 = RGE_Scenario::Get_CityPlan(param_1,iVar5,1);
    pcVar4 = RGE_Scenario::Get_BuildList(param_1,iVar5,1);
    (**(code **)(iVar1 + 0x2c))(pcVar4,pcVar3,pcVar2,uVar6,uVar7);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_0052b16d
// Address: 0052b16d
// XREFS: None
void __thiscall FUN_0052b16d(int param_1,int param_2)
{
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (1 < param_2) {
    param_2 = 1;
  }
  *(int *)(param_1 + 0x4be8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b18d
// Address: 0052b18d
// XREFS: None
undefined4 __fastcall FUN_0052b18d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x4be8);
}

// --------------------------------------------------

// Function: FUN_0052b197
// Address: 0052b197
// XREFS: None
void __thiscall FUN_0052b197(int param_1,int param_2)
{
  *(int *)(param_1 + 0x5140) = param_2;
  if (param_2 != 4) {
    *(undefined1 *)(param_1 + 0xc) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b1b6
// Address: 0052b1b6
// XREFS: None
undefined4 __fastcall FUN_0052b1b6(int param_1)
{
  return *(undefined4 *)(param_1 + 0x5140);
}

// --------------------------------------------------

// Function: FUN_0052b1c7
// Address: 0052b1c7
// XREFS: None
void __thiscall FUN_0052b1c7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x5144) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b1dd
// Address: 0052b1dd
// XREFS: None
undefined4 __fastcall FUN_0052b1dd(int param_1)
{
  return *(undefined4 *)(param_1 + 0x5144);
}

// --------------------------------------------------

// Function: FUN_0052b1e7
// Address: 0052b1e7
// XREFS: None
void __thiscall FUN_0052b1e7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x5148) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b1fd
// Address: 0052b1fd
// XREFS: None
undefined4 __fastcall FUN_0052b1fd(int param_1)
{
  return *(undefined4 *)(param_1 + 0x5148);
}

// --------------------------------------------------

// Function: FUN_0052b207
// Address: 0052b207
// XREFS: None
void __thiscall FUN_0052b207(int param_1,int param_2)
{
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (0x10 < param_2) {
    param_2 = 0xf;
  }
  *(int *)(param_1 + 0x4bf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b22d
// Address: 0052b22d
// XREFS: None
undefined4 __fastcall FUN_0052b22d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x4bf0);
}

// --------------------------------------------------

// Function: FUN_0052b237
// Address: 0052b237
// XREFS: None
void __fastcall FUN_0052b237(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0x1a90) = 1;
  *(undefined4 *)(param_1 + 0x1a94) = 0;
  *(undefined4 *)(param_1 + 0x1a98) = 0;
  *(undefined4 *)(param_1 + 0x1a9c) = 0;
  *(undefined4 *)(param_1 + 0x1aa0) = 0;
  *(undefined4 *)(param_1 + 0x1aa4) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x1aa8);
  for (iVar1 = 0xb40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b27a
// Address: 0052b27a
// XREFS: None
void __thiscall FUN_0052b27a(int param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x1aa8 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c);
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b2af
// Address: 0052b2af
// XREFS: None
void __fastcall FUN_0052b2af(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x47a8);
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 3;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b2c5
// Address: 0052b2c5
// XREFS: None
void __thiscall FUN_0052b2c5(int param_1,int param_2,int param_3,int param_4)
{
  if ((((param_4 == 1) || (param_4 == 3)) || (param_4 == 0)) &&
     (((-1 < param_2 && (param_2 < 0x10)) && ((-1 < param_3 && (param_3 < 0x10)))))) {
    *(int *)(param_1 + 0x47a8 + (param_2 * 0x10 + param_3) * 4) = param_4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b30d
// Address: 0052b30d
// XREFS: None
undefined4 __thiscall FUN_0052b30d(int param_1,int param_2,int param_3)
{
  if ((((-1 < param_2) && (param_2 < 0x10)) && (-1 < param_3)) && (param_3 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x47a8 + param_2 * 0x40 + param_3 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0052b35f
// Address: 0052b35f
// XREFS: None
void __thiscall FUN_0052b35f(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    *(undefined4 *)(param_2 * 0x10 + 0x1994 + param_1) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b37e
// Address: 0052b37e
// XREFS: None
void __thiscall FUN_0052b37e(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    *(undefined4 *)(param_2 * 0x10 + 0x1998 + param_1) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b39e
// Address: 0052b39e
// XREFS: None
void __thiscall FUN_0052b39e(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    *(undefined4 *)(param_2 * 0x10 + 0x199c + param_1) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b3be
// Address: 0052b3be
// XREFS: None
void __thiscall FUN_0052b3be(int param_1,int param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  
  if ((-1 < param_2) && (param_2 < 0x10)) {
    puVar1 = (undefined4 *)((param_2 + 0x199) * 0x10 + param_1);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b3f4
// Address: 0052b3f4
// XREFS: None
void __thiscall FUN_0052b3f4(RGE_Scenario *param_1,int param_2)
{
  RGE_Scenario *pRVar1;
  
  if (param_2 != 0) {
    pRVar1 = param_1 + 1;
    pRVar1->player_name[0].Name[0xf3] = '\x01';
    pRVar1->player_name[0].Name[0xf4] = '\0';
    pRVar1->player_name[0].Name[0xf5] = '\0';
    pRVar1->player_name[0].Name[0xf6] = '\0';
    RGE_Scenario::Set_conquest_victory(param_1,'\x01');
    return;
  }
  pRVar1 = param_1 + 1;
  pRVar1->player_name[0].Name[0xf3] = '\0';
  pRVar1->player_name[0].Name[0xf4] = '\0';
  pRVar1->player_name[0].Name[0xf5] = '\0';
  pRVar1->player_name[0].Name[0xf6] = '\0';
  RGE_Scenario::Set_conquest_victory(param_1,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_0052b43d
// Address: 0052b43d
// XREFS: None
void __thiscall FUN_0052b43d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1a98) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b44d
// Address: 0052b44d
// XREFS: None
void __thiscall FUN_0052b44d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1a9c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b45d
// Address: 0052b45d
// XREFS: None
void __thiscall FUN_0052b45d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1aa0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b46d
// Address: 0052b46d
// XREFS: None
void __thiscall FUN_0052b46d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1aa4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b47d
// Address: 0052b47d
// XREFS: None
void __thiscall
FUN_0052b47d(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)
{
  *(undefined4 *)(param_1 + (param_2 + 0x72 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x1abc + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_4;
  *(undefined4 *)(param_1 + 0x1ac0 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_5;
  *(undefined4 *)(param_1 + 0x1ac4 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_6;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b4f8
// Address: 0052b4f8
// XREFS: None
void __thiscall FUN_0052b4f8(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x1aa8 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b524
// Address: 0052b524
// XREFS: None
void __thiscall FUN_0052b524(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x1ab0 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b554
// Address: 0052b554
// XREFS: None
void __thiscall FUN_0052b554(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x1aac + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b584
// Address: 0052b584
// XREFS: None
void __thiscall FUN_0052b584(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x1ad0 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b5b4
// Address: 0052b5b4
// XREFS: None
void __thiscall FUN_0052b5b4(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x1ac8 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b5e4
// Address: 0052b5e4
// XREFS: None
void __thiscall FUN_0052b5e4(T_Scenario *param_1,int param_2,RGE_Static_Object *param_3)
{
  int iVar1;
  
  if (param_3 != (RGE_Static_Object *)0x0) {
    iVar1 = T_Scenario::get_object_ID(param_1,param_3);
    param_1->sp_victory[param_1->which_player][param_2].obj_ID = iVar1 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b625
// Address: 0052b625
// XREFS: None
void __thiscall FUN_0052b625(T_Scenario *param_1,int param_2,RGE_Static_Object *param_3)
{
  int iVar1;
  
  if (param_3 != (RGE_Static_Object *)0x0) {
    iVar1 = T_Scenario::get_object_ID(param_1,param_3);
    param_1->sp_victory[param_1->which_player][param_2].dest_obj_ID = iVar1 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052b665
// Address: 0052b665
// XREFS: None
void __thiscall FUN_0052b665(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x1acc + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b694
// Address: 0052b694
// XREFS: None
void __thiscall FUN_0052b694(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x4ba8 + param_2 * 4) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b6b2
// Address: 0052b6b2
// XREFS: None
void __thiscall FUN_0052b6b2(int param_1,int param_2,int param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x4bf4 + (param_3 + param_2 * 0x14) * 4) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b6dc
// Address: 0052b6dc
// XREFS: None
void __thiscall FUN_0052b6dc(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x50f4 + param_2 * 4) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b6f2
// Address: 0052b6f2
// XREFS: None
void __thiscall FUN_0052b6f2(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x5100 + param_2 * 4) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b712
// Address: 0052b712
// XREFS: None
undefined4 __thiscall FUN_0052b712(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x1990 + param_2 * 0x10);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052b73f
// Address: 0052b73f
// XREFS: None
undefined4 __thiscall FUN_0052b73f(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x1994 + param_2 * 0x10);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052b75f
// Address: 0052b75f
// XREFS: None
undefined4 __thiscall FUN_0052b75f(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x1998 + param_2 * 0x10);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052b77f
// Address: 0052b77f
// XREFS: None
undefined4 __thiscall FUN_0052b77f(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x199c + param_2 * 0x10);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052b79f
// Address: 0052b79f
// XREFS: None
int __thiscall FUN_0052b79f(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return (param_2 + 0x199) * 0x10 + param_1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052b7bf
// Address: 0052b7bf
// XREFS: None
undefined4 __fastcall FUN_0052b7bf(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1a90);
}

// --------------------------------------------------

// Function: FUN_0052b7c7
// Address: 0052b7c7
// XREFS: None
undefined4 __fastcall FUN_0052b7c7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1a94);
}

// --------------------------------------------------

// Function: FUN_0052b7d7
// Address: 0052b7d7
// XREFS: None
undefined4 __fastcall FUN_0052b7d7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1a98);
}

// --------------------------------------------------

// Function: FUN_0052b7e7
// Address: 0052b7e7
// XREFS: None
undefined4 __fastcall FUN_0052b7e7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1a9c);
}

// --------------------------------------------------

// Function: FUN_0052b7f7
// Address: 0052b7f7
// XREFS: None
undefined4 __fastcall FUN_0052b7f7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1aa0);
}

// --------------------------------------------------

// Function: FUN_0052b807
// Address: 0052b807
// XREFS: None
undefined4 __fastcall FUN_0052b807(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1aa4);
}

// --------------------------------------------------

// Function: FUN_0052b817
// Address: 0052b817
// XREFS: None
void __thiscall
FUN_0052b817(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6)
{
  *param_3 = *(undefined4 *)(param_1 + (param_2 + 0x72 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c);
  *param_4 = *(undefined4 *)(param_1 + 0x1abc + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c)
  ;
  *param_5 = *(undefined4 *)(param_1 + 0x1ac0 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c)
  ;
  *param_6 = *(undefined4 *)(param_1 + 0x1ac4 + (param_2 + *(int *)(param_1 + 0x4bf0) * 0xc) * 0x3c)
  ;
  return;
}

// --------------------------------------------------

// Function: FUN_0052b8a2
// Address: 0052b8a2
// XREFS: None
undefined4 __thiscall FUN_0052b8a2(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x1aa8 + *(int *)(param_1 + 0x4bf0) * 0x2d0 + param_2 * 0x3c);
}

// --------------------------------------------------

// Function: FUN_0052b8d7
// Address: 0052b8d7
// XREFS: None
undefined4 __thiscall FUN_0052b8d7(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + *(int *)(param_1 + 0x4bf0) * 0x2d0 + 0x1ab0 + param_2 * 0x3c);
}

// --------------------------------------------------

// Function: FUN_0052b908
// Address: 0052b908
// XREFS: None
undefined4 __thiscall FUN_0052b908(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + *(int *)(param_1 + 0x4bf0) * 0x2d0 + 0x1aac + param_2 * 0x3c);
}

// --------------------------------------------------

// Function: FUN_0052b938
// Address: 0052b938
// XREFS: None
undefined4 __thiscall FUN_0052b938(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + *(int *)(param_1 + 0x4bf0) * 0x2d0 + 0x1ad0 + param_2 * 0x3c);
}

// --------------------------------------------------

// Function: FUN_0052b968
// Address: 0052b968
// XREFS: None
undefined4 __thiscall FUN_0052b968(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + *(int *)(param_1 + 0x4bf0) * 0x2d0 + 0x1acc + param_2 * 0x3c);
}

// --------------------------------------------------

// Function: FUN_0052b998
// Address: 0052b998
// XREFS: None
undefined4 __thiscall FUN_0052b998(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + *(int *)(param_1 + 0x4bf0) * 0x2d0 + 0x1ac8 + param_2 * 0x3c);
}

// --------------------------------------------------

// Function: FUN_0052b9c8
// Address: 0052b9c8
// XREFS: None
void __thiscall FUN_0052b9c8(undefined4 *param_1,int param_2)
{
  (**(code **)*param_1)(param_1[(param_2 + param_1[0x12fc] * 0xc) * 0xf + 0x6b6]);
  return;
}

// --------------------------------------------------

// Function: FUN_0052b9f7
// Address: 0052b9f7
// XREFS: None
void __thiscall FUN_0052b9f7(undefined4 *param_1,int param_2)
{
  (**(code **)*param_1)(param_1[(param_2 + param_1[0x12fc] * 0xc) * 0xf + 0x6b5]);
  return;
}

// --------------------------------------------------

// Function: FUN_0052ba27
// Address: 0052ba27
// XREFS: None
undefined4 __thiscall FUN_0052ba27(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x4ba8 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_0052ba3e
// Address: 0052ba3e
// XREFS: None
undefined4 __thiscall FUN_0052ba3e(int param_1,int param_2,int param_3)
{
  return *(undefined4 *)(param_1 + 0x4bf4 + param_2 * 0x50 + param_3 * 4);
}

// --------------------------------------------------

// Function: FUN_0052ba5b
// Address: 0052ba5b
// XREFS: None
undefined4 __thiscall FUN_0052ba5b(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x50f4 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_0052ba6e
// Address: 0052ba6e
// XREFS: None
undefined4 __thiscall FUN_0052ba6e(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x5100 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_0052ba7e
// Address: 0052ba7e
// XREFS: None
void __fastcall FUN_0052ba7e(int param_1)
{
  RGE_Timeline::update(*(RGE_Timeline **)(param_1 + 4));
  return;
}

// --------------------------------------------------

// Function: FUN_0052ba88
// Address: 0052ba88
// XREFS: None
void __fastcall FUN_0052ba88(T_Scenario *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piStack_8;
  
  iVar3 = 1;
  if (1 < *(short *)(param_1->_padding_ + 0x3c)) {
    piStack_8 = param_1->AlliedVictory;
    iVar4 = 0x11e9;
    do {
      iVar2 = iVar3 + -1;
      iVar1 = T_Scenario::Get_player_Food(param_1,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(param_1->_padding_ + 0x40) + iVar3 * 4),0,(float)iVar1);
      iVar1 = T_Scenario::Get_player_Stone(param_1,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(param_1->_padding_ + 0x40) + iVar3 * 4),2,(float)iVar1);
      iVar1 = T_Scenario::Get_player_Gold(param_1,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(param_1->_padding_ + 0x40) + iVar3 * 4),3,(float)iVar1);
      iVar2 = T_Scenario::Get_player_Wood(param_1,iVar2);
      RGE_Player::new_attribute_num
                (*(RGE_Player **)(*(int *)(param_1->_padding_ + 0x40) + iVar3 * 4),1,(float)iVar2);
      iVar2 = param_1->_padding_;
      iVar1 = 1;
      if (1 < *(short *)(iVar2 + 0x3c)) {
        do {
          if (iVar1 != iVar3) {
            RGE_Player::set_relation
                      (*(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar3 * 4),iVar1,
                       (uchar)(&param_1->_padding_)[iVar1 + iVar4]);
          }
          iVar2 = param_1->_padding_;
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(short *)(iVar2 + 0x3c));
      }
      RGE_Player::set_allied_victory
                (*(RGE_Player **)(*(int *)(param_1->_padding_ + 0x40) + iVar3 * 4),(uchar)*piStack_8
                );
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
      piStack_8 = piStack_8 + 1;
    } while (iVar3 < *(short *)(param_1->_padding_ + 0x3c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052bbb5
// Address: 0052bbb5
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0052bbb5(T_Scenario *param_1,int param_2)
{
  int iVar1;
  RGE_Victory_Conditions *pRVar2;
  code *pcVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  undefined4 uVar6;
  RGE_Static_Object *pRVar7;
  int unaff_EBX;
  int iVar8;
  int *piVar9;
  int unaff_retaddr;
  float fVar10;
  float fVar11;
  float fVar12;
  uchar uVar13;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_2 != 0) {
    T_Scenario::SaveAttributesIntoPlayers(param_1);
  }
  iVar5 = param_1->_padding_;
  iVar8 = 1;
  if (1 < *(short *)(iVar5 + 0x3c)) {
    do {
      RGE_Victory_Conditions::destroy_all
                (*(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + iVar8 * 4) + 0x34));
      iVar5 = param_1->_padding_;
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(short *)(iVar5 + 0x3c));
  }
  if (param_1->mp_victory_type == 4) {
    if (param_1->victory_all_flag != 0) {
      iVar5 = param_1->_padding_;
      iVar8 = 1;
      if (1 < *(short *)(iVar5 + 0x3c)) {
        do {
          iVar1 = (param_1->victory).MP_Exploration;
          pRVar2 = *(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + iVar8 * 4) + 0x34)
          ;
          if (iVar1 != 0) {
            RGE_Victory_Conditions::add_explore(pRVar2,'\b',iVar1,'\x01');
          }
          iVar5 = (param_1->victory).MP_Ruins;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',0xe,iVar5,'\x01');
          }
          iVar5 = (param_1->victory).MP_Artifacts;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',7,iVar5,'\x01');
          }
          iVar5 = (param_1->victory).MP_Discoveries;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',0xd,iVar5,'\0');
          }
          iVar5 = (param_1->victory).MP_Gold;
          if (iVar5 != 0) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\b',3,iVar5,'\x01');
          }
          iVar5 = param_1->_padding_;
          iVar8 = iVar8 + 1;
        } while (iVar8 < *(short *)(iVar5 + 0x3c));
      }
      if (param_1->victory_all_flag != 0) goto LAB_0052bd5d;
    }
    iVar5 = param_1->_padding_;
    iVar8 = 1;
    if (1 < *(short *)(iVar5 + 0x3c)) {
      do {
        iVar1 = (param_1->victory).MP_Exploration;
        pRVar2 = *(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + iVar8 * 4) + 0x34);
        if (iVar1 != 0) {
          RGE_Victory_Conditions::add_explore(pRVar2,'\b',iVar1,'\x01');
        }
        iVar5 = (param_1->victory).MP_Ruins;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\t',0xe,iVar5,'\x01');
        }
        iVar5 = (param_1->victory).MP_Artifacts;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\n',7,iVar5,'\x01');
        }
        iVar5 = (param_1->victory).MP_Discoveries;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\v',0xd,iVar5,'\0');
        }
        iVar5 = (param_1->victory).MP_Gold;
        if (iVar5 != 0) {
          RGE_Victory_Conditions::add_attributes(pRVar2,'\f',3,iVar5,'\x01');
        }
        iVar5 = param_1->_padding_;
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(short *)(iVar5 + 0x3c));
    }
  }
LAB_0052bd5d:
  iVar5 = param_1->_padding_;
  iStack_8 = 0;
  if (*(short *)(iVar5 + 0x3c) != 1 && -1 < *(short *)(iVar5 + 0x3c) + -1) {
    param_2 = 0x72;
    iStack_c = 4;
    piVar9 = &param_1->sp_victory[0][0].AttribType;
    do {
      pRVar2 = *(RGE_Victory_Conditions **)(*(int *)(*(int *)(iVar5 + 0x40) + iStack_c) + 0x34);
      iStack_10 = 0;
      do {
        iVar5 = piVar9[-2];
        if (iVar5 != 0) {
          if (iVar5 == 4) {
            iVar5 = *piVar9;
            if (iVar5 == 6) {
              RGE_Victory_Conditions::add_explore(pRVar2,'\x01',piVar9[-1],'\x01');
            }
            else if (iVar5 == 4) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',0xb,piVar9[-1],'\0');
            }
            else if (iVar5 == 3) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',0,piVar9[-1],'\0');
            }
            else if (iVar5 == 2) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',2,piVar9[-1],'\0');
            }
            else if (iVar5 == 1) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',1,piVar9[-1],'\0');
            }
            else if (iVar5 == 0) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',3,piVar9[-1],'\0');
            }
            else if (iVar5 == 5) {
              RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',6,piVar9[-1],'\0');
            }
          }
          else if (iVar5 == 6) {
            RGE_Victory_Conditions::add_attributes(pRVar2,'\x01',*piVar9,piVar9[-1],'\0');
          }
          else if (iVar5 == 5) {
            uVar13 = '\x01';
            pRVar4 = (RGE_Static_Object *)(**(code **)param_1->_padding_)(piVar9[1]);
            RGE_Victory_Conditions::add_capture(pRVar2,'\x01',pRVar4,uVar13);
          }
          else if (iVar5 == 3) {
            pRVar4 = (RGE_Static_Object *)piVar9[2];
            pcVar3 = *(code **)param_1->_padding_;
            iVar5 = (*pcVar3)();
            if (iVar5 == 0) {
              fVar12 = (float)piVar9[-3];
              fVar11 = (float)piVar9[-4];
              fVar10 = (float)piVar9[-5];
              pRVar7 = (RGE_Static_Object *)
                       (*pcVar3)(piVar9[1],(&param_1->_padding_)[(unaff_retaddr + unaff_EBX) * 0xf])
              ;
              RGE_Victory_Conditions::add_bring
                        (pRVar2,'\x01',pRVar7,fVar10,fVar11,fVar12,(float)pRVar4);
            }
            else {
              uVar6 = (*pcVar3)(piVar9[2]);
              pRVar7 = (RGE_Static_Object *)(*pcVar3)(piVar9[1],uVar6);
              RGE_Victory_Conditions::add_bring(pRVar2,'\x01',pRVar7,pRVar4);
            }
          }
          else if (iVar5 == 2) {
            if ((float)piVar9[-4] <= (float)_DAT_00577330) {
              RGE_Victory_Conditions::add_create
                        (pRVar2,'\x01',((SP_Victory_Info *)(piVar9 + -10))->ObjType,piVar9[-1],'\0')
              ;
            }
            else {
              RGE_Victory_Conditions::add_create
                        (pRVar2,'\x01',((SP_Victory_Info *)(piVar9 + -10))->ObjType,piVar9[-1],
                         (float)(&param_1->_padding_)[(param_2 + iStack_10) * 0xf],(float)piVar9[-5]
                         ,(float)piVar9[-4],(float)piVar9[-3],'\0');
            }
          }
          else if (iVar5 == 7) {
            TRIBE_Victory_Conditions::add_tech((TRIBE_Victory_Conditions *)pRVar2,'\x01',*piVar9);
          }
          else if (iVar5 == 1) {
            iVar5 = ((SP_Victory_Info *)(piVar9 + -10))->ObjType;
            if ((iVar5 == 0) || (piVar9[-9] == 0)) {
              iVar8 = piVar9[-8];
              if (iVar8 == 0) {
LAB_0052bff1:
                pcVar3 = *(code **)param_1->_padding_;
                iVar5 = (*pcVar3)(piVar9[1]);
                if (iVar5 != 0) {
                  pRVar4 = (RGE_Static_Object *)(*pcVar3)(piVar9[1]);
                  RGE_Victory_Conditions::add_destroy(pRVar2,'\x01',pRVar4);
                }
              }
              else if (iVar5 == 0) {
                if (iVar8 == 0) goto LAB_0052bff1;
                RGE_Victory_Conditions::add_destroy
                          (pRVar2,'\x01',
                           *(RGE_Player **)(*(int *)(param_1->_padding_ + 0x40) + iVar8 * 4));
              }
              else {
                RGE_Victory_Conditions::add_destroy
                          (pRVar2,'\x01',iVar5,piVar9[-1],
                           *(RGE_Player **)(*(int *)(param_1->_padding_ + 0x40) + iVar8 * 4));
              }
            }
            else {
              RGE_Victory_Conditions::add_destroy(pRVar2,'\x01',iVar5,(RGE_Player *)0x0);
            }
          }
        }
        piVar9 = piVar9 + 0xf;
        iStack_10 = iStack_10 + 1;
      } while (iStack_10 < 0xc);
      param_2 = param_2 + 0xc;
      iVar5 = param_1->_padding_;
      iStack_c = iStack_c + 4;
      iStack_8 = iStack_8 + 1;
    } while (iStack_8 < *(short *)(iVar5 + 0x3c) + -1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052c061
// Address: 0052c061
// XREFS: None
void FUN_0052c061(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0052c071
// Address: 0052c071
// XREFS: None
RGE_Static_Object * __thiscall FUN_0052c071(int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)0x0;
  if (0 < param_2) {
    pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 8),param_2 + -1);
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: FUN_0052c097
// Address: 0052c097
// XREFS: None
undefined4 FUN_0052c097(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_0052c0aa
// Address: 0052c0aa
// XREFS: None
void __fastcall FUN_0052c0aa(int param_1)
{
  TRIBE_Player *this;
  int iVar1;
  int iVar2;
  uchar *puVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  if ((iVar1 != 0) && (iVar2 = 1, 1 < *(short *)(iVar1 + 0x3c))) {
    puVar3 = (uchar *)(param_1 + 0x4bf8);
    do {
      this = *(TRIBE_Player **)(*(int *)(iVar1 + 0x40) + iVar2 * 4);
      if (*(int *)(param_1 + 0x50f4) != 0) {
        (**(code **)(**(int **)(iVar1 + 0x4c) + 8))(100,this);
      }
      TRIBE_Player::tech_abling(this,0x58,puVar3[-4]);
      TRIBE_Player::tech_abling(this,0x59,*puVar3);
      TRIBE_Player::tech_abling(this,0x5a,puVar3[4]);
      TRIBE_Player::tech_abling(this,0x5b,puVar3[8]);
      TRIBE_Player::tech_abling(this,0x5e,puVar3[0xc]);
      TRIBE_Player::tech_abling(this,0x5f,puVar3[0x10]);
      TRIBE_Player::tech_abling(this,0x61,puVar3[0x14]);
      TRIBE_Player::tech_abling(this,0x62,puVar3[0x18]);
      TRIBE_Player::tech_abling(this,0x5d,puVar3[0x1c]);
      TRIBE_Player::tech_abling(this,0x60,puVar3[0x20]);
      TRIBE_Player::tech_abling(this,0x5c,puVar3[0x24]);
      TRIBE_Player::tech_abling(this,0x65,puVar3[0x28]);
      TRIBE_Player::tech_abling(this,0x66,puVar3[0x2c]);
      TRIBE_Player::tech_abling(this,0x67,puVar3[0x30]);
      TRIBE_Player::tech_abling(this,0x73,puVar3[0x34]);
      TRIBE_Player::tech_abling(this,0x74,puVar3[0x38]);
      iVar2 = iVar2 + 1;
      iVar1 = *(int *)(param_1 + 8);
      puVar3 = puVar3 + 0x50;
    } while (iVar2 < *(short *)(iVar1 + 0x3c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052c1da
// Address: 0052c1da
// XREFS: None
undefined4 __fastcall FUN_0052c1da(T_Scenario *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = RGE_Scenario::Get_player_Active((RGE_Scenario *)param_1,iVar3);
    if (iVar1 != 0) {
      T_Scenario::SetSPWhich(param_1,iVar3);
      iVar1 = 0;
      do {
        iVar2 = T_Scenario::GetSPVictoryType(param_1,iVar1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0xc);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052c224
// Address: 0052c224
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0052c224(int param_1,TRIBE_Player *param_2)
{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = *(short *)((int)&param_2->_padding_ + 2) + -1;
  if (iVar2 < 0) {
    return;
  }
  iVar1 = iVar2 * 0x50 + param_1;
  TRIBE_Player::tech_abling(param_2,0x58,*(uchar *)(iVar2 * 0x50 + 0x4bf4 + param_1));
  TRIBE_Player::tech_abling(param_2,0x59,*(uchar *)(iVar1 + 0x4bf8));
  TRIBE_Player::tech_abling(param_2,0x5a,*(uchar *)(iVar1 + 0x4bfc));
  TRIBE_Player::tech_abling(param_2,0x5b,*(uchar *)(iVar1 + 0x4c00));
  TRIBE_Player::tech_abling(param_2,0x5e,*(uchar *)(iVar1 + 0x4c04));
  TRIBE_Player::tech_abling(param_2,0x5f,*(uchar *)(iVar1 + 0x4c08));
  TRIBE_Player::tech_abling(param_2,0x61,*(uchar *)(iVar1 + 0x4c0c));
  TRIBE_Player::tech_abling(param_2,0x62,*(uchar *)(iVar1 + 0x4c10));
  TRIBE_Player::tech_abling(param_2,0x5d,*(uchar *)(iVar1 + 0x4c14));
  TRIBE_Player::tech_abling(param_2,0x60,*(uchar *)(iVar1 + 0x4c18));
  TRIBE_Player::tech_abling(param_2,0x5c,*(uchar *)(iVar1 + 0x4c1c));
  TRIBE_Player::tech_abling(param_2,0x65,*(uchar *)(iVar1 + 0x4c20));
  TRIBE_Player::tech_abling(param_2,0x66,*(uchar *)(iVar1 + 0x4c24));
  TRIBE_Player::tech_abling(param_2,0x67,*(uchar *)(iVar1 + 0x4c28));
  TRIBE_Player::tech_abling(param_2,0x73,*(uchar *)(iVar1 + 0x4c2c));
  TRIBE_Player::tech_abling(param_2,0x74,*(uchar *)(iVar1 + 0x4c30));
  TRIBE_Player_Tech::check_for_new_tech(param_2->tech_tree);
  if (*(int *)(param_1 + 0x50f4) != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x4c) + 8))(100,param_2);
  }
  if (rge_base_game->prog_mode != 7) {
    switch(*(undefined4 *)(param_1 + 0x5100 + iVar2 * 4)) {
    case 1:
      lVar3 = 0x19;
      break;
    case 2:
      lVar3 = 0x17;
      break;
    case 3:
      lVar3 = 0x18;
      break;
    case 4:
      lVar3 = 1;
      break;
    default:
      goto switchD_0052c390_default;
    }
    TRIBE_Player::rev_tech(param_2,lVar3);
  }
switchD_0052c390_default:
  if ((float)*(int *)(iVar1 + 0x4c2c) == _DAT_00577338) {
    *(undefined4 *)(param_2->_padding_ + 0xc0) = 0x3f800000;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052c3d3
// Address: 0052c3d3
// XREFS: None
void FUN_0052c3d3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0052c8a1
// Address: 0052c8a1
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

int __fastcall FUN_0052c8a1(RGE_Task_List *param_1,RGE_Task *param_2)
{
  char *in_EAX;
  int iVar1;
  char cVar2;
  undefined4 unaff_EBX;
  bool in_OF;
  
  if (in_OF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar2 = (char)((uint)param_2 >> 8);
  in_EAX[-0x3c] = in_EAX[-0x3c] + cVar2;
  (&stack0x0000004a)[(int)in_EAX * 8] =
       (&stack0x0000004a)[(int)in_EAX * 8] + (char)((uint)unaff_EBX >> 8);
  in_EAX[-0x3c] = in_EAX[-0x3c] + cVar2;
  in_EAX[0x52c4] = in_EAX[0x52c4] + (char)((uint)in_EAX >> 8);
  *in_EAX = *in_EAX + (char)in_EAX;
  if (param_2->action_type == 0x68) {
    return 1;
  }
  iVar1 = RGE_Task_List::is_attack_task(param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0052c8ec
// Address: 0052c8ec
// XREFS: None
RGE_Victory_Conditions * __thiscall
FUN_0052c8ec(RGE_Victory_Conditions *param_1,RGE_Player *param_2,int param_3,long *param_4,
            uchar param_5)
{
  RGE_Victory_Conditions::RGE_Victory_Conditions(param_1,param_2,param_3,param_4,param_5);
  param_1->_padding_ = (int)&TRIBE_Victory_Conditions::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052c91a
// Address: 0052c91a
// XREFS: None
RGE_Victory_Conditions * __thiscall
FUN_0052c91a(RGE_Victory_Conditions *param_1,RGE_Player *param_2)
{
  RGE_Victory_Conditions::RGE_Victory_Conditions(param_1,param_2);
  param_1->_padding_ = (int)&TRIBE_Victory_Conditions::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052c939
// Address: 0052c939
// XREFS: None
void __fastcall FUN_0052c939(RGE_Victory_Conditions *param_1)
{
  param_1->_padding_ = (int)&TRIBE_Victory_Conditions::_vftable_;
  RGE_Victory_Conditions::~RGE_Victory_Conditions(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0052c94b
// Address: 0052c94b
// XREFS: None
void __thiscall FUN_0052c94b(RGE_Victory_Conditions *param_1,RGE_Victory_Entry *param_2)
{
  if (param_2->command != 'd') {
    RGE_Victory_Conditions::handle_condition(param_1,param_2);
    return;
  }
  TRIBE_Victory_Conditions::handle_tech((TRIBE_Victory_Conditions *)param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0052c96a
// Address: 0052c96a
// XREFS: None
void __thiscall FUN_0052c96a(int param_1,int param_2)
{
  short sVar1;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (*(char *)(param_2 + 0x2e) == '\0')) {
    sVar1 = TRIBE_Player_Tech::get_tech_state
                      (*(TRIBE_Player_Tech **)(*(int *)(param_1 + 0xc) + 0x220),
                       *(short *)(param_2 + 0x20));
    if (sVar1 == 3) {
      *(undefined1 *)(param_2 + 0x2e) = 2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052c9a1
// Address: 0052c9a1
// XREFS: None
undefined4 __thiscall FUN_0052c9a1(RGE_Victory_Conditions *param_1,uchar param_2,long param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = 'd';
    pRVar1->count = param_3;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052c9d4
// Address: 0052c9d4
// XREFS: None
RGE_Diamond_Map_View * __fastcall FUN_0052c9d4(RGE_Diamond_Map_View *param_1)
{
  RGE_Diamond_Map_View::RGE_Diamond_Map_View(param_1);
  *(undefined ***)param_1 = &TRIBE_Diamond_Map_View::_vftable_;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)&param_1[1].field_0x4 = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052ca25
// Address: 0052ca25
// XREFS: None
void __thiscall FUN_0052ca25(RGE_Diamond_Map *param_1,RedrawMode param_2)
{
  RGE_Diamond_Map::set_redraw(param_1,param_2);
  if (((param_2 != RedrawNone) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) {
    TRIBE_Screen_Game::set_map_buttons_redraw((TRIBE_Screen_Game *)param_1->_padding_,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052ca5e
// Address: 0052ca5e
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_tvw_dmap_c: "C:\msdev\work\age1_x1\tvw_dmap.cpp"
void __fastcall FUN_0052ca5e(RGE_Diamond_Map *param_1)
{
  ulong uVar1;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_tvw_dmap_c,0x40);
  if (0x14c < uVar1 - param_1[1]._padding_) {
    param_1[1]._padding_ = (uint)(param_1[1]._padding_ == 0);
    param_1[1]._padding_ = uVar1;
  }
  RGE_Diamond_Map::draw_objects(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0052caa6
// Address: 0052caa6
// XREFS: None
void __thiscall
FUN_0052caa6(RGE_Diamond_Map *param_1,short param_2,short param_3,uchar param_4,short param_5,
            RGE_Static_Object *param_6)
{
  if (param_1->draw_objects_mode == 4) {
    param_4 = (-(param_1[1]._padding_ != 0) & 0x57U) - 1;
  }
  RGE_Diamond_Map::draw_object(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_0052caec
// Address: 0052caec
// XREFS: None
void __fastcall FUN_0052caec(RGE_Main_View *param_1)
{
  TRIBE_Master_Building_Object *pTVar1;
  int iVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iStack_48;
  TRIBE_Master_Building_Object *pTStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  long lStack_28;
  int iStack_24;
  int iStack_20;
  tagPOINT tStack_1c;
  RGE_Pick_Info RStack_14;
  
  if (rge_base_game->master_obj_id == -1) {
    return;
  }
  pTStack_44 = *(TRIBE_Master_Building_Object **)
                (*(int *)(param_1->_padding_ + 0x24) + rge_base_game->master_obj_id * 4);
  if (pTStack_44 == (TRIBE_Master_Building_Object *)0x0) {
    return;
  }
  TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)&param_1->_padding_);
  iVar4 = RGE_View::get_selection_area
                    ((RGE_View *)param_1,&iStack_38,&iStack_24,&iStack_30,&iStack_48,0);
  iVar5 = iStack_38;
  if (iVar4 == 0) {
    RGE_Base_Game::get_mouse_pos(rge_base_game,&tStack_1c);
    iVar5 = (**(code **)(param_1->_padding_ + 0xbc))(tStack_1c.x,tStack_1c.y);
    if (iVar5 == 0) {
      return;
    }
    uVar3 = RGE_Main_View::pick1
                      (param_1,'(','\0',tStack_1c.x - param_1->_padding_,
                       tStack_1c.y - param_1->_padding_,&RStack_14,(RGE_Static_Object *)0x0,1);
    if (uVar3 != '3') {
      return;
    }
    RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
    iVar5 = __ftol();
    iStack_38 = iVar5;
    iStack_48 = __ftol();
    iStack_30 = iVar5;
    iStack_24 = iStack_48;
  }
  pTVar1 = pTStack_44;
  lStack_28 = -1;
  iStack_2c = -1;
  uVar8 = iStack_48 - iStack_24 >> 0x1f;
  iVar9 = (iStack_48 - iStack_24 ^ uVar8) - uVar8;
  uVar8 = iStack_30 - iVar5 >> 0x1f;
  iVar4 = (iStack_30 - iVar5 ^ uVar8) - uVar8;
  if (iVar9 == iVar4) {
    if (iStack_30 < iVar5) {
      iVar4 = iStack_30;
      iVar9 = iStack_48;
      if (iStack_48 < iStack_24) {
        do {
          TRIBE_Main_View::draw_wall_outline((TRIBE_Main_View *)param_1,iVar4,iVar9,pTVar1,2);
          iVar4 = iVar4 + 1;
          iVar9 = iVar9 + 1;
        } while (iVar4 <= iStack_38);
        TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
        return;
      }
      if (iStack_30 < iVar5) {
        iVar4 = iStack_24;
        if (iStack_30 <= iVar5) {
          do {
            TRIBE_Main_View::draw_wall_outline((TRIBE_Main_View *)param_1,iVar5,iVar4,pTVar1,2);
            iVar5 = iVar5 + -1;
            iVar4 = iVar4 + 1;
          } while (iStack_30 <= iVar5);
          TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
          return;
        }
        goto LAB_0052d047;
      }
    }
    iVar4 = iStack_30;
    iVar9 = iStack_48;
    if (iStack_48 < iStack_24) {
      do {
        TRIBE_Main_View::draw_wall_outline((TRIBE_Main_View *)param_1,iVar4,iVar9,pTVar1,2);
        iVar4 = iVar4 + -1;
        iVar9 = iVar9 + 1;
      } while (iStack_38 <= iVar4);
      TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
      return;
    }
    iVar4 = iStack_24;
    if (iVar5 <= iStack_30) {
      do {
        TRIBE_Main_View::draw_wall_outline((TRIBE_Main_View *)param_1,iVar5,iVar4,pTVar1,2);
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar5 <= iStack_30);
      TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
      return;
    }
  }
  else if (iVar9 < iVar4) {
    iStack_40 = iStack_30;
    iStack_34 = iVar5;
    if (iVar5 < iStack_30) {
      iStack_40 = iVar5;
      iStack_34 = iStack_30;
    }
    if (iStack_24 < iStack_48) {
      iStack_20 = iStack_24 + 1;
      iStack_3c = iStack_48;
      lStack_28 = iStack_30;
    }
    else if (iStack_48 < iStack_24) {
      iStack_3c = iStack_24 + -1;
      iStack_20 = iStack_48;
      lStack_28 = iStack_30;
    }
    lVar6 = lStack_28;
    iVar4 = iStack_3c;
    iStack_2c = iStack_24;
    if ((lStack_28 == -1) ||
       (iVar9 = iStack_40, iVar11 = iStack_34, iVar10 = iStack_20, iStack_24 < iStack_20)) {
      iVar4 = iStack_34;
      if (iStack_40 <= iStack_34) {
        do {
          if ((iVar4 == iVar5) || (iVar4 == iStack_30)) {
            lVar6 = 2;
          }
          else {
            lVar6 = 0;
          }
          TRIBE_Main_View::draw_wall_outline
                    ((TRIBE_Main_View *)param_1,iVar4,iStack_2c,pTStack_44,lVar6);
          iVar4 = iVar4 + -1;
          iVar5 = iStack_38;
        } while (iStack_40 <= iVar4);
      }
      if ((lStack_28 != -1) && (iVar5 = iStack_20, iStack_20 <= iStack_3c)) {
        do {
          if ((iVar5 == iStack_24) || (lVar6 = 1, iVar5 == iStack_48)) {
            lVar6 = 2;
          }
          TRIBE_Main_View::draw_wall_outline
                    ((TRIBE_Main_View *)param_1,lStack_28,iVar5,pTStack_44,lVar6);
          iVar5 = iVar5 + 1;
        } while (iVar5 <= iStack_3c);
      }
    }
    else {
      for (; iStack_40 = iVar9, iStack_34 = iVar11, iVar10 <= iVar4; iVar10 = iVar10 + 1) {
        if ((iVar10 == iStack_24) || (lVar7 = 1, iVar10 == iStack_48)) {
          lVar7 = 2;
        }
        TRIBE_Main_View::draw_wall_outline((TRIBE_Main_View *)param_1,lVar6,iVar10,pTStack_44,lVar7)
        ;
        iVar5 = iStack_38;
        iVar9 = iStack_40;
        iVar11 = iStack_34;
      }
      if (iVar9 <= iVar11) {
        do {
          if ((iVar11 == iVar5) || (iVar11 == iStack_30)) {
            lVar6 = 2;
          }
          else {
            lVar6 = 0;
          }
          TRIBE_Main_View::draw_wall_outline
                    ((TRIBE_Main_View *)param_1,iVar11,iStack_2c,pTStack_44,lVar6);
          iVar11 = iVar11 + -1;
          iVar5 = iStack_38;
        } while (iVar9 <= iVar11);
        TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
        return;
      }
    }
  }
  else {
    iVar4 = iStack_48;
    iStack_3c = iStack_24;
    if (iStack_24 < iStack_48) {
      iStack_3c = iStack_48;
      iVar4 = iStack_24;
    }
    iVar9 = iStack_3c;
    if (iVar5 < iStack_30) {
      iStack_2c = iStack_48;
      iStack_40 = iVar5 + 1;
      iStack_34 = iStack_30;
    }
    else if (iStack_30 < iVar5) {
      iStack_2c = iStack_48;
      iStack_34 = iVar5 + -1;
      iStack_40 = iStack_30;
    }
    iVar2 = iStack_40;
    iVar11 = iVar5;
    lStack_28 = iVar5;
    iStack_20 = iVar4;
    iVar10 = iStack_34;
    if ((iStack_2c == -1) || (lVar6 = iVar5, iStack_34 < iVar5)) {
      for (; iStack_34 = iVar10, iVar4 <= iVar9; iVar4 = iVar4 + 1) {
        if ((iVar4 == iStack_24) || (lVar6 = 1, iVar4 == iStack_48)) {
          lVar6 = 2;
        }
        TRIBE_Main_View::draw_wall_outline((TRIBE_Main_View *)param_1,iVar5,iVar4,pTStack_44,lVar6);
        iVar11 = iStack_38;
        iVar10 = iStack_34;
      }
      if ((iStack_2c != -1) && (iStack_40 <= iVar10)) {
        do {
          if ((iVar10 == iVar11) || (iVar10 == iStack_30)) {
            lVar6 = 2;
          }
          else {
            lVar6 = 0;
          }
          TRIBE_Main_View::draw_wall_outline
                    ((TRIBE_Main_View *)param_1,iVar10,iStack_2c,pTStack_44,lVar6);
          iVar10 = iVar10 + -1;
          iVar11 = iStack_38;
        } while (iStack_40 <= iVar10);
        TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
        return;
      }
    }
    else {
      for (; iStack_3c = iVar9, lStack_28 = lVar6, iStack_20 = iVar4, iVar2 <= iVar10;
          iVar10 = iVar10 + -1) {
        if ((iVar10 == iVar5) || (iVar10 == iStack_30)) {
          lVar6 = 2;
        }
        else {
          lVar6 = 0;
        }
        TRIBE_Main_View::draw_wall_outline
                  ((TRIBE_Main_View *)param_1,iVar10,iStack_2c,pTStack_44,lVar6);
        iVar5 = iStack_38;
        lVar6 = lStack_28;
        iVar4 = iStack_20;
        iVar9 = iStack_3c;
      }
      if (iVar4 <= iVar9) {
        do {
          if ((iVar4 == iStack_24) || (lVar7 = 1, iVar4 == iStack_48)) {
            lVar7 = 2;
          }
          TRIBE_Main_View::draw_wall_outline
                    ((TRIBE_Main_View *)param_1,lVar6,iVar4,pTStack_44,lVar7);
          iVar4 = iVar4 + 1;
        } while (iVar4 <= iVar9);
        TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
        return;
      }
    }
  }
LAB_0052d047:
  TDrawArea::SetClipRect((TDrawArea *)param_1->_padding_,(tagRECT *)0x0);
  return;
}

// --------------------------------------------------

// Function: FUN_0052d059
// Address: 0052d059
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0052d059(RGE_View *param_1,int param_2,int param_3,RGE_Master_Static_Object *param_4)
{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  RGE_Player *pRVar7;
  int unaff_EDI;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short sStack_1c;
  short sStack_1a;
  undefined4 uStack_18;
  short sStack_14;
  short sStack_12;
  short asStack_10 [2];
  short asStack_c [2];
  short asStack_8 [2];
  short asStack_4 [2];
  
  iVar4 = RGE_View::get_tile_screen_coords
                    (param_1,(short)param_2,(short)param_3,asStack_c,asStack_10,0);
  if (iVar4 != 0) {
    fVar1 = (float)param_2 - _DAT_00577450;
    fVar2 = (float)param_3 - _DAT_00577450;
    RGE_Master_Static_Object::alignment_box
              (param_4,param_1->world,fVar1,fVar2,&sStack_1c,&sStack_12,&sStack_14,&sStack_1a,
               asStack_8,(short *)((int)&uStack_18 + 2),(short *)&uStack_18,asStack_4);
    iVar14 = 1;
    iVar4 = param_4->_padding_;
    iVar13 = 1;
    iVar12 = 1;
    uVar11 = 1;
    cVar3 = (**(code **)(iVar4 + 0x20))
                      (param_1->player,fVar1,fVar2,0,1,param_4->elevation_flag,0,1,1,1);
    if (cVar3 == '\0') {
      fog_next_shape = 5;
    }
    else {
      uVar5 = param_1->world->world_time >> 7 & 7;
      if (uVar5 < 4) {
        iVar6 = uVar5 + 0x24;
      }
      else {
        iVar6 = 0x2c - uVar5;
      }
      fog_next_shape = iVar6 << 4 | 9;
    }
    if (param_4->sprite != (RGE_Sprite *)0x0) {
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0;
      iVar13 = iVar13 + ((int)(short)uVar11 - (int)(short)iVar14) / 2 + iVar14;
      iVar12 = iVar12 + ((int)(short)((uint)uVar11 >> 0x10) - (int)(short)unaff_EDI) / 2 + unaff_EDI
      ;
      iVar14 = uStack_18 + 1;
      SDI_Draw_Line = (int)(short)iVar12;
      pRVar7 = RGE_Base_Game::get_player(rge_base_game);
      (**(code **)(iVar4 + 0x34))
                (param_1->_padding_,iVar13,iVar12,pRVar7->color_table,iVar14,uVar8,uVar9,uVar10);
    }
  }
  fog_next_shape = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0052d1e7
// Address: 0052d1e7
// XREFS: None
int __thiscall FUN_0052d1e7(RGE_Main_View *param_1,long param_2,long param_3)
{
  short sVar1;
  int *piVar2;
  int iVar3;
  uchar uVar4;
  char cVar5;
  int iVar6;
  undefined4 extraout_ECX;
  float fVar7;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float fVar8;
  int iVar9;
  RGE_Pick_Info RStack_14;
  
  if (allow_user_commands != 0) {
    if (rge_base_game->game_mode != 7) {
      iVar6 = RGE_Main_View::command_place_object(param_1,param_2,param_3,1);
      return iVar6;
    }
    uVar4 = RGE_Main_View::pick1
                      (param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
    if (uVar4 == '3') {
      RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
      sVar1 = rge_base_game->master_obj_id;
      iVar6 = (int)sVar1;
      if ((iVar6 != -1) &&
         (piVar2 = *(int **)(*(int *)(param_1->_padding_ + 0x24) + iVar6 * 4), piVar2 != (int *)0x0)
         ) {
        iVar9 = param_1->_padding_;
        iVar3 = *piVar2;
        (**(code **)(iVar3 + 0x24))(&RStack_14,&RStack_14.y,iVar9,0);
        fVar7 = (float)CONCAT31((int3)((uint)extraout_ECX >> 8),(char)piVar2[0x19]);
        fVar8 = 1.4013e-45;
        cVar5 = (**(code **)(iVar3 + 0x20))
                          (param_1->_padding_,unaff_EDI,unaff_ESI,0,1,fVar7,0,1,1,1);
        if (cVar5 == '\0') {
          if ((iVar9 != 0) || (iVar6 == 0x6d)) {
            (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          }
          uVar4 = TRIBE_Player::command_make_building
                            ((TRIBE_Player *)param_1->_padding_,sVar1,fVar8,fVar7);
          if (uVar4 != '\0') {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052d4e8
// Address: 0052d4e8
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052d4e8(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)
{
  code *pcVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  int iStack_c;
  int iStack_8;
  
  iVar4 = param_3;
  if (param_3 == param_5) {
    iStack_c = 0;
  }
  else {
    iStack_c = ((param_5 <= param_3) - 1 & 2) - 1;
  }
  if (param_4 == param_6) {
    iStack_8 = 0;
  }
  else {
    iStack_8 = ((param_6 <= param_4) - 1 & 2) - 1;
  }
  param_3 = param_4;
  param_4 = iVar4;
  pcVar1 = *(code **)(*param_2 + 0x20);
  while( true ) {
    fVar2 = (float)param_4 - _DAT_00577450;
    fVar3 = (float)param_3 - _DAT_00577450;
    cVar5 = (*pcVar1)(param_1,fVar2,fVar3,0,1,(char)param_2[0x19],0,1,1,1);
    if (cVar5 == '\0') {
      (**(code **)(*param_1 + 0x94))((int)(short)param_2[4],fVar2,fVar3,0,1);
    }
    if ((param_4 == param_5) && (param_3 == param_6)) break;
    param_4 = param_4 + iStack_c;
    param_3 = param_3 + iStack_8;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0052d5f1
// Address: 0052d5f1
// XREFS: None
long __thiscall FUN_0052d5f1(RGE_Main_View *param_1,int param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  long lVar4;
  RGE_Static_Object *pRVar5;
  RGE_Pick_Info RStack_14;
  
  iVar3 = rge_base_game->prog_mode;
  if ((((iVar3 != 4) && (iVar3 != 6)) && (iVar3 != 7)) && (iVar3 != 5)) {
    return 0;
  }
  iVar3 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar3 != 0) {
switchD_0052d657_default:
    lVar4 = RGE_Main_View::mouse_left_up_action(param_1,param_2,param_3,param_4,param_5);
    return lVar4;
  }
  switch(rge_base_game->game_mode) {
  case 100:
    TPanel::release_mouse((TPanel *)param_1);
    cVar1 = (char)param_1->_padding_;
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
      return 1;
    }
    uVar2 = RGE_Main_View::pick1
                      (param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
    if (uVar2 == '3') {
      RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
      uVar2 = TRIBE_Player::command_attack_ground
                        ((TRIBE_Player *)param_1->_padding_,RStack_14.x,RStack_14.y);
      if (uVar2 != '\0') {
        RGE_Main_View::reset_display_object_selection(param_1,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)param_1,rge_base_game->shapes[2],0,param_1->_padding_ + param_2,
                   param_1->_padding_ + param_3,0,0xf,(uchar *)0x0,2,0x7d);
        (**(code **)(param_1->_padding_ + 0x20))(1);
        goto LAB_0052d7cc;
      }
    }
    goto LAB_0052d7bf;
  case 0x65:
    TPanel::release_mouse((TPanel *)param_1);
    cVar1 = (char)param_1->_padding_;
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
      return 1;
    }
    iVar3 = (**(code **)(param_1->_padding_ + 0x100))(param_2,param_3,0,0x68);
    if (iVar3 != 0) goto LAB_0052d7cc;
LAB_0052d7bf:
    RGE_Base_Game::play_sound(rge_base_game,3);
LAB_0052d7cc:
    (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    return 1;
  case 0x66:
    TPanel::release_mouse((TPanel *)param_1);
    cVar1 = (char)param_1->_padding_;
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
      return 1;
    }
    iVar3 = (**(code **)(param_1->_padding_ + 0x100))(param_2,param_3,0,0x69);
    goto joined_r0x0052d81c;
  case 0x67:
    TPanel::release_mouse((TPanel *)param_1);
    cVar1 = (char)param_1->_padding_;
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
      return 1;
    }
    iVar3 = (**(code **)(param_1->_padding_ + 0x100))(param_2,param_3,0,7);
joined_r0x0052d81c:
    if (iVar3 != 0) goto LAB_0052d74d;
    break;
  case 0x68:
    TPanel::release_mouse((TPanel *)param_1);
    cVar1 = (char)param_1->_padding_;
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
      return 1;
    }
    pRVar5 = RGE_Main_View::pick_best_target(param_1,param_2,param_3,(int *)0x0,-1);
    if ((pRVar5 != (RGE_Static_Object *)0x0) &&
       (uVar2 = TRIBE_Player::command_make_repair((TRIBE_Player *)param_1->_padding_,pRVar5),
       uVar2 != '\0')) {
      RGE_View::display_object_selection((RGE_View *)param_1,pRVar5->id,0x5dc,2,2);
      RGE_View::reset_overlay_sprites((RGE_View *)param_1);
      (**(code **)(param_1->_padding_ + 0x20))(1);
      goto LAB_0052d74d;
    }
    break;
  case 0x69:
    TPanel::release_mouse((TPanel *)param_1);
    cVar1 = (char)param_1->_padding_;
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
      return 1;
    }
    uVar2 = RGE_Main_View::pick1
                      (param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
    if (uVar2 == '3') {
      RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
      uVar2 = TRIBE_Player::command_make_unload
                        ((TRIBE_Player *)param_1->_padding_,RStack_14.x,RStack_14.y);
      if (uVar2 != '\0') {
        RGE_Main_View::reset_display_object_selection(param_1,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)param_1,rge_base_game->shapes[2],0,param_1->_padding_ + param_2,
                   param_1->_padding_ + param_3,0,0xf,(uchar *)0x0,2,0x7d);
        (**(code **)(param_1->_padding_ + 0x20))(1);
        goto LAB_0052d74d;
      }
    }
    break;
  default:
    goto switchD_0052d657_default;
  }
  RGE_Base_Game::play_sound(rge_base_game,3);
LAB_0052d74d:
  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0052dd03
// Address: 0052dd03
// XREFS: None
char __thiscall FUN_0052dd03(int param_1,int param_2,int param_3)
{
  char cVar1;
  short sVar2;
  bool bVar3;
  
  cVar1 = *(char *)(*(int *)(param_2 + 8) + 0x8d);
  sVar2 = *(short *)(*(int *)(param_2 + 8) + 0x10);
  if ((((sVar2 == 0x4f) || (sVar2 == 199)) || (sVar2 == 0x45)) || (sVar2 == 0x116)) {
    cVar1 = '\x03';
  }
  if ((*(int *)(param_1 + 0x33c) == 0) || (*(int *)(param_1 + 0x340) != *(int *)(param_2 + 4))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (cVar1 == '\x02') {
    if (bVar3) {
      return '\x05';
    }
    if ((param_3 != 1) && (param_3 != 2)) {
      if (param_3 != 3) {
        return '\0';
      }
      return '\x02';
    }
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 != '\x04') {
        return '\x01';
      }
      if (!bVar3) {
        if ((param_3 != 1) && (param_3 != 2)) {
          return (param_3 == 3) + '\x02';
        }
        return '\x04';
      }
      return '\x05';
    }
    if (bVar3) {
      return '\x05';
    }
    if ((param_3 != 1) && (param_3 != 2)) {
      if (param_3 != 3) {
        return '\0';
      }
      if (1 < *(byte *)(param_2 + 0x48)) {
        return '\0';
      }
      return '\x02';
    }
  }
  return '\x03';
}

// --------------------------------------------------

// Function: FUN_0052de19
// Address: 0052de19
// XREFS: None
void __thiscall
FUN_0052de19(RGE_Main_View *param_1,long param_2,long param_3,int param_4,short param_5)
{
  RGE_Main_View::command_make_do(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0052de3c
// Address: 0052de3c
// XREFS: None
undefined4 __thiscall
FUN_0052de3c(RGE_Main_View *param_1,long param_2,long param_3,int param_4,int param_5)
{
  short sVar1;
  undefined4 *puVar2;
  RGE_Static_Object *pRVar3;
  uchar uVar4;
  bool bVar5;
  RGE_Pick_Info RStack_14;
  
  uVar4 = RGE_Main_View::pick1
                    (param_1,')','\x01',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
  if (((uVar4 == '4') && ((RStack_14.object)->master_obj->select_level == '\x04')) &&
     ((RStack_14.object)->owner == (RGE_Player *)param_1->_padding_)) {
    if ((param_4 == 0) && (param_5 == 0)) {
      RGE_Player::unselect_object((RGE_Player *)param_1->_padding_);
    }
    RGE_Player::select_one_object((RGE_Player *)param_1->_padding_,RStack_14.object,0);
    sVar1 = (RStack_14.object)->master_obj->id;
    param_3._0_1_ = (RStack_14.object)->master_obj->unit_level;
    if ((uchar)param_3 != '\x03') {
      param_3._0_1_ = 0xff;
    }
    for (puVar2 = *(undefined4 **)(*(int *)(param_1->_padding_ + 0x28) + 4);
        puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
      pRVar3 = (RGE_Static_Object *)*puVar2;
      if (((pRVar3->master_obj->id == sVar1) || (pRVar3->master_obj->unit_level == (uchar)param_3))
         && (bVar5 = RGE_View::Object_Was_Displayed((RGE_View *)param_1,pRVar3->id,false), bVar5)) {
        RGE_Player::select_one_object((RGE_Player *)param_1->_padding_,pRVar3,0);
      }
    }
    RGE_Player::select_one_object((RGE_Player *)param_1->_padding_,RStack_14.object,0);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0052df56
// Address: 0052df56
// XREFS: None
// [HELPER] s_data_aoe_ply: "data\aoe.ply"
RGE_Game_World * __fastcall FUN_0052df56(RGE_Game_World *param_1)
{
  TribeAIPlayBook *this;
  AIPlayBook *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_005618d3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Game_World::RGE_Game_World(param_1);
  iStack_4 = 0;
  *(undefined1 *)((int)&param_1[1].game_speed + 1) = 0xff;
  param_1->_padding_ = (int)&TRIBE_World::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1].world_time = 0;
  param_1[1].old_world_time = 0;
  param_1[1].world_time_delta = 0;
  param_1[1].temp_pause = '\0';
  param_1[1].game_state = '\0';
  param_1[1].game_end_condition = '\0';
  param_1[1].field_0x1f = 0;
  *(undefined1 *)&param_1[1].timer = 0;
  param_1[1].old_time = 0;
  *(undefined1 *)&param_1[1].game_speed = 0;
  this = (TribeAIPlayBook *)operator_new(0x50);
  iStack_4._0_1_ = 1;
  if (this == (TribeAIPlayBook *)0x0) {
    this_00 = (AIPlayBook *)0x0;
  }
  else {
    this_00 = (AIPlayBook *)TribeAIPlayBook::TribeAIPlayBook(this);
  }
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  param_1->playbook = this_00;
  if (this_00 != (AIPlayBook *)0x0) {
    AIPlayBook::loadPlays(this_00,s_data_aoe_ply);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052e017
// Address: 0052e017
// XREFS: None
TRIBE_World * __thiscall FUN_0052e017(TRIBE_World *param_1,byte param_2)
{
  TRIBE_World::~TRIBE_World(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052e03e
// Address: 0052e03e
// XREFS: None
void __fastcall FUN_0052e03e(RGE_Game_World *param_1)
{
  TRIBE_Tech *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005618e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_World::_vftable_;
  this = (TRIBE_Tech *)param_1[1]._padding_;
  uStack_4 = 0;
  if (this != (TRIBE_Tech *)0x0) {
    TRIBE_Tech::~TRIBE_Tech(this);
    operator_delete(this);
    param_1[1]._padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  RGE_Game_World::~RGE_Game_World(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e216
// Address: 0052e216
// XREFS: None
void __thiscall FUN_0052e216(RGE_Game_World *param_1,short param_2,short param_3,_iobuf *param_4)
{
  TRIBE_Master_Player *this;
  RGE_Master_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056190b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 != 1) {
    RGE_Game_World::data_load_players_type(param_1,param_2,param_3,param_4);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  this = (TRIBE_Master_Player *)operator_new(0x2c);
  uStack_4 = 0;
  if (this == (TRIBE_Master_Player *)0x0) {
    pRVar1 = (RGE_Master_Player *)0x0;
  }
  else {
    pRVar1 = (RGE_Master_Player *)TRIBE_Master_Player::TRIBE_Master_Player(this,param_4);
  }
  param_1->master_players[param_2] = pRVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e2ad
// Address: 0052e2ad
// XREFS: None
void __thiscall
FUN_0052e2ad(int param_1,char *param_2,char *param_3,char *param_4,char *param_5,short param_6,
            short param_7,short param_8,RGE_Sound **param_9,char *param_10)
{
  TRIBE_Map *this;
  RGE_Map *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056192b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Map *)operator_new(0xb5f8);
  uStack_4 = 0;
  if (this == (TRIBE_Map *)0x0) {
    this_00 = (RGE_Map *)0x0;
  }
  else {
    this_00 = (RGE_Map *)
              TRIBE_Map::TRIBE_Map
                        (this,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  uStack_4 = 0xffffffff;
  *(RGE_Map **)(param_1 + 0x28) = this_00;
  RGE_Map::load_terrain_obj_types(this_00,param_10);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e342
// Address: 0052e342
// XREFS: None
// [HELPER] s__s_: "%s\n"
undefined4 __thiscall FUN_0052e342(RGE_Game_World *param_1,_iobuf *param_2)
{
  TRIBE_Tech *this;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  char acStack_24 [24];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056194b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Game_World::data_load_world(param_1,param_2);
  fscanf(param_2,s__s_,acStack_24);
  this = (TRIBE_Tech *)operator_new(0xc);
  uStack_4 = 0;
  if (this == (TRIBE_Tech *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_Tech::TRIBE_Tech(this,acStack_24);
  }
  param_1[1]._padding_ = iVar1;
  param_1[1].world_time = 0;
  param_1[1].old_world_time = 0;
  param_1[1].world_time_delta = 0;
  *(undefined1 *)&param_1[1].timer = 0;
  param_1[1].old_time = 0;
  *(undefined1 *)&param_1[1].game_speed = 0;
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0052e3f2
// Address: 0052e3f2
// XREFS: None
uchar __thiscall FUN_0052e3f2(RGE_Game_World *param_1,int param_2,short param_3,uchar param_4)
{
  uchar uVar1;
  TRIBE_Master_Player *this;
  RGE_Master_Player *pRVar2;
  undefined4 *unaff_FS_OFFSET;
  RGE_Sound **ppRVar3;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056196b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_4 != '\x01') {
    uVar1 = RGE_Game_World::init_player_type(param_1,param_2,param_3,param_4);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  this = (TRIBE_Master_Player *)operator_new(0x2c);
  uStack_4 = 0;
  if (this == (TRIBE_Master_Player *)0x0) {
    pRVar2 = (RGE_Master_Player *)0x0;
  }
  else {
    pRVar2 = (RGE_Master_Player *)TRIBE_Master_Player::TRIBE_Master_Player(this,param_2);
  }
  uStack_4 = 0xffffffff;
  param_1->master_players[param_3] = pRVar2;
  ppRVar3 = param_1->sounds;
  (**(code **)(param_1->master_players[param_3]->_padding_ + 4))(param_2,param_1->sprites);
  *unaff_FS_OFFSET = ppRVar3;
  return '\x01';
}

// --------------------------------------------------

// Function: FUN_0052e4b4
// Address: 0052e4b4
// XREFS: None
void __thiscall FUN_0052e4b4(int param_1,int param_2)
{
  TRIBE_Map *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056198b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Map *)operator_new(0xb5f8);
  uStack_4 = 0;
  if (this == (TRIBE_Map *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TRIBE_Map::TRIBE_Map(this,param_2,*(RGE_Sound ***)(param_1 + 0x30),'\x01');
  }
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e521
// Address: 0052e521
// XREFS: None
void __thiscall
FUN_0052e521(TRIBE_World *param_1,undefined4 param_2,TCommunications_Handler *param_3)
{
  TRIBE_Command *this;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005619ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Command *)operator_new(0x18);
  uStack_4 = 0;
  if (this == (TRIBE_Command *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_Command::TRIBE_Command(this,param_1,param_3);
  }
  param_1->_padding_ = iVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e589
// Address: 0052e589
// XREFS: None
void __thiscall FUN_0052e589(int param_1,int param_2,RGE_Game_World *param_3)
{
  T_Scenario *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005619cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (T_Scenario *)operator_new(0x514c);
  uStack_4 = 0;
  if (this == (T_Scenario *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = T_Scenario::T_Scenario(this,param_2,param_3);
  }
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e64b
// Address: 0052e64b
// XREFS: None
void __thiscall FUN_0052e64b(int param_1,int param_2)
{
  TRIBE_Effects *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561a0b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Effects *)operator_new(0xc);
  uStack_4 = 0;
  if (this == (TRIBE_Effects *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TRIBE_Effects::TRIBE_Effects(this,param_2);
  }
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e6a8
// Address: 0052e6a8
// XREFS: None
void __thiscall
FUN_0052e6a8(TRIBE_World *param_1,int param_2,TSound_Driver *param_3,
            TCommunications_Handler *param_4)
{
  TRIBE_Tech *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561a2b;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Game_World::world_init((RGE_Game_World *)param_1,param_2,param_3,param_4);
  pTVar1 = (TRIBE_Tech *)operator_new(0xc);
  uStack_4 = 0;
  if (pTVar1 == (TRIBE_Tech *)0x0) {
    pTVar1 = (TRIBE_Tech *)0x0;
  }
  else {
    pTVar1 = (TRIBE_Tech *)TRIBE_Tech::TRIBE_Tech(pTVar1,param_2,param_1);
  }
  param_1->tech = pTVar1;
  param_1->victory_type = 0;
  param_1->artifact_count = 0;
  param_1->ruin_count = 0;
  param_1->countdown_victory = '\0';
  param_1->countdown_clock = 0.0;
  param_1->score_displayed = '\0';
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e743
// Address: 0052e743
// XREFS: None
void __thiscall
FUN_0052e743(RGE_Game_World *param_1,char *param_2,TSound_Driver *param_3,
            TCommunications_Handler *param_4)
{
  RGE_Game_World::init(param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0052e767
// Address: 0052e767
// XREFS: None
void __thiscall FUN_0052e767(RGE_Game_World *param_1,int param_2)
{
  RGE_Game_World::base_save(param_1,param_2);
  TRIBE_Tech::save((TRIBE_Tech *)param_1[1]._padding_,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0052e78f
// Address: 0052e78f
// XREFS: None
void __thiscall FUN_0052e78f(RGE_Game_World *param_1,int param_2)
{
  RGE_Game_World::save(param_1,param_2);
  rge_write(param_2,&param_1[1].world_time,4);
  rge_write(param_2,&param_1[1].old_world_time,4);
  rge_write(param_2,&param_1[1].world_time_delta,4);
  rge_write(param_2,&param_1[1].timer,1);
  rge_write(param_2,&param_1[1].old_time,4);
  rge_write(param_2,&param_1[1].game_speed,1);
  rge_write(param_2,(void *)((int)&param_1[1].game_speed + 1),1);
  return;
}

// --------------------------------------------------

// Function: FUN_0052e821
// Address: 0052e821
// XREFS: None
void __thiscall FUN_0052e821(TRIBE_World *param_1,int param_2,uchar param_3,short param_4)
{
  TRIBE_Gaia *this;
  TRIBE_Player *this_00;
  undefined4 uVar1;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561a56;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == '\x01') {
LAB_0052e8b5:
    this_00 = (TRIBE_Player *)operator_new(0x848);
    uStack_4 = 0;
    if (this_00 != (TRIBE_Player *)0x0) {
      uVar1 = TRIBE_Player::TRIBE_Player(this_00,param_2,param_1,(uchar)param_4);
      goto LAB_0052e8e8;
    }
  }
  else {
    if (param_3 != '\x02') {
      if (param_3 != '\x03') {
        RGE_Game_World::load_player((RGE_Game_World *)param_1,param_2,param_3,param_4);
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
      goto LAB_0052e8b5;
    }
    this = (TRIBE_Gaia *)operator_new(0x858);
    uStack_4 = 1;
    if (this != (TRIBE_Gaia *)0x0) {
      uVar1 = TRIBE_Gaia::TRIBE_Gaia(this,param_2,param_1,(uchar)param_4);
      goto LAB_0052e8e8;
    }
  }
  uVar1 = 0;
LAB_0052e8e8:
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1->_padding_ + param_4 * 4) = uVar1;
  (**(code **)(**(int **)(param_1->_padding_ + param_4 * 4) + 0x74))(param_2);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e91c
// Address: 0052e91c
// XREFS: None
// [HELPER] s_GAIA: "GAIA"
void __fastcall FUN_0052e91c(TRIBE_World *param_1)
{
  TRIBE_Gaia *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561a6b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Gaia *)operator_new(0x858);
  uStack_4 = 0;
  if (this == (TRIBE_Gaia *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TRIBE_Gaia::TRIBE_Gaia
                      (this,param_1,*(RGE_Master_Player **)param_1->_padding_,'\0',s_GAIA,'\0');
  }
  *(undefined4 *)param_1->_padding_ = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052e986
// Address: 0052e986
// XREFS: None
void __thiscall FUN_0052e986(TRIBE_World *param_1,char *param_2)
{
  char *pcVar1;
  TRIBE_Player *pTVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_00561aa1;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = 1;
  pcVar1 = param_2;
  if (1 < (short)param_1->_padding_) {
    do {
      uStack_4 = 0xffffffff;
      if (param_2[iVar4 + 0x248] == '\0') {
        pTVar2 = (TRIBE_Player *)operator_new(0x848);
        uStack_4 = 0;
        if (pTVar2 == (TRIBE_Player *)0x0) goto LAB_0052ea8b;
LAB_0052ea60:
        uVar3 = TRIBE_Player::TRIBE_Player
                          (pTVar2,param_1,
                           *(RGE_Master_Player **)(param_1->_padding_ + param_2[iVar4 + 0x251] * 4),
                           (uchar)iVar4,pcVar1,param_2[iVar4 + 0x251],'\0','\x01',(char *)0x0,
                           (char *)0x0,(char *)0x0);
LAB_0052ea8d:
        *(undefined4 *)(param_1->_padding_ + iVar4 * 4) = uVar3;
      }
      else if (param_2[iVar4 + 0x248] == '\x04') {
        if (useComputerPlayers == 0) {
          pTVar2 = (TRIBE_Player *)operator_new(0x848);
          uStack_4 = 1;
          if (pTVar2 != (TRIBE_Player *)0x0) goto LAB_0052ea60;
        }
        else {
          pTVar2 = (TRIBE_Player *)operator_new(0x848);
          uStack_4 = 2;
          if (pTVar2 != (TRIBE_Player *)0x0) {
            uVar3 = TRIBE_Player::TRIBE_Player
                              (pTVar2,param_1,
                               *(RGE_Master_Player **)
                                (param_1->_padding_ + param_2[iVar4 + 0x251] * 4),(uchar)iVar4,
                               pcVar1,param_2[iVar4 + 0x251],'\x01','\x01',(char *)0x0,(char *)0x0,
                               (char *)0x0);
            goto LAB_0052ea8d;
          }
        }
LAB_0052ea8b:
        uVar3 = 0;
        goto LAB_0052ea8d;
      }
      iVar4 = iVar4 + 1;
      pcVar1 = pcVar1 + 0x41;
    } while (iVar4 < (short)param_1->_padding_);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0052edef
// Address: 0052edef
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar __thiscall FUN_0052edef(RGE_Game_World *param_1,int param_2)
{
  uchar uVar1;
  
  uVar1 = RGE_Game_World::load_world(param_1,param_2);
  if (uVar1 == '\0') {
    return uVar1;
  }
  if (save_game_version < _DAT_00577564) {
    param_1[1].world_time = 0;
  }
  else {
    rge_read(param_2,&param_1[1].world_time,4);
  }
  if (save_game_version < _DAT_00577568) {
    param_1[1].old_world_time = 0;
    param_1[1].world_time_delta = 0;
  }
  else {
    rge_read(param_2,&param_1[1].old_world_time,4);
    rge_read(param_2,&param_1[1].world_time_delta,4);
  }
  if (save_game_version < _DAT_0057756c) {
    *(undefined1 *)&param_1[1].timer = 0;
    param_1[1].old_time = 0;
  }
  else {
    rge_read(param_2,&param_1[1].timer,1);
    rge_read(param_2,&param_1[1].old_time,4);
  }
  if (save_game_version < _DAT_00577570) {
    *(undefined1 *)&param_1[1].game_speed = 0;
  }
  else {
    rge_read(param_2,&param_1[1].game_speed,1);
  }
  if (_DAT_00577574 <= save_game_version) {
    rge_read(param_2,(void *)((int)&param_1[1].game_speed + 1),1);
    return '\x01';
  }
  *(undefined1 *)((int)&param_1[1].game_speed + 1) = 2;
  return '\x01';
}

// --------------------------------------------------

// Function: FUN_0052ef2a
// Address: 0052ef2a
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_tworld_cpp: "C:\msdev\work\age1_x1\tworld.cpp"
// [HELPER] s_NOFOODCAP: "NOFOODCAP"
// [HELPER] s_SYSTEM2: "SYSTEM2"
// [HELPER] s__s__s: "%s\n%s"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

uchar __thiscall FUN_0052ef2a(RGE_Game_World *param_1,RGE_Player_Info *param_2,int param_3)
{
  char cVar1;
  short sVar2;
  T_Scenario *pTVar3;
  RGE_Object_Node *pRVar4;
  uchar uVar5;
  byte bVar6;
  uchar uVar7;
  VictoryType VVar8;
  MapSize MVar9;
  MapType MVar10;
  Age AVar11;
  ResourceLevel RVar12;
  int iVar13;
  char *pcVar14;
  undefined4 uVar15;
  RGE_RMM_Object_Generator *this;
  uint uVar16;
  uint uVar17;
  int iVar18;
  RGE_Player **ppRVar19;
  int iVar20;
  char *pcVar21;
  char **ppcVar22;
  undefined4 *unaff_FS_OFFSET;
  char ***pppcVar23;
  char *pcStack_137c;
  char **ppcStack_1378;
  char *pcStack_1374;
  char **ppcStack_1370;
  char *pcStack_136c;
  char **ppcStack_1368;
  char **ppcStack_1364;
  undefined4 uStack_1360;
  char *apcStack_135c [6];
  int iStack_1344;
  undefined1 *puStack_1340;
  undefined1 *puStack_133c;
  RGE_RMM_Object_Generator *pRStack_1314;
  char acStack_1310 [3];
  uchar uStack_130d;
  char acStack_130c [140];
  undefined1 auStack_1280 [16];
  undefined1 auStack_1270 [16];
  char acStack_1260 [8];
  char acStack_1258 [16];
  undefined1 auStack_1248 [12];
  char acStack_123c [12];
  undefined1 auStack_1230 [16];
  undefined1 auStack_1220 [216];
  char acStack_1148 [200];
  undefined1 auStack_1080 [16];
  undefined1 auStack_1070 [16];
  undefined1 auStack_1060 [8];
  undefined1 auStack_1058 [16];
  char *apcStack_1048 [6];
  undefined1 auStack_1030 [16];
  undefined1 auStack_1020 [20];
  char acStack_100c [4092];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_00561aee;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_10 = 0x52ef4f;
  *(undefined1 *)&param_1[1].game_speed = 0;
  *(undefined1 *)((int)&param_1[1].game_speed + 1) = 0xff;
  uVar5 = RGE_Game_World::new_game(param_1,param_2,param_3);
  iVar20 = 0;
  uStack_130d = uVar5;
  if (0 < param_1->player_num) {
    do {
      RGE_Base_Game::reset_countdown_timer(rge_base_game,iVar20);
      iVar20 = iVar20 + 1;
    } while (iVar20 < param_1->player_num);
  }
  iVar20 = RGE_Base_Game::campaignGame(rge_base_game);
  if (((iVar20 != 0) || (iVar20 = RGE_Base_Game::randomGame(rge_base_game), iVar20 == 0)) &&
     (VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game), VVar8 == VictoryDefault))
  goto LAB_0052f765;
  iVar20 = RGE_Base_Game::campaignGame(rge_base_game);
  if ((iVar20 == 0) && (iVar20 = RGE_Base_Game::randomGame(rge_base_game), iVar20 != 0)) {
    RGE_Scenario::Set_scenario_name(param_1->scenario,s_);
  }
  VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  switch(VVar8) {
  case VictoryDefault:
  case VictoryStandard:
    iVar20 = rge_base_game->_padding_;
    break;
  case VictoryConquest:
    iVar20 = rge_base_game->_padding_;
    break;
  default:
    goto switchD_0052f009_caseD_2;
  case VictoryTime:
    iVar20 = rge_base_game->_padding_;
    break;
  case VictoryScore:
    iVar20 = rge_base_game->_padding_;
  }
  (**(code **)(iVar20 + 0x20))();
switchD_0052f009_caseD_2:
  MVar9 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
  switch(MVar9) {
  case Tiny:
    pcVar14 = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))();
    goto LAB_0052f0fa;
  case Small:
    iVar20 = rge_base_game->_padding_;
    break;
  case Medium:
    iVar20 = rge_base_game->_padding_;
    break;
  case Large:
    iVar20 = rge_base_game->_padding_;
    break;
  case Huge:
    iVar20 = rge_base_game->_padding_;
    break;
  case Humongous:
    iVar20 = rge_base_game->_padding_;
    break;
  default:
    goto switchD_0052f095_default;
  }
  pcVar14 = (char *)(**(code **)(iVar20 + 0x24))();
LAB_0052f0fa:
  uVar16 = 0xffffffff;
  do {
    pcVar21 = pcVar14;
    if (uVar16 == 0) break;
    uVar16 = uVar16 - 1;
    pcVar21 = pcVar14 + 1;
    cVar1 = *pcVar14;
    pcVar14 = pcVar21;
  } while (cVar1 != '\0');
  uVar16 = ~uVar16;
  pcVar14 = pcVar21 + -uVar16;
  pcVar21 = acStack_130c;
  for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
    *(undefined4 *)pcVar21 = *(undefined4 *)pcVar14;
    pcVar14 = pcVar14 + 4;
    pcVar21 = pcVar21 + 4;
  }
  for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
    *pcVar21 = *pcVar14;
    pcVar14 = pcVar14 + 1;
    pcVar21 = pcVar21 + 1;
  }
switchD_0052f095_default:
  (**(code **)(rge_base_game->_padding_ + 0x24))();
  sprintf();
  puStack_133c = (undefined1 *)0x52f165;
  sprintf();
  iVar20 = RGE_Base_Game::randomGame(rge_base_game);
  if (iVar20 != 0) {
    MVar10 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
    switch(MVar10) {
    case AllWater:
      iVar20 = rge_base_game->_padding_;
      break;
    case MostlyWater:
      iVar20 = rge_base_game->_padding_;
      break;
    case WaterAndLand:
      iVar20 = rge_base_game->_padding_;
      break;
    case MostlyLand:
      iVar20 = rge_base_game->_padding_;
      break;
    case AllLand:
      iVar20 = rge_base_game->_padding_;
      break;
    case Continental:
      iVar20 = rge_base_game->_padding_;
      break;
    case Lake:
      iVar20 = rge_base_game->_padding_;
      break;
    case Hilly:
      iVar20 = rge_base_game->_padding_;
      break;
    case Isthmas:
      iVar20 = rge_base_game->_padding_;
      break;
    default:
      goto switchD_0052f18f_default;
    }
    pcVar14 = (char *)(**(code **)(iVar20 + 0x24))();
    uVar16 = 0xffffffff;
    do {
      pcVar21 = pcVar14;
      if (uVar16 == 0) break;
      uVar16 = uVar16 - 1;
      pcVar21 = pcVar14 + 1;
      cVar1 = *pcVar14;
      pcVar14 = pcVar21;
    } while (cVar1 != '\0');
    uVar16 = ~uVar16;
    pcVar14 = pcVar21 + -uVar16;
    pcVar21 = acStack_1310;
    for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
      *(undefined4 *)pcVar21 = *(undefined4 *)pcVar14;
      pcVar14 = pcVar14 + 4;
      pcVar21 = pcVar21 + 4;
    }
    for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
      *pcVar21 = *pcVar14;
      pcVar14 = pcVar14 + 1;
      pcVar21 = pcVar21 + 1;
    }
switchD_0052f18f_default:
    (**(code **)(rge_base_game->_padding_ + 0x24))();
    sprintf();
    puStack_133c = (undefined1 *)0x52f289;
    sprintf();
  }
  AVar11 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar11 == DefaultAge) {
    iVar20 = rge_base_game->_padding_;
  }
  else {
    iVar20 = rge_base_game->_padding_;
  }
  (**(code **)(iVar20 + 0x20))();
  puStack_133c = (undefined1 *)0x25e4;
  puStack_1340 = (undefined1 *)0x52f2f5;
  puStack_1340 = (undefined1 *)(**(code **)(rge_base_game->_padding_ + 0x24))();
  iStack_1344 = (int)auStack_1220;
  apcStack_135c[5] = (char *)0x52f303;
  sprintf();
  puStack_133c = auStack_1220;
  puStack_1340 = auStack_1020;
  apcStack_135c[5] = auStack_1020;
  iStack_1344 = (int)s__s__s;
  apcStack_135c[4] = (char *)0x52f328;
  sprintf();
  puStack_133c = (undefined1 *)0x52f336;
  RVar12 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  puStack_133c = (undefined1 *)0x100;
  if (RVar12 == DefaultResources) {
    iStack_1344 = 0x10e7;
  }
  else {
    iStack_1344 = RVar12 + 0x25e5;
  }
  puStack_1340 = &stack0xffffece0;
  apcStack_135c[5] = (char *)0x52f361;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  apcStack_135c[5] = &stack0xffffecd4;
  apcStack_135c[4] = (char *)0x25e5;
  apcStack_135c[3] = (char *)0x52f376;
  apcStack_135c[3] = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))();
  apcStack_135c[2] = auStack_1230;
  apcStack_135c[1] = (char *)0x52f384;
  sprintf();
  apcStack_135c[4] = auStack_1230;
  apcStack_135c[3] = auStack_1030;
  apcStack_135c[1] = auStack_1030;
  apcStack_135c[2] = s__s__s;
  apcStack_135c[0] = (char *)0x52f3a9;
  sprintf();
  apcStack_135c[4] = (char *)0x52f3b7;
  RGE_Base_Game::difficulty(rge_base_game);
  apcStack_135c[3] = &stack0xffffecd0;
  apcStack_135c[4] = (char *)0x100;
  iVar20 = rge_base_game->_padding_;
  apcStack_135c[2] = (char *)0x52f3ce;
  iVar13 = RGE_Base_Game::difficulty(rge_base_game);
  apcStack_135c[2] = (char *)(iVar13 + 0x2bd0);
  apcStack_135c[1] = (char *)0x52f3dd;
  (**(code **)(iVar20 + 0x20))();
  apcStack_135c[0] = acStack_123c;
  apcStack_135c[1] = (char *)0x100;
  uStack_1360 = 0x25e0;
  ppcStack_1364 = (char **)0x52f3fa;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  ppcStack_1364 = apcStack_135c + 5;
  ppcStack_1368 = (char **)auStack_1248;
  pcStack_136c = acStack_1148;
  ppcStack_1370 = (char **)0x52f414;
  sprintf();
  ppcStack_1364 = (char **)acStack_1148;
  ppcStack_1368 = apcStack_1048;
  ppcStack_1370 = apcStack_1048;
  pcStack_136c = s__s__s;
  pcStack_1374 = (char *)0x52f439;
  sprintf();
  ppcStack_1364 = (char **)0x52f447;
  iVar20 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  ppcStack_1368 = apcStack_135c + 5;
  ppcStack_1364 = (char **)0x100;
  if (iVar20 == 0) {
    pcStack_136c = (char *)0xfa3;
  }
  else {
    pcStack_136c = (char *)0xfa4;
  }
  ppcStack_1370 = (char **)0x52f46c;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  ppcStack_1370 = apcStack_135c + 2;
  pcStack_1374 = (char *)0x25e9;
  ppcStack_1378 = (char **)0x52f481;
  ppcStack_1378 = (char **)(**(code **)(rge_base_game->_padding_ + 0x24))();
  pcStack_137c = acStack_1258;
  sprintf();
  pcStack_1374 = acStack_1258;
  ppcStack_1378 = (char **)auStack_1058;
  pcStack_137c = s__s__s;
  sprintf(auStack_1058);
  pcStack_1374 = (char *)0x52f4c2;
  iVar20 = RGE_Base_Game::fullVisibility(rge_base_game);
  if (iVar20 == 0) {
    pcStack_1374 = (char *)0xfa4;
  }
  else {
    pcStack_1374 = (char *)0xfa3;
  }
  ppcStack_1378 = (char **)0x52f4dd;
  pcVar14 = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))();
  uVar16 = 0xffffffff;
  do {
    pcVar21 = pcVar14;
    if (uVar16 == 0) break;
    uVar16 = uVar16 - 1;
    pcVar21 = pcVar14 + 1;
    cVar1 = *pcVar14;
    pcVar14 = pcVar21;
  } while (cVar1 != '\0');
  uVar16 = ~uVar16;
  pcVar14 = pcVar21 + -uVar16;
  ppcVar22 = apcStack_135c;
  for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
    *ppcVar22 = *(char **)pcVar14;
    pcVar14 = pcVar14 + 4;
    ppcVar22 = ppcVar22 + 1;
  }
  for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(char *)ppcVar22 = *pcVar14;
    pcVar14 = pcVar14 + 1;
    ppcVar22 = (char **)((int)ppcVar22 + 1);
  }
  ppcStack_1378 = apcStack_135c;
  pcStack_137c = (char *)0x25b8;
  uVar15 = (**(code **)(rge_base_game->_padding_ + 0x24))();
  sprintf(acStack_1260,uVar15);
  pcStack_137c = acStack_1260;
  sprintf(auStack_1060,s__s__s,auStack_1060);
  pcStack_137c = (char *)0x52f556;
  iVar20 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  pcStack_137c = (char *)0x100;
  if (iVar20 == 0) {
    uVar15 = 0xfa4;
  }
  else {
    uVar15 = 0xfa3;
  }
  (**(code **)(rge_base_game->_padding_ + 0x20))(uVar15,&uStack_1360);
  uVar15 = (**(code **)(rge_base_game->_padding_ + 0x24))(0x25ec,&pcStack_136c);
  sprintf(auStack_1270,uVar15);
  sprintf(auStack_1070,s__s__s,auStack_1070,auStack_1270);
  iVar20 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar20 != 0) {
    iVar20 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    if (iVar20 == 0) {
      uVar15 = 0xfa4;
    }
    else {
      uVar15 = 0xfa3;
    }
    pcVar14 = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))(uVar15);
    uVar16 = 0xffffffff;
    do {
      pcVar21 = pcVar14;
      if (uVar16 == 0) break;
      uVar16 = uVar16 - 1;
      pcVar21 = pcVar14 + 1;
      cVar1 = *pcVar14;
      pcVar14 = pcVar21;
    } while (cVar1 != '\0');
    uVar16 = ~uVar16;
    pcVar14 = pcVar21 + -uVar16;
    ppcVar22 = &pcStack_1374;
    for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
      *ppcVar22 = *(char **)pcVar14;
      pcVar14 = pcVar14 + 4;
      ppcVar22 = ppcVar22 + 1;
    }
    for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(char *)ppcVar22 = *pcVar14;
      pcVar14 = pcVar14 + 1;
      ppcVar22 = (char **)((int)ppcVar22 + 1);
    }
    uVar15 = (**(code **)(rge_base_game->_padding_ + 0x24))(0x25bb,&pcStack_1374);
    sprintf(auStack_1270,uVar15);
    sprintf(auStack_1070,s__s__s,auStack_1070,auStack_1270);
  }
  iVar13 = RGE_Base_Game::multiplayerGame(rge_base_game);
  uVar15 = 0x100;
  iVar20 = rge_base_game->_padding_;
  if (iVar13 == 0) {
    pppcVar23 = &ppcStack_1370;
    bVar6 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  else {
    pppcVar23 = &ppcStack_1370;
    bVar6 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  (**(code **)(iVar20 + 0x20))(bVar6 + 0x260e,pppcVar23,uVar15);
  uVar15 = (**(code **)(rge_base_game->_padding_ + 0x24))(0x25f1,&pcStack_137c);
  sprintf(auStack_1280,uVar15);
  sprintf(auStack_1080,s__s__s,auStack_1080,auStack_1280);
  uVar7 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
  (**(code **)(rge_base_game->_padding_ + 0x24))(0x25f0,uVar7);
  sprintf();
  sprintf();
  RGE_Scenario::add_description(param_1->scenario,acStack_100c);
LAB_0052f765:
  if (uVar5 != '\0') {
    param_1[1].world_time = 4;
    *(undefined1 *)&param_1[1].timer = 0;
    param_1[1].old_time = 0;
    iVar20 = RGE_Base_Game::campaignGame(rge_base_game);
    if (((iVar20 == 0) && (iVar20 = RGE_Base_Game::randomGame(rge_base_game), iVar20 != 0)) ||
       (VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game), VVar8 != VictoryDefault)) {
      T_Scenario::Set_victory_all_flag((T_Scenario *)param_1->scenario,0);
      T_Scenario::Set_Multi_Conquest((T_Scenario *)param_1->scenario,0);
      T_Scenario::Set_Multi_Ruins((T_Scenario *)param_1->scenario,0);
      T_Scenario::Set_Multi_Artifacts((T_Scenario *)param_1->scenario,0);
      T_Scenario::Set_Multi_Discoveries((T_Scenario *)param_1->scenario,0);
      T_Scenario::Set_Multi_Exploration((T_Scenario *)param_1->scenario,0);
      T_Scenario::Set_Multi_Gold((T_Scenario *)param_1->scenario,0);
      iVar20 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
      VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
      switch(VVar8) {
      case VictoryDefault:
      case VictoryStandard:
        pTVar3 = (T_Scenario *)param_1->scenario;
        param_1[1].world_time = 0;
        T_Scenario::Set_Multi_Conquest(pTVar3,1);
        break;
      case VictoryConquest:
        pTVar3 = (T_Scenario *)param_1->scenario;
        param_1[1].world_time = 1;
        T_Scenario::Set_Multi_Conquest(pTVar3,1);
        break;
      case VictoryExplore:
        T_Scenario::Set_Multi_Exploration((T_Scenario *)param_1->scenario,iVar20);
        break;
      case VictoryRuins:
        T_Scenario::Set_Multi_Ruins((T_Scenario *)param_1->scenario,iVar20);
        break;
      case VictoryArtifacts:
        T_Scenario::Set_Multi_Artifacts((T_Scenario *)param_1->scenario,iVar20);
        break;
      case VictoryDiscoveries:
        T_Scenario::Set_Multi_Discoveries((T_Scenario *)param_1->scenario,iVar20);
        break;
      case VictoryGold:
        T_Scenario::Set_Multi_Gold((T_Scenario *)param_1->scenario,iVar20);
        break;
      case VictoryTime:
        pTVar3 = (T_Scenario *)param_1->scenario;
        param_1[1].world_time = 2;
        T_Scenario::Set_Multi_Conquest(pTVar3,1);
        break;
      case VictoryScore:
        pTVar3 = (T_Scenario *)param_1->scenario;
        param_1[1].world_time = 3;
        T_Scenario::Set_Multi_Conquest(pTVar3,1);
      }
      T_Scenario::Save_victory_conditions_into_players((T_Scenario *)param_1->scenario,0);
      VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
      if (VVar8 == VictoryTime) {
        *(undefined1 *)&param_1[1].timer = 1;
        param_1[1].old_time = (ulong)(float)iVar20;
      }
      else if ((VVar8 == VictoryScore) && (iVar13 = 1, 1 < param_1->player_num)) {
        do {
          RGE_Victory_Conditions::add_victory_points
                    (param_1->players[iVar13]->victory_conditions,'\0',iVar20,'\x01');
          iVar13 = iVar13 + 1;
        } while (iVar13 < param_1->player_num);
      }
    }
    else {
      iVar20 = RGE_Base_Game::campaignGame(rge_base_game);
      if ((iVar20 != 0) || (iVar20 = RGE_Base_Game::scenarioGame(rge_base_game), iVar20 != 0)) {
        iVar20 = T_Scenario::GetMPVictory((T_Scenario *)param_1->scenario);
        switch(iVar20) {
        case 0:
          param_1[1].world_time = 0;
          break;
        case 1:
          param_1[1].world_time = 1;
          break;
        case 2:
          pTVar3 = (T_Scenario *)param_1->scenario;
          param_1[1].world_time = 3;
          iVar20 = T_Scenario::GetVictoryScore(pTVar3);
          iVar13 = 1;
          if (1 < param_1->player_num) {
            do {
              RGE_Victory_Conditions::add_victory_points
                        (param_1->players[iVar13]->victory_conditions,'\0',iVar20,'\x01');
              iVar13 = iVar13 + 1;
            } while (iVar13 < param_1->player_num);
          }
          break;
        case 3:
          pTVar3 = (T_Scenario *)param_1->scenario;
          param_1[1].world_time = 2;
          *(undefined1 *)&param_1[1].timer = 1;
          iVar20 = T_Scenario::GetVictoryTime(pTVar3);
          param_1[1].old_time = (ulong)(float)iVar20;
        }
      }
    }
    this = (RGE_RMM_Object_Generator *)operator_new(0x1920);
    uStack_4 = 0;
    if (this == (RGE_RMM_Object_Generator *)0x0) {
      pRStack_1314 = (RGE_RMM_Object_Generator *)0x0;
    }
    else {
      puStack_133c = (undefined1 *)0x52f9e8;
      pRStack_1314 = (RGE_RMM_Object_Generator *)
                     RGE_RMM_Object_Generator::RGE_RMM_Object_Generator
                               (this,param_1->map,(RGE_Random_Map_Module *)0x0,param_1,
                                (RGE_Object_Info *)0x0,'\0');
    }
    uStack_4 = 0xffffffff;
    iVar20 = T_Scenario::Get_Multi_Artifacts((T_Scenario *)param_1->scenario);
    if (0 < iVar20) {
      iVar18 = (int)param_1->player_num;
      iVar13 = 0;
      if (0 < iVar18) {
        ppRVar19 = param_1->players;
        do {
          for (pRVar4 = (*ppRVar19)->objects->list; pRVar4 != (RGE_Object_Node *)0x0;
              pRVar4 = pRVar4->next) {
            if (pRVar4->node->master_obj->id == 0x9f) {
              iVar13 = iVar13 + 1;
            }
          }
          ppRVar19 = ppRVar19 + 1;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      if (0 < iVar20 - iVar13) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,0x9f,iVar20 - iVar13,0);
      }
    }
    iVar20 = T_Scenario::Get_Multi_Discoveries((T_Scenario *)param_1->scenario);
    if (0 < iVar20) {
      iVar18 = (int)param_1->player_num;
      iVar13 = 0;
      if (0 < iVar18) {
        ppRVar19 = param_1->players;
        do {
          for (pRVar4 = (*ppRVar19)->objects->list; pRVar4 != (RGE_Object_Node *)0x0;
              pRVar4 = pRVar4->next) {
            if (pRVar4->node->master_obj->id == 10) {
              iVar13 = iVar13 + 1;
            }
          }
          ppRVar19 = ppRVar19 + 1;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      if (0 < iVar20 - iVar13) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,10,iVar20 - iVar13,0);
      }
    }
    iVar20 = T_Scenario::Get_Multi_Ruins((T_Scenario *)param_1->scenario);
    if (0 < iVar20) {
      iVar18 = (int)param_1->player_num;
      iVar13 = 0;
      if (0 < iVar18) {
        ppRVar19 = param_1->players;
        do {
          for (pRVar4 = (*ppRVar19)->objects->list; pRVar4 != (RGE_Object_Node *)0x0;
              pRVar4 = pRVar4->next) {
            sVar2 = pRVar4->node->master_obj->id;
            if ((sVar2 == 0x9e) || (sVar2 == 0xa3)) {
              iVar13 = iVar13 + 1;
            }
          }
          ppRVar19 = ppRVar19 + 1;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      if (0 < iVar20 - iVar13) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,0x9e,iVar20 - iVar13,0);
      }
    }
    iVar20 = RGE_Base_Game::campaignGame(rge_base_game);
    if ((iVar20 == 0) && (iVar20 = RGE_Base_Game::randomGame(rge_base_game), iVar20 != 0)) {
      if ((param_1[1].world_time == 3) ||
         (iVar20 = debug_rand(s_C__msdev_work_age1_x1_tworld_cpp,0x38d), iVar20 % 100 < 0x32)) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,0x9f,5,param_1->map->map_width / 5);
        param_1[1].old_world_time = 5;
      }
      iVar20 = debug_rand(s_C__msdev_work_age1_x1_tworld_cpp,0x394);
      if (iVar20 % 100 < 0x32) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,0x9e,5,param_1->map->map_width / 5);
        param_1[1].world_time_delta = 5;
      }
    }
    else {
      iVar20 = (int)param_1->player_num;
      param_1[1].old_world_time = 0;
      if (0 < iVar20) {
        ppRVar19 = param_1->players;
        iVar13 = iVar20;
        do {
          for (pRVar4 = (*ppRVar19)->objects->list; pRVar4 != (RGE_Object_Node *)0x0;
              pRVar4 = pRVar4->next) {
            if (pRVar4->node->master_obj->id == 0x9f) {
              param_1[1].old_world_time = param_1[1].old_world_time + 1;
            }
          }
          ppRVar19 = ppRVar19 + 1;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
      }
      param_1[1].world_time_delta = 0;
      if (0 < iVar20) {
        ppRVar19 = param_1->players;
        do {
          for (pRVar4 = (*ppRVar19)->objects->list; pRVar4 != (RGE_Object_Node *)0x0;
              pRVar4 = pRVar4->next) {
            sVar2 = pRVar4->node->master_obj->id;
            if ((sVar2 == 0x9e) || (sVar2 == 0xa3)) {
              param_1[1].world_time_delta = param_1[1].world_time_delta + 1;
            }
          }
          ppRVar19 = ppRVar19 + 1;
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
      }
    }
    (**(code **)pRStack_1314->_padding_)();
    if (pRStack_1314 != (RGE_RMM_Object_Generator *)0x0) {
      RGE_Random_Map_Module::~RGE_Random_Map_Module((RGE_Random_Map_Module *)pRStack_1314);
      operator_delete(pRStack_1314);
    }
  }
  iVar20 = TRIBE_Game::allowTrading((TRIBE_Game *)rge_base_game);
  if ((iVar20 == 0) && (iVar20 = 1, 1 < param_1->player_num)) {
    do {
      (**(code **)(param_1->effects->_padding_ + 8))();
      iVar20 = iVar20 + 1;
    } while (iVar20 < param_1->player_num);
  }
  iVar20 = TRIBE_Game::longCombat((TRIBE_Game *)rge_base_game);
  if ((iVar20 == 1) && (iVar20 = 1, 1 < param_1->player_num)) {
    do {
      (**(code **)(param_1->effects->_padding_ + 8))();
      iVar20 = iVar20 + 1;
    } while (iVar20 < param_1->player_num);
  }
  iVar20 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  if ((iVar20 == 0) &&
     (iVar20 = T_Scenario::GetScenarioOption((T_Scenario *)param_1->scenario,2), iVar20 == 0)) {
    iVar20 = 1;
    if (1 < param_1->player_num) {
      do {
        (**(code **)(param_1->effects->_padding_ + 8))();
        iVar20 = iVar20 + 1;
      } while (iVar20 < param_1->player_num);
    }
  }
  else {
    iVar20 = 1;
    if (1 < param_1->player_num) {
      do {
        (**(code **)(param_1->effects->_padding_ + 8))();
        iVar20 = iVar20 + 1;
      } while (iVar20 < param_1->player_num);
    }
  }
  RVar12 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  if (RVar12 == LowResource) {
    iVar20 = 1;
    if (1 < param_1->player_num) {
      do {
        iVar13 = iVar20 + 1;
        *param_1->players[iVar20]->attributes = 200.0;
        param_1->players[iVar20]->attributes[1] = 200.0;
        param_1->players[iVar20]->attributes[3] = 0.0;
        param_1->players[iVar20]->attributes[2] = 100.0;
        iVar20 = iVar13;
      } while (iVar13 < param_1->player_num);
    }
  }
  else if (RVar12 == MediumResources) {
    iVar20 = 1;
    if (1 < param_1->player_num) {
      do {
        iVar13 = iVar20 + 1;
        *param_1->players[iVar20]->attributes = 500.0;
        param_1->players[iVar20]->attributes[1] = 500.0;
        param_1->players[iVar20]->attributes[3] = 0.0;
        param_1->players[iVar20]->attributes[2] = 250.0;
        iVar20 = iVar13;
      } while (iVar13 < param_1->player_num);
    }
  }
  else if ((RVar12 == HighResources) && (iVar20 = 1, 1 < param_1->player_num)) {
    do {
      iVar13 = iVar20 + 1;
      *param_1->players[iVar20]->attributes = 1000.0;
      param_1->players[iVar20]->attributes[1] = 1000.0;
      param_1->players[iVar20]->attributes[3] = 0.0;
      param_1->players[iVar20]->attributes[2] = 750.0;
      iVar20 = iVar13;
    } while (iVar13 < param_1->player_num);
  }
  uVar5 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if ((uVar5 != '\0') && (iVar20 = 1, 1 < param_1->player_num)) {
    do {
      iVar13 = iVar20 + 1;
      *param_1->players[iVar20]->attributes = 20000.0;
      param_1->players[iVar20]->attributes[1] = 20000.0;
      param_1->players[iVar20]->attributes[3] = 10000.0;
      param_1->players[iVar20]->attributes[2] = 5000.0;
      iVar20 = iVar13;
    } while (iVar13 < param_1->player_num);
  }
  AVar11 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar11 == ToolAge) {
    iVar20 = 1;
    if (1 < param_1->player_num) {
      do {
        TRIBE_Player::rev_tech((TRIBE_Player *)param_1->players[iVar20],0x19);
        iVar20 = iVar20 + 1;
      } while (iVar20 < param_1->player_num);
    }
  }
  else if (AVar11 == BronzeAge) {
    iVar20 = 1;
    if (1 < param_1->player_num) {
      do {
        TRIBE_Player::rev_tech((TRIBE_Player *)param_1->players[iVar20],0x17);
        iVar20 = iVar20 + 1;
      } while (iVar20 < param_1->player_num);
    }
  }
  else if ((AVar11 == IronAge) && (iVar20 = 1, 1 < param_1->player_num)) {
    do {
      TRIBE_Player::rev_tech((TRIBE_Player *)param_1->players[iVar20],0x18);
      iVar20 = iVar20 + 1;
    } while (iVar20 < param_1->player_num);
  }
  uVar5 = RGE_Base_Game::check_prog_argument(rge_base_game,s_NOFOODCAP);
  if (uVar5 == '\0') {
    uVar5 = RGE_Base_Game::check_prog_argument(rge_base_game,s_SYSTEM2);
    iVar20 = 1;
    if (uVar5 == '\0') {
      if (1 < param_1->player_num) {
        do {
          bVar6 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
          RGE_Player::new_attribute_num(param_1->players[iVar20],0x20,(float)bVar6);
          RGE_Player::new_attribute_num(param_1->players[iVar20],0x21,0.0);
          RGE_Player::new_attribute_num(param_1->players[iVar20],0x1e,500.0);
          RGE_Player::new_attribute_num(param_1->players[iVar20],0x2d,1.0);
          puStack_133c = (undefined1 *)0x53009c;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\0','\0',0x14,2,1);
          puStack_133c = (undefined1 *)0x5300b1;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\0','\x01',0x2b,1,1);
          puStack_133c = (undefined1 *)0x5300c7;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\0','\x02',0x2c,1,1);
          puStack_133c = (undefined1 *)0x5300de;
          RGE_Victory_Conditions::add_points_high_attribute_once
                    (param_1->players[iVar20]->victory_conditions,'\0','\x03',0x28,1,0x19);
          puStack_133c = (undefined1 *)0x5300f4;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x01','\x04',0x31,100,1);
          puStack_133c = (undefined1 *)0x53010a;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x01','\t',0x35,0x3c,1);
          puStack_133c = (undefined1 *)0x53011f;
          RGE_Victory_Conditions::add_points_high_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x01','\x05',0x25,1,1);
          puStack_133c = (undefined1 *)0x530135;
          RGE_Victory_Conditions::add_points_high_attribute_once
                    (param_1->players[iVar20]->victory_conditions,'\x01','\x06',0x25,1,0x19);
          puStack_133c = (undefined1 *)0x53014b;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x01','\a',0x16,3,1);
          iVar13 = RGE_Base_Game::fullVisibility(rge_base_game);
          if (iVar13 == 0) {
            puStack_133c = (undefined1 *)0x530170;
            RGE_Victory_Conditions::add_points_highest_attribute
                      (param_1->players[iVar20]->victory_conditions,'\x01','\b',0x16,1,0x19);
          }
          puStack_133c = (undefined1 *)0x530187;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x02','\n',0x29,1,2);
          puStack_133c = (undefined1 *)0x53019e;
          RGE_Victory_Conditions::add_points_highest_attribute
                    (param_1->players[iVar20]->victory_conditions,'\x02','\v',0x29,1,0x19);
          puStack_133c = (undefined1 *)0x5301b5;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x02','\f',0xe,1,10);
          puStack_133c = (undefined1 *)0x5301cc;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x02','\r',7,1,10);
          puStack_133c = (undefined1 *)0x5301e3;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x02','\x0e',0x34,1,3);
          puStack_133c = (undefined1 *)0x5301fa;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x02','\x10',0x37,1,0x32);
          puStack_133c = (undefined1 *)0x530211;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x02','\x0f',0x36,1,0x32);
          puStack_133c = (undefined1 *)0x530228;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x03','\x11',0x15,1,2);
          puStack_133c = (undefined1 *)0x53023f;
          RGE_Victory_Conditions::add_points_highest_attribute
                    (param_1->players[iVar20]->victory_conditions,'\x03','\x12',0x15,1,0x32);
          puStack_133c = (undefined1 *)0x530257;
          RGE_Victory_Conditions::add_points_attribute_first
                    (param_1->players[iVar20]->victory_conditions,'\x03','\x13',6,3,0x19);
          puStack_133c = (undefined1 *)0x53026f;
          RGE_Victory_Conditions::add_points_attribute_first
                    (param_1->players[iVar20]->victory_conditions,'\x03','\x14',6,4,0x19);
          puStack_133c = (undefined1 *)0x530286;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x04','\x16',0x2d,1,100);
          puStack_133c = (undefined1 *)0x53029d;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (param_1->players[iVar20]->victory_conditions,'\x04','\x17',0x2a,1,100);
          TRIBE_Player::add_population_entry((TRIBE_Player *)param_1->players[iVar20]);
          iVar20 = iVar20 + 1;
        } while (iVar20 < param_1->player_num);
      }
    }
    else if (1 < param_1->player_num) {
      do {
        RGE_Player::new_attribute_num(param_1->players[iVar20],0x20,50.0);
        RGE_Player::new_attribute_num(param_1->players[iVar20],0x21,0.0);
        iVar20 = iVar20 + 1;
      } while (iVar20 < param_1->player_num);
    }
  }
  else {
    iVar20 = 1;
    if (1 < param_1->player_num) {
      do {
        RGE_Player::new_attribute_num(param_1->players[iVar20],0x20,50.0);
        RGE_Player::new_attribute_num(param_1->players[iVar20],0x21,0.0);
        RGE_Player::new_attribute_num(param_1->players[iVar20],0x1e,500.0);
        RGE_Player::new_attribute_num(param_1->players[iVar20],0x1f,5000.0);
        iVar20 = iVar20 + 1;
      } while (iVar20 < param_1->player_num);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uStack_130d;
}

// --------------------------------------------------

// Function: FUN_005303e2
// Address: 005303e2
// XREFS: None
// [HELPER] groups_used: "00000000"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005303e2(RGE_Game_World *param_1)
{
  short sVar1;
  RGE_Player **ppRVar2;
  float fVar3;
  bool bVar4;
  uchar uVar5;
  long lVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  RGE_Player *pRVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  ulong uVar15;
  int *piVar16;
  int iStack_1a4;
  int iStack_1a0;
  int *piStack_19c;
  int iStack_198;
  int iStack_190;
  int aiStack_18c [9];
  int aiStack_168 [9];
  int aiStack_144 [81];
  
  if (param_1->game_state == '\0') {
    if ((((param_1[1].world_time == 2) && (*(char *)&param_1[1].timer != '\0')) &&
        (_DAT_00577578 <= (float)param_1[1].old_time)) &&
       (fVar3 = (float)param_1[1].old_time -
                (param_1->world_time_delta_seconds + param_1->world_time_delta_seconds),
       bVar4 = fVar3 < _DAT_00577578, param_1[1].old_time = (ulong)fVar3, bVar4)) {
      iVar13 = 1;
      sVar1 = param_1->player_num;
      piVar16 = aiStack_18c;
      for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar16 = -1;
        piVar16 = piVar16 + 1;
      }
      if (1 < sVar1) {
        do {
          piVar16 = aiStack_18c + iVar13;
          lVar6 = RGE_Victory_Conditions::get_victory_points
                            (param_1->players[iVar13]->victory_conditions);
          ppRVar2 = param_1->players;
          *piVar16 = lVar6;
          iStack_1a4 = 1;
          if ((ppRVar2[iVar13]->allied_victory != '\0') && (iVar9 = 1, 1 < param_1->player_num)) {
            do {
              if (((iVar9 != iVar13) &&
                  ((uVar5 = RGE_Player::relation(param_1->players[iVar13],iVar9), uVar5 == '\0' &&
                   (uVar5 = RGE_Player::relation(param_1->players[iVar9],iVar13), uVar5 == '\0'))))
                 && (param_1->players[iVar9]->allied_victory != '\0')) {
                lVar6 = RGE_Victory_Conditions::get_victory_points
                                  (param_1->players[iVar9]->victory_conditions);
                iStack_1a4 = iStack_1a4 + 1;
                *piVar16 = *piVar16 + lVar6;
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < param_1->player_num);
          }
          sVar1 = param_1->player_num;
          iVar13 = iVar13 + 1;
          *piVar16 = *piVar16 / iStack_1a4;
        } while (iVar13 < sVar1);
      }
      iVar13 = 1;
      pRVar10 = (RGE_Player *)0x0;
      iVar9 = -1;
      if (1 < param_1->player_num) {
        do {
          if (iVar9 < aiStack_18c[iVar13]) {
            pRVar10 = param_1->players[iVar13];
            iVar9 = aiStack_18c[iVar13];
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < param_1->player_num);
      }
      if (pRVar10 != (RGE_Player *)0x0) {
        RGE_Player::win_game_now(pRVar10);
        param_1->game_end_condition = 'g';
      }
    }
    if ((0 < (int)param_1[1].old_world_time) || (0 < (int)param_1[1].world_time_delta)) {
      uVar12 = (uint)param_1->player_num;
      if (0 < (int)uVar12) {
        piVar16 = aiStack_18c;
        for (uVar11 = uVar12 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
          *piVar16 = 0;
          piVar16 = piVar16 + 1;
        }
        piVar16 = aiStack_168;
        for (uVar11 = uVar12 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
          *piVar16 = -1;
          piVar16 = piVar16 + 1;
        }
      }
      iStack_198 = 0;
      iStack_1a4 = 1;
      if (1 < (int)uVar12) {
        piStack_19c = (int *)0x0;
        piVar16 = aiStack_18c;
        do {
          if (aiStack_168[iStack_1a4] == -1) {
            aiStack_168[iStack_1a4] = iStack_198;
            iVar9 = *piVar16;
            pRVar10 = param_1->players[iStack_1a4];
            aiStack_144[iVar9 + (int)piStack_19c] = (int)pRVar10;
            iVar9 = iVar9 + 1;
            uVar5 = pRVar10->allied_victory;
            *piVar16 = iVar9;
            if ((uVar5 != '\0') && (iStack_1a0 = 1, 1 < (int)uVar12)) {
              piVar8 = aiStack_144 + (int)piStack_19c + iVar9;
              do {
                piVar14 = piVar8;
                if ((((aiStack_168[iStack_1a0] == -1) &&
                     (param_1->players[iStack_1a0]->allied_victory != '\0')) &&
                    (uVar5 = RGE_Player::relation(param_1->players[iStack_1a4],iStack_1a0),
                    uVar5 == '\0')) &&
                   (uVar5 = RGE_Player::relation(param_1->players[iStack_1a0],iStack_1a4),
                   uVar5 == '\0')) {
                  ppRVar2 = param_1->players;
                  iVar9 = iVar9 + 1;
                  aiStack_168[iStack_1a0] = iStack_198;
                  piVar14 = piVar8 + 1;
                  pRVar10 = ppRVar2[iStack_1a0];
                  *piVar16 = iVar9;
                  *piVar8 = (int)pRVar10;
                }
                iStack_1a0 = iStack_1a0 + 1;
                piVar8 = piVar14;
              } while (iStack_1a0 < param_1->player_num);
            }
            iStack_198 = iStack_198 + 1;
            piStack_19c = (int *)((int)piStack_19c + 9);
            piVar16 = piVar16 + 1;
          }
          uVar12 = (uint)param_1->player_num;
          iStack_1a4 = iStack_1a4 + 1;
        } while (iStack_1a4 < (int)uVar12);
      }
      if ((0 < (int)param_1[1].old_world_time) && (0 < iStack_198)) {
        piVar16 = aiStack_144;
        piStack_19c = aiStack_18c;
        iStack_190 = iStack_198;
        do {
          uVar15 = 0;
          iVar9 = *piStack_19c;
          iVar13 = iVar9;
          if (0 < iVar9) {
            do {
              iVar7 = __ftol();
              uVar15 = uVar15 + iVar7;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
          }
          if (uVar15 == param_1[1].old_world_time) {
            pRVar10 = (RGE_Player *)*piVar16;
            fVar3 = *(float *)(pRVar10[3].groups_used + 0x46);
            if (fVar3 == _DAT_00577580) {
              piVar8 = piVar16;
              iVar13 = iVar9;
              if (0 < iVar9) {
                do {
                  iVar13 = iVar13 + -1;
                  *(undefined4 *)(*(int *)(*piVar8 + 0x50) + 0xdc) = 0x3f800000;
                  piVar8 = piVar8 + 1;
                } while (iVar13 != 0);
              }
              if (param_1[1].world_time == 0) {
                piVar8 = piVar16;
                if (0 < iVar9) {
                  do {
                    iVar9 = iVar9 + -1;
                    *(undefined4 *)(*piVar8 + 0x844) = 0x44fa0000;
                    piVar8 = piVar8 + 1;
                  } while (iVar9 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))(0x72,(int)pRVar10->id,0,0,0);
              }
            }
            else if ((_DAT_00577578 <= fVar3) && (param_1[1].world_time == 0)) {
              fVar3 = fVar3 - (param_1->world_time_delta_seconds + param_1->world_time_delta_seconds
                              );
              piVar8 = piVar16;
              if (0 < iVar9) {
                do {
                  iVar9 = iVar9 + -1;
                  *(float *)(*piVar8 + 0x844) = fVar3;
                  piVar8 = piVar8 + 1;
                } while (iVar9 != 0);
              }
              if (fVar3 < _DAT_00577578) {
                RGE_Player::win_game_now(pRVar10);
                param_1->game_end_condition = 'e';
              }
            }
          }
          else {
            iVar13 = *piVar16;
            if (*(int *)(iVar13 + 0x844) != -0x40800000) {
              piVar8 = piVar16;
              iVar7 = iVar9;
              if (0 < iVar9) {
                do {
                  iVar7 = iVar7 + -1;
                  *(undefined4 *)(*(int *)(*piVar8 + 0x50) + 0xdc) = 0;
                  piVar8 = piVar8 + 1;
                } while (iVar7 != 0);
              }
              if (param_1[1].world_time == 0) {
                piVar8 = piVar16;
                if (0 < iVar9) {
                  do {
                    iVar9 = iVar9 + -1;
                    *(undefined4 *)(*piVar8 + 0x844) = 0xbf800000;
                    piVar8 = piVar8 + 1;
                  } while (iVar9 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))
                          (0x73,(int)*(short *)(iVar13 + 0x4a),0,0,0);
              }
            }
          }
          piStack_19c = piStack_19c + 1;
          piVar16 = piVar16 + 9;
          iStack_190 = iStack_190 + -1;
        } while (iStack_190 != 0);
      }
      if ((0 < (int)param_1[1].world_time_delta) && (0 < iStack_198)) {
        piVar16 = aiStack_144;
        piStack_19c = aiStack_18c;
        iStack_190 = iStack_198;
        do {
          uVar15 = 0;
          iVar9 = *piStack_19c;
          iVar13 = iVar9;
          if (0 < iVar9) {
            do {
              iVar7 = __ftol();
              uVar15 = uVar15 + iVar7;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
          }
          if (uVar15 == param_1[1].world_time_delta) {
            pRVar10 = (RGE_Player *)*piVar16;
            fVar3 = *(float *)(pRVar10[3].groups_used + 0x42);
            if (fVar3 == _DAT_00577580) {
              piVar8 = piVar16;
              iVar13 = iVar9;
              if (0 < iVar9) {
                do {
                  iVar13 = iVar13 + -1;
                  *(undefined4 *)(*(int *)(*piVar8 + 0x50) + 0xd8) = 0x3f800000;
                  piVar8 = piVar8 + 1;
                } while (iVar13 != 0);
              }
              if (param_1[1].world_time == 0) {
                piVar8 = piVar16;
                if (0 < iVar9) {
                  do {
                    iVar9 = iVar9 + -1;
                    *(undefined4 *)(*piVar8 + 0x840) = 0x44fa0000;
                    piVar8 = piVar8 + 1;
                  } while (iVar9 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))(0x74,(int)pRVar10->id,0,0,0);
              }
            }
            else if ((_DAT_00577578 <= fVar3) && (param_1[1].world_time == 0)) {
              fVar3 = fVar3 - (param_1->world_time_delta_seconds + param_1->world_time_delta_seconds
                              );
              piVar8 = piVar16;
              if (0 < iVar9) {
                do {
                  iVar9 = iVar9 + -1;
                  *(float *)(*piVar8 + 0x840) = fVar3;
                  piVar8 = piVar8 + 1;
                } while (iVar9 != 0);
              }
              if (fVar3 < _DAT_00577578) {
                RGE_Player::win_game_now(pRVar10);
                param_1->game_end_condition = 'f';
              }
            }
          }
          else {
            iVar13 = *piVar16;
            if (*(int *)(iVar13 + 0x840) != -0x40800000) {
              piVar8 = piVar16;
              iVar7 = iVar9;
              if (0 < iVar9) {
                do {
                  iVar7 = iVar7 + -1;
                  *(undefined4 *)(*(int *)(*piVar8 + 0x50) + 0xd8) = 0;
                  piVar8 = piVar8 + 1;
                } while (iVar7 != 0);
              }
              if (param_1[1].world_time == 0) {
                piVar8 = piVar16;
                if (0 < iVar9) {
                  do {
                    iVar9 = iVar9 + -1;
                    *(undefined4 *)(*piVar8 + 0x840) = 0xbf800000;
                    piVar8 = piVar8 + 1;
                  } while (iVar9 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))
                          (0x75,(int)*(short *)(iVar13 + 0x4a),0,0,0);
              }
            }
          }
          piStack_19c = piStack_19c + 1;
          piVar16 = piVar16 + 9;
          iStack_190 = iStack_190 + -1;
        } while (iStack_190 != 0);
      }
    }
  }
  RGE_Game_World::check_game_state(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00530a65
// Address: 00530a65
// XREFS: None
int __thiscall FUN_00530a65(int param_1,uchar param_2,int param_3)
{
  TRIBE_Player *this;
  int iVar1;
  
  iVar1 = 1;
  if (1 < *(short *)(param_1 + 0x3c)) {
    do {
      this = *(TRIBE_Player **)(*(int *)(param_1 + 0x40) + iVar1 * 4);
      if (this != (TRIBE_Player *)0x0) {
        TRIBE_Player::get_achievement(this,param_2,*(char **)(param_3 + iVar1 * 4));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(short *)(param_1 + 0x3c));
  }
  return (int)*(short *)(param_1 + 0x3c);
}

// --------------------------------------------------

// Function: FUN_00530ab1
// Address: 00530ab1
// XREFS: None
void __thiscall FUN_00530ab1(int param_1,short param_2)
{
  TRIBE_Command::command_cheat
            (*(TRIBE_Command **)(param_1 + 0x58),*(short *)(param_1 + 0x7c),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00530ad5
// Address: 00530ad5
// XREFS: None
// [HELPER] die_die_die: " "
void __thiscall FUN_00530ad5(int param_1,short param_2,short param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int *piVar5;
  int iVar6;
  
  iVar2 = RGE_Base_Game::allowCheatCodes(rge_base_game);
  if (iVar2 != 0) {
    switch((int)param_3) {
    case 0:
      if ((0 < param_2) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)
                               (*(int *)(*(int *)(param_1 + 0x40) + param_2 * 4) + 0x28),0x6d,-1.0,
                              -1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make(*(TRIBE_Command **)(param_1 + 0x58),pRVar4,0x112);
        return;
      }
      break;
    case 1:
      if ((0 < param_2) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)
                               (*(int *)(*(int *)(param_1 + 0x40) + param_2 * 4) + 0x28),0x6d,-1.0,
                              -1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make(*(TRIBE_Command **)(param_1 + 0x58),pRVar4,0xf8);
        return;
      }
      break;
    case 2:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x7f,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 3:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x80,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 4:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x81,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 5:
      (**(code **)(**(int **)(param_1 + 0x4c) + 8))(0x82,**(undefined4 **)(param_1 + 0x40));
      return;
    case 6:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x83,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 7:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x84,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 8:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x85,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 9:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x86,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 10:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x87,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 0xb:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x88,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 0xc:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x89,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 0xd:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0x8a,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 0xe:
      if ((0 < param_2) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)
                               (*(int *)(*(int *)(param_1 + 0x40) + param_2 * 4) + 0x28),0x6d,-1.0,
                              -1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make(*(TRIBE_Command **)(param_1 + 0x58),pRVar4,0x182);
        return;
      }
      break;
    case 0xf:
      if (0 < param_2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 8))
                  (0xd7,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4));
        return;
      }
      break;
    case 0x10:
      if ((0 < param_2) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)
                               (*(int *)(*(int *)(param_1 + 0x40) + param_2 * 4) + 0x28),0x6d,-1.0,
                              -1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make(*(TRIBE_Command **)(param_1 + 0x58),pRVar4,0x18d);
        return;
      }
      break;
    case 0x11:
      if (0 < param_2) {
        RGE_Object_List::find_by_master_id
                  (*(RGE_Object_List **)(*(int *)(*(int *)(param_1 + 0x40) + param_2 * 4) + 0x28),
                   0x6d,-1.0,-1.0,'\x01','\x02',(RGE_Static_Object *)0x0);
        return;
      }
      break;
    case 0x12:
      (**(code **)(**(int **)(param_1 + 0x4c) + 8))(0xd8,**(undefined4 **)(param_1 + 0x40));
      return;
    case 0x13:
      (**(code **)(**(int **)(param_1 + 0x4c) + 8))(0xd9,**(undefined4 **)(param_1 + 0x40));
      return;
    case 100:
      iVar2 = 1;
      die_die_die = '\x01';
      if (1 < *(short *)(param_1 + 0x3c)) {
        iVar6 = (int)param_2;
        do {
          if (((iVar2 != iVar6) ||
              (iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar6 * 4) + 0x1c))(iVar2)
              , iVar3 == 0)) ||
             (iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar2 * 4) + 0x1c))(iVar6),
             iVar3 == 0)) {
            for (piVar5 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + iVar2 * 4) + 0x28)
                                   + 4); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[1]) {
              piVar1 = (int *)*piVar5;
              if ((*(byte *)(piVar1 + 0x12) < 3) && (*(short *)(piVar1[2] + 0x14) != 1)) {
                (**(code **)(*piVar1 + 0x6c))();
              }
            }
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(short *)(param_1 + 0x3c));
        return;
      }
      break;
    case 0x65:
      piVar5 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + param_2 * 4) + 0x28) + 4);
      if (piVar5 != (int *)0x0) {
        do {
          piVar1 = (int *)*piVar5;
          if ((*(byte *)(piVar1 + 0x12) < 3) && (*(short *)(piVar1[2] + 0x14) != 1)) {
            (**(code **)(*piVar1 + 0x6c))();
          }
          piVar5 = (int *)piVar5[1];
        } while (piVar5 != (int *)0x0);
        return;
      }
      break;
    case 0x66:
      RGE_Player::win_game_now(*(RGE_Player **)(*(int *)(param_1 + 0x40) + param_2 * 4));
      *(undefined1 *)(param_1 + 0x1e) = 0x68;
      return;
    case 0x67:
      RGE_Player::loss_if_game_on(*(RGE_Player **)(*(int *)(param_1 + 0x40) + param_2 * 4));
      return;
    case 200:
    case 0xc9:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xcd:
    case 0xce:
    case 0xcf:
    case 0xd0:
    case 0xd1:
      iVar6 = (int)param_2;
      iVar2 = param_3 + -200;
      if ((((iVar2 != iVar6) ||
           (iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar6 * 4) + 0x1c))(iVar2),
           iVar3 == 0)) ||
          (iVar6 = (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar2 * 4) + 0x1c))(iVar6),
          iVar6 == 0)) &&
         (piVar5 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + iVar2 * 4) + 0x28) + 4),
         piVar5 != (int *)0x0)) {
        do {
          piVar1 = (int *)*piVar5;
          if ((*(byte *)(piVar1 + 0x12) < 3) && (*(short *)(piVar1[2] + 0x14) != 1)) {
            (**(code **)(*piVar1 + 0x6c))();
          }
          piVar5 = (int *)piVar5[1];
        } while (piVar5 != (int *)0x0);
        return;
      }
      break;
    case 0xdc:
      pRVar4 = RGE_Object_List::find_by_master_id
                         (*(RGE_Object_List **)
                           (*(int *)(*(int *)(param_1 + 0x40) + param_2 * 4) + 0x28),0x6d,-1.0,-1.0,
                          '\x01','\x02',(RGE_Static_Object *)0x0);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        TRIBE_Command::command_make(*(TRIBE_Command **)(param_1 + 0x58),pRVar4,0x174);
        return;
      }
      break;
    case 0xe6:
      RGE_Base_Game::set_map_visible(rge_base_game,'\x01');
      piVar5 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
      (**(code **)(*piVar5 + 0x20))(2);
      piVar5 = (int *)(**(code **)(rge_base_game->_padding_ + 0x30))();
      (**(code **)(*piVar5 + 0x20))(2);
      return;
    case 0xe7:
      RGE_Base_Game::set_map_fog(rge_base_game,'\0');
      piVar5 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
      (**(code **)(*piVar5 + 0x20))(2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005310de
// Address: 005310de
// XREFS: None
void __fastcall FUN_005310de(byte *param_1,int param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uchar uVar4;
  char cVar9;
  uint in_EAX;
  undefined1 (*pauVar5) [16];
  byte *pbVar6;
  int iVar7;
  long lVar8;
  char cVar13;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte bVar14;
  byte bVar15;
  char cVar16;
  char *unaff_EBX;
  int unaff_ESI;
  int iVar17;
  byte *unaff_EDI;
  long lVar18;
  char *pcVar19;
  char *pcVar20;
  byte *pbVar21;
  undefined2 in_CS;
  char in_CF;
  bool bVar22;
  bool bVar23;
  undefined1 in_XMM0 [16];
  int iStack_48;
  byte *pbStack_44;
  byte *pbStack_40;
  byte *pbStack_3c;
  byte *pbStack_38;
  byte *pbStack_34;
  char *pcStack_2c;
  char *pcStack_24;
  char *pcStack_20;
  char *pcStack_18;
  char *pcStack_14;
  
  bVar2 = (byte)param_1;
  *unaff_EBX = (*unaff_EBX - bVar2) - in_CF;
  cVar9 = (char)(in_EAX >> 8);
  *(char *)(unaff_ESI + 0xb) = *(char *)(unaff_ESI + 0xb) + cVar9;
  bVar14 = (byte)((uint)param_2 >> 8);
  (unaff_EBX + 0xbdd0053)[(int)param_1] = (unaff_EBX + 0xbdd0053)[(int)param_1] + bVar14;
  *param_1 = *param_1 + bVar2;
  cRam4f00530c = cRam4f00530c + bVar14;
  cVar16 = (char)((uint)unaff_EBX >> 8);
  unaff_EBX[0xc] = unaff_EBX[0xc] + cVar16;
  unaff_EDI[-0x2cffacf4] = unaff_EDI[-0x2cffacf4] + cVar9;
  cVar16 = cVar16 * '\x02';
  pcStack_14 = (char *)CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar16,(char)unaff_EBX));
  cVar13 = (char)((uint)param_1 >> 8);
  *pcStack_14 = *pcStack_14 + cVar13;
  pcStack_14[-0x50ffacf3] = pcStack_14[-0x50ffacf3] + ((byte)in_EAX | 0x53);
  pauVar5 = (undefined1 (*) [16])(in_EAX | 0xdff0053);
  pcStack_18 = pcStack_14;
  *param_1 = *param_1 + cVar13;
  pcStack_20 = pcStack_14;
  unaff_EDI[0xe] = unaff_EDI[0xe] + bVar14;
  pcStack_24 = pcStack_14;
  unaff_EDI[-0x36ffacf2] = unaff_EDI[-0x36ffacf2] + cVar13;
  pcStack_2c = pcStack_14;
  bVar15 = (char)unaff_EBX + cVar9;
  pbStack_34 = (byte *)CONCAT31((int3)((uint)pcStack_14 >> 8),bVar15);
  (*pauVar5)[0xf] = (*pauVar5)[0xf] + cVar9;
  pbStack_38 = pbStack_34;
  *(char *)(unaff_ESI + -0x46ffacf1) = *(char *)(unaff_ESI + -0x46ffacf1) + bVar15;
  rcpps(in_XMM0,*pauVar5);
  *unaff_EDI = *unaff_EDI >> 1 | *unaff_EDI << 7;
  pbStack_3c = pbStack_34;
  (*pauVar5)[param_2] = (*pauVar5)[param_2] + cVar16;
  pbStack_40 = pbStack_34;
  *(char *)(param_2 + 0x10) = *(char *)(param_2 + 0x10) + cVar16;
  pbStack_44 = pbStack_34;
  pbVar6 = (byte *)(unaff_ESI + -0x28ffacf0);
  bVar1 = *pbVar6;
  *pbVar6 = *pbVar6 + bVar14;
  bVar3 = (byte)param_2;
  *pbStack_34 = *pbStack_34 + bVar3 + CARRY1(bVar1,bVar14);
  *param_1 = *param_1 + (char)pauVar5;
  bVar1 = *pbStack_34;
  *param_1 = *param_1 | bVar2;
  iVar10 = CONCAT31((int3)((uint)param_1 >> 8),bVar2 | *pbStack_34);
  bVar2 = (char)pauVar5 + bVar1 + 5 | 0xd;
  iStack_48 = CONCAT22((short)((uint)iStack_48 >> 0x10),in_CS);
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < CARRY1(bVar3,*pbStack_34);
  bVar1 = bVar1 - CARRY1(bVar3,*pbStack_34);
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 + 0x15;
  bVar22 = 0xea < bVar2 || CARRY1(bVar1,bVar23);
  bVar1 = bVar1 + bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  bVar2 = bVar1 - 0x1c;
  bVar23 = bVar1 < 0x1c || bVar2 < bVar22;
  bVar2 = bVar2 - bVar22;
  bVar1 = bVar2 - 0x1c;
  bVar22 = bVar2 < 0x1c || bVar1 < bVar23;
  bVar1 = bVar1 - bVar23;
  pbVar6 = (byte *)CONCAT31((int3)((uint)pauVar5 >> 8),bVar1);
  bVar23 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar22;
  *pbVar6 = (*pbVar6 - bVar15) - bVar22;
  bVar22 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar23;
  *pbVar6 = (*pbVar6 - bVar15) - bVar23;
  bVar23 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar22;
  *pbVar6 = (*pbVar6 - bVar15) - bVar22;
  bVar22 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar23;
  *pbVar6 = (*pbVar6 - bVar15) - bVar23;
  bVar23 = *pbVar6 < bVar15 || (byte)(*pbVar6 - bVar15) < bVar22;
  *pbVar6 = (*pbVar6 - bVar15) - bVar22;
  bVar22 = bVar1 < 0x1c || (byte)(bVar1 - 0x1c) < bVar23;
  bVar2 = (bVar1 - 0x1c) - bVar23;
  bVar1 = bVar2 - 0x1c;
  bVar23 = bVar2 < 0x1c || bVar1 < bVar22;
  bVar1 = bVar1 - bVar22;
  bVar2 = bVar1 - 0x1c;
  bVar22 = bVar1 < 0x1c || bVar2 < bVar23;
  bVar2 = bVar2 - bVar23;
  bVar1 = bVar2 - 0x1c;
  bVar3 = bVar1 - bVar22;
  *(uint *)((int)&iStack_48 + (int)pbStack_34) =
       (*(int *)((int)&iStack_48 + (int)pbStack_34) - (int)pbStack_34) -
       (uint)(bVar3 < 0x1c || (byte)(bVar3 - 0x1c) < (bVar2 < 0x1c || bVar1 < bVar22));
  pbVar6 = pbStack_3c;
  iVar17 = 1;
  lVar18 = 0;
  iStack_48 = 1;
  if (1 < *(short *)(iVar10 + 0x3c)) {
    do {
      iVar7 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar10 + 0x40) + iVar17 * 4));
      if (iVar7 == 0) {
        lVar8 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)
                            (*(int *)(*(int *)(iVar10 + 0x40) + iVar17 * 4) + 0x34),(uchar)pbVar6);
        if (lVar18 < lVar8) {
          lVar18 = RGE_Victory_Conditions::get_victory_points_group
                             (*(RGE_Victory_Conditions **)
                               (*(int *)(*(int *)(iVar10 + 0x40) + iVar17 * 4) + 0x34),(uchar)pbVar6
                             );
          iStack_48 = iVar17;
        }
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < *(short *)(iVar10 + 0x3c));
  }
  *(long *)pbStack_40 = lVar18;
  iVar17 = iStack_48 * 4;
  pbStack_40[4] = *(byte *)(*(int *)(*(int *)(iVar10 + 0x40) + iVar17) + 0x54);
  uVar11 = 0xffffffff;
  pcVar19 = *(char **)(*(int *)(*(int *)(iVar10 + 0x40) + iVar17) + 0x44);
  do {
    pcVar20 = pcVar19;
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    pcVar20 = pcVar19 + 1;
    cVar16 = *pcVar19;
    pcVar19 = pcVar20;
  } while (cVar16 != '\0');
  uVar11 = ~uVar11;
  pbStack_3c = (byte *)0x0;
  pbVar6 = (byte *)(pcVar20 + -uVar11);
  pbVar21 = pbStack_40 + 5;
  for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pbVar21 = *(undefined4 *)pbVar6;
    pbVar6 = pbVar6 + 4;
    pbVar21 = pbVar21 + 4;
  }
  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *pbVar21 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    pbVar21 = pbVar21 + 1;
  }
  iVar7 = 1;
  if (1 < *(short *)(iVar10 + 0x3c)) {
    do {
      if (((iVar7 != iStack_48) &&
          (uVar4 = RGE_Player::relation
                             (*(RGE_Player **)(*(int *)(iVar10 + 0x40) + iVar7 * 4),iStack_48),
          uVar4 == '\0')) &&
         (uVar4 = RGE_Player::relation(*(RGE_Player **)(*(int *)(iVar10 + 0x40) + iVar17),iVar7),
         uVar4 == '\0')) {
        pbStack_3c = (byte *)((int)pbStack_3c + 1);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(short *)(iVar10 + 0x3c));
  }
  pbStack_40[0x15] = (byte)pbStack_3c;
  return;
}

// --------------------------------------------------

// Function: FUN_00531343
// Address: 00531343
// XREFS: None
void __fastcall FUN_00531343(TRIBE_World *param_1)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  int iVar8;
  long *plVar9;
  char *pcVar10;
  long *plVar11;
  int iStack_270;
  TRIBE_Game_Options TStack_268;
  char cStack_1fc;
  char cStack_1fb;
  char acStack_1fa [34];
  uint uStack_1d8;
  TRIBE_Zone_High_Score_Info TStack_1d4;
  TRIBE_Zone_High_Score_Info TStack_1bc;
  TRIBE_Zone_High_Score_Info TStack_1a4;
  TRIBE_Zone_High_Score_Info TStack_18c;
  TRIBE_Zone_High_Score_Info TStack_174;
  long alStack_14c [76];
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  ushort uStack_1a;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  uchar uStack_15;
  uchar uStack_14;
  undefined1 uStack_13;
  uchar uStack_12;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1->sent_zone_score == 0) {
    param_1->sent_zone_score = 1;
    cStack_1fc = '\0';
    iStack_270._0_1_ = '\0';
    iVar8 = 1;
    cVar1 = '\0';
    if (1 < (short)param_1->_padding_) {
      do {
        iStack_270._0_1_ = cVar1;
        iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1->_padding_ + iVar8 * 4));
        if (iVar2 == 0) {
          cStack_1fc = cStack_1fc + '\x01';
        }
        else {
          iStack_270._0_1_ = (char)iStack_270 + '\x01';
        }
        iVar8 = iVar8 + 1;
        cVar1 = (char)iStack_270;
      } while (iVar8 < (short)param_1->_padding_);
    }
    cStack_1fb = (char)iStack_270;
    pcVar3 = RGE_Scenario::Get_scenario_name((RGE_Scenario *)param_1->_padding_);
    uVar5 = 0xffffffff;
    do {
      pcVar10 = pcVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar10 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar10;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar3 = pcVar10 + -uVar5;
    pcVar10 = acStack_1fa;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar10 = pcVar10 + 4;
    }
    uVar6 = param_1->_padding_;
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar10 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar10 = pcVar10 + 1;
    }
    uStack_1d8 = uVar6 / 1000;
    TRIBE_World::fill_in_score(param_1,&TStack_1d4,0xff);
    TRIBE_World::fill_in_score(param_1,&TStack_1bc,2);
    TRIBE_World::fill_in_score(param_1,&TStack_1a4,1);
    TRIBE_World::fill_in_score(param_1,&TStack_18c,0);
    TRIBE_World::fill_in_score(param_1,&TStack_174,3);
    iStack_270 = 1;
    if (1 < (short)param_1->_padding_) {
      iVar8 = param_1->_padding_;
      plVar7 = alStack_14c;
      do {
        uVar5 = 0xffffffff;
        pcVar3 = *(char **)(*(int *)(iVar8 + iStack_270 * 4) + 0x44);
        do {
          pcVar10 = pcVar3;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar10 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar10;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        plVar9 = (long *)(pcVar10 + -uVar5);
        plVar11 = plVar7 + -4;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *plVar11 = *plVar9;
          plVar9 = plVar9 + 1;
          plVar11 = plVar11 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(char *)plVar11 = (char)*plVar9;
          plVar9 = (long *)((int)plVar9 + 1);
          plVar11 = (long *)((int)plVar11 + 1);
        }
        lVar4 = RGE_Victory_Conditions::get_victory_points
                          (*(RGE_Victory_Conditions **)(*(int *)(iVar8 + iStack_270 * 4) + 0x34));
        *plVar7 = lVar4;
        iVar8 = iStack_270 + -1;
        *(bool *)(plVar7 + 1) =
             *(char *)(*(int *)(param_1->_padding_ + iStack_270 * 4) + 0x80) == '\x01';
        iVar2 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar8);
        *(char *)((int)plVar7 + 5) = (char)iVar2;
        *(char *)((int)plVar7 + 6) = rge_base_game[1].save_music_file[iStack_270 * 4 + -0x50];
        iVar2 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,iVar8);
        *(char *)((int)plVar7 + 7) = (char)iVar2;
        iVar2 = RGE_Base_Game::playerTeam(rge_base_game,iVar8);
        iVar8 = param_1->_padding_;
        *(char *)(plVar7 + 2) = (char)iVar2;
        *(char *)((int)plVar7 + 9) = (char)comm->WasKicked[iStack_270 + -1];
        plVar7[3] = -1;
        plVar7[4] = -1;
        plVar7[5] = -1;
        for (pcVar3 = *(char **)(*(int *)(*(int *)(iVar8 + iStack_270 * 4) + 0x83c) + 4);
            pcVar3 != (char *)0x0; pcVar3 = *(char **)(pcVar3 + 0xc)) {
          cVar1 = *pcVar3;
          if (cVar1 == '\0') {
            plVar7[3] = *(long *)(pcVar3 + 8);
          }
          else if (cVar1 == '\x01') {
            plVar7[4] = *(long *)(pcVar3 + 8);
          }
          else if (cVar1 == '\x02') {
            plVar7[5] = *(long *)(pcVar3 + 8);
          }
        }
        iStack_270 = iStack_270 + 1;
        plVar7 = plVar7 + 10;
      } while (iStack_270 < (short)param_1->_padding_);
    }
    iVar8 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    uStack_10 = (undefined1)iVar8;
    switch(*(undefined1 *)((int)&param_1->_padding_ + 2)) {
    case 0:
      uStack_f = 0;
      break;
    case 1:
      uStack_f = 1;
      break;
    case 2:
      uStack_f = 6;
      break;
    default:
      uStack_f = 8;
      break;
    case 100:
      uStack_f = 2;
      break;
    case 0x65:
      uStack_f = 3;
      break;
    case 0x66:
      uStack_f = 4;
      break;
    case 0x67:
      uStack_f = 5;
      break;
    case 0x68:
      uStack_f = 7;
    }
    TRIBE_Game::get_tribe_options((TRIBE_Game *)rge_base_game,&TStack_268);
    uStack_1c = (undefined1)TStack_268.mapSizeValue;
    uStack_1b = (undefined1)TStack_268.mapTypeValue;
    uStack_18 = (undefined1)TStack_268.victoryTypeValue;
    uStack_17 = (undefined1)TStack_268.startingAgeValue;
    uStack_16 = (undefined1)TStack_268.resourceLevelValue;
    uStack_15 = TStack_268.fullTechTreeValue;
    uStack_14 = TStack_268.randomizePositionsValue;
    iVar8 = RGE_Base_Game::fullVisibility(rge_base_game);
    uStack_13 = (undefined1)iVar8;
    uStack_12 = TStack_268.deathMatchValue;
    uStack_1a = (ushort)TStack_268.popLimitValue;
    uStack_c = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    TCommunications_Handler::SendZoneMessage
              (*(TCommunications_Handler **)(param_1->_padding_ + 0x14),&cStack_1fc,0x1fc);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005316bd
// Address: 005316bd
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Victory_Conditions * __fastcall FUN_005316bd(undefined4 param_1,int *param_2)
{
  long *plVar1;
  RGE_Player *pRVar2;
  float fVar3;
  byte bVar10;
  undefined4 in_EAX;
  int iVar4;
  byte *pbVar5;
  RGE_Victory_Entry *pRVar6;
  RGE_Game_World *pRVar7;
  RGE_Static_Object *pRVar8;
  RGE_Victory_Point_Entry *pRVar9;
  byte bVar11;
  byte bVar12;
  int unaff_EBX;
  RGE_Player *pRVar13;
  int iVar14;
  int unaff_EBP;
  undefined2 in_ES;
  byte in_CF;
  char in_PF;
  char in_AF;
  char in_ZF;
  char in_SF;
  char unaff_retaddr;
  int iStack_28;
  RGE_Victory_Entry **ppRStack_24;
  int iStack_20;
  float fStack_1c;
  int iStack_18;
  long *plStack_14;
  RGE_Player *pRStack_10;
  RGE_Player *pRStack_c;
  RGE_Player *pRStack_8;
  RGE_Victory_Conditions *this;
  
  bVar11 = (byte)unaff_EBX;
  pRVar13 = (RGE_Player *)CONCAT31((int3)((uint)unaff_EBX >> 8),bVar11 * '\x02');
  pbVar5 = (byte *)(unaff_EBP + -0x38ffaceb);
  bVar10 = *pbVar5;
  bVar12 = (byte)((uint)unaff_EBX >> 8);
  *pbVar5 = *pbVar5 + bVar12;
  iVar4 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   CONCAT11(in_SF << 7 | in_ZF << 6 | in_AF << 4 | in_PF << 2 | 2U | in_CF,
                            (char)in_EAX)) + (uint)in_CF + (uint)CARRY1(bVar11,bVar11) + 0x412d00f9
          + (uint)CARRY1(bVar10,bVar12);
  bVar10 = (byte)((uint)iVar4 >> 8);
  bVar12 = (byte)((uint)param_1 >> 8);
  bVar11 = (byte)param_1;
  this = (RGE_Victory_Conditions *)
         CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(bVar12 + bVar10,bVar11));
  pbVar5 = (byte *)(iVar4 + 0x15ef0053 + (uint)CARRY1(bVar12,bVar10));
  *pbVar5 = *pbVar5 + (byte)pbVar5;
  *param_2 = (int)(pbVar5 + *param_2);
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *pbVar5 = *pbVar5 | bVar11;
  *(byte *)&pRVar13->_padding_ = (byte)pRVar13->_padding_ | (byte)pbVar5;
  plStack_14 = (long *)CONCAT22(plStack_14._2_2_,in_ES);
  this->_padding_ = (int)&RGE_Victory_Conditions::_vftable_;
  pRStack_10 = pRVar13;
  pRStack_c = pRVar13;
  pRStack_8 = pRVar13;
  if (unaff_retaddr == '\x01') {
    rge_read((int)pRVar13,&fStack_1c,4);
  }
  else {
    fStack_1c = 0.0;
  }
  plVar1 = &this->list_num;
  plStack_14 = plVar1;
  rge_read((int)pRVar13,plVar1,4);
  rge_read((int)pRVar13,&this->victory,1);
  ppRStack_24 = &this->victory_list;
  *ppRStack_24 = (RGE_Victory_Entry *)0x0;
  this->player = pRStack_c;
  iVar4 = 0;
  if (0 < *plVar1) {
    do {
      pRVar6 = (RGE_Victory_Entry *)calloc(1,0x34);
      rge_read((int)pRVar13,pRVar6,1);
      rge_read((int)pRVar13,&pRVar6->obj_type,4);
      rge_read((int)pRVar13,&iStack_20,4);
      rge_read((int)pRVar13,&pRVar6->x0,4);
      rge_read((int)pRVar13,&pRVar6->y0,4);
      rge_read((int)pRVar13,&pRVar6->x1,4);
      rge_read((int)pRVar13,&pRVar6->y1,4);
      rge_read((int)pRVar13,&pRVar6->number,4);
      rge_read((int)pRVar13,&pRVar6->count,4);
      rge_read((int)pRVar13,&pRStack_8,4);
      rge_read((int)pRVar13,&iStack_28,4);
      rge_read((int)pRVar13,&pRVar6->victory_group,1);
      rge_read((int)pRVar13,&pRVar6->ally_flag,1);
      pRStack_c = (RGE_Player *)&pRVar6->state;
      rge_read((int)pRVar13,pRStack_c,1);
      pRVar6->target_obj = (RGE_Static_Object *)0x0;
      pRVar6->this_obj = (RGE_Static_Object *)0x0;
      pRVar6->target_player = (RGE_Player *)0x0;
      *ppRStack_24 = pRVar6;
      ppRStack_24 = &pRVar6->next;
      if (-1 < (int)pRStack_8) {
        iVar14 = 0;
        pRVar7 = this->player->world;
        if (0 < pRVar7->player_num) {
          do {
            pRVar8 = RGE_Object_List::find_by_id(pRVar7->players[iVar14]->objects,(long)pRStack_8);
            pRVar6->this_obj = pRVar8;
            if (pRVar8 != (RGE_Static_Object *)0x0) break;
            iVar14 = iVar14 + 1;
            pRVar7 = this->player->world;
          } while (iVar14 < pRVar7->player_num);
        }
        if ((-1 < (int)pRStack_8) && (pRVar6->this_obj == (RGE_Static_Object *)0x0)) {
          *(uchar *)&pRStack_c->_padding_ = '\x03';
        }
      }
      if (-1 < iStack_28) {
        pRVar8 = RGE_Object_List::find_by_id(this->player->objects,iStack_28);
        pRVar6->target_obj = pRVar8;
      }
      if (iStack_20 < 0) {
        pRVar6->target_player = (RGE_Player *)0x0;
      }
      else {
        if (unaff_EBX != 0) {
          iStack_20 = *(int *)(unaff_EBX + iStack_20 * 4);
        }
        if (iStack_20 < 0) {
          *(uchar *)&pRStack_c->_padding_ = '\x03';
        }
        else {
          pRVar2 = this->player->world->players[iStack_20];
          pRVar6->target_player = pRVar2;
          if (((pRVar2 != (RGE_Player *)0x0) && (pRVar6->target_obj == (RGE_Static_Object *)0x0)) &&
             (-1 < iStack_28)) {
            pRVar8 = RGE_Object_List::find_by_id(pRVar2->objects,iStack_28);
            pRVar6->target_obj = pRVar8;
          }
        }
      }
      if ((-1 < iStack_28) && (pRVar6->target_obj == (RGE_Static_Object *)0x0)) {
        *(uchar *)&pRStack_c->_padding_ = '\x03';
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *plStack_14);
  }
  fVar3 = (float)_DAT_00577590;
  this->victory_point_list = (RGE_Victory_Point_Entry *)0x0;
  this->point_list_num = 0;
  if (fStack_1c < fVar3) {
    this->tot_victory_points = 0;
  }
  else {
    plVar1 = &this->tot_victory_points;
    rge_read((int)pRVar13,plVar1,4);
    rge_read((int)pRVar13,&iStack_18,4);
    iVar4 = 0;
    if (0 < iStack_18) {
      do {
        pRVar9 = RGE_Victory_Conditions::add_point(this,'\0','\0');
        rge_read((int)pRVar13,pRVar9,1);
        rge_read((int)pRVar13,&pRVar9->state,1);
        rge_read((int)pRVar13,&pRVar9->attribute,4);
        rge_read((int)pRVar13,&pRVar9->amount,4);
        rge_read((int)pRVar13,&pRVar9->points,4);
        rge_read((int)pRVar13,&pRVar9->curr_points,4);
        rge_read((int)pRVar13,&pRVar9->id,1);
        rge_read((int)pRVar13,&pRVar9->group,1);
        rge_read((int)pRVar13,&pRVar9->curr_attribute_amount,4);
        if (*plVar1 < 0) {
          pRVar9->points = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iStack_18);
    }
    if (*plVar1 < 0) {
      *plVar1 = 0;
      return this;
    }
  }
  return this;
}

// --------------------------------------------------

// Function: FUN_00531ae8
// Address: 00531ae8
// XREFS: None
void __thiscall FUN_00531ae8(undefined4 *param_1,undefined4 param_2)
{
  param_1[3] = param_2;
  *param_1 = &RGE_Victory_Conditions::_vftable_;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00531b16
// Address: 00531b16
// XREFS: None
void __fastcall FUN_00531b16(RGE_Victory_Conditions *param_1)
{
  RGE_Victory_Entry *pRVar1;
  RGE_Victory_Point_Entry *pRVar2;
  
  pRVar1 = param_1->victory_list;
  param_1->_padding_ = (int)&RGE_Victory_Conditions::_vftable_;
  while (pRVar1 != (RGE_Victory_Entry *)0x0) {
    RGE_Victory_Conditions::sub(param_1,pRVar1);
    pRVar1 = param_1->victory_list;
  }
  pRVar2 = param_1->victory_point_list;
  while (pRVar2 != (RGE_Victory_Point_Entry *)0x0) {
    RGE_Victory_Conditions::sub_point(param_1,pRVar2);
    pRVar2 = param_1->victory_point_list;
  }
  param_1->list_num = 0;
  param_1->point_list_num = 0;
  param_1->victory = '\0';
  param_1->player = (RGE_Player *)0x0;
  return;
}

// --------------------------------------------------

// Function: FUN_00531b67
// Address: 00531b67
// XREFS: None
void __thiscall FUN_00531b67(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_2;
  uStack_4 = 0x3f800000;
  rge_write(param_2,&uStack_4,4);
  rge_write(iVar2,(void *)(param_1 + 8),4);
  rge_write(iVar2,(void *)(param_1 + 0x10),1);
  for (pvVar1 = *(void **)(param_1 + 4); pvVar1 != (void *)0x0;
      pvVar1 = *(void **)((int)pvVar1 + 0x30)) {
    if (*(int *)((int)pvVar1 + 8) == 0) {
      param_2 = -1;
    }
    else {
      param_2 = (int)*(short *)(*(int *)((int)pvVar1 + 8) + 0x4a);
    }
    if (*(int *)((int)pvVar1 + 0x24) == 0) {
      uStack_c = 0xffffffff;
    }
    else {
      uStack_c = *(undefined4 *)(*(int *)((int)pvVar1 + 0x24) + 4);
    }
    if (*(int *)((int)pvVar1 + 0x28) == 0) {
      uStack_8 = 0xffffffff;
    }
    else {
      uStack_8 = *(undefined4 *)(*(int *)((int)pvVar1 + 0x28) + 4);
      param_2 = (int)*(short *)(*(int *)(*(int *)((int)pvVar1 + 0x28) + 0xc) + 0x4a);
    }
    rge_write(iVar2,pvVar1,1);
    rge_write(iVar2,(void *)((int)pvVar1 + 4),4);
    rge_write(iVar2,&param_2,4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0xc),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x10),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x14),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x18),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x1c),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x20),4);
    rge_write(iVar2,&uStack_c,4);
    rge_write(iVar2,&uStack_8,4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x2c),1);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x2d),1);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x2e),1);
  }
  rge_write(iVar2,(void *)(param_1 + 0x1c),4);
  rge_write(iVar2,(void *)(param_1 + 0x18),4);
  for (pvVar1 = *(void **)(param_1 + 0x14); pvVar1 != (void *)0x0;
      pvVar1 = *(void **)((int)pvVar1 + 0x18)) {
    rge_write(iVar2,pvVar1,1);
    rge_write(iVar2,(void *)((int)pvVar1 + 1),1);
    rge_write(iVar2,(void *)((int)pvVar1 + 4),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 8),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0xc),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x10),4);
    rge_write(iVar2,(void *)((int)pvVar1 + 2),1);
    rge_write(iVar2,(void *)((int)pvVar1 + 3),1);
    rge_write(iVar2,(void *)((int)pvVar1 + 0x14),4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00531dab
// Address: 00531dab
// XREFS: None
void __fastcall FUN_00531dab(uint param_1)
{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar3 = *(int *)(param_1 + 4);
  uStack_10 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  if (iVar3 != 0) {
    *(undefined1 *)(param_1 + 0x10) = 0;
    for (; uVar4 = param_1, iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x30)) {
      *(undefined1 *)(iVar3 + 0x2f) = 0;
    }
LAB_00531deb:
    do {
      iVar3 = *(int *)(param_1 + 4);
      if (iVar3 == 0) goto LAB_00531e70;
      do {
        if (*(char *)(iVar3 + 0x2f) == '\0') {
          uVar4 = (uint)*(byte *)(iVar3 + 0x2c);
          uStack_8 = uStack_8 + 1;
          break;
        }
        iVar3 = *(int *)(iVar3 + 0x30);
      } while (iVar3 != 0);
      if (iVar3 == 0) goto LAB_00531e70;
      iVar6 = 0;
      iVar5 = 0;
      bVar2 = false;
      do {
        if (*(byte *)(iVar3 + 0x2c) == uVar4) {
          iVar6 = iVar6 + 1;
          cVar1 = *(char *)(iVar3 + 0x2e);
          *(undefined1 *)(iVar3 + 0x2f) = 1;
          if (cVar1 == '\x01') {
            bVar2 = true;
          }
          else if (cVar1 == '\x02') {
            iVar5 = iVar5 + 1;
          }
          else if (cVar1 == '\x03') {
            uStack_10 = uStack_10 + 1;
          }
        }
        iVar3 = *(int *)(iVar3 + 0x30);
      } while (iVar3 != 0);
      if (bVar2) {
        uStack_c = uStack_c + 1;
        goto LAB_00531deb;
      }
    } while ((iVar5 < 1) || (iVar6 != uStack_10 + iVar5));
    *(undefined1 *)(param_1 + 0x10) = 2;
LAB_00531e70:
    if (uStack_8 == uStack_c) {
      *(undefined1 *)(param_1 + 0x10) = 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00531e88
// Address: 00531e88
// XREFS: None
uchar __fastcall FUN_00531e88(RGE_Victory_Conditions *param_1)
{
  RGE_Victory_Point_Entry *pRVar1;
  RGE_Victory_Entry *pRVar2;
  
  for (pRVar1 = param_1->victory_point_list; pRVar1 != (RGE_Victory_Point_Entry *)0x0;
      pRVar1 = pRVar1->next) {
    if ((pRVar1->state != '\x03') && (pRVar1->state != '\x01')) {
      (**(code **)param_1->_padding_)(pRVar1);
    }
  }
  for (pRVar2 = param_1->victory_list; pRVar2 != (RGE_Victory_Entry *)0x0; pRVar2 = pRVar2->next) {
    if ((pRVar2->state != '\x03') && (pRVar2->state != '\x01')) {
      (**(code **)(param_1->_padding_ + 4))(pRVar2);
    }
  }
  RGE_Victory_Conditions::check_for_victory(param_1);
  return param_1->victory;
}

// --------------------------------------------------

