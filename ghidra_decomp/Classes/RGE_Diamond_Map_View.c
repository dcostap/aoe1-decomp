// Class: RGE_Diamond_Map_View
// Size:  0x16C
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
// ----------------------------------------------------------------

// Function: RGE_Diamond_Map_View
// Address: 0053d360
RGE_Diamond_Map_View * __thiscall
RGE_Diamond_Map_View::RGE_Diamond_Map_View(RGE_Diamond_Map_View *this)
{
  RGE_Diamond_Map::RGE_Diamond_Map((RGE_Diamond_Map *)this);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)&this->field_0xc0 = 0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0053d380
void * __thiscall
RGE_Diamond_Map_View::_scalar_deleting_destructor_(RGE_Diamond_Map_View *this,uint param_1)
{
  ~RGE_Diamond_Map_View(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Diamond_Map_View
// Address: 0053d3a0
void __thiscall RGE_Diamond_Map_View::~RGE_Diamond_Map_View(RGE_Diamond_Map_View *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cf18;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)this = &RGE_Diamond_Map::_vftable_;
  uStack_4 = 0;
  RGE_Diamond_Map::delete_surfaces((RGE_Diamond_Map *)this);
  if (*(int *)&this->field_0x12c != 0) {
    free(*(int *)&this->field_0x12c);
    *(undefined4 *)&this->field_0x12c = 0;
  }
  if (*(int *)&this->field_0x128 != 0) {
    free(*(int *)&this->field_0x128);
    *(undefined4 *)&this->field_0x128 = 0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 0053d3b0
long __thiscall
RGE_Diamond_Map_View::handle_mouse_down
          (RGE_Diamond_Map_View *this,uchar param_1,long param_2,long param_3,int param_4,
          int param_5)
{
  long lVar1;
  int iVar2;
  long lVar3;
  RGE_Tile *tile;
  RGE_Diamond_Map_View *local_4;
  
  lVar1 = param_3;
  lVar3 = param_2;
  local_4 = this;
  iVar2 = RGE_Diamond_Map::pick_tile
                    ((RGE_Diamond_Map *)this,param_2,param_3,(short *)&param_2,(short *)&param_3,
                     (RGE_Tile **)&local_4);
  if (iVar2 == 0) {
    return 0;
  }
  lVar3 = TPanel::handle_mouse_down((TPanel *)this,param_1,lVar3,lVar1,param_4,param_5);
  return lVar3;
}

// --------------------------------------------------

// Function: mouse_left_down_action
// Address: 0053d400
long __thiscall
RGE_Diamond_Map_View::mouse_left_down_action
          (RGE_Diamond_Map_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    iVar1 = rge_base_game->prog_mode;
    if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
      if (rge_base_game->prog_info->interface_style == 2) {
        RGE_Diamond_Map::start_scroll_view((RGE_Diamond_Map *)this,param_1,param_2);
        return 1;
      }
      if (((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) {
        TPanel::capture_mouse((TPanel *)this);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_move_action
// Address: 0053d480
long __thiscall
RGE_Diamond_Map_View::mouse_left_move_action
          (RGE_Diamond_Map_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
    iVar1 = RGE_Base_Game::get_paused(rge_base_game);
    if (iVar1 != 0) {
      if (*(int *)&this->field_0x154 != 0) {
        RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)this);
        return 0;
      }
      TPanel::release_mouse((TPanel *)this);
      return 0;
    }
    if (*(int *)&this->field_0x154 != 0) {
      RGE_Diamond_Map::handle_scroll_view((RGE_Diamond_Map *)this,param_1,param_2);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_up_action
// Address: 0053d500
long __thiscall
RGE_Diamond_Map_View::mouse_left_up_action
          (RGE_Diamond_Map_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  short row;
  short col;
  RGE_Tile *tile;
  RGE_Tile *local_4;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
    if (*(int *)&this->field_0x154 != 0) {
      RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)this);
      return 1;
    }
    TPanel::release_mouse((TPanel *)this);
    iVar1 = RGE_Base_Game::get_paused(rge_base_game);
    if ((iVar1 == 0) && (rge_base_game->prog_mode != 5)) {
      iVar1 = RGE_Diamond_Map::pick_tile
                        ((RGE_Diamond_Map *)this,param_1,param_2,(short *)((int)&tile + 2),
                         (short *)&tile,&local_4);
      if (iVar1 != 0) {
        iVar1 = rge_base_game->game_mode;
        if (iVar1 == 0) {
          if (rge_base_game->prog_info->interface_style != 2) {
            iVar1 = (**(code **)(*(int *)this + 0xf4))(param_1,param_2);
            if (iVar1 != 0) {
              return 1;
            }
          }
        }
        else {
          if (iVar1 == 4) {
            (**(code **)(*(int *)this + 0xf8))(param_1,param_2);
            return 1;
          }
          if (iVar1 == 5) {
            (**(code **)(*(int *)this + 0xfc))(param_1,param_2);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_down_action
// Address: 0053d620
long __thiscall
RGE_Diamond_Map_View::mouse_right_down_action
          (RGE_Diamond_Map_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    iVar1 = rge_base_game->prog_mode;
    if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
      if (rge_base_game->prog_info->interface_style == 2) {
        if (((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) {
          TPanel::capture_mouse((TPanel *)this);
          return 1;
        }
      }
      else {
        RGE_Diamond_Map::start_scroll_view((RGE_Diamond_Map *)this,param_1,param_2);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_move_action
// Address: 0053d6a0
long __thiscall
RGE_Diamond_Map_View::mouse_right_move_action
          (RGE_Diamond_Map_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
    iVar1 = RGE_Base_Game::get_paused(rge_base_game);
    if (iVar1 != 0) {
      if (*(int *)&this->field_0x154 != 0) {
        RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)this);
        return 0;
      }
      TPanel::release_mouse((TPanel *)this);
      return 0;
    }
    if (*(int *)&this->field_0x154 != 0) {
      RGE_Diamond_Map::handle_scroll_view((RGE_Diamond_Map *)this,param_1,param_2);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_up_action
// Address: 0053d720
long __thiscall
RGE_Diamond_Map_View::mouse_right_up_action
          (RGE_Diamond_Map_View *this,long param_1,long param_2,int param_3,int param_4)
{
  int iVar1;
  RGE_Tile *tile;
  RGE_Diamond_Map_View *local_4;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
    local_4 = this;
    if (*(int *)&this->field_0x154 != 0) {
      RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)this);
      return 1;
    }
    TPanel::release_mouse((TPanel *)this);
    iVar1 = RGE_Base_Game::get_paused(rge_base_game);
    if ((iVar1 == 0) && ((this->field_0xec == '\x01' || (this->field_0xec == '\x02')))) {
      if (rge_base_game->prog_info->interface_style == 2) {
        if ((rge_base_game->game_mode == 0) && (rge_base_game->prog_mode != 5)) {
          if (param_4 != 0) {
            iVar1 = RGE_Diamond_Map::pick_tile
                              ((RGE_Diamond_Map *)this,param_1,param_2,(short *)&param_1,
                               (short *)&param_2,(RGE_Tile **)&local_4);
            if (iVar1 != 0) {
              param_4 = (int)(short)param_1;
              (**(code **)(**(int **)&this->field_0xf8 + 0xd8))
                        ((float)param_4 - _DAT_005777e8,(float)(int)(short)param_2 - _DAT_005777e8,
                         0x3f800000);
            }
            return 1;
          }
          iVar1 = (**(code **)(*(int *)this + 0xf4))(param_1,param_2);
          if (iVar1 != 0) {
            return 1;
          }
        }
      }
      else if (rge_base_game->prog_mode != 7) {
        if (rge_base_game->game_mode != 0) {
          (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          return 0;
        }
        RGE_Player::unselect_object(*(RGE_Player **)&this->field_0xf8);
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: draw
// Address: 0053d890
// [HELPER] s_C__msdev_work_age1_x1_vw_dimap_c: "C:\msdev\work\age1_x1\vw_dimap.cpp"
void __thiscall RGE_Diamond_Map_View::draw(RGE_Diamond_Map_View *this)
{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_dimap_c,0x10e);
  RGE_Diamond_Map::draw((RGE_Diamond_Map *)this);
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_dimap_c,0x112);
  RGE_Base_Game::add_to_timing(rge_base_game,7,uVar2 - uVar1);
  return;
}

// --------------------------------------------------

// Function: command_make_do
// Address: 0053d8e0
int __thiscall
RGE_Diamond_Map_View::command_make_do(RGE_Diamond_Map_View *this,long param_1,long param_2)
{
  int iVar1;
  uint uVar2;
  RGE_Tile *tile;
  RGE_Tile *local_4;
  
  if (allow_user_commands == 0) {
    return 0;
  }
  uVar2 = 0;
  iVar1 = RGE_Diamond_Map::pick_tile
                    ((RGE_Diamond_Map *)this,param_1,param_2,(short *)&param_1,(short *)&param_2,
                     &local_4);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(**(int **)&this->field_0xf8 + 0xa8))
                      (0,(float)(int)(short)param_1 - _DAT_005777e8,
                       (float)(int)(short)param_2 - _DAT_005777e8);
    uVar2 = uVar2 & 0xff;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: command_make_move
// Address: 0053d970
int __thiscall
RGE_Diamond_Map_View::command_make_move(RGE_Diamond_Map_View *this,long param_1,long param_2)
{
  int iVar1;
  uint uVar2;
  RGE_Tile *tile;
  RGE_Tile *local_4;
  
  if (allow_user_commands == 0) {
    return 0;
  }
  uVar2 = 0;
  iVar1 = RGE_Diamond_Map::pick_tile
                    ((RGE_Diamond_Map *)this,param_1,param_2,(short *)&param_1,(short *)&param_2,
                     &local_4);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(**(int **)&this->field_0xf8 + 0xa0))
                      (0,(float)(int)(short)param_1 - _DAT_005777e8,
                       (float)(int)(short)param_2 - _DAT_005777e8);
    uVar2 = uVar2 & 0xff;
  }
  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
  return uVar2;
}

// --------------------------------------------------

// Function: command_make_work
// Address: 0053da10
int __thiscall
RGE_Diamond_Map_View::command_make_work(RGE_Diamond_Map_View *this,long param_1,long param_2)
{
  int iVar1;
  uint uVar2;
  RGE_Tile *tile;
  RGE_Tile *local_4;
  
  if (allow_user_commands == 0) {
    return 0;
  }
  uVar2 = 0;
  iVar1 = RGE_Diamond_Map::pick_tile
                    ((RGE_Diamond_Map *)this,param_1,param_2,(short *)&param_1,(short *)&param_2,
                     &local_4);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(**(int **)&this->field_0xf8 + 0xa4))
                      (0,(float)(int)(short)param_1 - _DAT_005777e8,
                       (float)(int)(short)param_2 - _DAT_005777e8);
    uVar2 = uVar2 & 0xff;
  }
  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
  return uVar2;
}

// --------------------------------------------------

