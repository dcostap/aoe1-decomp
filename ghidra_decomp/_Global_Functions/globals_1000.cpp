// GLOBAL FUNCTIONS PART 1000
// Function: enum_wnd_proc
// Address: 00420580
/* WARNING: Variable defined which should be unmapped: wnd_title */
/* int __stdcall enum_wnd_proc(void *,long) */

int enum_wnd_proc(void *param_1,long param_2)
{
  char wnd_title [256];
  
  wnd_title[0] = -1;
  wnd_title[1] = '\0';
  wnd_title[2] = '\0';
  wnd_title[3] = '\0';
  GetWindowTextA(param_1,wnd_title + 4,0xff);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004205a9
// Address: 004205a9
undefined4 FUN_004205a9(undefined4 param_1)
{
  undefined1 auStack_100 [256];
  
  GetWindowTextA(param_1,auStack_100,0xff);
  return 1;
}

// --------------------------------------------------

// Function: enum_child_proc
// Address: 004205b0
/* WARNING: Variable defined which should be unmapped: wnd_title */
/* int __stdcall enum_child_proc(void *,long) */

int enum_child_proc(void *param_1,long param_2)
{
  char wnd_title [256];
  
  wnd_title[0] = -1;
  wnd_title[1] = '\0';
  wnd_title[2] = '\0';
  wnd_title[3] = '\0';
  GetWindowTextA(param_1,wnd_title + 4,0xff);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004205d9
// Address: 004205d9
undefined4 FUN_004205d9(undefined4 param_1)
{
  undefined1 auStack_100 [256];
  
  GetWindowTextA(param_1,auStack_100,0xff);
  return 1;
}

// --------------------------------------------------

// Function: enum_thread_proc
// Address: 004205e0
/* WARNING: Variable defined which should be unmapped: wnd_title */
/* int __stdcall enum_thread_proc(void *,long) */

int enum_thread_proc(void *param_1,long param_2)
{
  char wnd_title [256];
  
  wnd_title[0] = -1;
  wnd_title[1] = '\0';
  wnd_title[2] = '\0';
  wnd_title[3] = '\0';
  GetWindowTextA(param_1,wnd_title + 4,0xff);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00420609
// Address: 00420609
undefined4 FUN_00420609(void *param_1)
{
  void *pvVar1;
  
  if (param_1 != AppWnd) {
    pvVar1 = (void *)GetParent(param_1);
    if (pvVar1 != AppWnd) {
      SendMessageA(param_1,0x10,0,0);
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: close_thread_windows
// Address: 00420610
/* int __stdcall close_thread_windows(void *,long) */

int close_thread_windows(void *param_1,long param_2)
{
  void *pvVar1;
  
  if (param_1 != AppWnd) {
    pvVar1 = (void *)GetParent(param_1);
    if (pvVar1 != AppWnd) {
      SendMessageA(param_1,0x10,0,0);
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00420643
// Address: 00420643
// [HELPER] s_Locate_Session: "Locate Session"
undefined4 FUN_00420643(undefined4 param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  byte abStack_100 [256];
  
  abStack_100[0] = 0;
  GetWindowTextA(param_1,abStack_100,0xff);
  pbVar4 = &s_Locate_Session;
  pbVar2 = abStack_100;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004206a7:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004206ac;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004206a7;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004206ac:
  if (iVar3 != 0) {
    SendMessageA(param_1,0x10,0,0);
  }
  return 1;
}

// --------------------------------------------------

// Function: close_child_windows
// Address: 00420650
// [HELPER] s_Locate_Session: "Locate Session"
/* WARNING: Variable defined which should be unmapped: str */
/* int __stdcall close_child_windows(void *,long) */

int close_child_windows(void *param_1,long param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  char str [256];
  
  str[4] = '\0';
  GetWindowTextA(param_1,str + 4,0xff);
  pbVar4 = &s_Locate_Session;
  pbVar2 = (byte *)(str + 4);
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004206a7:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004206ac;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004206a7;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004206ac:
  if (iVar3 != 0) {
    SendMessageA(param_1,0x10,0,0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004206ce
// Address: 004206ce
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
int FUN_004206ce(RGE_Base_Game *param_1,void *param_2,uint param_3,uint param_4,void *param_5)
{
  bool bVar1;
  RGE_Base_Game *this;
  TPanel *pTVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  this = param_1;
  color_log('$','$',3);
  bVar1 = false;
  if ((0x200 < param_3) && (param_3 < 0x207)) {
    bVar1 = true;
    color_log('L','L',4);
  }
  if (param_1->sound_system != (TSound_Driver *)0x0) {
    TSound_Driver::handle_messages(param_1->sound_system,param_2,param_3,param_4,(long)param_5);
  }
  color_log('$','\x16',3);
  if (param_1->music_system != (TMusic_System *)0x0) {
    TMusic_System::handle_messages(param_1->music_system,param_2,param_3,param_4,(long)param_5);
  }
  color_log('$','L',3);
  param_1 = (RGE_Base_Game *)0x0;
  pTVar2 = TPanelSystem::currentPanel(&panel_system);
  if (pTVar2 == (TPanel *)0x0) {
LAB_004207c2:
    color_log('$','E',3);
    iVar4 = debug_timeGetTime_on;
    if (param_3 < 6) {
      if (param_3 == 5) {
        if (system_ignore_size_messages != 0) goto LAB_00420f09;
        color_log('2',0xba,3);
        iVar3 = (**(code **)(this->_padding_ + 0xe4))(param_2,5,param_4,param_5);
        iVar4 = debug_timeGetTime_on;
        if (iVar3 != 0) goto LAB_00420f09;
        if (bVar1) {
          color_log('L','_',4);
          color_log('$','_',3);
          return (int)param_1;
        }
        goto LAB_00420e74;
      }
      if (param_3 != 2) goto LAB_00420f09;
      color_log('2',0xba,3);
      iVar3 = (**(code **)(this->_padding_ + 0xf4))(param_2,2,param_4,param_5);
joined_r0x00420d93:
      iVar4 = debug_timeGetTime_on;
      if (iVar3 != 0) goto LAB_00420f09;
LAB_00420e5e:
      if (bVar1) {
        color_log('L','_',4);
      }
      goto LAB_00420e74;
    }
    if (param_3 < 0x10) {
      if (param_3 != 0xf) {
        if ((param_3 == 6) && (this->prog_ready != 0)) {
          if ((param_4 & 0xffff) == 0) {
            iVar4 = GetWindowThreadProcessId(this->prog_window,0);
            iVar3 = GetWindowThreadProcessId(param_5,0);
            if (iVar3 == iVar4) {
              save_active_wnd = param_5;
            }
          }
          iVar4 = debug_timeGetTime_on;
          if (((param_2 == this->prog_window) && ((param_4 & 0xffff) != 0)) &&
             ((param_4 >> 0x10 != 0 && (save_active_wnd != (void *)0x0)))) {
            save_active_wnd = (void *)0x0;
          }
        }
        goto LAB_00420f09;
      }
      color_log('2','E',3);
      iVar3 = (**(code **)(this->_padding_ + 0xd4))(param_2,0xf,param_4,param_5);
    }
    else if (param_3 < 0x1d) {
      if (param_3 != 0x1c) {
        if (param_3 != 0x10) goto LAB_00420f09;
LAB_00420dc9:
        color_log('2',0xba,3);
        iVar3 = (**(code **)(this->_padding_ + 0xf0))(param_2,param_3,param_4,param_5);
        iVar4 = debug_timeGetTime_on;
        if (iVar3 != 0) goto LAB_00420f09;
        if (bVar1) {
          color_log('L','_',4);
          color_log('$','_',3);
          return (int)param_1;
        }
        goto LAB_00420e74;
      }
      if (this->prog_ready != 0) {
        if (param_4 == 1) {
          if (DAT_0062c558 != 0) {
            SetCursor(0);
            SetClassLongA(this->prog_window,0xfffffff4,0);
            if (this->prog_mode != 1) {
              (**(code **)(this->_padding_ + 0xa8))();
            }
            DAT_0062c558 = 0;
            if (this->draw_system != (TDrawSystem *)0x0) {
              TDrawSystem::CheckSurfaces(this->draw_system);
              TDrawSystem::ClearRestored(this->draw_system);
              RGE_Base_Game::set_render_all(this);
            }
            if (this->prog_mode != 1) {
              if (this->draw_system != (TDrawSystem *)0x0) {
                TDrawSystem::ClearPrimarySurface(this->draw_system);
                TDrawSystem::ModifyPalette(this->draw_system,0,0x100,this->draw_system->palette);
              }
              RGE_Base_Game::set_render_all(this);
              InvalidateRect(this->prog_window,0,1);
              do_restore_palette = 10;
              restore_palette_timer = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0xe9b);
              restore_mouse_after_paint = 1;
            }
          }
        }
        else if (DAT_0062c558 == 0) {
          SetClassLongA(this->prog_window,0xfffffff4,0);
          if (this->prog_mode != 1) {
            (**(code **)(this->_padding_ + 0xa4))();
          }
          DAT_0062c558 = 1;
          if ((this->prog_mode != 1) && (this->mouse_pointer != (TMousePointer *)0x0)) {
            TMousePointer::Shutdown_Mouse(this->mouse_pointer);
          }
        }
      }
      color_log('2','T',3);
      iVar3 = (**(code **)(this->_padding_ + 0xd8))(param_2,0x1c,param_4,param_5);
    }
    else if (param_3 < 0x105) {
      if (param_3 == 0x104) {
        color_log('$',0xba,3);
        iVar3 = (**(code **)(this->_padding_ + 0xc4))(param_2,0x104,param_4,param_5);
      }
      else {
        if (param_3 != 0x100) goto LAB_00420f09;
        color_log('$',0xba,3);
        iVar3 = (**(code **)(this->_padding_ + 0xc4))(param_2,0x100,param_4,param_5);
      }
    }
    else if (param_3 < 0x112) {
      if (param_3 != 0x111) {
        if (((param_3 == 0x105) && (param_4 == 0x12)) &&
           (pTVar2 = TPanelSystem::currentPanel(&panel_system), iVar4 = debug_timeGetTime_on,
           pTVar2 != (TPanel *)0x0)) {
          pTVar2 = TPanelSystem::currentPanel(&panel_system);
          (**(code **)(pTVar2->_padding_ + 0xdc))();
          iVar4 = debug_timeGetTime_on;
        }
        goto LAB_00420f09;
      }
      color_log('2','\x16',3);
      iVar3 = (**(code **)(this->_padding_ + 0xcc))(param_2,0x111,param_4,param_5);
    }
    else if (param_3 < 0x201) {
      if (param_3 == 0x200) {
        color_log('$','T',3);
        iVar4 = (**(code **)(this->_padding_ + 0xc0))(param_2,0x200,param_4,param_5);
        if (iVar4 != 0) {
          iVar4 = debug_timeGetTime_on;
          if (MouseCursorInChildContol != 0) {
            if (this->windows_mouse == 0) {
              SetCursor(0);
              SetClassLongA(this->prog_window,0xfffffff4,0);
              RGE_Base_Game::mouse_on(this);
              MouseCursorInChildContol = 0;
              iVar4 = debug_timeGetTime_on;
            }
            else {
              SetCursor(this->mouse_cursor);
              MouseCursorInChildContol = 0;
              iVar4 = debug_timeGetTime_on;
            }
          }
          goto LAB_00420f09;
        }
        goto LAB_00420d04;
      }
      if (param_3 == 0x112) {
        if (((param_4 == 0xf100) && (this->prog_info->full_screen != 0)) &&
           (iVar3 = IsIconic(this->prog_window), iVar4 = debug_timeGetTime_on, iVar3 == 0)) {
          return 0;
        }
        goto LAB_00420f09;
      }
      if (param_3 == 0x113) {
        (**(code **)(this->_padding_ + 0xbc))();
        iVar4 = debug_timeGetTime_on;
        goto LAB_00420f09;
      }
      if (param_3 != 0x116) goto LAB_00420f09;
      color_log('2',0xba,3);
      iVar3 = (**(code **)(this->_padding_ + 0xdc))(param_2,0x116,param_4,param_5);
    }
    else {
      if (0x218 < param_3) {
        if (0x3b9 < param_3) {
          if (param_3 == 0x400) {
            color_log('2','$',3);
            iVar4 = debug_timeGetTime_on;
            debug_timeGetTime_on = 0;
            iVar3 = (**(code **)(this->_padding_ + 200))(param_2,0x400,param_4,param_5);
            if (iVar3 == 0) {
              if (bVar1) {
                color_log('L','_',4);
              }
              color_log('$','_',3);
              debug_timeGetTime_on = iVar4;
              return (int)param_1;
            }
            goto LAB_00420f09;
          }
          if (param_3 != 0x500) goto LAB_00420f09;
LAB_00420e36:
          color_log('2','L',3);
          iVar3 = (**(code **)(this->_padding_ + 0xd0))(param_2,param_3,param_4,param_5);
          goto joined_r0x00420d93;
        }
        if (param_3 == 0x3b9) goto LAB_00420e36;
        if (param_3 != 0x30f) {
          if (param_3 != 0x311) goto LAB_00420f09;
          color_log('2',0xba,3);
          iVar3 = (**(code **)(this->_padding_ + 0xe8))(param_2,0x311,param_4,param_5);
          goto joined_r0x00420d93;
        }
        color_log('2',0xba,3);
        iVar4 = (**(code **)(this->_padding_ + 0xec))(param_2,0x30f,param_4,param_5);
        if (iVar4 != 0) goto LAB_00420dc9;
        goto LAB_00420e5e;
      }
      if (param_3 == 0x218) {
        if (param_4 == 0) {
          return 0x424d5144;
        }
        goto LAB_00420f09;
      }
      if (param_3 != 0x212) goto LAB_00420f09;
      color_log('2',0xba,3);
      iVar3 = (**(code **)(this->_padding_ + 0xe0))(param_2,0x212,param_4,param_5);
    }
    iVar4 = debug_timeGetTime_on;
    if (iVar3 != 0) {
LAB_00420f09:
      debug_timeGetTime_on = iVar4;
      color_log('T','$',3);
      iVar4 = DefWindowProcA(param_2,param_3,param_4,param_5);
      if (unaff_EDI != 0) {
        color_log('L','_',4);
      }
      color_log('$','_',3);
      return iVar4;
    }
  }
  else {
    color_log('$','2',3);
    pTVar2 = TPanelSystem::currentPanel(&panel_system);
    param_1 = (RGE_Base_Game *)
              (**(code **)(pTVar2->_padding_ + 0x48))(param_2,param_3,param_4,param_5);
    if (((param_1 == (RGE_Base_Game *)0x0) || (param_3 == 0x200)) || (param_3 == 0x113))
    goto LAB_004207c2;
  }
LAB_00420d04:
  if (bVar1) {
    color_log('L','_',4);
    color_log('$','_',3);
    return (int)param_1;
  }
LAB_00420e74:
  color_log('$','_',3);
  return (int)param_1;
}

// --------------------------------------------------

// Function: FUN_00420f55
// Address: 00420f55
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
undefined4 __fastcall FUN_00420f55(RGE_Base_Game *param_1)
{
  TDrawSystem *this;
  ulong uVar1;
  TPanel *pTVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1->prog_ready != 0) && (param_1->prog_window != (void *)0x0)) {
    color_log('\x16','\x16',2);
    if ((do_restore_palette != 0) && (param_1->prog_active != 0)) {
      uVar4 = 0xfa;
      if (5 < do_restore_palette) {
        uVar4 = 500;
      }
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0xf9a);
      if (uVar4 <= uVar1 - restore_palette_timer) {
        this = param_1->draw_system;
        if (this != (TDrawSystem *)0x0) {
          TDrawSystem::ModifyPalette(this,0,0x100,this->palette);
        }
        do_restore_palette = do_restore_palette + -1;
        restore_palette_timer = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0xfa4);
      }
    }
    color_log('2','2',5);
    if (param_1->sound_system != (TSound_Driver *)0x0) {
      color_log('\x16',0xba,2);
      TSound_Driver::handle_messages(param_1->sound_system,param_1->prog_window,0x113,0,0);
    }
    pTVar2 = TPanelSystem::currentPanel(&panel_system);
    if (pTVar2 != (TPanel *)0x0) {
      color_log('\x16','E',2);
      pTVar2 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar2->_padding_ + 0x4c))();
    }
    if (param_1->comm_handler != (TCommunications_Handler *)0x0) {
      iVar3 = RGE_Base_Game::multiplayerGame(param_1);
      if (iVar3 != 0) {
        color_log('E','E',1);
        TCommunications_Handler::ReceiveGameMessages(param_1->comm_handler);
        color_log('E','_',1);
      }
    }
    if (param_1->do_show_comm != 0) {
      color_log('\x16','2',2);
      (**(code **)(param_1->_padding_ + 0x134))();
    }
    if (param_1->do_show_ai != 0) {
      color_log('\x16','$',2);
      (**(code **)(param_1->_padding_ + 0x138))();
    }
    color_log('2','_',5);
    color_log('\x16','_',2);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042110f
// Address: 0042110f
undefined4 __thiscall
FUN_0042110f(RGE_Base_Game *param_1,undefined4 param_2,undefined4 param_3,uint param_4,long param_5)
{
  int iVar1;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  tagPOINT tStack_8;
  
  if (param_1->prog_ready == 0) {
    return 1;
  }
  if ((param_1->custom_mouse != 0) && (param_1->windows_mouse == 0)) {
    iVar1 = TMousePointer::in_game_mode(param_1->mouse_pointer);
    if (iVar1 == 0) {
      TMousePointer::draw(param_1->mouse_pointer,0);
    }
    else {
      TMousePointer::Poll(param_1->mouse_pointer);
    }
  }
  RGE_Base_Game::get_mouse_info
            (param_1,param_4,param_5,&tStack_8,&iStack_c,&iStack_10,&iStack_14,&iStack_18);
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0xfc))(tStack_8.x,tStack_8.y,iStack_c,iStack_10,iStack_14,iStack_18);
  (**(code **)(iVar1 + 0xbc))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_004211cb
// Address: 004211cb
// [HELPER] s___AoE_04d_bmp: ".\AoE%04d.bmp"
bool __thiscall FUN_004211cb(int *param_1,int param_2,int param_3,int param_4,uint param_5)
{
  short sVar1;
  int iVar2;
  
  if (param_1[5] == 0) {
    return true;
  }
  DAT_005b2370 = param_5 & 0xffff;
  DAT_005b2368 = param_4;
  sVar1 = GetKeyState(0x11);
  DAT_0062c4bc = (uint)(sVar1 < 0);
  sVar1 = GetKeyState(0x12);
  DAT_0062c4b4 = (uint)(sVar1 < 0);
  sVar1 = GetKeyState(0x10);
  DAT_005b2164 = (uint)(sVar1 < 0);
  if (((((param_2 == param_1[4]) && (param_3 == 0x104)) &&
       ((DAT_005b2368 == 0x12 || ((DAT_005b2368 == 0x20 || (DAT_005b2368 == 0x79)))))) &&
      (*(int *)(param_1[3] + 0x894) != 0)) && (iVar2 = IsIconic(param_1[4]), iVar2 == 0)) {
    return false;
  }
  if ((DAT_0062c4bc != 0) && (DAT_005b2368 == 0x7b)) {
    TDrawArea::take_snapshot(*(TDrawArea **)(param_1[0x12] + 0xc),s___AoE_04d_bmp,&snapshot_number);
    return false;
  }
  iVar2 = (**(code **)(*param_1 + 0x100))
                    (DAT_005b2368,DAT_005b2370,DAT_0062c4bc,DAT_0062c4b4,DAT_005b2164);
  return iVar2 != 0;
}

// --------------------------------------------------

// Function: FUN_004212dc
// Address: 004212dc
bool __thiscall
FUN_004212dc(RGE_Base_Game *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = TCommunications_Handler::MultiplayerGameStart(param_1->comm_handler);
  if ((iVar1 != 0) && (out_of_sync == 0)) {
    if (param_4 == 0x17b3) {
      iVar1 = RGE_Base_Game::playerID(param_1,param_5);
      uVar2 = 1;
      iVar1 = param_1->world->players[iVar1]->_padding_;
    }
    else {
      if (param_4 != 0x17b4) goto LAB_00421350;
      iVar1 = RGE_Base_Game::playerID(param_1,param_5);
      uVar2 = 0;
      iVar1 = param_1->world->players[iVar1]->_padding_;
    }
    (**(code **)(iVar1 + 0xd4))(param_5,uVar2);
  }
LAB_00421350:
  if (param_4 == 0x17a2) {
    if (param_1->world != (RGE_Game_World *)0x0) {
      (**(code **)(param_1->world->_padding_ + 0xec))(1);
    }
  }
  else if ((param_4 == 0x17a3) && (param_1->world != (RGE_Game_World *)0x0)) {
    (**(code **)(param_1->world->_padding_ + 0xec))(0);
  }
  iVar1 = (**(code **)(param_1->_padding_ + 0x104))(param_4,param_5);
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_0042139e
// Address: 0042139e
bool __thiscall
FUN_0042139e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x108))(param_4,param_5);
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_004213bb
// Address: 004213bb
bool __fastcall FUN_004213bb(int *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x10c))();
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_004213d1
// Address: 004213d1
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
undefined4 __fastcall FUN_004213d1(RGE_Base_Game *param_1)
{
  IDirectDrawSurface *pIVar1;
  TSound_Driver *this;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  TPanel *pTVar6;
  ulong uVar7;
  undefined4 unaff_ESI;
  
  color_log('2','2',4);
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x10ea);
  iVar3 = RGE_Base_Game::check_paint(param_1);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x10ee);
  RGE_Base_Game::add_to_timing(param_1,5,uVar4 - uVar2);
  if (iVar3 == 0) {
    color_log('2','_',4);
    return 0;
  }
  iVar3 = param_1->prog_mode;
  if (((((iVar3 == 4) || (iVar3 == 6)) || (iVar3 == 7)) &&
      ((param_1->draw_system->DrawType != '\x01' && (param_1->custom_mouse != 0)))) &&
     (param_1->mouse_blit_sync != 0)) {
    pIVar1 = param_1->draw_system->PrimarySurface;
    iVar3 = (**(code **)((int)*pIVar1 + 0x34))(pIVar1,1);
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x10fc);
    do {
      if (iVar3 != -0x7789fde4) goto LAB_004214dc;
      pIVar1 = param_1->draw_system->PrimarySurface;
      iVar3 = (**(code **)((int)*pIVar1 + 0x34))(pIVar1,1);
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1100);
    } while (uVar4 <= uVar2 + 100);
    param_1->mouse_blit_sync = 0;
  }
LAB_004214dc:
  color_log('2',0xba,4);
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x110c);
  this = rge_base_game->sound_system;
  if (this != (TSound_Driver *)0x0) {
    TSound_Driver::play_list(this);
    TSound_Driver::reset_play_list(this);
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1115);
  RGE_Base_Game::add_to_timing(param_1,10,uVar4 - uVar2);
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x111c);
  if (param_1->erase_mouse != 0) {
    color_log('2','L',4);
    if ((param_1->render_all == 0) && (param_1->custom_mouse != 0)) {
      TMousePointer::erase(param_1->mouse_pointer);
    }
    param_1->erase_mouse = 0;
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1127);
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x112a);
  color_log('2','\x16',4);
  pTVar6 = TPanelSystem::currentPanel(&panel_system);
  if (pTVar6 == (TPanel *)0x0) {
    RGE_Base_Game::clear_window(param_1);
  }
  else {
    color_log('\x16','\x16',1);
    if (param_1->render_all != 0) {
      pTVar6 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar6->_padding_ + 0x20))(2);
    }
    pTVar6 = TPanelSystem::currentPanel(&panel_system);
    (**(code **)(pTVar6->_padding_ + 0x54))();
    color_log('\x16','_',1);
  }
  color_log('2','$',4);
  if (DAT_0062c57c != 0) {
    DAT_0062c57c = 0;
    if (((param_1->prog_mode == 4) || (param_1->prog_mode == 5)) && (param_1->do_show_timings != 0))
{
      (**(code **)(param_1->_padding_ + 0x130))();
    }
  }
  uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1147);
  RGE_Base_Game::add_to_timing(param_1,2,uVar7 - uVar5);
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x114b);
  color_log('2','T',4);
  if ((param_1->custom_mouse != 0) && (param_1->windows_mouse == 0)) {
    TMousePointer::draw(param_1->mouse_pointer,1);
    param_1->erase_mouse = 1;
  }
  uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x115b);
  RGE_Base_Game::add_to_timing(param_1,8,(uVar4 - uVar2) + (uVar7 - uVar5));
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1160);
  color_log('2','E',4);
  TDrawSystem::Paint(param_1->draw_system,(tagRECT *)0x0);
  ValidateRect(param_1->prog_window,0);
  ValidateRect(param_1->prog_window,0);
  param_1->render_all = 0;
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1176);
  RGE_Base_Game::add_to_timing(param_1,3,uVar4 - uVar2);
  color_log('2','_',4);
  param_1->frame_count = param_1->frame_count + 1;
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x1182);
  if (999 < uVar2 - DAT_0062c578) {
    (**(code **)(param_1->_padding_ + 0x128))();
    DAT_0062c57c = 1;
    DAT_0062c578 = uVar2;
  }
  if (restore_mouse_after_paint != 0) {
    if (param_1->mouse_pointer != (TMousePointer *)0x0) {
      TMousePointer::Restore_Mouse(param_1->mouse_pointer,param_1->draw_area);
      if (param_1->is_mouse_on != 0) {
        if ((param_1->custom_mouse == 0) || (param_1->windows_mouse != 0)) {
          SetCursor(param_1->mouse_cursor);
          SetClassLongA(param_1->prog_window,0xfffffff4,param_1->mouse_cursor);
        }
        else {
          TMousePointer::on(param_1->mouse_pointer);
          TMousePointer::draw(param_1->mouse_pointer,1);
        }
      }
      InvalidateRect(unaff_ESI,0,0);
    }
    restore_mouse_after_paint = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00421828
// Address: 00421828
undefined4 __thiscall
FUN_00421828(RGE_Base_Game *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  TPanel *pTVar1;
  int iVar2;
  
  if (param_4 == 0) {
    param_1->prog_active = 0;
  }
  else {
    param_1->prog_active = 1;
  }
  iVar2 = param_1->prog_mode;
  if (param_1->prog_active != 0) {
    if ((((iVar2 == 4) || (iVar2 == 6)) || (iVar2 == 7)) && (param_1->auto_paused == 1)) {
      param_1->auto_paused = 0;
      RGE_Base_Game::set_paused(param_1,0,0);
    }
    pTVar1 = TPanelSystem::currentPanel(&panel_system);
    if (pTVar1 != (TPanel *)0x0) {
      pTVar1 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar1->_padding_ + 0xdc))();
    }
    (**(code **)(param_1->_padding_ + 0x110))();
    return 1;
  }
  if (((iVar2 == 4) || (iVar2 == 6)) || (iVar2 == 7)) {
    iVar2 = RGE_Base_Game::singlePlayerGame(param_1);
    if (iVar2 == 1) {
      iVar2 = RGE_Base_Game::get_paused(param_1);
      if (iVar2 == 0) {
        param_1->auto_paused = 1;
        RGE_Base_Game::set_paused(param_1,1,0);
      }
    }
  }
  (**(code **)(param_1->_padding_ + 0x114))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_00421907
// Address: 00421907
bool __fastcall FUN_00421907(int *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x118))();
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00421921
// Address: 00421921
bool __fastcall FUN_00421921(int *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x11c))();
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00421941
// Address: 00421941
uint __thiscall FUN_00421941(int *param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  int iVar1;
  TPanel *pTVar2;
  
  if (param_4 == 1) {
    return param_4;
  }
  if ((TDrawSystem *)param_1[0x12] != (TDrawSystem *)0x0) {
    TDrawSystem::HandleSize((TDrawSystem *)param_1[0x12],param_2,param_3,param_4,param_5);
    if ((param_1[0x12] != 0) && (iVar1 = *(int *)(param_1[0x12] + 0x2c), iVar1 != 0)) {
      *(int *)(param_1[3] + 0x8e0) = iVar1;
      *(undefined4 *)(param_1[3] + 0x8e4) = *(undefined4 *)(param_1[0x12] + 0x30);
    }
    pTVar2 = TPanelSystem::currentPanel(&panel_system);
    if (pTVar2 != (TPanel *)0x0) {
      pTVar2 = TPanelSystem::currentPanel(&panel_system);
      (**(code **)(pTVar2->_padding_ + 0x50))
                (*(undefined4 *)(param_1[3] + 0x8e0),*(undefined4 *)(param_1[3] + 0x8e4));
    }
  }
  (**(code **)(*param_1 + 0x120))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_004219e7
// Address: 004219e7
undefined4 __thiscall
FUN_004219e7(int *param_1,void *param_2,uint param_3,void *param_4,long param_5)
{
  TDrawSystem *this;
  
  if ((TDrawSystem *)param_1[0x12] != (TDrawSystem *)0x0) {
    TDrawSystem::HandlePaletteChanged
              ((TDrawSystem *)param_1[0x12],param_2,param_3,(uint)param_4,param_5);
  }
  if (param_4 != param_2) {
    this = (TDrawSystem *)param_1[0x12];
    if (((this->DrawType == '\x01') || (this->ScreenMode == '\x01')) || (this == (TDrawSystem *)0x0)
       ) {
      (**(code **)(*param_1 + 0xec))(param_2,param_3,param_4,param_5);
    }
    else if (param_1[0x6c] != 1) {
      TDrawSystem::ModifyPalette(this,0,0x100,this->palette);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00421a76
// Address: 00421a76
int __thiscall FUN_00421a76(int param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  int iVar1;
  undefined4 uVar2;
  TPanel *pTVar3;
  TEasy_Panel *this;
  void *pvVar4;
  uint unaff_EBX;
  uint unaff_retaddr;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x48);
  if (((iVar1 != 0) && (*(char *)(iVar1 + 0x478) != '\x01')) && (*(char *)(iVar1 + 0x479) != '\x01')
     ) {
    InvalidateRect(param_2,0,0);
    iVar1 = TDrawSystem::HandleQueryNewPalette
                      (*(TDrawSystem **)(param_1 + 0x48),param_2,unaff_EBX,unaff_retaddr,
                       (long)param_2);
    return iVar1;
  }
  uVar2 = GetDC(param_2);
  pTVar3 = TPanelSystem::currentPanel(&panel_system);
  if (pTVar3 == (TPanel *)0x0) {
    pvVar4 = *(void **)(param_1 + 0x1c);
    if (pvVar4 == (void *)0x0) goto LAB_00421b1b;
    uVar5 = 0;
  }
  else {
    this = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
    pvVar4 = TEasy_Panel::get_palette(this);
    if (pvVar4 == (void *)0x0) goto LAB_00421b1b;
    uVar5 = 0;
    pvVar4 = TEasy_Panel::get_palette(this);
  }
  SelectPalette(uVar2,pvVar4,uVar5);
LAB_00421b1b:
  iVar1 = RealizePalette(uVar2);
  ReleaseDC(param_2,uVar2);
  if (iVar1 != 0) {
    InvalidateRect(param_2,0,0);
  }
  if (*(TDrawSystem **)(param_1 + 0x48) != (TDrawSystem *)0x0) {
    iVar1 = TDrawSystem::HandleQueryNewPalette
                      (*(TDrawSystem **)(param_1 + 0x48),param_2,param_3,param_4,param_5);
    return iVar1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00421b6a
// Address: 00421b6a
undefined4 __fastcall FUN_00421b6a(int *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x124))();
  if (iVar1 == 0) {
    return 0;
  }
  if (((TDrawArea *)param_1[0x13] != (TDrawArea *)0x0) && (param_1[0x12] != 0)) {
    TDrawArea::Clear((TDrawArea *)param_1[0x13],(tagRECT *)0x0,0);
    TDrawSystem::Paint((TDrawSystem *)param_1[0x12],(tagRECT *)0x0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00421bad
// Address: 00421bad
undefined4 __fastcall FUN_00421bad(int param_1)
{
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(int *)(param_1 + 0x44) != 0) {
    KillTimer(*(undefined4 *)(param_1 + 0x10),1);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  PostQuitMessage(0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00421be5
// Address: 00421be5
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
// [HELPER] s__lu___ld___ld___ld___ld___d___d_: "%lu, %ld, %ld, %ld, %ld, %d, %d, %d, %d, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %..."
void __fastcall FUN_00421be5(int *param_1)
{
  ulonglong uVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  uVar4 = 0;
  piVar7 = param_1 + 0x14a;
  iVar6 = 0x1e;
  do {
    if (piVar7[4] == 0) {
      piVar7[1] = *piVar7;
      piVar7[7] = piVar7[6];
      *piVar7 = 0;
      piVar7[6] = 0;
      uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x12b5);
      piVar7[2] = uVar2;
      if (piVar7[3] != 0) {
        uVar4 = uVar4 + piVar7[1];
      }
    }
    piVar7 = piVar7 + 8;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (param_1[0x14c] == 0) {
    param_1[0x14b] = uVar4;
  }
  else {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x12be);
    param_1[0x14b] = uVar2 - param_1[0x14c];
  }
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x12c1);
  uVar3 = param_1[0x14b];
  param_1[0x14c] = uVar2;
  if (uVar4 < uVar3) {
    param_1[0x16b] = uVar3 - uVar4;
  }
  else {
    param_1[0x16b] = 0;
  }
  if ((uint)(param_1[0x183] + param_1[0x17b]) < (uint)param_1[0x15b]) {
    param_1[0x193] = (param_1[0x15b] - param_1[0x17b]) - param_1[0x183];
  }
  else {
    param_1[0x193] = 0;
  }
  if (((uVar3 == 0) || (param_1[0x141] == 0)) ||
     (uVar1 = (ulonglong)uVar3 / (ulonglong)(uint)param_1[0x141], (int)uVar1 == 0)) {
    param_1[0x147] = 1000;
  }
  else {
    param_1[0x147] = (int)(1000 / uVar1);
  }
  if (((uVar3 == 0) || (param_1[0x143] == 0)) ||
     (uVar1 = (ulonglong)uVar3 / (ulonglong)(uint)param_1[0x143], (int)uVar1 == 0)) {
    param_1[0x149] = 0;
  }
  else {
    param_1[0x149] = (int)(1000 / uVar1);
  }
  if (((uVar3 == 0) || (param_1[0x142] == 0)) ||
     (uVar1 = (ulonglong)uVar3 / (ulonglong)(uint)param_1[0x142], (int)uVar1 == 0)) {
    param_1[0x148] = 0;
  }
  else {
    param_1[0x148] = (int)(1000 / uVar1);
  }
  (**(code **)(*param_1 + 300))();
  if ((do_fps_log != 0) && (param_1[0x6c] == 4)) {
    iVar8 = 0;
    iVar5 = 0;
    iVar6 = (int)*(short *)(param_1[0xfd] + 0x3c);
    if (1 < iVar6) {
      piVar7 = *(int **)(param_1[0xfd] + 0x40);
      iVar6 = iVar6 + -1;
      do {
        piVar7 = piVar7 + 1;
        iVar8 = iVar8 + *(short *)(*(int *)(*piVar7 + 0x28) + 8);
        iVar5 = iVar5 + *(short *)(*(int *)(*piVar7 + 0x2c) + 8);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    uVar4 = param_1[0x142];
    if (uVar4 == 0) {
      uStack_18 = 0;
      uStack_14 = 0;
      uStack_10 = 0;
      uStack_c = 0;
      uStack_8 = 0;
      uStack_4 = 0;
      uVar3 = 0;
    }
    else {
      uStack_18 = (uint)param_1[0x16b] / uVar4;
      uStack_14 = (uint)param_1[0x1b3] / uVar4;
      uStack_10 = (uint)(param_1[0x19b] + param_1[0x1ab]) / uVar4;
      uStack_c = (uint)param_1[0x153] / uVar4;
      uStack_8 = (uint)param_1[0x163] / uVar4;
      uStack_4 = (uint)param_1[0x183] / uVar4;
      uVar3 = (uint)param_1[0x17b] / uVar4;
    }
    fprintf(fps_log,s__lu___ld___ld___ld___ld___d___d_,*(undefined4 *)(param_1[0xfd] + 4),
            start_mem_total,start_mem_high,cur_mem_total,cur_mem_high,
            (int)*(short *)(*(int *)(**(int **)(param_1[0xfd] + 0x40) + 0x28) + 8),
            (int)*(short *)(*(int *)(**(int **)(param_1[0xfd] + 0x40) + 0x2c) + 8),iVar8,iVar5,uVar4
            ,param_1[0x143],param_1[0x148],param_1[0x149],uVar3,param_1[0x181],uStack_4,
            param_1[0x189],uStack_8,param_1[0x169],uStack_c,param_1[0x159],uStack_10,
            param_1[0x1a1] + param_1[0x1b1],uStack_14,param_1[0x1b9],uStack_18,param_1[0x171],0,
            0xffffffff,0xffffffff);
    fflush(fps_log);
  }
  param_1[0x144] = param_1[0x141];
  param_1[0x145] = param_1[0x142];
  param_1[0x146] = param_1[0x143];
  param_1[0x141] = 0;
  param_1[0x142] = 0;
  param_1[0x143] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00421f96
// Address: 00421f96
// [HELPER] s_fps__lu__rend__lu__view__lu__map: "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, upd=%lu, snd=%lu, misc=%lu, ot..."
void __fastcall FUN_00421f96(int param_1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x504);
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  sprintf(param_1 + 0x404,s_fps__lu__rend__lu__view__lu__map,*(undefined4 *)(param_1 + 0x51c),
          *(uint *)(param_1 + 0x56c) / uVar1,*(uint *)(param_1 + 0x5ec) / uVar1,
          *(uint *)(param_1 + 0x60c) / uVar1,*(uint *)(param_1 + 0x58c) / uVar1,
          *(uint *)(param_1 + 0x54c) / uVar1,*(uint *)(param_1 + 0x66c) / uVar1,
          *(uint *)(param_1 + 0x6cc) / uVar1,*(uint *)(param_1 + 0x5ac) / uVar1,
          *(uint *)(param_1 + 0x52c) / uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00422042
// Address: 00422042
// [HELPER] s__s: "%s"
void __fastcall FUN_00422042(int param_1)
{
  char *pcVar1;
  undefined1 auStack_100 [256];
  
  pcVar1 = TCommunications_Handler::GetCommInfo
                     (*(TCommunications_Handler **)(param_1 + 0x18c),'\x01');
  sprintf(auStack_100,s__s,pcVar1);
  SetWindowTextA(*(undefined4 *)(param_1 + 0x10),auStack_100);
  return;
}

// --------------------------------------------------

// Function: FUN_004220cd
// Address: 004220cd
void __fastcall FUN_004220cd(int param_1)
{
  if (*(TCommunications_Handler **)(param_1 + 0x18c) != (TCommunications_Handler *)0x0) {
    TCommunications_Handler::SetMyGameOptions
              (*(TCommunications_Handler **)(param_1 + 0x18c),(char *)(param_1 + 0x8f8),0xa8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004220ed
// Address: 004220ed
void __fastcall FUN_004220ed(RGE_Base_Game *param_1)
{
  RGE_Game_Options *pRVar1;
  ulong uStack_4;
  
  if (param_1->comm_handler != (TCommunications_Handler *)0x0) {
    uStack_4 = 0;
    pRVar1 = (RGE_Game_Options *)
             TCommunications_Handler::GetMyGameOptions(param_1->comm_handler,&uStack_4);
    if ((pRVar1 != (RGE_Game_Options *)0x0) && (uStack_4 == 0xa8)) {
      RGE_Base_Game::set_game_options(param_1,pRVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00422129
// Address: 00422129
void __thiscall FUN_00422129(RGE_Base_Game *param_1,float *param_2)
{
  int iVar1;
  
  RGE_Base_Game::setVersion(param_1,*param_2);
  RGE_Base_Game::setScenarioGame(param_1,(uint)*(byte *)(param_2 + 1));
  RGE_Base_Game::setScenarioName(param_1,(char *)((int)param_2 + 5));
  RGE_Base_Game::setSinglePlayerGame(param_1,(uint)*(byte *)((int)param_2 + 0x85));
  RGE_Base_Game::setMultiplayerGame(param_1,(uint)*(byte *)((int)param_2 + 0x86));
  RGE_Base_Game::setMapSize
            (param_1,(uint)*(byte *)((int)param_2 + 0x87),(uint)*(byte *)(param_2 + 0x22),
             (uint)*(byte *)((int)param_2 + 0x89));
  RGE_Base_Game::setAllowCheatCodes(param_1,(uint)*(byte *)((int)param_2 + 0x8a));
  RGE_Base_Game::setCheatNotification(param_1,(uint)*(byte *)(param_2 + 0x23));
  RGE_Base_Game::setFullVisibility(param_1,(uint)*(byte *)((int)param_2 + 0x8d));
  RGE_Base_Game::setFogOfWar(param_1,(uint)*(byte *)((int)param_2 + 0x8e));
  RGE_Base_Game::setColoredChat(param_1,(uint)*(byte *)((int)param_2 + 0x8f));
  RGE_Base_Game::setNumberPlayers(param_1,(uint)*(byte *)(param_2 + 0x24));
  RGE_Base_Game::setGameDeveloperMode(param_1,(uint)*(byte *)((int)param_2 + 0x91));
  RGE_Base_Game::setDifficulty(param_1,(uint)*(byte *)((int)param_2 + 0x9b));
  RGE_Base_Game::setMpPathFinding(param_1,*(uchar *)((int)param_2 + 0x8b));
  iVar1 = 0;
  do {
    RGE_Base_Game::setPlayerCDAndVersion(param_1,iVar1,*(uchar *)(iVar1 + 0x92 + (int)param_2));
    RGE_Base_Game::setPlayerTeam(param_1,iVar1,(uint)*(byte *)(iVar1 + 0x9c + (int)param_2));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}

// --------------------------------------------------

// Function: FUN_00422259
// Address: 00422259
void __thiscall FUN_00422259(RGE_Base_Game *param_1,float *param_2)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  float fVar9;
  
  fVar9 = RGE_Base_Game::version(param_1);
  *param_2 = fVar9;
  iVar3 = RGE_Base_Game::scenarioGame(param_1);
  *(char *)(param_2 + 1) = (char)iVar3;
  pcVar4 = RGE_Base_Game::scenarioName(param_1);
  uVar6 = 0xffffffff;
  do {
    pcVar8 = pcVar4;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar4 = pcVar8 + -uVar6;
  pcVar8 = (char *)((int)param_2 + 5);
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar8 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar8 = pcVar8 + 1;
  }
  iVar3 = RGE_Base_Game::singlePlayerGame(param_1);
  *(char *)((int)param_2 + 0x85) = (char)iVar3;
  iVar3 = RGE_Base_Game::multiplayerGame(param_1);
  *(char *)((int)param_2 + 0x86) = (char)iVar3;
  iVar3 = RGE_Base_Game::mapXSize(param_1);
  *(char *)((int)param_2 + 0x87) = (char)iVar3;
  iVar3 = RGE_Base_Game::mapYSize(param_1);
  *(char *)(param_2 + 0x22) = (char)iVar3;
  iVar3 = RGE_Base_Game::mapZSize(param_1);
  *(char *)((int)param_2 + 0x89) = (char)iVar3;
  iVar3 = RGE_Base_Game::allowCheatCodes(param_1);
  *(char *)((int)param_2 + 0x8a) = (char)iVar3;
  iVar3 = RGE_Base_Game::cheatNotification(param_1);
  *(char *)(param_2 + 0x23) = (char)iVar3;
  iVar3 = RGE_Base_Game::fullVisibility(param_1);
  *(char *)((int)param_2 + 0x8d) = (char)iVar3;
  iVar3 = RGE_Base_Game::fogOfWar(param_1);
  *(char *)((int)param_2 + 0x8e) = (char)iVar3;
  iVar3 = RGE_Base_Game::coloredChat(param_1);
  *(char *)((int)param_2 + 0x8f) = (char)iVar3;
  iVar3 = RGE_Base_Game::numberPlayers(param_1);
  *(char *)(param_2 + 0x24) = (char)iVar3;
  iVar3 = RGE_Base_Game::gameDeveloperMode(param_1);
  *(char *)((int)param_2 + 0x91) = (char)iVar3;
  iVar3 = RGE_Base_Game::difficulty(param_1);
  *(char *)((int)param_2 + 0x9b) = (char)iVar3;
  uVar2 = RGE_Base_Game::mpPathFinding(param_1);
  *(uchar *)((int)param_2 + 0x8b) = uVar2;
  iVar3 = 0;
  do {
    uVar2 = RGE_Base_Game::playerCDAndVersion(param_1,iVar3);
    *(uchar *)(iVar3 + 0x92 + (int)param_2) = uVar2;
    iVar5 = RGE_Base_Game::playerTeam(param_1,iVar3);
    *(char *)(iVar3 + 0x9c + (int)param_2) = (char)iVar5;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  return;
}

// --------------------------------------------------

// Function: FUN_00422388
// Address: 00422388
float10 __fastcall FUN_00422388(int param_1)
{
  return (float10)*(float *)(param_1 + 0x8f8);
}

// --------------------------------------------------

// Function: FUN_00422397
// Address: 00422397
undefined1 __fastcall FUN_00422397(int param_1)
{
  return *(undefined1 *)(param_1 + 0x8fc);
}

// --------------------------------------------------

// Function: FUN_004223a9
// Address: 004223a9
bool __fastcall FUN_004223a9(int param_1)
{
  return *(char *)(param_1 + 0x8fc) == '\0';
}

// --------------------------------------------------

// Function: FUN_004223be
// Address: 004223be
undefined4 __fastcall FUN_004223be(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9a0);
}

// --------------------------------------------------

// Function: FUN_004223c7
// Address: 004223c7
undefined4 __fastcall FUN_004223c7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9a4);
}

// --------------------------------------------------

// Function: FUN_004223d7
// Address: 004223d7
int __fastcall FUN_004223d7(int param_1)
{
  return param_1 + 0x8fd;
}

// --------------------------------------------------

// Function: FUN_004223e7
// Address: 004223e7
undefined1 __fastcall FUN_004223e7(int param_1)
{
  return *(undefined1 *)(param_1 + 0x97d);
}

// --------------------------------------------------

// Function: FUN_004223f9
// Address: 004223f9
undefined1 __fastcall FUN_004223f9(int param_1)
{
  return *(undefined1 *)(param_1 + 0x97e);
}

// --------------------------------------------------

// Function: FUN_00422409
// Address: 00422409
undefined1 __fastcall FUN_00422409(int param_1)
{
  return *(undefined1 *)(param_1 + 0x97f);
}

// --------------------------------------------------

// Function: FUN_00422419
// Address: 00422419
undefined1 __fastcall FUN_00422419(int param_1)
{
  return *(undefined1 *)(param_1 + 0x980);
}

// --------------------------------------------------

// Function: FUN_00422429
// Address: 00422429
undefined1 __fastcall FUN_00422429(int param_1)
{
  return *(undefined1 *)(param_1 + 0x981);
}

// --------------------------------------------------

// Function: FUN_00422439
// Address: 00422439
undefined1 __fastcall FUN_00422439(int param_1)
{
  return *(undefined1 *)(param_1 + 0x982);
}

// --------------------------------------------------

// Function: FUN_00422449
// Address: 00422449
undefined1 __fastcall FUN_00422449(int param_1)
{
  return *(undefined1 *)(param_1 + 0x984);
}

// --------------------------------------------------

// Function: FUN_00422459
// Address: 00422459
undefined1 __fastcall FUN_00422459(int param_1)
{
  return *(undefined1 *)(param_1 + 0x985);
}

// --------------------------------------------------

// Function: FUN_00422469
// Address: 00422469
undefined1 __fastcall FUN_00422469(int param_1)
{
  return *(undefined1 *)(param_1 + 0x986);
}

// --------------------------------------------------

// Function: FUN_00422479
// Address: 00422479
undefined1 __fastcall FUN_00422479(int param_1)
{
  return *(undefined1 *)(param_1 + 0x987);
}

// --------------------------------------------------

// Function: FUN_00422489
// Address: 00422489
undefined1 __fastcall FUN_00422489(int param_1)
{
  return *(undefined1 *)(param_1 + 0x989);
}

// --------------------------------------------------

// Function: FUN_00422499
// Address: 00422499
byte __thiscall FUN_00422499(int param_1,int param_2)
{
  return *(byte *)(param_1 + 0x98a + param_2) & 1;
}

// --------------------------------------------------

// Function: FUN_004224b1
// Address: 004224b1
byte __thiscall FUN_004224b1(int param_1,int param_2)
{
  return *(byte *)(param_1 + 0x98a + param_2) >> 1;
}

// --------------------------------------------------

// Function: FUN_004224d2
// Address: 004224d2
// [HELPER] s_1_0: "1.0"
// [HELPER] s_1_0a: "1.0a"
// [HELPER] s_1_0b: "1.0b"
// [HELPER] s_1_0c: "1.0c"
// [HELPER] s_1_0d: "1.0d"
// [HELPER] s_1_0e: "1.0e"
// [HELPER] s_1_1: "1.1"
// [HELPER] s_1_1a: "1.1a"
// [HELPER] s_1_1b: "1.1b"
// [HELPER] s_1_1c: "1.1c"
// [HELPER] s_1_2: "1.2"
// [HELPER] s_1_2a: "1.2a"
// [HELPER] s_1_2b: "1.2b"
// [HELPER] s_1_2c: "1.2c"
// [HELPER] s_1_3: "1.3"
// [HELPER] s_1_3a: "1.3a"
// [HELPER] s_1_3b: "1.3b"
// [HELPER] s_1_3c: "1.3c"
// [HELPER] s_1_4: "1.4"
// [HELPER] s_1_4a: "1.4a"
// [HELPER] s_1_4b: "1.4b"
// [HELPER] s_1_4c: "1.4c"
// [HELPER] s_1_X: "1.X"
// [HELPER] s_: ""
char * __thiscall FUN_004224d2(RGE_Base_Game *param_1,int param_2)
{
  uchar uVar1;
  
  uVar1 = RGE_Base_Game::playerVersion(param_1,param_2);
  switch(uVar1) {
  case '\0':
    return s_;
  case '\x01':
    return s_1_0;
  case '\x02':
    return s_1_0a;
  case '\x03':
    return s_1_0b;
  case '\x04':
    return s_1_0c;
  case '\x05':
    return s_1_0d;
  case '\x06':
    return s_1_0e;
  case '\a':
    return s_1_1;
  case '\b':
    return s_1_1a;
  case '\t':
    return s_1_1b;
  case '\n':
    return s_1_1c;
  case '\v':
    return s_1_2;
  case '\f':
    return s_1_2a;
  case '\r':
    return s_1_2b;
  case '\x0e':
    return s_1_2c;
  case '\x0f':
    return s_1_3;
  case '\x10':
    return s_1_3a;
  case '\x11':
    return s_1_3b;
  case '\x12':
    return s_1_3c;
  case '\x13':
    return s_1_4;
  case '\x14':
    return s_1_4a;
  case '\x15':
    return s_1_4b;
  case '\x16':
    return s_1_4c;
  default:
    return s_1_X;
  }
}

// --------------------------------------------------

// Function: FUN_004225c7
// Address: 004225c7
undefined1 __fastcall FUN_004225c7(int param_1,int param_2,undefined4 param_3,int param_4)
{
  byte in_AL;
  char unaff_BL;
  char unaff_BH;
  char *unaff_EDI;
  
  *unaff_EDI = *unaff_EDI + (char)param_2 + '\x01';
  *unaff_EDI = *unaff_EDI;
  *unaff_EDI = *unaff_EDI + (char)((uint)(param_2 + 3) >> 8);
  unaff_EDI[0x25] = unaff_EDI[0x25] + (in_AL & 0x42);
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)param_1;
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)param_2 + '\x06';
  unaff_EDI[0x25] = unaff_EDI[0x25] + unaff_BL;
  unaff_EDI[0x25] = unaff_EDI[0x25];
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)((uint)param_1 >> 8);
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)((uint)(param_2 + 10) >> 8);
  unaff_EDI[0x25] = unaff_EDI[0x25] + unaff_BH;
  unaff_EDI[-0x70ffbddb] = unaff_EDI[-0x70ffbddb] + (in_AL & 0x42);
  unaff_EDI[-0x58ffbddb] = unaff_EDI[-0x58ffbddb] + unaff_BL;
  unaff_EDI[-0x6fffbddb] = unaff_EDI[-0x6fffbddb] + (char)((uint)(param_2 + 0xe) >> 8);
  return *(undefined1 *)(param_1 + 0x98a + param_4);
}

// --------------------------------------------------

// Function: FUN_0042263e
// Address: 0042263e
undefined1 __fastcall FUN_0042263e(int param_1)
{
  return *(undefined1 *)(param_1 + 0x993);
}

// --------------------------------------------------

// Function: FUN_00422649
// Address: 00422649
undefined1 __fastcall FUN_00422649(int param_1)
{
  return *(undefined1 *)(param_1 + 0x988);
}

// --------------------------------------------------

// Function: FUN_00422659
// Address: 00422659
undefined1 __thiscall FUN_00422659(int param_1,int param_2)
{
  return *(undefined1 *)(param_1 + 0x994 + param_2);
}

// --------------------------------------------------

// Function: FUN_00422677
// Address: 00422677
undefined1 __fastcall FUN_00422677(int param_1)
{
  return *(undefined1 *)(param_1 + 0x983);
}

// --------------------------------------------------

// Function: FUN_00422687
// Address: 00422687
Alignment * FUN_00422687(void)
{
  DAT_0062c49c._0_1_ = 0;
  return &DAT_0062c49c;
}

// --------------------------------------------------

// Function: FUN_0042269d
// Address: 0042269d
void __fastcall FUN_0042269d(int param_1)
{
  RGE_Game_Info::find_campaigns(*(RGE_Game_Info **)(param_1 + 4));
  return;
}

// --------------------------------------------------

// Function: FUN_004226a8
// Address: 004226a8
void __thiscall FUN_004226a8(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x8fc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004226bd
// Address: 004226bd
void __thiscall FUN_004226bd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x8f8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004226cd
// Address: 004226cd
void __thiscall FUN_004226cd(int param_1,undefined4 param_2)
{
  strncpy(param_1 + 0x8fd,param_2,0x80);
  *(undefined1 *)(param_1 + 0x97c) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004226f7
// Address: 004226f7
void __thiscall FUN_004226f7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x9a0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0042270d
// Address: 0042270d
void __thiscall FUN_0042270d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x9a4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0042271d
// Address: 0042271d
void __thiscall FUN_0042271d(int param_1,int param_2)
{
  *(char *)(param_1 + 0x97d) = (char)param_2;
  *(bool *)(param_1 + 0x97e) = param_2 == 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0042273a
// Address: 0042273a
void __thiscall FUN_0042273a(int param_1,int param_2)
{
  *(char *)(param_1 + 0x97e) = (char)param_2;
  *(bool *)(param_1 + 0x97d) = param_2 == 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0042275a
// Address: 0042275a
void __thiscall FUN_0042275a(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)
{
  *(undefined1 *)(param_1 + 0x97f) = param_2;
  *(undefined1 *)(param_1 + 0x980) = param_3;
  *(undefined1 *)(param_1 + 0x981) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_00422781
// Address: 00422781
void __thiscall FUN_00422781(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x982) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0042279d
// Address: 0042279d
void __thiscall FUN_0042279d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x984) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004227ad
// Address: 004227ad
void __thiscall FUN_004227ad(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x985) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004227bd
// Address: 004227bd
void __thiscall FUN_004227bd(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x986) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004227cd
// Address: 004227cd
void __thiscall FUN_004227cd(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x987) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004227dd
// Address: 004227dd
void __thiscall FUN_004227dd(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x988) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004227ed
// Address: 004227ed
void __thiscall FUN_004227ed(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x989) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004227fd
// Address: 004227fd
void __thiscall FUN_004227fd(int param_1,int param_2,byte param_3)
{
  *(byte *)(param_1 + 0x98a + param_2) = *(byte *)(param_1 + 0x98a + param_2) & 0xfe | param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00422842
// Address: 00422842
void __thiscall FUN_00422842(int param_1,int param_2,undefined1 param_3)
{
  *(undefined1 *)(param_1 + 0x98a + param_2) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00422862
// Address: 00422862
void __thiscall FUN_00422862(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x993) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0042287d
// Address: 0042287d
void __thiscall FUN_0042287d(int param_1,int param_2,undefined1 param_3)
{
  *(undefined1 *)(param_1 + 0x994 + param_2) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00422892
// Address: 00422892
void __thiscall FUN_00422892(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xa14) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004228ad
// Address: 004228ad
void __thiscall FUN_004228ad(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x983) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004228bd
// Address: 004228bd
void __thiscall FUN_004228bd(int param_1,uchar param_2)
{
  if (*(RGE_Game_World **)(param_1 + 0x3f4) != (RGE_Game_World *)0x0) {
    RGE_Game_World::set_map_visible(*(RGE_Game_World **)(param_1 + 0x3f4),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004228d7
// Address: 004228d7
void __thiscall FUN_004228d7(int param_1,uchar param_2)
{
  if (*(RGE_Game_World **)(param_1 + 0x3f4) != (RGE_Game_World *)0x0) {
    RGE_Game_World::set_map_fog(*(RGE_Game_World **)(param_1 + 0x3f4),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004228f7
// Address: 004228f7
void __fastcall FUN_004228f7(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x00422908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x3f4) + 0xb4))();
  return;
}

// --------------------------------------------------

// Function: FUN_0042290e
// Address: 0042290e
void __fastcall FUN_0042290e(int param_1)
{
  RGE_Game_Info::open_scenario(*(RGE_Game_Info **)(param_1 + 4));
  return;
}

// --------------------------------------------------

// Function: FUN_00422918
// Address: 00422918
long __thiscall FUN_00422918(int param_1,int param_2)
{
  int iVar1;
  long lVar2;
  
  iVar1 = *(int *)(param_1 + 0x3f4);
  if (iVar1 != 0) {
    if (param_2 < 0) {
      lVar2 = RGE_Player::get_checksum
                        (*(RGE_Player **)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4));
      return lVar2;
    }
    if (param_2 < *(short *)(iVar1 + 0x3c)) {
      lVar2 = RGE_Player::get_checksum(*(RGE_Player **)(*(int *)(iVar1 + 0x40) + param_2 * 4));
      return lVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0042295f
// Address: 0042295f
undefined4 __thiscall FUN_0042295f(int param_1,int *param_2,int *param_3,int *param_4)
{
  int iVar1;
  int iVar2;
  long lStack_10;
  long lStack_c;
  long lStack_8;
  int iStack_4;
  
  iVar2 = 0;
  lStack_10 = 0;
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  iVar1 = *(int *)(param_1 + 0x3f4);
  lStack_c = 0;
  lStack_8 = 0;
  if (iVar1 != 0) {
    iStack_4 = param_1;
    if (0 < *(short *)(iVar1 + 0x3c)) {
      do {
        RGE_Player::get_checksums
                  (*(RGE_Player **)(*(int *)(iVar1 + 0x40) + iVar2 * 4),&lStack_10,&lStack_c,
                   &lStack_8);
        *param_2 = *param_2 + lStack_10;
        *param_3 = *param_3 + lStack_c;
        iVar2 = iVar2 + 1;
        *param_4 = *param_4 + lStack_8;
        iVar1 = *(int *)(iStack_4 + 0x3f4);
      } while (iVar2 < *(short *)(iVar1 + 0x3c));
    }
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00422a01
// Address: 00422a01
int __fastcall FUN_00422a01(int param_1)
{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x3f4);
  if (iVar1 != 0) {
    iVar4 = 0;
    if (0 < *(short *)(iVar1 + 0x3c)) {
      do {
        lVar2 = RGE_Player::get_checksum(*(RGE_Player **)(*(int *)(iVar1 + 0x40) + iVar4 * 4));
        iVar3 = iVar3 + lVar2;
        iVar1 = *(int *)(param_1 + 0x3f4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(short *)(iVar1 + 0x3c));
    }
    return iVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00422aaf
// Address: 00422aaf
void __fastcall FUN_00422aaf(RGE_Base_Game *param_1)
{
  int iVar1;
  void *pvVar2;
  
  if (param_1->input_disabled_window != (void *)0x0) {
    iVar1 = GetCapture();
    if (iVar1 != 0) {
      ReleaseCapture();
    }
  }
  TPanelSystem::EnableInput(&panel_system);
  param_1->input_enabled = 1;
  if (param_1->is_mouse_on != 0) {
    pvVar2 = (void *)LoadCursorA(0,0x7f00);
    RGE_Base_Game::set_mouse_cursor(param_1,pvVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00422b02
// Address: 00422b02
// [HELPER] s_DISPLAY: "DISPLAY"
void __thiscall FUN_00422b02(RGE_Base_Game *param_1,char *param_2,int param_3)
{
  int iVar1;
  char *pcStack_58;
  int iStack_54;
  int iStack_50;
  void *pvStack_4c;
  int iStack_48;
  int iStack_44;
  char *pcVar2;
  int iVar3;
  char *pcStack_c;
  int iStack_8;
  
  if (((char *)param_1->draw_area->Width != param_2) || (param_1->draw_area->Height != param_3)) {
    if ((param_1->draw_system->DrawType == '\x02') && (param_1->draw_system->ScreenMode == '\x02'))
{
      SetCursor();
      iStack_44 = 0x422b5d;
      SetClassLongA();
      TMousePointer::Shutdown_Mouse(param_1->mouse_pointer);
      iStack_44 = 0x422b74;
      TDrawSystem::SetDisplaySize(param_1->draw_system,(long)param_2,param_3,8);
      TDrawSystem::CheckSurfaces(param_1->draw_system);
      TDrawSystem::ClearRestored(param_1->draw_system);
      RGE_Base_Game::set_render_all(param_1);
      restore_mouse_after_paint = 1;
      return;
    }
    iVar3 = 0;
    pcVar2 = s_DISPLAY;
    iStack_44 = 0x422bb7;
    iVar1 = CreateICA();
    if (iVar1 != 0) {
      iStack_44 = 8;
      pvStack_4c = (void *)0x422bc6;
      iStack_48 = iVar1;
      pcStack_c = (char *)GetDeviceCaps();
      iStack_44 = 10;
      pvStack_4c = (void *)0x422bd3;
      iStack_48 = iVar1;
      iStack_8 = GetDeviceCaps();
      iStack_48 = 0x422bde;
      iStack_44 = iVar1;
      DeleteDC();
    }
    if (((int)param_2 <= (int)pcStack_c) && (param_3 <= iStack_8)) {
      if ((pcStack_c == param_2) && (iStack_8 == param_3)) {
        pvStack_4c = param_1->prog_window;
        iStack_44 = 0x92080000;
        iStack_48 = -0x10;
        param_1->window_style = -0x6df80000;
        iStack_50 = 0x422c18;
        SetWindowLongA();
        iStack_44 = param_1->window_style;
        iStack_48 = -0x14;
      }
      else {
        pvStack_4c = param_1->prog_window;
        iStack_44 = 0x12ca0000;
        iStack_48 = -0x14;
        param_1->window_style = 0x12ca0000;
        iStack_50 = 0x422c3a;
        SetWindowLongA();
        iStack_44 = param_1->window_style;
        iStack_48 = -0x10;
      }
      pvStack_4c = param_1->prog_window;
      iStack_50 = 0x422c46;
      SetWindowLongA();
      iStack_50 = 0;
      iStack_54 = param_3;
      pcStack_58 = param_2;
      SetWindowPos(param_1->prog_window,0,0,0);
      GetWindowRect(param_1->prog_window,&pcStack_58);
      GetClientRect(param_1->prog_window,&iStack_48);
      if ((pcVar2 != param_2) || (iVar3 != param_3)) {
        SetWindowPos(param_1->prog_window,0,pcStack_58,iStack_54,
                     param_2 + ((iStack_50 - (int)pcStack_58) - (int)pcVar2),
                     (int)pvStack_4c + ((param_3 - iStack_54) - iVar3),0);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00422cbe
// Address: 00422cbe
bool __fastcall FUN_00422cbe(int param_1)
{
  int iVar1;
  undefined4 unaff_retaddr;
  undefined1 *puStack_104;
  undefined1 auStack_100 [255];
  undefined1 uStack_1;
  
  puStack_104 = (undefined1 *)0xff;
  strncpy(auStack_100,*(int *)(param_1 + 0xc) + 0x518);
  puStack_104 = auStack_100;
  uStack_1 = 0;
  CharUpperA();
  iVar1 = strstr(&puStack_104,unaff_retaddr);
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00422d17
// Address: 00422d17
ulong __thiscall FUN_00422d17(RGE_Base_Game *param_1,char *param_2)
{
  ulong uVar1;
  RGE_Scenario_Header *this;
  
  this = RGE_Base_Game::get_scenario_header(param_1,param_2,0);
  if (this == (RGE_Scenario_Header *)0x0) {
    return 0;
  }
  uVar1 = this->checksum;
  RGE_Scenario_Header::~RGE_Scenario_Header(this);
  operator_delete(this);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00422d52
// Address: 00422d52
undefined4 __thiscall FUN_00422d52(RGE_Base_Game *param_1,char *param_2,int param_3)
{
  long lVar1;
  
  lVar1 = RGE_Base_Game::get_scenario_checksum(param_1,param_2);
  if ((lVar1 != 0) && (lVar1 == param_3)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00422d7e
// Address: 00422d7e
void FUN_00422d7e(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00422d83
// Address: 00422d83
undefined4 __thiscall FUN_00422d83(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x9b0 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_00422d9e
// Address: 00422d9e
void __thiscall FUN_00422d9e(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x9b0 + param_2 * 4) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00422db2
// Address: 00422db2
void __thiscall FUN_00422db2(int param_1,int param_2)
{
  *(undefined4 *)(param_1 + 0x9d8 + param_2 * 4) = 0xffffffff;
  return;
}

// --------------------------------------------------

// Function: FUN_00422dd2
// Address: 00422dd2
void __thiscall FUN_00422dd2(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x9d8 + param_2 * 4);
  if ((param_3 < iVar1) || (iVar1 < 0)) {
    *(int *)(param_1 + 0x9d8 + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00422e03
// Address: 00422e03
void __thiscall FUN_00422e03(int param_1,int param_2,undefined4 *param_3)
{
  *param_3 = *(undefined4 *)(param_1 + 0x9d8 + param_2 * 4);
  return;
}

// --------------------------------------------------

// Function: FUN_00422e24
// Address: 00422e24
undefined4 FUN_00422e24(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00422e35
// Address: 00422e35
void FUN_00422e35(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00422e41
// Address: 00422e41
void FUN_00422e41(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00422e51
// Address: 00422e51
int __thiscall FUN_00422e51(int param_1,int param_2)
{
  TDigital *this;
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 == 0) {
    return iVar1;
  }
  this = *(TDigital **)(param_2 * 4 + iVar1);
  if (this == (TDigital *)0x0) {
    return 0;
  }
  iVar1 = TDigital::is_playing(this);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = TDigital::play(*(TDigital **)(*(int *)(param_1 + 0x6c) + param_2 * 4));
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00422eac
// Address: 00422eac
float10 __fastcall FUN_00422eac(int param_1)
{
  return (float10)*(float *)(param_1 + 0xa0c);
}

// --------------------------------------------------

// Function: FUN_00422eb7
// Address: 00422eb7
void __thiscall FUN_00422eb7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa0c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00422ecd
// Address: 00422ecd
undefined4 __fastcall FUN_00422ecd(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa10);
}

// --------------------------------------------------

// Function: FUN_00422ed7
// Address: 00422ed7
void __thiscall FUN_00422ed7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa10) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00422eed
// Address: 00422eed
// [HELPER] s_Diamond_Map_Save_Area: "Diamond Map Save Area"
undefined4 __fastcall FUN_00422eed(int param_1)
{
  TDrawArea *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cc1b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = (TDrawArea *)operator_new(0x100);
  uStack_4 = 0;
  if (pTVar1 == (TDrawArea *)0x0) {
    pTVar1 = (TDrawArea *)0x0;
  }
  else {
    pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_Diamond_Map_Save_Area,0);
  }
  uStack_4 = 0xffffffff;
  *(TDrawArea **)(param_1 + 0xa20) = pTVar1;
  if (pTVar1 == (TDrawArea *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  iVar2 = TDrawArea::Init(pTVar1,*(TDrawSystem **)(param_1 + 0x48),0x118,0x8c,0,0);
  if (iVar2 == 0) {
    pTVar1 = *(TDrawArea **)(param_1 + 0xa20);
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar1);
      operator_delete(pTVar1);
    }
    *(undefined4 *)(param_1 + 0xa20) = 0;
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00422fc6
// Address: 00422fc6
void __fastcall FUN_00422fc6(int param_1)
{
  RGE_Scenario_File_Info::reload_scenarios(*(RGE_Scenario_File_Info **)(param_1 + 8));
  return;
}

// --------------------------------------------------

// Function: FUN_00422fd8
// Address: 00422fd8
void FUN_00422fd8(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00422fe1
// Address: 00422fe1
void __fastcall FUN_00422fe1(int param_1)
{
  *(undefined4 *)(param_1 + 0x3f8) = 1;
  TPanelSystem::set_restore(&panel_system);
  return;
}

// --------------------------------------------------

// Function: FUN_00423004
// Address: 00423004
// [HELPER] debug_random_log: "00000000"
void FUN_00423004(void)
{
  char **ppcVar1;
  
  ppcVar1 = &debug_random_log;
  do {
    *(undefined1 *)ppcVar1 = 0;
    ppcVar1 = ppcVar1 + 0x19;
  } while ((int)ppcVar1 < 0x62c498);
  debug_random_index = -1;
  return;
}

// --------------------------------------------------

// Function: debug_random_reset
// Address: 00423010
// [HELPER] debug_random_log: "00000000"
/* void __cdecl debug_random_reset(void) */

void __cdecl debug_random_reset(void)
{
  char **ppcVar1;
  
  ppcVar1 = &debug_random_log;
  do {
    *(undefined1 *)ppcVar1 = 0;
    ppcVar1 = ppcVar1 + 0x19;
  } while ((int)ppcVar1 < 0x62c498);
  debug_random_index = -1;
  return;
}

// --------------------------------------------------

// Function: FUN_0042302d
// Address: 0042302d
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_: ""
// [HELPER] s__: "}"
// [HELPER] s__s_d____s_: "%s%d - %s\n"
// [HELPER] s_c__aoerand_txt: "c:\aoerand.txt"
// [HELPER] s_w: "w"
void FUN_0042302d(void)
{
  int iVar1;
  undefined1 *puVar2;
  char **ppcVar3;
  int iVar4;
  
  iVar1 = fopen(s_c__aoerand_txt,s_w);
  if (iVar1 != 0) {
    iVar4 = 0;
    ppcVar3 = &debug_random_log;
    do {
      puVar2 = &s_>;
      if (iVar4 != debug_random_index) {
        puVar2 = &s__;
      }
      fprintf(iVar1,s__s_d____s_,puVar2,iVar4,ppcVar3);
      ppcVar3 = ppcVar3 + 0x19;
      iVar4 = iVar4 + 1;
    } while ((int)ppcVar3 < 0x62c498);
    fclose(iVar1);
    wrote_debug_random_log = 1;
  }
  return;
}

// --------------------------------------------------

// Function: debug_random_write
// Address: 00423030
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_: ""
// [HELPER] s__: "}"
// [HELPER] s__s_d____s_: "%s%d - %s\n"
// [HELPER] s_c__aoerand_txt: "c:\aoerand.txt"
// [HELPER] s_w: "w"
/* void __cdecl debug_random_write(void) */

void __cdecl debug_random_write(void)
{
  int iVar1;
  undefined1 *puVar2;
  char **ppcVar3;
  int iVar4;
  
  iVar1 = fopen(s_c__aoerand_txt,s_w);
  if (iVar1 != 0) {
    iVar4 = 0;
    ppcVar3 = &debug_random_log;
    do {
      puVar2 = &s_>;
      if (iVar4 != debug_random_index) {
        puVar2 = &s__;
      }
      fprintf(iVar1,s__s_d____s_,puVar2,iVar4,ppcVar3);
      ppcVar3 = ppcVar3 + 0x19;
      iVar4 = iVar4 + 1;
    } while ((int)ppcVar3 < 0x62c498);
    fclose(iVar1);
    wrote_debug_random_log = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00423099
// Address: 00423099
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_t_d__s_l_d_r_d: "t%d,%s,l%d,r%d"
undefined4 FUN_00423099(int param_1,undefined4 param_2)
{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  char acStack_c [12];
  
  uVar2 = rand();
  if ((do_debug_random != 0) && (debug_random_on != 0)) {
    pcVar3 = (char *)(param_1 + 10);
    pcVar4 = acStack_c;
    cVar1 = *pcVar3;
    for (; (cVar1 != '.' && (pcVar3 < (char *)(param_1 + 0x12U))); pcVar3 = pcVar3 + 1) {
      *pcVar4 = cVar1;
      cVar1 = pcVar3[1];
      pcVar4 = pcVar4 + 1;
    }
    *pcVar4 = '\0';
    if (debug_random_index < 4999) {
      debug_random_index = debug_random_index + 1;
    }
    else {
      debug_random_index = 0;
    }
    sprintf(&debug_random_log + debug_random_index * 0x19,s_t_d__s_l_d_r_d,
            rge_base_game->world->world_time,acStack_c,param_2,uVar2);
  }
  return uVar2;
}

// --------------------------------------------------

// Function: debug_rand
// Address: 004230a0
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_t_d__s_l_d_r_d: "t%d,%s,l%d,r%d"
/* WARNING: Variable defined which should be unmapped: temp_name */
/* int __cdecl debug_rand(char *,int) */

int __cdecl debug_rand(char *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char temp_name [9];
  
  iVar2 = rand();
  if ((do_debug_random != 0) && (debug_random_on != 0)) {
    pcVar3 = param_1 + 10;
    pcVar4 = temp_name + 4;
    cVar1 = *pcVar3;
    for (; (cVar1 != '.' && (pcVar3 < param_1 + 0x12)); pcVar3 = pcVar3 + 1) {
      *pcVar4 = cVar1;
      cVar1 = pcVar3[1];
      pcVar4 = pcVar4 + 1;
    }
    *pcVar4 = '\0';
    if (debug_random_index < 4999) {
      debug_random_index = debug_random_index + 1;
    }
    else {
      debug_random_index = 0;
    }
    sprintf(&debug_random_log + debug_random_index * 0x19,s_t_d__s_l_d_r_d,
            rge_base_game->world->world_time,temp_name + 4,param_2,iVar2);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0042313a
// Address: 0042313a
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_t_d__s_l_d_s_u: "t%d,%s,l%d,s%u"
void FUN_0042313a(int param_1,undefined4 param_2,undefined4 param_3)
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char acStack_c [12];
  
  if ((do_debug_random != 0) && (debug_random_on != 0)) {
    pcVar2 = (char *)(param_1 + 10);
    pcVar3 = acStack_c;
    cVar1 = *pcVar2;
    for (; (cVar1 != '.' && (pcVar2 < (char *)(param_1 + 0x12U))); pcVar2 = pcVar2 + 1) {
      *pcVar3 = cVar1;
      cVar1 = pcVar2[1];
      pcVar3 = pcVar3 + 1;
    }
    *pcVar3 = '\0';
    if (debug_random_index < 4999) {
      debug_random_index = debug_random_index + 1;
    }
    else {
      debug_random_index = 0;
    }
    sprintf(&debug_random_log + debug_random_index * 0x19,s_t_d__s_l_d_s_u,
            rge_base_game->world->world_time,acStack_c,param_2,param_3);
  }
  srand(param_3);
  return;
}

// --------------------------------------------------

// Function: debug_srand
// Address: 00423140
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_t_d__s_l_d_s_u: "t%d,%s,l%d,s%u"
/* WARNING: Variable defined which should be unmapped: temp_name */
/* void __cdecl debug_srand(char *,int,unsigned int) */

void __cdecl debug_srand(char *param_1,int param_2,uint param_3)
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char temp_name [9];
  
  if ((do_debug_random != 0) && (debug_random_on != 0)) {
    pcVar2 = param_1 + 10;
    pcVar3 = temp_name + 4;
    cVar1 = *pcVar2;
    for (; (cVar1 != '.' && (pcVar2 < param_1 + 0x12)); pcVar2 = pcVar2 + 1) {
      *pcVar3 = cVar1;
      cVar1 = pcVar2[1];
      pcVar3 = pcVar3 + 1;
    }
    *pcVar3 = '\0';
    if (debug_random_index < 4999) {
      debug_random_index = debug_random_index + 1;
    }
    else {
      debug_random_index = 0;
    }
    sprintf(&debug_random_log + debug_random_index * 0x19,s_t_d__s_l_d_s_u,
            rge_base_game->world->world_time,temp_name + 4,param_2,param_3);
  }
  srand(param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004231de
// Address: 004231de
int FUN_004231de(void)
{
  int iVar1;
  
  if ((do_debug_timeGetTime != 0) && (debug_timeGetTime_on != 0)) {
    debug_timeGetTime_cnt = debug_timeGetTime_cnt + 1;
    if (debug_timeGetTime_cnt == debug_timeGetTime_interval) {
      debug_timeGetTime_cnt = 0;
      debug_timeGetTime_time = debug_timeGetTime_time + 1;
    }
    return debug_timeGetTime_time;
  }
                    /* WARNING: Could not recover jumptable at 0x00423222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = timeGetTime();
  return iVar1;
}

// --------------------------------------------------

// Function: debug_timeGetTime
// Address: 004231e0
/* unsigned long __cdecl debug_timeGetTime(char *,int) */

ulong __cdecl debug_timeGetTime(char *param_1,int param_2)
{
  ulong uVar1;
  
  if ((do_debug_timeGetTime != 0) && (debug_timeGetTime_on != 0)) {
    debug_timeGetTime_cnt = debug_timeGetTime_cnt + 1;
    if (debug_timeGetTime_cnt == debug_timeGetTime_interval) {
      debug_timeGetTime_cnt = 0;
      debug_timeGetTime_time = debug_timeGetTime_time + 1;
    }
    return debug_timeGetTime_time;
  }
                    /* WARNING: Could not recover jumptable at 0x00423222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = timeGetTime();
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00423228
// Address: 00423228
// [HELPER] s_FILE_NOT_FOUND: "FILE NOT FOUND"
// [HELPER] s__s_s: "%s%s"
undefined4 * __thiscall FUN_00423228(undefined4 *param_1,undefined4 param_2)
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  sprintf(param_1 + 0x43,s__s_s,rge_base_game->prog_info->campaign_dir,param_2);
  iVar2 = __open(param_1 + 0x43,0x8000);
  if (-1 < iVar2) {
    read(iVar2,param_1,0x108);
    if (0 < (int)param_1[0x41]) {
      uVar3 = calloc(param_1[0x41],0x208);
      param_1[0x42] = uVar3;
      read(iVar2,uVar3,param_1[0x41] * 0x208);
      close(iVar2);
      return param_1;
    }
    param_1[0x42] = 0;
    close(iVar2);
    return param_1;
  }
  uVar4 = 0xffffffff;
  pcVar6 = &s_FILE_NOT_FOUND;
  do {
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar7 + -uVar4;
  pcVar7 = (char *)(param_1 + 1);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  param_1[0x41] = 0;
  *param_1 = 0;
  param_1[0x42] = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042332b
// Address: 0042332b
// [HELPER] s_1_00: "1.00"
// [HELPER] s__s_s: "%s%s"
RGE_Campaign * __thiscall
FUN_0042332b(RGE_Campaign *param_1,int param_2,char *param_3,int param_4,undefined4 *param_5,
            int param_6)
{
  char cVar1;
  RGE_Scenario_Offset *pRVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  sprintf(param_1->filename,s__s_s,rge_base_game->prog_info->campaign_dir,param_2);
  (param_1->campaign_header).version = s_1_00._0_4_;
  uVar3 = 0xffffffff;
  do {
    pcVar7 = param_3;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar6 = 0;
  pcVar7 = pcVar7 + -uVar3;
  pcVar8 = (param_1->campaign_header).name;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  (param_1->campaign_header).scenario_num = param_4;
  if (param_4 < 1) {
    param_1->scenario_offsets = (RGE_Scenario_Offset *)0x0;
  }
  else {
    pRVar2 = (RGE_Scenario_Offset *)calloc(param_4,0x208);
    param_1->scenario_offsets = pRVar2;
    if (0 < param_4) {
      param_2 = param_4;
      puVar5 = param_5;
      do {
        uVar3 = 0xffffffff;
        pcVar7 = *(char **)((param_6 - (int)param_5) + (int)puVar5);
        do {
          pcVar8 = pcVar7;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar8 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar8;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        pcVar7 = pcVar8 + -uVar3;
        pcVar8 = param_1->scenario_offsets->name + iVar6;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar8 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        }
        pcVar7 = param_1->scenario_offsets->file_name + iVar6;
        uVar3 = 0xffffffff;
        pcVar8 = (char *)*puVar5;
        do {
          pcVar9 = pcVar8;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar9 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar9;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        iVar6 = iVar6 + 0x208;
        pcVar8 = pcVar9 + -uVar3;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar7 = pcVar7 + 4;
        }
        param_2 = param_2 + -1;
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar7 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar7 = pcVar7 + 1;
        }
        puVar5 = puVar5 + 1;
        if (param_2 == 0) {
          RGE_Campaign::create_file(param_1);
          return param_1;
        }
      } while( true );
    }
  }
  RGE_Campaign::create_file(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00423471
// Address: 00423471
void __fastcall FUN_00423471(int param_1)
{
  if (*(int *)(param_1 + 0x108) != 0) {
    free(*(int *)(param_1 + 0x108));
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004234a2
// Address: 004234a2
// [HELPER] s__s_s: "%s%s"
void __fastcall FUN_004234a2(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack_13c;
  int iStack_134;
  int iStack_130;
  undefined1 auStack_12c [300];
  
  iVar1 = __open(param_1 + 0x10c,0x8301,0x180);
  if (-1 < iVar1) {
    write(iVar1,param_1,0x108);
    if (0 < *(int *)(param_1 + 0x104)) {
      write(iVar1,*(undefined4 *)(param_1 + 0x108),*(int *)(param_1 + 0x104) * 0x208);
      iStack_134 = 0;
      iStack_130 = *(int *)(param_1 + 0x104) * 0x208 + 0x108;
      if (0 < *(int *)(param_1 + 0x104)) {
        iStack_13c = 0;
        do {
          sprintf(auStack_12c,s__s_s,rge_base_game->prog_info->scenario_dir,
                  *(int *)(param_1 + 0x108) + 0x107 + iStack_13c);
          iVar2 = __open(auStack_12c,0x8000);
          if (-1 < iVar2) {
            lseek(iVar2,0,2);
            iVar3 = __tell(iVar2);
            uVar4 = calloc(iVar3,1);
            lseek(iVar2,0,0);
            read(iVar2,uVar4,iVar3);
            write(iVar1,uVar4,iVar3);
            *(int *)(*(int *)(param_1 + 0x108) + 4 + iStack_13c) = iStack_130;
            iStack_130 = iStack_130 + iVar3;
            *(int *)(*(int *)(param_1 + 0x108) + iStack_13c) = iVar3;
            free(uVar4);
            close(iVar2);
          }
          iStack_134 = iStack_134 + 1;
          iStack_13c = iStack_13c + 0x208;
        } while (iStack_134 < *(int *)(param_1 + 0x104));
      }
      lseek(iVar1,0x108,0);
      write(iVar1,*(undefined4 *)(param_1 + 0x108),*(int *)(param_1 + 0x104) * 0x208);
    }
    close(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00423682
// Address: 00423682
int __thiscall FUN_00423682(int param_1,int param_2)
{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x104))) {
    iVar1 = __open(param_1 + 0x10c,0x8000);
    if (-1 < iVar1) {
      lseek(iVar1,*(undefined4 *)(*(int *)(param_1 + 0x108) + 4 + param_2 * 0x208),0);
      rge_fake_open(iVar1,*(int *)(*(int *)(param_1 + 0x108) + param_2 * 0x208));
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00423706
// Address: 00423706
int __fastcall FUN_00423706(int param_1)
{
  return param_1 + 4;
}

// --------------------------------------------------

// Function: FUN_00423714
// Address: 00423714
undefined4 __fastcall FUN_00423714(int param_1)
{
  return *(undefined4 *)(param_1 + 0x104);
}

// --------------------------------------------------

// Function: FUN_00423727
// Address: 00423727
undefined4 __thiscall FUN_00423727(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = calloc(*(undefined4 *)(param_1 + 0x104),4);
  iVar2 = 0;
  *param_2 = iVar1;
  if (0 < *(int *)(param_1 + 0x104)) {
    iVar1 = 0;
    do {
      getstring((char **)(*param_2 + iVar2 * 4),(char *)(*(int *)(param_1 + 0x108) + 8 + iVar1));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x208;
    } while (iVar2 < *(int *)(param_1 + 0x104));
  }
  return *(undefined4 *)(param_1 + 0x104);
}

// --------------------------------------------------

// Function: FUN_00423794
// Address: 00423794
int __thiscall FUN_00423794(int param_1,int param_2)
{
  return *(int *)(param_1 + 0x108) + 8 + param_2 * 0x208;
}

// --------------------------------------------------

// Function: FUN_004237b8
// Address: 004237b8
void __fastcall FUN_004237b8(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004237f7
// Address: 004237f7
void __thiscall FUN_004237f7(CCDAudio *param_1,void *param_2)
{
  ulong uVar1;
  undefined1 auStack_20 [4];
  undefined4 uStack_1c;
  undefined1 auStack_14 [4];
  uint uStack_10;
  undefined4 uStack_c;
  
  param_1->m_Wnd = param_2;
  if (param_1->m_bOpened != 0) {
    CCDAudio::Close(param_1);
  }
  uStack_c = 0x204;
  uVar1 = mciSendCommandA(0,0x803,0x3102,auStack_14);
  if (uVar1 == 0) {
    param_1->m_bOpened = 1;
    param_1->m_nDeviceID = uStack_10;
    uStack_1c = 10;
    uVar1 = mciSendCommandA(uStack_10,0x80d,0x402,auStack_20);
  }
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423876
// Address: 00423876
ulong __fastcall FUN_00423876(CCDAudio *param_1)
{
  ulong uVar1;
  
  uVar1 = 0;
  if (param_1->m_bOpened != 0) {
    uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x804,2,0);
    CCDAudio::DisplayErrorMsg(param_1,uVar1);
    if (uVar1 == 0) {
      param_1->m_bOpened = 0;
    }
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004238b5
// Address: 004238b5
void __fastcall FUN_004238b5(CCDAudio *param_1)
{
  ulong uVar1;
  
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x808,2,0);
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423922
// Address: 00423922
void __fastcall FUN_00423922(CCDAudio *param_1)
{
  ulong uVar1;
  
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x809,2,0);
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423972
// Address: 00423972
void __fastcall FUN_00423972(CCDAudio *param_1)
{
  ulong uVar1;
  
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x80d,0x100,0);
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_004239a3
// Address: 004239a3
void __thiscall FUN_004239a3(CCDAudio *param_1,undefined1 *param_2)
{
  ulong uVar1;
  undefined1 auStack_10 [4];
  undefined1 uStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 3;
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x814,0x102,auStack_10);
  *param_2 = uStack_c;
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423a37
// Address: 00423a37
void __thiscall FUN_00423a37(CCDAudio *param_1,uint *param_2)
{
  ulong uVar1;
  undefined1 auStack_10 [4];
  uint uStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 4;
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x814,0x102,auStack_10);
  *param_2 = (uint)(uStack_c == 0x20e);
  if ((uStack_c == 0x20e) != 0) {
    uStack_8 = 8;
    uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x814,0x102,auStack_10);
    *param_2 = uStack_c;
  }
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423ab8
// Address: 00423ab8
void __thiscall FUN_00423ab8(CCDAudio *param_1,undefined1 *param_2,undefined1 *param_3)
{
  ulong uVar1;
  undefined1 auStack_10 [8];
  undefined4 uStack_8;
  
  uStack_8 = 1;
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x814,0x102,auStack_10);
  *param_2 = (char)auStack_10._4_2_;
  *param_3 = SUB21(auStack_10._4_2_,1);
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423b0a
// Address: 00423b0a
void __thiscall FUN_00423b0a(CCDAudio *param_1,uint param_2,undefined1 *param_3,undefined1 *param_4)
{
  ulong uVar1;
  undefined1 auStack_10 [8];
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = param_2 & 0xff;
  uStack_8 = 1;
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x814,0x112,auStack_10);
  *param_3 = (char)auStack_10._4_2_;
  *param_4 = SUB21(auStack_10._4_2_,1);
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423b67
// Address: 00423b67
void __thiscall
FUN_00423b67(CCDAudio *param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)
{
  ulong uVar1;
  undefined1 auStack_10 [8];
  undefined4 uStack_8;
  
  uStack_8 = 2;
  uVar1 = mciSendCommandA(param_1->m_nDeviceID,0x814,0x102,auStack_10);
  *param_2 = (char)auStack_10._4_4_;
  *param_3 = SUB41(auStack_10._4_4_,1);
  *param_4 = SUB41(auStack_10._4_4_,2);
  CCDAudio::DisplayErrorMsg(param_1,uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00423bc5
// Address: 00423bc5
// [HELPER] s_Unknow_Error: "Unknow Error"
int FUN_00423bc5(int param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 auStack_100 [64];
  
  if (param_1 != 0) {
    pcVar7 = &stack0xfffffefc;
    iVar2 = mciGetErrorStringA(param_1,auStack_100,0x100);
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
      pcVar5 = &s_Unknow_Error;
      do {
        pcVar6 = pcVar5;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar6 + -uVar3;
      for (uVar4 = uVar3 >> 2; pcVar7 = pcVar7 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      }
    }
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00423c2b
// Address: 00423c2b
TChat * __thiscall FUN_00423c2b(TChat *param_1,void *param_2)
{
  TTaunt *pTVar1;
  int iVar2;
  char **ppcVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cc3b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = (TTaunt *)operator_new(0x198);
  uStack_4 = 0;
  if (pTVar1 == (TTaunt *)0x0) {
    pTVar1 = (TTaunt *)0x0;
  }
  else {
    pTVar1 = (TTaunt *)TTaunt::TTaunt(pTVar1,rge_base_game->sound_system);
  }
  param_1->taunt = pTVar1;
  param_1->HostWnd = param_2;
  ppcVar3 = param_1->Chat;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppcVar3 = (char *)0x0;
    ppcVar3 = ppcVar3 + 1;
  }
  uStack_4 = 0xffffffff;
  param_1->CurrentMsgNo = 0;
  iVar2 = 0;
  do {
    TChat::setInChatGroup(param_1,iVar2,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00423ccb
// Address: 00423ccb
void __fastcall FUN_00423ccb(TChat *param_1)
{
  TTaunt *this;
  
  TChat::ClearChat(param_1);
  this = param_1->taunt;
  if (this != (TTaunt *)0x0) {
    TTaunt::~TTaunt(this);
    operator_delete(this);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00423cf4
// Address: 00423cf4
// [HELPER] s__s___s: "%s: %s"
int __thiscall FUN_00423cf4(undefined4 *param_1,char *param_2,char *param_3,uchar param_4)
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if (param_3 == (char *)0x0) {
    return 0;
  }
  iVar2 = param_1[0x3e];
  param_1[0x3e] = iVar2 + 1;
  if (0x32 < iVar2 + 1) {
    param_1[0x3e] = 0;
  }
  if (param_1[param_1[0x3e] + 0xb] != 0) {
    free(param_1[param_1[0x3e] + 0xb]);
  }
  uVar4 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar5 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = calloc(~uVar4 + ~uVar5 + 1,1);
  param_1[param_1[0x3e] + 0xb] = uVar3;
  iVar2 = param_1[param_1[0x3e] + 0xb];
  if (iVar2 == 0) {
    return iVar2;
  }
  sprintf(iVar2,s__s___s,param_2,param_3);
  PostMessageA(*param_1,0x400,0x17d5,param_1[0x3e]);
  if ((TTaunt *)param_1[0x3f] != (TTaunt *)0x0) {
    TTaunt::PlayTauntStr((TTaunt *)param_1[0x3f],param_3,param_4);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00423dee
// Address: 00423dee
undefined4 __thiscall FUN_00423dee(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x33)) {
    return *(undefined4 *)(param_1 + 0x2c + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00423e09
// Address: 00423e09
void __fastcall FUN_00423e09(int param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x2c);
  iVar2 = 0x33;
  do {
    if (*piVar1 != 0) {
      free(*piVar1);
    }
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0xf8) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00423e46
// Address: 00423e46
undefined4 FUN_00423e46(void)
{
  return 0x32;
}

// --------------------------------------------------

// Function: FUN_00423e56
// Address: 00423e56
void __thiscall FUN_00423e56(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00423e69
// Address: 00423e69
void __thiscall FUN_00423e69(int param_1,int param_2,undefined4 param_3)
{
  if ((0 < param_2) && (param_2 < 10)) {
    *(undefined4 *)(param_1 + 4 + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00423e88
// Address: 00423e88
undefined4 __thiscall FUN_00423e88(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 10)) {
    return *(undefined4 *)(param_1 + 4 + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00423ea9
// Address: 00423ea9
void __fastcall FUN_00423ea9(int param_1)
{
  if (*(TTaunt **)(param_1 + 0xfc) != (TTaunt *)0x0) {
    TTaunt::StopSoundSystem(*(TTaunt **)(param_1 + 0xfc));
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00423edf
// Address: 00423edf
void FUN_00423edf(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int iStack_10;
  int aiStack_c [3];
  
  pbVar5 = (byte *)(param_2 + 3);
  iVar2 = param_2 - param_1;
  iStack_10 = 0;
  pbVar7 = (byte *)(param_1 + 1);
  do {
    if ((iStack_10 == param_5) || (iStack_10 == param_6)) {
      pbVar5[-3] = pbVar7[-1];
      pbVar7[iVar2] = *pbVar7;
      pbVar5[-1] = pbVar7[1];
      *pbVar5 = pbVar7[2];
    }
    else {
      uVar4 = *(uint *)(pbVar7 + -1) & 0xff;
      aiStack_c[1] = (uint)*pbVar7;
      aiStack_c[2] = (uint)pbVar7[1];
      param_2 = 2;
      do {
        piVar1 = aiStack_c;
        iVar6 = 2;
        do {
          piVar1 = piVar1 + 1;
          iVar3 = piVar1[-1];
          if (iVar3 < *piVar1) {
            piVar1[-1] = *piVar1;
            *piVar1 = iVar3;
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      iVar6 = (aiStack_c[2] + aiStack_c[1]) * (0xff - uVar4);
      iVar6 = ((int)(iVar6 + (iVar6 >> 0x1f & 0x1ffU)) >> 9) + uVar4;
      iVar3 = ((int)((param_3 & 0xff) * iVar6) / 0xff - uVar4) * param_4;
      pbVar5[-3] = (((char)(iVar3 / 100) + (char)(iVar3 >> 0x1f)) -
                   (char)((longlong)iVar3 * 0x51eb851f >> 0x3f)) + pbVar7[-1];
      iVar3 = ((int)((param_3 >> 8 & 0xff) * iVar6) / 0xff - (uint)*pbVar7) * param_4;
      pbVar7[iVar2] =
           (((char)(iVar3 / 100) + (char)(iVar3 >> 0x1f)) -
           (char)((longlong)iVar3 * 0x51eb851f >> 0x3f)) + *pbVar7;
      iVar6 = ((int)((param_3 >> 0x10 & 0xff) * iVar6) / 0xff - (uint)pbVar7[1]) * param_4;
      pbVar5[-1] = (((char)(iVar6 / 100) + (char)(iVar6 >> 0x1f)) -
                   (char)((longlong)iVar6 * 0x51eb851f >> 0x3f)) + pbVar7[1];
      *pbVar5 = pbVar7[2];
    }
    iStack_10 = iStack_10 + 1;
    pbVar7 = pbVar7 + 4;
    pbVar5 = pbVar5 + 4;
  } while (iStack_10 < 0x100);
  return;
}

// --------------------------------------------------

// Function: RGE_translate_palette
// Address: 00423ee0
/* WARNING: Variable defined which should be unmapped: index1 */
/* void __cdecl RGE_translate_palette(struct tagPALETTEENTRY *,struct tagPALETTEENTRY *,struct
   tagPALETTEENTRY,long,int,int) */

void __cdecl
RGE_translate_palette
          (tagPALETTEENTRY *param_1,tagPALETTEENTRY *param_2,tagPALETTEENTRY param_3,long param_4,
          int param_5,int param_6)
{
  byte bVar1;
  tagPALETTEENTRY tVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  uchar *puVar8;
  long index1;
  long intense [3];
  
  puVar6 = &param_2->peFlags;
  iVar4 = (int)param_2 - (int)param_1;
  intense[0] = 0;
  puVar8 = &param_1->peGreen;
  do {
    if ((intense[0] == param_5) || (intense[0] == param_6)) {
      ((tagPALETTEENTRY *)(puVar6 + -3))->peRed = ((tagPALETTEENTRY *)(puVar8 + -1))->peRed;
      puVar8[iVar4] = *puVar8;
      puVar6[-1] = puVar8[1];
      *puVar6 = puVar8[2];
    }
    else {
      tVar2 = *(tagPALETTEENTRY *)(puVar8 + -1);
      intense[1] = (uint)tVar2 & 0xff;
      bVar1 = puVar8[1];
      intense[2] = (uint)*puVar8;
      param_2 = (tagPALETTEENTRY *)0x2;
      do {
        piVar3 = intense + 2;
        iVar7 = 2;
        do {
          iVar5 = piVar3[-1];
          if (iVar5 < *piVar3) {
            piVar3[-1] = *piVar3;
            *piVar3 = iVar5;
          }
          piVar3 = piVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        param_2 = (tagPALETTEENTRY *)&param_2[-1].peFlags;
      } while (param_2 != (tagPALETTEENTRY *)0x0);
      iVar7 = ((uint)bVar1 + intense[2]) * (0xff - intense[1]);
      iVar7 = ((int)(iVar7 + (iVar7 >> 0x1f & 0x1ffU)) >> 9) + intense[1];
      iVar5 = ((int)(((uint)param_3 & 0xff) * iVar7) / 0xff - ((uint)tVar2 & 0xff)) * param_4;
      ((tagPALETTEENTRY *)(puVar6 + -3))->peRed =
           (((char)(iVar5 / 100) + (char)(iVar5 >> 0x1f)) -
           (char)((longlong)iVar5 * 0x51eb851f >> 0x3f)) + ((tagPALETTEENTRY *)(puVar8 + -1))->peRed
      ;
      iVar5 = ((int)(((uint)param_3 >> 8 & 0xff) * iVar7) / 0xff - (uint)*puVar8) * param_4;
      puVar8[iVar4] =
           (((char)(iVar5 / 100) + (char)(iVar5 >> 0x1f)) -
           (char)((longlong)iVar5 * 0x51eb851f >> 0x3f)) + *puVar8;
      iVar7 = ((int)(((uint)param_3 >> 0x10 & 0xff) * iVar7) / 0xff - (uint)puVar8[1]) * param_4;
      puVar6[-1] = (((char)(iVar7 / 100) + (char)(iVar7 >> 0x1f)) -
                   (char)((longlong)iVar7 * 0x51eb851f >> 0x3f)) + puVar8[1];
      *puVar6 = puVar8[2];
    }
    intense[0] = intense[0] + 1;
    puVar8 = puVar8 + 4;
    puVar6 = puVar6 + 4;
  } while (intense[0] < 0x100);
  return;
}

// --------------------------------------------------

// Function: FUN_004240a1
// Address: 004240a1
// [HELPER] s_C__msdev_work_age1_x1_color_cpp: "C:\msdev\work\age1_x1\color.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004240a1(TDrawArea *param_1,tagPALETTEENTRY param_2,float param_3,char param_4,int param_5,
                 int param_6,int param_7)
{
  float fVar1;
  bool bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  tagPALETTEENTRY *ptVar9;
  tagPALETTEENTRY atStack_800 [256];
  tagPALETTEENTRY atStack_400 [256];
  
  iVar3 = 0;
  do {
    (&atStack_800[0].peRed)[iVar3] = '\0';
    (&atStack_800[0x100].peRed)[iVar3] = '\0';
    (&atStack_800[0].peBlue)[iVar3] = '\0';
    (&atStack_800[0x100].peBlue)[iVar3] = '\0';
    (&atStack_800[0].peGreen)[iVar3] = '\0';
    (&atStack_800[0x100].peGreen)[iVar3] = '\0';
    (&atStack_800[0].peFlags)[iVar3] = '\0';
    (&atStack_800[0x100].peFlags)[iVar3] = '\0';
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x400);
  if (param_5 == 0) {
    TDrawArea::GetPalette(param_1,atStack_800);
  }
  else {
    ptVar9 = atStack_800;
    iVar3 = 0x100;
    puVar4 = (undefined1 *)(param_5 + 1);
    do {
      puVar5 = puVar4 + 4;
      ptVar9->peRed = puVar4[-1];
      puVar5[(int)atStack_800 + (-3 - param_5)] = puVar4[1];
      puVar5[(int)atStack_800 + (-4 - param_5)] = *puVar4;
      puVar5[(int)atStack_800 + (-2 - param_5)] = puVar4[2];
      ptVar9 = ptVar9 + 1;
      iVar3 = iVar3 + -1;
      puVar4 = puVar5;
    } while (iVar3 != 0);
  }
  bVar2 = false;
  uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x69);
  if (param_4 != '\x01') {
    do {
      uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x88);
      fVar1 = param_3 - (float)(int)(uVar7 - uVar6) * _DAT_0056f020;
      if (((param_3 <= (float)_DAT_0056f028) || (param_3 < fVar1)) || (fVar1 < _DAT_0056f030)) {
        lVar8 = 0;
      }
      else {
        lVar8 = __ftol();
      }
      if (lVar8 < 1) {
        lVar8 = 0;
        bVar2 = true;
      }
      RGE_translate_palette(atStack_800,atStack_800 + 0x100,param_2,lVar8,param_6,param_7);
      TDrawArea::SetPalette(param_1,atStack_800 + 0x100);
    } while (!bVar2);
    return;
  }
  do {
    uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x70);
    fVar1 = (float)(int)(uVar7 - uVar6) * _DAT_0056f020;
    if (((param_3 <= (float)_DAT_0056f028) || (param_3 < fVar1)) || (fVar1 < _DAT_0056f030)) {
      lVar8 = 100;
    }
    else {
      lVar8 = __ftol();
    }
    if (99 < lVar8) {
      lVar8 = 100;
      bVar2 = true;
    }
    RGE_translate_palette(atStack_800,atStack_800 + 0x100,param_2,lVar8,param_6,param_7);
    TDrawArea::SetPalette(param_1,atStack_800 + 0x100);
  } while (!bVar2);
  return;
}

// --------------------------------------------------

// Function: RGE_fade_palette
// Address: 004240b0
// [HELPER] s_C__msdev_work_age1_x1_color_cpp: "C:\msdev\work\age1_x1\color.cpp"
/* WARNING: Variable defined which should be unmapped: delta_time */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl RGE_fade_palette(class TDrawArea *,struct tagPALETTEENTRY,float,unsigned char,struct
   tagPALETTEENTRY *,int,int) */

void __cdecl
RGE_fade_palette(TDrawArea *param_1,tagPALETTEENTRY param_2,float param_3,uchar param_4,
                tagPALETTEENTRY *param_5,int param_6,int param_7)
{
  float fVar1;
  bool bVar2;
  int iVar3;
  uchar *puVar4;
  uchar *puVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  tagPALETTEENTRY *ptVar9;
  float delta_time;
  uchar done;
  long old_time;
  float fade_time2;
  tagPALETTEENTRY palette1 [256];
  tagPALETTEENTRY palette2 [256];
  
  iVar3 = 0;
  do {
    (&palette1[1].peRed)[iVar3] = '\0';
    (&palette2[1].peRed)[iVar3] = '\0';
    (&palette1[1].peBlue)[iVar3] = '\0';
    (&palette2[1].peBlue)[iVar3] = '\0';
    (&palette1[1].peGreen)[iVar3] = '\0';
    (&palette2[1].peGreen)[iVar3] = '\0';
    (&palette1[1].peFlags)[iVar3] = '\0';
    (&palette2[1].peFlags)[iVar3] = '\0';
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x400);
  if (param_5 == (tagPALETTEENTRY *)0x0) {
    TDrawArea::GetPalette(param_1,palette1 + 1);
  }
  else {
    ptVar9 = palette1;
    iVar3 = 0x100;
    puVar4 = &param_5->peGreen;
    do {
      ptVar9 = ptVar9 + 1;
      puVar5 = puVar4 + 4;
      ptVar9->peRed = ((tagPALETTEENTRY *)(puVar4 + -1))->peRed;
      puVar5[(int)palette1 + (1 - (int)param_5)] = puVar4[1];
      puVar5[(int)palette1 - (int)param_5] = *puVar4;
      puVar5[(int)palette1 + (2 - (int)param_5)] = puVar4[2];
      iVar3 = iVar3 + -1;
      puVar4 = puVar5;
    } while (iVar3 != 0);
  }
  bVar2 = false;
  uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x69);
  palette1[0] = (tagPALETTEENTRY)(param_3 * param_3);
  if (param_4 != '\x01') {
    do {
      uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x88);
      fVar1 = param_3 - (float)(int)(uVar7 - uVar6) * _DAT_0056f020;
      if (((param_3 <= (float)_DAT_0056f028) || (param_3 < fVar1)) || (fVar1 < _DAT_0056f030)) {
        lVar8 = 0;
      }
      else {
        lVar8 = __ftol();
      }
      if (lVar8 < 1) {
        lVar8 = 0;
        bVar2 = true;
      }
      RGE_translate_palette(palette1 + 1,palette2 + 1,param_2,lVar8,param_6,param_7);
      TDrawArea::SetPalette(param_1,palette2 + 1);
    } while (!bVar2);
    return;
  }
  do {
                    /* language.dll match for 0x70: "B" */
    uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x70);
    fVar1 = (float)(int)(uVar7 - uVar6) * _DAT_0056f020;
    if (((param_3 <= (float)_DAT_0056f028) || (param_3 < fVar1)) || (fVar1 < _DAT_0056f030)) {
      lVar8 = 100;
    }
    else {
      lVar8 = __ftol();
    }
    if (99 < lVar8) {
      lVar8 = 100;
      bVar2 = true;
    }
    RGE_translate_palette(palette1 + 1,palette2 + 1,param_2,lVar8,param_6,param_7);
    TDrawArea::SetPalette(param_1,palette2 + 1);
  } while (!bVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_00424345
// Address: 00424345
// [HELPER] s__hd: "%hd"
// [HELPER] s_data__s: "data\%s"
// [HELPER] s_r: "r"
undefined4 * __thiscall FUN_00424345(undefined4 *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined1 auStack_12e [2];
  undefined1 auStack_12c [300];
  
  *param_1 = &RGE_Color_Table::_vftable_;
  rge_read(param_2,param_1 + 1,0x1e);
  rge_read(param_2,(void *)((int)param_1 + 0x26),2);
  rge_read(param_2,(void *)((int)param_1 + 0x22),2);
  rge_read(param_2,(void *)((int)param_1 + 0x25),1);
  rge_read(param_2,param_1 + 9,1);
  sprintf(auStack_12c,s_data__s,param_1 + 1);
  iVar1 = fopen(auStack_12c,s_r);
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      fscanf(iVar1,s__hd,auStack_12e);
      *(undefined1 *)(iVar2 + 0x28 + (int)param_1) = auStack_12e[0];
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    fclose(iVar1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042441b
// Address: 0042441b
RGE_Color_Table * __thiscall FUN_0042441b(RGE_Color_Table *param_1,byte param_2)
{
  RGE_Color_Table::~RGE_Color_Table(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042443e
// Address: 0042443e
// [HELPER] s__col: ".col"
// [HELPER] s__hd__s__hd__hd: "%hd %s %hd %hd"
undefined4 * __thiscall FUN_0042443e(undefined4 *param_1,undefined4 param_2,undefined2 param_3)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcStack_4;
  
  *(undefined2 *)((int)param_1 + 0x26) = param_3;
  *param_1 = &RGE_Color_Table::_vftable_;
  puVar6 = param_1 + 10;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  pcVar8 = (char *)(param_1 + 1);
  pcStack_4 = (char *)0x0;
  fscanf(param_2,s__hd__s__hd__hd,(int)param_1 + 0x22,pcVar8,&param_3,&param_2);
  *(undefined1 *)((int)param_1 + 0x25) = (undefined1)param_3;
  *(undefined1 *)(param_1 + 9) = (undefined1)param_2;
  addstring(&pcStack_4,pcVar8,&s__col);
  uVar3 = 0xffffffff;
  pcVar5 = pcStack_4;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar8 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar8 = pcVar8 + 1;
  }
  if (pcStack_4 != (char *)0x0) {
    free(pcStack_4);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004244e9
// Address: 004244e9
// [HELPER] s__col: ".col"
// [HELPER] s__hd: "%hd"
// [HELPER] s_data__s: "data\%s"
// [HELPER] s_r: "r"
undefined4 * __thiscall FUN_004244e9(undefined4 *param_1,char *param_2)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  uint uStack_130;
  undefined1 auStack_12c [300];
  
  *param_1 = &RGE_Color_Table::_vftable_;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  puVar7 = param_1 + 10;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = param_2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar9 = (char *)(param_1 + 1);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uStack_130 = 0xffffffff;
  pcVar5 = &s__col;
  do {
    pcVar9 = pcVar5;
    if (uStack_130 == 0) break;
    uStack_130 = uStack_130 - 1;
    pcVar9 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar9;
  } while (cVar1 != '\0');
  uStack_130 = ~uStack_130;
  iVar2 = -1;
  pcVar5 = (char *)(param_1 + 1);
  do {
    pcVar8 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar8 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar8;
  } while (cVar1 != '\0');
  pcVar5 = pcVar9 + -uStack_130;
  pcVar9 = pcVar8 + -1;
  for (uVar3 = uStack_130 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uStack_130 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar9 = pcVar9 + 1;
  }
  sprintf(auStack_12c,s_data__s,param_1 + 1);
  iVar2 = fopen(auStack_12c,s_r);
  if (iVar2 != 0) {
    iVar6 = 0;
    do {
      fscanf(iVar2,s__hd,&uStack_130);
      *(undefined1 *)(iVar6 + (int)(param_1 + 10)) = (undefined1)uStack_130;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x100);
    fclose(iVar2);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004245e3
// Address: 004245e3
void __thiscall
FUN_004245e3(undefined4 *param_1,TDrawArea *param_2,long param_3,tagPALETTEENTRY *param_4,
            int param_5)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  uchar *puVar7;
  undefined4 *puVar8;
  tagPALETTEENTRY tStack_81c;
  int iStack_814;
  tagPALETTEENTRY atStack_800 [256];
  tagPALETTEENTRY atStack_400 [256];
  
  *param_1 = &RGE_Color_Table::_vftable_;
  if (param_5 == 0) {
    TDrawArea::GetPalette(param_2,atStack_800);
  }
  else {
    puVar5 = &atStack_800[0].peGreen;
    iVar4 = 0x100;
    puVar1 = (undefined1 *)(param_5 + 2);
    do {
      puVar2 = puVar1 + 4;
      ((tagPALETTEENTRY *)(puVar5 + -1))->peRed = puVar1[-2];
      *puVar5 = puVar1[-1];
      puVar2[(int)atStack_800 + (-4 - param_5)] = *puVar1;
      puVar2[(int)atStack_800 + (-3 - param_5)] = puVar1[1];
      puVar5 = puVar5 + 4;
      iVar4 = iVar4 + -1;
      puVar1 = puVar2;
    } while (iVar4 != 0);
  }
  if (param_4 == (tagPALETTEENTRY *)0x0) {
    tStack_81c.peRed = '\0';
    tStack_81c.peGreen = '\0';
    tStack_81c.peBlue = '\0';
    tStack_81c.peFlags = '\0';
  }
  else {
    tStack_81c = *param_4;
  }
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  puVar8 = param_1 + 10;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  RGE_translate_palette(atStack_800,atStack_400,tStack_81c,param_3,-1,-1);
  puVar5 = &atStack_400[0].peGreen;
  iStack_814 = 0;
  do {
    iVar6 = 0;
    tStack_81c.peRed = '\0';
    tStack_81c.peGreen = '\0';
    tStack_81c.peBlue = '\0';
    tStack_81c.peFlags = '\0';
    iVar4 = 20000;
    puVar7 = &atStack_800[0].peGreen;
    do {
      iVar3 = (uint)((tagPALETTEENTRY *)(puVar5 + -1))->peRed -
              (uint)((tagPALETTEENTRY *)(puVar7 + -1))->peRed;
      iVar3 = iVar3 * iVar3 + ((uint)*puVar5 - (uint)*puVar7) * ((uint)*puVar5 - (uint)*puVar7) +
              ((uint)puVar5[1] - (uint)puVar7[1]) * ((uint)puVar5[1] - (uint)puVar7[1]);
      if (iVar3 < iVar4) {
        iVar4 = iVar3;
        tStack_81c = (tagPALETTEENTRY)iVar6;
      }
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 4;
    } while (iVar6 < 0x100);
    *(uchar *)(iStack_814 + 0x28 + (int)param_1) = tStack_81c.peRed;
    iStack_814 = iStack_814 + 1;
    puVar5 = puVar5 + 4;
  } while (iStack_814 < 0x100);
  return;
}

// --------------------------------------------------

// Function: FUN_00424798
// Address: 00424798
void __fastcall FUN_00424798(undefined4 *param_1)
{
  *param_1 = &RGE_Color_Table::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_004247a7
// Address: 004247a7
void __thiscall FUN_004247a7(int param_1,int param_2)
{
  rge_write(param_2,(void *)(param_1 + 4),0x1e);
  rge_write(param_2,(void *)(param_1 + 0x26),2);
  rge_write(param_2,(void *)(param_1 + 0x22),2);
  rge_write(param_2,(void *)(param_1 + 0x25),1);
  rge_write(param_2,(void *)(param_1 + 0x24),1);
  return;
}

// --------------------------------------------------

// Function: FUN_00424808
// Address: 00424808
// [HELPER] do_color_log: " "
void FUN_00424808(uint param_1,undefined4 param_2,int param_3)
{
  TDrawSystem *pTVar1;
  IDirectDrawSurface *pIVar2;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int *piStack_b8;
  IDirectDrawSurface *pIStack_b4;
  int *piStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  void *pvStack_a4;
  int *piStack_a0;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int aiStack_7c [3];
  undefined4 uStack_70;
  int iStack_6c;
  int iStack_68;
  undefined4 auStack_64 [2];
  uint uStack_5c;
  uint uStack_44;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_14;
  
  if ((((do_color_log != '\0') && (rge_base_game != (RGE_Base_Game *)0x0)) &&
      (1 < rge_base_game->prog_mode)) &&
     ((pTVar1 = rge_base_game->draw_system, pTVar1 != (TDrawSystem *)0x0 &&
      (pTVar1->PrimarySurface != (IDirectDrawSurface *)0x0)))) {
    aiStack_7c[1] = 0;
    uStack_70 = 10;
    aiStack_7c[0] = pTVar1->DrawArea->Width / 2 + (2 - param_3) * 0x14;
    aiStack_7c[2] = aiStack_7c[0] + 10;
    iStack_68 = 0;
    iStack_6c = aiStack_7c[0];
    if (pTVar1->ScreenMode == '\x02') {
      pvStack_a4 = pTVar1->Wnd;
      piStack_a0 = &iStack_6c;
      iStack_a8 = 0x4248b8;
      ClientToScreen();
    }
    iStack_84 = iStack_6c + 10;
    iStack_80 = iStack_68 + 10;
    piStack_a0 = auStack_64;
    auStack_64[0] = 100;
    pIStack_b4 = pTVar1->PrimarySurface;
    pvStack_a4 = (void *)0x1000400;
    iStack_a8 = 0;
    piStack_b0 = &iStack_8c;
    uStack_ac = 0;
    piStack_b8 = (int *)0x42490f;
    iStack_8c = iStack_6c;
    iStack_88 = iStack_68;
    uStack_14 = param_1 & 0xff;
    (**(code **)((int)*pIStack_b4 + 0x14))();
    aiStack_7c[0] = 100;
    piStack_b8 = aiStack_7c;
    uStack_bc = 0x1000400;
    pIVar2 = pTVar1->DrawArea->DrawSurface;
    uStack_c0 = 0;
    uStack_c4 = 0;
    uStack_2c = param_1 & 0xff;
    (**(code **)((int)*pIVar2 + 0x14))(pIVar2,&stack0xffffff6c);
    piStack_a0 = (int *)((int)piStack_a0 + 10);
    piStack_b8 = (int *)((int)piStack_b8 + 10);
    iStack_a8 = iStack_a8 + 10;
    piStack_b0 = (int *)((int)piStack_b0 + 10);
    uStack_44 = uStack_28 & 0xff;
    (**(code **)((int)*pTVar1->PrimarySurface + 0x14))
              (pTVar1->PrimarySurface,&uStack_bc,0,0,0x1000400,&stack0xffffff6c);
    uStack_ac = 100;
    pIVar2 = pTVar1->DrawArea->DrawSurface;
    uStack_5c = uStack_28 & 0xff;
    (**(code **)((int)*pIVar2 + 0x14))(pIVar2,&uStack_c4,0,0,0x1000400,&uStack_ac);
  }
  return;
}

// --------------------------------------------------

// Function: color_log
// Address: 00424810
// [HELPER] do_color_log: " "
/* WARNING: Variable defined which should be unmapped: scr_dest */
/* void __cdecl color_log(unsigned char,unsigned char,int) */

void __cdecl color_log(uchar param_1,uchar param_2,int param_3)
{
  TDrawSystem *pTVar1;
  IDirectDrawSurface *pIVar2;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  long *plStack_b8;
  IDirectDrawSurface *pIStack_b4;
  long *plStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  void *pvStack_a4;
  ulong *puStack_a0;
  tagRECT scr_dest;
  tagRECT back_dest;
  tagPOINT point;
  _DDBLTFX ddbltfx;
  
  if ((((do_color_log != '\0') && (rge_base_game != (RGE_Base_Game *)0x0)) &&
      (1 < rge_base_game->prog_mode)) &&
     ((pTVar1 = rge_base_game->draw_system, pTVar1 != (TDrawSystem *)0x0 &&
      (pTVar1->PrimarySurface != (IDirectDrawSurface *)0x0)))) {
    back_dest.right = 0;
    point.x = 10;
    back_dest.top = pTVar1->DrawArea->Width / 2 + (2 - param_3) * 0x14;
    back_dest.bottom = back_dest.top + 10;
    ddbltfx.dwSize = 0;
    point.y = back_dest.top;
    if (pTVar1->ScreenMode == '\x02') {
      pvStack_a4 = pTVar1->Wnd;
      puStack_a0 = (ulong *)&point.y;
      iStack_a8 = 0x4248b8;
      ClientToScreen();
    }
    scr_dest.bottom = point.y + 10;
    back_dest.left = ddbltfx.dwSize + 10;
    puStack_a0 = &ddbltfx.dwDDFX;
    ddbltfx.dwDDFX = 100;
    pIStack_b4 = pTVar1->PrimarySurface;
    pvStack_a4 = (void *)0x1000400;
    iStack_a8 = 0;
    plStack_b0 = &scr_dest.top;
    uStack_ac = 0;
    plStack_b8 = (long *)0x42490f;
    scr_dest.top = point.y;
    scr_dest.right = ddbltfx.dwSize;
    ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = (uint)param_1;
    (**(code **)((int)*pIStack_b4 + 0x14))();
    back_dest.top = 100;
    plStack_b8 = &back_dest.top;
    uStack_bc = 0x1000400;
    pIVar2 = pTVar1->DrawArea->DrawSurface;
    uStack_c0 = 0;
    uStack_c4 = 0;
    ddbltfx.dwReserved = (uint)param_1;
    (**(code **)((int)*pIVar2 + 0x14))(pIVar2,&stack0xffffff6c);
    puStack_a0 = (ulong *)((int)puStack_a0 + 10);
    plStack_b8 = (long *)((int)plStack_b8 + 10);
    iStack_a8 = iStack_a8 + 10;
    plStack_b0 = (long *)((int)plStack_b0 + 10);
    ddbltfx.dwZDestConstBitDepth = ddbltfx.dwAlphaDestConstBitDepth & 0xff;
    (**(code **)((int)*pTVar1->PrimarySurface + 0x14))
              (pTVar1->PrimarySurface,&uStack_bc,0,0,0x1000400,&stack0xffffff6c);
    uStack_ac = 100;
    pIVar2 = pTVar1->DrawArea->DrawSurface;
    ddbltfx.dwDDROP = ddbltfx.dwAlphaDestConstBitDepth & 0xff;
    (**(code **)((int)*pIVar2 + 0x14))(pIVar2,&uStack_c4,0,0,0x1000400,&uStack_ac);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004249ca
// Address: 004249ca
RGE_Communications_Addresses * __thiscall
FUN_004249ca(RGE_Communications_Addresses *param_1,TCommunications_Handler *param_2)
{
  int iVar1;
  char *pcVar2;
  undefined4 unaff_ESI;
  IPAD *pIVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 *puStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_4 = (undefined4 *)0xffffffff;
  pcStack_8 = FUN_0055cc5b;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->comm = param_2;
  RGE_Communications_Addresses::EraseInformation(param_1);
  iVar1 = _WSAStartup_8(0x101,&param_1->wsaData);
  puStack_4 = (undefined4 *)operator_new(0x504);
  uStack_c = 0;
  if (puStack_4 == (undefined4 *)0x0) {
    pIVar3 = (IPAD *)0x0;
  }
  else {
    pIVar3 = (IPAD *)(puStack_4 + 1);
    *puStack_4 = 8;
    _eh_vector_constructor_iterator_(pIVar3,0xa0,8,IPAD::IPAD,IPAD::~IPAD);
  }
  uStack_c = 0xffffffff;
  param_1->pIPAD = pIVar3;
  if (iVar1 == 0) {
    param_1->Status = 1;
    RGE_Communications_Addresses::GetHostName(param_1);
    pcVar2 = (char *)operator_new(0xff);
    RGE_Communications_Addresses::SetIPAddresses(param_1,pcVar2);
    RGE_Communications_Addresses::SetIPAliases(param_1,pcVar2);
    operator_delete(pcVar2);
  }
  else {
    param_1->Status = 0;
  }
  *unaff_FS_OFFSET = unaff_ESI;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00424ab3
// Address: 00424ab3
void * __thiscall FUN_00424ab3(void *param_1,byte param_2)
{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_(param_1,0xa0,*(int *)((int)param_1 + -4),IPAD::~IPAD);
    operator_delete((void *)((int)param_1 + -4));
    return param_1;
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00424b07
// Address: 00424b07
void __fastcall FUN_00424b07(RGE_Communications_Addresses *param_1)
{
  IPAD *pIVar1;
  
  RGE_Communications_Addresses::EraseInformation(param_1);
  if (param_1->Status != 0) {
    _WSACleanup_0();
  }
  pIVar1 = param_1->pIPAD;
  if (pIVar1 != (IPAD *)0x0) {
    _eh_vector_destructor_iterator_(pIVar1,0xa0,*(int *)(pIVar1[-1].Alias + 0x7c),IPAD::~IPAD);
    operator_delete(pIVar1[-1].Alias + 0x7c);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00424b53
// Address: 00424b53
int __fastcall FUN_00424b53(int param_1)
{
  gethostname(param_1 + 0x194,0x80);
  return param_1 + 0x194;
}

// --------------------------------------------------

// Function: FUN_00424b76
// Address: 00424b76
int __fastcall FUN_00424b76(int param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 *unaff_retaddr;
  
  iVar2 = param_1 + 0x194;
  if (iVar2 == 0) {
    return iVar2;
  }
  iVar2 = gethostbyname(iVar2);
  if (iVar2 == 0) {
    return 0;
  }
  *unaff_retaddr = 0;
  puVar5 = *(undefined4 **)(iVar2 + 4);
  *(undefined4 *)(param_1 + 0x21c) = 0;
  pcVar6 = (char *)*puVar5;
  do {
    if (pcVar6 == (char *)0x0) {
      return *(int *)(param_1 + 0x21c);
    }
    puVar5 = puVar5 + 1;
    uVar3 = 0xffffffff;
    do {
      pcVar7 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar7 + -uVar3;
    pcVar7 = (char *)(*(int *)(param_1 + 0x21c) * 0xa0 + 0x20 + *(int *)(param_1 + 0x220));
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x21c) + 1;
    pcVar6 = (char *)*puVar5;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00424c18
// Address: 00424c18
// [HELPER] s__: "}"
undefined1 * __thiscall FUN_00424c18(int param_1,uint param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_2 * 0xa0 + *(int *)(param_1 + 0x220));
  if ((puVar1 == (undefined1 *)0x0) || (*(uint *)(param_1 + 0x218) < param_2)) {
    puVar1 = &s__;
  }
  return puVar1;
}

// --------------------------------------------------

// Function: FUN_00424c48
// Address: 00424c48
// [HELPER] s__: "}"
undefined1 * __thiscall FUN_00424c48(int param_1,uint param_2)
{
  undefined1 *puVar1;
  
  if ((*(uint *)(param_1 + 0x21c) < param_2) ||
     (puVar1 = (undefined1 *)(param_2 * 0xa0 + 0x20 + *(int *)(param_1 + 0x220)),
     puVar1 == (undefined1 *)0x0)) {
    puVar1 = &s__;
  }
  return puVar1;
}

// --------------------------------------------------

// Function: FUN_00424c7a
// Address: 00424c7a
// [HELPER] s__d__d__d__d_: "%d.%d.%d.%d\n"
int __fastcall FUN_00424c7a(int param_1)
{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *unaff_retaddr;
  
  iVar3 = param_1 + 0x194;
  if (iVar3 == 0) {
    return iVar3;
  }
  iVar3 = gethostbyname(iVar3);
  if (iVar3 == 0) {
    return 0;
  }
  *unaff_retaddr = '\0';
  puVar6 = *(undefined4 **)(iVar3 + 0xc);
  *(undefined4 *)(param_1 + 0x218) = 0;
  puVar2 = (undefined1 *)*puVar6;
  do {
    if (puVar2 == (undefined1 *)0x0) {
      return *(int *)(param_1 + 0x218);
    }
    sprintf(&stack0xffffffe0,s__d__d__d__d_,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    uVar4 = 0xffffffff;
    pcVar7 = &stack0xffffffe0;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    puVar6 = puVar6 + 1;
    iVar3 = -1;
    pcVar7 = unaff_retaddr;
    do {
      pcVar8 = pcVar7;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar7 = &stack0xffffffe0;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = (char *)(*(int *)(param_1 + 0x218) * 0xa0 + *(int *)(param_1 + 0x220));
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    *(int *)(param_1 + 0x218) = *(int *)(param_1 + 0x218) + 1;
    puVar2 = (undefined1 *)*puVar6;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00424d84
// Address: 00424d84
// [HELPER] s_: ""
void __fastcall FUN_00424d84(int param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = s_;
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
  pcVar5 = (char *)(param_1 + 0x194);
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
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(undefined4 *)(param_1 + 0x218) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00424dcf
// Address: 00424dcf
// [HELPER] s_: ""
char * __fastcall FUN_00424dcf(char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = s_;
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
  pcVar5 = param_1;
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
  pcVar4 = s_;
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
  pcVar5 = param_1 + 0x20;
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00424e22
// Address: 00424e22
void FUN_00424e22(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00424e31
// Address: 00424e31
void __thiscall FUN_00424e31(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  param_1[1] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00424e52
// Address: 00424e52
// [HELPER] s_COMM__Send_msg_to_window_WM_USER: "COMM: Send msg to window WM_USER  Msg=%d  Param=%d "
void __thiscall FUN_00424e52(undefined4 *param_1,undefined4 param_2,undefined4 param_3)
{
  PostMessageA(*param_1,0x400,param_2,param_3);
  TDebuggingLog::Log(L,(char *)L,s_COMM__Send_msg_to_window_WM_USER,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_00424e95
// Address: 00424e95
void FUN_00424e95(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00424ea1
// Address: 00424ea1
// [HELPER] s_COM_Aborted: "COM Aborted"
// [HELPER] s_COM_Error_pending: "COM Error pending"
// [HELPER] s_COM_Invalid_Handle: "COM Invalid Handle"
// [HELPER] s_COM_Invalid_Pointer: "COM Invalid Pointer"
// [HELPER] s_COM_error_Access_Denied: "COM error Access Denied"
// [HELPER] s____COMM______DP_CALL_FAILED__Cod: "+++COMM______DP CALL FAILED_(Code %u)_____ %s____"
// [HELPER] s_____Access_Denied___busy_service: "!!! Access Denied - busy service or invalid use of host commands."
// [HELPER] s_____Active_Players___command_inv: "!!! Active Players - command invalid with active players."
// [HELPER] s_____Already_Initialized: "!!! Already Initialized"
// [HELPER] s_____Application_has_not_been_sta: "!!! Application has not been started yet."
// [HELPER] s_____Buffer_size_failure__LARGE_: "!!! Buffer size failure (LARGE)"
// [HELPER] s_____Buffer_size_failure__SMALL_: "!!! Buffer size failure (SMALL)"
// [HELPER] s_____Busy_Rcvd: "!!! Busy Rcvd"
// [HELPER] s_____COMM_TIMEOUT_Rcvd_from_HOST_: "!!! COMM TIMEOUT Rcvd from HOST connection."
// [HELPER] s_____COMM__CLASS_NO_AGGREGATION_: "!!! COMM: CLASS NO AGGREGATION."
// [HELPER] s_____Can_t_Add_Player: "!!! Can't Add Player"
// [HELPER] s_____Can_t_Create_Group: "!!! Can't Create Group"
// [HELPER] s_____Can_t_create_player_: "!!! Can't create player."
// [HELPER] s_____Can_t_create_session_: "!!! Can't create session."
// [HELPER] s_____Can_t_load_CAPI: "!!! Can't load CAPI"
// [HELPER] s_____Can_t_load_security_SSPI_pac: "!!! Can't load security SSPI package."
// [HELPER] s_____Can_t_load_security_package_: "!!! Can't load security package."
// [HELPER] s_____Can_t_start_the_application_: "!!! Can't start the application."
// [HELPER] s_____Communications___Session_is_: "!!! Communications / Session is Unavailable"
// [HELPER] s_____Device_caps_are_not_availabl: "!!! Device caps are not available."
// [HELPER] s_____ERROR_: "!!! ERROR!"
// [HELPER] s_____Exception_Raised: "!!! Exception Raised"
// [HELPER] s_____GENERIC__Undefined__ERROR_: "!!! GENERIC (Undefined) ERROR "
// [HELPER] s_____Invalid_Flags: "!!! Invalid Flags"
// [HELPER] s_____Invalid_Group: "!!! Invalid Group"
// [HELPER] s_____Invalid_Object: "!!! Invalid Object"
// [HELPER] s_____Invalid_Params: "!!! Invalid Params"
// [HELPER] s_____Invalid_Player: "!!! Invalid Player"
// [HELPER] s_____Lost_connection_to_session_: "!!! Lost connection to session."
// [HELPER] s_____No_Connection: "!!! No Connection"
// [HELPER] s_____No_Interface: "!!! No Interface"
// [HELPER] s_____No_messages: "!!! No messages"
// [HELPER] s_____No_name_server_running_: "!!! No name server running!"
// [HELPER] s_____No_players_are_connected_: "!!! No players are connected!"
// [HELPER] s_____No_sessions_are_available: "!!! No sessions are available"
// [HELPER] s_____Not_A_Lobby_Session: "!!! Not A Lobby Session"
// [HELPER] s_____Not_able_to_do_multipayer_: "!!! Not able to do multipayer!"
// [HELPER] s_____Out_Of_Memory: "!!! Out Of Memory"
// [HELPER] s_____Player_Lost_connection_: "!!! Player Lost connection."
// [HELPER] s_____Security_authentify_failed_: "!!! Security authentify failed."
// [HELPER] s_____Send_overflow_: "!!! Send overflow!"
// [HELPER] s_____The_encryption_failed_: "!!! The encryption failed."
// [HELPER] s_____The_secure_logon_failed_: "!!! The secure logon failed."
// [HELPER] s_____The_secure_password_is_inval: "!!! The secure password is invalid."
// [HELPER] s_____The_security_sign_failed_: "!!! The security sign failed."
// [HELPER] s_____The_session_is_in_the_proces: "!!! The session is in the process of connecting"
// [HELPER] s_____Unable_to_create_server: "!!! Unable to create server"
// [HELPER] s_____Unknown_application_specifie: "!!! Unknown application specified"
// [HELPER] s_____Unsupported_: "!!! Unsupported."
// [HELPER] s_____User_Cancel: "!!! User Cancel"
// [HELPER] s______s__Unhandled_DP_ERROR_excep: "!!! %s: Unhandled DP ERROR/exception in call.  Result=%ld  (%d)"
void __thiscall FUN_00424ea1(TDebuggingLog *param_1,int param_2,undefined4 param_3)
{
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *pTVar1;
  TDebuggingLog *this_01;
  char *pcVar2;
  
  if (param_2 == 0) {
    return;
  }
  TDebuggingLog::Log(param_1,(char *)L,s____COMM______DP_CALL_FAILED__Cod,param_2,param_3);
  param_1->DateTimestamp = param_2;
  if (param_2 < -0x7fffbffe) {
    if (param_2 == -0x7fffbfff) {
      TDebuggingLog::Log(this,(char *)L,s_____Unsupported_);
      return;
    }
    if (param_2 == -0x7ffffff6) {
      TDebuggingLog::Log(L,(char *)L,s_COM_Error_pending);
      return;
    }
  }
  else if (param_2 < -0x7ffbfeef) {
    if (param_2 == -0x7ffbfef0) {
      TDebuggingLog::Log(L,(char *)L,s_____COMM__CLASS_NO_AGGREGATION_);
      return;
    }
    switch(param_2) {
    case -0x7fffbffe:
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_FATAL_ERROR,0);
      TDebuggingLog::Log(L,(char *)L,s_____No_Interface);
      return;
    case -0x7fffbffd:
      TDebuggingLog::Log(this,(char *)L,s_COM_Invalid_Pointer);
      return;
    case -0x7fffbffc:
      TDebuggingLog::Log(this,(char *)L,s_COM_Aborted);
      return;
    case -0x7fffbffb:
      TDebuggingLog::Log(this,(char *)L,s_____GENERIC__Undefined__ERROR_);
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_FATAL_ERROR,0);
      return;
    }
  }
  else if (param_2 < -0x7ff8fff1) {
    if (param_2 == -0x7ff8fff2) {
      TDebuggingLog::Log(L,(char *)L,s_____Out_Of_Memory);
      return;
    }
    if (param_2 == -0x7ff8fffb) {
      pcVar2 = s_COM_error_Access_Denied;
      pTVar1 = this;
LAB_004254c5:
      TDebuggingLog::Log(pTVar1,(char *)L,pcVar2);
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_NO_LINK,0);
      return;
    }
    if (param_2 == -0x7ff8fffa) {
      TDebuggingLog::Log(this,(char *)L,s_COM_Invalid_Handle);
      return;
    }
  }
  else if (param_2 < -0x7788fffa) {
    if (param_2 == -0x7788fffb) {
      TDebuggingLog::Log(this,(char *)L,s_____Already_Initialized);
      return;
    }
    if (param_2 == -0x7ff8ffa9) {
      TDebuggingLog::Log(this,(char *)L,s_____Invalid_Params);
      return;
    }
  }
  else if (param_2 < -0x7788ffeb) {
    if (param_2 == -0x7788ffec) {
      TDebuggingLog::Log(this,(char *)L,s_____Active_Players___command_inv);
      return;
    }
    if (param_2 == -0x7788fff6) {
      pcVar2 = s_____Access_Denied___busy_service;
      pTVar1 = L;
      goto LAB_004254c5;
    }
  }
  else if (param_2 < -0x7788ffd7) {
    if (param_2 == -0x7788ffd8) {
      pcVar2 = s_____Can_t_Add_Player;
      pTVar1 = L;
LAB_004253bf:
      TDebuggingLog::Log(pTVar1,(char *)L,pcVar2);
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_NO_NEW_PLAYERS,0);
      return;
    }
    if (param_2 == -0x7788ffe2) {
      TDebuggingLog::Log(this,(char *)L,s_____Buffer_size_failure__SMALL_);
      return;
    }
  }
  else if (param_2 < -0x7788ffc3) {
    if (param_2 == -0x7788ffc4) {
      TDebuggingLog::Log(this,(char *)L,s_____Can_t_create_player_);
      return;
    }
    if (param_2 == -0x7788ffce) {
      TDebuggingLog::Log(this,(char *)L,s_____Can_t_Create_Group);
      return;
    }
  }
  else if (param_2 < -0x7788ffaf) {
    if (param_2 == -0x7788ffb0) {
      TDebuggingLog::Log(this,(char *)L,s_____Device_caps_are_not_availabl);
      TDebuggingLog::Log(this_00,(char *)L,s_____ERROR_);
      return;
    }
    if (param_2 == -0x7788ffba) {
      TDebuggingLog::Log(L,(char *)L,s_____Can_t_create_session_);
      return;
    }
  }
  else if (param_2 < -0x7788ff87) {
    if (param_2 == -0x7788ff88) {
      TDebuggingLog::Log(this,(char *)L,s_____Invalid_Flags);
      return;
    }
    if (param_2 == -0x7788ffa6) {
      TDebuggingLog::Log(L,(char *)L,s_____Exception_Raised);
      return;
    }
  }
  else if (param_2 < -0x7788ff69) {
    if (param_2 == -0x7788ff6a) {
      TDebuggingLog::Log(L,(char *)L,s_____Invalid_Player);
      return;
    }
    if (param_2 == -0x7788ff7e) {
      TDebuggingLog::Log(this,(char *)L,s_____Invalid_Object);
      return;
    }
  }
  else if (param_2 < -0x7788ff5f) {
    if (param_2 == -0x7788ff60) {
      TDebuggingLog::Log(this,(char *)L,s_____Not_able_to_do_multipayer_);
      return;
    }
    if (param_2 == -0x7788ff65) {
      TDebuggingLog::Log(this,(char *)L,s_____Invalid_Group);
      return;
    }
  }
  else if (param_2 < -0x7788ff41) {
    if (param_2 == -0x7788ff42) {
      TDebuggingLog::Log(this,(char *)L,s_____No_messages);
      return;
    }
    if (param_2 == -0x7788ff56) {
      TDebuggingLog::Log(L,(char *)L,s_____No_Connection);
      return;
    }
  }
  else if (param_2 < -0x7788ff2d) {
    if (param_2 == -0x7788ff2e) {
      TDebuggingLog::Log(L,(char *)L,s_____No_players_are_connected_);
      return;
    }
    if (param_2 == -0x7788ff38) {
      TDebuggingLog::Log(this,(char *)L,s_____No_name_server_running_);
      return;
    }
  }
  else if (param_2 < -0x7788ff19) {
    if (param_2 == -0x7788ff1a) {
      TDebuggingLog::Log(this,(char *)L,s_____Send_overflow_);
      return;
    }
    if (param_2 == -0x7788ff24) {
      TDebuggingLog::Log(this,(char *)L,s_____No_sessions_are_available);
      return;
    }
  }
  else if (param_2 < -0x7788ff05) {
    if (param_2 == -0x7788ff06) {
      pcVar2 = s_____Communications___Session_is_;
      pTVar1 = this;
      goto LAB_004253bf;
    }
    if (param_2 == -0x7788ff10) {
      TDebuggingLog::Log(L,(char *)L,s_____COMM_TIMEOUT_Rcvd_from_HOST_);
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_HOST_BUSY,0);
      return;
    }
  }
  else if (param_2 < -0x7788fee7) {
    if (param_2 == -0x7788fee8) {
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_NO_LINK,0);
      TDebuggingLog::Log(L,(char *)L,s_____User_Cancel);
      return;
    }
    if (param_2 == -0x7788fef2) {
      TDebuggingLog::Log(this,(char *)L,s_____Busy_Rcvd);
      return;
    }
  }
  else if (param_2 < -0x7788fed3) {
    if (param_2 == -0x7788fed4) {
      TDebuggingLog::Log(this,(char *)L,s_____Player_Lost_connection_);
      return;
    }
    if (param_2 == -0x7788fede) {
      TDebuggingLog::Log(this,(char *)L,s_____Unable_to_create_server);
      return;
    }
  }
  else if (param_2 < -0x7788febf) {
    if (param_2 == -0x7788fec0) {
      pcVar2 = s_____Unknown_application_specifie;
      pTVar1 = this;
      goto LAB_004254c5;
    }
    if (param_2 == -0x7788feca) {
      TDebuggingLog::Log(L,(char *)L,s_____Lost_connection_to_session_);
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_CANCEL_GAME,0);
      return;
    }
  }
  else if (param_2 < -0x7788feab) {
    if (param_2 == -0x7788feac) {
      TDebuggingLog::Log(L,(char *)L,s_____The_secure_password_is_inval);
      return;
    }
    if (param_2 == -0x7788feb6) {
      RGE_Comm_Error::NotifyWindowParam((RGE_Comm_Error *)param_1,COMM_NO_NEW_PLAYERS,0);
      TDebuggingLog::Log(this_01,(char *)L,s_____The_session_is_in_the_proces);
      return;
    }
  }
  else if (param_2 < -0x7788fc17) {
    if (param_2 == -0x7788fc18) {
      TDebuggingLog::Log(this,(char *)L,s_____Buffer_size_failure__LARGE_);
      return;
    }
    if (param_2 == -0x7788fea2) {
      TDebuggingLog::Log(this,(char *)L,s_____The_session_is_in_the_proces);
      return;
    }
  }
  else if (param_2 < -0x7788fc03) {
    if (param_2 == -0x7788fc04) {
      TDebuggingLog::Log(this,(char *)L,s_____Application_has_not_been_sta);
      return;
    }
    if (param_2 == -0x7788fc0e) {
      TDebuggingLog::Log(L,(char *)L,s_____Can_t_start_the_application_);
      return;
    }
  }
  else if (param_2 < -0x7788fbe5) {
    if (param_2 == -0x7788fbe6) {
      TDebuggingLog::Log(this,(char *)L,s_____Unknown_application_specifie);
      return;
    }
    if (param_2 == -0x7788fbf0) {
      return;
    }
  }
  else if (param_2 < -0x7788f82f) {
    if (param_2 == -0x7788f830) {
      TDebuggingLog::Log(this,(char *)L,s_____Security_authentify_failed_);
      return;
    }
    if (param_2 == -0x7788fbd2) {
      TDebuggingLog::Log(L,(char *)L,s_____Not_A_Lobby_Session);
      return;
    }
  }
  else if (param_2 < -0x7788f81b) {
    if (param_2 == -0x7788f81c) {
      TDebuggingLog::Log(L,(char *)L,s_____The_encryption_failed_);
      return;
    }
    if (param_2 == -0x7788f826) {
      TDebuggingLog::Log(this,(char *)L,s_____Can_t_load_security_SSPI_pac);
      return;
    }
  }
  else if (param_2 < -0x7788f807) {
    if (param_2 == -0x7788f808) {
      TDebuggingLog::Log(this,(char *)L,s_____Can_t_load_security_package_);
      return;
    }
    if (param_2 == -0x7788f812) {
      TDebuggingLog::Log(this,(char *)L,s_____The_security_sign_failed_);
      return;
    }
  }
  else {
    if (param_2 == -0x7788f7f4) {
      TDebuggingLog::Log(this,(char *)L,s_____Can_t_load_CAPI);
      return;
    }
    if (param_2 == -0x7788f7e0) {
      TDebuggingLog::Log(this,(char *)L,s_____The_secure_logon_failed_);
      return;
    }
  }
  TDebuggingLog::Log(L,(char *)L,s______s__Unhandled_DP_ERROR_excep,param_3,param_2,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0042577d
// Address: 0042577d
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s___d___s____s: "[%d] %s - %s"
// [HELPER] s___d___s____s__QUIET__d_msec__T__: "[%d] %s - %s (QUIET=%d msec  T#=%d )"
char * __thiscall FUN_0042577d(TCommunications_Handler *param_1,uint param_2)
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  int iVar5;
  
  pcVar1 = param_1->TBuff;
  pcVar2 = TCommunications_Handler::WaitingOnInfo(param_1,param_2);
  pcVar3 = TCommunications_Handler::GetPlayerName(param_1,param_2);
  sprintf(pcVar1,s___d___s____s,param_2,pcVar3,pcVar2);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x8e);
  iVar5 = uVar4 - param_1->LastPlayerCommunication[param_2];
  uVar4 = param_1->LastTurnAck[param_2];
  pcVar2 = TCommunications_Handler::WaitingOnInfo(param_1,param_2);
  pcVar3 = TCommunications_Handler::GetPlayerName(param_1,param_2);
  sprintf(pcVar1,s___d___s____s__QUIET__d_msec__T__,param_2,pcVar3,pcVar2,iVar5,uVar4);
  return pcVar1;
}

// --------------------------------------------------

// Function: FUN_004257fb
// Address: 004257fb
undefined4 __thiscall FUN_004257fb(TCommunications_Handler *param_1,uint param_2)
{
  int iVar1;
  
  iVar1 = TCommunications_Handler::IsPlayerComputer(param_1,param_2);
  if (iVar1 != 0) {
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b1,0x62c588,0x20);
    return 0x62c588;
  }
  iVar1 = TCommunications_Handler::IsPlayerHuman(param_1,param_2);
  if (iVar1 == 0) {
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b2,0x62c588,0x20);
    return 0x62c588;
  }
  if (param_1->LastTurnAck[param_2] < 4) {
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b3,0x62c588,0x20);
    return 0x62c588;
  }
  if (param_1->LastTurnAck[param_2] < param_1->current_turn) {
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b4,0x62c588,0x20);
    return 0x62c588;
  }
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b0,0x62c588,0x20);
  return 0x62c588;
}

// --------------------------------------------------

// Function: FUN_004258d3
// Address: 004258d3
void __thiscall FUN_004258d3(int param_1,int param_2)
{
  RGE_Communications_Synchronize::SetDialogOnFail
            (*(RGE_Communications_Synchronize **)(param_1 + 0x14d8),param_2);
  RGE_Communications_Synchronize::SetStopOnFail
            (*(RGE_Communications_Synchronize **)(param_1 + 0x14d8),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00425905
// Address: 00425905
void __thiscall FUN_00425905(int param_1,int param_2)
{
  RGE_Communications_Synchronize::SendChatMsgsAtChecksum
            (*(RGE_Communications_Synchronize **)(param_1 + 0x14d8),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00425923
// Address: 00425923
// [HELPER] s_DROPPING_PACKETS_INTENTIONALLY__: "DROPPING PACKETS INTENTIONALLY!!!"
void __thiscall FUN_00425923(TDebuggingLog *param_1,int param_2)
{
  *(int *)(param_1[2].osbuf + 0x270) = param_2;
  if (param_2 != 0) {
    TDebuggingLog::Log(param_1,(char *)L,s_DROPPING_PACKETS_INTENTIONALLY__);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00425954
// Address: 00425954
void __thiscall FUN_00425954(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1288) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0042596d
// Address: 0042596d
void __thiscall FUN_0042596d(int param_1,int param_2)
{
  RGE_Communications_Speed::EnableSpeedControl
            (*(RGE_Communications_Speed **)(param_1 + 0x14d4),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00425983
// Address: 00425983
undefined4 __fastcall FUN_00425983(TCommunications_Handler *param_1)
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 1;
  uVar1 = param_1->MaxGamePlayers;
  (param_1->PlayerOptions).HighPlayerNumber = 0;
  (param_1->PlayerOptions).LowPlayerNumber = uVar1 + 1;
  if (uVar1 != 0) {
    do {
      iVar2 = TCommunications_Handler::IsPlayerHuman(param_1,uVar4);
      if (iVar2 == 0) {
        iVar2 = TCommunications_Handler::IsPlayerComputer(param_1,uVar4);
        if (iVar2 != 0) goto LAB_004259d0;
      }
      else {
LAB_004259d0:
        uVar3 = (uint)(param_1->PlayerOptions).HighPlayerNumber;
        if ((int)uVar3 <= (int)uVar4) {
          uVar3 = uVar4;
        }
        (param_1->PlayerOptions).HighPlayerNumber = (ushort)uVar3;
        uVar3 = (uint)(param_1->PlayerOptions).LowPlayerNumber;
        if ((int)uVar4 <= (int)uVar3) {
          uVar3 = uVar4;
        }
        (param_1->PlayerOptions).LowPlayerNumber = (ushort)uVar3;
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 <= (int)(uint)param_1->MaxGamePlayers);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00425a12
// Address: 00425a12
void __thiscall FUN_00425a12(TCommunications_Handler *param_1,int param_2)
{
  TCommunications_Handler::TEST(param_1);
  param_1->Steps = param_1->Steps + param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00425a38
// Address: 00425a38
// [HELPER] s_13_17_08: "13:17:08"
// [HELPER] s_COMM___RGE_COMMUNICTIONS_STARTED: "COMM:  RGE COMMUNICTIONS STARTED ---------------%s"
// [HELPER] s_COMM____s__Version_____s: "COMM:  %s  Version... %s"
// [HELPER] s_C__msdev_work_age1_x1_Com_hand_c: "C:\msdev\work\age1_x1\Com_hand.cpp"
// [HELPER] s_C__msdev_work_age1_x1_com_hand_h: "C:\msdev\work\age1_x1\com_hand.h"
// [HELPER] s_Fri_Jul_17_09_39_38_1998: "Fri Jul 17 09:39:38 1998"
// [HELPER] s_Initialize_Player_List: "Initialize Player List"
// [HELPER] s__: "}"
TCommunications_Handler * __thiscall
FUN_00425a38(TCommunications_Handler *param_1,void *param_2,byte param_3,TChat *param_4,
            ulong param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
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
  TDebuggingLog *this;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  ulong *puVar22;
  undefined4 *unaff_FS_OFFSET;
  char acStack_2c [32];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ccbd;
  *unaff_FS_OFFSET = &uStack_c;
  TDebuggingLog::FlushToDisk(L,1);
  param_1->ReturnRXPacketSize = param_1->RXPacketLength;
  uVar15 = param_1->RXPacketLength;
  if (param_1->RXPacketLength <= param_1->RXPacketLengthHigh) {
    uVar15 = param_1->RXPacketLengthHigh;
  }
  param_1->RXPacketLengthHigh = uVar15;
  param_1->RXPacketLength = 0;
  param_1->ReturnTXPacketSize = param_1->TXPacketLength;
  uVar15 = param_1->TXPacketLength;
  if (param_1->TXPacketLength <= param_1->TXPacketLengthHigh) {
    uVar15 = param_1->TXPacketLengthHigh;
  }
  param_1->TXPacketLengthHigh = uVar15;
  p_Var1 = &param_1->NullGUID;
  param_1->TXPacketLength = 0;
  param_1->OutQ = (RGE_Communications_Queue *)0x0;
  param_1->InQ = (RGE_Communications_Queue *)0x0;
  param_1->GTDSerialNo = 0;
  p_Var1->Data1 = 0;
  (param_1->NullGUID).Data2 = 0;
  (param_1->NullGUID).Data3 = 0;
  (param_1->NullGUID).Data4[0] = '\0';
  (param_1->NullGUID).Data4[1] = '\0';
  (param_1->NullGUID).Data4[2] = '\0';
  (param_1->NullGUID).Data4[3] = '\0';
  (param_1->NullGUID).Data4[4] = '\0';
  (param_1->NullGUID).Data4[5] = '\0';
  (param_1->NullGUID).Data4[6] = '\0';
  (param_1->NullGUID).Data4[7] = '\0';
  param_1->CommunicationsStatus = INITIALIZED;
  (param_1->ApplicationGUID).Data1 = param_5;
  (param_1->ApplicationGUID).Data2 = (undefined2)param_6;
  (param_1->ApplicationGUID).Data3 = param_6._2_2_;
  *(undefined4 *)(param_1->ApplicationGUID).Data4 = param_7;
  *(undefined4 *)((param_1->ApplicationGUID).Data4 + 4) = param_8;
  (param_1->SessionGUID).Data1 = p_Var1->Data1;
  uVar3 = (param_1->NullGUID).Data3;
  (param_1->SessionGUID).Data2 = (param_1->NullGUID).Data2;
  (param_1->SessionGUID).Data3 = uVar3;
  *(undefined4 *)(param_1->SessionGUID).Data4 = *(undefined4 *)(param_1->NullGUID).Data4;
  *(undefined4 *)((param_1->SessionGUID).Data4 + 4) = *(undefined4 *)((param_1->NullGUID).Data4 + 4)
  ;
  (param_1->ServiceGUID).Data1 = p_Var1->Data1;
  uVar3 = (param_1->NullGUID).Data3;
  (param_1->ServiceGUID).Data2 = (param_1->NullGUID).Data2;
  (param_1->ServiceGUID).Data3 = uVar3;
  *(undefined4 *)(param_1->ServiceGUID).Data4 = *(undefined4 *)(param_1->NullGUID).Data4;
  *(undefined4 *)((param_1->ServiceGUID).Data4 + 4) = *(undefined4 *)((param_1->NullGUID).Data4 + 4)
  ;
  param_1->HostHWND = param_2;
  param_1->Chat = param_4;
  param_1->MaxGamePlayers = (ushort)param_3;
  TDebuggingLog::Log(L,(char *)L,s_COMM___RGE_COMMUNICTIONS_STARTED,
                     s_C__msdev_work_age1_x1_Com_hand_c);
  TDebuggingLog::Log(this,(char *)L,s_COMM____s__Version_____s,s_C__msdev_work_age1_x1_Com_hand_c,
                     s_Fri_Jul_17_09_39_38_1998);
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
  pcVar4 = pcVar19 + -uVar15;
  pcVar19 = acStack_2c;
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
  if (acStack_2c[0] != '\0') {
    pcVar4 = acStack_2c;
    do {
      if (*pcVar4 == ':') {
        *pcVar4 = '0';
      }
      pcVar19 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar19 != '\0');
  }
  param_1->CommunicationsVersionCode = 0x2e2887;
  uVar15 = (uint)param_3;
  iVar18 = uVar15 + 1;
  pcVar4 = (char *)operator_new(iVar18 * 0x80);
  if ((NAME *)pcVar4 == (NAME *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    _param_3 = uVar15 + 1;
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
      _param_3 = _param_3 + -1;
      for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        *pcVar21 = *pcVar20;
        pcVar20 = pcVar20 + 1;
        pcVar21 = pcVar21 + 1;
      }
      pcVar19 = pcVar19 + 0x80;
    } while (_param_3 != 0);
  }
  param_1->FriendlyName = (NAME *)pcVar4;
  pcVar4 = (char *)operator_new(iVar18 * 0x80);
  if ((NAME *)pcVar4 == (NAME *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar19 = pcVar4;
    _param_3 = iVar18;
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
        _param_3 = _param_3 + -1;
        for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
          *pcVar21 = *pcVar20;
          pcVar20 = pcVar20 + 1;
          pcVar21 = pcVar21 + 1;
        }
        pcVar19 = pcVar19 + 0x80;
      } while (_param_3 != 0);
    }
  }
  param_1->FormalName = (NAME *)pcVar4;
  pRVar5 = (RGE_Communications_Queue *)operator_new(0x118);
  uStack_4 = 0;
  if (pRVar5 == (RGE_Communications_Queue *)0x0) {
    pRVar5 = (RGE_Communications_Queue *)0x0;
  }
  else {
    pRVar5 = (RGE_Communications_Queue *)
             RGE_Communications_Queue::RGE_Communications_Queue(pRVar5,0x1f5);
  }
  uStack_4 = 0xffffffff;
  param_1->InQ = pRVar5;
  puVar6 = (undefined4 *)operator_new(0x6dd4);
  uStack_4 = 1;
  if (puVar6 == (undefined4 *)0x0) {
    pRVar7 = (RESENDER *)0x0;
  }
  else {
    pRVar7 = (RESENDER *)(puVar6 + 1);
    *puVar6 = 0x1f6;
    _eh_vector_constructor_iterator_(pRVar7,0x38,0x1f6,RESENDER::RESENDER,RESENDER::~RESENDER);
  }
  uStack_4 = 0xffffffff;
  param_1->Resend = pRVar7;
  puVar6 = (undefined4 *)operator_new(0x2f14);
  uStack_4 = 2;
  if (puVar6 == (undefined4 *)0x0) {
    pHVar8 = (HOLDER *)0x0;
  }
  else {
    pHVar8 = (HOLDER *)(puVar6 + 1);
    *puVar6 = 0x1f6;
    _eh_vector_constructor_iterator_(pHVar8,0x18,0x1f6,HOLDER::HOLDER,HOLDER::~HOLDER);
  }
  uStack_4 = 0xffffffff;
  param_1->OnHold = pHVar8;
  pRVar9 = (RGE_Comm_Error *)operator_new(8);
  uStack_4 = 3;
  if (pRVar9 == (RGE_Comm_Error *)0x0) {
    pRVar9 = (RGE_Comm_Error *)0x0;
  }
  else {
    pRVar9 = (RGE_Comm_Error *)RGE_Comm_Error::RGE_Comm_Error(pRVar9,param_2);
  }
  uStack_4 = 0xffffffff;
  param_1->Err = pRVar9;
  pRVar10 = (RGE_Lobby *)operator_new(0x1c);
  uStack_4 = 4;
  if (pRVar10 == (RGE_Lobby *)0x0) {
    pRVar10 = (RGE_Lobby *)0x0;
  }
  else {
    pRVar10 = (RGE_Lobby *)RGE_Lobby::RGE_Lobby(pRVar10,param_2);
  }
  uStack_4 = 0xffffffff;
  param_1->Lobby = pRVar10;
  pRVar11 = (RGE_Communications_Speed *)operator_new(0x240);
  uStack_4 = 5;
  if (pRVar11 == (RGE_Communications_Speed *)0x0) {
    pRVar11 = (RGE_Communications_Speed *)0x0;
  }
  else {
    pRVar11 = (RGE_Communications_Speed *)
              RGE_Communications_Speed::RGE_Communications_Speed(pRVar11,param_1);
  }
  uStack_4 = 0xffffffff;
  param_1->Speed = pRVar11;
  pRVar12 = (RGE_Communications_Synchronize *)operator_new(0x7ec);
  uStack_4 = 6;
  if (pRVar12 == (RGE_Communications_Synchronize *)0x0) {
    pRVar12 = (RGE_Communications_Synchronize *)0x0;
  }
  else {
    pRVar12 = (RGE_Communications_Synchronize *)
              RGE_Communications_Synchronize::RGE_Communications_Synchronize(pRVar12,param_1);
  }
  uStack_4 = 0xffffffff;
  param_1->Sync = pRVar12;
  uVar13 = debug_timeGetTime(s_C__msdev_work_age1_x1_com_hand_h,0x267);
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
  (param_1->PlayerOptions).LastSentTime = uVar13;
  uVar15 = 0xffffffff;
  param_1->AvgTurnTime = 0;
  param_1->PauseChangePending = 0;
  param_1->StepMode = 0;
  param_1->IntentionallyDropPackets = 0;
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
  pcVar19 = param_1->MyGameTitle;
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
  pcVar19 = param_1->MyFriendlyName;
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
  pcVar19 = param_1->MyFormalName;
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
  param_1->TickStart = 0;
  param_1->TickCount = 0;
  param_1->LastTimeoutMessageTime = 0;
  uVar3 = param_1->MaxGamePlayers;
  (param_1->PlayerOptions).LowPlayerNumber = 1;
  (param_1->PlayerOptions).HighPlayerNumber = uVar3;
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
  TDebuggingLog::Log((TDebuggingLog *)(uint)uVar3,(char *)L,s_Initialize_Player_List);
  uVar15 = 1;
  if (param_1->MaxGamePlayers != 0) {
    do {
      TCommunications_Handler::InitPlayerInformation(param_1,uVar15,0,&s__,&s__);
      uVar15 = uVar15 + 1;
    } while ((int)uVar15 <= (int)(uint)param_1->MaxGamePlayers);
  }
  (param_1->PlayerOptions).NeedsToBeSent = '\0';
  (param_1->PlayerOptions).LastSentTime = 0;
  TCommunications_Handler::ClearAllSerialNumbers(param_1);
  TCommunications_Handler::ClearRXandTX(param_1);
  puVar22 = param_1->PlayerStopTurn;
  for (iVar18 = 9; puVar22 = puVar22 + 1, iVar18 != 0; iVar18 = iVar18 + -1) {
    *puVar22 = 0;
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
  piVar14 = param_1->Kicked;
  iVar18 = 10;
  do {
    piVar14[-0x4c] = 0;
    *piVar14 = 0;
    piVar14[0xac] = 0;
    piVar14 = piVar14 + 1;
    iVar18 = iVar18 + -1;
  } while (iVar18 != 0);
  (param_1->PlayerOptions).DataSizeToFollow = 0;
  param_1->OptionsData = (char *)0x0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004260e4
// Address: 004260e4
undefined4 * __thiscall FUN_004260e4(undefined4 *param_1,byte param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_(param_1,0x38,param_1[-1],RESENDER::~RESENDER);
    operator_delete(param_1 + -1);
    return param_1;
  }
  *param_1 = 0;
  if ((void *)param_1[2] != (void *)0x0) {
    operator_delete((void *)param_1[2]);
  }
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  puVar2 = param_1 + 4;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00426162
// Address: 00426162
undefined4 * __thiscall FUN_00426162(undefined4 *param_1,byte param_2)
{
  if ((param_2 & 2) != 0) {
    _eh_vector_destructor_iterator_(param_1,0x18,param_1[-1],HOLDER::~HOLDER);
    operator_delete(param_1 + -1);
    return param_1;
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004261d8
// Address: 004261d8
// [HELPER] s_NO_MSG_Slot__d__Ser__d__Len__d__: "NO MSG Slot#%d  Ser#%d  Len=%d  DEST=%d,%d,%d,%d,%d,%d,%d,%d "
void __fastcall FUN_004261d8(TCommunications_Handler *param_1)
{
  RESENDER *pRVar1;
  int iVar2;
  HOLDER *pHVar3;
  RGE_Communications_Queue *this;
  RGE_Lobby *this_00;
  RGE_Communications_Speed *this_01;
  RGE_Communications_Synchronize *this_02;
  RGE_Comm_Error *this_03;
  int iVar4;
  uint uVar5;
  
  TCommunications_Handler::DestroyMultiplayerGame(param_1);
  TCommunications_Handler::CloseSession(param_1);
  TCommunications_Handler::ReleaseComm(param_1);
  TCommunications_Handler::FreeOptions(param_1);
  operator_delete(param_1->FriendlyName);
  operator_delete(param_1->FormalName);
  iVar4 = 0;
  uVar5 = 0;
  do {
    pRVar1 = param_1->Resend;
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
  pRVar1 = param_1->Resend;
  if (pRVar1 != (RESENDER *)0x0) {
    _eh_vector_destructor_iterator_(pRVar1,0x38,pRVar1[-1].DestMap[9],RESENDER::~RESENDER);
    operator_delete(pRVar1[-1].DestMap + 9);
  }
  pHVar3 = param_1->OnHold;
  if (pHVar3 != (HOLDER *)0x0) {
    _eh_vector_destructor_iterator_(pHVar3,0x18,pHVar3[-1].fromPlayer,HOLDER::~HOLDER);
    operator_delete(&pHVar3[-1].fromPlayer);
  }
  this = param_1->InQ;
  if (this != (RGE_Communications_Queue *)0x0) {
    RGE_Communications_Queue::~RGE_Communications_Queue(this);
    operator_delete(this);
  }
  this_00 = param_1->Lobby;
  if (this_00 != (RGE_Lobby *)0x0) {
    RGE_Lobby::~RGE_Lobby(this_00);
    operator_delete(this_00);
  }
  this_01 = param_1->Speed;
  if (this_01 != (RGE_Communications_Speed *)0x0) {
    RGE_Communications_Speed::~RGE_Communications_Speed(this_01);
    operator_delete(this_01);
  }
  this_02 = param_1->Sync;
  if (this_02 != (RGE_Communications_Synchronize *)0x0) {
    RGE_Communications_Synchronize::~RGE_Communications_Synchronize(this_02);
    operator_delete(this_02);
  }
  this_03 = param_1->Err;
  if (this_03 != (RGE_Comm_Error *)0x0) {
    RGE_Comm_Error::~RGE_Comm_Error(this_03);
    operator_delete(this_03);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042634c
// Address: 0042634c
// [HELPER] s___: "]\n"
void __fastcall FUN_0042634c(TCommunications_Handler *param_1)
{
  int iVar1;
  void *pvVar2;
  uint unaff_EBP;
  ulong *puVar3;
  uint uVar4;
  undefined4 uStack_14;
  int iStack_10;
  uint uStack_c;
  ulong uStack_8;
  TDebuggingLog *pTStack_4;
  
  uVar4 = 1;
  if (param_1->MaxGamePlayers != 0) {
    puVar3 = (param_1->PlayerOptions).dcoID;
    do {
      puVar3 = puVar3 + 1;
      iVar1 = TCommunications_Handler::IsPlayerHuman(param_1,uVar4);
      if (iVar1 != 0) {
        uStack_14 = 0;
        (**(code **)(*DAT_0062c5ec + 0x54))(DAT_0062c5ec,*puVar3,0,&uStack_14);
        pvVar2 = operator_new(unaff_EBP);
        iStack_10 = (**(code **)(*DAT_0062c5ec + 0x54))
                              (DAT_0062c5ec,*puVar3,pvVar2,&stack0xffffffdc);
        operator_delete(pvVar2);
        if (iStack_10 != 0) {
          uStack_8 = *puVar3;
          pTStack_4 = (TDebuggingLog *)param_1->current_turn;
          uStack_c = uVar4;
          TDebuggingLog::Log(pTStack_4,(char *)L,s___>TX_KP___d___d_,uVar4,0xc);
          TCommunications_Handler::CommOut(param_1,0,'K',&uStack_c,0xc,'\0');
          if (puVar3[-0x6a] == 0) {
            TCommunications_Handler::DropDeadPlayer(param_1,uVar4,*puVar3);
          }
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= param_1->MaxGamePlayers);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00426447
// Address: 00426447
undefined4 * __fastcall FUN_00426447(undefined4 *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  puVar2 = param_1 + 4;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0042646e
// Address: 0042646e
void __thiscall
FUN_0042646e(int param_1,ulong param_2,void *param_3,ulong param_4,uint param_5,uchar param_6,
            int param_7)
{
  RGE_Communications_Queue::AddItem
            (*(RGE_Communications_Queue **)(param_1 + 0x14c4),param_2,param_3,param_4,param_5,
             param_6,param_7);
  return;
}

// --------------------------------------------------

// Function: FUN_0042649c
// Address: 0042649c
void __fastcall FUN_0042649c(undefined4 *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 0;
  if ((void *)param_1[2] != (void *)0x0) {
    operator_delete((void *)param_1[2]);
  }
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  puVar2 = param_1 + 4;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042650c
// Address: 0042650c
void __thiscall FUN_0042650c(TCommunications_Handler *param_1,void *param_2,int param_3)
{
  TCommunications_Handler::NewCommand(param_1,param_2,param_3,0);
  return;
}

// --------------------------------------------------

// Function: FUN_00426524
// Address: 00426524
// [HELPER] s_NewCmnd: "NewCmnd"
// [HELPER] s___: "]\n"
undefined4 __thiscall
FUN_00426524(TCommunications_Handler *param_1,byte *param_2,ulong param_3,int param_4)
{
  byte bVar1;
  ulong uVar2;
  uchar uVar3;
  long lVar4;
  
  if (param_1->Multiplayer != 0) {
    TDebuggingLog::Log(L,(char *)L,s___>TX_CMD___d__Cmd__d_,param_3,(uint)*param_2);
    lVar4 = TCommunications_Handler::CommOut(param_1,0,'>',param_2,param_3,'\0');
    RGE_Comm_Error::ShowReturn(param_1->Err,lVar4,s_NewCmnd);
    return 1;
  }
  uVar2 = param_1->current_turn;
  bVar1 = (param_1->PlayerOptions).CommandTurnIncrement;
  uVar3 = RGE_Communications_Queue::GetNextSequence(param_1->InQ,uVar2);
  TCommunications_Handler::AddCommand
            (param_1,bVar1 + uVar2,param_2,param_3,param_1->Me,uVar3,param_4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004265d3
// Address: 004265d3
void __fastcall FUN_004265d3(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004265f3
// Address: 004265f3
void __fastcall FUN_004265f3(undefined4 *param_1)
{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}

// --------------------------------------------------

