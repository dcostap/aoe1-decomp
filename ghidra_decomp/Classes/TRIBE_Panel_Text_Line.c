// Class: TRIBE_Panel_Text_Line
// Size:  0x1C8
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
// [56] `vector_deleting_destructor'
// [57] run
// [58] wnd_proc
// [59] set_prog_mode
// [60] set_game_mode
// [61] set_player
// [62] get_error_code
// [63] get_string
// [64] get_string
// [65] get_string
// [66] get_string2
// [67] get_view_panel
// [68] get_map_panel
// [69] new_scenario_header
// [70] new_scenario_header
// [71] new_scenario_info
// [72] notification
// [73] reset_comm
// [74] send_game_options
// [75] receive_game_options
// [76] gameSummary
// [77] processCheatCode
// [78] setup_music_system
// [79] shutdown_music_system
// [80] setup
// [81] setup_cmd_options
// [82] setup_class
// [83] setup_main_window
// [84] setup_graphics_system
// [85] setup_palette
// [86] setup_mouse
// [87] setup_registry
// [88] setup_debugging_log
// [89] setup_chat
// [90] setup_comm
// [91] setup_sound_system
// [92] setup_fonts
// [93] setup_sounds
// [94] setup_shapes
// [95] setup_blank_screen
// [96] setup_timings
// [97] stop_sound_system
// [98] restart_sound_system
// [99] stop_music_system
// [100] restart_music_system
// [101] create_world
// [102] handle_message
// [103] handle_idle
// [104] handle_mouse_move
// [105] handle_key_down
// [106] handle_user_command
// [107] handle_command
// [108] handle_music_done
// [109] handle_paint
// [110] handle_activate
// [111] handle_init_menu
// [112] handle_exit_menu
// [113] handle_size
// [114] handle_palette_changed
// [115] handle_query_new_palette
// [116] handle_close
// [117] handle_destroy
// [118] action_update
// [119] action_mouse_move
// [120] action_key_down
// [121] action_user_command
// [122] action_command
// [123] action_music_done
// [124] action_activate
// [125] action_deactivate
// [126] action_init_menu
// [127] action_exit_menu
// [128] action_size
// [129] action_close
// [130] calc_timings
// [131] calc_timing_text
// [132] show_timings
// [133] show_comm
// [134] show_ai
// [135] setup_map_save_area
// [136] set_interface_messages
//
// Member Layout:
// [0x0F4] void * font
// [0x0F8] uchar text_type
// [0x0F9] char[200] text (sz: 0xC8)
// [0x1C4] long id
// ----------------------------------------------------------------

// Function: TRIBE_Panel_Text_Line
// Address: 00520d70
/* public: __thiscall TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(class TDrawArea *,class TPanel
   *,void *) */

TRIBE_Panel_Text_Line * __thiscall
TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line
          (TRIBE_Panel_Text_Line *this,TDrawArea *param_1,TPanel *param_2,void *param_3)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561548;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->font = param_3;
  local_4 = 0;
  this->text_type = '\0';
  this->text[0] = '\0';
  this->id = 0;
  this->_padding_ = (int)&_vftable_;
  lVar1 = TPanel::setup((TPanel *)this,param_1,param_2,0,0,0,0,'\0');
  if (lVar1 == 0) {
    this->_padding_ = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00520e00
/* public: virtual void * __thiscall TRIBE_Panel_Text_Line::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Panel_Text_Line::_scalar_deleting_destructor_(TRIBE_Panel_Text_Line *this,uint param_1)
{
  ~TRIBE_Panel_Text_Line(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Text_Line
// Address: 00520e20
/* public: virtual __thiscall TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line(void) */

void __thiscall TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line(TRIBE_Panel_Text_Line *this)
{
  int iVar1;
  char *pcVar2;
  
  this->_padding_ = (int)&TPanel::_vftable_;
  TPanel::release_mouse((TPanel *)this);
  if (this->_padding_ != 0) {
    iVar1 = TPanelSystem::inSystem(&panel_system,(TPanel *)this);
    if (iVar1 != 0) {
      pcVar2 = TPanel::panelName((TPanel *)this);
      TPanelSystem::removePanel(&panel_system,pcVar2);
    }
  }
  if ((PanelNode *)this->_padding_ != (PanelNode *)0x0) {
    if ((TPanel *)this->_padding_ != (TPanel *)0x0) {
      TPanel::remove_panel_node((TPanel *)this->_padding_,(PanelNode *)this->_padding_);
    }
    free(this->_padding_);
    this->_padding_ = 0;
  }
  this->_padding_ = 0;
  if (this->_padding_ != 0) {
    DeleteObject(this->_padding_);
    this->_padding_ = 0;
  }
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0x20))(2);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: set_info
// Address: 00520e30
/* public: void __thiscall TRIBE_Panel_Text_Line::set_info(unsigned char,char *,long) */

void __thiscall
TRIBE_Panel_Text_Line::set_info
          (TRIBE_Panel_Text_Line *this,uchar param_1,char *param_2,long param_3)
{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  
  if (param_1 == this->text_type) {
    pcVar7 = this->text;
    pbVar3 = (byte *)param_2;
    do {
      bVar2 = *pbVar3;
      bVar9 = bVar2 < (byte)*pcVar7;
      if (bVar2 != *pcVar7) {
LAB_00520e74:
        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_00520e79;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar9 = bVar2 < (byte)pcVar7[1];
      if (bVar2 != pcVar7[1]) goto LAB_00520e74;
      pbVar3 = pbVar3 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_00520e79:
    if ((iVar4 == 0) && (param_3 == this->id)) {
      return;
    }
  }
  uVar5 = 0xffffffff;
  this->text_type = param_1;
  do {
    pcVar7 = param_2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar4 = this->_padding_;
  pcVar7 = pcVar7 + -uVar5;
  pcVar8 = this->text;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  this->id = param_3;
  (**(code **)(iVar4 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 00520ed0
// [HELPER] s_tpnl_txl__draw: "tpnl_txl::draw"
/* public: virtual void __thiscall TRIBE_Panel_Text_Line::draw(void) */

void __thiscall TRIBE_Panel_Text_Line::draw(TRIBE_Panel_Text_Line *this)
{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_ESI;
  char *pcVar5;
  int iVar6;
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
    }
    iVar6 = this->_padding_;
    (**(code **)(iVar6 + 0x28))(0);
    pvVar2 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_txl__draw);
    if (pvVar2 != (void *)0x0) {
      uVar3 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
      SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
      SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0);
      if (this->text[0] != '\0') {
        uVar4 = 0xffffffff;
        pcVar5 = this->text;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_,this->_padding_,this->text,
                 ~uVar4 - 1);
        iVar6 = unaff_ESI;
      }
      SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar3);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_txl__draw);
    }
    (**(code **)(iVar6 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

