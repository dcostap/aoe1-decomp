// GLOBAL FUNCTIONS PART 4400
// Function: FUN_004f15f2
// Address: 004f15f2
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004f15f2(TribeTacticalAIModule *param_1,ulong param_2,uint param_3)
{
  ManagedArray<int> *this;
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  UnitData *pUVar7;
  ulong uVar8;
  uint uStack_14;
  int iStack_10;
  int iStack_c;
  XYPoint XStack_8;
  
  if ((param_1->civilians).numberValue < 1) {
    param_1->nextCivilianToTaskValue = -1;
    return 0;
  }
  iStack_c = 0;
  if (param_1->nextCivilianToTaskValue == -1) {
    if ((param_1->civilianExplorers).numberValue < (param_1->civilianExplorers).desiredNumberValue)
{
      do {
        pRVar1 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
        if (pRVar1 == (RGE_Static_Object *)0x0) {
          iVar2 = TribeTacticalAIModule::idleCivilian(param_1,-1);
        }
        else {
          XStack_8.x = __ftol();
          XStack_8.y = __ftol();
          iVar2 = TribeTacticalAIModule::idleCivilian(param_1,-1,&XStack_8,0);
        }
        if (iVar2 == -1) {
          if (param_1->desiredNumberGatherersValue < param_1->numberGatherersValue) {
            uStack_14 = 3;
            piVar5 = param_1->neededResourceValue + 3;
            iStack_10 = iVar2;
            do {
              if (iVar2 != -1) goto LAB_004f1799;
              pRVar1 = MainDecisionAIModule::object
                                 ((MainDecisionAIModule *)param_1->md,-1,-1,-1,0x261,0x25d,-1,-1,
                                  *piVar5,-1,0);
              if (((pRVar1 != (RGE_Static_Object *)0x0) ||
                  (pRVar1 = MainDecisionAIModule::object
                                      ((MainDecisionAIModule *)param_1->md,-1,-1,-1,0x265,0x25d,-1,
                                       -1,*piVar5,-1,0), pRVar1 != (RGE_Static_Object *)0x0)) &&
                 (pRVar1->attribute_amount_held == _DAT_005756f0)) {
                iVar6 = (param_1->civilianExplorers).numberValue;
                iVar4 = pRVar1->id;
                iVar3 = 0;
                if (0 < iVar6) {
                  do {
                    if ((param_1->civilianExplorers).maximumSizeValue <= iVar3) break;
                    iVar2 = iStack_10;
                    if ((param_1->civilianExplorers).value[iVar3] == iVar4) goto LAB_004f177f;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < iVar6);
                }
                TribeTacticalAIModule::removeGatherer(param_1,iVar4);
                iVar2 = iVar4;
                iStack_10 = iVar4;
              }
LAB_004f177f:
              piVar5 = piVar5 + -1;
              uStack_14 = uStack_14 - 1;
            } while (uStack_14 < 0x80000000);
          }
          if (iVar2 == -1) break;
        }
LAB_004f1799:
        iVar6 = (param_1->civilianExplorers).numberValue;
        this = &param_1->civilianExplorers;
        iVar4 = 0;
        if (0 < iVar6) {
          do {
            if ((param_1->civilianExplorers).maximumSizeValue <= iVar4) break;
            if (this->value[iVar4] == iVar2) goto LAB_004f17f1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar6);
        }
        if ((param_1->civilianExplorers).maximumSizeValue + -1 < iVar6) {
          ManagedArray<int>::resize(this,iVar6 + 1);
        }
        this->value[(param_1->civilianExplorers).numberValue] = iVar2;
        (param_1->civilianExplorers).numberValue = (param_1->civilianExplorers).numberValue + 1;
      } while ((param_1->civilianExplorers).numberValue <
               (param_1->civilianExplorers).desiredNumberValue);
    }
LAB_004f17f1:
    iVar2 = (param_1->civilianExplorers).numberValue;
    if ((param_1->civilianExplorers).desiredNumberValue < iVar2) {
      do {
        if (iVar2 < 1) break;
        if (((param_1->civilianExplorers).maximumSizeValue + -1 < 0) &&
           (piVar5 = (int *)operator_new(4), piVar5 != (int *)0x0)) {
          iVar2 = 0;
          if (0 < (param_1->civilianExplorers).maximumSizeValue) {
            do {
              if (0 < iVar2) break;
              iVar6 = iVar2 + 1;
              piVar5[iVar2] = (param_1->civilianExplorers).value[iVar2];
              iVar2 = iVar6;
            } while (iVar6 < (param_1->civilianExplorers).maximumSizeValue);
          }
          operator_delete((param_1->civilianExplorers).value);
          (param_1->civilianExplorers).value = piVar5;
          (param_1->civilianExplorers).maximumSizeValue = 1;
        }
        iVar4 = 0;
        iVar2 = *(param_1->civilianExplorers).value;
        iVar6 = (param_1->civilianExplorers).maximumSizeValue;
        if (0 < iVar6) {
          piVar5 = (param_1->civilianExplorers).value;
          do {
            if (*piVar5 == iVar2) break;
            iVar4 = iVar4 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar4 < iVar6);
        }
        if (iVar4 < iVar6) {
          if (iVar4 < iVar6 + -1) {
            do {
              piVar5 = (param_1->civilianExplorers).value;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = piVar5[iVar6];
              iVar4 = iVar6;
            } while (iVar6 < (param_1->civilianExplorers).maximumSizeValue + -1);
          }
          iVar6 = (param_1->civilianExplorers).numberValue + -1;
          (param_1->civilianExplorers).numberValue = iVar6;
          if (iVar6 < 0) {
            (param_1->civilianExplorers).numberValue = 0;
          }
        }
        TribeTacticalAIModule::stopUnit(param_1,iVar2,100);
        iVar2 = (param_1->civilianExplorers).numberValue;
      } while ((param_1->civilianExplorers).desiredNumberValue < iVar2);
    }
    if (param_1->numberGatherersValue < param_1->desiredNumberGatherersValue) {
      do {
        pRVar1 = MainDecisionAIModule::object
                           ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
        if (pRVar1 == (RGE_Static_Object *)0x0) {
          iVar2 = TribeTacticalAIModule::idleCivilian(param_1,-1);
        }
        else {
          XStack_8.x = __ftol();
          XStack_8.y = __ftol();
          iVar2 = TribeTacticalAIModule::idleCivilian(param_1,-1,&XStack_8,0);
        }
      } while (((iVar2 != -1) &&
               (pUVar7 = TribeTacticalAIModule::addGatherer(param_1,iVar2),
               pUVar7 != (UnitData *)0x0)) &&
              (param_1->numberGatherersValue < param_1->desiredNumberGatherersValue));
    }
    if ((param_1->civilians).maximumSizeValue + -1 < 0) {
      ManagedArray<int>::resize(&param_1->civilians,1);
    }
    param_1->nextCivilianToTaskValue = *(param_1->civilians).value;
    uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xd8a);
    if (param_3 <= uVar8 - param_2) {
      return 0;
    }
  }
  iVar2 = 0;
  if (0 < (param_1->civilians).numberValue) {
    do {
      if ((param_1->civilians).maximumSizeValue + -1 < iVar2) {
        piVar5 = (int *)operator_new(iVar2 * 4 + 4);
        if (piVar5 != (int *)0x0) {
          iVar6 = 0;
          if (0 < (param_1->civilians).maximumSizeValue) {
            do {
              if (iVar2 + 1 <= iVar6) break;
              iVar4 = iVar6 + 1;
              piVar5[iVar6] = (param_1->civilians).value[iVar6];
              iVar6 = iVar4;
            } while (iVar4 < (param_1->civilians).maximumSizeValue);
          }
          operator_delete((param_1->civilians).value);
          (param_1->civilians).value = piVar5;
          (param_1->civilians).maximumSizeValue = iVar2 + 1;
        }
      }
    } while ((param_1->nextCivilianToTaskValue != (param_1->civilians).value[iVar2]) &&
            (iVar2 = iVar2 + 1, iVar2 < (param_1->civilians).numberValue));
  }
  if ((param_1->civilians).numberValue <= iVar2) {
LAB_004f1d72:
    param_1->nextCivilianToTaskValue = -1;
    return iStack_c;
  }
  iStack_10 = iVar2 + 1;
  uStack_14 = iStack_10 * 4;
LAB_004f1a80:
  iStack_c = iStack_c + 1;
  if (((param_1->civilians).maximumSizeValue + -1 < iVar2) &&
     (piVar5 = (int *)operator_new(uStack_14), piVar5 != (int *)0x0)) {
    iVar6 = 0;
    if (0 < (param_1->civilians).maximumSizeValue) {
      do {
        if (iStack_10 <= iVar6) break;
        iVar4 = iVar6 + 1;
        piVar5[iVar6] = (param_1->civilians).value[iVar6];
        iVar6 = iVar4;
      } while (iVar4 < (param_1->civilians).maximumSizeValue);
    }
    operator_delete((param_1->civilians).value);
    (param_1->civilians).value = piVar5;
    (param_1->civilians).maximumSizeValue = iStack_10;
  }
  iVar6 = (param_1->civilianExplorers).numberValue;
  iVar4 = 0;
  if (0 < iVar6) {
    do {
      if ((param_1->civilianExplorers).maximumSizeValue <= iVar4) break;
      if ((param_1->civilianExplorers).value[iVar4] == (param_1->civilians).value[iVar2]) {
        if ((iVar2 <= (param_1->civilians).maximumSizeValue + -1) ||
           (piVar5 = (int *)operator_new(uStack_14), piVar5 == (int *)0x0)) goto LAB_004f1df6;
        iVar6 = 0;
        if ((param_1->civilians).maximumSizeValue < 1) goto LAB_004f1dd5;
        goto LAB_004f1db8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar6);
  }
  if (((param_1->civilians).maximumSizeValue + -1 < iVar2) &&
     (piVar5 = (int *)operator_new(uStack_14), piVar5 != (int *)0x0)) {
    iVar6 = 0;
    if (0 < (param_1->civilians).maximumSizeValue) {
      do {
        if (iStack_10 <= iVar6) break;
        iVar4 = iVar6 + 1;
        piVar5[iVar6] = (param_1->civilians).value[iVar6];
        iVar6 = iVar4;
      } while (iVar4 < (param_1->civilians).maximumSizeValue);
    }
    operator_delete((param_1->civilians).value);
    (param_1->civilians).value = piVar5;
    (param_1->civilians).maximumSizeValue = iStack_10;
  }
  iVar6 = TribeTacticalAIModule::highLevelTaskGatherer
                    (param_1,(param_1->civilians).value[iVar2],param_2);
  if (iVar6 != 0) goto LAB_004f1c2b;
  if (((param_1->civilians).maximumSizeValue + -1 < iVar2) &&
     (piVar5 = (int *)operator_new(uStack_14), piVar5 != (int *)0x0)) {
    iVar6 = 0;
    if (0 < (param_1->civilians).maximumSizeValue) {
      do {
        if (iStack_10 <= iVar6) break;
        iVar4 = iVar6 + 1;
        piVar5[iVar6] = (param_1->civilians).value[iVar6];
        iVar6 = iVar4;
      } while (iVar4 < (param_1->civilians).maximumSizeValue);
    }
    operator_delete((param_1->civilians).value);
    (param_1->civilians).value = piVar5;
    (param_1->civilians).maximumSizeValue = iStack_10;
  }
  TribeTacticalAIModule::addGatherer(param_1,(param_1->civilians).value[iVar2]);
  goto LAB_004f1ce0;
  while( true ) {
    iVar4 = iVar6 + 1;
    piVar5[iVar6] = (param_1->civilians).value[iVar6];
    iVar6 = iVar4;
    if ((param_1->civilians).maximumSizeValue <= iVar4) break;
LAB_004f1db8:
    if (iStack_10 <= iVar6) break;
  }
LAB_004f1dd5:
  operator_delete((param_1->civilians).value);
  (param_1->civilians).value = piVar5;
  (param_1->civilians).maximumSizeValue = iStack_10;
LAB_004f1df6:
  TribeTacticalAIModule::highLevelTaskExplorer(param_1,(param_1->civilians).value[iVar2],1);
LAB_004f1c2b:
  TribeTacticalAIModule::updateGathererDistribution(param_1);
  iVar6 = iVar2 + 1;
  if ((param_1->civilians).numberValue <= iVar6) goto LAB_004f1d72;
  if (((param_1->civilians).maximumSizeValue + -1 < iVar6) &&
     (piVar5 = (int *)operator_new(uStack_14 + 4), piVar5 != (int *)0x0)) {
    iVar4 = 0;
    if (0 < (param_1->civilians).maximumSizeValue) {
      do {
        if (iStack_10 + 1 <= iVar4) break;
        iVar3 = iVar4 + 1;
        piVar5[iVar4] = (param_1->civilians).value[iVar4];
        iVar4 = iVar3;
      } while (iVar3 < (param_1->civilians).maximumSizeValue);
    }
    operator_delete((param_1->civilians).value);
    (param_1->civilians).value = piVar5;
    (param_1->civilians).maximumSizeValue = iStack_10 + 1;
  }
  param_1->nextCivilianToTaskValue = (param_1->civilians).value[iVar6];
  uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xdc6);
  if (param_3 <= uVar8 - param_2) {
    if (iVar6 < 1) {
      return iStack_c;
    }
    if (iVar2 <= (param_1->civilians).maximumSizeValue + -1) {
      return iStack_c;
    }
    iVar2 = iVar2 + 1;
    piVar5 = (int *)operator_new(iVar2 * 4);
    if (piVar5 == (int *)0x0) {
      return iStack_c;
    }
    iVar6 = 0;
    if (0 < (param_1->civilians).maximumSizeValue) goto LAB_004f1d2c;
    goto LAB_004f1d49;
  }
LAB_004f1ce0:
  iStack_10 = iStack_10 + 1;
  uStack_14 = uStack_14 + 4;
  iVar2 = iVar2 + 1;
  if ((param_1->civilians).numberValue <= iVar2) goto LAB_004f1d72;
  goto LAB_004f1a80;
  while( true ) {
    iVar4 = iVar6 + 1;
    piVar5[iVar6] = (param_1->civilians).value[iVar6];
    iVar6 = iVar4;
    if ((param_1->civilians).maximumSizeValue <= iVar4) break;
LAB_004f1d2c:
    if (iVar2 <= iVar6) break;
  }
LAB_004f1d49:
  operator_delete((param_1->civilians).value);
  (param_1->civilians).value = piVar5;
  (param_1->civilians).maximumSizeValue = iVar2;
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004f1e0e
// Address: 004f1e0e
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
void __thiscall FUN_004f1e0e(TribeTacticalAIModule *param_1,int param_2,uint param_3)
{
  bool bVar1;
  uchar uVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  RGE_Static_Object *this;
  RGE_Static_Object *pRVar7;
  ulong uVar8;
  TacticalAIGroup *this_00;
  
  this_00 = (param_1->groups).next;
  if (param_1->nextIdleSoldierGroupToTaskValue != -1) {
    while (((this_00 != &param_1->groups && (this_00 != (TacticalAIGroup *)0x0)) &&
           (iVar4 = TacticalAIGroup::id(this_00), iVar4 != param_1->nextIdleSoldierGroupToTaskValue)
           )) {
      this_00 = this_00->next;
    }
    iVar4 = TacticalAIGroup::id(this_00);
    if (iVar4 != param_1->nextIdleSoldierGroupToTaskValue) {
      this_00 = (param_1->groups).next;
    }
  }
  do {
    while( true ) {
      if ((this_00 == &param_1->groups) || (this_00 == (TacticalAIGroup *)0x0)) {
        param_1->nextIdleSoldierGroupToTaskValue = -1;
        return;
      }
      iVar4 = TacticalAIGroup::type(this_00);
      if (((iVar4 != 0x6b) && (iVar4 = TacticalAIGroup::type(this_00), iVar4 != 0x6c)) &&
         ((iVar4 = TacticalAIGroup::type(this_00), iVar4 != 0x6a &&
          ((iVar4 = TacticalAIGroup::action(this_00), iVar4 == 0 ||
           (iVar4 = TacticalAIGroup::action(this_00), iVar4 == 1)))))) break;
      this_00 = this_00->next;
    }
    iVar4 = 1;
    bVar1 = true;
    if (this_00->consecutiveGatherAttemptsValue < 0xb) {
      iVar4 = TacticalAIGroup::isGathered(this_00,param_1,param_1->md);
    }
    iVar5 = TacticalAIGroup::desiredNumberUnits(this_00);
    iVar6 = TacticalAIGroup::numberUnits(this_00);
    if (iVar6 < iVar5) {
      iVar5 = TacticalAIGroup::commander(this_00);
      this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar5);
      pRVar7 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
      if ((this == (RGE_Static_Object *)0x0) || (pRVar7 == (RGE_Static_Object *)0x0)) {
        bVar1 = false;
      }
      else {
        uVar2 = RGE_Static_Object::currentZone(this);
        iVar5 = __ftol();
        iVar6 = __ftol();
        uVar3 = RGE_Static_Object::lookupZone(this,iVar6,iVar5);
        if (uVar2 == uVar3) {
          bVar1 = false;
        }
        else {
          iVar5 = TacticalAIGroup::numberUnits(this_00);
          TacticalAIGroup::setDesiredNumberUnits(this_00,iVar5);
        }
      }
    }
    else if (iVar4 == 0) {
      bVar1 = false;
    }
    else {
      iVar5 = TacticalAIGroup::allUnitsIdle(this_00,param_1->md,1);
      if (iVar5 == 0) {
        bVar1 = false;
      }
      else {
        iVar5 = TacticalAIGroup::type(this_00);
        if ((iVar5 == 0x66) || (iVar5 = TacticalAIGroup::type(this_00), iVar5 == 0x69)) {
          iVar5 = TacticalAIGroup::commander(this_00);
          iVar5 = TribeInformationAIModule::fullyExploredZone(&param_1->md->informationAI,iVar5);
          if (iVar5 == 0) {
            bVar1 = false;
            goto LAB_004f20e6;
          }
        }
        iVar5 = TacticalAIGroup::type(this_00);
        if ((iVar5 == 100) || (iVar5 = TacticalAIGroup::type(this_00), iVar5 == 0x67)) {
          iVar5 = TribeStrategyAIModule::currentVictoryCondition(&param_1->md->strategyAI);
          if (iVar5 == 0) {
            iVar5 = TribeTacticalAIModule::itemToCapture(param_1);
            if ((iVar5 == -1) && (iVar5 = TacticalAIGroup::type(this_00), iVar5 == 100)) {
              bVar1 = false;
            }
            else {
              TacticalAIGroup::setSubType(this_00,0);
            }
          }
          iVar5 = TribeStrategyAIModule::currentVictoryCondition(&param_1->md->strategyAI);
          if (iVar5 == 4) {
            iVar5 = TribeTacticalAIModule::itemToBringToArea(param_1);
            if ((iVar5 == -1) && (iVar5 = TacticalAIGroup::type(this_00), iVar5 == 100)) {
              bVar1 = false;
            }
            else {
              TacticalAIGroup::setSubType(this_00,4);
            }
          }
        }
        else {
          iVar5 = TacticalAIGroup::type(this_00);
          if (((iVar5 == 0x65) || (iVar5 = TacticalAIGroup::type(this_00), iVar5 == 0x68)) &&
             (iVar5 = TribeTacticalAIModule::numberItemsToDefend(param_1), iVar5 == 0)) {
            bVar1 = false;
          }
        }
      }
    }
LAB_004f20e6:
    if (bVar1) {
      iVar4 = TacticalAIGroup::type(this_00);
      if ((iVar4 == 0x66) || (iVar4 = TacticalAIGroup::type(this_00), iVar4 == 0x69)) {
LAB_004f218b:
        iVar4 = 8;
      }
      else {
        iVar4 = TacticalAIGroup::type(this_00);
        if ((iVar4 == 100) || (iVar4 = TacticalAIGroup::type(this_00), iVar4 == 0x67)) {
          iVar4 = TribeTacticalAIModule::numberItemsToAttack(param_1);
          if ((iVar4 == 0) && (iVar4 = TacticalAIGroup::type(this_00), iVar4 == 0x67)) {
            TacticalAIGroup::setType(this_00,0x69);
            goto LAB_004f218b;
          }
          iVar4 = 2;
        }
        else {
          iVar4 = TacticalAIGroup::type(this_00);
          if ((iVar4 == 0x65) || (iVar4 = TacticalAIGroup::type(this_00), iVar4 == 0x68)) {
            iVar4 = 4;
          }
          else {
            iVar4 = TacticalAIGroup::type(this_00);
            if (iVar4 != 0x6d) goto LAB_004f2194;
            iVar4 = 0x13;
          }
        }
      }
      TacticalAIGroup::setAction(this_00,iVar4);
    }
    else if (iVar4 == 0) {
      TacticalAIGroup::task(this_00,param_1,param_1->md,9,1,0);
    }
LAB_004f2194:
    this_00 = this_00->next;
    iVar4 = TacticalAIGroup::id(this_00);
    param_1->nextIdleSoldierGroupToTaskValue = iVar4;
    uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0xea9);
    if (param_3 <= uVar8 - param_2) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004f21ed
// Address: 004f21ed
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
// [HELPER] s_____Unit__d_has_invalid_unitAI_: "    Unit %d has invalid unitAI."
// [HELPER] s_____Unit__d_is_invalid_: "    Unit %d is invalid."
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f21ed(TribeTacticalAIModule *param_1,ulong param_2,uint param_3)
{
  byte bVar1;
  byte bVar2;
  code *pcVar3;
  XYPoint XVar4;
  XYPoint XVar5;
  uchar uVar6;
  int iVar7;
  ulong uVar8;
  RGE_Static_Object *pRVar9;
  int *piVar10;
  Path *pPVar11;
  TacticalAIGroup *pTVar12;
  UnitAIModule *pUVar13;
  RGE_Action *pRVar14;
  Waypoint *pWVar15;
  int iVar16;
  int iVar17;
  AIModule *this;
  AIModule *this_00;
  RGE_Static_Object *pRVar18;
  ObjectMemory *pOVar19;
  uint uVar20;
  TacticalAIGroup *this_01;
  float10 fVar21;
  float fVar22;
  float fVar23;
  Waypoint *pWVar24;
  TribeMainDecisionAIModule *pTVar25;
  float fVar26;
  int iVar27;
  int iVar28;
  RGE_Static_Object **ppRVar29;
  int iVar30;
  int iStack_d0;
  RGE_Static_Object *pRStack_cc;
  int iStack_c8;
  TacticalAIGroup *pTStack_c4;
  XYPoint XStack_c0;
  uint uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_84 [4];
  RGE_Static_Object *pRStack_80;
  undefined1 auStack_7c [4];
  undefined1 auStack_78 [4];
  undefined1 auStack_74 [4];
  XYPoint XStack_70;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  RGE_Static_Object *pRStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [8];
  int iStack_20;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  this_01 = (param_1->groups).next;
  if (param_1->nextActiveSoldierGroupToTaskValue != -1) {
    while (((this_01 != &param_1->groups && (this_01 != (TacticalAIGroup *)0x0)) &&
           (iVar7 = TacticalAIGroup::id(this_01),
           iVar7 != param_1->nextActiveSoldierGroupToTaskValue))) {
      this_01 = this_01->next;
    }
    iVar7 = TacticalAIGroup::id(this_01);
    if (iVar7 != param_1->nextActiveSoldierGroupToTaskValue) {
      this_01 = (param_1->groups).next;
    }
  }
  if (this_01 != &param_1->groups) {
    do {
      if (this_01 == (TacticalAIGroup *)0x0) break;
      iVar7 = TacticalAIGroup::type(this_01);
      if (((iVar7 == 0x6b) || (iVar7 = TacticalAIGroup::type(this_01), iVar7 == 0x6c)) ||
         ((iVar7 = TacticalAIGroup::type(this_01), iVar7 == 0x6a ||
          ((iVar7 = TacticalAIGroup::action(this_01), iVar7 == 0 ||
           (iVar7 = TacticalAIGroup::action(this_01), iVar7 == 1)))))) {
        this_01 = this_01->next;
      }
      else {
        iVar7 = TacticalAIGroup::allUnitsIdle(this_01,param_1->md,1);
        if (iVar7 == 0) {
          TacticalAIGroup::setConsecutiveIdleUnitCount
                    (this_01,*(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4));
        }
        iVar7 = TacticalAIGroup::inUse(this_01);
        if (iVar7 == 0) {
          pOVar19 = (ObjectMemory *)0x0;
          pRVar18 = (RGE_Static_Object *)0x0;
          pRStack_cc = (RGE_Static_Object *)0x1;
          iVar7 = TacticalAIGroup::type(this_01);
          if ((iVar7 != 100) && (iVar7 = TacticalAIGroup::type(this_01), iVar7 != 0x67)) {
            iVar7 = TacticalAIGroup::type(this_01);
            if ((iVar7 == 0x65) || (iVar7 = TacticalAIGroup::type(this_01), iVar7 == 0x68)) {
              iVar7 = TacticalAIGroup::commander(this_01);
              pOVar19 = TribeInformationAIModule::objectToDefend(&param_1->md->informationAI,iVar7);
              if (pOVar19 == (ObjectMemory *)0x0) {
                TacticalAIGroup::setAction(this_01,1);
              }
              else {
                iVar7 = TacticalAIGroup::commander(this_01);
                pRVar18 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar7);
                if (pRVar18 != (RGE_Static_Object *)0x0) {
                  if (pOVar19->type == 0x6d) {
                    iVar7 = param_1->sn[0x16];
                  }
                  else {
                    iVar7 = param_1->sn[0x39];
                  }
                  uStack_b8 = (uint)pOVar19->x;
                  uStack_b4 = (uint)pOVar19->y;
                  uStack_b0 = (uint)pOVar19->z;
                  iStack_c8 = pRVar18->_padding_;
                  fVar21 = (float10)(**(code **)(iStack_c8 + 0x10c))
                                              (pOVar19->id,auStack_74,1,0xffffffff,0xffffffff);
                  iVar27 = (**(code **)(iStack_c8 + 0x198))
                                     (uStack_b8,uStack_b4,uStack_b0,(float)fVar21);
                  if (iVar27 != 0) {
                    pOVar19->attackAttempts = 1;
                    TacticalAIGroup::setTarget(this_01,pOVar19->id);
                    TacticalAIGroup::setTargetType(this_01,(int)pOVar19->type);
                    TacticalAIGroup::setTargetLocation
                              (this_01,(float)pOVar19->x,(float)pOVar19->y,(float)pOVar19->z);
                    fVar23 = (float)pOVar19->z;
                    fVar22 = (float)pOVar19->y;
                    fVar26 = (float)pOVar19->x;
LAB_004f27f4:
                    TacticalAIGroup::setGatherLocation(this_01,fVar26,fVar22,fVar23);
                    TacticalAIGroup::setInUse(this_01,1);
                    goto LAB_004f2d49;
                  }
                  iVar7 = (**(code **)(iStack_c8 + 0x1a4))
                                    (uStack_b8,uStack_b4,uStack_b0,(float)iVar7,pOVar19->id,
                                     auStack_74,1,0x16,1,0xffffffff,0xffffffff);
                  if ((iVar7 != 0) &&
                     (iVar7 = (**(code **)(iStack_c8 + 0x1a8))(2,auStack_10,auStack_4), iVar7 == 1))
{
                    pOVar19->attackAttempts = 1;
                    TacticalAIGroup::task(this_01,param_1,param_1->md,0xe,1,0);
                    TacticalAIGroup::setAction(this_01,0xd);
                    TacticalAIGroup::setTarget(this_01,pOVar19->id);
                    TacticalAIGroup::setTargetType(this_01,(int)pOVar19->type);
                    TacticalAIGroup::setTargetLocation
                              (this_01,(float)pOVar19->x,(float)pOVar19->y,(float)pOVar19->z);
                    TacticalAIGroup::setInUse(this_01,1);
                    TacticalAIGroup::setWaitCode(this_01,200);
                    goto LAB_004f4548;
                  }
                  goto LAB_004f2afb;
                }
                TacticalAIGroup::setAction(this_01,1);
              }
            }
            else {
              iVar7 = TacticalAIGroup::type(this_01);
              if (iVar7 == 0x6d) {
                pTVar25 = param_1->md;
                uVar8 = TacticalAIGroup::consecutiveIdleUnitCount(this_01);
                if ((((RGE_Player *)pTVar25->_padding_)->world->world_time - uVar8) / 1000 < 0x3c) {
                  TacticalAIGroup::setAction(this_01,1);
                }
                else {
                  pRVar9 = MainDecisionAIModule::object
                                     ((MainDecisionAIModule *)pTVar25,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,
                                      -1);
                  if (pRVar9 == (RGE_Static_Object *)0x0) {
                    TacticalAIGroup::setAction(this_01,1);
                  }
                  else {
                    iVar7 = TacticalAIGroup::commander(this_01);
                    pRVar18 = MainDecisionAIModule::object
                                        ((MainDecisionAIModule *)param_1->md,iVar7);
                    if (pRVar18 == (RGE_Static_Object *)0x0) {
                      TacticalAIGroup::setAction(this_01,1);
                    }
                    else {
                      uStack_90 = __ftol();
                      uStack_8c = __ftol();
                      uStack_88 = __ftol();
                      iStack_c8 = pRVar18->_padding_;
                      iVar7 = (**(code **)(iStack_c8 + 0x198))
                                        (uStack_90,uStack_8c,uStack_88,(float)param_1->sn[0x17],
                                         pRVar9->id,auStack_7c,1,0xffffffff,0xffffffff);
                      if (iVar7 != 0) {
                        TacticalAIGroup::setTarget(this_01,pRVar9->id);
                        TacticalAIGroup::setTargetType(this_01,(uint)pRVar9->type);
                        TacticalAIGroup::setTargetLocation
                                  (this_01,pRVar9->world_x,pRVar9->world_y,pRVar9->world_z);
                        fVar23 = pRVar9->world_z;
                        fVar22 = pRVar9->world_y;
                        fVar26 = pRVar9->world_x;
                        goto LAB_004f27f4;
                      }
                      iVar7 = (**(code **)(iStack_c8 + 0x1a4))
                                        (uStack_90,uStack_8c,uStack_88,(float)param_1->sn[0x17],
                                         pRVar9->id,auStack_7c,1,0x16,1,0xffffffff,0xffffffff);
                      if (iVar7 == 0) {
                        TacticalAIGroup::setConsecutiveIdleUnitCount
                                  (this_01,*(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4));
                        TacticalAIGroup::setAction(this_01,1);
                      }
                      else {
                        iVar7 = (**(code **)(iStack_c8 + 0x1a8))(2,auStack_c,auStack_18);
                        if (iVar7 != 1) goto LAB_004f2afb;
                        TacticalAIGroup::task(this_01,param_1,param_1->md,0xe,1,0);
                        TacticalAIGroup::setAction(this_01,0xd);
                        TacticalAIGroup::setTarget(this_01,pRVar9->id);
                        TacticalAIGroup::setTargetType(this_01,(uint)pRVar9->type);
                        TacticalAIGroup::setTargetLocation
                                  (this_01,pRVar9->world_x,pRVar9->world_y,pRVar9->world_z);
                        TacticalAIGroup::setInUse(this_01,1);
                        TacticalAIGroup::setWaitCode(this_01,200);
                      }
                    }
                  }
                }
              }
              else {
LAB_004f2d49:
                iVar7 = TribeStrategyAIModule::currentVictoryCondition(&param_1->md->strategyAI);
                if ((iVar7 == 0xb) &&
                   ((((iVar7 = TacticalAIGroup::type(this_01), iVar7 == 100 ||
                      (iVar7 = TacticalAIGroup::type(this_01), iVar7 == 0x67)) &&
                     (param_1->sn[0x67] == 1)) &&
                    ((pOVar19 != (ObjectMemory *)0x0 && (pRVar18 != (RGE_Static_Object *)0x0)))))) {
                  TribeInformationAIModule::addEnemyInfluences
                            (&param_1->md->informationAI,(uint)pOVar19->owner,pOVar19->id);
                  TribeInformationAIModule::addPriorAttackInfluences
                            (&param_1->md->informationAI,(uint)pOVar19->owner,pOVar19->id);
                  uStack_34 = (uint)pOVar19->y;
                  uStack_38 = (uint)pOVar19->x;
                  iStack_c8 = pRVar18->_padding_;
                  uStack_30 = 1;
                  fVar21 = (float10)(**(code **)(iStack_c8 + 0x10c))(pOVar19->id);
                  pPVar11 = (Path *)(**(code **)(iStack_c8 + 0x1cc))(&uStack_38,(float)fVar21);
                  if (pPVar11 != (Path *)0x0) {
                    TribeTacticalAIModule::stuffAvoidancePath(param_1,this_01,pPVar11);
                  }
                }
                if ((pRStack_cc != (RGE_Static_Object *)0x0) ||
                   (iVar7 = TacticalAIGroup::action(this_01), iVar7 != 2)) {
LAB_004f452d:
                  iVar7 = 0;
                  iVar28 = 1;
                  iVar27 = TacticalAIGroup::action(this_01);
                  goto LAB_004f4539;
                }
                pTVar25 = param_1->md;
                iVar7 = 0;
                iVar28 = 1;
                iVar27 = 0x15;
LAB_004f4540:
                TacticalAIGroup::task(this_01,param_1,pTVar25,iVar27,iVar28,iVar7);
              }
            }
            goto LAB_004f4548;
          }
          if (param_1->attackEnabledValue == 0) {
            (param_1->attackStateValue).active = 0;
          }
          else {
            if ((param_1->sn[0xa2] != 0) && (iVar7 = TacticalAIGroup::type(this_01), iVar7 != 0x67))
{
              pOVar19 = TribeInformationAIModule::objectMemory
                                  (&param_1->md->informationAI,iRam00000000);
LAB_004f2ae2:
              iVar7 = TacticalAIGroup::commander(this_01);
              pRVar18 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar7);
              if (pRVar18 == (RGE_Static_Object *)0x0) {
LAB_004f2afb:
                TacticalAIGroup::setAction(this_01,1);
              }
              else {
                uStack_a4 = (uint)pOVar19->y;
                uStack_a8 = (uint)pOVar19->x;
                iStack_c8 = pRVar18->_padding_;
                pcVar3 = *(code **)(iStack_c8 + 0x10c);
                uStack_a0 = (uint)pOVar19->z;
                fVar21 = (float10)(*pcVar3)(pOVar19->id,auStack_78,1,pOVar19->owner,0x1b);
                iVar7 = (**(code **)(iStack_c8 + 0x198))
                                  (uStack_a8,uStack_a4,uStack_a0,(float)fVar21);
                if (iVar7 != 0) {
                  param_1->lastGroupAttackTime =
                       *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
                  if (param_1->sn[0x47] == 1) {
                    param_1->lastAttackResponseTime =
                         *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
                  }
                  TacticalAIGroup::setTarget(this_01,pOVar19->id);
                  TacticalAIGroup::setTargetType(this_01,(int)pOVar19->type);
                  TacticalAIGroup::setTargetLocation
                            (this_01,(float)pOVar19->x,(float)pOVar19->y,(float)pOVar19->z);
                  TacticalAIGroup::setInUse(this_01,1);
                  TribeTacticalAIModule::checkForCoopAttack
                            (param_1,(uint)pOVar19->owner,(uint)pOVar19->x,(uint)pOVar19->y);
                  goto LAB_004f2d49;
                }
                iVar7 = TacticalAIGroup::type(this_01);
                if (iVar7 != 0x67) {
                  fVar21 = (float10)(*pcVar3)(pOVar19->id,auStack_78,1,0x16,1,pOVar19->owner,0x1b);
                  iVar7 = (**(code **)(iStack_c8 + 0x1a4))
                                    (uStack_a8,uStack_a4,uStack_a0,(float)fVar21);
                  if (iVar7 == 0) {
                    this_01->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setAction(this_01,1);
                    this_01->playNumberValue = -1;
                    (param_1->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
                  iVar7 = (**(code **)(iStack_c8 + 0x1a8))(2,auStack_8,auStack_2c);
                  if (iVar7 == 1) {
                    TacticalAIGroup::task(this_01,param_1,param_1->md,0xe,1,0);
                    TacticalAIGroup::setAction(this_01,0xd);
                    TacticalAIGroup::setTarget(this_01,pOVar19->id);
                    TacticalAIGroup::setTargetType(this_01,(int)pOVar19->type);
                    bVar1 = pOVar19->z;
                    bVar2 = pOVar19->y;
                    pTVar12 = (TacticalAIGroup *)(uint)pOVar19->x;
                    goto LAB_004f3cf9;
                  }
                }
                TacticalAIGroup::setAction(this_01,1);
                this_01->playNumberValue = -1;
              }
              goto LAB_004f4548;
            }
            uVar20 = (*(int *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4) -
                     param_1->lastGroupAttackTime) / 1000;
            if ((((param_1->lastGroupAttackTime == 0) || (param_1->sn[0x2f] != 2)) || (uVar20 == 0))
               || (uVar8 = TribeTacticalAIModule::attackLimiterTime(param_1,0x2e), uVar8 <= uVar20))
{
              if (((param_1->lastGroupAttackTime == 0) || (param_1->sn[0x2f] != 1)) ||
                 (uVar8 = TribeTacticalAIModule::attackLimiterTime(param_1,0x2e), uVar8 <= uVar20))
{
                iVar7 = TribeStrategyAIModule::currentVictoryCondition(&param_1->md->strategyAI);
                if (iVar7 == 0) {
                  iVar7 = TribeTacticalAIModule::itemToCapture(param_1);
                  pOVar19 = TribeInformationAIModule::objectMemory
                                      (&param_1->md->informationAI,iVar7);
                  if (pOVar19 == (ObjectMemory *)0x0) {
                    if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar10 = (int *)operator_new(4), piVar10 != (int *)0x0)) {
                      iVar7 = 0;
                      if (0 < (param_1->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar7) break;
                          iVar27 = iVar7 + 1;
                          piVar10[iVar7] = (param_1->playersToAttack).value[iVar7];
                          iVar7 = iVar27;
                        } while (iVar27 < (param_1->playersToAttack).maximumSizeValue);
                      }
LAB_004f29d8:
                      operator_delete((param_1->playersToAttack).value);
                      (param_1->playersToAttack).value = piVar10;
                      (param_1->playersToAttack).maximumSizeValue = 1;
                    }
LAB_004f29f7:
                    piVar10 = (param_1->playersToAttack).value;
                    ppRVar29 = &pRStack_cc;
                    iVar7 = TacticalAIGroup::commander(this_01);
                    pOVar19 = TribeInformationAIModule::objectToAttack
                                        (&param_1->md->informationAI,*piVar10,1,1,iVar7,
                                         (int *)ppRVar29);
LAB_004f2ac7:
                    if (pOVar19 == (ObjectMemory *)0x0) {
                      TacticalAIGroup::setAction(this_01,1);
                      (param_1->attackStateValue).active = 0;
                      goto LAB_004f4552;
                    }
                  }
                }
                else {
                  iVar7 = TribeStrategyAIModule::currentVictoryCondition(&param_1->md->strategyAI);
                  if (iVar7 != 4) {
                    if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar10 = (int *)operator_new(4), piVar10 != (int *)0x0)) {
                      iVar7 = 0;
                      if (0 < (param_1->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar7) break;
                          iVar27 = iVar7 + 1;
                          piVar10[iVar7] = (param_1->playersToAttack).value[iVar7];
                          iVar7 = iVar27;
                        } while (iVar27 < (param_1->playersToAttack).maximumSizeValue);
                      }
                      operator_delete((param_1->playersToAttack).value);
                      (param_1->playersToAttack).value = piVar10;
                      (param_1->playersToAttack).maximumSizeValue = 1;
                    }
                    pOVar19 = TribeInformationAIModule::objectToAttackByGroup
                                        (&param_1->md->informationAI,
                                         *(param_1->playersToAttack).value,this_01,
                                         &param_1->attackStateValue,param_2);
                    if ((param_1->attackStateValue).active == 1) goto LAB_004f45bf;
                    goto LAB_004f2ac7;
                  }
                  iVar7 = TribeTacticalAIModule::itemToBringToArea(param_1);
                  pOVar19 = TribeInformationAIModule::objectMemory
                                      (&param_1->md->informationAI,iVar7);
                  if (pOVar19 == (ObjectMemory *)0x0) {
                    if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
                       (piVar10 = (int *)operator_new(4), piVar10 != (int *)0x0)) {
                      iVar7 = 0;
                      if (0 < (param_1->playersToAttack).maximumSizeValue) {
                        do {
                          if (0 < iVar7) break;
                          iVar27 = iVar7 + 1;
                          piVar10[iVar7] = (param_1->playersToAttack).value[iVar7];
                          iVar7 = iVar27;
                        } while (iVar27 < (param_1->playersToAttack).maximumSizeValue);
                      }
                      goto LAB_004f29d8;
                    }
                    goto LAB_004f29f7;
                  }
                }
                pOVar19->attackAttempts = pOVar19->attackAttempts + 1;
                goto LAB_004f2ae2;
              }
              (param_1->attackStateValue).active = 0;
            }
            else {
              (param_1->attackStateValue).active = 0;
            }
          }
        }
        else {
          iVar7 = TacticalAIGroup::action(this_01);
          if (iVar7 == 0xd) {
            iVar7 = TacticalAIGroup::waitCode(this_01);
            if (iVar7 == 200) {
              iVar7 = TacticalAIGroup::assistGroupID(this_01);
              if (iVar7 == -1) {
                iVar7 = TacticalAIGroup::commander(this_01);
                pRVar18 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar7);
                if (pRVar18 == (RGE_Static_Object *)0x0) {
                  (param_1->attackStateValue).active = 0;
                  goto LAB_004f4552;
                }
                XStack_70.x = __ftol();
                XStack_70.y = __ftol();
                pTVar12 = TribeTacticalAIModule::bestGroup(param_1,0x6a,1,-1,&XStack_70,-1);
                if ((pTVar12 != (TacticalAIGroup *)0x0) ||
                   (pTVar12 = TribeTacticalAIModule::bestGroup(param_1,0x6a,0,-1,&XStack_70,-1),
                   pTVar12 != (TacticalAIGroup *)0x0)) {
                  iVar7 = TacticalAIGroup::id(pTVar12);
                  TacticalAIGroup::setAssistGroupID(this_01,iVar7);
                  iVar7 = TacticalAIGroup::type(pTVar12);
                  TacticalAIGroup::setAssistGroupType(this_01,iVar7);
                  TacticalAIGroup::setAction(pTVar12,0xc);
                  TacticalAIGroup::setInUse(pTVar12,1);
                  iVar7 = TacticalAIGroup::id(this_01);
                  TacticalAIGroup::setAssistGroupID(pTVar12,iVar7);
                  goto LAB_004f2f57;
                }
              }
              else {
                iVar30 = -1;
                iVar28 = -1;
                iVar27 = -1;
                iVar7 = TacticalAIGroup::assistGroupID(this_01);
                pTVar12 = TribeTacticalAIModule::group(param_1,iVar7,iVar27,iVar28,iVar30);
LAB_004f2f57:
                if (pTVar12 != (TacticalAIGroup *)0x0) {
                  iVar7 = TacticalAIGroup::commander(pTVar12);
                  pRVar18 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar7);
                  if ((pRVar18 == (RGE_Static_Object *)0x0) ||
                     (pRVar18->objects->number_of_objects <
                      (short)(ushort)pRVar18->master_obj->obj_max)) {
                    iStack_c8 = 0;
                    pRStack_cc = (RGE_Static_Object *)0x0;
                    iVar7 = TacticalAIGroup::numberUnits(this_01);
                    if (0 < iVar7) {
                      do {
                        iVar7 = TacticalAIGroup::unit(this_01,(int)pRStack_cc);
                        pRVar18 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)param_1->md,iVar7);
                        if ((pRVar18 != (RGE_Static_Object *)0x0) &&
                           (pUVar13 = RGE_Static_Object::unitAI(pRVar18),
                           pUVar13 != (UnitAIModule *)0x0)) {
                          pUVar13 = RGE_Static_Object::unitAI(pRVar18);
                          iVar27 = UnitAIModule::currentAction(pUVar13);
                          if (iVar27 == -1) {
                            iStack_c8 = 1;
                            iVar27 = TacticalAIGroup::commander(pTVar12);
                            TribeTacticalAIModule::taskToEnter(param_1,iVar7,iVar27);
                          }
                        }
                        pRVar18 = (RGE_Static_Object *)((int)&pRStack_cc->_padding_ + 1);
                        pRStack_cc = pRVar18;
                        iVar7 = TacticalAIGroup::numberUnits(this_01);
                      } while ((int)pRVar18 < iVar7);
                    }
                    if (iStack_c8 != 0) goto LAB_004f43ca;
                    TacticalAIGroup::setAction(this_01,0xf);
                    (param_1->attackStateValue).active = 0;
                  }
                  else {
                    TacticalAIGroup::setAction(this_01,0xf);
                    (param_1->attackStateValue).active = 0;
                  }
                  goto LAB_004f4552;
                }
              }
              TacticalAIGroup::setAssistGroupID(this_01,-1);
              TacticalAIGroup::setAssistGroupType(this_01,-1);
              (param_1->attackStateValue).active = 0;
              goto LAB_004f4552;
            }
LAB_004f43ca:
            (param_1->attackStateValue).active = 0;
          }
          else {
            iVar7 = TacticalAIGroup::action(this_01);
            if (iVar7 == 0xf) {
              iVar30 = -1;
              iVar28 = -1;
              iVar27 = -1;
              iVar7 = TacticalAIGroup::assistGroupID(this_01);
              pTVar12 = TribeTacticalAIModule::group(param_1,iVar7,iVar27,iVar28,iVar30);
              if (pTVar12 != (TacticalAIGroup *)0x0) {
                iVar7 = TacticalAIGroup::commander(pTVar12);
                pRVar18 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar7);
                if (pRVar18 != (RGE_Static_Object *)0x0) {
                  if ((short)(ushort)pRVar18->master_obj->obj_max <=
                      pRVar18->objects->number_of_objects) {
                    TacticalAIGroup::removeUnboardedUnits(this_01,param_1,param_1->md);
                  }
                  uStack_ac = CONCAT31(uStack_ac._1_3_,0xff);
                  iStack_c8 = 1;
                  iStack_d0 = 0;
                  iVar7 = TacticalAIGroup::numberUnits(this_01);
                  if (0 < iVar7) {
                    do {
                      iVar7 = TacticalAIGroup::unit(this_01,iStack_d0);
                      pRStack_cc = MainDecisionAIModule::object
                                             ((MainDecisionAIModule *)param_1->md,iVar7);
                      if (pRStack_cc == (RGE_Static_Object *)0x0) {
                        AIModule::logCommonHistory(this,(char *)param_1,s_____Unit__d_is_invalid_);
                      }
                      else {
                        pUVar13 = RGE_Static_Object::unitAI(pRStack_cc);
                        if (pUVar13 == (UnitAIModule *)0x0) {
                          AIModule::logCommonHistory
                                    (this_00,(char *)param_1,s_____Unit__d_has_invalid_unitAI_);
                        }
                        else {
                          iVar7 = TacticalAIGroup::unit(this_01,iStack_d0);
                          iVar27 = TacticalAIGroup::commander(this_01);
                          pRVar18 = pRStack_cc;
                          if (iVar7 == iVar27) {
                            TacticalAIGroup::targetLocation(this_01);
                            iVar7 = __ftol();
                            TacticalAIGroup::targetLocation(this_01);
                            iVar27 = __ftol();
                            pRVar18 = pRStack_cc;
                            XVar5.y = iVar27;
                            XVar5.x = iVar7;
                            uVar6 = RGE_Static_Object::lookupZone(pRStack_cc,XVar5);
                            uStack_ac = CONCAT31(uStack_ac._1_3_,uVar6);
                          }
                          pRStack_cc = pRVar18->inside_obj;
                          if ((pRStack_cc != (RGE_Static_Object *)0x0) &&
                             (iVar7 = TacticalAIGroup::commander(pTVar12), pRStack_cc->id == iVar7))
{
                            pUVar13 = RGE_Static_Object::unitAI(pRVar18);
                            iVar7 = UnitAIModule::currentAction(pUVar13);
                            if (iVar7 != -1) {
                              TribeTacticalAIModule::stopUnit(param_1,pRVar18->id,100);
                              goto LAB_004f323d;
                            }
                          }
                          pRStack_cc = pRVar18->inside_obj;
                          if ((pRStack_cc == (RGE_Static_Object *)0x0) ||
                             (iVar7 = TacticalAIGroup::commander(pTVar12), pRStack_cc->id == iVar7))
{
                            if (pRVar18->inside_obj == (RGE_Static_Object *)0x0) {
                              iStack_c8 = 0;
                              pUVar13 = RGE_Static_Object::unitAI(pRVar18);
                              iVar7 = UnitAIModule::currentOrder(pUVar13);
                              if (iVar7 != 700) {
                                pUVar13 = RGE_Static_Object::unitAI(pRVar18);
                                iVar7 = UnitAIModule::currentOrder(pUVar13);
                                if (iVar7 != 0x2cd) {
                                  iVar7 = TacticalAIGroup::commander(pTVar12);
                                  iVar27 = TacticalAIGroup::unit(this_01,iStack_d0);
                                  TribeTacticalAIModule::taskToEnter(param_1,iVar27,iVar7);
                                }
                              }
                            }
                          }
                          else {
                            TacticalAIGroup::removeUnit(this_01,pRVar18->id,param_1->md);
                          }
                        }
                      }
LAB_004f323d:
                      iStack_d0 = iStack_d0 + 1;
                      iVar7 = TacticalAIGroup::numberUnits(this_01);
                    } while (iStack_d0 < iVar7);
                  }
                  if (iStack_c8 != 0) {
                    TacticalAIGroup::targetLocation(this_01);
                    iVar7 = __ftol();
                    TacticalAIGroup::targetLocation(this_01);
                    iStack_20 = __ftol();
                    iVar27 = TacticalAIGroup::commander(this_01);
                    iVar30 = 0xf;
                    iVar28 = TacticalAIGroup::target(this_01);
                    XVar4.y = iStack_20;
                    XVar4.x = iVar7;
                    iVar7 = TribeInformationAIModule::findStagingPoint
                                      (&param_1->md->informationAI,XVar4,&XStack_c0,1,1,iVar28,
                                       iVar30,iVar27);
                    if (iVar7 == 0) {
                      TacticalAIGroup::targetLocation(this_01);
                      XStack_c0.x = __ftol();
                      TacticalAIGroup::targetLocation(this_01);
                      XStack_c0.y = __ftol();
                    }
                    fVar23 = (float)XStack_c0.y - _DAT_00575768;
                    fVar22 = (float)XStack_c0.x - _DAT_00575768;
                    iVar7 = TacticalAIGroup::commander(pTVar12);
                    TribeTacticalAIModule::taskTransporter(param_1,iVar7,fVar22,fVar23);
                    TacticalAIGroup::setTargetLocation
                              (pTVar12,(float)XStack_c0.x,(float)XStack_c0.y,-1.0);
                    TacticalAIGroup::setAction(pTVar12,0xc);
                    TacticalAIGroup::setTargetType(pTVar12,uStack_ac & 0xff);
                    TacticalAIGroup::setAction(this_01,0x10);
                    TacticalAIGroup::task(this_01,param_1,param_1->md,0x16,0,1);
                    iVar7 = TacticalAIGroup::numberUnits(pTVar12);
                    if (1 < iVar7) {
                      pRVar18 = (RGE_Static_Object *)0x0;
                      pRStack_cc = (RGE_Static_Object *)0x0;
                      iVar7 = TacticalAIGroup::numberUnits(pTVar12);
                      if (0 < iVar7) {
                        do {
                          iVar7 = TacticalAIGroup::unit(pTVar12,(int)pRVar18);
                          iVar27 = TacticalAIGroup::commander(pTVar12);
                          pRVar18 = pRStack_cc;
                          if (iVar7 != iVar27) {
                            iVar7 = TacticalAIGroup::unit(pTVar12,(int)pRStack_cc);
                            pRVar9 = MainDecisionAIModule::object
                                               ((MainDecisionAIModule *)param_1->md,iVar7);
                            if (pRVar9 != (RGE_Static_Object *)0x0) {
                              iVar28 = 99;
                              fVar23 = pRVar9->master_obj->los * _DAT_005756fc;
                              iVar7 = TacticalAIGroup::commander(pTVar12);
                              iVar27 = TacticalAIGroup::unit(pTVar12,(int)pRVar18);
                              TribeTacticalAIModule::taskDefender
                                        (param_1,iVar27,iVar7,fVar23,iVar28);
                            }
                          }
                          pRVar18 = (RGE_Static_Object *)((int)&pRVar18->_padding_ + 1);
                          pRStack_cc = pRVar18;
                          iVar7 = TacticalAIGroup::numberUnits(pTVar12);
                        } while ((int)pRVar18 < iVar7);
                      }
                    }
                  }
                  goto LAB_004f4548;
                }
              }
              goto LAB_004f37f1;
            }
            iVar7 = TacticalAIGroup::action(this_01);
            if (iVar7 == 0x10) {
              iVar30 = -1;
              iVar28 = -1;
              iVar27 = -1;
              iVar7 = TacticalAIGroup::assistGroupID(this_01);
              pTStack_c4 = TribeTacticalAIModule::group(param_1,iVar7,iVar27,iVar28,iVar30);
              if (pTStack_c4 != (TacticalAIGroup *)0x0) {
                iVar7 = TacticalAIGroup::commander(pTStack_c4);
                pRVar18 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar7);
                pRStack_80 = pRVar18;
                if (((pRVar18 != (RGE_Static_Object *)0x0) &&
                    (pUVar13 = RGE_Static_Object::unitAI(pRVar18), pUVar13 != (UnitAIModule *)0x0))
                   && (pRVar18->owner->id == *(short *)(param_1->md->_padding_ + 0x4a))) {
                  iStack_c8 = 1;
                  pRStack_cc = (RGE_Static_Object *)0x1;
                  iStack_d0 = 0;
                  iVar7 = TacticalAIGroup::numberUnits(this_01);
                  if (0 < iVar7) {
                    do {
                      iVar7 = TacticalAIGroup::unit(this_01,iStack_d0);
                      pRVar18 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)param_1->md,iVar7);
                      if ((pRVar18 != (RGE_Static_Object *)0x0) &&
                         (pUVar13 = RGE_Static_Object::unitAI(pRVar18),
                         pUVar13 != (UnitAIModule *)0x0)) {
                        if (pRVar18->inside_obj == (RGE_Static_Object *)0x0) {
                          pRStack_cc = (RGE_Static_Object *)0x0;
                          iVar7 = TacticalAIGroup::target(this_01);
                          pRStack_5c = MainDecisionAIModule::object
                                                 ((MainDecisionAIModule *)param_1->md,iVar7);
                          iVar7 = TacticalAIGroup::type(this_01);
                          if ((iVar7 == 100) && (pRStack_5c != (RGE_Static_Object *)0x0)) {
                            pUVar13 = RGE_Static_Object::unitAI(pRVar18);
                            if (pUVar13 != (UnitAIModule *)0x0) {
                              pUVar13 = RGE_Static_Object::unitAI(pRVar18);
                              iVar7 = UnitAIModule::currentTarget(pUVar13);
                              iVar27 = TacticalAIGroup::target(this_01);
                              if (iVar7 != iVar27) {
                                iVar7 = pRVar18->_padding_;
                                fVar21 = (float10)(**(code **)(iVar7 + 0x10c))
                                                            (0,1,0xffffffff,0xffffffff);
                                fVar23 = (float)fVar21;
                                iVar27 = TacticalAIGroup::target(this_01);
                                iVar7 = (**(code **)(iVar7 + 0x194))(iVar27,fVar23);
                                if (iVar7 == 1) {
                                  iVar17 = 0;
                                  iVar16 = -1;
                                  iVar30 = 0;
                                  pWVar24 = (Waypoint *)0x0;
                                  iVar28 = -1;
                                  iVar7 = TacticalAIGroup::target(this_01);
                                  pWVar15 = TacticalAIGroup::targetLocation(this_01);
                                  fVar23 = pWVar15->y;
                                  pWVar15 = TacticalAIGroup::targetLocation(this_01);
                                  fVar22 = pWVar15->x;
                                  iVar27 = TacticalAIGroup::unit(this_01,iStack_d0);
                                  TribeTacticalAIModule::taskAttacker
                                            (param_1,iVar27,fVar22,fVar23,iVar7,iVar28,pWVar24,
                                             iVar30,iVar16,iVar17);
                                }
                              }
                            }
                          }
                          else {
                            iVar27 = 100;
                            iVar7 = TacticalAIGroup::unit(this_01,iStack_d0);
                            TribeTacticalAIModule::stopUnit(param_1,iVar7,iVar27);
                          }
                        }
                        else {
                          iStack_c8 = 0;
                        }
                      }
                      iStack_d0 = iStack_d0 + 1;
                      iVar7 = TacticalAIGroup::numberUnits(this_01);
                    } while (iStack_d0 < iVar7);
                  }
                  pRVar18 = pRStack_80;
                  if (pRStack_cc == (RGE_Static_Object *)0x1) {
                    uVar6 = RGE_Action_List::have_action
                                      ((RGE_Action_List *)pRStack_80[2].unitAIValue);
                    if ((uVar6 == '\0') ||
                       (pRVar14 = RGE_Action_List::get_action
                                            ((RGE_Action_List *)pRVar18[2].unitAIValue),
                       pRVar14->state == '\x02')) {
                      pTVar12 = pTStack_c4;
                      pWVar15 = TacticalAIGroup::targetLocation(pTStack_c4);
                      fVar23 = pWVar15->y - _DAT_00575768;
                      pWVar15 = TacticalAIGroup::targetLocation(pTVar12);
                      fVar22 = pWVar15->x - _DAT_00575768;
                      iVar7 = TacticalAIGroup::commander(pTVar12);
                      TribeTacticalAIModule::taskTransporter(param_1,iVar7,fVar22,fVar23);
                      TacticalAIGroup::setAction(pTVar12,0xc);
                    }
                  }
                  else if (iStack_c8 != 0) {
                    iVar30 = -1;
                    iVar28 = -1;
                    iVar27 = -1;
                    iVar7 = TacticalAIGroup::assistGroupID(this_01);
                    pTVar12 = TribeTacticalAIModule::group(param_1,iVar7,iVar27,iVar28,iVar30);
                    if (pTVar12 != (TacticalAIGroup *)0x0) {
                      TacticalAIGroup::setTarget(pTVar12,-1);
                      TacticalAIGroup::setTargetType(pTVar12,-1);
                      TacticalAIGroup::setAction(pTVar12,1);
                      TacticalAIGroup::setInUse(pTVar12,0);
                      pRVar18 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,
                                           -1,-1,-1,-1);
                      if (pRVar18 != (RGE_Static_Object *)0x0) {
                        fVar23 = pRVar18->world_y;
                        fVar22 = pRVar18->world_x;
                        iVar27 = 0x32;
                        iVar7 = TacticalAIGroup::commander(pTVar12);
                        TribeTacticalAIModule::moveUnit(param_1,iVar7,fVar22,fVar23,iVar27);
                      }
                    }
                    iVar7 = TacticalAIGroup::type(this_01);
                    if (iVar7 != 100) {
                      iVar7 = TacticalAIGroup::type(this_01);
                      if ((iVar7 != 0x65) && (iVar7 = TacticalAIGroup::type(this_01), iVar7 != 0x6d)
                         ) goto LAB_004f3825;
                      pWVar15 = TacticalAIGroup::targetLocation(this_01);
                      fVar23 = pWVar15->z;
                      pWVar15 = TacticalAIGroup::targetLocation(this_01);
                      fVar22 = pWVar15->y;
                      pWVar15 = TacticalAIGroup::targetLocation(this_01);
                      TacticalAIGroup::setGatherLocation(this_01,pWVar15->x,fVar22,fVar23);
                      TacticalAIGroup::setInUse(this_01,0);
                      TacticalAIGroup::setAction(this_01,1);
                      pTVar25 = param_1->md;
                      iVar7 = 1;
                      iVar28 = 1;
                      iVar27 = 1;
                      goto LAB_004f4540;
                    }
                    iVar7 = TacticalAIGroup::commander(this_01);
                    pRVar18 = MainDecisionAIModule::object
                                        ((MainDecisionAIModule *)param_1->md,iVar7);
                    if (pRVar18 == (RGE_Static_Object *)0x0) {
LAB_004f376c:
                      TacticalAIGroup::setInUse(this_01,1);
                      TacticalAIGroup::setAction(this_01,7);
                      pTVar25 = param_1->md;
                      iVar7 = 1;
                      iVar28 = 0;
                      iVar27 = 7;
                      goto LAB_004f4540;
                    }
                    iVar7 = pRVar18->_padding_;
                    fVar21 = (float10)(**(code **)(iVar7 + 0x10c))(0,1,0xffffffff,0xffffffff);
                    fVar23 = (float)fVar21;
                    iVar27 = TacticalAIGroup::target(this_01);
                    iVar7 = (**(code **)(iVar7 + 0x194))(iVar27,fVar23);
                    if (iVar7 != 1) goto LAB_004f376c;
                    param_1->lastGroupAttackTime =
                         *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
                    if (param_1->sn[0x47] == 1) {
                      param_1->lastAttackResponseTime =
                           *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
                    }
                    iVar7 = 2;
LAB_004f4526:
                    TacticalAIGroup::setAction(this_01,iVar7);
                    goto LAB_004f452d;
                  }
                  goto LAB_004f4548;
                }
              }
LAB_004f37f1:
              TacticalAIGroup::setTarget(this_01,-1);
              this_01->numberObjectsToDestroyValue = 0;
              TacticalAIGroup::setTargetType(this_01,-1);
              TacticalAIGroup::setAction(this_01,1);
              TacticalAIGroup::setInUse(this_01,0);
              (param_1->attackStateValue).active = 0;
            }
            else {
LAB_004f3825:
              iVar7 = TacticalAIGroup::action(this_01);
              if (iVar7 != 0xc) {
                iVar7 = TacticalAIGroup::action(this_01);
                if (iVar7 != 0x13) {
                  iVar7 = TacticalAIGroup::action(this_01);
                  if (iVar7 != 3) {
LAB_004f3a51:
                    iVar7 = TacticalAIGroup::action(this_01);
                    if (iVar7 == 7) {
                      iVar7 = TacticalAIGroup::commander(this_01);
                      pRVar18 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)param_1->md,iVar7);
                      if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
                         (piVar10 = (int *)operator_new(4), piVar10 != (int *)0x0)) {
                        iVar7 = 0;
                        if (0 < (param_1->playersToAttack).maximumSizeValue) {
                          do {
                            if (0 < iVar7) break;
                            iVar27 = iVar7 + 1;
                            piVar10[iVar7] = (param_1->playersToAttack).value[iVar7];
                            iVar7 = iVar27;
                          } while (iVar27 < (param_1->playersToAttack).maximumSizeValue);
                        }
                        operator_delete((param_1->playersToAttack).value);
                        (param_1->playersToAttack).value = piVar10;
                        (param_1->playersToAttack).maximumSizeValue = 1;
                      }
                      pOVar19 = TribeInformationAIModule::objectToAttackByGroup
                                          (&param_1->md->informationAI,
                                           *(param_1->playersToAttack).value,this_01,
                                           &param_1->attackStateValue,param_2);
                      if ((param_1->attackStateValue).active == 1) goto LAB_004f45bf;
                      pRVar9 = (RGE_Static_Object *)0x0;
                      if (pOVar19 != (ObjectMemory *)0x0) {
                        pRVar9 = MainDecisionAIModule::object
                                           ((MainDecisionAIModule *)param_1->md,pOVar19->id);
                      }
                      if (((pRVar18 == (RGE_Static_Object *)0x0) || (pOVar19 == (ObjectMemory *)0x0)
                          ) || (pRVar9 == (RGE_Static_Object *)0x0)) {
LAB_004f3d28:
                        uVar8 = TacticalAIGroup::consecutiveIdleUnitCount(this_01);
                        if ((uint)(param_1->sn[0x58] << 2) <
                            (*(int *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4) - uVar8) / 1000)
{
                          TacticalAIGroup::setAction(this_01,7);
                          pTVar25 = param_1->md;
                          iVar7 = 1;
                          iVar28 = 0;
                          iVar27 = 7;
                          goto LAB_004f4540;
                        }
                        goto LAB_004f3d75;
                      }
                      uStack_98 = (uint)pOVar19->y;
                      uStack_94 = (uint)pOVar19->z;
                      uStack_9c = (uint)pOVar19->x;
                      iVar7 = pRVar18->_padding_;
                      pRStack_cc = *(RGE_Static_Object **)(iVar7 + 0x10c);
                      fVar21 = (float10)(*(code *)pRStack_cc)
                                                  (pOVar19->id,auStack_84,1,pOVar19->owner,0x1b);
                      iVar27 = (**(code **)(iVar7 + 0x198))
                                         (uStack_9c,uStack_98,uStack_94,(float)fVar21);
                      if (iVar27 == 1) {
                        TacticalAIGroup::setAction(this_01,2);
                        TacticalAIGroup::setTarget(this_01,pOVar19->id);
                        TacticalAIGroup::setTargetType(this_01,(int)pOVar19->type);
                        pTStack_c4 = (TacticalAIGroup *)(uint)pOVar19->x;
                        TacticalAIGroup::setTargetLocation
                                  (this_01,(float)(int)pTStack_c4,(float)pOVar19->y,
                                   (float)pOVar19->z);
                        TacticalAIGroup::setInUse(this_01,1);
                        pTVar25 = param_1->md;
                        iVar7 = 1;
                        iVar28 = 0;
                        iVar27 = 2;
                        goto LAB_004f4540;
                      }
                      fVar21 = (float10)(*(code *)pRStack_cc)
                                                  (pOVar19->id,auStack_84,1,0x16,1,pOVar19->owner,
                                                   0x1b);
                      iVar27 = (**(code **)(iVar7 + 0x1a4))
                                         (uStack_9c,uStack_98,uStack_94,(float)fVar21);
                      if ((iVar27 != 1) ||
                         (iVar7 = (**(code **)(iVar7 + 0x1a8))(2,auStack_1c,auStack_28), iVar7 != 1)
                         ) goto LAB_004f3d28;
                      TacticalAIGroup::task(this_01,param_1,param_1->md,0xe,1,0);
                      TacticalAIGroup::setAction(this_01,0xd);
                      TacticalAIGroup::setTarget(this_01,pOVar19->id);
                      TacticalAIGroup::setTargetType(this_01,(int)pOVar19->type);
                      bVar1 = pOVar19->z;
                      bVar2 = pOVar19->y;
                      pTVar12 = (TacticalAIGroup *)(uint)pOVar19->x;
                      pTStack_c4 = pTVar12;
LAB_004f3cf9:
                      TacticalAIGroup::setTargetLocation
                                (this_01,(float)(int)pTVar12,(float)bVar2,(float)bVar1);
                      TacticalAIGroup::setInUse(this_01,1);
                      TacticalAIGroup::setWaitCode(this_01,200);
                      this_01->playNumberValue = -1;
                      goto LAB_004f4548;
                    }
LAB_004f3d75:
                    iVar7 = TacticalAIGroup::action(this_01);
                    if ((iVar7 == 2) && (this_01->playNumberValue == -1)) {
                      if (param_1->sn[0x5b] < 100) {
                        iVar27 = 0;
                        iVar7 = TacticalAIGroup::numberUnits(this_01);
                        if (0 < iVar7) {
                          do {
                            iVar7 = TacticalAIGroup::unit(this_01,iVar27);
                            pTStack_c4 = (TacticalAIGroup *)
                                         MainDecisionAIModule::object
                                                   ((MainDecisionAIModule *)param_1->md,iVar7);
                            if (pTStack_c4 == (TacticalAIGroup *)0x0) {
LAB_004f3e53:
                              iVar27 = iVar27 + 1;
                            }
                            else {
                              iVar7 = TacticalAIGroup::unitOriginalHitPoints(this_01,iVar27);
                              iVar28 = __ftol();
                              iVar30 = TacticalAIGroup::unitOriginalHitPoints(this_01,iVar27);
                              if (((iVar7 - iVar28) * 100) / iVar30 <= param_1->sn[0x5b])
                              goto LAB_004f3e53;
                              iVar28 = 100;
                              pWVar15 = TacticalAIGroup::retreatLocation(this_01);
                              fVar23 = pWVar15->y;
                              pWVar15 = TacticalAIGroup::retreatLocation(this_01);
                              fVar22 = pWVar15->x;
                              iVar7 = TacticalAIGroup::unit(this_01,iVar27);
                              TribeTacticalAIModule::moveUnit(param_1,iVar7,fVar22,fVar23,iVar28);
                              pTVar25 = param_1->md;
                              iVar7 = TacticalAIGroup::unit(this_01,iVar27);
                              TacticalAIGroup::removeUnit(this_01,iVar7,pTVar25);
                              iVar7 = TacticalAIGroup::numberUnits(this_01);
                              if (iVar7 == 0) break;
                            }
                            iVar7 = TacticalAIGroup::numberUnits(this_01);
                          } while (iVar27 < iVar7);
                        }
                      }
                      iVar7 = TacticalAIGroup::target(this_01);
                      pRVar18 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)param_1->md,iVar7);
                      if ((pRVar18 != (RGE_Static_Object *)0x0) && (pRVar18->object_state < 3)) {
                        iVar7 = TacticalAIGroup::subType(this_01);
                        if (iVar7 == -1) {
                          iVar7 = (**(code **)(*(int *)param_1->md->_padding_ + 0x1c))
                                            ((int)pRVar18->owner->id);
                          if (iVar7 == 0) {
                            iVar7 = TacticalAIGroup::allUnitsIdle(this_01,param_1->md,0);
                            if (iVar7 != 1) {
                              pTVar25 = param_1->md;
                              iVar7 = 1;
                              iVar28 = 0;
                              iVar27 = 0x14;
                              goto LAB_004f4540;
                            }
                            iVar7 = TacticalAIGroup::commander(this_01);
                            pRVar18 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)param_1->md,iVar7);
                            if (pRVar18 == (RGE_Static_Object *)0x0) {
                              (param_1->attackStateValue).active = 0;
                              goto LAB_004f4552;
                            }
                            iVar7 = pRVar18->_padding_;
                            fVar21 = (float10)(**(code **)(iVar7 + 0x10c))
                                                        (0,1,0xffffffff,0xffffffff);
                            fVar23 = (float)fVar21;
                            iVar27 = TacticalAIGroup::target(this_01);
                            iVar7 = (**(code **)(iVar7 + 0x194))(iVar27,fVar23);
                            if (iVar7 == 1) {
                              iVar28 = 0;
                              iVar27 = 0x14;
                              iVar7 = 1;
                              goto LAB_004f4539;
                            }
                            TacticalAIGroup::setGatherLocation
                                      (this_01,pRVar18->world_x,pRVar18->world_y,pRVar18->world_z);
                            TacticalAIGroup::setInUse(this_01,0);
                            TacticalAIGroup::setAction(this_01,1);
                            TacticalAIGroup::setTarget(this_01,-1);
                            TacticalAIGroup::setTargetType(this_01,-1);
                            this_01->numberObjectsToDestroyValue = 0;
                            TacticalAIGroup::setTargetLocation(this_01,-1.0,-1.0,-1.0);
                          }
                          else {
                            TacticalAIGroup::setInUse(this_01,0);
                            TacticalAIGroup::setAction(this_01,1);
                            TacticalAIGroup::setTarget(this_01,-1);
                            TacticalAIGroup::setTargetType(this_01,-1);
                            TacticalAIGroup::setTargetLocation(this_01,-1.0,-1.0,-1.0);
                            this_01->numberObjectsToDestroyValue = 0;
                            iVar7 = TacticalAIGroup::commander(this_01);
                            pRVar18 = MainDecisionAIModule::object
                                                ((MainDecisionAIModule *)param_1->md,iVar7);
                            if (pRVar18 != (RGE_Static_Object *)0x0) {
                              TacticalAIGroup::setGatherLocation
                                        (this_01,pRVar18->world_x,pRVar18->world_y,pRVar18->world_z)
                              ;
                            }
                          }
                          goto LAB_004f4548;
                        }
                        iVar7 = TacticalAIGroup::subType(this_01);
                        if ((((iVar7 != 0) &&
                             (iVar7 = TacticalAIGroup::subType(this_01), iVar7 == 4)) &&
                            (pRVar18->owner->id == *(short *)(param_1->md->_padding_ + 0x4a))) &&
                           (iVar7 = TribeMainDecisionAIModule::isMoveable(param_1->md,pRVar18->id),
                           iVar7 != 0)) {
                          TacticalAIGroup::addUnit(this_01,pRVar18->id,param_1->md);
                          pWVar15 = TribeStrategyAIModule::targetPoint1(&param_1->md->strategyAI);
                          fStack_58 = pWVar15->x;
                          fStack_54 = pWVar15->y;
                          fStack_50 = pWVar15->z;
                          uStack_4c = *(undefined4 *)&pWVar15->facetToNextWaypoint;
                          pWVar15 = TribeStrategyAIModule::targetPoint2(&param_1->md->strategyAI);
                          fStack_48 = pWVar15->x;
                          fStack_44 = pWVar15->y;
                          fStack_40 = pWVar15->z;
                          uStack_3c = *(undefined4 *)&pWVar15->facetToNextWaypoint;
                          TacticalAIGroup::setInUse(this_01,0);
                          TacticalAIGroup::setAction(this_01,1);
                          TacticalAIGroup::setTarget(this_01,-1);
                          this_01->numberObjectsToDestroyValue = 0;
                          TacticalAIGroup::setTargetType(this_01,-1);
                          TacticalAIGroup::setTargetLocation(this_01,-1.0,-1.0,-1.0);
                          TacticalAIGroup::setGatherLocation
                                    (this_01,(fStack_48 + fStack_58) * _DAT_005756fc,
                                     (fStack_44 + fStack_54) * _DAT_005756fc,
                                     (fStack_40 + fStack_50) * _DAT_005756fc);
                        }
                        uVar8 = TacticalAIGroup::consecutiveIdleUnitCount(this_01);
                        if ((uint)param_1->sn[0x4c] <
                            (*(int *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4) - uVar8) / 1000)
{
                          TacticalAIGroup::setInUse(this_01,0);
                          TacticalAIGroup::setAction(this_01,1);
                          TacticalAIGroup::setTarget(this_01,-1);
                          TacticalAIGroup::setTargetType(this_01,-1);
                          TacticalAIGroup::setTargetLocation(this_01,-1.0,-1.0,-1.0);
                          this_01->numberObjectsToDestroyValue = 0;
                          (param_1->attackStateValue).active = 0;
                          goto LAB_004f4552;
                        }
                        goto LAB_004f436b;
                      }
                      if (param_1->sn[0x31] == 2) {
                        TacticalAIGroup::setAction(this_01,1);
                        TacticalAIGroup::setTarget(this_01,-1);
                        this_01->numberObjectsToDestroyValue = 0;
                        TacticalAIGroup::setTargetType(this_01,-1);
                        TacticalAIGroup::setTargetLocation(this_01,-1.0,-1.0,-1.0);
                        iVar7 = 0;
                        iVar28 = 1;
                        iVar27 = TacticalAIGroup::action(this_01);
                        pTVar25 = param_1->md;
                        goto LAB_004f4540;
                      }
                      iVar7 = TacticalAIGroup::commander(this_01);
                      pRVar18 = MainDecisionAIModule::object
                                          ((MainDecisionAIModule *)param_1->md,iVar7);
                      if (pRVar18 == (RGE_Static_Object *)0x0) {
                        (param_1->attackStateValue).active = 0;
                        goto LAB_004f4552;
                      }
                      if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
                         (piVar10 = (int *)operator_new(4), piVar10 != (int *)0x0)) {
                        iVar7 = 0;
                        if (0 < (param_1->playersToAttack).maximumSizeValue) {
                          do {
                            if (0 < iVar7) break;
                            iVar27 = iVar7 + 1;
                            piVar10[iVar7] = (param_1->playersToAttack).value[iVar7];
                            iVar7 = iVar27;
                          } while (iVar27 < (param_1->playersToAttack).maximumSizeValue);
                        }
                        operator_delete((param_1->playersToAttack).value);
                        (param_1->playersToAttack).value = piVar10;
                        (param_1->playersToAttack).maximumSizeValue = 1;
                      }
                      pOVar19 = TribeInformationAIModule::objectToAttackByGroup
                                          (&param_1->md->informationAI,
                                           *(param_1->playersToAttack).value,this_01,
                                           &param_1->attackStateValue,param_2);
                      if ((param_1->attackStateValue).active == 1) {
LAB_004f45bf:
                        iVar7 = TacticalAIGroup::id(this_01);
                        param_1->nextActiveSoldierGroupToTaskValue = iVar7;
                        return;
                      }
                      if (pOVar19 != (ObjectMemory *)0x0) {
                        uStack_64 = (uint)pOVar19->y;
                        uStack_68 = (uint)pOVar19->x;
                        uStack_60 = (uint)pOVar19->z;
                        iVar7 = pRVar18->_padding_;
                        fVar21 = (float10)(**(code **)(iVar7 + 0x10c))
                                                    (pOVar19->id,auStack_14,1,pOVar19->owner,0x1b);
                        iVar7 = (**(code **)(iVar7 + 0x198))
                                          (uStack_68,uStack_64,uStack_60,(float)fVar21);
                        if (iVar7 == 1) {
                          TacticalAIGroup::setTarget(this_01,pOVar19->id);
                          TacticalAIGroup::setTargetType(this_01,(int)pOVar19->type);
                          pTStack_c4 = (TacticalAIGroup *)(uint)pOVar19->x;
                          TacticalAIGroup::setTargetLocation
                                    (this_01,(float)(int)pTStack_c4,(float)pOVar19->y,
                                     (float)pOVar19->z);
                          TacticalAIGroup::setInUse(this_01,1);
                          pTVar25 = param_1->md;
                          iVar7 = 0;
                          iVar28 = 0;
                          iVar27 = 2;
                          goto LAB_004f4540;
                        }
                      }
                      iVar7 = TacticalAIGroup::targetType(this_01);
                      TacticalAIGroup::setInUse(this_01,0);
                      TacticalAIGroup::setAction(this_01,1);
                      TacticalAIGroup::setTarget(this_01,-1);
                      this_01->numberObjectsToDestroyValue = 0;
                      TacticalAIGroup::setTargetType(this_01,-1);
                      TacticalAIGroup::setTargetLocation(this_01,-1.0,-1.0,-1.0);
                      if (param_1->sn[0x31] == 0) {
                        TacticalAIGroup::setGatherLocation
                                  (this_01,pRVar18->world_x,pRVar18->world_y,pRVar18->world_z);
                        goto LAB_004f4548;
                      }
                      if (((param_1->sn[0x31] != 3) || (iVar7 == 0x7e)) || (iVar7 == 0x59))
                      goto LAB_004f4548;
                      if (param_1->sn[0x87] == 1) {
                        iVar27 = __ftol();
                        iVar7 = param_1->sn[0x88];
                        iVar28 = __ftol();
                        TribeInformationAIModule::blotExploredMap
                                  (&param_1->md->informationAI,iVar28 - iVar7,iVar27 - iVar7,
                                   iVar28 + iVar7,iVar7 + iVar27);
                      }
                      TacticalAIGroup::setInUse(this_01,1);
                      TacticalAIGroup::setAction(this_01,7);
                      iVar7 = 1;
                      iVar28 = 0;
                      iVar27 = 7;
                    }
                    else {
LAB_004f436b:
                      iVar7 = TacticalAIGroup::action(this_01);
                      if ((iVar7 == 2) && (this_01->playNumberValue != -1)) {
                        iVar7 = TacticalAIGroup::commander(this_01);
                        pRVar18 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)param_1->md,iVar7);
                        if ((pRVar18 != (RGE_Static_Object *)0x0) &&
                           ((pUVar13 = RGE_Static_Object::unitAI(pRVar18),
                            pUVar13 != (UnitAIModule *)0x0 &&
                            (pUVar13 = RGE_Static_Object::unitAI(pRVar18),
                            pUVar13->playStatus == (AIPlayStatus *)0x0)))) {
                          this_01->playNumberValue = -1;
                          (param_1->attackStateValue).active = 0;
                          goto LAB_004f4552;
                        }
                        goto LAB_004f43ca;
                      }
                      iVar7 = TacticalAIGroup::action(this_01);
                      if (iVar7 != 4) {
LAB_004f4499:
                        iVar7 = TacticalAIGroup::action(this_01);
                        if ((iVar7 != 3) && (iVar7 = TacticalAIGroup::action(this_01), iVar7 != 0xd)
                           ) {
                          iVar7 = TacticalAIGroup::currentHitPoints(this_01,param_1->md);
                          iVar27 = TacticalAIGroup::originalHitPoints(this_01);
                          iVar28 = TacticalAIGroup::originalHitPoints(this_01);
                          iVar30 = TacticalAIGroup::numberUnits(this_01);
                          iVar16 = TacticalAIGroup::originalUnitNumber(this_01);
                          iVar17 = TacticalAIGroup::originalUnitNumber(this_01);
                          if ((param_1->sn[0x1e] < ((iVar27 - iVar7) * 100) / iVar28) ||
                             (param_1->sn[0x1f] < ((iVar16 - iVar30) * 100) / iVar17)) {
                            iVar7 = 3;
                            goto LAB_004f4526;
                          }
                        }
                        goto LAB_004f4552;
                      }
                      iVar7 = TacticalAIGroup::allUnitsIdle(this_01,param_1->md,1);
                      if ((iVar7 != 1) ||
                         (iVar7 = TacticalAIGroup::isGathered(this_01,param_1,param_1->md),
                         iVar7 != 0)) {
                        iVar7 = TacticalAIGroup::target(this_01);
                        pRVar18 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)param_1->md,iVar7);
                        if (pRVar18 != (RGE_Static_Object *)0x0) {
                          iVar28 = (int)pRVar18->master_obj->object_group;
                          iVar7 = TacticalAIGroup::targetType(this_01);
                          iVar27 = TacticalAIGroup::commander(this_01);
                          pOVar19 = TribeInformationAIModule::higherPriorityObjectToDefend
                                              (&param_1->md->informationAI,iVar27,iVar7,iVar28);
                          if (pOVar19 == (ObjectMemory *)0x0) goto LAB_004f4499;
                          iVar7 = TacticalAIGroup::target(this_01);
                          pOVar19 = TribeInformationAIModule::objectMemory
                                              (&param_1->md->informationAI,iVar7);
                          if (pOVar19 != (ObjectMemory *)0x0) {
                            pOVar19->attackAttempts = 0;
                          }
                        }
                        TacticalAIGroup::setAction(this_01,1);
                        TacticalAIGroup::setInUse(this_01,0);
                        goto LAB_004f448e;
                      }
                      iVar28 = 1;
                      iVar27 = 9;
                      iVar7 = 0;
                    }
LAB_004f4539:
                    pTVar25 = param_1->md;
                    goto LAB_004f4540;
                  }
                  pTVar25 = param_1->md;
                  uVar8 = TacticalAIGroup::consecutiveIdleUnitCount(this_01);
                  if ((uint)param_1->sn[0x4c] <
                      (*(int *)(*(int *)(pTVar25->_padding_ + 0x3c) + 4) - uVar8) / 1000) {
                    TacticalAIGroup::setInUse(this_01,0);
                    TacticalAIGroup::setAction(this_01,1);
                    TacticalAIGroup::setTarget(this_01,-1);
                    this_01->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setTargetType(this_01,-1);
                    TacticalAIGroup::setTargetLocation(this_01,-1.0,-1.0,-1.0);
                    (param_1->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
                  iVar7 = TacticalAIGroup::isGathered(this_01,param_1,pTVar25);
                  if (iVar7 == 0) goto LAB_004f3a51;
                  TacticalAIGroup::setAction(this_01,1);
                  TacticalAIGroup::setInUse(this_01,0);
                  iVar7 = TacticalAIGroup::type(this_01);
                  if ((iVar7 == 0x65) || (iVar7 = TacticalAIGroup::type(this_01), iVar7 == 0x68)) {
                    iVar7 = TacticalAIGroup::target(this_01);
                    pOVar19 = TribeInformationAIModule::objectMemory
                                        (&param_1->md->informationAI,iVar7);
                    if (pOVar19 != (ObjectMemory *)0x0) {
                      pOVar19->attackAttempts = 0;
                    }
                  }
                  iVar7 = BuildAIModule::buildListLength((BuildAIModule *)&param_1->md->buildAI);
                  if ((iVar7 == 0) &&
                     (((iVar7 = TacticalAIGroup::type(this_01), iVar7 == 100 &&
                       (iVar7 = TribeTacticalAIModule::numberGroups(param_1,100,-1), 1 < iVar7)) ||
                      (iVar7 = TacticalAIGroup::type(this_01), iVar7 != 100)))) {
                    iVar7 = TacticalAIGroup::type(this_01);
                    if (iVar7 == 0x66) {
                      param_1->sn[0x2a] = param_1->sn[0x2a] + -1;
                    }
                    else {
                      iVar7 = TacticalAIGroup::type(this_01);
                      if (iVar7 == 0x65) {
                        param_1->sn[0x26] = param_1->sn[0x26] + -1;
                      }
                      else {
                        iVar7 = TacticalAIGroup::type(this_01);
                        if (iVar7 == 100) {
                          param_1->sn[0x24] = param_1->sn[0x24] + -1;
                        }
                      }
                    }
                    TacticalAIGroup::removeUnits(this_01,param_1->md);
                    TacticalAIGroup::setAction(this_01,0);
                    (param_1->attackStateValue).active = 0;
                    goto LAB_004f4552;
                  }
LAB_004f448e:
                  (param_1->attackStateValue).active = 0;
                  goto LAB_004f4552;
                }
                iVar7 = TacticalAIGroup::isGathered(this_01,param_1,param_1->md);
                if (iVar7 == 0) {
                  pTVar25 = param_1->md;
                  uVar8 = TacticalAIGroup::consecutiveIdleUnitCount(this_01);
                  iVar7 = *(int *)(*(int *)(pTVar25->_padding_ + 0x3c) + 4);
                  iVar27 = TacticalAIGroup::allUnitsIdle(this_01,pTVar25,1);
                  if ((iVar27 == 1) && (5 < (iVar7 - uVar8) / 1000)) {
                    TacticalAIGroup::setConsecutiveIdleUnitCount
                              (this_01,*(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4));
                    pTVar25 = param_1->md;
                    iVar7 = 0;
                    iVar28 = 1;
                    iVar27 = 9;
                    goto LAB_004f4540;
                  }
                }
              }
LAB_004f4548:
              (param_1->attackStateValue).active = 0;
            }
          }
        }
LAB_004f4552:
        if ((param_1->attackStateValue).active != 0) {
          return;
        }
        this_01 = this_01->next;
        if ((this_01 == &param_1->groups) || (this_01 == (TacticalAIGroup *)0x0)) {
          param_1->nextActiveSoldierGroupToTaskValue = -1;
        }
        else {
          iVar7 = TacticalAIGroup::id(this_01);
          param_1->nextActiveSoldierGroupToTaskValue = iVar7;
        }
        uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x14fe);
        if (param_3 <= uVar8 - param_2) {
          return;
        }
      }
    } while (this_01 != &param_1->groups);
  }
  param_1->nextActiveSoldierGroupToTaskValue = -1;
  return;
}

// --------------------------------------------------

// Function: FUN_004f475c
// Address: 004f475c
// XREFS: None
void __fastcall FUN_004f475c(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int *piVar5;
  ObjectMemory *pOVar6;
  RGE_Static_Object *pRVar7;
  int iVar8;
  int *piStack_1a4;
  int *piStack_1a0;
  int iStack_19c;
  int iStack_198;
  int iStack_194;
  int aiStack_190 [50];
  int aiStack_c8 [50];
  
  if (param_1->sn[0xa2] != 0) {
    iVar8 = 0;
    piStack_1a4 = (int *)0x0;
    piVar1 = (int *)0;
    if (0 < (param_1->soldiers).numberValue) {
      piStack_1a0 = aiStack_190;
      do {
        if ((param_1->soldiers).maximumSizeValue + -1 < iVar8) {
          piVar1 = (int *)operator_new(iVar8 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->soldiers).maximumSizeValue) {
              do {
                if (iVar8 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (param_1->soldiers).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (param_1->soldiers).maximumSizeValue);
            }
            operator_delete((param_1->soldiers).value);
            (param_1->soldiers).value = piVar1;
            (param_1->soldiers).maximumSizeValue = iVar8 + 1;
          }
        }
        pTVar3 = TribeTacticalAIModule::groupUnitIsIn(param_1,(param_1->soldiers).value[iVar8]);
        if ((pTVar3 == (TacticalAIGroup *)0x0) ||
           (iVar4 = TacticalAIGroup::type(pTVar3), iVar4 != 100)) {
          if ((param_1->soldiers).maximumSizeValue + -1 < iVar8) {
            piVar1 = (int *)operator_new(iVar8 * 4 + 4);
            if (piVar1 != (int *)0x0) {
              iVar4 = 0;
              if (0 < (param_1->soldiers).maximumSizeValue) {
                do {
                  if (iVar8 + 1 <= iVar4) break;
                  iVar2 = iVar4 + 1;
                  piVar1[iVar4] = (param_1->soldiers).value[iVar4];
                  iVar4 = iVar2;
                } while (iVar2 < (param_1->soldiers).maximumSizeValue);
              }
              operator_delete((param_1->soldiers).value);
              (param_1->soldiers).value = piVar1;
              (param_1->soldiers).maximumSizeValue = iVar8 + 1;
            }
          }
          piStack_1a4 = (int *)((int)piStack_1a4 + 1);
          *piStack_1a0 = (param_1->soldiers).value[iVar8];
          piStack_1a0 = piStack_1a0 + 1;
        }
        iVar8 = iVar8 + 1;
        piVar1 = piStack_1a4;
      } while (iVar8 < (param_1->soldiers).numberValue);
    }
    if (piVar1 != (int *)0x0) {
      iStack_194 = -1;
      iStack_19c = 0;
      iStack_198 = -1;
      if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
         (piVar5 = (int *)operator_new(4), piVar5 != (int *)0x0)) {
        iVar8 = 0;
        if (0 < (param_1->playersToAttack).maximumSizeValue) {
          do {
            if (0 < iVar8) break;
            iVar4 = iVar8 + 1;
            piVar5[iVar8] = (param_1->playersToAttack).value[iVar8];
            iVar8 = iVar4;
          } while (iVar4 < (param_1->playersToAttack).maximumSizeValue);
        }
        operator_delete((param_1->playersToAttack).value);
        (param_1->playersToAttack).value = piVar5;
        (param_1->playersToAttack).maximumSizeValue = 1;
      }
      pOVar6 = TribeInformationAIModule::objectToAttackWithPlay
                         (&param_1->md->informationAI,*(param_1->playersToAttack).value,aiStack_190,
                          (int)piVar1,&iStack_194,aiStack_c8,&iStack_19c,&iStack_198);
      if (((pOVar6 != (ObjectMemory *)0x0) &&
          (pRVar7 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iStack_198),
          pRVar7 != (RGE_Static_Object *)0x0)) &&
         (pTVar3 = TribeTacticalAIModule::createGroup(param_1,1), pTVar3 != (TacticalAIGroup *)0x0))
{
        TacticalAIGroup::setType(pTVar3,100);
        TacticalAIGroup::setDesiredNumberUnits(pTVar3,iStack_19c);
        iVar8 = 0;
        if (0 < iStack_19c) {
          piStack_1a4 = aiStack_c8;
          do {
            TacticalAIGroup::addUnit(pTVar3,*piStack_1a4,param_1->md);
            iVar8 = iVar8 + 1;
            piStack_1a4 = piStack_1a4 + 1;
          } while (iVar8 < iStack_19c);
        }
        TacticalAIGroup::setSpecificCommander(pTVar3,iStack_198,param_1->md);
        TacticalAIGroup::setLocation(pTVar3,pRVar7->world_x,pRVar7->world_y,pRVar7->world_z);
        TacticalAIGroup::setGatherLocation(pTVar3,pRVar7->world_x,pRVar7->world_y,pRVar7->world_z);
        TacticalAIGroup::setRetreatLocation(pTVar3,pRVar7->world_x,pRVar7->world_y,pRVar7->world_z);
        TacticalAIGroup::setTarget(pTVar3,pOVar6->id);
        pTVar3->playNumberValue = iStack_194;
        TacticalAIGroup::setAction(pTVar3,2);
        TacticalAIGroup::setInUse(pTVar3,1);
        TacticalAIGroup::task(pTVar3,param_1,param_1->md,2,1,1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004f4a97
// Address: 004f4a97
// XREFS: None
RGE_Static_Object * __fastcall FUN_004f4a97(TribeTacticalAIModule *param_1)
{
  ManagedArray<int> *this;
  ManagedArray<int> *this_00;
  ulong uVar1;
  RGE_Static_Object *pRVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iStack_1c;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  uVar1 = ((RGE_Player *)param_1->md->_padding_)->world->world_time;
  uVar8 = uVar1 - param_1->lastUngroupedSoldierTaskTime;
  pRVar2 = (RGE_Static_Object *)(uVar8 * 0x10624dd3);
  if (0x3b < uVar8 / 1000) {
    param_1->lastUngroupedSoldierTaskTime = uVar1;
    pRVar2 = MainDecisionAIModule::object
                       ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      XStack_10.x = __ftol();
      XStack_10.y = __ftol();
      pRVar2 = (RGE_Static_Object *)(param_1->soldiers).numberValue;
      iStack_1c = 0;
      if (0 < (int)pRVar2) {
        this = &param_1->soldiers;
        do {
          if ((param_1->soldiers).maximumSizeValue + -1 < iStack_1c) {
            ManagedArray<int>::resize(this,iStack_1c + 1);
          }
          pTVar3 = TribeTacticalAIModule::groupUnitIsIn(param_1,this->value[iStack_1c]);
          if (pTVar3 == (TacticalAIGroup *)0x0) {
            if ((param_1->soldiers).maximumSizeValue + -1 < iStack_1c) {
              ManagedArray<int>::resize(this,iStack_1c + 1);
            }
            pRVar2 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1->md,this->value[iStack_1c]);
            if (pRVar2 != (RGE_Static_Object *)0x0) {
              if ((param_1->soldiers).maximumSizeValue + -1 < iStack_1c) {
                ManagedArray<int>::resize(this,iStack_1c + 1);
              }
              this_00 = &param_1->ungroupedSoldiers;
              iVar5 = 0;
              if (0 < (param_1->ungroupedSoldiers).numberValue) {
                do {
                  if ((param_1->ungroupedSoldiers).maximumSizeValue <= iVar5) break;
                  if (this_00->value[iVar5] == this->value[iStack_1c]) goto LAB_004f4d69;
                  iVar5 = iVar5 + 1;
                } while (iVar5 < (param_1->ungroupedSoldiers).numberValue);
              }
              if ((param_1->soldiers).maximumSizeValue + -1 < iStack_1c) {
                piVar6 = (int *)operator_new(iStack_1c * 4 + 4);
                if (piVar6 != (int *)0x0) {
                  iVar5 = 0;
                  if (0 < (param_1->soldiers).maximumSizeValue) {
                    do {
                      if (iStack_1c + 1 <= iVar5) break;
                      iVar4 = iVar5 + 1;
                      piVar6[iVar5] = this->value[iVar5];
                      iVar5 = iVar4;
                    } while (iVar4 < (param_1->soldiers).maximumSizeValue);
                  }
                  operator_delete(this->value);
                  this->value = piVar6;
                  (param_1->soldiers).maximumSizeValue = iStack_1c + 1;
                }
              }
              iVar7 = 0;
              iVar5 = this->value[iStack_1c];
              iVar4 = (param_1->ungroupedSoldiers).numberValue;
              if (0 < iVar4) {
                do {
                  if ((param_1->ungroupedSoldiers).maximumSizeValue <= iVar7) break;
                  if (this_00->value[iVar7] == iVar5) goto LAB_004f4cfa;
                  iVar7 = iVar7 + 1;
                } while (iVar7 < iVar4);
              }
              if ((param_1->ungroupedSoldiers).maximumSizeValue + -1 < iVar4) {
                ManagedArray<int>::resize(this_00,iVar4 + 1);
              }
              this_00->value[(param_1->ungroupedSoldiers).numberValue] = iVar5;
              (param_1->ungroupedSoldiers).numberValue =
                   (param_1->ungroupedSoldiers).numberValue + 1;
LAB_004f4cfa:
              iVar5 = TribeInformationAIModule::findGatherPosition
                                (&param_1->md->informationAI,&XStack_10,1,1,param_1->sn[0x16],
                                 param_1->sn[0x48],pRVar2,&XStack_8);
              if (iVar5 == 1) {
                if ((param_1->soldiers).maximumSizeValue + -1 < iStack_1c) {
                  ManagedArray<int>::resize(this,iStack_1c + 1);
                }
                TribeTacticalAIModule::moveUnit
                          (param_1,this->value[iStack_1c],(float)XStack_8.x,(float)XStack_8.y,0x32);
              }
            }
          }
          else {
            if ((param_1->soldiers).maximumSizeValue + -1 < iStack_1c) {
              ManagedArray<int>::resize(this,iStack_1c + 1);
            }
            iVar5 = (param_1->ungroupedSoldiers).maximumSizeValue;
            iVar4 = 0;
            if (0 < iVar5) {
              piVar6 = (param_1->ungroupedSoldiers).value;
              do {
                if (*piVar6 == this->value[iStack_1c]) break;
                iVar4 = iVar4 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar4 < iVar5);
            }
            if (iVar4 < iVar5) {
              if (iVar4 < iVar5 + -1) {
                do {
                  piVar6 = (param_1->ungroupedSoldiers).value;
                  iVar5 = iVar4 + 1;
                  piVar6[iVar4] = piVar6[iVar5];
                  iVar4 = iVar5;
                } while (iVar5 < (param_1->ungroupedSoldiers).maximumSizeValue + -1);
              }
              iVar5 = (param_1->ungroupedSoldiers).numberValue + -1;
              (param_1->ungroupedSoldiers).numberValue = iVar5;
              if (iVar5 < 0) {
                (param_1->ungroupedSoldiers).numberValue = 0;
              }
            }
          }
LAB_004f4d69:
          pRVar2 = (RGE_Static_Object *)(param_1->soldiers).numberValue;
          iStack_1c = iStack_1c + 1;
        } while (iStack_1c < (int)pRVar2);
      }
    }
  }
  return pRVar2;
}

// --------------------------------------------------

// Function: FUN_004f4d84
// Address: 004f4d84
// XREFS: None
void __fastcall FUN_004f4d84(TribeTacticalAIModule *param_1)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  ObjectMemory *pOVar6;
  UnitAIModule *pUVar7;
  RGE_Action_Object *this;
  RGE_Action *pRVar8;
  uint uVar9;
  TacticalAIGroup *pTVar10;
  bool bVar11;
  float *pfVar12;
  float *pfVar13;
  TribeMainDecisionAIModule *pTVar14;
  float fVar15;
  uint *puVar16;
  float fVar17;
  int *piVar18;
  float fVar19;
  int iVar20;
  int iStack_60;
  float fStack_5c;
  float fStack_58;
  int iStack_54;
  int *piStack_50;
  uint uStack_4c;
  float fStack_48;
  float fStack_44;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_28;
  uint uStack_24;
  uint uStack_1c;
  uint uStack_18;
  int aiStack_14 [5];
  
  pTVar10 = (param_1->groups).next;
  if (pTVar10 != &param_1->groups) {
    do {
      if (pTVar10 == (TacticalAIGroup *)0x0) break;
      iVar2 = TacticalAIGroup::type(pTVar10);
      if (((((iVar2 != 100) && (iVar2 = TacticalAIGroup::type(pTVar10), iVar2 != 0x65)) &&
           (iVar2 = TacticalAIGroup::type(pTVar10), iVar2 != 0x66)) &&
          ((iVar2 = TacticalAIGroup::type(pTVar10), iVar2 != 0x67 &&
           (iVar2 = TacticalAIGroup::type(pTVar10), iVar2 != 0x68)))) &&
         ((iVar2 = TacticalAIGroup::type(pTVar10), iVar2 != 0x69 &&
          ((iVar2 = TacticalAIGroup::action(pTVar10), iVar2 == 0 ||
           (iVar2 = TacticalAIGroup::action(pTVar10), iVar2 == 1)))))) {
        bVar11 = true;
        iVar2 = TacticalAIGroup::isGathered(pTVar10,param_1,param_1->md);
        iVar3 = TacticalAIGroup::numberUnits(pTVar10);
        iVar4 = TacticalAIGroup::desiredNumberUnits(pTVar10);
        if ((iVar3 < iVar4) ||
           (((iVar2 == 0 && (iVar3 = TacticalAIGroup::numberUnits(pTVar10), 1 < iVar3)) ||
            (iVar3 = TacticalAIGroup::allUnitsIdle(pTVar10,param_1->md,1), iVar3 == 0)))) {
          bVar11 = false;
        }
        if (bVar11) {
          iVar2 = TacticalAIGroup::type(pTVar10);
          if (iVar2 == 0x6b) {
            iVar2 = 10;
          }
          else {
            iVar2 = TacticalAIGroup::type(pTVar10);
            if (iVar2 == 0x6c) {
              iVar2 = 0xb;
            }
            else {
              iVar2 = TacticalAIGroup::type(pTVar10);
              if (iVar2 != 0x6a) goto LAB_004f4edc;
              iVar2 = 1;
            }
          }
          TacticalAIGroup::setAction(pTVar10,iVar2);
        }
        else if (iVar2 == 0) {
          TacticalAIGroup::task(pTVar10,param_1,param_1->md,9,1,0);
        }
      }
LAB_004f4edc:
      pTVar10 = pTVar10->next;
    } while (pTVar10 != &param_1->groups);
  }
  pTVar10 = (param_1->groups).next;
  if (pTVar10 != &param_1->groups) {
    do {
      if (pTVar10 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar2 = TacticalAIGroup::type(pTVar10);
      if (((((iVar2 == 100) || (iVar2 = TacticalAIGroup::type(pTVar10), iVar2 == 0x65)) ||
           ((iVar2 = TacticalAIGroup::type(pTVar10), iVar2 == 0x66 ||
            ((iVar2 = TacticalAIGroup::type(pTVar10), iVar2 == 0x67 ||
             (iVar2 = TacticalAIGroup::type(pTVar10), iVar2 == 0x68)))))) ||
          (iVar2 = TacticalAIGroup::type(pTVar10), iVar2 == 0x69)) ||
         ((iVar2 = TacticalAIGroup::action(pTVar10), iVar2 == 0 ||
          (iVar2 = TacticalAIGroup::action(pTVar10), iVar2 == 1)))) goto LAB_004f579c;
      iVar2 = TacticalAIGroup::inUse(pTVar10);
      if (iVar2 == 0) {
        iVar2 = TacticalAIGroup::type(pTVar10);
        if (iVar2 == 0x6b) {
          iVar2 = TacticalAIGroup::commander(pTVar10);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) {
            TacticalAIGroup::setAction(pTVar10,1);
          }
          else {
            iVar3 = -1;
            iStack_60 = 0;
            iStack_54 = -1;
            iVar2 = TribeTacticalAIModule::numberWaterExplorers(param_1);
            if (0 < iVar2) {
              iVar2 = TacticalAIGroup::commander(pTVar10);
              iVar2 = TribeInformationAIModule::fullyExploredZone(&param_1->md->informationAI,iVar2)
              ;
              if (iVar2 == 1) {
                piStack_50 = aiStack_14;
                uStack_4c = 0;
                do {
                  fStack_5c = 0.0;
                  fStack_58 = 0.0;
                  iVar3 = TribeInformationAIModule::gameIDOfResourceObject
                                    (&param_1->md->informationAI,0,pRVar5->id,&fStack_5c,&fStack_58,
                                     &iStack_54,aiStack_14,iStack_60);
                  uStack_38 = __ftol();
                  uStack_34 = __ftol();
                  uStack_30 = __ftol();
                  if (iStack_54 == -1) {
                    iVar2 = (**(code **)(pRVar5->_padding_ + 0x198))
                                      (uStack_38,uStack_34,uStack_30,0x3f800000,iVar3);
                  }
                  else {
                    iVar2 = (**(code **)(pRVar5->_padding_ + 0x19c))
                                      (iVar3,iStack_54,0x3f800000,0,1,0xffffffff,0xffffffff);
                  }
                  if (iVar2 == 0) {
                    iStack_60 = iStack_60 + 1;
                    *piStack_50 = iVar3;
                    piStack_50 = piStack_50 + 1;
                  }
                } while ((iVar2 != 1) && (uStack_4c = uStack_4c + 1, (int)uStack_4c < 5));
              }
            }
            pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar3);
            if ((-1 < iVar3) && (pRVar5 != (RGE_Static_Object *)0x0)) {
              TacticalAIGroup::setTarget(pTVar10,iVar3);
              TacticalAIGroup::setTargetType(pTVar10,(int)pRVar5->master_obj->id);
              fVar19 = pRVar5->world_z;
              fVar17 = pRVar5->world_y;
              fVar15 = pRVar5->world_x;
LAB_004f52da:
              TacticalAIGroup::setTargetLocation(pTVar10,fVar15,fVar17,fVar19);
              TacticalAIGroup::setInUse(pTVar10,1);
              goto LAB_004f52ea;
            }
            iVar2 = TacticalAIGroup::commander(pTVar10);
            iVar2 = TribeInformationAIModule::fullyExploredZone(&param_1->md->informationAI,iVar2);
            if (iVar2 == 1) {
              TacticalAIGroup::setAction(pTVar10,8);
              iVar4 = 0;
              iVar3 = 1;
              iVar2 = TacticalAIGroup::action(pTVar10);
              TacticalAIGroup::task(pTVar10,param_1,param_1->md,iVar2,iVar3,iVar4);
              TacticalAIGroup::setInUse(pTVar10,1);
              goto LAB_004f579c;
            }
LAB_004f571d:
            TacticalAIGroup::setAction(pTVar10,1);
          }
        }
        else {
          iVar2 = TacticalAIGroup::type(pTVar10);
          if (iVar2 == 0x6c) {
            iVar2 = TacticalAIGroup::commander(pTVar10);
            pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
            if (pRVar5 == (RGE_Static_Object *)0x0) {
              TacticalAIGroup::setAction(pTVar10,1);
            }
            else {
              iVar2 = TacticalAIGroup::commander(pTVar10);
              pOVar6 = TribeInformationAIModule::objectToTradeWith
                                 (&param_1->md->informationAI,iVar2);
              if (pOVar6 == (ObjectMemory *)0x0) {
                iVar2 = TacticalAIGroup::commander(pTVar10);
                iVar2 = TribeInformationAIModule::fullyExploredZone
                                  (&param_1->md->informationAI,iVar2);
                if (iVar2 != 1) goto LAB_004f571d;
                TacticalAIGroup::setAction(pTVar10,8);
                iVar3 = 1;
                iVar2 = TacticalAIGroup::action(pTVar10);
                TacticalAIGroup::task(pTVar10,param_1,param_1->md,iVar2,iVar3,(int)pOVar6);
                TacticalAIGroup::setInUse(pTVar10,1);
              }
              else {
                uStack_28 = (uint)pOVar6->y;
                uStack_24 = (uint)pOVar6->z;
                iVar2 = (**(code **)(pRVar5->_padding_ + 0x198))
                                  (pOVar6->x,uStack_28,uStack_24,0x3f800000,pOVar6->id,auStack_40,1,
                                   0xffffffff,0xffffffff);
                if (iVar2 != 0) {
                  TacticalAIGroup::setTarget(pTVar10,pOVar6->id);
                  TacticalAIGroup::setTargetType(pTVar10,(int)pOVar6->type);
                  fVar19 = (float)pOVar6->z;
                  uStack_4c = (uint)pOVar6->x;
                  fVar17 = (float)pOVar6->y;
                  fVar15 = (float)uStack_4c;
                  goto LAB_004f52da;
                }
                TacticalAIGroup::setAction(pTVar10,1);
              }
            }
            goto LAB_004f579c;
          }
LAB_004f52ea:
          iVar4 = 0;
LAB_004f5783:
          iVar3 = 1;
          iVar2 = TacticalAIGroup::action(pTVar10);
          pTVar14 = param_1->md;
LAB_004f5794:
          TacticalAIGroup::task(pTVar10,param_1,pTVar14,iVar2,iVar3,iVar4);
        }
      }
      else {
        iVar2 = TacticalAIGroup::action(pTVar10);
        if (iVar2 == 8) {
          iVar3 = 0;
          iVar2 = TacticalAIGroup::type(pTVar10);
          if (iVar2 == 0x6c) {
            iVar2 = TacticalAIGroup::commander(pTVar10);
            pOVar6 = TribeInformationAIModule::objectToTradeWith(&param_1->md->informationAI,iVar2);
            if (pOVar6 != (ObjectMemory *)0x0) {
              iVar3 = 1;
            }
          }
          iVar2 = TacticalAIGroup::type(pTVar10);
          if (iVar2 == 0x6b) {
            iVar2 = TribeTacticalAIModule::numberWaterExplorers(param_1);
            if (iVar2 < 2) {
              iVar2 = TacticalAIGroup::commander(pTVar10);
              pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
              if ((pRVar5 != (RGE_Static_Object *)0x0) &&
                 (pUVar7 = RGE_Static_Object::unitAI(pRVar5), pUVar7 != (UnitAIModule *)0x0)) {
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                iVar2 = UnitAIModule::currentOrder(pUVar7);
                if (iVar2 != 0x2c1) {
                  TacticalAIGroup::setAction(pTVar10,8);
                  iVar20 = 0;
                  iVar4 = 1;
                  iVar2 = TacticalAIGroup::action(pTVar10);
                  TacticalAIGroup::task(pTVar10,param_1,param_1->md,iVar2,iVar4,iVar20);
                  TacticalAIGroup::setInUse(pTVar10,1);
                }
              }
            }
            else {
              iVar4 = 0;
              puVar16 = &uStack_4c;
              piVar18 = (int *)0x0;
              pfVar13 = &fStack_48;
              pfVar12 = &fStack_44;
              fStack_44 = 0.0;
              fStack_48 = 0.0;
              uStack_4c = 0xffffffff;
              iVar2 = TacticalAIGroup::commander(pTVar10);
              iVar2 = TribeInformationAIModule::gameIDOfResourceObject
                                (&param_1->md->informationAI,0,iVar2,pfVar12,pfVar13,(int *)puVar16,
                                 piVar18,iVar4);
              if (iVar2 != -1) {
                iVar3 = 1;
              }
            }
          }
          if (iVar3 != 1) goto LAB_004f5496;
          iVar2 = TacticalAIGroup::commander(pTVar10);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) goto LAB_004f579c;
          TacticalAIGroup::setInUse(pTVar10,0);
          TacticalAIGroup::setAction(pTVar10,1);
          TacticalAIGroup::setTarget(pTVar10,-1);
          pTVar10->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::setTargetType(pTVar10,-1);
          TacticalAIGroup::setTargetLocation(pTVar10,-1.0,-1.0,-1.0);
          TacticalAIGroup::setGatherLocation
                    (pTVar10,pRVar5->world_x,pRVar5->world_y,pRVar5->world_z);
          iVar4 = 0;
          iVar2 = TacticalAIGroup::action(pTVar10);
          pTVar14 = param_1->md;
          goto LAB_004f5794;
        }
LAB_004f5496:
        iVar2 = TacticalAIGroup::action(pTVar10);
        if (iVar2 == 10) {
          iVar2 = TacticalAIGroup::target(pTVar10);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) {
            TacticalAIGroup::setInUse(pTVar10,0);
            TacticalAIGroup::setAction(pTVar10,1);
            TacticalAIGroup::setTarget(pTVar10,-1);
            TacticalAIGroup::setTargetType(pTVar10,-1);
            TacticalAIGroup::setTargetLocation(pTVar10,-1.0,-1.0,-1.0);
            pTVar10->numberObjectsToDestroyValue = 0;
            goto LAB_004f579c;
          }
          iVar2 = TacticalAIGroup::commander(pTVar10);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
          if ((pRVar5 != (RGE_Static_Object *)0x0) &&
             (pUVar7 = RGE_Static_Object::unitAI(pRVar5), pUVar7 != (UnitAIModule *)0x0)) {
            pUVar7 = RGE_Static_Object::unitAI(pRVar5);
            iVar2 = UnitAIModule::currentAction(pUVar7);
            if (iVar2 == -1) {
              TacticalAIGroup::setInUse(pTVar10,0);
              TacticalAIGroup::setAction(pTVar10,1);
              TacticalAIGroup::setTarget(pTVar10,-1);
              pTVar10->numberObjectsToDestroyValue = 0;
              TacticalAIGroup::setTargetType(pTVar10,-1);
              TacticalAIGroup::setTargetLocation(pTVar10,-1.0,-1.0,-1.0);
              pTVar10 = pTVar10->next;
            }
          }
        }
        iVar2 = TacticalAIGroup::action(pTVar10);
        if (iVar2 == 0xb) {
          iVar2 = TacticalAIGroup::target(pTVar10);
          pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
          if (pRVar5 == (RGE_Static_Object *)0x0) {
            TacticalAIGroup::setInUse(pTVar10,0);
            TacticalAIGroup::setAction(pTVar10,1);
            TacticalAIGroup::setTarget(pTVar10,-1);
            pTVar10->numberObjectsToDestroyValue = 0;
            TacticalAIGroup::setTargetType(pTVar10,-1);
            TacticalAIGroup::setTargetLocation(pTVar10,-1.0,-1.0,-1.0);
          }
          else {
            iVar2 = TacticalAIGroup::commander(pTVar10);
            this = (RGE_Action_Object *)
                   MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
            if ((this != (RGE_Action_Object *)0x0) &&
               (pUVar7 = RGE_Static_Object::unitAI((RGE_Static_Object *)this),
               pUVar7 != (UnitAIModule *)0x0)) {
              pUVar7 = RGE_Static_Object::unitAI((RGE_Static_Object *)this);
              iVar2 = UnitAIModule::currentAction(pUVar7);
              if (iVar2 == -1) {
                TacticalAIGroup::setInUse(pTVar10,0);
                TacticalAIGroup::setAction(pTVar10,1);
                TacticalAIGroup::setTarget(pTVar10,-1);
                pTVar10->numberObjectsToDestroyValue = 0;
                TacticalAIGroup::setTargetType(pTVar10,-1);
                TacticalAIGroup::setTargetLocation(pTVar10,-1.0,-1.0,-1.0);
                pTVar10 = pTVar10->next;
              }
              else {
                uVar1 = RGE_Action_Object::have_action(this);
                if (uVar1 != '\0') {
                  pRVar8 = RGE_Action_List::get_action(this->actions);
                  pOVar6 = TribeInformationAIModule::objectToTradeWith
                                     (&param_1->md->informationAI,pRVar8->target2ID);
                  if (pOVar6 != (ObjectMemory *)0x0) {
                    uStack_4c = pOVar6->id;
                    uVar9 = TacticalAIGroup::target(pTVar10);
                    if (uStack_4c != uVar9) {
                      uStack_18 = (uint)pOVar6->z;
                      uStack_1c = (uint)pOVar6->y;
                      iVar2 = (**(code **)(this->_padding_ + 0x198))
                                        (pOVar6->x,uStack_1c,uStack_18,0x3f800000,uStack_4c,
                                         auStack_3c,1,0xffffffff,0xffffffff);
                      if (iVar2 == 0) goto LAB_004f571d;
                      TacticalAIGroup::setTarget(pTVar10,pOVar6->id);
                      TacticalAIGroup::setTargetType(pTVar10,(int)pOVar6->type);
                      uStack_4c = (uint)pOVar6->x;
                      TacticalAIGroup::setTargetLocation
                                (pTVar10,(float)uStack_4c,(float)pOVar6->y,(float)pOVar6->z);
                      TacticalAIGroup::setInUse(pTVar10,1);
                      iVar4 = 1;
                      goto LAB_004f5783;
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_004f579c:
      pTVar10 = pTVar10->next;
    } while (pTVar10 != &param_1->groups);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004f57b5
// Address: 004f57b5
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f57b5(TribeTacticalAIModule *param_1)
{
  ManagedArray<int> *this;
  ManagedArray<int> *this_00;
  char cVar1;
  byte bVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  int *piVar7;
  int iVar8;
  TacticalAIGroup *this_01;
  int iVar9;
  TacticalAIGroup *this_02;
  float10 fVar10;
  int iVar11;
  int iStack_10;
  
  iStack_10 = 0;
  if (0 < (param_1->civilians).numberValue) {
    this = &param_1->civilians;
    do {
      if ((param_1->civilians).maximumSizeValue + -1 < iStack_10) {
        ManagedArray<int>::resize(this,iStack_10 + 1);
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),this->value[iStack_10]
                         );
      if ((pRVar3 != (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
        if ((param_1->civilians).maximumSizeValue + -1 < iStack_10) {
          ManagedArray<int>::resize(this,iStack_10 + 1);
        }
        iVar9 = (param_1->unitsTaskedThisUpdate).numberValue;
        iVar5 = 0;
        if (0 < iVar9) {
          do {
            if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
            if ((param_1->unitsTaskedThisUpdate).value[iVar5] == this->value[iStack_10])
            goto LAB_004f5a80;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar9);
        }
        iVar9 = pRVar3->_padding_;
        fVar10 = (float10)(**(code **)(iVar9 + 0xf4))();
        if ((((fVar10 != (float10)_DAT_00575770) || (pRVar3->attribute_amount_held <= _DAT_005756f0)
             ) || (cVar1 = (**(code **)(iVar9 + 0x130))(), cVar1 != '\0')) ||
           (bVar2 = (**(code **)(iVar9 + 0x134))(), 2 < bVar2)) {
          pUVar4 = RGE_Static_Object::unitAI(pRVar3);
          iVar9 = UnitAIModule::currentOrder(pUVar4);
          if (iVar9 == 700) {
            pUVar4 = RGE_Static_Object::unitAI(pRVar3);
            iVar9 = UnitAIModule::currentTarget(pUVar4);
            pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar9);
            if ((pRVar3 == (RGE_Static_Object *)0x0) || (2 < pRVar3->object_state)) {
              if ((param_1->civilians).maximumSizeValue + -1 < iStack_10) {
                ManagedArray<int>::resize(this,iStack_10 + 1);
              }
              iVar9 = this->value[iStack_10];
              goto LAB_004f5a79;
            }
          }
        }
        else {
          pRVar6 = TribeInformationAIModule::findClosestReturnDropsite
                             (&param_1->md->informationAI,pRVar3);
          if (pRVar6 == (RGE_Static_Object *)0x0) {
            if ((param_1->civilians).maximumSizeValue + -1 < iStack_10) {
              piVar7 = (int *)operator_new(iStack_10 * 4 + 4);
              if (piVar7 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->civilians).maximumSizeValue) {
                  do {
                    if (iStack_10 + 1 <= iVar9) break;
                    iVar5 = iVar9 + 1;
                    piVar7[iVar9] = this->value[iVar9];
                    iVar9 = iVar5;
                  } while (iVar5 < (param_1->civilians).maximumSizeValue);
                }
                operator_delete(this->value);
                this->value = piVar7;
                (param_1->civilians).maximumSizeValue = iStack_10 + 1;
              }
            }
            iVar9 = this->value[iStack_10];
LAB_004f5a79:
            TribeTacticalAIModule::stopUnit(param_1,iVar9,100);
          }
          else {
            (**(code **)(*(int *)param_1->md->_padding_ + 0x40))
                      (pRVar3,pRVar6,pRVar6->world_x,pRVar6->world_y);
            if ((param_1->civilians).maximumSizeValue + -1 < iStack_10) {
              piVar7 = (int *)operator_new(iStack_10 * 4 + 4);
              if (piVar7 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->civilians).maximumSizeValue) {
                  do {
                    if (iStack_10 + 1 <= iVar9) break;
                    iVar5 = iVar9 + 1;
                    piVar7[iVar9] = this->value[iVar9];
                    iVar9 = iVar5;
                  } while (iVar5 < (param_1->civilians).maximumSizeValue);
                }
                operator_delete(this->value);
                this->value = piVar7;
                (param_1->civilians).maximumSizeValue = iStack_10 + 1;
              }
            }
            this_00 = &param_1->unitsTaskedThisUpdate;
            iVar8 = 0;
            iVar9 = this->value[iStack_10];
            iVar5 = (param_1->unitsTaskedThisUpdate).numberValue;
            if (0 < iVar5) {
              do {
                if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar8) break;
                if (this_00->value[iVar8] == iVar9) goto LAB_004f5a80;
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar5);
            }
            if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
              ManagedArray<int>::resize(this_00,iVar5 + 1);
            }
            this_00->value[(param_1->unitsTaskedThisUpdate).numberValue] = iVar9;
            (param_1->unitsTaskedThisUpdate).numberValue =
                 (param_1->unitsTaskedThisUpdate).numberValue + 1;
          }
        }
      }
LAB_004f5a80:
      iStack_10 = iStack_10 + 1;
    } while (iStack_10 < (param_1->civilians).numberValue);
  }
  iVar9 = 0;
  if (0 < (param_1->civilians).numberValue) {
    do {
      if ((param_1->civilians).maximumSizeValue + -1 < iVar9) {
        piVar7 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (param_1->civilians).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar5) break;
              iVar8 = iVar5 + 1;
              piVar7[iVar5] = (param_1->civilians).value[iVar5];
              iVar5 = iVar8;
            } while (iVar8 < (param_1->civilians).maximumSizeValue);
          }
          operator_delete((param_1->civilians).value);
          (param_1->civilians).value = piVar7;
          (param_1->civilians).maximumSizeValue = iVar9 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),
                          (param_1->civilians).value[iVar9]);
      if (((pRVar3 == (RGE_Static_Object *)0x0) || (pRVar3->hp < _DAT_005756f4)) ||
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 == (UnitAIModule *)0x0)) {
        if ((param_1->civilians).maximumSizeValue + -1 < iVar9) {
          piVar7 = (int *)operator_new(iVar9 * 4 + 4);
          if (piVar7 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->civilians).maximumSizeValue) {
              do {
                if (iVar9 + 1 <= iVar5) break;
                iVar8 = iVar5 + 1;
                piVar7[iVar5] = (param_1->civilians).value[iVar5];
                iVar5 = iVar8;
              } while (iVar8 < (param_1->civilians).maximumSizeValue);
            }
            operator_delete((param_1->civilians).value);
            (param_1->civilians).value = piVar7;
            (param_1->civilians).maximumSizeValue = iVar9 + 1;
          }
        }
        TribeTacticalAIModule::removeObject(param_1,(param_1->civilians).value[iVar9]);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (param_1->civilians).numberValue);
  }
  iVar9 = 0;
  if (0 < (param_1->soldiers).numberValue) {
    do {
      if ((param_1->soldiers).maximumSizeValue + -1 < iVar9) {
        piVar7 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (param_1->soldiers).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar5) break;
              iVar8 = iVar5 + 1;
              piVar7[iVar5] = (param_1->soldiers).value[iVar5];
              iVar5 = iVar8;
            } while (iVar8 < (param_1->soldiers).maximumSizeValue);
          }
          operator_delete((param_1->soldiers).value);
          (param_1->soldiers).value = piVar7;
          (param_1->soldiers).maximumSizeValue = iVar9 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),
                          (param_1->soldiers).value[iVar9]);
      if (((pRVar3 == (RGE_Static_Object *)0x0) || (pRVar3->hp < _DAT_005756f4)) ||
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 == (UnitAIModule *)0x0)) {
        if ((param_1->soldiers).maximumSizeValue + -1 < iVar9) {
          piVar7 = (int *)operator_new(iVar9 * 4 + 4);
          if (piVar7 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->soldiers).maximumSizeValue) {
              do {
                if (iVar9 + 1 <= iVar5) break;
                iVar8 = iVar5 + 1;
                piVar7[iVar5] = (param_1->soldiers).value[iVar5];
                iVar5 = iVar8;
              } while (iVar8 < (param_1->soldiers).maximumSizeValue);
            }
            operator_delete((param_1->soldiers).value);
            (param_1->soldiers).value = piVar7;
            (param_1->soldiers).maximumSizeValue = iVar9 + 1;
          }
        }
        TribeTacticalAIModule::removeObject(param_1,(param_1->soldiers).value[iVar9]);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (param_1->soldiers).numberValue);
  }
  iVar9 = 0;
  if (0 < (param_1->boats).numberValue) {
    do {
      if ((param_1->boats).maximumSizeValue + -1 < iVar9) {
        piVar7 = (int *)operator_new(iVar9 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (param_1->boats).maximumSizeValue) {
            do {
              if (iVar9 + 1 <= iVar5) break;
              iVar8 = iVar5 + 1;
              piVar7[iVar5] = (param_1->boats).value[iVar5];
              iVar5 = iVar8;
            } while (iVar8 < (param_1->boats).maximumSizeValue);
          }
          operator_delete((param_1->boats).value);
          (param_1->boats).value = piVar7;
          (param_1->boats).maximumSizeValue = iVar9 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),
                          (param_1->boats).value[iVar9]);
      if (((pRVar3 == (RGE_Static_Object *)0x0) || (pRVar3->hp < _DAT_005756f4)) ||
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 == (UnitAIModule *)0x0)) {
        if ((param_1->boats).maximumSizeValue + -1 < iVar9) {
          piVar7 = (int *)operator_new(iVar9 * 4 + 4);
          if (piVar7 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->boats).maximumSizeValue) {
              do {
                if (iVar9 + 1 <= iVar5) break;
                iVar8 = iVar5 + 1;
                piVar7[iVar5] = (param_1->boats).value[iVar5];
                iVar5 = iVar8;
              } while (iVar8 < (param_1->boats).maximumSizeValue);
            }
            operator_delete((param_1->boats).value);
            (param_1->boats).value = piVar7;
            (param_1->boats).maximumSizeValue = iVar9 + 1;
          }
        }
        TribeTacticalAIModule::removeObject(param_1,(param_1->boats).value[iVar9]);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (param_1->boats).numberValue);
  }
  this_02 = (param_1->groups).next;
  if (this_02 != &param_1->groups) {
    do {
      if (this_02 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar9 = TacticalAIGroup::type(this_02);
      if ((iVar9 == 0x6a) && (iVar9 = TacticalAIGroup::action(this_02), iVar9 == 0xc)) {
        iVar11 = -1;
        iVar8 = -1;
        iVar5 = -1;
        iVar9 = TacticalAIGroup::assistGroupID(this_02);
        this_01 = TribeTacticalAIModule::group(param_1,iVar9,iVar5,iVar8,iVar11);
        iVar9 = TacticalAIGroup::assistGroupID(this_02);
        if ((iVar9 == -1) || (this_01 == (TacticalAIGroup *)0x0)) {
          TacticalAIGroup::setAction(this_02,1);
          TacticalAIGroup::setTarget(this_02,-1);
          TacticalAIGroup::setTargetType(this_02,-1);
          TacticalAIGroup::setTargetLocation(this_02,-1.0,-1.0,-1.0);
          TacticalAIGroup::setGatherLocation(this_02,-1.0,-1.0,-1.0);
          TacticalAIGroup::setRetreatLocation(this_02,-1.0,-1.0,-1.0);
          TacticalAIGroup::setInUse(this_02,0);
          TacticalAIGroup::setWaitCode(this_02,-1);
          this_02->playNumberValue = -1;
        }
        else {
          iVar9 = TacticalAIGroup::commander(this_02);
          pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar9);
          if (((pRVar3 != (RGE_Static_Object *)0x0) &&
              (cVar1 = (**(code **)(pRVar3->_padding_ + 0x134))(), cVar1 == '\x02')) &&
             (iVar9 = TacticalAIGroup::action(this_01), iVar9 == 0x10)) {
            iVar9 = TacticalAIGroup::commander(this_01);
            pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar9);
            if ((pRVar3 != (RGE_Static_Object *)0x0) && (0 < pRVar3->objects->number_of_objects)) {
              TacticalAIGroup::setAction(this_01,0xf);
            }
          }
        }
      }
      this_02 = this_02->next;
    } while (this_02 != &param_1->groups);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004f5fa8
// Address: 004f5fa8
// XREFS: None
void __fastcall FUN_004f5fa8(TribeTacticalAIModule *param_1)
{
  int iVar1;
  
  if (param_1->sn[0xcd] == 1) {
    iVar1 = BuildAIModule::haveBuildList((BuildAIModule *)&param_1->md->buildAI);
    if (((iVar1 != 0) && (param_1->builtFirstStoragePit == 0)) &&
       (param_1->sn[0xa9] <= (param_1->md->informationAI).numberFoundForestTilesValue)) {
      TribeBuildAIModule::insert(&param_1->md->buildAI,0x67,1,0);
      param_1->builtFirstStoragePit = 1;
    }
    if (param_1->sn[0xcd] == 1) {
      iVar1 = BuildAIModule::haveBuildList((BuildAIModule *)&param_1->md->buildAI);
      if ((iVar1 != 0) && (param_1->builtFirstGranary == 0)) {
        if (param_1->builtFirstStoragePit != 1) {
          iVar1 = TribeResourceAIModule::resource(&param_1->md->resourceAI,1);
          if (iVar1 < 0xfa) goto LAB_004f607f;
        }
        if ((param_1->md->informationAI).closestDropsiteValue[0] != -1) {
          TribeBuildAIModule::insert(&param_1->md->buildAI,0x44,1,1);
          param_1->builtFirstGranary = 1;
          goto LAB_004f6093;
        }
      }
    }
  }
LAB_004f607f:
  if (param_1->builtFirstGranary == 1) {
    TribeTacticalAIModule::checkForBuildInsertion(param_1,0x44,1,0);
  }
LAB_004f6093:
  if ((param_1->sn[0xaf] != -1) &&
     ((uint)param_1->sn[0xb0] <= *(uint *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4) / 60000)) {
    TribeBuildAIModule::insert(&param_1->md->buildAI,param_1->sn[0xaf],1,0);
    param_1->sn[0xaf] = -1;
  }
  TribeTacticalAIModule::checkForBuildInsertion(param_1,0x32,1,0);
  TribeTacticalAIModule::checkForBuildInsertion(param_1,0x4f,1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004f60f7
// Address: 004f60f7
// XREFS: None
undefined4 __fastcall FUN_004f60f7(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf8);
}

// --------------------------------------------------

// Function: FUN_004f6107
// Address: 004f6107
// XREFS: None
undefined4 __fastcall FUN_004f6107(int param_1)
{
  return *(undefined4 *)(param_1 + 0x108);
}

// --------------------------------------------------

// Function: FUN_004f6117
// Address: 004f6117
// XREFS: None
undefined4 __fastcall FUN_004f6117(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9cc);
}

// --------------------------------------------------

// Function: FUN_004f6127
// Address: 004f6127
// XREFS: None
undefined4 __fastcall FUN_004f6127(int param_1)
{
  return *(undefined4 *)(param_1 + 0x10c);
}

// --------------------------------------------------

// Function: FUN_004f6137
// Address: 004f6137
// XREFS: None
undefined4 __fastcall FUN_004f6137(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9d0);
}

// --------------------------------------------------

// Function: FUN_004f6147
// Address: 004f6147
// XREFS: None
undefined4 __fastcall FUN_004f6147(int param_1)
{
  return *(undefined4 *)(param_1 + 0x118);
}

// --------------------------------------------------

// Function: FUN_004f6157
// Address: 004f6157
// XREFS: None
void __fastcall FUN_004f6157(TribeTacticalAIModule *param_1)
{
  TribeTacticalAIModule::numberUnitsInGroups(param_1,0x66);
  return;
}

// --------------------------------------------------

// Function: FUN_004f6168
// Address: 004f6168
// XREFS: None
undefined4 __fastcall FUN_004f6168(int param_1)
{
  return *(undefined4 *)(param_1 + 0x138);
}

// --------------------------------------------------

// Function: FUN_004f6177
// Address: 004f6177
// XREFS: None
undefined4 __thiscall FUN_004f6177(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 4)) {
    return *(undefined4 *)(param_1 + 0xd88 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004f619d
// Address: 004f619d
// XREFS: None
int __thiscall FUN_004f619d(int param_1,int param_2)
{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < 4)) {
    iVar1 = ResourceItem::value((ResourceItem *)(param_1 + 0xda8),
                                *(int *)(param_1 + 0xd88 + param_2 * 4));
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_004f61c9
// Address: 004f61c9
// XREFS: None
// [HELPER] s_ERROR_DETASKING_Unit___d_: "ERROR DETASKING Unit #%d!"
void __thiscall FUN_004f61c9(TribeTacticalAIModule *param_1,int param_2)
{
  if (param_2 == -1) {
    AIModule::logCommonHistory
              ((AIModule *)param_1,(char *)param_1,s_ERROR_DETASKING_Unit___d_,0xffffffff);
    return;
  }
  TribeTacticalAIModule::removeFromTaskLists(param_1,param_2);
  TribeTacticalAIModule::stopUnit(param_1,param_2,100);
  return;
}

// --------------------------------------------------

// Function: FUN_004f6208
// Address: 004f6208
// XREFS: None
undefined4 __thiscall FUN_004f6208(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0xe2)) {
    return *(undefined4 *)(param_1 + 0x194 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004f622f
// Address: 004f622f
// XREFS: None
void __thiscall FUN_004f622f(int param_1,int param_2,int param_3)
{
  if ((-1 < param_2) && (param_2 < 0xe2)) {
    *(int *)(param_1 + 0x194 + param_2 * 4) = param_3;
    if ((((param_2 == 0x75) || (((param_2 == 0x78 || (param_2 == 0x77)) || (param_2 == 0x76)))) ||
        (((param_2 == 0x9c || (param_2 == 0x9d)) || (param_2 == 0x9e)))) || (param_2 == 0x9f)) {
      if (param_3 < 0) {
        *(undefined4 *)(param_1 + 0x194 + param_2 * 4) = 0;
      }
      else if (100 < param_3) {
        *(undefined4 *)(param_1 + 0x194 + param_2 * 4) = 100;
      }
    }
    if (param_2 == 0x69) {
      TribeInformationAIModule::setSaveLearnInformation
                ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),param_3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004f62b5
// Address: 004f62b5
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
void __thiscall
FUN_004f62b5(TribeTacticalAIModule *param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  TribeMainDecisionAIModule *pTVar1;
  uint uVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  RGE_Static_Object *pRVar6;
  RGE_Static_Object *pRVar7;
  int iVar8;
  int iVar9;
  UnitAIModule *pUVar10;
  ulong uVar11;
  TacticalAIGroup *this;
  RGE_Static_Object *pRVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  ulong uVar17;
  ObjectMemory *pOVar18;
  float10 fVar19;
  float fVar20;
  int unaff_retaddr;
  uchar uVar21;
  uchar uVar22;
  short sVar23;
  uchar uVar24;
  int iStack_2c;
  XYPoint XStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  XStack_24.x = (int)RGE_Game_World::object
                               ((RGE_Game_World *)param_1->md->aiPlayer->_padding_,param_2);
  if (((param_4 != 0x72) && (param_4 != 0x74)) &&
     ((RGE_Static_Object *)XStack_24.x == (RGE_Static_Object *)0x0)) {
    return;
  }
  pRVar5 = (RGE_Static_Object *)debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x1904);
  if ((param_4 == 0x72) || (param_4 == 0x74)) {
    if (param_4 == 0x72) {
      pOVar18 = TribeInformationAIModule::artifactToCapture(&param_1->md->informationAI,-1);
    }
    else {
      pOVar18 = TribeInformationAIModule::ruinToCapture(&param_1->md->informationAI,-1);
    }
    if (pOVar18 == (ObjectMemory *)0x0) {
      return;
    }
    iVar8 = TribeTacticalAIModule::numberSoldiersWithPriority(param_1,100,-1,1);
    param_4 = 3;
    if (iVar8 < 4) {
      param_4 = iVar8;
    }
    iVar8 = 0;
    param_2 = 0;
    if ((param_1->workingArea).numberValue < 1) {
      return;
    }
    do {
      if (param_4 <= param_2) {
        return;
      }
      if ((param_1->workingArea).maximumSizeValue + -1 < iVar8) {
        piVar13 = (int *)operator_new(iVar8 * 4 + 4);
        if (piVar13 != (int *)0x0) {
          iVar9 = 0;
          if (0 < (param_1->workingArea).maximumSizeValue) {
            do {
              if (iVar8 + 1 <= iVar9) break;
              iVar14 = iVar9 + 1;
              piVar13[iVar9] = (param_1->workingArea).value[iVar9];
              iVar9 = iVar14;
            } while (iVar14 < (param_1->workingArea).maximumSizeValue);
          }
          operator_delete((param_1->workingArea).value);
          (param_1->workingArea).value = piVar13;
          (param_1->workingArea).maximumSizeValue = iVar8 + 1;
        }
      }
      pRVar5 = RGE_Game_World::object
                         ((RGE_Game_World *)param_1->md->aiPlayer->_padding_,
                          (param_1->workingArea).value[iVar8]);
      if (((pRVar5 != (RGE_Static_Object *)0x0) &&
          (pUVar10 = RGE_Static_Object::unitAI(pRVar5), pUVar10 != (UnitAIModule *)0x0)) &&
         (iVar9 = (**(code **)(pRVar5->_padding_ + 0x194))
                            (pOVar18->id,0x40000000,0,1,0xffffffff,0xffffffff), iVar9 != 0)) {
        if ((param_1->workingArea).maximumSizeValue + -1 < iVar8) {
          piVar13 = (int *)operator_new(iVar8 * 4 + 4);
          if (piVar13 != (int *)0x0) {
            iVar9 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (iVar8 + 1 <= iVar9) break;
                iVar14 = iVar9 + 1;
                piVar13[iVar9] = (param_1->workingArea).value[iVar9];
                iVar9 = iVar14;
              } while (iVar14 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar13;
            (param_1->workingArea).maximumSizeValue = iVar8 + 1;
          }
        }
        iVar9 = TribeTacticalAIModule::taskDefender
                          (param_1,(param_1->workingArea).value[iVar8],pOVar18->id,2.0,100);
        if (iVar9 == 1) {
          if ((param_1->workingArea).maximumSizeValue + -1 < iVar8) {
            piVar13 = (int *)operator_new(iVar8 * 4 + 4);
            if (piVar13 != (int *)0x0) {
              iVar9 = 0;
              if (0 < (param_1->workingArea).maximumSizeValue) {
                do {
                  if (iVar8 + 1 <= iVar9) break;
                  iVar14 = iVar9 + 1;
                  piVar13[iVar9] = (param_1->workingArea).value[iVar9];
                  iVar9 = iVar14;
                } while (iVar14 < (param_1->workingArea).maximumSizeValue);
              }
              operator_delete((param_1->workingArea).value);
              (param_1->workingArea).value = piVar13;
              (param_1->workingArea).maximumSizeValue = iVar8 + 1;
            }
          }
          TribeTacticalAIModule::removeFromGroup(param_1,(param_1->workingArea).value[iVar8]);
          param_2 = param_2 + 1;
        }
      }
      iVar8 = iVar8 + 1;
      if ((param_1->workingArea).numberValue <= iVar8) {
        return;
      }
    } while( true );
  }
  if (param_4 != 0x201) {
    return;
  }
  pRVar6 = RGE_Game_World::object((RGE_Game_World *)param_1->md->aiPlayer->_padding_,param_5);
  if (pRVar6 == (RGE_Static_Object *)0x0) {
    return;
  }
  if (pRVar6->owner->id == *(short *)(param_1->md->_padding_ + 0x4a)) {
    return;
  }
  pRVar7 = RGE_Game_World::object((RGE_Game_World *)param_1->md->aiPlayer->_padding_,param_2);
  if (pRVar7 == (RGE_Static_Object *)0x0) {
    return;
  }
  if ((pRVar6->owner->id == 0) &&
     (((param_1->zoomingToNextAge == 0 ||
       ((sVar23 = pRVar6->master_obj->id, sVar23 != 0x7e && (sVar23 != 0x59)))) &&
      (iVar8 = TribeTacticalAIModule::dealWithGAIAAttacker(param_1,pRVar6,pRVar7), iVar8 == 1)))) {
    return;
  }
  if (pRVar6->owner->id != 0) {
    iVar8 = (param_1->civilians).numberValue;
    iVar9 = 0;
    if (0 < iVar8) {
      do {
        if ((param_1->civilians).maximumSizeValue <= iVar9) break;
        if ((param_1->civilians).value[iVar9] == param_2) {
          iVar8 = (param_1->civilianExplorers).numberValue;
          iVar9 = 0;
          if (iVar8 < 1) goto LAB_004f72fe;
          goto LAB_004f72e6;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar8);
    }
LAB_004f63ff:
    pUVar10 = RGE_Static_Object::unitAI(pRVar7);
    if (pUVar10 != (UnitAIModule *)0x0) {
      pUVar10 = RGE_Static_Object::unitAI(pRVar7);
      iVar8 = UnitAIModule::currentOrder(pUVar10);
      if (iVar8 != 0x2c1) {
        iVar8 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c))
        ;
        if (iVar8 == 3) {
          param_1->sn[0x68] = param_1->sn[0x68] + -2;
        }
        else {
          iVar8 = RGE_Game_World::difficultyLevel
                            (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c));
          if (iVar8 != 4) goto LAB_004f6466;
          param_1->sn[0x68] = param_1->sn[0x68] + -1;
        }
        goto LAB_004f6479;
      }
    }
  }
  goto LAB_004f6488;
  while( true ) {
    if ((param_1->civilianExplorers).value[iVar9] == param_2) goto LAB_004f63ff;
    iVar9 = iVar9 + 1;
    if (iVar8 <= iVar9) break;
LAB_004f72e6:
    if ((param_1->civilianExplorers).maximumSizeValue <= iVar9) break;
  }
LAB_004f72fe:
  iVar8 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c));
  if (iVar8 == 3) {
    param_1->sn[0x68] = param_1->sn[0x68] + -2;
  }
  else {
    iVar8 = RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c));
    if (iVar8 == 4) {
      param_1->sn[0x68] = param_1->sn[0x68] + -1;
    }
    else {
LAB_004f6466:
      TribeTacticalAIModule::enableAttack(&param_1->md->tacticalAI,3);
    }
  }
LAB_004f6479:
  TribeTacticalAIModule::checkForAttackResponseBuildInsertions(param_1,(int)pRVar6->owner->id);
LAB_004f6488:
  sVar23 = pRVar6->owner->id;
  param_1->hitsByPlayer[sVar23] = param_1->hitsByPlayer[sVar23] + 1;
  iVar9 = RGE_Player::computerPlayer(pRVar6->owner);
  iVar8 = *(int *)param_1->md->_padding_;
  if (iVar9 == 0) {
    iVar8 = (**(code **)(iVar8 + 0x1c))();
    if (((iVar8 == 1) &&
        (iVar8 = (int)pRVar6->owner->id, param_1->sn[0xdd] <= param_1->hitsByPlayer[iVar8])) &&
       (param_1->sn[0xd7] == 1)) {
LAB_004f657c:
      DiplomacyAIModule::setChangeable(&param_1->md->diplomacyAI,iVar8,'\x01');
      DiplomacyAIModule::setStance(&param_1->md->diplomacyAI,(int)pRVar6->owner->id,0,100);
      DiplomacyAIModule::setRelation(&param_1->md->diplomacyAI,(int)pRVar6->owner->id,3);
      DiplomacyAIModule::setChangeable(&param_1->md->diplomacyAI,(int)pRVar6->owner->id,'\0');
    }
    else {
      DiplomacyAIModule::changeStance
                (&param_1->md->diplomacyAI,(int)pRVar6->owner->id,2,param_1->sn[0xb2]);
      DiplomacyAIModule::changeStance
                (&param_1->md->diplomacyAI,(int)pRVar6->owner->id,0,param_1->sn[0xb2]);
    }
  }
  else {
    iVar8 = (**(code **)(iVar8 + 0x1c))((int)pRVar6->owner->id);
    if ((iVar8 == 1) &&
       (iVar8 = param_1->md->_padding_,
       iVar8 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar8 + 0x3c) + 0x40) +
                                      pRVar6->owner->id * 4) + 0x18))((int)*(short *)(iVar8 + 0x4a))
       , iVar8 == 1)) {
      iVar8 = (int)pRVar6->owner->id;
      goto LAB_004f657c;
    }
  }
  if (((0 < param_1->sn[0x7c]) && (param_1->sn[0x80] == (int)pRVar6->owner->id)) &&
     (param_1->sn[0x85] == 1)) {
    TribeMainDecisionAIModule::revokeTributeAlliance(param_1->md);
  }
  pTVar1 = param_1->md;
  iVar9 = -1;
  iVar8 = pTVar1->_padding_;
  uVar17 = *(ulong *)(*(int *)(iVar8 + 0x3c) + 4);
  uVar22 = *(uchar *)(iVar8 + 0x4a);
  uVar24 = '\0';
  sVar23 = 0;
  uVar21 = (uchar)pRVar6->owner->id;
  uVar3 = __ftol();
  uVar4 = __ftol();
  TribeInformationAIModule::storeAttackMemory
            (&pTVar1->informationAI,'\0',uVar4,uVar3,uVar21,uVar22,sVar23,uVar24,uVar17,iVar9);
  uVar17 = param_1->lastAttackResponseTime;
  iVar8 = *(int *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
  if ((uVar17 != 0) &&
     (uVar11 = TribeTacticalAIModule::attackLimiterTime(param_1,0x30),
     (iVar8 - uVar17) / 1000 < uVar11)) {
    return;
  }
  XStack_24.x = __ftol();
  XStack_24.y = __ftol();
  iVar8 = TribeInformationAIModule::isBoat(&param_1->md->informationAI,pRVar6);
  if (iVar8 == 1) {
    iVar8 = param_1->sn[0x14];
LAB_004f66f3:
    this = TribeTacticalAIModule::readyAndIdleGroup(param_1,0x67,iVar8,&XStack_24);
    if (this != (TacticalAIGroup *)0x0) goto LAB_004f6706;
  }
  else {
    this = TribeTacticalAIModule::readyAndIdleGroup(param_1,100,param_1->sn[0x14],&XStack_24);
    if (this == (TacticalAIGroup *)0x0) {
      iVar8 = param_1->sn[0x14];
      goto LAB_004f66f3;
    }
LAB_004f6706:
    iVar8 = TacticalAIGroup::commander(this);
    pRVar12 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),iVar8);
    if (pRVar12 != (RGE_Static_Object *)0x0) {
      uStack_1c = __ftol();
      uStack_18 = __ftol();
      uStack_14 = __ftol();
      iVar8 = pRVar12->_padding_;
      fVar19 = (float10)(**(code **)(iVar8 + 0x10c))(pRVar6->id,0,1,0xffffffff,0xffffffff);
      iVar8 = (**(code **)(iVar8 + 0x198))(uStack_1c,uStack_18,uStack_14,(float)fVar19);
      if (iVar8 == 1) {
        TacticalAIGroup::setTarget(this,(int)pRVar7);
        TacticalAIGroup::setTargetType(this,(int)pRVar6->master_obj->id);
        TacticalAIGroup::setTargetLocation(this,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
        TacticalAIGroup::setAction(this,2);
        TacticalAIGroup::task(this,param_1,param_1->md,2,1,0);
        param_1->lastAttackResponseTime = *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
        if (param_1->sn[0x47] != 1) {
          return;
        }
        param_1->lastGroupAttackTime = *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
        return;
      }
    }
  }
  pRVar7 = MainDecisionAIModule::object
                     ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  iVar8 = 1000;
  if (pRVar7 != (RGE_Static_Object *)0x0) {
    iVar8 = __ftol();
  }
  if (iVar8 < 0x14) {
    iVar8 = TribeTacticalAIModule::numberWarshipsWithPriority(param_1,100,-1);
    iVar9 = TribeTacticalAIModule::numberSoldiersWithPriority(param_1,100,-1,0);
    iVar8 = iVar8 + iVar9;
    uVar2 = *(uint *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
    if ((((iVar8 == 0) &&
         (iVar9 = TribeInformationAIModule::isBoat(&param_1->md->informationAI,pRVar6), iVar9 == 0))
        && (param_1->sn[0xe1] == 1)) && (uVar2 / 1000 < (uint)param_1->sn[0x68])) {
      iVar8 = 0;
      if (0 < (param_1->civilians).numberValue) {
        do {
          if ((param_1->civilians).maximumSizeValue + -1 < iVar8) {
            piVar13 = (int *)operator_new(iVar8 * 4 + 4);
            if (piVar13 != (int *)0x0) {
              iVar9 = 0;
              if (0 < (param_1->civilians).maximumSizeValue) {
                do {
                  if (iVar8 + 1 <= iVar9) break;
                  iVar14 = iVar9 + 1;
                  piVar13[iVar9] = (param_1->civilians).value[iVar9];
                  iVar9 = iVar14;
                } while (iVar14 < (param_1->civilians).maximumSizeValue);
              }
              operator_delete((param_1->civilians).value);
              (param_1->civilians).value = piVar13;
              (param_1->civilians).maximumSizeValue = iVar8 + 1;
            }
          }
          iVar9 = (param_1->workingArea).numberValue;
          iVar14 = (param_1->civilians).value[iVar8];
          iVar15 = 0;
          if (0 < iVar9) {
            do {
              if ((param_1->workingArea).maximumSizeValue <= iVar15) break;
              if ((param_1->workingArea).value[iVar15] == iVar14) goto LAB_004f6a3f;
              iVar15 = iVar15 + 1;
            } while (iVar15 < iVar9);
          }
          if ((param_1->workingArea).maximumSizeValue + -1 < iVar9) {
            iVar9 = iVar9 + 1;
            piVar13 = (int *)operator_new(iVar9 * 4);
            if (piVar13 != (int *)0x0) {
              iVar15 = 0;
              if (0 < (param_1->workingArea).maximumSizeValue) {
                do {
                  if (iVar9 <= iVar15) break;
                  iVar16 = iVar15 + 1;
                  piVar13[iVar15] = (param_1->workingArea).value[iVar15];
                  iVar15 = iVar16;
                } while (iVar16 < (param_1->workingArea).maximumSizeValue);
              }
              operator_delete((param_1->workingArea).value);
              (param_1->workingArea).value = piVar13;
              (param_1->workingArea).maximumSizeValue = iVar9;
            }
          }
          (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar14;
          (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004f6a3f:
          iVar8 = iVar8 + 1;
        } while (iVar8 < (param_1->civilians).numberValue);
      }
      iVar8 = (param_1->civilians).numberValue;
    }
    iVar9 = __ftol();
  }
  else {
    iVar8 = TribeInformationAIModule::isBoat(&param_1->md->informationAI,pRVar6);
    if (iVar8 == 1) {
      iVar8 = TribeTacticalAIModule::numberWarshipsWithPriority(param_1,param_1->sn[0x14],-1);
    }
    else {
      iVar8 = TribeTacticalAIModule::numberWarshipsWithPriority(param_1,param_1->sn[0x14],-1);
      iVar9 = TribeTacticalAIModule::numberSoldiersWithPriority(param_1,param_1->sn[0x14],-1,0);
      iVar8 = iVar8 + iVar9;
    }
    iVar8 = (param_1->sn[0x13] * iVar8) / 100;
    if (pRVar7 != (RGE_Static_Object *)0x0) {
      iVar9 = __ftol();
      iVar14 = __ftol();
      sVar23 = pRVar6->owner->id;
      goto LAB_004f6b18;
    }
    iVar9 = __ftol();
  }
  iVar14 = __ftol();
  sVar23 = pRVar6->owner->id;
LAB_004f6b18:
  TribeTacticalAIModule::checkForCoopAttack(param_1,(int)sVar23,iVar14,iVar9);
  param_3 = 0;
  param_4 = 0;
  if (0 < (param_1->workingArea).numberValue) {
    while ((param_3 < iVar8 &&
           ((param_4 < 2 ||
            (uVar17 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x1a54),
            uVar17 - iStack_2c < 0xb))))) {
      if ((param_1->workingArea).maximumSizeValue + -1 < param_4) {
        piVar13 = (int *)operator_new(param_4 * 4 + 4);
        if (piVar13 != (int *)0x0) {
          iVar9 = 0;
          if (0 < (param_1->workingArea).maximumSizeValue) {
            do {
              if (param_4 + 1 <= iVar9) break;
              iVar14 = iVar9 + 1;
              piVar13[iVar9] = (param_1->workingArea).value[iVar9];
              iVar9 = iVar14;
            } while (iVar14 < (param_1->workingArea).maximumSizeValue);
          }
          operator_delete((param_1->workingArea).value);
          (param_1->workingArea).value = piVar13;
          (param_1->workingArea).maximumSizeValue = param_4 + 1;
        }
      }
      pRVar7 = RGE_Game_World::object
                         ((RGE_Game_World *)param_1->md->aiPlayer->_padding_,
                          (param_1->workingArea).value[param_4]);
      if ((pRVar7 != (RGE_Static_Object *)0x0) &&
         (pUVar10 = RGE_Static_Object::unitAI(pRVar7), pUVar10 != (UnitAIModule *)0x0)) {
        pUVar10 = RGE_Static_Object::unitAI(pRVar7);
        iVar9 = UnitAIModule::currentAction(pUVar10);
        if (iVar9 == 600) {
          pUVar10 = RGE_Static_Object::unitAI(pRVar7);
          iVar9 = UnitAIModule::currentTarget(pUVar10);
          if (iVar9 == -1) goto LAB_004f6d07;
          pUVar10 = RGE_Static_Object::unitAI(pRVar7);
          iVar9 = UnitAIModule::currentTarget(pUVar10);
          if (iVar9 != pRVar6->id) {
            pUVar10 = RGE_Static_Object::unitAI(pRVar7);
            iVar9 = UnitAIModule::currentTarget(pUVar10);
            pRVar12 = RGE_Game_World::object
                                (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),iVar9);
            if (pRVar12 != (RGE_Static_Object *)0x0) {
              if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
                 (piVar13 = (int *)operator_new(4), piVar13 != (int *)0x0)) {
                iVar9 = 0;
                if (0 < (param_1->playersToAttack).maximumSizeValue) {
                  do {
                    if (0 < iVar9) break;
                    iVar14 = iVar9 + 1;
                    piVar13[iVar9] = (param_1->playersToAttack).value[iVar9];
                    iVar9 = iVar14;
                  } while (iVar14 < (param_1->playersToAttack).maximumSizeValue);
                }
                operator_delete((param_1->playersToAttack).value);
                (param_1->playersToAttack).value = piVar13;
                (param_1->playersToAttack).maximumSizeValue = 1;
              }
              if ((int)pRVar12->owner->id == *(param_1->playersToAttack).value) goto LAB_004f7055;
            }
            goto LAB_004f6d07;
          }
LAB_004f7051:
          param_3 = param_3 + 1;
        }
        else {
LAB_004f6d07:
          if (((param_1->workingArea).maximumSizeValue + -1 < param_4) &&
             (piVar13 = (int *)operator_new(param_4 * 4 + 4), piVar13 != (int *)0x0)) {
            iVar9 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (param_4 + 1 <= iVar9) break;
                iVar14 = iVar9 + 1;
                piVar13[iVar9] = (param_1->workingArea).value[iVar9];
                iVar9 = iVar14;
              } while (iVar14 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar13;
            (param_1->workingArea).maximumSizeValue = param_4 + 1;
          }
          if ((param_1->workingArea).value[param_4] == unaff_retaddr) {
            pUVar10 = RGE_Static_Object::unitAI(pRVar7);
            iVar9 = UnitAIModule::currentOrderPriority(pUVar10);
            if (iVar9 != 100) {
              uStack_1c = __ftol();
              uStack_18 = __ftol();
              uStack_14 = __ftol();
              iVar9 = pRVar7->_padding_;
              fVar19 = (float10)(**(code **)(iVar9 + 0x10c))(pRVar6->id,0,1,0xffffffff,0xffffffff);
              iVar9 = (**(code **)(iVar9 + 0x198))(uStack_1c,uStack_18,uStack_14,(float)fVar19);
              if (iVar9 != 0) {
                if ((param_1->workingArea).maximumSizeValue + -1 < param_4) {
                  piVar13 = (int *)operator_new(param_4 * 4 + 4);
                  if (piVar13 != (int *)0x0) {
                    iVar9 = 0;
                    if (0 < (param_1->workingArea).maximumSizeValue) {
                      do {
                        if (param_4 + 1 <= iVar9) break;
                        iVar14 = iVar9 + 1;
                        piVar13[iVar9] = (param_1->workingArea).value[iVar9];
                        iVar9 = iVar14;
                      } while (iVar14 < (param_1->workingArea).maximumSizeValue);
                    }
                    operator_delete((param_1->workingArea).value);
                    (param_1->workingArea).value = piVar13;
                    (param_1->workingArea).maximumSizeValue = param_4 + 1;
                  }
                }
                iVar9 = TribeTacticalAIModule::taskAttacker
                                  (param_1,(param_1->workingArea).value[param_4],pRVar6->world_x,
                                   pRVar6->world_y,pRVar6->id,(int)pRVar6->owner->id,(Waypoint *)0x0
                                   ,0,-1,0);
                if (iVar9 == 1) {
                  param_1->lastAttackResponseTime =
                       *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
                  if (param_1->sn[0x47] == 1) {
                    param_1->lastGroupAttackTime =
                         *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
                  }
                  goto LAB_004f7051;
                }
              }
            }
          }
          else {
            fVar20 = RGE_Static_Object::distance_to_object(pRVar5,pRVar7);
            iVar9 = TribeTacticalAIModule::calculatePriority(param_1,fVar20);
            if (fVar20 < (float)param_1->sn[0x14]) {
              pUVar10 = RGE_Static_Object::unitAI(pRVar7);
              iVar14 = UnitAIModule::currentOrderPriority(pUVar10);
              if ((iVar14 < iVar9) && (0 < iVar9)) {
                uStack_10 = __ftol();
                uStack_c = __ftol();
                uStack_8 = __ftol();
                iVar9 = pRVar7->_padding_;
                fVar19 = (float10)(**(code **)(iVar9 + 0x10c))(pRVar6->id,0,1,0xffffffff,0xffffffff)
                ;
                iVar9 = (**(code **)(iVar9 + 0x198))(uStack_10,uStack_c,uStack_8,(float)fVar19);
                if (iVar9 != 0) {
                  if ((param_1->workingArea).maximumSizeValue + -1 < param_4) {
                    piVar13 = (int *)operator_new(param_4 * 4 + 4);
                    if (piVar13 != (int *)0x0) {
                      iVar9 = 0;
                      if (0 < (param_1->workingArea).maximumSizeValue) {
                        do {
                          if (param_4 + 1 <= iVar9) break;
                          iVar14 = iVar9 + 1;
                          piVar13[iVar9] = (param_1->workingArea).value[iVar9];
                          iVar9 = iVar14;
                        } while (iVar14 < (param_1->workingArea).maximumSizeValue);
                      }
                      operator_delete((param_1->workingArea).value);
                      (param_1->workingArea).value = piVar13;
                      (param_1->workingArea).maximumSizeValue = param_4 + 1;
                    }
                  }
                  iVar9 = TribeTacticalAIModule::taskAttacker
                                    (param_1,(param_1->workingArea).value[param_4],pRVar6->world_x,
                                     pRVar6->world_y,pRVar6->id,(int)pRVar6->owner->id,
                                     (Waypoint *)0x0,0,-1,0);
                  if (iVar9 == 1) goto LAB_004f7051;
                }
              }
            }
          }
        }
      }
LAB_004f7055:
      param_4 = param_4 + 1;
      if ((param_1->workingArea).numberValue <= param_4) {
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004f734b
// Address: 004f734b
// XREFS: None
int __fastcall FUN_004f734b(int param_1)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int iStack_c;
  int iStack_4;
  
  iStack_c = 0;
  iStack_4 = 0;
  *(undefined4 *)(param_1 + 0xd4c) = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    do {
      if (*(int *)(param_1 + 0x120) + -1 < iStack_4) {
        pvVar1 = operator_new(iStack_4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x120)) {
            do {
              if (iStack_4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x114) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x120));
          }
          operator_delete(*(void **)(param_1 + 0x114));
          *(void **)(param_1 + 0x114) = pvVar1;
          *(int *)(param_1 + 0x120) = iStack_4 + 1;
        }
      }
      iVar2 = iStack_4 * 4;
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0x114) + iVar2));
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == -1) {
          if (*(int *)(param_1 + 0x120) + -1 < iStack_4) {
            pvVar1 = operator_new(iVar2 + 4);
            if (pvVar1 != (void *)0x0) {
              iVar4 = 0;
              if (0 < *(int *)(param_1 + 0x120)) {
                do {
                  if (iStack_4 + 1 <= iVar4) break;
                  iVar4 = iVar4 + 1;
                  *(undefined4 *)((int)pvVar1 + iVar4 * 4 + -4) =
                       *(undefined4 *)(*(int *)(param_1 + 0x114) + -4 + iVar4 * 4);
                } while (iVar4 < *(int *)(param_1 + 0x120));
              }
              operator_delete(*(void **)(param_1 + 0x114));
              *(void **)(param_1 + 0x114) = pvVar1;
              *(int *)(param_1 + 0x120) = iStack_4 + 1;
            }
          }
          iVar5 = 0;
          iVar4 = *(int *)(*(int *)(param_1 + 0x114) + iVar2);
          iVar2 = *(int *)(param_1 + 0xd4c);
          if (0 < iVar2) {
            do {
              if (*(int *)(param_1 + 0xd54) <= iVar5) break;
              if (*(int *)(*(int *)(param_1 + 0xd48) + iVar5 * 4) == iVar4) goto LAB_004f755b;
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar2);
          }
          if (*(int *)(param_1 + 0xd54) + -1 < iVar2) {
            iVar2 = iVar2 + 1;
            pvVar1 = operator_new(iVar2 * 4);
            if (pvVar1 != (void *)0x0) {
              iVar5 = 0;
              if (0 < *(int *)(param_1 + 0xd54)) {
                do {
                  if (iVar2 <= iVar5) break;
                  iVar5 = iVar5 + 1;
                  *(undefined4 *)((int)pvVar1 + iVar5 * 4 + -4) =
                       *(undefined4 *)(*(int *)(param_1 + 0xd48) + -4 + iVar5 * 4);
                } while (iVar5 < *(int *)(param_1 + 0xd54));
              }
              operator_delete(*(void **)(param_1 + 0xd48));
              *(void **)(param_1 + 0xd48) = pvVar1;
              *(int *)(param_1 + 0xd54) = iVar2;
            }
          }
          *(int *)(*(int *)(param_1 + 0xd48) + *(int *)(param_1 + 0xd4c) * 4) = iVar4;
          *(int *)(param_1 + 0xd4c) = *(int *)(param_1 + 0xd4c) + 1;
LAB_004f755b:
          iStack_c = iStack_c + 1;
        }
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < *(int *)(param_1 + 0x118));
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004f7587
// Address: 004f7587
// XREFS: None
int __thiscall FUN_004f7587(int param_1,int param_2,int param_3,int param_4)
{
  ManagedArray<int> *this;
  ManagedArray<int> *this_00;
  RGE_Static_Object *this_01;
  UnitAIModule *pUVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iStack_8;
  int iStack_4;
  
  iStack_8 = 0;
  if (param_4 == 1) {
    *(undefined4 *)(param_1 + 0xd4c) = 0;
  }
  param_4 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    this = (ManagedArray<int> *)(param_1 + 0x114);
    do {
      if (*(int *)(param_1 + 0x120) + -1 < param_4) {
        ManagedArray<int>::resize(this,param_4 + 1);
      }
      this_01 = RGE_Game_World::object
                          (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x3c)
                           ,this->value[param_4]);
      if ((this_01 != (RGE_Static_Object *)0x0) &&
         (pUVar1 = RGE_Static_Object::unitAI(this_01), pUVar1 != (UnitAIModule *)0x0)) {
        if (*(int *)(param_1 + 0x120) + -1 < param_4) {
          ManagedArray<int>::resize(this,param_4 + 1);
        }
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0xd5c)) {
          do {
            if (*(int *)(param_1 + 0xd64) <= iVar2) break;
            if (*(int *)(*(int *)(param_1 + 0xd58) + iVar2 * 4) == this->value[param_4])
            goto LAB_004f7778;
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_1 + 0xd5c));
        }
        if (param_3 < 0) {
          pUVar1 = RGE_Static_Object::unitAI(this_01);
          iVar2 = UnitAIModule::currentAction(pUVar1);
          if (iVar2 != -1) {
            pUVar1 = RGE_Static_Object::unitAI(this_01);
            iVar2 = UnitAIModule::currentOrderPriority(pUVar1);
            if (param_2 <= iVar2) goto LAB_004f7778;
          }
          if (*(int *)(param_1 + 0x120) + -1 < param_4) {
            ManagedArray<int>::resize(this,param_4 + 1);
          }
          iVar2 = *(int *)(param_1 + 0xd4c);
          iVar5 = this->value[param_4];
          iVar3 = 0;
          if (0 < iVar2) {
            do {
              if (*(int *)(param_1 + 0xd54) <= iVar3) break;
              if (*(int *)(*(int *)(param_1 + 0xd48) + iVar3 * 4) == iVar5) goto LAB_004f7770;
              iVar3 = iVar3 + 1;
            } while (iVar3 < iVar2);
          }
LAB_004f7750:
          if (*(int *)(param_1 + 0xd54) + -1 < iVar2) {
            ManagedArray<int>::resize((ManagedArray<int> *)(param_1 + 0xd48),iVar2 + 1);
          }
          ((ManagedArray<int> *)(param_1 + 0xd48))->value[*(int *)(param_1 + 0xd4c)] = iVar5;
          *(int *)(param_1 + 0xd4c) = *(int *)(param_1 + 0xd4c) + 1;
LAB_004f7770:
          iStack_8 = iStack_8 + 1;
        }
        else if (param_3 < 1) {
          pUVar1 = RGE_Static_Object::unitAI(this_01);
          iVar2 = UnitAIModule::currentAction(pUVar1);
          if (iVar2 != -1) {
            pUVar1 = RGE_Static_Object::unitAI(this_01);
            iVar2 = UnitAIModule::currentOrderPriority(pUVar1);
            if (iVar2 == param_2) {
              if (*(int *)(param_1 + 0x120) + -1 < param_4) {
                piVar4 = (int *)operator_new(param_4 * 4 + 4);
                if (piVar4 != (int *)0x0) {
                  iVar2 = 0;
                  if (0 < *(int *)(param_1 + 0x120)) {
                    do {
                      if (param_4 + 1 <= iVar2) break;
                      iVar5 = iVar2 + 1;
                      piVar4[iVar2] = this->value[iVar2];
                      iVar2 = iVar5;
                    } while (iVar5 < *(int *)(param_1 + 0x120));
                  }
                  operator_delete(this->value);
                  this->value = piVar4;
                  *(int *)(param_1 + 0x120) = param_4 + 1;
                }
              }
              this_00 = (ManagedArray<int> *)(param_1 + 0xd48);
              iStack_4 = this->value[param_4];
              iVar2 = ManagedArray<int>::contains(this_00,&iStack_4);
              if (iVar2 != 1) {
                if (*(int *)(param_1 + 0xd54) + -1 < *(int *)(param_1 + 0xd4c)) {
                  ManagedArray<int>::resize(this_00,*(int *)(param_1 + 0xd4c) + 1);
                }
                this_00->value[*(int *)(param_1 + 0xd4c)] = iStack_4;
                *(int *)(param_1 + 0xd4c) = *(int *)(param_1 + 0xd4c) + 1;
              }
              iStack_8 = iStack_8 + 1;
            }
          }
        }
        else {
          pUVar1 = RGE_Static_Object::unitAI(this_01);
          iVar2 = UnitAIModule::currentAction(pUVar1);
          if (iVar2 != -1) {
            pUVar1 = RGE_Static_Object::unitAI(this_01);
            iVar2 = UnitAIModule::currentOrderPriority(pUVar1);
            if (param_2 < iVar2) {
              if (*(int *)(param_1 + 0x120) + -1 < param_4) {
                ManagedArray<int>::resize(this,param_4 + 1);
              }
              iVar5 = this->value[param_4];
              iVar3 = 0;
              iVar2 = *(int *)(param_1 + 0xd4c);
              if (0 < iVar2) {
                do {
                  if (*(int *)(param_1 + 0xd54) <= iVar3) break;
                  if (*(int *)(*(int *)(param_1 + 0xd48) + iVar3 * 4) == iVar5) goto LAB_004f7770;
                  iVar3 = iVar3 + 1;
                } while (iVar3 < iVar2);
              }
              goto LAB_004f7750;
            }
          }
        }
      }
LAB_004f7778:
      param_4 = param_4 + 1;
    } while (param_4 < *(int *)(param_1 + 0x118));
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_004f7866
// Address: 004f7866
// XREFS: None
int __thiscall FUN_004f7866(int param_1,int param_2,int param_3)
{
  ManagedArray<int> *pMVar1;
  ManagedArray<int> *pMVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  UnitAIModule *pUVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  *(undefined4 *)(param_1 + 0xd4c) = 0;
  iStack_10 = 0;
  iStack_c = 0;
  iStack_4 = param_1;
  if (0 < *(int *)(param_1 + 0x148)) {
    pMVar1 = (ManagedArray<int> *)(param_1 + 0x144);
    do {
      if (*(int *)(param_1 + 0x150) + -1 < iStack_c) {
        ManagedArray<int>::resize(pMVar1,iStack_c + 1);
      }
      iStack_8 = iStack_c * 4;
      pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x3c),
                          pMVar1->value[iStack_c]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) &&
         (pUVar5 = RGE_Static_Object::unitAI(pRVar4), pUVar5 != (UnitAIModule *)0x0)) {
        if (*(int *)(param_1 + 0x150) + -1 < iStack_c) {
          ManagedArray<int>::resize(pMVar1,iStack_c + 1);
        }
        iVar6 = 0;
        if (0 < *(int *)(param_1 + 0xd5c)) {
          do {
            if (*(int *)(param_1 + 0xd64) <= iVar6) break;
            if (*(int *)(*(int *)(param_1 + 0xd58) + iVar6 * 4) ==
                *(int *)((int)pMVar1->value + iStack_8)) goto LAB_004f7aed;
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(param_1 + 0xd5c));
        }
        if (param_3 < 0) {
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          iVar6 = UnitAIModule::currentAction(pUVar5);
          if (iVar6 != -1) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
            if (param_2 <= iVar6) goto LAB_004f7aed;
          }
          if (*(int *)(param_1 + 0x150) + -1 < iStack_c) {
            ManagedArray<int>::resize(pMVar1,iStack_c + 1);
          }
          pMVar2 = (ManagedArray<int> *)(param_1 + 0xd48);
          iStack_8 = *(int *)((int)pMVar1->value + iStack_8);
          iVar6 = ManagedArray<int>::contains(pMVar2,&iStack_8);
          if (iVar6 != 1) {
            if (*(int *)(param_1 + 0xd54) + -1 < *(int *)(param_1 + 0xd4c)) {
              ManagedArray<int>::resize(pMVar2,*(int *)(param_1 + 0xd4c) + 1);
            }
            iVar6 = *(int *)(param_1 + 0xd4c);
            piVar7 = pMVar2->value;
LAB_004f7add:
            piVar7[iVar6] = iStack_8;
LAB_004f7ae0:
            *(int *)(param_1 + 0xd4c) = *(int *)(param_1 + 0xd4c) + 1;
          }
LAB_004f7ae3:
          iStack_10 = iStack_10 + 1;
        }
        else if (param_3 < 1) {
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          iVar6 = UnitAIModule::currentAction(pUVar5);
          if (iVar6 != -1) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
            if (iVar6 == param_2) {
              if (*(int *)(param_1 + 0x150) + -1 < iStack_c) {
                ManagedArray<int>::resize(pMVar1,iStack_c + 1);
              }
              pMVar2 = (ManagedArray<int> *)(param_1 + 0xd48);
              iStack_8 = *(int *)((int)pMVar1->value + iStack_8);
              iVar6 = ManagedArray<int>::contains(pMVar2,&iStack_8);
              if (iVar6 == 1) goto LAB_004f7ae3;
              if (*(int *)(param_1 + 0xd54) + -1 < *(int *)(param_1 + 0xd4c)) {
                ManagedArray<int>::resize(pMVar2,*(int *)(param_1 + 0xd4c) + 1);
              }
              iVar6 = *(int *)(param_1 + 0xd4c);
              piVar7 = pMVar2->value;
              goto LAB_004f7add;
            }
          }
        }
        else {
          pUVar5 = RGE_Static_Object::unitAI(pRVar4);
          iVar6 = UnitAIModule::currentAction(pUVar5);
          if (iVar6 != -1) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar6 = UnitAIModule::currentOrderPriority(pUVar5);
            if (param_2 < iVar6) {
              if (*(int *)(param_1 + 0x150) + -1 < iStack_c) {
                ManagedArray<int>::resize(pMVar1,iStack_c + 1);
              }
              pMVar2 = (ManagedArray<int> *)(param_1 + 0xd48);
              iStack_8 = *(int *)((int)pMVar1->value + iStack_8);
              iVar6 = ManagedArray<int>::contains(pMVar2,&iStack_8);
              if (iVar6 == 1) goto LAB_004f7ae3;
              if (*(int *)(param_1 + 0xd54) + -1 < *(int *)(param_1 + 0xd4c)) {
                ManagedArray<int>::resize(pMVar2,*(int *)(param_1 + 0xd4c) + 1);
              }
              pMVar2->value[*(int *)(param_1 + 0xd4c)] = iStack_8;
              goto LAB_004f7ae0;
            }
          }
        }
      }
LAB_004f7aed:
      iStack_c = iStack_c + 1;
    } while (iStack_c < *(int *)(param_1 + 0x148));
  }
  iStack_c = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    pMVar1 = (ManagedArray<int> *)(param_1 + 0x114);
    iVar6 = param_1;
    do {
      if (*(int *)(param_1 + 0x120) + -1 < iStack_c) {
        ManagedArray<int>::resize(pMVar1,iStack_c + 1);
      }
      pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(iVar6 + 0xf0) + 0x1256c) + 0x3c),
                          pMVar1->value[iStack_c]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) &&
         (pUVar5 = RGE_Static_Object::unitAI(pRVar4), pUVar5 != (UnitAIModule *)0x0)) {
        if (*(int *)(param_1 + 0x120) + -1 < iStack_c) {
          ManagedArray<int>::resize(pMVar1,iStack_c + 1);
        }
        piVar7 = (int *)(iVar6 + 0xd5c);
        iVar8 = 0;
        iVar9 = iVar6;
        if (0 < *piVar7) {
          do {
            iVar6 = iVar9;
            if (*(int *)(iVar9 + 0xd64) <= iVar8) break;
            iVar6 = iStack_4;
            if (*(int *)(*(int *)(iVar9 + 0xd58) + iVar8 * 4) == pMVar1->value[iStack_c])
            goto LAB_004f7d5f;
            iVar8 = iVar8 + 1;
            iVar9 = iStack_4;
          } while (iVar8 < *piVar7);
        }
        sVar3 = pRVar4->master_obj->object_group;
        if ((sVar3 == 0x12) || (sVar3 == 0xd)) {
          if (param_3 < 0) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar9 = UnitAIModule::currentAction(pUVar5);
            if (iVar9 != -1) {
              pUVar5 = RGE_Static_Object::unitAI(pRVar4);
              iVar9 = UnitAIModule::currentOrderPriority(pUVar5);
              if (param_2 <= iVar9) goto LAB_004f7d5f;
            }
            if (*(int *)(param_1 + 0x120) + -1 < iStack_c) {
              ManagedArray<int>::resize(pMVar1,iStack_c + 1);
            }
            iVar9 = *(int *)(iVar6 + 0xd4c);
            iVar10 = 0;
            iVar8 = pMVar1->value[iStack_c];
            if (0 < iVar9) {
              do {
                if (*(int *)(iVar6 + 0xd54) <= iVar10) break;
                if (*(int *)(*(int *)(iVar6 + 0xd48) + iVar10 * 4) == iVar8) goto LAB_004f7d55;
                iVar10 = iVar10 + 1;
              } while (iVar10 < iVar9);
            }
LAB_004f7cbd:
            if (*(int *)(iVar6 + 0xd54) + -1 < iVar9) {
              ManagedArray<int>::resize((ManagedArray<int> *)(iVar6 + 0xd48),iVar9 + 1);
            }
            ((ManagedArray<int> *)(iVar6 + 0xd48))->value[*(int *)(iVar6 + 0xd4c)] = iVar8;
LAB_004f7d52:
            *(int *)(iVar6 + 0xd4c) = *(int *)(iVar6 + 0xd4c) + 1;
LAB_004f7d55:
            iStack_10 = iStack_10 + 1;
          }
          else if (param_3 < 1) {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar9 = UnitAIModule::currentAction(pUVar5);
            if (iVar9 != -1) {
              pUVar5 = RGE_Static_Object::unitAI(pRVar4);
              iVar9 = UnitAIModule::currentOrderPriority(pUVar5);
              if (iVar9 == param_2) {
                if (*(int *)(param_1 + 0x120) + -1 < iStack_c) {
                  ManagedArray<int>::resize(pMVar1,iStack_c + 1);
                }
                pMVar2 = (ManagedArray<int> *)(iVar6 + 0xd48);
                iStack_8 = pMVar1->value[iStack_c];
                iVar9 = ManagedArray<int>::contains(pMVar2,&iStack_8);
                if (iVar9 != 1) {
                  if (*(int *)(iVar6 + 0xd54) + -1 < *(int *)(iVar6 + 0xd4c)) {
                    ManagedArray<int>::resize(pMVar2,*(int *)(iVar6 + 0xd4c) + 1);
                  }
                  pMVar2->value[*(int *)(iVar6 + 0xd4c)] = iStack_8;
                  goto LAB_004f7d52;
                }
                goto LAB_004f7d55;
              }
            }
          }
          else {
            pUVar5 = RGE_Static_Object::unitAI(pRVar4);
            iVar9 = UnitAIModule::currentAction(pUVar5);
            if (iVar9 != -1) {
              pUVar5 = RGE_Static_Object::unitAI(pRVar4);
              iVar9 = UnitAIModule::currentOrderPriority(pUVar5);
              if (param_2 < iVar9) {
                if (*(int *)(param_1 + 0x120) + -1 < iStack_c) {
                  ManagedArray<int>::resize(pMVar1,iStack_c + 1);
                }
                iVar9 = *(int *)(iVar6 + 0xd4c);
                iVar10 = 0;
                iVar8 = pMVar1->value[iStack_c];
                if (0 < iVar9) {
                  do {
                    if (*(int *)(iVar6 + 0xd54) <= iVar10) break;
                    if (*(int *)(*(int *)(iVar6 + 0xd48) + iVar10 * 4) == iVar8) goto LAB_004f7d55;
                    iVar10 = iVar10 + 1;
                  } while (iVar10 < iVar9);
                }
                goto LAB_004f7cbd;
              }
            }
          }
        }
      }
LAB_004f7d5f:
      iStack_c = iStack_c + 1;
    } while (iStack_c < *(int *)(iVar6 + 0x118));
  }
  return iStack_10;
}

// --------------------------------------------------

// Function: FUN_004f7d84
// Address: 004f7d84
// XREFS: None
long __fastcall FUN_004f7d84(int param_1)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0x118) < 1) {
    return -1;
  }
  do {
    if (*(int *)(param_1 + 0x120) + -1 < iVar4) {
      pvVar1 = operator_new(iVar4 * 4 + 4);
      if (pvVar1 != (void *)0x0) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x120)) {
          do {
            if (iVar4 + 1 <= iVar2) break;
            iVar2 = iVar2 + 1;
            *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x114) + -4 + iVar2 * 4);
          } while (iVar2 < *(int *)(param_1 + 0x120));
        }
        operator_delete(*(void **)(param_1 + 0x114));
        *(void **)(param_1 + 0x114) = pvVar1;
        *(int *)(param_1 + 0x120) = iVar4 + 1;
      }
    }
    this = RGE_Game_World::object
                     (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c),
                      *(int *)(*(int *)(param_1 + 0x114) + iVar4 * 4));
    if (this != (RGE_Static_Object *)0x0) {
      pUVar3 = RGE_Static_Object::unitAI(this);
      if (pUVar3 != (UnitAIModule *)0x0) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 == -1) {
          return this->id;
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (*(int *)(param_1 + 0x118) <= iVar4) {
      return -1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004f7e77
// Address: 004f7e77
// XREFS: None
long __thiscall FUN_004f7e77(TribeTacticalAIModule *param_1,int param_2)
{
  ManagedArray<int> *pMVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iStack_8;
  
  iVar6 = 0;
  if (0 < (param_1->civilians).numberValue) {
    pMVar1 = &param_1->civilians;
    do {
      if ((param_1->civilians).maximumSizeValue + -1 < iVar6) {
        ManagedArray<int>::resize(pMVar1,iVar6 + 1);
      }
      iVar4 = (param_1->unitsTaskedThisUpdate).numberValue;
      iVar2 = 0;
      if (0 < iVar4) {
        do {
          if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
          if ((param_1->unitsTaskedThisUpdate).value[iVar2] == pMVar1->value[iVar6])
          goto LAB_004f7fc0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar4);
      }
      if ((param_1->civilians).maximumSizeValue + -1 < iVar6) {
        ManagedArray<int>::resize(pMVar1,iVar6 + 1);
      }
      this = RGE_Game_World::object
                       (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),pMVar1->value[iVar6]);
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
        if ((param_1->civilians).maximumSizeValue + -1 < iVar6) {
          ManagedArray<int>::resize(pMVar1,iVar6 + 1);
        }
        iVar4 = TribeTacticalAIModule::isGatherer(param_1,pMVar1->value[iVar6]);
        if (iVar4 == 0) {
          if ((param_1->civilians).maximumSizeValue + -1 < iVar6) {
            ManagedArray<int>::resize(pMVar1,iVar6 + 1);
          }
          iVar4 = 0;
          if (0 < (param_1->civilianExplorers).numberValue) {
            do {
              if ((param_1->civilianExplorers).maximumSizeValue <= iVar4) break;
              if ((param_1->civilianExplorers).value[iVar4] == pMVar1->value[iVar6])
              goto LAB_004f7fc0;
              iVar4 = iVar4 + 1;
            } while (iVar4 < (param_1->civilianExplorers).numberValue);
          }
          pUVar3 = RGE_Static_Object::unitAI(this);
          iVar4 = UnitAIModule::currentAction(pUVar3);
          if (iVar4 == -1) {
            pUVar3 = RGE_Static_Object::unitAI(this);
            iVar4 = UnitAIModule::currentOrder(pUVar3);
            if (iVar4 == -1) goto LAB_004f8180;
          }
        }
      }
LAB_004f7fc0:
      iVar6 = iVar6 + 1;
    } while (iVar6 < (param_1->civilians).numberValue);
  }
  iStack_8 = 0;
  if ((param_1->civilians).numberValue < 1) {
    return -1;
  }
  pMVar1 = &param_1->civilians;
  do {
    if ((param_1->civilians).maximumSizeValue + -1 < iStack_8) {
      ManagedArray<int>::resize(pMVar1,iStack_8 + 1);
    }
    iVar6 = (param_1->unitsTaskedThisUpdate).numberValue;
    iVar4 = 0;
    if (0 < iVar6) {
      do {
        if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar4) break;
        if ((param_1->unitsTaskedThisUpdate).value[iVar4] == pMVar1->value[iStack_8])
        goto LAB_004f8160;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar6);
    }
    if ((param_1->civilians).maximumSizeValue + -1 < iStack_8) {
      ManagedArray<int>::resize(pMVar1,iStack_8 + 1);
    }
    this = RGE_Game_World::object
                     (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),pMVar1->value[iStack_8]);
    if ((this != (RGE_Static_Object *)0x0) &&
       (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) {
      if (param_2 != 0) {
        if (param_2 != 3) {
          if ((param_1->civilians).maximumSizeValue + -1 < iStack_8) {
            ManagedArray<int>::resize(pMVar1,iStack_8 + 1);
          }
          iVar6 = TribeTacticalAIModule::isGatherer(param_1,pMVar1->value[iStack_8]);
          if (iVar6 != 0) goto LAB_004f8160;
        }
        if ((param_2 != 0) && (param_2 != 1)) {
          if ((param_1->civilians).maximumSizeValue + -1 < iStack_8) {
            piVar5 = (int *)operator_new(iStack_8 * 4 + 4);
            if (piVar5 != (int *)0x0) {
              iVar6 = 0;
              if (0 < (param_1->civilians).maximumSizeValue) {
                do {
                  if (iStack_8 + 1 <= iVar6) break;
                  iVar4 = iVar6 + 1;
                  piVar5[iVar6] = pMVar1->value[iVar6];
                  iVar6 = iVar4;
                } while (iVar4 < (param_1->civilians).maximumSizeValue);
              }
              operator_delete(pMVar1->value);
              pMVar1->value = piVar5;
              (param_1->civilians).maximumSizeValue = iStack_8 + 1;
            }
          }
          iVar6 = (param_1->civilianExplorers).numberValue;
          iVar4 = 0;
          if (0 < iVar6) {
            do {
              if ((param_1->civilianExplorers).maximumSizeValue <= iVar4) break;
              if ((param_1->civilianExplorers).value[iVar4] == pMVar1->value[iStack_8])
              goto LAB_004f8160;
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar6);
          }
        }
      }
      pUVar3 = RGE_Static_Object::unitAI(this);
      iVar6 = UnitAIModule::currentAction(pUVar3);
      if (iVar6 == -1) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar6 = UnitAIModule::currentOrder(pUVar3);
        if (iVar6 == -1) {
LAB_004f8180:
          return this->id;
        }
      }
    }
LAB_004f8160:
    iStack_8 = iStack_8 + 1;
    if ((param_1->civilians).numberValue <= iStack_8) {
      return -1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004f819a
// Address: 004f819a
// XREFS: None
long __thiscall FUN_004f819a(TribeTacticalAIModule *param_1,int param_2,int *param_3,int param_4)
{
  ManagedArray<int> *pMVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  float fVar8;
  float fStack_10;
  int iStack_c;
  long lStack_8;
  
  iVar7 = 0;
  lStack_8 = -1;
  fStack_10 = 0.0;
  if (0 < (param_1->civilians).numberValue) {
    pMVar1 = &param_1->civilians;
    do {
      if ((param_1->civilians).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar1,iVar7 + 1);
      }
      iVar5 = (param_1->unitsTaskedThisUpdate).numberValue;
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
          if ((param_1->unitsTaskedThisUpdate).value[iVar2] == pMVar1->value[iVar7])
          goto LAB_004f82f0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
      if ((param_1->civilians).maximumSizeValue + -1 < iVar7) {
        ManagedArray<int>::resize(pMVar1,iVar7 + 1);
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),pMVar1->value[iVar7]);
      if ((pRVar3 != (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
        if ((param_1->civilians).maximumSizeValue + -1 < iVar7) {
          ManagedArray<int>::resize(pMVar1,iVar7 + 1);
        }
        iVar5 = TribeTacticalAIModule::isGatherer(param_1,pMVar1->value[iVar7]);
        if (iVar5 == 0) {
          if ((param_1->civilians).maximumSizeValue + -1 < iVar7) {
            ManagedArray<int>::resize(pMVar1,iVar7 + 1);
          }
          iVar5 = 0;
          if (0 < (param_1->civilianExplorers).numberValue) {
            do {
              if ((param_1->civilianExplorers).maximumSizeValue <= iVar5) break;
              if ((param_1->civilianExplorers).value[iVar5] == pMVar1->value[iVar7])
              goto LAB_004f82f0;
              iVar5 = iVar5 + 1;
            } while (iVar5 < (param_1->civilianExplorers).numberValue);
          }
          pUVar4 = RGE_Static_Object::unitAI(pRVar3);
          iVar5 = UnitAIModule::currentAction(pUVar4);
          if (iVar5 == -1) {
            pUVar4 = RGE_Static_Object::unitAI(pRVar3);
            iVar5 = UnitAIModule::currentOrder(pUVar4);
            if (iVar5 == -1) {
              return pRVar3->id;
            }
          }
        }
      }
LAB_004f82f0:
      iVar7 = iVar7 + 1;
    } while (iVar7 < (param_1->civilians).numberValue);
  }
  iStack_c = 0;
  if (0 < (param_1->civilians).numberValue) {
    pMVar1 = &param_1->civilians;
    do {
      if ((param_1->civilians).maximumSizeValue + -1 < iStack_c) {
        ManagedArray<int>::resize(pMVar1,iStack_c + 1);
      }
      iVar7 = (param_1->unitsTaskedThisUpdate).numberValue;
      iVar5 = 0;
      if (0 < iVar7) {
        do {
          if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
          if ((param_1->unitsTaskedThisUpdate).value[iVar5] == pMVar1->value[iStack_c])
          goto LAB_004f8542;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar7);
      }
      if (((param_1->civilians).maximumSizeValue + -1 < iStack_c) &&
         (piVar6 = (int *)operator_new(iStack_c * 4 + 4), piVar6 != (int *)0x0)) {
        iVar7 = 0;
        if (0 < (param_1->civilians).maximumSizeValue) {
          do {
            if (iStack_c + 1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar6[iVar7] = pMVar1->value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (param_1->civilians).maximumSizeValue);
        }
        operator_delete(pMVar1->value);
        pMVar1->value = piVar6;
        (param_1->civilians).maximumSizeValue = iStack_c + 1;
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),
                          pMVar1->value[iStack_c]);
      if ((pRVar3 != (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
        if (param_2 != 0) {
          if (param_2 != 3) {
            if ((param_1->civilians).maximumSizeValue + -1 < iStack_c) {
              piVar6 = (int *)operator_new(iStack_c * 4 + 4);
              if (piVar6 != (int *)0x0) {
                iVar7 = 0;
                if (0 < (param_1->civilians).maximumSizeValue) {
                  do {
                    if (iStack_c + 1 <= iVar7) break;
                    iVar5 = iVar7 + 1;
                    piVar6[iVar7] = pMVar1->value[iVar7];
                    iVar7 = iVar5;
                  } while (iVar5 < (param_1->civilians).maximumSizeValue);
                }
                operator_delete(pMVar1->value);
                pMVar1->value = piVar6;
                (param_1->civilians).maximumSizeValue = iStack_c + 1;
              }
            }
            iVar7 = TribeTacticalAIModule::isGatherer(param_1,pMVar1->value[iStack_c]);
            if (iVar7 != 0) goto LAB_004f8542;
          }
          if ((param_2 != 0) && (param_2 != 1)) {
            if ((param_1->civilians).maximumSizeValue + -1 < iStack_c) {
              ManagedArray<int>::resize(pMVar1,iStack_c + 1);
            }
            iVar7 = 0;
            if (0 < (param_1->civilianExplorers).numberValue) {
              do {
                if ((param_1->civilianExplorers).maximumSizeValue <= iVar7) break;
                if ((param_1->civilianExplorers).value[iVar7] == pMVar1->value[iStack_c])
                goto LAB_004f8542;
                iVar7 = iVar7 + 1;
              } while (iVar7 < (param_1->civilianExplorers).numberValue);
            }
          }
        }
        pUVar4 = RGE_Static_Object::unitAI(pRVar3);
        iVar7 = UnitAIModule::currentAction(pUVar4);
        if (iVar7 == -1) {
          pUVar4 = RGE_Static_Object::unitAI(pRVar3);
          iVar7 = UnitAIModule::currentOrder(pUVar4);
          if (iVar7 == -1) {
            fVar8 = RGE_Static_Object::distance_to_position
                              (pRVar3,(float)*param_3,(float)param_3[1],pRVar3->world_z);
            if (lStack_8 == -1) {
              lStack_8 = pRVar3->id;
              fStack_10 = fVar8;
            }
            else if (((param_4 == 1) && (fVar8 < fStack_10)) ||
                    ((param_4 == 0 && (fStack_10 < fVar8)))) {
              lStack_8 = pRVar3->id;
              fStack_10 = fVar8;
            }
          }
        }
      }
LAB_004f8542:
      iStack_c = iStack_c + 1;
    } while (iStack_c < (param_1->civilians).numberValue);
  }
  return lStack_8;
}

// --------------------------------------------------

// Function: FUN_004f87ad
// Address: 004f87ad
// XREFS: None
int __thiscall FUN_004f87ad(int param_1,int param_2,int param_3,int param_4)
{
  ManagedArray<int> *this;
  int *piVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    this = (ManagedArray<int> *)(param_1 + 0xf4);
    do {
      if ((*(int *)(param_1 + 0x100) + -1 < iVar7) &&
         (piVar1 = (int *)operator_new(iVar7 * 4 + 4), piVar1 != (int *)0x0)) {
        iVar5 = 0;
        if (0 < *(int *)(param_1 + 0x100)) {
          do {
            if (iVar7 + 1 <= iVar5) break;
            iVar2 = iVar5 + 1;
            piVar1[iVar5] = this->value[iVar5];
            iVar5 = iVar2;
          } while (iVar2 < *(int *)(param_1 + 0x100));
        }
        operator_delete(this->value);
        this->value = piVar1;
        *(int *)(param_1 + 0x100) = iVar7 + 1;
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x3c),
                          this->value[iVar7]);
      if ((pRVar3 == (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0),
         pUVar4 == (UnitAIModule *)0x0)) {
        if (param_2 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentAction(pUVar4);
          if (iVar5 != param_2) goto LAB_004f88a1;
        }
        if (param_3 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentTarget(pUVar4);
          if (iVar5 != param_3) goto LAB_004f88a1;
        }
        if (param_4 == -1) {
LAB_004f8bc0:
          if (*(int *)(param_1 + 0x100) + -1 < iVar7) {
            ManagedArray<int>::resize(this,iVar7 + 1);
          }
          return this->value[iVar7];
        }
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentTargetType(pUVar4);
        if (iVar5 == param_4) goto LAB_004f8bc0;
      }
LAB_004f88a1:
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0xf8));
  }
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    do {
      if (*(int *)(param_1 + 0x120) + -1 < iVar7) {
        pvVar6 = operator_new(iVar7 * 4 + 4);
        if (pvVar6 != (void *)0x0) {
          iVar5 = 0;
          if (0 < *(int *)(param_1 + 0x120)) {
            do {
              if (iVar7 + 1 <= iVar5) break;
              iVar5 = iVar5 + 1;
              *(undefined4 *)((int)pvVar6 + iVar5 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x114) + -4 + iVar5 * 4);
            } while (iVar5 < *(int *)(param_1 + 0x120));
          }
          operator_delete(*(void **)(param_1 + 0x114));
          *(void **)(param_1 + 0x114) = pvVar6;
          *(int *)(param_1 + 0x120) = iVar7 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x3c),
                          *(int *)(*(int *)(param_1 + 0x114) + iVar7 * 4));
      if ((pRVar3 == (RGE_Static_Object *)0x0) &&
         (pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0),
         pUVar4 == (UnitAIModule *)0x0)) {
        if (param_2 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentAction(pUVar4);
          if (iVar5 != param_2) goto LAB_004f89a6;
        }
        if (param_3 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentTarget(pUVar4);
          if (iVar5 != param_3) goto LAB_004f89a6;
        }
        if (param_4 != -1) {
          pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
          iVar5 = UnitAIModule::currentTargetType(pUVar4);
          if (iVar5 != param_4) goto LAB_004f89a6;
        }
        if (iVar7 <= *(int *)(param_1 + 0x120) + -1) goto LAB_004f8a1f;
        iVar5 = iVar7 + 1;
        pvVar6 = operator_new(iVar5 * 4);
        if (pvVar6 == (void *)0x0) goto LAB_004f8a1f;
        iVar2 = 0;
        if (*(int *)(param_1 + 0x120) < 1) goto LAB_004f8a04;
        goto LAB_004f89e7;
      }
LAB_004f89a6:
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x118));
  }
  iVar7 = 0;
  if (*(int *)(param_1 + 0x138) < 1) {
    return -1;
  }
  do {
    if (*(int *)(param_1 + 0x140) + -1 < iVar7) {
      pvVar6 = operator_new(iVar7 * 4 + 4);
      if (pvVar6 != (void *)0x0) {
        iVar5 = 0;
        if (0 < *(int *)(param_1 + 0x140)) {
          do {
            if (iVar7 + 1 <= iVar5) break;
            iVar5 = iVar5 + 1;
            *(undefined4 *)((int)pvVar6 + iVar5 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x134) + -4 + iVar5 * 4);
          } while (iVar5 < *(int *)(param_1 + 0x140));
        }
        operator_delete(*(void **)(param_1 + 0x134));
        *(void **)(param_1 + 0x134) = pvVar6;
        *(int *)(param_1 + 0x140) = iVar7 + 1;
      }
    }
    pRVar3 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x3c),
                        *(int *)(*(int *)(param_1 + 0x134) + iVar7 * 4));
    if ((pRVar3 == (RGE_Static_Object *)0x0) &&
       (pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0), pUVar4 == (UnitAIModule *)0x0)
       ) {
      if (param_2 != -1) {
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentAction(pUVar4);
        if (iVar5 != param_2) goto LAB_004f8b25;
      }
      if (param_3 != -1) {
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentTarget(pUVar4);
        if (iVar5 != param_3) goto LAB_004f8b25;
      }
      if (param_4 != -1) {
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)0x0);
        iVar5 = UnitAIModule::currentTargetType(pUVar4);
        if (iVar5 != param_4) goto LAB_004f8b25;
      }
      if (iVar7 <= *(int *)(param_1 + 0x140) + -1) goto LAB_004f8ba6;
      iVar5 = iVar7 + 1;
      pvVar6 = operator_new(iVar5 * 4);
      if (pvVar6 == (void *)0x0) goto LAB_004f8ba6;
      iVar2 = 0;
      if (*(int *)(param_1 + 0x140) < 1) goto LAB_004f8b8b;
      goto LAB_004f8b6e;
    }
LAB_004f8b25:
    iVar7 = iVar7 + 1;
    if (*(int *)(param_1 + 0x138) <= iVar7) {
      return -1;
    }
  } while( true );
  while( true ) {
    iVar2 = iVar2 + 1;
    *(undefined4 *)((int)pvVar6 + iVar2 * 4 + -4) =
         *(undefined4 *)(*(int *)(param_1 + 0x114) + -4 + iVar2 * 4);
    if (*(int *)(param_1 + 0x120) <= iVar2) break;
LAB_004f89e7:
    if (iVar5 <= iVar2) break;
  }
LAB_004f8a04:
  operator_delete(*(void **)(param_1 + 0x114));
  *(void **)(param_1 + 0x114) = pvVar6;
  *(int *)(param_1 + 0x120) = iVar5;
LAB_004f8a1f:
  return *(int *)(*(int *)(param_1 + 0x114) + iVar7 * 4);
  while( true ) {
    iVar2 = iVar2 + 1;
    *(undefined4 *)((int)pvVar6 + iVar2 * 4 + -4) =
         *(undefined4 *)(*(int *)(param_1 + 0x134) + -4 + iVar2 * 4);
    if (*(int *)(param_1 + 0x140) <= iVar2) break;
LAB_004f8b6e:
    if (iVar5 <= iVar2) break;
  }
LAB_004f8b8b:
  operator_delete(*(void **)(param_1 + 0x134));
  *(void **)(param_1 + 0x134) = pvVar6;
  *(int *)(param_1 + 0x140) = iVar5;
LAB_004f8ba6:
  return *(int *)(*(int *)(param_1 + 0x134) + iVar7 * 4);
}

// --------------------------------------------------

// Function: FUN_004f8bdf
// Address: 004f8bdf
// XREFS: None
undefined4 __thiscall FUN_004f8bdf(int param_1,int param_2,int param_3)
{
  RGE_Static_Object *this;
  UnitAIModule *pUVar1;
  int iVar2;
  
  this = RGE_Game_World::object
                   (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x3c),
                    param_2);
  if (this != (RGE_Static_Object *)0x0) {
    pUVar1 = RGE_Static_Object::unitAI(this);
    if (pUVar1 != (UnitAIModule *)0x0) {
      pUVar1 = RGE_Static_Object::unitAI(this);
      iVar2 = UnitAIModule::currentAction(pUVar1);
      if (iVar2 == param_3) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004f8c2e
// Address: 004f8c2e
// XREFS: None
void FUN_004f8c2e(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004f8c31
// Address: 004f8c31
// XREFS: None
void __fastcall FUN_004f8c31(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iStack_34;
  int aiStack_30 [12];
  
  TribeBuildAIModule::mostNeededResource
            ((TribeBuildAIModule *)(*(int *)(param_1 + 0xf0) + 0x104),
             (ResourceItem *)(param_1 + 0xda8),*(int *)(param_1 + 0x3e0));
  iVar7 = 0;
  aiStack_30[8] = 0xffffffff;
  aiStack_30[4] = 0xffffffff;
  aiStack_30[0] = 0;
  aiStack_30[9] = 0xffffffff;
  aiStack_30[5] = 0xffffffff;
  aiStack_30[1] = 0;
  aiStack_30[10] = 0xffffffff;
  aiStack_30[6] = 0xffffffff;
  aiStack_30[2] = 0;
  piVar5 = (int *)(param_1 + 0xd98);
  aiStack_30[0xb] = 0xffffffff;
  aiStack_30[7] = 0xffffffff;
  aiStack_30[3] = 0;
  do {
    iVar2 = TribeResourceAIModule::resource
                      ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),iVar7);
    iVar3 = ResourceItem::value((ResourceItem *)(param_1 + 0xda8),iVar7);
    iVar7 = iVar7 + 1;
    *piVar5 = iVar2 - iVar3;
    piVar5 = piVar5 + 1;
  } while (iVar7 < 4);
  iStack_34 = 0;
  do {
    iVar2 = -1;
    iVar7 = 0x7fffffff;
    iVar3 = 0;
    do {
      if (iVar3 == 0) {
        iVar4 = TribeResourceAIModule::resource
                          ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),0);
        if (iVar4 < *(int *)(param_1 + 0x48c)) goto LAB_004f8d09;
      }
      else {
LAB_004f8d09:
        if (iVar3 == 1) {
          iVar4 = TribeResourceAIModule::resource
                            ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),1);
          if (*(int *)(param_1 + 0x490) <= iVar4) goto LAB_004f8d95;
        }
        if (iVar3 == 3) {
          iVar4 = TribeResourceAIModule::resource
                            ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),3);
          if (*(int *)(param_1 + 0x498) <= iVar4) goto LAB_004f8d95;
        }
        if (iVar3 == 2) {
          iVar4 = TribeResourceAIModule::resource
                            ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),2);
          if (*(int *)(param_1 + 0x494) <= iVar4) goto LAB_004f8d95;
        }
        iVar4 = ResourceItem::value((ResourceItem *)(param_1 + 0xda8),iVar3);
        if ((0 < iVar4) &&
           (((iVar2 == -1 || (*(int *)(param_1 + 0xd98 + iVar3 * 4) < iVar7)) &&
            (aiStack_30[iVar3] == 0)))) {
          iVar7 = *(int *)(param_1 + 0xd98 + iVar3 * 4);
          iVar2 = iVar3;
        }
      }
LAB_004f8d95:
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    if (iVar2 == -1) {
      iVar3 = 0;
      piVar6 = aiStack_30;
      piVar5 = (int *)(param_1 + 0xd98);
      do {
        if (((iVar2 == -1) || (*piVar5 < iVar7)) && (*piVar6 == 0)) {
          iVar7 = *piVar5;
          iVar2 = iVar3;
        }
        iVar3 = iVar3 + 1;
        piVar6 = piVar6 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar3 < 4);
    }
    aiStack_30[iVar2] = 1;
    *(int *)((int)aiStack_30 + iStack_34 + 0x10) = iVar2;
    *(int *)((int)aiStack_30 + iStack_34 + 0x20) = iVar7;
    iStack_34 = iStack_34 + 4;
    if (0xf < iStack_34) {
      piVar5 = (int *)(param_1 + 0xd88);
      iVar7 = 0;
      do {
        iVar2 = *(int *)((int)aiStack_30 + iVar7 + 0x10);
        uVar1 = *(undefined4 *)((int)aiStack_30 + iVar7 + 0x20);
        *piVar5 = iVar2;
        iVar7 = iVar7 + 4;
        piVar5 = piVar5 + 1;
        *(undefined4 *)(param_1 + 0xd98 + iVar2 * 4) = uVar1;
      } while (iVar7 < 0x10);
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004f8e1e
// Address: 004f8e1e
// XREFS: None
void __fastcall FUN_004f8e1e(TribeTacticalAIModule *param_1)
{
  bool bVar1;
  RGE_Static_Object *this;
  UnitAIModule *pUVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iStack_4;
  
  param_1->actualGathererDistribution[0] = 0;
  param_1->actualGathererDistribution[1] = 0;
  iStack_4 = 0;
  param_1->actualGathererDistribution[2] = 0;
  param_1->actualGathererDistribution[3] = 0;
  if (0 < param_1->numberGatherersValue) {
    piVar7 = &param_1->gatherers[0].data1;
    do {
      this = MainDecisionAIModule::object
                       ((MainDecisionAIModule *)param_1->md,((UnitData *)(piVar7 + -1))->id);
      if ((this != (RGE_Static_Object *)0x0) &&
         (pUVar2 = RGE_Static_Object::unitAI(this), pUVar2 != (UnitAIModule *)0x0)) {
        pUVar2 = RGE_Static_Object::unitAI(this);
        iVar3 = UnitAIModule::currentAction(pUVar2);
        iVar6 = *piVar7;
        pUVar2 = RGE_Static_Object::unitAI(this);
        iVar4 = UnitAIModule::currentTarget(pUVar2);
        piVar7[3] = iVar4;
        if ((iVar3 == 0x261) && (this->master_obj->id == 0x103)) {
          if (iVar6 != 0) {
            iVar4 = (param_1->unitsTaskedThisUpdate).numberValue;
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar5) break;
                if ((param_1->unitsTaskedThisUpdate).value[iVar5] == this->id) goto LAB_004f8f06;
                iVar5 = iVar5 + 1;
              } while (iVar5 < iVar4);
            }
            *piVar7 = 0;
            goto LAB_004f8f06;
          }
        }
        else {
LAB_004f8f06:
          if (iVar6 < 0) goto LAB_004f8f53;
        }
        if (iVar6 < 4) {
          if ((iVar3 == 0x261) || (iVar3 == 0x265)) {
LAB_004f8f4c:
            param_1->actualGathererDistribution[iVar6] =
                 param_1->actualGathererDistribution[iVar6] + 1;
          }
          else {
            iVar3 = (param_1->unitsTaskedThisUpdate).numberValue;
            iVar4 = 0;
            if (0 < iVar3) {
              do {
                if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar4) break;
                if ((param_1->unitsTaskedThisUpdate).value[iVar4] == ((UnitData *)(piVar7 + -1))->id
                   ) goto LAB_004f8f4c;
                iVar4 = iVar4 + 1;
              } while (iVar4 < iVar3);
            }
          }
        }
      }
LAB_004f8f53:
      iStack_4 = iStack_4 + 1;
      piVar7 = piVar7 + 6;
    } while (iStack_4 < param_1->numberGatherersValue);
  }
  piVar7 = param_1->desiredGathererDistribution;
  bVar1 = false;
  *piVar7 = 0;
  param_1->desiredGathererDistribution[1] = 0;
  param_1->desiredGathererDistribution[2] = 0;
  param_1->desiredGathererDistribution[3] = 0;
  iVar6 = TribeTacticalAIModule::inAge(param_1,1);
  if (iVar6 == 0) {
    iVar6 = TribeTacticalAIModule::inAge(param_1,2);
    if (iVar6 == 0) {
      iVar6 = TribeTacticalAIModule::inAge(param_1,3);
      if (iVar6 == 0) goto LAB_004f91ed;
      if (param_1->sn[0xb7] == 1) {
        iVar6 = TribeBuildAIModule::readyToResearch(&param_1->md->buildAI,4,1);
        if (iVar6 == 0) {
          iVar6 = param_1->desiredNumberGatherersValue / 3;
          param_1->zoomingToNextAge = 0;
          bVar1 = true;
          *piVar7 = iVar6;
          param_1->desiredGathererDistribution[3] = iVar6;
          param_1->desiredGathererDistribution[1] = iVar6;
        }
        else {
          iVar3 = 0;
          iVar6 = param_1->desiredNumberGatherersValue / 2;
          *piVar7 = iVar6;
          param_1->desiredGathererDistribution[3] = iVar6;
          if (0 < param_1->numberGatherersValue) {
            piVar7 = &param_1->gatherers[0].data1;
            do {
              iVar6 = *piVar7;
              if (((iVar6 != 0) && (iVar6 != 3)) && (iVar6 != -1)) {
                piVar7[1] = 5;
              }
              iVar3 = iVar3 + 1;
              piVar7 = piVar7 + 6;
            } while (iVar3 < param_1->numberGatherersValue);
          }
          param_1->zoomingToNextAge = 1;
          bVar1 = true;
        }
        goto LAB_004f91ed;
      }
    }
    else if (param_1->sn[0xb6] == 1) {
      iVar6 = TribeBuildAIModule::readyToResearch(&param_1->md->buildAI,3,1);
      if ((iVar6 != 0) &&
         ((iVar6 = TribeResourceAIModule::resource(&param_1->md->resourceAI,1), 0xf0 < iVar6 ||
          ((iVar6 = TribeResourceAIModule::resource(&param_1->md->resourceAI,1), 0x78 < iVar6 &&
           ((param_1->md->informationAI).closestDropsiteValue[0] < 0x14)))))) {
        *piVar7 = param_1->desiredNumberGatherersValue;
        iVar6 = 0;
        if (0 < param_1->numberGatherersValue) {
          piVar7 = &param_1->gatherers[0].data1;
          do {
            if ((*piVar7 != 0) && (*piVar7 != -1)) {
              piVar7[1] = 5;
            }
            iVar6 = iVar6 + 1;
            piVar7 = piVar7 + 6;
          } while (iVar6 < param_1->numberGatherersValue);
        }
        param_1->zoomingToNextAge = 1;
        bVar1 = true;
        goto LAB_004f91ed;
      }
      goto LAB_004f910b;
    }
  }
  else if (param_1->sn[0xb5] == 1) {
    iVar6 = TribeBuildAIModule::readyToResearch(&param_1->md->buildAI,2,1);
    if (((iVar6 != 0) && ((param_1->md->informationAI).closestDropsiteValue[0] != -1)) &&
       ((iVar6 = TribeResourceAIModule::resource(&param_1->md->resourceAI,1), 0x78 < iVar6 ||
        (param_1->builtFirstGranary == 1)))) {
      *piVar7 = param_1->desiredNumberGatherersValue;
      iVar6 = 0;
      if (0 < param_1->numberGatherersValue) {
        piVar7 = &param_1->gatherers[0].data1;
        do {
          if ((*piVar7 != 0) && (*piVar7 != -1)) {
            piVar7[1] = 5;
          }
          iVar6 = iVar6 + 1;
          piVar7 = piVar7 + 6;
        } while (iVar6 < param_1->numberGatherersValue);
      }
      param_1->zoomingToNextAge = 1;
      bVar1 = true;
      goto LAB_004f91ed;
    }
LAB_004f910b:
    param_1->zoomingToNextAge = 0;
    param_1->desiredGathererDistribution[1] = param_1->desiredNumberGatherersValue;
    bVar1 = true;
    goto LAB_004f91ed;
  }
  param_1->zoomingToNextAge = 0;
LAB_004f91ed:
  if (!bVar1) {
    iVar6 = param_1->desiredNumberGatherersValue;
    iVar3 = param_1->sn[0x76];
    param_1->desiredGathererDistribution[2] =
         ((param_1->sn[0x77] + param_1->sn[0x9e]) * iVar6) / 100;
    iVar4 = param_1->sn[0x78];
    param_1->desiredGathererDistribution[3] = ((iVar3 + param_1->sn[0x9f]) * iVar6) / 100;
    iVar3 = param_1->sn[0x75];
    iVar5 = param_1->sn[0x9c];
    param_1->desiredGathererDistribution[1] = ((iVar4 + param_1->sn[0x9d]) * iVar6) / 100;
    param_1->desiredGathererDistribution[0] = ((iVar3 + iVar5) * iVar6) / 100;
  }
  iVar6 = 0;
  piVar7 = param_1->desiredGathererDistribution;
  iVar3 = 4;
  do {
    iVar4 = *piVar7;
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + iVar4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = param_1->desiredNumberGatherersValue;
  iStack_4 = 0;
  iVar4 = 0;
  piVar7 = param_1->resourceDifferenceValue;
  iVar5 = 4;
  do {
    if (*piVar7 < 0) {
      iVar4 = iVar4 - *piVar7;
      iStack_4 = iStack_4 + 1;
    }
    piVar7 = piVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (0 < iStack_4) {
    piVar7 = param_1->neededResourceValue;
    do {
      iVar5 = *piVar7;
      piVar7 = piVar7 + 1;
      iStack_4 = iStack_4 + -1;
      param_1->desiredGathererDistribution[iVar5] =
           param_1->desiredGathererDistribution[iVar5] -
           (param_1->resourceDifferenceValue[iVar5] * (iVar3 - iVar6)) / iVar4;
    } while (iStack_4 != 0);
  }
  iVar6 = 0;
  piVar7 = param_1->desiredGathererDistribution;
  iVar3 = 4;
  do {
    iVar4 = *piVar7;
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + iVar4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar8 = param_1->desiredNumberGatherersValue - iVar6;
  if (0 < (int)uVar8) {
    uVar9 = (int)uVar8 >> 0x1f;
    iVar3 = (int)uVar8 / 2;
    iVar6 = iVar3;
    if (((uVar8 ^ uVar9) - uVar9 & 1 ^ uVar9) - uVar9 == 1) {
      iVar6 = iVar3 + 1;
    }
    iVar4 = param_1->desiredGathererDistribution[1];
    param_1->desiredGathererDistribution[0] = param_1->desiredGathererDistribution[0] + iVar6;
    param_1->desiredGathererDistribution[1] = iVar4 + iVar3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004f9379
// Address: 004f9379
// XREFS: None
undefined4 __thiscall FUN_004f9379(int param_1,undefined4 param_2,undefined4 param_3)
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0xf0) + 0xf0);
  (**(code **)(*piVar1 + 0x30))
            ((int)*(short *)((int)piVar1 + 0x4a),param_2,0x2c2,0xffffffff,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,0xbf800000,1,0,param_3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f93c9
// Address: 004f93c9
// XREFS: None
undefined4 __thiscall
FUN_004f93c9(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0xf0) + 0xf0);
  (**(code **)(*piVar1 + 0x30))
            ((int)*(short *)((int)piVar1 + 0x4a),param_2,0x2c6,0xffffffff,0xffffffff,param_3,param_4
             ,0x3f800000,0x3f800000,1,0,param_5);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f9419
// Address: 004f9419
// XREFS: None
undefined4 __thiscall
FUN_004f9419(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0xf0) + 0xf0);
  (**(code **)(*piVar1 + 0x30))
            ((int)*(short *)((int)piVar1 + 0x4a),param_2,0x2d4,param_3,0xffffffff,param_4,param_5,
             param_6,param_7,1,0,param_8);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f946c
// Address: 004f946c
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_004f946c(TribeTacticalAIModule *param_1,int param_2,int param_3)
{
  RGE_Static_Object *this;
  UnitAIModule *pUVar1;
  int iVar2;
  
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),param_2);
  if ((this == (RGE_Static_Object *)0x0) ||
     (pUVar1 = RGE_Static_Object::unitAI(this), pUVar1 == (UnitAIModule *)0x0)) {
    return false;
  }
  pUVar1 = RGE_Static_Object::unitAI(this);
  iVar2 = UnitAIModule::currentAction(pUVar1);
  if (iVar2 == 600) {
    return true;
  }
  pUVar1 = RGE_Static_Object::unitAI(this);
  iVar2 = UnitAIModule::currentAction(pUVar1);
  if (iVar2 != 0x25a) {
    pUVar1 = RGE_Static_Object::unitAI(this);
    iVar2 = UnitAIModule::currentAction(pUVar1);
    if (iVar2 != 0x26a) {
      pUVar1 = RGE_Static_Object::unitAI(this);
      iVar2 = UnitAIModule::currentAction(pUVar1);
      if (iVar2 == 0x25d) {
        return true;
      }
      if (_DAT_005756f0 < this->attribute_amount_held) {
        return false;
      }
      pUVar1 = RGE_Static_Object::unitAI(this);
      iVar2 = UnitAIModule::currentOrder(pUVar1);
      if (iVar2 == 0x2c6) {
        pUVar1 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentOrderPriority(pUVar1);
        if (iVar2 == 100) {
          return false;
        }
      }
      pUVar1 = RGE_Static_Object::unitAI(this);
      iVar2 = UnitAIModule::currentOrder(pUVar1);
      if (iVar2 == 0x2be) {
        return false;
      }
      iVar2 = 0x2c1;
      pUVar1 = RGE_Static_Object::unitAI(this);
      iVar2 = UnitAIModule::hasOrderOnQueue(pUVar1,iVar2);
      if (iVar2 == 1) {
        return false;
      }
      iVar2 = TribeTacticalAIModule::taskExplorer(param_1,param_2,param_3);
      return iVar2 != 0;
    }
  }
  return true;
}

// --------------------------------------------------

// Function: FUN_004f95aa
// Address: 004f95aa
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004f95aa(TribeTacticalAIModule *param_1,int *param_2,ulong param_3)
{
  UnitData *pUVar1;
  ulong uVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int aiStack_10 [4];
  
  iVar8 = 0;
  iVar4 = param_1->numberGatherersValue;
  aiStack_10[0] = 0;
  aiStack_10[1] = 0;
  aiStack_10[2] = 0;
  aiStack_10[3] = 0;
  if (0 < iVar4) {
    pUVar1 = param_1->gatherers;
    do {
      if ((int *)pUVar1->id == param_2) break;
      iVar8 = iVar8 + 1;
      pUVar1 = pUVar1 + 1;
    } while (iVar8 < iVar4);
  }
  if (iVar4 <= iVar8) {
    return 0;
  }
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x1f5c);
  if (uVar2 - param_1->gatherers[iVar8].lastTaskTime < 5000) {
    return 1;
  }
  param_1->gatherers[iVar8].lastTaskTime = uVar2;
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),(int)param_2);
  if (this == (RGE_Static_Object *)0x0) {
    return 0;
  }
  pUVar3 = RGE_Static_Object::unitAI(this);
  if (pUVar3 == (UnitAIModule *)0x0) {
    return 0;
  }
  pUVar3 = RGE_Static_Object::unitAI(this);
  iVar4 = UnitAIModule::currentAction(pUVar3);
  if (iVar4 == 600) {
    return 1;
  }
  pUVar3 = RGE_Static_Object::unitAI(this);
  iVar4 = UnitAIModule::currentAction(pUVar3);
  if (iVar4 == 0x25a) {
    return 1;
  }
  pUVar3 = RGE_Static_Object::unitAI(this);
  iVar4 = UnitAIModule::currentAction(pUVar3);
  if (iVar4 == 0x26a) {
    return 1;
  }
  if (_DAT_005756f0 < this->attribute_amount_held) {
    return 1;
  }
  iVar4 = TribeTacticalAIModule::isFarmer(param_1,this);
  if (iVar4 == 1) {
    iVar4 = (param_1->civilians).numberValue;
    iVar5 = TribeTacticalAIModule::numberFarmers(param_1);
    iVar6 = TribeResourceAIModule::resource(&param_1->md->resourceAI,0);
    if ((iVar6 < 1000) && (3 < iVar4 - iVar5)) {
      return 1;
    }
  }
  pUVar3 = RGE_Static_Object::unitAI(this);
  iVar4 = UnitAIModule::currentOrder(pUVar3);
  if (iVar4 == 0x2c6) {
    pUVar3 = RGE_Static_Object::unitAI(this);
    iVar4 = UnitAIModule::currentOrderPriority(pUVar3);
    if (iVar4 == 100) {
      return 1;
    }
  }
  pUVar3 = RGE_Static_Object::unitAI(this);
  iVar4 = UnitAIModule::currentOrder(pUVar3);
  if (iVar4 == 0x2be) {
    return 1;
  }
  if (param_1->gatherers[iVar8].data3 < param_1->gatherers[iVar8].data2) {
    pUVar3 = RGE_Static_Object::unitAI(this);
    iVar4 = UnitAIModule::currentAction(pUVar3);
    if (iVar4 != -1) {
      return 1;
    }
    iVar4 = param_1->gatherers[iVar8].data1;
    aiStack_10[iVar4] = 1;
    iVar4 = TribeTacticalAIModule::taskGatherer
                      (param_1,param_1->gatherers[iVar8].id,iVar4,0,param_3,(int *)0x0);
    if (iVar4 == 1) {
      return 1;
    }
    param_1->gatherers[iVar8].data1 = -1;
    param_1->gatherers[iVar8].data2 = -1;
    param_1->gatherers[iVar8].data3 = -1;
  }
  param_2 = aiStack_10;
  piVar7 = param_1->desiredGathererDistribution;
  iVar4 = 0;
  iVar5 = 0;
  do {
    if ((*param_2 != 1) && (piVar7[-4] < *piVar7)) {
      if (param_1->gatherers[iVar8].data1 == iVar5) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == 0x265) {
          return 1;
        }
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar4 = UnitAIModule::currentAction(pUVar3);
        if (iVar4 == 0x261) {
          return 1;
        }
      }
      iVar4 = param_1->gatherers[iVar8].id;
      *param_2 = 1;
      iVar4 = TribeTacticalAIModule::taskGatherer(param_1,iVar4,iVar5,0,param_3,(int *)0x0);
      if (iVar4 == 1) {
        return 1;
      }
    }
    iVar5 = iVar5 + 1;
    piVar7 = piVar7 + 1;
    param_2 = param_2 + 1;
  } while (iVar5 < 4);
  iVar5 = TribeTacticalAIModule::inAge(param_1,1);
  if (((iVar5 == 0) || (param_1->sn[0xb5] != 1)) &&
     ((iVar5 = TribeTacticalAIModule::inAge(param_1,2), iVar5 == 0 ||
      ((param_1->sn[0xb6] != 1 || (aiStack_10[0] != 0)))))) {
    iVar5 = TribeTacticalAIModule::inAge(param_1,3);
    if ((iVar5 == 0) || (param_1->sn[0xb7] != 1)) goto LAB_004f9964;
    if (aiStack_10[0] == 0) {
      iVar4 = TribeTacticalAIModule::taskGatherer
                        (param_1,param_1->gatherers[iVar8].id,0,1,param_3,(int *)0x0);
      aiStack_10[0] = 1;
    }
    if (aiStack_10[3] != 0) goto LAB_004f9964;
    if (iVar4 != 0) {
      return 1;
    }
    iVar4 = param_1->gatherers[iVar8].id;
    iVar5 = 3;
    aiStack_10[3] = 1;
  }
  else {
    iVar4 = param_1->gatherers[iVar8].id;
    iVar5 = 0;
    aiStack_10[0] = 1;
  }
  iVar4 = TribeTacticalAIModule::taskGatherer(param_1,iVar4,iVar5,1,param_3,(int *)0x0);
LAB_004f9964:
  if (iVar4 == 0) {
    TribeTacticalAIModule::taskGatherer
              (param_1,param_1->gatherers[iVar8].id,-1,1,param_3,aiStack_10);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f99aa
// Address: 004f99aa
// XREFS: None
undefined4 __thiscall
FUN_004f99aa(TribeTacticalAIModule *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,int param_7,int param_8)
{
  int iVar1;
  uchar uVar2;
  uchar uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if ((param_7 != 0) && (0 < param_8)) {
    do {
      uVar2 = __ftol();
      uVar3 = __ftol();
      TribeTacticalAIModule::addWaypoint(param_1,param_2,uVar3,uVar2);
      param_8 = param_8 + -1;
    } while (param_8 != 0);
  }
  iVar1 = (param_1->unitsTaskedThisUpdate).numberValue;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar4) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar4] == param_2) goto LAB_004f9a97;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar5 = (int *)operator_new(iVar1 * 4);
    if (piVar5 != (int *)0x0) {
      iVar4 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar4) break;
          iVar6 = iVar4 + 1;
          piVar5[iVar4] = (param_1->unitsTaskedThisUpdate).value[iVar4];
          iVar4 = iVar6;
        } while (iVar6 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar5;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = param_2;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004f9a97:
  (**(code **)(*(int *)param_1->md->_padding_ + 0x4c))(param_2,param_3,param_4,param_5,param_6);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f9ac9
// Address: 004f9ac9
// XREFS: None
undefined4 __thiscall
FUN_004f9ac9(TribeTacticalAIModule *param_1,int param_2,BuildItem *param_3,ConstructionItem *param_4
            ,ulong param_5)
{
  RGE_Static_Object *this;
  UnitAIModule *pUVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  BaseItem *unaff_EDI;
  float fVar9;
  float fVar10;
  int iVar11;
  BuildItem *this_00;
  BuildItem *pBVar12;
  XYPoint XStack_8;
  
  if (((param_3 != (BuildItem *)0x0) ||
      (param_3 = TribeBuildAIModule::nextBuildableItem(&param_1->md->buildAI,0),
      param_3 != (BuildItem *)0x0)) &&
     ((param_4 != (ConstructionItem *)0x0 ||
      (param_4 = TribeConstructionAIModule::placeStructure
                           (&param_1->md->constructionAI,param_3,param_2,
                            &param_1->placementStateValue,param_5),
      param_4 != (ConstructionItem *)0x0)))) {
    if (param_2 == -1) {
      BaseItem::x((BaseItem *)param_4);
      XStack_8.x = __ftol();
      BaseItem::y((BaseItem *)param_4);
      XStack_8.y = __ftol();
      param_2 = TribeTacticalAIModule::civilian(param_1,&XStack_8,1,0x2be,0x2ce,700,0);
    }
    this = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),param_2);
    if ((this == (RGE_Static_Object *)0x0) ||
       (pUVar1 = RGE_Static_Object::unitAI(this), pUVar1 == (UnitAIModule *)0x0)) {
      if (param_4 != (ConstructionItem *)0x0) {
        (**(code **)param_4->_padding_)(1);
      }
    }
    else {
      BaseItem::x((BaseItem *)param_4);
      uVar2 = __ftol();
      BaseItem::y((BaseItem *)param_4);
      uVar3 = __ftol();
      uVar4 = __ftol();
      this_00 = (BuildItem *)0xffffffff;
      iVar11 = -1;
      iVar5 = (**(code **)(this->_padding_ + 0x198))(uVar2,uVar3,uVar4,0x40000000,0xffffffff,0,1);
      if (iVar5 != 0) {
        pBVar12 = this_00;
        BuildItem::setInProgress(this_00,1);
        BuildItem::setBuilt(this_00,0);
        iVar5 = (param_1->civilianExplorers).maximumSizeValue;
        iVar6 = 0;
        if (0 < iVar5) {
          piVar7 = (param_1->civilianExplorers).value;
          do {
            if (*piVar7 == iVar11) break;
            iVar6 = iVar6 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar6 < iVar5);
        }
        if (iVar6 < iVar5) {
          if (iVar6 < iVar5 + -1) {
            do {
              piVar7 = (param_1->civilianExplorers).value;
              iVar5 = iVar6 + 1;
              piVar7[iVar6] = piVar7[iVar5];
              iVar6 = iVar5;
            } while (iVar5 < (param_1->civilianExplorers).maximumSizeValue + -1);
          }
          iVar5 = (param_1->civilianExplorers).numberValue + -1;
          (param_1->civilianExplorers).numberValue = iVar5;
          if (iVar5 < 0) {
            (param_1->civilianExplorers).numberValue = 0;
          }
        }
        iVar5 = (param_1->unitsTaskedThisUpdate).numberValue;
        iVar6 = 0;
        if (0 < iVar5) {
          do {
            if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar6) break;
            if ((param_1->unitsTaskedThisUpdate).value[iVar6] == iVar11) goto LAB_004f9d52;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar5);
        }
        this_00 = pBVar12;
        if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
          iVar5 = iVar5 + 1;
          piVar7 = (int *)operator_new(iVar5 * 4);
          this_00 = pBVar12;
          if (piVar7 != (int *)0x0) {
            iVar6 = 0;
            if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
              do {
                if (iVar5 <= iVar6) break;
                iVar8 = iVar6 + 1;
                piVar7[iVar6] = (param_1->unitsTaskedThisUpdate).value[iVar6];
                iVar6 = iVar8;
              } while (iVar8 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
            }
            operator_delete((param_1->unitsTaskedThisUpdate).value);
            (param_1->unitsTaskedThisUpdate).value = piVar7;
            (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
            this_00 = pBVar12;
          }
        }
        (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] =
             iVar11;
        (param_1->unitsTaskedThisUpdate).numberValue =
             (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004f9d52:
        iVar5 = BaseItem::typeID(unaff_EDI);
        if (iVar5 == 0x114) {
          param_1->wonderInProgressValue = 1;
        }
        iVar5 = param_1->md->aiPlayer->_padding_;
        iVar6 = BaseItem::uniqueID((BaseItem *)this_00);
        fVar9 = BaseItem::y(unaff_EDI);
        fVar10 = BaseItem::x(unaff_EDI);
        iVar8 = BaseItem::typeID(unaff_EDI);
        (**(code **)(iVar5 + 0xfc))(iVar11,iVar8,fVar10,fVar9,iVar6);
        if (unaff_EDI != (BaseItem *)0x0) {
          (**(code **)unaff_EDI->_padding_)(1);
        }
        return 1;
      }
      if (unaff_EDI != (BaseItem *)0x0) {
        (**(code **)unaff_EDI->_padding_)(1);
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004f9df1
// Address: 004f9df1
// XREFS: None
undefined4 __thiscall
FUN_004f9df1(TribeTacticalAIModule *param_1,int param_2,RGE_Static_Object *param_3)
{
  RGE_Static_Object *pRVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  float fVar9;
  RGE_Static_Object *pRVar10;
  int iVar11;
  
  pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),param_2);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  uVar2 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  if (param_3 == (RGE_Static_Object *)0x0) {
    iVar11 = 1;
    pRVar10 = (RGE_Static_Object *)0xffffffff;
    iVar5 = (**(code **)(pRVar1->_padding_ + 0x198))
                      (uVar2,uVar3,uVar4,0x3f800000,0xffffffff,0,1,0xffffffff,0xffffffff);
    if (iVar5 == 0) {
      return 0;
    }
  }
  else {
    pRVar10 = (RGE_Static_Object *)param_3->id;
    iVar11 = 1;
    iVar5 = (**(code **)(pRVar1->_padding_ + 0x198))
                      (uVar2,uVar3,uVar4,0x3f800000,pRVar10,0,1,0xffffffff,0xffffffff);
    if (iVar5 == 0) {
      if (param_3->master_obj->id != 0x114) {
        TribeTacticalAIModule::deleteUnit(param_1,param_3->id);
      }
      return 0;
    }
  }
  iVar5 = (param_1->unitsTaskedThisUpdate).numberValue;
  iVar6 = 0;
  if (0 < iVar5) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar6) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar6] == iVar11) goto LAB_004f9f95;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
    iVar5 = iVar5 + 1;
    piVar7 = (int *)operator_new(iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      iVar6 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar5 <= iVar6) break;
          iVar8 = iVar6 + 1;
          piVar7[iVar6] = (param_1->unitsTaskedThisUpdate).value[iVar6];
          iVar6 = iVar8;
        } while (iVar8 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar7;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = iVar11;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004f9f95:
  fVar9 = RGE_Static_Object::distance_to_object(param_3,pRVar10);
  iVar5 = TribeTacticalAIModule::calculatePriority(param_1,fVar9);
  piVar7 = (int *)param_1->md->_padding_;
  iVar6 = (int)*(short *)((int)piVar7 + 0x4a);
  (**(code **)(*piVar7 + 0x30))
            (iVar6,iVar11,0x2be,param_3->id,iVar6,param_3->world_x,param_3->world_y,param_3->world_z
             ,0x3f800000,1,1,iVar5);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004f9ff9
// Address: 004f9ff9
// XREFS: None
undefined4 __thiscall
FUN_004f9ff9(TribeTacticalAIModule *param_1,int param_2,RGE_Static_Object *param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_EDI;
  float fVar6;
  RGE_Static_Object *pRVar7;
  
  pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),param_2);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  pRVar7 = (RGE_Static_Object *)0xffffffff;
  iVar2 = (**(code **)(pRVar1->_padding_ + 0x194))(param_3->id,0x3f800000,0,1,0xffffffff,0xffffffff)
  ;
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = (param_1->unitsTaskedThisUpdate).numberValue;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar3) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar3] == param_2) goto LAB_004fa112;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar2) {
    iVar2 = iVar2 + 1;
    pRVar1 = pRVar7;
    piVar4 = (int *)operator_new(iVar2 * 4);
    param_2 = unaff_EDI;
    if (piVar4 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar2 <= iVar3) break;
          iVar5 = iVar3 + 1;
          piVar4[iVar3] = (param_1->unitsTaskedThisUpdate).value[iVar3];
          iVar3 = iVar5;
        } while (iVar5 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar4;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar2;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = param_2;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fa112:
  fVar6 = RGE_Static_Object::distance_to_object(param_3,pRVar1);
  iVar2 = TribeTacticalAIModule::calculatePriority(param_1,fVar6);
  piVar4 = (int *)param_1->md->_padding_;
  iVar3 = (int)*(short *)((int)piVar4 + 0x4a);
  (**(code **)(*piVar4 + 0x30))
            (iVar3,param_2,0x2ce,param_3->id,iVar3,param_3->world_x,param_3->world_y,
             param_3->world_z,0x3f800000,1,0,iVar2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fa16e
// Address: 004fa16e
// XREFS: None
undefined4 __thiscall
FUN_004fa16e(TribeTacticalAIModule *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
            int *param_6)
{
  short sVar1;
  TribeMainDecisionAIModule *pTVar2;
  RGE_Static_Object *pRVar3;
  UnitData *pUVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  ManagedArray<int> *pMVar9;
  int iVar10;
  int iStack_30;
  RGE_Static_Object *pRStack_2c;
  float fStack_28;
  float fStack_24;
  int iStack_20;
  UnitData *pUStack_1c;
  int iStack_18;
  int aiStack_14 [5];
  
  pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_2);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  pRStack_2c = pRVar3;
  pUVar4 = TribeTacticalAIModule::gatherer(param_1,param_2);
  if ((pUVar4 != (UnitData *)0x0) && (pUVar4->data3 < pUVar4->data2)) {
    param_3 = pUVar4->data1;
  }
  iVar10 = -1;
  fStack_24 = 0.0;
  fStack_28 = 0.0;
  iStack_30 = 0;
  if (param_3 == -1) {
    iStack_30 = 0;
    piVar7 = param_1->neededResourceValue;
    do {
      param_3 = *piVar7;
      if ((param_6 == (int *)0x0) || (*(int *)((int)param_6 + param_3 * 4) != 1)) {
        iStack_20 = -1;
        iVar10 = TribeInformationAIModule::gameIDOfResourceObject
                           (&param_1->md->informationAI,param_3,param_2,&fStack_24,&fStack_28,
                            &iStack_20,aiStack_14,0);
        if (iVar10 != -1) {
          if (iStack_20 == -1) {
            (**(code **)(pRStack_2c->_padding_ + 0x194))(iVar10);
          }
          else {
            (**(code **)(pRStack_2c->_padding_ + 0x19c))
                      (iVar10,iStack_20,0x3f800000,0,1,0xffffffff,0xffffffff);
          }
          break;
        }
      }
      piVar7 = piVar7 + 1;
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < 4);
    if (iVar10 == -1) {
      return 0;
    }
  }
  else {
    pUStack_1c = (UnitData *)0x0;
    param_6 = aiStack_14;
    do {
      iStack_20 = -1;
      iVar10 = TribeInformationAIModule::gameIDOfResourceObject
                         (&param_1->md->informationAI,param_3,param_2,&fStack_24,&fStack_28,
                          &iStack_20,aiStack_14,iStack_30);
      if (iVar10 == -1) {
        return 0;
      }
      if (iStack_20 == -1) {
        iVar5 = (**(code **)(pRVar3->_padding_ + 0x194))(iVar10);
      }
      else {
        iVar5 = (**(code **)(pRVar3->_padding_ + 0x19c))
                          (iVar10,iStack_20,0x3f800000,0,1,0xffffffff,0xffffffff);
      }
      if (iVar5 != 0) break;
      if (param_3 == 0) {
        iVar5 = 2;
      }
      else {
        iVar5 = 0xf;
      }
      TribeInformationAIModule::setResourceObjectValid
                (&param_1->md->informationAI,param_3,iVar10,iVar5);
      iStack_30 = iStack_30 + 1;
      *param_6 = iVar10;
      param_6 = param_6 + 1;
      iVar10 = -1;
      pUStack_1c = (UnitData *)((int)&pUStack_1c->id + 1);
    } while ((int)pUStack_1c < 3);
    if (iVar10 < 0) {
      return 0;
    }
  }
  pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar10);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  if (param_1->sn[0xcd] != 1) goto LAB_004fa558;
  if ((param_3 == 0) && (param_1->builtFirstGranary == 1)) {
    if (param_1->builtFirstStoragePit != 1) goto LAB_004fa558;
    if (pRVar3->master_obj->id != 0x3b) {
      sVar1 = pRVar3->master_obj->object_group;
      if (((sVar1 == 0x1f) || (sVar1 == 5)) || (sVar1 == 0x21)) goto LAB_004fa558;
      iStack_30 = 0;
      pUStack_1c = (UnitData *)0x0;
      iVar5 = TribeTacticalAIModule::numberAvailableStoragePits
                        (param_1,&iStack_30,(int *)&pUStack_1c,0);
      if ((pUStack_1c != (UnitData *)0x0) || (iVar5 < 1)) goto LAB_004fa558;
      RGE_Static_Object::distance_to_object(pRStack_2c,pRVar3);
      iVar5 = __ftol();
      if (iVar5 < 0x10) goto joined_r0x004fa53f;
      goto LAB_004fa541;
    }
    iStack_30 = 0;
    pUStack_1c = (UnitData *)0x0;
    iVar5 = TribeTacticalAIModule::numberAvailableGranaries(param_1,&iStack_30,(int *)&pUStack_1c);
    if ((pUStack_1c != (UnitData *)0x0) || (iVar5 < 1)) goto LAB_004fa558;
    iStack_18 = param_1->sn[0xa3];
    RGE_Static_Object::distance_to_object(pRStack_2c,pRVar3);
    iVar5 = __ftol();
    if ((iVar5 <= iStack_18) ||
       (pTVar2 = param_1->md, (pTVar2->informationAI).closestDropsiteValue[0] == -1))
    goto LAB_004fa558;
    iVar5 = __ftol();
    iVar6 = __ftol();
    iVar5 = TribeInformationAIModule::acceptablePotentialDropsiteArea
                      (&pTVar2->informationAI,iVar6,iVar5);
    if (iVar5 != 1) goto LAB_004fa558;
    iVar5 = 0x44;
  }
  else {
    if ((param_1->builtFirstStoragePit != 1) || (param_1->builtFirstGranary != 1))
    goto LAB_004fa558;
    iStack_30 = 0;
    pUStack_1c = (UnitData *)0x0;
    iVar5 = TribeTacticalAIModule::numberAvailableStoragePits
                      (param_1,&iStack_30,(int *)&pUStack_1c,param_3);
    if ((pUStack_1c != (UnitData *)0x0) || (iVar5 < 1)) goto LAB_004fa558;
    iStack_18 = param_1->sn[pRVar3->attribute_type_held + 0xa3];
    RGE_Static_Object::distance_to_object(pRStack_2c,pRVar3);
    iVar5 = __ftol();
    if (iVar5 <= iStack_18) {
joined_r0x004fa53f:
      if (iStack_30 != 0) goto LAB_004fa558;
    }
LAB_004fa541:
    iVar5 = 0x67;
  }
  TribeBuildAIModule::insert(&param_1->md->buildAI,iVar5,1,-1);
LAB_004fa558:
  iVar5 = (param_1->civilianExplorers).maximumSizeValue;
  iVar6 = 0;
  if (0 < iVar5) {
    piVar7 = (param_1->civilianExplorers).value;
    do {
      if (*piVar7 == param_2) break;
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar6 < iVar5);
  }
  if (iVar6 < iVar5) {
    if (iVar6 < iVar5 + -1) {
      do {
        piVar7 = (param_1->civilianExplorers).value;
        iVar5 = iVar6 + 1;
        piVar7[iVar6] = piVar7[iVar5];
        iVar6 = iVar5;
      } while (iVar5 < (param_1->civilianExplorers).maximumSizeValue + -1);
    }
    iVar5 = (param_1->civilianExplorers).numberValue + -1;
    (param_1->civilianExplorers).numberValue = iVar5;
    if (iVar5 < 0) {
      (param_1->civilianExplorers).numberValue = 0;
    }
  }
  pUStack_1c = TribeTacticalAIModule::addGatherer(param_1,param_2);
  if (pUStack_1c == (UnitData *)0x0) {
    return 0;
  }
  iVar6 = 0;
  param_1->actualGathererDistribution[param_3] = param_1->actualGathererDistribution[param_3] + 1;
  iVar5 = (param_1->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar5) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar6) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar6] == param_2) goto LAB_004fa69e;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
    iVar5 = iVar5 + 1;
    piVar7 = (int *)operator_new(iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      iVar6 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar5 <= iVar6) break;
          iVar8 = iVar6 + 1;
          piVar7[iVar6] = (param_1->unitsTaskedThisUpdate).value[iVar6];
          iVar6 = iVar8;
        } while (iVar8 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar7;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = param_2;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fa69e:
  pUStack_1c->data1 = param_3;
  iVar5 = TribeTacticalAIModule::requiredGatherAmount(param_1,param_3);
  if (param_4 == 1) {
    iVar5 = 10;
  }
  else {
    if (param_1->sn[0xcb] == 1) {
      if (pRVar3->master_obj->id == 0x3b) {
        iVar5 = __ftol();
      }
      else if (param_3 == 1) {
        iVar5 = 0x4b;
      }
      else if (param_3 == 3) {
        iVar5 = 0x32;
      }
      else if (param_3 == 2) {
        iVar5 = 0x32;
      }
    }
    else {
      iVar6 = param_1->sn[0x94];
      if ((iVar5 < param_1->sn[0x94]) || (iVar6 = param_1->sn[0x95], param_1->sn[0x95] < iVar5)) {
        iVar5 = iVar6;
      }
    }
    if (param_1->zoomingToNextAge == 1) {
      iVar5 = 0x14;
    }
  }
  pUStack_1c->data2 = iVar5;
  pUStack_1c->data3 = 0;
  (**(code **)(param_1->md->aiPlayer->_padding_ + 0x124))
            (param_2,iVar10,(int)pRVar3->owner->id,fStack_24,fStack_28);
  if (pRVar3->master_obj->id == 0x30) {
    TribeTacticalAIModule::taskElephantGatherers(param_1,param_2,param_1->sn[0xcc] + -1,iVar10);
  }
  if (pRVar3->master_obj->id == 0x32) {
    pTVar2 = param_1->md;
    iVar5 = pRVar3->id;
    pMVar9 = &(pTVar2->informationAI).farmsTaskedThisUpdate;
    iVar6 = 0;
    iVar10 = (pTVar2->informationAI).farmsTaskedThisUpdate.numberValue;
    if (0 < iVar10) {
      do {
        if ((pTVar2->informationAI).farmsTaskedThisUpdate.maximumSizeValue <= iVar6) break;
        if (pMVar9->value[iVar6] == iVar5) {
          return 1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar10);
    }
    if ((pTVar2->informationAI).farmsTaskedThisUpdate.maximumSizeValue + -1 < iVar10) {
      iVar10 = iVar10 + 1;
      piVar7 = (int *)operator_new(iVar10 * 4);
      if (piVar7 != (int *)0x0) {
        iVar6 = 0;
        if (0 < (pTVar2->informationAI).farmsTaskedThisUpdate.maximumSizeValue) {
          do {
            if (iVar10 <= iVar6) break;
            iVar8 = iVar6 + 1;
            piVar7[iVar6] = pMVar9->value[iVar6];
            iVar6 = iVar8;
          } while (iVar8 < (pTVar2->informationAI).farmsTaskedThisUpdate.maximumSizeValue);
        }
        operator_delete(pMVar9->value);
        pMVar9->value = piVar7;
        (pTVar2->informationAI).farmsTaskedThisUpdate.maximumSizeValue = iVar10;
      }
    }
    pMVar9->value[(pTVar2->informationAI).farmsTaskedThisUpdate.numberValue] = iVar5;
    (pTVar2->informationAI).farmsTaskedThisUpdate.numberValue =
         (pTVar2->informationAI).farmsTaskedThisUpdate.numberValue + 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fa936
// Address: 004fa936
// XREFS: None
void __thiscall FUN_004fa936(TribeTacticalAIModule *param_1,int param_2,float param_3,float param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  XYPoint XStack_8;
  
  iVar1 = 0;
  iVar4 = (param_1->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar4) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar1) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar1] == param_2) goto LAB_004fa9fb;
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar4);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar4) {
    iVar4 = iVar4 + 1;
    piVar2 = (int *)operator_new(iVar4 * 4);
    if (piVar2 != (int *)0x0) {
      iVar1 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar4 <= iVar1) break;
          iVar3 = iVar1 + 1;
          piVar2[iVar1] = (param_1->unitsTaskedThisUpdate).value[iVar1];
          iVar1 = iVar3;
        } while (iVar3 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar2;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar4;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = param_2;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fa9fb:
  iVar4 = (param_1->civilians).numberValue;
  iVar1 = 0;
  if (0 < iVar4) {
    do {
      if ((param_1->civilians).maximumSizeValue <= iVar1) break;
      if ((param_1->civilians).value[iVar1] == param_2) {
        iVar4 = TribeTacticalAIModule::unexploredArea(param_1,param_2,&XStack_8);
        if (iVar4 == 1) {
          TribeTacticalAIModule::taskExplorer(param_1,param_2,(float)XStack_8.x,(float)XStack_8.y,1)
          ;
          return;
        }
        TribeTacticalAIModule::taskExplorer(param_1,param_2,param_3,param_4,1);
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar4);
  }
  TribeTacticalAIModule::taskExplorer(param_1,param_2,param_3,param_4,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004faa91
// Address: 004faa91
// XREFS: None
undefined4 __thiscall
FUN_004faa91(TribeTacticalAIModule *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            int param_5)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = (param_1->unitsTaskedThisUpdate).numberValue;
  if (0 < iVar1) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar2] == param_2) goto LAB_004fab58;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (param_1->unitsTaskedThisUpdate).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar3;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar1;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = param_2;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fab58:
  if (param_5 == 1) {
    iVar1 = (param_1->civilianExplorers).numberValue;
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if ((param_1->civilianExplorers).maximumSizeValue <= iVar2) break;
        if ((param_1->civilianExplorers).value[iVar2] == param_2) goto LAB_004fac3b;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    iVar1 = (param_1->civilianExplorers).numberValue;
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if ((param_1->civilianExplorers).maximumSizeValue <= iVar2) break;
        if ((param_1->civilianExplorers).value[iVar2] == param_2) goto LAB_004fac3b;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    if ((param_1->civilianExplorers).maximumSizeValue + -1 < iVar1) {
      iVar1 = iVar1 + 1;
      piVar3 = (int *)operator_new(iVar1 * 4);
      if (piVar3 != (int *)0x0) {
        iVar2 = 0;
        if (0 < (param_1->civilianExplorers).maximumSizeValue) {
          do {
            if (iVar1 <= iVar2) break;
            iVar4 = iVar2 + 1;
            piVar3[iVar2] = (param_1->civilianExplorers).value[iVar2];
            iVar2 = iVar4;
          } while (iVar4 < (param_1->civilianExplorers).maximumSizeValue);
        }
        operator_delete((param_1->civilianExplorers).value);
        (param_1->civilianExplorers).value = piVar3;
        (param_1->civilianExplorers).maximumSizeValue = iVar1;
      }
    }
    (param_1->civilianExplorers).value[(param_1->civilianExplorers).numberValue] = param_2;
    (param_1->civilianExplorers).numberValue = (param_1->civilianExplorers).numberValue + 1;
LAB_004fac3b:
    TribeTacticalAIModule::removeGatherer(param_1,param_2);
  }
  piVar3 = (int *)param_1->md->_padding_;
  (**(code **)(*piVar3 + 0x30))
            ((int)*(short *)((int)piVar3 + 0x4a),param_2,0x2c1,0xffffffff,0xffffffff,param_3,param_4
             ,0xbf800000,0x3f800000,1,0,1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fac89
// Address: 004fac89
// XREFS: None
undefined4 __thiscall
FUN_004fac89(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0xd5c);
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1 + 0xd64) <= iVar3) break;
      if (*(int *)(*(int *)(param_1 + 0xd58) + iVar3 * 4) == param_2) goto LAB_004fad48;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if (*(int *)(param_1 + 0xd64) + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar4 = operator_new(iVar1 * 4);
    if (pvVar4 != (void *)0x0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0xd64)) {
        do {
          if (iVar1 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0xd58) + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)(param_1 + 0xd64));
      }
      operator_delete(*(void **)(param_1 + 0xd58));
      *(void **)(param_1 + 0xd58) = pvVar4;
      *(int *)(param_1 + 0xd64) = iVar1;
    }
  }
  *(int *)(*(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xd5c) * 4) = param_2;
  *(int *)(param_1 + 0xd5c) = *(int *)(param_1 + 0xd5c) + 1;
LAB_004fad48:
  piVar2 = *(int **)(*(int *)(param_1 + 0xf0) + 0xf0);
  (**(code **)(*piVar2 + 0x30))
            ((int)*(short *)((int)piVar2 + 0x4a),param_2,0x2c8,param_3,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,param_4,1,0,param_5);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fad94
// Address: 004fad94
// XREFS: None
undefined4 __thiscall
FUN_004fad94(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0xd5c);
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1 + 0xd64) <= iVar3) break;
      if (*(int *)(*(int *)(param_1 + 0xd58) + iVar3 * 4) == param_2) goto LAB_004fae58;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if (*(int *)(param_1 + 0xd64) + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar4 = operator_new(iVar1 * 4);
    if (pvVar4 != (void *)0x0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0xd64)) {
        do {
          if (iVar1 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0xd58) + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)(param_1 + 0xd64));
      }
      operator_delete(*(void **)(param_1 + 0xd58));
      *(void **)(param_1 + 0xd58) = pvVar4;
      *(int *)(param_1 + 0xd64) = iVar1;
    }
  }
  *(int *)(*(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xd5c) * 4) = param_2;
  *(int *)(param_1 + 0xd5c) = *(int *)(param_1 + 0xd5c) + 1;
LAB_004fae58:
  piVar2 = *(int **)(*(int *)(param_1 + 0xf0) + 0xf0);
  (**(code **)(*piVar2 + 0x30))
            ((int)*(short *)((int)piVar2 + 0x4a),param_2,0x2bd,param_3,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,param_4,1,0,param_5);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004faea4
// Address: 004faea4
// XREFS: None
undefined4 __thiscall FUN_004faea4(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  
  if (param_2 == -1) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0xd5c);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1 + 0xd64) <= iVar3) break;
      if (*(int *)(*(int *)(param_1 + 0xd58) + iVar3 * 4) == param_2) goto LAB_004faf74;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if (*(int *)(param_1 + 0xd64) + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar4 = operator_new(iVar1 * 4);
    if (pvVar4 != (void *)0x0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0xd64)) {
        do {
          if (iVar1 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0xd58) + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)(param_1 + 0xd64));
      }
      operator_delete(*(void **)(param_1 + 0xd58));
      *(void **)(param_1 + 0xd58) = pvVar4;
      *(int *)(param_1 + 0xd64) = iVar1;
    }
  }
  *(int *)(*(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xd5c) * 4) = param_2;
  *(int *)(param_1 + 0xd5c) = *(int *)(param_1 + 0xd5c) + 1;
LAB_004faf74:
  piVar2 = *(int **)(*(int *)(param_1 + 0xf0) + 0xf0);
  (**(code **)(*piVar2 + 0x30))
            ((int)*(short *)((int)piVar2 + 0x4a),param_2,0x2c1,0xffffffff,0xffffffff,0xbf800000,
             0xbf800000,0xbf800000,0x3f800000,1,0,1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fafba
// Address: 004fafba
// XREFS: None
undefined4 __thiscall FUN_004fafba(int param_1,int param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  RGE_Static_Object *pRVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  undefined4 uVar10;
  
  pRVar1 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),param_2);
  if ((param_2 != -1) && (pRVar1 != (RGE_Static_Object *)0x0)) {
    pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),param_3);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      uVar3 = __ftol();
      uVar4 = __ftol();
      uVar5 = __ftol();
      uVar10 = 0xffffffff;
      iVar9 = 1;
      iVar6 = (**(code **)(pRVar1->_padding_ + 0x198))
                        (uVar3,uVar4,uVar5,0x40000000,param_3,0,1,0xffffffff,0xffffffff);
      if (iVar6 != 0) {
        iVar6 = *(int *)(param_1 + 0xd5c);
        iVar7 = 0;
        if (0 < iVar6) {
          do {
            if (*(int *)(param_1 + 0xd64) <= iVar7) break;
            if (*(int *)(*(int *)(param_1 + 0xd58) + iVar7 * 4) == iVar9) goto LAB_004fb111;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar6);
        }
        if (*(int *)(param_1 + 0xd64) + -1 < iVar6) {
          iVar6 = iVar6 + 1;
          pvVar8 = operator_new(iVar6 * 4);
          if (pvVar8 != (void *)0x0) {
            iVar7 = 0;
            if (0 < *(int *)(param_1 + 0xd64)) {
              do {
                if (iVar6 <= iVar7) break;
                iVar7 = iVar7 + 1;
                *(undefined4 *)((int)pvVar8 + iVar7 * 4 + -4) =
                     *(undefined4 *)(*(int *)(param_1 + 0xd58) + -4 + iVar7 * 4);
              } while (iVar7 < *(int *)(param_1 + 0xd64));
            }
            operator_delete(*(void **)(param_1 + 0xd58));
            *(void **)(param_1 + 0xd58) = pvVar8;
            *(int *)(param_1 + 0xd64) = iVar6;
          }
        }
        *(int *)(*(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xd5c) * 4) = iVar9;
        *(int *)(param_1 + 0xd5c) = *(int *)(param_1 + 0xd5c) + 1;
LAB_004fb111:
        (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x124))
                  (iVar9,uVar10,(int)*(short *)(*(int *)(param_3 + 0xc) + 0x4a),
                   *(undefined4 *)(param_3 + 0x38),*(undefined4 *)(param_3 + 0x3c));
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004fb15a
// Address: 004fb15a
// XREFS: None
undefined4 __thiscall FUN_004fb15a(int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  pRVar1 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),param_2);
  if ((param_2 != -1) && (pRVar1 != (RGE_Static_Object *)0x0)) {
    uVar2 = __ftol();
    uVar3 = __ftol();
    uVar10 = 0xffffffff;
    uVar9 = 0xffffffff;
    uVar8 = 1;
    iVar7 = 0;
    iVar4 = (**(code **)(pRVar1->_padding_ + 0x198))
                      (uVar2,uVar3,1,0x3f800000,0xffffffff,0,1,0xffffffff,0xffffffff);
    if (iVar4 != 0) {
      iVar4 = *(int *)(param_1 + 0xd5c);
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          if (*(int *)(param_1 + 0xd64) <= iVar5) break;
          if (*(int *)(*(int *)(param_1 + 0xd58) + iVar5 * 4) == iVar7) goto LAB_004fb288;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      if (*(int *)(param_1 + 0xd64) + -1 < iVar4) {
        iVar4 = iVar4 + 1;
        pvVar6 = operator_new(iVar4 * 4);
        if (pvVar6 != (void *)0x0) {
          iVar5 = 0;
          if (0 < *(int *)(param_1 + 0xd64)) {
            do {
              if (iVar4 <= iVar5) break;
              iVar5 = iVar5 + 1;
              *(undefined4 *)((int)pvVar6 + iVar5 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xd58) + -4 + iVar5 * 4);
            } while (iVar5 < *(int *)(param_1 + 0xd64));
          }
          operator_delete(*(void **)(param_1 + 0xd58));
          *(void **)(param_1 + 0xd58) = pvVar6;
          *(int *)(param_1 + 0xd64) = iVar4;
        }
      }
      *(int *)(*(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xd5c) * 4) = iVar7;
      *(int *)(param_1 + 0xd5c) = *(int *)(param_1 + 0xd5c) + 1;
LAB_004fb288:
      (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x124))
                (iVar7,uVar8,0,uVar9,uVar10);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004fb2c3
// Address: 004fb2c3
// XREFS: None
undefined4 __thiscall
FUN_004fb2c3(TribeTacticalAIModule *param_1,int param_2,float param_3,float param_4,int param_5,
            undefined4 param_6,int param_7,int param_8,undefined4 param_9,int param_10)
{
  uchar uVar1;
  uchar uVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float10 fVar9;
  float fVar10;
  
  if (((param_2 == -1) ||
      (this = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),param_2),
      this == (RGE_Static_Object *)0x0)) ||
     (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 == (UnitAIModule *)0x0)) {
    return 0;
  }
  if ((param_7 != 0) && (0 < param_8)) {
    do {
      uVar1 = __ftol();
      uVar2 = __ftol();
      TribeTacticalAIModule::addWaypoint(param_1,param_2,uVar2,uVar1);
      param_8 = param_8 + -1;
    } while (param_8 != 0);
  }
  if (param_5 == -1) {
    fVar10 = RGE_Static_Object::distance_to_position(this,param_3,param_4,1.0);
    iVar6 = TribeTacticalAIModule::calculatePriority(param_1,fVar10);
    TribeTacticalAIModule::moveUnit(param_1,param_2,param_3,param_4,iVar6);
  }
  else {
    pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),param_5);
    if (pRVar4 == (RGE_Static_Object *)0x0) {
      return 0;
    }
    fVar10 = RGE_Static_Object::distance_to_object(this,pRVar4);
    iVar5 = TribeTacticalAIModule::calculatePriority(param_1,fVar10);
    iVar6 = param_1->md->_padding_;
    iVar7 = *(int *)param_1->md->_padding_;
    fVar9 = (float10)(**(code **)(this->_padding_ + 0x10c))(1,0,iVar5);
    (**(code **)(iVar7 + 0x30))
              ((int)*(short *)(iVar6 + 0x4a),param_2,(-(uint)(param_10 != 1) & 0xffffffe3) + 0x2d9,
               param_5,param_6,param_3,param_4,0x3f800000,(float)fVar9);
  }
  iVar6 = (param_1->unitsTaskedThisUpdate).numberValue;
  iVar7 = 0;
  if (0 < iVar6) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar7) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar7] == param_2) {
        return 1;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar6);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar6) {
    iVar6 = iVar6 + 1;
    piVar8 = (int *)operator_new(iVar6 * 4);
    if (piVar8 != (int *)0x0) {
      iVar7 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar6 <= iVar7) break;
          iVar5 = iVar7 + 1;
          piVar8[iVar7] = (param_1->unitsTaskedThisUpdate).value[iVar7];
          iVar7 = iVar5;
        } while (iVar5 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar8;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar6;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = param_2;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fb4f1
// Address: 004fb4f1
// XREFS: None
// [HELPER] s_ERROR__Unused_taskDefender_call_: "ERROR: Unused taskDefender call 2: defender=%d, target=(%f, %f)."
undefined4 __thiscall FUN_004fb4f1(AIModule *param_1,undefined4 param_2,undefined4 param_3)
{
  AIModule::logCommonHistory
            (param_1,(char *)param_1,s_ERROR__Unused_taskDefender_call_,param_2,param_3);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004fb51d
// Address: 004fb51d
// XREFS: None
// [HELPER] s_ERROR__Unused_taskDefender_call_: "ERROR: Unused taskDefender call 2: defender=%d, target=(%f, %f)."
undefined4 __thiscall FUN_004fb51d(AIModule *param_1,undefined4 param_2,float param_3,float param_4)
{
  AIModule::logCommonHistory
            (param_1,(char *)param_1,s_ERROR__Unused_taskDefender_call_,param_2,(double)param_3,
             (double)param_4);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004fb54c
// Address: 004fb54c
// XREFS: None
// [HELPER] s_Could_not_find_a_building_to_tra: "Could not find a building to train type %d (UniqueID=%d) at, returning FALSE."
// [HELPER] s_Invalid_taskTrain_item__returnin: "Invalid taskTrain item, returning FALSE."
// [HELPER] s_Training_ID___d__UniqueID__d__fr: "Training ID #%d (UniqueID=%d) from building with gameID=%d."
undefined4 __thiscall FUN_004fb54c(AIModule *param_1,BuildItem *param_2)
{
  int iVar1;
  RGE_Static_Object *this;
  UnitAIModule *pUVar2;
  void *pvVar3;
  AIModule *this_00;
  AIModule *this_01;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  
  if (param_2 == (BuildItem *)0x0) {
    AIModule::logCommonHistory(param_1,(char *)param_1,s_Invalid_taskTrain_item__returnin);
    return 0;
  }
  iVar8 = 2;
  iVar6 = 0x26c;
  iVar5 = 0x26b;
  iVar4 = -1;
  iVar1 = BuildItem::buildFrom(param_2);
  this = MainDecisionAIModule::object
                   ((MainDecisionAIModule *)param_1[1]._padding_,-1,iVar1,iVar4,iVar5,iVar6,iVar8);
  if ((this == (RGE_Static_Object *)0x0) ||
     (pUVar2 = RGE_Static_Object::unitAI(this), pUVar2 == (UnitAIModule *)0x0)) {
    iVar1 = BaseItem::uniqueID((BaseItem *)param_2);
    iVar4 = BaseItem::typeID((BaseItem *)param_2);
    AIModule::logCommonHistory
              (this_01,(char *)param_1,s_Could_not_find_a_building_to_tra,iVar4,iVar1);
    return 0;
  }
  lVar7 = this->id;
  iVar1 = BaseItem::uniqueID((BaseItem *)param_2);
  iVar4 = BaseItem::typeID((BaseItem *)param_2);
  AIModule::logCommonHistory
            (this_00,(char *)param_1,s_Training_ID___d__UniqueID__d__fr,iVar4,iVar1,lVar7);
  BuildItem::setInProgress(param_2,1);
  BuildItem::setBuilt(param_2,0);
  iVar1 = *(int *)(param_1[0xe].idValue.name + 0x30);
  iVar4 = this->id;
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1[0xe].idValue.name + 0x38) <= iVar5) break;
      if (*(int *)(*(int *)(param_1[0xe].idValue.name + 0x2c) + iVar5 * 4) == iVar4)
      goto LAB_004fb6a7;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  if (*(int *)(param_1[0xe].idValue.name + 0x38) + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar3 = operator_new(iVar1 * 4);
    if (pvVar3 != (void *)0x0) {
      iVar5 = 0;
      if (0 < *(int *)(param_1[0xe].idValue.name + 0x38)) {
        do {
          if (iVar1 <= iVar5) break;
          iVar5 = iVar5 + 1;
          *(undefined4 *)((int)pvVar3 + iVar5 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1[0xe].idValue.name + 0x2c) + -4 + iVar5 * 4);
        } while (iVar5 < *(int *)(param_1[0xe].idValue.name + 0x38));
      }
      operator_delete(*(void **)(param_1[0xe].idValue.name + 0x2c));
      *(void **)(param_1[0xe].idValue.name + 0x2c) = pvVar3;
      *(int *)(param_1[0xe].idValue.name + 0x38) = iVar1;
    }
  }
  *(int *)(*(int *)(param_1[0xe].idValue.name + 0x2c) +
          *(int *)(param_1[0xe].idValue.name + 0x30) * 4) = iVar4;
  *(int *)(param_1[0xe].idValue.name + 0x30) = *(int *)(param_1[0xe].idValue.name + 0x30) + 1;
LAB_004fb6a7:
  iVar1 = **(int **)(param_1[1]._padding_ + 0x1256c);
  iVar4 = BaseItem::uniqueID((BaseItem *)param_2);
  lVar7 = this->id;
  iVar5 = BaseItem::typeID((BaseItem *)param_2);
  (**(code **)(iVar1 + 0x108))(iVar5,lVar7,iVar4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fb9dc
// Address: 004fb9dc
// XREFS: None
undefined4 __thiscall
FUN_004fb9dc(TribeTacticalAIModule *param_1,int param_2,float param_3,float param_4)
{
  RGE_Static_Object *this;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_2);
  if ((param_2 == -1) || (this == (RGE_Static_Object *)0x0)) {
    return 0;
  }
  fVar6 = RGE_Static_Object::distance_to_position(this,param_3,param_4,1.0);
  iVar1 = TribeTacticalAIModule::calculatePriority(param_1,fVar6);
  iVar5 = (param_1->unitsTaskedThisUpdate).numberValue;
  iVar2 = 0;
  if (0 < iVar5) {
    do {
      if ((param_1->unitsTaskedThisUpdate).maximumSizeValue <= iVar2) break;
      if ((param_1->unitsTaskedThisUpdate).value[iVar2] == param_2) goto LAB_004fbadf;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  if ((param_1->unitsTaskedThisUpdate).maximumSizeValue + -1 < iVar5) {
    iVar5 = iVar5 + 1;
    piVar3 = (int *)operator_new(iVar5 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (param_1->unitsTaskedThisUpdate).maximumSizeValue) {
        do {
          if (iVar5 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (param_1->unitsTaskedThisUpdate).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (param_1->unitsTaskedThisUpdate).maximumSizeValue);
      }
      operator_delete((param_1->unitsTaskedThisUpdate).value);
      (param_1->unitsTaskedThisUpdate).value = piVar3;
      (param_1->unitsTaskedThisUpdate).maximumSizeValue = iVar5;
    }
  }
  (param_1->unitsTaskedThisUpdate).value[(param_1->unitsTaskedThisUpdate).numberValue] = param_2;
  (param_1->unitsTaskedThisUpdate).numberValue = (param_1->unitsTaskedThisUpdate).numberValue + 1;
LAB_004fbadf:
  piVar3 = (int *)param_1->md->_padding_;
  iVar5 = (int)*(short *)((int)piVar3 + 0x4a);
  (**(code **)(*piVar3 + 0x30))
            (iVar5,param_2,0x2ca,0xffffffff,iVar5,param_3,param_4,0x3f800000,0x3f800000,1,0,iVar1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004fbc07
// Address: 004fbc07
// XREFS: None
int FUN_004fbc07(void)
{
  int iVar1;
  
  iVar1 = __ftol();
  if (99 < iVar1) {
    iVar1 = 99;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_004fbc2c
// Address: 004fbc2c
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
void __fastcall FUN_004fbc2c(TribeTacticalAIModule *param_1)
{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  RGE_Static_Object *pRVar7;
  int iVar8;
  TacticalAIGroup *pTVar9;
  undefined4 *unaff_FS_OFFSET;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_28;
  int iStack_24;
  ManagedArray<int> MStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00560b48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  MStack_1c.value = (int *)0x0;
  MStack_1c.numberValue = 0;
  MStack_1c.desiredNumberValue = 0;
  MStack_1c.maximumSizeValue = 0;
  pTVar9 = (param_1->groups).next;
  uStack_4 = 0;
  for (; (pTVar9 != &param_1->groups && (pTVar9 != (TacticalAIGroup *)0x0)); pTVar9 = pTVar9->next)
{
    iVar2 = TacticalAIGroup::numberUnits(pTVar9);
    if (iVar2 == 0) {
      iVar2 = TacticalAIGroup::id(pTVar9);
      iVar3 = 0;
      piVar4 = MStack_1c.value;
      if (0 < MStack_1c.numberValue) {
        do {
          if (MStack_1c.maximumSizeValue <= iVar3) break;
          if (*piVar4 == iVar2) goto LAB_004fbcda;
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar3 < MStack_1c.numberValue);
      }
      if (MStack_1c.maximumSizeValue + -1 < MStack_1c.numberValue) {
        ManagedArray<int>::resize(&MStack_1c,MStack_1c.numberValue + 1);
      }
      MStack_1c.value[MStack_1c.numberValue] = iVar2;
      MStack_1c.numberValue = MStack_1c.numberValue + 1;
    }
LAB_004fbcda:
  }
  uVar1 = *(ulong *)(*(int *)(param_1->md->_padding_ + 0x3c) + 4);
  if ((600 < (uVar1 - param_1->lastGroupAttackTime) / 1000) &&
     (600 < (uVar1 - param_1->lastGroupRebalanceTime) / 1000)) {
    pTVar9 = (param_1->groups).next;
    param_1->lastGroupRebalanceTime = uVar1;
    for (; (pTVar9 != &param_1->groups && (pTVar9 != (TacticalAIGroup *)0x0)); pTVar9 = pTVar9->next
        ) {
      iVar2 = TacticalAIGroup::type(pTVar9);
      if (iVar2 == 100) {
        iVar2 = TacticalAIGroup::id(pTVar9);
        iVar3 = 0;
        piVar4 = MStack_1c.value;
        if (0 < MStack_1c.numberValue) {
          do {
            if (MStack_1c.maximumSizeValue <= iVar3) break;
            if (*piVar4 == iVar2) goto LAB_004fbda8;
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar3 < MStack_1c.numberValue);
        }
        if (MStack_1c.maximumSizeValue + -1 < MStack_1c.numberValue) {
          ManagedArray<int>::resize(&MStack_1c,MStack_1c.numberValue + 1);
        }
        MStack_1c.value[MStack_1c.numberValue] = iVar2;
        MStack_1c.numberValue = MStack_1c.numberValue + 1;
      }
LAB_004fbda8:
    }
  }
  iStack_30 = 0;
  if (0 < MStack_1c.numberValue) {
    do {
      if (MStack_1c.maximumSizeValue + -1 < iStack_30) {
        piVar4 = (int *)operator_new(iStack_30 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar2 = 0;
          if (0 < MStack_1c.maximumSizeValue) {
            do {
              if (iStack_30 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar4[iVar2] = MStack_1c.value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < MStack_1c.maximumSizeValue);
          }
          operator_delete(MStack_1c.value);
          MStack_1c.value = piVar4;
          MStack_1c.maximumSizeValue = iStack_30 + 1;
        }
      }
      TribeTacticalAIModule::removeGroup(param_1,MStack_1c.value[iStack_30]);
      iStack_30 = iStack_30 + 1;
    } while (iStack_30 < MStack_1c.numberValue);
  }
  if (((param_1->soldiers).maximumSizeValue + -1 < 0) &&
     (piVar4 = (int *)operator_new(4), piVar4 != (int *)0x0)) {
    iVar2 = 0;
    if (0 < (param_1->soldiers).maximumSizeValue) {
      do {
        if (0 < iVar2) break;
        iVar3 = iVar2 + 1;
        piVar4[iVar2] = (param_1->soldiers).value[iVar2];
        iVar2 = iVar3;
      } while (iVar3 < (param_1->soldiers).maximumSizeValue);
    }
    operator_delete((param_1->soldiers).value);
    (param_1->soldiers).value = piVar4;
    (param_1->soldiers).maximumSizeValue = 1;
  }
  iVar2 = TribeInformationAIModule::fullyExploredZone
                    (&param_1->md->informationAI,*(param_1->soldiers).value);
  if (iVar2 == 0) {
    TribeTacticalAIModule::removeAllGroups(param_1,0x66);
    TribeTacticalAIModule::setStrategicNumber(param_1,0x2a,0);
  }
  iVar3 = TribeTacticalAIModule::numberGroups(param_1,100,-1);
  iStack_28 = TribeTacticalAIModule::numberGroups(param_1,0x65,-1);
  iStack_24 = TribeTacticalAIModule::numberGroups(param_1,0x66,-1);
  TribeTacticalAIModule::numberGroups(param_1,0x6d,-1);
  TribeTacticalAIModule::numberUngroupedArtifacts(param_1);
  iVar2 = (param_1->workingArea).numberValue;
  while (0 < iVar2) {
    if ((param_1->workingArea).maximumSizeValue + -1 < iStack_30) {
      iVar2 = iStack_30 + 1;
      piVar4 = (int *)operator_new(iVar2 * 4);
      if (piVar4 != (int *)0x0) {
        iVar8 = 0;
        if (0 < (param_1->workingArea).maximumSizeValue) {
          do {
            if (iVar2 <= iVar8) break;
            iVar5 = iVar8 + 1;
            piVar4[iVar8] = (param_1->workingArea).value[iVar8];
            iVar8 = iVar5;
          } while (iVar5 < (param_1->workingArea).maximumSizeValue);
        }
        operator_delete((param_1->workingArea).value);
        (param_1->workingArea).value = piVar4;
        (param_1->workingArea).maximumSizeValue = iVar2;
      }
    }
    iVar2 = (param_1->workingArea).value[iStack_30];
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar2);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      iVar8 = (param_1->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar8) {
        piVar4 = (param_1->workingArea).value;
        do {
          if (*piVar4 == iVar2) break;
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar5 < iVar8);
      }
      if (iVar5 < iVar8) {
        if (iVar5 < iVar8 + -1) {
          do {
            piVar4 = (param_1->workingArea).value;
            iVar2 = iVar5 + 1;
            piVar4[iVar5] = piVar4[iVar2];
            iVar5 = iVar2;
          } while (iVar2 < (param_1->workingArea).maximumSizeValue + -1);
        }
LAB_004fc050:
        iVar2 = (param_1->workingArea).numberValue + -1;
        (param_1->workingArea).numberValue = iVar2;
joined_r0x004fc13d:
        if (iVar2 < 0) {
          (param_1->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pRVar7 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
      if (pRVar7 == (RGE_Static_Object *)0x0) {
        iVar8 = (param_1->workingArea).maximumSizeValue;
        iVar5 = 0;
        if (0 < iVar8) {
          piVar4 = (param_1->workingArea).value;
          do {
            if (*piVar4 == iVar2) break;
            iVar5 = iVar5 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar5 < iVar8);
        }
        if (iVar5 < iVar8) {
          if (iVar5 < iVar8 + -1) {
            do {
              piVar4 = (param_1->workingArea).value;
              iVar2 = iVar5 + 1;
              piVar4[iVar5] = piVar4[iVar2];
              iVar5 = iVar2;
            } while (iVar2 < (param_1->workingArea).maximumSizeValue + -1);
          }
          goto LAB_004fc050;
        }
      }
      else {
        pTVar9 = TribeTacticalAIModule::createGroup(param_1,1);
        if (pTVar9 == (TacticalAIGroup *)0x0) break;
        TacticalAIGroup::setType(pTVar9,0x6d);
        TacticalAIGroup::setDesiredNumberUnits(pTVar9,1);
        TacticalAIGroup::addUnit(pTVar9,iVar2,param_1->md);
        TacticalAIGroup::setSpecificCommander(pTVar9,iVar2,param_1->md);
        TacticalAIGroup::setLocation(pTVar9,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
        TacticalAIGroup::setGatherLocation(pTVar9,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
        TacticalAIGroup::setRetreatLocation(pTVar9,pRVar7->world_x,pRVar7->world_y,pRVar7->world_z);
        iVar8 = (param_1->workingArea).maximumSizeValue;
        iVar5 = 0;
        if (0 < iVar8) {
          piVar4 = (param_1->workingArea).value;
          do {
            if (*piVar4 == iVar2) break;
            iVar5 = iVar5 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar5 < iVar8);
        }
        if (iVar5 < iVar8) {
          if (iVar5 < iVar8 + -1) {
            do {
              piVar4 = (param_1->workingArea).value;
              iVar2 = iVar5 + 1;
              piVar4[iVar5] = piVar4[iVar2];
              iVar5 = iVar2;
            } while (iVar2 < (param_1->workingArea).maximumSizeValue + -1);
          }
          iVar2 = (param_1->workingArea).numberValue + -1;
          (param_1->workingArea).numberValue = iVar2;
          goto joined_r0x004fc13d;
        }
      }
    }
    iVar2 = (param_1->workingArea).numberValue;
  }
  iStack_34 = 0;
  iStack_30 = 0;
  if (param_1->sn[0x28] == 0) {
    ceil((double)(param_1->soldiers).numberValue / (double)param_1->sn[0x10]);
    iStack_38 = __ftol();
    if (param_1->sn[0x24] < iStack_38) {
      iStack_38 = param_1->sn[0x24];
    }
    iVar8 = iStack_38 * param_1->sn[0x10];
    iVar2 = (param_1->soldiers).numberValue - iVar8;
    if (iVar2 < 1) goto LAB_004fc280;
    ceil((double)iVar2 / (double)param_1->sn[0x19]);
    iStack_34 = __ftol();
    if (param_1->sn[0x26] < iStack_34) {
      iStack_34 = param_1->sn[0x26];
    }
    iVar8 = ((param_1->soldiers).numberValue - iStack_34 * param_1->sn[0x19]) - iVar8;
    if (iVar8 < 1) goto LAB_004fc280;
    ceil((double)iVar8 / (double)param_1->sn[0x2b]);
    iStack_30 = __ftol();
    iVar8 = param_1->sn[0x2a];
    if (iStack_30 <= iVar8) goto LAB_004fc280;
  }
  else {
    iVar2 = (param_1->soldiers).numberValue;
    iStack_38 = iVar2;
    if (param_1->sn[0x24] <= iVar2) {
      iStack_38 = param_1->sn[0x24];
    }
    iVar2 = iVar2 - iStack_38;
    if (iVar2 < 1) goto LAB_004fc280;
    iStack_34 = param_1->sn[0x26];
    if (iVar2 < param_1->sn[0x26]) {
      iStack_34 = iVar2;
    }
    iVar2 = iVar2 - iStack_34;
    if ((iVar2 < 1) || (iVar8 = param_1->sn[0x2a], iStack_30 = iVar2, iVar2 < iVar8))
    goto LAB_004fc280;
  }
  iStack_30 = iVar8;
LAB_004fc280:
  if (param_1->sn[0xa2] == 1) {
    iStack_38 = 0;
  }
  for (; iVar3 < iStack_38; iVar3 = iVar3 + 1) {
    pTVar9 = (TacticalAIGroup *)0x0;
    if (iStack_28 < 1) {
LAB_004fc2d8:
      if (pTVar9 == (TacticalAIGroup *)0x0) goto LAB_004fc2dc;
    }
    else {
      pTVar9 = TribeTacticalAIModule::group(param_1,-1,0x65,-1,-1);
      if (pTVar9 != (TacticalAIGroup *)0x0) {
        iStack_28 = iStack_28 + -1;
        goto LAB_004fc2d8;
      }
      pTVar9 = TribeTacticalAIModule::group(param_1,-1,0x66,-1,-1);
      if (pTVar9 != (TacticalAIGroup *)0x0) {
        iStack_24 = iStack_24 + -1;
        goto LAB_004fc2d8;
      }
LAB_004fc2dc:
      pTVar9 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar9 == (TacticalAIGroup *)0x0) break;
    }
    TacticalAIGroup::setType(pTVar9,100);
    TacticalAIGroup::setTarget(pTVar9,-1);
    TacticalAIGroup::setTargetType(pTVar9,-1);
    TacticalAIGroup::setAction(pTVar9,1);
    TacticalAIGroup::setInUse(pTVar9,0);
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x2560);
    iVar2 = iVar2 % (param_1->sn[0x62] + 1) + param_1->sn[0x10];
    if (param_1->sn[0x1a] < iVar2) {
      iVar2 = param_1->sn[0x1a];
    }
    TacticalAIGroup::setDesiredNumberUnits(pTVar9,iVar2);
  }
  while ((iStack_38 < iVar3 &&
         ((pTVar9 = TribeTacticalAIModule::group(param_1,-1,100,0,-1),
          pTVar9 != (TacticalAIGroup *)0x0 ||
          (pTVar9 = TribeTacticalAIModule::group(param_1,-1,100,1,-1),
          pTVar9 != (TacticalAIGroup *)0x0))))) {
    iVar2 = TacticalAIGroup::id(pTVar9);
    TribeTacticalAIModule::removeGroup(param_1,iVar2);
    iVar3 = iVar3 + -1;
  }
  for (; iStack_28 < iStack_34; iStack_28 = iStack_28 + 1) {
    pTVar9 = (TacticalAIGroup *)0x0;
    if (iStack_24 < 1) {
LAB_004fc3db:
      if (pTVar9 == (TacticalAIGroup *)0x0) goto LAB_004fc3df;
    }
    else {
      pTVar9 = TribeTacticalAIModule::group(param_1,-1,0x66,-1,-1);
      if (pTVar9 != (TacticalAIGroup *)0x0) {
        iStack_24 = iStack_24 + -1;
        goto LAB_004fc3db;
      }
LAB_004fc3df:
      pTVar9 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar9 == (TacticalAIGroup *)0x0) break;
    }
    TacticalAIGroup::setType(pTVar9,0x65);
    TacticalAIGroup::setTarget(pTVar9,-1);
    TacticalAIGroup::setTargetType(pTVar9,-1);
    TacticalAIGroup::setAction(pTVar9,1);
    TacticalAIGroup::setInUse(pTVar9,0);
    TacticalAIGroup::setDesiredNumberUnits(pTVar9,param_1->sn[0x19]);
  }
  while ((iStack_34 < iStack_28 &&
         (pTVar9 = TribeTacticalAIModule::group(param_1,-1,0x65,-1,-1),
         pTVar9 != (TacticalAIGroup *)0x0))) {
    iVar2 = TacticalAIGroup::id(pTVar9);
    TribeTacticalAIModule::removeGroup(param_1,iVar2);
    iStack_28 = iStack_28 + -1;
  }
  while ((iStack_24 < iStack_30 &&
         (pTVar9 = TribeTacticalAIModule::createGroup(param_1,1), pTVar9 != (TacticalAIGroup *)0x0))
        ) {
    TacticalAIGroup::setType(pTVar9,0x66);
    TacticalAIGroup::setDesiredNumberUnits(pTVar9,param_1->sn[0x2b]);
    iStack_24 = iStack_24 + 1;
  }
  while ((iStack_30 < iStack_24 &&
         (pTVar9 = TribeTacticalAIModule::group(param_1,-1,0x66,-1,-1),
         pTVar9 != (TacticalAIGroup *)0x0))) {
    iVar2 = TacticalAIGroup::id(pTVar9);
    TribeTacticalAIModule::removeGroup(param_1,iVar2);
    iStack_24 = iStack_24 + -1;
  }
  uStack_4 = 0xffffffff;
  if (MStack_1c.value != (int *)0x0) {
    operator_delete(MStack_1c.value);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004fc4f1
// Address: 004fc4f1
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fc4f1(TribeTacticalAIModule *param_1)
{
  TacticalAIGroup *pTVar1;
  byte bVar2;
  uchar uVar3;
  uchar uVar4;
  int iVar5;
  int iVar6;
  Waypoint *pWVar7;
  int *piVar8;
  RGE_Static_Object *pRVar9;
  int iVar10;
  TacticalAIGroup *pTVar11;
  TacticalAIGroup *pTVar12;
  float fVar13;
  float fVar14;
  TribeMainDecisionAIModule *pTVar15;
  int iStack_1c;
  TacticalAIGroup *pTStack_18;
  float fStack_14;
  float fStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  TribeTacticalAIModule::numberUngroupedSoldiers(param_1);
  TribeTacticalAIModule::numberExtraGroupedSoldiers(param_1);
  pTVar12 = (param_1->groups).next;
  do {
    if ((pTVar12 == &param_1->groups) || (pTVar12 == (TacticalAIGroup *)0x0)) {
      if (param_1->sn[0x28] == 0) {
        iStack_c = 100;
        do {
          pTVar12 = (param_1->groups).next;
          if (pTVar12 != &param_1->groups) {
            do {
              if (pTVar12 == (TacticalAIGroup *)0x0) break;
              iVar5 = TacticalAIGroup::type(pTVar12);
              if (iVar5 == iStack_c) {
                iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                iVar6 = TacticalAIGroup::numberUnits(pTVar12);
                if (iVar6 < iVar5) {
                  iVar5 = TacticalAIGroup::inUse(pTVar12);
                  if (iVar5 == 1) {
                    pTVar12 = pTVar12->next;
                  }
                  else {
                    pTStack_18 = (TacticalAIGroup *)0xffffffff;
                    iVar5 = TacticalAIGroup::commander(pTVar12);
                    pRVar9 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar5)
                    ;
                    if (pRVar9 != (RGE_Static_Object *)0x0) {
                      bVar2 = RGE_Static_Object::currentZone(pRVar9);
                      pTStack_18 = (TacticalAIGroup *)(uint)bVar2;
                    }
                    iVar5 = TribeTacticalAIModule::numberUngroupedSoldiers(param_1);
                    iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                    iVar10 = TacticalAIGroup::numberUnits(pTVar12);
                    if (iVar6 - iVar10 < iVar5) {
                      iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                      iVar6 = TacticalAIGroup::numberUnits(pTVar12);
                      if (iVar6 < iVar5) {
                        do {
                          iVar5 = 0;
                          iStack_4 = -1;
                          fStack_14 = -1.0;
                          if (0 < (param_1->workingArea).numberValue) {
                            do {
                              if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                                piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                                if (piVar8 != (int *)0x0) {
                                  iVar6 = 0;
                                  if (0 < (param_1->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar5 + 1 <= iVar6) break;
                                      iVar10 = iVar6 + 1;
                                      piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                      iVar6 = iVar10;
                                    } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((param_1->workingArea).value);
                                  (param_1->workingArea).value = piVar8;
                                  (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                                }
                              }
                              pRVar9 = MainDecisionAIModule::object
                                                 ((MainDecisionAIModule *)param_1->md,
                                                  (param_1->workingArea).value[iVar5]);
                              if ((pRVar9 != (RGE_Static_Object *)0x0) &&
                                 (bVar2 = RGE_Static_Object::currentZone(pRVar9),
                                 pTStack_18 == (TacticalAIGroup *)(uint)bVar2)) {
                                pWVar7 = TacticalAIGroup::gatherLocation(pTVar12);
                                fVar13 = pWVar7->z;
                                pWVar7 = TacticalAIGroup::gatherLocation(pTVar12);
                                fVar14 = pWVar7->y;
                                pWVar7 = TacticalAIGroup::gatherLocation(pTVar12);
                                fVar13 = RGE_Static_Object::distance_to_position
                                                   (pRVar9,pWVar7->x,fVar14,fVar13);
                                if ((fStack_14 == _DAT_00575758) || (fVar13 < fStack_14)) {
                                  if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                                    piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                                    if (piVar8 != (int *)0x0) {
                                      iVar6 = 0;
                                      if (0 < (param_1->workingArea).maximumSizeValue) {
                                        do {
                                          if (iVar5 + 1 <= iVar6) break;
                                          iVar10 = iVar6 + 1;
                                          piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                          iVar6 = iVar10;
                                        } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                                      }
                                      operator_delete((param_1->workingArea).value);
                                      (param_1->workingArea).value = piVar8;
                                      (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                                    }
                                  }
                                  iStack_4 = (param_1->workingArea).value[iVar5];
                                  fStack_14 = fVar13;
                                }
                              }
                              iVar5 = iVar5 + 1;
                            } while (iVar5 < (param_1->workingArea).numberValue);
                          }
                          if (iStack_4 == -1) break;
                          TacticalAIGroup::addUnit(pTVar12,iStack_4,param_1->md);
                          iVar5 = (param_1->workingArea).maximumSizeValue;
                          iVar6 = 0;
                          if (0 < iVar5) {
                            piVar8 = (param_1->workingArea).value;
                            do {
                              if (*piVar8 == iStack_4) break;
                              iVar6 = iVar6 + 1;
                              piVar8 = piVar8 + 1;
                            } while (iVar6 < iVar5);
                          }
                          if (iVar6 < iVar5) {
                            if (iVar6 < iVar5 + -1) {
                              do {
                                piVar8 = (param_1->workingArea).value;
                                iVar5 = iVar6 + 1;
                                piVar8[iVar6] = piVar8[iVar5];
                                iVar6 = iVar5;
                              } while (iVar5 < (param_1->workingArea).maximumSizeValue + -1);
                            }
                            iVar5 = (param_1->workingArea).numberValue + -1;
                            (param_1->workingArea).numberValue = iVar5;
                            if (iVar5 < 0) {
                              (param_1->workingArea).numberValue = 0;
                            }
                          }
                          iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                          iVar6 = TacticalAIGroup::numberUnits(pTVar12);
                        } while (iVar6 < iVar5);
                      }
                    }
                    else {
                      iVar5 = 0;
                      if (0 < (param_1->workingArea).numberValue) {
                        do {
                          if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                            piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                            if (piVar8 != (int *)0x0) {
                              iVar6 = 0;
                              if (0 < (param_1->workingArea).maximumSizeValue) {
                                do {
                                  if (iVar5 + 1 <= iVar6) break;
                                  iVar10 = iVar6 + 1;
                                  piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                  iVar6 = iVar10;
                                } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                              }
                              operator_delete((param_1->workingArea).value);
                              (param_1->workingArea).value = piVar8;
                              (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                            }
                          }
                          pRVar9 = MainDecisionAIModule::object
                                             ((MainDecisionAIModule *)param_1->md,
                                              (param_1->workingArea).value[iVar5]);
                          if ((pRVar9 != (RGE_Static_Object *)0x0) &&
                             (bVar2 = RGE_Static_Object::currentZone(pRVar9),
                             pTStack_18 == (TacticalAIGroup *)(uint)bVar2)) {
                            if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                              piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                              if (piVar8 != (int *)0x0) {
                                iVar6 = 0;
                                if (0 < (param_1->workingArea).maximumSizeValue) {
                                  do {
                                    if (iVar5 + 1 <= iVar6) break;
                                    iVar10 = iVar6 + 1;
                                    piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                    iVar6 = iVar10;
                                  } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                                }
                                operator_delete((param_1->workingArea).value);
                                (param_1->workingArea).value = piVar8;
                                (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                              }
                            }
                            TacticalAIGroup::addUnit
                                      (pTVar12,(param_1->workingArea).value[iVar5],param_1->md);
                          }
                          iVar5 = iVar5 + 1;
                        } while (iVar5 < (param_1->workingArea).numberValue);
                      }
                    }
                    iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                    iVar6 = TacticalAIGroup::numberUnits(pTVar12);
                    if (iVar6 < iVar5) {
                      iVar5 = TribeTacticalAIModule::numberExtraGroupedSoldiers(param_1);
                      iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                      iVar10 = TacticalAIGroup::numberUnits(pTVar12);
                      if (iVar6 - iVar10 < iVar5) {
                        iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                        iVar6 = TacticalAIGroup::numberUnits(pTVar12);
                        if (iVar6 < iVar5) {
                          do {
                            iVar5 = 0;
                            iStack_8 = -1;
                            fStack_10 = -1.0;
                            if (0 < (param_1->workingArea).numberValue) {
                              do {
                                if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                                  piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                                  if (piVar8 != (int *)0x0) {
                                    iVar6 = 0;
                                    if (0 < (param_1->workingArea).maximumSizeValue) {
                                      do {
                                        if (iVar5 + 1 <= iVar6) break;
                                        iVar10 = iVar6 + 1;
                                        piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                        iVar6 = iVar10;
                                      } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                                    }
                                    operator_delete((param_1->workingArea).value);
                                    (param_1->workingArea).value = piVar8;
                                    (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                                  }
                                }
                                pRVar9 = MainDecisionAIModule::object
                                                   ((MainDecisionAIModule *)param_1->md,
                                                    (param_1->workingArea).value[iVar5]);
                                if ((pRVar9 != (RGE_Static_Object *)0x0) &&
                                   (bVar2 = RGE_Static_Object::currentZone(pRVar9),
                                   pTStack_18 == (TacticalAIGroup *)(uint)bVar2)) {
                                  pWVar7 = TacticalAIGroup::gatherLocation(pTVar12);
                                  fVar13 = pWVar7->z;
                                  pWVar7 = TacticalAIGroup::gatherLocation(pTVar12);
                                  fVar14 = pWVar7->y;
                                  pWVar7 = TacticalAIGroup::gatherLocation(pTVar12);
                                  fVar13 = RGE_Static_Object::distance_to_position
                                                     (pRVar9,pWVar7->x,fVar14,fVar13);
                                  if ((fStack_10 == _DAT_00575758) || (fVar13 < fStack_10)) {
                                    if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                                      piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                                      if (piVar8 != (int *)0x0) {
                                        iVar6 = 0;
                                        if (0 < (param_1->workingArea).maximumSizeValue) {
                                          do {
                                            if (iVar5 + 1 <= iVar6) break;
                                            iVar10 = iVar6 + 1;
                                            piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                            iVar6 = iVar10;
                                          } while (iVar10 < (param_1->workingArea).maximumSizeValue)
                                          ;
                                        }
                                        operator_delete((param_1->workingArea).value);
                                        (param_1->workingArea).value = piVar8;
                                        (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                                      }
                                    }
                                    iStack_8 = (param_1->workingArea).value[iVar5];
                                    fStack_10 = fVar13;
                                  }
                                }
                                iVar5 = iVar5 + 1;
                              } while (iVar5 < (param_1->workingArea).numberValue);
                            }
                            if (iStack_8 == -1) break;
                            TribeTacticalAIModule::removeFromGroup(param_1,iStack_8);
                            TacticalAIGroup::addUnit(pTVar12,iStack_8,param_1->md);
                            iVar5 = (param_1->workingArea).maximumSizeValue;
                            iVar6 = 0;
                            if (0 < iVar5) {
                              piVar8 = (param_1->workingArea).value;
                              do {
                                if (*piVar8 == iStack_8) break;
                                iVar6 = iVar6 + 1;
                                piVar8 = piVar8 + 1;
                              } while (iVar6 < iVar5);
                            }
                            if (iVar6 < iVar5) {
                              if (iVar6 < iVar5 + -1) {
                                do {
                                  piVar8 = (param_1->workingArea).value;
                                  iVar5 = iVar6 + 1;
                                  piVar8[iVar6] = piVar8[iVar5];
                                  iVar6 = iVar5;
                                } while (iVar5 < (param_1->workingArea).maximumSizeValue + -1);
                              }
                              iVar5 = (param_1->workingArea).numberValue + -1;
                              (param_1->workingArea).numberValue = iVar5;
                              if (iVar5 < 0) {
                                (param_1->workingArea).numberValue = 0;
                              }
                            }
                            iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                            iVar6 = TacticalAIGroup::numberUnits(pTVar12);
                          } while (iVar6 < iVar5);
                        }
                      }
                      else {
                        iVar5 = 0;
                        if (0 < (param_1->workingArea).numberValue) {
                          do {
                            if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                              piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                              if (piVar8 != (int *)0x0) {
                                iVar6 = 0;
                                if (0 < (param_1->workingArea).maximumSizeValue) {
                                  do {
                                    if (iVar5 + 1 <= iVar6) break;
                                    iVar10 = iVar6 + 1;
                                    piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                    iVar6 = iVar10;
                                  } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                                }
                                operator_delete((param_1->workingArea).value);
                                (param_1->workingArea).value = piVar8;
                                (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                              }
                            }
                            pRVar9 = MainDecisionAIModule::object
                                               ((MainDecisionAIModule *)param_1->md,
                                                (param_1->workingArea).value[iVar5]);
                            if ((pRVar9 != (RGE_Static_Object *)0x0) &&
                               (bVar2 = RGE_Static_Object::currentZone(pRVar9),
                               pTStack_18 == (TacticalAIGroup *)(uint)bVar2)) {
                              if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                                piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                                if (piVar8 != (int *)0x0) {
                                  iVar6 = 0;
                                  if (0 < (param_1->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar5 + 1 <= iVar6) break;
                                      iVar10 = iVar6 + 1;
                                      piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                      iVar6 = iVar10;
                                    } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((param_1->workingArea).value);
                                  (param_1->workingArea).value = piVar8;
                                  (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                                }
                              }
                              TribeTacticalAIModule::removeFromGroup
                                        (param_1,(param_1->workingArea).value[iVar5]);
                              if ((param_1->workingArea).maximumSizeValue + -1 < iVar5) {
                                piVar8 = (int *)operator_new(iVar5 * 4 + 4);
                                if (piVar8 != (int *)0x0) {
                                  iVar6 = 0;
                                  if (0 < (param_1->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar5 + 1 <= iVar6) break;
                                      iVar10 = iVar6 + 1;
                                      piVar8[iVar6] = (param_1->workingArea).value[iVar6];
                                      iVar6 = iVar10;
                                    } while (iVar10 < (param_1->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((param_1->workingArea).value);
                                  (param_1->workingArea).value = piVar8;
                                  (param_1->workingArea).maximumSizeValue = iVar5 + 1;
                                }
                              }
                              TacticalAIGroup::addUnit
                                        (pTVar12,(param_1->workingArea).value[iVar5],param_1->md);
                            }
                            iVar5 = iVar5 + 1;
                          } while (iVar5 < (param_1->workingArea).numberValue);
                        }
                      }
                      pTVar12 = pTVar12->next;
                    }
                    else {
                      pTVar12 = pTVar12->next;
                    }
                  }
                }
                else {
                  pTVar12 = pTVar12->next;
                }
              }
              else {
                pTVar12 = pTVar12->next;
              }
            } while (pTVar12 != &param_1->groups);
          }
          iStack_c = iStack_c + 1;
        } while (iStack_c < 0x67);
      }
      iVar5 = TribeTacticalAIModule::numberUngroupedSoldiers(param_1);
      if ((iVar5 != 0) && (iStack_1c = 0, 0 < (param_1->workingArea).numberValue)) {
        do {
          if ((param_1->workingArea).maximumSizeValue + -1 < iStack_1c) {
            piVar8 = (int *)operator_new(iStack_1c * 4 + 4);
            if (piVar8 != (int *)0x0) {
              iVar5 = 0;
              if (0 < (param_1->workingArea).maximumSizeValue) {
                do {
                  if (iStack_1c + 1 <= iVar5) break;
                  iVar6 = iVar5 + 1;
                  piVar8[iVar5] = (param_1->workingArea).value[iVar5];
                  iVar5 = iVar6;
                } while (iVar6 < (param_1->workingArea).maximumSizeValue);
              }
              operator_delete((param_1->workingArea).value);
              (param_1->workingArea).value = piVar8;
              (param_1->workingArea).maximumSizeValue = iStack_1c + 1;
            }
          }
          pRVar9 = MainDecisionAIModule::object
                             ((MainDecisionAIModule *)param_1->md,
                              (param_1->workingArea).value[iStack_1c]);
          if (pRVar9 != (RGE_Static_Object *)0x0) {
            uVar3 = RGE_Static_Object::currentZone(pRVar9);
            pTVar12 = (param_1->groups).next;
            iVar5 = 0;
            pTStack_18 = (TacticalAIGroup *)0x0;
            if (pTVar12 != &param_1->groups) {
              do {
                if (pTVar12 == (TacticalAIGroup *)0x0) break;
                iVar6 = TacticalAIGroup::type(pTVar12);
                if ((((iVar6 == 100) || (iVar6 = TacticalAIGroup::type(pTVar12), iVar6 == 0x65)) ||
                    (iVar6 = TacticalAIGroup::type(pTVar12), iVar6 == 0x66)) &&
                   (iVar6 = TacticalAIGroup::inUse(pTVar12), iVar6 != 1)) {
                  iVar6 = TacticalAIGroup::commander(pTVar12);
                  pRVar9 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar6);
                  if ((pRVar9 != (RGE_Static_Object *)0x0) &&
                     (uVar4 = RGE_Static_Object::currentZone(pRVar9), uVar3 == uVar4)) {
                    iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                    iVar10 = TacticalAIGroup::numberUnits(pTVar12);
                    if ((iVar10 < iVar6) &&
                       ((iVar6 = TacticalAIGroup::action(pTVar12), iVar6 == 1 ||
                        (iVar6 = TacticalAIGroup::action(pTVar12), iVar6 == 0)))) {
                      iVar6 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                      iVar10 = TacticalAIGroup::numberUnits(pTVar12);
                      if ((pTStack_18 == (TacticalAIGroup *)0x0) || (iVar5 < iVar6 - iVar10)) {
                        iVar5 = iVar6 - iVar10;
                        pTStack_18 = pTVar12;
                      }
                    }
                  }
                }
                pTVar12 = pTVar12->next;
              } while (pTVar12 != &param_1->groups);
            }
            if (pTStack_18 == (TacticalAIGroup *)0x0) {
              pTVar12 = (param_1->groups).next;
              pTStack_18 = (TacticalAIGroup *)0x0;
              iStack_4 = 0;
              pTVar11 = (TacticalAIGroup *)0x0;
              pTVar1 = pTStack_18;
              for (; (pTStack_18 = pTVar11, pTVar12 != &param_1->groups &&
                     (pTVar12 != (TacticalAIGroup *)0x0)); pTVar12 = pTVar12->next) {
                iVar5 = TacticalAIGroup::type(pTVar12);
                pTVar11 = pTStack_18;
                if (((((iVar5 == 100) ||
                      ((iVar5 = TacticalAIGroup::type(pTVar12), iVar5 == 0x65 ||
                       (iVar5 = TacticalAIGroup::type(pTVar12), iVar5 == 0x66)))) &&
                     (iVar5 = TacticalAIGroup::inUse(pTVar12), iVar5 != 1)) &&
                    (((iVar5 = TacticalAIGroup::action(pTVar12), iVar5 == 1 ||
                      (iVar5 = TacticalAIGroup::action(pTVar12), iVar5 == 0)) &&
                     ((iVar5 = TacticalAIGroup::type(pTVar12), iVar5 != 100 ||
                      (iVar5 = TacticalAIGroup::numberUnits(pTVar12), iVar5 < param_1->sn[0x1a])))))
                    ) && (((iVar5 = TacticalAIGroup::type(pTVar12), iVar5 != 0x65 ||
                           (iVar5 = TacticalAIGroup::numberUnits(pTVar12), iVar5 < param_1->sn[0x1c]
                           )) && ((iVar5 = TacticalAIGroup::type(pTVar12), iVar5 != 0x66 ||
                                  (iVar5 = TacticalAIGroup::numberUnits(pTVar12),
                                  iVar5 < param_1->sn[0x2c])))))) {
                  iVar5 = TacticalAIGroup::commander(pTVar12);
                  pRVar9 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar5);
                  if ((pRVar9 != (RGE_Static_Object *)0x0) &&
                     (uVar4 = RGE_Static_Object::currentZone(pRVar9), uVar4 == uVar3)) {
                    iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar12);
                    iVar6 = TacticalAIGroup::numberUnits(pTVar12);
                    if ((pTVar1 == (TacticalAIGroup *)0x0) ||
                       (pTVar11 = pTVar1, iVar6 - iVar5 < iStack_4)) {
                      pTVar11 = pTVar12;
                      pTVar1 = pTVar12;
                      iStack_4 = iVar6 - iVar5;
                    }
                  }
                }
                pTStack_18 = pTVar1;
                pTVar1 = pTStack_18;
              }
              if (pTStack_18 == (TacticalAIGroup *)0x0) {
                return;
              }
              if ((param_1->workingArea).maximumSizeValue + -1 < iStack_1c) {
                piVar8 = (int *)operator_new(iStack_1c * 4 + 4);
                if (piVar8 != (int *)0x0) {
                  iVar5 = 0;
                  if (0 < (param_1->workingArea).maximumSizeValue) {
                    do {
                      if (iStack_1c + 1 <= iVar5) break;
                      iVar6 = iVar5 + 1;
                      piVar8[iVar5] = (param_1->workingArea).value[iVar5];
                      iVar5 = iVar6;
                    } while (iVar6 < (param_1->workingArea).maximumSizeValue);
                  }
                  operator_delete((param_1->workingArea).value);
                  (param_1->workingArea).value = piVar8;
                  (param_1->workingArea).maximumSizeValue = iStack_1c + 1;
                }
              }
              pTVar15 = param_1->md;
              iVar5 = (param_1->workingArea).value[iStack_1c];
            }
            else {
              if ((param_1->workingArea).maximumSizeValue + -1 < iStack_1c) {
                piVar8 = (int *)operator_new(iStack_1c * 4 + 4);
                if (piVar8 != (int *)0x0) {
                  iVar5 = 0;
                  if (0 < (param_1->workingArea).maximumSizeValue) {
                    do {
                      if (iStack_1c + 1 <= iVar5) break;
                      iVar6 = iVar5 + 1;
                      piVar8[iVar5] = (param_1->workingArea).value[iVar5];
                      iVar5 = iVar6;
                    } while (iVar6 < (param_1->workingArea).maximumSizeValue);
                  }
                  operator_delete((param_1->workingArea).value);
                  (param_1->workingArea).value = piVar8;
                  (param_1->workingArea).maximumSizeValue = iStack_1c + 1;
                }
              }
              pTVar15 = param_1->md;
              iVar5 = (param_1->workingArea).value[iStack_1c];
            }
            TacticalAIGroup::addUnit(pTStack_18,iVar5,pTVar15);
          }
          iStack_1c = iStack_1c + 1;
        } while (iStack_1c < (param_1->workingArea).numberValue);
      }
      return;
    }
    iVar5 = TacticalAIGroup::type(pTVar12);
    if (((iVar5 == 100) ||
        ((iVar5 = TacticalAIGroup::type(pTVar12), iVar5 == 0x65 ||
         (iVar5 = TacticalAIGroup::type(pTVar12), iVar5 == 0x66)))) &&
       (iVar5 = TacticalAIGroup::commander(pTVar12), iVar5 == -1)) {
      iVar5 = TribeTacticalAIModule::numberUngroupedSoldiers(param_1);
      iVar6 = TacticalAIGroup::numberUnits(pTVar12);
      if (iVar6 < 1) {
        if (iVar5 == 0) {
          TribeTacticalAIModule::numberExtraGroupedSoldiers(param_1);
        }
        if ((param_1->workingArea).numberValue == 0) {
          return;
        }
        iVar5 = TribeTacticalAIModule::selectBestCommander(param_1,&param_1->workingArea);
        TacticalAIGroup::addUnit(pTVar12,iVar5,param_1->md);
        TacticalAIGroup::setSpecificCommander(pTVar12,iVar5,param_1->md);
        iVar5 = TacticalAIGroup::action(pTVar12);
        if (iVar5 != 0) {
          iVar5 = TacticalAIGroup::action(pTVar12);
          goto joined_r0x004fc609;
        }
      }
      else {
        iVar5 = TribeTacticalAIModule::selectBestCommander(param_1,pTVar12);
        TacticalAIGroup::setSpecificCommander(pTVar12,iVar5,param_1->md);
        iVar5 = TacticalAIGroup::action(pTVar12);
        if (iVar5 != 0) {
          iVar5 = TacticalAIGroup::action(pTVar12);
joined_r0x004fc609:
          if (iVar5 != 1) goto LAB_004fc613;
        }
      }
      TribeTacticalAIModule::setAllGroupLocations(param_1,pTVar12);
    }
LAB_004fc613:
    pTVar12 = pTVar12->next;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004fd2e2
// Address: 004fd2e2
// XREFS: None
int __fastcall FUN_004fd2e2(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  int iStack_4;
  
  iStack_c = 0;
  iStack_4 = 0;
  (param_1->workingArea).numberValue = 0;
  if (0 < (param_1->soldiers).numberValue) {
    do {
      if ((param_1->soldiers).maximumSizeValue + -1 < iStack_4) {
        piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->soldiers).maximumSizeValue) {
            do {
              if (iStack_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (param_1->soldiers).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (param_1->soldiers).maximumSizeValue);
          }
          operator_delete((param_1->soldiers).value);
          (param_1->soldiers).value = piVar1;
          (param_1->soldiers).maximumSizeValue = iStack_4 + 1;
        }
      }
      pTVar3 = TribeTacticalAIModule::groupUnitIsIn(param_1,(param_1->soldiers).value[iStack_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((param_1->soldiers).maximumSizeValue + -1 < iStack_4) {
          piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->soldiers).maximumSizeValue) {
              do {
                if (iStack_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (param_1->soldiers).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (param_1->soldiers).maximumSizeValue);
            }
            operator_delete((param_1->soldiers).value);
            (param_1->soldiers).value = piVar1;
            (param_1->soldiers).maximumSizeValue = iStack_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (param_1->soldiers).value[iStack_4];
        iVar4 = (param_1->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((param_1->workingArea).maximumSizeValue <= iVar5) break;
            if ((param_1->workingArea).value[iVar5] == iVar2) goto LAB_004fd4c2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((param_1->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (param_1->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar1;
            (param_1->workingArea).maximumSizeValue = iVar4;
          }
        }
        (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar2;
        (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004fd4c2:
        iStack_c = iStack_c + 1;
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < (param_1->soldiers).numberValue);
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004fd4ee
// Address: 004fd4ee
// XREFS: None
int __fastcall FUN_004fd4ee(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  TacticalAIGroup *this;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  *(undefined4 *)(param_1 + 0xd4c) = 0;
  this = *(TacticalAIGroup **)(param_1 + 0x9d8);
  if (this != (TacticalAIGroup *)(param_1 + 0x9d4)) {
    do {
      if (this == (TacticalAIGroup *)0x0) {
        return iStack_8;
      }
      iVar1 = TacticalAIGroup::type(this);
      if ((((iVar1 == 100) || (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x65)) ||
          (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x66)) &&
         ((iVar1 = TacticalAIGroup::action(this), iVar1 == 1 ||
          (iVar1 = TacticalAIGroup::action(this), iVar1 == 0)))) {
        iVar1 = TacticalAIGroup::desiredNumberUnits(this);
        iVar2 = TacticalAIGroup::numberUnits(this);
        if (iVar1 < iVar2) {
          iStack_c = TacticalAIGroup::numberUnits(this);
          iStack_10 = 0;
          iVar1 = TacticalAIGroup::desiredNumberUnits(this);
          if (iVar1 < iStack_c) {
            do {
              iVar1 = TacticalAIGroup::numberUnits(this);
              if (iVar1 <= iStack_10) break;
              iVar1 = TacticalAIGroup::unit(this,iStack_10);
              iVar2 = TacticalAIGroup::commander(this);
              if (iVar1 != iVar2) {
                iStack_c = iStack_c + -1;
                iVar2 = TacticalAIGroup::unit(this,iStack_10);
                iVar1 = *(int *)(param_1 + 0xd4c);
                iVar3 = 0;
                if (0 < iVar1) {
                  do {
                    if (*(int *)(param_1 + 0xd54) <= iVar3) break;
                    if (*(int *)(*(int *)(param_1 + 0xd48) + iVar3 * 4) == iVar2) goto LAB_004fd692;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < iVar1);
                }
                if (*(int *)(param_1 + 0xd54) + -1 < iVar1) {
                  iVar1 = iVar1 + 1;
                  pvVar4 = operator_new(iVar1 * 4);
                  if (pvVar4 != (void *)0x0) {
                    iVar3 = 0;
                    if (0 < *(int *)(param_1 + 0xd54)) {
                      do {
                        if (iVar1 <= iVar3) break;
                        iVar3 = iVar3 + 1;
                        *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
                             *(undefined4 *)(*(int *)(param_1 + 0xd48) + -4 + iVar3 * 4);
                      } while (iVar3 < *(int *)(param_1 + 0xd54));
                    }
                    operator_delete(*(void **)(param_1 + 0xd48));
                    *(void **)(param_1 + 0xd48) = pvVar4;
                    *(int *)(param_1 + 0xd54) = iVar1;
                  }
                }
                *(int *)(*(int *)(param_1 + 0xd48) + *(int *)(param_1 + 0xd4c) * 4) = iVar2;
                *(int *)(param_1 + 0xd4c) = *(int *)(param_1 + 0xd4c) + 1;
LAB_004fd692:
                iStack_8 = iStack_8 + 1;
              }
              iStack_10 = iStack_10 + 1;
              iVar1 = TacticalAIGroup::desiredNumberUnits(this);
            } while (iVar1 < iStack_c);
          }
        }
      }
      this = this->next;
    } while (this != (TacticalAIGroup *)(param_1 + 0x9d4));
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_004fd6c9
// Address: 004fd6c9
// XREFS: None
int __fastcall FUN_004fd6c9(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  int iStack_4;
  
  iStack_c = 0;
  iStack_4 = 0;
  (param_1->workingArea).numberValue = 0;
  if (0 < (param_1->artifacts).numberValue) {
    do {
      if ((param_1->artifacts).maximumSizeValue + -1 < iStack_4) {
        piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->artifacts).maximumSizeValue) {
            do {
              if (iStack_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (param_1->artifacts).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (param_1->artifacts).maximumSizeValue);
          }
          operator_delete((param_1->artifacts).value);
          (param_1->artifacts).value = piVar1;
          (param_1->artifacts).maximumSizeValue = iStack_4 + 1;
        }
      }
      pTVar3 = TribeTacticalAIModule::groupUnitIsIn(param_1,(param_1->artifacts).value[iStack_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((param_1->artifacts).maximumSizeValue + -1 < iStack_4) {
          piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->artifacts).maximumSizeValue) {
              do {
                if (iStack_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (param_1->artifacts).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (param_1->artifacts).maximumSizeValue);
            }
            operator_delete((param_1->artifacts).value);
            (param_1->artifacts).value = piVar1;
            (param_1->artifacts).maximumSizeValue = iStack_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (param_1->artifacts).value[iStack_4];
        iVar4 = (param_1->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((param_1->workingArea).maximumSizeValue <= iVar5) break;
            if ((param_1->workingArea).value[iVar5] == iVar2) goto LAB_004fd8a2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((param_1->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (param_1->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar1;
            (param_1->workingArea).maximumSizeValue = iVar4;
          }
        }
        (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar2;
        (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004fd8a2:
        iStack_c = iStack_c + 1;
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < (param_1->artifacts).numberValue);
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004fd8ce
// Address: 004fd8ce
// XREFS: None
// [HELPER] s_____AssistGroupID__d__AssistGrou: "    AssistGroupID=%d, AssistGroupType=%d, ConsecIdleCount=%ld."
// [HELPER] s_____Current_waypoints__d_: "    Current waypoints=%d."
// [HELPER] s_____NumUnits__d__DesNumUnits__d_: "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d."
// [HELPER] s_____NumberObjectsToDestroy__d_: "    NumberObjectsToDestroy=%d."
// [HELPER] s_____Play__d_: "    Play=%d."
// [HELPER] s_____Target__d__CommanderID__d__H: "    Target=%d, CommanderID=%d, HP(%d/%d), AssistGroup=%d."
// [HELPER] s_____Unit__d___s___state__d__acti: "    Unit %d (%s): state=%d, action=%d, target=%d, order=%d, pri=%d, loc=(%3f,..."
// [HELPER] s_______ObjectToDestroy___d___Unit: "      ObjectToDestroy #%d:  Unit #%d, but it's gone."
void __fastcall FUN_004fd8ce(AIModule *param_1)
{
  uchar uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  ulong uVar6;
  UnitAIModule *pUVar7;
  int iVar8;
  int iVar9;
  AIModule *extraout_ECX;
  AIModule *extraout_ECX_00;
  AIModule *extraout_ECX_01;
  AIModule *extraout_ECX_02;
  AIModule *this;
  AIModule *this_00;
  AIModule *this_01;
  AIModule *this_02;
  AIModule *this_03;
  AIModule *this_04;
  AIModule *this_05;
  AIModule *this_06;
  AIModule *this_07;
  AIModule *this_08;
  AIModule *this_09;
  AIModule *this_10;
  AIModule *this_11;
  AIModule *this_12;
  AIModule *this_13;
  AIModule *this_14;
  AIModule *this_15;
  AIModule *this_16;
  uint uVar10;
  TacticalAIGroup *this_17;
  char *pcVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  AIModule::logCommonHistory(param_1,(char *)param_1);
  this_17 = *(TacticalAIGroup **)(param_1[10].playerNameValue + 0x28);
  if (this_17 != (TacticalAIGroup *)(param_1[10].playerNameValue + 0x24)) {
    do {
      if (this_17 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar3 = TacticalAIGroup::type(this_17);
      if ((((iVar3 == 100) || (iVar3 = TacticalAIGroup::type(this_17), iVar3 == 0x65)) ||
          (iVar3 = TacticalAIGroup::type(this_17), iVar3 == 0x66)) ||
         (iVar3 = TacticalAIGroup::type(this_17), iVar3 == 0x6d)) {
        iVar3 = TacticalAIGroup::type(this_17);
        if (iVar3 == 100) {
          TacticalAIGroup::type(this_17);
          TacticalAIGroup::id(this_17);
          this = extraout_ECX;
LAB_004fd9b8:
          AIModule::logCommonHistory(this,(char *)param_1);
        }
        else {
          iVar3 = TacticalAIGroup::type(this_17);
          if (iVar3 == 0x65) {
            TacticalAIGroup::type(this_17);
            TacticalAIGroup::id(this_17);
            this = extraout_ECX_00;
            goto LAB_004fd9b8;
          }
          iVar3 = TacticalAIGroup::type(this_17);
          if (iVar3 == 0x66) {
            TacticalAIGroup::type(this_17);
            TacticalAIGroup::id(this_17);
            this = extraout_ECX_01;
            goto LAB_004fd9b8;
          }
          iVar3 = TacticalAIGroup::type(this_17);
          if (iVar3 == 0x6d) {
            TacticalAIGroup::type(this_17);
            TacticalAIGroup::id(this_17);
            this = extraout_ECX_02;
            goto LAB_004fd9b8;
          }
        }
        iVar3 = TacticalAIGroup::inUse(this_17);
        iVar4 = TacticalAIGroup::action(this_17);
        uVar13 = CONCAT44(iVar3,iVar4);
        iVar3 = TacticalAIGroup::originalUnitNumber(this_17);
        iVar4 = TacticalAIGroup::desiredNumberUnits(this_17);
        uVar12 = CONCAT44(iVar3,iVar4);
        iVar3 = TacticalAIGroup::numberUnits(this_17);
        AIModule::logCommonHistory
                  (this_00,(char *)param_1,s_____NumUnits__d__DesNumUnits__d_,iVar3,uVar12,uVar13);
        iVar3 = TacticalAIGroup::target(this_17);
        pRVar5 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1[1]._padding_,iVar3);
        if (pRVar5 == (RGE_Static_Object *)0x0) {
          iVar3 = TacticalAIGroup::waitCode(this_17);
          iVar4 = TacticalAIGroup::originalHitPoints(this_17);
          uVar13 = CONCAT44(iVar3,iVar4);
          iVar3 = TacticalAIGroup::currentHitPoints
                            (this_17,(TribeMainDecisionAIModule *)param_1[1]._padding_);
          iVar4 = TacticalAIGroup::commander(this_17);
          uVar12 = CONCAT44(iVar3,iVar4);
          iVar3 = TacticalAIGroup::target(this_17);
          AIModule::logCommonHistory
                    (this_02,(char *)param_1,s_____Target__d__CommanderID__d__H,iVar3,uVar12,uVar13)
          ;
        }
        else {
          TacticalAIGroup::waitCode(this_17);
          TacticalAIGroup::originalHitPoints(this_17);
          TacticalAIGroup::currentHitPoints
                    (this_17,(TribeMainDecisionAIModule *)param_1[1]._padding_);
          TacticalAIGroup::commander(this_17);
          TacticalAIGroup::target(this_17);
          AIModule::logCommonHistory(this_01,(char *)param_1);
        }
        uVar6 = TacticalAIGroup::consecutiveIdleUnitCount(this_17);
        iVar3 = TacticalAIGroup::assistGroupType(this_17);
        uVar12 = CONCAT44(uVar6,iVar3);
        iVar3 = TacticalAIGroup::assistGroupID(this_17);
        AIModule::logCommonHistory
                  (this_03,(char *)param_1,s_____AssistGroupID__d__AssistGrou,iVar3,uVar12);
        TacticalAIGroup::location(this_17);
        TacticalAIGroup::location(this_17);
        AIModule::logCommonHistory(this_04,(char *)param_1);
        TacticalAIGroup::gatherLocation(this_17);
        TacticalAIGroup::gatherLocation(this_17);
        AIModule::logCommonHistory(this_05,(char *)param_1);
        TacticalAIGroup::retreatLocation(this_17);
        TacticalAIGroup::retreatLocation(this_17);
        AIModule::logCommonHistory(this_06,(char *)param_1);
        TacticalAIGroup::targetLocation(this_17);
        TacticalAIGroup::targetLocation(this_17);
        AIModule::logCommonHistory(this_07,(char *)param_1);
        AIModule::logCommonHistory
                  ((AIModule *)this_17->playNumberValue,(char *)param_1,s_____Play__d_);
        AIModule::logCommonHistory(this_08,(char *)param_1,s_____NumberObjectsToDestroy__d_);
        if ((0 < this_17->numberObjectsToDestroyValue) &&
           (iVar3 = 0, 0 < this_17->numberObjectsToDestroyValue)) {
          do {
            iVar4 = TacticalAIGroup::objectToDestroy(this_17,iVar3);
            pRVar5 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1[1]._padding_,iVar4);
            if (pRVar5 == (RGE_Static_Object *)0x0) {
              TacticalAIGroup::objectToDestroy(this_17,iVar3);
              AIModule::logCommonHistory(this_09,(char *)param_1);
            }
            else {
              iVar4 = TacticalAIGroup::objectToDestroy(this_17,iVar3);
              AIModule::logCommonHistory
                        (this_10,(char *)param_1,s_______ObjectToDestroy___d___Unit,iVar3,iVar4);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < this_17->numberObjectsToDestroyValue);
        }
        iVar4 = 0;
        iVar3 = TacticalAIGroup::numberUnits(this_17);
        if (0 < iVar3) {
          do {
            iVar3 = TacticalAIGroup::unit(this_17,iVar4);
            pRVar5 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1[1]._padding_,iVar3);
            if (pRVar5 == (RGE_Static_Object *)0x0) {
              AIModule::logCommonHistory(this_11,(char *)param_1);
            }
            else {
              pUVar7 = RGE_Static_Object::unitAI(pRVar5);
              if (pUVar7 == (UnitAIModule *)0x0) {
                AIModule::logCommonHistory(this_12,(char *)param_1);
              }
              else {
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                UnitAIModule::currentTargetY(pUVar7);
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                UnitAIModule::currentTargetX(pUVar7);
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                UnitAIModule::currentOrderPriority(pUVar7);
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                UnitAIModule::currentOrder(pUVar7);
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                iVar3 = UnitAIModule::currentTarget(pUVar7);
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                iVar8 = UnitAIModule::currentAction(pUVar7);
                uVar10 = (uint)pRVar5->object_state;
                pcVar11 = pRVar5->master_obj->name;
                iVar9 = TacticalAIGroup::unit(this_17,iVar4);
                AIModule::logCommonHistory
                          (this_13,(char *)param_1,s_____Unit__d___s___state__d__acti,iVar9,pcVar11,
                           uVar10,iVar8,iVar3);
                pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                iVar3 = UnitAIModule::currentTarget(pUVar7);
                if (iVar3 != -1) {
                  pUVar7 = RGE_Static_Object::unitAI(pRVar5);
                  iVar3 = UnitAIModule::currentTarget(pUVar7);
                  pRVar5 = MainDecisionAIModule::object
                                     ((MainDecisionAIModule *)param_1[1]._padding_,iVar3);
                  if (pRVar5 != (RGE_Static_Object *)0x0) {
                    AIModule::logCommonHistory((AIModule *)(int)pRVar5->owner->id,(char *)param_1);
                  }
                }
              }
            }
            iVar4 = iVar4 + 1;
            iVar3 = TacticalAIGroup::numberUnits(this_17);
          } while (iVar4 < iVar3);
        }
        uVar1 = TacticalAIGroup::numberAttackWaypoints(this_17);
        if (uVar1 == '\0') {
          AIModule::logCommonHistory(this_14,(char *)param_1);
        }
        else {
          AIModule::logCommonHistory(this_14,(char *)param_1);
          iVar3 = 0;
          uVar1 = TacticalAIGroup::numberAttackWaypoints(this_17);
          if (uVar1 != '\0') {
            do {
              TacticalAIGroup::attackWaypoint(this_17,(uchar)iVar3);
              TacticalAIGroup::attackWaypoint(this_17,(uchar)iVar3);
              AIModule::logCommonHistory(this_15,(char *)param_1);
              iVar3 = iVar3 + 1;
              bVar2 = TacticalAIGroup::numberAttackWaypoints(this_17);
            } while (iVar3 < (int)(uint)bVar2);
          }
          TacticalAIGroup::currentAttackWaypoint(this_17);
          AIModule::logCommonHistory(this_16,(char *)param_1,s_____Current_waypoints__d_);
        }
      }
      this_17 = this_17->next;
    } while (this_17 != (TacticalAIGroup *)(param_1[10].playerNameValue + 0x24));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004fddfc
// Address: 004fddfc
// XREFS: None
void __fastcall FUN_004fddfc(TribeTacticalAIModule *param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  TacticalAIGroup *pTVar8;
  undefined4 *unaff_FS_OFFSET;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  ManagedArray<int> MStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00560b68;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  MStack_1c.value = (int *)0x0;
  MStack_1c.numberValue = 0;
  MStack_1c.desiredNumberValue = 0;
  MStack_1c.maximumSizeValue = 0;
  pTVar8 = (param_1->groups).next;
  uStack_4 = 0;
  while ((pTVar8 != &param_1->groups && (pTVar8 != (TacticalAIGroup *)0x0))) {
    iVar1 = TacticalAIGroup::type(pTVar8);
    if ((iVar1 == 0x67) ||
       ((iVar1 = TacticalAIGroup::type(pTVar8), iVar1 == 0x68 ||
        (iVar1 = TacticalAIGroup::type(pTVar8), iVar1 == 0x69)))) {
      iVar1 = TacticalAIGroup::numberUnits(pTVar8);
      if (iVar1 == 0) {
        iVar1 = TacticalAIGroup::id(pTVar8);
        iVar3 = 0;
        piVar2 = MStack_1c.value;
        if (0 < MStack_1c.numberValue) {
          do {
            if (MStack_1c.maximumSizeValue <= iVar3) break;
            if (*piVar2 == iVar1) goto LAB_004fdedf;
            iVar3 = iVar3 + 1;
            piVar2 = piVar2 + 1;
          } while (iVar3 < MStack_1c.numberValue);
        }
        if (MStack_1c.maximumSizeValue + -1 < MStack_1c.numberValue) {
          ManagedArray<int>::resize(&MStack_1c,MStack_1c.numberValue + 1);
        }
        MStack_1c.value[MStack_1c.numberValue] = iVar1;
        MStack_1c.numberValue = MStack_1c.numberValue + 1;
      }
LAB_004fdedf:
      pTVar8 = pTVar8->next;
    }
    else {
      pTVar8 = pTVar8->next;
    }
  }
  iStack_38 = 0;
  if (0 < MStack_1c.numberValue) {
    do {
      if (MStack_1c.maximumSizeValue + -1 < iStack_38) {
        piVar2 = (int *)operator_new(iStack_38 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar1 = 0;
          if (0 < MStack_1c.maximumSizeValue) {
            do {
              if (iStack_38 + 1 <= iVar1) break;
              iVar3 = iVar1 + 1;
              piVar2[iVar1] = MStack_1c.value[iVar1];
              iVar1 = iVar3;
            } while (iVar3 < MStack_1c.maximumSizeValue);
          }
          operator_delete(MStack_1c.value);
          MStack_1c.value = piVar2;
          MStack_1c.maximumSizeValue = iStack_38 + 1;
        }
      }
      TribeTacticalAIModule::removeGroup(param_1,MStack_1c.value[iStack_38]);
      iStack_38 = iStack_38 + 1;
    } while (iStack_38 < MStack_1c.numberValue);
  }
  iVar3 = TribeTacticalAIModule::numberGroups(param_1,0x67,-1);
  iVar4 = TribeTacticalAIModule::numberGroups(param_1,0x68,-1);
  iStack_34 = TribeTacticalAIModule::numberGroups(param_1,0x69,-1);
  TribeTacticalAIModule::numberGroups(param_1,0x6b,-1);
  TribeTacticalAIModule::numberGroups(param_1,0x6c,-1);
  TribeTacticalAIModule::numberGroups(param_1,0x6a,-1);
  TribeTacticalAIModule::numberUngroupedFishingBoats(param_1);
  iVar1 = (param_1->workingArea).numberValue;
  while (0 < iVar1) {
    if ((param_1->workingArea).maximumSizeValue + -1 < iStack_38) {
      iVar1 = iStack_38 + 1;
      piVar2 = (int *)operator_new(iVar1 * 4);
      if (piVar2 != (int *)0x0) {
        iVar7 = 0;
        if (0 < (param_1->workingArea).maximumSizeValue) {
          do {
            if (iVar1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar2[iVar7] = (param_1->workingArea).value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (param_1->workingArea).maximumSizeValue);
        }
        operator_delete((param_1->workingArea).value);
        (param_1->workingArea).value = piVar2;
        (param_1->workingArea).maximumSizeValue = iVar1;
      }
    }
    iVar1 = (param_1->workingArea).value[iStack_38];
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar1);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      iVar7 = (param_1->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar2 = (param_1->workingArea).value;
        do {
          if (*piVar2 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar2 = (param_1->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar2[iVar5] = piVar2[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (param_1->workingArea).numberValue + -1;
        (param_1->workingArea).numberValue = iVar1;
joined_r0x004fe183:
        if (iVar1 < 0) {
          (param_1->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pTVar8 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x6b);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,param_1->sn[0x41] + 1);
      TacticalAIGroup::addUnit(pTVar8,iVar1,param_1->md);
      TacticalAIGroup::setSpecificCommander(pTVar8,iVar1,param_1->md);
      TacticalAIGroup::setLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setGatherLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setRetreatLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      iVar7 = (param_1->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar2 = (param_1->workingArea).value;
        do {
          if (*piVar2 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar2 = (param_1->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar2[iVar5] = piVar2[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (param_1->workingArea).numberValue + -1;
        (param_1->workingArea).numberValue = iVar1;
        goto joined_r0x004fe183;
      }
    }
    iVar1 = (param_1->workingArea).numberValue;
  }
  TribeTacticalAIModule::numberUngroupedTradeBoats(param_1);
  iVar1 = (param_1->workingArea).numberValue;
  while (0 < iVar1) {
    if ((param_1->workingArea).maximumSizeValue + -1 < iStack_38) {
      iVar1 = iStack_38 + 1;
      piVar2 = (int *)operator_new(iVar1 * 4);
      if (piVar2 != (int *)0x0) {
        iVar7 = 0;
        if (0 < (param_1->workingArea).maximumSizeValue) {
          do {
            if (iVar1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar2[iVar7] = (param_1->workingArea).value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (param_1->workingArea).maximumSizeValue);
        }
        operator_delete((param_1->workingArea).value);
        (param_1->workingArea).value = piVar2;
        (param_1->workingArea).maximumSizeValue = iVar1;
      }
    }
    iVar1 = (param_1->workingArea).value[iStack_38];
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar1);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      iVar7 = (param_1->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar2 = (param_1->workingArea).value;
        do {
          if (*piVar2 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar2 = (param_1->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar2[iVar5] = piVar2[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (param_1->workingArea).numberValue + -1;
        (param_1->workingArea).numberValue = iVar1;
joined_r0x004fe366:
        if (iVar1 < 0) {
          (param_1->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pTVar8 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x6c);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,param_1->sn[0x40] + 1);
      TacticalAIGroup::addUnit(pTVar8,iVar1,param_1->md);
      TacticalAIGroup::setSpecificCommander(pTVar8,iVar1,param_1->md);
      TacticalAIGroup::setLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setGatherLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setRetreatLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      iVar7 = (param_1->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar2 = (param_1->workingArea).value;
        do {
          if (*piVar2 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar2 = (param_1->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar2[iVar5] = piVar2[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (param_1->workingArea).numberValue + -1;
        (param_1->workingArea).numberValue = iVar1;
        goto joined_r0x004fe366;
      }
    }
    iVar1 = (param_1->workingArea).numberValue;
  }
  TribeTacticalAIModule::numberUngroupedTransportBoats(param_1);
  iVar1 = (param_1->workingArea).numberValue;
  while (0 < iVar1) {
    if ((param_1->workingArea).maximumSizeValue + -1 < iStack_38) {
      iVar1 = iStack_38 + 1;
      piVar2 = (int *)operator_new(iVar1 * 4);
      if (piVar2 != (int *)0x0) {
        iVar7 = 0;
        if (0 < (param_1->workingArea).maximumSizeValue) {
          do {
            if (iVar1 <= iVar7) break;
            iVar5 = iVar7 + 1;
            piVar2[iVar7] = (param_1->workingArea).value[iVar7];
            iVar7 = iVar5;
          } while (iVar5 < (param_1->workingArea).maximumSizeValue);
        }
        operator_delete((param_1->workingArea).value);
        (param_1->workingArea).value = piVar2;
        (param_1->workingArea).maximumSizeValue = iVar1;
      }
    }
    iVar1 = (param_1->workingArea).value[iStack_38];
    pRVar6 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar1);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      iVar7 = (param_1->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar2 = (param_1->workingArea).value;
        do {
          if (*piVar2 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar2 = (param_1->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar2[iVar5] = piVar2[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (param_1->workingArea).numberValue + -1;
        (param_1->workingArea).numberValue = iVar1;
joined_r0x004fe549:
        if (iVar1 < 0) {
          (param_1->workingArea).numberValue = 0;
        }
      }
    }
    else {
      pTVar8 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x6a);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,param_1->sn[0x42] + 1);
      TacticalAIGroup::addUnit(pTVar8,iVar1,param_1->md);
      TacticalAIGroup::setSpecificCommander(pTVar8,iVar1,param_1->md);
      TacticalAIGroup::setLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setGatherLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      TacticalAIGroup::setRetreatLocation(pTVar8,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z);
      iVar7 = (param_1->workingArea).maximumSizeValue;
      iVar5 = 0;
      if (0 < iVar7) {
        piVar2 = (param_1->workingArea).value;
        do {
          if (*piVar2 == iVar1) break;
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar5 < iVar7);
      }
      if (iVar5 < iVar7) {
        if (iVar5 < iVar7 + -1) {
          do {
            piVar2 = (param_1->workingArea).value;
            iVar1 = iVar5 + 1;
            piVar2[iVar5] = piVar2[iVar1];
            iVar5 = iVar1;
          } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
        }
        iVar1 = (param_1->workingArea).numberValue + -1;
        (param_1->workingArea).numberValue = iVar1;
        goto joined_r0x004fe549;
      }
    }
    iVar1 = (param_1->workingArea).numberValue;
  }
  if (((param_1->boats).maximumSizeValue + -1 < 0) &&
     (piVar2 = (int *)operator_new(4), piVar2 != (int *)0x0)) {
    iVar1 = 0;
    if (0 < (param_1->boats).maximumSizeValue) {
      do {
        if (0 < iVar1) break;
        iVar7 = iVar1 + 1;
        piVar2[iVar1] = (param_1->boats).value[iVar1];
        iVar1 = iVar7;
      } while (iVar7 < (param_1->boats).maximumSizeValue);
    }
    operator_delete((param_1->boats).value);
    (param_1->boats).value = piVar2;
    (param_1->boats).maximumSizeValue = 1;
  }
  iVar1 = TribeInformationAIModule::fullyExploredZone
                    (&param_1->md->informationAI,*(param_1->boats).value);
  if (iVar1 == 0) {
    TribeTacticalAIModule::removeAllGroups(param_1,0x69);
    TribeTacticalAIModule::setStrategicNumber(param_1,0x3d,0);
  }
  iStack_38 = 0;
  iStack_2c = 0;
  if (param_1->sn[0x28] == 0) {
    ceil((double)(param_1->warBoats).numberValue / (double)param_1->sn[0x3b]);
    iStack_30 = __ftol();
    if (param_1->sn[0x3a] < iStack_30) {
      iStack_30 = param_1->sn[0x3a];
    }
    iVar7 = iStack_30 * param_1->sn[0x3b];
    iVar1 = (param_1->warBoats).numberValue - iVar7;
    if (0 < iVar1) {
      ceil((double)iVar1 / (double)param_1->sn[0x44]);
      iStack_38 = __ftol();
      if (param_1->sn[0x43] < iStack_38) {
        iStack_38 = param_1->sn[0x43];
      }
      iVar1 = ((param_1->warBoats).numberValue - iVar7) - iStack_38 * param_1->sn[0x44];
      if (0 < iVar1) {
        ceil((double)iVar1 / (double)param_1->sn[0x3e]);
        iStack_2c = __ftol();
        if (param_1->sn[0x3d] < iStack_2c) {
          iStack_2c = param_1->sn[0x3d];
        }
      }
    }
  }
  else {
    iVar1 = (param_1->warBoats).numberValue;
    iStack_30 = iVar1;
    if (param_1->sn[0x3a] <= iVar1) {
      iStack_30 = param_1->sn[0x3a];
    }
    iVar1 = iVar1 - iStack_30;
    if (0 < iVar1) {
      iStack_38 = param_1->sn[0x43];
      if (iVar1 < param_1->sn[0x43]) {
        iStack_38 = iVar1;
      }
      iVar1 = iVar1 - iStack_38;
      if ((0 < iVar1) && (iStack_2c = iVar1, param_1->sn[0x3d] <= iVar1)) {
        iStack_2c = param_1->sn[0x3d];
      }
    }
  }
  for (; iVar3 < iStack_30; iVar3 = iVar3 + 1) {
    pTVar8 = (TacticalAIGroup *)0x0;
    if (iVar4 < 1) {
LAB_004fe76d:
      if (pTVar8 == (TacticalAIGroup *)0x0) goto LAB_004fe771;
    }
    else {
      pTVar8 = TribeTacticalAIModule::group(param_1,-1,0x68,-1,-1);
      if (pTVar8 != (TacticalAIGroup *)0x0) {
        iVar4 = iVar4 + -1;
        goto LAB_004fe76d;
      }
      pTVar8 = TribeTacticalAIModule::group(param_1,-1,0x69,-1,-1);
      if (pTVar8 != (TacticalAIGroup *)0x0) {
        iStack_34 = iStack_34 + -1;
        goto LAB_004fe76d;
      }
LAB_004fe771:
      pTVar8 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
    }
    TacticalAIGroup::setType(pTVar8,0x67);
    TacticalAIGroup::setTarget(pTVar8,-1);
    TacticalAIGroup::setTargetType(pTVar8,-1);
    TacticalAIGroup::setAction(pTVar8,1);
    TacticalAIGroup::setInUse(pTVar8,0);
    TacticalAIGroup::setDesiredNumberUnits(pTVar8,param_1->sn[0x3b]);
  }
  while ((iStack_30 < iVar3 &&
         ((pTVar8 = TribeTacticalAIModule::group(param_1,-1,0x67,0,-1),
          pTVar8 != (TacticalAIGroup *)0x0 ||
          (pTVar8 = TribeTacticalAIModule::group(param_1,-1,0x67,1,-1),
          pTVar8 != (TacticalAIGroup *)0x0))))) {
    iVar1 = TacticalAIGroup::id(pTVar8);
    TribeTacticalAIModule::removeGroup(param_1,iVar1);
    iVar3 = iVar3 + -1;
  }
  for (; iVar4 < iStack_38; iVar4 = iVar4 + 1) {
    pTVar8 = (TacticalAIGroup *)0x0;
    if (iStack_34 < 1) {
LAB_004fe837:
      if (pTVar8 == (TacticalAIGroup *)0x0) goto LAB_004fe83b;
    }
    else {
      pTVar8 = TribeTacticalAIModule::group(param_1,-1,0x69,-1,-1);
      if (pTVar8 != (TacticalAIGroup *)0x0) {
        iStack_34 = iStack_34 + -1;
        goto LAB_004fe837;
      }
LAB_004fe83b:
      pTVar8 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
    }
    TacticalAIGroup::setType(pTVar8,0x68);
    TacticalAIGroup::setTarget(pTVar8,-1);
    TacticalAIGroup::setTargetType(pTVar8,-1);
    TacticalAIGroup::setAction(pTVar8,1);
    TacticalAIGroup::setInUse(pTVar8,0);
    TacticalAIGroup::setDesiredNumberUnits(pTVar8,param_1->sn[0x44]);
  }
  while ((iStack_38 < iVar4 &&
         (pTVar8 = TribeTacticalAIModule::group(param_1,-1,0x68,-1,-1),
         pTVar8 != (TacticalAIGroup *)0x0))) {
    iVar1 = TacticalAIGroup::id(pTVar8);
    TribeTacticalAIModule::removeGroup(param_1,iVar1);
    iVar4 = iVar4 + -1;
  }
  iVar1 = iStack_34 - iStack_2c;
  if (iStack_34 < iStack_2c) {
    do {
      pTVar8 = TribeTacticalAIModule::createGroup(param_1,1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      TacticalAIGroup::setType(pTVar8,0x69);
      TacticalAIGroup::setDesiredNumberUnits(pTVar8,param_1->sn[0x3e]);
      iStack_34 = iStack_34 + 1;
    } while (iStack_34 < iStack_2c);
    iVar1 = iStack_34 - iStack_2c;
  }
  if (iStack_34 != iStack_2c && SBORROW4(iStack_34,iStack_2c) == iVar1 < 0) {
    do {
      pTVar8 = TribeTacticalAIModule::group(param_1,-1,0x69,-1,-1);
      if (pTVar8 == (TacticalAIGroup *)0x0) break;
      iVar1 = TacticalAIGroup::id(pTVar8);
      TribeTacticalAIModule::removeGroup(param_1,iVar1);
      iStack_34 = iStack_34 + -1;
    } while (iStack_2c < iStack_34);
  }
  uStack_4 = 0xffffffff;
  if (MStack_1c.value != (int *)0x0) {
    operator_delete(MStack_1c.value);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004fe947
// Address: 004fe947
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fe947(TribeTacticalAIModule *param_1)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  Waypoint *pWVar4;
  int iVar5;
  int *piVar6;
  TacticalAIGroup *pTVar7;
  float fVar8;
  float fVar9;
  TacticalAIGroup *pTStack_18;
  float fStack_14;
  float fStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  TribeTacticalAIModule::numberUngroupedWarBoats(param_1);
  TribeTacticalAIModule::numberExtraGroupedWarBoats(param_1);
  pTVar7 = (param_1->groups).next;
  do {
    if ((pTVar7 == &param_1->groups) || (pTVar7 == (TacticalAIGroup *)0x0)) {
      if (param_1->sn[0x28] == 0) {
        iStack_c = 0x67;
        do {
          pTStack_18 = (param_1->groups).next;
          if (pTStack_18 != &param_1->groups) {
            do {
              if (pTStack_18 == (TacticalAIGroup *)0x0) break;
              iVar1 = TacticalAIGroup::type(pTStack_18);
              if (iVar1 == iStack_c) {
                iVar1 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                iVar2 = TacticalAIGroup::numberUnits(pTStack_18);
                if (iVar2 < iVar1) {
                  iVar1 = TribeTacticalAIModule::numberUngroupedWarBoats(param_1);
                  iVar2 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                  iVar5 = TacticalAIGroup::numberUnits(pTStack_18);
                  if (iVar2 - iVar5 < iVar1) {
                    iVar1 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                    iVar2 = TacticalAIGroup::numberUnits(pTStack_18);
                    if (iVar2 < iVar1) {
                      do {
                        iVar1 = 0;
                        iStack_4 = -1;
                        fStack_14 = -1.0;
                        if (0 < (param_1->workingArea).numberValue) {
                          do {
                            if ((param_1->workingArea).maximumSizeValue + -1 < iVar1) {
                              piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                              if (piVar6 != (int *)0x0) {
                                iVar2 = 0;
                                if (0 < (param_1->workingArea).maximumSizeValue) {
                                  do {
                                    if (iVar1 + 1 <= iVar2) break;
                                    iVar5 = iVar2 + 1;
                                    piVar6[iVar2] = (param_1->workingArea).value[iVar2];
                                    iVar2 = iVar5;
                                  } while (iVar5 < (param_1->workingArea).maximumSizeValue);
                                }
                                operator_delete((param_1->workingArea).value);
                                (param_1->workingArea).value = piVar6;
                                (param_1->workingArea).maximumSizeValue = iVar1 + 1;
                              }
                            }
                            pRVar3 = MainDecisionAIModule::object
                                               ((MainDecisionAIModule *)param_1->md,
                                                (param_1->workingArea).value[iVar1]);
                            if (pRVar3 != (RGE_Static_Object *)0x0) {
                              pWVar4 = TacticalAIGroup::gatherLocation(pTStack_18);
                              fVar8 = pWVar4->z;
                              pWVar4 = TacticalAIGroup::gatherLocation(pTStack_18);
                              fVar9 = pWVar4->y;
                              pWVar4 = TacticalAIGroup::gatherLocation(pTStack_18);
                              fVar8 = RGE_Static_Object::distance_to_position
                                                (pRVar3,pWVar4->x,fVar9,fVar8);
                              if ((fStack_14 == _DAT_00575758) || (fVar8 < fStack_14)) {
                                if ((param_1->workingArea).maximumSizeValue + -1 < iVar1) {
                                  piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                                  if (piVar6 != (int *)0x0) {
                                    iVar2 = 0;
                                    if (0 < (param_1->workingArea).maximumSizeValue) {
                                      do {
                                        if (iVar1 + 1 <= iVar2) break;
                                        iVar5 = iVar2 + 1;
                                        piVar6[iVar2] = (param_1->workingArea).value[iVar2];
                                        iVar2 = iVar5;
                                      } while (iVar5 < (param_1->workingArea).maximumSizeValue);
                                    }
                                    operator_delete((param_1->workingArea).value);
                                    (param_1->workingArea).value = piVar6;
                                    (param_1->workingArea).maximumSizeValue = iVar1 + 1;
                                  }
                                }
                                iStack_4 = (param_1->workingArea).value[iVar1];
                                fStack_14 = fVar8;
                              }
                            }
                            iVar1 = iVar1 + 1;
                          } while (iVar1 < (param_1->workingArea).numberValue);
                        }
                        if (iStack_4 == -1) break;
                        TacticalAIGroup::addUnit(pTStack_18,iStack_4,param_1->md);
                        iVar1 = (param_1->workingArea).maximumSizeValue;
                        iVar2 = 0;
                        if (0 < iVar1) {
                          piVar6 = (param_1->workingArea).value;
                          do {
                            if (*piVar6 == iStack_4) break;
                            iVar2 = iVar2 + 1;
                            piVar6 = piVar6 + 1;
                          } while (iVar2 < iVar1);
                        }
                        if (iVar2 < iVar1) {
                          if (iVar2 < iVar1 + -1) {
                            do {
                              piVar6 = (param_1->workingArea).value;
                              iVar1 = iVar2 + 1;
                              piVar6[iVar2] = piVar6[iVar1];
                              iVar2 = iVar1;
                            } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
                          }
                          iVar1 = (param_1->workingArea).numberValue + -1;
                          (param_1->workingArea).numberValue = iVar1;
                          if (iVar1 < 0) {
                            (param_1->workingArea).numberValue = 0;
                          }
                        }
                        iVar1 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                        iVar2 = TacticalAIGroup::numberUnits(pTStack_18);
                      } while (iVar2 < iVar1);
                    }
                  }
                  else {
                    iVar1 = 0;
                    if (0 < (param_1->workingArea).numberValue) {
                      do {
                        if ((param_1->workingArea).maximumSizeValue + -1 < iVar1) {
                          piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                          if (piVar6 != (int *)0x0) {
                            iVar2 = 0;
                            if (0 < (param_1->workingArea).maximumSizeValue) {
                              do {
                                if (iVar1 + 1 <= iVar2) break;
                                iVar5 = iVar2 + 1;
                                piVar6[iVar2] = (param_1->workingArea).value[iVar2];
                                iVar2 = iVar5;
                              } while (iVar5 < (param_1->workingArea).maximumSizeValue);
                            }
                            operator_delete((param_1->workingArea).value);
                            (param_1->workingArea).value = piVar6;
                            (param_1->workingArea).maximumSizeValue = iVar1 + 1;
                          }
                        }
                        TacticalAIGroup::addUnit
                                  (pTStack_18,(param_1->workingArea).value[iVar1],param_1->md);
                        iVar1 = iVar1 + 1;
                      } while (iVar1 < (param_1->workingArea).numberValue);
                    }
                  }
                  iVar1 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                  iVar2 = TacticalAIGroup::numberUnits(pTStack_18);
                  if (iVar2 < iVar1) {
                    iVar1 = TribeTacticalAIModule::numberExtraGroupedWarBoats(param_1);
                    iVar2 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                    iVar5 = TacticalAIGroup::numberUnits(pTStack_18);
                    if (iVar2 - iVar5 < iVar1) {
                      iVar1 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                      iVar2 = TacticalAIGroup::numberUnits(pTStack_18);
                      if (iVar2 < iVar1) {
                        do {
                          iVar1 = 0;
                          iStack_8 = -1;
                          fStack_10 = -1.0;
                          if (0 < (param_1->workingArea).numberValue) {
                            do {
                              if ((param_1->workingArea).maximumSizeValue + -1 < iVar1) {
                                piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                                if (piVar6 != (int *)0x0) {
                                  iVar2 = 0;
                                  if (0 < (param_1->workingArea).maximumSizeValue) {
                                    do {
                                      if (iVar1 + 1 <= iVar2) break;
                                      iVar5 = iVar2 + 1;
                                      piVar6[iVar2] = (param_1->workingArea).value[iVar2];
                                      iVar2 = iVar5;
                                    } while (iVar5 < (param_1->workingArea).maximumSizeValue);
                                  }
                                  operator_delete((param_1->workingArea).value);
                                  (param_1->workingArea).value = piVar6;
                                  (param_1->workingArea).maximumSizeValue = iVar1 + 1;
                                }
                              }
                              pRVar3 = MainDecisionAIModule::object
                                                 ((MainDecisionAIModule *)param_1->md,
                                                  (param_1->workingArea).value[iVar1]);
                              if (pRVar3 != (RGE_Static_Object *)0x0) {
                                pWVar4 = TacticalAIGroup::gatherLocation(pTStack_18);
                                fVar8 = pWVar4->z;
                                pWVar4 = TacticalAIGroup::gatherLocation(pTStack_18);
                                fVar9 = pWVar4->y;
                                pWVar4 = TacticalAIGroup::gatherLocation(pTStack_18);
                                fVar8 = RGE_Static_Object::distance_to_position
                                                  (pRVar3,pWVar4->x,fVar9,fVar8);
                                if ((fStack_10 == _DAT_00575758) || (fVar8 < fStack_10)) {
                                  if ((param_1->workingArea).maximumSizeValue + -1 < iVar1) {
                                    piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                                    if (piVar6 != (int *)0x0) {
                                      iVar2 = 0;
                                      if (0 < (param_1->workingArea).maximumSizeValue) {
                                        do {
                                          if (iVar1 + 1 <= iVar2) break;
                                          iVar5 = iVar2 + 1;
                                          piVar6[iVar2] = (param_1->workingArea).value[iVar2];
                                          iVar2 = iVar5;
                                        } while (iVar5 < (param_1->workingArea).maximumSizeValue);
                                      }
                                      operator_delete((param_1->workingArea).value);
                                      (param_1->workingArea).value = piVar6;
                                      (param_1->workingArea).maximumSizeValue = iVar1 + 1;
                                    }
                                  }
                                  iStack_8 = (param_1->workingArea).value[iVar1];
                                  fStack_10 = fVar8;
                                }
                              }
                              iVar1 = iVar1 + 1;
                            } while (iVar1 < (param_1->workingArea).numberValue);
                          }
                          if (iStack_8 == -1) break;
                          TribeTacticalAIModule::removeFromGroup(param_1,iStack_8);
                          TacticalAIGroup::addUnit(pTStack_18,iStack_8,param_1->md);
                          iVar1 = (param_1->workingArea).maximumSizeValue;
                          iVar2 = 0;
                          if (0 < iVar1) {
                            piVar6 = (param_1->workingArea).value;
                            do {
                              if (*piVar6 == iStack_8) break;
                              iVar2 = iVar2 + 1;
                              piVar6 = piVar6 + 1;
                            } while (iVar2 < iVar1);
                          }
                          if (iVar2 < iVar1) {
                            if (iVar2 < iVar1 + -1) {
                              do {
                                piVar6 = (param_1->workingArea).value;
                                iVar1 = iVar2 + 1;
                                piVar6[iVar2] = piVar6[iVar1];
                                iVar2 = iVar1;
                              } while (iVar1 < (param_1->workingArea).maximumSizeValue + -1);
                            }
                            iVar1 = (param_1->workingArea).numberValue + -1;
                            (param_1->workingArea).numberValue = iVar1;
                            if (iVar1 < 0) {
                              (param_1->workingArea).numberValue = 0;
                            }
                          }
                          iVar1 = TacticalAIGroup::desiredNumberUnits(pTStack_18);
                          iVar2 = TacticalAIGroup::numberUnits(pTStack_18);
                        } while (iVar2 < iVar1);
                      }
                    }
                    else {
                      iVar1 = 0;
                      if (0 < (param_1->workingArea).numberValue) {
                        do {
                          if ((param_1->workingArea).maximumSizeValue + -1 < iVar1) {
                            piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                            if (piVar6 != (int *)0x0) {
                              iVar2 = 0;
                              if (0 < (param_1->workingArea).maximumSizeValue) {
                                do {
                                  if (iVar1 + 1 <= iVar2) break;
                                  iVar5 = iVar2 + 1;
                                  piVar6[iVar2] = (param_1->workingArea).value[iVar2];
                                  iVar2 = iVar5;
                                } while (iVar5 < (param_1->workingArea).maximumSizeValue);
                              }
                              operator_delete((param_1->workingArea).value);
                              (param_1->workingArea).value = piVar6;
                              (param_1->workingArea).maximumSizeValue = iVar1 + 1;
                            }
                          }
                          TribeTacticalAIModule::removeFromGroup
                                    (param_1,(param_1->workingArea).value[iVar1]);
                          if ((param_1->workingArea).maximumSizeValue + -1 < iVar1) {
                            piVar6 = (int *)operator_new(iVar1 * 4 + 4);
                            if (piVar6 != (int *)0x0) {
                              iVar2 = 0;
                              if (0 < (param_1->workingArea).maximumSizeValue) {
                                do {
                                  if (iVar1 + 1 <= iVar2) break;
                                  iVar5 = iVar2 + 1;
                                  piVar6[iVar2] = (param_1->workingArea).value[iVar2];
                                  iVar2 = iVar5;
                                } while (iVar5 < (param_1->workingArea).maximumSizeValue);
                              }
                              operator_delete((param_1->workingArea).value);
                              (param_1->workingArea).value = piVar6;
                              (param_1->workingArea).maximumSizeValue = iVar1 + 1;
                            }
                          }
                          TacticalAIGroup::addUnit
                                    (pTStack_18,(param_1->workingArea).value[iVar1],param_1->md);
                          iVar1 = iVar1 + 1;
                        } while (iVar1 < (param_1->workingArea).numberValue);
                      }
                    }
                    pTStack_18 = pTStack_18->next;
                  }
                  else {
                    pTStack_18 = pTStack_18->next;
                  }
                }
                else {
                  pTStack_18 = pTStack_18->next;
                }
              }
              else {
                pTStack_18 = pTStack_18->next;
              }
            } while (pTStack_18 != &param_1->groups);
          }
          iStack_c = iStack_c + 1;
        } while (iStack_c < 0x6b);
      }
      iVar1 = TribeTacticalAIModule::numberUngroupedWarBoats(param_1);
      if ((iVar1 != 0) && (fStack_14 = 0.0, 0 < (param_1->workingArea).numberValue)) {
        do {
          pTVar7 = (param_1->groups).next;
          iVar1 = 0;
          pTStack_18 = (TacticalAIGroup *)0x0;
          if (pTVar7 != &param_1->groups) {
            do {
              if (pTVar7 == (TacticalAIGroup *)0x0) break;
              iVar2 = TacticalAIGroup::type(pTVar7);
              if (((((iVar2 == 0x67) || (iVar2 = TacticalAIGroup::type(pTVar7), iVar2 == 0x68)) ||
                   (iVar2 = TacticalAIGroup::type(pTVar7), iVar2 == 0x69)) ||
                  ((iVar2 = TacticalAIGroup::type(pTVar7), iVar2 == 0x6a ||
                   (iVar2 = TacticalAIGroup::type(pTVar7), iVar2 == 0x6b)))) ||
                 (iVar2 = TacticalAIGroup::type(pTVar7), iVar2 == 0x6c)) {
                iVar2 = TacticalAIGroup::numberUnits(pTVar7);
                iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar7);
                if ((iVar2 < iVar5) &&
                   ((iVar2 = TacticalAIGroup::action(pTVar7), iVar2 == 1 ||
                    (iVar2 = TacticalAIGroup::action(pTVar7), iVar2 == 0)))) {
                  iVar2 = TacticalAIGroup::numberUnits(pTVar7);
                  iVar5 = TacticalAIGroup::desiredNumberUnits(pTVar7);
                  if ((pTStack_18 == (TacticalAIGroup *)0x0) || (iVar1 < iVar5 - iVar2)) {
                    iVar1 = iVar5 - iVar2;
                    pTStack_18 = pTVar7;
                  }
                }
              }
              pTVar7 = pTVar7->next;
            } while (pTVar7 != &param_1->groups);
          }
          if (pTStack_18 == (TacticalAIGroup *)0x0) {
            pTVar7 = (param_1->groups).next;
            pTStack_18 = (TacticalAIGroup *)0x0;
            iStack_4 = 0;
            for (; (pTVar7 != &param_1->groups && (pTVar7 != (TacticalAIGroup *)0x0));
                pTVar7 = pTVar7->next) {
              iVar1 = TacticalAIGroup::type(pTVar7);
              if ((((((iVar1 == 0x67) ||
                     (((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x68 ||
                       (iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x69)) ||
                      (iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x6a)))) ||
                    ((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x6b ||
                     (iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x6c)))) &&
                   ((iVar1 = TacticalAIGroup::action(pTVar7), iVar1 == 1 ||
                    (iVar1 = TacticalAIGroup::action(pTVar7), iVar1 == 0)))) &&
                  (((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 != 0x67 ||
                    (iVar1 = TacticalAIGroup::numberUnits(pTVar7), iVar1 < param_1->sn[0x3c])) &&
                   ((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 != 0x68 ||
                    (iVar1 = TacticalAIGroup::numberUnits(pTVar7), iVar1 < param_1->sn[0x45]))))))
                 && ((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 != 0x69 ||
                     (iVar1 = TacticalAIGroup::numberUnits(pTVar7), iVar1 < param_1->sn[0x3f])))) {
                iVar1 = TacticalAIGroup::numberUnits(pTVar7);
                iVar2 = TacticalAIGroup::desiredNumberUnits(pTVar7);
                if ((pTStack_18 == (TacticalAIGroup *)0x0) || (iVar1 - iVar2 < iStack_4)) {
                  pTStack_18 = pTVar7;
                  iStack_4 = iVar1 - iVar2;
                }
              }
            }
            if (pTStack_18 == (TacticalAIGroup *)0x0) {
              return;
            }
            if ((param_1->workingArea).maximumSizeValue + -1 < (int)fStack_14) {
              piVar6 = (int *)operator_new((int)fStack_14 * 4 + 4);
              if (piVar6 != (int *)0x0) {
                iVar1 = 0;
                if (0 < (param_1->workingArea).maximumSizeValue) {
                  do {
                    if ((int)fStack_14 + 1 <= iVar1) break;
                    iVar2 = iVar1 + 1;
                    piVar6[iVar1] = (param_1->workingArea).value[iVar1];
                    iVar1 = iVar2;
                  } while (iVar2 < (param_1->workingArea).maximumSizeValue);
                }
                operator_delete((param_1->workingArea).value);
                (param_1->workingArea).value = piVar6;
                (param_1->workingArea).maximumSizeValue = (int)fStack_14 + 1;
              }
            }
            TacticalAIGroup::addUnit
                      (pTStack_18,(param_1->workingArea).value[(int)fStack_14],param_1->md);
          }
          else {
            if ((param_1->workingArea).maximumSizeValue + -1 < (int)fStack_14) {
              piVar6 = (int *)operator_new((int)fStack_14 * 4 + 4);
              if (piVar6 != (int *)0x0) {
                iVar1 = 0;
                if (0 < (param_1->workingArea).maximumSizeValue) {
                  do {
                    if ((int)fStack_14 + 1 <= iVar1) break;
                    iVar2 = iVar1 + 1;
                    piVar6[iVar1] = (param_1->workingArea).value[iVar1];
                    iVar1 = iVar2;
                  } while (iVar2 < (param_1->workingArea).maximumSizeValue);
                }
                operator_delete((param_1->workingArea).value);
                (param_1->workingArea).value = piVar6;
                (param_1->workingArea).maximumSizeValue = (int)fStack_14 + 1;
              }
            }
            TacticalAIGroup::addUnit
                      (pTStack_18,(param_1->workingArea).value[(int)fStack_14],param_1->md);
          }
          fStack_14 = (float)((int)fStack_14 + 1);
        } while ((int)fStack_14 < (param_1->workingArea).numberValue);
      }
      return;
    }
    iVar1 = TacticalAIGroup::type(pTVar7);
    if (((iVar1 == 0x67) ||
        ((iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x68 ||
         (iVar1 = TacticalAIGroup::type(pTVar7), iVar1 == 0x69)))) &&
       (iVar1 = TacticalAIGroup::commander(pTVar7), iVar1 == -1)) {
      iVar1 = TribeTacticalAIModule::numberUngroupedWarBoats(param_1);
      iVar2 = TacticalAIGroup::numberUnits(pTVar7);
      if (iVar2 < 1) {
        if (iVar1 == 0) {
          TribeTacticalAIModule::numberExtraGroupedWarBoats(param_1);
        }
        if ((param_1->workingArea).numberValue == 0) {
          return;
        }
        iVar1 = TribeTacticalAIModule::selectBestCommander(param_1,&param_1->workingArea);
        TacticalAIGroup::addUnit(pTVar7,iVar1,param_1->md);
        TacticalAIGroup::setSpecificCommander(pTVar7,iVar1,param_1->md);
        iVar1 = TacticalAIGroup::action(pTVar7);
        if (iVar1 != 0) {
          iVar1 = TacticalAIGroup::action(pTVar7);
          goto joined_r0x004fea59;
        }
      }
      else {
        iVar1 = TribeTacticalAIModule::selectBestCommander(param_1,pTVar7);
        TacticalAIGroup::setSpecificCommander(pTVar7,iVar1,param_1->md);
        iVar1 = TacticalAIGroup::action(pTVar7);
        if (iVar1 != 0) {
          iVar1 = TacticalAIGroup::action(pTVar7);
joined_r0x004fea59:
          if (iVar1 != 1) goto LAB_004fea63;
        }
      }
      TribeTacticalAIModule::setAllGroupLocations(param_1,pTVar7);
    }
LAB_004fea63:
    pTVar7 = pTVar7->next;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004ff4df
// Address: 004ff4df
// XREFS: None
int __fastcall FUN_004ff4df(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  int iStack_4;
  
  iStack_c = 0;
  iStack_4 = 0;
  (param_1->workingArea).numberValue = 0;
  if (0 < (param_1->boats).numberValue) {
    do {
      if ((param_1->boats).maximumSizeValue + -1 < iStack_4) {
        piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->boats).maximumSizeValue) {
            do {
              if (iStack_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (param_1->boats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (param_1->boats).maximumSizeValue);
          }
          operator_delete((param_1->boats).value);
          (param_1->boats).value = piVar1;
          (param_1->boats).maximumSizeValue = iStack_4 + 1;
        }
      }
      pTVar3 = TribeTacticalAIModule::groupUnitIsIn(param_1,(param_1->boats).value[iStack_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((param_1->boats).maximumSizeValue + -1 < iStack_4) {
          piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->boats).maximumSizeValue) {
              do {
                if (iStack_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (param_1->boats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (param_1->boats).maximumSizeValue);
            }
            operator_delete((param_1->boats).value);
            (param_1->boats).value = piVar1;
            (param_1->boats).maximumSizeValue = iStack_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (param_1->boats).value[iStack_4];
        iVar4 = (param_1->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((param_1->workingArea).maximumSizeValue <= iVar5) break;
            if ((param_1->workingArea).value[iVar5] == iVar2) goto LAB_004ff6b2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((param_1->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (param_1->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar1;
            (param_1->workingArea).maximumSizeValue = iVar4;
          }
        }
        (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar2;
        (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004ff6b2:
        iStack_c = iStack_c + 1;
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < (param_1->boats).numberValue);
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004ff6de
// Address: 004ff6de
// XREFS: None
int __fastcall FUN_004ff6de(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  TacticalAIGroup *this;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  *(undefined4 *)(param_1 + 0xd4c) = 0;
  this = *(TacticalAIGroup **)(param_1 + 0x9d8);
  if (this != (TacticalAIGroup *)(param_1 + 0x9d4)) {
    do {
      if (this == (TacticalAIGroup *)0x0) {
        return iStack_8;
      }
      iVar1 = TacticalAIGroup::type(this);
      if ((((((iVar1 == 0x67) || (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x68)) ||
            (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x69)) ||
           ((iVar1 = TacticalAIGroup::type(this), iVar1 == 0x6a ||
            (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x6b)))) ||
          (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x6c)) &&
         ((iVar1 = TacticalAIGroup::action(this), iVar1 == 1 ||
          (iVar1 = TacticalAIGroup::action(this), iVar1 == 0)))) {
        iVar1 = TacticalAIGroup::numberUnits(this);
        iVar2 = TacticalAIGroup::desiredNumberUnits(this);
        if (iVar2 < iVar1) {
          iStack_c = TacticalAIGroup::numberUnits(this);
          iStack_10 = 0;
          iVar1 = TacticalAIGroup::desiredNumberUnits(this);
          if (iVar1 < iStack_c) {
            do {
              iVar1 = TacticalAIGroup::numberUnits(this);
              if (iVar1 <= iStack_10) break;
              iVar1 = TacticalAIGroup::unit(this,iStack_10);
              iVar2 = TacticalAIGroup::commander(this);
              if (iVar1 != iVar2) {
                iStack_c = iStack_c + -1;
                iVar2 = TacticalAIGroup::unit(this,iStack_10);
                iVar1 = *(int *)(param_1 + 0xd4c);
                iVar3 = 0;
                if (0 < iVar1) {
                  do {
                    if (*(int *)(param_1 + 0xd54) <= iVar3) break;
                    if (*(int *)(*(int *)(param_1 + 0xd48) + iVar3 * 4) == iVar2) goto LAB_004ff8a6;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < iVar1);
                }
                if (*(int *)(param_1 + 0xd54) + -1 < iVar1) {
                  iVar1 = iVar1 + 1;
                  pvVar4 = operator_new(iVar1 * 4);
                  if (pvVar4 != (void *)0x0) {
                    iVar3 = 0;
                    if (0 < *(int *)(param_1 + 0xd54)) {
                      do {
                        if (iVar1 <= iVar3) break;
                        iVar3 = iVar3 + 1;
                        *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
                             *(undefined4 *)(*(int *)(param_1 + 0xd48) + -4 + iVar3 * 4);
                      } while (iVar3 < *(int *)(param_1 + 0xd54));
                    }
                    operator_delete(*(void **)(param_1 + 0xd48));
                    *(void **)(param_1 + 0xd48) = pvVar4;
                    *(int *)(param_1 + 0xd54) = iVar1;
                  }
                }
                *(int *)(*(int *)(param_1 + 0xd48) + *(int *)(param_1 + 0xd4c) * 4) = iVar2;
                *(int *)(param_1 + 0xd4c) = *(int *)(param_1 + 0xd4c) + 1;
LAB_004ff8a6:
                iStack_8 = iStack_8 + 1;
              }
              iStack_10 = iStack_10 + 1;
              iVar1 = TacticalAIGroup::desiredNumberUnits(this);
            } while (iVar1 < iStack_c);
          }
        }
      }
      this = this->next;
    } while (this != (TacticalAIGroup *)(param_1 + 0x9d4));
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_004ff8dd
// Address: 004ff8dd
// XREFS: None
int __fastcall FUN_004ff8dd(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  int iStack_4;
  
  iStack_c = 0;
  iStack_4 = 0;
  (param_1->workingArea).numberValue = 0;
  if (0 < (param_1->fishingBoats).numberValue) {
    do {
      if ((param_1->fishingBoats).maximumSizeValue + -1 < iStack_4) {
        piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->fishingBoats).maximumSizeValue) {
            do {
              if (iStack_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (param_1->fishingBoats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (param_1->fishingBoats).maximumSizeValue);
          }
          operator_delete((param_1->fishingBoats).value);
          (param_1->fishingBoats).value = piVar1;
          (param_1->fishingBoats).maximumSizeValue = iStack_4 + 1;
        }
      }
      pTVar3 = TribeTacticalAIModule::groupUnitIsIn(param_1,(param_1->fishingBoats).value[iStack_4])
      ;
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((param_1->fishingBoats).maximumSizeValue + -1 < iStack_4) {
          piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->fishingBoats).maximumSizeValue) {
              do {
                if (iStack_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (param_1->fishingBoats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (param_1->fishingBoats).maximumSizeValue);
            }
            operator_delete((param_1->fishingBoats).value);
            (param_1->fishingBoats).value = piVar1;
            (param_1->fishingBoats).maximumSizeValue = iStack_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (param_1->fishingBoats).value[iStack_4];
        iVar4 = (param_1->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((param_1->workingArea).maximumSizeValue <= iVar5) break;
            if ((param_1->workingArea).value[iVar5] == iVar2) goto LAB_004ffab2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((param_1->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (param_1->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar1;
            (param_1->workingArea).maximumSizeValue = iVar4;
          }
        }
        (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar2;
        (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004ffab2:
        iStack_c = iStack_c + 1;
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < (param_1->fishingBoats).numberValue);
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004ffade
// Address: 004ffade
// XREFS: None
int __fastcall FUN_004ffade(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  int iStack_4;
  
  iStack_c = 0;
  iStack_4 = 0;
  (param_1->workingArea).numberValue = 0;
  if (0 < (param_1->tradeBoats).numberValue) {
    do {
      if ((param_1->tradeBoats).maximumSizeValue + -1 < iStack_4) {
        piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->tradeBoats).maximumSizeValue) {
            do {
              if (iStack_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (param_1->tradeBoats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (param_1->tradeBoats).maximumSizeValue);
          }
          operator_delete((param_1->tradeBoats).value);
          (param_1->tradeBoats).value = piVar1;
          (param_1->tradeBoats).maximumSizeValue = iStack_4 + 1;
        }
      }
      pTVar3 = TribeTacticalAIModule::groupUnitIsIn(param_1,(param_1->tradeBoats).value[iStack_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((param_1->tradeBoats).maximumSizeValue + -1 < iStack_4) {
          piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->tradeBoats).maximumSizeValue) {
              do {
                if (iStack_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (param_1->tradeBoats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (param_1->tradeBoats).maximumSizeValue);
            }
            operator_delete((param_1->tradeBoats).value);
            (param_1->tradeBoats).value = piVar1;
            (param_1->tradeBoats).maximumSizeValue = iStack_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (param_1->tradeBoats).value[iStack_4];
        iVar4 = (param_1->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((param_1->workingArea).maximumSizeValue <= iVar5) break;
            if ((param_1->workingArea).value[iVar5] == iVar2) goto LAB_004ffcb2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((param_1->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (param_1->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar1;
            (param_1->workingArea).maximumSizeValue = iVar4;
          }
        }
        (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar2;
        (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004ffcb2:
        iStack_c = iStack_c + 1;
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < (param_1->tradeBoats).numberValue);
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004ffcde
// Address: 004ffcde
// XREFS: None
int __fastcall FUN_004ffcde(TribeTacticalAIModule *param_1)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  int iStack_4;
  
  iStack_c = 0;
  iStack_4 = 0;
  (param_1->workingArea).numberValue = 0;
  if (0 < (param_1->transportBoats).numberValue) {
    do {
      if ((param_1->transportBoats).maximumSizeValue + -1 < iStack_4) {
        piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->transportBoats).maximumSizeValue) {
            do {
              if (iStack_4 + 1 <= iVar4) break;
              iVar2 = iVar4 + 1;
              piVar1[iVar4] = (param_1->transportBoats).value[iVar4];
              iVar4 = iVar2;
            } while (iVar2 < (param_1->transportBoats).maximumSizeValue);
          }
          operator_delete((param_1->transportBoats).value);
          (param_1->transportBoats).value = piVar1;
          (param_1->transportBoats).maximumSizeValue = iStack_4 + 1;
        }
      }
      pTVar3 = TribeTacticalAIModule::groupUnitIsIn
                         (param_1,(param_1->transportBoats).value[iStack_4]);
      if (pTVar3 == (TacticalAIGroup *)0x0) {
        if ((param_1->transportBoats).maximumSizeValue + -1 < iStack_4) {
          piVar1 = (int *)operator_new(iStack_4 * 4 + 4);
          if (piVar1 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->transportBoats).maximumSizeValue) {
              do {
                if (iStack_4 + 1 <= iVar4) break;
                iVar2 = iVar4 + 1;
                piVar1[iVar4] = (param_1->transportBoats).value[iVar4];
                iVar4 = iVar2;
              } while (iVar2 < (param_1->transportBoats).maximumSizeValue);
            }
            operator_delete((param_1->transportBoats).value);
            (param_1->transportBoats).value = piVar1;
            (param_1->transportBoats).maximumSizeValue = iStack_4 + 1;
          }
        }
        iVar5 = 0;
        iVar2 = (param_1->transportBoats).value[iStack_4];
        iVar4 = (param_1->workingArea).numberValue;
        if (0 < iVar4) {
          do {
            if ((param_1->workingArea).maximumSizeValue <= iVar5) break;
            if ((param_1->workingArea).value[iVar5] == iVar2) goto LAB_004ffeb2;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
        if ((param_1->workingArea).maximumSizeValue + -1 < iVar4) {
          iVar4 = iVar4 + 1;
          piVar1 = (int *)operator_new(iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            iVar5 = 0;
            if (0 < (param_1->workingArea).maximumSizeValue) {
              do {
                if (iVar4 <= iVar5) break;
                iVar6 = iVar5 + 1;
                piVar1[iVar5] = (param_1->workingArea).value[iVar5];
                iVar5 = iVar6;
              } while (iVar6 < (param_1->workingArea).maximumSizeValue);
            }
            operator_delete((param_1->workingArea).value);
            (param_1->workingArea).value = piVar1;
            (param_1->workingArea).maximumSizeValue = iVar4;
          }
        }
        (param_1->workingArea).value[(param_1->workingArea).numberValue] = iVar2;
        (param_1->workingArea).numberValue = (param_1->workingArea).numberValue + 1;
LAB_004ffeb2:
        iStack_c = iStack_c + 1;
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < (param_1->transportBoats).numberValue);
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004ffede
// Address: 004ffede
// XREFS: None
// [HELPER] s_____Gather_Location___f___f__: "    Gather Location=(%f, %f)."
// [HELPER] s_____Location___f___f__: "    Location=(%f, %f)."
// [HELPER] s_____NumUnits__d__DesNumUnits__d_: "    NumUnits=%d, DesNumUnits=%d, OrgNumUnits=%d, Action=%d, inUse=%d."
// [HELPER] s_____Retreat_Location___f___f__: "    Retreat Location=(%f, %f)."
// [HELPER] s_____Target_Location___f___f__: "    Target Location=(%f, %f)."
// [HELPER] s_____Target__d__CommanderID__d__H: "    Target=%d, CommanderID=%d, HP(%d/%d), AssistGroup=%d."
// [HELPER] s_____Unit___d_: "    Unit #%d."
// [HELPER] s_____Unit__d__state__d__action__d: "    Unit %d: state=%d, action=%d, target=%d, order=%d, priority=%d, location=..."
void __fastcall FUN_004ffede(AIModule *param_1)
{
  int iVar1;
  int iVar2;
  Waypoint *pWVar3;
  RGE_Static_Object *this;
  UnitAIModule *pUVar4;
  int iVar5;
  int iVar6;
  AIModule *extraout_ECX;
  AIModule *extraout_ECX_00;
  AIModule *extraout_ECX_01;
  AIModule *extraout_ECX_02;
  AIModule *extraout_ECX_03;
  AIModule *extraout_ECX_04;
  AIModule *this_00;
  AIModule *this_01;
  AIModule *this_02;
  AIModule *this_03;
  AIModule *this_04;
  AIModule *this_05;
  AIModule *this_06;
  AIModule *this_07;
  AIModule *this_08;
  AIModule *this_09;
  uint uVar7;
  AIModule *this_10;
  TacticalAIGroup *this_11;
  undefined8 uVar8;
  undefined8 uVar9;
  double dVar10;
  
  AIModule::logCommonHistory(param_1,(char *)param_1);
  this_11 = *(TacticalAIGroup **)(param_1[10].playerNameValue + 0x28);
  if (this_11 != (TacticalAIGroup *)(param_1[10].playerNameValue + 0x24)) {
    do {
      if (this_11 == (TacticalAIGroup *)0x0) {
        return;
      }
      iVar1 = TacticalAIGroup::type(this_11);
      if ((((iVar1 == 0x67) || (iVar1 = TacticalAIGroup::type(this_11), iVar1 == 0x68)) ||
          (iVar1 = TacticalAIGroup::type(this_11), iVar1 == 0x69)) ||
         (((iVar1 = TacticalAIGroup::type(this_11), iVar1 == 0x6b ||
           (iVar1 = TacticalAIGroup::type(this_11), iVar1 == 0x6c)) ||
          (iVar1 = TacticalAIGroup::type(this_11), iVar1 == 0x6a)))) {
        iVar1 = TacticalAIGroup::type(this_11);
        if (iVar1 == 0x67) {
          TacticalAIGroup::type(this_11);
          TacticalAIGroup::id(this_11);
          this_00 = extraout_ECX;
LAB_00500028:
          AIModule::logCommonHistory(this_00,(char *)param_1);
        }
        else {
          iVar1 = TacticalAIGroup::type(this_11);
          if (iVar1 == 0x68) {
            TacticalAIGroup::type(this_11);
            TacticalAIGroup::id(this_11);
            this_00 = extraout_ECX_00;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_11);
          if (iVar1 == 0x69) {
            TacticalAIGroup::type(this_11);
            TacticalAIGroup::id(this_11);
            this_00 = extraout_ECX_01;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_11);
          if (iVar1 == 0x6b) {
            TacticalAIGroup::type(this_11);
            TacticalAIGroup::id(this_11);
            this_00 = extraout_ECX_02;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_11);
          if (iVar1 == 0x6c) {
            TacticalAIGroup::type(this_11);
            TacticalAIGroup::id(this_11);
            this_00 = extraout_ECX_03;
            goto LAB_00500028;
          }
          iVar1 = TacticalAIGroup::type(this_11);
          if (iVar1 == 0x6a) {
            TacticalAIGroup::type(this_11);
            TacticalAIGroup::id(this_11);
            this_00 = extraout_ECX_04;
            goto LAB_00500028;
          }
        }
        iVar1 = TacticalAIGroup::inUse(this_11);
        iVar2 = TacticalAIGroup::action(this_11);
        uVar9 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::originalUnitNumber(this_11);
        iVar2 = TacticalAIGroup::desiredNumberUnits(this_11);
        uVar8 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::numberUnits(this_11);
        AIModule::logCommonHistory
                  (this_01,(char *)param_1,s_____NumUnits__d__DesNumUnits__d_,iVar1,uVar8,uVar9);
        iVar1 = TacticalAIGroup::assistGroupID(this_11);
        iVar2 = TacticalAIGroup::originalHitPoints(this_11);
        uVar9 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::currentHitPoints
                          (this_11,(TribeMainDecisionAIModule *)param_1[1]._padding_);
        iVar2 = TacticalAIGroup::commander(this_11);
        uVar8 = CONCAT44(iVar1,iVar2);
        iVar1 = TacticalAIGroup::target(this_11);
        AIModule::logCommonHistory
                  (this_02,(char *)param_1,s_____Target__d__CommanderID__d__H,iVar1,uVar8,uVar9);
        pWVar3 = TacticalAIGroup::location(this_11);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::location(this_11);
        AIModule::logCommonHistory
                  (this_03,(char *)param_1,s_____Location___f___f__,(double)pWVar3->x,dVar10);
        pWVar3 = TacticalAIGroup::gatherLocation(this_11);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::gatherLocation(this_11);
        AIModule::logCommonHistory
                  (this_04,(char *)param_1,s_____Gather_Location___f___f__,(double)pWVar3->x,dVar10)
        ;
        pWVar3 = TacticalAIGroup::retreatLocation(this_11);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::retreatLocation(this_11);
        AIModule::logCommonHistory
                  (this_05,(char *)param_1,s_____Retreat_Location___f___f__,(double)pWVar3->x,dVar10
                  );
        pWVar3 = TacticalAIGroup::targetLocation(this_11);
        dVar10 = (double)pWVar3->y;
        pWVar3 = TacticalAIGroup::targetLocation(this_11);
        AIModule::logCommonHistory
                  (this_06,(char *)param_1,s_____Target_Location___f___f__,(double)pWVar3->x,dVar10)
        ;
        iVar2 = 0;
        iVar1 = TacticalAIGroup::numberUnits(this_11);
        if (0 < iVar1) {
          do {
            TacticalAIGroup::unit(this_11,iVar2);
            AIModule::logCommonHistory(this_07,(char *)param_1,s_____Unit___d_);
            iVar1 = TacticalAIGroup::unit(this_11,iVar2);
            this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1[1]._padding_,iVar1);
            if (this == (RGE_Static_Object *)0x0) {
              AIModule::logCommonHistory(this_08,(char *)param_1);
            }
            else {
              pUVar4 = RGE_Static_Object::unitAI(this);
              if (pUVar4 == (UnitAIModule *)0x0) {
                AIModule::logCommonHistory(this_09,(char *)param_1);
              }
              else {
                pUVar4 = RGE_Static_Object::unitAI(this);
                UnitAIModule::currentOrderPriority(pUVar4);
                pUVar4 = RGE_Static_Object::unitAI(this);
                UnitAIModule::currentOrder(pUVar4);
                pUVar4 = RGE_Static_Object::unitAI(this);
                iVar1 = UnitAIModule::currentTarget(pUVar4);
                pUVar4 = RGE_Static_Object::unitAI(this);
                iVar5 = UnitAIModule::currentAction(pUVar4);
                uVar7 = (uint)this->object_state;
                iVar6 = TacticalAIGroup::unit(this_11,iVar2);
                AIModule::logCommonHistory
                          (this_10,(char *)param_1,s_____Unit__d__state__d__action__d,iVar6,uVar7,
                           iVar5,iVar1);
              }
            }
            iVar2 = iVar2 + 1;
            iVar1 = TacticalAIGroup::numberUnits(this_11);
          } while (iVar2 < iVar1);
        }
      }
      this_11 = this_11->next;
    } while (this_11 != (TacticalAIGroup *)(param_1[10].playerNameValue + 0x24));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00500259
// Address: 00500259
// XREFS: None
TacticalAIGroup * __thiscall FUN_00500259(int param_1,int param_2)
{
  TacticalAIGroup *pTVar1;
  int iVar2;
  TacticalAIGroup *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560b8b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar3 = (TacticalAIGroup *)operator_new(0x330);
  uStack_4 = 0;
  if (pTVar3 == (TacticalAIGroup *)0x0) {
    pTVar3 = (TacticalAIGroup *)0x0;
  }
  else {
    pTVar3 = (TacticalAIGroup *)TacticalAIGroup::TacticalAIGroup(pTVar3);
  }
  uStack_4 = 0xffffffff;
  if (pTVar3 == (TacticalAIGroup *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return (TacticalAIGroup *)0x0;
  }
  pTVar3->next = (TacticalAIGroup *)(param_1 + 0x9d4);
  pTVar1 = *(TacticalAIGroup **)(param_1 + 0x9dc);
  pTVar3->prev = pTVar1;
  pTVar1->next = pTVar3;
  *(TacticalAIGroup **)(param_1 + 0x9dc) = pTVar3;
  if (param_2 == 1) {
    iVar2 = *(int *)(param_1 + 0xd04);
    *(int *)(param_1 + 0xd04) = iVar2 + 1;
    TacticalAIGroup::setID(pTVar3,iVar2);
    *(int *)(param_1 + 0xd08) = *(int *)(param_1 + 0xd08) + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return pTVar3;
}

// --------------------------------------------------

// Function: FUN_0050031b
// Address: 0050031b
// XREFS: None
undefined4 __thiscall FUN_0050031b(int param_1,int param_2)
{
  int iVar1;
  TacticalAIGroup *this;
  
  this = *(TacticalAIGroup **)(param_1 + 0x9d8);
  if (this != (TacticalAIGroup *)(param_1 + 0x9d4)) {
    while (this != (TacticalAIGroup *)0x0) {
      iVar1 = TacticalAIGroup::id(this);
      if (iVar1 == param_2) {
        this->prev->next = this->next;
        this->next->prev = this->prev;
        if (this != (TacticalAIGroup *)0x0) {
          (**(code **)this->_padding_)(1);
        }
        *(int *)(param_1 + 0xd08) = *(int *)(param_1 + 0xd08) + -1;
        return 1;
      }
      this = this->next;
      if (this == (TacticalAIGroup *)(param_1 + 0x9d4)) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00500399
// Address: 00500399
// XREFS: None
undefined4 __thiscall FUN_00500399(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  TacticalAIGroup *this;
  
  this = *(TacticalAIGroup **)(param_1 + 0x9d8);
  if (this != (TacticalAIGroup *)(param_1 + 0x9d4)) {
    do {
      if (this == (TacticalAIGroup *)0x0) {
        return 1;
      }
      iVar2 = TacticalAIGroup::type(this);
      if ((iVar2 == param_2) || (param_2 == -1)) {
        this->prev->next = this->next;
        this->next->prev = this->prev;
        piVar1 = &this->_padding_;
        this = this->prev;
        (**(code **)*piVar1)(1);
        *(int *)(param_1 + 0xd08) = *(int *)(param_1 + 0xd08) + -1;
      }
      this = this->next;
    } while (this != (TacticalAIGroup *)(param_1 + 0x9d4));
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00500413
// Address: 00500413
// XREFS: None
TacticalAIGroup * __thiscall
FUN_00500413(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  TacticalAIGroup *this;
  
  this = *(TacticalAIGroup **)(param_1 + 0x9d8);
  if (this != (TacticalAIGroup *)(param_1 + 0x9d4)) {
    while (this != (TacticalAIGroup *)0x0) {
      if (((((param_2 == -1) || (iVar1 = TacticalAIGroup::id(this), iVar1 == param_2)) &&
           ((param_3 == -1 || (iVar1 = TacticalAIGroup::type(this), iVar1 == param_3)))) &&
          ((param_4 == -1 || (iVar1 = TacticalAIGroup::action(this), iVar1 == param_4)))) &&
         ((param_5 == -1 || (iVar1 = TacticalAIGroup::target(this), iVar1 == param_5)))) {
        return this;
      }
      this = this->next;
      if (this == (TacticalAIGroup *)(param_1 + 0x9d4)) {
        return (TacticalAIGroup *)0x0;
      }
    }
  }
  return (TacticalAIGroup *)0x0;
}

// --------------------------------------------------

// Function: FUN_005004b6
// Address: 005004b6
// XREFS: None
TacticalAIGroup * __thiscall
FUN_005004b6(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,uint param_6)
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *this;
  TacticalAIGroup *this_00;
  TacticalAIGroup *this_01;
  int iStack_10;
  TacticalAIGroup *pTStack_c;
  TacticalAIGroup *pTStack_8;
  
  this_01 = *(TacticalAIGroup **)(param_1 + 0x9d8);
  pTStack_8 = (TacticalAIGroup *)0x0;
  iStack_10 = -1;
  if (this_01 != (TacticalAIGroup *)(param_1 + 0x9d4)) {
    do {
      pTStack_c = (TacticalAIGroup *)(param_1 + 0x9d4);
      if (this_01 == (TacticalAIGroup *)0x0) {
        return pTStack_8;
      }
      if (((param_2 == -1) || (iVar3 = TacticalAIGroup::type(this_01), iVar3 == param_2)) &&
         ((param_3 == -1 || (iVar3 = TacticalAIGroup::action(this_01), iVar3 == param_3)))) {
        if (param_2 == 0x6a) {
          bVar1 = true;
          this_00 = *(TacticalAIGroup **)(param_1 + 0x9d8);
          if (this_00 != pTStack_c) {
            do {
              if (this_00 == (TacticalAIGroup *)0x0) break;
              if (!bVar1) goto LAB_00500651;
              iVar3 = TacticalAIGroup::id(this_01);
              iVar4 = TacticalAIGroup::assistGroupID(this_00);
              if (iVar4 == iVar3) {
                bVar1 = false;
              }
              this_00 = this_00->next;
            } while (this_00 != (TacticalAIGroup *)(param_1 + 0x9d4));
          }
          if (!bVar1) goto LAB_00500651;
        }
        if (param_6 != 0xffffffff) {
          iVar3 = TacticalAIGroup::commander(this_01);
          this = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),iVar3);
          if ((this == (RGE_Static_Object *)0x0) ||
             (bVar2 = RGE_Static_Object::currentZone(this), bVar2 != param_6)) goto LAB_00500651;
        }
        TacticalAIGroup::gatherLocation(this_01);
        __ftol();
        TacticalAIGroup::gatherLocation(this_01);
        __ftol();
        TacticalAIGroup::gatherLocation(this_01);
        __ftol();
        TacticalAIGroup::gatherLocation(this_01);
        __ftol();
        iVar3 = __ftol();
        if (((iVar3 < param_4) && (iStack_10 == -1)) || ((param_4 == -1 || (iVar3 < iStack_10)))) {
          iStack_10 = iVar3;
          pTStack_8 = this_01;
        }
      }
LAB_00500651:
      pTStack_c = (TacticalAIGroup *)(param_1 + 0x9d4);
      this_01 = this_01->next;
    } while (this_01 != pTStack_c);
  }
  return pTStack_8;
}

// --------------------------------------------------

// Function: FUN_0050066e
// Address: 0050066e
// XREFS: None
TacticalAIGroup * __thiscall FUN_0050066e(TribeTacticalAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  TacticalAIGroup *this;
  int iStack_c;
  TacticalAIGroup *pTStack_4;
  
  this = (param_1->groups).next;
  pTStack_4 = (TacticalAIGroup *)0x0;
  iStack_c = -1;
  if (this != &param_1->groups) {
    do {
      if (this == (TacticalAIGroup *)0x0) {
        return pTStack_4;
      }
      if ((param_2 == -1) || (iVar1 = TacticalAIGroup::type(this), iVar1 == param_2)) {
        iVar1 = TacticalAIGroup::desiredNumberUnits(this);
        iVar2 = TacticalAIGroup::numberUnits(this);
        if ((iVar1 <= iVar2) &&
           ((iVar1 = TacticalAIGroup::isGathered(this,param_1,param_1->md), iVar1 != 0 &&
            (iVar1 = TacticalAIGroup::allUnitsIdle(this,param_1->md,1), iVar1 != 0)))) {
          TacticalAIGroup::gatherLocation(this);
          __ftol();
          TacticalAIGroup::gatherLocation(this);
          __ftol();
          TacticalAIGroup::gatherLocation(this);
          __ftol();
          TacticalAIGroup::gatherLocation(this);
          __ftol();
          iVar1 = __ftol();
          if (((iVar1 < param_3) && (iStack_c == -1)) || (iVar1 < iStack_c)) {
            iStack_c = iVar1;
            pTStack_4 = this;
          }
        }
      }
      this = this->next;
    } while (this != &param_1->groups);
  }
  return pTStack_4;
}

// --------------------------------------------------

// Function: FUN_005007ad
// Address: 005007ad
// XREFS: None
void __thiscall FUN_005007ad(TribeTacticalAIModule *param_1,int param_2,int param_3)
{
  TacticalAIGroup *this;
  
  this = TribeTacticalAIModule::group(param_1,param_3,-1,-1,-1);
  if (this == (TacticalAIGroup *)0x0) {
    return;
  }
  TacticalAIGroup::addUnit(this,param_2,param_1->md);
  return;
}

// --------------------------------------------------

// Function: FUN_005007e2
// Address: 005007e2
// XREFS: None
int __thiscall FUN_005007e2(TribeTacticalAIModule *param_1,int param_2,int param_3)
{
  TacticalAIGroup *this;
  int iVar1;
  int iVar2;
  
  this = TribeTacticalAIModule::group(param_1,param_3,-1,-1,-1);
  if (this == (TacticalAIGroup *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::removeUnit(this,param_2,param_1->md);
  iVar2 = TacticalAIGroup::numberUnits(this);
  if (iVar2 == 0) {
    TribeTacticalAIModule::removeGroup(param_1,param_3);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00500843
// Address: 00500843
// XREFS: None
int __thiscall FUN_00500843(TribeTacticalAIModule *param_1,int param_2)
{
  TacticalAIGroup *this;
  int iVar1;
  int iVar2;
  
  this = TribeTacticalAIModule::groupUnitIsIn(param_1,param_2);
  if (this == (TacticalAIGroup *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::removeUnit(this,param_2,param_1->md);
  iVar2 = TacticalAIGroup::numberUnits(this);
  if (iVar2 == 0) {
    iVar2 = TacticalAIGroup::id(this);
    TribeTacticalAIModule::removeGroup(param_1,iVar2);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0050089e
// Address: 0050089e
// XREFS: None
TacticalAIGroup * __thiscall FUN_0050089e(int param_1,int param_2)
{
  int iVar1;
  TacticalAIGroup *this;
  
  this = *(TacticalAIGroup **)(param_1 + 0x9d8);
  if (this != (TacticalAIGroup *)(param_1 + 0x9d4)) {
    while (this != (TacticalAIGroup *)0x0) {
      iVar1 = TacticalAIGroup::containsUnit(this,param_2);
      if (iVar1 == 1) {
        return this;
      }
      this = this->next;
      if (this == (TacticalAIGroup *)(param_1 + 0x9d4)) {
        return (TacticalAIGroup *)0x0;
      }
    }
  }
  return (TacticalAIGroup *)0x0;
}

// --------------------------------------------------

// Function: FUN_005008e7
// Address: 005008e7
// XREFS: None
int __thiscall FUN_005008e7(int param_1,int param_2,int param_3)
{
  TacticalAIGroup *this;
  int iVar1;
  int iStack_4;
  
  this = *(TacticalAIGroup **)(param_1 + 0x9d8);
  iStack_4 = 0;
  for (; (this != (TacticalAIGroup *)(param_1 + 0x9d4) && (this != (TacticalAIGroup *)0x0));
      this = this->next) {
    if (((param_2 == -1) || (iVar1 = TacticalAIGroup::type(this), iVar1 == param_2)) &&
       ((param_3 == -1 || (iVar1 = TacticalAIGroup::action(this), iVar1 == param_3)))) {
      iStack_4 = iStack_4 + 1;
    }
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_00500997
// Address: 00500997
// XREFS: None
void __fastcall FUN_00500997(int param_1)
{
  void *pvVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xd34) + -1 < 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0xd34)) {
        do {
          if (0 < iVar2) break;
          iVar2 = iVar2 + 1;
          *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0xd28) + -4 + iVar2 * 4);
        } while (iVar2 < *(int *)(param_1 + 0xd34));
      }
      operator_delete(*(void **)(param_1 + 0xd28));
      *(void **)(param_1 + 0xd28) = pvVar1;
      *(undefined4 *)(param_1 + 0xd34) = 1;
    }
  }
  TribeInformationAIModule::numberGameIDsOwnedBy
            ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),-1,
             **(int **)(param_1 + 0xd28));
  return;
}

// --------------------------------------------------

// Function: FUN_00500a25
// Address: 00500a25
// XREFS: None
int __fastcall FUN_00500a25(TribeTacticalAIModule *param_1)
{
  int iVar1;
  TacticalAIGroup *pTVar2;
  
  iVar1 = TribeStrategyAIModule::currentVictoryCondition(&param_1->md->strategyAI);
  if (iVar1 == 0) {
    iVar1 = TribeStrategyAIModule::targetID(&param_1->md->strategyAI);
    pTVar2 = TribeTacticalAIModule::group(param_1,-1,-1,-1,iVar1);
    if (pTVar2 == (TacticalAIGroup *)0x0) {
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00500a79
// Address: 00500a79
// XREFS: None
int __fastcall FUN_00500a79(TribeTacticalAIModule *param_1)
{
  int iVar1;
  TacticalAIGroup *pTVar2;
  
  iVar1 = TribeStrategyAIModule::currentVictoryCondition(&param_1->md->strategyAI);
  if (iVar1 == 4) {
    iVar1 = TribeStrategyAIModule::secondTargetID(&param_1->md->strategyAI);
    pTVar2 = TribeTacticalAIModule::group(param_1,-1,-1,-1,iVar1);
    if (pTVar2 == (TacticalAIGroup *)0x0) {
      return iVar1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00500aca
// Address: 00500aca
// XREFS: None
void __fastcall FUN_00500aca(int param_1)
{
  TribeInformationAIModule::numberItemsToDefend
            ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec));
  return;
}

// --------------------------------------------------

// Function: FUN_00500ae1
// Address: 00500ae1
// XREFS: None
int __thiscall FUN_00500ae1(int param_1,int param_2)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x2b0) == 1) {
    iVar1 = *(int *)(param_1 + 0xd24);
    if (*(int *)(param_1 + 0x254) <= iVar1) {
      return *(int *)(param_1 + 0x254);
    }
  }
  else {
    if (param_2 == 0x2e) {
      return *(int *)(param_1 + 0xd24);
    }
    iVar1 = *(int *)(param_1 + 0x254);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00500b27
// Address: 00500b27
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
void __fastcall FUN_00500b27(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x32c);
  if (iVar1 < 1) {
    *(undefined4 *)(param_1 + 0xd24) = *(undefined4 *)(param_1 + 0x24c);
  }
  else {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x2d35);
    *(int *)(param_1 + 0xd24) = iVar2 % iVar1 + (*(int *)(param_1 + 0x24c) - iVar1 / 2);
  }
  if (*(int *)(param_1 + 0xd24) < 0) {
    *(undefined4 *)(param_1 + 0xd24) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00500b93
// Address: 00500b93
// XREFS: None
undefined4 __thiscall FUN_00500b93(int param_1,TacticalAIGroup *param_2)
{
  TacticalAIGroup *this;
  int iVar1;
  RGE_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  XYPoint *pXVar8;
  float fVar9;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  this = param_2;
  iVar1 = TacticalAIGroup::commander(param_2);
  pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),iVar1);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::type(param_2);
  if (iVar1 != 100) {
    iVar1 = TacticalAIGroup::type(param_2);
    if (iVar1 != 0x65) {
      iVar1 = TacticalAIGroup::type(param_2);
      param_2 = (TacticalAIGroup *)0x0;
      if (iVar1 != 0x66) goto LAB_00500c04;
    }
  }
  param_2 = (TacticalAIGroup *)0x1;
LAB_00500c04:
  pRVar3 = MainDecisionAIModule::object
                     (*(MainDecisionAIModule **)(param_1 + 0xf0),-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  XStack_10.x = __ftol();
  XStack_10.y = __ftol();
  iVar1 = *(int *)(param_1 + 0x2b4);
  iVar5 = *(int *)(param_1 + 0x1ec);
  pXVar8 = &XStack_8;
  pRVar3 = pRVar2;
  iVar4 = TacticalAIGroup::desiredNumberUnits(this);
  iVar1 = TribeInformationAIModule::findGatherPosition
                    ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_10,iVar4
                     ,(int)param_2,iVar5,iVar1,pRVar3,pXVar8);
  if (iVar1 == 1) {
    fVar9 = pRVar2->world_z;
    fVar7 = (float)XStack_8.y;
    fVar6 = (float)XStack_8.x;
  }
  else {
    fVar9 = pRVar2->world_z;
    fVar7 = pRVar2->world_y;
    fVar6 = pRVar2->world_x;
  }
  TacticalAIGroup::setGatherLocation(this,fVar6,fVar7,fVar9);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00500cbf
// Address: 00500cbf
// XREFS: None
undefined4 __thiscall FUN_00500cbf(int param_1,TacticalAIGroup *param_2)
{
  TacticalAIGroup *this;
  int iVar1;
  RGE_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  XYPoint *pXVar8;
  float fVar9;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  this = param_2;
  iVar1 = TacticalAIGroup::commander(param_2);
  pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),iVar1);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar1 = TacticalAIGroup::type(param_2);
  if (iVar1 == 100) {
LAB_00500d1c:
    param_2 = (TacticalAIGroup *)0x1;
  }
  else {
    iVar1 = TacticalAIGroup::type(param_2);
    if (iVar1 == 0x65) goto LAB_00500d1c;
    iVar1 = TacticalAIGroup::type(param_2);
    param_2 = (TacticalAIGroup *)0x0;
    if (iVar1 == 0x66) goto LAB_00500d1c;
  }
  pRVar3 = MainDecisionAIModule::object
                     (*(MainDecisionAIModule **)(param_1 + 0xf0),-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    XStack_10.x = __ftol();
    XStack_10.y = __ftol();
    iVar1 = *(int *)(param_1 + 0x2b4);
    iVar5 = *(int *)(param_1 + 0x1ec);
    pXVar8 = &XStack_8;
    pRVar3 = pRVar2;
    iVar4 = TacticalAIGroup::desiredNumberUnits(this);
    iVar1 = TribeInformationAIModule::findGatherPosition
                      ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_10,
                       iVar4,(int)param_2,iVar5,iVar1,pRVar3,pXVar8);
    if (iVar1 == 1) {
      fVar9 = pRVar2->world_z;
      fVar7 = (float)XStack_8.y;
      fVar6 = (float)XStack_8.x;
      goto LAB_00500dbf;
    }
  }
  fVar9 = pRVar2->world_z;
  fVar7 = pRVar2->world_y;
  fVar6 = pRVar2->world_x;
LAB_00500dbf:
  TacticalAIGroup::setAllLocations(this,fVar6,fVar7,fVar9);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00500dd5
// Address: 00500dd5
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00500dd5(int param_1,InfluenceMap *param_2)
{
  TacticalAIGroup *this;
  Waypoint *pWVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  for (this = *(TacticalAIGroup **)(param_1 + 0x9d8);
      (this != (TacticalAIGroup *)(param_1 + 0x9d4) && (this != (TacticalAIGroup *)0x0));
      this = this->next) {
    pWVar1 = TacticalAIGroup::gatherLocation(this);
    if (pWVar1->x != _DAT_00575758) {
      iVar2 = TacticalAIGroup::desiredNumberUnits(this);
      TribeInformationAIModule::groupInfluenceDimension
                ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),iVar2);
      TacticalAIGroup::gatherLocation(this);
      XStack_8.x = __ftol();
      TacticalAIGroup::gatherLocation(this);
      XStack_8.y = __ftol();
      TribeInformationAIModule::mapBound
                ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_8);
      TacticalAIGroup::gatherLocation(this);
      XStack_10.x = __ftol();
      TacticalAIGroup::gatherLocation(this);
      XStack_10.y = __ftol();
      TribeInformationAIModule::mapBound
                ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_10);
      InfluenceMap::setValue(param_2,XStack_8.x,XStack_8.y,XStack_10.x,XStack_10.y,0xff);
      TacticalAIGroup::gatherLocation(this);
      XStack_8.x = __ftol();
      TacticalAIGroup::gatherLocation(this);
      XStack_8.y = __ftol();
      TribeInformationAIModule::mapBound
                ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_8);
      TacticalAIGroup::gatherLocation(this);
      XStack_10.x = __ftol();
      TacticalAIGroup::gatherLocation(this);
      XStack_10.y = __ftol();
      TribeInformationAIModule::mapBound
                ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_10);
      InfluenceMap::decrementValue(param_2,XStack_8.x,XStack_8.y,XStack_10.x,XStack_10.y,'\n');
    }
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x128)) {
    do {
      if ((*(int *)(param_1 + 0x130) + -1 < iVar2) &&
         (pvVar3 = operator_new(iVar2 * 4 + 4), pvVar3 != (void *)0x0)) {
        iVar4 = 0;
        if (0 < *(int *)(param_1 + 0x130)) {
          do {
            if (iVar2 + 1 <= iVar4) break;
            iVar4 = iVar4 + 1;
            *(undefined4 *)((int)pvVar3 + iVar4 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x124) + -4 + iVar4 * 4);
          } while (iVar4 < *(int *)(param_1 + 0x130));
        }
        operator_delete(*(void **)(param_1 + 0x124));
        *(void **)(param_1 + 0x124) = pvVar3;
        *(int *)(param_1 + 0x130) = iVar2 + 1;
      }
      pRVar5 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0xf0),
                          *(int *)(*(int *)(param_1 + 0x124) + iVar2 * 4));
      if (pRVar5 != (RGE_Static_Object *)0x0) {
        XStack_10.x = __ftol();
        XStack_10.y = __ftol();
        TribeInformationAIModule::mapBound
                  ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_10);
        XStack_8.x = __ftol();
        XStack_8.y = __ftol();
        TribeInformationAIModule::mapBound
                  ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_8);
        InfluenceMap::setValue(param_2,XStack_10.x,XStack_10.y,XStack_8.x,XStack_8.y,0xff);
        TribeInformationAIModule::groupInfluenceDimension
                  ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),1);
        XStack_10.x = __ftol();
        XStack_10.y = __ftol();
        TribeInformationAIModule::mapBound
                  ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_10);
        XStack_8.x = __ftol();
        XStack_8.y = __ftol();
        TribeInformationAIModule::mapBound
                  ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),&XStack_8);
        InfluenceMap::decrementValue(param_2,XStack_10.x,XStack_10.y,XStack_8.x,XStack_8.y,'\n');
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x128));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00501184
// Address: 00501184
// XREFS: None
int __thiscall FUN_00501184(int param_1,TacticalAIGroup *param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int iStack_8;
  
  iVar3 = -1;
  iStack_8 = -1;
  iVar4 = 0;
  iVar1 = TacticalAIGroup::numberUnits(param_2);
  if (0 < iVar1) {
    do {
      iVar1 = TacticalAIGroup::unit(param_2,iVar4);
      pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),iVar1);
      if ((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->master_obj->id != 0x7d)) {
        if (*(int *)(param_1 + 0x2c0) == 2) {
          (**(code **)(pRVar2->_padding_ + 0x10c))();
        }
        iVar1 = __ftol();
        if ((*(int *)(param_1 + 0x2c0) == 1) || (*(int *)(param_1 + 0x2c0) == 3)) {
          if ((iVar3 == -1) || (iVar1 < iVar3)) goto LAB_00501228;
        }
        else if ((iVar3 == -1) || (iVar3 < iVar1)) {
LAB_00501228:
          iStack_8 = TacticalAIGroup::unit(param_2,iVar4);
          iVar3 = iVar1;
        }
      }
      iVar4 = iVar4 + 1;
      iVar1 = TacticalAIGroup::numberUnits(param_2);
    } while (iVar4 < iVar1);
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_00501254
// Address: 00501254
// XREFS: None
undefined4 __thiscall FUN_00501254(int param_1,int *param_2)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iStack_c;
  undefined4 uStack_8;
  
  iVar4 = -1;
  uStack_8 = 0xffffffff;
  iStack_c = 0;
  if (0 < param_2[1]) {
    do {
      if (param_2[3] + -1 < iStack_c) {
        pvVar1 = operator_new(iStack_c * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < param_2[3]) {
            do {
              if (iStack_c + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*param_2 + -4 + iVar2 * 4);
            } while (iVar2 < param_2[3]);
          }
          operator_delete((void *)*param_2);
          *param_2 = (int)pvVar1;
          param_2[3] = iStack_c + 1;
        }
      }
      pRVar3 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0xf0),
                          *(int *)(*param_2 + iStack_c * 4));
      if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->master_obj->id != 0x7d)) {
        if (*(int *)(param_1 + 0x2c0) == 2) {
          (**(code **)(pRVar3->_padding_ + 0x10c))();
        }
        iVar2 = __ftol();
        if ((*(int *)(param_1 + 0x2c0) == 1) || (*(int *)(param_1 + 0x2c0) == 3)) {
          if ((iVar4 == -1) || (iVar2 < iVar4)) {
            if (param_2[3] + -1 < iStack_c) {
              pvVar1 = operator_new(iStack_c * 4 + 4);
              if (pvVar1 != (void *)0x0) {
                iVar4 = 0;
                if (0 < param_2[3]) {
                  do {
                    if (iStack_c + 1 <= iVar4) break;
                    iVar4 = iVar4 + 1;
                    *(undefined4 *)((int)pvVar1 + iVar4 * 4 + -4) =
                         *(undefined4 *)(*param_2 + -4 + iVar4 * 4);
                  } while (iVar4 < param_2[3]);
                }
                operator_delete((void *)*param_2);
                *param_2 = (int)pvVar1;
                param_2[3] = iStack_c + 1;
              }
            }
            uStack_8 = *(undefined4 *)(*param_2 + iStack_c * 4);
            iVar4 = iVar2;
          }
        }
        else if ((iVar4 == -1) || (iVar4 < iVar2)) {
          if (param_2[3] + -1 < iStack_c) {
            pvVar1 = operator_new(iStack_c * 4 + 4);
            if (pvVar1 != (void *)0x0) {
              iVar4 = 0;
              if (0 < param_2[3]) {
                do {
                  if (iStack_c + 1 <= iVar4) break;
                  iVar4 = iVar4 + 1;
                  *(undefined4 *)((int)pvVar1 + iVar4 * 4 + -4) =
                       *(undefined4 *)(*param_2 + -4 + iVar4 * 4);
                } while (iVar4 < param_2[3]);
              }
              operator_delete((void *)*param_2);
              *param_2 = (int)pvVar1;
              param_2[3] = iStack_c + 1;
            }
          }
          uStack_8 = *(undefined4 *)(*param_2 + iStack_c * 4);
          iVar4 = iVar2;
        }
      }
      iStack_c = iStack_c + 1;
    } while (iStack_c < param_2[1]);
  }
  return uStack_8;
}

// --------------------------------------------------

// Function: FUN_0050142f
// Address: 0050142f
// XREFS: None
bool __thiscall FUN_0050142f(TribeTacticalAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  float10 fVar5;
  XYPoint XStack_14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  if ((param_2 == 0) || (param_3 == 0)) {
    return false;
  }
  iVar3 = (param_1->civilianExplorers).numberValue;
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      if ((param_1->civilianExplorers).maximumSizeValue <= iVar2) break;
      if ((param_1->civilianExplorers).value[iVar2] == *(int *)(param_3 + 4)) {
        return false;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  param_2 = 0;
  XStack_14.x = __ftol();
  XStack_14.y = __ftol();
  iVar3 = TribeTacticalAIModule::civilian(param_1,&XStack_14,1,700,0x2c9,0x2c9,1);
  while (((iVar3 != -1 && (param_2 < param_1->sn[100])) &&
         (pRVar4 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar3),
         pRVar4 != (RGE_Static_Object *)0x0))) {
    uStack_c = __ftol();
    uStack_8 = __ftol();
    uStack_4 = __ftol();
    iVar2 = pRVar4->_padding_;
    fVar5 = (float10)(**(code **)(iVar2 + 0x10c))
                               (*(undefined4 *)(iVar1 + 4),0,1,0xffffffff,0xffffffff);
    iVar2 = (**(code **)(iVar2 + 0x198))(uStack_c,uStack_8,uStack_4,(float)fVar5);
    if (iVar2 == 0) break;
    TribeTacticalAIModule::taskAttacker
              (param_1,iVar3,*(float *)(iVar1 + 0x38),*(float *)(iVar1 + 0x3c),*(int *)(iVar1 + 4),
               (int)*(short *)(*(int *)(iVar1 + 0xc) + 0x4a),(Waypoint *)0x0,0,-1,0);
    param_2 = param_2 + 1;
    iVar3 = TribeTacticalAIModule::civilian(param_1,&XStack_14,1,700,0x2c9,0x2c9,1);
  }
  return 0 < param_2;
}

// --------------------------------------------------

// Function: FUN_005015d8
// Address: 005015d8
// XREFS: None
void __thiscall FUN_005015d8(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)
{
  undefined1 uStack00000009;
  undefined1 uStack0000000a;
  
  uStack00000009 = param_4;
  uStack0000000a = 1;
  (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x44))(param_2,&param_3,1);
  return;
}

// --------------------------------------------------

// Function: FUN_00501615
// Address: 00501615
// XREFS: None
undefined4 __thiscall FUN_00501615(int param_1,int param_2)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),param_2);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  sVar1 = pRVar2->master_obj->object_group;
  if ((sVar1 != 0x12) && (sVar1 != 0xd)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00501657
// Address: 00501657
// XREFS: None
void __thiscall FUN_00501657(int param_1,int param_2)
{
  if ((*(int *)(param_1 + 0xe18) != 1) &&
     ((*(int *)(param_1 + 0x3ac) == 0 || (*(int *)(param_1 + 0x3ac) == param_2)))) {
    *(undefined4 *)(param_1 + 0xe18) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00501688
// Address: 00501688
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_00501688(int param_1,int param_2,XYPoint *param_3)
{
  XYPoint *pXVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Static_Object *this;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fStack_10;
  int iStack_8;
  int iStack_4;
  
  pXVar1 = param_3;
  this = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),param_2);
  if (this == (RGE_Static_Object *)0x0) {
    return false;
  }
  uVar2 = RGE_Static_Object::currentZone(this);
  pRVar4 = MainDecisionAIModule::object
                     (*(MainDecisionAIModule **)(param_1 + 0xf0),-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
  fStack_10 = -1.0;
  iStack_8 = -1;
  iStack_4 = -1;
  iVar5 = -1;
  iVar6 = -1;
  if (pRVar4 != (RGE_Static_Object *)0x0) {
    param_3 = (XYPoint *)0x0;
    do {
      iVar5 = __ftol();
      pXVar1->x = iVar5;
      iVar5 = __ftol();
      pXVar1->y = iVar5;
      switch(param_3) {
      case (XYPoint *)0x0:
        pXVar1->x = pXVar1->x + -10;
        pXVar1->y = pXVar1->y + -10;
        break;
      case (XYPoint *)0x2:
        iVar5 = pXVar1->y;
        pXVar1->x = pXVar1->x + 10;
      case (XYPoint *)0x1:
        pXVar1->y = iVar5 + -10;
        break;
      case (XYPoint *)0x3:
        iVar5 = pXVar1->x + 10;
        goto LAB_00501784;
      case (XYPoint *)0x4:
        pXVar1->x = pXVar1->x + 10;
        pXVar1->y = pXVar1->y + 10;
        break;
      case (XYPoint *)0x6:
        iVar5 = pXVar1->y;
        pXVar1->x = pXVar1->x + -10;
      case (XYPoint *)0x5:
        pXVar1->y = iVar5 + 10;
        break;
      case (XYPoint *)0x7:
        iVar5 = pXVar1->x + -10;
LAB_00501784:
        pXVar1->x = iVar5;
      }
      if (((-1 < pXVar1->x) && (-1 < pXVar1->y)) &&
         (iVar5 = TribeInformationAIModule::mapXSize
                            ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec)),
         pXVar1->x < iVar5)) {
        iVar5 = pXVar1->y;
        iVar6 = TribeInformationAIModule::mapYSize
                          ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec));
        if (((iVar5 < iVar6) &&
            (iVar5 = TribeInformationAIModule::tileUncovered
                               ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),
                                pXVar1->x,iVar5), iVar5 != 1)) &&
           ((uVar3 = RGE_Static_Object::lookupZone(this,pXVar1->x,pXVar1->y), uVar2 == uVar3 &&
            ((fVar7 = RGE_Static_Object::distance_to_position
                                (this,(float)pXVar1->x,(float)pXVar1->y,this->world_z),
             fStack_10 == _DAT_00575758 || (fVar7 < fStack_10)))))) {
          iStack_8 = pXVar1->x;
          iStack_4 = pXVar1->y;
          fStack_10 = fVar7;
        }
      }
      param_3 = (XYPoint *)((int)param_3 + 1);
      iVar5 = iStack_8;
      iVar6 = iStack_4;
    } while ((int)param_3 < 8);
  }
  if (fStack_10 == _DAT_00575758) {
    iVar5 = TribeInformationAIModule::unexploredPlayerLocation
                      ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),param_2,pXVar1
                      );
    return iVar5 != 0;
  }
  pXVar1->x = iVar5;
  pXVar1->y = iVar6;
  TribeInformationAIModule::setTileExplored
            ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),iVar5,iVar6);
  return true;
}

// --------------------------------------------------

// Function: FUN_005018c1
// Address: 005018c1
// XREFS: None
int __fastcall FUN_005018c1(int param_1,int param_2)
{
  int in_EAX;
  int iVar1;
  byte bVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_EBP;
  byte *unaff_EDI;
  
  bVar2 = (byte)param_2;
  *unaff_EDI = *unaff_EDI ^ bVar2;
  unaff_EDI[param_2 + 0x50] = unaff_EDI[param_2 + 0x50] + (char)param_1;
  *(char *)(param_2 + 0x17) = *(char *)(param_2 + 0x17) + (char)in_EAX;
  unaff_EDI[param_2 + 0x50] = unaff_EDI[param_2 + 0x50] + bVar2;
  *(char *)(unaff_EBX + 0x17) = *(char *)(unaff_EBX + 0x17) + (char)unaff_EBX;
  unaff_EDI[0x17] = unaff_EDI[0x17] + (char)((uint)param_2 >> 8);
  *(char *)(unaff_EBP + 0x17) = *(char *)(unaff_EBP + 0x17) + (char)((uint)param_1 >> 8);
  unaff_EDI[0x17] = unaff_EDI[0x17] + (char)((uint)unaff_EBX >> 8);
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + bVar2;
  iVar1 = 0;
  piVar3 = (int *)(param_1 + 0x51c);
  do {
    if (*piVar3 == in_EAX) {
      return param_1 + 0x51c + iVar1 * 0x18;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 6;
  } while (iVar1 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0050191e
// Address: 0050191e
// XREFS: None
// [HELPER] s_ERROR_adding_gatherer_id__1_: "ERROR adding gatherer id -1."
char * __thiscall FUN_0050191e(AIModule *param_1,int param_2)
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == -1) {
    AIModule::logCommonHistory(param_1,(char *)param_1,s_ERROR_adding_gatherer_id__1_);
    return (char *)0x0;
  }
  iVar1 = 0;
  pcVar2 = param_1[5].playerNameValue + 0x1c;
  iVar3 = -1;
  while (((*(int *)pcVar2 == -1 && (iVar4 = iVar1, iVar3 == -1)) ||
         (iVar4 = iVar3, *(int *)pcVar2 != param_2))) {
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x18;
    iVar3 = iVar4;
    if (0x31 < iVar1) {
      if (iVar4 != -1) {
        *(int *)(param_1[5].playerNameValue + iVar4 * 0x18 + 0x1c) = param_2;
        pcVar2 = param_1[5].historyLogFilename + iVar4 * 0x18 + -0x28;
        pcVar2[0] = -1;
        pcVar2[1] = -1;
        pcVar2[2] = -1;
        pcVar2[3] = -1;
        pcVar2 = param_1[5].historyLogFilename + iVar4 * 0x18 + -0x24;
        pcVar2[0] = '\0';
        pcVar2[1] = '\0';
        pcVar2[2] = '\0';
        pcVar2[3] = '\0';
        *(int *)(param_1[10].playerNameValue + 0x1c) =
             *(int *)(param_1[10].playerNameValue + 0x1c) + 1;
        return param_1[5].playerNameValue + iVar4 * 0x18 + 0x1c;
      }
      return (char *)0x0;
    }
  }
  return param_1[5].playerNameValue + iVar1 * 0x18 + 0x1c;
}

// --------------------------------------------------

// Function: FUN_005019bb
// Address: 005019bb
// XREFS: None
// [HELPER] s_ERROR_removing_gatherer_id__1_: "ERROR removing gatherer id -1."
undefined4 __thiscall FUN_005019bb(AIModule *param_1,int param_2)
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_2 == -1) {
    AIModule::logCommonHistory(param_1,(char *)param_1,s_ERROR_removing_gatherer_id__1_);
    return 0;
  }
  iVar3 = 0;
  pcVar2 = param_1[5].playerNameValue + 0x1c;
  do {
    if (*(int *)pcVar2 == param_2) {
      pcVar2 = param_1[5].playerNameValue + iVar3 * 0x18 + 0x20;
      pcVar1 = param_1[5].playerNameValue + iVar3 * 0x18 + 0x1c;
      pcVar1[0] = -1;
      pcVar1[1] = -1;
      pcVar1[2] = -1;
      pcVar1[3] = -1;
      pcVar2[0] = -1;
      pcVar2[1] = -1;
      pcVar2[2] = -1;
      pcVar2[3] = -1;
      pcVar1 = param_1[5].playerNameValue + iVar3 * 0x18 + 0x24;
      pcVar1[0] = -1;
      pcVar1[1] = -1;
      pcVar1[2] = -1;
      pcVar1[3] = -1;
      pcVar1 = param_1[5].playerNameValue + iVar3 * 0x18 + 0x28;
      pcVar1[0] = -1;
      pcVar1[1] = -1;
      pcVar1[2] = -1;
      pcVar1[3] = -1;
      pcVar1 = param_1[5].historyLogFilename + iVar3 * 0x18 + -0x28;
      pcVar1[0] = -1;
      pcVar1[1] = -1;
      pcVar1[2] = -1;
      pcVar1[3] = -1;
      *(int *)(param_1[10].playerNameValue + 0x1c) =
           *(int *)(param_1[10].playerNameValue + 0x1c) + -1;
      for (; (iVar3 < 0x31 && (*(int *)(pcVar2 + 0x14) != -1)); pcVar2 = pcVar2 + 0x18) {
        *(int *)(pcVar2 + -4) = *(int *)(pcVar2 + 0x14);
        *(undefined4 *)pcVar2 = *(undefined4 *)(pcVar2 + 0x18);
        *(undefined4 *)(pcVar2 + 4) = *(undefined4 *)(pcVar2 + 0x1c);
        *(undefined4 *)(pcVar2 + 8) = *(undefined4 *)(pcVar2 + 0x20);
        *(undefined4 *)(pcVar2 + 0xc) = *(undefined4 *)(pcVar2 + 0x24);
        pcVar2[0x14] = -1;
        pcVar2[0x15] = -1;
        pcVar2[0x16] = -1;
        pcVar2[0x17] = -1;
        pcVar2[0x18] = -1;
        pcVar2[0x19] = -1;
        pcVar2[0x1a] = -1;
        pcVar2[0x1b] = -1;
        pcVar2[0x1c] = -1;
        pcVar2[0x1d] = -1;
        pcVar2[0x1e] = -1;
        pcVar2[0x1f] = -1;
        pcVar2[0x20] = -1;
        pcVar2[0x21] = -1;
        pcVar2[0x22] = -1;
        pcVar2[0x23] = -1;
        pcVar2[0x24] = -1;
        pcVar2[0x25] = -1;
        pcVar2[0x26] = -1;
        pcVar2[0x27] = -1;
        iVar3 = iVar3 + 1;
      }
      return 1;
    }
    iVar3 = iVar3 + 1;
    pcVar2 = pcVar2 + 0x18;
  } while (iVar3 < 0x32);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00501aa6
// Address: 00501aa6
// XREFS: None
int __thiscall FUN_00501aa6(int param_1,int param_2)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0xd78 + param_2 * 4) == 0) {
    return *(int *)(param_1 + 0x3e4);
  }
  iVar1 = ResourceItem::value((ResourceItem *)(param_1 + 0xda8),param_2);
  return iVar1 / *(int *)(param_1 + 0xd78 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_00501ae7
// Address: 00501ae7
// XREFS: None
void __thiscall FUN_00501ae7(TribeTacticalAIModule *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  UnitData *pUVar2;
  
  if (param_1->resourceDifferenceValue[param_3] < 0) {
    iVar1 = TribeResourceAIModule::resource(&param_1->md->resourceAI,param_3);
    if (0 < iVar1 + param_1->resourceDifferenceValue[param_3]) {
      TribeTacticalAIModule::updateNeededResources(param_1);
    }
  }
  pUVar2 = TribeTacticalAIModule::gatherer(param_1,param_2);
  if ((pUVar2 != (UnitData *)0x0) && (pUVar2->data1 == param_3)) {
    pUVar2->data3 = pUVar2->data3 + param_4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00501b4d
// Address: 00501b4d
// XREFS: None
undefined4 __thiscall FUN_00501b4d(int param_1,int param_2)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),param_2);
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    uVar1 = TRIBE_Player::command_delete_object
                      (*(TRIBE_Player **)(*(int *)(param_1 + 0xf0) + 0x1256c),pRVar2);
    if (uVar1 == '\x01') {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00501b8c
// Address: 00501b8c
// XREFS: None
uint __thiscall FUN_00501b8c(int param_1,int *param_2,int *param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = BuildAIModule::numberUnbuiltItemsOfType
                    ((BuildAIModule *)(*(int *)(param_1 + 0xf0) + 0x104),0x67,0);
  *param_3 = iVar1;
  if (0 < iVar1) {
    return 0;
  }
  iVar1 = TribeResourceAIModule::resource
                    ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),param_4);
  if (*(int *)(param_1 + 0x48c + param_4 * 4) <= iVar1) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x3ec);
  if (iVar1 != -1) {
    iVar3 = *(int *)(param_1 + 0xf0);
    iVar2 = __ftol();
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    iVar3 = BuildAIModule::numberItemsOfType((BuildAIModule *)(iVar3 + 0x104),0x67,0);
    uVar4 = iVar2 * iVar1 - iVar3;
    *param_2 = iVar3;
    return ((int)uVar4 < 0) - 1 & uVar4;
  }
  iVar1 = BuildAIModule::numberItemsOfType
                    ((BuildAIModule *)(*(int *)(param_1 + 0xf0) + 0x104),0x67,0);
  *param_2 = iVar1;
  uVar4 = TribeInformationAIModule::numberAvailableStoragePits
                    ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec),param_4);
  return uVar4;
}

// --------------------------------------------------

// Function: FUN_00501c6e
// Address: 00501c6e
// XREFS: None
int __thiscall FUN_00501c6e(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  
  iVar1 = BuildAIModule::numberUnbuiltItemsOfType
                    ((BuildAIModule *)(*(int *)(param_1 + 0xf0) + 0x104),0x44,0);
  *param_3 = iVar1;
  if (0 < iVar1) {
    return 0;
  }
  iVar1 = TribeResourceAIModule::resource
                    ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),0);
  if (*(int *)(param_1 + 0x48c) <= iVar1) {
    return 0;
  }
  if (*(int *)(param_1 + 0x3f0) != -1) {
    iVar1 = BuildAIModule::numberItemsOfType
                      ((BuildAIModule *)(*(int *)(param_1 + 0xf0) + 0x104),0x44,0);
    *param_2 = iVar1;
    if (*(int *)(param_1 + 0x3f0) <= iVar1) {
      return 0;
    }
  }
  iVar1 = BuildAIModule::numberItemsOfType
                    ((BuildAIModule *)(*(int *)(param_1 + 0xf0) + 0x104),0x44,0);
  *param_2 = iVar1;
  iVar1 = TribeInformationAIModule::numberAvailableGranaries
                    ((TribeInformationAIModule *)(*(int *)(param_1 + 0xf0) + 0xcec));
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00501d64
// Address: 00501d64
// XREFS: None
void __thiscall FUN_00501d64(TribeTacticalAIModule *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  int aiStack_84 [2];
  ResourceItem RStack_7c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560bb0;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 0x32) {
    if ((param_1->sn[0xce] != 1) || (iVar2 = TribeTacticalAIModule::inAge(param_1,4), iVar2 == 0))
    goto LAB_00502084;
    ResourceItem::ResourceItem(&RStack_7c,4);
    iVar2 = 0;
    uStack_4 = 0;
    if (0 < param_3) {
      do {
        iVar1 = ResourceItem::value(&RStack_7c,iVar2);
        ResourceItem::setValue(&RStack_7c,iVar2,iVar1 * param_3);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3);
    }
    TRIBE_Player::objectCost(param_1->md->aiPlayer,0x32,-1,&RStack_7c,1);
    iVar2 = TribeResourceAIModule::resourcesAvailable(&param_1->md->resourceAI,&RStack_7c);
    if ((((iVar2 != 0) &&
         (iVar2 = TRIBE_Player::objectAvailable(param_1->md->aiPlayer,0x32), iVar2 != 0)) &&
        (iVar2 = TribeBuildAIModule::allBuilt(&param_1->md->buildAI,0,0), iVar2 != 0)) &&
       (iVar2 = (**(code **)((param_1->md->buildAI)._padding_ + 0x48))(0x32,0),
       iVar2 < param_1->sn[0xdc])) {
      TribeBuildAIModule::insert(&param_1->md->buildAI,0x32,param_3,param_4);
    }
  }
  else {
    if (param_2 == 0x44) {
      if ((param_1->sn[0xcd] == 1) && ((param_1->md->informationAI).closestDropsiteValue[0] != -1))
{
        aiStack_84[1] = 0;
        aiStack_84[0] = 0;
        iVar2 = TribeTacticalAIModule::numberAvailableGranaries(param_1,aiStack_84 + 1,aiStack_84);
        if ((aiStack_84[0] < 1) &&
           ((0 < iVar2 && (param_1->sn[0xa3] < (param_1->md->informationAI).closestDropsiteValue[0])
            ))) {
          TribeBuildAIModule::insert(&param_1->md->buildAI,0x44,param_3,param_4);
        }
      }
      goto LAB_00502084;
    }
    if ((param_2 != 0x4f) || (param_1->sn[0xcf] != 1)) goto LAB_00502084;
    ResourceItem::ResourceItem(&RStack_7c,4);
    iVar2 = 0;
    uStack_4 = 1;
    if (0 < param_3) {
      do {
        iVar1 = ResourceItem::value(&RStack_7c,iVar2);
        ResourceItem::setValue(&RStack_7c,iVar2,iVar1 * param_3);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3);
    }
    TRIBE_Player::objectCost(param_1->md->aiPlayer,0x4f,-1,&RStack_7c,1);
    iVar2 = TribeResourceAIModule::resourcesAvailable(&param_1->md->resourceAI,&RStack_7c);
    if ((((iVar2 != 0) &&
         (iVar2 = TRIBE_Player::objectAvailable(param_1->md->aiPlayer,0x4f), iVar2 != 0)) &&
        (iVar2 = TribeBuildAIModule::allBuilt(&param_1->md->buildAI,0,0), iVar2 != 0)) &&
       (iVar2 = (**(code **)((param_1->md->buildAI)._padding_ + 0x48))(0x4f,0),
       iVar2 < param_1->sn[0xde])) {
      TribeBuildAIModule::insert(&param_1->md->buildAI,0x4f,param_3,param_4);
    }
  }
  uStack_4 = 0xffffffff;
  ResourceItem::~ResourceItem(&RStack_7c);
LAB_00502084:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0050209e
// Address: 0050209e
// XREFS: None
undefined4 FUN_0050209e(RGE_Static_Object *param_1)
{
  UnitAIModule *pUVar1;
  int iVar2;
  
  if (((param_1 != (RGE_Static_Object *)0x0) &&
      (pUVar1 = RGE_Static_Object::unitAI(param_1), pUVar1 != (UnitAIModule *)0x0)) &&
     (param_1->master_obj->id == 0x103)) {
    pUVar1 = RGE_Static_Object::unitAI(param_1);
    iVar2 = UnitAIModule::currentAction(pUVar1);
    if (iVar2 != 0x261) {
      pUVar1 = RGE_Static_Object::unitAI(param_1);
      iVar2 = UnitAIModule::currentAction(pUVar1);
      if (iVar2 != 0x262) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005020f8
// Address: 005020f8
// XREFS: None
int __fastcall FUN_005020f8(int param_1)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if (*(int *)(param_1 + 0x100) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x100)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xf4) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x100));
          }
          operator_delete(*(void **)(param_1 + 0xf4));
          *(void **)(param_1 + 0xf4) = pvVar1;
          *(int *)(param_1 + 0x100) = iVar4 + 1;
        }
      }
      this = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(param_1 + 0xf0),
                        *(int *)(*(int *)(param_1 + 0xf4) + iVar4 * 4));
      if (((this != (RGE_Static_Object *)0x0) &&
          (pUVar3 = RGE_Static_Object::unitAI(this), pUVar3 != (UnitAIModule *)0x0)) &&
         (this->master_obj->id == 0x103)) {
        pUVar3 = RGE_Static_Object::unitAI(this);
        iVar2 = UnitAIModule::currentAction(pUVar3);
        if (iVar2 != 0x261) {
          pUVar3 = RGE_Static_Object::unitAI(this);
          iVar2 = UnitAIModule::currentAction(pUVar3);
          if (iVar2 != 0x262) goto LAB_005021e0;
        }
        iStack_4 = iStack_4 + 1;
      }
LAB_005021e0:
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xf8));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_005021f9
// Address: 005021f9
// XREFS: None
bool FUN_005021f9(int param_1)
{
  int iVar1;
  
  iVar1 = __ftol();
  return iVar1 == param_1;
}

// --------------------------------------------------

// Function: FUN_00502227
// Address: 00502227
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00502227(TacticalAIGroup *param_1,Path *param_2)
{
  Path *this;
  int iVar1;
  int iVar2;
  Waypoint *pWVar3;
  int iVar4;
  float fVar5;
  float fStack_4;
  
  this = param_2;
  fStack_4 = Path::length(param_2);
  fStack_4 = fStack_4 * _DAT_00575778;
  if (fStack_4 < _DAT_0057577c) {
    fStack_4 = 10.0;
  }
  Path::initToStart(param_2);
  fVar5 = Path::distanceToNextWaypoint(param_2);
  Path::moveToNextWaypoint(param_2);
  iVar1 = Path::numberOfWaypoints(param_2);
  iVar4 = 1;
  iVar2 = Path::numberOfWaypoints(param_2);
  param_2 = (Path *)fVar5;
  if (1 < iVar2 + -1) {
    do {
      if (((iVar1 < 6) || (fStack_4 <= (float)param_2)) &&
         ((iVar1 >= 6 || (_DAT_00575780 <= (float)param_2)))) {
        pWVar3 = Path::currentWaypoint(this);
        fVar5 = pWVar3->y;
        pWVar3 = Path::currentWaypoint(this);
        TacticalAIGroup::addAttackWaypoint(param_1,pWVar3->x,fVar5);
      }
      fVar5 = Path::distanceToNextWaypoint(this);
      iVar4 = iVar4 + 1;
      Path::moveToNextWaypoint(this);
      iVar2 = Path::numberOfWaypoints(this);
      param_2 = (Path *)(fVar5 + (float)param_2);
    } while (iVar4 < iVar2 + -1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00502451
// Address: 00502451
// XREFS: None
void FUN_00502451(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502451:
  iVar3 = 0x4b;
  iVar4 = 0xc;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      goto code_r0x00502451;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050245d
// Address: 0050245d
// XREFS: None
void FUN_0050245d(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050245d:
  iVar3 = 0x5d;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,unaff_EDI,-1,-1,-1,-1,-1,-1,
                        -1,-1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar1 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar1 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    unaff_EDI = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      unaff_EDI = 0xc;
      goto LAB_005024bd;
    case 3:
      goto code_r0x0050245d;
    case 4:
      iVar3 = 0x27;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      unaff_EDI = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      unaff_EDI = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      unaff_EDI = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  unaff_EDI = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_00502464
// Address: 00502464
// XREFS: None
void FUN_00502464(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502464:
  iVar3 = 0x27;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      goto code_r0x00502464;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_00502470
// Address: 00502470
// XREFS: None
void FUN_00502470(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502470:
  iVar3 = 0x49;
  iVar4 = 0xc;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      goto code_r0x00502470;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050247c
// Address: 0050247c
// XREFS: None
void FUN_0050247c(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050247c:
  iVar3 = 5;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      goto code_r0x0050247c;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_00502488
// Address: 00502488
// XREFS: None
void FUN_00502488(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x00502488:
  iVar3 = 299;
LAB_005024b8:
  iVar4 = 0x65;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      iVar3 = 0x25;
      goto LAB_005024b8;
    case 2:
      goto FUN_00502451;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      goto code_r0x00502488;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
FUN_00502451:
  iVar3 = 0x4b;
  iVar4 = 0xc;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050248f
// Address: 0050248f
// XREFS: None
void FUN_0050248f(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050248f:
  iVar3 = 4;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      goto code_r0x0050248f;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_0050249b
// Address: 0050249b
// XREFS: None
void FUN_0050249b(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x0050249b:
  iVar3 = 0x7d;
  iVar4 = 0x68;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      goto code_r0x0050249b;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_005024a7
// Address: 005024a7
// XREFS: None
void FUN_005024a7(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x005024a7:
  iVar3 = 0x29;
  iVar4 = 0x57;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      goto switchD_005023fa_caseD_1;
    case 2:
      iVar3 = 0x4b;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      goto code_r0x005024a7;
    case 0xb:
      iVar3 = 0x28;
      goto LAB_005024b8;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
switchD_005023fa_caseD_1:
  iVar3 = 0x25;
LAB_005024b8:
  iVar4 = 0x65;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_005024b3
// Address: 005024b3
// XREFS: None
void FUN_005024b3(void)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000088;
  undefined4 in_stack_00000090;
  
code_r0x005024b3:
  iVar3 = 0x28;
LAB_005024b8:
                    /* language.dll match for 0x65: "1" */
  iVar4 = 0x65;
LAB_005024bd:
  iVar1 = TRIBE_Player::objectAvailable
                    (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3);
  if (iVar1 == 0) {
    in_stack_00000010 = in_stack_00000010 + 1;
  }
  else {
    pRVar2 = MainDecisionAIModule::object
                       (*(MainDecisionAIModule **)(unaff_EBX + 0xf0),-1,iVar4,-1,-1,-1,-1,-1,-1,-1,
                        -1);
    if (pRVar2 == (RGE_Static_Object *)0x0) {
      in_stack_00000010 = in_stack_00000010 + 1;
    }
    else {
      ResourceItem::ResourceItem((ResourceItem *)&stack0x00000018,4);
      in_stack_00000090 = 0;
      TRIBE_Player::objectCost
                (*(TRIBE_Player **)(*(int *)(unaff_EBX + 0xf0) + 0x1256c),iVar3,-1,
                 (ResourceItem *)&stack0x00000018,1);
      iVar4 = TribeResourceAIModule::resourcesAvailable
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),
                         (ResourceItem *)&stack0x00000018);
      if (iVar4 == 1) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),iVar3,1,0);
        unaff_EBP = unaff_EBP + -1;
        in_stack_00000014 = 1;
      }
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000090 = 0xffffffff;
      ResourceItem::~ResourceItem((ResourceItem *)&stack0x00000018);
    }
  }
  do {
    iVar4 = 0;
    if (unaff_EBP < 1) {
LAB_005025af:
      *unaff_FS_OFFSET = in_stack_00000088;
      return;
    }
    switch(in_stack_00000010) {
    case 0:
      iVar3 = TribeResourceAIModule::resource
                        ((TribeResourceAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x10d7c),2);
      if ((0x95 < iVar3) && (2 < *(int *)(unaff_EBX + 0xf8))) {
        TribeBuildAIModule::insert
                  ((TribeBuildAIModule *)(*(int *)(unaff_EBX + 0xf0) + 0x104),0x4f,1,0);
        unaff_EBP = unaff_EBP + -2;
      }
      in_stack_00000010 = 1;
      break;
    case 1:
      iVar3 = 0x25;
      goto LAB_005024b8;
    case 2:
      goto FUN_00502451;
    case 3:
      iVar3 = 0x5d;
      goto LAB_005024bd;
    case 4:
      iVar3 = 0x27;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 5:
      iVar3 = 0x49;
      iVar4 = 0xc;
      goto LAB_005024bd;
    case 6:
      iVar3 = 5;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 7:
      iVar3 = 299;
      goto LAB_005024b8;
    case 8:
      iVar3 = 4;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 9:
      iVar3 = 0x7d;
      iVar4 = 0x68;
      goto LAB_005024bd;
    case 10:
      iVar3 = 0x29;
      iVar4 = 0x57;
      goto LAB_005024bd;
    case 0xb:
      goto code_r0x005024b3;
    default:
      if (in_stack_00000014 != 1) goto LAB_005025af;
      in_stack_00000010 = 1;
      in_stack_00000014 = 0;
    }
  } while( true );
FUN_00502451:
  iVar3 = 0x4b;
  iVar4 = 0xc;
  goto LAB_005024bd;
}

// --------------------------------------------------

// Function: FUN_005025ca
// Address: 005025ca
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
uint __fastcall FUN_005025ca(int param_1,int param_2)
{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  uint in_EAX;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  int unaff_EBX;
  int unaff_EBP;
  int iVar9;
  int *piVar10;
  uint uStack_28;
  int iStack_24;
  int iStack_1c;
  uint uStack_18;
  
  piVar10 = (int *)(in_EAX + param_2 * 2);
  *piVar10 = (int)(&stack0x00000000 + *piVar10);
  *(char *)(param_2 + 0x24) = *(char *)(param_2 + 0x24) + (char)param_1;
  *(char *)(param_1 + 0x24) = *(char *)(param_1 + 0x24) + (char)param_2;
  *(char *)(unaff_EBP + 0x24) = *(char *)(unaff_EBP + 0x24) + (char)unaff_EBX;
  cVar8 = (char)((uint)param_2 >> 8);
  *(char *)(in_EAX + 0x24) = *(char *)(in_EAX + 0x24) + cVar8;
  *(char *)(in_EAX + 0x8f005024) = *(char *)(in_EAX + 0x8f005024) + (char)param_1;
  uStack_18 = in_EAX & 0xffffff50;
  *(char *)(unaff_EBX + -0x58ffafdc) = *(char *)(unaff_EBX + -0x58ffafdc) + (char)unaff_EBX;
  *(char *)(unaff_EBX + -0x6fffafdc) = *(char *)(unaff_EBX + -0x6fffafdc) + cVar8;
  if (*(int *)(param_1 + 0x47c) != -1) {
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 4);
    iVar7 = iVar3 - *(int *)(param_1 + 0xf98);
    uStack_18 = -(iVar7 >> 0x1f);
    if (*(int *)(param_1 + 0x47c) <= iVar7 / 1000) {
      *(int *)(param_1 + 0xf98) = iVar3;
      iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c);
      if (*(char *)(iVar3 + 0x11d) == -1) {
        iVar9 = 1;
        iVar7 = 0;
        if (1 < *(short *)(iVar3 + 0x3c)) {
          do {
            iVar5 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar9 * 4))
            ;
            if (iVar5 == 1) {
              iVar7 = iVar7 + 1;
            }
            uStack_18 = (uint)*(short *)(iVar3 + 0x3c);
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uStack_18);
        }
        if (iVar7 == 1) {
          uVar1 = *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a);
          uStack_18 = CONCAT31((int3)(uStack_18 >> 8),uVar1);
          *(undefined1 *)(iVar3 + 0x11d) = uVar1;
        }
        else {
          iVar9 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x31f0);
          uStack_18 = iVar9 / iVar7;
          iVar5 = 1;
          iStack_24 = iVar9 % iVar7 + 1;
          if (1 < *(short *)(iVar3 + 0x3c)) {
            do {
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar5 * 4);
              iVar7 = RGE_Player::computerPlayer(pRVar4);
              if ((iVar7 == 1) && (iStack_24 = iStack_24 + -1, iStack_24 == 0)) {
                *(char *)(iVar3 + 0x11d) = (char)pRVar4->id;
              }
              uStack_18 = (uint)*(short *)(iVar3 + 0x3c);
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)uStack_18);
          }
        }
      }
      uStack_18 = CONCAT31((int3)(uStack_18 >> 8),*(char *)(iVar3 + 0x11d));
      if (*(char *)(iVar3 + 0x11d) == *(char *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)) {
        uStack_28 = *(uint *)(param_1 + 0x480);
        piVar10 = (int *)(param_1 + 0xd88);
        uStack_18 = 0;
        do {
          if ((int)uStack_28 < 1) {
            return uStack_28;
          }
          if (((((*piVar10 != 0) ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),0)
                , iVar7 < *(int *)(param_1 + 0x48c))) &&
               ((*piVar10 != 1 ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),1)
                , iVar7 < *(int *)(param_1 + 0x490))))) &&
              (((*piVar10 != 3 ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),3)
                , iVar7 < *(int *)(param_1 + 0x498))) &&
               ((*piVar10 != 2 ||
                (iVar7 = TribeResourceAIModule::resource
                                   ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),2)
                , iVar7 < *(int *)(param_1 + 0x494))))))) &&
             ((piVar10[4] < 0 && (iStack_1c = 1, 1 < *(short *)(iVar3 + 0x3c))))) {
            do {
              if ((int)uStack_28 < 1) break;
              pRVar4 = *(RGE_Player **)(*(int *)(iVar3 + 0x40) + iStack_1c * 4);
              if (((pRVar4->id != *(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)) &&
                  (iVar7 = RGE_Player::computerPlayer(pRVar4), iVar7 != 0)) &&
                 (iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x1c))
                                    (iStack_1c), iVar7 != 0)) {
                iVar7 = pRVar4->_padding_;
                iVar9 = (**(code **)(iVar7 + 0x1c))
                                  ((int)*(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)
                                  );
                if (iVar9 != 0) {
                  uVar2 = *(ushort *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a);
                  if ((((short)uVar2 < pRVar4->id) &&
                      (pRVar4->id != (ushort)*(byte *)(iVar3 + 0x11d))) ||
                     (uVar2 == *(byte *)(iVar3 + 0x11d))) {
                    iVar9 = *piVar10;
                    uVar6 = __ftol();
                    if (0x32 < (int)uVar6) {
                      if ((int)uStack_28 < (int)uVar6) {
                        uVar6 = uStack_28;
                      }
                      uStack_28 = uStack_28 - uVar6;
                      (**(code **)(iVar7 + 0x54))((int)(short)uVar2,1,iVar9,uVar6,0);
                    }
                  }
                }
              }
              iStack_1c = iStack_1c + 1;
            } while (iStack_1c < *(short *)(iVar3 + 0x3c));
          }
          piVar10 = piVar10 + 1;
          uStack_18 = uStack_18 + 1;
        } while ((int)uStack_18 < 4);
      }
    }
  }
  return uStack_18;
}

// --------------------------------------------------

// Function: FUN_00502914
// Address: 00502914
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
void __fastcall FUN_00502914(int param_1)
{
  float *pfVar1;
  int iVar2;
  RGE_Player *pRVar3;
  int *piVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_1c;
  int iStack_18;
  int *piStack_14;
  int iStack_c;
  float fStack_8;
  
  if ((*(int *)(param_1 + 0x47c) != -1) &&
     (pRVar5 = RGE_Object_List::find_by_master_id
                         (*(RGE_Object_List **)(*(int *)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x28)
                          ,0x54,-1.0,-1.0,'\0','\x02',(RGE_Static_Object *)0x0),
     pRVar5 != (RGE_Static_Object *)0x0)) {
    iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 4);
    if (*(int *)(param_1 + 0x47c) <= (iVar2 - *(int *)(param_1 + 0xf9c)) / 1000) {
      *(int *)(param_1 + 0xf9c) = iVar2;
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c);
      if (*(char *)(iVar2 + 0x11d) == -1) {
        iVar7 = 1;
        iVar8 = 0;
        if (1 < *(short *)(iVar2 + 0x3c)) {
          do {
            iVar6 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar7 * 4))
            ;
            if (iVar6 == 1) {
              iVar8 = iVar8 + 1;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(short *)(iVar2 + 0x3c));
        }
        if (iVar8 == 1) {
          *(undefined1 *)(iVar2 + 0x11d) =
               *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a);
        }
        else {
          iVar7 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x3275);
          iVar6 = 1;
          iStack_c = iVar7 % iVar8 + 1;
          if (1 < *(short *)(iVar2 + 0x3c)) {
            do {
              pRVar3 = *(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar6 * 4);
              iVar7 = RGE_Player::computerPlayer(pRVar3);
              if ((iVar7 == 1) && (iStack_c = iStack_c + -1, iStack_c == 0)) {
                *(char *)(iVar2 + 0x11d) = (char)pRVar3->id;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < *(short *)(iVar2 + 0x3c));
          }
        }
      }
      piStack_14 = (int *)(param_1 + 0x48c);
      iStack_18 = 0;
      do {
        iVar7 = TribeResourceAIModule::resource
                          ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),iStack_18);
        if (*piStack_14 < iVar7) {
          iStack_1c = -1;
          fStack_8 = 0.0;
          iStack_c = 1;
          if (1 < *(short *)(iVar2 + 0x3c)) {
            do {
              pRVar3 = *(RGE_Player **)(*(int *)(iVar2 + 0x40) + iStack_c * 4);
              if (((pRVar3->id != *(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)) &&
                  (iVar7 = RGE_Player::computerPlayer(pRVar3), iVar7 != 0)) &&
                 (iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x1c))
                                    (iStack_c), iVar7 != 0)) {
                iVar7 = pRVar3->_padding_;
                iVar8 = (**(code **)(iVar7 + 0x1c))
                                  ((int)*(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)
                                  );
                if (iVar8 != 0) {
                  pfVar1 = pRVar3->attributes + iStack_18;
                  iVar7 = (**(code **)(iVar7 + 0x3c))(iStack_18 + 0xbe);
                  if ((*pfVar1 < (float)iVar7) && ((iStack_1c == -1 || (*pfVar1 < fStack_8)))) {
                    iStack_1c = (int)pRVar3->id;
                    fStack_8 = *pfVar1;
                  }
                }
              }
              iStack_c = iStack_c + 1;
            } while (iStack_c < *(short *)(iVar2 + 0x3c));
          }
          if (iStack_1c != -1) {
            iVar7 = TribeResourceAIModule::resource
                              ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),
                               iStack_18);
            piVar4 = *(int **)(*(int *)(param_1 + 0xf0) + 0x1256c);
            (**(code **)(*piVar4 + 0xf8))
                      (iStack_1c,iStack_18,(float)(iVar7 - *piStack_14),
                       *(undefined4 *)(piVar4[0x14] + 0xb8));
          }
        }
        iStack_18 = iStack_18 + 1;
        piStack_14 = piStack_14 + 1;
      } while (iStack_18 < 4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00502bea
// Address: 00502bea
// XREFS: None
void __fastcall FUN_00502bea(TribeTacticalAIModule *param_1)
{
  int iVar1;
  BuildItem *pBVar2;
  
  iVar1 = TribeTacticalAIModule::inAge(param_1,1);
  if ((((iVar1 == 0) || (param_1->sn[0xb5] != 1)) ||
      (iVar1 = TribeBuildAIModule::readyToResearch(&param_1->md->buildAI,2,1), iVar1 == 0)) ||
     (iVar1 = TribeResourceAIModule::resource(&param_1->md->resourceAI,0), iVar1 < 500)) {
    iVar1 = TribeTacticalAIModule::inAge(param_1,2);
    if (((iVar1 == 0) || (param_1->sn[0xb6] != 1)) ||
       ((iVar1 = TribeBuildAIModule::readyToResearch(&param_1->md->buildAI,3,1), iVar1 == 0 ||
        (iVar1 = TribeResourceAIModule::resource(&param_1->md->resourceAI,0), iVar1 < 800))))
    goto LAB_00502cc3;
    pBVar2 = TribeBuildAIModule::buildItem(&param_1->md->buildAI,0x66,1,4);
  }
  else {
    pBVar2 = TribeBuildAIModule::buildItem(&param_1->md->buildAI,0x65,1,4);
  }
  if (pBVar2 != (BuildItem *)0x0) {
    TribeTacticalAIModule::taskResearch(param_1,pBVar2);
  }
LAB_00502cc3:
  iVar1 = TribeTacticalAIModule::inAge(param_1,3);
  if (((iVar1 != 0) && (param_1->sn[0xb7] == 1)) &&
     ((iVar1 = TribeBuildAIModule::readyToResearch(&param_1->md->buildAI,4,1), iVar1 != 0 &&
      (((iVar1 = TribeResourceAIModule::resource(&param_1->md->resourceAI,0), 899 < iVar1 &&
        (iVar1 = TribeResourceAIModule::resource(&param_1->md->resourceAI,3), 699 < iVar1)) &&
       (pBVar2 = TribeBuildAIModule::buildItem(&param_1->md->buildAI,0x67,1,4),
       pBVar2 != (BuildItem *)0x0)))))) {
    TribeTacticalAIModule::taskResearch(param_1,pBVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00502d4b
// Address: 00502d4b
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
void __thiscall FUN_00502d4b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  ushort uVar1;
  int iVar2;
  RGE_Player *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_4;
  
  if (*(int *)(param_1 + 0x4a4) == 1) {
    iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 4);
    if (*(int *)(param_1 + 0x4a8) <= (iVar2 - *(int *)(param_1 + 4000)) / 1000) {
      *(int *)(param_1 + 4000) = iVar2;
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c);
      if (*(char *)(iVar2 + 0x11d) == -1) {
        iVar6 = 1;
        iVar5 = 0;
        if (1 < *(short *)(iVar2 + 0x3c)) {
          do {
            iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar6 * 4))
            ;
            if (iVar4 == 1) {
              iVar5 = iVar5 + 1;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(short *)(iVar2 + 0x3c));
        }
        if (iVar5 == 1) {
          *(undefined1 *)(iVar2 + 0x11d) =
               *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a);
        }
        else {
          iVar6 = debug_rand(s_C__msdev_work_age1_x1_taitacmd_c,0x32f1);
          iVar4 = 1;
          iStack_4 = iVar6 % iVar5 + 1;
          if (1 < *(short *)(iVar2 + 0x3c)) {
            do {
              pRVar3 = *(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar4 * 4);
              iVar5 = RGE_Player::computerPlayer(pRVar3);
              if ((iVar5 == 1) && (iStack_4 = iStack_4 + -1, iStack_4 == 0)) {
                *(char *)(iVar2 + 0x11d) = (char)pRVar3->id;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < *(short *)(iVar2 + 0x3c));
          }
        }
      }
      iStack_4 = 1;
      if (1 < *(short *)(iVar2 + 0x3c)) {
        do {
          pRVar3 = *(RGE_Player **)(*(int *)(iVar2 + 0x40) + iStack_4 * 4);
          if (((pRVar3->id != *(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a)) &&
              (iVar5 = RGE_Player::computerPlayer(pRVar3), iVar5 != 0)) &&
             (iVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x1c))(iStack_4),
             iVar5 != 0)) {
            iVar5 = pRVar3->_padding_;
            iVar6 = (**(code **)(iVar5 + 0x1c))
                              ((int)*(short *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a));
            if (iVar6 != 0) {
              uVar1 = *(ushort *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x4a);
              if ((((short)uVar1 < pRVar3->id) && (pRVar3->id != (ushort)*(byte *)(iVar2 + 0x11d)))
                 || (uVar1 == *(byte *)(iVar2 + 0x11d))) {
                (**(code **)(iVar5 + 0x54))((int)(short)uVar1,2,param_2,param_3,param_4);
              }
            }
          }
          iStack_4 = iStack_4 + 1;
        } while (iStack_4 < *(short *)(iVar2 + 0x3c));
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00502fe4
// Address: 00502fe4
// XREFS: None
undefined4 __thiscall FUN_00502fe4(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 4)) {
    return *(undefined4 *)(param_1 + 0xd68 + *(int *)(param_1 + 0xd88 + param_2 * 4) * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00503014
// Address: 00503014
// XREFS: None
undefined4 __thiscall FUN_00503014(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 4)) {
    return *(undefined4 *)(param_1 + 0xd68 + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0050303d
// Address: 0050303d
// XREFS: None
undefined4 __thiscall FUN_0050303d(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 4)) {
    return *(undefined4 *)(param_1 + 0xd78 + *(int *)(param_1 + 0xd88 + param_2 * 4) * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00503064
// Address: 00503064
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00503064(int param_1,float param_2,int param_3,int param_4)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  RGE_Static_Object *this;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 *unaff_FS_OFFSET;
  float fVar9;
  int iStack_28;
  int iStack_20;
  ManagedArray<int> MStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560be8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),param_4);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    MStack_1c.value = (int *)0x0;
    MStack_1c.numberValue = 0;
    MStack_1c.desiredNumberValue = 0;
    MStack_1c.maximumSizeValue = 0;
    uStack_4 = 0;
    ManagedArray<int>::resize(&MStack_1c,1);
    iStack_20 = 0;
    MStack_1c.value[MStack_1c.numberValue] = (int)param_2;
    MStack_1c.numberValue = MStack_1c.numberValue + 1;
    if (0 < param_3) {
      do {
        iVar7 = 0;
        param_2 = -1.0;
        iStack_28 = -1;
        iVar2 = -1;
        if (0 < *(int *)(param_1 + 0x9cc)) {
          piVar8 = (int *)(param_1 + 0x51c);
          iVar4 = MStack_1c.numberValue;
          iVar5 = MStack_1c.maximumSizeValue;
          do {
            iVar2 = 0;
            piVar6 = MStack_1c.value;
            if (0 < iVar4) {
              do {
                if (iVar5 <= iVar2) break;
                if (*piVar6 == *piVar8) goto LAB_005031a6;
                iVar2 = iVar2 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar2 < iVar4);
            }
            this = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0xf0),*piVar8);
            iVar4 = MStack_1c.numberValue;
            iVar5 = MStack_1c.maximumSizeValue;
            if ((((this != (RGE_Static_Object *)0x0) &&
                 (pUVar3 = RGE_Static_Object::unitAI(this), iVar4 = MStack_1c.numberValue,
                 iVar5 = MStack_1c.maximumSizeValue, pUVar3 != (UnitAIModule *)0x0)) &&
                (piVar8[1] == 0)) &&
               ((fVar9 = RGE_Static_Object::distance_to_object(this,pRVar1),
                iVar4 = MStack_1c.numberValue, iVar5 = MStack_1c.maximumSizeValue,
                param_2 == _DAT_00575758 || (fVar9 < param_2)))) {
              iStack_28 = *piVar8;
              param_2 = fVar9;
            }
LAB_005031a6:
            iVar7 = iVar7 + 1;
            piVar8 = piVar8 + 6;
            iVar2 = iStack_28;
          } while (iVar7 < *(int *)(param_1 + 0x9cc));
        }
        if (iVar2 == -1) break;
        (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0x1256c) + 0x124))
                  (iVar2,param_4,0,pRVar1->world_x,pRVar1->world_y);
        iVar7 = 0;
        piVar8 = MStack_1c.value;
        if (0 < MStack_1c.numberValue) {
          do {
            if (MStack_1c.maximumSizeValue <= iVar7) break;
            if (*piVar8 == iVar2) goto LAB_00503285;
            iVar7 = iVar7 + 1;
            piVar8 = piVar8 + 1;
          } while (iVar7 < MStack_1c.numberValue);
        }
        if (MStack_1c.maximumSizeValue + -1 < MStack_1c.numberValue) {
          iVar7 = MStack_1c.numberValue + 1;
          piVar8 = (int *)operator_new(iVar7 * 4);
          if (piVar8 != (int *)0x0) {
            iVar4 = 0;
            if (0 < MStack_1c.maximumSizeValue) {
              do {
                if (iVar7 <= iVar4) break;
                iVar5 = iVar4 + 1;
                piVar8[iVar4] = MStack_1c.value[iVar4];
                iVar4 = iVar5;
              } while (iVar5 < MStack_1c.maximumSizeValue);
            }
            operator_delete(MStack_1c.value);
            MStack_1c.value = piVar8;
            MStack_1c.maximumSizeValue = iVar7;
          }
        }
        MStack_1c.value[MStack_1c.numberValue] = iVar2;
        MStack_1c.numberValue = MStack_1c.numberValue + 1;
LAB_00503285:
        iStack_20 = iStack_20 + 1;
      } while (iStack_20 < param_3);
    }
    if (MStack_1c.value != (int *)0x0) {
      uStack_4 = 0xffffffff;
      operator_delete(MStack_1c.value);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005032da
// Address: 005032da
// XREFS: None
void __fastcall FUN_005032da(int param_1)
{
  short sVar1;
  void *pvVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iStack_4;
  
  iStack_4 = 0;
  if (*(int *)(param_1 + 0x168) < 1) {
    return;
  }
LAB_005032fb:
  if (*(int *)(param_1 + 0x170) + -1 < iStack_4) {
    pvVar2 = operator_new(iStack_4 * 4 + 4);
    if (pvVar2 != (void *)0x0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x170)) {
        do {
          if (iStack_4 + 1 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0x164) + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)(param_1 + 0x170));
      }
      operator_delete(*(void **)(param_1 + 0x164));
      *(void **)(param_1 + 0x164) = pvVar2;
      *(int *)(param_1 + 0x170) = iStack_4 + 1;
    }
  }
  pRVar4 = MainDecisionAIModule::object
                     (*(MainDecisionAIModule **)(param_1 + 0xf0),
                      *(int *)(*(int *)(param_1 + 0x164) + iStack_4 * 4));
  if (pRVar4 != (RGE_Static_Object *)0x0) {
    sVar1 = pRVar4->attribute_type_held;
    iVar3 = TribeResourceAIModule::resource
                      ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),(int)sVar1);
    if (iVar3 < *(int *)(param_1 + 0x4f4)) {
      iVar3 = 2;
      do {
        if ((iVar3 != sVar1) &&
           (iVar5 = TribeResourceAIModule::resource
                              ((TribeResourceAIModule *)(*(int *)(param_1 + 0xf0) + 0x10d7c),iVar3),
           *(int *)(param_1 + 0x4f4) <= iVar5)) {
          if (iStack_4 <= *(int *)(param_1 + 0x170) + -1) goto LAB_0050343d;
          pvVar2 = operator_new(iStack_4 * 4 + 4);
          if (pvVar2 == (void *)0x0) goto LAB_0050343d;
          iVar5 = 0;
          if (0 < *(int *)(param_1 + 0x170)) goto LAB_00503401;
          goto LAB_0050341e;
        }
        iVar3 = iVar3 + -1;
      } while (-1 < iVar3);
    }
  }
  goto LAB_0050345d;
  while( true ) {
    iVar5 = iVar5 + 1;
    *(undefined4 *)((int)pvVar2 + iVar5 * 4 + -4) =
         *(undefined4 *)(*(int *)(param_1 + 0x164) + -4 + iVar5 * 4);
    if (*(int *)(param_1 + 0x170) <= iVar5) break;
LAB_00503401:
    if (iStack_4 + 1 <= iVar5) break;
  }
LAB_0050341e:
  operator_delete(*(void **)(param_1 + 0x164));
  *(void **)(param_1 + 0x164) = pvVar2;
  *(int *)(param_1 + 0x170) = iStack_4 + 1;
LAB_0050343d:
  TRIBE_Player::command_trade_attribute
            (*(TRIBE_Player **)(*(int *)(param_1 + 0xf0) + 0x1256c),
             *(int *)(*(int *)(param_1 + 0x164) + iStack_4 * 4),iVar3);
LAB_0050345d:
  iStack_4 = iStack_4 + 1;
  if (*(int *)(param_1 + 0x168) <= iStack_4) {
    return;
  }
  goto LAB_005032fb;
}

// --------------------------------------------------

// Function: FUN_00503476
// Address: 00503476
// XREFS: None
int __thiscall FUN_00503476(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x9cc);
  iVar1 = 0;
  if (0 < iVar3) {
    piVar2 = (int *)(param_1 + 0x52c);
    do {
      if (*piVar2 == param_2) {
        iVar1 = iVar1 + 1;
      }
      piVar2 = piVar2 + 6;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_005034a6
// Address: 005034a6
// XREFS: None
void __fastcall FUN_005034a6(int param_1)
{
  TacticalAIGroup *this;
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xe18) != 0) {
    for (this = *(TacticalAIGroup **)(param_1 + 0x9d8);
        (this != (TacticalAIGroup *)(param_1 + 0x9d4) && (this != (TacticalAIGroup *)0x0));
        this = this->next) {
      iVar1 = TacticalAIGroup::type(this);
      if ((iVar1 == 100) && (iVar1 = TacticalAIGroup::inUse(this), iVar1 != 1)) {
        iVar1 = TacticalAIGroup::numberUnits(this);
        iVar2 = TacticalAIGroup::desiredNumberUnits(this);
        iVar2 = iVar2 - iVar1;
        if (0 < iVar2) {
          if (5 < iVar2) {
            iVar2 = 5;
          }
          if (iVar2 <= (int)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + 0xf0) + 0x3c) + 4
                                     ) - this->lastAddedUnitTimeValue) / 60000) {
            iVar1 = TacticalAIGroup::numberUnits(this);
            TacticalAIGroup::setDesiredNumberUnits(this,iVar1);
          }
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00503572
// Address: 00503572
// XREFS: None
int __fastcall FUN_00503572(int param_1)
{
  TacticalAIGroup *this;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (this = *(TacticalAIGroup **)(param_1 + 0x9d8);
      (this != (TacticalAIGroup *)(param_1 + 0x9d4) && (this != (TacticalAIGroup *)0x0));
      this = this->next) {
    iVar1 = TacticalAIGroup::type(this);
    if ((((iVar1 == 0x67) ||
         (((iVar1 = TacticalAIGroup::type(this), iVar1 == 0x68 ||
           (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x69)) ||
          (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x6a)))) ||
        ((iVar1 = TacticalAIGroup::type(this), iVar1 == 0x6b ||
         (iVar1 = TacticalAIGroup::type(this), iVar1 == 0x6c)))) &&
       (iVar1 = TacticalAIGroup::action(this), iVar1 == 8)) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_005035fb
// Address: 005035fb
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taitacmd_c: "C:\msdev\work\age1_x1\taitacmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005035fb(TribeTacticalAIModule *param_1,int param_2)
{
  ulong uVar1;
  RGE_Static_Object *pRVar2;
  TacticalAIGroup *this;
  int iVar3;
  RGE_Static_Object *pRVar4;
  ulong uVar5;
  int *piVar6;
  int iVar7;
  UnitAIModule *pUVar8;
  RGE_Static_Object *pRVar9;
  float10 fVar10;
  float fVar11;
  int iStack_24;
  int iStack_20;
  XYPoint XStack_14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x3420);
  pRVar2 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_2);
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    XStack_14.x = __ftol();
    XStack_14.y = __ftol();
    this = TribeTacticalAIModule::readyAndIdleGroup(param_1,100,param_1->sn[0x14],&XStack_14);
    if ((this != (TacticalAIGroup *)0x0) ||
       (this = TribeTacticalAIModule::readyAndIdleGroup(param_1,0x67,param_1->sn[0x14],&XStack_14),
       this != (TacticalAIGroup *)0x0)) {
      iVar3 = TacticalAIGroup::commander(this);
      pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),iVar3);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        uStack_c = __ftol();
        uStack_8 = __ftol();
        uStack_4 = __ftol();
        iVar3 = pRVar4->_padding_;
        fVar10 = (float10)(**(code **)(iVar3 + 0x10c))(param_2,0,1,0xffffffff,0xffffffff);
        iVar3 = (**(code **)(iVar3 + 0x198))(uStack_c,uStack_8,uStack_4,(float)fVar10);
        if (iVar3 == 1) {
          TacticalAIGroup::setTarget(this,param_2);
          TacticalAIGroup::setTargetType(this,(int)pRVar2->master_obj->id);
          TacticalAIGroup::setTargetLocation(this,pRVar2->world_x,pRVar2->world_y,pRVar2->world_z);
          TacticalAIGroup::setAction(this,2);
          TacticalAIGroup::task(this,param_1,param_1->md,2,1,0);
          return;
        }
      }
    }
    iStack_20 = 0;
    iStack_24 = 0;
    if (0 < (param_1->soldiers).numberValue) {
      do {
        if (5 < iStack_20) break;
        if ((1 < iStack_24) &&
           (uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_taitacmd_c,0x3447), 10 < uVar5 - uVar1
           )) {
          return;
        }
        if ((param_1->soldiers).maximumSizeValue + -1 < iStack_24) {
          piVar6 = (int *)operator_new(iStack_24 * 4 + 4);
          if (piVar6 != (int *)0x0) {
            iVar3 = 0;
            if (0 < (param_1->soldiers).maximumSizeValue) {
              do {
                if (iStack_24 + 1 <= iVar3) break;
                iVar7 = iVar3 + 1;
                piVar6[iVar3] = (param_1->soldiers).value[iVar3];
                iVar3 = iVar7;
              } while (iVar7 < (param_1->soldiers).maximumSizeValue);
            }
            operator_delete((param_1->soldiers).value);
            (param_1->soldiers).value = piVar6;
            (param_1->soldiers).maximumSizeValue = iStack_24 + 1;
          }
        }
        pRVar4 = RGE_Game_World::object
                           ((RGE_Game_World *)param_1->md->aiPlayer->_padding_,
                            (param_1->soldiers).value[iStack_24]);
        if ((pRVar4 != (RGE_Static_Object *)0x0) &&
           (pUVar8 = RGE_Static_Object::unitAI(pRVar4), pUVar8 != (UnitAIModule *)0x0)) {
          pUVar8 = RGE_Static_Object::unitAI(pRVar4);
          iVar3 = UnitAIModule::currentAction(pUVar8);
          if (iVar3 == 600) {
            pUVar8 = RGE_Static_Object::unitAI(pRVar4);
            iVar3 = UnitAIModule::currentTarget(pUVar8);
            if (iVar3 == -1) goto LAB_00503954;
            pUVar8 = RGE_Static_Object::unitAI(pRVar4);
            iVar3 = UnitAIModule::currentTarget(pUVar8);
            if (iVar3 != pRVar2->id) {
              pUVar8 = RGE_Static_Object::unitAI(pRVar4);
              iVar3 = UnitAIModule::currentTarget(pUVar8);
              pRVar9 = RGE_Game_World::object
                                 (*(RGE_Game_World **)(param_1->md->_padding_ + 0x3c),iVar3);
              if (pRVar9 != (RGE_Static_Object *)0x0) {
                if (((param_1->playersToAttack).maximumSizeValue + -1 < 0) &&
                   (piVar6 = (int *)operator_new(4), piVar6 != (int *)0x0)) {
                  iVar3 = 0;
                  if (0 < (param_1->playersToAttack).maximumSizeValue) {
                    do {
                      if (0 < iVar3) break;
                      iVar7 = iVar3 + 1;
                      piVar6[iVar3] = (param_1->playersToAttack).value[iVar3];
                      iVar3 = iVar7;
                    } while (iVar7 < (param_1->playersToAttack).maximumSizeValue);
                  }
                  operator_delete((param_1->playersToAttack).value);
                  (param_1->playersToAttack).value = piVar6;
                  (param_1->playersToAttack).maximumSizeValue = 1;
                }
                if ((int)pRVar9->owner->id == *(param_1->playersToAttack).value) goto LAB_00503a7a;
              }
              goto LAB_00503954;
            }
LAB_00503a76:
            iStack_20 = iStack_20 + 1;
          }
          else {
LAB_00503954:
            fVar11 = RGE_Static_Object::distance_to_object(pRVar4,pRVar2);
            if (fVar11 < _DAT_00575784) {
              uStack_c = __ftol();
              uStack_8 = __ftol();
              uStack_4 = __ftol();
              iVar3 = pRVar4->_padding_;
              fVar10 = (float10)(**(code **)(iVar3 + 0x10c))(pRVar2->id,0,1,0xffffffff,0xffffffff);
              iVar3 = (**(code **)(iVar3 + 0x198))(uStack_c,uStack_8,uStack_4,(float)fVar10);
              if (iVar3 != 0) {
                if ((param_1->soldiers).maximumSizeValue + -1 < iStack_24) {
                  piVar6 = (int *)operator_new(iStack_24 * 4 + 4);
                  if (piVar6 != (int *)0x0) {
                    iVar3 = 0;
                    if (0 < (param_1->soldiers).maximumSizeValue) {
                      do {
                        if (iStack_24 + 1 <= iVar3) break;
                        iVar7 = iVar3 + 1;
                        piVar6[iVar3] = (param_1->soldiers).value[iVar3];
                        iVar3 = iVar7;
                      } while (iVar7 < (param_1->soldiers).maximumSizeValue);
                    }
                    operator_delete((param_1->soldiers).value);
                    (param_1->soldiers).value = piVar6;
                    (param_1->soldiers).maximumSizeValue = iStack_24 + 1;
                  }
                }
                iVar3 = TribeTacticalAIModule::taskAttacker
                                  (param_1,(param_1->soldiers).value[iStack_24],pRVar2->world_x,
                                   pRVar2->world_y,pRVar2->id,(int)pRVar2->owner->id,(Waypoint *)0x0
                                   ,0,-1,0);
                if (iVar3 == 1) goto LAB_00503a76;
              }
            }
          }
        }
LAB_00503a7a:
        iStack_24 = iStack_24 + 1;
      } while (iStack_24 < (param_1->soldiers).numberValue);
    }
    iVar3 = TribeTacticalAIModule::civilian(param_1,&XStack_14,1,700,-1000,-1000,1);
    while (((iVar3 != -1 && (iStack_20 < 6)) &&
           (pRVar4 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar3),
           pRVar4 != (RGE_Static_Object *)0x0))) {
      uStack_c = __ftol();
      uStack_8 = __ftol();
      uStack_4 = __ftol();
      iVar7 = pRVar4->_padding_;
      fVar10 = (float10)(**(code **)(iVar7 + 0x10c))(param_2,0,1,0xffffffff,0xffffffff);
      iVar7 = (**(code **)(iVar7 + 0x198))(uStack_c,uStack_8,uStack_4,(float)fVar10);
      if (iVar7 == 0) {
        return;
      }
      TribeTacticalAIModule::taskAttacker
                (param_1,iVar3,pRVar2->world_x,pRVar2->world_y,param_2,(int)pRVar2->owner->id,
                 (Waypoint *)0x0,0,-1,0);
      iStack_20 = iStack_20 + 1;
      iVar3 = TribeTacticalAIModule::civilian(param_1,&XStack_14,1,700,0x2c9,0x2c9,1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00503baa
// Address: 00503baa
// XREFS: None
UnitAIModule * __thiscall FUN_00503baa(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560c08;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeHuntedAnimalUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x10;
  piVar1 = (int *)operator_new(0x40);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    param_1->importantObjects[1] = 4;
    param_1->importantObjects[2] = 0x1a;
    param_1->importantObjects[3] = 0x18;
    param_1->importantObjects[4] = 6;
    param_1->importantObjects[5] = 0x19;
    param_1->importantObjects[6] = 0x11;
    param_1->importantObjects[7] = 10;
    param_1->importantObjects[8] = 0xc;
    param_1->importantObjects[9] = 0x23;
    param_1->importantObjects[10] = 0x17;
    param_1->importantObjects[0xb] = 0x24;
    param_1->importantObjects[0xc] = 0x1c;
    param_1->importantObjects[0xd] = 0x12;
    param_1->importantObjects[0xe] = 0xd;
    param_1->importantObjects[0xf] = 0x27;
  }
  param_1->idleTimeoutValue = 4000;
  UnitAIModule::setAdjustedIdleTimeout(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00503cfc
// Address: 00503cfc
// XREFS: None
TribeHuntedAnimalUnitAIModule * __thiscall
FUN_00503cfc(TribeHuntedAnimalUnitAIModule *param_1,byte param_2)
{
  TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00503d25
// Address: 00503d25
// XREFS: None
int __thiscall FUN_00503d25(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_2->mType != 500) {
    if (param_2->mType != 0x20f) {
      iVar2 = UnitAIModule::processNotify(param_1,param_2,param_3);
      return iVar2;
    }
    return 2;
  }
  if (param_2->p2 < 1) {
    UnitAIModule::purgeNotifyQueue(param_1,param_3);
    return 4;
  }
  iVar1 = param_2->caller;
  iVar2 = (param_1->attackingUnitsValue).numberValue;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar3) break;
      if ((param_1->attackingUnitsValue).value[iVar3] == iVar1) goto LAB_00503e0b;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar2) {
    iVar2 = iVar2 + 1;
    piVar4 = (int *)operator_new(iVar2 * 4);
    if (piVar4 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
        do {
          if (iVar2 <= iVar3) break;
          iVar5 = iVar3 + 1;
          piVar4[iVar3] = (param_1->attackingUnitsValue).value[iVar3];
          iVar3 = iVar5;
        } while (iVar5 < (param_1->attackingUnitsValue).maximumSizeValue);
      }
      operator_delete((param_1->attackingUnitsValue).value);
      (param_1->attackingUnitsValue).value = piVar4;
      (param_1->attackingUnitsValue).maximumSizeValue = iVar2;
    }
  }
  (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar1;
  (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_00503e0b:
  (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
  (**(code **)(param_1->_padding_ + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: FUN_00503f15
// Address: 00503f15
// XREFS: None
UnitAIModule * __thiscall FUN_00503f15(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560c28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribePreditorUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x11;
  piVar1 = (int *)operator_new(0x44);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0x1d;
    param_1->importantObjects[1] = 9;
    param_1->importantObjects[2] = 0;
    param_1->importantObjects[3] = 4;
    param_1->importantObjects[4] = 0x1a;
    param_1->importantObjects[5] = 0x18;
    param_1->importantObjects[6] = 6;
    param_1->importantObjects[7] = 0x19;
    param_1->importantObjects[8] = 0x11;
    param_1->importantObjects[9] = 0xd;
    param_1->importantObjects[10] = 0xc;
    param_1->importantObjects[0xb] = 0x23;
    param_1->importantObjects[0xc] = 0x17;
    param_1->importantObjects[0xd] = 0x24;
    param_1->importantObjects[0xe] = 0x1c;
    param_1->importantObjects[0xf] = 0x12;
    param_1->importantObjects[0x10] = 0x27;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00504068
// Address: 00504068
// XREFS: None
TribePreditorUnitAIModule * __thiscall FUN_00504068(TribePreditorUnitAIModule *param_1,byte param_2)
{
  TribePreditorUnitAIModule::~TribePreditorUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00504095
// Address: 00504095
// XREFS: None
undefined4 FUN_00504095(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_005040a8
// Address: 005040a8
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
int __thiscall FUN_005040a8(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  RGE_Static_Object *pRVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  
  if (param_2->mType == 0x1fc) {
    pRVar1 = RGE_Game_World::object(param_1->objectValue->owner->world,param_1->currentTargetValue);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      fVar4 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar1);
      if (fVar4 <= param_1->objectValue->master_obj->los) {
        (**(code **)(param_1->_padding_ + 0x5c))(param_1->currentTargetValue,1);
        return 3;
      }
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar2 = -1;
      }
      else {
        lVar2 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0xfa)
      ;
    }
    iVar3 = param_1->_padding_;
    (**(code **)(iVar3 + 0x58))(1);
    (**(code **)(iVar3 + 0x1c))(param_2);
  }
  iVar3 = UnitAIModule::processNotify(param_1,param_2,param_3);
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00504169
// Address: 00504169
// XREFS: None
UnitAIModule * __thiscall FUN_00504169(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  param_1->_padding_ = (int)&TribeElephantUnitAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005041b5
// Address: 005041b5
// XREFS: None
int __thiscall FUN_005041b5(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (param_2->mType != 500) {
    if (param_2->mType != 0x20f) {
      iVar2 = UnitAIModule::processNotify(param_1,param_2,param_3);
      return iVar2;
    }
    return 2;
  }
  if (param_2->p2 < 1) {
    UnitAIModule::purgeNotifyQueue(param_1,param_3);
    return 4;
  }
  iVar1 = param_2->caller;
  iVar2 = (param_1->attackingUnitsValue).numberValue;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar3) break;
      if ((param_1->attackingUnitsValue).value[iVar3] == iVar1) goto LAB_0050429b;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar2) {
    iVar2 = iVar2 + 1;
    piVar4 = (int *)operator_new(iVar2 * 4);
    if (piVar4 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
        do {
          if (iVar2 <= iVar3) break;
          iVar5 = iVar3 + 1;
          piVar4[iVar3] = (param_1->attackingUnitsValue).value[iVar3];
          iVar3 = iVar5;
        } while (iVar5 < (param_1->attackingUnitsValue).maximumSizeValue);
      }
      operator_delete((param_1->attackingUnitsValue).value);
      (param_1->attackingUnitsValue).value = piVar4;
      (param_1->attackingUnitsValue).maximumSizeValue = iVar2;
    }
  }
  (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar1;
  (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_0050429b:
  (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
  iVar2 = param_1->_padding_;
  uVar6 = (**(code **)(iVar2 + 0x3c))(0);
  (**(code **)(iVar2 + 0x5c))(uVar6,0);
  return 3;
}

// --------------------------------------------------

// Function: FUN_005042c5
// Address: 005042c5
// XREFS: None
undefined4 FUN_005042c5(void)
{
  return 5;
}

// --------------------------------------------------

// Function: FUN_005042d8
// Address: 005042d8
// XREFS: None
UnitAIModule * __thiscall FUN_005042d8(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560c48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeLionUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x11;
  piVar1 = (int *)operator_new(0x44);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0x1d;
    param_1->importantObjects[1] = 9;
    param_1->importantObjects[2] = 0;
    param_1->importantObjects[3] = 4;
    param_1->importantObjects[4] = 0x1a;
    param_1->importantObjects[5] = 0x18;
    param_1->importantObjects[6] = 6;
    param_1->importantObjects[7] = 0x19;
    param_1->importantObjects[8] = 0x11;
    param_1->importantObjects[9] = 0xd;
    param_1->importantObjects[10] = 0xc;
    param_1->importantObjects[0xb] = 0x23;
    param_1->importantObjects[0xc] = 0x17;
    param_1->importantObjects[0xd] = 0x24;
    param_1->importantObjects[0xe] = 0x1c;
    param_1->importantObjects[0xf] = 0x12;
    param_1->importantObjects[0x10] = 0x27;
  }
  param_1->idleTimeoutValue = 6000;
  UnitAIModule::setAdjustedIdleTimeout(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00504439
// Address: 00504439
// XREFS: None
TribeLionUnitAIModule * __thiscall FUN_00504439(TribeLionUnitAIModule *param_1,byte param_2)
{
  TribeLionUnitAIModule::~TribeLionUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00504465
// Address: 00504465
// XREFS: None
undefined4 FUN_00504465(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_00504478
// Address: 00504478
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
int __thiscall FUN_00504478(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  RGE_Static_Object *pRVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  ulong unaff_retaddr;
  
  if (param_2->mType != 0x1fa) {
    if (param_2->mType == 0x1fc) {
      pRVar1 = RGE_Game_World::object
                         (param_1->objectValue->owner->world,param_1->currentTargetValue);
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        fVar4 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar1);
        if (fVar4 <= param_1->objectValue->master_obj->los) {
          (**(code **)(param_1->_padding_ + 0x5c))(param_1->currentTargetValue,1);
          return 3;
        }
      }
      UnitAIModule::removeCurrentTarget(param_1);
      if (actionFile != (_iobuf *)0x0) {
        if (param_1->objectValue == (RGE_Static_Object *)0x0) {
          lVar2 = -1;
        }
        else {
          lVar2 = param_1->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,
                0x1ac);
      }
      iVar3 = param_1->_padding_;
      (**(code **)(iVar3 + 0x58))(1);
      (**(code **)(iVar3 + 0x1c))(param_2);
      iVar3 = UnitAIModule::processNotify(param_1,param_2,unaff_retaddr);
      return iVar3;
    }
    goto LAB_005045ea;
  }
  if (param_2->p1 != 600) goto LAB_005045ea;
  iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar3 == 1) {
    iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if (iVar3 != 1) goto LAB_00504597;
    iVar3 = RGE_Game_World::difficultyLevel(param_1->objectValue->owner->world);
    param_1->idleTimeoutValue = (iVar3 + 3) * 5000;
  }
  else {
LAB_00504597:
    param_1->idleTimeoutValue = 25000;
  }
  UnitAIModule::setAdjustedIdleTimeout(param_1);
  UnitAIModule::removeCurrentTarget(param_1);
  if (actionFile != (_iobuf *)0x0) {
    if (param_1->objectValue == (RGE_Static_Object *)0x0) {
      lVar2 = -1;
    }
    else {
      lVar2 = param_1->objectValue->id;
    }
    fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x191);
  }
  (**(code **)(param_1->_padding_ + 0x58))(1);
LAB_005045ea:
  iVar3 = UnitAIModule::processNotify(param_1,param_2,param_3);
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_005045fd
// Address: 005045fd
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005045fd(UnitAIModule *param_1)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object *this;
  float fVar6;
  float fVar7;
  
  param_1->idleTimeoutValue = 6000;
  UnitAIModule::setAdjustedIdleTimeout(param_1);
  iVar1 = param_1->_padding_;
  iVar2 = (**(code **)(iVar1 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
  pRVar3 = UnitAIModule::lookupObject(param_1,iVar2);
  if ((iVar2 != -1) && (pRVar3 != (RGE_Static_Object *)0x0)) {
    iVar4 = RGE_Game_World::difficultyLevel(param_1->objectValue->owner->world);
    iVar5 = RGE_Base_Game::scenarioGame(rge_base_game);
    if ((iVar5 == 1) &&
       ((iVar5 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar5 == 1 && (2 < iVar4)))) {
      fVar7 = _DAT_005758b8;
      if (iVar4 == 3) {
        fVar7 = _DAT_005758b4;
      }
      this = param_1->objectValue;
      fVar7 = fVar7 * this->master_obj->los;
      if (fVar7 < _DAT_005758bc) {
        fVar7 = 1.0;
      }
    }
    else {
      this = param_1->objectValue;
      fVar7 = this->master_obj->los;
      fVar7 = fVar7 + fVar7;
    }
    fVar6 = RGE_Static_Object::distance_to_object(this,pRVar3);
    if (fVar6 <= fVar7) {
      (**(code **)(iVar1 + 0x5c))(iVar2,0);
      return 6;
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_005046fb
// Address: 005046fb
// XREFS: None
UnitAIModule * __thiscall FUN_005046fb(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  param_1->_padding_ = (int)&TribeRangedUnitAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00504745
// Address: 00504745
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00504745(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float fVar7;
  
  if (param_2->mType != 0x200) {
    iVar2 = UnitAIModule::processNotify(param_1,param_2,param_3);
    return iVar2;
  }
  if (param_1->currentActionValue == 600) {
    pRVar3 = RGE_Game_World::object(param_1->objectValue->owner->world,param_1->currentTargetValue);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      fVar4 = (float10)(**(code **)(pRVar3->_padding_ + 0xf4))();
      if (fVar4 != (float10)_DAT_005758c4) {
        iVar2 = param_1->_padding_;
        (**(code **)(iVar2 + 0x10))
                  (param_1->objectValue->id,700,param_1->currentTargetValue,0xffffffff,
                   param_1->currentTargetXValue,param_1->currentTargetYValue,
                   param_1->currentTargetZValue,param_1->desiredTargetDistanceValue,0,1,
                   param_1->currentOrderPriorityValue);
        pRVar1 = param_1->objectValue;
        fVar4 = (float10)(**(code **)(pRVar1->_padding_ + 0x100))();
        fVar7 = (float)fVar4;
        fVar4 = (float10)(**(code **)(pRVar1->_padding_ + 0xfc))();
        pRVar1 = param_1->objectValue;
        fVar4 = fVar4 * (float10)fVar7 * (float10)_DAT_005758b0;
        fVar5 = (float10)pRVar3->world_x - (float10)pRVar1->world_x;
        fVar6 = (float10)pRVar3->world_y - (float10)pRVar1->world_y;
        fVar7 = (float)SQRT(fVar6 * fVar6 + fVar5 * fVar5);
        (**(code **)(iVar2 + 0x9c))
                  ((float)(-((fVar5 / (float10)fVar7) * fVar4) + (float10)pRVar1->world_x),
                   (float)(-((fVar6 / (float10)fVar7) * fVar4) + (float10)pRVar1->world_y),
                   pRVar1->world_z,1);
        return 3;
      }
    }
  }
  return 2;
}

// --------------------------------------------------

// Function: FUN_00504876
// Address: 00504876
// XREFS: None
UnitAIModule * __thiscall FUN_00504876(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  param_1->_padding_ = (int)&TribeRangedUnitAIModule2::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005048c5
// Address: 005048c5
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_005048c5(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float10 fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  if (param_2->mType != 0x200) {
    iVar2 = UnitAIModule::processNotify(param_1,param_2,param_3);
    return iVar2;
  }
  if (((param_1->currentActionValue != 600) ||
      (pRVar3 = RGE_Game_World::object
                          (param_1->objectValue->owner->world,param_1->currentTargetValue),
      pRVar3 == (RGE_Static_Object *)0x0)) ||
     (fVar8 = (float10)(**(code **)(pRVar3->_padding_ + 0xf4))(), fVar8 == (float10)_DAT_005758c4))
{
    return 2;
  }
  fVar10 = param_1->currentTargetYValue;
  fVar7 = (float)param_1->_padding_;
  (**(code **)((int)fVar7 + 0x10))
            (param_1->objectValue->id,700,param_1->currentTargetValue,0xffffffff,
             param_1->currentTargetXValue,fVar10,param_1->currentTargetZValue,
             param_1->desiredTargetDistanceValue,0,1,param_1->currentOrderPriorityValue);
  pRVar1 = param_1->objectValue;
  fVar8 = (float10)(**(code **)(pRVar1->_padding_ + 0x100))();
  fVar9 = (float)fVar8;
  fVar8 = (float10)(**(code **)(pRVar1->_padding_ + 0xfc))();
  fVar9 = (float)(fVar8 * (float10)fVar9 * (float10)_DAT_005758b0);
  fVar12 = pRVar3->world_x - param_1->objectValue->world_x;
  fVar11 = pRVar3->world_y - param_1->objectValue->world_y;
  iVar2 = (param_1->attackingUnitsValue).numberValue;
  if ((0 < iVar2) && (iVar6 = 0, fVar7 = fVar10, 0 < iVar2)) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar6) {
        piVar4 = (int *)operator_new(iVar6 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
            do {
              if (iVar6 + 1 <= iVar2) break;
              iVar5 = iVar2 + 1;
              piVar4[iVar2] = (param_1->attackingUnitsValue).value[iVar2];
              iVar2 = iVar5;
            } while (iVar5 < (param_1->attackingUnitsValue).maximumSizeValue);
          }
          operator_delete((param_1->attackingUnitsValue).value);
          (param_1->attackingUnitsValue).value = piVar4;
          (param_1->attackingUnitsValue).maximumSizeValue = iVar6 + 1;
        }
      }
      if ((param_1->attackingUnitsValue).value[iVar6] != param_1->currentTargetValue) {
        if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar6) {
          piVar4 = (int *)operator_new(iVar6 * 4 + 4);
          if (piVar4 != (int *)0x0) {
            iVar2 = 0;
            if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
              do {
                if (iVar6 + 1 <= iVar2) break;
                iVar5 = iVar2 + 1;
                piVar4[iVar2] = (param_1->attackingUnitsValue).value[iVar2];
                iVar2 = iVar5;
              } while (iVar5 < (param_1->attackingUnitsValue).maximumSizeValue);
            }
            operator_delete((param_1->attackingUnitsValue).value);
            (param_1->attackingUnitsValue).value = piVar4;
            (param_1->attackingUnitsValue).maximumSizeValue = iVar6 + 1;
          }
        }
        pRVar3 = RGE_Game_World::object
                           (param_1->objectValue->owner->world,
                            (param_1->attackingUnitsValue).value[iVar6]);
        if (pRVar3 != (RGE_Static_Object *)0x0) {
          fVar12 = (pRVar3->world_x - param_1->objectValue->world_x) + fVar12;
          fVar11 = (pRVar3->world_y - param_1->objectValue->world_y) + fVar11;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (param_1->attackingUnitsValue).numberValue);
  }
  pRVar3 = param_1->objectValue;
  fVar10 = SQRT(fVar11 * fVar11 + fVar12 * fVar12);
  (**(code **)((int)fVar7 + 0x9c))
            (-((fVar12 / fVar10) * fVar9) + pRVar3->world_x,
             -((fVar11 / fVar10) * fVar9) + pRVar3->world_y,pRVar3->world_z,1);
  return 3;
}

// --------------------------------------------------

// Function: FUN_00504b53
// Address: 00504b53
// XREFS: None
UnitAIModule * __thiscall FUN_00504b53(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560c68;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeCivilianUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0xb;
  piVar1 = (int *)operator_new(0x2c);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 3;
    param_1->importantObjects[1] = 7;
    param_1->importantObjects[2] = 8;
    param_1->importantObjects[3] = 9;
    param_1->importantObjects[4] = 10;
    param_1->importantObjects[5] = 0xf;
    param_1->importantObjects[6] = 0x11;
    param_1->importantObjects[7] = 0x12;
    param_1->importantObjects[8] = 0x20;
    param_1->importantObjects[9] = 0x21;
    param_1->importantObjects[10] = 0x1b;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00504c5a
// Address: 00504c5a
// XREFS: None
TribeCivilianUnitAIModule * __thiscall FUN_00504c5a(TribeCivilianUnitAIModule *param_1,byte param_2)
{
  TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00504c85
// Address: 00504c85
// XREFS: None
undefined4 FUN_00504c85(int param_1)
{
  if ((((param_1 != 7) && (param_1 != 9)) && (param_1 != 10)) &&
     (((param_1 != 0xf && (param_1 != 8)) && (param_1 != 0x20)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00504cbf
// Address: 00504cbf
// XREFS: None
void __thiscall FUN_00504cbf(UnitAIModule *param_1,int param_2,int param_3)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return;
  }
  sVar1 = pRVar2->master_obj->object_group;
  if (((sVar1 != 9) && (sVar1 != 10)) && (sVar1 != 0xf)) {
    UnitAIModule::attackObject(param_1,param_2,param_3);
    return;
  }
  (**(code **)(param_1->_padding_ + 100))(param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_00504d1a
// Address: 00504d1a
// XREFS: None
uint FUN_00504d1a(uint param_1)
{
  if (param_1 == 0) {
    return param_1;
  }
  return (uint)(*(short *)(*(int *)(param_1 + 8) + 0x14) != 1);
}

// --------------------------------------------------

// Function: FUN_00504d3d
// Address: 00504d3d
// XREFS: None
undefined4 FUN_00504d3d(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00504d45
// Address: 00504d45
// XREFS: None
undefined4 FUN_00504d45(int param_1)
{
  if (((param_1 != 0x2c1) && (param_1 != 0x2c5)) && (param_1 != 0x2c9)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00504d76
// Address: 00504d76
// XREFS: None
undefined4 FUN_00504d76(undefined4 param_1)
{
  switch(param_1) {
  case 5:
  case 0x1f:
  case 0x21:
    return 2;
  default:
    return 0xffffffff;
  case 7:
    return 1;
  case 8:
    return 3;
  case 0xf:
    return 0;
  case 0x20:
    return 4;
  }
}

// --------------------------------------------------

// Function: FUN_00504dc6
// Address: 00504dc6
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Removing unreachable block (ram,0x00504ef5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_00504dc6(UnitAIModule *param_1,int *param_2)
{
  code *pcVar1;
  char cVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  int unaff_EBX;
  int unaff_EBP;
  ulong unaff_ESI;
  float10 fVar10;
  float fVar11;
  int iStack00000034;
  UnitAIModule *pUStack0000003c;
  NotifyEvent *in_stack_00000044;
  ulong in_stack_00000048;
  
  *(char *)(unaff_EBX + -0x4cffafb3) =
       *(char *)(unaff_EBX + -0x4cffafb3) + (char)((uint)param_1 >> 8);
  cVar2 = (char)((uint)unaff_EBX >> 8);
  cRam3e00a09a = cRam3e00a09a + cVar2;
  cRam5b00a09a = cRam5b00a09a + cVar2;
  iStack00000034 = unaff_EBP + -4;
  cRam9b00504d = cRam9b00504d + 'M';
  *param_2 = *param_2 + -0x64ffafb3;
  pUStack0000003c = param_1;
  switch(in_stack_00000044->mType) {
  case 500:
    goto switchD_00504e34_caseD_1f4;
  default:
    iVar9 = UnitAIModule::processNotify(param_1,in_stack_00000044,in_stack_00000048);
    return iVar9;
  case 0x1f9:
    if (param_1->currentActionValue != in_stack_00000044->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      fprintf();
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x58))();
      (**(code **)(iVar9 + 0x1c))();
      return 2;
    }
    break;
  case 0x1fa:
    if (param_1->currentActionValue != in_stack_00000044->p1) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      fprintf();
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x58))();
      (**(code **)(iVar9 + 0x1c))();
      return 2;
    }
    break;
  case 0x1fb:
  case 0x202:
    iVar9 = param_1->currentActionValue;
    if (iVar9 == 0x265) {
      if ((param_1->currentTargetTypeValue == -1) && (param_1->lastTargetTypeValue == -1)) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        iVar9 = param_1->_padding_;
        (**(code **)(iVar9 + 0x58))();
        (**(code **)(iVar9 + 0x1c))();
        return 2;
      }
      iVar9 = param_1->_padding_;
      iVar4 = (**(code **)(iVar9 + 0xc0))();
      if (iVar4 == -1) {
        iVar4 = (**(code **)(iVar9 + 0x40))();
      }
      else {
        iVar4 = (**(code **)(iVar9 + 0x44))();
      }
      if (iVar4 == -1) {
        iVar4 = RGE_Player::computerPlayer(param_1->objectValue->owner);
        if (iVar4 == 1) {
          UnitAIModule::removeCurrentTarget(param_1);
          goto joined_r0x0050570c;
        }
      }
      else {
        iVar4 = (**(code **)(iVar9 + 100))();
        if (iVar4 == 1) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        (**(code **)(iVar9 + 0x58))();
LAB_00505742:
        (**(code **)(iVar9 + 0x1c))();
      }
    }
    else if (iVar9 == 0x261) {
      if ((param_1->currentTargetTypeValue == -1) && (param_1->lastTargetTypeValue == -1)) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        iVar9 = param_1->_padding_;
        (**(code **)(iVar9 + 0x58))();
        (**(code **)(iVar9 + 0x1c))();
        return 2;
      }
      iVar9 = param_1->_padding_;
      iVar4 = (**(code **)(iVar9 + 0xc0))();
      if (iVar4 == -1) {
        iVar4 = (**(code **)(iVar9 + 0x40))();
      }
      else {
        iVar4 = (**(code **)(iVar9 + 0x44))();
      }
      if (iVar4 != -1) {
        iVar4 = (**(code **)(iVar9 + 0x68))();
        if (iVar4 == 1) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget(param_1);
joined_r0x0050570c:
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        (**(code **)(iVar9 + 0x58))();
        goto LAB_00505742;
      }
      iVar4 = RGE_Player::computerPlayer(param_1->objectValue->owner);
      if (iVar4 == 1) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile == (_iobuf *)0x0) {
LAB_005056e2:
          (**(code **)(iVar9 + 0x58))();
        }
        else {
          fprintf();
          (**(code **)(iVar9 + 0x58))();
        }
        goto LAB_00505742;
      }
      if (in_stack_00000044->p2 == 0x32) {
        fVar11 = _DAT_005758d0;
        if (_DAT_005758c8 < param_1->objectValue->world_x) {
          fVar11 = _DAT_005758cc;
        }
        pUStack0000003c = (UnitAIModule *)(param_1->objectValue->world_x - fVar11);
        (**(code **)(iVar9 + 0x9c))();
      }
    }
    else if (iVar9 == 0x25a) {
      iVar9 = param_1->_padding_;
      pcVar1 = *(code **)(iVar9 + 0x40);
      iVar4 = (*pcVar1)();
      if (((iVar4 == -1) && (iVar4 = (*pcVar1)(), iVar4 == -1)) ||
         (iVar4 = (**(code **)(param_1->objectValue->_padding_ + 0x194))(), iVar4 != 1)) {
        pRVar3 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue);
        if ((pRVar3 == (RGE_Static_Object *)0x0) ||
           (fVar11 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar3),
           _DAT_005758bc < fVar11)) {
          (**(code **)(iVar9 + 0x90))();
        }
      }
      else {
        iVar9 = (**(code **)(iVar9 + 0x78))();
        if (iVar9 == 1) {
          return 3;
        }
      }
    }
    else if (iVar9 == 0x25d) {
      iVar9 = param_1->_padding_;
      iVar4 = (**(code **)(iVar9 + 0x48))();
      if (iVar4 == 1) {
        UnitAIModule::addToWaypointQueue(param_1,(int)pUStack0000003c,in_stack_00000048);
        iVar4 = (**(code **)(iVar9 + 0x80))();
        if (iVar4 != 0) {
          return 3;
        }
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          fprintf();
        }
        goto LAB_005056e2;
      }
      UnitAIModule::removeCurrentTarget(param_1);
      goto joined_r0x0050570c;
    }
    if (in_stack_00000044->mType == 0x202) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      fprintf();
    }
    break;
  case 0x20f:
    iVar9 = RGE_Game_World::difficultyLevel(param_1->objectValue->owner->world);
    if (2 < iVar9) {
      return 2;
    }
switchD_00504e34_caseD_1f4:
    if (in_stack_00000044->p2 < 1) {
      (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))();
      UnitAIModule::purgeNotifyQueue(param_1,unaff_ESI);
      return 4;
    }
    pRVar3 = UnitAIModule::lookupObject(param_1,in_stack_00000044->caller);
    pUStack0000003c =
         (UnitAIModule *)UnitAIModule::lookupObject(param_1,param_1->currentTargetValue);
    if (pRVar3 == (RGE_Static_Object *)0x0) {
      return 2;
    }
    iVar9 = RGE_Player::computerPlayer(param_1->objectValue->owner);
    if (iVar9 == 1) {
      if ((pRVar3->owner->id == 0) && (pRVar3->id == param_1->currentTargetValue))
      goto LAB_00504f1d;
    }
    else if ((param_1->attackingUnitsValue).numberValue != 0) goto LAB_00504f1d;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))();
LAB_00504f1d:
    iVar9 = (param_1->attackingUnitsValue).numberValue;
    iVar4 = 0;
    if (0 < iVar9) {
      do {
        if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar4) break;
        if ((param_1->attackingUnitsValue).value[iVar4] == in_stack_00000044->caller)
        goto LAB_00504f5e;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar9);
    }
    iVar9 = RGE_Player::computerPlayer(param_1->objectValue->owner);
    if ((iVar9 == 0) && (param_1->currentTargetValue != in_stack_00000044->caller)) {
      UnitAIModule::askForHelp(param_1,in_stack_00000044->caller);
    }
LAB_00504f5e:
    iVar9 = (param_1->attackingUnitsValue).numberValue;
    iVar4 = in_stack_00000044->caller;
    iVar5 = 0;
    if (0 < iVar9) {
      do {
        if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar5) break;
        if ((param_1->attackingUnitsValue).value[iVar5] == iVar4) goto LAB_00504fe4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar9);
    }
    if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar9) {
      iVar9 = iVar9 + 1;
      piVar6 = (int *)operator_new(iVar9 * 4);
      if (piVar6 != (int *)0x0) {
        iVar5 = 0;
        if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
          do {
            if (iVar9 <= iVar5) break;
            iVar7 = iVar5 + 1;
            piVar6[iVar5] = (param_1->attackingUnitsValue).value[iVar5];
            iVar5 = iVar7;
          } while (iVar7 < (param_1->attackingUnitsValue).maximumSizeValue);
        }
        operator_delete((param_1->attackingUnitsValue).value);
        (param_1->attackingUnitsValue).value = piVar6;
        (param_1->attackingUnitsValue).maximumSizeValue = iVar9;
      }
    }
    (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar4;
    (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_00504fe4:
    (**(code **)(param_1->objectValue->_padding_ + 0xec))();
    fVar10 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0xf4))();
    cVar2 = (**(code **)(param_1->objectValue->_padding_ + 0x134))();
    iVar9 = param_1->currentOrderValue;
    if ((iVar9 == 0x2c6) && (_DAT_005758c4 < (float)fVar10)) {
      return 2;
    }
    if (iVar9 == 700) {
      return 2;
    }
    if ((((iVar9 == 0x2c9) && (cVar2 == '\f')) && (unaff_EBX != 0)) &&
       ((*(short *)(*(int *)(unaff_EBX + 8) + 0x14) == 10 &&
        (*(short *)(in_stack_00000044->p1 + 0x4a) == 0)))) {
      return 2;
    }
    if (iVar9 == 0x2ce) {
      return 2;
    }
    if (*(short *)(in_stack_00000044->p1 + 0x4a) != 0) {
      if ((param_1->currentActionValue == 0x262) && ((float)fVar10 != _DAT_005758c4)) {
        return 3;
      }
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x10))(param_1->objectValue->id);
      if (actionFile != (_iobuf *)0x0) {
        if (param_1->objectValue == (RGE_Static_Object *)0x0) {
          lVar8 = -1;
        }
        else {
          lVar8 = param_1->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar8,s_C__msdev_work_age1_x1_taiuaimd_c,
                0x39a);
      }
      (**(code **)(iVar9 + 0x58))(1);
      (**(code **)(iVar9 + 0xa4))(1);
      return 3;
    }
    if (iVar9 != -1) {
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x10))(param_1->objectValue->id);
      param_1->currentOrderValue = 700;
      param_1->currentOrderPriorityValue = 100;
      (**(code **)(iVar9 + 0x5c))(in_stack_00000044->caller,1);
      param_1->stopAfterTargetKilledValue = '\x01';
      return 3;
    }
    (**(code **)(param_1->_padding_ + 0x5c))();
    return 3;
  }
  iVar9 = param_1->_padding_;
  (**(code **)(iVar9 + 0x58))();
  (**(code **)(iVar9 + 0x1c))();
  return 2;
}

// --------------------------------------------------

// Function: FUN_005057be
// Address: 005057be
// XREFS: None
undefined4 __fastcall FUN_005057be(int param_1,int *param_2)
{
  int in_EAX;
  char cVar1;
  char *unaff_retaddr;
  
  *(char *)param_2 = (char)*param_2 + (char)in_EAX;
  unaff_retaddr[0x69005051] = unaff_retaddr[0x69005051] + (char)unaff_retaddr;
  cVar1 = (char)((uint)param_1 >> 8);
  *(char *)(param_1 + 0x52) = *(char *)(param_1 + 0x52) + cVar1;
  *unaff_retaddr = *unaff_retaddr + (char)((uint)unaff_retaddr >> 8);
  *(char *)(param_1 + 0x5057) = *(char *)(param_1 + 0x5057) + cVar1;
  *param_2 = *param_2 + in_EAX;
  return 5;
}

// --------------------------------------------------

// Function: FUN_00505808
// Address: 00505808
// XREFS: None
undefined4 FUN_00505808(void)
{
  return 9;
}

// --------------------------------------------------

// Function: FUN_00505816
// Address: 00505816
// XREFS: None
UnitAIModule * __thiscall FUN_00505816(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560c88;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribePriestUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x11;
  piVar1 = (int *)operator_new(0x44);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 3;
    param_1->importantObjects[1] = 0;
    param_1->importantObjects[2] = 4;
    param_1->importantObjects[3] = 0x1a;
    param_1->importantObjects[4] = 0x18;
    param_1->importantObjects[5] = 6;
    param_1->importantObjects[6] = 0x19;
    param_1->importantObjects[7] = 0x11;
    param_1->importantObjects[8] = 10;
    param_1->importantObjects[9] = 0xc;
    param_1->importantObjects[10] = 0x23;
    param_1->importantObjects[0xb] = 0x17;
    param_1->importantObjects[0xc] = 0x24;
    param_1->importantObjects[0xd] = 0x1c;
    param_1->importantObjects[0xe] = 0x12;
    param_1->importantObjects[0xf] = 0xd;
    param_1->importantObjects[0x10] = 0x27;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00505968
// Address: 00505968
// XREFS: None
TribePriestUnitAIModule * __thiscall FUN_00505968(TribePriestUnitAIModule *param_1,byte param_2)
{
  TribePriestUnitAIModule::~TribePriestUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00505995
// Address: 00505995
// XREFS: None
undefined4 __thiscall FUN_00505995(int *param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  iVar1 = *param_1;
  iVar2 = (**(code **)(iVar1 + 0xc4))(param_2);
  if (iVar2 != 0) {
    uVar3 = (**(code **)(iVar1 + 0x6c))(param_2,param_2);
    return uVar3;
  }
  if (param_1[10] == -1) {
    iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[1] + 0xc));
    if (iVar2 != 0) {
      fVar4 = (float10)(**(code **)(*(int *)param_1[1] + 0x10c))(param_2);
      uVar3 = (**(code **)(iVar1 + 0x94))(param_2,(float)fVar4);
      return uVar3;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00505a07
// Address: 00505a07
// XREFS: None
undefined4 FUN_00505a07(int param_1)
{
  if ((param_1 != 0x2c0) && (param_1 != 0x2bf)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00505a2f
// Address: 00505a2f
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00505a2f(int param_1,int param_2)
{
  short sVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  
  if (_DAT_005758d4 <= *(float *)(*(int *)(param_1 + 4) + 0x44)) {
    pRVar3 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x3c),param_2);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      sVar1 = pRVar3->master_obj->object_group;
      sVar2 = pRVar3->master_obj->id;
      if ((((((sVar2 != 0x6d) && (sVar1 != 0x1b)) && (sVar2 != 0x9f)) &&
           ((sVar2 != 0x114 && (sVar2 != 0x9e)))) && ((sVar2 != 0xa3 && (sVar1 != 0x1e)))) &&
         (((sVar1 != 0x12 ||
           (_DAT_005758c4 <
            *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x50) + 0x6c))) &&
          ((sVar1 != 3 ||
           (_DAT_005758c4 <
            *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x50) + 0x70))))))) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00505adc
// Address: 00505adc
// XREFS: None
undefined4 __thiscall FUN_00505adc(int *param_1,int param_2)
{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = (**(code **)(*param_1 + 0xc4))(*(undefined4 *)(param_2 + 4));
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00505afc
// Address: 00505afc
// XREFS: None
int __thiscall FUN_00505afc(UnitAIModule *param_1,int param_2,float *param_3)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  long lStack_1c;
  int iStack_18;
  float fStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  (**(code **)(param_1->_padding_ + 0x20))();
  iVar4 = -1;
  lStack_1c = -1;
  fStack_14 = 0.0;
  iStack_18 = 2;
  if (param_1->objectValue->owner->id == 0) {
    iStack_18 = 4;
  }
  iStack_c = 1;
  if (iStack_18 != 0) {
    iStack_8 = 0;
    do {
      iStack_10 = 0;
      if (0 < *(int *)((int)&DAT_0087d7cc + iStack_8)) {
        piVar1 = (int *)((int)&DAT_0087d7e4 + iStack_8);
        do {
          iVar4 = iStack_10 * 8;
          if ((((((*(int *)(iVar4 + *piVar1) != param_1->objectValue->id) &&
                 (pRVar5 = UnitAIModule::lookupObject(param_1,*(int *)(iVar4 + *piVar1)),
                 pRVar5 != (RGE_Static_Object *)0x0)) && (pRVar5->master_obj->object_group != 3)) &&
               (((pRVar5->hp < (float)(int)pRVar5->master_obj->hp && (pRVar5->object_state < 3)) &&
                ((param_2 != 0 || (*(byte *)(iVar4 + 4 + *piVar1) < 5)))))) &&
              ((param_1->objectValue->owner->id != 0 || (*(byte *)(iVar4 + 4 + *piVar1) < 3)))) &&
             (iVar6 = (**(code **)(param_1->objectValue->_padding_ + 0x194))
                                (*(undefined4 *)(iVar4 + *piVar1),0x3f800000,0,0,0xffffffff,
                                 0xffffffff), iVar6 != 0)) {
            fVar3 = (float)*(byte *)(iVar4 + 4 + *piVar1);
            fVar2 = (float)(int)pRVar5->master_obj->hp - pRVar5->hp / fVar3;
            if (((lStack_1c == -1) || (fVar2 < fStack_14)) &&
               (lStack_1c = pRVar5->id, fStack_14 = fVar2, param_3 != (float *)0x0)) {
              *param_3 = fVar3;
            }
          }
          iStack_10 = iStack_10 + 1;
          iVar4 = lStack_1c;
        } while (iStack_10 < *(int *)((int)&DAT_0087d7cc + iStack_8));
      }
      if (iVar4 != -1) {
        return iVar4;
      }
      iStack_c = iStack_c + 1;
      iStack_8 = iStack_8 + 4;
    } while (iStack_c <= iStack_18);
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00505cbd
// Address: 00505cbd
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __thiscall FUN_00505cbd(UnitAIModule *param_1,float *param_2)
{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  long lVar6;
  float fStack_c;
  int iStack_8;
  
  (**(code **)(param_1->_padding_ + 0x20))();
  lVar6 = -1;
  fStack_c = 0.0;
  iStack_8 = 0;
  if (0 < DAT_0087d7d8) {
    do {
      iVar1 = iStack_8 * 8;
      iVar4 = (**(code **)(param_1->objectValue->owner->_padding_ + 0x18))
                        (*(undefined1 *)(DAT_0087d7f0 + 5 + iVar1));
      if ((((iVar4 != 0) &&
           (pRVar5 = UnitAIModule::lookupObject(param_1,*(int *)(DAT_0087d7f0 + iVar1)),
           pRVar5 != (RGE_Static_Object *)0x0)) && (pRVar5->object_state < 3)) &&
         (iVar4 = (**(code **)(param_1->_padding_ + 0xc4))(pRVar5->id), iVar4 != 0)) {
        fVar2 = (float)*(byte *)(DAT_0087d7f0 + 4 + iVar1);
        if (fVar2 < _DAT_005758bc) {
          fVar2 = _DAT_005758bc;
        }
        fVar3 = (float)(int)pRVar5->master_obj->hp / fVar2;
        if (((lVar6 == -1) || (fStack_c < fVar3)) &&
           (lVar6 = pRVar5->id, fStack_c = fVar3, param_2 != (float *)0x0)) {
          *param_2 = fVar2;
        }
      }
      iStack_8 = iStack_8 + 1;
    } while (iStack_8 < DAT_0087d7d8);
  }
  return lVar6;
}

// --------------------------------------------------

// Function: FUN_00505dc7
// Address: 00505dc7
// XREFS: processNotify
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
int __thiscall FUN_00505dc7(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  uchar uVar1;
  long lVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  undefined4 uVar6;
  
  switch(param_2->mType) {
  case 0x1f9:
  case 0x1fb:
  case 0x202:
    break;
  case 0x1fc:
    pRVar4 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue);
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      iVar5 = __ftol();
      iVar3 = __ftol();
      uVar1 = UnitAIModule::visibleStatus(param_1,param_1->objectValue->owner->visible,iVar3,iVar5);
      if (uVar1 == '\x0f') {
        return 2;
      }
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar2 = -1;
      }
      else {
        lVar2 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x68f
             );
    }
    iVar5 = param_1->_padding_;
    (**(code **)(iVar5 + 0x58))(1);
    (**(code **)(iVar5 + 0x1c))(param_2);
  default:
    iVar5 = UnitAIModule::processNotify(param_1,param_2,param_3);
    return iVar5;
  }
  iVar5 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar5 == 0) && (param_1->currentActionValue == 0x25c)) {
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar2 = -1;
      }
      else {
        lVar2 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x63b
             );
    }
    iVar5 = param_1->_padding_;
    uVar6 = 1;
  }
  else {
    if (param_1->currentActionValue == 0x25c) {
      iVar5 = param_1->_padding_;
      iVar3 = (**(code **)(iVar5 + 0xe4))(0);
      if ((iVar3 != -1) && (iVar5 = (**(code **)(iVar5 + 0x6c))(iVar3,1), iVar5 == 1)) {
        return 3;
      }
    }
    else if (param_1->currentActionValue == 0x25b) {
      iVar5 = param_1->_padding_;
      iVar3 = (**(code **)(iVar5 + 0xe0))(0,0);
      if ((iVar3 != -1) && (iVar5 = (**(code **)(iVar5 + 0x70))(iVar3,1), iVar5 == 1)) {
        return 3;
      }
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar2 = -1;
      }
      else {
        lVar2 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar2,s_C__msdev_work_age1_x1_taiuaimd_c,0x675
             );
    }
    iVar5 = param_1->_padding_;
    uVar6 = 0;
  }
  (**(code **)(iVar5 + 0x58))(uVar6);
  (**(code **)(iVar5 + 0x1c))(param_2);
  return 2;
}

// --------------------------------------------------

// Function: FUN_00505fa9
// Address: 00505fa9
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00505fa9(undefined4 param_1,char param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  char cVar5;
  UnitAIModule *this;
  char cVar6;
  char *unaff_EBX;
  int unaff_ESI;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined1 auStack_4 [4];
  
  cVar6 = (char)((uint)unaff_EBX >> 8);
  cVar5 = (char)param_1 + cVar6;
  *unaff_EBX = *unaff_EBX + cVar5;
  this = (UnitAIModule *)CONCAT31((int3)((uint)param_1 >> 8),cVar5 + cVar6);
  *(char *)(unaff_ESI + 0x505f) = *(char *)(unaff_ESI + 0x505f) + param_2;
  iVar2 = RGE_Player::computerPlayer(this->objectValue->owner);
  if (iVar2 != 0) {
    iVar3 = UnitAIModule::processIdle(this,1);
    iVar2 = DAT_0087d7d8;
    if (iVar3 == 6) {
      return 6;
    }
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_taiuaimd_c,0x6ac);
    if ((0 < iVar2) && (iVar2 < iVar3 % (iVar2 + 2))) {
      iVar2 = this->_padding_;
      iVar3 = (**(code **)(iVar2 + 0xe0))(1,auStack_4);
      if (iVar3 != -1) {
        (**(code **)(iVar2 + 0x70))(iVar3,0);
        return 6;
      }
    }
    iVar2 = this->_padding_;
    iVar3 = (**(code **)(iVar2 + 0x40))(0xffffffff,2,0xffffffff,0xffffffff,0);
    if (iVar3 != -1) {
      pRVar4 = RGE_Game_World::object(this->objectValue->owner->world,iVar3);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        pRVar1 = this->objectValue;
        fVar9 = pRVar4->world_x - pRVar1->world_x;
        fVar8 = pRVar4->world_y - pRVar1->world_y;
        fVar10 = SQRT(fVar8 * fVar8 + fVar9 * fVar9);
        fVar7 = (float10)(**(code **)(pRVar1->_padding_ + 0x10c))();
        fVar7 = fVar7 - (float10)fVar10;
        if (fVar7 <= (float10)_DAT_005758c4) {
          return 5;
        }
        pRVar4 = this->objectValue;
        (**(code **)(iVar2 + 0x9c))
                  ((float)(-(((float10)fVar9 / (float10)fVar10) * fVar7) + (float10)pRVar4->world_x)
                   ,(float)(-(((float10)fVar8 / (float10)fVar10) * fVar7) + (float10)pRVar4->world_y
                           ),pRVar4->world_z,1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_00506138
// Address: 00506138
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00506138(int *param_1)
{
  uchar uVar1;
  int iVar2;
  RGE_Action *pRVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[1] + 0xc));
  if (((iVar2 == 1) && (iVar2 = param_1[1], _DAT_005758d4 <= *(float *)(iVar2 + 0x44))) &&
     ((uVar1 = RGE_Action_List::have_action(*(RGE_Action_List **)(iVar2 + 0x184)), uVar1 != '\x01'
      || (pRVar3 = RGE_Action_List::get_action(*(RGE_Action_List **)(iVar2 + 0x184)),
         pRVar3->state != '\a')))) {
    iVar2 = *param_1;
    iVar4 = (**(code **)(iVar2 + 0x30))(1,1,0);
    if ((iVar4 != -1) && (param_1[0xd] != iVar4)) {
      if (param_1[10] != -1) {
        (**(code **)(iVar2 + 0x10))
                  (*(undefined4 *)(param_1[1] + 4),param_1[10],param_1[0xd],0xffffffff,param_1[0xf],
                   param_1[0x10],param_1[0x11],param_1[0x12],0,0,param_1[0xb]);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1[1] == 0) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = *(undefined4 *)(param_1[1] + 4);
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,uVar5,s_C__msdev_work_age1_x1_taiuaimd_c,
                  0x6f8);
        }
        (**(code **)(iVar2 + 0x58))(1);
      }
      iVar2 = (**(code **)(iVar2 + 0x5c))(iVar4,1);
      if (iVar2 == 1) {
        return 10;
      }
    }
  }
  return 9;
}

// --------------------------------------------------

// Function: FUN_00506237
// Address: 00506237
// XREFS: None
UnitAIModule * __thiscall FUN_00506237(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560ca8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeTradeShipUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 5;
  piVar1 = (int *)operator_new(0x14);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 3;
    param_1->importantObjects[1] = 0x16;
    param_1->importantObjects[2] = 0x14;
    param_1->importantObjects[3] = 2;
    param_1->importantObjects[4] = 0x15;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005062e8
// Address: 005062e8
// XREFS: None
TribeTradeShipUnitAIModule * __thiscall
FUN_005062e8(TribeTradeShipUnitAIModule *param_1,byte param_2)
{
  TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00506315
// Address: 00506315
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
int __thiscall FUN_00506315(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  code *pcVar1;
  NotifyEvent *pNVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  long lVar8;
  ulong unaff_EDI;
  undefined4 uVar9;
  
  pNVar2 = param_2;
  iVar3 = param_2->mType;
  if (iVar3 != 500) {
    if (iVar3 == 0x202) {
      if (param_1->currentActionValue == 0x267) {
        iVar3 = param_1->_padding_;
        pcVar1 = *(code **)(iVar3 + 0x40);
        iVar4 = (*pcVar1)(0xffffffff,0,2,0x2d,0);
        if (iVar4 != -1) {
          iVar4 = (**(code **)(iVar3 + 0x7c))(iVar4,1);
          if (iVar4 == 1) {
            return 6;
          }
        }
        iVar4 = (*pcVar1)(0xffffffff,1,2,0x2d,0);
        if (iVar4 != -1) {
          iVar3 = (**(code **)(iVar3 + 0x7c))(iVar4,1);
          if (iVar3 == 1) {
            return 6;
          }
        }
        goto LAB_00506485;
      }
      if (param_1->currentActionValue != 0x25d) goto LAB_00506485;
      iVar3 = param_1->_padding_;
      iVar4 = (**(code **)(iVar3 + 0x48))(&param_2,&param_3,1);
      if (iVar4 == 1) {
        UnitAIModule::addToWaypointQueue(param_1,(int)param_2,param_3);
        iVar4 = (**(code **)(iVar3 + 0x80))(param_2,param_3,1);
        if (iVar4 != 0) goto LAB_00506485;
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar8 = -1;
            uVar9 = 0x79c;
          }
          else {
            lVar8 = param_1->objectValue->id;
            uVar9 = 0x79c;
          }
          goto LAB_00506464;
        }
      }
      else {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar8 = -1;
          }
          else {
            lVar8 = param_1->objectValue->id;
          }
          uVar9 = 0x7a8;
LAB_00506464:
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar8,s_C__msdev_work_age1_x1_taiuaimd_c,
                  uVar9);
        }
      }
      (**(code **)(iVar3 + 0x58))(1);
      (**(code **)(iVar3 + 0x1c))(pNVar2);
LAB_00506485:
      UnitAIModule::removeCurrentTarget(param_1);
      if (actionFile != (_iobuf *)0x0) {
        if (param_1->objectValue == (RGE_Static_Object *)0x0) {
          lVar8 = -1;
        }
        else {
          lVar8 = param_1->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar8,s_C__msdev_work_age1_x1_taiuaimd_c,
                0x7b0);
      }
      iVar3 = param_1->_padding_;
      (**(code **)(iVar3 + 0x58))(1);
      (**(code **)(iVar3 + 0x1c))(pNVar2);
      return 2;
    }
    if (iVar3 != 0x20f) {
      iVar3 = UnitAIModule::processNotify(param_1,param_2,param_3);
      return iVar3;
    }
  }
  if (param_2->p2 < 1) {
    lVar8 = param_1->objectValue->id;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))
              (lVar8,lVar8,0x209,param_2->caller,0,0);
    UnitAIModule::purgeNotifyQueue(param_1,unaff_EDI);
    return 4;
  }
  if ((param_1->attackingUnitsValue).numberValue != 0) {
    iVar3 = RGE_Player::computerPlayer(param_1->objectValue->owner);
    if (iVar3 != 1) goto LAB_0050654f;
  }
  lVar8 = param_1->objectValue->id;
  (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))(lVar8,lVar8,0x201,pNVar2->caller,0,0)
  ;
LAB_0050654f:
  iVar3 = (param_1->attackingUnitsValue).numberValue;
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar4) break;
      if ((param_1->attackingUnitsValue).value[iVar4] == pNVar2->caller) goto LAB_00506592;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  iVar3 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar3 == 0) && (param_1->currentTargetValue != pNVar2->caller)) {
    UnitAIModule::askForHelp(param_1,pNVar2->caller);
  }
LAB_00506592:
  iVar3 = (param_1->attackingUnitsValue).numberValue;
  iVar4 = pNVar2->caller;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar5) break;
      if ((param_1->attackingUnitsValue).value[iVar5] == iVar4) goto LAB_00506615;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar3) {
    iVar3 = iVar3 + 1;
    piVar6 = (int *)operator_new(iVar3 * 4);
    if (piVar6 != (int *)0x0) {
      iVar5 = 0;
      if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
        do {
          if (iVar3 <= iVar5) break;
          iVar7 = iVar5 + 1;
          piVar6[iVar5] = (param_1->attackingUnitsValue).value[iVar5];
          iVar5 = iVar7;
        } while (iVar7 < (param_1->attackingUnitsValue).maximumSizeValue);
      }
      operator_delete((param_1->attackingUnitsValue).value);
      (param_1->attackingUnitsValue).value = piVar6;
      (param_1->attackingUnitsValue).maximumSizeValue = iVar3;
    }
  }
  (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar4;
  (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_00506615:
  (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
  iVar3 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar3 == 0) && (param_1->currentOrderValue != -1)) {
    return 2;
  }
  if (param_1->currentActionValue != 0x262) {
    iVar3 = param_1->_padding_;
    (**(code **)(iVar3 + 0x10))
              (param_1->objectValue->id,param_1->currentOrderValue,param_1->currentTargetValue,
               0xffffffff,param_1->currentTargetXValue,param_1->currentTargetYValue,
               param_1->currentTargetZValue,param_1->desiredTargetDistanceValue,0,0,
               param_1->currentOrderPriorityValue);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar8 = -1;
      }
      else {
        lVar8 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar8,s_C__msdev_work_age1_x1_taiuaimd_c,0x761
             );
    }
    (**(code **)(iVar3 + 0x58))(1);
  }
  (**(code **)(param_1->_padding_ + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: FUN_005066cd
// Address: 005066cd
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005066cd(int *param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  float10 fVar7;
  
  iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[1] + 0xc));
  if (iVar4 != 0) {
    iVar4 = *param_1;
    iVar5 = (**(code **)(iVar4 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
    if (iVar5 != -1) {
      pRVar6 = RGE_Game_World::object(*(RGE_Game_World **)(*(int *)(param_1[1] + 0xc) + 0x3c),iVar5)
      ;
      if (pRVar6 != (RGE_Static_Object *)0x0) {
        fVar7 = (float10)(**(code **)(*(int *)param_1[1] + 0xfc))();
        iVar5 = param_1[1];
        fVar3 = pRVar6->world_x - *(float *)(iVar5 + 0x38);
        fVar1 = pRVar6->world_y - *(float *)(iVar5 + 0x3c);
        fVar2 = SQRT(fVar1 * fVar1 + fVar3 * fVar3);
        (**(code **)(iVar4 + 0x9c))
                  (-((fVar3 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x38),
                   -((fVar1 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_005067ca
// Address: 005067ca
// XREFS: None
UnitAIModule * __thiscall FUN_005067ca(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560cc8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeTransportShipUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 5;
  piVar1 = (int *)operator_new(0x14);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 3;
    param_1->importantObjects[1] = 0x16;
    param_1->importantObjects[2] = 0x14;
    param_1->importantObjects[3] = 2;
    param_1->importantObjects[4] = 0x15;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00506878
// Address: 00506878
// XREFS: None
TribeTransportShipUnitAIModule * __thiscall
FUN_00506878(TribeTransportShipUnitAIModule *param_1,byte param_2)
{
  TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005068a5
// Address: 005068a5
// XREFS: None
int __thiscall FUN_005068a5(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  long lVar1;
  RGE_Static_Object *pRVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  RGE_Action *pRVar9;
  ulong unaff_EDI;
  
  if ((param_2->mType != 500) && (param_2->mType != 0x20f)) {
    iVar4 = UnitAIModule::processNotify(param_1,param_2,param_3);
    return iVar4;
  }
  if (param_2->p2 < 1) {
    lVar1 = param_1->objectValue->id;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))
              (lVar1,lVar1,0x209,param_2->caller,0,0);
    UnitAIModule::purgeNotifyQueue(param_1,unaff_EDI);
    return 4;
  }
  if (((param_1->attackingUnitsValue).numberValue == 0) ||
     (iVar4 = RGE_Player::computerPlayer(param_1->objectValue->owner), iVar4 == 1)) {
    lVar1 = param_1->objectValue->id;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))
              (lVar1,lVar1,0x201,param_2->caller,0,0);
  }
  iVar4 = (param_1->attackingUnitsValue).numberValue;
  iVar5 = 0;
  if (0 < iVar4) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar5) break;
      if ((param_1->attackingUnitsValue).value[iVar5] == param_2->caller) goto LAB_00506990;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  iVar4 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar4 == 0) && (param_1->currentTargetValue != param_2->caller)) {
    UnitAIModule::askForHelp(param_1,param_2->caller);
  }
LAB_00506990:
  iVar4 = (param_1->attackingUnitsValue).numberValue;
  iVar5 = param_2->caller;
  iVar6 = 0;
  if (0 < iVar4) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar6) break;
      if ((param_1->attackingUnitsValue).value[iVar6] == iVar5) goto LAB_00506a12;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar4) {
    iVar4 = iVar4 + 1;
    piVar7 = (int *)operator_new(iVar4 * 4);
    if (piVar7 != (int *)0x0) {
      iVar6 = 0;
      if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
        do {
          if (iVar4 <= iVar6) break;
          iVar8 = iVar6 + 1;
          piVar7[iVar6] = (param_1->attackingUnitsValue).value[iVar6];
          iVar6 = iVar8;
        } while (iVar8 < (param_1->attackingUnitsValue).maximumSizeValue);
      }
      operator_delete((param_1->attackingUnitsValue).value);
      (param_1->attackingUnitsValue).value = piVar7;
      (param_1->attackingUnitsValue).maximumSizeValue = iVar4;
    }
  }
  (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar5;
  (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_00506a12:
  (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
  if (param_1->currentOrderValue != -1) {
    return 2;
  }
  pRVar2 = param_1->objectValue;
  uVar3 = RGE_Action_List::have_action((RGE_Action_List *)pRVar2[2].unitAIValue);
  if ((uVar3 != '\0') &&
     (pRVar9 = RGE_Action_List::get_action((RGE_Action_List *)pRVar2[2].unitAIValue),
     pRVar9->state != '\x02')) {
    return 3;
  }
  (**(code **)(param_1->_padding_ + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: FUN_00506a6c
// Address: 00506a6c
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00506a6c(int *param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  float10 fVar7;
  
  iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[1] + 0xc));
  if (iVar4 != 0) {
    iVar4 = *param_1;
    iVar5 = (**(code **)(iVar4 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
    if (iVar5 != -1) {
      pRVar6 = RGE_Game_World::object(*(RGE_Game_World **)(*(int *)(param_1[1] + 0xc) + 0x3c),iVar5)
      ;
      if (pRVar6 != (RGE_Static_Object *)0x0) {
        fVar7 = (float10)(**(code **)(*(int *)param_1[1] + 0xfc))();
        iVar5 = param_1[1];
        fVar3 = pRVar6->world_x - *(float *)(iVar5 + 0x38);
        fVar1 = pRVar6->world_y - *(float *)(iVar5 + 0x3c);
        fVar2 = SQRT(fVar1 * fVar1 + fVar3 * fVar3);
        (**(code **)(iVar4 + 0x9c))
                  (-((fVar3 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x38),
                   -((fVar1 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_00506b6a
// Address: 00506b6a
// XREFS: None
UnitAIModule * __thiscall FUN_00506b6a(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560ce8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeFishingShipUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 8;
  piVar1 = (int *)operator_new(0x20);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 3;
    param_1->importantObjects[1] = 0x16;
    param_1->importantObjects[2] = 0x14;
    param_1->importantObjects[3] = 2;
    param_1->importantObjects[4] = 0x15;
    param_1->importantObjects[5] = 5;
    param_1->importantObjects[6] = 0x1f;
    param_1->importantObjects[7] = 0x21;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00506c3f
// Address: 00506c3f
// XREFS: None
TribeFishingShipUnitAIModule * __thiscall
FUN_00506c3f(TribeFishingShipUnitAIModule *param_1,byte param_2)
{
  TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00506c65
// Address: 00506c65
// XREFS: None
undefined4 FUN_00506c65(int param_1)
{
  if ((param_1 != 0x1f) && (param_1 != 5)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00506c8b
// Address: 00506c8b
// XREFS: None
undefined4 FUN_00506c8b(int param_1)
{
  if (((param_1 != 0x1f) && (param_1 != 5)) && (param_1 != 0x21)) {
    return 0xffffffff;
  }
  return 2;
}

// --------------------------------------------------

// Function: FUN_00506cb1
// Address: 00506cb1
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
int __thiscall FUN_00506cb1(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  long lVar6;
  ulong unaff_EDI;
  
  if ((param_2->mType != 500) && (param_2->mType != 0x20f)) {
    iVar1 = UnitAIModule::processNotify(param_1,param_2,param_3);
    return iVar1;
  }
  if (param_2->p2 < 1) {
    lVar6 = param_1->objectValue->id;
    (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))
              (lVar6,lVar6,0x209,param_2->caller,0,0);
    UnitAIModule::purgeNotifyQueue(param_1,unaff_EDI);
    return 4;
  }
  if ((param_1->attackingUnitsValue).numberValue != 0) {
    iVar1 = RGE_Player::computerPlayer(param_1->objectValue->owner);
    if (iVar1 != 1) goto LAB_00506d5f;
  }
  lVar6 = param_1->objectValue->id;
  (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))
            (lVar6,lVar6,0x201,param_2->caller,0,0);
LAB_00506d5f:
  iVar1 = (param_1->attackingUnitsValue).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar2) break;
      if ((param_1->attackingUnitsValue).value[iVar2] == param_2->caller) goto LAB_00506da0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  iVar1 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar1 == 0) && (param_1->currentTargetValue != param_2->caller)) {
    UnitAIModule::askForHelp(param_1,param_2->caller);
  }
LAB_00506da0:
  iVar1 = (param_1->attackingUnitsValue).numberValue;
  iVar2 = param_2->caller;
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar3) break;
      if ((param_1->attackingUnitsValue).value[iVar3] == iVar2) goto LAB_00506e22;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar4 = (int *)operator_new(iVar1 * 4);
    if (piVar4 != (int *)0x0) {
      iVar3 = 0;
      if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
        do {
          if (iVar1 <= iVar3) break;
          iVar5 = iVar3 + 1;
          piVar4[iVar3] = (param_1->attackingUnitsValue).value[iVar3];
          iVar3 = iVar5;
        } while (iVar5 < (param_1->attackingUnitsValue).maximumSizeValue);
      }
      operator_delete((param_1->attackingUnitsValue).value);
      (param_1->attackingUnitsValue).value = piVar4;
      (param_1->attackingUnitsValue).maximumSizeValue = iVar1;
    }
  }
  (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar2;
  (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_00506e22:
  (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
  iVar1 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar1 == 0) && (param_1->currentOrderValue != -1)) {
    return 2;
  }
  if (param_1->currentActionValue != 0x262) {
    iVar1 = param_1->_padding_;
    (**(code **)(iVar1 + 0x10))
              (param_1->objectValue->id,param_1->currentOrderValue,param_1->currentTargetValue,
               0xffffffff,param_1->currentTargetXValue,param_1->currentTargetYValue,
               param_1->currentTargetZValue,param_1->desiredTargetDistanceValue,0,0,
               param_1->currentOrderPriorityValue);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar6 = -1;
      }
      else {
        lVar6 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar6,s_C__msdev_work_age1_x1_taiuaimd_c,0x8d4
             );
    }
    (**(code **)(iVar1 + 0x58))(1);
  }
  (**(code **)(param_1->_padding_ + 0xa4))(1);
  return 3;
}

// --------------------------------------------------

// Function: FUN_00506eda
// Address: 00506eda
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00506eda(int *param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  float10 fVar7;
  
  iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[1] + 0xc));
  if (iVar4 != 0) {
    iVar4 = *param_1;
    iVar5 = (**(code **)(iVar4 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0);
    if (iVar5 != -1) {
      pRVar6 = RGE_Game_World::object(*(RGE_Game_World **)(*(int *)(param_1[1] + 0xc) + 0x3c),iVar5)
      ;
      if (pRVar6 != (RGE_Static_Object *)0x0) {
        fVar7 = (float10)(**(code **)(*(int *)param_1[1] + 0xfc))();
        iVar5 = param_1[1];
        fVar3 = pRVar6->world_x - *(float *)(iVar5 + 0x38);
        fVar1 = pRVar6->world_y - *(float *)(iVar5 + 0x3c);
        fVar2 = SQRT(fVar1 * fVar1 + fVar3 * fVar3);
        (**(code **)(iVar4 + 0x9c))
                  (-((fVar3 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x38),
                   -((fVar1 / fVar2) * (float)(fVar7 * (float10)_DAT_005758d8)) +
                   *(float *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_00506fda
// Address: 00506fda
// XREFS: None
UnitAIModule * __thiscall FUN_00506fda(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560d08;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeSoldierUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x15;
  piVar1 = (int *)operator_new(0x54);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    param_1->importantObjects[1] = 3;
    param_1->importantObjects[2] = 4;
    param_1->importantObjects[3] = 0x1a;
    param_1->importantObjects[4] = 0x18;
    param_1->importantObjects[5] = 6;
    param_1->importantObjects[6] = 0x23;
    param_1->importantObjects[7] = 0x19;
    param_1->importantObjects[8] = 0x11;
    param_1->importantObjects[9] = 0xc;
    param_1->importantObjects[10] = 0x17;
    param_1->importantObjects[0xb] = 0x24;
    param_1->importantObjects[0xc] = 0x1c;
    param_1->importantObjects[0xd] = 0x12;
    param_1->importantObjects[0xe] = 0xd;
    param_1->importantObjects[0xf] = 0x1b;
    param_1->importantObjects[0x10] = 0x16;
    param_1->importantObjects[0x11] = 0x14;
    param_1->importantObjects[0x12] = 2;
    param_1->importantObjects[0x13] = 0x15;
    param_1->importantObjects[0x14] = 0x27;
  }
  param_1->idleTimeoutValue = 0x5dc;
  UnitAIModule::setAdjustedIdleTimeout(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0050716d
// Address: 0050716d
// XREFS: None
TribeSoldierUnitAIModule * __thiscall FUN_0050716d(TribeSoldierUnitAIModule *param_1,byte param_2)
{
  TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00507195
// Address: 00507195
// XREFS: None
uint FUN_00507195(uint param_1)
{
  if (param_1 == 0) {
    return param_1;
  }
  return (uint)(*(short *)(*(int *)(param_1 + 8) + 0x14) != 1);
}

// --------------------------------------------------

// Function: FUN_005071bd
// Address: 005071bd
// XREFS: None
undefined4 FUN_005071bd(int param_1)
{
  if ((((param_1 != 3) && (param_1 != 0x1b)) && (param_1 != 4)) &&
     (((param_1 != 0x15 && (param_1 != 2)) && (param_1 != 0x14)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005071ef
// Address: 005071ef
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_005071ef(UnitAIModule *param_1,NotifyEvent *param_2,ulong param_3)
{
  short sVar1;
  NotifyEvent *pNVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  float fVar10;
  float10 fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStack_8;
  
  pNVar2 = param_2;
  if (param_2->mType == 0x200) {
    iVar3 = RGE_Player::computerPlayer(param_1->objectValue->owner);
    if (((iVar3 != 0) &&
        (fVar11 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x10c))(),
        (float10)_DAT_005758bc <= fVar11)) &&
       (param_1->objectValue->master_obj->object_group != 0x1a)) {
      if (param_1->currentActionValue != 600) {
        return 2;
      }
      pRVar4 = RGE_Game_World::object
                         (param_1->objectValue->owner->world,param_1->currentTargetValue);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        fVar11 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x10c))();
        fVar12 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar4);
        if (_DAT_005758bc <= (float)fVar11 - fVar12) {
          fVar12 = param_1->desiredTargetDistanceValue;
          fVar15 = 0.0;
          fVar14 = param_1->currentTargetYValue;
          fVar13 = param_1->currentTargetXValue;
          fVar10 = (float)param_1->_padding_;
          (**(code **)((int)fVar10 + 0x10))
                    (param_1->objectValue->id,700,param_1->currentTargetValue,0xffffffff,fVar13,
                     fVar14,param_1->currentTargetZValue,fVar12,0,1,
                     param_1->currentOrderPriorityValue);
          iVar3 = (param_1->attackingUnitsValue).numberValue;
          if ((0 < iVar3) && (iVar9 = 0, 0 < iVar3)) {
            do {
              fVar10 = fVar14;
              if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar9) {
                piVar6 = (int *)operator_new(iVar9 * 4 + 4);
                if (piVar6 != (int *)0x0) {
                  iVar3 = 0;
                  if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
                    do {
                      if (iVar9 + 1 <= iVar3) break;
                      iVar7 = iVar3 + 1;
                      piVar6[iVar3] = (param_1->attackingUnitsValue).value[iVar3];
                      iVar3 = iVar7;
                    } while (iVar7 < (param_1->attackingUnitsValue).maximumSizeValue);
                  }
                  operator_delete((param_1->attackingUnitsValue).value);
                  (param_1->attackingUnitsValue).value = piVar6;
                  (param_1->attackingUnitsValue).maximumSizeValue = iVar9 + 1;
                }
              }
              if ((param_1->attackingUnitsValue).value[iVar9] != param_1->currentTargetValue) {
                if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar9) {
                  piVar6 = (int *)operator_new(iVar9 * 4 + 4);
                  if (piVar6 != (int *)0x0) {
                    iVar3 = 0;
                    if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
                      do {
                        if (iVar9 + 1 <= iVar3) break;
                        iVar7 = iVar3 + 1;
                        piVar6[iVar3] = (param_1->attackingUnitsValue).value[iVar3];
                        iVar3 = iVar7;
                      } while (iVar7 < (param_1->attackingUnitsValue).maximumSizeValue);
                    }
                    operator_delete((param_1->attackingUnitsValue).value);
                    (param_1->attackingUnitsValue).value = piVar6;
                    (param_1->attackingUnitsValue).maximumSizeValue = iVar9 + 1;
                  }
                }
                pRVar4 = RGE_Game_World::object
                                   (param_1->objectValue->owner->world,
                                    (param_1->attackingUnitsValue).value[iVar9]);
                if (pRVar4 != (RGE_Static_Object *)0x0) {
                  fVar15 = (pRVar4->world_x - param_1->objectValue->world_x) + fVar15;
                  fVar12 = (pRVar4->world_y - param_1->objectValue->world_y) + fVar12;
                }
              }
              iVar9 = iVar9 + 1;
              fVar14 = fVar10;
            } while (iVar9 < (param_1->attackingUnitsValue).numberValue);
          }
          pRVar4 = param_1->objectValue;
          fVar14 = SQRT(fVar12 * fVar12 + fVar15 * fVar15);
          iVar3 = (**(code **)((int)fVar10 + 0xa0))
                            (-((fVar15 / fVar14) * fVar13) + pRVar4->world_x,
                             -((fVar12 / fVar14) * fVar13) + pRVar4->world_y,pRVar4->world_z,0,1);
          if (iVar3 != 1) {
            return 2;
          }
          return 3;
        }
      }
    }
  }
  else if (((param_2->mType == 0x20f) &&
           (iVar3 = RGE_Player::computerPlayer(param_1->objectValue->owner), iVar3 != 0)) &&
          ((pRVar4 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2->caller),
           pRVar4 != (RGE_Static_Object *)0x0 &&
           (((sVar1 = pRVar4->master_obj->id, sVar1 == 0x23 || (sVar1 == 0x24)) &&
            (param_1->currentActionValue != -1)))))) {
    if (param_1->currentOrderValue != -1) {
      (**(code **)(param_1->_padding_ + 0x10))
                (param_1->objectValue->id,param_1->currentOrderValue,param_1->currentTargetValue,
                 0xffffffff,param_1->currentTargetXValue,param_1->currentTargetYValue,
                 param_1->currentTargetZValue,param_1->desiredTargetDistanceValue,0,0,
                 param_1->currentOrderPriorityValue);
    }
    pRVar4 = param_1->objectValue;
    uVar5 = debug_rand(s_C__msdev_work_age1_x1_taiuaimd_c,0x97c);
    uVar8 = (int)uVar5 >> 0x1f;
    fStack_8 = (pRVar4->world_x - _DAT_005758dc) +
               (float)(int)(((uVar5 ^ uVar8) - uVar8 & 7 ^ uVar8) - uVar8);
    if (fStack_8 == pRVar4->world_x) {
      fVar12 = _DAT_005758e4;
      if (_DAT_005758e0 < fStack_8) {
        fVar12 = _DAT_005758c0;
      }
      fStack_8 = fStack_8 - fVar12;
    }
    pRVar4 = param_1->objectValue;
    uVar5 = debug_rand(s_C__msdev_work_age1_x1_taiuaimd_c,0x983);
    uVar8 = (int)uVar5 >> 0x1f;
    param_2 = (NotifyEvent *)
              ((pRVar4->world_y - _DAT_005758dc) +
              (float)(int)(((uVar5 ^ uVar8) - uVar8 & 7 ^ uVar8) - uVar8));
    if ((float)param_2 == pRVar4->world_y) {
      fVar12 = _DAT_005758e4;
      if (_DAT_005758e0 < (float)param_2) {
        fVar12 = _DAT_005758c0;
      }
      param_2 = (NotifyEvent *)((float)param_2 - fVar12);
    }
    iVar3 = (**(code **)(param_1->_padding_ + 0xa0))(fStack_8,param_2,pRVar4->world_z,1,1);
    if (iVar3 == 1) {
      taskedThisUpdate = iVar3;
      return 3;
    }
  }
  iVar3 = UnitAIModule::processNotify(param_1,pNVar2,param_3);
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_0050763a
// Address: 0050763a
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0050763a(int *param_1,int param_2)
{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  RGE_Static_Object *pRVar7;
  float10 fVar8;
  
  if ((param_2 == 1) && (iVar5 = (**(code **)(*param_1 + 0xdc))(), iVar5 == 8)) {
    return 6;
  }
  if ((((*(RGE_Player **)(param_1[1] + 0xc))->id != 0) &&
      ((iVar5 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[1] + 0xc)), iVar5 != 0 ||
       (*(short *)(*(int *)(param_1[1] + 8) + 0x10) != 299)))) &&
     ((param_1[10] != 0x2d5 ||
      (((sVar1 = *(short *)(*(int *)(param_1[1] + 8) + 0x10), sVar1 != 0x23 && (sVar1 != 0x24)) &&
       (sVar1 != 0xfa)))))) {
    iVar5 = *param_1;
    iVar6 = (**(code **)(iVar5 + 0x30))(1,0,0);
    if ((iVar6 != -1) && (iVar6 = (**(code **)(iVar5 + 0x5c))(iVar6,1), iVar6 == 1)) {
      return 6;
    }
    iVar6 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[1] + 0xc));
    if ((iVar6 != 0) &&
       (iVar6 = RGE_Static_Object::inGroup((RGE_Static_Object *)param_1[1]), iVar6 != 1)) {
      RGE_Game_World::difficultyLevel(*(RGE_Game_World **)(*(int *)(param_1[1] + 0xc) + 0x3c));
      iVar6 = RGE_Base_Game::scenarioGame(rge_base_game);
      if ((iVar6 == 1) &&
         ((iVar6 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar6 == 1 &&
          (iVar6 = (**(code **)(**(int **)(param_1[1] + 0xc) + 0x3c))(0x8f), iVar6 == 0)))) {
        return 5;
      }
      iVar6 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar6 == 1) &&
         (iVar6 = (**(code **)(**(int **)(param_1[1] + 0xc) + 0x3c))(0x8f), iVar6 == 0)) {
        return 5;
      }
      if ((((param_1[10] != 0x2bd) && (param_1[10] != 0x2d5)) &&
          (iVar6 = (**(code **)(iVar5 + 0x40))(0xffffffff,0xffffffff,0xffffffff,0xffffffff,0),
          iVar6 != -1)) &&
         (pRVar7 = RGE_Game_World::object
                             (*(RGE_Game_World **)(*(int *)(param_1[1] + 0xc) + 0x3c),iVar6),
         pRVar7 != (RGE_Static_Object *)0x0)) {
        fVar8 = (float10)(**(code **)(*(int *)param_1[1] + 0xfc))();
        iVar6 = param_1[1];
        fVar4 = pRVar7->world_x - *(float *)(iVar6 + 0x38);
        fVar2 = pRVar7->world_y - *(float *)(iVar6 + 0x3c);
        fVar3 = SQRT(fVar2 * fVar2 + fVar4 * fVar4);
        (**(code **)(iVar5 + 0x9c))
                  (-((fVar4 / fVar3) * (float)(fVar8 * (float10)_DAT_005758b0)) +
                   *(float *)(iVar6 + 0x38),
                   -((fVar2 / fVar3) * (float)(fVar8 * (float10)_DAT_005758b0)) +
                   *(float *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x40),1);
        return 6;
      }
    }
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_00507874
// Address: 00507874
// XREFS: None
UnitAIModule * __thiscall FUN_00507874(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560d28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeArtifactUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x13;
  piVar1 = (int *)operator_new(0x4c);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    param_1->importantObjects[1] = 4;
    param_1->importantObjects[2] = 0x1a;
    param_1->importantObjects[3] = 0x18;
    param_1->importantObjects[4] = 6;
    param_1->importantObjects[5] = 0x23;
    param_1->importantObjects[6] = 0x19;
    param_1->importantObjects[7] = 0x11;
    param_1->importantObjects[8] = 0xc;
    param_1->importantObjects[9] = 0x17;
    param_1->importantObjects[10] = 0x24;
    param_1->importantObjects[0xb] = 0x1c;
    param_1->importantObjects[0xc] = 0x12;
    param_1->importantObjects[0xd] = 0xd;
    param_1->importantObjects[0xe] = 0x16;
    param_1->importantObjects[0xf] = 0x14;
    param_1->importantObjects[0x10] = 2;
    param_1->importantObjects[0x11] = 0x15;
    param_1->importantObjects[0x12] = 0x27;
  }
  param_1->idleTimeoutValue = 5000;
  UnitAIModule::setAdjustedIdleTimeout(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005079f3
// Address: 005079f3
// XREFS: None
TribeArtifactUnitAIModule * __thiscall FUN_005079f3(TribeArtifactUnitAIModule *param_1,byte param_2)
{
  TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00507a25
// Address: 00507a25
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
undefined4 __thiscall FUN_00507a25(UnitAIModule *param_1,int *param_2)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  long lVar8;
  undefined4 uVar9;
  
  switch(param_2[2]) {
  case 500:
  case 0x1f6:
  case 0x1f7:
  case 0x1f8:
  case 0x1fd:
  case 0x1fe:
  case 0x1ff:
  case 0x200:
  case 0x202:
  case 0x203:
  case 0x20b:
  case 0x20f:
  case 0x259:
  case 0x25a:
  case 0x25b:
  case 0x25c:
  case 0x25d:
  case 0x25e:
  case 0x25f:
  case 0x260:
  case 0x261:
  case 0x262:
  case 0x265:
  case 0x266:
  case 0x267:
  case 0x268:
  case 0x269:
  case 699:
    goto switchD_00507a55_caseD_1f4;
  default:
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar8 = -1;
      }
      else {
        lVar8 = param_1->objectValue->id;
      }
      uVar9 = 0xb1f;
LAB_00507d51:
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar8,s_C__msdev_work_age1_x1_taiuaimd_c,uVar9
             );
    }
    break;
  case 0x1f9:
    iVar3 = param_1->currentOrderValue;
    if (iVar3 != -1) {
      if (param_1->currentActionValue + 100 == iVar3) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar8 = -1;
            uVar9 = 0xac6;
          }
          else {
            lVar8 = param_1->objectValue->id;
            uVar9 = 0xac6;
          }
          goto LAB_00507d51;
        }
        break;
      }
      if (iVar3 != -1) {
        return 2;
      }
    }
    if (param_1->currentActionValue != param_2[3]) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar8 = -1;
        uVar9 = 0xacf;
      }
      else {
        lVar8 = param_1->objectValue->id;
        uVar9 = 0xacf;
      }
      goto LAB_00507d51;
    }
    break;
  case 0x1fa:
    iVar3 = param_1->currentOrderValue;
    if (iVar3 != -1) {
      if (param_1->currentActionValue + 100 == iVar3) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar8 = -1;
            uVar9 = 0xaae;
          }
          else {
            lVar8 = param_1->objectValue->id;
            uVar9 = 0xaae;
          }
          goto LAB_00507d51;
        }
        break;
      }
      if (iVar3 != -1) {
        return 2;
      }
    }
    if (param_1->currentActionValue != param_2[3]) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar8 = -1;
        uVar9 = 0xab7;
      }
      else {
        lVar8 = param_1->objectValue->id;
        uVar9 = 0xab7;
      }
      goto LAB_00507d51;
    }
    break;
  case 0x1fb:
    iVar3 = param_1->currentOrderValue;
    if (iVar3 != -1) {
      if (param_1->currentActionValue + 100 == iVar3) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar8 = -1;
            uVar9 = 0xade;
          }
          else {
            lVar8 = param_1->objectValue->id;
            uVar9 = 0xade;
          }
          goto LAB_00507d51;
        }
        break;
      }
      if (iVar3 != -1) {
        return 2;
      }
    }
    if (param_1->currentActionValue != param_2[3]) {
      return 2;
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar8 = -1;
        uVar9 = 0xae7;
      }
      else {
        lVar8 = param_1->objectValue->id;
        uVar9 = 0xae7;
      }
      goto LAB_00507d51;
    }
    break;
  case 0x1fc:
    pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_1->currentTargetValue);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      iVar3 = __ftol();
      iVar4 = __ftol();
      uVar1 = RGE_Visible_Map::get_visible(param_1->objectValue->owner->visible,iVar4,iVar3);
      if (uVar1 == '\x0f') {
        return 2;
      }
    }
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar8 = -1;
        uVar9 = 0xa9f;
      }
      else {
        lVar8 = param_1->objectValue->id;
        uVar9 = 0xa9f;
      }
      goto LAB_00507d51;
    }
    break;
  case 600:
    iVar3 = (param_1->attackingUnitsValue).numberValue;
    iVar4 = *param_2;
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar5) break;
        if ((param_1->attackingUnitsValue).value[iVar5] == iVar4) goto LAB_00507d13;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar3) {
      iVar3 = iVar3 + 1;
      piVar6 = (int *)operator_new(iVar3 * 4);
      if (piVar6 != (int *)0x0) {
        iVar5 = 0;
        if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
          do {
            if (iVar3 <= iVar5) break;
            iVar7 = iVar5 + 1;
            piVar6[iVar5] = (param_1->attackingUnitsValue).value[iVar5];
            iVar5 = iVar7;
          } while (iVar7 < (param_1->attackingUnitsValue).maximumSizeValue);
        }
        operator_delete((param_1->attackingUnitsValue).value);
        (param_1->attackingUnitsValue).value = piVar6;
        (param_1->attackingUnitsValue).maximumSizeValue = iVar3;
      }
    }
    (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] = iVar4;
    (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_00507d13:
    (**(code **)(param_1->objectValue->_padding_ + 0xec))(1);
    return 2;
  }
  iVar3 = param_1->_padding_;
  (**(code **)(iVar3 + 0x58))(1);
  (**(code **)(iVar3 + 0x1c))(param_2);
switchD_00507a55_caseD_1f4:
  return 2;
}

// --------------------------------------------------

// Function: FUN_00507ee6
// Address: 00507ee6
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_taiuaimd_c: "C:\msdev\work\age1_x1\taiuaimd.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
undefined4 __fastcall FUN_00507ee6(UnitAIModule *param_1)
{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar1 = param_1->_padding_;
  iVar2 = (**(code **)(iVar1 + 0xd4))(1);
  if (iVar2 == 6) {
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar3 = -1;
      }
      else {
        lVar3 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar3,s_C__msdev_work_age1_x1_taiuaimd_c,0xb60
             );
    }
    (**(code **)(iVar1 + 0x58))(1);
    param_1->idleTimerValue = 0;
    return 10;
  }
  return 9;
}

// --------------------------------------------------

// Function: FUN_00507f5d
// Address: 00507f5d
// XREFS: None
UnitAIModule * __thiscall FUN_00507f5d(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560d48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  UnitAIModule::UnitAIModule(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeTowerUnitAIModule::_vftable_;
  param_1->numberImportantObjects = 0x15;
  piVar1 = (int *)operator_new(0x54);
  param_1->importantObjects = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    param_1->importantObjects[1] = 3;
    param_1->importantObjects[2] = 4;
    param_1->importantObjects[3] = 0x1a;
    param_1->importantObjects[4] = 0x18;
    param_1->importantObjects[5] = 6;
    param_1->importantObjects[6] = 0x23;
    param_1->importantObjects[7] = 0x19;
    param_1->importantObjects[8] = 0x11;
    param_1->importantObjects[9] = 0xc;
    param_1->importantObjects[10] = 0x17;
    param_1->importantObjects[0xb] = 0x24;
    param_1->importantObjects[0xc] = 0x1c;
    param_1->importantObjects[0xd] = 0x12;
    param_1->importantObjects[0xe] = 0xd;
    param_1->importantObjects[0xf] = 0x1b;
    param_1->importantObjects[0x10] = 0x16;
    param_1->importantObjects[0x11] = 0x14;
    param_1->importantObjects[0x12] = 2;
    param_1->importantObjects[0x13] = 0x15;
    param_1->importantObjects[0x14] = 0x27;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005080dc
// Address: 005080dc
// XREFS: None
TribeTowerUnitAIModule * __thiscall FUN_005080dc(TribeTowerUnitAIModule *param_1,byte param_2)
{
  TribeTowerUnitAIModule::~TribeTowerUnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

