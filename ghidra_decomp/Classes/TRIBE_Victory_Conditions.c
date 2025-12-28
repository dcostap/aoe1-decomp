// Class: TRIBE_Victory_Conditions
// Size:  0x20
//
// VTable Layout:
// [00] handle_point_condition
// [01] handle_condition
// [02] condition_description
// [03] save
// [04] `scalar_deleting_destructor'
// [05] setup
// [06] set_rect
// [07] set_rect
// [08] set_color
// [09] set_active
// [10] set_positioning
// [11] set_fixed_position
// [12] set_redraw
// [13] set_overlapped_redraw
// [14] draw_setup
// [15] draw_finish
// [16] draw
// [17] draw_rect
// [18] draw_offset
// [19] draw_rect2
// [20] draw_offset2
// [21] paint
// [22] wnd_proc
// [23] handle_idle
// [24] handle_size
// [25] handle_paint
// [26] handle_key_down
// [27] handle_char
// [28] handle_command
// [29] handle_user_command
// [30] handle_timer_command
// [31] handle_scroll
// [32] handle_mouse_down
// [33] handle_mouse_move
// [34] handle_mouse_up
// [35] handle_mouse_dbl_click
// [36] mouse_move_action
// [37] mouse_left_down_action
// [38] mouse_left_hold_action
// [39] mouse_left_move_action
// [40] mouse_left_up_action
// [41] mouse_left_dbl_click_action
// [42] mouse_right_down_action
// [43] mouse_right_hold_action
// [44] mouse_right_move_action
// [45] mouse_right_up_action
// [46] mouse_right_dbl_click_action
// [47] key_down_action
// [48] char_action
// [49] action
// [50] get_true_render_rect
// [51] is_inside
// [52] set_focus
// [53] set_tab_order
// [54] set_tab_order
// [55] get_help_info
// [56] stop_sound_system
// [57] restart_sound_system
// [58] take_snapshot
// [59] handle_reactivate
// [60] draw_selected_area
// [61] draw_objects
// [62] draw_visible_object
// [63] draw_object
// [64] draw_view_rect
// [65] command_make_do
// [66] command_make_move
// [67] command_make_work
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Victory_Conditions
// Address: 0052c8f0
/* public: __thiscall TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(class RGE_Player *,int,long
   *,unsigned char) */

TRIBE_Victory_Conditions * __thiscall
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
          (TRIBE_Victory_Conditions *this,RGE_Player *param_1,int param_2,long *param_3,
          uchar param_4)
{
  RGE_Victory_Conditions::RGE_Victory_Conditions
            ((RGE_Victory_Conditions *)this,param_1,param_2,param_3,param_4);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Victory_Conditions
// Address: 0052c920
/* public: __thiscall TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(class RGE_Player *) */

TRIBE_Victory_Conditions * __thiscall
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
          (TRIBE_Victory_Conditions *this,RGE_Player *param_1)
{
  RGE_Victory_Conditions::RGE_Victory_Conditions((RGE_Victory_Conditions *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Victory_Conditions
// Address: 0052c940
/* public: __thiscall TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions(void) */

void __thiscall TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions(TRIBE_Victory_Conditions *this)
{
  *(undefined ***)this = &_vftable_;
  RGE_Victory_Conditions::~RGE_Victory_Conditions((RGE_Victory_Conditions *)this);
  return;
}

// --------------------------------------------------

// Function: handle_condition
// Address: 0052c950
/* public: virtual void __thiscall TRIBE_Victory_Conditions::handle_condition(struct
   RGE_Victory_Entry *) */

void __thiscall
TRIBE_Victory_Conditions::handle_condition
          (TRIBE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  if (param_1->command != 'd') {
    RGE_Victory_Conditions::handle_condition((RGE_Victory_Conditions *)this,param_1);
    return;
  }
  handle_tech(this,param_1);
  return;
}

// --------------------------------------------------

// Function: handle_tech
// Address: 0052c970
/* protected: void __thiscall TRIBE_Victory_Conditions::handle_tech(struct RGE_Victory_Entry *) */

void __thiscall
TRIBE_Victory_Conditions::handle_tech(TRIBE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  short sVar1;
  
  if ((*(int *)&this->field_0xc != 0) && (param_1->state == '\0')) {
    sVar1 = TRIBE_Player_Tech::get_tech_state
                      (*(TRIBE_Player_Tech **)(*(int *)&this->field_0xc + 0x220),
                       (short)param_1->count);
    if (sVar1 == 3) {
      param_1->state = '\x02';
    }
  }
  return;
}

// --------------------------------------------------

// Function: add_tech
// Address: 0052c9b0
/* public: unsigned char __thiscall TRIBE_Victory_Conditions::add_tech(unsigned char,long) */

uchar __thiscall
TRIBE_Victory_Conditions::add_tech(TRIBE_Victory_Conditions *this,uchar param_1,long param_2)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add((RGE_Victory_Conditions *)this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = 'd';
    pRVar1->count = param_2;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

