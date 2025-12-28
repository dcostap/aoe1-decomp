// Class: TRIBE_Main_View
// Size:  0x380
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
// [56] pick_through_fog
// [57] pick_weight
// [58] start_scroll_view
// [59] handle_scroll_view
// [60] end_scroll_view
// [61] do_paint
// [62] draw_multi_object_outline
// [63] command_place_object
// [64] command_make_do
// [65] command_make_move
// [66] command_make_work
// [67] command_place_multi_object
// [68] `vector_deleting_destructor'
// [69] setup
// [70] set_rect
// [71] set_rect
// [72] set_color
// [73] set_active
// [74] set_positioning
// [75] set_fixed_position
// [76] set_redraw
// [77] set_overlapped_redraw
// [78] draw_setup
// [79] draw_finish
// [80] draw
// [81] draw_rect
// [82] draw_offset
// [83] draw_rect2
// [84] draw_offset2
// [85] paint
// [86] wnd_proc
// [87] handle_idle
// [88] handle_size
// [89] handle_paint
// [90] handle_key_down
// [91] handle_char
// [92] handle_command
// [93] handle_user_command
// [94] handle_timer_command
// [95] handle_scroll
// [96] handle_mouse_down
// [97] handle_mouse_move
// [98] handle_mouse_up
// [99] handle_mouse_dbl_click
// [100] mouse_move_action
// [101] mouse_left_down_action
// [102] mouse_left_hold_action
// [103] mouse_left_move_action
// [104] mouse_left_up_action
// [105] mouse_left_dbl_click_action
// [106] mouse_right_down_action
// [107] mouse_right_hold_action
// [108] mouse_right_move_action
// [109] mouse_right_up_action
// [110] mouse_right_dbl_click_action
// [111] key_down_action
// [112] char_action
// [113] action
// [114] get_true_render_rect
// [115] is_inside
// [116] set_focus
// [117] set_tab_order
// [118] set_tab_order
// [119] get_help_info
// [120] stop_sound_system
// [121] restart_sound_system
// [122] take_snapshot
// [123] handle_reactivate
// [124] draw_background
// [125] set_ideal_size
// [126] create_button
// [127] create_button
// [128] create_check_box
// [129] create_radio_button
// [130] create_text
// [131] create_text
// [132] create_text
// [133] create_input
// [134] create_edit
// [135] create_drop_down
// [136] create_list
// [137] create_scrollbar
// [138] create_auto_scrollbar
// [139] create_vert_slider
// [140] create_horz_slider
// [141] position_panel
//
// Member Layout:
// ----------------------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00495470
void * __thiscall TRIBE_Main_View::_scalar_deleting_destructor_(TRIBE_Main_View *this,uint param_1)
{
  ~TRIBE_Main_View(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Main_View
// Address: 00495490
void __thiscall TRIBE_Main_View::~TRIBE_Main_View(TRIBE_Main_View *this)
{
  TShape *this_00;
  TSpan_List_Manager *pTVar1;
  DClipInfo_List *pDVar2;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561b28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)this = &RGE_View::_vftable_;
  this_00 = *(TShape **)&this->field_0x164;
  uStack_4 = 0;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    *(undefined4 *)&this->field_0x164 = 0;
  }
  RGE_View::delete_surfaces((RGE_View *)this);
  if (*(int *)&this->field_0x15c != 0) {
    DeleteObject(*(int *)&this->field_0x15c);
    *(undefined4 *)&this->field_0x15c = 0;
  }
  if (*(int *)&this->field_0x32c != 0) {
    free(*(int *)&this->field_0x32c);
  }
  pTVar1 = *(TSpan_List_Manager **)&this->field_0x178;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = *(TSpan_List_Manager **)&this->field_0x17c;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = *(TSpan_List_Manager **)&this->field_0x180;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  if (*(int *)&this->field_0x184 != 0) {
    free(*(int *)&this->field_0x184);
  }
  if (*(int *)&this->field_0x188 != 0) {
    free(*(int *)&this->field_0x188);
  }
  if (*(int *)&this->field_0x2c8 != 0) {
    free(*(int *)&this->field_0x2c8);
  }
  if (*(int *)&this->field_0x2dc != 0) {
    free(*(int *)&this->field_0x2dc);
  }
  pDVar2 = *(DClipInfo_List **)&this->field_0x334;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  pDVar2 = *(DClipInfo_List **)&this->field_0x338;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  piVar4 = (int *)&this->field_0x2fc;
  iVar3 = 5;
  do {
    if (*piVar4 != 0) {
      free(*piVar4);
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_mode(MouseSystem,0);
    TMousePointer::set_game_enable(MouseSystem,0);
  }
  if (*(int *)&this->field_0x354 != 0) {
    free(*(int *)&this->field_0x354);
  }
  RGE_View::reset_overlay_sprites((RGE_View *)this);
  TPanel::~TPanel((TPanel *)this);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: draw_multi_object_outline
// Address: 0052caf0
void __thiscall TRIBE_Main_View::draw_multi_object_outline(TRIBE_Main_View *this)
{
  int iVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  int iVar10;
  TRIBE_Master_Building_Object *pTVar11;
  long calc_row2;
  TRIBE_Master_Building_Object *master_bldg;
  int end_col;
  int end_row;
  long calc_col1;
  int start_col;
  long calc_col2;
  int main_row;
  int main_col;
  long calc_row1;
  int start_row;
  tagPOINT point;
  RGE_Pick_Info pick_info;
  
  if (rge_base_game->master_obj_id == -1) {
    return;
  }
  end_col = *(int *)(*(int *)(*(int *)&this->field_0x100 + 0x24) + rge_base_game->master_obj_id * 4)
  ;
  if (end_col == 0) {
    return;
  }
  TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)&this->field_0x24);
  iVar3 = RGE_View::get_selection_area
                    ((RGE_View *)this,&start_col,&start_row,&main_row,(long *)&master_bldg,0);
  iVar4 = start_col;
  if (iVar3 == 0) {
    RGE_Base_Game::get_mouse_pos(rge_base_game,(tagPOINT *)&point.y);
    iVar4 = (**(code **)(*(int *)this + 0xbc))(point.y,pick_info.x);
    if (iVar4 == 0) {
      return;
    }
    uVar2 = RGE_Main_View::pick1
                      ((RGE_Main_View *)this,'(','\0',point.y - *(int *)&this->field_0x8c,
                       (int)pick_info.x - *(int *)&this->field_0x90,(RGE_Pick_Info *)&pick_info.y,
                       (RGE_Static_Object *)0x0,1);
    if (uVar2 != '3') {
      return;
    }
    RGE_Main_View::fixup_pick_info((RGE_Main_View *)this,(RGE_Pick_Info *)&pick_info.y);
    iVar4 = __ftol();
    start_col = iVar4;
    master_bldg = (TRIBE_Master_Building_Object *)__ftol();
    main_row = iVar4;
    start_row = (int)master_bldg;
  }
  iVar3 = end_col;
  calc_row1 = -1;
  main_col = -1;
  uVar9 = (int)master_bldg - start_row >> 0x1f;
  iVar10 = ((int)master_bldg - start_row ^ uVar9) - uVar9;
  uVar9 = main_row - iVar4 >> 0x1f;
  iVar5 = (main_row - iVar4 ^ uVar9) - uVar9;
  if (iVar10 == iVar5) {
    if (main_row < iVar4) {
      iVar5 = main_row;
      pTVar11 = master_bldg;
      if ((int)master_bldg < start_row) {
        do {
          draw_wall_outline(this,iVar5,(long)pTVar11,(TRIBE_Master_Building_Object *)iVar3,2);
          iVar5 = iVar5 + 1;
          pTVar11 = (TRIBE_Master_Building_Object *)((int)&pTVar11->_padding_ + 1);
        } while (iVar5 <= start_col);
        TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
        return;
      }
      if (main_row < iVar4) {
        iVar5 = start_row;
        if (main_row <= iVar4) {
          do {
            draw_wall_outline(this,iVar4,iVar5,(TRIBE_Master_Building_Object *)iVar3,2);
            iVar4 = iVar4 + -1;
            iVar5 = iVar5 + 1;
          } while (main_row <= iVar4);
          TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
          return;
        }
        goto LAB_0052d047;
      }
    }
    iVar5 = main_row;
    pTVar11 = master_bldg;
    if ((int)master_bldg < start_row) {
      do {
        draw_wall_outline(this,iVar5,(long)pTVar11,(TRIBE_Master_Building_Object *)iVar3,2);
        iVar5 = iVar5 + -1;
        pTVar11 = (TRIBE_Master_Building_Object *)((int)&pTVar11->_padding_ + 1);
      } while (start_col <= iVar5);
      TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
      return;
    }
    iVar5 = start_row;
    if (iVar4 <= main_row) {
      do {
        draw_wall_outline(this,iVar4,iVar5,(TRIBE_Master_Building_Object *)iVar3,2);
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar4 <= main_row);
      TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
      return;
    }
  }
  else if (iVar10 < iVar5) {
    end_row = main_row;
    calc_col2 = iVar4;
    if (iVar4 < main_row) {
      end_row = iVar4;
      calc_col2 = main_row;
    }
    if (start_row < (int)master_bldg) {
      point.x = start_row + 1;
      calc_col1 = (long)master_bldg;
      calc_row1 = main_row;
    }
    else if ((int)master_bldg < start_row) {
      calc_col1 = start_row + -1;
      point.x = (long)master_bldg;
      calc_row1 = main_row;
    }
    lVar7 = calc_row1;
    lVar6 = calc_col1;
    main_col = start_row;
    if ((calc_row1 == -1) ||
       (iVar3 = end_row, iVar5 = calc_col2, pTVar11 = (TRIBE_Master_Building_Object *)point.x,
       start_row < point.x)) {
      lVar6 = calc_col2;
      if (end_row <= calc_col2) {
        do {
          if ((lVar6 == iVar4) || (lVar6 == main_row)) {
            lVar7 = 2;
          }
          else {
            lVar7 = 0;
          }
          draw_wall_outline(this,lVar6,main_col,(TRIBE_Master_Building_Object *)end_col,lVar7);
          lVar6 = lVar6 + -1;
          iVar4 = start_col;
        } while (end_row <= lVar6);
      }
      if ((calc_row1 != -1) &&
         (pTVar11 = (TRIBE_Master_Building_Object *)point.x, point.x <= calc_col1)) {
        do {
          if ((pTVar11 == (TRIBE_Master_Building_Object *)start_row) ||
             (lVar6 = 1, pTVar11 == master_bldg)) {
            lVar6 = 2;
          }
          draw_wall_outline(this,calc_row1,(long)pTVar11,(TRIBE_Master_Building_Object *)end_col,
                            lVar6);
          pTVar11 = (TRIBE_Master_Building_Object *)((int)&pTVar11->_padding_ + 1);
        } while ((int)pTVar11 <= calc_col1);
      }
    }
    else {
      for (; end_row = iVar3, calc_col2 = iVar5, (int)pTVar11 <= lVar6;
          pTVar11 = (TRIBE_Master_Building_Object *)((int)&pTVar11->_padding_ + 1)) {
        if ((pTVar11 == (TRIBE_Master_Building_Object *)start_row) ||
           (lVar8 = 1, pTVar11 == master_bldg)) {
          lVar8 = 2;
        }
        draw_wall_outline(this,lVar7,(long)pTVar11,(TRIBE_Master_Building_Object *)end_col,lVar8);
        iVar4 = start_col;
        iVar3 = end_row;
        iVar5 = calc_col2;
      }
      if (iVar3 <= iVar5) {
        do {
          if ((iVar5 == iVar4) || (iVar5 == main_row)) {
            lVar6 = 2;
          }
          else {
            lVar6 = 0;
          }
          draw_wall_outline(this,iVar5,main_col,(TRIBE_Master_Building_Object *)end_col,lVar6);
          iVar5 = iVar5 + -1;
          iVar4 = start_col;
        } while (iVar3 <= iVar5);
        TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
        return;
      }
    }
  }
  else {
    pTVar11 = master_bldg;
    calc_col1 = start_row;
    if (start_row < (int)master_bldg) {
      calc_col1 = (long)master_bldg;
      pTVar11 = (TRIBE_Master_Building_Object *)start_row;
    }
    lVar6 = calc_col1;
    if (iVar4 < main_row) {
      main_col = (int)master_bldg;
      end_row = iVar4 + 1;
      calc_col2 = main_row;
    }
    else if (main_row < iVar4) {
      main_col = (int)master_bldg;
      calc_col2 = iVar4 + -1;
      end_row = main_row;
    }
    iVar10 = end_row;
    iVar3 = iVar4;
    calc_row1 = iVar4;
    point.x = (long)pTVar11;
    iVar5 = calc_col2;
    if ((main_col == -1) || (lVar7 = iVar4, iVar1 = calc_col1, calc_col2 < iVar4)) {
      for (; calc_col2 = iVar5, (int)pTVar11 <= lVar6;
          pTVar11 = (TRIBE_Master_Building_Object *)((int)&pTVar11->_padding_ + 1)) {
        if ((pTVar11 == (TRIBE_Master_Building_Object *)start_row) ||
           (lVar7 = 1, pTVar11 == master_bldg)) {
          lVar7 = 2;
        }
        draw_wall_outline(this,iVar4,(long)pTVar11,(TRIBE_Master_Building_Object *)end_col,lVar7);
        iVar3 = start_col;
        iVar5 = calc_col2;
      }
      if ((main_col != -1) && (end_row <= iVar5)) {
        do {
          if ((iVar5 == iVar3) || (iVar5 == main_row)) {
            lVar6 = 2;
          }
          else {
            lVar6 = 0;
          }
          draw_wall_outline(this,iVar5,main_col,(TRIBE_Master_Building_Object *)end_col,lVar6);
          iVar5 = iVar5 + -1;
          iVar3 = start_col;
        } while (end_row <= iVar5);
        TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
        return;
      }
    }
    else {
      for (; calc_col1 = iVar1, calc_row1 = lVar7, point.x = (long)pTVar11, iVar10 <= iVar5;
          iVar5 = iVar5 + -1) {
        if ((iVar5 == iVar4) || (iVar5 == main_row)) {
          lVar6 = 2;
        }
        else {
          lVar6 = 0;
        }
        draw_wall_outline(this,iVar5,main_col,(TRIBE_Master_Building_Object *)end_col,lVar6);
        iVar4 = start_col;
        lVar7 = calc_row1;
        pTVar11 = (TRIBE_Master_Building_Object *)point.x;
        iVar1 = calc_col1;
      }
      if ((int)pTVar11 <= iVar1) {
        do {
          if ((pTVar11 == (TRIBE_Master_Building_Object *)start_row) ||
             (lVar6 = 1, pTVar11 == master_bldg)) {
            lVar6 = 2;
          }
          draw_wall_outline(this,lVar7,(long)pTVar11,(TRIBE_Master_Building_Object *)end_col,lVar6);
          pTVar11 = (TRIBE_Master_Building_Object *)((int)&pTVar11->_padding_ + 1);
        } while ((int)pTVar11 <= iVar1);
        TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
        return;
      }
    }
  }
LAB_0052d047:
  TDrawArea::SetClipRect(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0);
  return;
}

// --------------------------------------------------

// Function: draw_wall_outline
// Address: 0052d060
int __thiscall
TRIBE_Main_View::draw_wall_outline
          (TRIBE_Main_View *this,long param_1,long param_2,TRIBE_Master_Building_Object *param_3,
          long param_4)
{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  RGE_Player *pRVar7;
  int unaff_EDI;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short x1;
  short y2;
  short x4;
  short y3;
  short x2;
  short y1;
  short scr_y;
  short local_12;
  short scr_x;
  short x3;
  short y4;
  short local_4 [2];
  
  iVar4 = RGE_View::get_tile_screen_coords
                    ((RGE_View *)this,(short)param_1,(short)param_2,&x3,&scr_x,0);
  if (iVar4 != 0) {
    fVar1 = (float)param_1 - _DAT_00577450;
    fVar2 = (float)param_2 - _DAT_00577450;
    RGE_Master_Static_Object::alignment_box
              ((RGE_Master_Static_Object *)param_3,*(RGE_Game_World **)&this->field_0xfc,fVar1,fVar2
               ,&x4,&local_12,&scr_y,&y3,&y4,&y1,&x2,local_4);
    iVar14 = 1;
    iVar4 = param_3->_padding_;
    iVar13 = 1;
    iVar12 = 1;
    uVar11 = 1;
    cVar3 = (**(code **)(iVar4 + 0x20))
                      (*(undefined4 *)&this->field_0x100,fVar1,fVar2,0,1,(char)param_3->_padding_,0,
                       1,1,1);
    if (cVar3 == '\0') {
      fog_next_shape = 5;
    }
    else {
      uVar5 = *(uint *)(*(int *)&this->field_0xfc + 4) >> 7 & 7;
      if (uVar5 < 4) {
        iVar6 = uVar5 + 0x24;
      }
      else {
        iVar6 = 0x2c - uVar5;
      }
      fog_next_shape = iVar6 << 4 | 9;
    }
    if (param_3->_padding_ != 0) {
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0;
      iVar13 = iVar13 + ((int)(short)uVar11 - (int)(short)iVar14) / 2 + iVar14;
      iVar12 = iVar12 + ((int)(short)((uint)uVar11 >> 0x10) - (int)(short)unaff_EDI) / 2 + unaff_EDI
      ;
      iVar14 = _x2 + 1;
      SDI_Draw_Line = (int)(short)iVar12;
      pRVar7 = RGE_Base_Game::get_player(rge_base_game);
      (**(code **)(iVar4 + 0x34))
                (*(undefined4 *)&this->field_0x20,iVar13,iVar12,pRVar7->color_table,iVar14,uVar8,
                 uVar9,uVar10);
    }
  }
  fog_next_shape = 0;
  return 1;
}

// --------------------------------------------------

// Function: command_place_object
// Address: 0052d1f0
int __thiscall
TRIBE_Main_View::command_place_object(TRIBE_Main_View *this,long param_1,long param_2,int param_3)
{
  short sVar1;
  int *piVar2;
  int iVar3;
  uchar uVar4;
  char cVar5;
  int iVar6;
  undefined4 extraout_ECX;
  float fVar7;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float fVar8;
  int iVar9;
  RGE_Pick_Info pick_info;
  
  if (allow_user_commands != 0) {
    if (rge_base_game->game_mode != 7) {
      iVar6 = RGE_Main_View::command_place_object((RGE_Main_View *)this,param_1,param_2,1);
      return iVar6;
    }
    uVar4 = RGE_Main_View::pick1
                      ((RGE_Main_View *)this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                       (RGE_Static_Object *)0x0,1);
    if (uVar4 == '3') {
      RGE_Main_View::fixup_pick_info((RGE_Main_View *)this,(RGE_Pick_Info *)&pick_info.y);
      sVar1 = rge_base_game->master_obj_id;
      iVar6 = (int)sVar1;
      if ((iVar6 != -1) &&
         (piVar2 = *(int **)(*(int *)(*(int *)&this->field_0x100 + 0x24) + iVar6 * 4),
         piVar2 != (int *)0x0)) {
        iVar9 = *(int *)&this->field_0xfc;
        iVar3 = *piVar2;
        (**(code **)(iVar3 + 0x24))(&pick_info.y,&pick_info.scr_x,iVar9,0);
        fVar7 = (float)CONCAT31((int3)((uint)extraout_ECX >> 8),(char)piVar2[0x19]);
        fVar8 = 1.4013e-45;
        cVar5 = (**(code **)(iVar3 + 0x20))
                          (*(undefined4 *)&this->field_0x100,unaff_EDI,unaff_ESI,0,1,fVar7,0,1,1,1);
        if (cVar5 == '\0') {
          if ((iVar9 != 0) || (iVar6 == 0x6d)) {
            (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          }
          uVar4 = TRIBE_Player::command_make_building
                            (*(TRIBE_Player **)&this->field_0x100,sVar1,fVar8,fVar7);
          if (uVar4 != '\0') {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: command_place_multi_object
// Address: 0052d320
int __thiscall
TRIBE_Main_View::command_place_multi_object
          (TRIBE_Main_View *this,long param_1,long param_2,long param_3,long param_4,int param_5)
{
  short sVar1;
  TRIBE_Master_Building_Object *pTVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (allow_user_commands == 0) {
    return 0;
  }
  sVar1 = rge_base_game->master_obj_id;
  if (rge_base_game->prog_mode != 7) {
    if ((sVar1 != -1) &&
       (*(int *)((*(TRIBE_Player **)&this->field_0x100)->_padding_ + sVar1 * 4) != 0)) {
      uVar3 = TRIBE_Player::command_make_wall
                        (*(TRIBE_Player **)&this->field_0x100,sVar1,param_1,param_2,param_3,param_4)
      ;
      uVar6 = (uint)(uVar3 != '\0');
    }
    if (param_5 != 0) {
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    }
    goto LAB_0052d4c7;
  }
  if ((sVar1 == -1) ||
     (pTVar2 = *(TRIBE_Master_Building_Object **)
                (*(int *)(*(int *)&this->field_0x100 + 0x24) + sVar1 * 4),
     pTVar2 == (TRIBE_Master_Building_Object *)0x0)) goto LAB_0052d4c7;
  uVar6 = param_4 - param_2 >> 0x1f;
  iVar4 = (param_4 - param_2 ^ uVar6) - uVar6;
  uVar6 = param_3 - param_1 >> 0x1f;
  iVar5 = (param_3 - param_1 ^ uVar6) - uVar6;
  if (iVar4 == iVar5) {
LAB_0052d458:
    place_line_of_walls(this,*(TRIBE_Player **)&this->field_0x100,pTVar2,param_1,param_2,param_3,
                        param_4);
  }
  else if (iVar4 < iVar5) {
    place_line_of_walls(this,*(TRIBE_Player **)&this->field_0x100,pTVar2,param_1,param_2,param_3,
                        param_2);
    if (param_2 < param_4) {
      place_line_of_walls(this,*(TRIBE_Player **)&this->field_0x100,pTVar2,param_3,param_2 + 1,
                          param_3,param_4);
      uVar6 = 1;
      goto LAB_0052d4c7;
    }
    if (param_4 < param_2) {
      param_2 = param_2 + -1;
      param_1 = param_3;
      goto LAB_0052d458;
    }
  }
  else {
    place_line_of_walls(this,*(TRIBE_Player **)&this->field_0x100,pTVar2,param_1,param_2,param_1,
                        param_4);
    if (param_1 < param_3) {
      place_line_of_walls(this,*(TRIBE_Player **)&this->field_0x100,pTVar2,param_1 + 1,param_4,
                          param_3,param_4);
      uVar6 = 1;
      goto LAB_0052d4c7;
    }
    if (param_3 < param_1) {
      place_line_of_walls(this,*(TRIBE_Player **)&this->field_0x100,pTVar2,param_1 + -1,param_4,
                          param_3,param_4);
      uVar6 = 1;
      goto LAB_0052d4c7;
    }
  }
  uVar6 = 1;
LAB_0052d4c7:
  RGE_View::set_selection_area((RGE_View *)this,-1,-1,-1,-1);
  (**(code **)(*(int *)this + 0x20))(1);
  return uVar6;
}

// --------------------------------------------------

// Function: place_line_of_walls
// Address: 0052d4f0
void __thiscall
TRIBE_Main_View::place_line_of_walls
          (TRIBE_Main_View *this,TRIBE_Player *param_1,TRIBE_Master_Building_Object *param_2,
          int param_3,int param_4,int param_5,int param_6)
{
  code *pcVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  int x_skip;
  int y_skip;
  int local_8;
  
  iVar4 = param_3;
  if (param_3 == param_5) {
    y_skip = 0;
  }
  else {
    y_skip = ((param_5 <= param_3) - 1 & 2) - 1;
  }
  if (param_4 == param_6) {
    local_8 = 0;
  }
  else {
    local_8 = ((param_6 <= param_4) - 1 & 2) - 1;
  }
  param_3 = param_4;
  param_4 = iVar4;
  pcVar1 = *(code **)(param_2->_padding_ + 0x20);
  while( true ) {
    fVar2 = (float)param_4 - _DAT_00577450;
    fVar3 = (float)param_3 - _DAT_00577450;
    cVar5 = (*pcVar1)(param_1,fVar2,fVar3,0,1,(char)param_2->_padding_,0,1,1,1);
    if (cVar5 == '\0') {
      (**(code **)(param_1->_padding_ + 0x94))((int)(short)param_2->_padding_,fVar2,fVar3,0,1);
    }
    if ((param_4 == param_5) && (param_3 == param_6)) break;
    param_4 = param_4 + y_skip;
    param_3 = param_3 + local_8;
  }
  return;
}

// --------------------------------------------------

// Function: mouse_left_up_action
// Address: 0052d600
long __thiscall
TRIBE_Main_View::mouse_left_up_action
          (TRIBE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  long lVar3;
  RGE_Static_Object *pRVar4;
  RGE_Pick_Info pick_info;
  
  iVar2 = rge_base_game->prog_mode;
  if ((((iVar2 != 4) && (iVar2 != 6)) && (iVar2 != 7)) && (iVar2 != 5)) {
    return 0;
  }
  iVar2 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar2 != 0) {
switchD_0052d657_default:
    lVar3 = RGE_Main_View::mouse_left_up_action
                      ((RGE_Main_View *)this,param_1,param_2,param_3,param_4);
    return lVar3;
  }
  switch(rge_base_game->game_mode) {
  case 100:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    uVar1 = RGE_Main_View::pick1
                      ((RGE_Main_View *)this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                       (RGE_Static_Object *)0x0,1);
    if (uVar1 == '3') {
      RGE_Main_View::fixup_pick_info((RGE_Main_View *)this,(RGE_Pick_Info *)&pick_info.y);
      uVar1 = TRIBE_Player::command_attack_ground
                        (*(TRIBE_Player **)&this->field_0x100,pick_info.y,(float)pick_info._8_4_);
      if (uVar1 != '\0') {
        RGE_Main_View::reset_display_object_selection((RGE_Main_View *)this,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)this,rge_base_game->shapes[2],0,*(int *)&this->field_0x130 + param_1,
                   *(int *)&this->field_0x134 + param_2,0,0xf,(uchar *)0x0,2,0x7d);
        (**(code **)(*(int *)this + 0x20))(1);
        goto LAB_0052d7cc;
      }
    }
    goto LAB_0052d7bf;
  case 0x65:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    iVar2 = (**(code **)(*(int *)this + 0x100))(param_1,param_2,0,0x68);
    if (iVar2 != 0) goto LAB_0052d7cc;
LAB_0052d7bf:
    RGE_Base_Game::play_sound(rge_base_game,3);
LAB_0052d7cc:
    (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    return 1;
  case 0x66:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    iVar2 = (**(code **)(*(int *)this + 0x100))(param_1,param_2,0,0x69);
    goto joined_r0x0052d81c;
  case 0x67:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    iVar2 = (**(code **)(*(int *)this + 0x100))(param_1,param_2,0,7);
joined_r0x0052d81c:
    if (iVar2 != 0) goto LAB_0052d74d;
    break;
  case 0x68:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    pRVar4 = RGE_Main_View::pick_best_target((RGE_Main_View *)this,param_1,param_2,(int *)0x0,-1);
    if ((pRVar4 != (RGE_Static_Object *)0x0) &&
       (uVar1 = TRIBE_Player::command_make_repair(*(TRIBE_Player **)&this->field_0x100,pRVar4),
       uVar1 != '\0')) {
      RGE_View::display_object_selection((RGE_View *)this,pRVar4->id,0x5dc,2,2);
      RGE_View::reset_overlay_sprites((RGE_View *)this);
      (**(code **)(*(int *)this + 0x20))(1);
      goto LAB_0052d74d;
    }
    break;
  case 0x69:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    uVar1 = RGE_Main_View::pick1
                      ((RGE_Main_View *)this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                       (RGE_Static_Object *)0x0,1);
    if (uVar1 == '3') {
      RGE_Main_View::fixup_pick_info((RGE_Main_View *)this,(RGE_Pick_Info *)&pick_info.y);
      uVar1 = TRIBE_Player::command_make_unload
                        (*(TRIBE_Player **)&this->field_0x100,pick_info.y,(float)pick_info._8_4_);
      if (uVar1 != '\0') {
        RGE_Main_View::reset_display_object_selection((RGE_Main_View *)this,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)this,rge_base_game->shapes[2],0,*(int *)&this->field_0x130 + param_1,
                   *(int *)&this->field_0x134 + param_2,0,0xf,(uchar *)0x0,2,0x7d);
        (**(code **)(*(int *)this + 0x20))(1);
        goto LAB_0052d74d;
      }
    }
    break;
  default:
    goto switchD_0052d657_default;
  }
  RGE_Base_Game::play_sound(rge_base_game,3);
LAB_0052d74d:
  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
  return 1;
}

// --------------------------------------------------

// Function: mouse_right_up_action
// Address: 0052d970
long __thiscall
TRIBE_Main_View::mouse_right_up_action
          (TRIBE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  long lVar3;
  RGE_Static_Object *pRVar4;
  RGE_Pick_Info pick_info;
  
  iVar2 = rge_base_game->prog_mode;
  if ((((iVar2 != 4) && (iVar2 != 6)) && (iVar2 != 7)) && (iVar2 != 5)) {
    return 0;
  }
  iVar2 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar2 != 0) {
switchD_0052d9c7_default:
    lVar3 = RGE_Main_View::mouse_right_up_action
                      ((RGE_Main_View *)this,param_1,param_2,param_3,param_4);
    return lVar3;
  }
  switch(rge_base_game->game_mode) {
  case 100:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    uVar1 = RGE_Main_View::pick1
                      ((RGE_Main_View *)this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                       (RGE_Static_Object *)0x0,1);
    if (uVar1 == '3') {
      RGE_Main_View::fixup_pick_info((RGE_Main_View *)this,(RGE_Pick_Info *)&pick_info.y);
      uVar1 = TRIBE_Player::command_attack_ground
                        (*(TRIBE_Player **)&this->field_0x100,pick_info.y,(float)pick_info._8_4_);
      if (uVar1 != '\0') {
        RGE_Main_View::reset_display_object_selection((RGE_Main_View *)this,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)this,rge_base_game->shapes[2],0,*(int *)&this->field_0x130 + param_1,
                   *(int *)&this->field_0x134 + param_2,0,0xf,(uchar *)0x0,2,0x7d);
        (**(code **)(*(int *)this + 0x20))(1);
        goto LAB_0052db3c;
      }
    }
    goto LAB_0052db2f;
  case 0x65:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    iVar2 = (**(code **)(*(int *)this + 0x100))(param_1,param_2,0,0x68);
    if (iVar2 != 0) goto LAB_0052db3c;
LAB_0052db2f:
    RGE_Base_Game::play_sound(rge_base_game,3);
LAB_0052db3c:
    (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    return 1;
  case 0x66:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    iVar2 = (**(code **)(*(int *)this + 0x100))(param_1,param_2,0,0x69);
    goto joined_r0x0052db8c;
  case 0x67:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    iVar2 = (**(code **)(*(int *)this + 0x100))(param_1,param_2,0,7);
joined_r0x0052db8c:
    if (iVar2 != 0) goto LAB_0052dabd;
    break;
  case 0x68:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    pRVar4 = RGE_Main_View::pick_best_target((RGE_Main_View *)this,param_1,param_2,(int *)0x0,-1);
    if ((pRVar4 != (RGE_Static_Object *)0x0) &&
       (uVar1 = TRIBE_Player::command_make_repair(*(TRIBE_Player **)&this->field_0x100,pRVar4),
       uVar1 != '\0')) {
      RGE_View::display_object_selection((RGE_View *)this,pRVar4->id,0x5dc,2,2);
      RGE_View::reset_overlay_sprites((RGE_View *)this);
      (**(code **)(*(int *)this + 0x20))(1);
      goto LAB_0052dabd;
    }
    break;
  case 0x69:
    TPanel::release_mouse((TPanel *)this);
    if ((this->field_0xec != '\x01') && (this->field_0xec != '\x02')) {
      return 1;
    }
    uVar1 = RGE_Main_View::pick1
                      ((RGE_Main_View *)this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                       (RGE_Static_Object *)0x0,1);
    if (uVar1 == '3') {
      RGE_Main_View::fixup_pick_info((RGE_Main_View *)this,(RGE_Pick_Info *)&pick_info.y);
      uVar1 = TRIBE_Player::command_make_unload
                        (*(TRIBE_Player **)&this->field_0x100,pick_info.y,(float)pick_info._8_4_);
      if (uVar1 != '\0') {
        RGE_Main_View::reset_display_object_selection((RGE_Main_View *)this,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)this,rge_base_game->shapes[2],0,*(int *)&this->field_0x130 + param_1,
                   *(int *)&this->field_0x134 + param_2,0,0xf,(uchar *)0x0,2,0x7d);
        (**(code **)(*(int *)this + 0x20))(1);
        goto LAB_0052dabd;
      }
    }
    break;
  default:
    goto switchD_0052d9c7_default;
  }
  RGE_Base_Game::play_sound(rge_base_game,3);
LAB_0052dabd:
  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
  return 1;
}

// --------------------------------------------------

// Function: pick_through_fog
// Address: 0052dce0
int __thiscall TRIBE_Main_View::pick_through_fog(TRIBE_Main_View *this,RGE_Static_Object *param_1)
{
  int iVar1;
  
  if ((param_1 != (RGE_Static_Object *)0x0) && (param_1->master_obj->id == 0x2d)) {
    return 1;
  }
  iVar1 = RGE_View::pick_through_fog((RGE_View *)this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: pick_weight
// Address: 0052dd10
int __thiscall
TRIBE_Main_View::pick_weight(TRIBE_Main_View *this,RGE_Static_Object *param_1,int param_2)
{
  short sVar1;
  bool bVar2;
  RGE_Static_Object *pRVar3;
  
  pRVar3 = param_1;
  sVar1 = param_1->master_obj->id;
  param_1 = (RGE_Static_Object *)(uint)param_1->master_obj->select_level;
  if ((((sVar1 == 0x4f) || (sVar1 == 199)) || (sVar1 == 0x45)) || (sVar1 == 0x116)) {
    param_1 = (RGE_Static_Object *)&DAT_00000003;
  }
  if ((*(int *)&this->field_0x33c == 0) || (*(int *)&this->field_0x340 != pRVar3->id)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (param_1 == (RGE_Static_Object *)0x2) {
    if (bVar2) {
      return 5;
    }
    if ((param_2 != 1) && (param_2 != 2)) {
      if (param_2 != 3) {
        return 0;
      }
      return 2;
    }
  }
  else {
    if (param_1 != (RGE_Static_Object *)&DAT_00000003) {
      if (param_1 != (RGE_Static_Object *)0x4) {
        return 1;
      }
      if (!bVar2) {
        if ((param_2 != 1) && (param_2 != 2)) {
          return (param_2 == 3) + 2;
        }
        return 4;
      }
      return 5;
    }
    if (bVar2) {
      return 5;
    }
    if ((param_2 != 1) && (param_2 != 2)) {
      if (param_2 != 3) {
        return 0;
      }
      if (1 < pRVar3->object_state) {
        return 0;
      }
      return 2;
    }
  }
  return 3;
}

// --------------------------------------------------

// Function: command_make_do
// Address: 0052de20
int __thiscall
TRIBE_Main_View::command_make_do
          (TRIBE_Main_View *this,long param_1,long param_2,int param_3,short param_4)
{
  int iVar1;
  
  iVar1 = RGE_Main_View::command_make_do((RGE_Main_View *)this,param_1,param_2,param_3,param_4);
  return iVar1;
}

// --------------------------------------------------

// Function: mouse_left_dbl_click_action
// Address: 0052de40
long __thiscall
TRIBE_Main_View::mouse_left_dbl_click_action
          (TRIBE_Main_View *this,long param_1,long param_2,int param_3,int param_4)
{
  short sVar1;
  undefined4 *puVar2;
  RGE_Static_Object *pRVar3;
  uchar uVar4;
  bool bVar5;
  RGE_Pick_Info pick_info;
  
  uVar4 = RGE_Main_View::pick1
                    ((RGE_Main_View *)this,')','\x01',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                     (RGE_Static_Object *)0x0,1);
  if (((uVar4 == '4') && (*(char *)(*(int *)&(pick_info.tile)->last_drawn_shape + 0x8d) == '\x04'))
     && ((RGE_Player *)((pick_info.tile)->objects)._padding_ == *(RGE_Player **)&this->field_0x100))
{
    if ((param_3 == 0) && (param_4 == 0)) {
      RGE_Player::unselect_object(*(RGE_Player **)&this->field_0x100);
    }
    RGE_Player::select_one_object
              (*(RGE_Player **)&this->field_0x100,(RGE_Static_Object *)pick_info.tile,0);
    sVar1 = *(short *)(*(int *)&(pick_info.tile)->last_drawn_shape + 0x10);
    param_2._0_1_ = *(uchar *)(*(int *)&(pick_info.tile)->last_drawn_shape + 0x8f);
    if ((uchar)param_2 != '\x03') {
      param_2._0_1_ = 0xff;
    }
    for (puVar2 = *(undefined4 **)(*(int *)(*(int *)&this->field_0x100 + 0x28) + 4);
        puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
      pRVar3 = (RGE_Static_Object *)*puVar2;
      if (((pRVar3->master_obj->id == sVar1) || (pRVar3->master_obj->unit_level == (uchar)param_2))
         && (bVar5 = RGE_View::Object_Was_Displayed((RGE_View *)this,pRVar3->id,false), bVar5)) {
        RGE_Player::select_one_object(*(RGE_Player **)&this->field_0x100,pRVar3,0);
      }
    }
    RGE_Player::select_one_object
              (*(RGE_Player **)&this->field_0x100,(RGE_Static_Object *)pick_info.tile,0);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

