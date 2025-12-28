// Class: Time_Line_Panel
// Size:  0x52C
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
//
// Member Layout:
// [0x478] void * axis_font
// [0x47C] long axis_font_wid
// [0x480] long axis_font_hgt
// [0x484] void * body_font
// [0x488] long body_font_wid
// [0x48C] long body_font_hgt
// [0x490] Style text_style
// [0x494] ulong text_color1
// [0x498] ulong text_color2
// [0x49C] ulong highlightTextColor1
// [0x4A0] ulong highlightTextColor2
// [0x4A4] long text_wid
// [0x4A8] long text_hgt
// [0x4AC] TShape * background_pic
// [0x4B0] short background_pic_wid
// [0x4B2] short background_pic_hgt
// [0x4B4] int fill_back
// [0x4B8] uchar back_color
// [0x4BC] int outline
// [0x4C0] uchar outline_color
// [0x4C4] int sorted
// [0x4C8] int bevel_type
// [0x4CC] uchar bevel_color1
// [0x4CD] uchar bevel_color2
// [0x4CE] uchar bevel_color3
// [0x4CF] uchar bevel_color4
// [0x4D0] uchar bevel_color5
// [0x4D1] uchar bevel_color6
// [0x4D4] TShape * special_events_pic
// [0x4D8] short special_events_pic_wid
// [0x4DA] short special_events_pic_hgt
// [0x4DC] long X_start_line_pos
// [0x4E0] long Y_start_line_pos
// [0x4E4] long X_line_pos
// [0x4E8] long Y_line_pos
// [0x4EC] long X_line_max_width
// [0x4F0] long Y_line_max_length
// [0x4F4] long X_axis_length
// [0x4F8] long Y_axis_length
// [0x4FC] float bar_thickness
// [0x500] long pop_reading_rate
// [0x504] float time_slice_drop_rate
// [0x508] long total_slices_to_drop
// [0x50C] uchar drop_flag
// [0x510] long num_entries_page
// [0x514] long num_history_entries
// [0x518] Special_Events * time_slice_events
// [0x51C] uchar timeline_flag
// [0x520] TTextPanel *[3] legend_entry_text (sz: 0xC)
// ----------------------------------------------------------------

// Function: Time_Line_Panel
// Address: 0051e650
Time_Line_Panel * __thiscall Time_Line_Panel::Time_Line_Panel(Time_Line_Panel *this)
{
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)this);
  this->text_style = ChiseledStyle;
  this->axis_font = (void *)0x0;
  this->axis_font_wid = 0;
  this->axis_font_hgt = 0;
  this->body_font = (void *)0x0;
  this->body_font_wid = 0;
  this->body_font_hgt = 0;
  this->text_color1 = 0xffffff;
  this->text_color2 = 0;
  this->highlightTextColor1 = 0xffff;
  this->highlightTextColor2 = 0;
  this->text_wid = 0;
  this->text_hgt = 0;
  this->background_pic = (TShape *)0x0;
  this->background_pic_wid = 0;
  this->background_pic_hgt = 0;
  this->fill_back = 0;
  this->back_color = 0xff;
  this->outline = 0;
  this->outline_color = '\0';
  this->bevel_type = 0;
  this->bevel_color1 = '\0';
  this->bevel_color2 = '\0';
  this->bevel_color3 = '\0';
  this->bevel_color4 = '\0';
  this->bevel_color5 = '\0';
  this->bevel_color6 = '\0';
  this->special_events_pic = (TShape *)0x0;
  this->special_events_pic_wid = 0;
  this->special_events_pic_hgt = 0;
  this->total_slices_to_drop = 0;
  this->time_slice_events = (Special_Events *)0x0;
  this->_padding_ = (int)&_vftable_;
  this->_padding_ = 0;
  this->timeline_flag = '\x01';
  this->drop_flag = '\0';
  this->pop_reading_rate = 0xc;
  this->legend_entry_text[0] = (TTextPanel *)0x0;
  this->legend_entry_text[1] = (TTextPanel *)0x0;
  this->legend_entry_text[2] = (TTextPanel *)0x0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0051e770
void * __thiscall Time_Line_Panel::_scalar_deleting_destructor_(Time_Line_Panel *this,uint param_1)
{
  ~Time_Line_Panel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~Time_Line_Panel
// Address: 0051e790
void __thiscall Time_Line_Panel::~Time_Line_Panel(Time_Line_Panel *this)
{
  Special_Events *pSVar1;
  TShape *pTVar2;
  int iVar3;
  TTextPanel **ppTVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561468;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  pSVar1 = this->time_slice_events;
  local_4 = 0;
  while (pSVar1 != (Special_Events *)0x0) {
    this->time_slice_events = pSVar1->next;
    free(pSVar1);
    pSVar1 = this->time_slice_events;
  }
  pTVar2 = this->background_pic;
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
    this->background_pic = (TShape *)0x0;
  }
  pTVar2 = this->special_events_pic;
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
    this->special_events_pic = (TShape *)0x0;
  }
  ppTVar4 = this->legend_entry_text;
  iVar3 = 3;
  do {
    TPanel::delete_panel((TPanel *)this,(TPanel **)ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_4 = 0xffffffff;
  TEasy_Panel::~TEasy_Panel((TEasy_Panel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: create_timeline
// Address: 0051e860
long __thiscall
Time_Line_Panel::create_timeline
          (Time_Line_Panel *this,TPanel *param_1,Time_Line_Panel **param_2,long param_3,long param_4
          ,long param_5,long param_6,long param_7,long param_8,long param_9,long param_10)
{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  Time_Line_Panel *pTVar6;
  RGE_Font *pRVar7;
  RGE_Font *pRVar8;
  TDrawArea *pTVar9;
  undefined4 *unaff_FS_OFFSET;
  TPanel *parent;
  void *pvVar10;
  long lVar11;
  long lVar12;
  void *pvVar13;
  long lVar14;
  char *pcVar15;
  char *pcVar16;
  int iVar17;
  uchar uVar18;
  int iVar19;
  uchar uVar20;
  undefined4 local_c;
  code *pcStack_8;
  Time_Line_Panel *this;
  
  this = (Time_Line_Panel *)0xffffffff;
  pcStack_8 = FUN_0056148b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  lVar1 = TPanel::width(param_1);
  iVar2 = (lVar1 * param_3) / param_9;
  lVar1 = TPanel::height(param_1);
  iVar3 = (lVar1 * param_4) / param_10;
  lVar1 = TPanel::width(param_1);
  iVar4 = (lVar1 * param_5) / param_9;
  lVar1 = TPanel::height(param_1);
  iVar5 = (lVar1 * param_6) / param_10;
  pTVar6 = (Time_Line_Panel *)operator_new(0x52c);
  this = (Time_Line_Panel *)0x0;
  if (pTVar6 == (Time_Line_Panel *)0x0) {
    pTVar6 = (Time_Line_Panel *)0x0;
  }
  else {
    pTVar6 = (Time_Line_Panel *)Time_Line_Panel(pTVar6);
  }
  this = (Time_Line_Panel *)0xffffffff;
  *param_2 = pTVar6;
  if ((pTVar6 == (Time_Line_Panel *)0x0) || (pTVar6->_padding_ != 0)) {
    this->_padding_ = 1;
  }
  else {
    if (param_7 < 0) {
      param_7 = 0xb;
    }
    pRVar7 = RGE_Base_Game::get_font(rge_base_game,param_7);
    if (param_8 < 0) {
      param_8 = 0xb;
    }
    pRVar8 = RGE_Base_Game::get_font(rge_base_game,param_8);
    lVar1 = pRVar8->font_hgt;
    lVar14 = pRVar8->font_wid;
    uVar20 = '\0';
    iVar19 = 0;
    uVar18 = '\0';
    iVar17 = 0;
    pcVar16 = (char *)0x0;
    pcVar15 = (char *)0x0;
    pvVar13 = pRVar8->font;
    lVar12 = pRVar7->font_hgt;
    lVar11 = pRVar7->font_wid;
    pvVar10 = pRVar7->font;
    pTVar9 = TPanel::renderArea(param_1);
    lVar1 = setup(*param_2,pTVar9,param_1,iVar2,iVar3,iVar4,iVar5,pvVar10,lVar11,lVar12,pvVar13,
                  lVar14,lVar1,pcVar15,pcVar16,iVar17,uVar18,iVar19,uVar20);
    if (lVar1 != 0) {
      init_timeline(*param_2);
      lVar1 = 1;
      goto LAB_0051e9c4;
    }
    this->_padding_ = 1;
  }
  lVar1 = 0;
LAB_0051e9c4:
  *unaff_FS_OFFSET = local_c;
  return lVar1;
}

// --------------------------------------------------

// Function: setup
// Address: 0051e9e0
long __thiscall
Time_Line_Panel::setup
          (Time_Line_Panel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
          long param_5,long param_6,void *param_7,long param_8,long param_9,void *param_10,
          long param_11,long param_12,char *param_13,char *param_14,int param_15,uchar param_16,
          int param_17,uchar param_18)
{
  uchar uVar1;
  
  TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  this->fill_back = param_15;
  this->back_color = param_16;
  this->outline = param_17;
  this->outline_color = param_18;
  if (param_17 != 0) {
    this->bevel_type = 1;
  }
  set_axis_font(this,param_7,param_8,param_9);
  set_body_font(this,param_10,param_11,param_12);
  set_background(this,param_13);
  set_special_events(this,param_14);
  uVar1 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)this->_padding_ + 8),0);
  set_back_color(this,1,uVar1);
  return 1;
}

// --------------------------------------------------

// Function: set_bevel_info
// Address: 0051eab0
void __thiscall
Time_Line_Panel::set_bevel_info
          (Time_Line_Panel *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6,int param_7)
{
  this->bevel_type = param_1;
  this->bevel_color1 = (uchar)param_2;
  this->bevel_color2 = (uchar)param_3;
  this->bevel_color3 = (uchar)param_4;
  this->bevel_color4 = (uchar)param_5;
  this->bevel_color5 = (uchar)param_6;
  this->bevel_color6 = (uchar)param_7;
  return;
}

// --------------------------------------------------

// Function: set_background
// Address: 0051eb00
int __thiscall Time_Line_Panel::set_background(Time_Line_Panel *this,char *param_1)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  long x_max;
  long x_min;
  long y_max;
  long y_min;
  short local_10 [2];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005614ab;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = this->background_pic;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    this->background_pic = (TShape *)0x0;
    this->background_pic_wid = 0;
    this->background_pic_hgt = 0;
  }
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    pTVar1 = (TShape *)operator_new(0x20);
    local_4 = 0;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,param_1,-1);
    }
    local_4 = 0xffffffff;
    this->background_pic = pTVar1;
    TShape::shape_minmax(pTVar1,&y_max,(long *)local_10,&x_min,&y_min,0);
    this->background_pic_wid = ((short)x_min - (short)y_max) + 1;
    this->background_pic_hgt = ((short)y_min - local_10[0]) + 1;
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
  *unaff_FS_OFFSET = local_c;
  return 0;
}

// --------------------------------------------------

// Function: set_background
// Address: 0051ec10
// [HELPER] s_: ""
// [HELPER] s__s: "%s"
// [HELPER] s__s_shp: "%s.shp"
// [HELPER] s_none: "none"
int __thiscall Time_Line_Panel::set_background(Time_Line_Panel *this,char *param_1,long param_2)
{
  int iVar1;
  TShape *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  long y_max;
  long y_min;
  long x_min;
  short local_11c [2];
  long x_max;
  char file_name2 [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005614dc;
  *unaff_FS_OFFSET = &local_c;
  pTVar2 = this->background_pic;
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
    this->background_pic = (TShape *)0x0;
    this->background_pic_wid = 0;
    this->background_pic_hgt = 0;
  }
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
     (iVar1 = stricmp(param_1,s_none), iVar1 == 0)) {
    if (param_2 == -1) goto LAB_0051ed29;
    x_max = (long)operator_new(0x20);
    local_4 = 1;
    if ((TShape *)x_max == (TShape *)0x0) goto LAB_0051ed16;
    pTVar2 = (TShape *)TShape::TShape((TShape *)x_max,s_,param_2);
  }
  else {
    iVar1 = strchr(param_1,0x2e);
    if (iVar1 == 0) {
      pcVar3 = s__s_shp;
    }
    else {
      pcVar3 = s__s;
    }
    sprintf(file_name2 + 4,pcVar3,param_1);
    x_max = (long)operator_new(0x20);
    local_4 = 0;
    if ((TShape *)x_max == (TShape *)0x0) {
LAB_0051ed16:
      pTVar2 = (TShape *)0x0;
    }
    else {
      pTVar2 = (TShape *)TShape::TShape((TShape *)x_max,file_name2 + 4,param_2);
    }
  }
  local_4 = 0xffffffff;
  this->background_pic = pTVar2;
LAB_0051ed29:
  if ((this->background_pic != (TShape *)0x0) &&
     (iVar1 = TShape::is_loaded(this->background_pic), iVar1 == 0)) {
    pTVar2 = this->background_pic;
    if (pTVar2 != (TShape *)0x0) {
      TShape::~TShape(pTVar2);
      operator_delete(pTVar2);
    }
    this->background_pic = (TShape *)0x0;
  }
  pTVar2 = this->background_pic;
  if (pTVar2 != (TShape *)0x0) {
    TShape::shape_minmax(pTVar2,(long *)local_11c,&x_min,(long *)file_name2,&y_min,0);
    this->background_pic_wid = (file_name2._0_2_ - local_11c[0]) + 1;
    this->background_pic_hgt = ((short)y_min - (short)x_min) + 1;
  }
  *unaff_FS_OFFSET = local_c;
  return (uint)(pTVar2 != (TShape *)0x0);
}

// --------------------------------------------------

// Function: set_special_events
// Address: 0051edd0
int __thiscall Time_Line_Panel::set_special_events(Time_Line_Panel *this,char *param_1)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  long x_max;
  long x_min;
  long y_max;
  long y_min;
  short local_10 [2];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005614fb;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = this->special_events_pic;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    this->special_events_pic = (TShape *)0x0;
    this->special_events_pic_wid = 0;
    this->special_events_pic_hgt = 0;
  }
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    pTVar1 = (TShape *)operator_new(0x20);
    local_4 = 0;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,param_1,-1);
    }
    local_4 = 0xffffffff;
    this->special_events_pic = pTVar1;
    TShape::shape_minmax(pTVar1,&y_max,(long *)local_10,&x_min,&y_min,0);
    this->special_events_pic_wid = ((short)x_min - (short)y_max) + 1;
    this->special_events_pic_hgt = ((short)y_min - local_10[0]) + 1;
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
  *unaff_FS_OFFSET = local_c;
  return 0;
}

// --------------------------------------------------

// Function: set_special_events
// Address: 0051eee0
// [HELPER] s_: ""
// [HELPER] s__s: "%s"
// [HELPER] s__s_shp: "%s.shp"
// [HELPER] s_none: "none"
int __thiscall Time_Line_Panel::set_special_events(Time_Line_Panel *this,char *param_1,long param_2)
{
  int iVar1;
  TShape *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  long y_max;
  long y_min;
  long x_min;
  short local_11c [2];
  long x_max;
  char file_name2 [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056152c;
  *unaff_FS_OFFSET = &local_c;
  pTVar2 = this->special_events_pic;
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
    this->special_events_pic = (TShape *)0x0;
    this->special_events_pic_wid = 0;
    this->special_events_pic_hgt = 0;
  }
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
     (iVar1 = stricmp(param_1,s_none), iVar1 == 0)) {
    if (param_2 == -1) goto LAB_0051eff9;
    x_max = (long)operator_new(0x20);
    local_4 = 1;
    if ((TShape *)x_max == (TShape *)0x0) goto LAB_0051efe6;
    pTVar2 = (TShape *)TShape::TShape((TShape *)x_max,s_,param_2);
  }
  else {
    iVar1 = strchr(param_1,0x2e);
    if (iVar1 == 0) {
      pcVar3 = s__s_shp;
    }
    else {
      pcVar3 = s__s;
    }
    sprintf(file_name2 + 4,pcVar3,param_1);
    x_max = (long)operator_new(0x20);
    local_4 = 0;
    if ((TShape *)x_max == (TShape *)0x0) {
LAB_0051efe6:
      pTVar2 = (TShape *)0x0;
    }
    else {
      pTVar2 = (TShape *)TShape::TShape((TShape *)x_max,file_name2 + 4,param_2);
    }
  }
  local_4 = 0xffffffff;
  this->special_events_pic = pTVar2;
LAB_0051eff9:
  if ((this->special_events_pic != (TShape *)0x0) &&
     (iVar1 = TShape::is_loaded(this->special_events_pic), iVar1 == 0)) {
    pTVar2 = this->special_events_pic;
    if (pTVar2 != (TShape *)0x0) {
      TShape::~TShape(pTVar2);
      operator_delete(pTVar2);
    }
    this->special_events_pic = (TShape *)0x0;
  }
  pTVar2 = this->special_events_pic;
  if (pTVar2 != (TShape *)0x0) {
    TShape::shape_minmax(pTVar2,(long *)local_11c,&x_min,(long *)file_name2,&y_min,0);
    this->special_events_pic_wid = (file_name2._0_2_ - local_11c[0]) + 1;
    this->special_events_pic_hgt = ((short)y_min - (short)x_min) + 1;
  }
  *unaff_FS_OFFSET = local_c;
  return (uint)(pTVar2 != (TShape *)0x0);
}

// --------------------------------------------------

// Function: set_axis_font
// Address: 0051f0a0
void __thiscall
Time_Line_Panel::set_axis_font(Time_Line_Panel *this,void *param_1,long param_2,long param_3)
{
  this->axis_font = param_1;
  this->axis_font_wid = param_2;
  this->axis_font_hgt = param_3;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_body_font
// Address: 0051f0d0
void __thiscall
Time_Line_Panel::set_body_font(Time_Line_Panel *this,void *param_1,long param_2,long param_3)
{
  this->body_font = param_1;
  this->body_font_wid = param_2;
  this->body_font_hgt = param_3;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_back_color
// Address: 0051f100
void __thiscall Time_Line_Panel::set_back_color(Time_Line_Panel *this,int param_1,uchar param_2)
{
  this->fill_back = param_1;
  this->back_color = param_2;
  return;
}

// --------------------------------------------------

// Function: draw_border
// Address: 0051f120
// [HELPER] s_tpnl_tml__draw_border: "tpnl_tml::draw_border"
void __thiscall Time_Line_Panel::draw_border(Time_Line_Panel *this)
{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  uchar *puVar7;
  int iVar8;
  int iVar9;
  
  if (this->bevel_type == 0) {
    return;
  }
  puVar7 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_border,1);
  if (puVar7 == (uchar *)0x0) goto switchD_0051f158_default;
  switch(this->bevel_type) {
  case 1:
    TDrawArea::DrawRect((TDrawArea *)this->_padding_,this->_padding_,this->_padding_,
                        this->_padding_ + -1 + this->_padding_,
                        this->_padding_ + -1 + this->_padding_,this->outline_color);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_border);
    return;
  case 2:
    uVar1 = this->bevel_color1;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color6;
    goto LAB_0051f217;
  case 3:
    uVar1 = this->bevel_color1;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color2;
    uVar3 = this->bevel_color5;
    uVar4 = this->bevel_color6;
    goto LAB_0051f262;
  case 4:
    uVar1 = this->bevel_color1;
    iVar8 = this->_padding_;
    uVar2 = this->bevel_color2;
    uVar3 = this->bevel_color3;
    iVar9 = this->_padding_;
    uVar4 = this->bevel_color4;
    uVar5 = this->bevel_color5;
    uVar6 = this->bevel_color6;
    break;
  case 5:
    uVar1 = this->bevel_color6;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color1;
LAB_0051f217:
    TDrawArea::DrawBevel
              ((TDrawArea *)this->_padding_,iVar9,iVar8,this->_padding_ + -1 + iVar9,
               this->_padding_ + -1 + iVar8,uVar2,uVar1);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_border);
    return;
  case 6:
    uVar1 = this->bevel_color6;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color5;
    uVar3 = this->bevel_color2;
    uVar4 = this->bevel_color1;
LAB_0051f262:
    TDrawArea::DrawBevel2
              ((TDrawArea *)this->_padding_,iVar9,iVar8,this->_padding_ + -1 + iVar9,
               this->_padding_ + -1 + iVar8,uVar4,uVar3,uVar2,uVar1);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_border);
    return;
  case 7:
    uVar1 = this->bevel_color6;
    iVar8 = this->_padding_;
    uVar2 = this->bevel_color5;
    uVar3 = this->bevel_color4;
    iVar9 = this->_padding_;
    uVar4 = this->bevel_color3;
    uVar5 = this->bevel_color2;
    uVar6 = this->bevel_color1;
    break;
  default:
    goto switchD_0051f158_default;
  }
  TDrawArea::DrawBevel3
            ((TDrawArea *)this->_padding_,iVar9,iVar8,this->_padding_ + -1 + iVar9,
             this->_padding_ + -1 + iVar8,uVar6,uVar5,uVar4,uVar3,uVar2,uVar1);
switchD_0051f158_default:
  TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_border);
  return;
}

// --------------------------------------------------

// Function: init_timeline
// Address: 0051f310
void __thiscall Time_Line_Panel::init_timeline(Time_Line_Panel *this)
{
  bool bVar1;
  float fVar2;
  RGE_Game_World *pRVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long usable_X;
  
  iVar5 = 0;
  this->num_history_entries = 0;
  pRVar3 = rge_base_game->world;
  if (pRVar3->player_num != 1 && -1 < pRVar3->player_num + -1) {
    iVar6 = 4;
    do {
      lVar4 = TRIBE_History_Info::get_history_entry_num
                        (*(TRIBE_History_Info **)(*(int *)((int)pRVar3->players + iVar6) + 0x83c));
      if (this->num_history_entries < lVar4) {
        this->num_history_entries = lVar4;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 4;
      pRVar3 = rge_base_game->world;
    } while (iVar5 < pRVar3->player_num + -1);
  }
  lVar4 = TPanel::width((TPanel *)this);
  iVar5 = lVar4 + -0x31;
  if (this->num_history_entries == 0) {
    this->num_history_entries = 1;
    this->timeline_flag = '\0';
  }
  iVar6 = this->num_history_entries;
  this->time_slice_drop_rate = 0.0;
  fVar2 = (float)iVar5 / (float)iVar6;
  bVar1 = _DAT_005770b0 <= fVar2;
  this->bar_thickness = fVar2;
  if (bVar1) {
    this->num_entries_page = iVar6;
  }
  else {
    this->bar_thickness = 1.0;
    this->num_entries_page = iVar5;
    this->drop_flag = '\x01';
    this->total_slices_to_drop = iVar6 - iVar5;
    this->time_slice_drop_rate = (float)iVar5 / (float)(iVar6 - iVar5);
  }
  iVar5 = __ftol();
  this->X_axis_length = iVar5 + 4;
  lVar4 = TPanel::height((TPanel *)this);
  this->Y_axis_length = lVar4 + this->axis_font_hgt * -4 + -0x1a;
  lVar4 = TPanel::xPosition((TPanel *)this);
  this->X_start_line_pos = lVar4 + 0x1b;
  lVar4 = TPanel::yPosition((TPanel *)this);
  this->X_line_pos = this->X_start_line_pos;
  iVar5 = lVar4 + 0xf + this->axis_font_hgt * 2;
  this->Y_start_line_pos = iVar5;
  this->Y_line_pos = iVar5;
  this->X_line_max_width = this->X_axis_length + -2;
  this->Y_line_max_length = this->Y_axis_length + -3;
  if (this->num_entries_page < 0xc) {
    this->pop_reading_rate = 1;
    return;
  }
  lVar4 = __ftol();
  this->pop_reading_rate = lVar4;
  return;
}

// --------------------------------------------------

// Function: add_pop_total_special_event
// Address: 0051f4e0
void __thiscall
Time_Line_Panel::add_pop_total_special_event
          (Time_Line_Panel *this,long param_1,long param_2,long param_3,int param_4)
{
  Special_Events *pSVar1;
  
  pSVar1 = (Special_Events *)calloc(1,0xb0);
  pSVar1->time_slice = param_1;
  pSVar1->X_line_pos = param_3;
  pSVar1->Y_line_pos = 0;
  pSVar1->intermediate_y_line_segment = 0;
  pSVar1->player_id = '\0';
  pSVar1->player_color = '\0';
  pSVar1->interger_value_1 = 0;
  pSVar1->interger_value_2 = 0;
  pSVar1->start_x = 0;
  pSVar1->start_y = 0;
  pSVar1->start_txt_x1 = 0;
  pSVar1->start_txt_y1 = 0;
  pSVar1->start_txt_x2 = 0;
  pSVar1->start_txt_y2 = 0;
  pSVar1->text_length1 = 0;
  pSVar1->text1[0] = '\0';
  pSVar1->text_length2 = 0;
  pSVar1->text2[0] = '\0';
  pSVar1->event = '\x03';
  pSVar1->pop_total = param_2;
  pSVar1->icon_flag = param_4;
  pSVar1->next = this->time_slice_events;
  this->time_slice_events = pSVar1;
  return;
}

// --------------------------------------------------

// Function: record_special_event
// Address: 0051f560
void __thiscall
Time_Line_Panel::record_special_event
          (Time_Line_Panel *this,uchar param_1,TRIBE_History_Info *param_2,uchar param_3,
          long param_4,long param_5,long param_6,long param_7)
{
  long lVar1;
  uchar uVar2;
  Special_Events *pSVar3;
  
  lVar1 = param_4;
  uVar2 = TRIBE_History_Info::get_history_event(param_2,param_4,(uchar *)&param_4);
  if (uVar2 != '\0') {
    pSVar3 = (Special_Events *)calloc(1,0xb0);
    pSVar3->X_line_pos = param_5;
    pSVar3->Y_line_pos = param_6;
    pSVar3->intermediate_y_line_segment = param_7;
    pSVar3->time_slice = lVar1;
    pSVar3->player_id = param_1;
    pSVar3->player_color = param_3;
    pSVar3->event = (uchar)param_4;
    pSVar3->pop_total = 0;
    pSVar3->interger_value_1 = 0;
    pSVar3->interger_value_2 = 0;
    pSVar3->start_x = 0;
    pSVar3->start_y = 0;
    pSVar3->start_txt_x1 = 0;
    pSVar3->start_txt_y1 = 0;
    pSVar3->start_txt_x2 = 0;
    pSVar3->start_txt_y2 = 0;
    pSVar3->text_length1 = 0;
    pSVar3->text1[0] = '\0';
    pSVar3->text_length2 = 0;
    pSVar3->text2[0] = '\0';
    pSVar3->icon_flag = 0;
    pSVar3->next = this->time_slice_events;
    this->time_slice_events = pSVar3;
  }
  return;
}

// --------------------------------------------------

// Function: calculate_icon_location
// Address: 0051f600
int __thiscall
Time_Line_Panel::calculate_icon_location
          (Time_Line_Panel *this,Special_Events *param_1,short param_2,uchar param_3)
{
  char cVar1;
  Special_Events *pSVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined2 in_stack_0000000a;
  short height;
  int ret_val;
  long temp_start_txt_x1;
  long temp_start_y;
  long temp_start_x;
  int local_4;
  
  pSVar2 = param_1;
  iVar8 = 0;
  param_1->icon_flag = 0;
  local_4 = 0;
  temp_start_x = 0;
  temp_start_y = 0;
  temp_start_txt_x1 = (long)(this->special_events_pic != (TShape *)0x0);
  lVar3 = TShape::shape_count(this->special_events_pic);
  if (lVar3 == 0) {
    temp_start_txt_x1 = 0;
  }
  iVar6 = (int)param_2;
  lVar3 = TShape::shape_count(this->special_events_pic);
  if (lVar3 < iVar6) {
    temp_start_txt_x1 = 0;
  }
  if (temp_start_txt_x1 != 0) {
    TShape::shape_bounds
              (this->special_events_pic,iVar6,(short *)&param_1,(short *)((int)&ret_val + 2));
    if (0 < (short)param_1) {
      this->special_events_pic_wid = (short)param_1;
    }
    if (0 < ret_val._2_2_) {
      this->special_events_pic_hgt = ret_val._2_2_;
    }
    if (temp_start_txt_x1 != 0) {
      if (pSVar2->intermediate_y_line_segment < (int)this->special_events_pic_hgt) {
        temp_start_txt_x1 = 0;
      }
      iVar6 = (int)this->special_events_pic_wid / 2;
      if (this->X_line_max_width + this->X_start_line_pos < pSVar2->X_line_pos + iVar6) {
        temp_start_txt_x1 = 0;
      }
      iVar6 = pSVar2->X_line_pos - iVar6;
      if (iVar6 < this->X_start_line_pos) {
        temp_start_txt_x1 = 0;
      }
      if (temp_start_txt_x1 != 0) {
        temp_start_x = (pSVar2->intermediate_y_line_segment / 2 + pSVar2->Y_line_pos * 2) -
                       (int)this->special_events_pic_hgt / 2;
        local_4 = iVar6;
      }
    }
  }
  switch(pSVar2->event) {
  case '\0':
    uVar5 = 0xffffffff;
    pcVar9 = pSVar2->text1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    pSVar2->text_length1 = ~uVar5 - 1;
    iVar8 = this->body_font_wid * (~uVar5 - 1);
    if (iVar8 + 2 + pSVar2->X_line_pos < this->X_line_max_width + this->X_start_line_pos) {
      temp_start_y = pSVar2->X_line_pos + 2;
    }
    else {
      temp_start_y = (this->X_line_max_width - iVar8) + -3 + this->X_start_line_pos;
    }
    iVar6 = this->body_font_hgt;
    iVar8 = (pSVar2->Y_line_pos + pSVar2->intermediate_y_line_segment) - iVar6;
    break;
  case '\x01':
    uVar5 = 0xffffffff;
    pcVar9 = pSVar2->text1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    pSVar2->text_length1 = ~uVar5 - 1;
    iVar8 = this->body_font_wid * (~uVar5 - 1);
    if (iVar8 + 2 + pSVar2->X_line_pos < this->X_line_max_width + this->X_start_line_pos) {
      temp_start_y = pSVar2->X_line_pos + 2;
    }
    else {
      temp_start_y = (this->X_line_max_width - iVar8) + -8 + this->X_start_line_pos;
    }
    iVar4 = pSVar2->Y_line_pos;
    iVar8 = this->Y_start_line_pos + this->Y_line_max_length;
    if (iVar8 <= this->body_font_hgt + 2 + iVar4) {
      iVar8 = (iVar8 - this->body_font_hgt) + -2;
      goto switchD_0051f73e_caseD_3;
    }
    goto LAB_0051f87c;
  case '\x02':
    uVar5 = 0xffffffff;
    pcVar9 = pSVar2->text1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    pSVar2->text_length1 = ~uVar5 - 1;
    iVar8 = this->body_font_wid * (~uVar5 - 1);
    if (iVar8 + 2 + pSVar2->X_line_pos < this->X_line_max_width + this->X_start_line_pos) {
      temp_start_y = pSVar2->X_line_pos + 2;
    }
    else {
      temp_start_y = (this->X_line_max_width - iVar8) + -3 + this->X_start_line_pos;
    }
    iVar6 = this->body_font_hgt;
    iVar8 = (pSVar2->Y_line_pos + pSVar2->intermediate_y_line_segment) - iVar6;
    break;
  default:
    goto switchD_0051f73e_caseD_3;
  case '\x06':
    iVar8 = this->X_start_line_pos + this->X_line_max_width;
    uVar5 = 0xffffffff;
    pcVar9 = pSVar2->text1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar8 < (int)((~uVar5 - 1) * this->body_font_wid + pSVar2->X_line_pos)) {
      pSVar2->text_length1 = (iVar8 - pSVar2->X_line_pos) / this->body_font_wid;
    }
    else {
      uVar5 = 0xffffffff;
      pcVar9 = pSVar2->text1;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      pSVar2->text_length1 = ~uVar5 - 1;
    }
    if (2 < pSVar2->text_length1) {
      pSVar2->text_length1 = 2;
    }
    iVar8 = (int)this->special_events_pic_hgt;
    iVar6 = this->body_font_hgt;
    iVar4 = this->Y_line_max_length;
    iVar7 = this->Y_start_line_pos;
    if (iVar4 + iVar7 < temp_start_x + iVar6 + 1 + iVar8) {
LAB_0051f9bc:
      temp_start_x = ((iVar4 - iVar6) - iVar8) + -1 + iVar7;
    }
    goto LAB_0051f9c8;
  case '\b':
    iVar8 = this->X_start_line_pos + this->X_line_max_width;
    uVar5 = 0xffffffff;
    pcVar9 = pSVar2->text1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar8 < (int)((~uVar5 - 1) * this->body_font_wid + pSVar2->X_line_pos)) {
      pSVar2->text_length1 = (iVar8 - pSVar2->X_line_pos) / this->body_font_wid;
    }
    else {
      uVar5 = 0xffffffff;
      pcVar9 = pSVar2->text1;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      pSVar2->text_length1 = ~uVar5 - 1;
    }
    if (5 < pSVar2->text_length1) {
      pSVar2->text_length1 = 5;
    }
    iVar8 = (int)this->special_events_pic_hgt;
    iVar6 = this->body_font_hgt;
    iVar4 = this->Y_line_max_length;
    iVar7 = this->Y_start_line_pos;
    if (iVar4 + iVar7 < temp_start_x + iVar6 + 1 + iVar8) goto LAB_0051f9bc;
LAB_0051f9c8:
    temp_start_y = local_4;
    iVar8 = temp_start_x + 1 + iVar8;
    goto switchD_0051f73e_caseD_3;
  }
  iVar8 = iVar8 + -2;
  iVar4 = this->Y_start_line_pos;
  if (iVar4 < iVar8) {
    iVar4 = this->Y_line_max_length + iVar4;
    if (iVar4 <= iVar8) {
      iVar8 = (iVar4 - iVar6) + -3;
    }
  }
  else {
LAB_0051f87c:
    iVar8 = iVar4 + 2;
  }
switchD_0051f73e_caseD_3:
  pSVar2->start_x = local_4;
  pSVar2->start_txt_x1 = temp_start_y;
  pSVar2->start_y = temp_start_x;
  pSVar2->start_txt_y1 = iVar8;
  if (temp_start_txt_x1 != 0) {
    pSVar2->icon_flag = 1;
  }
  return temp_start_txt_x1;
}

// --------------------------------------------------

// Function: draw
// Address: 0051fa30
void __thiscall Time_Line_Panel::draw(Time_Line_Panel *this)
{
  int iVar1;
  
  TPanel::draw((TPanel *)this);
  this->_padding_ = 0;
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    draw_background(this);
    draw_border(this);
    draw_axis(this);
    draw_timeline(this);
    draw_special_events(this);
    draw_civilization_names(this);
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: draw_axis
// Address: 0051fa90
// [HELPER] s_tpnl_tml__draw_axis: "tpnl_tml::draw_axis"
void __thiscall Time_Line_Panel::draw_axis(Time_Line_Panel *this)
{
  int iVar1;
  char cVar2;
  uchar *puVar3;
  long lVar4;
  void *pvVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  uchar uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uchar white_color;
  char temp_str [100];
  
  cVar2 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)this->_padding_ + 8),0xffffff);
  temp_str[0] = cVar2;
  puVar3 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_axis,1);
  uVar15 = temp_str._0_4_;
  if (puVar3 != (uchar *)0x0) {
    uVar14 = temp_str._0_4_;
    lVar4 = TPanel::yPosition((TPanel *)this);
    uVar13 = (uchar)uVar14;
    iVar6 = lVar4 + this->axis_font_hgt * 2 + 0xd + this->Y_axis_length;
    lVar4 = TPanel::xPosition((TPanel *)this);
    iVar12 = lVar4 + 0x18 + this->X_axis_length;
    lVar4 = TPanel::yPosition((TPanel *)this);
    iVar10 = lVar4 + 0xc + this->axis_font_hgt * 2 + this->Y_axis_length;
    lVar4 = TPanel::xPosition((TPanel *)this);
    TDrawArea::FillRect((TDrawArea *)this->_padding_,lVar4 + 0x19,iVar10,iVar12,iVar6,uVar13);
    uVar14 = uVar15;
    lVar4 = TPanel::yPosition((TPanel *)this);
    uVar13 = (uchar)uVar14;
    iVar6 = lVar4 + 0xe + this->axis_font_hgt * 2;
    lVar4 = TPanel::xPosition((TPanel *)this);
    iVar12 = lVar4 + 0x18 + this->X_axis_length;
    lVar4 = TPanel::yPosition((TPanel *)this);
    iVar10 = lVar4 + 0xd + this->axis_font_hgt * 2;
    lVar4 = TPanel::xPosition((TPanel *)this);
    TDrawArea::FillRect((TDrawArea *)this->_padding_,lVar4 + 0x19,iVar10,iVar12,iVar6,uVar13);
    uVar14 = uVar15;
    lVar4 = TPanel::yPosition((TPanel *)this);
    uVar13 = (uchar)uVar14;
    iVar6 = lVar4 + this->axis_font_hgt * 2 + 0xd + this->Y_axis_length;
    lVar4 = TPanel::xPosition((TPanel *)this);
    iVar10 = lVar4 + 0x1a;
    lVar4 = TPanel::yPosition((TPanel *)this);
    iVar12 = lVar4 + 0xd + this->axis_font_hgt * 2;
    lVar4 = TPanel::xPosition((TPanel *)this);
    TDrawArea::FillRect((TDrawArea *)this->_padding_,lVar4 + 0x19,iVar12,iVar10,iVar6,uVar13);
    lVar4 = TPanel::yPosition((TPanel *)this);
    uVar13 = (uchar)uVar15;
    iVar6 = lVar4 + this->axis_font_hgt * 2 + 0xd + this->Y_axis_length;
    lVar4 = TPanel::xPosition((TPanel *)this);
    iVar12 = lVar4 + 0x18 + this->X_axis_length;
    lVar4 = TPanel::yPosition((TPanel *)this);
    iVar10 = lVar4 + 0xd + this->axis_font_hgt * 2;
    lVar4 = TPanel::xPosition((TPanel *)this);
    TDrawArea::FillRect((TDrawArea *)this->_padding_,lVar4 + 0x17 + this->X_axis_length,iVar10,
                        iVar12,iVar6,uVar13);
  }
  TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_axis);
  pvVar5 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_tml__draw_axis);
  if (pvVar5 != (void *)0x0) {
    SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
    temp_str._0_4_ = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->axis_font);
    iVar6 = TPanel::get_string((TPanel *)this,0x2c57,temp_str + 4,100);
    if (iVar6 != 0) {
      lVar4 = TPanel::xPosition((TPanel *)this);
      lVar7 = TPanel::yPosition((TPanel *)this);
      SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
      uVar8 = 0xffffffff;
      pcVar11 = temp_str + 4;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar2 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar2 != '\0');
      TextOutA(*(undefined4 *)(this->_padding_ + 0x38),lVar4 + 8,lVar7 + 5,temp_str + 4,~uVar8 - 1);
    }
    iVar6 = TPanel::get_string((TPanel *)this,0x2c56,temp_str + 4,100);
    if (iVar6 != 0) {
      uVar8 = 0xffffffff;
      iVar6 = this->X_start_line_pos;
      pcVar11 = temp_str + 4;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar2 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar2 != '\0');
      iVar12 = this->X_axis_length;
      iVar10 = this->axis_font_wid;
      lVar4 = TPanel::height((TPanel *)this);
      lVar7 = TPanel::yPosition((TPanel *)this);
      iVar1 = this->axis_font_hgt;
      SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
      uVar9 = 0xffffffff;
      pcVar11 = temp_str + 4;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar2 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar2 != '\0');
      TextOutA(*(undefined4 *)(this->_padding_ + 0x38),
               (iVar6 - ((~uVar8 - 1) * iVar10 >> 1)) + iVar12 / 2,lVar4 + lVar7 + (-5 - iVar1),
               temp_str + 4,~uVar9 - 1);
    }
    SelectObject(*(undefined4 *)(this->_padding_ + 0x38),temp_str._0_4_);
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_tml__draw_axis);
  }
  return;
}

// --------------------------------------------------

// Function: draw_special_events
// Address: 0051fd90
// [HELPER] s_tpnl_tml__draw_special_events: "tpnl_tml::draw_special_events"
void __thiscall Time_Line_Panel::draw_special_events(Time_Line_Panel *this)
{
  char cVar1;
  Special_Events *pSVar2;
  uchar *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 uVar12;
  short sVar13;
  char *pcVar14;
  uchar uVar15;
  void *old_font;
  
  if (this->timeline_flag != '\0') {
    GetNearestPaletteIndex(*(undefined4 *)(*(int *)this->_padding_ + 8),0xffffff);
    GetNearestPaletteIndex(*(undefined4 *)(*(int *)this->_padding_ + 8),0);
    puVar3 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_special_events,1);
    if (puVar3 != (uchar *)0x0) {
      for (pSVar2 = this->time_slice_events; pSVar2 != (Special_Events *)0x0; pSVar2 = pSVar2->next)
{
        switch(pSVar2->event) {
        case '\0':
          uVar15 = '\0';
          goto LAB_0051fe22;
        case '\x01':
          uVar15 = '\x01';
          goto LAB_0051fe22;
        case '\x02':
          uVar15 = '\x02';
          goto LAB_0051fe22;
        case '\x03':
          uVar15 = '\x03';
LAB_0051fe22:
          sVar13 = -1;
          break;
        case '\x04':
          uVar15 = '\x04';
          sVar13 = 0;
          break;
        case '\x05':
          uVar15 = '\x05';
          sVar13 = 1;
          break;
        case '\x06':
          uVar15 = '\x06';
          sVar13 = 2;
          break;
        case '\a':
          uVar15 = '\a';
          sVar13 = 3;
          break;
        case '\b':
          uVar15 = '\b';
          sVar13 = 4;
          break;
        default:
          goto switchD_0051fdef_default;
        }
        draw_icon(this,pSVar2,sVar13,uVar15);
switchD_0051fdef_default:
      }
    }
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_special_events);
    pvVar4 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_tml__draw_special_events);
    if (pvVar4 != (void *)0x0) {
      SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
      uVar5 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->body_font);
      for (pSVar2 = this->time_slice_events; pSVar2 != (Special_Events *)0x0; pSVar2 = pSVar2->next)
{
        switch(pSVar2->event) {
        case '\0':
          SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0);
          iVar9 = pSVar2->text_length1;
          lVar6 = pSVar2->start_txt_y1;
          pcVar14 = pSVar2->text1;
          lVar7 = pSVar2->start_txt_x1;
          uVar12 = *(undefined4 *)(this->_padding_ + 0x38);
          break;
        case '\x01':
switchD_0051fe9b_caseD_1:
          SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0);
          iVar9 = pSVar2->text_length1;
          lVar6 = pSVar2->start_txt_y1;
          pcVar14 = pSVar2->text1;
          lVar7 = pSVar2->start_txt_x1;
          uVar12 = *(undefined4 *)(this->_padding_ + 0x38);
          break;
        case '\x02':
switchD_0051fe9b_caseD_2:
          SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0);
          iVar9 = pSVar2->text_length1;
          lVar6 = pSVar2->start_txt_y1;
          pcVar14 = pSVar2->text1;
          lVar7 = pSVar2->start_txt_x1;
          uVar12 = *(undefined4 *)(this->_padding_ + 0x38);
          break;
        case '\x03':
          iVar10 = (-(uint)(pSVar2->time_slice != 0) & 0xfffffffc) + 2;
          SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
          pcVar14 = pSVar2->text1;
          uVar8 = 0xffffffff;
          pcVar11 = pcVar14;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          iVar9 = ~uVar8 - 1;
          lVar6 = TPanel::yPosition((TPanel *)this);
          uVar8 = 0xffffffff;
          pcVar11 = pSVar2->text1;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          TextOutA(*(undefined4 *)(this->_padding_ + 0x38),
                   (iVar10 - (~uVar8 - 1 >> 1) * this->axis_font_wid) + pSVar2->X_line_pos,
                   lVar6 + 8 + this->axis_font_hgt,pcVar14,iVar9);
          pcVar14 = pSVar2->text2;
          uVar8 = 0xffffffff;
          pcVar11 = pcVar14;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          iVar9 = ~uVar8 - 1;
          lVar6 = TPanel::yPosition((TPanel *)this);
          lVar7 = TPanel::height((TPanel *)this);
          lVar6 = lVar6 + lVar7 + this->axis_font_hgt * -2 + -7;
          uVar8 = 0xffffffff;
          pcVar11 = pSVar2->text2;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          uVar12 = *(undefined4 *)(this->_padding_ + 0x38);
          lVar7 = (iVar10 - (~uVar8 - 1 >> 1) * this->axis_font_wid) + pSVar2->X_line_pos;
          break;
        default:
          goto switchD_0051fe9b_caseD_4;
        case '\x06':
          if (pSVar2->icon_flag != 0) goto switchD_0051fe9b_caseD_1;
          goto switchD_0051fe9b_caseD_4;
        case '\b':
          if (pSVar2->icon_flag != 0) goto switchD_0051fe9b_caseD_2;
          goto switchD_0051fe9b_caseD_4;
        }
        TextOutA(uVar12,lVar7,lVar6,pcVar14,iVar9);
switchD_0051fe9b_caseD_4:
      }
      SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar5);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_tml__draw_special_events);
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_background
// Address: 00520080
// [HELPER] s_tpnl_tml__draw_background2: "tpnl_tml::draw_background2"
// [HELPER] s_tpnl_tml__draw_background: "tpnl_tml::draw_background"
void __thiscall Time_Line_Panel::draw_background(Time_Line_Panel *this)
{
  int *piVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short pic_cols;
  short pic_rows;
  int local_4;
  
  if (this->background_pic == (TShape *)0x0) {
    if (this->fill_back == 0) {
      piVar1 = (int *)this->_padding_;
      if (piVar1 != (int *)0x0) {
        if ((1 < this->bevel_type) && (this->bevel_type < 8)) {
          (**(code **)(*piVar1 + 0x3c))(&this->_padding_);
          return;
        }
        if (piVar1[0x21] == 0) {
          (**(code **)(*piVar1 + 0x34))(&this->_padding_);
        }
      }
    }
    else {
      puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_background2,1);
      if (puVar2 != (uchar *)0x0) {
        TDrawArea::FillRect((TDrawArea *)this->_padding_,this->_padding_,this->_padding_,
                            this->_padding_ + -1 + this->_padding_,
                            this->_padding_ + -1 + this->_padding_,this->back_color);
        TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_background2);
        return;
      }
    }
  }
  else {
    puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_background,1);
    if (puVar2 != (uchar *)0x0) {
      iVar3 = (int)this->background_pic_wid;
      iVar4 = this->_padding_;
      if (iVar3 < iVar4) {
        pic_rows = (short)(iVar4 / iVar3);
        if (pic_rows * iVar3 < iVar4) {
          pic_rows = pic_rows + 1;
        }
      }
      else {
        pic_rows = 1;
      }
      iVar3 = (int)this->background_pic_hgt;
      iVar4 = this->_padding_;
      if ((iVar4 <= iVar3) &&
         (local_4._0_2_ = (short)(iVar4 / iVar3), (short)local_4 * iVar3 < iVar4)) {
        local_4._0_2_ = (short)local_4 + 1;
      }
      if (0 < (short)local_4) {
        local_4 = (int)(short)local_4;
        iVar4 = 0;
        do {
          if (0 < pic_rows) {
            iVar5 = 0;
            iVar3 = (int)pic_rows;
            do {
              TShape::shape_draw(this->background_pic,(TDrawArea *)this->_padding_,
                                 iVar5 * this->background_pic_wid + this->_padding_,
                                 iVar4 * this->background_pic_hgt + this->_padding_,0,'\0',
                                 (uchar *)0x0);
              iVar5 = iVar5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          iVar4 = iVar4 + 1;
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
      TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_background);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_civilization_names
// Address: 00520220
// [HELPER] s__s____s: "%s - %s"
// [HELPER] s_tpnl_tml__draw_civilization_name: "tpnl_tml::draw_civilization_names"
void __thiscall Time_Line_Panel::draw_civilization_names(Time_Line_Panel *this)
{
  char cVar1;
  byte bVar2;
  void *pvVar3;
  RGE_Game_World *pRVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  float pop_total;
  float fStack_144;
  long y_line_segment_length;
  long Y_line_pos;
  long X_line_pos;
  void *old_font;
  char temp_str [100];
  char civ_str [100];
  char name_str [100];
  
  if (this->timeline_flag != '\0') {
    SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0);
    pvVar3 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_tml__draw_civilization_name);
    if (pvVar3 != (void *)0x0) {
      SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
      temp_str._0_4_ = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->body_font);
      iVar8 = 0;
      fStack_144 = 0.0;
      pRVar4 = rge_base_game->world;
      if (pRVar4->player_num != 1 && -1 < pRVar4->player_num + -1) {
        iVar10 = 4;
        do {
          bVar2 = TRIBE_History_Info::get_history_entry
                            (*(TRIBE_History_Info **)
                              (*(int *)((int)pRVar4->players + iVar10) + 0x83c),'\0',0);
          iVar8 = iVar8 + 1;
          pRVar4 = rge_base_game->world;
          iVar10 = iVar10 + 4;
          fStack_144 = (float)bVar2 + fStack_144;
        } while (iVar8 < pRVar4->player_num + -1);
      }
      if (fStack_144 != _DAT_005770b8) {
        iVar8 = this->X_start_line_pos;
        X_line_pos = this->Y_start_line_pos;
        pRVar4 = rge_base_game->world;
        if (pRVar4->player_num != 1 && -1 < pRVar4->player_num + -1) {
          y_line_segment_length = 0;
          iVar10 = 4;
          do {
            TRIBE_History_Info::get_history_entry
                      (*(TRIBE_History_Info **)(*(int *)((int)pRVar4->players + iVar10) + 0x83c),
                       '\0',0);
            iVar5 = __ftol();
            (**(code **)(rge_base_game->_padding_ + 0x28))
                      (0x69,*(undefined1 *)
                             (*(int *)((int)rge_base_game->world->players + iVar10) + 0x105),0,
                       civ_str + 4,100);
            pcVar12 = name_str;
            uVar6 = 0xffffffff;
            pcVar9 = *(char **)(*(int *)((int)rge_base_game->world->players + iVar10) + 0x44);
            do {
              pcVar11 = pcVar9;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar11 = pcVar9 + 1;
              cVar1 = *pcVar9;
              pcVar9 = pcVar11;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            pcVar9 = pcVar11 + -uVar6;
            for (uVar7 = uVar6 >> 2; pcVar12 = pcVar12 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined4 *)pcVar12 = *(undefined4 *)pcVar9;
              pcVar9 = pcVar9 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar12 = *pcVar9;
              pcVar9 = pcVar9 + 1;
              pcVar12 = pcVar12 + 1;
            }
            sprintf(temp_str + 4,s__s____s,name_str + 4,civ_str + 4);
            uVar6 = 0xffffffff;
            pcVar12 = temp_str + 4;
            do {
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              cVar1 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar1 != '\0');
            TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar8 + 3,
                     (iVar5 / 2 - this->body_font_hgt / 2) + X_line_pos,temp_str + 4,~uVar6 - 1);
            X_line_pos = X_line_pos + iVar5;
            iVar10 = iVar10 + 4;
            pRVar4 = rge_base_game->world;
            y_line_segment_length = y_line_segment_length + 1;
          } while (y_line_segment_length < pRVar4->player_num + -1);
        }
        SelectObject(*(undefined4 *)(this->_padding_ + 0x38),temp_str._0_4_);
        TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_tml__draw_civilization_name);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_timeline
// Address: 005204a0
// [HELPER] s_tpnl_tml__draw_timeline: "tpnl_tml::draw_timeline"
void __thiscall Time_Line_Panel::draw_timeline(Time_Line_Panel *this)
{
  byte bVar1;
  uchar uVar2;
  undefined1 uVar3;
  uchar *puVar4;
  long lVar5;
  RGE_Game_World *pRVar6;
  undefined4 uVar7;
  float fVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  float10 extraout_ST0;
  uchar event;
  float pop_total;
  float temp_pop_num;
  long time_slice;
  float next_pop_total;
  float float_remainder;
  long cntr_droped_slice_rate;
  long pop_sample_cntr;
  int local_38;
  int local_34;
  long error_correction_drop_time_slice_rate;
  long time_slice_cntr;
  int local_28;
  long Y_line_total;
  long cntr2;
  long intermediate_x_pos;
  int special_event_flag;
  long error_correction_time_slice_thickness;
  int local_10;
  long y_line_segment_length;
  uchar temp_color;
  undefined1 uStack_4;
  undefined3 uStack_3;
  
  if (this->timeline_flag != '\0') {
    puVar4 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_timeline,1);
    if (puVar4 != (uchar *)0x0) {
      this->X_line_pos = this->X_start_line_pos;
      local_38 = 0;
      local_10 = 0;
      time_slice_cntr = 0;
      pop_sample_cntr = 0;
      local_28 = 0;
      next_pop_total = 0.0;
      if (0 < this->num_history_entries) {
        error_correction_drop_time_slice_rate = 1;
        do {
          fVar8 = next_pop_total;
          if (this->num_entries_page <= local_28) break;
          iVar9 = 0;
          temp_pop_num = 0.0;
          error_correction_time_slice_thickness = 0;
          pRVar6 = rge_base_game->world;
          if (pRVar6->player_num != 1 && -1 < pRVar6->player_num + -1) {
            iVar11 = 4;
            do {
              bVar1 = TRIBE_History_Info::get_history_entry
                                (*(TRIBE_History_Info **)
                                  (*(int *)((int)pRVar6->players + iVar11) + 0x83c),'\0',(long)fVar8
                                );
              _temp_color = (uint)bVar1;
              time_slice = (long)(float)_temp_color;
              uVar2 = TRIBE_History_Info::get_history_event
                                (*(TRIBE_History_Info **)
                                  (*(int *)((int)rge_base_game->world->players + iVar11) + 0x83c),
                                 (long)fVar8,(uchar *)((int)&pop_total + 3));
              if (uVar2 != '\0') {
                error_correction_time_slice_thickness = 1;
              }
              iVar11 = iVar11 + 4;
              pRVar6 = rge_base_game->world;
              iVar9 = iVar9 + 1;
              temp_pop_num = (float)time_slice + temp_pop_num;
            } while (iVar9 < pRVar6->player_num + -1);
          }
          if (temp_pop_num == _DAT_005770b8) {
            return;
          }
          iVar9 = __ftol();
          iVar11 = __ftol();
          iVar11 = (iVar11 + (1 - error_correction_drop_time_slice_rate) * iVar9) - time_slice_cntr;
          if ((((this->drop_flag == '\0') || (error_correction_time_slice_thickness != 0)) ||
              (pop_sample_cntr < iVar11)) ||
             (this->total_slices_to_drop <= error_correction_drop_time_slice_rate + -1)) {
            pop_sample_cntr = pop_sample_cntr + 1;
            local_28 = local_28 + 1;
            if (fVar8 == (float)(this->num_entries_page + -1)) {
              float_remainder = temp_pop_num;
            }
            else {
              iVar9 = 0;
              float_remainder = 0.0;
              pRVar6 = rge_base_game->world;
              if (pRVar6->player_num != 1 && -1 < pRVar6->player_num + -1) {
                iVar11 = (int)fVar8 + 1;
                iVar12 = 4;
                do {
                  bVar1 = TRIBE_History_Info::get_history_entry
                                    (*(TRIBE_History_Info **)
                                      (*(int *)((int)pRVar6->players + iVar12) + 0x83c),'\0',iVar11)
                  ;
                  _temp_color = (uint)bVar1;
                  iVar9 = iVar9 + 1;
                  pRVar6 = rge_base_game->world;
                  iVar12 = iVar12 + 4;
                  float_remainder = (float)_temp_color + float_remainder;
                  fVar8 = next_pop_total;
                } while (iVar9 < pRVar6->player_num + -1);
              }
              if (float_remainder == _DAT_005770b8) {
                return;
              }
            }
            if ((local_38 == this->pop_reading_rate + -1) || (fVar8 == 0.0)) {
              lVar10 = this->X_line_pos;
              iVar9 = 1;
              lVar5 = __ftol();
              add_pop_total_special_event(this,(long)fVar8,lVar5,lVar10,iVar9);
              local_38 = 0;
            }
            else {
              local_38 = local_38 + 1;
            }
            y_line_segment_length = (int)fVar8 + 1;
            iVar9 = __ftol();
            error_correction_time_slice_thickness = __ftol();
            iVar11 = error_correction_time_slice_thickness * ((int)fVar8 + 1);
            if (iVar11 < iVar9 - local_10) {
              error_correction_time_slice_thickness =
                   ((iVar9 - local_10) - iVar11) + error_correction_time_slice_thickness;
              local_10 = local_10 + 1;
            }
            intermediate_x_pos = 0;
            special_event_flag = 0;
            if (0 < error_correction_time_slice_thickness) {
              do {
                this->Y_line_pos = this->Y_start_line_pos;
                cntr2 = 0;
                cntr_droped_slice_rate = 0;
                pRVar6 = rge_base_game->world;
                if (pRVar6->player_num != 1 && -1 < pRVar6->player_num + -1) {
                  local_34 = 0;
                  iVar9 = 4;
                  do {
                    switch(*(undefined2 *)
                            (*(int *)(*(int *)((int)pRVar6->players + iVar9) + 0x108) + 0x26)) {
                    case 0:
                      uVar7 = 0xc40000;
                      break;
                    case 1:
                      uVar7 = 200;
                      break;
                    case 2:
                      uVar7 = 0xeaea;
                      break;
                    case 3:
                      uVar7 = 0x215a8c;
                      break;
                    case 4:
                      uVar7 = 0x80ff;
                      break;
                    case 5:
                      uVar7 = 0x8000;
                      break;
                    case 6:
                      uVar7 = 0x808080;
                      break;
                    case 7:
                      uVar7 = 0x808040;
                      break;
                    default:
                      uVar7 = 0xffffff;
                    }
                    uVar3 = GetNearestPaletteIndex
                                      (*(undefined4 *)(*(int *)this->_padding_ + 8),uVar7);
                    _uStack_4 = CONCAT31(uStack_3,uVar3);
                    bVar1 = TRIBE_History_Info::get_history_entry
                                      (*(TRIBE_History_Info **)
                                        (*(int *)((int)rge_base_game->world->players + iVar9) +
                                        0x83c),'\0',(long)next_pop_total);
                    _temp_color = (uint)bVar1;
                    lVar10 = this->Y_line_max_length;
                    time_slice = (long)(float)_temp_color;
                    Y_line_total = lVar10;
                    _temp_color = __ftol();
                    if ((_DAT_005770b0 <= (float)time_slice) && ((int)_temp_color < 1)) {
                      _temp_color = 1;
                    }
                    uVar13 = _temp_color;
                    if (this->bar_thickness != 1.0) {
                      if (next_pop_total != (float)(this->num_entries_page + -1)) {
                        TRIBE_History_Info::get_history_entry
                                  (*(TRIBE_History_Info **)
                                    (*(int *)((int)rge_base_game->world->players + iVar9) + 0x83c),
                                   '\0',y_line_segment_length);
                      }
                      lVar10 = this->Y_line_max_length;
                      Y_line_total = lVar10;
                      iVar11 = __ftol();
                      Y_line_total = iVar11 - uVar13;
                      _temp_color = __ftol();
                      if ((_DAT_005770b0 <= (float)time_slice) && ((int)_temp_color < 1)) {
                        _temp_color = 1;
                      }
                      cntr_droped_slice_rate =
                           (long)(float)(((float10)(float)cntr_droped_slice_rate + extraout_ST0) -
                                        (float10)(int)_temp_color);
                      uVar13 = _temp_color;
                      if ((float)_DAT_005770c0 < (float)cntr_droped_slice_rate) {
                        cntr_droped_slice_rate =
                             (long)((float)cntr_droped_slice_rate - _DAT_005770b0);
                        uVar13 = _temp_color + 1;
                      }
                    }
                    if (local_34 == rge_base_game->world->player_num + -2) {
                      if (lVar10 < (int)(uVar13 + cntr2)) {
                        uVar13 = lVar10 - cntr2;
                      }
                      if ((int)(uVar13 + cntr2) < lVar10) {
                        uVar13 = lVar10 - cntr2;
                      }
                    }
                    uVar2 = (uchar)_uStack_4;
                    TDrawArea::DrawVertLine
                              ((TDrawArea *)this->_padding_,this->X_line_pos,this->Y_line_pos,uVar13
                               ,uVar2);
                    if (intermediate_x_pos == 0) {
                      record_special_event
                                (this,(char)local_34 + '\x01',
                                 *(TRIBE_History_Info **)
                                  (*(int *)((int)rge_base_game->world->players + iVar9) + 0x83c),
                                 uVar2,(long)next_pop_total,this->X_line_pos,this->Y_line_pos,uVar13
                                );
                    }
                    this->Y_line_pos = this->Y_line_pos + uVar13;
                    cntr2 = cntr2 + uVar13;
                    iVar9 = iVar9 + 4;
                    pRVar6 = rge_base_game->world;
                    local_34 = local_34 + 1;
                    fVar8 = next_pop_total;
                  } while (local_34 < pRVar6->player_num + -1);
                }
                intermediate_x_pos = intermediate_x_pos + 1;
                special_event_flag = special_event_flag + 1;
                this->X_line_pos = this->X_line_pos + 1;
              } while (intermediate_x_pos < error_correction_time_slice_thickness);
            }
          }
          else {
            error_correction_drop_time_slice_rate = error_correction_drop_time_slice_rate + 1;
            pop_sample_cntr = 0;
            if (iVar9 < iVar11) {
              time_slice_cntr = time_slice_cntr + 1;
            }
          }
          next_pop_total = (float)((int)fVar8 + 1);
        } while ((int)next_pop_total < this->num_history_entries);
      }
    }
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_tml__draw_timeline);
  }
  return;
}

// --------------------------------------------------

// Function: draw_icon
// Address: 00520ae0
// [HELPER] s__1ld__02ld: "%1ld:%02ld"
// [HELPER] s__ld: "%ld"
// [HELPER] s__ld__1d: "%ld/%1d"
// [HELPER] s__s: "%s"
void __thiscall
Time_Line_Panel::draw_icon
          (Time_Line_Panel *this,Special_Events *param_1,short param_2,uchar param_3)
{
  uchar uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uchar uVar8;
  uchar black_color;
  char temp_str [50];
  
  GetNearestPaletteIndex(*(undefined4 *)(*(int *)this->_padding_ + 8),0xffffff);
  cVar3 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)this->_padding_ + 8),0);
  temp_str[0] = cVar3;
  switch(param_1->event) {
  case '\0':
    iVar4 = TPanel::get_string((TPanel *)this,0x106a,temp_str + 4,0x32);
    if (iVar4 == 0) goto switchD_00520b22_caseD_4;
    goto LAB_00520b72;
  case '\x01':
    iVar4 = TPanel::get_string((TPanel *)this,0x106b,temp_str + 4,0x32);
    break;
  case '\x02':
    iVar4 = TPanel::get_string((TPanel *)this,0x106c,temp_str + 4,0x32);
    break;
  case '\x03':
    goto switchD_00520b22_caseD_3;
  case '\x04':
  case '\x05':
  case '\a':
    goto switchD_00520b22_caseD_4;
  default:
    goto switchD_00520b22_caseD_6;
  case '\b':
    sprintf(temp_str + 4,s__ld__1d,param_1->interger_value_1,param_1->interger_value_2);
    sprintf(param_1->text1,s__s,temp_str + 4);
    goto switchD_00520b22_caseD_3;
  }
  if (iVar4 == 0) {
switchD_00520b22_caseD_4:
    param_1->text1[0] = '\0';
  }
  else {
LAB_00520b72:
    sprintf(param_1->text1,s__s,temp_str + 4);
  }
switchD_00520b22_caseD_6:
  iVar4 = calculate_icon_location(this,param_1,param_2,param_3);
  uVar1 = param_1->event;
  uVar8 = (uchar)temp_str._0_4_;
  if (uVar1 == '\0') {
    TDrawArea::DrawVertLine
              ((TDrawArea *)this->_padding_,param_1->X_line_pos,param_1->Y_line_pos,
               param_1->intermediate_y_line_segment,uVar8);
  }
  else {
    if (uVar1 == '\x01') {
      TDrawArea::DrawVertLine
                ((TDrawArea *)this->_padding_,param_1->X_line_pos,param_1->Y_line_pos,
                 param_1->intermediate_y_line_segment,uVar8);
      return;
    }
    if (uVar1 == '\x02') {
      TDrawArea::DrawVertLine
                ((TDrawArea *)this->_padding_,param_1->X_line_pos,param_1->Y_line_pos,
                 param_1->intermediate_y_line_segment,uVar8);
      return;
    }
    if (iVar4 != 0) {
      TShape::shape_draw(this->special_events_pic,(TDrawArea *)this->_padding_,param_1->start_x,
                         param_1->start_y,(int)param_2,'\0',(uchar *)0x0);
      return;
    }
  }
  return;
switchD_00520b22_caseD_3:
  sprintf(param_1->text1,s__ld,param_1->pop_total);
  uVar5 = 0xffffffff;
  iVar4 = 0;
  pcVar7 = param_1->text1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  iVar2 = param_1->time_slice * 0xf;
  param_1->text_length1 = ~uVar5 - 1;
  iVar6 = 0;
  if ((0x3b < iVar2) && (iVar6 = iVar2 / 0x3c, 0x3b < iVar6)) {
    iVar4 = iVar6 / 0x3c;
    iVar6 = iVar6 % 0x3c;
  }
  sprintf(temp_str + 4,s__1ld__02ld,iVar4,iVar6);
  sprintf(param_1->text2,s__s,temp_str + 4);
  uVar5 = 0xffffffff;
  pcVar7 = param_1->text2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  param_1->text_length2 = ~uVar5 - 1;
  goto switchD_00520b22_caseD_6;
}

// --------------------------------------------------

// Function: draw_legend
// Address: 00520d50
void __thiscall Time_Line_Panel::draw_legend(Time_Line_Panel *this)
{
  long lVar1;
  
  if (this->special_events_pic != (TShape *)0x0) {
    lVar1 = TShape::shape_count(this->special_events_pic);
    if (lVar1 != 0) {
      TPanel::width((TPanel *)this);
    }
  }
  return;
}

// --------------------------------------------------

