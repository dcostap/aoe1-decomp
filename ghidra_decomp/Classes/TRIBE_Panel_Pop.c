// Class: TRIBE_Panel_Pop
// Size:  0x164
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
//
// Member Layout:
// [0x0F4] void * font
// [0x0F8] ulong color1
// [0x0FC] ulong color2
// [0x100] ulong color3
// [0x104] int player_id
// [0x108] TRIBE_World * world
// [0x10C] TRIBE_Player * player
// [0x110] int pop
// [0x114] int max_pop
// [0x118] uchar mode
// [0x11C] float timer
// [0x120] void * image_clip_region
// [0x124] TDrawArea * ImageBuffer
// [0x128] tagRECT ImageRect (sz: 0x10)
// [0x138] tagRECT UsedImageRect (sz: 0x10)
// [0x148] tagRECT UsedScreenRect (sz: 0x10)
// [0x158] int ImageTextActive
// [0x15C] int LastIBWidth
// [0x160] int LastIBHeight
// ----------------------------------------------------------------

// Function: TRIBE_Panel_Pop
// Address: 0051cca0
/* public: __thiscall TRIBE_Panel_Pop::TRIBE_Panel_Pop(class TDrawArea *,class TPanel *) */

TRIBE_Panel_Pop * __thiscall
TRIBE_Panel_Pop::TRIBE_Panel_Pop(TRIBE_Panel_Pop *this,TDrawArea *param_1,TPanel *param_2)
{
  RGE_Font *pRVar1;
  long lVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005613a8;
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
  this->color3 = 0xffff;
  this->player_id = 0;
  this->world = (TRIBE_World *)0x0;
  this->player = (TRIBE_Player *)0x0;
  this->pop = 0;
  this->max_pop = 0;
  this->mode = '\0';
  this->timer = 0.0;
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
// Address: 0051cd90
/* public: virtual void * __thiscall TRIBE_Panel_Pop::`scalar deleting destructor'(unsigned int) */

void * __thiscall TRIBE_Panel_Pop::_scalar_deleting_destructor_(TRIBE_Panel_Pop *this,uint param_1)
{
  ~TRIBE_Panel_Pop(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Pop
// Address: 0051cdb0
/* public: virtual __thiscall TRIBE_Panel_Pop::~TRIBE_Panel_Pop(void) */

void __thiscall TRIBE_Panel_Pop::~TRIBE_Panel_Pop(TRIBE_Panel_Pop *this)
{
  TDrawArea *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_005613c8;
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
// Address: 0051ce40
// [HELPER] s_time_message_panel: "time message panel"
/* public: virtual void __thiscall TRIBE_Panel_Pop::set_rect(long,long,long,long) */

void __thiscall
TRIBE_Panel_Pop::set_rect(TRIBE_Panel_Pop *this,long param_1,long param_2,long param_3,long param_4)
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
  pcStack_8 = FUN_005613eb;
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
// Address: 0051cfd0
/* public: void __thiscall TRIBE_Panel_Pop::startup(void) */

void __thiscall TRIBE_Panel_Pop::startup(TRIBE_Panel_Pop *this)
{
  TRIBE_Player *pTVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this->world = (TRIBE_World *)rge_base_game->world;
  pTVar1 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  this->player = pTVar1;
  iVar2 = __ftol();
  this->pop = iVar2;
  iVar3 = __ftol();
  this->max_pop = iVar2 + iVar3;
  iVar4 = __ftol();
  if (iVar4 < iVar2 + iVar3) {
    this->max_pop = iVar4;
  }
  return;
}

// --------------------------------------------------

// Function: get_player_id
// Address: 0051d040
/* public: int __thiscall TRIBE_Panel_Pop::get_player_id(void) */

int __thiscall TRIBE_Panel_Pop::get_player_id(TRIBE_Panel_Pop *this)
{
  if (this->player != (TRIBE_Player *)0x0) {
    return (int)*(short *)((int)&this->player->_padding_ + 2);
  }
  return 0;
}

// --------------------------------------------------

// Function: draw
// Address: 0051d060
// [HELPER] s__s_ld__ld: "%s%ld/%ld"
// [HELPER] s_tpnl_tim__draw: "tpnl_tim::draw"
/* WARNING: Variable defined which should be unmapped: changed_mode */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Panel_Pop::draw(void) */

void __thiscall TRIBE_Panel_Pop::draw(TRIBE_Panel_Pop *this)
{
  float fVar1;
  bool bVar2;
  float fVar3;
  byte bVar4;
  TRIBE_Player *pTVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  undefined4 uVar10;
  char *pcVar11;
  TDrawArea *pTVar12;
  int iVar13;
  ulong uVar14;
  uchar changed_mode;
  tagRECT rect;
  int iStack_110;
  void *old_font;
  char str [256];
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    this->_padding_ = this->_padding_ + 1;
    (**(code **)(this->_padding_ + 0x28))(0);
    pTVar5 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    this->player = pTVar5;
    bVar2 = false;
    if ((this->mode == '\0') &&
       (0 < *(int *)(rge_base_game[1].save_music_file +
                    *(short *)((int)&pTVar5->_padding_ + 2) * 4 + -0x70))) {
      this->mode = '\x01';
      this->timer = 0.0;
      bVar2 = true;
    }
    fVar3 = _DAT_00576ea0;
    if ((this->mode != '\0') &&
       (fVar1 = ((RGE_Game_World *)pTVar5->_padding_)->world_time_delta_seconds + this->timer,
       this->timer = fVar1, fVar3 < fVar1)) {
      bVar2 = true;
      bVar4 = this->mode + 1;
      this->timer = 0.0;
      this->mode = bVar4;
      if (2 < bVar4) {
        this->mode = '\0';
      }
    }
    iVar6 = __ftol();
    iVar7 = __ftol();
    iVar8 = __ftol();
    iVar13 = iVar7 + iVar6;
    if (iVar8 < iVar7 + iVar6) {
      iVar13 = iVar8;
    }
    if ((this->ImageBuffer != (TDrawArea *)0x0) &&
       ((((bVar2 || (*(char *)((int)&this->_padding_ + 3) != '\0')) || (this->pop != iVar6)) ||
        (this->max_pop != iVar13)))) {
      this->pop = iVar6;
      this->max_pop = iVar13;
      render_to_image_buffer(this);
      if (*(char *)((int)&this->_padding_ + 3) != '\0') {
        *(undefined1 *)((int)&this->_padding_ + 3) = 0;
        (**(code **)(iStack_110 + 0x2c))();
        return;
      }
    }
    if ((this->ImageTextActive != 0) && (this->ImageBuffer != (TDrawArea *)0x0)) {
      TDrawArea::SetTrans(this->ImageBuffer,1,'\x01');
      TDrawArea::Copy(this->ImageBuffer,(TDrawArea *)this->_padding_,(this->UsedScreenRect).left,
                      (this->UsedScreenRect).top,&this->UsedImageRect,1);
      TDrawArea::SetTrans(this->ImageBuffer,0,'\x01');
      (**(code **)(iStack_110 + 0x2c))();
      return;
    }
    pvVar9 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_tim__draw);
    if (pvVar9 != (void *)0x0) {
      SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
      uVar10 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
      SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
      iVar13 = this->max_pop;
      iVar6 = this->pop;
                    /* language.dll match for 0x2b2a: "pop: " */
      pcVar11 = TPanel::get_string((TPanel *)this,0x2b2a);
      sprintf(str,s__s_ld__ld,pcVar11,iVar6,iVar13);
      SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->color2);
      iVar13 = this->_padding_;
      iVar6 = this->_padding_;
      iVar8 = this->_padding_ + -2 + iVar6 + 1;
      iVar7 = this->_padding_ + -2 + iVar13 + 1;
      SetRect(&rect,iVar13,iVar6,iVar7 + -2,iVar8 + -2);
      DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,0x21);
      SetRect(&rect,iVar13,iVar6 + 2,iVar7 + -2,iVar8);
      DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,0x21);
      SetRect(&rect,iVar13 + 2,iVar6,iVar7,iVar8 + -2);
      DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,0x21);
      SetRect(&rect,iVar13 + 2,iVar6 + 2,iVar7,iVar8);
      DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,0x21);
      if (this->mode == '\x01') {
        uVar14 = this->color3;
        pTVar12 = this->ImageBuffer;
      }
      else {
        uVar14 = this->color1;
        pTVar12 = (TDrawArea *)this->_padding_;
      }
      SetTextColor(pTVar12->DrawDc,uVar14);
      SetRect(&rect,iVar13 + 1,iVar6 + 1,iVar7 + -1,iVar8 + -1);
      DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,0x21);
      SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar10);
      SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),0);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_tim__draw);
    }
                    /* Symbol Ref: {@symbol finish_up} */
    (**(code **)(iStack_110 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: get_true_render_rect
// Address: 0051d470
/* public: virtual void __thiscall TRIBE_Panel_Pop::get_true_render_rect(struct tagRECT &) */

void __thiscall TRIBE_Panel_Pop::get_true_render_rect(TRIBE_Panel_Pop *this,tagRECT *param_1)
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
// Address: 0051d4e0
/* public: virtual long __thiscall TRIBE_Panel_Pop::handle_idle(void) */

long __thiscall TRIBE_Panel_Pop::handle_idle(TRIBE_Panel_Pop *this)
{
  TPanel::handle_idle((TPanel *)this);
  return 0;
}

// --------------------------------------------------

// Function: render_to_image_buffer
// Address: 0051d4f0
// [HELPER] s__s_ld__ld: "%s%ld/%ld"
// [HELPER] s_tpnl_tim__render_to_image_buffer: "tpnl_tim::render_to_image_buffer"
/* WARNING: Variable defined which should be unmapped: rect */
/* protected: int __thiscall TRIBE_Panel_Pop::render_to_image_buffer(void) */

int __thiscall TRIBE_Panel_Pop::render_to_image_buffer(TRIBE_Panel_Pop *this)
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  tagRECT rect;
  void *old_font;
  char str [256];
  
  if (this->ImageBuffer == (TDrawArea *)0x0) {
    return 0;
  }
  TDrawArea::PtrClear(this->ImageBuffer,&this->ImageRect,1);
  pvVar3 = TDrawArea::GetDc(this->ImageBuffer,s_tpnl_tim__render_to_image_buffer);
  if (pvVar3 == (void *)0x0) {
    return 0;
  }
  TDrawArea::SetClipRect(this->ImageBuffer,&this->ImageRect);
  SelectClipRgn(this->ImageBuffer->DrawDc,this->image_clip_region);
  str._0_4_ = SelectObject(this->ImageBuffer->DrawDc,this->font);
  SetBkMode(this->ImageBuffer->DrawDc,1);
  iVar5 = this->max_pop;
  iVar7 = this->pop;
                    /* language.dll match for 0x2b2a: "pop: " */
  pcVar4 = TPanel::get_string((TPanel *)this,0x2b2a);
  sprintf(str + 4,s__s_ld__ld,pcVar4,iVar7,iVar5);
  SetTextColor(this->ImageBuffer->DrawDc,this->color2);
  iVar5 = this->_padding_;
  iVar7 = this->_padding_;
  SetRect(&rect.top,0,0,iVar5 + -3,iVar7 + -3);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,0x21);
  SetRect(&rect.top,0,2,iVar5 + -3,iVar7 + -1);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,0x21);
  SetRect(&rect.top,2,0,iVar5 + -1,iVar7 + -3);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,0x21);
  SetRect(&rect.top,2,2,iVar5 + -1,iVar7 + -1);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,0x21);
  if (this->mode == '\x01') {
    uVar6 = this->color3;
  }
  else {
    uVar6 = this->color1;
  }
  SetTextColor(this->ImageBuffer->DrawDc,uVar6);
  SetRect(&rect.top,1,1,iVar5 + -2,iVar7 + -2);
  DrawTextA(this->ImageBuffer->DrawDc,str + 4,0xffffffff,&rect.top,0x21);
  SelectObject(this->ImageBuffer->DrawDc,str._0_4_);
  SelectClipRgn(this->ImageBuffer->DrawDc,0);
  TDrawArea::ReleaseDc(this->ImageBuffer,s_tpnl_tim__render_to_image_buffer);
  iVar5 = this->_padding_;
  iVar7 = this->_padding_;
  iVar1 = this->_padding_;
  (this->UsedImageRect).left = 0;
  (this->UsedImageRect).top = 0;
  iVar2 = this->_padding_;
  iVar5 = iVar5 + -1;
  iVar7 = iVar7 + -1;
  (this->UsedScreenRect).left = iVar1;
  (this->UsedScreenRect).top = iVar2;
  (this->UsedScreenRect).bottom = iVar2 + iVar7;
  (this->UsedImageRect).right = iVar5;
  (this->UsedImageRect).bottom = iVar7;
  (this->UsedScreenRect).right = iVar1 + iVar5;
  this->ImageTextActive = 1;
  return 1;
}

// --------------------------------------------------

