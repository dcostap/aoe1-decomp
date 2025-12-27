// Class: RGE_RMM_Controller
// Function: RGE_RMM_Controller
// Address: 004821a0
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* public: __thiscall RGE_RMM_Controller::RGE_RMM_Controller(class RGE_Map *,class RGE_Game_World
   *,unsigned char,long) */

RGE_RMM_Controller * __thiscall
RGE_RMM_Controller::RGE_RMM_Controller
          (RGE_RMM_Controller *this,RGE_Map *param_1,RGE_Game_World *param_2,uchar param_3,
          long param_4)
{
  undefined4 *unaff_FS_OFFSET;
  RGE_Terrain_Info terrain_info;
  RGE_Land_Info land_info;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e5db;
  *unaff_FS_OFFSET = &local_c;
  terrain_info.terrain[0].terrain_size = (long)this;
  RGE_Random_Map_Module::RGE_Random_Map_Module
            ((RGE_Random_Map_Module *)this,param_1,(RGE_Random_Map_Module *)0x0,'\x01');
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  add_land_module(this,(RGE_Land_Info *)&land_info.land[0].terrain_type,(uint)param_3,param_4);
  add_terrain_module(this,(RGE_Terrain_Info *)&terrain_info.terrain[0].terrain_generated,
                     (RGE_Land_Info *)&land_info.land[0].terrain_type,(uint)param_3);
  add_object_module(this,param_2,(RGE_Land_Info *)&land_info.land[0].terrain_type);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: generate
// Address: 00482260
// [HELPER] s_C__msdev_work_age1_x1_rmm_base_c: "C:\msdev\work\age1_x1\rmm_base.cpp"
// [HELPER] s_RGE_RANDOM_MAP_MODULE__map_start: "RGE_RANDOM_MAP_MODULE::map startped with random: %d."
// [HELPER] s_RGE_RANDOM_MAP_MODULE__module_co: "RGE_RANDOM_MAP_MODULE::module completed with random: %d."
/* public: virtual unsigned char __thiscall RGE_RMM_Controller::generate(void) */

uchar __thiscall RGE_RMM_Controller::generate(RGE_RMM_Controller *this)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  TDebuggingLog *this_00;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  
  puVar2 = (undefined4 *)0x0;
  puVar7 = *(undefined4 **)&this->field_0x8;
joined_r0x004808e4:
  do {
    puVar3 = puVar7;
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 **)&this->field_0x8 = puVar2;
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8a);
      TDebuggingLog::Log(this_00,(char *)L,s_RGE_RANDOM_MAP_MODULE__map_start,iVar5);
      puVar7 = *(undefined4 **)&this->field_0x8;
      if (puVar7 == (undefined4 *)0x0) {
        return '\x01';
      }
      do {
        cVar4 = (*(code *)**(undefined4 **)*puVar7)();
        if (cVar4 == '\0') {
          return '\0';
        }
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8f);
        TDebuggingLog::Log(L,(char *)L,s_RGE_RANDOM_MAP_MODULE__module_co,iVar5);
        puVar7 = (undefined4 *)puVar7[1];
      } while (puVar7 != (undefined4 *)0x0);
      return '\x01';
    }
    puVar7 = (undefined4 *)puVar3[1];
    if (puVar2 != (undefined4 *)0x0) {
      fVar8 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar3);
      fVar9 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar2);
      puVar6 = puVar2;
      if (fVar9 <= fVar8) {
        do {
          if (puVar6[1] == 0) {
LAB_0048093c:
            puVar3[1] = puVar6[1];
            puVar6[1] = puVar3;
            break;
          }
          fVar8 = RGE_Random_Map_Module::get_schedule((RGE_Random_Map_Module *)*puVar3);
          fVar9 = RGE_Random_Map_Module::get_schedule(*(RGE_Random_Map_Module **)puVar6[1]);
          if (fVar8 < fVar9) goto LAB_0048093c;
          puVar1 = puVar6 + 1;
          puVar6 = (undefined4 *)*puVar1;
        } while ((undefined4 *)*puVar1 != (undefined4 *)0x0);
        goto joined_r0x004808e4;
      }
    }
    puVar3[1] = puVar2;
    puVar2 = puVar3;
  } while( true );
}

// --------------------------------------------------

// Function: add_land_module
// Address: 00482270
// [HELPER] s_C__msdev_work_age1_x1_rmm_cntr_c: "C:\msdev\work\age1_x1\rmm_cntr.cpp"
/* WARNING: Variable defined which should be unmapped: index */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: void __thiscall RGE_RMM_Controller::add_land_module(struct RGE_Land_Info &,long,long)
    */

void __thiscall
RGE_RMM_Controller::add_land_module
          (RGE_RMM_Controller *this,RGE_Land_Info *param_1,long param_2,long param_3)
{
  int iVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  RGE_RMM_Land_Generator *this_00;
  int iVar10;
  long *plVar11;
  long *plVar12;
  undefined4 *unaff_FS_OFFSET;
  long index;
  long mid_x1;
  long mid_x2;
  long mid_y1;
  long index2;
  long mid_y2;
  float bound_square;
  long land_tile_num;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e5fb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  param_1->land_num = param_3;
  switch(param_2) {
  case 0:
    param_1->base_terrain = '\x01';
    param_1->wall_1_avoidance_line = 8;
    param_1->wall_2_avoidance_line = 8;
    iVar5 = 0x1e;
    param_1->wall_3_avoidance_line = *(int *)&this->field_0x14 + -9;
    iVar1 = *(int *)&this->field_0x18;
    param_1->wall_fade = '\x14';
    param_1->wall_4_avoidance_line = iVar1 + -9;
    break;
  case 1:
    param_1->base_terrain = '\x01';
    param_1->wall_1_avoidance_line = 6;
    param_1->wall_2_avoidance_line = 6;
    iVar5 = 0x32;
    param_1->wall_3_avoidance_line = *(int *)&this->field_0x14 + -7;
    iVar1 = *(int *)&this->field_0x18;
    param_1->wall_fade = '\x14';
    param_1->wall_4_avoidance_line = iVar1 + -7;
    break;
  case 2:
    param_1->base_terrain = '\x01';
    param_1->wall_1_avoidance_line = 4;
    param_1->wall_2_avoidance_line = 4;
    iVar5 = 0x46;
    param_1->wall_3_avoidance_line = *(int *)&this->field_0x14 + -5;
    iVar1 = *(int *)&this->field_0x18;
    param_1->wall_fade = '\"';
    param_1->wall_4_avoidance_line = iVar1 + -5;
    break;
  case 3:
    param_1->base_terrain = '\x01';
    iVar5 = 0x5a;
    param_1->wall_1_avoidance_line = 0;
    param_1->wall_2_avoidance_line = 0;
    param_1->wall_3_avoidance_line = 0;
    param_1->wall_4_avoidance_line = 0;
    param_1->wall_fade = '\0';
    break;
  default:
    iVar5 = 0;
    param_1->base_terrain = '\0';
    param_1->wall_1_avoidance_line = 0;
    param_1->wall_2_avoidance_line = 0;
    param_1->wall_3_avoidance_line = 0;
    param_1->wall_4_avoidance_line = 0;
    param_1->wall_fade = '\0';
  }
  iVar1 = *(int *)&this->field_0x18;
  iVar2 = *(int *)&this->field_0x14;
  fVar3 = ((float)(iVar2 + -0x10) / SQRT((float)param_3)) * (float)_DAT_00571e70;
  mid_x2 = __ftol();
  index2 = __ftol();
  mid_y1 = __ftol();
  iVar6 = __ftol();
  if (mid_x2 < 9) {
    mid_x2 = 9;
  }
  if (index2 < 9) {
    index2 = 9;
  }
  if (iVar2 + -9 <= mid_y1) {
    mid_y1 = iVar2 + -10;
  }
  if (*(int *)&this->field_0x18 + -9 <= iVar6) {
    iVar6 = *(int *)&this->field_0x18 + -10;
  }
  mid_x1 = 0;
  if (0 < param_3) {
    plVar12 = &param_1->land[0].area;
    do {
      switch(param_2) {
      case 0:
        plVar12[-4] = 0;
        *plVar12 = 7;
        goto LAB_0048251c;
      case 1:
        plVar12[-4] = 0;
        *plVar12 = 4;
LAB_0048251c:
        plVar12[-1] = 5;
        *(uchar *)(plVar12 + 1) = (uchar)mid_x1;
        break;
      case 2:
      case 3:
      case 4:
        plVar12[-4] = 0;
        *plVar12 = 3;
        plVar12[-1] = 5;
        *(uchar *)(plVar12 + 1) = '\0';
      }
      do {
        bVar4 = false;
        iVar7 = debug_rand(s_C__msdev_work_age1_x1_rmm_cntr_c,0xd1);
        iVar7 = (iVar7 * (*(int *)&this->field_0x14 + -0x10)) / 0x7fff + 8;
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_cntr_c,0xd2);
        iVar8 = (iVar8 * (*(int *)&this->field_0x18 + -0x10)) / 0x7fff + 8;
        if ((((mid_x2 < iVar7) && (iVar7 < mid_y1)) && (index2 < iVar8)) && (iVar8 < iVar6)) {
          bVar4 = true;
        }
        else {
          mid_y2 = 0;
          if (0 < mid_x1) {
            plVar11 = &param_1->land[0].x;
            do {
              iVar10 = iVar7 - *plVar11;
              if (iVar10 < 0) {
                iVar10 = -iVar10;
              }
              iVar9 = iVar8 - plVar11[1];
              if (iVar9 < 0) {
                iVar9 = -iVar9;
              }
              if ((float)(iVar10 * iVar10 + iVar9 * iVar9) <= fVar3 * fVar3) {
                if ((!bVar4) && (mid_y2 == mid_x1 + -1)) {
                  plVar11[1] = iVar8;
                  *plVar11 = iVar7;
                }
                bVar4 = true;
              }
              mid_y2 = mid_y2 + 1;
              plVar11 = plVar11 + 0xd;
            } while (mid_y2 < mid_x1);
          }
        }
      } while (bVar4);
      plVar12[-3] = iVar7;
      plVar12[-2] = iVar8;
      ((RGE_Land_Info_Line *)(plVar12 + -5))->land_size =
           ((iVar5 * iVar1 * iVar2) / 100) / param_1->land_num;
      mid_x1 = mid_x1 + 1;
      plVar12 = plVar12 + 0xd;
    } while (mid_x1 < param_1->land_num);
  }
                    /* language.dll match for 0x1468: "Stone path 5" */
  this_00 = (RGE_RMM_Land_Generator *)operator_new(0x1468);
  local_4 = 0;
  if (this_00 != (RGE_RMM_Land_Generator *)0x0) {
    RGE_RMM_Land_Generator::RGE_RMM_Land_Generator
              (this_00,*(RGE_Map **)&this->field_0xc,(RGE_Random_Map_Module *)this,param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: add_terrain_module
// Address: 004826e0
/* protected: void __thiscall RGE_RMM_Controller::add_terrain_module(struct RGE_Terrain_Info
   &,struct RGE_Land_Info &,long) */

void __thiscall
RGE_RMM_Controller::add_terrain_module
          (RGE_RMM_Controller *this,RGE_Terrain_Info *param_1,RGE_Land_Info *param_2,long param_3)
{
  int iVar1;
  long *plVar2;
  RGE_RMM_Terrain_Generator *this_00;
  long *plVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e61b;
  *unaff_FS_OFFSET = &local_c;
  param_1->terrain_num = 2;
  switch(param_3) {
  case 0:
  case 1:
  case 2:
    iVar1 = *(int *)&this->field_0x18;
    iVar4 = *(int *)&this->field_0x14;
    param_1->terrain[0].terrain_type = 10;
    param_1->terrain[0].clumps = 0x14;
    param_1->terrain[0].base_terrain_type = 0;
    param_1->terrain[0].terrain_generated = 0;
    param_1->terrain[0].terrain_size = (iVar1 * iVar4 * 0x14) / 100;
    param_1->terrain[0].spacing = 2;
    iVar1 = *(int *)&this->field_0x18;
    iVar4 = *(int *)&this->field_0x14;
    param_1->terrain[1].terrain_type = 6;
    param_1->terrain[1].clumps = 7;
    param_1->terrain[1].terrain_size = (iVar1 * iVar4 * 0x1e) / 100;
    break;
  case 3:
  case 4:
    iVar1 = *(int *)&this->field_0x18;
    iVar4 = *(int *)&this->field_0x14;
    param_1->terrain[0].terrain_type = 10;
    param_1->terrain[0].clumps = 0x1e;
    param_1->terrain[0].base_terrain_type = 0;
    param_1->terrain[0].terrain_generated = 0;
    param_1->terrain[0].terrain_size = (iVar1 * iVar4 * 0x14) / 100;
    param_1->terrain[0].spacing = 2;
    iVar1 = *(int *)&this->field_0x18;
    iVar4 = *(int *)&this->field_0x14;
    param_1->terrain[1].terrain_type = 6;
    param_1->terrain[1].clumps = 0x11;
    param_1->terrain[1].terrain_size = (iVar1 * iVar4 * 0x1e) / 100;
    break;
  default:
    goto switchD_00482719_default;
  }
  param_1->terrain[1].base_terrain_type = 0;
  param_1->terrain[1].terrain_generated = 0;
  param_1->terrain[1].spacing = 0;
switchD_00482719_default:
  iVar4 = 0;
  iVar1 = param_2->land_num;
  param_1->hot_spot_num = iVar1;
  if (0 < iVar1) {
    plVar2 = &param_1->hot_spots[0].y;
    plVar3 = &param_2->land[0].y;
    do {
      iVar4 = iVar4 + 1;
      ((RGE_Terrain_Hot_Spots *)(plVar2 + -1))->x = plVar3[-1];
      *plVar2 = *plVar3;
      plVar2[1] = 0xc;
      plVar2[2] = 0x14;
      plVar3 = plVar3 + 0xd;
      plVar2 = plVar2 + 4;
    } while (iVar4 < param_1->hot_spot_num);
  }
  this_00 = (RGE_RMM_Terrain_Generator *)operator_new(0x12cc);
  local_4 = 0;
  if (this_00 != (RGE_RMM_Terrain_Generator *)0x0) {
    RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator
              (this_00,*(RGE_Map **)&this->field_0xc,(RGE_Random_Map_Module *)this,param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: count_map_tiles
// Address: 004828a0
/* protected: long __thiscall RGE_RMM_Controller::count_map_tiles(unsigned char) */

long __thiscall RGE_RMM_Controller::count_map_tiles(RGE_RMM_Controller *this,uchar param_1)
{
  return *(int *)&this->field_0x14 * *(int *)&this->field_0x18;
}

// --------------------------------------------------

// Function: add_object_module
// Address: 004828b0
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* protected: void __thiscall RGE_RMM_Controller::add_object_module(class RGE_Game_World *,struct
   RGE_Land_Info &) */

void __thiscall
RGE_RMM_Controller::add_object_module
          (RGE_RMM_Controller *this,RGE_Game_World *param_1,RGE_Land_Info *param_2)
{
  int iVar1;
  long *plVar2;
  int iVar3;
  long *plVar4;
  undefined4 *unaff_FS_OFFSET;
  RGE_Object_Info object_info;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055e63e;
                    /* language.dll match for 0x18d0: "Build Fire Galley (G)" */
  *unaff_FS_OFFSET = &local_c;
  object_info.lands[0].x = 6;
  object_info.objects[1].object_exclusion_zone = 4;
  object_info.objects[2].object_number_varience = 6;
  object_info.objects[3].object_number_varience = 6;
  object_info.objects[3].player_id = 4;
  object_info.objects[4].object_number_varience = 6;
  object_info.objects[0].terrain = 0x6d;
  object_info.objects[0].group_flag = '\0';
  object_info.objects[0].scale_flag = '\0';
  object_info.objects[0]._10_2_ = 0;
  object_info.objects[0].object_number_per_group._0_1_ = 0;
  object_info.objects[0].object_number_per_group._1_1_ = 0;
  object_info.objects[0].object_number_varience = 1;
  object_info.objects[0].number_of_groups = 0;
  object_info.objects[0].group_area = 1;
  object_info.objects[0].land_id = -1;
  object_info.objects[0].land_inner_radius = 0;
  object_info.objects[0].land_outer_radius = 0;
  object_info.objects[0].object_exclusion_zone = 0;
  object_info.objects[1].terrain = 0x53;
  object_info.objects[1].group_flag = '\0';
  object_info.objects[1].scale_flag = '\0';
  object_info.objects[1]._10_2_ = 0;
  object_info.objects[1].object_number_per_group._0_1_ = 0;
  object_info.objects[1].object_number_per_group._1_1_ = 0;
  object_info.objects[1].object_number_varience = 1;
  object_info.objects[1].number_of_groups = 0;
  object_info.objects[1].group_area = 3;
  object_info.objects[1].land_id = -1;
  object_info.objects[1].land_inner_radius = 0;
  object_info.objects[1].land_outer_radius = 2;
  object_info.objects[2].terrain = 0x41;
  object_info.objects[2].group_flag = '\0';
  object_info.objects[2].scale_flag = '\0';
  object_info.objects[2]._10_2_ = 0;
  object_info.objects[2].object_number_per_group._0_1_ = 1;
  object_info.objects[2].object_number_per_group._1_1_ = 1;
  object_info.objects[2].number_of_groups = 3;
  object_info.objects[2].group_area = 10;
  object_info.objects[2].player_id = 3;
  object_info.objects[2].land_id = 0;
  object_info.objects[2].land_inner_radius = -1;
  object_info.objects[2].land_outer_radius = -1;
  object_info.objects[2].object_exclusion_zone = -1;
  object_info.objects[3].terrain = 0x66;
  object_info.objects[3].group_flag = 0xff;
  object_info.objects[3].scale_flag = 0xff;
  object_info.objects[3]._10_2_ = 0xffff;
  object_info.objects[3].object_number_per_group._0_1_ = 2;
  object_info.objects[3].object_number_per_group._1_1_ = 0;
  object_info.objects[3].number_of_groups = 2;
  object_info.objects[3].group_area = 1;
  object_info.objects[3].land_id = 0;
  object_info.objects[3].land_inner_radius = 0;
  object_info.objects[3].land_outer_radius = 9;
  object_info.objects[3].object_exclusion_zone = 0xf;
  object_info.objects[4].terrain = 0x42;
  object_info.objects[4].group_flag = 0xff;
  object_info.objects[4].scale_flag = 0xff;
  object_info.objects[4]._10_2_ = 0xffff;
  object_info.objects[4].object_number_per_group._0_1_ = 2;
  object_info.objects[4].object_number_per_group._1_1_ = 0;
  object_info.objects[4].number_of_groups = 2;
  object_info.objects[4].group_area = 1;
  object_info.objects[4].player_id = 4;
  object_info.objects[4].land_id = 0;
  object_info.objects[4].land_inner_radius = 0;
  object_info.objects[4].land_outer_radius = 9;
  object_info.objects[4].object_exclusion_zone = 0xf;
  object_info.objects[5].terrain = 0x3b;
  object_info.objects[5].group_flag = 0xff;
  object_info.objects[5].scale_flag = 0xff;
  object_info.objects[5]._10_2_ = 0xffff;
  object_info.objects[5].player_id = 3;
  object_info.objects[5].land_outer_radius = 9;
  object_info.objects[5].number_of_groups = 2;
  iVar1 = param_2->land_num;
  iVar3 = 0;
  object_info.objects[5].object_number_per_group._0_1_ = 1;
  object_info.objects[5].object_number_per_group._1_1_ = 0;
  object_info.objects[5].object_number_varience = 5;
  object_info.objects[5].group_area = 1;
  object_info.objects[5].land_id = 0;
  object_info.objects[5].land_inner_radius = 0;
  object_info.objects[5].object_exclusion_zone = 0xf;
  if (0 < iVar1) {
    plVar2 = &object_info.lands[0].id;
    plVar4 = &param_2->land[0].y;
    do {
      iVar3 = iVar3 + 1;
      plVar2[-1] = plVar4[-1];
      *plVar2 = *plVar4;
      plVar2[1] = 0;
      plVar2[2] = iVar3;
      plVar4 = plVar4 + 0xd;
      plVar2 = plVar2 + 4;
    } while (iVar3 < iVar1);
  }
  object_info.objects[0].obj_id = (long)operator_new(0x1920);
  local_4 = 0;
  if ((RGE_RMM_Object_Generator *)object_info.objects[0].obj_id != (RGE_RMM_Object_Generator *)0x0)
{
    RGE_RMM_Object_Generator::RGE_RMM_Object_Generator
              ((RGE_RMM_Object_Generator *)object_info.objects[0].obj_id,
               *(RGE_Map **)&this->field_0xc,(RGE_Random_Map_Module *)this,param_1,
               (RGE_Object_Info *)&object_info.objects[0].terrain,'\x01');
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

