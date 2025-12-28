// Class: RGE_View
// Size:  0x360
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
// [56] pick_through_fog
// [57] pick_weight
// [58] start_scroll_view
// [59] handle_scroll_view
// [60] end_scroll_view
// [61] do_paint
// [62] draw_multi_object_outline
//
// Member Layout:
// [0x0F4] TDrawArea * cur_render_area
// [0x0F8] int calc_draw_count
// [0x0FC] RGE_Game_World * world
// [0x100] RGE_Player * player
// [0x104] RGE_Map * map
// [0x108] short tile_wid
// [0x10A] short tile_hgt
// [0x10C] short tile_half_wid
// [0x10E] short tile_half_hgt
// [0x110] short elev_hgt
// [0x112] short render_rect_wid
// [0x114] short render_rect_hgt
// [0x116] short max_col_num
// [0x118] short max_row_num
// [0x11A] short center_scr_col
// [0x11C] short center_scr_row
// [0x11E] short center_scr_col_offset
// [0x120] short center_scr_row_offset
// [0x122] short center_map_col
// [0x124] short center_map_row
// [0x126] short start_scr_col
// [0x128] short start_scr_row
// [0x12A] short start_map_col
// [0x12C] short start_map_row
// [0x130] int map_scr_x_offset
// [0x134] int map_scr_y_offset
// [0x138] float last_view_x
// [0x13C] float last_view_y
// [0x140] uchar function_mode
// [0x141] uchar function_parm
// [0x142] uchar render_terrain_mode
// [0x144] long sel_col1
// [0x148] long sel_row1
// [0x14C] long sel_col2
// [0x150] long sel_row2
// [0x154] short save_paint_terrain
// [0x158] void * white_pen
// [0x15C] void * red_pen
// [0x160] void * hollow_brush
// [0x164] TShape * border_line_shape
// [0x168] uchar scroll_action
// [0x16C] long mouse_last_x
// [0x170] long mouse_last_y
// [0x174] RGE_Static_Object * movable_object
// [0x178] TSpan_List_Manager * Terrain_Clip_Mask
// [0x17C] TSpan_List_Manager * Terrain_Fog_Clip_Mask
// [0x180] TSpan_List_Manager * Master_Clip_Mask
// [0x184] Tile_FogEdge_Table * * Tile_Edge_Tables
// [0x188] Tile_BlackEdge_Table * * Black_Edge_Tables
// [0x18C] tagRECT OverlaidPanel (sz: 0x10)
// [0x19C] int OverlaidPanelActive
// [0x1A0] uchar[256] EdgeNumber (sz: 0x100)
// [0x2A0] int Limited_Render_Rect
// [0x2A4] int Use_Rect2
// [0x2A8] tagRECT Render_Rect1 (sz: 0x10)
// [0x2B8] tagRECT Render_Rect2 (sz: 0x10)
// [0x2C8] void * * Float_Scroll_Offsets
// [0x2CC] int Float_Scroll_Offsets_Sz
// [0x2D0] int Float_X_Delta
// [0x2D4] int Float_Y_Delta
// [0x2D8] int Queued_Blits
// [0x2DC] Blit_Queue_Entry * Blit_Queue
// [0x2E0] int Blit_Queue_Size
// [0x2E4] int Blt_Queue_Allocated
// [0x2E8] int Current_Blit
// [0x2EC] int Blit_Offset_X
// [0x2F0] int Blit_Offset_Y
// [0x2F4] long real_old_map_col
// [0x2F8] long real_old_map_row
// [0x2FC] RGE_SPick_Info *[5] pick_lists (sz: 0x14)
// [0x310] int[5] pick_list_size (sz: 0x14)
// [0x324] TDrawArea * save_area1
// [0x328] uchar * LastRenderBits
// [0x32C] void * * RenderOffsets
// [0x330] int LastRenderSize
// [0x334] DClipInfo_List * prior_objs
// [0x338] DClipInfo_List * futur_objs
// [0x33C] int UC_ObjectTouched
// [0x340] int UC_TouchedObj
// [0x344] ulong UC_StartTime
// [0x348] ulong UC_ElapsedTime
// [0x34C] TMessagePanel * message_panel
// [0x350] Ov_Sprite_Draw_Rec * extra_sprites
// [0x354] DisplaySelectedObjRec * DispSel_List
// [0x358] int DispSel_List_Size
// [0x35C] int DispSel_List_Max
// ----------------------------------------------------------------

// Function: ~RGE_View
// Address: 0049548e
void __thiscall RGE_View::~RGE_View(RGE_View *this)
{
  TShape *this_00;
  TSpan_List_Manager *pTVar1;
  DClipInfo_List *pDVar2;
  int iVar3;
  RGE_SPick_Info **ppRVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561b28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->border_line_shape;
  uStack_4 = 0;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    this->border_line_shape = (TShape *)0x0;
  }
  delete_surfaces(this);
  if (this->red_pen != (void *)0x0) {
    DeleteObject(this->red_pen);
    this->red_pen = (void *)0x0;
  }
  if (this->RenderOffsets != (void **)0x0) {
    free(this->RenderOffsets);
  }
  pTVar1 = this->Terrain_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Terrain_Fog_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Master_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  if (this->Tile_Edge_Tables != (Tile_FogEdge_Table **)0x0) {
    free(this->Tile_Edge_Tables);
  }
  if (this->Black_Edge_Tables != (Tile_BlackEdge_Table **)0x0) {
    free(this->Black_Edge_Tables);
  }
  if (this->Float_Scroll_Offsets != (void **)0x0) {
    free(this->Float_Scroll_Offsets);
  }
  if (this->Blit_Queue != (Blit_Queue_Entry *)0x0) {
    free(this->Blit_Queue);
  }
  pDVar2 = this->prior_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  pDVar2 = this->futur_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  ppRVar4 = this->pick_lists;
  iVar3 = 5;
  do {
    if (*ppRVar4 != (RGE_SPick_Info *)0x0) {
      free(*ppRVar4);
    }
    ppRVar4 = ppRVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_mode(MouseSystem,0);
    TMousePointer::set_game_enable(MouseSystem,0);
  }
  if (this->DispSel_List != (DisplaySelectedObjRec *)0x0) {
    free(this->DispSel_List);
  }
  reset_overlay_sprites(this);
  TPanel::~TPanel((TPanel *)this);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: RGE_View
// Address: 00533510
/* public: __thiscall RGE_View::RGE_View(void) */

RGE_View * __thiscall RGE_View::RGE_View(RGE_View *this)
{
  int *piVar1;
  DisplaySelectedObjRec *pDVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561b08;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->_padding_ = (int)&_vftable_;
  this->cur_render_area = (TDrawArea *)0x0;
  this->calc_draw_count = 0;
  this->world = (RGE_Game_World *)0x0;
  this->player = (RGE_Player *)0x0;
  this->map = (RGE_Map *)0x0;
  this->tile_wid = 0;
  this->tile_hgt = 0;
  this->tile_half_hgt = 0;
  this->tile_half_wid = 0;
  this->elev_hgt = 0;
  this->max_col_num = 0;
  this->max_row_num = 0;
  this->center_scr_col = 0;
  this->center_scr_row = 0;
  this->center_scr_col_offset = 0;
  this->center_scr_row_offset = 0;
  this->center_map_col = 0;
  this->center_map_row = 0;
  this->start_scr_col = 0;
  this->start_scr_row = 0;
  this->start_map_col = 0;
  this->start_map_row = 0;
  this->map_scr_x_offset = 0;
  this->map_scr_y_offset = 0;
  this->last_view_x = -9999.0;
  this->last_view_y = -9999.0;
  this->function_mode = '\0';
  this->render_terrain_mode = '\0';
  this->save_area1 = (TDrawArea *)0x0;
  this->save_paint_terrain = -1;
  this->white_pen = (void *)0x0;
  this->red_pen = (void *)0x0;
  this->hollow_brush = (void *)0x0;
  this->border_line_shape = (TShape *)0x0;
  this->scroll_action = '\0';
  local_4 = 0;
  this->mouse_last_x = -1;
  this->mouse_last_y = -1;
  this->movable_object = (RGE_Static_Object *)0x0;
  set_selection_area(this,-1,-1,-1,-1);
  this->Terrain_Clip_Mask = (TSpan_List_Manager *)0x0;
  this->Terrain_Fog_Clip_Mask = (TSpan_List_Manager *)0x0;
  this->Master_Clip_Mask = (TSpan_List_Manager *)0x0;
  this->LastRenderBits = (uchar *)0x0;
  this->RenderOffsets = (void **)0x0;
  this->LastRenderSize = 0;
  this->Tile_Edge_Tables = (Tile_FogEdge_Table **)0x0;
  this->Black_Edge_Tables = (Tile_BlackEdge_Table **)0x0;
  this->Float_X_Delta = 0;
  this->Float_Y_Delta = 0;
  this->Float_Scroll_Offsets = (void **)0x0;
  this->Float_Scroll_Offsets_Sz = 0;
  this->Queued_Blits = 0;
  this->Blit_Queue = (Blit_Queue_Entry *)0x0;
  this->Blit_Queue_Size = 0;
  this->Current_Blit = 0;
  this->Blit_Offset_X = 0;
  this->Blit_Offset_Y = 0;
  this->prior_objs = (DClipInfo_List *)0x0;
  this->futur_objs = (DClipInfo_List *)0x0;
  piVar1 = this->pick_list_size;
  iVar3 = 5;
  do {
    piVar1[-5] = 0;
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this->UC_ObjectTouched = 0;
  this->UC_TouchedObj = -0x80000000;
  this->UC_StartTime = 0;
  this->UC_ElapsedTime = 0;
  this->message_panel = (TMessagePanel *)0x0;
  this->extra_sprites = (Ov_Sprite_Draw_Rec *)0x0;
  this->DispSel_List_Size = 0;
  this->DispSel_List_Max = 8;
  pDVar2 = (DisplaySelectedObjRec *)calloc(8,0x14);
  this->DispSel_List = pDVar2;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00533740
/* public: virtual void * __thiscall RGE_View::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_View::_vector_deleting_destructor_(RGE_View *this,uint param_1)
{
  ~RGE_View(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_View
// Address: 00533760
/* public: virtual __thiscall RGE_View::~RGE_View(void) */

void __thiscall RGE_View::~RGE_View(RGE_View *this)
{
  TShape *this_00;
  TSpan_List_Manager *pTVar1;
  DClipInfo_List *pDVar2;
  int iVar3;
  RGE_SPick_Info **ppRVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561b28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->border_line_shape;
  local_4 = 0;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    this->border_line_shape = (TShape *)0x0;
  }
  delete_surfaces(this);
  if (this->red_pen != (void *)0x0) {
    DeleteObject(this->red_pen);
    this->red_pen = (void *)0x0;
  }
  if (this->RenderOffsets != (void **)0x0) {
    free(this->RenderOffsets);
  }
  pTVar1 = this->Terrain_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Terrain_Fog_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Master_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  if (this->Tile_Edge_Tables != (Tile_FogEdge_Table **)0x0) {
    free(this->Tile_Edge_Tables);
  }
  if (this->Black_Edge_Tables != (Tile_BlackEdge_Table **)0x0) {
    free(this->Black_Edge_Tables);
  }
  if (this->Float_Scroll_Offsets != (void **)0x0) {
    free(this->Float_Scroll_Offsets);
  }
  if (this->Blit_Queue != (Blit_Queue_Entry *)0x0) {
    free(this->Blit_Queue);
  }
  pDVar2 = this->prior_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  pDVar2 = this->futur_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  ppRVar4 = this->pick_lists;
  iVar3 = 5;
  do {
    if (*ppRVar4 != (RGE_SPick_Info *)0x0) {
      free(*ppRVar4);
    }
    ppRVar4 = ppRVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_mode(MouseSystem,0);
    TMousePointer::set_game_enable(MouseSystem,0);
  }
  if (this->DispSel_List != (DisplaySelectedObjRec *)0x0) {
    free(this->DispSel_List);
  }
  reset_overlay_sprites(this);
  TPanel::~TPanel((TPanel *)this);
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 00533940
// [HELPER] s__s_shp: "%s.shp"
/* public: long __thiscall RGE_View::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,unsigned char,int,char *) */

long __thiscall
RGE_View::setup(RGE_View *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
               long param_5,long param_6,uchar param_7,int param_8,char *param_9)
{
  void *pvVar1;
  TShape *pTVar2;
  RGE_SPick_Info *pRVar3;
  int *piVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  char str [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561b4e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  this->cur_render_area = (TDrawArea *)0x0;
  this->calc_draw_count = param_8;
  this->start_scr_col = 0;
  this->start_scr_row = 0;
  this->start_map_col = 0;
  this->start_map_row = 0;
  this->last_view_x = -9999.0;
  this->last_view_y = -9999.0;
  this->function_mode = '\0';
  pvVar1 = (void *)GetStockObject(6);
  this->white_pen = pvVar1;
  pvVar1 = (void *)CreatePen(0,1,0xff);
  this->red_pen = pvVar1;
  pvVar1 = (void *)GetStockObject(5);
  this->hollow_brush = pvVar1;
  sprintf(str + 4,s__s_shp,param_9);
  str._0_4_ = operator_new(0x20);
  uStack_4 = 0;
  if ((TShape *)str._0_4_ == (TShape *)0x0) {
    pTVar2 = (TShape *)0x0;
  }
  else {
    pTVar2 = (TShape *)TShape::TShape((TShape *)str._0_4_,str + 4,-1);
  }
  uStack_4 = 0xffffffff;
  this->border_line_shape = pTVar2;
  Init_Tile_Edge_Tables(this);
  piVar4 = this->pick_list_size;
  iVar5 = 5;
  do {
    pRVar3 = (RGE_SPick_Info *)calloc(0x40,0x14);
    piVar4[-5] = (int)pRVar3;
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: set_focus
// Address: 00533ac0
/* protected: virtual void __thiscall RGE_View::set_focus(int) */

void __thiscall RGE_View::set_focus(RGE_View *this,int param_1)
{
  TPanel::set_focus((TPanel *)this,param_1);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_enable(MouseSystem,this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: Init_Tile_Edge_Tables
// Address: 00533af0
// [HELPER] s_DATA2_BLKEDGE_DAT: "DATA2\BLKEDGE.DAT"
// [HELPER] s_DATA2_TILEEDGE_DAT: "DATA2\TILEEDGE.DAT"
/* WARNING: Variable defined which should be unmapped: B0 */
/* protected: void __thiscall RGE_View::Init_Tile_Edge_Tables(void) */

void __thiscall RGE_View::Init_Tile_Edge_Tables(RGE_View *this)
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  Tile_FogEdge_Table **ppTVar5;
  Tile_BlackEdge_Table **ppTVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uchar *puVar11;
  int iVar12;
  uint uVar13;
  uchar *puVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  int B0;
  int A4;
  int y;
  int B5;
  int B4;
  
  iVar3 = __open(s_DATA2_TILEEDGE_DAT,0x8000);
  if (iVar3 != -1) {
    lseek(iVar3,0,2);
    uVar4 = __tell(iVar3);
    ppTVar5 = (Tile_FogEdge_Table **)calloc(1,uVar4);
    this->Tile_Edge_Tables = ppTVar5;
    lseek(iVar3,0,0);
    read(iVar3,this->Tile_Edge_Tables,uVar4);
    close(iVar3);
    ppTVar5 = this->Tile_Edge_Tables;
    iVar3 = 0;
    do {
      piVar8 = (int *)((int)this->Tile_Edge_Tables + iVar3);
      iVar3 = iVar3 + 4;
      *piVar8 = *piVar8 + (int)ppTVar5;
    } while (iVar3 < 0x44);
    iVar3 = 0;
    do {
      iVar12 = 0x2f;
      piVar8 = *(int **)(iVar3 + (int)this->Tile_Edge_Tables);
      do {
        if (*piVar8 != 0) {
          *piVar8 = *piVar8 + (int)ppTVar5;
        }
        if (piVar8[1] != 0) {
          piVar8[1] = piVar8[1] + (int)ppTVar5;
        }
        piVar8 = piVar8 + 2;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x44);
  }
  iVar3 = __open(s_DATA2_BLKEDGE_DAT,0x8000);
  if (iVar3 != -1) {
    lseek(iVar3,0,2);
    uVar4 = __tell(iVar3);
    ppTVar6 = (Tile_BlackEdge_Table **)calloc(1,uVar4);
    this->Black_Edge_Tables = ppTVar6;
    lseek(iVar3,0,0);
    read(iVar3,this->Black_Edge_Tables,uVar4);
    close(iVar3);
    ppTVar6 = this->Black_Edge_Tables;
    iVar3 = 0;
    do {
      piVar8 = (int *)((int)this->Black_Edge_Tables + iVar3);
      iVar3 = iVar3 + 4;
      *piVar8 = *piVar8 + (int)ppTVar6;
    } while (iVar3 < 0x44);
    iVar3 = 0;
    do {
      piVar8 = *(int **)(iVar3 + (int)this->Black_Edge_Tables);
      iVar12 = 0x2f;
      do {
        if (*piVar8 != 0) {
          *piVar8 = *piVar8 + (int)ppTVar6;
        }
        piVar8 = piVar8 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x44);
  }
  puVar11 = this->EdgeNumber;
  puVar14 = puVar11;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar14[0] = 0xff;
    puVar14[1] = 0xff;
    puVar14[2] = 0xff;
    puVar14[3] = 0xff;
    puVar14 = puVar14 + 4;
  }
  iVar3 = 0;
  B5 = 0;
  do {
    bVar2 = true;
    bVar1 = (byte)iVar3;
    bVar16 = (bVar1 & 1) == 1;
    bVar17 = (bVar1 & 2) == 2;
    bVar18 = (bVar1 & 4) == 4;
    bVar19 = (bVar1 & 8) == 8;
    if (((bVar1 & 0x80) == 0x80) && ((bVar16 || (bVar19)))) {
      bVar2 = false;
    }
    if (((bVar1 & 0x40) == 0x40) && ((bVar18 || (bVar19)))) {
      bVar2 = false;
    }
    if (((bVar1 & 0x20) == 0x20) && ((bVar17 || (bVar18)))) {
      bVar2 = false;
    }
    if (((bVar1 & 0x10) == 0x10) && ((bVar16 || (bVar17)))) {
      bVar2 = false;
    }
    if (bVar2) {
      puVar11[iVar3] = (uchar)B5;
      B5 = B5 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  uVar7 = 0;
  do {
    if (puVar11[uVar7] == 0xff) {
      uVar13 = uVar7 & 1;
      uVar9 = uVar7 & 2;
      uVar15 = uVar7 & 4;
      uVar10 = uVar7 & 8;
      if ((uVar7 & 0x80) != 0) {
        uVar10 = 0;
        uVar13 = 0;
      }
      if ((uVar7 & 0x40) != 0) {
        uVar10 = 0;
        uVar15 = 0;
      }
      if ((uVar7 & 0x20) != 0) {
        uVar15 = 0;
        uVar9 = 0;
      }
      if ((uVar7 & 0x10) != 0) {
        uVar9 = 0;
        uVar13 = 0;
      }
      puVar11[uVar7] = puVar11[uVar7 & 0xf0 | uVar10 | uVar15 | uVar9 | uVar13];
    }
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 0x100);
  return;
}

// --------------------------------------------------

// Function: update_display_selected_objects
// Address: 00533e10
// [HELPER] s_C__msdev_work_age1_x1_view_cpp: "C:\msdev\work\age1_x1\view.cpp"
/* public: void __thiscall RGE_View::update_display_selected_objects(void) */

void __thiscall RGE_View::update_display_selected_objects(RGE_View *this)
{
  RGE_Static_Object *pRVar1;
  ulong uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0x2cb);
  iVar5 = 0;
  if (0 < this->DispSel_List_Max) {
    iVar4 = 0;
    do {
      piVar3 = (int *)((int)&this->DispSel_List->active + iVar4);
      if (*piVar3 != 0) {
        pRVar1 = this->world->objectsValue[piVar3[1]];
        if (pRVar1 == (RGE_Static_Object *)0x0) {
          *piVar3 = 0;
          this->DispSel_List_Size = this->DispSel_List_Size + -1;
        }
        else {
          if ((uint)piVar3[3] < uVar2 - piVar3[2]) {
            *piVar3 = 0;
            this->DispSel_List_Size = this->DispSel_List_Size + -1;
          }
          else if ((uVar2 - piVar3[2] & 0x100) == 0) {
            pRVar1->selected = pRVar1->selected | *(byte *)(piVar3 + 4);
            goto LAB_00533e8f;
          }
          pRVar1->selected = pRVar1->selected & ~*(byte *)(piVar3 + 4);
        }
      }
LAB_00533e8f:
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar5 < this->DispSel_List_Max);
  }
  return;
}

// --------------------------------------------------

// Function: display_object_selection
// Address: 00533ec0
// [HELPER] s_C__msdev_work_age1_x1_view_cpp: "C:\msdev\work\age1_x1\view.cpp"
/* public: void __thiscall RGE_View::display_object_selection(int,int,int,int) */

void __thiscall
RGE_View::display_object_selection(RGE_View *this,int param_1,int param_2,int param_3,int param_4)
{
  bool bVar1;
  int *piVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  bVar1 = false;
  iVar5 = 0;
  piVar6 = (int *)param_4;
  if (0 < this->DispSel_List_Max) {
    iVar4 = 0;
    do {
      piVar2 = (int *)((int)&this->DispSel_List->active + iVar4);
      if (*piVar2 == 0) {
        bVar1 = true;
        piVar6 = piVar2;
      }
      else if ((param_4 != 0) && (piVar2[4] == param_4)) {
        piVar2[2] = piVar2[2] - piVar2[3];
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar5 < this->DispSel_List_Max);
  }
  if (bVar1) {
    *piVar6 = 1;
    piVar6[1] = param_1;
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0x31d);
    piVar6[2] = uVar3;
    piVar6[3] = param_2;
    piVar6[4] = param_3;
    this->DispSel_List_Size = this->DispSel_List_Size + 1;
  }
  return;
}

// --------------------------------------------------

// Function: set_rect
// Address: 00533f70
/* public: virtual void __thiscall RGE_View::set_rect(long,long,long,long) */

void __thiscall
RGE_View::set_rect(RGE_View *this,long param_1,long param_2,long param_3,long param_4)
{
  TSpan_List_Manager *pTVar1;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uStack_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561b81;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::set_rect((TPanel *)this,param_1,param_2,param_3,param_4);
  calc_draw_vars(this);
  create_surfaces(this);
  pTVar1 = this->Terrain_Clip_Mask;
  this->last_view_x = -9999.0;
  this->last_view_y = -9999.0;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Terrain_Fog_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Master_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
                    /* language.dll match for 0x68: "Arial" */
  pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
  local_4 = 0;
  if (pTVar1 == (TSpan_List_Manager *)0x0) {
    pTVar1 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar1 = (TSpan_List_Manager *)TSpan_List_Manager::TSpan_List_Manager(pTVar1,param_3,param_4);
  }
                    /* language.dll match for 0x68: "Arial" */
  local_4 = 0xffffffff;
  this->Terrain_Clip_Mask = pTVar1;
  pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
  local_4 = 1;
  if (pTVar1 == (TSpan_List_Manager *)0x0) {
    pTVar1 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar1 = (TSpan_List_Manager *)TSpan_List_Manager::TSpan_List_Manager(pTVar1,param_3,param_4);
  }
                    /* language.dll match for 0x68: "Arial" */
  local_4 = 0xffffffff;
  this->Terrain_Fog_Clip_Mask = pTVar1;
  pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
  local_4 = 2;
  if (pTVar1 == (TSpan_List_Manager *)0x0) {
    pTVar1 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar1 = (TSpan_List_Manager *)TSpan_List_Manager::TSpan_List_Manager(pTVar1,param_3,param_4);
  }
  this->Master_Clip_Mask = pTVar1;
  local_4 = 0xffffffff;
  if (((MouseSystem != (TMousePointer *)0x0) && (0 < param_3)) && (0 < param_4)) {
    TMousePointer::set_game_window(MouseSystem,param_1,param_2,param_3 + param_1,param_4 + param_2);
    TMousePointer::set_game_mode(MouseSystem,1);
  }
  (**(code **)(this->_padding_ + 0x20))(2);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: delete_surfaces
// Address: 00534100
/* public: void __thiscall RGE_View::delete_surfaces(void) */

void __thiscall RGE_View::delete_surfaces(RGE_View *this)
{
  TDrawArea *this_00;
  
  this_00 = this->save_area1;
  if (this_00 != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this_00);
    operator_delete(this_00);
    this->save_area1 = (TDrawArea *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: create_surfaces
// Address: 00534130
// [HELPER] s_Terrain_Buffer: "Terrain Buffer"
/* public: int __thiscall RGE_View::create_surfaces(void) */

int __thiscall RGE_View::create_surfaces(RGE_View *this)
{
  TDrawArea *pTVar1;
  DClipInfo_List *pDVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561bb1;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if ((this->_padding_ == 0) && (this->_padding_ == 0)) {
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
  if (this->save_area1 == (TDrawArea *)0x0) {
    pTVar1 = (TDrawArea *)operator_new(0x100);
    local_4 = 0;
    if (pTVar1 == (TDrawArea *)0x0) {
      pTVar1 = (TDrawArea *)0x0;
    }
    else {
      pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_Terrain_Buffer,0);
    }
    local_4 = 0xffffffff;
    this->save_area1 = pTVar1;
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::Init(pTVar1,*(TDrawSystem **)this->_padding_,this->_padding_,this->_padding_,1,0);
    }
  }
  if ((this->save_area1 != (TDrawArea *)0x0) && (0 < this->_padding_)) {
    TDrawArea::SetSize(this->save_area1,this->_padding_,this->_padding_,1);
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    TDrawArea::SetFloatOffsets(this->save_area1,0,0);
    pDVar2 = this->prior_objs;
    if (pDVar2 != (DClipInfo_List *)0x0) {
      DClipInfo_List::~DClipInfo_List(pDVar2);
      operator_delete(pDVar2);
    }
    pDVar2 = this->futur_objs;
    if (pDVar2 != (DClipInfo_List *)0x0) {
      DClipInfo_List::~DClipInfo_List(pDVar2);
      operator_delete(pDVar2);
    }
                    /* language.dll match for 0x70: "B" */
    iVar3 = this->_padding_ + 0x1c2;
    pDVar2 = (DClipInfo_List *)operator_new(0x70);
    local_4 = 1;
    if (pDVar2 == (DClipInfo_List *)0x0) {
      pDVar2 = (DClipInfo_List *)0x0;
    }
    else {
      pDVar2 = (DClipInfo_List *)
               DClipInfo_List::DClipInfo_List
                         (pDVar2,iVar3 * 2,iVar3,0x40,-200,this->_padding_ + 0xf9,0x28);
    }
                    /* language.dll match for 0x70: "B" */
    local_4 = 0xffffffff;
    this->prior_objs = pDVar2;
    pDVar2 = (DClipInfo_List *)operator_new(0x70);
    local_4 = 2;
    if (pDVar2 == (DClipInfo_List *)0x0) {
      pDVar2 = (DClipInfo_List *)0x0;
    }
    else {
      pDVar2 = (DClipInfo_List *)
               DClipInfo_List::DClipInfo_List
                         (pDVar2,iVar3 * 2,iVar3,0x40,-200,this->_padding_ + 0xf9,0x28);
    }
    this->futur_objs = pDVar2;
    local_4 = 0xffffffff;
    DClipInfo_List::SetDrawRegion(this->prior_objs,0,0,this->_padding_ + -1,this->_padding_ + -1);
    DClipInfo_List::SetDrawRegion(this->futur_objs,0,0,this->_padding_ + -1,this->_padding_ + -1);
  }
  pTVar1 = this->save_area1;
  *unaff_FS_OFFSET = local_c;
  return (uint)(pTVar1 != (TDrawArea *)0x0);
}

// --------------------------------------------------

// Function: calc_draw_vars
// Address: 00534340
/* protected: void __thiscall RGE_View::calc_draw_vars(void) */

void __thiscall RGE_View::calc_draw_vars(RGE_View *this)
{
  if (((this->_padding_ != 0) && (this->tile_wid != 0)) && (this->tile_hgt != 0)) {
    this->center_scr_col_offset = 0;
    this->center_scr_row_offset = 0;
    this->max_col_num = (short)(this->_padding_ / (int)this->tile_wid);
    this->max_row_num = (short)(this->_padding_ / (int)this->tile_hgt);
    this->center_scr_col =
         ((short)this->_padding_ - this->tile_half_wid) + (short)(this->_padding_ / 2);
    this->center_scr_row =
         ((short)this->_padding_ - this->tile_half_hgt) + (short)(this->_padding_ / 2);
    return;
  }
  this->max_row_num = 0;
  this->max_col_num = 0;
  this->center_scr_col = 0;
  this->center_scr_row = 0;
  this->center_map_col = 0;
  this->center_map_row = 0;
  this->center_scr_col_offset = 0;
  this->center_scr_row_offset = 0;
  return;
}

// --------------------------------------------------

// Function: set_redraw
// Address: 00534420
/* public: virtual void __thiscall RGE_View::set_redraw(enum TPanel::RedrawMode) */

void __thiscall RGE_View::set_redraw(RGE_View *this,RedrawMode param_1)
{
  TPanel::set_redraw((TPanel *)this,param_1);
  if (param_1 == RedrawFull) {
    this->render_terrain_mode = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: set_world
// Address: 00534440
/* public: void __thiscall RGE_View::set_world(class RGE_Game_World *) */

void __thiscall RGE_View::set_world(RGE_View *this,RGE_Game_World *param_1)
{
  RGE_Map *pRVar1;
  
  this->world = param_1;
  if (param_1 != (RGE_Game_World *)0x0) {
    pRVar1 = param_1->map;
    this->map = pRVar1;
    RGE_Map::coordinate_map(pRVar1);
    pRVar1 = this->map;
    this->tile_wid = pRVar1->tile_width;
    this->tile_hgt = pRVar1->tile_height;
    this->tile_half_wid = pRVar1->tile_half_width;
    this->tile_half_hgt = pRVar1->tile_half_height;
    this->elev_hgt = pRVar1->elev_height;
    calc_draw_vars(this);
    return;
  }
  this->map = (RGE_Map *)0x0;
  this->tile_wid = 0;
  this->tile_hgt = 0;
  this->tile_half_wid = 0;
  this->tile_half_hgt = 0;
  this->elev_hgt = 0;
  calc_draw_vars(this);
  return;
}

// --------------------------------------------------

// Function: set_player
// Address: 00534500
/* public: void __thiscall RGE_View::set_player(class RGE_Player *) */

void __thiscall RGE_View::set_player(RGE_View *this,RGE_Player *param_1)
{
  this->player = param_1;
  this->last_view_x = -9999.0;
  this->last_view_y = -9999.0;
  (**(code **)(this->_padding_ + 0x20))(2);
  return;
}

// --------------------------------------------------

// Function: set_selection_area
// Address: 00534530
/* public: void __thiscall RGE_View::set_selection_area(long,long,long,long) */

void __thiscall
RGE_View::set_selection_area(RGE_View *this,long param_1,long param_2,long param_3,long param_4)
{
  if ((this->map != (RGE_Map *)0x0) && (rge_base_game->game_mode != 0x15)) {
    RGE_Map::request_redraw
              (this->map,this->sel_col1,this->sel_row1,this->sel_col2,this->sel_row2,'\0');
  }
  this->sel_col1 = param_1;
  this->sel_row1 = param_2;
  this->sel_col2 = param_3;
  this->sel_row2 = param_4;
  if ((this->map != (RGE_Map *)0x0) && (rge_base_game->game_mode != 0x15)) {
    RGE_Map::request_redraw(this->map,param_1,param_2,param_3,param_4,'\x10');
  }
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: get_selection_area
// Address: 005345d0
/* public: int __thiscall RGE_View::get_selection_area(long &,long &,long &,long &,int) */

int __thiscall
RGE_View::get_selection_area
          (RGE_View *this,long *param_1,long *param_2,long *param_3,long *param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *param_1 = this->sel_col1;
  *param_2 = this->sel_row1;
  *param_3 = this->sel_col2;
  iVar3 = this->sel_row2;
  *param_4 = iVar3;
  iVar1 = *param_1;
  if ((((iVar1 == -1) && (*param_2 == -1)) && (*param_3 == -1)) && (iVar3 == -1)) {
    return 0;
  }
  if (iVar1 < 0) {
    *param_1 = 0;
  }
  else {
    iVar3 = this->map->map_width;
    if (iVar3 <= iVar1) {
      *param_1 = iVar3 + -1;
    }
  }
  if (*param_2 < 0) {
    *param_2 = 0;
  }
  else {
    iVar3 = this->map->map_height;
    if (iVar3 <= *param_2) {
      *param_2 = iVar3 + -1;
    }
  }
  if (*param_3 < 0) {
    *param_3 = 0;
  }
  else {
    iVar3 = this->map->map_width;
    if (iVar3 <= *param_3) {
      *param_3 = iVar3 + -1;
    }
  }
  if (*param_4 < 0) {
    *param_4 = 0;
  }
  else {
    iVar3 = this->map->map_height;
    if (iVar3 <= *param_4) {
      *param_4 = iVar3 + -1;
    }
  }
  if (param_5 != 0) {
    iVar3 = *param_1;
    iVar1 = *param_3;
    iVar2 = *param_4;
    iVar4 = *param_2;
    iVar5 = iVar3;
    if (iVar1 <= iVar3) {
      iVar5 = iVar1;
    }
    *param_1 = iVar5;
    iVar5 = iVar4;
    if (iVar2 <= iVar4) {
      iVar5 = iVar2;
    }
    *param_2 = iVar5;
    if (iVar3 <= iVar1) {
      iVar3 = iVar1;
    }
    *param_3 = iVar3;
    if (iVar4 <= iVar2) {
      iVar4 = iVar2;
    }
    *param_4 = iVar4;
  }
  return 1;
}

// --------------------------------------------------

// Function: CreateBlitQueue
// Address: 005346f0
/* WARNING: Variable defined which should be unmapped: yd */
/* protected: void __thiscall RGE_View::CreateBlitQueue(struct tagRECT &,struct tagRECT &,int,int)
    */

void __thiscall
RGE_View::CreateBlitQueue(RGE_View *this,tagRECT *param_1,tagRECT *param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  Blit_Queue_Entry *pBVar5;
  int iVar6;
  long *plVar7;
  int iVar8;
  int iVar9;
  int yd;
  int vBlits;
  int One_Blit;
  int blt_deltaY;
  int blt_deltaX;
  int local_24;
  tagRECT blt_src;
  int local_4;
  
  bVar4 = false;
  if ((param_3 != 0) || (param_4 != 0)) {
    iVar6 = param_1->top;
    if ((param_2->bottom < iVar6) ||
       (((iVar1 = param_1->left, param_2->right < iVar1 ||
         (iVar2 = param_1->bottom, iVar2 < param_2->top)) ||
        (iVar3 = param_1->right, iVar3 < param_2->left)))) {
      bVar4 = true;
      vBlits = 1;
    }
    else {
      iVar8 = param_4;
      if (param_4 < 0) {
        iVar8 = -param_4;
      }
      iVar9 = param_3;
      if (param_3 < 0) {
        iVar9 = -param_3;
      }
      vBlits = 9999;
      One_Blit = 9999;
      if (param_4 != 0) {
        One_Blit = (iVar8 + (iVar2 - iVar6)) / iVar8;
      }
      if (param_3 != 0) {
        vBlits = (iVar9 + (iVar3 - iVar1)) / iVar9;
      }
      blt_src.top = param_1->left;
      blt_src.right = param_1->top;
      blt_src.bottom = param_1->right;
      local_4 = param_1->bottom;
      local_24 = 0;
      blt_deltaX = 0;
      if (One_Blit < vBlits) {
        vBlits = One_Blit;
        blt_deltaX = param_4;
        if (param_4 < 0) {
          blt_src.right = param_4 + 1 + iVar2;
        }
        else {
          local_4 = param_4 + -1 + iVar6;
        }
      }
      else {
        local_24 = param_3;
        if (param_3 < 0) {
          blt_src.top = param_3 + 1 + iVar3;
        }
        else {
          blt_src.bottom = param_3 + -1 + iVar1;
        }
      }
    }
                    /* Symbol Ref: {@symbol CBQ_One} */
    if (this->Blt_Queue_Allocated < vBlits) {
      if (this->Blit_Queue != (Blit_Queue_Entry *)0x0) {
        free(this->Blit_Queue);
      }
      this->Blit_Queue = (Blit_Queue_Entry *)0x0;
    }
    if (this->Blit_Queue == (Blit_Queue_Entry *)0x0) {
      pBVar5 = (Blit_Queue_Entry *)calloc(vBlits,0x20);
      this->Blt_Queue_Allocated = vBlits;
      this->Blit_Queue = pBVar5;
    }
    if (bVar4) {
      pBVar5 = this->Blit_Queue;
      (pBVar5->src).left = param_1->left;
      (pBVar5->src).top = param_1->top;
      (pBVar5->src).right = param_1->right;
      (pBVar5->src).bottom = param_1->bottom;
      pBVar5 = this->Blit_Queue;
      (pBVar5->dest).left = param_2->left;
      (pBVar5->dest).top = param_2->top;
      (pBVar5->dest).right = param_2->right;
      (pBVar5->dest).bottom = param_2->bottom;
    }
    else if (0 < vBlits) {
      iVar6 = 0;
      param_2 = (tagRECT *)vBlits;
      do {
        plVar7 = (long *)((int)&(this->Blit_Queue->src).left + iVar6);
        *plVar7 = blt_src.top;
        plVar7[1] = blt_src.right;
        plVar7[2] = blt_src.bottom;
        plVar7[3] = local_4;
        *(long *)((int)&(this->Blit_Queue->dest).top + iVar6) = blt_src.right - param_4;
        *(long *)((int)&(this->Blit_Queue->dest).left + iVar6) = blt_src.top - param_3;
        *(int *)((int)&(this->Blit_Queue->dest).bottom + iVar6) = local_4 - param_4;
        *(long *)((int)&(this->Blit_Queue->dest).right + iVar6) = blt_src.bottom - param_3;
        blt_src.right = blt_src.right + blt_deltaX;
        local_4 = local_4 + blt_deltaX;
        blt_src.top = blt_src.top + local_24;
        blt_src.bottom = blt_src.bottom + local_24;
        if (blt_src.right < param_1->top) {
          blt_src.right = param_1->top;
        }
        if (blt_src.top < param_1->left) {
          blt_src.top = param_1->left;
        }
        if (param_1->right < blt_src.bottom) {
          blt_src.bottom = param_1->right;
        }
        if (param_1->bottom < local_4) {
          local_4 = param_1->bottom;
        }
        iVar6 = iVar6 + 0x20;
        param_2 = (tagRECT *)((int)&param_2[-1].bottom + 3);
      } while (param_2 != (tagRECT *)0x0);
    }
    this->Queued_Blits = 1;
    this->Blit_Queue_Size = vBlits;
    this->Current_Blit = -1;
    this->Blit_Offset_X = this->_padding_;
    this->Blit_Offset_Y = this->_padding_;
  }
  return;
}

// --------------------------------------------------

// Function: ProcessQueuedBlit
// Address: 00534a00
/* WARNING: Variable defined which should be unmapped: src */
/* protected: void __thiscall RGE_View::ProcessQueuedBlit(int) */

void __thiscall RGE_View::ProcessQueuedBlit(RGE_View *this,int param_1)
{
  int *piVar1;
  int iVar2;
  Blit_Queue_Entry *pBVar3;
  tagRECT src;
  
  if (this->Queued_Blits != 0) {
    if ((param_1 == 0) &&
       (piVar1 = *(int **)(this->_padding_ + 0x3c), iVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,1),
       iVar2 != 0)) {
      return;
    }
    iVar2 = this->Current_Blit + 1;
    this->Current_Blit = iVar2;
    if (((this->Blit_Queue != (Blit_Queue_Entry *)0x0) && (-1 < iVar2)) &&
       (iVar2 < this->Blit_Queue_Size)) {
      pBVar3 = this->Blit_Queue + iVar2;
      src.right = (pBVar3->src).top + this->Blit_Offset_Y;
      iVar2 = this->Blit_Offset_X;
      src.top = iVar2 + (pBVar3->src).left;
      src.bottom = (pBVar3->src).right + 1 + iVar2;
      piVar1 = *(int **)(this->_padding_ + 0x3c);
      (**(code **)(*piVar1 + 0x1c))
                (piVar1,(pBVar3->dest).left + iVar2,(pBVar3->dest).top + this->Blit_Offset_Y,piVar1,
                 &src.top,0x10);
      if (this->Current_Blit + 1 < this->Blit_Queue_Size) {
        return;
      }
    }
    this->Queued_Blits = 0;
  }
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 00534ae0
// [HELPER] s_view__draw2: "view::draw2"
// [HELPER] s_view__draw3: "view::draw3"
// [HELPER] s_view__draw: "view::draw"
/* WARNING: Variable defined which should be unmapped: old_start_map_row */
/* public: virtual void __thiscall RGE_View::draw(void) */

void __thiscall RGE_View::draw(RGE_View *this)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  TDrawArea *pTVar10;
  ushort uVar11;
  short unaff_BX;
  ushort uVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  char *pcVar17;
  short old_start_map_row;
  short old_start_scr_col;
  short old_start_scr_row;
  int old_map_scr_y_offset;
  tagRECT clip_rect2;
  tagRECT new_rect;
  tagRECT old_rect;
  tagRECT clip_rect1;
  
  tiles_drawn = 0;
  if (view_debug_redraw_all != 0) {
    this->render_terrain_mode = '\0';
    view_debug_redraw_all = 0;
  }
  if ((view_debug_ObstructionMap != 0) || (view_debug_palette != 0)) {
    this->render_terrain_mode = '\0';
  }
  if (this->world == (RGE_Game_World *)0x0) {
    iVar5 = this->_padding_;
    (**(code **)(iVar5 + 0x28))(0);
    TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,
                     (uint)*(byte *)((int)&this->_padding_ + 3));
    (**(code **)(iVar5 + 0x2c))();
    return;
  }
  sVar1 = this->start_scr_row;
  sVar2 = this->start_map_row;
  sVar3 = this->start_scr_col;
  sVar4 = this->start_map_col;
  TSpan_List_Manager::ResetAll(this->Terrain_Clip_Mask);
  TSpan_List_Manager::ResetAll(this->Terrain_Fog_Clip_Mask);
  TSpan_List_Manager::ResetAll(this->Master_Clip_Mask);
  iVar5 = this->map_scr_y_offset;
  iVar13 = this->map_scr_x_offset;
  this->Use_Rect2 = 0;
  this->Limited_Render_Rect = 0;
  update(this);
  clip_rect2.left = this->_padding_;
  (**(code **)(clip_rect2.left + 0x28))(0);
  if ((this->render_terrain_mode != '\x01') ||
     ((((this->start_map_col == sVar4 && (this->start_map_row == unaff_BX)) &&
       (this->start_scr_col == sVar2)) && (this->start_scr_row == sVar3)))) goto LAB_0053512b;
  uVar12 = (short)this->map_scr_y_offset - sVar1;
  uVar11 = (short)this->map_scr_x_offset - (short)iVar13;
  if ((uVar11 == 0) && (uVar12 == 0)) goto LAB_0053512b;
  iVar13 = this->_padding_;
  old_rect.left = 0;
  old_rect.top = 0;
  iVar7 = this->_padding_;
  old_rect.right = iVar13 + -1;
  new_rect.left = (long)(short)uVar11;
  new_rect.top = (long)(short)uVar12;
  old_rect.bottom = iVar7 + -1;
  new_rect.right = old_rect.right + new_rect.left;
  new_rect.bottom = old_rect.bottom + new_rect.top;
  if ((new_rect.bottom < 0) ||
     (((new_rect.right < 0 || (old_rect.bottom < new_rect.top)) || (old_rect.right < new_rect.left))
     )) {
    this->render_terrain_mode = '\0';
    goto LAB_0053512b;
  }
  if ((uVar11 & 7) != 0) {
    uVar9 = new_rect.left;
    if ((short)uVar11 < 1) {
      uVar9 = new_rect.left + 7;
    }
    iVar15 = (uVar9 & 0xfffffff8) - new_rect.left;
    uVar11 = uVar11 + (short)iVar15;
    this->map_scr_x_offset = this->map_scr_x_offset + iVar15;
  }
  if ((uVar12 & 7) != 0) {
    uVar9 = new_rect.top;
    if ((short)uVar12 < 1) {
      uVar9 = new_rect.top + 7;
    }
    iVar15 = (uVar9 & 0xfffffff8) - new_rect.top;
    uVar12 = uVar12 + (short)iVar15;
    this->map_scr_y_offset = this->map_scr_y_offset + iVar15;
  }
  if ((short)uVar11 < 0) {
    old_rect.left = 0;
    old_rect.right = (short)uVar11 + -1 + iVar13;
    new_rect.left = -(int)(short)uVar11;
  }
  else {
    old_rect.left = (long)(short)uVar11;
    old_rect.right = iVar13 + -1;
    new_rect.left = 0;
    iVar13 = iVar13 - old_rect.left;
  }
  new_rect.right = iVar13 + -1;
  iVar13 = (int)(short)uVar11;
  if ((short)uVar12 < 0) {
    old_rect.top = 0;
    old_rect.bottom = (short)uVar12 + -1 + iVar7;
    new_rect.top = -(int)(short)uVar12;
  }
  else {
    old_rect.top = (long)(short)uVar12;
    old_rect.bottom = iVar7 + -1;
    new_rect.top = 0;
    iVar7 = iVar7 - old_rect.top;
  }
  new_rect.bottom = iVar7 + -1;
  iVar7 = (int)(short)uVar12;
  pTVar10 = (TDrawArea *)this->_padding_;
  if ((pTVar10->DrawSystem->DrawType == '\x01') || (pTVar10->UsingVidMem == 0)) {
    TDrawArea::OverlayMemCopy
              (pTVar10,&old_rect,&new_rect,iVar13,iVar7,this->_padding_,this->_padding_);
    this->Queued_Blits = 0;
  }
  else {
    CreateBlitQueue(this,&old_rect,&new_rect,iVar13,iVar7);
    if (MouseSystem != (TMousePointer *)0x0) {
      TMousePointer::Poll(MouseSystem);
    }
    if (this->Queued_Blits != 0) {
      ProcessQueuedBlit(this,0);
    }
  }
  DClipInfo_List::Scroll(this->prior_objs,iVar13,iVar7);
  pTVar10 = this->save_area1;
  iVar15 = this->Float_X_Delta + iVar13;
  this->Float_X_Delta = iVar15;
  if (iVar15 < pTVar10->Width) {
    if ((iVar15 < 0) && (puVar6 = TDrawArea::Lock(pTVar10,s_view__draw2,1), puVar6 != (uchar *)0x0))
{
      pTVar10 = this->save_area1;
      iVar13 = this->Float_Y_Delta + -1;
      this->Float_X_Delta = this->Float_X_Delta + pTVar10->Width;
      this->Float_Y_Delta = iVar13;
      if (iVar13 < 0) {
        this->Float_Y_Delta = pTVar10->Height + -1;
      }
      uVar9 = this->Float_X_Delta;
      pcVar17 = s_view__draw3;
      puVar14 = (undefined4 *)*pTVar10->DisplayOffsets;
      puVar16 = (undefined4 *)((int)pTVar10->DisplayOffsets[pTVar10->Height + -1] + pTVar10->Width);
      for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
        puVar14 = (undefined4 *)((int)puVar14 + 1);
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      pTVar10 = this->save_area1;
      goto LAB_00534f10;
    }
  }
  else {
    puVar6 = TDrawArea::Lock(pTVar10,s_view__draw,1);
    if (puVar6 != (uchar *)0x0) {
      pTVar10 = this->save_area1;
      uVar8 = this->Float_X_Delta - iVar13;
      puVar14 = (undefined4 *)((int)pTVar10->DisplayOffsets[pTVar10->Height + -1] + pTVar10->Width);
      puVar16 = (undefined4 *)*pTVar10->DisplayOffsets;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
        puVar14 = (undefined4 *)((int)puVar14 + 1);
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      pTVar10 = this->save_area1;
      iVar13 = this->Float_Y_Delta + 1;
      this->Float_X_Delta = this->Float_X_Delta - pTVar10->Width;
      this->Float_Y_Delta = iVar13;
      if (pTVar10->Height <= iVar13) {
        this->Float_Y_Delta = 0;
      }
      pcVar17 = s_view__draw;
LAB_00534f10:
      TDrawArea::Unlock(pTVar10,pcVar17);
    }
  }
  iVar7 = this->Float_Y_Delta + iVar7;
  this->Float_Y_Delta = iVar7;
  if (iVar7 < 0) {
    this->Float_Y_Delta = this->save_area1->Height + iVar7;
  }
  iVar13 = this->save_area1->Height;
  if (iVar13 <= this->Float_Y_Delta) {
    this->Float_Y_Delta = this->Float_Y_Delta - iVar13;
  }
  TDrawArea::SetFloatOffsets(this->save_area1,this->Float_X_Delta,this->Float_Y_Delta);
  if ((new_rect.left == 0) && (iVar13 = this->_padding_ + -1, new_rect.right == iVar13)) {
    clip_rect1.left = -1;
    if ((new_rect.top == 0) && (new_rect.bottom == this->_padding_ + -1)) {
      clip_rect2.left = -1;
    }
    else {
      clip_rect2.left = 0;
      clip_rect2.right = iVar13;
      if (new_rect.top == 0) {
        clip_rect2.top = new_rect.bottom + 1;
        clip_rect2.bottom = this->_padding_ + -1;
      }
      else {
        clip_rect2.top = 0;
        clip_rect2.bottom = new_rect.top + -1;
      }
    }
  }
  else if (new_rect.left == 0) {
    clip_rect1.right = this->_padding_ + -1;
    clip_rect1.left = new_rect.right + 1;
    clip_rect1.bottom = this->_padding_ + -1;
    clip_rect1.top = 0;
    if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
      clip_rect2.left = -1;
    }
    else {
      clip_rect2.left = 0;
      if (new_rect.top == 0) {
        clip_rect2.top = new_rect.bottom + 1;
        clip_rect2.right = new_rect.right;
        clip_rect2.bottom = clip_rect1.bottom;
      }
      else {
        clip_rect2.top = 0;
        clip_rect2.right = new_rect.right;
        clip_rect2.bottom = new_rect.top + -1;
      }
    }
  }
  else {
    clip_rect1.right = new_rect.left + -1;
    clip_rect1.bottom = this->_padding_ + -1;
    clip_rect1.left = 0;
    clip_rect1.top = 0;
    if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
      clip_rect2.left = -1;
    }
    else {
      clip_rect2.left = new_rect.left;
      if (new_rect.top == 0) {
        clip_rect2.top = new_rect.bottom + 1;
        clip_rect2.right = this->_padding_ + -1;
        clip_rect2.bottom = clip_rect1.bottom;
      }
      else {
        clip_rect2.top = 0;
        clip_rect2.right = this->_padding_ + -1;
        clip_rect2.bottom = new_rect.top + -1;
      }
    }
  }
  if (clip_rect1.left != -1) {
    TDrawArea::PtrClear(this->save_area1,&clip_rect1,0);
    this->Limited_Render_Rect = 1;
    (this->Render_Rect1).left = clip_rect1.left;
    (this->Render_Rect1).top = clip_rect1.top;
    (this->Render_Rect1).right = clip_rect1.right;
    (this->Render_Rect1).bottom = clip_rect1.bottom;
  }
  if (clip_rect2.left != -1) {
    TDrawArea::PtrClear(this->save_area1,&clip_rect2,0);
    if (clip_rect1.left == -1) {
      this->Limited_Render_Rect = 1;
      (this->Render_Rect1).left = clip_rect2.left;
      (this->Render_Rect1).top = clip_rect2.top;
      (this->Render_Rect1).right = clip_rect2.right;
      (this->Render_Rect1).bottom = clip_rect2.bottom;
    }
    else {
      this->Use_Rect2 = 1;
      (this->Render_Rect2).left = clip_rect2.left;
      (this->Render_Rect2).top = clip_rect2.top;
      (this->Render_Rect2).right = clip_rect2.right;
      (this->Render_Rect2).bottom = clip_rect2.bottom;
    }
  }
LAB_0053512b:
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  if (this->Queued_Blits != 0) {
    ProcessQueuedBlit(this,0);
  }
  iVar13 = rge_base_game->game_mode;
  if ((8 < iVar13) && ((iVar13 < 0xb || (iVar13 == 0x13)))) {
    draw_paint_brush(this);
  }
  if (this->render_terrain_mode == '\0') {
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    TDrawArea::SetFloatOffsets(this->save_area1,0,0);
    TDrawArea::PtrClear(this->save_area1,&this->save_area1->ClipRect,0);
  }
  draw_view(this,'\n',this->save_area1);
  this->render_terrain_mode = '\x01';
  (**(code **)(iVar5 + 0x2c))();
  frame_count = frame_count + 1;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00535210
/* protected: void __thiscall RGE_View::update(void) */

void __thiscall RGE_View::update(RGE_View *this)
{
  RGE_Tile *pRVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  RGE_Player *pRVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short col_adj;
  
  pRVar5 = this->player;
  if ((pRVar5 != (RGE_Player *)0x0) &&
     ((pRVar5->view_x != this->last_view_x || (pRVar5->view_y != this->last_view_y)))) {
    sVar6 = __ftol();
    this->center_map_col = sVar6;
    sVar7 = __ftol();
    sVar6 = this->center_map_col;
    this->center_map_row = sVar7;
    this->last_view_x = pRVar5->view_x;
    this->last_view_y = pRVar5->view_y;
    sVar9 = ((short)this->_padding_ + (short)(this->_padding_ / 2)) - this->tile_half_wid;
    this->center_scr_col = sVar9;
    sVar10 = ((short)this->_padding_ + (short)(this->_padding_ / 2)) - this->tile_half_hgt;
    this->center_scr_row = sVar10;
    sVar7 = __ftol();
    sVar8 = __ftol();
    uVar2 = this->tile_half_hgt;
    sVar9 = sVar9 + -sVar7;
    sVar10 = sVar10 + -(sVar8 + uVar2);
    this->center_scr_col = sVar9;
    this->center_scr_row = sVar10;
    pRVar1 = this->map->map_row_offset[this->center_map_row] + sVar6;
    this->map_scr_x_offset = (int)pRVar1->screen_xpos - (int)sVar9;
    this->map_scr_y_offset =
         ((int)this->elev_hgt * (uint)((byte)pRVar1->field_0x5 >> 5) + (int)pRVar1->screen_ypos) -
         (int)sVar10;
    uVar3 = this->tile_half_wid;
    this->center_scr_col_offset = (sVar6 + this->center_map_row) * uVar3 + -sVar7;
    this->start_map_row = this->center_map_row;
    this->center_scr_row_offset =
         (this->center_map_row - sVar6) * this->tile_half_hgt + -(sVar8 + uVar2);
    sVar7 = this->max_col_num / 2 + 2;
    this->start_map_row = this->start_map_row - sVar7;
    uVar4 = this->tile_half_wid;
    this->start_map_col = sVar6 - sVar7;
    this->start_scr_col = sVar9 + sVar7 * uVar4 * -2;
    sVar6 = this->max_row_num / 2 + 1;
    this->start_map_col = this->start_map_col + sVar6;
    this->start_map_row = this->start_map_row - sVar6;
    this->start_scr_row = sVar10 + sVar6 * this->tile_half_hgt * -2;
  }
  return;
}

// --------------------------------------------------

// Function: draw_view
// Address: 00535480
// [HELPER] s_view__draw_view: "view::draw_view"
/* WARNING: Variable defined which should be unmapped: save_render_rect */
/* protected: void __thiscall RGE_View::draw_view(unsigned char,class TDrawArea *) */

void __thiscall RGE_View::draw_view(RGE_View *this,uchar param_1,TDrawArea *param_2)
{
  tagRECT tVar1;
  uchar *puVar2;
  tagRECT save_render_rect;
  int local_4;
  
  if (param_2 == (TDrawArea *)0x0) {
    param_2 = (TDrawArea *)this->_padding_;
  }
  this->cur_render_area = param_2;
  if (param_2 == this->save_area1) {
    save_render_rect.top = this->_padding_;
    save_render_rect.bottom = this->_padding_;
    save_render_rect.right = this->_padding_;
    local_4 = this->_padding_;
    this->_padding_ = 0;
    this->start_scr_col = this->start_scr_col - (short)save_render_rect.top;
    this->start_scr_row = this->start_scr_row - (short)save_render_rect.right;
    this->_padding_ = save_render_rect.bottom - save_render_rect.top;
    this->_padding_ = 0;
    this->_padding_ = local_4 - save_render_rect.right;
    this->map_scr_x_offset = this->map_scr_x_offset + save_render_rect.top;
    this->map_scr_y_offset = this->map_scr_y_offset + save_render_rect.right;
  }
  puVar2 = TDrawArea::Lock(param_2,s_view__draw_view,1);
  if (puVar2 != (uchar *)0x0) {
    if (param_1 == '\n') {
      tVar1.top = save_render_rect.right;
      tVar1.left = save_render_rect.top;
      tVar1.right = save_render_rect.bottom;
      tVar1.bottom = local_4;
      view_function_terrain(this,'\n',tVar1);
    }
    else {
      view_function(this,param_1,'\0',(tagPOINT *)0x0,(tagPOINT *)0x0,(void **)0x0,(float *)0x0,
                    (float *)0x0,(short *)0x0,(short *)0x0);
    }
    TDrawArea::Unlock(this->cur_render_area,s_view__draw_view);
  }
  if (this->cur_render_area == this->save_area1) {
    this->start_scr_col = this->start_scr_col + (short)save_render_rect.top;
    this->start_scr_row = this->start_scr_row + (short)save_render_rect.right;
    this->_padding_ = this->_padding_ + save_render_rect.top;
    this->_padding_ = this->_padding_ + save_render_rect.right;
    this->_padding_ = this->_padding_ + save_render_rect.top;
    this->_padding_ = this->_padding_ + save_render_rect.right;
    this->map_scr_x_offset = this->map_scr_x_offset - save_render_rect.top;
    this->map_scr_y_offset = this->map_scr_y_offset - save_render_rect.right;
  }
  this->cur_render_area = (TDrawArea *)0x0;
  return;
}

// --------------------------------------------------

// Function: draw_object_outline
// Address: 00535610
/* WARNING: Variable defined which should be unmapped: x1 */
/* protected: void __thiscall RGE_View::draw_object_outline(void) */

void __thiscall RGE_View::draw_object_outline(RGE_View *this)
{
  RGE_Master_Static_Object *this_00;
  int iVar1;
  RGE_Static_Object *pRVar2;
  uchar uVar3;
  char cVar4;
  short sVar5;
  short sVar6;
  RGE_Player *pRVar7;
  int iVar8;
  uint uVar9;
  RGE_Color_Table *pRVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  short *psVar16;
  short *psVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  short *psVar22;
  short x1;
  short y2;
  short x4;
  short y3;
  short x2;
  short y1;
  short scr_x;
  uchar frame_color;
  short scr_y;
  short x3;
  short y4;
  tagPOINT point;
  RGE_Pick_Info pick_info;
  
  sVar5 = rge_base_game->master_obj_id;
  if (sVar5 != -1) {
    pRVar7 = RGE_Base_Game::get_player(rge_base_game);
    this_00 = pRVar7->master_objects[sVar5];
    if (this_00 != (RGE_Master_Static_Object *)0x0) {
      RGE_Base_Game::get_mouse_pos(rge_base_game,(tagPOINT *)&point.y);
      if ((this->_padding_ <= point.y) && (point.y <= this->_padding_)) {
        if ((this->_padding_ <= (int)pick_info.x) && ((int)pick_info.x <= this->_padding_)) {
          uVar3 = pick(this,'(','\0',point.y - this->_padding_,(int)pick_info.x - this->_padding_,
                       (RGE_Pick_Info *)&pick_info.y,(RGE_Static_Object *)0x0);
          if (uVar3 == '3') {
            iVar1 = this_00->_padding_;
            psVar22 = &pick_info.scr_x;
            pfVar21 = &pick_info.y;
            (**(code **)(iVar1 + 0x24))(pfVar21,psVar22,this->world,0);
            psVar17 = &x2;
            iVar19 = 1;
            psVar16 = &x1;
            sVar5 = __ftol();
            sVar6 = __ftol();
            iVar19 = get_tile_screen_coords(this,sVar6,sVar5,psVar16,psVar17,iVar19);
            if (iVar19 != 0) {
              RGE_Master_Static_Object::alignment_box
                        (this_00,this->world,_y4,(float)point.x,(short *)&stack0xffffffb4,
                         (short *)&stack0xffffffbe,(short *)&stack0xffffffbc,
                         (short *)&stack0xffffffb6,&scr_x,(short *)&stack0xffffffba,
                         (short *)&stack0xffffffb8,(short *)&frame_color);
              uVar9 = (uint)this_00->elevation_flag;
              iVar20 = 1;
              uVar18 = 1;
              iVar19 = 1;
              uVar15 = 0;
              uVar14 = 1;
              uVar13 = 0;
              pRVar7 = RGE_Base_Game::get_player(rge_base_game);
              cVar4 = (**(code **)(iVar1 + 0x20))
                                (pRVar7,_y4,point.x,uVar13,uVar14,uVar9,uVar15,iVar19,uVar18);
              if (cVar4 == '\0') {
                fog_next_shape = 5;
              }
              else {
                uVar9 = this->world->world_time >> 7 & 7;
                if (uVar9 < 4) {
                  iVar8 = uVar9 + 0x24;
                }
                else {
                  iVar8 = 0x2c - uVar9;
                }
                fog_next_shape = iVar8 << 4 | 9;
              }
              iVar19 = (int)pfVar21 + iVar19 + ((int)(short)uVar14 - (int)(short)pfVar21) / 2;
              iVar20 = (int)psVar22 +
                       iVar20 + ((int)(short)((uint)uVar14 >> 0x10) - (int)(short)psVar22) / 2;
              if (this_00->sprite != (RGE_Sprite *)0x0) {
                SDI_Draw_Line = (int)(short)iVar20;
                uVar9 = this_00->draw_flag & 1;
                if (cVar4 == '\0') {
                  uVar12 = (uint)this_00->draw_color;
                }
                else {
                  uVar12 = 0x97;
                }
                if (((rge_base_game->game_mode == 8) && (rge_base_game->sub_game_mode == 1)) &&
                   (pRVar2 = this->movable_object, pRVar2 != (RGE_Static_Object *)0x0)) {
                  uVar13 = 0;
                  uVar11 = (uint)pRVar2->facet;
                  pRVar10 = pRVar2->owner->color_table;
                  iVar8 = this->_padding_;
                }
                else {
                  uVar13 = 0;
                  uVar11 = 0;
                  pRVar7 = RGE_Base_Game::get_player(rge_base_game);
                  pRVar10 = pRVar7->color_table;
                  iVar8 = this->_padding_;
                }
                (**(code **)(iVar1 + 0x34))(iVar8,iVar19,iVar20,pRVar10,uVar11,uVar13,uVar9,uVar12);
              }
              fog_next_shape = 0;
            }
          }
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_paint_brush
// Address: 005358b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: void __thiscall RGE_View::draw_paint_brush(void) */

void __thiscall RGE_View::draw_paint_brush(RGE_View *this)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  tagPOINT point;
  RGE_Pick_Info pick_info;
  
  set_selection_area(this,-1,-1,-1,-1);
  RGE_Base_Game::get_mouse_pos(rge_base_game,(tagPOINT *)&point.y);
  if ((((this->_padding_ <= point.y) && (point.y <= this->_padding_)) &&
      (this->_padding_ <= (int)pick_info.x)) && ((int)pick_info.x <= this->_padding_)) {
    uVar1 = pick(this,'(','\0',point.y,(long)pick_info.x,(RGE_Pick_Info *)&pick_info.y,
                 (RGE_Static_Object *)0x0);
    if (uVar1 == '3') {
      if (rge_base_game->game_mode == 0x13) {
        iVar2 = __ftol();
        point.x = iVar2 * -3;
        pick_info.y = _DAT_005776bc - (float)point.x;
        iVar2 = __ftol();
        sVar5 = 3;
        point.x = iVar2 * -3;
        pick_info._8_4_ = _DAT_005776bc - (float)point.x;
      }
      else {
        sVar5 = rge_base_game->brush_size;
      }
      iVar2 = __ftol();
      iVar3 = __ftol();
      iVar4 = (int)sVar5 >> 1;
      set_selection_area(this,iVar2 - iVar4,iVar3 - iVar4,iVar2 + iVar4,iVar3 + iVar4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: pick
// Address: 005359e0
/* WARNING: Variable defined which should be unmapped: start_mouse_pos */
/* public: unsigned char __thiscall RGE_View::pick(unsigned char,unsigned char,long,long,struct
   RGE_Pick_Info *,class RGE_Static_Object *) */

uchar __thiscall
RGE_View::pick(RGE_View *this,uchar param_1,uchar param_2,long param_3,long param_4,
              RGE_Pick_Info *param_5,RGE_Static_Object *param_6)
{
  RGE_Pick_Info *pRVar1;
  uchar uVar2;
  long lVar3;
  undefined3 in_stack_00000009;
  tagPOINT start_mouse_pos;
  tagPOINT mouse_pos;
  
  pRVar1 = param_5;
  uVar2 = param_1;
  _param_1 = (RGE_Static_Object *)(-(uint)(param_1 != '(') & (uint)param_6);
  mouse_pos.x = param_4;
  mouse_pos.y = param_3;
  start_mouse_pos.y = param_3;
  param_5->x = 0.0;
  param_5->y = 0.0;
  param_5->scr_x = 0;
  param_5->scr_y = 0;
  param_5->object = (RGE_Static_Object *)0x0;
  param_5->tile = (RGE_Tile *)0x0;
  lVar3 = view_function(this,uVar2,param_2,(tagPOINT *)&mouse_pos.y,(tagPOINT *)&start_mouse_pos.y,
                        (void **)&param_1,&param_5->x,&param_5->y,&param_5->scr_x,&param_5->scr_y);
  uVar2 = (uchar)lVar3;
  if (uVar2 == '4') {
    pRVar1->object = _param_1;
    return '4';
  }
  if (uVar2 == '3') {
    pRVar1->tile = (RGE_Tile *)_param_1;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: pick_multi
// Address: 00535a80
/* WARNING: Variable defined which should be unmapped: picked_any */
/* public: unsigned char __thiscall RGE_View::pick_multi(unsigned char,long,long,long,long) */

uchar __thiscall
RGE_View::pick_multi
          (RGE_View *this,uchar param_1,long param_2,long param_3,long param_4,long param_5)
{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  RGE_Pick_Obj_Info **ppRVar6;
  int iVar7;
  int picked_any;
  
  iVar7 = 0;
  bVar1 = false;
  iVar3 = pick_multi_objects(this,param_2,param_3,param_4,param_5,10,0x14,(int)this->player->id,
                             param_1,1);
  if (0 < iVar3) {
    ppRVar6 = &Picked_Objects;
    do {
      if (((*ppRVar6 != (RGE_Pick_Obj_Info *)0xffffffff) &&
          (pRVar5 = this->world->objectsValue[(int)*ppRVar6], pRVar5 != (RGE_Static_Object *)0x0))
         && (pRVar5->object_state < 7)) {
        iVar4 = RGE_Player::select_one_object(this->player,pRVar5,0);
        if (iVar4 == 0) break;
        bVar1 = true;
      }
      iVar7 = iVar7 + 1;
      ppRVar6 = ppRVar6 + 3;
    } while (iVar7 < iVar3);
  }
  if (bVar1) {
    return '\x01';
  }
  iVar4 = param_4 - param_2;
  iVar7 = param_5 - param_3;
  iVar3 = iVar4;
  if (iVar7 <= iVar4) {
    iVar3 = iVar7;
  }
  if (iVar3 < 0x32) {
    iVar3 = iVar7;
    if (iVar4 < iVar7) {
      iVar3 = iVar4;
    }
  }
  else {
    iVar3 = 0x32;
  }
  param_3 = pick_objects(this,iVar4 / 2 + param_2,iVar7 / 2 + param_3,10,0x14,iVar3,4,1);
  if (param_3 != 0) {
    iVar3 = 0;
    param_4 = 0;
    pRVar5 = (RGE_Static_Object *)0x0;
    if (0 < param_3) {
      ppRVar6 = &Picked_Objects;
      do {
        if (((-1 < (int)*ppRVar6) &&
            (pRVar5 = this->world->objectsValue[(int)*ppRVar6], pRVar5 != (RGE_Static_Object *)0x0))
           && ((pRVar5->object_state < 7 && (1 < pRVar5->master_obj->select_level)))) {
          if ((this->map->map_visible_flag == '\0') &&
             (iVar7 = (**(code **)(this->_padding_ + 0xe0))(pRVar5), iVar7 == 0)) {
            iVar7 = __ftol();
            iVar4 = __ftol();
            uVar2 = RGE_Visible_Map::get_visible(this->player->visible,iVar4,iVar7);
            if (uVar2 != '\x0f') goto LAB_00535c2f;
          }
          iVar7 = (**(code **)(this->_padding_ + 0xe4))(pRVar5,(int)*(short *)(ppRVar6 + 1));
          if (pRVar5->owner == this->player) {
            iVar7 = iVar7 + 5;
          }
          if (iVar3 < iVar7) {
            iVar3 = iVar7;
            param_4 = (long)pRVar5;
          }
        }
LAB_00535c2f:
        ppRVar6 = ppRVar6 + 3;
        param_3 = param_3 + -1;
        pRVar5 = (RGE_Static_Object *)param_4;
      } while (param_3 != 0);
    }
    if ((pRVar5 != (RGE_Static_Object *)0x0) &&
       (iVar3 = RGE_Player::select_one_object(this->player,pRVar5,0), iVar3 != 0)) {
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: pick
// Address: 00535c70
/* public: unsigned char __thiscall RGE_View::pick(unsigned char,unsigned char,struct tagPOINT
   *,struct tagPOINT *,void * *,float *,float *,short *,short *) */

uchar __thiscall
RGE_View::pick(RGE_View *this,uchar param_1,uchar param_2,tagPOINT *param_3,tagPOINT *param_4,
              void **param_5,float *param_6,float *param_7,short *param_8,short *param_9)
{
  long lVar1;
  
  lVar1 = view_function(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9
                       );
  return (uchar)lVar1;
}

// --------------------------------------------------

// Function: pick_through_fog
// Address: 00535cb0
/* public: virtual int __thiscall RGE_View::pick_through_fog(class RGE_Static_Object *) */

int __thiscall RGE_View::pick_through_fog(RGE_View *this,RGE_Static_Object *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: pick_weight
// Address: 00535cc0
/* public: virtual int __thiscall RGE_View::pick_weight(class RGE_Static_Object *,int) */

int __thiscall RGE_View::pick_weight(RGE_View *this,RGE_Static_Object *param_1,int param_2)
{
  bool bVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = param_1;
  param_1 = (RGE_Static_Object *)(uint)param_1->master_obj->select_level;
  if ((this->UC_ObjectTouched == 0) || (this->UC_TouchedObj != pRVar2->id)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (param_1 == (RGE_Static_Object *)0x2) {
    if (bVar1) {
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
      if (!bVar1) {
        if ((param_2 != 1) && (param_2 != 2)) {
          return (param_2 == 3) + 2;
        }
        return 4;
      }
      return 5;
    }
    if (bVar1) {
      return 5;
    }
    if (param_2 != 1) {
      if (param_2 != 2) {
        return 0;
      }
      return 3;
    }
  }
  return 3;
}

// --------------------------------------------------

// Function: get_tile_screen_coords
// Address: 00535da0
/* public: int __thiscall RGE_View::get_tile_screen_coords(short,short,short *,short *,int) */

int __thiscall
RGE_View::get_tile_screen_coords
          (RGE_View *this,short param_1,short param_2,short *param_3,short *param_4,int param_5)
{
  RGE_Tile *pRVar1;
  byte bVar2;
  RGE_Map *pRVar3;
  short sVar4;
  
  if (param_3 != (short *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (short *)0x0) {
    *param_4 = 0;
  }
  if (-1 < param_1) {
    pRVar3 = this->map;
    if (((((int)param_1 < pRVar3->map_width) && (-1 < param_2)) &&
        ((int)param_2 < pRVar3->map_height)) &&
       (pRVar1 = pRVar3->map_row_offset[param_2] + param_1, pRVar1 != (RGE_Tile *)0x0)) {
      bVar2 = pRVar1->tile_type;
      sVar4 = (pRVar3->tilesizes[bVar2].y_delta + pRVar1->screen_ypos) -
              (short)this->map_scr_y_offset;
      if (param_5 != 0) {
        if (bVar2 != 0) {
          sVar4 = sVar4 + this->elev_hgt / 2;
        }
        if (bVar2 == 6) {
          sVar4 = sVar4 - this->elev_hgt;
        }
        if (bVar2 == 5) {
          sVar4 = sVar4 - this->elev_hgt;
        }
        if (bVar2 == 3) {
          sVar4 = sVar4 - this->elev_hgt;
        }
        if (bVar2 == 0xb) {
          sVar4 = sVar4 - this->elev_hgt;
        }
      }
      *param_3 = pRVar1->screen_xpos - (short)this->map_scr_x_offset;
      *param_4 = sVar4;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: get_center_screen_pos
// Address: 00535eb0
/* public: void __thiscall RGE_View::get_center_screen_pos(short *,short *) */

void __thiscall RGE_View::get_center_screen_pos(RGE_View *this,short *param_1,short *param_2)
{
  *param_1 = this->center_scr_row;
  *param_2 = this->center_scr_col;
  return;
}

// --------------------------------------------------

// Function: get_start_coords
// Address: 00535ed0
/* public: void __thiscall RGE_View::get_start_coords(short *,short *,short *,short *) */

void __thiscall
RGE_View::get_start_coords
          (RGE_View *this,short *param_1,short *param_2,short *param_3,short *param_4)
{
  if (param_1 != (short *)0x0) {
    *param_1 = this->start_map_col;
  }
  if (param_2 != (short *)0x0) {
    *param_2 = this->start_map_row;
  }
  if (param_3 != (short *)0x0) {
    *param_3 = this->start_scr_col;
  }
  if (param_4 != (short *)0x0) {
    *param_4 = this->start_scr_row;
  }
  return;
}

// --------------------------------------------------

// Function: get_center_coords
// Address: 00535f20
/* public: void __thiscall RGE_View::get_center_coords(short *,short *,short *,short *) */

void __thiscall
RGE_View::get_center_coords
          (RGE_View *this,short *param_1,short *param_2,short *param_3,short *param_4)
{
  if (param_1 != (short *)0x0) {
    *param_1 = this->center_map_col;
  }
  if (param_2 != (short *)0x0) {
    *param_2 = this->center_map_row;
  }
  if (param_3 != (short *)0x0) {
    *param_3 = this->center_scr_col;
  }
  if (param_4 != (short *)0x0) {
    *param_4 = this->center_scr_row;
  }
  return;
}

// --------------------------------------------------

// Function: get_tile_sizes
// Address: 00535f70
/* public: void __thiscall RGE_View::get_tile_sizes(short *,short *,short *,short *) */

void __thiscall
RGE_View::get_tile_sizes(RGE_View *this,short *param_1,short *param_2,short *param_3,short *param_4)
{
  if (param_1 != (short *)0x0) {
    *param_1 = this->tile_wid;
  }
  if (param_2 != (short *)0x0) {
    *param_2 = this->tile_hgt;
  }
  if (param_3 != (short *)0x0) {
    *param_3 = this->tile_half_wid;
  }
  if (param_4 != (short *)0x0) {
    *param_4 = this->tile_half_hgt;
  }
  return;
}

// --------------------------------------------------

// Function: get_max_size
// Address: 00535fc0
/* public: void __thiscall RGE_View::get_max_size(short *,short *) */

void __thiscall RGE_View::get_max_size(RGE_View *this,short *param_1,short *param_2)
{
  *param_1 = this->max_col_num;
  *param_2 = this->max_row_num;
  return;
}

// --------------------------------------------------

// Function: view_function
// Address: 00535fe0
/* WARNING: Variable defined which should be unmapped: visible */
/* protected: long __thiscall RGE_View::view_function(unsigned char,unsigned char,struct tagPOINT
   *,struct tagPOINT *,void * *,float *,float *,short *,short *) */

long __thiscall
RGE_View::view_function
          (RGE_View *this,uchar param_1,uchar param_2,tagPOINT *param_3,tagPOINT *param_4,
          void **param_5,float *param_6,float *param_7,short *param_8,short *param_9)
{
  uchar uVar1;
  short sVar2;
  short sVar3;
  RGE_Visible_Map *this_00;
  RGE_Tile *pRVar4;
  float fVar5;
  byte bVar6;
  char cVar7;
  RGE_Static_Object *pRVar8;
  short sVar9;
  short sVar10;
  undefined4 extraout_EAX;
  RGE_Static_Object *pRVar11;
  byte bVar12;
  short *extraout_ECX;
  short *psVar13;
  undefined2 extraout_var;
  RGE_Map *pRVar14;
  short sVar16;
  byte bVar17;
  short sVar18;
  bool bVar19;
  short sVar20;
  RGE_Tile *pRVar21;
  short sVar22;
  short sVar23;
  int iVar24;
  uchar visible;
  short screen_col;
  uchar local_75;
  short map_row;
  short map_col;
  short start_scr_col2;
  short start_scr_row2;
  short cur_col_num;
  uchar picked_type;
  uchar fog_flag;
  RGE_Tile *tile;
  short start_map_col2;
  short start_map_row2;
  uchar direction;
  short tile_screen_row;
  RGE_Static_Object *last_picked_obj;
  uchar terrain_type;
  uchar tile_type;
  short col_num;
  short row_num;
  long calc_sel_col1;
  long calc_sel_col2;
  long calc_sel_row1;
  long calc_sel_row2;
  RGE_Static_Object *orig_picked_obj;
  short find_col;
  short find_row;
  short max_col_num2;
  short max_row_num2;
  int list_size;
  RGE_Tile_List_Node *list;
  RGE_Tile_List_Node *local_4;
  undefined2 uVar15;
  
  this->function_mode = param_1;
  this->function_parm = param_2;
  if ((param_1 == '\n') && (this->calc_draw_count != 0)) {
    pRVar14 = this->map;
    sVar16 = 0;
    if (0 < pRVar14->num_terrain) {
      do {
        iVar24 = (int)sVar16;
        sVar16 = sVar16 + 1;
        pRVar14->terrain_types[iVar24].drawn = '\0';
        pRVar14 = this->map;
      } while (sVar16 < pRVar14->num_terrain);
    }
  }
  RGE_Tile_List::get_list_info(&this->player->tile_list,&local_4,(int *)&list);
  uVar1 = this->function_mode;
  iVar24 = CONCAT31((int3)((uint)extraout_EAX >> 8),uVar1);
  bVar6 = 0x32;
  if (uVar1 == '(') {
LAB_0053609a:
    if (uVar1 == '<') goto LAB_0053609e;
  }
  else {
    if (uVar1 != '<') {
      if ((((uVar1 != ')') && (uVar1 != '*')) && (uVar1 != '+')) &&
         (psVar13 = extraout_ECX, uVar1 != ',')) goto LAB_00536104;
      goto LAB_0053609a;
    }
LAB_0053609e:
    _find_row = __ftol();
    _max_col_num2 = __ftol();
  }
  *param_6 = 0.0;
  *param_7 = 0.0;
  *param_8 = 0;
  *param_9 = 0;
  uVar1 = this->function_mode;
  iVar24 = CONCAT31((int3)((uint)param_8 >> 8),uVar1);
  if (((uVar1 == ')') || (uVar1 == '*')) || ((uVar1 == '+' || (uVar1 == ',')))) {
    _find_col = (RGE_Static_Object *)*param_5;
  }
  *param_5 = (void *)0x0;
  _terrain_type = (RGE_Static_Object *)0x0;
  psVar13 = param_9;
LAB_00536104:
  uVar15 = (undefined2)((uint)psVar13 >> 0x10);
  if ((this->function_mode == '\x0e') &&
     (iVar24 = get_selection_area(this,&calc_sel_col2,&calc_sel_row2,&calc_sel_row1,
                                  (long *)&orig_picked_obj,1), uVar15 = extraout_var, iVar24 == 0))
{
    return 0;
  }
  sVar16 = this->start_scr_col;
  sVar2 = this->start_map_col;
  sVar23 = this->start_scr_row;
  sVar10 = this->start_map_row;
  list_size = CONCAT22((short)((uint)iVar24 >> 0x10),this->max_row_num + 6) << 1;
  _picked_type = CONCAT22(uVar15,this->max_col_num + 4);
  cVar7 = '\x04';
  calc_sel_col1 = 0;
  _max_row_num2 = _picked_type;
  if (0 < (short)list_size) {
    do {
      sVar9 = 0;
      sVar20 = sVar16;
      sVar18 = sVar2;
      sVar22 = sVar10;
      if (0 < _picked_type) {
        do {
          if ((((sVar18 < 0) || (this->map->map_width <= (int)sVar18)) || (sVar22 < 0)) ||
             (this->map->map_height <= (int)sVar22)) {
            bVar19 = false;
            if ((this->function_mode == '(') || (this->function_mode == '*')) goto LAB_00536221;
          }
          else {
            bVar19 = true;
LAB_00536221:
            if (bVar19) {
              this_00 = this->player->visible;
              if ((this_00 == (RGE_Visible_Map *)0x0) || (this->map->map_visible_flag != '\0')) {
                local_75 = RGE_Visible_Map::get_visible(this_00,(int)sVar18,(int)sVar22);
                if (local_75 == '\0') {
                  local_75 = 0x80;
                }
              }
              else {
                local_75 = RGE_Visible_Map::get_visible(this_00,(int)sVar18,(int)sVar22);
                if ((this->function_mode == '\x1e') || (this->function_mode == '\x1f')) {
                  local_75 = '\x0f';
                }
              }
              if ((this->function_mode == '\v') &&
                 (pRVar21 = this->map->map_row_offset[sVar22],
                 pRVar21[sVar18].draw_as == pRVar21[sVar18].last_drawn_as)) goto LAB_005362af;
            }
            else {
LAB_005362af:
              local_75 = '\0';
            }
            pRVar8 = _find_col;
            if ((local_75 != '\x0f') && (local_75 != 0x80)) {
              local_75 = '\0';
            }
            if ((((local_75 != '\0') || (uVar1 = this->function_mode, uVar1 == '\x0e')) ||
                (uVar1 == '(')) || ((uVar1 == '<' || (uVar1 == '*')))) {
              if (bVar19) {
                pRVar4 = this->map->map_row_offset[sVar22];
                pRVar21 = pRVar4 + sVar18;
                _col_num = (uint)pRVar4[sVar18].tile_type;
                bVar12 = (byte)pRVar21->field_0x5 >> 5;
              }
              else {
                _col_num = 0;
                bVar12 = 0;
                pRVar21 = (RGE_Tile *)0x0;
              }
              last_picked_obj._0_2_ = sVar23 - (ushort)bVar12 * this->elev_hgt;
              switch(_col_num) {
              case 2:
              case 6:
              case 8:
              case 10:
              case 0xe:
              case 0xf:
              case 0x10:
                last_picked_obj._0_2_ = (short)last_picked_obj - this->elev_hgt;
              }
              if ((((this->_padding_ < (int)sVar20) ||
                   (this->_padding_ < (int)(short)last_picked_obj)) ||
                  (((int)this->map->tilesizes[_col_num].width + (int)sVar20 <= this->_padding_ ||
                   ((int)this->map->tilesizes[_col_num].height + (int)(short)last_picked_obj <=
                    this->_padding_)))) ||
                 ((this->function_mode == '\x0e' &&
                  ((((sVar18 < calc_sel_col2 || (calc_sel_row1 < sVar18)) ||
                    (sVar22 < calc_sel_row2)) || ((int)orig_picked_obj < (int)sVar22)))))) {
                bVar19 = true;
              }
              else {
                bVar19 = false;
              }
              uVar1 = this->function_mode;
              if ((((uVar1 == '\n') || (uVar1 == '\x1e')) ||
                  (((uVar1 == '\x1f' || ((uVar1 == ' ' || (uVar1 == '\x15')))) || (uVar1 == '\v'))))
                 || (uVar1 == '\x0e')) {
                if ((!bVar19) &&
                   (((uVar1 = this->function_mode, uVar1 == '\n' || (uVar1 == '\v')) ||
                    (uVar1 == '\x0e')))) {
                  bVar12 = pRVar21->field_0x5;
                  pRVar14 = this->map;
                  bVar17 = bVar12 & 0x1f;
                  _tile_type = bVar12 & 0xffffff1f;
                  sVar3 = pRVar14->terrain_types[bVar12 & 0x1f].terrain_to_draw;
                  if (sVar3 != -1) {
                    bVar17 = (byte)sVar3;
                    _tile_type = (uint)bVar17;
                  }
                  if (((this->function_mode == '\n') && (this->calc_draw_count != 0)) &&
                     ((short)(ushort)bVar17 < pRVar14->num_terrain)) {
                    pRVar14->terrain_types[_tile_type].drawn =
                         pRVar14->terrain_types[_tile_type].drawn + '\x01';
                  }
                  if (this->function_mode == '\v') {
                    pRVar21->last_drawn_as = pRVar21->draw_as;
                  }
                }
                if (((local_75 == '\x0f') || (local_75 == 0x80)) &&
                   ((uVar1 = this->function_mode, uVar1 == '\x1e' ||
                    (((uVar1 == '\x1f' || (uVar1 == ' ')) || (uVar1 == '\x15')))))) {
                  if ((local_75 == '\x0f') || ((local_75 == 0x80 && (this->map->fog_flag == '\0'))))
{
                    tile._0_1_ = '\0';
                  }
                  else {
                    tile._0_1_ = '\x01';
                  }
                  if (uVar1 == '\x1e') {
                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                    fog_next_shape = 1;
                    RGE_Object_List::shadow_draw
                              (&pRVar21->objects,this->cur_render_area,sVar20,sVar23,'\x01',
                               (uchar)tile);
                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                    fog_next_shape = 0;
                    RGE_Object_List::shadow_draw
                              (&pRVar21->objects,this->cur_render_area,sVar20,sVar23,'\x01',
                               (uchar)tile);
                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                  }
                  if (this->function_mode == '\x1f') {
                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                    fog_next_shape = 1;
                    RGE_Object_List::shadow_draw
                              (&pRVar21->objects,this->cur_render_area,sVar20,sVar23,'\n',
                               (uchar)tile);
                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                    fog_next_shape = 0;
                    RGE_Object_List::shadow_draw
                              (&pRVar21->objects,this->cur_render_area,sVar20,sVar23,'\n',
                               (uchar)tile);
                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                  }
                  if (this->function_mode == ' ') {
                    if ((this->map->fog_flag != '\0') && (local_75 == 0x80)) {
                      fog_next_shape = 1;
                    }
                    RGE_Object_List::shadow_draw
                              (&pRVar21->objects,this->cur_render_area,sVar20,sVar23,'\0',
                               (uchar)tile);
                  }
                  else {
                    if (this->function_mode != '\x15') goto LAB_005368a9;
                    if ((this->map->fog_flag != '\0') && (local_75 == 0x80)) {
                      fog_next_shape = 1;
                    }
                    RGE_Object_List::normal_draw
                              (&pRVar21->objects,this->cur_render_area,sVar20,sVar23,(uchar)tile);
                  }
                  fog_next_shape = 0;
                }
              }
              else {
                if (((local_75 == '\x0f') || (local_75 == 0x80)) &&
                   ((uVar1 == ')' || (((uVar1 == '*' || (uVar1 == '+')) || (uVar1 == ',')))))) {
                  if ((local_75 == '\x0f') || ((local_75 == 0x80 && (this->map->fog_flag == '\0'))))
{
                    tile._0_1_ = '\0';
                  }
                  else {
                    tile._0_1_ = '\x01';
                  }
                  pRVar11 = hit_object(this,pRVar21,sVar20,sVar23,sVar18,sVar22,param_3,param_4,
                                       param_8,param_9,_find_col,(uchar)tile);
                  if (pRVar11 != (RGE_Static_Object *)0x0) {
                    if (this->function_mode == ',') {
                      bVar6 = 0x34;
                    }
                    else {
                      if (((pRVar8 != (RGE_Static_Object *)0x0) && (pRVar11 == pRVar8)) &&
                         (bVar6 == 0x34)) {
                        *param_5 = _terrain_type;
                        return 0x34;
                      }
                      if (((_terrain_type == (RGE_Static_Object *)0x0) ||
                          (_terrain_type->master_obj->select_level <=
                           pRVar11->master_obj->select_level)) ||
                         ((_terrain_type == pRVar8 && (pRVar11 != pRVar8)))) {
                        *param_6 = pRVar11->world_x;
                        *param_7 = pRVar11->world_y;
                        bVar6 = 0x34;
                        _terrain_type = pRVar11;
                      }
                    }
                  }
                }
                uVar1 = this->function_mode;
                if ((uVar1 == '(') || ((uVar1 == '*' && (bVar6 == 0x32)))) {
                  iVar24 = hit_tile(this,pRVar21,sVar20,(short)last_picked_obj,sVar18,sVar22,param_3
                                   );
                  if (iVar24 != 0) {
                    if (pRVar21 == (RGE_Tile *)0x0) {
                      *param_6 = (float)(int)sVar18;
                      fVar5 = (float)(int)sVar22;
                    }
                    else {
                      RGE_Map::tile_map_coords
                                (this->map,(short)param_3->x - sVar20,
                                 (short)param_3->y - (short)last_picked_obj,pRVar21,param_6,param_7)
                      ;
                      *param_6 = (float)(int)sVar18 + *param_6;
                      fVar5 = (float)(int)sVar22 + *param_7;
                    }
                    *param_7 = fVar5;
                    *param_8 = sVar20;
                    bVar6 = 0x33;
                    *param_9 = (short)last_picked_obj;
                    *param_5 = pRVar21;
                  }
                }
                else if (((uVar1 == '<') && (sVar18 == find_row)) && (sVar22 == max_col_num2)) {
                  *param_6 = (float)(int)sVar18;
                  *param_7 = (float)(int)sVar22;
                  *param_8 = sVar20;
                  *param_9 = (short)last_picked_obj;
                  *param_5 = pRVar21;
                  return 0x33;
                }
              }
            }
          }
LAB_005368a9:
          sVar20 = sVar20 + this->tile_wid;
          sVar18 = sVar18 + 1;
          sVar22 = sVar22 + 1;
          sVar9 = sVar9 + 1;
        } while (sVar9 < _picked_type);
      }
      if ((cVar7 == '\x01') && (_picked_type == max_row_num2)) {
        cVar7 = '\x02';
      }
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(cVar7) {
      case '\x03':
        _picked_type = _picked_type + -1;
        sVar16 = sVar16 + this->tile_half_wid;
        sVar10 = sVar10 + 1;
        break;
      case '\x05':
                    /* WARNING: This code block may not be properly labeled as switch case */
        sVar16 = sVar16 + this->tile_half_wid;
        sVar10 = sVar10 + 1;
        cVar7 = '\x03';
      }
      sVar23 = sVar23 + this->tile_half_hgt;
      calc_sel_col1 = calc_sel_col1 + 1;
    } while ((short)calc_sel_col1 < (short)list_size);
  }
  if (this->function_mode == '\n') {
    pRVar14 = this->map;
    sVar16 = 0;
    if (0 < pRVar14->num_terrain) {
      do {
        iVar24 = (int)sVar16;
        sVar16 = sVar16 + 1;
        pRVar14->terrain_types[iVar24].frame_changed = '\0';
        pRVar14 = this->map;
      } while (sVar16 < pRVar14->num_terrain);
    }
  }
  uVar1 = this->function_mode;
  if ((((uVar1 == ')') || (uVar1 == '*')) || (uVar1 == '+')) && (bVar6 == 0x34)) {
    *param_5 = _terrain_type;
  }
  return (uint)bVar6;
}

// --------------------------------------------------

// Function: view_function_terrain
// Address: 00536b40
// [HELPER] s_C__msdev_work_age1_x1_view_cpp: "C:\msdev\work\age1_x1\view.cpp"
// [HELPER] s_view__view_function_terrain: "view::view_function_terrain"
/* WARNING: Variable defined which should be unmapped: ResetALLCyclic */
/* protected: long __thiscall RGE_View::view_function_terrain(unsigned char,struct tagRECT) */

long __thiscall RGE_View::view_function_terrain(RGE_View *this,uchar param_1,tagRECT param_2)
{
  RGE_Tile *pRVar1;
  short sVar2;
  Tile_FogEdge_Table *pTVar3;
  uint uVar4;
  Ov_Sprite_Draw_Rec *pOVar5;
  Ov_Sprite_Draw_Rec *pOVar6;
  TSpan_List_Manager *pTVar7;
  undefined4 *puVar8;
  TMessagePanel *this_00;
  int *piVar9;
  int *piVar10;
  Shape_Info *pSVar11;
  bool bVar12;
  RGE_Map *pRVar13;
  long lVar14;
  ulong uVar15;
  DClipInfo_Node *pDVar16;
  TDrawArea *pTVar17;
  DClipInfo_List *pDVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  DClipInfo_Node *pDVar22;
  char cVar23;
  uint uVar24;
  Shape_Info **ppSVar25;
  Shape_Info **ppSVar26;
  bool bVar27;
  short sVar28;
  short sVar29;
  uchar ResetALLCyclic;
  int y;
  DClipInfo_Node *LDI;
  uchar MapVis;
  int map_row;
  int screen_row;
  int newFacet;
  int text_id;
  int black_tile_mask_num;
  int screen_row2;
  int tile_mask_num;
  VSpanMiniList *black_draw_data;
  int fog_draw;
  int clip_to;
  int Map_Width;
  int map_col;
  int Map_Height;
  int black_draw;
  int rect2;
  int Full_Visibility;
  ulong TileVisibleMask;
  VSpanMiniList *fog_draw_data;
  int start_map_x;
  int col_num;
  VSpanMiniList *normal_draw_data;
  int cols_2_scan;
  ulong TileFoggedMask;
  ulong local_a8;
  int rows_2_scan;
  int theObj;
  tagPOINT CPoint;
  tagRECT panel_rect;
  char pText [128];
  
  if (0 < this->DispSel_List_Size) {
    update_display_selected_objects(this);
  }
  col_num = (int)this->start_map_col;
  black_tile_mask_num = (int)this->start_map_row;
  TileFoggedMask = (int)this->max_col_num + 5;
  iVar21 = this->max_row_num * 2 + 0xc;
  map_col = this->map->map_width;
  black_draw = this->map->map_height;
  this->function_mode = param_1;
  pRVar13 = this->map;
  iVar19 = 0;
  if (0 < pRVar13->num_terrain) {
    iVar20 = 0;
    do {
      *(undefined1 *)((int)pRVar13->terrain_types[0].tiles + iVar20 + -1) = 0;
      pRVar13 = this->map;
      iVar19 = iVar19 + 1;
      iVar20 = iVar20 + 0x198;
    } while (iVar19 < pRVar13->num_terrain);
  }
  local_a8 = this->player->mutualExploredMask;
  fog_draw_data = (VSpanMiniList *)this->player->mutualVisibleMask;
  SDI_List = this->futur_objs;
  theObj = iVar21;
  DClipInfo_List::ReclaimAllNodes(this->futur_objs);
  _MapVis = -1;
  if ((this->player->visible == (RGE_Visible_Map *)0x0) ||
     (TileVisibleMask = 0, this->map->map_visible_flag != '\0')) {
    TileVisibleMask = 1;
  }
  text_id = 0;
  if (0 < iVar21) {
    do {
      iVar19 = col_num;
      iVar21 = text_id;
      Map_Height = col_num;
      screen_row = black_tile_mask_num;
      if ((((byte)text_id & 3) == 3) && (MouseSystem != (TMousePointer *)0x0)) {
        TMousePointer::Poll(MouseSystem);
      }
      uVar24 = iVar21 & 1;
      rows_2_scan = uVar24;
      if ((uVar24 == 1) && (this->Queued_Blits != 0)) {
        ProcessQueuedBlit(this,0);
      }
      normal_draw_data = (VSpanMiniList *)0x0;
      if (0 < (int)TileFoggedMask) {
        do {
          if ((-1 < screen_row) && (-1 < iVar19)) {
            if ((screen_row < black_draw) && (iVar19 < map_col)) {
              pRVar13 = this->map;
              pRVar1 = pRVar13->map_row_offset[screen_row] + iVar19;
              iVar20 = (int)pRVar13->map_row_offset[screen_row][iVar19].screen_xpos -
                       this->map_scr_x_offset;
              iVar21 = (int)pRVar1->screen_ypos - this->map_scr_y_offset;
              fog_draw = this->tile_wid + iVar20;
              tile_mask_num = pRVar13->tilesizes[pRVar1->tile_type].height + iVar21;
              sVar28 = (short)iVar20;
              sVar29 = (short)iVar21;
              if (((uint)(&unified_map_offsets)[screen_row][iVar19] & (uint)fog_draw_data) == 0) {
                if (((local_a8 & (uint)(&unified_map_offsets)[screen_row][iVar19]) != 0) ||
                   (TileVisibleMask != 0)) {
                  map_row._0_1_ = (-(pRVar13->fog_flag != '\0') & 0x71U) + 0xf;
                  goto LAB_00536d7a;
                }
                map_row._0_1_ = '\0';
                pRVar1->last_drawn_as = '\0';
              }
              else {
                map_row._0_1_ = '\x0f';
LAB_00536d7a:
                if ((((iVar20 <= this->_padding_) && (iVar21 <= this->_padding_)) &&
                    (this->_padding_ < fog_draw)) && (this->_padding_ < tile_mask_num)) {
                  if ((this->calc_draw_count != 0) &&
                     ((short)(ushort)(pRVar1->field_0x5 & 0x1f) < pRVar13->num_terrain)) {
                    uVar24 = (byte)pRVar1->field_0x5 & 0x1f;
                    pRVar13->terrain_types[uVar24].drawn =
                         pRVar13->terrain_types[uVar24].drawn + '\x01';
                  }
                  black_draw_data = (VSpanMiniList *)0xffffffff;
                  screen_row2 = -1;
                  Map_Width = 0;
                  Full_Visibility = 0;
                  if ((this->render_terrain_mode != '\0') &&
                     (pRVar1->last_drawn_as == (uchar)map_row)) {
                    if ((uchar)map_row == '\x0f') {
                      if (this->map->fog_flag == '\0') {
                        black_draw_data = (VSpanMiniList *)0x0;
                      }
                      else {
                        black_draw_data =
                             (VSpanMiniList *)
                             get_tile_mask_num(this,iVar19,screen_row,map_col,black_draw,
                                               (ulong)fog_draw_data);
                      }
                      if ((VSpanMiniList *)(uint)pRVar1->last_drawn_shape != black_draw_data)
                      goto LAB_00536f71;
                    }
                    if (((uchar)map_row == '\x0f') || ((uchar)map_row == 0x80)) {
                      if (TileVisibleMask == 0) {
                        screen_row2 = get_tile_mask_num(this,iVar19,screen_row,map_col,black_draw,
                                                        local_a8);
                      }
                      else {
                        screen_row2 = 0;
                      }
                      if ((uint)pRVar1->last_drawn_shape2 != screen_row2) goto LAB_00536f71;
                    }
                    if (this->Limited_Render_Rect == 0) goto LAB_0053739b;
                    if ((this->Use_Rect2 != 0) &&
                       (((((this->Render_Rect2).right < iVar20 ||
                          (fog_draw < (this->Render_Rect2).left)) ||
                         ((this->Render_Rect2).bottom < iVar21)) ||
                        (Full_Visibility = 1, tile_mask_num < (this->Render_Rect2).top)))) {
                      Full_Visibility = 0;
                    }
                    if ((((this->Render_Rect1).right < iVar20) ||
                        (fog_draw < (this->Render_Rect1).left)) ||
                       (((this->Render_Rect1).bottom < iVar21 ||
                        (tile_mask_num < (this->Render_Rect1).top)))) {
                      if (Full_Visibility == 0) goto LAB_0053739b;
                      Full_Visibility = 0;
                      Map_Width = 2;
                    }
                    else {
                      Map_Width = 1;
                    }
                  }
LAB_00536f71:
                    /* Symbol Ref: {@symbol draw_this_tile} */
                  pTVar3 = this->Tile_Edge_Tables[pRVar1->tile_type];
                  rect2 = (int)this->Black_Edge_Tables[pRVar1->tile_type];
                  if (this->map->fog_flag == '\0') {
                    black_draw_data = (VSpanMiniList *)0x0;
                  }
                  if (TileVisibleMask != 0) {
                    screen_row2 = 0;
                  }
                  if (black_draw_data == (VSpanMiniList *)0xffffffff) {
                    if ((uchar)map_row == '\x0f') {
                      black_draw_data =
                           (VSpanMiniList *)
                           get_tile_mask_num(this,Map_Height,screen_row,map_col,black_draw,
                                             (ulong)fog_draw_data);
                    }
                    else {
                      black_draw_data = (VSpanMiniList *)0x0;
                    }
                  }
                  iVar19 = screen_row2;
                  if ((screen_row2 == -1) && (iVar19 = 0, (uchar)map_row != '\0')) {
                    iVar19 = get_tile_mask_num(this,Map_Height,screen_row,map_col,black_draw,
                                               local_a8);
                  }
                  screen_row2 = iVar19;
                  cols_2_scan = (int)pTVar3[(int)black_draw_data].normal_draw;
                  start_map_x = (int)pTVar3[(int)black_draw_data].fog_draw;
                  fog_draw = *(int *)(rect2 + screen_row2 * 4);
                  if ((uchar)map_row == 0x80) {
                    start_map_x = (int)pTVar3->normal_draw;
                    clip_to = 1;
                    tile_mask_num = 0;
                  }
                  else {
                    tile_mask_num = (int)((VSpanMiniList *)cols_2_scan != (VSpanMiniList *)0x0);
                    clip_to = (int)((VSpanMiniList *)start_map_x != (VSpanMiniList *)0x0);
                  }
                  if ((screen_row2 < 1) || (rect2 = 1, fog_draw == 0)) {
                    rect2 = 0;
                  }
                  if (Map_Width != _MapVis) {
                    if (Map_Width == 0) {
                      TSpan_List_Manager::SetSpanRegions
                                (this->Terrain_Clip_Mask,this->_padding_,this->_padding_,
                                 this->_padding_,this->_padding_);
                      TSpan_List_Manager::SetSpanRegions
                                (this->Terrain_Fog_Clip_Mask,this->_padding_,this->_padding_,
                                 this->_padding_,this->_padding_);
                    }
                    if (Map_Width == 1) {
                      TSpan_List_Manager::SetSpanRegions
                                (this->Terrain_Clip_Mask,(this->Render_Rect1).left,
                                 (this->Render_Rect1).top,(this->Render_Rect1).right,
                                 (this->Render_Rect1).bottom);
                      TSpan_List_Manager::SetSpanRegions
                                (this->Terrain_Fog_Clip_Mask,(this->Render_Rect1).left,
                                 (this->Render_Rect1).top,(this->Render_Rect1).right,
                                 (this->Render_Rect1).bottom);
                    }
                    _MapVis = Map_Width;
                    if (Map_Width == 2) {
                      TSpan_List_Manager::SetSpanRegions
                                (this->Terrain_Clip_Mask,(this->Render_Rect2).left,
                                 (this->Render_Rect2).top,(this->Render_Rect2).right,
                                 (this->Render_Rect2).bottom);
                      TSpan_List_Manager::SetSpanRegions
                                (this->Terrain_Fog_Clip_Mask,(this->Render_Rect2).left,
                                 (this->Render_Rect2).top,(this->Render_Rect2).right,
                                 (this->Render_Rect2).bottom);
                      _MapVis = Map_Width;
                    }
                  }
                  if (tile_mask_num != 0) {
                    TSpan_List_Manager::AddMiniList
                              (this->Terrain_Clip_Mask,(VSpanMiniList *)cols_2_scan,iVar20,iVar21);
                  }
                  if (clip_to != 0) {
                    TSpan_List_Manager::AddMiniList
                              (this->Terrain_Fog_Clip_Mask,(VSpanMiniList *)start_map_x,iVar20,
                               iVar21);
                  }
                  if (rect2 != 0) {
                    if (tile_mask_num != 0) {
                      TSpan_List_Manager::SubtractMiniList
                                (this->Terrain_Clip_Mask,(VSpanMiniList *)fog_draw,iVar20,iVar21);
                    }
                    if (clip_to != 0) {
                      TSpan_List_Manager::SubtractMiniList
                                (this->Terrain_Fog_Clip_Mask,(VSpanMiniList *)fog_draw,iVar20,iVar21
                                );
                    }
                  }
                  if (Full_Visibility != 0) {
                    TSpan_List_Manager::SetSpanRegions
                              (this->Terrain_Clip_Mask,(this->Render_Rect2).left,
                               (this->Render_Rect2).top,(this->Render_Rect2).right,
                               (this->Render_Rect2).bottom);
                    TSpan_List_Manager::SetSpanRegions
                              (this->Terrain_Fog_Clip_Mask,(this->Render_Rect2).left,
                               (this->Render_Rect2).top,(this->Render_Rect2).right,
                               (this->Render_Rect2).bottom);
                    _MapVis = 2;
                    if (tile_mask_num != 0) {
                      TSpan_List_Manager::AddMiniList
                                (this->Terrain_Clip_Mask,(VSpanMiniList *)cols_2_scan,iVar20,iVar21)
                      ;
                    }
                    if (clip_to != 0) {
                      TSpan_List_Manager::AddMiniList
                                (this->Terrain_Fog_Clip_Mask,(VSpanMiniList *)start_map_x,iVar20,
                                 iVar21);
                    }
                    if (rect2 != 0) {
                      if (tile_mask_num != 0) {
                        TSpan_List_Manager::SubtractMiniList
                                  (this->Terrain_Clip_Mask,(VSpanMiniList *)fog_draw,iVar20,iVar21);
                      }
                      if (clip_to != 0) {
                        TSpan_List_Manager::SubtractMiniList
                                  (this->Terrain_Fog_Clip_Mask,(VSpanMiniList *)fog_draw,iVar20,
                                   iVar21);
                      }
                    }
                  }
                  LDI._0_1_ = pRVar1->field_0x5 & 0x1f;
                  sVar2 = this->map->terrain_types[(byte)pRVar1->field_0x5 & 0x1f].terrain_to_draw;
                  if (sVar2 != -1) {
                    LDI._0_1_ = (byte)sVar2;
                  }
                  pRVar1->last_drawn_shape2 = (uchar)screen_row2;
                  pRVar1->last_drawn_shape = (uchar)black_draw_data;
                  pRVar1->last_drawn_as = (uchar)map_row;
                  pRVar1->draw_as = (uchar)map_row;
                  pRVar1->draw_attribute = pRVar1->draw_attribute & 0xbf;
                  draw_tile(this,pRVar1,(byte)LDI,sVar28,sVar29,(short)Map_Height,(short)screen_row,
                            (uchar)map_row,tile_mask_num,clip_to);
                  tiles_drawn = tiles_drawn + 1;
                  iVar19 = Map_Height;
                }
              }
LAB_0053739b:
                    /* Symbol Ref: {@symbol TileOffScreen} */
              if ((pRVar1 != (RGE_Tile *)0x0) && ((pRVar1->draw_attribute & 0x40) == 0x40)) {
                LDI._0_1_ = pRVar1->field_0x5 & 0x1f;
                sVar2 = this->map->terrain_types[(byte)pRVar1->field_0x5 & 0x1f].terrain_to_draw;
                if (sVar2 != -1) {
                  LDI._0_1_ = (byte)sVar2;
                }
                draw_tile(this,pRVar1,(byte)LDI,sVar28,sVar29,(short)iVar19,(short)screen_row,
                          (uchar)map_row,1,1);
                pRVar1->draw_attribute = pRVar1->draw_attribute & 0xbf;
              }
              if ((view_debug_Objects == 0) && (pRVar1 != (RGE_Tile *)0x0)) {
                SDI_Capture_Info = 1;
                if ((uchar)map_row == '\0') {
                  DClipInfo_List::SetCaptureLevel(this->futur_objs,0,5);
                }
                if ((uchar)map_row != '\x0f') {
                  fog_next_shape = 1;
                }
                RGE_Object_List::draw
                          (&pRVar1->objects,this->save_area1,sVar28,
                           (ushort)((byte)pRVar1->field_0x5 >> 5) * this->tile_half_hgt + sVar29,
                           (uchar)map_row == 0x80);
                DClipInfo_List::SetCaptureLevel(this->futur_objs,0,0x28);
                fog_next_shape = 0;
                SDI_Capture_Info = 0;
              }
            }
            else {
              normal_draw_data = (VSpanMiniList *)TileFoggedMask;
            }
          }
                    /* Symbol Ref: {@symbol SkipCol} */
          iVar19 = iVar19 + 1;
          screen_row = screen_row + 1;
          normal_draw_data = (VSpanMiniList *)&normal_draw_data->X_start;
          iVar21 = text_id;
          uVar24 = rows_2_scan;
          Map_Height = iVar19;
        } while ((int)normal_draw_data < (int)TileFoggedMask);
      }
      if (uVar24 == 1) {
        black_tile_mask_num = black_tile_mask_num + 1;
      }
      else {
        col_num = col_num + -1;
      }
      text_id = iVar21 + 1;
    } while (text_id < theObj);
  }
  iVar21 = this->Queued_Blits;
  while (iVar21 != 0) {
    ProcessQueuedBlit(this,1);
    iVar21 = this->Queued_Blits;
  }
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  this->_padding_ = this->_padding_ + param_2.left;
  this->_padding_ = this->_padding_ + param_2.top;
  this->_padding_ = this->_padding_ + param_2.left;
  this->_padding_ = this->_padding_ + param_2.top;
  SDI_Capture_Info = 1;
  if (this->scroll_action == '\x02') {
    DClipInfo_List::AddGDINode
              (this->futur_objs,4,0x14,this->_padding_ - param_2.left,this->_padding_ - param_2.top,
               this->mouse_last_x - param_2.left,this->mouse_last_y - param_2.top,0,0,0,0,0x28,0xff,
               0);
  }
  iVar21 = rge_base_game->game_mode;
  if ((iVar21 == 1) || ((6 < iVar21 && (iVar21 < 9)))) {
    draw_object_outline(this);
  }
  if (rge_base_game->game_mode == 0x15) {
    (**(code **)(this->_padding_ + 0xf8))();
  }
  bVar27 = false;
  if (this->extra_sprites != (Ov_Sprite_Draw_Rec *)0x0) {
    text_id = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0xe3e);
    pOVar6 = this->extra_sprites;
    while (pOVar6 != (Ov_Sprite_Draw_Rec *)0x0) {
      bVar12 = false;
      if (pOVar6->theShape == (TShape *)0x0) {
LAB_005376e9:
        if (bVar12) goto LAB_005376ed;
        pOVar6 = pOVar6->next;
      }
      else {
        if (pOVar6->LastDrawTime == 0) {
          pOVar6->LastDrawTime = text_id;
        }
        else if (((pOVar6->displayfunction == 1) || (pOVar6->displayfunction == 2)) &&
                (uVar24 = text_id - pOVar6->LastDrawTime, pOVar6->DrawTimeInterval <= uVar24)) {
          do {
            pOVar6->thefacet = pOVar6->thefacet + 1;
            lVar14 = TShape::shape_count(pOVar6->theShape);
            if ((lVar14 <= pOVar6->thefacet) && (pOVar6->thefacet = 0, pOVar6->displayfunction == 2)
               ) {
              bVar12 = true;
              bVar27 = true;
            }
            uVar4 = pOVar6->DrawTimeInterval;
            uVar24 = uVar24 - uVar4;
            pOVar6->LastDrawTime = pOVar6->LastDrawTime + uVar4;
          } while (uVar4 <= uVar24);
        }
        if (!bVar12) {
          SDI_Draw_Level = pOVar6->drawLevel;
          SDI_Object_ID = -1;
          TShape::shape_draw(pOVar6->theShape,(TDrawArea *)this->_padding_,
                             pOVar6->world_x - this->map_scr_x_offset,
                             pOVar6->world_y - this->map_scr_y_offset,pOVar6->thefacet,
                             (uchar)pOVar6->flags,pOVar6->colortable);
          goto LAB_005376e9;
        }
LAB_005376ed:
        if (pOVar6->prev != (Ov_Sprite_Draw_Rec *)0x0) {
          pOVar6->prev->next = pOVar6->next;
        }
        if (pOVar6->next != (Ov_Sprite_Draw_Rec *)0x0) {
          pOVar6->next->prev = pOVar6->prev;
        }
        if (pOVar6->prev == (Ov_Sprite_Draw_Rec *)0x0) {
          this->extra_sprites = pOVar6->next;
        }
        pOVar5 = pOVar6->next;
        operator_delete(pOVar6);
        pOVar6 = pOVar5;
      }
    }
  }
  if (bVar27) {
    reset_cyclic_overlay_sprites(this);
  }
  iVar21 = 0;
  SDI_Capture_Info = 0;
  this->_padding_ = this->_padding_ - param_2.left;
  this->_padding_ = this->_padding_ - param_2.top;
  this->_padding_ = this->_padding_ - param_2.left;
  this->_padding_ = this->_padding_ - param_2.top;
  pDVar18 = this->futur_objs;
  if (0 < pDVar18->YLine_Size) {
    do {
      for (pDVar16 = pDVar18->Draw_Clip_Nodes[iVar21]; pDVar16 != (DClipInfo_Node *)0x0;
          pDVar16 = pDVar16->Next) {
        iVar19 = pDVar16->Draw_Level;
        pDVar22 = this->futur_objs->Draw_Level_Tail[iVar19];
        if (pDVar22 == (DClipInfo_Node *)0x0) {
          this->futur_objs->Draw_Level_Head[iVar19] = pDVar16;
        }
        else {
          pDVar22->NextOnLevel = pDVar16;
        }
        this->futur_objs->Draw_Level_Tail[iVar19] = pDVar16;
      }
      pDVar18 = this->futur_objs;
      iVar21 = iVar21 + 1;
    } while (iVar21 < pDVar18->YLine_Size);
  }
  iVar21 = 0;
  Clip_draw = 0;
  Clip_remove = 0;
  if (_MapVis != 0) {
    TSpan_List_Manager::SetSpanRegions
              (this->Terrain_Clip_Mask,this->_padding_,this->_padding_,this->_padding_,
               this->_padding_);
    TSpan_List_Manager::SetSpanRegions
              (this->Terrain_Fog_Clip_Mask,this->_padding_,this->_padding_,this->_padding_,
               this->_padding_);
  }
  do {
    for (iVar19 = *(int *)((int)this->futur_objs->Draw_Level_Head + iVar21); iVar19 != 0;
        iVar19 = *(int *)(iVar19 + 4)) {
      if (*(int *)(iVar19 + 0x2c) == 0) {
        pTVar7 = this->Terrain_Clip_Mask;
        _ASMSet_Surface_Info
                  (this->save_area1->CurDisplayOffsets,pTVar7->Line_Head_Ptrs,pTVar7->Line_Tail_Ptrs
                   ,pTVar7->Min_Span_Px,pTVar7->Min_Line,pTVar7->Max_Span_Px,pTVar7->Max_Line);
        _ASMSet_Color_Xform(*(undefined4 *)(iVar19 + 0x28));
        _ASMSet_Xlate_Table(*(undefined4 *)(iVar19 + 0x24));
        puVar8 = *(undefined4 **)(iVar19 + 0xc);
        _ASMDraw_Sprite(*(undefined4 *)(iVar19 + 0x20),*(undefined4 *)(iVar19 + 0x14),
                        *(undefined4 *)(iVar19 + 0x18),puVar8[4],puVar8[5],*puVar8,puVar8[1],
                        *(uint *)(iVar19 + 0x1c) & 0xfe);
        pTVar7 = this->Terrain_Fog_Clip_Mask;
        _ASMSet_Surface_Info
                  (this->save_area1->CurDisplayOffsets,pTVar7->Line_Head_Ptrs,pTVar7->Line_Tail_Ptrs
                   ,pTVar7->Min_Span_Px,pTVar7->Min_Line,pTVar7->Max_Span_Px,pTVar7->Max_Line);
        _ASMDraw_Sprite(*(undefined4 *)(iVar19 + 0x20),*(undefined4 *)(iVar19 + 0x14),
                        *(undefined4 *)(iVar19 + 0x18),puVar8[4],puVar8[5],*puVar8,puVar8[1],
                        *(uint *)(iVar19 + 0x1c) | 1);
      }
    }
    iVar21 = iVar21 + 4;
  } while (iVar21 < 0x15);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  if (((rge_base_game->prog_mode == 4) && (this->_padding_ != 0)) &&
     (iVar21 = TMousePointer::get_game_enable(MouseSystem), iVar21 != 0)) {
                    /* language.dll match for 0xf11: "Click to select this Ruin." */
    uVar15 = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0xf11);
    iVar21 = Get_Cursor_Position(this,(tagPOINT *)&CPoint.y,-param_2.left,-param_2.top);
    if (iVar21 != 0) {
      iVar21 = pick_touched_object(this,this->futur_objs,CPoint.y,panel_rect.left,10,0x28,&CPoint.x)
      ;
      if (iVar21 == 1) {
        if (((this->UC_ObjectTouched != 0) && (this->UC_TouchedObj == CPoint.x)) ||
           (this->UC_ObjectTouched = 1, this->UC_TouchedObj == CPoint.x)) goto LAB_00537b2a;
        this->UC_StartTime = uVar15;
        this->UC_TouchedObj = CPoint.x;
        text_id = 0;
        black_tile_mask_num = 0;
        iVar21 = (**(code **)(this->player->_padding_ + 0x9c))
                           (CPoint.x,&text_id,&black_tile_mask_num);
        if (iVar21 == 1) {
          TMousePointer::set_game_facet(MouseSystem,text_id);
          if ((this->message_panel != (TMessagePanel *)0x0) && (rge_base_game->rollover != 0)) {
                    /* language.dll match for 0x7f: "N" */
            TPanel::get_string((TPanel *)this,black_tile_mask_num,pText + 4,0x7f);
                    /* language.dll match for 0x70: "B" */
            TMessagePanel::show_message
                      (this->message_panel,InfoMessage,pText + 4,'p','\0',(void *)0x0,0,0);
          }
          goto LAB_00537b2a;
        }
        TMousePointer::set_game_facet(MouseSystem,0);
        this_00 = this->message_panel;
        if (this_00 == (TMessagePanel *)0x0) goto LAB_00537b2a;
        iVar21 = rge_base_game->rollover;
      }
      else {
        if (this->UC_ObjectTouched == 0) goto LAB_00537b2a;
        this->UC_ObjectTouched = 0;
        this->UC_TouchedObj = -0x80000000;
        TMousePointer::set_game_facet(MouseSystem,0);
        this_00 = this->message_panel;
        if (this_00 == (TMessagePanel *)0x0) goto LAB_00537b2a;
        iVar21 = rge_base_game->rollover;
      }
      if (iVar21 != 0) {
        TMessagePanel::remove_message(this_00);
      }
    }
  }
LAB_00537b2a:
                    /* Symbol Ref: {@symbol no_mouse_process} */
  for (piVar9 = (int *)this->_padding_; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[2]) {
    piVar10 = (int *)*piVar9;
    if ((piVar10[0x1b] != 0) && (piVar10[0xe] != 0)) {
      (**(code **)(*piVar10 + 0xb8))(&panel_rect.top);
      iVar19 = panel_rect.right - param_2.top;
      iVar21 = panel_rect.top - param_2.left;
      if (iVar21 < 0) {
        iVar21 = 0;
      }
      if (iVar19 < 0) {
        iVar19 = 0;
      }
      pDVar16 = DClipInfo_List::AddGDINode
                          (this->futur_objs,3,pText._0_4_ - param_2.top,iVar21,iVar19,
                           panel_rect.bottom - param_2.left,pText._0_4_ - param_2.top,0,0,0,0,0x1e,
                           piVar10[0x38],0);
      if (pDVar16 != (DClipInfo_Node *)0x0) {
        pDVar22 = this->futur_objs->Draw_Level_Tail[0x1e];
        if (pDVar22 == (DClipInfo_Node *)0x0) {
          this->futur_objs->Draw_Level_Head[0x1e] = pDVar16;
        }
        else {
          pDVar22->NextOnLevel = pDVar16;
        }
        this->futur_objs->Draw_Level_Tail[0x1e] = pDVar16;
      }
    }
  }
  if (this->render_terrain_mode == '\0') {
    pTVar17 = this->save_area1;
    iVar21 = 0;
    if (0 < pTVar17->Height) {
      do {
        TSpan_List_Manager::AddSpan(this->Master_Clip_Mask,0,pTVar17->Width + -1,iVar21);
        pTVar17 = this->save_area1;
        iVar21 = iVar21 + 1;
      } while (iVar21 < pTVar17->Height);
    }
    DClipInfo_List::ReclaimAllNodes(this->prior_objs);
  }
  else {
    TSpan_List_Manager::Merge_n_Align
              (this->Master_Clip_Mask,this->Terrain_Clip_Mask,this->Terrain_Fog_Clip_Mask);
    if (this->Limited_Render_Rect != 0) {
      if ((-1 < (this->Render_Rect1).left) &&
         (iVar21 = (this->Render_Rect1).top, iVar21 <= (this->Render_Rect1).bottom)) {
        do {
          TSpan_List_Manager::AddSpan
                    (this->Master_Clip_Mask,(this->Render_Rect1).left,(this->Render_Rect1).right,
                     iVar21);
          iVar21 = iVar21 + 1;
        } while (iVar21 <= (this->Render_Rect1).bottom);
      }
      if (((this->Use_Rect2 != 0) && (-1 < (this->Render_Rect2).left)) &&
         (iVar21 = (this->Render_Rect2).top, iVar21 <= (this->Render_Rect2).bottom)) {
        do {
          TSpan_List_Manager::AddSpan
                    (this->Master_Clip_Mask,(this->Render_Rect2).left,(this->Render_Rect2).right,
                     iVar21);
          iVar21 = iVar21 + 1;
        } while (iVar21 <= (this->Render_Rect2).bottom);
      }
    }
    pDVar18 = this->futur_objs;
    LDI = (DClipInfo_Node *)0x0;
    if (0 < pDVar18->YLine_Size) {
      do {
        for (pDVar16 = pDVar18->Draw_Clip_Nodes[(int)LDI]; pDVar16 != (DClipInfo_Node *)0x0;
            pDVar16 = pDVar16->Next) {
          if (5 < pDVar16->Draw_Level) {
            pDVar22 = this->prior_objs->Draw_Clip_Nodes[(int)LDI];
            bVar27 = true;
            black_tile_mask_num = 1;
            if (pDVar22 != (DClipInfo_Node *)0x0) {
              do {
                bVar27 = true;
                iVar21 = (-(uint)(pDVar16->Node_Type != 0) & 0x10) + 0x24;
                ppSVar25 = &pDVar16->Shape;
                ppSVar26 = &pDVar22->Shape;
                do {
                  if (iVar21 == 0) break;
                  iVar21 = iVar21 + -1;
                  bVar27 = *(char *)ppSVar25 == *(char *)ppSVar26;
                  ppSVar25 = (Shape_Info **)((int)ppSVar25 + 1);
                  ppSVar26 = (Shape_Info **)((int)ppSVar26 + 1);
                } while (bVar27);
                if (bVar27) {
                  bVar27 = false;
                  Clip_remove = Clip_remove + 1;
                  pDVar22->Node_Type = -1;
                  goto LAB_00537d85;
                }
                pDVar22 = pDVar22->Next;
              } while (pDVar22 != (DClipInfo_Node *)0x0);
              bVar27 = true;
            }
LAB_00537d85:
            if (bVar27) {
              if (pDVar16->Node_Type == 0) {
                TSpan_List_Manager::AddShape_Align
                          (this->Master_Clip_Mask,pDVar16->Shape_Base,pDVar16->Shape,pDVar16->Draw_X
                           ,pDVar16->Draw_Y,(uint)(((byte)pDVar16->Draw_Flag & 2) == 2));
                Clip_draw = Clip_draw + 1;
              }
              else {
                Add_GDI_Clip_Mask(this,pDVar16,this->Master_Clip_Mask);
              }
            }
          }
        }
        for (pDVar16 = this->prior_objs->Draw_Clip_Nodes[(int)LDI]; pDVar16 != (DClipInfo_Node *)0x0
            ; pDVar16 = pDVar16->Next) {
          if ((5 < pDVar16->Draw_Level) && (pDVar16->Node_Type != -1)) {
            pDVar22 = this->futur_objs->Draw_Clip_Nodes[(int)LDI];
            bVar27 = true;
            black_tile_mask_num = 1;
            if (pDVar22 != (DClipInfo_Node *)0x0) {
              do {
                bVar27 = true;
                iVar21 = (-(uint)(pDVar16->Node_Type != 0) & 0x10) + 0x24;
                ppSVar25 = &pDVar22->Shape;
                ppSVar26 = &pDVar16->Shape;
                do {
                  if (iVar21 == 0) break;
                  iVar21 = iVar21 + -1;
                  bVar27 = *(char *)ppSVar25 == *(char *)ppSVar26;
                  ppSVar25 = (Shape_Info **)((int)ppSVar25 + 1);
                  ppSVar26 = (Shape_Info **)((int)ppSVar26 + 1);
                } while (bVar27);
                if (bVar27) {
                  bVar27 = false;
                  goto LAB_00537e5a;
                }
                pDVar22 = pDVar22->Next;
              } while (pDVar22 != (DClipInfo_Node *)0x0);
              bVar27 = true;
            }
LAB_00537e5a:
            if (bVar27) {
              if (pDVar16->Node_Type == 0) {
                TSpan_List_Manager::AddShape_Align
                          (this->Master_Clip_Mask,pDVar16->Shape_Base,pDVar16->Shape,pDVar16->Draw_X
                           ,pDVar16->Draw_Y,(uint)(((byte)pDVar16->Draw_Flag & 2) == 2));
                Clip_draw = Clip_draw + 1;
              }
              else {
                Add_GDI_Clip_Mask(this,pDVar16,this->Master_Clip_Mask);
              }
            }
          }
        }
        pDVar18 = this->futur_objs;
        LDI = (DClipInfo_Node *)((int)&LDI->Next + 1);
      } while ((int)LDI < pDVar18->YLine_Size);
    }
  }
                    /* Symbol Ref: {@symbol addNoMore} */
  this->_padding_ = this->_padding_ + param_2.left;
  this->_padding_ = this->_padding_ + param_2.top;
  this->_padding_ = this->_padding_ + param_2.left;
  this->_padding_ = this->_padding_ + param_2.top;
  TDrawArea::PtrSpanCopy
            (this->save_area1,(TDrawArea *)this->_padding_,this->_padding_,this->_padding_,
             &this->save_area1->ClipRect,(uchar **)this->Master_Clip_Mask->Line_Head_Ptrs);
  Update_Render_Pointers(this);
  this->_padding_ = this->_padding_ - param_2.left;
  this->_padding_ = this->_padding_ - param_2.top;
  this->_padding_ = this->_padding_ - param_2.left;
  pTVar7 = this->Master_Clip_Mask;
  this->_padding_ = this->_padding_ - param_2.top;
  _ASMSet_Surface_Info
            (this->RenderOffsets,pTVar7->Line_Head_Ptrs,pTVar7->Line_Tail_Ptrs,pTVar7->Min_Span_Px,
             pTVar7->Min_Line,pTVar7->Max_Span_Px,pTVar7->Max_Line);
  *(TSpan_List_Manager **)(this->_padding_ + 0xd0) = this->Master_Clip_Mask;
  text_id = 0x18;
  do {
    for (pDVar16 = *(DClipInfo_Node **)((int)this->futur_objs->Draw_Level_Head + text_id);
        pDVar16 != (DClipInfo_Node *)0x0; pDVar16 = pDVar16->NextOnLevel) {
      if (pDVar16->Node_Type == 0) {
        bVar27 = false;
        uVar24 = pDVar16->Draw_Flag & 0xffc;
        if (uVar24 != 0) {
          if (((byte)uVar24 & 4) == 4) {
            _ASMSet_Shadowing(0xffffff,0,0xffff00ff,0);
          }
          if (((byte)uVar24 & 8) == 8) {
            uVar24 = ((int)uVar24 >> 4) << 0x10 | (int)uVar24 >> 4;
            _ASMSet_Shadowing(&DAT_ff00ff00,uVar24,0xff00ff,uVar24 << 8);
          }
          bVar27 = true;
        }
        _ASMSet_Color_Xform(pDVar16->Xform_Mask);
        _ASMSet_Xlate_Table(pDVar16->Color_Table);
        pSVar11 = pDVar16->Shape;
        _ASMDraw_Sprite(pDVar16->Shape_Base,pDVar16->Draw_X,pDVar16->Draw_Y,pSVar11->Width,
                        pSVar11->Height,pSVar11->Shape_Data_Offsets,pSVar11->Shape_Outline_Offset,
                        pDVar16->Draw_Flag & 3);
        if (bVar27) {
          _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
        }
      }
      else {
        Draw_GDI_Object(this,pDVar16,(TDrawArea *)this->_padding_);
      }
    }
    text_id = text_id + 4;
  } while (text_id < 0xa1);
  if ((view_debug_spans != 0) && (this->render_terrain_mode != '\0')) {
    iVar21 = frame_count % 0xdc;
    pTVar17 = (TDrawArea *)this->_padding_;
    iVar19 = 0;
    if (0 < pTVar17->Height) {
      do {
        TDrawArea::DrawLine(pTVar17,0,iVar19,pTVar17->Width + -1,iVar19,(char)iVar21 + '\x10');
        pTVar17 = (TDrawArea *)this->_padding_;
        iVar19 = iVar19 + 1;
      } while (iVar19 < pTVar17->Height);
    }
  }
  if (view_debug_palette != 0) {
    LDI = (DClipInfo_Node *)0x0;
    iVar21 = 0x20;
    do {
      cVar23 = '\0';
      iVar19 = 0;
      do {
        TDrawArea::FillRect((TDrawArea *)this->_padding_,iVar19,iVar21,iVar19 + 0x1f,iVar21 + 0xf,
                            cVar23 + (byte)LDI * '\x10');
        iVar19 = iVar19 + 0x20;
        cVar23 = cVar23 + '\x01';
      } while (iVar19 < 0x200);
      iVar21 = iVar21 + 0x10;
      LDI = (DClipInfo_Node *)((int)&LDI->Next + 1);
    } while (iVar21 < 0x120);
  }
  TDrawArea::Unlock((TDrawArea *)this->_padding_,s_view__view_function_terrain);
  *(undefined4 *)(this->_padding_ + 0xd0) = *(undefined4 *)(this->_padding_ + 0xcc);
  pDVar18 = this->futur_objs;
  this->futur_objs = this->prior_objs;
  this->prior_objs = pDVar18;
  return 0;
}

// --------------------------------------------------

// Function: Update_Render_Pointers
// Address: 005381c0
/* protected: void __thiscall RGE_View::Update_Render_Pointers(void) */

void __thiscall RGE_View::Update_Render_Pointers(RGE_View *this)
{
  uchar *puVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = *(uchar **)(this->_padding_ + 8);
  if ((((this->LastRenderBits != puVar1) ||
       (this->LastRenderSize != (this->_padding_ - this->_padding_) + 1)) &&
      (iVar4 = (this->_padding_ - this->_padding_) + 1, 0 < iVar4)) && (puVar1 != (uchar *)0x0)) {
    if ((iVar4 != this->LastRenderSize) || (this->RenderOffsets == (void **)0x0)) {
      if (this->RenderOffsets != (void **)0x0) {
        free(this->RenderOffsets);
      }
      ppvVar2 = (void **)malloc(iVar4 * 4);
      this->RenderOffsets = ppvVar2;
      this->LastRenderSize = iVar4;
    }
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        this->RenderOffsets[iVar3] =
             (void *)(*(int *)(*(int *)(this->_padding_ + 0xbc) + (iVar3 + this->_padding_) * 4) +
                     this->_padding_);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: Add_GDI_Clip_Mask
// Address: 00538280
/* WARNING: Variable defined which should be unmapped: xr2 */
/* protected: void __thiscall RGE_View::Add_GDI_Clip_Mask(struct DClipInfo_Node *,class
   TSpan_List_Manager *) */

void __thiscall
RGE_View::Add_GDI_Clip_Mask(RGE_View *this,DClipInfo_Node *param_1,TSpan_List_Manager *param_2)
{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int xr2;
  int xl2;
  
  iVar5 = param_1->Node_Type;
  if (iVar5 != 1) {
    if ((iVar5 == 2) || (iVar5 == 3)) {
      sVar1 = param_1->x1;
      sVar2 = param_1->x2;
      iVar8 = (int)param_1->y1;
      iVar7 = (int)param_1->y2;
      iVar5 = iVar7;
      iVar9 = iVar8;
      if ((iVar8 <= iVar7) || (iVar5 = iVar8, iVar9 = iVar7, iVar7 <= iVar8)) {
        do {
          TSpan_List_Manager::AddSpan
                    (param_2,CONCAT31((int3)(char)((ushort)sVar1 >> 8),(char)sVar1) & 0xfffffffc,
                     (int)sVar2 | 3,iVar9);
          iVar9 = iVar9 + 1;
        } while (iVar9 <= iVar5);
      }
    }
    if (param_1->Node_Type == 4) {
      uVar3 = (uint)param_1->x1;
      uVar6 = (uint)param_1->x2;
      uVar4 = uVar3;
      if ((int)uVar6 < (int)uVar3) {
        uVar4 = uVar6;
        uVar6 = uVar3;
      }
      iVar9 = (int)param_1->y2;
      uVar10 = uVar4 & 0xfffffffc;
      uVar3 = uVar6 | 3;
      iVar7 = (int)param_1->y1;
      iVar5 = iVar7;
      if (iVar9 < iVar7) {
        iVar5 = iVar9;
        iVar9 = iVar7;
      }
      TSpan_List_Manager::AddSpan(param_2,uVar10,uVar3,iVar5);
      TSpan_List_Manager::AddSpan(param_2,uVar10,uVar3,iVar9);
      while (iVar5 = iVar5 + 1, iVar5 < iVar9) {
        TSpan_List_Manager::AddSpan(param_2,uVar10,uVar4 | 3,iVar5);
        TSpan_List_Manager::AddSpan(param_2,uVar6 & 0xfffffffc,uVar3,iVar5);
      }
    }
    return;
  }
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)param_1->x1,(int)param_1->y1,(int)param_1->x2,(int)param_1->y2);
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)param_1->x2,(int)param_1->y2,(int)param_1->x3,(int)param_1->y3);
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)param_1->x3,(int)param_1->y3,(int)param_1->x4,(int)param_1->y4);
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)param_1->x4,(int)param_1->y4,(int)param_1->x1,(int)param_1->y1);
  return;
}

// --------------------------------------------------

// Function: draw_multi_object_outline
// Address: 00538410
/* public: virtual void __thiscall RGE_View::draw_multi_object_outline(void) */

void __thiscall RGE_View::draw_multi_object_outline(RGE_View *this)
{
  return;
}

// --------------------------------------------------

// Function: Draw_GDI_Object
// Address: 00538420
/* protected: void __thiscall RGE_View::Draw_GDI_Object(struct DClipInfo_Node *,class TDrawArea *)
    */

void __thiscall RGE_View::Draw_GDI_Object(RGE_View *this,DClipInfo_Node *param_1,TDrawArea *param_2)
{
  int iVar1;
  
  if (param_1->Node_Type == 1) {
    TDrawArea::DrawLine(param_2,(int)param_1->x1,(int)param_1->y1,(int)param_1->x2,(int)param_1->y2,
                        (uchar)param_1->Draw_Flag);
    TDrawArea::DrawLine(param_2,(int)param_1->x2,(int)param_1->y2,(int)param_1->x3,(int)param_1->y3,
                        (uchar)param_1->Draw_Flag);
    TDrawArea::DrawLine(param_2,(int)param_1->x3,(int)param_1->y3,(int)param_1->x4,(int)param_1->y4,
                        (uchar)param_1->Draw_Flag);
    TDrawArea::DrawLine(param_2,(int)param_1->x4,(int)param_1->y4,(int)param_1->x1,(int)param_1->y1,
                        (uchar)param_1->Draw_Flag);
    return;
  }
  if ((param_1->Node_Type == 2) && (iVar1 = (int)param_1->y1, iVar1 <= param_1->y2)) {
    do {
      if (param_1->y3 != 0) {
        TDrawArea::DrawLine(param_2,(int)param_1->x1,iVar1,(int)param_1->x3,iVar1,'J');
      }
      if (param_1->y4 != 0) {
        TDrawArea::DrawLine(param_2,(int)param_1->x4,iVar1,(int)param_1->x2,iVar1,0x97);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= param_1->y2);
  }
  if (param_1->Node_Type == 4) {
    TDrawArea::DrawLine(param_2,(int)param_1->x1,(int)param_1->y1,(int)param_1->x2,(int)param_1->y1,
                        0xff);
    TDrawArea::DrawLine(param_2,(int)param_1->x1,(int)param_1->y2,(int)param_1->x2,(int)param_1->y2,
                        0xff);
    TDrawArea::DrawLine(param_2,(int)param_1->x1,(int)param_1->y1,(int)param_1->x1,(int)param_1->y2,
                        0xff);
    TDrawArea::DrawLine(param_2,(int)param_1->x2,(int)param_1->y1,(int)param_1->x2,(int)param_1->y2,
                        0xff);
  }
  return;
}

// --------------------------------------------------

// Function: get_tile_mask_num
// Address: 00538590
/* protected: int __thiscall RGE_View::get_tile_mask_num(int,int,int,int,unsigned long) */

int __thiscall
RGE_View::get_tile_mask_num
          (RGE_View *this,int param_1,int param_2,int param_3,int param_4,ulong param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  if ((((param_1 < 1) || (param_2 < 1)) || (param_3 + -1 <= param_1)) || (param_4 + -1 <= param_2))
{
    if ((0 < param_1) && (((uint)(&unified_map_offsets)[param_2][param_1 + -1] & param_5) == 0)) {
      uVar5 = 0x10;
    }
    iVar1 = param_3 + -1;
    if ((param_1 < iVar1) && (((uint)(&unified_map_offsets)[param_2][param_1 + 1] & param_5) == 0))
{
      uVar5 = uVar5 | 0x40;
    }
    if ((0 < param_2) &&
       ((*(uint *)(*(int *)(&UNK_0087d850.field_0x8fb4 + param_2 * 4) + param_1 * 4) & param_5) == 0
       )) {
      uVar5 = uVar5 | 0x80;
    }
    iVar3 = param_4 + -1;
    if ((param_2 < iVar3) && ((*(uint *)((&DAT_0088680c)[param_2] + param_1 * 4) & param_5) == 0)) {
      uVar5 = uVar5 | 0x20;
    }
    if (0 < param_1) {
      if ((0 < param_2) &&
         ((*(uint *)(*(int *)(&UNK_0087d850.field_0x8fb4 + param_2 * 4) + -4 + param_1 * 4) &
          param_5) == 0)) {
        uVar5 = uVar5 | 1;
      }
      if (((0 < param_1) && (param_2 < iVar3)) &&
         ((*(uint *)((&DAT_0088680c)[param_2] + -4 + param_1 * 4) & param_5) == 0)) {
        uVar5 = uVar5 | 2;
      }
    }
    if (param_1 < iVar1) {
      if ((0 < param_2) &&
         ((*(uint *)(*(int *)(&UNK_0087d850.field_0x8fb4 + param_2 * 4) + 4 + param_1 * 4) & param_5
          ) == 0)) {
        uVar5 = uVar5 | 8;
      }
      if (((param_1 < iVar1) && (param_2 < iVar3)) &&
         ((*(uint *)((&DAT_0088680c)[param_2] + 4 + param_1 * 4) & param_5) == 0)) {
        uVar5 = uVar5 | 4;
      }
    }
  }
  else {
    iVar3 = *(int *)(&UNK_0087d850.field_0x8fb4 + param_2 * 4);
    iVar1 = param_1 * 4;
    if ((*(uint *)(iVar3 + iVar1) & param_5) == 0) {
      uVar5 = 0x80;
    }
    iVar2 = param_1 * 4 + 4;
    if (((uint)(&unified_map_offsets)[param_2][param_1 + 1] & param_5) == 0) {
      uVar5 = uVar5 | 0x40;
    }
    iVar4 = (&DAT_0088680c)[param_2];
    if ((*(uint *)(iVar4 + iVar1) & param_5) == 0) {
      uVar5 = uVar5 | 0x20;
    }
    if (((uint)(&unified_map_offsets)[param_2][param_1 + -1] & param_5) == 0) {
      uVar5 = uVar5 | 0x10;
    }
    if ((*(uint *)(iVar2 + iVar3) & param_5) == 0) {
      uVar5 = uVar5 | 8;
    }
    if ((*(uint *)(iVar4 + iVar2) & param_5) == 0) {
      uVar5 = uVar5 | 4;
    }
    if ((*(uint *)(iVar4 + -4 + iVar1) & param_5) == 0) {
      uVar5 = uVar5 | 2;
    }
    if ((*(uint *)(iVar3 + -4 + iVar1) & param_5) == 0) {
      uVar5 = uVar5 | 1;
    }
  }
  return (uint)this->EdgeNumber[uVar5];
}

// --------------------------------------------------

// Function: draw_tile
// Address: 00538710
/* WARNING: Variable defined which should be unmapped: draw_attribute */
/* protected: int __thiscall RGE_View::draw_tile(struct RGE_Tile *,unsigned
   char,short,short,short,short,unsigned char,int,int) */

int __thiscall
RGE_View::draw_tile(RGE_View *this,RGE_Tile *param_1,uchar param_2,short param_3,short param_4,
                   short param_5,short param_6,uchar param_7,int param_8,int param_9)
{
  uchar *puVar1;
  byte bVar2;
  uchar uVar3;
  RGE_Map *pRVar4;
  TShape *pTVar5;
  RGE_Tile *pRVar6;
  bool bVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  uchar draw_attribute;
  int draw_border;
  int draw_terrain;
  uchar border_type;
  int top_index;
  int left_index;
  int right_index;
  int bottom_index;
  int retval;
  int local_8;
  int local_4;
  
  draw_border._0_1_ = param_1->draw_attribute;
  pRVar4 = this->map;
  if ((pRVar4->num_terrain <= (short)(ushort)param_2) ||
     (local_4 = (uint)param_2 * 0x198, pRVar4->terrain_types[param_2].loaded == '\0')) {
    return 0;
  }
  uVar3 = '\x01';
  local_8 = 0;
  bVar7 = false;
  bVar2 = param_1->field_0x6;
  bVar11 = bVar2 & 0xf;
  if ((((bVar2 & 0xf) != 0) && (uVar10 = bVar2 & 0xf, pRVar4->border_types[uVar10].loaded != '\0'))
     && (pRVar4->border_types[uVar10].shape != (TShape *)0x0)) {
    if (pRVar4->border_types[uVar10].border_style == 0) {
      sVar8 = get_border_picture(this,bVar11,param_1->tile_type,bVar2 >> 4,param_5,param_6);
      if (sVar8 != -1) {
        bVar7 = true;
        uVar3 = this->map->border_types[uVar10].draw_tile;
      }
    }
    else {
      iVar9 = get_border_edge_pictures
                        (this,bVar11,param_1->tile_type,bVar2 >> 4,param_5,param_6,&left_index,
                         &bottom_index,&right_index,&retval);
      if (iVar9 != 0) {
        bVar7 = true;
        uVar3 = '\x01';
      }
    }
  }
  if (((0 < View_Grid_Mode) && (((byte)draw_border & 0xdf) == 0)) &&
     (((char)((int)param_5 / View_Grid_Mode) + (char)((int)param_6 / View_Grid_Mode) & 1U) == 1)) {
    draw_border._0_1_ = (byte)draw_border | 0x20;
  }
  if (view_debug_ObstructionMap != 0) {
    bVar7 = false;
  }
  if (uVar3 != '\0') {
    pTVar5 = *(TShape **)(this->map->terrain_types[0].pict_name + local_4 + 0x11);
    sVar8 = get_tile_picture(this,param_2,param_1->tile_type,param_5,param_6);
    if ((pTVar5 != (TShape *)0x0) && (sVar8 != -1)) {
      if (view_debug_ObstructionMap != 0) {
        draw_terrain_obstruction_map
                  (this,(int)param_3,(int)param_4,pTVar5,(int)sVar8,(int)param_5,(int)param_6);
        return 1;
      }
      draw_terrain_shape(this,(int)param_3,(int)param_4,pTVar5,(int)sVar8,param_7,(byte)draw_border,
                         param_8,param_9);
      local_8 = 1;
    }
    if (!bVar7) {
      if (0 < param_5) {
        puVar1 = &this->map->map_row_offset[param_6][param_5 + -1].draw_attribute;
        *puVar1 = *puVar1 | 0x40;
      }
      if ((int)param_6 < this->map->map_height + -1) {
        puVar1 = &this->map->map_row_offset[param_6 + 1][param_5].draw_attribute;
        *puVar1 = *puVar1 | 0x40;
      }
    }
  }
  if (!bVar7) {
    return local_8;
  }
  pTVar5 = this->map->border_types[bVar2 & 0xf].shape;
  if (pTVar5 == (TShape *)0x0) goto LAB_00538b0e;
  if (this->map->border_types[bVar2 & 0xf].border_style == 0) {
    sVar8 = get_border_picture(this,bVar11,param_1->tile_type,(byte)param_1->field_0x6 >> 4,param_5,
                               param_6);
    if (sVar8 == -1) goto LAB_00538b0e;
    retval = (int)sVar8;
  }
  else {
    iVar9 = get_border_edge_pictures
                      (this,bVar11,param_1->tile_type,(byte)param_1->field_0x6 >> 4,param_5,param_6,
                       &left_index,&bottom_index,&right_index,&retval);
    if (iVar9 == 0) goto LAB_00538b0e;
    if (left_index != -1) {
      draw_terrain_shape(this,(int)param_3,(int)param_4,pTVar5,left_index,param_7,(byte)draw_border,
                         param_8,param_9);
    }
    if (right_index != -1) {
      draw_terrain_shape(this,(int)param_3,(int)param_4,pTVar5,right_index,param_7,(byte)draw_border
                         ,param_8,param_9);
    }
    if (bottom_index != -1) {
      draw_terrain_shape(this,(int)param_3,(int)param_4,pTVar5,bottom_index,param_7,
                         (byte)draw_border,param_8,param_9);
    }
    if (retval == -1) goto LAB_00538b0e;
  }
  draw_terrain_shape(this,(int)param_3,(int)param_4,pTVar5,retval,param_7,(byte)draw_border,param_8,
                     param_9);
LAB_00538b0e:
  if (0 < param_5) {
    puVar1 = &this->map->map_row_offset[param_6][param_5 + -1].draw_attribute;
    *puVar1 = *puVar1 | 0x40;
  }
  if ((int)param_6 < this->map->map_height + -1) {
    pRVar6 = this->map->map_row_offset[param_6 + 1];
    pRVar6[param_5].draw_attribute = pRVar6[param_5].draw_attribute | 0x40;
  }
  return local_8;
}

// --------------------------------------------------

// Function: draw_terrain_shape
// Address: 00538b80
/* protected: void __thiscall RGE_View::draw_terrain_shape(int,int,class TShape *,int,unsigned
   char,unsigned char,int,int) */

void __thiscall
RGE_View::draw_terrain_shape
          (RGE_View *this,int param_1,int param_2,TShape *param_3,int param_4,uchar param_5,
          uchar param_6,int param_7,int param_8)
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3->shape_info[param_4].Hotspot_Y;
  iVar1 = param_3->shape_info[param_4].Hotspot_X;
  if ((param_6 & 0x10) == 0x10) {
    fog_next_shape = 1;
    _ASMSet_Shadowing(0xff00ff,0x28002800,&DAT_ff00ff00,0x280028);
    TShape::shape_draw(param_3,this->cur_render_area,param_1 - iVar1,param_2 - iVar2,param_4,'\0',
                       (uchar *)0x0);
    _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
    fog_next_shape = 0;
    return;
  }
  if ((param_6 & 0x20) == 0x20) {
    _ASMSet_Shadowing(0xff00ff,0x56005600,&DAT_ff00ff00,&DAT_00560056);
  }
  if ((param_6 & 0x80) == 0x80) {
    iVar2 = (param_6 & 0xf) * 0x10001000 + 0x4000400;
    _ASMSet_Shadowing(0xff00ff,iVar2,&DAT_ff00ff00,iVar2);
  }
  if ((this->map->fog_flag != '\0') && (param_5 == 0x80)) {
    fog_next_shape = 1;
  }
  if (param_8 != 0) {
    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
    fog_next_shape = 1;
    TShape::shape_draw(param_3,this->cur_render_area,param_1,param_2,param_4,'\0',(uchar *)0x0);
    fog_next_shape = 0;
  }
  if ((param_6 & 0xa0) != 0) {
    fog_next_shape = 1;
  }
  if (param_7 != 0) {
    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
    TShape::shape_draw(param_3,this->cur_render_area,param_1,param_2,param_4,'\0',(uchar *)0x0);
  }
  this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
  _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
  fog_next_shape = 0;
  return;
}

// --------------------------------------------------

// Function: draw_terrain_obstruction_map
// Address: 00538d60
/* WARNING: Variable defined which should be unmapped: TileX4 */
/* protected: void __thiscall RGE_View::draw_terrain_obstruction_map(int,int,class TShape
   *,int,int,int) */

void __thiscall
RGE_View::draw_terrain_obstruction_map
          (RGE_View *this,int param_1,int param_2,TShape *param_3,int param_4,int param_5,
          int param_6)
{
  int iVar1;
  byte bVar2;
  TShape *this_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int TileX4;
  
  iVar1 = param_5 * 4;
  this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
  TShape::shape_draw(param_3,this->cur_render_area,param_1,param_2,param_4,'\0',(uchar *)0x0);
  this_00 = RGE_Base_Game::get_shape(rge_base_game,0);
  param_5 = 0;
  do {
    iVar4 = 0;
    iVar5 = param_5 * 8;
    iVar3 = param_5 * 4;
    do {
      bVar2 = PathingSystem::obstruction(&pathSystem,iVar4 + iVar1,param_5 + param_6 * 4);
      if (bVar2 != 0) {
        TShape::shape_draw(this_00,this->cur_render_area,param_1 + 2 + iVar5,param_2 + 0xd + iVar3,
                           bVar2 - 1,'\0',(uchar *)0x0);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 8;
      iVar3 = iVar3 + -4;
    } while (iVar4 < 4);
    param_5 = param_5 + 1;
  } while (param_5 < 4);
  return;
}

// --------------------------------------------------

// Function: Get_Cursor_Position
// Address: 00538e60
/* public: int __thiscall RGE_View::Get_Cursor_Position(struct tagPOINT &,int,int) */

int __thiscall
RGE_View::Get_Cursor_Position(RGE_View *this,tagPOINT *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  GetCursorPos(param_1);
  if (*(char *)(*(int *)this->_padding_ + 0x479) == '\x01') {
    ScreenToClient(((int *)this->_padding_)[1],param_1);
    if (0x7fff < param_1->x) {
      param_1->x = param_1->x + -0x10000;
    }
    if (0x7fff < param_1->y) {
      param_1->y = param_1->y + -0x10000;
    }
  }
  iVar1 = param_1->x + param_2;
  param_1->x = iVar1;
  iVar2 = param_1->y + param_3;
  param_1->y = iVar2;
  if ((((this->_padding_ <= iVar1) && (iVar1 <= this->_padding_)) && (this->_padding_ <= iVar2)) &&
     (iVar2 <= this->_padding_)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: Pick_Tile
// Address: 00538f00
/* WARNING: Variable defined which should be unmapped: MapW */
/* protected: int __thiscall RGE_View::Pick_Tile(long,long,int *,int *) */

int __thiscall
RGE_View::Pick_Tile(RGE_View *this,long param_1,long param_2,int *param_3,int *param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int MapW;
  int bx1;
  int local_4;
  
  iVar1 = this->map->map_width;
  local_4 = this->map->map_height;
  iVar2 = (this->map_scr_x_offset - this->_padding_) + param_1;
  iVar4 = (this->map_scr_y_offset - this->_padding_) + param_2;
  if (iVar2 < 0) {
    *param_3 = -1;
    *param_4 = -1;
    return 0;
  }
  if (iVar2 < iVar1 * this->tile_wid) {
    iVar2 = iVar2 / (int)this->tile_wid;
    iVar3 = iVar4 / (int)this->tile_hgt;
    iVar5 = iVar2 - iVar3;
    for (iVar2 = iVar2 + iVar3; (iVar5 < 0 || (iVar1 <= iVar2)); iVar2 = iVar2 + -1) {
      iVar5 = iVar5 + 1;
    }
    for (; (local_4 <= iVar5 || (iVar2 < 0)); iVar2 = iVar2 + 1) {
      iVar5 = iVar5 + -1;
    }
    param_3 = (int *)0x1;
    do {
      get_tile_bounding_coords(this,iVar2,iVar5,&local_4,(int *)&param_4,&param_2,&param_1);
      if (iVar4 < (int)param_4) {
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + -1;
      }
      else if (param_1 < iVar4) {
        iVar2 = iVar2 + -1;
        iVar5 = iVar5 + 1;
      }
      else {
        param_3 = (int *)0x0;
      }
    } while (param_3 != (int *)0x0);
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    return 0;
  }
  *param_3 = iVar1 + 1;
  *param_4 = local_4 + 1;
  return 0;
}

// --------------------------------------------------

// Function: get_tile_bounding_coords
// Address: 00539030
/* protected: void __thiscall RGE_View::get_tile_bounding_coords(int,int,int &,int &,int &,int &) */

void __thiscall
RGE_View::get_tile_bounding_coords
          (RGE_View *this,int param_1,int param_2,int *param_3,int *param_4,int *param_5,
          int *param_6)
{
  byte bVar1;
  short sVar2;
  RGE_Tile *pRVar3;
  
  pRVar3 = this->map->map_row_offset[param_2];
  sVar2 = pRVar3[param_1].screen_xpos;
  bVar1 = pRVar3[param_1].tile_type;
  *param_3 = (int)sVar2;
  *param_5 = this->map->tilesizes[bVar1].width + -1 + (int)sVar2;
  *param_4 = (int)pRVar3[param_1].screen_ypos - (int)this->tile_half_hgt;
  this->tile_half_hgt = 0;
  this->tile_half_wid = 0;
  this->elev_hgt = 0;
  *param_6 = this->map->tilesizes[bVar1].height + -1 + *param_4;
  return;
}

// --------------------------------------------------

// Function: pick_objects
// Address: 005390d0
/* protected: int __thiscall RGE_View::pick_objects(int,int,int,int,int,int,int) */

int __thiscall
RGE_View::pick_objects
          (RGE_View *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
          int param_7)
{
  short sVar1;
  DClipInfo_Node *pDVar2;
  bool bVar3;
  int iVar4;
  RGE_SPick_Info *pRVar5;
  int iVar6;
  RGE_SPick_Info *pRVar7;
  RGE_SPick_Info *pRVar8;
  short *psVar9;
  RGE_SPick_Info *pRVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  RGE_SPick_Info **ppRVar14;
  int hotY;
  int l;
  int obj_id;
  int z;
  int num_picked;
  RGE_SPick_Info *head [5];
  RGE_SPick_Info *tail [5];
  RGE_SPick_Info *freep [5];
  
  head[0] = (RGE_SPick_Info *)0x0;
  if (((((param_5 < 0) || (param_4 < param_3)) || (param_1 < this->_padding_)) ||
      ((this->_padding_ < param_1 || (param_2 < this->_padding_)))) ||
     ((this->_padding_ < param_2 || ((0x28 < param_3 || (param_4 < 0)))))) {
    return 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (0x28 < param_4) {
    param_4 = 0x28;
  }
  pRVar5 = (RGE_SPick_Info *)(param_2 - this->_padding_);
  iVar12 = param_1 - this->_padding_;
  freep[2] = (RGE_SPick_Info *)0x0;
  freep[3] = (RGE_SPick_Info *)0x0;
  freep[4] = (RGE_SPick_Info *)0x0;
  tail[2] = (RGE_SPick_Info *)0x0;
  tail[3] = (RGE_SPick_Info *)0x0;
  tail[4] = (RGE_SPick_Info *)0x0;
  freep[0] = (RGE_SPick_Info *)0x0;
  head[2] = (RGE_SPick_Info *)0x0;
  head[3] = (RGE_SPick_Info *)0x0;
  head[4] = (RGE_SPick_Info *)0x0;
  tail[0] = (RGE_SPick_Info *)0x0;
  this->pick_list_size[1] = 0;
  this->pick_list_size[2] = 0;
  this->pick_list_size[3] = 0;
  this->pick_list_size[4] = 0;
  pRVar10 = pRVar5;
  do {
    if (param_4 < param_3) {
      iVar12 = 1;
      ppRVar14 = head + 2;
      do {
        pRVar10 = *ppRVar14;
        if (pRVar10 != (RGE_SPick_Info *)0x0) {
          psVar9 = &DAT_0087d4a4 + (int)head[0] * 6;
          do {
            head[0] = (RGE_SPick_Info *)((int)&head[0]->object_id + 1);
            *(int *)(psVar9 + -2) = pRVar10->object_id;
            *psVar9 = pRVar10->confidence;
            psVar9[1] = pRVar10->draw_level;
            psVar9[2] = pRVar10->draw_x;
            psVar9[3] = pRVar10->draw_y;
            psVar9 = psVar9 + 6;
            if (0x87d7a3 < (int)psVar9) {
              return 0x40;
            }
            pRVar10 = pRVar10->next;
          } while (pRVar10 != (RGE_SPick_Info *)0x0);
        }
        iVar12 = iVar12 + 1;
        ppRVar14 = ppRVar14 + 1;
      } while (iVar12 < 5);
      return (int)head[0];
    }
    for (pDVar2 = this->prior_objs->Draw_Level_Head[param_4]; pDVar2 != (DClipInfo_Node *)0x0;
        pDVar2 = pDVar2->NextOnLevel) {
      iVar13 = 0;
      if ((pDVar2->Node_Type == 0) && ((param_7 == 0 || (-1 < pDVar2->Object_ID)))) {
        iVar11 = (int)pDVar2->y1;
        iVar6 = (int)pDVar2->x2;
        if ((iVar12 < pDVar2->x1 - param_5) ||
           ((((int)pRVar5 < iVar11 - param_5 || (param_5 + iVar6 < iVar12)) ||
            (pDVar2->y2 + param_5 < (int)pRVar5)))) {
          iVar13 = 0;
        }
        else {
          iVar13 = 4;
          if (((pDVar2->x1 <= iVar12) && (iVar11 <= (int)pRVar5)) &&
             ((iVar12 <= iVar6 && ((int)pRVar5 <= (int)pDVar2->y2)))) {
            iVar13 = 3;
            if (((byte)pDVar2->Draw_Flag & 2) == 2) {
              iVar6 = iVar6 - iVar12;
            }
            else {
              iVar6 = iVar12 - pDVar2->x1;
            }
            iVar6 = sprite_check(this,pDVar2->Shape_Base,pDVar2->Shape,iVar6,(int)pRVar5 - iVar11);
            if (iVar6 == 1) {
              iVar13 = 2;
            }
            else if (iVar6 == 2) {
              iVar13 = 1;
            }
          }
        }
      }
      if ((iVar13 != 0) && (iVar13 <= param_6)) {
        sVar1 = pDVar2->y3;
        iVar6 = pDVar2->Object_ID;
        iVar11 = 1;
        bVar3 = true;
        ppRVar14 = head + 2;
        pRVar8 = (RGE_SPick_Info *)0x0;
        do {
          pRVar7 = pRVar8;
          if (pRVar8 != (RGE_SPick_Info *)0x0) goto LAB_0053931b;
          for (pRVar10 = *ppRVar14;
              (pRVar7 = pRVar8, iVar4 = num_picked, pRVar10 != (RGE_SPick_Info *)0x0 &&
              (pRVar7 = pRVar10, iVar4 = iVar11, pRVar10->object_id != iVar6));
              pRVar10 = pRVar10->next) {
          }
          num_picked = iVar4;
          iVar11 = iVar11 + 1;
          ppRVar14 = ppRVar14 + 1;
          pRVar8 = pRVar7;
        } while (iVar11 < 5);
        if (pRVar7 != (RGE_SPick_Info *)0x0) {
LAB_0053931b:
          if ((num_picked < iVar13) || ((num_picked == iVar13 && (sVar1 < pRVar7->draw_level)))) {
            bVar3 = false;
          }
          if (bVar3) {
            if (head[num_picked + 1] == pRVar7) {
              head[num_picked + 1] = pRVar7->next;
            }
            if (tail[num_picked + 1] == pRVar7) {
              tail[num_picked + 1] = pRVar7->prev;
            }
            if (pRVar7->next != (RGE_SPick_Info *)0x0) {
              pRVar7->next->prev = pRVar7->prev;
            }
            if (pRVar7->prev != (RGE_SPick_Info *)0x0) {
              pRVar7->prev->next = pRVar7->next;
            }
            pRVar7->next = freep[num_picked + 1];
            pRVar7->prev = (RGE_SPick_Info *)0x0;
            freep[num_picked + 1] = pRVar7;
          }
        }
        if (bVar3) {
          pRVar8 = freep[iVar13 + 1];
          if (pRVar8 == (RGE_SPick_Info *)0x0) {
            iVar11 = this->pick_list_size[iVar13];
            if (iVar11 == 0x40) {
              bVar3 = false;
            }
            else {
              pRVar10 = this->pick_lists[iVar13] + iVar11;
              this->pick_list_size[iVar13] = iVar11 + 1;
            }
          }
          else {
            freep[iVar13 + 1] = pRVar8->next;
            pRVar10 = pRVar8;
          }
          if (bVar3) {
            pRVar10->object_id = iVar6;
            pRVar10->confidence = (short)iVar13;
            pRVar10->draw_level = sVar1;
            pRVar10->draw_x = (short)pDVar2->Draw_X;
            ppRVar14 = head + iVar13 + 1;
            pRVar10->draw_y = (short)pDVar2->Draw_Y;
            pRVar8 = *ppRVar14;
            pRVar10->next = (RGE_SPick_Info *)0x0;
            pRVar10->prev = (RGE_SPick_Info *)0x0;
            if (pRVar8 == (RGE_SPick_Info *)0x0) {
              *ppRVar14 = pRVar10;
LAB_00539462:
              tail[iVar13 + 1] = pRVar10;
            }
            else {
              do {
                if (pRVar8->draw_level <= sVar1) {
                  pRVar10->next = pRVar8;
                  pRVar7 = pRVar8->prev;
                  pRVar10->prev = pRVar7;
                  if (pRVar7 == (RGE_SPick_Info *)0x0) {
                    *ppRVar14 = pRVar10;
                    pRVar8->prev = pRVar10;
                  }
                  else {
                    pRVar10->prev->next = pRVar10;
                    pRVar8->prev = pRVar10;
                  }
                  break;
                }
                pRVar7 = pRVar8->next;
                if (pRVar7 == (RGE_SPick_Info *)0x0) {
                  pRVar8->next = pRVar10;
                  pRVar10->prev = pRVar8;
                  goto LAB_00539462;
                }
                pRVar8 = pRVar7;
              } while (pRVar7 != (RGE_SPick_Info *)0x0);
            }
          }
        }
      }
    }
    param_4 = param_4 + -1;
  } while( true );
}

// --------------------------------------------------

// Function: sprite_check
// Address: 00539510
/* protected: int __thiscall RGE_View::sprite_check(unsigned char *,struct Shape_Info *,int,int) */

int __thiscall
RGE_View::sprite_check(RGE_View *this,uchar *param_1,Shape_Info *param_2,int param_3,int param_4)
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  if ((((param_2 != (Shape_Info *)0x0) && (-1 < param_3)) &&
      (iVar2 = param_2->Width, param_3 < iVar2)) && ((-1 < param_4 && (param_4 < param_2->Height))))
{
    iVar5 = (int)*(short *)(param_1 + param_4 * 4 + param_2->Shape_Outline_Offset);
    if ((-1 < iVar5) &&
       ((iVar5 <= param_3 &&
        (param_3 <= iVar2 - *(short *)(param_1 + param_4 * 4 + param_2->Shape_Outline_Offset + 2))))
       ) {
      pbVar3 = param_1 + *(int *)(param_1 + param_4 * 4 + param_2->Shape_Data_Offsets);
      if (iVar5 < iVar2) {
        while (iVar5 <= param_3) {
          bVar1 = *pbVar3;
          pbVar4 = pbVar3 + 1;
          param_2 = (Shape_Info *)(uint)bVar1;
          switch(bVar1 & 0xf) {
          case 0:
          case 4:
          case 8:
          case 0xc:
            iVar5 = iVar5 + (uint)(bVar1 >> 2);
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar4 + (bVar1 >> 2);
            break;
          case 1:
          case 5:
          case 9:
          case 0xd:
            iVar5 = iVar5 + (uint)(bVar1 >> 2);
            break;
          case 2:
            uVar6 = (int)param_2 << 4 | (uint)*pbVar4;
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar3 + uVar6 + 2;
            break;
          case 3:
            bVar1 = *pbVar4;
            pbVar4 = pbVar3 + 2;
            iVar5 = iVar5 + ((int)param_2 << 4 | (uint)bVar1);
            break;
          case 6:
            uVar6 = (uint)(bVar1 >> 4);
            if (uVar6 == 0) {
              uVar6 = (uint)*pbVar4;
              pbVar4 = pbVar3 + 2;
            }
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar4 + uVar6;
            break;
          case 7:
          case 10:
            uVar6 = (uint)(bVar1 >> 4);
            if (uVar6 == 0) {
              uVar6 = (uint)*pbVar4;
              pbVar4 = pbVar3 + 2;
            }
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar4 + 1;
            break;
          case 0xb:
            uVar6 = (uint)(bVar1 >> 4);
            if (uVar6 == 0) {
              uVar6 = (uint)*pbVar4;
              pbVar4 = pbVar3 + 2;
            }
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            break;
          case 0xe:
          case 0xf:
            goto switchD_005395b3_caseD_e;
          default:
            goto switchD_005395b3_default;
          }
          pbVar3 = pbVar4;
          if (iVar2 <= iVar5) {
            return 1;
          }
        }
      }
switchD_005395b3_default:
      return 1;
    }
  }
switchD_005395b3_caseD_e:
  return 0;
}

// --------------------------------------------------

// Function: pick_multi_objects
// Address: 005396f0
/* WARNING: Variable defined which should be unmapped: num_picked */
/* protected: int __thiscall RGE_View::pick_multi_objects(int,int,int,int,int,int,int,unsigned
   char,int) */

int __thiscall
RGE_View::pick_multi_objects
          (RGE_View *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
          int param_7,uchar param_8,int param_9)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  bool bVar4;
  short sVar5;
  int iVar6;
  RGE_Pick_Obj_Info **ppRVar7;
  int iVar8;
  DClipInfo_Node *pDVar9;
  short *psVar10;
  int num_picked;
  int local_c;
  int z;
  
  iVar8 = 0;
  iVar1 = this->_padding_;
  local_c = 0;
  if (((((param_3 < iVar1) || (this->_padding_ < param_1)) ||
       (iVar2 = this->_padding_, param_4 < iVar2)) ||
      ((this->_padding_ < param_2 || (0x28 < param_5)))) || (param_6 < 0)) {
    return 0;
  }
  if (param_5 < 0) {
    param_5 = 0;
  }
  iVar6 = param_6;
  if (0x28 < param_6) {
    iVar6 = 0x28;
  }
  do {
    if (iVar6 < param_5) {
      return iVar8;
    }
    pDVar9 = this->prior_objs->Draw_Level_Head[iVar6];
    if (pDVar9 != (DClipInfo_Node *)0x0) {
      psVar10 = &DAT_0087d4a4 + iVar8 * 6;
      do {
        sVar5 = 0;
        if ((pDVar9->Node_Type == 0) && (param_6 = pDVar9->Object_ID, -1 < param_6)) {
          if ((((param_1 - iVar1 <= (int)pDVar9->x2) &&
               ((((int)pDVar9->x1 <= param_3 - iVar1 && (param_2 - iVar2 <= (int)pDVar9->y2)) &&
                ((int)pDVar9->y1 <= param_4 - iVar2)))) &&
              (((pRVar3 = this->world->objectsValue[param_6], param_7 == -1 ||
                (pRVar3->owner->id == param_7)) && (pRVar3->object_state == '\x02')))) &&
             (param_8 <= pRVar3->master_obj->select_level)) {
            sVar5 = 1;
          }
        }
        if (sVar5 != 0) {
          bVar4 = true;
          if ((0x87d4a4 < (int)psVar10) && (iVar8 = 0, 0x87d4a4 < (int)psVar10)) {
            ppRVar7 = &Picked_Objects;
            do {
              if (*ppRVar7 == (RGE_Pick_Obj_Info *)param_6) {
                bVar4 = false;
                if (sVar5 < (short)(&DAT_0087d4a4)[iVar8 * 6]) {
                  (&DAT_0087d4a4)[iVar8 * 6] = sVar5;
                }
                break;
              }
              iVar8 = iVar8 + 1;
              ppRVar7 = ppRVar7 + 3;
            } while (iVar8 < local_c);
          }
          if (bVar4) {
            *(int *)(psVar10 + -2) = param_6;
            *psVar10 = sVar5;
            psVar10[1] = sVar5;
            psVar10[2] = (short)pDVar9->Draw_X;
            psVar10[3] = (short)pDVar9->Draw_Y;
            local_c = local_c + 1;
            psVar10 = psVar10 + 6;
          }
          if (0x87d7a3 < (int)psVar10) {
            return 0x40;
          }
        }
        pDVar9 = pDVar9->NextOnLevel;
        iVar8 = local_c;
      } while (pDVar9 != (DClipInfo_Node *)0x0);
    }
    iVar6 = iVar6 + -1;
  } while( true );
}

// --------------------------------------------------

// Function: pick_touched_object
// Address: 00539930
/* protected: int __thiscall RGE_View::pick_touched_object(class DClipInfo_List
   *,int,int,int,int,int &) */

int __thiscall
RGE_View::pick_touched_object
          (RGE_View *this,DClipInfo_List *param_1,int param_2,int param_3,int param_4,int param_5,
          int *param_6)
{
  DClipInfo_Node *pDVar1;
  bool bVar2;
  int iVar3;
  
  *param_6 = 0;
  if ((((param_4 <= param_5) && (this->_padding_ <= param_2)) && (param_2 <= this->_padding_)) &&
     (((this->_padding_ <= param_3 && (param_3 <= this->_padding_)) &&
      ((param_4 < 0x29 && (-1 < param_5)))))) {
    if (param_4 < 0) {
      param_4 = 0;
    }
    if (0x28 < param_5) {
      param_5 = 0x28;
    }
    bVar2 = false;
    for (; param_4 <= param_5; param_5 = param_5 + -1) {
      for (pDVar1 = param_1->Draw_Level_Head[param_5]; pDVar1 != (DClipInfo_Node *)0x0;
          pDVar1 = pDVar1->NextOnLevel) {
        if (pDVar1->Node_Type == 0) {
          if (((byte)pDVar1->Draw_Flag & 2) == 2) {
            iVar3 = sprite_check(this,pDVar1->Shape_Base,pDVar1->Shape,pDVar1->x2 - param_2,
                                 param_3 - pDVar1->y1);
            if (iVar3 == 2) {
              bVar2 = true;
              *param_6 = pDVar1->Object_ID;
            }
          }
          else {
            iVar3 = sprite_check(this,pDVar1->Shape_Base,pDVar1->Shape,param_2 - pDVar1->x1,
                                 param_3 - pDVar1->y1);
            if (iVar3 == 2) {
              bVar2 = true;
              *param_6 = pDVar1->Object_ID;
            }
          }
        }
      }
      if (bVar2) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: get_tile_picture
// Address: 00539aa0
/* protected: short __thiscall RGE_View::get_tile_picture(unsigned char,unsigned char,short,short)
    */

short __thiscall
RGE_View::get_tile_picture(RGE_View *this,uchar param_1,uchar param_2,short param_3,short param_4)
{
  byte bVar1;
  short sVar2;
  RGE_Map *pRVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  short sVar7;
  byte bVar8;
  
  pRVar3 = this->map;
  uVar4 = (uint)param_1;
  if (pRVar3->terrain_types[uVar4].shape == (TShape *)0x0) {
    return -1;
  }
  uVar5 = (uint)param_2;
  sVar2 = pRVar3->terrain_types[uVar4].tiles[uVar5].count;
  if (sVar2 == 0) {
    return -1;
  }
  sVar7 = 0;
  if (1 < sVar2) {
    bVar6 = (byte)pRVar3->terrain_types[uVar4].rows;
    bVar1 = (byte)pRVar3->terrain_types[uVar4].cols;
    _param_1 = (uint)bVar6;
    _param_2 = (uint)bVar1;
    if ((1 < bVar6) || (1 < bVar1)) {
      if (bVar6 == 0) {
        bVar6 = 0;
      }
      else {
        bVar6 = (byte)((int)param_4 % (int)_param_1);
      }
      if (bVar1 == 0) {
        bVar8 = 0;
      }
      else {
        bVar8 = (byte)((int)param_3 % (int)_param_2);
      }
      sVar7 = (ushort)bVar6 * (ushort)bVar1 + (ushort)bVar8;
    }
  }
  if (sVar2 + -1 < (int)sVar7) {
    sVar7 = 0;
  }
  return pRVar3->terrain_types[uVar4].tiles[uVar5].animations * sVar7 +
         pRVar3->terrain_types[uVar4].tiles[uVar5].shape_index;
}

// --------------------------------------------------

// Function: get_border_picture
// Address: 00539b90
/* protected: short __thiscall RGE_View::get_border_picture(unsigned char,unsigned char,unsigned
   char,short,short) */

short __thiscall
RGE_View::get_border_picture
          (RGE_View *this,uchar param_1,uchar param_2,uchar param_3,short param_4,short param_5)
{
  short sVar1;
  RGE_Map *pRVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  
  pRVar2 = this->map;
  uVar3 = (uint)param_1;
  if (pRVar2->border_types[uVar3].shape == (TShape *)0x0) {
    return -1;
  }
  uVar4 = (uint)param_2;
  uVar5 = (uint)param_3;
  sVar1 = pRVar2->border_types[uVar3].borders[uVar4 - 1][uVar5 + 0xb].count;
  if (sVar1 == 0) {
    return -1;
  }
  sVar6 = 0;
  if (1 < sVar1) {
    sVar6 = pRVar2->border_types[uVar3].border_style;
    if (((sVar6 == 0) && ((param_3 == '\v' || (param_3 == '\f')))) ||
       ((sVar6 == 1 && ((param_3 == '\x03' || (param_3 == '\x02')))))) {
      sVar6 = param_5 % sVar1;
    }
    else if (((sVar6 == 0) && ((param_3 == '\t' || (param_3 == '\n')))) ||
            ((sVar6 == 1 && ((param_3 == '\x01' || (param_3 == '\x04')))))) {
      sVar6 = param_4 % sVar1;
    }
    else {
      sVar6 = 0;
    }
  }
  if (sVar1 + -1 < (int)sVar6) {
    sVar6 = 0;
  }
  return pRVar2->border_types[uVar3].borders[uVar4 - 1][uVar5 + 0xb].animations * sVar6 +
         pRVar2->border_types[uVar3].borders[uVar4 - 1][uVar5 + 0xb].shape_index;
}

// --------------------------------------------------

// Function: get_border_edge_pictures
// Address: 00539c80
/* protected: int __thiscall RGE_View::get_border_edge_pictures(unsigned char,unsigned char,unsigned
   char,short,short,int &,int &,int &,int &) */

int __thiscall
RGE_View::get_border_edge_pictures
          (RGE_View *this,uchar param_1,uchar param_2,uchar param_3,short param_4,short param_5,
          int *param_6,int *param_7,int *param_8,int *param_9)
{
  short sVar1;
  
  *param_6 = -1;
  *param_8 = -1;
  *param_7 = -1;
  *param_9 = -1;
  if (this->map->border_types[param_1].shape != (TShape *)0x0) {
    if (param_3 != '\0') {
      if ((param_3 & 1) != 0) {
        sVar1 = get_border_picture(this,param_1,param_2,'\x01',param_4,param_5);
        *param_6 = (int)sVar1;
      }
      if ((param_3 & 2) != 0) {
        sVar1 = get_border_picture(this,param_1,param_2,'\x04',param_4,param_5);
        *param_9 = (int)sVar1;
      }
      if ((param_3 & 4) != 0) {
        sVar1 = get_border_picture(this,param_1,param_2,'\x03',param_4,param_5);
        *param_8 = (int)sVar1;
      }
      if ((param_3 & 8) != 0) {
        sVar1 = get_border_picture(this,param_1,param_2,'\x02',param_4,param_5);
        *param_7 = (int)sVar1;
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: hit_tile
// Address: 00539d90
/* protected: int __thiscall RGE_View::hit_tile(struct RGE_Tile *,short,short,short,short,struct
   tagPOINT *) */

int __thiscall
RGE_View::hit_tile(RGE_View *this,RGE_Tile *param_1,short param_2,short param_3,short param_4,
                  short param_5,tagPOINT *param_6)
{
  RGE_Map *pRVar1;
  TShape *this_00;
  uchar uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  
  uVar6 = 0;
  if (param_1 == (RGE_Tile *)0x0) {
    param_1._0_2_ = 0;
  }
  else {
    uVar6 = (byte)param_1->field_0x5 & 0x1f;
    param_1._0_2_ = (ushort)param_1->tile_type;
  }
  if ((int)param_2 <= param_6->x) {
    iVar4 = (int)(short)(ushort)param_1;
    pRVar1 = this->map;
    if (param_6->x < (int)pRVar1->tilesizes[iVar4].width + (int)param_2) {
      iVar5 = (int)param_3;
      if ((iVar5 <= param_6->y) && (param_6->y < pRVar1->tilesizes[iVar4].height + iVar5)) {
        if (((short)uVar6 < pRVar1->num_terrain) &&
           (pRVar1->terrain_types[(short)uVar6].loaded != '\0')) {
          this_00 = pRVar1->terrain_types[(short)uVar6].shape;
          sVar3 = get_tile_picture(this,(uchar)uVar6,(uchar)(ushort)param_1,param_4,param_5);
          if ((this_00 != (TShape *)0x0) && (sVar3 != -1)) {
            if (this->map->tilesizes[iVar4].height + iVar5 <= param_6->y) {
              return 0;
            }
            uVar2 = TShape::shape_check(this_00,param_6->x - (int)param_2,param_6->y - iVar5,
                                        (int)sVar3);
            if (uVar2 == '\0') {
              return 0;
            }
            return 1;
          }
        }
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: hit_object
// Address: 00539ec0
/* WARNING: Variable defined which should be unmapped: max_x */
/* protected: class RGE_Static_Object * __thiscall RGE_View::hit_object(struct RGE_Tile
   *,short,short,short,short,struct tagPOINT *,struct tagPOINT *,short *,short *,class
   RGE_Static_Object *,unsigned char) */

RGE_Static_Object * __thiscall
RGE_View::hit_object
          (RGE_View *this,RGE_Tile *param_1,short param_2,short param_3,short param_4,short param_5,
          tagPOINT *param_6,tagPOINT *param_7,short *param_8,short *param_9,
          RGE_Static_Object *param_10,uchar param_11)
{
  char cVar1;
  RGE_Static_Object *this_00;
  RGE_Object_Node *pRVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  tagPOINT *ptVar5;
  RGE_Static_Object *pRVar6;
  uchar uVar7;
  int iVar8;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  short sVar9;
  short sVar10;
  short max_x;
  RGE_Static_Object *picked_obj;
  RGE_Static_Object *local_18;
  RGE_Object_Node *temp;
  RGE_Object_Node *save_list;
  short min_x;
  short min_y;
  undefined4 local_4;
  
  local_18 = (RGE_Static_Object *)0x0;
  if (&param_1->objects != (RGE_Object_List *)0x0) {
    temp = (RGE_Object_Node *)this;
    save_list = RGE_Object_List::sort(&param_1->objects);
    ptVar5 = param_6;
    uVar4 = _param_3;
    uVar3 = _param_2;
    _min_x = save_list;
    for (; (save_list != (RGE_Object_Node *)0x0 &&
           (this_00 = save_list->node, this_00 != (RGE_Static_Object *)0x0));
        save_list = save_list->next) {
      pRVar6 = local_18;
      if ((this_00->object_state < 7) &&
         (((param_11 == '\0' || (this_00->master_obj->fog_flag != '\0')) &&
          (*(byte *)((int)&temp[0x14].node + 1) <= this_00->master_obj->select_level)))) {
        cVar1 = *(char *)&temp[0x14].node;
        sVar9 = (short)uVar3;
        sVar10 = (short)uVar4;
        if ((cVar1 == '+') || (cVar1 == ',')) {
          if (this_00->owner == (RGE_Player *)temp[0x10].node) {
            if (cVar1 != ',') goto LAB_00539fb7;
            uVar7 = RGE_Static_Object::box_hit_test
                              (this_00,sVar9,sVar10,(short)param_7->x,(short)param_7->y,
                               (short)ptVar5->x,(short)ptVar5->y);
            pRVar6 = local_18;
            if ((uVar7 != '\0') &&
               (iVar8 = RGE_Player::select_one_object((RGE_Player *)temp[0x10].node,this_00,0),
               pRVar6 = this_00, iVar8 == 0)) break;
          }
        }
        else {
LAB_00539fb7:
          uVar7 = RGE_Static_Object::hit_test
                            (this_00,sVar9,sVar10,(short)ptVar5->x,(short)ptVar5->y,5);
          pRVar6 = local_18;
          if (uVar7 != '\0') {
            if (((param_10 != (RGE_Static_Object *)0x0) && (this_00 == param_10)) &&
               (local_18 != (RGE_Static_Object *)0x0)) {
              return local_18;
            }
            if ((local_18 == (RGE_Static_Object *)0x0) ||
               (((this_00->owner == (RGE_Player *)temp[0x10].node ||
                 (local_18->owner != (RGE_Player *)temp[0x10].node)) &&
                ((local_18 == (RGE_Static_Object *)0x0 ||
                 (local_18->master_obj->select_level <= this_00->master_obj->select_level)))))) {
              local_18 = this_00;
              iVar8 = RGE_Static_Object::get_frame
                                (this_00,&min_y,(short *)&local_4,(short *)((int)&picked_obj + 2),
                                 (short *)&param_1);
              if (iVar8 == 0) {
                _min_y = 0;
                local_4 = 0;
              }
              *param_8 = this_00->screen_x_offset + min_y + sVar9;
              *param_9 = this_00->screen_y_offset + (short)local_4 + sVar10;
              pRVar6 = local_18;
            }
          }
        }
      }
      local_18 = pRVar6;
    }
    while (_min_x != (RGE_Object_Node *)0x0) {
      pRVar2 = _min_x->next;
      free(_min_x);
      _min_x = pRVar2;
    }
  }
  return local_18;
}

// --------------------------------------------------

// Function: start_scroll_view
// Address: 0053a0d0
/* WARNING: Variable defined which should be unmapped: pick_info */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall RGE_View::start_scroll_view(unsigned char,long,long,int,int) */

int __thiscall
RGE_View::start_scroll_view
          (RGE_View *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  int iVar1;
  uchar uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  RGE_Pick_Info pick_info;
  
  if (param_1 == '\x03') {
    uVar2 = pick(this,'(','\0',param_2,param_3,(RGE_Pick_Info *)&pick_info.y,
                 (RGE_Static_Object *)0x0);
    if (uVar2 != '3') {
      return 0;
    }
    lVar3 = __ftol();
    lVar4 = __ftol();
    set_selection_area(this,lVar4,lVar3,lVar4,lVar3);
  }
  else if (param_1 == '\t') {
    pick(this,'(','\0',param_2,param_3,(RGE_Pick_Info *)&pick_info.y,(RGE_Static_Object *)0x0);
    lVar3 = __ftol();
    this->real_old_map_col = lVar3;
    lVar3 = __ftol();
    iVar1 = this->_padding_;
    this->real_old_map_row = lVar3;
    iVar5 = (**(code **)(iVar1 + 0xf4))(param_2,param_3,param_2,param_3,1);
    if (iVar5 == 0) {
      return 0;
    }
    (**(code **)(iVar1 + 0x20))(1);
  }
  this->scroll_action = param_1;
  this->mouse_last_x = param_2;
  this->_padding_ = param_2;
  this->mouse_last_y = param_3;
  this->_padding_ = param_3;
  TPanel::capture_mouse((TPanel *)this);
  uVar2 = this->scroll_action;
  if ((((uVar2 == '\x01') || (uVar2 == '\x02')) || (uVar2 == '\x06')) ||
     ((uVar2 == '\a' || (uVar2 == '\b')))) {
    RGE_Base_Game::mouse_off(rge_base_game);
  }
  if (this->scroll_action == '\x02') {
    if ((param_5 == 0) && (param_4 == 0)) {
      RGE_Player::unselect_object(this->player);
    }
    (**(code **)(this->_padding_ + 0x20))(1);
  }
  if ((this->scroll_action == '\x06') || (this->scroll_action == '\b')) {
    uVar2 = pick(this,'(','\0',param_2,param_3,(RGE_Pick_Info *)&pick_info.y,
                 (RGE_Static_Object *)0x0);
    if (uVar2 == '3') {
      RGE_Player::set_view_loc
                (this->player,pick_info.y - _DAT_005776c0,(float)pick_info._8_4_ - _DAT_005776c0);
      (**(code **)(this->_padding_ + 0x20))(1);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: handle_scroll_view
// Address: 0053a290
/* WARNING: Variable defined which should be unmapped: save_view_y */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall RGE_View::handle_scroll_view(long,long) */

int __thiscall RGE_View::handle_scroll_view(RGE_View *this,long param_1,long param_2)
{
  long *plVar1;
  short *psVar2;
  RGE_Player *pRVar3;
  float fVar4;
  float fVar5;
  RGE_Static_Object *pRVar6;
  RGE_Active_Sprite_List *this_00;
  RGE_Sprite *this_01;
  bool bVar7;
  uchar uVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  float unaff_EBP;
  float unaff_retaddr;
  float save_view_y;
  long save_mouse_last_x;
  tagPOINT point;
  RGE_Pick_Info pick_info;
  int iStack_4;
  
  point.x = this->mouse_last_x;
  plVar1 = &this->mouse_last_x;
  if ((param_1 == point.x) && (param_2 == this->mouse_last_y)) {
    return 0;
  }
  pRVar3 = this->player;
  fVar4 = pRVar3->view_x;
  fVar5 = pRVar3->view_y;
  uVar8 = this->scroll_action;
  switch(uVar8) {
  case '\x02':
    *plVar1 = param_1;
    this->mouse_last_y = param_2;
    TPanel::bound_point((TPanel *)this,plVar1,&this->mouse_last_y);
    (**(code **)(this->_padding_ + 0x20))(1);
    return 0;
  case '\x06':
    iVar10 = (**(code **)(this->_padding_ + 0xbc))(param_1,param_2);
    if ((iVar10 != 0) &&
       (uVar8 = pick(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&point.y,
                     (RGE_Static_Object *)0x0), uVar8 == '3')) {
      RGE_Player::set_view_loc
                (this->player,(float)point.y - _DAT_005776c0,pick_info.x - _DAT_005776c0);
    }
    *plVar1 = param_1;
    this->mouse_last_y = param_2;
    if ((unaff_retaddr == this->player->view_x) && (unaff_EBP == this->player->view_y)) {
      return 0;
    }
    (**(code **)(iStack_4 + 0x20))(1);
    return 1;
  case '\a':
    iVar10 = param_2 - this->mouse_last_y;
    if (((param_2 != this->mouse_last_y) && (iVar10 < 100)) && (-100 < iVar10)) {
      sVar9 = __ftol();
      psVar2 = &this->player->map_y;
      *psVar2 = *psVar2 + sVar9;
      psVar2 = &this->player->map_x;
      *psVar2 = *psVar2 - sVar9;
    }
    iVar10 = param_1 - *plVar1;
    if (((param_1 != *plVar1) && (iVar10 < 100)) && (-100 < iVar10)) {
      sVar9 = __ftol();
      psVar2 = &this->player->map_y;
      *psVar2 = *psVar2 + sVar9;
      psVar2 = &this->player->map_x;
      *psVar2 = *psVar2 + sVar9;
    }
    pick_info.x = (float)this->_padding_;
    uVar11 = param_2 - (int)pick_info.x >> 0x1f;
    if (((int)((param_2 - (int)pick_info.x ^ uVar11) - uVar11) < 9) &&
       (uVar11 = param_1 - this->_padding_, uVar14 = (int)uVar11 >> 0x1f,
       (int)((uVar11 ^ uVar14) - uVar14) < 9)) {
      *plVar1 = param_1;
      this->mouse_last_y = param_2;
      (**(code **)(this->_padding_ + 0x20))(1);
      return 1;
    }
    point.y = this->_padding_;
    ClientToScreen(*(undefined4 *)(this->_padding_ + 4),&point.y);
    SetCursorPos(point.y,pick_info.x);
    this->mouse_last_y = this->_padding_;
    *plVar1 = this->_padding_;
    (**(code **)(this->_padding_ + 0x20))(1);
    return 1;
  case '\b':
    iVar10 = param_2 - this->mouse_last_y;
    if (((param_2 != this->mouse_last_y) && (iVar10 < 100)) && (-100 < iVar10)) {
      iVar10 = __ftol();
      pRVar3 = this->player;
      RGE_Player::set_view_loc(pRVar3,pRVar3->view_x - (float)iVar10,pRVar3->view_y + (float)iVar10)
      ;
    }
    iVar10 = param_1 - *plVar1;
    if (((param_1 != *plVar1) && (iVar10 < 100)) && (-100 < iVar10)) {
      iVar10 = __ftol();
      pRVar3 = this->player;
      RGE_Player::set_view_loc(pRVar3,pRVar3->view_x + (float)iVar10,pRVar3->view_y + (float)iVar10)
      ;
    }
    uVar11 = param_2 - this->_padding_;
    uVar14 = (int)uVar11 >> 0x1f;
    if (((int)((uVar11 ^ uVar14) - uVar14) < 9) &&
       (uVar11 = param_1 - this->_padding_, uVar14 = (int)uVar11 >> 0x1f,
       (int)((uVar11 ^ uVar14) - uVar14) < 9)) {
      *plVar1 = param_1;
      this->mouse_last_y = param_2;
    }
    else {
      point.y = this->_padding_;
      pick_info.x = (float)this->_padding_;
      ClientToScreen(*(undefined4 *)(this->_padding_ + 4),&point.y);
      SetCursorPos(point.y,pick_info.x);
      *plVar1 = this->_padding_;
      this->mouse_last_y = this->_padding_;
    }
    if ((fVar4 == this->player->view_x) && (fVar5 == this->player->view_y)) {
      return 0;
    }
    (**(code **)(this->_padding_ + 0x20))(1);
    return 1;
  }
  if (((uVar8 == '\x03') || (uVar8 == '\x04')) || (uVar8 == '\t')) {
    if (((((param_1 < this->_padding_ + 0x40) && (param_1 < point.x)) ||
         ((this->_padding_ + -0x40 < param_1 && (point.x < param_1)))) ||
        ((param_2 < this->_padding_ + 0x20 && (param_2 < this->mouse_last_y)))) ||
       ((this->_padding_ + -0x20 < param_2 && (this->mouse_last_y < param_2)))) {
      bVar7 = true;
    }
    else {
      bVar7 = false;
    }
  }
  else {
    bVar7 = true;
  }
  iVar10 = param_2 - this->mouse_last_y;
  if ((((iVar10 != 0) && (iVar10 < 200)) && (-200 < iVar10)) && (bVar7)) {
    RGE_Player::set_view_loc
              (pRVar3,pRVar3->view_x - (float)iVar10 * _DAT_005776c4,
               pRVar3->view_y + (float)iVar10 * _DAT_005776c4);
  }
  iVar10 = param_1 - this->mouse_last_x;
  if (((iVar10 != 0) && (iVar10 < 200)) && ((-200 < iVar10 && (bVar7)))) {
    pRVar3 = this->player;
    RGE_Player::set_view_loc
              (pRVar3,pRVar3->view_x + (float)iVar10 * _DAT_005776c4,
               pRVar3->view_y + (float)iVar10 * _DAT_005776c4);
  }
  point.x = this->mouse_last_x;
  lVar12 = this->mouse_last_y;
  this->mouse_last_x = param_1;
  this->mouse_last_y = param_2;
  if (bVar7) {
    uVar11 = param_2 - this->_padding_;
    uVar14 = (int)uVar11 >> 0x1f;
    if ((8 < (int)((uVar11 ^ uVar14) - uVar14)) ||
       (uVar11 = param_1 - this->_padding_, uVar14 = (int)uVar11 >> 0x1f,
       8 < (int)((uVar11 ^ uVar14) - uVar14))) {
      point.y = this->_padding_;
      pick_info.x = (float)this->_padding_;
      ClientToScreen(*(undefined4 *)(this->_padding_ + 4),&point.y);
      SetCursorPos(point.y,pick_info.x);
      this->mouse_last_x = this->_padding_;
      this->mouse_last_y = this->_padding_;
    }
  }
  else {
    this->_padding_ = param_1;
    this->_padding_ = param_2;
  }
  uVar8 = this->scroll_action;
  if (uVar8 == '\x03') {
    uVar8 = pick(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                 (RGE_Static_Object *)0x0);
    if ((uVar8 == '3') && (this->player != (RGE_Player *)0x0)) {
      lVar12 = __ftol();
      lVar13 = __ftol();
      set_selection_area(this,this->sel_col1,this->sel_row1,lVar13,lVar12);
    }
  }
  else if (uVar8 == '\x04') {
    if ((this->player->selected_obj != (RGE_Static_Object *)0x0) &&
       (uVar8 = pick(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,
                     (RGE_Static_Object *)0x0), uVar8 == '3')) {
      (**(code **)(this->player->selected_obj->_padding_ + 0x34))(pick_info.y,pick_info._8_4_,0);
      pRVar6 = this->player->selected_obj;
      this_00 = pRVar6->sprite_list;
      if (this_00 == (RGE_Active_Sprite_List *)0x0) {
        this_01 = pRVar6->sprite;
        if (this_01 == (RGE_Sprite *)0x0) {
          uVar8 = '\x14';
        }
        else {
          uVar8 = RGE_Sprite::get_lowest_draw_level(this_01);
        }
      }
      else {
        uVar8 = RGE_Active_Sprite_List::get_lowest_draw_level(this_00);
      }
      if (uVar8 == '\0') {
        (**(code **)(this->_padding_ + 0x20))(2);
      }
      else {
        (**(code **)(this->_padding_ + 0x20))(1);
      }
    }
  }
  else if (uVar8 == '\t') {
    iVar10 = this->_padding_;
    (**(code **)(iVar10 + 0xf4))(point.x,lVar12,param_1,param_2,2);
    (**(code **)(iVar10 + 0x20))(1);
  }
  if ((fVar4 == this->player->view_x) && (fVar5 == this->player->view_y)) {
    return 0;
  }
  (**(code **)(this->_padding_ + 0x20))(1);
  return 1;
}

// --------------------------------------------------

// Function: end_scroll_view
// Address: 0053a9c0
/* WARNING: Variable defined which should be unmapped: point */
/* public: virtual void __thiscall RGE_View::end_scroll_view(void) */

void __thiscall RGE_View::end_scroll_view(RGE_View *this)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  tagPOINT point;
  
  switch(this->scroll_action) {
  case '\x01':
  case '\x06':
  case '\a':
  case '\b':
    point.y = this->_padding_;
    iVar6 = this->_padding_;
    ClientToScreen(*(undefined4 *)(this->_padding_ + 4),&point.y);
    SetCursorPos(point.y,iVar6);
    break;
  case '\x02':
    iVar6 = this->_padding_;
    iVar2 = this->mouse_last_x;
    iVar5 = iVar2;
    if (iVar2 < iVar6) {
      iVar5 = iVar6;
      iVar6 = iVar2;
    }
    iVar2 = this->_padding_;
    iVar4 = this->mouse_last_y;
    iVar3 = iVar2;
    if (iVar4 < iVar2) {
      iVar3 = iVar4;
      iVar4 = iVar2;
    }
    pick_multi(this,'\x04',iVar6,iVar3,iVar5,iVar4);
    (**(code **)(this->_padding_ + 0x20))(1);
    break;
  case '\t':
    iVar6 = this->_padding_;
    (**(code **)(iVar6 + 0xf4))(this->_padding_,this->_padding_,this->_padding_,this->_padding_,0);
    (**(code **)(iVar6 + 0x20))(1);
  }
  uVar1 = this->scroll_action;
  if ((((uVar1 == '\x01') || (uVar1 == '\x02')) || (uVar1 == '\x06')) ||
     ((uVar1 == '\a' || (uVar1 == '\b')))) {
    RGE_Base_Game::mouse_on(rge_base_game);
  }
  TPanel::release_mouse((TPanel *)this);
  this->scroll_action = '\0';
  return;
}

// --------------------------------------------------

// Function: do_paint
// Address: 0053aaf0
/* WARNING: Variable defined which should be unmapped: pick_info */
/* public: virtual int __thiscall RGE_View::do_paint(long,long,long,long,int) */

int __thiscall
RGE_View::do_paint(RGE_View *this,long param_1,long param_2,long param_3,long param_4,int param_5)
{
  int iVar1;
  uchar uVar2;
  long lVar3;
  long lVar4;
  RGE_Pick_Info pick_info;
  
  uVar2 = pick(this,'(','\0',param_3,param_4,(RGE_Pick_Info *)&pick_info.y,(RGE_Static_Object *)0x0)
  ;
  if (uVar2 != '3') {
    return 0;
  }
  lVar3 = __ftol();
  lVar4 = __ftol();
  pick(this,'(','\0',param_1,param_2,(RGE_Pick_Info *)&pick_info.y,(RGE_Static_Object *)0x0);
  iVar1 = rge_base_game->game_mode;
  if (iVar1 == 9) {
    if ((param_5 != 0) && (rge_base_game->terrain_id != -1)) {
      (**(code **)(this->map->_padding_ + 0x10))
                (this->real_old_map_col,this->real_old_map_row,lVar3,lVar4,
                 (int)rge_base_game->brush_size,rge_base_game->terrain_id);
    }
  }
  else if (iVar1 == 10) {
    if ((param_5 != 0) && (rge_base_game->elevation_height != -1)) {
      (**(code **)(this->map->_padding_ + 0x18))
                (this->real_old_map_col,this->real_old_map_row,lVar3,lVar4,
                 (int)rge_base_game->brush_size,rge_base_game->elevation_height);
    }
  }
  else if (iVar1 == 0x13) {
    (**(code **)(this->map->_padding_ + 0x20))
              (this->real_old_map_col,this->real_old_map_row,lVar3,lVar4,0,
               rge_base_game->sub_game_mode == 1);
    (**(code **)(this->_padding_ + 0x20))(2);
  }
  this->real_old_map_row = lVar4;
  this->real_old_map_col = lVar3;
  return 1;
}

// --------------------------------------------------

// Function: reset_overlay_sprites
// Address: 0053ac40
/* public: void __thiscall RGE_View::reset_overlay_sprites(void) */

void __thiscall RGE_View::reset_overlay_sprites(RGE_View *this)
{
  Ov_Sprite_Draw_Rec *pOVar1;
  Ov_Sprite_Draw_Rec *pOVar2;
  
  pOVar2 = this->extra_sprites;
  while (pOVar2 != (Ov_Sprite_Draw_Rec *)0x0) {
    pOVar1 = pOVar2->next;
    operator_delete(pOVar2);
    pOVar2 = pOVar1;
  }
  this->extra_sprites = (Ov_Sprite_Draw_Rec *)0x0;
  return;
}

// --------------------------------------------------

// Function: reset_cyclic_overlay_sprites
// Address: 0053ac70
/* public: void __thiscall RGE_View::reset_cyclic_overlay_sprites(void) */

void __thiscall RGE_View::reset_cyclic_overlay_sprites(RGE_View *this)
{
  Ov_Sprite_Draw_Rec *pOVar1;
  Ov_Sprite_Draw_Rec *pOVar2;
  
  pOVar2 = this->extra_sprites;
  while (pOVar2 != (Ov_Sprite_Draw_Rec *)0x0) {
    if (pOVar2->displayfunction == 1) {
      if (pOVar2->prev != (Ov_Sprite_Draw_Rec *)0x0) {
        pOVar2->prev->next = pOVar2->next;
      }
      if (pOVar2->next != (Ov_Sprite_Draw_Rec *)0x0) {
        pOVar2->next->prev = pOVar2->prev;
      }
      if (pOVar2->prev == (Ov_Sprite_Draw_Rec *)0x0) {
        this->extra_sprites = pOVar2->next;
      }
      pOVar1 = pOVar2->next;
      operator_delete(pOVar2);
      pOVar2 = pOVar1;
    }
    else {
      pOVar2 = pOVar2->next;
    }
  }
  return;
}

// --------------------------------------------------

// Function: add_overlay_sprite
// Address: 0053acd0
/* public: void __thiscall RGE_View::add_overlay_sprite(class TShape *,int,int,int,int,int,unsigned
   char *,int,unsigned long) */

void __thiscall
RGE_View::add_overlay_sprite
          (RGE_View *this,TShape *param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6,uchar *param_7,int param_8,ulong param_9)
{
  Ov_Sprite_Draw_Rec *pOVar1;
  Ov_Sprite_Draw_Rec *pOVar2;
  
  pOVar2 = (Ov_Sprite_Draw_Rec *)operator_new(0x30);
  if (pOVar2 != (Ov_Sprite_Draw_Rec *)0x0) {
    pOVar1 = this->extra_sprites;
    pOVar2->prev = (Ov_Sprite_Draw_Rec *)0x0;
    pOVar2->next = pOVar1;
    if (pOVar1 != (Ov_Sprite_Draw_Rec *)0x0) {
      pOVar1->prev = pOVar2;
    }
    this->extra_sprites = pOVar2;
    pOVar2->theShape = param_1;
    pOVar2->thefacet = param_2;
    pOVar2->world_x = param_3;
    pOVar2->world_y = param_4;
    pOVar2->flags = param_5;
    pOVar2->drawLevel = param_6;
    pOVar2->colortable = param_7;
    pOVar2->displayfunction = param_8;
    pOVar2->DrawTimeInterval = param_9;
    pOVar2->LastDrawTime = 0;
  }
  return;
}

// --------------------------------------------------

// Function: Object_Was_Displayed
// Address: 0053ad50
/* public: bool __thiscall RGE_View::Object_Was_Displayed(int,bool) */

bool __thiscall RGE_View::Object_Was_Displayed(RGE_View *this,int param_1,bool param_2)
{
  DClipInfo_Node *pDVar1;
  
  pDVar1 = DClipInfo_List::LocateIDbyDrawLevel(this->prior_objs,param_1,6,0x28,0);
  if (pDVar1 == (DClipInfo_Node *)0x0) {
    return false;
  }
  if ((!param_2) && ((pDVar1->Draw_Flag & 1) != 0)) {
    return false;
  }
  return true;
}

// --------------------------------------------------

// Function: ~RGE_View
// Address: 0053db2e
void __thiscall RGE_View::~RGE_View(RGE_View *this)
{
  TShape *this_00;
  TSpan_List_Manager *pTVar1;
  DClipInfo_List *pDVar2;
  int iVar3;
  RGE_SPick_Info **ppRVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561b28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->border_line_shape;
  uStack_4 = 0;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    this->border_line_shape = (TShape *)0x0;
  }
  delete_surfaces(this);
  if (this->red_pen != (void *)0x0) {
    DeleteObject(this->red_pen);
    this->red_pen = (void *)0x0;
  }
  if (this->RenderOffsets != (void **)0x0) {
    free(this->RenderOffsets);
  }
  pTVar1 = this->Terrain_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Terrain_Fog_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = this->Master_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  if (this->Tile_Edge_Tables != (Tile_FogEdge_Table **)0x0) {
    free(this->Tile_Edge_Tables);
  }
  if (this->Black_Edge_Tables != (Tile_BlackEdge_Table **)0x0) {
    free(this->Black_Edge_Tables);
  }
  if (this->Float_Scroll_Offsets != (void **)0x0) {
    free(this->Float_Scroll_Offsets);
  }
  if (this->Blit_Queue != (Blit_Queue_Entry *)0x0) {
    free(this->Blit_Queue);
  }
  pDVar2 = this->prior_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  pDVar2 = this->futur_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  ppRVar4 = this->pick_lists;
  iVar3 = 5;
  do {
    if (*ppRVar4 != (RGE_SPick_Info *)0x0) {
      free(*ppRVar4);
    }
    ppRVar4 = ppRVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_mode(MouseSystem,0);
    TMousePointer::set_game_enable(MouseSystem,0);
  }
  if (this->DispSel_List != (DisplaySelectedObjRec *)0x0) {
    free(this->DispSel_List);
  }
  reset_overlay_sprites(this);
  TPanel::~TPanel((TPanel *)this);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

