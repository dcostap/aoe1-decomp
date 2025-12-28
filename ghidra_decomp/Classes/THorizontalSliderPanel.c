// Class: THorizontalSliderPanel
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
// [112] set_text
// [113] set_text
// [114] set_text
// [115] set_bevel_info
//
// Member Layout:
// ----------------------------------------------------------------

// Function: THorizontalSliderPanel
// Address: 0047bdf0
/* public: __thiscall THorizontalSliderPanel::THorizontalSliderPanel(void) */

THorizontalSliderPanel * __thiscall
THorizontalSliderPanel::THorizontalSliderPanel(THorizontalSliderPanel *this)
{
  TVerticalSliderPanel::TVerticalSliderPanel((TVerticalSliderPanel *)this);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0047be10
/* public: virtual void * __thiscall THorizontalSliderPanel::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
THorizontalSliderPanel::_scalar_deleting_destructor_(THorizontalSliderPanel *this,uint param_1)
{
  ~THorizontalSliderPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~THorizontalSliderPanel
// Address: 0047be30
/* public: virtual __thiscall THorizontalSliderPanel::~THorizontalSliderPanel(void) */

void __thiscall THorizontalSliderPanel::~THorizontalSliderPanel(THorizontalSliderPanel *this)
{
  *(undefined ***)this = &_vftable_;
  TVerticalSliderPanel::~TVerticalSliderPanel((TVerticalSliderPanel *)this);
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0047be40
/* public: long __thiscall THorizontalSliderPanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,char *,char *,long,long,long,long,int,int) */

long __thiscall
THorizontalSliderPanel::setup
          (THorizontalSliderPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4
          ,long param_5,long param_6,char *param_7,char *param_8,long param_9,long param_10,
          long param_11,long param_12,int param_13,int param_14)
{
  long lVar1;
  
  *(int *)&this->field_0x1c4 = param_13;
  *(int *)&this->field_0x1c8 = param_14;
  lVar1 = TScrollBarPanel::setup
                    ((TScrollBarPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,param_7
                     ,(char *)0x0,(char *)0x0,param_8,0,param_9,(TPanel *)0x0,param_10,Horizontal);
  if (lVar1 == 0) {
    return 0;
  }
  *(long *)&this->field_0xfc = param_11;
  *(long *)&this->field_0x100 = param_12;
  return 1;
}

// --------------------------------------------------

// Function: set_rect
// Address: 0047bec0
/* public: virtual void __thiscall THorizontalSliderPanel::set_rect(long,long,long,long) */

void __thiscall
THorizontalSliderPanel::set_rect
          (THorizontalSliderPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  int iVar1;
  int iVar2;
  
  TScrollBarPanel::set_rect((TScrollBarPanel *)this,param_1,param_2,param_3,param_4);
  iVar2 = *(int *)&this->field_0xc;
  *(int *)&this->field_0x164 = iVar2;
  *(int *)&this->field_0x16c = iVar2;
  iVar1 = *(int *)&this->field_0x14 + -1 + iVar2;
  *(int *)&this->field_0x174 = iVar1;
  *(int *)&this->field_0x17c = iVar1;
  *(int *)&this->field_0x138 = iVar2 + 1;
  *(int *)&this->field_0x134 = iVar2 + 1;
  *(int *)&this->field_0x13c = (iVar1 - *(int *)&this->field_0x18) + 2;
  TScrollBarPanel::calc_item_rects((TScrollBarPanel *)this);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0047bf30
// [HELPER] s_pnl_scbr__draw: "pnl_scbr::draw"
/* public: virtual void __thiscall THorizontalSliderPanel::draw(void) */

void __thiscall THorizontalSliderPanel::draw(THorizontalSliderPanel *this)
{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  
  if (*(int **)&this->field_0x40 != (int *)0x0) {
    (**(code **)(**(int **)&this->field_0x40 + 0x3c))(&this->field_0x24);
  }
  iVar1 = *(int *)this;
  (**(code **)(iVar1 + 0x28))(0);
  puVar2 = TDrawArea::Lock(*(TDrawArea **)&this->field_0x20,s_pnl_scbr__draw,1);
  if (puVar2 != (uchar *)0x0) {
    TScrollBarPanel::draw_back_pic((TScrollBarPanel *)this);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,0,1,(tagRECT *)&this->field_0x8c);
    if ((*(int *)&this->field_0x168 != *(int *)&this->field_0x170) &&
       (*(int *)&this->field_0x164 != *(int *)&this->field_0x16c)) {
      if ((this->field_0x144 == '\x01') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,*(int *)&this->field_0x110,iVar3,
                 (tagRECT *)&this->field_0x164);
      if ((this->field_0x144 == '\x01') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->field_0x164);
    }
    if ((*(int *)&this->field_0x178 != *(int *)&this->field_0x180) &&
       (*(int *)&this->field_0x174 != *(int *)&this->field_0x17c)) {
      if ((this->field_0x144 == '\x02') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic
                ((TScrollBarPanel *)this,*(int *)&this->field_0x114,iVar3,
                 (tagRECT *)&this->field_0x174);
      if ((this->field_0x144 == '\x02') && (*(int *)&this->field_0x148 != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,iVar3,(tagRECT *)&this->field_0x174);
    }
    TScrollBarPanel::draw_button_pic
              ((TScrollBarPanel *)this,*(int *)&this->field_0x118,0,(tagRECT *)&this->field_0x184);
    TScrollBarPanel::draw_border((TScrollBarPanel *)this,1,0,(tagRECT *)&this->field_0x184);
    TDrawArea::Unlock(*(TDrawArea **)&this->field_0x20,s_pnl_scbr__draw);
  }
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

