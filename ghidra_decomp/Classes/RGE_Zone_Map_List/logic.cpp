// Class: RGE_Zone_Map_List
// Function: RGE_Zone_Map_List
// Address: 00547180
/* public: __thiscall RGE_Zone_Map_List::RGE_Zone_Map_List(int,class RGE_Map *) */

RGE_Zone_Map_List * __thiscall
RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Zone_Map_List *this,int param_1,RGE_Map *param_2)
{
  long *plVar1;
  RGE_Zone_Map **ppRVar2;
  RGE_Zone_Map *pRVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561e8b;
  *unaff_FS_OFFSET = &local_c;
  plVar1 = &this->zone_map_num;
  this->zone_maps = (RGE_Zone_Map **)0x0;
  this->map = param_2;
  rge_read(param_1,plVar1,4);
  if (*plVar1 < 1) {
    this->zone_maps = (RGE_Zone_Map **)0x0;
  }
  else {
    ppRVar2 = (RGE_Zone_Map **)calloc(*plVar1,4);
    this->zone_maps = ppRVar2;
    iVar4 = 0;
    if (0 < *plVar1) {
      do {
        pRVar3 = (RGE_Zone_Map *)operator_new(0x51c);
        local_4 = 0;
        if (pRVar3 == (RGE_Zone_Map *)0x0) {
          pRVar3 = (RGE_Zone_Map *)0x0;
        }
        else {
          pRVar3 = (RGE_Zone_Map *)RGE_Zone_Map::RGE_Zone_Map(pRVar3,param_1,this->map);
        }
        iVar5 = iVar4 + 1;
        local_4 = 0xffffffff;
        this->zone_maps[iVar4] = pRVar3;
        iVar4 = iVar5;
      } while (iVar5 < *plVar1);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Zone_Map_List
// Address: 00547240
/* public: __thiscall RGE_Zone_Map_List::RGE_Zone_Map_List(class RGE_Map *) */

void __thiscall RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Zone_Map_List *this,RGE_Map *param_1)
{
  this->map = param_1;
  this->zone_maps = (RGE_Zone_Map **)0x0;
  this->zone_map_num = 0;
  return;
}

// --------------------------------------------------

// Function: delete_zone_maps
// Address: 00547259
void __thiscall RGE_Zone_Map_List::delete_zone_maps(RGE_Zone_Map_List *this)
{
  RGE_Zone_Map *this_00;
  int iVar1;
  
  if ((this->zone_maps != (RGE_Zone_Map **)0x0) && (0 < this->zone_map_num)) {
    iVar1 = 0;
    if (0 < this->zone_map_num) {
      do {
        this_00 = this->zone_maps[iVar1];
        if (this_00 != (RGE_Zone_Map *)0x0) {
          RGE_Zone_Map::~RGE_Zone_Map(this_00);
          operator_delete(this_00);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->zone_map_num);
    }
    free(this->zone_maps);
    this->zone_maps = (RGE_Zone_Map **)0x0;
    this->zone_map_num = 0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Zone_Map_List
// Address: 00547260
/* public: __thiscall RGE_Zone_Map_List::~RGE_Zone_Map_List(void) */

void __thiscall RGE_Zone_Map_List::~RGE_Zone_Map_List(RGE_Zone_Map_List *this)
{
  RGE_Zone_Map *this_00;
  int iVar1;
  
  if ((this->zone_maps != (RGE_Zone_Map **)0x0) && (0 < this->zone_map_num)) {
    iVar1 = 0;
    if (0 < this->zone_map_num) {
      do {
        this_00 = this->zone_maps[iVar1];
        if (this_00 != (RGE_Zone_Map *)0x0) {
          RGE_Zone_Map::~RGE_Zone_Map(this_00);
          operator_delete(this_00);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->zone_map_num);
    }
    free(this->zone_maps);
    this->zone_maps = (RGE_Zone_Map **)0x0;
    this->zone_map_num = 0;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00547270
/* public: void __thiscall RGE_Zone_Map_List::save(int) */

void __thiscall RGE_Zone_Map_List::save(RGE_Zone_Map_List *this,int param_1)
{
  long *plVar1;
  int iVar2;
  
  plVar1 = &this->zone_map_num;
  rge_write(param_1,plVar1,4);
  if ((0 < *plVar1) && (iVar2 = 0, 0 < *plVar1)) {
    do {
      RGE_Zone_Map::save(this->zone_maps[iVar2],param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *plVar1);
  }
  return;
}

// --------------------------------------------------

// Function: create_zone_map
// Address: 005472b0
/* public: long __thiscall RGE_Zone_Map_List::create_zone_map(float *,long) */

long __thiscall
RGE_Zone_Map_List::create_zone_map(RGE_Zone_Map_List *this,float *param_1,long param_2)
{
  uchar uVar1;
  RGE_Zone_Map *pRVar2;
  RGE_Zone_Map **ppRVar3;
  uint uVar4;
  int iVar5;
  RGE_Zone_Map **ppRVar6;
  RGE_Zone_Map **ppRVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561eab;
  *unaff_FS_OFFSET = &local_c;
  iVar5 = 0;
  if (0 < this->zone_map_num) {
    do {
      pRVar2 = RGE_Zone_Map::check_info(this->zone_maps[iVar5],param_1,param_2);
      if (pRVar2 != (RGE_Zone_Map *)0x0) {
        uVar1 = RGE_Zone_Map::do_zone_map(this->zone_maps[iVar5]);
        if (uVar1 == '\0') {
          iVar5 = -1;
        }
        goto LAB_0054737c;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < this->zone_map_num);
  }
  ppRVar3 = (RGE_Zone_Map **)calloc(this->zone_map_num + 1,4);
  if (this->zone_maps != (RGE_Zone_Map **)0x0) {
    ppRVar6 = this->zone_maps;
    ppRVar7 = ppRVar3;
    for (uVar4 = this->zone_map_num & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      *ppRVar7 = *ppRVar6;
      ppRVar6 = ppRVar6 + 1;
      ppRVar7 = ppRVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)ppRVar7 = *(undefined1 *)ppRVar6;
      ppRVar6 = (RGE_Zone_Map **)((int)ppRVar6 + 1);
      ppRVar7 = (RGE_Zone_Map **)((int)ppRVar7 + 1);
    }
    free(this->zone_maps);
  }
  pRVar2 = (RGE_Zone_Map *)operator_new(0x51c);
  local_4 = 0;
  if (pRVar2 == (RGE_Zone_Map *)0x0) {
    pRVar2 = (RGE_Zone_Map *)0x0;
  }
  else {
    pRVar2 = (RGE_Zone_Map *)RGE_Zone_Map::RGE_Zone_Map(pRVar2,this->map,param_1,param_2);
  }
  ppRVar3[this->zone_map_num] = pRVar2;
  iVar5 = this->zone_map_num;
  this->zone_maps = ppRVar3;
  this->zone_map_num = iVar5 + 1;
LAB_0054737c:
  *unaff_FS_OFFSET = local_c;
  return iVar5;
}

// --------------------------------------------------

// Function: get_zone_map
// Address: 005473b0
/* public: class RGE_Zone_Map * __thiscall RGE_Zone_Map_List::get_zone_map(float *,long,int &) */

RGE_Zone_Map * __thiscall
RGE_Zone_Map_List::get_zone_map(RGE_Zone_Map_List *this,float *param_1,long param_2,int *param_3)
{
  RGE_Zone_Map *pRVar1;
  RGE_Zone_Map **ppRVar2;
  uint uVar3;
  int iVar4;
  RGE_Zone_Map **ppRVar5;
  RGE_Zone_Map **ppRVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561ecb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = 0;
  if (0 < this->zone_map_num) {
    do {
      pRVar1 = RGE_Zone_Map::check_info(this->zone_maps[iVar4],param_1,param_2);
      if (pRVar1 != (RGE_Zone_Map *)0x0) {
        *param_3 = iVar4;
        pRVar1 = this->zone_maps[iVar4];
        goto LAB_00547485;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->zone_map_num);
  }
  ppRVar2 = (RGE_Zone_Map **)calloc(this->zone_map_num + 1,4);
  if (this->zone_maps != (RGE_Zone_Map **)0x0) {
    ppRVar5 = this->zone_maps;
    ppRVar6 = ppRVar2;
    for (uVar3 = this->zone_map_num & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *ppRVar6 = *ppRVar5;
      ppRVar5 = ppRVar5 + 1;
      ppRVar6 = ppRVar6 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)ppRVar6 = *(undefined1 *)ppRVar5;
      ppRVar5 = (RGE_Zone_Map **)((int)ppRVar5 + 1);
      ppRVar6 = (RGE_Zone_Map **)((int)ppRVar6 + 1);
    }
    free(this->zone_maps);
  }
  pRVar1 = (RGE_Zone_Map *)operator_new(0x51c);
  local_4 = 0;
  if (pRVar1 == (RGE_Zone_Map *)0x0) {
    pRVar1 = (RGE_Zone_Map *)0x0;
  }
  else {
    pRVar1 = (RGE_Zone_Map *)RGE_Zone_Map::RGE_Zone_Map(pRVar1,this->map,param_1,param_2);
  }
  ppRVar2[this->zone_map_num] = pRVar1;
  iVar4 = this->zone_map_num;
  this->zone_maps = ppRVar2;
  this->zone_map_num = iVar4 + 1;
  *param_3 = iVar4;
  pRVar1 = ppRVar2[this->zone_map_num + -1];
LAB_00547485:
  *unaff_FS_OFFSET = local_c;
  return pRVar1;
}

// --------------------------------------------------

// Function: get_zone_map
// Address: 005474b0
/* public: class RGE_Zone_Map * __thiscall RGE_Zone_Map_List::get_zone_map(long) */

RGE_Zone_Map * __thiscall RGE_Zone_Map_List::get_zone_map(RGE_Zone_Map_List *this,long param_1)
{
  if ((param_1 < this->zone_map_num) && (-1 < param_1)) {
    return this->zone_maps[param_1];
  }
  return (RGE_Zone_Map *)0x0;
}

// --------------------------------------------------

// Function: delete_zone_maps
// Address: 005474d0
/* public: void __thiscall RGE_Zone_Map_List::delete_zone_maps(void) */

void __thiscall RGE_Zone_Map_List::delete_zone_maps(RGE_Zone_Map_List *this)
{
  RGE_Zone_Map *this_00;
  int iVar1;
  
  if ((this->zone_maps != (RGE_Zone_Map **)0x0) && (0 < this->zone_map_num)) {
    iVar1 = 0;
    if (0 < this->zone_map_num) {
      do {
        this_00 = this->zone_maps[iVar1];
        if (this_00 != (RGE_Zone_Map *)0x0) {
          RGE_Zone_Map::~RGE_Zone_Map(this_00);
          operator_delete(this_00);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->zone_map_num);
    }
    free(this->zone_maps);
    this->zone_maps = (RGE_Zone_Map **)0x0;
    this->zone_map_num = 0;
  }
  return;
}

// --------------------------------------------------

