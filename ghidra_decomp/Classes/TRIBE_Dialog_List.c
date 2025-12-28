// Class: TRIBE_Dialog_List
// Size:  0x4BC
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
// [56] draw_background
// [57] set_ideal_size
// [58] create_button
// [59] create_button
// [60] create_check_box
// [61] create_radio_button
// [62] create_text
// [63] create_text
// [64] create_text
// [65] create_input
// [66] create_edit
// [67] create_drop_down
// [68] create_list
// [69] create_scrollbar
// [70] create_auto_scrollbar
// [71] create_vert_slider
// [72] create_horz_slider
// [73] position_panel
// [74] setup
// [75] setup
// [76] get_list_id
// [77] get_list_name
// [78] create_list
// [79] get_cur_id
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Dialog_List
// Address: 0050b450
/* public: __thiscall TRIBE_Dialog_List::TRIBE_Dialog_List(char *) */

TRIBE_Dialog_List * __thiscall
TRIBE_Dialog_List::TRIBE_Dialog_List(TRIBE_Dialog_List *this,char *param_1)
{
  RGE_Dialog_List::RGE_Dialog_List((RGE_Dialog_List *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0050b470
/* public: virtual void * __thiscall TRIBE_Dialog_List::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Dialog_List::_scalar_deleting_destructor_(TRIBE_Dialog_List *this,uint param_1)
{
  ~TRIBE_Dialog_List(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Dialog_List
// Address: 0050b490
/* public: virtual __thiscall TRIBE_Dialog_List::~TRIBE_Dialog_List(void) */

void __thiscall TRIBE_Dialog_List::~TRIBE_Dialog_List(TRIBE_Dialog_List *this)
{
  int iVar1;
  int iVar2;
  
  *(undefined ***)this = &RGE_Dialog_List::_vftable_;
  if (*(int *)&this->field_0x4b8 != 0) {
    iVar2 = 0;
    if (0 < *(short *)&this->field_0x4b0) {
      do {
        iVar1 = *(int *)(*(int *)&this->field_0x4b8 + iVar2 * 4);
        if (iVar1 != 0) {
          free(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(short *)&this->field_0x4b0);
    }
    free(*(undefined4 *)&this->field_0x4b8);
    *(undefined4 *)&this->field_0x4b8 = 0;
  }
  if (*(int *)&this->field_0x4b4 != 0) {
    free(*(int *)&this->field_0x4b4);
    *(undefined4 *)&this->field_0x4b4 = 0;
  }
  TListDialog::~TListDialog((TListDialog *)this);
  return;
}

// --------------------------------------------------

// Function: create_list
// Address: 0050b4a0
/* protected: virtual int __thiscall TRIBE_Dialog_List::create_list(void) */

int __thiscall TRIBE_Dialog_List::create_list(TRIBE_Dialog_List *this)
{
  int iVar1;
  
  iVar1 = *(int *)&this->field_0x4ac;
  if (iVar1 == 100) {
    iVar1 = create_build_list(this);
    return iVar1;
  }
  if (iVar1 != 0x65) {
    if (iVar1 != 0x66) {
      iVar1 = RGE_Dialog_List::create_list((RGE_Dialog_List *)this);
      return iVar1;
    }
    iVar1 = create_research_list(this);
    return iVar1;
  }
  iVar1 = create_train_list(this);
  return iVar1;
}

// --------------------------------------------------

// Function: create_build_list
// Address: 0050b4d0
/* WARNING: Variable defined which should be unmapped: item_list */
/* protected: int __thiscall TRIBE_Dialog_List::create_build_list(void) */

int __thiscall TRIBE_Dialog_List::create_build_list(TRIBE_Dialog_List *this)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this_00;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *item_list;
  short item_num;
  short local_8 [4];
  
  this_00 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if (this_00 == (TRIBE_Player *)0x0) {
    return 0;
  }
  iVar3 = RGE_Player::is_group_selected((RGE_Player *)this_00,4);
  if (iVar3 == 0) {
    return 0;
  }
                    /* language.dll match for 0x76: "B" */
  _item_num = (Item_Avail *)0x0;
  local_8[0] = 0;
  local_8[1] = 0;
  TRIBE_Player::interface_item_avail(this_00,(Item_Avail **)&item_num,local_8,0x76);
  sVar2 = (short)local_8._0_4_;
  if (sVar2 == 0) {
    return 0;
  }
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  *(short *)&this->field_0x4b0 = sVar2;
  iVar3 = calloc((int)sVar2,0x66);
  *(int *)&this->field_0x4b4 = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  if (0 < *(short *)&this->field_0x4b0) {
    do {
      iVar3 = (int)sVar6;
      *(short *)(*(int *)&this->field_0x4b4 + 100 + iVar3 * 0x66) = _item_num[iVar3].id;
      uVar4 = 0xffffffff;
      pcVar7 = _item_num[iVar3].name;
      do {
        pcVar8 = pcVar7;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar7 = pcVar8 + -uVar4;
      pcVar8 = (char *)(*(int *)&this->field_0x4b4 + iVar3 * 0x66);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      sVar6 = sVar6 + 1;
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
    } while (sVar6 < *(short *)&this->field_0x4b0);
  }
  return 1;
}

// --------------------------------------------------

// Function: create_train_list
// Address: 0050b5e0
/* WARNING: Variable defined which should be unmapped: item_list */
/* protected: int __thiscall TRIBE_Dialog_List::create_train_list(void) */

int __thiscall TRIBE_Dialog_List::create_train_list(TRIBE_Dialog_List *this)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this_00;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *item_list;
  short item_num;
  short local_8 [4];
  
  this_00 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if ((this_00 != (TRIBE_Player *)0x0) && (this_00->_padding_ != 0)) {
    iVar3 = RGE_Player::own_selected((RGE_Player *)this_00);
    if (iVar3 != 0) {
      _item_num = (Item_Avail *)0x0;
      local_8[0] = 0;
      local_8[1] = 0;
      TRIBE_Player::interface_item_avail
                (this_00,(Item_Avail **)&item_num,local_8,
                 *(short *)(*(int *)(this_00->_padding_ + 8) + 0x10));
      sVar2 = (short)local_8._0_4_;
      if (sVar2 != 0) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
        *(short *)&this->field_0x4b0 = sVar2;
        iVar3 = calloc((int)sVar2,0x66);
        *(int *)&this->field_0x4b4 = iVar3;
        if (iVar3 != 0) {
          if (0 < *(short *)&this->field_0x4b0) {
            do {
              iVar3 = (int)sVar6;
              *(short *)(*(int *)&this->field_0x4b4 + 100 + iVar3 * 0x66) = _item_num[iVar3].id;
              uVar4 = 0xffffffff;
              pcVar7 = _item_num[iVar3].name;
              do {
                pcVar8 = pcVar7;
                if (uVar4 == 0) break;
                uVar4 = uVar4 - 1;
                pcVar8 = pcVar7 + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar8;
              } while (cVar1 != '\0');
              uVar4 = ~uVar4;
              pcVar7 = pcVar8 + -uVar4;
              pcVar8 = (char *)(*(int *)&this->field_0x4b4 + iVar3 * 0x66);
              for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
              }
              sVar6 = sVar6 + 1;
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *pcVar8 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
              }
            } while (sVar6 < *(short *)&this->field_0x4b0);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: create_research_list
// Address: 0050b700
/* WARNING: Variable defined which should be unmapped: item_list */
/* protected: int __thiscall TRIBE_Dialog_List::create_research_list(void) */

int __thiscall TRIBE_Dialog_List::create_research_list(TRIBE_Dialog_List *this)
{
  char cVar1;
  short sVar2;
  TRIBE_Player *this_00;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  char *pcVar7;
  char *pcVar8;
  Item_Avail *item_list;
  short item_num;
  short local_8 [4];
  
  this_00 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  sVar6 = 0;
  if ((this_00 != (TRIBE_Player *)0x0) && (this_00->_padding_ != 0)) {
    iVar3 = RGE_Player::own_selected((RGE_Player *)this_00);
    if (iVar3 != 0) {
      _item_num = (Item_Avail *)0x0;
      local_8[0] = 0;
      local_8[1] = 0;
      TRIBE_Player::interface_tech_avail
                (this_00,(Item_Avail **)&item_num,local_8,
                 *(short *)(*(int *)(this_00->_padding_ + 8) + 0x10));
      sVar2 = (short)local_8._0_4_;
      if (sVar2 != 0) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
        *(short *)&this->field_0x4b0 = sVar2;
        iVar3 = calloc((int)sVar2,0x66);
        *(int *)&this->field_0x4b4 = iVar3;
        if (iVar3 != 0) {
          if (0 < *(short *)&this->field_0x4b0) {
            do {
              iVar3 = (int)sVar6;
              *(short *)(*(int *)&this->field_0x4b4 + 100 + iVar3 * 0x66) = _item_num[iVar3].id;
              uVar4 = 0xffffffff;
              pcVar7 = _item_num[iVar3].name;
              do {
                pcVar8 = pcVar7;
                if (uVar4 == 0) break;
                uVar4 = uVar4 - 1;
                pcVar8 = pcVar7 + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar8;
              } while (cVar1 != '\0');
              uVar4 = ~uVar4;
              pcVar7 = pcVar8 + -uVar4;
              pcVar8 = (char *)(*(int *)&this->field_0x4b4 + iVar3 * 0x66);
              for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
              }
              sVar6 = sVar6 + 1;
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *pcVar8 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
              }
            } while (sVar6 < *(short *)&this->field_0x4b0);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: get_cur_id
// Address: 0050b820
/* protected: virtual short __thiscall TRIBE_Dialog_List::get_cur_id(void) */

short __thiscall TRIBE_Dialog_List::get_cur_id(TRIBE_Dialog_List *this)
{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)&this->field_0x4ac;
  if (((iVar1 != 100) && (iVar1 != 0x65)) && (iVar1 != 0x66)) {
    sVar2 = RGE_Dialog_List::get_cur_id((RGE_Dialog_List *)this);
    return sVar2;
  }
  return -1;
}

// --------------------------------------------------

