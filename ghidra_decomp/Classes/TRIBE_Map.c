// Class: TRIBE_Map
// Size:  0xB5F8
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] data_load_random_map
// [02] load_random_map
// [03] do_terrain_brush
// [04] do_terrain_brush_stroke
// [05] do_elevation_brush
// [06] do_elevation_brush_stroke
// [07] do_cliff_brush
// [08] do_cliff_brush_stroke
// [09] map_generate
// [10] map_generate2
// [11] save
// [12] delete_cliff
//
// Member Layout:
// [0x8DD0] TRIBE_Game * Game
// [0x8DD4] RGE_Player * rge_player
// [0x8DD8] RGE_Game_World * rge_game_world
// [0x8DDC] RGE_Map_Gen_Info * rge_map_gen_information
// [0x8DE0] uchar * zones
// [0x8DE4] long old_cliff_x
// [0x8DE8] long old_cliff_y
// [0x8DEC] long safe_cliff_x
// [0x8DF0] long safe_cliff_y
// [0x8DF4] long old_cliff_direction
// [0x8DF8] TRIBE_Master_Cliff_Info[256] cliff_master_table (sz: 0x2800)
// ----------------------------------------------------------------

// Function: TRIBE_Map
// Address: 0050f410
TRIBE_Map * __thiscall
TRIBE_Map::TRIBE_Map(TRIBE_Map *this,int param_1,RGE_Sound **param_2,uchar param_3)
{
  float *pfVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561048;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Map::RGE_Map((RGE_Map *)this,param_1,param_2,'\0');
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != '\0') {
    data_load_random_map(this,param_1);
  }
  pfVar1 = &this->cliff_master_table[0].offset_y;
  this->old_cliff_x = -1;
  this->old_cliff_y = -1;
  this->safe_cliff_x = -1;
  this->safe_cliff_y = -1;
  iVar2 = 0x100;
  do {
    pfVar1[-1] = 0.0;
    *pfVar1 = 0.0;
    ((TRIBE_Cliff_Info *)(pfVar1 + -5))->info[0] = 0;
    pfVar1[-4] = 0.0;
    pfVar1[-3] = 0.0;
    pfVar1[-2] = 0.0;
    ((TRIBE_Master_Cliff_Info *)(pfVar1 + -9))->id = -1;
    pfVar1[-8] = -NAN;
    pfVar1[-7] = -NAN;
    pfVar1[-6] = -NAN;
    pfVar1 = pfVar1 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  setup_cliff_type(this,1,0,0,0,0x108,0x10,-1,-1,1.5,1.5);
  setup_cliff_type(this,0,1,0,0,0x108,0x12,-1,-1,1.5,1.5);
  setup_cliff_type(this,0,0,1,0,0x108,0x11,-1,-1,1.5,1.5);
  setup_cliff_type(this,0,0,0,1,0x108,0x13,-1,-1,1.5,1.5);
  setup_cliff_type(this,-1,0,0,0,0x10a,0x14,-1,-1,1.5,1.5);
  setup_cliff_type(this,0,-1,0,0,0x109,0x16,-1,-1,1.5,1.5);
  setup_cliff_type(this,0,0,-1,0,0x10a,0x15,-1,-1,1.5,1.5);
  setup_cliff_type(this,0,0,0,-1,0x109,0x17,-1,-1,1.5,1.5);
  setup_cliff_type(this,-1,1,0,0,0x10e,0,-1,-1,1.5,2.0);
  setup_cliff_type(this,0,-1,-1,0,0x110,9,-1,-1,1.0,2.0);
  setup_cliff_type(this,0,0,1,-1,0x10c,6,-1,-1,1.0,1.5);
  setup_cliff_type(this,1,0,0,1,0x108,3,-1,-1,1.5,1.5);
  setup_cliff_type(this,1,-1,0,0,0x10b,0xc,-1,-1,2.0,1.5);
  setup_cliff_type(this,0,1,1,0,0x108,0xf,-1,-1,1.5,1.5);
  setup_cliff_type(this,0,0,-1,1,0x10d,0xe,-1,-1,1.5,1.0);
  setup_cliff_type(this,-1,0,0,-1,0x10f,0xd,-1,-1,2.0,1.0);
  setup_cliff_type(this,1,0,1,0,0x108,4,0x108,5,1.5,1.5);
  setup_cliff_type(this,0,1,0,1,0x108,1,0x108,2,1.5,1.5);
  setup_cliff_type(this,-1,0,-1,0,0x10a,0xb,0x10a,10,1.5,1.5);
  setup_cliff_type(this,0,-1,0,-1,0x109,8,0x109,7,1.5,1.5);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0050f740
void * __thiscall TRIBE_Map::_scalar_deleting_destructor_(TRIBE_Map *this,uint param_1)
{
  ~TRIBE_Map(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Map
// Address: 0050f760
TRIBE_Map * __thiscall
TRIBE_Map::TRIBE_Map
          (TRIBE_Map *this,char *param_1,char *param_2,char *param_3,char *param_4,short param_5,
          short param_6,short param_7,RGE_Sound **param_8)
{
  RGE_Map::RGE_Map((RGE_Map *)this,param_1,param_3,param_4,param_5,param_6,param_7,param_8);
  this->_padding_ = (int)&_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Map
// Address: 0050f7a0
void __thiscall TRIBE_Map::~TRIBE_Map(TRIBE_Map *this)
{
  this->_padding_ = (int)&_vftable_;
  RGE_Map::~RGE_Map((RGE_Map *)this);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0050f7b0
void __thiscall TRIBE_Map::save(TRIBE_Map *this,int param_1)
{
  RGE_Map::save((RGE_Map *)this,param_1);
  return;
}

// --------------------------------------------------

// Function: map_generate
// Address: 0050f7c0
void __thiscall
TRIBE_Map::map_generate
          (TRIBE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2,RGE_Player_Info *param_3,
          uchar *param_4)
{
  this->rge_game_world = param_2;
  this->rge_player = param_1;
  this->zones = param_4;
  map_generate(this,param_3);
  return;
}

// --------------------------------------------------

// Function: map_generate
// Address: 0050f7f0
void __thiscall TRIBE_Map::map_generate(TRIBE_Map *this,RGE_Player_Info *param_1)
{
  return;
}

// --------------------------------------------------

// Function: data_load_random_map
// Address: 0050f800
void __thiscall TRIBE_Map::data_load_random_map(TRIBE_Map *this,int param_1)
{
  TRIBE_RMM_Database_Controller *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056106b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_RMM_Database_Controller *)operator_new(0x4f5c);
  local_4 = 0;
  if (this_00 == (TRIBE_RMM_Database_Controller *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(this_00,param_1);
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_random_map
// Address: 0050f860
void __thiscall
TRIBE_Map::load_random_map(TRIBE_Map *this,char *param_1,char *param_2,char *param_3,char *param_4)
{
  TRIBE_RMM_Database_Controller *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056108b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_RMM_Database_Controller *)operator_new(0x4f5c);
  local_4 = 0;
  if (this_00 == (TRIBE_RMM_Database_Controller *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller
                      (this_00,param_2,param_3,param_4,param_1);
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: check_tile_for_forest_change
// Address: 0050f8d0
void __thiscall
TRIBE_Map::check_tile_for_forest_change
          (TRIBE_Map *this,short param_1,short param_2,RGE_Game_World *param_3)
{
  short sVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  byte bVar5;
  short sVar6;
  int iVar7;
  byte *pbVar8;
  short sVar9;
  int iVar10;
  short sVar11;
  int *piVar12;
  uchar success;
  short x0;
  short x1;
  short y1;
  
  sVar11 = param_2 + -1;
  sVar9 = param_2 + 1;
  iVar7 = *(int *)(this->_padding_ + param_2 * 4) + param_1 * 0x18;
  sVar1 = param_1 + -1;
  sVar6 = param_1 + 1;
  bVar2 = false;
  bVar3 = false;
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  if (sVar11 < 0) {
    sVar11 = 0;
  }
  if (this->_padding_ <= (int)sVar6) {
    sVar6 = (short)this->_padding_ + -1;
  }
  if (this->_padding_ <= (int)sVar9) {
    sVar9 = (short)this->_padding_ + -1;
  }
  bVar5 = *(byte *)(iVar7 + 5) & 0x1f;
  if (bVar5 == 10) {
    piVar12 = (int *)(this->_padding_ + sVar11 * 4);
    iVar7 = *piVar12;
    if (sVar11 <= sVar9) {
      iVar10 = ((int)sVar9 - (int)sVar11) + 1;
      do {
        if (sVar1 <= sVar6) {
          pbVar8 = (byte *)(sVar1 * 0x18 + iVar7 + 5);
          iVar7 = ((int)sVar6 - (int)sVar1) + 1;
          do {
            if (((*pbVar8 & 0x1f) != 10) && ((*pbVar8 & 0x1f) != 0x12)) {
              bVar3 = true;
            }
            pbVar8 = pbVar8 + 0x18;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        iVar7 = piVar12[1];
        piVar12 = piVar12 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    if (bVar3) {
      change_terrain(this,param_1,param_2,'\x12',param_3);
    }
  }
  else if (bVar5 == 0x12) {
    for (piVar12 = *(int **)(iVar7 + 0x10); piVar12 != (int *)0x0; piVar12 = (int *)piVar12[1]) {
      if ((*(short *)(*(int *)(*piVar12 + 8) + 0x14) == 0xf) && (*(byte *)(*piVar12 + 0x48) < 8)) {
        bVar2 = true;
      }
    }
    if ((!bVar2) &&
       (change_terrain(this,param_1,param_2,'\0',param_3), sVar4 = sVar1, sVar11 <= sVar9)) {
      do {
        for (; sVar4 <= sVar6; sVar4 = sVar4 + 1) {
          if ((sVar4 != param_1) || (sVar11 != param_2)) {
            check_tile_for_forest_change(this,sVar4,sVar11,param_3);
          }
        }
        sVar11 = sVar11 + 1;
        sVar4 = sVar1;
      } while (sVar11 <= sVar9);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: change_terrain
// Address: 0050fa90
void __thiscall
TRIBE_Map::change_terrain
          (TRIBE_Map *this,short param_1,short param_2,uchar param_3,RGE_Game_World *param_4)
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  short col2;
  short col1;
  int local_10;
  int local_c;
  short row2;
  
  sVar6 = param_1;
  iVar5 = (int)param_2;
  iVar7 = (int)param_1;
  iVar3 = *(int *)(this->_padding_ + iVar5 * 4) + iVar7 * 0x18;
  bVar1 = *(byte *)(iVar3 + 5);
  *(byte *)(iVar3 + 5) = (param_3 ^ bVar1) & 0x1f ^ bVar1;
  sVar4 = param_4->curr_player;
  if ((sVar4 < 1) || (param_4->player_num <= sVar4)) {
    _param_1 = (RGE_Player *)0x0;
  }
  else {
    _param_1 = param_4->players[sVar4];
  }
  if ((_param_1 != (RGE_Player *)0x0) && (param_4->game_state != '\x03')) {
    RGE_Tile_List::add_node(&_param_1->diam_tile_list,iVar7,iVar5);
  }
  if (sVar6 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = iVar7 + -1;
  }
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = iVar5 + -1;
  }
  if (iVar7 != this->_padding_ + -1) {
    sVar6 = sVar6 + 1;
  }
  sVar4 = param_2;
  if (iVar5 != this->_padding_ + -1) {
    sVar4 = param_2 + 1;
  }
  if ((short)iVar3 <= sVar4) {
    local_c = (int)(short)iVar3;
    _row2 = local_c * 4;
    _param_2 = iVar3;
    do {
      if ((short)local_10 <= sVar6) {
        _col2 = (int)(short)local_10;
        iVar5 = _col2 * 0x18;
        iVar3 = local_10;
        do {
          iVar7 = *(int *)(_row2 + this->_padding_) + iVar5;
          bVar1 = *(byte *)(iVar7 + 6);
          RGE_Map::get_border_type((RGE_Map *)this,(short)iVar3,(short)_param_2);
          if ((_param_1 != (RGE_Player *)0x0) &&
             (((bVar2 = *(byte *)(iVar7 + 6), (bVar2 & 0xf) != (bVar1 & 0xf) ||
               (bVar2 >> 4 != bVar1 >> 4)) && (param_4->game_state != '\x03')))) {
            RGE_Tile_List::add_node(&_param_1->diam_tile_list,_col2,local_c);
          }
          iVar3 = iVar3 + 1;
          _col2 = _col2 + 1;
          iVar5 = iVar5 + 0x18;
        } while ((short)iVar3 <= sVar6);
      }
      _param_2 = _param_2 + 1;
      local_c = local_c + 1;
      _row2 = _row2 + 4;
    } while ((short)_param_2 <= sVar4);
  }
  return;
}

// --------------------------------------------------

// Function: do_terrain_brush
// Address: 0050fc40
uchar __thiscall
TRIBE_Map::do_terrain_brush(TRIBE_Map *this,long param_1,long param_2,long param_3,uchar param_4)
{
  int iVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_3 + param_1;
  param_1 = param_1 - param_3;
  iVar3 = param_2 - param_3;
  param_3 = param_2 + param_3;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (this->_padding_ <= iVar4) {
    iVar4 = this->_padding_ + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (this->_padding_ <= param_3) {
    param_3 = this->_padding_ + -1;
  }
  uVar2 = water(this,param_4);
  if (uVar2 == '\0') {
    for (; iVar1 = param_1, iVar3 <= param_3; iVar3 = iVar3 + 1) {
      for (; iVar1 <= iVar4; iVar1 = iVar1 + 1) {
        RGE_Map::set_terrain
                  ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,(short)iVar1,(short)iVar3,
                   param_4,0,0);
      }
    }
  }
  else {
    iVar1 = param_1;
    if (iVar3 <= param_3) {
      do {
        for (; iVar1 <= iVar4; iVar1 = iVar1 + 1) {
          uVar2 = do_terrain_brush_check(this,iVar1,iVar3);
          if (uVar2 != '\0') {
            RGE_Map::set_terrain
                      ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,(short)iVar1,(short)iVar3,
                       param_4,0,0);
          }
        }
        iVar3 = iVar3 + 1;
        iVar1 = param_1;
      } while (iVar3 <= param_3);
      return '\x01';
    }
  }
  return '\x01';
}

// --------------------------------------------------

// Function: do_terrain_brush_stroke
// Address: 0050fd40
uchar __thiscall
TRIBE_Map::do_terrain_brush_stroke
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4,long param_5,
          uchar param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  RGE_Map::do_terrain_brush_stroke((RGE_Map *)this,param_1,param_2,param_3,param_4,param_5,param_6);
  if (param_1 < param_3) {
    iVar3 = param_1 - param_5;
  }
  else {
    iVar3 = param_3 - param_5;
    param_3 = param_1;
  }
  if (param_2 < param_4) {
    iVar2 = param_2 - param_5;
    iVar1 = param_4 + param_5;
  }
  else {
    iVar2 = param_4 - param_5;
    iVar1 = param_2 + param_5;
  }
  tribe_clean_terrain(this,iVar3 + -2,iVar2 + -2,param_3 + param_5 + 2,iVar1 + 2,'\x01',param_6);
  return '\x01';
}

// --------------------------------------------------

// Function: do_elevation_brush_stroke
// Address: 0050fdd0
uchar __thiscall
TRIBE_Map::do_elevation_brush_stroke
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4,long param_5,
          uchar param_6)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  RGE_Map::do_elevation_brush_stroke
            ((RGE_Map *)this,param_1,param_2,param_3,param_4,param_5,param_6);
  if (param_1 < param_3) {
    iVar4 = param_1 - (param_5 + (uint)param_6);
    iVar5 = param_3 + param_5 + (uint)param_6;
  }
  else {
    iVar4 = (param_3 - param_5) - (uint)param_6;
    iVar5 = param_1 + param_5 + (uint)param_6;
  }
  uVar1 = (uint)param_6;
  if (param_2 < param_4) {
    iVar3 = param_2 - (param_5 + uVar1);
    iVar2 = param_4 + param_5 + uVar1;
  }
  else {
    iVar3 = (param_4 - param_5) - uVar1;
    iVar2 = param_2 + param_5 + uVar1;
  }
  tribe_clean_elevation(this,iVar4 + -2,iVar3 + -2,iVar5 + 2,iVar2 + 2);
  tribe_clean_terrain(this,iVar4 + -2,iVar3 + -2,iVar5 + 2,iVar2 + 2,'\x01','\0');
  return '\x01';
}

// --------------------------------------------------

// Function: setup_cliff_type
// Address: 0050fe90
void __thiscall
TRIBE_Map::setup_cliff_type
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4,long param_5,
          long param_6,long param_7,long param_8,float param_9,float param_10)
{
  int iVar1;
  
  iVar1 = param_3 + (param_2 + param_1 * 4) * 4;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].id = param_5;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].facet = param_6;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].id2 = param_7;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].facet2 = param_8;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].offset_x = param_9;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].offset_y = param_10;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].info.info[0] = param_1;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].info.info[1] = param_2;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].info.info[2] = param_3;
  this->cliff_master_table[iVar1 * 4 + param_4 + 0x55].info.info[3] = param_4;
  return;
}

// --------------------------------------------------

// Function: find_cliff
// Address: 0050ff20
RGE_Static_Object * __thiscall TRIBE_Map::find_cliff(TRIBE_Map *this,long param_1,long param_2)
{
  short sVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 * 3 + 2 <= this->_padding_) && (iVar5 = param_2 * 3 + 2, iVar5 <= this->_padding_)) {
    iVar4 = (param_1 * 3 + 1) * 0x18;
    iVar2 = *(int *)(this->_padding_ + (param_2 * 3 + 1) * 4);
    for (pRVar3 = *(RGE_Static_Object **)(iVar2 + 0x10 + iVar4); pRVar3 != (RGE_Static_Object *)0x0;
        pRVar3 = (RGE_Static_Object *)pRVar3->id) {
      sVar1 = *(short *)(*(int *)(pRVar3->_padding_ + 8) + 0x10);
      if ((0x107 < sVar1) && (sVar1 < 0x112)) goto LAB_00510005;
    }
    iVar5 = iVar4 + *(int *)(this->_padding_ + iVar5 * 4);
    for (pRVar3 = *(RGE_Static_Object **)(iVar5 + 0x10); pRVar3 != (RGE_Static_Object *)0x0;
        pRVar3 = (RGE_Static_Object *)pRVar3->id) {
      sVar1 = *(short *)(*(int *)(pRVar3->_padding_ + 8) + 0x10);
      if ((0x107 < sVar1) && (sVar1 < 0x112)) goto LAB_00510005;
    }
    for (pRVar3 = *(RGE_Static_Object **)(iVar2 + iVar4 + 0x28); pRVar3 != (RGE_Static_Object *)0x0;
        pRVar3 = (RGE_Static_Object *)pRVar3->id) {
      sVar1 = *(short *)(*(int *)(pRVar3->_padding_ + 8) + 0x10);
      if ((0x107 < sVar1) && (sVar1 < 0x112)) goto LAB_00510005;
    }
    pRVar3 = *(RGE_Static_Object **)(iVar5 + 0x28);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      while ((sVar1 = *(short *)(*(int *)(pRVar3->_padding_ + 8) + 0x10), sVar1 < 0x108 ||
             (0x111 < sVar1))) {
        pRVar3 = (RGE_Static_Object *)pRVar3->id;
        if (pRVar3 == (RGE_Static_Object *)0x0) {
          return pRVar3;
        }
      }
LAB_00510005:
      return (RGE_Static_Object *)pRVar3->_padding_;
    }
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: get_cliff_info
// Address: 00510020
TRIBE_Cliff_Info * __thiscall
TRIBE_Map::get_cliff_info
          (TRIBE_Map *this,TRIBE_Cliff_Info *__return_storage_ptr__,RGE_Static_Object *param_1)
{
  TRIBE_Cliff_Info *pTVar1;
  long *plVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    __return_storage_ptr__->info[0] = 0;
    __return_storage_ptr__->info[1] = 0;
    __return_storage_ptr__->info[2] = 0;
    __return_storage_ptr__->info[3] = 0;
    return __return_storage_ptr__;
  }
  iVar3 = 0;
  iVar4 = (int)param_1->master_obj->id;
  plVar2 = &this->cliff_master_table[0].facet;
  while (((((TRIBE_Master_Cliff_Info *)(plVar2 + -1))->id != iVar4 ||
          (*plVar2 != (uint)param_1->facet)) &&
         ((plVar2[1] != iVar4 || (plVar2[2] != (uint)param_1->facet))))) {
    iVar3 = iVar3 + 1;
    plVar2 = plVar2 + 10;
    if (0xff < iVar3) {
      __return_storage_ptr__->info[0] = 0;
      __return_storage_ptr__->info[1] = 0;
      __return_storage_ptr__->info[2] = 0;
      __return_storage_ptr__->info[3] = 0;
      return __return_storage_ptr__;
    }
  }
  pTVar1 = &this->cliff_master_table[iVar3].info;
  __return_storage_ptr__->info[0] = pTVar1->info[0];
  __return_storage_ptr__->info[1] = pTVar1->info[1];
  __return_storage_ptr__->info[2] = pTVar1->info[2];
  __return_storage_ptr__->info[3] = pTVar1->info[3];
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: check_cliff_valid
// Address: 005100d0
uchar __thiscall TRIBE_Map::check_cliff_valid(TRIBE_Map *this,TRIBE_Cliff_Info param_1)
{
  return -1 < this->cliff_master_table
              [param_1.info[3] + (param_1.info[2] + (param_1.info[1] + param_1.info[0] * 4) * 4) * 4
               + 0x55].id;
}

// --------------------------------------------------

// Function: make_new_cliff
// Address: 00510110
// [HELPER] s_C__msdev_work_age1_x1_tmap_cpp: "C:\msdev\work\age1_x1\tmap.cpp"
RGE_Static_Object * __thiscall
TRIBE_Map::make_new_cliff(TRIBE_Map *this,long param_1,long param_2,TRIBE_Cliff_Info param_3)
{
  float fVar1;
  float fVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  uchar unaff_SI;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  long id;
  RGE_Static_Object *new_cliff;
  long facet;
  float local_c;
  float fStack_8;
  
  iVar5 = param_3.info[2] + (param_3.info[1] + param_3.info[0] * 4) * 4;
  fVar1 = this->cliff_master_table[iVar5 * 4 + param_3.info[3] + 0x55].offset_x;
  fVar2 = this->cliff_master_table[iVar5 * 4 + param_3.info[3] + 0x55].offset_y;
  if (-1 < this->cliff_master_table[iVar5 * 4 + param_3.info[3] + 0x55].id2) {
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_tmap_cpp,0x221);
    if (0x7fff < iVar3 * 2) {
      iVar3 = this->cliff_master_table[iVar5 * 4 + param_3.info[3] + 0x55].id2;
      local_c = (float)this->cliff_master_table[iVar5 * 4 + param_3.info[3] + 0x55].facet2;
      goto LAB_005101bf;
    }
  }
  local_c = (float)this->cliff_master_table[iVar5 * 4 + param_3.info[3] + 0x55].facet;
  iVar3 = this->cliff_master_table[iVar5 * 4 + param_3.info[3] + 0x55].id;
LAB_005101bf:
  if (-1 < iVar3) {
    uVar8 = 0;
    pRVar4 = (RGE_Static_Object *)
             (**(code **)(*(int *)**(undefined4 **)(this->_padding_ + 0x40) + 0x94))
                       (iVar3,(float)(param_1 * 3) + fVar1,(float)(param_2 * 3) + fVar2,0);
    facet = -1;
    iVar5 = __ftol();
    iVar3 = __ftol();
    do {
      iVar7 = 3;
      iVar6 = iVar5 + -1;
      do {
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(this->_padding_ + 0x40) +
                            *(short *)(this->_padding_ + 0x7c) * 4) + 0x6c),facet + iVar3,iVar6);
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      facet = facet + 1;
    } while (facet < 2);
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      pRVar4->facet = unaff_SI;
    }
    TRIBE_World::check_destructables
              ((TRIBE_World *)this->_padding_,0,(short)uVar8,fStack_8,local_c,'\x01');
    return pRVar4;
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: remove_cliff_edge
// Address: 005102a0
void __thiscall TRIBE_Map::remove_cliff_edge(TRIBE_Map *this,long param_1,long param_2,long param_3)
{
  int iVar1;
  TRIBE_Cliff_Info TVar2;
  RGE_Static_Object *pRVar3;
  TRIBE_Cliff_Info *pTVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  TRIBE_Map *unaff_EBX;
  int iVar8;
  int iVar9;
  long unaff_retaddr;
  TRIBE_Cliff_Info cliff_info;
  TRIBE_Cliff_Info local_10;
  
  switch(param_3) {
  case 0:
    param_1 = param_1 + 1;
    if (this->_padding_ <= param_1) {
      return;
    }
    break;
  case 1:
    param_2 = param_2 + 1;
    if (this->_padding_ <= param_2) {
      return;
    }
    break;
  case 2:
    if (param_1 < 1) {
      return;
    }
    param_1 = param_1 + -1;
    break;
  case 3:
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
  }
  cliff_info.info[0] = (long)this;
  pRVar3 = find_cliff(this,param_1,param_2);
  pTVar4 = get_cliff_info(this,&local_10,pRVar3);
  cliff_info.info[1] = pTVar4->info[0];
  cliff_info.info[2] = pTVar4->info[1];
  cliff_info.info[3] = pTVar4->info[2];
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    iVar8 = -1;
    do {
      iVar9 = -1;
      do {
        iVar1 = *(int *)(cliff_info.info[0] + 0x8dc0);
        iVar5 = __ftol();
        iVar5 = iVar9 + iVar5;
        iVar6 = __ftol();
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4) + 0x6c),
                   iVar8 + iVar6,iVar5);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 2);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    (**(code **)pRVar3->_padding_)(1);
    lVar7 = reverse_cliff_direction(unaff_EBX,param_2);
    cliff_info.info[lVar7] = 0;
    TVar2.info[1] = cliff_info.info[1];
    TVar2.info[0] = cliff_info.info[0];
    TVar2.info[2] = cliff_info.info[2];
    TVar2.info[3] = cliff_info.info[3];
    make_new_cliff(unaff_EBX,unaff_retaddr,param_1,TVar2);
  }
  return;
}

// --------------------------------------------------

// Function: reverse_cliff_direction
// Address: 00510410
long __thiscall TRIBE_Map::reverse_cliff_direction(TRIBE_Map *this,long param_1)
{
  long lVar1;
  
  lVar1 = param_1 + 2;
  if (3 < lVar1) {
    lVar1 = param_1 + -2;
  }
  return lVar1;
}

// --------------------------------------------------

// Function: add_cliff_edge
// Address: 00510430
long __thiscall
TRIBE_Map::add_cliff_edge
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4,long param_5)
{
  int iVar1;
  TRIBE_Cliff_Info TVar2;
  TRIBE_Cliff_Info TVar3;
  TRIBE_Cliff_Info TVar4;
  TRIBE_Cliff_Info TVar5;
  TRIBE_Cliff_Info TVar6;
  TRIBE_Cliff_Info TVar7;
  TRIBE_Cliff_Info TVar8;
  TRIBE_Cliff_Info TVar9;
  TRIBE_Cliff_Info TVar10;
  TRIBE_Cliff_Info TVar11;
  uchar uVar12;
  RGE_Static_Object *pRVar13;
  int iVar14;
  int iVar15;
  long *plVar16;
  int iVar17;
  bool bVar18;
  int iVar19;
  long possible_facing1;
  long possible_direction1;
  long possible_facing2;
  long possible_direction2;
  int local_18;
  TRIBE_Cliff_Info cliff_info;
  long lStack_4;
  
  cliff_info.info[0] = (long)this;
  pRVar13 = find_cliff(this,param_1,param_2);
  get_cliff_info(this,(TRIBE_Cliff_Info *)(cliff_info.info + 1),pRVar13);
  iVar17 = -1;
  possible_direction1 = 0;
  iVar19 = cliff_info.info[param_3 + 1];
  possible_facing2 = -1;
  local_18 = -1;
  possible_direction2 = 0;
  if (iVar19 != 0) {
    if (param_4 == 0) {
      return iVar19;
    }
    if (param_4 == iVar19) {
      return param_4;
    }
  }
  if (pRVar13 != (RGE_Static_Object *)0x0) {
    iVar19 = -1;
    while( true ) {
      do {
        iVar1 = this->_padding_;
        iVar14 = __ftol();
        iVar14 = iVar19 + iVar14;
        iVar15 = __ftol();
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4) + 0x6c),
                   iVar17 + iVar15,iVar14);
        iVar19 = iVar19 + 1;
        this = (TRIBE_Map *)cliff_info.info[0];
      } while (iVar19 < 2);
      iVar17 = iVar17 + 1;
      if (1 < iVar17) break;
      iVar19 = -1;
    }
    (**(code **)pRVar13->_padding_)(1);
    this = (TRIBE_Map *)cliff_info.info[0];
  }
  if (param_5 == param_3) {
    param_5 = -1;
  }
  if (param_5 < 0) {
    iVar17 = 0;
    iVar19 = 0;
    plVar16 = cliff_info.info;
    do {
      plVar16 = plVar16 + 1;
      if ((*plVar16 != 0) && (iVar19 != param_3)) {
        iVar17 = iVar17 + 1;
      }
      iVar19 = iVar19 + 1;
    } while (iVar19 < 4);
    if (iVar17 == 2) {
      iVar19 = 0;
      plVar16 = cliff_info.info;
      do {
        plVar16 = plVar16 + 1;
        iVar17 = *plVar16;
        if ((iVar17 != 0) && (iVar19 != param_3)) {
          iVar1 = iVar19;
          if (possible_facing2 < 0) {
            possible_direction1 = iVar17;
            possible_facing2 = iVar19;
            iVar17 = possible_direction2;
            iVar1 = local_18;
          }
          local_18 = iVar1;
          possible_direction2 = iVar17;
          *plVar16 = 0;
        }
        iVar19 = iVar19 + 1;
      } while (iVar19 < 4);
    }
  }
  else {
    iVar19 = 0;
    plVar16 = cliff_info.info;
    do {
      plVar16 = plVar16 + 1;
      if (iVar19 != param_5) {
        remove_cliff_edge(this,param_1,param_2,iVar19);
        *plVar16 = 0;
      }
      iVar19 = iVar19 + 1;
    } while (iVar19 < 4);
  }
  if (param_4 == 0) {
    param_4 = 1;
    bVar18 = false;
    cliff_info.info[param_3 + 1] = 1;
    if (-1 < possible_facing2) {
      cliff_info.info[possible_facing2 + 1] = possible_direction1;
      TVar5.info[1] = cliff_info.info[2];
      TVar5.info[0] = cliff_info.info[1];
      TVar5.info[2] = cliff_info.info[3];
      TVar5.info[3] = lStack_4;
      uVar12 = check_cliff_valid(this,TVar5);
      if (uVar12 == '\0') {
        cliff_info.info[possible_facing2 + 1] = 0;
      }
      else {
        bVar18 = true;
        possible_direction1 = 0;
      }
    }
    if (!bVar18) {
      bVar18 = false;
      if (-1 < local_18) {
        cliff_info.info[local_18 + 1] = possible_direction2;
        TVar6.info[1] = cliff_info.info[2];
        TVar6.info[0] = cliff_info.info[1];
        TVar6.info[2] = cliff_info.info[3];
        TVar6.info[3] = lStack_4;
        uVar12 = check_cliff_valid(this,TVar6);
        if (uVar12 == '\0') {
          cliff_info.info[local_18 + 1] = 0;
        }
        else {
          bVar18 = true;
          possible_direction2 = 0;
        }
      }
      if ((!bVar18) &&
         (TVar7.info[1] = cliff_info.info[2], TVar7.info[0] = cliff_info.info[1],
         TVar7.info[2] = cliff_info.info[3], TVar7.info[3] = lStack_4,
         uVar12 = check_cliff_valid(this,TVar7), uVar12 == '\0')) {
        cliff_info.info[param_3 + 1] = -1;
        param_4 = -1;
        bVar18 = false;
        if (-1 < possible_facing2) {
          cliff_info.info[possible_facing2 + 1] = possible_direction1;
          TVar8.info[1] = cliff_info.info[2];
          TVar8.info[0] = cliff_info.info[1];
          TVar8.info[2] = cliff_info.info[3];
          TVar8.info[3] = lStack_4;
          uVar12 = check_cliff_valid(this,TVar8);
          if (uVar12 == '\0') {
            cliff_info.info[possible_facing2 + 1] = 0;
          }
          else {
            bVar18 = true;
            possible_direction1 = 0;
          }
        }
        if (!bVar18) {
          bVar18 = false;
          if (-1 < local_18) {
            cliff_info.info[local_18 + 1] = possible_direction2;
            TVar9.info[1] = cliff_info.info[2];
            TVar9.info[0] = cliff_info.info[1];
            TVar9.info[2] = cliff_info.info[3];
            TVar9.info[3] = lStack_4;
            uVar12 = check_cliff_valid(this,TVar9);
            if (uVar12 == '\0') {
              cliff_info.info[local_18 + 1] = 0;
            }
            else {
              bVar18 = true;
              possible_direction2 = 0;
            }
          }
          if ((!bVar18) &&
             (TVar10.info[1] = cliff_info.info[2], TVar10.info[0] = cliff_info.info[1],
             TVar10.info[2] = cliff_info.info[3], TVar10.info[3] = lStack_4,
             uVar12 = check_cliff_valid(this,TVar10), uVar12 == '\0')) {
            plVar16 = cliff_info.info;
            iVar19 = 0;
            do {
              plVar16 = plVar16 + 1;
              if ((iVar19 != param_3) && (*plVar16 != 0)) {
                remove_cliff_edge(this,param_1,param_2,iVar19);
                *plVar16 = 0;
              }
              iVar19 = iVar19 + 1;
            } while (iVar19 < 4);
          }
        }
      }
    }
    if (possible_direction1 != 0) {
      remove_cliff_edge(this,param_1,param_2,possible_facing2);
    }
    if (possible_direction2 != 0) {
      remove_cliff_edge(this,param_1,param_2,local_18);
    }
  }
  else {
    cliff_info.info[param_3 + 1] = param_4;
    if (-1 < possible_facing2) {
      cliff_info.info[possible_facing2 + 1] = possible_direction1;
      TVar2.info[1] = cliff_info.info[2];
      TVar2.info[0] = cliff_info.info[1];
      TVar2.info[2] = cliff_info.info[3];
      TVar2.info[3] = lStack_4;
      uVar12 = check_cliff_valid(this,TVar2);
      if (uVar12 == '\0') {
        cliff_info.info[possible_facing2 + 1] = 0;
        remove_cliff_edge(this,param_1,param_2,possible_facing2);
      }
    }
    if (-1 < local_18) {
      cliff_info.info[local_18 + 1] = possible_direction2;
      TVar3.info[1] = cliff_info.info[2];
      TVar3.info[0] = cliff_info.info[1];
      TVar3.info[2] = cliff_info.info[3];
      TVar3.info[3] = lStack_4;
      uVar12 = check_cliff_valid(this,TVar3);
      if (uVar12 == '\0') {
        cliff_info.info[local_18 + 1] = 0;
        remove_cliff_edge(this,param_1,param_2,local_18);
      }
    }
    TVar4.info[1] = cliff_info.info[2];
    TVar4.info[0] = cliff_info.info[1];
    TVar4.info[2] = cliff_info.info[3];
    TVar4.info[3] = lStack_4;
    uVar12 = check_cliff_valid(this,TVar4);
    if (uVar12 == '\0') {
      iVar19 = 0;
      plVar16 = cliff_info.info;
      do {
        plVar16 = plVar16 + 1;
        if ((iVar19 != param_3) && (*plVar16 != 0)) {
          remove_cliff_edge(this,param_1,param_2,iVar19);
          *plVar16 = 0;
        }
        iVar19 = iVar19 + 1;
      } while (iVar19 < 4);
    }
  }
  TVar11.info[1] = cliff_info.info[2];
  TVar11.info[0] = cliff_info.info[1];
  TVar11.info[2] = cliff_info.info[3];
  TVar11.info[3] = lStack_4;
  make_new_cliff(this,param_1,param_2,TVar11);
  return param_4;
}

// --------------------------------------------------

// Function: delete_cliff
// Address: 00510960
void __thiscall TRIBE_Map::delete_cliff(TRIBE_Map *this,long param_1,long param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  TRIBE_Cliff_Info *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long *plVar7;
  TRIBE_Cliff_Info cliff_info;
  TRIBE_Cliff_Info local_10;
  
  pRVar2 = find_cliff(this,param_1,param_2);
  get_cliff_info(this,(TRIBE_Cliff_Info *)(cliff_info.info + 1),pRVar2);
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    pTVar3 = get_cliff_info(this,&local_10,pRVar2);
    iVar6 = 0;
    cliff_info.info[1] = pTVar3->info[0];
    plVar7 = cliff_info.info;
    cliff_info.info[2] = pTVar3->info[1];
    cliff_info.info[3] = pTVar3->info[2];
    do {
      plVar7 = plVar7 + 1;
      if (*plVar7 != 0) {
        remove_cliff_edge(this,param_1,param_2,iVar6);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
    param_2 = -1;
    do {
      iVar6 = -1;
      do {
        iVar1 = this->_padding_;
        iVar4 = __ftol();
        iVar4 = iVar6 + iVar4;
        iVar5 = __ftol();
        RGE_Tile_List::add_node
                  ((RGE_Tile_List *)
                   (*(int *)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4) + 0x6c),
                   param_2 + iVar5,iVar4);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 2);
      param_2 = param_2 + 1;
    } while (param_2 < 2);
    (**(code **)pRVar2->_padding_)(1);
  }
  return;
}

// --------------------------------------------------

// Function: do_cliff_brush
// Address: 00510a50
uchar __thiscall
TRIBE_Map::do_cliff_brush(TRIBE_Map *this,long param_1,long param_2,uchar param_3,uchar param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uchar uVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = param_1 / 3;
  iVar3 = param_2 / 3;
  uVar4 = RGE_Map::do_cliff_brush((RGE_Map *)this,param_1,param_2,param_3,param_4);
  if (uVar4 != '\0') {
    return '\x01';
  }
  iVar1 = this->old_cliff_x;
  this->safe_cliff_x = iVar10;
  this->safe_cliff_y = iVar3;
  if ((((iVar1 == iVar10) && (this->old_cliff_y == iVar3)) || (this->_padding_ <= iVar10 * 3 + 2))
     || (((this->_padding_ <= iVar3 * 3 + 2 || (iVar10 < 0)) || (iVar3 < 0)))) {
    return '\0';
  }
  iVar9 = iVar3;
  if ((iVar1 != -1) && (iVar2 = this->old_cliff_y, iVar2 != -1)) {
    iVar7 = param_1 + iVar1 * -3;
    uVar6 = param_2 + iVar2 * -3;
    iVar9 = iVar2;
    if ((iVar7 < 3) &&
       (((-1 < iVar7 && (iVar9 = iVar3, iVar10 = iVar1, (int)uVar6 < 3)) && (uVar6 < 0x80000000))))
{
      return '\0';
    }
  }
  if ((iVar10 == iVar1) && (iVar9 == this->old_cliff_y)) {
    return '\x01';
  }
  if (param_4 != '\0') {
    (**(code **)(this->_padding_ + 0x30))(iVar10,iVar9);
    return '\x01';
  }
  if (iVar1 == -1) {
    this->old_cliff_direction = -1;
    this->old_cliff_x = iVar10;
    this->old_cliff_y = iVar9;
    return '\x01';
  }
  if (iVar1 < iVar10) {
    lVar8 = 0;
  }
  else if (iVar10 < iVar1) {
    lVar8 = 2;
  }
  else {
    lVar8 = 1;
    if (iVar9 <= this->old_cliff_y) {
      lVar8 = 3;
    }
  }
  lVar5 = add_cliff_edge(this,iVar1,this->old_cliff_y,lVar8,0,this->old_cliff_direction);
  lVar8 = reverse_cliff_direction(this,lVar8);
  this->old_cliff_direction = lVar8;
  this->old_cliff_x = iVar10;
  this->old_cliff_y = iVar9;
  add_cliff_edge(this,iVar10,iVar9,lVar8,lVar5,-1);
  return '\x01';
}

// --------------------------------------------------

// Function: do_cliff_brush_stroke
// Address: 00510c10
uchar __thiscall
TRIBE_Map::do_cliff_brush_stroke
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6)
{
  if ((this->safe_cliff_x != param_1 / 3) || (this->safe_cliff_y != param_2 / 3)) {
    this->old_cliff_x = -1;
    this->old_cliff_y = -1;
    this->safe_cliff_x = -1;
    this->safe_cliff_y = -1;
    this->old_cliff_direction = -1;
  }
  RGE_Map::do_cliff_brush_stroke((RGE_Map *)this,param_1,param_2,param_3,param_4,param_5,param_6);
  return '\x01';
}

// --------------------------------------------------

// Function: water
// Address: 00510c90
uchar __thiscall TRIBE_Map::water(TRIBE_Map *this,uchar param_1)
{
  if (param_1 == '\x01') {
    return param_1;
  }
  if (param_1 == '\x16') {
    return '\x01';
  }
  return param_1 == '\x04';
}

// --------------------------------------------------

// Function: clean_borders
// Address: 00510cb0
void __thiscall
TRIBE_Map::clean_borders
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  uchar uVar5;
  long lVar6;
  int iVar7;
  
  iVar1 = this->_padding_ + -1;
  iVar2 = this->_padding_ + -1;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->_padding_ <= param_3) {
    param_3 = iVar2;
  }
  if (this->_padding_ <= param_4) {
    param_4 = iVar1;
  }
  for (; param_2 <= param_4; param_2 = param_2 + 1) {
    if (param_1 <= param_3) {
      iVar7 = param_1 * 0x18;
      lVar6 = param_1;
      do {
        bVar4 = *(byte *)(iVar7 + 5 + *(int *)(this->_padding_ + param_2 * 4)) & 0x1f;
        if (bVar4 == 2) {
          bVar3 = false;
          if (((0 < param_2) &&
              (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + param_2 * 4 + -4) + 5 + iVar7
                                           ) & 0x1f), uVar5 != '\0')) ||
             ((param_2 < iVar1 &&
              (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + 4 + param_2 * 4) + 5 + iVar7)
                                  & 0x1f), uVar5 != '\0')))) {
            bVar3 = true;
          }
          if ((0 < iVar7) &&
             (((uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + param_2 * 4) + -0x13 + iVar7
                                            ) & 0x1f), uVar5 != '\0' ||
               ((0 < param_2 &&
                (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + -4 + param_2 * 4) + -0x13 +
                                             iVar7) & 0x1f), uVar5 != '\0')))) ||
              ((param_2 < iVar1 &&
               (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + 4 + param_2 * 4) + -0x13 +
                                            iVar7) & 0x1f), uVar5 != '\0')))))) {
            bVar3 = true;
          }
          if ((lVar6 < iVar2) &&
             (((uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + param_2 * 4) + 0x1d + iVar7)
                                   & 0x1f), uVar5 != '\0' ||
               ((0 < param_2 &&
                (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + -4 + param_2 * 4) + 0x1d +
                                             iVar7) & 0x1f), uVar5 != '\0')))) ||
              ((param_2 < iVar1 &&
               (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + 4 + param_2 * 4) + 0x1d +
                                            iVar7) & 0x1f), uVar5 != '\0')))))) {
            bVar3 = true;
          }
          if (!bVar3) {
            RGE_Map::set_terrain
                      ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,(short)lVar6,(short)param_2
                       ,param_5,0,0);
          }
        }
        else {
          uVar5 = water(this,bVar4);
          if (uVar5 == '\0') {
            bVar3 = false;
            if (((0 < param_2) &&
                (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + -4 + param_2 * 4) + 5 +
                                             iVar7) & 0x1f), uVar5 != '\0')) ||
               ((param_2 < iVar1 &&
                (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + 4 + param_2 * 4) + 5 +
                                             iVar7) & 0x1f), uVar5 != '\0')))) {
              bVar3 = true;
            }
            if ((0 < iVar7) &&
               (((uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + param_2 * 4) + -0x13 +
                                              iVar7) & 0x1f), uVar5 != '\0' ||
                 ((0 < param_2 &&
                  (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + -4 + param_2 * 4) + -0x13
                                               + iVar7) & 0x1f), uVar5 != '\0')))) ||
                ((param_2 < iVar1 &&
                 (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + 4 + param_2 * 4) + -0x13 +
                                              iVar7) & 0x1f), uVar5 != '\0')))))) {
              bVar3 = true;
            }
            if ((lVar6 < iVar2) &&
               (((uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + param_2 * 4) + 0x1d +
                                              iVar7) & 0x1f), uVar5 != '\0' ||
                 ((0 < param_2 &&
                  (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + -4 + param_2 * 4) + 0x1d
                                               + iVar7) & 0x1f), uVar5 != '\0')))) ||
                ((param_2 < iVar1 &&
                 (uVar5 = water(this,*(byte *)(*(int *)(this->_padding_ + 4 + param_2 * 4) + 0x1d +
                                              iVar7) & 0x1f), uVar5 != '\0')))))) {
              bVar3 = true;
            }
            if (bVar3) {
              RGE_Map::set_terrain
                        ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,(short)lVar6,
                         (short)param_2,'\x02',0,0);
            }
          }
        }
        lVar6 = lVar6 + 1;
        iVar7 = iVar7 + 0x18;
      } while (lVar6 <= param_3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: do_terrain_brush_check
// Address: 00511000
uchar __thiscall TRIBE_Map::do_terrain_brush_check(TRIBE_Map *this,long param_1,long param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(this->_padding_ + param_2 * 4) + param_1 * 0x18;
  if ((0 < param_1) && (*(char *)(iVar2 + -0x14) != '\0')) {
    return '\0';
  }
  iVar3 = this->_padding_;
  iVar1 = iVar3 + -1;
  if ((param_1 < iVar1) && (*(char *)(iVar2 + 0x1c) != '\0')) {
    return '\0';
  }
  if (0 < param_2) {
    iVar4 = iVar2 + iVar3 * -0x18;
    if (*(char *)(iVar4 + 4) != '\0') {
      return '\0';
    }
    if ((0 < param_1) && (*(char *)(iVar4 + -0x14) != '\0')) {
      return '\0';
    }
    if ((param_1 < iVar1) && (*(char *)(iVar4 + 0x1c) != '\0')) {
      return '\0';
    }
  }
  if (param_2 < this->_padding_ + -1) {
    iVar4 = iVar2 + iVar3 * 0x18;
    if (*(char *)(iVar2 + 4 + iVar3 * 0x18) != '\0') {
      return '\0';
    }
    if ((0 < param_1) && (*(char *)(iVar4 + -0x14) != '\0')) {
      return '\0';
    }
    if ((param_1 < iVar1) && (*(char *)(iVar4 + 0x1c) != '\0')) {
      return '\0';
    }
  }
  return '\x01';
}

// --------------------------------------------------

// Function: tribe_clean_elevation
// Address: 005110e0
void __thiscall
TRIBE_Map::tribe_clean_elevation
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4)
{
  uchar uVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->_padding_ <= param_3) {
    param_3 = this->_padding_ + -1;
  }
  if (this->_padding_ <= param_4) {
    param_4 = this->_padding_ + -1;
  }
  for (; param_2 <= param_4; param_2 = param_2 + 1) {
    if (param_1 <= param_3) {
      iVar2 = param_1 * 0x18;
      lVar3 = param_1;
      do {
        uVar1 = water(this,*(byte *)(*(int *)(this->_padding_ + param_2 * 4) + 5 + iVar2) & 0x1f);
        if ((uVar1 != '\0') && (uVar1 = do_terrain_brush_check(this,lVar3,param_2), uVar1 == '\0'))
{
          RGE_Map::set_terrain
                    ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,(short)lVar3,(short)param_2,
                     '\0',0,0);
        }
        lVar3 = lVar3 + 1;
        iVar2 = iVar2 + 0x18;
      } while (lVar3 <= param_3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: tribe_clean_terrain
// Address: 005111a0
void __thiscall
TRIBE_Map::tribe_clean_terrain
          (TRIBE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6)
{
  short sVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  uchar uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  RGE_Game_World *pRVar20;
  short sVar21;
  short sVar22;
  uchar change_flag;
  RGE_Tile *til;
  short place2;
  short place4;
  short place6;
  short place8;
  short place3;
  short place5;
  short place7;
  long pass_index;
  short offset2;
  short local_1c;
  short offset1;
  short offset3;
  short offset7;
  short offset5;
  short local_8;
  
  sVar1 = (short)this->_padding_;
  offset3 = -1 - sVar1;
  local_1c = -sVar1;
  offset7 = 1 - sVar1;
  local_8 = sVar1 + 1;
  offset5 = sVar1 + -1;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->_padding_ <= param_3) {
    param_3 = this->_padding_ + -1;
  }
  iVar13 = param_4;
  iVar15 = param_3;
  iVar16 = param_2;
  iVar18 = param_1;
  if (this->_padding_ <= param_4) {
    iVar13 = this->_padding_ + -1;
    param_4 = iVar13;
  }
  do {
    bVar4 = false;
    if (0 < iVar18) {
      iVar18 = iVar18 + -1;
      param_1 = iVar18;
    }
    if (0 < iVar16) {
      iVar16 = iVar16 + -1;
      param_2 = iVar16;
    }
    if (iVar15 < this->_padding_ + -1) {
      iVar15 = iVar15 + 1;
      param_3 = iVar15;
    }
    if (iVar13 < this->_padding_ + -1) {
      iVar13 = iVar13 + 1;
      param_4 = iVar13;
    }
    _offset2 = 0;
    iVar17 = iVar16;
    do {
      iVar16 = iVar17;
      if (iVar17 <= iVar13) {
        iVar14 = iVar18 * 0x18;
        iVar19 = iVar18;
        do {
          iVar13 = *(int *)(this->_padding_ + iVar17 * 4) + iVar14;
          iVar18 = iVar19;
          if (iVar19 <= iVar15) {
            do {
              uVar12 = water(this,*(byte *)(iVar13 + 5) & 0x1f);
              if (uVar12 == '\0') {
                bVar3 = false;
                bVar5 = false;
                bVar9 = false;
                bVar7 = false;
                bVar11 = false;
                bVar6 = false;
                bVar10 = false;
                bVar8 = false;
                if ((0 < iVar17) &&
                   (uVar12 = water(this,*(byte *)(iVar13 + 5 + local_1c * 0x18) & 0x1f),
                   uVar12 != '\0')) {
                  bVar5 = true;
                }
                if ((iVar17 < this->_padding_ + -1) &&
                   (uVar12 = water(this,*(byte *)(iVar13 + 5 + sVar1 * 0x18) & 0x1f), uVar12 != '\0'
                   )) {
                  bVar6 = true;
                }
                if ((0 < iVar19) &&
                   (uVar12 = water(this,*(byte *)(iVar13 + -0x13) & 0x1f), uVar12 != '\0')) {
                  bVar8 = true;
                }
                if ((iVar19 < this->_padding_ + -1) &&
                   (uVar12 = water(this,*(byte *)(iVar13 + 0x1d) & 0x1f), uVar12 != '\0')) {
                  bVar7 = true;
                }
                if (0 < iVar17) {
                  bVar3 = false;
                  if ((0 < iVar19) &&
                     (uVar12 = water(this,*(byte *)(iVar13 + 5 + offset3 * 0x18) & 0x1f),
                     uVar12 != '\0')) {
                    bVar3 = true;
                  }
                  if ((iVar19 < this->_padding_ + -1) &&
                     (uVar12 = water(this,*(byte *)(iVar13 + 5 + offset7 * 0x18) & 0x1f),
                     uVar12 != '\0')) {
                    bVar9 = true;
                  }
                }
                if (iVar17 < this->_padding_ + -1) {
                  bVar10 = false;
                  if ((0 < iVar19) &&
                     (uVar12 = water(this,*(byte *)(iVar13 + 5 + offset5 * 0x18) & 0x1f),
                     uVar12 != '\0')) {
                    bVar10 = true;
                  }
                  if ((iVar19 < this->_padding_ + -1) &&
                     (uVar12 = water(this,*(byte *)(iVar13 + 5 + local_8 * 0x18) & 0x1f),
                     uVar12 != '\0')) {
                    bVar11 = true;
                  }
                }
                bVar2 = false;
                if (_offset2 == 0) {
                  if (((bVar5) && (bVar6)) || ((bVar7 && (bVar8)))) {
LAB_005115bc:
                    bVar2 = true;
                  }
LAB_005115be:
                  if (!bVar2) goto LAB_0051172c;
                }
                else {
                  if (bVar3) {
                    if (((((bVar9) && (!bVar5)) || ((bVar7 && (!bVar9)))) || ((bVar10 && (!bVar8))))
                       || ((bVar6 && (!bVar10)))) {
                      bVar2 = true;
                    }
                    else if (((bVar11) && (!bVar6)) && (!bVar7)) {
                      bVar2 = true;
                    }
                  }
                  if (((bVar9) && (!bVar2)) &&
                     (((((bVar3 && (!bVar5)) || ((bVar8 && (!bVar3)))) || ((bVar11 && (!bVar7)))) ||
                      (((bVar6 && (!bVar11)) || ((bVar10 && ((!bVar8 && (!bVar6)))))))))) {
                    bVar2 = true;
                  }
                  if (((bVar11) && (!bVar2)) &&
                     ((((bVar9 && (!bVar7)) || (((bVar5 && (!bVar9)) || ((bVar10 && (!bVar6)))))) ||
                      (((bVar8 && (!bVar10)) || ((bVar3 && ((!bVar8 && (!bVar5)))))))))) {
                    bVar2 = true;
                  }
                  if (!bVar10) goto LAB_005115be;
                  if (!bVar2) {
                    if ((((bVar3) && (!bVar8)) || ((bVar5 && (!bVar3)))) ||
                       ((((bVar11 && (!bVar6)) || ((bVar7 && (!bVar11)))) ||
                        (((bVar9 && (!bVar7)) && (!bVar5)))))) goto LAB_005115bc;
                    goto LAB_005115be;
                  }
                }
                uVar12 = water(this,param_6);
                sVar22 = (short)iVar17;
                if (uVar12 == '\0') {
                  sVar21 = (short)iVar19;
                  if (bVar3) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,sVar21 + -1,
                               sVar22 + -1,param_6,0,0);
                  }
                  if (bVar5) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,sVar21,sVar22 + -1,
                               param_6,0,0);
                  }
                  if (bVar9) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,sVar21 + 1,
                               sVar22 + -1,param_6,0,0);
                  }
                  if (bVar7) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,sVar21 + 1,sVar22,
                               param_6,0,0);
                  }
                  if (bVar11) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,sVar21 + 1,
                               sVar22 + 1,param_6,0,0);
                  }
                  if (bVar6) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,sVar21,sVar22 + 1,
                               param_6,0,0);
                  }
                  if (bVar10) {
                    RGE_Map::set_terrain
                              ((RGE_Map *)this,(RGE_Game_World *)this->_padding_,sVar21 + -1,
                               sVar22 + 1,param_6,0,0);
                  }
                  if (bVar8) {
                    pRVar20 = (RGE_Game_World *)this->_padding_;
                    iVar15 = iVar19 + -1;
                    goto LAB_00511720;
                  }
                }
                else {
                  uVar12 = do_terrain_brush_check(this,iVar19,iVar17);
                  if (uVar12 == '\0') goto LAB_0051172c;
                  pRVar20 = (RGE_Game_World *)this->_padding_;
                  iVar15 = iVar19;
LAB_00511720:
                  RGE_Map::set_terrain((RGE_Map *)this,pRVar20,(short)iVar15,sVar22,param_6,0,0);
                }
                bVar4 = true;
              }
LAB_0051172c:
              iVar13 = iVar13 + 0x18;
              iVar19 = iVar19 + 1;
              iVar15 = param_3;
              iVar18 = param_1;
            } while (iVar19 <= param_3);
          }
          iVar17 = iVar17 + 1;
          iVar13 = param_4;
          iVar16 = param_2;
          iVar19 = iVar18;
        } while (iVar17 <= param_4);
      }
      _offset2 = _offset2 + 1;
      iVar17 = iVar16;
    } while (_offset2 < 2);
    if (!bVar4) {
      clean_borders(this,iVar18,param_2,iVar15,param_4,param_6);
      RGE_Map::set_terrain
                ((RGE_Map *)this,(RGE_Player *)0x0,(RGE_Game_World *)0x0,(short)iVar18,
                 (short)param_2,(short)iVar15,(short)param_4,'\0','\0',0);
      return;
    }
  } while( true );
}

// --------------------------------------------------

