// Class: RGE_Zone_Map
// Size:  0x51C
//
// Member Layout:
// [0x000] int[257] numberTilesInZoneValue (sz: 0x404)
// [0x404] uchar * zone_map
// [0x408] uchar * * zone_map_rows
// [0x40C] uchar[257] zone_info (sz: 0x101)
// [0x510] float * terrain_passability_rules
// [0x514] long terrain_passability_rules_num
// [0x518] RGE_Map * map
// ----------------------------------------------------------------

// Function: RGE_Zone_Map
// Address: 005467b0
RGE_Zone_Map * __thiscall
RGE_Zone_Map::RGE_Zone_Map(RGE_Zone_Map *this,int param_1,RGE_Map *param_2)
{
  long *plVar1;
  uchar *puVar2;
  uchar **ppuVar3;
  int iVar4;
  float *pfVar5;
  RGE_Map *pRVar6;
  
  this->map = param_2;
  puVar2 = (uchar *)calloc(param_2->map_width * param_2->map_height,1);
  this->zone_map = puVar2;
  ppuVar3 = (uchar **)calloc(this->map->map_height,4);
  pRVar6 = this->map;
  this->zone_map_rows = ppuVar3;
  iVar4 = 0;
  if (0 < pRVar6->map_height) {
    do {
      this->zone_map_rows[iVar4] = this->zone_map + pRVar6->map_width * iVar4;
      pRVar6 = this->map;
      iVar4 = iVar4 + 1;
    } while (iVar4 < pRVar6->map_height);
  }
  rge_read(param_1,this->zone_info,0xff);
  rge_read(param_1,this,0x3fc);
  rge_read(param_1,this->zone_map,this->map->map_height * this->map->map_width);
  plVar1 = &this->terrain_passability_rules_num;
  rge_read(param_1,plVar1,4);
  if (0 < *plVar1) {
    pfVar5 = (float *)calloc(*plVar1,4);
    this->terrain_passability_rules = pfVar5;
    rge_read(param_1,pfVar5,*plVar1 << 2);
    return this;
  }
  this->terrain_passability_rules = (float *)0x0;
  return this;
}

// --------------------------------------------------

// Function: RGE_Zone_Map
// Address: 005468c0
RGE_Zone_Map * __thiscall
RGE_Zone_Map::RGE_Zone_Map(RGE_Zone_Map *this,RGE_Map *param_1,float *param_2,long param_3)
{
  uchar *puVar1;
  uchar **ppuVar2;
  int iVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  RGE_Map *pRVar7;
  RGE_Zone_Map *pRVar8;
  
  this->map = param_1;
  puVar1 = (uchar *)calloc(param_1->map_height * param_1->map_width,1);
  this->zone_map = puVar1;
  uVar5 = this->map->map_height * this->map->map_width;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    puVar1[0] = 0xff;
    puVar1[1] = 0xff;
    puVar1[2] = 0xff;
    puVar1[3] = 0xff;
    puVar1 = puVar1 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar1 = 0xff;
    puVar1 = puVar1 + 1;
  }
  ppuVar2 = (uchar **)calloc(this->map->map_height,4);
  pRVar7 = this->map;
  this->zone_map_rows = ppuVar2;
  iVar3 = 0;
  if (0 < pRVar7->map_height) {
    do {
      this->zone_map_rows[iVar3] = this->zone_map + pRVar7->map_width * iVar3;
      pRVar7 = this->map;
      iVar3 = iVar3 + 1;
    } while (iVar3 < pRVar7->map_height);
  }
  iVar3 = 0;
  pRVar8 = this;
  do {
    this->zone_info[iVar3] = 0xff;
    pRVar8->numberTilesInZoneValue[0] = 0;
    iVar3 = iVar3 + 1;
    pRVar8 = (RGE_Zone_Map *)(pRVar8->numberTilesInZoneValue + 1);
  } while (iVar3 < 0xff);
  this->terrain_passability_rules_num = param_3;
  pfVar4 = (float *)calloc(param_3,4);
  this->terrain_passability_rules = pfVar4;
  for (uVar6 = this->terrain_passability_rules_num & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pfVar4 = *param_2;
    param_2 = param_2 + 1;
    pfVar4 = pfVar4 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)pfVar4 = *(undefined1 *)param_2;
    param_2 = (float *)((int)param_2 + 1);
    pfVar4 = (float *)((int)pfVar4 + 1);
  }
  do_zone_map(this);
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Zone_Map
// Address: 005469c0
void __thiscall RGE_Zone_Map::~RGE_Zone_Map(RGE_Zone_Map *this)
{
  free(this->zone_map);
  free(this->zone_map_rows);
  free(this->terrain_passability_rules);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00546a00
void __thiscall RGE_Zone_Map::save(RGE_Zone_Map *this,int param_1)
{
  int iVar1;
  
  rge_write(param_1,this->zone_info,0xff);
  rge_write(param_1,this,0x3fc);
  rge_write(param_1,this->zone_map,this->map->map_height * this->map->map_width);
  rge_write(param_1,&this->terrain_passability_rules_num,4);
  iVar1 = this->terrain_passability_rules_num;
  if (0 < iVar1) {
    rge_write(param_1,this->terrain_passability_rules,iVar1 * 4);
  }
  return;
}

// --------------------------------------------------

// Function: do_zone_map
// Address: 00546a90
uchar __thiscall RGE_Zone_Map::do_zone_map(RGE_Zone_Map *this)
{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uchar *puVar9;
  long y;
  uchar group;
  long map_width;
  long map_height;
  
  iVar7 = 0;
  iVar2 = this->map->map_width;
  iVar3 = this->map->map_height;
  puVar9 = this->zone_info;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar9[0] = 0xff;
    puVar9[1] = 0xff;
    puVar9[2] = 0xff;
    puVar9[3] = 0xff;
    puVar9 = puVar9 + 4;
  }
  puVar9[0] = 0xff;
  puVar9[1] = 0xff;
  iVar6 = 0;
  puVar9[2] = 0xff;
  if (0 < iVar2) {
    do {
      iVar8 = 0;
      if (0 < iVar3) {
        do {
          iVar5 = iVar8 + 1;
          this->zone_map_rows[iVar6][iVar8] = 0xff;
          iVar8 = iVar5;
        } while (iVar5 < iVar3);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar2);
  }
  iVar6 = 0;
  _group = 0;
  if (0 < iVar2) {
    do {
      iVar8 = 0;
      if (0 < iVar3) {
        y = 0;
        do {
          if (*(char *)(iVar8 + *(int *)((int)this->zone_map_rows + iVar6)) == -1) {
            if (0xfe < iVar7) {
              iVar7 = 0;
            }
            fVar1 = this->terrain_passability_rules
                    [*(byte *)(*(int *)((int)this->map->map_row_offset + iVar6) + 5 + y) & 0x1f];
            fVar4 = (float)_DAT_00577a20;
            *(uchar *)(iVar8 + *(int *)((int)this->zone_map_rows + iVar6)) = (uchar)iVar7;
            do_zone_map_area(this,iVar8,_group,fVar4 < fVar1,(uchar)iVar7);
            iVar7 = iVar7 + 1;
          }
          iVar8 = iVar8 + 1;
          y = y + 0x18;
        } while (iVar8 < iVar3);
      }
      _group = _group + 1;
      iVar6 = iVar6 + 4;
    } while (_group < iVar2);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: do_zone_map_area
// Address: 00546bb0
void __thiscall
RGE_Zone_Map::do_zone_map_area
          (RGE_Zone_Map *this,long param_1,long param_2,uchar param_3,uchar param_4)
{
  uchar uVar1;
  uchar uVar2;
  undefined3 in_stack_0000000d;
  Zone_Queue *zone_end;
  Zone_Queue *zone_queue;
  Zone_Queue *local_c;
  int local_8;
  int local_4;
  
  uVar1 = param_4;
  local_c = (Zone_Queue *)0x0;
  zone_queue = (Zone_Queue *)0x0;
  local_8 = this->map->map_width + -1;
  local_4 = this->map->map_height + -1;
  do {
    if (0 < param_1) {
      if ((this->zone_map_rows[param_2][param_1 + -1] == 0xff) &&
         ((uint)((float)_DAT_00577a20 <
                this->terrain_passability_rules
                [(byte)this->map->map_row_offset[param_2][param_1 + -1].field_0x5 & 0x1f]) ==
          (_param_3 & 0xff))) {
        this->zone_map_rows[param_2][param_1 + -1] = uVar1;
        zone_push(&local_c,&zone_queue,param_1 + -1,param_2);
      }
    }
    if (0 < param_2) {
      if ((this->zone_map_rows[param_2 + -1][param_1] == 0xff) &&
         ((uint)((float)_DAT_00577a20 <
                this->terrain_passability_rules
                [(byte)this->map->map_row_offset[param_2 + -1][param_1].field_0x5 & 0x1f]) ==
          (_param_3 & 0xff))) {
        this->zone_map_rows[param_2 + -1][param_1] = uVar1;
        zone_push(&local_c,&zone_queue,param_1,param_2 + -1);
      }
    }
    if (param_1 < local_8) {
      if ((this->zone_map_rows[param_2][param_1 + 1] == 0xff) &&
         ((uint)((float)_DAT_00577a20 <
                this->terrain_passability_rules
                [(byte)this->map->map_row_offset[param_2][param_1 + 1].field_0x5 & 0x1f]) ==
          (_param_3 & 0xff))) {
        this->zone_map_rows[param_2][param_1 + 1] = uVar1;
        zone_push(&local_c,&zone_queue,param_1 + 1,param_2);
      }
    }
    if (param_2 < local_4) {
      if ((this->zone_map_rows[param_2 + 1][param_1] == 0xff) &&
         ((uint)((float)_DAT_00577a20 <
                this->terrain_passability_rules
                [(byte)this->map->map_row_offset[param_2 + 1][param_1].field_0x5 & 0x1f]) ==
          (_param_3 & 0xff))) {
        this->zone_map_rows[param_2 + 1][param_1] = uVar1;
        zone_push(&local_c,&zone_queue,param_1,param_2 + 1);
      }
    }
    uVar2 = zone_pop(&local_c,&zone_queue,&param_1,&param_2);
  } while (uVar2 != '\0');
  return;
}

// --------------------------------------------------

// Function: check_info
// Address: 00546e50
RGE_Zone_Map * __thiscall RGE_Zone_Map::check_info(RGE_Zone_Map *this,float *param_1,long param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->terrain_passability_rules_num;
  if (param_2 != iVar1) {
    return (RGE_Zone_Map *)0x0;
  }
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if ((float)_DAT_00577a20 < param_1[iVar2]) {
        if (this->terrain_passability_rules[iVar2] <= (float)_DAT_00577a20) {
          return (RGE_Zone_Map *)0x0;
        }
      }
      else if ((float)_DAT_00577a20 < this->terrain_passability_rules[iVar2]) {
        return (RGE_Zone_Map *)0x0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return this;
}

// --------------------------------------------------

// Function: get_zone_info
// Address: 00546eb0
uchar __thiscall RGE_Zone_Map::get_zone_info(RGE_Zone_Map *this,long param_1,long param_2)
{
  return this->zone_map_rows[param_2][param_1];
}

// --------------------------------------------------

// Function: withinRange
// Address: 00546ed0
int __thiscall
RGE_Zone_Map::withinRange(RGE_Zone_Map *this,XYPoint param_1,XYPoint param_2,float param_3)
{
  int iVar1;
  
  iVar1 = withinRange(this,this->zone_map_rows[param_1.y][param_1.x],param_2,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: withinRange
// Address: 00546f00
int __thiscall
RGE_Zone_Map::withinRange(RGE_Zone_Map *this,uchar param_1,XYPoint param_2,float param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  XYPoint max;
  
  iVar1 = __ftol();
  iVar3 = param_2.x - iVar1;
  iVar6 = param_2.y - iVar1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  iVar5 = this->map->map_width + -1;
  max.y = param_2.x + iVar1;
  if (iVar5 < param_2.x + iVar1) {
    max.y = iVar5;
  }
  iVar2 = this->map->map_height + -1;
  iVar5 = param_2.y + iVar1;
  if (iVar2 < param_2.y + iVar1) {
    iVar5 = iVar2;
  }
  if (max.y < iVar3) {
    return 0;
  }
  iVar1 = param_2.x - iVar3;
  do {
    if (iVar6 <= iVar5) {
      iVar4 = param_2.y - iVar6;
      iVar2 = iVar6;
      do {
        if ((SQRT((float)(iVar4 * iVar4 + iVar1 * iVar1)) <= param_3) &&
           (this->zone_map_rows[iVar2][iVar3] == param_1)) {
          return 1;
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar2 <= iVar5);
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + -1;
    if (max.y < iVar3) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: numberTilesInZone
// Address: 00547000
int __thiscall RGE_Zone_Map::numberTilesInZone(RGE_Zone_Map *this,uchar param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uchar uVar4;
  uchar **ppuVar5;
  int iVar6;
  int iVar7;
  int mapWidth;
  
  uVar4 = param_1;
  uVar3 = (uint)param_1;
  iVar6 = this->numberTilesInZoneValue[uVar3];
  if (iVar6 < 1) {
    iVar7 = 0;
    iVar1 = this->map->map_width;
    iVar2 = this->map->map_height;
    _param_1 = 0;
    iVar6 = 0;
    if (0 < iVar1) {
      do {
        if (0 < iVar2) {
          ppuVar5 = this->zone_map_rows;
          iVar6 = iVar2;
          do {
            if ((*ppuVar5)[iVar7] == uVar4) {
              _param_1 = _param_1 + 1;
            }
            ppuVar5 = ppuVar5 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        iVar7 = iVar7 + 1;
        iVar6 = _param_1;
      } while (iVar7 < iVar1);
    }
    this->numberTilesInZoneValue[uVar3] = iVar6;
  }
  return iVar6;
}

// --------------------------------------------------

// Function: findClosestPointInTerrainType
// Address: 00547080
int __thiscall
RGE_Zone_Map::findClosestPointInTerrainType
          (RGE_Zone_Map *this,XYPoint param_1,XYPoint *param_2,int param_3,int param_4,int param_5)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  XYPoint max;
  XYPoint min;
  int local_4;
  
  iVar5 = param_1.x - param_5;
  local_4 = param_1.y - param_5;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (local_4 < 0) {
    local_4 = 0;
  }
  iVar4 = this->map->map_width + -1;
  iVar3 = param_5 + param_1.x;
  if (iVar4 < param_5 + param_1.x) {
    iVar3 = iVar4;
  }
  iVar4 = this->map->map_height + -1;
  min.x = param_1.y + param_5;
  if (iVar4 < param_1.y + param_5) {
    min.x = iVar4;
  }
  iVar4 = -1;
  if (iVar5 <= iVar3) {
    param_5 = param_1.x - iVar5;
    do {
      if (local_4 <= min.x) {
        iVar7 = param_1.y - local_4;
        iVar6 = local_4;
        do {
          bVar1 = RGE_Map::get_terrain(this->map,(short)iVar5,(short)iVar6);
          if ((((uint)bVar1 == param_3) || ((uint)bVar1 == param_4)) &&
             ((iVar2 = param_5 * param_5 + iVar7 * iVar7, iVar4 == -1 || (iVar2 < iVar4)))) {
            param_2->x = iVar5;
            param_2->y = iVar6;
            iVar4 = iVar2;
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar6 <= min.x);
      }
      iVar5 = iVar5 + 1;
      param_5 = param_5 + -1;
    } while (iVar5 <= iVar3);
  }
  return (uint)(iVar4 != -1);
}

// --------------------------------------------------

