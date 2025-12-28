// Class: TribeConfigDialog
// Size:  0x564
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
// [0x490] Mode modeValue
// [0x494] TTextPanel * title
// [0x498] TTextPanel *[4] speedTitle (sz: 0x10)
// [0x4A8] TButtonPanel *[3] speedButton (sz: 0xC)
// [0x4B4] TTextPanel *[3] musicTitle (sz: 0xC)
// [0x4C0] TVerticalSliderPanel * musicSlider
// [0x4C4] TTextPanel *[3] soundTitle (sz: 0xC)
// [0x4D0] TVerticalSliderPanel * soundSlider
// [0x4D4] TTextPanel *[3] scrollSpeedTitle (sz: 0xC)
// [0x4E0] TVerticalSliderPanel * scrollSpeedSlider
// [0x4E4] TTextPanel *[4] sizeTitle (sz: 0x10)
// [0x4F4] TButtonPanel *[3] sizeButton (sz: 0xC)
// [0x500] TTextPanel *[3] mouseTitle (sz: 0xC)
// [0x50C] TButtonPanel *[2] mouseButton (sz: 0x8)
// [0x514] TTextPanel *[3] rolloverTitle (sz: 0xC)
// [0x520] TButtonPanel *[2] rolloverButton (sz: 0x8)
// [0x528] TTextPanel *[4] pathFindingTitle (sz: 0x10)
// [0x538] TButtonPanel *[3] pathFindingButton (sz: 0xC)
// [0x544] TButtonPanel * okButton
// [0x548] TButtonPanel * cancelButton
// [0x54C] long musicVolume
// [0x550] long soundVolume
// [0x554] float gameSpeed
// [0x558] long scrollSpeed
// [0x55C] long newMusicVolume
// [0x560] long newSoundVolume
// ----------------------------------------------------------------

// Function: TribeConfigDialog
// Address: 0043b560
// [HELPER] s_Config_Dialog: "Config Dialog"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall TribeConfigDialog::TribeConfigDialog(enum TribeConfigDialog::Mode,class
   TScreenPanel *) */

TribeConfigDialog * __thiscall
TribeConfigDialog::TribeConfigDialog(TribeConfigDialog *this,Mode param_1,TScreenPanel *param_2)
{
  float fVar1;
  ulong uVar2;
  bool bVar3;
  byte bVar4;
  long lVar5;
  char *pcVar6;
  TDrawArea *pTVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  TButtonPanel *pTVar11;
  TButtonPanel **ppTVar12;
  TButtonPanel **ppTVar13;
  undefined4 *unaff_FS_OFFSET;
  long lVar14;
  long lVar15;
  int iVar16;
  TPanel *tabList [10];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cfe8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  tabList[0] = (TPanel *)this;
  TDialogPanel::TDialogPanel((TDialogPanel *)this,s_Config_Dialog);
  this->modeValue = param_1;
  this->_padding_ = (int)&_vftable_;
  this->title = (TTextPanel *)0x0;
  this->speedTitle[0] = (TTextPanel *)0x0;
  iVar16 = 1;
  this->speedTitle[1] = (TTextPanel *)0x0;
  local_4 = 0;
  this->speedTitle[2] = (TTextPanel *)0x0;
  this->speedTitle[3] = (TTextPanel *)0x0;
  this->speedButton[0] = (TButtonPanel *)0x0;
  this->speedButton[1] = (TButtonPanel *)0x0;
  this->speedButton[2] = (TButtonPanel *)0x0;
  this->musicTitle[0] = (TTextPanel *)0x0;
  this->musicTitle[1] = (TTextPanel *)0x0;
  this->musicTitle[2] = (TTextPanel *)0x0;
  this->musicSlider = (TVerticalSliderPanel *)0x0;
  this->soundTitle[0] = (TTextPanel *)0x0;
  this->soundTitle[1] = (TTextPanel *)0x0;
  this->soundTitle[2] = (TTextPanel *)0x0;
  this->soundSlider = (TVerticalSliderPanel *)0x0;
  this->scrollSpeedTitle[0] = (TTextPanel *)0x0;
  this->scrollSpeedTitle[1] = (TTextPanel *)0x0;
  this->scrollSpeedTitle[2] = (TTextPanel *)0x0;
  this->scrollSpeedSlider = (TVerticalSliderPanel *)0x0;
  this->sizeTitle[0] = (TTextPanel *)0x0;
  this->sizeTitle[1] = (TTextPanel *)0x0;
  this->sizeTitle[2] = (TTextPanel *)0x0;
  this->sizeTitle[3] = (TTextPanel *)0x0;
  this->sizeButton[0] = (TButtonPanel *)0x0;
  this->sizeButton[1] = (TButtonPanel *)0x0;
  this->sizeButton[2] = (TButtonPanel *)0x0;
  this->mouseTitle[0] = (TTextPanel *)0x0;
  this->mouseTitle[1] = (TTextPanel *)0x0;
  this->mouseTitle[2] = (TTextPanel *)0x0;
  this->mouseButton[0] = (TButtonPanel *)0x0;
  this->mouseButton[1] = (TButtonPanel *)0x0;
  this->rolloverTitle[0] = (TTextPanel *)0x0;
  this->rolloverTitle[1] = (TTextPanel *)0x0;
  this->rolloverTitle[2] = (TTextPanel *)0x0;
  this->rolloverButton[0] = (TButtonPanel *)0x0;
  this->rolloverButton[1] = (TButtonPanel *)0x0;
  this->pathFindingTitle[0] = (TTextPanel *)0x0;
  this->pathFindingTitle[1] = (TTextPanel *)0x0;
  this->pathFindingTitle[2] = (TTextPanel *)0x0;
  this->pathFindingTitle[3] = (TTextPanel *)0x0;
  this->pathFindingButton[0] = (TButtonPanel *)0x0;
  this->pathFindingButton[1] = (TButtonPanel *)0x0;
  this->pathFindingButton[2] = (TButtonPanel *)0x0;
  this->okButton = (TButtonPanel *)0x0;
  this->cancelButton = (TButtonPanel *)0x0;
  lVar5 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_2);
  pcVar6 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_2);
  lVar15 = 0x186;
  lVar14 = 600;
  pTVar7 = TPanel::renderArea((TPanel *)param_2);
  iVar16 = TDialogPanel::setup((TDialogPanel *)this,pTVar7,(TPanel *)param_2,lVar14,lVar15,pcVar6,
                               lVar5,iVar16);
                    /* language.dll match for 0x24d7: "Game Settings" */
                    /* language.dll match for 0x24df: "Speed" */
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)this,(TPanel *)this,&this->title,0x24d7,0x67,10,0x18b,0x1e
                           ,1,1,1,0), iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,this->speedTitle,0x24df,0x14,0x32,0x6e,
                          0x1e,0xb,0,1,0), iVar16 == 0)) goto LAB_0043c089;
  iVar16 = 0;
  do {
    if (iVar16 == 0) {
LAB_0043b74d:
      iVar10 = 0x24d8;
    }
    else if (iVar16 == 1) {
      iVar10 = 0x24d9;
    }
    else {
      if (iVar16 != 2) goto LAB_0043b74d;
      iVar10 = 0x24da;
    }
    iVar9 = iVar16 * 0x23 + 0x55;
                    /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    iVar8 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,this->speedTitle + iVar16 + 1,iVar10,0x37,
                       iVar9,0x6e,0x1e,0xb,0,1,0);
    if ((iVar8 == 0) ||
       (iVar9 = TEasy_Panel::create_radio_button
                          ((TEasy_Panel *)this,(TPanel *)this,this->speedButton + iVar16,0x14,iVar9,
                           0x1e,0x1e,0,0), iVar9 == 0)) goto LAB_0043c089;
    iVar16 = iVar16 + 1;
  } while (iVar16 < 3);
  ppTVar12 = this->speedButton;
  iVar16 = 3;
  ppTVar13 = ppTVar12;
  do {
    TButtonPanel::set_radio_info(*ppTVar13,ppTVar12,3);
    ppTVar13 = ppTVar13 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  if (rge_base_game->prog_mode == 5) {
    iVar16 = 3;
    do {
      TButtonPanel::set_disabled(*ppTVar12,1);
      ppTVar12 = ppTVar12 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
  }
  fVar1 = rge_base_game->world->game_speed;
  bVar3 = fVar1 == _DAT_0056f740;
  this->gameSpeed = fVar1;
  if (bVar3) {
    pTVar11 = this->speedButton[2];
LAB_0043b849:
    TButtonPanel::set_radio_button(pTVar11);
  }
  else {
    if (fVar1 == _DAT_0056f744) {
      pTVar11 = this->speedButton[1];
      goto LAB_0043b849;
    }
    if (fVar1 == _DAT_0056f748) {
      pTVar11 = this->speedButton[0];
      goto LAB_0043b849;
    }
  }
                    /* language.dll match for 0x24db: "Music\\nVolume" */
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)this,(TPanel *)this,this->musicTitle,0x24db,0xa5,0x2d,0x6e,0x28
                      ,0xb,0,1,1);
                    /* language.dll match for 0x24dc: "High" */
                    /* language.dll match for 0x24dd: "Off" */
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)this,(TPanel *)this,this->musicTitle + 1,0x24dc,0xbe,0x55,
                           0x6e,0x14,0xb,0,1,0), iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,this->musicTitle + 2,0x24dd,0xbe,0xa5,
                          0x6e,0x14,0xb,0,1,0), iVar16 == 0)) goto LAB_0043c089;
  iVar16 = TEasy_Panel::create_vert_slider
                     ((TEasy_Panel *)this,(TPanel *)this,&this->musicSlider,100,10,0x14,0xaa,0x55,
                      0x14,100);
  if (iVar16 == 0) goto LAB_0043c089;
  if (rge_base_game->music_system == (TMusic_System *)0x0) {
    this->musicVolume = 99;
  }
  else {
    iVar16 = (int)((ulonglong)((longlong)rge_base_game->music_system->volume * -0x51eb851f) >> 0x20)
    ;
    this->musicVolume = (iVar16 >> 5) - (iVar16 >> 0x1f);
  }
  TScrollBarPanel::set_tab_pos((TScrollBarPanel *)this->musicSlider,this->musicVolume);
                    /* language.dll match for 0x24de: "Sound\\nVolume" */
  this->newMusicVolume = this->musicVolume;
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)this,(TPanel *)this,this->soundTitle,0x24de,0x131,0x2d,0x6e,
                      0x28,0xb,0,1,1);
                    /* language.dll match for 0x24dc: "High" */
                    /* language.dll match for 0x24dd: "Off" */
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)this,(TPanel *)this,this->soundTitle + 1,0x24dc,0x14a,0x55
                           ,0x6e,0x14,0xb,0,1,0), iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,this->soundTitle + 2,0x24dd,0x14a,0xa5,
                          0x6e,0x14,0xb,0,1,0), iVar16 == 0)) goto LAB_0043c089;
  iVar16 = TEasy_Panel::create_vert_slider
                     ((TEasy_Panel *)this,(TPanel *)this,&this->soundSlider,100,10,0x14,0x136,0x55,
                      0x14,100);
  if (iVar16 == 0) goto LAB_0043c089;
  if (rge_base_game->sound_system == (TSound_Driver *)0x0) {
    this->soundVolume = 99;
  }
  else {
    lVar5 = TSound_Driver::get_volume(rge_base_game->sound_system);
    iVar16 = (int)((ulonglong)((longlong)lVar5 * -0x51eb851f) >> 0x20);
    this->soundVolume = (iVar16 >> 5) - (iVar16 >> 0x1f);
  }
  TScrollBarPanel::set_tab_pos((TScrollBarPanel *)this->soundSlider,this->soundVolume);
                    /* language.dll match for 0x24f0: "Scroll\\nSpeed" */
  this->newSoundVolume = this->soundVolume;
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)this,(TPanel *)this,this->scrollSpeedTitle,0x24f0,0x1bd,0x2d,
                      0x6e,0x28,0xb,0,1,1);
                    /* language.dll match for 0x24f1: "Fast" */
                    /* language.dll match for 0x24f2: "Slow" */
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)this,(TPanel *)this,this->scrollSpeedTitle + 1,0x24f1,
                           0x1d6,0x55,0x6e,0x14,0xb,0,1,0), iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,this->scrollSpeedTitle + 2,0x24f2,0x1d6
                          ,0xa5,0x6e,0x14,0xb,0,1,0), iVar16 == 0)) goto LAB_0043c089;
  iVar16 = TEasy_Panel::create_vert_slider
                     ((TEasy_Panel *)this,(TPanel *)this,&this->scrollSpeedSlider,100,10,0x14,0x1c2,
                      0x55,0x14,100);
  if (iVar16 == 0) goto LAB_0043c089;
  uVar2 = rge_base_game->prog_info->mouse_scroll_interval;
  this->scrollSpeed = uVar2;
  TScrollBarPanel::set_tab_pos((TScrollBarPanel *)this->scrollSpeedSlider,uVar2 - 10);
                    /* language.dll match for 0x24e0: "Screen Size" */
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)this,(TPanel *)this,this->sizeTitle,0x24e0,0x14,0xbe,200,0x1e,
                      0xb,0,1,0);
  if (iVar16 == 0) goto LAB_0043c089;
  iVar16 = 0;
  do {
    if (iVar16 == 0) {
      iVar10 = 0x24e7;
    }
    else if (iVar16 == 1) {
      iVar10 = 0x24e8;
    }
    else if (iVar16 == 2) {
      iVar10 = 0x24e9;
    }
    iVar9 = iVar16 * 0x23 + 0xe1;
    iVar8 = TEasy_Panel::create_text
                      ((TEasy_Panel *)this,(TPanel *)this,this->sizeTitle + iVar16 + 1,iVar10,0x37,
                       iVar9,100,0x1e,0xb,0,1,0);
    if ((iVar8 == 0) ||
       (iVar9 = TEasy_Panel::create_radio_button
                          ((TEasy_Panel *)this,(TPanel *)this,this->sizeButton + iVar16,0x14,iVar9,
                           0x1e,0x1e,0,0), iVar9 == 0)) goto LAB_0043c089;
    iVar16 = iVar16 + 1;
  } while (iVar16 < 3);
  ppTVar12 = this->sizeButton;
  iVar16 = 3;
  ppTVar13 = ppTVar12;
  do {
    TButtonPanel::set_radio_info(*ppTVar13,ppTVar12,3);
    ppTVar13 = ppTVar13 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  iVar16 = *(int *)(*(int *)this->_padding_ + 0x2c);
  if (iVar16 == 0x280) {
    pTVar11 = *ppTVar12;
LAB_0043bc37:
    TButtonPanel::set_radio_button(pTVar11);
  }
  else {
    if (iVar16 == 800) {
      pTVar11 = this->sizeButton[1];
      goto LAB_0043bc37;
    }
    if (iVar16 == 0x400) {
      pTVar11 = this->sizeButton[2];
      goto LAB_0043bc37;
    }
  }
  iVar16 = TDrawSystem::IsModeAvail(*(TDrawSystem **)this->_padding_,0x280,0,8);
  if (iVar16 == 0) {
    TButtonPanel::set_disabled(*ppTVar12,1);
  }
  iVar16 = TDrawSystem::IsModeAvail(*(TDrawSystem **)this->_padding_,800,0,8);
  if (iVar16 == 0) {
    TButtonPanel::set_disabled(this->sizeButton[1],1);
  }
  iVar16 = TDrawSystem::IsModeAvail(*(TDrawSystem **)this->_padding_,0x400,0,8);
  if (iVar16 == 0) {
    TButtonPanel::set_disabled(this->sizeButton[2],1);
  }
                    /* language.dll match for 0x24ea: "Mouse Interface" */
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)this,(TPanel *)this,this->mouseTitle,0x24ea,0xaa,0xbe,0xd2,0x1e
                      ,0xb,0,1,0);
  if (iVar16 != 0) {
    iVar16 = 0;
    do {
      if (iVar16 == 0) {
                    /* language.dll match for 0x24eb: "Two Buttons" */
        iVar10 = TEasy_Panel::create_text
                           ((TEasy_Panel *)this,(TPanel *)this,this->mouseTitle + 1,0x24eb,0xcd,0xe1
                            ,0x78,0x1e,0xb,0,1,0);
      }
      else {
                    /* language.dll match for 0x24ec: "One Button" */
        iVar10 = TEasy_Panel::create_text
                           ((TEasy_Panel *)this,(TPanel *)this,this->mouseTitle + iVar16 + 1,0x24ec,
                            0xcd,iVar16 * 0x23 + 0xe1,0x78,0x1e,0xb,0,1,0);
      }
      if ((iVar10 == 0) ||
         (iVar10 = TEasy_Panel::create_radio_button
                             ((TEasy_Panel *)this,(TPanel *)this,this->mouseButton + iVar16,0xaa,
                              iVar16 * 0x23 + 0xe1,0x1e,0x1e,0,0), iVar10 == 0)) goto LAB_0043c089;
      iVar16 = iVar16 + 1;
    } while (iVar16 < 2);
    ppTVar12 = this->mouseButton;
    iVar16 = 2;
    ppTVar13 = ppTVar12;
    do {
      TButtonPanel::set_radio_info(*ppTVar13,ppTVar12,2);
      ppTVar13 = ppTVar13 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    if (rge_base_game->prog_info->interface_style == 2) {
      pTVar11 = *ppTVar12;
    }
    else {
      pTVar11 = this->mouseButton[1];
    }
    TButtonPanel::set_radio_button(pTVar11);
                    /* language.dll match for 0x24ed: "Roll-over Help" */
    iVar16 = TEasy_Panel::create_text
                       ((TEasy_Panel *)this,(TPanel *)this,this->rolloverTitle,0x24ed,0x14a,0xbe,
                        0xd2,0x1e,0xb,0,1,0);
    if (iVar16 != 0) {
      iVar16 = 0;
      do {
        if (iVar16 == 0) {
                    /* language.dll match for 0x24ee: "On" */
          iVar10 = TEasy_Panel::create_text
                             ((TEasy_Panel *)this,(TPanel *)this,this->rolloverTitle + 1,0x24ee,
                              0x16d,0xe1,0x78,0x1e,0xb,0,1,0);
        }
        else {
                    /* language.dll match for 0x24ef: "Off" */
          iVar10 = TEasy_Panel::create_text
                             ((TEasy_Panel *)this,(TPanel *)this,this->rolloverTitle + iVar16 + 1,
                              0x24ef,0x16d,iVar16 * 0x23 + 0xe1,0x78,0x1e,0xb,0,1,0);
        }
        if ((iVar10 == 0) ||
           (iVar10 = TEasy_Panel::create_radio_button
                               ((TEasy_Panel *)this,(TPanel *)this,this->rolloverButton + iVar16,
                                0x14a,iVar16 * 0x23 + 0xe1,0x1e,0x1e,0,0), iVar10 == 0))
        goto LAB_0043c089;
        iVar16 = iVar16 + 1;
      } while (iVar16 < 2);
      ppTVar12 = this->rolloverButton;
      iVar16 = 2;
      ppTVar13 = ppTVar12;
      do {
        TButtonPanel::set_radio_info(*ppTVar13,ppTVar12,2);
        ppTVar13 = ppTVar13 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      if (rge_base_game->rollover == 0) {
        pTVar11 = this->rolloverButton[1];
      }
      else {
        pTVar11 = *ppTVar12;
      }
      TButtonPanel::set_radio_button(pTVar11);
                    /* language.dll match for 0x260d: "Path Finding" */
      iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)this,(TPanel *)this,this->pathFindingTitle,0x260d,0x1cc,
                          0xbe,0xd2,0x1e,0xb,0,1,0);
      if (iVar16 != 0) {
        iVar16 = 0;
        iVar10 = 0xe1;
        ppTVar12 = this->pathFindingButton;
        do {
                    /* language.dll match for 0x78: "10" */
          iVar9 = TEasy_Panel::create_text
                            ((TEasy_Panel *)this,(TPanel *)this,(TTextPanel **)(ppTVar12 + -3),
                             iVar16 + 0x260e,0x1ef,iVar10,0x78,0x1e,0xb,0,1,0);
          if ((iVar9 == 0) ||
             (iVar9 = TEasy_Panel::create_radio_button
                                ((TEasy_Panel *)this,(TPanel *)this,ppTVar12,0x1cc,iVar10,0x1e,0x1e,
                                 0,0), iVar9 == 0)) goto LAB_0043c089;
          iVar9 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if (iVar9 != 0) {
            TButtonPanel::set_disabled(*ppTVar12,1);
          }
          iVar10 = iVar10 + 0x23;
          iVar16 = iVar16 + 1;
          ppTVar12 = ppTVar12 + 1;
        } while (iVar10 < 0x14a);
        ppTVar12 = this->pathFindingButton;
        iVar16 = 3;
        do {
          TButtonPanel::set_radio_info(*ppTVar12,this->pathFindingButton,3);
          ppTVar12 = ppTVar12 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        iVar16 = RGE_Base_Game::multiplayerGame(rge_base_game);
        if (iVar16 == 0) {
          bVar4 = RGE_Base_Game::pathFinding(rge_base_game);
        }
        else {
          bVar4 = RGE_Base_Game::mpPathFinding(rge_base_game);
        }
        if (bVar4 < 3) {
          TButtonPanel::set_radio_button(this->pathFindingButton[bVar4]);
        }
        ppTVar12 = &this->okButton;
                    /* language.dll match for 0xfa1: "OK" */
        iVar16 = TEasy_Panel::create_button
                           ((TEasy_Panel *)this,(TPanel *)this,ppTVar12,0xfa1,0,0x78,0x159,0xaa,0x1e
                            ,0,0,0);
        if (iVar16 != 0) {
          ppTVar13 = &this->cancelButton;
                    /* language.dll match for 0xfa2: "Cancel" */
          iVar16 = TEasy_Panel::create_button
                             ((TEasy_Panel *)this,(TPanel *)this,ppTVar13,0xfa2,0,0x136,0x159,0xaa,
                              0x1e,0,0,0);
          if (iVar16 != 0) {
            pTVar11 = *ppTVar13;
            pTVar11->hotkey = 0x1b;
            pTVar11->hotkey_shift = 0;
            TPanel::set_curr_child((TPanel *)this,(TPanel *)*ppTVar12);
            tabList[1] = (TPanel *)*ppTVar12;
            tabList[2] = (TPanel *)*ppTVar13;
            TPanel::set_tab_order((TPanel *)this,tabList + 1,2);
          }
        }
      }
    }
  }
LAB_0043c089:
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0043c0a0
/* public: virtual void * __thiscall TribeConfigDialog::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TribeConfigDialog::_scalar_deleting_destructor_(TribeConfigDialog *this,uint param_1)
{
  ~TribeConfigDialog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TribeConfigDialog
// Address: 0043c0c0
/* public: virtual __thiscall TribeConfigDialog::~TribeConfigDialog(void) */

void __thiscall TribeConfigDialog::~TribeConfigDialog(TribeConfigDialog *this)
{
  int iVar1;
  TTextPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055d008;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->title);
  ppTVar2 = this->speedTitle;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar3 = this->speedButton;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar3);
    ppTVar3 = ppTVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar2 = this->musicTitle;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->musicSlider);
  ppTVar2 = this->soundTitle;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->soundSlider);
  ppTVar2 = this->scrollSpeedTitle;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->scrollSpeedSlider);
  ppTVar2 = this->sizeTitle;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar3 = this->sizeButton;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar3);
    ppTVar3 = ppTVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar2 = this->mouseTitle;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar3 = this->mouseButton;
  iVar1 = 2;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar3);
    ppTVar3 = ppTVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar2 = this->rolloverTitle;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar3 = this->rolloverButton;
  iVar1 = 2;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar3);
    ppTVar3 = ppTVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar2 = this->pathFindingTitle;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ppTVar3 = this->pathFindingButton;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar3);
    ppTVar3 = ppTVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->okButton);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->cancelButton);
  local_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel((TDialogPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 0043c2b0
// [HELPER] do_color_log: " "
// [HELPER] s_Config_Dialog: "Config Dialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Music_Volume: "Music Volume"
/* WARNING: Variable defined which should be unmapped: new_speed */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual long __thiscall TribeConfigDialog::action(class TPanel *,long,unsigned
   long,unsigned long) */

long __thiscall
TribeConfigDialog::action
          (TribeConfigDialog *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  RGE_Prog_Info *pRVar1;
  TMusic_System *this_00;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  TSound_Driver *this_01;
  long lVar7;
  long lVar8;
  int iVar9;
  float new_speed;
  char msg [256];
  
  if (param_1 == (TPanel *)0x0) goto LAB_0043c80d;
  if (((TButtonPanel *)param_1 == this->okButton) && (param_2 == 1)) {
    if (this->modeValue == InGame) {
      iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar3 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      iVar3 = TButtonPanel::get_state(this->mouseButton[0]);
      if (iVar3 == 0) {
        rge_base_game->prog_info->interface_style = 1;
      }
      else {
        rge_base_game->prog_info->interface_style = 2;
      }
      (**(code **)(rge_base_game->_padding_ + 0x140))();
      iVar3 = TButtonPanel::get_state(this->rolloverButton[0]);
      if (iVar3 == 0) {
        rge_base_game->rollover = 0;
      }
      else {
        rge_base_game->rollover = 1;
      }
      iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if (iVar3 != 0) {
        iVar3 = TButtonPanel::get_state(this->pathFindingButton[0]);
        if (iVar3 == 0) {
          iVar3 = TButtonPanel::get_state(this->pathFindingButton[1]);
          if (iVar3 == 0) {
            iVar3 = TButtonPanel::get_state(this->pathFindingButton[2]);
            if (iVar3 != 0) {
              RGE_Base_Game::setPathFinding(rge_base_game,'\x02');
              numberPathingIterations = 0x1d4c;
            }
          }
          else {
            RGE_Base_Game::setPathFinding(rge_base_game,'\x01');
            numberPathingIterations = 5000;
          }
        }
        else {
          RGE_Base_Game::setPathFinding(rge_base_game,'\0');
                    /* language.dll match for 0x9c4: "This is not enabled in the trial version." */
          numberPathingIterations = 0x9c4;
        }
      }
      if (rge_base_game->prog_mode != 5) {
        msg[0] = '\0';
        msg[1] = '\0';
        msg[2] = '\0';
        msg[3] = '\0';
        iVar3 = TButtonPanel::get_state(this->speedButton[0]);
        if (iVar3 == 0) {
          iVar3 = TButtonPanel::get_state(this->speedButton[1]);
          if (iVar3 == 0) {
            iVar3 = TButtonPanel::get_state(this->speedButton[2]);
            if (iVar3 != 0) {
              msg[0] = '\0';
              msg[1] = '\0';
              msg[2] = '\0';
              msg[3] = '@';
            }
          }
          else {
            msg[0] = '\0';
            msg[1] = '\0';
            msg[2] = -0x40;
            msg[3] = '?';
          }
        }
        else {
          msg[0] = '\0';
          msg[1] = '\0';
          msg[2] = -0x80;
          msg[3] = '?';
        }
        if (((allow_user_commands != 0) && ((float)msg._0_4_ != _DAT_0056f74c)) &&
           ((float)msg._0_4_ != this->gameSpeed)) {
          iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if (iVar3 != 0) {
            uVar4 = TCommunications_Handler::WhoAmI(comm);
            pcVar5 = TCommunications_Handler::GetPlayerName(comm,uVar4);
                    /* language.dll match for 0xbf3: "Game speed changed." */
            pcVar6 = TPanel::get_string((TPanel *)this,0xbf3);
            sprintf(msg + 4,pcVar6,pcVar5);
            TCommunications_Handler::SendChatMsgAll(comm,msg + 4);
          }
          uVar2 = msg._0_4_;
          TRIBE_Command::command_game_speed
                    ((TRIBE_Command *)rge_base_game->world->commands,(float)msg._0_4_);
          iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if (iVar3 != 0) {
            RGE_Base_Game::set_game_speed(rge_base_game,(float)uVar2);
          }
        }
      }
      if (this->newMusicVolume != this->musicVolume) {
        pRVar1 = rge_base_game->prog_info;
        if (this->newMusicVolume < 99) {
          if (pRVar1->use_music == 0) {
            pRVar1->use_music = 1;
            TRegistry::RegSetInt(Regs,1,s_Music_Volume,this->newMusicVolume * 100);
            (**(code **)(rge_base_game->_padding_ + 0x58))();
            this_00 = rge_base_game->music_system;
            if (this_00 != (TMusic_System *)0x0) {
              if (this_00->music_type == '\x01') {
                iVar3 = this_00->track_count;
                iVar9 = 5;
              }
              else {
                if (this_00->music_type != '\x02') goto LAB_0043c5dd;
                iVar3 = this_00->track_count;
                iVar9 = 1;
              }
              TMusic_System::play_tracks(this_00,iVar9,iVar3,1,0,0);
            }
          }
        }
        else if (pRVar1->use_music != 0) {
          pRVar1->use_music = 0;
          (**(code **)(rge_base_game->_padding_ + 0x5c))();
        }
LAB_0043c5dd:
        if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
          TSound_Driver::set_volume(rge_base_game->sound_system,this->newSoundVolume * -100,1);
        }
      }
      iVar3 = TButtonPanel::get_state(this->sizeButton[0]);
      if (iVar3 == 0) {
        iVar3 = TButtonPanel::get_state(this->sizeButton[1]);
        if (iVar3 == 0) {
          iVar3 = TButtonPanel::get_state(this->sizeButton[2]);
          if (iVar3 == 0) goto LAB_0043c64b;
          lVar8 = 0x400;
          lVar7 = 0x300;
        }
        else {
          lVar8 = 800;
          lVar7 = 600;
        }
      }
      else {
LAB_0043c64b:
        lVar8 = 0x280;
        lVar7 = 0x1e0;
      }
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      (**(code **)(this->_padding_ + 0x14))(0);
      TEasy_Panel::prepare_for_close((TEasy_Panel *)this);
      if (do_color_log == '\0') {
        RGE_Base_Game::set_screen_size(rge_base_game,lVar8,lVar7);
      }
      goto LAB_0043c90b;
    }
  }
  else {
    if (((TButtonPanel *)param_1 == this->speedButton[0]) && (param_2 == 1)) {
      return 1;
    }
    if (((TButtonPanel *)param_1 == this->speedButton[1]) && (param_2 == 1)) {
      return 1;
    }
    if (((TButtonPanel *)param_1 == this->speedButton[2]) && (param_2 == 1)) {
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->sizeButton[0]) {
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->sizeButton[1]) {
      return 1;
    }
    if ((TButtonPanel *)param_1 == this->sizeButton[2]) {
      return 1;
    }
    if (((TVerticalSliderPanel *)param_1 == this->musicSlider) && (param_2 == 4)) {
      this->newMusicVolume = param_3;
      if (rge_base_game->music_system == (TMusic_System *)0x0) {
        return 1;
      }
      TMusic_System::set_volume(rge_base_game->music_system,param_3 * -100,1);
      this_01 = rge_base_game->sound_system;
      if (this_01 == (TSound_Driver *)0x0) {
        return 1;
      }
      param_3 = this->newSoundVolume;
LAB_0043c7cb:
      TSound_Driver::set_volume(this_01,param_3 * -100,1);
      return 1;
    }
    if (((TVerticalSliderPanel *)param_1 == this->soundSlider) && (param_2 == 4)) {
      this->newSoundVolume = param_3;
      this_01 = rge_base_game->sound_system;
      if (this_01 == (TSound_Driver *)0x0) {
        return 1;
      }
      goto LAB_0043c7cb;
    }
    if (((TVerticalSliderPanel *)param_1 == this->scrollSpeedSlider) && (param_2 == 4)) {
      pRVar1 = rge_base_game->prog_info;
      pRVar1->mouse_scroll_interval = param_3 + 10;
      pRVar1->key_scroll_interval = param_3 + 10;
LAB_0043c80d:
      lVar7 = TPanel::action((TPanel *)this,param_1,param_2,param_3,param_4);
      return lVar7;
    }
    if (((TButtonPanel *)param_1 != this->cancelButton) || (param_2 != 1)) goto LAB_0043c80d;
    if (rge_base_game->music_system != (TMusic_System *)0x0) {
      TMusic_System::set_volume(rge_base_game->music_system,this->musicVolume * -100,1);
    }
    if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
      TSound_Driver::set_volume(rge_base_game->sound_system,this->soundVolume * -100,1);
    }
    pRVar1 = rge_base_game->prog_info;
    pRVar1->mouse_scroll_interval = this->scrollSpeed;
    pRVar1->key_scroll_interval = this->scrollSpeed;
    if (this->modeValue == InGame) {
      iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar3 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      (**(code **)(this->_padding_ + 0x14))(0);
      goto LAB_0043c90b;
    }
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
LAB_0043c90b:
  TPanelSystem::destroyPanel(&panel_system,s_Config_Dialog);
  return 1;
}

// --------------------------------------------------

