// Class: TPanel
// Size:  0xF4
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
// [0x004] TPanel * previousPanelValue
// [0x008] TPanel * previousModalPanelValue
// [0x00C] long pnl_x
// [0x010] long pnl_y
// [0x014] long pnl_wid
// [0x018] long pnl_hgt
// [0x01C] char * panelNameValue
// [0x020] TDrawArea * render_area
// [0x024] tagRECT clip_rect (sz: 0x10)
// [0x034] PositionMode position_mode
// [0x038] RedrawMode need_redraw
// [0x03C] TPanel * curr_child
// [0x040] TPanel * parent_panel
// [0x044] TPanel * left_panel
// [0x048] TPanel * top_panel
// [0x04C] TPanel * right_panel
// [0x050] TPanel * bottom_panel
// [0x054] PanelNode * node
// [0x058] PanelNode * first_child_node
// [0x05C] PanelNode * last_child_node
// [0x060] TPanel * tab_prev_panel
// [0x064] TPanel * tab_next_panel
// [0x068] int mouse_captured
// [0x06C] int active
// [0x070] int visible
// [0x074] int tab_stop
// [0x078] int have_focus
// [0x07C] int overlapping_children
// [0x080] int handle_mouse_input
// [0x084] int just_drawn
// [0x088] void * clip_rgn
// [0x08C] tagRECT render_rect (sz: 0x10)
// [0x09C] long left_border
// [0x0A0] long top_border
// [0x0A4] long right_border
// [0x0A8] long bottom_border
// [0x0AC] long min_wid
// [0x0B0] long max_wid
// [0x0B4] long min_hgt
// [0x0B8] long max_hgt
// [0x0BC] long mouse_hold_interval
// [0x0C0] long mouse_move_tolerance
// [0x0C4] long mouse_down_x
// [0x0C8] long mouse_down_y
// [0x0CC] int mouse_down_ctrl
// [0x0D0] int mouse_down_shift
// [0x0D4] ulong mouse_down_time
// [0x0D8] int error_code
// [0x0DC] int z_order
// [0x0E0] int display_changed_count
// [0x0E4] long help_string_id
// [0x0E8] long help_page_id
// [0x0EC] uchar mouse_action
// [0x0ED] uchar mouse_down_button
// [0x0EE] uchar panel_type
// [0x0EF] uchar color
// [0x0F0] uchar fill_in_background
// [0x0F1] uchar clip_to_parent
// [0x0F2] uchar draw_rect2_flag
// [0x0F3] uchar need_restore
// ----------------------------------------------------------------

// Function: mouse_move_action
// Address: 00437110
long __thiscall
TPanel::mouse_move_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_down_action
// Address: 00437230
long __thiscall
TPanel::mouse_left_down_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_hold_action
// Address: 00437240
long __thiscall
TPanel::mouse_left_hold_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_move_action
// Address: 00437250
long __thiscall
TPanel::mouse_left_move_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_up_action
// Address: 00437260
long __thiscall
TPanel::mouse_left_up_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_dbl_click_action
// Address: 00437270
long __thiscall
TPanel::mouse_left_dbl_click_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_down_action
// Address: 00437280
long __thiscall
TPanel::mouse_right_down_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_hold_action
// Address: 00437290
long __thiscall
TPanel::mouse_right_hold_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_move_action
// Address: 004372a0
long __thiscall
TPanel::mouse_right_move_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_up_action
// Address: 004372b0
long __thiscall
TPanel::mouse_right_up_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_right_dbl_click_action
// Address: 00437490
long __thiscall
TPanel::mouse_right_dbl_click_action(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 004374a0
long __thiscall
TPanel::key_down_action(TPanel *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  return 0;
}

// --------------------------------------------------

// Function: char_action
// Address: 004374b0
long __thiscall TPanel::char_action(TPanel *this,long param_1,short param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: take_snapshot
// Address: 00437610
void __thiscall TPanel::take_snapshot(TPanel *this)
{
  return;
}

// --------------------------------------------------

// Function: TPanel
// Address: 00464720
TPanel * __thiscall TPanel::TPanel(TPanel *this,char *param_1)
{
  this->previousPanelValue = (TPanel *)0x0;
  this->previousModalPanelValue = (TPanel *)0x0;
  this->pnl_x = 0;
  this->pnl_y = 0;
  this->pnl_wid = 0;
  this->pnl_hgt = 0;
  this->panelNameValue = (char *)0x0;
  this->render_area = (TDrawArea *)0x0;
  this->position_mode = PositionFixed;
  this->need_redraw = RedrawFull;
  this->curr_child = (TPanel *)0x0;
  this->parent_panel = (TPanel *)0x0;
  this->left_panel = (TPanel *)0x0;
  this->top_panel = (TPanel *)0x0;
  this->right_panel = (TPanel *)0x0;
  this->bottom_panel = (TPanel *)0x0;
  this->node = (PanelNode *)0x0;
  this->first_child_node = (PanelNode *)0x0;
  this->last_child_node = (PanelNode *)0x0;
  this->tab_prev_panel = (TPanel *)0x0;
  this->tab_next_panel = (TPanel *)0x0;
  this->mouse_captured = 0;
  this->active = 1;
  this->visible = 0;
  this->tab_stop = 0;
  this->have_focus = 0;
  this->overlapping_children = 1;
  this->handle_mouse_input = 1;
  this->just_drawn = 0;
  this->clip_rgn = (void *)0x0;
  this->left_border = 0;
  this->top_border = 0;
  this->right_border = 0;
  this->bottom_border = 0;
  this->min_wid = 0;
  this->max_wid = 0;
  this->min_hgt = 0;
  this->max_hgt = 0;
  this->mouse_hold_interval = 0xfa;
  this->mouse_move_tolerance = 0;
  this->mouse_down_x = 0;
  this->mouse_down_y = 0;
  this->mouse_down_ctrl = 0;
  this->mouse_down_shift = 0;
  this->mouse_down_time = 0;
  this->error_code = 0;
  this->z_order = 0;
  this->display_changed_count = 0;
  this->mouse_action = '\0';
  this->mouse_down_button = '\0';
  this->panel_type = '\0';
  this->color = '\0';
  this->fill_in_background = '\0';
  this->draw_rect2_flag = '\0';
  this->_padding_ = (int)&_vftable_;
  (this->render_rect).left = 0;
  (this->render_rect).top = 0;
  (this->render_rect).right = 0;
  (this->render_rect).bottom = 0;
  setPanelName(this,param_1);
  this->need_restore = '\0';
  this->help_string_id = -1;
  this->help_page_id = -1;
  if ((this->panelNameValue != (char *)0x0) && (*this->panelNameValue != '\0')) {
    TPanelSystem::addPanel(&panel_system,this,0,0);
  }
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00464890
void * __thiscall TPanel::_scalar_deleting_destructor_(TPanel *this,uint param_1)
{
  ~TPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TPanel
// Address: 004648b0
void __thiscall TPanel::TPanel(TPanel *this)
{
  this->previousPanelValue = (TPanel *)0x0;
  this->previousModalPanelValue = (TPanel *)0x0;
  this->pnl_x = 0;
  this->pnl_y = 0;
  this->pnl_wid = 0;
  this->pnl_hgt = 0;
  this->panelNameValue = (char *)0x0;
  this->render_area = (TDrawArea *)0x0;
  this->position_mode = PositionFixed;
  this->need_redraw = RedrawFull;
  this->curr_child = (TPanel *)0x0;
  this->parent_panel = (TPanel *)0x0;
  this->left_panel = (TPanel *)0x0;
  this->top_panel = (TPanel *)0x0;
  this->right_panel = (TPanel *)0x0;
  this->bottom_panel = (TPanel *)0x0;
  this->node = (PanelNode *)0x0;
  this->first_child_node = (PanelNode *)0x0;
  this->last_child_node = (PanelNode *)0x0;
  this->tab_prev_panel = (TPanel *)0x0;
  this->tab_next_panel = (TPanel *)0x0;
  this->mouse_captured = 0;
  this->active = 1;
  this->visible = 0;
  this->tab_stop = 0;
  this->have_focus = 0;
  this->overlapping_children = 1;
  this->handle_mouse_input = 1;
  this->clip_rgn = (void *)0x0;
  this->left_border = 0;
  this->top_border = 0;
  this->right_border = 0;
  this->bottom_border = 0;
  this->min_wid = 0;
  this->max_wid = 0;
  this->min_hgt = 0;
  this->max_hgt = 0;
  this->mouse_move_tolerance = 0;
  this->mouse_down_x = 0;
  this->mouse_down_y = 0;
  this->mouse_down_ctrl = 0;
  this->mouse_down_shift = 0;
  this->mouse_down_time = 0;
  this->error_code = 0;
  this->z_order = 0;
  this->display_changed_count = 0;
  this->mouse_action = '\0';
  this->mouse_down_button = '\0';
  this->panel_type = '\0';
  this->color = '\0';
  this->fill_in_background = '\0';
  this->draw_rect2_flag = '\0';
  (this->render_rect).left = 0;
  (this->render_rect).top = 0;
  (this->render_rect).right = 0;
  (this->render_rect).bottom = 0;
  this->mouse_hold_interval = 0xfa;
  this->_padding_ = (int)&_vftable_;
  this->help_string_id = -1;
  this->help_page_id = -1;
  return;
}

// --------------------------------------------------

// Function: ~TPanel
// Address: 004649e0
void __thiscall TPanel::~TPanel(TPanel *this)
{
  int iVar1;
  char *pcVar2;
  
  this->_padding_ = (int)&_vftable_;
  release_mouse(this);
  if (this->panelNameValue != (char *)0x0) {
    iVar1 = TPanelSystem::inSystem(&panel_system,this);
    if (iVar1 != 0) {
      pcVar2 = panelName(this);
      TPanelSystem::removePanel(&panel_system,pcVar2);
    }
  }
  if (this->node != (PanelNode *)0x0) {
    if (this->parent_panel != (TPanel *)0x0) {
      remove_panel_node(this->parent_panel,this->node);
    }
    free(this->node);
    this->node = (PanelNode *)0x0;
  }
  this->first_child_node = (PanelNode *)0x0;
  if (this->clip_rgn != (void *)0x0) {
    DeleteObject(this->clip_rgn);
    this->clip_rgn = (void *)0x0;
  }
  if (this->parent_panel != (TPanel *)0x0) {
    (**(code **)(this->parent_panel->_padding_ + 0x20))(2);
  }
  if (this->panelNameValue != (char *)0x0) {
    free(this->panelNameValue);
  }
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 00464a80
long __thiscall
TPanel::setup(TPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,long param_5
             ,long param_6,uchar param_7)
{
  int iVar1;
  PanelNode *pPVar2;
  int iVar3;
  int iVar4;
  
  this->parent_panel = param_2;
  this->render_area = param_1;
  if (this->position_mode == PositionFixed) {
    this->top_border = param_4;
    this->min_wid = param_5;
    this->max_wid = param_5;
    this->left_border = param_3;
    this->right_border = 0;
    this->bottom_border = 0;
    this->min_hgt = param_6;
    this->max_hgt = param_6;
  }
  iVar1 = this->_padding_;
  if (param_1 == (TDrawArea *)0x0) {
    iVar4 = 0;
    iVar3 = 0;
  }
  else {
    iVar4 = param_1->Height;
    iVar3 = param_1->Width;
  }
  (**(code **)(iVar1 + 0x50))(iVar3,iVar4);
  (**(code **)(iVar1 + 0x10))(param_5);
  this->mouse_captured = 0;
  if (this->node == (PanelNode *)0x0) {
    pPVar2 = (PanelNode *)calloc(1,0xc);
    this->node = pPVar2;
    if (pPVar2 == (PanelNode *)0x0) {
      return 0;
    }
    pPVar2->panel = this;
    this->node->prev_node = (PanelNode *)0x0;
    this->node->next_node = (PanelNode *)0x0;
    if (this->parent_panel != (TPanel *)0x0) {
      add_panel_node(this->parent_panel,this->node,(PanelNode *)0x0,0);
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: add_panel_node
// Address: 00464b50
void __thiscall
TPanel::add_panel_node(TPanel *this,PanelNode *param_1,PanelNode *param_2,int param_3)
{
  PanelNode *pPVar1;
  PanelNode *pPVar2;
  
  if (param_2 == (PanelNode *)0x0) {
    pPVar1 = this->first_child_node;
    if (pPVar1 == (PanelNode *)0x0) {
      param_1->prev_node = (PanelNode *)0x0;
      param_1->next_node = (PanelNode *)0x0;
    }
    else {
      for (pPVar2 = pPVar1->next_node; pPVar2 != (PanelNode *)0x0; pPVar2 = pPVar2->next_node) {
        pPVar1 = pPVar2;
      }
      pPVar1->next_node = param_1;
      param_1->prev_node = pPVar1;
      param_1->next_node = (PanelNode *)0x0;
    }
  }
  else if (param_3 == 0) {
    pPVar1 = param_2->prev_node;
    param_1->next_node = param_2;
    param_1->prev_node = pPVar1;
    param_2->prev_node = param_1;
    if (param_1->prev_node != (PanelNode *)0x0) {
      param_1->prev_node->next_node = param_1;
    }
  }
  else {
    param_1->prev_node = param_2;
    param_1->next_node = param_2->next_node;
    param_2->next_node = param_1;
    if (param_1->next_node != (PanelNode *)0x0) {
      param_1->next_node->prev_node = param_1;
    }
  }
  if (param_1->prev_node == (PanelNode *)0x0) {
    this->first_child_node = param_1;
  }
  if (param_1->next_node == (PanelNode *)0x0) {
    this->last_child_node = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: remove_panel_node
// Address: 00464bf0
void __thiscall TPanel::remove_panel_node(TPanel *this,PanelNode *param_1)
{
  if (param_1 == this->first_child_node) {
    this->first_child_node = param_1->next_node;
  }
  if (param_1 == this->last_child_node) {
    this->last_child_node = param_1->prev_node;
  }
  if (param_1->prev_node != (PanelNode *)0x0) {
    param_1->prev_node->next_node = param_1->next_node;
  }
  if (param_1->next_node != (PanelNode *)0x0) {
    param_1->next_node->prev_node = param_1->prev_node;
  }
  param_1->prev_node = (PanelNode *)0x0;
  param_1->next_node = (PanelNode *)0x0;
  if (this->curr_child == param_1->panel) {
    this->curr_child = (TPanel *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: set_rect
// Address: 00464c50
void __thiscall TPanel::set_rect(TPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  int iVar1;
  int iVar2;
  TPanel *pTVar3;
  int iVar4;
  TDrawArea *pTVar5;
  int iVar6;
  void *pvVar7;
  
  pTVar3 = this->parent_panel;
  this->pnl_wid = param_3;
  this->pnl_hgt = param_4;
  iVar1 = param_3 + -1 + param_1;
  iVar2 = param_4 + -1 + param_2;
  this->pnl_x = param_1;
  this->pnl_y = param_2;
  (this->render_rect).left = param_1;
  (this->render_rect).top = param_2;
  (this->render_rect).right = iVar1;
  (this->render_rect).bottom = iVar2;
  (this->clip_rect).left = param_1;
  (this->clip_rect).top = param_2;
  (this->clip_rect).right = iVar1;
  (this->clip_rect).bottom = iVar2;
  if ((pTVar3 != (TPanel *)0x0) && (this->clip_to_parent != '\0')) {
    iVar4 = (pTVar3->clip_rect).left;
    if (param_1 < iVar4) {
      (this->clip_rect).left = iVar4;
    }
    iVar4 = (pTVar3->clip_rect).top;
    if (param_2 < iVar4) {
      (this->clip_rect).top = iVar4;
    }
    iVar4 = (pTVar3->clip_rect).right;
    if (iVar4 < iVar1) {
      (this->clip_rect).right = iVar4;
    }
    iVar1 = (pTVar3->clip_rect).bottom;
    if (iVar1 < iVar2) {
      (this->clip_rect).bottom = iVar1;
    }
  }
  if ((this->clip_rect).left < 0) {
    (this->clip_rect).left = 0;
  }
  if ((this->clip_rect).top < 0) {
    (this->clip_rect).top = 0;
  }
  pTVar5 = this->render_area;
  if (pTVar5 != (TDrawArea *)0x0) {
    if (pTVar5->Width <= (this->clip_rect).right) {
      (this->clip_rect).right = pTVar5->Width + -1;
    }
    if ((pTVar5 != (TDrawArea *)0x0) && (pTVar5->Height <= (this->clip_rect).bottom)) {
      (this->clip_rect).bottom = pTVar5->Height + -1;
    }
  }
  if (this->clip_rgn != (void *)0x0) {
    DeleteObject(this->clip_rgn);
    this->clip_rgn = (void *)0x0;
  }
  iVar1 = (this->clip_rect).right;
  iVar2 = (this->clip_rect).left;
  if (iVar2 <= iVar1) {
    iVar4 = (this->clip_rect).bottom;
    iVar6 = (this->clip_rect).top;
    if (iVar6 <= iVar4) {
      this->visible = 1;
      pvVar7 = (void *)CreateRectRgn(iVar2,iVar6,iVar1,iVar4);
      this->clip_rgn = pvVar7;
      goto LAB_00464d57;
    }
  }
  this->visible = 0;
LAB_00464d57:
  if (this->active != 0) {
    (**(code **)(this->_padding_ + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: set_rect
// Address: 00464d70
void __thiscall TPanel::set_rect(TPanel *this,tagRECT param_1)
{
  (**(code **)(this->_padding_ + 0xc))
            (param_1.left,param_1.top,(param_1.right - param_1.left) + 1,
             (param_1.bottom - param_1.top) + 1);
  return;
}

// --------------------------------------------------

// Function: set_color
// Address: 00464da0
void __thiscall TPanel::set_color(TPanel *this,uchar param_1)
{
  this->color = param_1;
  if (this->active != 0) {
    (**(code **)(this->_padding_ + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: set_active
// Address: 00464dc0
void __thiscall TPanel::set_active(TPanel *this,int param_1)
{
  if (this->active != param_1) {
    this->active = param_1;
    if (param_1 != 0) {
      (**(code **)(this->_padding_ + 0x20))(1);
      return;
    }
    release_mouse(this);
    if (this->parent_panel != (TPanel *)0x0) {
      (**(code **)(this->parent_panel->_padding_ + 0x20))(1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_positioning
// Address: 00464e00
void __thiscall
TPanel::set_positioning
          (TPanel *this,PositionMode param_1,long param_2,long param_3,long param_4,long param_5,
          long param_6,long param_7,long param_8,long param_9,TPanel *param_10,TPanel *param_11,
          TPanel *param_12,TPanel *param_13)
{
  int iVar1;
  TDrawArea *pTVar2;
  int iVar3;
  int iVar4;
  
  this->position_mode = param_1;
  this->right_border = param_4;
  this->max_wid = param_7;
  this->left_border = param_2;
  this->top_border = param_3;
  iVar1 = this->_padding_;
  this->left_panel = param_10;
  this->bottom_border = param_5;
  this->min_wid = param_6;
  this->bottom_panel = param_13;
  pTVar2 = this->render_area;
  this->min_hgt = param_8;
  this->max_hgt = param_9;
  this->top_panel = param_11;
  this->right_panel = param_12;
  if (pTVar2 == (TDrawArea *)0x0) {
    iVar4 = 0;
    iVar3 = 0;
  }
  else {
    iVar4 = pTVar2->Height;
    iVar3 = pTVar2->Width;
  }
  (**(code **)(iVar1 + 0x50))(iVar3,iVar4);
  if (this->active != 0) {
    (**(code **)(iVar1 + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: set_fixed_position
// Address: 00464eb0
void __thiscall
TPanel::set_fixed_position(TPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  (**(code **)(this->_padding_ + 0x18))
            (0,param_1,param_2,0,0,param_3,param_3,param_4,param_4,0,0,0,0);
  return;
}

// --------------------------------------------------

// Function: set_redraw
// Address: 00464ee0
void __thiscall TPanel::set_redraw(TPanel *this,RedrawMode param_1)
{
  if ((((param_1 != RedrawNormal) || (this->need_redraw != RedrawFull)) &&
      (this->need_redraw = param_1, param_1 != RedrawNone)) &&
     (((this->render_area != (TDrawArea *)0x0 && (this->visible != 0)) && (this->active != 0)))) {
    InvalidateRect(this->render_area->Wnd,&this->clip_rect,0);
  }
  return;
}

// --------------------------------------------------

// Function: set_overlapped_redraw
// Address: 00464f20
void __thiscall
TPanel::set_overlapped_redraw(TPanel *this,TPanel *param_1,TPanel *param_2,RedrawMode param_3)
{
  PanelNode *pPVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  TPanel *pTVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  PanelNode *temp_node;
  tagRECT this_rect;
  
  iVar2 = (param_1->clip_rect).left;
  iVar3 = (param_1->clip_rect).top;
  iVar4 = (param_1->clip_rect).right;
  iVar5 = (param_1->clip_rect).bottom;
  for (pPVar1 = this->first_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->next_node) {
    pTVar6 = pPVar1->panel;
    if (((pTVar6 != param_1) && (pTVar6 != param_2)) && (param_1->z_order < pTVar6->z_order)) {
      iVar7 = (pTVar6->clip_rect).left;
      iVar8 = (pTVar6->clip_rect).top;
      iVar9 = (pTVar6->clip_rect).right;
      iVar10 = (pTVar6->clip_rect).bottom;
      if (((((iVar7 < iVar2) || (iVar4 < iVar7)) && ((iVar9 < iVar2 || (iVar4 < iVar9)))) &&
          ((iVar2 <= iVar7 || (iVar9 <= iVar4)))) ||
         (((iVar8 < iVar3 || (iVar5 < iVar8)) &&
          (((iVar10 < iVar3 || (iVar5 < iVar10)) && ((iVar3 <= iVar8 || (iVar10 <= iVar5)))))))) {
        if (((((iVar7 <= iVar2) && (iVar2 <= iVar9)) || ((iVar7 <= iVar4 && (iVar4 <= iVar9)))) ||
            ((iVar2 < iVar7 && (iVar9 < iVar4)))) &&
           ((((iVar8 <= iVar3 && (iVar3 <= iVar10)) || ((iVar8 <= iVar5 && (iVar5 <= iVar10)))) ||
            ((iVar3 < iVar8 && (iVar10 < iVar5)))))) {
          (**(code **)(pTVar6->_padding_ + 0x20))(param_3);
        }
      }
      else {
        (**(code **)(pTVar6->_padding_ + 0x20))(param_3);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_any_overlapping_redraw
// Address: 00465050
void __thiscall TPanel::set_any_overlapping_redraw(TPanel *this,TPanel *param_1,RedrawMode param_2)
{
  PanelNode *pPVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  TPanel *pTVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  PanelNode *temp_node;
  tagRECT this_rect;
  
  iVar2 = (param_1->clip_rect).left;
  iVar3 = (param_1->clip_rect).top;
  iVar4 = (param_1->clip_rect).right;
  iVar5 = (param_1->clip_rect).bottom;
  for (pPVar1 = this->first_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->next_node) {
    pTVar6 = pPVar1->panel;
    if (pTVar6 != param_1) {
      iVar7 = (pTVar6->clip_rect).left;
      iVar8 = (pTVar6->clip_rect).top;
      iVar9 = (pTVar6->clip_rect).right;
      iVar10 = (pTVar6->clip_rect).bottom;
      if (((((iVar7 < iVar2) || (iVar4 < iVar7)) && ((iVar9 < iVar2 || (iVar4 < iVar9)))) &&
          ((iVar2 <= iVar7 || (iVar9 <= iVar4)))) ||
         (((iVar8 < iVar3 || (iVar5 < iVar8)) &&
          (((iVar10 < iVar3 || (iVar5 < iVar10)) && ((iVar3 <= iVar8 || (iVar10 <= iVar5)))))))) {
        if (((((iVar7 <= iVar2) && (iVar2 <= iVar9)) || ((iVar7 <= iVar4 && (iVar4 <= iVar9)))) ||
            ((iVar2 < iVar7 && (iVar9 < iVar4)))) &&
           ((((iVar8 <= iVar3 && (iVar3 <= iVar10)) || ((iVar8 <= iVar5 && (iVar5 <= iVar10)))) ||
            ((iVar3 < iVar8 && (iVar10 < iVar5)))))) {
          (**(code **)(pTVar6->_padding_ + 0x20))(param_2);
        }
      }
      else {
        (**(code **)(pTVar6->_padding_ + 0x20))(param_2);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 00465160
void __thiscall TPanel::draw(TPanel *this)
{
  int iVar1;
  
  this->need_redraw = RedrawNone;
  if (((this->render_area != (TDrawArea *)0x0) && (this->visible != 0)) && (this->active != 0)) {
    if ((this->fill_in_background == '\0') && (this->parent_panel != (TPanel *)0x0)) {
      iVar1 = this->parent_panel->_padding_;
      if (this->draw_rect2_flag != '\0') {
        (**(code **)(iVar1 + 0x3c))(&this->clip_rect);
        return;
      }
      (**(code **)(iVar1 + 0x34))(&this->clip_rect);
      return;
    }
    TDrawArea::Clear(this->render_area,&this->clip_rect,(uint)this->color);
  }
  return;
}

// --------------------------------------------------

// Function: draw_rect
// Address: 004651c0
void __thiscall TPanel::draw_rect(TPanel *this,tagRECT *param_1)
{
  tagRECT *ptVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  tagRECT save_rect;
  
  ptVar1 = &this->clip_rect;
  lVar2 = ptVar1->left;
  lVar3 = (this->clip_rect).top;
  lVar4 = (this->clip_rect).right;
  lVar5 = (this->clip_rect).bottom;
  ptVar1->left = param_1->left;
  (this->clip_rect).top = param_1->top;
  (this->clip_rect).right = param_1->right;
  (this->clip_rect).bottom = param_1->bottom;
  (**(code **)(this->_padding_ + 0x30))();
  ptVar1->left = lVar2;
  (this->clip_rect).top = lVar3;
  (this->clip_rect).right = lVar4;
  (this->clip_rect).bottom = lVar5;
  return;
}

// --------------------------------------------------

// Function: draw_offset
// Address: 00465220
void __thiscall TPanel::draw_offset(TPanel *this,long param_1,long param_2,tagRECT *param_3)
{
  tagRECT *ptVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  tagRECT save_rect;
  
  this->pnl_x = this->pnl_x + param_1;
  ptVar1 = &this->clip_rect;
  this->pnl_y = this->pnl_y + param_2;
  lVar2 = ptVar1->left;
  lVar3 = (this->clip_rect).top;
  lVar4 = (this->clip_rect).right;
  lVar5 = (this->clip_rect).bottom;
  ptVar1->left = param_3->left;
  (this->clip_rect).top = param_3->top;
  (this->clip_rect).right = param_3->right;
  iVar6 = this->_padding_;
  (this->clip_rect).bottom = param_3->bottom;
  (**(code **)(iVar6 + 0x30))();
  ptVar1->left = lVar2;
  (this->clip_rect).top = lVar3;
  iVar6 = this->pnl_x;
  (this->clip_rect).right = lVar4;
  (this->clip_rect).bottom = lVar5;
  this->pnl_x = iVar6 - param_1;
  this->pnl_y = this->pnl_y - param_2;
  return;
}

// --------------------------------------------------

// Function: draw_rect2
// Address: 004652c0
void __thiscall TPanel::draw_rect2(TPanel *this,tagRECT *param_1)
{
  this->draw_rect2_flag = '\x01';
  (**(code **)(this->_padding_ + 0x34))(param_1);
  this->draw_rect2_flag = '\0';
  return;
}

// --------------------------------------------------

// Function: draw_offset2
// Address: 004652f0
void __thiscall TPanel::draw_offset2(TPanel *this,long param_1,long param_2,tagRECT *param_3)
{
  this->draw_rect2_flag = '\x01';
  (**(code **)(this->_padding_ + 0x38))(param_1,param_2,param_3);
  this->draw_rect2_flag = '\0';
  return;
}

// --------------------------------------------------

// Function: draw_setup
// Address: 00465320
void __thiscall TPanel::draw_setup(TPanel *this,int param_1)
{
  void *pvVar1;
  
  pvVar1 = this->render_area->DrawDc;
  if (pvVar1 != (void *)0x0) {
    SelectClipRgn(pvVar1,this->clip_rgn);
  }
  TDrawArea::SetClipRect(this->render_area,&this->clip_rect);
  if (param_1 != 0) {
    TDrawArea::Clear(this->render_area,&this->clip_rect,(uint)this->color);
  }
  return;
}

// --------------------------------------------------

// Function: draw_finish
// Address: 00465370
void __thiscall TPanel::draw_finish(TPanel *this)
{
  void *pvVar1;
  
  this->need_redraw = RedrawNone;
  pvVar1 = this->render_area->DrawDc;
  if (pvVar1 != (void *)0x0) {
    SelectClipRgn(pvVar1,0);
  }
  TDrawArea::SetClipRect(this->render_area,(tagRECT *)0x0);
  this->need_restore = '\0';
  return;
}

// --------------------------------------------------

// Function: paint
// Address: 004653a0
void __thiscall TPanel::paint(TPanel *this)
{
  if (((this->render_area != (TDrawArea *)0x0) && (this->visible != 0)) && (this->active != 0)) {
    TDrawSystem::Paint(this->render_area->DrawSystem,&this->clip_rect);
    ValidateRect(this->render_area->Wnd,&this->clip_rect);
  }
  return;
}

// --------------------------------------------------

// Function: wnd_proc
// Address: 004653e0
long __thiscall TPanel::wnd_proc(TPanel *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  PanelNode *pPVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  long lVar7;
  TPanel *pTVar8;
  TPanel *pTVar9;
  tagPOINT point;
  undefined4 local_4;
  
  lVar7 = param_4;
  uVar3 = param_3;
  uVar2 = param_2;
  if (this->active == 0) {
    return 0;
  }
  point.x = (long)this;
  if (param_2 < 0x207) {
    if (param_2 < 0x200) {
      if (((param_2 != 0x100) && (param_2 != 0x102)) && (param_2 != 0x104)) goto LAB_00465435;
    }
    else {
      if (param_1 != this->render_area->Wnd) {
        return 0;
      }
      iVar6 = TPanelSystem::GetInputEnabled(&panel_system);
      pTVar8 = (TPanel *)point.x;
      if (iVar6 == 0) {
        return 0;
      }
      get_mouse_info((TPanel *)point.x,param_3,lVar7,(tagPOINT *)&point.y,&param_4,(int *)&param_2);
      pTVar9 = TPanelSystem::mouseOwner(&panel_system);
      if (pTVar9 == (TPanel *)0x0) {
        pTVar9 = TPanelSystem::keyboardOwner(&panel_system);
        if (pTVar9 == (TPanel *)0x0) {
          pTVar9 = TPanelSystem::modalPanel(&panel_system);
          if (pTVar9 != (TPanel *)0x0) {
            pTVar8 = TPanelSystem::modalPanel(&panel_system);
          }
        }
        else {
          pTVar8 = TPanelSystem::keyboardOwner(&panel_system);
        }
      }
      else {
        pTVar8 = TPanelSystem::mouseOwner(&panel_system);
      }
      switch(uVar2) {
      case 0x200:
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x74))(point.y,local_4,param_4,param_2);
        return lVar7;
      case 0x201:
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x70))(1,point.y,local_4,param_4,param_2);
        return lVar7;
      case 0x202:
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x78))(1,point.y,local_4,param_4,param_2);
        return lVar7;
      case 0x203:
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x7c))(1,point.y,local_4,param_4,param_2);
        return lVar7;
      case 0x204:
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x70))(2,point.y,local_4,param_4,param_2);
        return lVar7;
      case 0x205:
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x78))(2,point.y,local_4,param_4,param_2);
        return lVar7;
      case 0x206:
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x7c))(2,point.y,local_4,param_4,param_2);
        return lVar7;
      }
    }
    if ((param_1 == *(void **)(*(int *)(point.x + 0x20) + 4)) &&
       (iVar6 = TPanelSystem::GetInputEnabled(&panel_system), iVar6 != 0)) {
      pTVar8 = TPanelSystem::keyboardOwner(&panel_system);
      if (pTVar8 == (TPanel *)0x0) {
        pTVar9 = TPanelSystem::modalPanel(&panel_system);
        pTVar8 = (TPanel *)point.x;
        if (pTVar9 != (TPanel *)0x0) {
          pTVar8 = TPanelSystem::modalPanel(&panel_system);
        }
      }
      else {
        pTVar8 = TPanelSystem::keyboardOwner(&panel_system);
      }
      if ((uVar2 != 0x100) && (uVar2 != 0x104)) {
        lVar7 = (**(code **)(pTVar8->_padding_ + 0x5c))(param_3,lVar7);
        return lVar7;
      }
      sVar4 = GetKeyState(0x12);
      sVar5 = GetKeyState(0x11);
      param_4 = (long)(sVar5 < 0);
      sVar5 = GetKeyState(0x10);
      param_2 = (uint)(sVar5 < 0);
      lVar7 = (**(code **)(pTVar8->_padding_ + 0x58))(param_3,lVar7,sVar4 < 0,param_4,param_2);
      return lVar7;
    }
  }
  else {
LAB_00465435:
    for (pPVar1 = this->last_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->prev_node) {
      iVar6 = (**(code **)(pPVar1->panel->_padding_ + 0x48))(param_1,uVar2,uVar3,lVar7);
      if (iVar6 != 0) {
        return iVar6;
      }
    }
    if (uVar2 < 0x401) {
      if (uVar2 == 0x400) {
        lVar7 = (**(code **)(((TPanel *)point.x)->_padding_ + 100))(uVar3,lVar7);
        return lVar7;
      }
      switch(uVar2) {
      case 0x111:
        lVar7 = (**(code **)(((TPanel *)point.x)->_padding_ + 0x60))(uVar3,lVar7);
        return lVar7;
      case 0x113:
        lVar7 = (**(code **)(((TPanel *)point.x)->_padding_ + 0x68))(uVar3,lVar7);
        return lVar7;
      case 0x114:
      case 0x115:
        lVar7 = (**(code **)(((TPanel *)point.x)->_padding_ + 0x6c))(uVar3 & 0xffff,uVar3 >> 0x10);
        return lVar7;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 00465780
// [HELPER] s_C__msdev_work_age1_x1_Panel_cpp: "C:\msdev\work\age1_x1\Panel.cpp"
long __thiscall TPanel::handle_idle(TPanel *this)
{
  PanelNode *pPVar1;
  ulong uVar2;
  int iVar3;
  
  if (((this->active != 0) && (this->mouse_action == '\x01')) &&
     (uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Panel_cpp,0x5fd),
     this->mouse_hold_interval <= (int)(uVar2 - this->mouse_down_time))) {
    this->mouse_action = '\x02';
    if (this->mouse_down_button == '\x01') {
      (**(code **)(this->_padding_ + 0x88))();
    }
    else {
      (**(code **)(this->_padding_ + 0x9c))
                (this->mouse_down_x,this->mouse_down_y,this->mouse_down_ctrl,this->mouse_down_shift)
      ;
    }
  }
  pPVar1 = this->last_child_node;
  while( true ) {
    if (pPVar1 == (PanelNode *)0x0) {
      return 0;
    }
    iVar3 = (**(code **)(pPVar1->panel->_padding_ + 0x4c))();
    if (iVar3 != 0) break;
    pPVar1 = pPVar1->prev_node;
  }
  return iVar3;
}

// --------------------------------------------------

// Function: handle_size
// Address: 00465820
long __thiscall TPanel::handle_size(TPanel *this,long param_1,long param_2)
{
  TPanel *pTVar1;
  PositionMode PVar2;
  PanelNode *pPVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar9;
  int iVar10;
  int iVar11;
  long calc_hgt;
  
  pTVar1 = this->parent_panel;
  if (pTVar1 == (TPanel *)0x0) {
    iVar10 = 0;
    iVar4 = 0;
    iVar11 = param_1 + -1;
    iVar5 = param_2 + -1;
  }
  else {
    iVar11 = (pTVar1->render_rect).right;
    iVar10 = (pTVar1->render_rect).left;
    iVar4 = (pTVar1->render_rect).top;
    iVar5 = (pTVar1->render_rect).bottom;
    param_1 = (iVar11 - iVar10) + 1;
    param_2 = (iVar5 - iVar4) + 1;
  }
  if (this->position_mode == PositionFixed) {
    lVar6 = this->min_hgt;
    iVar10 = this->left_border + iVar10;
    iVar4 = this->top_border + iVar4;
    iVar11 = this->min_wid + -1 + iVar10;
  }
  else {
    pTVar1 = this->left_panel;
    if ((pTVar1 == (TPanel *)0x0) || (pTVar1->active == 0)) {
      iVar10 = this->left_border + iVar10;
    }
    else {
      iVar10 = this->left_border + 1 + (pTVar1->render_rect).right;
    }
    pTVar1 = this->top_panel;
    if ((pTVar1 == (TPanel *)0x0) || (pTVar1->active == 0)) {
      iVar4 = this->top_border + iVar4;
    }
    else {
      iVar4 = this->top_border + 1 + (pTVar1->render_rect).bottom;
    }
    pTVar1 = this->right_panel;
    if ((pTVar1 == (TPanel *)0x0) || (pTVar1->active == 0)) {
      iVar11 = iVar11 - this->right_border;
    }
    else {
      iVar11 = ((pTVar1->render_rect).left - this->right_border) + -1;
    }
    pTVar1 = this->bottom_panel;
    if ((pTVar1 == (TPanel *)0x0) || (pTVar1->active == 0)) {
      iVar5 = iVar5 - this->bottom_border;
    }
    else {
      iVar5 = ((pTVar1->render_rect).top - this->bottom_border) + -1;
    }
    iVar7 = (iVar11 - iVar10) + 1;
    iVar9 = (iVar5 - iVar4) + 1;
    iVar8 = this->min_wid;
    if ((iVar8 == 0) || (iVar8 <= iVar7)) {
      iVar8 = this->max_wid;
      if ((iVar8 != 0) && (iVar8 < iVar7)) {
        PVar2 = this->position_mode;
        if (((PVar2 == PositionLeft) || (PVar2 == PositionLeftTop)) || (PVar2 == PositionLeftBottom)
           ) goto LAB_00465973;
        iVar10 = (iVar11 - iVar8) + 1;
      }
    }
    else {
LAB_00465973:
      iVar11 = iVar10 + -1 + iVar8;
    }
    iVar8 = this->min_hgt;
    if ((iVar8 == 0) || (iVar8 <= iVar9)) {
      iVar8 = this->max_hgt;
      if ((iVar8 != 0) && (iVar8 < iVar9)) {
        PVar2 = this->position_mode;
        if (((PVar2 == PositionTop) || (PVar2 == PositionLeftTop)) || (PVar2 == PositionRightTop))
        goto LAB_004659b0;
        iVar4 = (iVar5 - iVar8) + 1;
      }
    }
    else {
LAB_004659b0:
      iVar5 = iVar4 + -1 + iVar8;
    }
    if (this->position_mode != PositionCentered) goto LAB_00465a0e;
    iVar11 = iVar11 - iVar10;
    iVar10 = iVar11 + 1;
    lVar6 = (iVar5 - iVar4) + 1;
    if (iVar10 == param_1) {
      iVar10 = 0;
    }
    else {
      iVar10 = param_1 / 2 - iVar10 / 2;
    }
    iVar11 = iVar11 + iVar10;
    if (lVar6 == param_2) {
      iVar4 = 0;
    }
    else {
      iVar4 = param_2 / 2 - lVar6 / 2;
    }
  }
  iVar5 = lVar6 + -1 + iVar4;
LAB_00465a0e:
  (**(code **)(this->_padding_ + 8))(iVar10,iVar4,iVar11,iVar5);
  iVar11 = 0;
  do {
    for (pPVar3 = this->first_child_node; pPVar3 != (PanelNode *)0x0; pPVar3 = pPVar3->next_node) {
      iVar10 = (**(code **)(pPVar3->panel->_padding_ + 0x50))(unaff_EBP,unaff_EBX);
      if (iVar10 != 0) {
        return iVar10;
      }
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 2);
  return 0;
}

// --------------------------------------------------

// Function: handle_paint
// Address: 00465a70
long __thiscall TPanel::handle_paint(TPanel *this)
{
  PanelNode *pPVar1;
  TPanel *pTVar2;
  int iVar3;
  
  if ((((this->render_area != (TDrawArea *)0x0) && (this->visible != 0)) && (this->active != 0)) &&
     ((rge_base_game->prog_active != 0 && (iVar3 = IsIconic(this->render_area->Wnd), iVar3 == 0))))
{
    if (this->need_redraw != RedrawNone) {
      for (pPVar1 = this->first_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->next_node)
{
        (**(code **)(pPVar1->panel->_padding_ + 0x20))(this->need_redraw);
      }
      pTVar2 = this->parent_panel;
      if ((pTVar2 != (TPanel *)0x0) && (pTVar2->overlapping_children != 0)) {
        (**(code **)(pTVar2->_padding_ + 0x24))(this,this,this->need_redraw);
      }
      (**(code **)(this->_padding_ + 0x30))();
      this->need_redraw = RedrawNone;
      this->just_drawn = 1;
    }
    for (pPVar1 = this->first_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->next_node) {
      (**(code **)(pPVar1->panel->_padding_ + 0x54))();
    }
    this->just_drawn = 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: handle_key_down
// Address: 00465b30
long __thiscall
TPanel::handle_key_down(TPanel *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  PanelNode *pPVar1;
  int iVar2;
  int iVar3;
  TPanel *pTVar4;
  undefined2 in_stack_0000000a;
  
  if (this->have_focus != 0) {
    for (pPVar1 = this->last_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->prev_node) {
      iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0x58))
                        (param_1,_param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = param_5;
    iVar3 = (**(code **)(this->_padding_ + 0xac))(param_1,_param_2,param_3,param_4);
    if (iVar3 != 0) {
      return iVar3;
    }
    if ((((param_3 == 0) && (param_4 == 0)) && (param_1 == 9)) &&
       ((*(int *)(iVar2 + 0x74) != 0 && (*(TPanel **)(iVar2 + 0x40) != (TPanel *)0x0)))) {
      if (param_5 == 0) {
        pTVar4 = *(TPanel **)(iVar2 + 100);
      }
      else {
        pTVar4 = *(TPanel **)(iVar2 + 0x60);
      }
      if (pTVar4 != (TPanel *)0x0) {
        set_curr_child(*(TPanel **)(iVar2 + 0x40),pTVar4);
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: handle_char
// Address: 00465be0
long __thiscall TPanel::handle_char(TPanel *this,long param_1,short param_2)
{
  PanelNode *pPVar1;
  int iVar2;
  long lVar3;
  undefined2 in_stack_0000000a;
  
  if (this->have_focus == 0) {
    return 0;
  }
  pPVar1 = this->last_child_node;
  while( true ) {
    if (pPVar1 == (PanelNode *)0x0) {
      lVar3 = (**(code **)(this->_padding_ + 0xb0))(param_1,_param_2);
      return lVar3;
    }
    iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0x5c))(param_1,_param_2);
    if (iVar2 != 0) break;
    pPVar1 = pPVar1->prev_node;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: handle_command
// Address: 00465c30
long __thiscall TPanel::handle_command(TPanel *this,uint param_1,long param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: handle_user_command
// Address: 00465c40
long __thiscall TPanel::handle_user_command(TPanel *this,uint param_1,long param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: handle_timer_command
// Address: 00465c50
long __thiscall TPanel::handle_timer_command(TPanel *this,uint param_1,long param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: handle_scroll
// Address: 00465c60
long __thiscall TPanel::handle_scroll(TPanel *this,long param_1,long param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 00465c70
// [HELPER] s_C__msdev_work_age1_x1_Panel_cpp: "C:\msdev\work\age1_x1\Panel.cpp"
long __thiscall
TPanel::handle_mouse_down
          (TPanel *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  PanelNode *pPVar1;
  int iVar2;
  ulong uVar3;
  undefined3 in_stack_00000005;
  
  if (this->active == 0) {
    return 0;
  }
  if (this->mouse_captured == 0) {
    iVar2 = (**(code **)(this->_padding_ + 0xbc))(param_2,param_3);
    if (iVar2 == 0) {
      return 0;
    }
    for (pPVar1 = this->last_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->prev_node) {
      iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0x70))
                        (_param_1,param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    if (this->handle_mouse_input == 0) {
      return 0;
    }
    this->mouse_down_button = param_1;
    this->mouse_down_x = param_2;
    this->mouse_down_y = param_3;
    this->mouse_down_ctrl = param_4;
    this->mouse_down_shift = param_5;
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Panel_cpp,0x72c);
    this->mouse_down_time = uVar3;
    this->mouse_action = '\x01';
    if (((this->tab_stop != 0) && (this->parent_panel != (TPanel *)0x0)) &&
       (this->mouse_down_button == '\x01')) {
      set_curr_child(this->parent_panel,this);
    }
  }
  if (this->handle_mouse_input == 0) {
    return 0;
  }
  if (this->mouse_down_button != '\x01') {
    (**(code **)(this->_padding_ + 0x98))(param_2,param_3,param_4,param_5);
    return 1;
  }
  (**(code **)(this->_padding_ + 0x84))(param_2,param_3,param_4,param_5);
  return 1;
}

// --------------------------------------------------

// Function: handle_mouse_move
// Address: 00465dc0
long __thiscall
TPanel::handle_mouse_move(TPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  PanelNode *pPVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  int unaff_EBP;
  
  if (this->active == 0) {
    return 0;
  }
  if (this->mouse_captured == 0) {
    iVar2 = (**(code **)(this->_padding_ + 0xbc))(param_1,param_2);
    if (iVar2 == 0) {
      return 0;
    }
    pPVar1 = this->last_child_node;
    while( true ) {
      if (pPVar1 == (PanelNode *)0x0) {
        if (this->handle_mouse_input != 0) {
          lVar3 = (**(code **)(unaff_EBP + 0x80))(param_1,param_2,param_1,param_2);
          return lVar3;
        }
        return 0;
      }
      iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0x74))(param_1,param_2,param_1,param_2);
      if (iVar2 != 0) break;
      pPVar1 = pPVar1->prev_node;
    }
    return iVar2;
  }
  if (this->handle_mouse_input == 0) {
    return 0;
  }
  if ((this->mouse_action == '\x01') || (this->mouse_action == '\x02')) {
    if (this->mouse_down_button == '\x01') {
      uVar4 = param_1 - this->mouse_down_x;
      uVar5 = (int)uVar4 >> 0x1f;
      if (((int)((uVar4 ^ uVar5) - uVar5) <= this->mouse_move_tolerance) &&
         (uVar4 = param_2 - this->mouse_down_y, uVar5 = (int)uVar4 >> 0x1f,
         (int)((uVar4 ^ uVar5) - uVar5) <= this->mouse_move_tolerance)) {
        return 1;
      }
    }
    else {
      uVar4 = param_1 - this->mouse_down_x;
      uVar5 = (int)uVar4 >> 0x1f;
      if (((int)((uVar4 ^ uVar5) - uVar5) < 0xb) &&
         (uVar4 = param_2 - this->mouse_down_y, uVar5 = (int)uVar4 >> 0x1f,
         (int)((uVar4 ^ uVar5) - uVar5) < 0xb)) {
        return 1;
      }
    }
  }
  this->mouse_action = '\x03';
  if (this->mouse_down_button == '\x01') {
    (**(code **)(this->_padding_ + 0x8c))(param_1,param_2,param_3,param_4);
    return 1;
  }
  if (this->mouse_down_button != '\x02') {
    (**(code **)(this->_padding_ + 0x80))(param_1,param_2,param_3,param_4);
    return 1;
  }
  (**(code **)(this->_padding_ + 0xa0))();
  return 1;
}

// --------------------------------------------------

// Function: handle_mouse_up
// Address: 00465f70
long __thiscall
TPanel::handle_mouse_up
          (TPanel *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  int iVar1;
  long lVar2;
  undefined4 unaff_EBX;
  uchar unaff_SI;
  PanelNode *pPVar3;
  undefined4 unaff_retaddr;
  undefined3 in_stack_00000005;
  
  if (this->active == 0) {
    return 0;
  }
  if (this->mouse_captured == 0) {
    iVar1 = (**(code **)(this->_padding_ + 0xbc))(param_2,param_3);
    if (iVar1 == 0) {
      return 0;
    }
    pPVar3 = this->last_child_node;
    if (pPVar3 == (PanelNode *)0x0) {
      return 0;
    }
    while (lVar2 = (**(code **)(pPVar3->panel->_padding_ + 0x78))
                             (unaff_EBX,unaff_retaddr,_param_1,param_2,param_3), lVar2 == 0) {
      pPVar3 = pPVar3->prev_node;
      if (pPVar3 == (PanelNode *)0x0) {
        return 0;
      }
    }
  }
  else {
    if (this->handle_mouse_input == 0) {
      return 0;
    }
    if (this->mouse_down_button == '\x01') {
      iVar1 = (**(code **)(this->_padding_ + 0x90))();
    }
    else {
      iVar1 = (**(code **)(this->_padding_ + 0xa4))(param_2,param_3,param_4,param_5);
    }
    if (iVar1 != 0) {
      return 0;
    }
    if (unaff_SI == this->mouse_down_button) {
      this->mouse_down_button = '\0';
      this->mouse_action = '\0';
    }
    lVar2 = 1;
  }
  return lVar2;
}

// --------------------------------------------------

// Function: handle_mouse_dbl_click
// Address: 00466060
long __thiscall
TPanel::handle_mouse_dbl_click
          (TPanel *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  PanelNode *pPVar1;
  int iVar2;
  long lVar3;
  undefined4 unaff_EBP;
  undefined4 unaff_retaddr;
  undefined3 in_stack_00000005;
  
  if (this->active == 0) {
    return 0;
  }
  if (this->mouse_captured == 0) {
    iVar2 = (**(code **)(this->_padding_ + 0xbc))(param_2,param_3);
    if (iVar2 == 0) {
      return 0;
    }
    for (pPVar1 = this->last_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->prev_node) {
      iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0x7c))
                        (_param_1,param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  if (this->handle_mouse_input != 0) {
    if (param_1 == '\x01') {
      lVar3 = (**(code **)(this->_padding_ + 0x94))(param_2,param_3,param_4);
    }
    else {
      lVar3 = (**(code **)(this->_padding_ + 0xa8))(param_2,param_3,param_4,param_5);
    }
    if (lVar3 == 0) {
      (**(code **)(_param_1 + 0x70))(unaff_EBP,param_2,param_3,unaff_retaddr,param_5);
      lVar3 = 1;
    }
    return lVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: action
// Address: 00466140
long __thiscall
TPanel::action(TPanel *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  if (this->parent_panel != (TPanel *)0x0) {
    lVar1 = (**(code **)(this->parent_panel->_padding_ + 0xb4))(param_1,param_2,param_3,param_4);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_mouse_info
// Address: 00466170
void __thiscall
TPanel::get_mouse_info
          (TPanel *this,uint param_1,long param_2,tagPOINT *param_3,int *param_4,int *param_5)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 & 0xffff;
  uVar2 = (uint)param_2 >> 0x10;
  param_3->x = uVar1;
  param_3->y = uVar2;
  if (60000 < uVar1) {
    param_3->x = uVar1 - 0x10000;
  }
  if (60000 < uVar2) {
    param_3->y = uVar2 - 0x10000;
  }
  *param_4 = param_1 & 8;
  *param_5 = param_1 & 4;
  return;
}

// --------------------------------------------------

// Function: get_mouse_pos
// Address: 004661d0
void __thiscall TPanel::get_mouse_pos(TPanel *this,tagPOINT *param_1)
{
  GetCursorPos(param_1);
  if (this->render_area->DrawSystem->ScreenMode != '\x02') {
    ScreenToClient(this->render_area->Wnd,param_1);
    if (60000 < param_1->x) {
      param_1->x = param_1->x + -0x10000;
    }
    if (60000 < param_1->y) {
      param_1->y = param_1->y + -0x10000;
    }
  }
  return;
}

// --------------------------------------------------

// Function: capture_mouse
// Address: 00466220
int __thiscall TPanel::capture_mouse(TPanel *this)
{
  TPanel *pTVar1;
  
  pTVar1 = TPanelSystem::mouseOwner(&panel_system);
  if (pTVar1 != (TPanel *)0x0) {
    pTVar1 = TPanelSystem::mouseOwner(&panel_system);
    if (pTVar1 != this) {
      return 0;
    }
  }
  pTVar1 = TPanelSystem::mouseOwner(&panel_system);
  if (pTVar1 == this) {
    return 1;
  }
  SetCapture(this->render_area->Wnd);
  TPanelSystem::setMouseOwner(&panel_system,this);
  this->mouse_captured = 1;
  return 1;
}

// --------------------------------------------------

// Function: release_mouse
// Address: 00466280
void __thiscall TPanel::release_mouse(TPanel *this)
{
  TPanel *pTVar1;
  
  if (this->mouse_captured != 0) {
    pTVar1 = TPanelSystem::mouseOwner(&panel_system);
    if (pTVar1 == this) {
      TPanelSystem::setMouseOwner(&panel_system,(TPanel *)0x0);
      ReleaseCapture();
    }
    this->mouse_captured = 0;
  }
  return;
}

// --------------------------------------------------

// Function: is_redraw_needed
// Address: 004662c0
uchar __thiscall TPanel::is_redraw_needed(TPanel *this)
{
  if (((this->render_area != (TDrawArea *)0x0) && (this->visible != 0)) && (this->active != 0)) {
    return (char)this->need_redraw;
  }
  return '\0';
}

// --------------------------------------------------

// Function: is_inside
// Address: 004662e0
int __thiscall TPanel::is_inside(TPanel *this,long param_1,long param_2)
{
  if ((((this->active != 0) && ((this->clip_rect).left <= param_1)) &&
      (param_1 <= (this->clip_rect).right)) &&
     (((this->clip_rect).top <= param_2 && (param_2 <= (this->clip_rect).bottom)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: is_inside_rect
// Address: 00466320
int __thiscall TPanel::is_inside_rect(TPanel *this,long param_1,long param_2,tagRECT *param_3)
{
  if ((((param_3->left <= param_1) && (param_1 <= param_3->right)) && (param_3->top <= param_2)) &&
     (param_2 <= param_3->bottom)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: bound_point
// Address: 00466350
int __thiscall TPanel::bound_point(TPanel *this,long *param_1,long *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = (this->clip_rect).left + 1;
  if ((*param_1 < iVar2) || (iVar2 = (this->clip_rect).right + -1, iVar2 < *param_1)) {
    *param_1 = iVar2;
    iVar1 = 1;
  }
  iVar2 = (this->clip_rect).top + 1;
  if (*param_2 < iVar2) {
    *param_2 = iVar2;
    return 1;
  }
  iVar2 = (this->clip_rect).bottom + -1;
  if (iVar2 < *param_2) {
    *param_2 = iVar2;
    iVar1 = 1;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: set_curr_child
// Address: 004663a0
void __thiscall TPanel::set_curr_child(TPanel *this,TPanel *param_1)
{
  TPanel *pTVar1;
  
  pTVar1 = this->curr_child;
  if (param_1 != pTVar1) {
    if ((pTVar1 != (TPanel *)0x0) && (this->have_focus != 0)) {
      (**(code **)(pTVar1->_padding_ + 0xc0))(0);
    }
    this->curr_child = param_1;
    if ((param_1 != (TPanel *)0x0) && (this->have_focus != 0)) {
      (**(code **)(param_1->_padding_ + 0xc0))(1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_focus
// Address: 004663f0
void __thiscall TPanel::set_focus(TPanel *this,int param_1)
{
  if (param_1 != this->have_focus) {
    this->have_focus = param_1;
    (**(code **)(this->_padding_ + 0x20))(1);
    if (this->curr_child != (TPanel *)0x0) {
      (**(code **)(this->curr_child->_padding_ + 0xc0))(this->have_focus);
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_focus
// Address: 00466420
int __thiscall TPanel::get_focus(TPanel *this)
{
  return this->have_focus;
}

// --------------------------------------------------

// Function: set_z_order
// Address: 00466430
void __thiscall TPanel::set_z_order(TPanel *this,uchar param_1,short param_2)
{
  if (this->parent_panel != (TPanel *)0x0) {
    set_child_z_order(this->parent_panel,this,param_1,param_2);
    return;
  }
  if (param_1 == '\0') {
    this->z_order = (int)param_2;
  }
  else {
    if (param_1 == '\x01') {
      this->z_order = 0;
      return;
    }
    if (param_1 == '\x02') {
      this->z_order = 0;
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_child_z_order
// Address: 00466490
void __thiscall TPanel::set_child_z_order(TPanel *this,TPanel *param_1,uchar param_2,short param_3)
{
  TPanel *pTVar1;
  int iVar2;
  bool bVar3;
  PanelNode *pPVar4;
  PanelNode *pPVar5;
  short sVar6;
  
  if (param_2 == '\0') {
    pPVar5 = this->first_child_node;
    bVar3 = false;
    if (pPVar5 != (PanelNode *)0x0) {
      pPVar4 = pPVar5;
      do {
        if (pPVar4->panel->z_order == (int)param_3) {
          bVar3 = true;
          break;
        }
        pPVar4 = pPVar4->next_node;
      } while (pPVar4 != (PanelNode *)0x0);
    }
    if ((bVar3) && (pPVar5 != (PanelNode *)0x0)) {
      do {
        iVar2 = pPVar5->panel->z_order;
        if (param_3 <= iVar2) {
          pPVar5->panel->z_order = iVar2 + 1;
        }
        pPVar5 = pPVar5->next_node;
      } while (pPVar5 != (PanelNode *)0x0);
    }
    param_1->z_order = (int)param_3;
  }
  else if (param_2 == '\x01') {
    sVar6 = 0;
    for (pPVar5 = this->first_child_node; pPVar5 != (PanelNode *)0x0; pPVar5 = pPVar5->next_node) {
      pTVar1 = pPVar5->panel;
      if ((pTVar1 != param_1) && ((int)sVar6 < pTVar1->z_order)) {
        sVar6 = (short)pTVar1->z_order;
      }
    }
    param_1->z_order = sVar6 + 1;
  }
  else if (param_2 == '\x02') {
    sVar6 = 0;
    for (pPVar5 = this->first_child_node; pPVar5 != (PanelNode *)0x0; pPVar5 = pPVar5->next_node) {
      pTVar1 = pPVar5->panel;
      if ((pTVar1 != param_1) && (pTVar1->z_order < (int)sVar6)) {
        sVar6 = (short)pTVar1->z_order;
      }
    }
    param_1->z_order = sVar6 + -1;
  }
  pPVar5 = this->first_child_node;
  pTVar1 = this->curr_child;
  this->curr_child = (TPanel *)0x0;
  for (; pPVar4 = (PanelNode *)0x0, pPVar5 != (PanelNode *)0x0; pPVar5 = pPVar5->next_node) {
    if (pPVar5->panel == param_1) {
      remove_panel_node(this,pPVar5);
      pPVar4 = pPVar5;
      break;
    }
  }
  if (pPVar4 != (PanelNode *)0x0) {
    pPVar5 = this->first_child_node;
    bVar3 = false;
    if (pPVar5 != (PanelNode *)0x0) {
      do {
        if (param_1->z_order < pPVar5->panel->z_order) {
          add_panel_node(this,pPVar4,pPVar5,0);
          bVar3 = true;
          break;
        }
        pPVar5 = pPVar5->next_node;
      } while (pPVar5 != (PanelNode *)0x0);
    }
    if (!bVar3) {
      add_panel_node(this,pPVar4,this->last_child_node,1);
    }
  }
  this->curr_child = pTVar1;
  return;
}

// --------------------------------------------------

// Function: set_tab_order
// Address: 00466600
void __thiscall TPanel::set_tab_order(TPanel *this,TPanel **param_1,short param_2)
{
  TPanel *pTVar1;
  TPanel *pTVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_2;
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      if (iVar4 == 0) {
        pTVar2 = param_1[iVar3 + -1];
      }
      else {
        pTVar2 = param_1[iVar4 + -1];
      }
      if (iVar4 == iVar3 + -1) {
        pTVar1 = *param_1;
      }
      else {
        pTVar1 = param_1[iVar4 + 1];
      }
      (**(code **)(param_1[iVar4]->_padding_ + 0xc4))(pTVar2,pTVar1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: set_tab_order
// Address: 00466650
void __thiscall TPanel::set_tab_order(TPanel *this,TPanel *param_1,TPanel *param_2)
{
  this->tab_prev_panel = param_1;
  this->tab_next_panel = param_2;
  this->tab_stop = 1;
  return;
}

// --------------------------------------------------

// Function: previousPanel
// Address: 00466670
TPanel * __thiscall TPanel::previousPanel(TPanel *this)
{
  return this->previousPanelValue;
}

// --------------------------------------------------

// Function: setPreviousPanel
// Address: 00466680
void __thiscall TPanel::setPreviousPanel(TPanel *this,TPanel *param_1)
{
  this->previousPanelValue = param_1;
  return;
}

// --------------------------------------------------

// Function: previousModalPanel
// Address: 00466690
TPanel * __thiscall TPanel::previousModalPanel(TPanel *this)
{
  return this->previousModalPanelValue;
}

// --------------------------------------------------

// Function: setPreviousModalPanel
// Address: 004666a0
void __thiscall TPanel::setPreviousModalPanel(TPanel *this,TPanel *param_1)
{
  this->previousModalPanelValue = param_1;
  return;
}

// --------------------------------------------------

// Function: panelName
// Address: 004666b0
char * __thiscall TPanel::panelName(TPanel *this)
{
  return this->panelNameValue;
}

// --------------------------------------------------

// Function: setPanelName
// Address: 004666c0
void __thiscall TPanel::setPanelName(TPanel *this,char *param_1)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  if (param_1 == (char *)0x0) {
LAB_00466748:
    if (this->panelNameValue != (char *)0x0) {
      free(this->panelNameValue);
      this->panelNameValue = (char *)0x0;
    }
    return;
  }
  iVar3 = -1;
  pcVar2 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar3 == -2) goto LAB_00466748;
  pcVar2 = this->panelNameValue;
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar6 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar5 = 0xffffffff;
    pcVar6 = pcVar2;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (~uVar4 - 1 <= ~uVar5 - 1) goto LAB_00466721;
    if (pcVar2 != (char *)0x0) {
      free(pcVar2);
    }
  }
  uVar4 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)malloc(~uVar4);
  this->panelNameValue = pcVar2;
LAB_00466721:
  uVar4 = 0xffffffff;
  do {
    pcVar2 = param_1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar2;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar2 + -uVar4;
  pcVar6 = this->panelNameValue;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: xPosition
// Address: 00466770
long __thiscall TPanel::xPosition(TPanel *this)
{
  return this->pnl_x;
}

// --------------------------------------------------

// Function: yPosition
// Address: 00466780
long __thiscall TPanel::yPosition(TPanel *this)
{
  return this->pnl_y;
}

// --------------------------------------------------

// Function: width
// Address: 00466790
long __thiscall TPanel::width(TPanel *this)
{
  return this->pnl_wid;
}

// --------------------------------------------------

// Function: height
// Address: 004667a0
long __thiscall TPanel::height(TPanel *this)
{
  return this->pnl_hgt;
}

// --------------------------------------------------

// Function: renderArea
// Address: 004667b0
TDrawArea * __thiscall TPanel::renderArea(TPanel *this)
{
  return this->render_area;
}

// --------------------------------------------------

// Function: clipRectangle
// Address: 004667c0
tagRECT * __thiscall TPanel::clipRectangle(TPanel *this,tagRECT *__return_storage_ptr__)
{
  tagRECT *___ReturnUdt;
  
  __return_storage_ptr__->left = (this->clip_rect).left;
  __return_storage_ptr__->top = (this->clip_rect).top;
  __return_storage_ptr__->right = (this->clip_rect).right;
  __return_storage_ptr__->bottom = (this->clip_rect).bottom;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: setClipRectangle
// Address: 004667f0
void __thiscall TPanel::setClipRectangle(TPanel *this,tagRECT param_1)
{
  (this->clip_rect).left = param_1.left;
  (this->clip_rect).top = param_1.top;
  (this->clip_rect).right = param_1.right;
  (this->clip_rect).bottom = param_1.bottom;
  return;
}

// --------------------------------------------------

// Function: delete_panel
// Address: 00466820
void __thiscall TPanel::delete_panel(TPanel *this,TPanel **param_1)
{
  if (*param_1 != (TPanel *)0x0) {
    (**(code **)(*param_1)->_padding_)(1);
    *param_1 = (TPanel *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: get_string
// Address: 00466840
int __thiscall TPanel::get_string(TPanel *this,int param_1,char *param_2,int param_3)
{
  (**(code **)(rge_base_game->_padding_ + 0x20))(param_1,param_2,param_3);
  return (uint)(*param_2 != '\0');
}

// --------------------------------------------------

// Function: get_string
// Address: 00466870
char * __thiscall TPanel::get_string(TPanel *this,int param_1)
{
  get_string(this,param_1,&UNK_0062e66c.field_0x4,0x200);
  return &UNK_0062e66c.field_0x4;
}

// --------------------------------------------------

// Function: get_help_message
// Address: 00466890
long __thiscall TPanel::get_help_message(TPanel *this)
{
  return this->help_string_id;
}

// --------------------------------------------------

// Function: get_help_page
// Address: 004668a0
long __thiscall TPanel::get_help_page(TPanel *this)
{
  return this->help_page_id;
}

// --------------------------------------------------

// Function: set_help_info
// Address: 004668b0
void __thiscall TPanel::set_help_info(TPanel *this,long param_1,long param_2)
{
  this->help_string_id = param_1;
  this->help_page_id = param_2;
  return;
}

// --------------------------------------------------

// Function: get_help_info
// Address: 004668d0
uchar __thiscall
TPanel::get_help_info(TPanel *this,char **param_1,long *param_2,long param_3,long param_4)
{
  PanelNode *pPVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  TPanel *unaff_EBP;
  char *pcVar7;
  long *unaff_retaddr;
  
  if ((this->active != 0) &&
     (iVar3 = (**(code **)(this->_padding_ + 0xbc))(param_3,param_4), iVar3 != 0)) {
    for (pPVar1 = this->last_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->prev_node) {
      cVar2 = (**(code **)(pPVar1->panel->_padding_ + 0xcc))(this,unaff_retaddr,param_1,param_4);
      if (cVar2 != '\0') {
        return '\x01';
      }
    }
    if (-1 < unaff_EBP->help_string_id) {
      pcVar4 = get_string(unaff_EBP,unaff_EBP->help_string_id);
      uVar5 = 0xffffffff;
      do {
        pcVar7 = pcVar4;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar7 = pcVar4 + 1;
        cVar2 = *pcVar4;
        pcVar4 = pcVar7;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar4 = pcVar7 + -uVar5;
      pcVar7 = (char *)this->_padding_;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar7 = pcVar7 + 1;
      }
      *unaff_retaddr = unaff_EBP->help_page_id;
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: stop_sound_system
// Address: 00466980
void __thiscall TPanel::stop_sound_system(TPanel *this)
{
  PanelNode *pPVar1;
  
  for (pPVar1 = this->first_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->next_node) {
    (**(code **)(pPVar1->panel->_padding_ + 0xd0))();
  }
  return;
}

// --------------------------------------------------

// Function: restart_sound_system
// Address: 004669a0
int __thiscall TPanel::restart_sound_system(TPanel *this)
{
  PanelNode *pPVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  for (pPVar1 = this->first_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->next_node) {
    iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0xd4))();
    if (iVar2 == 0) {
      iVar3 = 0;
    }
  }
  return iVar3;
}

// --------------------------------------------------

// Function: handle_reactivate
// Address: 004669d0
void __thiscall TPanel::handle_reactivate(TPanel *this)
{
  PanelNode *pPVar1;
  
  for (pPVar1 = this->first_child_node; pPVar1 != (PanelNode *)0x0; pPVar1 = pPVar1->next_node) {
    (**(code **)(pPVar1->panel->_padding_ + 0xdc))();
  }
  return;
}

// --------------------------------------------------

// Function: get_true_render_rect
// Address: 004669f0
void __thiscall TPanel::get_true_render_rect(TPanel *this,tagRECT *param_1)
{
  param_1->left = (this->render_rect).left;
  param_1->top = (this->render_rect).top;
  param_1->right = (this->render_rect).right;
  param_1->bottom = (this->render_rect).bottom;
  return;
}

// --------------------------------------------------

