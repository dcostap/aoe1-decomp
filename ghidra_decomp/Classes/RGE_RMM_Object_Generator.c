// Class: RGE_RMM_Object_Generator
// Size:  0x1920
//
// VTable Layout:
// [00] generate
//
// Member Layout:
// [0x030] RGE_Game_World * world
// [0x034] RGE_Object_Info info (sz: 0x18C8)
// [0x18FC] uchar[32] terrain_table (sz: 0x20)
// [0x191C] uchar add_terrain
// ----------------------------------------------------------------

// Function: RGE_RMM_Object_Generator
// Address: 00485c50
RGE_RMM_Object_Generator * __thiscall
RGE_RMM_Object_Generator::RGE_RMM_Object_Generator
          (RGE_RMM_Object_Generator *this,RGE_Map *param_1,RGE_Random_Map_Module *param_2,
          RGE_Game_World *param_3,RGE_Object_Info *param_4,uchar param_5)
{
  int iVar1;
  RGE_Object_Info *pRVar2;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)this,param_1,param_2,'\x01')
  ;
  this->_padding_ = (int)&_vftable_;
  this->world = param_3;
  if (param_4 == (RGE_Object_Info *)0x0) {
    (this->info).object_num = 0;
    (this->info).land_num = 0;
  }
  else {
    pRVar2 = &this->info;
    for (iVar1 = 0x632; iVar1 != 0; iVar1 = iVar1 + -1) {
      pRVar2->objects[0].obj_id = param_4->objects[0].obj_id;
      param_4 = (RGE_Object_Info *)&param_4->objects[0].terrain;
      pRVar2 = (RGE_Object_Info *)&pRVar2->objects[0].terrain;
    }
  }
  this->_padding_ = 0x40400000;
  this->add_terrain = param_5;
  return this;
}

// --------------------------------------------------

// Function: add_quick_obj
// Address: 00485cb0
void __thiscall
RGE_RMM_Object_Generator::add_quick_obj
          (RGE_RMM_Object_Generator *this,long param_1,long param_2,long param_3)
{
  (this->info).objects[(this->info).object_num].obj_id = param_1;
  (this->info).objects[(this->info).object_num].terrain = -1;
  (this->info).objects[(this->info).object_num].group_flag = '\0';
  (this->info).objects[(this->info).object_num].scale_flag = '\0';
  (this->info).objects[(this->info).object_num].object_number_per_group = 1;
  (this->info).objects[(this->info).object_num].object_number_varience = 1;
  (this->info).objects[(this->info).object_num].number_of_groups = param_2;
  (this->info).objects[(this->info).object_num].group_area = 2;
  (this->info).objects[(this->info).object_num].player_id = 0;
  (this->info).objects[(this->info).object_num].land_id = -1;
  (this->info).objects[(this->info).object_num].land_inner_radius = 0;
  (this->info).objects[(this->info).object_num].land_outer_radius = 1;
  (this->info).objects[(this->info).object_num].object_exclusion_zone = param_3;
  (this->info).object_num = (this->info).object_num + 1;
  return;
}

// --------------------------------------------------

// Function: generate
// Address: 00485dc0
uchar __thiscall RGE_RMM_Object_Generator::generate(RGE_RMM_Object_Generator *this)
{
  int iVar1;
  RGE_Object_Info_Line *pRVar2;
  uchar *puVar3;
  
  if (this->add_terrain != '\0') {
    RGE_Map::set_terrain
              ((RGE_Map *)this->_padding_,*this->world->players,this->world,0,0,
               (short)this->_padding_ + -1,(short)this->_padding_ + -1,'\x01','\0',0);
  }
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)this);
  puVar3 = this->terrain_table;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    puVar3[0] = '\0';
    puVar3[1] = '\0';
    puVar3[2] = '\0';
    puVar3[3] = '\0';
    puVar3 = puVar3 + 4;
  }
  iVar1 = 0;
  if (0 < (this->info).object_num) {
    pRVar2 = (this->info).objects;
    do {
      generate_objects(this,pRVar2);
      iVar1 = iVar1 + 1;
      pRVar2 = pRVar2 + 1;
    } while (iVar1 < (this->info).object_num);
  }
  RGE_Zone_Map_List::delete_zone_maps(*(RGE_Zone_Map_List **)(this->_padding_ + 0x8dc4));
  return '\x01';
}

// --------------------------------------------------

// Function: generate_objects
// Address: 00485e50
void __thiscall
RGE_RMM_Object_Generator::generate_objects
          (RGE_RMM_Object_Generator *this,RGE_Object_Info_Line *param_1)
{
  int iVar1;
  long *plVar2;
  
  if (param_1->scale_flag != '\0') {
    iVar1 = (this->_padding_ * this->_padding_ * param_1->number_of_groups) / 0x5100;
    param_1->number_of_groups = iVar1;
    if (iVar1 < 1) {
      param_1->number_of_groups = 1;
    }
  }
  iVar1 = param_1->land_id;
  if (iVar1 < 0) {
    if (iVar1 == -1) {
      place_objects(this,param_1);
      return;
    }
    if (iVar1 == -2) {
      place_avoid_objects(this,param_1,param_1->land_inner_radius);
    }
  }
  else {
    iVar1 = 0;
    if (0 < (this->info).land_num) {
      plVar2 = &(this->info).lands[0].y;
      do {
        if (plVar2[1] == param_1->land_id) {
          place_land_objects(this,param_1,((RGE_Land_Point_Info_Line *)(plVar2 + -1))->x,*plVar2,
                             param_1->land_inner_radius,param_1->land_outer_radius,iVar1);
        }
        iVar1 = iVar1 + 1;
        plVar2 = plVar2 + 4;
      } while (iVar1 < (this->info).land_num);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: make_placement_stack
// Address: 00485f10
// [HELPER] s_C__msdev_work_age1_x1_rmm_obj_cp: "C:\msdev\work\age1_x1\rmm_obj.cpp"
void __thiscall
RGE_RMM_Object_Generator::make_placement_stack
          (RGE_RMM_Object_Generator *this,Map_Stack *param_1,long param_2,long param_3,long param_4,
          long param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  Map_Stack *pMVar6;
  long y1;
  Map_Stack *last;
  Map_Stack *local_c;
  int local_4;
  
  param_1->next = (Map_Stack *)0x0;
  param_1->prev = (Map_Stack *)0x0;
  if (((param_2 < 0) || (param_3 < 0)) || (param_5 < 0)) {
    param_2 = 0;
    param_5 = this->_padding_ + -1;
    param_3 = 0;
    last = (Map_Stack *)(this->_padding_ + -1);
  }
  else {
    iVar5 = param_2 - param_5;
    iVar3 = param_3 - param_5;
    iVar1 = param_2 + param_5;
    last = (Map_Stack *)(param_3 + param_5);
    param_2 = iVar5;
    if (iVar5 < 0) {
      param_2 = 0;
    }
    param_3 = iVar3;
    if (iVar3 < 0) {
      param_3 = 0;
    }
    if (this->_padding_ <= iVar1) {
      iVar1 = this->_padding_ + -1;
    }
    param_5 = iVar1;
    if (this->_padding_ <= (int)last) {
      last = (Map_Stack *)(this->_padding_ + -1);
    }
  }
  local_c = param_1;
  if (param_3 <= (int)last) {
    iVar1 = param_3 * 4;
    local_4 = (int)last + (1 - param_3);
    do {
      if (param_2 <= param_5) {
        iVar3 = param_2 * 0x18;
        lVar4 = param_2;
        do {
          if (*(char *)(*(int *)(this->_padding_ + iVar1) + lVar4) != '\0') {
            pMVar6 = (Map_Stack *)(*(int *)(this->_padding_ + iVar1) + iVar3);
            RGE_Random_Map_Module::add_stack_node((RGE_Random_Map_Module *)this,local_c,pMVar6);
            local_c = pMVar6;
          }
          lVar4 = lVar4 + 1;
          iVar3 = iVar3 + 0x18;
        } while (lVar4 <= param_5);
      }
      iVar1 = iVar1 + 4;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  iVar1 = (param_5 - param_2) + -1;
  iVar3 = (int)last + (-1 - param_3);
  if (((1 < iVar1) && (1 < iVar3)) &&
     (param_5 = (int)(iVar3 * iVar1 + (iVar3 * iVar1 >> 0x1f & 3U)) >> 2, 0 < param_5)) {
    do {
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0xaf);
      iVar2 = (iVar5 * iVar1) / 0x7fff + param_2;
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0xb0);
      iVar5 = ((iVar5 * iVar3) / 0x7fff + param_3) * 4;
      if (*(char *)(*(int *)(this->_padding_ + iVar5) + iVar2) != '\0') {
        RGE_Random_Map_Module::add_stack_node
                  ((RGE_Random_Map_Module *)this,param_1,
                   (Map_Stack *)(*(int *)(this->_padding_ + iVar5) + iVar2 * 0x18));
      }
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: to_close
// Address: 00486110
uchar __thiscall
RGE_RMM_Object_Generator::to_close
          (RGE_RMM_Object_Generator *this,RGE_Object_Info_Line *param_1,long param_2,long param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  int iVar5;
  
  iVar1 = (this->info).land_num;
  iVar5 = 0;
  if (iVar1 < 1) {
    return '\0';
  }
  plVar4 = &(this->info).lands[0].y;
  while( true ) {
    iVar3 = param_2 - ((RGE_Land_Point_Info_Line *)(plVar4 + -1))->x;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    iVar2 = param_3 - *plVar4;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if ((iVar3 < param_1->land_inner_radius) && (iVar2 < param_1->land_inner_radius)) break;
    iVar5 = iVar5 + 1;
    plVar4 = plVar4 + 4;
    if (iVar1 <= iVar5) {
      return '\0';
    }
  }
  return '\x01';
}

// --------------------------------------------------

// Function: set_search_area
// Address: 00486180
void __thiscall
RGE_RMM_Object_Generator::set_search_area
          (RGE_RMM_Object_Generator *this,long param_1,long param_2,long param_3,uchar param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_1 - param_3;
  iVar2 = param_2 - param_3;
  iVar3 = param_1 + param_3;
  iVar4 = param_3 + param_2;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (this->_padding_ <= iVar3) {
    iVar3 = this->_padding_ + -1;
  }
  if (this->_padding_ <= iVar4) {
    iVar4 = this->_padding_ + -1;
  }
  for (; iVar2 <= iVar4; iVar2 = iVar2 + 1) {
    if (iVar5 <= iVar3) {
      iVar1 = iVar5;
      do {
        iVar1 = iVar1 + 1;
        *(uchar *)(*(int *)(this->_padding_ + iVar2 * 4) + -1 + iVar1) = param_4;
      } while (iVar1 <= iVar3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: remove_area_from_lists
// Address: 00486210
void __thiscall
RGE_RMM_Object_Generator::remove_area_from_lists
          (RGE_RMM_Object_Generator *this,long param_1,long param_2,long param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 - param_3;
  iVar2 = param_2 - param_3;
  iVar3 = param_3 + param_1;
  iVar1 = param_3 + param_2;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (this->_padding_ <= iVar3) {
    iVar3 = this->_padding_ + -1;
  }
  if (this->_padding_ <= iVar1) {
    iVar1 = this->_padding_ + -1;
  }
  for (; iVar2 <= iVar1; iVar2 = iVar2 + 1) {
    if (iVar4 <= iVar3) {
      iVar5 = iVar4 * 0x18;
      iVar6 = (iVar3 - iVar4) + 1;
      do {
        RGE_Random_Map_Module::remove_stack_node
                  ((RGE_Random_Map_Module *)this,
                   (Map_Stack *)(*(int *)(this->_padding_ + iVar2 * 4) + iVar5));
        iVar5 = iVar5 + 0x18;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: place_avoid_objects
// Address: 004862b0
void __thiscall
RGE_RMM_Object_Generator::place_avoid_objects
          (RGE_RMM_Object_Generator *this,RGE_Object_Info_Line *param_1,long param_2)
{
  uchar uVar1;
  RGE_Player *pRVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Object_Info_Line *pRVar4;
  char cVar5;
  short sVar6;
  Map_Stack *pMVar7;
  uint uVar8;
  uint uVar9;
  RGE_Land_Point_Info_Line *pRVar10;
  int iVar11;
  undefined4 *puVar12;
  long y;
  long x;
  float tile_x;
  long count;
  int local_24;
  float zone;
  Map_Stack obj_stack;
  
  pRVar4 = param_1;
  iVar11 = 0;
  uVar8 = this->_padding_ * this->_padding_;
  puVar12 = (undefined4 *)this->_padding_;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = 0x1010101;
    puVar12 = puVar12 + 1;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar12 = 1;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  if (0 < (this->info).land_num) {
    pRVar10 = (this->info).lands;
    do {
      set_search_area(this,pRVar10->x,pRVar10->y,param_1->land_inner_radius,'\0');
      iVar11 = iVar11 + 1;
      pRVar10 = pRVar10 + 1;
    } while (iVar11 < (this->info).land_num);
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  make_placement_stack(this,(Map_Stack *)&obj_stack.y,-1,-1,-1,-1);
  pRVar2 = this->world->players[param_1->player_id & (param_1->player_id < 0) - 1];
  local_24 = param_1->number_of_groups;
  pMVar7 = RGE_Random_Map_Module::pop_stack
                     ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long *)&tile_x,&x,
                      (float *)&obj_stack);
  while ((pMVar7 != (Map_Stack *)0x0 && (0 < local_24))) {
    if ((pRVar4->terrain < 0) ||
       ((*(byte *)(*(int *)(this->_padding_ + x * 4) + 5 + (int)tile_x * 0x18) & 0x1f) ==
        pRVar4->terrain)) {
      count = (long)(float)(int)tile_x;
      param_1 = (RGE_Object_Info_Line *)(float)x;
      pRVar3 = pRVar2->master_objects[pRVar4->obj_id];
      sVar6 = __ftol();
      zone = (float)(int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_x - (float)(int)zone) {
        count = (long)((float)count - ram0x00571ee0);
      }
      sVar6 = __ftol();
      zone = (float)(int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_y - (float)(int)zone) {
        param_1 = (RGE_Object_Info_Line *)((float)param_1 - ram0x00571ee0);
      }
      cVar5 = (**(code **)(pRVar3->_padding_ + 0x20))(pRVar2,count,param_1,0,0,1,1,1,0,1);
      if (cVar5 == '\0') {
        remove_area_from_lists(this,(long)tile_x,x,pRVar4->object_exclusion_zone);
        uVar1 = pRVar4->group_flag;
        if (uVar1 == '\0') {
          (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,count,param_1,0,1);
        }
        else if (uVar1 == '\x01') {
          place_group(this,pRVar4,(long)tile_x,x,pRVar2);
        }
        else if (uVar1 == '\x02') {
          place_cluster(this,pRVar4,(long)tile_x,x,pRVar2);
        }
        local_24 = local_24 + -1;
      }
    }
    pMVar7 = RGE_Random_Map_Module::pop_stack
                       ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long *)&tile_x,&x,
                        (float *)&obj_stack);
  }
  RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  return;
}

// --------------------------------------------------

// Function: place_objects
// Address: 004864f0
void __thiscall
RGE_RMM_Object_Generator::place_objects
          (RGE_RMM_Object_Generator *this,RGE_Object_Info_Line *param_1)
{
  uchar uVar1;
  RGE_Player *pRVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Object_Info_Line *pRVar4;
  char cVar5;
  short sVar6;
  Map_Stack *pMVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  long y;
  long x;
  float tile_x;
  long count;
  int local_24;
  float zone;
  Map_Stack obj_stack;
  
  pRVar4 = param_1;
  uVar8 = this->_padding_ * this->_padding_;
  puVar10 = (undefined4 *)this->_padding_;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar10 = 0x1010101;
    puVar10 = puVar10 + 1;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar10 = 1;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  make_placement_stack(this,(Map_Stack *)&obj_stack.y,-1,-1,-1,-1);
  pRVar2 = this->world->players[param_1->player_id & (param_1->player_id < 0) - 1];
  local_24 = param_1->number_of_groups;
  pMVar7 = RGE_Random_Map_Module::pop_stack
                     ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long *)&tile_x,&x,
                      (float *)&obj_stack);
  while ((pMVar7 != (Map_Stack *)0x0 && (0 < local_24))) {
    if ((pRVar4->terrain < 0) ||
       ((*(byte *)(*(int *)(this->_padding_ + x * 4) + 5 + (int)tile_x * 0x18) & 0x1f) ==
        pRVar4->terrain)) {
      count = (long)(float)(int)tile_x;
      param_1 = (RGE_Object_Info_Line *)(float)x;
      pRVar3 = pRVar2->master_objects[pRVar4->obj_id];
      sVar6 = __ftol();
      zone = (float)(int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_x - (float)(int)zone) {
        count = (long)((float)count - ram0x00571ee0);
      }
      sVar6 = __ftol();
      zone = (float)(int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_y - (float)(int)zone) {
        param_1 = (RGE_Object_Info_Line *)((float)param_1 - ram0x00571ee0);
      }
      cVar5 = (**(code **)(pRVar3->_padding_ + 0x20))(pRVar2,count,param_1,0,0,1,1,1,0,1);
      if (cVar5 == '\0') {
        remove_area_from_lists(this,(long)tile_x,x,pRVar4->object_exclusion_zone);
        uVar1 = pRVar4->group_flag;
        if (uVar1 == '\0') {
          (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,count,param_1,0,1);
        }
        else if (uVar1 == '\x01') {
          place_group(this,pRVar4,(long)tile_x,x,pRVar2);
        }
        else if (uVar1 == '\x02') {
          place_cluster(this,pRVar4,(long)tile_x,x,pRVar2);
        }
        local_24 = local_24 + -1;
      }
    }
    pMVar7 = RGE_Random_Map_Module::pop_stack
                       ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long *)&tile_x,&x,
                        (float *)&obj_stack);
  }
  RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  return;
}

// --------------------------------------------------

// Function: place_land_objects
// Address: 00486700
void __thiscall
RGE_RMM_Object_Generator::place_land_objects
          (RGE_RMM_Object_Generator *this,RGE_Object_Info_Line *param_1,long param_2,long param_3,
          long param_4,long param_5,long param_6)
{
  int iVar1;
  RGE_Player *pRVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Object_Info_Line *pRVar4;
  long lVar5;
  uchar uVar6;
  uchar uVar7;
  char cVar8;
  short sVar9;
  Map_Stack *pMVar10;
  uint uVar11;
  uint uVar12;
  RGE_Land_Point_Info_Line *pRVar13;
  undefined4 *puVar14;
  int iVar15;
  long y;
  long min_x0;
  long min_x1;
  long min_y0;
  long min_y1;
  int local_28;
  float zone;
  int temp;
  Map_Stack obj_stack;
  
  lVar5 = param_4;
  pRVar4 = param_1;
  local_28 = param_4 + param_3;
  min_x1 = param_2 - param_4;
  min_y1 = param_3 - param_4;
  min_y0 = param_2 + param_4;
  if (min_x1 < 0) {
    min_x1 = 0;
  }
  if (min_y1 < 0) {
    min_y1 = 0;
  }
  iVar15 = this->_padding_;
  if (iVar15 <= min_y0) {
    min_y0 = iVar15 + -1;
  }
  iVar1 = this->_padding_;
  if (iVar1 <= local_28) {
    local_28 = iVar1 + -1;
  }
  puVar14 = (undefined4 *)this->_padding_;
  for (uVar11 = (uint)(iVar1 * iVar15) >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *puVar14 = 0x1010101;
    puVar14 = puVar14 + 1;
  }
  for (uVar11 = iVar1 * iVar15 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined1 *)puVar14 = 1;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
  }
  iVar15 = 0;
  if (0 < (this->info).land_num) {
    pRVar13 = (this->info).lands;
    do {
      set_search_area(this,pRVar13->x,pRVar13->y,lVar5,'\0');
      iVar15 = iVar15 + 1;
      pRVar13 = pRVar13 + 1;
    } while (iVar15 < (this->info).land_num);
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  make_placement_stack(this,(Map_Stack *)&obj_stack.y,param_2,param_3,lVar5,param_5);
  uVar11 = param_1->player_id;
  if ((uVar11 < 0x80000000) ||
     (uVar11 = (this->info).lands[param_6].player_id, uVar12 = 0, 0 < (int)uVar11)) {
    uVar12 = uVar11;
  }
  pRVar2 = this->world->players[uVar12];
  if (pRVar2->master_objects[param_1->obj_id] != (RGE_Master_Static_Object *)0x0) {
    param_6 = (long)RGE_Zone_Map_List::get_zone_map
                              (*(RGE_Zone_Map_List **)(this->_padding_ + 0x8dc4),
                               this->world->terrains
                               [pRVar2->master_objects[param_1->obj_id]->terrain],0x20,&obj_stack.x)
    ;
    uVar6 = RGE_Zone_Map::get_zone_info((RGE_Zone_Map *)param_6,param_2,param_3);
    param_1 = (RGE_Object_Info_Line *)param_1->number_of_groups;
    pMVar10 = RGE_Random_Map_Module::pop_stack
                        ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,&param_4,&min_x0,
                         (float *)&temp);
    while ((pMVar10 != (Map_Stack *)0x0 && (0 < (int)param_1))) {
      uVar7 = RGE_Zone_Map::get_zone_info((RGE_Zone_Map *)param_6,param_4,min_x0);
      if (((uVar6 == uVar7) &&
          ((pRVar4->terrain < 0 ||
           ((*(byte *)(*(int *)(this->_padding_ + min_x0 * 4) + 5 + param_4 * 0x18) & 0x1f) ==
            pRVar4->terrain)))) &&
         ((param_4 <= min_x1 ||
          (((min_y0 <= param_4 || (min_x0 <= min_y1)) || (local_28 <= min_x0)))))) {
        param_5 = (long)(float)param_4;
        param_2 = (long)(float)min_x0;
        pRVar3 = pRVar2->master_objects[pRVar4->obj_id];
        sVar9 = __ftol();
        zone = (float)(int)sVar9;
        if ((float)DAT_00571edc < pRVar3->radius_x - (float)(int)zone) {
          param_5 = (long)((float)param_5 - ram0x00571ee0);
        }
        sVar9 = __ftol();
        zone = (float)(int)sVar9;
        if ((float)DAT_00571edc < pRVar3->radius_y - (float)(int)zone) {
          param_2 = (long)((float)param_2 - ram0x00571ee0);
        }
        cVar8 = (**(code **)(pRVar3->_padding_ + 0x20))(pRVar2,param_5,param_2,0,0,1,1,1,1,1);
        if (cVar8 == '\0') {
          remove_area_from_lists(this,param_4,min_x0,pRVar4->object_exclusion_zone);
          uVar7 = pRVar4->group_flag;
          if (uVar7 == '\0') {
            (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,param_5,param_2,0,1);
LAB_004869ee:
            param_1 = (RGE_Object_Info_Line *)((int)&param_1[-1].object_exclusion_zone + 3);
          }
          else if (uVar7 == '\x01') {
            place_group(this,pRVar4,param_4,min_x0,pRVar2);
            param_1 = (RGE_Object_Info_Line *)((int)&param_1[-1].object_exclusion_zone + 3);
          }
          else {
            if (uVar7 != '\x02') goto LAB_004869ee;
            place_cluster(this,pRVar4,param_4,min_x0,pRVar2);
            param_1 = (RGE_Object_Info_Line *)((int)&param_1[-1].object_exclusion_zone + 3);
          }
        }
        else if ((pRVar4->group_flag == '\0') && (obj_stack.prev == (Map_Stack *)0x0)) {
          (**(code **)(pRVar2->_padding_ + 0x94))(pRVar4->obj_id,param_5,param_2,0,1);
        }
      }
      pMVar10 = RGE_Random_Map_Module::pop_stack
                          ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,&param_4,&min_x0,
                           (float *)&temp);
    }
    RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  }
  return;
}

// --------------------------------------------------

// Function: place_group
// Address: 00486a60
// [HELPER] s_C__msdev_work_age1_x1_rmm_obj_cp: "C:\msdev\work\age1_x1\rmm_obj.cpp"
void __thiscall
RGE_RMM_Object_Generator::place_group
          (RGE_RMM_Object_Generator *this,RGE_Object_Info_Line *param_1,long param_2,long param_3,
          RGE_Player *param_4)
{
  int iVar1;
  int iVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Player *pRVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  Map_Stack *pMVar8;
  long y;
  long x;
  int local_28;
  RGE_RMM_Object_Generator *local_24;
  float zone;
  Map_Stack obj_stack;
  
  pRVar4 = param_4;
  local_24 = this;
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  make_placement_stack(this,(Map_Stack *)&obj_stack.y,param_2,param_3,0,param_1->group_area);
  iVar1 = param_1->object_number_per_group;
  iVar2 = param_1->object_number_varience;
  iVar7 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x212);
  param_3 = iVar1 + ((iVar7 * iVar2 * 2) / 0x7fff - iVar2);
  if (param_3 < 1) {
    param_3 = 1;
  }
  pMVar8 = RGE_Random_Map_Module::pop_stack
                     ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,&local_28,&x,
                      (float *)&obj_stack);
  while ((pMVar8 != (Map_Stack *)0x0 && (0 < param_3))) {
    if ((param_1->terrain < 0) ||
       (((byte)((RGE_Tile **)this->_padding_)[x][local_28].field_0x5 & 0x1f) == param_1->terrain)) {
      param_4 = (RGE_Player *)(float)local_28;
      param_2 = (long)(float)x;
      pRVar3 = pRVar4->master_objects[param_1->obj_id];
      sVar6 = __ftol();
      zone = (float)(int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_x - (float)(int)zone) {
        param_4 = (RGE_Player *)((float)param_4 - ram0x00571ee0);
      }
      sVar6 = __ftol();
      zone = (float)(int)sVar6;
      if ((float)DAT_00571edc < pRVar3->radius_y - (float)(int)zone) {
        param_2 = (long)((float)param_2 - ram0x00571ee0);
      }
      cVar5 = (**(code **)(pRVar3->_padding_ + 0x20))(pRVar4,param_4,param_2,0,0,1,1,1,0,1);
      this = local_24;
      if (cVar5 == '\0') {
        (**(code **)(pRVar4->_padding_ + 0x94))(param_1->obj_id,param_4,param_2,0,1);
        param_3 = param_3 + -1;
        this = local_24;
      }
    }
    pMVar8 = RGE_Random_Map_Module::pop_stack
                       ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,&local_28,&x,
                        (float *)&obj_stack);
  }
  RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  return;
}

// --------------------------------------------------

// Function: place_cluster
// Address: 00486c40
// [HELPER] s_C__msdev_work_age1_x1_rmm_obj_cp: "C:\msdev\work\age1_x1\rmm_obj.cpp"
void __thiscall
RGE_RMM_Object_Generator::place_cluster
          (RGE_RMM_Object_Generator *this,RGE_Object_Info_Line *param_1,long param_2,long param_3,
          RGE_Player *param_4)
{
  int iVar1;
  RGE_Master_Static_Object *pRVar2;
  float fVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  Map_Stack *pMVar7;
  int iVar8;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  long y;
  long x;
  float tile_y;
  float tile_x;
  long x1;
  long y0;
  long y1;
  float zone;
  Map_Stack obj_stack;
  
  obj_stack.prev = (Map_Stack *)0x0;
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  RGE_Random_Map_Module::add_stack_node
            ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,
             (Map_Stack *)(*(int *)(this->_padding_ + param_3 * 4) + param_2 * 0x18));
  iVar8 = param_1->group_area;
  y1 = param_3 - iVar8;
  y0 = param_2 + iVar8;
  zone = (float)(param_3 + iVar8);
  param_3 = param_2 - iVar8;
  if (param_2 - iVar8 < 0) {
    param_3 = 0;
  }
  if (y1 < 0) {
    y1 = 0;
  }
  if (this->_padding_ <= y0) {
    y0 = this->_padding_ + -1;
  }
  x = y1;
  if (this->_padding_ <= (int)zone) {
    zone = (float)(this->_padding_ + -1);
  }
  for (; fVar3 = (float)param_3, x <= (int)zone; x = x + 1) {
    while (tile_y = fVar3, (int)tile_y <= y0) {
      *(undefined1 *)(*(int *)(this->_padding_ + x * 4) + (int)tile_y) = 1;
      fVar3 = (float)((int)tile_y + 1);
    }
  }
  iVar8 = param_1->object_number_per_group;
  iVar1 = param_1->object_number_varience;
  iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x256);
  param_2 = iVar8 + ((iVar6 * iVar1 * 2) / 0x7fff - iVar1);
  if (param_2 < 1) {
    param_2 = 1;
  }
  pMVar7 = RGE_Random_Map_Module::pop_stack
                     ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long *)&tile_y,&x,
                      (float *)&obj_stack);
  while ((pMVar7 != (Map_Stack *)0x0 && (0 < param_2))) {
    x1 = (long)(float)(int)tile_y;
    pRVar2 = param_4->master_objects[param_1->obj_id];
    tile_x = (float)x;
    sVar5 = __ftol();
    if ((float)DAT_00571edc < pRVar2->radius_x - (float)(int)sVar5) {
      x1 = (long)((float)x1 - ram0x00571ee0);
    }
    sVar5 = __ftol();
    if ((float)DAT_00571edc < pRVar2->radius_y - (float)(int)sVar5) {
      tile_x = tile_x - ram0x00571ee0;
    }
    iVar8 = pRVar2->_padding_;
    (**(code **)(iVar8 + 0x24))(&x1,&tile_x,this->world,1);
    cVar4 = (**(code **)(iVar8 + 0x20))(param_4,unaff_EBX,unaff_EBP,0,0,1,1,1,0,1);
    if (cVar4 == '\0') {
      (**(code **)(param_4->_padding_ + 0x94))(param_1->obj_id,x1,tile_x,0,1);
      param_2 = param_2 + -1;
      *(undefined1 *)(*(int *)(this->_padding_ + x * 4) + (int)tile_y) = 0;
      if ((param_3 < (int)tile_y) &&
         (*(char *)(*(int *)(this->_padding_ + x * 4) + -1 + (int)tile_y) != '\0')) {
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x270);
        RGE_Random_Map_Module::push_stack
                  ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(int)tile_y + -1,x,0.0,
                   (float)iVar8);
      }
      if (((int)tile_y < y0) &&
         (*(char *)(*(int *)(this->_padding_ + x * 4) + 1 + (int)tile_y) != '\0')) {
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x273);
        RGE_Random_Map_Module::push_stack
                  ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(int)tile_y + 1,x,0.0,
                   (float)iVar8);
      }
      if ((y1 < x) && (*(char *)(*(int *)(this->_padding_ + -4 + x * 4) + (int)tile_y) != '\0')) {
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x276);
        RGE_Random_Map_Module::push_stack
                  ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long)tile_y,x + -1,0.0,
                   (float)iVar8);
      }
      if ((x < (int)zone) &&
         (*(char *)(*(int *)(this->_padding_ + 4 + x * 4) + (int)tile_y) != '\0')) {
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_obj_cp,0x279);
        RGE_Random_Map_Module::push_stack
                  ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long)tile_y,x + 1,0.0,
                   (float)iVar8);
      }
    }
    pMVar7 = RGE_Random_Map_Module::pop_stack
                       ((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y,(long *)&tile_y,&x,
                        (float *)&obj_stack);
  }
  RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&obj_stack.y);
  return;
}

// --------------------------------------------------

