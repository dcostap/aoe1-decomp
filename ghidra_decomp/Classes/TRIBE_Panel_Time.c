// Class: TRIBE_Panel_Time
// Size:  0x174
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
// [112] draw_background
// [113] set_ideal_size
// [114] create_button
// [115] create_button
// [116] create_check_box
// [117] create_radio_button
// [118] create_text
// [119] create_text
// [120] create_text
// [121] create_input
// [122] create_edit
// [123] create_drop_down
// [124] create_list
// [125] create_scrollbar
// [126] create_auto_scrollbar
// [127] create_vert_slider
// [128] create_horz_slider
// [129] position_panel
//
// Member Layout:
// [0x0F4] void * font
// [0x0F8] ulong color1
// [0x0FC] ulong color2
// [0x100] int clock_type
// [0x104] int old_clock_type
// [0x108] int clock_format
// [0x10C] int old_clock_format
// [0x110] int player_id
// [0x114] TRIBE_World * world
// [0x118] TRIBE_Player * player
// [0x11C] ulong start_real_time
// [0x120] ulong game_time
// [0x124] ulong last_game_time
// [0x128] ulong display_time
// [0x12C] ulong last_display_time
// [0x130] void * image_clip_region
// [0x134] TDrawArea * ImageBuffer
// [0x138] tagRECT ImageRect (sz: 0x10)
// [0x148] tagRECT UsedImageRect (sz: 0x10)
// [0x158] tagRECT UsedScreenRect (sz: 0x10)
// [0x168] int ImageTextActive
// [0x16C] int LastIBWidth
// [0x170] int LastIBHeight
// ----------------------------------------------------------------

// Function: TRIBE_Panel_Time
// Address: 0051d790
TRIBE_Panel_Time * __thiscall
TRIBE_Panel_Time::TRIBE_Panel_Time(TRIBE_Panel_Time *this,TDrawArea *param_1,TPanel *param_2)
{
  RGE_Font *pRVar1;
  long lVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561408;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->_padding_ = (int)&_vftable_;
  this->_padding_ = 0;
  local_4 = 0;
  pRVar1 = RGE_Base_Game::get_font(rge_base_game,0xb);
  this->font = pRVar1->font;
  this->color1 = 0xffffff;
  this->color2 = 0;
  this->clock_type = 0;
  this->clock_format = 0;
  this->old_clock_type = 0;
  this->old_clock_format = 0;
  this->player_id = 0;
  this->world = (TRIBE_World *)0x0;
  this->player = (TRIBE_Player *)0x0;
  this->start_real_time = 0;
  this->game_time = 0;
  this->last_game_time = 0;
  this->last_display_time = 0xffffffff;
  this->ImageBuffer = (TDrawArea *)0x0;
  this->LastIBWidth = -1;
  this->LastIBHeight = -1;
  this->ImageTextActive = 0;
  this->image_clip_region = (void *)0x0;
  lVar2 = TPanel::setup((TPanel *)this,param_1,param_2,0,0,0,0,'\0');
  if (lVar2 == 0) {
    this->_padding_ = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0051d890
void * __thiscall
TRIBE_Panel_Time::_scalar_deleting_destructor_(TRIBE_Panel_Time *this,uint param_1)
{
  ~TRIBE_Panel_Time(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Time
// Address: 0051d8b0
void __thiscall TRIBE_Panel_Time::~TRIBE_Panel_Time(TRIBE_Panel_Time *this)
{
  TDrawArea *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561428;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->image_clip_region != (void *)0x0) {
    DeleteObject(this->image_clip_region);
    this->image_clip_region = (void *)0x0;
  }
  this_00 = this->ImageBuffer;
  if (this_00 != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this_00);
    operator_delete(this_00);
    this->ImageBuffer = (TDrawArea *)0x0;
  }
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: set_rect
// Address: 0051d940
// [HELPER] s_time_message_panel: "time message panel"
void __thiscall
TRIBE_Panel_Time::set_rect
          (TRIBE_Panel_Time *this,long param_1,long param_2,long param_3,long param_4)
{
  TDrawArea *pTVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056144b;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::set_rect((TPanel *)this,param_1,param_2,param_3,param_4);
  if (((this->LastIBWidth < this->_padding_) || (this->LastIBHeight < this->_padding_)) ||
     (*(int *)(this->_padding_ + 0x18) <= param_1 + this->LastIBWidth)) {
    if (this->image_clip_region != (void *)0x0) {
      DeleteObject(this->image_clip_region);
      this->image_clip_region = (void *)0x0;
    }
    pTVar1 = this->ImageBuffer;
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar1);
      operator_delete(pTVar1);
      this->ImageBuffer = (TDrawArea *)0x0;
    }
    pTVar1 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 0;
    if (pTVar1 == (TDrawArea *)0x0) {
      pTVar1 = (TDrawArea *)0x0;
    }
    else {
      pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_time_message_panel,0);
    }
    this->ImageBuffer = pTVar1;
    uStack_4 = 0xffffffff;
    TDrawArea::Init(pTVar1,*(TDrawSystem **)this->_padding_,this->_padding_,this->_padding_,0,0);
    this->LastIBWidth = this->_padding_;
    this->LastIBHeight = this->_padding_;
    iVar2 = this->_padding_ + -1;
    iVar4 = this->_padding_ + -1;
    (this->ImageRect).left = 0;
    (this->ImageRect).top = 0;
    (this->ImageRect).right = iVar2;
    (this->ImageRect).bottom = iVar4;
    pvVar3 = (void *)CreateRectRgn(0,0,iVar2,iVar4);
    this->image_clip_region = pvVar3;
  }
  if (this->ImageBuffer == (TDrawArea *)0x0) {
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
  }
  else {
    (this->UsedImageRect).left = (this->ImageRect).left;
    (this->UsedImageRect).top = (this->ImageRect).top;
    (this->UsedImageRect).right = (this->ImageRect).right;
    (this->UsedImageRect).bottom = (this->ImageRect).bottom;
  }
  iVar2 = this->_padding_;
  *(undefined1 *)((int)&this->_padding_ + 3) = 1;
  (**(code **)(iVar2 + 0x20))(1);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: startup
// Address: 0051dad0
void __thiscall TRIBE_Panel_Time::startup(TRIBE_Panel_Time *this)
{
  ulong uVar1;
  
  this->world = (TRIBE_World *)rge_base_game->world;
  uVar1 = debug_timeGetTime(&s_C__msdev_work_age1_x1_tpnl_tim_c,0x92);
  this->start_real_time = uVar1;
  return;
}

// --------------------------------------------------

// Function: set_clock_type
// Address: 0051db00
void __thiscall TRIBE_Panel_Time::set_clock_type(TRIBE_Panel_Time *this,int param_1,int param_2)
{
  int iVar1;
  
  if (this->clock_type == param_1) {
    if (this->player == (TRIBE_Player *)0x0) {
      return;
    }
    if (*(short *)((int)&this->player->_padding_ + 2) == param_2) {
      return;
    }
  }
  this->clock_type = param_1;
  if (param_2 < 1) {
    this->player = (TRIBE_Player *)0x0;
  }
  else {
    this->player = *(TRIBE_Player **)(this->world->_padding_ + param_2 * 4);
  }
  if (this->player == (TRIBE_Player *)0x0) {
switchD_0051db73_default:
    this->color1 = 0xffffff;
  }
  else {
    switch(*(undefined2 *)(this->player->_padding_ + 0x26)) {
    case 0:
      this->color1 = 0xff0000;
      this->color2 = 0xb3b3b3;
      goto LAB_0051dbf4;
    case 1:
      this->color1 = 0x2139c6;
      break;
    case 2:
      this->color1 = 0xffff;
      break;
    case 3:
      this->color1 = 0x4f73a3;
      break;
    case 4:
      this->color1 = 0xf77f3;
      break;
    case 5:
      this->color1 = 0xc700;
      break;
    case 6:
      this->color1 = 0x7b90a2;
      break;
    case 7:
      this->color1 = 0xadad00;
      break;
    default:
      goto switchD_0051db73_default;
    }
  }
  this->color2 = 0;
LAB_0051dbf4:
  if ((param_1 == 1) || (param_1 == 2)) {
    this->clock_format = 1;
  }
  else {
    this->clock_format = 2;
  }
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0x14))(param_1 != 0);
  (**(code **)(iVar1 + 0x20))(1);
  (**(code **)(*(int *)this->_padding_ + 0x20))(1);
  (**(code **)(iVar1 + 0x4c))();
  return;
}

// --------------------------------------------------

// Function: get_clock_type
// Address: 0051dc60
int __thiscall TRIBE_Panel_Time::get_clock_type(TRIBE_Panel_Time *this)
{
  return this->clock_type;
}

// --------------------------------------------------

// Function: get_player_id
// Address: 0051dc70
int __thiscall TRIBE_Panel_Time::get_player_id(TRIBE_Panel_Time *this)
{
  if (this->player != (TRIBE_Player *)0x0) {
    return (int)*(short *)((int)&this->player->_padding_ + 2);
  }
  return 0;
}

// --------------------------------------------------

// Function: draw
// Address: 0051dc90
// [HELPER] s__02ld__02ld__02ld___3_1f_: "%02ld:%02ld:%02ld (%3.1f)"
// [HELPER] s_tpnl_tim__draw: "tpnl_tim::draw"
void __thiscall TRIBE_Panel_Time::draw(TRIBE_Panel_Time *this)
{
  ulong uVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  tagRECT rect;
  int iStack_114;
  void *old_font;
  char str [256];
  
  if (this->_padding_ == 0) {
    return;
  }
  if (this->_padding_ == 0) {
    return;
  }
  if (this->_padding_ == 0) {
    return;
  }
  iVar6 = this->_padding_;
  this->_padding_ = this->_padding_ + 1;
  (**(code **)(iVar6 + 0x28))(0);
  if (this->clock_format == 1) {
    uVar1 = this->game_time;
  }
  else {
    uVar1 = ((this->game_time + 4) / 5) * 5;
  }
  this->display_time = uVar1;
  if (((this->ImageBuffer != (TDrawArea *)0x0) &&
      ((((this->display_time != this->last_display_time ||
         (this->clock_type != this->old_clock_type)) ||
        (this->clock_format != this->old_clock_format)) ||
       (*(char *)((int)&this->_padding_ + 3) != '\0')))) &&
     (render_to_image_buffer(this), *(char *)((int)&this->_padding_ + 3) != '\0')) {
    *(undefined1 *)((int)&this->_padding_ + 3) = 0;
    (**(code **)(iVar6 + 0x2c))();
    return;
  }
  if ((this->ImageTextActive != 0) && (this->ImageBuffer != (TDrawArea *)0x0)) {
    TDrawArea::SetTrans(this->ImageBuffer,1,'\x01');
    TDrawArea::Copy(this->ImageBuffer,(TDrawArea *)this->_padding_,(this->UsedScreenRect).left,
                    (this->UsedScreenRect).top,&this->UsedImageRect,1);
    TDrawArea::SetTrans(this->ImageBuffer,0,'\x01');
    (**(code **)(iVar6 + 0x2c))();
    return;
  }
  pvVar2 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_tim__draw);
  if (pvVar2 == (void *)0x0) goto LAB_0051e0ce;
  SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
  uVar3 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
  SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
  if (this->clock_format == 1) {
    uVar1 = this->game_time;
    iVar6 = 0;
    iVar8 = 0;
    if (0x3b < (int)uVar1) {
      iVar6 = (int)uVar1 / 0x3c;
      uVar1 = (int)uVar1 % 0x3c;
      if (0x3b < iVar6) {
        iVar8 = iVar6 / 0x3c;
        iVar6 = iVar6 % 0x3c;
      }
    }
    sprintf(str,s__02ld__02ld__02ld___3_1f_,iVar8,iVar6,uVar1,
            (double)rge_base_game->world->game_speed);
    uVar9 = 0x20;
  }
  else {
    iVar6 = this->clock_type;
    iVar8 = ((this->game_time + 4) / 5) * 5;
    if (iVar6 == 4) {
      iVar6 = 0x2c25;
LAB_0051df07:
      pcVar4 = TPanel::get_string((TPanel *)this,iVar6);
      uVar10 = CONCAT44(iVar8,pcVar4);
    }
    else if (iVar6 == 5) {
      pcVar4 = TPanel::get_string((TPanel *)this,0x2c26);
      uVar10 = CONCAT44(iVar8,pcVar4);
    }
    else {
      if (iVar6 != 6) {
        iVar6 = 0x2c24;
        goto LAB_0051df07;
      }
      pcVar4 = TPanel::get_string((TPanel *)this,0x2c27);
      uVar10 = CONCAT44(iVar8,pcVar4);
    }
    sprintf(str,uVar10);
    uVar9 = 0x22;
  }
  SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->color2);
  iVar6 = this->_padding_;
  iVar8 = this->_padding_;
  iVar7 = this->_padding_ + -2 + iVar8 + 1;
  iVar5 = this->_padding_ + -2 + iVar6 + 1;
  SetRect(&rect,iVar6,iVar8,iVar5 + -2,iVar7 + -2);
  DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,uVar9);
  SetRect(&rect,iVar6,iVar8 + 2,iVar5 + -2,iVar7);
  DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,uVar9);
  SetRect(&rect,iVar6 + 2,iVar8,iVar5,iVar7 + -2);
  DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,uVar9);
  SetRect(&rect,iVar6 + 2,iVar8 + 2,iVar5,iVar7);
  DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,uVar9);
  SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->color1);
  SetRect(&rect,iVar6 + 1,iVar8 + 1,iVar5 + -1,iVar7 + -1);
  DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,uVar9);
  SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar3);
  SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),0);
  TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_tim__draw);
  iVar6 = iStack_114;
LAB_0051e0ce:
  (**(code **)(iVar6 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: get_true_render_rect
// Address: 0051e0e0
void __thiscall TRIBE_Panel_Time::get_true_render_rect(TRIBE_Panel_Time *this,tagRECT *param_1)
{
  if ((((this->ImageBuffer != (TDrawArea *)0x0) && (this->_padding_ != 0)) && (this->_padding_ != 0)
      ) && (this->_padding_ != 0)) {
    param_1->left = (this->UsedScreenRect).left;
    param_1->top = (this->UsedScreenRect).top;
    param_1->right = (this->UsedScreenRect).right;
    param_1->bottom = (this->UsedScreenRect).bottom;
    return;
  }
  param_1->left = this->_padding_;
  param_1->top = this->_padding_;
  param_1->right = this->_padding_;
  param_1->bottom = this->_padding_;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0051e150
long __thiscall TRIBE_Panel_Time::handle_idle(TRIBE_Panel_Time *this)
{
  ulong uVar1;
  long countdown_timer;
  TRIBE_Panel_Time *local_4;
  
  local_4 = this;
  TPanel::handle_idle((TPanel *)this);
  switch(this->clock_type) {
  case 0:
    goto switchD_0051e168_caseD_0;
  case 1:
    uVar1 = debug_timeGetTime(&s_C__msdev_work_age1_x1_tpnl_tim_c,0x18a);
    this->game_time = (uVar1 - this->start_real_time) / 1000;
    break;
  case 2:
    this->game_time = (uint)this->world->_padding_ / 1000;
    break;
  case 3:
    uVar1 = __ftol();
    this->game_time = uVar1;
    break;
  case 4:
    if (this->player == (TRIBE_Player *)0x0) {
LAB_0051e255:
      this->game_time = 0;
    }
    else {
      RGE_Base_Game::get_countdown_timer
                (rge_base_game,(int)*(short *)((int)&this->player->_padding_ + 2),(long *)&local_4);
      this->game_time = (ulong)local_4;
    }
    break;
  case 5:
    if ((this->player == (TRIBE_Player *)0x0) || (this->player->artifact_held_time == -1.0))
    goto LAB_0051e255;
    uVar1 = __ftol();
    this->game_time = uVar1;
    break;
  case 6:
    if ((this->player == (TRIBE_Player *)0x0) || (this->player->ruin_held_time == -1.0))
    goto LAB_0051e255;
    uVar1 = __ftol();
    this->game_time = uVar1;
  }
  if (this->game_time != this->last_game_time) {
    (**(code **)(this->_padding_ + 0x20))(1);
    (**(code **)(*(int *)this->_padding_ + 0x20))(1);
    this->last_game_time = this->game_time;
  }
switchD_0051e168_caseD_0:
  return 0;
}

// --------------------------------------------------

// Function: render_to_image_buffer
// Address: 0051e2b0
// [HELPER] s__02ld__02ld__02ld___3_1f_: "%02ld:%02ld:%02ld (%3.1f)"
// [HELPER] s_tpnl_tim__render_to_image_buffer: "tpnl_tim::render_to_image_buffer"
int __thiscall TRIBE_Panel_Time::render_to_image_buffer(TRIBE_Panel_Time *this)
{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  tagRECT rect;
  void *old_font;
  char str [256];
  
  if (this->ImageBuffer == (TDrawArea *)0x0) {
    return 0;
  }
  TDrawArea::PtrClear(this->ImageBuffer,&this->ImageRect,1);
  pvVar2 = TDrawArea::GetDc(this->ImageBuffer,s_tpnl_tim__render_to_image_buffer);
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  TDrawArea::SetClipRect(this->ImageBuffer,&this->ImageRect);
  SelectClipRgn(this->ImageBuffer->DrawDc,this->image_clip_region);
  str._0_4_ = SelectObject(this->ImageBuffer->DrawDc,this->font);
  SetBkMode(this->ImageBuffer->DrawDc,1);
  if (this->clock_format == 1) {
    uVar7 = this->game_time;
    iVar4 = 0;
    iVar6 = 0;
    if (0x3b < (int)uVar7) {
      iVar4 = (int)uVar7 / 0x3c;
      uVar7 = (int)uVar7 % 0x3c;
      if (0x3b < iVar4) {
        iVar6 = iVar4 / 0x3c;
        iVar4 = iVar4 % 0x3c;
      }
    }
    sprintf(str + 4,s__02ld__02ld__02ld___3_1f_,iVar6,iVar4,uVar7,
            (double)rge_base_game->world->game_speed);
    uVar8 = 0x20;
    goto LAB_0051e459;
  }
  iVar4 = this->clock_type;
  iVar6 = ((this->game_time + 4) / 5) * 5;
  if (iVar4 == 4) {
    iVar4 = 0x2c25;
LAB_0051e43f:
    pcVar3 = TPanel::get_string((TPanel *)this,iVar4);
    uVar9 = CONCAT44(iVar6,pcVar3);
  }
  else if (iVar4 == 5) {
    pcVar3 = TPanel::get_string((TPanel *)this,0x2c26);
    uVar9 = CONCAT44(iVar6,pcVar3);
  }
  else {
    if (iVar4 != 6) {
      iVar4 = 0x2c24;
      goto LAB_0051e43f;
    }
    pcVar3 = TPanel::get_string((TPanel *)this,0x2c27);
    uVar9 = CONCAT44(iVar6,pcVar3);
  }
  sprintf(str + 4,uVar9);
  uVar8 = 0x22;
LAB_0051e459:
  SetTextColor(this->ImageBuffer->DrawDc,this->color2);
  iVar4 = this->_padding_;
  iVar6 = this->_padding_;
  SetRect(&rect.top,0,0,iVar4 + -3,iVar6 + -3);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,uVar8);
  SetRect(&rect.top,0,2,iVar4 + -3,iVar6 + -1);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,uVar8);
  SetRect(&rect.top,2,0,iVar4 + -1,iVar6 + -3);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,uVar8);
  SetRect(&rect.top,2,2,iVar4 + -1,iVar6 + -1);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,uVar8);
  SetTextColor(this->ImageBuffer->DrawDc,this->color1);
  SetRect(&rect.top,1,1,iVar4 + -2,iVar6 + -2);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,uVar8);
  SelectObject(this->ImageBuffer->DrawDc,str._0_4_);
  SelectClipRgn(this->ImageBuffer->DrawDc,0);
  TDrawArea::ReleaseDc(this->ImageBuffer,s_tpnl_tim__render_to_image_buffer);
  iVar4 = this->_padding_;
  iVar6 = this->_padding_;
  iVar5 = this->_padding_;
  (this->UsedImageRect).left = 0;
  (this->UsedImageRect).top = 0;
  iVar1 = this->_padding_;
  iVar4 = iVar4 + -1;
  (this->UsedScreenRect).left = iVar6;
  iVar5 = iVar5 + -1;
  (this->UsedScreenRect).top = iVar1;
  (this->UsedImageRect).right = iVar4;
  uVar7 = this->display_time;
  (this->UsedImageRect).bottom = iVar5;
  (this->UsedScreenRect).right = iVar6 + iVar4;
  iVar4 = this->clock_format;
  iVar6 = this->clock_type;
  (this->UsedScreenRect).bottom = iVar1 + iVar5;
  this->last_display_time = uVar7;
  this->old_clock_type = iVar6;
  this->old_clock_format = iVar4;
  this->ImageTextActive = 1;
  return 1;
}

// --------------------------------------------------

