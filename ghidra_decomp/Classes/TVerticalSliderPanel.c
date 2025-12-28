// Class: TVerticalSliderPanel
// Size:  0x1CC
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
// [112] `scalar_deleting_destructor'
// [113] setup
// [114] set_rect
// [115] set_rect
// [116] set_color
// [117] set_active
// [118] set_positioning
// [119] set_fixed_position
// [120] set_redraw
// [121] set_overlapped_redraw
// [122] draw_setup
// [123] draw_finish
// [124] draw
// [125] draw_rect
// [126] draw_offset
// [127] draw_rect2
// [128] draw_offset2
// [129] paint
// [130] wnd_proc
// [131] handle_idle
// [132] handle_size
// [133] handle_paint
// [134] handle_key_down
// [135] handle_char
// [136] handle_command
// [137] handle_user_command
// [138] handle_timer_command
// [139] handle_scroll
// [140] handle_mouse_down
// [141] handle_mouse_move
// [142] handle_mouse_up
// [143] handle_mouse_dbl_click
// [144] mouse_move_action
// [145] mouse_left_down_action
// [146] mouse_left_hold_action
// [147] mouse_left_move_action
// [148] mouse_left_up_action
// [149] mouse_left_dbl_click_action
// [150] mouse_right_down_action
// [151] mouse_right_hold_action
// [152] mouse_right_move_action
// [153] mouse_right_up_action
// [154] mouse_right_dbl_click_action
// [155] key_down_action
// [156] char_action
// [157] action
// [158] get_true_render_rect
// [159] is_inside
// [160] set_focus
// [161] set_tab_order
// [162] set_tab_order
// [163] get_help_info
// [164] stop_sound_system
// [165] restart_sound_system
// [166] take_snapshot
// [167] handle_reactivate
// [168] set_text
// [169] set_text
// [170] set_text
// [171] set_bevel_info
//
// Member Layout:
// [0x1C4] int drawBox
// [0x1C8] int spineWidth
// ----------------------------------------------------------------

// Function: TVerticalSliderPanel
// Address: 0047bce0
/* public: __thiscall TVerticalSliderPanel::TVerticalSliderPanel(void) */

TVerticalSliderPanel * __thiscall
TVerticalSliderPanel::TVerticalSliderPanel(TVerticalSliderPanel *this)
{
  TScrollBarPanel::TScrollBarPanel((TScrollBarPanel *)this);
  this->drawBox = 1;
  this->spineWidth = 0;
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0047bd10
/* public: virtual void * __thiscall TVerticalSliderPanel::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TVerticalSliderPanel::_scalar_deleting_destructor_(TVerticalSliderPanel *this,uint param_1)
{
  ~TVerticalSliderPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TVerticalSliderPanel
// Address: 0047bd30
/* public: virtual __thiscall TVerticalSliderPanel::~TVerticalSliderPanel(void) */

void __thiscall TVerticalSliderPanel::~TVerticalSliderPanel(TVerticalSliderPanel *this)
{
  this->_padding_ = (int)&_vftable_;
  TScrollBarPanel::~TScrollBarPanel((TScrollBarPanel *)this);
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0047bd40
/* public: long __thiscall TVerticalSliderPanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,char *,char *,long,long,long,long,int,int) */

long __thiscall
TVerticalSliderPanel::setup
          (TVerticalSliderPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
          long param_5,long param_6,char *param_7,char *param_8,long param_9,long param_10,
          long param_11,long param_12,int param_13,int param_14)
{
  long lVar1;
  
  this->drawBox = param_13;
  this->spineWidth = param_14;
  lVar1 = TScrollBarPanel::setup
                    ((TScrollBarPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,param_7
                     ,(char *)0x0,(char *)0x0,param_8,0,param_9,(TPanel *)0x0,param_10,Vertical);
  if (lVar1 == 0) {
    return 0;
  }
  this->_padding_ = param_11;
  this->_padding_ = param_12;
  return 1;
}

// --------------------------------------------------

// Function: set_rect
// Address: 0047bdc0
/* public: virtual void __thiscall TVerticalSliderPanel::set_rect(long,long,long,long) */

void __thiscall
TVerticalSliderPanel::set_rect
          (TVerticalSliderPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  TScrollBarPanel::set_rect((TScrollBarPanel *)this,param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0047bde0
// [HELPER] s_pnl_scbr__draw: "pnl_scbr::draw"
/* public: virtual void __thiscall TVerticalSliderPanel::draw(void) */

void __thiscall TVerticalSliderPanel::draw(TVerticalSliderPanel *this)
{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0x3c))(&this->_padding_);
  }
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0x28))(0);
  puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_pnl_scbr__draw,1);
  if (puVar2 != (uchar *)0x0) {
    TScrollBarPanel::draw_back_pic((TScrollBarPanel *)this);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,0,1,(tagRECT *)&this->_padding_);
    if ((this->_padding_ != this->_padding_) && (this->_padding_ != this->_padding_)) {
      if (((char)this->_padding_ == '\x01') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,this->_padding_,iVar3,(tagRECT *)&this->_padding_);
      if (((char)this->_padding_ == '\x01') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->_padding_);
    }
    if ((this->_padding_ != this->_padding_) && (this->_padding_ != this->_padding_)) {
      if (((char)this->_padding_ == '\x02') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,this->_padding_,iVar3,(tagRECT *)&this->_padding_);
      if (((char)this->_padding_ == '\x02') && (this->_padding_ != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->_padding_);
    }
    TScrollBarPanel::draw_button_pic
              ((TScrollBarPanel *)this,this->_padding_,0,(tagRECT *)&this->_padding_);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,0,(tagRECT *)&this->_padding_);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_scbr__draw);
  }
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

