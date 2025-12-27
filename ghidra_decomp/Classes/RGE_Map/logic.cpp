// Class: RGE_Map
// Function: RGE_Map
// Address: 00455000
/* public: __thiscall RGE_Map::RGE_Map(int,class RGE_Sound * *,unsigned char) */

RGE_Map * __thiscall RGE_Map::RGE_Map(RGE_Map *this,int param_1,RGE_Sound **param_2,uchar param_3)
{
  RGE_Game_World *pRVar1;
  
  this->_padding_ = (int)&_vftable_;
  this->map_zones = (RGE_Zone_Map_List *)0x0;
  rge_read(param_1,this,0x8dd0);
  pRVar1 = rge_base_game->world;
  this->map = (RGE_Tile *)0x0;
  this->game_world = pRVar1;
  this->search_map = (uchar *)0x0;
  this->map_row_offset = (RGE_Tile **)0x0;
  this->search_map_rows = (uchar **)0x0;
  load_terrain_types(this,param_2);
  load_border_types(this,param_2);
  init_tile_sizes(this);
  if (param_3 != '\0') {
    data_load_random_map(this,param_1);
  }
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00455080
/* public: virtual void * __thiscall RGE_Map::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Map::_vector_deleting_destructor_(RGE_Map *this,uint param_1)
{
  ~RGE_Map(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Map
// Address: 004550a0
/* public: __thiscall RGE_Map::RGE_Map(char *,char *,char *,short,short,short,class RGE_Sound * *)
    */

RGE_Map * __thiscall
RGE_Map::RGE_Map(RGE_Map *this,char *param_1,char *param_2,char *param_3,short param_4,short param_5
                ,short param_6,RGE_Sound **param_7)
{
  short *psVar1;
  RGE_Sound **ppRVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  this->_padding_ = (int)&_vftable_;
  this->map_zones = (RGE_Zone_Map_List *)0x0;
  this->random_map = (RGE_RMM_Database_Controller *)0x0;
  this->game_world = rge_base_game->world;
  this->tile_width = param_4;
  this->tile_half_width = param_4 / 2;
  this->tile_height = param_5;
  this->tile_half_height = param_5 / 2;
  this->elev_height = param_6;
  this->map_width = 0;
  this->map_height = 0;
  this->world_width = 0;
  this->world_height = 0;
  set_tile_size(this,'\0',param_4,param_5,0);
  set_tile_size(this,'\x01',this->tile_width,this->elev_height,-100);
  set_tile_size(this,'\x02',this->tile_width,this->elev_height + this->tile_height,100);
  set_tile_size(this,'\x03',this->tile_width,this->tile_height,-100);
  set_tile_size(this,'\x04',this->tile_width,this->tile_height,-100);
  set_tile_size(this,'\x05',this->tile_width,this->elev_height,-100);
  set_tile_size(this,'\x06',this->tile_width,this->elev_height + this->tile_height,100);
  set_tile_size(this,'\a',this->tile_width,this->elev_height,-100);
  set_tile_size(this,'\b',this->tile_width,this->elev_height + this->tile_height,100);
  set_tile_size(this,'\t',this->tile_width,this->elev_height,-100);
  set_tile_size(this,'\n',this->tile_width,this->elev_height + this->tile_height,100);
  set_tile_size(this,'\v',this->tile_width,this->tile_height,-100);
  set_tile_size(this,'\f',this->tile_width,this->tile_height,-100);
  set_tile_size(this,'\r',this->tile_width,this->elev_height,-100);
  set_tile_size(this,'\x0e',this->tile_width,this->elev_height + this->tile_height,100);
  set_tile_size(this,'\x0f',this->tile_width,this->tile_height,100);
  set_tile_size(this,'\x10',this->tile_width,this->tile_height,100);
  set_tile_size(this,'\x11',this->tile_half_width,this->tile_height,0);
  set_tile_size(this,'\x12',this->tile_half_width,this->tile_height,0);
  this->cur_row = 0;
  this->cur_col = 0;
  this->num_terrain = 0;
  this->max_terrain = 0;
  this->block_beg_row = 0;
  this->block_end_row = 0;
  this->block_beg_col = 0;
  this->block_end_col = 0;
  this->any_frame_change = '\0';
  this->map_visible_flag = '\0';
  this->fog_flag = '\x01';
  iVar5 = 0x20;
  psVar4 = &this->terrain_types[0].rows;
  do {
    psVar4[0x6d] = 0;
    *psVar4 = 0;
    psVar4[1] = 0;
    psVar1 = psVar4 + 0x40;
    iVar3 = 0x1e;
    do {
      psVar1[-0x1e] = 0;
      *psVar1 = 0;
      psVar1 = psVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    psVar1 = psVar4;
    for (iVar3 = 0x10; psVar1 = psVar1 + 2, iVar3 != 0; iVar3 = iVar3 + -1) {
      psVar1[0] = 0;
      psVar1[1] = 0;
    }
    *(TShape **)(psVar4 + -0x4d) = (TShape *)0x0;
    *(RGE_Sound **)(psVar4 + -0x4b) = (RGE_Sound *)0x0;
    iVar5 = iVar5 + -1;
    psVar4 = psVar4 + 0xcc;
  } while (iVar5 != 0);
  ppRVar2 = &this->border_types[0xf].sound;
  iVar5 = 0x10;
  do {
    ppRVar2[-1] = (RGE_Sound *)0x0;
    *ppRVar2 = (RGE_Sound *)0x0;
    ppRVar2 = ppRVar2 + -0x168;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  load_terrain_types(this,param_2,param_7);
  load_border_types(this,param_1,param_7);
  this->map = (RGE_Tile *)0x0;
  this->search_map = (uchar *)0x0;
  this->map_row_offset = (RGE_Tile **)0x0;
  this->search_map_rows = (uchar **)0x0;
  this->unified_vis_map = (RGE_Unified_Visible_Map *)0x0;
  this->unit_manager = (Visible_Unit_Manager *)0x0;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Map
// Address: 00455430
/* public: virtual __thiscall RGE_Map::~RGE_Map(void) */

void __thiscall RGE_Map::~RGE_Map(RGE_Map *this)
{
  RGE_Zone_Map_List *this_00;
  RGE_RMM_Database_Controller *this_01;
  TShape *pTVar1;
  RGE_Unified_Visible_Map *this_02;
  Visible_Unit_Manager *this_03;
  int iVar2;
  TShape **ppTVar3;
  
  this_00 = this->map_zones;
  this->_padding_ = (int)&_vftable_;
  if (this_00 != (RGE_Zone_Map_List *)0x0) {
    RGE_Zone_Map_List::~RGE_Zone_Map_List(this_00);
    operator_delete(this_00);
    this->map_zones = (RGE_Zone_Map_List *)0x0;
  }
  this_01 = this->random_map;
  if (this_01 != (RGE_RMM_Database_Controller *)0x0) {
    RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller(this_01);
    operator_delete(this_01);
    this->random_map = (RGE_RMM_Database_Controller *)0x0;
  }
  if (this->map != (RGE_Tile *)0x0) {
    free(this->map);
  }
  if (this->search_map != (uchar *)0x0) {
    free(this->search_map);
  }
  if (this->map_row_offset != (RGE_Tile **)0x0) {
    free(this->map_row_offset);
  }
  if (this->search_map_rows != (uchar **)0x0) {
    free(this->search_map_rows);
  }
  ppTVar3 = &this->terrain_types[0x1f].shape;
  iVar2 = 0x20;
  do {
    pTVar1 = *ppTVar3;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
      *ppTVar3 = (TShape *)0x0;
    }
    ppTVar3 = ppTVar3 + -0x66;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar3 = &this->border_types[0xf].shape;
  iVar2 = 0x10;
  do {
    pTVar1 = *ppTVar3;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
      *ppTVar3 = (TShape *)0x0;
    }
    ppTVar3 = ppTVar3 + -0x168;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this_02 = this->unified_vis_map;
  if (this_02 != (RGE_Unified_Visible_Map *)0x0) {
    RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(this_02);
    operator_delete(this_02);
  }
  this_03 = this->unit_manager;
  if (this_03 != (Visible_Unit_Manager *)0x0) {
    Visible_Unit_Manager::~Visible_Unit_Manager(this_03);
    operator_delete(this_03);
  }
  return;
}

// --------------------------------------------------

// Function: init_tile_sizes
// Address: 00455570
/* public: void __thiscall RGE_Map::init_tile_sizes(void) */

void __thiscall RGE_Map::init_tile_sizes(RGE_Map *this)
{
  this->tile_width = 0x40;
  this->tile_height = 0x20;
  this->tile_half_width = 0x20;
  this->tile_half_height = 0x10;
  this->elev_height = 0x10;
  set_tile_size(this,'\0',0x40,0x20,0);
  set_tile_size(this,'\x01',this->tile_width,this->elev_height,-8);
  set_tile_size(this,'\x02',this->tile_width,this->elev_height + this->tile_height,8);
  set_tile_size(this,'\x03',this->tile_width,this->tile_height,-8);
  set_tile_size(this,'\x04',this->tile_width,this->tile_height,-8);
  set_tile_size(this,'\x05',this->tile_width,this->elev_height,-8);
  set_tile_size(this,'\x06',this->tile_width,this->elev_height + this->tile_height,8);
  set_tile_size(this,'\a',this->tile_width,this->elev_height,-8);
  set_tile_size(this,'\b',this->tile_width,this->elev_height + this->tile_height,8);
  set_tile_size(this,'\t',this->tile_width,this->elev_height,-8);
  set_tile_size(this,'\n',this->tile_width,this->elev_height + this->tile_height,8);
  set_tile_size(this,'\v',this->tile_width,this->tile_height,-8);
  set_tile_size(this,'\f',this->tile_width,this->tile_height,-8);
  set_tile_size(this,'\r',this->tile_width,this->elev_height,-8);
  set_tile_size(this,'\x0e',this->tile_width,this->elev_height + this->tile_height,8);
  set_tile_size(this,'\x0f',this->tile_width,this->tile_height,8);
  set_tile_size(this,'\x10',this->tile_width,this->tile_height,8);
  set_tile_size(this,'\x11',this->tile_half_width,this->tile_height,0);
  set_tile_size(this,'\x12',this->tile_half_width,this->tile_height,0);
  return;
}

// --------------------------------------------------

// Function: data_load_random_map
// Address: 004557c0
/* public: virtual void __thiscall RGE_Map::data_load_random_map(int) */

void __thiscall RGE_Map::data_load_random_map(RGE_Map *this,int param_1)
{
  RGE_RMM_Database_Controller *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055da9b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_RMM_Database_Controller *)operator_new(0x4f5c);
  local_4 = 0;
  if (pRVar1 == (RGE_RMM_Database_Controller *)0x0) {
    pRVar1 = (RGE_RMM_Database_Controller *)0x0;
  }
  else {
    pRVar1 = (RGE_RMM_Database_Controller *)
             RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(pRVar1,param_1);
  }
  this->random_map = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_random_map
// Address: 00455820
/* public: virtual void __thiscall RGE_Map::load_random_map(char *,char *,char *,char *) */

void __thiscall
RGE_Map::load_random_map(RGE_Map *this,char *param_1,char *param_2,char *param_3,char *param_4)
{
  RGE_RMM_Database_Controller *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dabb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_RMM_Database_Controller *)operator_new(0x4f5c);
  local_4 = 0;
  if (pRVar1 == (RGE_RMM_Database_Controller *)0x0) {
    pRVar1 = (RGE_RMM_Database_Controller *)0x0;
  }
  else {
    pRVar1 = (RGE_RMM_Database_Controller *)
             RGE_RMM_Database_Controller::RGE_RMM_Database_Controller
                       (pRVar1,param_2,param_3,param_4,param_1);
  }
  this->random_map = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: set_map_visible
// Address: 00455890
/* public: void __thiscall RGE_Map::set_map_visible(unsigned char) */

void __thiscall RGE_Map::set_map_visible(RGE_Map *this,uchar param_1)
{
  this->map_visible_flag = param_1;
  return;
}

// --------------------------------------------------

// Function: set_map_fog
// Address: 004558a0
/* public: void __thiscall RGE_Map::set_map_fog(unsigned char) */

void __thiscall RGE_Map::set_map_fog(RGE_Map *this,uchar param_1)
{
  this->fog_flag = param_1;
  return;
}

// --------------------------------------------------

// Function: clear_map
// Address: 004558b0
/* public: void __thiscall RGE_Map::clear_map(class RGE_Player *,class RGE_Game_World *,unsigned
   char,long,long) */

void __thiscall
RGE_Map::clear_map(RGE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2,uchar param_3,
                  long param_4,long param_5)
{
  new_map(this,param_4,param_5);
  if (param_2 != (RGE_Game_World *)0x0) {
    RGE_Game_World::reset_object_count(param_2);
  }
  set_terrain(this,param_1,param_2,0,0,(short)param_4 + -1,(short)param_5 + -1,param_3,'\x01',0);
  if (param_2 != (RGE_Game_World *)0x0) {
    RGE_Game_World::reset_player_visible_maps(param_2);
  }
  return;
}

// --------------------------------------------------

// Function: new_map
// Address: 00455910
/* public: void __thiscall RGE_Map::new_map(long,long) */

void __thiscall RGE_Map::new_map(RGE_Map *this,long param_1,long param_2)
{
  RGE_Player **ppRVar1;
  RGE_Player *pRVar2;
  RGE_Tile *pRVar3;
  uchar *puVar4;
  RGE_Tile **ppRVar5;
  uchar **ppuVar6;
  RGE_Zone_Map_List *pRVar7;
  RGE_Unified_Visible_Map *pRVar8;
  Visible_Unit_Manager *pVVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055daf1;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if ((0 < param_1) && (0 < param_2)) {
    if (this->map != (RGE_Tile *)0x0) {
      if (this->game_world != (RGE_Game_World *)0x0) {
        iVar11 = (int)this->game_world->player_num;
        iVar12 = 0;
        if (0 < iVar11) {
          do {
            ppRVar1 = this->game_world->players;
            if ((ppRVar1 != (RGE_Player **)0x0) &&
               (pRVar2 = ppRVar1[iVar12], pRVar2 != (RGE_Player *)0x0)) {
              RGE_Object_List::removeAllObjects(pRVar2->objects);
              RGE_Object_List::removeAllObjects(this->game_world->players[iVar12]->sleeping_objects)
              ;
              RGE_Object_List::removeAllObjects
                        (this->game_world->players[iVar12]->doppleganger_objects);
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 < iVar11);
        }
      }
      free(this->map);
    }
    if (this->search_map != (uchar *)0x0) {
      free(this->search_map);
    }
    if (this->map_row_offset != (RGE_Tile **)0x0) {
      free(this->map_row_offset);
    }
    if (this->search_map_rows != (uchar **)0x0) {
      free(this->search_map_rows);
    }
    this->map_height = param_2;
    this->map_width = param_1;
    this->world_width = this->tile_width * param_1;
    this->world_height = this->tile_height * param_2;
    pRVar3 = (RGE_Tile *)calloc(param_2 * param_1,0x18);
    this->map = pRVar3;
    puVar4 = (uchar *)calloc(this->map_height * this->map_width,1);
    this->search_map = puVar4;
    ppRVar5 = (RGE_Tile **)calloc(this->map_height + 1,4);
    this->map_row_offset = ppRVar5;
    ppuVar6 = (uchar **)calloc(this->map_height + 1,4);
    this->search_map_rows = ppuVar6;
    iVar11 = 0;
    if (0 < this->map_height) {
      do {
        this->map_row_offset[iVar11] = this->map + iVar11 * this->map_width;
        this->search_map_rows[iVar11] = this->search_map + iVar11 * this->map_width;
        iVar11 = iVar11 + 1;
      } while (iVar11 < this->map_height);
    }
    iVar11 = 0;
    this->map_row_offset[this->map_height] = this->map;
    this->search_map_rows[this->map_height] = this->search_map;
    if (0 < this->map_height) {
      do {
        iVar12 = 0;
        if (0 < this->map_width) {
          iVar10 = 0;
          do {
            iVar12 = iVar12 + 1;
            (&this->map_row_offset[iVar11]->field_0x5)[iVar10] =
                 (&this->map_row_offset[iVar11]->field_0x5)[iVar10] & 0x1f | 0x20;
            iVar10 = iVar10 + 0x18;
          } while (iVar12 < this->map_width);
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < this->map_height);
    }
    set_map_screen_pos(this,0,0,this->map_width + -1,this->map_height + -1);
    pRVar7 = this->map_zones;
    if (pRVar7 != (RGE_Zone_Map_List *)0x0) {
      RGE_Zone_Map_List::~RGE_Zone_Map_List(pRVar7);
      operator_delete(pRVar7);
    }
    pRVar7 = (RGE_Zone_Map_List *)operator_new(0xc);
    local_4 = 0;
    if (pRVar7 == (RGE_Zone_Map_List *)0x0) {
      pRVar7 = (RGE_Zone_Map_List *)0x0;
    }
    else {
      pRVar7 = (RGE_Zone_Map_List *)RGE_Zone_Map_List::RGE_Zone_Map_List(pRVar7,this);
    }
    pRVar8 = this->unified_vis_map;
    local_4 = 0xffffffff;
    this->map_zones = pRVar7;
    if (pRVar8 != (RGE_Unified_Visible_Map *)0x0) {
      RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(pRVar8);
      operator_delete(pRVar8);
    }
    pRVar8 = (RGE_Unified_Visible_Map *)operator_new(0xc);
    local_4 = 1;
    if (pRVar8 == (RGE_Unified_Visible_Map *)0x0) {
      pRVar8 = (RGE_Unified_Visible_Map *)0x0;
    }
    else {
      pRVar8 = (RGE_Unified_Visible_Map *)
               RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(pRVar8,param_1,param_2);
    }
    pVVar9 = this->unit_manager;
    local_4 = 0xffffffff;
    this->unified_vis_map = pRVar8;
    if (pVVar9 != (Visible_Unit_Manager *)0x0) {
      Visible_Unit_Manager::~Visible_Unit_Manager(pVVar9);
      operator_delete(pVVar9);
    }
    pVVar9 = (Visible_Unit_Manager *)operator_new(0x24);
    local_4 = 2;
    if (pVVar9 == (Visible_Unit_Manager *)0x0) {
      pVVar9 = (Visible_Unit_Manager *)0x0;
    }
    else {
      pVVar9 = (Visible_Unit_Manager *)
               Visible_Unit_Manager::Visible_Unit_Manager
                         (pVVar9,(int)this->game_world->player_num,0x40);
    }
    this->unit_manager = pVVar9;
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: clear_map
// Address: 00455c20
/* public: void __thiscall RGE_Map::clear_map(unsigned char,unsigned char) */

void __thiscall RGE_Map::clear_map(RGE_Map *this,uchar param_1,uchar param_2)
{
  RGE_Tile *pRVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < this->map_height) {
    do {
      iVar3 = 0;
      pRVar1 = this->map_row_offset[iVar2];
      if (0 < this->map_width) {
        do {
          pRVar1->tile_type = '\0';
          pRVar1->field_0x6 = 0;
          pRVar1->screen_xpos = 0;
          pRVar1->field_0x5 = param_1 & 0x1f | param_2 << 5;
          pRVar1->screen_ypos = 0;
          pRVar1->last_drawn_as = '\0';
          pRVar1->last_drawn_shape = 0xff;
          pRVar1->draw_as = '\0';
          pRVar1->draw_attribute = '\0';
          pRVar1->last_drawn_shape2 = 0xff;
          pRVar1 = pRVar1 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < this->map_width);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < this->map_height);
  }
  set_map_screen_pos(this,0,0,this->map_width + -1,this->map_height + -1);
  return;
}

// --------------------------------------------------

// Function: request_redraw
// Address: 00455cb0
/* public: void __thiscall RGE_Map::request_redraw(int,int,int,int,unsigned char) */

void __thiscall
RGE_Map::request_redraw(RGE_Map *this,int param_1,int param_2,int param_3,int param_4,uchar param_5)
{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_4;
  iVar4 = param_1;
  if (param_3 < param_1) {
    iVar4 = param_3;
    param_3 = param_1;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = iVar3;
  }
  if ((((-1 < param_3) && (-1 < param_4)) && (iVar3 = this->map_width, iVar4 < iVar3)) &&
     (iVar1 = this->map_height, param_2 < iVar1)) {
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (iVar3 <= param_3) {
      param_3 = iVar3 + -1;
    }
    if (iVar1 <= param_4) {
      param_4 = iVar1 + -1;
    }
    for (; param_2 <= param_4; param_2 = param_2 + 1) {
      if (iVar4 <= param_3) {
        puVar2 = &this->map_row_offset[param_2][iVar4].draw_attribute;
        iVar3 = (param_3 - iVar4) + 1;
        do {
          puVar2[-3] = 0xcc;
          *puVar2 = param_5;
          puVar2 = puVar2 + 0x18;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: clear_map_view_info
// Address: 00455d60
/* public: void __thiscall RGE_Map::clear_map_view_info(void) */

void __thiscall RGE_Map::clear_map_view_info(RGE_Map *this)
{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < this->map_height) {
    do {
      iVar2 = 0;
      if (0 < this->map_width) {
        puVar1 = &this->map_row_offset[iVar3]->last_drawn_shape;
        do {
          puVar1[-1] = '\0';
          *puVar1 = 0xff;
          puVar1[1] = '\0';
          puVar1[2] = '\0';
          puVar1[3] = 0xff;
          puVar1 = puVar1 + 0x18;
          iVar2 = iVar2 + 1;
        } while (iVar2 < this->map_width);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->map_height);
  }
  return;
}

// --------------------------------------------------

// Function: coordinate_map
// Address: 00455db0
/* public: void __thiscall RGE_Map::coordinate_map(void) */

void __thiscall RGE_Map::coordinate_map(RGE_Map *this)
{
  set_map_screen_pos(this,0,0,this->map_width + -1,this->map_height + -1);
  return;
}

// --------------------------------------------------

// Function: set_map_screen_pos
// Address: 00455dd0
/* public: void __thiscall RGE_Map::set_map_screen_pos(int,int,int,int) */

void __thiscall
RGE_Map::set_map_screen_pos(RGE_Map *this,int param_1,int param_2,int param_3,int param_4)
{
  RGE_Tile *pRVar1;
  int iVar2;
  
  if (param_1 < 0) {
    param_1 = 0;
    iVar2 = param_1;
  }
  else {
    iVar2 = this->map_width + -1;
    if (param_1 <= iVar2) goto LAB_00455df4;
  }
  param_1 = iVar2;
LAB_00455df4:
  if (param_2 < 0) {
    param_2 = 0;
  }
  else {
    iVar2 = this->map_height + -1;
    if (iVar2 < param_2) {
      param_2 = iVar2;
    }
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  else {
    iVar2 = this->map_width + -1;
    if (iVar2 < param_3) {
      param_3 = iVar2;
    }
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  else {
    iVar2 = this->map_height + -1;
    if (iVar2 < param_4) {
      param_4 = iVar2;
    }
  }
  for (; param_2 <= param_4; param_2 = param_2 + 1) {
    pRVar1 = this->map_row_offset[param_2] + param_1;
    for (iVar2 = param_1; iVar2 <= param_3; iVar2 = iVar2 + 1) {
      pRVar1->screen_xpos = (short)(param_2 + iVar2) * this->tile_half_width;
      pRVar1->screen_ypos =
           ((short)param_2 - (short)iVar2) * this->tile_half_height -
           (ushort)((byte)pRVar1->field_0x5 >> 5) * this->elev_height;
      switch(pRVar1->tile_type) {
      case '\x02':
      case '\x06':
      case '\b':
      case '\n':
      case '\x0e':
      case '\x0f':
      case '\x10':
        pRVar1->screen_ypos = pRVar1->screen_ypos - this->elev_height;
      }
      pRVar1 = pRVar1 + 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: scenario_save
// Address: 00455f10
/* WARNING: Variable defined which should be unmapped: height_info */
/* public: void __thiscall RGE_Map::scenario_save(int) */

void __thiscall RGE_Map::scenario_save(RGE_Map *this,int param_1)
{
  int iVar1;
  int iVar2;
  short sVar3;
  long *plVar4;
  short sVar5;
  uchar height_info;
  uchar overlay_info;
  short y;
  byte local_a [2];
  int local_8;
  RGE_Map *local_4;
  
  iVar1 = param_1;
  local_4 = this;
  rge_write(param_1,&this->map_width,4);
  plVar4 = &this->map_height;
  rge_write(iVar1,plVar4,4);
  iVar2 = *plVar4;
  local_8 = 0;
  if (0 < iVar2) {
    do {
      sVar5 = 0;
      if (0 < iVar2) {
        sVar3 = (short)local_8;
        iVar2 = 0;
        do {
          param_1 = CONCAT31(param_1._1_3_,local_4->map_row_offset[sVar3][iVar2].field_0x5) &
                    0xffffff1f;
          local_a[0] = (byte)local_4->map_row_offset[sVar3][iVar2].field_0x5 >> 5;
          local_a[1] = 0;
          rge_write(iVar1,&param_1,1);
          rge_write(iVar1,local_a,1);
          rge_write(iVar1,local_a + 1,1);
          sVar5 = sVar5 + 1;
          iVar2 = (int)sVar5;
        } while (iVar2 < *plVar4);
      }
      iVar2 = *plVar4;
      local_8 = local_8 + 1;
    } while ((short)local_8 < iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: scenario_load
// Address: 00455ff0
/* WARNING: Variable defined which should be unmapped: height_info */
/* public: void __thiscall RGE_Map::scenario_load(int,unsigned char *) */

void __thiscall RGE_Map::scenario_load(RGE_Map *this,int param_1,uchar *param_2)
{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  uchar height_info;
  uchar overlay_info;
  short x;
  char local_12;
  undefined1 local_11;
  short y;
  long h;
  long w;
  long local_4;
  
  iVar3 = param_1;
  rge_read(param_1,&local_4,4);
  rge_read(iVar3,&w,4);
  new_map(this,local_4,w);
  iVar4 = this->map_height;
  h = 0;
  if (0 < iVar4) {
    do {
      iVar6 = 0;
      _y = 0;
      if (0 < iVar4) {
        sVar5 = (short)h;
        do {
          rge_read(iVar3,&param_1,1);
          rge_read(iVar3,&local_12,1);
          rge_read(iVar3,&local_11,1);
          bVar2 = this->map_row_offset[sVar5][iVar6].field_0x5;
          this->map_row_offset[sVar5][iVar6].field_0x5 = ((byte)param_1 ^ bVar2) & 0x1f ^ bVar2;
          puVar1 = &this->map_row_offset[sVar5][iVar6].field_0x5;
          *puVar1 = local_12 << 5 | *puVar1 & 0x1f;
          _y = _y + 1;
          iVar6 = (int)(short)_y;
        } while (iVar6 < this->map_height);
      }
      iVar4 = this->map_height;
      h = h + 1;
    } while ((short)h < iVar4);
  }
  set_elev(this,0,0,(short)this->map_width + -1,(short)this->map_height + -1,'\0',0,'\0');
  set_terrain(this,(RGE_Player *)0x0,(RGE_Game_World *)0x0,0,0,(short)this->map_width + -1,
              (short)this->map_height + -1,'\0','\0',0);
  return;
}

// --------------------------------------------------

// Function: give_up_map_offsets
// Address: 00456140
/* public: struct RGE_Tile * * __thiscall RGE_Map::give_up_map_offsets(void) */

RGE_Tile ** __thiscall RGE_Map::give_up_map_offsets(RGE_Map *this)
{
  return this->map_row_offset;
}

// --------------------------------------------------

// Function: get_map_width
// Address: 00456150
/* public: long __thiscall RGE_Map::get_map_width(void) */

long __thiscall RGE_Map::get_map_width(RGE_Map *this)
{
  return this->map_width;
}

// --------------------------------------------------

// Function: get_map_height
// Address: 00456160
/* public: long __thiscall RGE_Map::get_map_height(void) */

long __thiscall RGE_Map::get_map_height(RGE_Map *this)
{
  return this->map_height;
}

// --------------------------------------------------

// Function: postclean_elevation
// Address: 00456170
/* WARNING: Variable defined which should be unmapped: was_bad */
/* public: unsigned char __thiscall RGE_Map::postclean_elevation(long,long,long,long,unsigned char)
    */

uchar __thiscall
RGE_Map::postclean_elevation
          (RGE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5)
{
  int iVar1;
  int iVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  byte bVar7;
  ushort uVar8;
  RGE_Tile *pRVar9;
  uchar was_bad;
  long index2;
  long index1;
  short offset1;
  short offset3;
  short offset2;
  
  sVar3 = (short)this->map_width;
  index2._1_1_ = '\0';
  if (0 < param_1) {
    param_1 = param_1 + -1;
  }
  if (0 < param_2) {
    param_2 = param_2 + -1;
  }
  if (param_3 < this->map_width + -1) {
    param_3 = param_3 + 1;
  }
  if (param_4 < this->map_height + -1) {
    param_4 = param_4 + 1;
  }
  do {
    if (param_4 < param_2) {
      return index2._1_1_;
    }
    pRVar9 = this->map_row_offset[param_2] + param_1;
    for (iVar6 = param_1; iVar6 <= param_3; iVar6 = iVar6 + 1) {
      bVar5 = false;
      bVar4 = false;
      bVar7 = (byte)pRVar9->field_0x5 >> 5;
      uVar8 = (ushort)bVar7;
      if (bVar7 < param_5) {
        uVar8 = uVar8 + 1;
        if ((0 < param_2) && (uVar8 < (byte)pRVar9[-sVar3].field_0x5 >> 5)) {
          bVar5 = true;
        }
        iVar1 = this->map_height + -1;
        if ((param_2 < iVar1) && (uVar8 < (byte)pRVar9[sVar3].field_0x5 >> 5)) {
          bVar5 = true;
        }
        if ((0 < iVar6) && (uVar8 < (byte)pRVar9[-1].field_0x5 >> 5)) {
          bVar5 = true;
        }
        iVar2 = this->map_width + -1;
        if ((iVar6 < iVar2) && (uVar8 < (byte)pRVar9[1].field_0x5 >> 5)) {
          bVar5 = true;
        }
        bVar4 = bVar5;
        if (0 < param_2) {
          if ((0 < iVar6) && (uVar8 < (byte)pRVar9[(short)(-1 - sVar3)].field_0x5 >> 5)) {
            bVar5 = true;
          }
          bVar4 = bVar5;
          if ((iVar6 < iVar2) && (uVar8 < (byte)pRVar9[(short)(1 - sVar3)].field_0x5 >> 5)) {
            bVar4 = true;
          }
        }
        if (param_2 < iVar1) {
          if ((0 < iVar6) && (uVar8 < (byte)pRVar9[(short)(sVar3 + -1)].field_0x5 >> 5)) {
            bVar4 = true;
          }
          if ((iVar6 < iVar2) && (uVar8 < (byte)pRVar9[(short)(sVar3 + 1)].field_0x5 >> 5)) {
LAB_0045647c:
            bVar4 = true;
          }
        }
      }
      else if (param_5 < bVar7) {
        uVar8 = uVar8 - 1;
        bVar4 = bVar5;
        if ((0 < param_2) && ((short)(ushort)((byte)pRVar9[-sVar3].field_0x5 >> 5) < (short)uVar8))
{
          bVar4 = true;
        }
        iVar1 = this->map_height + -1;
        if ((param_2 < iVar1) &&
           ((short)(ushort)((byte)pRVar9[sVar3].field_0x5 >> 5) < (short)uVar8)) {
          bVar4 = true;
        }
        if ((0 < iVar6) && ((short)(ushort)((byte)pRVar9[-1].field_0x5 >> 5) < (short)uVar8)) {
          bVar4 = true;
        }
        iVar2 = this->map_width + -1;
        if ((iVar6 < iVar2) && ((short)(ushort)((byte)pRVar9[1].field_0x5 >> 5) < (short)uVar8)) {
          bVar4 = true;
        }
        if (0 < param_2) {
          if ((0 < iVar6) &&
             ((short)(ushort)((byte)pRVar9[(short)(-1 - sVar3)].field_0x5 >> 5) < (short)uVar8)) {
            bVar4 = true;
          }
          if ((iVar6 < iVar2) &&
             ((short)(ushort)((byte)pRVar9[(short)(1 - sVar3)].field_0x5 >> 5) < (short)uVar8)) {
            bVar4 = true;
          }
        }
        if (param_2 < iVar1) {
          if ((0 < iVar6) &&
             ((short)(ushort)((byte)pRVar9[(short)(sVar3 + -1)].field_0x5 >> 5) < (short)uVar8)) {
            bVar4 = true;
          }
          if ((iVar6 < iVar2) &&
             ((short)(ushort)((byte)pRVar9[(short)(sVar3 + 1)].field_0x5 >> 5) < (short)uVar8))
          goto LAB_0045647c;
        }
      }
      if (bVar4) {
        index2._1_1_ = '\x01';
        pRVar9->field_0x5 = (char)uVar8 << 5 | pRVar9->field_0x5 & 0x1f;
      }
      pRVar9 = pRVar9 + 1;
    }
    param_2 = param_2 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: preclean_elevation
// Address: 004564e0
/* WARNING: Variable defined which should be unmapped: change_flag */
/* public: void __thiscall RGE_Map::preclean_elevation(long,long,long,long,unsigned char) */

void __thiscall
RGE_Map::preclean_elevation
          (RGE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5)
{
  short sVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  int iVar13;
  byte bVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  int iVar21;
  int iVar22;
  uchar change_flag;
  long index2;
  long index1;
  short place4;
  short place6;
  short place8;
  short place1;
  short offset1;
  short offset2;
  short place3;
  short offset3;
  short place5;
  short offset5;
  short place7;
  short offset7;
  int local_4;
  
  sVar2 = (short)this->map_width;
  sVar18 = -1 - sVar2;
  sVar19 = -sVar2;
  sVar20 = 1 - sVar2;
  sVar1 = sVar2 + 1;
  sVar15 = sVar2 + -1;
  iVar21 = param_1 * 0x18;
  iVar16 = param_1;
  local_4 = iVar21;
  do {
    bVar12 = false;
    if (0 < iVar16) {
      iVar16 = iVar16 + -1;
      iVar21 = iVar21 + -0x18;
      param_1 = iVar16;
      local_4 = iVar21;
    }
    if (0 < param_2) {
      param_2 = param_2 + -1;
    }
    if (param_3 < this->map_width + -1) {
      param_3 = param_3 + 1;
    }
    iVar13 = param_2;
    if (param_4 < this->map_height + -1) {
      param_4 = param_4 + 1;
    }
    for (; iVar13 <= param_4; iVar13 = iVar13 + 1) {
      iVar22 = (int)&this->map_row_offset[iVar13]->screen_xpos + iVar21;
      iVar17 = iVar16;
      for (; iVar17 <= param_3; iVar17 = iVar17 + 1) {
        bVar4 = false;
        bVar8 = false;
        bVar14 = *(byte *)(iVar22 + 5) >> 5;
        bVar9 = false;
        bVar5 = false;
        bVar10 = false;
        bVar3 = false;
        bVar11 = false;
        bVar6 = false;
        if (0 < iVar13) {
          bVar4 = bVar14 < *(byte *)(iVar22 + 5 + sVar19 * 0x18) >> 5;
        }
        iVar16 = this->map_height + -1;
        if (iVar13 < iVar16) {
          bVar3 = bVar14 < *(byte *)(iVar22 + 5 + sVar2 * 0x18) >> 5;
        }
        if ((0 < iVar17) && (bVar14 < *(byte *)(iVar22 + -0x13) >> 5)) {
          bVar6 = true;
        }
        iVar21 = this->map_width + -1;
        if ((iVar17 < iVar21) && (bVar14 < *(byte *)(iVar22 + 0x1d) >> 5)) {
          bVar5 = true;
        }
        if (0 < iVar13) {
          if ((0 < iVar17) && (bVar14 < *(byte *)(iVar22 + 5 + sVar18 * 0x18) >> 5)) {
            bVar8 = true;
          }
          if ((iVar17 < iVar21) && (bVar14 < *(byte *)(iVar22 + 5 + sVar20 * 0x18) >> 5)) {
            bVar9 = true;
          }
        }
        if (iVar13 < iVar16) {
          if ((0 < iVar17) && (bVar14 < *(byte *)(iVar22 + 5 + sVar15 * 0x18) >> 5)) {
            bVar11 = true;
          }
          if ((iVar17 < iVar21) && (bVar14 < *(byte *)(iVar22 + 5 + sVar1 * 0x18) >> 5)) {
            bVar10 = true;
          }
        }
        bVar7 = false;
        if ((bVar4) && (bVar3)) {
          bVar7 = true;
        }
        if ((bVar5) && (bVar6)) {
          bVar7 = true;
        }
        if (bVar7) {
          if (bVar14 < param_5) {
            *(byte *)(iVar22 + 5) = (bVar14 + 1) * ' ' ^ *(byte *)(iVar22 + 5) & 0x1f;
          }
          else {
            if (bVar8) {
              *(byte *)(iVar22 + 5 + sVar18 * 0x18) =
                   bVar14 << 5 | *(byte *)(iVar22 + 5 + sVar18 * 0x18) & 0x1f;
            }
            if (bVar4) {
              *(byte *)(iVar22 + 5 + sVar19 * 0x18) =
                   bVar14 << 5 | *(byte *)(iVar22 + 5 + sVar19 * 0x18) & 0x1f;
            }
            if (bVar9) {
              *(byte *)(iVar22 + 5 + sVar20 * 0x18) =
                   bVar14 << 5 | *(byte *)(iVar22 + 5 + sVar20 * 0x18) & 0x1f;
            }
            if (bVar5) {
              *(byte *)(iVar22 + 0x1d) = bVar14 << 5 | *(byte *)(iVar22 + 0x1d) & 0x1f;
            }
            if (bVar10) {
              *(byte *)(iVar22 + 5 + sVar1 * 0x18) =
                   bVar14 << 5 | *(byte *)(iVar22 + 5 + sVar1 * 0x18) & 0x1f;
            }
            if (bVar3) {
              *(byte *)(iVar22 + 5 + sVar2 * 0x18) =
                   bVar14 << 5 | *(byte *)(iVar22 + 5 + sVar2 * 0x18) & 0x1f;
            }
            if (bVar11) {
              *(byte *)(iVar22 + 5 + sVar15 * 0x18) =
                   bVar14 << 5 | *(byte *)(iVar22 + 5 + sVar15 * 0x18) & 0x1f;
            }
            if (bVar6) {
              *(byte *)(iVar22 + -0x13) = bVar14 << 5 | *(byte *)(iVar22 + -0x13) & 0x1f;
            }
          }
          bVar12 = true;
        }
        iVar22 = iVar22 + 0x18;
        iVar16 = param_1;
        iVar21 = local_4;
      }
    }
  } while (bVar12);
  return;
}

// --------------------------------------------------

// Function: clean_elevation
// Address: 004568c0
/* WARNING: Variable defined which should be unmapped: change_flag */
/* public: void __thiscall RGE_Map::clean_elevation(long,long,long,long,unsigned char) */

void __thiscall
RGE_Map::clean_elevation
          (RGE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5)
{
  int iVar1;
  int iVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  uchar uVar14;
  int iVar15;
  int iVar16;
  byte bVar17;
  RGE_Tile *pRVar18;
  uchar change_flag;
  short place2;
  short place5;
  short place6;
  short place7;
  short place8;
  long index2;
  short place3;
  short place4;
  long index1;
  short offset1;
  short offset2;
  short offset3;
  short offset5;
  short local_10;
  short offset7;
  short local_8;
  
  sVar3 = (short)this->map_width;
  offset2 = -1 - sVar3;
  offset3 = -sVar3;
  offset5 = 1 - sVar3;
  local_10 = sVar3 + 1;
  local_8 = sVar3 + -1;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->map_width <= param_3) {
    param_3 = this->map_width + -1;
  }
  if (this->map_height <= param_4) {
    param_4 = this->map_height + -1;
  }
  do {
    param_1 = param_1 + -2;
    param_2 = param_2 + -2;
    param_3 = param_3 + 2;
    param_4 = param_4 + 2;
    bVar6 = false;
    if (param_1 < 0) {
      param_1 = 0;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (this->map_width <= param_3) {
      param_3 = this->map_width + -1;
    }
    if (this->map_height <= param_4) {
      param_4 = this->map_height + -1;
    }
    preclean_elevation(this,param_1,param_2,param_3,param_4,param_5);
    for (iVar16 = param_2; iVar16 <= param_4; iVar16 = iVar16 + 1) {
      pRVar18 = this->map_row_offset[iVar16] + param_1;
      for (iVar15 = param_1; iVar15 <= param_3; iVar15 = iVar15 + 1) {
        bVar4 = false;
        bVar17 = (byte)pRVar18->field_0x5 >> 5;
        bVar8 = false;
        bVar7 = false;
        bVar9 = false;
        bVar13 = false;
        bVar12 = false;
        bVar10 = false;
        bVar11 = false;
        if ((0 < iVar16) && (bVar17 < (byte)pRVar18[offset3].field_0x5 >> 5)) {
          bVar8 = true;
        }
        iVar1 = this->map_height + -1;
        if ((iVar16 < iVar1) && (bVar17 < (byte)pRVar18[sVar3].field_0x5 >> 5)) {
          bVar12 = true;
        }
        if ((0 < iVar15) && (bVar17 < (byte)pRVar18[-1].field_0x5 >> 5)) {
          bVar11 = true;
        }
        iVar2 = this->map_width + -1;
        if ((iVar15 < iVar2) && (bVar17 < (byte)pRVar18[1].field_0x5 >> 5)) {
          bVar9 = true;
        }
        if (0 < iVar16) {
          if ((0 < iVar15) && (bVar17 < (byte)pRVar18[offset2].field_0x5 >> 5)) {
            bVar4 = true;
          }
          if ((iVar15 < iVar2) && (bVar17 < (byte)pRVar18[offset5].field_0x5 >> 5)) {
            bVar7 = true;
          }
        }
        if (iVar16 < iVar1) {
          bVar10 = false;
          if ((0 < iVar15) && (bVar17 < (byte)pRVar18[local_8].field_0x5 >> 5)) {
            bVar10 = true;
          }
          if ((iVar15 < iVar2) && (bVar17 < (byte)pRVar18[local_10].field_0x5 >> 5)) {
            bVar13 = true;
          }
        }
        bVar5 = false;
        if (bVar4) {
          if (((((bVar7) && (!bVar8)) || ((bVar9 && (!bVar7)))) || ((bVar10 && (!bVar11)))) ||
             ((bVar12 && (!bVar10)))) {
            bVar5 = true;
          }
          else if (((bVar13) && (!bVar12)) && (!bVar9)) {
            bVar5 = true;
          }
        }
        if (((bVar7) && (!bVar5)) &&
           (((((bVar13 && (!bVar9)) || ((bVar12 && (!bVar13)))) || ((bVar4 && (!bVar8)))) ||
            (((bVar11 && (!bVar4)) || ((bVar10 && ((!bVar11 && (!bVar12)))))))))) {
          bVar5 = true;
        }
        if (((bVar13) && (!bVar5)) &&
           ((((bVar10 && (!bVar12)) || (((bVar11 && (!bVar10)) || ((bVar7 && (!bVar9)))))) ||
            (((bVar8 && (!bVar7)) || ((bVar4 && ((!bVar8 && (!bVar11)))))))))) {
          bVar5 = true;
        }
        if (bVar10) {
          if (!bVar5) {
            if ((((bVar4) && (!bVar11)) || ((bVar8 && (!bVar4)))) ||
               ((((bVar13 && (!bVar12)) || ((bVar9 && (!bVar13)))) ||
                (((bVar7 && (!bVar9)) && (!bVar8)))))) {
              bVar5 = true;
            }
            goto LAB_00456cd0;
          }
LAB_00456cd8:
          if (bVar17 < param_5) {
            pRVar18->field_0x5 = (bVar17 + 1) * ' ' ^ pRVar18->field_0x5 & 0x1f;
          }
          else {
            if (bVar4) {
              pRVar18[offset2].field_0x5 = bVar17 << 5 | pRVar18[offset2].field_0x5 & 0x1f;
            }
            if (bVar8) {
              pRVar18[offset3].field_0x5 = bVar17 << 5 | pRVar18[offset3].field_0x5 & 0x1f;
            }
            if (bVar7) {
              pRVar18[offset5].field_0x5 = bVar17 << 5 | pRVar18[offset5].field_0x5 & 0x1f;
            }
            if (bVar9) {
              pRVar18[1].field_0x5 = bVar17 << 5 | pRVar18[1].field_0x5 & 0x1f;
            }
            if (bVar13) {
              pRVar18[local_10].field_0x5 = bVar17 << 5 | pRVar18[local_10].field_0x5 & 0x1f;
            }
            if (bVar12) {
              pRVar18[sVar3].field_0x5 = bVar17 << 5 | pRVar18[sVar3].field_0x5 & 0x1f;
            }
            if (bVar10) {
              pRVar18[local_8].field_0x5 = bVar17 << 5 | pRVar18[local_8].field_0x5 & 0x1f;
            }
            if (bVar11) {
              pRVar18[-1].field_0x5 = bVar17 << 5 | pRVar18[-1].field_0x5 & 0x1f;
            }
          }
          bVar6 = true;
        }
        else {
LAB_00456cd0:
          if (bVar5) goto LAB_00456cd8;
        }
        pRVar18 = pRVar18 + 1;
      }
    }
    uVar14 = postclean_elevation(this,param_1,param_2,param_3,param_4,param_5);
    if (uVar14 != '\0') {
      bVar6 = true;
    }
    if (!bVar6) {
      set_elev(this,(short)param_1,(short)param_2,(short)param_3,(short)param_4,'\0',0,'\0');
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: clean_terrain
// Address: 00456e90
/* WARNING: Variable defined which should be unmapped: index2 */
/* public: void __thiscall RGE_Map::clean_terrain(long,long,long,long,unsigned char) */

void __thiscall
RGE_Map::clean_terrain
          (RGE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5)
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
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  RGE_Tile *pRVar17;
  long index2;
  short place2;
  short place4;
  long index1;
  short place5;
  short place1;
  short place6;
  short place3;
  long pass_index;
  short offset2;
  short local_1c;
  short offset1;
  short offset3;
  short offset7;
  short offset5;
  short local_8;
  
  sVar1 = (short)this->map_width;
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
  if (this->map_width <= param_3) {
    param_3 = this->map_width + -1;
  }
  iVar14 = param_4;
  iVar15 = param_1;
  if (this->map_height <= param_4) {
    iVar14 = this->map_height + -1;
    param_4 = iVar14;
  }
  do {
    bVar6 = false;
    if (0 < iVar15) {
      iVar15 = iVar15 + -1;
      param_1 = iVar15;
    }
    if (0 < param_2) {
      param_2 = param_2 + -1;
    }
    if (param_3 < this->map_width + -1) {
      param_3 = param_3 + 1;
    }
    if (iVar14 < this->map_height + -1) {
      iVar14 = iVar14 + 1;
      param_4 = iVar14;
    }
    _offset2 = 0;
    do {
      iVar13 = param_2;
      iVar12 = iVar15;
      iVar16 = iVar15;
      if (param_2 <= iVar14) {
        do {
          pRVar17 = this->map_row_offset[iVar13] + iVar15;
          iVar16 = iVar12;
          for (; iVar12 <= param_3; iVar12 = iVar12 + 1) {
            if ((pRVar17->field_0x5 & 0x1f) != param_5) {
              bVar4 = false;
              bVar5 = false;
              bVar3 = false;
              bVar7 = false;
              bVar2 = false;
              bVar10 = false;
              bVar9 = false;
              bVar11 = false;
              bVar8 = false;
              if ((0 < iVar13) && ((pRVar17[local_1c].field_0x5 & 0x1f) == param_5)) {
                bVar7 = true;
              }
              iVar14 = this->map_height + -1;
              if ((iVar13 < iVar14) && ((pRVar17[sVar1].field_0x5 & 0x1f) == param_5)) {
                bVar8 = true;
              }
              if ((0 < iVar12) && ((pRVar17[-1].field_0x5 & 0x1f) == param_5)) {
                bVar4 = true;
              }
              iVar16 = this->map_width + -1;
              if ((iVar12 < iVar16) && ((pRVar17[1].field_0x5 & 0x1f) == param_5)) {
                bVar9 = true;
              }
              if (_offset2 == 1) {
                bVar10 = bVar2;
                if (0 < iVar13) {
                  if ((0 < iVar12) && ((pRVar17[offset3].field_0x5 & 0x1f) == param_5)) {
                    bVar3 = true;
                  }
                  if ((iVar12 < iVar16) && ((pRVar17[offset7].field_0x5 & 0x1f) == param_5)) {
                    bVar10 = true;
                  }
                }
                if (iVar13 < iVar14) {
                  bVar5 = false;
                  if ((0 < iVar12) && ((pRVar17[offset5].field_0x5 & 0x1f) == param_5)) {
                    bVar5 = true;
                  }
                  if ((iVar12 < iVar16) && ((pRVar17[local_8].field_0x5 & 0x1f) == param_5)) {
                    bVar11 = true;
                  }
                }
              }
              bVar2 = false;
              if (_offset2 == 0) {
                if (((bVar7) && (bVar8)) || ((bVar9 && (bVar4)))) {
LAB_00457268:
                  bVar2 = true;
                }
LAB_0045726a:
                if (!bVar2) goto LAB_00457292;
              }
              else {
                if (bVar3) {
                  if (((((bVar10) && (!bVar7)) || ((bVar9 && (!bVar10)))) || ((bVar5 && (!bVar4))))
                     || ((bVar8 && (!bVar5)))) {
                    bVar2 = true;
                  }
                  else if (((bVar11) && (!bVar8)) && (!bVar9)) {
                    bVar2 = true;
                  }
                }
                if (((bVar10) && (!bVar2)) &&
                   (((((bVar3 && (!bVar7)) || ((bVar4 && (!bVar3)))) || ((bVar11 && (!bVar9)))) ||
                    (((bVar8 && (!bVar11)) || ((bVar5 && ((!bVar4 && (!bVar8)))))))))) {
                  bVar2 = true;
                }
                if (((bVar11) && (!bVar2)) &&
                   ((((bVar10 && (!bVar9)) || (((bVar7 && (!bVar10)) || ((bVar5 && (!bVar8)))))) ||
                    (((bVar4 && (!bVar5)) || ((bVar3 && ((!bVar4 && (!bVar7)))))))))) {
                  bVar2 = true;
                }
                if (!bVar5) goto LAB_0045726a;
                if (!bVar2) {
                  if ((((bVar3) && (!bVar4)) || ((bVar7 && (!bVar3)))) ||
                     ((((bVar11 && (!bVar8)) || ((bVar9 && (!bVar11)))) ||
                      (((bVar10 && (!bVar9)) && (!bVar7)))))) goto LAB_00457268;
                  goto LAB_0045726a;
                }
              }
              set_terrain(this,this->game_world,(short)iVar12,(short)iVar13,param_5,0,0);
              bVar6 = true;
            }
LAB_00457292:
            pRVar17 = pRVar17 + 1;
            iVar14 = param_4;
            iVar16 = param_1;
          }
          iVar13 = iVar13 + 1;
          iVar12 = iVar16;
        } while (iVar13 <= iVar14);
      }
      _offset2 = _offset2 + 1;
      iVar15 = iVar16;
    } while (_offset2 < 2);
    if (!bVar6) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: clean_borders
// Address: 00457300
/* public: void __thiscall RGE_Map::clean_borders(long,long,long,long) */

void __thiscall
RGE_Map::clean_borders(RGE_Map *this,long param_1,long param_2,long param_3,long param_4)
{
  return;
}

// --------------------------------------------------

// Function: clean_border_tile
// Address: 00457310
/* public: long __thiscall RGE_Map::clean_border_tile(long,long,long (* const)[32]) */

long __thiscall RGE_Map::clean_border_tile(RGE_Map *this,long param_1,long param_2,long *param_3)
{
  return -1;
}

// --------------------------------------------------

// Function: do_terrain_brush
// Address: 00457320
/* public: virtual unsigned char __thiscall RGE_Map::do_terrain_brush(long,long,long,unsigned char)
    */

uchar __thiscall
RGE_Map::do_terrain_brush(RGE_Map *this,long param_1,long param_2,long param_3,uchar param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_3 + param_1;
  param_1 = param_1 - param_3;
  iVar4 = param_2 - param_3;
  iVar2 = param_3 + param_2;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (this->map_width <= iVar3) {
    iVar3 = this->map_width + -1;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (this->map_height <= iVar2) {
    iVar2 = this->map_height + -1;
  }
  for (; iVar1 = param_1, iVar4 <= iVar2; iVar4 = iVar4 + 1) {
    for (; iVar1 <= iVar3; iVar1 = iVar1 + 1) {
      set_terrain(this,this->game_world,(short)iVar1,(short)iVar4,param_4,0,0);
    }
  }
  return '\x01';
}

// --------------------------------------------------

// Function: do_terrain_brush_stroke
// Address: 004573c0
/* public: virtual unsigned char __thiscall
   RGE_Map::do_terrain_brush_stroke(long,long,long,long,long,unsigned char) */

uchar __thiscall
RGE_Map::do_terrain_brush_stroke
          (RGE_Map *this,long param_1,long param_2,long param_3,long param_4,long param_5,
          uchar param_6)
{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined3 in_stack_00000019;
  int iStack_3c;
  double dVar4;
  double dStack_30;
  undefined4 uStack_2c;
  long index;
  double x;
  double y;
  double dx;
  double dy;
  
  dVar4 = (double)CONCAT44(unaff_ESI,unaff_EDI);
  iVar3 = param_5 >> 1;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (this->map_width <= param_3) {
    param_3 = this->map_width + -1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->map_height <= param_4) {
    param_4 = this->map_height + -1;
  }
  uVar2 = __ftol();
  dStack_30 = (double)CONCAT44(uVar2,unaff_EBX);
  pcVar1 = *(code **)(this->_padding_ + 0xc);
  (*pcVar1)(param_1,param_2,iVar3);
  if (0 < _param_6) {
    iStack_3c = _param_6;
    do {
      dVar4 = dVar4 + (double)param_1;
      dStack_30 = dStack_30 + (double)param_2;
      uVar2 = __ftol(iVar3,_param_6);
      uVar2 = __ftol(uVar2);
      (*pcVar1)(uVar2);
      iStack_3c = iStack_3c + -1;
    } while (iStack_3c != 0);
  }
  if (((double)param_3 != dVar4) || ((double)param_4 != dStack_30)) {
    (*pcVar1)(param_3,param_4,iVar3,_param_6);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: do_elevation_brush
// Address: 00457510
/* WARNING: Variable defined which should be unmapped: x2 */
/* public: virtual unsigned char __thiscall RGE_Map::do_elevation_brush(long,long,long,unsigned
   char) */

uchar __thiscall
RGE_Map::do_elevation_brush(RGE_Map *this,long param_1,long param_2,long param_3,uchar param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long x2;
  
  iVar5 = param_3 + param_1;
  iVar3 = param_1 - param_3;
  iVar2 = param_2 - param_3;
  iVar1 = param_3 + param_2;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (this->map_width <= iVar5) {
    iVar5 = this->map_width + -1;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (this->map_height <= iVar1) {
    iVar1 = this->map_height + -1;
  }
  for (; iVar2 <= iVar1; iVar2 = iVar2 + 1) {
    if (iVar3 <= iVar5) {
      iVar6 = (iVar5 - iVar3) + 1;
      iVar4 = iVar3 * 0x18;
      do {
        iVar6 = iVar6 + -1;
        (&this->map_row_offset[iVar2]->field_0x5)[iVar4] =
             (&this->map_row_offset[iVar2]->field_0x5)[iVar4] & 0x1f | param_4 << 5;
        iVar4 = iVar4 + 0x18;
      } while (iVar6 != 0);
    }
  }
  return '\x01';
}

// --------------------------------------------------

// Function: do_elevation_brush_stroke
// Address: 004575c0
/* public: virtual unsigned char __thiscall
   RGE_Map::do_elevation_brush_stroke(long,long,long,long,long,unsigned char) */

uchar __thiscall
RGE_Map::do_elevation_brush_stroke
          (RGE_Map *this,long param_1,long param_2,long param_3,long param_4,long param_5,
          uchar param_6)
{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  int iVar5;
  undefined4 unaff_EDI;
  undefined3 in_stack_00000019;
  int iStack_3c;
  double dVar6;
  double dStack_30;
  undefined4 uStack_2c;
  long index;
  double x;
  double y;
  double dx;
  double dy;
  
  dVar6 = (double)CONCAT44(unaff_ESI,unaff_EDI);
  iVar5 = param_5 >> 1;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (this->map_width <= param_3) {
    param_3 = this->map_width + -1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->map_height <= param_4) {
    param_4 = this->map_height + -1;
  }
  uVar2 = __ftol();
  dStack_30 = (double)CONCAT44(uVar2,unaff_EBX);
  pcVar1 = *(code **)(this->_padding_ + 0x14);
  (*pcVar1)(param_1,param_2,iVar5);
  if (0 < _param_6) {
    iStack_3c = _param_6;
    do {
      dVar6 = dVar6 + (double)param_1;
      dStack_30 = dStack_30 + (double)param_2;
      uVar2 = __ftol(iVar5,_param_6);
      uVar2 = __ftol(uVar2);
      (*pcVar1)(uVar2);
      iStack_3c = iStack_3c + -1;
    } while (iStack_3c != 0);
  }
  if (((double)param_3 != dVar6) || ((double)param_4 != dStack_30)) {
    (*pcVar1)(param_3,param_4,iVar5,_param_6);
  }
  if (param_1 < param_3) {
    lVar4 = param_1 - iVar5;
  }
  else {
    lVar4 = param_3 - iVar5;
    param_3 = param_1;
  }
  if (param_2 < param_4) {
    lVar3 = param_2 - iVar5;
  }
  else {
    lVar3 = param_4 - iVar5;
    param_4 = param_2;
  }
  clean_elevation(this,lVar4,lVar3,param_3 + iVar5,param_4 + iVar5,param_6);
  return '\x01';
}

// --------------------------------------------------

// Function: do_cliff_brush
// Address: 00457750
/* public: virtual unsigned char __thiscall RGE_Map::do_cliff_brush(long,long,unsigned char,unsigned
   char) */

uchar __thiscall
RGE_Map::do_cliff_brush(RGE_Map *this,long param_1,long param_2,uchar param_3,uchar param_4)
{
  return '\0';
}

// --------------------------------------------------

// Function: do_cliff_brush_stroke
// Address: 00457760
/* public: virtual unsigned char __thiscall
   RGE_Map::do_cliff_brush_stroke(long,long,long,long,unsigned char,unsigned char) */

uchar __thiscall
RGE_Map::do_cliff_brush_stroke
          (RGE_Map *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6)
{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined3 in_stack_00000015;
  undefined3 in_stack_00000019;
  int iStack_3c;
  double dVar3;
  double dStack_30;
  undefined4 uStack_2c;
  long index;
  double x;
  double y;
  double dx;
  double dy;
  
  dVar3 = (double)CONCAT44(unaff_ESI,unaff_EDI);
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (this->map_width <= param_3) {
    param_3 = this->map_width + -1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->map_height <= param_4) {
    param_4 = this->map_height + -1;
  }
  uVar2 = __ftol();
  dStack_30 = (double)CONCAT44(uVar2,unaff_EBX);
  pcVar1 = *(code **)(this->_padding_ + 0x1c);
  (*pcVar1)(param_1,param_2,_param_5);
  if (0 < _param_6) {
    iStack_3c = _param_6;
    do {
      dVar3 = dVar3 + (double)param_1;
      dStack_30 = dStack_30 + (double)param_2;
      uVar2 = __ftol(_param_5,_param_6);
      uVar2 = __ftol(uVar2);
      (*pcVar1)(uVar2);
      iStack_3c = iStack_3c + -1;
    } while (iStack_3c != 0);
  }
  if (((double)param_3 != dVar3) || ((double)param_4 != dStack_30)) {
    (*pcVar1)(param_3,param_4,_param_5,_param_6);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: map_generate
// Address: 004578a0
/* public: virtual void __thiscall RGE_Map::map_generate(class RGE_Player *,class RGE_Game_World
   *,struct RGE_Player_Info *,unsigned char *) */

void __thiscall
RGE_Map::map_generate
          (RGE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2,RGE_Player_Info *param_3,
          uchar *param_4)
{
  return;
}

// --------------------------------------------------

// Function: map_generate2
// Address: 004578b0
// [HELPER] s_After_Random_Map_Generation_rand: "After Random Map Generation random number is %d"
// [HELPER] s_C__msdev_work_age1_x1_map_cpp: "C:\msdev\work\age1_x1\map.cpp"
// [HELPER] s_Random_Map_Seed____d: "Random Map Seed = %d"
/* public: virtual void __thiscall RGE_Map::map_generate2(class RGE_Game_World *,long,long,unsigned
   char,long) */

void __thiscall
RGE_Map::map_generate2
          (RGE_Map *this,RGE_Game_World *param_1,long param_2,long param_3,uchar param_4,
          long param_5)
{
  uchar uVar1;
  RGE_Base_Game *this_00;
  uint uVar2;
  int iVar3;
  undefined3 in_stack_00000011;
  
  uVar1 = this->game_world->game_state;
  this->game_world->game_state = '\x03';
  uVar2 = rge_base_game->random_map_seed;
  if (uVar2 == 0xffffffff) {
    uVar2 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x5ce);
  }
  this_00 = rge_base_game;
  rge_base_game->save_random_map_seed = uVar2;
  TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s_Random_Map_Seed____d,uVar2);
  debug_srand(s_C__msdev_work_age1_x1_map_cpp,0x5da,uVar2);
  clear_map(this,(RGE_Player *)0x0,param_1,'\0',param_2,param_3);
  debug_srand(s_C__msdev_work_age1_x1_map_cpp,0x5dd,uVar2);
  (**(code **)(this->random_map->_padding_ + 0x14))(this,param_1,_param_4,param_5,1);
  debug_srand(s_C__msdev_work_age1_x1_map_cpp,0x5e0,uVar2);
  (**(code **)this->random_map->_padding_)();
  (**(code **)(this->random_map->_padding_ + 0x18))();
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x5e5);
  TDebuggingLog::Log(L,(char *)L,s_After_Random_Map_Generation_rand,iVar3);
  this->game_world->game_state = uVar1;
  return;
}

// --------------------------------------------------

// Function: load_map
// Address: 004579c0
/* WARNING: Variable defined which should be unmapped: x */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::load_map(int) */

void __thiscall RGE_Map::load_map(RGE_Map *this,int param_1)
{
  int iVar1;
  RGE_Zone_Map_List *pRVar2;
  int iVar3;
  int iVar4;
  RGE_Tile *pRVar5;
  undefined4 *unaff_FS_OFFSET;
  int x;
  int y;
  long h;
  long w;
  long local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055db0b;
  *unaff_FS_OFFSET = &local_c;
  rge_read(param_1,&local_10,4);
  rge_read(iVar1,&w,4);
  new_map(this,local_10,w);
  pRVar2 = this->map_zones;
  if (pRVar2 != (RGE_Zone_Map_List *)0x0) {
    RGE_Zone_Map_List::~RGE_Zone_Map_List(pRVar2);
    operator_delete(pRVar2);
  }
  pRVar2 = (RGE_Zone_Map_List *)operator_new(0xc);
  local_4 = 0;
  if (pRVar2 == (RGE_Zone_Map_List *)0x0) {
    pRVar2 = (RGE_Zone_Map_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Zone_Map_List *)RGE_Zone_Map_List::RGE_Zone_Map_List(pRVar2,iVar1,this);
  }
  local_4 = 0xffffffff;
  this->map_zones = pRVar2;
  rge_read(iVar1,&this->map_visible_flag,1);
  rge_read(iVar1,&this->fog_flag,1);
  if (save_game_version < _DAT_005706a8) {
    rge_read(iVar1,this->map,this->map_width * this->map_height * 0x18);
    h = 0;
    if (0 < this->map_height) {
      do {
        iVar4 = 0;
        if (0 < this->map_width) {
          iVar3 = 0;
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)((int)&(this->map_row_offset[h]->objects).list + iVar3) = 0;
            iVar3 = iVar3 + 0x18;
          } while (iVar4 < this->map_width);
        }
        h = h + 1;
      } while (h < this->map_height);
    }
  }
  else {
    h = 0;
    if (0 < this->map_height) {
      do {
        y = 0;
        pRVar5 = this->map_row_offset[h];
        if (0 < this->map_width) {
          do {
            rge_read(iVar1,pRVar5,2);
            rge_read(iVar1,&pRVar5->screen_ypos,2);
            rge_read(iVar1,&pRVar5->tile_type,1);
            rge_read(iVar1,&param_1,1);
            pRVar5->field_0x5 = ((byte)param_1 ^ pRVar5->field_0x5) & 0x1f ^ pRVar5->field_0x5;
            rge_read(iVar1,&param_1,1);
            pRVar5->field_0x5 = (byte)param_1 << 5 | pRVar5->field_0x5 & 0x1f;
            rge_read(iVar1,&param_1,1);
            pRVar5->field_0x6 = ((byte)param_1 ^ pRVar5->field_0x6) & 0xf ^ pRVar5->field_0x6;
            rge_read(iVar1,&param_1,1);
            pRVar5->last_drawn_as = '\0';
            pRVar5->last_drawn_shape = 0xff;
            pRVar5->field_0x6 = (byte)param_1 << 4 | pRVar5->field_0x6 & 0xf;
            (pRVar5->objects).list = (RGE_Object_Node *)0x0;
            (pRVar5->objects).number_of_objects = 0;
            pRVar5->draw_as = '\0';
            pRVar5->draw_attribute = '\0';
            pRVar5->last_drawn_shape2 = 0xff;
            pRVar5 = pRVar5 + 1;
            y = y + 1;
          } while (y < this->map_width);
        }
        h = h + 1;
      } while (h < this->map_height);
    }
  }
  RGE_Unified_Visible_Map::load(this->unified_vis_map,iVar1);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: save_map
// Address: 00457c50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::save_map(int) */

void __thiscall RGE_Map::save_map(RGE_Map *this,int param_1)
{
  long *plVar1;
  long *plVar2;
  int iVar3;
  int iVar4;
  RGE_Tile *pRVar5;
  int y;
  int local_c;
  
  iVar3 = param_1;
  plVar1 = &this->map_width;
  rge_write(param_1,plVar1,4);
  plVar2 = &this->map_height;
  rge_write(iVar3,plVar2,4);
  RGE_Zone_Map_List::save(this->map_zones,iVar3);
  rge_write(iVar3,&this->map_visible_flag,1);
  rge_write(iVar3,&this->fog_flag,1);
  if (save_game_version < _DAT_005706a8) {
    rge_write(iVar3,this->map,*plVar2 * *plVar1 * 0x18);
  }
  else {
    local_c = 0;
    if (0 < *plVar2) {
      do {
        iVar4 = 0;
        pRVar5 = this->map_row_offset[local_c];
        if (0 < *plVar1) {
          do {
            rge_write(iVar3,pRVar5,2);
            rge_write(iVar3,&pRVar5->screen_ypos,2);
            rge_write(iVar3,&pRVar5->tile_type,1);
            param_1 = CONCAT31(param_1._1_3_,pRVar5->field_0x5) & 0xffffff1f;
            rge_write(iVar3,&param_1,1);
            param_1 = CONCAT31(param_1._1_3_,(byte)pRVar5->field_0x5 >> 5);
            rge_write(iVar3,&param_1,1);
            param_1 = CONCAT31(param_1._1_3_,pRVar5->field_0x6) & 0xffffff0f;
            rge_write(iVar3,&param_1,1);
            param_1 = CONCAT31(param_1._1_3_,(byte)pRVar5->field_0x6 >> 4);
            rge_write(iVar3,&param_1,1);
            pRVar5 = pRVar5 + 1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < *plVar1);
        }
        local_c = local_c + 1;
      } while (local_c < *plVar2);
    }
  }
  RGE_Unified_Visible_Map::save(this->unified_vis_map,iVar3);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00457df0
/* public: virtual void __thiscall RGE_Map::save(int) */

void __thiscall RGE_Map::save(RGE_Map *this,int param_1)
{
  int *piVar1;
  RGE_Sound **ppRVar2;
  int iVar3;
  RGE_Map *pRVar4;
  int iVar5;
  int *piVar6;
  
  piVar1 = (int *)calloc(1,0x8dd0);
  pRVar4 = this;
  piVar6 = piVar1;
  for (iVar3 = 0x2374; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = pRVar4->_padding_;
    pRVar4 = (RGE_Map *)&pRVar4->map;
    piVar6 = piVar6 + 1;
  }
  ppRVar2 = &this->terrain_types[0].sound;
  iVar3 = (int)piVar1 - (int)this;
  iVar5 = 0x20;
  do {
    if (((RGE_Tile_Set *)(ppRVar2 + -9))->loaded != '\0') {
      if (*ppRVar2 == (RGE_Sound *)0x0) {
        *(undefined4 *)(iVar3 + (int)ppRVar2) = 0xffffffff;
      }
      else {
        *(int *)(iVar3 + (int)ppRVar2) = (int)(*ppRVar2)->id;
      }
    }
    ppRVar2 = ppRVar2 + 0x66;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ppRVar2 = &this->border_types[0].sound;
  iVar5 = 0x10;
  do {
    if ((*ppRVar2 == (RGE_Sound *)0x0) || (((RGE_Border_Set *)(ppRVar2 + -9))->loaded == '\0')) {
      *(undefined4 *)((int)ppRVar2 + iVar3) = 0xffffffff;
    }
    else {
      *(int *)((int)ppRVar2 + iVar3) = (int)(*ppRVar2)->id;
    }
    ppRVar2 = ppRVar2 + 0x168;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  rge_write(param_1,piVar1,0x8dd0);
  RGE_RMM_Database_Controller::save(this->random_map,param_1);
  free(piVar1);
  return;
}

// --------------------------------------------------

// Function: load_terrain_types
// Address: 00457eb0
// [HELPER] s__shp: ".shp"
/* WARNING: Variable defined which should be unmapped: filename2 */
/* public: void __thiscall RGE_Map::load_terrain_types(class RGE_Sound * *) */

void __thiscall RGE_Map::load_terrain_types(RGE_Map *this,RGE_Sound **param_1)
{
  TShape *pTVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  undefined4 *unaff_FS_OFFSET;
  char *filename2;
  char *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055db2b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_10 = (char *)0x0;
  plVar4 = &this->terrain_types[0x1f].resource_id;
  iVar3 = 0x20;
  do {
    if (((RGE_Tile_Set *)(plVar4 + -7))->loaded != '\0') {
      addstring(&local_10,(char *)((int)plVar4 + -0xd),s__shp);
      pTVar1 = (TShape *)operator_new(0x20);
      local_4 = 0;
      if (pTVar1 == (TShape *)0x0) {
        pTVar1 = (TShape *)0x0;
      }
      else {
        pTVar1 = (TShape *)TShape::TShape(pTVar1,local_10,*plVar4);
      }
      local_4 = 0xffffffff;
      plVar4[1] = (long)pTVar1;
      iVar2 = TShape::is_loaded(pTVar1);
      if (iVar2 == 0) {
        ((RGE_Tile_Set *)(plVar4 + -7))->loaded = '\0';
      }
      if ((int)plVar4[2] < 0) {
        plVar4[2] = 0;
      }
      else {
        plVar4[2] = (long)param_1[(int)plVar4[2]];
      }
    }
    plVar4 = plVar4 + -0x66;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (local_10 != (char *)0x0) {
    free(local_10);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_terrain_types
// Address: 00457f80
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s__hd__s__s__d__hd__hd__hd__hd__hd: "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: border_num */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::load_terrain_types(char *,class RGE_Sound * *) */

void __thiscall RGE_Map::load_terrain_types(RGE_Map *this,char *param_1,RGE_Sound **param_2)
{
  char cVar1;
  short sVar2;
  RGE_Tile_Set *pRVar3;
  int iVar4;
  RGE_Sound *pRVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  RGE_TOB_Picts *pRVar9;
  char *pcVar10;
  char *pcVar11;
  short border_num;
  short border;
  short sound_id;
  short low_color;
  short med_color;
  short hi_color;
  short lt_cliff_color;
  short rt_cliff_color;
  short impassable_terrain;
  short passable_terrain;
  short row;
  short col;
  short is_animated;
  short animation_frames;
  short terrain_to_draw;
  short random;
  float interval;
  _iobuf *infile;
  int local_38;
  float pause_between_loops;
  float local_30;
  long resource_id;
  long local_28;
  char name [13];
  char pict_name [13];
  
  pRVar3 = this->terrain_types + 0x1f;
  iVar6 = 0x20;
  do {
    pRVar3->loaded = '\0';
    pRVar3 = pRVar3 + -1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  name._0_4_ = this;
  iVar6 = fopen(param_1,s_r);
  local_38 = iVar6;
  if (iVar6 != 0) {
    fscanf(iVar6,s__hd,&this->num_terrain);
    sVar2 = this->num_terrain + -1;
    if (-1 < sVar2) {
      resource_id = sVar2 + 1;
      do {
        sVar2 = 0;
        iVar4 = fscanf(iVar6,s__hd__s__s__d__hd__hd__hd__hd__hd,&param_1,name + 4,pict_name + 4,
                       &local_28,(int)&interval + 2,&lt_cliff_color,&rt_cliff_color,&hi_color,
                       &med_color,&terrain_to_draw,&random,&infile,&local_30,&interval,&is_animated,
                       &animation_frames,&impassable_terrain,&passable_terrain,&row,&col,&sound_id);
        if (((iVar4 != -1) && ((short)param_1 < 0x20)) && (-1 < (short)param_1)) {
          pause_between_loops = 2.66247e-44;
          pRVar3 = this->terrain_types + (short)param_1;
          pRVar9 = pRVar3->tiles;
          do {
            fscanf(local_38,s__hd__hd,pRVar9,&pRVar9->animations);
            pRVar9->shape_index = sVar2;
            sVar2 = sVar2 + pRVar9->count * pRVar9->animations;
            pRVar9 = pRVar9 + 1;
            pause_between_loops = (float)((int)pause_between_loops + -1);
          } while (pause_between_loops != 0.0);
          sVar2 = 0;
          pause_between_loops = 0.0;
          if (0 < sound_id) {
            do {
              fscanf(local_38,s__hd__hd,&param_1,&low_color);
              sVar2 = sVar2 + 1;
              pRVar3->borders[(short)param_1] = low_color;
            } while (sVar2 < sound_id);
          }
          if (med_color < 0) {
            pRVar5 = (RGE_Sound *)0x0;
          }
          else {
            pRVar5 = param_2[med_color];
          }
          pRVar3->sound = pRVar5;
          pRVar3->map_low_color = (uchar)hi_color;
          pRVar3->map_med_color = (uchar)lt_cliff_color;
          pRVar3->map_hi_color = (uchar)rt_cliff_color;
          pRVar3->map_lt_cliff_color = (uchar)impassable_terrain;
          pRVar3->map_rt_cliff_color = (uchar)passable_terrain;
          pRVar3->impassable_terrain = (uchar)row;
          pRVar3->passable_terrain = (uchar)col;
          convert_us(name + 4);
          uVar7 = 0xffffffff;
          pcVar10 = name + 4;
          do {
            pcVar11 = pcVar10;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar11 = pcVar10 + 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar11;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          pcVar10 = pcVar11 + -uVar7;
          pcVar11 = pRVar3->name;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar11 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar11 = pcVar11 + 1;
          }
          uVar7 = 0xffffffff;
          pcVar10 = pict_name + 4;
          do {
            pcVar11 = pcVar10;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar11 = pcVar10 + 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar11;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          pcVar10 = pcVar11 + -uVar7;
          pcVar11 = pRVar3->pict_name;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar11 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar11 = pcVar11 + 1;
          }
          pRVar3->animate_last = 0.0;
          pRVar3->resource_id = local_28;
          pRVar3->loaded = '\x01';
          pRVar3->rows = is_animated;
          pRVar3->cols = animation_frames;
          pRVar3->is_animated = (uchar)terrain_to_draw;
          pRVar3->animation_frames = random;
          if ((float)infile == _DAT_005706ac) {
            sVar2 = 0;
          }
          else {
            sVar2 = __ftol();
          }
          pRVar3->pause_frames = sVar2;
          pRVar3->interval = (float)infile;
          pRVar3->frame = 0;
          pRVar3->pause_between_loops = local_30;
          pRVar3->draw_frame = 0;
          pRVar3->frame_changed = '\0';
          pRVar3->drawn = '\0';
          pRVar3->terrain_to_draw = interval._0_2_;
          this = (RGE_Map *)name._0_4_;
          iVar6 = local_38;
        }
        resource_id = resource_id + -1;
      } while (resource_id != 0);
    }
  }
  fclose(iVar6);
  return;
}

// --------------------------------------------------

// Function: load_border_types
// Address: 00458280
// [HELPER] s__shp: ".shp"
/* WARNING: Variable defined which should be unmapped: filename2 */
/* public: void __thiscall RGE_Map::load_border_types(class RGE_Sound * *) */

void __thiscall RGE_Map::load_border_types(RGE_Map *this,RGE_Sound **param_1)
{
  TShape *pTVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  undefined4 *unaff_FS_OFFSET;
  char *filename2;
  char *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055db4b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_10 = (char *)0x0;
  plVar4 = &this->border_types[0xf].resource_id;
  iVar3 = 0x10;
  do {
    if (((RGE_Border_Set *)(plVar4 + -7))->loaded != '\0') {
      addstring(&local_10,(char *)((int)plVar4 + -0xd),s__shp);
      pTVar1 = (TShape *)operator_new(0x20);
      local_4 = 0;
      if (pTVar1 == (TShape *)0x0) {
        pTVar1 = (TShape *)0x0;
      }
      else {
        pTVar1 = (TShape *)TShape::TShape(pTVar1,local_10,*plVar4);
      }
      local_4 = 0xffffffff;
      plVar4[1] = (long)pTVar1;
      iVar2 = TShape::is_loaded(pTVar1);
      if (iVar2 == 0) {
        ((RGE_Border_Set *)(plVar4 + -7))->loaded = '\0';
      }
      if ((int)plVar4[2] < 0) {
        plVar4[2] = 0;
      }
      else {
        plVar4[2] = (long)param_1[(int)plVar4[2]];
      }
    }
    plVar4 = plVar4 + -0x168;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (local_10 != (char *)0x0) {
    free(local_10);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_border_types
// Address: 00458350
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s__hd__s__s__d__hd__hd__hd__hd__hd: "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: sound_id */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::load_border_types(char *,class RGE_Sound * *) */

void __thiscall RGE_Map::load_border_types(RGE_Map *this,char *param_1,RGE_Sound **param_2)
{
  char cVar1;
  short sVar2;
  short sVar3;
  RGE_Border_Set *pRVar4;
  int iVar5;
  RGE_Sound *pRVar6;
  int iVar7;
  RGE_TOB_Picts *pRVar8;
  uint uVar9;
  uint uVar10;
  short *psVar11;
  char *pcVar12;
  char *pcVar13;
  short sound_id;
  short low_color;
  short med_color;
  short hi_color;
  short is_animated;
  short animation_frames;
  short tile_flag;
  short underlay_terrain;
  short border_style;
  short random;
  short local_48;
  undefined1 local_46 [2];
  float interval;
  float local_40;
  int local_3c;
  float pause_between_loops;
  _iobuf *infile;
  int local_30;
  long resource_id;
  long local_28;
  char name [13];
  char pict_name [13];
  
  iVar7 = 0x10;
  pRVar4 = this->border_types + 0xf;
  do {
    pRVar4->loaded = '\0';
    pRVar4 = pRVar4 + -1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  name._0_4_ = this;
  iVar7 = fopen(param_1,s_r);
  local_30 = iVar7;
  if (iVar7 != 0) {
    fscanf(iVar7,s__hd,&this->num_borders);
    sVar3 = this->num_borders + -1;
    if (-1 < sVar3) {
      resource_id = sVar3 + 1;
      do {
        sVar3 = 0;
        iVar5 = fscanf(iVar7,s__hd__s__s__d__hd__hd__hd__hd__hd,&param_1,name + 4,pict_name + 4,
                       &local_28,local_46,&is_animated,&animation_frames,&hi_color,&med_color,
                       &tile_flag,&underlay_terrain,&local_40,&infile,&border_style,&random,
                       &local_48);
        if (((iVar5 != -1) && ((short)param_1 < 0x10)) && (-1 < (short)param_1)) {
          pause_between_loops = 2.66247e-44;
          pRVar4 = this->border_types + (short)param_1;
          pRVar8 = pRVar4->borders[0];
          do {
            psVar11 = &pRVar8->animations;
            local_3c = 0xc;
            interval = (float)pRVar8;
            do {
              fscanf(local_30,s__hd__hd,pRVar8,psVar11);
              sVar2 = ((RGE_TOB_Picts *)&pRVar8->count)->count;
              psVar11[1] = sVar3;
              sVar3 = sVar3 + sVar2 * *psVar11;
              pRVar8 = pRVar8 + 1;
              psVar11 = psVar11 + 3;
              local_3c = local_3c + -1;
            } while (local_3c != 0);
            pRVar8 = (RGE_TOB_Picts *)((int)interval + 0x48);
            pause_between_loops = (float)((int)pause_between_loops + -1);
          } while (pause_between_loops != 0.0);
          if (med_color < 0) {
            pRVar6 = (RGE_Sound *)0x0;
          }
          else {
            pRVar6 = param_2[med_color];
          }
          pRVar4->sound = pRVar6;
          pRVar4->map_low_color = (uchar)hi_color;
          pRVar4->map_med_color = (uchar)is_animated;
          pRVar4->map_hi_color = (uchar)animation_frames;
          interval = (float)pRVar8;
          convert_us(name + 4);
          uVar9 = 0xffffffff;
          pcVar12 = name + 4;
          do {
            pcVar13 = pcVar12;
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            pcVar13 = pcVar12 + 1;
            cVar1 = *pcVar12;
            pcVar12 = pcVar13;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          pcVar12 = pcVar13 + -uVar9;
          pcVar13 = pRVar4->name;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
          uVar9 = 0xffffffff;
          pcVar12 = pict_name + 4;
          do {
            pcVar13 = pcVar12;
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            pcVar13 = pcVar12 + 1;
            cVar1 = *pcVar12;
            pcVar12 = pcVar13;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          pcVar12 = pcVar13 + -uVar9;
          pcVar13 = pRVar4->pict_name;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
          pRVar4->loaded = '\x01';
          pRVar4->resource_id = local_28;
          pRVar4->is_animated = (uchar)tile_flag;
          pRVar4->animation_frames = underlay_terrain;
          if (local_40 == _DAT_005706ac) {
            sVar3 = 0;
          }
          else {
            sVar3 = __ftol();
          }
          pRVar4->pause_frames = sVar3;
          pRVar4->interval = local_40;
          pRVar4->pause_between_loops = (float)infile;
          pRVar4->frame = 0;
          pRVar4->draw_frame = 0;
          pRVar4->animate_last = 0.0;
          pRVar4->frame_changed = '\0';
          pRVar4->drawn = '\0';
          pRVar4->draw_tile = (uchar)border_style;
          pRVar4->underlay_terrain = random;
          pRVar4->border_style = local_48;
          iVar7 = local_30;
          this = (RGE_Map *)name._0_4_;
        }
        resource_id = resource_id + -1;
      } while (resource_id != 0);
    }
  }
  fclose(iVar7);
  return;
}

// --------------------------------------------------

// Function: load_terrain_obj_types
// Address: 00458600
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd__hd__hd: "%hd %hd %hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: flag */
/* public: void __thiscall RGE_Map::load_terrain_obj_types(char *) */

void __thiscall RGE_Map::load_terrain_obj_types(RGE_Map *this,char *param_1)
{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  short flag;
  short density;
  short obj_id;
  short num;
  short local_6;
  undefined4 local_4;
  
  iVar3 = fopen(param_1,s_r);
  if (iVar3 != 0) {
    fscanf(iVar3,s__hd,&local_4);
    uVar5 = fscanf(iVar3,s__hd__hd__hd__hd,&param_1,&local_6,&num,&obj_id);
    while ((int)uVar5 != -1) {
      iVar4 = (int)(short)param_1;
      if (this->terrain_types[iVar4].loaded != '\0') {
        sVar2 = this->terrain_types[iVar4].num_obj_type;
        if (sVar2 < 0x1e) {
          this->terrain_types[iVar4].obj_types[sVar2] = local_6;
          this->terrain_types[(short)param_1].obj_density[sVar2] = num;
          this->terrain_types[(short)param_1].obj_placement_flag[sVar2] = (uchar)obj_id;
          psVar1 = &this->terrain_types[(short)param_1].num_obj_type;
          *psVar1 = *psVar1 + 1;
          local_4 = CONCAT22((short)((ulonglong)uVar5 >> 0x30),sVar2);
        }
      }
      uVar5 = fscanf(iVar3,s__hd__hd__hd__hd,&param_1,&local_6,&num,&obj_id);
    }
  }
  fclose(iVar3);
  return;
}

// --------------------------------------------------

// Function: delete_objects_on_tile
// Address: 00458760
/* public: void __thiscall RGE_Map::delete_objects_on_tile(class RGE_Player *,class RGE_Game_World
   *,int,int,int,int) */

void __thiscall
RGE_Map::delete_objects_on_tile
          (RGE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2,int param_3,int param_4,
          int param_5,int param_6)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  
  if ((((-1 < param_3) && (param_3 < this->map_width)) && (-1 < param_4)) &&
     (param_4 < this->map_height)) {
    pRVar1 = this->map_row_offset[param_4][param_3].objects.list;
    while (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      pRVar1 = pRVar1->next;
      iVar3 = (int)pRVar2->master_obj->id;
      if (((pRVar2->owner == param_1) && ((iVar3 < param_5 || (param_6 < iVar3)))) &&
         (pRVar2 != (RGE_Static_Object *)0x0)) {
        (**(code **)pRVar2->_padding_)(1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: delete_all_objects_on_tile
// Address: 004587d0
/* public: void __thiscall RGE_Map::delete_all_objects_on_tile(int,int) */

void __thiscall RGE_Map::delete_all_objects_on_tile(RGE_Map *this,int param_1,int param_2)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_Node *pRVar2;
  RGE_Static_Object **ppRVar3;
  
  if ((((-1 < param_1) && (param_1 < this->map_width)) && (-1 < param_2)) &&
     (param_2 < this->map_height)) {
    pRVar2 = this->map_row_offset[param_2][param_1].objects.list;
    while (pRVar2 != (RGE_Object_Node *)0x0) {
      pRVar1 = pRVar2->next;
      ppRVar3 = &pRVar2->node;
      pRVar2 = pRVar1;
      if (*ppRVar3 != (RGE_Static_Object *)0x0) {
        (**(code **)(*ppRVar3)->_padding_)(1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: create_terrain_object
// Address: 00458820
// [HELPER] s_C__msdev_work_age1_x1_map_cpp: "C:\msdev\work\age1_x1\map.cpp"
/* WARNING: Variable defined which should be unmapped: y */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::create_terrain_object(class RGE_Player *,class RGE_Game_World
   *,short,short,short,int,int,int) */

void __thiscall
RGE_Map::create_terrain_object
          (RGE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2,short param_3,short param_4,
          short param_5,int param_6,int param_7,int param_8)
{
  uchar uVar1;
  short sVar2;
  RGE_Object_Node *pRVar3;
  RGE_Static_Object *pRVar4;
  RGE_Master_Static_Object *pRVar5;
  bool bVar6;
  byte bVar7;
  char cVar8;
  ushort uVar9;
  short sVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  short sVar14;
  float y;
  float x;
  float local_c;
  short end_i;
  
  local_c = 0.0;
  x = 0.0;
  bVar7 = get_terrain(this,param_4,param_3);
  uVar9 = (ushort)bVar7;
  sVar14 = this->terrain_types[(short)uVar9].num_obj_type;
  if (0 < sVar14) {
    pRVar3 = this->map_row_offset[param_3][param_4].objects.list;
    while (pRVar3 != (RGE_Object_Node *)0x0) {
      pRVar4 = pRVar3->node;
      pRVar3 = pRVar3->next;
      sVar2 = pRVar4->master_obj->id;
      if ((pRVar4->owner == param_1) && ((sVar2 < param_7 || (param_8 < sVar2)))) {
        if (param_5 < 0) {
          if (param_6 == 0) {
            (**(code **)(pRVar4->_padding_ + 0x68))();
          }
          else if (pRVar4 != (RGE_Static_Object *)0x0) {
            (**(code **)pRVar4->_padding_)(1);
          }
        }
        else {
          sVar10 = this->terrain_types[param_5].num_obj_type;
          if (-1 < sVar10) {
            do {
              if (this->terrain_types[param_5].obj_types[sVar10] == sVar2) break;
              sVar10 = sVar10 + -1;
            } while (-1 < sVar10);
            if (-1 < sVar10) {
              if (param_6 == 0) {
                (**(code **)(pRVar4->_padding_ + 0x68))();
              }
              else if (pRVar4 != (RGE_Static_Object *)0x0) {
                (**(code **)pRVar4->_padding_)(1);
              }
            }
          }
        }
      }
    }
    if (0 < sVar14) {
      param_7 = (int)sVar14;
      _param_5 = this->terrain_types[(short)uVar9].obj_placement_flag;
      psVar12 = this->terrain_types[(short)uVar9].obj_density;
      do {
        if (psVar12[-0x1e] != -1) {
          sVar14 = *psVar12;
          pRVar5 = param_1->master_objects[psVar12[-0x1e]];
          uVar1 = *_param_5;
          if ((pRVar5 != (RGE_Master_Static_Object *)0x0) && (0 < sVar14)) {
            iVar13 = (int)sVar14;
            do {
              if (uVar1 == '\0') {
                iVar11 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x813);
                local_c = (float)(int)param_4 - (float)iVar11 * _DAT_005706b4;
                iVar11 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x814);
                x = (float)(int)param_3 - (float)iVar11 * _DAT_005706b4;
              }
              else if (uVar1 == '\x01') {
                local_c = (float)(int)param_4 - _DAT_005706b0;
                x = (float)(int)param_3 - _DAT_005706b0;
              }
              if (sVar14 < 1000) {
                iVar11 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x820);
                bVar6 = (iVar11 * 1000) / 0x7fff < iVar13;
              }
              else {
                bVar6 = true;
              }
              if (bVar6) {
                iVar11 = pRVar5->_padding_;
                cVar8 = (**(code **)(iVar11 + 0x20))(param_1,local_c,x,0,0,1,0,1,0,1);
                if (cVar8 == '\0') {
                  (**(code **)(iVar11 + 0x18))(param_1,local_c,x,0);
                }
              }
              sVar14 = sVar14 + -1000;
              iVar13 = iVar13 + -1000;
            } while (0 < sVar14);
          }
        }
        psVar12 = psVar12 + 1;
        _param_5 = _param_5 + 1;
        param_7 = param_7 + -1;
      } while (param_7 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: clear_terrain_object
// Address: 00458b40
/* public: int __thiscall RGE_Map::clear_terrain_object(class RGE_Game_World
   *,short,short,short,int,int,int) */

int __thiscall
RGE_Map::clear_terrain_object
          (RGE_Map *this,RGE_Game_World *param_1,short param_2,short param_3,short param_4,
          int param_5,int param_6,int param_7)
{
  short sVar1;
  RGE_Object_Node *pRVar2;
  RGE_Object_Node *pRVar3;
  short sVar4;
  char cVar5;
  short sVar6;
  RGE_Static_Object *pRVar7;
  
  get_terrain(this,param_3,param_2);
  pRVar2 = this->map_row_offset[param_2][param_3].objects.list;
  sVar4 = -1;
joined_r0x00458b74:
  do {
    while( true ) {
      do {
        pRVar3 = pRVar2;
        if (pRVar3 == (RGE_Object_Node *)0x0) {
          return (int)sVar4;
        }
        pRVar7 = pRVar3->node;
        pRVar2 = pRVar3->next;
        sVar1 = pRVar7->master_obj->id;
      } while ((param_6 <= sVar1) && (sVar1 <= param_7));
      if (-1 < param_4) break;
      if (param_5 == 0) {
        (**(code **)(pRVar7->_padding_ + 0x68))();
      }
      else if (pRVar7 != (RGE_Static_Object *)0x0) {
        (**(code **)pRVar7->_padding_)(1);
      }
    }
    sVar6 = this->terrain_types[param_4].num_obj_type;
    sVar4 = sVar1;
    if (sVar6 < 0) break;
    do {
      if (this->terrain_types[param_4].obj_types[sVar6] == sVar1) break;
      sVar6 = sVar6 + -1;
    } while (-1 < sVar6);
    if (sVar6 < 0) break;
    if (param_5 == 0) goto LAB_00458c62;
    if (pRVar7 != (RGE_Static_Object *)0x0) {
      (**(code **)pRVar7->_padding_)(1);
    }
  } while( true );
  cVar5 = (**(code **)(pRVar7->master_obj->_padding_ + 0x20))
                    (pRVar7->owner,pRVar7->world_x,pRVar7->world_y,0,0,1,1,1,0,0);
  if (cVar5 != '\0') {
    pRVar7 = pRVar3->node;
    if (param_5 == 0) {
LAB_00458c62:
      (**(code **)(pRVar7->_padding_ + 0x68))();
    }
    else if (pRVar7 != (RGE_Static_Object *)0x0) {
      (**(code **)pRVar7->_padding_)(1);
    }
  }
  goto joined_r0x00458b74;
}

// --------------------------------------------------

// Function: place_terrain_object
// Address: 00458c90
// [HELPER] s_C__msdev_work_age1_x1_map_cpp: "C:\msdev\work\age1_x1\map.cpp"
/* WARNING: Variable defined which should be unmapped: obj_flag */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::place_terrain_object(class RGE_Player *,class RGE_Game_World
   *,short,short,int,int) */

void __thiscall
RGE_Map::place_terrain_object
          (RGE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2,short param_3,short param_4,
          int param_5,int param_6)
{
  uchar uVar1;
  RGE_Master_Static_Object *pRVar2;
  bool bVar3;
  float fVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  uchar obj_flag;
  float y;
  float x;
  short obj_density;
  int local_20;
  int i;
  int terrain;
  int end_i;
  
  bVar5 = get_terrain(this,param_4,param_3);
  iVar8 = (int)this->terrain_types[bVar5].num_obj_type;
  terrain = 0;
  if (iVar8 < 1) {
    return;
  }
  i = (int)this->terrain_types[bVar5].obj_types;
  do {
    if (*(short *)i != -1) {
      pRVar2 = param_1->master_objects[*(short *)i];
      sVar9 = this->terrain_types[bVar5].obj_density[terrain];
      uVar1 = this->terrain_types[bVar5].obj_placement_flag[terrain];
      if (pRVar2 != (RGE_Master_Static_Object *)0x0) {
        if (param_6 == 0) {
          if (0 < sVar9) {
            local_20 = (int)sVar9;
            do {
              if (uVar1 == '\0') {
                iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x894);
                _obj_density = (float)(int)param_4 - (float)iVar7 * _DAT_005706b4;
                iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x895);
                fVar4 = (float)(int)param_3 - (float)iVar7 * _DAT_005706b4;
              }
              else {
                _obj_density = (float)(int)param_4 - _DAT_005706b0;
                fVar4 = (float)(int)param_3 - _DAT_005706b0;
              }
              if (sVar9 < 1000) {
                iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x8a2);
                bVar3 = (iVar7 * 1000) / 0x7fff < local_20;
              }
              else {
                bVar3 = true;
              }
              if (bVar3) {
                iVar7 = pRVar2->_padding_;
                cVar6 = (**(code **)(iVar7 + 0x20))(param_1,_obj_density,fVar4,0,0,1,0,1,0,1);
                if (cVar6 == '\0') {
                  (**(code **)(iVar7 + 0x18))(param_1,_obj_density,fVar4,0);
                }
              }
              sVar9 = sVar9 + -1000;
              local_20 = local_20 + -1000;
            } while (0 < sVar9);
          }
        }
        else if ((pRVar2 != (RGE_Master_Static_Object *)0x0) && (param_6 == 1)) {
          if (uVar1 == '\0') {
            iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x8af);
            _obj_density = (float)(int)param_4 - (float)iVar7 * _DAT_005706b4;
            iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x8b0);
            fVar4 = (float)(int)param_3 - (float)iVar7 * _DAT_005706b4;
          }
          else {
            _obj_density = (float)(int)param_4 - _DAT_005706b0;
            fVar4 = (float)(int)param_3 - _DAT_005706b0;
          }
          cVar6 = (**(code **)(pRVar2->_padding_ + 0x20))(param_1,_obj_density,fVar4,0,0,1,0,1,0,1);
          if (cVar6 == '\0') {
            (**(code **)(pRVar2->_padding_ + 0x18))(param_1,_obj_density,fVar4,0);
            return;
          }
        }
      }
    }
    terrain = terrain + 1;
    i = i + 2;
    if (iVar8 <= terrain) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: create_terrain_objects
// Address: 00458fd0
/* public: void __thiscall RGE_Map::create_terrain_objects(class RGE_Player *,class RGE_Game_World
   *) */

void __thiscall
RGE_Map::create_terrain_objects(RGE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2)
{
  short sVar1;
  short sVar2;
  
  sVar1 = 0;
  if (0 < this->map_height) {
    do {
      sVar2 = 0;
      if (0 < this->map_width) {
        do {
          create_terrain_object(this,param_1,param_2,sVar1,sVar2,-1,0,-1,-1);
          sVar2 = sVar2 + 1;
        } while ((int)sVar2 < this->map_width);
      }
      sVar1 = sVar1 + 1;
    } while ((int)sVar1 < this->map_height);
  }
  return;
}

// --------------------------------------------------

// Function: set_tile_size
// Address: 00459020
/* public: void __thiscall RGE_Map::set_tile_size(unsigned char,short,short,short) */

void __thiscall
RGE_Map::set_tile_size(RGE_Map *this,uchar param_1,short param_2,short param_3,short param_4)
{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  this->tilesizes[uVar1].width = param_2;
  this->tilesizes[uVar1].height = param_3;
  this->tilesizes[uVar1].y_delta = param_4;
  return;
}

// --------------------------------------------------

// Function: tile_map_coords
// Address: 00459060
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::tile_map_coords(short,short,struct RGE_Tile *,float *,float *)
    */

void __thiscall
RGE_Map::tile_map_coords
          (RGE_Map *this,short param_1,short param_2,RGE_Tile *param_3,float *param_4,float *param_5
          )
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  double z;
  
  iVar5 = (int)param_2;
  fVar4 = (float)(int)param_1 / (float)(int)this->tile_width;
  fVar3 = 0.0;
  fVar1 = (float)iVar5 / (float)(int)this->tile_height;
  switch(param_3->tile_type) {
  case '\0':
  case '\t':
    goto switchD_004590c7_caseD_0;
  case '\x01':
    if (fVar4 <= (float)_DAT_005706c0) {
      fVar3 = (fVar1 + fVar1) - (((float)_DAT_005706c0 - fVar4) + ((float)_DAT_005706c0 - fVar4));
    }
    else {
      fVar3 = (fVar1 + fVar1) - ((fVar4 - (float)_DAT_005706c0) + (fVar4 - (float)_DAT_005706c0));
    }
    break;
  case '\x02':
    if ((float)_DAT_005706c0 < fVar4) {
      fVar3 = fVar4 * (float)_DAT_005706d0 - (fVar1 - (float)_DAT_005706c0);
      break;
    }
    goto switchD_004590c7_caseD_8;
  case '\x03':
    fVar3 = (float)_DAT_005706d8 - fVar4;
    if (fVar4 * (float)_DAT_005706c0 < (float)iVar5) {
      fVar3 = fVar3 * (float)_DAT_005706c0 - (fVar1 - (float)_DAT_005706c0);
      break;
    }
    fVar2 = fVar1 + fVar1;
    fVar3 = (fVar3 + fVar3) - (float)_DAT_005706d8;
    goto LAB_00459318;
  case '\x04':
    if (((float)_DAT_005706d8 - fVar4) * (float)_DAT_005706c0 < (float)iVar5) {
      fVar3 = fVar4 * (float)_DAT_005706c0 - (fVar1 - (float)_DAT_005706c0);
      break;
    }
  case '\a':
switchD_004590c7_caseD_7:
    fVar2 = fVar1 + fVar1;
    fVar3 = (fVar4 + fVar4) - (float)_DAT_005706d8;
LAB_00459318:
    fVar3 = fVar3 + fVar2;
    break;
  case '\x05':
    goto switchD_004590c7_caseD_5;
  case '\x06':
switchD_004590c7_caseD_6:
    fVar3 = fVar4 * (float)_DAT_005706d0 - (fVar1 - (float)_DAT_005706c0);
    break;
  case '\b':
    goto switchD_004590c7_caseD_8;
  case '\n':
    if ((float)_DAT_005706d8 <= fVar1) {
      fVar3 = -1.0;
    }
    else {
      fVar3 = -fVar1;
    }
    break;
  case '\v':
    if (fVar4 <= (float)_DAT_005706c0) {
      fVar3 = ((float)_DAT_005706c0 - fVar4) + ((float)_DAT_005706c0 - fVar4);
      break;
    }
    goto switchD_004590c7_caseD_0;
  case '\f':
    if ((float)_DAT_005706c0 < fVar4) {
      fVar3 = (fVar4 - (float)_DAT_005706c0) + (fVar4 - (float)_DAT_005706c0);
      break;
    }
switchD_004590c7_caseD_0:
    fVar3 = 0.0;
    break;
  case '\r':
    if (fVar4 <= (float)_DAT_005706c0) {
      fVar3 = ((float)_DAT_005706c0 - fVar4) + fVar1;
      fVar3 = fVar3 + fVar3;
    }
    else {
      fVar3 = (fVar4 - (float)_DAT_005706c0) + fVar1;
      fVar3 = fVar3 + fVar3;
    }
    break;
  case '\x0e':
    if (fVar4 <= (float)_DAT_005706c0) goto switchD_004590c7_caseD_6;
    goto switchD_004590c7_caseD_8;
  case '\x0f':
    if ((float)iVar5 <= (float)_DAT_005706d8 - fVar4 * (float)_DAT_005706c0)
    goto switchD_004590c7_caseD_7;
switchD_004590c7_caseD_8:
    fVar3 = ((float)_DAT_005706d8 - fVar4) * (float)_DAT_005706d0 - (fVar1 - (float)_DAT_005706c0);
    break;
  case '\x10':
    if ((float)_DAT_005706d8 - ((float)_DAT_005706d8 - fVar4) * (float)_DAT_005706c0 < (float)iVar5)
    goto switchD_004590c7_caseD_6;
switchD_004590c7_caseD_5:
    fVar3 = fVar1 + fVar1;
    fVar2 = (float)_DAT_005706d8 - (fVar4 + fVar4);
    goto LAB_00459318;
  }
  fVar1 = (((fVar4 + fVar4) - ((float)_DAT_005706d8 - (fVar1 + fVar1))) + fVar3) *
          (float)_DAT_005706c0;
  *param_5 = fVar1;
  *param_4 = (fVar4 + fVar4) - fVar1;
  return;
}

// --------------------------------------------------

// Function: check_map_coords
// Address: 004593a0
/* public: unsigned char __thiscall RGE_Map::check_map_coords(short,short) */

uchar __thiscall RGE_Map::check_map_coords(RGE_Map *this,short param_1,short param_2)
{
  if ((((-1 < param_1) && ((int)param_1 < this->map_width)) && (-1 < param_2)) &&
     ((int)param_2 < this->map_height)) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_elev
// Address: 004593d0
/* public: unsigned char __thiscall RGE_Map::get_elev(short,short) */

uchar __thiscall RGE_Map::get_elev(RGE_Map *this,short param_1,short param_2)
{
  byte bVar1;
  
  bVar1 = (byte)this->map_row_offset[param_2][param_1].field_0x5 >> 5;
  if (8 < bVar1) {
    bVar1 = 0;
  }
  return bVar1;
}

// --------------------------------------------------

// Function: get_terrain
// Address: 00459400
/* public: unsigned char __thiscall RGE_Map::get_terrain(short,short) */

uchar __thiscall RGE_Map::get_terrain(RGE_Map *this,short param_1,short param_2)
{
  byte bVar1;
  
  bVar1 = this->map_row_offset[param_2][param_1].field_0x5 & 0x1f;
  if ((0x20 < bVar1) ||
     ((this->terrain_types[bVar1].loaded == '\0' && (this->terrain_types[bVar1].terrain_to_draw < 0)
      ))) {
    bVar1 = 0;
  }
  return bVar1;
}

// --------------------------------------------------

// Function: get_border
// Address: 00459460
/* public: unsigned char __thiscall RGE_Map::get_border(short,short) */

uchar __thiscall RGE_Map::get_border(RGE_Map *this,short param_1,short param_2)
{
  byte bVar1;
  
  bVar1 = this->map_row_offset[param_2][param_1].field_0x6 & 0xf;
  _param_2 = (uint)bVar1;
  if ((0x10 < bVar1) || (this->border_types[_param_2].loaded == '\0')) {
    bVar1 = 0;
  }
  return bVar1;
}

// --------------------------------------------------

// Function: set_terrain_passablity
// Address: 004594b0
/* public: void __thiscall RGE_Map::set_terrain_passablity(short,short,short,short,unsigned char) */

void __thiscall
RGE_Map::set_terrain_passablity
          (RGE_Map *this,short param_1,short param_2,short param_3,short param_4,uchar param_5)
{
  byte bVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  byte bVar5;
  int iVar6;
  int local_4;
  
  sVar4 = param_4;
  if (param_4 < param_2) {
    sVar4 = param_2;
    param_2 = param_4;
  }
  sVar3 = param_1;
  if (param_3 < param_1) {
    sVar3 = param_3;
    param_3 = param_1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (this->map_height <= (int)sVar4) {
    sVar4 = (short)this->map_height + -1;
  }
  if (sVar3 < 0) {
    sVar3 = 0;
  }
  if (this->map_width <= (int)param_3) {
    param_3 = (short)this->map_width + -1;
  }
  if (param_2 <= sVar4) {
    iVar6 = (int)param_2;
    _param_2 = iVar6 * 4;
    local_4 = (sVar4 - iVar6) + 1;
    do {
      if (sVar3 <= param_3) {
        iVar6 = sVar3 * 0x18;
        _param_4 = ((int)param_3 - (int)sVar3) + 1;
        do {
          iVar2 = *(int *)((int)this->map_row_offset + _param_2);
          bVar1 = *(byte *)(iVar2 + 5 + iVar6);
          iVar2 = iVar2 + iVar6;
          if (param_5 == '\0') {
            bVar5 = this->terrain_types[(short)(ushort)(bVar1 & 0x1f)].impassable_terrain;
          }
          else {
            bVar5 = this->terrain_types[(short)(ushort)(bVar1 & 0x1f)].passable_terrain;
          }
          iVar6 = iVar6 + 0x18;
          *(byte *)(iVar2 + 5) = (bVar5 ^ bVar1) & 0x1f ^ bVar1;
          _param_4 = _param_4 + -1;
        } while (_param_4 != 0);
      }
      _param_2 = _param_2 + 4;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: set_elev
// Address: 004595e0
/* public: void __thiscall RGE_Map::set_elev(short,short,short,short,unsigned char,short,unsigned
   char) */

void __thiscall
RGE_Map::set_elev(RGE_Map *this,short param_1,short param_2,short param_3,short param_4,
                 uchar param_5,short param_6,uchar param_7)
{
  RGE_Player *pRVar1;
  int *piVar2;
  int *piVar3;
  uchar uVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  short sVar12;
  int iVar13;
  RGE_Player *cur_player;
  
  pRVar1 = this->game_world->players[this->game_world->curr_player];
  sVar5 = param_2;
  if (param_4 < param_2) {
    sVar5 = param_4;
    param_4 = param_2;
  }
  sVar11 = param_1;
  if (param_3 < param_1) {
    sVar11 = param_3;
    param_3 = param_1;
  }
  if (sVar5 < 0) {
    sVar5 = 0;
  }
  if (this->map_height <= (int)param_4) {
    param_4 = (short)this->map_height + -1;
  }
  if (sVar11 < 0) {
    sVar11 = 0;
  }
  if (this->map_width <= (int)param_3) {
    param_3 = (short)this->map_width + -1;
  }
  if (param_7 != '\0') {
    if (param_6 == 0) {
      if (8 < param_5) {
        param_5 = '\0';
      }
      if (sVar5 <= param_4) {
        iVar9 = sVar5 * 4;
        _param_7 = ((int)param_4 - (int)sVar5) + 1;
        do {
          if (sVar11 <= param_3) {
            iVar10 = sVar11 * 0x18;
            iVar13 = ((int)param_3 - (int)sVar11) + 1;
            do {
              iVar7 = *(int *)(iVar9 + (int)this->map_row_offset) + iVar10;
              iVar10 = iVar10 + 0x18;
              iVar13 = iVar13 + -1;
              *(byte *)(iVar7 + 5) = *(byte *)(iVar7 + 5) & 0x1f | param_5 << 5;
            } while (iVar13 != 0);
          }
          iVar9 = iVar9 + 4;
          _param_7 = _param_7 + -1;
        } while (_param_7 != 0);
      }
    }
    else if (sVar5 <= param_4) {
      iVar9 = sVar5 * 4;
      _param_5 = ((int)param_4 - (int)sVar5) + 1;
      do {
        if (sVar11 <= param_3) {
          iVar10 = sVar11 * 0x18;
          iVar13 = ((int)param_3 - (int)sVar11) + 1;
          do {
            iVar7 = *(int *)(iVar9 + (int)this->map_row_offset) + iVar10;
            sVar6 = (ushort)(*(byte *)(iVar7 + 5) >> 5) + param_6;
            if (sVar6 < 0) {
              sVar6 = 0;
            }
            else if (0xff < sVar6) {
              sVar6 = 0xff;
            }
            bVar8 = *(byte *)(iVar7 + 5) & 0x1f;
            *(byte *)(iVar7 + 5) = (byte)sVar6 << 5 | bVar8;
            if (8 < ((byte)sVar6 & 7)) {
              *(byte *)(iVar7 + 5) = bVar8;
            }
            iVar10 = iVar10 + 0x18;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        iVar9 = iVar9 + 4;
        _param_5 = _param_5 + -1;
      } while (_param_5 != 0);
    }
  }
  if (0 < sVar5) {
    sVar5 = sVar5 + -1;
  }
  if ((int)param_4 < this->map_height + -1) {
    param_4 = param_4 + 1;
  }
  if (0 < sVar11) {
    sVar11 = sVar11 + -1;
  }
  if ((int)param_3 < this->map_width + -1) {
    param_3 = param_3 + 1;
  }
  if (sVar5 <= param_4) {
    _param_6 = (int)sVar5;
    cur_player = (RGE_Player *)(_param_6 << 2);
    sVar6 = sVar5;
    do {
      if (sVar11 <= param_3) {
        _param_5 = (int)sVar11;
        iVar9 = _param_5 * 0x18;
        sVar12 = sVar11;
        do {
          iVar10 = *(int *)((int)&cur_player->_padding_ + (int)this->map_row_offset) + iVar9;
          uVar4 = get_tile_type(this,sVar12,sVar6);
          *(uchar *)(iVar10 + 4) = uVar4;
          for (piVar2 = *(int **)(iVar10 + 0x10); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
            piVar3 = (int *)*piVar2;
            (**(code **)(*piVar3 + 0x34))(piVar3[0xe],piVar3[0xf],0);
          }
          if (this->game_world->game_state != '\x03') {
            RGE_Tile_List::add_node(&pRVar1->diam_tile_list,_param_5,_param_6);
          }
          sVar12 = sVar12 + 1;
          _param_5 = _param_5 + 1;
          iVar9 = iVar9 + 0x18;
        } while (sVar12 <= param_3);
      }
      sVar6 = sVar6 + 1;
      _param_6 = _param_6 + 1;
      cur_player = (RGE_Player *)&cur_player->computerPlayerValue;
    } while (sVar6 <= param_4);
  }
  set_map_screen_pos(this,(int)sVar11,(int)sVar5,(int)param_3,(int)param_4);
  request_redraw(this,(int)sVar11,(int)sVar5,(int)param_3,(int)param_4,'\0');
  return;
}

// --------------------------------------------------

// Function: set_terrain
// Address: 00459900
/* WARNING: Variable defined which should be unmapped: old_terrain */
/* public: void __thiscall RGE_Map::set_terrain(class RGE_Game_World *,short,short,unsigned
   char,int,int) */

void __thiscall
RGE_Map::set_terrain
          (RGE_Map *this,RGE_Game_World *param_1,short param_2,short param_3,uchar param_4,
          int param_5,int param_6)
{
  byte bVar1;
  RGE_Player *pRVar2;
  RGE_Player *pRVar3;
  int iVar4;
  int iVar5;
  short old_terrain;
  RGE_Player *obj_owner;
  RGE_Player *cur_player;
  
  pRVar2 = *param_1->players;
  iVar4 = (int)param_3;
  iVar5 = (int)param_2;
  pRVar3 = this->game_world->players[this->game_world->curr_player];
  bVar1 = this->map_row_offset[iVar4][iVar5].field_0x5;
  if (((ushort)(bVar1 & 0x1f) != (ushort)param_4) &&
     (this->map_row_offset[iVar4][iVar5].field_0x5 = (param_4 ^ bVar1) & 0x1f ^ bVar1,
     pRVar2 != (RGE_Player *)0x0)) {
    request_redraw(this,iVar5,iVar4,iVar5,iVar4,'\0');
    if (param_1->game_state != '\x03') {
      RGE_Tile_List::add_node(&pRVar3->diam_tile_list,iVar5,iVar4);
    }
    iVar4 = clear_terrain_object
                      (this,param_1,param_3,param_2,(ushort)(bVar1 & 0x1f),1,param_5,param_6);
    place_terrain_object(this,pRVar2,param_1,param_3,param_2,iVar4,0);
    get_border_type(this,param_2,param_3);
    return;
  }
  get_border_type(this,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: set_terrain_absolute
// Address: 00459a00
/* WARNING: Variable defined which should be unmapped: obj_owner */
/* public: void __thiscall RGE_Map::set_terrain_absolute(class RGE_Game_World *,short,short,unsigned
   char,int,int) */

void __thiscall
RGE_Map::set_terrain_absolute
          (RGE_Map *this,RGE_Game_World *param_1,short param_2,short param_3,uchar param_4,
          int param_5,int param_6)
{
  byte bVar1;
  RGE_Player *pRVar2;
  int iVar3;
  RGE_Player *obj_owner;
  
  pRVar2 = *param_1->players;
  bVar1 = this->map_row_offset[param_3][param_2].field_0x5;
  this->map_row_offset[param_3][param_2].field_0x5 = (param_4 ^ bVar1) & 0x1f ^ bVar1;
  if (pRVar2 != (RGE_Player *)0x0) {
    iVar3 = clear_terrain_object(this,param_1,param_3,param_2,-1,1,param_5,param_6);
    place_terrain_object(this,pRVar2,param_1,param_3,param_2,iVar3,1);
  }
  get_border_type(this,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: set_terrain
// Address: 00459a90
/* public: void __thiscall RGE_Map::set_terrain(class RGE_Player *,class RGE_Game_World
   *,short,short,short,short,unsigned char,unsigned char,int) */

void __thiscall
RGE_Map::set_terrain
          (RGE_Map *this,RGE_Player *param_1,RGE_Game_World *param_2,short param_3,short param_4,
          short param_5,short param_6,uchar param_7,uchar param_8,int param_9)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  byte *pbVar8;
  short maprow;
  
  if ((short)(ushort)param_7 < this->num_terrain) {
    uVar2 = (uint)param_7;
    if ((this->terrain_types[uVar2].loaded != '\0') ||
       ((sVar6 = this->terrain_types[uVar2].terrain_to_draw, -1 < sVar6 &&
        (this->terrain_types[sVar6].loaded == '\x01')))) {
      sVar6 = param_4;
      if (param_6 < param_4) {
        sVar6 = param_6;
        param_6 = param_4;
      }
      sVar7 = param_3;
      if (param_5 < param_3) {
        sVar7 = param_5;
        param_5 = param_3;
      }
      if (sVar6 < 0) {
        sVar6 = 0;
      }
      if (this->map_height <= (int)param_6) {
        param_6 = (short)this->map_height + -1;
      }
      if (sVar7 < 0) {
        sVar7 = 0;
      }
      if (this->map_width <= (int)param_5) {
        param_5 = (short)this->map_width + -1;
      }
      if (((param_8 != '\0') || (param_1 != (RGE_Player *)0x0)) && (sVar6 <= param_6)) {
        iVar3 = (int)sVar6 << 2;
        sVar5 = sVar6;
        do {
          if (sVar7 <= param_5) {
            pbVar8 = (byte *)(*(int *)(iVar3 + (int)this->map_row_offset) + sVar7 * 0x18 + 5);
            sVar4 = sVar7;
            do {
              if (0 < this->terrain_types[uVar2].tiles[pbVar8[-1]].count) {
                bVar1 = *pbVar8;
                if (((ushort)(bVar1 & 0x1f) != (ushort)param_7) && (param_8 != '\0')) {
                  *pbVar8 = (param_7 ^ bVar1) & 0x1f ^ bVar1;
                }
                if (param_1 != (RGE_Player *)0x0) {
                  create_terrain_object
                            (this,param_1,param_2,sVar5,sVar4,(ushort)(bVar1 & 0x1f),param_9,-1,-1);
                }
              }
              sVar4 = sVar4 + 1;
              pbVar8 = pbVar8 + 0x18;
            } while (sVar4 <= param_5);
          }
          sVar5 = sVar5 + 1;
          iVar3 = iVar3 + 4;
        } while (sVar5 <= param_6);
      }
      if (0 < sVar6) {
        sVar6 = sVar6 + -1;
      }
      if ((int)param_6 < this->map_height + -1) {
        param_6 = param_6 + 1;
      }
      if (0 < sVar7) {
        sVar7 = sVar7 + -1;
      }
      sVar5 = sVar6;
      if ((int)param_5 < this->map_width + -1) {
        param_5 = param_5 + 1;
      }
      for (; sVar4 = sVar7, sVar5 <= param_6; sVar5 = sVar5 + 1) {
        for (; sVar4 <= param_5; sVar4 = sVar4 + 1) {
          get_border_type(this,sVar4,sVar5);
        }
      }
      request_redraw(this,(int)sVar7,(int)sVar6,(int)param_5,(int)param_6,'\0');
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_tile_type
// Address: 00459d20
/* WARNING: Variable defined which should be unmapped: ecl */
/* public: unsigned char __thiscall RGE_Map::get_tile_type(short,short) */

uchar __thiscall RGE_Map::get_tile_type(RGE_Map *this,short param_1,short param_2)
{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  RGE_Tile **ppRVar5;
  RGE_Tile *pRVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  ushort uVar15;
  ushort uVar16;
  short ecl;
  short etr;
  short etl;
  short et;
  short eb;
  short ech;
  
  if (-1 < param_1) {
    iVar3 = this->map_width;
    iVar13 = (int)param_1;
    if ((iVar13 < iVar3) && (-1 < param_2)) {
      iVar4 = this->map_height;
      iVar14 = (int)param_2;
      if (iVar14 < iVar4) {
        ppRVar5 = this->map_row_offset;
        pRVar6 = ppRVar5[iVar14];
        uVar16 = (ushort)((byte)pRVar6[iVar13].field_0x5 >> 5);
        uVar1 = uVar16 + 1;
        uVar2 = uVar16 - 1;
        uVar7 = uVar16;
        if ((0 < param_2) && (iVar13 < iVar3 + -1)) {
          uVar7 = (ushort)((byte)ppRVar5[iVar14 + -1][iVar13 + 1].field_0x5 >> 5);
        }
        uVar12 = uVar16;
        if (0 < param_2) {
          uVar12 = (ushort)((byte)ppRVar5[iVar14 + -1][iVar13].field_0x5 >> 5);
        }
        uVar11 = uVar16;
        if (iVar13 < iVar3 + -1) {
          uVar11 = (ushort)((byte)pRVar6[iVar13 + 1].field_0x5 >> 5);
        }
        uVar10 = uVar16;
        if ((0 < param_1) && (iVar14 < iVar4 + -1)) {
          uVar10 = (ushort)((byte)ppRVar5[iVar14 + 1][iVar13 + -1].field_0x5 >> 5);
        }
        uVar9 = uVar16;
        if (0 < param_1) {
          uVar9 = (ushort)((byte)pRVar6[iVar13 + -1].field_0x5 >> 5);
        }
        uVar15 = uVar16;
        if (iVar14 < iVar4 + -1) {
          uVar15 = (ushort)((byte)ppRVar5[iVar14 + 1][iVar13].field_0x5 >> 5);
        }
        uVar8 = uVar16;
        if ((0 < param_2) && (0 < param_1)) {
          uVar8 = (ushort)((byte)ppRVar5[iVar14 + -1][iVar13 + -1].field_0x5 >> 5);
        }
        if ((iVar14 < iVar4 + -1) && (iVar13 < iVar3 + -1)) {
          uVar16 = (ushort)((byte)ppRVar5[iVar14 + 1][iVar13 + 1].field_0x5 >> 5);
        }
        if ((uVar12 == uVar1) && (uVar11 == uVar1)) {
          return '\x0e';
        }
        if ((uVar9 == uVar1) && (uVar15 == uVar1)) {
          return '\r';
        }
        if ((uVar12 == uVar1) && (uVar9 == uVar1)) {
          return '\x10';
        }
        if ((uVar11 == uVar1) && (uVar15 == uVar1)) {
          return '\x0f';
        }
        if (uVar12 == uVar1) {
          return '\x06';
        }
        if (uVar11 == uVar1) {
          return '\b';
        }
        if (uVar9 == uVar1) {
          return '\x05';
        }
        if (uVar15 == uVar1) {
          return '\a';
        }
        if (uVar7 == uVar1) {
          if ((uVar9 == uVar2) && (uVar15 == uVar2)) {
            return '\x02';
          }
          return '\n';
        }
        if (uVar10 == uVar1) {
          if ((uVar12 == uVar2) && (uVar11 == uVar2)) {
            return '\x01';
          }
          return '\t';
        }
        if (uVar8 == uVar1) {
          if ((uVar11 == uVar2) && (uVar15 == uVar2)) {
            return '\x03';
          }
          return '\v';
        }
        if (uVar16 == uVar1) {
          if ((uVar12 == uVar2) && (uVar9 == uVar2)) {
            return '\x04';
          }
          return '\f';
        }
      }
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_border_type
// Address: 0045a030
/* WARNING: Variable defined which should be unmapped: ter_top */
/* public: void __thiscall RGE_Map::get_border_type(short,short) */

void __thiscall RGE_Map::get_border_type(RGE_Map *this,short param_1,short param_2)
{
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  RGE_Tile **ppRVar5;
  bool bVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  char cVar13;
  undefined2 in_stack_0000000a;
  uchar uVar14;
  uchar ter_top;
  uchar ter_lft;
  undefined3 uStack_27;
  uchar ter_rgt;
  undefined3 uStack_23;
  uchar ter_bot;
  undefined3 uStack_1f;
  RGE_Tile *tile;
  uchar ter_top_lft;
  uchar ter_bot_lft;
  undefined3 uStack_13;
  uchar ter_bot_rgt;
  undefined3 uStack_f;
  uint local_c;
  uchar ter_cur;
  uint local_4;
  
  if ((((-1 < param_1) && (iVar8 = (int)param_1, iVar8 < this->map_width)) && (-1 < param_2)) &&
     (iVar9 = (int)param_2, iVar9 < this->map_height)) {
    ppRVar5 = this->map_row_offset;
    _ter_top_lft = ppRVar5[iVar9] + iVar8;
    bVar1 = _ter_top_lft->field_0x5;
    bVar11 = bVar1 & 0x1f;
    local_4 = CONCAT31(local_4._1_3_,bVar1) & 0xffffff1f;
    bVar7 = bVar1;
    if (0 < param_2) {
      bVar7 = ppRVar5[iVar9 + -1][iVar8].field_0x5;
    }
    _ter_lft = CONCAT31(uStack_27,bVar7) & 0xffffff1f;
    iVar10 = this->map_height + -1;
    bVar7 = bVar1;
    if (iVar9 < iVar10) {
      bVar7 = ppRVar5[iVar9 + 1][iVar8].field_0x5;
    }
    tile = (RGE_Tile *)(CONCAT31(tile._1_3_,bVar7) & 0xffffff1f);
    bVar7 = bVar1;
    if (0 < param_1) {
      bVar7 = ppRVar5[iVar9][iVar8 + -1].field_0x5;
    }
    _ter_rgt = CONCAT31(uStack_23,bVar7) & 0xffffff1f;
    _ter_cur = this->map_width + -1;
    bVar7 = bVar1;
    if (iVar8 < _ter_cur) {
      bVar7 = ppRVar5[iVar9][iVar8 + 1].field_0x5;
    }
    _ter_bot = CONCAT31(uStack_1f,bVar7) & 0xffffff1f;
    bVar7 = bVar1;
    if ((0 < param_2) && (0 < param_1)) {
      bVar7 = ppRVar5[iVar9 + -1][iVar8 + -1].field_0x5;
    }
    _ter_bot_lft = CONCAT31(uStack_13,bVar7) & 0xffffff1f;
    bVar6 = 0 < param_2;
    bVar7 = bVar1;
    if ((bVar6) && (iVar8 < _ter_cur)) {
      bVar7 = ppRVar5[iVar9 + -1][iVar8 + 1].field_0x5;
    }
    _param_2 = CONCAT31(stack0x00000009,bVar7) & 0xffffff1f;
    uStack_f = (undefined3)((uint)iVar10 >> 8);
    bVar7 = bVar1;
    if ((iVar9 < iVar10) && (0 < param_1)) {
      bVar7 = ppRVar5[iVar9 + 1][iVar8 + -1].field_0x5;
    }
    _ter_bot_rgt = CONCAT31(uStack_f,bVar7) & 0xffffff1f;
    local_c._1_3_ = (int3)(char)((ushort)param_1 >> 8);
    bVar7 = bVar1;
    if ((iVar9 < iVar10) && (iVar8 < _ter_cur)) {
      bVar7 = ppRVar5[iVar9 + 1][iVar8 + 1].field_0x5;
    }
    local_c = CONCAT31(local_c._1_3_,bVar7) & 0xffffff1f;
    uVar14 = (uchar)local_4;
    check_for_border(this,uVar14,&ter_lft);
    check_for_border(this,uVar14,(uchar *)&tile);
    check_for_border(this,uVar14,&ter_rgt);
    check_for_border(this,uVar14,&ter_bot);
    check_for_border(this,uVar14,&ter_bot_lft);
    check_for_border(this,uVar14,(uchar *)&param_2);
    check_for_border(this,uVar14,&ter_bot_rgt);
    check_for_border(this,uVar14,(uchar *)&local_c);
    bVar7 = ter_lft;
    if ((((ter_lft != bVar11) || (bVar7 = (byte)tile, (byte)tile != bVar11)) ||
        (bVar7 = ter_rgt, ter_rgt != bVar11)) ||
       (((bVar7 = ter_bot, ter_bot != bVar11 || (bVar7 = ter_bot_lft, ter_bot_lft != bVar11)) ||
        ((bVar7 = (byte)param_2, (byte)param_2 != bVar11 ||
         ((bVar7 = ter_bot_rgt, ter_bot_rgt != bVar11 ||
          (bVar7 = (byte)local_c, (byte)local_c != bVar11)))))))) {
      uVar12 = bVar1 & 0x1f;
      _param_1 = (uint)bVar7;
      sVar2 = this->terrain_types[uVar12].borders[_param_1];
      if ((sVar2 == -1) ||
         (((sVar2 < 0 || (0xf < sVar2)) || (this->border_types[sVar2].loaded == '\0')))) {
        _ter_top_lft->field_0x6 = 0;
        return;
      }
      if (this->border_types[sVar2].border_style == 1) {
        cVar13 = this->terrain_types[uVar12].borders[_ter_lft & 0xff] == sVar2;
        if (this->terrain_types[uVar12].borders[(uint)tile & 0xff] == sVar2) {
          cVar13 = cVar13 + '\x02';
        }
        if (this->terrain_types[uVar12].borders[_ter_rgt & 0xff] == sVar2) {
          cVar13 = cVar13 + '\x04';
        }
        if (this->terrain_types[uVar12].borders[_ter_bot & 0xff] == sVar2) {
          cVar13 = cVar13 + '\b';
        }
        _ter_top_lft->field_0x6 = (byte)sVar2 & 0xf | cVar13 << 4;
        return;
      }
      sVar3 = this->terrain_types[uVar12].borders[_ter_lft & 0xff];
      if ((sVar3 == sVar2) && (this->terrain_types[uVar12].borders[_ter_rgt & 0xff] == sVar2)) {
        cVar13 = '\x01';
      }
      else if ((sVar3 == sVar2) && (this->terrain_types[uVar12].borders[_ter_bot & 0xff] == sVar2))
{
        cVar13 = '\x02';
      }
      else {
        sVar4 = this->terrain_types[uVar12].borders[(uint)tile & 0xff];
        if (sVar4 == sVar2) {
          if (this->terrain_types[uVar12].borders[_ter_rgt & 0xff] == sVar2) {
            cVar13 = '\x03';
            goto LAB_0045a436;
          }
          if ((sVar4 == sVar2) && (this->terrain_types[uVar12].borders[_ter_bot & 0xff] == sVar2)) {
            cVar13 = '\x04';
            goto LAB_0045a436;
          }
        }
        if (sVar3 == sVar2) {
          cVar13 = '\t';
        }
        else if (sVar4 == sVar2) {
          cVar13 = '\n';
        }
        else if (this->terrain_types[uVar12].borders[_ter_rgt & 0xff] == sVar2) {
          cVar13 = '\v';
        }
        else if (this->terrain_types[uVar12].borders[_ter_bot & 0xff] == sVar2) {
          cVar13 = '\f';
        }
        else if (this->terrain_types[uVar12].borders[_ter_bot_lft & 0xff] == sVar2) {
          cVar13 = '\x05';
        }
        else if (this->terrain_types[uVar12].borders[_param_2 & 0xff] == sVar2) {
          cVar13 = '\x06';
        }
        else if (this->terrain_types[uVar12].borders[_ter_bot_rgt & 0xff] == sVar2) {
          cVar13 = '\a';
        }
        else {
          if (this->terrain_types[uVar12].borders[local_c & 0xff] != sVar2) {
            _ter_top_lft->field_0x6 = 0;
            return;
          }
          cVar13 = '\b';
        }
      }
LAB_0045a436:
      _ter_top_lft->field_0x6 = (byte)sVar2 & 0xf | cVar13 << 4;
      return;
    }
    _ter_top_lft->field_0x6 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: check_for_border
// Address: 0045a490
/* public: void __thiscall RGE_Map::check_for_border(unsigned char,unsigned char &) */

void __thiscall RGE_Map::check_for_border(RGE_Map *this,uchar param_1,uchar *param_2)
{
  short sVar1;
  
  if ((*param_2 != param_1) &&
     ((((sVar1 = this->terrain_types[param_1].borders[*param_2], sVar1 == -1 || (sVar1 < 0)) ||
       (0xf < sVar1)) || (this->border_types[sVar1].loaded == '\0')))) {
    *param_2 = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 0045a500
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Map::update(unsigned long) */

void __thiscall RGE_Map::update(RGE_Map *this,ulong param_1)
{
  short sVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  short i;
  float cur_time;
  
  if (99 < param_1 - DAT_0062e65c) {
    cur_time = 0.0;
    fVar2 = (float)param_1 * _DAT_005706e8;
    if (0 < this->num_terrain) {
      do {
        sVar5 = SUB42(cur_time,0);
        if ((this->terrain_types[sVar5].is_animated != '\0') &&
           (this->terrain_types[sVar5].interval <= fVar2 - this->terrain_types[sVar5].animate_last))
{
          sVar3 = __ftol();
          sVar1 = this->terrain_types[sVar5].animation_frames;
          sVar4 = this->terrain_types[sVar5].pause_frames + sVar1;
          sVar6 = sVar3 + this->terrain_types[sVar5].frame;
          if (sVar4 <= sVar6) {
            sVar6 = sVar6 % sVar4;
          }
          this->terrain_types[sVar5].frame = sVar6;
          if (sVar1 <= sVar6) {
            sVar6 = sVar1 + -1;
          }
          if (this->terrain_types[sVar5].draw_frame != sVar6) {
            this->terrain_types[sVar5].draw_frame = sVar6;
            this->terrain_types[sVar5].frame_changed = '\x01';
            this->any_frame_change = '\x01';
          }
          this->terrain_types[sVar5].animate_last =
               (float)((float10)fVar2 -
                      (extraout_ST0 -
                      (float10)(int)sVar3 * (float10)this->terrain_types[sVar5].interval));
        }
        cur_time = (float)((int)cur_time + 1);
      } while (SUB42(cur_time,0) < this->num_terrain);
    }
    cur_time = 0.0;
    if (0 < this->num_borders) {
      do {
        sVar5 = SUB42(cur_time,0);
        if ((this->border_types[sVar5].is_animated != '\0') &&
           (this->border_types[sVar5].interval <= fVar2 - this->border_types[sVar5].animate_last)) {
          sVar3 = __ftol();
          sVar1 = this->border_types[sVar5].animation_frames;
          sVar4 = this->border_types[sVar5].pause_frames + sVar1;
          sVar6 = sVar3 + this->border_types[sVar5].frame;
          if (sVar4 <= sVar6) {
            sVar6 = sVar6 % sVar4;
          }
          this->border_types[sVar5].frame = sVar6;
          if (sVar1 <= sVar6) {
            sVar6 = sVar1 + -1;
          }
          if (this->border_types[sVar5].draw_frame != sVar6) {
            this->border_types[sVar5].draw_frame = sVar6;
            this->border_types[sVar5].frame_changed = '\x01';
            this->any_frame_change = '\x01';
          }
          this->border_types[sVar5].animate_last =
               (float)((float10)fVar2 -
                      (extraout_ST0_00 -
                      (float10)(int)sVar3 * (float10)this->border_types[sVar5].interval));
        }
        cur_time = (float)((int)cur_time + 1);
      } while (SUB42(cur_time,0) < this->num_borders);
    }
    DAT_0062e65c = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: get_point
// Address: 0045a6d0
/* public: void __thiscall RGE_Map::get_point(short &,short &,float,float,float,short,short) */

void __thiscall
RGE_Map::get_point(RGE_Map *this,short *param_1,short *param_2,float param_3,float param_4,
                  float param_5,short param_6,short param_7)
{
  short sVar1;
  
  sVar1 = __ftol();
  *param_1 = sVar1 + param_6;
  sVar1 = __ftol();
  *param_2 = sVar1 + -0x10 + param_7;
  return;
}

// --------------------------------------------------

