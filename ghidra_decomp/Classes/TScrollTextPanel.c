// Class: TScrollTextPanel
// Size:  0x198
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
// [56] set_text
// [57] set_text
// [58] set_text
// [59] set_bevel_info
//
// Member Layout:
// [0x188] int scroll
// [0x18C] ulong last_time
// [0x190] int speed
// [0x194] int done
// ----------------------------------------------------------------

// Function: TScrollTextPanel
// Address: 00492e70
TScrollTextPanel * __thiscall
TScrollTextPanel::TScrollTextPanel
          (TScrollTextPanel *this,TPanel *param_1,TDrawArea *param_2,long param_3,long param_4,
          long param_5,long param_6,int param_7,void *param_8,long param_9,long param_10,
          char *param_11)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055eb28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TTextPanel::TTextPanel((TTextPanel *)this);
  this->speed = param_7;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->scroll = 0;
  this->last_time = 0;
  this->done = 0;
  lVar1 = TTextPanel::setup((TTextPanel *)this,param_2,param_1,param_3,param_4,param_5,param_6,
                            param_8,param_9,param_10,(char *)0x0,0,'\0',0,'\0',0,(char *)0x0);
  if (lVar1 != 0) {
    TTextPanel::set_alignment((TTextPanel *)this,AlignTop,AlignCenter);
    TTextPanel::set_word_wrap((TTextPanel *)this,1);
    set_text(this,param_11);
    TTextPanel::set_text_color((TTextPanel *)this,this->_padding_,this->_padding_);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00492f50
void * __thiscall
TScrollTextPanel::_vector_deleting_destructor_(TScrollTextPanel *this,uint param_1)
{
  ~TScrollTextPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TScrollTextPanel
// Address: 00492f70
void __thiscall TScrollTextPanel::~TScrollTextPanel(TScrollTextPanel *this)
{
  this->_padding_ = (int)&_vftable_;
  TTextPanel::~TTextPanel((TTextPanel *)this);
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 00492f80
void __thiscall TScrollTextPanel::set_text(TScrollTextPanel *this,char *param_1)
{
  TTextPanel::set_text((TTextPanel *)this,param_1);
  this->last_time = 0;
  this->scroll = 0;
  this->done = 0;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00492fb0
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
long __thiscall TScrollTextPanel::handle_idle(TScrollTextPanel *this)
{
  ulong uVar1;
  int iVar2;
  long lVar3;
  
  if (this->last_time == 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x1dc);
    this->last_time = uVar1;
  }
  else {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x1df);
    iVar2 = __ftol();
    if (0 < iVar2) {
      this->scroll = this->scroll + iVar2;
      (**(code **)(this->_padding_ + 0x20))(1);
      this->last_time = uVar1;
    }
  }
  if ((this->done != 0) && ((int *)this->_padding_ != (int *)0x0)) {
    (**(code **)(*(int *)this->_padding_ + 0xb4))(this,1,0,0);
  }
  lVar3 = TPanel::handle_idle((TPanel *)this);
  return lVar3;
}

// --------------------------------------------------

// Function: draw
// Address: 00493070
// [HELPER] s_scr_cred__draw: "scr_cred::draw"
void __thiscall TScrollTextPanel::draw(TScrollTextPanel *this)
{
  void *pvVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  void *old_font;
  int iStack_8;
  
  this->_padding_ = 0;
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    TTextPanel::draw_background((TTextPanel *)this);
    iVar4 = this->_padding_;
    (**(code **)(iVar4 + 0x28))(0);
    pvVar1 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_scr_cred__draw);
    if (pvVar1 != (void *)0x0) {
      SelectClipRgn(pvVar1,this->_padding_);
      uVar2 = SelectObject(pvVar1,this->_padding_);
      SetBkMode(pvVar1,1);
      sVar3 = 0;
      if (0 < (short)this->_padding_) {
        do {
          draw_scrolled_line(this,pvVar1,sVar3,sVar3,this->_padding_,this->_padding_);
          sVar3 = sVar3 + 1;
        } while (sVar3 < (short)this->_padding_);
      }
      SelectObject(pvVar1,uVar2);
      SelectClipRgn(pvVar1,0);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_scr_cred__draw);
      iVar4 = iStack_8;
    }
    TTextPanel::draw_border((TTextPanel *)this);
    (**(code **)(iVar4 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: draw_scrolled_line
// Address: 00493160
void __thiscall
TScrollTextPanel::draw_scrolled_line
          (TScrollTextPanel *this,void *param_1,short param_2,short param_3,ulong param_4,
          ulong param_5)
{
  char cVar1;
  long lVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  short text_len;
  char *temp_text2;
  short text2_len;
  short local_1c;
  tagRECT line_rect;
  
  iVar6 = (int)param_3;
  temp_text2._0_2_ = 0;
  local_1c = 0;
  line_rect.left = (long)this;
  pcVar3 = TTextPanel::get_text((TTextPanel *)this,iVar6);
  pcVar4 = TTextPanel::get_text2((TTextPanel *)this,iVar6);
  if (pcVar3 == (char *)0x0) {
    if (pcVar4 == (char *)0x0) {
      return;
    }
  }
  else {
    iVar5 = -1;
    pcVar7 = pcVar3;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    temp_text2._0_2_ = ~(ushort)iVar5 - 1;
  }
  if (pcVar4 != (char *)0x0) {
    iVar5 = -1;
    pcVar7 = pcVar4;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    local_1c = ~(ushort)iVar5 - 1;
  }
  TTextPanel::calc_line_pos
            ((TTextPanel *)this,param_1,param_2,param_3,(tagRECT *)&line_rect.top,(long *)0x0);
  _param_3 = line_rect.top;
  if ((this->_padding_ != 0) && (this->_padding_ != 6)) {
    _param_3 = line_rect.top + 5;
  }
  iVar5 = this->_padding_ + _param_3;
  iVar8 = (this->_padding_ - this->scroll) + line_rect.right;
  if ((iVar6 == (short)this->_padding_ + -1) && (this->_padding_ + iVar8 < this->_padding_)) {
    this->done = 1;
  }
  if (this->_padding_ != 0) {
    SelectClipRgn(param_1,this->_padding_);
  }
  iVar6 = this->_padding_;
  if (iVar6 == 0) {
    SetTextColor(param_1,param_4);
  }
  else if (iVar6 == 1) {
    SetTextColor(param_1,param_4);
    if (pcVar3 != (char *)0x0) {
      TextOutA(param_1,_param_3 + -1,iVar8 + 1,pcVar3,(int)(short)temp_text2);
    }
    SetTextColor(param_1,param_5);
  }
  else {
    if (iVar6 != 2) goto LAB_00493317;
    SetTextColor(param_1,param_5);
    if (pcVar3 != (char *)0x0) {
      TextOutA(param_1,_param_3 + -1,iVar8 + 1,pcVar3,(int)(short)temp_text2);
    }
    SetTextColor(param_1,param_4);
  }
  if (pcVar3 != (char *)0x0) {
    TextOutA(param_1,_param_3,iVar8,pcVar3,(int)(short)temp_text2);
  }
LAB_00493317:
  lVar2 = line_rect.left;
  if (pcVar4 != (char *)0x0) {
    if (*(int *)(line_rect.left + 0x17c) != 0) {
      SelectClipRgn(param_1,*(undefined4 *)(line_rect.left + 0x88));
    }
    iVar6 = *(int *)(lVar2 + 0x11c);
    if (iVar6 == 0) {
      SetTextColor(param_1,param_4);
      TextOutA(param_1,iVar5,iVar8,pcVar4,(int)local_1c);
    }
    else {
      if (iVar6 == 1) {
        SetTextColor(param_1,param_4);
        TextOutA(param_1,iVar5 + -1,iVar8 + 1,pcVar4,(int)local_1c);
        SetTextColor(param_1,param_5);
        TextOutA(param_1,iVar5,iVar8,pcVar4,(int)local_1c);
        return;
      }
      if (iVar6 == 2) {
        SetTextColor(param_1,param_5);
        TextOutA(param_1,iVar5 + -1,iVar8 + 1,pcVar4,(int)local_1c);
        SetTextColor(param_1,param_4);
        TextOutA(param_1,iVar5,iVar8,pcVar4,(int)local_1c);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

