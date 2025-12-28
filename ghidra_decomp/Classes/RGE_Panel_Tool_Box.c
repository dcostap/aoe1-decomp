// Class: RGE_Panel_Tool_Box
// Size:  0x120
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
// [112] get_size
// [113] save
// [114] get_object_pointer
// [115] `scalar_deleting_destructor'
// [116] rehook
// [117] save
//
// Member Layout:
// [0x0F4] TScreenPanel * screen_panel
// [0x0F8] RGE_View * view
// [0x0FC] RGE_Diamond_Map * map
// [0x100] TButtonPanel * game_mode_button
// [0x104] TButtonPanel * object_mode_button
// [0x108] TButtonPanel * delete_mode_button
// [0x10C] TButtonPanel * move_mode_button
// [0x110] TButtonPanel * terrain_mode_button
// [0x114] TButtonPanel * elevation_mode_button
// [0x118] TButtonPanel * command_button
// [0x11C] TPanel * dialog
// ----------------------------------------------------------------

// Function: RGE_Panel_Tool_Box
// Address: 004898d0
// [HELPER] s_: ""
// [HELPER] s_Cmd: "Cmd"
// [HELPER] s_Del: "Del"
// [HELPER] s_Elev: "Elev"
// [HELPER] s_Game: "Game"
// [HELPER] s_Move: "Move"
// [HELPER] s_Obj: "Obj"
// [HELPER] s_Terr: "Terr"
RGE_Panel_Tool_Box * __thiscall
RGE_Panel_Tool_Box::RGE_Panel_Tool_Box
          (RGE_Panel_Tool_Box *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
          long param_5,long param_6,void *param_7,long param_8,long param_9,TDigital *param_10,
          TScreenPanel *param_11,RGE_View *param_12,RGE_Diamond_Map *param_13)
{
  long lVar1;
  TButtonPanel *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  TButtonPanel *mode_buttons [6];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e745;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  mode_buttons[0] = (TButtonPanel *)this;
  TPanel::TPanel((TPanel *)this);
  this->screen_panel = param_11;
  this->view = param_12;
  this->map = param_13;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->game_mode_button = (TButtonPanel *)0x0;
  this->object_mode_button = (TButtonPanel *)0x0;
  this->delete_mode_button = (TButtonPanel *)0x0;
  this->move_mode_button = (TButtonPanel *)0x0;
  this->terrain_mode_button = (TButtonPanel *)0x0;
  this->elevation_mode_button = (TButtonPanel *)0x0;
  this->command_button = (TButtonPanel *)0x0;
  this->dialog = (TPanel *)0x0;
  lVar1 = TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  if (lVar1 == 0) {
    this->_padding_ = 1;
  }
  if (this->view == (RGE_View *)0x0) {
    this->_padding_ = 1;
  }
  else {
    pTVar2 = (TButtonPanel *)operator_new(0x2b8);
    local_4._0_1_ = 1;
    if (pTVar2 == (TButtonPanel *)0x0) {
      pTVar2 = (TButtonPanel *)0x0;
    }
    else {
      pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
    }
    local_4._0_1_ = 0;
    this->game_mode_button = pTVar2;
    if (pTVar2 == (TButtonPanel *)0x0) {
      this->_padding_ = 1;
    }
    else {
      TButtonPanel::setup(pTVar2,(TDrawArea *)this->_padding_,(TPanel *)this,0,0,0x32,0x1e,DrawTextA
                          ,param_10,NotifyAction,0);
      TButtonPanel::set_text_info(this->game_mode_button,s_Game,param_7,param_8,param_9,-1,-1);
      TButtonPanel::set_text(this->game_mode_button,1,s_<Game>);
      pTVar2 = (TButtonPanel *)operator_new(0x2b8);
      local_4._0_1_ = 2;
      if (pTVar2 == (TButtonPanel *)0x0) {
        pTVar2 = (TButtonPanel *)0x0;
      }
      else {
        pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
      }
      local_4._0_1_ = 0;
      this->object_mode_button = pTVar2;
      if (pTVar2 == (TButtonPanel *)0x0) {
        this->_padding_ = 1;
      }
      else {
        TButtonPanel::setup(pTVar2,(TDrawArea *)this->_padding_,(TPanel *)this,0x34,0,0x32,0x1e,
                            DrawTextA,param_10,NotifyAction,0);
        TButtonPanel::set_text_info(this->object_mode_button,s_Obj,param_7,param_8,param_9,-1,-1);
        TButtonPanel::set_text(this->object_mode_button,1,s_<Obj>);
        pTVar2 = (TButtonPanel *)operator_new(0x2b8);
        local_4._0_1_ = 3;
        if (pTVar2 == (TButtonPanel *)0x0) {
          pTVar2 = (TButtonPanel *)0x0;
        }
        else {
          pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
        }
        local_4._0_1_ = 0;
        this->move_mode_button = pTVar2;
        if (pTVar2 == (TButtonPanel *)0x0) {
          this->_padding_ = 1;
        }
        else {
          TButtonPanel::setup(pTVar2,(TDrawArea *)this->_padding_,(TPanel *)this,0x68,0,0x32,0x1e,
                              DrawTextA,param_10,NotifyAction,0);
          TButtonPanel::set_text_info(this->move_mode_button,&s_Move,param_7,param_8,param_9,-1,-1);
          TButtonPanel::set_text(this->move_mode_button,1,s_<Move>);
          pTVar2 = (TButtonPanel *)operator_new(0x2b8);
          local_4._0_1_ = 4;
          if (pTVar2 == (TButtonPanel *)0x0) {
            pTVar2 = (TButtonPanel *)0x0;
          }
          else {
            pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
          }
          local_4._0_1_ = 0;
          this->delete_mode_button = pTVar2;
          if (pTVar2 == (TButtonPanel *)0x0) {
            this->_padding_ = 1;
          }
          else {
            TButtonPanel::setup(pTVar2,(TDrawArea *)this->_padding_,(TPanel *)this,0x9c,0,0x32,0x1e,
                                DrawTextA,param_10,NotifyAction,0);
            TButtonPanel::set_text_info
                      (this->delete_mode_button,s_Del,param_7,param_8,param_9,-1,-1);
            TButtonPanel::set_text(this->delete_mode_button,1,s_<Del>);
            pTVar2 = (TButtonPanel *)operator_new(0x2b8);
            local_4._0_1_ = 5;
            if (pTVar2 == (TButtonPanel *)0x0) {
              pTVar2 = (TButtonPanel *)0x0;
            }
            else {
              pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
            }
            local_4._0_1_ = 0;
            this->terrain_mode_button = pTVar2;
            if (pTVar2 == (TButtonPanel *)0x0) {
              this->_padding_ = 1;
            }
            else {
              TButtonPanel::setup(pTVar2,(TDrawArea *)this->_padding_,(TPanel *)this,0xd0,0,0x32,
                                  0x1e,DrawTextA,param_10,NotifyAction,0);
              TButtonPanel::set_text_info
                        (this->terrain_mode_button,s_Terr,param_7,param_8,param_9,-1,-1);
              TButtonPanel::set_text(this->terrain_mode_button,1,s_<Terr>);
              (**(code **)(this->terrain_mode_button->_padding_ + 0x14))(0);
              pTVar2 = (TButtonPanel *)operator_new(0x2b8);
              local_4._0_1_ = 6;
              if (pTVar2 == (TButtonPanel *)0x0) {
                pTVar2 = (TButtonPanel *)0x0;
              }
              else {
                pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
              }
              local_4._0_1_ = 0;
              this->elevation_mode_button = pTVar2;
              if (pTVar2 == (TButtonPanel *)0x0) {
                this->_padding_ = 1;
              }
              else {
                TButtonPanel::setup(pTVar2,(TDrawArea *)this->_padding_,(TPanel *)this,0x104,0,0x32,
                                    0x1e,DrawTextA,param_10,NotifyAction,0);
                TButtonPanel::set_text_info
                          (this->elevation_mode_button,s_Elev,param_7,param_8,param_9,-1,-1);
                TButtonPanel::set_text(this->elevation_mode_button,1,s_<Elev>);
                (**(code **)(this->elevation_mode_button->_padding_ + 0x14))(0);
                mode_buttons[3] = this->move_mode_button;
                mode_buttons[2] = this->object_mode_button;
                mode_buttons[1] = this->game_mode_button;
                mode_buttons[5] = this->terrain_mode_button;
                mode_buttons[4] = this->delete_mode_button;
                TButtonPanel::set_radio_info(mode_buttons[1],mode_buttons + 1,6);
                TButtonPanel::set_radio_info(this->object_mode_button,mode_buttons + 1,6);
                TButtonPanel::set_radio_info(this->move_mode_button,mode_buttons + 1,6);
                TButtonPanel::set_radio_info(this->delete_mode_button,mode_buttons + 1,6);
                TButtonPanel::set_radio_info(this->terrain_mode_button,mode_buttons + 1,6);
                TButtonPanel::set_radio_info(this->elevation_mode_button,mode_buttons + 1,6);
                pTVar2 = (TButtonPanel *)operator_new(0x2b8);
                local_4._0_1_ = 7;
                if (pTVar2 == (TButtonPanel *)0x0) {
                  pTVar2 = (TButtonPanel *)0x0;
                }
                else {
                  pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
                }
                local_4 = (uint)local_4._1_3_ << 8;
                this->command_button = pTVar2;
                if (pTVar2 == (TButtonPanel *)0x0) {
                  this->_padding_ = 1;
                }
                else {
                  TButtonPanel::setup(pTVar2,(TDrawArea *)this->_padding_,(TPanel *)this,0x13a,0,
                                      0x32,0x1e,DrawTextA,param_10,NotifyAction,0);
                  TButtonPanel::set_text_info
                            (this->command_button,s_Cmd,param_7,param_8,param_9,-1,-1);
                  TButtonPanel::set_text(this->command_button,1,s_<Cmd>);
                  TButtonPanel::set_state_info(this->command_button,2);
                  game_mode_changed(this,rge_base_game->game_mode,rge_base_game->game_mode);
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00489e70
void * __thiscall
RGE_Panel_Tool_Box::_vector_deleting_destructor_(RGE_Panel_Tool_Box *this,uint param_1)
{
  ~RGE_Panel_Tool_Box(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Panel_Tool_Box
// Address: 00489e90
void __thiscall RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box(RGE_Panel_Tool_Box *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055e758;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->game_mode_button != (TButtonPanel *)0x0) {
    (**(code **)this->game_mode_button->_padding_)(1);
  }
  if (this->object_mode_button != (TButtonPanel *)0x0) {
    (**(code **)this->object_mode_button->_padding_)(1);
  }
  if (this->move_mode_button != (TButtonPanel *)0x0) {
    (**(code **)this->move_mode_button->_padding_)(1);
  }
  if (this->delete_mode_button != (TButtonPanel *)0x0) {
    (**(code **)this->delete_mode_button->_padding_)(1);
  }
  if (this->terrain_mode_button != (TButtonPanel *)0x0) {
    (**(code **)this->terrain_mode_button->_padding_)(1);
  }
  if (this->elevation_mode_button != (TButtonPanel *)0x0) {
    (**(code **)this->elevation_mode_button->_padding_)(1);
  }
  if (this->command_button != (TButtonPanel *)0x0) {
    (**(code **)this->command_button->_padding_)(1);
  }
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: action
// Address: 00489f50
// [HELPER] s_Object_List_Dialog: "Object List Dialog"
// [HELPER] s_Terrain_List_Dialog: "Terrain List Dialog"
long __thiscall
RGE_Panel_Tool_Box::action
          (RGE_Panel_Tool_Box *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  TPanel **ppTVar1;
  byte bVar2;
  short sVar3;
  RGE_Dialog_List *this_00;
  TPanel *pTVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  byte *pbVar8;
  RGE_Player *this_01;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  byte *pbVar9;
  undefined4 *unaff_FS_OFFSET;
  bool bVar10;
  int iVar11;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e77b;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 != (TPanel *)0x0) {
    if (((TButtonPanel *)param_1 == this->game_mode_button) && (param_2 == 1)) {
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
      *unaff_FS_OFFSET = unaff_ESI;
      return 1;
    }
    if (((TButtonPanel *)param_1 == this->object_mode_button) && (param_2 == 1)) {
      this_00 = (RGE_Dialog_List *)operator_new(0x4bc);
      local_4 = 0;
      if (this_00 == (RGE_Dialog_List *)0x0) {
        pTVar4 = (TPanel *)0x0;
      }
      else {
        pTVar4 = (TPanel *)RGE_Dialog_List::RGE_Dialog_List(this_00,&s_Object_List_Dialog);
      }
      local_4 = 0xffffffff;
      this->dialog = pTVar4;
      if (pTVar4 != (TPanel *)0x0) {
        pcVar5 = TPanel::get_string((TPanel *)this,0x232a);
        iVar11 = 1;
        lVar6 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)this->screen_panel);
        pcVar7 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)this->screen_panel);
        iVar11 = RGE_Dialog_List::setup
                           ((RGE_Dialog_List *)this->dialog,this->screen_panel,pcVar7,lVar6,iVar11,
                            pcVar5);
        if (iVar11 == 0) {
          if (this->dialog != (TPanel *)0x0) {
            (**(code **)this->dialog->_padding_)(1);
          }
          this->dialog = (TPanel *)0x0;
          *unaff_FS_OFFSET = local_c;
          return 1;
        }
      }
    }
    else {
      if (((TButtonPanel *)param_1 == this->move_mode_button) && (param_2 == 1)) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(0x12,0);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
      if (((TButtonPanel *)param_1 == this->delete_mode_button) && (param_2 == 1)) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(0xe,0);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
      if (((TButtonPanel *)param_1 == this->elevation_mode_button) && (param_2 == 1)) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(3,0);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
      if (((TButtonPanel *)param_1 == this->command_button) && (param_2 == 1)) {
        if (rge_base_game->prog_mode == 4) {
          (**(code **)(rge_base_game->_padding_ + 0xc))(6);
          rge_base_game->world->temp_pause = '\x01';
          *unaff_FS_OFFSET = unaff_EBP;
          return 1;
        }
        (**(code **)(rge_base_game->_padding_ + 0xc))(4);
        *unaff_FS_OFFSET = unaff_EBP;
        return 1;
      }
      ppTVar1 = &this->dialog;
      if (param_1 != this->dialog) goto LAB_0048a307;
      pbVar9 = &s_Object_List_Dialog;
      pbVar8 = (byte *)TPanel::panelName(this->dialog);
      do {
        bVar2 = *pbVar8;
        bVar10 = bVar2 < *pbVar9;
        if (bVar2 != *pbVar9) {
LAB_0048a1c9:
          iVar11 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0048a1ce;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar10 = bVar2 < pbVar9[1];
        if (bVar2 != pbVar9[1]) goto LAB_0048a1c9;
        pbVar8 = pbVar8 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar2 != 0);
      iVar11 = 0;
LAB_0048a1ce:
      if (iVar11 == 0) {
        if (param_2 == 1) {
          sVar3 = (**(code **)((*ppTVar1)->_padding_ + 0x130))();
          rge_base_game->master_obj_id = sVar3;
          RGE_Base_Game::delete_dialog(rge_base_game,ppTVar1);
          (**(code **)(rge_base_game->_padding_ + 0x10))(1,0);
          this_01 = RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(this_01);
          *unaff_FS_OFFSET = unaff_ESI;
          return 1;
        }
      }
      else {
        pbVar9 = &s_Terrain_List_Dialog;
        pbVar8 = (byte *)TPanel::panelName(*ppTVar1);
        do {
          bVar2 = *pbVar8;
          bVar10 = bVar2 < *pbVar9;
          if (bVar2 != *pbVar9) {
LAB_0048a26c:
            iVar11 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_0048a271;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar8[1];
          bVar10 = bVar2 < pbVar9[1];
          if (bVar2 != pbVar9[1]) goto LAB_0048a26c;
          pbVar8 = pbVar8 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar2 != 0);
        iVar11 = 0;
LAB_0048a271:
        if (iVar11 != 0) goto LAB_0048a2ee;
        if (param_2 == 1) {
          sVar3 = (**(code **)((*ppTVar1)->_padding_ + 0x130))();
          rge_base_game->terrain_id = sVar3;
          RGE_Base_Game::delete_dialog(rge_base_game,ppTVar1);
          (**(code **)(rge_base_game->_padding_ + 0x10))(2,0);
          *unaff_FS_OFFSET = unaff_ESI;
          return 1;
        }
      }
      if (param_2 == 2) {
        RGE_Base_Game::delete_dialog(rge_base_game,ppTVar1);
        game_mode_changed(this,rge_base_game->game_mode,rge_base_game->game_mode);
      }
    }
LAB_0048a2ee:
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
LAB_0048a307:
  *unaff_FS_OFFSET = local_c;
  return 0;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 0048a320
long __thiscall
RGE_Panel_Tool_Box::key_down_action
          (RGE_Panel_Tool_Box *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  RGE_Static_Object *pRVar1;
  uchar uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  RGE_Map *this_00;
  long y2;
  long x2;
  long y1;
  long x1;
  long local_4;
  
  iVar3 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = rge_base_game->prog_mode;
  if (((iVar3 != 4) && (iVar3 != 6)) && (iVar3 != 7)) {
    return 0;
  }
  if (param_1 == 0x21) {
    if (rge_base_game->game_mode != 3) {
      return 0;
    }
    RGE_View::get_selection_area(this->view,&local_4,&x1,&y1,&x2,1);
    RGE_Map::set_elev(rge_base_game->world->map,(short)local_4,(short)x1,(short)y1,(short)x2,'\0',1,
                      '\x01');
    this_00 = rge_base_game->world->map;
  }
  else {
    if (param_1 != 0x22) {
      if (param_1 != 0x2e) {
        return 0;
      }
      if (rge_base_game->game_mode != 0x12) {
        return 0;
      }
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      pRVar1 = pRVar4->selected_obj;
      if (pRVar1 == (RGE_Static_Object *)0x0) {
        return 1;
      }
      if (pRVar1->sprite_list == (RGE_Active_Sprite_List *)0x0) {
        if (pRVar1->sprite == (RGE_Sprite *)0x0) {
          uVar2 = '\x14';
        }
        else {
          uVar2 = RGE_Sprite::get_lowest_draw_level(pRVar1->sprite);
        }
      }
      else {
        uVar2 = RGE_Active_Sprite_List::get_lowest_draw_level(pRVar1->sprite_list);
      }
      (**(code **)(pRVar1->_padding_ + 0x68))();
      if (uVar2 != '\0') {
        return 1;
      }
      (**(code **)(this->view->_padding_ + 0x20))(2);
      return 1;
    }
    if (rge_base_game->game_mode != 3) {
      return 0;
    }
    RGE_View::get_selection_area(this->view,&local_4,&x1,&y1,&x2,1);
    RGE_Map::set_elev(rge_base_game->world->map,(short)local_4,(short)x1,(short)y1,(short)x2,'\0',-1
                      ,'\x01');
    this_00 = rge_base_game->world->map;
  }
  RGE_Map::clean_elevation(this_00,local_4,x1,y1,x2,'\b');
  (**(code **)(this->view->_padding_ + 0x20))(2);
  if (this->map != (RGE_Diamond_Map *)0x0) {
    (**(code **)(this->map->_padding_ + 0x20))(2);
  }
  return 1;
}

// --------------------------------------------------

// Function: game_mode_changed
// Address: 0048a520
void __thiscall
RGE_Panel_Tool_Box::game_mode_changed(RGE_Panel_Tool_Box *this,int param_1,int param_2)
{
  RGE_Player *pRVar1;
  TButtonPanel *this_00;
  
  switch(param_1) {
  case 1:
  case 0x12:
    pRVar1 = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::unselect_object(pRVar1);
    break;
  case 2:
  case 3:
    RGE_View::set_selection_area(this->view,-1,-1,-1,-1);
  }
  switch(param_2) {
  case 1:
    TButtonPanel::set_radio_button(this->object_mode_button);
    return;
  case 2:
    this_00 = this->terrain_mode_button;
    break;
  case 3:
    this_00 = this->elevation_mode_button;
    break;
  default:
    TButtonPanel::set_radio_button(this->game_mode_button);
    return;
  case 0xe:
    TButtonPanel::set_radio_button(this->delete_mode_button);
    return;
  case 0x12:
    TButtonPanel::set_radio_button(this->move_mode_button);
    return;
  }
  TButtonPanel::set_radio_button(this_00);
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(pRVar1);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0048a640
void __thiscall RGE_Panel_Tool_Box::draw(RGE_Panel_Tool_Box *this)
{
  int iVar1;
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,0);
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

