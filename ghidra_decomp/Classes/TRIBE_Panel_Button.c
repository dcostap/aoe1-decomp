// Class: TRIBE_Panel_Button
// Size:  0x3D4
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
// [56] set_state
// [57] hit_button
// [58] `scalar_deleting_destructor'
// [59] setup
// [60] set_rect
// [61] set_rect
// [62] set_color
// [63] set_active
// [64] set_positioning
// [65] set_fixed_position
// [66] set_redraw
// [67] set_overlapped_redraw
// [68] draw_setup
// [69] draw_finish
// [70] draw
// [71] draw_rect
// [72] draw_offset
// [73] draw_rect2
// [74] draw_offset2
// [75] paint
// [76] wnd_proc
// [77] handle_idle
// [78] handle_size
// [79] handle_paint
// [80] handle_key_down
// [81] handle_char
// [82] handle_command
// [83] handle_user_command
// [84] handle_timer_command
// [85] handle_scroll
// [86] handle_mouse_down
// [87] handle_mouse_move
// [88] handle_mouse_up
// [89] handle_mouse_dbl_click
// [90] mouse_move_action
// [91] mouse_left_down_action
// [92] mouse_left_hold_action
// [93] mouse_left_move_action
// [94] mouse_left_up_action
// [95] mouse_left_dbl_click_action
// [96] mouse_right_down_action
// [97] mouse_right_hold_action
// [98] mouse_right_move_action
// [99] mouse_right_up_action
// [100] mouse_right_dbl_click_action
// [101] key_down_action
// [102] char_action
// [103] action
// [104] get_true_render_rect
// [105] is_inside
// [106] set_focus
// [107] set_tab_order
// [108] set_tab_order
// [109] get_help_info
// [110] stop_sound_system
// [111] restart_sound_system
// [112] take_snapshot
// [113] handle_reactivate
// [114] `scalar_deleting_destructor'
// [115] setup
// [116] set_rect
// [117] set_rect
// [118] set_color
// [119] set_active
// [120] set_positioning
// [121] set_fixed_position
// [122] set_redraw
// [123] set_overlapped_redraw
// [124] draw_setup
// [125] draw_finish
// [126] draw
// [127] draw_rect
// [128] draw_offset
// [129] draw_rect2
// [130] draw_offset2
// [131] paint
// [132] wnd_proc
// [133] handle_idle
// [134] handle_size
// [135] handle_paint
// [136] handle_key_down
// [137] handle_char
// [138] handle_command
// [139] handle_user_command
// [140] handle_timer_command
// [141] handle_scroll
// [142] handle_mouse_down
// [143] handle_mouse_move
// [144] handle_mouse_up
// [145] handle_mouse_dbl_click
// [146] mouse_move_action
// [147] mouse_left_down_action
// [148] mouse_left_hold_action
// [149] mouse_left_move_action
// [150] mouse_left_up_action
// [151] mouse_left_dbl_click_action
// [152] mouse_right_down_action
// [153] mouse_right_hold_action
// [154] mouse_right_move_action
// [155] mouse_right_up_action
// [156] mouse_right_dbl_click_action
// [157] key_down_action
// [158] char_action
// [159] action
// [160] get_true_render_rect
// [161] is_inside
// [162] set_focus
// [163] set_tab_order
// [164] set_tab_order
// [165] get_help_info
// [166] stop_sound_system
// [167] restart_sound_system
// [168] take_snapshot
// [169] handle_reactivate
// [170] draw_item
//
// Member Layout:
// [0x2B8] int display_garrison
// [0x2BC] int garrsion_number
// [0x2C0] uchar tribe_button_type
// [0x2C4] TShape * border_pic
// [0x2C8] uchar * color_table
// [0x2CC] int border_frame
// [0x2D0] char[256] text_msg (sz: 0x100)
// [0x3D0] int in_use
// ----------------------------------------------------------------

// Function: TRIBE_Panel_Button
// Address: 00519da0
/* public: __thiscall TRIBE_Panel_Button::TRIBE_Panel_Button(class TDrawArea *,class TPanel *,class
   TDigital *,void *,long,long,class TShape *) */

TRIBE_Panel_Button * __thiscall
TRIBE_Panel_Button::TRIBE_Panel_Button
          (TRIBE_Panel_Button *this,TDrawArea *param_1,TPanel *param_2,TDigital *param_3,
          void *param_4,long param_5,long param_6,TShape *param_7)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005612f8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TButtonPanel::TButtonPanel((TButtonPanel *)this);
  local_4 = 0;
  this->tribe_button_type = '\0';
  this->color_table = (uchar *)0x0;
  this->border_frame = 0;
  this->text_msg[0] = '\0';
  this->in_use = 0;
  this->display_garrison = 0;
  this->garrsion_number = 0;
  this->border_pic = param_7;
  this->_padding_ = (int)&_vftable_;
  lVar1 = TButtonPanel::setup((TButtonPanel *)this,param_1,param_2,0,0,0,0,DrawClear,param_3,
                              NotifyAction,-1);
  if (lVar1 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  TButtonPanel::set_font((TButtonPanel *)this,param_4,param_5,param_6);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00519e70
/* public: virtual void * __thiscall TRIBE_Panel_Button::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Panel_Button::_scalar_deleting_destructor_(TRIBE_Panel_Button *this,uint param_1)
{
  ~TRIBE_Panel_Button(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Button
// Address: 00519e90
/* public: virtual __thiscall TRIBE_Panel_Button::~TRIBE_Panel_Button(void) */

void __thiscall TRIBE_Panel_Button::~TRIBE_Panel_Button(TRIBE_Panel_Button *this)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 9;
  this->_padding_ = (int)&TButtonPanel::_vftable_;
  piVar2 = &this->_padding_;
  do {
    if (piVar2[-9] != 0) {
      free(piVar2[-9]);
      piVar2[-9] = 0;
    }
    if (*piVar2 != 0) {
      free(*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (this->_padding_ != 0) {
    free(this->_padding_);
    this->_padding_ = 0;
  }
  TPanel::~TPanel((TPanel *)this);
  return;
}

// --------------------------------------------------

// Function: set_text_msg
// Address: 00519ea0
/* public: void __thiscall TRIBE_Panel_Button::set_text_msg(char *) */

void __thiscall TRIBE_Panel_Button::set_text_msg(TRIBE_Panel_Button *this,char *param_1)
{
  if (param_1 == (char *)0x0) {
    this->text_msg[0] = '\0';
    return;
  }
  strncpy(this->text_msg,param_1,0x100);
  this->text_msg[0xff] = '\0';
  return;
}

// --------------------------------------------------

// Function: is_inside
// Address: 00519ee0
/* public: virtual int __thiscall TRIBE_Panel_Button::is_inside(long,long) */

int __thiscall TRIBE_Panel_Button::is_inside(TRIBE_Panel_Button *this,long param_1,long param_2)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = TPanel::is_inside((TPanel *)this,param_1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  if (((this->tribe_button_type == '\x02') || (this->tribe_button_type == '\x03')) &&
     (piVar1 = *(int **)(this->_padding_ + 0x4bc), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0xbc))(param_1,param_2);
    if (iVar2 != 0) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: draw
// Address: 00519f40
// [HELPER] s__d: "%d"
// [HELPER] s_tpnl_btn__draw2: "tpnl_btn::draw2"
// [HELPER] s_tpnl_btn__draw3: "tpnl_btn::draw3"
// [HELPER] s_tpnl_btn__draw: "tpnl_btn::draw"
// [HELPER] s_tpnl_inv__draw2: "tpnl_inv::draw2"
/* WARNING: Variable defined which should be unmapped: y */
/* public: virtual void __thiscall TRIBE_Panel_Button::draw(void) */

void __thiscall TRIBE_Panel_Button::draw(TRIBE_Panel_Button *this)
{
  int *piVar1;
  char cVar2;
  short sVar3;
  long lVar4;
  uchar *puVar5;
  void *pvVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  RGE_Player *pRVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  char *pcVar17;
  long *plVar18;
  bool bVar19;
  TDrawArea *pTVar20;
  long y;
  char *text;
  long x;
  short frame;
  void *old_font;
  int iStack_1c;
  tagSIZE text_size;
  char msg [10];
  
  if (this->tribe_button_type == '\x03') {
    TButtonPanel::draw((TButtonPanel *)this);
    return;
  }
  if (((this->_padding_ == 0) || (this->_padding_ == 0)) || (this->_padding_ == 0)) {
    this->_padding_ = 0;
    return;
  }
  text_size.cx = this->_padding_;
  (**(code **)(text_size.cx + 0x28))(0);
  piVar1 = &this->_padding_;
  (**(code **)(*(int *)this->_padding_ + 0x34))(piVar1);
  bVar19 = true;
  if (((this->tribe_button_type == '\0') || (this->tribe_button_type == '\x01')) &&
     ((this->border_pic != (TShape *)0x0 &&
      (puVar5 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_btn__draw,1),
      puVar5 != (uchar *)0x0)))) {
    bVar19 = false;
    TShape::shape_draw(this->border_pic,(TDrawArea *)this->_padding_,this->_padding_,this->_padding_
                       ,(uint)(this->_padding_ != 0) + this->border_frame,'\0',(uchar *)0x0);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_btn__draw);
  }
  if (bVar19) {
    (**(code **)(*(int *)this->_padding_ + 0x34))(piVar1);
  }
  if (((this->tribe_button_type != '\x01') && (this->tribe_button_type != '\x03')) ||
     (this->_padding_ == 0)) {
    if (((this->_padding_ != 0) && (-1 < (short)this->_padding_)) &&
       (puVar5 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_btn__draw3,1),
       puVar5 != (uchar *)0x0)) {
      x._0_2_ = (short)this->_padding_;
      if (this->tribe_button_type == '\0') {
        iVar8 = this->_padding_;
        if (this->_padding_ == 0) {
          iVar15 = this->_padding_ + 2;
          TDrawArea::SetClipRect
                    ((TDrawArea *)this->_padding_,*piVar1 + 2,this->_padding_ + 2,
                     this->_padding_ + -2,this->_padding_ + -2);
          iVar11 = iVar8 + 2;
        }
        else {
          iVar15 = this->_padding_ + 3;
          TDrawArea::SetClipRect
                    ((TDrawArea *)this->_padding_,*piVar1 + 3,this->_padding_ + 3,
                     this->_padding_ + -2,this->_padding_ + -3);
          iVar11 = iVar8 + 3;
        }
      }
      else {
        iVar8 = this->_padding_;
        if (this->tribe_button_type == '\x01') {
          iVar16 = this->_padding_;
          iVar15 = iVar16 + 1;
          TDrawArea::SetClipRect
                    ((TDrawArea *)this->_padding_,*piVar1 + 1,this->_padding_ + 1,
                     this->_padding_ + -1,this->_padding_ + -1);
          iVar11 = iVar8 + 1;
          if (this->_padding_ != 0) {
            iVar15 = iVar16 + 2;
            iVar11 = iVar8 + 2;
          }
        }
        else {
          iVar15 = this->_padding_;
          iVar11 = iVar8;
          if (this->_padding_ != 0) {
            x._0_2_ = (short)x + 1;
          }
        }
      }
      if (this->_padding_ != 0) {
        fog_next_shape = 1;
        _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
      }
      bVar19 = this->color_table == (uchar *)0x0;
      if (bVar19) {
        pTVar20 = (TDrawArea *)this->_padding_;
        puVar5 = (uchar *)0x0;
      }
      else {
        pRVar10 = RGE_Base_Game::get_player(rge_base_game);
        _ASMSet_Color_Xform((pRVar10->color_table->id + 1) * 0x10);
        puVar5 = this->color_table;
        pTVar20 = (TDrawArea *)this->_padding_;
      }
      TShape::shape_draw((TShape *)this->_padding_,pTVar20,iVar11,iVar15,(int)(short)x,!bVar19,
                         puVar5);
      if (this->_padding_ != 0) {
        fog_next_shape = 0;
      }
      TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_btn__draw3);
    }
    goto LAB_0051a46c;
  }
  pvVar6 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_btn__draw);
  if (pvVar6 == (void *)0x0) goto LAB_0051a46c;
  SelectClipRgn(pvVar6,this->_padding_);
  uVar7 = SelectObject(pvVar6,this->_padding_);
  SetBkMode(pvVar6,1);
  iVar8 = this->_padding_ / 2;
  pcVar13 = (char *)(&this->_padding_)[*(short *)((int)&this->_padding_ + 2)];
  iVar15 = this->_padding_ / 2;
  if (pcVar13 == (char *)0x0) {
    pcVar13 = (char *)this->_padding_;
  }
  if (pcVar13 != (char *)0x0) {
    iVar11 = -1;
    pcVar17 = pcVar13;
    do {
      if (iVar11 == 0) break;
      iVar11 = iVar11 + -1;
      cVar2 = *pcVar17;
      pcVar17 = pcVar17 + 1;
    } while (cVar2 != '\0');
    iVar11 = (int)(short)(~(ushort)iVar11 - 1);
    GetTextExtentPoint32A(pvVar6,pcVar13,iVar11,&iStack_1c);
    iVar16 = (iVar15 - iStack_1c / 2) + this->_padding_;
    sVar3 = *(short *)((int)&this->_padding_ + 2);
    if ((&this->_padding_)[sVar3] == 0) {
      iVar9 = (iVar8 - this->_padding_ / 2) + this->_padding_;
    }
    else {
      iVar9 = (iVar8 - this->_padding_) + this->_padding_;
    }
    if (this->_padding_ == 0) {
      if (this->_padding_ != 0) {
LAB_0051a150:
        iVar16 = iVar16 + 1;
        iVar9 = iVar9 + 1;
      }
    }
    else if (this->_padding_ == 0) goto LAB_0051a150;
    SetTextColor(pvVar6,(&this->_padding_)[sVar3]);
    TextOutA(pvVar6,iVar16 + -1,iVar9 + 1,pcVar13,iVar11);
    SetTextColor(pvVar6,(&this->_padding_)[*(short *)((int)&this->_padding_ + 2)]);
    TextOutA(pvVar6,iVar16,iVar9,pcVar13,iVar11);
    pcVar13 = (char *)(&this->_padding_)[*(short *)((int)&this->_padding_ + 2)];
    if (pcVar13 == (char *)0x0) {
      pcVar13 = (char *)this->_padding_;
    }
    if (pcVar13 != (char *)0x0) {
      iVar11 = -1;
      pcVar17 = pcVar13;
      do {
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        cVar2 = *pcVar17;
        pcVar17 = pcVar17 + 1;
      } while (cVar2 != '\0');
      iVar11 = (int)(short)(~(ushort)iVar11 - 1);
      GetTextExtentPoint32A(pvVar6,pcVar13,iVar11,&iStack_1c);
      text = (char *)((iVar15 - iStack_1c / 2) + this->_padding_);
      iVar8 = iVar8 + this->_padding_;
      if (this->_padding_ == 0) {
        if (this->_padding_ != 0) {
LAB_0051a237:
          text = text + 1;
          iVar8 = iVar8 + 1;
        }
      }
      else if (this->_padding_ == 0) goto LAB_0051a237;
      SetTextColor(pvVar6,(&this->_padding_)[*(short *)((int)&this->_padding_ + 2)]);
      TextOutA(pvVar6,text + -1,iVar8 + 1,pcVar13,iVar11);
      SetTextColor(pvVar6,(&this->_padding_)[*(short *)((int)&this->_padding_ + 2)]);
      TextOutA(pvVar6,text,iVar8,pcVar13,iVar11);
    }
  }
  SelectObject(pvVar6,uVar7);
  SelectClipRgn(pvVar6,0);
  TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_btn__draw);
LAB_0051a46c:
  if (((this->display_garrison != 0) && (0 < this->garrsion_number)) &&
     (pvVar6 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_btn__draw2),
     pvVar6 != (void *)0x0)) {
    sprintf(&text_size.cy,&s__d,this->garrsion_number);
    SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
    SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xcccccc);
    uVar14 = (uint)(this->_padding_ != 0);
    uVar12 = 0xffffffff;
    plVar18 = &text_size.cy;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      lVar4 = *plVar18;
      plVar18 = (long *)((int)plVar18 + 1);
    } while ((char)lVar4 != '\0');
    TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 3 + uVar14,
             this->_padding_ + 2 + uVar14,&text_size.cy,~uVar12 - 1);
    SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),0);
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_inv__draw2);
  }
  (**(code **)((int)old_font + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: set_display_garrison
// Address: 0051a570
/* public: void __thiscall TRIBE_Panel_Button::set_display_garrison(int) */

void __thiscall TRIBE_Panel_Button::set_display_garrison(TRIBE_Panel_Button *this,int param_1)
{
  this->display_garrison = param_1;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_garrison_number
// Address: 0051a590
/* public: void __thiscall TRIBE_Panel_Button::set_garrison_number(int) */

void __thiscall TRIBE_Panel_Button::set_garrison_number(TRIBE_Panel_Button *this,int param_1)
{
  this->garrsion_number = param_1;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: get_garrison_number
// Address: 0051a5b0
/* public: int __thiscall TRIBE_Panel_Button::get_garrison_number(void) */

int __thiscall TRIBE_Panel_Button::get_garrison_number(TRIBE_Panel_Button *this)
{
  return this->garrsion_number;
}

// --------------------------------------------------

