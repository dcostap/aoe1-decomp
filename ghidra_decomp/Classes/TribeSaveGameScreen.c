// Class: TribeSaveGameScreen
// Size:  0x6A4
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] setup
// [02] set_rect
// [03] set_rect
// [04] set_color
// [05] set_active
// [06] set_positioning
// [07] set_fixed_position
// [08] set_redraw
// [09] set_overlapped_redraw
// [10] draw_setup
// [11] draw_finish
// [12] draw
// [13] draw_rect
// [14] draw_offset
// [15] draw_rect2
// [16] draw_offset2
// [17] paint
// [18] wnd_proc
// [19] handle_idle
// [20] handle_size
// [21] handle_paint
// [22] handle_key_down
// [23] handle_char
// [24] handle_command
// [25] handle_user_command
// [26] handle_timer_command
// [27] handle_scroll
// [28] handle_mouse_down
// [29] handle_mouse_move
// [30] handle_mouse_up
// [31] handle_mouse_dbl_click
// [32] mouse_move_action
// [33] mouse_left_down_action
// [34] mouse_left_hold_action
// [35] mouse_left_move_action
// [36] mouse_left_up_action
// [37] mouse_left_dbl_click_action
// [38] mouse_right_down_action
// [39] mouse_right_hold_action
// [40] mouse_right_move_action
// [41] mouse_right_up_action
// [42] mouse_right_dbl_click_action
// [43] key_down_action
// [44] char_action
// [45] action
// [46] get_true_render_rect
// [47] is_inside
// [48] set_focus
// [49] set_tab_order
// [50] set_tab_order
// [51] get_help_info
// [52] stop_sound_system
// [53] restart_sound_system
// [54] take_snapshot
// [55] handle_reactivate
// [56] draw_background
// [57] set_ideal_size
// [58] create_button
// [59] create_button
// [60] create_check_box
// [61] create_radio_button
// [62] create_text
// [63] create_text
// [64] create_text
// [65] create_input
// [66] create_edit
// [67] create_drop_down
// [68] create_list
// [69] create_scrollbar
// [70] create_auto_scrollbar
// [71] create_vert_slider
// [72] create_horz_slider
// [73] position_panel
// [74] `vector_deleting_destructor'
// [75] setup
// [76] set_rect
// [77] set_rect
// [78] set_color
// [79] set_active
// [80] set_positioning
// [81] set_fixed_position
// [82] set_redraw
// [83] set_overlapped_redraw
// [84] draw_setup
// [85] draw_finish
// [86] draw
// [87] draw_rect
// [88] draw_offset
// [89] draw_rect2
// [90] draw_offset2
// [91] paint
// [92] wnd_proc
// [93] handle_idle
// [94] handle_size
// [95] handle_paint
// [96] handle_key_down
// [97] handle_char
// [98] handle_command
// [99] handle_user_command
// [100] handle_timer_command
// [101] handle_scroll
// [102] handle_mouse_down
// [103] handle_mouse_move
// [104] handle_mouse_up
// [105] handle_mouse_dbl_click
// [106] mouse_move_action
// [107] mouse_left_down_action
// [108] mouse_left_hold_action
// [109] mouse_left_move_action
// [110] mouse_left_up_action
// [111] mouse_left_dbl_click_action
// [112] mouse_right_down_action
// [113] mouse_right_hold_action
// [114] mouse_right_move_action
// [115] mouse_right_up_action
// [116] mouse_right_dbl_click_action
// [117] key_down_action
// [118] char_action
// [119] action
// [120] get_true_render_rect
// [121] is_inside
// [122] set_focus
// [123] set_tab_order
// [124] set_tab_order
// [125] get_help_info
// [126] stop_sound_system
// [127] restart_sound_system
// [128] take_snapshot
// [129] handle_reactivate
// [130] draw_background
// [131] set_ideal_size
// [132] create_button
// [133] create_button
// [134] create_check_box
// [135] create_radio_button
// [136] create_text
// [137] create_text
// [138] create_text
// [139] create_input
// [140] create_edit
// [141] create_drop_down
// [142] create_list
// [143] create_scrollbar
// [144] create_auto_scrollbar
// [145] create_vert_slider
// [146] create_horz_slider
// [147] position_panel
//
// Member Layout:
// [0x478] TTextPanel * title
// [0x47C] TEditPanel * input
// [0x480] TListPanel * list
// [0x484] TScrollBarPanel * scrollbar
// [0x488] TButtonPanel * okButton
// [0x48C] TButtonPanel * cancelButton
// [0x490] TButtonPanel * deleteButton
// [0x494] char[260] fileName (sz: 0x104)
// [0x598] char[260] fileNameNoExt (sz: 0x104)
// [0x69C] Mode modeValue
// [0x6A0] int quit_after_save
// ----------------------------------------------------------------

// Function: TribeSaveGameScreen
// Address: 004a71f0
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
TribeSaveGameScreen * __thiscall
TribeSaveGameScreen::TribeSaveGameScreen
          (TribeSaveGameScreen *this,Mode param_1,char *param_2,int param_3)
{
  TButtonPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  char cVar4;
  TDrawArea *pTVar5;
  TButtonPanel *pTVar6;
  short sVar7;
  char *pcVar8;
  long lVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  undefined4 *unaff_FS_OFFSET;
  int iVar14;
  TEasy_Panel *from_panel;
  TPanel *tabList [5];
  char info_file [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f3bb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  info_file._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Save_Game_Screen);
  this->quit_after_save = param_3;
  local_4 = 0;
  this->modeValue = param_1;
  this->_padding_ = (int)&_vftable_;
  this->title = (TTextPanel *)0x0;
  this->input = (TEditPanel *)0x0;
  this->list = (TListPanel *)0x0;
  this->scrollbar = (TScrollBarPanel *)0x0;
  this->okButton = (TButtonPanel *)0x0;
  this->cancelButton = (TButtonPanel *)0x0;
  this->deleteButton = (TButtonPanel *)0x0;
  if ((param_2 == (char *)0x0) && (param_1 == SaveGame)) {
    param_2 = TRIBE_Game::get_save_game_name((TRIBE_Game *)rge_base_game);
  }
  tabList[0] = TPanelSystem::currentPanel(&panel_system);
  pcVar8 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)tabList[0]);
  uVar11 = 0xffffffff;
  pcVar10 = info_file;
  do {
    pcVar13 = pcVar8;
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    pcVar13 = pcVar8 + 1;
    cVar4 = *pcVar8;
    pcVar8 = pcVar13;
  } while (cVar4 != '\0');
  uVar11 = ~uVar11;
  iVar14 = 1;
  pcVar8 = pcVar13 + -uVar11;
  for (uVar12 = uVar11 >> 2; pcVar10 = pcVar10 + 4, uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  pTVar5 = rge_base_game->draw_area;
  lVar9 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)tabList[0]);
  lVar9 = TScreenPanel::setup((TScreenPanel *)this,pTVar5,info_file + 4,lVar9,iVar14);
  if (lVar9 == 0) {
    this->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
    iVar14 = TEasy_Panel::create_text
                       ((TEasy_Panel *)this,(TPanel *)this,&this->title,
                        (this->modeValue != SaveGame) + 0x24c3,0x14,0x14,600,0x1e,1,1,0,0);
    if (iVar14 != 0) {
      uVar11 = 0xffffffff;
      pcVar10 = rge_base_game->work_dir;
      do {
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        cVar4 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar4 != '\0');
      if (0x7a - (~uVar11 - 1) < 0x51) {
        iVar14 = -1;
        pcVar10 = rge_base_game->work_dir;
        do {
          if (iVar14 == 0) break;
          iVar14 = iVar14 + -1;
          cVar4 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar4 != '\0');
        sVar7 = 0x7a - (~(ushort)iVar14 - 1);
      }
      else {
        sVar7 = 0x50;
      }
      iVar14 = TEasy_Panel::create_edit
                         ((TEasy_Panel *)this,(TPanel *)this,&this->input,param_2,sVar7,
                          FormatFileNoExt,0x14,0x46,600,0x17,0xb,1,1);
      if (iVar14 != 0) {
        TPanel::set_help_info((TPanel *)this->input,0x7670,-1);
        iVar14 = TEasy_Panel::create_list
                           ((TEasy_Panel *)this,(TPanel *)this,&this->list,0x14,0x6e,600,300,0xb);
        if (iVar14 != 0) {
          iVar14 = TEasy_Panel::create_auto_scrollbar
                             ((TEasy_Panel *)this,&this->scrollbar,(TTextPanel *)this->list,0x14);
          if (iVar14 != 0) {
            TPanel::set_help_info((TPanel *)this->scrollbar,0x7671,-1);
            ppTVar1 = &this->okButton;
            iVar14 = TEasy_Panel::create_button
                               ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0xfa1,0,0x1e,0x1b8,0xb4,
                                0x1e,0,0,0);
            if (iVar14 != 0) {
              ppTVar2 = &this->deleteButton;
              iVar14 = TEasy_Panel::create_button
                                 ((TEasy_Panel *)this,(TPanel *)this,ppTVar2,0x24c9,0,0xe6,0x1b8,
                                  0xb4,0x1e,0,0,0);
              if (iVar14 != 0) {
                ppTVar3 = &this->cancelButton;
                iVar14 = TEasy_Panel::create_button
                                   ((TEasy_Panel *)this,(TPanel *)this,ppTVar3,0xfa2,0,0x1ae,0x1b8,
                                    0xb4,0x1e,0,0,0);
                if (iVar14 != 0) {
                  TPanel::set_help_info((TPanel *)*ppTVar1,0x7531,-1);
                  TPanel::set_help_info((TPanel *)*ppTVar3,0x7532,-1);
                  pTVar6 = *ppTVar3;
                  pTVar6->hotkey = 0x1b;
                  pTVar6->hotkey_shift = 0;
                  pTVar6 = *ppTVar2;
                  pTVar6->hotkey_shift = 0;
                  pTVar6->hotkey = 0x2e;
                  fillList(this);
                  pcVar10 = TTextPanel::currentLine((TTextPanel *)this->list);
                  if (*pcVar10 == '\0') {
                    TButtonPanel::set_disabled(*ppTVar2,1);
                  }
                  TPanel::set_curr_child((TPanel *)this,(TPanel *)this->input);
                  tabList[1] = (TPanel *)this->input;
                  tabList[3] = (TPanel *)*ppTVar1;
                  tabList[2] = (TPanel *)this->list;
                  tabList[4] = (TPanel *)*ppTVar2;
                  TPanel::set_tab_order((TPanel *)this,tabList + 1,5);
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004a75a0
void * __thiscall
TribeSaveGameScreen::_vector_deleting_destructor_(TribeSaveGameScreen *this,uint param_1)
{
  ~TribeSaveGameScreen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeSaveGameScreen
// Address: 004a75c0
void __thiscall TribeSaveGameScreen::~TribeSaveGameScreen(TribeSaveGameScreen *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f3d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->input);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->list);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->scrollbar);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->okButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancelButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->deleteButton);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: fillList
// Address: 004a7670
// [HELPER] s__s__gam: "%s*.gam"
// [HELPER] s__s__gmx: "%s*.gmx"
// [HELPER] s__s__scn: "%s*.scn"
// [HELPER] s__s__scx: "%s*.scx"
void __thiscall TribeSaveGameScreen::fillList(TribeSaveGameScreen *this)
{
  char cVar1;
  TListPanel *this_00;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char file_name [260];
  _finddata_t fileInfo;
  
  TTextPanel::empty_list((TTextPanel *)this->list);
  this->list->_padding_ = 1;
  if (this->modeValue == SaveGame) {
    sprintf(file_name + 4,s__s__gam,rge_base_game->prog_info->save_dir);
  }
  else {
    sprintf(file_name + 4,s__s__scn,rge_base_game->prog_info->scenario_dir);
  }
  iVar2 = __findfirst(file_name + 4,&fileInfo.time_create);
  iVar3 = iVar2;
  while (iVar3 != -1) {
    uVar4 = 0xffffffff;
    pcVar5 = fileInfo.name + 4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    strncpy(file_name + 4,fileInfo.name + 4,~uVar4 - 5);
    file_name[~uVar4 - 1] = '\0';
    TTextPanel::append_line((TTextPanel *)this->list,file_name + 4,0);
    iVar3 = __findnext(iVar2,&fileInfo.time_create);
  }
  if (this->modeValue == SaveGame) {
    sprintf(file_name + 4,s__s__gmx,rge_base_game->prog_info->save_dir);
  }
  else {
    sprintf(file_name + 4,s__s__scx,rge_base_game->prog_info->scenario_dir);
  }
  iVar2 = __findfirst(file_name + 4,&fileInfo.time_create);
  iVar3 = iVar2;
  do {
    if (iVar3 == -1) {
      return;
    }
    uVar4 = 0xffffffff;
    pcVar5 = fileInfo.name + 4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    strncpy(file_name + 4,fileInfo.name + 4,~uVar4 - 5);
    this_00 = this->list;
    file_name[~uVar4 - 1] = '\0';
    TTextPanel::append_line((TTextPanel *)this_00,file_name + 4,0);
    iVar3 = __findnext(iVar2,&fileInfo.time_create);
  } while( true );
}

// --------------------------------------------------

// Function: action
// Address: 004a7850
// [HELPER] s_Cancel_Dialog: "Cancel Dialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_YesNoDialog: "YesNoDialog"
// [HELPER] s__s_gam: "%s.gam"
// [HELPER] s__s_gmx: "%s.gmx"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s__s_s_gam: "%s%s.gam"
// [HELPER] s__s_s_gmx: "%s%s.gmx"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_s_scx: "%s%s.scx"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
// [HELPER] s_rb: "rb"
long __thiscall
TribeSaveGameScreen::action
          (TribeSaveGameScreen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  char cVar1;
  byte bVar2;
  TListPanel *this_00;
  Mode MVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  long lVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  char *pcVar11;
  uchar exist_flag;
  char tempFileName [260];
  char text [556];
  
  if (param_1 != (TPanel *)0x0) {
    pcVar4 = TPanel::panelName(param_1);
    if (pcVar4 != (char *)0x0) {
      pbVar8 = &s_Cancel_Dialog;
      pbVar5 = (byte *)TPanel::panelName(param_1);
      do {
        bVar2 = *pbVar5;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_004a78b1:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004a78b6;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_004a78b1;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_004a78b6:
      if (iVar6 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_Cancel_Dialog);
        if (param_2 != 0) {
          return 1;
        }
        if (this->modeValue == SaveGame) {
          pcVar9 = rge_base_game->prog_info->save_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
          pcVar11 = s__s_s_gam;
        }
        else {
          pcVar9 = rge_base_game->prog_info->scenario_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
          pcVar11 = s__s_s_scn;
        }
        sprintf(tempFileName + 4,pcVar11,pcVar9,pcVar4);
        __unlink(tempFileName + 4);
        if (this->modeValue == SaveGame) {
          pcVar9 = rge_base_game->prog_info->save_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
          pcVar11 = s__s_s_gmx;
        }
        else {
          pcVar9 = rge_base_game->prog_info->scenario_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
          pcVar11 = s__s_s_scx;
        }
        sprintf(tempFileName + 4,pcVar11,pcVar9,pcVar4);
        __unlink(tempFileName + 4);
        lVar7 = TTextPanel::get_line((TTextPanel *)this->list);
        TTextPanel::delete_line((TTextPanel *)this->list,lVar7);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
        TEditPanel::set_text(this->input,pcVar4);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
        if (*pcVar4 != '\0') {
          return 1;
        }
        TButtonPanel::set_disabled(this->deleteButton,1);
        return 1;
      }
    }
    if ((((TButtonPanel *)param_1 == this->deleteButton) && (param_2 == 1)) &&
       (pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list), *pcVar4 != '\0')) {
      TPanel::get_string((TPanel *)this,0x24ca,tempFileName + 4,0x100);
      pcVar4 = TTextPanel::currentLine((TTextPanel *)this->list);
      sprintf(text + 4,tempFileName + 4,pcVar4);
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)this,text + 4,&s_Cancel_Dialog,0x1c2,100);
    }
    this_00 = this->list;
    if (((TListPanel *)param_1 == this_00) && (param_2 == 1)) {
      pcVar4 = TTextPanel::currentLine((TTextPanel *)this_00);
      TEditPanel::set_text(this->input,pcVar4);
      return 1;
    }
    if (((((TButtonPanel *)param_1 == this->okButton) && (param_2 == 1)) ||
        (((TEditPanel *)param_1 == this->input && (param_2 == 0)))) ||
       (((TListPanel *)param_1 == this_00 && (param_2 == 3)))) {
      pcVar4 = this->fileNameNoExt;
      TEditPanel::get_trimmed_str(this->input,pcVar4,0x104);
      iVar6 = -1;
      pcVar9 = pcVar4;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (iVar6 == -2) {
        if (this->modeValue != SaveGame) {
          TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x24c7,(char *)0x0,0x1c2,100);
          return 1;
        }
        TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x24c6,(char *)0x0,0x1c2,100);
        return 1;
      }
      tempFileName[3] = '\0';
      pcVar9 = this->fileName;
      if (this->modeValue == SaveGame) {
        sprintf(pcVar9,s__s_gam,pcVar4);
        pcVar11 = rge_base_game->prog_info->save_dir;
      }
      else {
        sprintf(pcVar9,s__s_scn,pcVar4);
        pcVar11 = rge_base_game->prog_info->scenario_dir;
      }
      sprintf(tempFileName + 4,s__s_s,pcVar11,pcVar9);
      iVar6 = fopen(tempFileName + 4,s_rb);
      if (iVar6 != 0) {
        tempFileName[3] = '\x01';
        fclose(iVar6);
      }
      if (this->modeValue == SaveGame) {
        sprintf(pcVar9,s__s_gmx,pcVar4);
        pcVar4 = rge_base_game->prog_info->save_dir;
      }
      else {
        sprintf(pcVar9,s__s_scx,pcVar4);
        pcVar4 = rge_base_game->prog_info->scenario_dir;
      }
      sprintf(tempFileName + 4,s__s_s,pcVar4,pcVar9);
      if (tempFileName[3] == '\0') {
        iVar6 = fopen(tempFileName + 4,s_rb);
        if (iVar6 != 0) {
          tempFileName[3] = '\x01';
          fclose(iVar6);
        }
        if (tempFileName[3] == '\0') {
          MVar3 = this->modeValue;
          if (MVar3 == SaveGame) {
            iVar6 = TRIBE_Game::save_game((TRIBE_Game *)rge_base_game,pcVar9);
            if (iVar6 == 0) {
              TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x962,(char *)0x0,0x1c2,100);
              return 1;
            }
          }
          else if (MVar3 == SaveScenario) {
            iVar6 = TRIBE_Game::save_scenario((TRIBE_Game *)rge_base_game,pcVar9);
            if (iVar6 == 0) {
              TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x963,(char *)0x0,0x1c2,100);
              return 1;
            }
          }
          else if (MVar3 == SaveScenarioEdit) {
            save_for_scenario_editor(this);
            return 1;
          }
          return 1;
        }
      }
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)this,0x24c8,(char *)0x0,0x1c2,100);
      return 1;
    }
    if ((((TButtonPanel *)param_1 == this->cancelButton) && (param_2 == 1)) ||
       (((TEditPanel *)param_1 == this->input && (param_2 == 1)))) {
      iVar6 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar6 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      if (this->modeValue == SaveScenarioEdit) {
        pcVar4 = s_Scenario_Editor_Screen;
      }
      else {
        pcVar4 = s_Game_Screen;
      }
      TPanelSystem::setCurrentPanel(&panel_system,pcVar4,0);
      TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
      return 1;
    }
    pcVar4 = TPanel::panelName(param_1);
    if (pcVar4 != (char *)0x0) {
      pbVar8 = &s_OKDialog;
      pbVar5 = (byte *)TPanel::panelName(param_1);
      do {
        bVar2 = *pbVar5;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_004a7df1:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004a7df6;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_004a7df1;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_004a7df6:
      if (iVar6 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
        TPanel::set_curr_child((TPanel *)this,(TPanel *)this->input);
        return 1;
      }
    }
    pcVar4 = TPanel::panelName(param_1);
    if (pcVar4 != (char *)0x0) {
      pbVar8 = &s_YesNoDialog;
      pbVar5 = (byte *)TPanel::panelName(param_1);
      do {
        bVar2 = *pbVar5;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_004a7e68:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004a7e6d;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_004a7e68;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_004a7e6d:
      if (iVar6 == 0) {
        if (param_2 != 0) {
          TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
          TPanel::set_curr_child((TPanel *)this,(TPanel *)this->input);
          return 1;
        }
        TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
        MVar3 = this->modeValue;
        if (MVar3 == SaveGame) {
          TEditPanel::get_trimmed_str(this->input,this->fileNameNoExt,0x104);
          sprintf(tempFileName + 4,s__s_s_gam,rge_base_game->prog_info->save_dir,this->fileNameNoExt
                 );
          __unlink(tempFileName + 4);
          iVar6 = TRIBE_Game::save_game((TRIBE_Game *)rge_base_game,this->fileName);
          if (iVar6 != 0) {
            return 1;
          }
          TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x962,(char *)0x0,0x1c2,100);
          return 1;
        }
        if (MVar3 != SaveScenario) {
          if (MVar3 != SaveScenarioEdit) {
            return 1;
          }
          TEditPanel::get_trimmed_str(this->input,this->fileNameNoExt,0x104);
          sprintf(tempFileName + 4,s__s_s_scn,rge_base_game->prog_info->scenario_dir,
                  this->fileNameNoExt);
          __unlink(tempFileName + 4);
          save_for_scenario_editor(this);
          return 1;
        }
        TEditPanel::get_trimmed_str(this->input,this->fileNameNoExt,0x104);
        sprintf(tempFileName + 4,s__s_s_scn,rge_base_game->prog_info->scenario_dir,
                this->fileNameNoExt);
        __unlink(tempFileName + 4);
        iVar6 = TRIBE_Game::save_scenario((TRIBE_Game *)rge_base_game,this->fileName);
        if (iVar6 != 0) {
          return 1;
        }
        TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x963,(char *)0x0,0x1c2,100);
        return 1;
      }
    }
  }
  lVar7 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar7;
}

// --------------------------------------------------

// Function: save_for_scenario_editor
// Address: 004a8060
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Status_Screen: "Status Screen"
void __thiscall TribeSaveGameScreen::save_for_scenario_editor(TribeSaveGameScreen *this)
{
  char cVar1;
  TPanel *pTVar2;
  int iVar3;
  TRIBE_Screen_Sed_Open *this_00;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar4;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f3fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
  RGE_Scenario::Set_scenario_name(rge_base_game->world->scenario,this->fileName);
  cVar1 = (**(code **)(rge_base_game->world->_padding_ + 0xe4))(this->fileName);
  if (cVar1 == '\0') {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)this,0x963,(char *)0x0,0x1c2,100);
    *unaff_FS_OFFSET = this;
    return;
  }
  pTVar2 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Screen);
  if (pTVar2 != (TPanel *)0x0) {
    pTVar2[4].fill_in_background = '\0';
  }
  iVar3 = this->quit_after_save;
  if (iVar3 == 1) {
    iVar3 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
    if (iVar3 == 0) {
      RGE_Base_Game::close(rge_base_game);
      *unaff_FS_OFFSET = this;
      return;
    }
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  }
  else {
    if (iVar3 == 2) {
      this_00 = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
      pcStack_8 = (code *)0x0;
      if (this_00 != (TRIBE_Screen_Sed_Open *)0x0) {
        TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this_00);
      }
      pcStack_8 = (code *)0xffffffff;
      pcVar4 = s_Scenario_Editor_Open;
    }
    else {
      if (iVar3 == 3) {
        TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
        goto LAB_004a81a7;
      }
      pcVar4 = s_Scenario_Editor_Screen;
    }
    TPanelSystem::setCurrentPanel(&panel_system,pcVar4,0);
  }
LAB_004a81a7:
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  *unaff_FS_OFFSET = this;
  return;
}

// --------------------------------------------------

