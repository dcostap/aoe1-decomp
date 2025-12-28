// GLOBAL FUNCTIONS PART 4200
// Function: FUN_004e1189
// Address: 004e1189
// XREFS: None
void __thiscall FUN_004e1189(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x1fc))) {
    param_2 = param_2 * 0x18;
    *(undefined4 *)(*(int *)(param_1 + 0x200) + param_2) = 0xffffffff;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 4 + param_2) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 5 + param_2) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 6 + param_2) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 7 + param_2) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 8 + param_2) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 9 + param_2) = 0xff;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 10 + param_2) = 0xff;
    *(undefined2 *)(*(int *)(param_1 + 0x200) + 0xc + param_2) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 0xe + param_2) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x14 + param_2) = 0xffffffff;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e1229
// Address: 004e1229
// XREFS: None
int __thiscall FUN_004e1229(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x1fc))) {
    return *(int *)(param_1 + 0x200) + param_2 * 0x18;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e1254
// Address: 004e1254
// XREFS: None
// [HELPER] s_learn__s_s__d: "learn\%s%s.%d"
// [HELPER] s_learn_default__d: "learn\default.%d"
void __thiscall FUN_004e1254(TribeInformationAIModule *param_1,int param_2)
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  ResourceMemory *pRVar7;
  int iVar8;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  uchar uStack_20;
  uchar uStack_1f;
  uchar uStack_1e;
  uchar uStack_1d;
  uchar uStack_1c;
  uchar uStack_1b;
  uchar uStack_1a;
  uchar uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  uchar uStack_16;
  undefined2 uStack_14;
  undefined2 uStack_12;
  int iStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pcVar1 = param_1->learnFileName;
  if (param_2 == 0) {
    sprintf(pcVar1,s_learn_default__d,(int)*(short *)(param_1->md->_padding_ + 0x4a));
  }
  else {
    pcVar2 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
    sprintf(pcVar1,s_learn__s_s__d,param_2,pcVar2);
  }
  iVar3 = rge_open(pcVar1,0x8000);
  if (iVar3 != -1) {
    rge_read(iVar3,&param_1->mapXSizeValue,4);
    rge_read(iVar3,&param_1->mapYSizeValue,4);
    rge_read(iVar3,&iStack_34,4);
    iVar8 = 0;
    if (0 < iStack_34) {
      do {
        rge_read(iVar3,&iStack_24,0x18);
        TribeInformationAIModule::storeAttackMemory
                  (param_1,uStack_20,uStack_1f,uStack_1e,uStack_1d,uStack_1c,uStack_1b,uStack_1a,
                   CONCAT11(uStack_17,uStack_18),uStack_16,CONCAT22(uStack_12,uStack_14),iStack_10);
        iVar8 = iVar8 + 1;
      } while (iVar8 < iStack_34);
    }
    rge_read(iVar3,&iStack_34,4);
    param_2 = 0;
    if (0 < iStack_34) {
      do {
        rge_read(iVar3,&iStack_24,0x24);
        TribeInformationAIModule::addObjectMemory
                  (param_1,iStack_24,CONCAT11(uStack_1f,uStack_20),CONCAT11(uStack_1d,uStack_1e),
                   uStack_1c,uStack_1b,uStack_1a,uStack_19,CONCAT11(uStack_17,uStack_18),
                   CONCAT22(uStack_12,uStack_14),(uchar)iStack_10,fStack_c,fStack_8,fStack_4,
                   (RGE_Static_Object *)0x0);
        iVar8 = (param_1->importantUnits).numberValue;
        iVar4 = 0;
        iStack_28 = iStack_24;
        if (0 < iVar8) {
          do {
            if ((param_1->importantUnits).maximumSizeValue <= iVar4) break;
            if ((param_1->importantUnits).value[iVar4] == iStack_24) goto LAB_004e149b;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar8);
        }
        if ((param_1->importantUnits).maximumSizeValue + -1 < iVar8) {
          iVar8 = iVar8 + 1;
          piVar5 = (int *)operator_new(iVar8 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->importantUnits).maximumSizeValue) {
              do {
                if (iVar8 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (param_1->importantUnits).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (param_1->importantUnits).maximumSizeValue);
            }
            operator_delete((param_1->importantUnits).value);
            (param_1->importantUnits).value = piVar5;
            (param_1->importantUnits).maximumSizeValue = iVar8;
          }
        }
        (param_1->importantUnits).value[(param_1->importantUnits).numberValue] = iStack_28;
        (param_1->importantUnits).numberValue = (param_1->importantUnits).numberValue + 1;
LAB_004e149b:
        param_2 = param_2 + 1;
      } while (param_2 < iStack_34);
    }
    piVar5 = param_1->maxResources;
    iVar8 = 4;
    do {
      rge_read(iVar3,piVar5,4);
      rge_read(iVar3,piVar5 + -4,4);
      pRVar7 = (ResourceMemory *)operator_new(*piVar5 * 0x14);
      piVar5[-8] = (int)pRVar7;
      rge_read(iVar3,pRVar7,*piVar5 * 0x14);
      piVar5 = piVar5 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    rge_read(iVar3,&iStack_30,4);
    param_2 = 0;
    if (0 < iStack_30) {
      do {
        rge_read(iVar3,&iStack_2c,4);
        iVar8 = (param_1->importantMiscs).numberValue;
        iVar4 = 0;
        iStack_28 = iStack_2c;
        if (0 < iVar8) {
          do {
            if ((param_1->importantMiscs).maximumSizeValue <= iVar4) break;
            if ((param_1->importantMiscs).value[iVar4] == iStack_2c) goto LAB_004e15f1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar8);
        }
        if ((param_1->importantMiscs).maximumSizeValue + -1 < iVar8) {
          iVar8 = iVar8 + 1;
          piVar5 = (int *)operator_new(iVar8 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->importantMiscs).maximumSizeValue) {
              do {
                if (iVar8 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (param_1->importantMiscs).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (param_1->importantMiscs).maximumSizeValue);
            }
            operator_delete((param_1->importantMiscs).value);
            (param_1->importantMiscs).value = piVar5;
            (param_1->importantMiscs).maximumSizeValue = iVar8;
          }
        }
        (param_1->importantMiscs).value[(param_1->importantMiscs).numberValue] = iStack_28;
        (param_1->importantMiscs).numberValue = (param_1->importantMiscs).numberValue + 1;
LAB_004e15f1:
        param_2 = param_2 + 1;
      } while (param_2 < iStack_30);
    }
    rge_read(iVar3,&iStack_30,4);
    param_2 = 0;
    if (0 < iStack_30) {
      do {
        rge_read(iVar3,&iStack_2c,4);
        iVar8 = (param_1->itemsToDefend).numberValue;
        iVar4 = 0;
        iStack_28 = iStack_2c;
        if (0 < iVar8) {
          do {
            if ((param_1->itemsToDefend).maximumSizeValue <= iVar4) break;
            if ((param_1->itemsToDefend).value[iVar4] == iStack_2c) goto LAB_004e16f4;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar8);
        }
        if ((param_1->itemsToDefend).maximumSizeValue + -1 < iVar8) {
          iVar8 = iVar8 + 1;
          piVar5 = (int *)operator_new(iVar8 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->itemsToDefend).maximumSizeValue) {
              do {
                if (iVar8 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (param_1->itemsToDefend).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (param_1->itemsToDefend).maximumSizeValue);
            }
            operator_delete((param_1->itemsToDefend).value);
            (param_1->itemsToDefend).value = piVar5;
            (param_1->itemsToDefend).maximumSizeValue = iVar8;
          }
        }
        (param_1->itemsToDefend).value[(param_1->itemsToDefend).numberValue] = iStack_28;
        (param_1->itemsToDefend).numberValue = (param_1->itemsToDefend).numberValue + 1;
LAB_004e16f4:
        param_2 = param_2 + 1;
      } while (param_2 < iStack_30);
    }
    rge_close(iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e171c
// Address: 004e171c
// XREFS: None
void __thiscall FUN_004e171c(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x204) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004e172d
// Address: 004e172d
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004e172d(TribeInformationAIModule *param_1,int param_2,uint *param_3)
{
  byte bVar1;
  ObjectMemory *pOVar2;
  uint *puVar3;
  uchar uVar4;
  RGE_Static_Object *this;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iStack_18;
  int iStack_14;
  
  iVar8 = param_2;
  this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_2);
  if (iVar8 != 0) {
    uVar4 = RGE_Static_Object::currentZone(this);
    param_2 = CONCAT31(param_2._1_3_,uVar4);
    iVar9 = 0;
    iVar8 = 0;
    iStack_18 = -1;
    iStack_14 = 0;
    if (0 < param_1->maxImportantObjectMemory) {
      do {
        piVar5 = (int *)((int)&param_1->importantObjectMemory->id + iVar9);
        if (((*piVar5 != -1) &&
            ((ushort)*(byte *)((int)piVar5 + 0xb) != *(ushort *)(param_1->md->_padding_ + 0x4a))) &&
           (*(char *)((int)piVar5 + 0xb) != '\0')) {
          iVar6 = TribeInformationAIModule::tileUncovered
                            (param_1,(uint)*(byte *)(piVar5 + 2),(uint)*(byte *)((int)piVar5 + 9));
          if (iVar6 != 1) {
            uVar4 = RGE_Static_Object::lookupZone
                              (this,(uint)(&param_1->importantObjectMemory->x)[iVar9],
                               (uint)(&param_1->importantObjectMemory->y)[iVar9]);
            if (uVar4 == (uchar)param_2) {
              pOVar2 = param_1->importantObjectMemory;
              RGE_Static_Object::distance_to_position
                        (this,(float)(&pOVar2->x)[iVar9],(float)(&pOVar2->y)[iVar9],
                         (float)(&pOVar2->z)[iVar9]);
              iVar6 = __ftol();
              if ((iVar8 == 0) || (iVar6 < iStack_18)) {
                iVar8 = (int)&param_1->importantObjectMemory->id + iVar9;
                iStack_18 = iVar6;
              }
            }
          }
        }
        iStack_14 = iStack_14 + 1;
        iVar9 = iVar9 + 0x24;
      } while (iStack_14 < param_1->maxImportantObjectMemory);
    }
    puVar3 = param_3;
    if (iVar8 != 0) {
      *param_3 = (uint)*(byte *)(iVar8 + 8);
      bVar1 = *(byte *)(iVar8 + 9);
      param_3[1] = (uint)bVar1;
      uVar7 = __ftol();
      iVar8 = (**(code **)(this->_padding_ + 0x198))
                        (*puVar3,(uint)bVar1,uVar7,this->master_obj->los - _DAT_00575564,0xffffffff,
                         &param_2,1,0xffffffff,0xffffffff);
      if (iVar8 == 0) {
        InfluenceMap::setValue(&param_1->pathMap,*puVar3,puVar3[1],'\x01');
        return 0;
      }
      InfluenceMap::setValue(&param_1->pathMap,*puVar3,puVar3[1],'\0');
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e1923
// Address: 004e1923
// XREFS: None
int __thiscall FUN_004e1923(int param_1,uint param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_4;
  
  iVar4 = 0;
  iVar3 = param_5 * param_5;
  param_5 = 0;
  uStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    do {
      if (param_2 == 0xffffffff) {
LAB_004e1974:
        iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x18))
                          (*(undefined1 *)(*(int *)(param_1 + 0x114) + 0xb + iVar4));
        if (iVar1 != 0) {
LAB_004e199a:
          iVar1 = *(int *)(param_1 + 0x114) + iVar4;
          iVar2 = (uint)*(byte *)(iVar1 + 8) - param_3;
          iVar1 = (uint)*(byte *)(iVar1 + 9) - param_4;
          if (iVar2 * iVar2 + iVar1 * iVar1 <= iVar3) {
            param_5 = param_5 + 1;
          }
        }
      }
      else if (*(byte *)(*(int *)(param_1 + 0x114) + 0xb + iVar4) == param_2) {
        if (param_2 == 0xffffffff) goto LAB_004e1974;
        goto LAB_004e199a;
      }
      uStack_4 = uStack_4 + 1;
      iVar4 = iVar4 + 0x24;
    } while (uStack_4 < *(int *)(param_1 + 0x110));
  }
  return param_5;
}

// --------------------------------------------------

// Function: FUN_004e19f5
// Address: 004e19f5
// XREFS: None
undefined4 __thiscall FUN_004e19f5(int param_1,undefined4 param_2,int param_3,uint param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  param_3 = param_3 * param_3;
  iVar1 = __ftol();
  iVar2 = __ftol();
  param_2 = 0;
  if (*(int *)(param_1 + 0x1fc) < 1) {
    return 0;
  }
  piVar4 = *(int **)(param_1 + 0x200);
  do {
    if (((*piVar4 != -1) && (*(char *)((int)piVar4 + 9) != '\0')) &&
       (*(byte *)((int)piVar4 + 10) == param_4)) {
      iVar6 = (uint)*(byte *)((int)piVar4 + 6) - iVar2;
      iVar3 = (uint)*(byte *)((int)piVar4 + 5) - iVar1;
      iVar3 = iVar3 * iVar3;
      if (((iVar6 * iVar6 + iVar3 <= param_3) ||
          (iVar5 = ((uint)*(byte *)(piVar4 + 2) - iVar2) * ((uint)*(byte *)(piVar4 + 2) - iVar2),
          iVar3 + iVar5 <= param_3)) ||
         ((iVar3 = (uint)*(byte *)((int)piVar4 + 7) - iVar1, iVar3 = iVar3 * iVar3,
          iVar5 + iVar3 <= param_3 || (iVar6 * iVar6 + iVar3 <= param_3)))) {
        return 1;
      }
    }
    piVar4 = piVar4 + 6;
    param_2 = param_2 + 1;
    if (*(int *)(param_1 + 0x1fc) <= param_2) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004e1ae9
// Address: 004e1ae9
// XREFS: None
undefined4 __thiscall FUN_004e1ae9(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = param_3 * param_3;
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar6 = 0;
  param_3 = 0;
  if (*(int *)(param_1 + 0x110) < 1) {
    return 0;
  }
  do {
    iVar3 = *(int *)(param_1 + 0x114) + iVar6;
    if (*(short *)(iVar3 + 4) == 0x6d) {
      iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x18))
                        (*(undefined1 *)(iVar3 + 0xb));
      if ((iVar3 != 0) &&
         (iVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x114) + iVar6 + 8) - iVar1,
         iVar4 = (uint)*(byte *)(*(int *)(param_1 + 0x114) + 9 + iVar6) - iVar2,
         iVar3 * iVar3 + iVar4 * iVar4 <= iVar5)) {
        return 1;
      }
    }
    param_3 = param_3 + 1;
    iVar6 = iVar6 + 0x24;
    if (*(int *)(param_1 + 0x110) <= param_3) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004e1bc1
// Address: 004e1bc1
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_004e1bc1(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_c;
  
  iVar7 = param_3 * param_3;
  iVar2 = __ftol();
  iVar3 = __ftol();
  param_3 = -1;
  param_2 = -1;
  iVar8 = 0;
  iStack_c = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    do {
      pRVar4 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0x100),
                          *(int *)(*(int *)(param_1 + 0x114) + iVar8));
      if (((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->object_state < 3)) &&
         (pRVar4->hp != _DAT_00575580)) {
        iVar6 = *(int *)(param_1 + 0x114) + iVar8;
        iVar5 = (int)*(short *)(iVar6 + 4);
        if ((((iVar5 == param_4) || (iVar5 == param_5)) ||
            ((iVar5 == param_6 || (iVar5 == param_7)))) &&
           (iVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x18))
                              (*(undefined1 *)(iVar6 + 0xb)), iVar5 != 0)) {
          piVar1 = (int *)(*(int *)(param_1 + 0x114) + iVar8);
          iVar5 = (uint)*(byte *)(*(int *)(param_1 + 0x114) + 8 + iVar8) - iVar2;
          iVar6 = (uint)*(byte *)((int)piVar1 + 9) - iVar3;
          iVar5 = iVar5 * iVar5 + iVar6 * iVar6;
          if ((iVar5 <= iVar7) && ((iVar5 < param_2 || (param_3 == -1)))) {
            param_3 = *piVar1;
            param_2 = iVar5;
          }
        }
      }
      iStack_c = iStack_c + 1;
      iVar8 = iVar8 + 0x24;
    } while (iStack_c < *(int *)(param_1 + 0x110));
  }
  return param_3;
}

// --------------------------------------------------

// Function: FUN_004e1d06
// Address: 004e1d06
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
bool __thiscall
FUN_004e1d06(TribeInformationAIModule *param_1,int param_2,int param_3,int *param_4,int param_5,
            int param_6,int param_7,uint param_8,int param_9)
{
  RGE_Visible_Map *this;
  bool bVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  ObjectMemory *pOVar5;
  RGE_Static_Object *this_00;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iStack_6c;
  int iStack_60;
  XYPoint XStack_40;
  XYPoint XStack_38;
  XYPoint XStack_30;
  XYPoint XStack_28;
  XYPoint XStack_20;
  XYPoint XStack_18;
  int iStack_10;
  int iStack_c;
  undefined1 auStack_8 [8];
  
  pOVar5 = TribeInformationAIModule::objectMemory(param_1,param_7);
  if (pOVar5 == (ObjectMemory *)0x0) {
    return false;
  }
  this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_9);
  if (this_00 == (RGE_Static_Object *)0x0) {
    return false;
  }
  iVar6 = TribeInformationAIModule::isBoat(param_1,this_00);
  if ((iVar6 == 1) && (param_5 == 0)) {
    iVar6 = 1;
    iVar15 = 0x16;
  }
  else {
    iVar6 = 2;
    iVar15 = 0;
  }
  XStack_28.y = param_3;
  XStack_28.x = param_2;
  XVar2.y = param_3;
  XVar2.x = param_2;
  RGE_Static_Object::findClosestPointInTerrainType(this_00,XVar2,&XStack_28,iVar6,iVar15,4);
  uVar3 = RGE_Static_Object::lookupZone(this_00,XStack_28.x,XStack_28.y);
  iVar15 = TribeInformationAIModule::setupLOSMap
                     (param_1,(uint)pOVar5->owner,(uint)pOVar5->x,(uint)pOVar5->y);
  iVar7 = TribeInformationAIModule::setupAttackMap
                    (param_1,(uint)pOVar5->owner,(uint)pOVar5->x,(uint)pOVar5->y);
  XStack_30.x = pOVar5->x - param_8;
  XStack_30.y = pOVar5->y - param_8;
  TribeInformationAIModule::mapBound(param_1,&XStack_30);
  XStack_38.x = param_8 + pOVar5->x;
  XStack_38.y = param_8 + pOVar5->y;
  TribeInformationAIModule::mapBound(param_1,&XStack_38);
  XStack_18.x = (int)pOVar5->x;
  XStack_18.y = (int)pOVar5->y;
  TribeInformationAIModule::mapBound(param_1,&XStack_18);
  iStack_60 = -1;
  this = *(RGE_Visible_Map **)(param_1->md->_padding_ + 0x38);
  iVar6 = *(int *)(param_1->md->aiPlayer->_padding_ + 0x28);
  if (XStack_30.x <= XStack_38.x) {
    iVar8 = XStack_30.x * 0x18;
    iVar16 = XStack_38.y;
    iVar14 = XStack_30.y;
    iVar17 = XStack_30.x;
    do {
      iVar9 = iVar14;
      if (iVar14 <= iVar16) {
        do {
          bVar13 = *(byte *)(*(int *)(*(int *)(iVar6 + 0x8d8c) + iVar14 * 4) + 5 + iVar8) & 0x1f;
          RGE_Visible_Map::get_visible(this,iVar17,iVar14);
          if (param_5 == 1) {
            if (bVar13 == 2) goto LAB_004e1f44;
          }
          else if (param_6 == 1) {
            if ((bVar13 != 1) && (bVar13 != 0x16)) {
LAB_004e1f44:
              uVar4 = RGE_Static_Object::lookupZone(this_00,iVar17,iVar14);
              if (uVar4 == uVar3) {
                if (param_5 == 1) {
                  XStack_20.x = iVar17 + -2;
                  XStack_20.y = iVar14 + -2;
                  TribeInformationAIModule::mapBound(param_1,&XStack_20);
                  XStack_40.x = iVar17 + 2;
                  XStack_40.y = iVar14 + 2;
                  TribeInformationAIModule::mapBound(param_1,&XStack_40);
                  bVar1 = true;
                  param_2 = XStack_20.x;
                  if (XStack_20.x <= XStack_40.x) {
                    iStack_6c = XStack_20.x * 0x18;
                    do {
                      if (!bVar1) goto LAB_004e218d;
                      iVar16 = XStack_20.y;
                      if (XStack_20.y <= XStack_40.y) {
                        do {
                          if (!bVar1) break;
                          bVar13 = *(byte *)(*(int *)(*(int *)(iVar6 + 0x8d8c) + iVar16 * 4) + 5 +
                                            iStack_6c) & 0x1f;
                          if (((bVar13 != 1) && (bVar13 != 0x16)) &&
                             (iVar9 = (**(code **)(this_00->_padding_ + 0x114))
                                                ((float)param_2,(float)iVar16,1), iVar9 == 0)) {
                            bVar1 = false;
                          }
                          iVar16 = iVar16 + 1;
                        } while (iVar16 <= XStack_40.y);
                      }
                      param_2 = param_2 + 1;
                      iStack_6c = iStack_6c + 0x18;
                    } while (param_2 <= XStack_40.x);
                  }
                  if (!bVar1) goto LAB_004e218d;
                }
                iVar10 = __ftol();
                iVar16 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x1b3f);
                iStack_10 = iVar17;
                iStack_c = iVar14;
                iVar9 = (**(code **)(this_00->_padding_ + 0x1b0))
                                  (&iStack_10,&XStack_18,0x3f800000,auStack_8,1);
                if (iVar15 < 1) {
                  iVar11 = 0;
                }
                else {
                  iVar11 = InfluenceMap::lookupValue(&losMap,iVar17,iVar14);
                  iVar11 = -((int)(iVar11 * param_8) / iVar15);
                }
                if (iVar7 < 1) {
                  iVar12 = 0;
                }
                else {
                  iVar12 = InfluenceMap::lookupValue(&attackMap,iVar17,iVar14);
                  iVar12 = -((int)(iVar12 * param_8) / iVar7);
                }
                iVar10 = iVar12 + iVar11 + (~-(uint)(iVar9 != 1) & param_8) +
                         iVar16 % (int)(param_8 * 3) + iVar10;
                if ((iStack_60 == -1) || (iStack_60 < iVar10)) {
                  *param_4 = iVar17;
                  param_4[1] = iVar14;
                  iStack_60 = iVar10;
                }
              }
            }
          }
          else if (((param_6 != 0) || (bVar13 == 1)) || (bVar13 == 0x16)) goto LAB_004e1f44;
LAB_004e218d:
          iVar14 = iVar14 + 1;
          iVar16 = XStack_38.y;
          iVar9 = XStack_30.y;
        } while (iVar14 <= XStack_38.y);
      }
      iVar17 = iVar17 + 1;
      iVar8 = iVar8 + 0x18;
      iVar14 = iVar9;
    } while (iVar17 <= XStack_38.x);
  }
  return iStack_60 != -1;
}

// --------------------------------------------------

// Function: FUN_004e21d3
// Address: 004e21d3
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e21d3(int param_1,uint param_2,int param_3,int param_4)
{
  uchar uVar1;
  int *piVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  InfluenceMap::initialize(&losMap,'\0');
  InfluenceMap::setReferencePoint(&losMap,param_3,param_4);
  param_3 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    param_4 = 0;
    do {
      piVar2 = (int *)(param_4 + *(int *)(param_1 + 0x114));
      if ((*(byte *)((int)piVar2 + 0xb) == param_2) &&
         (pRVar3 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),*piVar2)
         , pRVar3 != (RGE_Static_Object *)0x0)) {
        iVar4 = __ftol();
        iVar5 = __ftol();
        iVar6 = __ftol();
        fVar7 = (float10)(**(code **)(pRVar3->_padding_ + 0x108))();
        uVar1 = '\x05';
        if (fVar7 <= (float10)_DAT_00575580) {
          uVar1 = '\x01';
        }
        InfluenceMap::incrementValue
                  (&losMap,iVar5 - iVar4,iVar6 - iVar4,iVar4 + iVar5,iVar4 + iVar6,uVar1);
      }
      param_3 = param_3 + 1;
      param_4 = param_4 + 0x24;
    } while (param_3 < *(int *)(param_1 + 0x110));
  }
  InfluenceMap::maxValue(&losMap);
  return;
}

// --------------------------------------------------

// Function: FUN_004e22ed
// Address: 004e22ed
// XREFS: None
void __thiscall FUN_004e22ed(int param_1,uint param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  InfluenceMap::initialize(&attackMap,'\0');
  InfluenceMap::setReferencePoint(&attackMap,param_3,param_4);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x1fc)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_1 + 0x200) + iVar3;
      if ((*(byte *)(*(int *)(param_1 + 0x200) + 10 + iVar3) == param_2) &&
         ((ushort)*(byte *)(iVar1 + 9) ==
          *(ushort *)(*(int *)(*(int *)(param_1 + 0x100) + 0xf0) + 0x4a))) {
        InfluenceMap::incrementValue
                  (&attackMap,(uint)*(byte *)(iVar1 + 5),(uint)*(byte *)(iVar1 + 6),
                   (uint)*(byte *)(iVar1 + 7),(uint)*(byte *)(iVar1 + 8),'\x01');
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x18;
    } while (iVar2 < *(int *)(param_1 + 0x1fc));
  }
  InfluenceMap::maxValue(&attackMap);
  return;
}

// --------------------------------------------------

// Function: FUN_004e2395
// Address: 004e2395
// XREFS: None
void __thiscall FUN_004e2395(int param_1,int param_2,undefined4 param_3)
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  
  param_2 = param_2 * 4;
  pvVar2 = operator_new(*(int *)(*(int *)(param_1 + 0x4cc) + param_2) * 4 + 4);
  iVar3 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x4cc) + param_2)) {
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
           *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x4c8) + param_2) + -4 + iVar3 * 4);
    } while (iVar3 < *(int *)(*(int *)(param_1 + 0x4cc) + param_2));
  }
  *(undefined4 *)((int)pvVar2 + iVar3 * 4) = param_3;
  pvVar1 = *(void **)(*(int *)(param_1 + 0x4c8) + param_2);
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
  }
  *(void **)(*(int *)(param_1 + 0x4c8) + param_2) = pvVar2;
  *(int *)(*(int *)(param_1 + 0x4cc) + param_2) = *(int *)(*(int *)(param_1 + 0x4cc) + param_2) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004e2431
// Address: 004e2431
// XREFS: None
undefined4 __thiscall FUN_004e2431(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x4cc) + param_2 * 4);
  if (iVar1 < 1) {
    return 0;
  }
  piVar3 = *(int **)(*(int *)(param_1 + 0x4c8) + param_2 * 4);
  do {
    if (*piVar3 == param_3) {
      return 1;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < iVar1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e2489
// Address: 004e2489
// XREFS: None
undefined4 __thiscall FUN_004e2489(TribeInformationAIModule *param_1,RGE_Static_Object *param_2)
{
  short sVar1;
  uchar uVar2;
  ResourceMemory *pRVar3;
  uchar *puVar4;
  ResourceMemory *pRVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  int iStack_c;
  int iStack_4;
  
  pRVar9 = param_2;
  sVar1 = param_2->master_obj->object_group;
  if (sVar1 == 0xf) {
    uVar7 = 1;
  }
  else if (sVar1 == 8) {
    uVar7 = 2;
  }
  else {
    uVar7 = (sVar1 != 0x20) - 1 & 3;
  }
  iStack_c = param_1->maxResources[uVar7];
  if ((param_1->numResources[uVar7] == iStack_c) ||
     (param_1->resources[uVar7] == (ResourceMemory *)0x0)) {
    if (iStack_c == 0) {
      iStack_c = 100;
    }
    else {
      iStack_c = iStack_c * 2;
    }
    pRVar3 = (ResourceMemory *)operator_new(iStack_c * 0x14);
    if (pRVar3 == (ResourceMemory *)0x0) {
      return 0;
    }
    pRVar5 = param_1->resources[uVar7];
    iVar8 = 0;
    if (pRVar5 != (ResourceMemory *)0x0) {
      iVar6 = 0;
      puVar4 = &pRVar3->y;
      do {
        pRVar9 = param_2;
        if (param_1->maxResources[uVar7] <= iVar8) break;
        iVar8 = iVar8 + 1;
        ((ResourceMemory *)(puVar4 + -5))->id = *(int *)((int)&pRVar5->id + iVar6);
        puVar4[-1] = (&param_1->resources[uVar7]->x)[iVar6];
        *puVar4 = (&param_1->resources[uVar7]->y)[iVar6];
        puVar4[1] = (&param_1->resources[uVar7]->gatherAttempts)[iVar6];
        *(int *)(puVar4 + 3) = *(int *)((int)&param_1->resources[uVar7]->gatherValue + iVar6);
        puVar4[7] = (&param_1->resources[uVar7]->valid)[iVar6];
        puVar4[8] = (&param_1->resources[uVar7]->gone)[iVar6];
        puVar4[9] = (&param_1->resources[uVar7]->dropDistance)[iVar6];
        puVar4[10] = (&param_1->resources[uVar7]->resourceType)[iVar6];
        *(int *)(puVar4 + 0xb) = *(int *)((int)&param_1->resources[uVar7]->dropsiteID + iVar6);
        pRVar5 = param_1->resources[uVar7];
        iVar6 = iVar6 + 0x14;
        puVar4 = puVar4 + 0x14;
      } while (pRVar5 != (ResourceMemory *)0x0);
    }
    if (iVar8 < iStack_c) {
      iVar6 = iStack_c - iVar8;
      puVar4 = &pRVar3[iVar8].y;
      do {
        ((ResourceMemory *)(puVar4 + -5))->id = -1;
        puVar4[-1] = '\0';
        *puVar4 = '\0';
        puVar4[1] = '\0';
        *(int *)(puVar4 + 3) = 0xff;
        puVar4[7] = '\0';
        puVar4[8] = '\0';
        puVar4[9] = 0xff;
        puVar4[10] = 0xff;
        *(int *)(puVar4 + 0xb) = -1;
        puVar4 = puVar4 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (param_1->resources[uVar7] != (ResourceMemory *)0x0) {
      operator_delete(param_1->resources[uVar7]);
    }
    param_1->resources[uVar7] = pRVar3;
    param_1->maxResources[uVar7] = iStack_c;
  }
  iVar8 = 0;
  if (0 < param_1->maxResources[uVar7]) {
    pRVar3 = param_1->resources[uVar7];
    do {
      if (pRVar3->id == pRVar9->id) {
        param_2 = (RGE_Static_Object *)0xffffffff;
        TribeInformationAIModule::findClosestDropsite(param_1,pRVar9,1,(int *)&param_2);
        iVar6 = __ftol();
        param_1->resources[uVar7][iVar8].gatherValue = iVar6;
        param_1->resources[uVar7][iVar8].dropsiteID = (int)param_2;
        sVar1 = pRVar9->master_obj->object_group;
        if (sVar1 == 0xf) {
          iVar6 = __ftol();
          if ((param_1->closestDropsiteValue[1] <= iVar6) &&
             (param_1->closestDropsiteValue[1] != -1)) {
            return 1;
          }
          param_1->closestDropsiteValue[1] = iVar6;
          param_1->closestDropsiteResourceID[1] = param_1->resources[uVar7][iVar8].id;
          return 1;
        }
        if (sVar1 == 0x20) {
          iVar6 = __ftol();
          if ((param_1->closestDropsiteValue[3] <= iVar6) &&
             (param_1->closestDropsiteValue[3] != -1)) {
            return 1;
          }
          param_1->closestDropsiteValue[3] = iVar6;
          param_1->closestDropsiteResourceID[3] = param_1->resources[uVar7][iVar8].id;
          return 1;
        }
        if (sVar1 == 8) {
          iVar6 = __ftol();
          if ((param_1->closestDropsiteValue[2] <= iVar6) &&
             (param_1->closestDropsiteValue[2] != -1)) {
            return 1;
          }
          param_1->closestDropsiteValue[2] = iVar6;
          param_1->closestDropsiteResourceID[2] = param_1->resources[uVar7][iVar8].id;
          return 1;
        }
        if (sVar1 != 7) {
          return 1;
        }
        iVar6 = __ftol();
        if ((param_1->closestDropsiteValue[0] <= iVar6) && (param_1->closestDropsiteValue[0] != -1))
{
          return 1;
        }
        param_1->closestDropsiteValue[0] = iVar6;
        param_1->closestDropsiteResourceID[0] = param_1->resources[uVar7][iVar8].id;
        return 1;
      }
      iVar8 = iVar8 + 1;
      pRVar3 = pRVar3 + 1;
    } while (iVar8 < param_1->maxResources[uVar7]);
  }
  param_1->resources[uVar7][param_1->numResources[uVar7]].id = pRVar9->id;
  uVar2 = __ftol();
  param_1->resources[uVar7][param_1->numResources[uVar7]].x = uVar2;
  uVar2 = __ftol();
  param_1->resources[uVar7][param_1->numResources[uVar7]].y = uVar2;
  param_1->resources[uVar7][param_1->numResources[uVar7]].gatherAttempts = '\0';
  param_1->resources[uVar7][param_1->numResources[uVar7]].valid = '\0';
  param_1->resources[uVar7][param_1->numResources[uVar7]].gone = '\0';
  param_1->resources[uVar7][param_1->numResources[uVar7]].resourceType = (uchar)uVar7;
  iStack_4 = -1;
  TribeInformationAIModule::findClosestDropsite(param_1,pRVar9,1,&iStack_4);
  uVar2 = __ftol();
  param_1->resources[uVar7][param_1->numResources[uVar7]].dropDistance = uVar2;
  param_1->resources[uVar7][param_1->numResources[uVar7]].dropsiteID = iStack_4;
  iVar8 = __ftol();
  param_1->resources[uVar7][param_1->numResources[uVar7]].gatherValue = iVar8;
  param_1->numResources[uVar7] = param_1->numResources[uVar7] + 1;
  sVar1 = pRVar9->master_obj->object_group;
  if (sVar1 == 0xf) {
    iVar8 = __ftol();
    if ((iVar8 < param_1->closestDropsiteValue[1]) || (param_1->closestDropsiteValue[1] == -1)) {
      param_1->closestDropsiteValue[1] = iVar8;
      param_1->closestDropsiteResourceID[1] = pRVar9->id;
      return 1;
    }
  }
  else if (sVar1 == 0x20) {
    iVar8 = __ftol();
    if ((iVar8 < param_1->closestDropsiteValue[3]) || (param_1->closestDropsiteValue[3] == -1)) {
      param_1->closestDropsiteValue[3] = iVar8;
      param_1->closestDropsiteResourceID[3] = pRVar9->id;
      return 1;
    }
  }
  else if (sVar1 == 8) {
    iVar8 = __ftol();
    if ((iVar8 < param_1->closestDropsiteValue[2]) || (param_1->closestDropsiteValue[2] == -1)) {
      param_1->closestDropsiteValue[2] = iVar8;
      param_1->closestDropsiteResourceID[2] = pRVar9->id;
      return 1;
    }
  }
  else if (sVar1 == 7) {
    iVar8 = __ftol();
    if ((iVar8 < param_1->closestDropsiteValue[0]) || (param_1->closestDropsiteValue[0] == -1)) {
      param_1->closestDropsiteValue[0] = iVar8;
      param_1->closestDropsiteResourceID[0] = pRVar9->id;
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e2b9c
// Address: 004e2b9c
// XREFS: None
RGE_Static_Object * __thiscall FUN_004e2b9c(int param_1,RGE_Static_Object *param_2)
{
  short sVar1;
  float fVar2;
  float fVar3;
  RGE_Static_Object *pRVar4;
  uchar uVar5;
  uchar uVar6;
  void *pvVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  int iVar10;
  int iVar11;
  RGE_Static_Object *pRStack_c;
  float fStack_4;
  
  iVar11 = 0;
  pRStack_c = (RGE_Static_Object *)0x0;
  fStack_4 = 1000.0;
  uVar5 = RGE_Static_Object::currentZone(param_2);
  if (0 < *(int *)(param_1 + 0x194)) {
    do {
      if (*(int *)(param_1 + 0x19c) + -1 < iVar11) {
        pvVar7 = operator_new(iVar11 * 4 + 4);
        if (pvVar7 != (void *)0x0) {
          iVar8 = 0;
          if (0 < *(int *)(param_1 + 0x19c)) {
            do {
              if (iVar11 + 1 <= iVar8) break;
              iVar8 = iVar8 + 1;
              *(undefined4 *)((int)pvVar7 + iVar8 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 400) + -4 + iVar8 * 4);
            } while (iVar8 < *(int *)(param_1 + 0x19c));
          }
          operator_delete(*(void **)(param_1 + 400));
          *(void **)(param_1 + 400) = pvVar7;
          *(int *)(param_1 + 0x19c) = iVar11 + 1;
        }
      }
      pRVar9 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0x100),
                          *(int *)(*(int *)(param_1 + 400) + iVar11 * 4));
      pRVar4 = pRStack_c;
      fVar2 = fStack_4;
      if (pRVar9 != (RGE_Static_Object *)0x0) {
        iVar8 = __ftol();
        iVar10 = __ftol();
        uVar6 = RGE_Static_Object::lookupZone(param_2,iVar10,iVar8);
        if (((uVar6 == uVar5) &&
            (((sVar1 = pRVar9->master_obj->id, sVar1 == 0x6d ||
              ((sVar1 == 0x67 && (param_2->attribute_type_held != 0x10)))) ||
             ((sVar1 == 0x44 && (param_2->attribute_type_held == 0x10)))))) &&
           ((fVar3 = pRVar9->world_x - param_2->world_x, fVar2 = pRVar9->world_y - param_2->world_y,
            fVar2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3), pRVar4 = pRVar9,
            pRStack_c != (RGE_Static_Object *)0x0 && (fStack_4 <= fVar2)))) {
          pRVar4 = pRStack_c;
          fVar2 = fStack_4;
        }
      }
      fStack_4 = fVar2;
      pRStack_c = pRVar4;
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(param_1 + 0x194));
  }
  return pRStack_c;
}

// --------------------------------------------------

// Function: FUN_004e2d04
// Address: 004e2d04
// XREFS: None
void __fastcall FUN_004e2d04(TribeInformationAIModule *param_1)
{
  short sVar1;
  uchar uVar2;
  RGE_Static_Object *pRVar3;
  undefined4 uVar4;
  int iVar5;
  ResourceMemory **ppRVar6;
  int iVar7;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iStack_4 = 4;
  ppRVar6 = param_1->resources;
  do {
    iVar7 = 0;
    ppRVar6[0x1c] = (ResourceMemory *)0xffffffff;
    ppRVar6[0x20] = (ResourceMemory *)0xffffffff;
    iStack_8 = 0;
    if (0 < (int)ppRVar6[4]) {
      do {
        pRVar3 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)param_1->md,
                            *(int *)((int)&(*ppRVar6)->id + iVar7));
        if (pRVar3 != (RGE_Static_Object *)0x0) {
          iStack_c = -1;
          TribeInformationAIModule::findClosestDropsite(param_1,pRVar3,1,&iStack_c);
          uVar4 = __ftol();
          *(undefined4 *)((int)&(*ppRVar6)->gatherValue + iVar7) = uVar4;
          uVar2 = __ftol();
          (&(*ppRVar6)->dropDistance)[iVar7] = uVar2;
          *(int *)((int)&(*ppRVar6)->dropsiteID + iVar7) = iStack_c;
          sVar1 = pRVar3->master_obj->object_group;
          if (sVar1 == 0xf) {
            iVar5 = __ftol();
            if ((iVar5 < param_1->closestDropsiteValue[1]) ||
               (param_1->closestDropsiteValue[1] == -1)) {
              param_1->closestDropsiteValue[1] = iVar5;
              param_1->closestDropsiteResourceID[1] = pRVar3->id;
            }
          }
          else if (sVar1 == 0x20) {
            iVar5 = __ftol();
            if ((iVar5 < param_1->closestDropsiteValue[3]) ||
               (param_1->closestDropsiteValue[3] == -1)) {
              param_1->closestDropsiteValue[3] = iVar5;
              param_1->closestDropsiteResourceID[3] = pRVar3->id;
            }
          }
          else if (sVar1 == 8) {
            iVar5 = __ftol();
            if ((iVar5 < param_1->closestDropsiteValue[2]) ||
               (param_1->closestDropsiteValue[2] == -1)) {
              param_1->closestDropsiteValue[2] = iVar5;
              param_1->closestDropsiteResourceID[2] = pRVar3->id;
            }
          }
          else if (sVar1 == 7) {
            iVar5 = __ftol();
            if ((iVar5 < param_1->closestDropsiteValue[0]) ||
               (param_1->closestDropsiteValue[0] == -1)) {
              param_1->closestDropsiteValue[0] = iVar5;
              param_1->closestDropsiteResourceID[0] = pRVar3->id;
            }
          }
        }
        iStack_8 = iStack_8 + 1;
        iVar7 = iVar7 + 0x14;
      } while (iStack_8 < (int)ppRVar6[4]);
    }
    ppRVar6 = ppRVar6 + 1;
    iStack_4 = iStack_4 + -1;
  } while (iStack_4 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_004e2e8f
// Address: 004e2e8f
// XREFS: None
void __thiscall FUN_004e2e8f(TribeInformationAIModule *param_1,int param_2)
{
  short sVar1;
  int iVar2;
  uchar uVar3;
  int *piVar4;
  RGE_Static_Object *pRVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iStack_4;
  
  iVar2 = param_2;
  iVar8 = 0;
  param_1->closestDropsiteValue[param_2] = -1;
  param_1->closestDropsiteResourceID[param_2] = -1;
  iStack_4 = 0;
  if (0 < param_1->numResources[param_2]) {
    do {
      piVar4 = (int *)((int)&param_1->resources[iVar2]->id + iVar8);
      if ((*(char *)((int)piVar4 + 0xd) != '\x01') &&
         (pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,*piVar4),
         pRVar5 != (RGE_Static_Object *)0x0)) {
        param_2 = -1;
        TribeInformationAIModule::findClosestDropsite(param_1,pRVar5,1,&param_2);
        uVar6 = __ftol();
        *(undefined4 *)((int)&param_1->resources[iVar2]->gatherValue + iVar8) = uVar6;
        uVar3 = __ftol();
        (&param_1->resources[iVar2]->dropDistance)[iVar8] = uVar3;
        *(int *)((int)&param_1->resources[iVar2]->dropsiteID + iVar8) = param_2;
        sVar1 = pRVar5->master_obj->object_group;
        if (sVar1 == 0xf) {
          iVar7 = __ftol();
          if ((iVar7 < param_1->closestDropsiteValue[1]) || (param_1->closestDropsiteValue[1] == -1)
             ) {
            param_1->closestDropsiteValue[1] = iVar7;
            param_1->closestDropsiteResourceID[1] = pRVar5->id;
          }
        }
        else if (sVar1 == 0x20) {
          iVar7 = __ftol();
          if ((iVar7 < param_1->closestDropsiteValue[3]) || (param_1->closestDropsiteValue[3] == -1)
             ) {
            param_1->closestDropsiteValue[3] = iVar7;
            param_1->closestDropsiteResourceID[3] = pRVar5->id;
          }
        }
        else if (sVar1 == 8) {
          iVar7 = __ftol();
          if ((iVar7 < param_1->closestDropsiteValue[2]) || (param_1->closestDropsiteValue[2] == -1)
             ) {
            param_1->closestDropsiteValue[2] = iVar7;
            param_1->closestDropsiteResourceID[2] = pRVar5->id;
          }
        }
        else if (sVar1 == 7) {
          iVar7 = __ftol();
          if ((iVar7 < param_1->closestDropsiteValue[0]) || (param_1->closestDropsiteValue[0] == -1)
             ) {
            param_1->closestDropsiteValue[0] = iVar7;
            param_1->closestDropsiteResourceID[0] = pRVar5->id;
          }
        }
      }
      iStack_4 = iStack_4 + 1;
      iVar8 = iVar8 + 0x14;
    } while (iStack_4 < param_1->numResources[iVar2]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e301d
// Address: 004e301d
// XREFS: None
undefined4 __thiscall FUN_004e301d(int param_1,int param_2,int param_3,undefined1 param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x4e0 + param_2 * 4);
  if (iVar1 < 1) {
    return 0;
  }
  piVar2 = *(int **)(param_1 + 0x4d0 + param_2 * 4);
  piVar4 = piVar2;
  do {
    if (*piVar4 == param_3) {
      *(undefined1 *)(piVar2 + iVar3 * 5 + 3) = param_4;
      return 1;
    }
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 5;
  } while (iVar3 < iVar1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e306f
// Address: 004e306f
// XREFS: None
int __fastcall FUN_004e306f(int param_1)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x194)) {
    do {
      if (*(int *)(param_1 + 0x19c) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x19c)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 400) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x19c));
          }
          operator_delete(*(void **)(param_1 + 400));
          *(void **)(param_1 + 400) = pvVar1;
          *(int *)(param_1 + 0x19c) = iVar4 + 1;
        }
      }
      pRVar3 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0x100),
                          *(int *)(*(int *)(param_1 + 400) + iVar4 * 4));
      if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->master_obj->id == 0x67)) {
        iStack_4 = iStack_4 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x194));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_004e3131
// Address: 004e3131
// XREFS: None
int __fastcall FUN_004e3131(int param_1)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x194)) {
    do {
      if (*(int *)(param_1 + 0x19c) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x19c)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 400) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x19c));
          }
          operator_delete(*(void **)(param_1 + 400));
          *(void **)(param_1 + 400) = pvVar1;
          *(int *)(param_1 + 0x19c) = iVar4 + 1;
        }
      }
      pRVar3 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0x100),
                          *(int *)(*(int *)(param_1 + 400) + iVar4 * 4));
      if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->master_obj->id == 0x44)) {
        iStack_4 = iStack_4 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x194));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_004e3201
// Address: 004e3201
// XREFS: None
void __fastcall FUN_004e3201(int param_1)
{
  int *piVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x4e0)) {
    iVar4 = 0;
    do {
      piVar1 = (int *)(*(int *)(param_1 + 0x4d0) + iVar4);
      if (((*(char *)((int)piVar1 + 0xd) != '\x01') &&
          (pRVar2 = MainDecisionAIModule::object
                              (*(MainDecisionAIModule **)(param_1 + 0x100),*piVar1),
          pRVar2 != (RGE_Static_Object *)0x0)) && (pRVar2->master_obj->id == 0x3b)) {
        __ftol();
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar3 < *(int *)(param_1 + 0x4e0));
  }
  __ftol();
  return;
}

// --------------------------------------------------

// Function: FUN_004e32ba
// Address: 004e32ba
// XREFS: None
void __thiscall FUN_004e32ba(int param_1,int param_2)
{
  int *piVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iStack_4;
  
  iVar3 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x4e0 + param_2 * 4)) {
    do {
      piVar1 = (int *)(*(int *)(param_1 + 0x4d0 + param_2 * 4) + iVar3);
      if (((*(char *)((int)piVar1 + 0xd) != '\x01') &&
          (pRVar2 = MainDecisionAIModule::object
                              (*(MainDecisionAIModule **)(param_1 + 0x100),*piVar1),
          pRVar2 != (RGE_Static_Object *)0x0)) &&
         ((param_2 != 0 || (pRVar2->master_obj->id != 0x3b)))) {
        __ftol();
      }
      iStack_4 = iStack_4 + 1;
      iVar3 = iVar3 + 0x14;
    } while (iStack_4 < *(int *)(param_1 + 0x4e0 + param_2 * 4));
  }
  __ftol();
  return;
}

// --------------------------------------------------

// Function: FUN_004e3385
// Address: 004e3385
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004e3385(int param_1,float param_2,int param_3,int param_4)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  RGE_Static_Object *this;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float fVar6;
  float fStack_c;
  
  fStack_c = 0.0;
  pRVar1 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),(int)param_2);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x110)) {
      iVar4 = 0;
      do {
        iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x18))
                          (*(undefined1 *)(*(int *)(param_1 + 0x114) + 0xb + iVar4));
        if ((((iVar2 != 0) &&
             (this = MainDecisionAIModule::object
                               (*(MainDecisionAIModule **)(param_1 + 0x100),
                                *(int *)(*(int *)(param_1 + 0x114) + iVar4)),
             this != (RGE_Static_Object *)0x0)) && (this->object_state < 3)) &&
           (fVar6 = RGE_Static_Object::distance_to_position
                              (this,(float)param_3,(float)param_4,this->world_z),
           fVar6 <= this->master_obj->los)) {
          (**(code **)(pRVar1->_padding_ + 0x104))(this);
          fVar5 = (float10)(**(code **)(this->_padding_ + 0x100))();
          if ((fVar5 != (float10)_DAT_00575580) && (param_2 != _DAT_00575580)) {
            fStack_c = param_2 / (float)fVar5 + fStack_c;
          }
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x24;
      } while (iVar3 < *(int *)(param_1 + 0x110));
    }
    return (float10)fStack_c;
  }
  return (float10)_DAT_00575580;
}

// --------------------------------------------------

// Function: FUN_004e34b4
// Address: 004e34b4
// XREFS: None
undefined4 __thiscall FUN_004e34b4(int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  undefined4 uVar2;
  
  pRVar1 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_2);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0xffffffff;
  }
  uVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x58))
                    ((int)pRVar1->master_obj->id);
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004e34fb
// Address: 004e34fb
// XREFS: None
undefined4 __thiscall FUN_004e34fb(int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  undefined4 uVar2;
  
  pRVar1 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_2);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0xffffffff;
  }
  uVar2 = (**(code **)(pRVar1->owner->_padding_ + 0x58))((int)pRVar1->master_obj->id);
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004e352d
// Address: 004e352d
// XREFS: None
undefined4 __thiscall FUN_004e352d(int param_1,uint param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  RGE_Static_Object *this;
  int iVar2;
  float10 fVar3;
  float fVar4;
  int iStack_4;
  
  iVar2 = 0;
  iStack_4 = 0;
  if (*(int *)(param_1 + 0x110) < 1) {
    return 0;
  }
  do {
    if (param_2 == 0xffffffff) {
LAB_004e356b:
      iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x18))
                        (*(undefined1 *)(*(int *)(param_1 + 0x114) + 0xb + iVar2));
      if (iVar1 != 0) {
LAB_004e358d:
        this = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0x100),
                          *(int *)(*(int *)(param_1 + 0x114) + iVar2));
        if ((this != (RGE_Static_Object *)0x0) && (this->object_state < 3)) {
          fVar4 = RGE_Static_Object::distance_to_position
                            (this,(float)param_3,(float)param_4,this->world_z);
          fVar3 = (float10)(**(code **)(this->_padding_ + 0x10c))();
          if ((param_5 == 0) && (fVar4 < this->master_obj->los)) {
            fVar3 = (float10)this->master_obj->los;
          }
          if ((float10)fVar4 <= fVar3) {
            return 1;
          }
        }
      }
    }
    else if (*(byte *)(*(int *)(param_1 + 0x114) + 0xb + iVar2) == param_2) {
      if (param_2 == 0xffffffff) goto LAB_004e356b;
      goto LAB_004e358d;
    }
    iStack_4 = iStack_4 + 1;
    iVar2 = iVar2 + 0x24;
    if (*(int *)(param_1 + 0x110) <= iStack_4) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004e363f
// Address: 004e363f
// XREFS: None
int __thiscall FUN_004e363f(int param_1,uint param_2)
{
  float fVar1;
  float fVar2;
  uchar uVar3;
  short sVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  RGE_Action *pRVar7;
  uint uVar8;
  int iVar9;
  int iStack_18;
  uint uStack_14;
  float fStack_10;
  float fStack_8;
  int iStack_4;
  
  iVar9 = 0;
  uStack_14 = 0xffffffff;
  fStack_10 = 0.0;
  fStack_8 = 0.0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    iStack_18 = 0;
    do {
      iVar5 = *(int *)(param_1 + 0x114) + iStack_18;
      if (*(short *)(iVar5 + 4) == 0x114) {
        if (param_2 == 0xffffffff) {
LAB_004e36a2:
          iVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x18))
                            (*(undefined1 *)(iVar5 + 0xb));
          if (iVar5 != 0) {
LAB_004e36c3:
            pRVar6 = MainDecisionAIModule::object
                               (*(MainDecisionAIModule **)(param_1 + 0x100),
                                *(int *)(*(int *)(param_1 + 0x114) + iStack_18));
            if (((pRVar6 != (RGE_Static_Object *)0x0) && (pRVar6->object_state < 3)) &&
               (uVar3 = RGE_Action_List::have_action((RGE_Action_List *)pRVar6[2].unitAIValue),
               uVar3 != '\0')) {
              pRVar7 = RGE_Action_List::get_action((RGE_Action_List *)pRVar6[2].unitAIValue);
              sVar4 = (**(code **)(pRVar7->_padding_ + 0x18))();
              if (sVar4 == 0x78) {
                pRVar7 = RGE_Action_List::get_action((RGE_Action_List *)pRVar6[2].unitAIValue);
                uVar8 = (uint)pRVar7->state;
                pRVar7 = RGE_Action_List::get_action((RGE_Action_List *)pRVar6[2].unitAIValue);
                fVar2 = pRVar6->hp;
                fVar1 = pRVar7->timer;
                if (iVar9 == 0) {
                  iVar9 = *(int *)(param_1 + 0x114) + iStack_18;
                  uStack_14 = uVar8;
                  fStack_10 = fVar1;
                  fStack_8 = fVar2;
                }
                else if ((uStack_14 != 6) || (uVar8 != 2)) {
                  if ((uStack_14 == 2) && (uVar8 == 6)) {
                    iVar9 = *(int *)(param_1 + 0x114) + iStack_18;
                    uStack_14 = uVar8;
                    fStack_10 = fVar1;
                    fStack_8 = fVar2;
                  }
                  else if (uStack_14 == uVar8) {
                    if ((uStack_14 != 2) || (fVar2 <= fStack_8)) {
                      if ((uStack_14 == uVar8) && ((uStack_14 == 6 && (fVar1 < fStack_10)))) {
                        iVar9 = *(int *)(param_1 + 0x114) + iStack_18;
                        uStack_14 = uVar8;
                        fStack_10 = fVar1;
                        fStack_8 = fVar2;
                      }
                    }
                    else {
                      iVar9 = *(int *)(param_1 + 0x114) + iStack_18;
                      uStack_14 = uVar8;
                      fStack_10 = fVar1;
                      fStack_8 = fVar2;
                    }
                  }
                }
              }
            }
          }
        }
        else if (*(byte *)(iVar5 + 0xb) == param_2) {
          if (param_2 == 0xffffffff) goto LAB_004e36a2;
          goto LAB_004e36c3;
        }
      }
      iStack_4 = iStack_4 + 1;
      iStack_18 = iStack_18 + 0x24;
    } while (iStack_4 < *(int *)(param_1 + 0x110));
  }
  return iVar9;
}

// --------------------------------------------------

// Function: FUN_004e3839
// Address: 004e3839
// XREFS: None
int __thiscall FUN_004e3839(TribeInformationAIModule *param_1,uint param_2)
{
  short sVar1;
  ObjectMemory *pOVar2;
  RGE_Static_Object *this;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  this = MainDecisionAIModule::object
                   ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  iVar6 = 0;
  iStack_c = -1;
  iStack_10 = 0;
  iStack_8 = 0;
  if (0 < param_1->maxImportantObjectMemory) {
    do {
      pOVar2 = param_1->importantObjectMemory;
      sVar1 = *(short *)((int)&pOVar2->type + iVar6);
      if ((sVar1 == 0x9e) || (sVar1 == 0xa3)) {
        if (param_2 == 0xffffffff) {
LAB_004e38c3:
          iVar3 = (**(code **)(*(int *)param_1->md->_padding_ + 0x18))((&pOVar2->owner)[iVar6]);
          if (iVar3 != 0) {
LAB_004e38e6:
            pRVar4 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1->md,
                                *(int *)((int)&param_1->importantObjectMemory->id + iVar6));
            if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->object_state < 3)) {
              iVar3 = TribeInformationAIModule::numberUnitsWithinXTiles
                                (param_1,param_2,(uint)(&param_1->importantObjectMemory->x)[iVar6],
                                 (uint)(&param_1->importantObjectMemory->y)[iVar6],5);
              if (this != (RGE_Static_Object *)0x0) {
                pOVar2 = param_1->importantObjectMemory;
                RGE_Static_Object::distance_to_position
                          (this,(float)(&pOVar2->x)[iVar6],(float)(&pOVar2->y)[iVar6],
                           (float)(&pOVar2->z)[iVar6]);
                iVar5 = __ftol();
                iVar3 = iVar5 * iVar3;
              }
              if ((iStack_10 == 0) || (iVar3 < iStack_c)) {
                iStack_10 = (int)&param_1->importantObjectMemory->id + iVar6;
                iStack_c = iVar3;
              }
            }
          }
        }
        else if ((&pOVar2->owner)[iVar6] == param_2) {
          if (param_2 == 0xffffffff) goto LAB_004e38c3;
          goto LAB_004e38e6;
        }
      }
      iStack_8 = iStack_8 + 1;
      iVar6 = iVar6 + 0x24;
    } while (iStack_8 < param_1->maxImportantObjectMemory);
  }
  return iStack_10;
}

// --------------------------------------------------

// Function: FUN_004e39c9
// Address: 004e39c9
// XREFS: None
int __thiscall FUN_004e39c9(TribeInformationAIModule *param_1,uint param_2)
{
  RGE_Visible_Map *this;
  ObjectMemory *pOVar1;
  uchar uVar2;
  RGE_Static_Object *this_00;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  this_00 = MainDecisionAIModule::object
                      ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  iVar6 = 0;
  iStack_14 = -1;
  iStack_18 = 0;
  this = *(RGE_Visible_Map **)(param_1->md->_padding_ + 0x38);
  iStack_10 = 0;
  if (0 < param_1->maxImportantObjectMemory) {
    do {
      pOVar1 = param_1->importantObjectMemory;
      if (*(short *)((int)&pOVar1->type + iVar6) == 0x9f) {
        if (param_2 == 0xffffffff) {
LAB_004e3a5e:
          iVar3 = (**(code **)(*(int *)param_1->md->_padding_ + 0x18))((&pOVar1->owner)[iVar6]);
          if (iVar3 != 0) {
LAB_004e3a7d:
            pRVar4 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1->md,
                                *(int *)((int)&param_1->importantObjectMemory->id + iVar6));
            if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->object_state < 3)) {
              iVar3 = __ftol();
              iVar5 = __ftol();
              uVar2 = RGE_Visible_Map::get_visible(this,iVar3,iVar5);
              if (uVar2 != '\0') {
                uVar2 = __ftol();
                (&param_1->importantObjectMemory->x)[iVar6] = uVar2;
                uVar2 = __ftol();
                (&param_1->importantObjectMemory->y)[iVar6] = uVar2;
                uVar2 = __ftol();
                (&param_1->importantObjectMemory->z)[iVar6] = uVar2;
                iVar3 = TribeInformationAIModule::numberUnitsWithinXTiles
                                  (param_1,param_2,iVar3,iVar5,5);
                if (this_00 != (RGE_Static_Object *)0x0) {
                  RGE_Static_Object::distance_to_object(this_00,pRVar4);
                  iVar5 = __ftol();
                  iVar3 = iVar5 * iVar3;
                }
                if ((iStack_18 == 0) || (iVar3 < iStack_14)) {
                  iStack_18 = (int)&param_1->importantObjectMemory->id + iVar6;
                  iStack_14 = iVar3;
                }
              }
            }
          }
        }
        else if ((&pOVar1->owner)[iVar6] == param_2) {
          if (param_2 == 0xffffffff) goto LAB_004e3a5e;
          goto LAB_004e3a7d;
        }
      }
      iStack_10 = iStack_10 + 1;
      iVar6 = iVar6 + 0x24;
    } while (iStack_10 < param_1->maxImportantObjectMemory);
  }
  return iStack_18;
}

// --------------------------------------------------

// Function: FUN_004e3b7c
// Address: 004e3b7c
// XREFS: None
undefined4 __thiscall FUN_004e3b7c(int param_1,int param_2)
{
  int iVar1;
  
  if (param_2 == 2) {
    return 0;
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x100) + 0x104) + 0x48))(0x67,0);
  if ((iVar1 == 0) && (*(int *)(param_1 + 0x544) != -1)) {
    return 1;
  }
  if (param_2 == 1) {
    if (*(int *)(param_1 + 0x544) != -1) {
      iVar1 = TribeTacticalAIModule::strategicNumber
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0xa4);
      if (iVar1 < *(int *)(param_1 + 0x544)) {
        return 1;
      }
    }
    if (*(int *)(param_1 + 0x54c) != -1) {
      iVar1 = TribeTacticalAIModule::strategicNumber
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0xa6);
      if (iVar1 < *(int *)(param_1 + 0x54c)) {
        return 3;
      }
    }
    if ((*(int *)(param_1 + 0x540) != -1) && (0xf < *(int *)(param_1 + 0x540))) {
      return 2;
    }
    if (*(int *)(param_1 + 0x548) != -1) {
      iVar1 = TribeTacticalAIModule::strategicNumber
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0xa5);
      if (iVar1 < *(int *)(param_1 + 0x548)) {
        return 2;
      }
    }
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004e3c84
// Address: 004e3c84
// XREFS: None
undefined4 __thiscall FUN_004e3c84(int param_1,int *param_2,int param_3,int param_4)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  int iStack_30;
  int iStack_2c;
  int iStack_20;
  int *piStack_1c;
  int iStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00560578;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_2 = 0;
  iStack_2c = 0;
  piStack_1c = (int *)0x0;
  iStack_10 = 0;
  uStack_4 = 0;
  iStack_20 = 0;
  piVar4 = (int *)0x0;
  if (0 < *(int *)(param_1 + 0x4e0 + param_3 * 4)) {
    iStack_30 = 0;
    iVar7 = 0;
    do {
      iVar1 = *(int *)(param_1 + 0x4d0 + param_3 * 4);
      iVar8 = iVar7;
      if ((*(char *)(iStack_30 + 0xd + iVar1) != '\x01') &&
         (pRVar2 = MainDecisionAIModule::object
                             (*(MainDecisionAIModule **)(param_1 + 0x100),
                              *(int *)(iStack_30 + iVar1)), pRVar2 != (RGE_Static_Object *)0x0)) {
        iStack_2c = iStack_2c + 1;
        iVar1 = iStack_30 + *(int *)(param_1 + 0x4d0 + param_3 * 4);
        if ((int)(uint)*(byte *)(iVar1 + 0xe) <= param_4) {
          iVar3 = 0;
          piVar4 = piStack_1c;
          if (0 < iVar7) {
            do {
              if (iStack_10 <= iVar3) break;
              if (*piVar4 == *(int *)(iVar1 + 0x10)) goto LAB_004e3e1c;
              iVar3 = iVar3 + 1;
              piVar4 = piVar4 + 1;
            } while (iVar3 < iVar7);
          }
          *param_2 = *param_2 + 1;
          iVar1 = *(int *)(iStack_30 + 0x10 + *(int *)(param_1 + 0x4d0 + param_3 * 4));
          iVar3 = 0;
          piVar4 = piStack_1c;
          if (0 < iVar7) {
            do {
              if (iStack_10 <= iVar3) break;
              if (*piVar4 == iVar1) goto LAB_004e3e1c;
              iVar3 = iVar3 + 1;
              piVar4 = piVar4 + 1;
            } while (iVar3 < iVar7);
          }
          if (iStack_10 + -1 < iVar7) {
            iVar8 = iVar7 + 1;
            piVar4 = (int *)operator_new(iVar8 * 4);
            if (piVar4 != (int *)0x0) {
              iVar3 = 0;
              if (0 < iStack_10) {
                piVar5 = piVar4;
                do {
                  if (iVar8 <= iVar3) break;
                  iVar3 = iVar3 + 1;
                  *piVar5 = *(int *)(((int)piStack_1c - (int)piVar4) + (int)piVar5);
                  piVar5 = piVar5 + 1;
                } while (iVar3 < iStack_10);
              }
              operator_delete(piStack_1c);
              piStack_1c = piVar4;
              iStack_10 = iVar8;
            }
          }
          iVar8 = iVar7 + 1;
          piStack_1c[iVar7] = iVar1;
        }
      }
LAB_004e3e1c:
      iStack_20 = iStack_20 + 1;
      iStack_30 = iStack_30 + 0x14;
      piVar4 = piStack_1c;
      iVar7 = iVar8;
    } while (iStack_20 < *(int *)(param_1 + 0x4e0 + param_3 * 4));
  }
  uStack_4 = 0xffffffff;
  if (iStack_2c < 1) {
    if (piVar4 != (int *)0x0) {
      operator_delete(piVar4);
    }
    uVar6 = 0;
  }
  else {
    if (piVar4 != (int *)0x0) {
      operator_delete(piVar4);
    }
    uVar6 = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar6;
}

// --------------------------------------------------

// Function: FUN_004e3e8d
// Address: 004e3e8d
// XREFS: None
bool __thiscall FUN_004e3e8d(int param_1,int param_2)
{
  MainDecisionAIModule *this;
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  RGE_Static_Object *this_00;
  RGE_Static_Object *pRVar4;
  int iVar5;
  
  this = *(MainDecisionAIModule **)(param_1 + 0x100);
  iVar3 = __ftol();
  iVar3 = iVar3 + -1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (3 < iVar3) {
    iVar3 = 3;
  }
  if (*(int *)(param_1 + (iVar3 + 0x140 + param_2 * 4) * 4) != 0) {
    this_00 = MainDecisionAIModule::object(this,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
    if ((this_00 != (RGE_Static_Object *)0x0) &&
       (pRVar4 = MainDecisionAIModule::object
                           (*(MainDecisionAIModule **)(param_1 + 0x100),
                            *(int *)(param_1 + 0x550 + param_2 * 4)),
       pRVar4 != (RGE_Static_Object *)0x0)) {
      uVar1 = RGE_Static_Object::currentZone(this_00);
      iVar3 = __ftol();
      iVar5 = __ftol();
      uVar2 = RGE_Static_Object::lookupZone(this_00,iVar5,iVar3);
      if (uVar1 != uVar2) {
        return false;
      }
    }
    iVar3 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),param_2 + 0xa3
                      );
    return iVar3 < *(int *)(param_1 + 0x540 + param_2 * 4);
  }
  return false;
}

// --------------------------------------------------

// Function: FUN_004e3f7e
// Address: 004e3f7e
// XREFS: None
bool __fastcall FUN_004e3f7e(int param_1)
{
  uchar uVar1;
  uchar uVar2;
  RGE_Static_Object *this;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x540) == -1) {
    return false;
  }
  this = MainDecisionAIModule::object
                   (*(MainDecisionAIModule **)(param_1 + 0x100),-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  if (this != (RGE_Static_Object *)0x0) {
    pRVar3 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(param_1 + 0x100),*(int *)(param_1 + 0x550));
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      uVar1 = RGE_Static_Object::currentZone(this);
      iVar4 = __ftol();
      iVar5 = __ftol();
      uVar2 = RGE_Static_Object::lookupZone(this,iVar5,iVar4);
      if (uVar1 != uVar2) {
        return false;
      }
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber
                    ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0xa3);
  return iVar4 < *(int *)(param_1 + 0x540);
}

// --------------------------------------------------

// Function: FUN_004e4036
// Address: 004e4036
// XREFS: None
void __fastcall FUN_004e4036(TribeInformationAIModule *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_c;
  int iStack_8;
  
  iVar1 = *(int *)(*(int *)(param_1->md->_padding_ + 0x3c) + 0x28);
  iStack_18 = 0;
  if (0 < param_1->mapXSizeValue) {
    iStack_14 = 0;
    iStack_20 = 0;
    do {
      iVar5 = param_1->mapYSizeValue;
      iStack_c = 0;
      if (0 < iVar5) {
        iStack_8 = 0;
        do {
          bVar6 = *(byte *)(*(int *)(*(int *)(iVar1 + 0x8d8c) + iStack_8) + 5 + iStack_20) & 0x1f;
          if (param_1->mapXSizeValue != -1) {
            iVar4 = iStack_14 / param_1->mapXSizeValue;
            param_1->quadrantLog[iVar4][iStack_8 / iVar5].numberExploredTiles =
                 param_1->quadrantLog[iVar4][iStack_8 / iVar5].numberExploredTiles + 1;
          }
          InfluenceMap::setValue(&param_1->pathMap,iStack_18,iStack_c,'\0');
          iStack_1c = 0;
          for (puVar2 = *(undefined4 **)
                         (*(int *)(*(int *)(iVar1 + 0x8d8c) + iStack_8) + 0x10 + iStack_20);
              puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
            pRVar3 = (RGE_Static_Object *)*puVar2;
            iVar4 = (int)pRVar3->master_obj->object_group;
            iVar5 = TribeInformationAIModule::importantObject(param_1,iVar4);
            if (iVar5 == 1) {
              TribeInformationAIModule::addImportantObject(param_1,pRVar3,0);
            }
            if (iVar4 == 0xf) {
              iStack_1c = iStack_1c + 1;
            }
          }
          if ((0 < iStack_1c) &&
             ((((bVar6 == 10 || (bVar6 == 0x13)) || (bVar6 == 0xd)) || (bVar6 == 0x14)))) {
            param_1->numberFoundForestTilesValue = param_1->numberFoundForestTilesValue + 1;
          }
          iVar5 = param_1->mapYSizeValue;
          iStack_c = iStack_c + 1;
          iStack_8 = iStack_8 + 4;
        } while (iStack_c < iVar5);
      }
      iStack_18 = iStack_18 + 1;
      iStack_20 = iStack_20 + 0x18;
      iStack_14 = iStack_14 + 4;
    } while (iStack_18 < param_1->mapXSizeValue);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e41bb
// Address: 004e41bb
// XREFS: None
float10 __thiscall FUN_004e41bb(int param_1,TacticalAIGroup *param_2,int *param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  float10 fVar4;
  float fStack_4;
  
  fStack_4 = 0.0;
  iVar3 = 0;
  iVar1 = TacticalAIGroup::numberUnits(param_2);
  if (0 < iVar1) {
    do {
      iVar1 = TacticalAIGroup::unit(param_2,iVar3);
      pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),iVar1);
      if (pRVar2 != (RGE_Static_Object *)0x0) {
        (**(code **)(*param_3 + 0x104))(pRVar2);
        fVar4 = (float10)(**(code **)(pRVar2->_padding_ + 0x100))();
        fStack_4 = (float)((float10)(float)param_2 / fVar4 + (float10)fStack_4);
      }
      iVar3 = iVar3 + 1;
      iVar1 = TacticalAIGroup::numberUnits(param_2);
    } while (iVar3 < iVar1);
  }
  return (float10)fStack_4;
}

// --------------------------------------------------

// Function: FUN_004e4239
// Address: 004e4239
// XREFS: None
float10 __thiscall FUN_004e4239(int param_1,int *param_2,float param_3,int *param_4)
{
  RGE_Static_Object *pRVar1;
  float fVar2;
  float10 fVar3;
  float fStack_4;
  
  fStack_4 = 0.0;
  fVar2 = param_3;
  if (0 < (int)param_3) {
    do {
      pRVar1 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),*param_2);
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        (**(code **)(*param_4 + 0x104))(pRVar1);
        fVar3 = (float10)(**(code **)(pRVar1->_padding_ + 0x100))();
        fStack_4 = (float)((float10)param_3 / fVar3 + (float10)fStack_4);
      }
      param_2 = param_2 + 1;
      fVar2 = (float)((int)fVar2 + -1);
    } while (fVar2 != 0.0);
  }
  return (float10)fStack_4;
}

// --------------------------------------------------

// Function: FUN_004e42aa
// Address: 004e42aa
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004e42aa(TribeInformationAIModule *param_1,TacticalAIGroup *param_2)
{
  float fVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fStack_4;
  
  fStack_4 = 0.0;
  iVar6 = 0;
  iVar2 = TacticalAIGroup::numberUnits(param_2);
  if (0 < iVar2) {
    do {
      iVar2 = TacticalAIGroup::unit(param_2,iVar6);
      pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
      if (pRVar3 != (RGE_Static_Object *)0x0) {
        iVar2 = __ftol();
        iVar4 = __ftol();
        iVar5 = TacticalAIGroup::unit(param_2,iVar6);
        fVar7 = TribeInformationAIModule::damagePerSecond(param_1,iVar5,iVar4,iVar2);
        fVar1 = _DAT_005755c0;
        if (fVar7 != _DAT_00575580) {
          fVar1 = pRVar3->hp / fVar7;
        }
        fStack_4 = fVar1 + fStack_4;
      }
      iVar6 = iVar6 + 1;
      iVar2 = TacticalAIGroup::numberUnits(param_2);
    } while (iVar6 < iVar2);
  }
  return (float10)fStack_4;
}

// --------------------------------------------------

// Function: FUN_004e434e
// Address: 004e434e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004e434e(TribeInformationAIModule *param_1,int *param_2,int param_3)
{
  float fVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fStack_4;
  
  fStack_4 = 0.0;
  if (0 < param_3) {
    do {
      pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,*param_2);
      if (pRVar2 != (RGE_Static_Object *)0x0) {
        iVar3 = __ftol();
        iVar4 = __ftol();
        fVar5 = TribeInformationAIModule::damagePerSecond(param_1,*param_2,iVar4,iVar3);
        fVar1 = _DAT_005755c0;
        if (fVar5 != _DAT_00575580) {
          fVar1 = pRVar2->hp / fVar5;
        }
        fStack_4 = fVar1 + fStack_4;
      }
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return (float10)fStack_4;
}

// --------------------------------------------------

// Function: FUN_004e43df
// Address: 004e43df
// XREFS: None
undefined4 __thiscall FUN_004e43df(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 4)) {
    return *(undefined4 *)(param_1 + 0x550 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004e43fd
// Address: 004e43fd
// XREFS: None
int FUN_004e43fd(void)
{
  int iVar1;
  
  iVar1 = 16000;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = __ftol();
  return 100 - iVar1;
}

// --------------------------------------------------

// Function: FUN_004e4442
// Address: 004e4442
// XREFS: None
int FUN_004e4442(int param_1)
{
  short sVar1;
  short sVar2;
  
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x14);
  sVar2 = *(short *)(*(int *)(param_1 + 8) + 0x10);
  if (sVar1 == 0x12) {
    return 5;
  }
  if (sVar1 == 0x1c) {
    return 3;
  }
  if (sVar1 == 0xd) {
    return 4;
  }
  if (sVar1 == 0xc) {
    return 2;
  }
  if (sVar1 == 0x23) {
    return 7;
  }
  if (sVar2 == 0x49) {
    return 0;
  }
  if (sVar2 == 0x4b) {
    return 1;
  }
  if (((sVar2 != 4) && (sVar2 != 5)) && (sVar2 != 0x27)) {
    if (sVar2 == 0x29) {
      return 10;
    }
    if ((sVar2 != 0x2e) && (sVar2 != 0x19)) {
      return (-(uint)(sVar1 != 0x16) & 0xfffffff7) + 8;
    }
    return 9;
  }
  return 6;
}

// --------------------------------------------------

// Function: FUN_004e44fc
// Address: 004e44fc
// XREFS: None
// [HELPER] s_learn_Default_uh: "learn\Default.uh"
// [HELPER] s_learn__s_uh: "learn\%s.uh"
void __fastcall FUN_004e44fc(int param_1)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char acStack_100 [256];
  
  if (rge_base_game->player_game_info == (RGE_Game_Info *)0x0) {
    uVar4 = 0xffffffff;
    pcVar2 = &s_learn_Default_uh;
    do {
      pcVar6 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar6 + -uVar4;
    pcVar6 = acStack_100;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  else {
    pcVar2 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
    sprintf(acStack_100,s_learn__s_uh,pcVar2);
  }
  iVar3 = rge_open(acStack_100,0x8000);
  if (iVar3 != -1) {
    rge_read(iVar3,(void *)(param_1 + 0xff64),0x2c);
    rge_close(iVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e4595
// Address: 004e4595
// XREFS: None
void __thiscall FUN_004e4595(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(param_1 + 0xff64);
  iVar4 = -1;
  *param_2 = -1;
  iVar1 = 0;
  piVar2 = piVar3;
  do {
    if ((iVar4 == -1) || (iVar4 < *piVar2)) {
      *param_2 = iVar1;
      iVar4 = *piVar2;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0xb);
  iVar4 = -1;
  iVar1 = 0;
  *param_3 = -1;
  do {
    if ((iVar1 != *param_2) && ((iVar4 == -1 || (iVar4 < *piVar3)))) {
      *param_3 = iVar1;
      iVar4 = *piVar3;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar1 < 0xb);
  return;
}

// --------------------------------------------------

// Function: FUN_004e4601
// Address: 004e4601
// XREFS: None
void __thiscall FUN_004e4601(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(param_1 + 0xff64);
  iVar4 = -1;
  *param_2 = 0x7fffffff;
  iVar1 = 0;
  piVar2 = piVar3;
  do {
    if ((iVar4 == -1) || (*piVar2 < iVar4)) {
      *param_2 = iVar1;
      iVar4 = *piVar2;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0xb);
  iVar4 = -1;
  iVar1 = 0;
  *param_3 = 0x7fffffff;
  do {
    if ((iVar1 != *param_2) && ((iVar4 == -1 || (*piVar3 < iVar4)))) {
      *param_3 = iVar1;
      iVar4 = *piVar3;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar1 < 0xb);
  return;
}

// --------------------------------------------------

// Function: FUN_004e4671
// Address: 004e4671
// XREFS: None
undefined4 __thiscall FUN_004e4671(int param_1,int param_2,int param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_4;
  
  iVar2 = TribeTacticalAIModule::strategicNumber
                    ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0xca);
  iVar3 = TribeTacticalAIModule::strategicNumber
                    ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0xca);
  iVar6 = 0;
  uStack_4 = 0;
  if (*(int *)(param_1 + 0x110) < 1) {
    return 1;
  }
  do {
    iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0xf0) + 0x18))
                      (*(undefined1 *)(*(int *)(param_1 + 0x114) + 0xb + iVar6));
    if (iVar4 != 0) {
      iVar4 = *(int *)(param_1 + 0x114) + iVar6;
      sVar1 = *(short *)(iVar4 + 4);
      if (((((sVar1 == 0x6d) || (sVar1 == 0x67)) || (sVar1 == 0x44)) ||
          (((sVar1 == 0x4f || (sVar1 == 199)) || (sVar1 == 0x45)))) &&
         (iVar5 = (uint)*(byte *)(iVar4 + 8) - param_2, iVar4 = (uint)*(byte *)(iVar4 + 9) - param_3
         , iVar5 * iVar5 + iVar4 * iVar4 <= iVar2 * iVar3)) {
        return 0;
      }
    }
    uStack_4 = uStack_4 + 1;
    iVar6 = iVar6 + 0x24;
    if (*(int *)(param_1 + 0x110) <= uStack_4) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004e4784
// Address: 004e4784
// XREFS: None
int __thiscall FUN_004e4784(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x104);
  if (iVar1 == -1) {
    return 0;
  }
  iVar2 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * *(int *)(param_1 + 0x108);
  return (*(int *)(param_1 +
                  ((param_3 * 4) / *(int *)(param_1 + 0x108) + 0x56 + ((param_2 << 2) / iVar1) * 4)
                  * 0xc) * 100) / ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
}

// --------------------------------------------------

// Function: FUN_004e47f9
// Address: 004e47f9
// XREFS: None
TribeMainDecisionAIModule * __thiscall
FUN_004e47f9(TribeMainDecisionAIModule *param_1,void *param_2,int param_3,char *param_4,
            TRIBE_Player *param_5)
{
  TribeInformationAIModule *this;
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560616;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  MainDecisionAIModule::MainDecisionAIModule
            ((MainDecisionAIModule *)param_1,param_2,param_3,(RGE_Player *)param_5);
  uStack_4 = 0;
  TribeBuildAIModule::TribeBuildAIModule(&param_1->buildAI,param_2,param_3);
  uStack_4._0_1_ = 1;
  TribeConstructionAIModule::TribeConstructionAIModule(&param_1->constructionAI,param_2,param_3);
  uStack_4._0_1_ = 2;
  DiplomacyAIModule::DiplomacyAIModule(&param_1->diplomacyAI,param_2,param_3);
  uStack_4._0_1_ = 3;
  EmotionalAIModule::EmotionalAIModule(&param_1->emotionalAI,param_2,param_3);
  this = &param_1->informationAI;
  uStack_4._0_1_ = 4;
  TribeInformationAIModule::TribeInformationAIModule(this,param_2,param_3);
  uStack_4._0_1_ = 5;
  TribeResourceAIModule::TribeResourceAIModule(&param_1->resourceAI,param_2,param_3,4,500,0,1000);
  uStack_4._0_1_ = 6;
  TribeStrategyAIModule::TribeStrategyAIModule(&param_1->strategyAI,param_2,param_3);
  uStack_4._0_1_ = 7;
  TribeTacticalAIModule::TribeTacticalAIModule(&param_1->tacticalAI,param_2,param_3);
  uStack_4._0_1_ = 8;
  TradeAIModule::TradeAIModule(&param_1->tradeAI,param_2,param_3);
  param_1->firstUpdate = 1;
  param_1->veryFirstUpdate = 1;
  uStack_4 = CONCAT31(uStack_4._1_3_,9);
  param_1->aiPlayer = param_5;
  param_1->updateDelay = param_3;
  param_1->lastDiplomacyUpdateTime = 0;
  param_1->lastTacticalUpdateTime = 0;
  param_1->lastTributeChatTime = 0;
  param_1->tributeChatTimeout = 0;
  param_1->waitingOnTribute = 0;
  param_1->tributeExpirationTimeout = 0;
  param_1->tributeAddressed = 0;
  param_1->tributeAmount = 0;
  param_1->decidedInitialDiplomacy = 0;
  param_1->requiredDiplomacyTributeAmount = 0;
  param_1->_padding_ = (int)&TribeMainDecisionAIModule::_vftable_;
  AIModule::setPlayer((AIModule *)param_1,param_3,param_4);
  AIModule::setLogCommonHistory((AIModule *)param_1,(uint)(startLoggingAI != 0));
  TribeBuildAIModule::setMainDecisionAI(&param_1->buildAI,param_1);
  TribeConstructionAIModule::setMainDecisionAI(&param_1->constructionAI,param_1);
  DiplomacyAIModule::setMainDecisionAI(&param_1->diplomacyAI,(MainDecisionAIModule *)param_1);
  EmotionalAIModule::setMainDecisionAI(&param_1->emotionalAI,(MainDecisionAIModule *)param_1);
  TribeInformationAIModule::setMainDecisionAI(this,param_1);
  TribeResourceAIModule::setMainDecisionAI(&param_1->resourceAI,param_1);
  TribeStrategyAIModule::setMainDecisionAI(&param_1->strategyAI,param_1);
  TribeTacticalAIModule::setMainDecisionAI(&param_1->tacticalAI,param_1);
  TradeAIModule::setMainDecisionAI(&param_1->tradeAI,(MainDecisionAIModule *)param_1);
  AIModule::setPlayer((AIModule *)&param_1->buildAI,param_3,param_4);
  AIModule::setPlayer((AIModule *)&param_1->constructionAI,param_3,param_4);
  AIModule::setPlayer((AIModule *)&param_1->diplomacyAI,param_3,param_4);
  AIModule::setPlayer((AIModule *)&param_1->emotionalAI,param_3,param_4);
  AIModule::setPlayer((AIModule *)this,param_3,param_4);
  AIModule::setPlayer((AIModule *)&param_1->resourceAI,param_3,param_4);
  AIModule::setPlayer((AIModule *)&param_1->strategyAI,param_3,param_4);
  AIModule::setPlayer((AIModule *)&param_1->tacticalAI,param_3,param_4);
  AIModule::setPlayer((AIModule *)&param_1->tradeAI,param_3,param_4);
  TribeInformationAIModule::addResourceType(this,0,0x30);
  TribeInformationAIModule::addResourceType(this,0,0x7e);
  TribeInformationAIModule::addResourceType(this,0,0x3b);
  TribeInformationAIModule::addResourceType(this,0,0x41);
  TribeInformationAIModule::addResourceType(this,0,0x34);
  TribeInformationAIModule::addResourceType(this,0,0x35);
  TribeInformationAIModule::addResourceType(this,0,0x104);
  TribeInformationAIModule::addResourceType(this,0,0x107);
  TribeInformationAIModule::addResourceType(this,0,0x32);
  iVar1 = 0x6f;
  do {
    TribeInformationAIModule::addResourceType(this,1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x73);
  iVar1 = 0x86;
  do {
    TribeInformationAIModule::addResourceType(this,1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x9a);
  iVar1 = 0xc0;
  do {
    TribeInformationAIModule::addResourceType(this,1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc6);
  TribeInformationAIModule::addResourceType(this,2,0x66);
  TribeInformationAIModule::addResourceType(this,3,0x42);
  iVar1 = 0x150;
  do {
    TribeInformationAIModule::addResourceType(this,3,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x154);
  EmotionalAIModule::setOverallState(&param_1->emotionalAI,0);
  piVar2 = param_1->tributeGiven;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e4b5e
// Address: 004e4b5e
// XREFS: None
TribeMainDecisionAIModule * __thiscall FUN_004e4b5e(TribeMainDecisionAIModule *param_1,byte param_2)
{
  TribeMainDecisionAIModule::~TribeMainDecisionAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e4b7e
// Address: 004e4b7e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TribeMainDecisionAIModule * __thiscall
FUN_004e4b7e(TribeMainDecisionAIModule *param_1,int param_2,char *param_3,TRIBE_Player *param_4,
            int param_5)
{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005606a6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  MainDecisionAIModule::MainDecisionAIModule
            ((MainDecisionAIModule *)param_1,param_2,(RGE_Player *)param_4,param_5);
  uStack_4 = 0;
  TribeBuildAIModule::TribeBuildAIModule(&param_1->buildAI,param_2,param_5);
  uStack_4._0_1_ = 1;
  TribeConstructionAIModule::TribeConstructionAIModule(&param_1->constructionAI,param_2,param_5);
  uStack_4._0_1_ = 2;
  DiplomacyAIModule::DiplomacyAIModule(&param_1->diplomacyAI,param_2,param_5);
  uStack_4._0_1_ = 3;
  EmotionalAIModule::EmotionalAIModule(&param_1->emotionalAI,param_2,param_5);
  uStack_4._0_1_ = 4;
  TribeInformationAIModule::TribeInformationAIModule(&param_1->informationAI,param_2,param_5);
  uStack_4._0_1_ = 5;
  TribeResourceAIModule::TribeResourceAIModule(&param_1->resourceAI,param_2,param_5);
  uStack_4._0_1_ = 6;
  TribeStrategyAIModule::TribeStrategyAIModule(&param_1->strategyAI,param_2,param_5);
  uStack_4._0_1_ = 7;
  TribeTacticalAIModule::TribeTacticalAIModule(&param_1->tacticalAI,param_2,param_5);
  uStack_4._0_1_ = 8;
  TradeAIModule::TradeAIModule(&param_1->tradeAI,param_2,param_5);
  param_1->aiPlayer = param_4;
  uStack_4 = CONCAT31(uStack_4._1_3_,9);
  param_1->firstUpdate = 0;
  param_1->veryFirstUpdate = 0;
  param_1->updateDelay = param_2;
  param_1->lastDiplomacyUpdateTime = 0;
  param_1->lastTacticalUpdateTime = 0;
  param_1->decidedInitialDiplomacy = 0;
  param_1->requiredDiplomacyTributeAmount = 0;
  param_1->_padding_ = (int)&TribeMainDecisionAIModule::_vftable_;
  AIModule::setPlayer((AIModule *)param_1,param_2,param_3);
  AIModule::setLogCommonHistory((AIModule *)param_1,(uint)(startLoggingAI != 0));
  TribeBuildAIModule::setMainDecisionAI(&param_1->buildAI,param_1);
  TribeConstructionAIModule::setMainDecisionAI(&param_1->constructionAI,param_1);
  DiplomacyAIModule::setMainDecisionAI(&param_1->diplomacyAI,(MainDecisionAIModule *)param_1);
  EmotionalAIModule::setMainDecisionAI(&param_1->emotionalAI,(MainDecisionAIModule *)param_1);
  TribeInformationAIModule::setMainDecisionAI(&param_1->informationAI,param_1);
  TribeResourceAIModule::setMainDecisionAI(&param_1->resourceAI,param_1);
  TribeStrategyAIModule::setMainDecisionAI(&param_1->strategyAI,param_1);
  TribeTacticalAIModule::setMainDecisionAI(&param_1->tacticalAI,param_1);
  TradeAIModule::setMainDecisionAI(&param_1->tradeAI,(MainDecisionAIModule *)param_1);
  AIModule::setPlayer((AIModule *)&param_1->buildAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->constructionAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->diplomacyAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->emotionalAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->informationAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->resourceAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->strategyAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->tacticalAI,param_2,param_3);
  AIModule::setPlayer((AIModule *)&param_1->tradeAI,param_2,param_3);
  rge_read(param_5,&param_1->updateDelay,4);
  rge_read(param_5,&param_1->lastDiplomacyUpdateTime,4);
  rge_read(param_5,&param_1->lastTacticalUpdateTime,4);
  if (_DAT_00575618 <= save_game_version) {
    rge_read(param_5,&param_1->lastTributeChatTime,4);
    rge_read(param_5,&param_1->tributeChatTimeout,4);
    rge_read(param_5,&param_1->waitingOnTribute,4);
    rge_read(param_5,&param_1->tributeExpirationTimeout,4);
    rge_read(param_5,&param_1->tributeAddressed,4);
    rge_read(param_5,&param_1->tributeAmount,4);
  }
  if (save_game_version < _DAT_0057561c) {
    piVar2 = param_1->tributeGiven;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  else {
    rge_read(param_5,&param_1->decidedInitialDiplomacy,4);
    rge_read(param_5,&param_1->requiredDiplomacyTributeAmount,4);
    rge_read(param_5,param_1->tributeGiven,0x24);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e4f95
// Address: 004e4f95
// XREFS: None
void __thiscall FUN_004e4f95(MainDecisionAIModule *param_1,int param_2)
{
  (**(code **)(param_1[1]._padding_ + 8))(param_2);
  (**(code **)(param_1[6]._padding_ + 8))(param_2);
  (**(code **)(param_1[9]._padding_ + 8))(param_2);
  (**(code **)(param_1[0xb]._padding_ + 8))(param_2);
  (**(code **)(param_1[0xc]._padding_ + 8))(param_2);
  (**(code **)(param_1[0x109]._padding_ + 8))(param_2);
  (**(code **)(param_1[0x10a]._padding_ + 8))(param_2);
  (**(code **)(param_1[0x110]._padding_ + 8))(param_2);
  (**(code **)(param_1[0x11f].objects.desiredNumberValue + 8))(param_2);
  MainDecisionAIModule::setLogHistory(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004e5045
// Address: 004e5045
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taimdmd_cp: "C:\msdev\work\age1_x1\taimdmd.cpp"
// [HELPER] s_Initial_Diplomacy_Settings_: "Initial Diplomacy Settings:"
// [HELPER] s___Player___d__Dislike__d__Like__: "  Player #%d: Dislike=%d, Like=%d, Ambivalence=%d."
undefined4 __fastcall FUN_004e5045(TribeMainDecisionAIModule *param_1)
{
  DiplomacyAIModule *this;
  TribeTacticalAIModule *pTVar1;
  AIModule *this_00;
  ulong uVar2;
  RGE_Player *pRVar3;
  RGE_Player *this_01;
  uchar uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  AIModule *this_02;
  RGE_Player *this_03;
  RGE_Player *this_04;
  undefined4 unaff_EBP;
  int iVar12;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar13;
  undefined1 *puVar14;
  undefined4 uVar15;
  int iStack_14c;
  int iStack_148;
  int *piStack_144;
  int iStack_140;
  int iStack_138;
  int aiStack_134 [7];
  undefined1 auStack_118 [8];
  undefined1 auStack_110 [256];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056074b;
  *unaff_FS_OFFSET = &uStack_c;
  this_00 = *(AIModule **)(param_1->_padding_ + 0x3c);
  if (((this_00->idValue).name[0x11] == '\0') && (param_1->firstUpdate == 1)) {
    param_1->firstUpdate = 0;
    AIModule::logCommonHistory(this_00,(char *)param_1,s_Initial_Diplomacy_Settings_);
    iVar12 = 1;
    if (1 < *(short *)(*(int *)(param_1->_padding_ + 0x3c) + 0x3c)) {
      this = &param_1->diplomacyAI;
      do {
        iVar5 = DiplomacyAIModule::stance(this,iVar12,1);
        iVar6 = DiplomacyAIModule::stance(this,iVar12,2);
        iVar7 = DiplomacyAIModule::stance(this,iVar12,0);
        AIModule::logCommonHistory
                  (this_02,(char *)param_1,s___Player___d__Dislike__d__Like__,iVar12,iVar7,iVar6,
                   iVar5);
        iVar12 = iVar12 + 1;
      } while (iVar12 < *(short *)(*(int *)(param_1->_padding_ + 0x3c) + 0x3c));
    }
    (**(code **)((param_1->strategyAI)._padding_ + 0x30))(0);
    TribeBuildAIModule::initialize(&param_1->buildAI);
    TribeInformationAIModule::initialize(&param_1->informationAI);
    TribeMainDecisionAIModule::setTributeChat(param_1);
    pTVar1 = &param_1->tacticalAI;
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
    if ((iVar12 == 1) && (iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7d), iVar12 == 0)
       ) {
      param_1->waitingOnTribute = 1;
      param_1->tributeAmount = 0;
    }
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8a);
    if (iVar12 != 0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))(0,(float)iVar12);
    }
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8b);
    if (iVar12 != 0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))(3,(float)iVar12);
    }
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8c);
    if (iVar12 != 0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))(2,(float)iVar12);
    }
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x8d);
    if (iVar12 != 0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))(1,(float)iVar12);
    }
  }
  iVar12 = param_1->updateDelay + 1;
  param_1->updateDelay = iVar12;
  if (0x13 < iVar12) {
    (**(code **)((param_1->strategyAI)._padding_ + 0x30))(0);
    param_1->updateDelay = 0;
  }
  (**(code **)((param_1->informationAI)._padding_ + 0x30))(0);
  iVar12 = param_1->_padding_;
  if (0x3b < (*(int *)(*(int *)(iVar12 + 0x3c) + 4) - param_1->lastDiplomacyUpdateTime) / 1000) {
    (**(code **)((param_1->diplomacyAI)._padding_ + 0x30))(0);
    iVar12 = param_1->_padding_;
    param_1->lastDiplomacyUpdateTime = *(ulong *)(*(int *)(iVar12 + 0x3c) + 4);
  }
  uVar2 = param_1->lastTributeChatTime;
  pTVar1 = &param_1->tacticalAI;
  iVar12 = *(int *)(*(int *)(iVar12 + 0x3c) + 4);
  iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
  if ((iVar5 < 1) || (param_1->tributeAddressed != 0)) goto LAB_004e56fa;
  if (((iVar12 - uVar2) / 1000 < param_1->tributeChatTimeout) ||
     (iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7d), iVar12 < 1)) {
    if (param_1->waitingOnTribute != 1) goto LAB_004e56fa;
    iVar12 = param_1->tributeExpirationTimeout - *(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0xc)
    ;
    param_1->tributeExpirationTimeout = iVar12;
    if (iVar12 < 1) {
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x82);
      if (iVar12 == 1) {
        iVar6 = 100;
        iVar5 = 0;
        iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&param_1->diplomacyAI,iVar12,iVar5,iVar6);
        iVar6 = 0;
        iVar5 = 2;
        iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&param_1->diplomacyAI,iVar12,iVar5,iVar6);
        uVar15 = 3;
        iVar12 = param_1->aiPlayer->_padding_;
        iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        (**(code **)(iVar12 + 0x28))(iVar5,uVar15);
        (**(code **)(rge_base_game->_padding_ + 0x20))(0x901,auStack_118,0x100);
        puVar14 = auStack_110;
        pcVar13 = (char *)0x0;
        iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        RGE_Player::sendChatMessage
                  ((RGE_Player *)param_1->_padding_,param_1->_padding_,iVar12,pcVar13,puVar14);
        param_1->waitingOnTribute = 0;
        uVar2 = *(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4);
        param_1->tributeAddressed = 1;
        param_1->lastTributeChatTime = uVar2;
        goto LAB_004e56fa;
      }
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
      if (iVar12 != 1) goto LAB_004e56fa;
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x900,auStack_110,0x100);
LAB_004e5646:
      puVar14 = auStack_110;
      pcVar13 = (char *)0x0;
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
      RGE_Player::sendChatMessage(this_04,param_1->_padding_,iVar12,pcVar13,puVar14);
      param_1->waitingOnTribute = 0;
      param_1->lastTributeChatTime = *(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4);
    }
    else {
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
      if (param_1->tributeAmount < iVar12) goto LAB_004e56fa;
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
      if (iVar12 == 1) {
        iVar6 = 0;
        iVar5 = 0;
        iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&param_1->diplomacyAI,iVar12,iVar5,iVar6);
        iVar6 = 100;
        iVar5 = 2;
        iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        DiplomacyAIModule::setStance(&param_1->diplomacyAI,iVar12,iVar5,iVar6);
        uVar15 = 0;
        iVar12 = param_1->aiPlayer->_padding_;
        iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
        (**(code **)(iVar12 + 0x28))(iVar5,uVar15);
        (**(code **)(rge_base_game->_padding_ + 0x20))(0x8ff,auStack_118,0x100);
        goto LAB_004e5646;
      }
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x82);
      if (iVar12 != 1) goto LAB_004e56fa;
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x8fe,auStack_110,0x100);
      puVar14 = auStack_110;
      pcVar13 = (char *)0x0;
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
      RGE_Player::sendChatMessage
                ((RGE_Player *)param_1->_padding_,param_1->_padding_,iVar12,pcVar13,puVar14);
      param_1->waitingOnTribute = 0;
      param_1->lastTributeChatTime = *(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4);
    }
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x84);
    param_1->tributeAddressed = (uint)(iVar12 == 0);
    goto LAB_004e56fa;
  }
  if (param_1->waitingOnTribute == 0) {
    param_1->waitingOnTribute = 1;
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7f);
    param_1->tributeAmount = 0;
    param_1->tributeExpirationTimeout = iVar12 * 1000;
  }
  param_1->lastTributeChatTime = *(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4);
  iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x82);
  if (iVar12 == 1) {
    if (param_1->tributeAmount < 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x903,auStack_110,0x100);
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
LAB_004e5443:
      puVar14 = auStack_110;
      pcVar13 = (char *)0x0;
      iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
      RGE_Player::sendChatMessage
                ((RGE_Player *)param_1->_padding_,param_1->_padding_,iVar5,pcVar13,puVar14,iVar12);
LAB_004e5461:
      TribeMainDecisionAIModule::setTributeChat(param_1);
      goto LAB_004e56fa;
    }
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x902,auStack_110,0x100);
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
    iVar12 = iVar12 - param_1->tributeAmount;
  }
  else {
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x81);
    if (iVar12 != 1) goto LAB_004e5461;
    if (param_1->tributeAmount < 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x905,auStack_110,0x100);
      iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
      iVar12 = iVar12 - param_1->tributeAmount;
      goto LAB_004e5443;
    }
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x904,auStack_110,0x100);
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x7c);
  }
  puVar14 = auStack_110;
  pcVar13 = (char *)0x0;
  iVar5 = TribeTacticalAIModule::strategicNumber(pTVar1,0x80);
  RGE_Player::sendChatMessage(this_03,param_1->_padding_,iVar5,pcVar13,puVar14,iVar12);
  TribeMainDecisionAIModule::setTributeChat(param_1);
LAB_004e56fa:
  if ((param_1->decidedInitialDiplomacy == 0) &&
     (10000 < *(uint *)(*(int *)(param_1->_padding_ + 0x3c) + 4))) {
    iVar6 = 1;
    param_1->decidedInitialDiplomacy = 1;
    iVar12 = *(int *)(param_1->_padding_ + 0x3c);
    iVar5 = 0;
    iStack_148 = 0;
    iStack_14c = 0;
    if (1 < *(short *)(iVar12 + 0x3c)) {
      do {
        pRVar3 = *(RGE_Player **)(*(int *)(iVar12 + 0x40) + iVar6 * 4);
        iVar7 = RGE_Player::computerPlayer(pRVar3);
        if (iVar7 == 0) {
          iStack_148 = iStack_148 + 1;
        }
        else {
          iVar5 = iVar5 + 1;
          iVar7 = (**(code **)(pRVar3->_padding_ + 0x24))();
          if (iVar7 == 1) {
            aiStack_134[iVar6] = 1;
            iStack_14c = iStack_14c + 1;
          }
          else {
            aiStack_134[iVar6] = 0;
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(short *)(iVar12 + 0x3c));
    }
    if (*(char *)(iVar12 + 0x11d) == -1) {
      if (iVar5 == 1) {
        *(undefined1 *)(iVar12 + 0x11d) = *(undefined1 *)(param_1->_padding_ + 0x4a);
      }
      else {
        iVar6 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x236);
        iVar7 = 1;
        iVar6 = iVar6 % iVar5 + 1;
        if (1 < *(short *)(iVar12 + 0x3c)) {
          do {
            pRVar3 = *(RGE_Player **)(*(int *)(iVar12 + 0x40) + iVar7 * 4);
            iVar8 = RGE_Player::computerPlayer(pRVar3);
            if ((iVar8 == 1) && (iVar6 = iVar6 + -1, iVar6 == 0)) {
              *(char *)(iVar12 + 0x11d) = (char)pRVar3->id;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(short *)(iVar12 + 0x3c));
        }
      }
    }
    if (*(char *)(iVar12 + 0x11d) == *(char *)(param_1->_padding_ + 0x4a)) {
      iVar5 = (iVar5 - iStack_148) / 2;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if (iStack_14c < iVar5) {
        iVar5 = iStack_14c;
      }
      uVar4 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
      if (uVar4 == '\x01') {
        iVar5 = 0;
      }
      if ((iVar5 <= iStack_14c) && (0 < iStack_14c)) {
        iVar7 = 0;
        piStack_144 = (int *)0x0;
        iStack_140 = 0;
        iStack_138 = 0;
        pcStack_8 = (code *)0x0;
        iStack_14c = 1;
        iVar6 = iVar7;
        if (1 < *(short *)(iVar12 + 0x3c)) {
          do {
            pRVar3 = *(RGE_Player **)(*(int *)(iVar12 + 0x40) + iStack_14c * 4);
            iVar8 = RGE_Player::computerPlayer(pRVar3);
            iVar7 = iVar6;
            if ((((iVar8 != 0) && (aiStack_134[iStack_14c] != 0)) &&
                ((ushort)*(byte *)(iVar12 + 0x11d) != pRVar3->id)) && (iVar6 < iVar5)) {
              iVar8 = 0;
              piVar9 = piStack_144;
              if (0 < iVar6) {
                do {
                  if (iStack_138 <= iVar8) break;
                  if (*piVar9 == iStack_14c) goto LAB_004e598c;
                  iVar8 = iVar8 + 1;
                  piVar9 = piVar9 + 1;
                } while (iVar8 < iVar6);
              }
              if (iStack_138 + -1 < iVar6) {
                iVar7 = iVar6 + 1;
                piVar9 = (int *)operator_new(iVar7 * 4);
                if (piVar9 != (int *)0x0) {
                  iVar8 = 0;
                  if (0 < iStack_138) {
                    piVar10 = piVar9;
                    do {
                      if (iVar7 <= iVar8) break;
                      iVar8 = iVar8 + 1;
                      *piVar10 = *(int *)(((int)piStack_144 - (int)piVar9) + (int)piVar10);
                      piVar10 = piVar10 + 1;
                      iVar6 = iStack_140;
                    } while (iVar8 < iStack_138);
                  }
                  operator_delete(piStack_144);
                  piStack_144 = piVar9;
                  iStack_138 = iVar7;
                }
              }
              iVar7 = iVar6 + 1;
              piStack_144[iVar6] = iStack_14c;
              iStack_140 = iVar7;
            }
LAB_004e598c:
            iStack_14c = iStack_14c + 1;
            iVar6 = iVar7;
          } while (iStack_14c < *(short *)(iVar12 + 0x3c));
        }
        iVar5 = 2000;
        iVar6 = RGE_Base_Game::difficulty(rge_base_game);
        switch(iVar6) {
        case 0:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x26e);
          iVar5 = iVar5 % 500 + 0x578;
          break;
        case 1:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x26f);
          iVar5 = iVar5 % 400 + 1000;
          break;
        case 2:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x270);
          iVar5 = iVar5 % 300 + 700;
          break;
        case 3:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x271);
          iVar5 = iVar5 % 200 + 0x1c2;
          break;
        case 4:
          iVar5 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x272);
          iVar5 = iVar5 % 100 + 300;
        }
        iStack_14c = 1;
        if (1 < *(short *)(iVar12 + 0x3c)) {
          do {
            pRVar3 = *(RGE_Player **)(*(int *)(iVar12 + 0x40) + iStack_14c * 4);
            iVar6 = RGE_Player::computerPlayer(pRVar3);
            if ((iVar6 != 0) && (aiStack_134[iStack_14c] != 0)) {
              iVar6 = 0;
              piVar9 = piStack_144;
              if (0 < iVar7) {
                do {
                  if (iStack_138 <= iVar6) break;
                  if (*piVar9 == iStack_14c) {
                    (**(code **)(pRVar3->_padding_ + 0x54))
                              ((int)*(short *)(param_1->_padding_ + 0x4a),7,iVar5,0,0);
                    iVar5 = iVar5 * 2;
                    break;
                  }
                  iVar6 = iVar6 + 1;
                  piVar9 = piVar9 + 1;
                } while (iVar6 < iVar7);
              }
              iVar6 = 1;
              if (1 < *(short *)(iVar12 + 0x3c)) {
                do {
                  if (iStack_14c != iVar6) {
                    this_01 = *(RGE_Player **)(*(int *)(iVar12 + 0x40) + iVar6 * 4);
                    iVar8 = RGE_Player::computerPlayer(this_01);
                    if (iVar8 == 0) {
                      if (0 < iVar7) {
                        iVar8 = 0;
                        piVar9 = piStack_144;
                        do {
                          if (iStack_138 <= iVar8) break;
                          if (*piVar9 == iStack_14c) goto LAB_004e5b47;
                          iVar8 = iVar8 + 1;
                          piVar9 = piVar9 + 1;
                        } while (iVar8 < iVar7);
                      }
                      iVar8 = pRVar3->_padding_;
                      uVar15 = 0;
                    }
                    else {
LAB_004e5b47:
                      iVar8 = RGE_Player::computerPlayer(this_01);
                      if (iVar8 != 1) goto LAB_004e5b6f;
                      iVar8 = pRVar3->_padding_;
                      uVar15 = 2;
                    }
                    (**(code **)(iVar8 + 0x54))
                              ((int)*(short *)(param_1->_padding_ + 0x4a),6,iVar6,uVar15,0);
                  }
LAB_004e5b6f:
                  iVar6 = iVar6 + 1;
                } while (iVar6 < *(short *)(iVar12 + 0x3c));
              }
            }
            iStack_14c = iStack_14c + 1;
          } while (iStack_14c < *(short *)(iVar12 + 0x3c));
        }
        pcStack_8 = (code *)0xffffffff;
        if (piStack_144 != (int *)0x0) {
          operator_delete(piStack_144);
        }
      }
    }
  }
  pTVar1 = &param_1->tacticalAI;
  iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0xd9);
  if (iVar12 == 1) {
    iVar12 = TribeTacticalAIModule::strategicNumber(pTVar1,0x68);
    uVar11 = (iVar12 + -3) * 1000;
    if ((int)uVar11 < 0) {
      uVar11 = 0;
    }
    if (uVar11 < *(uint *)(*(int *)(param_1->_padding_ + 0x3c) + 4)) {
      TribeTacticalAIModule::setStrategicNumber(pTVar1,0xd9,0);
      iVar6 = 1;
      iVar12 = *(int *)(param_1->_padding_ + 0x3c);
      iVar5 = -1;
      if (1 < *(short *)(iVar12 + 0x3c)) {
        do {
          iVar12 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar12 + 0x40) + iVar6 * 4))
          ;
          iVar5 = iVar6;
          if (iVar12 != 1) break;
          iVar6 = iVar6 + 1;
          iVar12 = *(int *)(param_1->_padding_ + 0x3c);
          iVar5 = -1;
        } while (iVar6 < *(short *)(iVar12 + 0x3c));
      }
      if (iVar5 != -1) {
        iVar12 = (**(code **)(*(int *)param_1->_padding_ + 0x18))(iVar5);
        if (iVar12 == 0) {
          (**(code **)(*(int *)param_1->_padding_ + 0x54))
                    ((int)*(short *)(param_1->_padding_ + 0x4a),6,iVar5,0,0);
        }
        iVar12 = param_1->_padding_;
        iVar7 = 1;
        iVar6 = *(int *)(iVar12 + 0x3c);
        if (1 < *(short *)(iVar6 + 0x3c)) {
          do {
            if ((iVar7 != *(short *)(iVar12 + 0x4a)) && (iVar7 != iVar5)) {
              pRVar3 = *(RGE_Player **)(*(int *)(iVar6 + 0x40) + iVar7 * 4);
              iVar12 = pRVar3->_padding_;
              iVar6 = (**(code **)(iVar12 + 0x18))(iVar5);
              if (iVar6 == 1) {
                (**(code **)(*(int *)param_1->_padding_ + 0x54))
                          ((int)*(short *)(param_1->_padding_ + 0x4a),6,iVar7,2,0);
                iVar6 = RGE_Player::computerPlayer(pRVar3);
                if (iVar6 == 1) {
                  iVar6 = (int)*(short *)(param_1->_padding_ + 0x4a);
                  (**(code **)(iVar12 + 0x54))(iVar6,6,iVar6,2,0);
                }
              }
              else {
                iVar12 = (**(code **)(iVar12 + 0x1c))(unaff_EBP);
                if (iVar12 == 1) {
                  (**(code **)(*(int *)param_1->_padding_ + 0x54))
                            ((int)*(short *)(param_1->_padding_ + 0x4a),6,iVar7,0,0);
                }
              }
            }
            iVar12 = param_1->_padding_;
            iVar7 = iVar7 + 1;
            iVar6 = *(int *)(iVar12 + 0x3c);
          } while (iVar7 < *(short *)(iVar6 + 0x3c));
        }
      }
    }
  }
  iVar12 = *(int *)(param_1->_padding_ + 0x3c);
  if ((*(char *)(iVar12 + 0x1d) == '\0') &&
     (*(int *)(iVar12 + 0xfc) == (int)*(short *)(param_1->_padding_ + 0x4a))) {
    (**(code **)((param_1->tacticalAI)._padding_ + 0x30))(0);
    param_1->lastTacticalUpdateTime = *(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4);
  }
  *unaff_FS_OFFSET = uStack_10;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e5d95
// Address: 004e5d95
// XREFS: None
undefined4 __thiscall
FUN_004e5d95(int param_1,undefined4 param_2,char param_3,undefined4 param_4,undefined4 param_5,
            int param_6)
{
  int in_EAX;
  char *pcVar1;
  MainDecisionAIModule *unaff_retaddr;
  
  pcVar1 = (char *)*(undefined6 *)(param_1 + 0x4e);
  *pcVar1 = *pcVar1 + (char)unaff_retaddr;
  cRam4f004e5a = cRam4f004e5a + (char)((uint)unaff_retaddr >> 8);
  *(char *)(in_EAX + 0x56909090) = *(char *)(in_EAX + 0x56909090) + param_3;
  MainDecisionAIModule::save(unaff_retaddr,param_6);
  (**(code **)(unaff_retaddr[1]._padding_ + 0x3c))();
  (**(code **)(unaff_retaddr[6]._padding_ + 0x3c))();
  (**(code **)(unaff_retaddr[9]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0xb]._padding_ + 0x3c))(param_6);
  TribeInformationAIModule::save((TribeInformationAIModule *)&unaff_retaddr[0xc]._padding_,param_6);
  (**(code **)(unaff_retaddr[0x109]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0x10a]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0x110]._padding_ + 0x3c))(param_6);
  (**(code **)(unaff_retaddr[0x11f].objects.desiredNumberValue + 0x3c))(param_6);
  rge_write(param_6,&unaff_retaddr[0x120].objects.numberValue,4);
  rge_write(param_6,&unaff_retaddr[0x120].objects.desiredNumberValue,4);
  rge_write(param_6,&unaff_retaddr[0x120].objects.maximumSizeValue,4);
  rge_write(param_6,unaff_retaddr + 0x121,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,4);
  rge_write(param_6,&unaff_retaddr[0x121]._padding_,0x24);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e5f2c
// Address: 004e5f2c
// XREFS: None
// [HELPER] s_Current_Build_list_is_: "Current Build list is:"
// [HELPER] s_Got_a_kick__d_: "Got a kick=%d."
void __thiscall FUN_004e5f2c(AIModule *param_1,int param_2)
{
  AIModule *extraout_ECX;
  AIModule *extraout_ECX_00;
  AIModule *extraout_ECX_01;
  AIModule *this;
  
  AIModule::logCommonHistory(param_1,(char *)param_1,s_Got_a_kick__d_,param_2);
  this = extraout_ECX;
  if (param_2 == 1) {
    TribeBuildAIModule::skipNextBuildListItem((TribeBuildAIModule *)(param_1[1].idValue.name + 8));
    this = extraout_ECX_00;
  }
  if (param_2 == 2) {
    TribeBuildAIModule::insert((TribeBuildAIModule *)(param_1[1].idValue.name + 8),0x53,1,-1);
    this = extraout_ECX_01;
  }
  if (param_2 == 3) {
    AIModule::logCommonHistory(this,(char *)param_1,s_Current_Build_list_is_);
    (**(code **)(*(int *)(param_1[1].idValue.name + 8) + 0x40))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e5f94
// Address: 004e5f94
// XREFS: None
int __thiscall FUN_004e5f94(MainDecisionAIModule *param_1,RGE_Static_Object *param_2)
{
  int iVar1;
  
  if (param_2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  TribeTacticalAIModule::addObject((TribeTacticalAIModule *)&param_1[0x110]._padding_,param_2);
  TribeInformationAIModule::addObject((TribeInformationAIModule *)&param_1[0xc]._padding_,param_2);
  iVar1 = MainDecisionAIModule::addObject(param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_004e5fd8
// Address: 004e5fd8
// XREFS: None
void __thiscall FUN_004e5fd8(MainDecisionAIModule *param_1,int param_2)
{
  TribeTacticalAIModule::removeObject((TribeTacticalAIModule *)&param_1[0x110]._padding_,param_2);
  TribeBuildAIModule::removeBuiltItem((TribeBuildAIModule *)(param_1 + 1),param_2);
  TribeInformationAIModule::removeObject
            ((TribeInformationAIModule *)&param_1[0xc]._padding_,param_2);
  MainDecisionAIModule::removeObject(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004e6019
// Address: 004e6019
// XREFS: None
int __thiscall FUN_004e6019(MainDecisionAIModule *param_1,int param_2)
{
  int iVar1;
  
  switch(param_2) {
  case 0x25a:
  case 0x25d:
  case 0x261:
  case 0x265:
    return 4;
  default:
    iVar1 = MainDecisionAIModule::objectGroupThatCanPerformAction(param_1,param_2);
    return iVar1;
  case 0x26b:
  case 0x26c:
    return 3;
  }
}

// --------------------------------------------------

// Function: FUN_004e605b
// Address: 004e605b
// XREFS: None
undefined4 __fastcall FUN_004e605b(MainDecisionAIModule *param_1,char param_2)
{
  byte bVar1;
  char cVar2;
  undefined4 in_EAX;
  RGE_Static_Object *pRVar5;
  int iVar6;
  char cVar7;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int unaff_ESI;
  char *unaff_EDI;
  byte in_AF;
  uint uVar3;
  char *pcVar4;
  
  bVar1 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar3 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar1 * -6) & 0xffffff0f;
  cVar2 = (char)uVar3;
  pcVar4 = (char *)CONCAT22((short)(uVar3 >> 0x10),CONCAT11((char)((uint)in_EAX >> 8) - bVar1,cVar2)
                           );
  cVar7 = (char)((uint)unaff_EBX >> 8);
  *unaff_EDI = *unaff_EDI + cVar7;
  *unaff_EDI = *unaff_EDI + cVar7;
  *unaff_EDI = *unaff_EDI + cVar7;
  pcVar4[0x60] = pcVar4[0x60] + (char)param_1;
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + param_2;
  *pcVar4 = *pcVar4 + cVar2;
  pRVar5 = MainDecisionAIModule::object(param_1,unaff_ESI + -3);
  if (pRVar5 != (RGE_Static_Object *)0x0) {
    iVar6 = (**(code **)(param_1->_padding_ + 0x48))(unaff_EBP);
    if (pRVar5->master_obj->object_group == iVar6) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e60cc
// Address: 004e60cc
// XREFS: None
void __thiscall FUN_004e60cc(int param_1,int param_2)
{
  TribeTacticalAIModule::detask((TribeTacticalAIModule *)(param_1 + 0x1146c),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004e60e3
// Address: 004e60e3
// XREFS: None
undefined4 __thiscall FUN_004e60e3(MainDecisionAIModule *param_1,int param_2)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object(param_1,param_2);
  if (((((pRVar2 != (RGE_Static_Object *)0x0) &&
        (sVar1 = pRVar2->master_obj->object_group, sVar1 != 3)) && (sVar1 != 0x1b)) &&
      (((sVar1 != 0x1e && (sVar1 != 0x1f)) && ((sVar1 != 5 && ((sVar1 != 0x21 && (sVar1 != 7))))))))
     && ((sVar1 != 8 && ((((sVar1 != 0x20 && (sVar1 != 0x10)) && (sVar1 != 0xe)) && (sVar1 != 0xf)))
         ))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e615a
// Address: 004e615a
// XREFS: None
void __fastcall FUN_004e615a(MainDecisionAIModule *param_1)
{
  RGE_Map *pRVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  
  iVar6 = 0;
  if (0 < (param_1->objects).numberValue) {
    do {
      if ((param_1->objects).maximumSizeValue + -1 < iVar6) {
        piVar2 = (int *)operator_new(iVar6 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->objects).maximumSizeValue) {
            do {
              if (iVar6 + 1 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->objects).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->objects).maximumSizeValue);
          }
          operator_delete((param_1->objects).value);
          (param_1->objects).value = piVar2;
          (param_1->objects).maximumSizeValue = iVar6 + 1;
        }
      }
      pRVar5 = MainDecisionAIModule::object(param_1,(param_1->objects).value[iVar6]);
      if ((pRVar5 != (RGE_Static_Object *)0x0) &&
         (TribeBuildAIModule::addItem((TribeBuildAIModule *)(param_1 + 1),pRVar5,0),
         pRVar5->master_obj->id == 0x6d)) {
        pRVar1 = param_1->player->world->map;
        ConstructionAIModule::setReferencePoint
                  ((ConstructionAIModule *)&param_1[6]._padding_,pRVar1->map_width,
                   pRVar1->map_height,pRVar5->world_x,pRVar5->world_y,pRVar5->world_z);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (param_1->objects).numberValue);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e624c
// Address: 004e624c
// XREFS: None
void __thiscall FUN_004e624c(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  TribeTacticalAIModule *unaff_EBX;
  int iVar4;
  undefined4 uVar5;
  TribeTacticalAIModule *this;
  int *piVar6;
  TribeTacticalAIModule *apTStack_108 [66];
  
  if (((*(int *)(param_1 + 0x1258c) == 1) &&
      (iVar1 = TribeTacticalAIModule::strategicNumber
                         ((TribeTacticalAIModule *)(param_1 + 0x1146c),0x80), param_2 == iVar1)) &&
     (param_3 == 3)) {
    *(int *)(param_1 + 0x12598) = *(int *)(param_1 + 0x12598) + param_4;
    return;
  }
  apTStack_108[0] = (TribeTacticalAIModule *)(param_1 + 0x1146c);
  iVar1 = TribeTacticalAIModule::strategicNumber(apTStack_108[0],0x80);
  if (param_2 != iVar1) {
    DiplomacyAIModule::changeStance((DiplomacyAIModule *)(param_1 + 0x9dc),param_2,2,param_4 / 100);
    DiplomacyAIModule::changeStance
              ((DiplomacyAIModule *)(param_1 + 0x9dc),param_2,0,-(param_4 / 100));
    *(int *)(param_1 + 0x125a4 + param_2 * 4) = *(int *)(param_1 + 0x125a4 + param_2 * 4) + param_4;
    iVar1 = (**(code **)(**(int **)(param_1 + 0xf0) + 0x20))();
    iVar4 = 1;
    if (((iVar1 == 1) &&
        (iVar1 = TribeTacticalAIModule::strategicNumber(unaff_EBX,0xd9), iVar1 == 1)) &&
       (*(int *)(param_1 + 0x125a0) <= *(int *)(param_1 + 0x125a4 + param_2 * 4))) {
      this = (TribeTacticalAIModule *)0x6;
      (**(code **)(**(int **)(param_1 + 0xf0) + 0x54))
                ((int)*(short *)((int)*(int **)(param_1 + 0xf0) + 0x4a),6,param_2);
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x907,&stack0xfffffee8,0x100);
      RGE_Player::sendChatMessage
                ((RGE_Player *)&stack0xfffffedc,*(int *)(param_1 + 0xf0),param_2,(char *)0x0,
                 (RGE_Player *)&stack0xfffffedc);
      iVar1 = *(int *)(param_1 + 0xf0);
      piVar6 = *(int **)(*(int *)(*(int *)(iVar1 + 0x3c) + 0x40) + param_2 * 4);
      if (1 < *(short *)(*(int *)(iVar1 + 0x3c) + 0x3c)) {
        do {
          if ((iVar4 != *(short *)(iVar1 + 0x4a)) && (iVar4 != param_2)) {
            iVar1 = *piVar6;
            iVar2 = (**(code **)(iVar1 + 0x1c))(iVar4);
            if (iVar2 == 1) {
              piVar3 = *(int **)(param_1 + 0xf0);
              uVar5 = 2;
              iVar1 = *piVar3;
            }
            else {
              iVar1 = (**(code **)(iVar1 + 0x18))(iVar4);
              if (iVar1 != 1) goto LAB_004e640b;
              piVar3 = *(int **)(param_1 + 0xf0);
              uVar5 = 0;
              iVar1 = *piVar3;
            }
            (**(code **)(iVar1 + 0x54))((int)*(short *)((int)piVar3 + 0x4a),6,iVar4,uVar5,0);
          }
LAB_004e640b:
          iVar1 = *(int *)(param_1 + 0xf0);
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(short *)(*(int *)(iVar1 + 0x3c) + 0x3c));
      }
      TribeTacticalAIModule::setStrategicNumber(this,0xd9,0);
      return;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0xf0) + 0x18))();
    if (iVar1 == 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))(0x906,apTStack_108);
      RGE_Player::sendChatMessage
                ((RGE_Player *)&stack0xfffffeec,*(int *)(param_1 + 0xf0),param_2,(char *)0x0,
                 (RGE_Player *)&stack0xfffffeec);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e6488
// Address: 004e6488
// XREFS: None
void __fastcall FUN_004e6488(int param_1)
{
  TribeTacticalAIModule *this;
  int iVar1;
  int iVar2;
  RGE_Player *this_00;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  
  this = (TribeTacticalAIModule *)(param_1 + 0x1146c);
  iVar1 = **(int **)(param_1 + 0xf0);
  TribeTacticalAIModule::strategicNumber(this,0x80);
  iVar1 = (**(code **)(iVar1 + 0x18))();
  if (iVar1 == 0) {
    iVar5 = iVar1;
    iVar2 = TribeTacticalAIModule::strategicNumber(this,0x80);
    DiplomacyAIModule::setStance((DiplomacyAIModule *)(param_1 + 0x9dc),iVar2,iVar1,iVar5);
    iVar2 = 100;
    iVar5 = 2;
    iVar1 = TribeTacticalAIModule::strategicNumber(this,0x80);
    DiplomacyAIModule::setStance((DiplomacyAIModule *)(param_1 + 0x9dc),iVar1,iVar5,iVar2);
    iVar1 = **(int **)(param_1 + 0x1256c);
    TribeTacticalAIModule::strategicNumber(this,0x80);
    (**(code **)(iVar1 + 0x28))();
    (**(code **)(rge_base_game->_padding_ + 0x20))(0x8fd,&stack0xfffffef4,0x100);
    puVar4 = &stack0xfffffee8;
    pcVar3 = (char *)0x0;
    iVar1 = TribeTacticalAIModule::strategicNumber(this,0x80);
    RGE_Player::sendChatMessage(this_00,*(int *)(param_1 + 0xf0),iVar1,pcVar3,puVar4);
    *(undefined4 *)(param_1 + 0x1258c) = 0;
    *(undefined4 *)(param_1 + 0x12594) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e6576
// Address: 004e6576
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taimdmd_cp: "C:\msdev\work\age1_x1\taimdmd.cpp"
void __fastcall FUN_004e6576(int param_1)
{
  TribeTacticalAIModule *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this = (TribeTacticalAIModule *)(param_1 + 0x1146c);
  iVar1 = TribeTacticalAIModule::strategicNumber(this,0x7e);
  if (0 < iVar1) {
    iVar1 = debug_rand(s_C__msdev_work_age1_x1_taimdmd_cp,0x41d);
    iVar2 = TribeTacticalAIModule::strategicNumber(this,0x7e);
    iVar3 = TribeTacticalAIModule::strategicNumber(this,0x7e);
    iVar4 = TribeTacticalAIModule::strategicNumber(this,0x7d);
    *(int *)(param_1 + 0x12588) = (iVar1 % iVar2 - iVar3 / 2) + iVar4;
    return;
  }
  iVar1 = TribeTacticalAIModule::strategicNumber(this,0x7d);
  *(int *)(param_1 + 0x12588) = iVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_004e65f5
// Address: 004e65f5
// XREFS: None
undefined4 __thiscall
FUN_004e65f5(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)
{
  DiplomacyAIModule *this;
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  
  switch(param_3) {
  case 0:
    TribeInformationAIModule::lookAtMap((TribeInformationAIModule *)(param_1 + 0xcec));
    return 1;
  case 1:
    if ((param_2 != *(short *)(*(int *)(param_1 + 0xf0) + 0x4a)) &&
       (pRVar1 = RGE_Object_List::find_by_master_id
                           (*(RGE_Object_List **)(*(int *)(param_1 + 0x1256c) + 0x28),0x54,-1.0,-1.0
                            ,'\0','\x02',(RGE_Static_Object *)0x0),
       pRVar1 != (RGE_Static_Object *)0x0)) {
      (**(code **)(**(int **)(param_1 + 0x1256c) + 0xf8))
                (param_2,param_4,(float)param_5,
                 *(undefined4 *)((*(int **)(param_1 + 0x1256c))[0x14] + 0xb8));
      return 1;
    }
    break;
  case 2:
  case 3:
    if (param_2 != *(short *)(*(int *)(param_1 + 0xf0) + 0x4a)) {
      TribeTacticalAIModule::processCoopAttack
                ((TribeTacticalAIModule *)(param_1 + 0x1146c),param_2,param_4,param_5,param_6);
      return 1;
    }
    break;
  default:
    return 0;
  case 6:
    this = (DiplomacyAIModule *)(param_1 + 0x9dc);
    DiplomacyAIModule::setChangeable(this,param_4,'\x01');
    if (param_5 == 0) {
      DiplomacyAIModule::setStance(this,param_4,0,100);
      iVar2 = 3;
LAB_004e681c:
      DiplomacyAIModule::setRelation(this,param_4,iVar2);
    }
    else {
      if (param_5 == 1) {
        DiplomacyAIModule::setStance(this,param_4,0,0x31);
        DiplomacyAIModule::setStance(this,param_4,2,0x31);
        iVar2 = 1;
        goto LAB_004e681c;
      }
      if (param_5 == 2) {
        DiplomacyAIModule::setStance(this,param_4,2,100);
        DiplomacyAIModule::setRelation(this,param_4,0);
        iVar2 = RGE_Base_Game::difficulty(rge_base_game);
        if (iVar2 != 4) {
          TRIBE_Command::command_allied_victory
                    (*(TRIBE_Command **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x3c) + 0x58),
                     *(short *)(*(int *)(param_1 + 0xf0) + 0x4a),'\x01');
          DiplomacyAIModule::setChangeable(this,param_4,'\0');
          return 1;
        }
        iVar3 = RGE_Player::computerPlayer
                          (*(RGE_Player **)
                            (*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0x3c) + 0x40) +
                            param_4 * 4));
        iVar2 = *(int *)(param_1 + 0xf0);
        if (iVar3 == 0) {
          TRIBE_Command::command_allied_victory
                    (*(TRIBE_Command **)(*(int *)(iVar2 + 0x3c) + 0x58),*(short *)(iVar2 + 0x4a),
                     '\x01');
          DiplomacyAIModule::setChangeable(this,param_4,'\0');
          return 1;
        }
        TRIBE_Command::command_allied_victory
                  (*(TRIBE_Command **)(*(int *)(iVar2 + 0x3c) + 0x58),*(short *)(iVar2 + 0x4a),'\0')
        ;
        DiplomacyAIModule::setChangeable(this,param_4,'\0');
        return 1;
      }
    }
    DiplomacyAIModule::setChangeable(this,param_4,'\0');
    break;
  case 7:
    *(int *)(param_1 + 0x125a0) = param_4;
    TribeTacticalAIModule::setStrategicNumber((TribeTacticalAIModule *)(param_1 + 0x1146c),0xd9,1);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e6841
// Address: 004e6841
// XREFS: None
long __fastcall FUN_004e6841(char *param_1,char param_2)
{
  int iVar1;
  int in_EAX;
  long lVar2;
  char cVar3;
  char unaff_BL;
  char unaff_BH;
  int unaff_ESI;
  char *unaff_EDI;
  byte in_CF;
  int unaff_retaddr;
  
  *(int *)(unaff_ESI + 0x4e) = (*(int *)(unaff_ESI + 0x4e) - (int)&stack0x00000000) - (uint)in_CF;
  cVar3 = (char)((uint)param_1 >> 8);
  *unaff_EDI = *unaff_EDI + cVar3;
  param_1[-0x5effb19a] = param_1[-0x5effb19a] + (char)((uint)in_EAX >> 8);
  *param_1 = *param_1 + unaff_BH;
  *unaff_EDI = *unaff_EDI + (char)in_EAX;
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + param_2;
  if ((0 < unaff_retaddr) &&
     (iVar1 = *(int *)(*(int *)(CONCAT22((short)((uint)param_1 >> 0x10),
                                         CONCAT11(cVar3 + unaff_BL,(char)param_1)) + 0xf0) + 0x3c),
     unaff_retaddr <= *(short *)(iVar1 + 0x3c))) {
    lVar2 = RGE_Victory_Conditions::get_victory_points
                      (*(RGE_Victory_Conditions **)
                        (*(int *)(*(int *)(iVar1 + 0x40) + unaff_retaddr * 4) + 0x34));
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_004e68a1
// Address: 004e68a1
// XREFS: None
AIPlayBook * __fastcall FUN_004e68a1(AIPlayBook *param_1)
{
  AIPlayBook::AIPlayBook(param_1);
  param_1->_padding_ = (int)&TribeAIPlayBook::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e68c2
// Address: 004e68c2
// XREFS: None
TribeAIPlayBook * __thiscall FUN_004e68c2(TribeAIPlayBook *param_1,byte param_2)
{
  TribeAIPlayBook::~TribeAIPlayBook(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e68f5
// Address: 004e68f5
// XREFS: None
void __thiscall FUN_004e68f5(AIPlayBook *param_1,char *param_2)
{
  AIPlayBook::convertTargetNameToIntType(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004e690d
// Address: 004e690d
// XREFS: None
void __thiscall FUN_004e690d(AIPlayBook *param_1,char *param_2)
{
  AIPlayBook::convertTargetCharacteristicNameToIntType(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004e691d
// Address: 004e691d
// XREFS: None
// [HELPER] s_Cavalry: "Cavalry"
// [HELPER] s_Hand: "Hand"
// [HELPER] s_Legion: "Legion"
// [HELPER] s_Priest: "Priest"
// [HELPER] s_Ranged: "Ranged"
// [HELPER] s_Siege: "Siege"
int __thiscall FUN_004e691d(AIPlayBook *param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Hand;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6959:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e695e;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6959;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e695e:
  if (iVar3 == 0) {
    return 0;
  }
  pbVar4 = &s_Ranged;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6998:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e699d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6998;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e699d:
  if (iVar3 == 0) {
    return 1;
  }
  pbVar4 = &s_Priest;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e69dc:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e69e1;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e69dc;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e69e1:
  if (iVar3 == 0) {
    return 4;
  }
  pbVar4 = &s_Siege;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6a20:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e6a25;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6a20;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e6a25:
  if (iVar3 == 0) {
    return 5;
  }
  pbVar4 = &s_Cavalry;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6a64:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e6a69;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6a64;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e6a69:
  if (iVar3 == 0) {
    return 2;
  }
  pbVar4 = &s_Legion;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004e6aa8:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004e6aad;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004e6aa8;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e6aad:
  if (iVar3 == 0) {
    return 3;
  }
  iVar3 = AIPlayBook::convertUnitNameToIntType(param_1,(char *)param_2);
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_004e6acc
// Address: 004e6acc
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e6acc(int *param_1)
{
  short sVar1;
  float10 fVar2;
  
  sVar1 = *(short *)(param_1[2] + 0x14);
  if (sVar1 == 0x12) {
    return 4;
  }
  if (sVar1 == 0x1c) {
    return 3;
  }
  if (sVar1 == 0xd) {
    return 5;
  }
  if ((sVar1 != 0xc) && (sVar1 != 0x23)) {
    fVar2 = (float10)(**(code **)(*param_1 + 0x10c))();
    if ((float10)_DAT_00575634 < fVar2) {
      return 1;
    }
    return 0;
  }
  return 2;
}

// --------------------------------------------------

// Function: FUN_004e6b3b
// Address: 004e6b3b
// XREFS: None
// [HELPER] s_Resource_AI: "Resource AI"
AIModule * __thiscall FUN_004e6b3b(AIModule *param_1,void *param_2,int param_3,int param_4)
{
  AIModule::AIModule(param_1,s_Resource_AI,0x3ef,param_3,param_2);
  param_1[1]._padding_ = 0;
  param_1[1].idValue._padding_ = param_4;
  param_1->_padding_ = (int)&TribeResourceAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e6b7e
// Address: 004e6b7e
// XREFS: None
TribeResourceAIModule * __thiscall FUN_004e6b7e(TribeResourceAIModule *param_1,byte param_2)
{
  TribeResourceAIModule::~TribeResourceAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e6b9e
// Address: 004e6b9e
// XREFS: None
// [HELPER] s_ResAI: "ResAI"
AIModule * __thiscall FUN_004e6b9e(AIModule *param_1,int param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560768;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_ResAI,0x3ef,param_2,(void *)0x0);
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TribeResourceAIModule::_vftable_;
  rge_read(param_3,&param_1[1].idValue,4);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e6c15
// Address: 004e6c15
// XREFS: None
void __fastcall FUN_004e6c15(AIModule *param_1)
{
  param_1->_padding_ = (int)&TribeResourceAIModule::_vftable_;
  AIModule::~AIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004e6c2b
// Address: 004e6c2b
// XREFS: None
void __thiscall FUN_004e6c2b(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004e6c3d
// Address: 004e6c3d
// XREFS: None
undefined4 __thiscall FUN_004e6c3d(int param_1,int param_2)
{
  rge_write(param_2,(void *)(param_1 + 0xf4),4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e6c5e
// Address: 004e6c5e
// XREFS: None
undefined4 __fastcall FUN_004e6c5e(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf4);
}

// --------------------------------------------------

// Function: FUN_004e6c67
// Address: 004e6c67
// XREFS: None
undefined4 __thiscall FUN_004e6c67(int param_1,int param_2)
{
  undefined4 uVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xf4))) {
    uVar1 = __ftol();
    return uVar1;
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004e6d33
// Address: 004e6d33
// XREFS: None
int __thiscall FUN_004e6d33(int param_1,ResourceItem *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == (ResourceItem *)0x0) {
    return 0;
  }
  iVar1 = ResourceItem::number(param_2);
  if (*(int *)(param_1 + 0xf4) == iVar1) {
    iVar3 = 0;
    iVar1 = ResourceItem::number(param_2);
    if (0 < iVar1) {
      do {
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x50);
        iVar2 = ResourceItem::value(param_2,iVar3);
        if (*(float *)(iVar1 + iVar3 * 4) < (float)iVar2) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
        iVar1 = ResourceItem::number(param_2);
      } while (iVar3 < iVar1);
      return -1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_004e6dc6
// Address: 004e6dc6
// XREFS: None
// [HELPER] s_Food: "Food"
// [HELPER] s_Gold: "Gold"
// [HELPER] s_Stone: "Stone"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s_Wood: "Wood"
char * FUN_004e6dc6(int param_1)
{
  char *pcVar1;
  
  if (param_1 == 0) {
    return s_Food;
  }
  if (param_1 == 1) {
    return s_Wood;
  }
  if (param_1 == 2) {
    return s_Stone;
  }
  pcVar1 = s_Gold;
  if (param_1 != 3) {
    pcVar1 = &s_Unknown;
  }
  return pcVar1;
}

// --------------------------------------------------

// Function: FUN_004e6e0c
// Address: 004e6e0c
// XREFS: None
void __fastcall FUN_004e6e0c(undefined4 *param_1)
{
  *param_1 = &VictoryConditionRuleSystem::_vftable_;
  param_1[1] = 0x22;
  param_1[2] = 0;
  param_1[3] = 0x42;
  param_1[4] = 2;
  param_1[5] = 2;
  param_1[6] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[8] = 0xffffffff;
  param_1[9] = 0xffffffff;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0xffffffff;
  param_1[0xd] = 0xffffffff;
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0xffffffff;
  param_1[0x11] = 4;
  param_1[0x12] = 0xffffffff;
  param_1[0x13] = 4;
  param_1[0x14] = 0x32;
  param_1[0x15] = 0x32;
  param_1[0x16] = 0xffffffff;
  param_1[0x17] = 0xc;
  param_1[0x18] = 10;
  param_1[0x19] = 0x4b;
  param_1[0x1a] = 1;
  param_1[0x1b] = 10;
  param_1[0x1c] = 0xffffffff;
  param_1[0x1d] = 4;
  param_1[0x1e] = 0x55;
  param_1[0x1f] = 0x46;
  param_1[0x20] = 0x4b;
  param_1[0x21] = 100;
  param_1[0x22] = 0xffffffff;
  param_1[0x23] = 0x32;
  param_1[0x24] = 0;
  param_1[0x25] = 3;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 4;
  param_1[0x2b] = 0;
  param_1[0x2c] = 1;
  param_1[0x2d] = 3;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0x1e;
  param_1[0x30] = 1;
  param_1[0x31] = 0x1e;
  param_1[0x32] = 3;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 7;
  param_1[0x3a] = 3;
  param_1[0x3b] = 2;
  param_1[0x3c] = 1;
  param_1[0x3d] = 5;
  param_1[0x3e] = 1;
  param_1[0x3f] = 1;
  param_1[0x40] = 2;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 1;
  param_1[0x49] = 2;
  param_1[0x4a] = 0xc;
  param_1[0x4b] = 0x14;
  param_1[0x4c] = 3;
  param_1[0x4d] = 0xf;
  param_1[0x4e] = 0x32;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 4;
  param_1[0x56] = 2;
  param_1[0x57] = 0x19;
  param_1[0x58] = 100;
  param_1[0x59] = 3;
  param_1[0x5a] = 0xffffffe7;
  param_1[0x5b] = 0;
  param_1[0x5c] = 100;
  param_1[0x5d] = 5;
  param_1[0x5e] = 1;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 1;
  param_1[100] = 10;
  param_1[0x65] = 3;
  param_1[0x66] = 1;
  param_1[0x67] = 0xf;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0xffffffff;
  param_1[0x6c] = 0xffffffff;
  param_1[0x6d] = 0xffffffff;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 300;
  param_1[0x72] = 0;
  param_1[0x73] = 0x19;
  param_1[0x74] = 10;
  param_1[0x75] = 10;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 100;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x81] = 0xffffffff;
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  param_1[0x84] = 3;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 1;
  param_1[0x89] = 0xf;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 1;
  param_1[0x91] = 0;
  param_1[0x92] = 10;
  param_1[0x93] = 0x32;
  param_1[0x94] = 10;
  param_1[0x95] = 0x14;
  param_1[0x96] = 0x28;
  param_1[0x97] = 0xffffffff;
  param_1[0x98] = 3;
  param_1[0x99] = 0;
  param_1[0x9a] = 0xffffffff;
  param_1[0x9b] = 0xffffffff;
  param_1[0x9c] = 10;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0x32;
  param_1[0xa2] = 2;
  param_1[0xa3] = 0;
  param_1[0xa4] = 7;
  param_1[0xa5] = 10;
  param_1[0xa6] = 0x19;
  param_1[0xa7] = 7;
  param_1[0xa8] = 2;
  param_1[0xa9] = 0x32;
  param_1[0xaa] = 10;
  param_1[0xab] = 200;
  param_1[0xac] = 0xfa;
  param_1[0xad] = 0x96;
  param_1[0xae] = 200;
  param_1[0xaf] = 2;
  param_1[0xb0] = 0xffffffff;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0xffffffff;
  param_1[0xb3] = 10;
  param_1[0xb4] = 0x1e;
  param_1[0xb5] = 1;
  param_1[0xb6] = 1;
  param_1[0xb7] = 0;
  param_1[0xb8] = 0;
  param_1[0xb9] = 0x14;
  param_1[0xba] = 0x32;
  param_1[0xbb] = 0;
  param_1[0xbc] = 0;
  param_1[0xbd] = 1;
  param_1[0xbe] = 0x32;
  param_1[0xbf] = 3000;
  param_1[0xc0] = 2000;
  param_1[0xc1] = 0x5dc;
  param_1[0xc2] = 3000;
  param_1[0xc3] = 1;
  param_1[0xc4] = 0x19;
  param_1[200] = 0x19;
  param_1[0xcb] = 0x19;
  param_1[0xc5] = 1;
  param_1[0xc6] = 0x78;
  param_1[199] = 0x32;
  param_1[0xc9] = 0x32;
  param_1[0xca] = 0;
  param_1[0xcc] = 1;
  param_1[0xcd] = 5;
  param_1[0xce] = 1;
  param_1[0xcf] = 1;
  param_1[0xd0] = 1;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 1;
  param_1[0xd5] = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 1;
  param_1[0xd9] = 0x32;
  param_1[0xda] = 0;
  param_1[0xdb] = 100;
  param_1[0xdc] = 100;
  param_1[0xdd] = 8;
  param_1[0xde] = 3;
  param_1[0xdf] = 10;
  param_1[0xe0] = 0;
  param_1[0xe1] = 0;
  param_1[0xe2] = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004e740b
// Address: 004e740b
// XREFS: None
VictoryConditionRuleSystem * __thiscall
FUN_004e740b(VictoryConditionRuleSystem *param_1,byte param_2)
{
  VictoryConditionRuleSystem::~VictoryConditionRuleSystem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e742e
// Address: 004e742e
// XREFS: None
void __fastcall FUN_004e742e(undefined4 *param_1)
{
  *param_1 = &VictoryConditionRuleSystem::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_004e7437
// Address: 004e7437
// XREFS: None
// [HELPER] s_NONE: "NONE"
// [HELPER] s___c_c: " %c%c"
// [HELPER] s__d__d_: "%d %d "
// [HELPER] s__s: "%s"
// [HELPER] s__tmp: ".tmp"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_004e7437(int param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  char cStack_10a;
  char cStack_109;
  int iStack_108;
  undefined4 uStack_104;
  undefined1 auStack_100 [256];
  
  pbVar5 = &s_NONE;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_004e747e:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_004e7483;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_004e747e;
    pbVar2 = pbVar2 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004e7483:
  if ((iVar3 != 0) && (param_2 != (byte *)0x0)) {
    iVar3 = -1;
    pbVar2 = param_2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
    } while (bVar1 != 0);
    if (iVar3 != -2) {
      sprintf(auStack_100,s__s,param_2);
      iVar3 = fopen(auStack_100,s_r);
      if (iVar3 != 0) {
        iVar4 = fgets(auStack_100,0x100,iVar3);
        while (iVar4 != 0) {
          sscanf(auStack_100,s___c_c,&cStack_10a,&cStack_109);
          if ((((cStack_10a != '/') || (cStack_109 != '/')) &&
              ((cStack_10a != 'D' || (cStack_109 != 'E')))) &&
             ((cStack_10a != 'V' || (cStack_109 != 'C')))) {
            if ((cStack_10a == 'E') && (cStack_109 == 'N')) break;
            sscanf(auStack_100,s__d__d_,&iStack_108,&uStack_104);
            if ((-1 < iStack_108) && (iStack_108 < 0xe2)) {
              *(undefined4 *)(param_1 + 4 + iStack_108 * 4) = uStack_104;
            }
          }
          iVar4 = fgets(auStack_100,0x100,iVar3);
        }
        fclose(iVar3);
        iVar3 = strstr(param_2,s__tmp);
        if (iVar3 != 0) {
          __unlink(param_2);
        }
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e75ca
// Address: 004e75ca
// XREFS: None
void __thiscall FUN_004e75ca(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 0xe2)) {
    *(undefined4 *)(param_1 + 4 + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e75ea
// Address: 004e75ea
// XREFS: None
undefined4 __thiscall FUN_004e75ea(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0xe2)) {
    return *(undefined4 *)(param_1 + 4 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004e760c
// Address: 004e760c
// XREFS: None
undefined4 FUN_004e760c(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e7615
// Address: 004e7615
// XREFS: None
undefined4 FUN_004e7615(undefined4 param_1,undefined4 param_2)
{
  switch(param_2) {
  case 1:
  case 2:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
    return 0xfffffffe;
  default:
    return 0;
  }
}

// --------------------------------------------------

// Function: FUN_004e7646
// Address: 004e7646
// XREFS: None
/* WARNING: Instruction at (ram,0x004e76a5) overlaps instruction at (ram,0x004e76a3)
    */

undefined4 __fastcall
FUN_004e7646(byte *param_1,char *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            undefined4 param_6,undefined4 param_7)
{
  byte bVar1;
  char cVar2;
  char *in_EAX;
  undefined3 uVar5;
  uint uVar3;
  char *pcVar4;
  int iVar6;
  byte bVar7;
  int *unaff_EBX;
  byte *unaff_ESI;
  int iVar8;
  int iVar9;
  
  bVar1 = *param_1;
  bVar7 = (byte)((uint)unaff_EBX >> 8);
  *param_1 = *param_1 + bVar7;
  if (CARRY1(bVar1,bVar7) || *param_1 == 0) {
    in_EAX = in_EAX + CARRY1(bVar1,bVar7) + 0xf8830000;
code_r0x004e76a2:
    pcVar4 = (char *)((uint)in_EAX | 0x15928d0f);
    *pcVar4 = *pcVar4 + (char)pcVar4;
  }
  else {
    bVar1 = *param_1;
    *param_1 = *param_1 + bVar7;
    if (CARRY1(bVar1,bVar7) || *param_1 == 0) goto code_r0x004e76a2;
    bVar1 = *param_1;
    *param_1 = *param_1 + bVar7;
    if (!CARRY1(bVar1,bVar7) && *param_1 != 0) {
      cVar2 = (char)in_EAX;
      param_1[0x76] = param_1[0x76] + cVar2;
      *in_EAX = *in_EAX + cVar2;
      in_EAX[(int)&stack0x00000000] = in_EAX[(int)&stack0x00000000] + cVar2;
      uVar5 = (undefined3)((uint)in_EAX >> 8);
      *(int *)param_1 = *(int *)param_1 + CONCAT31(uVar5,cVar2 + '\r');
      uVar3 = CONCAT31(uVar5,cVar2 + *param_2 + '\x13') + *unaff_EBX + *unaff_EBX + *unaff_EBX +
              *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX +
              *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX + *unaff_EBX & 0xffffff08;
      if ((int)uVar3 < 0) {
        return 0;
      }
      unaff_ESI = param_1;
      if (0xc < (int)uVar3) {
        return 0;
      }
    }
  }
  switch(param_7) {
  case 1:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0,
               *(int *)(unaff_ESI + 4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),1,
               *(int *)(unaff_ESI + 8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),2,
               *(int *)(unaff_ESI + 0xc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),3,
               *(int *)(unaff_ESI + 0x10));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),4,
               *(int *)(unaff_ESI + 0x14));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),5,
               *(int *)(unaff_ESI + 0x18));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x23,
               *(int *)(unaff_ESI + 0x90));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),100,
               *(int *)(unaff_ESI + 0x194));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xe1,
               *(int *)(unaff_ESI + 0x388));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x75,
               *(int *)(unaff_ESI + 0x1d8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x76,
               *(int *)(unaff_ESI + 0x1dc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x77,
               *(int *)(unaff_ESI + 0x1e0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x78,
               *(int *)(unaff_ESI + 0x1e4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9c,
               *(int *)(unaff_ESI + 0x274));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9f,
               *(int *)(unaff_ESI + 0x280));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9e,
               *(int *)(unaff_ESI + 0x27c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9d,
               *(int *)(unaff_ESI + 0x278));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa0,
               *(int *)(unaff_ESI + 0x284));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8e,
               *(int *)(unaff_ESI + 0x23c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x94,
               *(int *)(unaff_ESI + 0x254));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x95,
               *(int *)(unaff_ESI + 600));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xcb,
               *(int *)(unaff_ESI + 0x330));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa3,
               *(int *)(unaff_ESI + 0x290));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa4,
               *(int *)(unaff_ESI + 0x294));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa6,
               *(int *)(unaff_ESI + 0x29c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa5,
               *(int *)(unaff_ESI + 0x298));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa7,
               *(int *)(unaff_ESI + 0x2a0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb3,
               *(int *)(unaff_ESI + 0x2d0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb4,
               *(int *)(unaff_ESI + 0x2d4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xcd,
               *(int *)(unaff_ESI + 0x338));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xcf,
               *(int *)(unaff_ESI + 0x340));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xce,
               *(int *)(unaff_ESI + 0x33c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xdc,
               *(int *)(unaff_ESI + 0x374));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xde,
               *(int *)(unaff_ESI + 0x37c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd0,
               *(int *)(unaff_ESI + 0x344));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd1,
               *(int *)(unaff_ESI + 0x348));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd2,
               *(int *)(unaff_ESI + 0x34c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd3,
               *(int *)(unaff_ESI + 0x350));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xdf,
               *(int *)(unaff_ESI + 0x380));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd4,
               *(int *)(unaff_ESI + 0x354));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd5,
               *(int *)(unaff_ESI + 0x358));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd6,
               *(int *)(unaff_ESI + 0x35c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xe0,
               *(int *)(unaff_ESI + 900));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa9,
               *(int *)(unaff_ESI + 0x2a8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xaa,
               *(int *)(unaff_ESI + 0x2ac));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xab,
               *(int *)(unaff_ESI + 0x2b0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xac,
               *(int *)(unaff_ESI + 0x2b4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xad,
               *(int *)(unaff_ESI + 0x2b8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbe,
               *(int *)(unaff_ESI + 0x2fc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbf,
               *(int *)(unaff_ESI + 0x300));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc0,
               *(int *)(unaff_ESI + 0x304));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc1,
               *(int *)(unaff_ESI + 0x308));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xae,
               *(int *)(unaff_ESI + 700));
    iVar9 = *(int *)(unaff_ESI + 0x334);
    iVar8 = 0xcc;
    break;
  case 2:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x10,
               *(int *)(unaff_ESI + 0x44));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1a,
               *(int *)(unaff_ESI + 0x6c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x24,
               *(int *)(unaff_ESI + 0x94));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x25,
               *(int *)(unaff_ESI + 0x98));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5d,
               *(int *)(unaff_ESI + 0x178));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5e,
               *(int *)(unaff_ESI + 0x17c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x62,
               *(int *)(unaff_ESI + 0x18c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x79,
               *(int *)(unaff_ESI + 0x1e8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x83,
               *(int *)(unaff_ESI + 0x210));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8f,
               *(int *)(unaff_ESI + 0x240));
    iVar9 = *(int *)(unaff_ESI + 0x28c);
    iVar8 = 0xa2;
    break;
  default:
    return 0;
  case 0xc:
    iVar9 = *(int *)(unaff_ESI + 0x4c);
    iVar8 = 0x12;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0xd:
    iVar9 = *(int *)(unaff_ESI + 0x50);
    iVar8 = 0x13;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0xe:
    iVar9 = *(int *)(unaff_ESI + 0x54);
    iVar8 = 0x14;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x10:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x16,
               *(int *)(unaff_ESI + 0x5c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x48,
               *(int *)(unaff_ESI + 0x124));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x39,
               *(int *)(unaff_ESI + 0xe8));
    iVar9 = *(int *)(unaff_ESI + 0x174);
    iVar8 = 0x5c;
    break;
  case 0x11:
    iVar9 = *(int *)(unaff_ESI + 0x60);
    iVar8 = 0x17;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x12:
    iVar9 = *(int *)(unaff_ESI + 100);
    iVar8 = 0x18;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x15:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x19,
               *(int *)(unaff_ESI + 0x68));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1c,
               *(int *)(unaff_ESI + 0x74));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x26,
               *(int *)(unaff_ESI + 0x9c));
    iVar9 = *(int *)(unaff_ESI + 0xa0);
    iVar8 = 0x27;
    break;
  case 0x16:
    iVar9 = *(int *)(unaff_ESI + 0x78);
    iVar8 = 0x1d;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x17:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x20,
               *(int *)(unaff_ESI + 0x84));
    iVar9 = *(int *)(unaff_ESI + 0x248);
    iVar8 = 0x91;
    break;
  case 0x18:
    iVar9 = *(int *)(unaff_ESI + 0x8c);
    iVar8 = 0x22;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x19:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x28,
               *(int *)(unaff_ESI + 0xa4));
    iVar9 = *(int *)(unaff_ESI + 0x130);
    iVar8 = 0x4b;
    break;
  case 0x1a:
    iVar9 = *(int *)(unaff_ESI + 0xa8);
    iVar8 = 0x29;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x1b:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2b,
               *(int *)(unaff_ESI + 0xb0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2c,
               *(int *)(unaff_ESI + 0xb4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2a,
               *(int *)(unaff_ESI + 0xac));
    iVar9 = *(int *)(unaff_ESI + 0xb8);
    iVar8 = 0x2d;
    break;
  case 0x1c:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1e,
               *(int *)(unaff_ESI + 0x7c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x1f,
               *(int *)(unaff_ESI + 0x80));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5b,
               *(int *)(unaff_ESI + 0x170));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5f,
               *(int *)(unaff_ESI + 0x180));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x60,
               *(int *)(unaff_ESI + 0x184));
    iVar9 = *(int *)(unaff_ESI + 0x188);
    iVar8 = 0x61;
    break;
  case 0x1d:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2e,
               *(int *)(unaff_ESI + 0xbc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x66,
               *(int *)(unaff_ESI + 0x19c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x2f,
               *(int *)(unaff_ESI + 0xc0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x67,
               *(int *)(unaff_ESI + 0x1a0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x68,
               *(int *)(unaff_ESI + 0x1a4));
    iVar9 = *(int *)(unaff_ESI + 0x21c);
    iVar8 = 0x86;
    break;
  case 0x1e:
    iVar9 = *(int *)(unaff_ESI + 0xc4);
    iVar8 = 0x30;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x1f:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x31,
               *(int *)(unaff_ESI + 200));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x87,
               *(int *)(unaff_ESI + 0x220));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x88,
               *(int *)(unaff_ESI + 0x224));
    iVar9 = *(int *)(unaff_ESI + 0x324);
    iVar8 = 200;
    break;
  case 0x20:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x32,
               *(int *)(unaff_ESI + 0xcc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x33,
               *(int *)(unaff_ESI + 0xd0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x34,
               *(int *)(unaff_ESI + 0xd4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x35,
               *(int *)(unaff_ESI + 0xd8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x36,
               *(int *)(unaff_ESI + 0xdc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x37,
               *(int *)(unaff_ESI + 0xe0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x38,
               *(int *)(unaff_ESI + 0xe4));
    iVar9 = *(int *)(unaff_ESI + 0x11c);
    iVar8 = 0x46;
    break;
  case 0x21:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3a,
               *(int *)(unaff_ESI + 0xec));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3b,
               *(int *)(unaff_ESI + 0xf0));
    iVar9 = *(int *)(unaff_ESI + 0xf4);
    iVar8 = 0x3c;
    break;
  case 0x22:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3d,
               *(int *)(unaff_ESI + 0xf8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x3e,
               *(int *)(unaff_ESI + 0xfc));
    iVar9 = *(int *)(unaff_ESI + 0x100);
    iVar8 = 0x3f;
    break;
  case 0x23:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x40,
               *(int *)(unaff_ESI + 0x104));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x41,
               *(int *)(unaff_ESI + 0x108));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x42,
               *(int *)(unaff_ESI + 0x10c));
    iVar9 = *(int *)(unaff_ESI + 0x364);
    iVar8 = 0xd8;
    break;
  case 0x24:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x43,
               *(int *)(unaff_ESI + 0x110));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x44,
               *(int *)(unaff_ESI + 0x114));
    iVar9 = *(int *)(unaff_ESI + 0x118);
    iVar8 = 0x45;
    break;
  case 0x25:
    iVar9 = *(int *)(unaff_ESI + 0x120);
    iVar8 = 0x47;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x26:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x49,
               *(int *)(unaff_ESI + 0x128));
    iVar9 = *(int *)(unaff_ESI + 300);
    iVar8 = 0x4a;
    break;
  case 0x27:
    iVar9 = *(int *)(unaff_ESI + 0x134);
    iVar8 = 0x4c;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x28:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x4d,
               *(int *)(unaff_ESI + 0x138));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x4e,
               *(int *)(unaff_ESI + 0x13c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x4f,
               *(int *)(unaff_ESI + 0x140));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x50,
               *(int *)(unaff_ESI + 0x144));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x51,
               *(int *)(unaff_ESI + 0x148));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x52,
               *(int *)(unaff_ESI + 0x14c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x53,
               *(int *)(unaff_ESI + 0x150));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x59,
               *(int *)(unaff_ESI + 0x168));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x5a,
               *(int *)(unaff_ESI + 0x16c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6a,
               *(int *)(unaff_ESI + 0x1ac));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6b,
               *(int *)(unaff_ESI + 0x1b0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6c,
               *(int *)(unaff_ESI + 0x1b4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6d,
               *(int *)(unaff_ESI + 0x1b8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6e,
               *(int *)(unaff_ESI + 0x1bc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x6f,
               *(int *)(unaff_ESI + 0x1c0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7a,
               *(int *)(unaff_ESI + 0x1ec));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7b,
               *(int *)(unaff_ESI + 0x1f0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x90,
               *(int *)(unaff_ESI + 0x244));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb8,
               *(int *)(unaff_ESI + 0x2e4));
    iVar9 = *(int *)(unaff_ESI + 0x2e8);
    iVar8 = 0xb9;
    break;
  case 0x29:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x54,
               *(int *)(unaff_ESI + 0x154));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x55,
               *(int *)(unaff_ESI + 0x158));
    iVar9 = *(int *)(unaff_ESI + 0x228);
    iVar8 = 0x89;
    break;
  case 0x2a:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x56,
               *(int *)(unaff_ESI + 0x15c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x57,
               *(int *)(unaff_ESI + 0x160));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xca,
               *(int *)(unaff_ESI + 0x32c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x96,
               *(int *)(unaff_ESI + 0x25c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x97,
               *(int *)(unaff_ESI + 0x260));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x98,
               *(int *)(unaff_ESI + 0x264));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xa1,
               *(int *)(unaff_ESI + 0x288));
    iVar9 = *(int *)(unaff_ESI + 0x2a4);
    iVar8 = 0xa8;
    break;
  case 0x2b:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x58,
               *(int *)(unaff_ESI + 0x164));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x65,
               *(int *)(unaff_ESI + 0x198));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x9b,
               *(int *)(unaff_ESI + 0x270));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xaf,
               *(int *)(unaff_ESI + 0x2c0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb0,
               *(int *)(unaff_ESI + 0x2c4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb1,
               *(int *)(unaff_ESI + 0x2c8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb5,
               *(int *)(unaff_ESI + 0x2d8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb6,
               *(int *)(unaff_ESI + 0x2dc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb7,
               *(int *)(unaff_ESI + 0x2e0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xba,
               *(int *)(unaff_ESI + 0x2ec));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbb,
               *(int *)(unaff_ESI + 0x2f0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc2,
               *(int *)(unaff_ESI + 0x30c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc4,
               *(int *)(unaff_ESI + 0x314));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc5,
               *(int *)(unaff_ESI + 0x318));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbc,
               *(int *)(unaff_ESI + 0x2f4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc3,
               *(int *)(unaff_ESI + 0x310));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xbd,
               *(int *)(unaff_ESI + 0x2f8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xc6,
               *(int *)(unaff_ESI + 0x31c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),199,
               *(int *)(unaff_ESI + 800));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd7,
               *(int *)(unaff_ESI + 0x360));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xd9,
               *(int *)(unaff_ESI + 0x368));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xda,
               *(int *)(unaff_ESI + 0x36c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xdb,
               *(int *)(unaff_ESI + 0x370));
    iVar9 = *(int *)(unaff_ESI + 0x378);
    iVar8 = 0xdd;
    break;
  case 0x2c:
    iVar9 = *(int *)(unaff_ESI + 400);
    iVar8 = 99;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x2d:
    iVar9 = *(int *)(unaff_ESI + 0x1a8);
    iVar8 = 0x69;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x2e:
    iVar9 = *(int *)(unaff_ESI + 0x1c4);
    iVar8 = 0x70;
    iVar6 = *(int *)(param_5 + 0x238);
    goto LAB_004e8c26;
  case 0x2f:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x71,
               *(int *)(unaff_ESI + 0x1c8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x72,
               *(int *)(unaff_ESI + 0x1cc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x73,
               *(int *)(unaff_ESI + 0x1d0));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x74,
               *(int *)(unaff_ESI + 0x1d4));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x92,
               *(int *)(unaff_ESI + 0x24c));
    iVar9 = *(int *)(unaff_ESI + 0x250);
    iVar8 = 0x93;
    break;
  case 0x30:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7c,
               *(int *)(unaff_ESI + 500));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7d,
               *(int *)(unaff_ESI + 0x1f8));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7e,
               *(int *)(unaff_ESI + 0x1fc));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x7f,
               *(int *)(unaff_ESI + 0x200));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x80,
               *(int *)(unaff_ESI + 0x204));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x81,
               *(int *)(unaff_ESI + 0x208));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x82,
               *(int *)(unaff_ESI + 0x20c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x84,
               *(int *)(unaff_ESI + 0x214));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x85,
               *(int *)(unaff_ESI + 0x218));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0xb2,
               *(int *)(unaff_ESI + 0x2cc));
    iVar9 = *(int *)(unaff_ESI + 0x328);
    iVar8 = 0xc9;
    break;
  case 0x31:
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8a,
               *(int *)(unaff_ESI + 0x22c));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8b,
               *(int *)(unaff_ESI + 0x230));
    TribeTacticalAIModule::setStrategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_5 + 0x238) + 0x1146c),0x8c,
               *(int *)(unaff_ESI + 0x234));
    iVar9 = *(int *)(unaff_ESI + 0x238);
    iVar8 = 0x8d;
  }
  iVar6 = *(int *)(param_5 + 0x238);
LAB_004e8c26:
  TribeTacticalAIModule::setStrategicNumber((TribeTacticalAIModule *)(iVar6 + 0x1146c),iVar8,iVar9);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e8c42
// Address: 004e8c42
// XREFS: None
/* WARNING: Instruction at (ram,0x004e8d01) overlaps instruction at (ram,0x004e8cff)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined4 __fastcall FUN_004e8c42(uint param_1,undefined4 param_2)
{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  char cVar3;
  uint uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char *unaff_EBX;
  int unaff_EBP;
  uint *puVar10;
  int unaff_EDI;
  undefined2 in_CS;
  undefined1 in_ZF;
  char in_SF;
  char in_OF;
  float10 in_ST0;
  uint uVar4;
  
  cVar9 = (char)((uint)param_2 >> 8);
  cVar6 = (char)param_2;
  puVar10 = (uint *)0x9e004e76;
  uVar4 = param_1;
  if (in_OF == in_SF) {
    cVar8 = (char)((uint)unaff_EBX >> 8);
    *unaff_EBX = *unaff_EBX + cVar8;
    *unaff_EBX = *unaff_EBX + cVar8;
    *unaff_EBX = *unaff_EBX + cVar8;
    pcVar1 = (char *)(unaff_EDI + -0x33ffb183);
    cVar2 = *pcVar1;
    uRam9e004e76 = in_CS;
    *pcVar1 = *pcVar1 + cVar9;
    if (SCARRY1(cVar2,cVar9) == *pcVar1 < '\0') goto code_r0x004e8cc5;
    cVar2 = (char)((uint)in_EAX >> 8);
    cVar3 = (char)param_1 + cVar2;
    uVar4 = CONCAT31((int3)(param_1 >> 8),cVar3);
    if (SCARRY1((char)param_1,cVar2) != cVar3 < '\0') {
      *unaff_EBX = *unaff_EBX + cVar8;
      in_EAX = CONCAT22((short)((uint)in_EAX >> 0x10),
                        CONCAT11((char)((short)in_EAX % (short)*(char *)(unaff_EBP + 0x4e)),
                                 (char)((short)in_EAX / (short)*(char *)(unaff_EBP + 0x4e))));
      uRam9e004e76 = in_CS;
      unaff_EBX[0x7e] = unaff_EBX[0x7e] + cVar6;
      *(char *)(in_EAX + 0x7e) = *(char *)(in_EAX + 0x7e) + (char)(param_1 >> 8);
      puVar10 = (uint *)0x9e004e74;
      *unaff_EBX = *unaff_EBX + cVar8;
      in_OF = SCARRY1(cVar8,cVar6);
      cVar8 = cVar8 + cVar6;
      unaff_EBX = (char *)CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar8,(char)unaff_EBX))
      ;
      in_SF = cVar8 < '\0';
      in_ZF = cVar8 == '\0';
      uRam9e004e74 = in_CS;
      goto code_r0x004e8c99;
    }
  }
  else {
code_r0x004e8c99:
    if ((bool)in_ZF || in_OF != in_SF) {
      LOCK();
      uVar5 = *puVar10;
      *(byte *)puVar10 = (byte)uVar4;
      uVar5 = CONCAT31((int3)(uVar4 >> 8),(byte)uVar5);
      UNLOCK();
code_r0x004e8cf1:
      *puVar10 = uVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    cVar8 = (char)((uint)in_EAX >> 8);
    cVar3 = (char)(uVar4 >> 8);
    cVar2 = cVar8 + cVar3;
    if (cVar2 == '\0' || SCARRY1(cVar8,cVar3) != cVar2 < '\0') {
      LOCK();
      uVar5 = *puVar10;
      *puVar10 = uVar4;
      UNLOCK();
      goto code_r0x004e8cf1;
    }
    cVar8 = *unaff_EBX;
    cVar7 = (char)unaff_EBX;
    *unaff_EBX = *unaff_EBX + cVar7;
    uVar5 = uVar4;
    if (*unaff_EBX != '\0' && SCARRY1(cVar8,cVar7) == *unaff_EBX < '\0') goto code_r0x004e8cf1;
    cVar8 = *unaff_EBX;
    *unaff_EBX = *unaff_EBX + cVar9;
    if (*unaff_EBX != '\0' && SCARRY1(cVar8,cVar9) == *unaff_EBX < '\0') goto code_r0x004e8cf5;
    *(char *)(unaff_EDI + 0x7f) = *(char *)(unaff_EDI + 0x7f) + cVar7;
    *(char *)(unaff_EDI + 0x7f) = *(char *)(unaff_EDI + 0x7f) + cVar9;
    cVar8 = (char)((uint)unaff_EBX >> 8);
    cVar9 = cVar8 + cVar6;
    if (cVar9 != '\0' && SCARRY1(cVar8,cVar6) == cVar9 < '\0') {
      return 0;
    }
    pcVar1 = (char *)(CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar2,(char)in_EAX)) + -0x80);
    *pcVar1 = *pcVar1 + cVar3;
    puVar10 = (uint *)((int)puVar10 + -3);
    *(byte *)puVar10 = *(byte *)puVar10 | 0x17;
    *puVar10 = *puVar10 | 0x4e8180;
code_r0x004e8cc5:
    *(byte *)puVar10 = (byte)*puVar10 | 0x8e;
  }
  *(byte *)puVar10 = (byte)*puVar10 | 0xd4;
  *(byte *)puVar10 = (byte)*puVar10 | 0x37;
  *puVar10 = *puVar10 | 0x7d;
  *puVar10 = *puVar10 | 0xffffff95;
  *puVar10 = *puVar10 | 0xffffffc1;
  *puVar10 = *puVar10 | 0xffffffd9;
  *puVar10 = *puVar10 | 0xffffffe2;
  puVar10 = (uint *)((int)puVar10 + -1);
  *(char *)(unaff_EDI + -0x38ffb177) = *(char *)(unaff_EDI + -0x38ffb177) + (char)(uVar4 >> 8);
code_r0x004e8cf5:
  *puVar10 = uVar4;
  *(short *)(uVar4 + 0x89f7004e) = (short)in_ST0;
  *(char *)(uVar4 + 0xb9004e8a) = *(char *)(uVar4 + 0xb9004e8a) + cVar6;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004e8d15
// Address: 004e8d15
// XREFS: None
void __thiscall FUN_004e8d15(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != 0) {
    iVar2 = 0;
    iVar4 = 0;
    iVar3 = 0;
    switch(param_2) {
    case 1:
      iVar1 = RGE_Base_Game::scenarioGame(rge_base_game);
      if (iVar1 == 1) {
        iVar2 = 0x1e;
        iVar4 = 0x78;
        iVar3 = 1;
      }
      break;
    case 2:
      iVar2 = 0x3c;
      iVar4 = 0xf0;
      iVar3 = 2;
      break;
    case 3:
      iVar2 = 0x5a;
      iVar4 = RGE_Base_Game::scenarioGame(rge_base_game);
      iVar3 = 3;
      iVar4 = (-(uint)(iVar4 != 1) & 0x21c) + 0x168;
      break;
    case 4:
      iVar2 = 0x78;
      iVar4 = RGE_Base_Game::scenarioGame(rge_base_game);
      iVar3 = 4;
      iVar4 = (-(uint)(iVar4 != 1) & 0x30c) + 0x1e0;
      break;
    default:
      goto switchD_004e8d55_default;
    }
    if (0 < *(int *)(param_1 + 0x94)) {
      iVar1 = __ftol();
      *(int *)(param_1 + 0x94) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x94) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x44)) {
      iVar1 = __ftol();
      *(int *)(param_1 + 0x44) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x6c)) {
      iVar1 = __ftol();
      *(int *)(param_1 + 0x6c) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x6c) = 1;
      }
    }
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + iVar2;
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + iVar2;
    if (0 < *(int *)(param_1 + 0x50)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x50) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x50) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x54)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x54) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x54) = 1;
      }
    }
    *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + iVar4;
    if (0 < *(int *)(param_1 + 0x68)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x68) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x68) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x74)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x74) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x74) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x9c)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x9c) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x9c) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0xec)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0xec) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0xec) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0xf0)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0xf0) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0xf0) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0xf4)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0xf4) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0xf4) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x110)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x110) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x110) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x114)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x114) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x114) = 1;
      }
    }
    if (0 < *(int *)(param_1 + 0x118)) {
      iVar2 = __ftol();
      *(int *)(param_1 + 0x118) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x118) = 1;
      }
    }
    *(int *)(param_1 + 0x164) = *(int *)(param_1 + 0x164) + iVar3;
    if (param_2 < 4) {
      *(undefined4 *)(param_1 + 0x1a0) = 1;
      return;
    }
    *(undefined4 *)(param_1 + 0x1a0) = 0;
  }
switchD_004e8d55_default:
  return;
}

// --------------------------------------------------

// Function: FUN_004e90e9
// Address: 004e90e9
// XREFS: None
// [HELPER] s_: ""
/* WARNING: Unable to track spacebase fully for stack */

StrategyAIModule * FUN_004e90e9(void)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int unaff_ESI;
  StrategyAIModule *this;
  char *pcVar4;
  undefined4 unaff_EDI;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  int unaff_retaddr;
  
  this = (StrategyAIModule *)(unaff_ESI + -1);
  *(undefined4 *)(unaff_retaddr + -4) = 0xffffffff;
  *(code **)(unaff_retaddr + -8) = FUN_005607b2;
  *(undefined4 *)(unaff_retaddr + -0xc) = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = unaff_retaddr + -0xc;
  *(StrategyAIModule **)(unaff_retaddr + -0x10) = this;
  *(undefined4 *)(unaff_retaddr + -0x14) = unaff_EBX;
  *(undefined4 *)(unaff_retaddr + -0x18) = unaff_EBP;
  *(StrategyAIModule **)(unaff_retaddr + -0x1c) = this;
  *(undefined4 *)(unaff_retaddr + -0x20) = unaff_EDI;
  *(undefined4 *)(unaff_retaddr + -0x24) = *(undefined4 *)(unaff_retaddr + 8);
  *(undefined4 *)(unaff_retaddr + -0x28) = *(undefined4 *)(unaff_retaddr + 4);
  *(StrategyAIModule **)(unaff_retaddr + -0x10) = this;
  *(undefined4 *)(unaff_retaddr + -0x2c) = 0x4e9131;
  StrategyAIModule::StrategyAIModule
            (this,*(void **)(unaff_retaddr + -0x28),*(int *)(unaff_retaddr + -0x24));
  *(undefined4 *)(unaff_ESI + 0xef) = 0;
  *(undefined4 *)(unaff_ESI + 0xf3) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x1fb) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x1ff) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x203) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x207) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x22b) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x22f) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x233) = 0;
  *(undefined4 *)(unaff_retaddr + -4) = 0;
  *(undefined4 *)(unaff_ESI + 0x237) = 0;
  *(undefined4 *)(unaff_ESI + 0x23b) = 0;
  *(undefined4 *)(unaff_ESI + 0x23f) = 0;
  *(undefined4 *)(unaff_ESI + 0x243) = 0;
  *(undefined4 *)(unaff_ESI + 0x247) = 0;
  *(undefined4 *)(unaff_ESI + 0x24b) = 0;
  *(undefined4 *)(unaff_ESI + 0x24f) = 0;
  *(undefined4 *)(unaff_ESI + 0x253) = 0;
  *(undefined4 *)(unaff_ESI + 599) = 0;
  *(undefined4 *)(unaff_ESI + 0x25b) = 0;
  *(undefined4 *)(unaff_ESI + 0x25f) = 0;
  *(undefined4 *)(unaff_ESI + 0x263) = 0;
  *(undefined1 *)(unaff_retaddr + -4) = 3;
  *(undefined4 *)(unaff_retaddr + -0x24) = 0x4e91c8;
  VictoryConditionRuleSystem::VictoryConditionRuleSystem
            ((VictoryConditionRuleSystem *)(unaff_ESI + 0x267));
  *(undefined4 *)(unaff_ESI + 0x20b) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x20f) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x213) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x21b) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x21f) = 0xbf800000;
  *(undefined4 *)(unaff_ESI + 0x223) = 0xbf800000;
  uVar2 = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x5f3) = 0;
  *(undefined ***)this = &TribeStrategyAIModule::_vftable_;
  pcVar4 = s_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = (char *)(unaff_ESI + 0xf7);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_retaddr + -0xc);
  return this;
}

// --------------------------------------------------

// Function: FUN_004e923b
// Address: 004e923b
// XREFS: None
TribeStrategyAIModule * __thiscall FUN_004e923b(TribeStrategyAIModule *param_1,byte param_2)
{
  TribeStrategyAIModule::~TribeStrategyAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e925e
// Address: 004e925e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TribeStrategyAIModule * __thiscall
FUN_004e925e(TribeStrategyAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  TribeStrategyAIModule *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560800;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_10 = param_1;
  StrategyAIModule::StrategyAIModule((StrategyAIModule *)param_1,(void *)0x0,param_2);
  param_1->md = (TribeMainDecisionAIModule *)0x0;
  (param_1->vcRuleSet).value = (int *)0x0;
  (param_1->vcRuleSet).numberValue = 0;
  (param_1->vcRuleSet).desiredNumberValue = 0;
  (param_1->vcRuleSet).maximumSizeValue = 0;
  (param_1->executingRules).value = (int *)0x0;
  (param_1->executingRules).numberValue = 0;
  (param_1->executingRules).desiredNumberValue = 0;
  (param_1->executingRules).maximumSizeValue = 0;
  (param_1->idleRules).value = (int *)0x0;
  (param_1->idleRules).numberValue = 0;
  (param_1->idleRules).desiredNumberValue = 0;
  (param_1->idleRules).maximumSizeValue = 0;
  uStack_4._0_1_ = 3;
  uStack_4._1_3_ = 0;
  VictoryConditionRuleSystem::VictoryConditionRuleSystem(&param_1->vcRules);
  iVar5 = param_3;
  piVar3 = &param_1->difficultyLevel;
  *piVar3 = 0;
  uStack_4 = CONCAT31(uStack_4._1_3_,4);
  param_1->_padding_ = (int)&TribeStrategyAIModule::_vftable_;
  rge_read(param_3,&param_1->currentVictoryConditionValue,4);
  rge_read(iVar5,&param_1->targetIDValue,4);
  rge_read(iVar5,&param_1->secondTargetIDValue,4);
  rge_read(iVar5,&param_1->secondTargetTypeValue,4);
  rge_read(iVar5,&param_1->targetPoint1Value,0x10);
  rge_read(iVar5,&param_1->targetPoint2Value,0x10);
  rge_read(iVar5,&param_1->targetAttributeValue,4);
  rge_read(iVar5,&param_1->targetNumberValue,4);
  rge_read(iVar5,&param_1->victoryConditionChangeTimeout,4);
  if (_DAT_00575690 <= save_game_version) {
    rge_read(iVar5,piVar3,4);
  }
  rge_read(iVar5,&param_2,4);
  rge_read(iVar5,param_1->ruleSetNameValue,param_2);
  param_1->ruleSetNameValue[param_2] = '\0';
  TribeStrategyAIModule::loadRules(param_1,param_1->ruleSetNameValue);
  TribeStrategyAIModule::setDifficultyLevel(param_1,*piVar3);
  rge_read(iVar5,&iStack_18,4);
  iStack_1c = 0;
  if (0 < iStack_18) {
    do {
      rge_read(iVar5,&param_2,4);
      iVar1 = (param_1->vcRuleSet).numberValue;
      iVar2 = 0;
      iStack_14 = param_2;
      if (0 < iVar1) {
        do {
          if ((param_1->vcRuleSet).maximumSizeValue <= iVar2) break;
          if ((param_1->vcRuleSet).value[iVar2] == param_2) goto LAB_004e94fb;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
      }
      if ((param_1->vcRuleSet).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar3 = (int *)operator_new(iVar1 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (param_1->vcRuleSet).maximumSizeValue) {
            do {
              if (iVar1 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (param_1->vcRuleSet).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (param_1->vcRuleSet).maximumSizeValue);
          }
          operator_delete((param_1->vcRuleSet).value);
          (param_1->vcRuleSet).value = piVar3;
          (param_1->vcRuleSet).maximumSizeValue = iVar1;
        }
      }
      (param_1->vcRuleSet).value[(param_1->vcRuleSet).numberValue] = iStack_14;
      (param_1->vcRuleSet).numberValue = (param_1->vcRuleSet).numberValue + 1;
LAB_004e94fb:
      iStack_1c = iStack_1c + 1;
    } while (iStack_1c < iStack_18);
  }
  rge_read(iVar5,&iStack_18,4);
  iStack_1c = 0;
  if (0 < iStack_18) {
    do {
      rge_read(iVar5,&param_2,4);
      iVar1 = (param_1->executingRules).numberValue;
      iVar2 = 0;
      iStack_14 = param_2;
      if (0 < iVar1) {
        do {
          if ((param_1->executingRules).maximumSizeValue <= iVar2) break;
          if ((param_1->executingRules).value[iVar2] == param_2) goto LAB_004e95ff;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
      }
      if ((param_1->executingRules).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar3 = (int *)operator_new(iVar1 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (param_1->executingRules).maximumSizeValue) {
            do {
              if (iVar1 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (param_1->executingRules).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (param_1->executingRules).maximumSizeValue);
          }
          operator_delete((param_1->executingRules).value);
          (param_1->executingRules).value = piVar3;
          (param_1->executingRules).maximumSizeValue = iVar1;
        }
      }
      (param_1->executingRules).value[(param_1->executingRules).numberValue] = iStack_14;
      (param_1->executingRules).numberValue = (param_1->executingRules).numberValue + 1;
LAB_004e95ff:
      iStack_1c = iStack_1c + 1;
    } while (iStack_1c < iStack_18);
  }
  rge_read(iVar5,&iStack_18,4);
  iStack_1c = 0;
  if (0 < iStack_18) {
    do {
      rge_read(iVar5,&param_2,4);
      iVar1 = param_2;
      iVar5 = (param_1->idleRules).numberValue;
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          if ((param_1->idleRules).maximumSizeValue <= iVar2) break;
          if ((param_1->idleRules).value[iVar2] == param_2) goto LAB_004e9703;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
      if ((param_1->idleRules).maximumSizeValue + -1 < iVar5) {
        iVar5 = iVar5 + 1;
        piVar3 = (int *)operator_new(iVar5 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (param_1->idleRules).maximumSizeValue) {
            do {
              if (iVar5 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (param_1->idleRules).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (param_1->idleRules).maximumSizeValue);
          }
          operator_delete((param_1->idleRules).value);
          (param_1->idleRules).value = piVar3;
          (param_1->idleRules).maximumSizeValue = iVar5;
        }
      }
      (param_1->idleRules).value[(param_1->idleRules).numberValue] = iVar1;
      (param_1->idleRules).numberValue = (param_1->idleRules).numberValue + 1;
LAB_004e9703:
      iStack_1c = iStack_1c + 1;
      iVar5 = param_3;
    } while (iStack_1c < iStack_18);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004e972f
// Address: 004e972f
// XREFS: None
void __fastcall FUN_004e972f(StrategyAIModule *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  pcStack_8 = FUN_00560842;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeStrategyAIModule::_vftable_;
  iStack_4 = 3;
  VictoryConditionRuleSystem::~VictoryConditionRuleSystem
            ((VictoryConditionRuleSystem *)&param_1[2].field_0x88);
  iStack_4._0_1_ = 2;
  if (*(void **)&param_1[2].field_0x78 != (void *)0x0) {
    operator_delete(*(void **)&param_1[2].field_0x78);
    *(undefined4 *)&param_1[2].field_0x78 = 0;
  }
  *(undefined4 *)&param_1[2].field_0x7c = 0;
  *(undefined4 *)&param_1[2].field_0x80 = 0;
  *(undefined4 *)&param_1[2].field_0x84 = 0;
  iStack_4._0_1_ = 1;
  if (*(void **)&param_1[2].field_0x68 != (void *)0x0) {
    operator_delete(*(void **)&param_1[2].field_0x68);
    *(undefined4 *)&param_1[2].field_0x68 = 0;
  }
  *(undefined4 *)&param_1[2].field_0x6c = 0;
  *(undefined4 *)&param_1[2].field_0x70 = 0;
  *(undefined4 *)&param_1[2].field_0x74 = 0;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  if (*(void **)&param_1[2].field_0x58 != (void *)0x0) {
    operator_delete(*(void **)&param_1[2].field_0x58);
    *(undefined4 *)&param_1[2].field_0x58 = 0;
  }
  *(undefined4 *)&param_1[2].field_0x5c = 0;
  *(undefined4 *)&param_1[2].field_0x60 = 0;
  *(undefined4 *)&param_1[2].field_0x64 = 0;
  iStack_4 = 0xffffffff;
  StrategyAIModule::~StrategyAIModule(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004e9818
// Address: 004e9818
// XREFS: None
undefined4 __fastcall FUN_004e9818(TribeStrategyAIModule *param_1)
{
  ManagedArray<int> *pMVar1;
  int iVar2;
  RGE_Victory_Entry *pRVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iStack_8;
  int iStack_4;
  
  iVar7 = 0;
  iVar2 = param_1->victoryConditionChangeTimeout + 1;
  param_1->victoryConditionChangeTimeout = iVar2;
  if (-1 < iVar2) {
    param_1->victoryConditionChangeTimeout = 0;
    uVar8 = 0xb;
    pRVar3 = RGE_Victory_Conditions::condition_raw_info
                       (*(RGE_Victory_Conditions **)(param_1->md->_padding_ + 0x34),0);
    if (pRVar3 != (RGE_Victory_Entry *)0x0) {
      uVar8 = (uint)pRVar3->command;
      if (pRVar3->target_obj != (RGE_Static_Object *)0x0) {
        param_1->targetIDValue = pRVar3->target_obj->id;
        param_1->targetTypeValue = (int)pRVar3->target_obj->master_obj->id;
      }
      if (pRVar3->this_obj != (RGE_Static_Object *)0x0) {
        param_1->secondTargetIDValue = pRVar3->this_obj->id;
        param_1->secondTargetTypeValue = (int)pRVar3->this_obj->master_obj->id;
      }
      (param_1->targetPoint1Value).x = pRVar3->x0;
      (param_1->targetPoint1Value).y = pRVar3->y0;
      (param_1->targetPoint1Value).z = 1.0;
      (param_1->targetPoint2Value).x = pRVar3->x1;
      (param_1->targetPoint2Value).y = pRVar3->y1;
      (param_1->targetPoint2Value).z = 1.0;
      param_1->targetAttributeValue = pRVar3->number;
      param_1->targetNumberValue = pRVar3->count;
    }
    if (uVar8 != param_1->currentVictoryConditionValue) {
      TribeStrategyAIModule::setVictoryCondition(param_1,uVar8);
    }
  }
  iVar2 = 0;
  iStack_8 = -1;
  iVar4 = -1;
  if (0 < (param_1->idleRules).numberValue) {
    pMVar1 = &param_1->idleRules;
    do {
      if ((param_1->idleRules).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar1,iVar7 + 1);
      }
      iVar4 = VictoryConditionRuleSystem::evaluateAsNonInProgress
                        (&param_1->vcRules,param_1->md->aiPlayer,pMVar1->value[iVar7]);
      if (iVar2 < iVar4) {
        if (((param_1->idleRules).maximumSizeValue + -1 < iVar7) &&
           (piVar5 = (int *)operator_new(iVar7 * 4 + 4), piVar5 != (int *)0x0)) {
          iVar2 = 0;
          if (0 < (param_1->idleRules).maximumSizeValue) {
            do {
              if (iVar7 + 1 <= iVar2) break;
              iVar6 = iVar2 + 1;
              piVar5[iVar2] = pMVar1->value[iVar2];
              iVar2 = iVar6;
            } while (iVar6 < (param_1->idleRules).maximumSizeValue);
          }
          operator_delete(pMVar1->value);
          pMVar1->value = piVar5;
          (param_1->idleRules).maximumSizeValue = iVar7 + 1;
        }
        iStack_8 = pMVar1->value[iVar7];
        iVar2 = iVar4;
      }
      iVar7 = iVar7 + 1;
      iVar4 = iStack_8;
    } while (iVar7 < (param_1->idleRules).numberValue);
  }
  if ((iVar4 != -1) &&
     (iVar2 = VictoryConditionRuleSystem::execute
                        (&param_1->vcRules,param_1->md->aiPlayer,
                         param_1->currentVictoryConditionValue,iVar4), iVar2 == 1)) {
    iVar2 = (param_1->executingRules).numberValue;
    pMVar1 = &param_1->executingRules;
    iVar7 = 0;
    if (0 < iVar2) {
      do {
        if ((param_1->executingRules).maximumSizeValue <= iVar7) break;
        if (pMVar1->value[iVar7] == iVar4) goto LAB_004e9a47;
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar2);
    }
    if ((param_1->executingRules).maximumSizeValue + -1 < iVar2) {
      ManagedArray<int>::resize(pMVar1,iVar2 + 1);
    }
    pMVar1->value[(param_1->executingRules).numberValue] = iVar4;
    (param_1->executingRules).numberValue = (param_1->executingRules).numberValue + 1;
LAB_004e9a47:
    iVar2 = (param_1->idleRules).maximumSizeValue;
    iVar7 = 0;
    if (0 < iVar2) {
      piVar5 = (param_1->idleRules).value;
      do {
        if (*piVar5 == iVar4) break;
        iVar7 = iVar7 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar7 < iVar2);
    }
    if (iVar7 < iVar2) {
      if (iVar7 < iVar2 + -1) {
        do {
          piVar5 = (param_1->idleRules).value;
          iVar2 = iVar7 + 1;
          piVar5[iVar7] = piVar5[iVar2];
          iVar7 = iVar2;
        } while (iVar2 < (param_1->idleRules).maximumSizeValue + -1);
      }
      iVar2 = (param_1->idleRules).numberValue + -1;
      (param_1->idleRules).numberValue = iVar2;
      if (iVar2 < 0) {
        (param_1->idleRules).numberValue = 0;
      }
    }
  }
  iVar7 = 0;
  iStack_4 = -1;
  iStack_8 = 0x65;
  iVar2 = -1;
  if (0 < (param_1->executingRules).numberValue) {
    pMVar1 = &param_1->executingRules;
    do {
      if (((param_1->executingRules).maximumSizeValue + -1 < iVar7) &&
         (piVar5 = (int *)operator_new(iVar7 * 4 + 4), piVar5 != (int *)0x0)) {
        iVar2 = 0;
        if (0 < (param_1->executingRules).maximumSizeValue) {
          do {
            if (iVar7 + 1 <= iVar2) break;
            iVar4 = iVar2 + 1;
            piVar5[iVar2] = pMVar1->value[iVar2];
            iVar2 = iVar4;
          } while (iVar4 < (param_1->executingRules).maximumSizeValue);
        }
        operator_delete(pMVar1->value);
        pMVar1->value = piVar5;
        (param_1->executingRules).maximumSizeValue = iVar7 + 1;
      }
      iVar2 = VictoryConditionRuleSystem::evaluateAsInProgress
                        (&param_1->vcRules,param_1->md->aiPlayer,pMVar1->value[iVar7]);
      if (iVar2 < iStack_8) {
        if ((param_1->executingRules).maximumSizeValue + -1 < iVar7) {
          ManagedArray<int>::resize(pMVar1,iVar7 + 1);
        }
        iStack_4 = pMVar1->value[iVar7];
        iStack_8 = iVar2;
      }
      iVar7 = iVar7 + 1;
      iVar2 = iStack_4;
    } while (iVar7 < (param_1->executingRules).numberValue);
  }
  if ((iVar2 != -1) &&
     (iVar7 = VictoryConditionRuleSystem::stopExecution
                        (&param_1->vcRules,param_1->md->aiPlayer,iVar2), iVar7 == 1)) {
    iVar7 = (param_1->executingRules).maximumSizeValue;
    iVar4 = 0;
    if (0 < iVar7) {
      piVar5 = (param_1->executingRules).value;
      do {
        if (*piVar5 == iVar2) break;
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < iVar7);
    }
    if (iVar4 < iVar7) {
      if (iVar4 < iVar7 + -1) {
        do {
          piVar5 = (param_1->executingRules).value;
          iVar7 = iVar4 + 1;
          piVar5[iVar4] = piVar5[iVar7];
          iVar4 = iVar7;
        } while (iVar7 < (param_1->executingRules).maximumSizeValue + -1);
      }
      iVar7 = (param_1->executingRules).numberValue + -1;
      (param_1->executingRules).numberValue = iVar7;
      if (iVar7 < 0) {
        (param_1->executingRules).numberValue = 0;
      }
    }
    iVar7 = (param_1->idleRules).numberValue;
    pMVar1 = &param_1->idleRules;
    iVar4 = 0;
    if (0 < iVar7) {
      do {
        if ((param_1->idleRules).maximumSizeValue <= iVar4) break;
        if (pMVar1->value[iVar4] == iVar2) goto LAB_004e9c3d;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar7);
    }
    if ((param_1->idleRules).maximumSizeValue + -1 < iVar7) {
      ManagedArray<int>::resize(pMVar1,iVar7 + 1);
    }
    pMVar1->value[(param_1->idleRules).numberValue] = iVar2;
    (param_1->idleRules).numberValue = (param_1->idleRules).numberValue + 1;
  }
LAB_004e9c3d:
  iVar2 = 0;
  if (0 < (param_1->vcRuleSet).numberValue) {
    do {
      if ((param_1->vcRuleSet).maximumSizeValue + -1 < iVar2) {
        piVar5 = (int *)operator_new(iVar2 * 4 + 4);
        if (piVar5 != (int *)0x0) {
          iVar7 = 0;
          if (0 < (param_1->vcRuleSet).maximumSizeValue) {
            do {
              if (iVar2 + 1 <= iVar7) break;
              iVar4 = iVar7 + 1;
              piVar5[iVar7] = (param_1->vcRuleSet).value[iVar7];
              iVar7 = iVar4;
            } while (iVar4 < (param_1->vcRuleSet).maximumSizeValue);
          }
          operator_delete((param_1->vcRuleSet).value);
          (param_1->vcRuleSet).value = piVar5;
          (param_1->vcRuleSet).maximumSizeValue = iVar2 + 1;
        }
      }
      iVar7 = VictoryConditionRuleSystem::evaluateAsNonInProgress
                        (&param_1->vcRules,param_1->md->aiPlayer,(param_1->vcRuleSet).value[iVar2]);
      if (iVar7 == -1) {
        if ((param_1->vcRuleSet).maximumSizeValue + -1 < iVar2) {
          piVar5 = (int *)operator_new(iVar2 * 4 + 4);
          if (piVar5 != (int *)0x0) {
            iVar7 = 0;
            if (0 < (param_1->vcRuleSet).maximumSizeValue) {
              do {
                if (iVar2 + 1 <= iVar7) break;
                iVar4 = iVar7 + 1;
                piVar5[iVar7] = (param_1->vcRuleSet).value[iVar7];
                iVar7 = iVar4;
              } while (iVar4 < (param_1->vcRuleSet).maximumSizeValue);
            }
            operator_delete((param_1->vcRuleSet).value);
            (param_1->vcRuleSet).value = piVar5;
            (param_1->vcRuleSet).maximumSizeValue = iVar2 + 1;
          }
        }
        VictoryConditionRuleSystem::execute
                  (&param_1->vcRules,param_1->md->aiPlayer,param_1->currentVictoryConditionValue,
                   (param_1->vcRuleSet).value[iVar2]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (param_1->vcRuleSet).numberValue);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e9d8f
// Address: 004e9d8f
// XREFS: None
void __thiscall FUN_004e9d8f(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004e9d9d
// Address: 004e9d9d
// XREFS: None
undefined4 __thiscall FUN_004e9d9d(int param_1,int param_2)
{
  char cVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iStack_108;
  char acStack_104 [260];
  
  rge_write(param_2,(void *)(param_1 + 0xf4),4);
  rge_write(param_2,(void *)(param_1 + 0x1fc),4);
  rge_write(param_2,(void *)(param_1 + 0x204),4);
  rge_write(param_2,(void *)(param_1 + 0x208),4);
  rge_write(param_2,(void *)(param_1 + 0x20c),0x10);
  rge_write(param_2,(void *)(param_1 + 0x21c),0x10);
  rge_write(param_2,(void *)(param_1 + 0x22c),4);
  rge_write(param_2,(void *)(param_1 + 0x230),4);
  rge_write(param_2,(void *)(param_1 + 0x234),4);
  rge_write(param_2,(void *)(param_1 + 0x5f4),4);
  uVar4 = 0xffffffff;
  pcVar6 = (char *)(param_1 + 0xf8);
  do {
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar7 + -uVar4;
  pcVar7 = acStack_104;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar6 = acStack_104;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iStack_108 = ~uVar4 - 1;
  rge_write(param_2,&iStack_108,4);
  uVar4 = 0xffffffff;
  pcVar6 = acStack_104;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  rge_write(param_2,acStack_104,~uVar4 - 1);
  iStack_108 = *(int *)(param_1 + 0x23c);
  rge_write(param_2,&iStack_108,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x23c)) {
    do {
      if ((*(int *)(param_1 + 0x244) + -1 < iVar8) &&
         (pvVar2 = operator_new(iVar8 * 4 + 4), pvVar2 != (void *)0x0)) {
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x244)) {
          do {
            if (iVar8 + 1 <= iVar3) break;
            iVar3 = iVar3 + 1;
            *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x238) + -4 + iVar3 * 4);
          } while (iVar3 < *(int *)(param_1 + 0x244));
        }
        operator_delete(*(void **)(param_1 + 0x238));
        *(void **)(param_1 + 0x238) = pvVar2;
        *(int *)(param_1 + 0x244) = iVar8 + 1;
      }
      iStack_108 = *(int *)(*(int *)(param_1 + 0x238) + iVar8 * 4);
      rge_write(param_2,&iStack_108,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x23c));
  }
  iStack_108 = *(int *)(param_1 + 0x24c);
  rge_write(param_2,&iStack_108,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x24c)) {
    do {
      if ((*(int *)(param_1 + 0x254) + -1 < iVar8) &&
         (pvVar2 = operator_new(iVar8 * 4 + 4), pvVar2 != (void *)0x0)) {
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x254)) {
          do {
            if (iVar8 + 1 <= iVar3) break;
            iVar3 = iVar3 + 1;
            *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x248) + -4 + iVar3 * 4);
          } while (iVar3 < *(int *)(param_1 + 0x254));
        }
        operator_delete(*(void **)(param_1 + 0x248));
        *(void **)(param_1 + 0x248) = pvVar2;
        *(int *)(param_1 + 0x254) = iVar8 + 1;
      }
      iStack_108 = *(int *)(*(int *)(param_1 + 0x248) + iVar8 * 4);
      rge_write(param_2,&iStack_108,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x24c));
  }
  iStack_108 = *(int *)(param_1 + 0x25c);
  rge_write(param_2,&iStack_108,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x25c)) {
    do {
      if (*(int *)(param_1 + 0x264) + -1 < iVar8) {
        pvVar2 = operator_new(iVar8 * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x264)) {
            do {
              if (iVar8 + 1 <= iVar3) break;
              iVar3 = iVar3 + 1;
              *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 600) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x264));
          }
          operator_delete(*(void **)(param_1 + 600));
          *(void **)(param_1 + 600) = pvVar2;
          *(int *)(param_1 + 0x264) = iVar8 + 1;
        }
      }
      iStack_108 = *(int *)(*(int *)(param_1 + 600) + iVar8 * 4);
      rge_write(param_2,&iStack_108,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x25c));
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ea126
// Address: 004ea126
// XREFS: None
int __fastcall FUN_004ea126(int param_1)
{
  return param_1 + 0xf8;
}

// --------------------------------------------------

// Function: FUN_004ea137
// Address: 004ea137
// XREFS: None
void __thiscall FUN_004ea137(int param_1,int param_2)
{
  if (param_2 == 0) {
    return;
  }
  strncpy((char *)(param_1 + 0xf8),param_2,0xff);
  VictoryConditionRuleSystem::loadRules
            ((VictoryConditionRuleSystem *)(param_1 + 0x268),(char *)(param_1 + 0xf8));
  return;
}

// --------------------------------------------------

// Function: FUN_004ea176
// Address: 004ea176
// XREFS: None
// [HELPER] s_Setting_SN__d__to__d_: "Setting SN[%d] to %d."
void __thiscall FUN_004ea176(AIModule *param_1,int param_2,int param_3)
{
  AIModule::logCommonHistory(param_1,(char *)param_1,s_Setting_SN__d__to__d_,param_2,param_3);
  VictoryConditionRuleSystem::setRule
            ((VictoryConditionRuleSystem *)(param_1[2].playerNameValue + 0x38),param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004ea1c3
// Address: 004ea1c3
// XREFS: None
void __thiscall FUN_004ea1c3(int param_1,int param_2)
{
  VictoryConditionRuleSystem::modifyForDifficultyLevel
            ((VictoryConditionRuleSystem *)(param_1 + 0x268),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004ea1e3
// Address: 004ea1e3
// XREFS: None
undefined4 __fastcall FUN_004ea1e3(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf4);
}

// --------------------------------------------------

// Function: FUN_004ea1f7
// Address: 004ea1f7
// XREFS: None
undefined4 __fastcall FUN_004ea1f7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1fc);
}

// --------------------------------------------------

// Function: FUN_004ea207
// Address: 004ea207
// XREFS: None
undefined4 __fastcall FUN_004ea207(int param_1)
{
  return *(undefined4 *)(param_1 + 0x200);
}

// --------------------------------------------------

// Function: FUN_004ea217
// Address: 004ea217
// XREFS: None
undefined4 __fastcall FUN_004ea217(int param_1)
{
  return *(undefined4 *)(param_1 + 0x204);
}

// --------------------------------------------------

// Function: FUN_004ea227
// Address: 004ea227
// XREFS: None
undefined4 __fastcall FUN_004ea227(int param_1)
{
  return *(undefined4 *)(param_1 + 0x208);
}

// --------------------------------------------------

// Function: FUN_004ea237
// Address: 004ea237
// XREFS: None
int __fastcall FUN_004ea237(int param_1)
{
  return param_1 + 0x20c;
}

// --------------------------------------------------

// Function: FUN_004ea247
// Address: 004ea247
// XREFS: None
int __fastcall FUN_004ea247(int param_1)
{
  return param_1 + 0x21c;
}

// --------------------------------------------------

// Function: FUN_004ea257
// Address: 004ea257
// XREFS: None
undefined4 __fastcall FUN_004ea257(int param_1)
{
  return *(undefined4 *)(param_1 + 0x22c);
}

// --------------------------------------------------

// Function: FUN_004ea267
// Address: 004ea267
// XREFS: None
undefined4 __fastcall FUN_004ea267(int param_1)
{
  return *(undefined4 *)(param_1 + 0x230);
}

// --------------------------------------------------

// Function: FUN_004ea277
// Address: 004ea277
// XREFS: None
void __thiscall FUN_004ea277(int param_1,int param_2)
{
  ManagedArray<int> *this;
  int iVar1;
  int *piVar2;
  ManagedArray<int> *this_00;
  int iVar3;
  
  this = (ManagedArray<int> *)(param_1 + 0x238);
  iVar3 = 0;
  *(int *)(param_1 + 0xf4) = param_2;
  *(undefined4 *)(param_1 + 0x23c) = 0;
  param_2 = 1;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 2;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0xc;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0xd;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0xe;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x10;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x11;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x12;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x15;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x16;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x17;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x18;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  param_2 = 0x19;
  iVar1 = ManagedArray<int>::contains(this,&param_2);
  if (iVar1 != 1) {
    if (*(int *)(param_1 + 0x244) + -1 < *(int *)(param_1 + 0x23c)) {
      ManagedArray<int>::resize(this,*(int *)(param_1 + 0x23c) + 1);
    }
    this->value[*(int *)(param_1 + 0x23c)] = param_2;
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  }
  ManagedArray<int>::add(this,0x1a);
  ManagedArray<int>::add(this,0x1b);
  ManagedArray<int>::add(this,0x1c);
  ManagedArray<int>::add(this,0x1d);
  ManagedArray<int>::add(this,0x1e);
  ManagedArray<int>::add(this,0x1f);
  ManagedArray<int>::add(this,0x20);
  ManagedArray<int>::add(this,0x21);
  ManagedArray<int>::add(this,0x22);
  ManagedArray<int>::add(this,0x23);
  ManagedArray<int>::add(this,0x24);
  ManagedArray<int>::add(this,0x25);
  ManagedArray<int>::add(this,0x26);
  ManagedArray<int>::add(this,0x27);
  ManagedArray<int>::add(this,0x28);
  ManagedArray<int>::add(this,0x29);
  ManagedArray<int>::add(this,0x2a);
  ManagedArray<int>::add(this,0x2b);
  ManagedArray<int>::add(this,0x2c);
  ManagedArray<int>::add(this,0x2d);
  ManagedArray<int>::add(this,0x2e);
  ManagedArray<int>::add(this,0x2f);
  ManagedArray<int>::add(this,0x30);
  ManagedArray<int>::add(this,0x31);
  if (0 < *(int *)(param_1 + 0x23c)) {
    do {
      piVar2 = ManagedArray<int>::operator[](this,iVar3);
      iVar1 = VictoryConditionRuleSystem::evaluateAsNonInProgress
                        ((VictoryConditionRuleSystem *)(param_1 + 0x268),
                         *(TRIBE_Player **)(*(int *)(param_1 + 0xf0) + 0x1256c),*piVar2);
      if (iVar1 == -2) {
        piVar2 = ManagedArray<int>::operator[](this,iVar3);
        iVar1 = VictoryConditionRuleSystem::execute
                          ((VictoryConditionRuleSystem *)(param_1 + 0x268),
                           *(TRIBE_Player **)(*(int *)(param_1 + 0xf0) + 0x1256c),
                           *(int *)(param_1 + 0xf4),*piVar2);
        if (iVar1 == 1) {
          piVar2 = ManagedArray<int>::operator[](this,iVar3);
          iVar1 = *piVar2;
          this_00 = (ManagedArray<int> *)(param_1 + 0x248);
        }
        else {
          piVar2 = ManagedArray<int>::operator[](this,iVar3);
          iVar1 = *piVar2;
          this_00 = (ManagedArray<int> *)(param_1 + 600);
        }
        ManagedArray<int>::add(this_00,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x23c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ea74f
// Address: 004ea74f
// XREFS: None
int __thiscall FUN_004ea74f(int *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_1[3] + -1 < param_2) {
    iVar1 = param_2 + 1;
    pvVar2 = operator_new(iVar1 * 4);
    if (pvVar2 != (void *)0x0) {
      iVar3 = 0;
      if (0 < param_1[3]) {
        do {
          if (iVar1 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) = *(undefined4 *)(*param_1 + -4 + iVar3 * 4)
          ;
        } while (iVar3 < param_1[3]);
      }
      operator_delete((void *)*param_1);
      *param_1 = (int)pvVar2;
      param_1[3] = iVar1;
    }
  }
  return *param_1 + param_2 * 4;
}

// --------------------------------------------------

// Function: FUN_004ea7b6
// Address: 004ea7b6
// XREFS: None
undefined4 __thiscall FUN_004ea7b6(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x24c)) {
    while (iVar1 < *(int *)(param_1 + 0x254)) {
      if (*(int *)(*(int *)(param_1 + 0x248) + iVar1 * 4) == param_2) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      if (*(int *)(param_1 + 0x24c) <= iVar1) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ea808
// Address: 004ea808
// XREFS: None
undefined4 __thiscall FUN_004ea808(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x25c)) {
    while (iVar1 < *(int *)(param_1 + 0x264)) {
      if (*(int *)(*(int *)(param_1 + 600) + iVar1 * 4) == param_2) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      if (*(int *)(param_1 + 0x25c) <= iVar1) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ea858
// Address: 004ea858
// XREFS: None
TacticalAIGroup * __fastcall FUN_004ea858(TacticalAIGroup *param_1)
{
  int *piVar1;
  int iVar2;
  
  param_1->idValue = -1;
  param_1->inUseValue = 0;
  param_1->typeValue = -1;
  param_1->subTypeValue = -1;
  param_1->numberUnitsValue = 0;
  param_1->desiredNumberUnitsValue = 0;
  param_1->commanderValue = -1;
  param_1->originalHitPointsValue = -1;
  param_1->originalUnitNumberValue = -1;
  param_1->actionValue = 0;
  param_1->targetValue = -1;
  param_1->targetTypeValue = -1;
  param_1->priorityValue = 0;
  param_1->waitCodeValue = -1;
  param_1->assistGroupIDValue = -1;
  param_1->assistGroupTypeValue = -1;
  param_1->consecutiveIdleUnitCountValue = 0;
  param_1->playNumberValue = -1;
  param_1->numberAttackWaypointsValue = '\0';
  param_1->currentAttackWaypointValue = '\0';
  param_1->consecutiveGatherAttemptsValue = '\0';
  param_1->numberObjectsToDestroyValue = 0;
  param_1->objectsToDestroyOwnerValue = -1;
  param_1->objectsToDestroyCommanderZoneValue = -1;
  param_1->lastAttackRoundupTime = 0;
  param_1->lastAddedUnitTimeValue = 0;
  param_1->_padding_ = (int)&TacticalAIGroup::_vftable_;
  TacticalAIGroup::setTargetLocation(param_1,-1.0,-1.0,-1.0);
  TacticalAIGroup::setGatherLocation(param_1,-1.0,-1.0,-1.0);
  TacticalAIGroup::setRetreatLocation(param_1,-1.0,-1.0,-1.0);
  TacticalAIGroup::setLocation(param_1,-1.0,-1.0,-1.0);
  piVar1 = param_1->unitsOriginalHitPointsValue;
  iVar2 = 0x28;
  do {
    piVar1[-0x28] = -1;
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar1 = param_1->objectsToDestroyValue;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ea984
// Address: 004ea984
// XREFS: None
TacticalAIGroup * __thiscall FUN_004ea984(TacticalAIGroup *param_1,byte param_2)
{
  TacticalAIGroup::~TacticalAIGroup(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ea9ae
// Address: 004ea9ae
// XREFS: None
void __fastcall FUN_004ea9ae(undefined4 *param_1)
{
  *param_1 = &TacticalAIGroup::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_004ea9b7
// Address: 004ea9b7
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004ea9b7(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  
  rge_read(param_2,(void *)(param_1 + 0xc),4);
  rge_read(param_2,(void *)(param_1 + 0x10),4);
  pvVar1 = (void *)(param_1 + 0xbc);
  iVar2 = 0x28;
  do {
    rge_read(param_2,(void *)((int)pvVar1 + -0xa0),4);
    rge_read(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  rge_read(param_2,(void *)(param_1 + 0x15c),4);
  rge_read(param_2,(void *)(param_1 + 0x160),4);
  rge_read(param_2,(void *)(param_1 + 0x164),4);
  rge_read(param_2,(void *)(param_1 + 0x168),4);
  rge_read(param_2,(void *)(param_1 + 0x16c),4);
  rge_read(param_2,(void *)(param_1 + 0x170),0x10);
  rge_read(param_2,(void *)(param_1 + 0x180),4);
  rge_read(param_2,(void *)(param_1 + 0x184),4);
  rge_read(param_2,(void *)(param_1 + 0x188),4);
  rge_read(param_2,(void *)(param_1 + 0x18c),0x10);
  rge_read(param_2,(void *)(param_1 + 0x19c),0x10);
  rge_read(param_2,(void *)(param_1 + 0x1ac),0x10);
  rge_read(param_2,(void *)(param_1 + 0x1bc),4);
  rge_read(param_2,(void *)(param_1 + 0x1c0),4);
  rge_read(param_2,(void *)(param_1 + 0x1c4),4);
  rge_read(param_2,(void *)(param_1 + 0x1c8),4);
  rge_read(param_2,(void *)(param_1 + 0x14),4);
  rge_read(param_2,(void *)(param_1 + 0x18),4);
  rge_read(param_2,(void *)(param_1 + 0x1cc),4);
  rge_read(param_2,(void *)(param_1 + 0x1d4),1);
  rge_read(param_2,(void *)(param_1 + 0x1d5),1);
  rge_read(param_2,(void *)(param_1 + 0x1d8),0xf0);
  rge_read(param_2,(void *)(param_1 + 0x1d0),4);
  if (save_game_version < _DAT_005756e0) {
    *(undefined1 *)(param_1 + 0x2c8) = 0;
  }
  else {
    rge_read(param_2,(void *)(param_1 + 0x2c8),1);
  }
  if (_DAT_005756e4 <= save_game_version) {
    rge_read(param_2,(void *)(param_1 + 0x2cc),4);
    rge_read(param_2,(void *)(param_1 + 0x2d0),0x50);
    rge_read(param_2,(void *)(param_1 + 800),4);
    rge_read(param_2,(void *)(param_1 + 0x324),4);
  }
  if (_DAT_005756e8 <= save_game_version) {
    rge_read(param_2,(void *)(param_1 + 0x328),4);
  }
  if (_DAT_005756ec <= save_game_version) {
    rge_read(param_2,(void *)(param_1 + 0x32c),4);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004eac91
// Address: 004eac91
// XREFS: None
undefined4 __thiscall FUN_004eac91(int param_1,int param_2)
{
  void *pvVar1;
  int iVar2;
  
  rge_write(param_2,(void *)(param_1 + 0xc),4);
  rge_write(param_2,(void *)(param_1 + 0x10),4);
  pvVar1 = (void *)(param_1 + 0xbc);
  iVar2 = 0x28;
  do {
    rge_write(param_2,(void *)((int)pvVar1 + -0xa0),4);
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  rge_write(param_2,(void *)(param_1 + 0x15c),4);
  rge_write(param_2,(void *)(param_1 + 0x160),4);
  rge_write(param_2,(void *)(param_1 + 0x164),4);
  rge_write(param_2,(void *)(param_1 + 0x168),4);
  rge_write(param_2,(void *)(param_1 + 0x16c),4);
  rge_write(param_2,(void *)(param_1 + 0x170),0x10);
  rge_write(param_2,(void *)(param_1 + 0x180),4);
  rge_write(param_2,(void *)(param_1 + 0x184),4);
  rge_write(param_2,(void *)(param_1 + 0x188),4);
  rge_write(param_2,(void *)(param_1 + 0x18c),0x10);
  rge_write(param_2,(void *)(param_1 + 0x19c),0x10);
  rge_write(param_2,(void *)(param_1 + 0x1ac),0x10);
  rge_write(param_2,(void *)(param_1 + 0x1bc),4);
  rge_write(param_2,(void *)(param_1 + 0x1c0),4);
  rge_write(param_2,(void *)(param_1 + 0x1c4),4);
  rge_write(param_2,(void *)(param_1 + 0x1c8),4);
  rge_write(param_2,(void *)(param_1 + 0x14),4);
  rge_write(param_2,(void *)(param_1 + 0x18),4);
  rge_write(param_2,(void *)(param_1 + 0x1cc),4);
  rge_write(param_2,(void *)(param_1 + 0x1d4),1);
  rge_write(param_2,(void *)(param_1 + 0x1d5),1);
  rge_write(param_2,(void *)(param_1 + 0x1d8),0xf0);
  rge_write(param_2,(void *)(param_1 + 0x1d0),4);
  rge_write(param_2,(void *)(param_1 + 0x2c8),1);
  rge_write(param_2,(void *)(param_1 + 0x2cc),4);
  rge_write(param_2,(void *)(param_1 + 0x2d0),0x50);
  rge_write(param_2,(void *)(param_1 + 800),4);
  rge_write(param_2,(void *)(param_1 + 0x324),4);
  rge_write(param_2,(void *)(param_1 + 0x328),4);
  rge_write(param_2,(void *)(param_1 + 0x32c),4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004eaf1c
// Address: 004eaf1c
// XREFS: None
undefined4 __fastcall FUN_004eaf1c(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_004eaf24
// Address: 004eaf24
// XREFS: None
void __thiscall FUN_004eaf24(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eaf3a
// Address: 004eaf3a
// XREFS: None
undefined4 __fastcall FUN_004eaf3a(int param_1)
{
  return *(undefined4 *)(param_1 + 0x10);
}

// --------------------------------------------------

// Function: FUN_004eaf44
// Address: 004eaf44
// XREFS: None
void __thiscall FUN_004eaf44(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eaf5a
// Address: 004eaf5a
// XREFS: None
undefined4 __fastcall FUN_004eaf5a(int param_1)
{
  return *(undefined4 *)(param_1 + 0x14);
}

// --------------------------------------------------

// Function: FUN_004eaf64
// Address: 004eaf64
// XREFS: None
void __thiscall FUN_004eaf64(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eaf7a
// Address: 004eaf7a
// XREFS: None
undefined4 __fastcall FUN_004eaf7a(int param_1)
{
  return *(undefined4 *)(param_1 + 0x18);
}

// --------------------------------------------------

// Function: FUN_004eaf84
// Address: 004eaf84
// XREFS: None
void __thiscall FUN_004eaf84(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eaf9a
// Address: 004eaf9a
// XREFS: None
undefined4 __thiscall FUN_004eaf9a(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x1c);
  do {
    if (*piVar2 == -1) {
      *(undefined4 *)(param_1 + 0x1c + iVar1 * 4) = param_2;
      *(undefined4 *)(param_1 + 0xbc + iVar1 * 4) = 0xffffffff;
      *(int *)(param_1 + 0x15c) = *(int *)(param_1 + 0x15c) + 1;
      if (*(int *)(param_1 + 0x164) != -1) {
        (**(code **)(**(int **)(param_3 + 0xf0) + 200))
                  (*(int *)(param_1 + 0x164),param_2,0x40800000);
      }
      *(undefined4 *)(param_1 + 0x32c) =
           *(undefined4 *)(*(int *)(*(int *)(param_3 + 0xf0) + 0x3c) + 4);
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x28);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004eb021
// Address: 004eb021
// XREFS: None
undefined4 __thiscall
FUN_004eb021(TacticalAIGroup *param_1,int param_2,TribeMainDecisionAIModule *param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = param_1->unitsValue;
  do {
    if (*piVar2 == param_2) {
      iVar1 = param_1->commanderValue;
      if (param_2 == iVar1) {
        TacticalAIGroup::setSpecificCommander(param_1,-1,param_3);
      }
      else if (iVar1 != -1) {
        (**(code **)(*(int *)param_3->_padding_ + 0xcc))(iVar1,param_2);
      }
      param_1->unitsValue[iVar3] = -1;
      param_1->unitsOriginalHitPointsValue[iVar3] = -1;
      param_1->numberUnitsValue = param_1->numberUnitsValue + -1;
      return 1;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 0x28);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004eb0b1
// Address: 004eb0b1
// XREFS: None
undefined4 __thiscall
FUN_004eb0b1(TacticalAIGroup *param_1,int param_2,TribeMainDecisionAIModule *param_3)
{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < 0x28)) {
    iVar1 = param_1->commanderValue;
    if (param_1->unitsValue[param_2] == iVar1) {
      TacticalAIGroup::setSpecificCommander(param_1,-1,param_3);
    }
    else if (iVar1 != -1) {
      (**(code **)(*(int *)param_3->_padding_ + 0xcc))(iVar1,param_1->unitsValue[param_2]);
    }
    param_1->unitsValue[param_2] = -1;
    param_1->unitsOriginalHitPointsValue[param_2] = -1;
    param_1->numberUnitsValue = param_1->numberUnitsValue + -1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004eb13a
// Address: 004eb13a
// XREFS: None
void __thiscall FUN_004eb13a(TacticalAIGroup *param_1,TribeMainDecisionAIModule *param_2)
{
  int *piVar1;
  int iVar2;
  
  TacticalAIGroup::setSpecificCommander(param_1,-1,param_2);
  param_1->numberUnitsValue = 0;
  piVar1 = param_1->unitsOriginalHitPointsValue;
  iVar2 = 0x28;
  do {
    piVar1[-0x28] = -1;
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_004eb17a
// Address: 004eb17a
// XREFS: None
undefined4 __thiscall FUN_004eb17a(TacticalAIGroup *param_1,TribeMainDecisionAIModule *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = param_1->numberUnitsValue;
  if ((param_1->desiredNumberUnitsValue < iVar1) && (0 < iVar1)) {
    iVar3 = 0;
    if (param_1->desiredNumberUnitsValue < iVar1) {
      piVar2 = param_1->unitsValue;
      do {
        if (0x27 < iVar3) {
          return 1;
        }
        if (*piVar2 != -1) {
          TacticalAIGroup::removeUnitByIndex(param_1,iVar3,param_2);
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (param_1->desiredNumberUnitsValue < param_1->numberUnitsValue);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004eb1e3
// Address: 004eb1e3
// XREFS: None
undefined4 __thiscall
FUN_004eb1e3(TacticalAIGroup *param_1,TribeTacticalAIModule *param_2,
            TribeMainDecisionAIModule *param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int *piVar3;
  int iStack_4;
  
  iStack_4 = 0x28;
  piVar3 = param_1->unitsValue;
  do {
    if (*piVar3 != -1) {
      pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar3);
      if ((pRVar2 == (RGE_Static_Object *)0x0) || (pRVar2->inside_obj == (RGE_Static_Object *)0x0))
{
        iVar1 = param_1->commanderValue;
        if (*piVar3 == iVar1) {
          TacticalAIGroup::setSpecificCommander(param_1,-1,param_3);
        }
        else if (iVar1 != -1) {
          (**(code **)(*(int *)param_3->_padding_ + 0xcc))(iVar1,*piVar3);
        }
        TribeTacticalAIModule::stopUnit(param_2,*piVar3,100);
        *piVar3 = -1;
        piVar3[0x28] = -1;
        param_1->numberUnitsValue = param_1->numberUnitsValue + -1;
      }
    }
    piVar3 = piVar3 + 1;
    iStack_4 = iStack_4 + -1;
  } while (iStack_4 != 0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004eb28c
// Address: 004eb28c
// XREFS: None
undefined4 __thiscall FUN_004eb28c(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x1c);
  do {
    if (*piVar2 == param_2) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x28);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004eb2b3
// Address: 004eb2b3
// XREFS: None
undefined4 __fastcall FUN_004eb2b3(int param_1)
{
  return *(undefined4 *)(param_1 + 0x15c);
}

// --------------------------------------------------

// Function: FUN_004eb2c7
// Address: 004eb2c7
// XREFS: None
int __thiscall FUN_004eb2c7(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = -1;
  piVar2 = (int *)(param_1 + 0x1c);
  while( true ) {
    if (param_2 + 1 <= iVar3) {
      return -1;
    }
    if (*piVar2 != -1) {
      iVar3 = iVar3 + 1;
    }
    if (iVar3 == param_2) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
    if (0x27 < iVar1) {
      return -1;
    }
  }
  return ((int *)(param_1 + 0x1c))[iVar1];
}

// --------------------------------------------------

// Function: FUN_004eb316
// Address: 004eb316
// XREFS: None
undefined4 __thiscall FUN_004eb316(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = -1;
  piVar2 = (int *)(param_1 + 0x1c);
  while( true ) {
    if (param_2 + 1 <= iVar3) {
      return 0xffffffff;
    }
    if (*piVar2 != -1) {
      iVar3 = iVar3 + 1;
    }
    if (iVar3 == param_2) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
    if (0x27 < iVar1) {
      return 0xffffffff;
    }
  }
  return *(undefined4 *)(param_1 + 0xbc + iVar1 * 4);
}

// --------------------------------------------------

// Function: FUN_004eb368
// Address: 004eb368
// XREFS: None
undefined4 __fastcall FUN_004eb368(int param_1)
{
  return *(undefined4 *)(param_1 + 0x160);
}

// --------------------------------------------------

// Function: FUN_004eb377
// Address: 004eb377
// XREFS: None
void __thiscall FUN_004eb377(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x160) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb38d
// Address: 004eb38d
// XREFS: None
undefined4 __fastcall FUN_004eb38d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x164);
}

// --------------------------------------------------

// Function: FUN_004eb397
// Address: 004eb397
// XREFS: None
void __thiscall FUN_004eb397(int param_1,int param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int aiStack_a0 [40];
  
  if (*(int *)(param_1 + 0x164) != -1) {
    (**(code **)(**(int **)(param_3 + 0xf0) + 0xd0))(*(int *)(param_1 + 0x164));
  }
  *(int *)(param_1 + 0x164) = param_2;
  if (param_2 != -1) {
    piVar2 = (int *)(param_1 + 0x1c);
    iVar5 = 0;
    piVar3 = aiStack_a0;
    iVar4 = 0x28;
    do {
      iVar1 = *piVar2;
      *piVar3 = iVar1;
      if (iVar1 != -1) {
        iVar5 = iVar5 + 1;
        piVar3 = piVar3 + 1;
      }
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    (**(code **)(**(int **)(param_3 + 0xf0) + 0xc4))(param_2,aiStack_a0,iVar5,0x40800000);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004eb427
// Address: 004eb427
// XREFS: None
int __thiscall FUN_004eb427(int param_1,MainDecisionAIModule *param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  piVar5 = (int *)(param_1 + 0x1c);
  iVar3 = 0x28;
  do {
    if (*piVar5 != -1) {
      pRVar1 = MainDecisionAIModule::object(param_2,*piVar5);
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        iVar2 = __ftol();
        iVar4 = iVar4 + iVar2;
      }
    }
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar4;
}

// --------------------------------------------------

// Function: FUN_004eb46e
// Address: 004eb46e
// XREFS: None
undefined4 __fastcall FUN_004eb46e(int param_1)
{
  return *(undefined4 *)(param_1 + 0x168);
}

// --------------------------------------------------

// Function: FUN_004eb477
// Address: 004eb477
// XREFS: None
void __thiscall FUN_004eb477(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x168) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb48d
// Address: 004eb48d
// XREFS: None
undefined4 __fastcall FUN_004eb48d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x16c);
}

// --------------------------------------------------

// Function: FUN_004eb497
// Address: 004eb497
// XREFS: None
void __thiscall FUN_004eb497(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x16c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb4ad
// Address: 004eb4ad
// XREFS: None
int __fastcall FUN_004eb4ad(int param_1)
{
  return param_1 + 0x170;
}

// --------------------------------------------------

// Function: FUN_004eb4b7
// Address: 004eb4b7
// XREFS: None
void __thiscall FUN_004eb4b7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x170) = param_2;
  *(undefined4 *)(param_1 + 0x174) = param_3;
  *(undefined4 *)(param_1 + 0x178) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb4e1
// Address: 004eb4e1
// XREFS: None
undefined4 __fastcall FUN_004eb4e1(int param_1)
{
  return *(undefined4 *)(param_1 + 0x180);
}

// --------------------------------------------------

// Function: FUN_004eb4f7
// Address: 004eb4f7
// XREFS: None
void __thiscall FUN_004eb4f7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x180) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb50d
// Address: 004eb50d
// XREFS: None
undefined4 __fastcall FUN_004eb50d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x184);
}

// --------------------------------------------------

// Function: FUN_004eb517
// Address: 004eb517
// XREFS: None
void __thiscall FUN_004eb517(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x184) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb52d
// Address: 004eb52d
// XREFS: None
undefined4 __fastcall FUN_004eb52d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x188);
}

// --------------------------------------------------

// Function: FUN_004eb537
// Address: 004eb537
// XREFS: None
void __thiscall FUN_004eb537(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x188) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb54d
// Address: 004eb54d
// XREFS: None
int __fastcall FUN_004eb54d(int param_1)
{
  return param_1 + 0x18c;
}

// --------------------------------------------------

// Function: FUN_004eb557
// Address: 004eb557
// XREFS: None
void __thiscall FUN_004eb557(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x170) = param_2;
  *(undefined4 *)(param_1 + 0x174) = param_3;
  *(undefined4 *)(param_1 + 0x178) = param_4;
  *(undefined4 *)(param_1 + 0x19c) = param_2;
  *(undefined4 *)(param_1 + 0x1a0) = param_3;
  *(undefined4 *)(param_1 + 0x1a4) = param_4;
  *(undefined4 *)(param_1 + 0x1ac) = param_2;
  *(undefined4 *)(param_1 + 0x1b0) = param_3;
  *(undefined4 *)(param_1 + 0x1b4) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb5bd
// Address: 004eb5bd
// XREFS: None
void __thiscall FUN_004eb5bd(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x18c) = param_2;
  *(undefined4 *)(param_1 + 400) = param_3;
  *(undefined4 *)(param_1 + 0x194) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb5e1
// Address: 004eb5e1
// XREFS: None
int __fastcall FUN_004eb5e1(int param_1)
{
  return param_1 + 0x19c;
}

// --------------------------------------------------

// Function: FUN_004eb5f7
// Address: 004eb5f7
// XREFS: None
void __thiscall FUN_004eb5f7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x19c) = param_2;
  *(undefined4 *)(param_1 + 0x1a0) = param_3;
  *(undefined4 *)(param_1 + 0x1a4) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb621
// Address: 004eb621
// XREFS: None
int __fastcall FUN_004eb621(int param_1)
{
  return param_1 + 0x1ac;
}

// --------------------------------------------------

// Function: FUN_004eb637
// Address: 004eb637
// XREFS: None
void __thiscall FUN_004eb637(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x1ac) = param_2;
  *(undefined4 *)(param_1 + 0x1b0) = param_3;
  *(undefined4 *)(param_1 + 0x1b4) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb661
// Address: 004eb661
// XREFS: None
undefined4 __fastcall FUN_004eb661(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1bc);
}

// --------------------------------------------------

// Function: FUN_004eb677
// Address: 004eb677
// XREFS: None
void __thiscall FUN_004eb677(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1bc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb68d
// Address: 004eb68d
// XREFS: None
undefined4 __fastcall FUN_004eb68d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1c0);
}

// --------------------------------------------------

// Function: FUN_004eb697
// Address: 004eb697
// XREFS: None
void __thiscall FUN_004eb697(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb6ad
// Address: 004eb6ad
// XREFS: None
undefined4 __fastcall FUN_004eb6ad(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1c4);
}

// --------------------------------------------------

// Function: FUN_004eb6b7
// Address: 004eb6b7
// XREFS: None
void __thiscall FUN_004eb6b7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1c4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb6cd
// Address: 004eb6cd
// XREFS: None
undefined4 __fastcall FUN_004eb6cd(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1c8);
}

// --------------------------------------------------

// Function: FUN_004eb6d7
// Address: 004eb6d7
// XREFS: None
void __thiscall FUN_004eb6d7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1c8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004eb6ed
// Address: 004eb6ed
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
// [HELPER] s_Entering_task___taskID__d__reset: "Entering task:  taskID=%d, resetOrg=%d, oCA=%d."
// [HELPER] s___Going_to_send_my_units_to_atta: "  Going to send my units to attack roundup targetID=%d."
// [HELPER] s___Going_to_send_my_units_to_defe: "  Going to send my units to defend Uni #%d at (%f, %f)"
// [HELPER] s___Retreat_Position___f___f__: "  Retreat Position=(%f, %f)."
// [HELPER] s___Task_ID__d_is_an_unknown_group: "  Task ID %d is an unknown group task id."
// [HELPER] s_____Checking_on_Unit___d_: "    Checking on Unit #%d:"
// [HELPER] s_____Target_Location___f___f__: "    Target Location=(%f, %f)."
// [HELPER] s_____Using_Attack_with_Play___d_: "    Using Attack with Play #%d."
// [HELPER] s_____We_ve_only_waited__d_seconds: "    We've only waited %d seconds, returning."
// [HELPER] s_____We_ve_waited__d_seconds__che: "    We've waited %d seconds, checking the tasks."
// [HELPER] s_______CurrentAction__d_: "      CurrentAction=%d."
// [HELPER] s_______Tasking_Unit___d_to_move_t: "      Tasking Unit #%d to move to the retreat position."
// [HELPER] s_______Unit___d_is_gone__removing: "      Unit #%d is gone, removing him."
// [HELPER] s_______Unit__d_is_busy_with_an_ac: "      Unit %d is busy with an action already, skipping."
// [HELPER] s_______Unit__d_is_busy_with_an_no: "      Unit %d is busy with an non-wall attack already, skipping."
// [HELPER] s_______Unit__d_is_not_the_command: "      Unit %d is not the commander, tasking him as a defender."
// [HELPER] s_______Unit__d_is_the_commander__: "      Unit %d is the commander, tasking him as explorer."
// [HELPER] s_______Unit__d_is_within_a_tile_o: "      Unit %d is within a tile of the retreat distance, skipping."
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004eb6ed(TacticalAIGroup *param_1,TribeTacticalAIModule *param_2,
            TribeMainDecisionAIModule *param_3,int param_4,TribeTacticalAIModule *param_5,
            int param_6)
{
  TribeInformationAIModule *this;
  byte bVar1;
  bool bVar2;
  uchar uVar3;
  uchar uVar4;
  int iVar5;
  RGE_Static_Object *this_00;
  RGE_Static_Object *pRVar6;
  UnitAIModule *pUVar7;
  int iVar8;
  int *piVar9;
  TribeTacticalAIModule *extraout_ECX;
  TribeTacticalAIModule *extraout_ECX_00;
  TribeTacticalAIModule *extraout_ECX_01;
  TribeTacticalAIModule *extraout_ECX_02;
  TribeTacticalAIModule *extraout_ECX_03;
  TribeTacticalAIModule *extraout_ECX_04;
  TribeTacticalAIModule *extraout_ECX_05;
  TribeTacticalAIModule *extraout_ECX_06;
  TribeTacticalAIModule *extraout_ECX_07;
  TribeTacticalAIModule *extraout_ECX_08;
  TribeTacticalAIModule *extraout_ECX_09;
  TribeTacticalAIModule *this_01;
  TribeTacticalAIModule *extraout_ECX_10;
  TribeTacticalAIModule *extraout_ECX_11;
  TribeTacticalAIModule *extraout_ECX_12;
  TribeTacticalAIModule *extraout_ECX_13;
  TribeTacticalAIModule *extraout_ECX_14;
  TribeTacticalAIModule *extraout_ECX_15;
  TribeTacticalAIModule *this_02;
  TribeTacticalAIModule *extraout_ECX_16;
  TribeTacticalAIModule *extraout_ECX_17;
  TribeTacticalAIModule *extraout_ECX_18;
  TribeTacticalAIModule *this_03;
  TribeTacticalAIModule *pTVar10;
  TribeTacticalAIModule *this_04;
  TribeTacticalAIModule *this_05;
  TribeTacticalAIModule *extraout_ECX_19;
  TribeTacticalAIModule *extraout_ECX_20;
  TribeTacticalAIModule *this_06;
  TribeTacticalAIModule *extraout_ECX_21;
  TribeTacticalAIModule *this_07;
  TribeTacticalAIModule *extraout_ECX_22;
  TribeTacticalAIModule *extraout_ECX_23;
  TribeTacticalAIModule *extraout_ECX_24;
  TribeTacticalAIModule *extraout_ECX_25;
  TribeTacticalAIModule *extraout_ECX_26;
  TribeTacticalAIModule *extraout_ECX_27;
  int *piVar11;
  TribeTacticalAIModule *extraout_ECX_28;
  TribeTacticalAIModule *this_08;
  TribeTacticalAIModule *extraout_ECX_29;
  TribeTacticalAIModule *extraout_ECX_30;
  TribeTacticalAIModule *extraout_ECX_31;
  TribeTacticalAIModule *extraout_ECX_32;
  TribeTacticalAIModule *extraout_ECX_33;
  TribeTacticalAIModule *extraout_ECX_34;
  TribeTacticalAIModule *extraout_ECX_35;
  TribeTacticalAIModule *this_09;
  TribeTacticalAIModule *extraout_ECX_36;
  TribeTacticalAIModule *extraout_ECX_37;
  TribeTacticalAIModule *extraout_ECX_38;
  TribeTacticalAIModule *extraout_ECX_39;
  int *piVar12;
  float fVar13;
  float fVar14;
  TribeTacticalAIModule *pTVar15;
  undefined8 uVar16;
  TribeTacticalAIModule *pTStack_1c;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  pTVar15 = param_2;
  TribeTacticalAIModule::logGroupDebug
            (param_5,(int)param_2,(char *)param_1->idValue,s_Entering_task___taskID__d__reset,
             param_4,param_5);
  pTVar10 = (TribeTacticalAIModule *)param_1->commanderValue;
  if (pTVar10 == (TribeTacticalAIModule *)0xffffffff) {
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)0xffffffff,(int)param_2,(char *)param_1->idValue);
    return 0;
  }
  if ((param_4 != 9) && (param_4 != 0xe)) {
    param_1->consecutiveGatherAttemptsValue = '\0';
  }
  switch(param_4) {
  case 0:
  case 1:
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue);
    param_4 = 0;
    param_6 = 0;
    piVar9 = param_1->unitsValue;
    pTVar10 = extraout_ECX;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar10,(int)param_2,(char *)param_1->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        pTVar10 = extraout_ECX_00;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar10 = extraout_ECX_01,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar10,(int)param_2,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_6,param_3);
          pTVar10 = extraout_ECX_03;
        }
        else {
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          param_4 = param_4 + iVar8;
          TribeTacticalAIModule::stopUnit(param_2,*piVar9,100);
          pTVar10 = extraout_ECX_02;
        }
      }
      piVar9 = piVar9 + 1;
      param_6 = param_6 + 1;
    } while (param_6 < 0x28);
    param_1->inUseValue = 0;
    break;
  case 2:
  case 0x15:
    TribeTacticalAIModule::logGroupDebug
              (pTVar10,(int)param_2,(char *)param_1->idValue,s___Going_to_send_my_units_to_atta,
               param_1->targetValue);
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue,
               s_____Target_Location___f___f__,(double)(param_1->targetLocationValue).x,
               (double)(param_1->targetLocationValue).y);
    if (param_1->playNumberValue == -1) {
      TribeTacticalAIModule::logGroupDebug(this_05,(int)param_2,(char *)param_1->idValue);
    }
    else {
      TribeTacticalAIModule::logGroupDebug
                (this_05,(int)param_2,(char *)param_1->idValue,s_____Using_Attack_with_Play___d_);
    }
    bVar2 = true;
    pTStack_1c = (TribeTacticalAIModule *)0x0;
    param_2 = (TribeTacticalAIModule *)0x0;
    piVar9 = param_1->unitsValue;
    pTVar10 = *(TribeTacticalAIModule **)(*(int *)(param_3->_padding_ + 0x3c) + 4);
    param_1->lastAttackRoundupTime = (ulong)pTVar10;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar10,(int)pTVar15,(char *)param_1->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        pTVar10 = extraout_ECX_19;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar10 = extraout_ECX_20,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar10,(int)pTVar15,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,(int)param_2,param_3);
          pTVar10 = extraout_ECX_27;
        }
        else {
          pUVar7 = RGE_Static_Object::unitAI(pRVar6);
          UnitAIModule::currentAction(pUVar7);
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,(char *)param_1->idValue
                     ,s_______CurrentAction__d_);
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          pTStack_1c = (TribeTacticalAIModule *)((int)&pTStack_1c->_padding_ + iVar8);
          pTVar10 = pTStack_1c;
          if (param_1->playNumberValue == -1) {
            if (param_6 == 0) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              iVar8 = UnitAIModule::currentAction(pUVar7);
              if (iVar8 == 600) {
                pUVar7 = RGE_Static_Object::unitAI(pRVar6);
                iVar8 = UnitAIModule::currentTargetType(pUVar7);
                if (iVar8 != 0x1b) {
                  TribeTacticalAIModule::logGroupDebug
                            (this_06,(int)pTVar15,(char *)param_1->idValue,
                             s_______Unit__d_is_busy_with_an_no);
                  pTVar10 = extraout_ECX_21;
                  goto LAB_004ec625;
                }
              }
            }
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)param_1->subTypeValue,(int)pTVar15,
                       (char *)param_1->idValue);
            if ((param_1->subTypeValue == 0) || (param_1->subTypeValue == 4)) {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue);
              TribeTacticalAIModule::taskDefender(pTVar15,*piVar9,param_1->targetValue,2.0,100);
              pTVar10 = extraout_ECX_26;
            }
            else {
              pRVar6 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)param_3,param_1->targetValue);
              if (pRVar6 == (RGE_Static_Object *)0x0) {
                TribeTacticalAIModule::logGroupDebug(this_07,(int)pTVar15,(char *)param_1->idValue);
                pTVar10 = extraout_ECX_25;
              }
              else {
                if (bVar2) {
                  TribeTacticalAIModule::logGroupDebug
                            (this_07,(int)pTVar15,(char *)param_1->idValue);
                  XStack_10.x = __ftol();
                  XStack_10.x = XStack_10.x + -7;
                  XStack_10.y = __ftol();
                  XStack_10.y = XStack_10.y + -7;
                  this = &param_3->informationAI;
                  TribeInformationAIModule::mapBound(this,&XStack_10);
                  XStack_8.x = __ftol();
                  XStack_8.x = XStack_8.x + 7;
                  XStack_8.y = __ftol();
                  XStack_8.y = XStack_8.y + 7;
                  TribeInformationAIModule::mapBound(this,&XStack_8);
                  bVar1 = param_1->numberAttackWaypointsValue;
                  if (1 < bVar1) {
                    if ((float)XStack_10.x <= param_1->attackWaypoints[bVar1 - 2].x) {
                      XStack_8.x = __ftol();
                    }
                    else {
                      XStack_10.x = __ftol();
                    }
                    if ((float)XStack_10.y <= param_1->attackWaypoints[bVar1 - 2].y) {
                      XStack_8.y = __ftol();
                    }
                    else {
                      XStack_10.y = __ftol();
                    }
                  }
                  TribeInformationAIModule::storeAttackMemory
                            (this,'\0',(uchar)XStack_10.x,(uchar)XStack_10.y,(uchar)XStack_8.x,
                             (uchar)XStack_8.y,*(uchar *)(param_3->_padding_ + 0x4a),
                             (uchar)pRVar6->owner->id,0,'\0',
                             *(ulong *)(*(int *)(param_3->_padding_ + 0x3c) + 4),-1);
                  TribeTacticalAIModule::resetAttackSeparationTime(pTVar15);
                  bVar2 = false;
                }
                TribeTacticalAIModule::logGroupDebug
                          ((TribeTacticalAIModule *)param_1->targetValue,(int)pTVar15,
                           (char *)param_1->idValue);
                if (((*piVar9 == param_1->commanderValue) ||
                    (iVar8 = TribeTacticalAIModule::importantGroupLeader
                                       (pTVar15,param_1->commanderValue), iVar8 == 0)) ||
                   (iVar8 = TribeTacticalAIModule::strategicNumber(pTVar15,0x79), iVar8 == 0)) {
                  TribeTacticalAIModule::logGroupDebug
                            ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                             (char *)param_1->idValue);
                  if (param_4 == 0x15) {
                    TribeTacticalAIModule::moveUnit
                              (pTVar15,*piVar9,(param_1->targetLocationValue).x,
                               (param_1->targetLocationValue).y,100);
                    pTVar10 = extraout_ECX_23;
                  }
                  else {
                    TribeTacticalAIModule::taskAttacker
                              (pTVar15,*piVar9,(param_1->targetLocationValue).x,
                               (param_1->targetLocationValue).y,param_1->targetValue,
                               (int)pRVar6->owner->id,param_1->attackWaypoints,
                               (uint)param_1->numberAttackWaypointsValue,param_1->commanderValue,0);
                    pTVar10 = extraout_ECX_24;
                  }
                }
                else {
                  TribeTacticalAIModule::logGroupDebug
                            ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                             (char *)param_1->idValue);
                  iVar5 = 99;
                  iVar8 = TribeTacticalAIModule::strategicNumber(pTVar15,0x83);
                  TribeTacticalAIModule::taskDefender
                            (pTVar15,*piVar9,param_1->commanderValue,(float)iVar8,iVar5);
                  pTVar10 = extraout_ECX_22;
                }
              }
            }
          }
        }
      }
LAB_004ec625:
      piVar9 = piVar9 + 1;
      param_2 = (TribeTacticalAIModule *)((int)param_2 + 1);
    } while ((int)param_2 < 0x28);
    if (param_1->playNumberValue != -1) {
      piVar9 = (int *)operator_new(param_1->numberUnitsValue << 2);
      if (piVar9 != (int *)0x0) {
        piVar11 = param_1->unitsValue;
        iVar8 = 0x28;
        piVar12 = piVar9;
        do {
          if (*piVar11 != -1) {
            *piVar12 = *piVar11;
            piVar12 = piVar12 + 1;
          }
          piVar11 = piVar11 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        TribeTacticalAIModule::taskPlay
                  (pTVar15,param_1->commanderValue,piVar9,param_1->numberUnitsValue,
                   param_1->targetValue,param_1->playNumberValue,param_1->attackWaypoints,
                   (uint)param_1->numberAttackWaypointsValue);
        operator_delete(piVar9);
        return 0;
      }
      TribeTacticalAIModule::logGroupDebug
                ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,(char *)param_1->idValue);
      return 0;
    }
    param_1->inUseValue = 1;
    param_2 = pTStack_1c;
    goto joined_r0x004ec189;
  case 3:
    TribeTacticalAIModule::logGroupDebug(pTVar10,(int)param_2,(char *)param_1->idValue);
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue,
               s___Retreat_Position___f___f__,(double)(param_1->retreatLocationValue).x,
               (double)(param_1->retreatLocationValue).y);
    param_5 = (TribeTacticalAIModule *)0x0;
    piVar9 = param_1->unitsValue;
    pTVar10 = extraout_ECX_04;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar10,(int)param_2,(char *)param_1->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue
                     ,s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,(int)param_5,param_3);
          pTVar10 = extraout_ECX_07;
        }
        else {
          fVar14 = RGE_Static_Object::distance_to_position
                             (pRVar6,(param_1->retreatLocationValue).x,
                              (param_1->retreatLocationValue).y,(param_1->retreatLocationValue).z);
          fVar13 = fVar14 - _DAT_005756f4;
          if (fVar14 - _DAT_005756f4 < _DAT_005756f0) {
            fVar13 = _DAT_005756f0;
          }
          if ((float)((TribeTacticalAIModule *)pRVar6->master_obj)->_padding_ * _DAT_005756f8 <=
              fVar13) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)*piVar9,(int)param_2,(char *)param_1->idValue,
                       s_______Tasking_Unit___d_to_move_t);
            TribeTacticalAIModule::moveUnit
                      (param_2,*piVar9,(param_1->retreatLocationValue).x,
                       (param_1->retreatLocationValue).y,100);
            pTVar10 = extraout_ECX_06;
          }
          else {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)pRVar6->master_obj,(int)param_2,
                       (char *)param_1->idValue,s_______Unit__d_is_within_a_tile_o);
            pTVar10 = extraout_ECX_05;
          }
        }
      }
      piVar9 = piVar9 + 1;
      param_5 = (TribeTacticalAIModule *)((int)param_5 + 1);
    } while ((int)param_5 < 0x28);
    return 1;
  case 4:
    TribeTacticalAIModule::logGroupDebug
              (pTVar10,(int)param_2,(char *)param_1->idValue,s___Going_to_send_my_units_to_defe,
               param_1->targetValue,(double)(param_1->targetLocationValue).x,
               (double)(param_1->targetLocationValue).y);
    param_2 = (TribeTacticalAIModule *)0x0;
    param_4 = 0;
    piVar9 = param_1->unitsValue;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,(char *)param_1->idValue,
                   s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_4,param_3);
        }
        else {
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          param_2 = (TribeTacticalAIModule *)((int)param_2 + iVar8);
          if (param_6 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                         (char *)param_1->idValue);
              goto LAB_004ec8ac;
            }
          }
          fVar13 = RGE_Static_Object::distance_to_position
                             (pRVar6,(param_1->targetLocationValue).x,
                              (param_1->targetLocationValue).y,(param_1->targetLocationValue).z);
          iVar8 = TribeTacticalAIModule::calculatePriority(pTVar15,fVar13);
          if (param_1->targetTypeValue == 0x6d) {
            iVar5 = TribeTacticalAIModule::strategicNumber(pTVar15,0x16);
            TribeTacticalAIModule::taskDefender
                      (pTVar15,*piVar9,param_1->targetValue,(float)iVar5,iVar8);
          }
          else {
            iVar5 = TribeTacticalAIModule::strategicNumber(pTVar15,0x39);
            TribeTacticalAIModule::taskDefender
                      (pTVar15,*piVar9,param_1->targetValue,(float)iVar5,iVar8);
          }
        }
      }
LAB_004ec8ac:
      piVar9 = piVar9 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < 0x28);
    param_1->inUseValue = 1;
    goto joined_r0x004eca61;
  case 5:
  case 6:
  case 0xc:
  case 0x13:
    TribeTacticalAIModule::logGroupDebug(pTVar10,(int)param_2,(char *)param_1->idValue);
    param_4 = 0;
    param_6 = 0;
    piVar9 = param_1->unitsValue;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue,
                   s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue
                     ,s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_6,param_3);
        }
        else {
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          param_4 = param_4 + iVar8;
        }
      }
      piVar9 = piVar9 + 1;
      param_6 = param_6 + 1;
    } while (param_6 < 0x28);
    param_1->inUseValue = 1;
    if (param_5 != (TribeTacticalAIModule *)0x1) {
      return 0;
    }
    param_1->originalHitPointsValue = param_4;
    param_1->originalUnitNumberValue = param_1->numberUnitsValue;
    return 0;
  case 7:
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue);
    param_2 = (TribeTacticalAIModule *)0x0;
    iVar8 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x3af);
    pTVar10 = (TribeTacticalAIModule *)0x64;
    param_4 = 0;
    piVar9 = param_1->unitsValue;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar10,(int)pTVar15,(char *)param_1->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_4,param_3);
          pTVar10 = extraout_ECX_12;
        }
        else {
          iVar5 = __ftol();
          piVar9[0x28] = iVar5;
          param_2 = (TribeTacticalAIModule *)((int)param_2 + iVar5);
          if (param_6 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar5 = UnitAIModule::currentAction(pUVar7);
            if (iVar5 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue);
              pTVar10 = extraout_ECX_08;
              goto LAB_004ebd75;
            }
          }
          if ((TribeTacticalAIModule *)*piVar9 == (TribeTacticalAIModule *)param_1->commanderValue)
{
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)param_1->commanderValue,(int)pTVar15,
                       (char *)param_1->idValue,s_______Unit__d_is_the_commander__);
            TribeTacticalAIModule::taskExplorer(pTVar15,*piVar9,0);
            pTVar10 = extraout_ECX_09;
          }
          else {
            iVar5 = TribeTacticalAIModule::strategicNumber(pTVar15,200);
            if (iVar8 % 100 < iVar5) {
              TribeTacticalAIModule::logGroupDebug
                        (this_01,(int)pTVar15,(char *)param_1->idValue,
                         s_______Unit__d_is_not_the_command);
              TribeTacticalAIModule::taskDefender
                        (pTVar15,*piVar9,param_1->commanderValue,
                         pRVar6->master_obj->los * _DAT_005756fc,99);
              pTVar10 = extraout_ECX_10;
            }
            else {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue,
                         s_______Unit__d_is_not_the_command);
              TribeTacticalAIModule::taskExplorer(pTVar15,*piVar9,0);
              pTVar10 = extraout_ECX_11;
            }
          }
        }
      }
LAB_004ebd75:
      piVar9 = piVar9 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < 0x28);
    param_1->inUseValue = 1;
    goto joined_r0x004eca61;
  case 8:
    TribeTacticalAIModule::logGroupDebug(pTVar10,(int)param_2,(char *)param_1->idValue);
    param_2 = (TribeTacticalAIModule *)0x0;
    param_4 = 0;
    piVar9 = param_1->unitsValue;
    pTVar10 = extraout_ECX_13;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar10,(int)pTVar15,(char *)param_1->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        pTVar10 = extraout_ECX_14;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar10 = extraout_ECX_15,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar10,(int)pTVar15,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_4,param_3);
          pTVar10 = extraout_ECX_18;
        }
        else {
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          param_2 = (TribeTacticalAIModule *)((int)param_2 + iVar8);
          if (param_6 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug(this_02,(int)pTVar15,(char *)param_1->idValue);
              pTVar10 = extraout_ECX_16;
              goto LAB_004ebe91;
            }
          }
          TribeTacticalAIModule::taskExplorer(pTVar15,*piVar9,0);
          pTVar10 = extraout_ECX_17;
        }
      }
LAB_004ebe91:
      piVar9 = piVar9 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < 0x28);
    param_1->inUseValue = 1;
    param_4 = (int)param_2;
    break;
  case 9:
  case 0xe:
    if (param_1->consecutiveGatherAttemptsValue != 0xff) {
      param_1->consecutiveGatherAttemptsValue = param_1->consecutiveGatherAttemptsValue + '\x01';
    }
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,(int)pTVar10);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      return 0;
    }
    uVar3 = RGE_Static_Object::currentZone(pRVar6);
    iVar8 = __ftol();
    iVar5 = __ftol();
    uVar4 = RGE_Static_Object::lookupZone(pRVar6,iVar5,iVar8);
    if (uVar3 != uVar4) {
      TacticalAIGroup::setGatherLocation(param_1,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
    }
    param_2 = (TribeTacticalAIModule *)0x0;
    piVar9 = param_1->unitsValue;
    do {
      if (*piVar9 != -1) {
        this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        if ((this_00 != (RGE_Static_Object *)0x0) &&
           (pUVar7 = RGE_Static_Object::unitAI(this_00), pUVar7 != (UnitAIModule *)0x0)) {
          iVar8 = __ftol();
          iVar5 = __ftol();
          uVar4 = RGE_Static_Object::lookupZone(pRVar6,iVar5,iVar8);
          if (uVar4 == uVar3) {
            if (param_6 == 0) {
              pUVar7 = RGE_Static_Object::unitAI(this_00);
              iVar8 = UnitAIModule::currentAction(pUVar7);
              if (iVar8 != -1) {
                pUVar7 = RGE_Static_Object::unitAI(this_00);
                iVar8 = UnitAIModule::currentAction(pUVar7);
                if (iVar8 != 0x266) goto LAB_004eba3c;
              }
            }
            if (param_4 == 0xe) {
              pTStack_1c = (TribeTacticalAIModule *)0x0;
            }
            else {
              iVar8 = TribeTacticalAIModule::strategicNumber(pTVar15,0x29);
              pTStack_1c = (TribeTacticalAIModule *)(float)iVar8;
            }
            fVar13 = RGE_Static_Object::distance_to_position
                               (this_00,(param_1->gatherLocationValue).x,
                                (param_1->gatherLocationValue).y,(param_1->gatherLocationValue).z);
            param_5 = (TribeTacticalAIModule *)(fVar13 - _DAT_005756f4);
            if ((float)param_5 < _DAT_005756f0) {
              param_5 = (TribeTacticalAIModule *)0x0;
            }
            if ((float)pTStack_1c <= (float)param_5) {
              iVar8 = TribeTacticalAIModule::calculatePriority(pTVar15,(float)param_5);
              TribeTacticalAIModule::groupGatherUnit
                        (pTVar15,*piVar9,param_1->commanderValue,(param_1->gatherLocationValue).x,
                         (param_1->gatherLocationValue).y,(param_1->gatherLocationValue).z,
                         (float)pTStack_1c,iVar8);
            }
            else {
              pUVar7 = RGE_Static_Object::unitAI(this_00);
              iVar8 = UnitAIModule::currentOrder(pUVar7);
              if (iVar8 != -1) {
                TribeTacticalAIModule::stopUnit(pTVar15,*piVar9,100);
              }
            }
            goto LAB_004eba3c;
          }
        }
        TacticalAIGroup::removeUnitByIndex(param_1,(int)param_2,param_3);
      }
LAB_004eba3c:
      piVar9 = piVar9 + 1;
      param_2 = (TribeTacticalAIModule *)((int)param_2 + 1);
      if (0x27 < (int)param_2) {
        return 1;
      }
    } while( true );
  case 10:
    TribeTacticalAIModule::logGroupDebug(pTVar10,(int)param_2,(char *)param_1->idValue);
    param_2 = (TribeTacticalAIModule *)0x0;
    param_4 = 0;
    piVar9 = param_1->unitsValue;
    pTVar10 = extraout_ECX_28;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar10,(int)pTVar15,(char *)param_1->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_4,param_3);
          pTVar10 = extraout_ECX_32;
        }
        else {
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          param_2 = (TribeTacticalAIModule *)((int)param_2 + iVar8);
          if (param_6 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug(this_08,(int)pTVar15,(char *)param_1->idValue);
              pTVar10 = extraout_ECX_29;
              goto LAB_004eca3e;
            }
          }
          if ((TribeTacticalAIModule *)*piVar9 == (TribeTacticalAIModule *)param_1->commanderValue)
{
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                       (char *)param_1->idValue,s_______Unit__d_is_the_commander__);
            TribeTacticalAIModule::taskWaterFisher
                      (pTVar15,*piVar9,param_1->targetValue,(param_1->targetLocationValue).x,
                       (param_1->targetLocationValue).y);
            pTVar10 = extraout_ECX_30;
          }
          else {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)param_1->commanderValue,(int)pTVar15,
                       (char *)param_1->idValue,s_______Unit__d_is_not_the_command);
            TribeTacticalAIModule::taskDefender
                      (pTVar15,*piVar9,param_1->commanderValue,
                       pRVar6->master_obj->los * _DAT_005756fc,99);
            pTVar10 = extraout_ECX_31;
          }
        }
      }
LAB_004eca3e:
      piVar9 = piVar9 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < 0x28);
    param_1->inUseValue = 1;
joined_r0x004eca61:
    if (param_5 == (TribeTacticalAIModule *)0x1) {
      param_1->originalHitPointsValue = (int)param_2;
      param_1->originalUnitNumberValue = param_1->numberUnitsValue;
      return 1;
    }
    return 1;
  case 0xb:
    TribeTacticalAIModule::logGroupDebug(pTVar10,(int)param_2,(char *)param_1->idValue);
    param_2 = (TribeTacticalAIModule *)0x0;
    param_4 = 0;
    piVar9 = param_1->unitsValue;
    pTVar10 = extraout_ECX_33;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  (pTVar10,(int)pTVar15,(char *)param_1->idValue,s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        pTVar10 = extraout_ECX_34;
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pTVar10 = extraout_ECX_35,
           pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    (pTVar10,(int)pTVar15,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_4,param_3);
          pTVar10 = extraout_ECX_39;
        }
        else {
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          param_2 = (TribeTacticalAIModule *)((int)param_2 + iVar8);
          if (param_6 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              pUVar7 = RGE_Static_Object::unitAI(pRVar6);
              UnitAIModule::currentAction(pUVar7);
              TribeTacticalAIModule::logGroupDebug(this_09,(int)pTVar15,(char *)param_1->idValue);
              pTVar10 = extraout_ECX_36;
              goto LAB_004ecbd9;
            }
          }
          if (*piVar9 == param_1->commanderValue) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                       (char *)param_1->idValue,s_______Unit__d_is_the_commander__);
            TribeTacticalAIModule::taskWaterTrader(pTVar15,*piVar9,param_1->targetValue);
            pTVar10 = extraout_ECX_37;
          }
          else {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                       (char *)param_1->idValue,s_______Unit__d_is_not_the_command);
            TribeTacticalAIModule::taskDefender
                      (pTVar15,*piVar9,param_1->commanderValue,
                       pRVar6->master_obj->los * _DAT_005756fc,99);
            pTVar10 = extraout_ECX_38;
          }
        }
      }
LAB_004ecbd9:
      piVar9 = piVar9 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < 0x28);
    param_1->inUseValue = 1;
    param_4 = (int)param_2;
    break;
  default:
    uVar16 = CONCAT44(param_4,s___Task_ID__d_is_an_unknown_group);
    pTVar15 = (TribeTacticalAIModule *)param_1->idValue;
LAB_004ecd0a:
    TribeTacticalAIModule::logGroupDebug(pTVar10,(int)param_2,(char *)pTVar15,uVar16);
    return 0;
  case 0x14:
    TribeTacticalAIModule::logGroupDebug
              ((TribeTacticalAIModule *)param_1->idValue,(int)param_2,(char *)param_1->idValue,
               s___Going_to_send_my_units_to_atta,param_1->targetValue);
    TribeTacticalAIModule::logGroupDebug
              (this_03,(int)param_2,(char *)param_1->idValue,s_____Target_Location___f___f__,
               (double)(param_1->targetLocationValue).x,(double)(param_1->targetLocationValue).y);
    pTVar10 = (TribeTacticalAIModule *)
              (*(int *)(*(int *)(param_3->_padding_ + 0x3c) + 4) - param_1->lastAttackRoundupTime);
    iVar8 = (int)pTVar10 / 1000;
    if (iVar8 < 10) {
      pTVar10 = (TribeTacticalAIModule *)param_1->idValue;
      uVar16 = CONCAT44(iVar8,s_____We_ve_only_waited__d_seconds);
      pTVar15 = pTVar10;
      goto LAB_004ecd0a;
    }
    TribeTacticalAIModule::logGroupDebug
              (pTVar10,(int)param_2,(char *)param_1->idValue,s_____We_ve_waited__d_seconds__che);
    pTVar10 = *(TribeTacticalAIModule **)(param_3->_padding_ + 0x3c);
    param_1->lastAttackRoundupTime = pTVar10->_padding_;
    if (param_1->playNumberValue != -1) {
      TribeTacticalAIModule::logGroupDebug(pTVar10,(int)param_2,(char *)param_1->idValue);
      return 0;
    }
    param_2 = (TribeTacticalAIModule *)0x0;
    param_4 = 0;
    piVar9 = param_1->unitsValue;
    do {
      if (*piVar9 != -1) {
        TribeTacticalAIModule::logGroupDebug
                  ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,(char *)param_1->idValue,
                   s_____Checking_on_Unit___d_);
        pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar9);
        if ((pRVar6 == (RGE_Static_Object *)0x0) ||
           (pUVar7 = RGE_Static_Object::unitAI(pRVar6), pUVar7 == (UnitAIModule *)0x0)) {
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue,
                     s_______Unit___d_is_gone__removing);
          TacticalAIGroup::removeUnitByIndex(param_1,param_4,param_3);
        }
        else {
          pUVar7 = RGE_Static_Object::unitAI(pRVar6);
          UnitAIModule::currentAction(pUVar7);
          TribeTacticalAIModule::logGroupDebug
                    (this_04,(int)pTVar15,(char *)param_1->idValue,s_______CurrentAction__d_);
          iVar8 = __ftol();
          piVar9[0x28] = iVar8;
          param_2 = (TribeTacticalAIModule *)((int)&param_2->_padding_ + iVar8);
          if (param_6 == 0) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar6);
            iVar8 = UnitAIModule::currentAction(pUVar7);
            if (iVar8 != -1) {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue,
                         s_______Unit__d_is_busy_with_an_ac);
              goto LAB_004ec166;
            }
          }
          TribeTacticalAIModule::logGroupDebug
                    ((TribeTacticalAIModule *)*piVar9,(int)pTVar15,(char *)param_1->idValue);
          if ((param_1->subTypeValue == 0) || (param_1->subTypeValue == 4)) {
            TribeTacticalAIModule::logGroupDebug
                      ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                       (char *)param_1->idValue);
            TribeTacticalAIModule::taskDefender(pTVar15,*piVar9,param_1->targetValue,2.0,100);
          }
          else {
            pRVar6 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_3,param_1->targetValue);
            if (pRVar6 == (RGE_Static_Object *)0x0) {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)param_1->idValue,(int)pTVar15,
                         (char *)param_1->idValue);
            }
            else {
              TribeTacticalAIModule::logGroupDebug
                        ((TribeTacticalAIModule *)param_1->targetValue,(int)pTVar15,
                         (char *)param_1->idValue);
              TribeTacticalAIModule::taskAttacker
                        (pTVar15,*piVar9,(param_1->targetLocationValue).x,
                         (param_1->targetLocationValue).y,param_1->targetValue,
                         (int)pRVar6->owner->id,param_1->attackWaypoints,
                         (uint)param_1->numberAttackWaypointsValue,param_1->commanderValue,1);
            }
          }
        }
      }
LAB_004ec166:
      piVar9 = piVar9 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < 0x28);
    param_1->inUseValue = 1;
joined_r0x004ec189:
    if (param_5 == (TribeTacticalAIModule *)0x1) {
      param_1->originalHitPointsValue = (int)param_2;
      param_1->originalUnitNumberValue = param_1->numberUnitsValue;
      param_1->numberAttackWaypointsValue = '\0';
      return 1;
    }
    return 1;
  }
  if (param_5 == (TribeTacticalAIModule *)0x1) {
    param_1->originalHitPointsValue = param_4;
    param_1->originalUnitNumberValue = param_1->numberUnitsValue;
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ecd1f
// Address: 004ecd1f
// XREFS: None
void FUN_004ecd1f(void)
{
  code *pcVar1;
  int in_EAX;
  char unaff_BL;
  
  *(char *)(in_EAX + -0x46) = *(char *)(in_EAX + -0x46) + (char)((uint)in_EAX >> 8);
  cRam22004ec7 = cRam22004ec7 + unaff_BL;
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_004ece68
// Address: 004ece68
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004ece68(TacticalAIGroup *param_1,undefined4 param_2,TribeMainDecisionAIModule *param_3)
{
  float fVar1;
  RGE_Static_Object *this;
  UnitAIModule *pUVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  
  iVar4 = 0;
  piVar3 = param_1->unitsValue;
  do {
    if (*piVar3 != -1) {
      this = MainDecisionAIModule::object((MainDecisionAIModule *)param_3,*piVar3);
      if ((this == (RGE_Static_Object *)0x0) ||
         (pUVar2 = RGE_Static_Object::unitAI(this), pUVar2 == (UnitAIModule *)0x0)) {
        TacticalAIGroup::removeUnitByIndex(param_1,iVar4,param_3);
      }
      else {
        fVar5 = RGE_Static_Object::distance_to_position
                          (this,(param_1->gatherLocationValue).x,(param_1->gatherLocationValue).y,
                           (param_1->gatherLocationValue).z);
        fVar1 = fVar5 - _DAT_00575700;
        if (fVar5 - _DAT_00575700 < _DAT_005756f0) {
          fVar1 = _DAT_005756f0;
        }
        if ((float)_DAT_00575708 < fVar1) {
          return 0;
        }
      }
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    if (0x27 < iVar4) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004ecf0f
// Address: 004ecf0f
// XREFS: None
undefined4 __thiscall
FUN_004ecf0f(TacticalAIGroup *param_1,TribeMainDecisionAIModule *param_2,int param_3)
{
  RGE_Static_Object *this;
  UnitAIModule *pUVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = param_1->unitsValue;
  do {
    if (*piVar3 != -1) {
      this = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar3);
      if ((this == (RGE_Static_Object *)0x0) ||
         (pUVar1 = RGE_Static_Object::unitAI(this), pUVar1 == (UnitAIModule *)0x0)) {
        TacticalAIGroup::removeUnitByIndex(param_1,iVar4,param_2);
      }
      else if (this->master_obj->id != 0x7d) {
        if (param_3 == 1) {
          pUVar1 = RGE_Static_Object::unitAI(this);
          iVar2 = UnitAIModule::currentAction(pUVar1);
          if ((iVar2 == 600) && ((param_1->typeValue == 100 || (param_1->typeValue == 0x67))))
          goto LAB_004ecfb3;
        }
        pUVar1 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar1);
        if (iVar2 != -1) {
          pUVar1 = RGE_Static_Object::unitAI(this);
          iVar2 = UnitAIModule::currentOrder(pUVar1);
          if (iVar2 != 0x2bd) {
            return 0;
          }
        }
      }
    }
LAB_004ecfb3:
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    if (0x27 < iVar4) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004ecfd7
// Address: 004ecfd7
// XREFS: None
undefined4 __fastcall FUN_004ecfd7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1cc);
}

// --------------------------------------------------

// Function: FUN_004ecfe7
// Address: 004ecfe7
// XREFS: None
void __thiscall FUN_004ecfe7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1cc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004ecffd
// Address: 004ecffd
// XREFS: None
void __thiscall FUN_004ecffd(int param_1,int param_2)
{
  *(int *)(param_1 + 0x1cc) = *(int *)(param_1 + 0x1cc) + param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004ed015
// Address: 004ed015
// XREFS: None
undefined1 __fastcall FUN_004ed015(int param_1)
{
  return *(undefined1 *)(param_1 + 0x1d4);
}

// --------------------------------------------------

// Function: FUN_004ed027
// Address: 004ed027
// XREFS: None
undefined1 __fastcall FUN_004ed027(int param_1)
{
  return *(undefined1 *)(param_1 + 0x1d5);
}

// --------------------------------------------------

// Function: FUN_004ed037
// Address: 004ed037
// XREFS: None
void __thiscall FUN_004ed037(int param_1,byte param_2)
{
  if (param_2 < *(byte *)(param_1 + 0x1d4)) {
    *(byte *)(param_1 + 0x1d5) = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ed057
// Address: 004ed057
// XREFS: None
void __thiscall FUN_004ed057(int param_1,undefined4 param_2,undefined4 param_3)
{
  if (*(byte *)(param_1 + 0x1d4) < 0xe) {
    *(undefined4 *)((uint)*(byte *)(param_1 + 0x1d4) * 0x10 + 0x1d8 + param_1) = param_2;
    *(undefined4 *)((uint)*(byte *)(param_1 + 0x1d4) * 0x10 + 0x1dc + param_1) = param_3;
    *(undefined4 *)((*(byte *)(param_1 + 0x1d4) + 0x1e) * 0x10 + param_1) = 0x3f800000;
    *(char *)(param_1 + 0x1d4) = *(char *)(param_1 + 0x1d4) + '\x01';
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ed0b9
// Address: 004ed0b9
// XREFS: None
int __thiscall FUN_004ed0b9(int param_1,byte param_2)
{
  if (param_2 < *(byte *)(param_1 + 0x1d4)) {
    return (uint)param_2 * 0x10 + 0x1d8 + param_1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ed0e5
// Address: 004ed0e5
// XREFS: None
int __thiscall FUN_004ed0e5(TacticalAIGroup *param_1,TribeMainDecisionAIModule *param_2)
{
  RGE_Static_Object *this;
  UnitAIModule *pUVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = param_1->unitsValue;
  do {
    if (*piVar3 != -1) {
      this = MainDecisionAIModule::object((MainDecisionAIModule *)param_2,*piVar3);
      if ((this == (RGE_Static_Object *)0x0) ||
         (pUVar1 = RGE_Static_Object::unitAI(this), pUVar1 == (UnitAIModule *)0x0)) {
        TacticalAIGroup::removeUnitByIndex(param_1,iVar4,param_2);
      }
      else {
        pUVar1 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar1);
        if (iVar2 == -1) {
          return param_1->unitsValue[iVar4];
        }
      }
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 0x28);
  return -1;
}

// --------------------------------------------------

// Function: FUN_004ed16f
// Address: 004ed16f
// XREFS: None
undefined4 __thiscall FUN_004ed16f(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x14)) {
    return *(undefined4 *)(param_1 + 0x2d0 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004ed18d
// Address: 004ed18d
// XREFS: None
undefined4 __thiscall FUN_004ed18d(int param_1,undefined4 param_2)
{
  if (*(int *)(param_1 + 0x2cc) < 0x13) {
    *(undefined4 *)(param_1 + 0x2d0 + *(int *)(param_1 + 0x2cc) * 4) = param_2;
    *(int *)(param_1 + 0x2cc) = *(int *)(param_1 + 0x2cc) + 1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ed4ce
// Address: 004ed4ce
// XREFS: None
TribeTacticalAIModule * __thiscall FUN_004ed4ce(TribeTacticalAIModule *param_1,byte param_2)
{
  TribeTacticalAIModule::~TribeTacticalAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ed4ee
// Address: 004ed4ee
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TribeTacticalAIModule * __thiscall
FUN_004ed4ee(TribeTacticalAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  TacticalAIGroup *pTVar5;
  int iVar6;
  PlacementState *pPVar7;
  AttackState *pAVar8;
  undefined4 *unaff_FS_OFFSET;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  TribeTacticalAIModule *pTStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560a28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_24 = param_1;
  TacticalAIModule::TacticalAIModule((TacticalAIModule *)param_1,(void *)0x0,param_2);
  param_1->md = (TribeMainDecisionAIModule *)0x0;
  (param_1->civilians).value = (int *)0x0;
  (param_1->civilians).numberValue = 0;
  (param_1->civilians).desiredNumberValue = 0;
  (param_1->civilians).maximumSizeValue = 0;
  (param_1->civilianExplorers).value = (int *)0x0;
  (param_1->civilianExplorers).numberValue = 0;
  (param_1->civilianExplorers).desiredNumberValue = 0;
  (param_1->civilianExplorers).maximumSizeValue = 0;
  (param_1->soldiers).value = (int *)0x0;
  (param_1->soldiers).numberValue = 0;
  (param_1->soldiers).desiredNumberValue = 0;
  (param_1->soldiers).maximumSizeValue = 0;
  (param_1->ungroupedSoldiers).value = (int *)0x0;
  (param_1->ungroupedSoldiers).numberValue = 0;
  (param_1->ungroupedSoldiers).desiredNumberValue = 0;
  (param_1->ungroupedSoldiers).maximumSizeValue = 0;
  (param_1->boats).value = (int *)0x0;
  (param_1->boats).numberValue = 0;
  (param_1->boats).desiredNumberValue = 0;
  (param_1->boats).maximumSizeValue = 0;
  (param_1->warBoats).value = (int *)0x0;
  (param_1->warBoats).numberValue = 0;
  (param_1->warBoats).desiredNumberValue = 0;
  (param_1->warBoats).maximumSizeValue = 0;
  (param_1->fishingBoats).value = (int *)0x0;
  (param_1->fishingBoats).numberValue = 0;
  (param_1->fishingBoats).desiredNumberValue = 0;
  (param_1->fishingBoats).maximumSizeValue = 0;
  (param_1->tradeBoats).value = (int *)0x0;
  (param_1->tradeBoats).numberValue = 0;
  (param_1->tradeBoats).desiredNumberValue = 0;
  (param_1->tradeBoats).maximumSizeValue = 0;
  (param_1->transportBoats).value = (int *)0x0;
  (param_1->transportBoats).numberValue = 0;
  (param_1->transportBoats).desiredNumberValue = 0;
  (param_1->transportBoats).maximumSizeValue = 0;
  (param_1->artifacts).value = (int *)0x0;
  (param_1->artifacts).numberValue = 0;
  (param_1->artifacts).desiredNumberValue = 0;
  (param_1->artifacts).maximumSizeValue = 0;
  pTVar5 = &param_1->groups;
  uStack_4._0_1_ = 10;
  uStack_4._1_3_ = 0;
  TacticalAIGroup::TacticalAIGroup(pTVar5);
  param_1->lastGroupRebalanceTime = 0;
  (param_1->playersToAttack).value = (int *)0x0;
  (param_1->playersToAttack).numberValue = 0;
  (param_1->playersToAttack).desiredNumberValue = 0;
  (param_1->playersToAttack).maximumSizeValue = 0;
  (param_1->playersToDefend).value = (int *)0x0;
  (param_1->playersToDefend).numberValue = 0;
  (param_1->playersToDefend).desiredNumberValue = 0;
  (param_1->playersToDefend).maximumSizeValue = 0;
  (param_1->workingArea).value = (int *)0x0;
  (param_1->workingArea).numberValue = 0;
  (param_1->workingArea).desiredNumberValue = 0;
  (param_1->workingArea).maximumSizeValue = 0;
  (param_1->unitsTaskedThisUpdate).value = (int *)0x0;
  (param_1->unitsTaskedThisUpdate).numberValue = 0;
  (param_1->unitsTaskedThisUpdate).desiredNumberValue = 0;
  (param_1->unitsTaskedThisUpdate).maximumSizeValue = 0;
  uStack_4._0_1_ = 0xf;
  ResourceItem::ResourceItem(&param_1->neededResources,4);
  iVar6 = param_3;
  (param_1->groups).next = pTVar5;
  (param_1->groups).prev = pTVar5;
  uStack_4 = CONCAT31(uStack_4._1_3_,0x10);
  param_1->attackEnabledValue = 0;
  param_1->updateArea = 0;
  param_1->firstNeededResourceUpdateDone = 0;
  param_1->wonderInProgressValue = 0;
  param_1->wonderBuiltValue = 0;
  param_1->nextCivilianToTaskValue = -1;
  param_1->nextIdleSoldierGroupToTaskValue = -1;
  param_1->nextActiveSoldierGroupToTaskValue = -1;
  param_1->builtFirstStoragePit = 0;
  param_1->builtFirstGranary = 0;
  param_1->lastBuildTime = 0;
  param_1->lastAttackResponseBuildInsertionTime = 0;
  param_1->lastCoopTributeDemandTime = 0;
  param_1->lastCoopTributeGiftTime = 0;
  param_1->lastCoopAttackDemandTime = 0;
  param_1->zoomingToNextAge = 0;
  param_1->lastUngroupedSoldierTaskTime = 0;
  param_1->lastUpdateAreaTimeValue = -1;
  param_1->averageUpdateAreaTimeValue = -1;
  param_1->updateAreaAverageCount = 0;
  param_1->updateAreaAverageTotal = 0;
  param_1->_padding_ = (int)&TribeTacticalAIModule::_vftable_;
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(iVar6,&iStack_2c,4);
      iVar6 = (param_1->civilians).numberValue;
      iVar1 = 0;
      iStack_28 = iStack_2c;
      if (0 < iVar6) {
        do {
          if ((param_1->civilians).maximumSizeValue <= iVar1) break;
          if ((param_1->civilians).value[iVar1] == iStack_2c) goto LAB_004ed829;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((param_1->civilians).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (param_1->civilians).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (param_1->civilians).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (param_1->civilians).maximumSizeValue);
          }
          operator_delete((param_1->civilians).value);
          (param_1->civilians).value = piVar2;
          (param_1->civilians).maximumSizeValue = iVar6;
        }
      }
      (param_1->civilians).value[(param_1->civilians).numberValue] = iStack_28;
      (param_1->civilians).numberValue = (param_1->civilians).numberValue + 1;
LAB_004ed829:
      iStack_30 = iStack_30 + 1;
      iVar6 = param_3;
    } while (iStack_30 < param_2);
  }
  rge_read(iVar6,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(iVar6,&iStack_2c,4);
      iVar6 = (param_1->civilianExplorers).numberValue;
      iVar1 = 0;
      iStack_28 = iStack_2c;
      if (0 < iVar6) {
        do {
          if ((param_1->civilianExplorers).maximumSizeValue <= iVar1) break;
          if ((param_1->civilianExplorers).value[iVar1] == iStack_2c) goto LAB_004ed92c;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((param_1->civilianExplorers).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (param_1->civilianExplorers).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (param_1->civilianExplorers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (param_1->civilianExplorers).maximumSizeValue);
          }
          operator_delete((param_1->civilianExplorers).value);
          (param_1->civilianExplorers).value = piVar2;
          (param_1->civilianExplorers).maximumSizeValue = iVar6;
        }
      }
      (param_1->civilianExplorers).value[(param_1->civilianExplorers).numberValue] = iStack_28;
      (param_1->civilianExplorers).numberValue = (param_1->civilianExplorers).numberValue + 1;
LAB_004ed92c:
      iStack_30 = iStack_30 + 1;
      iVar6 = param_3;
    } while (iStack_30 < param_2);
  }
  rge_read(iVar6,&param_1->numberGatherersValue,4);
  rge_read(iVar6,&param_1->desiredNumberGatherersValue,4);
  if (save_game_version < _DAT_00575710) {
    piVar2 = &param_1->gatherers[0].data1;
    iVar6 = 0x32;
    if (save_game_version < _DAT_00575714) {
      do {
        rge_read(param_3,&iStack_20,0x10);
        ((UnitData *)(piVar2 + -1))->id = iStack_20;
        *piVar2 = iStack_1c;
        piVar2[1] = iStack_18;
        piVar2[2] = iStack_14;
        piVar2[3] = -1;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      do {
        rge_read(param_3,&iStack_20,0x14);
        ((UnitData *)(piVar2 + -1))->id = iStack_20;
        *piVar2 = iStack_1c;
        piVar2[1] = iStack_18;
        piVar2[2] = iStack_14;
        piVar2[3] = iStack_10;
        piVar2[4] = 0;
        piVar2 = piVar2 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
    rge_read(iVar6,param_1->gatherers,0x4b0);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar6 = (param_1->soldiers).numberValue;
      iVar1 = 0;
      iStack_28 = iStack_2c;
      if (0 < iVar6) {
        do {
          if ((param_1->soldiers).maximumSizeValue <= iVar1) break;
          if ((param_1->soldiers).value[iVar1] == iStack_2c) goto LAB_004edb26;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((param_1->soldiers).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (param_1->soldiers).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (param_1->soldiers).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (param_1->soldiers).maximumSizeValue);
          }
          operator_delete((param_1->soldiers).value);
          (param_1->soldiers).value = piVar2;
          (param_1->soldiers).maximumSizeValue = iVar6;
        }
      }
      (param_1->soldiers).value[(param_1->soldiers).numberValue] = iStack_28;
      (param_1->soldiers).numberValue = (param_1->soldiers).numberValue + 1;
LAB_004edb26:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  if (_DAT_00575718 <= save_game_version) {
    rge_read(param_3,&param_2,4);
    iStack_30 = 0;
    if (0 < param_2) {
      do {
        rge_read(param_3,&iStack_2c,4);
        iVar6 = (param_1->ungroupedSoldiers).numberValue;
        iVar1 = 0;
        iStack_28 = iStack_2c;
        if (0 < iVar6) {
          do {
            if ((param_1->ungroupedSoldiers).maximumSizeValue <= iVar1) break;
            if ((param_1->ungroupedSoldiers).value[iVar1] == iStack_2c) goto LAB_004edc44;
            iVar1 = iVar1 + 1;
          } while (iVar1 < iVar6);
        }
        if ((param_1->ungroupedSoldiers).maximumSizeValue + -1 < iVar6) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar1 = 0;
            if (0 < (param_1->ungroupedSoldiers).maximumSizeValue) {
              do {
                if (iVar6 <= iVar1) break;
                iVar3 = iVar1 + 1;
                piVar2[iVar1] = (param_1->ungroupedSoldiers).value[iVar1];
                iVar1 = iVar3;
              } while (iVar3 < (param_1->ungroupedSoldiers).maximumSizeValue);
            }
            operator_delete((param_1->ungroupedSoldiers).value);
            (param_1->ungroupedSoldiers).value = piVar2;
            (param_1->ungroupedSoldiers).maximumSizeValue = iVar6;
          }
        }
        (param_1->ungroupedSoldiers).value[(param_1->ungroupedSoldiers).numberValue] = iStack_28;
        (param_1->ungroupedSoldiers).numberValue = (param_1->ungroupedSoldiers).numberValue + 1;
LAB_004edc44:
        iStack_30 = iStack_30 + 1;
      } while (iStack_30 < param_2);
    }
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar6 = (param_1->boats).numberValue;
      iVar1 = 0;
      iStack_28 = iStack_2c;
      if (0 < iVar6) {
        do {
          if ((param_1->boats).maximumSizeValue <= iVar1) break;
          if ((param_1->boats).value[iVar1] == iStack_2c) goto LAB_004edd4b;
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar6);
      }
      if ((param_1->boats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < (param_1->boats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = (param_1->boats).value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < (param_1->boats).maximumSizeValue);
          }
          operator_delete((param_1->boats).value);
          (param_1->boats).value = piVar2;
          (param_1->boats).maximumSizeValue = iVar6;
        }
      }
      (param_1->boats).value[(param_1->boats).numberValue] = iStack_28;
      (param_1->boats).numberValue = (param_1->boats).numberValue + 1;
LAB_004edd4b:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->warBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->warBoats).maximumSizeValue <= iVar3) break;
          if ((param_1->warBoats).value[iVar3] == iStack_2c) goto LAB_004ede4c;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->warBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->warBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->warBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->warBoats).maximumSizeValue);
          }
          operator_delete((param_1->warBoats).value);
          (param_1->warBoats).value = piVar2;
          (param_1->warBoats).maximumSizeValue = iVar6;
        }
      }
      (param_1->warBoats).value[(param_1->warBoats).numberValue] = iVar1;
      (param_1->warBoats).numberValue = (param_1->warBoats).numberValue + 1;
LAB_004ede4c:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->fishingBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->fishingBoats).maximumSizeValue <= iVar3) break;
          if ((param_1->fishingBoats).value[iVar3] == iStack_2c) goto LAB_004edf51;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->fishingBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->fishingBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->fishingBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->fishingBoats).maximumSizeValue);
          }
          operator_delete((param_1->fishingBoats).value);
          (param_1->fishingBoats).value = piVar2;
          (param_1->fishingBoats).maximumSizeValue = iVar6;
        }
      }
      (param_1->fishingBoats).value[(param_1->fishingBoats).numberValue] = iVar1;
      (param_1->fishingBoats).numberValue = (param_1->fishingBoats).numberValue + 1;
LAB_004edf51:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->tradeBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->tradeBoats).maximumSizeValue <= iVar3) break;
          if ((param_1->tradeBoats).value[iVar3] == iStack_2c) goto LAB_004ee056;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->tradeBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->tradeBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->tradeBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->tradeBoats).maximumSizeValue);
          }
          operator_delete((param_1->tradeBoats).value);
          (param_1->tradeBoats).value = piVar2;
          (param_1->tradeBoats).maximumSizeValue = iVar6;
        }
      }
      (param_1->tradeBoats).value[(param_1->tradeBoats).numberValue] = iVar1;
      (param_1->tradeBoats).numberValue = (param_1->tradeBoats).numberValue + 1;
LAB_004ee056:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->transportBoats).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->transportBoats).maximumSizeValue <= iVar3) break;
          if ((param_1->transportBoats).value[iVar3] == iStack_2c) goto LAB_004ee15b;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->transportBoats).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->transportBoats).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->transportBoats).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->transportBoats).maximumSizeValue);
          }
          operator_delete((param_1->transportBoats).value);
          (param_1->transportBoats).value = piVar2;
          (param_1->transportBoats).maximumSizeValue = iVar6;
        }
      }
      (param_1->transportBoats).value[(param_1->transportBoats).numberValue] = iVar1;
      (param_1->transportBoats).numberValue = (param_1->transportBoats).numberValue + 1;
LAB_004ee15b:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  if (_DAT_0057571c <= save_game_version) {
    rge_read(param_3,&param_2,4);
    iStack_30 = 0;
    if (0 < param_2) {
      do {
        rge_read(param_3,&iStack_2c,4);
        iVar1 = iStack_2c;
        iVar6 = (param_1->artifacts).numberValue;
        iVar3 = 0;
        if (0 < iVar6) {
          do {
            if ((param_1->artifacts).maximumSizeValue <= iVar3) break;
            if ((param_1->artifacts).value[iVar3] == iStack_2c) goto LAB_004ee277;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar6);
        }
        if ((param_1->artifacts).maximumSizeValue + -1 < iVar6) {
          iVar6 = iVar6 + 1;
          piVar2 = (int *)operator_new(iVar6 * 4);
          if (piVar2 != (int *)0x0) {
            iVar3 = 0;
            if (0 < (param_1->artifacts).maximumSizeValue) {
              do {
                if (iVar6 <= iVar3) break;
                iVar4 = iVar3 + 1;
                piVar2[iVar3] = (param_1->artifacts).value[iVar3];
                iVar3 = iVar4;
              } while (iVar4 < (param_1->artifacts).maximumSizeValue);
            }
            operator_delete((param_1->artifacts).value);
            (param_1->artifacts).value = piVar2;
            (param_1->artifacts).maximumSizeValue = iVar6;
          }
        }
        (param_1->artifacts).value[(param_1->artifacts).numberValue] = iVar1;
        (param_1->artifacts).numberValue = (param_1->artifacts).numberValue + 1;
LAB_004ee277:
        iStack_30 = iStack_30 + 1;
      } while (iStack_30 < param_2);
    }
  }
  iVar6 = param_3;
  rge_read(param_3,&param_2,4);
  iVar1 = 0;
  if (0 < param_2) {
    piVar2 = param_1->sn;
    do {
      rge_read(iVar6,piVar2,4);
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < param_2);
  }
  rge_read(iVar6,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->playersToAttack).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->playersToAttack).maximumSizeValue <= iVar3) break;
          if ((param_1->playersToAttack).value[iVar3] == iStack_2c) goto LAB_004ee3b4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->playersToAttack).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->playersToAttack).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->playersToAttack).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->playersToAttack).maximumSizeValue);
          }
          operator_delete((param_1->playersToAttack).value);
          (param_1->playersToAttack).value = piVar2;
          (param_1->playersToAttack).maximumSizeValue = iVar6;
        }
      }
      (param_1->playersToAttack).value[(param_1->playersToAttack).numberValue] = iVar1;
      (param_1->playersToAttack).numberValue = (param_1->playersToAttack).numberValue + 1;
LAB_004ee3b4:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->playersToDefend).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->playersToDefend).maximumSizeValue <= iVar3) break;
          if ((param_1->playersToDefend).value[iVar3] == iStack_2c) goto LAB_004ee4b9;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->playersToDefend).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->playersToDefend).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->playersToDefend).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->playersToDefend).maximumSizeValue);
          }
          operator_delete((param_1->playersToDefend).value);
          (param_1->playersToDefend).value = piVar2;
          (param_1->playersToDefend).maximumSizeValue = iVar6;
        }
      }
      (param_1->playersToDefend).value[(param_1->playersToDefend).numberValue] = iVar1;
      (param_1->playersToDefend).numberValue = (param_1->playersToDefend).numberValue + 1;
LAB_004ee4b9:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->workingArea).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->workingArea).maximumSizeValue <= iVar3) break;
          if ((param_1->workingArea).value[iVar3] == iStack_2c) goto LAB_004ee5be;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->workingArea).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->workingArea).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->workingArea).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->workingArea).maximumSizeValue);
          }
          operator_delete((param_1->workingArea).value);
          (param_1->workingArea).value = piVar2;
          (param_1->workingArea).maximumSizeValue = iVar6;
        }
      }
      (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar1;
      (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004ee5be:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  rge_read(param_3,&param_2,4);
  iStack_30 = 0;
  if (0 < param_2) {
    do {
      rge_read(param_3,&iStack_2c,4);
      iVar1 = iStack_2c;
      iVar6 = (param_1->unitsTaskedThisUpdate).numberValue;
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar3) break;
          if ((param_1->unitsTaskedThisUpdate).value[iVar3] == iStack_2c) goto LAB_004ee6c3;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar6) {
        iVar6 = iVar6 + 1;
        piVar2 = (int *)operator_new(iVar6 * 4);
        if (piVar2 != (int *)0x0) {
          iVar3 = 0;
          if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
            do {
              if (iVar6 <= iVar3) break;
              iVar4 = iVar3 + 1;
              piVar2[iVar3] = (param_1->unitsTaskedThisUpdate).value[iVar3];
              iVar3 = iVar4;
            } while (iVar4 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
          }
          operator_delete((param_1->unitsTaskedThisUpdate).value);
          (param_1->unitsTaskedThisUpdate).value = piVar2;
          (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar6;
        }
      }
      (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = iVar1;
      (param_1->unitsTaskedThisUpdate).numberValue =
           (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004ee6c3:
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < param_2);
  }
  iVar6 = param_3;
  piVar2 = param_1->actualGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = param_1->desiredGathererDistribution;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = param_1->neededResourceValue;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = param_1->resourceDifferenceValue;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = param_1->numberStoragePitsBuilt;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = param_1->numberGranariesBuilt;
  iVar1 = 4;
  do {
    rge_read(iVar6,piVar2,4);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0;
  do {
    rge_read(iVar6,&iStack_2c,4);
    ResourceItem::setValue(&param_1->neededResources,iVar1,iStack_2c);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  rge_read(iVar6,&param_1->groupIDValue,4);
  piVar2 = &param_1->numberGroupsValue;
  rge_read(iVar6,piVar2,4);
  iVar1 = 0;
  if (0 < *piVar2) {
    do {
      pTVar5 = TribeTacticalAIModule::createGroup(param_1,0);
      if (pTVar5 != (TacticalAIGroup *)0x0) {
        TacticalAIGroup::load(pTVar5,iVar6);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *piVar2);
  }
  rge_read(iVar6,&param_1->lastGroupAttackTime,4);
  if (_DAT_00575720 <= save_game_version) {
    rge_read(iVar6,&param_1->lastGroupRebalanceTime,4);
  }
  rge_read(iVar6,&param_1->lastAttackResponseTime,4);
  rge_read(iVar6,&param_1->lastBoatAttackResponseTime,4);
  rge_read(iVar6,&param_1->lastScalingUpdateValue,4);
  rge_read(iVar6,&param_1->numberBuildUpdatesSkipped,4);
  rge_read(iVar6,&param_1->randomizedAttackSeparationTime,4);
  if (_DAT_00575724 <= save_game_version) {
    rge_read(iVar6,&param_1->attackEnabledValue,4);
  }
  rge_read(iVar6,&param_1->updateArea,4);
  if (_DAT_00575728 <= save_game_version) {
    rge_read(iVar6,&param_1->wonderInProgressValue,4);
    rge_read(iVar6,&param_1->wonderBuiltValue,4);
  }
  if (save_game_version < _DAT_0057572c) {
    pPVar7 = &param_1->placementStateValue;
    for (iVar1 = 0x4c; iVar1 != 0; iVar1 = iVar1 + -1) {
      pPVar7->buildingTypeID = 0;
      pPVar7 = (PlacementState *)&pPVar7->buildingSize;
    }
  }
  else {
    rge_read(iVar6,&param_1->placementStateValue,0x130);
  }
  (param_1->placementStateValue).active = 0;
  if (_DAT_00575730 <= save_game_version) {
    rge_read(iVar6,&param_1->nextCivilianToTaskValue,4);
  }
  if (_DAT_00575734 <= save_game_version) {
    rge_read(iVar6,&param_1->nextIdleSoldierGroupToTaskValue,4);
    rge_read(iVar6,&param_1->nextActiveSoldierGroupToTaskValue,4);
  }
  if (_DAT_00575738 <= save_game_version) {
    rge_read(iVar6,&param_1->builtFirstStoragePit,4);
    rge_read(iVar6,&param_1->builtFirstGranary,4);
  }
  if (_DAT_0057573c <= save_game_version) {
    rge_read(iVar6,&param_1->lastBuildTime,4);
    rge_read(iVar6,&param_1->lastAttackResponseBuildInsertionTime,4);
    rge_read(iVar6,&param_1->lastCoopTributeDemandTime,4);
  }
  if (_DAT_00575740 <= save_game_version) {
    rge_read(iVar6,&param_1->lastCoopTributeGiftTime,4);
  }
  if (_DAT_00575744 <= save_game_version) {
    rge_read(iVar6,&param_1->zoomingToNextAge,4);
  }
  if (_DAT_00575748 <= save_game_version) {
    rge_read(iVar6,&param_1->lastCoopAttackDemandTime,4);
  }
  if (_DAT_0057574c <= save_game_version) {
    rge_read(iVar6,&param_1->lastUngroupedSoldierTaskTime,4);
  }
  if (save_game_version < _DAT_00575750) {
    pAVar8 = &param_1->attackStateValue;
    for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
      pAVar8->bestTargetID = 0;
      pAVar8 = (AttackState *)&pAVar8->bestTargetValue;
    }
  }
  else {
    rge_read(iVar6,&param_1->attackStateValue,0x2c);
  }
  (param_1->attackStateValue).active = 0;
  if (save_game_version < _DAT_00575754) {
    piVar2 = param_1->hitsByPlayer;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  else {
    rge_read(iVar6,param_1->hitsByPlayer,0x24);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004eeb34
// Address: 004eeb34
// XREFS: None
void __fastcall FUN_004eeb34(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  pcStack_8 = FUN_00560b28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeTacticalAIModule::_vftable_;
  iStack_4 = 0x10;
  TribeTacticalAIModule::removeAllGroups(param_1,-1);
  iStack_4._0_1_ = 0xf;
  ResourceItem::~ResourceItem(&param_1->neededResources);
  piVar1 = (param_1->unitsTaskedThisUpdate).value;
  iStack_4._0_1_ = 0xe;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->unitsTaskedThisUpdate).value = (int *)0x0;
  }
  (param_1->unitsTaskedThisUpdate).numberValue = 0;
  (param_1->unitsTaskedThisUpdate).desiredNumberValue = 0;
  (param_1->unitsTaskedThisUpdate).maximumSizeValue = 0;
  piVar1 = (param_1->workingArea).value;
  iStack_4._0_1_ = 0xd;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->workingArea).value = (int *)0x0;
  }
  (param_1->workingArea).numberValue = 0;
  (param_1->workingArea).desiredNumberValue = 0;
  (param_1->workingArea).maximumSizeValue = 0;
  piVar1 = (param_1->playersToDefend).value;
  iStack_4._0_1_ = 0xc;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->playersToDefend).value = (int *)0x0;
  }
  (param_1->playersToDefend).numberValue = 0;
  (param_1->playersToDefend).desiredNumberValue = 0;
  (param_1->playersToDefend).maximumSizeValue = 0;
  piVar1 = (param_1->playersToAttack).value;
  iStack_4._0_1_ = 0xb;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->playersToAttack).value = (int *)0x0;
  }
  (param_1->playersToAttack).numberValue = 0;
  (param_1->playersToAttack).desiredNumberValue = 0;
  (param_1->playersToAttack).maximumSizeValue = 0;
  iStack_4._0_1_ = 10;
  TacticalAIGroup::~TacticalAIGroup(&param_1->groups);
  piVar1 = (param_1->artifacts).value;
  iStack_4._0_1_ = 9;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->artifacts).value = (int *)0x0;
  }
  (param_1->artifacts).numberValue = 0;
  (param_1->artifacts).desiredNumberValue = 0;
  (param_1->artifacts).maximumSizeValue = 0;
  piVar1 = (param_1->transportBoats).value;
  iStack_4._0_1_ = 8;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->transportBoats).value = (int *)0x0;
  }
  (param_1->transportBoats).numberValue = 0;
  (param_1->transportBoats).desiredNumberValue = 0;
  (param_1->transportBoats).maximumSizeValue = 0;
  piVar1 = (param_1->tradeBoats).value;
  iStack_4._0_1_ = 7;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->tradeBoats).value = (int *)0x0;
  }
  (param_1->tradeBoats).numberValue = 0;
  (param_1->tradeBoats).desiredNumberValue = 0;
  (param_1->tradeBoats).maximumSizeValue = 0;
  piVar1 = (param_1->fishingBoats).value;
  iStack_4._0_1_ = 6;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->fishingBoats).value = (int *)0x0;
  }
  (param_1->fishingBoats).numberValue = 0;
  (param_1->fishingBoats).desiredNumberValue = 0;
  (param_1->fishingBoats).maximumSizeValue = 0;
  piVar1 = (param_1->warBoats).value;
  iStack_4._0_1_ = 5;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->warBoats).value = (int *)0x0;
  }
  (param_1->warBoats).numberValue = 0;
  (param_1->warBoats).desiredNumberValue = 0;
  (param_1->warBoats).maximumSizeValue = 0;
  piVar1 = (param_1->boats).value;
  iStack_4._0_1_ = 4;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->boats).value = (int *)0x0;
  }
  (param_1->boats).numberValue = 0;
  (param_1->boats).desiredNumberValue = 0;
  (param_1->boats).maximumSizeValue = 0;
  piVar1 = (param_1->ungroupedSoldiers).value;
  iStack_4._0_1_ = 3;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->ungroupedSoldiers).value = (int *)0x0;
  }
  (param_1->ungroupedSoldiers).numberValue = 0;
  (param_1->ungroupedSoldiers).desiredNumberValue = 0;
  (param_1->ungroupedSoldiers).maximumSizeValue = 0;
  piVar1 = (param_1->soldiers).value;
  iStack_4._0_1_ = 2;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->soldiers).value = (int *)0x0;
  }
  (param_1->soldiers).numberValue = 0;
  (param_1->soldiers).desiredNumberValue = 0;
  (param_1->soldiers).maximumSizeValue = 0;
  piVar1 = (param_1->civilianExplorers).value;
  iStack_4._0_1_ = 1;
  if (piVar1 != (int *)0x0) {
    operator_delete(piVar1);
    (param_1->civilianExplorers).value = (int *)0x0;
  }
  (param_1->civilianExplorers).numberValue = 0;
  (param_1->civilianExplorers).desiredNumberValue = 0;
  (param_1->civilianExplorers).maximumSizeValue = 0;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  ManagedArray<int>::~ManagedArray<int>(&param_1->civilians);
  iStack_4 = 0xffffffff;
  TacticalAIModule::~TacticalAIModule((TacticalAIModule *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004eee34
// Address: 004eee34
// XREFS: None
// [HELPER] s_BldLst_Change: "BldLst Change"
// [HELPER] s_BldLst_Insertions: "BldLst Insertions"
// [HELPER] s_Build: "Build"
// [HELPER] s_Eval_CivDist: "Eval CivDist"
// [HELPER] s_Fill_BoatGroups: "Fill BoatGroups"
// [HELPER] s_Fill_SolGroups: "Fill SolGroups"
// [HELPER] s_Food_dropsite: "Food dropsite"
// [HELPER] s_Help_Build: "Help Build"
// [HELPER] s_Invalid: "Invalid"
// [HELPER] s_Open_Builds: "Open Builds"
// [HELPER] s_Open_Tasks: "Open Tasks"
// [HELPER] s_Playtasking: "Playtasking"
// [HELPER] s_Repair_Bldg: "Repair Bldg"
// [HELPER] s_Repair_Wall: "Repair Wall"
// [HELPER] s_Research: "Research"
// [HELPER] s_Setup_BoatGroups: "Setup BoatGroups"
// [HELPER] s_Setup_SolGroups: "Setup SolGroups"
// [HELPER] s_Task_ActSol: "Task ActSol"
// [HELPER] s_Task_Boats: "Task Boats"
// [HELPER] s_Task_Civs: "Task Civs"
// [HELPER] s_Task_IdleSol: "Task IdleSol"
// [HELPER] s_Task_UngrpSol: "Task UngrpSol"
// [HELPER] s_Train: "Train"
char * __fastcall FUN_004eee34(int param_1)
{
  switch(*(undefined4 *)(param_1 + 0xe1c)) {
  case 0:
    return s_Setup_SolGroups;
  case 1:
    return s_Eval_CivDist;
  case 2:
    return s_Task_Civs;
  case 3:
    return s_Setup_BoatGroups;
  case 4:
    return s_Fill_BoatGroups;
  case 5:
    return s_Task_Boats;
  case 6:
    return s_Fill_SolGroups;
  case 7:
    return s_Task_IdleSol;
  case 8:
    return s_Task_ActSol;
  case 9:
    return s_Playtasking;
  case 10:
    return s_Task_UngrpSol;
  case 0xb:
    return s_Research;
  case 0xc:
    return s_Train;
  case 0xd:
    return s_BldLst_Change;
  case 0xe:
    return s_Help_Build;
  case 0xf:
    return s_Repair_Bldg;
  case 0x10:
    return s_Repair_Wall;
  case 0x11:
    return s_Build;
  case 0x12:
    return s_Open_Builds;
  case 0x13:
    return s_Open_Tasks;
  case 0x14:
    return s_Food_dropsite;
  case 0x15:
    return s_BldLst_Insertions;
  default:
    return s_Invalid;
  }
}

// --------------------------------------------------

// Function: FUN_004ef4cd
// Address: 004ef4cd
// XREFS: None
void __thiscall FUN_004ef4cd(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004ef4dd
// Address: 004ef4dd
// XREFS: None
undefined4 __thiscall FUN_004ef4dd(int param_1,int param_2)
{
  TacticalAIGroup *this;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  iStack_4 = *(int *)(param_1 + 0xf8);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar3) {
        ManagedArray<int>::resize((ManagedArray<int> *)(param_1 + 0xf4),iVar3 + 1);
      }
      iStack_4 = ((ManagedArray<int> *)(param_1 + 0xf4))->value[iVar3];
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xf8));
  }
  iStack_4 = *(int *)(param_1 + 0x108);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x108)) {
    do {
      if (*(int *)(param_1 + 0x110) + -1 < iVar3) {
        ManagedArray<int>::resize((ManagedArray<int> *)(param_1 + 0x104),iVar3 + 1);
      }
      iStack_4 = ((ManagedArray<int> *)(param_1 + 0x104))->value[iVar3];
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x108));
  }
  rge_write(param_2,(void *)(param_1 + 0x9cc),4);
  rge_write(param_2,(void *)(param_1 + 0x9d0),4);
  rge_write(param_2,(void *)(param_1 + 0x51c),0x4b0);
  iStack_4 = *(int *)(param_1 + 0x118);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    do {
      if (*(int *)(param_1 + 0x120) + -1 < iVar3) {
        ManagedArray<int>::resize((ManagedArray<int> *)(param_1 + 0x114),iVar3 + 1);
      }
      iStack_4 = ((ManagedArray<int> *)(param_1 + 0x114))->value[iVar3];
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x118));
  }
  iStack_4 = *(int *)(param_1 + 0x128);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x128)) {
    do {
      if (*(int *)(param_1 + 0x130) + -1 < iVar3) {
        ManagedArray<int>::resize((ManagedArray<int> *)(param_1 + 0x124),iVar3 + 1);
      }
      iStack_4 = ((ManagedArray<int> *)(param_1 + 0x124))->value[iVar3];
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x128));
  }
  iStack_4 = *(int *)(param_1 + 0x138);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x138)) {
    do {
      if ((*(int *)(param_1 + 0x140) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x140)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x134) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0x140));
        }
        operator_delete(*(void **)(param_1 + 0x134));
        *(void **)(param_1 + 0x134) = pvVar1;
        *(int *)(param_1 + 0x140) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0x134) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x138));
  }
  iStack_4 = *(int *)(param_1 + 0x148);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x148)) {
    do {
      if ((*(int *)(param_1 + 0x150) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x150)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x144) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0x150));
        }
        operator_delete(*(void **)(param_1 + 0x144));
        *(void **)(param_1 + 0x144) = pvVar1;
        *(int *)(param_1 + 0x150) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0x144) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x148));
  }
  iStack_4 = *(int *)(param_1 + 0x158);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x158)) {
    do {
      if ((*(int *)(param_1 + 0x160) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x160)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x154) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0x160));
        }
        operator_delete(*(void **)(param_1 + 0x154));
        *(void **)(param_1 + 0x154) = pvVar1;
        *(int *)(param_1 + 0x160) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0x154) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x158));
  }
  iStack_4 = *(int *)(param_1 + 0x168);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x168)) {
    do {
      if ((*(int *)(param_1 + 0x170) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x170)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x164) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0x170));
        }
        operator_delete(*(void **)(param_1 + 0x164));
        *(void **)(param_1 + 0x164) = pvVar1;
        *(int *)(param_1 + 0x170) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0x164) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x168));
  }
  iStack_4 = *(int *)(param_1 + 0x178);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x178)) {
    do {
      if ((*(int *)(param_1 + 0x180) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x180)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x174) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0x180));
        }
        operator_delete(*(void **)(param_1 + 0x174));
        *(void **)(param_1 + 0x174) = pvVar1;
        *(int *)(param_1 + 0x180) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0x174) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x178));
  }
  iStack_4 = *(int *)(param_1 + 0x188);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x188)) {
    do {
      if ((*(int *)(param_1 + 400) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 400)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x184) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 400));
        }
        operator_delete(*(void **)(param_1 + 0x184));
        *(void **)(param_1 + 0x184) = pvVar1;
        *(int *)(param_1 + 400) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0x184) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x188));
  }
  iStack_4 = 0xe2;
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < iStack_4) {
    pvVar1 = (void *)(param_1 + 0x194);
    do {
      rge_write(param_2,pvVar1,4);
      iVar3 = iVar3 + 1;
      pvVar1 = (void *)((int)pvVar1 + 4);
    } while (iVar3 < iStack_4);
  }
  iStack_4 = *(int *)(param_1 + 0xd2c);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xd2c)) {
    do {
      if ((*(int *)(param_1 + 0xd34) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0xd34)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0xd28) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0xd34));
        }
        operator_delete(*(void **)(param_1 + 0xd28));
        *(void **)(param_1 + 0xd28) = pvVar1;
        *(int *)(param_1 + 0xd34) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0xd28) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xd2c));
  }
  iStack_4 = *(int *)(param_1 + 0xd3c);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xd3c)) {
    do {
      if ((*(int *)(param_1 + 0xd44) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0xd44)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0xd38) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0xd44));
        }
        operator_delete(*(void **)(param_1 + 0xd38));
        *(void **)(param_1 + 0xd38) = pvVar1;
        *(int *)(param_1 + 0xd44) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0xd38) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xd3c));
  }
  iStack_4 = *(int *)(param_1 + 0xd4c);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xd4c)) {
    do {
      if ((*(int *)(param_1 + 0xd54) + -1 < iVar3) &&
         (pvVar1 = operator_new(iVar3 * 4 + 4), pvVar1 != (void *)0x0)) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0xd54)) {
          do {
            if (iVar3 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0xd48) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0xd54));
        }
        operator_delete(*(void **)(param_1 + 0xd48));
        *(void **)(param_1 + 0xd48) = pvVar1;
        *(int *)(param_1 + 0xd54) = iVar3 + 1;
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0xd48) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xd4c));
  }
  iStack_4 = *(int *)(param_1 + 0xd5c);
  rge_write(param_2,&iStack_4,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xd5c)) {
    do {
      if (*(int *)(param_1 + 0xd64) + -1 < iVar3) {
        pvVar1 = operator_new(iVar3 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0xd64)) {
            do {
              if (iVar3 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xd58) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0xd64));
          }
          operator_delete(*(void **)(param_1 + 0xd58));
          *(void **)(param_1 + 0xd58) = pvVar1;
          *(int *)(param_1 + 0xd64) = iVar3 + 1;
        }
      }
      iStack_4 = *(int *)(*(int *)(param_1 + 0xd58) + iVar3 * 4);
      rge_write(param_2,&iStack_4,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xd5c));
  }
  pvVar1 = (void *)(param_1 + 0xd68);
  iVar3 = 4;
  do {
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pvVar1 = (void *)(param_1 + 0xd78);
  iVar3 = 4;
  do {
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pvVar1 = (void *)(param_1 + 0xd88);
  iVar3 = 4;
  do {
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pvVar1 = (void *)(param_1 + 0xd98);
  iVar3 = 4;
  do {
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pvVar1 = (void *)(param_1 + 0xe24);
  iVar3 = 4;
  do {
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pvVar1 = (void *)(param_1 + 0xe34);
  iVar3 = 4;
  do {
    rge_write(param_2,pvVar1,4);
    pvVar1 = (void *)((int)pvVar1 + 4);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0;
  do {
    iStack_4 = ResourceItem::value((ResourceItem *)(param_1 + 0xda8),iVar3);
    rge_write(param_2,&iStack_4,4);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  rge_write(param_2,(void *)(param_1 + 0xd04),4);
  rge_write(param_2,(void *)(param_1 + 0xd08),4);
  for (this = *(TacticalAIGroup **)(param_1 + 0x9d8);
      (this != (TacticalAIGroup *)(param_1 + 0x9d4) && (this != (TacticalAIGroup *)0x0));
      this = this->next) {
    TacticalAIGroup::save(this,param_2);
  }
  rge_write(param_2,(void *)(param_1 + 0xd0c),4);
  rge_write(param_2,(void *)(param_1 + 0xd10),4);
  rge_write(param_2,(void *)(param_1 + 0xd14),4);
  rge_write(param_2,(void *)(param_1 + 0xd18),4);
  rge_write(param_2,(void *)(param_1 + 0xd1c),4);
  rge_write(param_2,(void *)(param_1 + 0xd20),4);
  rge_write(param_2,(void *)(param_1 + 0xd24),4);
  rge_write(param_2,(void *)(param_1 + 0xe18),4);
  rge_write(param_2,(void *)(param_1 + 0xe1c),4);
  rge_write(param_2,(void *)(param_1 + 0xe44),4);
  rge_write(param_2,(void *)(param_1 + 0xe48),4);
  rge_write(param_2,(void *)(param_1 + 0xe4c),0x130);
  rge_write(param_2,(void *)(param_1 + 0xf7c),4);
  rge_write(param_2,(void *)(param_1 + 0xf80),4);
  rge_write(param_2,(void *)(param_1 + 0xf84),4);
  rge_write(param_2,(void *)(param_1 + 0xf88),4);
  rge_write(param_2,(void *)(param_1 + 0xf8c),4);
  rge_write(param_2,(void *)(param_1 + 0xf90),4);
  rge_write(param_2,(void *)(param_1 + 0xf94),4);
  rge_write(param_2,(void *)(param_1 + 0xf98),4);
  rge_write(param_2,(void *)(param_1 + 0xf9c),4);
  rge_write(param_2,(void *)(param_1 + 0xfa4),4);
  rge_write(param_2,(void *)(param_1 + 4000),4);
  rge_write(param_2,(void *)(param_1 + 0xfa8),4);
  rge_write(param_2,(void *)(param_1 + 0xfac),0x2c);
  rge_write(param_2,(void *)(param_1 + 0xfd8),0x24);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f017e
// Address: 004f017e
// XREFS: None
void FUN_004f017e(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004f0181
// Address: 004f0181
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
// [HELPER] s__s_bld: "%s.bld"
undefined4 __fastcall FUN_004f0181(TribeTacticalAIModule *param_1)
{
  uint uVar1;
  bool bVar2;
  ulong uVar3;
  ulong uVar4;
  char *pcVar5;
  RGE_Static_Object *pRVar6;
  BuildItem *pBVar7;
  ConstructionItem *pCVar8;
  RGE_Static_Object *pRVar9;
  ulong uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  XYPoint XStack_118;
  XYPoint XStack_110;
  XYPoint XStack_108;
  undefined1 auStack_100 [256];
  
  uVar1 = *(uint *)(*(int *)(param_1->md->_padding_ + 0x3c) + 0xf8);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x99c);
  if (uVar1 != 0) {
    do {
      uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x99f);
      bVar2 = true;
      switch(param_1->updateArea) {
      case 0:
        TribeTacticalAIModule::setupSoldierGroups(param_1);
        break;
      case 1:
        if (0 < (param_1->civilians).numberValue) {
          if (param_1->firstNeededResourceUpdateDone == 0) {
            param_1->firstNeededResourceUpdateDone = 1;
            TribeTacticalAIModule::updateNeededResources(param_1);
          }
          TribeTacticalAIModule::evaluateCivilianDistribution(param_1);
        }
        break;
      case 2:
        TribeTacticalAIModule::taskCivilians(param_1,uVar3,uVar1);
        if (param_1->nextCivilianToTaskValue != -1) {
          bVar2 = false;
        }
        break;
      case 3:
        if (0 < (param_1->boats).numberValue) {
          TribeTacticalAIModule::setupBoatGroups(param_1);
        }
        break;
      case 4:
        if (0 < (param_1->boats).numberValue) {
          TribeTacticalAIModule::fillBoatGroups(param_1);
        }
        break;
      case 5:
        if (0 < (param_1->boats).numberValue) {
          TribeTacticalAIModule::taskBoats(param_1);
        }
        break;
      case 6:
        if ((0 < (param_1->boats).numberValue) || (0 < (param_1->soldiers).numberValue)) {
          TribeTacticalAIModule::fillSoldierGroups(param_1);
        }
        break;
      case 7:
        if ((((0 < (param_1->boats).numberValue) || (0 < (param_1->soldiers).numberValue)) ||
            (0 < (param_1->artifacts).numberValue)) &&
           (TribeTacticalAIModule::taskIdleSoldiers(param_1,uVar3,uVar1),
           param_1->nextIdleSoldierGroupToTaskValue != -1)) {
          bVar2 = false;
        }
        break;
      case 8:
        if ((((0 < (param_1->boats).numberValue) || (0 < (param_1->soldiers).numberValue)) ||
            (0 < (param_1->artifacts).numberValue)) &&
           (TribeTacticalAIModule::taskActiveSoldiers(param_1,uVar3,uVar1),
           param_1->nextActiveSoldierGroupToTaskValue != -1)) {
          bVar2 = false;
        }
        break;
      case 9:
        if (0 < (param_1->soldiers).numberValue) {
          TribeTacticalAIModule::playTaskSoldiers(param_1,uVar3,uVar1);
        }
        break;
      case 10:
        pRVar9 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
        if ((pRVar9 != (RGE_Static_Object *)0x0) &&
           (iVar11 = TribeInformationAIModule::withinXTilesOfObject
                               (&param_1->md->informationAI,pRVar9,0x14,0x4f,199,0x45,0x116),
           iVar11 != -1)) {
          TribeTacticalAIModule::saveTheTown(param_1,iVar11);
        }
        break;
      case 0xb:
        param_1->numberBuildUpdatesSkipped = param_1->numberBuildUpdatesSkipped + 1;
        iVar11 = BuildAIModule::buildListLength((BuildAIModule *)&param_1->md->buildAI);
        if (((0 < iVar11) && (param_1->sn[0x65] <= param_1->numberBuildUpdatesSkipped)) &&
           (pBVar7 = TribeBuildAIModule::nextBuildableItem(&param_1->md->buildAI,1),
           pBVar7 != (BuildItem *)0x0)) {
          TribeTacticalAIModule::taskResearch(param_1,pBVar7);
        }
        break;
      case 0xc:
        iVar11 = *(int *)(param_1->md->_padding_ + 0x50);
        if ((((*(float *)(iVar11 + 0x2c) < *(float *)(iVar11 + 0x80)) &&
             (iVar11 = BuildAIModule::buildListLength((BuildAIModule *)&param_1->md->buildAI),
             0 < iVar11)) && (param_1->sn[0x65] <= param_1->numberBuildUpdatesSkipped)) &&
           (pBVar7 = TribeBuildAIModule::nextBuildableItem(&param_1->md->buildAI,2),
           pBVar7 != (BuildItem *)0x0)) {
          TribeTacticalAIModule::taskTrain(param_1,pBVar7);
        }
        break;
      case 0xd:
        iVar11 = BuildAIModule::buildListLength((BuildAIModule *)&param_1->md->buildAI);
        if ((0 < iVar11) && (param_1->sn[0x65] <= param_1->numberBuildUpdatesSkipped)) {
          pBVar7 = TribeBuildAIModule::nextBuildableItem(&param_1->md->buildAI,3);
          if (pBVar7 != (BuildItem *)0x0) {
            pcVar5 = BaseItem::name((BaseItem *)pBVar7);
            sprintf(auStack_100,s__s_bld,pcVar5);
            (**(code **)((param_1->md->buildAI)._padding_ + 0x44))
                      (auStack_100,param_1->md->aiPlayer);
            TribeMainDecisionAIModule::updateBuildAIWithObjects(param_1->md);
            TribeTacticalAIModule::updateNeededResources(param_1);
          }
          param_1->numberBuildUpdatesSkipped = 0;
        }
        break;
      case 0xe:
        iVar11 = TribeTacticalAIModule::initialExplorationSatisfied(param_1);
        if ((iVar11 != 0) &&
           ((((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                  ((MainDecisionAIModule *)param_1->md,0x25a),
              iVar11 < param_1->sn[4] || (param_1->wonderInProgressValue != 0)) ||
             (param_1->wonderBuiltValue != 0)) &&
            ((pRVar9 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)param_1->md,-1,-1,-1,-1,-1,-1,-1,-1,0,-1),
             pRVar9 != (RGE_Static_Object *)0x0 &&
             ((pRVar6 = MainDecisionAIModule::object
                                  ((MainDecisionAIModule *)param_1->md,-1,-1,-1,0x25a,-1,pRVar9->id,
                                   -1,-1,-1,-1), param_1->wonderInProgressValue != 0 ||
              (pRVar6 == (RGE_Static_Object *)0x0)))))))) {
          XStack_108.x = __ftol();
          XStack_108.y = __ftol();
          iVar11 = TribeTacticalAIModule::civilian(param_1,&XStack_108,1,0x2be,0x2ce,700,0);
          if ((iVar11 != -1) &&
             (iVar11 = TribeTacticalAIModule::taskBuilder(param_1,iVar11,pRVar9), iVar11 == 1)) {
            param_1->lastBuildTime = *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
          }
        }
        break;
      case 0xf:
        iVar11 = TribeTacticalAIModule::initialExplorationSatisfied(param_1);
        if ((iVar11 != 0) &&
           (((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                 ((MainDecisionAIModule *)param_1->md,0x25a),
             iVar11 < param_1->sn[4] || (param_1->wonderInProgressValue != 0)) ||
            (param_1->wonderBuiltValue != 0)))) {
          if (param_1->wonderBuiltValue == 1) {
            iVar11 = 0x114;
          }
          else {
            iVar11 = -1;
          }
          pRVar9 = MainDecisionAIModule::mostDamaged((MainDecisionAIModule *)param_1->md,3,iVar11);
          if (((pRVar9 != (RGE_Static_Object *)0x0) && (pRVar9->object_state == '\x02')) &&
             (pRVar6 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)param_1->md,-1,-1,-1,0x26a,-1,pRVar9->id,
                                  -1,-1,-1,-1), pRVar6 == (RGE_Static_Object *)0x0)) {
            XStack_118.x = __ftol();
            XStack_118.y = __ftol();
            iVar11 = TribeTacticalAIModule::civilian(param_1,&XStack_118,1,0x2be,0x2ce,700,0);
            if (iVar11 != -1) {
              TribeTacticalAIModule::taskRepairer(param_1,iVar11,pRVar9);
            }
          }
        }
        break;
      case 0x10:
        iVar11 = TribeTacticalAIModule::initialExplorationSatisfied(param_1);
        if (((iVar11 != 0) &&
            ((((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                   ((MainDecisionAIModule *)param_1->md,0x25a),
               iVar11 < param_1->sn[4] || (param_1->wonderInProgressValue != 0)) ||
              (param_1->wonderBuiltValue != 0)) &&
             ((pRVar9 = MainDecisionAIModule::mostDamaged
                                  ((MainDecisionAIModule *)param_1->md,0x1b,-1),
              pRVar9 != (RGE_Static_Object *)0x0 && (pRVar9->object_state == '\x02')))))) &&
           (pRVar6 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1->md,-1,-1,-1,0x26a,-1,pRVar9->id,-1,
                                -1,-1,-1), pRVar6 == (RGE_Static_Object *)0x0)) {
          XStack_110.x = __ftol();
          XStack_110.y = __ftol();
          iVar11 = TribeTacticalAIModule::civilian(param_1,&XStack_110,1,0x2be,0x2ce,700,0);
          if (iVar11 != -1) {
            TribeTacticalAIModule::taskRepairer(param_1,iVar11,pRVar9);
          }
        }
        break;
      case 0x11:
        iVar11 = TribeTacticalAIModule::initialExplorationSatisfied(param_1);
        if ((((iVar11 != 0) &&
             ((iVar11 = MainDecisionAIModule::numberObjectsWithAction
                                  ((MainDecisionAIModule *)param_1->md,0x25a),
              iVar11 < param_1->sn[4] ||
              ((param_1->wonderInProgressValue == 0 && (param_1->wonderBuiltValue != 0)))))) &&
            (param_1->wonderInProgressValue == 0)) &&
           ((pBVar7 = TribeBuildAIModule::nextBuildableItem(&param_1->md->buildAI,0),
            pBVar7 != (BuildItem *)0x0 &&
            (iVar11 = TribeTacticalAIModule::taskBuilder
                                (param_1,-1,pBVar7,(ConstructionItem *)0x0,uVar3), iVar11 == 1)))) {
          param_1->lastBuildTime = *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
        }
        break;
      case 0x12:
        if ((param_1->placementStateValue).active == 1) {
          pCVar8 = TribeConstructionAIModule::placeStructure
                             (&param_1->md->constructionAI,(param_1->placementStateValue).buildItem,
                              (param_1->placementStateValue).builderID,&param_1->placementStateValue
                              ,uVar3);
          if ((pCVar8 != (ConstructionItem *)0x0) &&
             (iVar11 = TribeTacticalAIModule::taskBuilder
                                 (param_1,(param_1->placementStateValue).builderID,
                                  (param_1->placementStateValue).buildItem,pCVar8,uVar3),
             iVar11 == 1)) {
            param_1->lastBuildTime = *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
          }
          if ((param_1->placementStateValue).active == 1) {
            bVar2 = false;
          }
        }
        break;
      case 0x13:
        TribeTacticalAIModule::evaluateOpenTasks(param_1);
        iVar11 = 0;
        piVar12 = param_1->resourceDifferenceValue;
        do {
          if ((0 < *piVar12) &&
             (iVar13 = TribeResourceAIModule::resource(&param_1->md->resourceAI,iVar11),
             iVar13 + *piVar12 < 0)) {
            TribeTacticalAIModule::updateNeededResources(param_1);
            break;
          }
          iVar11 = iVar11 + 1;
          piVar12 = piVar12 + 1;
        } while (iVar11 < 4);
        TribeTacticalAIModule::checkForCoopTributeDemand(param_1);
        TribeTacticalAIModule::checkForCoopTributeGift(param_1);
        TribeTacticalAIModule::checkForASAPAgeResearch(param_1);
        TribeTacticalAIModule::checkTradeBoats(param_1);
        TribeTacticalAIModule::checkStaleAttackGroups(param_1);
        break;
      case 0x14:
        iVar11 = TribeInformationAIModule::closestDropsiteResID(&param_1->md->informationAI,0);
        pRVar9 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar11);
        if (pRVar9 == (RGE_Static_Object *)0x0) {
          TribeInformationAIModule::updateResourceDropsites(&param_1->md->informationAI,0);
        }
        break;
      case 0x15:
        TribeTacticalAIModule::evaluateBuildListInsertions(param_1);
        if (5 < (int)(*(int *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4) - param_1->lastBuildTime
                     ) / 60000) {
          TribeBuildAIModule::unskipBuildList
                    (&param_1->md->buildAI,param_1->builtFirstStoragePit,param_1->builtFirstGranary)
          ;
          param_1->lastBuildTime = *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
        }
        uVar10 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xb92);
        RGE_Game_World::useComputerPlayerUpdateTime
                  (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),uVar10 - uVar3);
        iVar11 = param_1->updateAreaAverageTotal + (uVar10 - uVar4);
        iVar13 = param_1->updateAreaAverageCount + 1;
        param_1->lastUpdateAreaTimeValue = uVar10 - uVar4;
        param_1->updateAreaAverageTotal = iVar11;
        param_1->updateAreaAverageCount = iVar13;
        if (0x13 < iVar13) {
          param_1->updateAreaAverageTotal = 0;
          param_1->updateAreaAverageCount = 0;
          param_1->averageUpdateAreaTimeValue = iVar11 / iVar13;
        }
        param_1->updateArea = 0;
        RGE_Game_World::selectNextComputerPlayer
                  (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),3);
        return 1;
      }
      uVar10 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xbaa);
      iVar11 = param_1->updateAreaAverageTotal + (uVar10 - uVar4);
      iVar13 = param_1->updateAreaAverageCount + 1;
      param_1->lastUpdateAreaTimeValue = uVar10 - uVar4;
      param_1->updateAreaAverageTotal = iVar11;
      param_1->updateAreaAverageCount = iVar13;
      if (0x13 < iVar13) {
        param_1->updateAreaAverageTotal = 0;
        param_1->updateAreaAverageCount = 0;
        param_1->averageUpdateAreaTimeValue = iVar11 / 0x14;
      }
      if (bVar2) {
        param_1->updateArea = param_1->updateArea + 1;
      }
    } while (uVar10 - uVar3 < uVar1);
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xbc9);
  RGE_Game_World::useComputerPlayerUpdateTime
            (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),uVar4 - uVar3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f0b62
// Address: 004f0b62
// XREFS: None
/* WARNING: Instruction at (ram,0x004f0b78) overlaps instruction at (ram,0x004f0b77)
    */

char * __fastcall FUN_004f0b62(char param_1,uint *param_2)
{
  char *pcVar1;
  uint uVar2;
  uint in_EAX;
  char *pcVar3;
  char cVar4;
  char cVar5;
  undefined2 unaff_BX;
  int unaff_EDI;
  char *pcVar6;
  char *pcVar7;
  undefined2 in_DS;
  
  uVar2 = *param_2;
  pcVar6 = (char *)(unaff_EDI + -1);
  *pcVar6 = *pcVar6 + (char)param_2;
  cVar4 = param_1 + *pcVar6 + *pcVar6;
  pcVar1 = (char *)segment(in_DS,unaff_BX);
  cVar5 = cVar4 + *pcVar1;
  pcVar3 = (char *)((in_EAX | uVar2) - 1);
  pcVar7 = pcVar6;
  if (cVar5 != '\0' && SCARRY1(cVar4,*pcVar1) == cVar5 < '\0') {
    pcVar7 = (char *)((in_EAX | uVar2) + 3);
    pcVar3 = pcVar6;
  }
  pcVar7[-0x50ffb0ff] = pcVar7[-0x50ffb0ff] + (char)param_2;
  return pcVar3;
}

// --------------------------------------------------

// Function: FUN_004f0d4d
// Address: 004f0d4d
// XREFS: None
void __fastcall
FUN_004f0d4d(int param_1,char param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  char *pcVar1;
  short sVar2;
  uint in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  ManagedArray<int> *pMVar10;
  int unaff_EDI;
  
  iVar8 = param_5;
  iVar7 = CONCAT31((int3)((uint)param_1 >> 8),(byte)param_1 ^ *(byte *)(unaff_EDI + param_1 * 2));
  cVar9 = (char)((uint)param_1 >> 8);
  (&stack0x0000004f)[iVar7] = (&stack0x0000004f)[iVar7] + cVar9;
  *(char *)(in_EAX + 0xc) = *(char *)(in_EAX + 0xc) + param_2;
  *(char *)(in_EAX + 0x60004f0c) = *(char *)(in_EAX + 0x60004f0c) + param_2;
  (&stack0x0000004f)[iVar7] = (&stack0x0000004f)[iVar7] + cVar9;
  pcVar1 = (char *)((in_EAX | 0x4f) + 0x90004f0c);
  *pcVar1 = *pcVar1 + (char)(in_EAX | 0x4f);
  *(char *)(iVar7 + 0x53) = *(char *)(iVar7 + 0x53) + param_2;
  sVar2 = *(short *)(*(int *)(param_5 + 8) + 0x14);
  param_3 = iVar7;
  if (sVar2 == 4) {
    iVar8 = *(int *)(iVar7 + 0xf8);
    iVar4 = *(int *)(param_5 + 4);
    pMVar10 = (ManagedArray<int> *)(iVar7 + 0xf4);
    iVar3 = 0;
    if (0 < iVar8) {
      do {
        if (*(int *)(iVar7 + 0x100) <= iVar3) break;
        if (pMVar10->value[iVar3] == iVar4) {
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar8);
    }
    if (iVar8 <= *(int *)(iVar7 + 0x100) + -1) goto LAB_004f1077;
  }
  else {
    if ((((((sVar2 != 0) && (sVar2 != 0x18)) && (sVar2 != 6)) &&
         (((sVar2 != 0x19 && (sVar2 != 0x1a)) &&
          ((sVar2 != 0xc && ((sVar2 != 0x23 && (sVar2 != 0x17)))))))) && (sVar2 != 0x24)) &&
       ((((sVar2 != 0x1c && (sVar2 != 0x12)) && (sVar2 != 0xd)) && (sVar2 != 0x27)))) {
      if (((sVar2 != 2) && (sVar2 != 0x14)) && ((sVar2 != 0x16 && (sVar2 != 0x15)))) {
        if (*(short *)(*(int *)(param_5 + 8) + 0x10) != 0x9f) {
          return;
        }
        iVar4 = RGE_Game_World::difficultyLevel
                          (*(RGE_Game_World **)(*(int *)(*(int *)(iVar7 + 0xf0) + 0xf0) + 0x3c));
        if (3 < iVar4) {
          return;
        }
        ManagedArray<int>::add((ManagedArray<int> *)(iVar7 + 0x184),*(int *)(iVar8 + 4));
        return;
      }
      iVar4 = *(int *)(iVar7 + 0x138);
      iVar3 = *(int *)(param_5 + 4);
      pMVar10 = (ManagedArray<int> *)(iVar7 + 0x134);
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          if (*(int *)(iVar7 + 0x140) <= iVar5) break;
          if (pMVar10->value[iVar5] == iVar3) goto LAB_004f0ee8;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      if (*(int *)(iVar7 + 0x140) + -1 < iVar4) {
        ManagedArray<int>::resize(pMVar10,iVar4 + 1);
      }
      pMVar10->value[*(int *)(iVar7 + 0x138)] = iVar3;
      *(int *)(iVar7 + 0x138) = *(int *)(iVar7 + 0x138) + 1;
LAB_004f0ee8:
      iVar4 = iVar7;
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) == 2) {
        iVar3 = *(int *)(iVar7 + 0x168);
        iVar5 = *(int *)(iVar8 + 4);
        pMVar10 = (ManagedArray<int> *)(iVar7 + 0x164);
        iVar6 = 0;
        if (0 < iVar3) {
          do {
            if (*(int *)(iVar7 + 0x170) <= iVar6) break;
            iVar4 = param_3;
            if (pMVar10->value[iVar6] == iVar5) goto LAB_004f0f45;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar3);
        }
        if (*(int *)(iVar7 + 0x170) + -1 < iVar3) {
          ManagedArray<int>::resize(pMVar10,iVar3 + 1);
        }
        pMVar10->value[*(int *)(iVar7 + 0x168)] = iVar5;
        *(int *)(iVar7 + 0x168) = *(int *)(iVar7 + 0x168) + 1;
      }
LAB_004f0f45:
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) == 0x14) {
        param_5 = *(int *)(iVar8 + 4);
        pMVar10 = (ManagedArray<int> *)(iVar4 + 0x174);
        iVar7 = ManagedArray<int>::contains(pMVar10,&param_5);
        if (iVar7 != 1) {
          if (*(int *)(iVar4 + 0x180) + -1 < *(int *)(iVar4 + 0x178)) {
            ManagedArray<int>::resize(pMVar10,*(int *)(iVar4 + 0x178) + 1);
          }
          pMVar10->value[*(int *)(iVar4 + 0x178)] = param_5;
          *(int *)(iVar4 + 0x178) = *(int *)(iVar4 + 0x178) + 1;
        }
      }
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) == 0x16) {
        param_5 = *(int *)(iVar8 + 4);
        pMVar10 = (ManagedArray<int> *)(iVar4 + 0x144);
        iVar7 = ManagedArray<int>::contains(pMVar10,&param_5);
        if (iVar7 != 1) {
          if (*(int *)(iVar4 + 0x150) + -1 < *(int *)(iVar4 + 0x148)) {
            ManagedArray<int>::resize(pMVar10,*(int *)(iVar4 + 0x148) + 1);
          }
          pMVar10->value[*(int *)(iVar4 + 0x148)] = param_5;
          *(int *)(iVar4 + 0x148) = *(int *)(iVar4 + 0x148) + 1;
        }
      }
      if (*(short *)(*(int *)(iVar8 + 8) + 0x14) != 0x15) {
        return;
      }
      param_5 = *(int *)(iVar8 + 4);
      pMVar10 = (ManagedArray<int> *)(iVar4 + 0x154);
      iVar8 = ManagedArray<int>::contains(pMVar10,&param_5);
      if (iVar8 == 1) {
        return;
      }
      if (*(int *)(iVar4 + 0x160) + -1 < *(int *)(iVar4 + 0x158)) {
        ManagedArray<int>::resize(pMVar10,*(int *)(iVar4 + 0x158) + 1);
      }
      pMVar10->value[*(int *)(iVar4 + 0x158)] = param_5;
      *(int *)(iVar4 + 0x158) = *(int *)(iVar4 + 0x158) + 1;
      return;
    }
    iVar8 = *(int *)(iVar7 + 0x118);
    iVar4 = *(int *)(param_5 + 4);
    pMVar10 = (ManagedArray<int> *)(iVar7 + 0x114);
    iVar3 = 0;
    if (0 < iVar8) {
      do {
        if (*(int *)(iVar7 + 0x120) <= iVar3) break;
        if (pMVar10->value[iVar3] == iVar4) {
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar8);
    }
    if (iVar8 <= *(int *)(iVar7 + 0x120) + -1) goto LAB_004f1077;
  }
  ManagedArray<int>::resize(pMVar10,iVar8 + 1);
LAB_004f1077:
  pMVar10->value[pMVar10->numberValue] = iVar4;
  pMVar10->numberValue = pMVar10->numberValue + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004f108e
// Address: 004f108e
// XREFS: None
void __thiscall FUN_004f108e(TribeTacticalAIModule *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  ManagedArray<int> *this;
  
  TribeTacticalAIModule::removeFromTaskLists(param_1,param_2);
  iVar2 = (param_1->civilians).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((param_1->civilians).maximumSizeValue <= iVar1) break;
      if ((param_1->civilians).value[iVar1] == param_2) {
        iVar2 = (param_1->civilians).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f1343;
        piVar3 = (param_1->civilians).value;
        goto LAB_004f1337;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  iVar2 = (param_1->soldiers).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((param_1->soldiers).maximumSizeValue <= iVar1) break;
      if ((param_1->soldiers).value[iVar1] == param_2) {
        iVar2 = (param_1->soldiers).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f1120;
        piVar3 = (param_1->soldiers).value;
        goto LAB_004f1114;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  iVar2 = (param_1->boats).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((param_1->boats).maximumSizeValue <= iVar1) break;
      if ((param_1->boats).value[iVar1] == param_2) {
        iVar2 = (param_1->boats).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f11c4;
        piVar3 = (param_1->boats).value;
        goto LAB_004f11b8;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  this = &param_1->artifacts;
  iVar2 = ManagedArray<int>::contains(this,&param_2);
joined_r0x004f12e7:
  if (iVar2 == 0) goto LAB_004f1316;
  goto LAB_004f130b;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f1337:
    if (*piVar3 == param_2) break;
  }
LAB_004f1343:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (param_1->civilians).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (param_1->civilians).maximumSizeValue + -1);
    }
    iVar2 = (param_1->civilians).numberValue + -1;
    (param_1->civilians).numberValue = iVar2;
    if (iVar2 < 0) {
      (param_1->civilians).numberValue = 0;
      TribeTacticalAIModule::removeFromGroup(param_1,param_2);
      return;
    }
  }
  goto LAB_004f1316;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f1114:
    if (*piVar3 == param_2) break;
  }
LAB_004f1120:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (param_1->soldiers).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (param_1->soldiers).maximumSizeValue + -1);
    }
    iVar2 = (param_1->soldiers).numberValue + -1;
    (param_1->soldiers).numberValue = iVar2;
    if (iVar2 < 0) {
      (param_1->soldiers).numberValue = 0;
      TribeTacticalAIModule::removeFromGroup(param_1,param_2);
      return;
    }
  }
  goto LAB_004f1316;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f11b8:
    if (*piVar3 == param_2) break;
  }
LAB_004f11c4:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (param_1->boats).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (param_1->boats).maximumSizeValue + -1);
    }
    iVar2 = (param_1->boats).numberValue + -1;
    (param_1->boats).numberValue = iVar2;
    if (iVar2 < 0) {
      (param_1->boats).numberValue = 0;
    }
  }
  iVar2 = (param_1->warBoats).numberValue;
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      if ((param_1->warBoats).maximumSizeValue <= iVar1) break;
      if ((param_1->warBoats).value[iVar1] == param_2) {
        iVar2 = (param_1->warBoats).maximumSizeValue;
        iVar1 = 0;
        if (iVar2 < 1) goto LAB_004f124e;
        piVar3 = (param_1->warBoats).value;
        goto LAB_004f1242;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  this = &param_1->fishingBoats;
  iVar2 = ManagedArray<int>::contains(this,&param_2);
  if (iVar2 == 0) {
    this = &param_1->tradeBoats;
    iVar2 = ManagedArray<int>::contains(this,&param_2);
    if (iVar2 == 0) {
      this = &param_1->transportBoats;
      iVar2 = ManagedArray<int>::contains(this,&param_2);
      goto joined_r0x004f12e7;
    }
  }
LAB_004f130b:
  ManagedArray<int>::remove(this,param_2);
  goto LAB_004f1316;
  while( true ) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 <= iVar1) break;
LAB_004f1242:
    if (*piVar3 == param_2) break;
  }
LAB_004f124e:
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (param_1->warBoats).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (param_1->warBoats).maximumSizeValue + -1);
    }
    iVar2 = (param_1->warBoats).numberValue + -1;
    (param_1->warBoats).numberValue = iVar2;
    if (iVar2 < 0) {
      (param_1->warBoats).numberValue = 0;
      TribeTacticalAIModule::removeFromGroup(param_1,param_2);
      return;
    }
  }
LAB_004f1316:
  TribeTacticalAIModule::removeFromGroup(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004f138d
// Address: 004f138d
// XREFS: None
undefined4 __thiscall FUN_004f138d(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_1[3];
  iVar2 = 0;
  if (0 < iVar1) {
    piVar3 = (int *)*param_1;
    do {
      if (*piVar3 == param_2) break;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar1 <= iVar2) {
    return 0;
  }
  if (iVar2 < iVar1 + -1) {
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*param_1 + -4 + iVar2 * 4) = *(undefined4 *)(*param_1 + iVar2 * 4);
    } while (iVar2 < param_1[3] + -1);
  }
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  if (iVar1 + -1 < 0) {
    param_1[1] = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f13e9
// Address: 004f13e9
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f13e9(TribeTacticalAIModule *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  RGE_Visible_Map::percentExplored(*(RGE_Visible_Map **)(param_1->md->_padding_ + 0x38));
  iVar1 = __ftol();
  if ((param_1->playersToAttack).maximumSizeValue + -1 < 0) {
    ManagedArray<int>::resize(&param_1->playersToAttack,1);
  }
  iVar2 = TribeInformationAIModule::numberGameIDsOwnedBy
                    (&param_1->md->informationAI,-1,*(param_1->playersToAttack).value);
  iVar3 = (param_1->civilians).numberValue;
  if (iVar3 < 3) {
    iVar1 = 1;
    if (iVar3 == 1) {
      param_1->desiredNumberGatherersValue = 0;
    }
    else {
      iVar1 = param_1->sn[5];
      param_1->desiredNumberGatherersValue = 1;
      if ((iVar1 != -1) && (iVar1 < 1)) {
        param_1->desiredNumberGatherersValue = iVar1;
      }
      iVar3 = (param_1->civilians).numberValue - param_1->desiredNumberGatherersValue;
      (param_1->civilianExplorers).desiredNumberValue = iVar3;
      iVar1 = param_1->sn[3];
      if ((iVar1 == -1) || (iVar3 <= iVar1)) goto LAB_004f15df;
    }
    (param_1->civilianExplorers).desiredNumberValue = iVar1;
    goto LAB_004f15df;
  }
  if ((param_1->civilians).maximumSizeValue + -1 < 0) {
    ManagedArray<int>::resize(&param_1->civilians,1);
  }
  iVar3 = TribeInformationAIModule::fullyExploredZone
                    (&param_1->md->informationAI,*(param_1->civilians).value);
  if (iVar3 == 1) {
    ceil((double)((float)param_1->sn[0] * (float)(param_1->civilians).numberValue * _DAT_00575764));
    iVar3 = __ftol();
    (param_1->civilianExplorers).desiredNumberValue = iVar3;
    iVar3 = TribeTacticalAIModule::numberSoldierExplorers(param_1);
    if (param_1->sn[0x12] < iVar3 + (param_1->civilianExplorers).desiredNumberValue) {
      (param_1->civilianExplorers).desiredNumberValue = param_1->sn[0x12] - iVar3;
    }
    iVar3 = param_1->sn[3];
    if ((iVar3 != -1) && (iVar3 < (param_1->civilianExplorers).desiredNumberValue)) {
      (param_1->civilianExplorers).desiredNumberValue = iVar3;
    }
  }
  else {
    (param_1->civilianExplorers).desiredNumberValue = 0;
  }
  if ((iVar1 < param_1->sn[0x20]) || (iVar2 <= param_1->sn[0x91])) {
    if (param_1->sn[0xb3] <= iVar1) {
      iVar1 = (param_1->civilianExplorers).desiredNumberValue / 2;
      if (iVar1 < 1) {
        iVar1 = 0;
      }
      goto LAB_004f1535;
    }
  }
  else {
    iVar1 = param_1->sn[0x23];
    if (iVar1 < (param_1->civilianExplorers).desiredNumberValue) {
LAB_004f1535:
      (param_1->civilianExplorers).desiredNumberValue = iVar1;
    }
  }
  if (param_1->zoomingToNextAge == 1) {
    (param_1->civilianExplorers).desiredNumberValue = 0;
  }
  iVar1 = param_1->sn[5];
  iVar3 = (param_1->civilians).numberValue - (param_1->civilianExplorers).desiredNumberValue;
  param_1->desiredNumberGatherersValue = iVar3;
  if ((iVar1 != -1) && (iVar1 < iVar3)) {
    param_1->desiredNumberGatherersValue = iVar1;
    TribeTacticalAIModule::displayCivilianDistribution(param_1);
    TribeTacticalAIModule::updateGathererDistribution(param_1);
    return;
  }
LAB_004f15df:
  TribeTacticalAIModule::displayCivilianDistribution(param_1);
  TribeTacticalAIModule::updateGathererDistribution(param_1);
  return;
}

// --------------------------------------------------

