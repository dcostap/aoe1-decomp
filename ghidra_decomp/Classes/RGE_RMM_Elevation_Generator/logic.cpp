// Class: RGE_RMM_Elevation_Generator
// Function: RGE_RMM_Elevation_Generator
// Address: 004846c0
/* public: __thiscall RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(class RGE_Map *,class
   RGE_Random_Map_Module *,struct RGE_Elevation_Info *) */

RGE_RMM_Elevation_Generator * __thiscall
RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator
          (RGE_RMM_Elevation_Generator *this,RGE_Map *param_1,RGE_Random_Map_Module *param_2,
          RGE_Elevation_Info *param_3)
{
  int iVar1;
  RGE_Elevation_Info *pRVar2;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)this,param_1,param_2,'\x01')
  ;
  this->_padding_ = (int)&_vftable_;
  pRVar2 = &this->info;
  for (iVar1 = 0x3e0; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->elevation[0].elevation_size = param_3->elevation[0].elevation_size;
    param_3 = (RGE_Elevation_Info *)&param_3->elevation[0].elevation;
    pRVar2 = (RGE_Elevation_Info *)&pRVar2->elevation[0].elevation;
  }
  this->_padding_ = 0x3fc00000;
  return this;
}

// --------------------------------------------------

// Function: generate
// Address: 00484700
/* public: virtual unsigned char __thiscall RGE_RMM_Elevation_Generator::generate(void) */

uchar __thiscall RGE_RMM_Elevation_Generator::generate(RGE_RMM_Elevation_Generator *this)
{
  int iVar1;
  RGE_Elevation_Info_Line RVar2;
  int iVar3;
  int iVar4;
  RGE_Elevation_Info *pRVar5;
  int iVar6;
  long *plVar7;
  long in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  undefined4 in_stack_ffffffdc;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  long lVar8;
  RGE_Elevation_Info *local_4;
  
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)this);
  if ((0 < (this->info).elevation_num) && (iVar3 = 0, 0 < this->_padding_)) {
    do {
      iVar4 = 0;
      if (0 < this->_padding_) {
        iVar6 = 0;
        do {
          iVar1 = *(int *)(this->_padding_ + iVar3 * 4);
          iVar4 = iVar4 + 1;
          *(byte *)(iVar1 + 5 + iVar6) =
               *(byte *)(iVar1 + 5 + iVar6) & 0x1f |
               (char)(this->info).elevation[0].base_elevation << 5;
          iVar6 = iVar6 + 0x18;
        } while (iVar4 < this->_padding_);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->_padding_);
  }
  lVar8 = 0x48475f;
  generate_modifiers(this);
  iVar3 = 0;
  if (0 < (this->info).elevation_num) {
    local_4 = &this->info;
    do {
      pRVar5 = local_4;
      plVar7 = (long *)&stack0xffffffd4;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *plVar7 = pRVar5->elevation[0].elevation_size;
        pRVar5 = (RGE_Elevation_Info *)&pRVar5->elevation[0].elevation;
        plVar7 = plVar7 + 1;
      }
      RVar2.elevation = in_stack_ffffffd8;
      RVar2.elevation_size = in_stack_ffffffd4;
      RVar2.clumps = in_stack_ffffffdc;
      RVar2.spacing = in_stack_ffffffe0;
      RVar2.base_elevation = in_stack_ffffffe4;
      RVar2.base_terrain_type = lVar8;
      base_elevation_generate(this,RVar2);
      in_stack_ffffffe4 = this->_padding_ + -1;
      lVar8 = 8;
      in_stack_ffffffe0 = this->_padding_ + -1;
      in_stack_ffffffdc = 0;
      in_stack_ffffffd8 = 0;
      in_stack_ffffffd4 = 0x4847a1;
      RGE_Map::clean_elevation
                ((RGE_Map *)this->_padding_,0,0,in_stack_ffffffe0,in_stack_ffffffe4,'\b');
      iVar3 = iVar3 + 1;
      local_4 = (RGE_Elevation_Info *)(local_4->elevation + 1);
    } while (iVar3 < (this->info).elevation_num);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: check_start_elevation
// Address: 004847c0
/* protected: unsigned char __thiscall
   RGE_RMM_Elevation_Generator::check_start_elevation(long,long,unsigned char,unsigned char,unsigned
   char) */

uchar __thiscall
RGE_RMM_Elevation_Generator::check_start_elevation
          (RGE_RMM_Elevation_Generator *this,long param_1,long param_2,uchar param_3,uchar param_4,
          uchar param_5)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  
  uVar2 = (uint)param_5;
  iVar5 = param_1 - uVar2;
  iVar3 = param_2 - uVar2;
  _param_5 = param_2 + uVar2;
  iVar4 = param_1 + uVar2;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (this->_padding_ <= iVar4) {
    iVar4 = this->_padding_ + -1;
  }
  if (this->_padding_ <= _param_5) {
    _param_5 = this->_padding_ + -1;
  }
  param_2 = this->_padding_ + iVar3 * 4;
  iVar1 = *(int *)param_2;
  param_1 = iVar3;
  if (_param_5 < iVar3) {
    return '\x01';
  }
  do {
    if (iVar5 <= iVar4) {
      pbVar6 = (byte *)(iVar1 + iVar5 * 0x18 + 5);
      iVar3 = iVar5;
      do {
        if (((param_3 == 0xff) || ((*pbVar6 & 0x1f) != param_3)) || (*pbVar6 >> 5 < param_4)) {
          return '\0';
        }
        iVar3 = iVar3 + 1;
        pbVar6 = pbVar6 + 0x18;
      } while (iVar3 <= iVar4);
    }
    param_2 = param_2 + 4;
    param_1 = param_1 + 1;
    iVar1 = *(int *)param_2;
    if (_param_5 < param_1) {
      return '\x01';
    }
  } while( true );
}

// --------------------------------------------------

// Function: check_elevation
// Address: 004848a0
/* WARNING: Variable defined which should be unmapped: index1 */
/* protected: unsigned char __thiscall RGE_RMM_Elevation_Generator::check_elevation(unsigned
   char,long,long,long,unsigned char,unsigned char) */

uchar __thiscall
RGE_RMM_Elevation_Generator::check_elevation
          (RGE_RMM_Elevation_Generator *this,uchar param_1,long param_2,long param_3,long param_4,
          uchar param_5,uchar param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  long index1;
  long count;
  uchar local_10;
  
  local_10 = '\0';
  if (0 < param_4) {
    iVar3 = param_2 - param_4;
    iVar5 = param_3 - param_4;
    iVar2 = param_3 + param_4;
    iVar4 = param_4 + param_2;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (this->_padding_ <= iVar4) {
      iVar4 = this->_padding_ + -1;
    }
    param_4 = iVar2;
    if (this->_padding_ <= iVar2) {
      param_4 = this->_padding_ + -1;
    }
    iVar2 = *(int *)(this->_padding_ + iVar5 * 4);
    piVar7 = (int *)(this->_padding_ + iVar5 * 4);
    for (; iVar5 <= param_4; iVar5 = iVar5 + 1) {
      if (iVar3 <= iVar4) {
        pbVar6 = (byte *)(iVar2 + iVar3 * 0x18 + 5);
        iVar2 = iVar3;
        do {
          if (((param_5 == 0xff) || ((*pbVar6 & 0x1f) != param_5)) || (*pbVar6 >> 5 < param_6)) {
            return '\0';
          }
          iVar2 = iVar2 + 1;
          pbVar6 = pbVar6 + 0x18;
        } while (iVar2 <= iVar4);
      }
      piVar7 = piVar7 + 1;
      iVar2 = *piVar7;
    }
  }
  iVar4 = param_2 + -2;
  iVar5 = param_3 + -2;
  iVar2 = param_2 + 2;
  iVar3 = param_3 + 2;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (this->_padding_ <= iVar2) {
    iVar2 = this->_padding_ + -1;
  }
  if (this->_padding_ <= iVar3) {
    iVar3 = this->_padding_ + -1;
  }
  iVar8 = this->_padding_ + iVar5 * 4;
  iVar1 = *(int *)(this->_padding_ + iVar5 * 4);
  if (iVar5 <= iVar3) {
    _param_6 = (iVar3 - iVar5) + 1;
    local_10 = '\0';
    do {
      if (iVar4 <= iVar2) {
        pbVar6 = (byte *)(iVar1 + iVar4 * 0x18 + 5);
        iVar5 = (iVar2 - iVar4) + 1;
        do {
          if (*pbVar6 >> 5 == param_1) {
            local_10 = local_10 + '\x01';
          }
          pbVar6 = pbVar6 + 0x18;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar1 = *(int *)(iVar8 + 4);
      iVar8 = iVar8 + 4;
      _param_6 = _param_6 + -1;
    } while (_param_6 != 0);
  }
  return local_10;
}

// --------------------------------------------------

// Function: generate_modifiers
// Address: 00484a40
/* WARNING: Variable defined which should be unmapped: modifier */
/* protected: void __thiscall RGE_RMM_Elevation_Generator::generate_modifiers(void) */

void __thiscall RGE_RMM_Elevation_Generator::generate_modifiers(RGE_RMM_Elevation_Generator *this)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  undefined4 *puVar6;
  int iVar7;
  long modifier;
  int local_c;
  int local_8;
  
  uVar2 = this->_padding_ * this->_padding_;
  iVar4 = 0;
  puVar6 = (undefined4 *)this->_padding_;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  if (0 < this->_padding_) {
    do {
      iVar7 = 0;
      if (0 < this->_padding_) {
        do {
          local_8 = (this->info).hot_spot_num;
          local_c = 0;
          iVar1 = 0;
          if (0 < local_8) {
            plVar5 = &(this->info).hot_spots[0].y;
            do {
              iVar1 = __ftol();
              if (0 < plVar5[1] - iVar1) {
                local_c = local_c + plVar5[2] * (plVar5[1] - iVar1);
              }
              plVar5 = plVar5 + 4;
              local_8 = local_8 + -1;
              iVar1 = local_c;
            } while (local_8 != 0);
          }
          if (iVar1 < 0x65) {
            *(char *)(*(int *)(this->_padding_ + iVar4 * 4) + iVar7) = (char)iVar1;
          }
          else {
            *(undefined1 *)(*(int *)(this->_padding_ + iVar4 * 4) + iVar7) = 0x65;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < this->_padding_);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: fig_chance
// Address: 00484b30
/* protected: float __thiscall RGE_RMM_Elevation_Generator::fig_chance(long,long,long) */

float __thiscall
RGE_RMM_Elevation_Generator::fig_chance
          (RGE_RMM_Elevation_Generator *this,long param_1,long param_2,long param_3)
{
  return (float)(param_1 * -0xf + 0xfa);
}

// --------------------------------------------------

// Function: count_map_tiles
// Address: 00484b50
/* protected: long __thiscall RGE_RMM_Elevation_Generator::count_map_tiles(unsigned char) */

long __thiscall
RGE_RMM_Elevation_Generator::count_map_tiles(RGE_RMM_Elevation_Generator *this,uchar param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = *(uint *)this->_padding_;
  uVar1 = uVar2 + this->_padding_ * this->_padding_ * 0x18;
  for (; uVar2 < uVar1; uVar2 = uVar2 + 0x18) {
    if ((*(byte *)(uVar2 + 5) & 0x1f) == param_1) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}

// --------------------------------------------------

// Function: link_stack_randomly
// Address: 00484b90
// [HELPER] s_C__msdev_work_age1_x1_rmm_elev_c: "C:\msdev\work\age1_x1\rmm_elev.cpp"
/* protected: void __thiscall RGE_RMM_Elevation_Generator::link_stack_randomly(struct Map_Stack *)
    */

void __thiscall
RGE_RMM_Elevation_Generator::link_stack_randomly
          (RGE_RMM_Elevation_Generator *this,Map_Stack *param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_4;
  
  iVar2 = this->_padding_;
  iVar3 = this->_padding_;
  iVar5 = this->_padding_;
  *(Map_Stack **)(iVar5 + 0x14) = param_1;
  uVar1 = iVar5 + -0x18 + iVar2 * iVar3 * 0x18;
  *(uint *)(iVar5 + 0x10) = iVar5 + 0x18U;
  *(undefined4 *)(uVar1 + 0x10) = 0;
  *(uint *)(uVar1 + 0x14) = uVar1 - 0x18;
  uVar4 = iVar5 + 0x18U;
  while (uVar4 < uVar1) {
    *(uint *)(uVar4 + 0x10) = uVar4 + 0x18;
    *(uint *)(uVar4 + 0x14) = uVar4 - 0x18;
    uVar4 = uVar4 + 0x18;
  }
  iVar5 = this->_padding_ * this->_padding_;
  local_4 = (int)(iVar5 + (iVar5 >> 0x1f & 0xfU)) >> 4;
  if (0 < local_4) {
    do {
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0xfa);
      iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0xfb);
      RGE_Random_Map_Module::add_stack_node
                ((RGE_Random_Map_Module *)this,param_1,
                 (Map_Stack *)
                 (*(int *)(this->_padding_ + ((iVar6 * (iVar2 + -1)) / 0x7fff) * 4) +
                 ((iVar5 * (iVar3 + -1)) / 0x7fff) * 0x18));
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: remove_area_from_lists
// Address: 00484c80
/* protected: void __thiscall RGE_RMM_Elevation_Generator::remove_area_from_lists(long,long,long) */

void __thiscall
RGE_RMM_Elevation_Generator::remove_area_from_lists
          (RGE_RMM_Elevation_Generator *this,long param_1,long param_2,long param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1 - param_3;
  iVar1 = param_2 - param_3;
  iVar2 = param_3 + param_1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (this->_padding_ <= iVar2) {
    iVar2 = this->_padding_ + -1;
  }
  for (; iVar1 <= iVar2; iVar1 = iVar1 + 1) {
    if (iVar3 <= iVar2) {
      iVar4 = iVar3 * 0x18;
      iVar5 = (iVar2 - iVar3) + 1;
      do {
        RGE_Random_Map_Module::remove_stack_node
                  ((RGE_Random_Map_Module *)this,
                   (Map_Stack *)(*(int *)(this->_padding_ + iVar1 * 4) + iVar4));
        iVar4 = iVar4 + 0x18;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: base_elevation_generate
// Address: 00484d00
// [HELPER] s_C__msdev_work_age1_x1_rmm_elev_c: "C:\msdev\work\age1_x1\rmm_elev.cpp"
/* WARNING: Variable defined which should be unmapped: x */
/* protected: unsigned char __thiscall RGE_RMM_Elevation_Generator::base_elevation_generate(struct
   RGE_Elevation_Info_Line) */

uchar __thiscall
RGE_RMM_Elevation_Generator::base_elevation_generate
          (RGE_RMM_Elevation_Generator *this,RGE_Elevation_Info_Line param_1)
{
  byte *pbVar1;
  uchar uVar2;
  byte bVar3;
  int iVar4;
  Map_Stack *pMVar5;
  int iVar6;
  long lVar7;
  Map_Stack *pMVar8;
  long x;
  long y;
  int iStack_984;
  uchar done;
  char local_97d;
  long clump_size;
  float chance;
  float local_974;
  long max_y;
  float in_zone;
  long max_x;
  Map_Stack loc_stack;
  Map_Stack stack [99];
  
  loc_stack.x = this->_padding_ + -1;
  chance = 0.0;
  in_zone = (float)(this->_padding_ + -1);
  if (0 < param_1.clumps) {
    pMVar8 = (Map_Stack *)&stack[0].y;
    lVar7 = param_1.clumps;
    do {
      RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,pMVar8);
      pMVar8 = pMVar8 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  loc_stack.prev = (Map_Stack *)0x0;
  stack[0].x = 0;
  link_stack_randomly(this,(Map_Stack *)&loc_stack.y);
  iVar4 = __ftol();
  lVar7 = iVar4 / 2;
  if (lVar7 < 2) {
    lVar7 = 2;
  }
  iVar4 = 0;
  if (0 < param_1.clumps) {
    pMVar8 = (Map_Stack *)&stack[0].y;
    do {
      pMVar5 = RGE_Random_Map_Module::pop_stack
                         ((RGE_Random_Map_Module *)this,(Map_Stack *)&loc_stack.y,&y,
                          &stack0xfffff67c,(float *)&max_x);
      if (pMVar5 == (Map_Stack *)0x0) break;
      if ((*(char *)(*(int *)(this->_padding_ + iStack_984 * 4) + y) == '\0') &&
         (uVar2 = check_start_elevation
                            (this,y,iStack_984,(uchar)param_1.base_terrain_type,
                             (uchar)param_1.base_elevation,(uchar)param_1.spacing), uVar2 != '\0'))
{
        remove_area_from_lists(this,y,iStack_984,lVar7);
        pbVar1 = (byte *)(*(int *)(this->_padding_ + iStack_984 * 4) + 5 + y * 0x18);
        *pbVar1 = (uchar)param_1.elevation << 5 | *pbVar1 & 0x1f;
        if (0 < y) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)this,pMVar8,y + -1,iStack_984,0.0,0.0);
        }
        if (0 < iStack_984) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)this,pMVar8,y,iStack_984 + -1,0.0,0.0);
        }
        if (y < this->_padding_ + -1) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)this,pMVar8,y + 1,iStack_984,0.0,0.0);
        }
        if (iStack_984 < this->_padding_ + -1) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)this,pMVar8,y,iStack_984 + 1,0.0,0.0);
        }
        chance = (float)((int)chance + 1);
        iVar4 = iVar4 + 1;
        pMVar8 = pMVar8 + 1;
      }
    } while (iVar4 < param_1.clumps);
  }
  do {
    local_97d = '\x01';
    if (0 < param_1.clumps) {
      pMVar8 = (Map_Stack *)&stack[0].y;
      max_y = param_1.clumps;
      do {
        if (((int)chance < param_1.elevation_size) &&
           (pMVar5 = RGE_Random_Map_Module::pop_stack
                               ((RGE_Random_Map_Module *)this,pMVar8,&y,&stack0xfffff67c,
                                (float *)&max_x), pMVar5 != (Map_Stack *)0x0)) {
          iVar4 = iStack_984 * 4;
          local_97d = '\0';
          pbVar1 = (byte *)(*(int *)(this->_padding_ + iStack_984 * 4) + y);
          iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0x171);
          if ((iVar6 * 100) / 0x7fff < (int)(uint)*pbVar1) {
            *pbVar1 = 0x65;
          }
          else {
            iVar4 = *(int *)(this->_padding_ + iVar4) + y * 0x18;
            bVar3 = check_elevation(this,(uchar)param_1.elevation,y,iStack_984,param_1.spacing,
                                    (uchar)param_1.base_terrain_type,(uchar)param_1.base_elevation);
            if (((uint)(*(byte *)(iVar4 + 5) >> 5) == param_1.base_elevation) && (bVar3 != 0)) {
              local_974 = fig_chance(this,(uint)bVar3,y,iStack_984);
              *(byte *)(iVar4 + 5) = (uchar)param_1.elevation << 5 | *(byte *)(iVar4 + 5) & 0x1f;
              if ((0 < y) && ((uint)(*(byte *)(iVar4 + -0x13) >> 5) == param_1.base_elevation)) {
                iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0x17d);
                clump_size = (iVar6 * 100) / 0x7fff;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)this,pMVar8,y + -1,iStack_984,0.0,
                           (float)clump_size + local_974);
              }
              if ((y < loc_stack.x) &&
                 ((uint)(*(byte *)(iVar4 + 0x1d) >> 5) == param_1.base_elevation)) {
                iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0x17f);
                clump_size = (iVar6 * 100) / 0x7fff;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)this,pMVar8,y + 1,iStack_984,0.0,
                           (float)clump_size + local_974);
              }
              if ((0 < iStack_984) &&
                 ((uint)(*(byte *)(iVar4 + this->_padding_ * -0x18 + 5) >> 5) ==
                  param_1.base_elevation)) {
                iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0x181);
                clump_size = (iVar6 * 100) / 0x7fff;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)this,pMVar8,y,iStack_984 + -1,0.0,
                           (float)clump_size + local_974);
              }
              if ((iStack_984 < (int)in_zone) &&
                 ((uint)(*(byte *)(iVar4 + 5 + this->_padding_ * 0x18) >> 5) ==
                  param_1.base_elevation)) {
                iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0x183);
                clump_size = (iVar4 * 100) / 0x7fff;
                RGE_Random_Map_Module::push_stack
                          ((RGE_Random_Map_Module *)this,pMVar8,y,iStack_984 + 1,0.0,
                           (float)clump_size + local_974);
              }
              chance = (float)((int)chance + 1);
            }
          }
        }
        pMVar8 = pMVar8 + 1;
        max_y = max_y + -1;
      } while (max_y != 0);
      max_y = 0;
    }
  } while (local_97d == '\0');
  if (0 < param_1.clumps) {
    pMVar8 = (Map_Stack *)&stack[0].y;
    do {
      RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)this,pMVar8);
      pMVar8 = pMVar8 + 1;
      param_1.clumps = param_1.clumps + -1;
    } while (param_1.clumps != 0);
  }
  return '\x01';
}

// --------------------------------------------------

