// Class: RGE_Visible_Map
// Function: RGE_Visible_Map
// Address: 0053c1b0
/* public: __thiscall RGE_Visible_Map::RGE_Visible_Map(class RGE_Map *,class RGE_Player *) */

RGE_Visible_Map * __thiscall
RGE_Visible_Map::RGE_Visible_Map(RGE_Visible_Map *this,RGE_Map *param_1,RGE_Player *param_2)
{
  int iVar1;
  uchar *puVar2;
  uchar **ppuVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  this->world = param_2->world;
  this->player = param_2;
  this->map = param_1;
  iVar4 = param_1->map_width;
  this->widthValue = iVar4;
  iVar1 = param_1->map_height;
  this->heightValue = iVar1;
  this->numberTilesExploredValue = 0;
  this->numberTotalTilesValue = iVar1 * iVar4;
  if ((iVar4 < 1) || (iVar1 < 1)) {
    this->visible_map = (uchar *)0x0;
    this->map_offsets = (uchar **)0x0;
  }
  else {
    puVar2 = (uchar *)calloc(iVar1 * iVar4,1);
    this->visible_map = puVar2;
    ppuVar3 = (uchar **)calloc(this->heightValue,4);
    this->map_offsets = ppuVar3;
    iVar4 = 0;
    if (0 < this->heightValue) {
      do {
        this->map_offsets[iVar4] = this->visible_map + iVar4 * this->widthValue;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->heightValue);
    }
    uVar5 = this->heightValue * this->widthValue;
    puVar2 = this->visible_map;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      puVar2[0] = 0xff;
      puVar2[1] = 0xff;
      puVar2[2] = 0xff;
      puVar2[3] = 0xff;
      puVar2 = puVar2 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar2 = 0xff;
      puVar2 = puVar2 + 1;
    }
  }
  uVar6 = 1 << ((byte)param_2->id & 0x1f);
  this->input_csum = 0;
  this->PlayerVisibleMaskValue = uVar6;
  this->PlayerVisibleMaskInvertValue = ~uVar6;
  uVar6 = this->PlayerVisibleMaskValue << 0x10;
  this->PlayerExploredMaskValue = uVar6;
  this->PlayerExploredMaskInvertValue = ~uVar6;
  return this;
}

// --------------------------------------------------

// Function: RGE_Visible_Map
// Address: 0053c290
/* WARNING: Variable defined which should be unmapped: player_id */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall RGE_Visible_Map::RGE_Visible_Map(int,class RGE_Game_World *) */

RGE_Visible_Map * __thiscall
RGE_Visible_Map::RGE_Visible_Map(RGE_Visible_Map *this,int param_1,RGE_Game_World *param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uchar *puVar4;
  uchar **ppuVar5;
  uint uVar6;
  short player_id;
  RGE_Visible_Map *local_4;
  
  piVar1 = &this->widthValue;
  this->world = param_2;
  this->map = param_2->map;
  this->numberTilesExploredValue = 0;
  local_4 = this;
  rge_read(param_1,piVar1,4);
  piVar2 = &this->heightValue;
  rge_read(param_1,piVar2,4);
  if (_DAT_005776e0 <= save_game_version) {
    rge_read(param_1,&this->numberTilesExploredValue,4);
  }
  rge_read(param_1,&local_4,2);
  iVar3 = *piVar2 * *piVar1;
  this->numberTotalTilesValue = iVar3;
  this->player = param_2->players[(short)local_4];
  if ((*piVar1 < 1) || (*piVar2 < 1)) {
    this->visible_map = (uchar *)0x0;
    this->map_offsets = (uchar **)0x0;
  }
  else {
    puVar4 = (uchar *)calloc(iVar3,1);
    this->visible_map = puVar4;
    ppuVar5 = (uchar **)calloc(*piVar2,4);
    this->map_offsets = ppuVar5;
    iVar3 = 0;
    if (0 < *piVar2) {
      do {
        this->map_offsets[iVar3] = this->visible_map + iVar3 * *piVar1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *piVar2);
    }
    rge_read(param_1,this->visible_map,*piVar1 * *piVar2);
  }
  uVar6 = 1 << ((byte)local_4 & 0x1f);
  this->input_csum = 0;
  this->PlayerVisibleMaskValue = uVar6;
  this->PlayerExploredMaskValue = uVar6 << 0x10;
  this->PlayerExploredMaskInvertValue = ~(uVar6 << 0x10);
  this->PlayerVisibleMaskInvertValue = ~uVar6;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Visible_Map
// Address: 0053c3c0
/* public: __thiscall RGE_Visible_Map::~RGE_Visible_Map(void) */

void __thiscall RGE_Visible_Map::~RGE_Visible_Map(RGE_Visible_Map *this)
{
  if (this->visible_map != (uchar *)0x0) {
    free(this->visible_map);
    this->visible_map = (uchar *)0x0;
  }
  if (this->map_offsets != (uchar **)0x0) {
    free(this->map_offsets);
    this->map_offsets = (uchar **)0x0;
  }
  this->player = (RGE_Player *)0x0;
  this->map = (RGE_Map *)0x0;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0053c400
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Visible_Map::save(int) */

void __thiscall RGE_Visible_Map::save(RGE_Visible_Map *this,int param_1)
{
  int iVar1;
  int iVar2;
  
  rge_write(param_1,&this->widthValue,4);
  rge_write(param_1,&this->heightValue,4);
  if (_DAT_005776e0 <= save_game_version) {
    rge_write(param_1,&this->numberTilesExploredValue,4);
  }
  rge_write(param_1,&this->player->id,2);
  iVar1 = this->widthValue;
  if ((0 < iVar1) && (iVar2 = this->heightValue, 0 < iVar2)) {
    rge_write(param_1,this->visible_map,iVar2 * iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: get_visible
// Address: 0053c490
/* public: unsigned char __thiscall RGE_Visible_Map::get_visible(int,int)const  */

uchar __thiscall RGE_Visible_Map::get_visible(RGE_Visible_Map *this,int param_1,int param_2)
{
  if (((uint)(&unified_map_offsets)[param_2][param_1] & this->player->mutualVisibleMask) != 0) {
    return '\x0f';
  }
  return -((this->player->mutualExploredMask & (uint)(&unified_map_offsets)[param_2][param_1]) != 0)
         & 0x80;
}

// --------------------------------------------------

// Function: set_all
// Address: 0053c4d0
/* public: void __thiscall RGE_Visible_Map::set_all(unsigned char) */

void __thiscall RGE_Visible_Map::set_all(RGE_Visible_Map *this,uchar param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong ***pppuVar5;
  uint uVar6;
  
  log_map_call(this->world->world_time,(int)this->player->id,5,0,(uint)param_1,0,0,0,0);
  iVar4 = 0;
  if (0 < this->heightValue) {
    do {
      iVar3 = 0;
      if (0 < this->widthValue) {
        do {
          iVar2 = iVar3 + 1;
          this->map_offsets[iVar4][iVar3] = param_1;
          iVar3 = iVar2;
        } while (iVar2 < this->widthValue);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->heightValue);
  }
  if ((param_1 == 0xff) || (param_1 == '\0')) {
    uVar6 = this->PlayerVisibleMaskInvertValue;
    if (param_1 == 0xff) {
      uVar6 = uVar6 & this->PlayerExploredMaskInvertValue;
    }
    iVar4 = 0;
    if (0 < this->heightValue) {
      pppuVar5 = &unified_map_offsets;
      do {
        iVar3 = 0;
        if (0 < this->widthValue) {
          do {
            (*pppuVar5)[iVar3] = (ulong *)((uint)(*pppuVar5)[iVar3] & uVar6);
            iVar3 = iVar3 + 1;
          } while (iVar3 < this->widthValue);
        }
        iVar4 = iVar4 + 1;
        pppuVar5 = pppuVar5 + 1;
      } while (iVar4 < this->heightValue);
    }
  }
  else {
    uVar6 = this->PlayerExploredMaskValue;
    uVar1 = this->PlayerVisibleMaskValue;
    iVar4 = 0;
    if (0 < this->heightValue) {
      pppuVar5 = &unified_map_offsets;
      do {
        iVar3 = 0;
        if (0 < this->widthValue) {
          do {
            (*pppuVar5)[iVar3] = (ulong *)((uint)(*pppuVar5)[iVar3] | uVar6 | uVar1);
            iVar3 = iVar3 + 1;
          } while (iVar3 < this->widthValue);
        }
        iVar4 = iVar4 + 1;
        pppuVar5 = pppuVar5 + 1;
      } while (iVar4 < this->heightValue);
    }
  }
  if (param_1 != 0xff) {
    this->numberTilesExploredValue = this->numberTotalTilesValue;
    return;
  }
  this->numberTilesExploredValue = 0;
  return;
}

// --------------------------------------------------

// Function: explore_all
// Address: 0053c5d0
/* public: void __thiscall RGE_Visible_Map::explore_all(void) */

void __thiscall RGE_Visible_Map::explore_all(RGE_Visible_Map *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  log_map_call(this->world->world_time,(int)this->player->id,6,0,0,0,0,0,0);
  iVar3 = 0;
  if (0 < this->heightValue) {
    iVar2 = 0;
    do {
      iVar4 = 0;
      if (0 < this->widthValue) {
        do {
          iVar1 = *(int *)((int)this->map_offsets + iVar2);
          if (*(char *)(iVar4 + iVar1) == -1) {
            *(undefined1 *)(iVar4 + iVar1) = 0;
            this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
            *(uint *)(*(int *)((int)&unified_map_offsets + iVar2) + iVar4 * 4) =
                 *(uint *)(*(int *)((int)&unified_map_offsets + iVar2) + iVar4 * 4) |
                 this->PlayerExploredMaskValue;
            RGE_Tile_List::add_node(&this->player->tile_list,iVar4,iVar3);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < this->widthValue);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < this->heightValue);
  }
  (this->player->tile_list).collapse_list = 1;
  return;
}

// --------------------------------------------------

// Function: percentExplored
// Address: 0053c670
/* public: float __thiscall RGE_Visible_Map::percentExplored(void)const  */

float __thiscall RGE_Visible_Map::percentExplored(RGE_Visible_Map *this)
{
  return (float)this->numberTilesExploredValue / (float)this->numberTotalTilesValue;
}

// --------------------------------------------------

// Function: recomputeExplored
// Address: 0053c680
/* public: void __thiscall RGE_Visible_Map::recomputeExplored(void) */

void __thiscall RGE_Visible_Map::recomputeExplored(RGE_Visible_Map *this)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  this->numberTilesExploredValue = 0;
  if (0 < this->heightValue) {
    do {
      iVar1 = 0;
      if (0 < this->widthValue) {
        do {
          if (this->map_offsets[iVar2][iVar1] != 0xff) {
            this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < this->widthValue);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < this->heightValue);
  }
  return;
}

// --------------------------------------------------

// Function: get_los_table
// Address: 0053c6c0
/* public: struct LOSTBL * __thiscall RGE_Visible_Map::get_los_table(int,int) */

LOSTBL * __thiscall RGE_Visible_Map::get_los_table(RGE_Visible_Map *this,int param_1,int param_2)
{
  if (0x10 < param_1) {
    param_1 = 0x10;
  }
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 != 0) {
    return (LOSTBL *)(&SquareLOS)[param_1];
  }
  return (LOSTBL *)(&NormalLOS)[param_1];
}

// --------------------------------------------------

// Function: explore_terrain
// Address: 0053c6f0
/* public: int __thiscall RGE_Visible_Map::explore_terrain(int,int,int,int,int,int) */

int __thiscall
RGE_Visible_Map::explore_terrain
          (RGE_Visible_Map *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int *piVar1;
  RGE_Player *pRVar2;
  uchar uVar3;
  uint uVar4;
  int *piVar5;
  ulong **ppuVar6;
  uchar *puVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  RGE_Player *curVisPlayer;
  int y;
  int Revealed;
  int x2;
  int VisibleToCurPlayer;
  
  iVar8 = param_3;
  Revealed = 0;
  log_map_call(this->world->world_time,(int)this->player->id,1,param_6,param_1,param_2,param_3,
               param_4,Map_Update_Suppresion);
  if (Map_Update_Suppresion != 0) {
    return 0;
  }
  uVar4 = this->input_csum << 3;
  uVar4 = (((uVar4 | this->input_csum >> 0x1d) ^ 0x1010101) << 2 | uVar4 >> 0x1e) ^
          (int)this->player->id;
  uVar4 = (uVar4 << 3 | uVar4 >> 0x1d) ^ param_1;
  uVar4 = (uVar4 << 4 | uVar4 >> 0x1c) ^ param_2;
  this->input_csum = ((uVar4 << 3 | uVar4 >> 0x1d) ^ param_3) + param_4;
  pRVar2 = this->world->players[this->world->curr_player];
  if (pRVar2 == (RGE_Player *)0x0) {
    bVar10 = false;
  }
  else {
    bVar10 = pRVar2->mutualAlly[this->player->id] == 1;
  }
  param_3 = 0;
  curVisPlayer = (RGE_Player *)0x0;
  if (bVar10) {
    curVisPlayer = pRVar2;
  }
  if (0x10 < iVar8) {
    iVar8 = 0x10;
  }
  if (param_4 == 0) {
    piVar5 = (int *)(&NormalLOS)[iVar8];
  }
  else {
    piVar5 = (int *)(&SquareLOS)[iVar8];
  }
  iVar8 = *piVar5;
  while (iVar8 != 999) {
    iVar8 = param_2 + iVar8;
    if ((-1 < iVar8) && (iVar8 < this->heightValue)) {
      iVar9 = piVar5[1] + param_1;
      if (iVar9 < 0) {
        iVar9 = 0;
      }
      x2 = piVar5[2] + param_1;
      if (this->widthValue <= x2) {
        x2 = this->widthValue + -1;
      }
      puVar7 = this->map_offsets[iVar8] + iVar9;
      ppuVar6 = (&unified_map_offsets)[iVar8] + iVar9;
      if (param_5 != 0) {
        param_3 = (int)(this->map->map_row_offset[iVar8] + iVar9);
      }
      for (; iVar9 <= x2; iVar9 = iVar9 + 1) {
        uVar3 = *puVar7 + '\x01';
        if (uVar3 == '\0') {
          Revealed = Revealed + 1;
          this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
          RGE_Tile_List::add_node(&this->player->tile_list,iVar9,iVar8);
          if (bVar10) {
            RGE_Tile_List::add_node(&curVisPlayer->diam_tile_list,iVar9,iVar8);
          }
          uVar3 = '\x01';
          *ppuVar6 = (ulong *)((uint)*ppuVar6 | this->PlayerExploredMaskValue);
        }
        if (uVar3 == '\x01') {
          if (param_5 != 0) {
            ((RGE_Tile *)param_3)->draw_as = '\x0f';
          }
          *ppuVar6 = (ulong *)((uint)*ppuVar6 | this->PlayerVisibleMaskValue);
        }
        if (uVar3 == 0xfa) {
          uVar3 = 0xf9;
        }
        *puVar7 = uVar3;
        puVar7 = puVar7 + 1;
        ppuVar6 = ppuVar6 + 1;
        param_3 = param_3 + 0x18;
      }
    }
    piVar1 = piVar5 + 3;
    piVar5 = piVar5 + 3;
    iVar8 = *piVar1;
  }
  return Revealed;
}

// --------------------------------------------------

// Function: unexplore_terrain
// Address: 0053c920
/* public: void __thiscall RGE_Visible_Map::unexplore_terrain(int,int,int,int,int,int) */

void __thiscall
RGE_Visible_Map::unexplore_terrain
          (RGE_Visible_Map *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uchar *puVar4;
  uchar uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  ulong **ppuVar9;
  int plNum;
  RGE_Tile *tile;
  
  tile = (RGE_Tile *)0x0;
  log_map_call(this->world->world_time,(int)this->player->id,3,param_6,param_1,param_2,param_3,
               param_4,Map_Update_Suppresion);
  if (Map_Update_Suppresion == 0) {
    uVar2 = this->input_csum << 3;
    uVar2 = (((uVar2 | this->input_csum >> 0x1d) ^ 0x20202020) << 2 | uVar2 >> 0x1e) ^
            (int)this->player->id;
    uVar2 = (uVar2 << 3 | uVar2 >> 0x1d) ^ param_1;
    uVar2 = (uVar2 << 4 | uVar2 >> 0x1c) ^ param_2;
    this->input_csum = ((uVar2 << 3 | uVar2 >> 0x1d) ^ param_3) + param_4;
    if (0x10 < param_3) {
      param_3 = 0x10;
    }
    if (param_4 == 0) {
      piVar7 = (int *)(&NormalLOS)[param_3];
    }
    else {
      piVar7 = (int *)(&SquareLOS)[param_3];
    }
    iVar3 = *piVar7;
    while (iVar3 != 999) {
      iVar3 = iVar3 + param_2;
      if ((-1 < iVar3) && (iVar3 < this->heightValue)) {
        iVar6 = piVar7[1] + param_1;
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        iVar8 = piVar7[2] + param_1;
        if (this->widthValue <= iVar8) {
          iVar8 = this->widthValue + -1;
        }
        puVar4 = this->map_offsets[iVar3] + iVar6;
        ppuVar9 = (&unified_map_offsets)[iVar3] + iVar6;
        if (param_5 != 0) {
          tile = this->map->map_row_offset[iVar3] + iVar6;
        }
        if (iVar6 <= iVar8) {
          iVar3 = (iVar8 - iVar6) + 1;
          do {
            uVar5 = *puVar4 + 0xff;
            if (uVar5 == 0xff) {
              uVar5 = '\0';
            }
            if (uVar5 == '\0') {
              if (param_5 != 0) {
                tile->draw_as = 0x80;
              }
              *ppuVar9 = (ulong *)((uint)*ppuVar9 & this->PlayerVisibleMaskInvertValue);
            }
            *puVar4 = uVar5;
            puVar4 = puVar4 + 1;
            ppuVar9 = ppuVar9 + 1;
            tile = tile + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      piVar1 = piVar7 + 3;
      piVar7 = piVar7 + 3;
      iVar3 = *piVar1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: explore_terrain_sq
// Address: 0053cac0
/* public: int __thiscall RGE_Visible_Map::explore_terrain_sq(int,int,int,int,int,int) */

int __thiscall
RGE_Visible_Map::explore_terrain_sq
          (RGE_Visible_Map *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int iVar1;
  int iVar2;
  uchar uVar3;
  uint uVar4;
  uchar *puVar5;
  ulong **ppuVar6;
  bool bVar7;
  int isCurPlayer;
  RGE_Player *curVisPlayer;
  int Revealed;
  uchar *p;
  
  Revealed = 0;
  log_map_call(this->world->world_time,(int)this->player->id,2,param_6,param_1,param_2,param_3,
               param_4,Map_Update_Suppresion);
  if (Map_Update_Suppresion == 0) {
    bVar7 = this->world->players[this->world->curr_player]->mutualAlly[this->player->id] == 1;
    param_6 = 0;
    curVisPlayer = (RGE_Player *)0x0;
    uVar4 = this->input_csum << 3;
    uVar4 = (((uVar4 | this->input_csum >> 0x1d) ^ 0x34343434) << 2 | uVar4 >> 0x1e) ^ param_1;
    uVar4 = (uVar4 << 4 | uVar4 >> 0x1c) ^ param_2;
    uVar4 = (uVar4 << 3 | uVar4 >> 0x1d) ^ param_3;
    this->input_csum = (uVar4 << 3 | uVar4 >> 0x1d) ^ param_4;
    if (bVar7) {
      curVisPlayer = this->world->players[this->world->curr_player];
    }
    iVar1 = this->widthValue;
    if ((((param_1 < iVar1) && (-1 < param_3)) && (iVar2 = this->heightValue, param_2 < iVar2)) &&
       (-1 < param_4)) {
      if (param_1 < 0) {
        param_1 = 0;
      }
      if (iVar1 <= param_3) {
        param_3 = iVar1 + -1;
      }
      if (param_2 < 0) {
        param_2 = 0;
      }
      if (iVar2 <= param_4) {
        param_4 = iVar2 + -1;
      }
      for (; param_2 <= param_4; param_2 = param_2 + 1) {
        ppuVar6 = (&unified_map_offsets)[param_2] + param_1;
        puVar5 = this->map_offsets[param_2] + param_1;
        iVar1 = param_1;
        if (param_5 != 0) {
          param_6 = (int)(this->map->map_row_offset[param_2] + param_1);
        }
        for (; iVar1 <= param_3; iVar1 = iVar1 + 1) {
          uVar3 = *puVar5 + '\x01';
          if (uVar3 == '\0') {
            Revealed = Revealed + 1;
            this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
            RGE_Tile_List::add_node(&this->player->tile_list,iVar1,param_2);
            if (bVar7) {
              RGE_Tile_List::add_node(&curVisPlayer->diam_tile_list,iVar1,param_2);
            }
            uVar3 = '\x01';
            *ppuVar6 = (ulong *)((uint)*ppuVar6 | this->PlayerExploredMaskValue);
          }
          if (uVar3 == '\x01') {
            if (param_5 != 0) {
              ((RGE_Tile *)param_6)->draw_as = '\x0f';
            }
            *ppuVar6 = (ulong *)((uint)*ppuVar6 | this->PlayerVisibleMaskValue);
          }
          if (uVar3 == 0xfa) {
            uVar3 = 0xf9;
          }
          *puVar5 = uVar3;
          puVar5 = puVar5 + 1;
          ppuVar6 = ppuVar6 + 1;
          param_6 = param_6 + 0x18;
        }
      }
      return Revealed;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: unexplore_terrain_sq
// Address: 0053ccf0
/* public: void __thiscall RGE_Visible_Map::unexplore_terrain_sq(int,int,int,int,int,int) */

void __thiscall
RGE_Visible_Map::unexplore_terrain_sq
          (RGE_Visible_Map *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int iVar1;
  uint uVar2;
  uchar *puVar3;
  uchar uVar4;
  ulong **ppuVar5;
  int iVar6;
  RGE_Tile *tile;
  
  tile = (RGE_Tile *)0x0;
  log_map_call(this->world->world_time,(int)this->player->id,4,param_6,param_1,param_2,param_3,
               param_4,Map_Update_Suppresion);
  if (Map_Update_Suppresion == 0) {
    uVar2 = (this->input_csum << 3 | this->input_csum >> 0x1d) ^ 0x56565656;
    uVar2 = (uVar2 << 2 | uVar2 >> 0x1e) ^ param_1;
    uVar2 = (uVar2 << 4 | uVar2 >> 0x1c) ^ param_2;
    uVar2 = (uVar2 << 3 | uVar2 >> 0x1d) ^ param_3;
    this->input_csum = (uVar2 << 3 | uVar2 >> 0x1d) ^ param_4;
    iVar6 = this->widthValue;
    if ((((param_1 < iVar6) && (-1 < param_3)) && (iVar1 = this->heightValue, param_2 < iVar1)) &&
       (-1 < param_4)) {
      if (param_1 < 0) {
        param_1 = 0;
      }
      if (iVar6 <= param_3) {
        param_3 = iVar6 + -1;
      }
      if (param_2 < 0) {
        param_2 = 0;
      }
      if (iVar1 <= param_4) {
        param_4 = iVar1 + -1;
      }
      for (; param_2 <= param_4; param_2 = param_2 + 1) {
        puVar3 = this->map_offsets[param_2] + param_1;
        ppuVar5 = (&unified_map_offsets)[param_2] + param_1;
        if (param_5 != 0) {
          tile = this->map->map_row_offset[param_2] + param_1;
        }
        if (param_1 <= param_3) {
          iVar6 = (param_3 - param_1) + 1;
          do {
            uVar4 = *puVar3 + 0xff;
            if (uVar4 == 0xff) {
              uVar4 = '\0';
            }
            if (uVar4 == '\0') {
              if (param_5 != 0) {
                tile->draw_as = 0x80;
              }
              *ppuVar5 = (ulong *)((uint)*ppuVar5 & this->PlayerVisibleMaskInvertValue);
            }
            *puVar3 = uVar4;
            puVar3 = puVar3 + 1;
            ppuVar5 = ppuVar5 + 1;
            tile = tile + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: checksum_visible_inputs
// Address: 0053ce70
/* public: unsigned long __thiscall RGE_Visible_Map::checksum_visible_inputs(void) */

ulong __thiscall RGE_Visible_Map::checksum_visible_inputs(RGE_Visible_Map *this)
{
  ulong uVar1;
  
  uVar1 = this->input_csum;
  this->input_csum = 0;
  return uVar1;
}

// --------------------------------------------------

// Function: checksumVisible
// Address: 0053d0d0
/* public: long __thiscall RGE_Visible_Map::checksumVisible(void) */

long __thiscall RGE_Visible_Map::checksumVisible(RGE_Visible_Map *this)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = 0;
  if (0 < this->heightValue) {
    do {
      iVar2 = 0;
      if (0 < this->widthValue) {
        do {
          uVar1 = uVar1 ^ this->map_offsets[iVar3][iVar2];
          iVar2 = iVar2 + 1;
        } while (iVar2 < this->widthValue);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->heightValue);
  }
  return uVar1;
}

// --------------------------------------------------

// Function: checksumUnifiedVisible
// Address: 0053d110
/* public: unsigned long __thiscall RGE_Visible_Map::checksumUnifiedVisible(void) */

ulong __thiscall RGE_Visible_Map::checksumUnifiedVisible(RGE_Visible_Map *this)
{
  ulong *puVar1;
  ulong uVar2;
  ulong **ppuVar3;
  int iVar4;
  int iVar5;
  ulong ***pppuVar6;
  
  iVar5 = this->heightValue;
  uVar2 = 0;
  if (0 < iVar5) {
    pppuVar6 = &unified_map_offsets;
    do {
      if (0 < this->widthValue) {
        ppuVar3 = *pppuVar6;
        iVar4 = this->widthValue;
        do {
          puVar1 = *ppuVar3;
          ppuVar3 = ppuVar3 + 1;
          uVar2 = uVar2 ^ (uint)puVar1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      pppuVar6 = pppuVar6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return uVar2;
}

// --------------------------------------------------

