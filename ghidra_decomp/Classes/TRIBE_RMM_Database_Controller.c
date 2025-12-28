// Class: TRIBE_RMM_Database_Controller
// Size:  0x4F5C
//
// VTable Layout:
// [00] generate
// [01] add_land_module
// [02] add_terrain_module
// [03] add_object_module
// [04] add_elevation_module
// [05] init
// [06] de_init
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_RMM_Database_Controller
// Address: 004876c0
TRIBE_RMM_Database_Controller * __thiscall
TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller
          (TRIBE_RMM_Database_Controller *this,char *param_1,char *param_2,char *param_3,
          char *param_4)
{
  RGE_RMM_Database_Controller::RGE_RMM_Database_Controller
            ((RGE_RMM_Database_Controller *)this,param_1,param_2,param_3,param_4);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_RMM_Database_Controller
// Address: 004876f0
TRIBE_RMM_Database_Controller * __thiscall
TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller
          (TRIBE_RMM_Database_Controller *this,int param_1)
{
  RGE_RMM_Database_Controller::RGE_RMM_Database_Controller
            ((RGE_RMM_Database_Controller *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: init
// Address: 00487710
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
uchar __thiscall
TRIBE_RMM_Database_Controller::init
          (TRIBE_RMM_Database_Controller *this,RGE_Map *param_1,RGE_Game_World *param_2,
          uchar param_3,long param_4,uchar param_5)
{
  undefined4 uVar1;
  int iVar2;
  long *plVar3;
  RGE_RMM_Cliffs_Generator *pRVar4;
  int iVar5;
  long *plVar6;
  undefined4 *unaff_FS_OFFSET;
  long alStack_99c [298];
  undefined4 uStack_4f4;
  long base_cliff_size;
  RGE_Cliffs_Info cliff_info;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e6be;
  *unaff_FS_OFFSET = &local_c;
  iVar2 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  uStack_4f4 = 0x487776;
  RGE_RMM_Database_Controller::init
            ((RGE_RMM_Database_Controller *)this,param_1,param_2,param_3,param_4,
             '\x01' - (iVar2 != 0));
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x40);
  if (0x1fff < iVar2) {
    iVar2 = *(int *)&this->field_0x14;
    if (iVar2 < 0x49) {
      cliff_info.number_of_cliffs = 3;
      iVar5 = 10;
    }
    else if (iVar2 < 0x61) {
      cliff_info.number_of_cliffs = 4;
      iVar5 = 0xc;
    }
    else if (iVar2 < 0x79) {
      cliff_info.number_of_cliffs = 6;
      iVar5 = 0xe;
    }
    else if (iVar2 < 0x91) {
      cliff_info.number_of_cliffs = 8;
      iVar5 = 0x10;
    }
    else if (iVar2 < 0xc9) {
      cliff_info.number_of_cliffs = 0x12;
      iVar5 = 0x14;
    }
    else {
      iVar5 = cliff_info.number_of_cliffs;
      if (iVar2 < 0xfb) {
        cliff_info.number_of_cliffs = 0x1c;
        iVar5 = 0x14;
      }
    }
    switch(*(undefined4 *)&this->field_0x34) {
    case 0:
      cliff_info.number_of_cliffs = 0;
      iVar5 = 0;
      break;
    case 1:
      cliff_info.number_of_cliffs = cliff_info.number_of_cliffs + -5;
      iVar5 = iVar5 + -6;
      break;
    case 2:
      cliff_info.number_of_cliffs = cliff_info.number_of_cliffs + -3;
      iVar5 = iVar5 + -2;
      break;
    case 5:
    case 6:
    case 8:
      iVar5 = iVar5 + -4;
    }
    if (iVar5 < 3) {
      iVar5 = 3;
    }
    cliff_info.average_cliff_size = 2;
    cliff_info.cliff_to_cliff_spacing = 2;
    cliff_info.hot_spots[0].x = 2;
    if (iVar5 + -3 < 1) {
      cliff_info.cliff_terrain_spacing = 0;
    }
    else {
      cliff_info.cliff_terrain_spacing = (iVar5 + -3) / 2;
    }
    iVar2 = *(int *)&this->field_0x2708;
    cliff_info.cliff_size_variance = iVar5 - cliff_info.cliff_terrain_spacing;
    if (0 < iVar2) {
      plVar6 = &cliff_info.hot_spots[0].radius;
      plVar3 = (long *)&this->field_0x20dc;
      do {
        plVar6[-1] = plVar3[-1];
        *plVar6 = *plVar3;
        plVar6[1] = plVar3[1];
        plVar6 = plVar6 + 3;
        iVar2 = iVar2 + -1;
        plVar3 = plVar3 + 4;
      } while (iVar2 != 0);
    }
    if ((0 < cliff_info.cliff_size_variance) && (0 < cliff_info.number_of_cliffs)) {
      cliff_info.number_of_cliffs_variance = cliff_info.number_of_cliffs;
      pRVar4 = (RGE_RMM_Cliffs_Generator *)operator_new(0x508);
      local_4 = 0;
      if (pRVar4 != (RGE_RMM_Cliffs_Generator *)0x0) {
        uVar1 = *(undefined4 *)&this->field_0xc;
        plVar6 = &cliff_info.number_of_cliffs_variance;
        plVar3 = alStack_99c;
        cliff_info.number_of_cliffs = (long)pRVar4;
        for (iVar2 = 0x130; iVar2 != 0; iVar2 = iVar2 + -1) {
          *plVar3 = *plVar6;
          plVar6 = plVar6 + 1;
          plVar3 = plVar3 + 1;
        }
        RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(pRVar4,uVar1,this);
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: de_init
// Address: 00487930
uchar __thiscall TRIBE_RMM_Database_Controller::de_init(TRIBE_RMM_Database_Controller *this)
{
  RGE_RMM_Database_Controller::de_init((RGE_RMM_Database_Controller *)this);
  return '\x01';
}

// --------------------------------------------------

// Function: add_land_module
// Address: 00487940
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_land_initilization__r: "Random Map land initilization, rand: %d"
void __thiscall
TRIBE_RMM_Database_Controller::add_land_module(TRIBE_RMM_Database_Controller *this,uchar param_1)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  TDebuggingLog *this_00;
  int iVar7;
  
  iVar2 = *(int *)&this->field_0x34;
  uVar1 = *(undefined4 *)(*(int *)&this->field_0x4f58 + 0x18 + iVar2 * 0x48);
  if (((iVar2 == 5) || (iVar2 == 8)) && (*(int *)&this->field_0x14 < 100)) {
    *(uint *)(*(int *)&this->field_0x4f58 + 0x18 + iVar2 * 0x48) =
         ((0x4f < *(int *)&this->field_0x14) - 1 & 0xfffffffb) + 0x19;
  }
  RGE_RMM_Database_Controller::add_land_module((RGE_RMM_Database_Controller *)this,param_1);
  *(undefined4 *)(*(int *)&this->field_0x4f58 + 0x18 + *(int *)&this->field_0x34 * 0x48) = uVar1;
  if (*(int *)&this->field_0x34 < 5) {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xb9);
    if (iVar2 < 0x3fff) {
      iVar2 = 0;
      *(undefined4 *)&this->field_0x1460 = 0xffffffff;
      if (0 < *(int *)&this->field_0x1458) {
        puVar3 = (undefined4 *)&this->field_0x5c;
        do {
          *puVar3 = 0xffffffff;
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 0xd;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
    }
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xc0);
    if (iVar2 < 0x3fff) {
      iVar2 = 0;
      *(undefined4 *)&this->field_0x1464 = 0xffffffff;
      if (0 < *(int *)&this->field_0x1458) {
        puVar3 = (undefined4 *)&this->field_0x60;
        do {
          *puVar3 = 0xffffffff;
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 0xd;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
    }
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,199);
    if (iVar2 < 0x3fff) {
      *(undefined4 *)&this->field_0x1468 = *(undefined4 *)&this->field_0x14;
      iVar2 = 0;
      if (0 < *(int *)&this->field_0x1458) {
        puVar3 = (undefined4 *)&this->field_0x64;
        do {
          iVar2 = iVar2 + 1;
          *puVar3 = *(undefined4 *)&this->field_0x14;
          puVar3 = puVar3 + 0xd;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
    }
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xce);
    if (iVar2 < 0x3fff) {
      *(undefined4 *)&this->field_0x146c = *(undefined4 *)&this->field_0x18;
      iVar2 = 0;
      if (0 < *(int *)&this->field_0x1458) {
        puVar3 = (undefined4 *)&this->field_0x68;
        do {
          iVar2 = iVar2 + 1;
          *puVar3 = *(undefined4 *)&this->field_0x18;
          puVar3 = puVar3 + 0xd;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
    }
  }
  if (*(int *)&this->field_0x34 == 8) {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xd8);
    if (iVar2 < 0x3fff) {
      iVar2 = 0;
      *(undefined4 *)&this->field_0x1468 = *(undefined4 *)&this->field_0x14;
      *(undefined4 *)&this->field_0x1460 = 0xffffffff;
      if (0 < *(int *)&this->field_0x1458) {
        puVar3 = (undefined4 *)&this->field_0x64;
        do {
          puVar3[-2] = 0xffffffff;
          *puVar3 = *(undefined4 *)&this->field_0x14;
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 0xd;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
    }
    else {
      iVar2 = 0;
      *(undefined4 *)&this->field_0x146c = *(undefined4 *)&this->field_0x18;
      *(undefined4 *)&this->field_0x1464 = 0xffffffff;
      if (0 < *(int *)&this->field_0x1458) {
        puVar3 = (undefined4 *)&this->field_0x68;
        do {
          puVar3[-2] = 0xffffffff;
          *puVar3 = *(undefined4 *)&this->field_0x18;
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 0xd;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
    }
  }
  iVar2 = *(int *)&this->field_0x34;
  if (((1 < iVar2) && (iVar2 < 7)) || (iVar2 == 8)) {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xf1);
    if (iVar2 < 0x3fff) {
      iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xf7);
      if (iVar2 < 0x3fff) {
        iVar2 = 0;
        if (0 < *(int *)&this->field_0x1458) {
          puVar6 = &this->field_0x54;
          do {
            *puVar6 = 0;
            iVar2 = iVar2 + 2;
            puVar6 = puVar6 + 0x68;
          } while (iVar2 < *(int *)&this->field_0x1458);
        }
      }
      else {
        iVar2 = 0;
        if (0 < *(int *)&this->field_0x1458) {
          puVar6 = &this->field_0x54;
          do {
            *puVar6 = (char)iVar2;
            iVar2 = iVar2 + 2;
            puVar6 = puVar6 + 0x68;
          } while (iVar2 < *(int *)&this->field_0x1458);
        }
      }
      iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0xff);
      iVar4 = 1;
      if (iVar2 < 0x3fff) {
        if (1 < *(int *)&this->field_0x1458) {
          puVar6 = &this->field_0x88;
          do {
            *puVar6 = 1;
            iVar4 = iVar4 + 2;
            puVar6 = puVar6 + 0x68;
          } while (iVar4 < *(int *)&this->field_0x1458);
          add_shallows_module(this);
          goto LAB_00487c90;
        }
      }
      else if (1 < *(int *)&this->field_0x1458) {
        puVar6 = &this->field_0x88;
        do {
          *puVar6 = (char)iVar4;
          iVar4 = iVar4 + 2;
          puVar6 = puVar6 + 0x68;
        } while (iVar4 < *(int *)&this->field_0x1458);
      }
      add_shallows_module(this);
    }
    else if (*(int *)&this->field_0x34 == 4) {
      iVar2 = 0;
      if (0 < *(int *)&this->field_0x1458) {
        puVar6 = &this->field_0x54;
        do {
          *puVar6 = 0;
          iVar2 = iVar2 + 1;
          puVar6 = puVar6 + 0x34;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
      this->field_0x145c = 0;
    }
    else if ((4 < *(int *)&this->field_0x34) && (iVar2 = 0, 0 < *(int *)&this->field_0x1458)) {
      puVar6 = &this->field_0x54;
      do {
        *puVar6 = 0;
        iVar2 = iVar2 + 1;
        puVar6 = puVar6 + 0x34;
      } while (iVar2 < *(int *)&this->field_0x1458);
    }
  }
LAB_00487c90:
  if ((*(int *)&this->field_0x34 == 5) || (*(int *)&this->field_0x34 == 8)) {
    iVar2 = *(int *)&this->field_0x14;
    if (iVar2 < 100) {
      iVar4 = ((0x4f < iVar2) - 1 & 0xfffffffb) + 0xf;
      if (0 < *(int *)&this->field_0x1460) {
        *(int *)&this->field_0x1460 = iVar4;
      }
      if (0 < *(int *)&this->field_0x1464) {
        *(int *)&this->field_0x1464 = iVar4;
      }
      if (*(int *)&this->field_0x1468 < iVar2) {
        *(int *)&this->field_0x1468 = iVar2 - iVar4;
      }
      if (*(int *)&this->field_0x146c < *(int *)&this->field_0x18) {
        *(int *)&this->field_0x146c = *(int *)&this->field_0x18 - iVar4;
      }
      iVar2 = 0;
      if (0 < *(int *)&this->field_0x1458) {
        piVar5 = (int *)&this->field_0x60;
        do {
          if (0 < piVar5[-1]) {
            piVar5[-1] = iVar4;
          }
          if (0 < *piVar5) {
            *piVar5 = iVar4;
          }
          if (piVar5[1] < *(int *)&this->field_0x14) {
            piVar5[1] = *(int *)&this->field_0x14 - iVar4;
          }
          if (piVar5[2] < *(int *)&this->field_0x18) {
            piVar5[2] = *(int *)&this->field_0x18 - iVar4;
          }
          iVar2 = iVar2 + 1;
          piVar5 = piVar5 + 0xd;
        } while (iVar2 < *(int *)&this->field_0x1458);
      }
    }
    iVar4 = __ftol();
    iVar2 = *(int *)&this->field_0x1458;
    iVar7 = 0;
    if (0 < iVar2) {
      piVar5 = (int *)&this->field_0x3c;
      do {
        iVar7 = iVar7 + 1;
        *piVar5 = iVar4 / iVar2;
        iVar2 = *(int *)&this->field_0x1458;
        piVar5 = piVar5 + 0xd;
      } while (iVar7 < iVar2);
    }
  }
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x137);
  TDebuggingLog::Log(this_00,(char *)L,s_Random_Map_land_initilization__r,iVar2);
  return;
}

// --------------------------------------------------

// Function: add_terrain_module
// Address: 00487dd0
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_terrain_initilization: "Random Map terrain initilization, rand: %d"
void __thiscall
TRIBE_RMM_Database_Controller::add_terrain_module(TRIBE_RMM_Database_Controller *this)
{
  int iVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  TDebuggingLog *this_00;
  int iVar8;
  long land_tile_num;
  
  iVar5 = *(int *)(*(int *)&this->field_0x4f58 + 0x20 + *(int *)&this->field_0x34 * 0x48);
  iVar1 = *(int *)&this->field_0x18;
  iVar2 = *(int *)&this->field_0x14;
  RGE_RMM_Database_Controller::add_terrain_module((RGE_RMM_Database_Controller *)this);
  iVar8 = 0;
  fVar3 = (float)((iVar5 * iVar1 * iVar2) / 100) * _DAT_00571f28;
  if (0 < *(int *)&this->field_0x20d4) {
    puVar6 = (undefined4 *)&this->field_0x1480;
    do {
      if ((puVar6[-1] != 6) && ((float)_DAT_00571f30 < fVar3)) {
        uVar4 = __ftol();
        *puVar6 = uVar4;
      }
      iVar8 = iVar8 + 1;
      puVar6 = puVar6 + 8;
    } while (iVar8 < *(int *)&this->field_0x20d4);
  }
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x154);
  if (iVar5 < 0x1fff) {
    iVar5 = 0;
    if (0 < *(int *)&this->field_0x20d4) {
      piVar7 = (int *)&this->field_0x1480;
      do {
        iVar1 = piVar7[-1];
        if (iVar1 == 0xd) {
          piVar7[-3] = piVar7[-3] * 3;
          *piVar7 = *piVar7 * 3;
          piVar7[4] = 2;
        }
        else if (iVar1 == 0x14) {
          piVar7[-3] = piVar7[-3] / 2;
          *piVar7 = *piVar7 / 2;
        }
        else if (iVar1 == 0x13) {
          piVar7[-3] = piVar7[-3] / 2;
          *piVar7 = *piVar7 / 2;
        }
        else if (iVar1 == 10) {
          piVar7[-3] = piVar7[-3] / 2;
          *piVar7 = *piVar7 / 2;
          piVar7[4] = 2;
        }
        else if (iVar1 == 6) {
          piVar7[-3] = piVar7[-3] << 1;
          piVar7[4] = 0;
        }
        iVar5 = iVar5 + 1;
        piVar7 = piVar7 + 8;
      } while (iVar5 < *(int *)&this->field_0x20d4);
    }
  }
  else {
    iVar5 = 0;
    if (0 < *(int *)&this->field_0x20d4) {
      puVar6 = (undefined4 *)&this->field_0x1490;
      do {
        iVar1 = puVar6[-5];
        if (iVar1 == 6) {
          *puVar6 = 0;
        }
        else if ((iVar1 == 10) || (iVar1 == 0xd)) {
          *puVar6 = 2;
        }
        iVar5 = iVar5 + 1;
        puVar6 = puVar6 + 8;
      } while (iVar5 < *(int *)&this->field_0x20d4);
    }
  }
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x180);
  TDebuggingLog::Log(this_00,(char *)L,s_Random_Map_terrain_initilization,iVar5);
  return;
}

// --------------------------------------------------

// Function: add_object_module
// Address: 00487fa0
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_object_initilization_: "Random Map object initilization, rand: %d"
void __thiscall
TRIBE_RMM_Database_Controller::add_object_module(TRIBE_RMM_Database_Controller *this)
{
  bool bVar1;
  Age AVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uchar done;
  long extra_island_roll;
  long count;
  long index1;
  int local_8;
  
  RGE_RMM_Database_Controller::add_object_module((RGE_RMM_Database_Controller *)this);
  debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x198);
  AVar2 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar2 == NomadAge) {
    iVar6 = 0;
    if (0 < *(int *)&this->field_0x399c) {
      puVar3 = (undefined4 *)&this->field_0x2720;
      do {
        if (puVar3[-5] == 0x53) {
          *puVar3 = 1;
        }
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 0xc;
      } while (iVar6 < *(int *)&this->field_0x399c);
    }
    iVar6 = 0;
    if (0 < *(int *)&this->field_0x399c) {
      puVar3 = (undefined4 *)&this->field_0x2720;
      do {
        if (puVar3[-5] == 0x6d) {
          *puVar3 = 0;
        }
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 0xc;
      } while (iVar6 < *(int *)&this->field_0x399c);
    }
  }
  if (*(int *)&this->field_0x34 == 6) {
    iVar6 = *(int *)&this->field_0x1458;
    if (0 < iVar6) {
      puVar3 = (undefined4 *)(&this->field_0x3c + iVar6 * 0x34);
      do {
        iVar6 = iVar6 + -1;
        puVar10 = puVar3 + -0xd;
        puVar11 = puVar3;
        for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        puVar3 = puVar3 + -0xd;
      } while (iVar6 != 0);
    }
    iVar6 = *(int *)&this->field_0x14;
    iVar9 = iVar6 / 6;
    iVar7 = *(int *)&this->field_0x18;
    this->field_0x54 = this->field_0x1458;
    *(undefined4 *)&this->field_0x40 = 1;
    *(undefined4 *)&this->field_0x50 = 7;
    *(undefined4 *)&this->field_0x4c = 2;
    uVar4 = __ftol();
    *(undefined4 *)&this->field_0x3c = uVar4;
    *(undefined4 *)&this->field_0x58 = 10;
    *(int *)&this->field_0x44 = *(int *)(*(int *)&this->field_0xc + 8) / 2;
    iVar5 = *(int *)(*(int *)&this->field_0xc + 0xc);
    *(int *)&this->field_0x5c = iVar9;
    *(int *)&this->field_0x48 = iVar5 / 2;
    *(int *)&this->field_0x60 = iVar9;
    *(int *)&this->field_0x64 = iVar6 - iVar9;
    *(int *)&this->field_0x68 = iVar7 - iVar9;
    this->field_0x6c = 10;
    *(int *)&this->field_0x1458 = *(int *)&this->field_0x1458 + 1;
  }
  if (*(int *)&this->field_0x34 < 2) {
    iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1c3);
    count = (iVar6 * 4) / 0x7fff + 1;
    if (10 < count + *(int *)&this->field_0x38) {
      count = 10 - *(int *)&this->field_0x38;
    }
    iVar6 = *(int *)&this->field_0x18;
    iVar7 = *(int *)&this->field_0x14;
    iVar5 = *(int *)&this->field_0x1458;
    iVar9 = 0;
    if (0 < iVar5) {
      piVar8 = (int *)&this->field_0x3c;
      do {
        iVar9 = iVar9 + 1;
        *piVar8 = *piVar8 - ((iVar6 + iVar7) * count) / iVar5;
        piVar8 = piVar8 + 0xd;
      } while (iVar9 < *(int *)&this->field_0x1458);
    }
    iVar6 = 0;
    if (0 < count) {
      do {
        *(undefined4 *)(&this->field_0x40 + (iVar6 + *(int *)&this->field_0x1458) * 0x34) = 0;
        *(undefined4 *)(&this->field_0x50 + (iVar6 + *(int *)&this->field_0x1458) * 0x34) = 7;
        *(undefined4 *)(&this->field_0x4c + (iVar6 + *(int *)&this->field_0x1458) * 0x34) = 3;
        (&this->field_0x54)[(iVar6 + *(int *)&this->field_0x1458) * 0x34] =
             (char)iVar6 + this->field_0x1458;
        uVar4 = __ftol();
        index1 = 0;
        *(undefined4 *)(&this->field_0x3c + (iVar6 + *(int *)&this->field_0x1458) * 0x34) = uVar4;
        *(undefined4 *)(&this->field_0x58 + (iVar6 + *(int *)&this->field_0x1458) * 0x34) = 10;
        *(undefined4 *)(&this->field_0x5c + (iVar6 + *(int *)&this->field_0x1458) * 0x34) =
             *(undefined4 *)&this->field_0x1460;
        *(undefined4 *)(&this->field_0x60 + (iVar6 + *(int *)&this->field_0x1458) * 0x34) =
             *(undefined4 *)&this->field_0x1464;
        *(undefined4 *)(&this->field_0x64 + (iVar6 + *(int *)&this->field_0x1458) * 0x34) =
             *(undefined4 *)&this->field_0x1468;
        *(undefined4 *)(&this->field_0x68 + iVar6 * 0x34 + *(int *)&this->field_0x1458 * 0x34) =
             *(undefined4 *)&this->field_0x146c;
        (&this->field_0x6c)[(iVar6 + *(int *)&this->field_0x1458) * 0x34] = this->field_0x1470;
        do {
          index1 = index1 + 1;
          bVar1 = true;
          iVar7 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1de);
          iVar7 = (iVar7 * (*(int *)&this->field_0x14 + -0x10)) / 0x7fff + 8;
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1df);
          local_8 = 0;
          iVar5 = (iVar5 * (*(int *)&this->field_0x18 + -0x10)) / 0x7fff + 8;
          if (0 < *(int *)&this->field_0x1458) {
            piVar8 = (int *)&this->field_0x48;
            do {
              if (!bVar1) goto LAB_00488399;
              if ((iVar7 - piVar8[-1]) * (iVar7 - piVar8[-1]) +
                  (iVar5 - *piVar8) * (iVar5 - *piVar8) < 400) {
                bVar1 = false;
              }
              local_8 = local_8 + 1;
              piVar8 = piVar8 + 0xd;
            } while (local_8 < *(int *)&this->field_0x1458);
          }
          if (bVar1) break;
LAB_00488399:
        } while (index1 < 1000);
        if (999 < index1) {
          count = iVar6;
        }
        *(int *)(&this->field_0x44 + (iVar6 + *(int *)&this->field_0x1458) * 0x34) = iVar7;
        *(int *)(&this->field_0x48 + (iVar6 + *(int *)&this->field_0x1458) * 0x34) = iVar5;
        *(undefined4 *)(&this->field_0x2710 + *(int *)&this->field_0x399c * 0x30) = 0xffffffff;
        (&this->field_0x2714)[*(int *)&this->field_0x399c * 0x30] = 2;
        (&this->field_0x2715)[*(int *)&this->field_0x399c * 0x30] = 0;
        *(undefined4 *)(&this->field_0x2718 + *(int *)&this->field_0x399c * 0x30) = 8;
        *(undefined4 *)(&this->field_0x271c + *(int *)&this->field_0x399c * 0x30) = 0;
        *(undefined4 *)(&this->field_0x2720 + *(int *)&this->field_0x399c * 0x30) = 1;
        *(undefined4 *)(&this->field_0x2724 + *(int *)&this->field_0x399c * 0x30) = 4;
        *(undefined4 *)(&this->field_0x2728 + *(int *)&this->field_0x399c * 0x30) = 0;
        *(int *)(&this->field_0x272c + *(int *)&this->field_0x399c * 0x30) =
             iVar6 + *(int *)&this->field_0x1458;
        *(undefined4 *)(&this->field_0x2730 + *(int *)&this->field_0x399c * 0x30) = 0;
        *(undefined4 *)(&this->field_0x2734 + *(int *)&this->field_0x399c * 0x30) = 0x1a;
        *(undefined4 *)(&this->field_0x2738 + *(int *)&this->field_0x399c * 0x30) = 0;
        iVar9 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x1fd);
        if (iVar9 < 0x3fff) {
          *(undefined4 *)(&this->field_0x270c + *(int *)&this->field_0x399c * 0x30) = 0x66;
        }
        else {
          *(undefined4 *)(&this->field_0x270c + *(int *)&this->field_0x399c * 0x30) = 0x42;
        }
        *(int *)&this->field_0x399c = *(int *)&this->field_0x399c + 1;
        *(int *)(&this->field_0x39a4 + *(int *)&this->field_0x3fd0 * 0x10) = iVar5;
        *(int *)(&this->field_0x39a0 + *(int *)&this->field_0x3fd0 * 0x10) = iVar7;
        *(int *)(&this->field_0x39a8 + *(int *)&this->field_0x3fd0 * 0x10) =
             iVar6 + *(int *)&this->field_0x1458;
        *(undefined4 *)(&this->field_0x39ac + *(int *)&this->field_0x3fd0 * 0x10) = 0;
        iVar6 = iVar6 + 1;
        *(int *)&this->field_0x3fd0 = *(int *)&this->field_0x3fd0 + 1;
      } while (iVar6 < count);
    }
    *(int *)&this->field_0x1458 = *(int *)&this->field_0x1458 + count;
  }
  iVar6 = 0;
  if (0 < *(int *)&this->field_0x399c) {
    piVar8 = (int *)&this->field_0x2738;
    do {
      if (-1 < piVar8[-3]) {
        switch(piVar8[-0xb]) {
        case 0x3b:
        case 0x41:
        case 0x42:
        case 0x66:
          *piVar8 = 0xc;
        }
        goto switchD_004885d5_caseD_3c;
      }
      if (piVar8[-3] != -2) goto switchD_004885d5_caseD_3c;
      switch(piVar8[-0xb]) {
      case 0x3b:
      case 0x42:
        iVar7 = *(int *)(*(int *)&this->field_0xc + 8);
        goto LAB_00488624;
      case 0x41:
        iVar7 = *(int *)(*(int *)&this->field_0xc + 8);
        *piVar8 = (int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3;
        break;
      case 0x66:
        iVar7 = *(int *)(*(int *)&this->field_0xc + 8);
LAB_00488624:
        *piVar8 = iVar7 / 6;
      }
switchD_004885d5_caseD_3c:
      iVar6 = iVar6 + 1;
      piVar8 = piVar8 + 0xc;
    } while (iVar6 < *(int *)&this->field_0x399c);
  }
  iVar6 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x236);
  TDebuggingLog::Log(L,(char *)L,s_Random_Map_object_initilization_,iVar6);
  return;
}

// --------------------------------------------------

// Function: add_elevation_module
// Address: 00488700
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_elevation_initilizati: "Random Map elevation initilization, rand: %d"
void __thiscall
TRIBE_RMM_Database_Controller::add_elevation_module(TRIBE_RMM_Database_Controller *this)
{
  undefined4 uVar1;
  TDebuggingLog *this_00;
  undefined4 *puVar2;
  int iVar3;
  
  RGE_RMM_Database_Controller::add_elevation_module((RGE_RMM_Database_Controller *)this);
  debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x243);
  iVar3 = 0;
  if (0 < *(int *)&this->field_0x491c) {
    puVar2 = (undefined4 *)&this->field_0x3fd4;
    do {
      uVar1 = __ftol();
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 6;
    } while (iVar3 < *(int *)&this->field_0x491c);
  }
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x24b);
  TDebuggingLog::Log(this_00,(char *)L,s_Random_Map_elevation_initilizati,iVar3);
  return;
}

// --------------------------------------------------

// Function: add_shallows_module
// Address: 004887a0
// [HELPER] s_C__msdev_work_age1_x1_rmm_tdbc_c: "C:\msdev\work\age1_x1\rmm_tdbc.cpp"
// [HELPER] s_Random_Map_shallows_initilizatio: "Random Map shallows initilization, rand: %d"
void __thiscall
TRIBE_RMM_Database_Controller::add_shallows_module(TRIBE_RMM_Database_Controller *this)
{
  long *plVar1;
  int iVar2;
  RGE_Shallows_Info_Line *pRVar3;
  TDebuggingLog *this_00;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  RGE_Shallows_Info shallows_info;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e6de;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = 0;
  iVar2 = *(int *)&this->field_0x1458;
  if (0 < iVar2) {
    pRVar3 = shallows_info.shallows;
    plVar1 = (long *)&this->field_0x48;
    do {
      pRVar3 = pRVar3 + 1;
      iVar4 = iVar4 + 1;
      ((RGE_Shallows_Info *)(pRVar3 + -1))->shallows[0].y = plVar1[-1];
      pRVar3->x = *plVar1;
      plVar1 = plVar1 + 0xd;
    } while (iVar4 < iVar2);
  }
  shallows_info.shallows[0].x = (long)operator_new(0x34c);
  local_4 = 0;
  if ((RGE_RMM_Shallows_Generator *)shallows_info.shallows[0].x != (RGE_RMM_Shallows_Generator *)0x0
     ) {
    RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator
              ((RGE_RMM_Shallows_Generator *)shallows_info.shallows[0].x,
               *(RGE_Map **)&this->field_0xc,(RGE_Random_Map_Module *)this,
               (RGE_Shallows_Info *)&shallows_info.shallows[0].y);
  }
  local_4 = 0xffffffff;
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_rmm_tdbc_c,0x25f);
  TDebuggingLog::Log(this_00,(char *)L,s_Random_Map_shallows_initilizatio,iVar2);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: generate
// Address: 00488870
uchar __thiscall TRIBE_RMM_Database_Controller::generate(TRIBE_RMM_Database_Controller *this)
{
  int iVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar ret_num;
  
  uVar2 = RGE_RMM_Database_Controller::generate((RGE_RMM_Database_Controller *)this);
  iVar4 = 0;
  if (0 < *(int *)&this->field_0x18) {
    iVar5 = 0;
    do {
      iVar6 = 0;
      if (0 < *(int *)&this->field_0x14) {
        iVar3 = 0;
        do {
          if ((*(byte *)(*(int *)(*(int *)&this->field_0x10 + iVar5) + 5 + iVar3) & 0x1f) == 0x10) {
            iVar1 = *(int *)(*(int *)&this->field_0x10 + iVar5);
            *(byte *)(iVar1 + 5 + iVar3) = *(byte *)(iVar1 + 5 + iVar3) & 0xe0;
          }
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 0x18;
        } while (iVar6 < *(int *)&this->field_0x14);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar4 < *(int *)&this->field_0x18);
  }
  return uVar2;
}

// --------------------------------------------------

