// Class: TRIBE_Credits_Screen
// Size:  0x8B8
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
// [130] set_text
// [131] set_text
// [132] set_text
// [133] set_bevel_info
//
// Member Layout:
// [0x478] TScrollTextPanel * text_panel
// [0x47C] int text_set
// [0x480] int picture_set
// [0x484] ulong last_picture_time
// [0x488] ulong last_pause_time
// [0x48C] ScreenMode mode
// [0x490] tagPALETTEENTRY[256] color_table (sz: 0x400)
// [0x890] tagPALETTEENTRY color
// [0x894] TShape *[7] back_pics (sz: 0x1C)
// [0x8B0] int first_draw
// [0x8B4] int text_done
// ----------------------------------------------------------------

// Function: TRIBE_Credits_Screen
// Address: 004926e0
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_credit_d: "credit%d"
// [HELPER] s_data2_list_cr: "data2\list.cr"
// [HELPER] s_scr_cred: "scr_cred"
TRIBE_Credits_Screen * __thiscall
TRIBE_Credits_Screen::TRIBE_Credits_Screen(TRIBE_Credits_Screen *this)
{
  TMusic_System *this_00;
  long lVar1;
  RGE_Font *pRVar2;
  int iVar3;
  TScrollTextPanel *pTVar4;
  TShape *pTVar5;
  int iVar6;
  TShape **ppTVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  long size;
  char temp_file_name [13];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055eace;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  temp_file_name._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Credits_Screen);
  this->_padding_ = (int)&_vftable_;
  this->text_panel = (TScrollTextPanel *)0x0;
  this->text_set = 1;
  this->picture_set = 1;
  this->last_picture_time = 0;
  this->last_pause_time = 0;
  this->mode = ModeNone;
  this->first_draw = 1;
  this->text_done = 0;
  ppTVar7 = this->back_pics;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppTVar7 = (TShape *)0x0;
    ppTVar7 = ppTVar7 + 1;
  }
  local_4 = 0;
  lVar1 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,s_scr_cred,0xc38b,1);
  if (lVar1 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
  pRVar2 = RGE_Base_Game::get_font(rge_base_game,4);
  pcVar8 = (char *)0x0;
  iVar6 = __open(s_data2_list_cr,0x8000);
  if (iVar6 != -1) {
    lseek(iVar6,0,2);
    iVar3 = __tell(iVar6);
    pcVar8 = (char *)calloc(iVar3 + 1,0x400);
    if (pcVar8 != (char *)0x0) {
      lseek(iVar6,0,0);
      read(iVar6,pcVar8,iVar3);
    }
    close(iVar6);
  }
  pTVar4 = (TScrollTextPanel *)operator_new(0x198);
  local_4._0_1_ = 1;
  if (pTVar4 == (TScrollTextPanel *)0x0) {
    pTVar4 = (TScrollTextPanel *)0x0;
  }
  else {
    pTVar4 = (TScrollTextPanel *)
             TScrollTextPanel::TScrollTextPanel
                       (pTVar4,(TPanel *)this,(TDrawArea *)this->_padding_,
                        this->_padding_ / 2 + -0xfa,this->_padding_ / 2 + -0x96,500,300,0x1e,
                        pRVar2->font,pRVar2->font_wid,pRVar2->font_hgt,pcVar8);
  }
  local_4._0_1_ = 0;
  this->text_panel = pTVar4;
  if (pcVar8 != (char *)0x0) {
    free(pcVar8);
  }
  this->back_pics[0] = (TShape *)this->_padding_;
  ppTVar7 = this->back_pics;
  iVar6 = 0xc3eb;
  do {
    ppTVar7 = ppTVar7 + 1;
    sprintf(temp_file_name + 4,s_credit_d,iVar6 + -0xc3e9);
    pTVar5 = (TShape *)operator_new(0x20);
    local_4._0_1_ = 2;
    if (pTVar5 == (TShape *)0x0) {
      pTVar5 = (TShape *)0x0;
    }
    else {
      pTVar5 = (TShape *)TShape::TShape(pTVar5,temp_file_name + 4,iVar6);
    }
    *ppTVar7 = pTVar5;
    local_4._0_1_ = 0;
    iVar3 = iVar6 + -0xc3e9;
    iVar6 = iVar6 + 1;
  } while (iVar3 < 7);
  this_00 = rge_base_game->music_system;
  if (((this_00 != (TMusic_System *)0x0) && (this_00->music_type == '\x01')) &&
     (this_00->track_count == 0xf)) {
    TMusic_System::play_tracks(this_00,0xf,0xf,1,0,0);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00492950
void * __thiscall
TRIBE_Credits_Screen::_scalar_deleting_destructor_(TRIBE_Credits_Screen *this,uint param_1)
{
  ~TRIBE_Credits_Screen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Credits_Screen
// Address: 00492970
void __thiscall TRIBE_Credits_Screen::~TRIBE_Credits_Screen(TRIBE_Credits_Screen *this)
{
  TShape *this_00;
  TMusic_System *this_01;
  int iVar1;
  TShape **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055eae8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  ppTVar2 = this->back_pics;
  iVar1 = 7;
  do {
    this_00 = *ppTVar2;
    if (this_00 != (TShape *)0x0) {
      TShape::~TShape(this_00);
      operator_delete(this_00);
      *ppTVar2 = (TShape *)0x0;
    }
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->_padding_ = 0;
  if (this->text_panel != (TScrollTextPanel *)0x0) {
    (**(code **)this->text_panel->_padding_)(1);
    this->text_panel = (TScrollTextPanel *)0x0;
  }
  this_01 = rge_base_game->music_system;
  if (((this_01 != (TMusic_System *)0x0) && (this_01->music_type == '\x01')) &&
     (this_01->track_count == 0xf)) {
    TMusic_System::play_tracks(this_01,5,0xe,1,0,0);
  }
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 00492a40
long __thiscall
TRIBE_Credits_Screen::handle_mouse_down
          (TRIBE_Credits_Screen *this,uchar param_1,long param_2,long param_3,int param_4,
          int param_5)
{
  close_screen(this);
  return 1;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00492a50
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
long __thiscall TRIBE_Credits_Screen::handle_idle(TRIBE_Credits_Screen *this)
{
  ScreenMode SVar1;
  TDrawArea *this_00;
  TDrawSystem *pTVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  
  SVar1 = this->mode;
  if (SVar1 == ModeNone) {
    if (this->last_picture_time != 0) {
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0xf5);
      if (9999 < uVar3 - this->last_picture_time) {
        this_00 = (TDrawArea *)this->_padding_;
        pTVar2 = this_00->DrawSystem;
        if ((pTVar2->ScreenMode == '\x02') || (pTVar2->DrawType == '\x01')) {
          iVar5 = this->_padding_;
          this->mode = ModeFadeOut;
          (this->color).peRed = '\0';
          (this->color).peGreen = '\0';
          (this->color).peBlue = '\0';
          if (iVar5 == 0) {
            TDrawArea::GetPalette(this_00,this->color_table);
          }
          else {
            GetPaletteEntries(iVar5,0,0x100,this->color_table);
          }
          RGE_fade_palette_start
                    ((TDrawArea *)this->_padding_,this->color,0.5,'\x01',(tagPALETTEENTRY *)0x0,0xff
                     ,-1);
        }
        else {
          this->mode = ModePause;
        }
      }
      goto LAB_00492c91;
    }
    iVar5 = 0xf1;
  }
  else {
    if (SVar1 == ModeFadeOut) {
      iVar5 = RGE_fade_palette_step();
      if (iVar5 != 0) {
        iVar5 = this->_padding_;
        this->mode = ModePause;
        this->last_pause_time = 0;
        (**(code **)(iVar5 + 0x20))(1);
        (**(code **)(iVar5 + 0x54))();
        TDrawSystem::Paint(*(TDrawSystem **)this->_padding_,(tagRECT *)0x0);
      }
      goto LAB_00492c91;
    }
    if (SVar1 == ModePause) {
      if (this->last_pause_time == 0) {
        uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x11a);
        this->last_pause_time = uVar3;
        goto LAB_00492c91;
      }
      debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x11e);
      iVar5 = this->picture_set + 1;
      this->mode = ModeFadeIn;
      this->picture_set = iVar5;
      if (7 < iVar5) {
        this->picture_set = 1;
      }
      iVar5 = this->_padding_;
      this->_padding_ = (int)this->back_pics[this->picture_set + -1];
      (**(code **)(iVar5 + 0x20))(1);
      (**(code **)(iVar5 + 0x54))();
      TDrawSystem::Paint(*(TDrawSystem **)this->_padding_,(tagRECT *)0x0);
      pTVar2 = ((TDrawArea *)this->_padding_)->DrawSystem;
      if ((pTVar2->ScreenMode == '\x02') || (pTVar2->DrawType == '\x01')) {
        RGE_fade_palette_start
                  ((TDrawArea *)this->_padding_,this->color,0.5,'\x02',this->color_table,0xff,-1);
        goto LAB_00492c91;
      }
      this->mode = ModeNone;
      iVar5 = 0x138;
    }
    else {
      if (SVar1 != ModeFadeIn) goto LAB_00492c91;
      iVar5 = RGE_fade_palette_step();
      if (iVar5 == 0) goto LAB_00492c91;
      this->mode = ModeNone;
      iVar5 = 0x142;
    }
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,iVar5);
  this->last_picture_time = uVar3;
LAB_00492c91:
  if (this->text_done != 0) {
    close_screen(this);
    return 1;
  }
  lVar4 = TPanel::handle_idle((TPanel *)this);
  return lVar4;
}

// --------------------------------------------------

// Function: draw
// Address: 00492cc0
void __thiscall TRIBE_Credits_Screen::draw(TRIBE_Credits_Screen *this)
{
  TDrawSystem *pTVar1;
  int iVar2;
  TShape **ppTVar3;
  
  if (this->mode == ModePause) {
    pTVar1 = ((TDrawArea *)this->_padding_)->DrawSystem;
    if ((pTVar1->ScreenMode == '\x02') || (pTVar1->DrawType == '\x01')) {
      TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,0);
      return;
    }
  }
  if (this->first_draw != 0) {
    iVar2 = 7;
    ppTVar3 = this->back_pics;
    do {
      this->_padding_ = (int)*ppTVar3;
      TScreenPanel::draw((TScreenPanel *)this);
      ppTVar3 = ppTVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    this->first_draw = 0;
    this->_padding_ = (int)this->back_pics[0];
  }
  TScreenPanel::draw((TScreenPanel *)this);
  return;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 00492d50
long __thiscall
TRIBE_Credits_Screen::key_down_action
          (TRIBE_Credits_Screen *this,long param_1,short param_2,int param_3,int param_4,int param_5
          )
{
  if ((param_1 != 0xd) && (param_1 != 0x1b)) {
    return 0;
  }
  close_screen(this);
  return 1;
}

// --------------------------------------------------

// Function: action
// Address: 00492d70
long __thiscall
TRIBE_Credits_Screen::action
          (TRIBE_Credits_Screen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  if (((param_1 != (TPanel *)0x0) && ((TScrollTextPanel *)param_1 == this->text_panel)) &&
     (param_2 == 1)) {
    this->text_done = 1;
    return 1;
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: close_screen
// Address: 00492db0
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Main_Menu: "Main Menu"
void __thiscall TRIBE_Credits_Screen::close_screen(TRIBE_Credits_Screen *this)
{
  TPanel *pTVar1;
  int iVar2;
  TRIBE_Screen_Main_Menu *this_00;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055eb0b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = TPanelSystem::panel(&panel_system,s_Game_Screen);
  if (pTVar1 == (TPanel *)0x0) {
    this_00 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
    local_4 = 0;
    if (this_00 != (TRIBE_Screen_Main_Menu *)0x0) {
      TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_00);
    }
    local_4 = 0xffffffff;
    pcVar3 = s_Main_Menu;
  }
  else {
    iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
      RGE_Base_Game::set_paused(rge_base_game,0,0);
    }
    pcVar3 = s_Game_Screen;
  }
  TPanelSystem::setCurrentPanel(&panel_system,pcVar3,0);
  TPanelSystem::destroyPanel(&panel_system,s_Credits_Screen);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

