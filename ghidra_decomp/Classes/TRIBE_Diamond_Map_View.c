// Class: TRIBE_Diamond_Map_View
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
// [56] draw_selected_area
// [57] draw_objects
// [58] draw_visible_object
// [59] draw_object
// [60] draw_view_rect
// [61] command_make_do
// [62] command_make_move
// [63] command_make_work
//
// Member Layout:
// [0x16C] ulong last_attack_time
// [0x170] int flash_on
// ----------------------------------------------------------------

// Function: TRIBE_Diamond_Map_View
// Address: 0052c9e0
/* public: __thiscall TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View(void) */

TRIBE_Diamond_Map_View * __thiscall
TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View(TRIBE_Diamond_Map_View *this)
{
  RGE_Diamond_Map_View::RGE_Diamond_Map_View((RGE_Diamond_Map_View *)this);
  this->_padding_ = (int)&_vftable_;
  this->last_attack_time = 0;
  this->flash_on = 0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0052ca00
/* public: virtual void * __thiscall TRIBE_Diamond_Map_View::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Diamond_Map_View::_scalar_deleting_destructor_(TRIBE_Diamond_Map_View *this,uint param_1)
{
  ~TRIBE_Diamond_Map_View(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Diamond_Map_View
// Address: 0052ca20
/* public: virtual __thiscall TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View(void) */

void __thiscall TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View(TRIBE_Diamond_Map_View *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cf18;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&RGE_Diamond_Map::_vftable_;
  uStack_4 = 0;
  RGE_Diamond_Map::delete_surfaces((RGE_Diamond_Map *)this);
  if (this->_padding_ != 0) {
    free(this->_padding_);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
    this->_padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: set_redraw
// Address: 0052ca30
/* public: virtual void __thiscall TRIBE_Diamond_Map_View::set_redraw(enum TPanel::RedrawMode) */

void __thiscall TRIBE_Diamond_Map_View::set_redraw(TRIBE_Diamond_Map_View *this,RedrawMode param_1)
{
  RGE_Diamond_Map::set_redraw((RGE_Diamond_Map *)this,param_1);
  if (((param_1 != RedrawNone) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    TRIBE_Screen_Game::set_map_buttons_redraw((TRIBE_Screen_Game *)this->_padding_,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: draw_objects
// Address: 0052ca60
// [HELPER] s_C__msdev_work_age1_x1_tvw_dmap_c: "C:\msdev\work\age1_x1\tvw_dmap.cpp"
/* protected: virtual void __thiscall TRIBE_Diamond_Map_View::draw_objects(void) */

void __thiscall TRIBE_Diamond_Map_View::draw_objects(TRIBE_Diamond_Map_View *this)
{
  ulong uVar1;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_tvw_dmap_c,0x40);
  if (0x14c < uVar1 - this->last_attack_time) {
    this->flash_on = (uint)(this->flash_on == 0);
    this->last_attack_time = uVar1;
  }
  RGE_Diamond_Map::draw_objects((RGE_Diamond_Map *)this);
  return;
}

// --------------------------------------------------

// Function: draw_object
// Address: 0052cab0
/* protected: virtual void __thiscall TRIBE_Diamond_Map_View::draw_object(short,short,unsigned
   char,short,class RGE_Static_Object *) */

void __thiscall
TRIBE_Diamond_Map_View::draw_object
          (TRIBE_Diamond_Map_View *this,short param_1,short param_2,uchar param_3,short param_4,
          RGE_Static_Object *param_5)
{
  if (this->_padding_ == 4) {
    param_3 = (-(this->flash_on != 0) & 0x57U) - 1;
  }
  RGE_Diamond_Map::draw_object((RGE_Diamond_Map *)this,param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

