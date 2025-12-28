// Class: TribeAboutDialog
// Size:  0x4C4
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
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
// [74] setup
// [75] setup
//
// Member Layout:
// [0x490] TTextPanel * title_text
// [0x494] TTextPanel * version_text
// [0x498] TTextPanel * ms_copy_text1
// [0x49C] TTextPanel * ms_copy_text2
// [0x4A0] TTextPanel * ens_copy_text
// [0x4A4] TTextPanel * genie_copy_text
// [0x4A8] TTextPanel * pid_label_text
// [0x4AC] TTextPanel * pid_text
// [0x4B0] TTextPanel * warning_text
// [0x4B4] TTextPanel * background
// [0x4B8] TButtonPanel * credits_button
// [0x4BC] TButtonPanel * close_button
// [0x4C0] TPicturePanel * circle_p_pic
// ----------------------------------------------------------------

// Function: TribeAboutDialog
// Address: 0043ad70
// [HELPER] s_00000_000_0000000_00000: "00000-000-0000000-00000"
// [HELPER] s_: ""
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_PID: "PID"
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s_circlep: "circlep"
TribeAboutDialog * __thiscall
TribeAboutDialog::TribeAboutDialog(TribeAboutDialog *this,TScreenPanel *param_1)
{
  TTextPanel **ppTVar1;
  TTextPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  TButtonPanel **ppTVar4;
  char cVar5;
  TTextPanel *this_00;
  TButtonPanel *pTVar6;
  long lVar7;
  char *pcVar8;
  TDrawArea *pTVar9;
  TPicturePanel *pTVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 *unaff_FS_OFFSET;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  TPanel *tabList [2];
  tagRECT rect;
  char temp_str [512];
  char str [4096];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055cf89;
  *unaff_FS_OFFSET = &local_c;
  temp_str._0_4_ = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_About_Dialog);
  ppTVar1 = &this->ms_copy_text1;
  ppTVar2 = &this->background;
  iVar22 = 1;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->title_text = (TTextPanel *)0x0;
  this->version_text = (TTextPanel *)0x0;
  *ppTVar1 = (TTextPanel *)0x0;
  this->ms_copy_text2 = (TTextPanel *)0x0;
  this->ens_copy_text = (TTextPanel *)0x0;
  this->genie_copy_text = (TTextPanel *)0x0;
  this->pid_label_text = (TTextPanel *)0x0;
  this->pid_text = (TTextPanel *)0x0;
  this->warning_text = (TTextPanel *)0x0;
  this->credits_button = (TButtonPanel *)0x0;
  this->close_button = (TButtonPanel *)0x0;
  this->circle_p_pic = (TPicturePanel *)0x0;
  *ppTVar2 = (TTextPanel *)0x0;
  lVar7 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1);
  pcVar8 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1);
  lVar18 = 0x19c;
  lVar16 = 0x208;
  pTVar9 = TPanel::renderArea((TPanel *)param_1);
  iVar22 = TDialogPanel::setup((TDialogPanel *)this,pTVar9,(TPanel *)param_1,lVar16,lVar18,pcVar8,
                               lVar7,iVar22);
  if (iVar22 != 0) {
    TEasy_Panel::create_text((TEasy_Panel *)this,(TPanel *)this,ppTVar2,s_,10,10,500,0x15e,4,0,0,0);
    (**(code **)((*ppTVar2)->_padding_ + 0xec))
              (3,(char)this->_padding_,*(undefined1 *)((int)&this->_padding_ + 1),
               *(undefined1 *)((int)&this->_padding_ + 2),*(undefined1 *)((int)&this->_padding_ + 3)
               ,(char)this->_padding_,*(undefined1 *)((int)&this->_padding_ + 1));
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->title_text,0x2419,0x14,0x14,0x1e0,0x14,4,0,
               0,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->version_text,0x241a,0x14,0x28,0x1e0,0x14,
               0xb,0,0,0);
    TPanel::get_string((TPanel *)this,0x2424,temp_str + 4,0x200);
    if (temp_str[4] == '\0') {
      TEasy_Panel::create_text
                ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x241b,0x14,0x41,0x1e0,0x14,10,0,0,0);
      if (*ppTVar1 != (TTextPanel *)0x0) {
        iVar22 = TTextPanel::get_text_rect(*ppTVar1,(tagRECT *)&rect.top);
        if (iVar22 != 0) {
          pTVar10 = (TPicturePanel *)operator_new(0x11c);
          local_4._0_1_ = 1;
          if (pTVar10 == (TPicturePanel *)0x0) {
            pTVar10 = (TPicturePanel *)0x0;
          }
          else {
            pTVar10 = (TPicturePanel *)TPicturePanel::TPicturePanel(pTVar10);
          }
          local_4 = (uint)local_4._1_3_ << 8;
          this->circle_p_pic = pTVar10;
          if (pTVar10 != (TPicturePanel *)0x0) {
            TPicturePanel::setup
                      (pTVar10,(TDrawArea *)this->_padding_,(TPanel *)this,
                       (rect.bottom - this->_padding_) + 3,0x42,0xf,0xe,s_circlep,0xc4e0,0,1);
            iVar23 = 0;
            iVar21 = 0;
            iVar20 = 0;
            lVar19 = 10;
            lVar17 = 0x14;
            lVar15 = 0x1e0;
            lVar18 = 0x41;
            lVar7 = TPanel::xPosition((TPanel *)this->circle_p_pic);
            iVar22 = this->_padding_;
            lVar16 = TPanel::width((TPanel *)this->circle_p_pic);
            TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,&this->ms_copy_text2,0x241c,
                       (lVar7 - iVar22) + lVar16,lVar18,lVar15,lVar17,lVar19,iVar20,iVar21,iVar23);
          }
        }
      }
    }
    else {
      pcVar11 = TPanel::get_string((TPanel *)this,0x241b);
      uVar12 = 0xffffffff;
      pcVar8 = temp_str;
      do {
        pcVar14 = pcVar11;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar14 = pcVar11 + 1;
        cVar5 = *pcVar11;
        pcVar11 = pcVar14;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      pcVar11 = pcVar14 + -uVar12;
      for (uVar13 = uVar12 >> 2; pcVar8 = pcVar8 + 4, uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar8 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar8 = pcVar8 + 1;
      }
      pcVar8 = TPanel::get_string((TPanel *)this,0x2424);
      uVar12 = 0xffffffff;
      do {
        pcVar11 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar11 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      iVar22 = -1;
      pcVar8 = temp_str + 4;
      do {
        pcVar14 = pcVar8;
        if (iVar22 == 0) break;
        iVar22 = iVar22 + -1;
        pcVar14 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar14;
      } while (cVar5 != '\0');
      pcVar8 = pcVar11 + -uVar12;
      pcVar11 = pcVar14 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar12 = 0xffffffff;
      pcVar8 = &s__;
      do {
        pcVar11 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar11 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      iVar22 = -1;
      pcVar8 = temp_str + 4;
      do {
        pcVar14 = pcVar8;
        if (iVar22 == 0) break;
        iVar22 = iVar22 + -1;
        pcVar14 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar14;
      } while (cVar5 != '\0');
      pcVar8 = pcVar11 + -uVar12;
      pcVar11 = pcVar14 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
      pcVar8 = TPanel::get_string((TPanel *)this,0x241c);
      uVar12 = 0xffffffff;
      do {
        pcVar11 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar11 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar5 != '\0');
      uVar12 = ~uVar12;
      iVar22 = -1;
      pcVar8 = temp_str + 4;
      do {
        pcVar14 = pcVar8;
        if (iVar22 == 0) break;
        iVar22 = iVar22 + -1;
        pcVar14 = pcVar8 + 1;
        cVar5 = *pcVar8;
        pcVar8 = pcVar14;
      } while (cVar5 != '\0');
      pcVar8 = pcVar11 + -uVar12;
      pcVar11 = pcVar14 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
      TEasy_Panel::create_text
                ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,temp_str + 4,0x14,0x41,0x1e0,0x14,10,0,0
                 ,0);
    }
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->ens_copy_text,0x241d,0x14,0x55,0x1e0,0x14,
               10,0,0,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->genie_copy_text,0x2423,0x14,0x69,0x1e0,0x28
               ,10,0,0,1);
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->pid_label_text,0x241e,0x14,0x96,0x5f,0x14,
               10,0,0,0);
    this_00 = this->pid_label_text;
    if (this_00 != (TTextPanel *)0x0) {
      iVar22 = TTextPanel::get_text_rect(this_00,(tagRECT *)&rect.top);
      if (iVar22 != 0) {
        pcVar8 = TRegistry::RegGetAscii(Regs,0,s_PID);
        if (pcVar8 == (char *)0x0) {
          pcVar8 = s_00000_000_0000000_00000;
        }
        sprintf(str + 4,s__s,pcVar8);
        TEasy_Panel::create_text
                  ((TEasy_Panel *)this,(TPanel *)this,&this->pid_text,str + 4,
                   (rect.bottom - this->_padding_) + 4,0x96,200,0x14,0xb,0,0,0);
      }
    }
    TPanel::get_string((TPanel *)this,0x241f,str + 4,0x1000);
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->warning_text,str + 4,0x14,0xaf,0x1e0,0xdc,
               10,0,0,1);
    ppTVar3 = &this->credits_button;
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,ppTVar3,0x2420,0,0x46,0x172,0xaa,0x1e,0,0,0);
    ppTVar4 = &this->close_button;
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,ppTVar4,0x2421,0,0x118,0x172,0xaa,0x1e,0,0,0);
    pTVar6 = *ppTVar4;
    pTVar6->hotkey = 0x1b;
    pTVar6->hotkey_shift = 0;
    tabList[1] = (TPanel *)*ppTVar3;
    rect.left = (long)*ppTVar4;
    TPanel::set_tab_order((TPanel *)this,tabList + 1,2);
    TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0043b2e0
void * __thiscall
TribeAboutDialog::_scalar_deleting_destructor_(TribeAboutDialog *this,uint param_1)
{
  ~TribeAboutDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeAboutDialog
// Address: 0043b300
void __thiscall TribeAboutDialog::~TribeAboutDialog(TribeAboutDialog *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055cfa8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->version_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ms_copy_text1);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ms_copy_text2);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->ens_copy_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->genie_copy_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->pid_label_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->pid_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->warning_text);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->credits_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->close_button);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->circle_p_pic);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->background);
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 0043b400
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_Game_Screen: "Game Screen"
long __thiscall
TribeAboutDialog::action
          (TribeAboutDialog *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  TPanel *pTVar1;
  int iVar2;
  TRIBE_Credits_Screen *this_00;
  long lVar3;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cfcb;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == 1) {
    if ((TButtonPanel *)param_1 == this->close_button) {
      pTVar1 = TPanelSystem::panel(&panel_system,s_Game_Screen);
      if (pTVar1 != (TPanel *)0x0) {
        iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
        if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
          RGE_Base_Game::set_paused(rge_base_game,0,0);
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        (**(code **)(this->_padding_ + 0x14))(0);
        TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
    }
    else {
      if ((TButtonPanel *)param_1 != this->credits_button) goto LAB_0043b520;
      this_00 = (TRIBE_Credits_Screen *)operator_new(0x8b8);
      local_4 = 0;
      if (this_00 != (TRIBE_Credits_Screen *)0x0) {
        TRIBE_Credits_Screen::TRIBE_Credits_Screen(this_00);
      }
      local_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Credits_Screen,0);
    }
    TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
LAB_0043b520:
  lVar3 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  *unaff_FS_OFFSET = local_c;
  return lVar3;
}

// --------------------------------------------------

// Function: draw
// Address: 0043b550
void __thiscall TribeAboutDialog::draw(TribeAboutDialog *this)
{
  if (*(char *)((int)&this->_padding_ + 3) != '\0') {
    if (this->_padding_ != 0) {
      TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,1);
    }
    *(undefined1 *)((int)&this->_padding_ + 3) = 0;
  }
  if (*(char *)((int)&this->_padding_ + 2) != '\0') {
    (**(code **)(this->_padding_ + 0xe0))(1);
    return;
  }
  (**(code **)(this->_padding_ + 0xe0))(0);
  return;
}

// --------------------------------------------------

