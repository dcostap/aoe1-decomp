// Class: TRIBE_Panel_Inven
// Size:  0x118
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
// [56] `scalar_deleting_destructor'
// [57] setup
// [58] set_rect
// [59] set_rect
// [60] set_color
// [61] set_active
// [62] set_positioning
// [63] set_fixed_position
// [64] set_redraw
// [65] set_overlapped_redraw
// [66] draw_setup
// [67] draw_finish
// [68] draw
// [69] draw_rect
// [70] draw_offset
// [71] draw_rect2
// [72] draw_offset2
// [73] paint
// [74] wnd_proc
// [75] handle_idle
// [76] handle_size
// [77] handle_paint
// [78] handle_key_down
// [79] handle_char
// [80] handle_command
// [81] handle_user_command
// [82] handle_timer_command
// [83] handle_scroll
// [84] handle_mouse_down
// [85] handle_mouse_move
// [86] handle_mouse_up
// [87] handle_mouse_dbl_click
// [88] mouse_move_action
// [89] mouse_left_down_action
// [90] mouse_left_hold_action
// [91] mouse_left_move_action
// [92] mouse_left_up_action
// [93] mouse_left_dbl_click_action
// [94] mouse_right_down_action
// [95] mouse_right_hold_action
// [96] mouse_right_move_action
// [97] mouse_right_up_action
// [98] mouse_right_dbl_click_action
// [99] key_down_action
// [100] char_action
// [101] action
// [102] get_true_render_rect
// [103] is_inside
// [104] set_focus
// [105] set_tab_order
// [106] set_tab_order
// [107] get_help_info
// [108] stop_sound_system
// [109] restart_sound_system
// [110] take_snapshot
// [111] handle_reactivate
// [112] draw_item
//
// Member Layout:
// [0x0F4] TShape * pics
// [0x0F8] TRIBE_Player * player
// [0x0FC] short save_attr_num
// [0x100] short * save_attr
// [0x104] ulong idle_time
// [0x108] ulong idle_interval
// [0x10C] void * font
// [0x110] ulong font_color
// [0x114] ulong back_color
// ----------------------------------------------------------------

// Function: TRIBE_Panel_Inven
// Address: 0051a5c0
TRIBE_Panel_Inven * __thiscall
TRIBE_Panel_Inven::TRIBE_Panel_Inven
          (TRIBE_Panel_Inven *this,TDrawArea *param_1,TPanel *param_2,void *param_3,
          TRIBE_Player *param_4)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561318;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->font = param_3;
  local_4 = 0;
  this->save_attr_num = 0;
  this->save_attr = (short *)0x0;
  this->pics = (TShape *)0x0;
  this->idle_time = 0;
  this->player = (TRIBE_Player *)0x0;
  this->back_color = 0;
  this->_padding_ = (int)&_vftable_;
  this->idle_interval = 500;
  this->font_color = 0xffffff;
  lVar1 = TPanel::setup((TPanel *)this,param_1,param_2,0,0,0,0,'\0');
  if (lVar1 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  set_player(this,param_4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0051a690
void * __thiscall
TRIBE_Panel_Inven::_scalar_deleting_destructor_(TRIBE_Panel_Inven *this,uint param_1)
{
  ~TRIBE_Panel_Inven(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: set_text_color
// Address: 0051a6b0
void __thiscall
TRIBE_Panel_Inven::set_text_color(TRIBE_Panel_Inven *this,ulong param_1,ulong param_2)
{
  this->font_color = param_1;
  this->back_color = param_2;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Inven
// Address: 0051a6d0
void __thiscall TRIBE_Panel_Inven::~TRIBE_Panel_Inven(TRIBE_Panel_Inven *this)
{
  TShape *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561338;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->save_attr != (short *)0x0) {
    free(this->save_attr);
    this->save_attr = (short *)0x0;
  }
  this_00 = this->pics;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    this->pics = (TShape *)0x0;
  }
  TPanel::~TPanel((TPanel *)this);
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0051a770
// [HELPER] s__ld: "%ld"
// [HELPER] s_tpnl_inv__draw: "tpnl_inv::draw"
void __thiscall TRIBE_Panel_Inven::draw(TRIBE_Panel_Inven *this)
{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  long x;
  void *old_font;
  int iStack_1c;
  char str [20];
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
    }
    if (this->player != (TRIBE_Player *)0x0) {
      iVar9 = this->_padding_;
      str._0_4_ = iVar9;
      (**(code **)(iVar9 + 0x28))(0);
      pvVar3 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_inv__draw);
      if (pvVar3 != (void *)0x0) {
        uVar4 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
        SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
        iVar2 = this->_padding_;
        iVar9 = this->_padding_;
        iVar7 = iVar9 + 2;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        iVar9 = iVar9 + 3;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0x1f,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0x20,iVar7,str,~uVar6 - 1);
        iVar2 = this->_padding_;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0x62,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 99,iVar7,str,~uVar6 - 1);
        iVar2 = this->_padding_;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xa5,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xa6,iVar7,str,~uVar6 - 1);
        iVar2 = this->_padding_;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xe8,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xe9,iVar7,str,~uVar6 - 1);
        SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar4);
        TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_inv__draw);
        iVar9 = iStack_1c;
      }
      (**(code **)(iVar9 + 0x2c))();
      return;
    }
  }
  this->_padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0051aad0
// [HELPER] s_C__msdev_work_age1_x1_tpnl_inv_c: "C:\msdev\work\age1_x1\tpnl_inv.cpp"
long __thiscall TRIBE_Panel_Inven::handle_idle(TRIBE_Panel_Inven *this)
{
  int iVar1;
  short *psVar2;
  bool bVar3;
  short sVar4;
  ulong uVar5;
  short sVar6;
  int changed;
  
  TPanel::handle_idle((TPanel *)this);
  iVar1 = rge_base_game->prog_mode;
  if (((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) &&
     (uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_inv_c,0xad),
     this->idle_interval <= uVar5 - this->idle_time)) {
    color_log(0xba,0xba,5);
    sVar6 = 0;
    bVar3 = false;
    if (0 < this->save_attr_num) {
      psVar2 = this->save_attr;
      do {
        sVar4 = __ftol();
        if (sVar4 != psVar2[sVar6]) {
          bVar3 = true;
          break;
        }
        sVar6 = sVar6 + 1;
      } while (sVar6 < this->save_attr_num);
    }
    if (bVar3) {
      color_log(0xba,'\x16',5);
      save_info(this);
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_inv_c,0xc2);
    this->idle_time = uVar5;
    color_log(0xba,'_',5);
  }
  return 0;
}

// --------------------------------------------------

// Function: set_player
// Address: 0051abf0
void __thiscall TRIBE_Panel_Inven::set_player(TRIBE_Panel_Inven *this,TRIBE_Player *param_1)
{
  this->player = param_1;
  save_info(this);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: save_info
// Address: 0051ac10
void __thiscall TRIBE_Panel_Inven::save_info(TRIBE_Panel_Inven *this)
{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  psVar2 = this->save_attr;
  if (psVar2 != (short *)0x0) {
    if (this->save_attr_num == (short)this->player->_padding_) goto LAB_0051ac6b;
    if (psVar2 != (short *)0x0) {
      free(psVar2);
      this->save_attr = (short *)0x0;
    }
  }
  sVar1 = (short)this->player->_padding_;
  this->save_attr_num = sVar1;
  psVar2 = (short *)calloc((int)sVar1,2);
  this->save_attr = psVar2;
LAB_0051ac6b:
  iVar3 = 0;
  if (0 < this->save_attr_num) {
    do {
      sVar1 = __ftol();
      iVar4 = iVar3 + 1;
      this->save_attr[iVar3] = sVar1;
      iVar3 = iVar4;
    } while (iVar4 < this->save_attr_num);
  }
  return;
}

// --------------------------------------------------

// Function: get_help_info
// Address: 0051aca0
uchar __thiscall
TRIBE_Panel_Inven::get_help_info
          (TRIBE_Panel_Inven *this,char **param_1,long *param_2,long param_3,long param_4)
{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *unaff_ESI;
  undefined4 *unaff_retaddr;
  
  if (this->_padding_ == 0) {
    return '\0';
  }
  iVar1 = (**(code **)(this->_padding_ + 0xbc))(param_3,param_4);
  if (iVar1 == 0) {
    return '\0';
  }
  iVar1 = this->_padding_;
  if (param_3 < iVar1 + 0x37) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string((TPanel *)this,0x1d4ee);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return '\x01';
  }
  if (param_3 < iVar1 + 0x6e) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string((TPanel *)this,0x1d4ed);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return '\x01';
  }
  if (param_3 < iVar1 + 0xa5) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string((TPanel *)this,0x1d4ef);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return '\x01';
  }
  uVar2 = __ftol();
  pcVar3 = TPanel::get_string((TPanel *)this,0x1d4f0);
  sprintf(*unaff_ESI,pcVar3,uVar2);
  *unaff_retaddr = 0xffffffff;
  return '\x01';
}

// --------------------------------------------------

