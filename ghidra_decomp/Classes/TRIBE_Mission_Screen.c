// Class: TRIBE_Mission_Screen
// Size:  0x49C
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
// [74] `scalar_deleting_destructor'
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
// [130] draw_item
//
// Member Layout:
// [0x478] TTextPanel * title
// [0x47C] TTextPanel * list
// [0x480] TScrollBarPanel * scroll_bar
// [0x484] TButtonPanel * ok_button
// [0x488] TButtonPanel *[3] text_buttons (sz: 0xC)
// [0x494] uchar game_flag
// [0x498] TPicture * vc_back_bmp
// ----------------------------------------------------------------

// Function: TRIBE_Mission_Screen
// Address: 004b8100
// [HELPER] s_Mission_Dialog: "Mission Dialog"
TRIBE_Mission_Screen * __thiscall
TRIBE_Mission_Screen::TRIBE_Mission_Screen
          (TRIBE_Mission_Screen *this,char *param_1,uchar param_2,TPicture *param_3)
{
  TButtonPanel **ppTVar1;
  TTextPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  char cVar4;
  long lVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  TButtonPanel **ppTVar12;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uchar starting_description;
  bool local_21d;
  undefined4 local_21c;
  char adjusted_name [260];
  char info_file [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f85b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  adjusted_name._0_4_ = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)this,s_Mission_Dialog);
  ppTVar1 = this->text_buttons;
  local_4 = 0;
  this->title = (TTextPanel *)0x0;
  this->ok_button = (TButtonPanel *)0x0;
  this->list = (TTextPanel *)0x0;
  this->scroll_bar = (TScrollBarPanel *)0x0;
  this->vc_back_bmp = (TPicture *)0x0;
  this->_padding_ = (int)&_vftable_;
  this->game_flag = param_2;
  *ppTVar1 = (TButtonPanel *)0x0;
  this->text_buttons[1] = (TButtonPanel *)0x0;
  this->text_buttons[2] = (TButtonPanel *)0x0;
  TPanelSystem::currentPanel(&panel_system);
  uVar9 = 0xffffffff;
  pcVar6 = info_file;
  pcVar8 = &s_scr9;
  do {
    pcVar11 = pcVar8;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar11 = pcVar8 + 1;
    cVar4 = *pcVar8;
    pcVar8 = pcVar11;
  } while (cVar4 != '\0');
  uVar9 = ~uVar9;
  pcVar8 = pcVar11 + -uVar9;
  for (uVar10 = uVar9 >> 2; pcVar6 = pcVar6 + 4, uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar6 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  }
  lVar5 = TScreenPanel::setup((TScreenPanel *)this,rge_base_game->draw_area,info_file + 4,0xc38c,1);
  if (lVar5 == 0) {
    this->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x280,0x1e0);
    pcVar6 = RGE_Scenario::Get_scenario_name(rge_base_game->world->scenario);
    if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {
      pcVar8 = TPanel::get_string((TPanel *)this,0x2655);
      uVar9 = 0xffffffff;
      pcVar6 = adjusted_name;
      do {
        pcVar11 = pcVar8;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar11 = pcVar8 + 1;
        cVar4 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar4 != '\0');
      uVar9 = ~uVar9;
      pcVar8 = pcVar11 + -uVar9;
      for (uVar10 = uVar9 >> 2; pcVar6 = pcVar6 + 4, uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar6 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar6 = pcVar6 + 1;
      }
    }
    else {
      uVar9 = 0xffffffff;
      local_21c = adjusted_name + 4;
      pcVar8 = pcVar6;
      do {
        pcVar11 = pcVar8;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar11 = pcVar8 + 1;
        cVar4 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar4 != '\0');
      uVar9 = ~uVar9;
      pcVar8 = pcVar11 + -uVar9;
      pcVar11 = local_21c;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar9 = 0xffffffff;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar4 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar4 != '\0');
      adjusted_name[~uVar9 - 1] = '\0';
    }
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,&this->title,adjusted_name + 4,10,0xf,0x26c,0x14,4
               ,1,1,0);
    ppTVar2 = &this->list;
    TEasy_Panel::create_text
              ((TEasy_Panel *)this,(TPanel *)this,ppTVar2,param_1,0xf,0x46,300,0x154,0xb,0,0,1);
    TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)this,&this->scroll_bar,*ppTVar2,0x14);
    if (this->_padding_ != 0) {
      (**(code **)((*ppTVar2)->_padding_ + 0xec))
                (3,(char)this->_padding_,*(undefined1 *)((int)&this->_padding_ + 1),
                 *(undefined1 *)((int)&this->_padding_ + 2),
                 *(undefined1 *)((int)&this->_padding_ + 3),(char)this->_padding_,
                 *(undefined1 *)((int)&this->_padding_ + 1));
    }
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,&this->ok_button,0xfa1,0,200,0x1b8,0xf0,0x1e,0,0,0
              );
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,ppTVar1,0x2a31,0,0x145,0x13c,0xb4,0x1e,0,-1,0);
    ppTVar3 = this->text_buttons + 1;
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,ppTVar3,0x2a32,0,0x145,0x15c,0xb4,0x1e,0,-1,0);
    TEasy_Panel::create_button
              ((TEasy_Panel *)this,(TPanel *)this,this->text_buttons + 2,0x2a37,0,0x145,0x17c,0xb4,
               0x1e,0,-1,0);
    local_21c = (char *)0x3;
    ppTVar12 = ppTVar1;
    do {
      TButtonPanel::set_radio_info(*ppTVar12,ppTVar1,3);
      ppTVar12 = ppTVar12 + 1;
      local_21c = (char *)((int)local_21c + -1);
    } while (local_21c != (char *)0x0);
    if (this->_padding_ < 0x281) {
      (**(code **)(this->title->_padding_ + 0x1c))(3,0xf,0x27a,0x14);
      (**(code **)(this->list->_padding_ + 0x1c))(0x14,0x32,600,0x73);
      (**(code **)((*ppTVar1)->_padding_ + 0x1c))(5,0x1bd,0x96,0x1e);
      (**(code **)((*ppTVar3)->_padding_ + 0x1c))(0xa5,0x1bd,0x96,0x1e);
      (**(code **)(this->text_buttons[2]->_padding_ + 0x1c))(0x145,0x1bd,0x96,0x1e);
      uVar16 = 0x1e;
      uVar15 = 0x96;
      uVar14 = 0x1bd;
      iVar7 = this->ok_button->_padding_;
      uVar13 = 0x1e5;
    }
    else if (this->_padding_ < 0x321) {
      TEasy_Panel::set_ideal_size((TEasy_Panel *)this,800,0x280);
      (**(code **)(this->title->_padding_ + 0x1c))(3,0xf,0x31a,0x14);
      (**(code **)(this->list->_padding_ + 0x1c))(0x1e,0x2d,0x2e4,0xe6);
      (**(code **)((*ppTVar1)->_padding_ + 0x1c))(5,0x235,0xbe,0x1e);
      (**(code **)((*ppTVar3)->_padding_ + 0x1c))(0xcd,0x235,0xbe,0x1e);
      (**(code **)(this->text_buttons[2]->_padding_ + 0x1c))(0x195,0x235,0xbe,0x1e);
      uVar16 = 0x1e;
      uVar15 = 0xbe;
      uVar14 = 0x235;
      iVar7 = this->ok_button->_padding_;
      uVar13 = 0x25d;
    }
    else {
      TEasy_Panel::set_ideal_size((TEasy_Panel *)this,0x400,0x300);
      (**(code **)(this->title->_padding_ + 0x1c))(3,0xf,0x3fa,0x14);
      (**(code **)(this->list->_padding_ + 0x1c))(0x28,0x41,0x3b0,0x136);
      (**(code **)((*ppTVar1)->_padding_ + 0x1c))(10,0x2b2,0xf0,0x32);
      (**(code **)((*ppTVar3)->_padding_ + 0x1c))(0x10a,0x2b2,0xf0,0x32);
      (**(code **)(this->text_buttons[2]->_padding_ + 0x1c))(0x20a,0x2b2,0xf0,0x32);
      uVar16 = 0x32;
      uVar15 = 0xf0;
      uVar14 = 0x2b2;
      iVar7 = this->ok_button->_padding_;
      uVar13 = 0x306;
    }
    (**(code **)(iVar7 + 0x1c))(uVar13,uVar14,uVar15,uVar16);
    pcVar6 = RGE_Scenario::Get_message(rge_base_game->world->scenario,0);
    if (pcVar6 == (char *)0x0) {
      (**(code **)((*ppTVar3)->_padding_ + 0x14))(0);
    }
    else {
      iVar7 = this->list->_padding_;
      pcVar8 = RGE_Scenario::Get_message(rge_base_game->world->scenario,0);
      (**(code **)(iVar7 + 0xe8))(pcVar8);
      TButtonPanel::set_radio_button(*ppTVar3);
    }
    local_21d = pcVar6 != (char *)0x0;
    pcVar6 = RGE_Scenario::Get_message(rge_base_game->world->scenario,4);
    if (pcVar6 == (char *)0x0) {
      (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
    }
    else {
      if (!local_21d) {
        iVar7 = this->list->_padding_;
        pcVar6 = RGE_Scenario::Get_message(rge_base_game->world->scenario,4);
        (**(code **)(iVar7 + 0xe8))(pcVar6);
        TButtonPanel::set_radio_button(*ppTVar1);
      }
      local_21d = (bool)(local_21d + '\x01');
    }
    pcVar6 = RGE_Scenario::Get_message(rge_base_game->world->scenario,1);
    if (pcVar6 == (char *)0x0) {
      (**(code **)(this->text_buttons[2]->_padding_ + 0x14))(0);
      if (local_21d == false) {
        (**(code **)(this->list->_padding_ + 0x14))(0);
      }
    }
    else {
      if (local_21d == false) {
        iVar7 = this->list->_padding_;
        pcVar6 = RGE_Scenario::Get_message(rge_base_game->world->scenario,1);
        (**(code **)(iVar7 + 0xe8))(pcVar6);
        TButtonPanel::set_radio_button(this->text_buttons[2]);
      }
      local_21d = (bool)(local_21d + '\x01');
    }
    if (local_21d == true) {
      (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
      (**(code **)((*ppTVar3)->_padding_ + 0x14))(0);
      (**(code **)(this->text_buttons[2]->_padding_ + 0x14))(0);
    }
    TPanel::set_curr_child((TPanel *)this,(TPanel *)this->ok_button);
    this->vc_back_bmp = param_3;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004b87b0
void * __thiscall
TRIBE_Mission_Screen::_vector_deleting_destructor_(TRIBE_Mission_Screen *this,uint param_1)
{
  ~TRIBE_Mission_Screen(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Mission_Screen
// Address: 004b87d0
void __thiscall TRIBE_Mission_Screen::~TRIBE_Mission_Screen(TRIBE_Mission_Screen *this)
{
  TButtonPanel **ppTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f878;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (((this->game_flag == '\0') && (rge_base_game->prog_info->use_sound != 0)) &&
     (rge_base_game->sound_system != (TSound_Driver *)0x0)) {
    TSound_Driver::stop_stream(rge_base_game->sound_system);
  }
  if (this->title != (TTextPanel *)0x0) {
    (**(code **)this->title->_padding_)(1);
  }
  if (this->list != (TTextPanel *)0x0) {
    (**(code **)this->list->_padding_)(1);
  }
  if (this->scroll_bar != (TScrollBarPanel *)0x0) {
    (**(code **)this->scroll_bar->_padding_)(1);
  }
  if (this->ok_button != (TButtonPanel *)0x0) {
    (**(code **)this->ok_button->_padding_)(1);
  }
  ppTVar1 = this->text_buttons;
  iVar2 = 3;
  do {
    if (*ppTVar1 != (TButtonPanel *)0x0) {
      (**(code **)(*ppTVar1)->_padding_)(1);
    }
    ppTVar1 = ppTVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel((TScreenPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 004b88b0
long __thiscall TRIBE_Mission_Screen::handle_idle(TRIBE_Mission_Screen *this)
{
  long lVar1;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  lVar1 = TPanel::handle_idle((TPanel *)this);
  return lVar1;
}

// --------------------------------------------------

// Function: draw
// Address: 004b88e0
// [HELPER] s_scr_vc__draw: "scr_vc::draw"
void __thiscall TRIBE_Mission_Screen::draw(TRIBE_Mission_Screen *this)
{
  int iVar1;
  uchar *puVar2;
  long lVar3;
  int iVar4;
  
  TScreenPanel::draw((TScreenPanel *)this);
  if (this->vc_back_bmp != (TPicture *)0x0) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    if (this->_padding_ == 2) {
      TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,
                       (uint)(byte)this->_padding_);
    }
    puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_scr_vc__draw,1);
    if (puVar2 != (uchar *)0x0) {
      if (this->_padding_ < 0x281) {
        iVar4 = this->_padding_ + 0xa6;
        lVar3 = this->_padding_ + 7;
      }
      else if (this->_padding_ < 0x321) {
        iVar4 = this->_padding_ + 0x118;
        lVar3 = this->_padding_ + 0x53;
      }
      else {
        iVar4 = this->_padding_ + 0x16b;
        lVar3 = this->_padding_ + 0xc5;
      }
      TPicture::Draw(this->vc_back_bmp,(TDrawArea *)this->_padding_,lVar3,iVar4,0,0);
      TDrawArea::Unlock((TDrawArea *)this->_padding_,s_scr_vc__draw);
    }
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: action
// Address: 004b89a0
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Mission_Dialog: "Mission Dialog"
long __thiscall
TRIBE_Mission_Screen::action
          (TRIBE_Mission_Screen *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  if (param_2 == 1) {
    if ((TButtonPanel *)param_1 == this->text_buttons[0]) {
      iVar2 = this->list->_padding_;
      pcVar1 = RGE_Scenario::Get_message(rge_base_game->world->scenario,4);
      (**(code **)(iVar2 + 0xe8))(pcVar1);
    }
    if ((TButtonPanel *)param_1 == this->text_buttons[1]) {
      iVar2 = this->list->_padding_;
      pcVar1 = RGE_Scenario::Get_message(rge_base_game->world->scenario,0);
      (**(code **)(iVar2 + 0xe8))(pcVar1);
    }
    if ((TButtonPanel *)param_1 == this->text_buttons[2]) {
      iVar2 = this->list->_padding_;
      pcVar1 = RGE_Scenario::Get_message(rge_base_game->world->scenario,1);
      (**(code **)(iVar2 + 0xe8))(pcVar1);
    }
    if ((TButtonPanel *)param_1 == this->ok_button) {
      if (this->game_flag == '\0') {
        TRIBE_Game::create_game_screen((TRIBE_Game *)rge_base_game);
      }
      else {
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
        if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
          RGE_Base_Game::set_paused(rge_base_game,0,0);
        }
      }
      TPanelSystem::destroyPanel(&panel_system,s_Mission_Dialog);
      return 1;
    }
  }
  lVar3 = TEasy_Panel::action((TEasy_Panel *)this,param_1,param_2,param_3,param_4);
  return lVar3;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 004b8ae0
// [HELPER] s_voice_wav: "voice.wav"
long __thiscall
TRIBE_Mission_Screen::key_down_action
          (TRIBE_Mission_Screen *this,long param_1,short param_2,int param_3,int param_4,int param_5
          )
{
  if ((param_4 != 0) && (param_1 == 0x56)) {
    if (((this->game_flag == '\0') && (rge_base_game->prog_info->use_sound != 0)) &&
       (rge_base_game->sound_system != (TSound_Driver *)0x0)) {
      TSound_Driver::stream_file(rge_base_game->sound_system,s_voice_wav,0,0);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

