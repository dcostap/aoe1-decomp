// Class: TInputPanel
// Size:  0x1B8
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
// [56] set_text
// [57] set_text
// [58] set_text
// [59] set_bevel_info
// [60] `vector_deleting_destructor'
// [61] setup
// [62] set_rect
// [63] set_rect
// [64] set_color
// [65] set_active
// [66] set_positioning
// [67] set_fixed_position
// [68] set_redraw
// [69] set_overlapped_redraw
// [70] draw_setup
// [71] draw_finish
// [72] draw
// [73] draw_rect
// [74] draw_offset
// [75] draw_rect2
// [76] draw_offset2
// [77] paint
// [78] wnd_proc
// [79] handle_idle
// [80] handle_size
// [81] handle_paint
// [82] handle_key_down
// [83] handle_char
// [84] handle_command
// [85] handle_user_command
// [86] handle_timer_command
// [87] handle_scroll
// [88] handle_mouse_down
// [89] handle_mouse_move
// [90] handle_mouse_up
// [91] handle_mouse_dbl_click
// [92] mouse_move_action
// [93] mouse_left_down_action
// [94] mouse_left_hold_action
// [95] mouse_left_move_action
// [96] mouse_left_up_action
// [97] mouse_left_dbl_click_action
// [98] mouse_right_down_action
// [99] mouse_right_hold_action
// [100] mouse_right_move_action
// [101] mouse_right_up_action
// [102] mouse_right_dbl_click_action
// [103] key_down_action
// [104] char_action
// [105] action
// [106] get_true_render_rect
// [107] is_inside
// [108] set_focus
// [109] set_tab_order
// [110] set_tab_order
// [111] get_help_info
// [112] stop_sound_system
// [113] restart_sound_system
// [114] take_snapshot
// [115] handle_reactivate
// [116] set_text
// [117] set_text
// [118] set_text
// [119] set_bevel_info
// [120] `scalar_deleting_destructor'
// [121] setup
// [122] set_rect
// [123] set_rect
// [124] set_color
// [125] set_active
// [126] set_positioning
// [127] set_fixed_position
// [128] set_redraw
// [129] set_overlapped_redraw
// [130] draw_setup
// [131] draw_finish
// [132] draw
// [133] draw_rect
// [134] draw_offset
// [135] draw_rect2
// [136] draw_offset2
// [137] paint
// [138] wnd_proc
// [139] handle_idle
// [140] handle_size
// [141] handle_paint
// [142] handle_key_down
// [143] handle_char
// [144] handle_command
// [145] handle_user_command
// [146] handle_timer_command
// [147] handle_scroll
// [148] handle_mouse_down
// [149] handle_mouse_move
// [150] handle_mouse_up
// [151] handle_mouse_dbl_click
// [152] mouse_move_action
// [153] mouse_left_down_action
// [154] mouse_left_hold_action
// [155] mouse_left_move_action
// [156] mouse_left_up_action
// [157] mouse_left_dbl_click_action
// [158] mouse_right_down_action
// [159] mouse_right_hold_action
// [160] mouse_right_move_action
// [161] mouse_right_up_action
// [162] mouse_right_dbl_click_action
// [163] key_down_action
// [164] char_action
// [165] action
// [166] get_true_render_rect
// [167] is_inside
// [168] set_focus
// [169] set_tab_order
// [170] set_tab_order
// [171] get_help_info
// [172] stop_sound_system
// [173] restart_sound_system
// [174] take_snapshot
// [175] handle_reactivate
// [176] set_font
//
// Member Layout:
// [0x188] uchar caret_color
// [0x18C] ulong caret_interval
// [0x190] ulong caret_last_time
// [0x194] int draw_caret
// [0x198] TDigital * overLengthSound
// [0x19C] FormatType format_type
// [0x1A0] char * input_buffer
// [0x1A4] char * input_buffer1
// [0x1A8] char * input_buffer2
// [0x1AC] short input_len
// [0x1AE] short max_len
// [0x1B0] int insert_mode
// [0x1B4] short input_pos
// ----------------------------------------------------------------

// Function: TInputPanel
// Address: 00476c10
TInputPanel * __thiscall TInputPanel::TInputPanel(TInputPanel *this)
{
  ulong uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e488;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TTextPanel::TTextPanel((TTextPanel *)this);
  local_4 = 0;
  this->caret_color = '\0';
  uVar1 = GetCaretBlinkTime();
  this->caret_interval = uVar1;
  this->caret_last_time = 0;
  this->draw_caret = 1;
  this->insert_mode = 1;
  this->_padding_ = 1;
  this->_padding_ = 1;
  this->overLengthSound = (TDigital *)0x0;
  this->input_buffer = (char *)0x0;
  this->input_buffer1 = (char *)0x0;
  this->input_buffer2 = (char *)0x0;
  this->input_len = 0;
  this->max_len = 0;
  this->input_pos = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)((int)&this->_padding_ + 2) = 7;
  this->_padding_ = 5;
  *unaff_FS_OFFSET = uStack_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00476cd0
void * __thiscall TInputPanel::_scalar_deleting_destructor_(TInputPanel *this,uint param_1)
{
  ~TInputPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TInputPanel
// Address: 00476cf0
void __thiscall TInputPanel::~TInputPanel(TInputPanel *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055e4a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->input_buffer1 != (char *)0x0) {
    operator_delete(this->input_buffer1);
    this->input_buffer1 = (char *)0x0;
  }
  if (this->input_buffer2 != (char *)0x0) {
    operator_delete(this->input_buffer2);
    this->input_buffer2 = (char *)0x0;
  }
  this->input_buffer = (char *)0x0;
  this->_padding_ = 1;
  local_4 = 0xffffffff;
  TTextPanel::~TTextPanel((TTextPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 00476d80
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
long __thiscall
TInputPanel::setup(TInputPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
                  long param_5,long param_6,void *param_7,long param_8,long param_9,char *param_10,
                  int param_11,uchar param_12,int param_13,uchar param_14,uchar param_15,
                  short param_16,TDigital *param_17,char *param_18,FormatType param_19)
{
  int iVar1;
  short sVar2;
  long lVar3;
  ulong uVar4;
  char *pcVar5;
  
  sVar2 = param_16;
  if (param_19 == FormatMultiLine) {
    sVar2 = 0;
  }
  lVar3 = TTextPanel::setup((TTextPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,
                            param_7,param_8,param_9,param_10,param_11,param_12,param_13,param_14,
                            sVar2,(char *)0x0);
  if (lVar3 == 0) {
    return 0;
  }
  this->caret_color = param_15;
  this->format_type = param_19;
  if (this->_padding_ != 0) {
    this->draw_caret = 1;
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x59);
    this->caret_last_time = uVar4;
  }
  if (param_16 == 0) {
    this->overLengthSound = (TDigital *)0x0;
  }
  else {
    this->overLengthSound = param_17;
  }
  if (this->format_type == FormatMultiLine) {
    TTextPanel::set_alignment((TTextPanel *)this,AlignTop,AlignLeft);
    TTextPanel::set_word_wrap((TTextPanel *)this,1);
  }
  else {
    TTextPanel::set_alignment((TTextPanel *)this,AlignCenter,AlignHorizontalScroll);
  }
  iVar1 = param_16 * 2 + 1;
  pcVar5 = (char *)calloc(iVar1,1);
  this->input_buffer1 = pcVar5;
  if (pcVar5 != (char *)0x0) {
    pcVar5 = (char *)calloc(iVar1,1);
    this->input_buffer2 = pcVar5;
    if (pcVar5 != (char *)0x0) {
      this->input_buffer = this->input_buffer1;
      (**(code **)(this->_padding_ + 0xe8))(param_18);
      this->max_len = param_16;
      reformat(this);
      return 1;
    }
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: set_focus
// Address: 00476ee0
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
void __thiscall TInputPanel::set_focus(TInputPanel *this,int param_1)
{
  ulong uVar1;
  
  TPanel::set_focus((TPanel *)this,param_1);
  if (this->_padding_ != 0) {
    this->draw_caret = 1;
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x89);
    this->caret_last_time = uVar1;
  }
  return;
}

// --------------------------------------------------

// Function: set_format
// Address: 00476f20
void __thiscall TInputPanel::set_format(TInputPanel *this,FormatType param_1)
{
  this->format_type = param_1;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00476f30
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
long __thiscall TInputPanel::handle_idle(TInputPanel *this)
{
  ulong uVar1;
  long lVar2;
  
  if (this->_padding_ != 0) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x9e);
    if (this->caret_interval <= uVar1 - this->caret_last_time) {
      this->draw_caret = (uint)(this->draw_caret == 0);
      (**(code **)(this->_padding_ + 0x20))(1);
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0xa3);
      this->caret_last_time = uVar1;
    }
  }
  lVar2 = TPanel::handle_idle((TPanel *)this);
  return lVar2;
}

// --------------------------------------------------

// Function: char_action
// Address: 00476fa0
// [HELPER] s_10: "10"
long __thiscall TInputPanel::char_action(TInputPanel *this,long param_1,short param_2)
{
  FormatType FVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  
  if ((((param_1 != 8) && (param_1 != 9)) && (param_1 != 10)) &&
     (((param_1 != 0xd && (param_1 != 0x1b)) && (0x1a < param_1)))) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    sVar5 = 0;
    if (0 < param_2) {
      do {
        FVar1 = this->format_type;
        switch(FVar1) {
        case FormatNumber:
        case FormatInteger:
        case FormatUnsignedInt:
          if ((((param_1 < 0x30) || (0x39 < param_1)) &&
              (((param_1 != 0x2d || (*this->input_buffer != '\0')) || (FVar1 == FormatUnsignedInt)))
              ) && (((param_1 != 0x2e || (iVar4 = __mbschr(this->input_buffer,0x2e), iVar4 == 0)) ||
                    (this->format_type != FormatNumber)))) goto LAB_004771ae;
          break;
        case FormatFile:
        case FormatFileNoExt:
          if (param_1 == 0x2e) {
            if ((FVar1 != FormatFile) || (iVar4 = __mbschr(this->input_buffer,0x2e), iVar4 != 0))
            goto LAB_004771ae;
          }
          else if (((param_1 == 0x5c) ||
                   (((param_1 == 0x3a || (param_1 == 0x2f)) || (param_1 == 0x22)))) ||
                  (((param_1 == 0x2a || (param_1 == 0x3f)) ||
                   ((param_1 == 0x3e || ((param_1 == 0x3c || (param_1 == 0x7c)))))))) {
LAB_004771ae:
            if (this->overLengthSound != (TDigital *)0x0) {
              TDigital::play(this->overLengthSound);
              return 1;
            }
LAB_004771e4:
            MessageBeep(0xffffffff);
            return 1;
          }
          break;
        case FormatPath:
          if ((((((param_1 == 0x3a) && (this->input_len != 1)) || (param_1 == 0x2f)) ||
               ((param_1 == 0x22 || (param_1 == 0x2a)))) || (param_1 == 0x3f)) ||
             (((param_1 == 0x3e || (param_1 == 0x3c)) || (param_1 == 0x7c)))) {
            if (this->overLengthSound != (TDigital *)0x0) {
              TDigital::play(this->overLengthSound);
              return 1;
            }
            goto LAB_004771e4;
          }
          break;
        case FormatPercent:
          pcVar2 = TTextPanel::get_text((TTextPanel *)this);
          uVar3 = __mbslen(pcVar2);
          if (((1 < uVar3) || (param_1 < 0x30)) || (0x39 < param_1)) {
            pcVar2 = TTextPanel::get_text((TTextPanel *)this);
            iVar4 = __mbslen(pcVar2);
            if ((iVar4 == 2) && (param_1 == 0x30)) {
              pcVar2 = TTextPanel::get_text((TTextPanel *)this);
              iVar4 = __mbscmp(s_10,pcVar2);
              if (iVar4 == 0) break;
            }
            if (this->overLengthSound != (TDigital *)0x0) {
              TDigital::play(this->overLengthSound);
              return 1;
            }
            goto LAB_004771e4;
          }
        }
        iVar4 = insert_character(this,param_1);
        if (iVar4 == 0) {
          return 1;
        }
        sVar5 = sVar5 + 1;
        if (param_2 <= sVar5) {
          return 1;
        }
      } while( true );
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 00477220
long __thiscall
TInputPanel::key_down_action
          (TInputPanel *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  short sVar1;
  undefined2 uVar2;
  short sVar3;
  char *pcVar4;
  int iVar5;
  
  switch(param_1) {
  case 8:
    backspace_character(this);
    return 1;
  default:
    return 0;
  case 0xd:
    if (this->format_type == FormatMultiLine) {
      insert_character(this,10);
      return 1;
    }
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(this,0,0,0);
      return 1;
    }
    break;
  case 0x1b:
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(this,1,0,0);
      return 1;
    }
    break;
  case 0x21:
    if ((short)this->_padding_ < 1) {
      return 1;
    }
    sVar1 = (short)this->_padding_;
    if (sVar1 < 1) {
      return 1;
    }
    sVar3 = (short)this->_padding_;
    if ((sVar1 < sVar3) || (*(short *)((int)&this->_padding_ + 2) < sVar1)) {
      *(short *)&this->_padding_ = sVar3;
    }
    if ((short)this->_padding_ == sVar3) {
      TTextPanel::scroll((TTextPanel *)this,'\x05',0,1);
      sVar3 = (short)this->_padding_;
    }
    goto LAB_004775f9;
  case 0x22:
    sVar3 = (short)this->_padding_;
    if (sVar3 < 1) {
      return 1;
    }
    sVar1 = (short)this->_padding_;
    if (sVar3 + -1 <= (int)sVar1) {
      return 1;
    }
    if ((sVar1 < (short)this->_padding_) ||
       (sVar3 = *(short *)((int)&this->_padding_ + 2), sVar3 < sVar1)) {
      sVar3 = *(short *)((int)&this->_padding_ + 2);
      *(short *)&this->_padding_ = sVar3;
    }
    if ((short)this->_padding_ == sVar3) {
      TTextPanel::scroll((TTextPanel *)this,'\x04',0,1);
      sVar3 = *(short *)((int)&this->_padding_ + 2);
    }
LAB_004775f9:
    *(short *)&this->_padding_ = sVar3;
    pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)sVar3);
    sVar3 = __mbslen(pcVar4);
    if (sVar3 < *(short *)((int)&this->_padding_ + 2)) {
LAB_0047761d:
      sVar3 = (short)this->_padding_;
LAB_00477625:
      pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)sVar3);
      sVar3 = __mbslen(pcVar4);
LAB_00477635:
      *(short *)((int)&this->_padding_ + 2) = sVar3;
    }
LAB_0047763c:
    calc_input_pos(this);
    (**(code **)(this->_padding_ + 0x20))(1);
    return 1;
  case 0x23:
    sVar3 = (short)this->_padding_;
    if (sVar3 < 1) {
      return 1;
    }
    if (param_4 == 0) {
      pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)(short)this->_padding_);
      sVar3 = __mbslen(pcVar4);
      if (*(short *)((int)&this->_padding_ + 2) == sVar3) {
        return 1;
      }
      sVar3 = (short)this->_padding_;
    }
    else {
      iVar5 = (int)(short)this->_padding_;
      if (iVar5 == sVar3 + -1) {
        pcVar4 = TTextPanel::get_text((TTextPanel *)this,iVar5);
        sVar3 = __mbslen(pcVar4);
        if (*(short *)((int)&this->_padding_ + 2) == sVar3) {
          return 1;
        }
      }
      sVar3 = (short)this->_padding_ + -1;
      *(short *)&this->_padding_ = sVar3;
    }
    pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)sVar3);
    uVar2 = __mbslen(pcVar4);
    *(undefined2 *)((int)&this->_padding_ + 2) = uVar2;
LAB_0047750f:
    (**(code **)(this->_padding_ + 0x20))(1);
    calc_input_pos(this);
    return 1;
  case 0x24:
    if ((short)this->_padding_ < 1) {
      return 1;
    }
    if (param_4 == 0) {
      if (*(short *)((int)&this->_padding_ + 2) != 0) {
        *(undefined2 *)((int)&this->_padding_ + 2) = 0;
        goto LAB_0047750f;
      }
    }
    else if ((*(short *)((int)&this->_padding_ + 2) != 0) || ((short)this->_padding_ != 0)) {
      *(undefined2 *)((int)&this->_padding_ + 2) = 0;
      *(undefined2 *)&this->_padding_ = 0;
      calc_input_pos(this);
      (**(code **)(this->_padding_ + 0x20))(1);
      return 1;
    }
    break;
  case 0x25:
    if ((short)this->_padding_ < 1) {
      return 1;
    }
    sVar3 = *(short *)((int)&this->_padding_ + 2);
    if (sVar3 < 1) {
      sVar3 = (short)this->_padding_;
      if (sVar3 < 1) {
        return 1;
      }
      sVar3 = sVar3 + -1;
      *(short *)&this->_padding_ = sVar3;
      goto LAB_00477625;
    }
    sVar3 = sVar3 + -1;
    goto LAB_00477635;
  case 0x26:
    if ((short)this->_padding_ < 1) {
      return 1;
    }
    sVar3 = (short)this->_padding_;
    if (0 < sVar3) {
      sVar3 = sVar3 + -1;
      *(short *)&this->_padding_ = sVar3;
      pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)sVar3);
      sVar3 = __mbslen(pcVar4);
      if (sVar3 < *(short *)((int)&this->_padding_ + 2)) {
        pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)(short)this->_padding_);
        uVar2 = __mbslen(pcVar4);
        *(undefined2 *)((int)&this->_padding_ + 2) = uVar2;
      }
LAB_00477379:
      calc_input_pos(this);
      (**(code **)(this->_padding_ + 0x20))(1);
      return 1;
    }
    break;
  case 0x27:
    if ((short)this->_padding_ < 1) {
      return 1;
    }
    sVar3 = *(short *)((int)&this->_padding_ + 2);
    pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)(short)this->_padding_);
    sVar1 = __mbslen(pcVar4);
    if (sVar3 < sVar1) {
      *(short *)((int)&this->_padding_ + 2) = sVar3 + 1;
      calc_input_pos(this);
      (**(code **)(this->_padding_ + 0x20))(1);
      return 1;
    }
    sVar3 = (short)this->_padding_;
    if ((int)sVar3 < (short)this->_padding_ + -1) {
      *(undefined2 *)((int)&this->_padding_ + 2) = 0;
      *(short *)&this->_padding_ = sVar3 + 1;
      goto LAB_00477379;
    }
    break;
  case 0x28:
    sVar3 = (short)this->_padding_;
    if (sVar3 < 1) {
      return 1;
    }
    sVar1 = (short)this->_padding_;
    if (sVar3 + -1 <= (int)sVar1) {
      return 1;
    }
    sVar1 = sVar1 + 1;
    *(short *)&this->_padding_ = sVar1;
    pcVar4 = TTextPanel::get_text((TTextPanel *)this,(int)sVar1);
    sVar3 = __mbslen(pcVar4);
    if (*(short *)((int)&this->_padding_ + 2) <= sVar3) goto LAB_0047763c;
    goto LAB_0047761d;
  case 0x2d:
    if (param_5 == 0) {
      if (param_4 != 0) {
        return 1;
      }
      this->insert_mode = (uint)(this->insert_mode == 0);
      return 1;
    }
    goto LAB_00477711;
  case 0x2e:
    delete_character(this);
    return 1;
  case 0x56:
    if (param_4 == 0) {
      return 0;
    }
LAB_00477711:
    paste(this);
  }
  return 1;
}

// --------------------------------------------------

// Function: draw
// Address: 004777c0
// [HELPER] s_pnl_inp__draw: "pnl_inp::draw"
void __thiscall TInputPanel::draw(TInputPanel *this)
{
  int iVar1;
  short sVar2;
  void *pvVar3;
  undefined4 uVar4;
  uchar *puVar5;
  long unaff_ESI;
  int iVar6;
  long cursor_x_offset;
  int iStack_18;
  tagRECT line_rect;
  
  cursor_x_offset = unaff_ESI;
  TTextPanel::draw((TTextPanel *)this);
  if ((((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) &&
     (((this->_padding_ != 0 && (this->draw_caret != 0)) &&
      ((sVar2 = (short)this->_padding_, (short)this->_padding_ <= sVar2 &&
       (sVar2 <= *(short *)((int)&this->_padding_ + 2))))))) {
    line_rect.left = this->_padding_;
    (**(code **)(line_rect.left + 0x28))(0);
    pvVar3 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_pnl_inp__draw);
    if (pvVar3 != (void *)0x0) {
      uVar4 = SelectObject(pvVar3,this->_padding_);
      sVar2 = (short)this->_padding_;
      TTextPanel::calc_line_pos
                ((TTextPanel *)this,pvVar3,sVar2 - (short)this->_padding_,sVar2,&line_rect,
                 &cursor_x_offset);
      SelectObject(pvVar3,uVar4);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_pnl_inp__draw);
      puVar5 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_pnl_inp__draw,1);
      if (puVar5 != (uchar *)0x0) {
        iVar1 = cursor_x_offset + line_rect.left;
        iVar6 = (line_rect.bottom - line_rect.top) + 1;
        if (iVar1 < this->_padding_) {
          TDrawArea::DrawVertLine
                    ((TDrawArea *)this->_padding_,iVar1,line_rect.top,iVar6,this->caret_color);
          TDrawArea::DrawVertLine
                    ((TDrawArea *)this->_padding_,iVar1 + 1,line_rect.top,iVar6,this->caret_color);
        }
        TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_inp__draw);
      }
    }
    (**(code **)(iStack_18 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 00477910
void __thiscall TInputPanel::set_text(TInputPanel *this,char *param_1)
{
  char *pcVar1;
  FormatType FVar2;
  short sVar3;
  
  pcVar1 = this->input_buffer;
  if (pcVar1 != (char *)0x0) {
    if (param_1 == (char *)0x0) {
      *pcVar1 = '\0';
    }
    else {
      __mbscpy(pcVar1,param_1);
    }
    sVar3 = __mbslen(this->input_buffer);
    FVar2 = this->format_type;
    this->input_len = sVar3;
    this->input_pos = 0;
    *(undefined2 *)&this->_padding_ = 0;
    *(undefined2 *)((int)&this->_padding_ + 2) = 0;
    if ((FVar2 != FormatMultiLine) && (0 < sVar3)) {
      this->input_pos = sVar3;
      *(short *)((int)&this->_padding_ + 2) = sVar3;
    }
    reformat(this);
  }
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 00477990
void __thiscall TInputPanel::set_text(TInputPanel *this,char **param_1,short param_2)
{
  return;
}

// --------------------------------------------------

// Function: get_input_buffer
// Address: 004779a0
char * __thiscall TInputPanel::get_input_buffer(TInputPanel *this)
{
  return this->input_buffer;
}

// --------------------------------------------------

// Function: append_character
// Address: 004779b0
int __thiscall TInputPanel::append_character(TInputPanel *this,long param_1)
{
  int iVar1;
  
  this->input_pos = this->input_len;
  iVar1 = insert_character(this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: insert_character
// Address: 004779d0
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
int __thiscall TInputPanel::insert_character(TInputPanel *this,long param_1)
{
  char *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  ulong uVar4;
  
  if (this->input_len < this->max_len) {
    pcVar2 = this->input_buffer1;
    if (this->input_buffer == pcVar2) {
      pcVar1 = pcVar2;
      pcVar2 = this->input_buffer2;
    }
    else {
      pcVar1 = this->input_buffer2;
    }
    this->input_buffer = pcVar2;
    *pcVar2 = '\0';
    if (0 < this->input_pos) {
      __mbsncpy(pcVar2,pcVar1,(int)this->input_pos);
      pcVar1 = (char *)__mbsninc(pcVar1,(int)this->input_pos);
      pcVar2 = (char *)__mbsninc(pcVar2,(int)this->input_pos);
    }
    __mbsncpy(pcVar2,&param_1,1);
    uVar3 = __mbsinc(pcVar2);
    __mbsncpy(uVar3,pcVar1,((int)this->input_len - (int)this->input_pos) + 1);
    this->input_len = this->input_len + 1;
    this->input_pos = this->input_pos + 1;
    reformat(this);
    calc_cur_line_col(this);
    this->draw_caret = 1;
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x28f);
    this->caret_last_time = uVar4;
    return 1;
  }
  if (this->overLengthSound != (TDigital *)0x0) {
    TDigital::play(this->overLengthSound);
    return 0;
  }
  MessageBeep(0xffffffff);
  return 0;
}

// --------------------------------------------------

// Function: delete_character
// Address: 00477af0
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
int __thiscall TInputPanel::delete_character(TInputPanel *this)
{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  ulong uVar5;
  short sVar6;
  uchar *cur_dest;
  int move_back_one;
  
  if (this->input_len <= this->input_pos) {
    return 0;
  }
  pcVar3 = this->input_buffer1;
  bVar1 = false;
  if (this->input_buffer == pcVar3) {
    pcVar4 = pcVar3;
    pcVar3 = this->input_buffer2;
  }
  else {
    pcVar4 = this->input_buffer2;
  }
  this->input_buffer = pcVar3;
  *pcVar3 = '\0';
  pcVar2 = pcVar4;
  move_back_one = (int)pcVar3;
  if (0 < this->input_pos) {
    __mbsncpy(pcVar3,pcVar4,(int)this->input_pos);
    pcVar2 = (char *)__mbsninc(pcVar4,(int)this->input_pos);
    move_back_one = __mbsninc(pcVar3,(int)this->input_pos);
  }
  if (*pcVar2 == '\r') {
    pcVar3 = (char *)__mbsinc(pcVar2);
    sVar6 = 1;
    if (*pcVar3 == '\n') {
      pcVar3 = (char *)__mbsinc(pcVar3);
      sVar6 = 2;
    }
  }
  else {
    if ((*pcVar2 == '\n') && (pcVar4 < pcVar2)) {
      pcVar4 = (char *)__mbsdec(pcVar4,pcVar2);
      if (*pcVar4 == '\r') {
        move_back_one = __mbsdec(pcVar3,move_back_one);
        pcVar3 = (char *)__mbsninc(pcVar4,2);
        sVar6 = 2;
        bVar1 = true;
        goto LAB_00477c15;
      }
      pcVar3 = (char *)__mbsninc(pcVar4,2);
    }
    else {
      pcVar3 = (char *)__mbsinc(pcVar2);
    }
    sVar6 = 1;
  }
LAB_00477c15:
  __mbsncpy(move_back_one,pcVar3,((int)this->input_len - (int)this->input_pos) + 1);
  if (bVar1) {
    this->input_pos = this->input_pos + -1;
  }
  this->input_len = this->input_len - sVar6;
  reformat(this);
  calc_cur_line_col(this);
  this->draw_caret = 1;
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x2f6);
  this->caret_last_time = uVar5;
  return 1;
}

// --------------------------------------------------

// Function: backspace_character
// Address: 00477c90
int __thiscall TInputPanel::backspace_character(TInputPanel *this)
{
  int iVar1;
  
  if (0 < this->input_pos) {
    this->input_pos = this->input_pos + -1;
    iVar1 = delete_character(this);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: paste
// Address: 00477cb0
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
int __thiscall TInputPanel::paste(TInputPanel *this)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  void *data_handle;
  char new_str [4096];
  
  iVar6 = 0;
  new_str[4] = '\0';
  iVar1 = IsClipboardFormatAvailable(1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = OpenClipboard(*(undefined4 *)(this->_padding_ + 4));
  if (iVar1 == 0) {
    return 0;
  }
  new_str._0_4_ = GetClipboardData(1);
  if (new_str._0_4_ != 0) {
    iVar1 = GlobalLock(new_str._0_4_);
    if (iVar1 != 0) {
      iVar6 = __mbslen(iVar1);
      if (0xfff < iVar6) {
        iVar6 = 0xfff;
      }
      pcVar8 = new_str;
      for (iVar5 = 0x400; pcVar8 = pcVar8 + 4, iVar5 != 0; iVar5 = iVar5 + -1) {
        pcVar8[0] = '\0';
        pcVar8[1] = '\0';
        pcVar8[2] = '\0';
        pcVar8[3] = '\0';
      }
      __mbsncpy(new_str + 4,iVar1,iVar6);
      GlobalUnlock(new_str._0_4_);
    }
  }
  CloseClipboard();
  if ((int)this->max_len <= iVar6 + this->input_len) {
    if (this->overLengthSound != (TDigital *)0x0) {
      TDigital::play(this->overLengthSound);
      return 0;
    }
    MessageBeep(0xffffffff);
    return 0;
  }
  pcVar8 = this->input_buffer1;
  if (this->input_buffer == pcVar8) {
    pcVar7 = pcVar8;
    pcVar8 = this->input_buffer2;
  }
  else {
    pcVar7 = this->input_buffer2;
  }
  this->input_buffer = pcVar8;
  *pcVar8 = '\0';
  __mbsncpy(pcVar8,pcVar7,(int)this->input_pos);
  uVar2 = __mbsninc(pcVar7,(int)this->input_pos);
  uVar3 = __mbsninc(pcVar8,(int)this->input_pos);
  __mbsncpy(uVar3,new_str + 4,iVar6);
  uVar3 = __mbsninc(uVar3,iVar6);
  __mbsncpy(uVar3,uVar2,((int)this->input_len - (int)this->input_pos) + 1);
  this->input_len = this->input_len + (short)iVar6;
  this->input_pos = this->input_pos + (short)iVar6;
  reformat(this);
  calc_cur_line_col(this);
  this->draw_caret = 1;
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x362);
  this->caret_last_time = uVar4;
  return 1;
}

// --------------------------------------------------

// Function: reformat
// Address: 00477e90
void __thiscall TInputPanel::reformat(TInputPanel *this)
{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = (short)this->_padding_;
  sVar3 = (short)this->_padding_;
  TTextPanel::set_text((TTextPanel *)this,this->input_buffer);
  sVar2 = (short)this->_padding_;
  if (sVar2 <= sVar3) {
    sVar3 = sVar2 + -1;
  }
  *(short *)&this->_padding_ = sVar3;
  if (sVar2 <= sVar1) {
    *(short *)&this->_padding_ = sVar2 + -1;
  }
  TTextPanel::scroll((TTextPanel *)this,'\x01',sVar1,1);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: calc_input_pos
// Address: 00477ef0
void __thiscall TInputPanel::calc_input_pos(TInputPanel *this)
{
  undefined4 *puVar1;
  short sVar2;
  short sVar3;
  
  puVar1 = (undefined4 *)this->_padding_;
  this->input_pos = 0;
  for (sVar3 = 0; (puVar1 != (undefined4 *)0x0 && (sVar3 < (short)this->_padding_));
      sVar3 = sVar3 + 1) {
    sVar2 = __mbslen(*puVar1);
    this->input_pos = this->input_pos + sVar2;
    puVar1 = (undefined4 *)puVar1[3];
  }
  sVar3 = *(short *)((int)&this->_padding_ + 2);
  this->input_pos = this->input_pos + sVar3;
  sVar2 = this->input_pos;
  if (((0 < sVar3) && (0 < sVar2)) && (this->input_buffer[sVar2 + -1] == '\n')) {
    this->input_pos = sVar2 + -1;
    *(short *)((int)&this->_padding_ + 2) = sVar3 + -1;
  }
  sVar3 = *(short *)((int)&this->_padding_ + 2);
  if (((0 < sVar3) && (sVar2 = this->input_pos, 0 < sVar2)) &&
     (this->input_buffer[sVar2 + -1] == '\r')) {
    this->input_pos = sVar2 + -1;
    *(short *)((int)&this->_padding_ + 2) = sVar3 + -1;
  }
  if ((short)this->_padding_ < (short)this->_padding_) {
    do {
      TTextPanel::scroll((TTextPanel *)this,'\x03',1,1);
    } while ((short)this->_padding_ < (short)this->_padding_);
  }
  if (*(short *)((int)&this->_padding_ + 2) < (short)this->_padding_) {
    do {
      TTextPanel::scroll((TTextPanel *)this,'\x02',1,1);
    } while (*(short *)((int)&this->_padding_ + 2) < (short)this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: calc_cur_line_col
// Address: 00478010
void __thiscall TInputPanel::calc_cur_line_col(TInputPanel *this)
{
  short *psVar1;
  undefined4 *puVar2;
  short sVar3;
  short sVar4;
  
  puVar2 = (undefined4 *)this->_padding_;
  *(undefined2 *)&this->_padding_ = 0;
  *(undefined2 *)((int)&this->_padding_ + 2) = 0;
  for (sVar4 = 0;
      ((puVar2 != (undefined4 *)0x0 && ((int)(short)this->_padding_ != (short)this->_padding_ + -1))
      && (sVar3 = __mbslen(*puVar2), (int)sVar4 + (int)sVar3 <= (int)this->input_pos));
      sVar4 = sVar4 + sVar3) {
    *(short *)&this->_padding_ = (short)this->_padding_ + 1;
    puVar2 = (undefined4 *)puVar2[3];
  }
  sVar3 = this->input_pos;
  *(short *)((int)&this->_padding_ + 2) = sVar3 - sVar4;
  if (((0 < (short)(sVar3 - sVar4)) && (0 < sVar3)) && (this->input_buffer[sVar3 + -1] == '\n')) {
    psVar1 = (short *)((int)&this->_padding_ + 2);
    *psVar1 = *psVar1 + -1;
    this->input_pos = sVar3 + -1;
  }
  if (((0 < *(short *)((int)&this->_padding_ + 2)) && (sVar4 = this->input_pos, 0 < sVar4)) &&
     (this->input_buffer[sVar4 + -1] == '\r')) {
    psVar1 = (short *)((int)&this->_padding_ + 2);
    *psVar1 = *psVar1 + -1;
    this->input_pos = sVar4 + -1;
  }
  if ((short)this->_padding_ < (short)this->_padding_) {
    do {
      TTextPanel::scroll((TTextPanel *)this,'\x03',1,1);
    } while ((short)this->_padding_ < (short)this->_padding_);
  }
  if (*(short *)((int)&this->_padding_ + 2) < (short)this->_padding_) {
    do {
      TTextPanel::scroll((TTextPanel *)this,'\x02',1,1);
    } while (*(short *)((int)&this->_padding_ + 2) < (short)this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: is_blank
// Address: 00478150
int __thiscall TInputPanel::is_blank(TInputPanel *this)
{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = TTextPanel::currentLine((TTextPanel *)this);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    for (; *pcVar1 != '\0'; pcVar1 = (char *)__mbsinc(pcVar1)) {
      iVar2 = __ismbcspace(*pcVar1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: get_trimmed_str
// Address: 004781a0
char * __thiscall TInputPanel::get_trimmed_str(TInputPanel *this,char *param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char temp_str [256];
  
  pcVar3 = temp_str;
  for (iVar4 = 0x40; pcVar3 = pcVar3 + 4, iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
  }
  pcVar2 = TTextPanel::currentLine((TTextPanel *)this);
  uVar5 = 0xffffffff;
  pcVar3 = temp_str;
  do {
    pcVar7 = pcVar2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar2 = pcVar7 + -uVar5;
  for (uVar6 = uVar5 >> 2; pcVar3 = pcVar3 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar3 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  pcVar3 = param_1;
  for (uVar5 = (uint)param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  for (uVar5 = param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar3 = '\0';
    pcVar3 = pcVar3 + 1;
  }
  pcVar3 = temp_str + 4;
  iVar4 = __ismbcspace(temp_str._4_4_ & 0xff);
  while (iVar4 != 0) {
    pcVar3 = (char *)__mbsinc(pcVar3);
    iVar4 = __ismbcspace(*pcVar3);
  }
  cVar1 = *pcVar3;
  pcVar2 = param_1;
  while (cVar1 != '\0') {
    __mbsncpy(pcVar2,pcVar3,1);
    pcVar2 = (char *)__mbsinc(pcVar2);
    pcVar3 = (char *)__mbsinc(pcVar3);
    cVar1 = *pcVar3;
  }
  do {
    *pcVar2 = '\0';
    if (pcVar2 == param_1) {
      return param_1;
    }
    pcVar2 = (char *)__mbsdec(param_1,pcVar2);
    iVar4 = __ismbcspace(*pcVar2);
  } while (iVar4 != 0);
  return param_1;
}

// --------------------------------------------------

