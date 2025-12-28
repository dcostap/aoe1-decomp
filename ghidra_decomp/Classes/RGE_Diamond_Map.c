// Class: RGE_Diamond_Map
// Size:  0x16C
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
// [56] draw_selected_area
// [57] draw_objects
// [58] draw_visible_object
// [59] draw_object
// [60] draw_view_rect
//
// Member Layout:
// [0x0F4] RGE_Game_World * world
// [0x0F8] RGE_Player * player
// [0x0FC] RGE_Map * map
// [0x100] int all_visible
// [0x104] int render_all
// [0x108] long mouse_last_x
// [0x10C] long mouse_last_y
// [0x110] int repos_mouse
// [0x114] tagRECT view_rect (sz: 0x10)
// [0x124] RGE_Player * last_player
// [0x128] RGE_Map_Image_Line * map_image_lines
// [0x12C] RGE_Map_Tile_Row * map_tile_rows
// [0x130] short map_wid
// [0x132] short map_hgt
// [0x134] short map_image_start_y
// [0x136] short map_image_wid
// [0x138] short map_image_hgt
// [0x13A] short map_tile_row_cnt
// [0x13C] float map_row_step
// [0x140] float map_col_ratio
// [0x144] float map_row_ratio
// [0x148] short map_tile_draw_hgt
// [0x14A] short map_tile_draw_wid
// [0x14C] short view_col
// [0x14E] short view_row
// [0x150] RGE_View * main_view
// [0x154] int scrolling
// [0x158] uchar fog_color
// [0x15C] int draw_objects_mode
// [0x160] ulong cur_player_bit
// [0x164] int own_save_area
// [0x168] TDrawArea * save_area
// ----------------------------------------------------------------

// Function: RGE_Diamond_Map
// Address: 00436830
/* public: __thiscall RGE_Diamond_Map::RGE_Diamond_Map(void) */

RGE_Diamond_Map * __thiscall RGE_Diamond_Map::RGE_Diamond_Map(RGE_Diamond_Map *this)
{
  TPanel::TPanel((TPanel *)this);
  this->world = (RGE_Game_World *)0x0;
  this->player = (RGE_Player *)0x0;
  this->map = (RGE_Map *)0x0;
  this->repos_mouse = 0;
  this->last_player = (RGE_Player *)0x0;
  this->map_image_start_y = 0;
  this->map_image_lines = (RGE_Map_Image_Line *)0x0;
  this->map_tile_rows = (RGE_Map_Tile_Row *)0x0;
  this->map_image_wid = 0;
  this->map_image_hgt = 0;
  this->map_tile_row_cnt = 0;
  this->map_row_step = 0.0;
  this->map_tile_draw_hgt = 0;
  this->map_tile_draw_wid = 0;
  this->map_col_ratio = 0.0;
  this->map_row_ratio = 0.0;
  this->save_area = (TDrawArea *)0x0;
  this->own_save_area = 0;
  (this->view_rect).left = 0;
  (this->view_rect).top = 0;
  (this->view_rect).right = 0;
  (this->view_rect).bottom = 0;
  this->main_view = (RGE_View *)0x0;
  this->scrolling = 0;
  this->draw_objects_mode = 0;
  this->cur_player_bit = 0;
  this->_padding_ = (int)&_vftable_;
  this->view_col = -1;
  this->view_row = -1;
  this->render_all = 1;
  this->fog_color = 0xff;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00436910
/* public: virtual void * __thiscall RGE_Diamond_Map::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Diamond_Map::_vector_deleting_destructor_(RGE_Diamond_Map *this,uint param_1)
{
  ~RGE_Diamond_Map(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Diamond_Map
// Address: 00436930
/* public: virtual __thiscall RGE_Diamond_Map::~RGE_Diamond_Map(void) */

void __thiscall RGE_Diamond_Map::~RGE_Diamond_Map(RGE_Diamond_Map *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055cf18;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  delete_surfaces(this);
  if (this->map_tile_rows != (RGE_Map_Tile_Row *)0x0) {
    free(this->map_tile_rows);
    this->map_tile_rows = (RGE_Map_Tile_Row *)0x0;
  }
  if (this->map_image_lines != (RGE_Map_Image_Line *)0x0) {
    free(this->map_image_lines);
    this->map_image_lines = (RGE_Map_Image_Line *)0x0;
  }
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 004369c0
/* public: long __thiscall RGE_Diamond_Map::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,unsigned char,int,class TDrawArea *) */

long __thiscall
RGE_Diamond_Map::setup
          (RGE_Diamond_Map *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
          long param_5,long param_6,uchar param_7,int param_8,TDrawArea *param_9)
{
  this->save_area = param_9;
  this->own_save_area = 0;
  TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return 1;
}

// --------------------------------------------------

// Function: set_bitmap
// Address: 00436a10
/* WARNING: Variable defined which should be unmapped: pic_pitch */
/* public: int __thiscall RGE_Diamond_Map::set_bitmap(char *,long) */

int __thiscall RGE_Diamond_Map::set_bitmap(RGE_Diamond_Map *this,char *param_1,long param_2)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  TPicture *this_00;
  int iVar5;
  RGE_Map_Image_Line *pRVar6;
  long lVar7;
  short sVar8;
  char *pcVar9;
  char *pcVar10;
  short sVar11;
  undefined4 *unaff_FS_OFFSET;
  short pic_pitch;
  short pic_hgt;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cf3b;
  *unaff_FS_OFFSET = &local_c;
  if (this->map_image_lines != (RGE_Map_Image_Line *)0x0) {
    free(this->map_image_lines);
    this->map_image_lines = (RGE_Map_Image_Line *)0x0;
  }
  if (this->map_tile_rows != (RGE_Map_Tile_Row *)0x0) {
    free(this->map_tile_rows);
    this->map_tile_rows = (RGE_Map_Tile_Row *)0x0;
  }
  this_00 = (TPicture *)operator_new(0x20);
  local_4 = 0;
  if (this_00 == (TPicture *)0x0) {
    param_2 = 0;
  }
  else {
    param_2 = TPicture::TPicture(this_00,param_1,param_2,0,(void *)0x0,0);
  }
  local_4 = 0xffffffff;
  if (param_2 == 0) {
    iVar5 = 0;
  }
  else if (*(int *)param_2 == 0) {
    TPicture::~TPicture((TPicture *)param_2);
    operator_delete((void *)param_2);
    iVar5 = 0;
  }
  else {
    sVar1 = *(short *)(param_2 + 0x18);
    sVar2 = *(short *)(param_2 + 0x14);
    pRVar6 = (RGE_Map_Image_Line *)calloc((int)sVar1,6);
    this->map_image_lines = pRVar6;
    if (*(short *)(param_2 + 0x1c) == 1) {
      pcVar10 = *(char **)(param_2 + 8);
      lVar7 = TPicture::AlignedWidth((TPicture *)param_2);
      sVar3 = (short)lVar7;
    }
    else {
      lVar7 = TPicture::AlignedWidth((TPicture *)param_2);
      pcVar10 = (char *)(lVar7 * (sVar1 + -1) + *(int *)(param_2 + 8));
      lVar7 = TPicture::AlignedWidth((TPicture *)param_2);
      sVar3 = -(short)lVar7;
    }
    this->map_image_start_y = -1;
    this->map_image_wid = 0;
    this->map_image_hgt = 0;
    param_1 = (char *)0x0;
    if (0 < sVar1) {
      do {
        sVar8 = 0;
        pcVar9 = pcVar10;
        sVar4 = -1;
        if (0 < sVar2) {
          do {
            sVar4 = sVar8;
            if (*pcVar9 == -1) break;
            pcVar9 = pcVar9 + 1;
            sVar8 = sVar8 + 1;
            sVar4 = -1;
          } while (sVar8 < sVar2);
        }
        if (sVar4 != -1) {
          sVar11 = 0;
          for (; (sVar8 < sVar2 && (*pcVar9 == -1)); pcVar9 = pcVar9 + 1) {
            sVar11 = sVar11 + 1;
            sVar8 = sVar8 + 1;
          }
          this->map_image_lines[this->map_image_hgt].start_x = sVar4;
          this->map_image_lines[this->map_image_hgt].line_len = sVar11;
          this->map_image_hgt = this->map_image_hgt + 1;
          if (this->map_image_wid < sVar11) {
            this->map_image_wid = sVar11;
          }
          if (this->map_image_start_y == -1) {
            this->map_image_start_y = (short)param_1;
          }
        }
        pcVar10 = pcVar10 + sVar3;
        param_1 = param_1 + 1;
      } while ((short)param_1 < sVar1);
    }
    TPicture::~TPicture((TPicture *)param_2);
    operator_delete((void *)param_2);
    if (this->world != (RGE_Game_World *)0x0) {
      set_world(this,this->world);
    }
    iVar5 = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return iVar5;
}

// --------------------------------------------------

// Function: set_world
// Address: 00436c30
/* WARNING: Variable defined which should be unmapped: tot_draw_wid */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Diamond_Map::set_world(class RGE_Game_World *) */

void __thiscall RGE_Diamond_Map::set_world(RGE_Diamond_Map *this,RGE_Game_World *param_1)
{
  RGE_Map *pRVar1;
  RGE_Map_Image_Line *pRVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  RGE_Map_Tile_Row *pRVar7;
  short sVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  short tot_draw_wid;
  short sStack_10;
  float col_step;
  
  this->world = param_1;
  if ((param_1 != (RGE_Game_World *)0x0) && (this->map_image_lines != (RGE_Map_Image_Line *)0x0)) {
    pRVar1 = param_1->map;
    this->map = pRVar1;
    this->map_wid = (short)pRVar1->map_width;
    sVar6 = (short)this->map->map_height;
    this->map_hgt = sVar6;
    this->map_tile_row_cnt = this->map_wid + sVar6 + -1;
    if (this->map_tile_rows != (RGE_Map_Tile_Row *)0x0) {
      free(this->map_tile_rows);
    }
    pRVar7 = (RGE_Map_Tile_Row *)calloc((int)this->map_tile_row_cnt,0x24);
    this->map_tile_rows = pRVar7;
    this->map_row_step = (float)(int)this->map_tile_row_cnt / (float)(int)this->map_image_hgt;
    sVar6 = 0;
    sStack_10 = 0;
    param_1 = (RGE_Game_World *)0x0;
    if (0 < this->map_image_hgt) {
      do {
        pRVar2 = this->map_image_lines;
        sVar5 = pRVar2[(short)param_1].line_len;
        sVar4 = __ftol();
        if (this->map_tile_row_cnt <= sVar4) {
          sVar4 = this->map_tile_row_cnt + -1;
        }
        pRVar2[(short)param_1].tile_row = sVar4;
        if (sVar4 < this->map_wid) {
          sVar8 = this->map_hgt;
          if (sVar4 < sVar8) {
            sVar8 = sVar4 + 1;
          }
        }
        else {
          sVar8 = (this->map_hgt - sVar4) + -1 + this->map_wid;
        }
        fVar9 = (float10)(int)sVar8;
        fVar10 = fVar9 / (float10)(int)sVar5;
        sStack_10 = __ftol();
        if ((float10)(int)sStack_10 != extraout_ST0) {
          sStack_10 = sStack_10 + 1;
        }
        this->map_tile_rows[sVar4].image_line = (short)param_1;
        this->map_tile_rows[sVar4].draw = '\x01';
        this->map_tile_rows[sVar4].row_len = sVar8;
        this->map_tile_rows[sVar4].col_step = (float)fVar9;
        this->map_tile_rows[sVar4].draw_wid = sStack_10;
        this->map_tile_rows[sVar4].draw_step = (float)extraout_ST0;
        fVar9 = extraout_ST1;
        sVar5 = __ftol();
        this->map_tile_rows[sVar4].num_tiles = sVar5;
        this->map_tile_rows[sVar4].ratio = (float)(extraout_ST1_00 / fVar9);
        fVar3 = (float)DAT_0056f5fc;
        if (this->map_tile_rows[sVar4].ratio < _DAT_0056f604) {
          fVar3 = (float)fVar10 * ram0x0056f600;
        }
        this->map_tile_rows[sVar4].col_extra = fVar3;
        if (sVar4 < this->map_wid) {
          this->map_tile_rows[sVar4].map_row = 0;
          this->map_tile_rows[sVar4].map_col = (this->map_wid - sVar4) + -1;
        }
        else {
          this->map_tile_rows[sVar4].map_row = (sVar4 - this->map_wid) + 1;
          this->map_tile_rows[sVar4].map_col = 0;
        }
        sStack_10 = sVar6 + sStack_10;
        param_1 = (RGE_Game_World *)((int)&param_1->_padding_ + 1);
        sVar6 = sStack_10;
      } while ((short)param_1 < this->map_image_hgt);
    }
    sVar6 = __ftol();
    this->map_tile_draw_hgt = sVar6;
    if ((float10)(int)sVar6 != extraout_ST0_00) {
      this->map_tile_draw_hgt = sVar6 + 1;
    }
    sStack_10 = sStack_10 / this->map_image_hgt;
    this->map_tile_draw_wid = sStack_10;
    if (sStack_10 == 0) {
      this->map_tile_draw_wid = 1;
    }
    sVar4 = 0;
    fVar9 = (float10)(int)this->map_image_hgt;
    this->map_col_ratio = (float)(extraout_ST1_01 / fVar9);
    this->map_row_ratio = (float)(fVar9 / (float10)(int)this->map_tile_row_cnt);
    sVar6 = 0;
    if (0 < this->map_tile_row_cnt) {
      do {
        pRVar7 = this->map_tile_rows;
        sVar5 = sVar4;
        if (pRVar7[sVar4].draw == '\0') {
          pRVar7[sVar4].image_line = pRVar7[sVar6].image_line;
          this->map_tile_rows[sVar4].row_len = this->map_tile_rows[sVar6].row_len;
          this->map_tile_rows[sVar4].col_step = this->map_tile_rows[sVar6].col_step;
          this->map_tile_rows[sVar4].draw_wid = this->map_tile_rows[sVar6].draw_wid;
          this->map_tile_rows[sVar4].draw_step = this->map_tile_rows[sVar6].draw_step;
          this->map_tile_rows[sVar4].num_tiles = this->map_tile_rows[sVar6].num_tiles;
          this->map_tile_rows[sVar4].ratio = this->map_tile_rows[sVar6].ratio;
          this->map_tile_rows[sVar4].col_extra = this->map_tile_rows[sVar6].col_extra;
          sVar5 = sVar6;
        }
        sVar4 = sVar4 + 1;
        sVar6 = sVar5;
      } while (sVar4 < this->map_tile_row_cnt);
    }
    this->view_col = -1;
    this->view_row = -1;
    (**(code **)(this->_padding_ + 0x20))(2);
    return;
  }
  this->map = (RGE_Map *)0x0;
  return;
}

// --------------------------------------------------

// Function: set_player
// Address: 00437070
/* public: void __thiscall RGE_Diamond_Map::set_player(class RGE_Player *) */

void __thiscall RGE_Diamond_Map::set_player(RGE_Diamond_Map *this,RGE_Player *param_1)
{
  this->player = param_1;
  (**(code **)(this->_padding_ + 0x20))(2);
  return;
}

// --------------------------------------------------

// Function: set_redraw
// Address: 00437090
/* public: virtual void __thiscall RGE_Diamond_Map::set_redraw(enum TPanel::RedrawMode) */

void __thiscall RGE_Diamond_Map::set_redraw(RGE_Diamond_Map *this,RedrawMode param_1)
{
  TPanel::set_redraw((TPanel *)this,param_1);
  if (param_1 == RedrawFull) {
    this->render_all = 1;
  }
  return;
}

// --------------------------------------------------

// Function: delete_surfaces
// Address: 004370c0
/* public: void __thiscall RGE_Diamond_Map::delete_surfaces(void) */

void __thiscall RGE_Diamond_Map::delete_surfaces(RGE_Diamond_Map *this)
{
  TDrawArea *this_00;
  
  this_00 = this->save_area;
  if ((this_00 != (TDrawArea *)0x0) && (this->own_save_area != 0)) {
    if (this_00 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(this_00);
      operator_delete(this_00);
    }
    this->save_area = (TDrawArea *)0x0;
    this->own_save_area = 0;
  }
  return;
}

// --------------------------------------------------

// Function: create_surfaces
// Address: 00437120
// [HELPER] s_Diamond_map__restored_: "Diamond map (restored)"
/* public: int __thiscall RGE_Diamond_Map::create_surfaces(void) */

int __thiscall RGE_Diamond_Map::create_surfaces(RGE_Diamond_Map *this)
{
  TDrawArea *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055cf5b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (this->save_area == (TDrawArea *)0x0) {
    pTVar1 = (TDrawArea *)operator_new(0x100);
    local_4 = 0;
    if (pTVar1 == (TDrawArea *)0x0) {
      pTVar1 = (TDrawArea *)0x0;
    }
    else {
      pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_Diamond_map__restored_,0);
    }
    local_4 = 0xffffffff;
    this->save_area = pTVar1;
    if (pTVar1 == (TDrawArea *)0x0) {
      *unaff_FS_OFFSET = local_c;
      return 0;
    }
    iVar2 = TDrawArea::Init(pTVar1,*(TDrawSystem **)this->_padding_,this->_padding_,this->_padding_,
                            0,0);
    if (iVar2 == 0) {
      pTVar1 = this->save_area;
      if (pTVar1 != (TDrawArea *)0x0) {
        TDrawArea::~TDrawArea(pTVar1);
        operator_delete(pTVar1);
      }
      this->save_area = (TDrawArea *)0x0;
      *unaff_FS_OFFSET = local_c;
      return 0;
    }
    this->own_save_area = 1;
  }
  else if (this->own_save_area != 0) {
    TDrawArea::SetSize(this->save_area,this->_padding_,this->_padding_,0);
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: draw
// Address: 004372c0
// [HELPER] s_diam_map__draw: "diam_map::draw"
/* public: virtual void __thiscall RGE_Diamond_Map::draw(void) */

void __thiscall RGE_Diamond_Map::draw(RGE_Diamond_Map *this)
{
  int iVar1;
  uchar *puVar2;
  
  if ((((this->_padding_ == 0) || (this->save_area == (TDrawArea *)0x0)) || (this->_padding_ == 0))
     || (this->_padding_ == 0)) {
    this->_padding_ = 0;
    return;
  }
  if (((this->map != (RGE_Map *)0x0) && (this->player != (RGE_Player *)0x0)) &&
     ((this->map_image_lines != (RGE_Map_Image_Line *)0x0 &&
      (this->map_tile_rows != (RGE_Map_Tile_Row *)0x0)))) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    this->cur_player_bit = 1 << ((byte)this->world->curr_player & 0x1f);
    if (this->render_all == 0) {
      draw_explored_tiles(this);
    }
    else {
      if ((int *)this->_padding_ == (int *)0x0) {
        TDrawArea::Clear(this->save_area,(tagRECT *)0x0,(uint)*(byte *)((int)&this->_padding_ + 3));
      }
      else {
        (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
        TDrawArea::Copy((TDrawArea *)this->_padding_,this->save_area,0,0,(tagRECT *)&this->_padding_
                        ,0);
        clear_image(this);
      }
      draw_all_tiles(this);
      this->render_all = 0;
    }
    copy_image(this);
    if (rge_base_game->game_mode != 0x15) {
      (**(code **)(iVar1 + 0xe0))();
    }
    (**(code **)(iVar1 + 0xe4))();
    puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_diam_map__draw,1);
    if (puVar2 != (uchar *)0x0) {
      (**(code **)(iVar1 + 0xf0))();
      TDrawArea::Unlock((TDrawArea *)this->_padding_,s_diam_map__draw);
    }
    (**(code **)(iVar1 + 0x2c))();
    RGE_Tile_List::del_list(&this->player->diam_tile_list);
    return;
  }
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0x28))(0);
  if (this->map_image_lines != (RGE_Map_Image_Line *)0x0) {
    clear_image(this);
    copy_image(this);
    (**(code **)(iVar1 + 0x2c))();
    return;
  }
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
    (**(code **)(iVar1 + 0x2c))();
    return;
  }
  TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,
                   (uint)*(byte *)((int)&this->_padding_ + 3));
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: clear_image
// Address: 004374c0
// [HELPER] s_diam_map__clear_image: "diam_map::clear_image"
/* protected: void __thiscall RGE_Diamond_Map::clear_image(void) */

void __thiscall RGE_Diamond_Map::clear_image(RGE_Diamond_Map *this)
{
  TDrawArea *pTVar1;
  short sVar2;
  short sVar3;
  uchar *puVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short *psVar9;
  int local_8;
  
  puVar4 = TDrawArea::Lock(this->save_area,s_diam_map__clear_image,1);
  if (puVar4 != (uchar *)0x0) {
    pTVar1 = this->save_area;
    sVar6 = this->map_image_start_y;
    if (pTVar1->Orien == 1) {
      sVar2 = (short)pTVar1->Pitch;
      puVar4 = pTVar1->Bits + (int)sVar6 * pTVar1->Pitch;
    }
    else {
      puVar4 = pTVar1->Bits + ((pTVar1->Height - (int)sVar6) + -1) * pTVar1->Pitch;
      sVar2 = -(short)pTVar1->Pitch;
    }
    sVar6 = (short)this->_padding_ + sVar6;
    sVar8 = this->map_image_hgt + sVar6;
    if (sVar6 < sVar8) {
      psVar9 = &this->map_image_lines->line_len;
      iVar5 = (int)sVar6;
      local_8 = sVar8 - iVar5;
      do {
        if ((this->_padding_ <= iVar5) && (iVar5 <= this->_padding_)) {
          sVar6 = psVar9[-1];
          sVar3 = (short)this->_padding_ + sVar6;
          sVar7 = sVar3 + *psVar9 + -1;
          sVar8 = sVar3;
          if ((int)sVar3 < this->_padding_) {
            sVar8 = (short)this->_padding_;
            sVar6 = sVar6 + (sVar8 - sVar3);
          }
          if (this->_padding_ < (int)sVar7) {
            sVar7 = (short)this->_padding_;
          }
          if ((this->_padding_ <= (int)sVar8) && ((int)sVar7 <= this->_padding_)) {
            memset(puVar4 + sVar6,*(undefined1 *)((int)&this->_padding_ + 3),
                   ((int)sVar7 - (int)sVar8) + 1);
          }
        }
        psVar9 = psVar9 + 3;
        puVar4 = puVar4 + sVar2;
        iVar5 = iVar5 + 1;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
    TDrawArea::Unlock(this->save_area,s_diam_map__clear_image);
  }
  return;
}

// --------------------------------------------------

// Function: copy_image
// Address: 00437620
/* WARNING: Variable defined which should be unmapped: r */
/* protected: void __thiscall RGE_Diamond_Map::copy_image(void) */

void __thiscall RGE_Diamond_Map::copy_image(RGE_Diamond_Map *this)
{
  tagRECT r;
  
  r.bottom = this->_padding_ + -1;
  r.top = 0;
  r.right = 0;
  r.left = 0;
  TDrawArea::Copy(this->save_area,(TDrawArea *)this->_padding_,this->_padding_,this->_padding_,
                  (tagRECT *)&r.top,0);
  return;
}

// --------------------------------------------------

// Function: draw_all_tiles
// Address: 00437660
// [HELPER] s_diam_map__draw_all_tiles: "diam_map::draw_all_tiles"
/* protected: void __thiscall RGE_Diamond_Map::draw_all_tiles(void) */

void __thiscall RGE_Diamond_Map::draw_all_tiles(RGE_Diamond_Map *this)
{
  uchar *puVar1;
  short sVar2;
  short sVar3;
  
  puVar1 = TDrawArea::Lock(this->save_area,s_diam_map__draw_all_tiles,1);
  if (puVar1 != (uchar *)0x0) {
    sVar2 = 0;
    if (0 < this->map_hgt) {
      do {
        sVar3 = 0;
        if (0 < this->map_wid) {
          do {
            draw_tile(this,sVar3,sVar2,0,'\0');
            sVar3 = sVar3 + 1;
          } while (sVar3 < this->map_wid);
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < this->map_hgt);
    }
    TDrawArea::Unlock(this->save_area,s_diam_map__draw_all_tiles);
  }
  return;
}

// --------------------------------------------------

// Function: draw_explored_tiles
// Address: 004376d0
// [HELPER] s_diam_map__draw_explored_tiles: "diam_map::draw_explored_tiles"
/* WARNING: Variable defined which should be unmapped: list */
/* protected: void __thiscall RGE_Diamond_Map::draw_explored_tiles(void) */

void __thiscall RGE_Diamond_Map::draw_explored_tiles(RGE_Diamond_Map *this)
{
  uchar *puVar1;
  int iVar2;
  RGE_Tile_List_Node *list;
  int list_size;
  int local_4;
  
  RGE_Tile_List::get_list_info
            (&this->player->diam_tile_list,(RGE_Tile_List_Node **)&list_size,&local_4);
  if ((0 < local_4) &&
     (puVar1 = TDrawArea::Lock(this->save_area,s_diam_map__draw_explored_tiles,1),
     puVar1 != (uchar *)0x0)) {
    iVar2 = 0;
    if (0 < local_4) {
      do {
        draw_tile(this,*(short *)list_size,*(short *)(list_size + 4),0,'\0');
        iVar2 = iVar2 + 1;
        list_size = list_size + 8;
      } while (iVar2 < local_4);
    }
    TDrawArea::Unlock(this->save_area,s_diam_map__draw_explored_tiles);
  }
  return;
}

// --------------------------------------------------

// Function: draw_tile
// Address: 00437760
/* WARNING: Variable defined which should be unmapped: color */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: void __thiscall RGE_Diamond_Map::draw_tile(short,short,int,unsigned char) */

void __thiscall
RGE_Diamond_Map::draw_tile
          (RGE_Diamond_Map *this,short param_1,short param_2,int param_3,uchar param_4)
{
  RGE_Map_Tile_Row *pRVar1;
  byte bVar2;
  RGE_Map *pRVar3;
  RGE_Tile **ppRVar4;
  RGE_Tile *pRVar5;
  bool bVar6;
  short sVar7;
  RGE_Object_Node *pRVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float10 extraout_ST0;
  uchar uVar14;
  uchar color;
  long y;
  RGE_Map_Tile_Row *tile_row;
  uchar terrain;
  long x;
  
  iVar11 = (int)param_2;
  iVar12 = (int)param_1;
  y = 0;
  pRVar1 = this->map_tile_rows + ((iVar11 + this->map_wid) - iVar12) + -1;
  if (pRVar1->draw == '\0') {
    return;
  }
  pRVar3 = this->map;
  ppRVar4 = pRVar3->map_row_offset;
  pRVar5 = ppRVar4[iVar11];
  if ((pRVar3->map_visible_flag == '\0') &&
     ((this->player->mutualExploredMask & (uint)(&unified_map_offsets)[iVar11][iVar12]) == 0)) {
    return;
  }
  bVar6 = false;
  if (_DAT_0056f604 <= pRVar1->ratio) {
    sVar7 = __ftol();
LAB_00437856:
    bVar6 = true;
  }
  else {
    sVar7 = __ftol();
    if (extraout_ST0 - (float10)(int)sVar7 < (float10)pRVar1->ratio) goto LAB_00437856;
  }
  if (!bVar6) {
    return;
  }
  iVar13 = (int)this->map_image_lines[pRVar1->image_line].start_x + (int)sVar7;
  iVar9 = (int)this->map_image_start_y + (int)pRVar1->image_line;
  bVar2 = pRVar5[iVar12].field_0x5;
  if (param_3 != 0) {
    iVar9 = iVar9 + this->_padding_;
    sVar7 = pRVar1->draw_wid;
    iVar13 = iVar13 + this->_padding_;
    if (this->map_tile_draw_hgt != 1) {
      sVar10 = 0;
      if (this->map_tile_draw_hgt < 1) {
        return;
      }
      do {
        if (0 < sVar7) {
          iVar12 = (int)sVar7;
          iVar11 = iVar13;
          do {
            TDrawArea::SetPixel((TDrawArea *)this->_padding_,iVar11,iVar9 + sVar10,this->fog_color);
            iVar11 = iVar11 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        sVar10 = sVar10 + 1;
      } while (sVar10 < this->map_tile_draw_hgt);
      return;
    }
    if (sVar7 == 1) {
      TDrawArea::SetPixel((TDrawArea *)this->_padding_,iVar13,iVar9,this->fog_color);
      return;
    }
    if (sVar7 == 2) {
      TDrawArea::SetPixel((TDrawArea *)this->_padding_,iVar13,iVar9,this->fog_color);
      TDrawArea::SetPixel((TDrawArea *)this->_padding_,iVar13 + 1,iVar9,this->fog_color);
      return;
    }
    if (sVar7 < 1) {
      return;
    }
    iVar11 = (int)sVar7;
    do {
      TDrawArea::SetPixel((TDrawArea *)this->_padding_,iVar13,iVar9,this->fog_color);
      iVar13 = iVar13 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    return;
  }
  if (param_4 == '\0') {
    switch(pRVar5[iVar12].tile_type) {
    case '\0':
      y = (long)pRVar3->terrain_types[bVar2 & 0x1f].map_med_color;
      break;
    case '\x01':
    case '\x04':
    case '\x05':
    case '\a':
    case '\b':
    case '\t':
    case '\f':
    case '\r':
    case '\x0f':
      y = (long)pRVar3->terrain_types[bVar2 & 0x1f].map_low_color;
      break;
    case '\x02':
    case '\x03':
    case '\x06':
    case '\n':
    case '\v':
    case '\x0e':
    case '\x10':
      param_4 = pRVar3->terrain_types[bVar2 & 0x1f].map_hi_color;
      goto LAB_00437920;
    }
  }
  else {
LAB_00437920:
    y = (long)param_4;
  }
  sVar7 = param_2 + -1;
  do {
    if (iVar11 + 2 <= (int)sVar7) {
      sVar7 = pRVar1->draw_wid;
      uVar14 = (uchar)y;
      if (this->map_tile_draw_hgt == 1) {
        if (sVar7 == 1) {
          TDrawArea::SetPixel(this->save_area,iVar13,iVar9,uVar14);
          return;
        }
        if (sVar7 == 2) {
          TDrawArea::SetPixel(this->save_area,iVar13,iVar9,uVar14);
          TDrawArea::SetPixel(this->save_area,iVar13 + 1,iVar9,uVar14);
          return;
        }
        if (0 < sVar7) {
          iVar11 = (int)sVar7;
          do {
            TDrawArea::SetPixel(this->save_area,iVar13,iVar9,uVar14);
            iVar13 = iVar13 + 1;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          return;
        }
      }
      else {
        sVar10 = 0;
        if (0 < this->map_tile_draw_hgt) {
          do {
            if (0 < sVar7) {
              iVar12 = (int)sVar7;
              iVar11 = iVar13;
              do {
                TDrawArea::SetPixel(this->save_area,iVar11,iVar9 + sVar10,uVar14);
                iVar11 = iVar11 + 1;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
            sVar10 = sVar10 + 1;
          } while (sVar10 < this->map_tile_draw_hgt);
          return;
        }
      }
      return;
    }
    if ((-1 < sVar7) && (sVar7 < this->map_hgt)) {
      sVar10 = param_1 + -1;
      while ((int)sVar10 < iVar12 + 2) {
        if (((sVar10 < 0) || (this->map_wid <= sVar10)) ||
           (pRVar8 = ppRVar4[sVar7][sVar10].objects.list, pRVar8 == (RGE_Object_Node *)0x0)) {
LAB_004379bb:
          sVar10 = sVar10 + 1;
        }
        else {
          do {
            if (pRVar8->node->master_obj->map_draw_level == '\x04') {
              y = (long)pRVar8->node->master_obj->map_color;
              goto LAB_004379bb;
            }
            pRVar8 = pRVar8->next;
          } while (pRVar8 != (RGE_Object_Node *)0x0);
          sVar10 = sVar10 + 1;
        }
      }
    }
    sVar7 = sVar7 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: draw_selected_area
// Address: 00437c20
// [HELPER] s_diam_map__draw_selected_area: "diam_map::draw_selected_area"
/* WARNING: Variable defined which should be unmapped: sel_col2 */
/* protected: virtual void __thiscall RGE_Diamond_Map::draw_selected_area(void) */

void __thiscall RGE_Diamond_Map::draw_selected_area(RGE_Diamond_Map *this)
{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long sel_col2;
  long sel_col1;
  long sel_row2;
  long sel_row1;
  int local_4;
  
  if (((this->main_view != (RGE_View *)0x0) &&
      (iVar1 = RGE_View::get_selection_area
                         (this->main_view,&sel_row2,&local_4,&sel_col1,&sel_row1,1), iVar1 != 0)) &&
     (puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_diam_map__draw_selected_area,1),
     puVar2 != (uchar *)0x0)) {
    iVar1 = sel_col1;
    iVar3 = sel_row2;
    iVar5 = local_4;
    if (local_4 <= sel_row1) {
      do {
        iVar4 = iVar3;
        if (iVar3 <= iVar1) {
          do {
            draw_tile(this,(short)iVar3,(short)iVar5,1,'\0');
            iVar3 = iVar3 + 1;
            iVar1 = sel_col1;
            iVar4 = sel_row2;
          } while (iVar3 <= sel_col1);
        }
        iVar5 = iVar5 + 1;
        iVar3 = iVar4;
      } while (iVar5 <= sel_row1);
    }
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_diam_map__draw_selected_area);
  }
  return;
}

// --------------------------------------------------

// Function: draw_objects
// Address: 00437cc0
// [HELPER] s_diam_map__draw_objects: "diam_map::draw_objects"
/* WARNING: Variable defined which should be unmapped: color2 */
/* protected: virtual void __thiscall RGE_Diamond_Map::draw_objects(void) */

void __thiscall RGE_Diamond_Map::draw_objects(RGE_Diamond_Map *this)
{
  uchar uVar1;
  RGE_Object_Node *pRVar2;
  RGE_Player *pRVar3;
  RGE_Static_Object *pRVar4;
  char cVar5;
  uchar *puVar6;
  RGE_Game_World *pRVar7;
  short sVar8;
  short sVar9;
  uchar color2;
  uchar color1;
  short i;
  
  puVar6 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_diam_map__draw_objects,1);
  if (puVar6 != (uchar *)0x0) {
    this->draw_objects_mode = 1;
    for (pRVar2 = (*this->world->players)->objects->list; pRVar2 != (RGE_Object_Node *)0x0;
        pRVar2 = pRVar2->next) {
      if (pRVar2->node != (RGE_Static_Object *)0x0) {
        (**(code **)(this->_padding_ + 0xe8))(pRVar2->node,0xff,0xff);
      }
    }
    pRVar7 = this->world;
    this->draw_objects_mode = 2;
    sVar8 = 1;
    if (1 < pRVar7->player_num) {
      do {
        pRVar3 = pRVar7->players[sVar8];
        uVar1 = pRVar3->color_table->map_color;
        for (pRVar2 = pRVar3->doppleganger_objects->list; pRVar2 != (RGE_Object_Node *)0x0;
            pRVar2 = pRVar2->next) {
          if (pRVar2->node != (RGE_Static_Object *)0x0) {
            (**(code **)(this->_padding_ + 0xe8))(pRVar2->node,uVar1,uVar1);
          }
        }
        for (pRVar2 = pRVar3->objects->list; pRVar2 != (RGE_Object_Node *)0x0; pRVar2 = pRVar2->next
            ) {
          pRVar4 = pRVar2->node;
          if (((pRVar4 != (RGE_Static_Object *)0x0) && ((pRVar4->selected & 1) == 0)) &&
             ((pRVar4->owner != this->player ||
              (cVar5 = (**(code **)(pRVar4->_padding_ + 0xe8))(), cVar5 == '\0')))) {
            (**(code **)(this->_padding_ + 0xe8))(pRVar4,uVar1,uVar1);
          }
        }
        pRVar7 = this->world;
        sVar8 = sVar8 + 1;
      } while (sVar8 < pRVar7->player_num);
    }
    if (0 < this->player->sel_count) {
      sVar9 = 0;
      this->draw_objects_mode = 3;
      sVar8 = 0;
      do {
        if (this->player->sel_count <= sVar8) break;
        pRVar4 = this->player->sel_list[sVar9];
        if (pRVar4 != (RGE_Static_Object *)0x0) {
          (**(code **)(this->_padding_ + 0xe8))(pRVar4,0xff,0xff);
          sVar8 = sVar8 + 1;
        }
        sVar9 = sVar9 + 1;
      } while (sVar9 < 0x19);
    }
    this->draw_objects_mode = 4;
    uVar1 = this->player->color_table->map_color;
    for (pRVar2 = this->player->objects->list; pRVar2 != (RGE_Object_Node *)0x0;
        pRVar2 = pRVar2->next) {
      pRVar4 = pRVar2->node;
      if ((pRVar4 != (RGE_Static_Object *)0x0) &&
         (cVar5 = (**(code **)(pRVar4->_padding_ + 0xe8))(), cVar5 != '\0')) {
        (**(code **)(this->_padding_ + 0xe8))(pRVar4,uVar1,uVar1);
      }
    }
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_diam_map__draw_objects);
  }
  return;
}

// --------------------------------------------------

// Function: draw_visible_object
// Address: 00437ec0
/* WARNING: Variable defined which should be unmapped: row */
/* protected: virtual void __thiscall RGE_Diamond_Map::draw_visible_object(class RGE_Static_Object
   *,unsigned char,unsigned char) */

void __thiscall
RGE_Diamond_Map::draw_visible_object
          (RGE_Diamond_Map *this,RGE_Static_Object *param_1,uchar param_2,uchar param_3)
{
  RGE_Player *pRVar1;
  RGE_Map *pRVar2;
  RGE_Static_Object *pRVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  uchar uVar8;
  undefined4 uVar9;
  short row;
  
  pRVar3 = param_1;
  if (param_1->tile == (RGE_Tile *)0x0) {
    return;
  }
  uVar4 = __ftol();
  uVar5 = __ftol();
  pRVar1 = this->player;
  if (pRVar1->visible == (RGE_Visible_Map *)0x0) {
LAB_00437f58:
    cVar7 = '\x0f';
  }
  else {
    pRVar2 = this->map;
    if ((pRVar2->map_visible_flag != '\0') && (pRVar2->fog_flag == '\0')) goto LAB_00437f58;
    param_1._0_2_ = (short)uVar4;
    cVar7 = '\0';
    if ((pRVar1->mutualExploredMask & (uint)(&unified_map_offsets)[(short)uVar5][(short)param_1]) !=
        0) {
      cVar7 = -0x80;
    }
    if ((pRVar1->mutualVisibleMask & (uint)(&unified_map_offsets)[(short)uVar5][(short)param_1]) !=
        0) {
      cVar7 = '\x0f';
    }
    if ((pRVar2->map_visible_flag != '\0') && (cVar7 == '\0')) {
      cVar7 = -0x80;
    }
    if ((pRVar2->fog_flag == '\0') && (cVar7 == -0x80)) goto LAB_00437f58;
  }
  if ((cVar7 == '\x0f') || ((cVar7 == -0x80 && (pRVar3->master_obj->fog_flag != '\0')))) {
    if (pRVar3->type == '\x19') {
      if (cVar7 == '\x0f') {
        return;
      }
      if ((pRVar1->mutualAlly[pRVar3->owner->id] == 1) &&
         ((this->cur_player_bit & (uint)pRVar3[1].tile) == 0)) {
        uVar8 = *(uchar *)&pRVar3[1].inside_obj;
        param_2 = *(uchar *)((int)&pRVar3[1].inside_obj + 1);
        param_3 = param_2;
      }
      else {
        param_2 = 0xff;
        uVar8 = '\0';
        param_3 = 0xff;
      }
    }
    else {
      uVar8 = pRVar3->master_obj->map_draw_level;
      if (uVar8 == '\x03') {
        param_2 = pRVar3->master_obj->map_color;
      }
    }
    switch(uVar8) {
    default:
      goto switchD_00437ffe_caseD_0;
    case '\x01':
      iVar6 = this->_padding_;
      uVar9 = 1;
      break;
    case '\x02':
      (**(code **)(this->_padding_ + 0xec))(uVar4,uVar5,param_2,2,pRVar3);
      return;
    case '\x03':
      iVar6 = this->_padding_;
      uVar9 = 2;
      param_3 = param_2;
    }
    (**(code **)(iVar6 + 0xec))(uVar4,uVar5,param_3,uVar9,pRVar3);
  }
switchD_00437ffe_caseD_0:
  return;
}

// --------------------------------------------------

// Function: draw_object
// Address: 00438060
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual void __thiscall RGE_Diamond_Map::draw_object(short,short,unsigned
   char,short,class RGE_Static_Object *) */

void __thiscall
RGE_Diamond_Map::draw_object
          (RGE_Diamond_Map *this,short param_1,short param_2,uchar param_3,short param_4,
          RGE_Static_Object *param_5)
{
  RGE_Map_Tile_Row *pRVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  sVar3 = this->map_wid;
  pRVar1 = this->map_tile_rows;
  sVar2 = __ftol();
  sVar3 = pRVar1[(((int)sVar3 + (int)param_2) - (int)param_1) + -1].image_line;
  sVar2 = this->map_image_lines[sVar3].start_x + (short)this->_padding_ + sVar2;
  sVar3 = (short)this->_padding_ + this->map_image_start_y + sVar3;
  if (param_4 == 1) {
    TDrawArea::FillRect((TDrawArea *)this->_padding_,sVar2 + -1,sVar3 + -1,sVar2 + 1,sVar3 + 1,
                        param_3);
    return;
  }
  if (param_4 != 2) {
    if (param_4 == 3) {
      iVar5 = (int)sVar3;
      iVar4 = (int)sVar2;
      TDrawArea::FillRect((TDrawArea *)this->_padding_,iVar4 + -3,iVar5,iVar4 + 3,iVar5 + 1,param_3)
      ;
      TDrawArea::FillRect((TDrawArea *)this->_padding_,iVar4 + -2,iVar5 + -1,iVar4 + 2,iVar5 + 2,
                          param_3);
      return;
    }
    if (param_4 == 4) {
      TDrawArea::FillRect((TDrawArea *)this->_padding_,sVar2 + -2,sVar3 + -2,sVar2 + 2,sVar3 + 2,
                          param_3);
    }
    return;
  }
  iVar5 = (int)sVar3;
  iVar4 = (int)sVar2;
  TDrawArea::FillRect((TDrawArea *)this->_padding_,iVar4,iVar5 + -1,iVar4,iVar5 + 1,param_3);
  TDrawArea::FillRect((TDrawArea *)this->_padding_,iVar4 + -1,iVar5,iVar4 + 1,iVar5,param_3);
  return;
}

// --------------------------------------------------

// Function: draw_clipped_horz_line
// Address: 004381d0
/* protected: void __thiscall RGE_Diamond_Map::draw_clipped_horz_line(short,short,short,unsigned
   char,struct RGE_Map_Image_Line *) */

void __thiscall
RGE_Diamond_Map::draw_clipped_horz_line
          (RGE_Diamond_Map *this,short param_1,short param_2,short param_3,uchar param_4,
          RGE_Map_Image_Line *param_5)
{
  short sVar1;
  int iVar2;
  
  sVar1 = param_5->start_x;
  iVar2 = this->_padding_ + (int)sVar1;
  if (param_1 < iVar2) {
    param_1 = (short)this->_padding_ + sVar1;
  }
  if (param_5->line_len + iVar2 <= param_3 + -1 + (int)param_1) {
    param_3 = ((short)this->_padding_ - param_1) + param_5->line_len + sVar1;
  }
  TDrawArea::DrawHorzLine
            ((TDrawArea *)this->_padding_,(int)param_1,(int)param_2,(int)param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: draw_view_rect
// Address: 00438250
/* WARNING: Variable defined which should be unmapped: vwid */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual void __thiscall RGE_Diamond_Map::draw_view_rect(void) */

void __thiscall RGE_Diamond_Map::draw_view_rect(RGE_Diamond_Map *this)
{
  RGE_Map_Tile_Row *pRVar1;
  RGE_Map_Image_Line *pRVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  short vwid;
  short vhgt;
  short row;
  undefined4 local_8;
  int local_4;
  
  sVar3 = __ftol();
  local_8 = __ftol();
  sVar4 = (short)local_8;
  if ((sVar3 != this->view_col) || (sVar4 != this->view_row)) {
    if (sVar3 < 0) {
      return;
    }
    if (this->map->map_width <= (int)sVar3) {
      return;
    }
    if (sVar4 < 0) {
      return;
    }
    if (this->map->map_height <= (int)sVar4) {
      return;
    }
    sVar4 = this->map_wid;
    sVar5 = __ftol();
    sVar6 = __ftol();
    pRVar1 = this->map_tile_rows;
    sVar11 = (short)local_8;
    if (sVar3 < (short)local_8) {
      sVar11 = sVar3;
    }
    _row = (int)sVar11;
    __ftol();
    sVar4 = pRVar1[((int)sVar4 - (int)sVar5) + -1 + (int)sVar6].image_line;
    iVar13 = this->_padding_;
    sVar11 = this->map_image_start_y;
    RGE_View::get_max_size(this->main_view,&vhgt,&row);
    iVar7 = (int)vhgt;
    local_4 = iVar7 / 2;
    lVar8 = __ftol();
    (this->view_rect).left = lVar8;
    iVar12 = (int)row;
    _vhgt = (float)(int)(short)((short)iVar13 + sVar11 + sVar4);
    local_4 = iVar12;
    lVar8 = __ftol();
    local_4 = iVar7 / 2 + 2;
    (this->view_rect).top = lVar8;
    lVar8 = __ftol();
    local_4 = iVar12 + 4;
    (this->view_rect).right = lVar8;
    lVar8 = __ftol();
    (this->view_rect).bottom = lVar8;
    this->view_col = sVar3;
    this->view_row = (short)local_8;
  }
  iVar13 = (this->view_rect).top;
  iVar7 = (this->view_rect).bottom;
  if (iVar13 <= iVar7) {
    do {
      iVar12 = this->_padding_ + (int)this->map_image_start_y;
      if ((iVar12 <= iVar13) && (iVar13 <= this->map_image_hgt + -1 + iVar12)) {
        iVar9 = (iVar13 - this->map_image_start_y) - this->_padding_;
        iVar12 = (this->view_rect).right;
        pRVar2 = this->map_image_lines;
        iVar10 = (this->view_rect).left;
        if ((iVar13 == (this->view_rect).top) || (iVar13 == iVar7)) {
          iVar7 = (int)pRVar2[iVar9].start_x + this->_padding_;
          iVar9 = pRVar2[iVar9].line_len + iVar7;
          if ((iVar10 < iVar9) && (iVar7 <= iVar12)) {
            if (iVar10 < iVar7) {
              iVar10 = iVar7;
            }
            if (iVar9 <= iVar12) {
              iVar12 = iVar9 + -1;
            }
            TDrawArea::DrawHorzLine
                      ((TDrawArea *)this->_padding_,iVar10,iVar13,(iVar12 - iVar10) + 1,0xff);
          }
        }
        else {
          iVar7 = (int)pRVar2[iVar9].start_x + this->_padding_;
          if ((iVar10 < pRVar2[iVar9].line_len + iVar7) && (iVar7 <= iVar10)) {
            TDrawArea::SetPixel((TDrawArea *)this->_padding_,iVar10,iVar13,0xff);
          }
          iVar7 = (int)pRVar2[iVar9].start_x + this->_padding_;
          if ((iVar12 < pRVar2[iVar9].line_len + iVar7) && (iVar7 <= iVar12)) {
            TDrawArea::SetPixel((TDrawArea *)this->_padding_,iVar12,iVar13,0xff);
          }
        }
      }
      iVar7 = (this->view_rect).bottom;
      iVar13 = iVar13 + 1;
    } while (iVar13 <= iVar7);
  }
  return;
}

// --------------------------------------------------

// Function: pick_tile
// Address: 00438530
/* public: int __thiscall RGE_Diamond_Map::pick_tile(long,long,short *,short *,struct RGE_Tile * *)
    */

int __thiscall
RGE_Diamond_Map::pick_tile
          (RGE_Diamond_Map *this,long param_1,long param_2,short *param_3,short *param_4,
          RGE_Tile **param_5)
{
  short sVar1;
  RGE_Map_Image_Line *pRVar2;
  RGE_Map_Tile_Row *pRVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  
  if ((this->map != (RGE_Map *)0x0) &&
     (pRVar2 = this->map_image_lines, pRVar2 != (RGE_Map_Image_Line *)0x0)) {
    iVar7 = param_2 - this->_padding_;
    iVar5 = param_1 - this->_padding_;
    iVar8 = (int)this->map_image_start_y;
    if ((iVar8 <= iVar7) && (iVar7 <= this->map_image_hgt + -1 + iVar8)) {
      if ((pRVar2[iVar7 - iVar8].start_x <= iVar5) &&
         (iVar5 <= pRVar2[iVar7 - iVar8].line_len + -1 + (int)pRVar2[iVar7 - iVar8].start_x)) {
        sVar1 = pRVar2[iVar7 - iVar8].tile_row;
        pRVar3 = this->map_tile_rows;
        sVar4 = __ftol();
        sVar6 = pRVar3[sVar1].map_col + sVar4;
        sVar4 = pRVar3[sVar1].map_row + sVar4;
        if (param_3 != (short *)0x0) {
          *param_3 = sVar6;
        }
        if (param_4 != (short *)0x0) {
          *param_4 = sVar4;
        }
        if (param_5 != (RGE_Tile **)0x0) {
          *param_5 = this->map->map_row_offset[sVar4] + sVar6;
        }
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: handle_size
// Address: 00438630
/* public: virtual long __thiscall RGE_Diamond_Map::handle_size(long,long) */

long __thiscall RGE_Diamond_Map::handle_size(RGE_Diamond_Map *this,long param_1,long param_2)
{
  TPanel::handle_size((TPanel *)this,param_1,param_2);
  this->view_col = -1;
  this->view_row = -1;
  create_surfaces(this);
  return 0;
}

// --------------------------------------------------

// Function: start_scroll_view
// Address: 00438670
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Diamond_Map::start_scroll_view(long,long) */

void __thiscall RGE_Diamond_Map::start_scroll_view(RGE_Diamond_Map *this,long param_1,long param_2)
{
  float fVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  RGE_Tile *tile;
  RGE_Tile *local_4;
  
  lVar3 = param_2;
  lVar2 = param_1;
  iVar4 = pick_tile(this,param_1,param_2,(short *)&param_1,(short *)&param_2,&local_4);
  if (iVar4 != 0) {
    TPanel::capture_mouse((TPanel *)this);
    fVar1 = (float)(int)(short)param_2 - _DAT_0056f608;
    this->scrolling = 1;
    RGE_Player::set_view_loc(this->player,(float)(int)(short)param_1 - _DAT_0056f608,fVar1);
    (**(code **)(this->_padding_ + 0x20))(1);
    if (this->main_view != (RGE_View *)0x0) {
      (**(code **)(this->main_view->_padding_ + 0x20))(1);
    }
    this->mouse_last_x = lVar2;
    this->mouse_last_y = lVar3;
  }
  return;
}

// --------------------------------------------------

// Function: handle_scroll_view
// Address: 00438720
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Diamond_Map::handle_scroll_view(long,long) */

void __thiscall RGE_Diamond_Map::handle_scroll_view(RGE_Diamond_Map *this,long param_1,long param_2)
{
  long lVar1;
  long lVar2;
  int iVar3;
  RGE_Tile *tile;
  RGE_Tile *local_4;
  
  lVar2 = param_2;
  lVar1 = param_1;
  iVar3 = pick_tile(this,param_1,param_2,(short *)&param_1,(short *)&param_2,&local_4);
  if (iVar3 != 0) {
    RGE_Player::set_view_loc
              (this->player,(float)(int)(short)param_1 - _DAT_0056f608,
               (float)(int)(short)param_2 - _DAT_0056f608);
    (**(code **)(this->_padding_ + 0x20))(1);
    if (this->main_view != (RGE_View *)0x0) {
      (**(code **)(this->main_view->_padding_ + 0x20))(1);
    }
    this->mouse_last_x = lVar1;
    this->mouse_last_y = lVar2;
  }
  return;
}

// --------------------------------------------------

// Function: end_scroll_view
// Address: 004387c0
/* public: void __thiscall RGE_Diamond_Map::end_scroll_view(void) */

void __thiscall RGE_Diamond_Map::end_scroll_view(RGE_Diamond_Map *this)
{
  this->scrolling = 0;
  TPanel::release_mouse((TPanel *)this);
  return;
}

// --------------------------------------------------

// Function: is_inside
// Address: 004387d0
/* WARNING: Variable defined which should be unmapped: tile */
/* public: virtual int __thiscall RGE_Diamond_Map::is_inside(long,long) */

int __thiscall RGE_Diamond_Map::is_inside(RGE_Diamond_Map *this,long param_1,long param_2)
{
  long lVar1;
  long lVar2;
  int iVar3;
  RGE_Tile *tile;
  RGE_Diamond_Map *local_4;
  
  lVar2 = param_2;
  lVar1 = param_1;
  local_4 = this;
  iVar3 = TPanel::is_inside((TPanel *)this,param_1,param_2);
  if (iVar3 != 0) {
    iVar3 = pick_tile(this,lVar1,lVar2,(short *)&param_1,(short *)&param_2,(RGE_Tile **)&local_4);
    return iVar3;
  }
  return 0;
}

// --------------------------------------------------

