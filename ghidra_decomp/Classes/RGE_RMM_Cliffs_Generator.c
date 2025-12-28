// Class: RGE_RMM_Cliffs_Generator
// Size:  0x508
//
// VTable Layout:
// [00] generate
// [01] generate
//
// Member Layout:
// [0x030] RGE_Cliffs_Info info (sz: 0x4C0)
// [0x4F0] Map_Stack valid_cliff_sites (sz: 0x18)
// ----------------------------------------------------------------

// Function: RGE_RMM_Cliffs_Generator
// Address: 00481980
/* public: __thiscall RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(class RGE_Map *,class
   RGE_Random_Map_Module *,struct RGE_Cliffs_Info) */

RGE_RMM_Cliffs_Generator * __thiscall
RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator
          (RGE_RMM_Cliffs_Generator *this,RGE_Map *param_1,RGE_Random_Map_Module *param_2)
{
  int iVar1;
  long *plVar2;
  RGE_Cliffs_Info *pRVar3;
  
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)this,param_1,param_2,'\x01')
  ;
  this->_padding_ = (int)&_vftable_;
  plVar2 = (long *)&stack0x0000000c;
  pRVar3 = &this->info;
  for (iVar1 = 0x130; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar3->number_of_cliffs = *plVar2;
    plVar2 = plVar2 + 1;
    pRVar3 = (RGE_Cliffs_Info *)&pRVar3->number_of_cliffs_variance;
  }
  this->_padding_ = 0x3fe00000;
  return this;
}

// --------------------------------------------------

// Function: generate
// Address: 004819c0
// [HELPER] s_C__msdev_work_age1_x1_rmm_clif_c: "C:\msdev\work\age1_x1\rmm_clif.cpp"
/* public: virtual unsigned char __thiscall RGE_RMM_Cliffs_Generator::generate(void) */

uchar __thiscall RGE_RMM_Cliffs_Generator::generate(RGE_RMM_Cliffs_Generator *this)
{
  int iVar1;
  
  setup_cliff_maps(this);
  debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0x32);
  iVar1 = 0;
  if (0 < (this->info).number_of_cliffs) {
    do {
      generate_cliff(this);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (this->info).number_of_cliffs);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: setup_cliff_maps
// Address: 00481a00
/* WARNING: Variable defined which should be unmapped: water_area */
/* protected: void __thiscall RGE_RMM_Cliffs_Generator::setup_cliff_maps(void) */

void __thiscall RGE_RMM_Cliffs_Generator::setup_cliff_maps(RGE_RMM_Cliffs_Generator *this)
{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  byte bVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  long *plVar13;
  int iVar14;
  undefined4 *puVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  uchar water_area;
  long cliff_x;
  long cliff_y;
  long cliff_width;
  int local_20;
  long cliff_height;
  uchar terrain_height;
  int local_10;
  long cliff_height2;
  long cliff_width2;
  
  iVar5 = this->_padding_ / 3;
  iVar6 = this->_padding_ / 3;
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)this);
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,&this->valid_cliff_sites);
  uVar10 = this->_padding_ * this->_padding_;
  puVar15 = (undefined4 *)this->_padding_;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *puVar15 = 0x1010101;
    puVar15 = puVar15 + 1;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined1 *)puVar15 = 1;
    puVar15 = (undefined4 *)((int)puVar15 + 1);
  }
  cliff_width = 0;
  if (0 < iVar6) {
    cliff_height = 0;
    do {
      cliff_y = 0;
      if (0 < iVar5) {
        local_20 = 0;
        do {
          uVar11 = 0xffffffff;
          bVar4 = true;
          bVar7 = false;
          piVar16 = (int *)(cliff_height + this->_padding_);
          cliff_height2 = 3;
          do {
            local_10 = 3;
            pbVar12 = (byte *)(*piVar16 + 5 + local_20);
            do {
              bVar8 = *pbVar12 & 0x1f;
              if ((bVar8 == 0) || (bVar8 == 6)) {
                bVar8 = *pbVar12 >> 5;
                if ((int)uVar11 < 0) {
                  uVar11 = (uint)bVar8;
                }
                else if (uVar11 != bVar8) {
                  bVar4 = false;
                }
              }
              else {
                bVar4 = false;
                if (((bVar8 == 1) || (bVar8 == 4)) || (bVar8 == 0x16)) {
                  bVar7 = true;
                }
              }
              pbVar12 = pbVar12 + 0x18;
              local_10 = local_10 + -1;
            } while (local_10 != 0);
            piVar16 = piVar16 + 1;
            cliff_height2 = cliff_height2 + -1;
          } while (cliff_height2 != 0);
          if (bVar4) {
            pcVar9 = (char *)(*(int *)(this->_padding_ + cliff_width * 4) + cliff_y);
            if (*pcVar9 != '\0') {
              *pcVar9 = (char)uVar11 + '\x01';
              RGE_Random_Map_Module::push_stack
                        ((RGE_Random_Map_Module *)this,&this->valid_cliff_sites,cliff_y,cliff_width,
                         0.0,0.0);
            }
          }
          else {
            if (bVar7) {
              invalidate_cliff_area(this,cliff_y,cliff_width,(this->info).cliff_terrain_spacing);
            }
            *(undefined1 *)(*(int *)(this->_padding_ + cliff_width * 4) + cliff_y) = 0;
          }
          cliff_y = cliff_y + 1;
          local_20 = local_20 + 0x48;
        } while (cliff_y < iVar5);
      }
      cliff_width = cliff_width + 1;
      cliff_height = cliff_height + 0xc;
    } while (cliff_width < iVar6);
  }
  iVar17 = 0;
  if (0 < (this->info).hot_spot_num) {
    plVar13 = &(this->info).hot_spots[0].y;
    do {
      invalidate_cliff_area
                (this,((RGE_Cliffs_Hot_Spots *)(plVar13 + -1))->x / 3,*plVar13 / 3,
                 plVar13[1] / 3 + 2);
      iVar17 = iVar17 + 1;
      plVar13 = plVar13 + 3;
    } while (iVar17 < (this->info).hot_spot_num);
  }
  iVar17 = 0;
  if (0 < iVar6) {
    do {
      iVar14 = 0;
      if (0 < iVar5) {
        iVar18 = 0;
        do {
          iVar2 = this->_padding_;
          iVar3 = *(int *)(iVar2 + iVar17 * 4);
          puVar1 = (undefined1 *)(iVar14 + iVar3);
          if ((((*(char *)(iVar14 + iVar3) != '\0') &&
               ((iVar17 < 1 || (*(char *)(*(int *)(iVar2 + -4 + iVar17 * 4) + iVar14) == '\0')))) &&
              ((iVar18 < 1 || (puVar1[-1] == '\0')))) &&
             (((iVar6 + -1 <= iVar17 ||
               (*(char *)(*(int *)(iVar2 + 4 + iVar17 * 4) + iVar14) == '\0')) &&
              ((iVar5 + -1 <= iVar14 || (puVar1[1] == '\0')))))) {
            *puVar1 = 0;
            RGE_Random_Map_Module::remove_stack_node
                      ((RGE_Random_Map_Module *)this,
                       (Map_Stack *)(*(int *)(this->_padding_ + iVar17 * 4) + iVar18));
          }
          iVar14 = iVar14 + 1;
          iVar18 = iVar18 + 0x18;
        } while (iVar14 < iVar5);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < iVar6);
  }
  RGE_Random_Map_Module::randomize_stack((RGE_Random_Map_Module *)this,&this->valid_cliff_sites);
  return;
}

// --------------------------------------------------

// Function: generate_cliff
// Address: 00481cd0
// [HELPER] s_C__msdev_work_age1_x1_rmm_clif_c: "C:\msdev\work\age1_x1\rmm_clif.cpp"
/* WARNING: Variable defined which should be unmapped: cliff_end_found */
/* protected: void __thiscall RGE_RMM_Cliffs_Generator::generate_cliff(void) */

void __thiscall RGE_RMM_Cliffs_Generator::generate_cliff(RGE_RMM_Cliffs_Generator *this)
{
  bool bVar1;
  bool bVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  int iVar7;
  uchar cliff_end_found;
  uchar first_cliff;
  long x;
  long y;
  long valid_height;
  long index;
  long this_cliff_size;
  float cost;
  Map_Stack cliff;
  
  iVar6 = -1;
  iVar5 = (this->info).cliff_size_variance;
  iVar7 = -1;
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0xc4);
  bVar1 = true;
  cost = (float)(((iVar4 * iVar5 * 2) / 0x7fff + (this->info).average_cliff_size) - iVar5);
  if ((this->valid_cliff_sites).next == (Map_Stack *)0x0) {
    return;
  }
  if ((int)cost < 3) {
    return;
  }
  RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)this,(Map_Stack *)&cliff.y);
  while (RGE_Random_Map_Module::pop_stack
                   ((RGE_Random_Map_Module *)this,&this->valid_cliff_sites,&y,&valid_height,
                    (float *)&cliff),
        *(char *)(*(int *)(this->_padding_ + valid_height * 4) + y) == '\0') {
    if ((this->valid_cliff_sites).next == (Map_Stack *)0x0) {
      return;
    }
  }
  index = (long)*(byte *)(*(int *)(this->_padding_ + valid_height * 4) + y);
  RGE_Random_Map_Module::push_stack
            ((RGE_Random_Map_Module *)this,(Map_Stack *)&cliff.y,y,valid_height,0.0,0.0);
  *(undefined1 *)(*(int *)(this->_padding_ + valid_height * 4) + y) = 0;
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0xdd);
  iVar5 = (iVar5 * 4) / 0x7fff;
  this_cliff_size = 0;
  if (0 < (int)cost) {
    do {
      bVar2 = false;
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_clif_c,0xe3);
      iVar4 = (iVar4 * 100) / 0x7fff;
      if (iVar4 < 0x12) {
        if (iVar5 < 1) {
          iVar5 = 3;
        }
        else {
          iVar5 = iVar5 + -1;
        }
      }
      else if (iVar4 < 0x24) {
        if (iVar5 < 3) {
          iVar5 = iVar5 + 1;
        }
        else {
          iVar5 = 0;
        }
      }
      uVar3 = check_for_valid_cliff_site(this,iVar5,&y,&valid_height,index);
      if ((((uVar3 == '\0') &&
           (uVar3 = check_for_valid_cliff_site(this,iVar5 + 1,&y,&valid_height,index), uVar3 == '\0'
           )) && (uVar3 = check_for_valid_cliff_site(this,iVar5 + -1,&y,&valid_height,index),
                 uVar3 == '\0')) &&
         ((!bVar1 ||
          (uVar3 = check_for_valid_cliff_site(this,iVar5 + -2,&y,&valid_height,index), uVar3 == '\0'
          )))) {
        bVar2 = true;
      }
      bVar1 = false;
      if (bVar2) break;
      RGE_Random_Map_Module::push_stack
                ((RGE_Random_Map_Module *)this,(Map_Stack *)&cliff.y,y,valid_height,0.0,0.0);
      *(undefined1 *)(*(int *)(this->_padding_ + valid_height * 4) + y) = 0;
      this_cliff_size = this_cliff_size + 1;
    } while (this_cliff_size < (int)cost);
  }
  while (cliff.prev != (Map_Stack *)0x0) {
    RGE_Random_Map_Module::pop_stack
              ((RGE_Random_Map_Module *)this,(Map_Stack *)&cliff.y,&y,&valid_height,(float *)&cliff)
    ;
    if (iVar6 == -1) {
      iVar6 = y;
      iVar7 = valid_height;
    }
    iVar4 = 0x10;
    iVar5 = iVar7 * 3 + 1;
    iVar6 = iVar6 * 3 + 1;
    (**(code **)(*(int *)this->_padding_ + 0x10))(iVar6,iVar5,y * 3 + 1,valid_height * 3 + 1,1,0x10)
    ;
    (**(code **)(*(int *)this->_padding_ + 0x20))(iVar6,iVar5,iVar4 * 3 + 1,unaff_EDI * 3 + 1,0,0);
    iVar7 = valid_height;
    iVar6 = y;
    invalidate_cliff_area(this,y,valid_height,(this->info).cliff_to_cliff_spacing);
  }
  return;
}

// --------------------------------------------------

// Function: check_for_valid_cliff_site
// Address: 00481fc0
/* protected: unsigned char __thiscall
   RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(long,long &,long &,long) */

uchar __thiscall
RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site
          (RGE_RMM_Cliffs_Generator *this,long param_1,long *param_2,long *param_3,long param_4)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_3;
  iVar3 = *param_2;
  if (3 < param_1) {
    uVar1 = (param_1 - 1U) / 3;
    do {
      param_1 = param_1 + -3;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if (param_1 < 0) {
    param_1 = ((2U - param_1) / 3) * 3 + param_1;
  }
  switch(param_1) {
  case 0:
    if (iVar2 < 1) {
      return '\0';
    }
    iVar2 = iVar2 + -1;
    break;
  case 1:
    if (this->_padding_ / 3 + -1 <= iVar3) {
      return '\0';
    }
    iVar3 = iVar3 + 1;
    break;
  case 2:
    if (this->_padding_ / 3 + -1 <= iVar2) {
      return '\0';
    }
    iVar2 = iVar2 + 1;
    break;
  case 3:
    if (iVar3 < 1) {
      return '\0';
    }
    iVar3 = iVar3 + -1;
  }
  if ((uint)*(byte *)(*(int *)(this->_padding_ + iVar2 * 4) + iVar3) != param_4) {
    return '\0';
  }
  *param_2 = iVar3;
  *param_3 = iVar2;
  return '\x01';
}

// --------------------------------------------------

// Function: invalidate_cliff_area
// Address: 004820a0
/* WARNING: Variable defined which should be unmapped: cliff_width2 */
/* protected: void __thiscall RGE_RMM_Cliffs_Generator::invalidate_cliff_area(long,long,long) */

void __thiscall
RGE_RMM_Cliffs_Generator::invalidate_cliff_area
          (RGE_RMM_Cliffs_Generator *this,long param_1,long param_2,long param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long cliff_width2;
  long cliff_height2;
  
  iVar6 = this->_padding_ / 3 + -1;
  iVar5 = this->_padding_ / 3 + -1;
  iVar2 = param_1 - param_3;
  iVar3 = param_2 - param_3;
  iVar4 = param_3 + param_1;
  iVar1 = param_3 + param_2;
  param_3 = iVar2;
  if (iVar2 < 0) {
    param_3 = 0;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar6 < iVar4) {
    iVar4 = iVar6;
  }
  if (iVar5 < iVar4) {
    iVar1 = iVar5;
  }
  if (iVar3 <= iVar1) {
    iVar6 = iVar3 * 4;
    param_2 = (iVar1 - iVar3) + 1;
    do {
      if (param_3 <= iVar4) {
        iVar5 = param_3 * 0x18;
        lVar7 = param_3;
        do {
          iVar1 = *(int *)(this->_padding_ + iVar6);
          if (*(char *)(lVar7 + iVar1) != '\0') {
            *(undefined1 *)(lVar7 + iVar1) = 0;
            RGE_Random_Map_Module::remove_stack_node
                      ((RGE_Random_Map_Module *)this,
                       (Map_Stack *)(*(int *)(this->_padding_ + iVar6) + iVar5));
          }
          lVar7 = lVar7 + 1;
          iVar5 = iVar5 + 0x18;
        } while (lVar7 <= iVar4);
      }
      iVar6 = iVar6 + 4;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

// --------------------------------------------------

